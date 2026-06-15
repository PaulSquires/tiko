' ########################################################################################
' Platform: Microsoft Windows
' Filename: CDtPicker.inc
' Purpose:  Windows common controls - Datetime picker
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
USING AfxNova

NAMESPACE AfxNova


' ########################################################################################
'                                    *** DateTime Picker ***
' ########################################################################################
TYPE CDtPicker

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION GetSystemtime (BYVAL hDtp AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS DWORD
   DECLARE STATIC FUNCTION GetSystemtime (BYVAL hDtp AS HWND, BYREF st AS SYSTEMTIME) AS DWORD
   DECLARE STATIC FUNCTION GetSystemtime (BYVAL hDtp AS HWND) AS SYSTEMTIME
   DECLARE STATIC FUNCTION SetSystemtime (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYVAL pst AS SYSTEMTIME PTR) AS DWORD
   DECLARE STATIC FUNCTION SetSystemtime (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYREF st AS SYSTEMTIME) AS DWORD
   DECLARE STATIC FUNCTION GetRange (BYVAL hDtp AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
   DECLARE STATIC FUNCTION SetRange (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
   DECLARE STATIC SUB SetFormat (BYVAL hDtp AS HWND, BYVAL pwsz AS WSTRING PTR)
   DECLARE STATIC FUNCTION SetMonthCalColor (BYVAL hDtp AS HWND, BYVAL iColor AS LONG, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION GetMonthCalColor (BYVAL hDtp AS HWND, BYVAL iColor AS LONG) AS COLORREF
   DECLARE STATIC FUNCTION GetMonthCal (BYVAL hDtp AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetMonthCalFont (BYVAL hDtp AS HWND) AS HFONT
   DECLARE STATIC SUB SetMonthCalFont (BYVAL hDtp AS HWND, BYVAL hfont AS HFONT, BYVAL fRedraw AS BOOLEAN)
#if _WIN32_WINNT >= &h0600
   DECLARE STATIC FUNCTION SetMonthCalStyle (BYVAL hDtp AS HWND, BYVAL dwStyle AS DWORD) AS LRESULT
   DECLARE STATIC FUNCTION GetMonthCalStyle (BYVAL hDtp AS HWND) AS LRESULT
   DECLARE STATIC SUB CloseMonthCal (BYVAL hDtp AS HWND)
   DECLARE STATIC SUB GetDateTimePickerInfo (BYVAL hDtp AS HWND, BYVAL pdtpi AS DATETIMEPICKERINFO PTR)
   DECLARE STATIC SUB GetDateTimePickerInfo (BYVAL hDtp AS HWND, BYREF dtpi AS DATETIMEPICKERINFO)
   DECLARE STATIC FUNCTION GetDateTimePickerInfo (BYVAL hDtp AS HWND) AS DATETIMEPICKERINFO
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hDtp AS HWND, BYVAL psize AS SIZE PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hDtp AS HWND, BYREF sz AS SIZE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hDtp AS HWND) AS SIZE
#endif

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CDtPicker
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CDtPicker
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Gets the currently selected time from a date and time picker (DTP) control and places it
' in a specified SYSTEMTIME structure.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetSystemtime (BYVAL hDtp AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS DWORD
   RETURN SendMessageW(hDtp, DTM_GETSYSTEMTIME, 0, cast(LPARAM, pst))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetSystemtime (BYVAL hDtp AS HWND, BYREF st AS SYSTEMTIME) AS DWORD
   RETURN SendMessageW(hDtp, DTM_GETSYSTEMTIME, 0, cast(LPARAM, @st))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetSystemtime (BYVAL hDtp AS HWND) AS SYSTEMTIME
   DIM st AS SYSTEMTIME
   SendMessageW(hDtp, DTM_GETSYSTEMTIME, 0, cast(LPARAM, @st))
   RETURN st
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a date and time picker (DTP) control to a given date and time.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.SetSystemtime (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYVAL pst AS SYSTEMTIME PTR) AS DWORD
   RETURN SendMessageW(hDtp, DTM_SETSYSTEMTIME, gd, cast(LPARAM, pst))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDtPicker.SetSystemtime (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYREF st AS SYSTEMTIME) AS DWORD
   RETURN SendMessageW(hDtp, DTM_SETSYSTEMTIME, gd, cast(LPARAM, @st))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current minimum and maximum allowable system times for a date and time picker (DTP)
' control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetRange (BYVAL hDtp AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
   RETURN SendMessageW(hDtp, DTM_GETRANGE, 0, cast(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum allowable system times for a date and time picker (DTP) control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.SetRange (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
   RETURN SendMessageW(hDtp, DTM_SETRANGE, gd, cast(LPARAM, rgst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the display of a date and time picker (DTP) control based on a given format string.
' ========================================================================================
PRIVATE SUB CDtPicker.SetFormat (BYVAL hDtp AS HWND, BYVAL pwsz AS WSTRING PTR)
   SendMessageW(hDtp, DTM_SETFORMATW, 0, cast(LPARAM, pwsz))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the color for a given portion of the month calendar within a date and time picker (DTP)
' control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.SetMonthCalColor (BYVAL hDtp AS HWND, BYVAL iColor AS LONG, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hDtp, DTM_SETMCCOLOR, iColor, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color for a given portion of the month calendar within a date and time picker (DTP)
' control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetMonthCalColor (BYVAL hDtp AS HWND, BYVAL iColor AS LONG) AS COLORREF
   RETURN SendMessageW(hDtp, DTM_GETMCCOLOR, iColor, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to a date and time picker's (DTP) child month calendar control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetMonthCal (BYVAL hDtp AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hDtp, DTM_GETMONTHCAL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the font that the date and time picker (DTP) control's child month calendar control
' is currently using.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetMonthCalFont (BYVAL hDtp AS HWND) AS HFONT
   RETURN cast(HFONT, SendMessageW(hDtp, DTM_GETMCFONT, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font to be used by the date and time picker (DTP) control's child month calendar
' control.
' ========================================================================================
PRIVATE SUB CDtPicker.SetMonthCalFont (BYVAL hDtp AS HWND, BYVAL hfont AS HFONT, BYVAL fRedraw AS BOOLEAN)
   SendMessageW(hDtp, DTM_SETMCFONT, cast(WPARAM, hfont), cast(LPARAM, fRedraw))
END SUB
' ========================================================================================

#if _WIN32_WINNT >= &h0600

' ========================================================================================
' Sets the style for a specified date and time picker (DTP) control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.SetMonthCalStyle (BYVAL hDtp AS HWND, BYVAL dwStyle AS DWORD) AS LRESULT
   RETURN SendMessageW(hDtp, DTM_SETMCSTYLE, 0, cast(LPARAM, dwStyle))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the style of a specified date and time picker (DTP) control.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetMonthCalStyle (BYVAL hDtp AS HWND) AS LRESULT
   RETURN SendMessageW(hDtp, DTM_GETMCSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Closes the date and time picker (DTP) control.
' ========================================================================================
PRIVATE SUB CDtPicker.CloseMonthCal (BYVAL hDtp AS HWND)
   SendMessageW(hDtp, DTM_CLOSEMONTHCAL, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Gets information for a specified date and time picker (DTP) control.
' ========================================================================================
PRIVATE SUB CDtPicker.GetDateTimePickerInfo (BYVAL hDtp AS HWND, BYVAL pdtpi AS DATETIMEPICKERINFO PTR)
   IF pdtpi = NULL THEN EXIT SUB
   pdtpi->cbSize = SIZEOF(DATETIMEPICKERINFO)
   SendMessageW(hDtp, DTM_GETDATETIMEPICKERINFO, 0, cast(LPARAM, pdtpi))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CDtPicker.GetDateTimePickerInfo (BYVAL hDtp AS HWND, BYREF dtpi AS DATETIMEPICKERINFO)
   IF VARPTR(dtpi) = NULL THEN EXIT SUB
   dtpi.cbSize = SIZEOF(DATETIMEPICKERINFO)
   SendMessageW(hDtp, DTM_GETDATETIMEPICKERINFO, 0, cast(LPARAM, @dtpi))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetDateTimePickerInfo (BYVAL hDtp AS HWND) AS DATETIMEPICKERINFO
   DIM dtpi AS DATETIMEPICKERINFO
   dtpi.cbSize = SIZEOF(DATETIMEPICKERINFO)
   SendMessageW(hDtp, DTM_GETDATETIMEPICKERINFO, 0, cast(LPARAM, @dtpi))
   RETURN dtpi
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the size needed to display the control without clipping.
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetIdealSize (BYVAL hDtp AS HWND, BYVAL psize AS SIZE PTR) AS BOOLEAN
   RETURN SendMessageW(hDtp, DTM_GETIDEALSIZE, 0, cast(LPARAM, psize))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetIdealSize (BYVAL hDtp AS HWND, BYREF sz AS SIZE) AS BOOLEAN
   RETURN SendMessageW(hDtp, DTM_GETIDEALSIZE, 0, cast(LPARAM, @sz))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDtPicker.GetIdealSize (BYVAL hDtp AS HWND) AS SIZE
   DIM sz AS SIZE
   SendMessageW(hDtp, DTM_GETIDEALSIZE, 0, cast(LPARAM, @sz))
   RETURN sz
END FUNCTION
' ========================================================================================

#endif

END NAMESPACE
