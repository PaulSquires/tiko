' ########################################################################################
' Platform: Microsoft Windows
' Filename: CPager.inc
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
#include once "win/ole2.bi"
#include once "AfxNova/RGB_Colors.bi"

NAMESPACE AfxNova


' ########################################################################################
'                                     *** PAGER ***
' ########################################################################################
TYPE CPager

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC SUB ForwardMouse (BYVAL hPager AS HWND, BYVAL bForward AS BOOLEAN)
   DECLARE STATIC FUNCTION GetBkColor (BYVAL hPager AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetBorder (BYVAL hPager AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetButtonSize (BYVAL hPager AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetButtonState (BYVAL hPager AS HWND, BYVAL iButton AS LONG) AS DWORD
   DECLARE STATIC SUB GetDropTarget (BYVAL hPager AS HWND, BYVAL ppdt AS IDropTarget PTR PTR)
   DECLARE STATIC FUNCTION GetDropTarget (BYVAL hPager AS HWND) AS IDropTarget PTR
   DECLARE STATIC FUNCTION GetPos (BYVAL hPager AS HWND) AS LONG
   DECLARE STATIC SUB RecalcSize (BYVAL hPager AS HWND)
   DECLARE STATIC FUNCTION SetBkColor (BYVAL hPager AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION SetBorder (BYVAL hPager AS HWND, BYVAL iBorder AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetButtonSize (BYVAL hPager AS HWND, BYVAL iSize AS LONG) AS LONG
   DECLARE STATIC SUB SetChild (BYVAL hPager AS HWND, BYVAL hwndChild AS HWND)
   DECLARE STATIC FUNCTION SetPos (BYVAL hPager AS HWND, BYVAL iPos AS LONG) AS LONG

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CPager
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CPager
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Enables or disables mouse forwarding for the pager control. When mouse forwarding is
' enabled, the pager control forwards WM_MOUSEMOVE messages to the contained window. You
' can use this macro or send the PGM_FORWARDMOUSE message explicitly.
' ========================================================================================
PRIVATE SUB CPager.ForwardMouse (BYVAL hPager AS HWND, BYVAL bForward AS BOOLEAN)
   SendMessageW(hPager, PGM_FORWARDMOUSE, cast(WPARAM, bForWard), 0)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the current background color for the pager control. You can use this macro or
' send the PGM_GETBKCOLOR message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.GetBkColor (BYVAL hPager AS HWND) AS COLORREF
   RETURN SendMessageW(hPager, PGM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current border size for the pager control. You can use this macro or send
' the PGM_GETBORDER message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.GetBorder (BYVAL hPager AS HWND) AS LONG
   RETURN SendMessageW(hPager, PGM_GETBORDER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current button size for the pager control. You can use this macro or send
' the PGM_GETBUTTONSIZE message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.GetButtonSize (BYVAL hPager AS HWND) AS LONG
   RETURN SendMessageW(hPager, PGM_GETBUTTONSIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the state of the specified button in a pager control. You can use this macro
' or send the PGM_GETBUTTONSTATE message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.GetButtonState (BYVAL hPager AS HWND, BYVAL iButton AS LONG) AS DWORD
   RETURN SendMessageW(hPager, PGM_GETBUTTONSTATE, 0, iButton)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a pager control's IDropTarget interface pointer. You can use this macro or send
' the PGM_GETDROPTARGET message explicitly.
' ========================================================================================
PRIVATE SUB CPager.GetDropTarget (BYVAL hPager AS HWND, BYVAL ppdt AS IDropTarget PTR PTR)
   SendMessageW(hPager, PGM_GETDROPTARGET, 0, cast(LPARAM, ppdt))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CPager.GetDropTarget (BYVAL hPager AS HWND) AS IDropTarget PTR
   DIM pdt AS IDropTarget PTR
   SendMessageW(hPager, PGM_GETDROPTARGET, 0, cast(LPARAM, @pdt))
   RETURN pdt
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current scroll position of the pager control. You can use this macro or
' send the PGM_GETPOS message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.GetPos (BYVAL hPager AS HWND) AS LONG
   RETURN SendMessageW(hPager, PGM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Forces the pager control to recalculate the size of the contained window. Using this
' method will result in a PGN_CALCSIZE notification being sent. You can use this method or
' send the PGM_RECALCSIZE message explicitly.
' ========================================================================================
PRIVATE SUB CPager.RecalcSize (BYVAL hPager AS HWND)
   SendMessageW(hPager, PGM_RECALCSIZE, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the current background color for the pager control. You can use this macro or send
' the PGM_SETBKCOLOR message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.SetBkColor (BYVAL hPager AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hPager, PGM_SETBKCOLOR, 0, cast(LPARAM, clr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current border size for the pager control. You can use this macro or send the
' PGM_SETBORDER message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.SetBorder (BYVAL hPager AS HWND, BYVAL iBorder AS LONG) AS LONG
   RETURN SendMessageW(hPager, PGM_SETBORDER, 0, cast(LPARAM, iBorder))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current button size for the pager control. You can use this macro or send the
' PGM_SETBUTTONSIZE message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.SetButtonSize (BYVAL hPager AS HWND, BYVAL iSize AS LONG) AS LONG
   RETURN SendMessageW(hPager, PGM_SETBUTTONSIZE, 0, cast(LPARAM, iSize))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the contained window for the pager control. This macro will not change the parent
' of the contained window; it only assigns a window handle to the pager control for scrolling.
' In most cases, the contained window will be a child window. If this is the case, the
' contained window should be a child of the pager control. You can use this macro or send
' the PGM_SETCHILD message explicitly.
' ========================================================================================
PRIVATE SUB CPager.SetChild (BYVAL hPager AS HWND, BYVAL hwndChild AS HWND)
   SendMessageW(hPager, PGM_SETCHILD, 0, cast(LPARAM, hwndChild))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the scroll position for the pager control. You can use this macro or send the
' PGM_SETPOS message explicitly.
' ========================================================================================
PRIVATE FUNCTION CPager.SetPos (BYVAL hPager AS HWND, BYVAL iPos AS LONG) AS LONG
   RETURN SendMessageW(hPager, PGM_SETPOS, 0, cast(LPARAM, iPos))
END FUNCTION
' ========================================================================================

END NAMESPACE
