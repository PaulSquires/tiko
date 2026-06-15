' ########################################################################################
' Microsoft Windows
' File: CW_TreeView_DarkMode.bas
' Contents: CWindow - TreeView control
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CTreeView.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

#define IDC_TREEVIEW 1001

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Create the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - TreeView control", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(320, 375)
   ' // Center the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_BLACK)

   ' // Add a TreeView
   DIM hTreeView AS HWND
   hTreeView = pWindow.AddControl("TreeView", hWin, IDC_TREEVIEW, "")
   pWindow.SetWindowPos hTreeView, NULL, 8, 8, 300, 320, SWP_NOZORDER
   ' // To add checkboxes, use:
   'AfxAddWindowStyle hTreeView, TVS_CHECKBOXES
   ' // Set dark mode
   SetWindowTheme(hTreeView, "DarkMode_Explorer", NULL)
   ' // Set colors
   CTreeView.SetBkColor(hTreeView, RGB_BLACK)
   CTreeView.SetTextColor(hTreeView, RGB_WHITE)

   ' // Anchor the TreeView
   pWindow.AnchorControl(IDC_TREEVIEW, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Add items to the TreeView
   DIM AS HTREEITEM hRoot, hNode, hItem
   ' // Create the root node
   hRoot = CTreeView.AddRootItem(hTreeView, "Root")
   ' // Create a node
   hNode = CTreeView.AppendItem(hTreeView, hRoot, "Node 1")
   ' // Insert items in the node
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 1 Item 1")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 1 Item 2")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 1 Item 3")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 1 Item 4")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 1 Item 5")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 1 Item 6")
   ' // Expand the node
   CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)
   ' // Create another node
   hNode = CTreeView.AppendItem(hTreeView, hRoot, "Node 2")
   ' // Insert items in the node
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 2 Item 1")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 2 Item 2")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 2 Item 3")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 2 Item 4")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 2 Item 5")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 2 Item 6")
   ' // Expand the node
   CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)
   ' // Create another node
   hNode = CTreeView.AppendItem(hTreeView, hRoot, "Node 3")
   ' // Insert items in the node
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 3 Item 1")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 3 Item 2")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 3 Item 3")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 3 Item 4")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 3 Item 5")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 3 Item 6")
   ' // Expand the node
   CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)
   ' // Create another node
   hNode = CTreeView.AppendItem(hTreeView, hRoot, "Node 4")
   ' // Insert items in the node
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 4 Item 1")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 4 Item 2")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 4 Item 3")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 4 Item 4")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 4 Item 5")
   hItem = CTreeView.AppendItem(hTreeView, hNode, "Node 4 Item 6")
   ' // Expand the node
   CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)

   ' // Expand the root node
   CTreeView.Expand(hTreeView, hRoot, TVE_EXPAND)

   ' // Add a cancel button
   DIM hButton AS HWND = pWindow.AddControl("Button", hWin, IDCANCEL, "&Cancel",  233, 340, 75, 23)
      ' // Set button dark mode
   SetWindowTheme(hButton, "DarkMode_Explorer", NULL)
   ' // Anchor the button
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         EXIT FUNCTION

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         DIM hdr AS NMHDR
         CBNMTYPESET(hdr, wParam, lParam)
         IF hdr.idFrom = IDC_TREEVIEW AND hdr.code = NM_DBLCLK THEN
            ' // Retrieve the handle of the TreeView
            DIM hTreeView AS HWND = GetDlgItem(hwnd, IDC_TREEVIEW)
            ' // Retrieve the selected item
            DIM hItem AS HTREEITEM = CTreeView.GetSelection(hTreeView)
            ' // Retrieve the text of the selected item
            DIM wszText AS WSTRING * 260
            CTreeView.GetItemText(hTreeView, hItem, @wszText, 260)
            MessageBoxW hwnd, wszText, "Message", MB_OK
            RETURN 0
         END IF

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
