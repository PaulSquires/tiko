'#TEMPLATE DDT - Menu with icons
#cmdline "EX_DDT_Menu_Icons_01.rc"
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#include once "AfxNova/DDT.inc"
#include once "AfxNova/AfxMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

DECLARE FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR

' // Menu identifiers
ENUM
   IDM_UNDO = 1001   ' Undo
   IDM_REDO          ' Redo
   IDM_HOME          ' Home
   IDM_SAVE          ' Save
   IDM_EXIT          ' Exit
END ENUM

CONST IDC_CLOSE = 1100

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Create a new dialog using dialog units
   DIM hDlg AS HWND = DialogNew(0, "DDT - Menu with icons",50, 50, 175, 75, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Create a top-level menu:
   DIM hMenu AS HMENU = MenuNewBar
   ' // Add a submenu
   DIM hPopupMenu AS HMENU = MenuNewPopup
   MenuAddPopup hMenu, "&File", hPopupMenu, MF_ENABLED
   ' // Add items to the submenu
   MenuAddString hPopupMenu, "&Undo" & CHR(9) & "Ctrl+U", IDM_UNDO, MF_ENABLED
   MenuAddString hPopupMenu, "&Redo" & CHR(9) & "Ctrl+R", IDM_REDO, MF_ENABLED
   MenuAddString hPopupMenu, "&Home" & CHR(9) & "Ctrl+H", IDM_HOME, MF_ENABLED
   MenuAddString hPopupMenu, "&Save" & CHR(9) & "Ctrl+S", IDM_SAVE, MF_ENABLED
   MenuAddString hPopupMenu, "E&xit" & CHR(9) & "Alt+F4", IDM_EXIT, MF_ENABLED
   ' // Attach the menu to the dialog
   MenuAttach hMenu, hDlg

   ' // Create a keyboard accelerator table
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "U", IDM_UNDO  ' // Ctrl+U - Undo
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "R", IDM_REDO  ' // Ctrl+R - Redo
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "H", IDM_HOME  ' // Ctrl+H - Home
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "S", IDM_SAVE  ' // Ctrl+S - Save
   CreateAccelTable(hDlg)

   ' // Get the submenu handle
   DIM hSubMenu AS HMENU = MenuGetSubMenu(hMenu, 1)
   ' // Add icons to the submenu items
   MenuAddIconToItem(hSubMenu, 1, TRUE, AfxGdipIconFromRes(hInstance, "IDI_ARROW_LEFT_32"))
   MenuAddIconToItem(hSubMenu, 2, TRUE, AfxGdipIconFromRes(hInstance, "IDI_ARROW_RIGHT_32"))
   MenuAddIconToItem(hSubMenu, 3, TRUE, AfxGdipIconFromRes(hInstance, "IDI_HOME_32"))
   MenuAddIconToItem(hSubMenu, 4, TRUE, AfxGdipIconFromRes(hInstance, "IDI_SAVE_32"))

   ControlAdd("Button", hDlg, IDC_CLOSE, "&Close", 80, 40, 50, 12, BS_DEFPUSHBUTTON)
   ControlAnchor(hDlg, IDC_CLOSE, AFX_ANCHOR_BOTTOM_RIGHT)

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
            CASE IDC_ClOSE, IDM_EXIT
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hDlg, WM_CLOSE, 0, 0
               END IF
            CASE IDM_UNDO TO IDM_SAVE
               MsgBox("WM_COMMAND received from a menu item!", MB_TASKMODAL, "Message")
         END SELECT

      CASE WM_CLOSE
         ' // Destroy the bitmaps used in the menu
         DIM hMenu AS HMENU = MenuGetHandle(hDlg)
         MenuDestroyBitmaps(hMenu)
         MenuDestroy(hMenu)
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
