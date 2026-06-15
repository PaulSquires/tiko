' ########################################################################################
' Microsoft Windows
' File: CW_ListView_CheckBoxes_01b.bas
' Contents: ListView control
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CListView.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

#define IDC_LISTVIEW 1001

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

   ' // Create the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - ListView control", @WndProc)
   ' // Size it by setting the wanted width and height of its client area
   pWindow.SetClientSize(280, 280)
   ' // Center the window
   pWindow.Center

   ' // Adds a listview
   DIM hListView AS HWND = pWindow.AddControl("ListView", hWin, IDC_LISTVIEW, "", 10, 10, 260, 260)
   CListview.AddColumn(hListview, 0, "Common Controls", pWindow.ScaleX(227), LVCFMT_LEFT)
   CListview.AddItem(hListview, 0, 0, "Buttons")
   CListview.AddItem(hListview, 1, 0, "Checkboxes")
   CListview.AddItem(hListview, 2, 0, "Comboboxes")
   CListview.AddItem(hListview, 3, 0, "Custom Controls")
   CListview.AddItem(hListview, 4, 0, "Frames")
   CListview.AddItem(hListview, 5, 0, "Graphics")
   CListview.AddItem(hListview, 6, 0, "Labels")
   CListview.AddItem(hListview, 7, 0, "Listboxes")
   CListview.AddItem(hListview, 8, 0, "Listviews")
   CListview.AddItem(hListview, 9, 0, "Radio Buttons")
   CListview.AddItem(hListview, 10, 0, "Textboxes")
   DIM LV_Style AS DWORD = CListView.GetExtendedListViewStyle(hListView)
   CListView.SetExtendedListViewStyle(hListView, LV_Style XOR LVS_EX_CHECKBOXES OR LVS_EX_INFOTIP)

   ' // Set the text color of the ListView
   CListView.SetTextColor(hListView, RGB_BLUE)
   
   ' // Anchor the ListView
   pWindow.AnchorControl(IDC_LISTVIEW, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Optinal: Set the font of the tooltips
   DIM hTooltipFont AS HFONT = pWindow.CreateFont("Times New Roman", 10, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET)
   DIM hwndTooltip AS HWND = CListView.GetToolTips(hListview)
   IF hwndTooltip THEN AfxSetWindowFont(hwndTooltip, hTooltipFont)

   ' // Select the fist item (ListView items are zero based)
   CListView.SelectItem(hListView, 0)
   ' // Set the focus in the ListView
   SetFocus hListView

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

   ' // Delete the tooltip font
   IF hTooltipFont THEN DeleteObject hTooltipFont

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
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         ' // Listview Tooltips
         DIM wszText AS WSTRING * 80
         DIM infoTip AS NMLVGETINFOTIPW
         infotip.cchTextMax = 80
         CBNMTypeset(infoTip, wParam, lParam)
         IF infoTip.hdr.code = LVN_GETINFOTIPW AND infoTip.hdr.idFrom = IDC_LISTVIEW THEN
            SELECT CASE infoTip.iItem
               CASE  0 : wszText = "Add Buttons"
               CASE  1 : wszText = "Add Checkbox Controls"
               CASE  2 : wszText = "Add Combobox Controls"
               CASE  3 : wszText = "Add Custom Controls"
               CASE  4 : wszText = "Add Frame Controls"
               CASE  5 : wszText = "Add Graphic Controls"
               CASE  6 : wszText = "Add Label Controls"
               CASE  7 : wszText = "Add Listbox Controls"
               CASE  8 : wszText = "Add Listview Controls"
               CASE  9 : wszText = "Add Radio Button Controls"
               CASE 10 : wszText = "Add Textbox Controls"
            END SELECT
            ' // Assign the tooltip text to the tooltip buffer
            IF LEN(wszText) THEN *infoTip.pszText = wszText
         END IF

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
