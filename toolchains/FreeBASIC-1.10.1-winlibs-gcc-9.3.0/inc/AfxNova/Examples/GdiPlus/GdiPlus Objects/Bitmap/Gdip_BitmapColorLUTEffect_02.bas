' ########################################################################################
' Microsoft Windows
' File: Gdip_BitmapColorLUTEffect_02.bas
' Contents: GDI+ Flat API - GdipBitmapColorLUTEffect example
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
' The ColorLUT effect lets you define lookup tables for each channel—Alpha, Red, Green,
' and Blue—with 256 entries each. For every pixel in the image:
' The channel value (0–255) is used as an index.
' The corresponding value in the LUT replaces the original.
' This means you can:
' Invert colors
' Apply posterization
' Simulate film-like grading
' Create custom stylizations
' The following example applies the effect to the specified region only.
' ========================================================================================
SUB Example_ColorLUTEffectRegion (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a bitmap object from a .jpg file
   DIM bmp AS GdiPlusBitmap = "climber.jpg"
   ' // Set the resolution of this Bitmap object to the user's DPI settings
   bmp.SetResolution(graphics)

   ' // Create ColorLUT effect
   DIM effect AS GdiPlusEffect = ColorLUTEffectGuid

   ' // Create LUTs: identity (no change)
   DIM lut AS ColorLUTParams
   FOR i AS LONG = 0 TO 255
       lut.lutB(i) = 255 - i   ' Invert red
       lut.lutG(i)   = i       ' Identity
       lut.lutR(i) = i         ' Identity
       lut.lutA(i)  = i        ' Identity
   NEXT

   ' // Example: invert red channel
   FOR i AS LONG = 0 TO 255
       lut.lutR(i) = 255 - i
   NEXT

   ' // Set parameters
   GdipSetEffectParameters(effect, @lut, SIZEOF(lut))

   ' // Define the region of interest (ROI)
   DIM roi AS RECT
   roi.left   = 20
   roi.top    = 20
   roi.right  = 150
   roi.bottom = 100

   ' // Apply effect to the specified region only
   GdipBitmapApplyEffect(bmp, effect, @roi, FALSE, NULL, NULL)

   ' // Draw image
   GdipDrawImage(graphics, bmp, 110, 60)

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
   pWindow.Create(NULL, "GDI+ GdipBitmapColorLUTEffect", @WndProc)
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
   Example_ColorLUTEffectRegion(pGraphCtx.GetMemDc)

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
