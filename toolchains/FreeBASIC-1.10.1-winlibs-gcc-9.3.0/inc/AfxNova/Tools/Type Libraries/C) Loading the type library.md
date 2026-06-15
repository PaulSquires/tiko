# Loading the type library

Once we have retrieved the path of the type library, the next step if to load it calling the API functions **LoadTypelib** or **LoadTypeLibEx**, that return a pointer of the **ITypeLib** interface.

This is my definition of that interface:

```
' ########################################################################################

' Interface name = ITypeLib
' Extracts information about a type library, the data that describes a set of objects.
' Inherited interface = IUnknown
' ########################################################################################
#ifndef __Afx_ITypeLib_INTERFACE_DEFINED__
#define __Afx_ITypeLib_INTERFACE_DEFINED__
TYPE Afx_ITypeLib_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetTypeInfoCount () AS UINT
   DECLARE ABSTRACT FUNCTION GetTypeInfo (BYVAL index AS UINT, BYVAL ppTInfo AS Afx_ITypeInfo PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTypeInfoType (BYVAL index AS UINT, BYVAL pTKind AS TYPEKIND PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTypeInfoOfGuid (BYVAL guid AS CONST GUID CONST PTR, BYVAL ppTinfo AS Afx_ITypeInfo PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLibAttr (BYVAL ppTLibAttr AS TLIBATTR PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTypeComp (BYVAL ppTComp AS ITypeComp PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDocumentation (BYVAL index AS INT_, BYVAL pBstrName AS AFX_BSTR PTR, BYVAL pBstrDocString AS AFX_BSTR PTR, BYVAL pdwHelpContext AS DWORD PTR, BYVAL pBstrHelpFile AS AFX_BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsName (BYVAL szNameBuf AS LPOLESTR, BYVAL lHashVal AS ULONG, BYVAL pfName AS WINBOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION FindName (BYVAL szNameBuf AS LPOLESTR, BYVAL lHashVal AS ULONG, BYVAL ppTInfo AS Afx_ITypeInfo PTR PTR, BYVAL rgMemId AS MEMBERID PTR, BYVAL pcFound AS USHORT PTR) AS HRESULT
   DECLARE ABSTRACT SUB      ReleaseTLibAttr (BYVAL pTLibAttr AS TLIBATTR PTR)
END TYPE
#endif
```

and this is some code to load the type library and extract basic information:

```
' =====================================================================================
' Load the type library
' =====================================================================================
FUNCTION CParseTypeLib.LoadTypeLibEx (BYVAL pwszPath AS WSTRING PTR) AS HRESULT

   DIM pTypeLib AS ITypeLib PTR
   DIM hr AS HRESULT = .LoadTypeLibEx(pwszPath, REGKIND_NONE, @pTypeLib)
   m_pTypeLib = cast(Afx_ITypeLib PTR, cast(ULONG_PTR, pTypeLib))
   IF hr <> S_OK OR m_pTypeLib = NULL THEN
      TLB_MsgBox m_pWindow->hWindow, "Error &h" & HEX(hr, 8) & " loading " & *pwszPath, _
         MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.LoadTypeLibEx"
      RETURN hr
   END IF
   m_LibPath = *pwszPath

   ' // Gets the documentation
   DIM AS AFX_BSTR bstrLibName, bstrLibHelpString, bstrLibHelpFile
   hr = m_pTypeLib->GetDocumentation(-1, @bstrLibName, @bstrLibHelpString, @m_LibHelpContext, @bstrLibHelpFile)
   m_LibName = *bstrLibName : m_LibHelpString = *bstrLibHelpString : m_LibHelpFile = *bstrLibHelpFile
   SysFreeString bstrLibName : SysFreeString bstrLibHelpString : SysFreeString bstrLibHelpFile
   IF hr <> S_OK THEN
      TLB_MsgBox m_pWindow->hWindow, "Error &h" & HEX(hr, 8) & " retrieving the documentation", _
         MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.LoadTypeLibEx"
      RETURN hr
   END IF
   ' // Use the library name as a namespace
   m_Namespace = TRIM(m_LibName, ANY CHR(32, 34))
   DIM hEditNamespace AS HWND = cast(HWND, m_pWindow->UserData(AFX_HEDITNAMESPACE))
   SetWindowText hEditNamespace, m_Namespace

   ' // Gets the attributes of the library
   DIM pLibAttr AS TLIBATTR PTR
   hr = m_pTypeLib->GetLibAttr(@pLibAttr)
   IF hr <> S_OK OR pLibAttr = NULL THEN
      TLB_MsgBox m_pWindow->hWindow, "Error &h" & HEX(hr, 8) & " retrieving the attributes", _
         MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.LoadTypeLibEx"
      RETURN hr
   END IF
   m_LibGuid = AfxGuidText(pLibAttr->guid)
   m_LibLcid = pLibAttr->lcid
   m_LibSysKind = pLibAttr->syskind
   m_LibMajorVersion = pLibAttr->wMajorVerNum
   m_LibMinorVersion = pLibAttr->wMinorVerNum
   m_LibAttr = pLibAttr->wLibFlags
   m_pTypeLib->ReleaseTLibAttr(pLibAttr)

   ' // Treeview handle
   DIM hTreeView AS HWND = cast(HWND, m_pWindow->UserData(AFX_HTREEVIEW))
   ' // Delete all the items in the tree view
   TreeView_DeleteAllItems(hTreeView)
   ' // Create the nodes
   m_hRootNode = TreeView_AddItem(hTreeView, 0, TVI_ROOT, m_LibName)
   m_hDocNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Documentation")
   m_hProgIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "ProgIDs (Program identifiers)")
   m_hVerIndProgIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Version independent ProgIDs")
   m_hClsIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "ClsIDs (Class identifiers)")
   m_hIIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "IIDs (Interface identifiers)")
   m_hCoClassesNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "CoClasses")
   m_hTypeDefsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Typedefs")
   m_hAliasesNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Aliases")
   m_hEnumsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Enumerations")
   m_hRecordsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Structures")
   m_hUnionsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Unions")
   m_hModulesNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Modules")
   m_hIntNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Interfaces")
   m_hOleAutIntNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Ole automation interfaces")
   m_hDualIntNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Dual interfaces")
   m_hDispIntNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Dispatch interfaces")
   m_hDispblIntNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Dispatchable interfaces")
   m_hEventsNode = TreeView_AddItem(hTreeView, m_hRootNode, NULL, "Events interfaces")
   ' // Fill the documentation node
   IF m_hDocNode THEN
      IF LEN(m_LibHelpString) THEN TreeView_AddItem hTreeView, m_hDocNode, NULL, "Help string = " & m_LibHelpString
      TreeView_AddItem hTreeView, m_hDocNode, NULL, "GUID = " & m_LibGuid
      TreeView_AddItem hTreeView, m_hDocNode, NULL, "LCID = " & WSTR(m_LibLcid)
      TreeView_AddItem hTreeView, m_hDocNode, NULL, "Major version = " & WSTR(m_LibMajorVersion)
      TreeView_AddItem hTreeView, m_hDocNode, NULL, "Minor version = " & WSTR(m_LibMinorVersion)
      TreeView_AddItem hTreeView, m_hDocNode, NULL, "Path = " & m_LibPath
      IF m_LibHelpContext THEN TreeView_AddItem hTreeView, m_hDocNode, NULL, "Help context = " & WSTR(m_LibHelpContext)
      IF LEN(m_LibHelpFile) THEN TreeView_AddItem hTreeView, m_hDocNode, NULL, "Help file = " & m_LibHelpFile
      TreeView_AddItem hTreeView, m_hDocNode, NULL, "Attributes = " & WSTR(m_LibAttr) & " [&h" & HEX(m_LibAttr, 8) & "] " & TLB_LibFlagsToStr(m_LibAttr)
      SELECT CASE m_LibSysKind
         CASE SYS_WIN16 : TreeView_AddItem hTreeView, m_hDocNode, NULL, "Target OS = " & WSTR(m_LibSysKind) & " (Win16)"
         CASE SYS_WIN32 : TreeView_AddItem hTreeView, m_hDocNode, NULL, "Target OS = " & WSTR(m_LibSysKind) & " (Win32)"
         CASE SYS_MAC   : TreeView_AddItem hTreeView, m_hDocNode, NULL, "Target OS = " & WSTR(m_LibSysKind) & " (MAC)"
         CASE SYS_WIN64 : TreeView_AddItem hTreeView, m_hDocNode, NULL, "Target OS = " & WSTR(m_LibSysKind) & " (Win64)"
      END SELECT
   END IF

   ' // Parse the type infos
   this.ParseTypeInfos

   ' // Generate code
   this.GenerateCode

   ' // Expands the root node
   TreeView_Expand(hTreeView, m_hRootNode, TVE_EXPAND)

END FUNCTION
' =====================================================================================
```
