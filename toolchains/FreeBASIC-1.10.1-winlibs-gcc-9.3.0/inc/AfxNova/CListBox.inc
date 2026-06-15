' ########################################################################################
' Platform: Microsoft Windows
' Filename: CListBox.inc
' Purpose:  Windows common controls - ListBox
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
' CListBox class
' ########################################################################################

TYPE CListBox

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION AddFile (BYVAL hListBox AS HWND, BYVAL pwszFileName AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION AddItemData (BYVAL hListBox AS HWND, BYVAL pData AS ANY PTR) AS LONG
   DECLARE STATIC FUNCTION AddString (BYVAL hListBox AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION CalcHorizontalExtent (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION DeleteString (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION Dir (BYVAL hListBox AS HWND, BYVAL Attr AS DWORD, BYVAL pwszFileSpec AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION Disable (BYVAL hListBox AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Enable (BYVAL hListBox AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION FindItemData (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS ANY PTR) AS LONG
   DECLARE STATIC FUNCTION FindString (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pwszString AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION FindStringExact (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pwszSearchString AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION GetAnchorIndex (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetCaretIndex (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetCount (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetCurSel (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetHorizontalExtent (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetListBoxInfo (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS ANY PTR
   DECLARE STATIC FUNCTION GetItemHeight (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL prc AS RECT PTR) AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYREF rc AS RECT) AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetLocale (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetSel (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSelCount (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetSelect (BYVAL hListBox AS HWND, BYVAL startIndex AS LONG = 0) AS LONG
   DECLARE STATIC FUNCTION GetSelItems (BYVAL hListBox AS HWND, BYVAL items AS DWORD, BYVAL rgItems AS LONG PTR) AS LONG
   DECLARE STATIC FUNCTION GetText (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION GetTextLen (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetTopIndex (BYVAL hListBox AS HWND) AS LONG
   DECLARE STATIC FUNCTION InitStorage (BYVAL hListBox AS HWND, BYVAL nItems AS DWORD, BYVAL nBytes AS DWORD) AS LONG
   DECLARE STATIC FUNCTION InsertItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pData AS ANY PTR) AS LONG
   DECLARE STATIC FUNCTION InsertString (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION ItemFromPoint (BYVAL hListBox AS HWND, BYVAL x AS SHORT, BYVAL y AS SHORT) AS LONG
   DECLARE STATIC FUNCTION ReplaceString (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszNewText AS WSTRING PTR, BYVAL pNewData AS ANY PTR = NULL) AS LONG
   DECLARE STATIC SUB ResetContent (BYVAL hListBox AS HWND)
   DECLARE STATIC FUNCTION SelectItemData (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS ANY PTR) AS LONG
   DECLARE STATIC FUNCTION SelectString (BYVAL hListBox AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION SelectString (BYVAL hListBox AS HWND, BYVAL index AS LONG =-1) AS LONG
   DECLARE STATIC FUNCTION SelItemRange (BYVAL hListBox AS HWND, BYVAL fSel AS BOOLEAN, BYVAL startIndex AS SHORT, BYVAL endIndex AS SHORT) AS LONG
   DECLARE STATIC FUNCTION SelItemRangeEx (BYVAL hListBox AS HWND, BYVAL startIndex AS LONG, BYVAL endIndex AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetAnchorIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetCaretIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL fVisibility AS BOOLEAN = FALSE) AS LONG
   DECLARE STATIC SUB SetColumnWidth (BYVAL hListBox AS HWND, BYVAL nWidth AS DWORD)
   DECLARE STATIC FUNCTION SetCount (BYVAL hListBox AS HWND, BYVAL nCount AS DWORD) AS LONG
   DECLARE STATIC FUNCTION SetCurSel (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC SUB SetHorizontalExtent (BYVAL hListBox AS HWND, BYVAL cxExtent AS LONG)
   DECLARE STATIC FUNCTION SetItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pData AS ANY PTR) AS LONG
   DECLARE STATIC FUNCTION SetItemHeight (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL nHeight AS DWORD) AS LONG
   DECLARE STATIC FUNCTION SetLocale (BYVAL hListBox AS HWND, BYVAL wLocaleID AS DWORD) AS LONG
   DECLARE STATIC FUNCTION SetSel (BYVAL hListBox AS HWND, BYVAL fSelect AS BOOLEAN, BYVAL index AS LONG = -1) AS LONG
   DECLARE STATIC FUNCTION SetText (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszNewText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION UnselectString (BYVAL hListBox AS HWND, BYVAL index AS LONG = -1) AS LONG
   DECLARE STATIC SUB SetTabStops (BYVAL hListBox AS HWND, BYVAL cTabs AS LONG, BYVAL prgTabs AS LONG PTR)
   DECLARE STATIC FUNCTION SetTopIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetDarkMode (BYVAL hListBox AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode (BYVAL hListBox AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CListBox
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CListBox
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Enables the control.
' Return value: False if the control was previous enabled; otherwise TRUE
' ========================================================================================
PRIVATE FUNCTION CListBox.Enable (BYVAL hListBox AS HWND) AS BOOLEAN
   RETURN EnableWindow(hListBox, TRUE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Disables the control
' Return value: False if the control was previous disabled; otherwise TRUE
' ========================================================================================
PRIVATE FUNCTION CListBox.Disable (BYVAL hListBox AS HWND) AS BOOLEAN
   DIM res AS LONG = EnableWindow(hListBox, FALSE)
   DIM bEnable AS BOOLEAN
   IF res = 0 THEN bEnable = TRUE ELSE bEnable = FALSE
   RETURN bEnable
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds the specified filename to a list box that contains a directory listing.
' ========================================================================================
PRIVATE FUNCTION CListBox.AddFile (BYVAL hListBox AS HWND, BYVAL pwszFileName AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_ADDFILE, 0, CAST(LPARAM, pwszFileName))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds a string to a list box. If the list box does not have the LBS_SORT style, the
' string is added to the end of the list. Otherwise, the string is inserted into the list
' and the list is sorted.
' ========================================================================================
PRIVATE FUNCTION CListBox.AddString (BYVAL hListBox AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_ADDSTRING, 0, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes a string in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.DeleteString (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_DELETESTRING, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds names to the list displayed by a list box. The message adds the names of
' directories and files that match a specified string and set of file attributes.
' LB_DIR can also add mapped drive letters to the list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.Dir (BYVAL hListBox AS HWND, BYVAL Attr AS DWORD, BYVAL pwszFileSpec AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_DIR, Attr, CAST(LPARAM, pwszFileSpec))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Finds the first string in a list box that begins with the specified string.
' ========================================================================================
PRIVATE FUNCTION CListBox.FindString (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pwszString AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_FINDSTRING, indexStart, CAST(LPARAM, pwszString))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Finds the first list box string that exactly matches the specified string, except that
' the search is not case sensitive.
' ========================================================================================
PRIVATE FUNCTION CListBox.FindStringExact (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pwszSearchString AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_FINDSTRINGEXACT, indexStart, CAST(LPARAM, pwszSearchString))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the index of the anchor item--that is, the item from which a multiple selection
' starts. A multiple selection spans all items from the anchor item to the caret item.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetAnchorIndex (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETANCHORINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines the index of the item that has the focus rectangle in a multiple-selection
' list box. The item may or may not be selected.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetCaretIndex (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETCARETINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the number of items in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetCount (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the index of the currently selected item, if any, in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetCurSel (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, IIF((GetWindowLong(hListBox, GWL_STYLE) AND LBS_MULTIPLESEL), LB_GETCARETINDEX, LB_GETCURSEL), 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width, in pixels, that a list box can be scrolled horizontally (the scrollable
' width) if the list box has a horizontal scroll bar.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetHorizontalExtent (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETHORIZONTALEXTENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the number of items per column in a specified list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetListBoxInfo (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETLISTBOXINFO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the application-defined value associated with the specified list box item.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS ANY PTR
   RETURN cast(ANY PTR, SendMessageW(hListBox, LB_GETITEMDATA, index, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the height of items in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetItemHeight (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_GETITEMHEIGHT, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the dimensions of the rectangle that bounds a list box item as it is currently
' displayed in the list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL prc AS RECT PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_GETITEMRECT, index, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListBox.GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYREF rc AS RECT) AS LONG
   RETURN SendMessageW(hListBox, LB_GETITEMRECT, index, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListBox.GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS RECT
   DIM rc AS RECT
   SendMessageW(hListBox, LB_GETITEMRECT, index, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the current locale of the list box. You can use the locale to determine the correct
' sorting order of displayed text (for list boxes with the LBS_SORT style) and of text
' added by the LB_ADDSTRING message.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetLocale (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETLOCALE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the selection state of an item.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetSel (BYVAL hListBox AS HWND, BYVAL Index AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListBox, LB_GETSEL, Index, 0) > 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' * The listbox is searched to find the first selected item. If the item parameter is included,
' searching starts at that position to facilitate retrieving multiple selected items.
' If item is omitted, the search starts at the first data item. The index number of the
' selected item is returned as the result of the function. If no item is selected, the
' value -1 is returned.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetSelect (BYVAL hListBox AS HWND, BYVAL startIndex AS LONG = 0) AS LONG
   IF (GetWindowLongPtrW(hListBox, GWL_STYLE) AND LBS_EXTENDEDSEL) = LBS_EXTENDEDSEL THEN
      ' // Multiple-selection listbox
      ' // Search for the first selected item starting from startIndex (zero-based)
      DIM nCount AS LONG = SendMessageW(hListBox, LB_GETCOUNT, 0, 0)
      FOR selectedIndex AS LONG = startIndex TO nCount - 1
         IF SendMessageW(hListBox, LB_GETSEL, selectedIndex, 0) <> 0 THEN
            RETURN selectedIndex ' Zero-based index
         END IF
      NEXT
      ' // If no item is selected, return -1
      RETURN -1
   ELSE
      '// Single slection listbox
      RETURN SendMessageW(hListBox, IIF((GetWindowLong(hListBox, GWL_STYLE) AND LBS_MULTIPLESEL), LB_GETCARETINDEX, LB_GETCURSEL), 0, 0)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the total number of selected items in a multiple-selection list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetSelCount (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETSELCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Fills a buffer with an array of integers that specify the item numbers of selected items
' in a multiple-selection list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetSelItems (BYVAL hListBox AS HWND, BYVAL items AS DWORD, BYVAL prgItems AS LONG PTR) AS LONG
   RETURN SendMessage(hListBox, LB_GETSELITEMS, items, CAST(LPARAM, prgItems))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets a string from a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetText (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS DWSTRING
   DIM nLen AS LONG, buffer AS DWSTRING
   IF index < 0 THEN index = SendMessageW(hListBox, IIF((GetWindowLong(hListBox, GWL_STYLE) AND LBS_MULTIPLESEL), LB_GETCARETINDEX, LB_GETCURSEL), 0, 0)
   nLen = SendMessageW(hListBox, LB_GETTEXTLEN, index, 0)
   buffer = WSPACE(nLen + 1)
   SendMessageW hListBox, LB_GETTEXT, index, CAST(LPARAM, STRPTR(buffer))
   RETURN LEFT(buffer, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the length of a string in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetTextLen (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_GETTEXTLEN, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the index of the first visible item in a list box. Initially the item with index 0
' is at the top of the list box, but if the list box contents have been scrolled another
' item may be at the top.
' ========================================================================================
PRIVATE FUNCTION CListBox.GetTopIndex (BYVAL hListBox AS HWND) AS LONG
   RETURN SendMessageW(hListBox, LB_GETTOPINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Allocates memory for storing list box items. This message is used before an application
' adds a large number of items to a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.InitStorage (BYVAL hListBox AS HWND, BYVAL nItems AS DWORD, BYVAL nBytes AS DWORD) AS LONG
   RETURN SendMessageW(hListBox, LB_INITSTORAGE, nItems, nBytes)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Inserts a string into a list box. Unlike the LB_ADDSTRING message, the LB_INSERTSTRING
' message does not cause a list with the LBS_SORT style to be sorted.
' ========================================================================================
PRIVATE FUNCTION CListBox.InsertString (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_INSERTSTRING, index, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the zero-based index of the item nearest the specified point in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.ItemFromPoint (BYVAL hListBox AS HWND, BYVAL x AS SHORT, BYVAL y AS SHORT) AS LONG
   RETURN SendMessageW(hListBox, LB_ITEMFROMPOINT, 0, MAKELONG(x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes all items from a list box.
' ========================================================================================
PRIVATE SUB CListBox.ResetContent (BYVAL hListBox AS HWND)
   SendMessageW hListBox, LB_RESETCONTENT, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Searches a list box for an item that begins with the characters in a specified string.
' If a matching item is found, the item is selected.
' ========================================================================================
PRIVATE FUNCTION CListBox.SelectString (BYVAL hListBox AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_SELECTSTRING, start, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects one or more consecutive items in a multiple-selection list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.SelItemRange (BYVAL hListBox AS HWND, BYVAL fSel AS BOOLEAN, BYVAL startIndex AS SHORT, BYVAL endIndex AS SHORT) AS LONG
   RETURN SendMessageW(hListBox, LB_SELITEMRANGE, fSel, MAKELONG(startIndex, endIndex))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects one or more consecutive items in a multiple-selection list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.SelItemRangeEx (BYVAL hListBox AS HWND, BYVAL startIndex AS LONG, BYVAL endIndex AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_SELITEMRANGEEX, startIndex, endIndex)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the anchor item--that is, the item from which a multiple selection starts.
' A multiple selection spans all items from the anchor item to the caret item.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetAnchorIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_SETANCHORINDEX, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the focus rectangle to the item at the specified index in a multiple-selection list
' box. If the item is not visible, it is scrolled into view.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetCaretIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL fVisibility AS BOOLEAN = FALSE) AS LONG
   RETURN SendMessageW(hListBox, LB_SETCARETINDEX, index, cast(LPARAM, fVisibility))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width, in pixels, of all columns in a multiple-column list box (created with
' the LBS_MULTICOLUMN style).
' ========================================================================================
PRIVATE SUB CListBox.SetColumnWidth (BYVAL hListBox AS HWND, BYVAL nWidth AS DWORD)
   SendMessageW(hListBox, LB_SETCOLUMNWIDTH, nWidth, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the count of items in a list box created with the LBS_NODATA style and not created
' with the LBS_HASSTRINGS style.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetCount (BYVAL hListBox AS HWND, BYVAL nCount AS DWORD) AS LONG
   RETURN SendMessageW(hListBox, LB_SETCOUNT, nCount, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects a string and scroll it into view, if necessary. When the new string is selected,
' the list box removes the highlight from the previously selected string.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetCurSel (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_SETCURSEL, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' An application sends an LB_SETHORIZONTALEXTENT message to set the width, in pixels, by
' which a list box can be scrolled horizontally (the scrollable width). If the width of
' the list box is smaller than this value, the horizontal scroll bar horizontally scrolls
' items in the list box. If the width of the list box is equal to or greater than this
' value, the horizontal scroll bar is hidden.
' ========================================================================================
PRIVATE SUB CListBox.SetHorizontalExtent (BYVAL hListBox AS HWND, BYVAL cxExtent AS LONG)
   SendMessageW hListBox, LB_SETHORIZONTALEXTENT, cxExtent, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets a value associated with the specified item in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pData AS ANY PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_SETITEMDATA, index, cast(LPARAM, pData))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the height, in pixels, of items in a list box. If the list box has the
' LBS_OWNERDRAWVARIABLE style, this message sets the height of the item specified by the
' nHeight parameter. Otherwise, this message sets the height of all items in the list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetItemHeight (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL nHeight AS DWORD) AS LONG
   RETURN SendMessageW(hListBox, LB_SETITEMHEIGHT, index, nHeight)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the current locale of the list box. You can use the locale to determine the correct
' sorting order of displayed text (for list boxes with the LBS_SORT style) and of text
' added by the LB_ADDSTRING message.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetLocale (BYVAL hListBox AS HWND, BYVAL wLocaleID AS DWORD) AS LONG
   RETURN SendMessageW(hListBox, LB_SETLOCALE, wLocaleID, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects a string in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetSel (BYVAL hListBox AS HWND, BYVAL fSelect AS BOOLEAN, BYVAL index AS LONG = -1) AS LONG
   IF (GetWindowLongPtrW(hListBox, GWL_STYLE) AND LBS_EXTENDEDSEL) = LBS_EXTENDEDSEL THEN
      ' // Multiple-selection listbox
      RETURN SendMessageW(hListBox, LB_SETSEL, fSelect, index)
   ELSE
      '// Single slection listbox
      RETURN SendMessageW(hListBox, LB_SETCURSEL, index, 0)
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Selects the specified string in a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.SelectString (BYVAL hListBox AS HWND, BYVAL index AS LONG =-1) AS LONG
   IF (GetWindowLongPtrW(hListBox, GWL_STYLE) AND LBS_EXTENDEDSEL) = LBS_EXTENDEDSEL THEN
      ' // Multiple-selection listbox
      RETURN SendMessageW(hListBox, LB_SETSEL, CTRUE, index)
   ELSE
      '// Single slection listbox
      RETURN SendMessageW(hListBox, LB_SETCURSEL, Index, 0)
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Unselects the specified string in a multiple-selection list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.UnselectString (BYVAL hListBox AS HWND, BYVAL index AS LONG = -1) AS LONG
   IF (GetWindowLongPtrW(hListBox, GWL_STYLE) AND LBS_EXTENDEDSEL) = LBS_EXTENDEDSEL THEN
      ' // Multiple-selection listbox
      RETURN SendMessageW(hListBox, LB_SETSEL, FALSE, index)
   ELSE
      ' // Single slection listbox
      RETURN SendMessageW(hListBox, LB_SETCURSEL, -1, 0)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the tab-stop positions in a list box.
' ========================================================================================
PRIVATE SUB CListBox.SetTabStops (BYVAL hListBox AS HWND, BYVAL cTabs AS LONG, BYVAL prgTabs AS LONG PTR)
   SendMessageW hListBox, LB_SETTABSTOPS, cTabs, CAST(LPARAM, prgTabs)
END SUB
' ========================================================================================

' ========================================================================================
' * Ensures that a particular item in a list box is visible.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetTopIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hListBox, LB_SETTOPINDEX, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Replaces a string, and his associated data, into a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.ReplaceString (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszNewText AS WSTRING PTR, BYVAL pNewData AS ANY PTR = NULL) AS LONG
   DIM lRes AS LONG = SendMessageW(hListBox, LB_DELETESTRING, index, 0)
   IF lRes = LB_ERR THEN RETURN lRes
   ' // Insert the new string
   index = SendMessageW(hListBox, LB_INSERTSTRING, index, CAST(LPARAM, pwszNewText))
   IF index = LB_ERR OR index = LB_ERRSPACE THEN RETURN index
   lRes = SendMessageW(hListBox, LB_SETITEMDATA, index, CAST(LPARAM, pNewData))
   IF lRes = LB_ERR THEN RETURN lRes
   RETURN SendMessageW(hListBox, IIF((GetWindowLongPtrW(hListBox, GWL_STYLE) AND LBS_MULTIPLESEL), LB_SETSEL, LB_SETCURSEL), index, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListBox.SetText (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszNewText AS WSTRING PTR) AS LONG
   DIM lRes AS LONG = SendMessageW(hListBox, LB_DELETESTRING, index, 0)
   IF lRes = LB_ERR THEN RETURN lRes
   ' // Insert the new string
   index = SendMessageW(hListBox, LB_INSERTSTRING, index, CAST(LPARAM, pwszNewText))
   IF index = LB_ERR OR index = LB_ERRSPACE THEN RETURN index
   RETURN SendMessageW(hListBox, IIF((GetWindowLongPtrW(hListBox, GWL_STYLE) AND LBS_MULTIPLESEL), LB_SETSEL, LB_SETCURSEL), index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Calculates the size, in logical units, of the widest string item.
' ========================================================================================
PRIVATE FUNCTION CListBox.CalcHorizontalExtent (BYVAL hListBox AS HWND) AS LONG
   ' // Get an handle to the device context of the control
   DIM hDC AS HDC = GetDC(hListBox)
   ' // Get the number of items
   DIM i AS LONG, cxScrollWidth AS LONG
   DIM cItems AS LRESULT = SendMessageW(hListBox, LB_GETCOUNT, 0, 0)
   FOR i = 0 TO cItems - 1
      ' // Get the text of the item
      DIM cbLen AS LONG = SendMessageW(hListBox, LB_GETTEXTLEN, i, 0)
      IF cbLen = 0 THEN CONTINUE FOR
      DIM pbuffer AS WSTRING PTR = CAllocate(cbLen * 2)
      SendMessageW(hListBox, LB_GETTEXT, i, CAST(LPARAM, pbuffer))
      ' // Computes the width and height of the text
      DIM tsize AS SIZE
      GetTextExtentPoint32W hDC, pbuffer, cbLen, @tsize
      cxScrollWidth = MAX(cxScrollWidth, tsize.cx)
      Deallocate pbuffer
   NEXT
   ' // Release the device context
   ReleaseDC hListBox, hDC
   ' // Return the width of the text
   FUNCTION = cxScrollWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds item data to the list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.AddItemData (BYVAL hListBox AS HWND, BYVAL pData AS ANY PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_ADDSTRING, 0, CAST(LPARAM, pData))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Inserts item data to a list box.
' ========================================================================================
PRIVATE FUNCTION CListBox.InsertItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pData AS ANY PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_INSERTSTRING, index, CAST(LPARAM, pData))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Finds the first item in a list box that has the specified item data.
' ========================================================================================
PRIVATE FUNCTION CListBox.FindItemData (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS ANY PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_FINDSTRING, indexStart, CAST(LPARAM, pData))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Searches a list box for an item that has the specified item data. If a matching item is found, the item is selected.
' ========================================================================================
PRIVATE FUNCTION CListBox.SelectItemData (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS ANY PTR) AS LONG
   RETURN SendMessageW(hListBox, LB_SELECTSTRING, indexStart, CAST(LPARAM, pData))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Set the control dark mode.
' Only affects the scroll bars.
' ========================================================================================
PRIVATE FUNCTION CListBox.SetDarkMode (BYVAL hListBox AS HWND) AS HRESULT
   RETURN SetWindowTheme(hListBox, "DarkMode_Explorer", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Removes the control dark mode.
' Only affects the scroll bars.
' ========================================================================================
PRIVATE FUNCTION CListBox.RemoveDarkMode (BYVAL hListBox AS HWND) AS HRESULT
   RETURN SetWindowTheme(hListBox, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
