' ########################################################################################
' Microsoft Windows
' File: CW_TaskDialogIndirect_01.bas
' Contents: CWindow - Button
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
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
DECLARE FUNCTION TaskDialogIndirectCallbackProc(BYVAL hwnd AS HWND, BYVAL uNotification AS UINT, BYVAL wParam AS WPARAM, _
        BYVAL lParam AS LPARAM, BYVAL dwRefData AS LONG_PTR) AS HRESULT

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Task Dialog", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Add buttons
   pWindow.AddControl("Button", hWin, IDOK, "Click me", 200, 155, 75, 30)
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 290, 155, 75, 30)
   ' // Anchors the buttons to the bottom and the right side of the main window
   pWindow.AnchorControl(IDOK, AFX_ANCHOR_BOTTOM_RIGHT)
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
            ' // Launch the Pick icon dialog
            CASE IDOK
               ' // Display the message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  DIM TaskConfig AS TASKDIALOGCONFIG
                  WITH TaskConfig
                     .cbSize = SIZEOF(TASKDIALOGCONFIG)
                     .hwndParent = hwnd
                     .dwFlags = TDF_ENABLE_HYPERLINKS
                     .pszWindowTitle = @WSTR("CWindow")
                     .pszMainIcon = TD_INFORMATION_ICON
                     .dwCommonButtons = TDCBF_OK_BUTTON OR TDCBF_CANCEL_BUTTON
                     .pszMainInstruction = @WSTR("CWindow")
                     .pszContent = @WSTR("An update for the CWindow framework has just been released. Click the hyperlink if you want to download it.")
                     .pszFooter = @WSTR("Hyperlink: <A HREF=" & CHR(34) & "https://github.com/JoseRoca/AfxNova" & CHR(34) & ">Download link</A>")
                     .pszFooterIcon = TD_WARNING_ICON
                     .nDefaultButton = IDOK
                     .pfCallback = @TaskDialogIndirectCallbackProc
                  END WITH
                  DIM nClickedButton AS LONG
                  DIM hr AS HRESULT = AfxTaskDialogIndirect(@TaskConfig, @nClickedButton, NULL, NULL)
               END IF
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

' ========================================================================================
' Callback for TaskDialogIndirect.
' ========================================================================================
FUNCTION TaskDialogIndirectCallbackProc(BYVAL hwnd AS HWND, BYVAL uNotification AS UINT, BYVAL wParam AS WPARAM, _
                                        BYVAL lParam AS LPARAM, BYVAL dwRefData AS LONG_PTR) AS HRESULT
   SELECT CASE uNotification
      CASE TDN_HYPERLINK_CLICKED
         ' // The lParam parameter of this message contains the url
         DIM hInstance AS HINSTANCE = ShellExecuteW(NULL, "open", cast(WSTRING PTR, lParam), NULL, NULL, SW_SHOW)
         IF hInstance <= 32 THEN FUNCTION = cast(HRESULT, (cast(LONG_PTR, hInstance))) ELSE FUNCTION = S_OK
   END SELECT
END FUNCTION
' ========================================================================================
