' ########################################################################################
' Microsoft Windows
' File: CW_ListView_DragAndDrop_01.bas
' Contents: ListView control
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

#define IDC_LISTVIEW 1001

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
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - ListView control", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(440, 280)
   ' // Center the window
   pWindow.Center

   ' // Adds a listview
   DIM hListView AS HWND = pWindow.AddControl("ListView", hWin, IDC_LISTVIEW, "", 10, 10, 420, 260)

   ' // Adds the header's column name
   Listview_AddColumn(hListview, 0, "Items", pWindow.ScaleX(390), LVCFMT_LEFT)

   ' // Populates the ListView with some data
   DIM wszText AS WSTRING * 260
   FOR i AS LONG = 0 to 29
      wszText = "This is item number " + WSTR(i)
      Listview_AddItem(hListview, i, 0, wszText)
   NEXT

   ' // Adds grid lines
   DIM dwExStyle AS DWORD = ListView_GetExtendedListViewStyle(hListView)
   dwExStyle OR= LVS_EX_GRIDLINES
   ListView_SetExtendedListViewStyle(hListView, dwExStyle)

   ' // Set the text color of the ListView
   ListView_SetTextColor(hListView, RGB_BLUE)
   
   ' // Anchor the ListView
   pWindow.AnchorControl(IDC_LISTVIEW, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Select the fist item (ListView items are zero based)
   ListView_SelectItem(hListView, 0)
   ' // Set the focus in the ListView
   SetFocus hListView

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC bDragItem AS BOOLEAN, hListView AS HWND
   DIM lvi AS LVITEMW, lvhit AS LVHITTESTINFO, wszText AS WSTRING * 260

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

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         DIM pnmh AS NMHDR PTR = cast(NMHDR PTR, lParam)
         SELECT CASE pnmh->idFrom
            CASE IDC_LISTVIEW
               SELECT CASE pnmh->code
                  CASE LVN_BEGINDRAG
                     ' Track the handle, capture mouse input and set drag flag...
                     hListView = pnmh->hwndFrom
                     bDragItem = TRUE
                     SetFocus hListView
                     SetCapture hwnd
               END SELECT
         END SELECT

      CASE WM_MOUSEMOVE
         ' Set focus rectangle on new position, or display no-move cursor...
         IF bDragItem THEN
            GetCursorPos @lvhit.pt
            ScreenToClient hListView, @lvhit.pt
            SendMessageW hListView, LVM_HITTEST, 0, cast(LPARAM, @lvhit)
            IF lvhit.iItem > -1 THEN
               SetCursor LoadCursor(NULL, IDC_ARROW)
               lvi.state = LVIS_FOCUSED
               lvi.stateMask = LVIS_FOCUSED
               SendMessageW hListView, LVM_SETITEMSTATE, cast(WPARAM, lvhit.iItem), cast(LPARAM, @lvi)
            ELSE
               SetCursor LoadCursor(NULL, IDC_NO)
            END IF
         END IF

      CASE WM_LBUTTONUP
         IF bDragItem THEN
            ' Finish dragging item...
            ReleaseCapture
            bDragItem = FALSE
            ' Locate the item drop position...
            GetCursorPos @lvhit.pt
            ScreenToClient hListView, @lvhit.pt
            SendMessageW hListView, LVM_HITTEST, 0, cast(LPARAM, @lvhit)
            DIM nPos AS LONG = SendMessageW(hListView, LVM_GETNEXTITEM, -1, LVNI_SELECTED)
            ' Check to make sure we have a valid item...
            IF (nPos = -1) OR (lvhit.iItem = -1) OR (lvhit.iItem = nPos) OR _
               ((lvhit.flags AND LVHT_ONITEMLABEL = 0) AND (lvhit.flags AND LVHT_ONITEMSTATEICON = 0)) THEN
               ' Reset the focus back to original...
               lvi.state = LVIS_FOCUSED OR LVIS_SELECTED
               lvi.stateMask = LVIS_FOCUSED OR LVIS_SELECTED
               SendMessageW hListView, LVM_SETITEMSTATE, nPos, cast(LPARAM, @lvi)
               EXIT FUNCTION
            END IF
            ' Delete and re-insert item to complete the operation...
            lvi.iItem = nPos
            lvi.pszText = @wszText
            lvi.cchTextMax = SIZEOF(wszText)\2
            lvi.mask = LVIF_STATE OR LVIF_IMAGE OR LVIF_INDENT OR LVIF_PARAM OR LVIF_TEXT
            SendMessageW hListView, LVM_GETITEM, 0, cast(LPARAM, @lvi)
            lvi.iItem = lvhit.iItem
            lvi.state = LVIS_SELECTED OR LVIS_FOCUSED
            lvi.stateMask = LVIS_SELECTED OR LVIS_FOCUSED
            SendMessageW hListView, LVM_DELETEITEM, nPos, 0
            SendMessageW hListView, LVM_INSERTITEM, 0, cast(LPARAM, @lvi)
            SendMessageW hListView, LVM_SETITEMTEXT, lvi.iItem, cast(LPARAM, @lvi)
         END IF

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
