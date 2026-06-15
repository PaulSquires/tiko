# Aliases and typedefs

Some type libraries use aliases and typedefs to give alternate names to data types, enumerations or structures. For example, ADO uses ADO_LONGPTR as a typedef of a LongInteger and SearchDirection as an alias of SearchDirectionEnum.

```
' ----------------------------------------------------------------------------
' Aliases and typedefs
' ----------------------------------------------------------------------------
CASE TKIND_ALIAS
   dwsOrigName = "" : dwsAliasName = "" : dwsAliasName2 = "" : dwsTypedefName = ""
   DIM bstrName AS AFX_BSTR
   hr = m_pTypeLib->GetDocumentation(i, @bstrName, NULL, NULL, NULL)
   dwsName = *bstrName
   SysFreeString bstrName
   IF hr = S_OK THEN
      dwsOrigName = dwsName
      IF pTypeAttr->tdescAlias.vt = VT_USERDEFINED THEN
         ' // If it is a user defined type, retrieve its name
         hr = pTypeInfo->GetRefTypeInfo(pTypeAttr->tdescAlias.hreftype, @pRefTypeInfo)
         IF hr = S_OK AND pRefTypeInfo <> NULL THEN
            DIM bstrName AS AFX_BSTR
            hr = pRefTypeInfo->GetDocumentation(-1, @bstrName, NULL, NULL, NULL)
            dwsName = *bstrName
            SysFreeString bstrName
            IF hr = S_OK THEN
               dwsAliasName = dwsOrigName & " = " & dwsName
               dwsAliasName2 = dwsName & " = " & dwsOrigName
            END IF
            pRefTypeInfo->Release
            pRefTypeInfo = NULL
         END IF
      ELSEIF pTypeAttr->tdescAlias.vt = VT_PTR THEN
         ' // Pointer to a TYPEDESC structure
         DIM ptdesc AS TYPEDESC PTR = pTypeAttr->tdescAlias.lptdesc
         DO
            SELECT CASE ptdesc->vt
               ' // If it is a pointer, do it again
               CASE VT_PTR
                  ptdesc = ptdesc->lptdesc
               CASE VT_USERDEFINED
                  ' // Retrieve the name of the user defined type
                  hr = pTypeInfo->GetRefTypeInfo(ptdesc->hreftype, @pRefTypeInfo)
                  IF hr = S_OK AND pRefTypeInfo <> NULL THEN
                     DIM bstrName AS AFX_BSTR
                     hr = pRefTypeInfo->GetDocumentation(-1, @bstrName, NULL, NULL, NULL)
                     dwsName = *bstrName
                     SysFreeString bstrName
                     IF hr = S_OK THEN
                        dwsAliasName = dwsOrigName & " = " & dwsName
                        dwsAliasName2 = dwsName & " = " & dwsOrigName
                     END IF
                     pRefTypeInfo->Release
                     pRefTypeInfo = NULL
                  END IF
                  EXIT DO
               CASE ELSE
                  ' // Get the equivalent type
                  dwsTypedefName = dwsName & " = " & TLB_VarTypeToConstant(ptdesc->vt) & " <" & TLB_VarTypeToKeyword(pTypeAttr->tdescAlias.vt) & ">"
                  EXIT DO
            END SELECT
         LOOP
      ELSE
         ' // Get the equivalent type
         dwsTypedefName = dwsName & " = " & TLB_VarTypeToKeyword(pTypeAttr->tdescAlias.vt)  & " ' <" & TLB_VarTypeToConstant(pTypeAttr->tdescAlias.vt) & ">"
      END IF
      IF LEN(dwsTypedefName) THEN
         TreeView_AddItem hTreeView, m_hTypedefsNode, NULL, dwsTypedefName
      ELSE
         TreeView_AddItem hTreeView, m_hAliasesNode, NULL, dwsAliasName
      END IF
   END IF
```
