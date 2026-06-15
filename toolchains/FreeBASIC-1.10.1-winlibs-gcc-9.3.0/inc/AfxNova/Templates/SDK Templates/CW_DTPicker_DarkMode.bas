' ########################################################################################
' Microsoft Windows
' File: CW_DTPicker_DarkMode.bas
' Contents: CWindow - Date and time picker
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_LABEL = 1001
CONST IDC_DTPICKER = 1002

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Button", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_BLACK)

   ' // Add a lebel
   DIM hLabel AS HWND = pWindow.AddControl("Label", hWin, IDC_LABEL, "Select one date with the mouse", 50, 20, 300, 23)
   ' // Set the label colors
   pWindow.SetCtlColors(hLabel, RGB_WHITE, RGB_BLACK)

   ' // Add a date time picker control
   DIM htDTP AS HWND = pWindow.AddControl("DateTimePicker", hWin, IDC_DTPICKER, "", 100, 60, 150, 23)

   ' // Anchor the controls
   pWindow.AnchorControl(IDC_LABEL, AFX_ANCHOR_WIDTH)
   pWindow.AnchorControl(IDC_DTPICKER, AFX_ANCHOR_WIDTH)

   ' // Set the date
   DIM st AS SYSTEMTIME
   st.wDay = 15
   st.wMonth = 8
   st.wYear = 2016
   DateTime_SetSystemTime(htDTP, GDT_VALID, @st)

   ' // Adds a button
   DIM hButton AS HWND = pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Set dark mode for the button
   SetWindowTheme(hButton, "DarkMode_Explorer", NULL)
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
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         ' // Notification messages
         DIM dtp AS NMDATETIMECHANGE
         CBNMTYPESET(dtp, wParam, lParam)
         IF dtp.nmhdr.idfrom = IDC_DTPICKER THEN
            IF dtp.nmhdr.code = DTN_DROPDOWN THEN
               ' // Get the handle of the month calendar control
               DIM hMonthCal AS HWND = DateTime_GetMonthCal(dtp.nmhdr.hwndFrom)
                  ' // Disable visual styles
               SetWindowTheme(hMonthCal, "", "")
               ' // Apply dark colors
               MonthCal_SetColor(hMonthCal, MCSC_BACKGROUND, RGB_BLACK)
               MonthCal_SetColor(hMonthCal, MCSC_MONTHBK, RGB_BLACK)
               MonthCal_SetColor(hMonthCal, MCSC_TEXT, RGB_WHITE)
               MonthCal_SetColor(hMonthCal, MCSC_TITLEBK, RGB_BLACK)
               MonthCal_SetColor(hMonthCal, MCSC_TITLETEXT, RGB_WHITE)
               MonthCal_SetColor(hMonthCal, MCSC_TRAILINGTEXT, RGB_LIGHTGRAY)
            END IF
            IF dtp.nmhdr.code = DTN_DATETIMECHANGE THEN
               ' // Get the selected date
               DIM wszDate AS WSTRING * 260
               GetDateFormatW LOCALE_USER_DEFAULT, DATE_LONGDATE, @dtp.st, NULL, wszDate, SIZEOF(wszDate)\2
               SetWindowText(GetDlgItem(hwnd, IDC_LABEL), "Selected date: " & wszDate)
            END IF
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
