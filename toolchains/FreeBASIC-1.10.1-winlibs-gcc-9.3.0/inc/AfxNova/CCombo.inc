' ########################################################################################
' Platform: Microsoft Windows
' Filename: CCombo.inc
' Purpose:  Windows common controls
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

' ========================================================================================
' CCombo class
' ========================================================================================
TYPE CCombo

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION Enable (BYVAL hCombo AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Disable (BYVAL hCombo AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION AddString (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION DeleteString (BYVAL hCombo AS HWND, BYVAL Index AS LONG) AS LONG
   DECLARE STATIC FUNCTION Dir (BYVAL hCombo AS HWND, BYVAL attr AS UINT, BYVAL pwszFileSpec AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION FindString (BYVAL hCombo AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION FindStringExact (BYVAL hCombo AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION GetComboBoxInfo (BYVAL hCombo AS HWND, BYVAL pcbi AS COMBOBOXINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetComboBoxInfo (BYVAL hCombo AS HWND, BYREF cbi AS COMBOBOXINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetComboBoxInfo (BYVAL hCombo AS HWND) AS COMBOBOXINFO
   DECLARE STATIC FUNCTION GetEditBoxHandle (BYVAL hCombo AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetListBoxHandle (BYVAL hCombo AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetCount (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetCueBannerText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCueBannerText (BYVAL hCombo AS HWND, BYVAL cchText AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetCurSel (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetState (BYVAL hCombo AS HWND, BYVAL item AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSelCount (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC SUB GetDroppedControlRect (BYVAL hCombo AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB GetDroppedControlRect (BYVAL hCombo AS HWND, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION GetDroppedControlRect (BYVAL hCombo AS HWND) AS RECT
   DECLARE STATIC FUNCTION GetDroppedState (BYVAL hCombo AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetDroppedWidth (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC SUB GetEditSel (BYVAL hCombo AS HWND, BYREF dwStart AS DWORD, BYREF dwEnd AS DWORD)
   DECLARE STATIC SUB GetEditSel (BYVAL hCombo AS HWND, BYVAL pdwStart AS DWORD PTR, BYVAL pdwEnd AS DWORD PTR)
   DECLARE STATIC FUNCTION GetExtendedUI (BYVAL hCombo AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetHorizontalExtent (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG_PTR
   DECLARE STATIC FUNCTION GetItemHeight (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetLbTextLen (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetLbText (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION GetLocale (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetMinVisible (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetTopIndex (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION InsertString (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC SUB LimitText (BYVAL hCombo AS HWND, BYVAL chLimit AS LONG)
   DECLARE STATIC SUB ResetContent (BYVAL hCombo AS HWND)
   DECLARE STATIC FUNCTION SelectString (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION SelectString (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetCueBannerText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION SetCurSel (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION UnselectString (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION SetDroppedWidth (BYVAL hCombo AS HWND, BYVAL nWidth AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetEditSel (BYVAL hCombo AS HWND, BYVAL nStart AS SHORT, BYVAL nEnd AS SHORT) AS LONG
   DECLARE STATIC FUNCTION SetExtendedUI (BYVAL hCombo AS HWND, BYVAL flag AS BOOLEAN) AS LONG
   DECLARE STATIC SUB SetHorizontalExtent (BYVAL hCombo AS HWND, BYVAL nWidth AS LONG)
   DECLARE STATIC FUNCTION SetItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL nData AS LPARAM) AS LONG
   DECLARE STATIC FUNCTION SetItemHeight (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL nHeight AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetLocale (BYVAL hCombo AS HWND, BYVAL lcid AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetMinVisible (BYVAL hCombo AS HWND, BYVAL iMinVisible AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetTopIndex (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC SUB ShowDropDown (BYVAL hCombo AS HWND)
   DECLARE STATIC SUB HideDropDown (BYVAL hCombo AS HWND)
   DECLARE STATIC FUNCTION CalcHorizontalExtent (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION AddItemData (BYVAL hCombo AS HWND, BYVAL pData AS LRESULT) AS LONG
   DECLARE STATIC FUNCTION InsertItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pData AS LRESULT) AS LONG
   DECLARE STATIC FUNCTION FindItemData (BYVAL hCombo AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS LRESULT) AS LONG
   DECLARE STATIC FUNCTION SelectItemData (BYVAL hCombo AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS LRESULT) AS LONG
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hCombo AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION GetText (BYVAL hCombo AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetText (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION SetText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetText (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION ReplaceText (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION SetDarkMode (BYVAL hCombo AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode (BYVAL hCombo AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CCombo
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CCombo
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Enables a combobox
' ========================================================================================
PRIVATE FUNCTION CCombo.Enable (BYVAL hCombo AS HWND) AS BOOLEAN
   RETURN EnableWindow(hCombo, CTRUE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Disables a combobox
' ========================================================================================
PRIVATE FUNCTION CCombo.Disable (BYVAL hCombo AS HWND) AS BOOLEAN
   DIM res AS LONG = EnableWindow(hCombo, FALSE)
   DIM bEnable AS BOOLEAN
   IF res = 0 THEN bEnable = TRUE ELSE bEnable = FALSE
   RETURN bEnable
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds a string to the list box of a combo box. If the combo box does not have the
' CBS_SORT style, the string is added to the end of the list.
' ========================================================================================
PRIVATE FUNCTION CCombo.AddString (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_ADDSTRING, 0, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes a string in the list box of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.DeleteString (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_DELETESTRING, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds names to the list displayed by the combo box. The message adds the names of
' directories and files that match a specified string and set of file attributes.
' CB_DIR can also add mapped drive letters to the list.
' ========================================================================================
PRIVATE FUNCTION CCombo.Dir (BYVAL hCombo AS HWND, BYVAL attr AS UINT, BYVAL pwszFileSpec AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_DIR, attr, CAST(LPARAM, pwszFileSpec))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Searches the list box of a combo box for an item beginning with the characters in a
' specified string.
' ========================================================================================
PRIVATE FUNCTION CCombo.FindString (BYVAL hCombo AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_FINDSTRING, start, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Finds the first list box string in a combo box that matches the string specified in the
' start parameter.
' ========================================================================================
PRIVATE FUNCTION CCombo.FindStringExact (BYVAL hCombo AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_FINDSTRINGEXACT, start, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves information about the specified combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetComboBoxInfo (BYVAL hCombo AS HWND, BYVAL pcbi AS COMBOBOXINFO PTR) AS BOOLEAN
   IF pcbi = NULL THEN RETURN FALSE
   pcbi->cbSize = SIZEOF(COMBOBOXINFO)
   RETURN SendMessageW(hCombo, CB_GETCOMBOBOXINFO, 0, CAST(LPARAM, pcbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.GetComboBoxInfo (BYVAL hCombo AS HWND, BYREF cbi AS COMBOBOXINFO) AS BOOLEAN
   IF VARPTR(cbi) = 0 THEN RETURN FALSE
   cbi.cbSize = SIZEOF(COMBOBOXINFO)
   RETURN SendMessageW(hCombo, CB_GETCOMBOBOXINFO, 0, CAST(LPARAM, @cbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.GetComboBoxInfo (BYVAL hCombo AS HWND) AS COMBOBOXINFO
   DIM cbi AS COMBOBOXINFO
   cbi.cbSize = SIZEOF(COMBOBOXINFO)
   SendMessageW(hCombo, CB_GETCOMBOBOXINFO, 0, CAST(LPARAM, @cbi))
   RETURN cbi
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the handle to the edit box of the combobox
' ========================================================================================
PRIVATE FUNCTION CCombo.GetEditBoxHandle (BYVAL hCombo AS HWND) AS HWND
   DIM cbi AS COMBOBOXINFO
   cbi.cbSize = SIZEOF(COMBOBOXINFO)
   SendMessageW(hCombo, CB_GETCOMBOBOXINFO, 0, CAST(LPARAM, @cbi))
   RETURN cbi.hwndItem
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the handle to the drop-down list of the combobox
' ========================================================================================
PRIVATE FUNCTION CCombo.GetListBoxHandle (BYVAL hCombo AS HWND) AS HWND
   DIM cbi AS COMBOBOXINFO
   cbi.cbSize = SIZEOF(COMBOBOXINFO)
   SendMessageW(hCombo, CB_GETCOMBOBOXINFO, 0, CAST(LPARAM, @cbi))
   RETURN cbi.hwndList
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of items in the list box of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetCount (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the cue banner text displayed in the edit control of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetCueBannerText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hCombo, CB_GETCUEBANNER, CAST(LPARAM, pwszText), cchText)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.GetCueBannerText (BYVAL hCombo AS HWND, BYVAL cchText AS DWORD) AS DWSTRING
   DIM dwsText AS DWSTRING = WSPACE(cchText + 1)
   SendMessageW(hCombo, CB_GETCUEBANNER, cast(WPARAM, *dwsText), LEN(dwsText))
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the index of the currently selected item, if any, in the list box of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetCurSel (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETCURSEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the specified item is selected; FALSE, otherwise.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetState (BYVAL hCombo AS HWND, BYVAL item AS LONG) AS BOOLEAN
   DIM selItem AS LONG = SendMessageW(hCombo, CB_GETCURSEL, 0, 0)
   IF selItem = item THEN RETURN TRUE ELSE RETURN FALSE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the number of selected items, if any, in the list box of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetSelCount (BYVAL hCombo AS HWND) AS LONG
   DIM item AS LONG = SendMessageW(hCombo, CB_GETCURSEL, 0, 0)
   IF item <> CB_ERR THEN RETURN 1 ELSE RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the screen coordinates of a combo box in its dropped-down state
' ========================================================================================
PRIVATE SUB CCombo.GetDroppedControlRect (BYVAL hCombo AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW(hCombo, CB_GETDROPPEDCONTROLRECT,  0, CAST(LPARAM, prc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CCombo.GetDroppedControlRect (BYVAL hCombo AS HWND, BYREF rc AS RECT)
   SendMessageW(hCombo, CB_GETDROPPEDCONTROLRECT,  0, CAST(LPARAM, @rc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.GetDroppedControlRect (BYVAL hCombo AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hCombo, CB_GETDROPPEDCONTROLRECT,  0, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the list box of a combo box is dropped down.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetDroppedState (BYVAL hCombo AS HWND) AS BOOLEAN
   RETURN SendMessageW(hCombo, CB_GETDROPPEDSTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the minimum allowable width, in pixels, of the list box of a combo box with
' the CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetDroppedWidth (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETDROPPEDWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the starting and ending character positions of the current selection in the edit
' control of a combo box.
' ========================================================================================
PRIVATE SUB CCombo.GetEditSel (BYVAL hCombo AS HWND, BYREF dwStart AS DWORD, BYREF dwEnd AS DWORD)
   SendMessageW hCombo, CB_GETEDITSEL, CAST(WPARAM, @dwStart), CAST(LPARAM, @dwEnd)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CCombo.GetEditSel (BYVAL hCombo AS HWND, BYVAL pdwStart AS DWORD PTR, BYVAL pdwEnd AS DWORD PTR)
   SendMessageW hCombo, CB_GETEDITSEL, CAST(WPARAM, pdwStart), CAST(LPARAM, pdwEnd)
END SUB
' ========================================================================================

' ========================================================================================
' * Determines whether a combo box has the default user interface or the extended user interface.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetExtendedUI (BYVAL hCombo AS HWND) AS BOOLEAN
   RETURN SendMessageW(hCombo, CB_GETEXTENDEDUI, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves from a combo box the width, in pixels, by which the list box can be scrolled
' horizontally (the scrollable width). This is applicable only if the list box has a
' horizontal scroll bar.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetHorizontalExtent (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETHORIZONTALEXTENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the application-supplied value associated with the specified item in the combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG_PTR
   IF index < 0 THEN index = SendMessageW(hCombo, CB_GETCURSEL, 0, 0)
   RETURN SendMessageW(hCombo, CB_GETITEMDATA, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the height of list items in a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetItemHeight (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETITEMHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieve the length, in characters, of a string in the list of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetLbTextLen (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_GETLBTEXTLEN, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets a string from the list of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetLbText (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
   DIM dwsText AS DWSTRING
   DIM nLen AS LONG
   IF index < 0 THEN index = SendMessageW(hCombo, CB_GETCURSEL, 0, 0)
   nLen = SendMessageW(hCombo, CB_GETLBTEXTLEN, index, 0)
   dwsText = WSPACE(nLen + 1)
   SendMessageW hCombo, CB_GETLBTEXT, index, CAST(LPARAM, *dwsText)
   RETURN LEFT(dwsText, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the current locale of the combo box. The locale is used to determine the
' correct sorting order of displayed text for combo boxes with the CBS_SORT style and text
' added by using the CB_ADDSTRING message.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetLocale (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETLOCALE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the minimum number of visible items in the drop-down list of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetMinVisible (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETMINVISIBLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the zero-based index of the first visible item in the list box portion of a
' combo box. Initially, the item with index 0 is at the top of the list box, but if the
' list box contents have been scrolled, another item may be at the top.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetTopIndex (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_GETTOPINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Inserts a string into the list box of a combo box. Unlike the CB_ADDSTRING message, the
' CB_INSERTSTRING message does not cause a list with the CBS_SORT style to be sorted.
' ========================================================================================
PRIVATE FUNCTION CCombo.InsertString (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_INSERTSTRING, index, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Limits the length of the text the user may type into the edit control of a combo box.
' ========================================================================================
PRIVATE SUB CCombo.LimitText (BYVAL hCombo AS HWND, BYVAL chLimit AS LONG)
   SendMessageW hCombo, CB_LIMITTEXT, chLimit, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Removes all items from the list box and edit control of a combo box.
' ========================================================================================
PRIVATE SUB CCombo.ResetContent (BYVAL hCombo AS HWND)
   SendMessageW hCombo, CB_RESETCONTENT, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Searches the list of a combo box for an item that begins with the characters in a
' specified string. If a matching item is found, it is selected and copied to the edit control.
' ========================================================================================
PRIVATE FUNCTION CCombo.SelectString (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_SELECTSTRING, index, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the cue banner text displayed in the edit control of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetCueBannerText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_SETCUEBANNER, 0, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects a string in the list of a combo box. If necessary, the list scrolls the string
' into view. The text in the edit control of the combo box changes to reflect the new
' selection, and any previous selection in the list is removed.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetCurSel (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_SETCURSEL, index, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.UnselectString (BYVAL hCombo AS HWND) AS LONG
   RETURN SendMessageW(hCombo, CB_SETCURSEL, -1, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum allowable width, in pixels, of the list box of a combo box with the
' CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetDroppedWidth (BYVAL hCombo AS HWND, BYVAL nWidth AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_SETDROPPEDWIDTH, nWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects characters in the edit control of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetEditSel (BYVAL hCombo AS HWND, BYVAL nStart AS SHORT, BYVAL nEnd AS SHORT) AS LONG
   RETURN SendMessageW(hCombo, CB_SETEDITSEL, 0, MAKELONG(nStart, nEnd))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects either the default user interface or the extended user interface for a combo box
' that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetExtendedUI (BYVAL hCombo AS HWND, BYVAL flag AS BOOLEAN) AS LONG
   RETURN SendMessageW(hCombo, CB_SETEXTENDEDUI, IIF(flag = TRUE, CTRUE, FALSE), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width, in pixels, by which a list box can be scrolled horizontally (the
' scrollable width). If the width of the list box is smaller than this value, the
' horizontal scroll bar horizontally scrolls items in the list box. If the width of the
' list box is equal to or greater than this value, the horizontal scroll bar is hidden or,
' if the combo box has the CBS_DISABLENOSCROLL style, disabled.
' ========================================================================================
PRIVATE SUB CCombo.SetHorizontalExtent (BYVAL hCombo AS HWND, BYVAL nWidth AS LONG)
   SendMessageW hCombo, CB_SETHORIZONTALEXTENT, nWidth, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the value associated with the specified item in a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL nData AS LONG_PTR) AS LONG
   RETURN SendMessageW(hCombo, CB_SETITEMDATA, index, nData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the height of list items or the selection field in a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetItemHeight (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL nHeight AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_SETITEMHEIGHT, index, nHeight)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the current locale of the combo box. If the combo box has the CBS_SORT style and
' strings are added using CB_ADDSTRING, the locale of a combo box affects how list items
' are sorted.  The return value is the previous locale identifier. If lcid specifies a
' locale not installed on the system, the return value is CB_ERR and the current combo box
' locale is not changed.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetLocale (BYVAL hCombo AS HWND, BYVAL lcid AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_SETLOCALE, cast(WPARAM, lcid), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum number of visible items in the drop-down list of a combo box.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetMinVisible (BYVAL hCombo AS HWND, BYVAL iMinVisible AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_SETMINVISIBLE, iMinVisible, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Ensures that a particular item is visible in the list box of a combo box. The system
' scrolls the list box contents so that either the specified it. If the message is successful,
' the return value is zero. If the message fails, the return value is CB_ERR.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetTopIndex (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hCombo, CB_SETTOPINDEX, cast(WPARAM, index), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows or hides the list box of a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
PRIVATE SUB CCombo.ShowDropDown (BYVAL hCombo AS HWND)
   SendMessageW hCombo, CB_SHOWDROPDOWN, CTRUE, 0
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CCombo.HideDropDown (BYVAL hCombo AS HWND)
   SendMessageW hCombo, CB_SHOWDROPDOWN, FALSE, 0
END SUB
' ========================================================================================

' ========================================================================================
' Calculates the size, in logical units, of the widest string item.
' ========================================================================================
PRIVATE FUNCTION CCombo.CalcHorizontalExtent (BYVAL hCombo AS HWND) AS LONG
   ' // Get an handle to the device context of the control
   DIM hDC AS HDC = GetDC(hCombo)
   ' // Get the number of items
   DIM i AS LONG, cxScrollWidth AS LONG
   DIM cItems AS LRESULT = SendMessageW(hCombo, CB_GETCOUNT, 0, 0)
   FOR i = 0 TO cItems - 1
      ' // Get the text of the item
      DIM cbLen AS LONG = SendMessageW(hCombo, CB_GETLBTEXTLEN, i, 0)
      IF cbLen = 0 THEN CONTINUE FOR
      DIM pbuffer AS WSTRING PTR = CAllocate(cbLen * 2)
      SendMessageW(hCombo, CB_GETLBTEXT, i, CAST(LPARAM, pbuffer))
      ' // Computes the width and height of the text
      DIM tsize AS SIZE
      GetTextExtentPoint32W hDC, pbuffer, cbLen, @tsize
      cxScrollWidth = MAX(cxScrollWidth, tsize.cx)
      Deallocate pbuffer
   NEXT
   ' // Release the device context
   ReleaseDC hCombo, hDC
   ' // Return the width of the text
   RETURN cxScrollWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the length of a text item in a combobox control.
' - hCombo: A handle to the combobox.
' - index: The zero-based index of the item.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetTextLength (BYVAL hCombo AS HWND) AS LONG
   RETURN GetWindowTextLengthW(hCombo)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.GetTextLength (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
   RETURN SendMessageW(hCombo, CB_GETLBTEXTLEN, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text in a combobox control.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetText (BYVAL hCombo AS HWND) AS DWSTRING
   DIM nLen AS LONG = GetWindowTextLengthW(hCombo)
   DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
   GetWindowTextW(hCombo, dwsText, nLen +  1)
   RETURN dwsText
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Gets a string from a list in a combo box.
' - hCombo: A handle to the combobox.
' - index: The zero-based index of the item.
' ========================================================================================
PRIVATE FUNCTION CCombo.GetText (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
   DIM nLen AS LONG = SendMessageW(hCombo, CB_GETLBTEXTLEN, index, 0)
   DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
   SendMessageW(hCombo, CB_GETLBTEXT, index, cast(LPARAM, *dwsText))
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of a combobox control.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   RETURN SetWindowTextW(hCombo, pwszText)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Replaces the text of an item in a combobox control.
' - hCombo: A handle to the combobox.
' - index: The zero-based index of the item.
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CCombo.SetText (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   IF SendMessageW(hCombo, CB_DELETESTRING, index, 0) = CB_ERR THEN RETURN CB_ERR
   RETURN SendMessageW(hCombo, CB_INSERTSTRING, index, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION CCombo.ReplaceText (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   IF SendMessageW(hCombo, CB_DELETESTRING, index, 0) = CB_ERR THEN RETURN CB_ERR
   RETURN SendMessageW(hCombo, CB_INSERTSTRING, index, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the control dark mode.
' ========================================================================================
PRIVATE FUNCTION CCombo.SetDarkMode (BYVAL hCombo AS HWND) AS HRESULT
   RETURN SetWindowTheme(hCombo, "DarkMode_CFD", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Removes the control dark mode.
' ========================================================================================
PRIVATE FUNCTION CCombo.RemoveDarkMode (BYVAL hCombo AS HWND) AS HRESULT
   RETURN SetWindowTheme(hCombo, NULL, NULL)
END FUNCTION
' ========================================================================================

' ########################################################################################

' ========================================================================================
' CComboEx class
' ========================================================================================
TYPE CComboEx

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION DeleteItem (BYVAL hComboEx AS HWND, BYVAL nIndex AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetComboControl (BYVAL hComboEx AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetEditControl (BYVAL hComboEx AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetExtendedStyle (BYVAL hComboEx AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetImageList (BYVAL hComboEx AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hComboEx AS HWND) AS COMBOBOXEXITEMW
   DECLARE STATIC FUNCTION HasEditChanged (BYVAL hComboEx AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS LONG
   DECLARE STATIC FUNCTION InsertItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS LONG
   DECLARE STATIC FUNCTION SetExtendedStyle (BYVAL hComboEx AS HWND, BYVAL dwMask AS DWORD, BYVAL dwExStyle AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetImageList (BYVAL hComboEx AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS BOOLEAN
   DECLARE STATIC SUB SetWindowTheme (BYVAL hComboEx AS HWND, BYVAL pwszStyle AS WSTRING PTR)
   DECLARE STATIC FUNCTION SetDarkMode (BYVAL hCombo AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode (BYVAL hCombo AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CComboEx
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CComboEx
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Removes an item from a ComboBoxEx control. Returns an INT value that represents the number
' of items remaining in the control. If iIndex is invalid, the message returns CB_ERR.
' ========================================================================================
PRIVATE FUNCTION CComboEx.DeleteItem (BYVAL hComboEx AS HWND, BYVAL iIndex AS LONG) AS LONG
   RETURN SendMessageW(hComboEx, CBEM_DELETEITEM, iIndex, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle to the combo box control within the ComboBoxEx control.
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetComboControl (BYVAL hComboEx AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hComboEx, CBEM_GETCOMBOCONTROL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle to the edit control within the ComboBoxEx control if it uses the
' CBS_DROPDOWN style. Otherwise, the message returns NULL.
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetEditControl (BYVAL hComboEx AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hComboEx, CBEM_GETEDITCONTROL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a DWORD value that contains the ComboBoxEx control extended styles in use for the control.
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetExtendedStyle (BYVAL hComboEx AS HWND) AS DWORD
   RETURN SendMessageW(hComboEx, CBEM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to an image list assigned to a ComboBoxEx control.
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetImageList (BYVAL hComboEx AS HWND) AS HIMAGELIST
   RETURN cast(HIMAGELIST, SendMessageW(hComboEx, CBEM_GETIMAGELIST, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves item information for a given ComboBoxEx item. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hComboEx, CBEM_GETITEMW, 0, cast(LPARAM, pCBItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS BOOLEAN
   RETURN SendMessageW(hComboEx, CBEM_GETITEMW, 0, cast(LPARAM, @CBItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CComboEx.GetItem (BYVAL hComboEx AS HWND) AS COMBOBOXEXITEMW
   DIM item AS COMBOBOXEXITEMW
   SendMessageW(hComboEx, CBEM_GETITEMW, 0, cast(LPARAM, @item))
   RETURN item
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether or not the user has changed the text of a ComboBoxEx edit control.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CComboEx.HasEditChanged (BYVAL hComboEx AS HWND) AS BOOLEAN
   RETURN SendMessageW(hComboEx, CBEM_HASEDITCHANGED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the index at which the new item was inserted if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CComboEx.InsertItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS LONG
   RETURN SendMessageW(hComboEx, CBEM_INSERTITEMW, 0, cast(LPARAM, pCBItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CComboEx.InsertItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS LONG
   IF VARPTR(CBItem) = 0 THEN RETURN FALSE
   RETURN SendMessageW(hComboEx, CBEM_INSERTITEMW, 0, cast(LPARAM, @CBItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets extended styles within a ComboBoxEx control.
' ========================================================================================
PRIVATE FUNCTION CComboEx.SetExtendedStyle (BYVAL hComboEx AS HWND, BYVAL dwExMask AS DWORD, BYVAL dwExStyle AS DWORD) AS DWORD
   RETURN SendMessageW(hComboEx, CBEM_SETEXTENDEDSTYLE, cast(WPARAM, dwExMask), cast(LPARAM, dwExStyle))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle to the image list previously associated with the control, or returns
' NULL if no image list was previously set.
' ========================================================================================
PRIVATE FUNCTION CComboEx.SetImageList (BYVAL hComboEx AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   RETURN cast(HIMAGELIST, SendMessageW(hComboEx, CBEM_SETIMAGELIST, 0, cast(LPARAM, himl)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the attributes for an item in a ComboBoxEx control.
' Returns nonzero if successful, or zero otherwise.
' ========================================================================================
PRIVATE FUNCTION CComboEx.SetItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS BOOLEAN
   IF pCBItem = NULL THEN RETURN FALSE
   RETURN SendMessageW(hComboEx, CBEM_SETITEMW, 0, cast(LPARAM, pCBItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CComboEx.SetItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS BOOLEAN
   IF VARPTR(CBItem) = 0 THEN RETURN FALSE
   RETURN SendMessageW(hComboEx, CBEM_SETITEMW, 0, cast(LPARAM, @CBItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the visual style of a ComboboxEx control.
' ========================================================================================
PRIVATE SUB CComboEx.SetWindowTheme (BYVAL hComboEx AS HWND, BYVAL pwszStyle AS WSTRING PTR)
   SendMessageW(hComboEx, CBEM_SETWINDOWTHEME, 0, cast(LPARAM, pwszStyle))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the control dark mode.
' ========================================================================================
PRIVATE FUNCTION CComboEx.SetDarkMode (BYVAL hComboEx AS HWND) AS HRESULT
   RETURN ..SetWindowTheme(hComboEx, "DarkMode_CFD", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Removes the control dark mode.
' ========================================================================================
PRIVATE FUNCTION CComboEx.RemoveDarkMode (BYVAL hComboEx AS HWND) AS HRESULT
   RETURN ..SetWindowTheme(hComboEx, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
