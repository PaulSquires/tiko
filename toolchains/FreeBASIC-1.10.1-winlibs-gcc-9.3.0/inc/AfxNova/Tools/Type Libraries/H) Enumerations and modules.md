# Enumerations and modules

```
' ----------------------------------------------------------------------------
' Enumerations and modules
' ----------------------------------------------------------------------------
CASE TKIND_ENUM, TKIND_MODULE
   DIM AS AFX_BSTR bstrName, bstrHelpString, bstrHelpFile
   hr = m_pTypeLib->GetDocumentation(i, @bstrName, @bstrHelpString, @dwHelpContext, @bstrHelpFile)
   dwsName = *bstrName : SysFreeString bstrName
   dwsHelpString = bstrHelpString : SysFreeString bstrHelpString
   dwsHelpFile = *bstrHelpFile : SysFreeString bstrHelpFile
   IF hr = S_OK THEN
      IF pTKind = TKIND_ENUM THEN
         hNode = TreeView_AddItem(hTreeView, m_hEnumsNode, NULL, dwsName)
      ELSE
         hNode = TreeView_AddItem(hTreeView, m_hModulesNode, NULL, dwsName)
      END IF
      IF AfxGuidText(pTypeAttr->guid) <> "{00000000-0000-0000-0000-000000000000}" THEN TreeView_AddItem(hTreeView, hNode, NULL, "IID: " & AfxGuidText(pTypeAttr->guid))
      IF LEN(dwsHelpString) THEN TreeView_AddItem(hTreeView, hNode, NULL, "Documentation string: " & dwsHelpString)
      ' /*** Constants ***/
      IF pTypeAttr->cVars THEN
         hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Number of constants: " & WSTR(pTypeAttr->cVars))
         this.GetConstants(pTypeInfo, pTypeAttr, hTreeView, hSubNode)
      END IF
      ' /*** Functions ***/
      IF pTypeAttr->cFuncs THEN
         hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Number of functions " & WSTR(pTypeAttr->cFuncs))
         this.GetFunctions(pTypeInfo, pTypeAttr, hTreeView, hSubNode, FALSE)
      END IF
   END IF
```
