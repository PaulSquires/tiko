' ########################################################################################
' Microsoft Windows
' Contents: D2D1 - Draw text with shadow
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
   DIM pFactory AS ID2D1Factory PTR
   DIM pRenderTarget AS ID2D1DCRenderTarget PTR
   DIM pTextBrush AS ID2D1SolidColorBrush PTR
   DIM pShadowBrush AS ID2D1SolidColorBrush PTR

   ' // Create Direct2D factory
   hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, IID_ID2D1Factory, BYVAL NULL, pFactory)
   IF hr <> S_OK THEN RETURN hr

   ' // DPI
   DIM AS SINGLE dpiX, dpiY
   pFactory->GetDesktopDpi(dpiX, dpiY)
   DIM scale AS SINGLE = dpiX / 96

   ' // Render target properties
   DIM props AS D2D1_RENDER_TARGET_PROPERTIES = D2D1_RenderTargetProperties( _
      D2D1_RENDER_TARGET_TYPE_DEFAULT, _
      D2D1_PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE), _
      dpiX, dpiY, _
      D2D1_RENDER_TARGET_USAGE_NONE, D2D1_FEATURE_LEVEL_DEFAULT)

   ' // Create DC render target
   hr = pFactory->CreateDCRenderTarget(props, pRenderTarget)
   IF hr <> S_OK THEN
      pFactory->Release
      RETURN hr
   END IF

   ' // Bind DC
   DIM rc AS RECT = (0, 0, nWidth, nHeight)
   hr = pRenderTarget->BindDC(hMemDC, rc)

   ' // Brushes
   pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(D2D1_Black, 0.35), BYVAL NULL, pShadowBrush)
   pRenderTarget->CreateSolidColorBrush(D2D1_ColorF(D2D1_Blue), BYVAL NULL, pTextBrush)

   ' // DirectWrite factory
   DIM pDWFactory AS IDWriteFactory PTR
   hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, IID_IDWriteFactory, pDWFactory)
   IF hr <> S_OK THEN
      pFactory->Release
      RETURN hr
   END IF

   ' // Text format
   DIM pTextFormat AS IDWriteTextFormat PTR
   pDWFactory->CreateTextFormat( _
      "Segoe UI", _
      NULL, _
      DWRITE_FONT_WEIGHT_BOLD, _
      DWRITE_FONT_STYLE_NORMAL, _
      DWRITE_FONT_STRETCH_NORMAL, _
      36 * scale, _
      "", _
      pTextFormat)

   pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING)
   pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR)

   ' // Render target size
   DIM size AS D2D1_SIZE_F
   pRenderTarget->GetSize(size)

   ' // Begin drawing
   pRenderTarget->BeginDraw
      pRenderTarget->Clear(D2D1_ColorF(D2D1_White))

      DIM txt AS WSTRING * 128 = "Text with shadow"

      ' // Shadow (offset 3px)
      pRenderTarget->DrawText( _
         txt, LEN(txt), _
         pTextFormat, _
         D2D1_RectF(50 + 3, 50 + 3, size.width, size.height), _
         pShadowBrush)

      ' // Main text
      pRenderTarget->DrawText( _
         txt, LEN(txt), _
         pTextFormat, _
         D2D1_RectF(50, 50, size.width, size.height), _
         pTextBrush)

   hr = pRenderTarget->EndDraw

   ' // Cleanup
   D2D1_SafeRelease(pTextFormat)
   D2D1_SafeRelease(pDWFactory)
   D2D1_SafeRelease(pShadowBrush)
   D2D1_SafeRelease(pTextBrush)
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
   DIM hWin AS HWND = pWindow.Create(NULL, "D2D1 - Draw text with shadow", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 300)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_WHITE)

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_FLORALWHITE
   pGraphCtx.Stretchable = TRUE
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
