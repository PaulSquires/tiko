' ########################################################################################
' Microsoft Windows
' File: CW_ListBox_DarkMode_01.bas
' Contents: ListBox control
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE   ' ListBox_AddString needs the unicode flag
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

#define IDC_LISTBOX 1001

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - ListBox control", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(318, 380)
   ' // Center the window
   pWindow.Center
   pWindow.SetBackColor(RGB_BLACK)

   ' // Adds a listbox
   DIM hListBox AS HWND = pWindow.AddControl("ListBox", hWin, IDC_LISTBOX)
   pWindow.SetWindowPos hListBox, NULL, 8, 8, 300, 320, SWP_NOZORDER
   ' // Anchor the ListBox
   pWindow.AnchorControl(IDC_LISTBOX, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Dark scrollbars
   SetWindowTheme(hListBox, "DarkMode_Explorer", NULL)
   ' // Colors of the listbox items
   pWindow.SetCtlColors(hListBox, RGB_WHITE, RGB_BLACK)

   ' // Fill the list box
   DIM dwsText AS DWSTRING
   FOR i AS LONG = 1 TO 50
      dwsText = "Item " & RIGHT("00" & WSTR(i), 2)
      ListBox_AddString(hListBox, *dwsText)
      ' -- or --
      ' AfxListBoxAddString(hListBox, dwsText)
   NEXT
   ' // Select the first item
   ListBox_SetCursel(hListBox, 0)

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
            CASE IDC_LISTBOX
               SELECT CASE CBCTLMSG(wParam, lParam)
                  CASE LBN_DBLCLK
                     ' // Get the handle of the Listbox
                     DIM hListBox AS HWND = GetDlgItem(hwnd, IDC_LISTBOX)
                     ' // Get the current selection
                     DIM curSel AS LONG = ListBox_GetCursel(hListBox)
                     DIM dwsText AS DWSTRING = AfxGetListBoxText(hListBox, curSel)
                     MessageBoxW(hwnd, dwsText, "ListBox test", MB_OK)
               END SELECT
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
