' ########################################################################################
' Platform: Microsoft Windows
' Filename: CTrackbar.inc
' Purpose:  Windows common controls - Trackbar
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
' CTrackbar class
' ########################################################################################

TYPE CTrackbar

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC SUB ClearSel (BYVAL hTrackbar AS HWND, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB ClearTics (BYVAL hTrackbar AS HWND, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC FUNCTION GetBuddy (BYVAL hTrackbar AS HWND, BYVAL fLocation AS BOOLEAN) AS HWND
   DECLARE STATIC SUB GetChannelRect (BYVAL hTrackbar AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB GetChannelRect (BYVAL hTrackbar AS HWND, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION GetChannelRect (BYVAL hTrackbar AS HWND) AS RECT
   DECLARE STATIC FUNCTION GetLineSize (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetNumTics (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetPageSize (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetPos (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetPTics (BYVAL hTrackbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetRangeMax (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetRangeMin (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetSelEnd (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetSelStart (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetThumbLength (BYVAL hTrackbar AS HWND) AS LONG
   DECLARE STATIC SUB GetThumbRect (BYVAL hTrackbar AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB GetThumbRect (BYVAL hTrackbar AS HWND, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION GetThumbRect (BYVAL hTrackbar AS HWND) AS RECT
   DECLARE STATIC FUNCTION GetTic (BYVAL hTrackbar AS HWND, BYVAL iTic AS DWORD) AS LONG
   DECLARE STATIC FUNCTION GetTicPos (BYVAL hTrackbar AS HWND, BYVAL iTic AS DWORD) AS LONG
   DECLARE STATIC FUNCTION GetTooltips (BYVAL hTrackbar AS HWND) AS HWND
   DECLARE STATIC FUNCTION SetBuddy (BYVAL hTrackbar AS HWND, BYVAL fLocation AS BOOLEAN, BYVAL hwndBuddy AS HWND) AS HWND
   DECLARE STATIC FUNCTION SetLineSize (BYVAL hTrackbar AS HWND, BYVAL lLineSize AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetPageSize (BYVAL hTrackbar AS HWND, BYVAL lPageSize AS LONG) AS LONG
   DECLARE STATIC SUB SetPos (BYVAL hTrackbar AS HWND, BYVAL fPosition AS BOOLEAN, BYVAL lPosition AS LONG)
   DECLARE STATIC SUB SetRange (BYVAL hTrackbar AS HWND, BYVAL lMinimum AS LONG, BYVAL lMaximum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB SetRangeMax (BYVAL hTrackbar AS HWND, BYVAL lMaximum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB SetRangeMin (BYVAL hTrackbar AS HWND, BYVAL lMinimum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB SetSel (BYVAL hTrackbar AS HWND, BYVAL iStart AS SHORT, BYVAL iEnd AS SHORT, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB SetSelEnd (BYVAL hTrackbar AS HWND, BYVAL lEnd AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB SetSelStart (BYVAL hTrackbar AS HWND, BYVAL lStart AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC SUB SetThumbLength (BYVAL hTrackbar AS HWND, BYVAL iLength AS LONG)
   DECLARE STATIC FUNCTION SetTic (BYVAL hTrackbar AS HWND, BYVAL lPosition AS LONG) AS BOOLEAN
   DECLARE STATIC SUB SetTicFreq (BYVAL hTrackbar AS HWND, BYVAL wFreq AS WORD)
   DECLARE STATIC FUNCTION SetTipSide (BYVAL hTrackbar AS HWND, BYVAL fLocation AS LONG) AS LONG
   DECLARE STATIC SUB SetToolTips (BYVAL hTrackbar AS HWND, BYVAL hwndTT AS HWND)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CTrackbar
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CTrackbar
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Clears the current selection range in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.ClearSel (BYVAL hTrackbar AS HWND, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_CLEARSEL, fRedraw, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Removes the current tick marks from a trackbar. This message does not remove the first
' and last tick marks, which are created automatically by the trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.ClearTics (BYVAL hTrackbar AS HWND, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_CLEARTICS, fRedraw, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the handle to a trackbar control buddy window at a given location.
' Value indicating which buddy window handle will be retrieved, by relative location.
' This value can be one of the following:
' - TRUE : Retrieves the handle to the buddy to the left of the trackbar. If the trackbar
'   control uses the TBS_VERT style, the message will retrieve the buddy above the trackbar.
' - FALSE : Retrieves the handle to the buddy to the right of the trackbar. If the trackbar
'   control uses the TBS_VERT style, the message will retrieve the buddy below the trackbar.
' Returns the handle to the buddy window at the location specified by wParam, or NULL if no buddy window exists at that location.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetBuddy (BYVAL hTrackbar AS HWND, BYVAL fLocation AS BOOLEAN) AS HWND
   RETURN CAST(HWND, SendMessage(hTrackbar, TBM_GETBUDDY, fLocation, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size and position of the bounding rectangle for a trackbar's channel.
' (The channel is the area over which the slider moves. It contains the highlight when a
' range is selected.)
' ========================================================================================
PRIVATE SUB CTrackbar.GetChannelRect (BYVAL hTrackbar AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW(hTrackbar, TBM_GETCHANNELRECT, 0, cast(LPARAM, prc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTrackbar.GetChannelRect (BYVAL hTrackbar AS HWND, BYREF rc AS RECT)
   SendMessageW(hTrackbar, TBM_GETCHANNELRECT, 0, cast(LPARAM, @rc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetChannelRect (BYVAL hTrackbar AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hTrackbar, TBM_GETCHANNELRECT, 0, cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of logical positions the trackbar's slider moves in response to
' keyboard input from the arrow keys, such as the or keys. The logical positions are the
' integer increments in the trackbar's range of minimum to maximum slider positions.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetLineSize (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETLINESIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of tick marks in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetNumTics (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETNUMTICS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of logical positions the trackbar's slider moves in response to
' keyboard input, such as the or keys, or mouse input, such as clicks in the trackbar's
' channel. The logical positions are the integer increments in the trackbar's range of
' minimum to maximum slider positions.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetPageSize (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETPAGESIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current logical position of the slider in a trackbar. The logical positions
' are the integer values in the trackbar's range of minimum to maximum slider positions.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetPos (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the address of an array that contains the positions of the tick marks for a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetPTics (BYVAL hTrackbar AS HWND) AS DWORD
   RETURN SendMessageW(hTrackbar, TBM_GETPTICS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum position for the slider in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetRangeMax (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETRANGEMAX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the minimum position for the slider in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetRangeMin (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETRANGEMIN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the ending position of the current selection range in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetSelEnd (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETSELEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the starting position of the current selection range in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetSelStart (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETSELSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetThumbLength (BYVAL hTrackbar AS HWND) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETTHUMBLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.GetThumbRect (BYVAL hTrackbar AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW(hTrackbar, TBM_GETTHUMBRECT, 0, cast(LPARAM, prc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTrackbar.GetThumbRect (BYVAL hTrackbar AS HWND, BYREF rc AS RECT)
   SendMessageW(hTrackbar, TBM_GETTHUMBRECT, 0, cast(LPARAM, @rc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetThumbRect (BYVAL hTrackbar AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hTrackbar, TBM_GETTHUMBRECT, 0, cast(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetTic (BYVAL hTrackbar AS HWND, BYVAL iTic AS DWORD) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETTIC, iTic, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetTicPos (BYVAL hTrackbar AS HWND, BYVAL iTic AS DWORD) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_GETTICPOS, iTic, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the ToolTip control assigned to the trackbar, if any.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.GetTooltips (BYVAL hTrackbar AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hTrackbar, TBM_GETTOOLTIPS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns a window as the buddy window for a trackbar control. Trackbar buddy windows are
' automatically displayed in a location relative to the control's orientation (horizontal
' or vertical).
' Returns the handle to the window that was previously assigned to the control at that location.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.SetBuddy (BYVAL hTrackbar AS HWND, BYVAL fLocation AS BOOLEAN, BYVAL hwndBuddy AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hTrackbar, TBM_SETBUDDY, fLocation, cast(LPARAM, hwndBuddy)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the number of logical positions the trackbar's slider moves in response to keyboard
' input from the arrow keys, such as the or keys. The logical positions are the integer
' increments in the trackbar's range of minimum to maximum slider positions.
' Returns a 32-bit value that specifies the previous line size.
' Remarks: The default setting for the line size is 1.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.SetLineSize (BYVAL hTrackbar AS HWND, BYVAL lLineSize AS LONG) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_SETLINESIZE, 0, lLineSize)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the number of logical positions the trackbar's slider moves in response to keyboard
' input, such as the or keys, or mouse input, such as clicks in the trackbar's channel.
' The logical positions are the integer increments in the trackbar's range of minimum to
' maximum slider positions.
' Returns a 32-bit value that specifies the previous page size.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.SetPageSize (BYVAL hTrackbar AS HWND, BYVAL lPageSize AS LONG) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_SETPAGESIZE, 0, lPageSize)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current logical position of the slider in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.SetPos (BYVAL hTrackbar AS HWND, BYVAL fPosition AS BOOLEAN, BYVAL lPosition AS LONG)
   SendMessageW(hTrackbar, TBM_SETPOS, fPosition, lPosition)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the range of minimum and maximum logical positions for the slider in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.SetRange (BYVAL hTrackbar AS HWND, BYVAL lMinimum AS LONG, BYVAL lMaximum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_SETRANGE, fRedraw, MAKELONG(lMinimum, lMaximum))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the maximum logical position for the slider in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.SetRangeMax (BYVAL hTrackbar AS HWND, BYVAL lMaximum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_SETRANGEMAX, fRedraw, lMaximum)
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the minimum logical position for the slider in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.SetRangeMin (BYVAL hTrackbar AS HWND, BYVAL lMinimum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_SETRANGEMIN, fRedraw, lMinimum)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the starting and ending positions for the available selection range in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.SetSel (BYVAL hTrackbar AS HWND, BYVAL iStart AS SHORT, BYVAL iEnd AS SHORT, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_SETSEL, fRedraw, MAKELONG(iStart, iEnd))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the ending logical position of the current selection range in a trackbar. This
' message is ignored if the trackbar does not have the TBS_ENABLESELRANGE style.
' ========================================================================================
PRIVATE SUB CTrackbar.SetSelEnd (BYVAL hTrackbar AS HWND, BYVAL lEnd AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_SETSELEND, fRedraw, lEnd)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the starting logical position of the current selection range in a trackbar. This
' message is ignored if the trackbar does not have the BS_ENABLESELRANGE style.
' ========================================================================================
PRIVATE SUB CTrackbar.SetSelStart (BYVAL hTrackbar AS HWND, BYVAL lStart AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
   SendMessageW(hTrackbar, TBM_SETSELSTART, fRedraw, lStart)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the length of the slider in a trackbar. This message is ignored if the trackbar
' does not have the TBS_FIXEDLENGTH style.
' ========================================================================================
PRIVATE SUB CTrackbar.SetThumbLength (BYVAL hTrackbar AS HWND, BYVAL iLength AS LONG)
   SendMessageW(hTrackbar, TBM_SETTHUMBLENGTH, iLength, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets a tick mark in a trackbar at the specified logical position.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.SetTic (BYVAL hTrackbar AS HWND, BYVAL lPosition AS LONG) AS BOOLEAN
   RETURN SendMessageW(hTrackbar, TBM_SETTIC, 0, lPosition)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the interval frequency for tick marks in a trackbar.
' ========================================================================================
PRIVATE SUB CTrackbar.SetTicFreq (BYVAL hTrackbar AS HWND, BYVAL wFreq AS WORD)
   SendMessageW(hTrackbar, TBM_SETTICFREQ, wFreq, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Positions a ToolTip control used by a trackbar control. Trackbar controls that use the
' TBS_TOOLTIPS style display ToolTips.
' ========================================================================================
PRIVATE FUNCTION CTrackbar.SetTipSide (BYVAL hTrackbar AS HWND, BYVAL fLocation AS LONG) AS LONG
   RETURN SendMessageW(hTrackbar, TBM_SETTIPSIDE, fLocation, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns a ToolTip control to a trackbar control.
' ========================================================================================
PRIVATE SUB CTrackbar.SetToolTips (BYVAL hTrackbar AS HWND, BYVAL hwndTT AS HWND)
   SendMessageW(hTrackbar, TBM_SETTOOLTIPS, cast(WPARAM, hwndTT), 0)
END SUB
' ========================================================================================

END NAMESPACE
