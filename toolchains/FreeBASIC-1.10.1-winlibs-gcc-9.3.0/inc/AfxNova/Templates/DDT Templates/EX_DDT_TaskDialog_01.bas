'#TEMPLATE DDT Dialog - Task Dialog
#cmdline "Resource.rc"
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

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)

   ' // Create a new dialog using dialog units
   DIM hDlg AS HWND = DialogNew(0, "DDT - Task Dialog", , , 285, 120, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add buttons
   ControlAddButton, hDlg, IDOK, "&Click me", 140, 90, 50, 14
   ControlAddButton, hDlg, IDCANCEL, "&Close", 210, 90, 50, 14

   ' // Anchor the controls
   ControlAnchor(hDlg, IDOK, AFX_ANCHOR_BOTTOM_RIGHT)
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
            ' // Launch the Pick icon dialog
            CASE IDOK
               ' // Display the message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  DIM nClickedButton AS LONG
                  DIM hr AS HRESULT = TaskDialog(hDlg, NULL, "CDialog", "CDialog", _
                        "An update for the CDialog framework has just been released", _
                        TDCBF_YES_BUTTON OR TDCBF_NO_BUTTON, _
                        TD_INFORMATION_ICON, @nClickedButton)
                  IF hr = S_OK THEN
                     SELECT CASE nClickedButton
                        CASE IDYES : MsgBox hDlg, "You clicked the Yes button", MB_OK, "Message"
                        CASE IDNO  : MsgBox hDlg, "You clicked the No button", MB_OK, "Message"
                     END SELECT
                  END IF
               END IF
         END SELECT

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
