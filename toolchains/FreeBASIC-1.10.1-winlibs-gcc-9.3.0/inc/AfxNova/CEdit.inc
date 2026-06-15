' ########################################################################################
' Platform: Microsoft Windows
' Filename: CEdit.inc
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
' CEdit class
' ========================================================================================
TYPE CEdit

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION CanUndo (BYVAL hEdit AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION CharFromPos (BYVAL hEdit AS HWND, BYVAL x AS SHORT, BYVAL y AS SHORT) AS DWORD
   DECLARE STATIC SUB Clear (BYVAL hEdit AS HWND)
   DECLARE STATIC SUB Copy (BYVAL hEdit AS HWND)
   DECLARE STATIC SUB Cut (BYVAL hEdit AS HWND)
   DECLARE STATIC SUB EmptyUndoBuffer (BYVAL hEdit AS HWND)
   DECLARE STATIC FUNCTION Enable (BYVAL hEdit AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Disable (BYVAL hEdit AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION FmtLines (BYVAL hEdit AS HWND, BYVAL AddEolFlag AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCueBannerText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCueBannerText (BYVAL hEdit AS HWND, BYVAL cchText AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetFirstVisibleLine (BYVAL hEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetHandle (BYVAL hEdit AS HWND) AS ..HLOCAL
   DECLARE STATIC FUNCTION GetIMEStatus (BYVAL hEdit AS HWND, BYVAL nStatusType AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetLimitText (BYVAL hEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetLine (BYVAL hEdit AS HWND, BYVAL which AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetLineCount (BYVAL hEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetMargins (BYVAL hEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetLeftMargin (BYVAL hEdit AS HWND) AS WORD
   DECLARE STATIC FUNCTION GetRightMargin (BYVAL hEdit AS HWND) AS WORD
   DECLARE STATIC FUNCTION GetModify (BYVAL hEdit AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetPasswordChar (BYVAL hEdit AS HWND) AS LONG
   DECLARE STATIC SUB GetRect (BYVAL hEdit AS HWND, BYREF rc AS RECT)
   DECLARE STATIC SUB GetRect (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC FUNCTION GetRect (BYVAL hEdit AS HWND) AS RECT
   DECLARE STATIC FUNCTION GetSel (BYVAL hEdit AS HWND, BYREF dwStartPos AS DWORD, BYREF dwEndPos AS DWORD) AS LONG
   DECLARE STATIC FUNCTION GetSel (BYVAL hEdit AS HWND, BYVAL pdwStartPos AS DWORD PTR, BYVAL pdwEndPos AS DWORD PTR) AS LONG
   DECLARE STATIC FUNCTION GetSel (BYVAL hEdit AS HWND) AS ..POINTL
   DECLARE STATIC FUNCTION GetSelStart (BYVAL hEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetSelEnd (BYVAL hEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetText (BYVAL hEdit AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetThumb (BYVAL hEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetWordBreakProc (BYVAL hEdit AS HWND) AS LONG_PTR
   DECLARE STATIC FUNCTION HideBalloonTip (BYVAL hEdit AS HWND) AS BOOLEAN
   DECLARE STATIC SUB LimitText (BYVAL hEdit AS HWND, BYVAL chMax AS DWORD)
   DECLARE STATIC FUNCTION LineFromChar (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION LineLength (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC FUNCTION LineScroll (BYVAL hEdit AS HWND, BYVAL x AS LONG, BYVAL y AS LONG) AS BOOLEAN
   DECLARE STATIC SUB Paste (BYVAL hEdit AS HWND)
   DECLARE STATIC FUNCTION PosFromChar (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
   DECLARE STATIC SUB ReplaceSel (BYVAL hEdit AS HWND, BYVAL bCanBeUndone AS BOOLEAN, BYVAL pwszText AS WSTRING PTR)
   DECLARE STATIC FUNCTION Scroll (BYVAL hEdit AS HWND, BYVAL nAction AS LONG) AS DWORD
   DECLARE STATIC SUB ScrollCaret (BYVAL hEdit AS HWND)
   DECLARE STATIC FUNCTION SetCueBannerText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL bDrawFocused AS BOOLEAN = FALSE) AS LONG
   DECLARE STATIC SUB SetHandle (BYVAL hEdit AS HWND, BYVAL hLocal AS ..HLOCAL)
   DECLARE STATIC FUNCTION SetIMEStatus (BYVAL hEdit AS HWND, BYVAL nStatusType AS LONG, BYVAL flags AS DWORD) AS DWORD
   DECLARE STATIC SUB SetLimitText (BYVAL hEdit AS HWND, BYVAL chMax AS DWORD)
   DECLARE STATIC SUB SetMargins (BYVAL hEdit AS HWND, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
   DECLARE STATIC SUB SetLeftMargin (BYVAL hEdit AS HWND, BYVAL nWidth AS WORD)
   DECLARE STATIC SUB SetRightMargin (BYVAL hEdit AS HWND, BYVAL nWidth AS WORD)
   DECLARE STATIC SUB SetModify (BYVAL hEdit AS HWND, BYVAL fModify AS BOOLEAN)
   DECLARE STATIC SUB SetPasswordChar (BYVAL hEdit AS HWND, BYVAL dwchar AS DWORD)
   DECLARE STATIC FUNCTION SetReadOnly (BYVAL hEdit AS HWND, BYVAL fReadOnly AS BOOLEAN) AS LONG
   DECLARE STATIC SUB SetRect (BYVAL hEdit AS HWND, BYREF rc AS RECT)
   DECLARE STATIC SUB SetRect (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB SetRectNoPaint (BYVAL hEdit AS HWND, BYREF rc AS RECT)
   DECLARE STATIC SUB SetRectNoPaint (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB SetSel (BYVAL hEdit AS HWND, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
   DECLARE STATIC FUNCTION SetTabStops (BYVAL hEdit AS HWND, BYVAL cTabs AS LONG, BYVAL prgTabStops AS LONG PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC SUB SetWordBreakProc (BYVAL hEdit AS HWND, BYVAL pfn AS LONG_PTR)
   DECLARE STATIC FUNCTION ShowBalloonTip (BYVAL hEdit AS HWND, BYVAL peditballoontip AS EDITBALLOONTIP PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION ShowBalloonTip (BYVAL hEdit AS HWND, BYVAL pwszTitle AS WSTRING PTR, BYVAL pwszText AS WSTRING PTR, BYVAL iIcon AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION Undo (BYVAL hEdit AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION SetDarkMode (BYVAL hEdit AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode (BYVAL hEdit AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CEdit
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CEdit
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Determines whether there are any actions in an edit control's undo queue. You can send
' this message to either an edit control or a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.CanUndo (BYVAL hEdit AS HWND) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_CANUNDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets information about the character closest to a specified point in the client area of
' an edit control. You can send this message to either an edit control or a rich edit control.
' Return value: The LOWORD specifies the zero-based index of the character nearest the
' specified point. This index is relative to the beginning of the control, not the beginning
' of the line. If the specified point is beyond the last character in the edit control, the
' return value indicates the last character in the control. The HIWORD specifies the
' zero-based index of the line that contains the character. For single-line edit controls,
' this value is zero. The index indicates the line delimiter if the specified point is
' beyond the last visible character in a line.
' ========================================================================================
PRIVATE FUNCTION CEdit.CharFromPos (BYVAL hEdit AS HWND, BYVAL x AS SHORT, BYVAL y AS SHORT) AS DWORD
   RETURN SendMessageW(hEdit, EM_CHARFROMPOS, 0, cast(LPARAM, MAKELONG(x, y)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes (clears) the current selection, if any, from the edit control.
' ========================================================================================
PRIVATE SUB CEdit.Clear (BYVAL hEdit AS HWND)
   SendMessageW(hEdit, WM_CLEAR, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Copies the current selection to the clipboard in CF_TEXT format.
' ========================================================================================
PRIVATE SUB CEdit.Copy (BYVAL hEdit AS HWND)
   SendMessageW(hEdit, WM_COPY, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Deletes (cuts) the current selection, if any, in the edit control and copy the deleted
' text to the clipboard in CF_TEXT format.
' ========================================================================================
PRIVATE SUB CEdit.Cut (BYVAL hEdit AS HWND)
   SendMessageW(hEdit, WM_CUT, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Resets the undo flag of an edit control. The undo flag is set whenever an operation
' within the edit control can be undone.
' ========================================================================================
PRIVATE SUB CEdit.EmptyUndoBuffer (BYVAL hEdit AS HWND)
   SendMessageW hEdit, EM_EMPTYUNDOBUFFER, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Enables the control.
' Return value: False if the control was previous enabled; otherwise TRUE
' ========================================================================================
PRIVATE FUNCTION CEdit.Enable (BYVAL hEdit AS HWND) AS BOOLEAN
   RETURN EnableWindow(hEdit, CTRUE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Disables the control.
' Return value: False if the control was previous disabled; otherwise TRUE
' ========================================================================================
PRIVATE FUNCTION CEdit.Disable (BYVAL hEdit AS HWND) AS BOOLEAN
   DIM res AS LONG = EnableWindow(hEdit, FALSE)
   DIM bEnable AS BOOLEAN
   IF res = 0 THEN bEnable = TRUE ELSE bEnable = FALSE
   RETURN bEnable
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a flag that determines whether a multiline edit control includes soft line-break
' characters. A soft line break consists of two carriage returns and a line feed and is
' inserted at the end of a line that is broken because of wordwrapping.
' ========================================================================================
PRIVATE FUNCTION CEdit.FmtLines (BYVAL hEdit AS HWND, BYVAL AddEolFlag AS BOOLEAN) AS BOOLEAN
   SendMessageW(hEdit, EM_FMTLINES, CAST(WPARAM, AddEolFlag), 0)
   RETURN AddEolFlag
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text that is displayed as the textual cue, or tip, in an edit control.
' To use this method, you must provide a manifest specifying Comctl32.dll version 6.0.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetCueBannerText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_GETCUEBANNER, cast(WPARAM, pwszText), cchText)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CEdit.GetCueBannerText (BYVAL hEdit AS HWND, BYVAL cchText AS DWORD) AS DWSTRING
   DIM dwsText AS DWSTRING = WSPACE(cchText + 1)
   SendMessageW(hEdit, EM_GETCUEBANNER, cast(WPARAM, *dwsText), LEN(dwsText))
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the zero-based index of the uppermost visible line in a multiline edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetFirstVisibleLine (BYVAL hEdit AS HWND) AS LONG
   RETURN SendMessageW(hEdit, EM_GETFIRSTVISIBLELINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a handle of the memory currently allocated for a multiline edit control's text.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetHandle (BYVAL hEdit AS HWND) AS ..HLOCAL
   RETURN CAST(..HLOCAL, SendMessageW(hEdit, EM_GETHANDLE, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'PRIVATE FUNCTION CEdit.GetHilite (BYVAL hEdit AS HWND) AS LONG
'   RETURN SendMessageW(hEdit, EM_GETHILITE, 0, 0)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a set of status flags that indicate how the edit control interacts with the
' Input Method Editor (IME).
' ========================================================================================
PRIVATE FUNCTION CEdit.GetIMEStatus (BYVAL hEdit AS HWND, BYVAL nStatusType AS LONG) AS LONG
   RETURN SendMessageW(hEdit, EM_GETIMESTATUS, cast(WPARAM, nStatusType), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the current text limit for an edit control. The return value is the text limit.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetLimitText (BYVAL hEdit AS HWND) AS DWORD
   RETURN SendMessageW(hEdit, EM_GETLIMITTEXT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Copies a line of text from an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetLine (BYVAL hEdit AS HWND, BYVAL which AS DWORD) AS DWSTRING
   DIM buffer AS DWSTRING
   buffer = MKI(32765) + WSTRING(32765, 0)
   DIM nLen AS LONG = SendMessageW(hEdit, EM_GETLINE, which, CAST(LPARAM, STRPTR(buffer)))
   RETURN LEFT(buffer, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the number of lines in a multiline edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetLineCount (BYVAL hEdit AS HWND) AS LONG
   RETURN SendMessageW(hEdit, EM_GETLINECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width of the left margin in the LOWORD, and the width of the right margin in the HIWORD.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetMargins (BYVAL hEdit AS HWND) AS DWORD
   RETURN SendMessageW(hEdit, EM_GETMARGINS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width of the left margin for an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetLeftMargin (BYVAL hEdit AS HWND) AS WORD
   RETURN LOWORD(SendMessageW(hEdit, EM_GETMARGINS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the right margin for an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetRightMargin (BYVAL hEdit AS HWND) AS WORD
   RETURN HIWORD(SendMessageW(hEdit, EM_GETMARGINS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the state of an edit control's modification flag. The flag indicates whether the
' contents of the edit control have been modified.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetModify (BYVAL hEdit AS HWND) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_GETMODIFY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the password character that an edit control displays when the user enters text.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetPasswordChar (BYVAL hEdit AS HWND) AS LONG
   RETURN SendMessageW(hEdit, EM_GETPASSWORDCHAR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the formatting rectangle of an edit control. The formatting rectangle is the
' limiting rectangle into which the control draws the text. The limiting rectangle is
' independent of the size of the edit-control window.
' ========================================================================================
PRIVATE SUB CEdit.GetRect (BYVAL hEdit AS HWND, BYREF rc AS RECT)
   SendMessageW hEdit, EM_GETRECT, 0, CAST(LPARAM, @rc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CEdit.GetRect (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW hEdit, EM_GETRECT, 0, CAST(LPARAM, prc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CEdit.GetRect (BYVAL hEdit AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW hEdit, EM_GETRECT, 0, CAST(LPARAM, @rc)
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the starting and ending character positions of the current selection in an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetSel (BYVAL hEdit AS HWND, BYREF dwStartPos AS DWORD, BYREF dwEndPos AS DWORD) AS LONG
   RETURN SendMessageW(hEdit, EM_GETSEL, CAST(WPARAM, @dwStartPos), cast(LPARAM, @dwEndPos))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CEdit.GetSel (BYVAL hEdit AS HWND, BYVAL pdwStartPos AS DWORD PTR, BYVAL pdwEndPos AS DWORD PTR) AS LONG
   RETURN SendMessageW(hEdit, EM_GETSEL, CAST(WPARAM, pdwStartPos), cast(LPARAM, pdwEndPos))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CEdit.GetSel (BYVAL hEdit AS HWND) AS ..POINTL
   DIM dwStartPos AS DWORD, dwEndPos AS DWORD, pt AS .POINTL
   SendMessageW(hEdit, EM_GETSEL, CAST(WPARAM, @dwStartPos), cast(LPARAM, @dwEndPos))
   pt.x = dwStartPos : pt.y = dwEndPos
   RETURN pt
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Gets the starting character position of the current selection in an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetSelStart (BYVAL hEdit AS HWND) AS DWORD
   DIM dwStartPos AS DWORD, dwEndPos AS DWORD
   SendMessageW(hEdit, EM_GETSEL, CAST(WPARAM, @dwStartPos), cast(LPARAM, @dwEndPos))
   RETURN dwStartPos
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Gets the ending character position of the current selection in an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetSelEnd (BYVAL hEdit AS HWND) AS DWORD
   DIM dwStartPos AS DWORD, dwEndPos AS DWORD
   SendMessageW(hEdit, EM_GETSEL, CAST(WPARAM, @dwStartPos), cast(LPARAM, @dwEndPos))
   RETURN dwEndPos
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text length from an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetTextLength (BYVAL hEdit AS HWND) AS LONG
   RETURN GetWindowTextLengthW(hEdit)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text in a button control.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetText (BYVAL hEdit AS HWND) AS DWSTRING
   DIM nLen AS LONG = GetWindowTextLengthW(hEdit)
   DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
   GetWindowTextW(hEdit, dwsText, nLen +  1)
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the position of the scroll box (thumb) in the vertical scroll bar of a multiline
' edit control. Note: With multiline edit controls always returns 0, so we are using
' GetScrollPos as an alternative.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetThumb (BYVAL hEdit AS HWND) AS LONG
'   RETURN SendMessageW(hEdit, EM_GETTHUMB, 0, 0)
   RETURN GetScrollPos(hEdit, SB_VERT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the address of the currently registered word-break procedure.
' ========================================================================================
PRIVATE FUNCTION CEdit.GetWordBreakProc (BYVAL hEdit AS HWND) AS LONG_PTR
   RETURN SendMessageW(hEdit, EM_GETWORDBREAKPROC, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Hides any balloon tip associated with an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.HideBalloonTip (BYVAL hEdit AS HWND) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_HIDEBALLOONTIP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text limit of an edit control. The text limit is the maximum amount of text, in
' bytes, that the user can type into the edit control.
' ========================================================================================
PRIVATE SUB CEdit.LimitText (BYVAL hEdit AS HWND, BYVAL chMax AS DWORD)
   SendMessageW hEdit, EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gets the index of the line that contains the specified character index in a multiline
' edit control. A character index is the zero-based index of the character from the
' beginning of the edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.LineFromChar (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hEdit, EM_LINEFROMCHAR, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the length, in characters, of a line in an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.LineLength (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hEdit, EM_LINELENGTH, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Scrolls the text in a multiline edit control.
' If the message is sent to a multiline edit control, the return value is TRUE.
' If the message is sent to a single-line edit control, the return value is FALSE.
' ========================================================================================
PRIVATE FUNCTION CEdit.LineScroll (BYVAL hEdit AS HWND, BYVAL x AS LONG, BYVAL y AS LONG) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_LINESCROLL, cast(WPARAM, x), cast(LPARAM, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Copies the current content of the clipboard to the edit control at the current caret
' position. Data is inserted only if the clipboard contains data in CF_TEXT format.
' ========================================================================================
PRIVATE SUB CEdit.Paste (BYVAL hEdit AS HWND)
   SendMessageW(hEdit, WM_PASTE, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the client area coordinates of a specified character in an edit control.
' The return value contains the client area coordinates of the character. The LOWORD
' contains the horizontal coordinate and the HIWORD contains the vertical coordinate.
' ========================================================================================
PRIVATE FUNCTION CEdit.PosFromChar (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
   RETURN SendMessageW(hEdit, EM_POSFROMCHAR, cast(WPARAM, index), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Replaces the current selection in an edit control with the specified text.
' ========================================================================================
PRIVATE SUB CEdit.ReplaceSel (BYVAL hEdit AS HWND, BYVAL bCanBeUndone AS BOOLEAN, BYVAL pwszText AS WSTRING PTR)
   SendMessageW hEdit, EM_REPLACESEL, CAST(WPARAM, bCanBeUndone), CAST(LPARAM, pwszText)
END SUB
' ========================================================================================

' ========================================================================================
' * Scrolls the text vertically in a multiline edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.Scroll (BYVAL hEdit AS HWND, BYVAL nAction AS LONG) AS DWORD
   RETURN SendMessageW(hEdit, EM_SCROLL, nAction, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the caret into view in an edit control.
' ========================================================================================
PRIVATE SUB CEdit.ScrollCaret (BYVAL hEdit AS HWND)
   SendMessageW hEdit, EM_SCROLLCARET, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the text that is displayed as the textual cue, or tip, for an edit control.
' - pwszText: A pointer to a Unicode string that contains the text to display as the textual cue.
' - bDrawFocused: TRUE if the cue banner should show even when the edit control has focus;
'   otherwise, FALSE. FALSE is the default behavior—the cue banner disappears when the user
'   clicks in the control.
' If the message succeeds, it returns TRUE. Otherwise it returns FALSE.
' ========================================================================================
PRIVATE FUNCTION CEdit.SetCueBannerText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL fDrawFocused AS BOOLEAN = FALSE) AS LONG
   RETURN SendMessageW(hEdit, EM_SETCUEBANNER, fDrawFocused, cast(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the handle of the memory that will be used by a multiline edit control.
' ========================================================================================
PRIVATE SUB CEdit.SetHandle (BYVAL hEdit AS HWND, BYVAL hLocal AS ..HLOCAL)
   SendMessageW hEdit, EM_SETHANDLE, cast(WPARAM, hLocal), 0
END SUB
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'PRIVATE FUNCTION CEdit.SetHilite (BYVAL hEdit AS HWND, BYVAL ichStart AS LONG, BYVAL ichEnd AS LONG) AS LONG
'   RETURN SendMessageW(hEdit, EM_SETHILITE, ichStart, ichEnd)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the status flags that determine how an edit control interacts with the Input Method
' Editor (IME).
' - nStatusType: The type of status to set. This parameter can be EMSIS_COMPOSITIONSTRING.
' - flags: Data specific to the status type. If wParam is EMSIS_COMPOSITIONSTRING, this
'   parameter can be one or more of the following values: EIMES_GETCOMPSTRATONCE,
'   EIMES_CANCELCOMPSTRINFOCUS, EIMES_COMPLETECOMPSTRKILLFOCUS.
' Returns the previous value of the flags parameter.
' ========================================================================================
PRIVATE FUNCTION CEdit.SetIMEStatus (BYVAL hEdit AS HWND, BYVAL nStatusType AS LONG, BYVAL flags AS DWORD) AS DWORD
   RETURN SendMessageW(hEdit, EM_SETIMESTATUS, cast(WPARAM, nStatusType), cast(LPARAM, flags))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text limit of an edit control. The text limit is the maximum amount of text, in
' TCHARs, that the user can type into the edit control.
' ========================================================================================
PRIVATE SUB CEdit.SetLimitText (BYVAL hEdit AS HWND, BYVAL chMax AS DWORD)
   SendMessageW hEdit, EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the widths of the left and right margins for an edit control. The message redraws
' the control to reflect the new margins.
' - nMargins: One or more of the following values:
'   EC_LEFTMARGIN: Sets the left margin.
'   EC_RIGHTMARGIN: Sets the right margin.
' - nWidth: The low-order word specifies the new width of the left margin, in pixels.
'   The high-order word specifies the new width of the right margin, in pixels.
' ========================================================================================
PRIVATE SUB CEdit.SetMargins (BYVAL hEdit AS HWND, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
   SendMessageW(hEdit, EM_SETMARGINS, nMargins, nWidth)
END SUB
' ========================================================================================
' ========================================================================================
' * Sets the width of the left margin for an edit control. The message redraws the control
' to reflect the new margin.
' ========================================================================================
PRIVATE SUB CEdit.SetLeftMargin (BYVAL hEdit AS HWND, BYVAL nWidth AS WORD)
   SendMessageW(hEdit, EM_SETMARGINS, EC_LEFTMARGIN, MAKELONG(nWidth, 0))
END SUB
' ========================================================================================
' ========================================================================================
' * Sets the width of the right margin for an edit control. The message redraws the control
' to reflect the new margin.
' ========================================================================================
PRIVATE SUB CEdit.SetRightMargin (BYVAL hEdit AS HWND, BYVAL nWidth AS WORD)
   SendMessageW(hEdit, EM_SETMARGINS, EC_RIGHTMARGIN, MAKELONG(0, nWidth))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets or clears the modification flag for an edit control. The modification flag
' indicates whether the text within the edit control has been modified.
' ========================================================================================
PRIVATE SUB CEdit.SetModify (BYVAL hEdit AS HWND, BYVAL fModify AS BOOLEAN)
   SendMessageW hEdit, EM_SETMODIFY, cast(WPARAM, fModify), 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets or removes the password character for an edit control. When a password character is
' set, that character is displayed in place of the characters typed by the user.
' ========================================================================================
PRIVATE SUB CEdit.SetPasswordChar (BYVAL hEdit AS HWND, BYVAL dwchar AS DWORD)
   SendMessageW hEdit, EM_SETPASSWORDCHAR, dwchar, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Sets or removes the read-only style (ES_READONLY) of an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.SetReadOnly (BYVAL hEdit AS HWND, BYVAL fReadOnly AS BOOLEAN) AS LONG
   RETURN SendMessageW(hEdit, EM_SETREADONLY, cast(WPARAM, fReadOnly), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline edit control. The formatting rectangle is
' the limiting rectangle into which the control draws the text. The limiting rectangle is
' independent of the size of the edit control window. This message is processed only by
' multiline edit controls.
' ========================================================================================
PRIVATE SUB CEdit.SetRect (BYVAL hEdit AS HWND, BYREF rc AS RECT)
   SendMessageW hEdit, EM_SETRECT, 0, cast(LPARAM, @rc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CEdit.SetRect (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW hEdit, EM_SETRECT, 0, cast(LPARAM, prc)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline edit control. The EM_SETRECTNP message is
' identical to the EM_SETRECT message, except that EM_SETRECTNP does not redraw the edit
' control window. The formatting rectangle is the limiting rectangle into which the
' control draws the text. The limiting rectangle is independent of the size of the edit
' control window. This message is processed only by multiline edit controls.
' ========================================================================================
PRIVATE SUB CEdit.SetRectNoPaint (BYVAL hEdit AS HWND, BYREF rc AS RECT)
   SendMessageW hEdit, EM_SETRECTNP, 0, CAST(LPARAM, @rc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CEdit.SetRectNoPaint (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW hEdit, EM_SETRECTNP, 0, CAST(LPARAM, prc)
END SUB
' ========================================================================================

' ========================================================================================
' * Selects a range of characters in an edit control.
' ========================================================================================
PRIVATE SUB CEdit.SetSel (BYVAL hEdit AS HWND, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
   SendMessageW hEdit, EM_SETSEL, nStart, nEnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the tab stops in a multiline edit control. When text is copied to the control, any
' tab character in the text causes space to be generated up to the next tab stop. This
' message is processed only by multiline edit controls.
' ========================================================================================
PRIVATE FUNCTION CEdit.SetTabStops (BYVAL hEdit AS HWND, BYVAL cTabs AS LONG, BYVAL prgTabStops AS LONG PTR) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_SETTABSTOPS, cTabs, cast(LPARAM, prgTabStops))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of an edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.SetText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   RETURN SetWindowText(hEdit, pwszText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces an edit control's default Wordwrap function with an application-defined
' Wordwrap function.
' ========================================================================================
PRIVATE SUB CEdit.SetWordBreakProc (BYVAL hEdit AS HWND, BYVAL pfn AS LONG_PTR)
   SendMessageW hEdit, EM_SETWORDBREAKPROC, 0, pfn
END SUB
' ========================================================================================

' ========================================================================================
' * Displays a balloon tip associated with an edit control.
' Can be used, for example, to display warning or error messages like "Invalud inùt",
' instead of a message box.
' ========================================================================================
PRIVATE FUNCTION CEdit.ShowBalloonTip (BYVAL hEdit AS HWND, BYVAL peditballoontip AS EDITBALLOONTIP PTR) AS BOOLEAN
   IF peditballoontip = NULL THEN RETURN FALSE
   peditballoontip->cbStruct = SIZEOF(EDITBALLOONTIP)
   RETURN SendMessageW(hEdit, EM_SHOWBALLOONTIP, 0, cast(LPARAM, peditballoontip))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CEdit.ShowBalloonTip (BYVAL hEdit AS HWND, BYVAL pwszTitle AS WSTRING PTR, BYVAL pwszText AS WSTRING PTR, BYVAL iIcon AS LONG) AS BOOLEAN
   DIM bt AS EDITBALLOONTIP
   bt.cbStruct = SIZEOF(EDITBALLOONTIP)
   bt.pszTitle = pwszTitle
   bt.pszText = pwszText
   bt.ttiIcon = iIcon
   RETURN SendMessageW(hEdit, EM_SHOWBALLOONTIP, 0, cast(LPARAM, @bt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Undoes the last edit control operation in the control's undo queue.
' ========================================================================================
PRIVATE FUNCTION CEdit.Undo (BYVAL hEdit AS HWND) AS BOOLEAN
   RETURN SendMessageW(hEdit, EM_UNDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Set the edit control dark mode.
' Only affects the scroll bars of a multiline edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.SetDarkMode (BYVAL hEdit AS HWND) AS HRESULT
   RETURN SetWindowTheme(hEdit, "DarkMode_Explorer", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Removes the edit control dark mode.
' Only affects the scroll bars of a multiline edit control.
' ========================================================================================
PRIVATE FUNCTION CEdit.RemoveDarkMode (BYVAL hEdit AS HWND) AS HRESULT
   RETURN SetWindowTheme(hEdit, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
