# Enumerating structures and unions

If the retrieved type info is of type `TKIND_RECORD` or `TKIND_UNION`, the *cvars* member of the `TYPEATTR` structure contains the number of members or data members and the **GetVarDesc** method of the **ITypeInfo** interface retrieves a `VARDESC` structure that describes the specified member or data member.

The parsing of this type info is more complexs
that in the case of the constants because they don't contain simple values, but the names and types of the members of an structure that can be simple data types, but also pointers, arrays or even other structures.

```
' =====================================================================================
' Retrieves information about the members of records and unions, and of datamembers.
' Note: Bined.dll fails to retrieve information of several members of the VSPROPSHEETPAGE structure.
' =====================================================================================
FUNCTION CParseTypeLib.GetMembers (BYVAL pTypeInfo AS Afx_ITypeInfo PTR, BYVAL pTypeAttr AS TYPEATTR PTR, BYVAL hTreeView AS HWND, BYVAL hSubNode AS HTREEITEM, BYVAL bIsRecord AS BOOLEAN = FALSE) AS HRESULT

   DIM wIndirectionLevel AS WORD           ' // Indirection level
   DIM pRefTypeInfo AS Afx_ITypeInfo PTR   ' // Referenced TypeInfo interface
   DIM pVarTypeAttr AS TYPEATTR PTR        ' // Type attribute for the member
   DIM hSubNode2 AS HTREEITEM              ' // Sub node handle
   DIM hSubNode3 AS HTREEITEM              ' // Sub node handle
   DIM dwsVarName AS DWSTRING              ' // Variable name
   DIM dwsVarType AS DWSTRING              ' // Variable type
   DIM dwsTypeKind AS DWSTRING             ' // Type kind
   DIM dwsFBKeyword AS DWSTRING            ' // FB keyword
   DIM dwsFBSyntax AS DWSTRING             ' // FB syntax

   IF pTypeInfo = NULL OR pTypeAttr = NULL THEN RETURN E_INVALIDARG

   FOR x AS LONG = 0 TO pTypeAttr->cVars - 1

      ' // Gets a reference to the VarDesc structure
      DIM pVarDesc AS VARDESC PTR
      DIM hr AS HRESULT = pTypeInfo->GetVarDesc(x, @pVarDesc)
      IF hr <> S_OK OR pVarDesc = NULL THEN EXIT FOR

      ' // Retrieve information
      DIM bstrVarName AS AFX_BSTR
      pTypeInfo->GetDocumentation(pVarDesc->memid, @bstrVarName, NULL, NULL, NULL)
      dwsVarName = *bstrVarName
      SysFreeString bstrVarName
      hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, dwsVarName)
      TreeView_AddItem(hTreeView, hSubNode2, NULL, "DispID = " & WSTR(pVarDesc->memid) & " [&h" & HEX(pVarDesc->memid, 8) & "]")
      IF pVarDesc->wVarFlags THEN TreeView_AddItem(hTreeView, hSubNode2, NULL, "Attributes = " & WSTR(pVarDesc->wVarFlags) & " [&h" & HEX(pVarDesc->wVarFlags, 8) & "]" & TLB_VarFlagsToStr(pVarDesc->wVarFlags))
      wIndirectionLevel = 0
      dwsTypeKind = ""
      IF pVarDesc->elemdescVar.tdesc.vt = VT_USERDEFINED THEN
         ' // If it is a user defined type, retrieve its name
         hr = pTypeInfo->GetRefTypeInfo(pVarDesc->elemdescVar.tdesc.hreftype, @pRefTypeInfo)
         IF hr = S_OK AND pRefTypeInfo <> NULL THEN
            DIM bstrVarType AS AFX_BSTR
            hr = pRefTypeInfo->GetDocumentation(-1, @bstrVarType, NULL, NULL, NULL)
            dwsVarType = *bstrVarType
            SysFreeString bstrVarType
            hr = pRefTypeInfo->GetTypeAttr(@pVarTypeAttr)
            IF hr = S_OK AND pVarTypeAttr <> NULL THEN
               IF pVarTypeAttr->typekind = TKIND_ALIAS THEN
                  dwsTypeKind = TLB_TypeKindToStr(pVarTypeAttr->typekind) & " | " & TLB_VarTypeToConstant(pVarTypeAttr->tdescalias.vt)
               ELSE
                  dwsTypeKind = TLB_TypeKindToStr(pVarTypeAttr->typekind)
               END IF
               TreeView_AddItem(hTreeView, hSubNode2, NULL, "TypeKind = " & dwsTypeKind)
               pRefTypeInfo->ReleaseTypeAttr(pVarTypeAttr)
               pVarTypeAttr = NULL
            END IF
            IF pRefTypeInfo THEN pRefTypeInfo->Release
         ELSE
            dwsVarType = "GetRefTypeInfo failed - Error: &h" & HEX(hr, 8)
         END IF
      ELSEIF pVarDesc->elemdescVar.tdesc.vt = VT_PTR THEN
         wIndirectionLevel = 1
         DIM ptdesc AS TYPEDESC PTR = pVarDesc->elemdescVar.tdesc.lptdesc
         DO
            SELECT CASE ptdesc->vt
               ' // If it is another pointer, loop again
               CASE VT_PTR
                  wIndirectionLevel += 1
                  ptdesc = ptdesc->lptdesc
               CASE VT_USERDEFINED
                  hr = pTypeInfo->GetRefTypeInfo(ptdesc->hreftype, @pRefTypeInfo)
                  IF hr = S_OK AND pRefTypeInfo <> NULL THEN
                     DIM bstrVarType AS AFX_BSTR
                     hr = pRefTypeInfo->GetDocumentation(-1, @bstrVarType, NULL, NULL, NULL)
                     dwsVarType = *bstrVarType
                     SysFreeString bstrVarType
                     IF hr = S_OK THEN
                        pRefTypeInfo->GetTypeAttr(@pVarTypeAttr)
                        IF hr = S_OK AND pVarTypeAttr <> NULL THEN
                           IF pVarTypeAttr->typekind = TKIND_ALIAS THEN
                              dwsTypeKind = TLB_TypeKindToStr(pVarTypeAttr->typekind) & " | " & TLB_VarTypeToConstant(pVarTypeAttr->tdescalias.vt)
                           ELSE
                              dwsTypeKind = TLB_TypeKindToStr(pVarTypeAttr->typekind)
                           END IF
                           TreeView_AddItem(hTreeView, hSubNode2, NULL, "TypeKind = " & dwsTypeKind)
                           pRefTypeInfo->ReleaseTypeAttr(pVarTypeAttr)
                           pVarTypeAttr = NULL
                        END IF
                     END IF
                     IF pRefTypeInfo THEN pRefTypeInfo->Release
                     EXIT DO
                  ELSE
                     dwsVarType = "GetRefTypeInfo failed - Error: &h" & HEX(hr, 8)
                  END IF
               CASE ELSE
                  ' // Get the equivalent type
                  dwsVarType = TLB_VarTypeToConstant(ptdesc->vt)
                  dwsFBKeyword = TLB_VarTypeToKeyword(ptdesc->vt)
                  EXIT DO
            END SELECT
         LOOP
      ELSE
         ' // Get the equivalent type
         dwsVarType = TLB_VarTypeToConstant(pVarDesc->elemdescVar.tdesc.vt)
         dwsFBKeyword = TLB_VarTypeToKeyword(pVarDesc->elemdescVar.tdesc.vt)
      END IF

      IF bIsRecord = FALSE THEN
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "VarType = " & dwsVarType)
      ELSE   ' // Records and unions only
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "Indirection level = " & WSTR(wIndirectionLevel))
'           ' // Add the "tag_" prefix to structures and unions
'            IF cbstrTypeKind = "TKIND_RECORD" OR cbstrTypeKind = "TKIND_UNION" THEN cbstrVarType = "tag" & cbstrVarType
         ' // END isn't allowed as a member name
         IF UCASE(dwsVarName) = "END" THEN dwsVarName += "_"
         ' // Use generic data types for enums and interfaces
         IF dwsFBKeyword = "" THEN dwsFBKeyword = dwsVarType
         ' // Add the "tag_" prefix to structures and unions
'         IF dwsTypeKind = "TKIND_RECORD" OR dwsTypeKind = "TKIND_UNION" THEN dwsFBKeyword = "tag_" & dwsFBKeyword
         IF wIndirectionLevel > 0 THEN dwsFBKeyword += " PTR"
'         IF dwsTypeKind = "TKIND_ALIAS | VT_PTR" THEN dwsFBKeyword = "VOID"
         IF dwsTypeKind = "TKIND_ALIAS | VT_PTR" THEN dwsFBKeyword = dwsVarType & " PTR"
         IF dwsTypeKind = "TKIND_ENUM" THEN dwsFBKeyword = dwsVarType
         IF dwsTypeKind = "TKIND_UNION" THEN dwsFBKeyword = dwsVarType
         IF dwsTypeKind = "TKIND_RECORD" THEN dwsFBKeyword = dwsVarType
         IF dwsTypeKind = "TKIND_RECORD" AND wIndirectionLevel = 1 THEN dwsFBKeyword += " PTR"
         IF dwsTypeKind = "TKIND_UNKNOWN" THEN dwsFBKeyword = "IUnknown PTR"
         IF dwsTypeKind = "TKIND_DISPATCH" THEN dwsFBKeyword = "IDispatch PTR"
         IF pVarDesc->elemdescVar.tdesc.vt = VT_CARRAY THEN
            DIM padesc AS ARRAYDESC PTR = pVarDesc->elemdescVar.tdesc.lpadesc
            dwsVarType += " | " & TLB_VarTypeToConstant(padesc->tdescElem.vt)
            dwsVarName += " ("
            FOR y AS LONG = 0 TO padesc->cDims - 1
               dwsVarName += WSTR(padesc->rgbounds(y).lLBound) & " TO "
               dwsVarName += WSTR(padesc->rgbounds(y).lLBound + padesc->rgbounds(y).cElements - 1)
               IF padesc->cDims > 1 THEN dwsVarName += ", "
            NEXT
            dwsVarName += ")"
            dwsFBKeyword = TLB_VarTypeToKeyword(padesc->tdescElem.vt)
         END IF
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "VarType = " & dwsVarType)
         IF pVarDesc->elemdescVar.tdesc.vt = VT_CARRAY THEN
            DIM padesc AS ARRAYDESC PTR = pVarDesc->elemdescVar.tdesc.lpadesc
            hSubNode3 = TreeView_AddItem(hTreeView, hSubNode2, NULL, "Dimensions = " & WSTR(padesc->cDims))
            FOR y AS LONG = 0 TO padesc->cDims - 1
               TreeView_AddItem(hTreeView, hSubNode3, NULL, "Dimension " & WSTR(y + 1) & " lower bound = " & WSTR(padesc->rgbounds(y).lLBound))
               TreeView_AddItem(hTreeView, hSubNode3, NULL, "Dimension " & WSTR(y + 1) & " elements = " & WSTR(padesc->rgbounds(y).cElements))
            NEXT
            TreeView_Expand(hTreeView, hSubNode3, TVE_EXPAND)
         END IF
'         ' // FB syntax
         SELECT CASE dwsVarType
            CASE "VT_LPSTR", "VT_CARRAY | VT_LPSTR"
               dwsFBSyntax = dwsVarName & " AS ZSTRING PTR"
            CASE "VT_LPWSTR", "VT_CARRAY | VT_LPWSTR"
               dwsFBSyntax = dwsVarName & " AS WSTRING PTR"
            CASE ELSE
               dwsFBSyntax = dwsVarName & " AS " & dwsFBKeyword
         END SELECT
         TreeView_AddItem(hTreeView, hSubNode2, NULL, "FB syntax = " & dwsFBSyntax)
      END IF

      ' // Expand the nodes
'         TreeView_Expand(hTreeView, hSubNode2, TVE_EXPAND)
      TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
      ' // Release the VARDESC structure
      pTypeInfo->ReleaseVarDesc(pVarDesc) : pVarDesc = NULL

   NEXT

   ' // Just to satisfy the compiler rules; it has no useful meaning
   FUNCTION = S_OK

END FUNCTION
' =====================================================================================
```
