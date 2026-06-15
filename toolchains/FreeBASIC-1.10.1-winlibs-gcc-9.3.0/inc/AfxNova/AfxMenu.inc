' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxMenu.inc
' Contents: Menu wrapper functions
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2025 José Roca
'
' License: Distributed under the MIT license.
'
' Permission is hereby granted, free of charge, to any person obtaining a copy of this
' software and associated documentation files (the “Software”), to deal in the Software
' without restriction, including without limitation the rights to use, copy, modify, merge,
' publish, distribute, sublicense, and/or sell copies of the Software, and to permit
' persons to whom the Software is furnished to do so, subject to the following conditions:

' The above copyright notice and this permission notice shall be included in all copies or
' substantial portions of the Software.

' THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
' INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
' PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
' FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
' OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
' DEALINGS IN THE SOFTWARE.'
' ########################################################################################

#pragma once
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/DWSTRING.inc"
#INCLUDE ONCE "AfxNova/AfxWin.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' Destroys the specified menu and frees any memory that the menu occupies.
' ========================================================================================
PRIVATE FUNCTION AfxDestroyMenu OVERLOAD (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN DestroyMenu(hMenu)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Destroys the menu attached to a window or dialog and frees any memory that the menu occupies.
' ========================================================================================
PRIVATE FUNCTION AfxDestroyMenu OVERLOAD (BYVAL hwnd AS HWND) AS BOOLEAN
   ' // Get the menu handle, if any
   DIM hMenu AS HMENU = GetMenu(hwnd)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Detach the menu from the dialog
   SetMenu(hwnd, NULL)
   ' // Destroy the menu
   RETURN DestroyMenu(hMenu)
   ' // Redraw the menu bar
   DrawMenuBar(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: The return value specifies the previous state of the menu item (either
' MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.
' ========================================================================================
PRIVATE FUNCTION AfxCheckMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   dwFlags = dwFlags OR MF_CHECKED
   RETURN CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unchecks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: The return value specifies the previous state of the menu item (either
' MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.
' ========================================================================================
PRIVATE FUNCTION AfxUnCheckMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   dwFlags = dwFlags OR MF_UNCHECKED
   RETURN CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Toggles the checked state of a menu item.
' ========================================================================================
PRIVATE FUNCTION AfxToggleMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF GetMenuState(hMenu, uItem, dwFlags) AND MF_CHECKED = MF_CHECKED THEN
      dwFlags = dwFlags OR MF_UNCHECKED
   ELSE
      dwFlags = dwFlags OR MF_CHECKED
   END IF
   RETURN CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is checked; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemChecked (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF GetMenuState(hMenu, uItem, dwFlags) AND MF_CHECKED = MF_CHECKED THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is enabled; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemEnabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_DISABLED) <> MF_DISABLED) AND ((dwRes AND MF_GRAYED) <> MF_GRAYED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is disabled; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemDisabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_DISABLED) = MF_DISABLED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is grayed; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemGrayed (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_GRAYED) = MF_GRAYED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is highlighted; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemHighlighted (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_HILITE) = MF_HILITE) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is a separator; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemSeparator (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_SEPARATOR) = MF_SEPARATOR) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is a submenu; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemPopup (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_POPUP) = MF_POPUP) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsMenuItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_OWNERDRAW) = MF_OWNERDRAW) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the state of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: 0 on failure or one or more of the following values:
' - MFS_CHECKED   The item is checked
' - MFS_DEFAULT   The menu item is the default.
' - MFS_DISABLED  The item is disabled.
' - MFS_ENABLED   The item is enabled.
' - MFS_GRAYED    The item is grayed.
' - MFS_HILITE    The item is highlighted
' - MFS_UNCHECKED The item is unchecked.
' - MFS_UNHILITE  The item is not highlighed.
' Note: To get extended error information, use the GetLastError function.
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) = 0 THEN RETURN 0
   RETURN mii.fState
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the state of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fState = The menu item state. It can be one or more of these values:
' - MFS_CHECKED   Checks the menu item.
' - MFS_DEFAULT   Specifies that the menu item is the default.
' - MFS_DISABLED  Disables the menu item and grays it so that it cannot be selected.
' - MFS_ENABLED   Enables the menu item so that it can be selected. This is the default state.
' - MFS_GRAYED    Disables the menu item and grays it so that it cannot be selected.
' - MFS_HILITE    Highlights the menu item.
' - MFS_UNCHECKED Unchecks the menu item.
' - MFS_UNHILITE  Removes the highlight from the menu item. This is the default state.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION AfxSetMenuItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fState AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = fState
   RETURN SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION AfxEnableMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_ENABLED
   RETURN SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION AfxDisableMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_DISABLED
   RETURN SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Grays the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION AfxGrayMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_GRAYED
   RETURN SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Highlights the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION AfxHiliteMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_HILITE
   RETURN SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the system menu close option and disables the X button.
' Parameter: hwnd = Handle of the window that owns the menu.
' Return value: TRUE of FALSE.
' Note: To restore the close menu, call GetSystemMenu(hwnd, TRUE)
' ========================================================================================
PRIVATE FUNCTION AfxRemoveCloseMenu (BYVAL hwnd AS HWND) AS BOOLEAN
   ' // Get the system menu handle
   DIM hMenu AS HMENU = GetSystemMenu(hwnd, 0)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Get the number of menu items
   DIM cbItems AS LONG = GetMenuItemCount(hMenu)
   IF cbItems = 0 THEN RETURN FALSE
   ' // Remove the close menu item
   IF RemoveMenu(hMenu, cbItems - 1, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Remove the separator line
   IF RemoveMenu(hMenu, cbItems - 2, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Redraw the menu (this refreshes the caption bar, dimming the X button)
   DrawMenuBar(hwnd)
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Right justifies a top level menu item. This is usually used to have the Help menu item
' right-justified on the menu bar.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - uItem = [in] The zero-based position of the menu item to change.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxRightJustifyMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fState = MFS_DEFAULT
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU
   IF GetMenuItemInfoW(hMenu, uItem, CTRUE, @mii) THEN
      mii.fType = mii.fType OR MF_HELP
      RETURN SetMenuItemInfoW(hMenu, uItem, CTRUE, @mii)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the text of a menu item to bold.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - uItem = [in] The zero-based position of the menu item to change.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxSetMenuItemBold (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU OR MIIM_STATE
   IF GetMenuItemInfoW(hMenu, uItem, TRUE, @mii) THEN
      mii.fState = mii.fState OR &H1000
      RETURN SetMenuItemInfoW(hMenu, uItem, CTRUE, @mii)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - wszText = Text to set.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxSetMenuItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYREF wszText AS WSTRING, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = @wszText
   RETURN SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the lengnth of the specified menu item.
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuItemTextLen (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
   ' // Fills the MENUITEMINFOW structure
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = NULL
   ' // Get the needed size of the buffer
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) = 0 THEN RETURN 0
   RETURN mii.cch
END FUNCTION

' ========================================================================================
' Retrieves the text of the specified menu item.
' - hMenu = Handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' - pwszText: A pointer to a buffer to receive the retrieved text.
' - cchTextMax : Maximum number of characters to return. Both this value and the size of the
'      buffer pointed by pwszText must be one character bigger that the wanted length of the text
'      to return to make room for the null character terminator.
' Return value: TRUE or FALSE.
' Usage example:
' DIM wsz AS WSTRING * 260
' AfxGetMenuItemText(hSubMenu, 1, TRUE, @wsz, 260)
' AfxMsg wsz
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuItemText OVERLOAD (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
   IF pwszText = NULL THEN RETURN FALSE
   ' // Fills the MENUITEMINFOW structure
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = pwszText
   mii.cch = cchTextMax
   RETURN GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuItemText OVERLOAD (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG) AS DWSTRING
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = NULL
   ' // Get the needed size of the buffer
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) = 0 THEN RETURN ""
   ' // Make room for the trailing null
   mii.cch += 1
   ' // Allocate the buffer
   DIM buffer AS DWSTRING = WSPACE(mii.cch)
   ' // Get the menu string
   mii.dwTypeData = cast(WSTRING PTR, *buffer)
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) THEN
      RETURN RTRIM(buffer, CHR(0))
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the font used in menu bars.
' Return value: TRUE on succes or FALSE on failure.
' If the function fails, the return value is zero.
' To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuFont (BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
   DIM ncm AS NONCLIENTMETRICSW
   IF plfw = NULL THEN RETURN FALSE
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) <> 0 THEN RETURN FALSE
   *plfw = ncm.lfMenuFont
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the point size of the font used in menu bars.
' If the function fails, the return value is 0.
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuFontPointSize () AS LONG
   DIM ncm AS NONCLIENTMETRICSW
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) = 0 THEN RETURN 0
   DIM hDC AS HDC = CreateDCW("DISPLAY", NULL, NULL, NULL)
   IF hDC = NULL THEN RETURN 0
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   DeleteDC hDC
   DIM nPointSize AS LONG = MulDiv(ncm.lfMenuFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   RETURN nPointSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the size of a menu bar or a drop-down menu.
' - hwnd = Handle of the window that owns the menu.
' - hmenu = Handle of the menu.
' - prcmenu = Pointer to a variable of type RECT where to return the retrieved values.
' Return Value:
' If the function succeeds, the return value is 0.
' If the function fails, the return value is a system error code.
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL prcmenu AS RECT PTR) AS LONG
   DIM i AS LONG, nRes AS LONG, rc AS RECT
   FOR i = 1 TO GetMenuItemCount(hmenu)
      nRes = GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      UnionRect prcmenu, prcmenu, @rc
   NEXT
   RETURN nRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetMenuRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU) AS RECT
   DIM i AS LONG, nRes AS LONG, rc AS RECT, rcMenu AS RECT
   FOR i = 1 TO GetMenuItemCount(hmenu)
      nRes = GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      UnionRect @rcMenu, @rcMenu, @rc
   NEXT
   RETURN rcMenu
END FUNCTION
' ========================================================================================

' ########################################################################################
'                              *** VISUAL STYLE MENUS ***
' ########################################################################################

' Windows Vista and posterior Windows versions provide menus that are part of the visual
' schema. These menus are rendered using visual styles, which can be added to existing
' applications. Adding code for new features to existing code must be done carefully to
' avoid breaking existing application behavior. Certain situations can cause visual styling
' to be disabled in an application. These situations include:
'    - Customizing menus using owner-draw menu items (MFT_OWNERDRAW)
'    - Using menu breaks (MFT_MENUBREAK or MFT_MENUBARBREAK)
'    - Using HBMMENU_CALLBACK to defer bitmap rendering
'    - Using a destroyed menu handle
' These situations prevent visual style menus from being rendered. Owner-draw menus can be
' used in Windows Vista and posterior Windows versions, but the menus will not be visually
' styled.
' Windows Vista and posterior Windows versions provide alpha-blended bitmaps, which enables
' menu items to be shown without using owner-draw menu items.
' Requirements:
'    - The bitmap is a 32bpp DIB section.
'    - The DIB section has BI_RGB compression.
'    - The bitmap contains pre-multiplied alpha pixels.
'    - The bitmap is stored in hbmpChecked, hbmpUnchecked, or hbmpItem fields.
' Note: MFT_BITMAP items do not support PARGB32 bitmaps.
' The following functions use the the Graphics Device Interface (GDI) to convert icons to
' bitmaps. Another solution is to use the Windows Imaging Component (WIC).
' Usage example:
'    DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
'    DIM hIcon AS HICON
'    hIcon = LoadImageW(NULL, "MyIcon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE)
'    IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
' PNG icons can be used by converting them to an icon with AfxGdipImageFromFile:
'    hIcon = AfxGdipImageFromFile("MyIcon.png")
'    IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)

#if _WIN32_WINNT = &h0602
' ========================================================================================
' Initializes the BITMAPINFO structure
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxInitBitmapInfo (BYVAL pbmi AS BITMAPINFO PTR, BYVAL cbInfo AS ULONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL bpp AS WORD) AS BOOLEAN
   IF pbmi = NULL THEN RETURN FALSE
   memset(pbmi, 0, cbInfo)
   pbmi->bmiHeader.biSize = SIZEOF(BITMAPINFOHEADER)
   pbmi->bmiHeader.biPlanes = 1
   pbmi->bmiHeader.biCompression = BI_RGB
   pbmi->bmiHeader.biWidth = cx
   pbmi->bmiHeader.biHeight = cy
   pbmi->bmiHeader.biBitCount = bpp
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a 32bpp and a BI_RGB DIB section.
' Paramaters:
' - hDC     = Handle to the device context.
' - psize   = Size of the icon
' - ppvBits = A pointer to a variable that receives a pointer to the location of the
'             DIB bit values. Can be NULL.
' - phbmp   = A pointer to a variable that receives the handle to the newly created DIB.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxCreate32BitHBITMAP (BYVAL hDC AS HDC, BYVAL psize AS SIZE PTR, BYVAL ppvBits AS ANY PTR PTR, BYVAL phBmp AS HBITMAP PTR) AS BOOLEAN
   IF psize = NULL OR phBmp = NULL THEN RETURN FALSE
   *phBmp = NULL
   DIM bmi AS BITMAPINFO
   AfxInitBitmapInfo(@bmi, SIZEOF(bmi), psize->cx, psize->cy, 32)
   DIM hdcUsed AS ..HDC = IIF(hDC <> NULL, hDC, GetDC(NULL))
   IF hdcUsed = NULL THEN RETURN FALSE
   *phBmp = CreateDIBSection(hdcUsed, @bmi, DIB_RGB_COLORS, ppvBits, NULL, 0)
   ReleaseDC(NULL, hdcUsed)
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a bitmap to the menu item.
' Parameters:
' - hMenu       = A handle to the menu that contains the menu item.
' - nMenuItem   = The identifier or position of the menu item to change.
'                 The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of nMenuItem. If this parameter is FALSE, nMenuItem is a
'                 menu item identifier. Otherwise, it is a menu item position.
' - hbmp        = Bitmap handle.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxAddBitmapToMenuItem (BYVAL hMenu AS HMENU, BYVAL nMenuItem AS LONG, BYVAL fByPosition AS BOOLEAN, BYVAL hbmp AS HBITMAP) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_BITMAP
   mii.hbmpItem = hbmp
   IF SetMenuItemInfoW(hMenu, nMenuItem, fByPosition, @mii) = 0 THEN RETURN FALSE
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Convert a bitmap to a PARGB32 bitmap.
' Parameters:
' - hDC       = Handle of the device context.
' - pargb     = Pointer to the address of the buffer bitmap pixels.
' - hbmp      = Bitmap handle.
' - sizeImage = Size of the bitmap.
' - cxRow     = The width, in pixels, of the buffer bitmap.
'               This value is not necessarily equal to the buffer width. It may be larger.
' Return value: TRUE or FALSE.
' Remarks: MFT_BITMAP items do not support PARGB32 bitmaps.
' ========================================================================================
PRIVATE FUNCTION AfxConvertToPARGB32 (BYVAL hDC AS HDC, BYVAL pargb AS DWORD PTR, BYVAL hbmp AS HBITMAP, BYVAL sizeImage AS SIZE, BYVAL cxRow AS LONG) AS BOOLEAN
   IF hDC = NULL OR pargb = NULL OR hbmp = NULL THEN RETURN FALSE
   DIM bmi AS BITMAPINFO
   AfxInitBitmapInfo(@bmi, SIZEOF(bmi), sizeImage.cx, sizeImage.cy, 32)
   DIM hHeap AS HANDLE = GetProcessHeap
   DIM pvBits AS ANY PTR = HeapAlloc(hHeap, 0, bmi.bmiHeader.biWidth * 4 * bmi.bmiHeader.biHeight)
   IF pvBits THEN
      IF GetDIBits(hDC, hbmp, 0, bmi.bmiHeader.biHeight, pvBits, @bmi, DIB_RGB_COLORS) = bmi.bmiHeader.biHeight THEN
         DIM cxDelta AS ULONG = cxRow - bmi.bmiHeader.biWidth
         DIM pargbMask AS DWORD PTR = CAST(DWORD PTR, pvBits)
         DIM x AS LONG, y AS LONG
         FOR y = bmi.bmiHeader.biHeight TO 1 STEP -1
            FOR x = bmi.bmiHeader.biWidth TO 1 STEP -1
               IF *pargbMask THEN
                  ' // transparent pixel
                  *pargb = 0
                  pargbMask +=1
                  pargb += 1
               ELSE
                  ' // opaque pixel
                  *pargb OR= &hFF000000
                  pargb +=1
               END IF
               pargb += cxDelta
            NEXT
         NEXT
      END IF
   END IF
   HeapFree(hHeap, 0, pvBits)
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks if the bitmap has the alpha channel set.
' Parameters:
' - pargb     = Pointer to the address of the buffer bitmap pixels.
' - sizeImage = Size of the bitmap.
' - cxRow     = The width, in pixels, of the buffer bitmap.
'               This value is not necessarily equal to the buffer width. It may be larger.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxHasAlpha (BYVAL pargb AS DWORD PTR, BYVAL sizeImage AS SIZE, BYVAL cxRow AS LONG) AS BOOLEAN
   IF pargb = NULL THEN RETURN FALSE
   DIM cxDelta AS ULONG = cxRow - sizeImage.cx
   DIM x AS LONG, y AS LONG
   FOR y = sizeImage.cy TO 1 STEP -1
      FOR x = sizeImage.cx TO 1 STEP -1
         IF (*pargb AND &hFF000000) THEN RETURN TRUE
         pargb += 1
      NEXT
      pargb += cxDelta
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a buffered bitmap to an PARGB32 bitmap.
' Parameters:
' - hPaintBuffer = The handle of the buffered paint context, obtained through BeginBufferedPaint.
' - hDC          = The Handle of the device context.
' - hIcon        = The icon handle.
' - sizeIcon     = The size of the icon.
' Return value: An HRESULT code
' ========================================================================================
PRIVATE FUNCTION AfxConvertBufferToPARGB32 (BYVAL hPaintBuffer AS HPAINTBUFFER, BYVAL hDC AS HDC, BYVAL hIcon AS HICON, BYVAL sizeIcon AS SIZE) AS BOOLEAN
   IF hPaintBuffer = NULL OR hDC = NULL OR hIcon = NULL THEN RETURN FALSE
   DIM prgbQuad AS RGBQUAD PTR, cxRow AS LONG
   DIM hr AS HRESULT
   hr = GetBufferedPaintBits(hPaintBuffer, @prgbQuad, @cxRow)
   IF SUCCEEDED(hr) THEN
      DIM pargb AS DWORD PTR = CAST(DWORD PTR, prgbQuad)
      IF NOT AfxHasAlpha(pargb, sizeIcon, cxRow) THEN
         DIM info AS ICONINFO
         IF GetIconInfo(hicon, @info) THEN
            IF info.hbmMask THEN
               hr = AfxConvertToPARGB32(hDC, pargb, info.hbmMask, sizeIcon, cxRow)
               DeleteObject(info.hbmColor)
               DeleteObject(info.hbmMask)
            END IF
         END IF
      END IF
   END IF
   IF SUCCEEDED(hr) THEN RETURN TRUE ELSE RETURN FALSE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a hIcon to a bitmap and adds it to the specified hbmpItem field of HMENU item.
' The caller is responsible for destroying the bitmap generated. The icon will be destroyed
' if fAutoDestroy is set to true. The hbmpItem field of the menu item can be used to keep
' track of the bitmap by passing NULL to phbmp.
' Parameters:
' - hMenu        = Menu handle that contains the item to which an icon will be added.
' - uItem        = The identifier or position of the menu item to change.
'                  The meaning of this parameter depends on the value of fByPosition.
' - fByPosition  = The meaning of nMenuItem. If this parameter is FALSE, nMenuItem is a
'                  menu item identifier. Otherwise, it is a menu item position.
' - hIcon        = Handle of the icon to add to the menu.
' - fAutoDestroy = TRUE (the default) or FALSE.
'                  If TRUE, AfxAddIconToMenuItem destroys the icon before returning.
' - phbmp        = Location where the bitmap representation of the icon is stored. Can be NULL.
' ========================================================================================
PRIVATE FUNCTION AfxAddIconToMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
   IF hMenu = NULL OR hIcon = NULL THEN RETURN FALSE
   DIM hbmp AS HBITMAP, sizIcon AS SIZE, rcIcon AS RECT
   sizIcon.cx = GetSystemMetrics(SM_CXSMICON)
   sizIcon.cy = GetSystemMetrics(SM_CYSMICON)
   SetRect(@rcIcon, 0, 0, sizIcon.cx, sizIcon.cy)
   DIM hdcDest AS HDC = CreateCompatibleDC(NULL)
   IF hdcDest = NULL THEN RETURN FALSE
   DIM hr AS HRESULT = AfxCreate32BitHBITMAP(hdcDest, @sizIcon, NULL, @hbmp)
   IF hr THEN
      DIM hbmpOld AS HBITMAP = CAST(HBITMAP, SelectObject(hdcDest, hbmp))
      IF hbmpOld THEN
         DIM bfAlpha AS BLENDFUNCTION = (AC_SRC_OVER, 0, 255, AC_SRC_ALPHA)
         DIM paintParams AS BP_PAINTPARAMS
         paintParams.cbSize = SIZEOF(paintParams)
         paintParams.dwFlags = BPPF_ERASE
         paintParams.pBlendFunction = @bfAlpha
         DIM hdcBuffer AS HDC
         DIM hPaintBuffer AS HPAINTBUFFER = BeginBufferedPaint(hdcDest, @rcIcon, BPBF_DIB, @paintParams, @hdcBuffer)
         IF hPaintBuffer THEN
            IF DrawIconEx(hdcBuffer, 0, 0, hIcon, sizIcon.cx, sizIcon.cy, 0, NULL, DI_NORMAL) THEN
               ' // If icon did not have an alpha channel, we need to convert buffer to PARGB32.
               hr = AfxConvertBufferToPARGB32(hPaintBuffer, hdcDest, hIcon, sizIcon)
            END IF
            ' // This will write the buffer contents to the destination bitmap.
            EndBufferedPaint(hPaintBuffer, TRUE)
         END IF
         SelectObject(hdcDest, hbmpOld)
      END IF
   END IF
   DeleteDC(hdcDest)
   IF hr THEN hr = AfxAddBitmapToMenuItem(hMenu, uItem, fByPosition, hbmp)
   IF hr = FALSE THEN DeleteObject(hbmp): hbmp = NULL
   IF fAutoDestroy THEN DestroyIcon(hIcon)
   IF phbmp THEN *phbmp = hbmp
   RETURN hr
END FUNCTION
#endif
' ========================================================================================

' ########################################################################################
'                                *** DDT MENU WRAPPERS ***
' ########################################################################################

' ========================================================================================
' * Creates a new menu bar
' ========================================================================================
PRIVATE FUNCTION MenuNewBar () AS HMENU
   RETURN CreateMenu
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a handle to the menu assigned to the specified window or dialog. 
' ========================================================================================
PRIVATE FUNCTION MenuGetHandle (BYVAL hwnd AS HWND) AS HMENU
   RETURN GetMenu(hwnd)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Enables the application to access the window menu (also known as the system menu
' or the control menu) for copying and modifying.
' ========================================================================================
PRIVATE FUNCTION MenuGetSystemMenuHandle (BYVAL hwnd AS HWND, BYVAL bRevert AS BOOLEAN = FALSE) AS HMENU
   RETURN GetSystemMenu(hwnd, bRevert)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.
' ========================================================================================
PRIVATE FUNCTION MenuGetSubMenu (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS HMENU
   nPos -= 1 : IF nPos < 0 THEN nPos = 0
   RETURN GetSubMenu(hMenu, nPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the menu item ID of a menu item located at the specified position in a menu.
' Usage example: MenuGetItemID(MenuGetSubMenu(hMenu, 1), 1)
' - Returms the identifier of the first item of the first submenu.
' ========================================================================================
PRIVATE FUNCTION MenuGetItemID (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS UINT
   nPos -= 1 : IF nPos < 0 THEN nPos = 0
   RETURN GetMenuItemID(hMenu, nPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of submenus of a menu.
' ========================================================================================
PRIVATE FUNCTION MenuGetSubmenusCount(BYVAL hMenu AS HMENU) AS LONG
   DIM itemCount AS LONG = GetMenuItemCount(hMenu)
   DIM submenuCount AS LONG
   FOR i AS LONG = 0 TO itemCount - 1
      IF GetSubMenu(hMenu, i) <> 0 THEN submenuCount += 1
   NEXT
   RETURN submenuCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the window owner of the specified menu
' ========================================================================================
PRIVATE FUNCTION MenuGetWindowOwner (BYVAL hMenu AS HMENU) AS HWND
   DIM hwnd As HWND = GetTopWindow(NULL)
   WHILE hwnd <> 0
      IF GetMenu(hwnd) = hMenu THEN
         RETURN hwnd ' Found the window owner
      END IF
      hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)
   WEND
   RETURN NULL ' Not found
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a new popup menu
' ========================================================================================
PRIVATE FUNCTION MenuNewPopup () AS HMENU
   RETURN CreatePopupMenu
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds a popup child menu to an existing menu.
' ========================================================================================
PRIVATE FUNCTION MenuAddPopup (BYVAL hMenu AS HMENU, BYREF wszText AS WSTRING, BYVAL hPopup AS HMENU, _
BYVAL fState AS UINT, BYVAL item AS LONG = 0, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   fState = fState OR MF_POPUP
   IF item = 0 THEN RETURN AppendMenuW(hMenu, fState, CAST(UINT_PTR, hPopup), @wszText)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_SUBMENU OR MIIM_STRING OR MIIM_ID
   mii.hSubMenu = hPopup
   mii.dwTypeData = @wszText
   IF fByPosition = FALSE THEN mii.wID = item   '// it is not a position but an identifier
   IF fByPosition = TRUE THEN item -= 1
   IF InsertMenuItemW(hMenu, item, fByPosition, @mii) = FALSE THEN RETURN FALSE
   mii.fMask = MIIM_STATE
   mii.fState = fState
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds the position of the specified menu item.
' Example:
'   DIM nPos AS LONG
'   MenuFindItemPosition(hMenu, ID_EXIT, nPos)
'Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION MenuFindItemPosition OVERLOAD (BYVAL hMenu AS HMENU, BYVAL itemID AS UINT, BYREF itemPos AS LONG) AS BOOLEAN
   DIM itemCount AS LONG = GetMenuItemCount(hMenu)
   FOR i AS LONG = 0 TO itemCount - 1
      DIM currentID AS UINT = GetMenuItemID(hMenu, i)
      ' If the item matches, return its absolute position
      IF currentID = itemID THEN
         itemPos = i
         RETURN TRUE
      END IF
      ' Check if the item is a submenu
      DIM hSubMenu AS ..HMENU = GetSubMenu(hMenu, i)
      IF hSubMenu <> 0 THEN
         ' Recursively search the submenu
         IF MenuFindItemPosition(hSubMenu, itemID, itemPos) THEN
            itemPos = itemPos + i + 1 ' Adjust position relative to parent menu
            RETURN TRUE
         END IF
      END IF
   NEXT
   RETURN FALSE ' Item not found
END FUNCTION
' ========================================================================================
' ========================================================================================
' Example:
'   DIM nPos AS LONG = MenuFindItemPosition(hMenu, ID_EXIT)
'Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION MenuFindItemPosition OVERLOAD (BYVAL hMenu AS HMENU, BYVAL itemID AS UINT) AS LONG
   DIM itemPos AS LONG
   MenuFindItemPosition(hMenu, itemID, itemPos)
   RETURN itemPos
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds a string or separator to an existing menu.
' Usage examples:
' MenuAddString hPopup1, "&Open", ID_OPEN, MF_ENABLED
' Insert the item before the ID_OPEN item
' MenuAddString hPopup1, "&Exit", ID_EXIT, MF_ENABLED, 1, TRUE          ' insert by position
' MenuAddString hPopup1, "&Exit", ID_EXIT, MF_ENABLED, ID_OPEN, FALSE   ' insert by identifier
' ========================================================================================
PRIVATE FUNCTION MenuAddString OVERLOAD (BYVAL hMenu AS HMENU, BYREF wszText AS WSTRING, BYVAL id AS LONG, _
BYVAL fState AS UINT, BYVAL item AS LONG = 0, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   IF wszText = "-" THEN RETURN AppendMenuW(hMenu, MF_SEPARATOR, 1, "")
   ' // If fByPosition = FALSE and item > 0, it is a menu identifier
   IF fByPosition = FALSE AND item > 0 THEN
      ' // Find the item position
      DIM itemPos AS LONG
      IF MenuFindItemPosition (hMenu, item, itemPos) THEN
         ' // If found, insert the item before that position
         IF itemPos THEN
            item = itemPos
            fByPosition = TRUE
         END IF
      END IF
   END IF
   IF fByPosition THEN
      ' // If the position is <=0, append the item into the menu
      IF item <= 0 THEN RETURN AppendMenuW(hMenu, fState, id, @wszText)
      ' // else adjust the position from 0-based to one-based
      item -= 1
   END IF
   ' // Insert the item into the menu
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = @wszText
   IF InsertMenuItemW(hMenu, item, fByPosition, @mii) = FALSE THEN RETURN FALSE
   mii.fMask = MIIM_STATE
   mii.fState = fState
   mii.fMask = MIIM_ID
   mii.wID = id
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Attaches a menu to a window or dialog.
' ========================================================================================
PRIVATE FUNCTION MenuAttach (BYVAL hMenu AS HMENU, BYVAL hwnd AS HWND) AS BOOLEAN
   RETURN SetMenu(hwnd, hMenu)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes a menu item from an existing menu.
' If it returns TRUE, call DrawMenuBar(hwnd).
' ========================================================================================
PRIVATE FUNCTION MenuDelete (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM uFlags AS UINT
   IF fByPosition = TRUE THEN uFlags = MF_BYPOSITION ELSE uFlags = MF_BYCOMMAND
   FUNCTION = RemoveMenu(hMenu, item, uFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Destroys the main menu from the window or dialog.
' hwnd = Handle of the window or dialog that owns the menu.
' ========================================================================================
PRIVATE FUNCTION MenuDestroy OVERLOAD (BYVAL hwnd AS HWND) AS BOOLEAN
   ' // Get the menu
   DIM hMenu AS HMENU = GetMenu(hwnd)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Detach the menu
   SetMenu(hwnd, NULL)
   ' // Destroy the menu
   IF DestroyMenu(hMenu) THEN
      ' // Redraw the menu
      DrawMenuBar hwnd
      RETURN TRUE
   ELSE
      RETURN FALSE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Destroys the specified menu and frees any memory that the menu occupies.
' Before closing, an application must use the MenuDestroy function to destroy a menu not
' assigned to a window. A menu that is assigned to a window is automatically destroyed when
' the application closes.
' MenuDestroy is recursive, that is, it will destroy the menu and all its submenus.
' ========================================================================================
PRIVATE FUNCTION MenuDestroy OVERLOAD (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN DestroyMenu(hMenu)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Redraws the menu bar of the specified window or dialog. If the menu bar changes after the
' system has created the window or dialog, this function must be called to draw the changed menu bar.
' ========================================================================================
PRIVATE FUNCTION MenuDrawBar (BYVAL hwnd AS HWND) AS BOOLEAN
   RETURN DrawMenuBar(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the lengnth of the text of the specified menu item.
' ========================================================================================
PRIVATE FUNCTION MenuGetTextLen (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS LONG
   ' // Fills the MENUITEMINFOW structure
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = NULL
   ' // Get the needed size of the buffer
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   IF GetMenuItemInfoW(hMenu, item, fByPosition, @mii) = 0 THEN RETURN 0
   RETURN mii.cch
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text of the specified menu item.
' - hMenu = Handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return value: The retrieved text.
' ========================================================================================
PRIVATE FUNCTION MenuGetText (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS DWSTRING
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM wszText AS WSTRING * 260
   mii.dwTypeData = @wszText
   mii.cch = 260
   IF GetMenuItemInfoW(hMenu, item, fByPosition, @mii) THEN
      RETURN wszText
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - wszText = Text to set.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION MenuSetText (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYREF wszText AS WSTRING, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = @wszText
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the state of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: 0 on failure or one or more of the following values:
' - MFS_CHECKED   The item is checked
' - MFS_DEFAULT   The menu item is the default.
' - MFS_DISABLED  The item is disabled.
' - MFS_ENABLED   The item is enabled.
' - MFS_GRAYED    The item is grayed.
' - MFS_HILITE    The item is highlighted
' - MFS_UNCHECKED The item is unchecked.
' - MFS_UNHILITE  The item is not highlighted.
' Note: To get extended error information, use the GetLastError function.
' ========================================================================================
PRIVATE FUNCTION MenuGetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS UINT
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   IF GetMenuItemInfoW(hMenu, item, fByPosition, @mii) = 0 THEN RETURN 0
   RETURN mii.fState
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Toggles the checked state of a menu item.
' ========================================================================================
PRIVATE FUNCTION MenuItemToggleCheckState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF GetMenuState(hMenu, item, dwFlags) AND MF_CHECKED = MF_CHECKED THEN
      dwFlags = dwFlags OR MF_UNCHECKED
   ELSE
      dwFlags = dwFlags OR MF_CHECKED
   END IF
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   ' Microsoft advises to use SetMenuItemInfoW
'   RETURN CheckMenuItem(hMenu, item, dwFlags)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = dwFlags
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines whether a handle is a menu handle.
' ========================================================================================
PRIVATE FUNCTION IsMenuHandle (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN IsMenu(hMenu)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is checked; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemChecked (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   IF GetMenuState(hMenu, item, dwFlags) AND MF_CHECKED = MF_CHECKED THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Returns TRUE if the specified menu item is enabled; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemEnabled (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_DISABLED) <> MF_DISABLED) AND ((dwRes AND MF_GRAYED) <> MF_GRAYED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Returns TRUE if the specified menu item is disabled; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemDisabled (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_DISABLED) = MF_DISABLED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Returns TRUE if the specified menu item is grayed; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemGrayed (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_GRAYED) = MF_GRAYED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Returns TRUE if the specified menu item is highlighted; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemHighlighted (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_HILITE) = MF_HILITE) THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns TRUE if the specified menu item is a separator; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemSeparator (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_SEPARATOR) = MF_SEPARATOR) THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_OWNERDRAW) = MF_OWNERDRAW) THEN RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns TRUE if the specified menu item is a submenu; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION IsMenuItemPopup (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1
   DIM dwRes AS DWORD = GetMenuState(hMenu, item, dwFlags)
   IF ((dwRes AND MF_POPUP) = MF_POPUP) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a bitmap to the menu item.
' Parameters:
' - hMenu       = A handle to the menu that contains the menu item.
' - item        = The identifier or position of the menu item to change.
'                 The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a
'                 menu item identifier. Otherwise, it is a menu item position.
' - hbmp        = Bitmap handle.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION MenuAddBitmapToItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN, BYVAL hbmp AS HBITMAP) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_BITMAP
   mii.hbmpItem = hbmp
   IF fByPosition = TRUE THEN
      item -= 1 : IF item < 0 THEN item = 0
   END IF
   IF SetMenuItemInfoW(hMenu, item, fByPosition, @mii) = 0 THEN RETURN FALSE
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the state of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fState = The menu item state. It can be one or more of these values:
' - MFS_CHECKED   Checks the menu item.
' - MFS_DEFAULT   Specifies that the menu item is the default.
' - MFS_DISABLED  Disables the menu item and grays it so that it cannot be selected.
' - MFS_ENABLED   Enables the menu item so that it can be selected. This is the default state.
' - MFS_GRAYED    Disables the menu item and grays it so that it cannot be selected.
' - MFS_HILITE    Highlights the menu item.
' - MFS_UNCHECKED Unchecks the menu item.
' - MFS_UNHILITE  Removes the highlight from the menu item. This is the default state.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION MenuSetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fState AS UINT, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = fState
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Checks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to set information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION MenuCheckItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   dwFlags = dwFlags OR MF_CHECKED
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   ' Microsoft advises to use SetMenuItemInfoW
'   RETURN CheckMenuItem(hMenu, item, dwFlags)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = dwFlags
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Unchecks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of item. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION MenuUnCheckItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   dwFlags = dwFlags OR MF_UNCHECKED
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   ' Microsoft advises to use SetMenuItemInfoW
'   RETURN CheckMenuItem(hMenu, item, dwFlags)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = dwFlags
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Enables the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION MenuEnableItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_ENABLED
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Disables the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION MenuDisableItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_DISABLED
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Grays the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION MenuGrayItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_GRAYED
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Highlights the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
PRIVATE FUNCTION MenuHiliteItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_HILITE
   RETURN SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Changes the text of a menu item to bold.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - item = The identifier or position of the menu item to get information about.
'          The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' ========================================================================================
PRIVATE FUNCTION MenuBoldItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU OR MIIM_STATE
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   IF GetMenuItemInfoW(hMenu, item, FALSE, @mii) THEN
      mii.fState = mii.fState OR &H1000
      RETURN SetMenuItemInfoW(hMenu, item, FALSE, @mii)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Right justifies a top level menu item. This is usually used to have the Help menu item
' right-justified on the menu bar.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - item = [in] The one-based position of the menu item to change.
' Return value: TRUE or FALSE.
' Usage example: MenuRightJustifyItem(hMenu, ID_EXIT)
' ========================================================================================
PRIVATE FUNCTION MenuRightJustifyItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fState = MFS_DEFAULT
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU
   IF fByPosition = TRUE THEN item -= 1   ' // adjust for zero-based
   IF GetMenuItemInfoW(hMenu, item, CTRUE, @mii) THEN
      mii.fType = mii.fType OR MF_HELP
      RETURN SetMenuItemInfoW(hMenu, item, CTRUE, @mii)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves information about the font used in menu bars.
' Return value: A LOGFONTW structure that contains information about the font used in menu bars.
' ========================================================================================
PRIVATE FUNCTION MenuGetFont () AS LOGFONTW
   DIM ncm AS NONCLIENTMETRICSW
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) <> 0 THEN
      RETURN ncm.lfMenuFont
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the point size of the font used in menu bars.
' If the function fails, the return value is 0.
' ========================================================================================
PRIVATE FUNCTION MenuGetFontPointSize () AS LONG
   DIM ncm AS NONCLIENTMETRICSW
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) = 0 THEN RETURN 0
   DIM hDC AS HDC = CreateDCW("DISPLAY", NULL, NULL, NULL)
   IF hDC = NULL THEN RETURN 0
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   DeleteDC hDC
   DIM nPointSize AS LONG = MulDiv(ncm.lfMenuFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   RETURN nPointSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the size of a menu bar or a drop-down menu.
' - hwnd = Handle of the window that owns the menu.
' - hmenu = Handle of the menu.
' - prcmenu = Pointer to a variable of type RECT where to return the retrieved values.
' Return Value:
' If the function succeeds, the return value is 0.
' If the function fails, the return value is a system error code.
' ========================================================================================
PRIVATE FUNCTION MenuGetRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL prcmenu AS RECT PTR) AS LONG
   DIM i AS LONG, nRes AS LONG, rc AS RECT
   FOR i = 1 TO GetMenuItemCount(hmenu)
      nRes = GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      UnionRect prcmenu, prcmenu, @rc
   NEXT
   RETURN nRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION MenuGetRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU) AS RECT
   DIM i AS LONG, nRes AS LONG, rc AS RECT, rcMenu AS RECT
   FOR i = 1 TO GetMenuItemCount(hmenu)
      nRes = GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      UnionRect @rcMenu, @rcMenu, @rc
   NEXT
   RETURN rcMenu
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes the system menu close option and disables the X button.
' Parameter: hwnd = Handle of the window or dialog that owns the menu.
' Return value: TRUE of FALSE.
' Note: To restore the close menu, call GetSystemMenu(hwnd, TRUE)
' ========================================================================================
PRIVATE FUNCTION MenuRemoveCloseOptiom (BYVAL hwnd AS HWND) AS BOOLEAN
   ' // Get the system menu handle
   DIM hMenu AS HMENU = GetSystemMenu(hwnd, FALSE)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Get the number of menu items
   DIM cbItems AS LONG = GetMenuItemCount(hMenu)
   IF cbItems = 0 THEN RETURN FALSE
   ' // Remove the close menu item
   IF RemoveMenu(hMenu, cbItems - 1, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Remove the separator line
   IF RemoveMenu(hMenu, cbItems - 2, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Redraw the menu (this refreshes the caption bar, dimming the X button)
   DrawMenuBar(hwnd)
   RETURN TRUE
END FUNCTION
' =====================================================================================
' =====================================================================================
' * Restores the system menu close option and enables Alt+F4 and the X button.
' Parameter: hwnd = Handle of the window or dialog that owns the menu.
' =====================================================================================
PRIVATE FUNCTION MenuRestoreCloseOption (BYVAL hwnd AS HWND) AS BOOLEAN
   IF GetSystemMenu(hwnd, TRUE) <> NULL THEN RETURN FALSE
   DrawMenuBar(hwnd)
   RETURN TRUE
END FUNCTION
' =====================================================================================

' =====================================================================================
' Retrieves information about the specified menu bar.
' Parameters:
' - hwnd = A handle to the window (menu bar) whose information is to be retrieved.
' - idObject = The menu object. This parameter can be one of the following values:
'     - OBJID_CLIENT: &hFFFFFFFC - The popup menu associated with the window.
'     - OBJID_MENU: &hFFFFFFFD - The menu bar associated with the window
'     - OBJID_SYSMENU: &hFFFFFFFF - The system menu associated with the window
' - idItem = The item for which to retrieve information. If this parameter is zero,
'     the function retrieves information about the menu itself. If this parameter is 1,
'     the function retrieves information about the first item on the menu, and so on.
' Return value: A MENUBARINFO structure.
' Result code:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
'   To get extended error information, call GetLastError.
' =====================================================================================
PRIVATE FUNCTION MenuGetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG) AS MENUBARINFO
   DIM mbi AS MENUBARINFO : mbi.cbSize = SIZEOF(MENUBARINFO)
   DIM bRes AS BOOLEAN = GetMenuBarInfo(hwnd, idObject, idItem, @mbi)
   RETURN mbi
END FUNCTION
' =====================================================================================

' =====================================================================================
' Checks a specified menu item and makes it a radio item. At the same time, the function
' clears all other menu items in the associated group and clears the radio-item type flag
' for those items.
' - hMenu: A handle to the menu that contains the group of menu items.
' - first: The identifier or position of the first menu item in the group.
' - last: The identifier or position of the last menu item in the group.
' - check: The identifier or position of the menu item to check.
' - fByPosition: The meaning of check. If this parameter is FALSE, check is a menu item
'                identifier. Otherwise, it is a menu item position.
' Usage example:
'   MenuCheckRadioButton(hMenu, ID_OPEN, ID_EXIT, ID_EXIT)      ' By item identifier
'   MenuCheckRadioButton(GetSubMenu(hMenu, 0), 1, 2, 2, TRUE)   ' By position
' =====================================================================================
PRIVATE FUNCTION MenuCheckRadioButton (BYVAL hMenu AS HMENU, BYVAL first AS LONG, BYVAL last AS LONG, BYVAL check AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
'   IF fByPosition = TRUE THEN
'      first -= 1 : IF first < 0 THEN first = 0
'      last -= 1 : IF last < 0 THEN last = 0
'      check -= 1 : IF check < 0 THEN check = 0
'   END IF
   DIM dwFlags AS DWORD
   IF fByPosition = TRUE THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM bRes AS BOOLEAN = CheckMenuRadioItem(hMenu, first, last, check, dwFlags)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN MenuDrawBar(MenuGetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Retrieves the dimensions of the default check-mark bitmap. The system displays this
' bitmap next to selected menu items. Before calling the MenuSetItemBitmaps function to
' replace the default check-mark bitmap for a menu item, an application must determine
' the correct bitmap size by calling MenuGetCheckMarkWidth and MenuGetCheckMarkHeight.
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION MenuGetCheckMarkWidth () AS LONG
   RETURN GetSystemMetrics(SM_CYMENUCHECK)
END FUNCTION
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION MenuGetCheckMarkHeight () AS LONG
   RETURN GetSystemMetrics(SM_CXMENUCHECK)
END FUNCTION
' =====================================================================================

' =====================================================================================
' Sets the default menu item for the specified menu.
' Parameters:
' - hMenu = A handle to the menu to set the default item for.
' - item = The identifier or position of the new default menu item or -1 for no default item.
'          The meaning of this parameter depends on the value of fByPos.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item identifier.
'                 Otherwise, it is a menu item position.
' Return value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Usage example:
' MenuSetDefaultItem(hMenu, 1)
' =====================================================================================
PRIVATE FUNCTION MenuSetDefaultItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   IF fByPosition = TRUE AND item <> -1 THEN item -= 1   ' Position is zero-based
   RETURN SetMenuDefaultItem(hMenu, item, fByPosition)
END FUNCTION
' =====================================================================================
' =====================================================================================
' * Determines the default menu item on the specified menu.
' Parameters:
' - hMenu = A handle to the menu for which to retrieve the default menu item.
' - gmdiFlags = Indicates how the function should search for menu items. This parameter
'   can be zero or more of the following values.
'   Value	Meaning
'   GMDI_GOINTOPOPUPS &H0002 : If the default item is one that opens a submenu, the function
'      is to search recursively in the corresponding submenu. If the submenu has no default
'      item, the return value identifies the item that opens the submenu. By default, the
'      function returns the first default item on the specified menu, regardless of whether
'      it is an item that opens a submenu.
'  GMDI_USEDISABLED &h0001: The function is to return a default item, even if it is disabled.
'      By default, the function skips disabled or grayed items.
' - fByPosition = Indicates whether to retrieve the menu item's identifier or its position.
'      If this parameter is FALSE, the identifier is returned. Otherwise, the position is returned.
' Return value: If the function succeeds, the return value is the identifier or position of the menu item.
' If the function fails, the return value is 0. To get extended error information, call GetLastError.
' Usage example: MenuGetDefaultItem(hMenu, 1)
' =====================================================================================
PRIVATE FUNCTION MenuGetDefaultItem (BYVAL hMenu AS HMENU, BYVAL gmdiFlags AS UINT = 0, BYVAL fByPosition AS BOOLEAN = TRUE) AS LONG
   IF gmdiFlags = 0 THEN gmdiFlags = GMDI_GOINTOPOPUPS
   RETURN GetMenuDefaultItem(hMenu, gmdiFlags, fByPosition) + 1
END FUNCTION
' =====================================================================================

' =====================================================================================
' Determines the number of items in the specified menu.
' =====================================================================================
PRIVATE FUNCTION MenuGetItemCount (BYVAL hMenu AS HMENU) AS LONG
   RETURN GetMenuItemCount(hMenu)
END FUNCTION
' =====================================================================================

' =====================================================================================
' Associates the specified bitmap with a menu item. Whether the menu item is selected or
' clear, the system displays the appropriate bitmap next to the menu item.
' Usage example:
' MenuCheckItem(hMenu, ID_OPEN)
' MenuSetItemBitmaps(hMenu, ID_OPEN, NULL, NULL)
' =====================================================================================
PRIVATE FUNCTION MenuSetItemBitmaps (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL hBitmapUnchecked AS HBITMAP, _
BYVAL hBitmapChecked AS HBITMAP, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS UINT
   IF fByPosition = TRUE THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF fByPosition = TRUE THEN item -= 1   ' Position is zero-based
   RETURN SetMenuItemBitmaps(hMenu, item, dwFlags, hBitmapUnchecked, hBitmapChecked)
END FUNCTION
' =====================================================================================

' =====================================================================================
' Determines which menu item, if any, is at the specified location.
' =====================================================================================
PRIVATE FUNCTION MenuGetItemFromPoint (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL ptScreen AS POINT) AS LONG
   RETURN MenuItemFromPoint(hwnd, hMenu, ptScreen)
END FUNCTION
' =====================================================================================

' =====================================================================================
' Associates a Help context identifier with a menu.
' =====================================================================================
PRIVATE FUNCTION MenuSetContextHelpId (BYVAL hMenu AS HMENU, BYVAL helpID AS DWORD) AS BOOLEAN
   RETURN SetMenuContextHelpId(hMenu, helpID)
END FUNCTION
' =====================================================================================
' =====================================================================================
' Retrieves the Help context identifier associated with the specified menu.
' =====================================================================================
PRIVATE FUNCTION MenuGetContextHelpId (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN GetMenuContextHelpId(hMenu)
END FUNCTION
' =====================================================================================

' ========================================================================================
' Creates a floating context menu.
' ========================================================================================
PRIVATE FUNCTION MenuContext (BYVAL hDlg AS HWND, BYVAL hPopupMenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL flags AS UINT) AS LONG
   flags = flags OR TPM_NONOTIFY OR TPM_RETURNCMD OR TPM_NOANIMATION
   RETURN TrackPopupMenu(hPopupMenu, flags, x, y, 0, hDlg, NULL)
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT = &h0602
' ========================================================================================
' Converts an icon to a bitmap and adds it to the specified hbmpItem field of HMENU item.
' The caller is responsible for destroying the bitmap generated. The icon will be destroyed
' if fAutoDestroy is set to true. The hbmpItem field of the menu item can be used to keep
' track of the bitmap by passing NULL to phbmp.
' Parameters:
' - hMenu        = Menu handle that contains the item to which an icon will be added.
' - item         = The identifier or position of the menu item to change.
'                  The meaning of this parameter depends on the value of fByPosition.
' - fByPosition  = The meaning of item. If this parameter is FALSE, item is a
'                  menu item identifier. Otherwise, it is a menu item position.
' - hIcon        = Handle of the icon to add to the menu.
' - fAutoDestroy = TRUE (the default) or FALSE.
'                  If TRUE, MenuAddIconToItem destroys the icon before returning.
' - phbmp        = Location where the bitmap representation of the icon is stored. Can be NULL.
' ========================================================================================
PRIVATE FUNCTION MenuAddIconToItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
   IF hMenu = NULL OR hIcon = NULL THEN RETURN FALSE
   DIM hbmp AS HBITMAP, sizIcon AS SIZE, rcIcon AS RECT
   sizIcon.cx = GetSystemMetrics(SM_CXSMICON)
   sizIcon.cy = GetSystemMetrics(SM_CYSMICON)
   SetRect(@rcIcon, 0, 0, sizIcon.cx, sizIcon.cy)
   DIM hdcDest AS HDC = CreateCompatibleDC(NULL)
   IF hdcDest = NULL THEN RETURN FALSE
   DIM hr AS HRESULT = AfxCreate32BitHBITMAP(hdcDest, @sizIcon, NULL, @hbmp)
   IF hr THEN
      DIM hbmpOld AS HBITMAP = CAST(HBITMAP, SelectObject(hdcDest, hbmp))
      IF hbmpOld THEN
         DIM bfAlpha AS BLENDFUNCTION = (AC_SRC_OVER, 0, 255, AC_SRC_ALPHA)
         DIM paintParams AS BP_PAINTPARAMS
         paintParams.cbSize = SIZEOF(paintParams)
         paintParams.dwFlags = BPPF_ERASE
         paintParams.pBlendFunction = @bfAlpha
         DIM hdcBuffer AS HDC
         DIM hPaintBuffer AS HPAINTBUFFER = BeginBufferedPaint(hdcDest, @rcIcon, BPBF_DIB, @paintParams, @hdcBuffer)
         IF hPaintBuffer THEN
            IF DrawIconEx(hdcBuffer, 0, 0, hIcon, sizIcon.cx, sizIcon.cy, 0, NULL, DI_NORMAL) THEN
               ' // If icon did not have an alpha channel, we need to convert buffer to PARGB32.
               hr = AfxConvertBufferToPARGB32(hPaintBuffer, hdcDest, hIcon, sizIcon)
            END IF
            ' // This will write the buffer contents to the destination bitmap.
            EndBufferedPaint(hPaintBuffer, TRUE)
         END IF
         SelectObject(hdcDest, hbmpOld)
      END IF
   END IF
   DeleteDC(hdcDest)
   IF hr THEN hr = MenuAddBitmapToItem(hMenu, item, fByPosition, hbmp)
   IF hr = FALSE THEN DeleteObject(hbmp): hbmp = NULL
   IF fAutoDestroy THEN DestroyIcon(hIcon)
   IF phbmp THEN *phbmp = hbmp
   RETURN hr
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' If the menu uses bitmaps, call this function in WM_DESTROY to delete them.
' CASE WM_DESTROY
'     // Destroy the menu and the bitmaps
'     DIM hMenu AS HMENU = GetMenu(hwnd)
'     AfxDestroyMenuBitmaps(hMenu)
'     DestroyMenu(hMenu)              
' ========================================================================================
SUB AfxDestroyMenuBitmaps (BYVAL hMenu AS HMENU)
   DIM count AS LONG = GetMenuItemCount(hMenu)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.fMask = MIIM_BITMAP OR MIIM_SUBMENU
   FOR i AS LONG = 0 TO count - 1
      IF GetMenuItemInfoW(hMenu, i, TRUE, @mii) THEN
         ' If it has a submenu, process it recursively
         IF mii.hSubMenu THEN
            AfxDestroyMenuBitmaps(mii.hSubMenu)
         END IF
         ' If it has a bitmap and is NOT one of the special ones
         IF mii.hbmpItem <> NULL _
            ANDALSO mii.hbmpItem <> HBMMENU_CALLBACK _
            ANDALSO mii.hbmpItem <> HBMMENU_SYSTEM _
            ANDALSO mii.hbmpItem <> HBMMENU_MBAR_CLOSE _
            ANDALSO mii.hbmpItem <> HBMMENU_MBAR_CLOSE_D _
            ANDALSO mii.hbmpItem <> HBMMENU_MBAR_MINIMIZE _
            ANDALSO mii.hbmpItem <> HBMMENU_MBAR_MINIMIZE_D _
            ANDALSO mii.hbmpItem <> HBMMENU_MBAR_RESTORE _
            ANDALSO mii.hbmpItem <> HBMMENU_POPUP_CLOSE _
            ANDALSO mii.hbmpItem <> HBMMENU_POPUP_RESTORE _
            ANDALSO mii.hbmpItem <> HBMMENU_POPUP_MAXIMIZE _
            ANDALSO mii.hbmpItem <> HBMMENU_POPUP_MINIMIZE THEN
            DeleteObject(mii.hbmpItem)
            mii.hbmpItem = NULL
            SetMenuItemInfoW(hMenu, i, TRUE, @mii)
         END IF
      END IF
    NEXT
END SUB
' ========================================================================================
#define MenudestroyBitmaps AfxDestroyMenuBitmaps
' ========================================================================================

END NAMESPACE
' ########################################################################################
