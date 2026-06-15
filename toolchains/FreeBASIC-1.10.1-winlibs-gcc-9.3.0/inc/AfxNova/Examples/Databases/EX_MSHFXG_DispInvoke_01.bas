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
'#define _CAXH_DEBUG_ 1
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
#INCLUDE ONCE "AfxNova/CAxHost.inc"
#INCLUDE ONCE "AfxNova/MSHFlexGrid.inc"
#INCLUDE ONCE "AfxNova/CDispInvoke.inc"
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
   SetFocus pHost.hWindow

   ' // Get a pointer to the Afx_IMSHFlexGrid interface
   DIM pGrid AS Afx_IMSHFlexGrid PTR = cast(ANY PTR, pHost.OcxDispPtr)
   IF pGrid THEN
      ' // Set the width of thecolumns, in pixels
      pGrid->put_ColWidth(0, 0, 300)
      pGrid->put_ColWidth(1, 0, 1100)
      pGrid->put_ColWidth(2, 0, 3000)
      pGrid->put_ColWidth(3, 0, 2000)
      pGrid->put_ColWidth(4, 0, 2000)
      pGrid->put_ColWidth(5, 0, 3000)
      pGrid->put_ColWidth(6, 0, 1500)
      pGrid->put_ColWidth(7, 0, 700)
      pGrid->put_ColWidth(8, 0, 1200)
      pGrid->put_ColWidth(9, 0, 1200)
      pGrid->put_ColWidth(10, 0, 1500)
      pGrid->put_ColWidth(11, 0, 1500)
      ' // Change the foreground and background colors
      pGrid->put_ForeColor(BGR(0, 0, 0))
      pGrid->put_BackColor(BGR(255,255,235))
   END IF

   ' // Open an ADO connection
   DIM pConnection AS CAdoConnection PTR = NEW CAdoConnection
   pConnection->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" & ExePath & $"\nwind.mdb"
   pConnection->Open
   ' // Open a recordset
   DIM pRecordset AS CAdoRecordset PTR = NEW CAdoRecordset
   DIM dvSource AS DVARIANT = "SELECT * FROM Customers"
   pRecordset->Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)
   ' // Set the Datasource property of the recordset
   pGrid->putref_DataSource(cast(ANY PTR, pRecordset->DataSource))
   ' // Close the recordset
   pRecordset->Close
   ' // Close the connection
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
      ' // Forward the message to the grid
      IF AfxCAxHostForwardMessage(GetFocus, @uMsg) = FALSE THEN
         IF IsDialogMessageW(hwndMain, @uMsg) = 0 THEN
            TranslateMessage(@uMsg)
            DispatchMessageW(@uMsg)
         END IF
      END IF
   WEND
   FUNCTION = uMsg.wParam

IF pGrid THEN AfxSAfeRelease(pGrid)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_SIZE
         ' // Optional resizing code
         IF wParam <> SIZE_MINIMIZED THEN
            ' // Retrieve a pointer to the CWindow class
            DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
            ' // Move the position of the button
            IF pWindow THEN pWindow->MoveWindow GetDlgItem(hwnd, IDC_GRID), _
               0, 0, pWindow->ClientWidth, pWindow->ClientHeight, CTRUE
         END IF

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
