' ########################################################################################
' Microsoft Windows
' Contents: GDI+ Draw clock
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
' Swiss blue crystal dome
' ========================================================================================
SUB Example_DrawClock (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' ============================
   ' 1) Clock background (normal)
   ' ============================
   DIM pen AS GdiPlusPen = GdiPlusPen(ARGB_Black, 3)
   DIM brushText AS GdiPlusSolidBrush = ARGB_Black

   GdipDrawArc(graphics, pen, 100, 25, 200, 200, 0, 360)

   ' Marks
   FOR i AS LONG = 0 TO 59
      DIM ang AS SINGLE = (i * 6 - 90) * 0.0174533
      DIM r1 AS SINGLE = IIF(i MOD 5 = 0, 100, 95)
      DIM r2 AS SINGLE = IIF(i MOD 5 = 0, 80, 90)
      DIM x1 AS SINGLE = 200 + COS(ang) * r1
      DIM y1 AS SINGLE = 125 + SIN(ang) * r1
      DIM x2 AS SINGLE = 200 + COS(ang) * r2
      DIM y2 AS SINGLE = 125 + SIN(ang) * r2
      GdipDrawLine(graphics, pen, x1, y1, x2, y2)
   NEXT

   ' Numbers
   DIM font AS GdiPlusFont = GdiPlusFont("Arial", 12, TRUE)
   FOR i AS LONG = 1 TO 12
      DIM ang AS SINGLE = (i * 30 - 90) * 0.0174533
      DIM x AS SINGLE = 200 + COS(ang) * 70
      DIM y AS SINGLE = 125 + SIN(ang) * 70
      graphics.DrawString(WSTR(i), font, brushText, x - 5, y - 5)
   NEXT

   ' Hands
   DIM angH AS SINGLE = (4 * 30 + 20 * 0.5 - 90) * 0.0174533
   DIM angM AS SINGLE = (20 * 6 - 90) * 0.0174533

   GdipDrawLine(graphics, pen, 200,125, 200 + COS(angH)*60, 125 + SIN(angH)*60)
   GdipDrawLine(graphics, pen, 200,125, 200 + COS(angM)*90, 125 + SIN(angM)*90)

   ' ============================================================
   ' 1) Circular path for the glass
   ' ============================================================
   DIM path AS GdiPlusGraphicsPath = FillModeAlternate
   GdipAddPathEllipse(path, 100, 25, 200, 200)

   ' ============================================================
   ' 2) Create a PathGradientBrush
   ' ============================================================
   DIM pgb AS GdiPlusPathGradientBrush = *path

   ' Center shifted upwards -> Overhead light
   DIM center AS GpPointF = (200, 60)
   GdipSetPathGradientCenterPoint(pgb, @center)

   ' Very light blue center (cool brightness)
   GdipSetPathGradientCenterColor(pgb, GDIP_ARGB(180, 180, 220, 255))

   ' Semi-transparent dark blue border
   DIM surround(0) AS ARGB = {GDIP_ARGB(120, 0, 40, 90)}
   DIM count AS UINT = 1
   GdipSetPathGradientSurroundColorsWithCount(pgb, @surround(0), @count)

   ' Fill the glass
   GdipFillPath(graphics, pgb, path)

   ' ============================================================
   ' 3) Superior reflection (typical of Swiss crystal)
   ' ============================================================
   DIM topRef AS GdiPlusGraphicsPath = FillModeAlternate
   GdipAddPathPie(topRef, 120, 35, 160, 80, 200, 140)

   DIM topBrush AS GdiPlusSolidBrush = GDIP_ARGB(90, 255, 255, 255)
   GdipFillPath(graphics, topBrush, topRef)

   ' ============================================================
   ' 4) Side reflection (Swiss premium effect)
   ' ============================================================
   DIM sideRef AS GdiPlusGraphicsPath = FillModeAlternate
   GdipAddPathPie(sideRef, 160, 60, 80, 140, 300, 120)

   DIM sideBrush AS GdiPlusSolidBrush = GDIP_ARGB(60, 255, 255, 255)
   GdipFillPath(graphics, sideBrush, sideRef)

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
   pWindow.Create(NULL, "GDI+ Draw clock", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 270)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_FLORALWHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   Example_DrawClock(pGraphCtx.GetMemDc)

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
