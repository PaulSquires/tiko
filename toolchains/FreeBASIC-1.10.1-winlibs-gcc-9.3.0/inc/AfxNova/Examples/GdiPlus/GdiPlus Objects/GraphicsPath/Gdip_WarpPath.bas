' ########################################################################################
' Microsoft Windows
' File: Gdip_WarpPath.bas
' Contents: GDI+ Flat API - GdipWarpPath example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define _WIN32_WINNT &h0602
'#define _GDIP_DEBUG_ 1
#INCLUDE ONCE "AfxNova/AfxGdipObjects.inc"
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
' The following example creates a GraphicsPath object and adds a closed figure to the path.
' The code defines a warp transformation by specifying a source rectangle and an array of
' four destination points. The source rectangle and destination points are passed to the
' GdipWarpPath function. The code draws the path twice: once before it has been warped and
' once after it has been warped.
' ========================================================================================
SUB Example_WarpPath (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a path
   DIM path AS GdiPlusGraphicsPath = FillModeAlternate

   DIM pts(7) AS GpPointF
   pts(0).x = 20 : pts(0).y = 60
   pts(1).x = 30 : pts(1).y = 90
   pts(2).x = 15 : pts(2).y = 110
   pts(3).x = 15 : pts(3).y = 145
   pts(4).x = 55 : pts(4).y = 145
   pts(5).x = 55 : pts(5).y = 110
   pts(6).x = 40 : pts(6).y = 90
   pts(7).x = 50 : pts(7).y = 60

   GdipAddPathLine2(path, @pts(0), 8)
   GdipClosePathFigure(path)

   ' // Draw the path before applying a warp transformation.
   DIM bluePen AS GdiPlusPen = GdiPlusPen(ARGB_BLUE, 1, UnitWorld)
   GdipDrawPath(graphics, bluePen, path)

   ' // Define a warp transformation, and warp the path.
   DIM srcRect AS GpRectF = (10, 50, 50, 100)

   ' // Destinations points
   DIM destPts(3) AS GpPointF
   destPts(0).x = 220 : destPts(0).y = 10
   destPts(1).x = 280 : destPts(1).y = 10
   destPts(2).x = 100 : destPts(2).y = 150
   destPts(3).x = 400 : destPts(3).y = 150

   ' // Warp the path
   GdipWarpPath(path, NULL, @destPts(0), 4, srcRect.x, srcRect.y, srcRect.Width, srcRect.Height, WarpModePerspective, FlatnessDefault)

   ' // Draw the warped path.
   GdipDrawPath(graphics, bluePen, path)

   ' // Draw the source rectangle and the destination polygon.
   DIM blackPen AS GdiPlusPen = GdiPlusPen(ARGB_BLACK, 1, UnitWorld)
   GdipDrawRectangle(graphics, blackPen, srcRect.x, srcRect.y, srcRect.Width, srcRect.Height)
   GdipDrawLine(graphics, blackPen, destpts(0).x, destPts(0).y, destPts(1).x, destPts(1).y)
   GdipDrawLine(graphics, blackPen, destpts(0).x, destPts(0).y, destPts(2).x, destPts(2).y)
   GdipDrawLine(graphics, blackPen, destpts(1).x, destPts(1).y, destPts(3).x, destPts(3).y)
   GdipDrawLine(graphics, blackPen, destpts(2).x, destPts(2).y, destPts(3).x, destPts(3).y)

END SUB
' ========================================================================================

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
   DIM pWindow AS CWindow = "MyClassName"
   pWindow.Create(NULL, "GDI+ GdipWarpPath", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(410, 250)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   Example_WarpPath(pGraphCtx.GetMemDc)

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

      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  RETURN 0
               END IF
         END SELECT

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
