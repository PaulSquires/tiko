' ########################################################################################
' Microsoft Windows
' File: Gdip_LoadImageFromStream.bas
' Contents: GDI+ Flat API - GdipLoadImageFromStream example
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
' The following example creates two Image objects. Each Image object is based on a stream
' that is part of a compound file. For an example of creating a compound file, see
' GdipSaveImageToStream. The code calls StgOpenStorage to open the compound file and get a
' pointer to its IStorage interface. Then the code calls IStorage.OpenStream to get a pointer
' to an IStream interface that represents one of the streams in the compound file. The code
' constructs an Image object based on that IStream pointer and then calls GdipDrawImage to
' display the image on the screen. The code uses a similar process to construct an Image
' object based on a second stream that is part of the same compound file.
' ========================================================================================
SUB Example_LoadImageFromStream (BYVAL hdc AS HDC)

   ' // Create a graphics object from the device context
   DIM graphics AS GdiPlusGraphics = hdc
   ' // Set the scale transform
   graphics.ScaleTransform

   ' // Open compound file
   DIM fileName As WSTRING * 260 = "CompoundFile.cmp"
   DIM storage AS IStorage PTR
   DIM hr AS HRESULT = StgOpenStorage(@fileName, NULL, STGM_READ OR STGM_SHARE_EXCLUSIVE, NULL, 0, @storage)
   IF FAILED(hr) THEN
      MessageBox(NULL, "StgOpenStorage failed", "Error", MB_OK)
      EXIT SUB
   END IF

   ' // Open StreamImage1
   DIM stream1 AS IStream PTR
   DIM streamName1 AS WSTRING * 260 = "StreamImage1"
   hr = storage->lpvtbl->OpenStream(storage, streamName1, NULL, STGM_READ Or STGM_SHARE_EXCLUSIVE, 0, @stream1)

   ' // Open StreamImage2
   DIM stream2 AS IStream PTR
   DIM streamName2 AS WSTRING * 260 = "StreamImage2"
   hr = storage->lpvtbl->OpenStream(storage, streamName2, NULL, STGM_READ Or STGM_SHARE_EXCLUSIVE, 0, @stream2)

   ' // Load image from stream1
   DIM image1 AS GdiPlusImage = stream1
   ' // Set the resolution of this Image object to the user's DPI settings
   image1.SetResolution(*graphics)
   ' // Draw the image
   GdipDrawImage(graphics, image1, 10, 10)

   ' // Load image from stream2
   DIM image2 AS GdiPlusImage = stream2
   ' // Set the resolution of this Image object to the user's DPI settings
   image2.SetResolution(graphics)
   ' // Draw the image
   GdipDrawImage(graphics, image2, 200, 10)

   ' // Cleanup
   IF stream1 THEN stream1->lpvtbl->Release(stream1)
   IF stream2 THEN stream2->lpvtbl->Release(stream2)
   IF storage THEN storage->lpvtbl->Release(storage)

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
   pWindow.Create(NULL, "GDI+ GdipLoadImageFromStream", @WndProc)
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
   Example_LoadImageFromStream(pGraphCtx.GetMemDc)

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
