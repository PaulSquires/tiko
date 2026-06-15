' ########################################################################################
' Platform: Microsoft Windows
' Filename: CControls.inc
' Purpose:  Windows controls
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
#include once "win/Windowsx.bi"
' // include files for Windows standard controls
#include once "CButton.inc"
#include once "CCombo.inc"
#include once "CDtPicker.inc"
#include once "CEdit.inc"
#include once "CHeader.inc"
#include once "CListBox.inc"
#include once "CListView.inc"
#include once "CMonthCal.inc"
#include once "CPager.inc"
#include once "CProgBar.inc"
#include once "CRebar.inc"
#include once "CRichEdit.inc"
#include once "CStatic.inc"
#include once "CStatusBar.inc"
#include once "CTab.inc"
#include once "CToolBar.inc"
#include once "CToolTip.inc"
#include once "CTrackBar.inc"
#include once "CTreeView.inc"
#include once "CUpDown.inc"
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
'                                    *** ANIMATE ***
' ########################################################################################
TYPE CAnimate

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION Create (BYVAL hParent AS HWND, BYVAL id AS LONG_PTR, BYVAL dwStyle AS DWORD, BYVAL hInstance AS HINSTANCE) AS HWND
   DECLARE STATIC FUNCTION Open (BYVAL hAnimate AS HWND, BYVAL pwzName AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION OpenEx (BYVAL hAnimate AS HWND, BYVAL hInstance AS HINSTANCE, BYVAL pwzName AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION Play (BYVAL hAnimate AS HWND, BYVAL from AS UINT, BYVAL to AS UINT, BYVAL rep AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION Stop (BYVAL hAnimate AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION IsPlaying (BYVAL hAnimate AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Close (BYVAL hAnimate AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Seek (BYVAL hAnimate AS HWND, BYVAL frame AS UINT) AS BOOLEAN

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CAnimate
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CAnimate
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an animation control. Animate_Create calls the CreateWindow function to create
' the animation control.
' ========================================================================================
PRIVATE FUNCTION CAnimate.Create (BYVAL hParent AS HWND, BYVAL id AS LONG_PTR, BYVAL dwStyle AS DWORD, BYVAL hInstance AS HINSTANCE) AS HWND
   RETURN CreateWindowW("SysAnimate32", NULL, dwStyle, 0, 0, 0, 0, hParent, cast(HMENU, id), hInstance, NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Opens an AVI clip and displays its first frame in an animation control. You can use this
' macro or send the ACM_OPEN message explicitly.
' ========================================================================================
PRIVATE FUNCTION CAnimate.Open (BYVAL hAnimate AS HWND, BYVAL pwzName AS WSTRING PTR) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_OPEN, 0, cast(LPARAM, pwzName))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Opens an AVI clip and displays its first frame in an animation control. You can use this
' macro or send the ACM_OPEN message explicitly.
' ========================================================================================
PRIVATE FUNCTION CAnimate.OpenEx (BYVAL hAnimate AS HWND, BYVAL hInstance AS HINSTANCE, BYVAL pwzName AS WSTRING PTR) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_OPEN, cast(WPARAM, hInstance), cast(LPARAM, pwzName))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Plays an AVI clip in an animation control. The control plays the clip in the background
' while the thread continues executing. You can use this macro or send the ACM_PLAY message
' explicitly.
' ========================================================================================
PRIVATE FUNCTION CAnimate.Play (BYVAL hAnimate AS HWND, BYVAL from AS UINT, BYVAL _to AS UINT, BYVAL rep AS UINT) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_PLAY, rep, cast(LPARAM, MAKELONG(from, _to)))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Stops playing an AVI clip in an animation control. You can use this macro or send the
' ACM_STOP message explicitly.
' ========================================================================================
PRIVATE FUNCTION CAnimate.Stop (BYVAL hAnimate AS HWND) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_STOP, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Checks to see if an Audio-Video Interleaved (AVI) clip is playing. You can use this macro
' or send an ACM_ISPLAYING message.
' ========================================================================================
PRIVATE FUNCTION CAnimate.IsPlaying (BYVAL hAnimate AS HWND) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_ISPLAYING, 0, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Closes an AVI clip. You can use this macro or send the ACM_OPEN message explicitly,
' passing in NULL parameters.
' ========================================================================================
PRIVATE FUNCTION CAnimate.Close (BYVAL hAnimate AS HWND) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_OPEN, 0, NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Directs an animation control to display a particular frame of an AVI clip. The control
' displays the clip in the background while the thread continues executing. You can use
' this macro or send the ACM_PLAY message explicitly.
' ========================================================================================
PRIVATE FUNCTION CAnimate.Seek (BYVAL hAnimate AS HWND, BYVAL frame AS UINT) AS BOOLEAN
   RETURN SendMessageW(hAnimate, ACM_PLAY, 1, cast(LPARAM, MAKELONG(frame, frame)))
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                    *** HOTKEY ***
' ########################################################################################
TYPE CHotKey

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION GetHotKey (BYVAL hHotKey AS HWND) AS DWORD
   DECLARE STATIC SUB SetHotKey (BYVAL hHotKey AS HWND, BYVAL vkCode AS SHORT, BYVAL fMods AS SHORT)
   DECLARE STATIC SUB SetRules (BYVAL hHotKey AS HWND, BYVAL fwCombInv AS WORD, BYVAL fwModInv AS WORD)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CHotKey
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CHotKey
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Gets the virtual key code and modifier flags of a hot key from a hot key control.
' Returns the virtual key code and modifier flags. The LOBYTE of the LOWORD is the virtual
' key code of the hot key. The HIBYTE of the LOWORD is the key modifier that specifies the
' keys that define a hot key combination. The modifier flags can be a combination of the
' following values:
'   HOTKEYF_ALT      ALT key
'   HOTKEYF_CONTROL  CONTROL key
'   HOTKEYF_EXT      Extended key
'   HOTKEYF_SHIFT    SHIFT key
' ========================================================================================
PRIVATE FUNCTION CHotKey.GetHotKey (BYVAL hHotKey AS HWND) AS DWORD
   RETURN SendMessageW(hHotKey, HKM_GETHOTKEY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the hot key combination for a hot key control.
' - vkCode: The virtual key code of the hot key.
' - fMods: The key modifier that indicates the keys that define a hot key combination.
' For a list of modifier flag values, see the description of the HotKey_GetHotKey function.
' ========================================================================================
PRIVATE SUB CHotKey.SetHotKey (BYVAL hHotKey AS HWND, BYVAL vkCode AS SHORT, BYVAL fMods AS SHORT)
   SendMessageW(hHotKey, HKM_SETHOTKEY, MAKELONG(vkCode, fMods), 0)
END SUB
' ========================================================================================

' ========================================================================================
' Defines the invalid combinations and the default modifier combination for a hot key control.
' - fwCombInv: An array of flags that specify invalid key combinations. This parameter can be a combination
'   of the following values:
' Value Meaning
'   HKCOMB_A ALT
'   HKCOMB_C CTRL
'   HKCOMB_CA CTRL+ALT
'   HKCOMB_NONE Unmodified keys
'   HKCOMB_S SHIFT
'   HKCOMB_SA SHIFT+ALT
'   HKCOMB_SC SHIFT+CTRL
'   HKCOMB_SCA SHIFT+CTRL+ALT
' - fwModInv: An array of flags that specify the key combination to use when the user enters
'   an invalid combination. For a list of modifier flag values, see the description of the
'   HotKey_GetHotKey message.
' ========================================================================================
PRIVATE SUB CHotKey.SetRules (BYVAL hHotKey AS HWND, BYVAL fwCombInv AS WORD, BYVAL fwModInv AS WORD)
   SendMessageW(hHotKey, HKM_SETRULES, cast(WPARAM, fwCombInv), cast(LPARAM, MAKELONG(fwModInv, 0)))
END SUB
' ========================================================================================


' ########################################################################################
'                                   *** IP ADDRESS ***
' ########################################################################################
TYPE CIPAddress

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC SUB ClearAddress (BYVAL hIPM AS HWND)
   DECLARE STATIC FUNCTION GetAddress (BYVAL hIPM AS HWND, BYVAL pdwAddr AS DWORD PTR) AS LONG
   DECLARE STATIC SUB IsBlank (BYVAL hIPM AS HWND)
   DECLARE STATIC SUB SetAddress (BYVAL hIPM AS HWND, BYVAL dwAddr AS DWORD)
   DECLARE STATIC SUB SetFocus (BYVAL hIPM AS HWND, BYVAL nField AS LONG)
   DECLARE STATIC FUNCTION SetRange (BYVAL hIPM AS HWND, BYVAL nField AS LONG, BYVAL loRange AS BYTE, BYVAL hiRange AS BYTE) AS BOOLEAN

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CIPAddress
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CIPAddress
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Clears the contents of the IP address control.
' ========================================================================================
PRIVATE SUB CIPAddress.ClearAddress (BYVAL hIPM AS HWND)
   SendMessageW(hIPM, IPM_CLEARADDRESS, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the address values for all four fields in the IP address control.
' Returns the number of nonblank fields.
' ========================================================================================
PRIVATE FUNCTION CIPAddress.GetAddress (BYVAL hIPM AS HWND, BYVAL pdwAddr AS DWORD PTR) AS LONG
   RETURN SendMessageW(hIPM, IPM_GETADDRESS, 0, CAST(LPARAM, pdwAddr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if all fields in the IP address control are blank.
' ========================================================================================
PRIVATE SUB CIPAddress.IsBlank (BYVAL hIPM AS HWND)
   SendMessageW(hIPM, IPM_ISBLANK, 0, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the address values for all four fields in the IP address control.
' ========================================================================================
PRIVATE SUB CIPAddress.SetAddress (BYVAL hIPM AS HWND, BYVAL dwAddr AS DWORD)
   SendMessageW(hIPM, IPM_SETADDRESS, 0, cast(LPARAM, dwAddr))
END SUB
' ========================================================================================

' ========================================================================================
' Sets the keyboard focus to the specified field in the IP address control.
' All of the text in that field will be selected.
' ========================================================================================
PRIVATE SUB CIPAddress.SetFocus (BYVAL hIPM AS HWND, BYVAL nField AS LONG)
   SendMessageW(hIPM, IPM_SETFOCUS, cast(WPARAM, nField), 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the valid range for the specified field in the IP address control.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CIPAddress.SetRange (BYVAL hIPM AS HWND, BYVAL nField AS LONG, BYVAL loRange AS BYTE, BYVAL hiRange AS BYTE) AS BOOLEAN
   RETURN SendMessageW(hIPM, IPM_SETRANGE, cast(WPARAM, nField), cast(LPARAM, MAKEIPRANGE(loRange, hiRange)))
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                   *** SYSLINK ***
' ########################################################################################
TYPE CSysLink

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION GetIdealHeight (BYVAL hLM AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hLM AS HWND, BYVAL cxMaxWidth AS LONG, BYVAL psize AS SIZE PTR) AS LONG
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hLM AS HWND, BYVAL cxMaxWidth AS LONG, BYREF sz AS SIZE) AS LONG
   DECLARE STATIC FUNCTION GetIdealSize (BYVAL hLM AS HWND, BYVAL cxMaxWidth AS LONG) AS SIZE
   DECLARE STATIC FUNCTION GetItem (BYVAL hLM AS HWND, BYVAL pItem AS LITEM PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hLM AS HWND, BYREF item AS LITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION HitTest (BYVAL hLM AS HWND, BYVAL phti AS LHITTESTINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION HitTest (BYVAL hLM AS HWND, BYREF hti AS LHITTESTINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItem (BYVAL hLM AS HWND, BYVAL pItem AS LITEM PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItem (BYVAL hLM AS HWND, BYREF item AS LITEM) AS BOOLEAN

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CSysLink
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CSysLink
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Retrieves the preferred height of a link for the control's current width.
' ========================================================================================
PRIVATE FUNCTION CSysLink.GetIdealHeight (BYVAL hLM AS HWND) AS LONG
   RETURN SendMessageW(hLM, LM_GETIDEALHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the preferred height of a link for the control's current width.
' Note: It is the same message that LM_GETIDEALHEIGHT with sifferent values.
' ========================================================================================
PRIVATE FUNCTION CSysLink.GetIdealSize (BYVAL hLM AS HWND, BYVAL cxMaxWidth AS LONG, BYVAL psize AS SIZE PTR) AS LONG
   RETURN SendMessageW(hLM, LM_GETIDEALHEIGHT, cxMaxWidth, cast(LPARAM, psize))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSysLink.GetIdealSize (BYVAL hLM AS HWND, BYVAL cxMaxWidth AS LONG, BYREF sz AS SIZE) AS LONG
   RETURN SendMessageW(hLM, LM_GETIDEALHEIGHT, cxMaxWidth, cast(LPARAM, @sz))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSysLink.GetIdealSize (BYVAL hLM AS HWND, BYVAL cxMaxWidth AS LONG) AS SIZE
   DIM sz AS SIZE
   SendMessageW(hLM, LM_GETIDEALHEIGHT, cxMaxWidth, cast(LPARAM, @sz))
   RETURN sz
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the states and attributes of an item.
' Returns TRUE if the message succeeds in getting the values and attributes specified.
' ========================================================================================
PRIVATE FUNCTION CSyslink.GetItem (BYVAL hLM AS HWND, BYVAL pItem AS LITEM PTR) AS BOOLEAN
   FUNCTION = SendMessageW(hLM, LM_GETITEM, 0, cast(LPARAM, pItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSyslink.GetItem (BYVAL hLM AS HWND, BYREF item AS LITEM) AS BOOLEAN
   FUNCTION = SendMessageW(hLM, LM_GETITEM, 0, cast(LPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if the user clicked the specified link.
' Returns TRUE if user clicked on a link, otherwise returns FALSE.
' ========================================================================================
PRIVATE FUNCTION CSysLink.HitTest (BYVAL hLM AS HWND, BYVAL phti AS LHITTESTINFO PTR) AS BOOLEAN
   FUNCTION = SendMessageW(hLM, LM_HITTEST, 0, cast(LPARAM, phti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSysLink.HitTest (BYVAL hLM AS HWND, BYREF hti AS LHITTESTINFO) AS BOOLEAN
   FUNCTION = SendMessageW(hLM, LM_HITTEST, 0, cast(LPARAM, @hti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the states and attributes of an item.
' Returns TRUE if the message succeeds in setting the values and attributes specified.
' ========================================================================================
PRIVATE FUNCTION CSysLink.SetItem (BYVAL hLM AS HWND, BYVAL pItem AS LITEM PTR) AS BOOLEAN
   FUNCTION = SendMessageW(hLM, LM_SETITEM, 0, cast(LPARAM, pItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSysLink.SetItem (BYVAL hLM AS HWND, BYREF item AS LITEM) AS BOOLEAN
   FUNCTION = SendMessageW(hLM, LM_SETITEM, 0, cast(LPARAM, @item))
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                    *** SCROLLBAR ***
' ########################################################################################
TYPE CScrollBar

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION Enable (BYVAL hSB AS HWND, BYVAL flags AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION Show (BYVAL hSB AS HWND, BYVAL fShow AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION Show (BYVAL hSB AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Hide (BYVAL hSB AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION SetPos (BYVAL hSB AS HWND, BYVAL pos AS LONG, BYVAL fRedraw AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetPos (BYVAL hSB AS HWND) AS LONG
   DECLARE STATIC FUNCTION SetRange (BYVAL hSB AS HWND, BYVAL posMin AS LONG, BYVAL posMax AS LONG, BYVAL fedraw AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetRange (BYVAL hSB AS HWND, BYVAL posMin AS LONG PTR, BYVAL posMax AS LONG PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetRange (BYVAL hSB AS HWND, BYREF posMin AS LONG, BYREF posMax AS LONG) AS BOOLEAN

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CScrollBar
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CScrollBar
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Enables or disables a scroll bar control.
' This method expands to a call to EnableScrollBar with SB_CTL in the wSBFlags parameter.
' ========================================================================================
PRIVATE FUNCTION CScrollBar.Enable (BYVAL hSB AS HWND, BYVAL flags AS UINT) AS BOOLEAN
   RETURN EnableScrollBar(hSB, SB_CTL, flags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows or hides a scroll bar control.
' ========================================================================================
PRIVATE FUNCTION CScrollBar.Show (BYVAL hSB AS HWND, BYVAL fShow AS BOOLEAN) AS BOOLEAN
   RETURN ShowWindow(hSB, iif(fShow, SW_SHOWNORMAL, SW_HIDE))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CScrollBar.Show (BYVAL hSB AS HWND) AS BOOLEAN
   RETURN ShowWindow(hSB, SW_SHOWNORMAL)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CScrollBar.Hide (BYVAL hSB AS HWND) AS BOOLEAN
   RETURN ShowWindow(hSB, SW_HIDE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the position of the scroll box (thumb) in the specified scroll bar and, if requested,
' redraws the scroll bar to reflect the new position of the scroll box.
' ========================================================================================
PRIVATE FUNCTION CScrollBar.SetPos (BYVAL hSB AS HWND, BYVAL pos AS LONG, BYVAL fRedraw AS BOOLEAN) AS BOOLEAN
   RETURN SetScrollPos(hSB, SB_CTL, pos, fRedraw)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the position of the scroll box (thumb) in the specified scroll bar.
' ========================================================================================
PRIVATE FUNCTION CScrollBar.GetPos (BYVAL hSB AS HWND) AS LONG
   RETURN GetScrollPos(hSB, SB_CTL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the range of a scroll bar.
' ========================================================================================
PRIVATE FUNCTION CScrollBar.SetRange (BYVAL hSB AS HWND, BYVAL posMin AS LONG, BYVAL posMax AS LONG, BYVAL fRedraw AS BOOLEAN) AS BOOLEAN
   RETURN SetScrollRange(hSB, SB_CTL, posMin, posMax, fRedraw)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the range of a scroll bar.
' ========================================================================================
PRIVATE FUNCTION CScrollBar.GetRange (BYVAL hSB AS HWND, BYVAL posMin AS LONG PTR, BYVAL posMax AS LONG PTR) AS BOOLEAN
   RETURN GetScrollRange(hSB, SB_CTL, posMin, posMax)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CScrollBar.GetRange (BYVAL hSB AS HWND, BYREF posMin AS LONG, BYREF posMax AS LONG) AS BOOLEAN
   RETURN GetScrollRange(hSB, SB_CTL, @posMin, @posMax)
END FUNCTION
' ========================================================================================


#if _WIN32_WINNT = &h0602

' ########################################################################################
'                                    *** PROPSHEET ***
' ########################################################################################
TYPE CPropSheet

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC SUB SetNextText (BYVAL hDlg AS HWND, BYVAL pwszText AS WSTRING PTR)
   DECLARE STATIC SUB ShowWizButtons (BYVAL hDlg AS HWND, BYVAL dwFlag AS DWORD, BYVAL dwButton AS DWORD)
   DECLARE STATIC SUB EnableWizButtons (BYVAL hDlg AS HWND, BYVAL dwState AS DWORD, BYVAL dwMask AS DWORD)
   DECLARE STATIC SUB SetButtonText (BYVAL hDlg AS HWND, BYVAL dwButton AS DWORD, BYVAL pwszText AS WSTRING PTR)

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CPropSheet
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CPropSheet
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' PSM_SETNEXTTEXTW         = (WM_USER + 137)
' PSM_SETNEXTTEXT          = PSM_SETNEXTTEXTW
' ========================================================================================
PRIVATE SUB CPropSheet.SetNextText (BYVAL hDlg AS HWND, BYVAL pwszText AS WSTRING PTR)
   SendMessageW(hDlg, WM_USER + 137, 0, cast(LPARAM, pwszText))
END SUB
' ========================================================================================

' ========================================================================================
' PSWIZB_SHOW                    = 0
' PSWIZB_RESTORE                 = 1
' PSM_SHOWWIZBUTTONS             = (WM_USER + 138)
' ========================================================================================
PRIVATE SUB CPropSheet.ShowWizButtons (BYVAL hDlg AS HWND, BYVAL dwFlag AS DWORD, BYVAL dwButton AS DWORD)
   SendMessageW(hDlg, WM_USER + 138, cast(WPARAM, dwFlag), cast(LPARAM, dwButton))
END SUB
' ========================================================================================

' ========================================================================================
' PSM_ENABLEWIZBUTTONS           = (WM_USER + 139)
' ========================================================================================
PRIVATE SUB CPropSheet.EnableWizButtons (BYVAL hDlg AS HWND, BYVAL dwState AS DWORD, BYVAL dwMask AS DWORD)
   SendMessageW(hDlg, WM_USER + 139, cast(WPARAM, dwState), cast(LPARAM, dwMask))
END SUB
' ========================================================================================

' ========================================================================================
' PSM_SETBUTTONTEXTW         = (WM_USER + 140)
' PSM_SETBUTTONTEXT          = PSM_SETBUTTONTEXTW
' ========================================================================================
PRIVATE SUB CPropSheet.SetButtonText (BYVAL hDlg AS HWND, BYVAL dwButton AS DWORD, BYVAL pwszText AS WSTRING PTR)
   SendMessageW(hDlg, WM_USER + 140, cast(WPARAM, dwButton), cast(LPARAM, pwszText))
END SUB
' ========================================================================================

#endif

END NAMESPACE
