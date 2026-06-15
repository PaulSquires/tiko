' ########################################################################################
' Microsoft Windows
' File: Gdip_GetPathGradientBlend.bas
' Contents: GDI+ Flat API - GdipGetPathGradientBlend example
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
' The following example demonstrates several PathGradient functions, including
' GdipSetPathGradientBlend, GdipGetPathGradientBlendCount, and GdipGetPathGradientBlend.
' The code creates a PathGradientBrush object and calls the GdipSetPathGradientBlend function
' to establish a set of blend factors and blend positions for the brush. Then the code calls
' the GdipGetPathGradientBlendCount function to retrieve the number of blend factors. After
' the number of blend factors is retrieved, the code allocates two buffers: one to receive
' the array of blend factors and one to receive the array of blend positions. Then the code
' calls the GdipGetPathGradientBlendCount method to retrieve the blend factors and the blend
' positions.
' ========================================================================================
SUB Example_GetPathGradientBlend (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a path that consists of a single ellipse.
   DIM path AS GdiPlusGraphicsPath = FillModeAlternate
   GdipAddPathEllipse(path, 100, 70, 200, 100)

   ' // Use the path to construct a brush.
   DIM brush AS GdiPlusPathGradientBrush = *path

   ' // Set the color at the center of the path
   GdipSetPathGradientCenterColor(brush, ARGB_BLUE)

   ' // Set the color along the entire boundary of the path
   DIM colour(0) AS ARGB = {ARGB_RED}
   DIM count AS LONG = 1
   GdipSetPathGradientSurroundColorsWithCount(brush, @Colour(0), @count)

   ' // Set blend factors and positions for the path gradient brush.
   DIM factors(0 TO 3) AS SINGLE = {0.0, 0.4, 0.8, 1.0}
   DIM positions(0 TO 3) AS SINGLE = {0.0, 0.3, 0.7, 1.0}
   GdipSetPathGradientBlend(brush, @factors(0), @positions(0), 4)

   ' // Fill the ellipse with the path gradient brush.
   GdipFillEllipse(graphics, brush, 100, 70, 200, 100)

   ' // Obtain information about the path gradient brush.
   DIM blendCount AS LONG
   GdipGetPathGradientBlendCount(brush, @blendCount)
   DIM blendFactors(blendCount - 1) AS SINGLE
   DIM blendPositions(blendCount - 1) AS SINGLE
   GdipGetPathGradientBlend(brush, @blendFactors(0), @blendPositions(0), blendCount)

   FOR i AS LONG = 0 TO blendCount - 1
      ' // Inspect or use the value in rgFactors(j)
      ' // Inspect or use the value in rgPositions(j)
      OutputDebugStringW WSTR(blendFactors(i)) & " " & WSTR(blendPositions(i))
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
   pWindow.Create(NULL, "GDI+ GdipGetPathGradientBlend", @WndProc)
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
   Example_GetPathGradientBlend(pGraphCtx.GetMemDc)

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
