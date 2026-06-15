' ########################################################################################
' Microsoft Windows
' File: Gdip_GetHemfFromMetafile.bas
' Contents: GDI+ Flat API - GdipGetHemfFromMetafile example
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
' Extract and Save EMF from a GDI+ Metafile.
' Lets you save a GDI+ metafile using classic WinAPI.
' Enables interoperability with legacy GDI tools and viewers.
' Essential for exporting vector graphics from GDI+ workflows.
' ========================================================================================
SUB Example_GetHemfFromMetafile (BYVAL hdc AS HDC)

   ' // Initialize GDI+
   DIM pObjs AS GdiPlusObjects

   ' // Define frame rectangle
   DIM rcfFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Metafile for export"

   ' // Record metafile
   DIM Status AS GpStatus
   DIM metafile AS GpMetafile PTR
   status = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcfFrame, MetafileFrameUnitPixel, @description, @metafile)
   IF status <> 0 THEN
      AfxMsg "Recording failed: " & WSTR(status)
      EXIT SUB
   END IF

   ' // Draw into metafile
   DIM graphics AS GpGraphics PTR
   status = GdipGetImageGraphicsContext(metafile, @graphics)
   DIM pen AS GdiPlusPen = GdiPlusPen(ARGB_RED, 2.0, UnitPixel)
   status = GdipDrawEllipse(graphics, pen, 50.0, 50.0, 200.0, 100.0)
   GdipDeleteGraphics(graphics)

   ' // Extract HENHMETAFILE
   DIM hEmf AS HENHMETAFILE
   status = GdipGetHemfFromMetafile(metafile, @hEmf)
   IF status <> 0 OR hEmf = 0 THEN
      AfxMsg "Failed to extract EMF handle: " & STR(status)
   ELSE
      ' // Save to disk
      DIM saved AS HENHMETAFILE
      saved = CopyEnhMetaFile(hEmf, "exported.emf")
      IF saved THEN DeleteEnhMetaFile(saved)
      DeleteEnhMetaFile(hEmf)
      AfxMsg "Metafile saved to exported.emf"
   END IF

   ' // Dispose metafile
   IF metafile THEN GdipDisposeImage(metafile)

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
   pWindow.Create(NULL, "GDI+ GdipGetHemfFromMetafile", @WndProc)
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
   Example_GetHemfFromMetafile(pGraphCtx.GetMemDc)

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
