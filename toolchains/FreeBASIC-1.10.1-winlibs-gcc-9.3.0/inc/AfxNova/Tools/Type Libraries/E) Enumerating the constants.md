# Enumerating the constants

If the retrieved type info is of type `TKIND_ENUM` or `TKIND_MODULE`, the *cvars* member of the [TYPEATTR structure](https://msdn.microsoft.com/en-us/library/windows/desktop/ms221003(v=vs.85).aspx) contains the number of variables and the **GetVarDesc** method of the **ITypeInfo** interface retrieves a [VARDESC structure](https://msdn.microsoft.com/en-us/library/windows/desktop/ms221391(v=vs.85).aspx) that describes the specified variable.

```
' =====================================================================================
' Retrieves information about constants
' =====================================================================================
FUNCTION CParseTypeLib.GetConstants (BYVAL pTypeInfo AS Afx_ITypeInfo PTR, BYVAL pTypeAttr AS TYPEATTR PTR, BYVAL hTreeView AS HWND, BYVAL hSubNode AS HTREEITEM) AS HRESULT

   IF pTypeInfo = NULL OR pTypeAttr = NULL THEN RETURN E_INVALIDARG

   FOR x AS LONG = 0 TO pTypeAttr->cVars - 1
      DIM pVarDesc AS VARDESC PTR
      DIM hr AS HRESULT = pTypeInfo->GetVarDesc(x, @pVarDesc)
      IF hr <> S_OK OR pVarDesc = NULL THEN EXIT FOR
      DIM dwsName AS DWSTRING, bstrName AS AFX_BSTR
      pTypeInfo->GetDocumentation(pVarDesc->memid, @bstrName, NULL, NULL, NULL)
      dwsName = *bstrName
      SysFreeString bstrName
      ' // Some components use spaces in the names of enumeration members!
      IF INSTR(dwsName, " ") THEN
         dwsName = DWStrReplace(dwsName, " ", "_")
      END IF
      ' // Pointer to the variant that stores the value of the constant
      DIM vtPtr AS tagVARIANT PTR = pVarDesc->lpvarvalue
      ' // Gets the value of the constant
      DIM dwsValue AS DWSTRING = AfxVarToStr(vtPtr)
      DIM dwsTypeKind AS DWSTRING = TLB_VarTypeToConstant(pVarDesc->elemdescVar.tdesc.vt)
      SELECT CASE pVarDesc->elemdescVar.tdesc.vt
         CASE VT_I1, VT_UI1, VT_I2, VT_UI2, VT_I4, VT_UI4, VT_INT, VT_UINT
            dwsValue = dwsValue & "   ' (&h" & HEX(VAL(dwsValue), 8) & ")"
         CASE VT_BSTR, VT_LPSTR, VT_LPWSTR
            ' // cdosys.dll contains VT_BSTR constants
            dwsValue = CHR(34) & dwsValue & CHR(34)
         CASE VT_PTR
            DIM ptdesc AS TYPEDESC PTR = pVarDesc->elemdescVar.tdesc.lptdesc
            IF ptdesc THEN
               ' WORD PTR (null terminated unicode string)
               ' hxds.dll contains a module with these kind of constants.
               IF ptdesc->vt = VT_UI2 THEN dwsValue = CHR(34) & dwsValue & CHR(34)
            END IF
         ' // Other types can be VT_CARRAY and VT_USERDEFINED, but don't have a typelib to test
      END SELECT
      DIM hSubNode2 AS HTREEITEM = TreeView_AddItem(hTreeView, hSubNode, NULL, dwsName & " = " & dwsValue)
      TreeView_AddItem(hTreeView, hSubNode2, NULL, "TYPE = " & dwsTypeKind)
      TreeView_AddItem(hTreeView, hSubNode2, NULL, "VALUE = " & dwsValue)
      TreeView_AddItem(hTreeView, hSubNode2, NULL, "ID = " & WSTR(pVarDesc->memid))
      TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
      pTypeInfo->ReleaseVarDesc(pVarDesc) : pVarDesc = NULL
   NEXT

END FUNCTION
' =====================================================================================
```

Modules can also contain string constants and declarations of functions and procedures of external DLLs. This is covered by the following code in the **GetFunctions** method.

```
hr = pTypeInfo->GetDllEntry(pFuncDesc->memid, pFuncDesc->invkind, @bstrDllName, @bstrEntryPoint, @wOrdinal)
dwsDllName = *bstrDllName
SysFreeString bstrDllName
dwsEntryPoint = *bstrEntryPoint
SysFreeString bstrEntryPoint
IF hr = S_OK THEN
   IF LEN(dwsDllName) THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "DLL name = " & dwsDllName)
   IF LEN(dwsEntryPoint) THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Entry point = " & dwsEntryPoint)
  IF wOrdinal THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Ordinal = " & WSTR(wOrdinal))
END IF
```
