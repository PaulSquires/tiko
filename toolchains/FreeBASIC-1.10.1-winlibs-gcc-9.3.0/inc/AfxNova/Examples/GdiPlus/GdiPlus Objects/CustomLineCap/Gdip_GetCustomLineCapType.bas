' ########################################################################################
' Microsoft Windows
' File: Gdip_GetCustomLineCapType.bas
' Contents: GDI+ Flat API - Gdip_GetCustomLineCapType example
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
' The following example creates two AdjustableArrowCap objects, arrowCapStart and
' arrowCapEnd, and sets the fill mode to TRUE. The code then creates a Pen object and
' assigns arrowCapStart as the starting line cap for this Pen object and arrowCapEnd as
' the ending line cap. Next, draws a line.
' ========================================================================================
SUB Example_LineCapType (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   DIM dpiRatio AS SINGLE = graphics.DpiRatio
   graphics.ScaleTransform(dpiRatio)

   ' // Create an AdjustableArrowCap that is filled.
   DIM arrowCapStart AS GdiPlusAdjustableArrowCap = GdiPlusAdjustableArrowCap(10, 10, TRUE)
   ' // Adjust to DPI by setting the scale width
   GdipSetCustomLineCapWidthScale(arrowCapStart, dpiRatio)

   ' // Get the type of CustomLineCap
   ' // It will return 1 (CustomLineCapTypeAdjustableArrow)
   DIM nType AS CustomLineCapType
   GdipGetCustomLineCapType(arrowCapStart, @nType)
   AfxMsg "arrowCapStart type = " & WSTR(nType)

   ' // Create an AdjustableArrowCap that is not filled.
   DIM arrowCapEnd AS GdiPlusAdjustableArrowCap = GdiPlusAdjustableArrowCap(15, 15, FALSE)
   ' // Adjust to DPI by setting the scale width
   GdipSetCustomLineCapWidthScale(arrowCapEnd, dpiRatio)

   ' // Get the type of CustomLineCap
   ' // It will return 1 (CustomLineCapTypeAdjustableArrow)
   GdipGetCustomLineCapType(arrowCapEnd, @nType)
   AfxMsg "arrowCapEnd type = " & WSTR(nType)

   ' // Create a Pen
   DIM arrowPen AS GdiPlusPen = GdiPlusPen(ARGB_Violet, 1)

   ' Assign arrowCapStart as the start cap.
   GdipSetPenCustomStartCap(arrowPen, arrowCapStart)
   ' Assign arrowCapEnd as the end cap.
   GdipSetPenCustomEndCap(arrowPen, arrowCapEnd)

   ' // Draw a line using arrowPen.
   GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

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
   pWindow.Create(NULL, "GDI+ Gdip_GetCustomLineCapType", @WndProc)
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
   Example_LineCapType(pGraphCtx.GetMemDc)

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
