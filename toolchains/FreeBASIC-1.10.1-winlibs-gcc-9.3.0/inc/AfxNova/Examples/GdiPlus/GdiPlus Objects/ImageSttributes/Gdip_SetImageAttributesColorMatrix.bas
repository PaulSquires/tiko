' ########################################################################################
' Microsoft Windows
' File: Gdip_SetImageAttributesColorMatrix.bas
' Contents: GDI+ Flat API - GdipSetImageAttributesColorMatrix example
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
' This example applies a grayscale color matrix to an image using GdipSetImageAttributesColorMatrix.
' ========================================================================================
SUB Example_SetColorMatrix (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Load an image from file
   DIM image AS GdiPlusImage = "climber.jpg"
   ' // Set the resolution of this image object to the user's DPI settings
   image.SetResolution(graphics)
   
   ' // Get the width and height of the image
   DIM AS LONG nWidth, nHeight
   GdipGetImageWidth(image, @nWidth)
   GdipGetImageHeight(image, @nHeight)

   ' // Create an ImageAttributes object
   DIM imgAttr AS GdiPlusImageAttributes

   ' // Define grayscale color matrix
   DIM grayMatrix AS ColorMatrix
   grayMatrix.m(0, 0) = 0.3 : grayMatrix.m(0, 1) = 0.3 : grayMatrix.m(0, 2) = 0.3 : grayMatrix.m(0, 3) = 0 : grayMatrix.m(0, 4) = 0
   grayMatrix.m(1, 0) = 0.59: grayMatrix.m(1, 1) = 0.59: grayMatrix.m(1, 2) = 0.59: grayMatrix.m(1, 3) = 0 : grayMatrix.m(1, 4) = 0
   grayMatrix.m(2, 0) = 0.11: grayMatrix.m(2, 1) = 0.11: grayMatrix.m(2, 2) = 0.11: grayMatrix.m(2, 3) = 0 : grayMatrix.m(2, 4) = 0
   grayMatrix.m(3, 0) = 0   : grayMatrix.m(3, 1) = 0   : grayMatrix.m(3, 2) = 0   : grayMatrix.m(3, 3) = 1 : grayMatrix.m(3, 4) = 0
   grayMatrix.m(4, 0) = 0   : grayMatrix.m(4, 1) = 0   : grayMatrix.m(4, 2) = 0   : grayMatrix.m(4, 3) = 0 : grayMatrix.m(4, 4) = 1

   ' // Apply the color matrix
   GdipSetImageAttributesColorMatrix(imgAttr, ColorAdjustTypeDefault, TRUE, @grayMatrix, NULL, ColorMatrixFlagsDefault)

   ' // Draw original image
   GdipDrawImageRect(graphics, image, 10, 10, nWidth, nHeight)

   ' // Draw grayscale image
   GdipDrawImageRectRect(graphics, image, _
      200, 10, nWidth, nHeight, _
      0, 0, nWidth, nHeight, _
      UnitPixel, imgAttr, NULL, NULL)

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
   pWindow.Create(NULL, "GDI+ GdipSetImageAttributesColorMatrix", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(390, 250)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   Example_SetColorMatrix(pGraphCtx.GetMemDc)

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
