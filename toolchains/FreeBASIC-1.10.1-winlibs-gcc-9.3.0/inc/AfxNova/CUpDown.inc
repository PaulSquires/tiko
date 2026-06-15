' ########################################################################################
' Platform: Microsoft Windows
' Filename: CUpDown.inc
' Purpose:  Windows common controls - UpDown control
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
' CUpDown class
' ########################################################################################

TYPE CUpDown

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION GetAccel (BYVAL hUpDown AS HWND, BYVAL cAccels AS DWORD, BYVAL paccels AS UDACCEL PTR) AS LONG
   DECLARE STATIC FUNCTION GetBase (BYVAL hUpDown AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetBuddy (BYVAL hUpDown AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetPos (BYVAL hUpDown AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetPos32 (BYVAL hUpDown AS HWND, BYVAL pfError AS LONG PTR = NULL) AS LONG
   DECLARE STATIC FUNCTION GetRange (BYVAL hUpDown AS HWND) AS LONG
   DECLARE STATIC SUB GetRange32 (BYVAL hUpDown AS HWND, BYVAL pLow AS LONG PTR, BYVAL pHigh AS LONG PTR)
   DECLARE STATIC FUNCTION SetAccel (BYVAL hUpDown AS HWND, BYVAL cAccels AS DWORD, BYVAL pAccels AS UDACCEL PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBase (BYVAL hUpDown AS HWND, BYVAL nBase AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetBuddy (BYVAL hUpDown AS HWND, BYVAL hwndBuddy AS HWND) AS HWND
   DECLARE STATIC FUNCTION SetPos (BYVAL hUpDown AS HWND, BYVAL nPos AS SHORT) AS LONG
   DECLARE STATIC FUNCTION SetPos32 (BYVAL hUpDown AS HWND, BYVAL nPos AS LONG) AS LONG
   DECLARE STATIC SUB SetRange (BYVAL hUpDown AS HWND, BYVAL nUpper AS SHORT, BYVAL nLower AS SHORT)
   DECLARE STATIC SUB SetRange32 (BYVAL hUpDown AS HWND, BYVAL iLow AS LONG, BYVAL iHigh AS LONG)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CUpDown
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CUpDown
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Retrieves acceleration information for an up-down control.
' The return value is the number of accelerators currently set for the control.
' ========================================================================================
PRIVATE FUNCTION CUpDown.GetAccel (BYVAL hUpDown AS HWND, BYVAL cAccels AS DWORD, BYVAL pAccels AS UDACCEL PTR) AS LONG
   RETURN SendMessageW(hUpDown, UDM_GETACCEL, cAccels, CAST(LPARAM, pAccels))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current radix base (that is, either base 10 or 16) for an up-down control.
' ========================================================================================
PRIVATE FUNCTION CUpDown.GetBase (BYVAL hUpDown AS HWND) AS LONG
   RETURN SendMessageW(hUpDown, UDM_GETBASE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the current buddy window.
' ========================================================================================
PRIVATE FUNCTION CUpDown.GetBuddy (BYVAL hUpDown AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hUpDown, UDM_GETBUDDY, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current position of an up-down control with 16-bit precision.
' ========================================================================================
PRIVATE FUNCTION CUpDown.GetPos (BYVAL hUpDown AS HWND) AS LONG
   RETURN SendMessageW(hUpDown, UDM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the 32-bit position of an up-down control.
' ========================================================================================
PRIVATE FUNCTION CUpDown.GetPos32 (BYVAL hUpDown AS HWND, BYVAL pfError AS LONG PTR = NULL) AS LONG
   RETURN SendMessageW(hUpDown, UDM_GETPOS32, 0, cast(LPARAM, pfError))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the 32-bit position of an up-down control.
' ========================================================================================
PRIVATE FUNCTION CUpDown.GetRange (BYVAL hUpDown AS HWND) AS LONG
   RETURN SendMessageW(hUpDown, UDM_GETRANGE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the 32-bit position of an up-down control.
' ========================================================================================
PRIVATE SUB CUpDown.GetRange32 (BYVAL hUpDown AS HWND, BYVAL pLow AS LONG PTR, BYVAL pHigh AS LONG PTR)
   SendMessageW(hUpDown, UDM_GETRANGE32, cast(WPARAM, pLow), cast(LPARAM, pHigh))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the acceleration for an up-down control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CUpDown.SetAccel (BYVAL hUpDown AS HWND, BYVAL cAccels AS DWORD, BYVAL pAccels AS UDACCEL PTR) AS BOOLEAN
   RETURN SendMessageW(hUpDown, UDM_SETACCEL, cAccels, cast(LPARAM, pAccels))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the acceleration for an up-down control.
' The return value is the previous base value. If an invalid base is given, the return value is zero.
' ========================================================================================
PRIVATE FUNCTION CUpDown.SetBase (BYVAL hUpDown AS HWND, BYVAL nBase AS LONG) AS LONG
   RETURN SendMessageW(hUpDown, UDM_SETBASE, nBase, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the buddy window for an up-down control.
' The return value is the handle to the previous buddy window.
' ========================================================================================
PRIVATE FUNCTION CUpDown.SetBuddy (BYVAL hUpDown AS HWND, BYVAL hwndBuddy AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hUpDown, UDM_SETBUDDY, cast(WPARAM, hwndBuddy), 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current position for an up-down control with 16-bit precision.
' The return value is the previous position.
' ========================================================================================
PRIVATE FUNCTION CUpDown.SetPos (BYVAL hUpDown AS HWND, BYVAL nPos AS SHORT) AS LONG
   RETURN SendMessageW(hUpDown, UDM_SETPOS, 0, MAKELONG(nPos, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the current position for an up-down control with 32-bit precision.
' The return value is the previous position.
' ========================================================================================
PRIVATE FUNCTION CUpDown.SetPos32 (BYVAL hUpDown AS HWND, BYVAL nPos AS LONG) AS LONG
   RETURN SendMessageW(hUpDown, UDM_SETPOS32, 0, cast(LPARAM, nPos))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the minimum and maximum positions (range) for an up-down control.
' ========================================================================================
PRIVATE SUB CUpDown.SetRange (BYVAL hUpDown AS HWND, BYVAL nUpper AS SHORT, BYVAL nLower AS SHORT)
   SendMessageW(hUpDown, UDM_SETRANGE, 0, MAKELONG(nUpper, nLower))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum positions (range) for an up-down control.
' ========================================================================================
PRIVATE SUB CUpDown.SetRange32 (BYVAL hUpDown AS HWND, BYVAL iLow AS LONG, BYVAL iHigh AS LONG)
   SendMessageW(hUpDown, UDM_SETRANGE32, cast(WPARAM, iLow), cast(LPARAM, iHigh))
END SUB
' ========================================================================================

END NAMESPACE
