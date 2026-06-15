' ########################################################################################
' Microsoft Windows
' File: Gdip_SetClipGraphics.bas
' Contents: GDI+ Flat API - GdipSetClipGraphics example
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
' This example demonstrates how to share a clipping region between two GDI+ Graphics objects
' while maintaining DPI-aware rendering:
' It creates two Graphics objects from the same device context and applies DPI scaling to both.
' A blue rectangle is drawn using the first graphics object.
' A clipping rectangle is defined on the first graphics object, scaled to match the DPI.
' The clipping region is then copied to the second graphics object using GdipSetClipGraphics.
' A red rectangle is drawn using the second graphics object, but only the portion inside the
' shared clipping region is visible—effectively masking the red rectangle over part of the blue one.
' ========================================================================================
SUB Example_SetClipGraphics (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   DIM dpiRatio AS SINGLE = graphics.DpiRatio
   graphics.ScaleTransform(dpiRatio)

   DIM bluePen AS GdiPlusPen = GdiPlusPen(ARGB_BLUE, 2.0, UnitPixel)
   GdipDrawRectangle(graphics, bluePen, 0.0, 0.0, 200.0, 200.0)

   ' // Set a clipping rectangle on graphics
   GdipSetClipRect(graphics, 50.0 * dpiRatio, 50.0 * dpiRatio, 100.0 * dpiRatio, 100.0 * dpiRatio, CombineModeReplace)

   ' // Create a second graphics object
   DIM graphics2 AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics2.ScaleTransform(dpiRatio)

   ' // Apply graphics's clipping region to graphics2
   GdipSetClipGraphics(graphics2, graphics, CombineModeReplace)

   ' // Create pen and draw with graphics2
   DIM pen AS GdiPlusPen = GdiPlusPen(ARGB_RED, 2.0, UnitPixel)
   GdipDrawRectangle(graphics2, pen, 0.0, 0.0, 200.0, 200.0)

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
   pWindow.Create(NULL, "GDI+ GdipSetClipGraphics", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(450, 310)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   Example_SetClipGraphics(pGraphCtx.GetMemDc)

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
