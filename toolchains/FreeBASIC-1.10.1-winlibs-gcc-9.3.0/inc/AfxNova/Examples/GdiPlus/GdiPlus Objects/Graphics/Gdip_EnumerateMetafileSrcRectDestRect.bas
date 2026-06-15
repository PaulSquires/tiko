' ########################################################################################
' Microsoft Windows
' File: Gdip_EnumerateMetafileSrcRectDestRect.bas
' Contents: GDI+ Flat API - GdipEnumerateMetafileSrcRectDestRect example
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
' Cropped Metafile Playback in a Rectangle
' Cropping: Only the portion inside srcRect is processed.
' Scaling and positioning: The content is rendered inside destRect, stretched or shrunk as needed.
' Inspection: The callback lets you analyze or selectively replay records.
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WSTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileSrcRectDestRect (BYVAL hdc AS HDC)

   ' // Create graphics object from HDC
   DIM graphics AS GdiPlusGraphics = hdc

   ' // Load a metafile
   DIM status AS GpStatus
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   status = GdipCreateMetafileFromFile(@filename, @metafile)
   IF status <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(status)
      EXIT SUB
   END IF

   ' // Define source rectangle (crop area)
   DIM srcRect AS GpRectF = (50.0, 50.0, 200.0, 100.0)

   ' // Define destination rectangle (where to draw)
   DIM destRect AS GpRectF = (300.0, 100.0, 400.0, 200.0)

   ' // Enumerate and replay cropped metafile
   status = GdipEnumerateMetafileSrcRectDestRect(graphics, metafile, @destRect, @srcRect, _
                                                 UnitPixel, @MetafileCallback, NULL, NULL)
   IF status <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(status)
   ELSE
      AfxMsg "Success"
   END IF

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
   pWindow.Create(NULL, "GDI+ GdipEnumerateMetafileSrcRectDestRect", @WndProc)
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
   Example_EnumerateMetafileSrcRectDestRect(pGraphCtx.GetMemDc)

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
