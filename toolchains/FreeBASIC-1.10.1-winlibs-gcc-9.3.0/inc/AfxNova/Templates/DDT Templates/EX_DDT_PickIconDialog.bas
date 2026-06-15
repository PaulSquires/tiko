'#TEMPLATE DDT Dialog - Pick Icon Dialog
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

CONST IDC_PICKDLG = 1001

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
   DIM hDlg AS HWND = DialogNew(0, "DDT - Pick Icon Dialog", , , 285, 120, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add buttons
   ControlAddButton, hDlg, IDC_PICKDLG, "&Pick", 140, 90, 50, 14
   ControlAddButton, hDlg, IDCANCEL, "&Close", 210, 90, 50, 14

   ' // Anchor the controls
   ControlAnchor(hDlg, IDC_PICKDLG, AFX_ANCHOR_BOTTOM_RIGHT)
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

   STATIC wszIconPath AS WSTRING * MAX_PATH   ' // Path of the resource file containing the icons
   STATIC nIconIndex AS LONG                  ' // Icon index
   STATIC hIcon AS HICON                      ' // Icon handle
   
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
            CASE IDC_PICKDLG
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  IF LEN(wszIconPath) = 0 THEN wszIconPath = AfxGetSystemDllPath("Shell32.dll")
                  IF LEN(wszIconPath) = 0 THEN RETURN FALSE
                  ' // Activate the Pick Icon Common Dialog Box
                  DIM hr AS LONG = PickIconDlg(hDlg, wszIconPath, SIZEOF(wszIconPath)\2, @nIconIndex)
                  ' // If an icon has been selected...
                  IF hr = 1 THEN
                     ' // Destroy previously loaded icon, if any
                     IF hIcon THEN DestroyIcon(hIcon)
                     ' // Get the handle of the new selected icon
                     hIcon = ExtractIconW(GetModuleHandle(NULL), wszIconPath, nIconIndex)
                     ' // Replace the application icons
                     IF hIcon THEN DialogSetIconEx(hDlg, hIcon, hIcon)
                  END IF
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_CLOSE
         ' // Destroy the icon
         IF hIcon THEN DestroyIcon(hIcon)
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
