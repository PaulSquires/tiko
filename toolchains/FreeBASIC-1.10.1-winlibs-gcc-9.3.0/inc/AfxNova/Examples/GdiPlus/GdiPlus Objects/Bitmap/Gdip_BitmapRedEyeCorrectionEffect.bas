' ########################################################################################
' Microsoft Windows
' File: Gdip_RedEyeCorrectionEffect.bas
' Contents: GDI+ Flat API - Gdip_RedEyeCorrectionEffect example
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
' The RedEyeCorrection effect enables you to correct the red eyes that sometimes occur in
' flash photographs. To specify areas of the bitmap that have red eyes, pass a 
' RedEyeCorrectionParams structure to the GdipSetEffectParameters function.
' ========================================================================================
SUB Example_Gdip_RedEyeCorrectionEffect (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   DIM dpiRatio AS SINGLE = graphics.DpiRatio
   graphics.ScaleTransform(dpiRatio)

   ' // Create a bitmap object from a .jpg file
   DIM bmp AS GdiPlusBitmap = "RedEyes.jpg"
   ' // Set the resolution of this Bitmap object to the user's DPI settings
   bmp.SetResolution(graphics)

   ' // Create a red eyes correction effect
   DIM effect AS GdiPlusEffect = RedEyeCorrectionEffectGuid

   ' // We need to specify one or more rectangles that enclose the red-eye areas.
   ' // These are passed as an array of RECT structures.

   ' // Define two rectangles around the eyes
   ' // Change the values according the coordinates of your image
   DIM eyeRects(0 TO 1) AS RECT
   eyeRects(0).left   = 1 : eyeRects(0).top    = 1
   eyeRects(0).right  = 400 : eyeRects(0).bottom = 250
   eyeRects(1).left   = 1 : eyeRects(1).top    = 1
   eyeRects(1).right  = 400 : eyeRects(1).bottom = 250

   ' // Fill a RedEyeCorrectionParams structure
   DIM redeyeParams AS RedEyeCorrectionParams
   redeyeParams.numberOfAreas = 2
   redeyeParams.areas = @eyeRects(0)
   ' // Calculate the size of the paameters
   DIM paramsSize AS UINT = SIZEOF(RedEyeCorrectionParams) + redeyeParams.numberOfAreas * SIZEOF(RECT)
   ' // Set the parameters
   GdipSetEffectParameters(effect, @redeyeParams, paramsSize)

   ' // Apply effect
   GdipBitmapApplyEffect(bmp, effect, NULL, FALSE, NULL, NULL)

   ' // Draw the image
   GdipDrawImage(graphics, bmp, 5, 5)

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
   pWindow.Create(NULL, "GDI+ GdipRedEyeCorrectionEffect", @WndProc)
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
   Example_Gdip_RedEyeCorrectionEffect(pGraphCtx.GetMemDc)

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
