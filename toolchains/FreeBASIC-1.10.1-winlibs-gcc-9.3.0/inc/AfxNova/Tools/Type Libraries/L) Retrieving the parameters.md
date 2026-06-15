# Retrieving the parameters

One of the members of the [FUNDESC](https://learn.microsoft.com/en-us/windows/win32/api/oaidl/ns-oaidl-funcdesc) structure, *cParams*, contains the number of parameters of each function or method. Parameters can be of any kind of data type and be passed by value or by reference.

```
' =====================================================================================
' Retrieve information about the parameters
' =====================================================================================
FUNCTION CParseTypeLib.GetParameters (BYVAL pTypeInfo AS Afx_ITypeInfo PTR, BYVAL pFuncDesc AS FUNCDESC PTR, _
   BYVAL hTreeView AS HWND, BYVAL hSubNode2 AS HTREEITEM, BYVAL bVTableView AS BOOLEAN) AS HRESULT

   DIM hParamsNode AS HTREEITEM            ' // Parameters node
   DIM hParamNameNode AS HTREEITEM         ' // Parameter name node
   DIM pParamTypeAttr AS TYPEATTR PTR      ' // Referenced TYPEATTR structure
   DIM pReturnTypeAttr AS TYPEATTR PTR     ' // Referenced TYPEATTR structure
   DIM wIndirectionLevel AS WORD           ' // Indirection level
   DIM pRefTypeInfo AS Afx_ITypeInfo PTR   ' // Referenced TypeInfo interface
   DIM dwsParamName AS DWSTRING            ' // Parameter name
   DIM dwsVarType AS DWSTRING              ' // Variable type
   DIM dwsTypeKind AS DWSTRING             ' // Type kind
   DIM dwsFBKeyword AS DWSTRING            ' // FB keyword
   DIM dwsFBSyntax AS DWSTRING             ' // FB syntax

   hParamsNode = TreeView_AddItem(hTreeView, hSubNode2, NULL, "Number of parameters = " & WSTR(pFuncDesc->cParams))
   ' ----------------------------------------------------------------------------------
   ' Gets the name of all the parameters.
   ' The first one is the name of the function.
   ' If the member ID identifies a property that is implemented with property functions,
   ' the property name is returned. For property get functions, the names of the function
   ' and its parameters are always returned.
   ' For property put and put reference functions, the right side of the assignment is
   ' unnamed. If cMaxNames is less than is required to return all of the names of the
   ' parameters of a function, then only the names of the first cMaxNames-1 parameters
   ' are returned. The names of the parameters are returned in the array in the same
   ' order that they appear elsewhere in the interface (for example, the same order in
   ' the parameter array associated with the FUNCDESC enumeration).
   ' ----------------------------------------------------------------------------------
   REDIM rgbstrNames(pFuncDesc->cParams) AS AFX_BSTR
   DIM cNames AS DWORD   ' // Number of names
   DIM hr AS HRESULT = pTypeInfo->GetNames(pFuncDesc->memid, @rgbstrNames(0), pFuncDesc->cParams + 1, @cNames)
   IF hr = S_OK THEN
      ' // Pointer to an ELEMDESC structure
      DIM pParam AS ELEMDESC PTR = pFuncDesc->lprgelemdescParam
      ' // Retrieves information about the parameters
      FOR y AS LONG = 0 TO pFuncDesc->cParams - 1
         dwsVarType = "" : dwsTypeKind = "" : dwsFBKeyword = ""
         ' // Attributes
         DIM wFlags AS WORD = pParam[y].paramdesc.wParamFlags
         ' // When using the automation view, it does not return a name for the return type
         dwsParamName = rgbstrNames(y + 1)
         IF LEN(dwsParamName) = 0 THEN
            IF y = pFuncDesc->cParams - 1 THEN
               dwsParamName = "rhs"
            ELSE
               dwsParamName = "prm" & WSTR(y + 1)
            END IF
         END IF
         hParamNameNode = TreeView_AddItem(hTreeView, hParamsNode, NULL, dwsParamName)
         TreeView_AddItem(hTreeView, hParamNameNode, NULL, "Attributes = " & WSTR(wFlags) & " [&h" & HEX(wFlags, 8) & "] " & TLB_ParamflagsToStr(wFlags))
         wIndirectionLevel = 0
         IF pParam[y].tdesc.vt = VT_USERDEFINED THEN
            ' // If it is a user defined type, retrieve its name
            hr = pTypeInfo->GetRefTypeInfo(pParam[y].tdesc.hreftype, @pRefTypeInfo)
            IF hr = S_OK AND pRefTypeInfo <> NULL THEN
               DIM bstrVarType AS AFX_BSTR
               hr = pRefTypeInfo->GetDocumentation(-1, @bstrVarType, NULL, NULL, NULL)
               dwsVarType = *bstrVarType
               SysFreeString bstrVarType
               hr = pRefTypeInfo->GetTypeAttr(@pParamTypeAttr)
               IF hr = S_OK AND pParamTypeAttr <> NULL THEN
                  IF pParamTypeAttr->typekind = TKIND_ALIAS THEN
                     dwsTypeKind = TLB_TypeKindToStr(pParamTypeAttr->typekind) & " | " & TLB_VarTypeToConstant(pParamTypeAttr->tdescalias.vt)
                  ELSE
                     dwsTypeKind = TLB_TypeKindToStr(pParamTypeAttr->typekind)
                  END IF
                  TreeView_AddItem(hTreeView, hParamNameNode, NULL, "TypeKind = " & dwsTypeKind)
                  pRefTypeInfo->ReleaseTypeAttr(pParamTypeAttr)
                  pParamTypeAttr = NULL
               END IF
               IF pRefTypeInfo THEN pRefTypeInfo->Release
            END IF
         ELSEIF pParam[y].tdesc.vt = VT_PTR THEN
            ' // Pointer to a TYPEDESC structure
            DIM ptdesc AS TYPEDESC PTR = pParam[y].tdesc.lptdesc
            wIndirectionLevel = 1
            DO
               SELECT CASE ptdesc->vt
                  ' // If it is a pointer, do it again
                  CASE VT_PTR
                     wIndirectionLevel += 1
                     ptdesc = ptdesc->lptdesc
                  CASE VT_USERDEFINED
                     ' // Retrieve the name of the user defined type
                     hr = pTypeInfo->GetRefTypeInfo(ptdesc->hreftype, @pRefTypeInfo)
                     IF hr = S_OK AND pRefTypeInfo <> NULL THEN
                        DIM bstrVarType AS AFX_BSTR
                        hr = pRefTypeInfo->GetDocumentation(-1, @bstrVarType, NULL, NULL, NULL)
                        dwsVarType = *bstrVarType
                        SysFreeString bstrVarType
                        hr = pRefTypeInfo->GetTypeAttr(@pParamTypeAttr)
                        IF hr = S_OK AND pParamTypeAttr <> NULL THEN
                           IF pParamTypeAttr->typekind = TKIND_ALIAS THEN
                              dwsTypeKind = TLB_TypeKindToStr(pParamTypeAttr->typekind) & " | " & TLB_VarTypeToConstant(pParamTypeAttr->tdescalias.vt)
                           ELSE
                              dwsTypeKind = TLB_TypeKindToStr(pParamTypeAttr->typekind)
                           END IF
                           TreeView_AddItem(hTreeView, hParamNameNode, NULL, "TypeKind = " & dwsTypeKind)
                           pRefTypeInfo->ReleaseTypeAttr(pParamTypeAttr)
                           pParamTypeAttr = NULL
                        END IF
                        IF pRefTypeInfo THEN pRefTypeInfo->Release
                     END IF
                     EXIT DO
                  CASE ELSE
                     ' // Get the equivalent type
                     dwsVarType = TLB_VarTypeToConstant(ptdesc->vt)
                     dwsFBKeyword = TLB_VarTypeToKeyword(ptdesc->vt)
                     EXIT DO
               END SELECT
            LOOP
         ELSE
            ' // Get the equivalent type
            dwsVarType = TLB_VarTypeToConstant(pParam[y].tdesc.vt)
            dwsFBKeyword = TLB_VarTypeToKeyword(pParam[y].tdesc.vt)
            ' // Increment indirection level to pointers
            IF dwsTypeKind = "TKIND_INTERFACE" OR dwsTypeKind = "TKIND_DISPATCH" OR dwsTypeKind = "TKIND_COCLASS" THEN wIndirectionLevel += 1
            IF dwsVarType = "VT_SAFEARRAY" THEN wIndirectionLevel += 1
         END IF
         TreeView_AddItem(hTreeView, hParamNameNode, NULL, "Indirection level = " & WSTR(wIndirectionLevel))
         TreeView_AddItem(hTreeView, hParamNameNode, NULL, "VarType = " & dwsVarType)
         ' // Add a prefix to structures that begin with an underscore
'         IF LEFT$(dwsVarType, 1) = "_" THEN
'            IF dwsTypeKind = "TKIND_RECORD" OR dwsTypeKind = "TKIND_UNION" THEN dwsVarType = "tag" & dwsVarType
'         END IF
         ' // TODO: IF m_vTableView = TRUE then use BSTRING and DVARIANT
         SELECT CASE dwsTypeKind
            CASE "TKIND_INTERFACE", "TKIND_DISPATCH", "TKIND_COCLASS"
               IF wIndirectionLevel = 2 THEN
                  dwsFBSyntax = "BYVAL " & dwsParamName & " AS " & dwsVarType & " PTR PTR"
               ELSE
                  dwsFBSyntax = "BYVAL " & dwsParamName & " AS " & dwsVarType & " PTR"
               END IF
            CASE "TKIND_RECORD", "TKIND_UNION", "TKIND_ENUM"
               IF wIndirectionLevel = 2 THEN
                  dwsFBSyntax = "BYVAL " & dwsParamName & " AS " & dwsVarType & " PTR PTR"
               ELSEIF wIndirectionLevel = 1 THEN
                  dwsFBSyntax = "BYVAL " & dwsParamName &  " AS " & dwsVarType & " PTR"
               ELSE
                  dwsFBSyntax = "BYVAL " & dwsParamName & " AS " & dwsVarType
               END IF
            CASE ELSE
               IF LEFT(dwsTypeKind, 11) = "TKIND_ALIAS" THEN
                  IF wIndirectionLevel = 2 THEN
                     dwsFBSyntax = "BYVAL " & dwsParamName & " AS " & dwsVarType & " PTR PTR"
                  ELSEIF wIndirectionLevel = 1 THEN
                     dwsFBSyntax = "BYVAL " & dwsParamName &  " AS " & dwsVarType & " PTR"
                  ELSE
                     dwsFBSyntax = "BYVAL " & dwsParamName & " AS " & dwsVarType
                  END IF
               ELSE
                  SELECT CASE dwsVarType
                     CASE "VT_UNKNOWN"
                        IF wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS IUnknown PTR PTR"
                        ELSEIF wIndirectionLevel = 1 THEN
                           IF ((wFlags AND PARAMFLAG_FOUT) = PARAMFLAG_FOUT) OR ((wFlags AND PARAMFLAG_FRETVAL) = PARAMFLAG_FRETVAL) THEN
                              dwsFBSyntax = "BYVAL " & dwsParamName & " AS IUnknown PTR PTR"
                           ELSE
                              dwsFBSyntax = "BYVAL " & dwsParamName & " AS IUnknown PTR"
                           END IF
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS IUnknown PTR"
                        END IF
                     CASE "VT_DISPATCH"
                        IF wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS IDispatch PTR PTR"
                        ELSEIF wIndirectionLevel = 1 THEN
                           IF ((wFlags AND PARAMFLAG_FOUT) = PARAMFLAG_FOUT) OR ((wFlags AND PARAMFLAG_FRETVAL) = PARAMFLAG_FRETVAL) THEN
                              dwsFBSyntax = "BYVAL " & dwsParamName & " AS IDispatch PTR PTR"
                           ELSE
                              dwsFBSyntax = "BYVAL " & dwsParamName & " AS IDispatch PTR"
                           END IF
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS IDispatch PTR"
                        END IF
                     CASE "VT_VOID"
                        IF wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS ANY PTR PTR"
                        ELSEIF wIndirectionLevel = 1 THEN
                           IF ((wFlags AND PARAMFLAG_FOUT) = PARAMFLAG_FOUT) OR ((wFlags AND PARAMFLAG_FRETVAL) = PARAMFLAG_FRETVAL) THEN
                              dwsFBSyntax = "BYVAL " & dwsParamName & " AS ANY PTR PTR"
                           ELSE
                              dwsFBSyntax = "BYVAL " & dwsParamName & " AS ANY PTR"
                           END IF
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS ANY PTR"
                        END IF
                     CASE "VT_LPSTR"
                        IF wIndirectionLevel = 1 OR wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS ZSTRING PTR PTR"
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS ZSTRING PTR"
                        END IF
                     CASE "VT_LPWSTR"
                        IF wIndirectionLevel = 1 OR wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS WSTRING PTR PTR"
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS WSTRING PTR"
                        END IF
                     CASE "VT_BSTR"
                        IF wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS BSTR PTR PTR"
                        ELSEIF wIndirectionLevel = 1 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS BSTR PTR"
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName & " AS BSTR"
                        END IF
                     CASE ELSE
                        IF wIndirectionLevel = 2 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName &  " AS " & dwsFBKeyword & " PTR PTR"
                        ELSEIF wIndirectionLevel = 1 THEN
                           dwsFBSyntax = "BYVAL " & dwsParamName &  " AS " & dwsFBKeyword & " PTR"
                        ELSE
                           dwsFBSyntax = "BYVAL " & dwsParamName &  " AS " & dwsFBKeyword
                        END IF
                  END SELECT
               END IF
         END SELECT
         ' // See of it is an optional parameter without a default value
         IF (pParam[y].paramdesc.wParamFlags AND PARAMFLAG_FOPT) = PARAMFLAG_FOPT AND _
            (pParam[y].paramdesc.wParamFlags AND PARAMFLAG_FHASDEFAULT) <> PARAMFLAG_FHASDEFAULT THEN
            IF RIGHT(dwsFBSyntax, 4) = " PTR" THEN dwsFBSyntax += " = NULL"
            IF RIGHT(dwsFBSyntax, 11) = " AS VARIANT" THEN dwsFBSyntax += " = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)"
         END IF
         ' // See if it has a default value
         IF (pParam[y].paramdesc.wParamFlags AND PARAMFLAG_FHASDEFAULT) = PARAMFLAG_FHASDEFAULT THEN
            DIM pex AS PARAMDESCEX PTR = pParam[y].paramdesc.pparamdescex
            DIM dwsDefaultValue AS DWSTRING = AfxVarToStr(@pex->vardefaultvalue)
            IF pex->vardefaultvalue.vt = VT_BSTR THEN
               TreeView_AddItem(hTreeView, hParamNameNode, NULL, "Default value = " & CHR(34) & dwsDefaultValue & CHR(34))
'               dwsFBSyntax += " = " & CHR(34) & dwsDefaultValue & CHR(34)
            ELSE
               TreeView_AddItem(hTreeView, hParamNameNode, NULL, "Default value = " & dwsDefaultValue)
               ' // Some typelibs have unprintable default values, e.g. wbemdisp.tlb,
               ' // that has unprintable IDispatch PTR values.
               IF LEN(dwsDefaultValue) THEN dwsFBSyntax += " = " & dwsDefaultValue
            END IF
         END IF
         TreeView_AddItem(hTreeView, hParamNameNode, NULL, "FB syntax = " & dwsFBSyntax)
         TreeView_Expand(hTreeView, hParamNameNode, TVE_EXPAND)
      NEXT
   END IF

   ' // Exand the parameters node
'   TreeView_Expand(hTreeView, hParamsNode, TVE_EXPAND)

   ' // DO NOT free the BSTRs; they are owned by the callee
   ' // Free the BSTRs of the array
'   FOR i AS LONG = LBOUND(rgbstrNames) TO UBOUND(rgbstrNames)
'      IF rgbstrNames(i) THEN SysFreeString(rgbstrNames(i))
'   NEXT

   ' // Just to satisfy the compiler rules; it has no useful meaning
   RETURN S_OK

END FUNCTION
' =====================================================================================
```
