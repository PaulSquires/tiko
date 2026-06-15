' ########################################################################################
' Microsoft Windows
' Contents: D2D1 - Radial gradient brush
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
      ' Bézier heart with radial gradient fill + glowing border + gold outline
      ' ============================================================

      ' // 1) Radial gradient for the heart fill
      DIM pFillBrush  AS ID2D1RadialGradientBrush PTR
      DIM pFillStops  AS ID2D1GradientStopCollection PTR

      DIM fillStops(3) AS D2D1_GRADIENT_STOP
      fillStops(0).position = 0.0
      fillStops(0).color    = D2D1_ColorF(1.0, 0.95, 0.6, 1.0)   ' warm highlight
      fillStops(1).position = 0.33
      fillStops(1).color    = D2D1_ColorF(1.0, 0.6, 0.2, 1.0)    ' orange
      fillStops(2).position = 0.66
      fillStops(2).color    = D2D1_ColorF(0.4, 0.3, 1.0, 1.0)    ' violet
      fillStops(3).position = 1.0
      fillStops(3).color    = D2D1_ColorF(0.1, 0.1, 0.3, 1.0)    ' deep blue

      pRenderTarget->CreateGradientStopCollection( _
         fillStops(0), 4, _
         D2D1_GAMMA_2_2, _
         D2D1_EXTEND_MODE_CLAMP, _
         pFillStops)

      DIM fillProps AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
      fillProps.center = D2D1_Point2F(175, 150)
      fillProps.gradientOriginOffset = D2D1_Point2F(-60, -40)
      fillProps.radiusX = 180
      fillProps.radiusY = 120

      pRenderTarget->CreateRadialGradientBrush( _
         fillProps, _
         BYVAL NULL, _
         pFillStops, _
         pFillBrush)

      ' // 2) Glow border (soft halo)
      DIM pGlowBrush AS ID2D1RadialGradientBrush PTR
      DIM pGlowStops AS ID2D1GradientStopCollection PTR

      DIM glowStops(2) AS D2D1_GRADIENT_STOP
      glowStops(0).position = 0.0
      glowStops(0).color    = D2D1_ColorF(1.0, 1.0, 0.9, 1.0)   ' bright glow
      glowStops(1).position = 0.6
      glowStops(1).color    = D2D1_ColorF(1.0, 0.6, 0.2, 0.4)   ' soft orange
      glowStops(2).position = 1.0
      glowStops(2).color    = D2D1_ColorF(0.0, 0.0, 0.0, 0.0)   ' fade to transparent

      pRenderTarget->CreateGradientStopCollection( _
         glowStops(0), 3, _
         D2D1_GAMMA_2_2, _
         D2D1_EXTEND_MODE_CLAMP, _
         pGlowStops)

      DIM glowProps AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
      glowProps.center = D2D1_Point2F(175, 150)
      glowProps.gradientOriginOffset = D2D1_Point2F(0, 0)
      glowProps.radiusX = 210
      glowProps.radiusY = 210

      pRenderTarget->CreateRadialGradientBrush( _
         glowProps, _
         BYVAL NULL, _
         pGlowStops, _
         pGlowBrush)

      ' // 3 Gold outline (solid brush)
      DIM pGoldBrush AS ID2D1SolidColorBrush PTR
      pRenderTarget->CreateSolidColorBrush( _
         D2D1_ColorF(1.0, 0.85, 0.2, 1.0), _   ' gold color
         BYVAL NULL, _
         pGoldBrush)


      ' // 4) Bézier heart geometry
      DIM pGeoHeart AS ID2D1PathGeometry PTR
      DIM pSink     AS ID2D1GeometrySink PTR

      pFactory->CreatePathGeometry(pGeoHeart)
      pGeoHeart->Open(pSink)

      DIM AS SINGLE topX,topY : topX = 175 : topY =  90
      DIM AS SINGLE lcX,lcY   : lcX  =  70 : lcY  =  40
      DIM AS SINGLE lmX,lmY   : lmX  =  60 : lmY  = 150
      DIM AS SINGLE rcX,rcY   : rcX  = 280 : rcY  =  40
      DIM AS SINGLE rmX,rmY   : rmX  = 290 : rmY  = 150
      DIM AS SINGLE bx,by     : bx   = 175 : by   = 240

      pSink->BeginFigure(D2D1_Point2F(topX, topY), D2D1_FIGURE_BEGIN_FILLED)

      DIM L AS D2D1_BEZIER_SEGMENT
      L.point1 = D2D1_Point2F(lcX, lcY)
      L.point2 = D2D1_Point2F(lmX, lmY)
      L.point3 = D2D1_Point2F(bx,  by)
      pSink->AddBezier(L)

      DIM R AS D2D1_BEZIER_SEGMENT
      R.point1 = D2D1_Point2F(rmX, rmY)
      R.point2 = D2D1_Point2F(rcX, rcY)
      R.point3 = D2D1_Point2F(topX, topY)
      pSink->AddBezier(R)

      pSink->EndFigure(D2D1_FIGURE_END_CLOSED)
      pSink->Close
      pSink->Release

      ' ============================================================
      ' Metallic loop above the heart
      ' ============================================================
      ' // Metallic fill brush (radial gradient)
      DIM pLoopBrush AS ID2D1RadialGradientBrush PTR
      DIM pLoopStops AS ID2D1GradientStopCollection PTR

      DIM loopStops(2) AS D2D1_GRADIENT_STOP
      loopStops(0).position = 0.0
      loopStops(0).color    = D2D1_ColorF(1.0, 0.95, 0.6, 1.0)   ' bright gold center
      loopStops(1).position = 0.5
      loopStops(1).color    = D2D1_ColorF(0.9, 0.7, 0.2, 1.0)    ' warm gold
      loopStops(2).position = 1.0
      loopStops(2).color    = D2D1_ColorF(0.4, 0.3, 0.1, 1.0)    ' darker gold edge

      pRenderTarget->CreateGradientStopCollection( _
         loopStops(0), 3, _
         D2D1_GAMMA_2_2, _
         D2D1_EXTEND_MODE_CLAMP, _
         pLoopStops)

      DIM loopProps AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
      loopProps.center = D2D1_Point2F(175, 60)         ' center of the loop
      loopProps.gradientOriginOffset = D2D1_Point2F(-10, -10)
      loopProps.radiusX = 40
      loopProps.radiusY = 40

      pRenderTarget->CreateRadialGradientBrush( _
          loopProps, _
          BYVAL NULL, _
          pLoopStops, _
          pLoopBrush )

      ' // Loop geometry (rounded arc)
      DIM pGeoLoop AS ID2D1PathGeometry PTR
      DIM pSink2   AS ID2D1GeometrySink PTR

      pFactory->CreatePathGeometry(pGeoLoop)
      pGeoLoop->Open(pSink2)

      ' Loop coordinates (small arc above the heart)
      DIM AS SINGLE lx1, ly1 : lx1 = 145 : ly1 =  80   ' left base
      DIM AS SINGLE lx2, ly2 : lx2 = 205 : ly2 =  80   ' right base
      DIM AS SINGLE cx,  cy  : cx  = 175 : cy  =  40   ' top of arc

      pSink2->BeginFigure(D2D1_Point2F(lx1, ly1), D2D1_FIGURE_BEGIN_FILLED)

      DIM arcseg AS D2D1_BEZIER_SEGMENT
      arcseg.point1 = D2D1_Point2F(150, 30)   ' left control
      arcseg.point2 = D2D1_Point2F(200, 30)   ' right control
      arcseg.point3 = D2D1_Point2F(lx2, ly2)  ' right base
      pSink2->AddBezier(arcseg)

      ' Close the bottom of the loop
      pSink2->AddLine(D2D1_Point2F(lx1, ly1))

      pSink2->EndFigure(D2D1_FIGURE_END_CLOSED)
      pSink2->Close
      pSink2->Release

      ' ============================================================
      ' Natural hanging rotation for the pendant
      ' ============================================================

      ' // Save current transform
      DIM oldTransform AS D2D1_MATRIX_3X2_F
      pRenderTarget->GetTransform(oldTransform)

      ' // Define rotation
      DIM angle AS SINGLE
      angle = -8.0 * 3.14159 / 180.0     ' slight tilt to the left (~ -8°)
      ' // Rotation center (pivot point)
      ' // Use the top of the loop so it looks physically correct
      DIM pivotX AS SINGLE : pivotX = 175
      DIM pivotY AS SINGLE : pivotY =  40
      DIM rot AS D2D1_MATRIX_3X2_F
      rot = D2D1_MatrixRotation(angle * 180.0 / 3.14159, D2D1_Point2F(pivotX, pivotY))
      ' // Apply rotation
      pRenderTarget->SetTransform(rot)

      ' ============================================================
      ' ======= Draw everything =======
      ' ============================================================

      ' // Fill the heart
      pRenderTarget->FillGeometry(pGeoHeart, pFillBrush)
      ' // Glow border (soft halo)
      pRenderTarget->DrawGeometry(pGeoHeart, pGlowBrush, 14.0)
      ' // Gold outline (sharp edge)
      pRenderTarget->DrawGeometry(pGeoHeart, pGoldBrush, 3.0)
      pGeoHeart->Release

      ' // Draw loop (fill + gold outline)
      pRenderTarget->FillGeometry(pGeoLoop, pLoopBrush)
      pRenderTarget->DrawGeometry(pGeoLoop, pGoldBrush, 3.0)
      pGeoLoop->Release

      ' // Release the loop resources
      D2D1_SafeRelease(pLoopBrush)
      D2D1_SafeRelease(pLoopStops)

      ' ============================================================
      '  Gold chain above the metallic loop
      ' ============================================================
      ' Optional: softer inner gold for chain fill
      DIM pChainFill AS ID2D1SolidColorBrush PTR
      pRenderTarget->CreateSolidColorBrush( _
         D2D1_ColorF(1.0, 0.95, 0.7, 1.0), _
         BYVAL NULL, _
         pChainFill)

      ' --- Chain parameters ---
      DIM AS SINGLE baseY      : baseY      = 35     ' vertical position of chain
      DIM AS SINGLE startX     : startX     = 115    ' leftmost link center
      DIM AS SINGLE linkWidth  : linkWidth  = 22
      DIM AS SINGLE linkHeight : linkHeight = 10
      DIM AS SINGLE spacing    : spacing    = 18
      DIM AS INTEGER i

      DIM linkRect AS D2D1_ELLIPSE

      FOR i = 0 TO 6
         DIM cx AS SINGLE
         cx = startX + i * spacing
         ' Slight vertical sag in the middle (chain curve)
         DIM cy AS SINGLE
         cy = baseY + 3 * SIN((i - 3) * 3.14159 / 6.0)
          linkRect.point.x = cx
          linkRect.point.y = cy
          linkRect.radiusX = linkWidth  / 2.0
          linkRect.radiusY = linkHeight / 2.0
         ' Fill + outline for each link
         pRenderTarget->FillEllipse(linkRect, pChainFill)
         pRenderTarget->DrawEllipse(linkRect, pGoldBrush, 2.0)
      NEXT

      ' --- Release chain fill brush ---
      IF pChainFill THEN pChainFill->Release

      ' // Restore original transform
      pRenderTarget->SetTransform(oldTransform)

   ' // The BeginDraw, Clear, and DrawEllipse methods all have a void return type.
   ' // If an error occurs during the execution of any of these methods, the error
   ' // is signaled through the return value of the EndDraw method.
   ' // The EndDraw method signals the completion of drawing for this frame.
   ' //  All drawing operations must be placed between calls to BeginDraw and EndDraw.

   hr = pRenderTarget->EndDraw

   ' // Clean resources
   D2D1_SafeRelease(pFillBrush)
   D2D1_SafeRelease(pFillStops)
   D2D1_SafeRelease(pGoldBrush)
   D2D1_SafeRelease(pGlowBrush)
   D2D1_SafeRelease(pGlowStops)
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
   DIM hWin AS HWND = pWindow.Create(NULL, "D2D1 - Radial gradient brush", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(350, 300)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_WHITE)

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_FLORALWHITE
   'pGraphCtx.Stretchable = TRUE
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
