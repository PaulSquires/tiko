' ########################################################################################
' Microsoft Windows
' Contents: D2D1 - Reversed diagonal linear gradient brush
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CGraphCtx.inc"
#include once "AfxNova/AfxD2D1.bi"
USING AfxNova

CONST IDC_GRCTX = 1001

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' This function draws Direct2D content to a GDI HDC.
' hMemDC = Handle of the memory device context of the graphic control
' nWidth = Width of the virtual buffer of the graphic control
' nHeight = Height of the virtual buffer of the graphic control
' ========================================================================================
FUNCTION RenderScene (BYVAL hMemDC AS HDC, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS HRESULT

   DIM hr AS HRESULT
   DIM pFactory AS ID2D1Factory PTR                ' // ID2D1Factory interface
   DIM pRenderTarget AS ID2D1DCRenderTarget PTR    ' // ID2D1DCRenderTarget interface
   DIM pBrush AS ID2D1SolidColorBrush PTR          ' // ID2D1SolidColorBrush interface

   ' // Create an instance of the ID2D1Factory interface
   hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, IID_ID2D1Factory, BYVAL NULL, pFactory)
   IF hr <> S_OK THEN RETURN hr

   ' // Get the DPI values
   DIM AS SINGLE dpix, dpiY
   pFactory->GetDesktopDpi(dpiX, dpiY)

   ' // Poperties of the tender target
   DIM props AS D2D1_RENDER_TARGET_PROPERTIES = D2D1_RenderTargetProperties ( _
       D2D1_RENDER_TARGET_TYPE_DEFAULT, _
       D2D1_PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE), _
       dpiX, dpiY, _
       D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT)

   ' // Create a DC render target.
   hr = pFactory->CreateDCRenderTarget(props, pRenderTarget) 
   IF hr <> S_OK THEN
      pFactory->Release
      RETURN hr
   END IF

   ' // Get the dimensions of the graphic control drawing area.
   DIM rc AS RECT = (0, 0, nWidth, nHeight)

   ' // Bind the DC to the DC render target.
   hr = pRenderTarget->BindDC(hMemDC, rc)

   ' // Create a brush.
   hr = pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(D2D1_Blue), BYVAL NULL, pBrush)

   ' // The ID2D1RenderTarget.BeginDraw method signals the start of drawing.
   pRenderTarget->BeginDraw

      ' // The ID2D1RenderTarget.Clear method fills the entire render target with a
      ' // solid color. The color is given as a D2D1_COLOR_F structure.
      pRenderTarget->Clear(D2D1_ColorF(D2D1_White))

      ' ============================================================
      ' Four-clor revesed diagonal linear gadient brush
      '  Direction: bottom-right ? top-left
      ' ============================================================

      ' --- Brush and stop collection pointers ---
      DIM pGradientBrush  AS ID2D1LinearGradientBrush PTR
      DIM pStopCollection AS ID2D1GradientStopCollection PTR

      ' --- Define four gradient stops ---
      DIM stops(3) AS D2D1_GRADIENT_STOP
      stops(0).position = 0.0
      stops(0).color    = D2D1_ColorF(1.0, 0.2, 0.4, 1.0)   ' Pink/Red (bottom-right)
      stops(1).position = 0.33
      stops(1).color    = D2D1_ColorF(1.0, 0.8, 0.2, 1.0)   ' Gold
      stops(2).position = 0.66
      stops(2).color    = D2D1_ColorF(0.2, 1.0, 0.6, 1.0)   ' Greenish
      stops(3).position = 1.0
      stops(3).color    = D2D1_ColorF(0.2, 0.4, 1.0, 1.0)   ' Blue (top-left)

      ' --- Create gradient stop collection ---
      pRenderTarget->CreateGradientStopCollection( _
         stops(0), 4, _
         D2D1_GAMMA_2_2, _
         D2D1_EXTEND_MODE_CLAMP, _
         pStopCollection)

      ' --- Define reversed diagonal direction ---
      DIM brushprops AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
      brushprops.startPoint = D2D1_Point2F(300, 300)    ' bottom-right
      brushprops.endPoint   = D2D1_Point2F(50, 50)      ' top-left

      ' --- Create the linear gradient brush ---
      pRenderTarget->CreateLinearGradientBrush( _
         brushprops, _
         BYVAL NULL, _
         pStopCollection, _
         pGradientBrush)

      ' --- Draw a rectangle using the reversed diagonal gradient ---
      DIM r AS D2D1_RECT_F
      r.left   = 50
      r.top    = 50
      r.right  = 250
      r.bottom = 250

      pRenderTarget->FillRectangle(r, pGradientBrush)

   ' // The BeginDraw, Clear, and DrawEllipse methods all have a void return type.
   ' // If an error occurs during the execution of any of these methods, the error
   ' // is signaled through the return value of the EndDraw method.
   ' // The EndDraw method signals the completion of drawing for this frame.
   ' //  All drawing operations must be placed between calls to BeginDraw and EndDraw.

   hr = pRenderTarget->EndDraw

   ' // Clean resources
   D2D1_SafeRelease(pGradientBrush)
   D2D1_SafeRelease(pStopCollection)
   D2D1_SafeRelease(pRenderTarget)
   D2D1_SafeRelease(pFactory)


   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Initializa the COM library
   CoInitialize NULL

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "D2D1 - Reversed diagonal linear gradient brush", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(300, 300)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_WHITE)

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_FLORALWHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Draw the graphics
   RenderScene(pGraphCtx.GetMemDc, pGraphCtx.GetVirtualBufferWidth, pGraphCtx.GetVirtualBufferHeight)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

   ' // Uninitialize the COM library
   CoUninitialize

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

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
