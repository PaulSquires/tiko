' ########################################################################################
' Microsoft Windows
' File: CW_WebView2_DisplayWbemideo
' Contents: WebView2 example - Display WBEM video
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

' ########################################################################################
' CWebView2NavigationCompletedEventHandlerImpl class
' Implementation of the ICoreWebView2NavigationCompletedEventHandler callback interface.
' ########################################################################################
TYPE CWebView2NavigationCompletedEventHandlerImpl EXTENDS CWebView2NavigationCompletedEventHandler

   DECLARE FUNCTION Invoke (BYVAL sender AS Afx_ICoreWebView2 PTR, BYVAL args AS Afx_ICoreWebView2NavigationCompletedEventArgs PTR) AS HRESULT
   DECLARE CONSTRUCTOR (BYVAL pWebView2 AS CWebView2 PTR)
   DECLARE DESTRUCTOR

   m_pWebView2 AS CWebView2 PTR
   m_token AS EventRegistrationToken

END TYPE
' ########################################################################################

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
   DIM hWin AS HWND = pWindow.Create(NULL, "WebView2 - Display WBEM video", @WndProc)
   ' // Set its client size
   pWindow.SetClientSize(640, 420)
   ' // Center the window
   pWindow.Center

   ' // Adds a label
   DIM hLabel AS HWND = pWindow.AddControl("Label", hWin, IDC_LABEL, "", 20, 20, 600, 380)
   ' // Anchors the label to the height and width of the main window
   pWindow.AnchorControl(hLabel, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Script to load the video
   ' // Note: YouTube videos give error 153
   DIM s AS STRING
   s += "<!DOCTYPE html>"
   s += "<html>"
   s += "<body scroll='auto'>"
   s += "<center>"
   s += "<video width='540' height='340' controls>"
   s += "  <source src='http://www.bokowsky.net/de/knowledge-base/video/videos/big_buck_bunny_240p.webm' type='video/webm'>"
   s += "</video>"
   s += "<center>"
   s += "</body>"
   s += "</html>"
   
   ' // Use the same folder for the WebView2 files
   ' // Here we are using a subfolder in the temporary folder
   DIM dwsUserDataFolder AS DWSTRING = AfxGetTempPath & "AfxNovaWebView2"
   ' // Create an instance of WebView
   DIM pWebView2 AS CWebView2 = CWebView2(hLabel, dwsUserDataFolder)
   ' // Wait until is ready
   IF pWebView2.IsReady THEN
      ' // Navigate to a web page
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
         
         SELECT CASE GET_WM_COMMAND_ID(wParam, lParam)

            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
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
