' ########################################################################################
' Platform: Microsoft Windows
' Filename: CMenu.inc
' Purpose:  Menu wrapper functions
' Compiler: Free Basic 32 & 64 bit
' Copyright (c) 2026 José Roca
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
#include once "windows.bi"
#include once "AfxNova/DWSTRING.inc"
#undef GetWindowOwner    ' // conflict with macro in windowsx.bi
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' CButton class
' ========================================================================================
TYPE CMenu

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION ComCtlVersion () AS LONG
   DECLARE STATIC FUNCTION Create () AS HMENU
   DECLARE STATIC FUNCTION Destroy (BYVAL hMenu AS HMENU) AS BOOLEAN
   DECLARE STATIC FUNCTION Destroy (BYVAL hwnd AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION CreatePopup () AS HMENU
   DECLARE STATIC FUNCTION NewPopup () AS HMENU
   DECLARE STATIC FUNCTION AddPopup (BYVAL hMenu AS HMENU, BYVAL hPopup AS HMENU, BYVAL fState AS UINT, _
           BYVAL item AS LONG, BYREF wszText AS WSTRING, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION Attach (BYVAL hMenu AS HMENU, BYVAL hwnd AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Append (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL uIDNewItem AS UINT_PTR, BYVAL pwszNewItem AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION CheckItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
   DECLARE STATIC FUNCTION UncheckItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DECLARE STATIC FUNCTION ToggleItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
   DECLARE STATIC FUNCTION IsItemChecked (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemEnabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemDisabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemGrayed (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemHighlighted (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemSeparator (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemPopup (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DECLARE STATIC FUNCTION SetItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fState AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION EnableItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION DisableItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION GrayItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION HiliteItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION RemoveCloseMenu (BYVAL hwnd AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION RightJustifyItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemBold (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION BoldItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD,  BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYREF wszText AS WSTRING, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemTextLen (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
   DECLARE STATIC FUNCTION GetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWSTRING
   DECLARE STATIC FUNCTION GetFont (BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFont () AS LOGFONTW
   DECLARE STATIC FUNCTION GetFontPointSize () AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT, BYVAL prcItem AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT, BYREF rcItem AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT) AS RECT
   DECLARE STATIC FUNCTION GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL prcmenu AS RECT PTR) AS LONG
   DECLARE STATIC FUNCTION GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYREF rcmenu AS RECT) AS LONG
   DECLARE STATIC FUNCTION GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU) AS RECT
   DECLARE STATIC FUNCTION DrawBar (BYVAL hwnd AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetHandle (BYVAL hwnd AS HWND) AS HMENU
   DECLARE STATIC FUNCTION GetSystemMenuHandle (BYVAL hwnd AS HWND, BYVAL bRevert AS BOOLEAN = FALSE) AS HMENU
   DECLARE STATIC FUNCTION GetSubMenu (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS HMENU
   DECLARE STATIC FUNCTION GetItemID (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetItemID (BYVAL hMenu AS HMENU, BYVAL submenu AS LONG, BYVAL nPos AS LONG) AS LONG
   DECLARE STATIC FUNCTION FindItemPos (BYVAL hMenu AS HMENU, BYVAL itemID AS UINT, BYREF hMenuFound AS HMENU, BYREF itemPos AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSubmenusCount (BYVAL hMenu AS HMENU) AS LONG
   DECLARE STATIC FUNCTION GetWindowOwner (BYVAL hMenu AS HMENU) AS HWND
   DECLARE STATIC FUNCTION RemoveItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION RemoveMenu (BYVAL hMenu AS HMENU, BYVAL uPosition AS DWORD, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteMenu (BYVAL hMenu AS HMENU, BYVAL uPosition AS DWORD, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS UINT
   DECLARE STATIC FUNCTION ToggleCheckState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION IsMenu (BYVAL hMenu AS HMENU) AS BOOLEAN
   DECLARE STATIC FUNCTION IsMenuHandle (BYVAL hMenu AS HMENU) AS BOOLEAN
   DECLARE STATIC FUNCTION SetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fState AS UINT, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION RemoveCloseOption (BYVAL hwnd AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION RestoreCloseOption (BYVAL hwnd AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG, BYVAL pmbi AS MENUBARINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG, BYREF mbi AS MENUBARINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG) AS MENUBARINFO
   DECLARE STATIC FUNCTION CheckRadioButton (BYVAL hMenu AS HMENU, BYVAL first AS LONG, BYVAL last AS LONG, BYVAL check AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCheckMarkWidth () AS LONG
   DECLARE STATIC FUNCTION GetCheckMarkHeight () AS LONG
   DECLARE STATIC FUNCTION SetDefaultItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetDefaultItem (BYVAL hMenu AS HMENU, BYVAL gmdiFlags AS UINT = 0, BYVAL fByPosition AS BOOLEAN = TRUE) AS LONG
   DECLARE STATIC FUNCTION GetItemCount (BYVAL hMenu AS HMENU) AS LONG
   DECLARE STATIC FUNCTION SetItemBitmaps (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL hBitmapUnchecked AS HBITMAP, _
                  BYVAL hBitmapChecked AS HBITMAP, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemFromPoint (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL ptScreen AS POINT) AS LONG
   DECLARE STATIC FUNCTION GetItemFromPoint (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetContextHelpId (BYVAL hMenu AS HMENU, BYVAL helpID AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION GetContextHelpId (BYVAL hMenu AS HMENU) AS DWORD
   DECLARE STATIC FUNCTION ContextMenu (BYVAL hwnd AS HWND, BYVAL hPopupMenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL flags AS UINT = 0) AS LONG
   DECLARE STATIC FUNCTION TrackPopupMenu (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL x AS LONG, BYVAL y AS LONG, _
                  BYVAL hwnd AS HWND, BYVAL prc AS RECT PTR = NULL) AS BOOLEAN
   DECLARE STATIC FUNCTION TrackPopupMenuEx (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL x AS LONG, BYVAL y AS LONG, _
                  BYVAL hwnd AS HWND, BYVAL ptpm AS TPMPARAMS PTR = NULL) AS BOOLEAN
   DECLARE STATIC FUNCTION Load (BYVAL hInst AS HINSTANCE, BYVAL pMenuName AS WSTRING PTR) AS HMENU
   DECLARE STATIC FUNCTION LoadIndirect (BYVAL pMenuTemplate AS MENUTEMPLATEW PTR) AS HMENU
   DECLARE STATIC FUNCTION Modify (BYVAL hMenu AS HMENU, BYVAL uPosition AS UINT, BYVAL uFlags AS UINT, BYVAL uIDNewItem AS UINT_PTR, BYVAL pNewItem AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetInfo (BYVAL hMenu AS HMENU, BYVAL pmi AS MENUINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetInfo (BYVAL hMenu AS HMENU, BYREF mi AS MENUINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInfo (BYVAL hMenu AS HMENU, BYVAL pmi AS MENUINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInfo (BYVAL hMenu AS HMENU, BYREF mi AS MENUINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYVAL pmii AS MENUITEMINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYREF mii AS MENUITEMINFOW) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYVAL pmii AS MENUITEMINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYREF mii AS MENUITEMINFOW) AS BOOLEAN
   DECLARE STATIC FUNCTION SetMenu (BYVAL hwnd AS HWND, BYVAL hMenu AS HMENU) AS BOOLEAN
  ' // Visual styles menus 
#if _WIN32_WINNT >= &h0600
   DECLARE STATIC FUNCTION InitBitmapInfo (BYVAL pbmi AS BITMAPINFO PTR, BYVAL cbInfo AS ULONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL bpp AS WORD) AS BOOLEAN
   DECLARE STATIC FUNCTION Create32BitHBITMAP (BYVAL hDC AS HDC, BYVAL psize AS SIZE PTR, BYVAL ppvBits AS ANY PTR PTR, BYVAL phBmp AS HBITMAP PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION AddBitmapToItem (BYVAL hMenu AS HMENU, BYVAL nMenuItem AS LONG, BYVAL fByPosition AS BOOLEAN, BYVAL hbmp AS HBITMAP) AS BOOLEAN
   DECLARE STATIC FUNCTION ConvertToPARGB32 (BYVAL hDC AS HDC, BYVAL pargb AS DWORD PTR, BYVAL hbmp AS HBITMAP, BYVAL sizeImage AS SIZE, BYVAL cxRow AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION HasAlpha (BYVAL pargb AS DWORD PTR, BYVAL sizeImage AS SIZE, BYVAL cxRow AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION ConvertBufferToPARGB32 (BYVAL hPaintBuffer AS HPAINTBUFFER, BYVAL hDC AS HDC, BYVAL hIcon AS HICON, BYVAL sizeIcon AS SIZE) AS BOOLEAN
   DECLARE STATIC FUNCTION AddIconToItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
#endif
   DECLARE STATIC SUB DestroyBitmaps (BYVAL hMenu AS HMENU)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CMenu
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CMenu
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Returns the version of ComCtrl.dll version multiplied by 100, e.g. 601 for version 6.01.
' Example: DIM ver AS LONG = CMenu.GetFileVersion("COMCTL32.DLL")
' ========================================================================================
PRIVATE FUNCTION CMenu.ComCtlVersion () AS LONG
   DIM pvsffi AS VS_FIXEDFILEINFO PTR, dwHandle AS DWORD
   DIM cbLen AS DWORD = GetFileVersionInfoSizeW("COMCTL32.DLL", @dwHandle)
   IF cbLen = 0 THEN EXIT FUNCTION
   DIM pVerInfo AS HANDLE = HeapAlloc(GetProcessHeap, HEAP_ZERO_MEMORY, cbLen)
   IF pVerInfo = NULL THEN EXIT FUNCTION
   IF GetFileVersionInfoW("COMCTL32.DLL", dwHandle, cbLen, pVerInfo) THEN
      IF VerQueryValueW(pVerInfo, "\", @pvsffi, @cbLen) THEN
         DIM wMajor AS WORD = HIWORD(pvsffi->dwFileVersionMS)
         DIM wMinor AS WORD = LOWORD(pvsffi->dwFileVersionMS)
         FUNCTION = (wMajor + wMinor / 100) * 100
      END IF
   END IF
   HeapFree(GetProcessHeap, 0, pVerInfo)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a new menu bar
' Usage example:
' DIM hMenu AS HMENU = CMenu.Create
' ========================================================================================
PRIVATE FUNCTION CMenu.Create () AS HMENU
   RETURN ..CreateMenu
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Destroys the specified menu and frees any memory that the menu occupies.
' Usage example: CMenu.Destroy(hMenu)
' ========================================================================================
PRIVATE FUNCTION CMenu.Destroy (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN ..DestroyMenu(hMenu)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Destroys the menu attached to a window or dialog and frees any memory that the menu occupies.
' Usage example: CMenu.Destroy(hwnd)
' ========================================================================================
PRIVATE FUNCTION CMenu.Destroy (BYVAL hwnd AS HWND) AS BOOLEAN
   ' // Get the menu handle, if any
   DIM hMenu AS HMENU = ..GetMenu(hwnd)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Detach the menu from the dialog
   ..SetMenu(hwnd, NULL)
   ' // Destroy the menu
   RETURN ..DestroyMenu(hMenu)
   ' // Redraw the menu bar
   ..DrawMenuBar(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Appends a new item to the end of the specified menu bar, drop-down menu, submenu, or
' shortcut menu. You can use this function to specify the content, appearance, and behavior
' of the menu item.
' Usage examples:
' CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
' CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
' CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
' ========================================================================================
PRIVATE FUNCTION CMenu.Append (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL uIDNewItem AS UINT_PTR, BYVAL pwszNewItem AS WSTRING PTR) AS BOOLEAN
   RETURN ..AppendMenuW(hMenu, uFlags, uIDNewItem, pwszNewItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Checks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: The return value specifies the previous state of the menu item (either
' MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.
' Usage examples:
' - By command:
'    CMenu.CheckItem(hMenu, IDM_OPEN)
' - By position:
'    DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 0)
'    CMenu.CheckItem(hSubMenu, 1, TRUE)
' ========================================================================================
PRIVATE FUNCTION CMenu.CheckItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   dwFlags = dwFlags OR MF_CHECKED
   RETURN ..CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Unchecks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: The return value specifies the previous state of the menu item (either
' MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.
' Usage example: CMenu.UncheckItem(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.UncheckItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   dwFlags = dwFlags OR MF_UNCHECKED
   RETURN ..CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Toggles the checked state of a menu item.
' Usage example: CMenu.ToggleItem(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.ToggleItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF ..GetMenuState(hMenu, uItem, dwFlags) AND MF_CHECKED = MF_CHECKED THEN
      dwFlags = dwFlags OR MF_UNCHECKED
   ELSE
      dwFlags = dwFlags OR MF_CHECKED
   END IF
   RETURN ..CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is checked; FALSE otherwise.
' Usage example: CMenu.IsItemChecked(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemChecked (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF ..GetMenuState(hMenu, uItem, dwFlags) AND MF_CHECKED = MF_CHECKED THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is enabled; FALSE otherwise.
' Usage example: CMenu.IsItemEnabled(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemEnabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_DISABLED) <> MF_DISABLED) AND ((dwRes AND MF_GRAYED) <> MF_GRAYED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is disabled; FALSE otherwise.
' Usage example: IsItemDisabled(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemDisabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_DISABLED) = MF_DISABLED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is grayed; FALSE otherwise.
' Usage example: CMenu.IsItemGrayed(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemGrayed (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_GRAYED) = MF_GRAYED) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is highlighted; FALSE otherwise.
' Usage example: CMenu.IsItemHighlighted(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemHighlighted (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_HILITE) = MF_HILITE) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified menu item is a separator; FALSE otherwise.
' Usage example:
' DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 0)
' PRINT CMenu.IsItemSeparator(hSubMenu, 2, TRUE)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemSeparator (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_SEPARATOR) = MF_SEPARATOR) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is a submenu; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemPopup (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_POPUP) = MF_POPUP) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CMenu.IsItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM dwRes AS DWORD = ..GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND MF_OWNERDRAW) = MF_OWNERDRAW) THEN RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the state of the specified menu item.
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
' Usage example: CMenu.GetItemState(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) = 0 THEN RETURN 0
   RETURN mii.fState
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the state of the specified menu item.
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
' Usage example: CMenu.SetItemState(hMenu, IDM_OPEN, MFS_CHECKED)
' ========================================================================================
PRIVATE FUNCTION CMenu.SetItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fState AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = fState
   DIM bRes AS BOOLEAN
   bRes = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Enables the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' Usage example: CMenu.EnableItem(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.EnableItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_ENABLED
   DIM bRes AS BOOLEAN
   bRes = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
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
' Usage example: CMenu.DisableItem((hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.DisableItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_DISABLED
   DIM bRes AS BOOLEAN = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
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
' Usage example: CMenu.GrayItem(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.GrayItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_GRAYED
   DIM bRes AS BOOLEAN = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Highlights the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' Usage example: CMenu.HiliteItem(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.HiliteItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = MFS_HILITE
   DIM bRes AS BOOLEAN = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Right justifies a top level menu item. This is usually used to have the Help menu item
' right-justified on the menu bar.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - uItem = [in] The zero-based position of the menu item to change.
' Return value: TRUE or FALSE.
' Usage example: CMenu.RightJustifyItem(hMenu, 2)
' ========================================================================================
PRIVATE FUNCTION CMenu.RightJustifyItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fState = MFS_DEFAULT
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU
   DIM bRes AS BOOLEAN
   IF GetMenuItemInfoW(hMenu, uItem, CTRUE, @mii) THEN
      mii.fType = mii.fType OR MF_HELP
      bRes = SetMenuItemInfoW(hMenu, uItem, CTRUE, @mii)
   END IF
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Changes the text of a menu item to bold.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - uItem = [in] The zero-based position of the menu item to change.
' Return value: TRUE or FALSE.
' Usage examples:
' CMenu.SetItemBold(hMenu, IDM_EXIT)
' CMenu.BoldItem(hMenu, IDM_EXIT)
' ========================================================================================
PRIVATE FUNCTION CMenu.SetItemBold (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU OR MIIM_STATE
   DIM bRes AS BOOLEAN
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) THEN
      mii.fState = mii.fState OR &H1000
      bRes = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   END IF
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.BoldItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW, buffer AS WSTRING * MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = @buffer
   mii.cch = MAX_PATH
   mii.fType = MF_STRING
   mii.fMask = MIIM_ID OR MIIM_DATA OR MIIM_TYPE OR MIIM_SUBMENU OR MIIM_STATE
   DIM bRes AS BOOLEAN
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) THEN
      mii.fState = mii.fState OR &H1000
      bRes = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   END IF
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - wszText = Text to set.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return value: TRUE or FALSE.
' Usage example: CMenu.SetItemText(hMenu, IDM_OPEN, "Open new")
' ========================================================================================
PRIVATE FUNCTION CMenu.SetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYREF wszText AS WSTRING, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = @wszText
   DIM bRes AS BOOLEAN
   bRes = SetMenuItemInfoW(hMenu, uItem, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the lengnth of the specified menu item.
' Usage example: CMenu.GetItemTextLen(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemTextLen (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
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

' ========================================================================================
' * Retrieves the text of the specified menu item.
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
' CMenu.GetItemText(hMenu, IDM_OPEN, FALSE, @wsz, 260)
' AfxMsg wsz
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
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
' Usage example: DIM dwsText AS DWSTRING = CMenu.GetItemText(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWSTRING
   DIM wszText AS WSTRING * 260
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STRING
   mii.dwTypeData = @wszText
   mii.cch = 260
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, @mii) THEN RETURN wszText
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves information about the font used in menu bars.
' Return value: TRUE on succes or FALSE on failure.
' If the function fails, the return value is zero.
' To get extended error information, call GetLastError.
' Usage example:
' DIM lfw AS LOGFONTW
' CMenu.GetFont(@lfw)
' print lfw.lfFaceName
' ========================================================================================
PRIVATE FUNCTION CMenu.GetFont (BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
   DIM ncm AS NONCLIENTMETRICSW
   IF plfw = NULL THEN RETURN FALSE
   IF CMenu.ComCtlVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) = 0 THEN RETURN FALSE
   *plfw = ncm.lfMenuFont
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Usage example:
' DIM lfw AS LOGFONTW = CMenu.GetFont
' print lfw.lfFaceName
' ========================================================================================
PRIVATE FUNCTION CMenu.GetFont () AS LOGFONTW
   DIM ncm AS NONCLIENTMETRICSW
   IF CMenu.ComCtlVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   SetLastError(SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0))
   RETURN ncm.lfMenuFont
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the point size of the font used in menu bars.
' If the function fails, the return value is 0.
' print CMenu.GetFontPointSize
' ========================================================================================
PRIVATE FUNCTION CMenu.GetFontPointSize () AS LONG
   DIM ncm AS NONCLIENTMETRICSW
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) = 0 THEN RETURN 0
   DIM hDC AS HDC = CreateDCW("DISPLAY", NULL, NULL, NULL)
   IF hDC = NULL THEN RETURN 0
   DIM cyPixelsPerInch AS LONG = ..GetDeviceCaps(hDC, LOGPIXELSY)
   ..DeleteDC hDC
   DIM nPointSize AS LONG = MulDiv(ncm.lfMenuFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   RETURN nPointSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the bounding rectangle for the specified menu item.
' Usage example:
' DIM rc AS RECT = CMenu.GetItemRect(hWin, hMenu, 1)
' print rc.left, rc.top, rc.right, rc.bottom
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT, BYVAL prcItem AS RECT PTR) AS BOOLEAN
   RETURN ..GetMenuItemRect(hwnd, hMenu, uItem, prcItem)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT, BYREF rcItem AS RECT) AS BOOLEAN
   RETURN ..GetMenuItemRect(hwnd, hMenu, uItem, @rcItem)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT) AS RECT
   DIM rcItem AS RECT
   ..GetMenuItemRect(hwnd, hMenu, uItem, @rcItem)
   RETURN rcItem
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Calculates the size of a menu bar or a drop-down menu.
' - hwnd = Handle of the window that owns the menu.
' - hmenu = Handle of the menu.
' - prcmenu = Pointer to a variable of type RECT where to return the retrieved values.
' Return Value:
' If the function succeeds, the return value is 0.
' If the function fails, the return value is a system error code.
' Usage example:
' DIM rc AS RECT = CMenu.GetRect(hWin, hMenu)
' print rc.left, rc.top, rc.right, rc.bottom
' ========================================================================================
PRIVATE FUNCTION CMenu.GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL prcmenu AS RECT PTR) AS LONG
   DIM i AS LONG, nRes AS LONG, rc AS RECT
   FOR i = 1 TO ..GetMenuItemCount(hmenu)
      nRes = ..GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      ..UnionRect prcmenu, prcmenu, @rc
   NEXT
   RETURN nRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYREF rcmenu AS RECT) AS LONG
   DIM i AS LONG, nRes AS LONG, rc AS RECT
   FOR i = 1 TO ..GetMenuItemCount(hmenu)
      nRes = ..GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      ..UnionRect @rcmenu, @rcmenu, @rc
   NEXT
   RETURN nRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU) AS RECT
   DIM i AS LONG, nRes AS LONG, rc AS RECT, rcMenu AS RECT
   FOR i = 1 TO ..GetMenuItemCount(hmenu)
      nRes = ..GetMenuItemRect(hwnd, hmenu, i, @rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      ..UnionRect @rcMenu, @rcMenu, @rc
   NEXT
   RETURN rcMenu
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a drop-down menu, submenu, or shortcut menu. The menu is initially empty. You can
' insert or append menu items by using the InsertMenuItem function. You can also use the
' AppendMenu function to append menu items.
' ========================================================================================
PRIVATE FUNCTION CMenu.CreatePopup () AS HMENU
   RETURN ..CreatePopupMenu
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.NewPopup () AS HMENU
   RETURN ..CreatePopupMenu
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds a popup child menu to an existing menu.
' ========================================================================================
PRIVATE FUNCTION CMenu.AddPopup (BYVAL hMenu AS HMENU, BYVAL hPopup AS HMENU, BYVAL fState AS UINT, _
BYVAL item AS LONG, BYREF wszText AS WSTRING, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   fState = fState OR MF_POPUP
   IF item = 0 THEN RETURN AppendMenuW(hMenu, fState, CAST(UINT_PTR, hPopup), @wszText)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_SUBMENU OR MIIM_STRING OR MIIM_ID
   mii.hSubMenu = hPopup
   mii.dwTypeData = @wszText
   IF fByPosition = FALSE THEN mii.wID = item   '// it is not a position but an identifier
   IF InsertMenuItemW(hMenu, item, fByPosition, @mii) = FALSE THEN RETURN FALSE
   mii.fMask = MIIM_STATE
   mii.fState = fState
   DIM bRes AS BOOLEAN = SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Attaches a menu to a window or dialog.
' ========================================================================================
PRIVATE FUNCTION CMenu.Attach (BYVAL hMenu AS HMENU, BYVAL hwnd AS HWND) AS BOOLEAN
   RETURN ..SetMenu(hwnd, hMenu)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Assigns a new menu to the specified window.
' ========================================================================================
PRIVATE FUNCTION CMenu.SetMenu (BYVAL hwnd AS HWND, BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN ..SetMenu(hwnd, hMenu)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes a menu item or detaches a submenu from the specified menu. If the menu item
' opens a drop-down menu or submenu, RemoveItem does not destroy the menu or its handle,
' allowing the menu to be reused. Before this function is called, the FindItemPos metod
' should retrieve a handle to the drop-down menu or submenu.
' Usage examples:
' ----------------------------------------------------------------------------------------
' Remove by identifier:
' ----------------------------------------------------------------------------------------
' CMenu.RemoveItem(hMenu, IDM_OPEN)    ' Removes the menu item with the IDM_OPEN identifier
' CMenu.RemoveItem(hMenu, IDM_POPUP)   ' Removes de popup menu with the IDM_POPUP identifier
' ----------------------------------------------------------------------------------------
' Remove a menu by position
' ----------------------------------------------------------------------------------------
' CMenu.RemoveItem(hMenu, 1, TRUE)     ' Removes the second menu (zero-based position)
' ----------------------------------------------------------------------------------------
' Remove an item by position
' ----------------------------------------------------------------------------------------
' DIM hFoundMenu AS HMENU, itemPos AS LONG
' DIM bRes AS BOOLEAN = CMenu.FindItemPos(hMenu, IDM_EXIT, hFoundMenu, itemPos)
' IF bRes THEN CMenu.RemoveItem(hFoundMenu, itemPos, TRUE)
' ----------------------------------------------------------------------------------------
' Note: To remove menus use always the position and to remove drop-down menus use the identifier.
' ========================================================================================
PRIVATE FUNCTION CMenu.RemoveItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM uFlags AS UINT
   IF fByPosition = TRUE THEN uFlags = MF_BYPOSITION ELSE uFlags = MF_BYCOMMAND
   DIM bRes AS BOOLEAN
   bRes = ..RemoveMenu(hMenu, item, uFlags)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.DeleteItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM uFlags AS UINT
   IF fByPosition = TRUE THEN uFlags = MF_BYPOSITION ELSE uFlags = MF_BYCOMMAND
   DIM bRes AS BOOLEAN
   bRes = ..RemoveMenu(hMenu, item, uFlags)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a menu or detaches a submenu from the specified menu.
' ========================================================================================
PRIVATE FUNCTION CMenu.RemoveMenu (BYVAL hMenu AS HMENU, BYVAL uPositiom AS DWORD, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   DIM uFlags AS UINT
   IF fByPosition = TRUE THEN uFlags = MF_BYPOSITION ELSE uFlags = MF_BYCOMMAND
   DIM bRes AS BOOLEAN
   bRes = ..RemoveMenu(hMenu, uPositiom, uFlags)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.DeleteMenu (BYVAL hMenu AS HMENU, BYVAL uPositiom AS DWORD, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   DIM uFlags AS UINT
   IF fByPosition = TRUE THEN uFlags = MF_BYPOSITION ELSE uFlags = MF_BYCOMMAND
   DIM bRes AS BOOLEAN
   bRes = ..RemoveMenu(hMenu, uPositiom, uFlags)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Redraws the menu bar of the specified window. If the menu bar changes after the system
' has created the window, this function must be called to draw the changed menu bar.
' Usage example: CMenu.DrawBar(hwnd)
' ========================================================================================
PRIVATE FUNCTION CMenu.DrawBar (BYVAL hwnd AS HWND) AS BOOLEAN
   RETURN ..DrawMenuBar(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a handle to the menu assigned to the specified window or dialog. 
' Usage example: CMenu.GetHandle(hWin)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetHandle (BYVAL hwnd AS HWND) AS HMENU
   RETURN ..GetMenu(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the system menu handle.
' Usage example: CMenu.GetSystemMenuHandle(hWin)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetSystemMenuHandle (BYVAL hwnd AS HWND, BYVAL bRevert AS BOOLEAN = FALSE) AS HMENU
   RETURN ..GetSystemMenu(hwnd, bRevert)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.
' Usage example: DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 0)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetSubMenu (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS HMENU
   RETURN ..GetSubMenu(hMenu, nPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the menu item ID of a menu item located at the specified position in a menu.
' Usage example: CMenu.GetItemID(CMenu.GetSubMenu(hMenu, 0), 1) 
' - Returms the identifier of the second item of the first submenu.
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemID (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS LONG
   RETURN ..GetMenuItemID(hMenu, nPos)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemID (BYVAL hMenu AS HMENU, BYVAL submenu AS LONG, BYVAL nPos AS LONG) AS LONG
   RETURN ..GetMenuItemID(GetSubMenu(hMenu, submenu), nPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Recursively finds the submenu and position of the specified menu item.
' Parameters:
' - hMenu       = [in]  Handle of the menu to search
' - itemID      = [in]  Item identifier to locate
' - hMenuFound  = [out] HMENU where the item was found
' - itemPos     = [out] Zero-based position of the item in that submenu
' Return value: TRUE if found, FALSE otherwise.
' Example:
'   DIM hFoundMenu AS HMENU, itemPos AS LONG
'   DIM bRes AS BOOLEAN = CMenu.FindItemPos(hMenu, IDM_COPY, hFoundMenu, itemPos)
'   IF bRes THEN
'      PRINT "hFoundMenu", hFoundMenu
'      PRINT "itemPos", itemPos
'      PRINT CMenu.GetItemID(hFoundMenu, itemPos)
'   END IF
' ========================================================================================
PRIVATE FUNCTION CMenu.FindItemPos ( _
      BYVAL hMenu AS HMENU, _
      BYVAL itemID AS UINT, _
      BYREF hMenuFound AS HMENU, _
      BYREF itemPos AS LONG _
   ) AS BOOLEAN

   ' // Number of items of the menu
   DIM itemCount AS LONG = GetMenuItemCount(hMenu)

   ' --- 1. Search in this menu ---
   FOR i AS LONG = 0 TO itemCount - 1
      IF GetMenuItemID(hMenu, i) = itemID THEN
         hMenuFound = hMenu
         itemPos = i
         RETURN TRUE
      END IF
   NEXT

   ' --- 2. Search recursively in submenus ---
   DIM hSub AS ..HMENU
   FOR x AS LONG = 0 TO itemCount - 1
      hSub = GetSubMenu(hMenu, x)
      IF hSub <> 0 THEN
         IF CMenu.FindItemPos(hSub, itemID, hMenuFound, itemPos) THEN
            RETURN TRUE
         END IF
      END IF
   NEXT

   RETURN FALSE ' Item not found

END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of submenus of a menu.
' Usage example: CMenu.GetSubmenusCount(hMenu)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetSubmenusCount (BYVAL hMenu AS HMENU) AS LONG
   DIM itemCount AS LONG = ..GetMenuItemCount(hMenu)
   DIM submenuCount AS LONG
   FOR i AS LONG = 0 TO itemCount - 1
      IF ..GetSubMenu(hMenu, i) <> 0 THEN submenuCount += 1
   NEXT
   RETURN submenuCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the window owner of the specified menu.
' Usage example: CMenu.GetWindowOwner(hMenu)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetWindowOwner (BYVAL hMenu AS HMENU) AS HWND
   DIM hwnd AS HWND = ..GetTopWindow(NULL)
   WHILE hwnd <> 0
      IF ..GetMenu(hwnd) = hMenu THEN
         RETURN hwnd ' Found the window owner
      END IF
      hwnd = ..GetNextWindow(hwnd, GW_HWNDNEXT)
   WEND
   RETURN NULL ' Not found
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
' Usage example: CMenu.GetState(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.GetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS UINT
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   IF GetMenuItemInfoW(hMenu, item, fByPosition, @mii) = 0 THEN RETURN 0
   RETURN mii.fState
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Toggles the checked state of a menu item.
' Usage example: CMenu.ToggleCheckState(hMenu, IDM_OPEN)
' ========================================================================================
PRIVATE FUNCTION CMenu.ToggleCheckState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   IF GetMenuState(hMenu, item, dwFlags) AND MF_CHECKED = MF_CHECKED THEN
      dwFlags = dwFlags OR MF_UNCHECKED
   ELSE
      dwFlags = dwFlags OR MF_CHECKED
   END IF
   ' Microsoft advises to use SetMenuItemInfoW
'   RETURN CheckMenuItem(hMenu, item, dwFlags)
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = dwFlags
   DIM bRes AS BOOLEAN
   bRes = SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines whether a handle is a menu handle.
' Usage examples:
' CMenu.IsMenu(hMenu)
' CMenu.IsMenuHandle(hMenu)
' ========================================================================================
PRIVATE FUNCTION CMenu.IsMenu (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN ..IsMenu(hMenu)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.IsMenuHandle (BYVAL hMenu AS HMENU) AS BOOLEAN
   RETURN ..IsMenu(hMenu)
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
' Usage example: CMenu.SetState(hMenu, IDM_OPEN, MFS_CHECKED)
' ========================================================================================
PRIVATE FUNCTION CMenu.SetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fState AS UINT, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_STATE
   mii.fState = fState
   DIM bRes AS BOOLEAN
   bRes = SetMenuItemInfoW(hMenu, item, fByPosition, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes the system menu close option and disables the X button.
' Parameter: hwnd = Handle of the window or dialog that owns the menu.
' Return value: TRUE of FALSE.
' Note: To restore the close menu, call RestoreCloseOption.
' Usage example: CMenu.RemoveCloseOption(hWin)
' ========================================================================================
PRIVATE FUNCTION CMenu.RemoveCloseOption (BYVAL hwnd AS HWND) AS BOOLEAN
   ' // Get the system menu handle
   DIM hMenu AS HMENU = ..GetSystemMenu(hwnd, FALSE)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Get the number of menu items
   DIM cbItems AS LONG = ..GetMenuItemCount(hMenu)
   IF cbItems = 0 THEN RETURN FALSE
   ' // Remove the close menu item
   IF ..RemoveMenu(hMenu, cbItems - 1, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Remove the separator line
   IF ..RemoveMenu(hMenu, cbItems - 2, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Redraw the menu (this refreshes the caption bar, dimming the X button)
   ..DrawMenuBar(hwnd)
   RETURN TRUE
END FUNCTION
' =====================================================================================
' =====================================================================================
' Restores the system menu close option and enables Alt+F4 and the X button.
' Parameter: hwnd = Handle of the window or dialog that owns the menu.
' Usage example: CMenu.RestoreCloseOption(hWin)
' =====================================================================================
PRIVATE FUNCTION CMenu.RestoreCloseOption (BYVAL hwnd AS HWND) AS BOOLEAN
   IF ..GetSystemMenu(hwnd, TRUE) <> NULL THEN RETURN FALSE
   ..DrawMenuBar(hwnd)
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
PRIVATE FUNCTION CMenu.GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG, BYVAL pmbi AS MENUBARINFO PTR) AS BOOLEAN
   IF pmbi = NULL THEN RETURN FALSE
   pmbi->cbSize = SIZEOF(MENUBARINFO)
   RETURN ..GetMenuBarInfo(hwnd, idObject, idItem, pmbi)
END FUNCTION
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CMenu.GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG, BYREF mbi AS MENUBARINFO) AS BOOLEAN
   IF VARPTR(mbi) = NULL THEN RETURN FALSE
   mbi.cbSize = SIZEOF(MENUBARINFO)
   RETURN ..GetMenuBarInfo(hwnd, idObject, idItem, @mbi)
END FUNCTION
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CMenu.GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG) AS MENUBARINFO
   DIM mbi AS MENUBARINFO : mbi.cbSize = SIZEOF(MENUBARINFO)
   DIM bRes AS BOOLEAN = ..GetMenuBarInfo(hwnd, idObject, idItem, @mbi)
   RETURN mbi
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Checks a specified menu item and makes it a radio item. At the same time, the function
' clears all other menu items in the associated group and clears the radio-item type flag
' for those items.
' - hMenu: A handle to the menu that contains the group of menu items.
' - first: The identifier or position of the first menu item in the group.
' - last: The identifier or position of the last menu item in the group.
' - check: The identifier or position of the menu item to check.
' - fByPosition: The meaning of check. If this parameter is FALSE, check is a menu item
'                identifier. Otherwise, it is a menu item position.
' Usage example:
'   CMenu.CheckRadioButton(hMenu, IDM_OPEN, IDM_EXIT, IDM_SAVE)         ' By item identifier
'   CMenu.CheckRadioButton(CMenu.GetSubMenu(hMenu, 0), 0, 1, 1, TRUE)   ' By position
' =====================================================================================
PRIVATE FUNCTION CMenu.CheckRadioButton (BYVAL hMenu AS HMENU, BYVAL first AS LONG, BYVAL last AS LONG, BYVAL check AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS DWORD
   IF fByPosition = TRUE THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   DIM bRes AS BOOLEAN = ..CheckMenuRadioItem(hMenu, first, last, check, dwFlags)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Retrieves the dimensions of the default check-mark bitmap. The system displays this
' bitmap next to selected menu items. Before calling the MenuSetItemBitmaps function to
' replace the default check-mark bitmap for a menu item, an application must determine
' the correct bitmap size by calling CMenu.GetCheckMarkWidth and CMenu.GetCheckMarkHeight.
' Usage example: DIM nWidth AS LONG = CMenu.GetCheckMarkWidth
' =====================================================================================
PRIVATE FUNCTION CMenu.GetCheckMarkWidth () AS LONG
   RETURN GetSystemMetrics(SM_CYMENUCHECK)
END FUNCTION
' =====================================================================================
' =====================================================================================
' * Usage example: DIM nHeight AS LONG = CMenu.GetCheckMarkHeight
' =====================================================================================
PRIVATE FUNCTION CMenu.GetCheckMarkHeight () AS LONG
   RETURN GetSystemMetrics(SM_CXMENUCHECK)
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Sets the default menu item for the specified menu.
' Parameters:
' - hMenu = A handle to the menu to set the default item for.
' - item = The identifier or position of the new default menu item or -1 for no default item.
'          The meaning of this parameter depends on the value of fByPos.
' - fByPosition = The meaning of item. If this parameter is FALSE, item is a menu item identifier.
'                 Otherwise, it is a menu item position.
' Return value: TRUE or FALSE. To get extended error information, use the GetLastError function.
' Usage example:
' CMenu.SetDefaultItem(hMenu, 1)
' =====================================================================================
PRIVATE FUNCTION CMenu.SetDefaultItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
   RETURN ..SetMenuDefaultItem(hMenu, item, fByPosition)
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
PRIVATE FUNCTION CMenu.GetDefaultItem (BYVAL hMenu AS HMENU, BYVAL gmdiFlags AS UINT = 0, BYVAL fByPosition AS BOOLEAN = TRUE) AS LONG
   IF gmdiFlags = 0 THEN gmdiFlags = GMDI_GOINTOPOPUPS
   RETURN ..GetMenuDefaultItem(hMenu, gmdiFlags, fByPosition) + 1
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Determines the number of items in the specified menu.
' Usage examples:
' CMenu.GetItemCount(hMenu)
' CMenu.GetItemCount(CMenu.GetSubmenu(hMenu, 0))
' =====================================================================================
PRIVATE FUNCTION CMenu.GetItemCount (BYVAL hMenu AS HMENU) AS LONG
   RETURN ..GetMenuItemCount(hMenu)
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Associates the specified bitmap with a menu item. Whether the menu item is selected or
' clear, the system displays the appropriate bitmap next to the menu item.
' Usage example:
' CMenu.CheckItem(hMenu, IDM_OPEN)
' CMenu.SetItemBitmaps(hMenu, IDM_OPEN, NULL, NULL)
' =====================================================================================
PRIVATE FUNCTION CMenu.SetItemBitmaps (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL hBitmapUnchecked AS HBITMAP, _
BYVAL hBitmapChecked AS HBITMAP, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
   DIM dwFlags AS UINT
   IF fByPosition = TRUE THEN dwFlags = MF_BYPOSITION ELSE dwFlags = MF_BYCOMMAND
   RETURN SetMenuItemBitmaps(hMenu, item, dwFlags, hBitmapUnchecked, hBitmapChecked)
END FUNCTION
' =====================================================================================

' =====================================================================================
' Determines which menu item, if any, is at the specified location.
' =====================================================================================
PRIVATE FUNCTION CMenu.GetItemFromPoint (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL ptScreen AS POINT) AS LONG
   RETURN ..MenuItemFromPoint(hwnd, hMenu, ptScreen)
END FUNCTION
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CMenu.GetItemFromPoint (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   DIM ptScreen AS POINT
   ptScreen.x = x : ptScreen.y = y
   RETURN ..MenuItemFromPoint(hwnd, hMenu, ptScreen)
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Associates a Help context identifier with a menu.
' CMenu.SetContextHelpId(hMenu, 123)
' =====================================================================================
PRIVATE FUNCTION CMenu.SetContextHelpId (BYVAL hMenu AS HMENU, BYVAL helpID AS DWORD) AS BOOLEAN
   RETURN ..SetMenuContextHelpId(hMenu, helpID)
END FUNCTION
' =====================================================================================
' =====================================================================================
' * Retrieves the Help context identifier associated with the specified menu.
' print CMenu.GetContextHelpId(hMenu)
' =====================================================================================
PRIVATE FUNCTION CMenu.GetContextHelpId (BYVAL hMenu AS HMENU) AS DWORD
   RETURN ..GetMenuContextHelpId(hMenu)
END FUNCTION
' =====================================================================================
 
' ========================================================================================
' * Creates a floating context menu.
' ========================================================================================
PRIVATE FUNCTION CMenu.ContextMenu (BYVAL hwnd AS HWND, BYVAL hPopupMenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL flags AS UINT = 0) AS LONG
   RETURN ..TrackPopupMenu(hPopupMenu, flags, x, y, 0, hwnd, NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Displays a shortcut menu at the specified location and tracks the selection of items on
' the menu. The shortcut menu can appear anywhere on the screen. 
' ========================================================================================
PRIVATE FUNCTION CMenu.TrackPopupMenu (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL x AS LONG, BYVAL y AS LONG, _
BYVAL hwnd AS HWND, BYVAL prc AS RECT PTR = NULL) AS BOOLEAN
   RETURN ..TrackPopupMenu(hMenu, uFlags, x, y, 0, hwnd, prc)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Displays a shortcut menu at the specified location and tracks the selection of items on
' the menu. The shortcut menu can appear anywhere on the screen. 
' ========================================================================================
PRIVATE FUNCTION CMenu.TrackPopupMenuEx (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL x AS LONG, BYVAL y AS LONG, _
BYVAL hwnd AS HWND, BYVAL ptpm AS TPMPARAMS PTR = NULL) AS BOOLEAN
   RETURN ..TrackPopupMenuEx(hMenu, uFlags, x, y, hwnd, ptpm)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads the specified menu resource from the executable (.exe) file associated with an application instance.
' ========================================================================================
PRIVATE FUNCTION CMenu.Load (BYVAL hInst AS HINSTANCE, BYVAL pMenuName AS WSTRING PTR) AS HMENU
   RETURN ..LoadMenuW(hInst, pMenuName)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads the specified menu template in memory.
' ========================================================================================
PRIVATE FUNCTION CMenu.LoadIndirect (BYVAL pMenuTemplate AS MENUTEMPLATEW PTR) AS HMENU
   RETURN ..LoadMenuIndirectW(pMenuTemplate)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes an existing menu item. This function is used to specify the content, appearance,
' and behavior of the menu item.
' ========================================================================================
PRIVATE FUNCTION CMenu.Modify (BYVAL hMenu AS HMENU, BYVAL uPosition AS UINT, BYVAL uFlags AS UINT, BYVAL uIDNewItem AS UINT_PTR, BYVAL pNewItem AS WSTRING PTR) AS BOOLEAN
   RETURN ..ModifyMenuW(hMenu, uPosition, uFlags, uIDNewItem, pNewItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information for a specified menu.
' ========================================================================================
PRIVATE FUNCTION CMenu.GetInfo (BYVAL hMenu AS HMENU, BYVAL pmi AS MENUINFO PTR) AS BOOLEAN
   IF pmi = NULL THEN RETURN FALSE
   pmi->cBSize = SIZEOF(MENUINFO)
   RETURN ..GetMenuInfo(hMenu, pmi)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetInfo (BYVAL hMenu AS HMENU, BYREF mi AS MENUINFO) AS BOOLEAN
   IF VARPTR(mi) = NULL THEN RETURN FALSE
   mi.cbSize = SIZEOF(MENUINFO)
   RETURN ..GetMenuInfo(hMenu, @mi)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information for a specified menu.
' ========================================================================================
PRIVATE FUNCTION CMenu.SetInfo (BYVAL hMenu AS HMENU, BYVAL pmi AS MENUINFO PTR) AS BOOLEAN
   IF pmi = NULL THEN RETURN FALSE
   pmi->cBSize = SIZEOF(MENUINFO)
   RETURN ..SetMenuInfo(hMenu, pmi)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.SetInfo (BYVAL hMenu AS HMENU, BYREF mi AS MENUINFO) AS BOOLEAN
   IF VARPTR(mi) = NULL THEN RETURN FALSE
   mi.cbSize = SIZEOF(MENUINFO)
   RETURN ..SetMenuInfo(hMenu, @mi)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about a menu item.
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYVAL pmii AS MENUITEMINFOW PTR) AS BOOLEAN
   IF pmii = NULL THEN RETURN FALSE
   pmii->cBSize = SIZEOF(MENUITEMINFOW)
   RETURN ..GetMenuItemInfoW(hMenu, item, fByPositon, pmii)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.GetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYREF mii AS MENUITEMINFOW) AS BOOLEAN
   IF VARPTR(mii) = NULL THEN RETURN FALSE
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   RETURN ..GetMenuItemInfoW(hMenu, item, fByPositon, @mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes information about a menu item.
' ========================================================================================
PRIVATE FUNCTION CMenu.SetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYVAL pmii AS MENUITEMINFOW PTR) AS BOOLEAN
   IF pmii = NULL THEN RETURN FALSE
   pmii->cBSize = SIZEOF(MENUINFO)
   DIM bRes AS BOOLEAN
   bRes = ..SetMenuItemInfoW(hMenu, item, fByPositon, pmii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMenu.SetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, BYREF mii AS MENUITEMINFOW) AS BOOLEAN
   IF VARPTR(mii) = NULL THEN RETURN FALSE
   mii.cbSize = SIZEOF(MENUINFO)
   DIM bRes AS BOOLEAN
   bRes = ..SetMenuItemInfoW(hMenu, item, fByPositon, @mii)
   ' Redraw the menu bar to reflect the changes
   IF bRes THEN ..DrawMenuBar(CMenu.GetWindowOwner(hMenu))
   RETURN bRes
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
'    IF hIcon THEN CMenu.AddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
' PNG icons can be used by converting them to an icon with AfxGdipImageFromFile:
'    hIcon = AfxGdipImageFromFile("MyIcon.png")
'    IF hIcon THEN CMenu.AddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)

#if _WIN32_WINNT = &h0602
' ========================================================================================
' Initializes the BITMAPINFO structure
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CMenu.InitBitmapInfo (BYVAL pbmi AS BITMAPINFO PTR, BYVAL cbInfo AS ULONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL bpp AS WORD) AS BOOLEAN
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
PRIVATE FUNCTION CMenu.Create32BitHBITMAP (BYVAL hDC AS HDC, BYVAL psize AS SIZE PTR, BYVAL ppvBits AS ANY PTR PTR, BYVAL phBmp AS HBITMAP PTR) AS BOOLEAN
   IF psize = NULL OR phBmp = NULL THEN RETURN FALSE
   *phBmp = NULL
   DIM bmi AS BITMAPINFO
   CMenu.InitBitmapInfo(@bmi, SIZEOF(bmi), psize->cx, psize->cy, 32)
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
PRIVATE FUNCTION CMenu.AddBitmapToItem (BYVAL hMenu AS HMENU, BYVAL nMenuItem AS LONG, BYVAL fByPosition AS BOOLEAN, BYVAL hbmp AS HBITMAP) AS BOOLEAN
   DIM mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = MIIM_BITMAP
   mii.hbmpItem = hbmp
   IF SetMenuItemInfoW(hMenu, nMenuItem, fByPosition, @mii) = 0 THEN RETURN FALSE
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a bitmap to a PARGB32 bitmap.
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
PRIVATE FUNCTION CMenu.ConvertToPARGB32 (BYVAL hDC AS HDC, BYVAL pargb AS DWORD PTR, BYVAL hbmp AS HBITMAP, BYVAL sizeImage AS SIZE, BYVAL cxRow AS LONG) AS BOOLEAN
   IF hDC = NULL OR pargb = NULL OR hbmp = NULL THEN RETURN FALSE
   DIM bmi AS BITMAPINFO
   CMenu.InitBitmapInfo(@bmi, SIZEOF(bmi), sizeImage.cx, sizeImage.cy, 32)
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
PRIVATE FUNCTION CMenu.HasAlpha (BYVAL pargb AS DWORD PTR, BYVAL sizeImage AS SIZE, BYVAL cxRow AS LONG) AS BOOLEAN
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
PRIVATE FUNCTION CMenu.ConvertBufferToPARGB32 (BYVAL hPaintBuffer AS HPAINTBUFFER, BYVAL hDC AS HDC, BYVAL hIcon AS HICON, BYVAL sizeIcon AS SIZE) AS BOOLEAN
   IF hPaintBuffer = NULL OR hDC = NULL OR hIcon = NULL THEN RETURN FALSE
   DIM prgbQuad AS RGBQUAD PTR, cxRow AS LONG
   DIM hr AS HRESULT
   hr = GetBufferedPaintBits(hPaintBuffer, @prgbQuad, @cxRow)
   IF SUCCEEDED(hr) THEN
      DIM pargb AS DWORD PTR = CAST(DWORD PTR, prgbQuad)
      IF NOT CMenu.HasAlpha(pargb, sizeIcon, cxRow) THEN
         DIM info AS ICONINFO
         IF GetIconInfo(hicon, @info) THEN
            IF info.hbmMask THEN
               hr = CMenu.ConvertToPARGB32(hDC, pargb, info.hbmMask, sizeIcon, cxRow)
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
'                  If TRUE, CMenu.AddIconToMenuItem destroys the icon before returning.
' - phbmp        = Location where the bitmap representation of the icon is stored. Can be NULL.
' ========================================================================================
PRIVATE FUNCTION CMenu.AddIconToItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
   IF hMenu = NULL OR hIcon = NULL THEN RETURN FALSE
   DIM hbmp AS HBITMAP, sizIcon AS SIZE, rcIcon AS RECT
   sizIcon.cx = GetSystemMetrics(SM_CXSMICON)
   sizIcon.cy = GetSystemMetrics(SM_CYSMICON)
   SetRect(@rcIcon, 0, 0, sizIcon.cx, sizIcon.cy)
   DIM hdcDest AS HDC = CreateCompatibleDC(NULL)
   IF hdcDest = NULL THEN RETURN FALSE
   DIM hr AS HRESULT = CMenu.Create32BitHBITMAP(hdcDest, @sizIcon, NULL, @hbmp)
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
               hr = CMenu.ConvertBufferToPARGB32(hPaintBuffer, hdcDest, hIcon, sizIcon)
            END IF
            ' // This will write the buffer contents to the destination bitmap.
            EndBufferedPaint(hPaintBuffer, TRUE)
         END IF
         SelectObject(hdcDest, hbmpOld)
      END IF
   END IF
   DeleteDC(hdcDest)
   IF hr THEN hr = CMenu.AddBitmapToItem(hMenu, uItem, fByPosition, hbmp)
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
'     CMenu.DestroyBitmaps(hMenu)
'     CMenu.Destroy(hMenu)              
' ========================================================================================
SUB CMenu.DestroyBitmaps (BYVAL hMenu AS HMENU)
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

END NAMESPACE
