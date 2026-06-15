' ########################################################################################
' Microsoft Windows
' Contents: GDI+ Draw closed curve
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
' Closed curve with blue crystal effect (Swiss Blue)
' ========================================================================================
SUB Example_DrawClosedCurve (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Array of points
   DIM pts(4) AS GpPointF = { _
      (140, 60), _
      (260, 40), _
      (300, 150), _
      (200, 210), _
      (120, 140) _
   }

   ' // Create a path
   DIM path AS GdiPlusGraphicsPath = FillModeAlternate

   ' // Add curve
   GdipAddPathCurve(path, @pts(0), 5)

   ' // Close the current figure of this path
   GdipClosePathFigure(path)

   ' // Create a gradient brush
   DIM pgb AS GdiPlusPathGradientBrush = *path

   ' // Displaced center
   DIM center AS GpPointF = (200, 80)
   GdipSetPathGradientCenterPoint(pgb, @center)

   ' // Light blue center color
   GdipSetPathGradientCenterColor(pgb, GDIP_ARGB(180, 180, 220, 255))

   ' // Dark blue border
   DIM surround(0) AS ARGB = {GDIP_ARGB(120, 0, 40, 90)}
   DIM count AS UINT = 1
   GdipSetPathGradientSurroundColorsWithCount(pgb, @surround(0), @count)

   ' // Draw the path
   GdipFillPath(graphics, pgb, path)

   ' // Upper reflection
   DIM hpath AS GdiPlusGraphicsPath = FillModeAlternate
   GdipAddPathPie(hpath, 160, 50, 80, 40, 200, 140)

   ' // Create a brush
   DIM hbrush AS GdiPlusSolidBrush = GDIP_ARGB(80, 255, 255, 255)
   GdipFillPath(graphics, hbrush, hpath)

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
   pWindow.Create(NULL, "GDI+ Draw closed curve", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 250)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_FLORALWHITE
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
