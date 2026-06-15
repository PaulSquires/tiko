' ########################################################################################
' Microsoft Windows
' File: CW_Button_Ownerdraw_01.bas
' Contents: CWindow - Ownerdraw button
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#INCLUDE ONCE "AfxNova/RGB_Colors.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_BUTTON = 1001

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

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Ownerdraw button", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_GOLD)

   ' // Adds an ownerdraw button
   DIM hButton AS HWND = pWindow.AddControl("Button", hWin, IDC_BUTTON, "Ok", 230, 140, 100, 35, BS_OWNERDRAW)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDC_BUTTON, AFX_ANCHOR_BOTTOM_RIGHT)
   ' // Set the focus on the button
   SetFocus hButton

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
            CASE IDC_BUTTON
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  MessageBoxW hwnd, "Button clicked", "", MB_OK
                  SetFocus GetDlgItem(hwnd, IDC_BUTTON)
               END IF
         END SELECT
         RETURN 0

      CASE WM_DRAWITEM
         DIM pDis AS DRAWITEMSTRUCT PTR = CAST(DRAWITEMSTRUCT PTR, lParam)
         IF pDis->CtlId <> IDC_BUTTON THEN EXIT FUNCTION
         ' // Get the rectangle that defines the boundaries of the button to be drawn.
         DIM rc AS RECT = pDis->rcItem
         ' // Create a new font
         DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
         DIM hNewFont AS HGDIOBJ = pWindow->CreateFont("Times New Roman", 20, FW_BOLD, TRUE, FALSE, FALSE, DEFAULT_CHARSET)
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
         DrawTextW pDis->hDC, wszText, -1, @rc, DT_CENTER OR DT_SINGLELINE
         SelectObject pDis->hDC, hOldFont
         DeleteObject(hNewFont)
         RETURN TRUE

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
