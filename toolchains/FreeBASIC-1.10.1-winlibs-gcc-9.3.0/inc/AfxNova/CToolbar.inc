' ########################################################################################
' Platform: Microsoft Windows
' Filename: CToolbar.inc
' Purpose:  Windows common controls - ToolBar
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
' CToolbar class
' ########################################################################################

TYPE CToolbar

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION AddBitmap (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYVAL tabm AS TBADDBITMAP PTR) AS LONG
   DECLARE STATIC FUNCTION AddBitmap (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYREF abm AS TBADDBITMAP) AS LONG
   DECLARE STATIC FUNCTION AddButtons (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYVAL pButtons AS TBBUTTON PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION AddButtons (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYREF Buttons AS TBBUTTON) AS BOOLEAN
   DECLARE STATIC FUNCTION AddButton (BYVAL hToolbar AS HWND, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
                  BYVAL fsState AS UBYTE = 0, BYVAL fsStyle AS UBYTE = 0, BYVAL dwData AS DWORD_PTR = 0, BYVAL pwszText AS WSTRING PTR = NULL) AS BOOLEAN
   DECLARE STATIC FUNCTION AddSeparator (BYVAL hToolbar AS HWND, BYVAL nWidth AS LONG = 0) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL pButton AS TBBUTTON PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYREF Button AS TBBUTTON) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
                  BYVAL fsState AS UBYTE = 0, BYVAL fsStyle AS UBYTE = 0, BYVAL dwData AS DWORD_PTR = 0, BYVAL pwszText AS WSTRING PTR = NULL) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertSeparator (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL nWidth AS LONG = 0) AS BOOLEAN
   DECLARE STATIC FUNCTION AddString (BYVAL hToolbar AS HWND, BYVAL hInst AS HINSTANCE, BYVAL idString AS INT_PTR) AS LONG
   DECLARE STATIC SUB AutoSize (BYVAL hToolbar AS HWND)
   DECLARE STATIC FUNCTION ButtonCount (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC SUB ButtonStructSize (BYVAL hToolbar AS HWND, BYVAL cb AS LONG)
   DECLARE STATIC FUNCTION ChangeBitmap (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL iBitmap AS WORD) AS BOOLEAN
   DECLARE STATIC FUNCTION CheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fCheck AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION CheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION UncheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION CommandToIndex (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC SUB Customize (BYVAL hToolbar AS HWND)
   DECLARE STATIC FUNCTION DeleteButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION EnableButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION DisableButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetAnchorHighlight (BYVAL hToolbar AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBitmap (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetBitmapFlags (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYVAL ptbb AS TBBUTTON PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYREF tbb AS TBBUTTON) AS BOOLEAN
   DECLARE STATIC FUNCTION GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS TBBUTTON
   DECLARE STATIC FUNCTION GetButtonHeight (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetButtonWidth (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetButtonSize (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL ptbbi AS TBBUTTONINFOW PTR) AS LONG
   DECLARE STATIC FUNCTION GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF tbbi AS TBBUTTONINFOW) AS LONG
   DECLARE STATIC FUNCTION GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG) AS TBBUTTONINFOW
   DECLARE STATIC FUNCTION GetColorScheme (BYVAL hToolbar AS HWND, BYVAL pcs AS COLORSCHEME PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColorScheme (BYVAL hToolbar AS HWND, BYREF cs AS COLORSCHEME) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColorScheme (BYVAL hToolbar AS HWND) AS COLORSCHEME
   DECLARE STATIC FUNCTION GetImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetImageListCount (BYVAL hToolbar AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetDisabledImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetHotImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetExtendedStyle (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetHotItem (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetInsertMark (BYVAL hToolbar AS HWND, BYVAL ptbim AS TBINSERTMARK PTR) AS LONG
   DECLARE STATIC FUNCTION GetInsertMark (BYVAL hToolbar AS HWND, BYREF tbim AS TBINSERTMARK) AS LONG
   DECLARE STATIC FUNCTION GetInsertMark (BYVAL hToolbar AS HWND) AS TBINSERTMARK
   DECLARE STATIC FUNCTION GetInsertMarkColor (BYVAL hToolbar AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetMaxSize (BYVAL hToolbar AS HWND, BYVAL psize AS SIZE PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetMaxSize (BYVAL hToolbar AS HWND, BYREF sz AS SIZE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetMaxSize (BYVAL hToolbar AS HWND) AS SIZE
   DECLARE STATIC SUB GetMetrics (BYVAL hToolbar AS HWND, BYVAL ptbMetrics AS TBMETRICS PTR)
   DECLARE STATIC SUB GetMetrics (BYVAL hToolbar AS HWND, BYREF tbMet AS TBMETRICS)
   DECLARE STATIC FUNCTION GetMetrics (BYVAL hToolbar AS HWND) AS TBMETRICS
   DECLARE STATIC FUNCTION GetPadding (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetHorizontalPadding (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetVerticalPadding (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetRows (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetState (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS DWORD
   DECLARE STATIC FUNCTION GetString (BYVAL hToolbar AS HWND, BYVAL iString AS SHORT, BYVAL pBuffer AS WSTRING PTR, BYVAL cchMax AS SHORT) AS LONG
   DECLARE STATIC FUNCTION GetStyle (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetTextRows (BYVAL hToolbar AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetTooltips (BYVAL hToolbar AS HWND) AS HWND
   DECLARE STATIC FUNCTION HideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fShow AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION HideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION UnhideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION HitTest (BYVAL hToolbar AS HWND, BYVAL pptHitTest AS POINT PTR) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hToolbar AS HWND, BYREF ptHitTest AS POINT) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hToolbar AS HWND) AS POINT
   DECLARE STATIC FUNCTION Indeterminate (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fIndeterminate AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertMarkHitTest (BYVAL hToolbar AS HWND, BYVAL ppt AS POINT PTR, BYVAL ptbim AS TBINSERTMARK PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertMarkHitTest (BYVAL hToolbar AS HWND, BYREF pt AS POINT, BYVAL tbim AS TBINSERTMARK) AS BOOLEAN
   DECLARE STATIC FUNCTION IsButtonChecked (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION IsButtonEnabled (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION IsButtonHidden (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION IsButtonHighlighted (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION IsButtonIndeterminate (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION IsButtonPressed (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION LoadImages (BYVAL hToolbar AS HWND, BYVAL iBitmapID AS DWORD, BYVAL hinst AS HINSTANCE) AS LONG
   DECLARE STATIC FUNCTION LoadImages (BYVAL hToolbar AS HWND, BYVAL iBitmapID AS DWORD) AS LONG
   DECLARE STATIC FUNCTION MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD, BYVAL pIDBtn AS DWORD PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD, BYREF IDBtn AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION MarkButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fHighlight AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION HighlightButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION UnhighlightButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION MoveButton (BYVAL hToolbar AS HWND, BYVAL uOldPos AS DWORD, BYVAL uNewPos AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION PressButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fPress AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION PressButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION ReleaseButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION ReplaceBitmap (BYVAL hToolbar AS HWND, BYVAL ptbrb AS TBREPLACEBITMAP PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION ReplaceBitmap (BYVAL hToolbar AS HWND, BYREF tbrb AS TBREPLACEBITMAP) AS BOOLEAN
   DECLARE STATIC SUB SaveRestore (BYVAL hToolbar AS HWND, BYVAL fSave AS LONG, BYVAL ptbsp AS TBSAVEPARAMSW PTR)
   DECLARE STATIC SUB SaveRestore (BYVAL hToolbar AS HWND, BYVAL fSave AS LONG, BYREF tbsp AS TBSAVEPARAMSW)
   DECLARE STATIC FUNCTION SetAnchorHighlight (BYVAL hToolbar AS HWND, BYVAL fAnchor AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBitmapSize (BYVAL hToolbar AS HWND, BYVAL dxBitmap AS SHORT, BYVAL dyBitmap AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION SetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL ptbbi AS TBBUTTONINFOW PTR) AS LONG
   DECLARE STATIC FUNCTION SetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF tbbi AS TBBUTTONINFOW) AS LONG
   DECLARE STATIC FUNCTION SetButtonSize (BYVAL hToolbar AS HWND, BYVAL dxButton AS SHORT, BYVAL dyButton AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION SetButtonWidth (BYVAL hToolbar AS HWND, BYVAL cxMin AS SHORT, BYVAL cxMax AS SHORT) AS BOOLEAN
   DECLARE STATIC FUNCTION SetCmdId (BYVAL hToolbar AS HWND, BYVAL index AS SHORT, BYVAL cmdid AS SHORT) AS BOOLEAN
   DECLARE STATIC SUB SetColorScheme (BYVAL hToolbar AS HWND, BYVAL pcs AS COLORSCHEME PTR)
   DECLARE STATIC SUB SetColorScheme (BYVAL hToolbar AS HWND, BYREF cs AS COLORSCHEME)
   DECLARE STATIC FUNCTION SetImageList (BYVAL hToolbar AS HWND, BYVAL himlNew AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetHotImageList (BYVAL hToolbar AS HWND, BYVAL himlNewHot AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetDisabledImageList (BYVAL hToolbar AS HWND, BYVAL himlNewDisabled AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetDrawTextFlags (BYVAL hToolbar AS HWND, BYVAL dwMask AS DWORD, BYVAL dwDTFlags AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetExtendedStyle (BYVAL hToolbar AS HWND, BYVAL dwExStyle AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetHotItem (BYVAL hToolbar AS HWND, BYVAL iHot AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetIndent (BYVAL hToolbar AS HWND, BYVAL iIndent AS LONG) AS BOOLEAN
   DECLARE STATIC SUB SetInsertMark (BYVAL hToolbar AS HWND, BYVAL ptbim AS TBINSERTMARK PTR)
   DECLARE STATIC SUB SetInsertMark (BYVAL hToolbar AS HWND, BYREF tbim AS TBINSERTMARK)
   DECLARE STATIC FUNCTION SetInsertMarkColor (BYVAL hToolbar AS HWND, BYVAL clrInsertMark AS COLORREF) AS COLORREF
   DECLARE STATIC SUB SetListGap (BYVAL hToolbar AS HWND, BYVAL gap AS DWORD)
   DECLARE STATIC FUNCTION SetMaxTextRows (BYVAL hToolbar AS HWND, BYVAL iMaxRows AS LONG) AS BOOLEAN
   DECLARE STATIC SUB SetMetrics (BYVAL hToolbar AS HWND, BYVAL ptbMetrics AS TBMETRICS PTR)
   DECLARE STATIC SUB SetMetrics (BYVAL hToolbar AS HWND, BYREF tbMet AS TBMETRICS)
   DECLARE STATIC FUNCTION SetPadding (BYVAL hToolbar AS HWND, BYVAL cx AS SHORT, BYVAL cy AS SHORT) AS DWORD
   DECLARE STATIC FUNCTION SetParent (BYVAL hToolbar AS HWND, BYVAL hwndParent AS HWND) AS HWND
   DECLARE STATIC FUNCTION SetPressedImageList (BYVAL hToolbar AS HWND, BYVAL iImageID AS DWORD, BYVAL himlNew AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC SUB SetRows (BYVAL hToolbar AS HWND, BYVAL cRows AS WORD, BYVAL fLarger AS BOOLEAN, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB SetRows (BYVAL hToolbar AS HWND, BYVAL cRows AS WORD, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION SetState (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fState AS SHORT) AS BOOLEAN
   DECLARE STATIC SUB SetStyle (BYVAL hToolbar AS HWND, BYVAL dwStyle AS DWORD)
   DECLARE STATIC SUB SetToolTips (BYVAL hToolbar AS HWND, BYVAL hwndToolTip AS HWND)
   DECLARE STATIC SUB SetWindowTheme (BYVAL hToolbar AS HWND, BYVAL pwszTheme AS WSTRING PTR)
   DECLARE STATIC SUB MakeOpaque (BYVAL hToolbar AS HWND)
   DECLARE STATIC FUNCTION GetObject (BYVAL hToolbar AS HWND) AS IDropTarget PTR
   DECLARE STATIC FUNCTION GetButtonText (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL pBuffer AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION GetButtonText (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS DWSTRING
   DECLARE STATIC FUNCTION GetButtonTextLength (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetDarkMode(BYVAL hToolbar AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode(BYVAL hToolbar AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CToolbar
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CToolbar
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Adds one or more images to the list of button images available for a toolbar.
' Returns the index of the first new image if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddBitmap (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYVAL ptabm AS TBADDBITMAP PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_ADDBITMAP, cast(WPARAM, nButtons), CAST(LPARAM, ptabm))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddBitmap (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYREF tabm AS TBADDBITMAP) AS LONG
   RETURN SendMessageW(hToolbar, TB_ADDBITMAP, cast(WPARAM, nButtons), CAST(LPARAM, @tabm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds one or more buttons to a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddButtons (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYVAL pButtons AS TBBUTTON PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_ADDBUTTONSW, cast(WPARAM, nButtons), CAST(LPARAM, pButtons))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddButtons (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYREF Buttons AS TBBUTTON) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_ADDBUTTONSW, cast(WPARAM, nButtons), CAST(LPARAM, @Buttons))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds a button to a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddButton (BYVAL hToolbar AS HWND, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
BYVAL fsState AS UBYTE = 0, BYVAL fsStyle AS UBYTE = 0, BYVAL dwData AS DWORD_PTR = 0, BYVAL pwszText AS WSTRING PTR = NULL) AS BOOLEAN
   IF fsState = 0 THEN fsState = TBSTATE_ENABLED
   DIM idxString AS INT_PTR
   IF pwszText <> NULL THEN idxString = IIF(LEN(*pwszText) = 0, -1, CAST(INT_PTR, pwszText))
#ifdef __FB_64BIT__
   DIM tbb AS TBBUTTON = (idxBitmap, idCommand, fsState, fsStyle, {0, 0, 0, 0, 0, 0}, dwData, idxString)
#else
   DIM tbb AS TBBUTTON = (idxBitmap, idCommand, fsState, fsStyle, {0, 0}, dwData, idxString)
#endif
   RETURN SendMessageW(hToolbar, TB_ADDBUTTONSW, 1, CAST(LPARAM, @tbb))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a separator to a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddSeparator (BYVAL hToolbar AS HWND, BYVAL nWidth AS LONG = 0) AS BOOLEAN
#ifdef __FB_64BIT__
   DIM tbb AS TBBUTTON = (nWidth, 0, TBSTATE_ENABLED, TBSTYLE_SEP, {0, 0, 0, 0, 0, 0}, 0, -1)
#else
   DIM tbb AS TBBUTTON = (nWidth, 0, TBSTATE_ENABLED, TBSTYLE_SEP, {0, 0}, 0, -1)
#endif
   RETURN SendMessageW(hToolbar, TB_ADDBUTTONSW, 1, CAST(LPARAM, @tbb))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL pButton AS TBBUTTON PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_INSERTBUTTONW, cast(WPARAM, idxButton), CAST(LPARAM, pButton))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYREF Button AS TBBUTTON) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_INSERTBUTTONW, cast(WPARAM, idxButton), CAST(LPARAM, @Button))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
BYVAL fsState AS UBYTE = 0, BYVAL fsStyle AS UBYTE = 0, BYVAL dwData AS DWORD_PTR = 0, BYVAL pwszText AS WSTRING PTR = NULL) AS BOOLEAN
   IF fsState = 0 THEN fsState = TBSTATE_ENABLED
   DIM idxString AS INT_PTR
   IF pwszText <> NULL THEN idxString = IIF(LEN(*pwszText) = 0, -1, CAST(INT_PTR, pwszText))
#ifdef __FB_64BIT__
   DIM tbb AS TBBUTTON = (idxBitmap, idCommand, fsState, fsStyle, {0, 0, 0, 0, 0, 0}, dwData, idxString)
#else
   DIM tbb AS TBBUTTON = (idxBitmap, idCommand, fsState, fsStyle, {0, 0}, dwData, idxString)
#endif
   RETURN SendMessageW(hToolbar, TB_INSERTBUTTONW, idxButton, CAST(LPARAM, @tbb))
END FUNCTION
' ========================================================================================
'
' ========================================================================================
' Inserts a separator in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.InsertSeparator (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL nWidth AS LONG = 0) AS BOOLEAN
#ifdef __FB_64BIT__
   DIM tbb AS TBBUTTON = (nWidth, 0, TBSTATE_ENABLED, TBSTYLE_SEP, {0, 0, 0, 0, 0, 0}, 0, -1)
#else
   DIM tbb AS TBBUTTON = (nWidth, 0, TBSTATE_ENABLED, TBSTYLE_SEP, {0, 0}, 0, -1)
#endif
   RETURN SendMessageW(hToolbar, TB_INSERTBUTTONW, idxButton, CAST(LPARAM, @tbb))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a new string to the toolbar's string pool.
' Returns the index of the first new string if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.AddString (BYVAL hToolbar AS HWND, BYVAL hInst AS HINSTANCE, BYVAL idString AS INT_PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_ADDSTRINGW, CAST(WPARAM, hInst), IIF(hInst = NULL, idString, MAKELONG(idString, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Causes a toolbar to be resized.
' ========================================================================================
PRIVATE SUB CToolbar.AutoSize (BYVAL hToolbar AS HWND)
   SendMessageW(hToolbar, TB_AUTOSIZE, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Retrieves a count of the buttons currently in the toolbar.
' ========================================================================================
PRIVATE FUNCTION CToolbar.ButtonCount (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_BUTTONCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the size of the TBBUTTON structure.
' ========================================================================================
PRIVATE SUB CToolbar.ButtonStructSize (BYVAL hToolbar AS HWND, BYVAL cb AS LONG)
   SendMessageW(hToolbar, TB_BUTTONSTRUCTSIZE, cb, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Changes the bitmap for a button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.ChangeBitmap (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL iBitmap AS WORD) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_CHANGEBITMAP, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(iBitmap, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Checks or unchecks a given button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.CheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fCheck AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_CHECKBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(fCheck, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.CheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_CHECKBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(CTRUE, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.UncheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_CHECKBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(FALSE, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the zero-based index for the button associated with the specified command
' identifier. Returns the zero-based index for the button or -1 if the specified command
' identifier is invalid.
' ========================================================================================
PRIVATE FUNCTION CToolbar.CommandToIndex (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_COMMANDTOINDEX, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the Customize Toolbar dialog box.
' ========================================================================================
PRIVATE SUB CToolbar.Customize (BYVAL hToolbar AS HWND)
   SendMessageW(hToolbar, TB_CUSTOMIZE, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Deletes a button from the toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.DeleteButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_DELETEBUTTON, cast(WPARAM, nButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Enables the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.EnableButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_ENABLEBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(CTRUE, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Disables the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.DisableButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_ENABLEBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(FALSE, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the anchor highlight setting for a toolbar.
' Returns a Boolean value that indicates if anchor highlighting is set. If this value is
' nonzero, anchor highlighting is enabled. If this value is zero, it is disabled.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetAnchorHighlight (BYVAL hToolbar AS HWND) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETANCHORHIGHLIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the index of the bitmap associated with a button in a toolbar.
' Returns the index of the bitmap if successful, or zero otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetBitmap (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETBITMAP, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the flags that describe the type of bitmap to be used.
' Returns a DWORD value that describes the type of bitmap that should be used. If this
' return value has the TBBF_LARGE flag set, applications should use large bitmaps (24 x 24);
' otherwise, applications should use small bitmaps (16 x 16). All other bits are reserved.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetBitmapFlags (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETBITMAPFLAGS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYVAL ptbb AS TBBUTTON PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETBUTTON, CAST(WPARAM, nButton), CAST(LPARAM, ptbb))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYREF tbb AS TBBUTTON) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETBUTTON, CAST(WPARAM, nButton), CAST(LPARAM, @tbb))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS TBBUTTON
   DIM tbb AS TBBUTTON
   SendMessageW(hToolbar, TB_GETBUTTON, CAST(WPARAM, nButton), CAST(LPARAM, @tbb))
   RETURN tbb
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the current width and height of toolbar buttons, in pixels.
' Returns a DWORD value that contains the width and height values in the low word and high
' word, respectively.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonSize (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETBUTTONSIZE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the current height of toolbar buttons, in pixels.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonHeight (BYVAL hToolbar AS HWND) AS DWORD
   RETURN HIWORD(SendMessageW(hToolbar, TB_GETBUTTONSIZE, 0, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the current width of toolbar buttons, in pixels.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonWidth (BYVAL hToolbar AS HWND) AS DWORD
   RETURN LOWORD(SendMessageW(hToolbar, TB_GETBUTTONSIZE, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves extended information for a button in a toolbar.
' Returns the zero-based index of the button, or -1 if an error occurs.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL ptbbi AS TBBUTTONINFOW PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETBUTTONINFOW, cast(WPARAM, iID), cast(LPARAM, ptbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF tbbi AS TBBUTTONINFOW) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETBUTTONINFOW, cast(WPARAM, iID), cast(LPARAM, @tbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG) AS TBBUTTONINFOW
   DIM tbbi AS TBBUTTONINFOW
   SendMessageW(hToolbar, TB_GETBUTTONINFOW, cast(WPARAM, iID), cast(LPARAM, @tbbi))
   RETURN tbbi
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color scheme information from the toolbar control.
' - lpcs: Pointer to a COLORSCHEME structure that will receive the color scheme information.
'   You must set the cbSize member of this structure to sizeof(COLORSCHEME) before sending
'   this message.
' Returns nonzero if successful, or zero otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetColorScheme (BYVAL hToolbar AS HWND, BYVAL pcs AS COLORSCHEME PTR) AS BOOLEAN
   IF pcs = NULL THEN RETURN FALSE
   pcs->dwSize = SIZEOF(COLORSCHEME)
   RETURN SendMessageW(hToolbar, TB_GETCOLORSCHEME, 0, CAST(LPARAM, pcs))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetColorScheme (BYVAL hToolbar AS HWND, BYREF cs AS COLORSCHEME) AS BOOLEAN
   cs.dwSize = SIZEOF(COLORSCHEME)
   RETURN SendMessageW(hToolbar, TB_GETCOLORSCHEME, 0, CAST(LPARAM, @cs))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetColorScheme (BYVAL hToolbar AS HWND) AS COLORSCHEME
   DIM cs AS COLORSCHEME
   cs.dwSize = SIZEOF(COLORSCHEME)
   SendMessageW(hToolbar, TB_GETCOLORSCHEME, 0, CAST(LPARAM, @cs))
   RETURN cs
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the image list that a toolbar control uses to display buttons in their default
' state. A toolbar control uses this image list to display buttons when they are not hot
' or disabled.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_GETIMAGELIST, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of image lists associated with the toolbar.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetImageListCount (BYVAL hToolbar AS HWND) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETIMAGELISTCOUNT , 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the image list that a toolbar control uses to display inactive buttons.
' A toolbar control uses this image list to display buttons when they are disabled.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetDisabledImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_GETDISABLEDIMAGELIST, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the image list that a toolbar control uses to display hot buttons.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetHotImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_GETHOTIMAGELIST, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended styles for a toolbar control.
' Returns a DWORD that represents the styles currently in use for the toolbar control.
' This value can be a combination of extended styles.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetExtendedStyle (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the index of the hot item in a toolbar.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetHotItem (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETHOTITEM, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current insertion mark for the toolbar.
' Always returns TRUE.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetInsertMark (BYVAL hToolbar AS HWND, BYVAL ptbim AS TBINSERTMARK PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETINSERTMARK, 0, CAST(LPARAM, ptbim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetInsertMark (BYVAL hToolbar AS HWND, BYREF tbim AS TBINSERTMARK) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETINSERTMARK, 0, CAST(LPARAM, @tbim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetInsertMark (BYVAL hToolbar AS HWND) AS TBINSERTMARK
   DIM tbim AS TBINSERTMARK
   SendMessageW(hToolbar, TB_GETINSERTMARK, 0, CAST(LPARAM, @tbim))
   RETURN tbim
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color used to draw the insertion mark for the toolbar.
' Returns a COLORREF value that contains the current insertion mark color.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetInsertMarkColor (BYVAL hToolbar AS HWND) AS COLORREF
   RETURN SendMessageW(hToolbar, TB_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle of a button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETITEMRECT, cast(WPARAM, nButton), CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETITEMRECT, cast(WPARAM, nButton), CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS RECT
   DIM rc AS RECT
   SendMessageW(hToolbar, TB_GETITEMRECT, cast(WPARAM, nButton), CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================
 
' ========================================================================================
' Retrieves the total size of all of the visible buttons and separators in the toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetMaxSize (BYVAL hToolbar AS HWND, BYVAL psize AS SIZE PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETMAXSIZE, 0, CAST(LPARAM, psize))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetMaxSize (BYVAL hToolbar AS HWND, BYREF sz AS SIZE) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETMAXSIZE, 0, CAST(LPARAM, @sz))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetMaxSize (BYVAL hToolbar AS HWND) AS SIZE
   DIM sz AS SIZE
   SendMessageW(hToolbar, TB_GETMAXSIZE, 0, CAST(LPARAM, @sz))
   RETURN sz
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the metrics of a toolbar control.
' Note: To use this API, you must provide a manifest specifying Comclt32.dll version 6.0.
' ========================================================================================
PRIVATE SUB CToolbar.GetMetrics (BYVAL hToolbar AS HWND, BYVAL ptbMetrics AS TBMETRICS PTR)
   IF ptbMetrics = NULL THEN EXIT SUB
   ptbMetrics->cbSize = SIZEOF(TBMETRICS)
   SendMessageW(hToolbar, TB_GETMETRICS, 0, CAST(LPARAM, ptbMetrics))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CToolbar.GetMetrics (BYVAL hToolbar AS HWND, BYREF tbMet AS TBMETRICS)
   IF VARPTR(tbMet) = NULL THEN EXIT SUB
   tbMet.cbSize = SIZEOF(TBMETRICS)
   SendMessageW(hToolbar, TB_GETMETRICS, 0, CAST(LPARAM, @tbMet))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetMetrics (BYVAL hToolbar AS HWND) AS TBMETRICS
   DIM tbMet AS TBMETRICS
   tbMet.cbSize = SIZEOF(TBMETRICS)
   SendMessageW(hToolbar, TB_GETMETRICS, 0, CAST(LPARAM, @tbMet))
   RETURN tbMet
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the padding for a toolbar control.
' Returns a DWORD value that contains the horizontal padding in the low word and the
' vertical padding in the high word, in pixels.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetPadding (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETPADDING, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the horizontal padding for a toolbar control.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetHorizontalPadding (BYVAL hToolbar AS HWND) AS DWORD
   RETURN LOWORD(SendMessageW(hToolbar, TB_GETPADDING, 0, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the vertical padding for a toolbar control.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetVerticalPadding (BYVAL hToolbar AS HWND) AS DWORD
   RETURN HIWORD(SendMessageW(hToolbar, TB_GETPADDING, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle for a specified toolbar button.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETRECT, cast(WPARAM, iID), CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_GETRECT, cast(WPARAM, iID), CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG) AS RECT
   DIM rc AS RECT
   SendMessageW(hToolbar, TB_GETRECT, cast(WPARAM, iID), CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of rows of buttons in a toolbar with the TBSTYLE_WRAPABLE style.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetRows (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETROWS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves information about the state of the specified button in a toolbar, such as
' whether it is enabled, pressed, or checked.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetState (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETSTATE, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a string from a toolbar's string pool.
' - iString: Index of the string
' - pBuffer: Pointer to a buffer used to return the string.
' - cchMax: Length of the buffer in bytes.
' Returns the string length if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetString (BYVAL hToolbar AS HWND, BYVAL iString AS SHORT, BYVAL pBuffer AS WSTRING PTR, BYVAL cchMax AS SHORT) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETSTRINGW, MAKELONG(cchMax, iString), CAST(LPARAM, pbuffer))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the styles currently in use for a toolbar control.
' Returns a DWORD value that is a combination of toolbar control styles.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetStyle (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the number of rows of buttons in a toolbar with the TBSTYLE_WRAPABLE style.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetTextRows (BYVAL hToolbar AS HWND) AS DWORD
   RETURN SendMessageW(hToolbar, TB_GETTEXTROWS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the handle to the ToolTip control, if any, associated with the toolbar.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetTooltips (BYVAL hToolbar AS HWND) AS HWND
   RETURN cast(HWND, SendMessageW(hToolbar, TB_GETTOOLTIPS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Hides or shows the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.HideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fShow AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_HIDEBUTTON, idButton, MAKELONG(fShow, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.HideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_HIDEBUTTON, idButton, MAKELONG(CTRUE, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.UnhideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_HIDEBUTTON, idButton, MAKELONG(FALSE, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines where a point lies in a toolbar control.
' Returns an integer value. If the return value is zero or a positive value, it is the
' zero-based index of the nonseparator item in which the point lies. If the return value
' is negative, the point does not lie within a button. The absolute value of the return
' value is the index of a separator item or the nearest nonseparator item.
' ========================================================================================
PRIVATE FUNCTION CToolbar.HitTest (BYVAL hToolbar AS HWND, BYVAL pptHitTest AS POINT PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_HITTEST, 0, CAST(LPARAM, pptHitTest))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.HitTest (BYVAL hToolbar AS HWND, BYREF ptHitTest AS POINT) AS LONG
   RETURN SendMessageW(hToolbar, TB_HITTEST, 0, CAST(LPARAM, @ptHitTest))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.HitTest (BYVAL hToolbar AS HWND) AS POINT
   DIM ptHitTest AS POINT
   SendMessageW(hToolbar, TB_HITTEST, 0, CAST(LPARAM, @ptHitTest))
   RETURN ptHitTest
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets or clears the indeterminate state of the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.Indeterminate (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fIndeterminate AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_INDETERMINATE, cast(WPARAM, idButton), MAKELONG(fIndeterminate, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the insertion mark information for a point in a toolbar.
' ========================================================================================
PRIVATE FUNCTION CToolbar.InsertMarkHitTest (BYVAL hToolbar AS HWND, BYVAL ppt AS POINT PTR, BYVAL ptbim AS TBINSERTMARK PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_INSERTMARKHITTEST, CAST(WPARAM, ppt), CAST(LPARAM, ptbim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.InsertMarkHitTest (BYVAL hToolbar AS HWND, BYREF pt AS POINT, BYVAL tbim AS TBINSERTMARK) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_INSERTMARKHITTEST, CAST(WPARAM, @pt), CAST(LPARAM, @tbim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines whether the specified button in a toolbar is checked.
' Returns nonzero if the button is checked, or zero otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.IsButtonChecked (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_ISBUTTONCHECKED, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines whether the specified button in a toolbar is enabled.
' Returns TRUE if the button is enabled, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.IsButtonEnabled (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_ISBUTTONENABLED, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines whether the specified button in a toolbar is hidden.
' Returns TRUE if the button is hidden, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.IsButtonHidden (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_ISBUTTONHIDDEN, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Checks the highlight state of a toolbar button.
' Returns TRUE if the button is highlighted, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.IsButtonHighlighted (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_ISBUTTONHIGHLIGHTED, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is indeterminate.
' Returns TRUE if the button is in a indetermides state, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.IsButtonIndeterminate (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_ISBUTTONINDETERMINATE, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is pressed.
' Returns TRUE if the button is pressed, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.IsButtonPressed (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_ISBUTTONPRESSED, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads system-defined button images into a toolbar control's image list.
' The count of images in the image list. Returns zero if the toolbar has no image list or
' if the existing image list is empty.
' ========================================================================================
PRIVATE FUNCTION CToolbar.LoadImages (BYVAL hToolbar AS HWND, BYVAL iBitmapID AS DWORD, BYVAL hinst AS HINSTANCE) AS LONG
   RETURN SendMessageW(hToolbar, TB_LOADIMAGES, cast(WPARAM, iBitmapID), CAST(LPARAM, hinst))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.LoadImages (BYVAL hToolbar AS HWND, BYVAL iBitmapID AS DWORD) AS LONG
   RETURN SendMessageW(hToolbar, TB_LOADIMAGES, cast(WPARAM, iBitmapID), CAST(LPARAM, HINST_COMMCTRL))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the ID of the button that corresponds to the specified accelerator character.
' Returns TRUE if one of the buttons has wParam as its accelerator character, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD, BYVAL pIDBtn AS DWORD PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_MAPACCELERATOR, cast(WPARAM, chAccel), CAST(LPARAM, pIDBtn))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD, BYREF IDBtn AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_MAPACCELERATOR, cast(WPARAM, chAccel), CAST(LPARAM, @IDBtn))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD) AS DWORD
   DIM IDBtn AS DWORD
   SendMessageW(hToolbar, TB_MAPACCELERATOR, cast(WPARAM, chAccel), CAST(LPARAM, @IDBtn))
   RETURN IDBtn
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the highlight state of a given button in a toolbar control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.MarkButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fHighlight AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_MARKBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(fHighlight, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.HighlightButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_MARKBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(CTRUE, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.UnhighlightButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_MARKBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(FALSE, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Moves a button from one index to another.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.MoveButton (BYVAL hToolbar AS HWND, BYVAL uOldPos AS DWORD, BYVAL uNewPos AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_MOVEBUTTON, cast(WPARAM, uOldPos), cast(LPARAM, uNewPos))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Presses or releases the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' Returns -1 if idButton does not exist.
' ========================================================================================
PRIVATE FUNCTION CToolbar.PressButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fPress AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_PRESSBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(fPress, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.PressButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_PRESSBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(CTRUE, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.ReleaseButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_PRESSBUTTON, cast(WPARAM, idButton), cast(LPARAM, MAKELONG(FALSE, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces an existing bitmap with a new bitmap.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.ReplaceBitmap (BYVAL hToolbar AS HWND, BYVAL ptbrb AS TBREPLACEBITMAP PTR) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_REPLACEBITMAP, 0, CAST(LPARAM, ptbrb))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.ReplaceBitmap (BYVAL hToolbar AS HWND, BYREF tbrb AS TBREPLACEBITMAP) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_REPLACEBITMAP, 0, CAST(LPARAM, @tbrb))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Send this message to initiate saving or restoring a toolbar state.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
PRIVATE SUB CToolbar.SaveRestore (BYVAL hToolbar AS HWND, BYVAL fSave AS LONG, BYVAL ptbsp AS TBSAVEPARAMSW PTR)
   SendMessageW(hToolbar, TB_SAVERESTOREW, cast(WPARAM, fSave), CAST(LPARAM, ptbsp))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CToolbar.SaveRestore (BYVAL hToolbar AS HWND, BYVAL fSave AS LONG, BYREF tbsp AS TBSAVEPARAMSW)
   SendMessageW(hToolbar, TB_SAVERESTOREW, cast(WPARAM, fSave), CAST(LPARAM, @tbsp))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the anchor highlight setting for a toolbar.
' Returns the previous anchor highlight setting. If this value is nonzero, anchor highlighting
' was enabled. If this value is zero, anchor highlighting was disabled.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetAnchorHighlight (BYVAL hToolbar AS HWND, BYVAL fAnchor AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETANCHORHIGHLIGHT, fAnchor, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size of the bitmapped images to be added to a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetBitmapSize (BYVAL hToolbar AS HWND, BYVAL dxBitmap AS SHORT, BYVAL dyBitmap AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETBITMAPSIZE, 0, MAKELONG(dxBitmap, dyBitmap))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the information for an existing button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' Returns -1 if iID does mt exist.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL ptbbi AS TBBUTTONINFOW PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_SETBUTTONINFOW, cast(WPARAM, iID), CAST(LPARAM, ptbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF tbbi AS TBBUTTONINFOW) AS LONG
   RETURN SendMessageW(hToolbar, TB_SETBUTTONINFOW, cast(WPARAM, iID), CAST(LPARAM, @tbbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size of the buttons to be added to a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetButtonSize (BYVAL hToolbar AS HWND, BYVAL dxButton AS SHORT, BYVAL dyButton AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETBUTTONSIZE, 0, cast(LPARAM, MAKELONG(dxButton, dyButton)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum button widths in the toolbar control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetButtonWidth (BYVAL hToolbar AS HWND, BYVAL cxMin AS SHORT, BYVAL cxMax AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETBUTTONWIDTH, 0, cast(LPARAM, MAKELONG(cxMin, cxMax)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the command identifier of a toolbar button.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetCmdId (BYVAL hToolbar AS HWND, BYVAL index AS SHORT, BYVAL cmdid AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETCMDID, cast(WPARAM, index), cast(LPARAM, cmdid))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color scheme information for the toolbar control.
' ========================================================================================
PRIVATE SUB CToolbar.SetColorScheme (BYVAL hToolbar AS HWND, BYVAL pcs AS COLORSCHEME PTR)
   SendMessageW(hToolbar, TB_SETCOLORSCHEME, 0, CAST(LPARAM, pcs))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CToolbar.SetColorScheme (BYVAL hToolbar AS HWND, BYREF cs AS COLORSCHEME)
   SendMessageW(hToolbar, TB_SETCOLORSCHEME, 0, CAST(LPARAM, @cs))
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the image list that the toolbar will use to display buttons that are in their
' default state. Returns the handle to the image list previously used to display buttons
' in their default state, or NULL if no image list was previously set.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetImageList (BYVAL hToolbar AS HWND, BYVAL himlNew AS HIMAGELIST) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_SETIMAGELIST, 0, CAST(LPARAM, himlNew)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the image list that the toolbar control will use to display hot buttons.
' Returns the handle to the image list previously used to display hot buttons, or NULL if
' no image list was previously set.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetHotImageList (BYVAL hToolbar AS HWND, BYVAL himlNewHot AS HIMAGELIST) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_SETHOTIMAGELIST, 0, CAST(LPARAM, himlNewHot)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the image list that the toolbar control will use to display disabled buttons.
' Returns the handle to the image list previously used to display disabled buttons, or NULL
' if no image list was previously set.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetDisabledImageList (BYVAL hToolbar AS HWND, BYVAL himlNewDisabled AS HIMAGELIST) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_SETDISABLEDIMAGELIST, 0, CAST(LPARAM, himlNewDisabled)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the image list that the toolbar uses to display buttons that are in a pressed state.
' Returns the handle to the image list previously used to display buttons in their pressed
' state, or NULL if no such image list was previously set.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetPressedImageList (BYVAL hToolbar AS HWND, BYVAL iImageID AS DWORD, BYVAL himlNew AS HIMAGELIST) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hToolbar, TB_SETPRESSEDIMAGELIST, cast(WPARAM, iImageID), CAST(LPARAM, himlNew)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text drawing flags for the toolbar.
' Returns the previous text drawing flags.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetDrawTextFlags (BYVAL hToolbar AS HWND, BYVAL dwMask AS DWORD, BYVAL dwDTFlags AS DWORD) AS DWORD
   RETURN SendMessageW(hToolbar, TB_SETDRAWTEXTFLAGS, cast(WPARAM, dwMask), cast(LPARAM, dwDTFlags))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the extended styles for a toolbar control.
' Returns a DWORD that represents the previous extended styles. This value can be a
' combination of extended styles.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetExtendedStyle (BYVAL hToolbar AS HWND, BYVAL dwExStyle AS DWORD) AS DWORD
   RETURN SendMessageW(hToolbar, TB_SETEXTENDEDSTYLE, 0, cast(LPARAM, dwExStyle))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the hot item in a toolbar.
' iHot: Index of the item that will be made hot. If this value is -1, none of the items will be hot.
' Returns the index of the previous hot item, or -1 if there was no hot item.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetHotItem (BYVAL hToolbar AS HWND, BYVAL iHot AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_SETHOTITEM, cast(WPARAM, iHot), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the indentation for the first button in a toolbar control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetIndent (BYVAL hToolbar AS HWND, BYVAL iIndent AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETINDENT, cast(WPARAM, iIndent), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current insertion mark for the toolbar.
' ========================================================================================
PRIVATE SUB CToolbar.SetInsertMark (BYVAL hToolbar AS HWND, BYVAL ptbim AS TBINSERTMARK PTR)
   SendMessageW(hToolbar, TB_SETINSERTMARK, 0, CAST(LPARAM, ptbim))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CToolbar.SetInsertMark (BYVAL hToolbar AS HWND, BYREF tbim AS TBINSERTMARK)
   SendMessageW(hToolbar, TB_SETINSERTMARK, 0, CAST(LPARAM, @tbim))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the color used to draw the insertion mark for the toolbar.
' clrInsertMark: COLORREF value that contains the new insertion mark color.
' Returns a COLORREF value that contains the previous insertion mark color.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetInsertMarkColor (BYVAL hToolbar AS HWND, BYVAL clrInsertMark AS COLORREF) AS COLORREF
   RETURN SendMessageW(hToolbar, TB_SETINSERTMARKCOLOR, cast(WPARAM, clrInsertMark), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the distance between the toolbar buttons on a specific toolbar.
' ========================================================================================
PRIVATE SUB CToolbar.SetListGap (BYVAL hToolbar AS HWND, BYVAL gap AS DWORD)
   SendMessageW(hToolbar, TB_SETLISTGAP, gap, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the maximum number of text rows displayed on a toolbar button.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetMaxTextRows (BYVAL hToolbar AS HWND, BYVAL iMaxRows AS LONG) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETMAXTEXTROWS, cast(WPARAM, iMaxRows), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the metrics of a toolbar control.
' ptbMetrics: TBMETRICS structure that contains the toolbar metrics to set.
' ========================================================================================
PRIVATE SUB CToolbar.SetMetrics (BYVAL hToolbar AS HWND, BYVAL ptbMetrics AS TBMETRICS PTR)
   SendMessageW(hToolbar, TB_SETMETRICS, 0, CAST(LPARAM, ptbmetrics))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CToolbar.SetMetrics (BYVAL hToolbar AS HWND, BYREF tbMet AS TBMETRICS)
   SendMessageW(hToolbar, TB_SETMETRICS, 0, CAST(LPARAM, @tbMet))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the padding for a toolbar control.
' Returns a DWORD value that contains the previous horizontal padding in the LOWORD and
' the previous vertical padding in the HIWORD, in pixels.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetPadding (BYVAL hToolbar AS HWND, BYVAL cx AS SHORT, BYVAL cy AS SHORT) AS DWORD
   RETURN SendMessageW(hToolbar, TB_SETPADDING, 0, MAKELONG(cx, cy))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the window to which the toolbar control sends notification messages.
' The return value is a handle to the previous notification window, or NULL if there is no
' previous notification window.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetParent (BYVAL hToolbar AS HWND, BYVAL hwndParent AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hToolbar, TB_SETPARENT, CAST(WPARAM, hwndParent), 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the number of rows of buttons in a toolbar.
' ========================================================================================
PRIVATE SUB CToolbar.SetRows (BYVAL hToolbar AS HWND, BYVAL cRows AS WORD, BYVAL fLarger AS BOOLEAN, BYVAL prc AS RECT PTR)
   SendMessageW(hToolbar, TB_SETROWS, MAKELONG(cRows, fLarger), CAST(LPARAM, prc))
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CToolbar.SetRows (BYVAL hToolbar AS HWND, BYVAL cRows AS WORD, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT)
   SendMessageW(hToolbar, TB_SETROWS, MAKELONG(cRows, fLarger), CAST(LPARAM, @rc))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the state for the specified button in a toolbar.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetState (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fState AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hToolbar, TB_SETSTATE, cast(WPARAM, idButton), MAKELONG(fState, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the style for a toolbar control.
' ========================================================================================
PRIVATE SUB CToolbar.SetStyle (BYVAL hToolbar AS HWND, BYVAL dwStyle AS DWORD)
   SendMessageW(hToolbar, TB_SETSTYLE, 0, dwStyle)
END SUB
' ========================================================================================

' ========================================================================================
' Associates a ToolTip control with a toolbar.
' ========================================================================================
PRIVATE SUB CToolbar.SetToolTips (BYVAL hToolbar AS HWND, BYVAL hwndToolTip AS HWND)
   SendMessageW(hToolbar, TB_SETTOOLTIPS, CAST(WPARAM, hwndToolTip), 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the visual style of a toolbar control.
' Note: To use this API, you must provide a manifest specifying Comclt32.dll version 6.0.
' Minimum Operating System: Windows XP.
' ========================================================================================
PRIVATE SUB CToolbar.SetWindowTheme (BYVAL hToolbar AS HWND, BYVAL pwszTheme AS WSTRING PTR)
   SendMessageW(hToolbar, TB_SETWINDOWTHEME, CAST(WPARAM, pwszTheme), 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Makes the toolbar opaque by removing the TBSTYLE_TRANSPARENT style.
' ========================================================================================
PRIVATE SUB CToolbar.MakeOpaque (BYVAL hToolbar AS HWND)
   SetWindowLongPtrW(hToolbar, GWL_STYLE, GetWindowLongPtrW(hToolbar, GWL_STYLE) AND NOT TBSTYLE_TRANSPARENT)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the IDropTarget for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetObject (BYVAL hToolbar AS HWND) AS IDropTarget PTR
   DIM ppvObject AS IDropTarget PTR
   DIM IID_IDropTarget AS GUID = (&h00000122, &h0000, &h0000, {&hC0, &h00, &h00, &h00, &h00, &h00, &h00, &h46})
   DIM hr AS HRESULT = SendMessageW(hToolbar, TB_GETOBJECT, CAST(WPARAM, @IID_IDropTarget), CAST(LPARAM, ppvObject))
   IF hr <> S_OK THEN RETURN ppvObject
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the display text of a button on a toolbar.
' Returns the length, in characters, of the string pointed to by lParam. The length does
' not include the terminating null character. If unsuccessful, the return value is -1.
' idButton = Command identifier of the button whose text is to be retrieved.
' pBuffer = Pointer to a buffer that receives the button text.
' Minimum operating systems Windows NT 3.51, Windows 95
' Security Warning: Using this message incorrectly might compromise the security of your
' program. This message does not provide a way for you to know the size of the buffer.
' If you use this message, first call the message passing NULL in the lParam, this returns
' the number of characters, excluding NULL that are required. Then call the message a
' second time to retrieve the string.
' The returned string corresponds to the text that is currently displayed by the button.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonText (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL pBuffer AS WSTRING PTR) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETBUTTONTEXTW, cast(WPARAM, idButton), CAST(LPARAM, pbuffer))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonText (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS DWSTRING
   DIM cbLen AS LONG = SendMessageW(hToolbar, TB_GETBUTTONTEXTW, cast(WPARAM, idButton), 0)
   IF cbLen < 1 THEN RETURN ""
   DIM dwsText AS DWSTRING = WSPACE(cbLen + 1)
   SendMessageW(hToolbar, TB_GETBUTTONTEXTW, cast(WPARAM, idButton), CAST(LPARAM, *dwsText))
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the length of the display text of a button on a toolbar.
' Returns the length, in characters, of the string pointed to by lParam. The length does
' not include the terminating null character. If unsuccessful, the return value is -1.
' ========================================================================================
PRIVATE FUNCTION CToolbar.GetButtonTextLength (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
   RETURN SendMessageW(hToolbar, TB_GETBUTTONTEXTW, cast(WPARAM, idButton), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the toolbar dark mode.
' ========================================================================================
PRIVATE FUNCTION CToolbar.SetDarkMode (BYVAL hToolbar AS HWND) AS HRESULT
   RETURN ..SetWindowTheme(hToolbar, "DarkMode_InfoPaneToolbar", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Removes the toolbar dark mode.
' ========================================================================================
PRIVATE FUNCTION CToolbar.RemoveDarkMode (BYVAL hToolbar AS HWND) AS HRESULT
   RETURN ..SetWindowTheme(hToolbar, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
