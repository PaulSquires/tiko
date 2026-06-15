'#TEMPLATE DDT Dialog with a Date Time Picker
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

CONST IDC_LABEL = 1001
CONST IDC_DTPICKER = 1002

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
   DIM hDlg AS HWND = DialogNew(0, "DDT Dialog with a DateTimePicker", 50, 50, 190, 80, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add a label
   ControlAddLabel, hDlg, IDC_LABEL, "", 25, 15, 150, 12
   ' // Add a date time picker control to the dialog
   DIM hDTP AS HWND = ControlAdd("DateTimePicker", hDlg, IDC_DTPICKER, "", 35, 30, 115, 12)
   ' // Set the date
   DIM st AS SYSTEMTIME
   st.wDay = 1
   st.wMonth = 7
   st.wYear = 2025
   DateTime_SetSystemTime(hDTP, GDT_VALID, @st)

   ' // Anchor the controls
   ControlAnchor(hDlg, IDC_LABEL, AFX_ANCHOR_WIDTH)
   ControlAnchor(hDlg, IDC_DTPICKER, AFX_ANCHOR_WIDTH)

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
         DIM dtp AS NMDATETIMECHANGE
         CBNMTYPESET(dtp, wParam, lParam)
         IF dtp.nmhdr.idfrom = IDC_DTPICKER THEN
            IF dtp.nmhdr.code = DTN_DATETIMECHANGE THEN
               ' // Get the selected date
               DIM wszDate AS WSTRING * 260
               GetDateFormatW LOCALE_USER_DEFAULT, DATE_LONGDATE, @dtp.st, NULL, wszDate, SIZEOF(wszDate)\2
               ControlSetText(hDlg, IDC_LABEL, "Selected date: " & wszDate)
            END IF
         END IF

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
