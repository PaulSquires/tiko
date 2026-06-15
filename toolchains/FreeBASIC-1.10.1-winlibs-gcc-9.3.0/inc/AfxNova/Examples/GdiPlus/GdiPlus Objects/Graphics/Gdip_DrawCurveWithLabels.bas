' ########################################################################################
' Microsoft Windows
' File: Gdip_DrawlosedCurveWithLabels.bas
' Contents: GDI+ Flat API - GdipDrawlosedCurveWithLabels example
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
' The following example draws a cardinal spline and adds labels to each point.
' ========================================================================================
SUB Example_DrawCurveWithLabels (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a green Pen
   DIM greenPen AS GdiPlusPen = GdiPlusPen(ARGB_LIGHTGREEN, 3)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200, 50)
   DIM point3 AS GpPointF = (400, 30)
   DIM point4 AS GpPointF = (500, 100)

   DIM curvePoints(3) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4

   ' // Specify offset, number of segments to draw, and tension.
   DIM offset AS LONG = 1
   DIM segments AS LONG = 2
   DIM tension AS SINGLE = 1.0

   ' // Draw the curve
   GdipDrawCurve(graphics, greenPen, @curvePoints(0), 4)

   ' // Create the brush
   DIM redBrush AS GdiPlusSolidBrush = ARGB_RED

   ' // Draw the points in the curve
   GdipFillEllipse(*graphics, *redBrush, 95, 95, 10, 10)
   GdipFillEllipse(*graphics, *redBrush, 195, 45, 10, 10)
   GdipFillEllipse(*graphics, *redBrush, 395, 25, 10, 10)
   GdipFillEllipse(*graphics, *redBrush, 495, 95, 10, 10)

   ' // Create a font
   DIM font AS GdiPlusFont = GdiPlusFont("Arial", 12, TRUE)

   ' // Create a brush
   DIM labelBrush AS GdiPlusSolidBrush = ARGB_BLACK

   ' // Label each point
   DIM layoutRect AS GpRectF
   DIM label AS WSTRING * 32
   FOR i AS LONG = 0 TO 3
      label = "P" & STR(i)
      layoutRect.x = curvePoints(i).x + 10
      layoutRect.y = curvePoints(i).y - 10
      layoutRect.Width = 50
      layoutRect.Height = 20
      GdipDrawString(graphics, @label, -1, font, @layoutRect, NULL, labelBrush)
   NEXT

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
   pWindow.Create(NULL, "GDI+ GdipDrawlosedCurveWithLabels", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(600, 250)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Get the memory device context of the graphic control
   DIM hdc AS HDC = pGraphCtx.GetMemDc

   ' // Draw the graphics
   Example_DrawCurveWithLabels(pGraphCtx.GetMemDc)

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
