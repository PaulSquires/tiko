' ########################################################################################
' Microsoft Windows
' Contents: Embedded Microsoft Hierarchical Grid Control
' Compiler: FreeBasic 32 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#define _WIN32_WINNT &h0602
'#define _CMSHGRID_DEBUG_ 1
#INCLUDE ONCE "AfxNova/CAxHost.inc"
#INCLUDE ONCE "AfxNova/MSHFlexGrid.inc"
#INCLUDE ONCE "AfxNova/CADODB.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_GRID = 1001

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   ' // The recommended way is to use a manifest file
   AfxSetProcessDPIAware

   ' // Creates the main window
   DIM pWindow AS CWindow
   ' -or- DIM pWindow AS CWindow = "MyClassName" (use the name that you wish)
   DIM hwndMain AS HWND = pWindow.Create(NULL, "Microsoft Hierarchical Flex Grid", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(800, 450)
   ' // Centers the window
   pWindow.Center

   DIM wszLibName AS WSTRING * 260 = ExePath & "\MSHFLXGD.OCX"
   DIM pHost AS CAxHost = CAxHost(@pWindow, IDC_GRID, wszLibName, AFX_CLSID_MSHFlexGrid, _
       AFX_IID_IMSHFlexGrid, RTLKEY_MSHFlexGrid, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pWindow.AnchorControl(IDC_GRID, AFX_ANCHOR_HEIGHT_WIDTH)
   SetFocus pHost.hWindow

   DIM pGrid AS CMSHFlexGrid = pHost.OcxDispObj

   ' // Set the events sink
   DIM pEvtSink AS ANY PTR = NEW CMSHFlexGridEvents
   pGrid.SetEvents(pEvtSink)
   pGrid.OleDropMode = flexOLEDropManual

   ' // Set the width of the columns (in twips)
   pGrid.ColWidth(0) = 300
   pGrid.ColWidth(1) = 1100
   pGrid.ColWidth(2) = 3000
   pGrid.ColWidth(3) = 2000
   pGrid.ColWidth(4) = 2000
   pGrid.ColWidth(5) = 3000
   pGrid.ColWidth(6) = 1500
   pGrid.ColWidth(7) = 700
   pGrid.ColWidth(8) = 1200
   pGrid.ColWidth(9) = 1200
   pGrid.ColWidth(10) = 1500
   pGrid.ColWidth(11) = 1500
   ' Change the foreground and background colors
   pGrid.ForeColor = BGR(0, 0, 0)
   pGrid.BackColor = BGR(255,255,235)

   ' // Allow user resizing of columns and rows
   pGrid.AllowUserResizing = flexResizeBoth

   ' Open an ADO connection
   DIM pConnection AS CAdoConnection PTR = NEW CAdoConnection
   pConnection->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" & ExePath & $"\nwind.mdb"
   pConnection->Open
   ' Open a recordset
   DIM pRecordset AS CAdoRecordset PTR = NEW CAdoRecordset
   DIM dvSource AS DVARIANT = "SELECT * FROM Customers"
   pRecordset->Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)
   ' Set the Datasource property of the recordset
   pGrid.DataSource = cast(ANY PTR, pRecordset->DataSource)
   ' Close the recordset
   pRecordset->Close
   ' Close the connection
   pConnection->Close
   ' // Delete the recordset
   Delete pRecordset
   ' // Delete the connection
   Delete pConnection

   ' // Display the window
   ShowWindow(hwndMain, nCmdShow)
   UpdateWindow(hwndMain)

   ' // Dispatch Windows messages
   DIM uMsg AS MSG
   WHILE (GetMessageW(@uMsg, NULL, 0, 0) <> FALSE)
      IF AfxCAxHostForwardMessage(GetFocus, @uMsg) = FALSE THEN
         IF IsDialogMessageW(hwndMain, @uMsg) = 0 THEN
            TranslateMessage(@uMsg)
            DispatchMessageW(@uMsg)
         END IF
      END IF
   WEND
   FUNCTION = uMsg.wParam

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
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
