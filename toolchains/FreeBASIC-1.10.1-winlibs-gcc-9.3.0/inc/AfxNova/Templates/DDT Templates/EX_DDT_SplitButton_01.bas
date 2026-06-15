'#TEMPLATE DDT Dialog with a Split button
#cmdline "EX_DDT_SplitButton_01.rc"
#define _WIN32_WINNT &h0602
#include once "AfxNova/AfxExt.bi"
#include once "AfxNova/AfxGdiPlus.inc"
#include once "AfxNova/DDT.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

DECLARE FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR

CONST IDC_SPLITBUTTON = 1001

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

   ' // Create a new dialog using dialog units
   DIM hDlg AS HWND = DialogNew(0, "DDT Dialog - Split button", 50, 50, 190, 85, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add an edit control
   DIM hSplitButton AS HWND = ControlAdd("BUTTON", hDlg, IDC_SPLITBUTTON, "&Shutdown", 60, 30, 60, 12, BS_SPLITBUTTON)

   ' // Calculate an appropriate icon size
   DIM cx AS LONG = 16 * GetDpiForSystem \ 96
   ' // Create an image list for the button
   DIM hImageList AS HIMAGELIST = ImageListNewIcon(cx, cx, 32, 1)
   IF hImageList THEN AfxGdipAddIconFromRes(hImageList, hInstance, "IDI_SHUTDOWN_48")
   ' // Fill a BUTTON_IMAGELIST structure and set the image list
   DIM rc AS RECT = (2, 2, 2, 2)    ' // set the magins for the icon
   rc = ScaleRectForDpi(hDlg, rc)   ' // scale them for DPI
   DIM bi AS BUTTON_IMAGELIST = (hImageList, rc, BUTTON_IMAGELIST_ALIGN_LEFT)
   Button_SetImageList(hSplitButton, @bi)

   ' // Anchor the button
   ControlAnchor(hDlg, IDC_SPLITBUTTON, AFX_ANCHOR_CENTER)

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
            CASE IDC_SPLITBUTTON
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  MsgBox(hDlg, "Button clicked", MB_OK, "Message")
               END IF
         END SELECT

      CASE WM_NOTIFY
         ' // Processs notify messages sent by the split button
         DIM tDropDown AS NMBCDROPDOWN
         CBNMTYPESET(tDropDown, wParam, lParam)
         IF tDropDown.hdr.idFrom = IDC_SPLITBUTTON THEN
            IF tDropDown.hdr.code = BCN_DROPDOWN THEN
               ' // Get the screen coordinates of the button
               DIM pt AS POINT = (tDropdown.rcButton.left, tDropDown.rcButton.bottom)
               ClientToScreen(tDropDown.hdr.hwndFrom, @pt)
               ' // Create a menu and add items
               DIM hSplitMenu AS HMENU = MenuNewPopup
               MenuAddString(hSplitMenu, "Menu item 1", 1, MF_ENABLED)
               MenuAddString(hSplitMenu, "Menu item 2", 2, MF_ENABLED)
               MenuAddString(hSplitMenu, "Menu item 3", 3, MF_ENABLED)
               DIM id AS LONG = MenuContext(hDlg, hSplitMenu, pt.x, pt.y, TPM_LEFTBUTTON)
               IF id THEN MsgBox(hDlg, "You clicked item " & WSTR(id), MB_OK, "Message")
            ELSEIF tDropDown.hdr.code = BCN_HOTITEMCHANGE THEN
               DIM tHotItem AS NMBCHOTITEM
               CBNMTYPESET(tHotItem, wParam, lParam)
               IF (tHotItem.dwFlags AND HICF_ENTERING) THEN
                  DialogSetText hDlg, "Mouse entering the button"
               ELSEIF (tHotItem.dwFlags AND HICF_LEAVING) THEN
                  DialogSetText hDlg, "Mouse leaving the button"
               END IF
            END IF
         END IF
         RETURN TRUE

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

      CASE WM_DESTROY
         ' // Destroy the image list
         DIM hSplitButton AS HWND = ControlHandle(hDlg, IDC_SPLITBUTTON)
         DIM bi AS BUTTON_IMAGELIST
         IF Button_GetImageList(hSplitButton, @bi) THEN
            ImageListKill bi.hIml
         END IF

   END SELECT

   RETURN FALSE

END FUNCTION
