'#TEMPLATE DDT Dialog - Task Dialog Indirect
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

' // Forward declarations
DECLARE FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR
DECLARE FUNCTION TaskDialogIndirectCallbackProc(BYVAL hwnd AS HWND, BYVAL uNotification AS UINT, BYVAL wParam AS WPARAM, _
        BYVAL lParam AS LPARAM, BYVAL dwRefData AS LONG_PTR) AS HRESULT

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
                  DIM TaskConfig AS TASKDIALOGCONFIG
                  WITH TaskConfig
                     .cbSize = SIZEOF(TASKDIALOGCONFIG)
                     .hwndParent = hDlg
                     .dwFlags = TDF_ENABLE_HYPERLINKS
                     .pszWindowTitle = @WSTR("CDialog")
                     .pszMainIcon = TD_INFORMATION_ICON
                     .dwCommonButtons = TDCBF_OK_BUTTON OR TDCBF_CANCEL_BUTTON
                     .pszMainInstruction = @WSTR("CDialog")
                     .pszContent = @WSTR("An update for the CDialog framework has just been released. Click the hyperlink if you want to download it.")
                     .pszFooter = @WSTR("Hyperlink: <A HREF=" & CHR(34) & "https://github.com/JoseRoca/AfxNova/tree/main" & CHR(34) & ">Download link</A>")
                     .pszFooterIcon = TD_WARNING_ICON
                     .nDefaultButton = IDOK
                     .pfCallback = @TaskDialogIndirectCallbackProc
                  END WITH
                  DIM nClickedButton AS LONG
                  DIM hr AS HRESULT = TaskDialogIndirect(@TaskConfig, @nClickedButton, NULL, NULL)
               END IF
         END SELECT

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback for TaskDialogIndirect.
' ========================================================================================
FUNCTION TaskDialogIndirectCallbackProc(BYVAL hwnd AS HWND, BYVAL uNotification AS UINT, BYVAL wParam AS WPARAM, _
                                        BYVAL lParam AS LPARAM, BYVAL dwRefData AS LONG_PTR) AS HRESULT
   SELECT CASE uNotification
      CASE TDN_HYPERLINK_CLICKED
         ' // The lParam parameter of this message contains the url
         DIM hInstance AS HINSTANCE = ShellExecuteW(NULL, "open", cast(WSTRING PTR, lParam), NULL, NULL, SW_SHOW)
         IF hInstance <= 32 THEN FUNCTION = cast(HRESULT, (cast(LONG_PTR, hInstance))) ELSE FUNCTION = S_OK
   END SELECT
END FUNCTION
' ========================================================================================
