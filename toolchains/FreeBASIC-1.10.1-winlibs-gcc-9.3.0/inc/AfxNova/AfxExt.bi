' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxExt.bi
' Purpose:  Extensions to the FreeBasic headers for Windows
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2025 José Roca
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
#include once "win/shtypes.bi"

' ########################################################################################
'                                  *** WINUSER32 ***
' ########################################################################################

'#inclib "user32"

' // Identifies the dots per inch (dpi) setting for a thread, process, or window.
type DPI_AWARENESS AS LONG
enum
  DPI_AWARENESS_INVALID = -1
  DPI_AWARENESS_UNAWARE = 0
  DPI_AWARENESS_SYSTEM_AWARE = 1
  DPI_AWARENESS_PER_MONITOR_AWARE = 2
end enum

' // Identifies the awareness context for a window.
#define DPI_AWARENESS_CONTEXT HANDLE
#define DPI_AWARENESS_CONTEXT_UNAWARE              (CAST(DPI_AWARENESS_CONTEXT,-1))
#define DPI_AWARENESS_CONTEXT_SYSTEM_AWARE         (CAST(DPI_AWARENESS_CONTEXT,-2))
#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE    (CAST(DPI_AWARENESS_CONTEXT,-3))
#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 (CAST(DPI_AWARENESS_CONTEXT,-4))
#define DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED    (CAST(DPI_AWARENESS_CONTEXT,-5))

' // Identifies the DPI hosting behavior for a window.
' // This behavior allows windows created in the thread to host
' // child windows with a different DPI_AWARENESS_CONTEXT
type DPI_HOSTING_BEHAVIOR AS LONG
enum
  DPI_HOSTING_BEHAVIOR_INVALID = -1
  DPI_HOSTING_BEHAVIOR_DEFAULT = 0
  DPI_HOSTING_BEHAVIOR_MIXED = 1
end enum

' // Describes per-monitor DPI scaling behavior overrides for child windows within dialogs.
' // The values in this enumeration are bitfields and can be combined.
type DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS AS LONG
enum
  DCDC_DEFAULT = &h0000
  DCDC_DISABLE_FONT_UPDATE = &h0001
  DCDC_DISABLE_RELAYOUT = &h0002
end enum

' // In Per Monitor v2 contexts, dialogs will automatically respond to DPI changes by
' // resizing themselves and re-computing the positions of their child windows
' // (here referred to as re-layouting). This enum works in conjunction with
' // SetDialogDpiChangeBehavior in order to override the default DPI scaling behavior for dialogs.
' // This does not affect DPI scaling behavior for the child windows of dialogs
' // (beyond re-layouting), which is controlled by DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS.
type DIALOG_DPI_CHANGE_BEHAVIOR AS LONG
enum
  DDC_DEFAULT = &h0000
  DDC_DISABLE_ALL = &h0001
  DDC_DISABLE_RESIZE = &h0002
  DDC_DISABLE_CONTROL_RELAYOUT = &h0004
end enum

extern "Windows" LIB "user32.dll"
DECLARE FUNCTION AdjustWindowRectExForDpi (BYVAL lpRect AS RECT PTR, BYVAL dwStyle AS DWORD, BYVAL bMenu As WINBOOL, _
   BYVAL dwExStyle AS DWORD, BYVAL dpi AS UINT) AS WINBOOL
DECLARE FUNCTION AreDpiAwarenessContextsEqual (BYVAL dpiContextA AS DPI_AWARENESS_CONTEXT, BYVAL dpiContextB AS DPI_AWARENESS_CONTEXT) AS WINBOOL
DECLARE FUNCTION EnableNonClientDpiScaling (BYVAL hwnd AS HWND) AS WINBOOL
DECLARE FUNCTION GetAwarenessFromDpiAwarenessContext (BYVAL value AS DPI_AWARENESS_CONTEXT) AS DPI_AWARENESS
DECLARE FUNCTION GetDialogControlDpiChangeBehavior (BYVAL hwnd AS HWND) AS DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS
DECLARE FUNCTION GetDialogDpiChangeBehavior (BYVAL hDlg AS HWND) AS DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS
DECLARE FUNCTION GetDpiAwarenessContextForProcess (BYVAL hProcess AS HANDLE) AS DPI_AWARENESS_CONTEXT
DECLARE FUNCTION GetDpiForSystem() AS UINT
DECLARE FUNCTION GetDpiForWindow (BYVAL hwnd AS HWND) AS UINT
DECLARE FUNCTION GetDpiFromDpiAwarenessContext (BYVAL value AS DPI_AWARENESS_CONTEXT) AS UINT
DECLARE FUNCTION GetSystemDpiForProcess (BYVAL hProcess AS HANDLE) AS UINT
DECLARE FUNCTION GetSystemMetricsForDpi (BYVAL nIndex AS int_, BYVAL dpi AS UINT) AS int_
DECLARE FUNCTION GetThreadDpiAwarenessContext () AS DPI_AWARENESS_CONTEXT
DECLARE FUNCTION GetThreadDpiHostingBehavior () AS DPI_HOSTING_BEHAVIOR
DECLARE FUNCTION GetWindowDpiAwarenessContext (BYVAL hwnd AS HWND) AS DPI_AWARENESS_CONTEXT
DECLARE FUNCTION InheritWindowMonitor (BYVAL hwnd AS HWND, BYVAL hwndInherit AS HWND) AS WINBOOL
DECLARE FUNCTION IsValidDpiAwarenessContext (BYVAL value AS DPI_AWARENESS_CONTEXT) AS WINBOOL
DECLARE FUNCTION LogicalToPhysicalPointForPerMonitorDPI (BYVAL hwnd AS HWND, BYVAL lpPoint AS LPPOINT) AS WINBOOL
DECLARE FUNCTION PhysicalToLogicalPointForPerMonitorDPI (BYVAL hwnd AS HWND, BYVAL lpPoint AS LPPOINT) AS WINBOOL
DECLARE FUNCTION SetDialogControlDpiChangeBehavior (BYVAL hwnd AS HWND, BYVAL mask AS DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS, _
   BYVAL values AS DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS) AS WINBOOL
DECLARE FUNCTION SetProcessDpiAwarenessContext (BYVAL value AS DPI_AWARENESS_CONTEXT) AS WINBOOL
DECLARE FUNCTION SetThreadCursorCreationScaling (BYVAL cursorDPI AS UINT) AS UINT
DECLARE FUNCTION SetThreadDpiAwarenessContext (BYVAL dpiContext AS DPI_AWARENESS_CONTEXT) AS DPI_AWARENESS_CONTEXT
DECLARE FUNCTION SetThreadDpiHostingBehavior (BYVAL value AS DPI_HOSTING_BEHAVIOR) AS DPI_HOSTING_BEHAVIOR
DECLARE FUNCTION SystemParametersInfoForDpi (BYVAL uiAction AS UINT, BYVAL uiParam AS UINT, BYVAL pvParam AS PVOID, BYVAL fWinIni AS UINT, BYVAL dpi AS UINT) AS WINBOOL
end extern

extern "Windows" LIB "user32.dll"
DECLARE FUNCTION MessageBoxTimeoutA (BYVAL hWin AS HWND, BYVAL pszText AS LPCSTR, BYVAL pszCaption AS LPCSTR, _
   BYVAL uType AS UINT, BYVAL wLanguageId AS WORD, BYVAL dwMilliseconds AS DWORD) AS LONG
DECLARE FUNCTION MessageBoxTimeoutW (BYVAL hWin AS HWND, BYVAL pwszText AS LPWSTR, BYVAL pwszCaption AS LPWSTR, _
   BYVAL uType AS UINT, BYVAL wLanguageId AS WORD, BYVAL dwMilliseconds AS DWORD) AS LONG
end extern

' ########################################################################################


' ########################################################################################
'                                    *** SHCORE ***
' ########################################################################################

'#inclib "shcore"

type DISPLAY_DEVICE_TYPE AS LONG
enum
   DEVICE_PRIMARY = 0
   DEVICE_IMMERSIVE = 1
end enum

type SCALE_CHANGE_FLAGS AS LONG
enum
   SCF_VALUE_NONE = &h00
   SCF_SCALE = &h01
   SCF_PHYSICAL = &h02
end enum

' // Identifies dots per inch (dpi) awareness values.
type PROCESS_DPI_AWARENESS AS LONG
enum
  PROCESS_DPI_UNAWARE = 0
  PROCESS_SYSTEM_DPI_AWARE = 1
  PROCESS_PER_MONITOR_DPI_AWARE = 2
end enum

' // Identifies the dots per inch (dpi) setting for a monitor.
type MONITOR_DPI_TYPE AS LONG
enum
  MDT_EFFECTIVE_DPI = 0
  MDT_ANGULAR_DPI = 1
  MDT_RAW_DPI = 2
  MDT_DEFAULT
end enum

' defined in shtypes.bi
'type DEVICE_SCALE_FACTOR as long
'enum
'	SCALE_100_PERCENT = 100
'	SCALE_140_PERCENT = 140
'	SCALE_180_PERCENT = 180
'end enum

' Additional constants
CONST DEVICE_SCALE_FACTOR_INVALID = 0
CONST SCALE_120_PERCENT = 120
CONST SCALE_125_PERCENT = 125
CONST SCALE_150_PERCENT = 150
CoNST SCALE_160_PERCENT = 160
CONST SCALE_175_PERCENT = 175
CONST SCALE_200_PERCENT = 200
CONST SCALE_225_PERCENT = 225
CONST SCALE_250_PERCENT = 250
CONST SCALE_300_PERCENT = 300
CONST SCALE_350_PERCENT = 350
CONST SCALE_400_PERCENT = 400
CONST SCALE_450_PERCENT = 450
CONST SCALE_500_PERCENT = 500

extern "Windows" LIB "shcore.dll"
' This function is not supported as of Windows 8.1. Use GetScaleFactorForMonitor instead.
DECLARE FUNCTION GetScaleFactorForDevice (BYVAL deviceType AS DISPLAY_DEVICE_TYPE) AS DEVICE_SCALE_FACTOR
' This function is not supported as of Windows 8.1. Use RegisterScaleChangeEvent instead.
DECLARE FUNCTION RegisterScaleChangeNotifications (BYVAL displayDevice AS DISPLAY_DEVICE_TYPE, BYVAL hwndNotify AS HWND, BYVAL uMsgNotify AS UINT, BYVAL pdwCookie AS DWORD PTR) AS HRESULT
' This function is not supported as of Windows 8.1. Use UnregisterScaleChangeEvent instead.
DECLARE FUNCTION RevokeScaleChangeNotifications (BYVAL displayDevice AS DISPLAY_DEVICE_TYPE, BYVAL dwCookie AS DWORD) AS HRESULT
DECLARE FUNCTION GetScaleFactorForMonitor (BYVAL hMon AS HMONITOR, BYVAL pScale AS DEVICE_SCALE_FACTOR PTR) AS HRESULT
DECLARE FUNCTION RegisterScaleChangeEvent (BYVAL hEvent AS HANDLE, BYVAL pdwCookie AS DWORD_PTR PTR) AS HRESULT
DECLARE FUNCTION UnregisterScaleChangeEvent (BYVAL dwCookie AS DWORD_PTR) AS HRESULT
DECLARE FUNCTION SetProcessDpiAwareness (BYVAL value AS PROCESS_DPI_AWARENESS) AS HRESULT
DECLARE FUNCTION GetProcessDpiAwareness (BYVAL hprocess AS HANDLE, BYVAL value AS PROCESS_DPI_AWARENESS PTR) AS HRESULT
DECLARE FUNCTION GetDpiForMonitor (BYVAL hMonitor AS HMONITOR, BYVAL dpiTYpe AS MONITOR_DPI_TYPE, BYVAL dpiX AS UINT PTR, BYVAL dpiY AS UINT PTR) AS HRESULT
end extern

' ########################################################################################

' ########################################################################################
'                                    *** DWMAPI ***
' ########################################################################################

#INCLUDE ONCE "AfxNova/AfxDwmApi.bi"

' ########################################################################################
