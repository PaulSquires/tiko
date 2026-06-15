' ########################################################################################
' Microsoft Windows
' File: CW_Menu_NestedSubmenus_01.bas
' Contents: CWindow - Nested submenus
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
#INCLUDE ONCE "AfxNova/AfxMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

 
' // Menu identifiers
ENUM
   IDM_NEW = 1001     ' New file
   IDM_OPEN           ' Open file...
   IDM_SAVE           ' Save file
   IDM_SAVEAS         ' Save file as...
   IDM_EXIT           ' Exit

   IDM_UNDO = 2001    ' Undo
   IDM_CUT            ' Cut
   IDM_COPY           ' Copy
   IDM_PASTE          ' Paste

   IDM_TILEH = 3001   ' Tile hosizontal
   IDM_TILEV          ' Tile vertical
   IDM_CASCADE        ' Cascade
   IDM_ARRANGE        ' Arrange icons
   IDM_CLOSE          ' Close
   IDM_CLOSEALL       ' Close all
END ENUM

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CMenu.Create
   hPopUpMenu = CMenu.NewPopup
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_OPEN, "&Open..." & CHR(9) & "Ctrl+O"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVEAS, "Save &As..."
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   hPopUpMenu = CMenu.CreatePopUp
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Edit"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+Z"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CUT, "Cu&t" & CHR(9) & "Ctrl+X"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_COPY, "&Copy" & CHR(9) & "Ctrl+C"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_PASTE, "&Paste" & CHR(9) & "Ctrl+V"
   hPopUpMenu = CMenu.CreatePopUp
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Window"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_TILEH, "&Tile Horizontal"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_TILEV, "Tile &Vertical"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CASCADE, "Ca&scade"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_ARRANGE, "&Arrange &Icons"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CLOSE, "&Close" & CHR(9) & "Ctrl+F4"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CLOSEALL, "Close &All"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""

   ' // Nested menus
   DIM hSubPopUpMenu AS HMENU = CMenu.CreatePopUp
         CMenu.AddPopup hPopUpMenu, hSubPopUpMenu, MF_ENABLED, 4001, "Nested submenu 1"
         CMenu.Append hSubPopUpMenu, MF_ENABLED, 4002, "Nested submenu 1 item 1"
         CMenu.Append hSubPopUpMenu, MF_ENABLED, 4003, "Nested submenu 1 item 2"
         CMenu.Append hSubPopUpMenu, MF_SEPARATOR, 0, ""
   DIM hSubPopUpMenu2 AS HMENU = CMenu.CreatePopUp
         CMenu.AddPopup hSubPopUpMenu, hSubPopUpMenu2, MF_ENABLED, 5001, "Nested submenu 2"
         CMenu.Append hSubPopUpMenu2, MF_ENABLED, 5002, "Nested submenu 2 item 1"
         CMenu.Append hSubPopUpMenu2, MF_ENABLED, 5003, "Nested submenu 2 item 2"

   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

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

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Menu", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Creates the menu
   DIM hMenu AS HMENU = BuildMenu
   CMenu.SetMenu pWindow.hWindow, hMenu

   ' // Set the main window background color
   pWindow.SetBackColor(RGB_GOLD)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Anchors the button to the bottom and the right side of the main window
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

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

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
            CASE IDM_NEW   ' IDM_OPEN, IDM_SAVE, etc.
               MessageBox hwnd, "New option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT
         RETURN 0

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
