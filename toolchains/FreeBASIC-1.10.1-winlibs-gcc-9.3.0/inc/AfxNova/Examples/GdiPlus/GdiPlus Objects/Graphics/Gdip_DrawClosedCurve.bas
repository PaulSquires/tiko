' ########################################################################################
' Microsoft Windows
' File: Gdip_DrawClosedCurve.bas
' Contents: GDI+ Flat API - GdipDrawClosedCurve example
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
' The following example draws a closed cardinal spline.
' ========================================================================================
SUB Example_DrawClosedCurve (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a green Pen
   DIM greenPen AS GdiPlusPen = GdiPlusPen(ARGB_LIGHTGREEN, 1)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200,  50)
   DIM point3 AS GpPointF = (400,  10)
   DIM point4 AS GpPointF = (500, 100)
   DIM point5 AS GpPointF = (600, 200)
   DIM point6 AS GpPointF = (700, 400)
   DIM point7 AS GpPointF = (500, 500)

   DIM curvePoints(6) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4
   curvePoints(4) = point5
   curvePoints(5) = point6
   curvePoints(6) = point7

   ' // Draw the closed curve
   GdipDrawClosedCurve2(graphics, greenPen, @curvePoints(0), 7, 1.0)

   ' // Create the brush
   DIM redBrush AS GdiPlusSolidBrush = ARGB_RED

   ' //Draw the points in the curve
   GdipFillEllipse(graphics, redBrush, 95, 95, 10, 10)
   GdipFillEllipse(graphics, redBrush, 495, 95, 10, 10)
   GdipFillEllipse(graphics, redBrush, 495, 495, 10, 10)
   GdipFillEllipse(graphics, redBrush, 195, 45, 10, 10)
   GdipFillEllipse(graphics, redBrush, 395, 5, 10, 10)
   GdipFillEllipse(graphics, redBrush, 595, 195, 10, 10)
   GdipFillEllipse(graphics, redBrush, 695, 395, 10, 10)

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
   pWindow.Create(NULL, "GDI+ GdipDrawClosedCurve", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(800, 550)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   Example_DrawClosedCurve(pGraphCtx.GetMemDc)

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
