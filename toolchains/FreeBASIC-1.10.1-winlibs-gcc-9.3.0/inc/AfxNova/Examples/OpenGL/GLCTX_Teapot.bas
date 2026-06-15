' ########################################################################################
' Microsoft Windows
' File: GLCTX_Teapot.bas
' Contents: Graphic Control OpenGL - Teapot
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxGlut.inc"
#INCLUDE ONCE "AfxNova/CGraphCtx.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declarations
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
DECLARE FUNCTION GraphCtx_SubclassProc ( _
   BYVAL hwnd   AS HWND, _                 ' // Control window handle
   BYVAL uMsg   AS UINT, _                 ' // Type of message
   BYVAL wParam AS WPARAM, _               ' // First message parameter
   BYVAL lParam AS LPARAM, _               ' // Second message parameter
   BYVAL uIdSubclass AS UINT_PTR, _        ' // The subclass ID
   BYVAL dwRefData AS DWORD_PTR _          ' // Pointer to reference data
   ) AS LRESULT

CONST GL_WINDOWWIDTH   = 600                 ' Window width
CONST GL_WINDOWHEIGHT  = 400                 ' Window height
CONST GL_WindowCaption = "OpenGL - Teapot"   ' Window caption
CONST IDC_GRCTX = 1001

' =======================================================================================
' OpenGL class
' =======================================================================================
TYPE CtxOgl

   Private:
      m_pGraphCtx AS CGraphCtx PTR

   Public:
      DECLARE CONSTRUCTOR (BYVAL pGraphCtx AS CGraphCtx PTR)
      DECLARE DESTRUCTOR
      DECLARE SUB SetupScene
      DECLARE SUB ResizeScene
      DECLARE SUB RenderScene

END TYPE
' =======================================================================================

' ========================================================================================
' COGL constructor
' ========================================================================================
CONSTRUCTOR CtxOgl (BYVAL pGraphCtx AS CGraphCtx PTR)
   m_pGraphCtx = pGraphCtx
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' COGL Destructor
' ========================================================================================
DESTRUCTOR CtxOgl
END DESTRUCTOR
' ========================================================================================

' =======================================================================================
' All the setup goes here
' =======================================================================================
SUB CtxOgl.SetupScene

   glEnable(GL_LIGHTING)
   glEnable(GL_LIGHT0)
   glEnable(GL_DEPTH_TEST)

END SUB
' =======================================================================================

' =======================================================================================
SUB CtxOgl.ResizeScene

   ' // Get the dimensions of the control
   IF m_pGraphCtx = NULL THEN EXIT SUB
   DIM nWidth AS LONG = AfxGetWindowWidth(m_pGraphCtx->hWindow)
   DIM nHeight AS LONG = AfxGetWindowHeight(m_pGraphCtx->hWindow)
   ' // Prevent divide by zero making height equal one
   IF nHeight = 0 THEN nHeight = 1
   ' // Reset the current viewport
   glViewport 0, 0, nWidth, nHeight
   ' // Select the projection matrix
   glMatrixMode GL_PROJECTION
   ' // Reset the projection matrix
   glLoadIdentity
   ' // Calculate the aspect ratio of the window
   gluPerspective 45.0, nWidth / nHeight, 0.1, 100.0
   ' // Select the model view matrix
   glMatrixMode GL_MODELVIEW
   ' // Reset the model view matrix
   glLoadIdentity

END SUB
' =======================================================================================

' =======================================================================================
SUB CtxOgl.RenderScene

   ' // Clear the screen buffer
   glClear GL_COLOR_BUFFER_BIT OR GL_DEPTH_BUFFER_BIT
   glPushMatrix
   gluLookAt(0,2.5,-7, 0,0,0, 0,1,0)
   AfxGlutSolidTeapot(2.5)
   glPopMatrix
   glFlush

END SUB
' =======================================================================================

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
   ' // Create the window
   DIM hwndMain AS HWND = pWindow.Create(NULL, GL_WindowCaption, @WndProc)
   ' // Don't erase the background
   ' // Use a black brush
   pWindow.Brush = CreateSolidBrush(BGR(255, 255, 255))
   ' // Sizes the window by setting the wanted width and height of its client area
   pWindow.SetClientSize(GL_WINDOWWIDTH, GL_WINDOWHEIGHT)
   ' // Centers the window
   pWindow.Center

   ' // Add a subclassed graphic control with OPENGL enabled
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "OPENGL", _
       0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Resizable = TRUE
   ' // Set the focus in the control
   SetFocus pGraphCtx.hWindow
   ' // Set the timer (using a timer to trigger redrawing allows a smoother rendering)
   SetTimer(pGraphCtx.hWindow, 1, 0, NULL)
   ' // Anchor the control
   pWindow.AnchorControl(IDC_GRCTX, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Create an instance of the CtxOgl class
   DIM pCtxOgl AS CtxOgl = @pGraphCtx
   ' // Subclass the graphic control
   SetWindowSubclass pGraphCtx.hWindow, CAST(SUBCLASSPROC, @GraphCtx_SubclassProc), IDC_GRCTX, CAST(DWORD_PTR, @pCtxOgl)
   ' // Setup the OpenGL scene
   pCtxOgl.SetupScene
   ' // Resize the OpenGL scene
   pCtxOgl.ResizeScene
   ' // Render the OpenGL scene
   pCtxOgl.RenderScene

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

      CASE WM_SYSCOMMAND
         ' // Disable the Windows screensaver
         IF (wParam AND &hFFF0) = SC_SCREENSAVE THEN RETURN 0
         ' // Close the window
         IF (wParam AND &hFFF0) = SC_CLOSE THEN
            SendMessageW hwnd, WM_CLOSE, 0, 0
            RETURN 0
         END IF

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
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
' Processes messages for the subclassed graphic control
' ========================================================================================
FUNCTION GraphCtx_SubclassProc ( _
   BYVAL hwnd   AS HWND, _                 ' // Control window handle
   BYVAL uMsg   AS UINT, _                 ' // Type of message
   BYVAL wParam AS WPARAM, _               ' // First message parameter
   BYVAL lParam AS LPARAM, _               ' // Second message parameter
   BYVAL uIdSubclass AS UINT_PTR, _        ' // The subclass ID
   BYVAL dwRefData AS DWORD_PTR _          ' // Pointer to reference data
   ) AS LRESULT

   SELECT CASE uMsg

      CASE WM_GETDLGCODE
         ' // All keyboard input
         FUNCTION = DLGC_WANTALLKEYS
         EXIT FUNCTION

      CASE WM_TIMER
         ' // Render the scene
         DIM pCtxOgl AS CtxOgl PTR = cast(CtxOgl PTR, dwRefData)
         IF pCtxOgl THEN pCtxOgl->RenderScene
         EXIT FUNCTION

      CASE WM_SIZE
         ' // First perform the default action
         DefSubclassProc(hwnd, uMsg, wParam, lParam)
         ' // Check if the graphic contol is resizable
         DIM bResizable AS BOOLEAN =  AfxCGraphCtxPtr(hwnd)->Resizable
         ' // If it is resizable, we need to recreate the scene
         ' // because the rendering context has changed
         IF bResizable THEN
            DIM pCtxOgl AS CtxOgl PTR = cast(CtxOgl PTR, dwRefData)
            pCtxOgl->SetUpScene
            pCtxOgl->ResizeScene
            pCtxOgl->RenderScene
         END IF

      EXIT FUNCTION

      CASE WM_DESTROY
         ' // Kill the timer
         KillTimer(hwnd, 1)
         ' // REQUIRED: Remove control subclassing
         RemoveWindowSubclass hwnd, @GraphCtx_SubclassProc, uIdSubclass

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefSubclassProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
