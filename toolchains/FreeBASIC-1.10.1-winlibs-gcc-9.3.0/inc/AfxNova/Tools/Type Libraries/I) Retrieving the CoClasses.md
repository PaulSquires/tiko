# CoClasses

`CoClasses` provide information about each COM class, such the **ProgID** (Program Identifier), **CLSID** (Class Identifier), attributes, the in-process server and the implemented interfaces.

```
         ' ----------------------------------------------------------------------------
         ' CoClasses
         ' ----------------------------------------------------------------------------
         CASE TKIND_COCLASS
            ' // Get the name of the CoClass
            DIM AS AFX_BSTR bstrName, bstrHelpString, bstrHelpFile
            hr = m_pTypeLib->GetDocumentation(i, @bstrName, @bstrHelpString, @dwHelpContext, @bstrHelpFile)
            dwsName = *bstrName : SysFreeString bstrName
            dwsHelpString = *bstrHelpString : SysFreeString bstrHelpString
            dwsHelpFile = *bstrHelpFile : SysFreeString bstrHelpFile
            hNode = TreeView_AddItem(hTreeView, m_hCoClassesNode, NULL, dwsName)
            ' // ProgIDs node
            ' Some external programs, such McAffee Antivirus, modify the typelibs of
            ' components such Windows Script Host to redirect it to its own server.
            ' This originates duplicate ProgIDs, so we need to search if the ProgID
            ' is already listed to avoid duplicates.
            dwsProgID = TLB_GetProgID(AfxGuidText(pTypeAttr->guid))
            IF LEN(dwsProgID) THEN
               IF TreeView_ItemExists(hTreeView, m_hProgIDsNode, dwsProgID) = FALSE THEN
                  TreeView_AddItem hTreeView, m_hProgIDsNode, NULL, dwsProgID
                  hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "ProgID")
                  TreeView_AddItem hTreeView, hSubNode, NULL, dwsProgID
                  TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
               END IF
            END IF
            ' // Version independent ProgIDs node
            ' Note: Search if it already exists because there are components like
            ' MSXML that allow side-by-side installation of several versions that have
            ' different ProgIDs but, of course, the same independent version ProgID.
            dwsProgID = TLB_GetVersionIndependentProgID(AfxGuidText(pTypeAttr->guid))
            IF LEN(dwsProgID) THEN
               IF TreeView_ItemExists(hTreeView, m_hVerIndProgIDsNode, dwsProgID) = FALSE THEN
                  TreeView_AddItem hTreeView, m_hVerIndProgIDsNode, NULL, dwsProgID
                  hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Version independent ProgID")
                  TreeView_AddItem hTreeView, hSubNode, NULL, dwsProgID
                  TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
               END IF
            END IF
            ' // ClsIDs nodes
            TreeView_AddItem hTreeView, m_hClsIDsNode, NULL, "CLSID_" & dwsName & " = " & CHR(34) & AfxGuidText(pTypeAttr->guid) & CHR(34)
            hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "CLSID")
            TreeView_AddItem hTreeView, hSubNode, NULL, AfxGuidText(pTypeAttr->guid)
            TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
            ' // Attributes
            hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Attributes")
            TreeView_AddItem hTreeView, hSubNode, NULL, WSTR(pTypeAttr->wTypeFlags) & " [&h" & HEX(pTypeAttr->wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(pTypeAttr->wTypeFlags)
            TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
            ' // Help info
            IF LEN(dwsHelpString) THEN
               hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Help string")
               TreeView_AddItem hTreeView, hSubNode, NULL, dwsHelpString
               TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
            END IF
            IF dwHelpContext THEN
               hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Help context")
               TreeView_AddItem hTreeView, hSubNode, NULL, WSTR(dwHelpContext) & " [&h" & HEX(dwHelpContext, 8) & "]"
               TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
            END IF
            IF LEN(dwsHelpFile) THEN
               hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Help file")
               TreeView_AddItem hTreeView, hSubNode, NULL, dwsHelpFile
               TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
            END IF
            ' // InProcServer32
            dwsInProcServer = TLB_GetInprocServer32(AfxGuidText(pTypeAttr->guid))
            IF LEN(dwsInProcServer) THEN
               hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "InProcServer32")
               IF INSTR(dwsInProcServer, "%") THEN
                  DIM wszSrc AS WSTRING * MAX_PATH, wszDest AS WSTRING * MAX_PATH, cbLen AS DWORD
                  wszSrc = dwsInProcServer
                  cbLen = ExpandEnvironmentStringsW(@wszSrc, @wszDest, MAX_PATH)
                  IF cbLen THEN dwsInProcServer = wszDest
               END IF
               TreeView_AddItem hTreeView, hSubNode, NULL, dwsInProcServer
               TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
            END IF
            ' // Retrieve the implemented interfaces
            ' Note: Don't release pRefType or it will explode
            cImplTypes = pTypeAttr->cImplTypes
            IF cImplTypes THEN hImplIntSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Implemented interfaces")
            FOR x AS LONG = 0 TO cImplTypes - 1
               lImplTypeFlags = 0
               hr = pTypeInfo->GetImplTypeFlags(x, @lImplTypeFlags)
               IF hr <> S_OK THEN EXIT FOR
               pRefType = 0
               hr = pTypeInfo->GetRefTypeOfImplType(x, @pRefType)
               IF hr <> S_OK THEN EXIT FOR
               hr = pTypeInfo->GetRefTypeInfo(pRefType, @pImplTypeInfo)
               IF hr <> S_OK OR pImplTypeInfo = NULL THEN EXIT FOR
               DIM bstrName AS AFX_BSTR
               hr = pImplTypeInfo->GetDocumentation(-1, @bstrName, NULL, NULL, NULL)
               dwsName = *bstrName
               SysFreeString bstrName
               IF hr <> S_OK THEN EXIT FOR
               TreeView_AddItem hTreeView, hImplIntSubNode, NULL, dwsName
               TreeView_Expand(hTreeView, hImplIntSubNode, TVE_EXPAND)
               pImplTypeAttr = 0
               pImplTypeInfo->GetTypeAttr(@pImplTypeAttr)
               IF lImplTypeFlags = IMPLTYPEFLAG_FDEFAULT THEN   ' // Default interface
                  hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Default interface")
                  TreeView_AddItem hTreeView, hSubNode, NULL, dwsName
                  TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
                  hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Default interface IID")
                  IF pImplTypeAttr THEN TreeView_AddItem hTreeView, hSubNode, NULL, AfxGuidText(pImplTypeAttr->guid)
                  TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
               ELSEIF lImplTypeFlags = IMPLTYPEFLAG_FSOURCE THEN   ' // Events interface
                  ' // Some components, such Office 12's AccWiz.dll, have deprecated CoClasses that
                  ' // implement the same events interfaces that the new one. We need to check if the
                  ' // interface is hidden to avoid listing them twice.
'                  IF (pTypeAttr->wTypeFlags AND TYPEFLAG_FHIDDEN) <> TYPEFLAG_FHIDDEN THEN
'                     IF TreeView_ItemExists(hTreeView, m_hEventsNode, dwsName) = FALSE THEN
'                        TreeView_AddItem hTreeView, m_hEventsNode, NULL, dwsName
'                     END IF
'                  END IF
               ELSEIF lImplTypeFlags = (IMPLTYPEFLAG_FDEFAULT OR IMPLTYPEFLAG_FSOURCE) THEN   ' // Default events interface
                  hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Default events interface")
                  TreeView_AddItem hTreeView, hSubNode, NULL, dwsName
                  TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
                  hSubNode = TreeView_AddItem(hTreeView, hNode, NULL, "Default events interface IID")
                  IF pImplTypeAttr THEN TreeView_AddItem hTreeView, hSubNode, NULL, AfxGuidText(pImplTypeAttr->guid)
                  TreeView_Expand(hTreeView, hSubNode, TVE_EXPAND)
                  ' // Some components, such Office 12's AccWiz.dll, have deprecated CoClasses that
                  ' // implement the same events interfaces that the new one. We need to check if the
                  ' // interface is hidden to avoid listing them twice.
'                  IF (pTypeAttr->wTypeFlags AND TYPEFLAG_FHIDDEN) <> TYPEFLAG_FHIDDEN THEN
'                     IF TreeView_ItemExists(hTreeView, m_hEventsNode, dwsName) = FALSE THEN
'                        TreeView_AddItem hTreeView, m_hEventsNode, NULL, dwsName
'                     END IF
'                  END IF
               END IF
               IF pImplTypeAttr THEN
                  IF pImplTypeInfo THEN pImplTypeInfo->ReleaseTypeAttr(pImplTypeAttr)
                  pImplTypeAttr = NULL
               END IF
            NEXT
            IF pImplTypeAttr THEN
               IF pImplTypeInfo THEN pImplTypeInfo->ReleaseTypeAttr(pImplTypeAttr)
               pImplTypeAttr = NULL
            END IF
            IF pImplTypeInfo THEN
               pImplTypeInfo->Release
               pImplTypeInfo = NULL
            END IF
```

