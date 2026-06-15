' ########################################################################################
' Platform: Microsoft Windows
' Filename: CStatic.inc
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
#include once "win/uxtheme.bi"
#include once "AfxNova/DWSTRING.inc"
' // conflicting define in windowsx.bi
#undef DeleteBitmap
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
' CStatic class
' ########################################################################################

TYPE CStatic

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION Enable (BYVAL hStatic AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Disable (BYVAL hStatic AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteBitmap (BYVAL hStatic AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteCursor (BYVAL hStatic AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteEnhancedMetafile (BYVAL hStatic AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteIcon (BYVAL hStatic AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteImage (BYVAL hStatic AS HWND, BYVAL nType AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetIcon (BYVAL hStatic AS HWND) AS HICON
   DECLARE STATIC FUNCTION GetImage (BYVAL hStatic AS HWND, BYVAL nType AS LONG) AS HANDLE
   DECLARE STATIC FUNCTION SetImage (BYVAL hStatic AS HWND, BYVAL nType AS LONG, BYVAL hImage AS HANDLE) AS HANDLE
   DECLARE STATIC FUNCTION SetBitmap (BYVAL hStatic AS HWND, BYVAL hBmp AS HBITMAP) AS HBITMAP
   DECLARE STATIC FUNCTION SetCursor (BYVAL hStatic AS HWND, BYVAL hCur AS HCURSOR) AS HCURSOR
   DECLARE STATIC FUNCTION SetEnhancedMetafile (BYVAL hStatic AS HWND, BYVAL _hEnhMetafile AS HENHMETAFILE) AS HENHMETAFILE
   DECLARE STATIC FUNCTION SetIcon (BYVAL hStatic AS HWND, BYVAL hIcon AS HICON) AS HICON
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hStatic AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetText (BYVAL hStatic AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION SetText (BYVAL hStatic AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CStatic
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CStatic
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Enables the control.
' Return value: False if the control was previous enabled; otherwise TRUE
' ========================================================================================
PRIVATE FUNCTION CStatic.Enable (BYVAL hStatic AS HWND) AS BOOLEAN
   RETURN EnableWindow(hStatic, CTRUE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Disables the control.
' Return value: False if the control was previous disabled; otherwise TRUE
' ========================================================================================
PRIVATE FUNCTION CStatic.Disable (BYVAL hStatic AS HWND) AS BOOLEAN
   DIM res AS LONG = EnableWindow(hStatic, FALSE)
   DIM bEnable AS BOOLEAN
   IF res = 0 THEN bEnable = TRUE ELSE bEnable = FALSE
   RETURN bEnable
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a bitmap associated with a static control. Returns TRUE o FALSE.
' ========================================================================================
PRIVATE FUNCTION CStatic.DeleteBitmap (BYVAL hStatic AS HWND) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, IMAGE_BITMAP), 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a cursor associated with a static control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CStatic.DeleteCursor (BYVAL hStatic AS HWND) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, IMAGE_CURSOR), 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an enhanced metafile associated with a static control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CStatic.DeleteEnhancedMetafile (BYVAL hStatic AS HWND) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, IMAGE_ENHMETAFILE), 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an icon associated with a static control. Returns TRUE o FALSE.
' ========================================================================================
PRIVATE FUNCTION CStatic.DeleteIcon (BYVAL hStatic AS HWND) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hStatic, STM_SETICON, 0, 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an image associated with a static control. Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CStatic.DeleteImage (BYVAL hStatic AS HWND, BYVAL nType AS LONG) AS BOOLEAN
   RETURN DeleteObject(cast(HGDIOBJ, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, nType), 0)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to the icon associated with a static control that has the SS_ICON style.
' ========================================================================================
PRIVATE FUNCTION CStatic.GetIcon (BYVAL hStatic AS HWND) AS HICON
   RETURN CAST(HICON, SendMessageW(hStatic, STM_GETICON, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to the image (icon or bitmap) associated with a static control.
' The return value is a handle to the image, if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CStatic.GetImage (BYVAL hStatic AS HWND, BYVAL nType AS LONG) AS HANDLE
   RETURN cast(HANDLE, SendMessageW(hStatic, STM_GETIMAGE, nType, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a bitmap with a static control.
' The return value is a handle to the image previously associated with the static control,
' if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CStatic.SetBitmap (BYVAL hStatic AS HWND, BYVAL hBmp AS HBITMAP) AS HBITMAP
   RETURN cast(HBITMAP, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, IMAGE_BITMAP), cast(LPARAM, hBmp)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a cursor with a static control.
' The return value is a handle to the cursor previously associated with the static control.
' ========================================================================================
PRIVATE FUNCTION CStatic.SetCursor (BYVAL hStatic AS HWND, BYVAL hCur AS HCURSOR) AS HCURSOR
   RETURN cast(HCURSOR, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, IMAGE_CURSOR), cast(LPARAM, hCur)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates an enhanced metafile with a static control.
' The return value is a handle to the image previously associated with the static control,
' if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CStatic.SetEnhancedMetafile (BYVAL hStatic AS HWND, BYVAL _hEnhMetafile AS HENHMETAFILE) AS HENHMETAFILE
   RETURN cast(HENHMETAFILE, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, IMAGE_ENHMETAFILE), cast(LPARAM, _hEnhMetafile)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates an icon with an static control.
' The return value is a handle to the icon previously associated with the static control,
' if any; otherwise, it is NULL.
' ========================================================================================
PRIVATE FUNCTION CStatic.SetIcon (BYVAL hStatic AS HWND, BYVAL hIcon AS HICON) AS HICON
   RETURN CAST(..HICON, SendMessageW(hStatic, STM_SETICON, CAST(WPARAM, hIcon), 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new image with a static control.
' The return value is a handle to the image previously associated with the static control,
' if any; otherwise, it is NULL.
' To associate an image with a static control, the control must have the proper style. The
' following table shows the style needed for each image type.
' Image type          Static control style
'   IMAGE_BITMAP      SS_BITMAP
'   IMAGE_CURSOR      SS_ICON
'   IMAGE_ENHMETAFILE SS_ENHMETAFILE
'   IMAGE_ICON        SS_ICON
' ========================================================================================
PRIVATE FUNCTION CStatic.SetImage (BYVAL hStatic AS HWND, BYVAL nType AS LONG, BYVAL hImage AS HANDLE) AS HANDLE
   RETURN cast(HANDLE, SendMessageW(hStatic, STM_SETIMAGE, cast(WPARAM, nType), cast(LPARAM, hImage)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the length of the text of a static control.
' ========================================================================================
PRIVATE FUNCTION CStatic.GetTextLength (BYVAL hStatic AS HWND) AS LONG
   RETURN GetWindowTextLength(hStatic)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text of a static control.
' ========================================================================================
PRIVATE FUNCTION CStatic.GetText (BYVAL hStatic AS HWND) AS DWSTRING
   DIM nLen AS LONG, buffer AS DWSTRING
   nLen = GetWindowTextLength(hStatic)
   buffer = WSPACE(nLen + 1)
   GetWindowTextW hStatic, STRPTR(buffer), nLen + 1
   RETURN buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of a static control.
' ========================================================================================
PRIVATE FUNCTION CStatic.SetText (BYVAL hStatic AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   RETURN SetWindowTextW(hStatic, pwszText)
END FUNCTION
' ========================================================================================

END NAMESPACE
