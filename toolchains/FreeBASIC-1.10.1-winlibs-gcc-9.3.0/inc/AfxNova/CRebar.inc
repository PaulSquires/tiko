' ########################################################################################
' Platform: Microsoft Windows
' Filename: CRebar.inc
' Purpose:  Windows common controls - Rebar control
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
' CRebar class
' ########################################################################################

TYPE CRebar

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION ComCtlVersion () AS LONG
   DECLARE STATIC SUB BeginDrag (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL dwPos AS DWORD)
   DECLARE STATIC FUNCTION DeleteBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS BOOLEAN
   DECLARE STATIC SUB DragMove (BYVAL hRebar AS HWND, BYVAL dwPos AS DWORD)
   DECLARE STATIC SUB EndDrag (BYVAL hRebar AS HWND)
   DECLARE STATIC SUB GetBandBorders (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB GetBandBorders (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION GetBandBorders (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS RECT
   DECLARE STATIC FUNCTION GetBandCount (BYVAL hRebar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prbbi AS REBARBANDINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rbbi AS REBARBANDINFOW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS REBARBANDINFOW
   DECLARE STATIC SUB GetBandMargins (BYVAL hRebar AS HWND, BYVAL pMargins AS MARGINS PTR)
   DECLARE STATIC SUB GetBandMargins (BYVAL hRebar AS HWND, BYREF _margins AS MARGINS)
   DECLARE STATIC FUNCTION GetBandMargins (BYVAL hRebar AS HWND) AS MARGINS
   DECLARE STATIC FUNCTION GetBarHeight (BYVAL hRebar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetBarInfo (BYVAL hRebar AS HWND, BYVAL prbi AS REBARINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBarInfo (BYVAL hRebar AS HWND, BYREF rbi AS REBARINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBarInfo (BYVAL hRebar AS HWND) AS REBARINFO
   DECLARE STATIC FUNCTION GetBkColor (BYVAL hRebar AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetColorScheme (BYVAL hRebar AS HWND, BYVAL pcs AS COLORSCHEME PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColorScheme (BYVAL hRebar AS HWND, BYREF cs AS COLORSCHEME) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColorScheme (BYVAL hRebar AS HWND) AS COLORSCHEME
   DECLARE STATIC FUNCTION GetDropTarget (BYVAL hRebar AS HWND) AS IDropTarget PTR
   DECLARE STATIC FUNCTION GetPalette (BYVAL hRebar AS HWND) AS HPALETTE
   DECLARE STATIC FUNCTION GetRect (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetRect (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetRect (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS RECT
   DECLARE STATIC FUNCTION GetRowCount (BYVAL hRebar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetRowHeight (BYVAL hRebar AS HWND, BYVAL uRow AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION GetTextColor (BYVAL hRebar AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetTooltips (BYVAL hRebar AS HWND) AS HWND
   DECLARE STATIC FUNCTION HitTest (BYVAL hRebar AS HWND, BYREF rhbt AS RBHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION IdToIndex (BYVAL hRebar AS HWND, BYVAL uBandID AS DWORD) AS LONG
   DECLARE STATIC FUNCTION InsertBand (BYVAL hRebar AS HWND, BYVAL nIndex AS LONG, BYVAL prbbi AS REBARBANDINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertBand (BYVAL hRebar AS HWND, BYVAL nIndex AS LONG, BYREF rbbi AS REBARBANDINFOW) AS BOOLEAN
   DECLARE STATIC SUB MaximizeBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL fIdeal AS BOOLEAN)
   DECLARE STATIC SUB MinimizeBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD)
   DECLARE STATIC FUNCTION MoveBand (BYVAL hRebar AS HWND, BYVAL nFrom AS DWORD, BYVAL nTo AS DWORD) AS BOOLEAN
   DECLARE STATIC SUB PushChevron (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL iAppValue AS DWORD)
   DECLARE STATIC FUNCTION SetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prbbi AS REBARBANDINFOW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rbbi AS REBARBANDINFOW) AS BOOLEAN
   #if _WIN32_WINNT = &h0602
   DECLARE STATIC FUNCTION SetBandWidth (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL nWidth AS DWORD) AS BOOLEAN
   #endif
   DECLARE STATIC FUNCTION SetBarInfo (BYVAL hRebar AS HWND, BYVAL prbi AS REBARINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBarInfo (BYVAL hRebar AS HWND, BYREF rbi AS REBARINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBkColor (BYVAL hRebar AS HWND, BYVAL clrBk AS COLORREF) AS COLORREF
   DECLARE STATIC SUB SetColorScheme (BYVAL hRebar AS HWND, BYVAL pcs AS COLORSCHEME PTR)
   DECLARE STATIC SUB SetColorScheme (BYVAL hRebar AS HWND, BYREF cs AS COLORSCHEME)
   DECLARE STATIC FUNCTION SetPalette (BYVAL hRebar AS HWND, BYVAL hPal AS HPALETTE) AS HPALETTE
   DECLARE STATIC FUNCTION SetParent (BYVAL hRebar AS HWND, BYVAL hwndParent AS hWND) AS HWND
   DECLARE STATIC FUNCTION SetTextColor (BYVAL hRebar AS HWND, BYVAL clrText AS COLORREF) AS COLORREF
   DECLARE STATIC SUB SetTooltips (BYVAL hRebar AS HWND, BYVAL hwndToolTip AS HWND)
   DECLARE STATIC SUB SetWindowTheme (BYVAL hRebar AS HWND, BYVAL pwszTheme AS WSTRING PTR)
   DECLARE STATIC FUNCTION ShowBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL fShow AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION SizeToRect (BYVAL hRebar AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SizeToRect (BYVAL hRebar AS HWND, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION SizeToRect (BYVAL hRebar AS HWND) AS RECT
   DECLARE STATIC FUNCTION SetDarkMode(BYVAL hRebar AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode(BYVAL hRebar AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CRebar
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CRebar
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Returns the version of ComCtrl.dll version multiplied by 100, e.g. 601 for version 6.01.
' Example: DIM ver AS LONG = AfxGetFileVersion("COMCTL32.DLL")
' ========================================================================================
PRIVATE FUNCTION CRebar.ComCtlVersion () AS LONG
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
' Puts the rebar control in drag-and-drop mode.
' ========================================================================================
PRIVATE SUB CRebar.BeginDrag (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL dwPos AS DWORD)
   SendMessageW(hRebar, RB_BEGINDRAG, uBand, dwPos)
END SUB
' ========================================================================================

' ========================================================================================
' * Deletes a band from a rebar control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.DeleteBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_DELETEBAND, uBand, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Updates the drag position in the rebar control after a previous RB_BEGINDRAG message.
' ========================================================================================
PRIVATE SUB CRebar.DragMove (BYVAL hRebar AS HWND, BYVAL dwPos AS DWORD)
   SendMessageW(hRebar, RB_DRAGMOVE, 0, dwPos)
END SUB
' ========================================================================================

' ========================================================================================
' Terminates the rebar control's drag-and-drop operation. This message does not cause an
' RBN_ENDDRAG notification to be sent.
' ========================================================================================
PRIVATE SUB CRebar.EndDrag (BYVAL hRebar AS HWND)
   SendMessageW(hRebar, RB_ENDDRAG, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the borders of a band. The result of this message can be used to calculate the
' usable area in a band.
' ========================================================================================
PRIVATE SUB CRebar.GetBandBorders (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prc AS RECT PTR)
   SendMessageW(hRebar, RB_GETBANDBORDERS, uBand, cast(LPARAM, prc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CRebar.GetBandBorders (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rc AS RECT)
   SendMessageW(hRebar, RB_GETBANDBORDERS, uBand, cast(LPARAM, @rc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBandBorders (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS RECT
   DIM rc AS RECT
   SendMessageW(hRebar, RB_GETBANDBORDERS, uBand, cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the count of bands currently in the rebar control.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBandCount (BYVAL hRebar AS HWND) AS DWORD
   RETURN SendMessageW(hRebar, RB_GETBANDCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about a specified band in a rebar control.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prbbi AS REBARBANDINFOW PTR) AS BOOLEAN
   IF prbbi = NULL THEN RETURN FALSE
   IF CRebar.ComCtlVersion >= 600 THEN
      prbbi->cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      prbbi->cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   RETURN SendMessageW(hRebar, RB_GETBANDINFO, uBand, cast(LPARAM, prbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rbbi AS REBARBANDINFOW) AS BOOLEAN
   IF VARPTR(rbbi) = 0 THEN RETURN FALSE
   IF CRebar.ComCtlVersion >= 600 THEN
      rbbi.cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      rbbi.cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   RETURN SendMessageW(hRebar, RB_GETBANDINFO, uBand, cast(LPARAM, @rbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS REBARBANDINFOW
   DIM rbbi AS REBARBANDINFOW
   IF CRebar.ComCtlVersion >= 600 THEN
      rbbi.cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      rbbi.cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   SendMessageW(hRebar, RB_GETBANDINFO, uBand, cast(LPARAM, @rbbi))
   RETURN rbbi
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the margins of a band.
' ========================================================================================
PRIVATE SUB CRebar.GetBandMargins (BYVAL hRebar AS HWND, BYVAL pMargins AS MARGINS PTR)
   SendMessageW(hRebar, RB_GETBANDMARGINS, 0, cast(LPARAM, pMargins))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CRebar.GetBandMargins (BYVAL hRebar AS HWND, BYREF _margins AS MARGINS)
   SendMessageW(hRebar, RB_GETBANDMARGINS, 0, cast(LPARAM, @_margins))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBandMargins (BYVAL hRebar AS HWND) AS MARGINS
   DIM _margins AS MARGINS
   SendMessageW(hRebar, RB_GETBANDMARGINS, 0, cast(LPARAM, @_margins))
   RETURN _margins
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the height of the rebar control.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBarHeight (BYVAL hRebar AS HWND) AS DWORD
   RETURN SendMessageW(hRebar, RB_GETBARHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the rebar control and the image list it uses.
' Return value: Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBarInfo (BYVAL hRebar AS HWND, BYVAL prbi AS REBARINFO PTR) AS BOOLEAN
   IF prbi = NULL THEN RETURN FALSE
   prbi->cbSize = SIZEOF(REBARINFO)
   RETURN SendMessageW(hRebar, RB_GETBARINFO, 0, cast(LPARAM, prbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBarInfo (BYVAL hRebar AS HWND, BYREF rbi AS REBARINFO) AS BOOLEAN
   IF VARPTR(rbi) = 0 THEN RETURN FALSE
   rbi.cbSize = SIZEOF(rbi)
   RETURN SendMessageW(hRebar, RB_GETBARINFO, 0, cast(LPARAM, @rbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBarInfo (BYVAL hRebar AS HWND) AS REBARINFO
   DIM rbi AS REBARINFO
   rbi.cbSize = SIZEOF(REBARINFO)
   SendMessageW(hRebar, RB_GETBARINFO, 0, cast(LPARAM, @rbi))
   RETURN rbi
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a rebar control's default background color.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetBkColor (BYVAL hRebar AS HWND) AS COLORREF
   RETURN SendMessageW(hRebar, RB_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color scheme information from the rebar control.
' Return value: Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetColorScheme (BYVAL hRebar AS HWND, BYVAL pcs AS COLORSCHEME PTR) AS BOOLEAN
   IF pcs = NULL THEN RETURN FALSE
   pcs->dwSize = SIZEOF(COLORSCHEME)
   RETURN SendMessageW(hRebar, RB_GETCOLORSCHEME, 0, CAST(LPARAM, pcs))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetColorScheme (BYVAL hRebar AS HWND, BYREF cs AS COLORSCHEME) AS BOOLEAN
   IF VARPTR(cs) THEN RETURN FALSE
   cs.dwSize = SIZEOF(cs)
   RETURN SendMessageW(hRebar, RB_GETCOLORSCHEME, 0, CAST(LPARAM, @cs))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetColorScheme (BYVAL hRebar AS HWND) AS COLORSCHEME
   DIM cs AS COLORSCHEME
   cs.dwSize = SIZEOF(cs)
   SendMessageW(hRebar, RB_GETCOLORSCHEME, 0, CAST(LPARaM, @cs))
   RETURN cs
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a rebar control's IDropTarget interface pointer.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetDropTarget (BYVAL hRebar AS HWND) AS IDropTarget PTR
   DIM ppIDropTarget AS IDropTarget PTR
   SendMessageW(hRebar, RB_GETDROPTARGET, 0, CAST(LPARAM, @ppIDropTarget))
   RETURN ppIDropTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the rebar control's current palette.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetPalette (BYVAL hRebar AS HWND) AS HPALETTE
   RETURN cast(HPALETTE, SendMessageW(hRebar, RB_GETPALETTE, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle for a given band in a rebar control.
' Return value: Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetRect (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_GETRECT, uBand, cast(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetRect (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_GETRECT, uBand, cast(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.GetRect (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD) AS RECT
   DIM rc AS RECT
   SendMessageW(hRebar, RB_GETRECT, uBand, cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of rows of bands in a rebar control.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetRowCount (BYVAL hRebar AS HWND) AS DWORD
   RETURN SendMessageW(hRebar, RB_GETROWCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the height of a specified row in a rebar control.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetRowHeight (BYVAL hRebar AS HWND, BYVAL uRow AS DWORD) AS DWORD
   RETURN SendMessageW(hRebar, RB_GETROWHEIGHT, uRow, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a rebar control's default text color.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetTextColor (BYVAL hRebar AS HWND) AS COLORREF
   RETURN SendMessageW(hRebar, RB_GETTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to any ToolTip control associated with the rebar control.
' ========================================================================================
PRIVATE FUNCTION CRebar.GetTooltips (BYVAL hRebar AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hRebar, RB_GETTOOLTIPS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which portion of a rebar band is at a given point on the screen, if a rebar
' band exists at that point.
' - hRebar: Pointer to the rebar control.
' - lprhbt: Pointer to an RBHITTESTINFO structure. Before sending the message, the pt member
'   of this structure must be initialized to the point that will be hit tested, in client coordinates.
' Returns the zero-based index of the band at the given point, or -1 if no rebar band was at the point.
' ========================================================================================
PRIVATE FUNCTION CRebar.HitTest (BYVAL hRebar AS HWND, BYREF rhbt AS RBHITTESTINFO) AS LONG
   IF VARPTR(rhbt) = 0 THEN RETURN -1
   RETURN SendMessageW(hRebar, RB_HITTEST, 0, cast(LPARAM, @rhbt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a band identifier to a band index in a rebar control.
' Returns the zero-based band index if successful, or -1 otherwise. If duplicate band
' identifiers exist, the first one is returned.
' ========================================================================================
PRIVATE FUNCTION CRebar.IdToIndex (BYVAL hRebar AS HWND, BYVAL uBandID AS DWORD) AS LONG
   RETURN SendMessageW(hRebar, RB_IDTOINDEX, uBandID, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Inserts a new band in a rebar control.
' ========================================================================================
PRIVATE FUNCTION CRebar.InsertBand (BYVAL hRebar AS HWND, BYVAL nIndex AS LONG, BYVAL prbbi AS REBARBANDINFOW PTR) AS BOOLEAN
   IF prbbi = NULL THEN RETURN FALSE
   IF CRebar.ComCtlVersion >= 600 THEN
      prbbi->cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      prbbi->cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   RETURN SendMessageW(hRebar, RB_INSERTBAND, nIndex, cast(LPARAM, prbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.InsertBand (BYVAL hRebar AS HWND, BYVAL nIndex AS LONG, BYREF rbbi AS REBARBANDINFOW) AS BOOLEAN
   IF VARPTR(rbbi) = 0 THEN RETURN FALSE
   IF CRebar.ComCtlVersion >= 600 THEN
      rbbi.cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      rbbi.cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   RETURN SendMessageW(hRebar, RB_INSERTBAND, nIndex, cast(LPARAM, @rbbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resizes a band in a rebar control to either its ideal or largest size.
' ========================================================================================
PRIVATE SUB CRebar.MaximizeBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL fIdeal AS BOOLEAN)
   SendMessageW(hRebar, RB_MAXIMIZEBAND, uBand, fIdeal)
END SUB
' ========================================================================================

' ========================================================================================
' Resizes a band in a rebar control to its smallest size.
' ========================================================================================
PRIVATE SUB CRebar.MinimizeBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD)
  SendMessageW(hRebar, RB_MINIMIZEBAND, cast(WPARAM, uBand), 0)
END SUB
' ========================================================================================

' ========================================================================================
' Moves a band from one index to another. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.MoveBand (BYVAL hRebar AS HWND, BYVAL nFrom AS DWORD, BYVAL nTo AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_MOVEBAND, nFrom, nTo)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sent to a rebar control to programmatically push a chevron.
' ========================================================================================
PRIVATE SUB CRebar.PushChevron (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL iAppValue AS DWORD)
   SendMessageW(hRebar, RB_PUSHCHEVRON, uBand, iAppValue)
END SUB
' ========================================================================================

' ========================================================================================
' Sets characteristics of an existing band in a rebar control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL prbbi AS REBARBANDINFOW PTR) AS BOOLEAN
   IF prbbi = NULL THEN RETURN FALSE
   IF CRebar.ComCtlVersion >= 600 THEN
      prbbi->cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      prbbi->cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   RETURN SendMessageW(hRebar, RB_SETBANDINFO, uBand, cast(LPARAM, prbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.SetBandInfo (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYREF rbbi AS REBARBANDINFOW) AS BOOLEAN
   IF CRebar.ComCtlVersion >= 600 THEN
      rbbi.cbSize  = REBARBANDINFO_V6_SIZE
   ELSE
      rbbi.cbSize  = REBARBANDINFO_V3_SIZE
   END IF
   RETURN SendMessageW(hRebar, RB_SETBANDINFO, uBand, cast(LPARAM, @rbbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the characteristics of a rebar control. Returns TRUE or FALSE.
' ========================================================================================
#if _WIN32_WINNT = &h0602
PRIVATE FUNCTION CRebar.SetBandWidth (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL nWidth AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_SETBANDWIDTH, uBand, nWidth)
END FUNCTION
#endif
' ========================================================================================

' ========================================================================================
' Sets the characteristics of a rebar control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetBarInfo (BYVAL hRebar AS HWND, BYVAL prbi AS REBARINFO PTR) AS BOOLEAN
   IF prbi = NULL THEN RETURN FALSE
   prbi->cbSize = SIZEOF(REBARINFO)
   RETURN SendMessageW(hRebar, RB_SETBARINFO, 0, cast(LPARAM, prbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.SetBarInfo (BYVAL hRebar AS HWND, BYREF rbi AS REBARINFO) AS BOOLEAN
   IF VARPTR(rbi) = 0 THEN RETURN FALSE
   rbi.cbSize = SIZEOF(rbi)
   RETURN SendMessageW(hRebar, RB_SETBARINFO, 0, cast(LPARAM, @rbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a rebar control's default background color.
' Returns a COLORREF value that represents the previous default background color.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetBkColor (BYVAL hRebar AS HWND, BYVAL clrBk AS DWORD) AS DWORD
   RETURN SendMessageW(hRebar, RB_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color scheme information for the rebar control.
' ========================================================================================
PRIVATE SUB CRebar.SetColorScheme (BYVAL hRebar AS HWND, BYVAL pcs AS COLORSCHEME PTR)
   IF pcs = NULL THEN EXIT SUB
   pcs->dwSize = SIZEOF(COLORSCHEME)
   SendMessageW(hRebar, RB_SETCOLORSCHEME, 0, CAST(LPARAM, pcs))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CRebar.SetColorScheme (BYVAL hRebar AS HWND, BYREF cs AS COLORSCHEME)
   IF VARPTR(cs) THEN EXIT SUB
   cs.dwSize = SIZEOF(COLORSCHEME)
   SendMessageW(hRebar, RB_SETCOLORSCHEME, 0, CAST(LPARAM, @cs))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the rebar control's current palette.
' Returns an HPALETTE that specifies the rebar control's previous palette.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetPalette (BYVAL hRebar AS HWND, BYVAL hPal AS HPALETTE) AS HPALETTE
   RETURN cast(HPALETTE, SendMessageW(hRebar, RB_SETPALETTE, 0, cast(LPARAM, hPal)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a rebar control's parent window.
' Returns the handle to the previous parent window, or NULL if there is no previous parent.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetParent (BYVAL hRebar AS HWND, BYVAL hwndParent AS hWND) AS HWND
   RETURN cast(HWND, SendMessageW(hRebar, RB_SETPARENT, cast(WPARAM, hwndParent), 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a rebar control's default text color.
' Returns a COLORREF value that represents the previous default text color.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetTextColor (BYVAL hRebar AS HWND, BYVAL clrText AS COLORREF) AS COLORREF
   RETURN SendMessageW(hRebar, RB_SETTEXTCOLOR, 0, clrText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a tooltip control with the rebar control.
' ========================================================================================
PRIVATE SUB CRebar.SetTooltips (BYVAL hRebar AS HWND, BYVAL hwndToolTip AS HWND)
   SendMessageW(hRebar, RB_SETTOOLTIPS, cast(WPARAM, hwndToolTip), 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the visual style of a rebar control.
' ========================================================================================
PRIVATE SUB CRebar.SetWindowTheme (BYVAL hRebar AS HWND, BYVAL pwszTheme AS WSTRING PTR)
   SendMessageW(hRebar, RB_SETWINDOWTHEME, 0, cast(LPARAM, pwszTheme))
END SUB
' ========================================================================================

' ========================================================================================
' Shows or hides a given band in a rebar control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.ShowBand (BYVAL hRebar AS HWND, BYVAL uBand AS DWORD, BYVAL fShow AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_SHOWBAND, uBand, fShow)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Attempts to find the best layout of the bands for the given rectangle. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CRebar.SizeToRect (BYVAL hRebar AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_SIZETORECT, 0, cast(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.SizeToRect (BYVAL hRebar AS HWND, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hRebar, RB_SIZETORECT, 0, cast(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CRebar.SizeToRect (BYVAL hRebar AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hRebar, RB_SIZETORECT, 0, cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the rebar dark mode.
' ========================================================================================
PRIVATE FUNCTION CRebar.SetDarkMode(BYVAL hRebar AS HWND) AS HRESULT
   RETURN ..SetWindowTheme(hRebar, "DarkModeNavbar", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Removes the rebar dark mode.
' ========================================================================================
PRIVATE FUNCTION CRebar.RemoveDarkMode(BYVAL hRebar AS HWND) AS HRESULT
   RETURN ..SetWindowTheme(hRebar, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
