'#TEMPLATE DDT Dialog with a Month Calendar control
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/DDT.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

DECLARE FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR


CONST IDC_MONTHCAL = 1001

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
   DIM hDlg AS HWND = DialogNew(0, "DDT Dialog - Month Calendar", , , , , WS_OVERLAPPEDWINDOW)
   DialogSetClient(hDlg, 230, 120)
   DialogCenter(hDlg)

   ' // Add a date time month calendar control to the dialog
   ControlAddMonthCalendar, hDlg, IDC_MONTHCAL, "", 0, 0, _
      DialogGetClientWidth(hDlg), DialogGetClientHeight(hDlg)

   ' // Anchor the controls
   ControlAnchor(hDlg, IDC_MONTHCAL, AFX_ANCHOR_HEIGHT_WIDTH)

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
         ' // Notification messages
         DIM dst AS NMSELCHANGE
         CBNMTYPESET(dst, wParam, lParam)
         IF dst.nmhdr.idfrom = IDC_MONTHCAL THEN
            IF dst.nmhdr.code = MCN_SELCHANGE THEN
               ' // Get the selected date
               DIM wszDate AS WSTRING * 260
               GetDateFormatW LOCALE_USER_DEFAULT, DATE_LONGDATE, @dst.stSelStart, NULL, wszDate, SIZEOF(wszDate)\2
               DialogSetText(hDlg, wszDate)
            END IF
         END IF

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
