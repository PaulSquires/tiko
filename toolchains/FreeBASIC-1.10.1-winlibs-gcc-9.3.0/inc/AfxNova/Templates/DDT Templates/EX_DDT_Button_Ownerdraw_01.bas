'#TEMPLATE DDT Dialog with an ownerdraw button
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

CONST IDC_OK = 1001

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
   DIM hDlg AS HWND = DialogNew(0, "DDT Dialog with an ownerdraw button",50, 50, 175, 65, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add a button to the dialog
   ControlAdd("OwnerdrawButton", hDlg, IDC_OK, "&Ok", 105, 40, 50, 14)

   ' // Anchor the button to the bottom and the right side of the dialog
   ControlAnchor(hDlg, IDC_OK, AFX_ANCHOR_BOTTOM_RIGHT)

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
            CASE IDC_OK
               MsgBox("OK button pressed", MB_ICONEXCLAMATION OR MB_TASKMODAL, "Message")
         END SELECT

      CASE WM_DRAWITEM
         DIM pDis AS DRAWITEMSTRUCT PTR = CAST(DRAWITEMSTRUCT PTR, lParam)
         IF pDis->CtlId <> IDC_OK THEN RETURN FALSE
         ' // Get the rectangle that defines the boundaries of the button to be drawn.
         DIM rc AS RECT = pDis->rcItem
         ' // Create a new font
         DIM hNewFont AS HGDIOBJ = FontNew("Times New Roman", 14, FW_BOLD, TRUE, FALSE, FALSE, DEFAULT_CHARSET)
         ' // Select the font in the button's device context
         DIM hOldFont AS HGDIOBJ = SelectObject(pDis->hDC, hNewFont)
         ' // Draw the button
         IF (pDis->itemState AND ODS_FOCUS) THEN
            DIM hPen AS HPEN = SelectObject(pDis->hDC, CreatePen(PS_SOLID, 3, RGB_RED))
            DIM hBrush AS HBRUSH = SelectObject(pDis->hDC, GetSysColorBrush(COLOR_BTNFACE))
            Rectangle pDis->hDC, rc.Left, rc.Top, rc.Right, rc.Bottom
            SelectObject pDis->hDC, hBrush
            DeleteObject SelectObject(pDis->hDC, hPen)
         ELSE
            FillRect pDis->hDC, @rc, GetSysColorBrush(COLOR_BTNFACE)
         END IF
         ' // Draw the button's edge
         rc.Left += 3: rc.Top += 3 : rc.Bottom -= 3: rc.Right -= 3
         IF (pDis->itemState AND ODS_SELECTED) THEN
            DrawEdge pDis->hDC, @rc, BDR_SUNKEN, BF_RECT OR BF_MIDDLE OR BF_SOFT
            rc.Left += 2 : rc.Top += 2
         ELSE
            DrawEdge pDis->hDC, @rc, BDR_RAISED, BF_RECT OR BF_MIDDLE OR BF_SOFT
         END IF
         ' // Draw the button's caption
         SetBkMode pDis->hDC, TRANSPARENT
         SetTextColor pDis->hDC, IIF((pDis->itemState AND ODS_DISABLED), GetSysColor(COLOR_GRAYTEXT), GetSysColor(COLOR_BTNTEXT))
         DIM wszText AS WSTRING * 260
         GetWindowTextW(pDis->hWndItem, wszText, SIZEOF(wszText)\2)
         DrawTextW pDis->hDC, wszText, -1, @rc, DT_CENTER OR DT_VCENTER ' or DT_SINGLELINE
         SelectObject pDis->hDC, hOldFont
         DeleteObject(hNewFont)
         RETURN TRUE

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
