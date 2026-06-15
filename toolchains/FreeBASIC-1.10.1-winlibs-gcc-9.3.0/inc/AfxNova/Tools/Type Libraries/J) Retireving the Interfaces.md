# Interfaces

The type infos `TKIND_INTERFACE` and `TKIND_DISPATCH` provide information about the implemented interfaces and its methods and properties.

```
         ' ----------------------------------------------------------------------------
         ' Interfaces
         ' ----------------------------------------------------------------------------
         CASE TKIND_INTERFACE, TKIND_DISPATCH
            DIM AS AFX_BSTR bstrName, bstrHelpString
            hr = m_pTypeLib->GetDocumentation(i, @bstrName, @bstrHelpString, NULL, NULL)
            dwsName = *bstrName
            SysFreeString bstrName
            dwsHelpString = *bstrHelpString
            SysFreeString bstrHelpString
            IF hr = S_OK THEN
               TreeView_AddItem hTreeView, m_hIIDsNode, NULL, "IID_" & dwsName & " = " & CHR(34) & AfxGuidText(pTypeAttr->guid) & CHR(34)
               ' ------------------------------------------------------------------------------------------
               ' If it is a dual interface and the VTable option has been set, try to change the view.
               ' ------------------------------------------------------------------------------------------
               DIM VTableView AS BOOLEAN = m_VTableView
               IF pTKind = TKIND_DISPATCH AND (pTypeAttr->wTypeFlags AND TYPEFLAG_FDUAL) = TYPEFLAG_FDUAL THEN
                  IF VTableView = TRUE THEN
                     DO   ' // Fake DO LOOP to allow exit without GOTO
                        ' // Attempt to change the view to VTable
                        pRefType = NULL
                        hr = pTypeInfo->GetRefTypeOfImplType(-1, @pRefType)
                        IF hr <> S_OK OR pRefType = NULL THEN
                           VTableView = FALSE
                           EXIT DO
                        END IF
                        hr = pTypeInfo->GetRefTypeInfo(pRefType, @pRefTypeInfo)
                        IF hr <> S_OK OR pRefTypeInfo = NULL THEN
                           VTableView = FALSE
                           EXIT DO
                        END IF
                        pRefTypeAttr = NULL
                        hr = pRefTypeInfo->GetTypeAttr(@pRefTypeAttr)
                        hSubNode = TreeView_AddItem(hTreeView, m_hDualIntNode, NULL, dwsName)
                        IF AfxGuidText(pRefTypeAttr->guid) <> "{00000000-0000-0000-0000-000000000000}" THEN
                           TreeView_AddItem(hTreeView, hSubNode, NULL, "IID: " & AfxGuidText(pRefTypeAttr->guid))
                        END IF
                        IF LEN(dwsHelpString) THEN TreeView_AddItem(hTreeView, hSubNode, NULL, "Documentation string: " & dwsHelpString)
                        IF pRefTypeAttr->wTypeFlags THEN TreeView_AddItem(hTreeView, hSubNode, NULL, "Attributes =  " & WSTR(pRefTypeAttr->wTypeFlags) & " [&h" & HEX(pRefTypeAttr->wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(pRefTypeAttr->wTypeFlags))
                        dwsInheritedInterface = TLB_GetImplementedInterface(pRefTypeInfo)
                        IF LEN(dwsInheritedInterface) THEN TreeView_AddItem(hTreeView, hSubNode, NULL, "Inherited interface = " & dwsInheritedInterface)
                        ' /*** Datamembers ***/
                        IF pRefTypeAttr->cVars THEN
                           hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "Number of datamembers = " & WSTR(pRefTypeAttr->cVars))
                           this.GetMembers (pRefTypeInfo, pRefTypeAttr, hTreeView, hSubNode2)
                        END IF
                        ' /*** Retrieves the methods and properties ***/
                        IF @pRefTypeAttr->cFuncs THEN
                           hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "Number of methods = " & WSTR(pRefTypeAttr->cFuncs))
                           this.GetFunctions(pRefTypeInfo, pRefTypeAttr, hTreeView, hSubNode2, VTableView, TRUE, pTKind, dwsImplInterface)
                        ELSE
                           hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "Number of methods = 0")
                        END IF
                        IF pRefTypeInfo THEN
                           IF pTypeAttr THEN pRefTypeInfo->ReleaseTypeAttr(pRefTypeAttr)
                           pRefTypeInfo->Release
                        END IF
                        ' // exit the fake loop
                        EXIT DO
                     LOOP
                  END IF
               ELSE
                  VTableView = FALSE
               END IF
               ' ------------------------------------------------------------------------------------------
               ' ...else use the default view
               ' ------------------------------------------------------------------------------------------
               IF pTKind = TKIND_INTERFACE OR pTKind = TKIND_DISPATCH AND CLNG(VTableView) = FALSE THEN
                  dwsImplInterface = TLB_GetImplementedInterface(pTypeInfo)
                  IF dwsImplInterface <> "" THEN
                     IF UCASE(dwsImplInterface) <> "IUNKNOWN" AND UCASE(dwsImplInterface) <> "IDISPATCH" THEN
                        dwsImplInterface = TLB_GetBaseClass(m_pTypeLib, dwsName)
                     END IF
                  END IF
                  IF pTKind = TKIND_INTERFACE THEN
                     IF UCASE(dwsImplInterface) = "IUNKNOWN" AND (pTypeAttr->wTypeFlags AND TYPEFLAG_FOLEAUTOMATION) = TYPEFLAG_FOLEAUTOMATION THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hOleAutIntNode, NULL, dwsName)
                     ELSEIF UCASE(dwsImplInterface) = "IDISPATCH" AND (pTypeAttr->wTypeFlags AND TYPEFLAG_FDUAL) <> TYPEFLAG_FDUAL THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hDispblIntNode, NULL, dwsName)
                     ELSE
                        hSubNode = TreeView_AddItem(hTreeView, m_hIntNode, NULL, dwsName)
                     END IF
                  ELSEIF pTKind = TKIND_DISPATCH THEN
                     IF (pTypeAttr->wTypeFlags AND TYPEFLAG_FDUAL) = TYPEFLAG_FDUAL THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hDualIntNode, NULL, dwsName)
                     ELSEIF INSTR(dwsEvents, "#" & dwsName & "#") THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hEventsNode, NULL, dwsName)
                     ELSE
                        hSubNode = TreeView_AddItem(hTreeView, m_hDispIntNode, NULL, dwsName)
                     END IF
                  END IF
                  IF AfxGuidText(pTypeAttr->guid) <> "{00000000-0000-0000-0000-000000000000}" THEN
                     TreeView_AddItem(hTreeView, hSubNode, NULL, "IID: " & AfxGuidText(pTypeAttr->guid))
                  END IF
                  IF LEN(dwsHelpString) THEN TreeView_AddItem(hTreeView, hSubNode, NULL, "Documentation string: " & dwsHelpString)
                  IF pTypeAttr->wTypeFlags THEN TreeView_AddItem(hTreeView, hSubNode, NULL, "Attributes =  " & WSTR(pTypeAttr->wTypeFlags) & " [&h" & HEX(pTypeAttr->wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(pTypeAttr->wTypeFlags))
                  dwsInheritedInterface = TLB_GetImplementedInterface(pTypeInfo)
                  IF LEN(dwsInheritedInterface) THEN TreeView_AddItem(hTreeView, hSubNode, NULL, "Inherited interface = " & dwsInheritedInterface)
                  ' /*** Datamembers ***/
                  IF pTypeAttr->cVars THEN
                     hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "Number of datamembers = " & WSTR(pTypeAttr->cVars))
                     this.GetMembers (pTypeInfo, pTypeAttr, hTreeView, hSubNode2)
                  END IF
                  ' /*** Retrieves the methods and properties ***/
                  IF pTypeAttr->cFuncs THEN
                     hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "Number of methods = " & WSTR(pTypeAttr->cFuncs))
                     IF pTKind = TKIND_INTERFACE THEN
                        this.GetFunctions(pTypeInfo, pTypeAttr, hTreeView, hSubNode2, TRUE, TRUE, pTKind, dwsImplInterface)
                     ELSE
                        this.GetFunctions(pTypeInfo, pTypeAttr, hTreeView, hSubNode2, VTableView, TRUE, pTKind, dwsImplInterface)
                     END IF
                  ELSE
                     hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, NULL, "Number of methods = 0")
                  END IF
               END IF
            END IF
```

A very important particularity is that the information can be returned in two different kind of views, the `VTable` view and the `Automation` view.

To change the type of views from the default `Automation` one to the `VTable` one, we have to call the **GetRefTypeOfImplType** of the **ITypeInfo** interface. The meager documentation provided by Microsoft states that "If a type description describes a COM class, it retrieves the type description of the implemented interface types. For an interface, **GetRefTypeOfImplType** returns the type information for inherited interfaces, if any exist." See: [GetRefTypeOfImplType](https://msdn.microsoft.com/en-us/library/windows/desktop/ms221569(v=vs.85).aspx)

There is a remark at the bottom: "If the TKIND_DISPATCH type description is for a dual interface, the TKIND_INTERFACE type description can be obtained by calling **GetRefTypeOfImplType** with an indexof –1, and by passing the returned *pRefTypehandle* to **GetRefTypeInfo** to retrieve the type information."

So, if we have a TKIND_DISPATCH description and be want a TKIND_INTERFACE description (assuming that the Dispatch interface is dual and not a dispatch only interface), we can get it passing -1 to **GetRefTypeOfImplType**.

```
' // Attempt to change the view to VTable
pRefType = NULL
hr = pTypeInfo->GetRefTypeOfImplType(-1, @pRefType)
IF hr <> S_OK OR pRefType = NULL THEN
   VTableView = FALSE
   EXIT DO
END IF
hr = pTypeInfo->GetRefTypeInfo(pRefType, @pRefTypeInfo)
IF hr <> S_OK OR pRefTypeInfo = NULL THEN
   VTableView = FALSE
   EXIT DO
END IF
pRefTypeAttr = NULL
hr = pRefTypeInfo->GetTypeAttr(@pRefTypeAttr)
```
