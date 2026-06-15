' ########################################################################################
' Platform: Microsoft Windows
' Filename: CMonthCal.inc
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

' ########################################################################################
' CMonthCal class
' ########################################################################################

TYPE CMonthCal

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION GetColor (BYVAL hMonthCal AS HWND, BYVAL iColor AS LONG) AS COLORREF
   DECLARE STATIC FUNCTION GetCurSel (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCurSel (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCurSel (BYVAL hMonthCal AS HWND) AS SYSTEMTIME
   DECLARE STATIC FUNCTION GetFirstDayOfWeek (BYVAL hMonthCal AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetMaxSelCount (BYVAL hMonthCal AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetMaxTodayWidth (BYVAL hMonthCal AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetMonthDelta (BYVAL hMonthCal AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetMonthRange (BYVAL hMonthCal AS HWND, BYVAL gmr AS DWORD, BYVaL rgst AS SYSTEMTIME PTR) AS LONG
   DECLARE STATIC FUNCTION GetRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
   DECLARE STATIC FUNCTION GetSelRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS LONG
   DECLARE STATIC FUNCTION GetToday (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetToday (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS BOOLEAN
   DECLARE STATIC FUNCTION GetToday (BYVAL hMonthCal AS HWND) AS SYSTEMTIME
   DECLARE STATIC FUNCTION HitTest (BYVAL hMonthCal AS HWND, BYVAL pinfo AS MCHITTESTINFO PTR) AS DWORD
   DECLARE STATIC FUNCTION HitTest (BYVAL hMonthCal AS HWND, BYREF info AS MCHITTESTINFO) AS DWORD
   DECLARE STATIC FUNCTION SetColor (BYVAL hMonthCal AS HWND, BYVAL iColor AS LONG, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION SetCurSel (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS LONG
   DECLARE STATIC FUNCTION SetCurSel (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS LONG
   DECLARE STATIC FUNCTION SetDayState (BYVAL hMonthCal AS HWND, BYVAL cbds AS LONG, BYVAL rgds AS MONTHDAYSTATE PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetFirstDayOfWeek (BYVAL hMonthCal AS HWND, BYVAL iDay AS LONG) AS DWORD
   DECLARE STATIC FUNCTION SetMaxSelCount (BYVAL hMonthCal AS HWND, BYVAL iMax AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION SetMonthDelta (BYVAL hMonthCal AS HWND, BYVAL iDelta AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetRange (BYVAL hMonthCal AS HWND, BYVAL fWhichLimit AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetSelRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS BOOLEAN
   DECLARE STATIC SUB SetToday (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR)
   DECLARE STATIC SUB SetToday (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME)

#if _WIN32_WINNT >= &h0600
   DECLARE STATIC FUNCTION GetCalendarGridInfo (BYVAL hMonthCal AS HWND, BYVAL pInfo AS MCGRIDINFO PTR) AS BOOLEan
   DECLARE STATIC FUNCTION GetCalendarGridInfo (BYVAL hMonthCal AS HWND, BYREF info AS MCGRIDINFO) AS BOOLEan
   DECLARE STATIC FUNCTION GetCalendarBorder (BYVAL hMonthCal AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetCalendarCount (BYVAL hMonthCal AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetCALID (BYVAL hMonthCal AS HWND) AS CALID
   DECLARE STATIC FUNCTION GetCurrentView (BYVAL hMonthCal AS HWND) AS DWORD
   DECLARE STATIC SUB SetCalendarBorder (BYVAL hMonthCal AS HWND, BYVAL fset AS BOOLEAN, BYVAL xyborder AS LONG)
   DECLARE STATIC SUB SetCALID (BYVAL hMonthCal AS HWND, BYVAL calid AS UINT)
   DECLARE STATIC FUNCTION SetCurrentView (BYVAL hMonthCal AS HWND, BYVAL dwNewView AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION GetMinReqRect (BYVAL hMonthCal AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetMinReqRect (BYVAL hMonthCal AS HWND, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION SizeRectToMin (BYVAL hMonthCal AS HWND, BYVAL prc AS RECT PTR) AS LONG
   DECLARE STATIC FUNCTION SizeRectToMin (BYVAL hMonthCal AS HWND, BYREF rc AS RECT) AS LONG
#endif

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CMonthCal
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CMonthCal
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Retrieves the color for a given portion of a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetColor (BYVAL hMonthCal AS HWND, BYVAL iColor AS LONG) AS COLORREF
   RETURN SendMessageW(hMonthCal, MCM_GETCOLOR, iColor, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the currently selected date.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCurSel (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_GETCURSEL, 0, CAST(LPARaM, pst))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCurSel (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_GETCURSEL, 0, CAST(LPARaM, @st))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCurSel (BYVAL hMonthCal AS HWND) AS SYSTEMTIME
   DIM st AS SYSTEMTIME
   SendMessageW(hMonthCal, MCM_GETCURSEL, 0, CAST(LPARaM, @st))
   RETURN st
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the first day of the week for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetFirstDayOfWeek (BYVAL hMonthCal AS HWND) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETFIRSTDAYOFWEEK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum date range that can be selected in a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetMaxSelCount (BYVAL hMonthCal AS HWND) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETMAXSELCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum width of the "today" string in a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetMaxTodayWidth (BYVAL hMonthCal AS HWND) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETMAXTODAYWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the scroll rate for a month calendar control. The scroll rate is the number of
' months that the control moves its display when the user clicks a scroll button.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetMonthDelta (BYVAL hMonthCal AS HWND) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_GETMONTHDELTA, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves date information (using SYSTEMTIME structures) that represents the high and
' low limits of a month calendar control's display.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetMonthRange (BYVAL hMonthCal AS HWND, BYVAL gmr AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_GETMONTHRANGE, gmr, CAST(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the minimum and maximum allowable dates set for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETRANGE, 0, CAST(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves date information that represents the upper and lower limits of the date range
' currently selected by the user.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetSelRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_GETSELRANGE, 0, CAST(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the date information for the date specified as "today" for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetToday (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_GETTODAY, 0, CAST(LPARAM, pst))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetToday (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS BOOLEAN
   IF VARPTR(st) = 0 THEN RETURN FALSE
   RETURN SendMessageW(hMonthCal, MCM_GETTODAY, 0, CAST(LPARAM, @st))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetToday (BYVAL hMonthCal AS HWND) AS SYSTEMTIME
   DIM st AS SYSTEMTIME
   SendMessageW(hMonthCal, MCM_GETTODAY, 0, CAST(LPARAM, @st))
   RETURN st
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which portion of a month calendar control is at a given point on the screen.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.HitTest (BYVAL hMonthCal AS HWND, BYVAL pinfo AS MCHITTESTINFO PTR) AS DWORD
   IF pInfo THEN pinfo->cbSize = SIZEOF(MCHITTESTINFO)
   RETURN SendMessageW(hMonthCal, MCM_HITTEST, 0, CAST(LPARAM, pinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.HitTest (BYVAL hMonthCal AS HWND, BYREF info AS MCHITTESTINFO) AS DWORD
   IF VARPTR(info) <> 0 THEN info.cbSize = SIZEOF(MCHITTESTINFO)
   RETURN SendMessageW(hMonthCal, MCM_HITTEST, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color for a given portion of a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetColor (BYVAL hMonthCal AS HWND, BYVAL iColor AS LONG, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hMonthCal, MCM_SETCOLOR, iColor, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the currently selected date for a month calendar control. If the specified date is
' not in view, the control updates the display to bring it into view.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetCurSel (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_SETCURSEL, 0, CAST(LPARAM, pst))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetCurSel (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_SETCURSEL, 0, CAST(LPARAM, @st))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the day states for all months that are currently visible within a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetDayState (BYVAL hMonthCal AS HWND, BYVAL cbds AS LONG, BYVAL rgds AS MONTHDAYSTATE PTR) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_SETDAYSTATE, cbds, CAST(LPARAM, rgds))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the first day of the week for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetFirstDayOfWeek (BYVAL hMonthCal AS HWND, BYVAL iDay AS LONG) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_SETFIRSTDAYOFWEEK, 0, iDay)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum number of days that can be selected in a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetMaxSelCount (BYVAL hMonthCal AS HWND, BYVAL iMax AS UINT) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_SETMAXSELCOUNT, iMax, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the scroll rate for a month calendar control. The scroll rate is the number of
' months that the control moves its display when the user clicks a scroll button.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetMonthDelta (BYVAL hMonthCal AS HWND, BYVAL iDelta AS LONG) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_SETMONTHDELTA, iDelta, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum allowable dates for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetRange (BYVAL hMonthCal AS HWND, BYVAL fWhichLimit AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_SETRANGE, fWhichLimit, CAST(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the selection for a month calendar control to a given date range.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetSelRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_SETSELRANGE, 0, CAST(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the "today" selection for a month calendar control.
' ========================================================================================
PRIVATE SUB CMonthCal.SetToday (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR)
   SendMessage hMonthCal, MCM_SETTODAY, 0, CAST(LPARAM, pst)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CMonthCal.SetToday (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME)
   SendMessage hMonthCal, MCM_SETTODAY, 0, CAST(LPARAM, @st)
END SUB
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Gets information about a calendar grid.
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCalendarGridInfo (BYVAL hMonthCal AS HWND, BYVAL pInfo AS MCGRIDINFO PTR) AS BOOLEAN
   IF pInfo THEN pInfo->cbSize = SIZEOF(MCGRIDINFO)
   RETURN SendMessageW(hMonthCal, MCM_GETCALENDARGRIDINFO, 0, CAST(LPARAM, pInfo))
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCalendarGridInfo (BYVAL hMonthCal AS HWND, BYREF info AS MCGRIDINFO) AS BOOLEAN
   IF VARPTR(info) <> 0 THEN info.cbSize = SIZEOF(MCGRIDINFO)
   RETURN SendMessageW(hMonthCal, MCM_GETCALENDARGRIDINFO, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the border size, in pixels, of a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCalendarBorder (BYVAL hMonthCal AS HWND) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETCALENDARBORDER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of calendars currently displayed in the calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCalendarCount (BYVAL hMonthCal AS HWND) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETCALENDARCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current calendar ID for the given calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCALID (BYVAL hMonthCal AS HWND) AS CALID
   RETURN SendMessageW(hMonthCal, MCM_GETCALID, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the view for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetCurrentView (BYVAL hMonthCal AS HWND) AS DWORD
   RETURN SendMessageW(hMonthCal, MCM_GETCURRENTVIEW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the border size, in pixels, of a month calendar control.
' ========================================================================================
PRIVATE SUB CMonthCal.SetCalendarBorder (BYVAL hMonthCal AS HWND, BYVAL fset AS BOOLEAN, BYVAL xyborder AS LONG)
   SendMessageW(hMonthCal, MCM_SETCALENDARBORDER, fset, xyborder)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the calendar ID for the given calendar control.
' ========================================================================================
PRIVATE SUB CMonthCal.SetCALID (BYVAL hMonthCal AS HWND, BYVAL calid AS UINT)
   SendMessageW(hMonthCal, MCM_SETCALID, calid, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the view for a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.SetCurrentView (BYVAL hMonthCal AS HWND, BYVAL dwNewView AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_SETCURRENTVIEW, 0, dwNewView)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the minimum size required to display a full month in a month calendar control.
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetMinReqRect (BYVAL hMonthCal AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_GETMINREQRECT, 0, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMonthCal.GetMinReqRect (BYVAL hMonthCal AS HWND, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hMonthCal, MCM_GETMINREQRECT, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates how many calendars will fit in the given rectangle, and then returns the
' minimum size that a rectangle needs to be to fit that number of calendars.
' ========================================================================================
FUNCTION CMonthCal.SizeRectToMin (BYVAL hMonthCal AS HWND, BYVAL prc AS RECT PTR) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_SIZERECTTOMIN, 0, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION CMonthCal.SizeRectToMin (BYVAL hMonthCal AS HWND, BYREF rc AS RECT) AS LONG
   RETURN SendMessageW(hMonthCal, MCM_SIZERECTTOMIN, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================

#endif

END NAMESPACE
