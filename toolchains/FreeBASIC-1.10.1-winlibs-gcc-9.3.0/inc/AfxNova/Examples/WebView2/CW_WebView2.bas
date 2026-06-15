' ########################################################################################
' Microsoft Windows
' File: CW_WebView2.bas
' Contents: WebView2 example
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
   DIM hWin AS HWND = pWindow.Create(NULL, "WebView2", @WndProc)
   ' // Set its client size
   pWindow.SetClientSize(1050, 500)
   ' // Center the window
   pWindow.Center

   ' // Use the same folder for the WebView2 files
   ' // Here we are using a subfolder in the temporary folder
   DIM dwsUserDataFolder AS DWSTRING = AfxGetTempPath & "AfxNovaWebView2"
   ' // Create an instance of WebView
   DIM pWebView2 AS CWebView2 = CWebView2(hWin, dwsUserDataFolder)
   ' // Wait until is ready
   IF pWebView2.IsReady THEN
      ' // Set a navigation handler
      DIM pEnv AS CWebView2NavigationCompletedEventHandlerImpl PTR
      pEnv = NEW CWebView2NavigationCompletedEventHandlerImpl(@pWebView2)
      ' // Set an event handler for NewWindow
      DIM pNewWindowHandler AS CWebView2NewWindowRequestedEventHandlerInternal PTR
      pNewWindowHandler = NEW CWebView2NewWindowRequestedEventHandlerInternal(@pWebView2, FALSE)
      ' // Navigate to a web page
      pWebView2.Navigate("https://www.planetsquires.com/protect/forum/index.php")
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


' ########################################################################################
' Implementation of the CWebView2NavigationCompletedEventHandlerImpl class
' ########################################################################################

' ========================================================================================
CONSTRUCTOR CWebView2NavigationCompletedEventHandlerImpl (BYVAL pWebView2 AS CWebView2 PTR)
   CWV2_DP("pWebView2: " & WSTR(pWebView2))
   IF pWebView2 THEN
      m_pWebView2 = pWebView2
      pWebView2->AddNavigationCompleted(cast(ANY PTR, @this), @m_token)
   END IF
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
DESTRUCTOR CWebView2NavigationCompletedEventHandlerImpl
   CWV2_DP("")
   IF m_pWebView2 THEN m_pWebView2->RemoveNavigationCompleted(m_token)
END DESTRUCTOR
' ========================================================================================
' ========================================================================================
FUNCTION CWebView2NavigationCompletedEventHandlerImpl.Invoke (BYVAL sender AS Afx_ICoreWebView2 PTR, BYVAL args AS Afx_ICoreWebView2NavigationCompletedEventArgs PTR) AS HRESULT
   CWV2_DP("Navigation completed")
   DIM IsSuccess AS WINBOOL   
   IF args THEN args->get_IsSuccess(@IsSuccess)
   CWV2_DP("IsSuccess: " & WSTR(IsSuccess))
   DIM WebErrorStatus AS COREWEBVIEW2_WEB_ERROR_STATUS
   IF args THEN args->get_WebErrorStatus(@WebErrorStatus)
   CWV2_DP("WebErrorStatus: " & WSTR(WebErrorStatus))
   DIM NavigationId AS UINT64
   IF args THEN args->get_NavigationId(@NavigationId)
   CWV2_DP("NavigationId: " & WSTR(NavigationId))
   RETURN S_OK
END FUNCTION
' ========================================================================================
