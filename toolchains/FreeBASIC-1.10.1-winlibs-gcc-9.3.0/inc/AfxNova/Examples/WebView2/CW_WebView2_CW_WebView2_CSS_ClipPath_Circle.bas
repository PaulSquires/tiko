' ########################################################################################
' Microsoft Windows
' File: CW_WebView2_CSS_ClipPath_Circle.bas
' Contents: WebView2 example - Display clipped image
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José© Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define _WIN32_WINNT &h0602
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

CONST IDC_LABEL = 1001

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
   DIM hWin AS HWND = pWindow.Create(NULL, "WebView2 - Display clipped image", @WndProc)
   ' // Set its client size
   pWindow.SetClientSize(640, 440)
   ' // Center the window
   pWindow.Center

   ' // Adds a label
   DIM hLabel AS HWND = pWindow.AddControl("Label", hWin, IDC_LABEL, "", 20, 20, 600, 395)
   ' // Anchors the label to the height and width of the main window
   pWindow.AnchorControl(hLabel, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Use the same folder for the WebView2 files
   ' // Here we are using a subfolder in the temporary folder
   DIM dwsUserDataFolder AS DWSTRING = AfxGetTempPath & "AfxNovaWebView2"

   ' // Create an instance of WebView
   DIM pWebView2 AS CWebView2 = CWebView2(hLabel, dwsUserDataFolder)

   ' // Wait until is ready
   IF pWebView2.IsReady THEN

      ' // Build the script
      DIM s AS STRING

      s = "<!DOCTYPE html>"
      s += "<html>"
      s += "<head>"
      s += "<meta charset='UTF-8'>"

      ' // CSS code (Cascading Style Sheets)
      s += "<style>"
      s += "body {"
      s += "  background: linear-gradient(45deg, violet, pink);"
      s += "  filter: drop-shadow(0 0 30px rgba(0,0,0,0.5));"
      s += "  animation: zoom 6s infinite alternate;"
      s += "}"

      s += "@keyframes zoom {"
      s += "  0% { clip-path: circle(30%); }"
      s += "  100% { clip-path: circle(40%); }"
      s + = "}"

      s += "#img1 {"
      s += "  width: 100vw;"
      s += "  height: 100vh;"
      s += "  object-fit: cover;"
      s += "  object-position: center;"
      s += "  clip-path: circle(35%);"
      s += "}"
      s += "html, body {"
      s += "  margin: 0;"
      s += "  padding: 0;"
      s += "  overflow: hidden;"
      s += "}"

      ' // HTML code
      s += "</style>"
      s += "</head>"
      s += "<body>"
      s += "<img id='img1' src='https://images.unsplash.com/photo-1532274402911-5a369e4c4bb5?w=600&auto=format&fit=crop&q=60'>"
      s += "</body>"
      s += "</html>"
      
      ' // Navigate to the string
      pWebView2.NavigateToString(s)

      ' // Set the focus in the web page
      pWebView2.MoveFocus(COREWEBVIEW2_MOVE_FOCUS_REASON_PROGRAMMATIC)

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

      CASE WM_COMMAND
         
         SELECT CASE CBCTL(wParam, lParam)

            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE WM_SIZE
         ' // Set the bound of the WebView2 control
         DIM hLabel AS HWND = GetDLgItem(hwnd, IDC_LABEL)
         DIM pWebView2 AS CWebView2 PTR = CAST(CWebView2 PTR, GetWindowLongPtrW(hLabel, GWLP_USERDATA))
         IF pWebView2 THEN
            DIM rc AS RECT
            IF GetClientRect(hLabel, @rc) THEN
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
