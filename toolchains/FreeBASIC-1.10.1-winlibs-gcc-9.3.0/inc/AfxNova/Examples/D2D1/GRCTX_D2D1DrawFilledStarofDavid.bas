' ########################################################################################
' Microsoft Windows
' Contents: D2D1 - Draw a filled 6-point star (Star of David)
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
   DIM pGeo  AS ID2D1PathGeometry PTR              ' // ID2D1PathGeometry interface
   DIM pSink AS ID2D1GeometrySink PTR              ' // ID2D1GeometrySink interface

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

      ' // Centered 6-point star (Star of David)
      DIM AS FLOAT x1, y1, x2, y2, x3, y3
      DIM AS FLOAT x4, y4, x5, y5, x6, y6

      ' // Upper triangle
      x1 = 150 : y1 =  30
      x2 =  20 : y2 = 260
      x3 = 280 : y3 = 260

      ' // Lower triangle
      x4 = 150 : y4 = 320
      x5 =  20 : y5 =  90
      x6 = 280 : y6 =  90

      ' // Creates an empty ID2D1PathGeometry
      hr = pFactory->CreatePathGeometry(pGeo)
      IF hr = S_OK THEN
         hr = pGeo->Open(pSink)
         IF hr = S_OK THEN
            ' // Upper triangle
            pSink->BeginFigure(D2D1_Point2F(x1, y1), D2D1_FIGURE_BEGIN_FILLED)
            pSink->AddLine(D2D1_Point2F(x2, y2))
            pSink->AddLine(D2D1_Point2F(x3, y3))
            pSink->EndFigure(D2D1_FIGURE_END_CLOSED)
            ' // Lower triangle
            pSink->BeginFigure(D2D1_Point2F(x4, y4), D2D1_FIGURE_BEGIN_FILLED)
            pSink->AddLine(D2D1_Point2F(x5, y5))
            pSink->AddLine(D2D1_Point2F(x6, y6))
            pSink->EndFigure(D2D1_FIGURE_END_CLOSED)
            pSink->Close
         END IF
      END IF

      ' // Paints the interior of the specified geometry
      pRenderTarget->FillGeometry(pGeo, pBrush)

   ' // The BeginDraw, Clear, and DrawEllipse methods all have a void return type.
   ' // If an error occurs during the execution of any of these methods, the error
   ' // is signaled through the return value of the EndDraw method.
   ' // The EndDraw method signals the completion of drawing for this frame.
   ' //  All drawing operations must be placed between calls to BeginDraw and EndDraw.

   hr = pRenderTarget->EndDraw

   ' // Clean resources
   D2D1_SafeRelease(pGeo)
   D2D1_SafeRelease(pSink)
   D2D1_SafeRelease(pBrush)
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
   DIM hWin AS HWND = pWindow.Create(NULL, "D2D1 - Draw a filled 6-point star", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(300, 350)
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
