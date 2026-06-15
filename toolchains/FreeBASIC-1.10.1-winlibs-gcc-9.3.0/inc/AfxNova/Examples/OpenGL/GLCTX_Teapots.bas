' ########################################################################################
' Microsoft Windows
' File: GLCTX_Teapots
' Contents: CWindow OpenGL - Teapots
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 1993-1997, Silicon Graphics, Inc.
' Adapted in 2026 by José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxGlut.inc"
#INCLUDE ONCE "AfxNova/CGraphCtx.inc"
USING AfxNova

CONST GL_WINDOWWIDTH   = 600                  ' Window width
CONST GL_WINDOWHEIGHT  = 400                  ' Window height
CONST GL_WindowCaption = "OpenGL - Teapots"   ' Window caption
CONST IDC_GRCTX = 1001

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

' =======================================================================================
' OpenGL class
' =======================================================================================
TYPE CtxOgl

   Private:
      m_pGraphCtx AS CGraphCtx PTR

      teapotList AS GLUint
      ambient(3) AS SINGLE = { 0.0, 0.0, 0.0, 1.0 }
      diffuse(3) AS SINGLE = { 1.0, 1.0, 1.0, 1.0 }
      specular(3) AS SINGLE = { 1.0, 1.0, 1.0, 1.0 }
      position(3) AS SINGLE = { 0.0, 3.0, 3.0, 0.0 }
      lmodel_ambient(3) AS SINGLE = { 0.2, 0.2, 0.2, 1.0 }
      local_view(0) AS SINGLE = { 0.0 }

   Public:
      DECLARE CONSTRUCTOR (BYVAL pGraphCtx AS CGraphCtx PTR)
      DECLARE DESTRUCTOR
      DECLARE SUB SetupScene
      DECLARE SUB ResizeScene
      DECLARE SUB RenderScene
      DECLARE SUB renderTeapot (BYVAL x AS SINGLE, BYVAL y AS SINGLE, _
         BYVAL ambr AS SINGLE, BYVAL ambg AS SINGLE, BYVAL ambb AS SINGLE, _
         BYVAL difr AS SINGLE, BYVAL difg AS SINGLE, BYVAL difb AS SINGLE, _
         BYVAL specr AS SINGLE, BYVAL specg AS SINGLE, BYVAL specb AS SINGLE, BYVAL shine AS SINGLE)

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

   glLightfv GL_LIGHT0, GL_AMBIENT, @ambient(0)
   glLightfv GL_LIGHT0, GL_DIFFUSE, @diffuse(0)
   glLightfv GL_LIGHT0, GL_POSITION, @position(0)
   glLightModelfv GL_LIGHT_MODEL_AMBIENT, @lmodel_ambient(0)
   glLightModelfv GL_LIGHT_MODEL_LOCAL_VIEWER, @local_view(0)

   glFrontFace GL_CW
   glEnable GL_LIGHTING
   glEnable GL_LIGHT0
   glEnable GL_AUTO_NORMAL
   glEnable GL_NORMALIZE
   glEnable GL_DEPTH_TEST
   ' /*  be efficient--make teapot display list  */
   teapotList = glGenLists(1)
   glNewList teapotList, GL_COMPILE
   AfxGlutSolidTeapot 1.0
   glEndList

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
   IF nWidth <= nHeight THEN
      glOrtho 0.0, 16.0, 0.0, 16.0 * nHeight / nWidth, -10.0, 10.0
   ELSE
      glOrtho 0.0, 16.0 * nWidth / nHeight, 0.0, 16.0, -10.0, 10.0
   END IF
   ' // Select the model view matrix
   glMatrixMode GL_MODELVIEW

END SUB
' =======================================================================================

' =======================================================================================
' Move object into position. Use 3rd through 12th
' parameters to specify the material property. Draw a teapot.
' =======================================================================================
SUB CtxOgl.renderTeapot (BYVAL x AS SINGLE, BYVAL y AS SINGLE, _
   BYVAL ambr AS SINGLE, BYVAL ambg AS SINGLE, BYVAL ambb AS SINGLE, _
   BYVAL difr AS SINGLE, BYVAL difg AS SINGLE, BYVAL difb AS SINGLE, _
   BYVAL specr AS SINGLE, BYVAL specg AS SINGLE, BYVAL specb AS SINGLE, BYVAL shine AS SINGLE)

   glPushMatrix
   glTranslatef x, y, 0.0
   DIM matx(3) AS SINGLE
   matx(0) = ambr : matx(1) = ambg : matx(2) = ambb : matx(3) = 1.0
   glMaterialfv GL_FRONT, GL_AMBIENT, @matx(0)
   matx (0) = difr : matx(1) = difg : matx(2) = difb
   glMaterialfv GL_FRONT, GL_DIFFUSE, @matx(0)
   matx(0) = specr : matx(1) = specg : matx(2) = specb
   glMaterialfv GL_FRONT, GL_SPECULAR, @matx(0)
   glMaterialf GL_FRONT, GL_SHININESS, shine * 128.0
   glCallList teapotList
   glPopMatrix

END SUB
' =======================================================================================

' =======================================================================================
SUB CtxOgl.RenderScene

   ' // Clear the screen buffer
   glClear GL_COLOR_BUFFER_BIT OR GL_DEPTH_BUFFER_BIT
   ' // Draw the teapots
   this.renderTeapot(2.0, 17.0, 0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6)
   this.renderTeapot(2.0, 14.0, 0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, 0.316228, 0.316228, 0.316228, 0.1)
   this.renderTeapot(2.0, 11.0, 0.05375, 0.05, 0.06625, 0.18275, 0.17, 0.22525, 0.332741, 0.328634, 0.346435, 0.3)
   this.renderTeapot(2.0, 8.0, 0.25, 0.20725, 0.20725, 1, 0.829, 0.829, 0.296648, 0.296648, 0.296648, 0.088)
   this.renderTeapot(2.0, 5.0, 0.1745, 0.01175, 0.01175, 0.61424, 0.04136, 0.04136, 0.727811, 0.626959, 0.626959, 0.6)
   this.renderTeapot(2.0, 2.0, 0.1, 0.18725, 0.1745, 0.396, 0.74151, 0.69102, 0.297254, 0.30829, 0.306678, 0.1)
   this.renderTeapot(6.0, 17.0, 0.329412, 0.223529, 0.027451, 0.780392, 0.568627, 0.113725, 0.992157, 0.941176, 0.807843, 0.21794872)
   this.renderTeapot(6.0, 14.0, 0.2125, 0.1275, 0.054, 0.714, 0.4284, 0.18144, 0.393548, 0.271906, 0.166721, 0.2)
   this.renderTeapot(6.0, 11.0, 0.25, 0.25, 0.25, 0.4, 0.4, 0.4, 0.774597, 0.774597, 0.774597, 0.6)
   this.renderTeapot(6.0, 8.0, 0.19125, 0.0735, 0.0225, 0.7038, 0.27048, 0.0828, 0.256777, 0.137622, 0.086014, 0.1)
   this.renderTeapot(6.0, 5.0, 0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4)
   this.renderTeapot(6.0, 2.0, 0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273, 0.4)
   this.renderTeapot(10.0, 17.0, 0.0, 0.0, 0.0, 0.01, 0.01, 0.01, 0.50, 0.50, 0.50, .25)
   this.renderTeapot(10.0, 14.0, 0.0, 0.1, 0.06, 0.0, 0.50980392, 0.50980392, 0.50196078, 0.50196078, 0.50196078, .25)
   this.renderTeapot(10.0, 11.0, 0.0, 0.0, 0.0, 0.1, 0.35, 0.1, 0.45, 0.55, 0.45, .25)
   this.renderTeapot(10.0, 8.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.7, 0.6, 0.6, .25)
   this.renderTeapot(10.0, 5.0, 0.0, 0.0, 0.0, 0.55, 0.55, 0.55, 0.70, 0.70, 0.70, .25)
   this.renderTeapot(10.0, 2.0, 0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.60, 0.60, 0.50, .25)
   this.renderTeapot(14.0, 17.0, 0.02, 0.02, 0.02, 0.01, 0.01, 0.01, 0.4, 0.4, 0.4, .078125)
   this.renderTeapot(14.0, 14.0, 0.0, 0.05, 0.05, 0.4, 0.5, 0.5, 0.04, 0.7, 0.7, .078125)
   this.renderTeapot(14.0, 11.0, 0.0, 0.05, 0.0, 0.4, 0.5, 0.4, 0.04, 0.7, 0.04, .078125)
   this.renderTeapot(14.0, 8.0, 0.05, 0.0, 0.0, 0.5, 0.4, 0.4, 0.7, 0.04, 0.04, .078125)
   this.renderTeapot(14.0, 5.0, 0.05, 0.05, 0.05, 0.5, 0.5, 0.5, 0.7, 0.7, 0.7, .078125)
   this.renderTeapot(14.0, 2.0, 0.05, 0.05, 0.0, 0.5, 0.5, 0.4, 0.7, 0.7, 0.04, .078125)
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
   DIM pWindow AS CWindow
   ' -or- DIM pWindow AS CWindow = "MyClassName" (use the name that you wish)
   ' // Create the window
   DIM hwndMain AS HWND = pWindow.Create(NULL, GL_WindowCaption, @WndProc)
   ' // Don't erase the background
   pWindow.ClassStyle = CS_DBLCLKS
   ' // Use a black brush
   pWindow.Brush = CreateSolidBrush(BGR(255, 255, 255))
   ' // Sizes the window by setting the wanted width and height of its client area
   pWindow.SetClientSize(GL_WINDOWWIDTH, GL_WINDOWHEIGHT)
   ' // Centers the window
   pWindow.Center

   ' // Add a subclassed graphic control with OPENGL enabled
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "OPENGL", _
       0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
'   pGraphCtx.Stretchable = TRUE
   pGraphCtx.Resizable = TRUE
   ' // Set the timer (using a timer to trigger redrawing allows a smoother rendering)
   SetTimer(pGraphCtx.hWindow, 1, 0, NULL)

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

   ' // Dispatch Windows events
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
         IF (wParam AND &hFFF0) = SC_SCREENSAVE THEN EXIT FUNCTION
         ' // Close the window
         IF (wParam AND &hFFF0) = SC_CLOSE THEN
            SendMessageW hwnd, WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE WM_COMMAND
         SELECT CASE GET_WM_COMMAND_ID(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_SIZE
         IF wParam <> SIZE_MINIMIZED THEN
            DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
            ' // If the window isn't minimized, resize the graphic control
            IF pWindow THEN pWindow->MoveWindow GetDlgItem(hwnd, IDC_GRCTX), _
               0, 0, pWindow->ClientWidth, pWindow->ClientHeight, CTRUE
         END IF

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Processes messages for the subclassed Button window.
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

      CASE WM_LBUTTONDOWN
         MessageBoxW(GetParent(hwnd), "Click", "FreeBasic", MB_OK)
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
