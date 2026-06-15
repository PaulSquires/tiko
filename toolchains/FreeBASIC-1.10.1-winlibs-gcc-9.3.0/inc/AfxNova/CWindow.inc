' ########################################################################################
' Platform: Microsoft Windows
' Filename: CWindow.inc
' Contents: A wrapper class to create a SDK main window and add controls to it.
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
#include once "win/uxtheme.bi"
#include once "AfxNova/AfxCtl.inc"
#include once "AfxNova/AfxWin.inc"
#include once "AfxNova/AfxMenu.inc"
#include once "AfxNova/RGB_Colors.bi"
USING AfxNova

' ========================================================================================
' Macro for debug
' To allow debugging, define _CWINDOW_DEBUG_ 1 in your application before including this file.
' To capture and display the messages sent by the Windows function OutputDebugStringW, you
' can use the DebugView tool. See: https://learn.microsoft.com/en-us/sysinternals/downloads/debugview
' ========================================================================================
#ifndef _CWINDOW_DEBUG_
   #define _CWINDOW_DEBUG_ 0
#ENDIF
#ifndef _CWINDOW_DP_
   #define _CWINDOW_DP_ 1
   #MACRO CWINDOW_DP(st)
      #IF (_CWINDOW_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

#ifndef DDT_CBMACROS
#define DDT_CBMACROS
' // For compatibility with the Power Basic syntax
#define CBHNDL(wp, lp) cast(HWND, lp)
#define CBCTL(wp, lp) LOWORD(wp)
#define CBCTLMSG(wp, lp) HIWORD(wp)
#define CBNMCODE(wp, lp) LOWORD(wp) 
#define CBNMHWND(wp, lp) cast(HWND, lp)
#define CBNMID(wp, lp) HIWORD(wp)
#define CBNMHDR(wp, lp) cast(NMHDR PTR, lp)
' // For cast notification messages, e.g.
' DIM p AS NMDATETIMECHANGE PTR = CBNMSGPTR(NMDATETIMECHANGE, wParam, lParam)
' print p->nmhdr.idfrom
' print p->dwFlags
#define CBNMSGPTR(msg, wp, lp) cast(msg PTR, CBNMHDR(wp, lp))
' // To copy notification messages, e.g.
' DIM dt AS NMDATETIMECHANGE
' CBNMTYPESET(dt, wParam, lParam)
' print dt.nmhdr.idfrom
' print dt.dwFlags
#define CBNMTYPESET(tp, wp, lp) memcpy @tp, CAST(ANY PTR, lp), SIZEOF(tp)
#endif

NAMESPACE AfxNova

#ifndef AFX_ANCHORPOINT
#define AFX_ANCHORPOINT
' // Layout manager - Anchor flags
ENUM AFX_ANCHORPOINT
   AFX_ANCHOR_NONE =  0
   AFX_ANCHOR_WIDTH
   AFX_ANCHOR_RIGHT
   AFX_ANCHOR_CENTER_HORZ
   AFX_ANCHOR_HEIGHT
   AFX_ANCHOR_HEIGHT_WIDTH
   AFX_ANCHOR_HEIGHT_RIGHT
   AFX_ANCHOR_BOTTOM
   AFX_ANCHOR_BOTTOM_WIDTH
   AFX_ANCHOR_BOTTOM_RIGHT
   AFX_ANCHOR_CENTER_HORZ_BOTTOM
   AFX_ANCHOR_CENTER_VERT
   AFX_ANCHOR_CENTER_VERT_RIGHT
   AFX_ANCHOR_CENTER
END ENUM
#endif

#ifndef AFX_ANCHORPROPERTY
' // Layout manager - Anchor properties
TYPE AFX_ANCHORPROPERTY
   hwndCtl AS HWND
   anchor  AS LONG
   rc      AS RECT
   centerX AS LONG
   centerY AS LONG
END TYPE
#endif

#ifndef AFX_WINDOWCOLORS
' // Windows and control colors
TYPE AFX_WINDOWCOLORS
   hwnd AS ..HWND
   foreColor AS COLORREF
   backColor AS COLORREF
END TYPE
#endif

#ifndef AFX_CTLUSERDATA
' // Controls user data
TYPE AFX_CTLUSERDATA
   hCtl AS HWND
   Values (0 TO 9) AS LONG_PTR
END TYPE
#endif

#ifndef AFX_CTLCALLBACKS
' // Controls user data
TYPE AFX_CTLCALLBACKS
   hCtl AS HWND
   pCallback AS ANY PTR
END TYPE
#endif

' ========================================================================================
' CWindow class
' ========================================================================================
TYPE CWindow

Private:
   m_hwnd AS HWND                                  ' // Window handle
   m_hInstance AS HINSTANCE                        ' // Instance handle
   m_pUserWndProc AS WNDPROC                       ' // User window procedure
   m_hFont AS HFONT                                ' // Default font handle
   m_hAccel AS HACCEL                              ' // Accelerator table handle
   m_DPI AS LONG = 96                              ' // Design-time DPI
   m_rx AS SINGLE = 1                              ' // Horizontal scaling ratio
   m_ry AS SINGLE = 1                              ' // Vertical scaling ratio
   m_wAtom AS ATOM                                 ' // Class atom
   m_wszClassName AS WSTRING * 260                 ' // Class name
   m_DefaultFontSize AS LONG                       ' // Default font size
   m_wszDefaultFontName AS WSTRING * LF_FACESIZE   ' // Default font name
   m_IsStabilized AS BOOLEAN                       ' // The main window is stabilized (true) or is not stable (false)
   m_hRichEditLib AS HMODULE                       ' // Rich Edit moudle handle
   DIM m_rgUserData(0 TO 99) AS LONG_PTR           ' // User data
   DIM m_rgAccelEntries(ANY) AS ACCEL              ' // Accelerator table
   DIM m_rgProps(ANY) AS AFX_ANCHORPROPERTY        ' // Array of anchor property structures
   DIM m_rgCtrlUserData(ANY) AS AFX_CTLUSERDATA    ' // Control's user data
   DIM m_rgColors(ANY) AS AFX_WINDOWCOLORS         ' // Window and controls colors - Array of colors structures
   DIM m_rgCtrlCallbacks(ANY) AS AFX_CTLCALLBACKS  ' // Control's callbacks
   ' // Scrollable windows
   m_IsWindowScrollable AS BOOLEAN                 ' // Window scrollable -True of False
   m_OrigClientRect AS RECT                        ' // Coordinates of the window original client area
   m_nHorzInc AS LONG                              ' // Horizontal increment
   m_nVertInc AS LONG                              ' // Vertical increment
   m_HScrollMax AS LONG                            ' // Maximum horizontal scroll value
   m_VScrollMax AS LONG                            ' // Maximum vertical scroll value
   m_HScrollPos AS LONG                            ' // Horizontal scroll position
   m_VScrollPos AS LONG                            ' // Vertical scroll position
   m_HorzUnits AS LONG                             ' // Amount, in device units, of horizontal scrolling
   m_VertUnits AS LONG                             ' // Amount, in device units, of vertical scrolling

Public:
   DECLARE CONSTRUCTOR (BYREF wszClassName AS CONST WSTRING = "")
   DECLARE DESTRUCTOR
   DECLARE PROPERTY DPI () AS SINGLE
   DECLARE PROPERTY DPI (BYVAL dpi AS SINGLE)
   DECLARE PROPERTY UserData (BYVAL idx AS LONG) AS LONG_PTR
   DECLARE PROPERTY UserData (BYVAL idx AS LONG, BYVAL newValue AS LONG_PTR)
   DECLARE FUNCTION DoEvents (BYVAL nCmdShow AS LONG = 0) AS LONG
   DECLARE FUNCTION Create (BYVAL hParent AS HWND = NULL, BYREF wszTitle AS WSTRING = "", BYVAL lpfnWndProc AS WNDPROC = NULL, _
      BYVAL x AS LONG = CW_USEDEFAULT, BYVAL y AS LONG = CW_USEDEFAULT, BYVAL nWidth AS LONG = CW_USEDEFAULT, BYVAL nHeight AS LONG = CW_USEDEFAULT, _
      BYVAL dwStyle AS DWORD = WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS, _
      BYVAL dwExStyle AS DWORD = WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE) AS HWND
   DECLARE FUNCTION CreateOverlapped (BYVAL hParent AS HWND = NULL, BYREF wszTitle AS WSTRING = "", BYVAL lpfnWndProc AS WNDPROC = NULL, _
      BYVAL x AS LONG = CW_USEDEFAULT, BYVAL y AS LONG = CW_USEDEFAULT, BYVAL nWidth AS LONG = CW_USEDEFAULT, BYVAL nHeight AS LONG = CW_USEDEFAULT, _
      BYVAL dwExStyle AS UINT = WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE) AS HWND
   DECLARE SUB SetClientSize (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)
   DECLARE SUB Center (BYVAL hwnd AS HWND = NULL, BYVAL hwndParent AS HWND = NULL)
   DECLARE FUNCTION GetWindowProc () AS WNDPROC
   DECLARE PROPERTY hWindow () AS HWND
   DECLARE PROPERTY hWindow (BYVAL hwnd AS HWND)
   DECLARE PROPERTY InstanceHandle () AS HINSTANCE
   DECLARE PROPERTY InstanceHandle (BYVAL hInst AS HINSTANCE)
   DECLARE PROPERTY ClassStyle () AS ULONG_PTR
   DECLARE PROPERTY ClassStyle (BYVAL dwStyle AS LONG_PTR)
   DECLARE PROPERTY WindowStyle () AS LONG_PTR
   DECLARE PROPERTY WindowStyle (BYVAL dwStyle AS LONG_PTR)
   DECLARE PROPERTY WindowExStyle () AS LONG_PTR
   DECLARE PROPERTY WindowExStyle (BYVAL dwExStyle AS LONG_PTR)
   DECLARE PROPERTY WindowStyleEx () AS LONG_PTR
   DECLARE PROPERTY WindowStyleEx (BYVAL dwExStyle AS LONG_PTR)
   DECLARE PROPERTY DefaultFontName () AS STRING
   DECLARE PROPERTY DefaultFontName (BYREF wszFontName AS WSTRING)
   DECLARE PROPERTY DefaultFontSize () AS LONG
   DECLARE PROPERTY DefaultFontSize (BYVAL nPointSize AS LONG)
   DECLARE PROPERTY Font () AS HFONT
   DECLARE PROPERTY Font (BYVAL hFont AS HFONT)
   DECLARE PROPERTY Brush () AS HBRUSH
   DECLARE PROPERTY Brush (BYVAL hbrBackground AS HBRUSH)
   DECLARE PROPERTY BigIcon (BYVAL hIcon AS HICON)
   DECLARE PROPERTY SmallIcon (BYVAL hIcon AS HICON)
   DECLARE PROPERTY rxRatio () AS SINGLE
   DECLARE PROPERTY rxRatio (BYVAL rx AS SINGLE)
   DECLARE PROPERTY ryRatio (BYVAL rx AS SINGLE)
   DECLARE PROPERTY ryRatio () AS SINGLE
   DECLARE FUNCTION ScaleX (BYVAL cx AS SINGLE) AS SINGLE
   DECLARE FUNCTION ScaleY (BYVAL cy AS SINGLE) AS SINGLE
   DECLARE FUNCTION UnScaleX (BYVAL cx AS SINGLE) AS SINGLE
   DECLARE FUNCTION UnScaleY (BYVAL cy AS SINGLE) AS SINGLE
   DECLARE PROPERTY Width () AS LONG
   DECLARE PROPERTY Height () AS LONG
   DECLARE PROPERTY ScreenX () AS LONG
   DECLARE PROPERTY ScreenY () AS LONG
   DECLARE PROPERTY ClientHeight () AS LONG
   DECLARE PROPERTY ClientWidth () AS LONG
   DECLARE PROPERTY ControlWidth (BYVAL hwnd AS HWND) AS LONG
   DECLARE PROPERTY ControlHeight (BYVAL hwnd AS HWND) AS LONG
   DECLARE PROPERTY ControlClientWidth (BYVAL hwnd AS HWND) AS LONG
   DECLARE PROPERTY ControlClientHeight (BYVAL hwnd AS HWND) AS LONG
   DECLARE SUB GetWindowRect OVERLOAD (BYVAL lpRect AS LPRECT)
   DECLARE FUNCTION GetWindowRect OVERLOAD () AS RECT
   DECLARE SUB GetClientRect OVERLOAD (BYVAL lpRect AS LPRECT)
   DECLARE FUNCTION GetClientRect OVERLOAD () AS RECT
   DECLARE SUB GetControlWindowRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
   DECLARE FUNCTION GetControlWindowRect OVERLOAD (BYVAL hwnd AS HWND) AS RECT
   DECLARE SUB GetControlClientRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
   DECLARE FUNCTION GetControlClientRect OVERLOAD (BYVAL hwnd AS HWND) AS RECT
   DECLARE SUB GetWorkArea OVERLOAD (BYVAL lpRect AS LPRECT)
   DECLARE FUNCTION GetWorkArea OVERLOAD () AS RECT
   DECLARE FUNCTION ControlHandle (BYVAL cID AS LONG) AS HWND
   DECLARE FUNCTION ControlGetStyle (BYVAL hWnd AS HWND) AS LONG_PTR
   DECLARE FUNCTION ControlGetExStyle (BYVAL hWnd AS HWND) AS LONG_PTR
   DECLARE FUNCTION ControlSetStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DECLARE FUNCTION ControlSetExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
   DECLARE FUNCTION ControlAddStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DECLARE FUNCTION ControlAddExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
   DECLARE FUNCTION ControlRemoveStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DECLARE FUNCTION ControlRemoveExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS DWORD) AS LONG_PTR
   DECLARE FUNCTION SetWindowPos (BYVAL hwnd AS HWND, BYVAL hwndInsertAfter AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL uFlags AS UINT) AS BOOLEAN
   DECLARE FUNCTION MoveWindow (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS BOOLEAN = TRUE) AS BOOLEAN
   DECLARE SUB Resize ()
   DECLARE SUB ForceVisibleDisplay ()
   DECLARE FUNCTION CreateFont (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, BYVAL lWeight AS LONG = 0, _
           BYVAL bItalic AS UBYTE = FALSE, BYVAL bUnderline AS UBYTE = FALSE, BYVAL bStrikeOut AS UBYTE = FALSE, BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS HFONT
   DECLARE FUNCTION SetFont (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, BYVAL lWeight AS LONG = 0, _
           BYVAL bItalic AS UBYTE = FALSE, BYVAL bUnderline AS UBYTE = FALSE, BYVAL bStrikeOut AS UBYTE = FALSE, BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS BOOLEAN
   DECLARE FUNCTION AddControl (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = NULL, BYVAL cID AS LONG_PTR = 0, _
           BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, BYVAL nWidth AS LONG = 0, _
           BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS LONG = -1, BYVAL dwExStyle AS LONG = -1, BYVAL lpParam AS LONG_PTR = 0) AS HWND
   DECLARE FUNCTION SetControlSubclass (BYVAL hCtl AS HWND, BYVAL pfnSubclass AS ANY PTR, BYVAL uIdSubclass AS UINT_PTR, BYVAL dwRefData AS ANY PTR) AS BOOLEAN
   DECLARE FUNCTION SetControlSubclass (BYVAL hCtl AS HWND, BYVAL pfnSubclass AS ANY PTR, BYVAL uIdSubclass AS UINT_PTR, BYVAL dwRefData AS DWORD_PTR) AS BOOLEAN

   ' // Main window stabilization
   DECLARE FUNCTION Stabilize () AS BOOLEAN
   DECLARE FUNCTION NonStable () AS BOOLEAN
   DECLARE FUNCTION IsStabilized () AS BOOLEAN
   DECLARE FUNCTION IsNonStable () AS BOOLEAN

   ' // Keyboard accelerators
   DECLARE PROPERTY AccelHandle () AS HACCEL
   DECLARE PROPERTY AccelHandle (BYVAL hAccel AS HACCEL)
   DECLARE SUB AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYVAL wKey AS WORD, BYVAL cmd AS WORD)
   DECLARE SUB AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYREF wszKey AS WSTRING, BYVAL cmd AS WORD)
   DECLARE FUNCTION CreateAcceleratorTable () AS HACCEL
   DECLARE SUB DestroyAcceleratorTable ()

   ' // Scrollable windows
   DECLARE FUNCTION SetViewPort (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION IsWindowScrollable () AS BOOLEAN
   DECLARE SUB ResetScrollBars
   DECLARE SUB SetupScrollBars
   DECLARE SUB OnVScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   DECLARE SUB OnHScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   DECLARE SUB OnSize (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)

   ' // Layout manager
   DECLARE FUNCTION AnchorControl (BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DECLARE FUNCTION AnchorControl (BYVAL hCtl AS HWND, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DECLARE FUNCTION AnchorControl (BYVAL hParent AS HWND, BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DECLARE FUNCTION GetAnchorItem (BYVAL hwndCtl AS HWND) AS LONG
   DECLARE FUNCTION AdjustControls () AS BOOLEAN

   '// Control's user data
   DECLARE FUNCTION GetUserDataItem (BYVAL cid AS LONG) AS LONG
   DECLARE FUNCTION ControlSetUser (BYVAL cid AS LONG, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION ControlGetUser (BYVAL cid AS LONG, BYVAL index AS LONG) AS LONG_PTR
   DECLARE FUNCTION GetUserDataItem (BYVAL hctl AS HWND) AS LONG
   DECLARE FUNCTION ControlSetUser (BYVAL hctl AS HWND, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION ControlGetUser (BYVAL hctl AS HWND, BYVAL index AS LONG) AS LONG_PTR

   ' //  Colors
   DECLARE FUNCTION GetColorItem (BYVAL hwnd AS ..HWND) AS LONG
   DECLARE FUNCTION GetForeColor (BYVAL nItem AS LONG) AS COLORREF
   DEClARE FUNCTION GetForeColor (BYVAL hCtl AS HWND) AS COLORREF
   DECLARE FUNCTION GetBackColor (BYVAL nItem AS LONG) AS COLORREF
   DECLARE FUNCTION GetBackColor (BYVAL hCtl AS HWND) AS COLORREF
   DECLARE FUNCTION SetBackColor (BYVAL backColor AS COLORREF) AS BOOLEAN
   DECLARE FUNCTION SetCtlColors (BYVAL hCtl AS ..HWND, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   DECLARE FUNCTION SetCtlColors (BYVAL cID AS LONG, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN

   ' // Callbacks
   DECLARE FUNCTION GetControlCallbackItem (BYVAL cID AS LONG) AS LONG
   DECLARE FUNCTION GetControlCallbackItem (BYVAL hCtl AS HWND) AS LONG
   DECLARE FUNCTION SetControlCallback (BYVAL cID AS LONG, BYVAL pCallback AS ANY PTR) AS BOOLEAN
   DECLARE FUNCTION SetControlCallback (BYVAL hCtl AS HWND, BYVAL pCallback AS ANY PTR) AS BOOLEAN
   DECLARE FUNCTION GetControlCallback (BYVAL cID AS LONG) AS ANY PTR
   DECLARE FUNCTION GetControlCallback (BYVAL hCtl AS HWND) AS ANY PTR

Private:
   DECLARE STATIC FUNCTION LayoutEnumChildProc (BYVAL hwnd AS HWND, BYVAL lParam AS LPARAM) AS LONG

END TYPE
' ========================================================================================

' ########################################################################################
'                                 *** CWINDOW CLASS ***
' ########################################################################################

' // CWindow class forward declarations
DECLARE FUNCTION CWindow_RegisterClass (BYREF wszClassName AS CONST WSTRING, BYVAL hInstance AS HINSTANCE, BYVAL lpfnWndProc AS WNDPROC) AS ATOM
DECLARE FUNCTION CWindow_WindowProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
DECLARE FUNCTION AfxCWindowPtr OVERLOAD (BYVAL hwnd AS HWND) AS CWindow PTR
DECLARE FUNCTION AfxCWindowPtr OVERLOAD (BYVAL lParam AS LPARAM) AS CWindow PTR
DECLARE FUNCTION AfxCWindowPtr OVERLOAD (BYVAL pCreateStruct AS CREATESTRUCT PTR) AS CWindow PTR
DECLARE FUNCTION AfxCWindowOwnerPtr OVERLOAD (BYVAL hwnd AS HWND) AS CWindow PTR

' ========================================================================================
' Registers the window class.
' Parameter:
' - lpfnWndProc = Pointer to the window procedure.
' Return Value:
'   An atom that uniquely identifies the class.
' Remarks:
'   The values of several of the members of this structure can be retrieved with
'   GetClassLongPtrW and set with SetClassLongPtrW.
' Note: The class uses CS_HREDRAW OR CS_VREDRAW as default window styles. Without them,
' the background is not repainted and the controls leave garbage in it when resized. With
' them, windows with many controls cause heavy flicker. To avoid flicker, you can change
' the windows style using e.g. pWindow.ClassStyle = CS_DBLCLKS and take care yourself of
' repainting.
' ========================================================================================
PRIVATE FUNCTION CWindow_RegisterClass (BYREF wszClassName AS CONST WSTRING, BYVAL hInstance AS HINSTANCE, BYVAL lpfnWndProc AS WNDPROC) AS ATOM

   DIM    wAtom AS ATOM                     ' // Atom
   DIM    wcexw AS WNDCLASSEXW              ' // WNDCLASSEXW structure
   STATIC nCount AS LONG = 0                ' // Counter
   STATIC m_wszClassName AS WSTRING * 256   ' // class name

   IF LEN(wszClassName) THEN
      m_wszClassName = wszClassName
   ELSE
      m_wszClassName = "FBWindowClass"
      m_wszClassName = m_wszClassName & ":" & WSTR(nCount)
   END IF

   ' // Fill the WNDCLASSEXW structure
   WITH wcexw
      .cbSize        = SIZEOF(wcexw)
      .style         = CS_DBLCLKS OR CS_HREDRAW OR CS_VREDRAW
      .lpfnWndProc   = lpfnWndProc
      .cbClsExtra    = 0
      .cbWndExtra    = SIZEOF(HANDLE)
      .hInstance     = hInstance
      .hCursor       = ..LoadCursorW(NULL, CAST(LPCWSTR, IDC_ARROW))
      .hbrBackground = CAST(HBRUSH, COLOR_3DFACE + 1)
      .lpszMenuName  = NULL
      .lpszClassName = @m_wszClassName
      .hIcon         = 0
      .hIconSm       = 0
   END WITH

   ' // Register the class
   wAtom = RegisterClassExW(@wcexw)
   ' // Increment the class counter
   IF wAtom THEN nCount = nCount + 1
   ' // Return the atom
   FUNCTION = wAtom

END FUNCTION
' ========================================================================================

' ========================================================================================
' Processes window messages
' // Uses IsDialogMessage in the message pump. To process arrow keys, characters, enter,
' // insert, backspace or delete keys, you can process the WM_GETDLGCODE message:
' // CASE WM_GETDLGCODE
' //    FUNCTION = DLGC_WANTALLKEYS
' // If you are only interested in arrow keys and characters...
' // CASE WM_GETDLGCODE
' //    FUNCTION = DLGC_WANTARROWS OR DLGC_WANTCHARS
' ========================================================================================
PRIVATE FUNCTION CWindow.DoEvents (BYVAL nCmdShow AS LONG = 0) AS LONG

   DIM uMsg AS MSG
   IF m_hwnd = NULL THEN EXIT FUNCTION
   ' // Show the window and update its client area
   IF nCmdShow = 0 THEN ..ShowWindow(m_hwnd, SW_SHOW) ELSE ..ShowWindow(m_hwnd, nCmdShow)
   ..UpdateWindow m_hwnd
   ' // Message loop
   WHILE ..GetMessageW(@uMsg, NULL, 0, 0)
      ' // Processes accelerator keys for menu commands
      IF m_hAccel = NULL OR .TranslateAcceleratorW(m_hwnd, m_hAccel, @uMsg) = 0 THEN
         ' // Determines whether a message is intended for the specified
         ' // dialog box and, if it is, processes the message.
         IF ..IsDialogMessageW(m_hwnd, @uMsg) = 0 THEN
            ' // Translates virtual-key messages into character messages.
            ..TranslateMessage @uMsg
            ' // Dispatches a message to a window procedure.
            ..DispatchMessageW @uMsg
         END IF
      END IF
   WEND
   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Internal CWindow callback procedure.
' ========================================================================================
PRIVATE FUNCTION CWindow_WindowProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   DIM pWindow AS CWindow PTR

   SELECT CASE AS CONST uMsg

      CASE WM_CREATE
         ' // Retrieve a reference to the CWindow class
         DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
         pWindow = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
         RETURN CallWindowProcW(pWindow->GetWindowProc, hwnd, uMsg, wParam, lParam)

      CASE WM_SYSCOMMAND
         ' // Trap the SC_CLOSE message sent by Alt+F4 and the X-button
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
         ' // Abort the action
            IF (wParam AND &hFFF0) = SC_CLOSE AND pWindow->IsStabilized = TRUE THEN RETURN 0
         END IF

      CASE WM_COMMAND
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            DIM hCtl AS ..HWND = CAST(..HWND, lParam)
            DIM nItem AS LONG = pWindow->GetControlCallbackItem(hCtl)
            IF nItem >= 0 THEN
               RETURN CallWindowProcW(CAST(WNDPROC, pWindow->GetControlCallback(hCtl)), hCtl, uMsg, wParam, lParam)
            END IF
         END IF

      CASE WM_NOTIFY
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            DIM ptnmhdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
            DIM hCtl AS ..HWND = ptnmhdr->hwndFrom
            DIM nItem AS LONG = pWindow->GetControlCallbackItem(hCtl)
            IF nItem >= 0 THEN
               RETURN CallWindowProcW(CAST(WNDPROC, pWindow->GetControlCallback(hCtl)), hCtl, uMsg, wParam, lParam)
            END IF
         END IF

      CASE WM_ERASEBKGND
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            DIM hDC AS ..HDC = CAST(..HDC, wParam)
            DIM rcClient AS RECT
            ..GetCLientRect(hwnd, @rcClient)
            DIM nItem AS LONG = pWindow->GetColorItem(CAST(..HWND, hwnd))
            IF nItem >= 0 THEN
               DIM hBrush AS ..HBRUSH = CreateSolidBrush(pWindow->GetBackColor(nItem))
               FillRect hDC, @rcClient, hBrush
               DeleteObject hBrush
               RETURN CTRUE
            END IF
         END IF

      CASE WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC
         ' WM_CTLCOLORBTN does not color a button - use XPBUTTON
         ' wParam = HDC; lParam = Handle of the control.
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            DIM nItem AS LONG = pWindow->GetColorItem(CAST(..HWND, lParam))
            IF nItem >= 0 THEN
               SetTextColor(CAST(HDC, wParam), pWindow->GetForeColor(nItem))
               SetBkColor(CAST(HDC, wParam), pWindow->GetBackColor(nItem))
               SetDCBrushColor(CAST(HDC, wParam), pWindow->GetBackColor(nItem))
               RETURN CAST(LRESULT, GetStockObject(DC_BRUSH))
            END IF
         END IF

      CASE WM_SIZE
         ' // Adjust anchored controls and redraw the main window
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            IF wParam = SIZE_RESTORED OR wParam = SIZE_MAXIMIZED THEN
               IF pWindow->AdjustControls THEN
                  InvalidateRect hwnd, NULL, CTRUE
                  UpdateWindow hwnd
               END IF
            END IF
            ' // Scrollable window - Setup scrollbars
            IF pWindow->IsWindowScrollable THEN
               pWindow->ResetScrollbars
               pWindow->SetupScrollbars
            END IF
         END IF

      CASE WM_HSCROLL
         ' // Horizontal scrollbar
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            IF pWindow->IsWindowScrollable THEN pWindow->OnHScroll(wParam, lParam)
         END IF

      CASE WM_VSCROLL
         ' // Vertical scrollbar
         pWindow = AfxCWindowPtr(hwnd)
         IF pWindow THEN
            IF pWindow->IsWindowScrollable THEN pWindow->OnVScroll(wParam, lParam)
         END IF

   END SELECT

   pWindow = AfxCWindowPtr(hwnd)
   IF pWindow THEN
      IF pWindow->GetWindowProc THEN
         DIM res AS LRESULT = CallWindowProcW(pWindow->GetWindowProc, hwnd, uMsg, wParam, lParam)
         IF res = 0 THEN RETURN 0
         IF res <> CTRUE OR res <> TRUE THEN RETURN res
      END IF
   END IF

   ' // Process unprocessed messages
   RETURN DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' CWindow class constructor
' Usage:
'    DIM pWindow AS CWindow
' -or-
'    DIM pWindow AS CWindow = "MyClassName" (change it as needed)
' Remarks:
' Using the fist syntax, CWindow will use "FBWindowClass:" and a number as the window class.
' Using the second syntax, CWindows will use the passed string as the class name.
' ========================================================================================
PRIVATE CONSTRUCTOR CWindow (BYREF wszClassName AS CONST WSTRING = "")

   ' // Class name
   m_wszClassName = wszClassName
   ' // Instance handle
   m_hInstance = ..GetModuleHandleW(NULL)
   ' // Scale windows according to the DPI setting.
'   IF AfxUseDpiScaling = 0 THEN this.DPI = 96 ELSE this.DPI = -1   ' May fail in Windows 10
   IF AfxIsProcessDpiAware = FALSE THEN this.DPI = 96 ELSE this.DPI = -1
   ' // Default font name
   IF LEN(m_wszDefaultFontName) = 0 THEN
      IF AfxWindowsVersion >= 600 AND CLNG(AfxIsProcessDpiAware) THEN m_wszDefaultFontName = "Segoe UI" ELSE m_wszDefaultFontName = "Tahoma"
   END IF
   ' // Default font size
   IF m_DefaultFontSize = 0 THEN
      IF AfxWindowsVersion >= 600 AND CLNG(AfxIsProcessDpiAware) THEN m_DefaultFontSize = 9 ELSE m_DefaultFontSize = 8
   END IF
   ' // Initialize the common controls library
   DIM icc AS INITCOMMONCONTROLSEX
   icc.dwSize = SIZEOF(icc)
   icc.dwICC  = ICC_NATIVEFNTCTL_CLASS OR ICC_COOL_CLASSES OR ICC_BAR_CLASSES OR _
                ICC_TAB_CLASSES OR ICC_USEREX_CLASSES OR ICC_WIN95_CLASSES OR _
                ICC_STANDARD_CLASSES OR ICC_ANIMATE_CLASS OR ICC_DATE_CLASSES OR _
                ICC_HOTKEY_CLASS OR ICC_INTERNET_CLASSES OR ICC_LISTVIEW_CLASSES OR _
                ICC_PAGESCROLLER_CLASS OR ICC_PROGRESS_CLASS OR ICC_TREEVIEW_CLASSES OR _
                ICC_UPDOWN_CLASS
   ..InitCommonControlsEx(@icc)

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' CWindow class destructor
' ========================================================================================
PRIVATE DESTRUCTOR CWindow

   IF m_hFont THEN ..DeleteObject m_hFont
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   IF m_wszClassName <> "" THEN .UnregisterClassW(m_wszClassName, m_hInstance)
   IF m_hRichEditLib THEN ..FreeLibrary m_hRichEditLib

END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the DPI (dots per pixel) used by the application.
' ========================================================================================
PRIVATE PROPERTY CWindow.DPI () AS SINGLE
   PROPERTY = m_DPI
END PROPERTY
' ========================================================================================

' ========================================================================================
' Sets the DPI (dots per pixel) to be used by the application.
' Pass -1 to use the value returned by the GetDeviceCaps API function.
' Note: Set this value if you want to make your application High-DPI aware.
' The main window, controls and fonts will be scaled if the user changes the DPI setting.
' Don't change the DPI value once the main window has been created.
' ========================================================================================
PRIVATE PROPERTY CWindow.DPI (BYVAL nDPI AS SINGLE)

   DIM hDC AS HDC
   m_DPI = nDPI
   ' // Get the screen device context
   hDC = ..GetDC(NULL)
   IF m_DPI < 0 THEN
      m_DPI = ..GetDeviceCaps(hDC, LOGPIXELSX)
      nDPI = m_DPI
   END IF
   ' // Resolution ratio = current resolution / 96
   IF nDPI < 0 THEN
      m_rx = (..GetDeviceCaps(hDC, LOGPIXELSX) / 96)
      m_ry = (..GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ELSE
      m_rx = nDPI / 96
      m_ry = nDPI / 96
   END IF
   ..ReleaseDC NULL, hDC

END PROPERTY
' ========================================================================================

' =====================================================================================
' Retrieves a value from the user data area of a CWindow.
' idx = The index number of the user data value to retrieve, in the range 0 to 99 inclusive.
' =====================================================================================
PRIVATE PROPERTY CWindow.UserData (BYVAL idx AS LONG) AS LONG_PTR
   IF idx < 0 OR idx > 99 THEN EXIT PROPERTY
   PROPERTY = m_rgUserData(idx)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets a value in the user data area of a CWindow.
' idx = The index number of the user data value to retrieve, in the range 0 to 99 inclusive.
' =====================================================================================
PRIVATE PROPERTY CWindow.UserData (BYVAL idx AS LONG, BYVAL newValue AS LONG_PTR)
   IF idx < 0 OR idx > 99 THEN EXIT PROPERTY
   m_rgUserData(idx) = newValue
END PROPERTY
' =====================================================================================

' ========================================================================================
' Window creation
' Parameters:
' - hParent     = Parent window handle
' - wszTitle    = Window caption
' - lpfnWndProc = Address of the callback function
' - x           = Horizontal position
' - y           = Vertical position
' - nWidth      = Window width
' - nHeight     = Window height
' - dwStyle     = Window style
' - dwExStyle   = Extended style
' Remarks: As the last parameter we are passing a pointer to the class to allow its use
' in the WM_CREATE message, e.g.
'    CASE WM_CREATE
'       DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
'       DIM pWindow AS CWindow PTR = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
'       IF pWindow THEN pWindow->AddControl("Button", hwnd, IDCANCEL, "&Close", 350, 250, 75, 23)
' -or-
'    CASE WM_CREATE
'       DIM pWindow AS CWindow PTR = AfxCWindowPtr(CAST(CREATESTRUCT PTR, lParam))
'       IF pWindow THEN pWindow->AddControl("Button", hwnd, IDCANCEL, "&Close", 350, 250, 75, 23)
' -or-
'    CASE WM_CREATE
'       DIM pWindow AS CWindow PTR = AfxCWindowPtr(lParam)
'       IF pWindow THEN pWindow->AddControl("Button", hwnd, IDCANCEL, "&Close", 350, 250, 75, 23)
' ========================================================================================
PRIVATE FUNCTION CWindow.Create (BYVAL hParent AS HWND = NULL, BYREF wszTitle AS WSTRING = "", BYVAL lpfnWndProc AS WNDPROC = NULL, _
   BYVAL x AS LONG = CW_USEDEFAULT, BYVAL y AS LONG = CW_USEDEFAULT, BYVAL nWidth AS LONG = CW_USEDEFAULT, BYVAL nHeight AS LONG = CW_USEDEFAULT, _
   BYVAL dwStyle AS UINT = WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS, _
   BYVAL dwExStyle AS UINT = WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE) AS HWND

   IF m_hwnd <> NULL THEN EXIT FUNCTION
   ' // User window callback procedure
   m_pUserWndProc = lpfnWndProc
   ' // Internal window callback procedure
   lpfnWndProc = @CWindow_WindowProc
   ' // Register the class
   m_wAtom = CWindow_RegisterClass(m_wszClassName, m_hInstance, lpfnWndProc)
   IF m_wAtom = 0 THEN EXIT FUNCTION
   ' // Create a default font
   IF m_hFont = NULL THEN m_hFont = this.CreateFont(m_wszDefaultFontName, m_DefaultFontSize, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET)
   ' // Create the window
   m_hwnd = ..CreateWindowExW(dwExStyle, CAST(LPCWSTR, CAST(ULONG_PTR, CAST(WORD, m_wAtom))), wszTitle, dwStyle, _
            IIF(x = CW_USEDEFAULT, CW_USEDEFAULT, x * m_rx), _
            IIF(y = CW_USEDEFAULT, CW_USEDEFAULT, y * m_ry), _
            IIF(nWidth = CW_USEDEFAULT, CW_USEDEFAULT, nWidth * m_rx), _
            IIF(nHeight = CW_USEDEFAULT, CW_USEDEFAULT, nHeight * m_ry), _
            hParent, NULL, m_hInstance, CAST(HANDLE, @this))
   IF m_hwnd = NULL THEN EXIT FUNCTION
   ' // Get the class name
   ..GetClassNameW(m_hwnd, @m_wszClassName, SIZEOF(m_wszClassName)\2)
   FUNCTION = m_hwnd
   ' // Set the font
   IF m_hFont THEN ..SendMessageW m_hwnd, WM_SETFONT, CAST(WPARAM, m_hFont), FALSE
   ' // Store the class pointer
   ..SetWindowLongPtrW(m_hwnd, 0, CAST(LONG_PTR, @this))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an overlapped window. An overlapped window has a title bar and a border.
' ========================================================================================
PRIVATE FUNCTION CWindow.CreateOverlapped (BYVAL hParent AS HWND = NULL, BYREF wszTitle AS WSTRING = "", BYVAL lpfnWndProc AS WNDPROC = NULL, _
   BYVAL x AS LONG = CW_USEDEFAULT, BYVAL y AS LONG = CW_USEDEFAULT, BYVAL nWidth AS LONG = CW_USEDEFAULT, BYVAL nHeight AS LONG = CW_USEDEFAULT, _
   BYVAL dwExStyle AS UINT = WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE) AS HWND

   RETURN this.Create(hParent, wszTitle, lpfnWndProc, x, y, nWidth, nHeight, WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU, dwExStyle)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Adjusts the bounding rectangle of the window based on the desired size of the client area.
' ========================================================================================
PRIVATE SUB CWindow.SetClientSize (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)
   AfxSetWindowClientSize(m_hwnd, nWidth, nHeight, m_rx, m_ry)
END SUB
' ========================================================================================

' =====================================================================================
' Centers a window on the screen or over another window.
' It also ensures that the placement is done within the work area.
' Parameters:
' - hwnd = Handle of the window.
' - hwndParent = [optional] Handle of the parent window.
' =====================================================================================
PRIVATE SUB CWindow.Center (BYVAL hwnd AS HWND = NULL, BYVAL hwndParent AS HWND = NULL)
   IF hwnd = NULL THEN hwnd = m_hwnd
   AfxCenterWindow(hwnd, hwndParent)
END SUB
' =====================================================================================

' =====================================================================================
' Return the user's Window procedure function pointer
' =====================================================================================
PRIVATE FUNCTION CWindow.GetWindowProc () AS WNDPROC
   FUNCTION = m_pUserWndProc
END FUNCTION
' =====================================================================================

' =====================================================================================
' Returns the window handle
' =====================================================================================
PRIVATE PROPERTY CWindow.hWindow () AS HWND
   PROPERTY = m_hwnd
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the window handle
' =====================================================================================
PRIVATE PROPERTY CWindow.hWindow (BYVAL hwnd AS HWND)
   IF m_hwnd = NULL THEN m_hwnd = hwnd
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the instance handle
' =====================================================================================
PRIVATE PROPERTY CWindow.InstanceHandle () AS HINSTANCE
   PROPERTY = m_hInstance
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the instance handle
' =====================================================================================
PRIVATE PROPERTY CWindow.InstanceHandle (BYVAL hInst AS HINSTANCE)
   IF m_hInstance = NULL THEN m_hInstance = hInst
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets the window class style.
' =====================================================================================
PRIVATE PROPERTY CWindow.ClassStyle () AS ULONG_PTR
   IF m_hwnd = NULL THEN EXIT PROPERTY
   PROPERTY = ..GetClassLongPtrW(m_hwnd, GCL_STYLE)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the window class style.
' =====================================================================================
PRIVATE PROPERTY CWindow.ClassStyle (BYVAL dwStyle AS LONG_PTR)
   IF m_hwnd = NULL THEN EXIT PROPERTY
   ..SetClassLongPtrW(m_hwnd, GCL_STYLE, dwStyle)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets the window style.
' =====================================================================================
PRIVATE PROPERTY CWindow.WindowStyle () AS LONG_PTR
   IF m_hwnd = NULL THEN EXIT PROPERTY
   PROPERTY = ..GetWindowLongPtrW(m_hwnd, GWL_STYLE)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the window style.
' Example to create a popup window: pWindow.WindowStyle = WS_POPUPWINDOW OR WS_CAPTION
' =====================================================================================
PRIVATE PROPERTY CWindow.WindowStyle (BYVAL dwStyle AS LONG_PTR)
   IF m_hwnd = NULL THEN EXIT PROPERTY
   ..SetWindowLongPtrW(m_hwnd, GWL_STYLE, dwStyle)
   ..SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets the window extended style.
' =====================================================================================
PRIVATE PROPERTY CWindow.WindowExStyle () AS LONG_PTR
   IF m_hwnd = NULL THEN EXIT PROPERTY
   PROPERTY = ..GetWindowLongPtrW(m_hwnd, GWL_EXSTYLE)
END PROPERTY
' =====================================================================================
' =====================================================================================
PRIVATE PROPERTY CWindow.WindowStyleEx () AS LONG_PTR
   IF m_hwnd = NULL THEN EXIT PROPERTY
   PROPERTY = ..GetWindowLongPtrW(m_hwnd, GWL_EXSTYLE)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the window extended style.
' =====================================================================================
PRIVATE PROPERTY CWindow.WindowExStyle (BYVAL dwExStyle AS LONG_PTR)
   IF m_hwnd = NULL THEN EXIT PROPERTY
   ..SetWindowLongPtrW(m_hwnd, GWL_EXSTYLE, dwExStyle)
   ..SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
END PROPERTY
' =====================================================================================
' =====================================================================================
PRIVATE PROPERTY CWindow.WindowStyleEx (BYVAL dwExStyle AS LONG_PTR)
   IF m_hwnd = NULL THEN EXIT PROPERTY
   ..SetWindowLongPtrW(m_hwnd, GWL_EXSTYLE, dwExStyle)
   ..SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets/sets the default font name
' =====================================================================================
PRIVATE PROPERTY CWindow.DefaultFontName () AS STRING
   PROPERTY = m_wszDefaultFontName
END PROPERTY
' =====================================================================================
PRIVATE PROPERTY CWindow.DefaultFontName (BYREF wszFontName AS WSTRING)
   IF VARPTR(wszFontName) <> NULL AND LEN(wszFontName) > 0 THEN m_wszDefaultFontName = wszFontName
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets/sets the size in points of the default font.
' =====================================================================================
PRIVATE PROPERTY CWindow.DefaultFontSize () AS LONG
   PROPERTY = m_DefaultFontSize
END PROPERTY
' =====================================================================================
PRIVATE PROPERTY CWindow.DefaultFontSize (BYVAL nPointSize AS LONG)
   m_DefaultFontSize = nPointSize
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the handle of the font used as default.
' =====================================================================================
PRIVATE PROPERTY CWindow.Font () AS HFONT
   PROPERTY = m_hFont
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the handle of the font used as default.
' If m_hFont already exists, ignore it because the font is already being used.
' =====================================================================================
PRIVATE PROPERTY CWindow.Font (BYVAL hFont AS HFONT)
   IF m_hFont = NULL THEN m_hFont = hFont
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets the background brush.
' =====================================================================================
PRIVATE PROPERTY CWindow.Brush () AS HBRUSH
   IF m_hwnd = NULL THEN EXIT PROPERTY
   PROPERTY = CAST(HBRUSH, ..GetClassLongPtrW(m_hwnd, GCLP_HBRBACKGROUND))
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the background brush.
' Handle to the class background brush. This member can be a handle to the physical
' brush to be used for painting the background, or it can be a color value. A color
' value must be one of the standard system colors (the value 1 must be added
' to the chosen color), e.g. COLOR_WINDOW + 1.
' You can also use CreateSolidBrush to create a logical brush with a solid color, e.g.
' CreateSolidBrush(BGR(0, 0, 255)
' =====================================================================================
PRIVATE PROPERTY CWindow.Brush (BYVAL hbrBackground AS HBRUSH)
   IF m_hwnd = NULL THEN EXIT PROPERTY
   ..SetClassLongPtrW m_hwnd, GCLP_HBRBACKGROUND, CAST(LONG_PTR, hbrBackground)
   ..InvalidateRect m_hwnd, NULL, CTRUE
   ..UpdateWindow m_hwnd
END PROPERTY
' =====================================================================================

' =====================================================================================
' Associates a new large icon with the main window. The system displays the large icon
' in the ALT+TAB dialog box.
' Parameters:
' - hIcon = Handle to the new large icon.
'   If this parameter is NULL, the icon is removed.
' =====================================================================================
PRIVATE PROPERTY CWindow.BigIcon (BYVAL hIcon AS HICON)
   ..SendMessageW(m_hwnd, WM_SETICON, CAST(WPARAM, ICON_BIG), CAST(LPARAM, hIcon))
END PROPERTY
' =====================================================================================

' =====================================================================================
' Associates a new small icon with the main window. The system displays the small icon
' in the in the window caption.
' Parameters:
' - hIcon = Handle to the new small icon.
'   If this parameter is NULL, the icon is removed.
' =====================================================================================
PRIVATE PROPERTY CWindow.SmallIcon (BYVAL hIcon AS HICON)
   ..SendMessageW(m_hwnd, WM_SETICON, CAST(WPARAM, ICON_SMALL), CAST(LPARAM, hIcon))
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets the horizontal scaling ratio
' =====================================================================================
PRIVATE PROPERTY CWindow.rxRatio () AS SINGLE
   PROPERTY = m_rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the horizontal scaling ratio
' =====================================================================================
PRIVATE PROPERTY CWindow.rxRatio (BYVAL rx AS SINGLE)
   m_rx = rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Gets the vertical scaling ratio
' =====================================================================================
PRIVATE PROPERTY CWindow.ryRatio () AS SINGLE
   PROPERTY = m_ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Sets the vertical scaligng ratio
' =====================================================================================
PRIVATE PROPERTY CWindow.ryRatio (BYVAL ry AS SINGLE)
   m_ry = ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Scales an horizontal coordinate according the DPI setting.
' =====================================================================================
PRIVATE FUNCTION CWindow.ScaleX (BYVAL cx AS SINGLE) AS SINGLE
   FUNCTION = cx * m_rx
END FUNCTION
' =====================================================================================

' =====================================================================================
' Scales a vertical coordinate according the DPI setting.
' =====================================================================================
PRIVATE FUNCTION CWindow.ScaleY (BYVAL cy AS SINGLE) AS SINGLE
   FUNCTION = cy * m_ry
END FUNCTION
' =====================================================================================

' =====================================================================================
' Unscales an horizontal coordinate according the DPI setting.
' =====================================================================================
PRIVATE FUNCTION CWindow.UnScaleX (BYVAL cx AS SINGLE) AS SINGLE
   FUNCTION = cx / m_rx
END FUNCTION
' =====================================================================================

' =====================================================================================
' Unscales a vertical coordinate according the DPI setting.
' =====================================================================================
PRIVATE FUNCTION CWindow.UnScaleY (BYVAL cy AS SINGLE) AS SINGLE
   FUNCTION = cy / m_ry
END FUNCTION
' =====================================================================================

' =====================================================================================
' Returns the unscaled width of the window
' =====================================================================================
PRIVATE PROPERTY CWindow.Width () AS LONG
   DIM rc AS RECT
   ..GetWindowRect m_hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Right - rc.Left) / m_rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the unscaled height of the window
' =====================================================================================
PRIVATE PROPERTY CWindow.Height () AS LONG
   DIM rc AS RECT
   ..GetWindowRect m_hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Bottom - rc.Top) / m_ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the unscaled x-coordinate of the window relative to the screen.
' =====================================================================================
PRIVATE PROPERTY CWindow.ScreenX () AS LONG
   DIM rc AS RECT
   ' // Get the dimensions of the window
   ..GetWindowRect(m_hwnd, @rc)
   ' // Convert the coordinates to be relative to the parent
   ..MapWindowPoints(HWND_DESKTOP, ..GetParent(m_hwnd), CAST(POINT PTR, @rc), 2)
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = rc.Left / m_rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the unscaled y-coordinate of the window relative to the screen.
' =====================================================================================
PRIVATE PROPERTY CWindow.ScreenY () AS LONG
   DIM rc AS RECT
   ' // Get the dimensions of the window
   ..GetWindowRect(m_hwnd, @rc)
   ' // Convert the coordinates to be relative to the parent
   ..MapWindowPoints(HWND_DESKTOP, ..GetParent(m_hwnd), CAST(POINT PTR, @rc), 2)
   ' // Divide by m_ry to make the result High DPI aware
   PROPERTY = rc.Top / m_ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the client width of the window
' =====================================================================================
PRIVATE PROPERTY CWindow.ClientWidth () AS LONG
   DIM rc AS RECT
   ..GetClientRect m_hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Right - rc.Left) / m_rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the client height of the window
' =====================================================================================
PRIVATE PROPERTY CWindow.ClientHeight () AS LONG
   DIM rc AS RECT
   ..GetClientRect m_hwnd, @rc
   ' // Divide by m_ry to make the result High DPI aware
   PROPERTY = (rc.Bottom - rc.Top) / m_ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the width of the specified window
' =====================================================================================
PRIVATE PROPERTY CWindow.ControlWidth (BYVAL hwnd AS HWND) AS LONG
   DIM rc AS RECT
   ..GetWindowRect hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Right - rc.Left) / m_rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the height of the specified window
' =====================================================================================
PRIVATE PROPERTY CWindow.ControlHeight (BYVAL hwnd AS HWND) AS LONG
   DIM rc AS RECT
   ..GetWindowRect hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Bottom - rc.Top) / m_ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the client width of the specified window
' =====================================================================================
PRIVATE PROPERTY CWindow.ControlClientWidth (BYVAL hwnd AS HWND) AS LONG
   DIM rc AS RECT
   ..GetClientRect hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Right - rc.Left) / m_rx
END PROPERTY
' =====================================================================================

' =====================================================================================
' Returns the client height of the specified window
' =====================================================================================
PRIVATE PROPERTY CWindow.ControlClientHeight (BYVAL hwnd AS HWND) AS LONG
   DIM rc AS RECT
   ..GetClientRect hwnd, @rc
   ' // Divide by m_rx to make the result High DPI aware
   PROPERTY = (rc.Bottom - rc.Top) / m_ry
END PROPERTY
' =====================================================================================

' =====================================================================================
' Retrieves the dimensions of the bounding rectangle of the main window.
' =====================================================================================
PRIVATE SUB CWindow.GetWindowRect OVERLOAD (BYVAL lpRect AS LPRECT)
   IF lpRect = NULL THEN EXIT SUB
   ..GetWindowRect(m_hwnd, lpRect)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   lpRect->Left   /= m_rx
   lpRect->Right  /= m_rx
   lpRect->Top    /= m_ry
   lpRect->Bottom /= m_ry
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CWindow.GetWindowRect OVERLOAD () AS RECT
   DIM rc AS RECT
   ..GetWindowRect(m_hwnd, @rc)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   rc.Left   /= m_rx
   rc.Right  /= m_rx
   rc.Top    /= m_ry
   rc.Bottom /= m_ry
   FUNCTION = rc
END FUNCTION
' =====================================================================================

' =====================================================================================
' Retrieves the coordinates of the main window's client area.
' =====================================================================================
PRIVATE SUB CWindow.GetClientRect OVERLOAD (BYVAL lpRect AS LPRECT)
   IF lpRect = NULL THEN EXIT SUB
   ..GetClientRect(m_hwnd, lpRect)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   lpRect->Left   /= m_rx
   lpRect->Right  /= m_rx
   lpRect->Top    /= m_ry
   lpRect->Bottom /= m_ry
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CWindow.GetClientRect OVERLOAD () AS RECT
   DIM rc AS RECT
   ..GetClientRect(m_hwnd, @rc)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   rc.Left   /= m_rx
   rc.Right  /= m_rx
   rc.Top    /= m_ry
   rc.Bottom /= m_ry
   FUNCTION = rc
END FUNCTION
' =====================================================================================

' =====================================================================================
' Retrieves the dimensions of the bounding rectangle of the specified window.
' =====================================================================================
PRIVATE SUB CWindow.GetControlWindowRect (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
   IF lpRect = NULL THEN EXIT SUB
   ..GetWindowRect(hwnd, lpRect)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   lpRect->Left   /= m_rx
   lpRect->Right  /= m_rx
   lpRect->Top    /= m_ry
   lpRect->Bottom /= m_ry
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CWindow.GetControlWindowRect (BYVAL hwnd AS HWND) AS RECT
   DIM rc AS RECT
   ..GetWindowRect(hwnd, @rc)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   rc.Left   /= m_rx
   rc.Right  /= m_rx
   rc.Top    /= m_ry
   rc.Bottom /= m_ry
   FUNCTION = rc
END FUNCTION
' =====================================================================================

' =====================================================================================
' Retrieves the dimensions of a window's client area.
' =====================================================================================
PRIVATE SUB CWindow.GetControlClientRect OVERLOAD (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
   IF lpRect = NULL THEN EXIT SUB
   ..GetClientRect(hwnd, lpRect)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   lpRect->Left   /= m_rx
   lpRect->Right  /= m_rx
   lpRect->Top    /= m_ry
   lpRect->Bottom /= m_ry
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CWindow.GetControlClientRect OVERLOAD (BYVAL hwnd AS HWND) AS RECT
   DIM rc AS RECT
   ..GetClientRect(hwnd, @rc)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   rc.Left   /= m_rx
   rc.Right  /= m_rx
   rc.Top    /= m_ry
   rc.Bottom /= m_ry
   FUNCTION = rc
END FUNCTION
' =====================================================================================

' =====================================================================================
' Retrieves the size of the work area on the primary display monitor. The work area is the
' portion of the screen not obscured by the system taskbar or by application desktop toolbars.
' =====================================================================================
PRIVATE SUB CWindow.GetWorkArea OVERLOAD (BYVAL lpRect AS LPRECT)
   IF lpRect = NULL THEN EXIT SUB
   SystemParametersInfoW(SPI_GETWORKAREA, 0, lpRect, 0)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   lpRect->Left   /= m_rx
   lpRect->Right  /= m_rx
   lpRect->Top    /= m_ry
   lpRect->Bottom /= m_ry
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CWindow.GetWorkArea OVERLOAD () AS RECT
   DIM rc AS RECT
   SystemParametersInfoW(SPI_GETWORKAREA, 0, @rc, 0)
   ' // Divide by m_rx and m_ry to make the result High DPI aware
   rc.Left   /= m_rx
   rc.Right  /= m_rx
   rc.Top    /= m_ry
   rc.Bottom /= m_ry
   FUNCTION = rc
END FUNCTION
' =====================================================================================

' =====================================================================================
' Retrieves a handle to the child control specified by its identifier.
' =====================================================================================
PRIVATE FUNCTION CWindow.ControlHandle (BYVAL cID AS LONG) AS HWND
   FUNCTION = ..GetDlgItem(m_hwnd, cID)
END FUNCTION
' =====================================================================================

' ========================================================================================
' Retrieves the window styles of the specified control
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlGetStyle (BYVAL hWnd AS HWND) AS LONG_PTR
   RETURN GetWindowLongPtrW(hWnd, GWL_STYLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended window styles of the specified control
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlGetExStyle (BYVAL hWnd AS HWND) AS LONG_PTR
   RETURN GetWindowLongPtrW(hWnd, GWL_EXSTYLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the window styles of the specified control
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlSetStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldStyle AS LONG_PTR = GetWindowLongPtrW(hWnd, GWL_STYLE)
   SetWindowLongPtrW(hWnd, GWL_STYLE, dwStyle)
   SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the window extended styles
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlSetExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldExStyle AS LONG_PTR = GetWindowLongPtrW(hWnd, GWL_EXSTYLE)
   SetWindowLongPtrW(hWnd, GWL_EXSTYLE, dwExStyle)
   SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldExStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a new style to the specified control.
' - hwnd  = Window handle
' - dwStyle = Style to add
' Return value:
'   The previous window styles
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlAddStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldStyle AS LONG_PTR = GetWindowLongPtrW(hWnd, GWL_STYLE)
   SetWindowLongPtrW(hWnd, GWL_STYLE, dwOldStyle OR dwStyle)
   SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a new extended style to the specified control.
' - hwnd  = Window handle
' - dwExStyle = Style to add
' Return value:
'   The previous extended window styles
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlAddExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldExStyle AS LONG_PTR = GetWindowLongPtrW(hWnd, GWL_EXSTYLE)
   SetWindowLongPtrW(hWnd, GWL_EXSTYLE, dwOldExStyle OR dwExStyle)
   SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldExStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an style from the specified control.
' - hwnd  = Window handle
' - dwStyle = Style to remove
' Return value:
'   The previous window styles
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlRemoveStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldStyle AS LONG_PTR = GetWindowLongPtrW(hWnd, GWL_STYLE)
   SetWindowLongPtrW(hWnd, GWL_STYLE, dwOldStyle AND (NOT dwStyle))
   SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an extended style from the specified control.
' - hwnd  = Window handle
' - dwExStyle = Style to remove
' Return value:
'   The previous window styles
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlRemoveExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS DWORD) AS LONG_PTR
   DIM dwOldExStyle AS LONG_PTR = GetWindowLongPtrW(hWnd, GWL_EXSTYLE)
   SetWindowLongPtrW(hWnd, GWL_EXSTYLE, dwOldExStyle AND (NOT dwExStyle))
   SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldExStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resizes the window
' =====================================================================================
PRIVATE SUB CWindow.Resize
   ..SendMessageW m_hwnd, WM_SIZE, CAST(WPARAM, SIZE_RESTORED), MAKELONG(this.ClientWidth, this.ClientHeight)
END SUB
' =====================================================================================

' =====================================================================================
' Changes the size, position, and Z order of a child, pop-up, or top-level window.
' =====================================================================================
PRIVATE FUNCTION CWindow.SetWindowPos (BYVAL hwnd AS HWND, BYVAL hwndInsertAfter AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL uFlags AS UINT) AS BOOLEAN
   IF x <> 0 THEN x = x * m_rx
   IF y <> 0 THEN y = y * m_ry
   FUNCTION = ..SetWindowPos(hwnd, hwndInsertAfter, x, y, cx * m_rx, cy * m_ry, uFlags)
END FUNCTION
' =====================================================================================

' =====================================================================================
' Changes the position and dimensions of the specified window.
' =====================================================================================
PRIVATE FUNCTION CWindow.MoveWindow (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS BOOLEAN = TRUE) AS BOOLEAN
   IF x <> 0 THEN x = x * m_rx
   IF y <> 0 THEN y = y * m_ry
   FUNCTION = ..MoveWindow(hwnd, x, y, nWidth * m_rx, nHeight * m_ry, bRepaint)
END FUNCTION
' =====================================================================================

' ========================================================================================
' If you use dual (or even triple/quad) displays then you have undoubtedly encountered the
' following situation: You change the physical order of your displays, or otherwise
' reconfigure the logical ordering using your display software. This sometimes has the
' side-effect of changing your desktop coordinates from zero-based to negative starting
' coordinates (i.e. the top-left coordinate of your desktop changes from 0,0 to -1024,-768).
' This effects many Windows programs which restore their last on-screen position whenever
' they are started. Should the user reorder their display configuration this can sometimes
' result in a Windows program subsequently starting in an off-screen position (i.e. at a
' location that used to be visible) - and is now effectively invisible, preventing the
' user from closing it down or otherwise moving it back on-screen.
' The DialogForceVisibility method can be called at program start-time right after the
' main window has been created and positioned 'on-screen'. Should the window be positioned
' in an off-screen position, it is forced back onto the nearest display to its last
' position. The user will be unaware this is happening and won't even realise to thank you
' for keeping their user-interface visible, even though they changed their display
' settings.
' Source: http://www.catch22.net/tuts/tips2
' ========================================================================================
PRIVATE SUB CWindow.ForceVisibleDisplay
   ' // Check if the specified window-rectangle is visible on any display
   DIM rc AS RECT
   ..GetWindowRect(m_hwnd, @rc)
   IF MonitorFromRect(@rc, MONITOR_DEFAULTTONULL) <> NULL THEN EXIT SUB
   ' // Find the nearest display to the rectangle
   DIM hMonitor AS HMONITOR
   DIM mi AS MONITORINFO
   mi.cbSize = SIZEOF(mi)
   hMonitor = MonitorFromRect(@rc, MONITOR_DEFAULTTONEAREST)
   GetMonitorInfoW(hMonitor, @mi)
   ' // Center window rectangle
   rc.left = mi.rcWork.left + ((mi.rcWork.right - mi.rcWork.left) - (rc.right-rc.left)) \ 2
   rc.top = mi.rcWork.top + ((mi.rcWork.bottom - mi.rcWork.top) - (rc.bottom-rc.top)) \ 2
   ..SetWindowPos(m_hwnd, 0, rc.left, rc.top, 0, 0, SWP_NOACTIVATE OR SWP_NOZORDER OR SWP_NOSIZE)
END SUB
' ========================================================================================

' ========================================================================================
' Creates a High DPI aware logical font.
' - wszFaceName = The typeface name.
' - lPointSize = The point size.
' - lWeight = The weight of the font in the range 0 through 1000. For example, 400 is normal
'      and 700 is bold. If this value is zero, a default weight is used.
'      The following values are defined for convenience.
'      FW_DONTCARE (0), FW_THIN (100), FW_EXTRALIGHT (200), FW_ULTRALIGHT (200), FW_LIGHT (300),
'      FW_NORMAL (400), FW_REGULAR (400), FW_MEDIUM (500), FW_SEMIBOLD (600), FW_DEMIBOLD (600),
'      FW_BOLD (700), FW_EXTRABOLD (800), FW_ULTRABOLD (800), FW_HEAVY (900), FW_BLACK (900)
' - bItalic = Italic flag. CTRUE or FALSE
' - bUnderline = Underline flag. CTRUE or FALSE
' - bStrikeOut = StrikeOut flag. CTRUE or FALSE
' - bCharset = Charset.
'      The following values are predefined: ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET,
'      DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET,
'      MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET,
'      VIETNAMESE_CHARSET, JOHAB_CHARSET (Korean language edition of Windows), ARABIC_CHARSET and
'      HEBREW_CHARSET (Middle East language edition of Windows), THAI_CHARSET (Thai language
'      edition of Windows).
'      The OEM_CHARSET value specifies a character set that is operating-system dependent.
'      DEFAULT_CHARSET is set to a value based on the current system locale. For example, when
'      the system locale is English (United States), it is set as ANSI_CHARSET.
'      Fonts with other character sets may exist in the operating system. If an application uses
'      a font with an unknown character set, it should not attempt to translate or interpret
'      strings that are rendered with that font.
'      This parameter is important in the font mapping process. To ensure consistent results,
'      specify a specific character set. If you specify a typeface name in the lfFaceName member,
'      make sure that the lfCharSet value matches the character set of the typeface specified in lfFaceName.
' Return value: The handle of the font or NULL on failure.
' Remarks: The returned font must be destroyed with DeleteObject or the macro DeleteFont
' when no longer needed to prevent memory leaks.
' Usage examples:
'   hFont = CWindow.CreateFont("MS Sans Serif", 8, FW_NORMAL, , , , DEFAULT_CHARSET)
'   hFont = CWindow.CreateFont("Courier New", 10, FW_BOLD, , , , DEFAULT_CHARSET)
'   hFont = CWindow.CreateFont("Marlett", 8, FW_NORMAL, , , , SYMBOL_CHARSET)
' ========================================================================================
PRIVATE FUNCTION CWindow.CreateFont ( _
   BYREF wszFaceName AS WSTRING, _                  ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _                     ' __in Point size
   BYVAL lWeight     AS LONG = 0, _                 ' __in Font weight(bold etc.)
   BYVAL bItalic     AS UBYTE = FALSE, _            ' __in CTRUE = italic
   BYVAL bUnderline  AS UBYTE = FALSE, _            ' __in CTRUE = underline
   BYVAL bStrikeOut  AS UBYTE = FALSE, _            ' __in CTRUE = strikeout
   BYVAL bCharSet    AS UBYTE = DEFAULT_CHARSET _   ' __in character set
   ) AS HFONT                                       ' Handle of font or NULL on failure.

   DIM tlfw AS LOGFONTW
   DIM wstrFaceName AS WSTRING * LF_FACESIZE
   IF VARPTR(wszFacename) <> NULL AND LEN(wszFacename) > 0 THEN wstrFaceName = wszFaceName ELSE wstrFaceName = m_wszDefaultFontName

   ' // The result must be 1, unless the programmer has set a different DPI with the set DPI property
   DIM hDC AS HDC = ..GetDC(HWND_DESKTOP)
   lPointSize = (lPointSize * m_DPI) \ ..GetDeviceCaps(hDC, LOGPIXELSY)

   tlfw.lfHeight         = -MulDiv(lPointSize, ..GetDeviceCaps(hDC, LOGPIXELSY), 72)  ' logical font height
   tlfw.lfWidth          =  0                                                        ' average character width
   tlfw.lfEscapement     =  0                                                        ' escapement
   tlfw.lfOrientation    =  0                                                        ' orientation angles
   tlfw.lfWeight         =  lWeight                                                  ' font weight
   tlfw.lfItalic         =  bItalic                                                  ' italic(CTRUE/FALSE)
   tlfw.lfUnderline      =  bUnderline                                               ' underline(CTRUE/FALSE)
   tlfw.lfStrikeOut      =  bStrikeOut                                               ' strikeout(CTRUE/FALSE)
   tlfw.lfCharSet        =  bCharset                                                 ' character set
   tlfw.lfOutPrecision   =  OUT_TT_PRECIS                                            ' output precision
   tlfw.lfClipPrecision  =  CLIP_DEFAULT_PRECIS                                      ' clipping precision
   tlfw.lfQuality        =  DEFAULT_QUALITY                                          ' output quality
   tlfw.lfPitchAndFamily =  FF_DONTCARE                                              ' pitch and family
   tlfw.lfFaceName       =  wstrFaceName                                             ' typeface name

   ..ReleaseDC HWND_DESKTOP, hDC
   FUNCTION = ..CreateFontIndirectW(@tlfw)

END FUNCTION
' ========================================================================================

' =====================================================================================
' Creates a High DPI aware logical font and sets it as the default font.
' Usage examples:
'   CWindow.SetFont("MS Sans Serif", 8, FW_NORMAL, , , , DEFAULT_CHARSET)
'   CWindow.SetFont("Courier New", 10, FW_BOLD, , , , DEFAULT_CHARSET)
'   CWindow.SetFont("Marlett", 8, FW_NORMAL, , , , SYMBOL_CHARSET)
' Return Value = TRUE or FALSE.
' =====================================================================================
PRIVATE FUNCTION CWindow.SetFont ( _
   BYREF wszFaceName AS WSTRING, _                  ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _                     ' __in Point size
   BYVAL lWeight     AS LONG = 0, _                 ' __in Font weight(bold etc.)
   BYVAL bItalic     AS UBYTE = FALSE, _            ' __in CTRUE = italic
   BYVAL bUnderline  AS UBYTE = FALSE, _            ' __in CTRUE = underline
   BYVAL bStrikeOut  AS UBYTE = FALSE, _            ' __in CTRUE = strikeout
   BYVAL bCharSet    AS UBYTE = DEFAULT_CHARSET _   ' __in character set
   ) AS BOOLEAN                                     ' Result

   DIM hFont AS HFONT
   DIM wstrFaceName AS WSTRING * LF_FACESIZE
   IF VARPTR(wszFacename) <> NULL AND LEN (wszFacename) > 0 THEN wstrFaceName = wszFaceName ELSE wstrFaceName = m_wszDefaultFontName
   hFont = this.CreateFont(wstrFaceName, lPointSize, lWeight, bItalic, bUnderline, bStrikeOut, bCharSet)
   IF hFont THEN
      IF m_hFont THEN ..DeleteObject m_hFont
      m_hFont = hFont
      m_wszDefaultFontName = wstrFaceName
      m_DefaultFontSize = lPointSize
      FUNCTION = TRUE
   ELSE
      FUNCTION = FALSE
   END IF

END FUNCTION
' =====================================================================================

' =====================================================================================
' Adds a control to the window
' =====================================================================================
PRIVATE FUNCTION CWindow.AddControl ( _
   BYREF wszClassName AS WSTRING, _                       ' // Class name
   BYVAL hParent AS HWND = NULL, _                        ' // Parent window handle
   BYVAL cID AS LONG_PTR = 0, _                           ' // Control identifier
   BYREF wszTitle AS WSTRING = "", _                      ' // Control caption
   BYVAL x AS LONG = 0, _                                 ' // Horizontal position
   BYVAL y AS LONG = 0, _                                 ' // Vertical position
   BYVAL nWidth AS LONG = 0, _                            ' // Control width
   BYVAL nHeight AS LONG = 0, _                           ' // Control height
   BYVAL dwStyle AS LONG = -1, _                          ' // Control style
   BYVAL dwExStyle AS LONG = -1, _                        ' // Extended style
   BYVAL lpParam AS LONG_PTR = 0 _                        ' // Pointer to custom data
   ) AS HWND                                              ' // Control handle

   DIM hCtl AS HWND
   IF LEN(wszClassName) = 0 THEN EXIT FUNCTION
   IF hParent = NULL THEN hParent = m_hwnd
   DIM bSetFont AS LONG = CTRUE
   ' // Window styles
   DIM wsClassName AS WSTRING * 260
   wsClassName = wszClassName

   SELECT CASE UCASE(wsClassName)
      CASE "BUTTON"
         ' Adds a button to the window
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER
         IF dwStyle = BS_FLAT THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER OR BS_FLAT
         IF dwStyle = BS_DEFPUSHBUTTON THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_DEFPUSHBUTTON
         IF dwStyle = BS_BITMAP THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_BITMAP
         IF dwStyle = BS_ICON THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_ICON
         IF dwStyle = BS_OWNERDRAW THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_OWNERDRAW
         #if _WIN32_WINNT = &h0602
         IF dwStyle = BS_SPLITBUTTON THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_SPLITBUTTON
         IF dwStyle = BS_DEFSPLITBUTTON THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_DEFSPLITBUTTON
         IF dwStyle = BS_COMMANDLINK THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_COMMANDLINK
         IF dwStyle = BS_DEFCOMMANDLINK THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_DEFCOMMANDLINK
         #endif
      CASE "CUSTOMBUTTON", "OWNERDRAWBUTTON"
         ' Adds an ownerdraw button to the window.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_OWNERDRAW
      CASE "RADIOBUTTON", "OPTION"
         ' Adds a radio button to the window.
         ' Note: In PowerBASIC this control is called "Option".
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_AUTORADIOBUTTON OR BS_LEFT OR BS_VCENTER
         IF dwStyle = WS_GROUP THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_AUTORADIOBUTTON OR BS_LEFT OR BS_VCENTER OR WS_GROUP
      CASE "CHECKBOX"
         ' Adds a checkbox to the window.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_AUTOCHECKBOX OR BS_LEFT OR BS_VCENTER
      CASE "CHECK3STATE"
         ' Adds a 3 state checkbox to the window.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_AUTO3STATE OR BS_LEFT OR BS_VCENTER
      CASE "LABEL"
         ' Adds a label to the window.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR SS_LEFT OR SS_NOTIFY
      CASE "BITMAPLABEL"
         ' Adds an image label to the window.
         ' You must delete the bitmap before the application ends.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_GROUP OR SS_BITMAP
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
         bSetFont = FALSE
      CASE "ICONLABEL"
         ' Adds an image label to the window.
         ' You must delete the icon before the application ends.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_GROUP OR SS_ICON
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
         bSetFont = FALSE
      CASE "BITMAPBUTTON"
         ' Adds an image button to the window.
         ' You must delete the bitmap before the application ends.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_BITMAP
      CASE "ICONBUTTON"
         ' Adds an image button to the window.
         ' You must delete the icon before the application ends.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_ICON
      CASE "CUSTOMLABEL"
         ' Adds an ownerdraw label to the window.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_GROUP OR SS_OWNERDRAW
         bSetFont = FALSE
      CASE "FRAME", "FRAMEWINDOW"
         ' Adds a frame to the window.
         ' Note: This is not the same that PowerBASIC DDT's Frame control, that in fact is a Group Box.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_CLIPSIBLINGS OR WS_GROUP OR SS_BLACKFRAME
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
         bSetFont = FALSE
      CASE "GROUPBOX"
         ' Adds a group box to the window.
         ' Note: This is the same that DDT's frame control.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_CLIPSIBLINGS OR WS_GROUP OR BS_GROUPBOX
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
      CASE "LINE"
         ' Adds an horizontal line to the window
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR SS_ETCHEDFRAME
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
         bSetFont = FALSE
      CASE "EDIT", "TEXTBOX"
         ' Adds an edit control to the window.
         wsClassName = "Edit"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR ES_AUTOHSCROLL
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "EDITMULTILINE", "MULTILINETEXTBOX"
         ' Adds an edit control to the window.
         wsClassName = "Edit"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR WS_VSCROLL OR ES_LEFT OR ES_AUTOHSCROLL OR ES_MULTILINE OR ES_NOHIDESEL OR ES_WANTRETURN
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "COMBOBOX"
         ' Adds a combo box to the window.
         IF dwStyle = -1 THEN dwStyle = WS_CHILD OR WS_VISIBLE OR WS_VSCROLL OR WS_BORDER OR WS_TABSTOP OR CBS_DROPDOWN OR CBS_HASSTRINGS OR CBS_SORT
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "COMBOBOXEX", "COMBOBOXEX32"
         ' Adds a combo box ex to the window.
         wsClassName = "ComboBoxEx32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_BORDER OR WS_TABSTOP OR CBS_DROPDOWNLIST
      CASE "LISTBOX"
         ' Adds a list box to the window.
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_HSCROLL OR WS_VSCROLL OR WS_BORDER OR WS_TABSTOP OR LBS_STANDARD OR LBS_HASSTRINGS OR LBS_SORT OR LBS_NOTIFY
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "PROGRESSBAR", "MSCTLS_PROGRESS32"
         ' Adds a progress bar to the window.
         wsClassName = "msctls_progress32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE
         bSetFont = FALSE
      CASE "HEADER", "SYSHEADER32"
         ' Adds an header control to the window.
         wsClassName = "SysHeader32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR CCS_TOP OR HDS_HORZ OR HDS_BUTTONS
      CASE "TREEVIEW", "SYSTREEVIEW32"
         ' Adds a tree view control to the window.
         wsClassName = "SysTreeView32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_BORDER OR WS_TABSTOP OR TVS_HASBUTTONS OR TVS_HASLINES OR TVS_LINESATROOT OR TVS_SHOWSELALWAYS
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "LISTVIEW", "SYSLISTVIEW32"
         ' Adds a list view control to the window.
         wsClassName = "SysListView32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_CLIPCHILDREN OR WS_TABSTOP OR LVS_REPORT OR LVS_SHOWSELALWAYS OR LVS_SHAREIMAGELISTS OR LVS_AUTOARRANGE OR LVS_EDITLABELS OR LVS_ALIGNTOP
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "TOOLBAR", "TOOLBARWINDOW32"
         ' Adds a toolbar control to the window.
         wsClassName = "ToolbarWindow32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR CCS_TOP OR WS_BORDER OR TBSTYLE_FLAT OR TBSTYLE_TOOLTIPS
      CASE "REBAR", "REBARWINDOW32"
         ' Adds a rebar control to the window.
         wsClassName = "ReBarWindow32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_BORDER OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR CCS_NODIVIDER OR RBS_VARHEIGHT OR RBS_BANDBORDERS
      CASE "DATETIMEPICKER", "SYSDATETIMEPICK32"
         ' Adds a date time picker control to the window.
         wsClassName = "SysDateTimePick32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR DTS_SHORTDATEFORMAT
      CASE "MONTHCALENDAR", "MONTHCAL", "SYSMONTHCAL32"
         ' Adds a month calendar control to the window.
         wsClassName = "SysMonthCal32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "IPADDRESS", "SYSIPADDRESS32"
         ' Adds an IPAddress control to the window.
         wsClassName = "SysIPAddress32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "HOTKEY", "MSCTLS_HOTKEY32"
         ' Adds an hotkey control to the window.
         wsClassName = "msctls_hotkey32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
      CASE "ANIMATE", "ANIMATION", "SYSANIMATE32"
         ' Adds an animation control to the window.
         wsClassName = "SysAnimate32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR ACS_TRANSPARENT
      CASE "SYSLINK"
         ' Adds a SysLink control to the window.
         ' Note: The SysLink control is defined in the ComCtl32.dll version 6 and requires a manifest
         ' or directive that specifies that version 6 of the DLL should be used if it is available.
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP
         bSetFont = FALSE
      CASE "PAGER", "SYSPAGER"
         ' Adds a Pager control to the window.
         wsClassName = "SysPager"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR PGS_HORZ
         bSetFont = FALSE
      CASE "TAB", "TABCONTROL", "SYSTABCONTROL32"
         ' Adds a Tab control to the window.
         wsClassName = "SysTabControl32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_GROUP OR WS_TABSTOP OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR TCS_TABS OR TCS_SINGLELINE OR TCS_RAGGEDRIGHT
         IF dwExStyle = -1 THEN dwExStyle = 0
         dwExStyle =  dwExStyle OR WS_EX_CONTROLPARENT
      CASE "STATUSBAR", "MSCTLS_STATUSBAR32"
         ' Adds a StatusBar control to the window.
         wsClassName = "msctls_statusbar32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR CCS_BOTTOM OR SBARS_SIZEGRIP
      CASE "SIZEBAR", "SIZEBOX", "SIZEGRIP"
         ' Adds a size box to the window.
         wsClassName = "Scrollbar"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR SBS_SIZEGRIP OR SBS_SIZEBOXBOTTOMRIGHTALIGN
         bSetFont = FALSE
         nWidth = GetSystemMetrics(SM_CXVSCROLL)
         nHeight = GetSystemMetrics(SM_CYHSCROLL)
         DIM rcClient AS RECT = this.GetClientRect
         x = rcClient.Right - nWidth
         y = rcClient.Bottom - nHeight
         bSetFont = FALSE
      CASE "HSCROLLBAR"
         ' Adds an horizontal scroll bar to the window.
         wsClassName = "Scrollbar"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR SBS_HORZ
         bSetFont = FALSE
      CASE "VSCROLLBAR"
         ' Adds a vertical scroll bar to the window.
         wsClassName = "Scrollbar"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR SBS_VERT
         bSetFont = FALSE
      CASE "TRACKBAR", "MSCTLS_TRACKBAR32", "SLIDER"
         wsClassName = "msctls_trackbar32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR TBS_AUTOTICKS OR TBS_HORZ OR TBS_BOTTOM OR TBS_TOOLTIPS
         bSetFont = FALSE
      CASE "UPDOWN", "MSCTLS_UPDOWN32"
         wsClassName = "msctls_updown32"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR UDS_WRAP OR UDS_ARROWKEYS OR UDS_ALIGNRIGHT OR UDS_SETBUDDYINT
         bSetFont = FALSE
      CASE "RICHEDIT", "RICHEDIT50W"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR WS_HSCROLL OR WS_VSCROLL OR ES_AUTOHSCROLL OR ES_AUTOVSCROLL OR ES_MULTILINE OR ES_WANTRETURN OR ES_NOHIDESEL OR ES_SAVESEL
'         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
         IF dwExStyle = -1 THEN dwExStyle = 0
         wsClassName = "RichEdit50W"
         IF m_hRichEditLib = 0 THEN m_hRichEditLib = CAST(HMODULE, LoadLibraryW("MSFTEDIT.DLL"))
   END SELECT
   ' // Don't allow negative values for the styles
   IF dwStyle = -1 THEN dwStyle = 0
   IF dwExStyle = -1 THEN dwExStyle = 0
   ' // Make sure that the control has the WS_CHILD style
   dwStyle = dwStyle OR WS_CHILD
   ' // Create the control
   hCtl = ..CreateWindowExW(dwExStyle, wsClassName, wszTitle, dwStyle, x * m_rx, y * m_ry, nWidth * m_rx, nHeight * m_ry, _
      hParent, CAST(HMENU, cID), m_hInstance, CAST(LPVOID, lpParam))
   IF hCtl = NULL THEN EXIT FUNCTION
   ' // Set the font
   IF m_hFont THEN
      IF bSetFont THEN ..SendMessageW hCtl, WM_SETFONT, CAST(WPARAM, m_hFont), CTRUE
   END IF
   SELECT CASE UCASE(wszClassName)
      CASE "LISTBOX"
         ' // Adjust the height of the control so that the integral height
         ' // is based on the new font rather than the default SYSTEM_FONT
         SetWindowPos hCtl, NULL, x, y, nWidth, nHeight, SWP_NOZORDER
      CASE "DATETIMEPICKER", "SYSDATETIMEPICK32"
         ' // Sets the font to be used by the date and time picker control's child month calendar control.
         IF m_hFont THEN SendMessageW hCtl, DTM_SETMCFONT, CAST(WPARAM, m_hFont), CTRUE
      CASE "PROGRESSBAR", "MSCTLS_PROGRESS32"
         ' // Set the default range
         ..SendMessageW hCtl, PBM_SETRANGE32, 0, 100
         ' // Set the default initial value
         ..SendMessageW hCtl, PBM_SETPOS, 0, 0
      CASE "TRACKBAR", "MSCTLS_TRACKBAR32"
         ' // Set the default range values
         ..SendMessageW hCtl, TBM_SETRANGEMIN, CTRUE, 0
         ..SendMessageW hCtl, TBM_SETRANGEMAX, CTRUE, 100
         ' // Set the default page size
         ..SendMessageW hCtl, TBM_SETPAGESIZE, 0, 10
      CASE "UPDOWN", "MSCTLS_UPDOWN32"
         ' // Set the default base
         ..SendMessageW hCtl, UDM_SETBASE, 10, 0
         ' // Set the default range values
         ..SendMessageW hCtl, UDM_SETRANGE32, 100, 0
         ' // Set the default initial value
         ..SendMessageW hCtl, UDM_SETPOS32, 0, 0
         ' // Correct for Windows using a default size for the updown control
         this.SetWindowPos hCtl, NULL, x, y, nWidth, nHeight, SWP_NOZORDER
      CASE "HSCROLLBAR", "VSCROLLBAR"
         ' // Initialize the scroll bar with default values
         DIM tsi AS SCROLLINFO
         tsi.cbSize = SIZEOF(tsi)
         tsi.fMask  = SIF_PAGE OR SIF_POS OR SIF_RANGE
         tsi.nMin   = 0
         tsi.nMax   = 100
         tsi.nPage  = 0
         tsi.nPos   = 0
         ..SetScrollInfo hCtl, SB_CTL, @tsi, CTRUE
      CASE "TOOLBAR", "TOOLBARWINDOW32"
         ' // Set the button size
         DIM AS LONG nButtonWidth, nButtonHeight
         nButtonWidth = LOWORD(.SendMessageW(hCtl, TB_GETBUTTONSIZE, 0, 0)) * m_rx
         nButtonHeight = HIWORD(.SendMessageW(hCtl, TB_GETBUTTONSIZE, 0, 0)) * m_ry
         ..SendMessageW hCtl, TB_SETBUTTONSIZE, 0, MAKELONG(nButtonWidth, nButtonHeight)
         ' // Send this message for backward compatibility
         ..SendMessageW hCtl, TB_BUTTONSTRUCTSIZE, SIZEOF(TBBUTTON), 0
      CASE "BITMAPLABEL"
         ' // Loads the image
         DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
         IF LEFT(wszTitle, 1) = "#" THEN
            wID = VAL(MID(wszTitle, 2))
            dwID = MAKELONG(wID, 0)
            hImage = ..LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR)
         ELSE
            hImage = ..LoadImageW(m_hInstance, wszTitle, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR)
         END IF
         IF hImage THEN ..SendMessageW(hCtl, STM_SETIMAGE, IMAGE_BITMAP, CAST(LPARAM, hImage))
      CASE "ICONLABEL"
         ' // Loads the image
         DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
         IF LEFT(wszTitle, 1) = "#" THEN
            wID = VAL(MID(wszTitle, 2))
            dwID = MAKELONG(wID, 0)
            hImage = ..LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
         ELSE
            hImage = ..LoadImageW(m_hInstance, wszTitle, IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
         END IF
         IF hImage THEN ..SendMessageW(hCtl, STM_SETIMAGE, IMAGE_ICON, CAST(LPARAM, hImage))
      CASE "BITMAPBUTTON"
         ' // Loads the image
         DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
         IF LEFT(wszTitle, 1) = "#" THEN
            wID = VAL(MID(wszTitle, 2))
            dwID = MAKELONG(wID, 0)
            hImage = ..LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR)
         ELSE
            hImage = ..LoadImageW(m_hInstance, wszTitle, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR)
         END IF
         IF hImage THEN ..SendMessageW(hCtl, BM_SETIMAGE, IMAGE_BITMAP, CAST(LPARAM, hImage))
      CASE "ICONBUTTON"
         ' // Loads the image
         DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
         IF LEFT(wszTitle, 1) = "#" THEN
            wID = VAL(MID(wszTitle, 2))
            dwID = MAKELONG(wID, 0)
            hImage = ..LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
         ELSE
            hImage = ..LoadImageW(m_hInstance, wszTitle, IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
         END IF
         IF hImage THEN ..SendMessageW(hCtl, BM_SETIMAGE, IMAGE_ICON, CAST(LPARAM, hImage))
   END SELECT
   FUNCTION = hCtl
END FUNCTION
' =====================================================================================

' =====================================================================================
' Installs or updates a control subclass callback.
' =====================================================================================
PRIVATE FUNCTION CWindow.SetControlSubclass (BYVAL hCtl AS HWND, BYVAL pfnSubclass AS ANY PTR, BYVAL uIdSubclass AS UINT_PTR, BYVAL dwRefData AS ANY PTR) AS BOOLEAN
   IF hCtl = NULL OR hCtl = m_hwnd THEN RETURN FALSE
   RETURN SetWindowSubclass(hCtl, CAST(SUBCLASSPROC, pfnSubclass), uIdSubclass, CAST(DWORD_PTR, dwRefData))
END FUNCTION
' =====================================================================================
' =====================================================================================
PRIVATE FUNCTION CWindow.SetControlSubclass (BYVAL hCtl AS HWND, BYVAL pfnSubclass AS ANY PTR, BYVAL uIdSubclass AS UINT_PTR, BYVAL dwRefData AS DWORD_PTR) AS BOOLEAN
   IF hCtl = NULL OR hCtl = m_hwnd THEN RETURN FALSE
   RETURN SetWindowSubclass(hCtl, CAST(SUBCLASSPROC, pfnSubclass), uIdSubclass, dwRefData)
END FUNCTION
' =====================================================================================


' ########################################################################################
'                            *** CWINDOW stabilization  ***
' ########################################################################################

' ========================================================================================
' Makes the main window stabilized (non-closeable).
' ========================================================================================
PRIVATE FUNCTION CWindow.Stabilize () AS BOOLEAN
   ' // Get the system menu handle
   DIM hMenu AS HMENU = GetSystemMenu(m_hwnd, FALSE)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Get the number of menu items
   DIM cbItems AS LONG = GetMenuItemCount(hMenu)
   IF cbItems = 0 THEN RETURN FALSE
   ' // Remove the close menu item
   IF RemoveMenu(hMenu, cbItems - 1, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Remove the separator line
   IF RemoveMenu(hMenu, cbItems - 2, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Redraw the menu (this refreshes the caption bar, dimming the X button)
   DrawMenuBar(m_hwnd)
   ' // Flags the dialog as stabilized
   m_IsStabilized = TRUE
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Makes a dialog non stable (closeable).
' ========================================================================================
PRIVATE FUNCTION CWindow.NonStable () AS BOOLEAN
   GetSystemMenu(m_hwnd, TRUE)
   DrawMenuBar(m_hwnd)
   m_IsStabilized = FALSE
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns true if the dialog is stabilized; otherwise, false.
' ========================================================================================
PRIVATE FUNCTION CWindow.IsStabilized () AS BOOLEAN
   RETURN m_IsStabilized
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns true if the dialog is non stable; otherwise, false.
' ========================================================================================
PRIVATE FUNCTION CWindow.IsNonStable () AS BOOLEAN
   RETURN NOT m_IsStabilized
END FUNCTION
' ========================================================================================

' ########################################################################################
'                               *** ACCELERATOR TABLE ***
' ########################################################################################

' =====================================================================================
' Gets/Sets the accelerator table handle
' =====================================================================================
PRIVATE PROPERTY CWindow.AccelHandle () AS HACCEL
   PROPERTY = m_hAccel
END PROPERTY
' =====================================================================================
' =====================================================================================
PRIVATE PROPERTY CWindow.AccelHandle (BYVAL hAccel AS HACCEL)
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) > -1 THEN ERASE m_rgAccelEntries
   m_hAccel = hAccel
END PROPERTY
' =====================================================================================
' =====================================================================================
' Adds an accelerator key to the table.
' =====================================================================================
PRIVATE SUB CWindow.AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYVAL wKey AS WORD, BYVAL cmd AS WORD)
   REDIM PRESERVE m_rgAccelEntries(UBOUND(m_rgAccelEntries) + 1) AS ACCEL
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).fvirt = fvirt
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).key = wKey
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).cmd = cmd
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE SUB CWindow.AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYREF wszKey AS WSTRING, BYVAL cmd AS WORD)
   REDIM PRESERVE m_rgAccelEntries(UBOUND(m_rgAccelEntries) + 1) AS ACCEL
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).fvirt = fvirt
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).key = ASC(wszKey)
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).cmd = cmd
END SUB
' =====================================================================================
' =====================================================================================
' Creates the accelerator table.
' =====================================================================================
PRIVATE FUNCTION CWindow.CreateAcceleratorTable () AS HACCEL
   IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) = -1 THEN EXIT FUNCTION
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   m_hAccel = ..CreateAcceleratorTableW(CAST(LPACCEL, @m_rgAccelEntries(0)), UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) + 1)
   FUNCTION = m_hAccel
END FUNCTION
' =====================================================================================
' =====================================================================================
' Destroys the accelerator table.
' =====================================================================================
PRIVATE SUB CWindow.DestroyAcceleratorTable
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) > -1 THEN ERASE m_rgAccelEntries
   m_hAccel = NULL
END SUB
' =====================================================================================

' ########################################################################################
'                             *** CONTROL'S USER DATA ***
' ########################################################################################

' ========================================================================================
' Gets the control user data item
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CWindow.GetUserDataItem (BYVAL cID AS LONG) AS LONG
   FUNCTION = -1
   Dim hCtl AS HWND = GetDlgItem(m_hWnd, cID)
   FOR i AS LONG = 0 TO UBOUND(m_rgCtrlUserData)
      IF m_rgCtrlUserData(i).hCtl = hCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetUserDataItem (BYVAL hCtl AS HWND) AS LONG
   FUNCTION = -1
   FOR i AS LONG = 0 TO UBOUND(m_rgCtrlUserData)
      IF m_rgCtrlUserData(i).hCtl = hCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the control's user data
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlSetUser (BYVAL cID AS LONG, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
   IF index < 0 OR index > 9 THEN RETURN FALSE
   DIM hCtl AS HWND = GetDlgItem(m_hWnd, CID)
   IF IsWindow(hCtl) = FALSE THEN RETURN FALSE
   ' // Check if the element already exists
   DIM nItem AS LONG = this.GetUserDataItem(cID)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgCtrlUserData(UBOUND(m_rgCtrlUserData) + 1) AS AFX_CTLUSERDATA
      nItem = UBOUND(m_rgCtrlUserData)
   END IF
   m_rgCtrlUserData(nItem).hCtl = hCtl
   m_rgCtrlUserData(nItem).Values(index) = userValue
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the control's user data
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlSetUser (BYVAL hCtl AS HWND, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
   IF index < 0 OR index > 9 THEN RETURN FALSE
   IF IsWindow(hCtl) = FALSE THEN RETURN FALSE
   ' // Check if the element already exists
   DIM nItem AS LONG = this.GetUserDataItem(hCtl)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgCtrlUserData(UBOUND(m_rgCtrlUserData) + 1) AS AFX_CTLUSERDATA
      nItem = UBOUND(m_rgCtrlUserData)
   END IF
   m_rgCtrlUserData(nItem).hCtl = hCtl
   m_rgCtrlUserData(nItem).Values(index) = userValue
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Gets the control's user data
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlGetUser (BYVAL cID AS LONG, BYVAL index AS LONG) AS LONG_PTR
   IF index < 0 OR index > 9 THEN RETURN FALSE
   DIM hCtl AS HWND = GetDlgItem(m_hWnd, cID)
   DIM nItem AS LONG = this.GetUserDataItem(cID)
   IF nItem > -1 THEN RETURN m_rgCtrlUserData(nItem).Values(index)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.ControlGetUser (BYVAL hwnd AS HWND, BYVAL index AS LONG) AS LONG_PTR
   IF index < 0 OR index > 9 THEN RETURN FALSE
   DIM nItem AS LONG = this.GetUserDataItem(hwnd)
   IF nItem > -1 THEN RETURN m_rgCtrlUserData(nItem).Values(index)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                             *** CONTROL'S CALLBACKs ***
' ########################################################################################

' ========================================================================================
' Gets the control callback pointer
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CWindow.GetControlCallbackItem (BYVAL cID AS LONG) AS LONG
   FUNCTION = -1
   Dim hCtl AS HWND = GetDlgItem(m_hWnd, cID)
   FOR i AS LONG = 0 TO UBOUND(m_rgCtrlCallbacks)
      IF m_rgCtrlCallbacks(i).hCtl = hCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetControlCallbackItem (BYVAL hCtl AS HWND) AS LONG
   FUNCTION = -1
   FOR i AS LONG = 0 TO UBOUND(m_rgCtrlCallbacks)
      IF m_rgCtrlCallbacks(i).hCtl = hCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the control callback pointer
' ========================================================================================
PRIVATE FUNCTION CWindow.SetControlCallback (BYVAL cID AS LONG, BYVAL pCallback AS ANY PTR) AS BOOLEAN
   DIM hCtl AS HWND = GetDlgItem(m_hWnd, CID)
   IF IsWindow(hCtl) = FALSE THEN RETURN FALSE
   ' // Check if the element already exists
   DIM nItem AS LONG = this.GetControlCallbackItem(cID)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgCtrlCallbacks(UBOUND(m_rgCtrlCallbacks) + 1) AS AFX_CTLCALLBACKS
      nItem = UBOUND(m_rgCtrlCallbacks)
   END IF
   m_rgCtrlCallbacks(nItem).hCtl = hCtl
   m_rgCtrlCallbacks(nItem).pCallback = pCallback
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.SetControlCallback (BYVAL hCtl AS HWND, BYVAL pCallback AS ANY PTR) AS BOOLEAN
   IF IsWindow(hCtl) = FALSE THEN RETURN FALSE
   ' // Check if the element already exists
   DIM nItem AS LONG = this.GetControlCallbackItem(hCtl)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgCtrlCallbacks(UBOUND(m_rgCtrlCallbacks) + 1) AS AFX_CTLCALLBACKS
      nItem = UBOUND(m_rgCtrlCallbacks)
   END IF
   m_rgCtrlCallbacks(nItem).hCtl = hCtl
   m_rgCtrlCallbacks(nItem).pCallback = pCallback
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Gets the control's user data
' ========================================================================================
PRIVATE FUNCTION CWindow.GetControlCallback (BYVAL cID AS LONG) AS ANY PTR
   DIM hCtl AS HWND = GetDlgItem(m_hWnd, cID)
   DIM nItem AS LONG = this.GetControlCallbackItem(cID)
   IF nItem > -1 THEN RETURN m_rgCtrlCallbacks(nItem).pCallback
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetControlCallback (BYVAL hCtl AS HWND) AS ANY PTR
   DIM nItem AS LONG = this.GetControlCallbackItem(hCtl)
   IF nItem > -1 THEN RETURN m_rgCtrlCallbacks(nItem).pCallback
END FUNCTION
' ========================================================================================

' ########################################################################################
'                               *** LAYOUT MANAGER ***
' ########################################################################################

' ========================================================================================
' Gets the anchor item
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CWindow.GetAnchorItem (BYVAL hwndCtl AS HWND) AS LONG
   FUNCTION = -1
   FOR i AS LONG = 0 TO UBOUND(m_rgProps)
      IF m_rgProps(i).hwndCtl = hwndCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Anchors the control
' ========================================================================================
PRIVATE FUNCTION CWindow.AnchorControl (BYVAL hwndCtl AS HWND, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   IF .IsWindow(hwndCtl) = FALSE THEN RETURN FALSE
   ' // Check if the item already exists
   DIM nItem AS LONG = this.GetAnchorItem(hwndCtl)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgProps(UBOUND(m_rgProps) + 1) AS AFX_ANCHORPROPERTY
      nItem = UBOUND(m_rgProps)
   END IF
   m_rgProps(nItem).hwndCtl = hwndCtl
   ' // Get the coordinates of the control
   DIM rcCtl AS RECT, pt AS POINT
   .GetWindowRect(hwndCtl, @rcCtl)
   pt.x = rcCtl.Left
   pt.y = rcCtl.Top
   ' // Convert the screen coordinates to screen to client-area coordinates
   .ScreenToClient(GetParent(hwndCtl), @pt)
   ' // Get the client coordinates of the parent window
   DIm rcParent AS RECT
   .GetClientRect(GetParent(hwndCtl), @rcParent)
   m_rgProps(nItem).anchor    = MIN(MAX(nAnchorMode, AFX_ANCHOR_NONE), AFX_ANCHOR_CENTER)
   m_rgProps(nItem).rc.Left   = pt.x
   m_rgProps(nItem).rc.Top    = pt.y
   m_rgProps(nItem).rc.Right  = rcParent.Right - (rcCtl.Right - rcCtl.Left + pt.x)
   m_rgProps(nItem).rc.Bottom = rcParent.Bottom - (rcCtl.Bottom - rcCtl.Top + pt.y)
   m_rgProps(nItem).centerX   = pt.x - (rcParent.Right \ 2)
   m_rgProps(nItem).centerY   = pt.y - (rcParent.Bottom \ 2)
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.AnchorControl (BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DIM hwndCtl AS HWND = GetDlgItem(m_hwnd, cID)
   IF hwndCtl THEN RETURN this.AnchorControl(hwndCtl, nAnchorMode)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.AnchorControl (BYVAL hParent AS HWND, BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DIM hwndCtl AS HWND = GetDlgItem(hParent, cID)
   IF hwndCtl THEN RETURN this.AnchorControl(hwndCtl, nAnchorMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback function to enumerate child windows
' ========================================================================================
PRIVATE FUNCTION CWindow.LayoutEnumChildProc (BYVAL hwndChild AS HWND, BYVAL lParam AS LPARAM) AS LONG
   DIM rcParent AS RECT, rcChild AS RECT
   DIM nWidth AS LONG, nHeight AS LONG, x AS LONG, y AS LONG, xWidth AS LONG, yHeight AS LONG
   DIM pWindow AS CWindow PTR = CAST(CWindow PTR, lParam)
   DIM nItem AS LONG = pWindow->GetAnchorItem(hwndChild)
   IF nItem > -1 THEN
      IF pWindow->m_rgProps(nItem).anchor > AFX_ANCHOR_NONE THEN
         ..GetWindowRect(hwndChild, @rcChild)
         nWidth = rcChild.Right - rcChild.Left
         nHeight = rcChild.Bottom - rcChild.Top
         ..GetClientRect(GetParent(hwndChild), @rcParent)
         x = 0: y = 0: xWidth = 0: yHeight = 0
         SELECT CASE pWindow->m_rgProps(nItem).anchor
            CASE AFX_ANCHOR_NONE
               x = pWindow->m_rgProps(nItem).rc.Left
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = MAX(rcParent.Right - pWindow->m_rgProps(nItem).rc.Left - pWindow->m_rgProps(nItem).rc.Right, 0)
               yHeight = nHeight
            CASE AFX_ANCHOR_WIDTH
               x = pWindow->m_rgProps(nItem).rc.Left
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = MAX(rcParent.Right - pWindow->m_rgProps(nItem).rc.Left - pWindow->m_rgProps(nItem).rc.Right, 0)
               yHeight = nHeight
            CASE AFX_ANCHOR_RIGHT
               x = rcParent.Right - nWidth - pWindow->m_rgProps(nItem).rc.Right
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_HORZ
               x = (rcParent.Right \ 2) + pWindow->m_rgProps(nItem).centerX
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_HEIGHT
               x = pWindow->m_rgProps(nItem).rc.Left
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = MAX(rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Top - pWindow->m_rgProps(nItem).rc.Bottom, 0)
            CASE AFX_ANCHOR_HEIGHT_WIDTH
               x = pWindow->m_rgProps(nItem).rc.Left
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = MAX(rcParent.Right - pWindow->m_rgProps(nItem).rc.Left - pWindow->m_rgProps(nItem).rc.Right, 0)
               yHeight = MAX(rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Top - pWindow->m_rgProps(nItem).rc.Bottom, 0)
            CASE AFX_ANCHOR_HEIGHT_RIGHT
               x = rcParent.Right - nWidth - pWindow->m_rgProps(nItem).rc.Right
               y = pWindow->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = MAX(rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Top - pWindow->m_rgProps(nItem).rc.Bottom, 0)
            CASE AFX_ANCHOR_BOTTOM
               x = pWindow->m_rgProps(nItem).rc.Left
               y = rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_BOTTOM_WIDTH
               x = pWindow->m_rgProps(nItem).rc.Left
               y = rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = MAX(rcParent.Right - pWindow->m_rgProps(nItem).rc.Left - pWindow->m_rgProps(nItem).rc.Right, 0)
               yHeight = nHeight
            CASE AFX_ANCHOR_BOTTOM_RIGHT
               x = rcParent.Right - nWidth - pWindow->m_rgProps(nItem).rc.Right
               y = rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_HORZ_BOTTOM
               x = (rcParent.Right \ 2) + pWindow->m_rgProps(nItem).centerX
               y = rcParent.Bottom - pWindow->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_VERT
               x = pWindow->m_rgProps(nItem).rc.Left
               y = (rcParent.Bottom - nHeight) \ 2
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_VERT_RIGHT
               x = rcParent.Right - nWidth - pWindow->m_rgProps(nItem).rc.Right
               y = (rcParent.Bottom - nHeight) \ 2
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER
               x = (rcParent.Right \ 2) + pWindow->m_rgProps(nItem).centerX
               y = (rcParent.Bottom \ 2) + pWindow->m_rgProps(nItem).centerY
               xWidth = nWidth
               yHeight = nHeight
         END SELECT
         ..MoveWindow(hwndChild, x, y, xWidth, yHeight, CTRUE)
      END IF
   END IF

   RETURN CTRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Adjust the controls size and/or position
' ========================================================================================
PRIVATE FUNCTION CWindow.AdjustControls () AS BOOLEAN
   IF UBOUND(m_rgProps) = -1 THEN RETURN FALSE
   EnumChildWindows(m_hWnd, CAST(WNDENUMPROC, @LayoutEnumChildProc), CAST(LPARAM, @this))
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ########################################################################################
'                              *** SCROLLABLE WINDOW ***
' ########################################################################################

' ========================================================================================
' Makes a window scrollable by shrinking its client area size
' ========================================================================================
PRIVATE FUNCTION CWindow.SetViewPort (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   ' // Data for optional scrollable dialogs
   m_HorzUnits = 10
   m_VertUnits = 10
   ..GetClientRect(m_hwnd, @m_OrigClientRect)
   ' // Shrink the client size
   this.SetClientSize(nWidth, nHeight)
   m_IsWindowScrollable = TRUE
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CWindow.IsWindowScrollable () AS BOOLEAN
   FUNCTION = m_IsWindowScrollable
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resets the window scrolling information
' ========================================================================================
PRIVATE SUB CWindow.ResetScrollBars
   ScrollWindow(m_hwnd, m_HScrollPos * m_HorzUnits, 0, NULL, NULL)
   ScrollWindow(m_hwnd, 0, m_VScrollPos * m_HorzUnits, NULL, NULL)
   m_HScrollPos = 0
   m_VScrollPos = 0
   SetScrollPos(m_hwnd, SB_HORZ, m_HScrollPos, CTRUE)
   SetScrollPos(m_hwnd, SB_VERT, m_VScrollPos, CTRUE)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the window scroll information
' Refactored: uses SCROLLINFO for proportional thumb size.
' ========================================================================================
PRIVATE SUB CWindow.SetupScrollBars
   DIM tempRect AS RECT
   ..GetClientRect(m_hwnd, @tempRect)
   ' // Calculate how many scrolling increments for the client area
   m_nHorzInc = ((m_OrigClientRect.Right - m_OrigClientRect.Left) - (tempRect.Right  - tempRect.Left) ) \ m_HorzUnits
   m_nVertInc = ((m_OrigClientRect.Bottom - m_OrigClientRect.Top) - (tempRect.bottom - tempRect.Top ) ) \ m_VertUnits
   m_HScrollMax = MAX(0, m_nHorzInc)
   m_HScrollPos = MIN(m_HScrollPos, m_HScrollMax)
   m_VScrollMax = MAX(0, m_nVertInc)
   m_VScrollPos = MIN(m_VScrollPos, m_VScrollMax)

   ' Use SCROLLINFO so thumbs reflect the visible area
   DIM si AS SCROLLINFO
   si.cbSize = SIZEOF(si)
   si.fMask = SIF_RANGE OR SIF_PAGE OR SIF_POS

   ' Horizontal scroll bar
   si.nMin = 0
   si.nMax = m_OrigClientRect.Right - m_OrigClientRect.Left - 1
   si.nPage = tempRect.Right - tempRect.Left
   si.nPos = m_HScrollPos
   SetScrollInfo(m_hwnd, SB_HORZ, @si, TRUE)

   ' Vertical scroll bar
   si.nMin = 0
   si.nMax = m_OrigClientRect.Bottom - m_OrigClientRect.Top - 1
   si.nPage = tempRect.Bottom - tempRect.Top
   si.nPos = m_VScrollPos
   SetScrollInfo(m_hwnd, SB_VERT, @si, TRUE)
END SUB
' ========================================================================================

' ========================================================================================
' Handles vertical scrollbar messages
' WM_VSCROLL
' nScrollCode = (int) LOWORD(wParam); // scroll bar value
' nPos = (short int) HIWORD(wParam);  // scroll box position
' hwndScrollBar = (HWND) lParam;      // handle of scroll bar
' ========================================================================================
PRIVATE SUB CWindow.OnVScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   DIM nInc AS LONG, iMove AS LONG
   SELECT CASE LOWORD(wParam)
      CASE SB_TOP        : nInc = -m_VScrollPos
      CASE SB_BOTTOM     : nInc = m_VScrollMax - m_VScrollPos
      CASE SB_LINEUP     : nInc = -1
      CASE SB_LINEDOWN   : nInc = 1
      CASE SB_PAGEUP     : nInc = MIN(-1, -m_nVertInc)
      CASE SB_PAGEDOWN   : nInc = MAX(1, m_nVertInc)
      CASE SB_THUMBTRACK : nInc = HIWORD(wParam) - m_VScrollPos
      CASE ELSE
         nInc = 0
   END SELECT
   nInc = MAX(-m_VScrollPos, MIN(nInc, m_VScrollMax - m_VScrollPos))
   IF nInc THEN
      m_VScrollPos += nInc
      iMove = -m_HorzUnits * nInc
      ScrollWindow(m_hwnd, 0, iMove, NULL, NULL)
      SetScrollPos(m_hwnd, SB_VERT, m_VScrollPos, CTRUE)
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' Handle horizontal scrollbar messages
' WM_HSCROLL
' nScrollCode = (int) LOWORD(wParam);  // scroll bar value
' nPos = (short int) HIWORD(wParam);   // scroll box position
' hwndScrollBar = (HWND) lParam;       // handle of scroll bar
' ========================================================================================
PRIVATE SUB CWindow.OnHScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   DIM nInc AS LONG, iMove AS LONG
   SELECT CASE LOWORD(wParam)
      CASE SB_TOP        : nInc = -m_HScrollPos
      CASE SB_BOTTOM     : nInc = m_HScrollMax - m_HScrollPos
      CASE SB_LINEUP     : nInc = -1
      CASE SB_LINEDOWN   : nInc = 1
      CASE SB_PAGEUP     : nInc = -m_HorzUnits
      CASE SB_PAGEDOWN   : nInc = m_HorzUnits
      CASE SB_THUMBTRACK : nInc = HIWORD(wParam) - m_HScrollPos
      CASE ELSE
         nInc = 0
   END SELECT
   nInc = MAX(-m_HScrollPos, MIN(nInc, m_HScrollMax - m_HScrollPos))
   IF nInc THEN
      m_HScrollPos += nInc
      iMove = -m_HorzUnits * nInc
      ScrollWindow(m_hwnd, iMove, 0, NULL, NULL)
      SetScrollPos(m_hwnd, SB_HORZ, m_HScrollPos, CTRUE)
  END IF
END SUB
' ========================================================================================

' ========================================================================================
' Handles WM_SIZE messges
' WM_SIZE
' fwSizeType = wParam;      // resizing flag
' nWidth = LOWORD(lParam);  // width of client area
' nHeight = HIWORD(lParam); // height of client area
' ========================================================================================
PRIVATE SUB CWindow.OnSize (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   this.ResetScrollbars
   this.SetupScrollbars
END SUB
' ========================================================================================

' ########################################################################################
'                         *** CWINDOW AND CONTROLS COLORS ***
' ########################################################################################

' ========================================================================================
' Gets the color item
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CWindow.GetColorItem (BYVAL hwnd AS ..HWND) AS LONG
   FUNCTION = -1
   FOR i AS LONG = 0 TO UBOUND(m_rgColors)
      IF m_rgColors(i).hwnd = hwnd THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetForeColor (BYVAL nItem AS LONG) AS COLORREF
   IF nItem >= 0 AND nItem <= UBOUND(m_rgColors) THEN
      RETURN this. m_rgColors(nItem).foreColor
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetForeColor (BYVAL hCtl AS HWND) AS COLORREF
   DIM nItem AS LONG = this.GetColorItem(hCtl)
   IF nItem >= 0 AND nItem <= UBOUND(m_rgColors) THEN
      RETURN this. m_rgColors(nItem).foreColor
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetBackColor (BYVAL nItem AS LONG) AS COLORREF
   IF nItem >= 0 AND nItem <= UBOUND(m_rgColors) THEN
      RETURN this. m_rgColors(nItem).backColor
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.GetBackColor (BYVAL hCtl AS HWND) AS COLORREF
   DIM nItem AS LONG = this.GetColorItem(hCtl)
   IF nItem >= 0 AND nItem <= UBOUND(m_rgColors) THEN
      RETURN this. m_rgColors(nItem).backColor
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the colors of the control
' ========================================================================================
PRIVATE FUNCTION CWindow.SetCtlColors (BYVAL hCtl AS ..HWND, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   IF IsWindow(hCtl) = FALSE THEN RETURN FALSE
   ' // Check if the item already exists
   DIM nItem AS LONG = this.GetColorItem(hCtl)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgColors(UBOUND(m_rgColors) + 1) AS AFX_WINDOWCOLORS
      nItem = UBOUND(m_rgColors)
   END IF
   m_rgColors(nItem).hwnd = hCtl
   m_rgColors(nItem).foreColor = foreColor
   m_rgColors(nItem).backColor = backColor
   '// Redraw the window
   InvalidateRect hCtl, NULL, CTRUE
   UpdateWindow hCtl
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWindow.SetCtlColors (BYVAL cID AS LONG, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   RETURN this.SetCtlColors(GetDlgItem(m_hwnd, cID), forecolor, backcolor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color of the main window
' ========================================================================================
PRIVATE FUNCTION CWindow.SetBackColor (BYVAL backColor AS COLORREF) AS BOOLEAN
   RETURN this.SetCtlColors(m_hwnd, 0, backColor)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                *** HELPER FUNCTIONS ***
' ########################################################################################

' ========================================================================================
' Returns a pointer to the CWindow class given the handle of its associated window handle.
' To retrieve it from the handle of any of its child windows or controls, use AfxCWindowOwnerPtr.
' ========================================================================================
PRIVATE FUNCTION AfxCWindowPtr OVERLOAD (BYVAL hwnd AS HWND) AS CWindow PTR
   FUNCTION = CAST(CWindow PTR, ..GetWindowLongPtrW(hwnd, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a pointer to the CWindow class given the a pointer to the CREATESTRUCT structure.
' ========================================================================================
PRIVATE FUNCTION AfxCWindowPtr OVERLOAD (BYVAL lParam AS LPARAM) AS CWindow PTR
   DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
   FUNCTION = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a pointer to the CWindow class given the a pointer to the CREATESTRUCT structure.
' ========================================================================================
PRIVATE FUNCTION AfxCWindowPtr OVERLOAD (BYVAL pCreateStruct AS CREATESTRUCT PTR) AS CWindow PTR
   FUNCTION = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a pointer to the CWindow class given the handle of the window created with it
' or the handle of any of it's children.
' ========================================================================================
PRIVATE FUNCTION AfxCWindowOwnerPtr OVERLOAD (BYVAL hwnd AS HWND) AS CWindow PTR
   IF hwnd = NULL THEN EXIT FUNCTION
   DIM hRootOwner AS ..HWND = ..GetAncestor(hwnd, GA_ROOTOWNER)
   IF hRootOwner = NULL THEN EXIT FUNCTION
   FUNCTION = CAST(CWindow PTR, ..GetWindowLongPtrW(hRootOwner, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a pointer to the CTabPage class given the handle of the tab control to which the
' tab page is associated and the zero-based tab index. If nTabIdx is ommited, the function
' will return the pointer of the selected tab, if any.
' ========================================================================================
'PRIVATE FUNCTION AfxCTabPagePtr OVERLOAD (BYVAL hTab AS HWND, BYVAL idx AS LONG) AS CTabPage PTR
'   IF hTab = NULL THEN EXIT FUNCTION
'   IF idx = -1 THEN idx = SendMessageW(hTab, TCM_GETCURSEL, 0, 0)
'   IF idx = -1 THEN EXIT FUNCTION   ' No tab selected
'   ' // Ask to return the value of the lParam member
'   DIM tci AS TCITEMW
'   tci.mask = TCIF_PARAM
'   IF ..SendMessageW(hTab, TCM_GETITEMW, idx, CAST(LPARAM, @tci)) THEN
'      IF tci.lParam THEN
'         FUNCTION = CAST(CTabPage PTR, tci.lParam)
'      END IF
'   END IF
'END FUNCTION
' ========================================================================================

' ########################################################################################
'                                *** INPUT BOX DIALOG ***
' ########################################################################################

' ========================================================================================
' Input box dialog
' Parameters:
' - hParent = Handle of the parent window
' - x, y = The location on the screen to display the dialog. If both are 0, the dialog
'   is centered on the screen.
' - wszCaption = Caption of the window
' - wszPrompt = Prompt string
' - wszText = Text to edit
' - nLen = [opt] Maximum length of the string to edit (default = 260 characters; maximum = 2048 characters)
' - bPassword = [opt] TRUE or FALSE. Default FALSE. Displays all characters as an
'     asterisk (*) as they are typed into the edit control.
'   Note: The maximum length is 2048 characters.
' ========================================================================================
' Forward declaration of the callback function
DECLARE FUNCTION AfxInputBoxWindowProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
' ========================================================================================
PRIVATE FUNCTION AfxInputBox (BYVAL hParent AS HWND = NULL, BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
BYREF dwsCaption AS DWSTRING = "", BYREF dwsPrompt AS DWSTRING = "", BYREF dwsText AS DWSTRING = "", _
BYVAL nLen AS LONG = 260, BYVAL bPassword AS BOOLEAN = FALSE) AS DWSTRING

   ' // Create the window
   DIM pInputBox AS CWindow
   DIM dwStyle AS DWORD = WS_CAPTION OR WS_POPUPWINDOW
   DIM dwExStyle AS DWORD = WS_EX_DLGMODALFRAME OR WS_EX_CONTROLPARENT
   DIM hInputBox AS HWND = pInputBox.Create(hParent, dwsCaption, @AfxInputBoxWindowProc, x, y, 326, 142, dwStyle, dwExStyle)
   ' // Center the window
   IF x = 0 AND y = 0 THEN pInputBox.Center(hInputBox, hParent)
   ' // Add a label control
   pInputBox.AddControl("Label", hInputBox, -1, dwsPrompt, 21, 10, 280, 19)
   ' // Add a TextBox control
   dwStyle = WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR ES_AUTOHSCROLL
   IF bPassWord THEN dwStyle = dwStyle OR ES_PASSWORD
   DIM hEdit AS HWND = pInputBox.AddControl("Edit", hInputBox, 101, "", 21, 33, 280, 19, dwStyle)
   ' // Add the buttons
   DIM hOkButton AS HWND = pInputBox.AddControl("Button", hInputBox, IDOK, "&Ok", 21, 72, 75, 22)
   DIM hCancelButton AS HWND = pInputBox.AddControl("Button", hInputBox, IDCANCEL, "&Cancel", 226, 72, 75, 22)
   ' // Localized strings. In the resource file of user32.dll, the OK button has
   ' // IDS_OK (801) as the identifier and the Cancel button IDS_CANCEL (801).
   DIM hUser32Instance AS HINSTANCE = GetModuleHandleW("user32.dll")
   DIM wszOk AS WSTRING * 260
   DIM cbLen AS LONG = LoadStringW(hUser32Instance, 800, @wszOk, SIZEOF(wszOk)\2)
   IF cbLen THEN wszOk = "&" & wszOk : SendMessageW(hOkButton, WM_SETTEXT, 0, cast(LPARAM, @wszOk))
   DIM wszCancel AS WSTRING * 260
   cbLen = LoadStringW(hUser32Instance, 801, @wszCancel, SIZEOF(wszCancel)\2)
   IF cbLen THEN wszCancel = "&" & wszCancel : SendMessageW(hCancelButton, WM_SETTEXT, 0, cast(LPARAM, @wszCancel))
   ' // Set the text and the limit
   IF nLen = 0 THEN nLen = 260
   IF nLen < 1 OR nLen > 2048 THEN nLen = 2048
   SendMessageW hEdit, EM_LIMITTEXT, nLen, 0
   IF LEN(dwsText) > nLen THEN dwsText = LEFT(dwsText, nLen)
   SetWindowTextW(hEdit, dwsText)
   SendMessageW(hEdit, EM_SETSEL, 0, -1)
   ' // Set the focus in the edit control
   SetFocus hEdit
   ' // Pointer to the allocated string to return the result
   DIM wszOut AS WSTRING * 2049
   pInputBox.UserData(0) = cast(LONG_PTR, @wszOut)
   ' // Process Windows messages
   pInputBox.DoEvents
   ' // Enable the parent window
   EnableWindow hParent, CTRUE
   ' // Return the output string
   RETURN wszOut

END FUNCTION
' ========================================================================================

' ========================================================================================
' Input box callback function.
' ========================================================================================
PRIVATE FUNCTION AfxInputBoxWindowProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg
      CASE WM_CREATE
         ' Disable parent window to make popup window modal
         EnableWindow GetParent(hwnd), FALSE
         EXIT FUNCTION
      CASE WM_COMMAND
         SELECT CASE GET_WM_COMMAND_ID(wParam, lParam)
            CASE IDCANCEL
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDOK
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
                  DIM nLen AS LONG = SendMessageW(GetDlgItem(hwnd, 101), WM_GETTEXTLENGTH, 0, 0)
                  IF nLen > 2048 THEN nLen = 2048
'                  nLen = SendMessageW(GetDlgItem(hwnd, 101), WM_GETTEXT, nLen + 1, cast(..LPARAM, pText))
                  DIM pInputBox AS CWindow PTR = AfxCWindowPtr(hwnd)
                  IF pInputBox THEN
                     ' // Pointer to the string buffer
                     DIM pText AS LONG_PTR = pInputBox->UserData(0)
                     IF pText THEN nLen = SendMessageW(GetDlgItem(hwnd, 101), WM_GETTEXT, nLen + 1, cast(..LPARAM, pText))
                  END IF
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT
      CASE WM_CLOSE
         ' // Enables parent window keeping parent's zorder
         EnableWindow GetParent(hwnd), CTRUE
         ' // Don't exit; let DefWindowProcW perform the default action
      CASE WM_DESTROY
         ' // Close the main window
         PostQuitMessage(0)
         EXIT FUNCTION
   END SELECT

   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================


' // Tab control pages
#include once "AfxNova/CTabPage.inc"

END NAMESPACE
