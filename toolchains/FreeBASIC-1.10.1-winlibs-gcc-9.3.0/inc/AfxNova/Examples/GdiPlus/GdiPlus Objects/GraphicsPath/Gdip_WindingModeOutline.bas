' ########################################################################################
' Microsoft Windows
' File: Gdip_WindingModeOutline.bas
' Contents: GDI+ Flat API - GdipWindingModeOutline example
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
' The following example creates a GraphicsPath object and calls the GdiAddPathClosedCurve
' method to add a closed cardinal spline to the path. The code calls the GdipWidenPath function
' to widen the path and then draws the path. Next, the code calls the GdipWindingModeOutline
' function The code calls the GdipTranslateWorldTransform function so that the outlined path
' drawn by the subsequent call to GdipDrawPath sits to the right of the first path.
' ========================================================================================
SUB Example_WindingModeOutline (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a path
   DIM path AS GdiPlusGraphicsPath = FillModeAlternate

   ' // Create the pens.
   DIM bluePen AS GdiPlusPen = GdiPlusPen(ARGB_BLUE, 1, UnitWorld)
   DIM greenPen AS GdiPlusPen = GdiPlusPen(ARGB_LIGHTGREEN, 10, UnitWorld)

   ' // Add a closed curve
   DIM pts(3) AS GpPointF
   pts(0).x = 20  : pts(0).y = 20
   pts(1).x = 160 : pts(1).y = 100
   pts(2).x = 140 : pts(2).y = 60
   pts(3).x = 60  : pts(3).y = 100
   GdipAddPathClosedCurve(path, @pts(0), 4)

   GdipWidenPath(path, greenPen, NULL, FlatnessDefault)
   GdipDrawPath(graphics, bluePen, path)
   GdipWindingModeOutline(path, NULL, FlatnessDefault)
   GdipTranslateWorldTransform(graphics, 180, 0, MatrixOrderPrepend)
   GdipDrawPath(graphics, bluePen, path)

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
   pWindow.Create(NULL, "GDI+ GdipWindingModeOutline", @WndProc)
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
   Example_WindingModeOutline(pGraphCtx.GetMemDc)

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
