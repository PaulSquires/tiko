' ########################################################################################
' Microsoft Windows
' Contents: GDI+ Draw rectangle
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
' Rectangle with rounded corners
' ========================================================================================
SUB Example_DrawRectangle (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a path
   DIM path AS GdiPlusGraphicsPath = FillModeWinding
   DIM r AS SINGLE = 20
   DIM x AS SINGLE = 100, y AS SINGLE = 60, w AS SINGLE = 200, h AS SINGLE = 120

   '// Addarcs to the path (for the corners)
   GdipAddPathArc(path, x, y, r, r, 180, 90)
   GdipAddPathArc(path, x+w-r, y, r, r, 270, 90)
   GdipAddPathArc(path, x+w-r, y+h-r, r, r, 0, 90)
   GdipAddPathArc(path, x, y+h-r, r, r, 90, 90)
   GdipClosePathFigure(path)

   ' // Create a pen
   DIM pen AS GdiPlusPen = GdiPlusPen(ARGB_DARKBLUE, 3)

   ' // Draw the path
   GdipDrawPath(graphics, pen, path)

END SUB
' ========================================================================================
'SUB Rect_Rounded (BYVAL hdc AS HDC)
'    DIM g AS GdiPlusGraphics = hdc
'    g.ScaleTransform

'    DIM path AS GdiPlusPath = GdiPlusPath(FillModeWinding)
'    DIM r AS SINGLE = 20
'    DIM x AS SINGLE = 40, y AS SINGLE = 40, w AS SINGLE = 200, h AS SINGLE = 120

'    GdipAddPathArc(path, x, y, r, r, 180, 90)
'    GdipAddPathArc(path, x+w-r, y, r, r, 270, 90)
'    GdipAddPathArc(path, x+w-r, y+h-r, r, r, 0, 90)
'    GdipAddPathArc(path, x, y+h-r, r, r, 90, 90)
'    GdipClosePathFigure(path)

'    DIM pen AS GdiPlusPen = GdiPlusPen(ARGB_DARKBLUE, 3, UnitPixel)
'    GdipDrawPath(g, pen, path)
'END SUB

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
   pWindow.Create(NULL, "GDI+ Draw rectangle", @WndProc)
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
   Example_DrawRectangle(pGraphCtx.GetMemDc)

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
