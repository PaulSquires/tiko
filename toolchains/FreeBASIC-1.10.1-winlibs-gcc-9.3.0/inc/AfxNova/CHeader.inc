' ########################################################################################
' Platform: Microsoft Windows
' Filename: CHeader.inc
' Purpose:  Windows common controls - Header control
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
#include once "win/uxtheme.bi"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
' CHeader class
' ########################################################################################

TYPE CHeader

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION ClearAllFilters (BYVAL hHeader AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION ClearFilter (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION CreateDragImage (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS HIMAGELIST
   DECLARE STATIC FUNCTION DeleteItem (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION EditFilter (BYVAL hHeader AS HWND, BYVAL i AS LONG, BYVAL fDiscardChanges AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBitmapMargin (BYVAL hHeader AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetImageList (BYVAL hHeader AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetItem (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL phdi AS HDITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF hdi AS HDITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS HDITEMW
   DECLARE STATIC FUNCTION GetItemCount (BYVAL hHeader AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemOrder (BYVAL hHeader AS HWND, BYVAL nItem AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION GetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS BOOLEAN
   DECLARE STATIC FUNCTION GetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION GetItemWidth (BYVAL hHeader AS HWND, BYVAL nItem AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetOrderArray (BYVAL hHeader AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS LONG
   DECLARE STATIC FUNCTION GetStateImageList (BYVAL hHeader AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION HitTest (BYVAL hHeader AS HWND, BYVAL phdhti AS HDHITTESTINFO PTR) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hHeader AS HWND, BYREF hdhti AS HDHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hHeader AS HWND) AS HDHITTESTINFO
   DECLARE STATIC FUNCTION InsertItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS LONG
   DECLARE STATIC FUNCTION InsertItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS LONG
   DECLARE STATIC FUNCTION Layout (BYVAL hHeader AS HWND, BYVAL phdl AS HDLAYOUT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION Layout (BYVAL hHeader AS HWND, BYREF hdl AS HDLAYOUT) AS BOOLEAN
   DECLARE STATIC FUNCTION Layout (BYVAL hHeader AS HWND) AS HDLAYOUT
   DECLARE STATIC FUNCTION OrderToIndex (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetBitmapMargin (BYVAL hHeader AS HWND, BYVAL iWidth AS DWORD) AS LONG
   DECLARE STATIC FUNCTION SetFilterChangeTimeout (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetHotDivider (BYVAL hHeader AS HWND, BYVAL fPos AS BOOLEAN, BYVAL dwInputValue AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetImageList (BYVAL hHeader AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS LONG
   DECLARE STATIC FUNCTION SetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS LONG
   DECLARE STATIC FUNCTION SetItemText (BYVAL hHeader AS HWND, BYVAL nItem AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetText (BYVAL hHeader AS HWND, BYVAL nItem AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemOrder (BYVAL hHeader AS HWND, BYVAL nItem AS LONG, BYVAL iOrder AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemWidth (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL nWidth AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetOrderArray (BYVAL hHeader AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetStateImageList (BYVAL hHeader AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST

#if _WIN32_WINNT >= &h0600
   DECLARE STATIC FUNCTION GetFocusedItem (BYVAL hHeader AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetOverflowRect (BYVAL hHeader AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetOverflowRect (BYVAL hHeader AS HWND, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetOverflowRect (BYVAL hHeader AS HWND) AS RECT
   DECLARE STATIC FUNCTION SetFocusedItem (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
#endif

   DECLARE STATIC FUNCTION SetDarkMode(BYVAL hHeader AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode(BYVAL hHeader AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CHeader
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CHeader
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Clears all of the filters for a given header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.ClearAllFilters (BYVAL hHeader AS HWND) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_CLEARFILTER, -1, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Clears the filter for a given header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.ClearFilter (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_CLEARFILTER, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a transparent version of an item image within an existing header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.CreateDragImage (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS HIMAGELIST
   RETURN cast(HIMAGELIST, SendMessageW(hHeader, HDM_CREATEDRAGIMAGE, i, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an item from a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.DeleteItem (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_DELETEITEM, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves the input focus to the edit box when a filter button has the focus.
' ========================================================================================
PRIVATE FUNCTION CHeader.EditFilter (BYVAL hHeader AS HWND, BYVAL i AS LONG, BYVAL fDiscardChanges AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_EDITFILTER, i, fDiscardChanges)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the margin (in pixels) of a bitmap in an existing header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetBitmapMargin (BYVAL hHeader AS HWND) AS LONG
   RETURN SendMessageW(hHeader, HDM_GETBITMAPMARGIN, 0, 0)
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Gets the item in a header control that has the focus.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetFocusedItem (BYVAL hHeader AS HWND) AS LONG
   RETURN SendMessageW(hHeader, HDM_GETFOCUSEDITEM, 0, 0)
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Gets the handle to the image list that has been set for an existing header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetImageList (BYVAL hHeader AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hHeader, HDM_GETIMAGELIST, HDSIL_NORMAL, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about an item in a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItem (BYVAL hHeader AS HWND, BYVAL i AS LONG, BYVAL phdi AS HDITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_GETITEMW, i, CAST(LPARAM, phdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItem (BYVAL hHeader AS HWND, BYVAL i AS LONG, BYREF hdi AS HDITEMW) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_GETITEMW, i, CAST(LPARAM, @hdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItem (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS HDITEMW
   DIM hdi AS HDITEMW
   SendMessageW(hHeader, HDM_GETITEMW, i, CAST(LPARAM, @hdi))
   RETURN hdi
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a count of the items in a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemCount (BYVAL hHeader AS HWND) AS LONG
   RETURN SendMessageW(hHeader, HDM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Gets the coordinates of the drop-down button for a specfied item in a header control.
' The header control must be of type HDF_SPLITBUTTON.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   IF prc = NULL THEN RETURN FALSE
   RETURN SendMessageW(hHeader, HDM_GETITEMDROPDOWNRECT, iItem, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF rc AS RECT) AS BOOLEAN
   IF VARPTR(rc) = 0 THEN RETURN FALSE
   RETURN SendMessageW(hHeader, HDM_GETITEMDROPDOWNRECT, iItem, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS RECT
   DIM rc AS RECT
   SendMessageW(hHeader, HDM_GETITEMDROPDOWNRECT, iItem, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Gets the bounding rectangle for a given item in a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_GETITEMRECT, iItem, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_GETITEMRECT, iItem, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS RECT
   DIM rc AS RECT
   SendMessageW(hHeader, HDM_GETITEMRECT, iItem, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the order of the specified item of a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemOrder (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS LONG
   DIM hdi AS HDITEMW
   hdi.mask = HDI_ORDER
   IF SendMessageW(hHeader, HDM_GETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi))) THEN RETURN hdi.iOrder
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of the specified column.
' - hHeader: Handle to the header control.
' - nItem: The index of the item for which information is to be retrieved.
' - pwszText: A pointer to an item string. If the text is being retrieved from the control,
'   this member must be initialized to point to a character buffer. If this member is set
'   to LPSTR_TEXTCALLBACK, the control will request text information for this item by sending
'   an HDN_GETDISPINFO notification code. Note that although the header control allows a
'   string of any length to be stored as item text, only the first 260 characters are displayed.
' - cchTextMax : Maximum number of characters to return. Both this value and the size of the
'   buffer pointed by pwszText must be one character bigger that the wanted length of the text
'   to return to make room for the null character terminator.
' Return value: Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.psztext = pwszText
   hdi.cchtextmax = cchtextmax
   RETURN SendMessageW(hHeader, HDM_GETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS DWSTRING
   DIM wszText AS WSTRING * MAX_PATH + 1
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.psztext = @wszText
   hdi.cchtextmax = MAX_PATH + 1
   SendMessageW(hHeader, HDM_GETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
   RETURN wszText
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of the specified column.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.psztext = pwszText
   hdi.cchtextmax = cchtextmax
   RETURN SendMessageW(hHeader, HDM_GETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS DWSTRING
   DIM wszText AS WSTRING * MAX_PATH + 1
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.psztext = @wszText
   hdi.cchtextmax = MAX_PATH + 1
   SendMessageW(hHeader, HDM_GETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
   RETURN wszText
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the specified item of a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetItemWidth (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS LONG
   DIM hdi AS HDITEMW
   hdi.mask = HDI_WIDTH
   IF SendMessageW(hHeader, HDM_GETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi))) THEN RETURN hdi.cxy
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current left-to-right order of items in a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetOrderArray (BYVAL hHeader AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS LONG
   RETURN SendMessageW(hHeader, HDM_GETORDERARRAY, iCount, CAST(LPARAM, lpiArray))
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Gets the coordinates of the drop-down overflow area for a specified header control.
' The header control must be of type HDF_SPLITBUTTON.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetOverflowRect (BYVAL hHeader AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   IF prc = NULL THEN RETURN FALSE
   RETURN SendMessageW(hHeader, HDM_GETOVERFLOWRECT, 0, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetOverflowRect (BYVAL hHeader AS HWND, BYREF rc AS RECT) AS BOOLEAN
   IF VARPTR(rc) = 0 THEN RETURN FALSE
   RETURN SendMessageW(hHeader, HDM_GETOVERFLOWRECT, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.GetOverflowRect (BYVAL hHeader AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hHeader, HDM_GETOVERFLOWRECT, 0, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Gets the handle to the image list that has been set for an existing header control state.
' ========================================================================================
PRIVATE FUNCTION CHeader.GetStateImageList (BYVAL hHeader AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hHeader, HDM_GETIMAGELIST, HDSIL_STATE, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests a point to determine which header item, if any, is at the specified point.
' ========================================================================================
PRIVATE FUNCTION CHeader.HitTest (BYVAL hHeader AS HWND, BYVAL phdhti AS HDHITTESTINFO PTR) AS LONG
   IF phdhti = NULL THEN RETURN 0
   RETURN SendMessageW(hHeader, HDM_HITTEST, 0, CAST(LPARAM, phdhti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.HitTest (BYVAL hHeader AS HWND, BYREF hdhti AS HDHITTESTINFO) AS LONG
   IF VARPTR(hdhti) = 0 THEN RETURN 0
   RETURN SendMessageW(hHeader, HDM_HITTEST, 0, CAST(LPARAM, @hdhti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.HitTest (BYVAL hHeader AS HWND) AS HDHITTESTINFO
   DIM hdhti AS HDHITTESTINFO
   SendMessageW(hHeader, HDM_HITTEST, 0, CAST(LPARAM, @hdhti))
   RETURN hdhti
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item into a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.InsertItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS LONG
   RETURN SendMessageW(hHeader, HDM_INSERTITEMW, i, CAST(LPARAM, phdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.InsertItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS LONG
   RETURN SendMessageW(hHeader, HDM_INSERTITEMW, i, CAST(LPARAM, @hdi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the correct size and position of a header control within the parent window.
' ========================================================================================
PRIVATE FUNCTION CHeader.Layout (BYVAL hHeader AS HWND, BYVAL phdl AS HDLAYOUT PTR) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_LAYOUT, 0, CAST(LPARAM, phdl))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.Layout (BYVAL hHeader AS HWND, BYREF hdl AS HDLAYOUT) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_LAYOUT, 0, CAST(LPARAM, @hdl))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.Layout (BYVAL hHeader AS HWND) AS HDLAYOUT
   DIM hdl AS HDLAYOUT
   SendMessageW(hHeader, HDM_LAYOUT, 0, CAST(LPARAM, @hdl))
   RETURN hdl
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves an index value for an item based on its order in the header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.OrderToIndex (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS LONG
   RETURN SendMessageW(hHeader, HDM_ORDERTOINDEX, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width of the margin for a bitmap in an existing header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetBitmapMargin (BYVAL hHeader AS HWND, BYVAL iWidth AS DWORD) AS LONG
   RETURN SendMessageW(hHeader, HDM_SETBITMAPMARGIN, iWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the timeout interval between the time a change takes place in the filter
' attributes and the posting of an HDN_FILTERCHANGE notification.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetFilterChangeTimeout (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS LONG
   RETURN SendMessageW(hHeader, HDM_SETFILTERCHANGETIMEOUT, 0, i)
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Sets the focus to a specified item in a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetFocusedItem (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_SETFOCUSEDITEM, 0, iItem)
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Changes the color of a divider between header items to indicate the destination of an
' external drag-and-drop operation.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetHotDivider (BYVAL hHeader AS HWND, BYVAL fPos AS BOOLEAN, BYVAL dwInputValue AS LONG) AS LONG
   RETURN SendMessageW(hHeader, HDM_SETHOTDIVIDER, fPos, dwInputValue)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to an existing header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetImageList (BYVAL hHeader AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   RETURN CAsT (HIMAGELIST, SendMessageW(hHeader, HDM_SETIMAGELIST, 0, CAST(LPARAM, himl)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the attributes of the specified item in a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS LONG
   RETURN SendMessageW(hHeader, HDM_SETITEMW, i, CAST(LPARAM, phdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CHeader.SetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS LONG
   RETURN SendMessageW(hHeader, HDM_SETITEMW, i, CAST(LPARAM, @hdi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the order of the specified item of a header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetItemOrder (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL iOrder AS LONG) AS BOOLEAN
   DIM hdi AS HDITEMW
   hdi.mask = HDI_ORDER
   hdi.iOrder = iOrder
   RETURN SendMessageW(hHeader, HDM_SETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of the specified item.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.cchTextMax = LEN(*pwszText)
   hdi.pszText = pwszText
   RETURN SendMessageW(hHeader, HDM_SETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Sets the text of the specified item. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.cchTextMax = LEN(*pwszText)
   hdi.pszText = pwszText
   RETURN SendMessageW(hHeader, HDM_SETITEMW, iItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the width of the specified item of a header control.
' Returns nonzero upon success, or zero otherwise.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetItemWidth (BYVAL hHeader AS HWND, BYVAL nItem AS LONG, BYVAL nWidth AS LONG) AS BOOLEAN
   DIM hdi AS HDITEMW
   hdi.mask = HDI_WIDTH
   hdi.cxy = nWidth
   RETURN SendMessageW(hHeader, HDM_SETITEMW, nItem, CAST(LPARAM, CAST(HDITEMW PTR, @hdi)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the left-to-right order of header items.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetOrderArray (BYVAL hHeader AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS BOOLEAN
   RETURN SendMessageW(hHeader, HDM_SETORDERARRAY, iCount, CAST(LPARAM, lpiArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to an existing header control.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetStateImageList (BYVAL hHeader AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hHeader, HDM_SETIMAGELIST, HDSIL_STATE, CAST(LPARAM, himl)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the header dark mode.
' ========================================================================================
PRIVATE FUNCTION CHeader.SetDarkMode(BYVAL hHeader AS HWND) AS HRESULT
   RETURN SetWindowTheme(hHeader, "DarkMode_ItemsView", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Removes the header dark mode.
' ========================================================================================
PRIVATE FUNCTION CHeader.RemoveDarkMode(BYVAL hHeader AS HWND) AS HRESULT
   RETURN SetWindowTheme(hHeader, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
