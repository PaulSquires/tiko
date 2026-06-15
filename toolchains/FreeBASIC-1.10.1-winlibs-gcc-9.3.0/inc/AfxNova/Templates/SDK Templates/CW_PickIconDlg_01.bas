' ########################################################################################
' Microsoft Windows
' File: CW_PickIconDlg_01.bas
' Contents: CWindow - Pick Icon dialog
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

CONST IDC_PICKDLG = 1001   ' // Pick icon dialog identifier

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Pick Icon Dialog", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(500, 320)
   ' // Centers the window
   pWindow.Center

   ' // Add buttons without position or size (it will be resized in the WM_SIZE message).
   pWindow.AddControl("Button", hWin, IDC_PICKDLG, "&Pick", pWindow.ClientWidth - 230, pWindow.ClientHeight - 50, 75, 30)
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", pWindow.ClientWidth - 120, pWindow.ClientHeight - 50, 75, 30)


   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC wszIconPath AS WSTRING * MAX_PATH   ' // Path of the resource file containing the icons
   STATIC nIconIndex AS LONG                  ' // Icon index
   STATIC hIcon AS HICON                      ' // Icon handle

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
            ' // Launch the Pick icon dialog
            CASE IDC_PICKDLG
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  IF LEN(wszIconPath) = 0 THEN wszIconPath = AfxGetSystemDllPath("Shell32.dll")
                  IF LEN(wszIconPath) = 0 THEN EXIT FUNCTION
                  ' // Activate the Pick Icon Common Dialog Box
                  DIM hr AS LONG = PickIconDlg(0, wszIconPath, SIZEOF(wszIconPath)\2, @nIconIndex)
                  ' // If an icon has been selected...
                  IF hr = 1 THEN
                     ' // Destroy previously loaded icon, if any
                     IF hIcon THEN DestroyIcon(hIcon)
                     ' // Get the handle of the new selected icon
                     hIcon = ExtractIconW(GetModuleHandle(NULL), wszIconPath, nIconIndex)
                     ' // Replace the application icons
                     IF hIcon THEN
                        AfxSetWindowIcon hwnd, ICON_SMALL, hIcon
                        AfxSetWindowIcon hwnd, ICON_BIG, hIcon
                     END IF
                  END IF
                  EXIT FUNCTION
               END IF
         END SELECT
         RETURN 0

      CASE WM_DESTROY
         ' // Destroy the icon
         IF hIcon THEN DestroyIcon(hIcon)
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
