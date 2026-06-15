' ########################################################################################
' Microsoft Windows
' File: Gdip_CreateHICONFromBitmap.bas
' Contents: GDI+ Flat API - GdipCreateHICONFromBitmap example
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
#INCLUDE ONCE "file.bi"
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
' This example converts a GDI+ Bitmap into a Windows HICON and displays it.
' ========================================================================================
SUB Example_CreateHICONFromBitmap (BYVAL hdc AS HDC)

   DIM status AS GpStatus

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   DIM dpiRatio AS SINGLE = graphics.DpiRatio
   status = graphics.ScaleTransform(dpiRatio)

   ' // Create a bitmap object from a .jpg file
   DIM bmp AS GdiPlusBitmap = "climber.jpg"
   ' // Set the resolution of this Bitmap object to the user's DPI settings
   status = GdipBitmapSetResolution(*bmp, graphics.dpiX, graphics.dpiY)

   ' // Convert to HICON
   DIM hIcon AS HICON
   status = GdipCreateHICONFromBitmap(*bmp, @hIcon)

   ' // Get width and height of the icon
   DIM iconInfo AS ICONINFO
   DIM iconWidth AS LONG
   DIM iconHeight AS LONG
   IF GetIconInfo(hIcon, @iconInfo) THEN
      DIM bmp AS BITMAP
      IF iconInfo.hbmColor THEN
         ' Icon has a color bitmap
         GetObject(iconInfo.hbmColor, SIZEOF(BITMAP), @bmp)
         iconWidth = bmp.bmWidth
         iconHeight = bmp.bmHeight
         DeleteObject(iconInfo.hbmColor)
      ELSEIF iconInfo.hbmMask THEN
         ' Monochrome icon: height is double, so divide by 2
         GetObject(iconInfo.hbmMask, SIZEOF(BITMAP), @bmp)
         iconWidth = bmp.bmWidth
         iconHeight = bmp.bmHeight \ 2
      END IF
      IF iconInfo.hbmMask THEN DeleteObject(iconInfo.hbmMask)
   END IF

   ' // Scale it according to the DPI settings
   DIM scaledWidth AS LONG = iconWidth * dpiRatio
   DIM scaledHeight AS LONG = iconHeight * dpiRatio

   ' // Draw the icon
   DrawIconEx(hdc, 110 * dpiRatio, 60 * dpiRatio, hIcon, scaledWidth, scaledHeight, 0, NULL, DI_NORMAL)

   ' // Cleanup
   IF hIcon THEN DestroyIcon(hIcon)

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
   pWindow.Create(NULL, "GDI+ GdipCreateHICONFromBitmap", @WndProc)
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
   Example_CreateHICONFromBitmap(pGraphCtx.GetMemDc)

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
