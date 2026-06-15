' ########################################################################################
' Platform: Microsoft Windows
' Filename: CDialog.inc
' Purpose:  Dialog box class
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

#include once "windows.bi"
#include once "win/commctrl.bi"
#include once "win/uxtheme.bi"
#include once "win/richedit.bi"
#include once "AfxNova/AfxWin.inc"
#include once "AfxNova/DWSTRING.inc"
#include once "AfxNova/RGB_Colors.bi"
USING AfxNova

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

' ========================================================================================
' Macro for debug
' To allow debugging, define _CDIALOG_DEBUG_ 1 in your application before including this file.
' To capture and display the messages sent by the Windows function OutputDebugStringW, you
' can use the DebugView tool. See: https://learn.microsoft.com/en-us/sysinternals/downloads/debugview
' ========================================================================================
#ifndef _CDIALOG_DEBUG_
   #define _CDIALOG_DEBUG_ 0
#ENDIF
#ifndef _CDIALOG_DP_
   #define _CDIALOG_DP_ 1
   #MACRO CDIALOG_DP(st)
      #IF (_CDIALOG_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

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

#ifndef AFX_DLGCOLORS
' // Dialog and control colors
TYPE AFX_DLGCOLORS
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

' ========================================================================================
' CDialog class
' ========================================================================================
TYPE CDialog

Private:

   m_hDlg  AS HWND                              ' // Dialog handle
   m_pCallback AS WNDPROC                       ' // Pointer to a subclassed user callback procedure
   m_hInstance AS HINSTANCE                     ' // Instance handle
   m_hRichEditLib AS HMODULE                    ' // Rich Edit module handle
   m_ptSize AS LONG                             ' // Font point size
   m_fontStyle AS BYTE                          ' // Font style
   m_charset AS BYTE                            ' // Font character set
   m_fontName AS WSTRING * 32                   ' // Font face name
   m_IsModal AS BOOLEAN                         ' // Dialog is modal
   m_IsCustom AS BOOLEAN                        ' // Dialog has a custom class
   m_UsePixels AS BOOLEAN                       ' // Use pixels instead of dialog units
   m_RepaintDisabled AS BOOLEAN                 ' // Repaint is disabled/enabled while resizing (true/false)
   m_DisableRepaintOnResize AS BOOLEAN          ' // Repaint is enabled while resizing (true/false)
   m_IsStabilized AS BOOLEAN                    ' // The dialog is stabilized(true) or is not stable (false)
   m_wszClassName AS WSTRING * 256              ' // Class name
   m_rx AS SINGLE = 1                           ' // DPI - Horizontal scaling ratio
   m_ry AS SINGLE = 1                           ' // DPI - Vertical scaling ratio
   m_DlgRetVal AS INT_PTR                       ' // To simulate EndDialog
   m_hDefPushButton AS HWND                     ' // Handle of the default push button
   DIM m_rgUserData(0 TO 99) AS LONG_PTR        ' // User data
   ' // Layout manager
   DIM m_rgProps(ANY) AS AFX_ANCHORPROPERTY     ' // Array of anchor property structures
   ' // Dialog and controls colors
   DIM m_rgColors(ANY) AS AFX_DLGCOLORS         ' // Array of colors structures
   ' // Accelerator table
   m_hAccel AS HACCEL                           ' // Accelerator table handle
   DIM m_rgAccelEntries(ANY) AS ACCEL           ' // Table of accelerator keys
   ' // Controls user data
   DIM m_rgCtrlUserData(ANY) AS AFX_CTLUSERDATA
   ' // Scrollable dialogs
   m_IsDialogScrollable AS BOOLEAN              ' // Dialog scrollable -True of False
   m_OrigClientRect AS RECT                     ' // Coordinates of the dialog's original client area
   m_nHorzInc AS LONG                           ' // Horizontal increment
   m_nVertInc AS LONG                           ' // Vertical increment
   m_HScrollMax AS LONG                         ' // Maximum horizontal scroll value
   m_VScrollMax AS LONG                         ' // Maximum vertical scroll value
   m_HScrollPos AS LONG                         ' // Horizontal scroll position
   m_VScrollPos AS LONG                         ' // Vertical scroll position
   m_HorzUnits AS LONG                          ' // Amount, in device units, of horizontal scrolling
   m_VertUnits AS LONG                          ' // Amount, in device units, of vertical scrolling

Public:

   ' // Dialogs
   DECLARE CONSTRUCTOR (BYREF fontName AS WSTRING = "Segoe UI", BYVAL ptSize AS LONG = 9, _
      BYVAL fontStyle AS BYTE = 0, BYVAL charset AS BYTE = DEFAULT_CHARSET) 
   DECLARE DESTRUCTOR 
   DECLARE FUNCTION RegisterClass (BYREF wszClassName AS CONST WSTRING) AS ATOM
   DECLARE FUNCTION DialogTemplate (BYREF wszClassName AS WSTRING, BYREF wszTitle AS WSTRING, BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, _
      BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS STRING
   DECLARE FUNCTION DialogNew (BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
      BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
      BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   DECLARE FUNCTION DialogNew (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
      BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
      BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   DECLARE FUNCTION DialogNewPixels (BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
      BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
      BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   DECLARE FUNCTION DialogNewPixels (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING = "", _
      BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
      BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   DECLARE FUNCTION DialogShowModeless (BYVAL pCallback AS ANY PTR = NULL) AS INT_PTR
   DECLARE FUNCTION DialogShowModal (BYVAL pCallback AS ANY PTR = NULL) AS INT_PTR
   DECLARE FUNCTION DialogDoEvents (BYVAL dwMilliseconds AS DWORD = 1) AS BOOLEAN
   DECLARE FUNCTION DialogEnd (BYVAL nResult AS LONG = 0) AS INT_PTR
   DECLARE FUNCTION DialogEndResult () AS INT_PTR
   DECLARE FUNCTION ControlAdd (BYREF wszClassName AS WSTRING, BYVAL cId AS LONG_PTR = 0, _
      BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
      BYVAL dwStyle AS LONG = -1, BYVAL dwExStyle AS LONG = -1, BYVAL lpParam AS LONG_PTR = 0, _
      BYVAL pCallbackProc AS WNDPROC = NULL) AS HWND
   DECLARE PROPERTY hDialog () AS HWND
'   DECLARE PROPERTY hDialog (BYVAL hDlg AS HWND)
   DECLARE FUNCTION IsModal () AS BOOLEAN
   DECLARE FUNCTION IsCustom () AS BOOLEAN
   DECLARE PROPERTY UsesPixels () AS BOOLEAN
   DECLARE PROPERTY UsesPixels (BYVAL fUsePixels AS BOOLEAN)
   DECLARE FUNCTION UsesUnits () AS BOOLEAN
   DECLARE FUNCTION DialogShowState (BYVAL showState AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogMaximize () AS BOOLEAN
   DECLARE FUNCTION DialogMinimize () AS BOOLEAN
   DECLARE FUNCTION DialogHide () AS BOOLEAN
   DECLARE FUNCTION DialogNormalize () AS BOOLEAN
   DECLARE FUNCTION DialogDisable () AS BOOLEAN
   DECLARE FUNCTION DialogEnable () AS BOOLEAN
   DECLARE FUNCTION DialogRedraw () AS BOOLEAN
   DECLARE FUNCTION DialogPost (BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION DialogSend (BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION DialogGetSize (BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogGetWidth () AS LONG
   DECLARE FUNCTION DialogGetHeight () AS LONG
   DECLARE FUNCTION DialogSetSize (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogGetBounds () AS RECT
   DECLARE FUNCTION DialogGetClient (BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogGetClientWidth () AS LONG
   DECLARE FUNCTION DialogGetClientHeight () AS LONG
   DECLARE FUNCTION DialogSetClient (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogGetLoc (BYREF nLeft AS LONG, BYREF nTop AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogSetLoc (BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogGetText () AS DWSTRING
   DECLARE FUNCTION DialogSetText (BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE FUNCTION DialogGetUser (BYVAL idx AS LONG) AS LONG_PTR
   DECLARE SUB DialogSetUser (BYVAL idx AS LONG, BYVAL newValue AS LONG_PTR)
   DECLARE FUNCTION DialogGetFont () AS HFONT
   DECLARE FUNCTION DialogGetFontFaceName () AS DWSTRING
   DECLARE FUNCTION DialogGetFontPointSize () AS LONG
   DECLARE SUB DialogCenter(BYVAL hwndParent AS HWND = NULL)
   DECLARE FUNCTION DialogStabilize () AS BOOLEAN
   DECLARE FUNCTION DialogNonStable () AS BOOLEAN
   DECLARE FUNCTION IsDialogStabilized () AS BOOLEAN
   DECLARE FUNCTION IsDialogNonStable () AS BOOLEAN
   DECLARE FUNCTION DialogReposition () AS BOOLEAN
   DECLARE SUB DialogForceVisibility
   DECLARE FUNCTION GetDefId () AS INT_PTR
   DECLARE FUNCTION SetDefId (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE FUNCTION FontNew (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, _
      BYVAL lWeight AS LONG = 0, BYVAL bItalic AS UBYTE = FALSE, BYVAL bUnderline AS UBYTE = FALSE, _
      BYVAL bStrikeOut AS UBYTE = FALSE, BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS HFONT
   DECLARE SUB FontEnd (BYVAL hFont AS HFONT)

   ' // Control methods
   DECLARE FUNCTION ControlDisable (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlEnable (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE SUB ControlSetFocus (BYVAL cId AS LONG)
   DECLARE FUNCTION ControlGetLoc (BYVAL cId AS LONG, BYREF nLeft AS LONG, BYREF nTop AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlSetLoc (BYVAL cId AS LONG, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlGetText (BYVAL cId AS LONG) AS DWSTRING
   DECLARE FUNCTION ControlSetText (BYVAL cId AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE FUNCTION ControlHandle (BYVAL cId AS LONG) AS HWND
   DECLARE FUNCTION ControlHide (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlNormalize (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlKill (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlRedraw (BYVAL cId AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlShowState (BYVAL cId AS LONG, BYVAL showState AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlPost (BYVAL cId AS LONG, BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION ControlSend (BYVAL cId AS LONG, BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION ControlGetSize (BYVAL cId AS LONG, BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlGetWidth (BYVAL cId AS LONG) AS LONG
   DECLARE FUNCTION ControlGetHeight (BYVAL cId AS LONG) AS LONG
   DECLARE FUNCTION ControlSetSize (BYVAL cId AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlGetClient (BYVAL cId AS LONG, BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlGetClientWidth (BYVAL cId AS LONG) AS LONG
   DECLARE FUNCTION ControlGetClientHeight (BYVAL cId AS LONG) AS LONG
   DECLARE FUNCTION ControlSetClient (BYVAL cId AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlGetFont (BYVAL cId AS LONG) AS HFONT
   DECLARE FUNCTION ControlGetFontFaceName (BYVAL cId AS LONG) AS DWSTRING
   DECLARE FUNCTION ControlGetFontPointSize (BYVAL cId AS LONG) AS LONG
   DECLARE SUB ControlSetFont (BYVAL cId AS LONG, BYVAL hFont AS HFONT, BYVAL fRedraw AS BOOLEAN = TRUE)
   DECLARE SUB ControlCenterHoriz (BYVAL cId AS LONG)
   DECLARE SUB ControlCenterVert (BYVAL cId AS LONG)
   DECLARE FUNCTION ControlGetCheck (BYVAL cId AS LONG) AS LONG
   DECLARE SUB ControlSetCheck (BYVAL cId AS LONG, BYVAL checkState AS LONG)
   DECLARE FUNCTION ControlSetOption (BYVAL cId AS LONG, BYVAL minId AS LONG, BYVAL maxId AS LONG) AS BOOLEAN
   DECLARE FUNCTION GetUserDataItem (BYVAL cid AS LONG) AS LONG
   DECLARE FUNCTION ControlSetUser (BYVAL cid AS LONG, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
   DECLARE FUNCTION ControlGetUser (BYVAL cid AS LONG, BYVAL index AS LONG) AS LONG_PTR
   DECLARE FUNCTION MenuContext (BYVAL hPopUpMenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL flags AS UINT) AS LONG

   ' // Colors
   DECLARE FUNCTION DialogSetColor (BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   DECLARE FUNCTION ControlSetColor (BYVAL hwnd AS HWND, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   DECLARE FUNCTION ControlSetColor (BYVAL cID AS LONG, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   DECLARE FUNCTION GetColorItem (BYVAL hwnd AS HWND) AS LONG
   DECLARE SUB DialogEnableRepaint (BYVAL fRepaint AS BOOLEAN)
   DECLARE FUNCTION IsDialogRepaintDisabled () AS BOOLEAN
   DECLARE SUB DialogDisableRepaintOnResize (BYVAL fRepaint AS BOOLEAN)
   DECLARE FUNCTION IsDialogRepaintDisabledOnResize () AS BOOLEAN

   ' // Images
   DECLARE SUB DialogSetIcon (BYREF wszImage AS WSTRING)
   DECLARE SUB DialogSetIconEx (BYVAL hIconBig AS HICON, BYVAL hIconSmall AS HICON)
   DECLARE FUNCTION FindResourceType (BYREF wszResourceName AS WSTRING) AS STRING
   DECLARE FUNCTION ControlSetImage (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DECLARE FUNCTION ControlSetImageX (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DECLARE FUNCTION ControlSetImgButton (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DECLARE FUNCTION ControlSetImgButtonX (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN

   ' // Conversion functions
   DECLARE FUNCTION DialogUnitsToPixels (BYVAL dluX AS LONG, BYVAL dluY AS LONG, BYREF pixelX AS LONG, BYREF pixelY AS LONG) AS BOOLEAN
   DECLARE FUNCTION DialogUnitsToPixelsRatios (BYREF ratioX AS SINGLE, BYREF ratioY AS SINGLE) AS BOOLEAN
   DECLARE FUNCTION DluToPixRX () AS SINGLE
   DECLARE FUNCTION DluToPixRY () AS SINGLE
   DECLARE FUNCTION PixelsToDialogUnits (BYVAL pixelX AS LONG, BYVAL pixelY AS LONG, BYREF dluX AS LONG, BYREF dluY AS LONG) AS BOOLEAN
   DECLARE FUNCTION PixelsToDialogUnitsRatios (BYREF ratioX AS SINGLE, BYREF ratioY AS SINGLE) AS BOOLEAN
   DECLARE FUNCTION PixToDluRX () AS SINGLE
   DECLARE FUNCTION PixToDluRY () AS SINGLE

   ' // Scaling (High DPI)
   DECLARE FUNCTION RxRatio () AS SINGLE
   DECLARE FUNCTION RyRatio () AS SINGLE
   DECLARE FUNCTION ScaleX (BYVAL cx AS SINGLE) AS SINGLE
   DECLARE FUNCTION ScaleY (BYVAL cy AS SINGLE) AS SINGLE
   DECLARE FUNCTION UnScaleX (BYVAL cx AS SINGLE) AS SINGLE
   DECLARE FUNCTION UnScaleY (BYVAL cy AS SINGLE) AS SINGLE
   DECLARE FUNCTION ScaleRect (BYVAL rc AS RECT) AS RECT
   DECLARE FUNCTION UnScaleRect (BYVAL rc AS RECT) AS RECT
   DECLARE FUNCTION SetWindowPosForDPI (BYVAL hwnd AS HWND, BYVAL hWndInsertAfter AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL uFlags AS UINT = SWP_NOZORDER) AS BOOLEAN
   DECLARE FUNCTION MoveWindowForDPI (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS BOOLEAN) AS BOOLEAN

   ' // Layout manager
   DECLARE FUNCTION ControlAnchor (BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlAnchor (BYVAL hCtl AS HWND, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DECLARE FUNCTION ControlAnchor (BYVAL hParent AS HWND, BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DECLARE FUNCTION GetAnchorItem (BYVAL hwndCtl AS HWND) AS LONG
   DECLARE FUNCTION AdjustControls () AS BOOLEAN

   ' // Keyboard accelerators
   DECLARE PROPERTY AccelHandle () AS ..HACCEL
   DECLARE SUB AccelAttach (BYVAL hAccel AS ..HACCEL)
   DECLARE SUB AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYVAL wKey AS WORD, BYVAL cmd AS WORD)
   DECLARE SUB AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYREF wszKey AS WSTRING, BYVAL cmd AS WORD)
   DECLARE FUNCTION CreateAccelTable () AS ..HACCEL
   DECLARE SUB DestroyAccelTable

   ' // Scrollable dialogs
   DECLARE FUNCTION DialogSetViewPort (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   DECLARE FUNCTION IsDialogScrollable () AS BOOLEAN
   DECLARE SUB DialogResetScrollBars
   DECLARE SUB DialogSetupScrollBars
   DECLARE SUB DialogOnVScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   DECLARE SUB DialogOnHScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   DECLARE SUB DialogOnSize (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)

   ' // Dialog procedure callback
   DECLARE FUNCTION CBGetDlgMsgResult () AS LONG_PTR
   DECLARE FUNCTION CBSetDlgMsgResult (BYVAL result AS LONG_PTR) AS LONG_PTR

Private:

   DECLARE STATIC FUNCTION CDialogProc (BYVAL hDlg AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
'   DECLARE STATIC FUNCTION CCustomDialogProc (BYVAL hDlg AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
   ' // Layout manager - Callback function to enumerate child windows
   DECLARE STATIC FUNCTION LayoutEnumChildProc (BYVAL hwnd AS HWND, BYVAL lParam AS LPARAM) AS LONG

END TYPE
' ========================================================================================

' ========================================================================================
' * Dialog constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CDialog (BYREF fontName AS WSTRING = "Segoe UI", BYVAL ptSize AS LONG = 9, BYVAL fontStyle AS BYTE = 0, BYVAL charset AS BYTE = DEFAULT_CHARSET) 
   CDIALOG_DP("")
   ' // Store the passed parameters
   m_fontName = fontName
   m_ptSize = ptSize
   m_fontStyle = fontStyle
   m_charset = charset
   ' // Instance handle
   m_hInstance = GetModuleHandleW(NULL)
   ' // Initialize the common controls library
   DIM icc AS INITCOMMONCONTROLSEX
   icc.dwSize = SIZEOF(icc)
   icc.dwICC  = ICC_NATIVEFNTCTL_CLASS OR ICC_COOL_CLASSES OR ICC_BAR_CLASSES OR _
                ICC_TAB_CLASSES OR ICC_USEREX_CLASSES OR ICC_WIN95_CLASSES OR _
                ICC_STANDARD_CLASSES OR ICC_ANIMATE_CLASS OR ICC_DATE_CLASSES OR _
                ICC_HOTKEY_CLASS OR ICC_INTERNET_CLASSES OR ICC_LISTVIEW_CLASSES OR _
                ICC_PAGESCROLLER_CLASS OR ICC_PROGRESS_CLASS OR ICC_TREEVIEW_CLASSES OR _
                ICC_UPDOWN_CLASS
   InitCommonControlsEx(@icc)
   ' // DPI ratios
   DIM hDC AS HDC
   hDC = .GetDC(NULL)
   m_rx = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   m_ry = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC NULL, hDC
   ' // Initialize the COM library
   CoInitialize NULL
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' * Destructor
' ========================================================================================
PRIVATE DESTRUCTOR CDialog
   CDIALOG_DP("")
   ' // Destroy the accelerator table
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   ' // Free the Rich Edit library
   IF m_hRichEditLib THEN FreeLibrary m_hRichEditLib
   ' // Unregister the class name
   IF LEN(m_wszClassName) THEN UnregisterClassW(m_wszClassName, m_hInstance)
   ' // Uninitialize the COM library
   CoUninitialize
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Registers a window class.
' Parameter:
' - wszClassName = The class name
' Return Value:
'   An atom that uniquely identifies the class or 0 on failure.
' ========================================================================================
PRIVATE FUNCTION CDialog.RegisterClass (BYREF wszClassName AS CONST WSTRING) AS ATOM
   CDIALOG_DP(" - " & wszClassName)
   ' // Flags it as a custom dialog
   m_IsCustom = TRUE
   ' // Class name
   IF LEN(wszClassName) THEN m_wszClassName = wszClassName ELSE RETURN 0
   ' // Fill the WNDCLASSEXW structure (same data than the #32770 class)
   DIM wcexw AS WNDCLASSEXW              ' // WNDCLASSEXW structure
   WITH wcexw
      .cbSize        = SIZEOF(wcexw)
      .style         = 0
      .lpfnWndProc   = PROCPTR(CDialog.CDialogProc)
      .cbClsExtra    = 0
      .cbWndExtra    = DLGWINDOWEXTRA
      .hInstance     = m_hInstance
      .hCursor       = ..LoadCursorW(NULL, CAST(LPCWSTR, IDC_ARROW))
      .hbrBackground = 0
      .lpszMenuName  = NULL
      .lpszClassName = @wszClassName
      .hIcon         = 0
      .hIconSm       = 0
   END WITH
   ' // Register the class
   DIM wAtom AS ATOM = RegisterClassExW(@wcexw)
   ' // Return the atom
   FUNCTION = wAtom
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a dialog template in memory.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogTemplate (BYREF wszClassName AS WSTRING, BYREF wszTitle AS WSTRING, BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, _
   BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS STRING
   ' // Default styles. PB also includes DS_3DLOOK, but this style is obsolete since the system automatically
   ' // applies the three-dimensional look to dialog boxes created by applications.
   IF dwStyle = 0 THEN dwStyle = WS_VISIBLE OR DS_MODALFRAME OR DS_NOFAILCREATE OR DS_SETFONT OR WS_OVERLAPPEDWINDOW _
      OR WS_CAPTION OR WS_CLIPSIBLINGS OR WS_DLGFRAME OR WS_POPUP OR WS_SYSMENU
   IF x = -1 AND y = -1 THEN dwStyle OR= DS_CENTER
   IF x = -1 THEN x = 0
   IF y = -1 THEN y = 0
   ' // Default extended styles.
   IF dwExStyle = 0 THEN dwExStyle = WS_EX_LEFT OR WS_EX_LTRREADING OR WS_EX_RIGHTSCROLLBAR

   ' // We need raw unicode in the strings
   DIM sTitle AS STRING = SPACE(LEN(wszTitle) * 2)
   memcpy STRPTR(sTitle), VARPTR(wszTitle), LEN(wszTitle) * 2
   DIM sFontName AS STRING = SPACE(LEN(m_FontName) * 2)
   memcpy STRPTR(sFontName), VARPTR(m_FontName), LEN(m_FontName) * 2
   ' // Custom dialog
   DIM wAtom AS ATOM
   IF LEN(wszClassName) THEN wAtom = this.RegisterClass(wszClassName)
   DIM sClassName AS STRING = SPACE(LEN(wszClassName) * 2)
   memcpy STRPTR(sClassName), VARPTR(wszClassName), LEN(wszClassName) * 2

   DIM sTemplateEx AS STRING = _
      MKShort(1) + _                     ' // Version is always 1
      MKShort(&hFFFF) + _                ' // Use extended dialog box template signature
      MKL(0) + _                         ' // Help context identifier
      MKL(dwExStyle) + _                 ' // Window extended style
      MKL(dwStyle OR DS_SETFONT) + _     ' // Window style
      MKShort(0) + _                     ' // Number of controls
      MKShort(x) + _                     ' // x coordinate
      MKShort(y) + _                     ' // y coordinate
      MKShort(cx) + _                    ' // Width of the window
      MKShort(cy) + _                    ' // Height of the window
      MKShort(0) + _                     ' // Menu
      sClassName & CHR(0) & CHR(0) + _   ' // Custom dialog class name (raw unicode with double nulls)
      sTitle & CHR(0) & CHR(0) + _       ' // Dialog caption (raw unicode with double nulls)
      MKShort(m_ptSize) + _              ' // Font point size
      MKShort(FW_NORMAL) + _             ' // Font weight
      CHR(m_fontStyle) + _               ' // Font Italic flag
      CHR(m_charset) + _                 ' // Font charset
      sFontName & CHR(0) & CHR(0)        ' // Font face name (raw unicode with double nulls)

   FUNCTION = sTemplateEx
   
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a control to the dialog.
' Note: Although the control identifier is a LONG, we must declare it here as a LONG_PTR
' because we have to cast it in CreateWindowExW to the member HMENU, which is an handle
' (4 bytes in 32-bit, 8 bytes in 64-bit).
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlAdd ( _
   BYREF wszClassName AS WSTRING, _                       ' // Class name
   BYVAL cId AS LONG_PTR = 0, _                           ' // Control identifier
   BYREF wszTitle AS WSTRING = "", _                      ' // Control caption
   BYVAL x AS LONG = 0, _                                 ' // Horizontal position
   BYVAL y AS LONG = 0, _                                 ' // Vertical position
   BYVAL nWidth AS LONG = 0, _                            ' // Control width
   BYVAL nHeight AS LONG = 0, _                           ' // Control height
   BYVAL dwStyle AS LONG = -1, _                          ' // Control style
   BYVAL dwExStyle AS LONG = -1, _                        ' // Extended style
   BYVAL lpParam AS LONG_PTR = 0, _                       ' // Pointer to custom data
   BYVAL pCallbackProc AS WNDPROC = NULL _                ' // Address of the control callback procedure
   ) AS HWND                                              ' // Control handle

   DIM hCtl AS HWND
   IF LEN(wszClassName) = 0 THEN EXIT FUNCTION
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
         IF dwStyle = BS_OWNERDRAW THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_OWNERDRAW
         #if _WIN32_WINNT = &h0602
         IF dwStyle = BS_SPLITBUTTON THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_SPLITBUTTON
         IF dwStyle = BS_DEFSPLITBUTTON THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_DEFSPLITBUTTON
         #endif
      CASE "CUSTOMBUTTON", "OWNERDRAWBUTTON", "BUTTONOWNERDRAW"
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
      CASE "CHECK3STATE", "CHECKSTATE"
         ' Adds a 3 state checkbox to the window.
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_AUTO3STATE OR BS_LEFT OR BS_VCENTER
      CASE "LABEL"
         ' Adds a label to the window.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR SS_LEFT OR WS_GROUP OR SS_NOTIFY
      CASE "IMGBUTTON", "IMGBUTTONX"   ' // For compatibility with PowerBasic
         wsClassName = "Button"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON ELSE dwStyle OR= WS_VISIBLE OR WS_TABSTOP
         bSetFont = FALSE
         '// Check the type if resource (icon or bitmap)
         DIM strType AS STRING = this.FindResourceType(wszTitle)
         DIM nType AS LONG
         IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = BS_ICON ELSE IF strType = "RT_BITMAP" THEN nType = BS_BITMAP
         ' // Add the style
         IF nType THEN dwStyle OR= nType
      CASE "IMAGE"   ' // For compatibility with PowerBasic
         ' Adds an image label to the window.
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE ELSE dwStyle OR= WS_VISIBLE
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
         bSetFont = FALSE
         '// Check the type if resource (icon or bitmap)
         DIM strType AS STRING = this.FindResourceType(wszTitle)
         DIM nType AS LONG
         IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = SS_ICON ELSE IF strType = "RT_BITMAP" THEN nType = SS_BITMAP
         ' // Add the style
         IF nType THEN dwStyle OR= nType
      CASE "IMAGEX"   ' // For compatibility with PowerBasic
         wsClassName = "Static"
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE ELSE dwStyle OR= WS_VISIBLE
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_TRANSPARENT
         ' // With this style, the image is stretched
         dwStyle OR= SS_REALSIZECONTROL
         bSetFont = FALSE
         '// Check the type if resource (icon or bitmap)
         DIM strType AS STRING = this.FindResourceType(wszTitle)
         DIM nType AS LONG
         IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = SS_ICON ELSE IF strType = "RT_BITMAP" THEN nType = SS_BITMAP
         ' // Add the style
         IF nType THEN dwStyle OR= nType
      CASE "CUSTOMLABEL", "LABELOWNERDRAW"
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
      CASE "LISTBOXMULTISELECT", "LBMULTISELECT"
         ' Adds a muliple-selection list box to the window.
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_HSCROLL OR WS_VSCROLL OR WS_BORDER OR WS_TABSTOP OR LBS_STANDARD OR LBS_HASSTRINGS OR LBS_SORT OR LBS_NOTIFY OR LBS_EXTENDEDSEL
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
         wsClassName = "ListBox"
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
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_TABSTOP OR LVS_REPORT OR LVS_SHOWSELALWAYS OR LVS_SHAREIMAGELISTS OR LVS_AUTOARRANGE OR LVS_EDITLABELS OR LVS_ALIGNTOP
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
         IF dwExStyle = -1 THEN dwExStyle = WS_EX_CLIENTEDGE
         wsClassName = "RichEdit50W"
         IF m_hRichEditLib = 0 THEN m_hRichEditLib = CAST(HMODULE, LoadLibraryW("MSFTEDIT.DLL"))
      CASE ELSE
         IF dwStyle = -1 THEN dwStyle = WS_VISIBLE OR WS_CHILD
   END SELECT
   ' // Don't allow negative values for the styles
   IF dwStyle = -1 THEN dwStyle = 0
   IF dwExStyle = -1 THEN dwExStyle = 0
   ' // Make sure that the control has the WS_CHILD style and that it is visible
   dwStyle = dwStyle OR WS_CHILD OR WS_VISIBLE

   ' // Create the control
   DIM rc AS RECT
   rc.Left = x : rc.Right  = x + nWidth
   rc.Top  = y : rc.Bottom = y + nHeight
   IF m_UsePixels = FALSE THEN
      MapDialogRect m_hDlg, @rc
      hCtl = CreateWindowExW (dwExStyle, wsClassName, wszTitle, dwStyle, rc.Left, rc.Top, (rc.Right - rc.Left), _
             (rc.Bottom - rc.Top), m_hDlg, CAST(HMENU, cID), m_hInstance, CAST(LPVOID, lpParam))
   ELSE
      hCtl = CreateWindowExW (dwExStyle, wsClassName, wszTitle, dwStyle, rc.Left * m_rx, rc.Top * m_ry, (rc.Right - rc.Left) * m_ry, _
             (rc.Bottom - rc.Top) * m_ry, m_hDlg, CAST(HMENU, cID), m_hInstance, CAST(LPVOID, lpParam))
   END IF
   IF hCtl = NULL THEN EXIT FUNCTION
   ' // Set the font
   IF bSetFont THEN SendMessageW(hCtl, WM_SETFONT, SendMessageW(m_hDlg, WM_GETFONT, 0, 0), 0)

   SELECT CASE UCASE(wsClassName)
      CASE "BUTTON"
         IF (dwStyle AND BS_DEFPUSHBUTTON) = BS_DEFPUSHBUTTON THEN
            ' // Removes the default button because 32768 is not a valid control ID.
            ' // Needed if the user has set the BS_DEFBUTTON style to more of one button.
            ' // We don't want to have more than one default button.
            SendMessageW(m_hDlg, DM_SETDEFID, 32768, 0)
            ' // Sets the specified button as the default
            SendMessageW(m_hDlg, DM_SETDEFID, cId, 0)
            ' // DEfault push button
            m_hDefPushButton = hCtl
         END IF
      CASE "LISTBOX"
         ' // Adjust the height of the control so that the integral height
         ' // is based on the new font rather than the default SYSTEM_FONT
         SetWindowPosForDpi hCtl, NULL, x, y, nWidth, nHeight, SWP_NOZORDER
      CASE "DATETIMEPICKER", "SYSDATETIMEPICK32"
         ' // Sets the font to be used by the date and time picker control's child month calendar control.
         SendMessageW(hCtl, DTM_SETMCFONT, SendMessageW(m_hDlg, WM_GETFONT, 0, 0), CTRUE)
      CASE "PROGRESSBAR", "MSCTLS_PROGRESS32"
         ' // Set the default range
         .SendMessageW hCtl, PBM_SETRANGE32, 0, 100
         ' // Set the default initial value
         .SendMessageW hCtl, PBM_SETPOS, 0, 0
      CASE "TRACKBAR", "MSCTLS_TRACKBAR32"
         ' // Set the default range values
         .SendMessageW hCtl, TBM_SETRANGEMIN, CTRUE, 0
         .SendMessageW hCtl, TBM_SETRANGEMAX, CTRUE, 100
         ' // Set the default page size
         .SendMessageW hCtl, TBM_SETPAGESIZE, 0, 10
      CASE "UPDOWN", "MSCTLS_UPDOWN32"
         ' // Set the default base
         .SendMessageW hCtl, UDM_SETBASE, 10, 0
         ' // Set the default range values
         .SendMessageW hCtl, UDM_SETRANGE32, 100, 0
         ' // Set the default initial value
         .SendMessageW hCtl, UDM_SETPOS32, 0, 0
         ' // Correct for Windows using a default size for the updown control
         SetWindowPos hCtl, NULL, x, y, nWidth, nHeight, SWP_NOZORDER
      CASE "HSCROLLBAR", "VSCROLLBAR"
         ' // Initialize the scroll bar with default values
         DIM tsi AS SCROLLINFO
         tsi.cbSize = SIZEOF(tsi)
         tsi.fMask  = SIF_PAGE OR SIF_POS OR SIF_RANGE
         tsi.nMin   = 0
         tsi.nMax   = 100
         tsi.nPage  = 0
         tsi.nPos   = 0
         .SetScrollInfo hCtl, SB_CTL, @tsi, CTRUE
      CASE "TOOLBAR", "TOOLBARWINDOW32"
         ' // Set the button size
         DIM AS LONG nButtonWidth, nButtonHeight
         nButtonWidth = LOWORD(.SendMessageW(hCtl, TB_GETBUTTONSIZE, 0, 0))
         nButtonHeight = HIWORD(.SendMessageW(hCtl, TB_GETBUTTONSIZE, 0, 0))
         .SendMessageW hCtl, TB_SETBUTTONSIZE, 0, MAKELONG(nButtonWidth, nButtonHeight)
         ' // Send this message for backward compatibility
         .SendMessageW hCtl, TB_BUTTONSTRUCTSIZE, SIZEOF(TBBUTTON), 0
   END SELECT
   ' // Buttons with images (icon or bitmap)
   SELECT CASE UCASE(wszClassName)
      CASE "IMGBUTTON", "IMGBUTTONX"
         DIM AS LONG nType, nWidth, nHeight
         IF (dwStyle AND BS_BITMAP) = BS_BITMAP THEN nType = IMAGE_BITMAP ELSE nType = IMAGE_ICON
         IF wszClassName = "IMGBUTTONX" THEN
            DIM rc AS RECT
            GetClientRect(hCtl, @rc)
            nWidth = rc.right - rc.left
            nHeight = rc.bottom -rc.top
         END IF
         ' // Loads the bitmap from resource
         DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
         IF LEFT(wszTitle, 1) = "#" THEN
            wID = VAL(MID(wszTitle, 2))
            dwID = MAKELONG(wID, 0)
            hImage = LoadImageW(m_hInstance, MAKEINTRESOURCEW(dwID), nType, nWidth, nHeight, LR_DEFAULTCOLOR)
         ELSE
            ' // Loads the bitmap from file
            IF UCASE(RIGHT(wszTitle, 4)) = ".BMP" THEN
               hImage = LoadImageW(NULL, wszTitle, nType, nWidth, nHeight, LR_LOADFROMFILE)
            ELSE
               ' // Loads the bitmap from resource
               hImage = LoadImageW(m_hInstance, wszTitle, nType, nWidth, nHeight, LR_DEFAULTCOLOR)
            END IF
         END IF
         ' // Sets the image and deletes the old one
         IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(hCtl, BM_SETIMAGE, nType, CAST(LPARAM, hImage))))
      CASE "SIZEBAR", "SIZEBOX", "SIZEGRIP"
         nWidth = GetSystemMetrics(SM_CXVSCROLL)
         nHeight = GetSystemMetrics(SM_CYHSCROLL)
         DIM rcClient AS RECT
         GetClientRect(m_hDlg, @rcClient)
         x = rcClient.Right - nWidth
         y = rcClient.Bottom - nHeight
         SetWindowPos hCtl, NULL, x, y, nWidth, nHeight, SWP_NOZORDER OR SWP_SHOWWINDOW
   END SELECT
   FUNCTION = hCtl
END FUNCTION
' =====================================================================================

' ========================================================================================
' Gets the handle of the dialog
' ========================================================================================
PRIVATE PROPERTY CDialog.hDialog () AS HWND
   RETURN m_hDlg
END PROPERTY
' ========================================================================================
' ========================================================================================
' Sets the handle of the dialog
' ========================================================================================
'PRIVATE PROPERTY CDialog.hDialog (BYVAL hDlg AS HWND)
'   IF IsWindow(hDlg) THEN m_hDlg = hDlg
'END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns true if the dialog is modal
' ========================================================================================
PRIVATE FUNCTION CDialog.IsModal () AS BOOLEAN
   RETURN m_IsModal
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns true if it is a custom dialog
' ========================================================================================
PRIVATE FUNCTION CDialog.IsCustom () AS BOOLEAN
   RETURN m_IsCustom
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns true if it uses pixels
' ========================================================================================
PRIVATE PROPERTY CDialog.UsesPixels (BYVAL fUsePixels AS BOOLEAN)
   m_UsePixels = fUsePixels
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns true if it uses pixels
' ========================================================================================
PRIVATE PROPERTY CDialog.UsesPixels () AS BOOLEAN
   RETURN m_UsePixels
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns true if it uses dialog units
' ========================================================================================
PRIVATE FUNCTION CDialog.UsesUnits () AS BOOLEAN
   IF m_UsePixels = TRUE THEN RETURN FALSE ELSE RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a modeless dialog in memory
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogNew (BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
   BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
   BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   CDIALOG_DP("#32770 - UNITS")
   m_UsePixels = FALSE
   ' // Default styles
   IF dwStyle THEN dwStyle = dwStyle OR DS_3DLOOK OR DS_NOFAILCREATE OR DS_SETFONT
   IF dwStyle = 0 THEN dwStyle = DS_3DLOOK OR DS_SETFONT OR DS_MODALFRAME OR DS_NOFAILCREATE OR WS_BORDER OR _
                                 WS_CLIPSIBLINGS OR WS_DLGFRAME OR WS_POPUP
   IF dwExStyle = 0 THEN dwExstyle = WS_EX_LEFT OR WS_EX_LTRREADING OR WS_EX_RIGHTSCROLLBAR
   ' // Remove the WS_VISIBLE style to avoid partial images of the dialog to appear before it is completed.
   ' // The dialog will be displayed and activated in the ShowDialogModal or ShowDialogModeless methods with ShowWindow.
   dwStyle = dwStyle AND (NOT WS_VISIBLE)
   DIM sTemplate AS STRING = this.DialogTemplate("", wszTitle, x, y, cx, cy, dwStyle, dwExStyle)
   m_hDlg = CreateDialogIndirectParamW(m_hInstance, cast(LPCDLGTEMPLATEW, STRPTR(sTemplate)), _
            hParent, NULL, cast(LPARAM, @this))
   ' // Set the default procedure callback
   SetWindowLongPtrW(m_hDlg, DWLP_DLGPROC, CAST(LONG_PTR, PROCPTR(CDialog.CDialogProc)))
   ' // Store a pointer to the CDialog class
   IF m_hDlg THEN SetWindowLongPtrW(m_hDlg, DWLP_USER, CAST(LONG_PTR, @this))
   ' // Return the dialog handle
   RETURN m_hDlg
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a custom modeless dialog in memory
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogNew (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING = "", _
   BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
   BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   CDIALOG_DP(wszClassName)
   m_UsePixels = FALSE
   ' // Check if the class is already registered
   DIM wcw AS WNDCLASSW
   IF GetClassInfoW(m_hInstance, wszClassName, @wcw) THEN RETURN NULL
   ' // Default styles
   IF dwStyle THEN dwStyle = dwStyle OR DS_3DLOOK OR DS_NOFAILCREATE OR DS_SETFONT
   IF dwStyle = 0 THEN dwStyle = DS_3DLOOK OR DS_SETFONT OR DS_MODALFRAME OR DS_NOFAILCREATE OR WS_BORDER OR _
                                 WS_CLIPSIBLINGS OR WS_DLGFRAME OR WS_POPUP
   IF dwExStyle = 0 THEN dwExstyle = WS_EX_LEFT OR WS_EX_LTRREADING OR WS_EX_RIGHTSCROLLBAR
   ' // Remove the WS_VISIBLE style to avoid partial images of the dialog to appear before it is completed.
   ' // The dialog will be displayed and activated in the ShowDialogModal or ShowDialogModeless methods with ShowWindow.
   dwStyle = dwStyle AND (NOT WS_VISIBLE)
   DIM sTemplate AS STRING = this.DialogTemplate(wszClassName, wszTitle, x, y, cx, cy, dwStyle, dwExStyle)
   m_hDlg = CreateDialogIndirectParamW(m_hInstance, cast(LPCDLGTEMPLATEW, STRPTR(sTemplate)), _
            hParent, NULL, cast(LPARAM, @this))
   ' // Store a pointer to the CDialog class
   IF m_hDlg THEN SetWindowLongPtrW(m_hDlg, DWLP_USER, CAST(LONG_PTR, @this))
   ' // Return the dialog handle
   RETURN m_hDlg
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a modeless dialog in memory
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogNewPixels (BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
   BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
   BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   CDIALOG_DP("#32770- PIXELS")
   m_UsePixels = TRUE
   ' // Default styles
   IF dwStyle THEN dwStyle = dwStyle OR DS_3DLOOK OR DS_NOFAILCREATE OR DS_SETFONT
   IF dwStyle = 0 THEN dwStyle = DS_3DLOOK OR DS_SETFONT OR DS_MODALFRAME OR DS_NOFAILCREATE OR WS_BORDER OR _
                                 WS_CLIPSIBLINGS OR WS_DLGFRAME OR WS_POPUP
   IF dwExStyle = 0 THEN dwExstyle = WS_EX_LEFT OR WS_EX_LTRREADING OR WS_EX_RIGHTSCROLLBAR
   ' // Remove the WS_VISIBLE style to avoid partial images of the dialog to appear before it is completed.
   ' // The dialog will be displayed and activated in the ShowDialogModal or ShowDialogModeless methods with ShowWindow.
   dwStyle = dwStyle AND (NOT WS_VISIBLE)
   DIM sTemplate AS STRING = this.DialogTemplate("", wszTitle, x, y, cx * m_rx, cy * m_ry, dwStyle, dwExStyle)
   m_hDlg = CreateDialogIndirectParamW(m_hInstance, cast(LPCDLGTEMPLATEW, STRPTR(sTemplate)), _
            hParent, NULL, cast(LPARAM, @this))
   IF m_hDlg = NULL THEN RETURN NULL
'   SetWindowPos (m_hDlg, NULL, x, y, cx * m_rx, cy * m_ry, SWP_NOZORDER OR SWP_NOACTIVATE OR SWP_NOMOVE)
   this.DialogSetClient(cx, cy)
   IF x = -1 AND y = -1 THEN this.DialogCenter   ' // Center the dialog
   IF (dwStyle AND DS_CENTER) = DS_CENTER THEN
      this.DialogCenter   ' // Center the dialog
   ELSEIF x = -1 AND y = -1 THEN
      this.DialogCenter   ' // Center the dialog
   END IF
   ' // Set the default procedure callback
   SetWindowLongPtrW(m_hDlg, DWLP_DLGPROC, CAST(LONG_PTR, PROCPTR(CDialog.CDialogProc)))
   ' // Store a pointer to the CDialog class
   IF m_hDlg THEN SetWindowLongPtrW(m_hDlg, DWLP_USER, CAST(LONG_PTR, @this))
   ' // Return the dialog handle
   RETURN m_hDlg
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Creates a custom modeless dialog in memory
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogNewPixels (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING = "", _
   BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
   BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
   CDIALOG_DP(wszClassName & " - PIXELS")
   m_UsePixels = TRUE
   ' // Check if the class is already registered
   DIM wcw AS WNDCLASSW
   IF GetClassInfoW(m_hInstance, wszClassName, @wcw) THEN RETURN NULL
   ' // Default styles
   IF dwStyle THEN dwStyle = dwStyle OR DS_3DLOOK OR DS_NOFAILCREATE OR DS_SETFONT
   IF dwStyle = 0 THEN dwStyle = DS_3DLOOK OR DS_SETFONT OR DS_MODALFRAME OR DS_NOFAILCREATE OR WS_BORDER OR _
                                 WS_CLIPSIBLINGS OR WS_DLGFRAME OR WS_POPUP
   IF dwExStyle = 0 THEN dwExstyle = WS_EX_LEFT OR WS_EX_LTRREADING OR WS_EX_RIGHTSCROLLBAR
   ' // Remove the WS_VISIBLE style to avoid partial images of the dialog to appear before it is completed.
   ' // The dialog will be displayed and activated in the ShowDialogModal or ShowDialogModeless methods with ShowWindow.
   dwStyle = dwStyle AND (NOT WS_VISIBLE)
   DIM sTemplate AS STRING = this.DialogTemplate(wszClassName, wszTitle, x, y, cx * m_rx, cy * m_ry, dwStyle, dwExStyle)
   m_hDlg = CreateDialogIndirectParamW(m_hInstance, cast(LPCDLGTEMPLATEW, STRPTR(sTemplate)), _
            hParent, NULL, cast(LPARAM, @this))
   IF m_hDlg = NULL THEN RETURN NULL
'   SetWindowPos (m_hDlg, NULL, x, y, cx * m_rx, cy * m_ry, SWP_NOZORDER OR SWP_NOACTIVATE OR SWP_NOMOVE)
   this.DialogSetClient(cx, cy)
   IF x = -1 AND y = -1 THEN this.DialogCenter   ' // Center the dialog
   IF (dwStyle AND DS_CENTER) = DS_CENTER THEN
      this.DialogCenter   ' // Center the dialog
   ELSEIF x = -1 AND y = -1 THEN
      this.DialogCenter   ' // Center the dialog
   END IF
   ' // Store a pointer to the CDalog class
   IF m_hDlg THEN SetWindowLongPtrW(m_hDlg, DWLP_USER, CAST(LONG_PTR, @this))
   ' // Return the dialog handle
   RETURN m_hDlg
END FUNCTION
' ========================================================================================

' ========================================================================================
' Internal dialog procedure.
' ========================================================================================
PRIVATE FUNCTION CDialog.CDialogProc (BYVAL hDlg AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   ' // Can't use a static variable or we will get a mess if we create another instance of the dialog
'   STATIC pDlg AS CDIALOG PTR   ' // Pointer to the CDialog class
   DIM pDlg AS CDialog PTR = CAST(CDialog PTR, GetWindowLongPtrW(hDlg, DWLP_USER))

   SELECT CASE uMsg

      CASE WM_INITDIALOG
         CDIALOG_DP("WM_INITDIALOG " & WSTR(hDlg) & " - " & WSTR(wParam) & " - " & WSTR(lParam))

      CASE WM_SYSCOMMAND
         CDIALOG_DP("WM_SYSCOMMAND")
         ' // Trap the SC_CLOSE message sent by Alt+F4 and the X-button
         IF pDlg THEN
         ' // Abort the action
            IF (wParam AND &hFFF0) = SC_CLOSE AND pDlg->IsDialogStabilized = TRUE THEN RETURN TRUE
         END IF

      CASE WM_CLOSE
         CDIALOG_DP("WM_CLOSE")
         ' // If it is a child dialog, enable its parent before it is destroyed
         DIM hParent AS HWND = GetParent(hDlg)
         IF hParent <> HWND_DESKTOP THEN
            IF IsWindowEnabled(hParent) = FALSE THEN EnableWindow(hParent, TRUE)
         END IF

      CASE WM_DESTROY
         CDIALOG_DP("WM_DESTROY")

      CASE WM_ENTERSIZEMOVE
         CDIALOG_DP("WM_ENTERSIZEMOVE")
         IF pDlg THEN
            IF pDlg->IsDialogRepaintDisabledOnResize = TRUE THEN
               pDlg->DialogEnableRepaint(FALSE)
            ELSE
               pDlg->DialogEnableRepaint(TRUE)
            END IF
         END IF

      CASE WM_EXITSIZEMOVE
         CDIALOG_DP("WM_EXITSIZEMOVE")
         IF pDlg THEN
            pDlg->DialogEnableRepaint(TRUE)
            ' // Redraw the dialog
            pDlg->DialogRedraw
         END IF

      CASE WM_CTLCOLORDLG
         ' wParam = HDC; lParam = Handle of the dialog
         IF pDlg THEN
            IF pDlg->IsDialogRepaintDisabled = FALSE THEN
               DIM nItem AS LONG = pDlg->GetColorItem(CAST(HWND, lParam))
               IF nItem >= 0 THEN
'                  OutputDebugStringW("WM_CTLCOLORDLG")
                  SetDCBrushColor(CAST(HDC, wParam), pDlg->m_rgColors(nItem).backColor)
                  RETURN CAST(LRESULT, GetStockObject(DC_BRUSH))
               END IF
            END IF
         END IF

      CASE WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC
         ' WM_CTLCOLORBTN does not color a button - use XPBUTTON
         ' wParam = HDC; lParam = Handle of the control.
         IF pDlg THEN
            IF pDlg->IsDialogRepaintDisabled = FALSE THEN
               DIM nItem AS LONG = pDlg->GetColorItem(CAST(HWND, lParam))
               IF nItem >= 0 THEN
'                  OutputDebugStringW("WM_CTLCOLOR - " & WSTR(HEX(uMsg)) & " - " & WSTR(lParam))
                  SetTextColor(CAST(HDC, wParam), pDlg->m_rgColors(nItem).foreColor)
                  SetBkColor(CAST(HDC, wParam), pDlg->m_rgColors(nItem).backColor)
                  SetDCBrushColor(CAST(HDC, wParam), pDlg->m_rgColors(nItem).backColor)
                  RETURN CAST(LRESULT, GetStockObject(DC_BRUSH))
               END IF
            END IF
         END IF

      CASE WM_SIZE
'          CDIALOG_DP("WM_SIZE pDlg: " & WSTR(pDlg) & " - wParam: " & WSTR(wParam) & " - width: " & WSTR(LOWORD(lParam)) & " - height: " & (HIWORD(lParam)))
         ' // Adjust anchored controls and redraw the dialog
         IF pDlg THEN
            IF wParam = SIZE_RESTORED OR wParam = SIZE_MAXIMIZED THEN
               IF pDlg->AdjustControls THEN pDlg->DialogRedraw
            END IF
            ' // Scrollable dialogs - Setup scrollbars
            IF pDlg->IsDialogScrollable THEN
               pDlg->DialogResetScrollbars
               pDlg->DialogSetupScrollbars
            END IF
         END IF

      CASE WM_PAINT
         ' IMPORTANT: Force frame redraw to ensure all child controls (including complex controls
         ' such as Rebar, Toolbar, Tab) are reliably repainted after resizing or other state changes.
         ' This prevents users from having to manually handle WM_PAINT or SetWindowPos for those controls.
         SetWindowPos hDlg, NULL, 0, 0, 0, 0, SWP_NOZORDER OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_DRAWFRAME

      CASE WM_HSCROLL
         ' // Horizontal scrollbar
         IF pDlg->IsDialogScrollable THEN pDlg->DialogOnHScroll(wParam, lParam)
      CASE WM_VSCROLL
         ' // Vertical scrollbar
         IF pDlg->IsDialogScrollable THEN pDlg->DialogOnVScroll(wParam, lParam)

   END SELECT

   ' // Forward the messages to the user-defined callback procedure
   IF pDlg THEN
      DIM res AS LRESULT = CallWindowProcW(CAST(WNDPROC, pDlg->m_pCallback), hDlg, uMsg, wParam, lParam)
      IF pDlg->IsCustom = FALSE THEN RETURN res
      IF res = TRUE THEN RETURN res
   END IF
   ' // Custom dialog - Deault processing for unprocessed messages
   RETURN DefDlgProcW(hDlg, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' * Shows the dialog as modeless.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogShowModeless (BYVAL pCallback AS ANY PTR = NULL) AS INT_PTR
   CDIALOG_DP("pCallback = " & WSTR(pCallback))
   m_IsModal = FALSE
   ' // Display the dialog
   ShowWindow m_hDlg, SW_SHOWNORMAL
   IF pCallback THEN
      ' // Store the user-defined dialog callback
      m_pCallback = pCallback
      ' // Set the dialog callback if it is a custom dialog
      IF m_IsCustom THEN SetWindowLongPtrW(m_hDlg, DWLP_DLGPROC, CAST(LPARAM, pCallBack))
   END IF
   ' // Send a WM_INITDIALOG message
   ' // Get the handle of the control that should receive the focus
   DIM hFocus AS HWND = GetNextDlgTabItem(m_hDlg, NULL, FALSE)
   DIM bRes AS BOOLEAN = SendMessageW(m_hDlg, WM_INITDIALOG, cast(WPARAM, hFocus), cast(LPARAM, @this))
   ' // If the user returns TRUE when processing WM_INITDIALOG set the focus to the control;
   ' // If it returns FALSE, do nothing.
   IF bRes = TRUE THEN SendMessageW(m_hDlg, WM_NEXTDLGCTL, CAST(WPARAM, hFocus), CTRUE)
   ' // Get the client area
   DIM rc AS RECT
   GetCLientRect(m_hDlg, @rc)
   DIM nWidth AS LONG = rc.Right - rc.Left
   DIM nHeight AS LONG = rc.Bottom - rc.Top
   SendMessageW m_hDlg, WM_SIZE, 0, MAKELONG(nWidth, nHeight)
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Shows the dialog as modal.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogShowModal (BYVAL pCallback AS ANY PTR = NULL) AS INT_PTR
   CDIALOG_DP("pCallback = " & WSTR(pCallback))
   ' // Flag the dialog as modal
   m_IsModal = TRUE
   ' // Display the dialog
   ShowWindow m_hDlg, SW_SHOWNORMAL
   IF pCallback THEN
      ' // Store the user-defined dialog callback
      m_pCallback = pCallback
      ' // Set the dialog callback if it is a custom dualog
      IF m_IsCustom THEN SetWindowLongPtrW(m_hDlg, DWLP_DLGPROC, CAST(LPARAM, pCallBack))
   END IF
   ' // Send a WM_INITDIALOG message
   ' // Get the handle of the control that should receive the focus
   DIM hFocus AS HWND = GetNextDlgTabItem(m_hDlg, NULL, FALSE)
   DIM bRes AS BOOLEAN = SendMessageW(m_hDlg, WM_INITDIALOG, cast(WPARAM, hFocus), cast(LPARAM, @this))
   ' // If the user returns TRUE when processing WM_INITDIALOG set the focus to the control;
   ' // If it returns FALSE, do nothing.
   IF bRes = TRUE THEN SendMessageW(m_hDlg, WM_NEXTDLGCTL, CAST(WPARAM, hFocus), CTRUE)
   ' // Get the client area
   DIM rc AS RECT
   GetCLientRect(m_hDlg, @rc)
   DIM nWidth AS LONG = rc.Right - rc.Left
   DIM nHeight AS LONG = rc.Bottom - rc.Top
   SendMessageW m_hDlg, WM_SIZE, 0, MAKELONG(nWidth, nHeight)
   ' // Disable the parent window
   DIM hParent AS HWND = GetParent(m_hDlg)
   IF hParent THEN EnableWindow(hParent, FALSE)
   ' // Message handler loop
   DO
      this.DialogDoEvents
   LOOP WHILE IsWindow(m_hDlg)
   ' // Enable the parent window (must be done in WM_CLOSE, before the dialog is destroyed)
'   IF hParent THEN EnableWindow(hParent, TRUE)
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Ends the dialog
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogEnd (BYVAL nResult AS LONG = 0) AS INT_PTR
   CDIALOG_DP("")
   ' // Store the passed exit code
   m_DlgRetVal = nResult
   '// Destroy the dialog
   DestroyWindow(m_hDlg)
   '// Exit the message loop if he user is using one
   PostQuitMessage(0)
   ' // Return the exit code
   RETURN m_DlgRetVal
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the value passed to DialogEnd
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogEndResult () AS INT_PTR
   CDIALOG_DP("")
   RETURN m_DlgRetVal
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Message pump for modeless dialogs
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogDoEvents (BYVAL dwMilliseconds AS DWORD = 1) AS BOOLEAN
   DIM uMsg AS tagMsg
   IF PeekMessageW(@uMsg, NULL, 0, 0, PM_REMOVE) THEN
      IF m_hAccel = NULL OR TranslateAcceleratorW(m_hDlg, m_hAccel, @uMsg) = 0 THEN
         IF IsDialogMessageW(GetActiveWindow, @uMsg) = 0 THEN
            TranslateMessage @uMsg
            DispatchMessage @uMsg
         END IF
      END IF
      RETURN TRUE
   ELSE
      Sleep_(dwMilliseconds)
      RETURN FALSE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the identifier of the default push button control for a dialog box.
' ========================================================================================
PRIVATE FUNCTION CDialog.GetDefId () AS INT_PTR
   RETURN LOWORD(SendMessageW(m_hDlg, DM_GETDEFID, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Changes the identifier of the default push button for a dialog box.
' ========================================================================================
PRIVATE FUNCTION CDialog.SetDefId (BYVAL cId AS LONG) AS BOOLEAN
   ' // Removes the default button because 32768 is not a valid control ID.
   SendMessageW(m_hDlg, DM_SETDEFID, 32768, 0)
   ' // Sets the specified button as the default
   RETURN SendMessageW(m_hDlg, DM_SETDEFID, cId, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Repositions a top-level dialog box so that it fits within the desktop area. 
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogReposition () AS BOOLEAN
   RETURN SendMessageW(m_hDlg, DM_REPOSITION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Change the visible state of a dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogShowState (BYVAL showState AS LONG) AS BOOLEAN
   RETURN ShowWindow(m_hDlg, showState)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Maximizes the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogMaximize () AS BOOLEAN
   RETURN ShowWindow(m_hDlg, SW_MAXIMIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Minimizes the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogMinimize () AS BOOLEAN
   RETURN ShowWindow(m_hDlg, SW_MINIMIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Hides the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogHide () AS BOOLEAN
   RETURN ShowWindow(m_hDlg, SW_HIDE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Makes the dialog visible at its normal size and position.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogNormalize () AS BOOLEAN
   RETURN ShowWindow(m_hDlg, SW_SHOWNORMAL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogDisable () AS BOOLEAN
   RETURN EnableWindow(m_hDlg, FALSE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogEnable () AS BOOLEAN
   RETURN EnableWindow(m_hDlg, CTRUE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Redraws the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogRedraw () AS BOOLEAN
   RETURN RedrawWindow(m_hDlg, NULL, NULL, RDW_INVALIDATE OR RDW_ERASE OR RDW_UPDATENOW)
END FUNCTION
' ========================================================================================

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
PRIVATE SUB CDialog.DialogForceVisibility
   ' // Check if the specified window-rectangle is visible on any display
   DIM rc AS RECT
   GetWindowRect(m_hDlg, @rc)
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
   SetWindowPos(m_hDlg, 0, rc.left, rc.top, 0, 0, SWP_NOACTIVATE OR SWP_NOZORDER OR SWP_NOSIZE)
END SUB
' ========================================================================================

' ========================================================================================
' Centers the dialog.
' ========================================================================================
' ========================================================================================
' Centers a window on the screen or over another window.
' It also ensures that the placement is done within the work area.
' Parameters:
' - hwndParent = [optional] Handle of the parent window.
' ========================================================================================
PRIVATE SUB CDialog.DialogCenter (BYVAL hwndParent AS HWND = NULL)

   DIM rc            AS RECT    ' Window coordinates
   DIM rcParent      AS RECT    ' Parent window coordinates
   DIM rcWorkArea    AS RECT    ' Work area coordinates
   DIM pt            AS POINT   ' x and y coordinates of centered window

   ' // Get the coordinates of the window
   GetWindowRect m_hDlg, @rc
   ' // Calculate the width and height of the window
   DIM nWidth AS LONG = rc.Right - rc.Left
   DIM nHeight AS LONG = rc.Bottom - rc.Top
   ' // Get the coordinates of the work area
   IF SystemParametersInfoW(SPI_GETWORKAREA, SIZEOF(rcWorkArea), @rcWorkArea, 0) = 0 THEN
      rcWorkArea.Right  = GetSystemMetrics(SM_CXSCREEN)
      rcWorkArea.Bottom = GetSystemMetrics(SM_CYSCREEN)
   END IF
   ' // Get the coordinates of the parent window
   IF hwndParent THEN
      GetWindowRect hwndParent, @rcParent
   ELSE
      rcParent.Left   = rcWorkArea.Left
      rcParent.Top    = rcWorkArea.Top
      rcParent.Right  = rcWorkArea.Right
      rcParent.Bottom = rcWorkArea.Bottom
   END IF
   ' // Calculate the width and height of the parent window
   DIM nParentWidth AS LONG = rcParent.Right - rcParent.Left
   DIM nParentHeight AS LONG = rcParent.Bottom - rcParent.Top
   ' // Calculate the new x coordinate and adjust for work area
   pt.x = rcParent.Left + ((nParentWidth - nWidth) \ 2)
   IF (pt.x < rcWorkArea.Left) THEN
      pt.x = rcWorkArea.Left
   ELSEIF ((pt.x + nWidth) > rcWorkArea.Right) THEN
      pt.x = rcWorkArea.Right - nWidth
   END IF
   ' // Calculate the new y coordinate and adjust for work area
   pt.y = rcParent.Top  + ((nParentHeight - nHeight) \ 2)
   IF (pt.y < rcWorkArea.Top) THEN
      pt.y = rcWorkArea.Top
   ELSEIF ((pt.y + nHeight) > rcWorkArea.Bottom) THEN
      pt.y = rcWorkArea.Bottom - nHeight
   END IF
   ' // Convert screen coordinates to client area coordinates
   IF (GetWindowLongPtrW(m_hDlg, GWL_STYLE) AND WS_CHILD) = WS_CHILD THEN ScreenToClient hwndParent, @pt
   ' // Reposition the window retaining its size and Z order
   SetWindowPos(m_hDlg, NULL, pt.x, pt.y, 0, 0, SWP_NOSIZE OR SWP_NOZORDER)

END SUB
' ========================================================================================

' ========================================================================================
' Makes a dialog stabilized (non-closeable).
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogStabilize () AS BOOLEAN
   ' // Get the system menu handle
   DIM hMenu AS HMENU = GetSystemMenu(m_hDlg, FALSE)
   IF hMenu = NULL THEN RETURN FALSE
   ' // Get the number of menu items
   DIM cbItems AS LONG = GetMenuItemCount(hMenu)
   IF cbItems = 0 THEN RETURN FALSE
   ' // Remove the close menu item
   IF RemoveMenu(hMenu, cbItems - 1, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Remove the separator line
   IF RemoveMenu(hMenu, cbItems - 2, MF_REMOVE OR MF_BYPOSITION) = 0 THEN RETURN FALSE
   ' // Redraw the menu (this refreshes the caption bar, dimming the X button)
   DrawMenuBar(m_hDlg)
   ' // Flags the dialog as stabilized
   m_IsStabilized = TRUE
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Makes a dialog non stable (closeable).
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogNonStable () AS BOOLEAN
   GetSystemMenu(m_hDlg, TRUE)
   DrawMenuBar(m_hDlg)
   m_IsStabilized = FALSE
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns true if the dialog is stabilized; otherwise, false.
' ========================================================================================
PRIVATE FUNCTION CDialog.IsDialogStabilized () AS BOOLEAN
   RETURN m_IsStabilized
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns true if the dialog is stabilized; otherwise, false.
' ========================================================================================
PRIVATE FUNCTION CDialog.IsDialogNonStable () AS BOOLEAN
   RETURN NOT m_IsStabilized
END FUNCTION
' ========================================================================================

' ========================================================================================
' Places (posts) a message in the message queue associated with the thread that created the
' specified dialog and returns without waiting for the thread to process the message.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogPost (BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   RETURN PostMessageW(m_hDlg, Msg, cast(WPARAM, wPrm), cast(LPARAM, lPrm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sends the specified message to a window or windows. The SendMessage function calls the
' window procedure for the dialog and does not return until the dialog procedure has
' processed the message.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSend (BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   RETURN SendMessageW(m_hDlg, Msg, cast(WPARAM, wPrm), cast(LPARAM, lPrm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts the specified dialog box units to screen units (pixels).
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogUnitsToPixels (BYVAL dluX AS LONG, BYVAL dluY AS LONG, BYREF pixelX AS LONG, BYREF pixelY AS LONG) AS BOOLEAN
   IF VARPTR(pixelX) = 0 OR VARPTR(pixelY) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   rc.Right = dluX : rc.Bottom = dluY
   DIM bResult AS BOOLEAN = MapDialogRect(m_hDlg, @rc)
   IF bResult = FALSE THEN RETURN FALSE
   IF VARPTR(pixelX) THEN pixelX = rc.Right
   IF VARPTR(pixelY) THEN pixelY = rc.Bottom
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the conversion ratios from dialog units to pixels
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogUnitsToPixelsRatios (BYREF ratioX AS SINGLE, BYREF ratioY AS SINGLE) AS BOOLEAN
   IF VARPTR(ratioX) = 0 OR VARPTR(ratioY) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   rc.Right = 4 : rc.Bottom = 8
   DIM bResult AS BOOLEAN = MapDialogRect(m_hDlg, @rc)
   IF bResult = FALSE THEN RETURN FALSE
   IF VARPTR(ratioX) THEN ratioX = rc.Right / 4
   IF VARPTR(ratioY) THEN ratioY = rc.Bottom / 8
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the conversion ratio from dialog units to pixels
' ========================================================================================
PRIVATE FUNCTION CDialog.DluToPixRX () AS SINGLE
   DIM rc AS RECT
   rc.Right = 4 : rc.Bottom = 8
   DIM bResult AS BOOLEAN = MapDialogRect(m_hDlg, @rc)
   RETURN rc.Right / 4
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the conversion ratio from dialog units to pixels
' ========================================================================================
PRIVATE FUNCTION CDialog.DluToPixRY () AS SINGLE
   DIM rc AS RECT
   rc.Right = 4 : rc.Bottom = 8
   DIM bResult AS BOOLEAN = MapDialogRect(m_hDlg, @rc)
   RETURN rc.Bottom / 8
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts the specified screen units (pixels) to dialog box units.
' ========================================================================================
PRIVATE FUNCTION CDialog.PixelsToDialogUnits (BYVAL pixelX AS LONG, BYVAL pixelY AS LONG, BYREF dluX AS LONG, BYREF dluY AS LONG) AS BOOLEAN
   IF VARPTR(pixelX) = 0 OR VARPTR(pixelY) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   rc.Right = 4
   rc.Bottom = 8
   DIM bResult AS BOOLEAN = MapDialogRect(m_hDlg, @rc)
   IF bResult = FALSE THEN RETURN FALSE
   IF VARPTR(dluX) THEN dluX = pixelX * (4.0 / rc.right)
   IF VARPTR(dluY) THEN dluY = pixelY * (8.0 / rc.bottom)
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the conversion ratios from pixels to dialog units
' ========================================================================================
PRIVATE FUNCTION CDialog.PixelsToDialogUnitsRatios (BYREF ratioX AS SINGLE, BYREF ratioY AS SINGLE) AS BOOLEAN
   IF VARPTR(ratioX) = 0 OR VARPTR(ratioY) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   rc.Right = 4 : rc.Bottom = 8
   DIM bResult AS BOOLEAN = MapDialogRect(m_hDlg, @rc)
   IF bResult = FALSE THEN RETURN FALSE
   IF VARPTR(ratioX) THEN ratioX = 4.0 / rc.right
   IF VARPTR(ratioY) THEN ratioY = 8.0 / rc.bottom
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the conversion ratio from pixels to dialog units
' ========================================================================================
PRIVATE FUNCTION CDialog.PixToDluRX () AS SINGLE
   DIM rc AS RECT
   rc.Right = 4 : rc.Bottom = 8
   MapDialogRect(m_hDlg, @rc)
   RETURN 4.0 / rc.right
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the conversion ratio from pixels to dialog units
' ========================================================================================
PRIVATE FUNCTION CDialog.PixToDluRY () AS SINGLE
   DIM rc AS RECT
   rc.Right = 4 : rc.Bottom = 8
   MapDialogRect(m_hDlg, @rc)
   RETURN 8.0 / rc.bottom
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width and height of the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetSize (BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   IF VARPTR(nWidth) = 0 OR VARPTR(nHeight) = 0 THEN RETURN FALSE
   ' // Get the dimensions of the window
   DIM rc AS RECT
   GetWindowRect(m_hDlg, @rc)
   ' // Return the width and height
   IF m_UsePixels = FALSE THEN RETURN this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   nWidth = rc.Right - rc.Left
   nHeight = rc.Bottom - rc.Top
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width of the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetWidth () AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetWindowRect(m_hDlg, @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
   END IF
   RETURN nWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the height of the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetHeight () AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetWindowRect(m_hDlg, @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN nHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the size of the dialog.
' - nWidth = The new width of the window.
' - nHeight = The new height of the window.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSetSize (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   IF m_UsePixels = FALSE THEN this.DialogUnitsToPixels(nWidth, nHeight, nWidth, nHeight)
   RETURN SetWindowPos(m_hDlg, NULL, 0, 0, nWidth, nHeight, SWP_NOZORDER OR SWP_NOMOVE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounds of a window without the drop shadows.
' In Windows Vista and later, the Window Rect includes the area occupied by the drop shadow.
' Calling GetWindowRect will have different behavior depending on whether the window has
' ever been shown or not. If the window has not been shown before, GetWindowRect will not
' include the area of the drop shadow.
' To get the window bounds excluding the drop shadow, use DwmGetWindowAttribute, specifying
' DWMWA_EXTENDED_FRAME_BOUNDS. Note that unlike the Window Rect, the DWM Extended Frame Bounds
' are not adjusted for DPI. Getting the extended frame bounds can only be done after the
' window has been shown at least once.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetBounds () AS RECT
   DIM rc AS RECT
   DIM AS ANY PTR pLib = DyLibLoad("Dwmapi.DLL")
   IF pLib  THEN
      DIM pProc AS FUNCTION (BYVAL hDlg AS .HWND, BYVAL dwAttribute AS DWORD, BYVAL pvAttribute AS ANY PTR, BYVAL cbAttribute AS DWORD) AS HRESULT
      pProc = DyLibSymbol(pLib, "DwmGetWindowAttribute")
      ' DWMWA_EXTENDED_FRAME_BOUNDS = 9
      IF pProc THEN pProc(m_hDlg, 9, @rc, SIZEOF(rc))
      DyLibFree(pLib)
      ' // Convert to dialog units
      IF m_UsePixels = FALSE THEN
         this.PixelsToDialogUnits(rc.Left, rc.Top, rc.Left, rc.Top)
         this.PixelsToDialogUnits(rc.Right, rc.Bottom, rc.Right, rc.Bottom)
      END IF
   END IF
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the coordinates of the dialog's client area. The client coordinates specify the
' upper-left and lower-right corners of the client area. Because client coordinates are
' relative to the upper-left corner of a window's client area, the coordinates of the
' upper-left corner are (0,0).
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetClient (BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   IF VARPTR(nWidth) = 0 OR VARPTR(nHeight) = 0 THEN RETURN FALSE
   ' // Get the dimensions of the window
   DIM rc AS RECT
   GetClientRect(m_hDlg, @rc)
   ' // Return the width and height values
   IF m_UsePixels = FALSE THEN
      RETURN this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width of the the dialog's client area.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetClientWidth () AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetClientRect(m_hDlg, @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
   END IF
   RETURN nWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the height of the dialog's client area.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetClientHeight () AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetClientRect(m_hDlg, @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN nHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adjusts the bounding rectangle of the dialog based on the desired size of the client area.
' Parameters:
' - nWidth = The new width of the client area of the dialog.
' - nHeight = The new height of the client area of the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSetClient (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   ' // Convert dialog units to pixels
   IF m_UsePixels = FALSE THEN this.DialogUnitsToPixels(nWidth, nHeight, nWidth, nHeight)
   ' // Convert the client rectangle to a window rectangle.
   ' // The AdjustWindowRectEx function cannot take menu wrapping into account
   ' // because it doesn't know which menu we are using.
   DIM rc AS RECT, rcTemp  AS RECT
   IF m_UsePixels THEN nWidth *= m_rx : nHeight *= m_ry
   SetRect(@rc, 0, 0, nWidth, nHeight)
   DIM hMenu AS HANDLE = GetMenu(m_hDlg)
   DIM dwStyle AS DWORD = GetWindowLongPtrW(m_hDlg, GWL_STYLE)
   AdjustWindowRectEx(@rc, dwStyle, (hMenu <> NULL), GetWindowLongPtrW(m_hDlg, GWL_EXSTYLE))
   ' // If there is a menu, we need to check how much wrapping occurs when we set
   ' // the window to the width specified by AdjustWindowRectEX and an infinite
   ' // amount of height. An infinite height allows us to see every single menu wrap.
   IF hMenu <> NULL THEN
      rcTemp = rc
      rcTemp.Bottom = &H7FFF   ' // "Infinite" height
      SendMessageW(m_hDlg, WM_NCCALCSIZE, 0, CAST(LPARAM, @rcTemp))
      ' // Adjust our previous calculation to compensate for menu wrapping.
      rc.Bottom = rc.Bottom + rcTemp.Top
   END IF
   ' // The AdjustWindowRectEx function does not take the WS_VSCROLL or WS_HSCROLL
   ' // styles into account. To account for the scroll bars, we need to call the
   ' // GetSystemMetrics function with SM_CXVSCROLL or SM_CYHSCROLL.
   IF (dwStyle AND WS_HSCROLL) = WS_HSCROLL THEN
      rc.Bottom = rc.Bottom + GetSystemMetrics(SM_CYHSCROLL)
   END IF
   IF (dwStyle AND WS_VSCROLL) = WS_VSCROLL THEN
      rc.Right = rc.Right + GetSystemMetrics(SM_CXVSCROLL)
   END IF
   DIM cx AS LONG = rc.Right - rc.Left
   DIM cy AS LONG = rc.Bottom - rc.Top
   RETURN SetWindowPos(m_hDlg, NULL, 0, 0, cx, cy, SWP_NOZORDER OR SWP_NOMOVE OR SWP_NOACTIVATE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle of the font used by the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetFont () AS HFONT
   RETURN CAST(HFONT, SendMessageW(m_hDlg, WM_GETFONT, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the face name of the font used by the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetFontFaceName () AS DWSTRING
   ' // Get the handle of the font used by the dialog
   DIM hCurFont AS HFONT = CAST(HFONT, SendMessageW(m_hDlg, WM_GETFONT, 0, 0))
   IF hCurFont = NULL THEN RETURN ""   
   ' // Get the LOGFONTW structure
   DIM lfw AS LOGFONTW
   IF hCurFont THEN GetObjectW(hCurFont, SIZEOF(lfw), @lfw)
   RETURN lfw.lfFaceName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the point size of the font used by the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetFontPointSize () AS LONG
   ' // Get the handle of the font used by the dialog
   DIM hCurFont AS HFONT = CAST(HFONT, SendMessageW(m_hDlg, WM_GETFONT, 0, 0))
   IF hCurFont = NULL THEN RETURN 0
   ' // Get the LOGFONTW structure
   DIM lfw AS LOGFONTW
   IF hCurFont THEN GetObjectW(hCurFont, SIZEOF(lfw), @lfw)
   DIM hDc AS HDC = GetDC(m_hDlg)
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(m_hDlg, hDC)
   DIM ptSize AS LONG = MulDiv(lfw.lfHeight, 72, cyPixelsPerInch)
   IF ptSize < 0 THEN ptSize = -ptSize
   RETURN ptSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text in a dialog or window caption.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetText () AS DWSTRING
   DIM nLen AS LONG = SendMessageW(m_hDlg, WM_GETTEXTLENGTH, 0, 0)
   DIM dwsText AS DWSTRING = SPACE(nLen + 1)
   SendMessageW(m_hDlg, WM_GETTEXT, nLen + 1, cast(LPARAM, dwsText))
   RETURN LEFT(dwsText, LEN(dwsText) - 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text in a dialog or window caption.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSetText (BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
'   RETURN SendMessageW(m_hDlg, WM_SETTEXT, 0, CAST(LPARAM, pwszText))
   RETURN SetWindowTextW(m_hDlg, pwszText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the location of the top left corner of the window.
' The location is relative to the upper-left corner of the client area in the parent window.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogGetLoc (BYREF nLeft AS LONG, BYREF nTop AS LONG) AS BOOLEAN
   IF VARPTR(nLeft) = 0 OR VARPTR(nTop) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   ' // Get the dimensions of the window
   GetWindowRect(m_hDlg, @rc)
   ' // Convert the coordinates to be relative to the parent
   MapWindowPoints(HWND_DESKTOP, GetParent(m_hDlg), CAST(POINT PTR, @rc), 2)
   ' // Return the left and top values
   IF m_UsePixels = FALSE THEN
      RETURN this.PixelsToDialogUnits(rc.Left, rc.Top, nLeft, nTop)
   ELSE
      nLeft = rc.Left
      nTop = rc.Top
   END IF
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the location of the top left corner of the window.
' The location is relative to the upper-left corner of the client area in the parent window.
' Return value: TRUE or FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSetLoc (BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
   IF m_UsePixels = FALSE THEN DialogUnitsToPixels(nLeft, nTop, nLeft, nTop)
   RETURN SetWindowPos(m_hDlg, 0, nLeft, nTop, 0, 0, SWP_NOSIZE OR SWP_NOZORDER)
END FUNCTION
' ========================================================================================

' =====================================================================================
' * Retrieves a value from the user data area of the dialog.
' idx = The index number of the user data value to retrieve, in the range 0 to 99 inclusive.
' =====================================================================================
PRIVATE FUNCTION CDialog.DialogGetUser (BYVAL idx AS LONG) AS LONG_PTR
   IF idx < 0 OR idx > 99 THEN RETURN 0
   RETURN m_rgUserData(idx)
END FUNCTION
' =====================================================================================

' =====================================================================================
' * Sets a value in the user data area of a dialog.
' idx = The index number of the user data value to retrieve, in the range 0 to 99 inclusive.
' =====================================================================================
PRIVATE SUB CDialog.DialogSetUser (BYVAL idx AS LONG, BYVAL newValue AS LONG_PTR)
   IF idx > -1 AND idx < 100 THEN m_rgUserData(idx) = newValue
END SUB
' =====================================================================================

' =====================================================================================
' * Sets the big and small icons of the dialog.
' =====================================================================================
PRIVATE SUB CDialog.DialogSetIconEx (BYVAL hIconBig AS HICON, BYVAL hIconSmall AS HICON)
   SendMessageW(m_hDlg, WM_SETICON, ICON_BIG, cast(LPARAM, hIconBig))
   SendMessageW(m_hDlg, WM_SETICON, ICON_SMALL, cast(LPARAM, hIconSmall))
END SUB
' =====================================================================================

' ========================================================================================
' * Sets the focus in the specified control of a dialog box.
' See https://devblogs.microsoft.com/oldnewthing/20040802-00/?p=38283
' ========================================================================================
PRIVATE SUB CDialog.ControlSetFocus (BYVAL cId AS LONG)
   SendMessageW(m_hDlg, WM_NEXTDLGCTL, cast(WPARAM, GetDlgItem(m_hDlg, cId)), CTRUE)
END SUB
' ========================================================================================

' ========================================================================================
' * Disables the specified control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlDisable (BYVAL cId AS LONG) AS BOOLEAN
   RETURN EnableWindow(GetDlgItem(m_hDlg, cId), FALSE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Enables the specified control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlEnable (BYVAL cId AS LONG) AS BOOLEAN
   RETURN EnableWindow(GetDlgItem(m_hDlg, cId), CTRUE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the location of the top left corner of the window.
' The location is relative to the upper-left corner of the client area in the parent window.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetLoc (BYVAL cId AS LONG, BYREF nLeft AS LONG, BYREF nTop AS LONG) AS BOOLEAN
   IF VARPTR(nLeft) = 0 OR VARPTR(nTop) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   ' // Get the dimensions of the window
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cID)
   GetWindowRect(hCtl, @rc)
   ' // Convert the coordinates to be relative to the parent
   MapWindowPoints(HWND_DESKTOP, GetParent(hCtl), CAST(POINT PTR, @rc), 2)
   ' // Return the left and top values
   IF m_UsePixels = FALSE THEN
      RETURN this.PixelsToDialogUnits(rc.Left, rc.Top, nLeft, nTop)
   ELSE
      nLeft = rc.Left
      nTop = rc.Top
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the location of the top left corner of the window.
' The location is relative to the upper-left corner of the client area in the parent window.
' Return value: TRUE or FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetLoc (BYVAL cId AS LONG, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
   IF m_UsePixels = FALSE THEN DialogUnitsToPixels(nLeft, nTop, nLeft, nTop)
   RETURN SetWindowPos(GetDlgItem(m_hDlg, cId), 0, nLeft, nTop, 0, 0, SWP_NOSIZE OR SWP_NOZORDER)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the text in a control or control caption.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetText (BYVAL cId AS LONG) AS DWSTRING
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cID)
   DIM nLen AS LONG = SendMessageW(hCtl, WM_GETTEXTLENGTH, 0, 0)
   DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
   SendMessageW(hCtl, WM_GETTEXT, nLen + 1, cast(LPARAM, *dwsText))
   RETURN LEFT(dwsText, LEN(dwsText) - 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text in a control or control caption.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetText (BYVAL cId AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
'   RETURN SendMessageW(GetDlgItem(m_hDlg, cID), WM_SETTEXT, 0, CAST(LPARAM, pwszText))
   RETURN SetWindowTextW(GetDlgItem(m_hDlg, cID), pwszText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a window handle for the specified control ID.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlHandle (BYVAL cId AS LONG) AS HWND
   RETURN GetDlgItem(m_hDlg, cID)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Hides the specified control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlHide (BYVAL cId AS LONG) AS BOOLEAN
   RETURN ShowWindow(GetDlgItem(m_hDlg, cId), SW_HIDE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Makes visible the specified control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlNormalize (BYVAL cId AS LONG) AS BOOLEAN
   RETURN ShowWindow(GetDlgItem(m_hDlg, cId), SW_SHOW)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Destroys the specified control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlKill (BYVAL cId AS LONG) AS BOOLEAN
   RETURN DestroyWindow(GetDlgItem(m_hDlg, cId))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Changes the visible state of a control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlShowState (BYVAL cId AS LONG, BYVAL showState AS LONG) AS BOOLEAN
   RETURN ShowWindow(GetDlgItem(m_hDlg, cId), showState)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Redraws the specified control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlRedraw (BYVAL cId AS LONG) AS BOOLEAN
   RETURN RedrawWindow(GetDlgItem(m_hDlg, cId), NULL, NULL, RDW_INVALIDATE OR RDW_UPDATENOW)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a logical font.
' Parameters:
' - wszFaceName = The typeface name.
' - lPointSize = The point size.
' - DPI = Dots per inch to calculate scaling. Default value = 96 (no scaling). If you pass -1
'   and the application is DPI aware, the DPI value used by the operating system will be used.
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
'   hFont = FontNew("MS Sans Serif", 8, FW_NORMAL)
'   hFont = FontNew("Courier New", 10, FW_BOLD)
'   hFont = FontNew("Marlett", 8, FW_NORMAL, , , , SYMBOL_CHARSET)
' ========================================================================================
PRIVATE FUNCTION CDialog.FontNew (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, _
   BYVAL lWeight AS LONG = 0, BYVAL bItalic AS UBYTE = FALSE, BYVAL bUnderline AS UBYTE = FALSE, _
   BYVAL bStrikeOut AS UBYTE = FALSE, BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS HFONT

   DIM tlfw AS LOGFONTW
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)

   ' // Font scaling
   DIM DPI AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   IF DPI > 0 THEN lPointSize = (lPointSize * DPI) \ GetDeviceCaps(hDC, LOGPIXELSY)

   tlfw.lfHeight         = -MulDiv(lPointSize, .GetDeviceCaps(hDC, LOGPIXELSY), 72)  ' logical font height
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
   tlfw.lfFaceName       =  wszFaceName                                              ' typeface name

   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = CreateFontIndirectW(@tlfw)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Destroys a font when it is no longer needed.
' ========================================================================================
PRIVATE SUB CDialog.FontEnd (BYVAL hFont AS HFONT)
   DeleteObject hFont
END SUB
' ========================================================================================

' ========================================================================================
' Gets the handle of the font used by the control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetFont (BYVAL cId AS LONG) AS HFONT
   RETURN CAST(HFONT, SendMessageW(GetDLgItem(m_hDlg, cId), WM_GETFONT, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font that a control is to use when drawing text.
' ========================================================================================
PRIVATE SUB CDialog.ControlSetFont (BYVAL cId AS LONG, BYVAL hFont AS HFONT, BYVAL fRedraw AS BOOLEAN = TRUE)
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   DIM hDC AS HDC = GetDC(hCtl)
   DeleteObject(SelectObject(hDC, CAST(HGDIOBJ, hFont)))
   ReleaseDC(hCtl, hDC)
   SendMessageW(hCtl, WM_SETFONT, CAST(WPARAM, hFont), fRedraw)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the face name of the font used by the control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetFontFaceName (BYVAL cId AS LONG) AS DWSTRING
   ' // Get the handle of the font used by the dialog
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   DIM hCurFont AS HFONT = CAST(HFONT, SendMessageW(hCtl, WM_GETFONT, 0, 0))
   ' // Get the LOGFONTW structure
   DIM lfw AS LOGFONTW
   IF hCurFont THEN GetObjectW(hCurFont, SIZEOF(lfw), @lfw)
   DIM hDc AS HDC = GetDC(hCtl)
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(hCtl, hDC)
   RETURN lfw.lfFaceName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the point size of the font used by the control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetFontPointSize (BYVAL cId AS LONG) AS LONG
   ' // Get the handle of the font used by the dialog
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   DIM hCurFont AS HFONT = CAST(HFONT, SendMessageW(hCtl, WM_GETFONT, 0, 0))
   ' // Get the LOGFONTW structure
   DIM lfw AS LOGFONTW
   IF hCurFont THEN GetObjectW(hCurFont, SIZEOF(lfw), @lfw)
   DIM hDc AS HDC = GetDC(hCtl)
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(hCtl, hDC)
   DIM ptSize AS LONG = MulDiv(lfw.lfHeight, 72, cyPixelsPerInch)
   IF ptSize < 0 THEN ptSize = -ptSize
   RETURN ptSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets/gets the return value of a message processed in the dialog box procedure.
' Return value: TRUE or FALSE.
' Must be set just before exiting the callback message (not after calling other functions)
' See https://forum.powerbasic.com/forum/user-to-user-discussions/programming/19130-info-dwl_msgresult
' Messages that may need the use of this method:
' WM_CTLCOLORMSGBOX, WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORBTN, WM_CTLCOLORDLG
' WM_CTLCOLORSCROLLBAR, WM_CTLCOLORSTATIC, WM_COMPAREITEM, WM_VKEYTOITEM, WM_CHARTOITEM
' WM_QUERYDRAGICON, WM_INITDIALOG.
' #define SetDlgMsgResult(hwnd,msg,result) (iif((msg)=WM_CTLCOLORMSGBOX orelse (msg)=WM_CTLCOLOREDIT
' orelse (msg)=WM_CTLCOLORLISTBOX orelse (msg)=WM_CTLCOLORBTN orelse (msg)=WM_CTLCOLORDLG
' orelse (msg)=WM_CTLCOLORSCROLLBAR orelse (msg)=WM_CTLCOLORSTATIC orelse (msg)=WM_COMPAREITEM
' orelse (msg)=WM_VKEYTOITEM orelse (msg)=WM_CHARTOITEM orelse (msg)=WM_QUERYDRAGICON
' orelse (msg)=WM_INITDIALOG, cast(WINBOOL, (result)), (SetWindowLongPtr((hwnd),DWLP_MSGRESULT,
' cast(LPARAM, cast(LRESULT, result)),TRUE))))
' See also this info message from Dominic Mitchell in the PowerBasic forum:
' https://forum.powerbasic.com/forum/user-to-user-discussions/programming/19130-info-dwl_msgresult
' And Rasymond Chen: https://devblogs.microsoft.com/oldnewthing/20031112-00/?p=41863
' Note: If you return a result using this function, your callback procedure must return TRUE.
' ========================================================================================
PRIVATE FUNCTION CDialog.CBSetDlgMsgResult(BYVAL result AS LONG_PTR) AS LONG_PTR
   RETURN SetWindowLongPtrW(m_hDlg, DWLP_MSGRESULT, result)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CDialog.CBGetDlgMsgResult () AS LONG_PTR
   RETURN GetWindowLongPtrW(m_hDlg, DWLP_MSGRESULT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Places (posts) a message in the message queue associated with the thread that created the
' specified window and returns without waiting for the thread to process the message.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlPost (BYVAL cId AS LONG, BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   RETURN PostMessageW(GetDlgItem(m_hDlg, cId), Msg, cast(WPARAM, wPrm), cast(LPARAM, lPrm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sends the specified message to a window or windows. The SendMessage function calls the
' window procedure for the specified window and does not return until the window procedure
' has processed the message.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSend (BYVAL cId AS LONG, BYVAL Msg AS UINT, BYVAL wPrm AS LONG_PTR, BYVAL lPrm AS LONG_PTR) AS BOOLEAN
   RETURN SendDlgItemMessageW(m_hDlg, cId, Msg, cast(WPARAM, wPrm), cast(LPARAM, lPrm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width and height of the control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetSize (BYVAL cId AS LONG, BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   IF VARPTR(nWidth) = 0 OR VARPTR(nHeight) = 0 THEN RETURN FALSE
   ' // Get the dimensions of the window
   DIM rc AS RECT
   GetWindowRect(GetDlgItem(m_hDlg, cId), @rc)
   ' // Return the width and height
   IF m_UsePixels = FALSE THEN
      RETURN this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width of the control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetWidth (BYVAL cId AS LONG) AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetWindowRect(GetDLgItem(m_hDlg, cId), @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
   END IF
   RETURN nWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the height of the control.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetHeight (BYVAL cId AS LONG) AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetWindowRect(GetDlgItem(m_hDlg, cId), @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN nHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the size of the specified window.
' - nWidth = The new width of the window.
' - nHeight = The new height of the window.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetSize (BYVAL cId AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   IF m_UsePixels = FALSE THEN this.DialogUnitsToPixels(nWidth, nHeight, nWidth, nHeight)
   RETURN SetWindowPos(GetDlgItem(m_hDlg, cId), NULL, 0, 0, nWidth, nHeight, SWP_NOZORDER OR SWP_NOMOVE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the coordinates of the control's client area. The client coordinates specify the
' upper-left and lower-right corners of the client area. Because client coordinates are
' relative to the upper-left corner of a window's client area, the coordinates of the
' upper-left corner are (0,0).
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetClient (BYVAL cId AS LONG, BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   IF VARPTR(nWidth) = 0 OR VARPTR(nHeight) = 0 THEN RETURN FALSE
   ' // Get the dimensions of the window
   DIM rc AS RECT
   GetClientRect(GetDlgItem(m_hDlg, cId), @rc)
   ' // Return the width and height values
   IF m_UsePixels = FALSE THEN
      RETURN this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width of the the control's client area
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetClientWidth (BYVAL cId AS LONG) AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetClientRect(GetDlgItem(m_hDlg, cId), @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nWidth = rc.Right - rc.Left
   END IF
   RETURN nWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the height of the control's client area.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetClientHeight (BYVAL cId AS LONG) AS LONG
   ' // Get the dimensions of the window
   DIM rc AS RECT
   FUNCTION = GetClientRect(GetDlgItem(m_hDlg, cId), @rc)
   ' // Return the width
   DIM AS LONG nWidth, nHeight
   IF m_UsePixels = FALSE THEN
      this.PixelsToDialogUnits(rc.Right - rc.Left, rc.Bottom - rc.Top, nWidth, nHeight)
   ELSE
      nHeight = rc.Bottom - rc.Top
   END IF
   RETURN nHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adjusts the bounding rectangle of the dialog based on the desired size of the client area.
' Parameters:
' - nWidth = The new width of the client area of the dialog.
' - nHeight = The new height of the client area of the dialog.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetClient (BYVAL cId AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   ' // Convert dialog units to pixels
   IF m_UsePixels = FALSE THEN this.DialogUnitsToPixels(nWidth, nHeight, nWidth, nHeight)
   RETURN SetWindowPos(GetDlgItem(m_hDlg, cId), NULL, 0, 0, nWidth, nHeight, SWP_NOZORDER OR SWP_NOMOVE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Moves the control to the center of the dialog horizontally
' - cId = Identifier of the control
' ========================================================================================
PRIVATE SUB CDialog.ControlCenterHoriz (BYVAL cId AS LONG)
   DIM hCtrl AS HWND = GetDlgItem(m_hDlg, cId)
   IF hCtrl = NULL THEN EXIT SUB
   DIM rc AS RECT, rcParent AS RECT
   ' // Get the coordinates of the control
   GetWindowRect hCtrl, @rc
   DIM nWidthControl AS LONG = rc.Right - rc.Left
   DIM nHeightControl AS LONG = rc.Bottom - rc.Top
   ' // Get the coordinates of the parent window
   DIM hParent AS HWND = GetParent(hCtrl)
   GetClientRect hParent, @rcParent
   DIM nWidthParent AS LONG = rcParent.Right - rcParent.Left
   ' // Calculate the x coordinate to center the control horizontally
   DIM x AS LONG = (nWidthParent - nWidthControl) \ 2
   ' // Convert the y coordinate of the control to client area coordinate
   DIM pt AS POINT
   pt.y = rc.Top
   ScreenToClient hParent, @pt
   MoveWindow hCtrl, x, pt.y, nWidthControl, nHeightControl, CTRUE
END SUB
' ========================================================================================

' ========================================================================================
' * Moves the control to the center of the dialog vertically
' - cId = Identifier of the control
' ========================================================================================
PRIVATE SUB CDialog.ControlCenterVert (BYVAL cId AS LONG)
   DIM hCtrl AS HWND = GetDlgItem(m_hDlg, cId)
   DIM rc AS RECT, rcParent AS RECT
   ' // Get the coordinates of the control
   GetWindowRect hCtrl, @rc
   DIM nWidthControl AS LONG = rc.Right - rc.Left
   DIM nHeightControl AS LONG = rc.Bottom - rc.Top
   ' // Get the coordinates of the parent window
   DIM hParent AS HWND = GetParent(hCtrl)
   GetClientRect hParent, @rcParent
   DIM nHeightParent AS LONG = rcParent.Bottom - rcParent.Top
   ' // Calculate the x coordinate to center the control vertically
   DIM y AS LONG = (nHeightParent - nHeightControl) \ 2
   ' // Convert the x coordinate of the control to client area coordinate
   DIM pt AS POINT
   pt.x = rc.Left
   ScreenToClient hParent, @pt
   MoveWindow hCtrl, pt.x + (nWidthControl \ 2), y, nWidthControl, nHeightControl, CTRUE
END SUB
' ========================================================================================

' ========================================================================================
' Gets the check state of a radio button or check box. 
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetCheck (BYVAL cId AS LONG) AS LONG
   DIM hCtrl AS HWND = GetDlgItem(m_hDlg, cId)
   RETURN SendMessageW(hCtrl, BM_GETCHECK, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the check state of a radio button or check box.
' ========================================================================================
PRIVATE SUB CDialog.ControlSetCheck (BYVAL cId AS LONG, BYVAL checkState AS LONG)
   DIM hCtrl AS HWND = GetDlgItem(m_hDlg, cId)
   SendMessageW(hCtrl, BM_SETCHECK, checkState, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the check state for an Option (radio) control, and unsets the check state for other Option buttons in a group.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetOption (BYVAL cId AS LONG, BYVAL minId AS LONG, BYVAL maxId AS LONG) AS BOOLEAN
   RETURN ..CheckRadioButton(GetDlgItem(m_hDlg, cId), minId, maxId, cId)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                *** Image procedures ***
' ########################################################################################

' ========================================================================================
' Changes both the dialog icon in the caption, and the icon shown in the ALT+TAB task list.
' The old image handle is released.
' ========================================================================================
PRIVATE SUB CDialog.DialogSetIcon (BYREF wszImage AS WSTRING)
   ' // Loads the icon from resource
   DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
   IF LEFT(wszImage, 1) = "#" THEN
      wID = VAL(MID(wszImage, 2))
      dwID = MAKELONG(wID, 0)
      hImage = LoadImageW(m_hInstance, MAKEINTRESOURCEW(dwID), IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
   ELSE
      ' // Loads the icon from file
      IF UCASE(RIGHT(wszImage, 4)) = ".ICO" THEN
         hImage = LoadImageW(NULL, wszImage, IMAGE_ICON, 0, 0, LR_LOADFROMFILE)
      ELSE
         ' // Loads the icon from resource
         hImage = LoadImageW(m_hInstance, wszImage, IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
      END IF
   END IF
   ' // Sets the images and deletes the old ones
   IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(m_hDlg, WM_SETICON, ICON_BIG, CAST(LPARAM, hImage))))
   IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(m_hDlg, WM_SETICON, ICON_SMALL, CAST(LPARAM, hImage))))
END SUB
' =====================================================================================

' =====================================================================================
' Finds the resource type given it's identifier or name.
' =====================================================================================
PRIVATE FUNCTION CDialog.FindResourceType (BYREF wszResourceName AS WSTRING) AS STRING
   IF LEFT(wszResourceName, 1) = "#" THEN
      DIM wID AS WORD, dwID AS DWORD
      wID = VAL(MID(wszResourceName, 2))
      dwID = MAKELONG(wID, 0)
      IF FindResourceW(m_hInstance, MAKEINTRESOURCEW(dwID), CAST(LPCWSTR, RT_GROUP_ICON)) THEN RETURN "RT_GROUP_ICON"
      IF FindResourceW(m_hInstance, MAKEINTRESOURCEW(dwID), CAST(LPCWSTR, RT_ICON)) THEN RETURN "RT_ICON"
      IF FindResourceW(m_hInstance, MAKEINTRESOURCEW(dwID), CAST(LPCWSTR, RT_BITMAP)) THEN RETURN "RT_BITMAP"
      IF FindResourceW(m_hInstance, MAKEINTRESOURCEW(dwID), CAST(LPCWSTR, RT_RCDATA)) THEN RETURN "RT_RCDATA"
   ELSE
      IF FindResourceW(m_hInstance, wszResourceName, CAST(LPCWSTR, RT_GROUP_ICON)) THEN RETURN "RT_GROUP_ICON"
      IF FindResourceW(m_hInstance, wszResourceName, CAST(LPCWSTR, RT_ICON)) THEN RETURN "RT_ICON"
      IF FindResourceW(m_hInstance, wszResourceName, CAST(LPCWSTR, RT_BITMAP)) THEN RETURN "RT_BITMAP"
      IF FindResourceW(m_hInstance, wszResourceName, CAST(LPCWSTR, RT_RCDATA)) THEN RETURN "RT_RCDATA"
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the icon or bitmap displayed in a label.
' The size of the label is adjusted to the size of the image.
' The old image handle is released.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetImage (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   IF hCtl = NULL THEN RETURN FALSE
   '// Check the type if resource (icon or bitmap)
   DIM strType AS STRING = this.FindResourceType(wszImage)
   DIM nType AS LONG
   IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = IMAGE_ICON ELSE IF strType = "RT_BITMAP" THEN nType = IMAGE_BITMAP
   ' // Loads the image from resource
   DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
   IF LEFT(wszImage, 1) = "#" THEN
      wID = VAL(MID(wszImage, 2))
      dwID = MAKELONG(wID, 0)
      hImage = .LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), nType, 0, 0, LR_DEFAULTCOLOR)
   ELSE
      ' // Loads the image from file
      IF UCASE(RIGHT(wszImage, 4)) = ".ICO" THEN
         hImage = .LoadImageW(NULL, wszImage, nType, 0, 0, LR_LOADFROMFILE)
      ELSE
         ' // Loads the icon from resource
         hImage = .LoadImageW(m_hInstance, wszImage, nType, 0, 0, LR_DEFAULTCOLOR)
      END IF
   END IF
   ' // Sets the image and deletes the old one
   DIM h AS HANDLE
   IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(hCtl, STM_SETIMAGE, nType, CAST(LPARAM, hImage))))
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the icon or bitmap displayed in a label
' The size of the image is streched to fit the size of the control.
' The old image handle is released.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetImageX (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   IF hCtl = NULL THEN RETURN FALSE
   '// Check the type if resource (icon or bitmap)
   DIM strType AS STRING = this.FindResourceType(wszImage)
   DIM nType AS LONG
   IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = IMAGE_ICON ELSE IF strType = "RT_BITMAP" THEN nType = IMAGE_BITMAP
   ' // Loads the image from resource
   DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
   DIM rc AS RECT
   GetClientRect(hCtl, @rc)
   DIM AS LONG nWidth, nHeight
   nWidth = rc.right - rc.left
   nHeight = rc.bottom -rc.top
   IF LEFT(wszImage, 1) = "#" THEN
      wID = VAL(MID(wszImage, 2))
      dwID = MAKELONG(wID, 0)
      hImage = .LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), nType, nWidth, nHeight, LR_DEFAULTCOLOR)
   ELSE
      ' // Loads the image from file
      IF UCASE(RIGHT(wszImage, 4)) = ".ICO" THEN
         hImage = .LoadImageW(NULL, wszImage, nType, nWidth, nHeight, LR_LOADFROMFILE)
      ELSE
         ' // Loads the icon from resource
         hImage = .LoadImageW(m_hInstance, wszImage, nType, nWidth, nHeight, LR_DEFAULTCOLOR)
      END IF
   END IF
   ' // Sets the image and deletes the old one
   DIM h AS HANDLE
   IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(hCtl, STM_SETIMAGE, nType, CAST(LPARAM, hImage))))
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the icon or bitmap displayed in a button.
' The size of the button does not change; The image is clipped if it does nt fit in the button.
' The old image handle is released.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetImgButton (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   IF hCtl = NULL THEN RETURN FALSE
   '// Check the type if resource (icon or bitmap)
   DIM strType AS STRING = this.FindResourceType(wszImage)
   DIM nType AS LONG
   IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = IMAGE_ICON ELSE IF strType = "RT_BITMAP" THEN nType = IMAGE_BITMAP
   ' // Loads the image from resource
   DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
   IF LEFT(wszImage, 1) = "#" THEN
      wID = VAL(MID(wszImage, 2))
      dwID = MAKELONG(wID, 0)
      hImage = .LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), nType, 0, 0, LR_DEFAULTCOLOR)
   ELSE
      ' // Loads the image from file
      IF UCASE(RIGHT(wszImage, 4)) = ".ICO" THEN
         hImage = .LoadImageW(NULL, wszImage, nType, 0, 0, LR_LOADFROMFILE)
      ELSE
         ' // Loads the icon from resource
         hImage = .LoadImageW(m_hInstance, wszImage, nType, 0, 0, LR_DEFAULTCOLOR)
      END IF
   END IF
   ' // Sets the image and deletes the old one
   DIM h AS HANDLE
   IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(hCtl, BM_SETIMAGE, nType, CAST(LPARAM, hImage))))
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the icon or bitmap displayed in a button.
' The size of the button does not change; The image is clipped if it does nt fit in the button.
' The old image handle is released.
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetImgButtonX (BYVAL cId AS LONG, BYREF wszImage AS WSTRING) AS BOOLEAN
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cId)
   IF hCtl = NULL THEN RETURN FALSE
   '// Check the type if resource (icon or bitmap)
   DIM strType AS STRING = this.FindResourceType(wszImage)
   DIM nType AS LONG
   IF strType = "RT_ICON" OR strType = "RT_GROUP_ICON" THEN nType = IMAGE_ICON ELSE IF strType = "RT_BITMAP" THEN nType = IMAGE_BITMAP
   ' // Loads the image from resource
   DIM hImage AS HANDLE, wID AS WORD, dwID AS DWORD
   DIM rc AS RECT
   GetClientRect(hCtl, @rc)
   DIM AS LONG nWidth, nHeight
   nWidth = rc.right - rc.left
   nHeight = rc.bottom -rc.top
   IF LEFT(wszImage, 1) = "#" THEN
      wID = VAL(MID(wszImage, 2))
      dwID = MAKELONG(wID, 0)
      hImage = .LoadImageW(m_hInstance, CAST(LPCWSTR, CAST(ULONG_PTR, dwID)), nType, nWidth, nHeight, LR_DEFAULTCOLOR)
   ELSE
      ' // Loads the image from file
      IF UCASE(RIGHT(wszImage, 4)) = ".ICO" THEN
         hImage = .LoadImageW(NULL, wszImage, nType, nWidth, nHeight, LR_LOADFROMFILE)
      ELSE
         ' // Loads the icon from resource
         hImage = .LoadImageW(m_hInstance, wszImage, nType, nWidth, nHeight, LR_DEFAULTCOLOR)
      END IF
   END IF
   ' // Sets the image and deletes the old one
   DIM h AS HANDLE
   IF hImage THEN DeleteObject(CAST(HGDIOBJ, SendMessageW(hCtl, BM_SETIMAGE, nType, CAST(LPARAM, hImage))))
   RETURN TRUE
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                  *** DPI procedures ***
' ########################################################################################

' ========================================================================================
' Returns the DPI scaling ratios
' ========================================================================================
PRIVATE FUNCTION CDialog.rxRatio () AS SINGLE
   IF m_UsePixels THEN RETURN m_rx ELSE RETURN this.DluToPixRX
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDialog.ryRatio () AS SINGLE
   IF m_UsePixels THEN RETURN m_ry ELSE RETURN this.DluToPixRY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scales a horizontal coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION CDialog.ScaleX (BYVAL cx AS SINGLE) AS SINGLE
   IF m_UsePixels THEN RETURN cx * m_rx ELSE RETURN cx * this.DluToPixRX
END FUNCTION
' ========================================================================================
' ========================================================================================
' Scales a vertical coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION CDialog.ScaleY (BYVAL cy AS SINGLE) AS SINGLE
   IF m_UsePixels THEN RETURN cy * m_ry ELSE RETURN cy * this.DluToPixRY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unscales a horizontal coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION CDialog.UnScaleX (BYVAL cx AS SINGLE) AS SINGLE
   IF m_UsePixels THEN RETURN cx / m_rx ELSE RETURN cx / this.DluToPixRX
END FUNCTION
' ========================================================================================
' ========================================================================================
' Unscales a vertical coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION CDialog.UnScaleY (BYVAL cy AS SINGLE) AS SINGLE
   IF m_UsePixels THEN RETURN cy / m_ry ELSE RETURN cy / this.DluToPixRY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scales a RECT structure
' ========================================================================================
PRIVATE FUNCTION CDialog.ScaleRect (BYVAL rc AS RECT) AS RECT
   IF m_UsePixels THEN
      rc.left   *= m_rx
      rc.right  *= m_rx
      rc.top    *= m_ry
      rc.bottom *= m_ry
   ELSE
      MapDialogRect(m_hDlg, @rc)
   END IF
   RETURN rc
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Unscales a RECT structure.
' ========================================================================================
PRIVATE FUNCTION CDialog.UnScaleRect (BYVAL rc AS RECT) AS RECT
   IF m_UsePixels THEN
      rc.left   /= m_rx
      rc.right  /= m_rx
      rc.top    /= m_ry
      rc.bottom /= m_ry
   ELSE
      rc.left   /= this.DluToPixRX
      rc.right  /= this.DluToPixRX
      rc.top    /= this.DluToPixRY
      rc.bottom /= this.DluToPixRY
   END IF
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the size, position, and Z order of a child, pop-up, or top-level window.
' ========================================================================================
PRIVATE FUNCTION CDialog.SetWindowPosForDPI (BYVAL hwnd AS HWND, BYVAL hWndInsertAfter AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, _
   BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL uFlags AS UINT = SWP_NOZORDER) AS BOOLEAN
   RETURN ..SetWindowPos(hwnd, hWndInsertAfter, this.ScaleX(x), this.ScaleY(y), this.ScaleX(cx), this.ScaleY(cy), uFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the position and dimensions of the specified window.
' ========================================================================================
PRIVATE FUNCTION CDialog.MoveWindowForDPI (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS BOOLEAN) AS BOOLEAN
   RETURN ..MoveWindow(hwnd, this.ScaleX(x), this.ScaleY(y), this.ScaleX(nWidth), this.ScaleY(nHeight), bRepaint)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                               *** LAYOUT MANAGER ***
' ########################################################################################

' ========================================================================================
' Gets the anchor item
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CDialog.GetAnchorItem (BYVAL hwndCtl AS HWND) AS LONG
   FUNCTION = -1
   FOR i AS LONG = 0 TO UBOUND(m_rgProps)
      IF m_rgProps(i).hwndCtl = hwndCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Anchors the control
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlAnchor (BYVAL hwndCtl AS HWND, BYVAL nAnchorMode AS LONG) AS BOOLEAN
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
PRIVATE FUNCTION CDialog.ControlAnchor (BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DIM hwndCtl AS HWND = GetDlgItem(m_hDlg, cID)
   IF hwndCtl THEN RETURN this.ControlAnchor(hwndCtl, nAnchorMode)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlAnchor (BYVAL hParent AS HWND, BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
   DIM hwndCtl AS HWND = GetDlgItem(hParent, cID)
   IF hwndCtl THEN RETURN this.ControlAnchor(hwndCtl, nAnchorMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback function to enumerate child windows
' ========================================================================================
PRIVATE FUNCTION CDialog.LayoutEnumChildProc (BYVAL hwndChild AS HWND, BYVAL lParam AS LPARAM) AS LONG
   DIM rcParent AS RECT, rcChild AS RECT
   DIM nWidth AS LONG, nHeight AS LONG, x AS LONG, y AS LONG, xWidth AS LONG, yHeight AS LONG
   DIM pDlg AS CDialog PTR = CAST(CDialog PTR, lParam)
   DIM nItem AS LONG = pDlg->GetAnchorItem(hwndChild)
   IF nItem > -1 THEN
      IF pDlg->m_rgProps(nItem).anchor > AFX_ANCHOR_NONE THEN
         GetWindowRect(hwndChild, @rcChild)
         nWidth = rcChild.Right - rcChild.Left
         nHeight = rcChild.Bottom - rcChild.Top
         GetClientRect(GetParent(hwndChild), @rcParent)
         x = 0: y = 0: xWidth = 0: yHeight = 0
         SELECT CASE pDlg->m_rgProps(nItem).anchor
            CASE AFX_ANCHOR_NONE
               x = pDlg->m_rgProps(nItem).rc.Left
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = MAX(rcParent.Right - pDlg->m_rgProps(nItem).rc.Left - pDlg->m_rgProps(nItem).rc.Right, 0)
               yHeight = nHeight
            CASE AFX_ANCHOR_WIDTH
               x = pDlg->m_rgProps(nItem).rc.Left
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = MAX(rcParent.Right - pDlg->m_rgProps(nItem).rc.Left - pDlg->m_rgProps(nItem).rc.Right, 0)
               yHeight = nHeight
            CASE AFX_ANCHOR_RIGHT
               x = rcParent.Right - nWidth - pDlg->m_rgProps(nItem).rc.Right
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_HORZ
               x = (rcParent.Right \ 2) + pDlg->m_rgProps(nItem).centerX
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_HEIGHT
               x = pDlg->m_rgProps(nItem).rc.Left
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = MAX(rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Top - pDlg->m_rgProps(nItem).rc.Bottom, 0)
            CASE AFX_ANCHOR_HEIGHT_WIDTH
               x = pDlg->m_rgProps(nItem).rc.Left
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = MAX(rcParent.Right - pDlg->m_rgProps(nItem).rc.Left - pDlg->m_rgProps(nItem).rc.Right, 0)
               yHeight = MAX(rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Top - pDlg->m_rgProps(nItem).rc.Bottom, 0)
            CASE AFX_ANCHOR_HEIGHT_RIGHT
               x = rcParent.Right - nWidth - pDlg->m_rgProps(nItem).rc.Right
               y = pDlg->m_rgProps(nItem).rc.Top
               xWidth = nWidth
               yHeight = MAX(rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Top - pDlg->m_rgProps(nItem).rc.Bottom, 0)
            CASE AFX_ANCHOR_BOTTOM
               x = pDlg->m_rgProps(nItem).rc.Left
               y = rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_BOTTOM_WIDTH
               x = pDlg->m_rgProps(nItem).rc.Left
               y = rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = MAX(rcParent.Right - pDlg->m_rgProps(nItem).rc.Left - pDlg->m_rgProps(nItem).rc.Right, 0)
               yHeight = nHeight
            CASE AFX_ANCHOR_BOTTOM_RIGHT
               x = rcParent.Right - nWidth - pDlg->m_rgProps(nItem).rc.Right
               y = rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_HORZ_BOTTOM
               x = (rcParent.Right \ 2) + pDlg->m_rgProps(nItem).centerX
               y = rcParent.Bottom - pDlg->m_rgProps(nItem).rc.Bottom - nHeight
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_VERT
               x = pDlg->m_rgProps(nItem).rc.Left
               y = (rcParent.Bottom - nHeight) \ 2
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER_VERT_RIGHT
               x = rcParent.Right - nWidth - pDlg->m_rgProps(nItem).rc.Right
               y = (rcParent.Bottom - nHeight) \ 2
               xWidth = nWidth
               yHeight = nHeight
            CASE AFX_ANCHOR_CENTER
               x = (rcParent.Right \ 2) + pDlg->m_rgProps(nItem).centerX
               y = (rcParent.Bottom \ 2) + pDlg->m_rgProps(nItem).centerY
               xWidth = nWidth
               yHeight = nHeight
         END SELECT
         MoveWindow(hwndChild, x, y, xWidth, yHeight, CTRUE)

      END IF
   END IF

   RETURN CTRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Adjust the controls size and/or position
' ========================================================================================
PRIVATE FUNCTION CDialog.AdjustControls () AS BOOLEAN
   IF UBOUND(m_rgProps) = -1 THEN RETURN FALSE
   EnumChildWindows(m_hDlg, CAST(WNDENUMPROC, @LayoutEnumChildProc), CAST(LPARAM, @this))
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ########################################################################################
'                          *** DIALOG AND CONTROLS COLORS ***
' ########################################################################################

' ========================================================================================
' Gets the color item
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CDialog.GetColorItem (BYVAL hwnd AS ..HWND) AS LONG
   FUNCTION = -1
   FOR i AS LONG = 0 TO UBOUND(m_rgColors)
      IF m_rgColors(i).hwnd = hwnd THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the colors of the control
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetColor (BYVAL hwnd AS ..HWND, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   IF IsWindow(hwnd) = FALSE THEN RETURN FALSE
   ' // Check if the item already exists
   DIM nItem AS LONG = this.GetColorItem(hwnd)
   ' // If it does not exist, make room for it
   IF nItem = -1 THEN
      REDIM PRESERVE m_rgColors(UBOUND(m_rgColors) + 1) AS AFX_DLGCOLORS
      nItem = UBOUND(m_rgColors)
   END IF
   m_rgColors(nItem).hwnd = hwnd
   m_rgColors(nItem).foreColor = foreColor
   m_rgColors(nItem).backColor = backColor
   '// Redraw the dialog
   this.DialogRedraw
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the colors of the control
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetColor (BYVAL cID AS LONG, BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cID)
   FUNCTION = this.ControlSetColor(hCtl, foreColor, backColor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color of the dialog
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSetColor (BYVAL foreColor AS COLORREF, BYVAL backColor AS COLORREF) AS BOOLEAN
   FUNCTION = this.ControlSetColor(m_hDlg, foreColor, backColor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enable/disable dialog repainting during resizing
' ========================================================================================
PRIVATE SUB CDialog.DialogEnableRepaint (BYVAL fRepaint AS BOOLEAN)
   m_RepaintDisabled = NOT fRepaint
END SUB
' ========================================================================================
' ========================================================================================
' Checks if repainting is enabled during resizing
' ========================================================================================
PRIVATE FUNCTION CDialog.IsDialogRepaintDisabled () AS BOOLEAN
   RETURN m_RepaintDisabled
END FUNCTION
' ========================================================================================
' ========================================================================================
' Enable/disable dialog repainting during resizing
' ========================================================================================
PRIVATE SUB CDialog.DialogDisableRepaintOnResize (BYVAL fRepaint AS BOOLEAN)
   m_DisableRepaintOnResize = fRepaint
END SUB
' ========================================================================================
' ========================================================================================
' Check if repainting is enabled during resizing
' ========================================================================================
PRIVATE FUNCTION CDialog.IsDialogRepaintDisabledOnResize () AS BOOLEAN
   RETURN m_DisableRepaintOnResize
END FUNCTION
' ========================================================================================

' ########################################################################################

' ========================================================================================
' Gets the control user data item
' Return Value: The array index on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION CDialog.GetUserDataItem (BYVAL cID AS LONG) AS LONG
   FUNCTION = -1
   Dim hCtl AS HWND = GetDlgItem(m_hDlg, cID)
   FOR i AS LONG = 0 TO UBOUND(m_rgCtrlUserData)
      IF m_rgCtrlUserData(i).hCtl = hCtl THEN FUNCTION = i : EXIT FOR
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the control's user data
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlSetUser (BYVAL cID AS LONG, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
   IF index < 0 OR index > 9 THEN RETURN FALSE
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, CID)
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
' Sets the colors of the control
' ========================================================================================
PRIVATE FUNCTION CDialog.ControlGetUser (BYVAL cID AS LONG, BYVAL index AS LONG) AS LONG_PTR
   IF index < 0 OR index > 9 THEN RETURN FALSE
   DIM hCtl AS HWND = GetDlgItem(m_hDlg, cID)
   DIM nItem AS LONG = this.GetUserDataItem(cID)
   IF nItem > -1 THEN RETURN m_rgCtrlUserData(nItem).Values(index)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a floating context menu.
' ========================================================================================
PRIVATE FUNCTION CDialog.MenuContext (BYVAL hPopUpMenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL flags AS UINT) AS LONG
   flags = flags OR TPM_NONOTIFY OR TPM_RETURNCMD OR TPM_NOANIMATION
   RETURN TrackPopUpMenu(hPopUpMenu, flags, x, y, 0, m_hDlg, NULL)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                           *** KEYBOARD ACCELERATORS ***
' ########################################################################################

' =====================================================================================
' Gets the accelerator table handle
' =====================================================================================
PRIVATE PROPERTY CDialog.AccelHandle () AS ..HACCEL
   PROPERTY = m_hAccel
END PROPERTY
' =====================================================================================
' =====================================================================================
PRIVATE SUB CDialog.AccelAttach (BYVAL hAccel AS ..HACCEL)
   IF m_hAccel THEN .DestroyAcceleratorTable(m_hAccel)
   IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) > -1 THEN ERASE m_rgAccelEntries
   m_hAccel = hAccel
END SUB
' =====================================================================================
' =====================================================================================
' Adds an accelerator key to the table.
' =====================================================================================
PRIVATE SUB CDialog.AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYVAL wKey AS WORD, BYVAL cmd AS WORD)
   REDIM PRESERVE m_rgAccelEntries(UBOUND(m_rgAccelEntries) + 1) AS ACCEL
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).fvirt = fvirt
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).key = wKey
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).cmd = cmd
END SUB
' =====================================================================================
' =====================================================================================
PRIVATE SUB CDialog.AddAccelerator OVERLOAD (BYVAL fvirt AS UBYTE, BYREF wszKey AS WSTRING, BYVAL cmd AS WORD)
   REDIM PRESERVE m_rgAccelEntries(UBOUND(m_rgAccelEntries) + 1) AS ACCEL
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).fvirt = fvirt
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).key = ASC(wszKey)
   m_rgAccelEntries(UBOUND(m_rgAccelEntries)).cmd = cmd
END SUB
' =====================================================================================
' =====================================================================================
' Creates the accelerator table.
' =====================================================================================
PRIVATE FUNCTION CDialog.CreateAccelTable () AS ..HACCEL
   IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) = -1 THEN RETURN NULL
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   m_hAccel = .CreateAcceleratorTableW(CAST(LPACCEL, @m_rgAccelEntries(0)), UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) + 1)
   RETURN m_hAccel
END FUNCTION
' =====================================================================================
' =====================================================================================
' Destroys the accelerator table.
' =====================================================================================
PRIVATE SUB CDialog.DestroyAccelTable
   IF m_hAccel THEN ..DestroyAcceleratorTable(m_hAccel)
   IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) > -1 THEN ERASE m_rgAccelEntries
   m_hAccel = NULL
END SUB
' =====================================================================================

' ########################################################################################
'                              *** SCROLLABLE DIALOG ***
' ########################################################################################

' ========================================================================================
' Makes a dialog scrollable by shrinking its client area size
' ========================================================================================
PRIVATE FUNCTION CDialog.DialogSetViewPort (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   ' // Data for optional scrollable dialogs
   m_HorzUnits = 10
   m_VertUnits = 10
   GetClientRect(m_hDlg, @m_OrigClientRect)
   ' // Shrink the client size
   this.DialogSetClient(nWidth, nHeight)
   m_IsDialogScrollable = TRUE
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CDialog.IsDialogScrollable () AS BOOLEAN
   FUNCTION = m_IsDialogScrollable
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resets the dialog scrolling information
' ========================================================================================
PRIVATE SUB CDialog.DialogResetScrollBars
   ScrollWindow(m_hDlg, m_HScrollPos * m_HorzUnits, 0, NULL, NULL)
   ScrollWindow(m_hDlg, 0, m_VScrollPos * m_HorzUnits, NULL, NULL)
   m_HScrollPos = 0
   m_VScrollPos = 0
   SetScrollPos(m_hDlg, SB_HORZ, m_HScrollPos, CTRUE)
   SetScrollPos(m_hDlg, SB_VERT, m_VScrollPos, CTRUE)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the dialog scroll information (uses SCROLLINFO for thumb size)
' ========================================================================================
PRIVATE SUB CDialog.DialogSetupScrollBars
   DIM tempRect AS RECT
   ..GetClientRect(m_hDlg, @tempRect)
   m_nHorzInc = ((m_OrigClientRect.Right - m_OrigClientRect.Left) - (tempRect.Right  - tempRect.Left)) \ m_HorzUnits
   m_nVertInc = ((m_OrigClientRect.Bottom - m_OrigClientRect.Top) - (tempRect.Bottom - tempRect.Top)) \ m_VertUnits
   m_HScrollMax = MAX(0, m_nHorzInc)
   m_HScrollPos = MIN(m_HScrollPos, m_HScrollMax)
   m_VScrollMax = MAX(0, m_nVertInc)
   m_VScrollPos = MIN(m_VScrollPos, m_VScrollMax)
   DIM si AS SCROLLINFO
   si.cbSize = SIZEOF(si)
   si.fMask = SIF_RANGE OR SIF_PAGE OR SIF_POS
   ' Horizontal scroll bar
   si.nMin = 0
   si.nMax = m_OrigClientRect.Right - m_OrigClientRect.Left - 1
   si.nPage = tempRect.Right - tempRect.Left
   si.nPos = m_HScrollPos
   SetScrollInfo(m_hDlg, SB_HORZ, @si, TRUE)
   ' Vertical scroll bar
   si.nMin = 0
   si.nMax = m_OrigClientRect.Bottom - m_OrigClientRect.Top - 1
   si.nPage = tempRect.Bottom - tempRect.Top
   si.nPos = m_VScrollPos
   SetScrollInfo(m_hDlg, SB_VERT, @si, TRUE)
END SUB
' ========================================================================================

' ========================================================================================
' Handles vertical scrollbar messages
' WM_VSCROLL
' nScrollCode = (int) LOWORD(wParam); // scroll bar value
' nPos = (short int) HIWORD(wParam);  // scroll box position
' hwndScrollBar = (HWND) lParam;      // handle of scroll bar
' ========================================================================================
PRIVATE SUB CDialog.DialogOnVScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
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
      ScrollWindow(m_hDlg, 0, iMove, NULL, NULL)
      SetScrollPos(m_hDlg, SB_VERT, m_VScrollPos, CTRUE)
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
PRIVATE SUB CDialog.DialogOnHScroll (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
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
      ScrollWindow(m_hDlg, iMove, 0, NULL, NULL)
      SetScrollPos(m_hDlg, SB_HORZ, m_HScrollPos, CTRUE)
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
PRIVATE SUB CDialog.DialogOnSize (BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM)
   this.DialogResetScrollbars
   this.DialogSetupScrollbars
END SUB
' ========================================================================================


' ########################################################################################

' ========================================================================================
' Returns a pointer to the CDialog class given the handle of the window created with it
' or the handle of any of it's children.
' ========================================================================================
PRIVATE FUNCTION AfxCDialogPtr (BYVAL hwnd AS HWND) AS CDialog PTR
   IF hwnd = NULL THEN RETURN NULL
   DIM hRootOwner AS ..HWND = GetAncestor(hwnd, GA_ROOTOWNER)
   IF hRootOwner = NULL THEN RETURN NULL
   RETURN CAST(CDialog PTR, GetWindowLongPtrW(hRootOwner, DWLP_USER))
END FUNCTION
' ========================================================================================

' ########################################################################################

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
DECLARE FUNCTION DialogInputBoxWindowProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
' ========================================================================================
PRIVATE FUNCTION DialogInputBox (BYVAL hParent AS HWND = NULL, BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
BYREF wszCaption AS WSTRING = "", BYREF wszPrompt AS WSTRING = "", BYREF wszText AS WSTRING = "", _
BYVAL nLen AS LONG = 260, BYVAL bPassword AS BOOLEAN = FALSE) AS DWSTRING

   ' // Create the dialog
   DIM dwStyle AS DWORD = WS_VISIBLE OR WS_CAPTION OR WS_POPUPWINDOW OR WS_THICKFRAME
   DIM dwExStyle AS DWORD = WS_EX_WINDOWEDGE
   DIM pDlg AS CDialog = CDialog("Segoe UI", 9)
   DIM hInputBox AS HWND = pDlg.DialogNewPixels("CDialog_InputBox", hParent, wszCaption, x, y, 346, 115, dwStyle, dwExStyle)
   IF hInputBox = NULL THEN RETURN ""
   ' // Center the dialog
   IF x = 0 AND y = 0 THEN pDlg.DialogCenter(hParent)
   ' // Add a label control
   pDlg.ControlAdd("Label", -1, wszPrompt, 21, 10, 300, 19)
   ' // Add a TextBox control
   dwStyle = WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR ES_AUTOHSCROLL
   IF bPassWord THEN dwStyle = dwStyle OR ES_PASSWORD
   DIM hEdit AS HWND = pDlg.ControlAdd("Edit", 101, "", 21, 33, 300, 19, dwStyle)
   ' // Add the buttons
   DIM hOkButton AS HWND = pDlg.ControlAdd("Button", IDOK, "&Ok", 21, 72, 75, 25, BS_DEFPUSHBUTTON)
   DIM hCancelButton AS HWND = pDlg.ControlAdd("Button", IDCANCEL, "&Cancel", 246, 72, 75, 25)

   ' // Localized strings. In the resource file of user32.dll, the OK button has
   ' // IDS_OK (800) as the identifier and the Cancel button IDS_CANCEL (801).
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
   DIM dwsText AS DWSTRING = wszText
   IF LEN(dwsText) > nLen THEN dwsText = LEFT(dwsText, nLen)
   SendMessageW(hEdit, WM_SETTEXT, 0, cast(LPARAM, *dwsText))
   SendMessageW(hEdit, EM_SETSEL, 0, -1)

   ' // Pointer to the allocated string to return the result
   DIM wszOut AS WSTRING * 2049
   ' // Store it in the dialog user data
   pDlg.DialogSetUser(0, cast(LONG_PTR, @wszOut))

   ' // Anchor the controls
   pDlg.ControlAnchor(101, AFX_ANCHOR_WIDTH)
   pDlg.ControlAnchor(IDOK, AFX_ANCHOR_BOTTOM)
   pDlg.ControlAnchor(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Display the dialog as modal
   pDlg.DialogShowModal(@DialogInputBoxWindowProc)
   ' // Return the output string
   RETURN wszOut

END FUNCTION
' ========================================================================================

' ========================================================================================
' Input box callback function.
' ========================================================================================
PRIVATE FUNCTION DialogInputBoxWindowProc (BYVAL hDlg AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg
      CASE WM_INITDIALOG
         RETURN TRUE

      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW(hDlg, WM_CLOSE, 0, 0)
               END IF
            CASE IDOK
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  DIM nLen AS LONG = SendMessageW(GetDlgItem(hDlg, 101), WM_GETTEXTLENGTH, 0, 0)
                  IF nLen > 2048 THEN nLen = 2048
                  SCOPE
                     DIM pDlg AS CDialog PTR = cast(CDialog PTR, GetWindowLongPtrW(hDlg, DWLP_USER))
                     IF pDlg THEN
                        DIM pText AS LONG_PTR = pDlg->DialogGetUser(0)
                        IF pText THEN nLen = SendMessageW(GetDlgItem(hDlg, 101), WM_GETTEXT, nLen + 1, cast(..LPARAM, pText))
                     END IF
                  END SCOPE
                  SendMessageW(hDlg, WM_CLOSE, 0, 0)
               END IF
         END SELECT

      CASE WM_GETMINMAXINFO
         ' Set the pointer to the address of the MINMAXINFO structure
         DIM ptmmi AS MINMAXINFO PTR = cast(MINMAXINFO PTR, lParam)
         ' Set the minimum and maximum sizes that can be produced by dragging the borders of the window
         SCOPE
            DIM pDlg AS CDialog PTR = cast(CDialog PTR, GetWindowLongPtrW(hDlg, DWLP_USER))
            IF pDlg THEN
               ptmmi->ptMinTrackSize.x = 220 * pDlg->rxRatio
               ptmmi->ptMinTrackSize.y = 150 * pDlg->ryRatio
            END IF
         END SCOPE

      CASE WM_CLOSE
         ' // End the application
         DIM pDlg AS CDialog PTR = cast(CDialog PTR, GetWindowLongPtrW(hDlg, DWLP_USER))
         IF pDlg THEN pDlg->DialogEnd(1)

   END SELECT

   RETURN FALSE

END FUNCTION
' ========================================================================================

END NAMESPACE

' ########################################################################################
