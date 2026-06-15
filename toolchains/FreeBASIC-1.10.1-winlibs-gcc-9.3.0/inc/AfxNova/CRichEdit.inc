' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxRichEdit.inc
' Purpose:  Rich Edit control procedures
' Compiler: FreeBASIC 32 & 64 bit
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
#include once "win/richedit.bi"
#include once "win/richole.bi"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' Custom structure used by the CRichEdit.LoadRtfFromResourceW function.
' ========================================================================================
#ifndef AFX_RICHEDIT_CUSTOMDATA
TYPE AFX_RICHEDIT_CUSTOMDATA
   pData  AS BYTE PTR
   nLen   AS LONG
   curPos AS LONG
END TYPE
#endif
' ========================================================================================

' ========================================================================================
' CRichEdit class
' ========================================================================================
TYPE CRichEdit

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION AutoUrlDetect (BYVAL hRichEdit AS HWND, BYVAL fUrlDetect AS LONG) AS LONG
   DECLARE STATIC FUNCTION CallAutocorrectProc (BYVAL hRichEdit AS HWND, BYVAL char AS WCHAR) AS LONG
   DECLARE STATIC FUNCTION CanPaste (BYVAL hRichEdit AS HWND, BYVAL clipformat AS LONG) AS LONG
   DECLARE STATIC FUNCTION CanRedo (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION CanUndo (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION CharFromPos (BYVAL hRichEdit AS HWND, BYVAL lppl AS POINTL PTR) AS LONG
   DECLARE STATIC FUNCTION DisplayBand (BYVAL hRichEdit AS HWND, BYVAL lprc AS RECT PTR) AS LONG
   DECLARE STATIC SUB EmptyUndoBuffer (BYVAL hRichEdit AS HWND)
   DECLARE STATIC SUB ExGetSel (BYVAL hRichEdit AS HWND, BYVAL lpchr AS CHARRANGE PTR)
   DECLARE STATIC SUB ExLimitText (BYVAL hRichEdit AS HWND, BYVAL dwLimit AS DWORD)
   DECLARE STATIC FUNCTION ExLineFromChar (BYVAL hRichEdit AS HWND, BYVAL iIndex AS LONG) AS LONG
   DECLARE STATIC FUNCTION ExSetSel (BYVAL hRichEdit AS HWND, BYVAL lpcr AS CHARRANGE PTR) AS DWORD
   DECLARE STATIC FUNCTION FindText (BYVAL hRichEdit AS HWND, BYVAL fOptions AS DWORD, BYVAL lpft AS FINDTEXTW PTR) AS LONG
   DECLARE STATIC FUNCTION FindTextEx (BYVAL hRichEdit AS HWND, BYVAL fOptions AS DWORD, BYVAL lpftexw AS FINDTEXTEXW PTR) AS LONG
   DECLARE STATIC FUNCTION FindWordBreak (BYVAL hRichEdit AS HWND, BYVAL fOperation AS DWORD, BYVAL dwStartPos AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION FormatRange (BYVAL hRichEdit AS HWND, BYVAL fRender AS LONG, BYVAL lpfr AS ..FORMATRANGE PTR) AS DWORD
   DECLARE STATIC FUNCTION GetAutoCorrectProc (BYVAL hRichEdit AS HWND) AS LONG_PTR
   DECLARE STATIC FUNCTION GetAutoUrlDetect (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC SUB GetBidiOptions (BYVAL hRichEdit AS HWND, BYVAL lpbo AS BIDIOPTIONS PTR)
   DECLARE STATIC FUNCTION GetCharFormat (BYVAL hRichEdit AS HWND, BYVAL fOption AS DWORD, BYVAL lpcf AS CHARFORMATW PTR) AS DWORD
   DECLARE STATIC FUNCTION GetCTFModeBias (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetCTFOpenStatus (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetEditStyle (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetEditStyleEx (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetEllipsisMode (BYVAL hRichEdit AS HWND, BYVAL pmode AS DWORD PTR) AS DWORD
   DECLARE STATIC FUNCTION GetEllipsisState (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetEventMask (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetFirstVisibleLine (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC SUB GetHyphenateInfo (BYVAL hRichEdit AS HWND, BYVAL lphi AS HYPHENATEINFO PTR)
   DECLARE STATIC FUNCTION GetIMEColor (BYVAL hRichEdit AS HWND, BYVAL rgCmpclr AS COMPCOLOR PTR) AS LONG
   DECLARE STATIC FUNCTION GetIMECompMode (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetIMECompText (BYVAL hRichEdit AS HWND, BYVAL lpict AS IMECOMPTEXT PTR, BYVAL buffer AS ANY PTR) AS DWORD
   DECLARE STATIC FUNCTION GetIMEModeBias (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetIMEOptions (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetIMEProperty (BYVAL hRichEdit AS HWND, BYVAL figp AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION GetLangOptions (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetLimitText (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetLine (BYVAL hRichEdit AS HWND, BYVAL which AS DWORD) AS DWSTRING
   DECLARE STATIC FUNCTION GetLineCount (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetModify (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetOleInterface (BYVAL hRichEdit AS HWND, BYVAL ppObject AS IUnknown PTR PTR) AS LONG
   DECLARE STATIC FUNCTION GetOptions (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetPageRotate (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetParaFormat (BYVAL hRichEdit AS HWND, BYVAL pParaFmt AS PARAFORMAT PTR) AS DWORD
   DECLARE STATIC FUNCTION GetPasswordChar (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetPunctuation (BYVAL hRichEdit AS HWND, BYVAL punctype AS DWORD, BYVAL lppunct AS PUNCTUATION PTR) AS LONG
   DECLARE STATIC SUB GetRect (BYVAL hRichEdit AS HWND, BYVAL prc AS RECT PTR)
   DECLARE STATIC FUNCTION GetRedoName (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetScrollPos (BYVAL hRichEdit AS HWND, BYVAL lppt AS POINT PTR) AS DWORD
   DECLARE STATIC FUNCTION GetSel (BYVAL hRichEdit AS HWND, BYVAL pdwStartPos AS DWORD PTR, BYVAL pdwEndPos AS DWORD PTR) AS LONG
   DECLARE STATIC FUNCTION GetSelText (BYVAL hRichEdit AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetStoryTpe (BYVAL hRichEdit AS HWND, BYVAL Index AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION GetTableParams (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
   DECLARE STATIC FUNCTION GetText (BYVAL hRichEdit AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetTextEx (BYVAL hRichEdit AS HWND, BYVAL lpgtex AS ..GETTEXTEX PTR, BYVAL buffer AS ANY PTR) AS DWORD
   DECLARE STATIC FUNCTION GetTextLength (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetTextLengthEx (BYVAL hRichEdit AS HWND, BYVAL lpgtex AS ..GETTEXTLENGTHEX PTR) AS LONG
   DECLARE STATIC FUNCTION GetTextMode (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetTextRange (BYVAL hRichEdit AS HWND, BYVAL lptrg AS TEXTRANGEW PTR) AS DWORD
   DECLARE STATIC FUNCTION GetThumb (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetTouchOptions (BYVAL hRichEdit AS HWND, BYVAL Options AS LONG PTR) AS DWORD
   DECLARE STATIC FUNCTION GetTypographyOptions (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetUndoName (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetWordBreakProc (BYVAL hRichEdit AS HWND) AS LONG_PTR
   DECLARE STATIC FUNCTION GetWordBreakProcEx (BYVAL hRichEdit AS HWND) AS LONG_PTR
   DECLARE STATIC FUNCTION GetWordWrapMode (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetZoom (BYVAL hRichEdit AS HWND, BYVAL pzNum AS DWORD PTR, BYVAL pzDen AS DWORD PTR) AS LONG
   DECLARE STATIC SUB HideSelection (BYVAL hRichEdit AS HWND, BYVAL fHide AS DWORD)
   DECLARE STATIC FUNCTION InsertImage (BYVAL hRichEdit AS HWND, BYVAL lpip AS RICHEDIT_IMAGE_PARAMETERS PTR) AS DWORD
   DECLARE STATIC FUNCTION InsertTable (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
   DECLARE STATIC FUNCTION IsIME (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC SUB LimitText (BYVAL hRichEdit AS HWND, BYVAL chMax AS DWORD)
   DECLARE STATIC FUNCTION LineFromChar (BYVAL hRichEdit AS HWND, BYVAL index AS DWORD) AS LONG
   DECLARE STATIC FUNCTION LineIndex (BYVAL hRichEdit AS HWND, BYVAL nLine AS LONG) AS LONG
   DECLARE STATIC FUNCTION LineLength (BYVAL hRichEdit AS HWND, BYVAL index AS DWORD) AS LONG
   DECLARE STATIC FUNCTION LineScroll (BYVAL hRichEdit AS HWND, BYVAL y AS LONG) AS LONG
   DECLARE STATIC SUB PasteSpecial (BYVAL hRichEdit AS HWND, BYVAL clpfmt AS DWORD, BYVAL lprps AS REPASTESPECIAL PTR)
   DECLARE STATIC SUB PosFromChar (BYVAL hRichEdit AS HWND, BYVAL pt AS POINTL PTR, BYVAL index AS DWORD)
   DECLARE STATIC FUNCTION Reconversion (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION Redo (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC SUB ReplaceSel (BYVAL hRichEdit AS HWND, BYVAL bCanBeUndone AS LONG, BYVAL pwszText AS WSTRING PTR)
   DECLARE STATIC SUB RequestResize (BYVAL hRichEdit AS HWND)
   DECLARE STATIC FUNCTION Scroll (BYVAL hRichEdit AS HWND, BYVAL nAction AS LONG) AS LONG
   DECLARE STATIC SUB ScrollCaret (BYVAL hRichEdit AS HWND)
   DECLARE STATIC FUNCTION SelectionType (BYVAL hRichEdit AS HWND) AS LONG
   DECLARE STATIC FUNCTION SetAutoCorrectProc (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR) AS DWORD
   DECLARE STATIC SUB SetBidiOptions (BYVAL hRichEdit AS HWND, BYVAL pOptions AS BIDIOPTIONS PTR)
   DECLARE STATIC FUNCTION SetBkgndColor (BYVAL hRichEdit AS HWND, BYVAL pSysColor AS DWORD, BYVAL pBkColor AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetCharFormat (BYVAL hRichEdit AS HWND, BYVAL chfmt AS DWORD, BYVAL lpcf AS CHARFORMATW PTR) AS LONG
   DECLARE STATIC FUNCTION SetCTFModeBias (BYVAL hRichEdit AS HWND, BYVAL nModeBias AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetCTFOpenStatus (BYVAL hRichEdit AS HWND, BYVAL fTSFkbd AS LONG) AS DWORD
   DECLARE STATIC FUNCTION SetEditStyle (BYVAL hRichEdit AS HWND, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
   DECLARE STATIC FUNCTION SetEditStyleEx (BYVAL hRichEdit AS HWND, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
   DECLARE STATIC FUNCTION SetElipsisMode (BYVAL hRichEdit AS HWND, BYVAL fMode AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetEventMask (BYVAL hRichEdit AS HWND, BYVAL fMask AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetFontSize (BYVAL hRichEdit AS HWND, BYVAL ptsize AS LONG) AS LONG
   DECLARE STATIC SUB SetHyphenateInfo (BYVAL hRichEdit AS HWND, BYVAL phinfo AS HYPHENATEINFO PTR)
   DECLARE STATIC FUNCTION SetIMEColor (BYVAL hRichEdit AS HWND, BYVAL pcompcolor AS COMPCOLOR PTR) AS LONG
   DECLARE STATIC FUNCTION SetIMEModeBias (BYVAL hRichEdit AS HWND, BYVAL nModeBias AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetIMEOptions (BYVAL hRichEdit AS HWND, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetLangOptions (BYVAL hRichEdit AS HWND, BYVAL lgoptions AS LONG) AS DWORD
   DECLARE STATIC SUB SetLimitText (BYVAL hRichEdit AS HWND, BYVAL chMax AS DWORD)
   DECLARE STATIC SUB SetMargins (BYVAL hRichEdit AS HWND, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
   DECLARE STATIC SUB SetModify (BYVAL hRichEdit AS HWND, BYVAL fModify AS LONG)
   DECLARE STATIC FUNCTION SetOleCallback (BYVAL hRichEdit AS HWND, BYVAL pCallback AS ANY PTR) AS LONG
   DECLARE STATIC FUNCTION SetOptions (BYVAL hRichEdit AS HWND, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetPageRotate (BYVAL hRichEdit AS HWND, BYVAL txtlayout AS LONG) AS LONG
   DECLARE STATIC SUB SetPalette (BYVAL hRichEdit AS HWND, BYVAL newPalette AS HPALETTE)
   DECLARE STATIC FUNCTION SetParaFormat (BYVAL hRichEdit AS HWND, BYVAL pfmt AS PARAFORMAT PTR) AS LONG
   DECLARE STATIC SUB SetPasswordChar (BYVAL hRichEdit AS HWND, BYVAL dwchar AS DWORD)
   DECLARE STATIC FUNCTION SetPunctuation (BYVAL hRichEdit AS HWND, BYVAL punctype AS LONG, BYVAL ppunct AS PUNCTUATION PTR) AS LONG
   DECLARE STATIC FUNCTION SetReadOnly (BYVAL hRichEdit AS HWND, BYVAL fReadOnly AS LONG) AS LONG
   DECLARE STATIC SUB SetRect (BYVAL hRichEdit AS HWND, BYVAL fCoord AS LONG, BYVAL prect AS RECT PTR)
   DECLARE STATIC SUB SetRectNP (BYVAL hRichEdit AS HWND, BYVAL fCoord AS LONG, BYVAL prect AS RECT PTR)
   DECLARE STATIC FUNCTION SetScrollPos (BYVAL hRichEdit AS HWND, BYVAL pt AS POINT PTR) AS DWORD
   DECLARE STATIC SUB SetSel (BYVAL hRichEdit AS HWND, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
   DECLARE STATIC FUNCTION SetStoryType (BYVAL hRichEdit AS HWND, BYVAL Index AS LONG, BYVAL dwType AS DWORD) AS DWORD
   DECLARE STATIC FUNCTION SetTableParams (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
   DECLARE STATIC FUNCTION SetTabStops (BYVAL hRichEdit AS HWND, BYVAL nTabs AS LONG, BYVAL rgTabStops AS LONG_PTR) AS LONG
   DECLARE STATIC FUNCTION SetTargetDevice (BYVAL hRichEdit AS HWND, BYVAL hDC AS HDC, BYVAL lnwidth AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetText (BYVAL hRichEdit AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION SetTextExW (BYVAL hRichEdit AS HWND, BYVAL pstex AS SETTEXTEX PTR, BYVAL pwszText AS WSTRING PTR) AS DWORD
   DECLARE STATIC FUNCTION SetTextMode (BYVAL hRichEdit AS HWND, BYVAL pvalues AS LONG) AS LONG
   DECLARE STATIC SUB SetTouchOptions (BYVAL hRichEdit AS HWND, BYVAL Options AS LONG, BYVAL fEnable AS LONG)
   DECLARE STATIC FUNCTION SetTypographyOptions (BYVAL hRichEdit AS HWND, BYVAL pto AS LONG, BYVAL fMask AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetUIAName (BYVAL hRichEdit AS HWND, BYVAL pwszName AS WSTRING PTR) AS DWORD
   DECLARE STATIC FUNCTION SetUndoLimit (BYVAL hRichEdit AS HWND, BYVAL maxactions AS DWORD) AS DWORD
   DECLARE STATIC SUB SetWordBreakProc (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR)
   DECLARE STATIC FUNCTION SetWordBreakProcEx (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR) AS LONG_PTR
   DECLARE STATIC FUNCTION SetWordWrapMode (BYVAL hRichEdit AS HWND, BYVAL pvalues AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetZoom (BYVAL hRichEdit AS HWND, BYVAL zNum AS DWORD, BYVAL zDen AS DWORD) AS LONG
   DECLARE STATIC SUB ShowScrollBar (BYVAL hRichEdit AS HWND, BYVAL nScrollBar AS DWORD, BYVAL fShow AS LONG)
   DECLARE STATIC FUNCTION StopGroupTyping (BYVAL hRichEdit AS HWND) AS DWORD
   DECLARE STATIC FUNCTION StreamIn (BYVAL hRichEdit AS HWND, BYVAL psf AS LONG, BYVAL pedst AS EDITSTREAM PTR) AS DWORD
   DECLARE STATIC FUNCTION StreamOut (BYVAL hRichEdit AS HWND, BYVAL psf AS LONG, BYVAL pedst AS EDITSTREAM PTR) AS DWORD
   DECLARE STATIC FUNCTION Undo (BYVAL hRichEdit AS HWND) AS LONG
   '  // Helper functions
   DECLARE STATIC FUNCTION EnumFontFamProcW (BYVAL lpelf AS ENUMLOGFONTW PTR, BYVAL lpntm AS NEWTEXTMETRICW PTR, _
           BYVAL FontType AS LONG, BYVAL lplf AS LOGFONTW PTR) AS LONG
   DECLARE STATIC FUNCTION SetFont (BYVAL hRichEdit AS HWND, BYREF wszFaceName AS WSTRING, BYVAL ptsize AS LONG) AS LRESULT
   DECLARE STATIC FUNCTION LoadRtfFromFileCallback (BYVAL hFile AS HANDLE, BYVAL lpBuff AS BYTE PTR, BYVAL cb AS LONG, BYVAL pcb AS LONG PTR) AS UINT
   DECLARE STATIC FUNCTION LoadRtfFromFile (BYVAL hRichEdit AS HWND, BYREF wszFileName AS WSTRING) AS BOOLEAN
   DECLARE STATIC FUNCTION LoadRtfFromResourceCallback (BYVAL pCustData AS AFX_RICHEDIT_CUSTOMDATA PTR, BYVAL lpBuff AS BYTE PTR, _
           BYVAL cb AS LONG, BYVAL pcb AS LONG PTR) AS DWORD
   DECLARE STATIC FUNCTION LoadRtfFromResource (BYVAL hRichEdit AS HWND, BYVAL hInstance AS HINSTANCE, BYREF wszResourceName AS WSTRING) AS BOOLEAN
   DECLARE STATIC FUNCTION GetTextCallback (BYVAL dwCookie AS DWORD_PTR, BYVAL pbBuff AS BYTE PTR, BYVAL cb AS LONG, BYVAL pcb AS LONG PTR) AS DWORD
   DECLARE STATIC FUNCTION GetRtfText (BYVAL hRichEdit AS HWND) AS STRING

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CRichEdit
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CRichEdit
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Enables or disables automatic detection of URLs by a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.AutoUrlDetect (BYVAL hRichEdit AS HWND, BYVAL fUrlDetect AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_AUTOURLDETECT, fUrlDetect, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calls the autocorrect callback function that is stored by the **CRichEdit.SetAutocorrectProc**
' message, provided that the text preceding the insertion point is a candidate for autocorrection.
' ========================================================================================
FUNCTION CRichEdit.CallAutocorrectProc (BYVAL hRichEdit AS HWND, BYVAL char AS WCHAR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_CALLAUTOCORRECTPROC, char, 0)
END FUNCTION

' ========================================================================================
' Determines whether a rich edit control can paste a specified clipboard format.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.CanPaste (BYVAL hRichEdit AS HWND, BYVAL clipformat AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_CANPASTE, clipformat, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether there are any actions in the control redo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.CanRedo (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_CANREDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether there are any actions in an edit control's undo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.CanUndo (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_CANUNDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about the character closest to a specified point in the client area of
' an edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.CharFromPos (BYVAL hRichEdit AS HWND, BYVAL lppl AS POINTL PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_CHARFROMPOS, 0, cast(LPARAM, lppl))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays a portion of the contents of a rich edit control, as previously formatted for a
' device using the EM_FORMATRANGE message.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.DisplayBand (BYVAL hRichEdit AS HWND, BYVAL lprc AS RECT PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_DISPLAYBAND, 0, cast(LPARAM, lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resets the undo flag of a rich edit control. The undo flag is set whenever an operation
' within the rich edit control can be undone.
' ========================================================================================
PRIVATE SUB CRichEdit.EmptyUndoBuffer (BYVAL hRichEdit AS HWND)
   SendMessageW hRichEdit, EM_EMPTYUNDOBUFFER, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the starting and ending character positions of the selection in a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.ExGetSel (BYVAL hRichEdit AS HWND, BYVAL lpchr AS CHARRANGE PTR)
   SendMessageW hRichEdit, EM_EXGETSEL, 0, cast(LPARAM, lpchr)
END SUB
' ========================================================================================

' ========================================================================================
' Sets an upper limit to the amount of text the user can type or paste into a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.ExLimitText (BYVAL hRichEdit AS HWND, BYVAL dwLimit AS DWORD)
   SendMessageW hRichEdit, EM_EXLIMITTEXT, 0, dwLimit
END SUB
' ========================================================================================

' ========================================================================================
' Determines which line contains the specified character in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.ExLineFromChar (BYVAL hRichEdit AS HWND, BYVAL iIndex AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_EXLINEFROMCHAR, 0, iIndex)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a range of characters and/or Component Object Model (COM) objects in a Microsoft
' Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.ExSetSel (BYVAL hRichEdit AS HWND, BYVAL lpcr AS CHARRANGE PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_EXSETSEL, 0, cast(LPARAM, lpcr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds text within a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.FindText (BYVAL hRichEdit AS HWND, BYVAL fOptions AS DWORD, BYVAL lpft AS FINDTEXTW PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_FINDTEXTW, fOptions, cast(LPARAM, lpft))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds text within a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.FindTextEx (BYVAL hRichEdit AS HWND, BYVAL fOptions AS DWORD, BYVAL lpftexw AS FINDTEXTEXW PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_FINDTEXTEXW, fOptions, cast(LPARAM, lpftexw))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds the next word break before or after the specified character position or retrieves
' information about the character at that position.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.FindWordBreak (BYVAL hRichEdit AS HWND, BYVAL fOperation AS DWORD, BYVAL dwStartPos AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_FINDWORDBREAK, fOperation, dwStartPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Formats a range of text in a rich edit control for a specific device.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.FormatRange (BYVAL hRichEdit AS HWND, BYVAL fRender AS LONG, BYVAL lpfr AS ..FORMATRANGE PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_FORMATRANGE, fRender, cast(LPARAM, lpfr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a pointer to the application-defined AutoCorrectProc callback function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetAutoCorrectProc (BYVAL hRichEdit AS HWND) AS LONG_PTR
   FUNCTION = SendMessageW(hRichEdit, EM_GETAUTOCORRECTPROC, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the auto URL detection is turned on in the rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetAutoUrlDetect (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETAUTOURLDETECT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates the current state of the bidirectional options in the rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.GetBidiOptions (BYVAL hRichEdit AS HWND, BYVAL lpbo AS BIDIOPTIONS PTR)
   SendMessageW hRichEdit, EM_GETBIDIOPTIONS, 0, cast(LPARAM, lpbo)
END SUB
' ========================================================================================

' ========================================================================================
' Determines the current character formatting in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetCharFormat (BYVAL hRichEdit AS HWND, BYVAL fOption AS DWORD, BYVAL lpcf AS CHARFORMATW PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETCHARFORMAT, fOption, cast(LPARAM, lpcf))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Text Services Framework mode bias values for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetCTFModeBias (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETCTFMODEBIAS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if the Text Services Framework (TSF) keyboard is open or closed.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetCTFOpenStatus (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETCTFOPENSTATUS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current edit style flags.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetEditStyle (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETEDITSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the extended edit style flags.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetEditStyleEx (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETEDITSTYLEEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current ellipsis mode.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetEllipsisMode (BYVAL hRichEdit AS HWND, BYVAL pmode AS DWORD PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETELLIPSISMODE, 0, cast(LPARAM, pMode))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current ellipsis mode.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetEllipsisState (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETELLIPSISSTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the event mask for a rich edit control. The event mask specifies which
' notification messages the control sends to its parent window.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetEventMask (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETEVENTMASK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the zero-based index of the uppermost visible line in a multiline rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetFirstVisibleLine (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETFIRSTVISIBLELINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about hyphenation for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.GetHyphenateInfo (BYVAL hRichEdit AS HWND, BYVAL lphi AS HYPHENATEINFO PTR)
   SendMessageW hRichEdit, EM_GETHYPHENATEINFO, cast(WPARAM, lphi), 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the Input Method Editor (IME) composition color. This message is available
' only in Asian-language versions of the operating system.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetIMEColor (BYVAL hRichEdit AS HWND, BYVAL rgCmpclr AS COMPCOLOR PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETIMECOLOR, 0, cast(LPARAM, rgCmpclr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current IME mode for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetIMECompMode (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETIMECOMPMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Input Method Editor (IME) composition text.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetIMECompText (BYVAL hRichEdit AS HWND, BYVAL lpict AS IMECOMPTEXT PTR, BYVAL buffer AS ANY PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETIMECOMPTEXT, cast(WPARAM, lpict), cast(LPARAM, buffer))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetIMEModeBias (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETIMEMODEBIAS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current Input Method Editor (IME) options. This message is available only
' in Asian-language versions of the operating system.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetIMEOptions (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETIMEOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the property and capabilities of the Input Method Editor (IME) associated with the
' current input locale.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetIMEProperty (BYVAL hRichEdit AS HWND, BYVAL figp AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETIMEPROPERTY, figp, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a rich edit control's option settings for Input Method Editor (IME) and Asian
' language support.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetLangOptions (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETLANGOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current text limit for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetLimitText (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETLIMITTEXT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies a line of text from a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetLine (BYVAL hRichEdit AS HWND, BYVAL which AS DWORD) AS DWSTRING
   DIM buffer AS DWSTRING = MKI(32765) + STRING(32765, 0)
   DIM n AS LONG = SendMessageW(hRichEdit, EM_GETLINE, which, cast(LPARAM, *buffer))
   RETURN LEFT(buffer, n)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of lines in a multiline rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetLineCount (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETLINECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of a rich edit control's modification flag. The flag indicates whether
' the contents of the rich edit control have been modified.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetModify (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETMODIFY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves an IRichEditOle object that a client can use to access a rich edit control's
' Component Object Model (COM) functionality.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetOleInterface (BYVAL hRichEdit AS HWND, BYVAL ppObject AS IUnknown PTR PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETOLEINTERFACE, 0, cast(LPARAM, ppObject))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves rich edit control options.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetOptions (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deprecated. Gets the text layout for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetPageRotate (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETPAGEROTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the paragraph formatting of the current selection in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetParaFormat (BYVAL hRichEdit AS HWND, BYVAL pParaFmt AS PARAFORMAT PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETPARAFORMAT, 0, cast(LPARAM, pParaFmt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the password character that a rich edit control displays when the user enters text.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetPasswordChar (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETPASSWORDCHAR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current punctuation characters for the rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetPunctuation (BYVAL hRichEdit AS HWND, BYVAL punctype AS DWORD, BYVAL lppunct AS PUNCTUATION PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETPUNCTUATION, punctype, cast(LPARAM, lppunct))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the formatting rectangle of a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.GetRect (BYVAL hRichEdit AS HWND, BYVAL prc AS RECT PTR)
   SendMessageW hRichEdit, EM_GETRECT, 0, cast(LPARAM, prc)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the type of the next action, if any, in the control's redo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetRedoName (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETREDONAME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Obtains the current scroll position of the edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetScrollPos (BYVAL hRichEdit AS HWND, BYVAL lppt AS POINT PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETSCROLLPOS, 0, cast(LPARAM, lppt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the starting and ending character positions of the current selection in a rich
' edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetSel (BYVAL hRichEdit AS HWND, BYVAL pdwStartPos AS DWORD PTR, BYVAL pdwEndPos AS DWORD PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETSEL, cast(WPARAM, pdwStartPos), cast(LPARAM, pdwEndPos))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the currently selected text in a rich edit control.
' Note: From version 4.1 (RichEdit50W class in MSFTEDIT.DLL), Windows XP, EM_GETSELTEXT
' returns the text in unicode.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetSelText (BYVAL hRichEdit AS HWND) AS DWSTRING
   DIM dwStartPos AS DWORD, dwEndPos AS DWORD, cr AS CHARRANGE
   SendMessageW(hRichEdit, EM_EXGETSEL, 0, cast(LPARAM, @cr))
   DIM cbLen AS DWORD = cr.cpMax - cr.cpMin
   IF cbLen < 1 THEN RETURN ""
   DIM dwsText AS DWSTRING = WSPACE(cbLen + 1)
   cbLen = SendMessageW(hRichEdit, EM_GETSELTEXT, 0, cast(LPARAM, *dwsText))
   RETURN LEFT(dwsText, cbLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the story type.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetStoryTpe (BYVAL hRichEdit AS HWND, BYVAL Index AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETSTORYTYPE, Index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the table parameters for a table row and the cell parameters for the specified number of cells.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTableParams (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETTABLEPARMS, cast(WPARAM, lptp), cast(LPARAM, lptcp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text from a rich edit control.
' Note: GetWindowText cannot retrieve the text of a control in another application.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetText (BYVAL hRichEdit AS HWND) AS DWSTRING
   DIM cbLen AS DWORD = SendMessageW(hRichEdit, WM_GETTEXTLENGTH, 0, 0)
   IF cbLen < 1 THEN RETURN ""
   DIM dwsText AS DWSTRING = WSPACE(cbLen + 1)
   cbLen = SendMessageW(hRichEdit, WM_GETTEXT, cbLen + 1, cast(LPARAM, *dwsText))
   RETURN LEFT(dwsText, cbLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets all of the text from the rich edit control in any particular code base you want.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTextEx (BYVAL hRichEdit AS HWND, BYVAL lpgtex AS ..GETTEXTEX PTR, BYVAL buffer AS ANY PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETTEXTEX, cast(WPARAM, lpgtex), cast(LPARAM, buffer))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of all text in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTextLength (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates text length in various ways. It is usually called before creating a buffer to
' receive the text from the control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTextLengthEx (BYVAL hRichEdit AS HWND, BYVAL lpgtex AS ..GETTEXTLENGTHEX PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETTEXTLENGTHEX, cast(WPARAM, lpgtex), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current text mode and undo level of a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTextMode (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETTEXTMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a specified range of characters from a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTextRange (BYVAL hRichEdit AS HWND, BYVAL lptrg AS TEXTRANGEW PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETTEXTRANGE, 0, cast(LPARAM, lptrg))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of the scroll box (thumb) in the vertical scroll bar of a multiline
' rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetThumb (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETTHUMB, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the touch options that are associated with a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTouchOptions (BYVAL hRichEdit AS HWND, BYVAL Options AS LONG PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETTOUCHOPTIONS, cast(WPARAM, Options), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current state of the typography options of a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTypographyOptions (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETTYPOGRAPHYOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of the next undo action, if any.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetUndoName (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETUNDONAME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the address of the current Wordwrap function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetWordBreakProc (BYVAL hRichEdit AS HWND) AS LONG_PTR
   FUNCTION = SendMessageW(hRichEdit, EM_GETWORDBREAKPROC, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the address of the currently registered extended word-break procedure.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetWordBreakProcEx (BYVAL hRichEdit AS HWND) AS LONG_PTR
   FUNCTION = SendMessageW(hRichEdit, EM_GETWORDBREAKPROCEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current word wrap and word-break options for the rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetWordWrapMode (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_GETWORDWRAPMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current zoom ratio, which is always between 1/64 and 64.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetZoom (BYVAL hRichEdit AS HWND, BYVAL pzNum AS DWORD PTR, BYVAL pzDen AS DWORD PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETZOOM, cast(WPARAM, pzNum), cast(LPARAM, pzDen))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Hides or shows the selection in a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.HideSelection (BYVAL hRichEdit AS HWND, BYVAL fHide AS DWORD)
   SendMessageW hRichEdit, EM_HIDESELECTION, fHide, 0
END SUB
' ========================================================================================

' ========================================================================================
' Replaces the selection with a blob that displays an image.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.InsertImage (BYVAL hRichEdit AS HWND, BYVAL lpip AS RICHEDIT_IMAGE_PARAMETERS PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_INSERTIMAGE, 0, cast(LPARAM, lpip))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts one or more identical table rows with empty cells.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.InsertTable (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_INSERTTABLE, cast(WPARAM, lptp), cast(LPARAM, lptcp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if current input locale is an East Asian locale.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.IsIME (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_ISIME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text limit of a rich edit control. The text limit is the maximum amount of text,
' in TCHARs, that the user can type into the edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.LimitText (BYVAL hRichEdit AS HWND, BYVAL chMax AS DWORD)
   SendMessageW hRichEdit, EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gets the index of the line that contains the specified character index in a multiline
' rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.LineFromChar (BYVAL hRichEdit AS HWND, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_LINEFROMCHAR, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the character index of the first character of a specified line in a multiline
' rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.LineIndex (BYVAL hRichEdit AS HWND, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_LINEINDEX, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length, in characters, of a line in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.LineLength (BYVAL hRichEdit AS HWND, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_LINELENGTH, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the text in a multiline rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.LineScroll (BYVAL hRichEdit AS HWND, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_LINESCROLL, 0, y)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Pastes a specific clipboard format in a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.PasteSpecial (BYVAL hRichEdit AS HWND, BYVAL clpfmt AS DWORD, BYVAL lprps AS REPASTESPECIAL PTR)
   SendMessageW hRichEdit, EM_PASTESPECIAL, clpfmt, cast(LPARAM, lprps)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the client area coordinates of a specified character in a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.PosFromChar (BYVAL hRichEdit AS HWND, BYVAL pt AS POINTL PTR, BYVAL index as DWORD)
   SendMessageW(hRichEdit, EM_POSFROMCHAR, cast(WPARAM, pt), index)
END SUB
' ========================================================================================

' ========================================================================================
' Invokes the Input Method Editor (IME) reconversion dialog box.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.Reconversion (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_RECONVERSION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Redoes the next action in the control's redo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.Redo (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_REDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces the current selection in a rich edit control with the specified text.
' ========================================================================================
PRIVATE SUB CRichEdit.ReplaceSel (BYVAL hRichEdit AS HWND, BYVAL bCanBeUndone AS LONG, BYVAL pwszText AS WSTRING PTR)
   SendMessageW hRichEdit, EM_REPLACESEL, bCanBeUndone, cast(LPARAM, pwszText)
END SUB
' ========================================================================================

' ========================================================================================
' Forces a rich edit control to send an EN_REQUESTRESIZE notification message to its
' parent window.
' ========================================================================================
PRIVATE SUB CRichEdit.RequestResize (BYVAL hRichEdit AS HWND)
   SendMessageW hRichEdit, EM_REQUESTRESIZE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Scrolls the text vertically in a multiline rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.Scroll (BYVAL hRichEdit AS HWND, BYVAL nAction AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SCROLL, nAction, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the caret into view in a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.ScrollCaret (BYVAL hRichEdit AS HWND)
   SendMessageW hRichEdit, EM_SCROLLCARET, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Determines the selection type for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SelectionType (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SELECTIONTYPE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a pointer to the application-defined AutoCorrectProc callback procedure.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetAutoCorrectProc (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETAUTOCORRECTPROC, 0, cast(LPARAM, pfn))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current state of the bidirectional options in the rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.SetBidiOptions (BYVAL hRichEdit AS HWND, BYVAL pOptions AS BIDIOPTIONS PTR)
   SendMessageW(hRichEdit, EM_SETBIDIOPTIONS, 0, cast(LPARAM, pOptions))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the background color for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetBkgndColor (BYVAL hRichEdit AS HWND, BYVAL pSysColor AS DWORD, BYVAL pBkColor AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETBKGNDCOLOR, pSysColor, pBkColor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets character formatting in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetCharFormat (BYVAL hRichEdit AS HWND, BYVAL chfmt AS DWORD, BYVAL lpcf AS CHARFORMATW PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETCHARFORMAT, chfmt, cast (LPARAM, lpcf))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Text Services Framework (TSF) mode bias for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetCTFModeBias (BYVAL hRichEdit AS HWND, BYVAL nModeBias AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETCTFMODEBIAS, nModeBias, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Opens or closes the Text Services Framework (TSF) keyboard.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetCTFOpenStatus (BYVAL hRichEdit AS HWND, BYVAL fTSFkbd AS LONG) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETCTFOPENSTATUS, fTSFkbd, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current edit style flags.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetEditStyle (BYVAL hRichEdit AS HWND, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETEDITSTYLE, fStyle, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current extended edit style flags.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetEditStyleEx (BYVAL hRichEdit AS HWND, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETEDITSTYLEEX, fStyle, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current extended edit style flags.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetElipsisMode (BYVAL hRichEdit AS HWND, BYVAL fMode AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETELLIPSISMODE, 0, fMode)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the event mask for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetEventMask (BYVAL hRichEdit AS HWND, BYVAL fMask AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETEVENTMASK, 0, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font size for the selected text.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetFontSize (BYVAL hRichEdit AS HWND, BYVAL ptsize AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETFONTSIZE, ptsize, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the way a Microsoft Rich Edit control does hyphenation.
' ========================================================================================
PRIVATE SUB CRichEdit.SetHyphenateInfo (BYVAL hRichEdit AS HWND, BYVAL phinfo AS HYPHENATEINFO PTR)
   SendMessageW hRichEdit, EM_SETHYPHENATEINFO, cast(WPARAM, phinfo), 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Input Method Editor (IME) composition color.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetIMEColor (BYVAL hRichEdit AS HWND, BYVAL pcompcolor AS COMPCOLOR PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETIMECOLOR, 0, cast(LPARAM, pcompcolor))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetIMEModeBias (BYVAL hRichEdit AS HWND, BYVAL nModeBias AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit,EM_SETIMEMODEBIAS, nModeBias, nModeBias)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Input Method Editor (IME) options.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetIMEOptions (BYVAL hRichEdit AS HWND, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETIMEOPTIONS, fCoop, fOptions)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets options for Input Method Editor (IME) and Asian language support in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetLangOptions (BYVAL hRichEdit AS HWND, BYVAL lgoptions AS LONG) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETLANGOPTIONS, 0, lgoptions)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text limit of a rich edit control. The text limit is the maximum amount of
' text, in TCHARs, that the user can type into the edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.SetLimitText (BYVAL hRichEdit AS HWND, BYVAL chMax AS DWORD)
   SendMessageW hRichEdit, EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the widths of the left and right margins for a rich edit control. The message
' redraws the control to reflect the new margins.
' ========================================================================================
PRIVATE SUB CRichEdit.SetMargins (BYVAL hRichEdit AS HWND, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
   SendMessageW(hRichEdit, EM_SETMARGINS, nMargins, nWidth)
END SUB
' ========================================================================================

' ========================================================================================
' Sets or clears the modification flag for a rich edit control. The modification flag
' indicates whether the text within the rich edit control has been modified.
' ========================================================================================
PRIVATE SUB CRichEdit.SetModify (BYVAL hRichEdit AS HWND, BYVAL fModify AS LONG)
   SendMessageW hRichEdit, EM_SETMODIFY, fModify, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gives a rich edit control an IRichEditOleCallback object that the control uses to get
' OLE-related resources and information from the client.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetOleCallback (BYVAL hRichEdit AS HWND, BYVAL pCallback AS ANY PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETOLECALLBACK, 0, cast(LPARAM, pCallback))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the options for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetOptions (BYVAL hRichEdit AS HWND, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETOPTIONS, fCoop, fOptions)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deprecated. Sets the text layout for a Microsoft Rich Edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetPageRotate (BYVAL hRichEdit AS HWND, BYVAL txtlayout AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETPAGEROTATE, txtlayout, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the palette that a rich edit control uses for its display window.
' ========================================================================================
PRIVATE SUB CRichEdit.SetPalette (BYVAL hRichEdit AS HWND, BYVAL newPalette AS HPALETTE)
   SendMessageW hRichEdit, EM_SETPALETTE, cast(WPARAM, newPalette), 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the paragraph formatting for the current selection in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetParaFormat (BYVAL hRichEdit AS HWND, BYVAL pfmt AS PARAFORMAT PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETPARAFORMAT, 0, cast(LPARAM, pfmt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets or removes the password character for a rich edit control. When a password
' character is set, that character is displayed in place of the characters typed by the user.
' ========================================================================================
PRIVATE SUB CRichEdit.SetPasswordChar (BYVAL hRichEdit AS HWND, BYVAL dwchar AS DWORD)
   SendMessageW hRichEdit, EM_SETPASSWORDCHAR, dwchar, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the punctuation characters for a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetPunctuation (BYVAL hRichEdit AS HWND, BYVAL punctype AS LONG, BYVAL ppunct AS PUNCTUATION PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETPUNCTUATION, punctype, cast(LPARAM, ppunct))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets or removes the read-only style (ES_READONLY) of a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetReadOnly (BYVAL hRichEdit AS HWND, BYVAL fReadOnly AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETREADONLY, fReadOnly, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.SetRect (BYVAL hRichEdit AS HWND, BYVAL fCoord AS LONG, BYVAL prect AS RECT PTR)
   SendMessageW hRichEdit, EM_SETRECT, fCoord, cast(LPARAM, prect)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.SetRectNP (BYVAL hRichEdit AS HWND, BYVAL fCoord AS LONG, BYVAL prect AS RECT PTR)
   SendMessageW hRichEdit, EM_SETRECTNP, fCoord, cast(LPARAM, prect)
END SUB
' ========================================================================================

' ========================================================================================
' Tells the rich edit control to scroll to a particular point.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetScrollPos (BYVAL hRichEdit AS HWND, BYVAL pt AS POINT PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETSCROLLPOS, 0, cast(LPARAM, pt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a range of characters in a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.SetSel (BYVAL hRichEdit AS HWND, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
   SendMessageW hRichEdit, EM_SETSEL, nStart, nEnd
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetStoryType (BYVAL hRichEdit AS HWND, BYVAL Index AS LONG, BYVAL dwType AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETSTORYTYPE, Index, dwType)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the parameters of rows in a table.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetTableParams (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETTABLEPARMS, cast(WPARAM, lptp), cast(LPARAM, lptcp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the tab stops in a multiline rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetTabStops (BYVAL hRichEdit AS HWND, BYVAL nTabs AS LONG, BYVAL rgTabStops AS LONG_PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETTABSTOPS, nTabs, cast(LPARAM, rgTabStops))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the target device and line width used for WYSIWYG formatting in a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetTargetDevice (BYVAL hRichEdit AS HWND, BYVAL hDC AS HDC, BYVAL lnwidth AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETTARGETDEVICE, cast(WPARAM, hDC), lnwidth)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of an edit control.
' Note: SetWindowText cannot change the text of a control in another application.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetText (BYVAL hRichEdit AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   FUNCTION = SendMessageW(hRichEdit, WM_SETTEXT, 0, cast(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Combines the functionality of WM_SETTEXT and EM_REPLACESEL and adds the ability to set
' text using a code page and to use either Rich Text Format (RTF) rich text or plain text.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetTextExW (BYVAL hRichEdit AS HWND, BYVAL pstex AS SETTEXTEX PTR, BYVAL pwszText AS WSTRING PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETTEXTEX, cast(WPARAM, pstex), cast(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text mode or undo level of a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetTextMode (BYVAL hRichEdit AS HWND, BYVAL pvalues AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETTEXTMODE, 0, pvalues)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the touch options associated with a rich edit control.
' ========================================================================================
PRIVATE SUB CRichEdit.SetTouchOptions (BYVAL hRichEdit AS HWND, BYVAL Options AS LONG, BYVAL fEnable AS LONG)
   SendMessageW(hRichEdit, EM_SETTOUCHOPTIONS, Options, fEnable)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the current state of the typography options of a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetTypographyOptions (BYVAL hRichEdit AS HWND, BYVAL pto AS LONG, BYVAL fMask AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETTYPOGRAPHYOPTIONS, pto, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum number of actions that can stored in the undo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetUIAName (BYVAL hRichEdit AS HWND, BYVAL pwszName AS WSTRING PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETUIANAME, 0, cast(LPARAM, pwszName))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum number of actions that can stored in the undo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetUndoLimit (BYVAL hRichEdit AS HWND, BYVAL maxactions AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_SETUNDOLIMIT, maxactions, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces a rich edit control's default Wordwrap function with an application-defined Wordwrap function.
' ========================================================================================
PRIVATE SUB CRichEdit.SetWordBreakProc (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR)
   SendMessageW(hRichEdit, EM_SETWORDBREAKPROC, 0, cast(LPARAM, pfn))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the extended word-break procedure.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetWordBreakProcEx (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR) AS LONG_PTR
   FUNCTION = SendMessageW(hRichEdit, EM_SETWORDBREAKPROCEX, 0, cast(LPARAM, pfn))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the word-wrapping and word-breaking options for the rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetWordWrapMode (BYVAL hRichEdit AS HWND, BYVAL pvalues AS LONG) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETWORDWRAPMODE, pvalues, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the zoom ratio anywhere between 1/64 and 64.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetZoom (BYVAL hRichEdit AS HWND, BYVAL zNum AS DWORD, BYVAL zDen AS DWORD) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_SETZOOM, zNum, zDen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows or hides one of the scroll bars in the Text Host window.
' ========================================================================================
PRIVATE SUB CRichEdit.ShowScrollBar (BYVAL hRichEdit AS HWND, BYVAL nScrollBar AS DWORD, BYVAL fShow AS LONG)
   SendMessageW hRichEdit, EM_SHOWSCROLLBAR, nScrollBar, fShow
END SUB
' ========================================================================================

' ========================================================================================
' Stops the control from collecting additional typing actions into the current undo action.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.StopGroupTyping (BYVAL hRichEdit AS HWND) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_STOPGROUPTYPING, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces the contents of a rich edit control with a stream of data provided by an
' application defined EditStreamCallback callback function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.StreamIn (BYVAL hRichEdit AS HWND, BYVAL psf AS LONG, BYVAL pedst AS EDITSTREAM PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_STREAMIN, psf, cast(LPARAM, pedst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Causes a rich edit control to pass its contents to an application defined
' EditStreamCallback callback function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.StreamOut (BYVAL hRichEdit AS HWND, BYVAL psf AS LONG, BYVAL pedst AS EDITSTREAM PTR) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_STREAMOUT, psf, cast(LPARAM, pedst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' This message undoes the last edit control operation in the control's undo queue.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.Undo (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_UNDO, 0, 0)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                          H E L P E R    F U N C T I O N S
' ########################################################################################

' ========================================================================================
' Enumerates font families. Used by the CRichEdit.SetFontW function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.EnumFontFamProcW ( _
   BYVAL lpelf    AS ENUMLOGFONTW PTR, _     ' // Address of ENUMLOGFONT structure
   BYVAL lpntm    AS NEWTEXTMETRICW PTR, _   ' // Address of NEWTEXTMETRIC structure
   BYVAL FontType AS LONG, _                 ' // Font type
   BYVAL lplf     AS LOGFONTW PTR _          ' // Address of LOGFONT struct
   ) AS LONG

   lplf->lfCharSet        = lpelf->elfLogFont.lfCharSet
   lplf->lfPitchAndFamily = lpelf->elfLogFont.lfPitchAndFamily
   lplf->lfFaceName       = lpelf->elfLogFont.lfFaceName

   FUNCTION = FALSE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font used by a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.SetFont ( _
   BYVAL hRichEdit AS HWND, _             ' // Handle to the RichEdit control
   BYREF wszFaceName AS WSTRING, _        ' // Font name
   BYVAL ptsize AS LONG _                 ' // Font size in points
   ) AS LRESULT

   DIM lResult AS LRESULT                 ' // Result code
   DIM hDC AS HDC                         ' // Handle of the device context
   DIM tlf AS LOGFONTW                    ' // LOGFONT structure
   DIM tcf AS CHARFORMATW                 ' // CHARFORMATW structure

   hDC = GetDC(NULL)
   EnumFontFamiliesW(hDC, wszFaceName, cast(FONTENUMPROCW, @CRichEdit.EnumFontFamProcW), cast(LPARAM, @tlf))
   ReleaseDC NULL, hDC
   tcf.cbSize = SIZEOF(tcf)
   tcf.dwMask = CFM_BOLD OR CFM_ITALIC OR CFM_UNDERLINE OR CFM_STRIKEOUT OR _
                CFM_FACE OR CFM_CHARSET OR CFM_SIZE
   tcf.yHeight = ptsize * 20   ' // Expects it in 20ths of a point
   tcf.bCharSet = tlf.lfCharSet
   tcf.bPitchAndFamily = tlf.lfPitchAndFamily
   tcf.szFaceName = tlf.lfFaceName
   lResult = SendMessageW(hRichEdit, EM_SETCHARFORMAT, SCF_ALL, cast(LPARAM, @tcf))
   ' // Specify which notifications the control sends to its parent window
   IF lResult <> 0 THEN lResult = SendMessageW(hRichEdit, EM_SETEVENTMASK, 0, ENM_CHANGE)
   FUNCTION = lResult

END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback function used by the CRichEdit.LoadRtfFromFileW function.
' Transfers a stream of data into a rich edit control.
' ========================================================================================
FUNCTION CRichEdit.LoadRtfFromFileCallback ( _
   BYVAL hFile AS HANDLE _                  ' // Value of the dwCookie member of the EDITSTREAM structure.
 , BYVAL lpBuff AS BYTE PTR _               ' // Pointer to a buffer to write to
 , BYVAL cb AS LONG _                       ' // Maximum number of bytes to read
 , BYVAL pcb AS LONG PTR _                  ' // Number of bytes actually read
 ) AS UINT                                  ' // 0 for success, or an error code

   IF ReadFile(hFile, lpBuff, cb, pcb, NULL) = 0 THEN FUNCTION = GetLastError

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CRichEdit.LoadRtfFromFile ( _
   BYVAL hRichEdit AS HWND _                ' // Handle of the Rich Edit control
 , BYREF wszFileName AS WSTRING _           ' // Name of the file to load
 ) AS BOOLEAN                               ' // TRUE or FALSE

   DIM hFile AS HANDLE                      ' // File handle
   DIM eds AS EDITSTREAM                    ' // EDITSTREAM structure

   ' // Checks the validity of the parameters
   IF hRichEdit = 0 THEN EXIT FUNCTION
   IF LEN(wszFileName) = 0 THEN EXIT FUNCTION

   ' // Opens the file and sends the message
   hFile = CreateFileW(wszFileName, GENERIC_READ, FILE_SHARE_READ, _
                       NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   eds.dwCookie = cast(DWORD_PTR, hFile)
   eds.pfnCallback = cast(EDITSTREAMCALLBACK, @CRichEdit.LoadRtfFromFileCallback)
   IF SendMessageW(hRichEdit, EM_STREAMIN, SF_RTF, cast(LPARAM, @eds)) > 0 AND eds.dwError = 0 THEN FUNCTION = TRUE
   CloseHandle hFile

END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback function used by the CRichEdit.LoadRtfFromResourceW function.
' Transfers a stream of data into a rich edit control.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.LoadRtfFromResourceCallback ( _
   BYVAL pCustData AS AFX_RICHEDIT_CUSTOMDATA PTR _   ' // Value of the dwCookie member of the EDITSTREAM structure.
 , BYVAL lpBuff AS BYTE PTR _                         ' // Pointer to a buffer to write to.
 , BYVAL cb AS LONG _                                 ' // Number of bytes to write.
 , BYVAL pcb AS LONG PTR _                            ' // Number of bytes actually written.
 ) AS DWORD                                           ' // 0 for success, or an error code

   DIM nBytes AS LONG
   IF pCustData->nLen - pCustData->curPos > cb THEN nBytes = cb ELSE nBytes = pCustData->nLen - pCustData->curPos
   IF nBytes THEN
      CopyMemory(lpBuff, pCustData->pData + pCustData->curPos, nBytes)
      pCustData->curPos = pCustData->curPos + nBytes
      FUNCTION = 0
   ELSE
      FUNCTION = 1
   END IF
   *pcb = nBytes

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a RTF resource file into a Rich Edit control.
' The EM_STREAMIN message replaces the contents of a rich edit control with a stream of
' data provided by an application defined EditStreamCallback callback function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.LoadRtfFromResource ( _
   BYVAL hRichEdit AS HWND _                ' // Handle of the Rich Edit control
 , BYVAL hInstance AS HINSTANCE _           ' // Instance handle
 , BYREF wszResourceName AS WSTRING _       ' // Name of the resource to load
 ) AS BOOLEAN                               ' // TRUE or FALSE

   DIM hResInfo AS HRSRC                        ' // Resource handle
   DIM pResData AS LPVOID                       ' // Pointer to the resource data
   DIM eds AS EDITSTREAM                        ' // EDITSTREAM structure
   DIM rtfCustData AS AFX_RICHEDIT_CUSTOMDATA   ' // AFX_CRichEdit.CUSTOMDATA structure

   ' // Checks the validity of the parameters
   IF hRichEdit = NULL OR hInstance = NULL THEN EXIT FUNCTION
   IF LEN(wszResourceName) = 0 THEN EXIT FUNCTION

   ' // Loads the resource
   hResInfo = FindResourceW(hInstance, wszResourceName, RT_RCDATA)
   IF hResInfo = NULL THEN EXIT FUNCTION

   ' // Loads and locks the resource
   ' // Note  LockResource does not actually lock memory; it is just used to obtain
   ' // a pointer to the memory containing the resource data.
   pResData = LockResource(LoadResource(hInstance, hResInfo))
   IF pResData = NULL THEN EXIT FUNCTION
   DIM cbSize AS LONG = SizeofResource(hInstance, hResInfo)
   DIM buffer AS STRING = SPACE(cbSize)
   CopyMemory(STRPTR(buffer), pResData, cbSize)

   ' // Sends the message
   rtfCustData.pData = STRPTR(buffer)
   rtfCustData.nLen = cbSize
   rtfCustData.curPos = 0
   eds.dwCookie = cast(DWORD_PTR, @rtfCustData)
   eds.pfnCallback = cast(EDITSTREAMCALLBACK, @CRichEdit.LoadRtfFromResourceCallback)
   IF SendMessageW(hRichEdit, EM_STREAMIN, SF_RTF, cast(LPARAM, @eds)) > 0 AND eds.dwError = 0 THEN
      FUNCTION = TRUE
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback used by the CRichEdit.GetRtfText function.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetTextCallback ( _
   BYVAL dwCookie AS DWORD_PTR _                      ' // Value of the dwCookie member of the EDITSTREAM structure.
 , BYVAL pbBuff AS BYTE PTR _                         ' // Pointer to the buffer to read from.
 , BYVAL cb AS LONG _                                 ' // Number of bytes to read.
 , BYVAL pcb AS LONG PTR _                            ' // Number of bytes actually read.
 ) AS DWORD                                           ' // 0 for success, or an error code

   DIM pcws AS DWSTRING PTR = cast(DWSTRING PTR, dwCookie)
   pcws->AppendBuffer(pbBuff, cb)
   *pcb = cb
   FUNCTION = 0

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves RTF formatted text from a Rich Edit control
' - hRichEdit = Handle of the Rich Edit control.
' Returns the retrieved text or a null string.
' ========================================================================================
PRIVATE FUNCTION CRichEdit.GetRtfText (BYVAL hRichEdit AS HWND) AS STRING

   DIM eds AS EDITSTREAM, dws AS DWSTRING
   eds.dwCookie = cast(DWORD_PTR, @dws)
   eds.pfnCallBack = cast(EDITSTREAMCALLBACK, @CRichEdit.GetTextCallback)
   SendMessageW hRichEdit, EM_STREAMOUT, SF_RTF, cast(LPARAM, @eds)
   ' // Copy the ansi contents of the STRING to a STRING
'   DIM s AS STRING = SPACE(cws.m_BufferLen - 2)   ' // -2 to remove the ending nulls
'   IF LEN(s) THEN CopyMemory(STRPTR(s), cws.m_pBuffer, cws.m_BufferLen - 2)
   DIM s AS STRING = SPACE(LEN(dws) * 2)
   IF LEN(s) THEN CopyMemory(STRPTR(s), dws, LEN(dws) * 2)
   RETURN s

END FUNCTION
' ========================================================================================

END NAMESPACE
