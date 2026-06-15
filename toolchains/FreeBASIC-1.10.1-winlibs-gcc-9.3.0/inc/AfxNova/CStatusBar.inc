' ########################################################################################
' Platform: Microsoft Windows
' Filename: CStatusBar.inc
' Purpose:  Windows common controls - Status bar
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
#INCLUDE ONCE "AfxNova/AfxWin.inc"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
' CStatusBar class
' ########################################################################################

TYPE CStatusBar

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION GetBorders (BYVAL hStatusBar AS HWND, BYVAL rgBorders AS LONG PTR) AS LONG
   DECLARE STATIC FUNCTION GetHeight (BYVAL hStatusBar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetIcon (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS HICON
   DECLARE STATIC FUNCTION GetParts (BYVAL hStatusBar AS HWND, BYVAL nParts AS DWORD, BYVAL rgRightCoords AS LONG PTR) AS LONG
   DECLARE STATIC FUNCTION GetPartsCount (BYVAL hStatusBar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYVAL lprc AS RECT PTR) AS LONG
   DECLARE STATIC FUNCTION GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYREF rc AS RECT) AS LONG
   DECLARE STATIC FUNCTION GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS RECT
   DECLARE STATIC FUNCTION GetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYVAL pwszText AS WSTRING PTR) AS DWORD
   DECLARE STATIC FUNCTION GetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetTextDrawingMode (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS LONG
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS LONG
   DECLARE STATIC SUB GetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS WORD, BYVAL pwszText AS WSTRING PTR, BYVAL wLen AS WORD)
   DECLARE STATIC FUNCTION GetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS WORD) AS DWSTRING
   DECLARE STATIC FUNCTION IsSimple (BYVAL hStatusBar AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBkColor (BYVAL hStatusBar AS HWND, BYVAL clrBk AS COLORREF) AS COLORREF
   DECLARE STATIC SUB SetFont (BYVAL hStatusBar AS HWND, BYVAL hFont AS HFONT, BYVAL fRedraw AS LONG = FALSE)
   DECLARE STATIC FUNCTION SetIcon (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL hIcon AS HICON) AS BOOLEAN
   DECLARE STATIC SUB SetMinHeight (BYVAL hStatusBar AS HWND, BYVAL minHeight AS DWORD)
   DECLARE STATIC FUNCTION SetParts (BYVAL hStatusBar AS HWND, BYVAL dwParts AS DWORD, BYVAL rgWidths AS LONG PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL uType AS DWORD = 0) AS BOOLEAN
   DECLARE STATIC SUB SetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL pwszTipText AS WSTRING PTR)
   DECLARE STATIC SUB Simple (BYVAL hStatusBar AS HWND, BYVAL fSimple AS BOOLEAN)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CStatusBar
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CStatusBar
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Retrieves the current widths of the horizontal, and vertical borders of a status window,
' and the width of the border between rectangles. Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetBorders (BYVAL hStatusBar AS HWND, BYVAL rgBorders AS LONG PTR) AS LONG
   RETURN SendMessageW(hStatusBar, SB_GETBORDERS, 0, cast(LPARAM, rgBorders))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the height of the status bar.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetHeight (BYVAL hStatusBar AS HWND) AS LONG
   DIM rc AS RECT
   GetWindowRect(hStatusBar, @rc)
   RETURN rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the icon for a part in a status bar.
' Returns the handle to the icon if successful, or NULL otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetIcon (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS HICON
  RETURN cast(HICON, SendMessageW(hStatusBar, SB_GETICON, nPart, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a count of the parts in a status window. The message also retrieves the
' coordinate of the right edge of the specified number of parts.
' - nParts: Number of parts for which to retrieve coordinates. If this parameter is greater
'   than the number of parts in the window, the message retrieves coordinates for existing
'   parts only.
' - rgRightCoords: Pointer to an integer array that has the same number of elements as parts
'   specified by nParts. Each element in the array receives the client coordinate of the
'   right edge of the corresponding part. If an element is set to -1, the position of the
'   right edge for that part extends to the right edge of the window. To retrieve the current
'   number of parts, set this parameter to zero.
' This message always returns the number of parts in the status bar.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetParts (BYVAL hStatusBar AS HWND, BYVAL nParts AS DWORD, BYVAL rgRightCoords AS LONG PTR) AS LONG
   RETURN SendMessageW(hStatusBar, SB_GETPARTS, nParts, cast(LPARAM, rgRightCoords))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a count of the parts in a status window.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetPartsCount (BYVAL hStatusBar AS HWND) AS DWORD
   RETURN SendMessageW(hStatusBar, SB_GETPARTS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the bounding rectangle of a part in a status window.
' - nPart: Zero-based index of the part whose bounding rectangle is to be retrieved.
' - lprc: Pointer to a RECT structure that receives the bounding rectangle.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYVAL lprc AS RECT PTR) AS LONG
   RETURN SendMessageW(hStatusBar, SB_GETRECT, cast(WPARAM, nPart), cast(LPARAM, lprc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYREF rc AS RECT) AS LONG
   RETURN SendMessageW(hStatusBar, SB_GETRECT, cast(WPARAM, nPart), cast(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS RECT
   DIM rc AS RECT
   SendMessageW(hStatusBar, SB_GETRECT, cast(WPARAM, nPart), cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text from the specified part of a status window.
' - nPart: Zero-based index of the part from which to retrieve text.
' - pwszText: Pointer to the buffer that receives the text as a null-terminated string.
'   Use the SB_GETTEXTLENGTH message to determine the required size of the buffer.
' Returns a 32-bit value that consists of two 16-bit values. The low word specifies the
' length, in characters, of the text. The high word specifies the type of operation used
' to draw the text.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYVAL pwszText AS WSTRING PTR) AS DWORD
   IF pwszText = NULL THEN EXIT FUNCTION
   RETURN SendMessageW(hStatusBar, SB_GETTEXTW, cast(WPARAM, nPart), cast(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text from the specified part of a status window.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS DWSTRING
   DIM nLen AS LONG, buffer AS dWSTRING
   DIM dwResult AS DWORD = SendMessageW(hStatusBar, SB_GETTEXTLENGTH, nPart, 0)
   nLen = LOWORD(dwResult)
   buffer = WSPACE(nLen + 1)
   SendMessageW hStatusBar, SB_GETTEXTW, nPart, CAST(LPARAM, STRPTR(buffer))
   RETURN LEFT(buffer, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of operation used to draw the text.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetTextDrawingMode (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS LONG
   DIM dwResult AS DWORD = SendMessageW(hStatusBar, SB_GETTEXTLENGTH, cast(WPARAM, nPart), 0)
   RETURN HIWORD(dwResult)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the length, in characters, of the text from the specified part of a status window.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetTextLength (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS LONG
   DIM dwResult AS DWORD = SendMessageW(hStatusBar, SB_GETTEXTLENGTH, cast(WPARAM, nPart), 0)
   RETURN LOWORD(dwResult)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the tooltip text for a part in a status bar. The status bar must have been
' created with the SBT_TOOLTIPS style to enable tooltips.
' Using this message incorrectly can cause problems for your application. For example, if
' the text is too large for the pwszText buffer, it could cause a buffer overflow.
' ========================================================================================
PRIVATE SUB CStatusBar.GetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS WORD, BYVAL pwszText AS WSTRING PTR, BYVAL wLen AS WORD)
   IF pwszText = NULL THEN EXIT SUB
   SendMessageW(hStatusBar, SB_GETTIPTEXTW, cast(WPARAM, MAKELONG(nPart, wLen)), cast(LPARAM, pwszText))
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the tooltip text for a part in a status bar. The status bar must have been
' created with the SBT_TOOLTIPS style to enable tooltips.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.GetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS WORD) AS DWSTRING
   DIM wszBuffer AS WSTRING * 65535
   SendMessageW hStatusBar, SB_GETTIPTEXTW, MAKELONG(nPart, SIZEOF(wszBuffer)\2), CAST(LPARAM, @wszBuffer)
   RETURN wszBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Checks a status bar control to determine if it is in simple mode.
' Returns TRUE if the status bar control is in simple mode, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.IsSimple (BYVAL hStatusBar AS HWND) AS BOOLEAN
   RETURN SendMessageW(hStatusBar, SB_ISSIMPLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the background color in a status bar.
' - clrBk: COLORREF value that specifies the new background color. Specify the CLR_DEFAULT
'   value to cause the status bar to use its default background color.
' Returns the previous background color, or CLR_DEFAULT if the background color is the default color.
' Note: Does nothing if visual styles are used.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.SetBkColor (BYVAL hStatusBar AS HWND, BYVAL clrBk AS COLORREF) AS COLORREF
   RETURN SendMessageW(hStatusBar, SB_SETBKCOLOR, 0, cast(LPARAM, clrBk))
END FUNCTION
' ========================================================================================

' ========================================================================================
'  Sets the font that the status bar is to use when drawing text.
' ========================================================================================
PRIVATE SUB CStatusBar.SetFont (BYVAL hStatusBar AS HWND, BYVAL hFont AS HFONT, BYVAL fRedraw AS LONG = FALSE)
   SendMessageW(hStatusBar, WM_SETFONT, cast(WPARAM, hFont), cast(LPARAM, fRedraw))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the icon for a part in a status bar.
' - nPart: Zero-based index of the part that will receive the icon. If this parameter is -1,
'   the status bar is assumed to be a simple status bar.
' - hIcon: Handle to the icon to be set. If this value is NULL, the icon is removed from the part.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.SetIcon (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL hIcon AS HICON) AS BOOLEAN
   RETURN SendMessageW(hStatusBar, SB_SETICON, cast(WPARAM, nPart), cast(LPARAM, hIcon))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum length, in pixels, of a status window's drawing area.
' The minimum height is the sum of minHeight and twice the width, in pixels, of the vertical
' border of the status window. An application must send the WM_SIZE message to the status
' window to redraw the window.
' ========================================================================================
PRIVATE SUB CStatusBar.SetMinHeight (BYVAL hStatusBar AS HWND, BYVAL minHeight AS DWORD)
   SendMessageW(hStatusBar, SB_SETMINHEIGHT, cast(WPARAM, minHeight), 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the number of parts in a status window and the coordinate of the right edge of each part.
' - dwParts: Number of parts to set (cannot be greater than 256).
' - rgWidths: Pointer to an integer array. The number of elements is specified in dwParts.
'   Each element specifies the position, in client coordinates, of the right edge of the
'   corresponding part. If an element is -1, the right edge of the corresponding part extends
'   to the border of the window.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.SetParts (BYVAL hStatusBar AS HWND, BYVAL dwParts AS DWORD, BYVAL rgWidths AS LONG PTR) AS BOOLEAN
   RETURN SendMessageW(hStatusBar, SB_SETPARTS, cast(WPARAM, dwParts), cast(LPARAM, rgWidths))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text in the specified part of a status window.
' - nPart: The zero-based index of the part to set. If it is set to SB_SIMPLEID, the status
'   window is assumed to be a simple mode status bar; that is, a status bar with only one part.
' - pwszText: Pointer to a null-terminated string that specifies the text to set. If nPart is
'   SBT_OWNERDRAW, this parameter represents 32 bits of data. The parent window must interpret
'   the data and draw the text when it receives the WM_DRAWITEM message.
' - uType:
'   0	: The text is drawn with a border to appear lower than the plane of the window.
'   SBT_NOBORDERS    : The text is drawn without borders.
'   SBT_OWNERDRAW    : The text is drawn by the parent window.
'                      Note  A simple mode status bar does not support owner drawing.
'   SBT_POPOUT       : The text is drawn with a border to appear higher than the plane of the window.
'   SBT_RTLREADING   : The text will be displayed in the opposite direction to the text in the parent window.
'   SBT_NOTABPARSING : Tab characters are ignored.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CStatusBar.SetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL uType AS DWORD = 0) AS BOOLEAN
   RETURN SendMessageW(hStatusBar, SB_SETTEXTW, cast(WPARAM, nPart OR uType), cast(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the tooltip text for a part in a status bar. The status bar must have been created
' with the SBT_TOOLTIPS style to enable tooltips.
' - nPart: Zero-based index of the part that will receive the tooltip text.
' - pwszText: Pointer to a character buffer that contains the new tooltip text.
' Usage example:
'   DIM rgParts(1 TO 3) AS LONG = {pWindow.ScaleX(100), pWindow.ScaleX(220), -1}
'   IF CStatusBar.SetParts(hStatusBar, 3, @rgParts(1)) THEN
'      CStatusBar.Simple(hStatusBar, FALSE)
'   END IF
' ========================================================================================
PRIVATE SUB CStatusBar.SetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL pwszTipText AS WSTRING PTR)
   SendMessageW(hStatusBar, SB_SETTIPTEXTW, cast(WPARAM, nPart), cast(LPARAM, pwszTipText))
END SUB
' ========================================================================================

' ========================================================================================
' * Specifies whether a status window displays simple text or displays all window parts set
' by a previous SB_SETPARTS message.
' - fSimple: Display type flag. If this parameter is TRUE, the window displays simple text.
'   If it is FALSE, it displays multiple parts.
' ========================================================================================
PRIVATE SUB CStatusBar.Simple (BYVAL hStatusBar AS HWND, BYVAL fSimple AS BOOLEAN)
   SendMessageW(hStatusBar, SB_SIMPLE, fSimple, 0)
END SUB
' ========================================================================================

END NAMESPACE
