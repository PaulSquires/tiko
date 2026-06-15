' ########################################################################################
' Microsoft Windows
' File: CW_Split_Button_01.bas
' Contents: CWindow - Split Button
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "CW_SplitButton_01.rc"
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxGdiplus.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_SPLITBUTTON = 1001
CONST IDC_MENUCOMMAND1 = 28000
CONST IDC_MENUCOMMAND2 = 28001
CONST IDC_MENUCOMMAND3 = 28002

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Split Button", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Add a button without position or size (it will be resized in the WM_SIZE message).
   DIM hSplitButton AS HWND = pWindow.AddControl("Button", hWin, IDC_SPLITBUTTON, "&Shutdown", 140, 60, 110, 30, BS_SPLITBUTTON)
   ' // Calculate an appropriate icon size
   DIM cx AS LONG = 16 * pWindow.DPI \ 96
   ' // Create an image list for the button
   DIM hImageList AS HIMAGELIST = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 1, 0)
   ' // --> Remember to change the path and name of the icon
   IF hImageList THEN AfxGdipAddIconFromRes(hImageList, hInstance, "IDI_SHUTDOWN_48")
   ' // Fill a BUTTON_IMAGELIST structure and set the image list
   DIM bi AS BUTTON_IMAGELIST = (hImageList, (3, 3, 3, 3), BUTTON_IMAGELIST_ALIGN_LEFT)
   Button_SetImageList(hSplitButton, @bi)
   ' // Anchor the button
   pWindow.AnchorControl(IDC_SPLITBUTTON, AFX_ANCHOR_CENTER)

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
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         ' // Processs notify messages sent by the split button
         DIM tDropDown AS NMBCDROPDOWN
         CBNMTYPESET(tDropDown, wParam, lParam)
         IF tDropDown.hdr.idFrom = IDC_SPLITBUTTON THEN
            IF tDropDown.hdr.code = BCN_DROPDOWN THEN
               ' // Get the screen coordinates of the button
               DIM pt AS POINT = (tDropdown.rcButton.left, tDropDown.rcButton.bottom)
               ClientToScreen(tDropDown.hdr.hwndFrom, @pt)
               ' // Create a menu and add items
               DIM hSplitMenu AS HMENU = CreatePopupMenu
               AppendMenuW(hSplitMenu, MF_BYPOSITION, IDC_MENUCOMMAND1, "Menu item 1")
               AppendMenuW(hSplitMenu, MF_BYPOSITION, IDC_MENUCOMMAND2, "Menu item 2")
               AppendMenuW(hSplitMenu, MF_BYPOSITION, IDC_MENUCOMMAND3, "Menu item 3")
               ' // Display the menu
               DIM flags AS DWORD = TPM_LEFTBUTTON OR TPM_NONOTIFY OR TPM_RETURNCMD OR TPM_NOANIMATION
               DIM id AS LONG = TrackPopupMenu(hSplitMenu, flags, pt.x, pt.y, 0, hwnd, NULL)
               SELECT CASE id
                  CASE IDC_MENUCOMMAND1
                     MessageBoxW(hwnd, "You clicked item 1", "Message", MB_OK)
                  CASE IDC_MENUCOMMAND2
                     MessageBoxW(hwnd, "You clicked item 2", "Message", MB_OK)
                  CASE IDC_MENUCOMMAND3
                     MessageBoxW(hwnd, "You clicked item 3", "Message", MB_OK)
               END SELECT
               DestroyMenu hSplitMenu
            ELSEIF tDropDown.hdr.code = BCN_HOTITEMCHANGE THEN
               DIM tHotItem AS NMBCHOTITEM
               CBNMTYPESET(tHotItem, wParam, lParam)
               IF (tHotItem.dwFlags AND HICF_ENTERING) THEN
                  SetWindowText hwnd, "Mouse entering the button"
               ELSEIF (tHotItem.dwFlags AND HICF_LEAVING) THEN
                  SetWindowText hwnd, "Mouse leaving the button"
               END IF
            END IF
            RETURN TRUE
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
