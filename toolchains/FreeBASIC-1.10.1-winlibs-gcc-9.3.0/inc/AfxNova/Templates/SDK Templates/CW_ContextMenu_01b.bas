' ########################################################################################
' Microsoft Windows
' File: CW_ContextMenu_01.bas
' Contents: CWindow - Context menu
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_LABEL = 1001

' // Menu identifiers
ENUM
   IDM_NEW = 1001   ' New file
   IDM_OPEN         ' Open file...
   IDM_SAVE         ' Save file
   IDM_SAVEAS       ' Save file as...
   IDM_EXIT         ' Exit
END ENUM

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Context meu", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Adds a label
   pWindow.AddControl("Label", hWin, IDC_LABEL, "Click the mouse right button", 110, 20, 175, 23)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDC_LABEL, AFX_ANCHOR_WIDTH)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 290, 160, 75, 30)
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
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
'            CASE IDM_NEW   ' IDM_OPEN, IDM_SAVE, etc.
'               MessageBox hwnd, "New option clicked", "Menu", MB_OK
            CASE IDM_NEW TO IDM_EXIT  ' IDM_OPEN, IDM_SAVE, etc.
               MessageBox hwnd, "Option clicked", "Menu", MB_OK
         END SELECT
         RETURN 0

      CASE WM_CONTEXTMENU
         ' // Build the context menu
         DIM hPopUpMenu AS HMENU = CMenu.CreatePopUp
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_OPEN, "&Open..." & CHR(9) & "Ctrl+O"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVEAS, "Save &As..."
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
         DIM pt AS POINT
         GetCursorPos @pt
         CMenu.ContextMenu hwnd, hPopupMenu, pt.x, pt.y

         CMenu.Destroy hPopupMenu
         EXIT FUNCTION

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
