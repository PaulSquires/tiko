' ########################################################################################
' Microsoft Windows
' File: Gdip_CreatePathGradientFromPath.bas
' Contents: GDI+ Flat API - GdipCreatePathGradientFromPath example
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
' The following example draws a star-shaped GraphicsPath.
' Creates a star-shaped GraphicsPath and fills it using a PathGradientBrush constructed
' from that path. The gradient transitions from a red center to a set of surround colors
' defined at each vertex of the star. DPI scaling is applied globally to ensure consistent
' rendering across high-resolution displays.
' ========================================================================================
SUB Example_CreatePathGradientFromPath (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a GraphicsPath object and initializes the fill mode.
   DIM path AS GdiPlusGraphicsPath = FillModeAlternate

   ' // Fill the array of points.
   DIM pts(0 TO 9) AS GpPointF
   pts(0).x = 75  : pts(0).y = 0
   pts(1).x = 100 : pts(1).y = 50
   pts(2).x = 150 : pts(2).y = 50
   pts(3).x = 112 : pts(3).y = 75
   pts(4).x = 150 : pts(4).y = 150
   pts(5).x = 75  : pts(5).y = 100
   pts(6).x = 0   : pts(6).y = 150
   pts(7).x = 37  : pts(7).y = 75
   pts(8).x = 0   : pts(8).y = 50
   pts(9).x = 50  : pts(9).y = 50

   ' // Construct the path with the array of points.
   GdipAddPathLine2(path, @pts(0), 10)

   ' // Use the path to construct a path gradient brush.
   DIM brush AS GdiPlusPathGradientBrush = *path

   ' // Set the color at the center of the path to red.
   GdipSetPathGradientCenterColor(brush, ARGB_RED)

   ' // Set the colors of the points in the array.
   DIM Colors(9) AS ARGB
   Colors(0) = ARGB_BLACK
   Colors(1) = ARGB_LIGHTGREEN
   Colors(2) = ARGB_BLUE
   Colors(3) = ARGB_WHITE
   Colors(4) = ARGB_BLACK
   Colors(5) = ARGB_LIGHTGREEN
   Colors(6) = ARGB_BLUE
   Colors(7) = ARGB_WHITE
   Colors(8) = ARGB_BLACK
   Colors(9) = ARGB_LIGHTGREEN
   DIM count AS LONG = 10
   GdipSetPathGradientSurroundColorsWithCount(brush, @Colors(0), @count)

   ' // Fill the path with the path gradient brush.
   GdipFillPath(graphics, brush, path)

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
   pWindow.Create(NULL, "GDI+ GdipCreatePathGradientFromPath", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 250)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   Example_CreatePathGradientFromPath(pGraphCtx.GetMemDc)

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
