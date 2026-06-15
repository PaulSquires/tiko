' ########################################################################################
' Platform: Microsoft Windows
' Filename: CListView.inc
' Purpose:  Listview control
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
' CListView class
' ########################################################################################

TYPE CListView

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION ApproximateViewRect (BYVAL hListView AS HWND, BYVAL iWidth AS SHORT, BYVAL iHeight AS SHORT, BYVAL iCount AS LONG) AS DWORD
   DECLARE STATIC FUNCTION Arrange (BYVAL hListView AS HWND, BYVAL code AS UINT) AS BOOLEAN
   DECLARE STATIC SUB CancelEditLabel (BYVAL hListView AS HWND)
   DECLARE STATIC FUNCTION CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL lpptUpLeft AS POINT PTR) AS HIMAGELIST
   DECLARE STATIC FUNCTION CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF lpptUpLeft AS POINT) AS HIMAGELIST
   DECLARE STATIC FUNCTION CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG) AS HIMAGELIST
   DECLARE STATIC FUNCTION DeleteAllItems (BYVAL hListView AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteItem (BYVAL hListView AS HWND, BYVAL i AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION EditLabel (BYVAL hListView AS HWND, BYVAL i AS LONG) AS HWND
   DECLARE STATIC FUNCTION EnableGroupView (BYVAL hListView AS HWND, BYVAL fEnable AS BOOLEAN) AS LONG
   DECLARE STATIC FUNCTION EnsureVisible (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL fPartialOK AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION FindItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYVAL pvfi AS LVFINDINFOW PTR) AS LONG
   DECLARE STATIC FUNCTION FindItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYREF vfi AS LVFINDINFOW) AS LONG
   DECLARE STATIC FUNCTION FindString (BYVAL hListView AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION GetBkColor (BYVAL hListView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetBkImage (BYVAL hListView AS HWND, BYVAL pvbki AS LVBKIMAGEW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBkImage (BYVAL hListView AS HWND, BYREF vbki AS LVBKIMAGEW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetBkImage (BYVAL hListView AS HWND) AS LVBKIMAGEW
   DECLARE STATIC FUNCTION GetCallbackMask (BYVAL hListView AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetCheckState (BYVAL hListView AS HWND, BYVAL i AS LONG) AS UINT
   DECLARE STATIC FUNCTION GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LVCOLUMNW
   DECLARE STATIC FUNCTION GetColumnText (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
   DECLARE STATIC FUNCTION GetColumnOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS LONG
   DECLARE STATIC FUNCTION GetColumnWidth (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetCountPerPage (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetEditControl (BYVAL hListView AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetExtendedListViewStyle (BYVAL hListView AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetFocusedGroup (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetGroupCount (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetGroupHeaderImageList (BYVAL hListView AS HWND) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
   DECLARE STATIC FUNCTION GetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYREF grp AS LVGROUP) AS LONG
   DECLARE STATIC FUNCTION GetGroupInfoByIndex (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYREF grp AS LVGROUP) AS BOOLEAN
   DECLARE STATIC FUNCTION GetGroupInfoByIndex (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYREF pgrp AS LVGROUP PTR) AS BOOLEAN
   DECLARE STATIC SUB GetGroupMetrics (BYVAL hListView AS HWND, BYVAL pGroupMetrics AS LVGROUPMETRICS PTR)
   DECLARE STATIC SUB GetGroupMetrics (BYVAL hListView AS HWND, BYREF GroupMetrics AS LVGROUPMETRICS)
   DECLARE STATIC FUNCTION GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetGroupState (BYVAL hListView AS HWND, BYVAL dwGroupId AS UINT, BYVAL dwMask AS UINT) AS UINT
   DECLARE STATIC FUNCTION GetHeader (BYVAL hListView AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetHotCursor (BYVAL hListView AS HWND) AS HCURSOR
   DECLARE STATIC FUNCTION GetHotItem (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetHoverTime (BYVAL hListView AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetImageList (BYVAL hListView AS HWND, BYVAL iImageList AS LONG) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetInsertMark (BYVAL hListView AS HWND, BYVAL pvim AS LVINSERTMARK PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetInsertMark (BYVAL hListView AS HWND, BYREF vim AS LVINSERTMARK) AS BOOLEAN
   DECLARE STATIC FUNCTION GetInsertMark (BYVAL hListView AS HWND) AS LVINSERTMARK
   DECLARE STATIC FUNCTION GetInsertMarkColor (BYVAL hListView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetInsertMarkRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS LONG
   DECLARE STATIC FUNCTION GetInsertMarkRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS LONG
   DECLARE STATIC FUNCTION GetInsertMarkRect (BYVAL hListView AS HWND) AS RECT
   DECLARE STATIC FUNCTION GetISearchStringLen (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetISearchString (BYVAL hListView AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemCount (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL ppt AS POINT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF pt AS POINT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG) AS POINT
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL code AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetItemSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
   DECLARE STATIC FUNCTION GetItemHorizontalSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
   DECLARE STATIC FUNCTION GetItemVerticalSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
   DECLARE STATIC FUNCTION GetItemState (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL mask AS LONG) AS UINT
   DECLARE STATIC SUB GetItemText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1)
   DECLARE STATIC FUNCTION GetText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
   DECLARE STATIC FUNCTION GetNextItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYVAL flags AS UINT) AS LONG
   DECLARE STATIC FUNCTION GetSelection (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetFocusedItem (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetNumberOfWorkAreas (BYVAL hListView AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetOrigin (BYVAL hListView AS HWND, BYVAL pptOrg AS POINT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetOrigin (BYVAL hListView AS HWND, BYREF ptOrg AS POINT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetOrigin (BYVAL hListView AS HWND) AS POINT
   DECLARE STATIC FUNCTION GetOutlineColor (BYVAL hListView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetSelectedColumn (BYVAL hListView AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetSelectedCount (BYVAL hListView AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetSelectionMark (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetStringWidth (BYVAL hListView AS HWND, BYREF wszText AS WSTRING) AS LONG
   DECLARE STATIC FUNCTION GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetTextBkColor (BYVAL hListView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetTextColor (BYVAL hListView AS HWND) AS COLORREF
   DECLARE STATIC SUB GetTileInfo (BYVAL hListView AS HWND, BYVAL pti AS LVTILEINFO PTR)
   DECLARE STATIC SUB GetTileInfo (BYVAL hListView AS HWND, BYREF ti AS LVTILEINFO)
   DECLARE STATIC FUNCTION GetTileInfo (BYVAL hListView AS HWND) AS LVTILEINFO
   DECLARE STATIC SUB GetTileViewInfo (BYVAL hListView AS HWND, BYVAL ptvi AS LVTILEVIEWINFO PTR)
   DECLARE STATIC SUB GetTileViewInfo (BYVAL hListView AS HWND, BYREF tvi AS LVTILEVIEWINFO)
   DECLARE STATIC FUNCTION GetTileViewInfo (BYVAL hListView AS HWND) AS LVTILEVIEWINFO
   DECLARE STATIC FUNCTION GetToolTips (BYVAL hListView AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetTopIndex (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetView (BYVAL hListView AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetViewRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetViewRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetViewRect (BYVAL hListView AS HWND) AS RECT
   DECLARE STATIC SUB GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG) AS RECT
   DECLARE STATIC FUNCTION HasGroup (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION HitTest (BYVAL hListView AS HWND, BYVAL pinfo AS LVHITTESTINFO PTR) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hListView AS HWND, BYREF info AS LVHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION HitTest (BYVAL hListView AS HWND) AS LVHITTESTINFO
   DECLARE STATIC FUNCTION HitTestEx (BYVAL hListView AS HWND, BYREF pinfo AS LVHITTESTINFO PTR) AS LONG
   DECLARE STATIC FUNCTION HitTestEx (BYVAL hListView AS HWND, BYREF info AS LVHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION HitTestEx (BYVAL hListView AS HWND) AS LVHITTESTINFO
   DECLARE STATIC FUNCTION InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMN PTR) AS LONG
   DECLARE STATIC FUNCTION InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMN) AS LONG
   DECLARE STATIC FUNCTION InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF wszText AS WSTRING, BYVAL nWidth AS LONG, BYVAL nFormat AS LONG = LVCFMT_LEFT) AS LONG
   DECLARE STATIC FUNCTION AddColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF wszText AS WSTRING, BYVAL nWidth AS LONG, BYVAL nFormat AS LONG = LVCFMT_LEFT) AS LONG
   DECLARE STATIC FUNCTION InsertGroup (BYVAL hListView AS HWND, BYVAL index AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
   DECLARE STATIC FUNCTION InsertGroup (BYVAL hListView AS HWND, BYVAL index AS LONG, BYREF grp AS LVGROUP) AS LONG
   DECLARE STATIC SUB InsertGroupSorted (BYVAL hListView AS HWND, BYVAL pstructInsert AS LVINSERTGROUPSORTED PTR)
   DECLARE STATIC SUB InsertGroupSorted (BYVAL hListView AS HWND, BYREF structInsert AS LVINSERTGROUPSORTED)
   DECLARE STATIC FUNCTION InsertItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS LONG
   DECLARE STATIC FUNCTION InsertItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS LONG
   DECLARE STATIC FUNCTION InsertItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG, BYREF wszText AS WSTRING) AS LONG
   DECLARE STATIC FUNCTION AddItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG, BYREF wszText AS WSTRING) AS LONG
   DECLARE STATIC FUNCTION AppendItem (BYVAL hListView AS HWND, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION InsertMarkHitTest (BYVAL hListView AS HWND, BYVAL pt AS POINT PTR, BYVAL pvim AS LVINSERTMARK PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION InsertMarkHitTest (BYVAL hListView AS HWND, BYREF pt AS POINT, BYREF vim AS LVINSERTMARK) AS BOOLEAN
   DECLARE STATIC FUNCTION IsGroupViewEnabled (BYVAL hListView AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION IsItemVisible (BYVAL hListView AS HWND, BYVAL index AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION MapIDToIndex (BYVAL hListView AS HWND, BYVAL id AS UINT) AS UINT
   DECLARE STATIC FUNCTION MapIndexToID (BYVAL hListView AS HWND, BYVAL index AS UINT) AS UINT
   DECLARE STATIC FUNCTION RedrawItems (BYVAL hListView AS HWND, BYVAL iFirst AS LONG, BYVAL iLast AS LONG) AS BOOLEAN
   DECLARE STATIC SUB RemoveAllGroups (BYVAL hListView AS HWND)
   DECLARE STATIC FUNCTION RemoveGroup (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG) AS LONG
   DECLARE STATIC FUNCTION Scroll (BYVAL hListView AS HWND, BYVAL dx AS LONG, BYVAL dy AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBkColor (BYVAL hListView AS HWND, BYVAL clrBk AS COLORREF) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBkImage (BYVAL hListView AS HWND, BYVAL pvbki AS LVBKIMAGE PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetBkImage (BYVAL hListView AS HWND, BYREF vbki AS LVBKIMAGE) AS BOOLEAN
   DECLARE STATIC FUNCTION SetCallbackMask (BYVAL hListView AS HWND, BYVAL mask AS DWORD) AS BOOLEAN
   DECLARE STATIC SUB SetCheckState (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYVAL fCheck AS BOOLEAN)
   DECLARE STATIC FUNCTION SetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS BOOLEAN
   DECLARE STATIC SUB SetColumnOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS LONG, BYVAL pi AS LONG PTR)
   DECLARE STATIC FUNCTION SetColumnWidth (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cx AS LONG) AS BOOLEAN
   DECLARE STATIC SUB SetExtendedListViewStyle (BYVAL hListView AS HWND, BYVAL dwExStyle AS DWORD)
   DECLARE STATIC SUB SetExtendedListViewStyleEx (BYVAL hListView AS HWND, BYVAL dwExMask AS DWORD, BYVAL dwExStyle AS DWORD)
   DECLARE STATIC FUNCTION SetGroupHeaderImageList (BYVAL hListView AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
   DECLARE STATIC FUNCTION SetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYREF grp AS LVGROUP) AS LONG
   DECLARE STATIC SUB SetGroupMetrics (BYVAL hListView AS HWND, BYVAL pGroupMetrics AS LVGROUPMETRICS PTR)
   DECLARE STATIC SUB SetGroupMetrics (BYVAL hListView AS HWND, BYREF GroupMetrics AS LVGROUPMETRICS)
   DECLARE STATIC FUNCTION SetGroupState (BYVAL hListView AS HWND, BYVAL dwGroupId AS UINT, BYVAL dwMask AS UINT, BYVAL dwState AS UINT) AS LONG
   DECLARE STATIC FUNCTION SetHotCursor (BYVAL hListView AS HWND, BYVAL hCur AS HCURSOR) AS HCURSOR
   DECLARE STATIC FUNCTION SetHotItem (BYVAL hListView AS HWND, BYVAL iIndex AS DWORD) AS LONG
   DECLARE STATIC SUB SetHoverTime (BYVAL hListView AS HWND, BYVAL dwHoverTimeMs AS DWORD)
   DECLARE STATIC FUNCTION SetIconSpacing (BYVAL hListView AS HWND, BYVAL cx AS SHORT, BYVAL cy AS SHORT) AS DWORD
   DECLARE STATIC FUNCTION SetImageList (BYVAL hListView AS HWND, BYVAL himl AS HIMAGELIST, BYVAL nImageList AS LONG) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetInfoTip (BYVAL hListView AS HWND, BYVAL plvInfoTip AS LVSETINFOTIP PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInfoTip (BYVAL hListView AS HWND, BYREF lvInfoTip AS LVSETINFOTIP) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInsertMark (BYVAL hListView AS HWND, BYVAL plvim AS LVINSERTMARK PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInsertMark (BYVAL hListView AS HWND, BYREF lvim AS LVINSERTMARK) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInsertMarkColor (BYVAL hListView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION SetItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemCount (BYVAL hListView AS HWND, BYVAL cItems AS LONG) AS LRESULT
   DECLARE STATIC FUNCTION SetItemCountEx (BYVAL hListView AS HWND, BYVAL cItems AS LONG, BYVAL dwFlags AS LONG) AS LRESULT
   DECLARE STATIC FUNCTION SetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS SHORT, BYVAL y AS SHORT) AS BOOLEAN
   DECLARE STATIC SUB SetItemPosition32 (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG)
   DECLARE STATIC SUB SetItemState (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL dwState AS DWORD, BYVAL mask AS DWORD)
   DECLARE STATIC SUB SetItemText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL pwszText AS WSTRING PTR)
   DECLARE STATIC SUB SetText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF wszText AS WSTRING)
   DECLARE STATIC FUNCTION SetOutlineColor (BYVAL hListView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC SUB SetSelectedColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG)
   DECLARE STATIC FUNCTION SetSelectionMark (BYVAL hListView AS HWND, BYVAL iIndex AS LONG) AS LONG
   DECLARE STATIC FUNCTION SetTextBkColor (BYVAL hListView AS HWND, BYVAL clrTextBk AS COLORREF) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTextColor (BYVAL hListView AS HWND, BYVAL clrText AS COLORREF) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTileInfo (BYVAL hListView AS HWND, BYVAL plvtinfo AS LVTILEINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTileInfo (BYVAL hListView AS HWND, BYREF lvtinfo AS LVTILEINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTileViewInfo (BYVAL hListView AS HWND, BYVAL plvtvinfo AS LVTILEVIEWINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTileViewInfo (BYVAL hListView AS HWND, BYREF lvtvinfo AS LVTILEVIEWINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION SetToolTips (BYVAL hListView AS HWND, BYVAL hwndToolTip AS HWND) AS HWND
   DECLARE STATIC FUNCTION SetView (BYVAL hListView AS HWND, BYVAL iView AS DWORD) AS LONG
   DECLARE STATIC SUB SetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYVAL prc AS RECT PTR)
   DECLARE STATIC SUB SetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYREF rc AS RECT)
   DECLARE STATIC FUNCTION SortGroups (BYVAL hListView AS HWND, BYVAL _pfnGroupCompare AS PFNLVGROUPCOMPARE PTR, BYVAL _plv AS ANY PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SortItems (BYVAL hListView AS HWND, BYVAL _pfnCompare AS PFNLVCOMPARE PTR, BYVAL _lPrm AS LPARAM) AS LONG
   DECLARE STATIC FUNCTION SortItemsEx (BYVAL hListView AS HWND, BYVAL _pfnCompare AS PFNLVCOMPARE PTR, BYVAL _lPrm AS LPARAM) AS LONG
   DECLARE STATIC FUNCTION SubItemHitTest (BYVAL hListView AS HWND, BYVAL plvhti AS LVHITTESTINFO PTR) AS LONG
   DECLARE STATIC FUNCTION SubItemHitTest (BYVAL hListView AS HWND, BYREF lvhti AS LVHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION SubItemHitTestEx (BYVAL hListView AS HWND, BYVAL plvhti AS LVHITTESTINFO PTR) AS LONG
   DECLARE STATIC FUNCTION SubItemHitTestEx (BYVAL hListView AS HWND, BYREF lvhti AS LVHITTESTINFO) AS LONG
   DECLARE STATIC FUNCTION Update (BYVAL hListView AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
   ' // Additional procedures
   DECLARE STATIC SUB SelectItem (BYVAL hListView AS HWND, BYVAL iIndex AS LONG)
   DECLARE STATIC SUB SelectAllItems (BYVAL hListView AS HWND)
   DECLARE STATIC SUB UnselectItem (BYVAL hListView AS HWND, BYVAL iIndex AS LONG)
   DECLARE STATIC SUB UnselectAllItems (BYVAL hListView AS HWND)
   DECLARE STATIC SUB MakeHeaderFlat (BYVAL hListView AS HWND)
   DECLARE STATIC FUNCTION FitContent (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION AutoSizeColumns (BYVAL hListView AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION FitHeader (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION AutoSizeHeader (BYVAL hListView AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION GetColumnCount (BYVAL hListView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetHeaderText (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
   DECLARE STATIC FUNCTION GetColumnOrder (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LONG
   DECLARE STATIC FUNCTION GetOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS DWORD, BYVAL pi AS LONG PTR) AS LONG
   DECLARE STATIC FUNCTION GetTooltipsFont (BYVAL hListView AS HWND) AS HFONT
   DECLARE STATIC SUB SetTooltipsFont (BYVAL hListView AS HWND, BYVAL hFont AS HFONT = NULL, BYVAL fRedraw AS BOOLEAN = FALSE)
   DECLARE STATIC FUNCTION SetHeaderFont (BYVAL hListView AS HWND, BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, _
      BYVAL lWeight AS LONG, BYVAL bItalic AS BYTE, BYVAL bUnderline AS BYTE, BYVAL bStrikeOut AS BYTE, _
      BYVAL bCharSet AS BYTE) AS HFONT
   DECLARE STATIC FUNCTION ModifyHeaderFont (BYVAL hListView AS HWND, BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, _
      BYVAL lWeight AS LONG, BYVAL bItalic AS BYTE, BYVAL bUnderline AS BYTE, BYVAL bStrikeOut AS BYTE, _
      BYVAL bCharSet AS BYTE) AS HFONT

#if _WIN32_WINNT >= &h0600
   DECLARE STATIC FUNCTION GetFooterInfo (BYVAL hListView AS HWND, BYVAL pvfi AS LVFOOTERINFO PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterInfo (BYVAL hListView AS HWND, BYREF vfi AS LVFOOTERINFO) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterInfo (BYVAL hListView AS HWND) AS LVFOOTERINFO
   DECLARE STATIC FUNCTION GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL pfi AS LVFOOTERITEM PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYREF fi AS LVFOOTERITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS UINT) AS LVFOOTERITEM
   DECLARE STATIC FUNCTION GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT) AS RECT
   DECLARE STATIC FUNCTION GetItemIndexRect (BYVAL hListView AS HWND, BYVAL pvii AS LVITEMINDEX PTR, BYVAL iSubItem AS LONG, BYVAL code AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemIndexRect (BYVAL hListView AS HWND, BYREF pvii AS LVITEMINDEX, BYVAL iSubItem AS LONG, BYVAL code AS LONG, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemIndexRect (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL iSubItem AS LONG, BYVAL code AS LONG) AS RECT
   DECLARE STATIC FUNCTION GetNextItemIndex (BYVAL hListView AS HWND, BYVAL plvii AS LVITEMINDEX PTR, BYVAL flags AS ..LPARAM) AS LONG
   DECLARE STATIC FUNCTION GetNextItemIndex (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL flags AS ..LPARAM) AS LONG
   DECLARE STATIC FUNCTION SetItemIndexState (BYVAL hListView AS HWND, BYVAL plvii AS LVITEMINDEX PTR, BYVAL dwData AS UINT, BYVAL mask AS UINT) AS HRESULT
   DECLARE STATIC FUNCTION SetItemIndexState (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL dwData AS UINT, BYVAL mask AS UINT) AS HRESULT
   DECLARE STATIC FUNCTION GetEmptyText (BYVAL hListView AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS BOOLEAN
   DECLARE STATIC FUNCTION GetFooterRect (BYVAL hListView AS HWND) AS RECT
#endif

   DECLARE STATIC FUNCTION SetDarkMode (BYVAL hListView AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode (BYVAL hListView AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CListView
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CListView
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Calculates the approximate width and height required to display a given number of items.
' ========================================================================================
PRIVATE FUNCTION CListView.ApproximateViewRect (BYVAL hListView AS HWND, BYVAL iWidth AS SHORT, BYVAL iHeight AS SHORT, BYVAL iCount AS LONG) AS DWORD
   RETURN SendMessageW(hListView, LVM_APPROXIMATEVIEWRECT, iCount, MAKELONG(iWidth, iHeight))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges items in icon view.
' ========================================================================================
PRIVATE FUNCTION CListView.Arrange (BYVAL hListView AS HWND, BYVAL code AS UINT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_ARRANGE, code, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Cancels an item text editing operation.
' ========================================================================================
PRIVATE SUB CListView.CancelEditLabel (BYVAL hListView AS HWND)
   SendMessageW hListView, LVM_CANCELEDITLABEL, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Creates a drag image list for the specified item.
' ========================================================================================
PRIVATE FUNCTION CListView.CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL lpptUpLeft AS POINT PTR) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_CREATEDRAGIMAGE, i, CAST(LPARAM, lpptUpLeft)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF tUpLeft AS POINT) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_CREATEDRAGIMAGE, i, CAST(LPARAM, @tUpLeft)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG) AS HIMAGELIST
   DIM tUpLeft AS POINT = TYPE<POINT>(x, y)
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_CREATEDRAGIMAGE, i, CAST(LPARAM, @tUpLeft)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes all items from a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.DeleteAllItems (BYVAL hListView AS HWND) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_DELETEALLITEMS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes a column from a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.DeleteColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_DELETECOLUMN, iCol, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes an item from a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.DeleteItem (BYVAL hListView AS HWND, BYVAL i AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_DELETEITEM, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Begins in-place editing of the specified list-view item's text. The message implicitly
' selects and focuses the specified item.
' ========================================================================================
PRIVATE FUNCTION CListView.EditLabel (BYVAL hListView AS HWND, BYVAL i AS LONG) AS HWND
   RETURN CAST(HWND, SendMessageW(hListView, LVM_EDITLABEL, i, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables or disables whether the items in a list-view control display as a group.
' ========================================================================================
PRIVATE FUNCTION CListView.EnableGroupView (BYVAL hListView AS HWND, BYVAL fEnable AS BOOLEAN) AS LONG
   RETURN SendMessageW(hListView, LVM_ENABLEGROUPVIEW, fEnable, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Ensures that a list-view item is either entirely or partially visible, scrolling the
' list-view control if necessary.
' ========================================================================================
PRIVATE FUNCTION CListView.EnsureVisible (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL fPartialOK AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_ENSUREVISIBLE, i, MAKELONG(fPartialOK, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for a list-view item with the specified characteristics.
' ========================================================================================
PRIVATE FUNCTION CListView.FindItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYVAL pvfi AS LVFINDINFOW PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_FINDITEMW, iStart, CAST(LPARAM, pvfi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.FindItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYREF vfi AS LVFINDINFOW) AS LONG
   RETURN SendMessageW(hListView, LVM_FINDITEMW, iStart, CAST(LPARAM, @vfi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Searches for a list-view item with the specified text.
' Returns the index of the item if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CListView.FindString (BYVAL hListView AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
   DIM lvf AS LVFINDINFOW
   lvf.flags = LVFI_STRING OR LVFI_PARTIAL
   lvf.psz = pwszText
   RETURN SendMessageW(hListView, LVM_FINDITEMW, -1, CAST(LPARAM, @lvf))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the background color of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetBkColor (BYVAL hListView AS HWND) AS COLORREF
   RETURN SendMessageW(hListView, LVM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the background image in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetBkImage (BYVAL hListView AS HWND, BYVAL pvbki AS LVBKIMAGEW PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETBKIMAGE, 0, CAST(LPARAM, pvbki))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetBkImage (BYVAL hListView AS HWND, BYREF vbki AS LVBKIMAGEW) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETBKIMAGE, 0, CAST(LPARAM, @vbki))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetBkImage (BYVAL hListView AS HWND) AS LVBKIMAGEW
   DIM vbki AS LVBKIMAGEW
   SendMessageW(hListView, LVM_GETBKIMAGEW, 0, CAST(LPARAM, @vbki))
   RETURN vbki
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the callback mask for a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetCallbackMask (BYVAL hListView AS HWND) AS UINT
   RETURN SendMessageW(hListView, LVM_GETCALLBACKMASK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if an item in a list-view control is selected. This should be used only for
' list-view controls that have the LVS_EX_CHECKBOXES style.
' ========================================================================================
PRIVATE FUNCTION CListView.GetCheckState (BYVAL hListView AS HWND, BYVAL i AS LONG) AS UINT
   DIM nCheck AS LONG
   nCheck = SendMessageW(hListView, LVM_GETITEMSTATE, i, LVIS_STATEIMAGEMASK)
   RETURN BIT(nCheck, 12) - 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the attributes of a list-view control's column.
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETCOLUMNW, iCol, CAST(LPARAM, pcol))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETCOLUMNW, iCol, CAST(LPARAM, @col))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LVCOLUMNW
   DIM pcol AS LVCOLUMNW
   SendMessageW(hListView, LVM_GETCOLUMNW, iCol, CAST(LPARAM, @pcol))
   RETURN pcol
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text of a list-view control's column.
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumnText (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
   DIM dwsText AS DWSTRING
   IF cchTextMax < 1 THEN cchTextMax = MAX_PATH + 1
   dwsText = WSPACE(cchTextMax + 1)
   DIM lvc AS LVCOLUMNW
   lvc.mask = LVCF_TEXT
   lvc.cchTextMax = cchTextMax + 1
   lvc.pszText = STRPTR(dwsText)
   IF SendMessageW(hListView, LVM_GETCOLUMNW, iCol, CAST(LPARAM, @lvc)) THEN RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current left-to-right order of columns in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumnOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_GETCOLUMNORDERARRAY, iCount, CAST(LPARAM, lpiArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the width of a column in report or list view.
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumnWidth (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LONG
   RETURN SendMessageW(hListView, LVM_GETCOLUMNWIDTH, iCol, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Calculates the number of items that can fit vertically in the visible area of a
' list-view control when in list or report view.
' ========================================================================================
PRIVATE FUNCTION CListView.GetCountPerPage (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETCOUNTPERPAGE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to the edit control being used to edit a list-view item's text.
' ========================================================================================
PRIVATE FUNCTION CListView.GetEditControl (BYVAL hListView AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hListView, LVM_GETEDITCONTROL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the extended styles that are currently in use for a given list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetExtendedListViewStyle (BYVAL hListView AS HWND) AS DWORD
   RETURN SendMessageW(hListView, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the group that has the focus.
' ========================================================================================
PRIVATE FUNCTION CListView.GetFocusedGroup (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETFOCUSEDGROUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of groups.
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupCount (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETGROUPCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the group header image list that has been set for an existing list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupHeaderImageList (BYVAL hListView AS HWND) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_GETIMAGELIST, LVSIL_GROUPHEADER, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets group information.
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
   IF pgrp = NULL THEN RETURN -1
   pgrp->cbSize = SIZEOF(LVGROUP)
   RETURN SendMessageW(hListView, LVM_GETGROUPINFO, iGroupId, CAST(LPARAM, pgrp))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYREF grp AS LVGROUP) AS LONG
   IF VARPTR(grp) = NULL THEN RETURN -1
   grp.cbSize = SIZEOF(LVGROUP)
   RETURN SendMessageW(hListView, LVM_GETGROUPINFO, iGroupId, CAST(LPARAM, @grp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information on a specified group.
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupInfoByIndex (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYREF pgrp AS LVGROUP PTR) AS BOOLEAN
   IF pgrp = NULL THEN RETURN FALSE
   pgrp->cbSize = SIZEOF(LVGROUP)
   RETURN SendMessageW(hListView, LVM_GETGROUPINFOBYINDEX, iIndex, CAST(LPARAM, pgrp))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupInfoByIndex (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYREF grp AS LVGROUP) AS BOOLEAN
   IF VARPTR(grp) = NULL THEN RETURN FALSE
   grp.cbSize = SIZEOF(LVGROUP)
   RETURN SendMessageW(hListView, LVM_GETGROUPINFOBYINDEX, iIndex, CAST(LPARAM, @grp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about the display of groups.
' ========================================================================================
PRIVATE SUB CListView.GetGroupMetrics (BYVAL hListView AS HWND, BYVAL pGroupMetrics AS LVGROUPMETRICS PTR)
   IF pGroupMetrics = NULL THEN EXIT SUB
   pGroupMetrics->cbSize = SIZEOF(LVGROUPMETRICS)
   SendMessageW hListView, LVM_GETGROUPMETRICS, 0, CAST(LPARAM, pGroupMetrics)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.GetGroupMetrics (BYVAL hListView AS HWND, BYREF GroupMetrics AS LVGROUPMETRICS)
   IF VARPTR(GroupMetrics) = NULL THEN EXIT SUB
   GroupMetrics.cbSize = SIZEOF(LVGROUPMETRICS)
   SendMessageW hListView, LVM_GETGROUPMETRICS, 0, CAST(LPARAM, @GroupMetrics)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the rectangle for a specified group.
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETGROUPRECT, iGroupId, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, BYREF rc AS RECT) AS BOOLEAN
   rc.Top = nType
   RETURN SendMessageW(hListView, LVM_GETGROUPRECT, iGroupId, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG) AS RECT
   DIM rc AS RECT
   rc.Top = nType
   SendMessageW(hListView, LVM_GETGROUPRECT, iGroupId, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state for a specified group.
' ========================================================================================
PRIVATE FUNCTION CListView.GetGroupState (BYVAL hListView AS HWND, BYVAL dwGroupId AS UINT, BYVAL dwMask AS UINT) AS UINT
   RETURN SendMessageW(hListView, LVM_GETGROUPSTATE, dwGroupId, dwMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the handle to the header control used by a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetHeader (BYVAL hListView AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the HCURSOR used when the pointer is over an item while hot tracking is enabled.
' ========================================================================================
PRIVATE FUNCTION CListView.GetHotCursor (BYVAL hListView AS HWND) AS HCURSOR
   RETURN CAST(HCURSOR, SendMessageW(hListView, LVM_GETHOTCURSOR, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the hot item.
' ========================================================================================
PRIVATE FUNCTION CListView.GetHotItem (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETHOTITEM, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the amount of time that the mouse cursor must hover over an item before it is selected.
' ========================================================================================
PRIVATE FUNCTION CListView.GetHoverTime (BYVAL hListView AS HWND) AS DWORD
   RETURN SendMessageW(hListView, LVM_GETHOVERTIME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to an image list used for drawing list-view items.
' ========================================================================================
PRIVATE FUNCTION CListView.GetImageList (BYVAL hListView AS HWND, BYVAL iImageList AS LONG) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_GETIMAGELIST, iImageList, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of the insertion point.
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMark (BYVAL hListView AS HWND, BYVAL pvim AS LVINSERTMARK PTR) AS BOOLEAN
   IF pvim = NULL THEN RETURN FALSE
   pvim->cbSize = SIZEOF(LVINSERTMARK)
   RETURN SendMessageW(hListView, LVM_GETINSERTMARK, 0, CAST(LPARAM, pvim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMark (BYVAL hListView AS HWND, BYREF vim AS LVINSERTMARK) AS BOOLEAN
   IF VARPTR(vim) = NULL THEN RETURN FALSE
   vim.cbSize = SIZEOF(LVINSERTMARK)
   RETURN SendMessageW(hListView, LVM_GETINSERTMARK, 0, CAST(LPARAM, @vim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMark (BYVAL hListView AS HWND) AS LVINSERTMARK
   DIM vim AS LVINSERTMARK
   vim.cbSize = SIZEOF(LVINSERTMARK)
   SendMessageW(hListView, LVM_GETINSERTMARK, 0, CAST(LPARAM, @vim))
   RETURN vim
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color of the insertion point.
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMarkColor (BYVAL hListView AS HWND) AS COLORREF
   RETURN SendMessageW(hListView, LVM_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the rectangle that bounds the insertion point.
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMarkRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_GETINSERTMARKRECT, 0, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMarkRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS LONG
   RETURN SendMessageW(hListView, LVM_GETINSERTMARKRECT, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetInsertMarkRect (BYVAL hListView AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hListView, LVM_GETINSERTMARKRECT, 0, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the length of the incremental search string of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetISearchStringLen (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETISEARCHSTRINGW, 0, NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the incremental search string of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetISearchString (BYVAL hListView AS HWND) AS DWSTRING
   DIM nLen AS LONG = SendMessageW(hListView, LVM_GETISEARCHSTRINGW, 0, BYVAL NULL)
   DIM dwsSearch AS DWSTRING = WSPACE(nLen + 1)
   nLen = SendMessageW(hListView, LVM_GETISEARCHSTRINGW, 0, BYVAL CAST(LPARAM, STRPTR(dwsSearch)))
   RETURN LEFT(dwsSearch, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets some or all of a list-view item's attributes.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETITEM, 0, CAST(LPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETITEM, 0, CAST(LPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the number of items in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemCount (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of a list-view item.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL ppt AS POINT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETITEMPOSITION, i, CAST(LPARAM, ppt))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF pt AS POINT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETITEMPOSITION, i, CAST(LPARAM, @pt))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG) AS POINT
   DIM pt AS POINT
   SendMessageW(hListView, LVM_GETITEMPOSITION, i, CAST(LPARAM, @pt))
   RETURN pt
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounding rectangle for all or part of an item in the current view.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETITEMRECT, i, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETITEMRECT, i, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL code AS LONG) AS RECT
   DIM rc AS RECT : rc.Left = code
   SendMessageW(hListView, LVM_GETITEMRECT, i, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines the spacing between items in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
   RETURN SendMessageW(hListView, LVM_GETITEMSPACING, fSmall, 0)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemHorizontalSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
   RETURN LOWORD(SendMessageW(hListView, LVM_GETITEMSPACING, fSmall, 0))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemVerticalSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
   RETURN HIWORD(SendMessageW(hListView, LVM_GETITEMSPACING, fSmall, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of a list-view item.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemState (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL mask AS LONG) AS UINT
   RETURN SendMessageW(hListView, LVM_GETITEMSTATE, i, mask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a list-view item or subitem.
' ========================================================================================
PRIVATE SUB CListView.GetItemText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG  = MAX_PATH + 1)
   DIM lvi AS LVITEMW
   lvi.iSubItem = iSubItem
   lvi.cchTextMax = cchTextMax
   lvi.pszText = pwszText
   SendMessageW hListView, LVM_GETITEMTEXTW, i, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================
' ========================================================================================
' * Gets the text of a list-view item or subitem.
' ========================================================================================
PRIVATE FUNCTION CListView.GetText (BYVAL hListView AS HWND, BYVAL item AS LONG, BYVAL iSubItem AS LONG, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
   DIM dwsText AS DWSTRING
   DIM lvi AS LVITEMW
   DIM nLen AS LONG
   IF cchTextMax < 1 THEN cchTextMax = MAX_PATH + 1
   dwsText = WSPACE(cchTextMax + 1)
   lvi.mask = LVIF_TEXT
   lvi.iItem = item
   lvi.iSubItem = iSubItem
   lvi.cchTextMax = cchTextMax + 1
   lvi.pszText = STRPTR(dwsText)
   nLen = SendMessageW(hListView, LVM_GETITEMTEXTW, 0, CAST(LPARAM, @lvi))
   RETURN LEFT(dwsText, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for a list-view item that has the specified properties and bears the specified
' relationship to a specified item.
' ========================================================================================
PRIVATE FUNCTION CListView.GetNextItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYVAL flags AS UINT) AS LONG
   RETURN SendMessageW(hListView, LVM_GETNEXTITEM, iStart, MAKELONG(flags, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the zero-based index of the currently selected item.
' See the following Microsoft article: How To Select a Listview Item Programmatically
' http://support.microsoft.com/kb/131284
' ========================================================================================
PRIVATE FUNCTION CListView.GetSelection (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETNEXTITEM, -1, LVNI_SELECTED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the item that has the focus, which may or may not be selected.
' Returns the index of the next item if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CListView.GetFocusedItem (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETNEXTITEM, -1, LVNI_ALL OR LVNI_FOCUSED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of working areas in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetNumberOfWorkAreas (BYVAL hListView AS HWND) AS DWORD
   DIM pnWorkAreas AS DWORD
   RETURN SendMessageW(hListView, LVM_GETNUMBEROFWORKAREAS, 0, CAST(LPARAM, @pnWorkAreas))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current view origin for a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetOrigin (BYVAL hListView AS HWND, BYVAL pptOrg AS POINT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETORIGIN, 0, CAST(LPARAM, pptOrg))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetOrigin (BYVAL hListView AS HWND, BYREF ptOrg AS POINT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETORIGIN, 0, CAST(LPARAM, @ptOrg))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetOrigin (BYVAL hListView AS HWND) AS POINT
   DIM ptOrg AS POINT
   SendMessageW(hListView, LVM_GETORIGIN, 0, CAST(LPARAM, @ptOrg))
   RETURN ptOrg
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color of the border of a list-view control if the LVS_EX_BORDERSELECT extended
' window style is set.
' ========================================================================================
PRIVATE FUNCTION CListView.GetOutlineColor (BYVAL hListView AS HWND) AS COLORREF
   RETURN SendMessageW(hListView, LVM_GETOUTLINECOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets an integer that specifies the selected column.
' ========================================================================================
PRIVATE FUNCTION CListView.GetSelectedColumn (BYVAL hListView AS HWND) AS UINT
   RETURN SendMessageW(hListView, LVM_GETSELECTEDCOLUMN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines the number of selected items in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetSelectedCount (BYVAL hListView AS HWND) AS UINT
   RETURN SendMessageW(hListView, LVM_GETSELECTEDCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the selection mark from a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetSelectionMark (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETSELECTIONMARK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Determines the width of a specified string using the specified list-view control's
' current font.
' ========================================================================================
PRIVATE FUNCTION CListView.GetStringWidth (BYVAL hListView AS HWND, BYREF wszText AS WSTRING) AS LONG
   RETURN SendMessageW(hListView, LVM_GETSTRINGWIDTHW, 0, CAST(LPARAM, @wszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about the rectangle that surrounds a subitem in a list-view control.
' This function is intended to be used only on list-view controls that use the LVS_REPORT style.
' ========================================================================================
PRIVATE FUNCTION CListView.GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   IF prc = NULL THEN RETURN FALSE
   prc->Top = iSubItem
   prc->Left = nCode
   RETURN SendMessageW(hListView, LVM_GETSUBITEMRECT, iItem, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYREF rc AS RECT) AS BOOLEAN
   IF VARPTR(rc) = NULL THEN RETURN FALSE
   rc.Top = iSubItem
   rc.Left = nCode
   RETURN SendMessageW(hListView, LVM_GETSUBITEMRECT, iItem, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG) AS RECT
   DIM rc AS RECT
   rc.Top = iSubItem
   rc.Left = nCode
   SendMessageW(hListView, LVM_GETSUBITEMRECT, iItem, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text background color of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetTextBkColor (BYVAL hListView AS HWND) AS COLORREF
   RETURN SendMessageW(hListView, LVM_GETTEXTBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text color of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetTextColor (BYVAL hListView AS HWND) AS COLORREF
   RETURN SendMessageW(hListView, LVM_GETTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about a tile in a list-view control.
' ========================================================================================
PRIVATE SUB CListView.GetTileInfo (BYVAL hListView AS HWND, BYVAL pti AS LVTILEINFO PTR)
   IF pti = NULL THEN EXIT SUB
   pti->cbSize = SIZEOF(LVTILEINFO)
   SendMessageW hListView, LVM_GETTILEINFO, 0, CAST(LPARAM, pti)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.GetTileInfo (BYVAL hListView AS HWND, BYREF ti AS LVTILEINFO)
   IF VARPTR(ti) = NULL THEN EXIT SUB
   ti.cbSize = SIZEOF(LVTILEINFO)
   SendMessageW hListView, LVM_GETTILEINFO, 0, CAST(LPARAM, @ti)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetTileInfo (BYVAL hListView AS HWND) AS LVTILEINFO
   DIM ti AS LVTILEINFO
   ti.cbSize = SIZEOF(LVTILEINFO)
   SendMessageW hListView, LVM_GETTILEINFO, 0, CAST(LPARAM, @ti)
   RETURN ti
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about a list-view control in tile view.
' ========================================================================================
PRIVATE SUB CListView.GetTileViewInfo (BYVAL hListView AS HWND, BYVAL ptvi AS LVTILEVIEWINFO PTR)
   IF ptvi = NULL THEN EXIT SUB
   ptvi->cbSize = SIZEOF(LVTILEVIEWINFO)
   SendMessageW hListView, LVM_GETTILEVIEWINFO, 0, CAST(LPARAM, ptvi)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.GetTileViewInfo (BYVAL hListView AS HWND, BYREF tvi AS LVTILEVIEWINFO)
   IF VARPTR(tvi) = NULL THEN EXIT SUB
   tvi.cbSize = SIZEOF(LVTILEVIEWINFO)
   SendMessageW hListView, LVM_GETTILEVIEWINFO, 0, CAST(LPARAM, @tvi)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetTileViewInfo (BYVAL hListView AS HWND) AS LVTILEVIEWINFO
   DIM tvi AS LVTILEVIEWINFO
   tvi.cbSize = SIZEOF(LVTILEVIEWINFO)
   SendMessageW hListView, LVM_GETTILEVIEWINFO, 0, CAST(LPARAM, @tvi)
   RETURN tvi
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the ToolTip control that the list-view control uses to display tooltips.
' ========================================================================================
PRIVATE FUNCTION CListView.GetToolTips (BYVAL hListView AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hListView, LVM_GETTOOLTIPS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the index of the topmost visible item when in list or report view.
' ========================================================================================
PRIVATE FUNCTION CListView.GetTopIndex (BYVAL hListView AS HWND) AS LONG
   RETURN SendMessageW(hListView, LVM_GETTOPINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current view of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetView (BYVAL hListView AS HWND) AS DWORD
   RETURN SendMessageW(hListView, LVM_GETVIEW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounding rectangle of all items in the list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetViewRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETVIEWRECT, 0, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetViewRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETVIEWRECT, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetViewRect (BYVAL hListView AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hListView, LVM_GETVIEWRECT, 0, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the working areas from a list-view control.
' ========================================================================================
PRIVATE SUB CListView.GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYVAL prc AS RECT PTR)
   SendMessageW hListView, LVM_GETWORKAREAS, nWorkAreas, CAST(LPARAM, prc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYREF rc AS RECT)
   SendMessageW hListView, LVM_GETWORKAREAS, nWorkAreas, CAST(LPARAM, @rc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG) AS RECT
   DIM rc AS RECT
   SendMessageW hListView, LVM_GETWORKAREAS, nWorkAreas, CAST(LPARAM, @rc)
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the list-view control has a specified group.
' ========================================================================================
PRIVATE FUNCTION CListView.HasGroup (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_HASGROUP, iGroupId, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item, if any, is at a specified position.
' ========================================================================================
PRIVATE FUNCTION CListView.HitTest (BYVAL hListView AS HWND, BYVAL pinfo AS LVHITTESTINFO PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_HITTEST, 0, CAST(LPARAM, pinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.HitTest (BYVAL hListView AS HWND, BYREF info AS LVHITTESTINFO) AS LONG
   RETURN SendMessageW(hListView, LVM_HITTEST, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.HitTest (BYVAL hListView AS HWND) AS LVHITTESTINFO
   DIM info AS LVHITTESTINFO
   SendMessageW(hListView, LVM_HITTEST, 0, CAST(LPARAM, @info))
   RETURN info
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item, if any, is at a specified position.
' ========================================================================================
PRIVATE FUNCTION CListView.HitTestEx (BYVAL hListView AS HWND, BYREF pinfo AS LVHITTESTINFO PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_HITTEST, -1, CAST(LPARAM, pinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.HitTestEx (BYVAL hListView AS HWND, BYREF info AS LVHITTESTINFO) AS LONG
   RETURN SendMessageW(hListView, LVM_HITTEST, -1, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.HitTestEx (BYVAL hListView AS HWND) AS LVHITTESTINFO
   DIM info AS LVHITTESTINFO
   SendMessageW(hListView, LVM_HITTEST, -1, CAST(LPARAM, @info))
   RETURN info
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Inserts a new column in a list-view control.
' Usage example:
'   DIM lvc AS LVCOLUMNW, wszText AS WSTRING * 260
'   lvc.mask = LVCF_FMT OR LVCF_WIDTH OR LVCF_TEXT OR LVCF_SUBITEM
'   FOR i AS LONG = 1 TO 5
'      wszText = "Column " & STR(i)
'      lvc.pszText = @wszText
'      lvc.cx = 50
'      CListView.InsertColumn(i, @lvc)
'   NEXT
' ========================================================================================
PRIVATE FUNCTION CListView.InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMN PTR) AS LONG
   IF pcol = NULL THEN RETURN -1
   RETURN SendMessageW(hListView, LVM_INSERTCOLUMN, iCol, CAST(LPARAM, pcol))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMN) AS LONG
   IF VARPTR(col) = 0 THEN RETURN -1
   RETURN SendMessageW(hListView, LVM_INSERTCOLUMN, iCol, CAST(LPARAM, @col))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Inserts a new column in a list-view control.
' - hCtl: Handle to the ListView control.
' - iCol: Index of the new column.
' - wszText: The column header text.
' - nWidth: The width of the column, in pixels.
' - nFormat: Alignment of the column header and the subitem text in the column.
'   The alignment of the leftmost column is always left-justified; it cannot be changed.
'   This member can be one of the following values:
'   see https://msdn.microsoft.com/en-us/library/windows/desktop/bb774743%28v=vs.85%29.aspx
' Returns the index of the new column if successful, or -1 otherwise.
' Usage example:
'   DIM wszText AS WSTRING * 260
'   FOR i AS LONG = 1 TO 5
'      wszText = "Column " & STR(i)
'      CListView.AddColumn(i, wszText, 50)
'   NEXT
' ========================================================================================
PRIVATE FUNCTION CListView.AddColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF wszText AS WSTRING, BYVAL nWidth AS LONG, BYVAL nFormat AS LONG = LVCFMT_LEFT) AS LONG
   DIM lvc AS LVCOLUMNW
   lvc.mask = LVCF_FMT OR LVCF_WIDTH OR LVCF_TEXT OR LVCF_SUBITEM
   lvc.fmt = nFormat
   lvc.pszText = @wszText
   lvc.cx = nWidth
   RETURN SendMessageW(hListView, LVM_INSERTCOLUMNW, iCol, CAST(LPARAM, @lvc))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Inserts a new column in a list-view control. Same as AddColumn.
' ========================================================================================
PRIVATE FUNCTION CListView.InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF wszText AS WSTRING, BYVAL nWidth AS LONG, BYVAL nFormat AS LONG = LVCFMT_LEFT) AS LONG
   DIM lvc AS LVCOLUMNW
   lvc.mask = LVCF_FMT OR LVCF_WIDTH OR LVCF_TEXT OR LVCF_SUBITEM
   lvc.fmt = nFormat
   lvc.pszText = @wszText
   lvc.cx = nWidth
   RETURN SendMessageW(hListView, LVM_INSERTCOLUMNW, iCol, CAST(LPARAM, @lvc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a group into a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.InsertGroup (BYVAL hListView AS HWND, BYVAL index AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_INSERTGROUP, index, CAST(LPARAM, pgrp))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.InsertGroup (BYVAL hListView AS HWND, BYVAL index AS LONG, BYREF grp AS LVGROUP) AS LONG
   RETURN SendMessageW(hListView, LVM_INSERTGROUP, index, CAST(LPARAM, @grp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a group into an ordered list of groups.
' ========================================================================================
PRIVATE SUB CListView.InsertGroupSorted (BYVAL hListView AS HWND, BYVAL pstructInsert AS LVINSERTGROUPSORTED PTR)
   SendMessageW hListView, LVM_INSERTGROUPSORTED, CAST(LPARAM, pstructInsert), 0
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.InsertGroupSorted (BYVAL hListView AS HWND, BYREF structInsert AS LVINSERTGROUPSORTED)
   SendMessageW hListView, LVM_INSERTGROUPSORTED, CAST(LPARAM, @structInsert), 0
END SUB
' ========================================================================================

' ========================================================================================
' Inserts a new item in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.InsertItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS LONG
   IF pitem = NULL THEN RETURN - 1
   RETURN SendMessageW(hListView, LVM_INSERTITEMW, 0, CAST(LPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.InsertItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS LONG
   IF VARPTR(item) = 0 THEN RETURN - 1
   RETURN SendMessageW(hListView, LVM_INSERTITEMW, 0, CAST(LPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item in a list-view control.
' - hListView: Handle to the ListView control.
' - iItem: Index at which the new item should be inserted. If this value is greater than
'   the number of items currently contained by the listview control, the new item will be
'   appended to the end of the list and assigned the correct index. Examine the return
'   value to determine the actual index assigned to the item.
' - iImage: Index of the item's icon in the control's image list.
' - wszText: The item text.
' Returns the index of the new item if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CListView.AddItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG, BYREF wszText AS WSTRING) AS LONG
   DIM lvi AS LVITEMW
   lvi.mask = LVIF_TEXT
   lvi.pszText = @wszText
   lvi.iItem = iItem
   lvi.iImage = iImage
   FUNCTION = SendMessageW(hListView, LVM_INSERTITEMW, iItem, cast(LPARAM, @lvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.InsertItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG, BYREF wszText AS WSTRING) AS LONG
   DIM lvi AS LVITEMW
   lvi.mask = LVIF_TEXT
   lvi.pszText = @wszText
   lvi.iItem = iItem
   lvi.iImage = iImage
   FUNCTION = SendMessageW(hListView, LVM_INSERTITEMW, iItem, cast(LPARAM, @lvi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Appends a new item in a list-view control.
' - hListView: Handle to the ListView control.
' - iImage: Zero-based index of the item's icon in the control's image list.
' - pwszText: The item text.
' Returns the index of the new item if successful, or -1 otherwise.
' ========================================================================================
PRIVATE FUNCTION CListView.AppendItem (BYVAL hListView AS HWND, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
   DIM lvi AS LVITEMW
   DIM iItem AS LONG = SendMessageW(hListView, LVM_GETITEMCOUNT, 0, 0)
   lvi.mask = LVIF_TEXT
   lvi.pszText = pwszText
   lvi.iItem = iItem
   lvi.iImage = iImage
   RETURN SendMessageW(hListView, LVM_INSERTITEMW, iItem, CAST(LPARAM, @lvi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the insertion point closest to a specified point.
' ========================================================================================
PRIVATE FUNCTION CListView.InsertMarkHitTest (BYVAL hListView AS HWND, BYVAL ppt AS POINT PTR, BYVAL pvim AS LVINSERTMARK PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_INSERTMARKHITTEST, CAST(WPARAM, ppt), CAST(LPARAM, pvim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.InsertMarkHitTest (BYVAL hListView AS HWND, BYREF pt AS POINT, BYREF vim AS LVINSERTMARK) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_INSERTMARKHITTEST, CAST(WPARAM, @pt), CAST(LPARAM, @vim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks whether the list-view control has group view enabled.
' ========================================================================================
PRIVATE FUNCTION CListView.IsGroupViewEnabled (BYVAL hListView AS HWND) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_ISGROUPVIEWENABLED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Indicates whether an item in the list-view control is visible.
' ========================================================================================
PRIVATE FUNCTION CListView.IsItemVisible (BYVAL hListView AS HWND, BYVAL index AS UINT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_ISITEMVISIBLE, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps the ID of an item to an index.
' ========================================================================================
PRIVATE FUNCTION CListView.MapIDToIndex (BYVAL hListView AS HWND, BYVAL id AS UINT) AS UINT
   RETURN SendMessageW(hListView, LVM_MAPIDTOINDEX, id, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps the index of an item to a unique ID.
' ========================================================================================
PRIVATE FUNCTION CListView.MapIndexToID (BYVAL hListView AS HWND, BYVAL index AS UINT) AS UINT
   RETURN SendMessageW(hListView, LVM_MAPINDEXTOID, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'PRIVATE SUB CListView.MoveGroup (BYVAL hListView AS HWND, BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG, BYVAL toIndex AS LONG)
'   SendMessageW(hListView, LVM_MOVEGROUP, iGroupId, toIndex)
'END SUB
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'PRIVATE SUB ListView_MoveItemToGroup (BYVAL hListView AS HWND, BYVAL idItemFrom AS LONG, BYVAL idGroupTo AS LONG)
'   SendMessageW(hListView, LVM_MOVEITEMTOGROUP, idItemFrom, idGroupTo)
'END SUB
' ========================================================================================

' ========================================================================================
' * Forces a list-view control to redraw a range of items.
' ========================================================================================
PRIVATE FUNCTION CListView.RedrawItems (BYVAL hListView AS HWND, BYVAL iFirst AS LONG, BYVAL iLast AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_REDRAWITEMS, iFirst, iLast)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes all groups from a list-view control.
' ========================================================================================
PRIVATE SUB CListView.RemoveAllGroups (BYVAL hListView AS HWND)
   SendMessageW hListView, LVM_REMOVEALLGROUPS, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Removes a group from a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.RemoveGroup (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG) AS LONG
   RETURN SendMessageW(hListView, LVM_REMOVEGROUP, iGroupId, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Scrolls the content of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.Scroll (BYVAL hListView AS HWND, BYVAL dx AS LONG, BYVAL dy AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SCROLL, dx, dy)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the background color of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetBkColor (BYVAL hListView AS HWND, BYVAL clrBk AS COLORREF) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background image in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetBkImage (BYVAL hListView AS HWND, BYVAL pvbki AS LVBKIMAGE PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETBKIMAGE, 0, CAST(LPARAM, pvbki))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetBkImage (BYVAL hListView AS HWND, BYREF vbki AS LVBKIMAGE) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETBKIMAGE, 0, CAST(LPARAM, @vbki))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the callback mask for a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetCallbackMask (BYVAL hListView AS HWND, BYVAL mask AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETCALLBACKMASK, mask, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects or deselects an item in a list-view control.
' ========================================================================================
PRIVATE SUB CListView.SetCheckState (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYVAL fCheck AS BOOLEAN)
   DIM lvi AS LVITEM
   lvi.stateMask = LVIS_STATEIMAGEMASK
   lvi.state = INDEXTOSTATEIMAGEMASK(IIF(fCheck, 2, 1))
   SendMessageW hListView, LVM_SETITEMSTATE, iIndex, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the attributes of a list-view column.
' ========================================================================================
PRIVATE FUNCTION CListView.SetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETCOLUMNW, iCol, CAST(LPARAM, pcol))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETCOLUMNW, iCol, CAST(LPARAM, @col))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the left-to-right order of columns in a list-view control.
' ========================================================================================
PRIVATE SUB CListView.SetColumnOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS LONG, BYVAL prgi AS LONG PTR)
   SendMessageW(hListView, LVM_SETCOLUMNORDERARRAY, iCount, CAST(LPARAM, prgi))
END SUB
' ========================================================================================

' ========================================================================================
' * Used to change the width of a column in report view or the width of all columns in list-view mode.
' ========================================================================================
PRIVATE FUNCTION CListView.SetColumnWidth (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cx AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETCOLUMNWIDTH, iCol, MAKELONG(cx, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets extended styles for list-view controls
' ========================================================================================
PRIVATE SUB CListView.SetExtendedListViewStyle (BYVAL hListView AS HWND, BYVAL dwExStyle AS DWORD)
   SendMessageW hListView, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwExStyle
END SUB
' ========================================================================================

' ========================================================================================
' * Sets extended styles for list-view controls using the style mask.
' ========================================================================================
PRIVATE SUB CListView.SetExtendedListViewStyleEx (BYVAL hListView AS HWND, BYVAL dwExMask AS DWORD, BYVAL dwExStyle AS DWORD)
   SendMessageW hListView, LVM_SETEXTENDEDLISTVIEWSTYLE, dwExMask, dwExStyle
END SUB
' ========================================================================================
' ========================================================================================
' Assigns an image list to the group header of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetGroupHeaderImageList (BYVAL hListView AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_SETIMAGELIST, LVSIL_GROUPHEADER, CAST(LPARAM, himl)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets group information.
' ========================================================================================
PRIVATE FUNCTION CListView.SetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_SETGROUPINFO, iGroupId, CAST(LPARaM, pgrp))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYREF grp AS LVGROUP) AS LONG
   RETURN SendMessageW(hListView, LVM_SETGROUPINFO, iGroupId, CAST(LPARaM, @grp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information about the display of groups.
' ========================================================================================
PRIVATE SUB CListView.SetGroupMetrics (BYVAL hListView AS HWND, BYVAL pGroupMetrics AS LVGROUPMETRICS PTR)
   SendMessageW hListView, LVM_SETGROUPMETRICS, 0, CAST(LPARAM, pGroupMetrics)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.SetGroupMetrics (BYVAL hListView AS HWND, BYREF GroupMetrics AS LVGROUPMETRICS)
   SendMessageW hListView, LVM_SETGROUPMETRICS, 0, CAST(LPARAM, @GroupMetrics)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the state for a specified group.
' ========================================================================================
PRIVATE FUNCTION CListView.SetGroupState (BYVAL hListView AS HWND, BYVAL dwGroupId AS UINT, BYVAL dwMask AS UINT, BYVAL dwState AS UINT) AS LONG
   DIM lvg AS LVGROUP
   lvg.cbSize = SIZEOF(lvg)
   lvg.mask = LVGF_STATE
   lvg.stateMask = dwMask
   lvg.state = dwState
   RETURN SendMessageW(hListView, LVM_SETGROUPINFO, dwGroupId, CAST(LPARAM, @lvg))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the HCURSOR that the list-view control uses when the pointer is over an item while
' hot tracking is enabled.
' ========================================================================================
PRIVATE FUNCTION CListView.SetHotCursor (BYVAL hListView AS HWND, BYVAL hCur AS HCURSOR) AS HCURSOR
   RETURN CAST(HCURSOR, SendMessageW(hListView, LVM_SETHOTCURSOR, 0, CAST(LPARAM, hCur)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the hot item in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetHotItem (BYVAL hListView AS HWND, BYVAL iIndex AS DWORD) AS LONG
   RETURN SendMessageW(hListView, LVM_SETHOTITEM, iIndex, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the amount of time that the mouse cursor must hover over an item before it is selected.
' ========================================================================================
PRIVATE SUB CListView.SetHoverTime (BYVAL hListView AS HWND, BYVAL dwHoverTimeMs AS DWORD)
   SendMessageW(hListView, LVM_SETHOVERTIME, 0, dwHoverTimeMs)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the spacing between icons in list-view controls set to the LVS_ICON style.
' ========================================================================================
PRIVATE FUNCTION CListView.SetIconSpacing (BYVAL hListView AS HWND, BYVAL cx AS SHORT, BYVAL cy AS SHORT) AS DWORD
   RETURN SendMessageW(hListView, LVM_SETICONSPACING, 0, MAKELONG(cx, cy))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetImageList (BYVAL hListView AS HWND, BYVAL himl AS HIMAGELIST, BYVAL nImageList AS LONG) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hListView, LVM_SETIMAGELIST, nImageList, CAST(LPARAM, himl)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets tooltip text.
' ========================================================================================
PRIVATE FUNCTION CListView.SetInfoTip (BYVAL hListView AS HWND, BYVAL plvInfoTip AS LVSETINFOTIP PTR) AS BOOLEAN
   IF plvInfoTip = NULL THEN RETURN FALSE
   plvInfoTip->cbSize = SIZEOF(LVSETINFOTIP)
   RETURN SendMessageW(hListView, LVM_SETINFOTIP, 0, CAST(LPARAM, plvInfoTip))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetInfoTip (BYVAL hListView AS HWND, BYREF lvInfoTip AS LVSETINFOTIP) AS BOOLEAN
   lvInfoTip.cbSize = SIZEOF(LVSETINFOTIP)
   RETURN SendMessageW(hListView, LVM_SETINFOTIP, 0, CAST(LPARAM, @lvInfoTip))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the insertion point to the defined position.
' ========================================================================================
PRIVATE FUNCTION CListView.SetInsertMark (BYVAL hListView AS HWND, BYVAL plvim AS LVINSERTMARK PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETINSERTMARK, 0, CAST(LPARAM, plvim))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetInsertMark (BYVAL hListView AS HWND, BYREF lvim AS LVINSERTMARK) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETINSERTMARK, 0, CAST(LPARAM, @lvim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color of the insertion point.
' ========================================================================================
PRIVATE FUNCTION CListView.SetInsertMarkColor (BYVAL hListView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hListView, LVM_SETINSERTMARKCOLOR, 0, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets some or all of a list-view item's attributes. You can also use SetItem to set the text of a subitem.
' ========================================================================================
PRIVATE FUNCTION CListView.SetItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETITEM, 0, CAST(LPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETITEM, 0, CAST(LPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Causes the list-view control to allocate memory for the specified number of items.
' ========================================================================================
PRIVATE FUNCTION CListView.SetItemCount (BYVAL hListView AS HWND, BYVAL cItems AS LONG) AS LRESULT
   RETURN SendMessageW(hListView, LVM_SETITEMCOUNT, cItems, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the virtual number of items in a virtual list view.
' ========================================================================================
PRIVATE FUNCTION CListView.SetItemCountEx (BYVAL hListView AS HWND, BYVAL cItems AS LONG, BYVAL dwFlags AS LONG) AS LRESULT
   RETURN SendMessageW(hListView, LVM_SETITEMCOUNT, cItems, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves an item to a specified position in a list-view control (in icon or small icon view).
' ========================================================================================
PRIVATE FUNCTION CListView.SetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS SHORT, BYVAL y AS SHORT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETITEMPOSITION, i, MAKELONG(x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves an item to a specified position in a list-view control (in icon or small icon view).
' This method differs from the SetItemPosition method in that it uses 32-bit coordinates.
' ========================================================================================
PRIVATE SUB CListView.SetItemPosition32 (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG)
   DIM ptNewPos AS POINT
   ptNewPos.x = x
   ptNewPos.y = y
   SendMessageW hListView, LVM_SETITEMPOSITION32, i, CAST(LPARAM, @ptNewPos)
END SUB
' ========================================================================================

' ========================================================================================
' Changes the state of an item in a list-view control.
' ========================================================================================
PRIVATE SUB CListView.SetItemState (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL dwState AS DWORD, BYVAL mask AS DWORD)
   DIM lvi AS LVITEM
   lvi.stateMask = mask
   lvi.state = dwState
   SendMessageW hListView, LVM_SETITEMSTATE, i, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' * Changes the text of a list-view item or subitem.
' ========================================================================================
PRIVATE SUB CListView.SetItemText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL pwszText AS WSTRING PTR)
   DIM lvi AS LVITEMW
   lvi.iSubItem = iSubItem
   lvi.pszText = pwszText
   SendMessageW hListView, LVM_SETITEMTEXTW, i, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.SetText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF wszText AS WSTRING)
   DIM lvi AS LVITEMW
   lvi.pszText = @wszText
   SendMessageW hListView, LVM_SETITEMTEXTW, i, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the color of the border of a list-view control if the LVS_EX_BORDERSELECT extended
' window style is set.
' ========================================================================================
PRIVATE FUNCTION CListView.SetOutlineColor (BYVAL hListView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hListView, LVM_SETOUTLINECOLOR, 0, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the index of the selected column.
' ========================================================================================
PRIVATE SUB CListView.SetSelectedColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG)
   SendMessageW hListView, LVM_SETSELECTEDCOLUMN, iCol, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the selection mark in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetSelectionMark (BYVAL hListView AS HWND, BYVAL iIndex AS LONG) AS LONG
   RETURN SendMessageW(hListView, LVM_SETSELECTIONMARK, 0, iIndex)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the background color of text in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetTextBkColor (BYVAL hListView AS HWND, BYVAL clrTextBk AS COLORREF) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETTEXTBKCOLOR, 0, clrTextBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text color of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetTextColor (BYVAL hListView AS HWND, BYVAL clrText AS COLORREF) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETTEXTCOLOR, 0, clrText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information for an existing tile of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetTileInfo (BYVAL hListView AS HWND, BYVAL plvtinfo AS LVTILEINFO PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETTILEINFO, 0, CAST(LPARAM, plvtinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetTileInfo (BYVAL hListView AS HWND, BYREF lvtinfo AS LVTILEINFO) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETTILEINFO, 0, CAST(LPARAM, @lvtinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information that a list-view control uses in tile view.
' ========================================================================================
PRIVATE FUNCTION CListView.SetTileViewInfo (BYVAL hListView AS HWND, BYVAL plvtvinfo AS LVTILEVIEWINFO PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETTILEVIEWINFO, 0, CAST(LPARAM, plvtvinfo))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetTileViewInfo (BYVAL hListView AS HWND, BYREF lvtvinfo AS LVTILEVIEWINFO) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETTILEVIEWINFO, 0, CAST(LPARAM, @lvtvinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' This message is supported only through Microsoft Windows XP.
' Currently not supported.
' ========================================================================================
'PRIVATE FUNCTION CListView.SetTileWidth (BYVAL hListView AS HWND, BYVAL hwnd AS DWORD, BYVAL cpWidth AS DWORD) AS LONG
'   RETURN SendMessageW(hwnd, LVM_SETTILEWIDTH, cpWidth, 0)
'END FUNCTION
' ========================================================================================
 
 ' ========================================================================================
' Sets the ToolTip control that the list-view control will use to display tooltips.
' ========================================================================================
PRIVATE FUNCTION CListView.SetToolTips (BYVAL hListView AS HWND, BYVAL hwndToolTip AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hListView, LVM_SETTOOLTIPS, CAST(LPARAM, hwndToolTip), 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the view of a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SetView (BYVAL hListView AS HWND, BYVAL iView AS DWORD) AS LONG
   RETURN SendMessageW(hListView, LVM_SETVIEW, iView, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the working areas within a list-view control.
' ========================================================================================
PRIVATE SUB CListView.SetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYVAL prc AS RECT PTR)
   SendMessageW hListView, LVM_SETWORKAREAS, nWorkAreas, CAST(LPARAM, prc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CListView.SetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYREF rc AS RECT)
   SendMessageW hListView, LVM_SETWORKAREAS, nWorkAreas, CAST(LPARAM, @rc)
END SUB
' ========================================================================================

' ========================================================================================
' Uses an application-defined comparison function to sort groups by ID within a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.SortGroups (BYVAL hListView AS HWND, BYVAL _pfnGroupCompare AS PFNLVGROUPCOMPARE PTR, BYVAL _plv AS ANY PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SORTGROUPS, CAST(WPARAM, _pfnGroupCompare), CAST(LPARAM, _plv))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Uses an application-defined comparison function to sort the items of a list-view control.
' The index of each item changes to reflect the new sequence.
' ========================================================================================
PRIVATE FUNCTION CListView.SortItems (BYVAL hListView AS HWND, BYVAL _pfnCompare AS PFNLVCOMPARE PTR, BYVAL _lPrm AS LPARAM) AS LONG
   RETURN SendMessageW(hListView, LVM_SORTITEMS, CAST(WPARAM, _lPrm), CAST(LPARAM, _pfnCompare))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Uses an application-defined comparison function to sort the items of a list-view control.
' The index of each item changes to reflect the new sequence.
' ========================================================================================
PRIVATE FUNCTION CListView.SortItemsEx (BYVAL hListView AS HWND, BYVAL _pfnCompare AS PFNLVCOMPARE PTR, BYVAL _lPrm AS LPARAM) AS LONG
   RETURN SendMessageW(hListView, LVM_SORTITEMSEX, CAST(WPARAM, _lPrm), CAST(LPARAM, _pfnCompare))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item or subitem is located at a given position.
' ========================================================================================
PRIVATE FUNCTION CListView.SubItemHitTest (BYVAL hListView AS HWND, BYVAL plvhti AS LVHITTESTINFO PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_SUBITEMHITTEST, 0, CAST(LPARAM, plvhti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SubItemHitTest (BYVAL hListView AS HWND, BYREF lvhti AS LVHITTESTINFO) AS LONG
   RETURN SendMessageW(hListView, LVM_SUBITEMHITTEST, 0, CAST(LPARAM, @lvhti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item or subitem is located at a given position.
' ========================================================================================
PRIVATE FUNCTION CListView.SubItemHitTestEx (BYVAL hListView AS HWND, BYVAL plvhti AS LVHITTESTINFO PTR) AS LONG
   RETURN SendMessageW(hListView, LVM_SUBITEMHITTEST, -1, CAST(LPARAM, plvhti))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SubItemHitTestEx (BYVAL hListView AS HWND, BYREF lvhti AS LVHITTESTINFO) AS LONG
   RETURN SendMessageW(hListView, LVM_SUBITEMHITTEST, -1, CAST(LPARAM, @lvhti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Updates a list-view item. If the list-view control has the LVS_AUTOARRANGE style, this
' method causes the list-view control to be arranged.
' ========================================================================================
PRIVATE FUNCTION CListView.Update (BYVAL hListView AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_UPDATE, iItem, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################


' ========================================================================================
' * Selects a ListView item.
' Windows does not provide a separate message or function to set the current selection in
' a listview. Instead, it defines item states or LVIS_* values that determine the listview
' item's appearance and functionality. LVIS_FOCUSED and LVIS_SELECTED in particular are
' the states that determine a listview item's selection state.
' Note that the last parameter passed to this method is a mask specifying which bits are
' about to change. LVIS_FOCUSED and LVIS_SELECTED are defined in commctrl.inc as &H0001
' and &H0002 respectively, so you need to set the last four bits of the mask.
' See the following Microsoft article: How To Select a Listview Item Programmatically
' http://support.microsoft.com/kb/131284
' ========================================================================================
PRIVATE SUB CListView.SelectItem (BYVAL hListView AS HWND, BYVAL iIndex AS LONG)
   DIM lvi AS LVITEM
   lvi.stateMask = &h000F
   lvi.state = LVIS_FOCUSED OR LVIS_SELECTED
   SendMessageW hListView, LVM_SETITEMSTATE, iIndex, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' * Selects all items.
' ========================================================================================
PRIVATE SUB CListView.SelectAllItems (BYVAL hListView AS HWND)
   DIM lvi AS LVITEM
   lvi.mask = LVIF_STATE
   lvi.state = -1
   lvi.stateMask = LVIS_SELECTED
   SendMessageW hListView, LVM_SETITEMSTATE, -1, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' * Unselects an item in a ListView.
' ========================================================================================
PRIVATE SUB CListView.UnselectItem (BYVAL hListView AS HWND, BYVAL iIndex AS LONG)
   DIM lvi AS LVITEM
   lvi.mask = LVIF_STATE
   lvi.state = 0
   lvi.statemask = LVIS_SELECTED
   SendMessageW hListView, LVM_SETITEMSTATE, iIndex, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' * Unselects all items.
' ========================================================================================
PRIVATE SUB CListView.UnselectAllItems (BYVAL hListView AS HWND)
   DIM lvi AS LVITEM
   lvi.stateMask = LVIS_SELECTED OR LVIS_FOCUSED
   lvi.state = 0
   SendMessageW hListView, LVM_SETITEMSTATE, -1, CAST(LPARAM, @lvi)
END SUB
' ========================================================================================

' ========================================================================================
' * Removes the HDS_BUTTONS style from the header control to give it a flat appearance.
' ========================================================================================
PRIVATE SUB CListView.MakeHeaderFlat (BYVAL hListView AS HWND)
   DIM hLvHeader AS HWND
   hLvHeader = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN EXIT SUB
   SetWindowLong hLvHeader, GWL_STYLE, GetWindowLong(hLvHeader, GWL_STYLE) XOR HDS_BUTTONS
   SetWindowPos GetParent(hListView), NULL, 0, 0, 0, 0, SWP_NOZORDER OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_DRAWFRAME
END SUB
' ========================================================================================

' ========================================================================================
' * Automatically sizes the specified column.
' ========================================================================================
PRIVATE FUNCTION CListView.FitContent (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETCOLUMNWIDTH, iCol, LVSCW_AUTOSIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Automatically sizes all the columns of a listview
' ========================================================================================
PRIVATE FUNCTION CListView.AutoSizeColumns (BYVAL hListView AS HWND) AS BOOLEAN
   DIM AS LONG i, nCount
   DIM hLvHeader AS HWND
   hLvHeader = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN EXIT FUNCTION
   nCount = SendMessageW(hLvHeader, HDM_GETITEMCOUNT, 0, 0)
   FOR i = 0 TO nCount - 1
      FUNCTION = SendMessageW(hListView, LVM_SETCOLUMNWIDTH, i, LVSCW_AUTOSIZE)
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Automatically sizes the column to fit the header text. If you use this value with the
' last column, its width is set to fill the remaining width of the list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.FitHeader (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_SETCOLUMNWIDTH, iCol, LVSCW_AUTOSIZE_USEHEADER)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Automatically sizes all the columns of the header of a listview
' ========================================================================================
PRIVATE FUNCTION CListView.AutoSizeHeader (BYVAL hListView AS HWND) AS BOOLEAN
   DIM AS LONG i, nCount
   DIM hLvHeader AS HWND
   hLvHeader = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN EXIT FUNCTION
   nCount = SendMessageW(hLvHeader, HDM_GETITEMCOUNT, 0, 0)
   FOR i = 0 TO nCount - 1
      FUNCTION = SendMessageW(hListView, LVM_SETCOLUMNWIDTH, i, LVSCW_AUTOSIZE_USEHEADER)
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the number of columns of a listview.
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumnCount (BYVAL hListView AS HWND) AS LONG
   DIM hLvHeader AS HWND = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN EXIT FUNCTION
   RETURN SendMessageW(hLvHeader, HDM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the text of the specified column of the header of a listview control.
' - hCtl Handle to the ListView control.
' - nCol: Zero-based index of the column
' - cchTextMax : Maximum number of characters to return. Both this value and the size of the
'   buffer pointed by pwszText must be one character bigger that the wanted length of the text
'   to return to make room for the null character terminator.
' ========================================================================================
PRIVATE FUNCTION CListView.GetHeaderText (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
   DIM hLvHeader AS HWND = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN RETURN ""
   DIM dwsText AS DWSTRING
   IF cchTextMax < 1 THEN cchTextMax = MAX_PATH + 1
   dwsText = WSPACE(cchTextMax + 1)
   DIM hdi AS HDITEMW
   hdi.mask = HDI_TEXT
   hdi.cchTextMax = cchTextMax + 1
   hdi.pszText = *dwsText
   SendMessageW(hLvHeader, HDM_GETITEMW, iCol, CAST(LPARAM, @hdi))
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Gets the order of the specified column of the listview's header control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetColumnOrder (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LONG
   DIM hLvHeader AS HWND = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN RETURN 0
   DIM hdi AS HDITEMW
   hdi.mask = HDI_ORDER
   SendMessageW(hLvHeader, HDM_GETITEM, iCol, CAST(LPARAM, @hdi))
   RETURN hdi.iOrder
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current left-to-right order of items in the header of a listview control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS DWORD, BYVAL lpi AS LONG PTR) AS LONG
   DIM hLvHeader AS HWND = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN RETURN 0
   RETURN SendMessageW(hLvHeader, HDM_GETORDERARRAY, iCount, CAST(LPARAM, lpi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the font used by the ToolTip control that the list-view control uses to display tooltips.
' The return value is a handle to the font used by the control, or NULL if the control is
' using the system font.
' ========================================================================================
PRIVATE FUNCTION CListView.GetTooltipsFont (BYVAL hListView AS HWND) AS HFONT
   DIM hwndTooltips AS HWND = CAST(HWND, SendMessageW(hListView, LVM_GETTOOLTIPS, 0, 0))
   FUNCTION = CAST(HFONT, SendMessageW(hwndTooltips, WM_GETFONT, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font used by the ToolTip control that the list-view control uses to display tooltips.
' Parameters:
' - hCtl    = Handle to the ListView control.
' - hFont   = Handle to the font. If this parameter is NULL, the control uses the default system font to draw text.
' - fRedraw = Specifies whether the control should be redrawn immediately upon setting the font.
'             If this parameter is TRUE, the control redraws itself.
' ========================================================================================
PRIVATE SUB CListView.SetTooltipsFont (BYVAL hListView AS HWND, BYVAL hFont AS HFONT = NULL, BYVAL fRedraw AS BOOLEAN = FALSE)
   DIM hwndTooltips AS HWND = CAST(HWND, SendMessageW(hListView, LVM_GETTOOLTIPS, 0, 0))
   IF hwndTooltips = NULL THEN EXIT SUB
   SendMessageW(hwndTooltips, WM_SETFONT, CAST(WPARAM, hFont), fRedraw)
END SUB
' ========================================================================================


' ========================================================================================
PRIVATE FUNCTION CListView.SetHeaderFont ( _
   BYVAL hListView AS HWND, _        ' ListView handle
   BYREF wszFaceName AS WSTRING, _   ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS HFONT                        ' Handle of font or NULL on failure.

   DIM hLvHeader AS HWND
   DIM hLvHeaderFont AS HFONT
   DIM hOldFont AS HFONT
   DIM lf AS LOGFONTW
   DIM hDC AS HDC

   ' // Get the handle of the header
   hLvHeader = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN RETURN NULL

   ' // Create the font
   hDC = GetDC(HWND_DESKTOP)
   lf.lfHeight         = -MulDiv(lPointSize, GetDeviceCaps(hDC, LOGPIXELSY), 72) ' logical font height
   lf.lfWidth          =  0                                                       ' average character width
   lf.lfEscapement     =  0                                                       ' escapement
   lf.lfOrientation    =  0                                                       ' orientation angles
   lf.lfWeight         =  lWeight                                                 ' font weight
   lf.lfItalic         =  bItalic                                                 ' italic(TRUE/FALSE)
   lf.lfUnderline      =  bUnderline                                              ' underline(TRUE/FALSE)
   lf.lfStrikeOut      =  bStrikeOut                                              ' strikeout(TRUE/FALSE)
   lf.lfCharSet        =  bCharset                                                ' character set
   lf.lfOutPrecision   =  OUT_TT_PRECIS                                           ' output precision
   lf.lfClipPrecision  =  CLIP_DEFAULT_PRECIS                                     ' clipping precision
   lf.lfQuality        =  DEFAULT_QUALITY                                         ' output quality
   lf.lfPitchAndFamily =  FF_DONTCARE                                             ' pitch and family
   lf.lfFaceName       =  wszFaceName                                             ' typeface name
   ReleaseDC HWND_DESKTOP, hDC
   hLvHeaderFont = CreateFontIndirectW(@lf)
   IF hLvHeaderFont = NULL THEN RETURN NULL

   ' // Select the font
   hDC = GetDC(hLvHeader)
   hOldFont = SelectObject(hDC, hLvHeaderFont)
   ReleaseDC (hLvHeader, hDC)
   SendMessageW(CAST(HWND, hLvHeader), WM_SETFONT, CAST(WPARAM, hLvHeaderFont), TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   RETURN hLvHeaderFont

END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the font used by the listview header.
' Only the passed values that are not an empty string or zero will be modified.
' Note: The returned font must be destroyed with DeleteObject when no longer needed to prevent memory leaks.
' ========================================================================================
PRIVATE FUNCTION CListView.ModifyHeaderFont ( _
   BYVAL hListView AS HWND, _        ' ListView handle
   BYREF wszFaceName AS WSTRING, _   ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS HFONT                        ' Handle of font or NULL on failure.

   DIM hLvHeader AS HWND
   DIM hLvHeaderFont AS HFONT
   DIM hCurFont AS HFONT
   DIM hOldFont AS HFONT
   DIM lf AS LOGFONTW
   DIM hDC AS HDC

   ' // Get the handle of the header
   hLvHeader = CAST(HWND, SendMessageW(hListView, LVM_GETHEADER, 0, 0))
   IF hLvHeader = 0 THEN RETURN NULL

   ' // Get the handle of the font used by the header
   hCurFont = CAST(HFONT, SendMessageW(hLvHeader, WM_GETFONT, 0, 0))
   IF hCurFont = NULL THEN EXIT FUNCTION
   ' // Get the LOGFONT structure
   IF GetObjectW(hCurFont, SIZEOF(lf), @lf) = 0 THEN RETURN NULL

   ' // Change the requested values
   IF lPointSize THEN
      hDC = GetDC(HWND_DESKTOP)
      lf.lfHeight = -MulDiv(lPointSize, GetDeviceCaps(hDC, LOGPIXELSY), 72)
      ReleaseDC HWND_DESKTOP, hDC
   END IF
   IF lWeight THEN lf.lfWeight =  lWeight
   IF bItalic THEN lf.lfItalic =  bItalic
   IF bUnderline THEN lf.lfUnderline =  bUnderline
   IF bStrikeOut THEN lf.lfStrikeOut =  bStrikeOut
   IF bCharset THEN lf.lfCharSet =  bCharset
   IF wszFaceName <> "" THEN lf.lfFaceName =  wszFaceName

   ' // Create the font
   hLvHeaderFont = CreateFontIndirectW(@lf)
   IF hLvHeaderFont = 0 THEN EXIT FUNCTION

   ' // Select the font
   hDC = GetDC(hLvHeader)
   hOldFont = SelectObject(hDC, hLvHeaderFont)
   ReleaseDC (hLvHeader, hDC)
   SendMessageW(hLvHeader, WM_SETFONT, CAST(WPARAM, hLvHeaderFont), TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   RETURN hLvHeaderFont

END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Gets information on the footer of a specified list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterInfo (BYVAL hListView AS HWND, BYVAL pvfi AS LVFOOTERINFO PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERINFO, 0, CAST(LPARAM, pvfi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterInfo (BYVAL hListView AS HWND, BYREF vfi AS LVFOOTERINFO) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERINFO, 0, CAST(LPARAM, @vfi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterInfo (BYVAL hListView AS HWND) AS LVFOOTERINFO
   DIM vfi AS LVFOOTERINFO
   SendMessageW(hListView, LVM_GETFOOTERINFO, 0, CAST(LPARAM, @vfi))
   RETURN vfi
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information on a footer item for a specified list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL pfi AS LVFOOTERITEM PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERITEM, iItem, CAST(LPARAM, pfi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYREF fi AS LVFOOTERITEM) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERITEM, iItem, CAST(LPARAM, @fi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS UINT) AS LVFOOTERITEM
   DIM fi AS LVFOOTERITEM
   SendMessageW(hListView, LVM_GETFOOTERITEM, iItem, CAST(LPARAM, @fi))
   RETURN fi
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the coordinates of a footer for a specified item in a list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERITEMRECT, iItem, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERITEMRECT, iItem, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT) AS RECT
   DIM rc AS RECT
   SendMessageW(hListView, LVM_GETFOOTERITEMRECT, iItem, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================
' ========================================================================================
' Gets the bounding rectangle for all or part of a subitem in the current view of a
' specified list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemIndexRect (BYVAL hListView AS HWND, BYVAL pvii AS LVITEMINDEX PTR, BYVAL iSubItem AS LONG, BYVAL code AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
   prc->Top = iSubItem : prc->Left = Code
   RETURN SendMessageW(hListView, LVM_GETITEMINDEXRECT, CAST(WPARAM, pvii), CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemIndexRect (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL iSubItem AS LONG, BYVAL code AS LONG, BYREF rc AS RECT) AS BOOLEAN
   rc.Top = iSubItem : rc.Left = Code
   RETURN SendMessageW(hListView, LVM_GETITEMINDEXRECT, CAST(WPARAM, @lvii), CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetItemIndexRect (BYVAL hListView AS HWND, BYREF vii AS LVITEMINDEX, BYVAL iSubItem AS LONG, BYVAL code AS LONG) AS RECT
   dim rc AS RECT: rc.Top = iSubItem : rc.Left = Code
   SendMessageW(hListView, LVM_GETITEMINDEXRECT, CAST(WPARAM, @vii), CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the item in a particular list-view control that has the specified
' properties and relationship to another specific item.
' ========================================================================================
PRIVATE FUNCTION CListView.GetNextItemIndex (BYVAL hListView AS HWND, BYVAL plvii AS LVITEMINDEX PTR, BYVAL flags AS ..LPARAM) AS LONG
   RETURN SendMessageW(hListView, LVM_GETNEXTITEMINDEX, CAST(WPARAM, plvii), flags)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetNextItemIndex (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL flags AS ..LPARAM) AS LONG
   RETURN SendMessageW(hListView, LVM_GETNEXTITEMINDEX, CAST(WPARAM, @lvii), flags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the state of a specified list-view item.
' ========================================================================================
PRIVATE FUNCTION CListView.SetItemIndexState (BYVAL hListView AS HWND, BYVAL plvii AS LVITEMINDEX PTR, BYVAL dwData AS UINT, BYVAL mask AS UINT) AS HRESULT
   DIM lvi AS LVITEMW
   lvi.stateMask = mask
   lvi.state = dwData
   RETURN SendMessageW(hListView, LVM_SETITEMINDEXSTATE, CAST(WPARAM, plvii), Cast(LPARAM, @lvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.SetItemIndexState (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL dwData AS UINT, BYVAL mask AS UINT) AS HRESULT
   DIM lvi AS LVITEMW
   lvi.stateMask = mask
   lvi.state = dwData
   RETURN SendMessageW(hListView, LVM_SETITEMINDEXSTATE, CAST(WPARAM, @lvii), Cast(LPARAM, @lvi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text meant for display when the list-view control appears empty.
' ========================================================================================
PRIVATE FUNCTION CListView.GetEmptyText (BYVAL hListView AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETEMPTYTEXT, cchText, CAST(LPARAM, pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the coordinates of the footer for a specified list-view control.
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERRECT, 0, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS BOOLEAN
   RETURN SendMessageW(hListView, LVM_GETFOOTERRECT, 0, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CListView.GetFooterRect (BYVAL hListView AS HWND) AS RECT
   DIM rc AS RECT
   SendMessageW(hListView, LVM_GETFOOTERRECT, 0, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

#endif

' ========================================================================================
' Sets the listview dark mode.
' ========================================================================================
PRIVATE FUNCTION CListView.SetDarkMode (BYVAL hListView AS HWND) AS HRESULT
   RETURN SetWindowTheme(hListView, "DarkMode_Explorer", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Removes the listview dark mode.
' ========================================================================================
PRIVATE FUNCTION CListView.RemoveDarkMode (BYVAL hListView AS HWND) AS HRESULT
   RETURN SetWindowTheme(hListView, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
