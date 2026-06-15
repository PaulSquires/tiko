'#TEMPLATE DDT Dialog with a TreeView
#cmdline "EX_DDT_TreeView_01.rc"
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/AfxGdiplus.inc"
#include once "AfxNova/AfxExt.bi"
#include once "AfxNova/DDT.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

DECLARE FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR

CONST IDC_TREEVIEW = 1001

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

'   ' // Set process DPI aware
'   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
'   ' // Enable visual styles without including a manifest file
'   AfxEnableVisualStyles

   ' // Create a new dialog using dialog units
   DIM hDlg AS HWND = DialogNew(0, "DDT Dialog with a TreeView", , , 190, 175, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add a TreeView
   ControlAddTreeView, hDlg, IDC_TREEVIEW, "", 5, 5, 180, 150

   ' // Calculate the size of the icon according the DPI
   DIM cx AS LONG = 16 * GetDpiForSystem \ 96

   ' // Create an image list for the treeview
   DIM hImageList AS HIMAGELIST
   hImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 3, 0)
   IF hImageList THEN
      AfxGdipAddIconFromRes(hImageList, hInstance, "IDI_FOLDER_CLOSED")
      AfxGdipAddIconFromRes(hImageList, hInstance, "IDI_FOLDER_OPEN")
      AfxGdipAddIconFromRes(hImageList, hInstance, "IDI_ARROW_RIGHT")
      ' // Set the image list
      TreeViewSetImageList(hDlg, IDC_TREEVIEW, hImageList)
   END IF

   ' // Add items to the TreeView
   DIM AS HTREEITEM hRoot, hNode, hItem
   ' // Create the root node
   hRoot = TreeViewInsertItem(hDlg, IDC_TREEVIEW, 0, TVI_FIRST, 1, 3, "Root")
   ' // Create a node
   hNode = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hRoot, TVI_LAST, 1, 3, "Node 1")
   ' // Insert items in the node
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 1 Item 1")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 1 Item 2")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 1 Item 3")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 1 Item 4")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 1 Item 5")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 1 Item 6")
   ' // Expand the node
   TreeViewSetExpanded(hDlg, IDC_TREEVIEW, hNode, TRUE)

   ' // Create another node
   hNode = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hRoot, TVI_LAST, 1, 3, "Node 2")
   ' // Insert items in the node
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 2 Item 1")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 2 Item 2")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 2 Item 3")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 2 Item 4")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 2 Item 5")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 2 Item 6")
   ' // Expand the node
   TreeViewSetExpanded(hDlg, IDC_TREEVIEW, hNode, TRUE)

   ' // Create another node
   hNode = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hRoot, TVI_LAST, 1, 3, "Node 3")
   ' // Insert items in the node
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 3 Item 1")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 3 Item 2")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 3 Item 3")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 3 Item 4")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 3 Item 5")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 3 Item 6")
   ' // Expand the node
   TreeViewSetExpanded(hDlg, IDC_TREEVIEW, hNode, TRUE)

   ' // Create another node
   hNode = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hRoot, TVI_LAST, 1, 3, "Node 4")
   ' // Insert items in the node
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 4 Item 1")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 4 Item 2")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 4 Item 3")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 4 Item 4")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 4 Item 5")
   hItem = TreeViewInsertItem(hDlg, IDC_TREEVIEW, hNode, TVI_LAST, 1, 3, "Node 4 Item 6")
   ' // Expand the node
   TreeViewSetExpanded(hDlg, IDC_TREEVIEW, hNode, TRUE)

   ' // Expand the root node
   TreeViewSetExpanded(hDlg, IDC_TREEVIEW, hRoot, TRUE)

   ' // Add a cancel button
   ControlAddButton, hDlg, IDCANCEL, "&Close", 135, 160, 50, 12

   ' // Anchor the controls
   ControlAnchor(hDlg, IDC_TREEVIEW, AFX_ANCHOR_HEIGHT_WIDTH)
   ControlAnchor(hDlg, IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Display and activate the dialog as modal
   DialogShowModal(hDlg, @DlgProc)

   RETURN DialogEndResult(hDlg)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Dialog callback procedure
' ========================================================================================
FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR
   
   SELECT CASE uMsg

      CASE WM_INITDIALOG
         RETURN TRUE

      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hDlg, WM_CLOSE, 0, 0
               END IF
         END SELECT

      CASE WM_NOTIFY
         DIM tv AS NMTREEVIEWW
         CBNMTYPESET(tv, wParam, lParam)
         IF tv.hdr.idFrom = IDC_TREEVIEW THEN
            SELECT CASE tv.hdr.code
               CASE NM_DBLCLK
                  DIM hItem AS HTREEITEM = TreeViewGetSelect(hDlg, IDC_TREEVIEW)
                  ' // Retrieve the text of the selected item
                  DIM dwsText AS DWSTRING = TreeViewGetText(hDlg, IDC_TREEVIEW, hItem)
                  MsgBox hDlg, dwsText, MB_OK, "Message"
                  RETURN TRUE
               CASE TVN_ITEMEXPANDEDW
                  DIM tvi AS TVITEM = tv.itemNew
                  IF (tv.itemNew.state AND TVIS_EXPANDED) THEN tvi.iImage = 2 ELSE tvi.iImage = 1
                  ' // Set the item's new attributes
                  DIM hTreeView AS HWND = ControlHandle(hDlg, IDC_TREEVIEW)
                  TreeView_SetItem(hTreeView, @tvi)
                  RETURN TRUE
            END SELECT
         END IF

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

    	CASE WM_DESTROY
          ' // Destroy the image list
         ImageListKill(TreeViewSetImageList(hDlg, IDC_TREEVIEW, NULL))
         RETURN TRUE

   END SELECT

   RETURN FALSE

END FUNCTION
