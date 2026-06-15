' ########################################################################################
' Microsoft Windows
' File: CW_SBwithPB_01b.bas
' Contents: CWindow - Status Bar with a Progress Bar
' Contents: Demonstrates the use of the Statusbar and ProgressBar controls.
' Comments: In this example, the progress bar has been made child of the status bar.
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CStatusBar.inc"
#INCLUDE ONCE "AfxNova/CProgBar.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_START = 1001
CONST IDC_STATUSBAR = 1002
CONST IDC_PROGRESSBAR = 1003

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Status bar with progress bar", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Add a status bar
   DIM hStatusbar AS HWND = pWindow.AddControl("Statusbar", , IDC_STATUSBAR)
   ' // Set the parts
   DIM rgParts(1 TO 2) AS LONG = {pWindow.ScaleX(160), -1}
   IF CStatusBar.SetParts(hStatusBar, 2, @rgParts(1)) THEN
      CStatusBar.Simple(hStatusBar, FALSE)
   END IF

   ' // Adds a progress bar to the status bar
   DIM hProgBar AS HWND = pWindow.AddControl("ProgressBar", hStatusbar, IDC_PROGRESSBAR, "", 0, 2, 160, 18)
   ' // Set the range
   CProgBar.SetRange32(hProgBar, 0, 100)
   ' // Set the initial position
   CProgBar.SetPos(hProgBar, 0)
   ' // Disable theme for the control
   SetWindowTheme(hProgBar, "", "")

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDC_START, "&Start", 20, 20, 75, 23)

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
            CASE IDC_START
               ' // Retrieve the handle to the progress bar
               DIM hProgBar AS HWND = GetDlgItem(GetDlgItem(hwnd, IDC_STATUSBAR), IDC_PROGRESSBAR)
               ' *** Test code ***
               ' // Sets the step increment
               CProgBar.SetStep(hProgBar, 1)
               ' // Draws the bar
               FOR i AS LONG = 1 TO 100
                  ' // Advances the current position for a progress bar by the step
                  ' // increment and redraws the bar to reflect the new position
                  CProgBar.StepIt(hProgBar)
                  SLEEP 10
               NEXT
               ' // Clears the bar by reseting its position to 0
               CProgBar.SetPos(hProgBar, 0)
         END SELECT
         RETURN 0

      CASE WM_SIZE
         ' // Resizes the status bar and redraws it
         DIM hStatusBar AS HWND = GetDlgItem(hwnd, IDC_STATUSBAR)
         SendMessageW hStatusBar, WM_SIZE, wParam, lParam
         InvalidateRect hStatusBar, NULL, CTRUE
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
