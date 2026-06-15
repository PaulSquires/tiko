' ########################################################################################
' Platform: Microsoft Windows
' Filename: CButton.inc
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
' // conflicting define in windowsx.bi
#undef DeleteBitmap
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' CButton class
' ========================================================================================
TYPE CButton

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC SUB Click (BYVAL hButton AS HWND)
   DECLARE STATIC FUNCTION GetImage (BYVAL hButton AS HWND, BYVAL imgType AS LONG) AS HANDLE
   DECLARE STATIC FUNCTION GetBitmap (BYVAL hButton AS HWND) AS HANDLE
   DECLARE STATIC FUNCTION GetIcon (BYVAL hButton AS HWND) AS HANDLE
   DECLARE STATIC FUNCTION SetImage (BYVAL hButton AS HWND, BYVAL ImageType AS DWORD, BYVAL hImage AS HANDLE) AS HANDLE
   DECLARE STATIC FUNCTION SetBitmap (BYVAL hButton AS HWND, BYVAL hbmp AS HBITMAP) AS HBITMAP
   DECLARE STATIC FUNCTION SetIcon (BYVAL hButton AS HWND, BYVAL hIcon AS HICON) AS HICON
   DECLARE STATIC FUNCTION GetImageList (BYVAL hButton AS HWND, BYVAL pbuttonImagelist AS BUTTON_IMAGELIST PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetImageList (BYVAL hButton AS HWND, BYREF buttonImagelist AS BUTTON_IMAGELIST) AS BOOLEAN
   DECLARE STATIC FUNCTION GetImageList (BYVAL hButton AS HWND) AS BUTTON_IMAGELIST
   DECLARE STATIC FUNCTION SetImageList (BYVAL hButton AS HWND, BYVAL pbuttonImagelist AS BUTTON_IMAGELIST PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetImageList (BYVAL hButton AS HWND, BYVAL himl AS HIMAGELIST, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG, BYVAL uALign AS DWORD = 0) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteImage (BYVAL hButton AS HWND, BYVAL ImageType AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteBitmap (BYVAL hButton AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteIcon (BYVAL hButton AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Enable (BYVAL hButton AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Disable (BYVAL hButton AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetText (BYVAL hButton AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hButton AS HWND) AS LONG
   DECLARE STATIC FUNCTION SetText (BYVAL hButton AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCheck (BYVAL hButton AS HWND) AS LRESULT
   DECLARE STATIC SUB SetCheck (BYVAL hButton AS HWND, BYVAL checkState AS LONG)
   DECLARE STATIC SUB Check (BYVAL hButton AS HWND)
   DECLARE STATIC SUB Uncheck (BYVAL hButton AS HWND)
   DECLARE STATIC SUB Gray (BYVAL hButton AS HWND)
   DECLARE STATIC SUB Indeterminate (BYVAL hButton AS HWND)
   DECLARE STATIC FUNCTION GetState (BYVAL hButton AS HWND) AS LRESULT
   DECLARE STATIC SUB SetState (BYVAL hButton AS HWND, BYVAL bstate AS BOOLEAN)
   DECLARE STATIC FUNCTION GetStyle (BYVAL hButton AS HWND) AS DWORD
   DECLARE STATIC SUB SetStyle (BYVAL hButton AS HWND, BYVAL dwStyle AS DWORD, BYVAL fRedraw AS BOOLEAN)
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hButton AS HWND, BYVAL pSize AS SIZE PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hButton AS HWND, BYREF sz AS SIZE) AS BOOLEAN
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hButton AS HWND) AS SIZE
   DECLARE STATIC FUNCTION GetTextMargin (BYVAL hButton AS HWND, BYVAL pMargin AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetTextMargin (BYVAL hButton AS HWND, BYREF margin AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetTextMargin (BYVAL hButton AS HWND) AS RECT
   DECLARE STATIC FUNCTION SetTextMargin (BYVAL hButton AS HWND, BYVAL pMargin AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTextMargin (BYVAL hButton AS HWND, BYREF margin AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTextMargin (BYVAL hButton AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG) AS BOOLEAN

   #if _WIN32_WINNT >= &h0600
   DECLARE STATIC SUB SetDontClick (BYVAL hButton AS HWND, BYVAL bState AS BOOLEAN)
   DECLARE STATIC FUNCTION SetDropDownState (BYVAL hButton AS HWND, BYVAL fDropDown AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSplitGlyphSize (BYVAL hButton AS HWND) AS SIZE
   DECLARE STATIC FUNCTION GetSplitInfo (BYVAL hButton AS HWND, BYVAL pinfo AS BUTTON_SPLITINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSplitInfo (BYVAL hButton AS HWND, BYREF info AS BUTTON_SPLITINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSplitInfo (BYVAL hButton AS HWND) AS BUTTON_SPLITINFO
   DECLARE STATIC FUNCTION SetSplitInfo (BYVAL hButton AS HWND, BYVAL pinfo AS BUTTON_SPLITINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetSplitInfo (BYVAL hButton AS HWND, BYREF info AS BUTTON_SPLITINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSplitStyle (BYVAL hButton AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetSplitImageList (BYVAL hButton AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetSplitGlyphSize (BYVAL hButton AS HWND, BYVAL cx AS LONG, BYVAL cy AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetSplitStyle (BYVAL hButton AS HWND, BYVAL uStyle AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION SetSplitImageList (BYVAL hButton AS HWND, BYVAL himlGlyph AS HIMAGELIST) AS BOOLEAN
   DECLARE STATIC FUNCTION GetNoteLength (BYVAL hButton AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetNote (BYVAL hButton AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION SetNote (BYVAL hButton AS HWND, BYVAL pwsz AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetElevationRequiredState (BYVAL hButton AS HWND, BYVAL fRequired AS BOOLEAN) AS LONG
   #endif

   DECLARE STATIC FUNCTION SetDarkMode(BYVAL hButton AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode(BYVAL hButton AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CButton
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CButton
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Simulates the user clicking a button. This message causes the button to receive the
' WM_LBUTTONDOWN and WM_LBUTTONUP messages, and the button's parent window to receive a
' BN_CLICKED notification code.
' ========================================================================================
PRIVATE SUB CButton.Click (BYVAL hButton AS HWND)
   SendMessageW(hButton, BM_CLICK, 0, 0)
END sUB
' ========================================================================================

' ========================================================================================
' * Retrieves a handle to the image (icon or bitmap) associated with the button.
' The return value is a handle to the image, if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CButton.GetImage (BYVAL hButton AS HWND, BYVAL imgType AS LONG) AS HANDLE
   RETURN cast(HANDLE, SendMessageW(hButton, BM_GETIMAGE, imgType, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves a handle to the bitmap associated with the button.
' ========================================================================================
PRIVATE FUNCTION CButton.GetBitmap (BYVAL hButton AS HWND) AS HANDLE
   RETURN CAST(HANDLE, SendMessageW(hButton, BM_GETIMAGE, IMAGE_BITMAP, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves a handle to the icon associated with the button.
' ========================================================================================
PRIVATE FUNCTION CButton.GetIcon (BYVAL hButton AS HWND) AS HANDLE
   RETURN cast(HANDLE, SendMessageW(hButton, BM_GETIMAGE, IMAGE_ICON, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Associates a new image (icon or bitmap) with the button. The return value is a handle to
' the image previously associated with the button, if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CButton.SetImage (BYVAL hButton AS HWND, BYVAL ImageType AS DWORD, BYVAL hImage AS HANDLE) AS HANDLE
   RETURN cast(HANDLE, SendMessageW(hButton, BM_SETIMAGE, cast(WPARAM, ImageType), cast(LPARAM, hImage)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Associates a new bitmap with a button. The return value is a handle to the image previously
' associated with the button, if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CButton.SetBitmap (BYVAL hButton AS HWND, BYVAL hbmp AS HBITMAP) AS HBITMAP
   RETURN cast(HBITMAP, SendMessageW(hButton, BM_SETIMAGE, cast(WPARAM, IMAGE_BITMAP), cast(LPARAM, hbmp)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Associates a new icon with the button. The return value is a handle to the image previously
' associated with the button, if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CButton.SetIcon (BYVAL hButton AS HWND, BYVAL hIcon AS HICON) AS HICON
   RETURN cast(..HICON, SendMessageW(hButton, BM_SETIMAGE, cast(WPARAM, IMAGE_ICON), cast(LPARAM, hIcon)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the BUTTON_IMAGELIST structure that describes the image list assigned to a button control. 
' ========================================================================================
PRIVATE FUNCTION CButton.GetImageList (BYVAL hButton AS HWND, BYVAL pbuttonImagelist AS BUTTON_IMAGELIST PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETIMAGELIST, 0, CAST(LPARAM, pbuttonImagelist))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetImageList (BYVAL hButton AS HWND, BYREF buttonImagelist AS BUTTON_IMAGELIST) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETIMAGELIST, 0, CAST(LPARAM, @buttonImagelist))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetImageList (BYVAL hButton AS HWND) AS BUTTON_IMAGELIST
   DIM bi AS BUTTON_IMAGELIST
   SendMessageW(hButton, BCM_GETIMAGELIST, 0, CAST(LPARAM, @bi))
   RETURN bi
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Assigns an image list to a button control.
' ========================================================================================
PRIVATE FUNCTION CButton.SetImageList (BYVAL hButton AS HWND, BYVAL pbuttonImagelist AS BUTTON_IMAGELIST PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETIMAGELIST, 0, cast(LPARAM, pbuttonImagelist))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Assigns an image list to a button control. Requires Windows XP or superior.
' Parameters:
' - hButon     = The handle of the button.
' - hImageList =
' - nLeft      = The x-coordinate of the upper-left corner of the rectangle for the image.
' - nTop       = The y-coordinate of the upper-left corner of the rectangle for the image.
' - nRight     = The x-coordinate of the lower-right corner of the rectangle for the image.
' - nBottom    = The y-coordinate of the lower-right corner of the rectangle for the image.
' - uAlign     = The alignment to use. This parameter can be one of the following values:
'                BUTTON_IMAGELIST_ALIGN_LEFT   Align the image with the left margin.
'                BUTTON_IMAGELIST_ALIGN_RIGHT  Align the image with the right margin
'                BUTTON_IMAGELIST_ALIGN_TOP    Align the image with the top margin
'                BUTTON_IMAGELIST_ALIGN_BOTTOM Align the image with the bottom margin
'                BUTTON_IMAGELIST_ALIGN_CENTER Center the image.
'                The default value is BUTTON_IMAGELIST_ALIGN_LEFT.
' Return value:  If the function succeeds, it returns TRUE. Otherwise it returns FALSE.
' ========================================================================================
PRIVATE FUNCTION CButton.SetImageList (BYVAL hButton AS HWND, BYVAL himl AS HIMAGELIST, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG, BYVAL uALign AS UINT = 0) AS BOOLEAN
   DIM bi AS BUTTON_IMAGELIST = (himl, (nLeft, nTop, nRight, nBottom), uAlign)
   RETURN SendMessageW(hButton, BCM_SETIMAGELIST, 0, cast(LPARAM, @bi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes an image (icon or bitmap) associated a button.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CButton.DeleteImage (BYVAL hButton AS HWND, BYVAL ImageType AS DWORD) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hButton, BM_SETIMAGE, cast(WPARAM, ImageType), cast(LPARAM, NULL))))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Deletes a bitmap associated with a button.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CButton.DeleteBitmap (BYVAL hButton AS HWND) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hButton, BM_SETIMAGE, cast(WPARAM, IMAGE_BITMAP), cast(LPARAM, NULL))))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Deletes an icon associated with a button.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CButton.DeleteIcon (BYVAL hButton AS HWND) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hButton, BM_SETIMAGE, cast(WPARAM, IMAGE_ICON), cast(LPARAM, NULL))))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Enables mouse and keyboard input to the specified button 
' ========================================================================================
PRIVATE FUNCTION CButton.Enable (BYVAL hButton AS HWND) AS BOOLEAN
   RETURN EnableWIndow(hButton, CTRUE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Disables mouse and keyboard input to the specified button 
' ========================================================================================
PRIVATE FUNCTION CButton.Disable (BYVAL hButton AS HWND) AS BOOLEAN
   RETURN EnableWIndow(hButton, FALSE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text of a button.
' ========================================================================================
PRIVATE FUNCTION CButton.GetText (BYVAL hButton AS HWND) AS DWSTRING
   DIM nLen AS LONG = GetWindowTextLengthW(hButton)
   DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
   GetWindowTextW(hButton, dwsText, nLen +  1)
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the length of the text of a button.
' ========================================================================================
PRIVATE FUNCTION CButton.GetTextLength (BYVAL hButton AS HWND) AS LONG
   RETURN GetWindowTextLengthW(hButton)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of the button.
' ========================================================================================
PRIVATE FUNCTION CButton.SetText (BYVAL hButton AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   RETURN SetWindowTextW(hButton, pwszText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the check state of a radio button or check box.
' ========================================================================================
PRIVATE FUNCTION CButton.GetCheck (BYVAL hButton AS HWND) AS LRESULT
   RETURN SendMessageW(hButton, BM_GETCHECK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the check state of a radio button or check box.
' ========================================================================================
PRIVATE SUB CButton.SetCheck (BYVAL hButton AS HWND, BYVAL checkState AS LONG)
   SendMessageW(hButton, BM_SETCHECK, checkState, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Sets the button state to checked.
' ========================================================================================
PRIVATE SUB CButton.Check (BYVAL hButton AS HWND)
   SendMessageW hButton, BM_SETCHECK, BST_CHECKED, 0
END SUB
' ========================================================================================
' ========================================================================================
' * Unchecks the button.
' ========================================================================================
PRIVATE SUB CButton.Uncheck (BYVAL hButton AS HWND)
   SendMessageW hButton, BM_SETCHECK, BST_UNCHECKED, 0
END SUB
' ========================================================================================
' ========================================================================================
' * Sets the button state to grayed, indicating an indeterminate state. Use this value only
' if the button has the BS_3STATE or BS_AUTO3STATE style.
' ========================================================================================
PRIVATE SUB CButton.Gray (BYVAL hButton AS HWND)
   SendMessageW hButton, BM_SETCHECK, BST_INDETERMINATE, 0
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CButton.Indeterminate (BYVAL hButton AS HWND)
   SendMessageW hButton, BM_SETCHECK, BST_INDETERMINATE, 0
END SUB
' ========================================================================================

' ========================================================================================
' * Gets the state of a button or check box.
' ========================================================================================
PRIVATE FUNCTION CButton.GetState (BYVAL hButton AS HWND) AS LRESULT
   RETURN SendMessageW(hButton, BM_GETSTATE, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Sets the highlight state of a button. The highlight state indicates whether the button
' is highlighted as if the user had pushed it. 
' ========================================================================================
PRIVATE SUB CButton.SetState (BYVAL hButton AS HWND, BYVAL bstate AS BOOLEAN)
   SendMessageW(hButton, BM_SETSTATE, bstate, 0)
END SUB
' ========================================================================================

' ========================================================================================
' * Gets the style of button.
' ========================================================================================
PRIVATE FUNCTION CButton.GetStyle (BYVAL hButton AS HWND) AS DWORD
   RETURN GetWindowLongPtrW(hButton, GWL_STYLE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the style of a button.
' ========================================================================================
PRIVATE SUB CButton.SetStyle (BYVAL hButton AS HWND, BYVAL dwStyle AS DWORD, BYVAL fRedraw AS BOOLEAN)
   SendMessageW(hButton, BM_SETSTYLE, dwStyle, fRedraw)
END SUB
' ========================================================================================

' ========================================================================================
' * Gets the size of the button that best fits its text and image, if an image list is present.
' ========================================================================================
PRIVATE FUNCTION CButton.GetIdealSize (BYVAL hButton AS HWND, BYVAL pSize AS SIZE PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETIDEALSIZE, 0, CAST(LPARAM, pSize))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetIdealSize (BYVAL hButton AS HWND) AS SIZE
   DIM sz AS SIZE
   SendMessageW(hButton, BCM_GETIDEALSIZE, 0, CAST(LPARAM, @sz))
   RETURN sz
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the margins used to draw text in a button control.
' ========================================================================================
PRIVATE FUNCTION CButton.GetTextMargin (BYVAL hButton AS HWND, BYVAL pMargin AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETTEXTMARGIN, 0, CAST(LPARAM, pMargin))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetTextMargin (BYVAL hButton AS HWND, BYREF margin AS RECT) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETTEXTMARGIN, 0, CAST(LPARAM, @margin))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetTextMargin (BYVAL hButton AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hButton, BCM_GETTEXTMARGIN, 0, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Sets the margins for drawing text in a button control.
' ========================================================================================
PRIVATE FUNCTION CButton.SetTextMargin (BYVAL hButton AS HWND, BYVAL pMargin AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETTEXTMARGIN, 0, CAST(LPARAM, pMargin))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.SetTextMargin (BYVAL hButton AS HWND, BYREF margin AS RECT) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETTEXTMARGIN, 0, CAST(LPARAM, @margin))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.SetTextMargin (BYVAL hButton AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG) AS BOOLEAN
   DIM rc AS RECT = TYPE(nLeft, nTop, nRight, nBottom)
   RETURN SendMessageW(hButton, BCM_SETTEXTMARGIN, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT = &h0602

' ========================================================================================
' Sets a flag on a radio button that controls the generation of BN_CLICKED messages when
' the button receives focus.
' Starting with Vista and later, radio buttons no longer send BN_CLICKED when they
' receive focus, so this message has not effect in these Windows versions.
' ========================================================================================
PRIVATE SUB CButton.SetDontClick (BYVAL hButton AS HWND, BYVAL fState AS BOOLEAN)
   SendMessageW(hButton, BM_SETDONTCLICK, cast(WPARAM, fState), 0)
END SUB
 ' ========================================================================================

 ' ========================================================================================
' * Sets the drop down state for a specified button with style of BS_SPLITBUTTON.
' ========================================================================================
PRIVATE FUNCTION CButton.SetDropDownState (BYVAL hButton AS HWND, BYVAL fDropDown AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETDROPDOWNSTATE, fDropDown, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CButton.GetSplitGlyphSize (BYVAL hButton AS HWND) AS SIZE
   DIM info AS BUTTON_SPLITINFO
   info.mask = BCSIF_SIZE
   SendMessageW(hButton, BCM_GETSPLITINFO, 0, CAST(LPARAM, @info))
   DIM sz AS SIZE
   sz.cx = info.size.cx
   sz.cy = info.size.cy
   RETURN sz
END FUNCTION
' ========================================================================================
' ========================================================================================
' Gets information for a specified split button control.
' ========================================================================================
PRIVATE FUNCTION CButton.GetSplitInfo (BYVAL hButton AS HWND, BYVAL pinfo AS BUTTON_SPLITINFO PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETSPLITINFO, 0, CAST(LPARAM, pinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetSplitInfo (BYVAL hButton AS HWND, BYREF info AS BUTTON_SPLITINFO) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_GETSPLITINFO, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetSplitInfo (BYVAL hButton AS HWND) AS BUTTON_SPLITINFO
   DIM info AS BUTTON_SPLITINFO
'   info.mask = BCSIF_GLYPH OR BCSIF_IMAGE OR BCSIF_SIZE OR BCSIF_STYLE
   info.mask = BCSIF_IMAGE OR BCSIF_SIZE OR BCSIF_STYLE
   SendMessageW(hButton, BCM_GETSPLITINFO, 0, CAST(LPARAM, @info))
   RETURN info
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetSplitStyle (BYVAL hButton AS HWND) AS UINT
   DIM info AS BUTTON_SPLITINFO
   info.mask = BCSIF_STYLE
   SendMessageW(hButton, BCM_GETSPLITINFO, 0, CAST(LPARAM, @info))
   RETURN info.uSplitStyle
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.GetSplitImageList (BYVAL hButton AS HWND) AS HIMAGELIST
   DIM info AS BUTTON_SPLITINFO
   info.mask = BCSIF_IMAGE
   SendMessageW(hButton, BCM_GETSPLITINFO, 0, CAST(LPARAM, @info))
   RETURN info.himlGlyph
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the split size (glyph area) of a split button (BCSIF_SIZE).
' ========================================================================================
PRIVATE FUNCTION CButton.SetSplitGlyphSize (BYVAL hButton AS HWND, BYVAL cx AS LONG, BYVAL cy AS LONG) AS BOOLEAN
   DIM info AS BUTTON_SPLITINFO
   info.mask = BCSIF_SIZE
   info.size.cx = cx
   info.size.cy = cy
   RETURN SendMessageW(hButton, BCM_SETSPLITINFO, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets information for a specified split button control.
' ========================================================================================
PRIVATE FUNCTION CButton.SetSplitInfo (BYVAL hButton AS HWND, BYVAL pinfo AS BUTTON_SPLITINFO PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETSPLITINFO, 0, CAST(LPARAM, pinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CButton.SetSplitInfo (BYVAL hButton AS HWND, BYREF info AS BUTTON_SPLITINFO) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETSPLITINFO, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Sets the split style of a split button (BCSIF_STYLE).
' ========================================================================================
PRIVATE FUNCTION CButton.SetSplitStyle (BYVAL hButton AS HWND, BYVAL uStyle AS UINT) AS BOOLEAN
   DIM info AS BUTTON_SPLITINFO
   info.mask = BCSIF_STYLE
   info.uSplitStyle = uStyle
   RETURN SendMessageW(hButton, BCM_SETSPLITINFO, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets the image list used as split glyph (BCSIF_IMAGE / BCSIF_GLYPH).
' Normally you only need BCSIF_IMAGE; BCSIF_GLYPH is optional.
' ========================================================================================
PRIVATE FUNCTION CButton.SetSplitImageList (BYVAL hButton AS HWND, BYVAL himlGlyph AS HIMAGELIST) AS BOOLEAN
   DIM info AS BUTTON_SPLITINFO
   info.mask = BCSIF_IMAGE   ' o BCSIF_IMAGE OR BCSIF_GLYPH if you want to force a glyph
   info.himlGlyph = himlGlyph
   RETURN SendMessageW(hButton, BCM_SETSPLITINFO, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the length of the note text that may be displayed in the description for a command link.
' ========================================================================================
PRIVATE FUNCTION CButton.GetNoteLength (BYVAL hButton AS HWND) AS LONG
   RETURN SendMessageW(hButton, BCM_GETNOTELENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text of the note associated with the Command Link button.
' ========================================================================================
PRIVATE FUNCTION CButton.GetNote (BYVAL hButton AS HWND) AS DWSTRING
   DIM nLen AS DWORD = SendMessageW(hButton, BCM_GETNOTELENGTH, 0, 0)
   IF nLen < 1 THEN RETURN ""
   nLen += 1
   DIM dws AS DWSTRING = WSPACE(nLen)
'   SendMessageW(hButton, BCM_GETNOTE, cast(WPARAM, @nLen), CAST(LPARAM, STRPTR(dws)))
   SendMessageW(hButton, BCM_GETNOTE, cast(WPARAM, @nLen), CAST(LPARAM, *dws))
   IF nLen THEN dws = LEFT(dws, nLen - 1)
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of the note associated with a specified command link button.
' Note: The note text is displayed underneath the main caption.  
'       Command Link buttons require extra vertical space; if the control  
'       is too short, Windows will hide the note and render a single-line layout.  
'       Make the button taller to ensure the note becomes visible.
' ========================================================================================
PRIVATE FUNCTION CButton.SetNote (BYVAL hButton AS HWND, BYVAL pwsz AS WSTRING PTR) AS BOOLEAN
   RETURN SendMessageW(hButton, BCM_SETNOTE, 0, CAST(LPARAM, pwsz))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the elevation required state for a specified button or command link to display an elevated icon.
' Note: Although the documentation says that it returns 1 on success, it seems to return always 0.
' ========================================================================================
PRIVATE FUNCTION CButton.SetElevationRequiredState (BYVAL hButton AS HWND, BYVAL fRequired AS BOOLEAN) AS LONG
   RETURN SendMessageW(hButton, BCM_SETSHIELD, 0, fRequired)
END FUNCTION
' ========================================================================================

#endif

' ========================================================================================
' * Set button dark mode.
' ========================================================================================
PRIVATE FUNCTION CButton.SetDarkMode (BYVAL hButton AS HWND) AS HRESULT
   RETURN SetWindowTheme(hButton, "DarkMode_Explorer", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Remove button dark mode.
' ========================================================================================
PRIVATE FUNCTION CButton.RemoveDarkMode (BYVAL hButton AS HWND) AS HRESULT
   RETURN SetWindowTheme(hButton, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
