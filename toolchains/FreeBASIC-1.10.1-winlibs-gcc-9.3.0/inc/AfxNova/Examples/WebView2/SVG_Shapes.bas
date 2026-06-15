' ########################################################################################
' Microsoft Windows
' File: SVG_Shapes.bas
' Contents: WebView2 example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José© Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#define _WIN32_WINNT &h0602
#include once "AfxNova/CWindow.inc"
'#define _CWV2_DEBUG_ 1
#include once "AfxNova/CWebView2.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

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
   DIM pWindow AS CWindow
   DIM hWin AS HWND = pWindow.Create(NULL, "WebView2 - SVG Shaped", @WndProc)
   ' // Set its client size
   pWindow.SetClientSize(630, 380)
   ' // Center the window
   pWindow.Center

   ' // Use the same folder for the WebView2 files
   ' // Here we are using a subfolder in the temporary folder
   DIM dwsUserDataFolder AS DWSTRING = AfxGetTempPath & "AfxNovaWebView2"

   ' // Create an instance of WebView
   DIM pWebView2 AS CWebView2 = CWebView2(hWin, dwsUserDataFolder)

   ' // Wait until is ready
   IF pWebView2.IsReady THEN

      ' // Build the script

      DIM s AS DWSTRING

      s  = "<!DOCTYPE html>"
      s += "<html><head><meta charset=""UTF-8""></head><body>"
      s += "<h2>SVG Shapes Demo</h2>"
      s += "<svg width=""600"" height=""300"" xmlns=""http://www.w3.org/2000/svg"">"

      ' Rectangle with rounded corners
      s += "  <rect x=""20"" y=""20"" width=""100"" height=""60"" rx=""10"" ry=""10"" "
      s += "        style=""fill:blue;stroke:black;stroke-width:2;opacity:0.7"" />"

      ' Circle
      s += "  <circle cx=""200"" cy=""50"" r=""30"" "
      s += "          style=""fill:green;stroke:black;stroke-width:2;opacity:0.7"" />"

      ' Ellipse
      s += "  <ellipse cx=""320"" cy=""50"" rx=""50"" ry=""30"" "
      s += "           style=""fill:orange;stroke:black;stroke-width:2;opacity:0.7"" />"

      ' Line
      s += "  <line x1=""400"" y1=""20"" x2=""500"" y2=""80"" "
      s += "        style=""stroke:red;stroke-width:4"" />"

      s += "</svg>"
      s += "</body></html>"

      ' // Navigate to the string
      pWebView2.NavigateToString(s)

   END IF

   ' // Dispatch Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window callback procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC hFocus AS HWND

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

      CASE WM_COMMAND
         
         SELECT CASE GET_WM_COMMAND_ID(wParam, lParam)

            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE WM_SIZE
         ' // Resize the WebView
         DIM pWebView2 AS CWebView2 PTR = AfxCWebView2Ptr(hWnd)
         IF pWebView2 THEN
            DIM rc AS RECT
            IF GetClientRect(hWnd, @rc) THEN
               pWebView2->SetBounds(rc)
            ENDIF
         END IF

    	CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
