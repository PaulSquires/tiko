' ########################################################################################
' Microsoft Windows
' File: CW_Toolbar_Rebar.bas
' Contents: CWindow - Toolbar inside a rebar
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "CW_Toolbar_HDPI.rc"
#define UNICODE
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxGdiplus.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

CONST IDC_TOOLBAR = 1001
CONST IDC_REBAR = 1002
enum
   IDM_LEFTARROW = 28000
   IDM_RIGHTARROW
   IDM_HOME
   IDM_SAVEFILE
end enum

' // Forward reference
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

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

   DIM pWindow AS CWindow
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Toolbar inside a rebar", @WndProc)
   ' // Sets the client size
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_OLDLACE)

   ' // Adds a tooolbar
   DIM hToolBar AS HWND = pWindow.AddControl("Toolbar", hWin, IDC_TOOLBAR)
   ' // Allow drop down arrows
   SendMessageW hToolBar, TB_SETEXTENDEDSTYLE, 0, TBSTYLE_EX_DRAWDDARROWS

   ' // Calculate the size of the icon according the DPI
   DIM cx AS LONG = 30 * pWindow.DPI \ 96

   ' // Creates an image list for the toolbar
   DIM hNormalImageList AS HIMAGELIST
   hNormalImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
   IF hNormalImageList THEN
      AfxGdipAddIconFromRes(hNormalImageList, hInstance, "IDI_ARROW_LEFT")
      AfxGdipAddIconFromRes(hNormalImageList, hInstance, "IDI_ARROW_RIGHT")
      AfxGdipAddIconFromRes(hNormalImageList, hInstance, "IDI_HOME")
      AfxGdipAddIconFromRes(hNormalImageList, hInstance, "IDI_SAVE")
      ' // Set the normal image list
      Toolbar_SetImageList hToolBar, hNormalImageList
      ' // Set the hot image list with the same images than the normal one
      Toolbar_SetHotImageList hToolBar, hNormalImageList
   END IF

   ' // Creates a disabled image list for the toolbar
   DIM hDisabledImageList AS HIMAGELIST
   hDisabledImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
   IF hDisabledImageList THEN
      AfxGdipAddIconFromRes(hDisabledImageList, hInstance, "IDI_ARROW_LEFT", 60, TRUE)
      AfxGdipAddIconFromRes(hDisabledImageList, hInstance, "IDI_ARROW_RIGHT", 60, TRUE)
      AfxGdipAddIconFromRes(hDisabledImageList, hInstance, "IDI_HOME", 60, TRUE)
      AfxGdipAddIconFromRes(hDisabledImageList, hInstance, "IDI_SAVE", 60, TRUE)
      ' // Set the disabled image list
      Toolbar_SetDisabledImageList hToolBar, hDisabledImageList
   END IF

   ' // Adds buttons to the toolbar
   Toolbar_AddButton hToolBar, 0, IDM_LEFTARROW
   Toolbar_AddButton hToolBar, 1, IDM_RIGHTARROW, 0, BTNS_DROPDOWN
   Toolbar_AddButton hToolBar, 2, IDM_HOME
   Toolbar_AddButton hToolBar, 3, IDM_SAVEFILE

   ' // Disables the save file button
   Toolbar_DisableButton(hToolBar, IDM_SAVEFILE)

   ' // Sizes the toolbar
   Toolbar_AutoSize hToolBar
   ' // Anchors the toolbar
   pWindow.AnchorControl(IDC_TOOLBAR, AFX_ANCHOR_WIDTH)

   ' // Create a rebar control
   DIM hRebar AS HWND = pWindow.AddControl("Rebar", , IDC_REBAR)

   ' // Add the band containing the toolbar control to the rebar
   ' // The size of the REBARBANDINFOW is different in Vista/Windows 7
   DIM rc AS RECT, wszText AS WSTRING * 260
   DIM rbbi AS REBARBANDINFOW
   IF AfxWindowsVersion >= 600 AND AfxComCtlVersion >= 600 THEN
      rbbi.cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      rbbi.cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   ' // Insert the toolbar in the rebar control
   rbbi.fMask      = RBBIM_STYLE OR RBBIM_CHILD OR RBBIM_CHILDSIZE OR _
                     RBBIM_SIZE OR RBBIM_ID OR RBBIM_IDEALSIZE OR RBBIM_TEXT
   rbbi.fStyle     = RBBS_CHILDEDGE
   rbbi.hwndChild  = hToolbar
   rbbi.cxMinChild = 200 * pWindow.rxRatio
   rbbi.cyMinChild = Toolbar_GetButtonHeight(hToolbar)
   rbbi.cx         = 200 * pWindow.rxRatio
   rbbi.cxIdeal    = 200 * pWindow.rxRatio
   wszText = "Toolbar"
   rbbi.lpText = @wszText
   '// Insert band into rebar
   Rebar_InsertBand(hRebar, -1, @rbbi)
   ' // Anchor the rebar
   pWindow.AnchorControl(IDC_REBAR, AFX_ANCHOR_WIDTH)

   ' // Adds a cancel button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Processes event messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         EXIT FUNCTION

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
               END IF
            CASE IDM_LEFTARROW
               MessageBoxW hwnd, "You have clicked the left arrow button", "Toolbar", MB_OK
            CASE IDM_RIGHTARROW
               MessageBoxW hwnd, "You have clicked the right arrow button", "Toolbar", MB_OK
            CASE IDM_HOME
               MessageBoxW hwnd, "You have clicked the home button", "Toolbar", MB_OK
            CASE IDM_SAVEFILE
               MessageBoxW hwnd, "You have clicked the save button", "Toolbar", MB_OK
         END SELECT

      CASE WM_NOTIFY
         ' -------------------------------------------------------
         ' Notification messages are handled here.
         ' The TTN_GETDISPINFO message is sent by a ToolTip control
         ' to retrieve information needed to display a ToolTip window.
         ' ------------------------------------------------------
         DIM ptnmhdr AS NMHDR PTR              ' // Information about a notification message
         DIM ptttdi AS NMTTDISPINFOW PTR       ' // Tooltip notification message information
         DIM wszTooltipText AS WSTRING * 260   ' // Tooltip text
         ptnmhdr = CAST(NMHDR PTR, lParam)
         SELECT CASE ptnmhdr->code
            CASE TTN_GETDISPINFOW
               ptttdi = CAST(NMTTDISPINFOW PTR, lParam)
               ptttdi->hinst = NULL
               wszTooltipText = ""
               SELECT CASE ptttdi->hdr.hwndFrom
                  CASE SendMessageW(GetDlgItem(hwnd, IDC_TOOLBAR), TB_GETTOOLTIPS, 0, 0)
                     SELECT CASE ptttdi->hdr.idFrom
                        CASE IDM_LEFTARROW  : wszTooltipText = "Back"
                        CASE IDM_RIGHTARROW : wszTooltipText = "Forward"
                        CASE IDM_HOME       : wszTooltipText = "Home"
                        CASE IDM_SAVEFILE   : wszTooltipText = "Save"
                     END SELECT
                     IF LEN(wszTooltipText) THEN ptttdi->lpszText = @wszTooltipText
               END SELECT
         CASE TBN_DROPDOWN   ' // dropdown menu
            DIM ptbn AS TBNOTIFY PTR = CAST(TBNOTIFY PTR, lParam)
            SELECT CASE ptbn->iItem
               CASE IDM_RIGHTARROW
                  DIM rc AS RECT
                  SendMessageW(ptbn->hdr.hwndFrom, TB_GETRECT, ptbn->iItem, CAST(LPARAM, @rc))
                  MapWindowPoints(ptbn->hdr.hwndFrom, HWND_DESKTOP, CAST(LPPOINT, @rc), 2)
                  DIM hPopupMenu AS HMENU = CreatePopUpMenu
                  AppendMenuW hPopupMenu, MF_ENABLED, 10001, "Option 1"
                  AppendMenuW hPopupMenu, MF_ENABLED, 10002, "Option 2"
                  AppendMenuW hPopupMenu, MF_ENABLED, 10003, "Option 3"
                  AppendMenuW hPopupMenu, MF_ENABLED, 10004, "Option 4"
                  AppendMenuW hPopupMenu, MF_ENABLED, 10005, "Option 5"
                  DIM flags AS DWORD = TPM_LEFTBUTTON OR TPM_NONOTIFY OR TPM_RETURNCMD OR TPM_NOANIMATION
                  DIM id AS LONG = TrackPopupMenu(hPopupMenu, flags, rc.Left, rc.Bottom, 0, hwnd, NULL)
                  SELECT CASE id
                     CASE 10001
                        MessageBoxW(hwnd, "You clicked item 1", "Message", MB_OK)
                     CASE 10002
                        MessageBoxW(hwnd, "You clicked item 2", "Message", MB_OK)
                     CASE 10003
                        MessageBoxW(hwnd, "You clicked item 3", "Message", MB_OK)
                     CASE 10004
                        MessageBoxW(hwnd, "You clicked item 4", "Message", MB_OK)
                     CASE 10005
                        MessageBoxW(hwnd, "You clicked item 5", "Message", MB_OK)
                  END SELECT
                  DestroyMenu hPopupMenu
            END SELECT
         END SELECT

    	CASE WM_DESTROY
         ' // Destroy the image lists
         ImageList_Destroy CAST(HIMAGELIST, SendMessageW(GetDlgItem(hwnd, IDC_TOOLBAR), TB_SETIMAGELIST, 0, 0))
         ImageList_Destroy CAST(HIMAGELIST, SendMessageW(GetDlgItem(hwnd, IDC_TOOLBAR), TB_SETHOTIMAGELIST, 0, 0))
         ImageList_Destroy CAST(HIMAGELIST, SendMessageW(GetDlgItem(hwnd, IDC_TOOLBAR), TB_SETDISABLEDIMAGELIST, 0, 0))
         ' // Quit the application
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
