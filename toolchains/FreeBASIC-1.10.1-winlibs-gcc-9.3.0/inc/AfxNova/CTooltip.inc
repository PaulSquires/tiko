' ########################################################################################
' Platform: Microsoft Windows
' Filename: CTooltip.inc
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
#include once "win/uxtheme.bi"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' CTooltip class
' ========================================================================================
TYPE CTooltip

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION ComCtlVersion () AS LONG
   DECLARE STATIC SUB Activate (BYVAL hTooltip AS HWND, BYVAL fActivate AS BOOLEAN)
   DECLARE STATIC SUB Activate (BYVAL hTooltip AS HWND)
   DECLARE STATIC SUB Deactivate (BYVAL hTooltip AS HWND)
   DECLARE STATIC FUNCTION AddTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION AddTooltip (BYVAL hwnd AS HWND, BYREF wszText AS CONST WSTRING = "", BYVAL bBalloon AS BOOLEAN = FALSE, BYVAL bCentered AS BOOLEAN = FALSE) AS HWND
   DECLARE STATIC FUNCTION AdjustRect (BYVAL hTooltip AS HWND, BYVAL fLarger AS BOOLEAN, BYVAL lprc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION AdjustRect (BYVAL hTooltip AS HWND, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC SUB DelTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB DelTool (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   DECLARE STATIC SUB DeleteTooltip (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND)
   DECLARE STATIC FUNCTION EnumTools (BYVAL hTooltip AS HWND, BYVAL iTool AS DWORD, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION EnumTools (BYVAL hTooltip AS HWND, BYVAL iTool AS DWORD, BYREF ti AS TOOLINFOW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBubbleSize (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS DWORD
   DECLARE STATIC FUNCTION GetBubbleSize (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS DWORD
   DECLARE STATIC FUNCTION GetCurrentTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCurrentTool (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetDelayTime (BYVAL hTooltip AS HWND, BYVAL flag AS DWORD) AS LONG
   DECLARE STATIC SUB GetMargin (BYVAL hTooltip AS HWND, BYVAL lprc AS RECT PTR)
   DECLARE STATIC SUB GetMargin (BYVAL hTooltip AS HWND, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION GetMargin (BYVAL hTooltip AS HWND) AS RECT
   DECLARE STATIC FUNCTION GetMaxTipWidth (BYVAL hTooltip AS HWND) AS LONG
   DECLARE STATIC SUB GetText (BYVAL hTooltip AS HWND, BYVAL numChars AS DWORD, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB GetText (BYVAL hTooltip AS HWND, BYVAL numChars AS DWORD, BYREF ti AS TOOLINFOW)
   DECLARE STATIC FUNCTION GetText (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND, BYVAL numChars AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetTipBkColor (BYVAL hTooltip AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetTipTextColor (BYVAL hTooltip AS HWND) AS COLORREF
   DECLARE STATIC SUB GetTitle (BYVAL hTooltip AS HWND, BYVAL pTTGetTitle AS TTGETTITLE PTR)
   DECLARE STATIC SUB GetTitle (BYVAL hTooltip AS HWND, BYREF tTTGetTitle AS TTGETTITLE)
   DECLARE STATIC FUNCTION GetToolCount (BYVAL hTooltip AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetToolInfo (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetToolInfo (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetToolInfo (BYVAL hTooltip AS HWND) AS TOOLINFOW
   DECLARE STATIC FUNCTION HitTest (BYVAL hTooltip AS HWND, BYVAL lphti AS TTHITTESTINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION HitTest (BYVAL hTooltip AS HWND, BYREF phti AS TTHITTESTINFOW) AS BOOLEAN
   DECLARE STATIC SUB NewToolRect (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB NewToolRect (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   DECLARE STATIC SUB Pop (BYVAL hTooltip AS HWND)
   DECLARE STATIC SUB Popup (BYVAL hTooltip AS HWND)
   DECLARE STATIC FUNCTION RelayEvent (BYVAL hTooltip AS HWND, BYVAL lpmsg AS tagMSG PTR) AS LONG
   DECLARE STATIC FUNCTION RelayEvent (BYVAL hTooltip AS HWND, BYREF msg AS tagMSG) AS LONG
   DECLARE STATIC SUB SetDelayTime (BYVAL hTooltip AS HWND, BYVAL flag AS DWORD, BYVAL iTime AS SHORT)
   DECLARE STATIC SUB SetMargin (BYVAL hTooltip AS HWND, BYVAL lprc AS RECT PTR)
   DECLARE STATIC SUB SetMargin (BYVAL hTooltip AS HWND, BYREF rc AS RECT)
   DECLARE STATIC SUB SetMargin (BYVAL hTooltip AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG)
   DECLARE STATIC FUNCTION SetMaxTipWidth (BYVAL hTooltip AS HWND, BYVAL iWidth AS LONG) AS LONG
   DECLARE STATIC SUB SetTipBkColor (BYVAL hTooltip AS HWND, BYVAL clr AS COLORREF)
   DECLARE STATIC SUB SetTipTextColor (BYVAL hTooltip AS HWND, BYVAL clr AS COLORREF)
   DECLARE STATIC FUNCTION SetTitle (BYVAL hTooltip AS HWND, BYVAL nIcon AS LONG, BYVAL pwszTitle AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC SUB SetToolInfo (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB SetToolInfo (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   DECLARE STATIC SUB SetTooltipText (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND, BYREF wszText AS CONST WSTRING)
   DECLARE STATIC SUB SetWindowTheme (BYVAL hTooltip AS HWND, BYVAL pwszTheme AS WSTRING PTR)
   DECLARE STATIC SUB SetDarkMode (BYVAL hTooltip AS HWND)
   DECLARE STATIC SUB TrackActivate (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB TrackActivate (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   DECLARE STATIC SUB TrackDeactivate (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB TrackDeactivate (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   DECLARE STATIC SUB TrackPosition (BYVAL hTooltip AS HWND, BYVAL xPos AS LONG, BYVAL yPos AS LONG)
   DECLARE STATIC SUB Update (BYVAL hTooltip AS HWND)
   DECLARE STATIC SUB UpdateTipText (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   DECLARE STATIC SUB UpdateTipText (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   DECLARE STATIC FUNCTION WindowFromPoint (BYVAL hTooltip AS HWND, BYVAL lppt AS POINT PTR) AS HWND

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CTooltip
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CTooltip
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Returns the version of ComCtrl.dll version multiplied by 100, e.g. 601 for version 6.01.
' Example: DIM ver AS LONG = AfxGetFileVersion("COMCTL32.DLL")
' ========================================================================================
PRIVATE FUNCTION CTooltip.ComCtlVersion () AS LONG
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
' * Activates or deactivates a Tooltip control.
' ========================================================================================
PRIVATE SUB CTooltip.Activate (BYVAL hTooltip AS HWND, BYVAL fActivate AS BOOLEAN)
   SendMessageW(hTooltip, TTM_ACTIVATE, fActivate, 0)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.Activate (BYVAL hTooltip AS HWND)
   SendMessageW(hTooltip, TTM_ACTIVATE, CTRUE, 0)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.Deactivate (BYVAL hTooltip AS HWND)
   SendMessageW(hTooltip, TTM_ACTIVATE, FALSE, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Registers a tool with a Tooltip control.
' See the AddTooltip method.
' ========================================================================================
PRIVATE FUNCTION CTooltip.AddTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   IF lpti = NULL THEN RETURN FALSE
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_ADDTOOLW, 0, CAST(LPARAM, lpti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates a Tooltip control's text display rectangle from its window rectangle, or the
' tooltip window rectangle needed to display a specified text display rectangle.
' ========================================================================================
PRIVATE FUNCTION CTooltip.AdjustRect (BYVAL hTooltip AS HWND, BYVAL fLarger AS BOOLEAN, BYVAL lprc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hTooltip, TTM_ADJUSTRECT, cast(WPARAM, fLarger), cast(LPARAM, lprc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.AdjustRect (BYVAL hTooltip AS HWND, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hTooltip, TTM_ADJUSTRECT, cast(WPARAM, fLarger), cast(LPARAM, @rc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes a tool from a Tooltip control.
' See the DeleteToolTip method.
' ========================================================================================
PRIVATE SUB CTooltip.DelTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_DELTOOLW, 0, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.DelTool (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_DELTOOLW, 0, cast(LPARAM, @ti))
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the information that a Tooltip control maintains about the current tool--that
' is, the tool for which the Tooltip is currently displaying text.
' ========================================================================================
PRIVATE FUNCTION CTooltip.EnumTools (BYVAL hTooltip AS HWND, BYVAL iTool AS DWORD, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   IF lpti = NULL THEN RETURN FALSE
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_ENUMTOOLSW, cast(WPARAM, iTool), cast(LPARAM, lpti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.EnumTools (BYVAL hTooltip AS HWND, BYVAL iTool AS DWORD, BYREF ti AS TOOLINFOW) AS BOOLEAN
   IF VARPTR(ti) = NULL THEN RETURN FALSE
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.>cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_ENUMTOOLSW, cast(WPARAM, iTool), cast(LPARAM, @ti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width and height of a Tooltip control.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetBubbleSize (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS DWORD
   IF lpti = NULL THEN RETURN 0
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_GETBUBBLESIZE, 0, cast(LPARAM, lpti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetBubbleSize (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS DWORD
   IF VARPTR(ti) = NULL THEN RETURN 0
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_GETBUBBLESIZE, 0, cast(LPARAM, @ti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the information for the current tool in a Tooltip control.
' IF lpti is NULL, the return value indicates the existence of the current tool without
' actually retrieving the tool information. If this value is not NULL, the cbSize member
' of the TOOLINFOW structure must be filled in before sending this message.
' A “current tool” only exists in two situations:
' - The mouse is physically over a tool’s rectangle, or
' - The tooltip is currently active (track mode, or a tooltip is being shown)
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetCurrentTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   IF lpti <> NULL THEN
   #ifdef __FB_64BIT__
      IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
   #else
      IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
   #endif
   END IF
   RETURN SendMessageW(hTooltip, TTM_GETCURRENTTOOLW, 0, cast(LPARAM, lpti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetCurrentTool (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS BOOLEAN
   IF VARPTR(ti) <> NULL THEN
   #ifdef __FB_64BIT__
      IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
   #else
      IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
   #endif
   END IF
   RETURN SendMessageW(hTooltip, TTM_GETCURRENTTOOLW, 0, cast(LPARAM, @ti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the information for the current tool in a Tooltip control.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetDelayTime (BYVAL hTooltip AS HWND, BYVAL flag AS DWORD) AS LONG
   RETURN SendMessageW(hTooltip, TTM_GETDELAYTIME, cast(WPARAM, flag), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the top, left, bottom, and right margins set for a Tooltip window. A margin is
' the distance, in pixels, between the ToolTip window border and the text contained within
' the ToolTip window.
' ========================================================================================
PRIVATE SUB CTooltip.GetMargin (BYVAL hTooltip AS HWND, BYVAL lprc AS RECT PTR)
   SendMessageW(hTooltip, TTM_GETMARGIN, 0, cast(LPARAM, lprc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.GetMargin (BYVAL hTooltip AS HWND, BYREF rc AS RECT)
   SendMessageW(hTooltip, TTM_GETMARGIN, 0, cast(LPARAM, @rc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetMargin (BYVAL hTooltip AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hTooltip, TTM_GETMARGIN, 0, cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the maximum width for a Tooltip window.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetMaxTipWidth (BYVAL hTooltip AS HWND) AS LONG
   RETURN SendMessageW(hTooltip, TTM_GETMAXTIPWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the information a ToolTtp control maintains about a tool.
' - hTooltip: Handle of the ToolTip control.
' Example:
' DIM ti AS TOOLINFOW
' ti.hwnd = GetParent(hCtl)
' ti.uId = CAST(UINT_PTR, hCtl)
' DIM wszText AS WSTRING * 50 + 1
' ti.lpszText = @wszText
' CTooltip.GetText(hTTP, 50, @ti)
' IF ti.lpszText THEN print *ti.lpszText
' ========================================================================================
PRIVATE SUB CTooltip.GetText (BYVAL hTooltip AS HWND, BYVAL numChars AS DWORD, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_GETTEXTW, numChars, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.GetText (BYVAL hTooltip AS HWND, BYVAL numChars AS DWORD, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_GETTEXTW, numChars, cast(LPARAM, @ti))
END SUB
' ========================================================================================
' ========================================================================================
' * Retrieves the information a ToolTip control maintains about a tool.
' - hTooltip: Handle of the ToolTip control.
' - hwnd: Handle to the window that contains the tool.
' - numChars: Maximum number of characters to return.
' Note: To be used with tooltips added with the AddTooltip method. With tooltips with
' different characteristics, use the previous GetText procedure passing a TOOLINFOW structure.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetText (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND, BYVAL numChars AS DWORD) AS DWSTRING
   DIM ti AS TOOLINFOW
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   ' Try IDISHWND pattern first
   ti.hwnd = GetParent(hwnd)
   ti.uId = CAST(UINT_PTR, hwnd)
   IF SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, cast(LPARAM, @ti)) = 0 THEN
      ' Try non-IDISHWND pattern
      ti.hwnd = hwnd
      ti.uId  = 0
      IF SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, cast(LPARAM, @ti)) = 0 THEN
         RETURN ""   ' Tool not found
      END IF
   END IF
   ' At this point ti contains the REAL tool info
   ' Now retrieve the text
   DIM dwsText AS DWSTRING = WSPACE(numChars + 1)
   ti.lpszText = *dwsText
   SendMessageW(hTooltip, TTM_GETTEXTW, numChars, cast(LPARAM, @ti))
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the background color in a Tooltip window.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetTipBkColor (BYVAL hTooltip AS HWND) AS COLORREF
   RETURN SendMessageW(hTooltip, TTM_GETTIPBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text color in a Tooltip window.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetTipTextColor (BYVAL hTooltip AS HWND) AS COLORREF
   RETURN SendMessageW(hTooltip, TTM_GETTIPTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information concerning the title of a tooltip control.
' ========================================================================================
PRIVATE SUB CTooltip.GetTitle (BYVAL hTooltip AS HWND, BYVAL pTTGetTitle AS TTGETTITLE PTR)
   IF pTTGetTitle = NULL THEN EXIT SUB
   pTTGetTitle->dwSize = SIZEOF(TTGETTITLE)
   SendMessageW(hTooltip, TTM_GETTITLE, 0, cast(LPARAM, pTTGetTitle))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.GetTitle (BYVAL hTooltip AS HWND, BYREF tTTGetTitle AS TTGETTITLE)
   IF VARPTR(tTTGetTitle) = NULL THEN EXIT SUB
   tTTGetTitle.dwSize = SIZEOF(TTGETTITLE)
   SendMessageW(hTooltip, TTM_GETTITLE, 0, cast(LPARAM, @tTTGetTitle))
END SUB
' ========================================================================================

' ========================================================================================
' * Retrieves a count of the tools maintained by a Tooltip control.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetToolCount (BYVAL hTooltip AS HWND) AS LONG
   RETURN SendMessageW(hTooltip, TTM_GETTOOLCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the information that a Tooltip control maintains about a tool.
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetToolInfo (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
   IF lpti = NULL THEN RETURN FALSE
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, cast(LPARAM, lpti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetToolInfo (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS BOOLEAN
   IF VARPTR(ti) = NULL THEN RETURN FALSE
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   RETURN SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, cast(LPARAM, @ti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.GetToolInfo (BYVAL hTooltip AS HWND) AS TOOLINFOW
   DIM ti AS TOOLINFOW
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, cast(LPARAM, @ti))
   RETURN ti
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests a point to determine whether it is within the bounding rectangle of the specified
' tool and, if it is, retrieves information about the tool.
' ========================================================================================
PRIVATE FUNCTION CTooltip.HitTest (BYVAL hTooltip AS HWND, BYVAL lphti AS TTHITTESTINFOW PTR) AS BOOLEAN
   RETURN SendMessageW(hTooltip, TTM_HITTEST, 0, cast(LPARAM, lphti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.HitTest (BYVAL hTooltip AS HWND, BYREF phti AS TTHITTESTINFOW) AS BOOLEAN
   RETURN SendMessageW(hTooltip, TTM_HITTEST, 0, cast(LPARAM, @phti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a new bounding rectangle for a tool.
' ========================================================================================
PRIVATE SUB CTooltip.NewToolRect (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_NEWTOOLRECTW, 0, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.NewToolRect (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_NEWTOOLRECTW, 0, cast(LPARAM, @ti))
END SUB
' ========================================================================================

' ========================================================================================
' * Removes a displayed Tooltip window from view.
' ========================================================================================
PRIVATE SUB CTooltip.Pop (BYVAL hTooltip AS HWND)
   SendMessageW hTooltip, TTM_POP, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Causes the Tooltip to display at the coordinates of the last mouse message.
' ========================================================================================
PRIVATE SUB CTooltip.Popup (BYVAL hTooltip AS HWND)
   SendMessageW hTooltip, TTM_POPUP, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Passes a mouse message to a Tooltip control for processing.
' ========================================================================================
PRIVATE FUNCTION CTooltip.RelayEvent (BYVAL hTooltip AS HWND, BYVAL lpmsg AS tagMSG PTR) AS LONG
   RETURN SendMessageW(hTooltip, TTM_RELAYEVENT, 0, cast(LPARAM, lpmsg))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTooltip.RelayEvent (BYVAL hTooltip AS HWND, BYREF msg AS tagMSG) AS LONG
   RETURN SendMessageW(hTooltip, TTM_RELAYEVENT, 0, cast(LPARAM, @msg))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the initial, pop-up, and reshow durations for a Tooltip control.
' ========================================================================================
PRIVATE SUB CTooltip.SetDelayTime (BYVAL hTooltip AS HWND, BYVAL flag AS DWORD, BYVAL iTime AS SHORT)
   SendMessageW(hTooltip, TTM_SETDELAYTIME, flag, MAKELONG(iTime, 0))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the top, left, bottom, and right margins for a Tooltip window. A margin is the
' distance, in pixels, between the ToolTip window border and the text contained within the
' ToolTip window.
' ========================================================================================
PRIVATE SUB CTooltip.SetMargin (BYVAL hTooltip AS HWND, BYVAL lprc AS RECT PTR)
   SendMessageW(hTooltip, TTM_SETMARGIN, 0, cast(LPARAM, lprc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.SetMargin (BYVAL hTooltip AS HWND, BYREF rc AS RECT)
   SendMessageW(hTooltip, TTM_SETMARGIN, 0, cast(LPARAM, @rc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.SetMargin (BYVAL hTooltip AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG)
   DIM rc AS RECT = (nLeft, nTop, nRight, nBottom)
   SendMessageW(hTooltip, TTM_SETMARGIN, 0, cast(LPARAM, @rc))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the maximum width for a Tooltip window.
' ========================================================================================
PRIVATE FUNCTION CTooltip.SetMaxTipWidth (BYVAL hTooltip AS HWND, BYVAL iWidth AS LONG) AS LONG
   RETURN SendMessageW(hTooltip, TTM_SETMAXTIPWIDTH, 0, cast(LPARAM, iWidth))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the background color in a Tooltip window.
' Does nothing when using visual styles.
' ========================================================================================
PRIVATE SUB CTooltip.SetTipBkColor (BYVAL hTooltip AS HWND, BYVAL clr AS COLORREF)
   SendMessageW(hTooltip, TTM_SETTIPBKCOLOR, cast(WPARAM, clr), 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the text color in a Tooltip window.
' Does nothing when using visual styles.
' ========================================================================================
PRIVATE SUB CTooltip.SetTipTextColor (BYVAL hTooltip AS HWND, BYVAL clr AS COLORREF)
   SendMessageW(hTooltip, TTM_SETTIPTEXTCOLOR, cast(WPARAM, clr), 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Adds a standard icon and title string to a Tooltip.
' If you use visual styles, you will get a bigger caption size that if you don't, and you
' can also use the large predefined icons.
' ========================================================================================
PRIVATE FUNCTION CTooltip.SetTitle (BYVAL hTooltip AS HWND, BYVAL nIcon AS LONG, BYVAL pwszTitle AS WSTRING PTR) AS BOOLEAN
   RETURN SendMessageW(hTooltip, TTM_SETTITLEW, nIcon, cast(LPARAM, pwszTitle))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the information that a Tooltip control maintains for a tool.
' ========================================================================================
PRIVATE SUB CTooltip.SetToolInfo (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_SETTOOLINFOW, 0, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.SetToolInfo (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_SETTOOLINFOW, 0, cast(LPARAM, @ti))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the visual style of a Tooltip control.
' ========================================================================================
PRIVATE SUB CTooltip.SetWindowTheme (BYVAL hTooltip AS HWND, BYVAL pwszTheme AS WSTRING PTR)
   SendMessageW(hTooltip, TTM_SETWINDOWTHEME, 0, cast(LPARAM, pwszTheme))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the dark mode visual style of a Tooltip control.
' You need to use visual styles.
' ========================================================================================
PRIVATE SUB CTooltip.SetDarkMode (BYVAL hTooltip AS HWND)
   DIM wszTheme AS WSTRING * 20 = "DarkMode_Explorer"
   SendMessageW(hTooltip, TTM_SETWINDOWTHEME, 0, cast(LPARAM, @wszTheme))
END SUB
' ========================================================================================

' ========================================================================================
' * Activates a tracking Tooltip.
' ========================================================================================
PRIVATE SUB CTooltip.TrackActivate (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_TRACKACTIVATE, CTRUE, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.TrackActivate (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_TRACKACTIVATE, CTRUE, cast(LPARAM, @ti))
END SUB
' ========================================================================================
' ========================================================================================
' * Deactivates a tracking Tooltip.
' ========================================================================================
PRIVATE SUB CTooltip.TrackDeactivate (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_TRACKACTIVATE, FALSE, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.TrackDeactivate (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_TRACKACTIVATE, FALSE, cast(LPARAM, @ti))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the position of a tracking Tooltip.
' ========================================================================================
PRIVATE SUB CTooltip.TrackPosition (BYVAL hTooltip AS HWND, BYVAL xPos AS LONG, BYVAL yPos AS LONG)
   SendMessageW(hTooltip, TTM_TRACKPOSITION, 0, cast(LPARAM, MAKELONG(xPos, yPos)))
END SUB
' ========================================================================================

' ========================================================================================
' Forces the current Tooltip to be redrawn.
' ========================================================================================
PRIVATE SUB CTooltip.Update (BYVAL hTooltip AS HWND)
   SendMessageW(hTooltip, TTM_UPDATE, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Tooltip text for a tool.
' ========================================================================================
PRIVATE SUB CTooltip.UpdateTipText (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
   IF lpti = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 64 ELSE lpti->cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN lpti->cbSize = 44 ELSE lpti->cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_UPDATETIPTEXTW, 0, cast(LPARAM, lpti))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTooltip.UpdateTipText (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
   IF VARPTR(ti) = NULL THEN EXIT SUB
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 64 ELSE ti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN ti.cbSize = 44 ELSE ti.cbSize = 48
#endif
   SendMessageW(hTooltip, TTM_UPDATETIPTEXTW, 0, cast(LPARAM, @ti))
END SUB
' ========================================================================================

' ========================================================================================
' * Creates a Tooltip for a control.
' Parameters:
' - hwnd      = Handle of the window or control
' - wszText   = Tooltip text
' - bBalloon  = Balloon tip (TRUE or FALSE)
' - bCentered = Centered (TRUE or FALSE)
' Return Value:
'   The handle of the Tooltip control
' ========================================================================================
PRIVATE FUNCTION CTooltip.AddTooltip (BYVAL hwnd AS HWND, BYREF wszText AS CONST WSTRING = "", BYVAL bBalloon AS BOOLEAN = FALSE, BYVAL bCentered AS BOOLEAN = FALSE) AS HWND
   IF IsWindow(hwnd) = 0 THEN EXIT FUNCTION
   ' // Creates the tooltip control
   DIM dwStyle AS DWORD = WS_POPUP OR TTS_ALWAYSTIP
   IF bBalloon THEN dwStyle = dwStyle OR TTS_BALLOON
   DIM hTooltip AS ..HWND
   hTooltip = CreateWindowExW(0, "tooltips_class32", "", dwStyle, 0, 0, 0, 0, NULL, NULL, NULL, NULL)
   IF hTooltip = NULL THEN EXIT FUNCTION
   ' // You must explicitly define a tooltip control as topmost. Otherwise, it might be covered by the parent window.
   SetWindowPos(hTooltip, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOACTIVATE)
   ' // Registers the window with the tooltip control
   ' // 32-bit: The size of the TOOLINFOW structure is 48 bytes in
   '    version 6 of comctl32.dll, and 44 bytes in lower versions.
   ' // 64-bit: The size of the TOOLINFOW structure is 72 bytes in
   '    version 6 of comctl32.dll, and 64 bytes in lower versions.
   DIM tti AS TOOLINFOW
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN tti.cbSize = 64 ELSE tti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN tti.cbSize = 44 ELSE tti.cbSize = 48
#endif
   IF (GetWindowLongPtrW(hwnd, GWL_STYLE) AND WS_CHILD) = WS_CHILD THEN
      tti.uFlags = TTF_IDISHWND OR TTF_SUBCLASS
      tti.hwnd = GetParent(hwnd)
      tti.uId = CAST(UINT_PTR, hwnd)
   ELSE
      tti.uFlags = TTF_SUBCLASS
      tti.hwnd = hwnd
      tti.uId = 0
      GetClientRect(hwnd, @tti.rect)
   END IF
   IF bCentered THEN tti.uFlags = tti.uFlags OR TTF_CENTERTIP
   tti.hinst = GetModuleHandleW(NULL)
   tti.lpszText = CAST(LPWSTR, @wszText)
   SendMessageW(hTooltip, TTM_ADDTOOLW, 0, CAST(LPARAM, @tti))
   RETURN hTooltip
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets/replaces the text of a Tooltip control
' Parameters:
' - hTooltip = Handle of the tooltip control
' - hwnd     = Handle of the window or control
' - wszText  = Tooltip text
' ========================================================================================
PRIVATE SUB CTooltip.SetTooltipText (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND, BYREF wszText AS CONST WSTRING)
   IF hTooltip = NULL OR hwnd = NULL THEN EXIT SUB
   ' // 32-bit: The size of the TOOLINFOW structure is 48 bytes in
   '    version 6 of comctl32.dll, and 44 bytes in lower versions.
   ' // 64-bit: The size of the TOOLINFOW structure is 72 bytes in
   '    version 6 of comctl32.dll, and 64 bytes in lower versions.
   DIM tti AS TOOLINFOW
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN tti.cbSize = 64 ELSE tti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN tti.cbSize = 44 ELSE tti.cbSize = 48
#endif
   IF (GetWindowLongPtrW(hwnd, GWL_STYLE) AND WS_CHILD) = WS_CHILD THEN
      tti.hwnd = GetParent(hwnd)
      tti.uId = CAST(UINT_PTR, hwnd)
   ELSE
      tti.hwnd = hwnd
      tti.uId = 0
   END IF
   ' // Retrieve the tooltip information
   SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, CAST(LPARAM, @tti))
   IF SendMessageW(hTooltip, TTM_GETTOOLINFOW, 0, CAST(LPARAM, @tti)) THEN
      tti.lpszText = CAST(LPWSTR, @wszText)
      SendMessageW(hTooltip, TTM_SETTOOLINFOW, 0, CAST(LPARAM, @tti))
   END IF
   ' // Note: Windows provides the TTM_UPDATETIPTEXT message, but needs Vista or superior.
END SUB
' ========================================================================================

' ========================================================================================
' * Removes a tool from a Tooltip control.
' Parameters:
' - hTooltip = Handle of the Tooltip control
' - hwnd     = Handle of the window or control
' ========================================================================================
PRIVATE SUB CTooltip.DeleteTooltip (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND)
   IF hTooltip = NULL OR hwnd = NULL THEN EXIT SUB
   ' // 32-bit: The size of the TOOLINFOW structure is 48 bytes in
   '    version 6 of comctl32.dll, and 44 bytes in lower versions.
   ' // 64-bit: The size of the TOOLINFOW structure is 72 bytes in
   '    version 6 of comctl32.dll, and 64 bytes in lower versions.
   DIM tti AS TOOLINFOW
#ifdef __FB_64BIT__
   IF CTooltip.ComCtlVersion < 600 THEN tti.cbSize = 64 ELSE tti.cbSize = 72
#else
   IF CTooltip.ComCtlVersion < 600 THEN tti.cbSize = 44 ELSE tti.cbSize = 48
#endif
   IF (GetWindowLongPtrW(hwnd, GWL_STYLE) AND WS_CHILD) = WS_CHILD THEN
      tti.hwnd = GetParent(hwnd)
      tti.uId = CAST(UINT_PTR, hwnd)
   ELSE
      tti.hwnd = hwnd
      tti.uId = 0
   END IF
   ' // Remove the tooltip
   SendMessageW(hTooltip, TTM_DELTOOL, 0, CAST(LPARAM, @tti))
END SUB
' ========================================================================================

' ========================================================================================
' Allows a subclass procedure to cause a tooltip to display text for a window other than
' the one beneath the mouse cursor.
' Note: Thete is not an overload with BYVAL pt AS POINT because it conflcts with the
' Windows API version of the same name.
' ========================================================================================
PRIVATE FUNCTION WindowFromPoint (BYVAL hTooltip AS HWND, BYVAL lppt AS POINT PTR) AS HWND
   RETURN WindowFromPoint(hTooltip, lppt)
END FUNCTION
' ========================================================================================

END NAMESPACE
