' ########################################################################################
' Microsoft Windows
' Contents: Draw polygon
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CGraphCtx.inc"
USING AfxNova

CONST IDC_GRCTX = 1001

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG

   END wWinMain(GetModuleHandleW(NULL), NULL, wCOMMAND(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Draws a polygon
' ========================================================================================
SUB OpenGL_DrawPolygon (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)

   ' // Specify clear values for the color buffers
   glClearColor 0.0, 0.0, 0.0, 0.0
   ' // Specify the clear value for the depth buffer
   glClearDepth 1.0
   ' // Specify the value used for depth-buffer comparisons
   glDepthFunc GL_LESS
   ' // Enable depth comparisons and update the depth buffer
   glEnable GL_DEPTH_TEST
   ' // Select smooth shading
   glShadeModel GL_SMOOTH

   ' // Prevent divide by zero making height equal one
   IF nHeight = 0 THEN nHeight = 1
   ' // Reset the current viewport
   glViewport 0, 0, nWidth, nHeight
   ' // Select the projection matrix
   glMatrixMode GL_PROJECTION
   ' // Reset the projection matrix
   glLoadIdentity
   ' // Calculate the aspect ratio of the window
   glOrtho 0, nWidth, nHeight, 0, -1, 1
   ' // Select the model view matrix
   glMatrixMode GL_MODELVIEW
   ' // Reset the model view matrix
   glLoadIdentity

   ' // Clear the screen buffer
   glClear GL_COLOR_BUFFER_BIT OR GL_DEPTH_BUFFER_BIT

   ' ============================================================
   ' Bounding box of the polygon
   ' ============================================================
   DIM minX AS SINGLE = 10
   DIM maxX AS SINGLE = 120
   DIM minY AS SINGLE = 10
   DIM maxY AS SINGLE = 120

   DIM polyW AS SINGLE = maxX - minX
   DIM polyH AS SINGLE = maxY - minY

   ' ============================================================
   ' Scale to occupy 80% of the area
   ' ============================================================
   DIM scaleX AS SINGLE = (nWidth  * 0.80) / polyW
   DIM scaleY AS SINGLE = (nHeight * 0.80) / polyH
   DIM scale  AS SINGLE = IIF(scaleX < scaleY, scaleX, scaleY)

   ' ============================================================
   ' Center of the area
   ' ============================================================
   DIM centerX AS SINGLE = nWidth  / 2
   DIM centerY AS SINGLE = nHeight / 2

   ' ============================================================
   ' Center of the original polygon
   ' ============================================================
   DIM polyCX AS SINGLE = (minX + maxX) / 2
   DIM polyCY AS SINGLE = (minY + maxY) / 2

   ' ============================================================
   ' Transformation
   ' ============================================================
   glMatrixMode GL_MODELVIEW
   glLoadIdentity

   ' 1. Move to the center of the area
   glTranslatef centerX, centerY, 0

   ' 2. Scale
   glScalef scale, scale, 1

   ' 3. Move the polygon so that its center coincides with the origin
   glTranslatef -polyCX, -polyCY, 0

   ' ============================================================
   ' Draw the polygon
   ' ============================================================
   glBegin GL_POLYGON
      glVertex2f  10,  10
      glVertex2f 100,  20
      glVertex2f 120,  80
      glVertex2f  60, 120
      glVertex2f  20,  90
   glEnd

   ' // Required: Force execution of GL commands in finite time
   glFlush

END SUB
' =======================================================================================
SUB GL_PolygonBasic()
    glBegin GL_POLYGON
        glVertex2f  10,  10
        glVertex2f 100,  20
        glVertex2f 120,  80
        glVertex2f  60, 120
        glVertex2f  20,  90
    glEnd
END SUB

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
   pWindow.Create(NULL, "Draw polygon", @WndProc)
   pWindow.SetClientSize(400, 250)
   pWindow.Center

   ' // Add a graphic control with OPENGL enabled
   DIM nWidth AS LONG = pWindow.ClientWidth
   DIM nHeight AS LONG = pWindow.ClientHeight
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "OPENGL", 0, 0, nWidth, nHeight)
   ' // Optional: Make the control stretchable
   pGraphCtx.Stretchable = TRUE
   ' // Anchor the control
   pWindow.AnchorControl(IDC_GRCTX, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Make current the rendering context
   pGraphCtx.MakeCurrent

   ' // Render the scene
   DIM nBufferWidth AS LONG = pGraphCtx.GetVirtualBufferWidth
   DIM nBufferHeight AS LONG = pGraphCtx.GetVirtualBufferHeight
   OpenGL_DrawPolygon(nBufferWidth, nBufferHeight)

   ' // Dispatch Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window callback procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

    	CASE WM_DESTROY
         ' // End the application
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================