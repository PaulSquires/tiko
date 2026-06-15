# Retrieving the methods and properties

The *cFuncs* member of the `TYPEATTR` structure contains the number of methods and properties implemented in an interface and the **GetFuncDesc** method of the **ITypeInfo** interface retrieves the [FUNCDESC](https://msdn.microsoft.com/en-us/library/windows/desktop/ms221425(v=vs.85).aspx) structure that contains information about a specified function, as well as the return type.

```
' =====================================================================================
' Retrieve information about the methods, properties and functions.
' =====================================================================================
FUNCTION CParseTypeLib.GetFunctions (BYVAL pTypeInfo AS Afx_ITypeInfo PTR, BYVAL pTypeAttr AS TYPEATTR PTR, _
   BYVAL hTreeView AS HWND, BYVAL hSubNode AS HTREEITEM, BYVAL bVTableView AS BOOLEAN, BYVAL bIsMethod AS BOOLEAN = FALSE, _
   BYVAL pTKind AS TYPEKIND = -1, BYVAL pwszImplInterface AS WSTRING PTR = NULL) AS HRESULT

   DIM hSubNode2 AS HTREEITEM              ' // Sub node handle
   DIM dwHelpContext AS DWORD              ' // Help context number
   DIM pRefTypeInfo AS Afx_ITypeInfo PTR   ' // Referenced TypeInfo interface
   DIM pReturnTypeAttr AS TYPEATTR PTR     ' // Referenced TYPEATTR structure
   DIM ReturnTypeKind AS TYPEKIND          ' // Return value type kind
   DIM dwsName AS DWSTRING                 ' // Name
   DIM dwsHelpString AS DWSTRING           ' // Help string
   DIM dwsDllName AS DWSTRING              ' // DLL name
   DIM dwsEntryPoint AS DWSTRING           ' // Entry point
   DIM dwsType AS DWSTRING                 ' // Type

   IF pTypeInfo = NULL OR pTypeAttr = NULL THEN RETURN E_INVALIDARG

   FOR x AS LONG = 0 TO pTypeAttr->cFuncs - 1
      ' // Gets a reference to the FuncDesc structure
      DIM pFuncDesc AS FUNCDESC PTR
      DIM hr AS HRESULT = pTypeInfo->GetFuncDesc(x, @pFuncDesc)
      IF hr <> S_OK OR pFuncDesc = NULL THEN EXIT FOR
      ' // Retrieve the name
      DIM AS AFX_BSTR bstrName, bstrHelpString
      pTypeInfo->GetDocumentation(pFuncDesc->memid, @bstrName, @bstrHelpString, @dwHelpContext, NULL)
      dwsName = *bstrName
      SysFreeString bstrName
      dwsHelpString = *bstrHelpString
      SysFreeString bstrHelpString
      IF bIsMethod THEN
         ' ------------------------------------------------------------------
         ' Workaround for libraries that can have illegal method names.
         ' For example, TLBINF32.DLL has a property called GetTypeInfo.
         ' ------------------------------------------------------------------
         DIM vtOffset AS LONG
#ifdef __FB_64BIT__
         vtOffset = 48
#else
         vtOffset = 24
#endif
         IF UCASE(dwsName) = "QUERYINTERFACE" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "ADDREF" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "RELEASE" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "GETTYPEINFOCOUNT" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "GETTYPEINFO" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "GETIDSOFNAMES" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "INVOKE" AND pFuncdesc->oVft > vtOffset THEN dwsName += "_"
         IF UCASE(dwsName) = "DELETE" THEN dwsName += "_"
         IF UCASE(dwsName) = "PROPERTY" THEN dwsName += "_"

         IF pTKind = TKIND_INTERFACE OR pTKind = TKIND_DISPATCH THEN
            IF pFuncDesc->invkind = INVOKE_FUNC THEN dwsName = "METHOD " & dwsName
            IF pFuncDesc->invkind = INVOKE_PROPERTYGET THEN dwsName = "PROPERTY GET " & dwsName
            IF pFuncDesc->invkind = INVOKE_PROPERTYPUT THEN dwsName = "PROPERTY PUT " & dwsName
            IF pFuncDesc->invkind = INVOKE_PROPERTYPUTREF THEN dwsName = "PROPERTY PUTREF " & dwsName
         END IF
         hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, dwsName)
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "VTable offset = " &  WSTR(pFuncdesc->oVft) & " [&h" & HEX(pFuncdesc->oVft, 8) & "]")
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "DispID = " & WSTR(pFuncDesc->memid) & " [&h" & HEX(pFuncDesc->memid, 8) & "]")
         IF LEN(dwsHelpString) THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Help string = " & dwsHelpString)
         IF dwHelpContext THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Help context = " & WSTR(dwHelpContext))
      ELSE
         IF pFuncDesc->elemdescFunc.tdesc.vt = VT_VOID THEN
            hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "SUB " & dwsName)
         ELSE
            hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "FUNCTION " & dwsName)
         END IF
         IF LEN(dwsHelpString) THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Help string = " & dwsHelpString)
         IF dwHelpContext THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Help context = " & WSTR(dwHelpContext))
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "DispID = " & WSTR(pFuncDesc->memid) & " [&h" & HEX(pFuncDesc->memid, 8) & "]")
         DIM wOrdinal AS WORD, bstrDllName AS AFX_BSTR, bstrEntryPoint AS AFX_BSTR
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
      END IF

      ' // Kind of function
      SELECT CASE pFuncDesc->funckind
         CASE FUNC_VIRTUAL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "FuncKind = Virtual")
         CASE FUNC_PUREVIRTUAL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "FuncKind = Pure virtual")
         CASE FUNC_NONVIRTUAL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "FuncKind = Non virtual")
         CASE FUNC_STATIC
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "FuncKind = Static")
         CASE FUNC_DISPATCH
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "FuncKind = Dispatch")
      END SELECT
      ' // Invoke kind
      SELECT CASE pFuncDesc->invkind
         CASE INVOKE_FUNC
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "InvokeKind = Function")
         CASE INVOKE_PROPERTYGET
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "InvokeKind = Get property")
         CASE INVOKE_PROPERTYPUT
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "InvokeKind = Put property")
         CASE INVOKE_PROPERTYPUTREF
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "InvokeKind = PutRef property")
      END SELECT
      ' // Calling convention
      SELECT CASE pFuncDesc->callconv
         CASE CC_FASTCALL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = FASTCALL")
         CASE CC_CDECL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = CDECL")
         CASE CC_MACPASCAL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = MACPASCAL")
         CASE CC_STDCALL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = STDCALL")
         CASE CC_FPFASTCALL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = FPFASTCALL")
         CASE CC_SYSCALL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = SYSCALL")
         CASE CC_MPWCDECL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = MPWCDECL")
         CASE CC_MPWPASCAL
            TreeView_AddItem(hTreeView, hSubNode2, NULL, "Calling convention = MPWPASCAL")
      END SELECT

      ' // More general information
      IF pFuncDesc->cParamsOpt THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Number of optional variant parameters = " & WSTR(pFuncDesc->cParamsOpt))
      IF pFuncDesc->cScodes THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Count of permitted return values = " & WSTR(pFuncDesc->cScodes))
      IF pFuncDesc->wFuncFlags THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Attributes = " & WSTR(pFuncDesc->wFuncFlags)& " [&h" & HEX(pFuncDesc->wFuncFlags, 8) & "]" & TLB_FuncFlagsToStr(pFuncDesc->wFuncFlags))
      ' // Return type
      ReturnTypeKind = -1  ' // Because the TYPEKIND enum starts at 0
      IF pFuncDesc->elemdescFunc.tdesc.vt = VT_USERDEFINED THEN
         ' // If it is a user defined type, retrieve its name
         hr = pTypeInfo->GetRefTypeInfo(pFuncDesc->elemdescFunc.tdesc.hreftype, @pRefTypeInfo)
         IF hr = S_OK AND pRefTypeInfo <> NULL THEN
            DIM bstrType AS AFX_BSTR
            hr = pRefTypeInfo->GetDocumentation(-1, @bstrType, NULL, NULL, NULL)
            dwsType = *bstrType
            SysFreeString bstrType
            hr = pRefTypeInfo->GetTypeAttr(@pReturnTypeAttr)
            IF hr = S_OK AND pReturnTypeAttr <> NULL THEN
               TreeView_AddItem(hTreeView, hSubNode2, NULL, "Return type typeKind = " & TLB_TypeKindToStr(pReturnTypeAttr->typekind))
               ReturnTypeKind = pReturnTypeAttr->typekind
               pRefTypeInfo->ReleaseTypeAttr(pReturnTypeAttr)
               pReturnTypeAttr = NULL
            END IF
            IF pRefTypeInfo THEN pRefTypeInfo->Release
         END IF
      ELSEIF pFuncDesc->elemdescFunc.tdesc.vt = VT_PTR THEN
         ' // Pointer to a TYPEDESC structure
         DIM ptdesc AS TYPEDESC PTR = pFuncDesc->elemdescFunc.tdesc.lptdesc
         DO
            SELECT CASE ptdesc->vt
               ' // If it is a pointer, do it again
               CASE VT_PTR
                  ptdesc = ptdesc->lptdesc
               CASE VT_USERDEFINED
                  ' // Retrieve the name of the user defined type
                  hr = pTypeInfo->GetRefTypeInfo(ptdesc->hreftype, @pRefTypeInfo)
                  IF hr = S_OK AND pRefTypeInfo <> NULL THEN
                     DIM bstrType AS AFX_BSTR
                     hr = pRefTypeInfo->GetDocumentation(-1, @bstrType, NULL, NULL, NULL)
                     dwsType = *bstrType
                     SysFreeString bstrType
                     hr = pRefTypeInfo->GetTypeAttr(@pReturnTypeAttr)
                     IF hr = S_OK AND pReturnTypeAttr <> NULL THEN
                        TreeView_AddItem(hTreeView, hSubNode2, NULL, "Return type typeKind = " & TLB_TypeKindToStr(pReturnTypeAttr->typekind))
                        ReturnTypeKind = pReturnTypeAttr->typekind
                        pRefTypeInfo->ReleaseTypeAttr(pReturnTypeAttr)
                        pReturnTypeAttr = NULL
                     END IF
                     IF pRefTypeInfo THEN pRefTypeInfo->Release
                  END IF
                  EXIT DO
               CASE ELSE
                  ' // Get the equivalent type
                  dwsType = TLB_VarTypeToConstant(ptdesc->vt)
                  EXIT DO
            END SELECT
         LOOP
      ELSE
         ' // Get the equivalent type
         dwsType = TLB_VarTypeToConstant(pFuncDesc->elemdescFunc.tdesc.vt)
      END IF
      ' // Return type
      TreeView_AddItem(hTreeView, hSubNode2, NULL, "Return type = " & dwsType)
      DIM strReturn AS STRING = ""
      IF bVTableView = FALSE THEN
         IF ReturnTypeKind = TKIND_INTERFACE OR ReturnTypeKind = TKIND_DISPATCH THEN
            strReturn = "BYVAL rhs AS " & dwsType & " PTR PTR"
         ELSEIF ReturnTypeKind = TKIND_ENUM THEN
            strReturn = "BYVAL rhs AS " & dwsType & " PTR"
         ELSEIF ReturnTypeKind = TKIND_ALIAS THEN
            strReturn = "BYVAL rhs AS " & dwsType & " PTR"
         ELSEIF pFuncDesc->elemdescFunc.tdesc.vt = VT_VOID THEN
            ' // With Automation view, VT_VOID means no return type
            strReturn = ""
         ELSEIF pFuncDesc->invkind <> INVOKE_PROPERTYGET AND pFuncDesc->cParams = 0 THEN
            ' // With Automation view, if it is not a get property and it has not
            ' // parameters, then it has not an OUT return value but returns the value
            ' //  directly as the result of the method, e.g. AddRef and Release.
            strReturn = ""
         ELSE
            ' // Returns the value as an OUT parameter
            strReturn = "BYVAL rhs AS " & TLB_VarTypeToKeyword(pFuncDesc->elemdescFunc.tdesc.vt) & " PTR"
         END IF
         IF LEN(strReturn) THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Return type FB syntax = " & strReturn)
      END IF
      ' // Parameters
      IF pFuncDesc->cParams THEN this.GetParameters(pTypeInfo, pFuncDesc, hTreeView, hSubNode2, bVTableView)
      ' // Expand the nodes
'      TreeView_Expand(hTreeView, hSubNode2, TVE_EXPAND)
      TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
      ' // Release the FUNCDESC structure
      pTypeInfo->ReleaseFuncDesc(pFuncDesc) : pFuncDesc = NULL
      ReturnTypeKind = -1
   NEXT

   ' // Just to satisfy the compiler rules; it has no useful meaning
   FUNCTION = S_OK

END FUNCTION
' =====================================================================================
```
