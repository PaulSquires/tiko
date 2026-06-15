' ########################################################################################
' Platform: Microsoft Windows
' Filename: CTab.inc
' Purpose:  Windows common controls - Tab control
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
#include once "win/commctrl.bi"
#include once "win/uxtheme.bi"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
' CTab class
' ########################################################################################

TYPE CTab

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC SUB AdjustRect (BYVAL hTab AS HWND, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT)
   DECLARE STATIC SUB AdjustRect (BYVAL hTab AS HWND, BYVAL fLarger AS BOOLEAN, BYVAL prc AS RECT PTR)
   DECLARE STATIC FUNCTION DeleteAllItems (BYVAL hTab AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
   DECLARE STATIC SUB DeselectAll (BYVAL hTab AS HWND, BYVAL fExcludeFocus AS BOOLEAN)
   DECLARE STATIC FUNCTION GetCurFocus (BYVAL hTab AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetCurSel (BYVAL hTab AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetExtendedStyle (BYVAL hTab AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetImageIndex (BYVAL hTab AS HWND, BYVAL iItem AS DWORD) AS LONG
   DECLARE STATIC FUNCTION GetImageList (BYVAL hTab AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF tcitem AS TCITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL ptcitem AS TCITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemCount (BYVAL hTab AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD) AS RECT
   DECLARE STATIC FUNCTION GetRowCount (BYVAL hTab AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetToolTips (BYVAL hTab AS HWND) AS HWND
   DECLARE STATIC FUNCTION HighlightItem (BYVAL hTab AS HWND, BYVAL idItem AS LONG, BYVAL fHighlight AS WORD) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hTab AS HWND, BYVAL pInfo AS TCHITTESTINFO PTR) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hTab AS HWND, BYREF info AS TCHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION InsertItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL pitem AS TCITEMW PTR) AS LONG
   DECLARE STATIC FUNCTION InsertItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF item AS TCITEMW) AS LONG
   DECLARE STATIC FUNCTION InsertTab (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0) AS LONG
   DECLARE STATIC FUNCTION AddTab (BYVAL hTab AS HWND, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS LPARAM = 0) AS LONG
   DECLARE STATIC SUB RemoveImage (BYVAL hTab AS HWND, BYVAL iImage AS LONG)
   DECLARE STATIC SUB SetCurFocus (BYVAL hTab AS HWND, BYVAL iItem AS LONG)
   DECLARE STATIC FUNCTION SetCurSel (BYVAL hTab AS HWND, BYVAL iItem AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetExtendedStyle (BYVAL hTab AS HWND, BYVAL dwExStyle AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetImageList (BYVAL hTab AS HWND, BYVAL himl AS HIMAGELIST) AS BOOLEAN
   DECLARE STATIC FUNCTION SetImageIndex (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYREF pitem AS TCITEMW PTR) AS LONG
   DECLARE STATIC FUNCTION SetItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYREF item AS TCITEMW) AS LONG
   DECLARE STATIC FUNCTION SetItemExtra (BYVAL hTab AS HWND, BYVAL cb AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemSize (BYVAL hTab AS HWND, BYVAL x AS LONG, BYVAL y AS LONG) AS DWORD
   DECLARE STATIC FUNCTION SetMinTabWidth (BYVAL hTab AS HWND, BYVAL cx AS LONG) AS LONG
   DECLARE STATIC SUB SetPadding (BYVAL hTab AS HWND, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER)
   DECLARE STATIC FUNCTION SetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC SUB SetToolTips (BYVAL hTab AS HWND, BYVAL hwndTT AS HWND)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CTab
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CTab
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Calculates a tab control's display area given a window rectangle, or calculates the
' window rectangle that would correspond to a specified display area.
' ========================================================================================
PRIVATE SUB CTab.AdjustRect (BYVAL hTab AS HWND, BYVAL fLarger AS BOOLEAN, BYVAL prc AS RECT PTR)
   SendMessageW hTab, TCM_ADJUSTRECT, fLarger, CAST(LPARAM, prc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTab.AdjustRect (BYVAL hTab AS HWND, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT)
   SendMessageW hTab, TCM_ADJUSTRECT, fLarger, CAST(LPARAM, @rc)
END SUB
' ========================================================================================

' ========================================================================================
' * Removes all items from a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.DeleteAllItems (BYVAL hTab AS HWND) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_DELETEALLITEMS, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Removes an item from a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.DeleteItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_DELETEITEM, iItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resets items in a tab control, clearing any that were set to the TCIS_BUTTONPRESSED state.
' ========================================================================================
PRIVATE SUB CTab.DeselectAll (BYVAL hTab AS HWND, BYVAL fExcludeFocus AS BOOLEAN)
   SendMessageW hTab, TCM_DESELECTALL, fExcludeFocus, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Returns the index of the item that has the focus in a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetCurFocus (BYVAL hTab AS HWND) AS LONG
   RETURN SendMessageW(hTab, TCM_GETCURFOCUS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines the currently selected tab in a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetCurSel (BYVAL hTab AS HWND) AS LONG
   RETURN SendMessageW(hTab, TCM_GETCURSEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the extended styles that are currently in use for the tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetExtendedStyle (BYVAL hTab AS HWND) AS DWORD
   RETURN SendMessageW(hTab, TCM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the 0-based index in the tab control's image list.
' Returns the index of the image or -1 if not found.
' ========================================================================================
PRIVATE FUNCTION CTab.GetImageIndex (BYVAL hTab AS HWND, BYVAL iItem AS DWORD) AS LONG
   DIM ttc_item AS TCITEMW
   ttc_item.mask = TCIF_IMAGE
   FUNCTION = -1
   IF SendMessageW(hTab, TCM_GETITEMW, cast(WPARAM, iItem), cast(LPARAM, @ttc_item)) THEN
      FUNCTION = ttc_item.iImage
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the image list associated with a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetImageList (BYVAL hTab AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hTab, TCM_GETIMAGELIST, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves information about a tab in a tab control.
' Usage example:
' DIM hTab AS HWND = GetDlgItem(hwnd, IDC_TAB)
' DIM tcitem AS TCITEMW
' tcitem.mask = TCIF_TEXT 
' DIM wszText AS WSTRING * 260
' tcitem.pszText = @wszText
' tcitem.cchTextMax = 260
' CTab.GetItem(hTab, 0, tcitem)
' print *tcitem.pszText
' ========================================================================================
PRIVATE FUNCTION CTab.GetItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF tcitem AS TCITEMW) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_GETITEMW, iItem, CAST(LPARAM, @tcitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTab.GetItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL ptcitem AS TCITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_GETITEMW, iItem, CAST(LPARAM, ptcitem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of tabs in the tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetItemCount (BYVAL hTab AS HWND) AS LONG
   RETURN SendMessageW(hTab, TCM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the bounding rectangle for a tab in a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_GETITEMRECT, iItem, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTab.GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_GETITEMRECT, iItem, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTab.GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD) AS RECT
   DIM rc AS RECT
   SendMessageW(hTab, TCM_GETITEMRECT, iItem, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of rows of tabs in the tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetRowCount (BYVAL hTab AS HWND) AS LONG
   RETURN SendMessageW(hTab, TCM_GETROWCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the name of a tab in a Tab control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTab.GetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
   DIM ttc_item AS TCITEMW
   ttc_item.mask = TCIF_TEXT
   ttc_item.pszText = pwszText
   ttc_item.cchTextMax = cchTextMax
   RETURN SendMessageW(hTab, TCM_GETITEMW, cast(WPARAM, nTabIndex), cast(LPARAM, @ttc_item))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Gets the name of a tab in a Tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD) AS DWSTRING
   DIM wszText AS WSTRING * 260
   DIM ttc_item AS TCITEMW
   ttc_item.mask = TCIF_TEXT
   ttc_item.pszText = @wszText
   ttc_item.cchTextMax = SIZEOF(wszText)\2
   SendMessageW(hTab, TCM_GETITEMW, cast(WPARAM, nTabIndex), cast(LPARAM, @ttc_item))
   RETURN wszText
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the ToolTip control associated with a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.GetToolTips (BYVAL hTab AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hTab, TCM_GETTOOLTIPS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the highlight state of a tab item.
' ========================================================================================
PRIVATE FUNCTION CTab.HighlightItem (BYVAL hTab AS HWND, BYVAL idItem AS LONG, BYVAL fHighlight AS WORD) AS LONG
   RETURN SendMessageW(hTab, TCM_HIGHLIGHTITEM, idItem, MAKELONG(fHighlight, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which tab, if any, is at a specified screen position.
' ========================================================================================
PRIVATE FUNCTION CTab.HitTest (BYVAL hTab AS HWND, BYVAL pInfo AS TCHITTESTINFO PTR) AS LONG
   RETURN SendMessageW(hTab, TCM_HITTEST, 0, CAST(LPARAM, pInfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTab.HitTest (BYVAL hTab AS HWND, BYREF info AS TCHITTESTINFO) AS LONG
   RETURN SendMessageW(hTab, TCM_HITTEST, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new tab in a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.InsertItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL pitem AS TCITEMW PTR) AS LONG
   RETURN SendMessageW(hTab, TCM_INSERTITEMW, iItem, CAST(LPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTab.InsertItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF item AS TCITEMW) AS LONG
   RETURN SendMessageW(hTab, TCM_INSERTITEMW, iItem, CAST(LPARAM, @Item))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Inserts a new tab in a tab control.
' - hTab: Handle to the tab control.
' - nTabInxex = Zero-based index of the tab
' - iImage = Zero-based index of the image in the image list or -1 for no image.
' - pwszText = Pointer to a null-terminated string that contains the tab text when item
'     information is being set.
' - lParam: Application-defined data associated with the tab control item.
' Returns the index of the new tab if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CTab.InsertTab (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0) AS LONG
   IF pwszText = NULL THEN RETURN -1
   DIM ttc_item AS TCITEMW
   ttc_item.mask = TCIF_TEXT OR TCIF_IMAGE OR TCIF_RTLREADING OR TCIF_PARAM OR TCIF_STATE OR TCIS_BUTTONPRESSED OR TCIS_HIGHLIGHTED
   ttc_item.pszText = pwszText
   ttc_item.cchTextMax = LEN(*pwszText)
   ttc_item.iImage = iImage
   ttc_item.lParam = lParam
   RETURN SendMessageW(hTab, TCM_INSERTITEMW, cast(WPARAM, nTabIndex), cast(..LPARAM, @ttc_item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of tabs and calls InsertTab to add a new tab.
' ========================================================================================
PRIVATE FUNCTION CTab.AddTab (BYVAL hTab AS HWND, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0) AS LONG
   IF pwszText = NULL THEN RETURN -1
   DIM nTabIndex AS LONG = SendMessageW(hTab, TCM_GETITEMCOUNT, 0, 0)
   RETURN CTab.InsertTab(hTab, nTabIndex, iImage, pwszText, lParam)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an image from a tab control's image list.
' ========================================================================================
PRIVATE SUB CTab.RemoveImage (BYVAL hTab AS HWND, BYVAL iImage AS LONG)
   SendMessageW hTab, TCM_REMOVEIMAGE, iImage, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the focus to a specified tab in a tab control.
' ========================================================================================
PRIVATE SUB CTab.SetCurFocus (BYVAL hTab AS HWND, BYVAL iItem AS LONG)
   SendMessageW hTab, TCM_SETCURFOCUS, iItem, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Selects a tab in a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.SetCurSel (BYVAL hTab AS HWND, BYVAL iItem AS LONG) AS LONG
   RETURN SendMessageW(hTab, TCM_SETCURSEL, iItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the extended styles that the tab control will use.
' ========================================================================================
PRIVATE FUNCTION CTab.SetExtendedStyle (BYVAL hTab AS HWND, BYVAL dwExStyle AS DWORD) AS DWORD
   RETURN SendMessageW(hTab, TCM_SETEXTENDEDSTYLE, 0, dwExStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.SetImageList (BYVAL hTab AS HWND, BYVAL himl AS HIMAGELIST) AS BOOLEAN
    RETURN SendMessageW(hTab, TCM_SETIMAGELIST, 0, CAST(LPARAM, himl))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the zero-based index in the tab control's image list.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTab.SetImageIndex (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG) AS BOOLEAN
   DIM ttc_item AS TCITEMW
   ttc_item.mask = TCIF_IMAGE
   ttc_item.iImage = iImage
   RETURN SendMessageW(hTab, TCM_SETITEMW, iItem, cast(LPARAM, @ttc_item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets some or all of a tab's attributes.
' ========================================================================================
PRIVATE FUNCTION CTab.SetItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYREF pitem AS TCITEMW PTR) AS LONG
   RETURN SendMessageW(hTab, TCM_SETITEMW, iItem, CAST(LPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTab.SetItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYREF item AS TCITEMW) AS LONG
   RETURN SendMessageW(hTab, TCM_SETITEMW, iItem, CAST(LPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the number of bytes per tab reserved for application-defined data in a tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.SetItemExtra (BYVAL hTab AS HWND, BYVAL cb AS LONG) AS BOOLEAN
   RETURN SendMessageW(hTab, TCM_SETITEMEXTRA, cb, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width and height of tabs in a fixed-width or owner-drawn tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.SetItemSize (BYVAL hTab AS HWND, BYVAL x AS LONG, BYVAL y AS LONG) AS DWORD
   RETURN SendMessageW(hTab, TCM_SETITEMSIZE, 0, MAKELONG(x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width and height of tabs in a fixed-width or owner-drawn tab control.
' ========================================================================================
PRIVATE FUNCTION CTab.SetMinTabWidth (BYVAL hTab AS HWND, BYVAL cx AS LONG) AS LONG
   RETURN SendMessageW(hTab, TCM_SETMINTABWIDTH, 0, cx)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the amount of space (padding) around each tab's icon and label in a tab control.
' ========================================================================================
PRIVATE SUB CTab.SetPadding (BYVAL hTab AS HWND, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER)
   SendMessageW hTab, TCM_SETPADDING, 0, MAKELONG(cx, cy)
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the name of a tab in a Tab control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTab.SetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DIM ttc_item AS TCITEMW
   ttc_item.mask = TCIF_TEXT
   ttc_item.pszText = pwszText
   ttc_item.cchTextMax = LEN(*pwszText)
   RETURN SendMessageW(hTab, TCM_SETITEMW, cast(WPARAM, nTabIndex), cast(LPARAM, @ttc_item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns a ToolTip control to a tab control.
' ========================================================================================
PRIVATE SUB CTab.SetToolTips (BYVAL hTab AS HWND, BYVAL hwndTT AS HWND)
   SendMessageW hTab, TCM_SETTOOLTIPS, CAST(WPARAM, hwndTT), 0
END SUB
' ========================================================================================

END NAMESPACE
