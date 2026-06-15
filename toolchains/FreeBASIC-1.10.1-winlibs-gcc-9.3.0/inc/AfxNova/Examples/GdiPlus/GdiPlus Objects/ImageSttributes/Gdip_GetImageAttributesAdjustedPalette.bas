' ########################################################################################
' Microsoft Windows
' File: Gdip_GetImageAttributesAdjustedPalette.bas
' Contents: GDI+ Flat API - GdipGetImageAttributesAdjustedPalette example
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
' The following example initializes a ColorPalette structure with four colors: aqua, black,
' red, and green. The code also creates an ImageAttributes object and sets its bitmap remap
' table so that green will be converted to blue. Then the code adjusts the palette colors by
' passing the address of the palette to the GdipGetAdjustedPalette function. The code displays
' the four palette colors twice: once before the adjustment and once after the adjustment.
' ========================================================================================
SUB GDIP_GetAdjustedPalette  (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Create a palette that has four entries.
   DIM clrPalette AS COLORPALETTE PTR
   DIM PALETTE_SIZE AS LONG = 4
   clrPalette = Allocate(SIZEOF(COLORPALETTE) + PALETTE_SIZE * SIZEOF(ARGB))
   clrPalette->Flags = 0
   clrPalette->Count = PALETTE_SIZE

   clrPalette->Entries(0) = ARGB_Aqua
   clrPalette->Entries(1) = ARGB_Black
   clrPalette->Entries(2) = ARGB_Red
   clrPalette->Entries(3) = ARGB_Green

   ' // Create a SolidBrush
   DIM brush AS GdiPlusSolidBrush = ARGB_BLACK
   
   ' // Display the four palette colors with no adjustment.
   FOR j AS LONG = 0 TO PALETTE_SIZE - 1
      GdipSetSolidFillColor(brush, clrPalette->Entries(j))
      GdipFillRectangle(graphics, brush, 30 * j, 0, 20, 20)
   NEXT
   
   ' // Create a remap table that converts green to blue.
   DIM map AS GpColorMap
   map.oldColor = ARGB_Green
   map.newColor = ARGB_Violet

   ' // Create an ImageAttributes object, and set its bitmap remap table.
   DIM imgAttr AS GdiPlusImageAttributes
   GdipSetImageAttributesRemapTable(imgAttr, _
             ColorAdjustTypeBitmap, TRUE, 1, @map)

   ' // Adjust the palette.
   GdipGetImageAttributesAdjustedPalette(imgAttr, clrPalette, ColorAdjustTypeBitmap)

   ' // Display the four palette colors after the adjustment.
   FOR j AS LONG = 0 TO PALETTE_SIZE - 1
      GdipSetSolidFillColor(brush, clrPalette->Entries(j))
      GdipFillRectangle (graphics, brush, 30 * j, 30, 20, 20)
   NEXT

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
   pWindow.Create(NULL, "GDI+ GdipGetImageAttributesAdjustedPalette", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 250)
   ' // Center the window
   pWindow.Center

   ' // Add a graphic control
   DIM pGraphCtx AS CGraphCtx = CGraphCtx(@pWindow, IDC_GRCTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pGraphCtx.Clear RGB_WHITE
   ' // Anchor the control
   pWindow.AnchorControl(pGraphCtx.hWindow, AFX_ANCHOR_HEIGHT_WIDTH)
   
   ' // Draw the graphics
   GDIP_GetAdjustedPalette(pGraphCtx.GetMemDc)

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
