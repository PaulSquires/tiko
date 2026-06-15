' ########################################################################################
' Microsoft Windows
' File: Gdip_GetPathGradientSurroundColorsWithCount.bas
' Contents: GDI+ Flat API - GdipGetPathGradientSurroundColorsWithCount example
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
' The following example creates a PathGradientBrush object based on a triangular path that
' is defined by an array of three points. The code calls the GdipSetPathGradientSurroundColorsWithCount
' function to specify a color for each of the points that define the triangle. The
' GdipGetPathGradientSurroundColorCount function determines the current number of surround
' colors (the colors specified for the brush's boundary path). Next, the code allocates a
' buffer large enough to receive the array of surround colors and calls GdipGetPathGradientSurroundColorsWithCount
' to fill that buffer. Finally the code fills a small square with each of the brush's surround colors.
' ========================================================================================
SUB Example_GetPathGradientSurroundColorsWithCount (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Creates a gradient brush based on an array of points
   DIM points(0 TO 2) AS GpPointF = {(100, 0), (200, 200), (0, 200)}
   DIM brush AS GdiPlusPathGradientBrush = GdiPlusPathGradientBrush(@points(0), 3)

   ' // Sets the surround colors
   DIM  count AS LONG = 3
   DIM colors(0 TO 2) AS ARGB = {ARGB_RED, ARGB_BLUE, ARGB_LIGHTGREEN}
   GdipSetPathGradientSurroundColorsWithCount(brush, @colors(0), @count)
   
   ' // Get surround color count
   DIM colorCount AS LONG
   GdipGetPathGradientSurroundColorCount(brush, @colorCount)

   ' // Retrieve surround colors
   DIM rgColors(0 TO 2) AS ARGB
   GdipGetPathGradientSurroundColorsWithCount(brush, @rgColors(0), @colorCount)

   ' // Create solid brush for rendering
   DIM solidBrush AS GdiPlusSolidBrush = ARGB_WHITE

   ' // Draw small rectangles with each surround color
   FOR j AS LONG = 0 TO colorCount - 1
      GdipSetSolidFillColor(solidBrush, rgColors(j))
      GdipFillRectangle(graphics, solidBrush, 15 * j, 0, 10, 10)
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
   pWindow.Create(NULL, "GDI+ GdipGetPathGradientSurroundColorsWithCount", @WndProc)
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
   Example_GetPathGradientSurroundColorsWithCount(pGraphCtx.GetMemDc)

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
