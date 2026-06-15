' ########################################################################################
' Microsoft Windows
' Contents: D2D1 - Hollow bezier heart with 3D shadow
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

   ' // The ID2D1RenderTarget.BeginDraw method signals the start of drawing.
   pRenderTarget->BeginDraw

      ' ============================================================
      '  Hollow bezier heart with 3D shading
      ' ============================================================

      ' ===== Brushes =====
      DIM pBrushLight AS ID2D1SolidColorBrush PTR   ' light (right)
      DIM pBrushMid   AS ID2D1SolidColorBrush PTR   ' medium (tip)
      DIM pBrushDark  AS ID2D1SolidColorBrush PTR   ' shadow (left)
      DIM pBrushBack  AS ID2D1SolidColorBrush PTR   ' back (hollow)

      pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(1.0,0.6,0.7,1.0), BYVAL NULL, pBrushLight)
      pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(0.9,0.3,0.5,1.0), BYVAL NULL, pBrushMid)
      pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(0.7,0.1,0.3,1.0), BYVAL NULL, pBrushDark)
      pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(1.0,1.0,1.0,1.0), BYVAL NULL, pBrushBack)

      ' ===== Heart coordinates =====
      ' Exterior (wide and organic)
      DIM AS SINGLE topX,topY : topX = 175 : topY =  90
      DIM AS SINGLE lcX,lcY   : lcX  =  70 : lcY  =  40
      DIM AS SINGLE lmX,lmY   : lmX  =  60 : lmY  = 150
      DIM AS SINGLE rcX,rcY   : rcX  = 280 : rcY  =  40
      DIM AS SINGLE rmX,rmY   : rmX  = 290 : rmY  = 150
      DIM AS SINGLE bx,by     : bx   = 175 : by   = 240

      ' Interior (hollow)
      DIM AS SINGLE topXi,topYi : topXi = 175 : topYi = 120
      DIM AS SINGLE lcXi,lcYi   : lcXi  = 110 : lcYi  =  80
      DIM AS SINGLE lmXi,lmYi   : lmXi  = 110 : lmYi  = 160
      DIM AS SINGLE rcXi,rcYi   : rcXi  = 240 : rcYi  =  80
      DIM AS SINGLE rmXi,rmYi   : rmXi  = 240 : rmYi  = 160
      DIM AS SINGLE bXi,bYi     : bXi   = 175 : bYi   = 210


      ' ============================================================
      '   Geometry 1 — Left lobe (shadow)
      ' ============================================================
      DIM pGeoLeft AS ID2D1PathGeometry PTR
      DIM pSink AS ID2D1GeometrySink PTR

      pFactory->CreatePathGeometry(pGeoLeft)
      pGeoLeft->Open(pSink)

      pSink->BeginFigure(D2D1_Point2F(topX,topY), D2D1_FIGURE_BEGIN_FILLED)

      DIM B1 AS D2D1_BEZIER_SEGMENT
      B1.point1 = D2D1_Point2F(lcX,lcY)
      B1.point2 = D2D1_Point2F(lmX,lmY)
      B1.point3 = D2D1_Point2F(bx,by)
      pSink->AddBezier(B1)

      pSink->EndFigure(D2D1_FIGURE_END_CLOSED)
      pSink->Close
      pSink->Release

      pRenderTarget->FillGeometry(pGeoLeft, pBrushDark)
      pGeoLeft->Release

      ' ============================================================
      '   Geometry 2 — Right robe (light)
      ' ============================================================
      DIM pGeoRight AS ID2D1PathGeometry PTR

      pFactory->CreatePathGeometry(pGeoRight)
      pGeoRight->Open(pSink)

      pSink->BeginFigure(D2D1_Point2F(bx,by), D2D1_FIGURE_BEGIN_FILLED)

      DIM B2 AS D2D1_BEZIER_SEGMENT
      B2.point1 = D2D1_Point2F(rmX,rmY)
      B2.point2 = D2D1_Point2F(rcX,rcY)
      B2.point3 = D2D1_Point2F(topX,topY)
      pSink->AddBezier(B2)

      pSink->EndFigure(D2D1_FIGURE_END_CLOSED)
      pSink->Close
      pSink->Release

      pRenderTarget->FillGeometry(pGeoRight, pBrushLight)
      pGeoRight->Release


      ' ============================================================
      '  Geometry 3 — Lowert tip (medium tone)
      ' ============================================================
      DIM pGeoBottom AS ID2D1PathGeometry PTR

      pFactory->CreatePathGeometry(pGeoBottom)
      pGeoBottom->Open(pSink)

      pSink->BeginFigure(D2D1_Point2F(lmX,lmY), D2D1_FIGURE_BEGIN_FILLED)
      pSink->AddLine(D2D1_Point2F(bx,by))
      pSink->AddLine(D2D1_Point2F(rmX,rmY))
      pSink->EndFigure(D2D1_FIGURE_END_CLOSED)

      pSink->Close
      pSink->Release

      pRenderTarget->FillGeometry(pGeoBottom, pBrushMid)
      pGeoBottom->Release

      ' ============================================================
      '   Geometry 4 — Inner heart (hole)
      ' ============================================================
      DIM pGeoInner AS ID2D1PathGeometry PTR

      pFactory->CreatePathGeometry(pGeoInner)
      pGeoInner->Open(pSink)

      pSink->BeginFigure(D2D1_Point2F(topXi,topYi), D2D1_FIGURE_BEGIN_FILLED)

      DIM Bi1 AS D2D1_BEZIER_SEGMENT
      Bi1.point1 = D2D1_Point2F(lcXi,lcYi)
      Bi1.point2 = D2D1_Point2F(lmXi,lmYi)
      Bi1.point3 = D2D1_Point2F(bXi,bYi)
      pSink->AddBezier(Bi1)

      DIM Bi2 AS D2D1_BEZIER_SEGMENT
      Bi2.point1 = D2D1_Point2F(rmXi,rmYi)
      Bi2.point2 = D2D1_Point2F(rcXi,rcYi)
      Bi2.point3 = D2D1_Point2F(topXi,topYi)
      pSink->AddBezier(Bi2)

      pSink->EndFigure(D2D1_FIGURE_END_CLOSED)
      pSink->Close
      pSink->Release

      ' // We paint the interior with the background color to simulate the gap.
      pRenderTarget->FillGeometry(pGeoInner, pBrushBack)
      pGeoInner->Release

   hr = pRenderTarget->EndDraw

   ' // Clean resources
   D2D1_SafeRelease(pBrushDark)
   D2D1_SafeRelease(pBrushMid)
   D2D1_SafeRelease(pBrushLight)
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
   DIM hWin AS HWND = pWindow.Create(NULL, "D2D1 - Hollow bezier heart", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(350, 300)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_WHITE)

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
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
