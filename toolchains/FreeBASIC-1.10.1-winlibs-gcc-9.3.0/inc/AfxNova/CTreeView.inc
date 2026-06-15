' ########################################################################################
' Platform: Microsoft Windows
' Filename: CTreeView.inc
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
' // conflicting defines in windowsx.bi
#undef GetNextSibling
#undef GetPrevSibling
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
' CTreeView class
' ########################################################################################

TYPE CTreeView

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:
   DECLARE STATIC FUNCTION AddRootItem (BYVAL hTreeView AS HWND, BYVAL pwszText AS WSTRING PTR, _
      BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   DECLARE STATIC FUNCTION AppendItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
      BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   DECLARE STATIC FUNCTION Collapse (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC SUB CollapseAllItems (BYVAL hTreeView AS HWND)
   DECLARE STATIC SUB CollapseAllChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DECLARE STATIC SUB CollapseChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DECLARE STATIC FUNCTION CollapseReset (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC SUB CollapseSiblings (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DECLARE STATIC FUNCTION CreateDragImage (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HIMAGELIST
   DECLARE STATIC FUNCTION DeleteAllItems (BYVAL hTreeView AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION Reset (BYVAL hTreeView AS HWND) AS BOOLEAN
   DECLARE STATIC FUNCTION DeleteItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION EditLabel (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HWND
   DECLARE STATIC FUNCTION EndEditLabelNow (BYVAL hTreeView AS HWND, BYVAL fCancel AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION EnsureVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION Expand (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION Expand (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC SUB ExpandAllChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DECLARE STATIC SUB ExpandAllItems (BYVAL hTreeView AS HWND)
   DECLARE STATIC SUB ExpandChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DECLARE STATIC FUNCTION ExpandPartial (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC SUB ExpandSiblings (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DECLARE STATIC FUNCTION GetBkColor (BYVAL hTreeView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetBold (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCheck (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION GetCheckState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS UINT
   DECLARE STATIC FUNCTION GetChild (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetCount (BYVAL hTreeView AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetDropHilight (BYVAL hTreeView AS HWND) AS HTREEITEM
   DECLARE STATIC FUNCTION GetEditControl (BYVAL hTreeView AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetExtendedStyle (BYVAL hTreeView AS HWND) AS DWORD
   DECLARE STATIC FUNCTION GetFirstVisible (BYVAL hTreeView AS HWND) AS HTREEITEM
   DECLARE STATIC FUNCTION GetImageList (BYVAL hTreeView AS HWND, BYVAL iImage AS LONG) AS HIMAGELIST
   DECLARE STATIC FUNCTION GetIndent (BYVAL hTreeView AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetInsertMarkColor (BYVAL hTreeView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetISearchString (BYVAL hTreeView AS HWND, BYVAL pwsz AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetISearchString (BYVAL hTreeView AS HWND) AS DWSTRING
   DECLARE STATIC FUNCTION GetISearchStringLen (BYVAL hTreeView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItem (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItem (BYVAL hTreeView AS HWND, BYREF item AS TVITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemEx (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMEXW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemEx (BYVAL hTreeView AS HWND, BYREF item AS TVITEMEXW) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemHeight (BYVAL hTreeView AS HWND) AS LONG
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYREF rc AS RECT, BYVAL code AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL prc AS RECT PTR, BYVAL code AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS BOOLEAN) AS RECT
   DECLARE STATIC FUNCTION GetItemState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL mask AS UINT) AS UINT
   DECLARE STATIC FUNCTION GetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR, BYVAL cchtextmax AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL cchTextMax AS LONG = 0) AS DWSTRING
   DECLARE STATIC FUNCTION GetLastVisible (BYVAL hTreeView AS HWND) AS HTREEITEM
   DECLARE STATIC FUNCTION GetLineColor (BYVAL hTreeView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetlParam (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS LPARAM
   DECLARE STATIC FUNCTION GetSelect (BYVAL hTreeView AS HWND) AS HTREEITEM
   DECLARE STATIC FUNCTION GetSelection (BYVAL hTreeView AS HWND) AS HTREEITEM
   DECLARE STATIC FUNCTION GetNext (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetNextItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS HTREEITEM
   DECLARE STATIC FUNCTION GetNextSelected (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetNextSibling (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetNextVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetParent (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetParentText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION GetParentText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL cchTextMax AS LONG = 0) AS DWSTRING
   DECLARE STATIC FUNCTION GetPrevSibling (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetPrevious (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetPrevVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   DECLARE STATIC FUNCTION GetRoot (BYVAL hTreeView AS HWND) AS HTREEITEM
   DECLARE STATIC FUNCTION GetScrollTime (BYVAL hTreeView AS HWND) AS UINT
   DECLARE STATIC FUNCTION GetTextColor (BYVAL hTreeView AS HWND) AS COLORREF
   DECLARE STATIC FUNCTION GetToolTips (BYVAL hTreeView AS HWND) AS HWND
   DECLARE STATIC FUNCTION GetVisibleCount (BYVAL hTreeView AS HWND) AS UINT
   DECLARE STATIC FUNCTION HitTest (BYVAL hTreeView AS HWND, BYVAL pht AS TVHITTESTINFO PTR) AS HTREEITEM
   DECLARE STATIC FUNCTION HitTest (BYVAL hTreeView AS HWND, BYREF ht AS TVHITTESTINFO) AS HTREEITEM
   DECLARE STATIC FUNCTION InsertItem (BYVAL hTreeView AS HWND, BYVAL pisw AS TVINSERTSTRUCTW PTR) AS HTREEITEM
   DECLARE STATIC FUNCTION InsertItem (BYVAL hTreeView AS HWND, BYREF isw AS TVINSERTSTRUCTW) AS HTREEITEM
   DECLARE STATIC FUNCTION Insert (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL hInsertAfter AS HTREEITEM, _
      BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0, BYVAL pwszText AS WSTRING PTR) AS HTREEITEM
   DECLARE STATIC FUNCTION InsertItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL hInsertAfter AS HTREEITEM, _
      BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   DECLARE STATIC FUNCTION InsertFirstItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
      BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   DECLARE STATIC FUNCTION InsertSortedItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
      BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   DECLARE STATIC FUNCTION IsItemChecked (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION ItemExists (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION ItemExistsIgnoreCase (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION MapAccIDToHTREEITEM (BYVAL hTreeView AS HWND, BYVAL id AS UINT) AS HTREEITEM
   DECLARE STATIC FUNCTION MapHTREEITEMToAccID (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS UINT
   DECLARE STATIC FUNCTION SelectDropTarget (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION SelectItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION SelectItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS BOOLEAN
   DECLARE STATIC FUNCTION SelectSetFirstVisible (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION SetAutoScrollInfo (BYVAL hTreeView AS HWND, BYVAL uPixPerSec AS UINT, BYVAL uUpdateTime AS UINT) AS LRESULT
   DECLARE STATIC FUNCTION SetBkColor (BYVAL hTreeView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC SUB SetBold (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fBold AS BOOLEAN)
   DECLARE STATIC SUB SetCheck (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fCheck AS BOOLEAN)
   DECLARE STATIC SUB SetCheckState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fCheck AS BOOLEAN)
   DECLARE STATIC FUNCTION SetExtendedStyle (BYVAL hTreeView AS HWND, BYVAL dwExStyle AS DWORD, BYVAL mask AS UINT) AS HRESULT
   DECLARE STATIC FUNCTION SetImageList (BYVAL hTreeView AS HWND, BYVAL himl AS HIMAGELIST, BYVAL iImage AS LONG) AS HIMAGELIST
   DECLARE STATIC FUNCTION SetIndent (BYVAL hTreeView AS HWND, BYVAL indent AS LONG) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInsertMark (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fAfter AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION SetInsertMarkColor (BYVAL hTreeView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION SetItem (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItem (BYVAL hTreeView AS HWND, BYREF item AS TVITEMW) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemEx (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMEXW PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemEx (BYVAL hTreeView AS HWND, BYREF item AS TVITEMEXW) AS BOOLEAN
   DECLARE STATIC FUNCTION SetItemHeight (BYVAL hTreeView AS HWND, BYVAL cyItem AS SHORT) AS LONG
   DECLARE STATIC SUB SetItemState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL state AS UINT, BYVAL statemask AS UINT)
   DECLARE STATIC FUNCTION SetLineColor (BYVAL hTreeView AS HWND, BYVAL clrLine AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION SetScrollTime (BYVAL hTreeView AS HWND, BYVAL uMaxScrollTime AS UINT) AS UINT
   DECLARE STATIC FUNCTION SetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DECLARE STATIC FUNCTION SetTextColor (BYVAL hTreeView AS HWND, BYVAL clrText AS COLORREF) AS COLORREF
   DECLARE STATIC FUNCTION SetToolTips (BYVAL hTreeView AS HWND, BYVAL hwndTT AS HWND) AS HWND
   DECLARE STATIC FUNCTION Toggle (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   DECLARE STATIC FUNCTION UnSelect (BYVAL hTreeView AS HWND) AS BOOLEAN

   DECLARE STATIC FUNCTION SortChildren (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM, BYVAL fRecurse AS BOOLEAN) AS BOOLEAN
   DECLARE STATIC FUNCTION SortChildrenCB (BYVAL hTreeView AS HWND, BYVAL psort AS TVSORTCB PTR, BYVAL fRecurse AS BOOLEAN) AS BOOLEAN

#if _WIN32_WINNT >= &h0600
   DECLARE STATIC FUNCTION GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYREF rc AS RECT, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL prc AS RECT PTR, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS BOOLEAN
   DECLARE STATIC FUNCTION GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS RECT
   DECLARE STATIC FUNCTION ShowInfoTip (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM) AS DWORD
#endif

   DECLARE STATIC FUNCTION SetDarkMode(BYVAL hTreeView AS HWND) AS HRESULT
   DECLARE STATIC FUNCTION RemoveDarkMode(BYVAL hTreeView AS HWND) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CTreeView
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CTreeView
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Retrieves some or all of a treeview item's attributes.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItem (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_GETITEMW, 0, cast(LPARAM, pitem))
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItem (BYVAL hTreeView AS HWND, BYREF item AS TVITEMW) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_GETITEMW, 0, cast(LPARAM, @item))
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemEx (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMEXW PTR) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_GETITEMW, 0, cast(LPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemEx (BYVAL hTreeView AS HWND, BYREF item AS TVITEMEXW) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_GETITEMW, 0, cast(LPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.InsertItem (BYVAL hTreeView AS HWND, BYVAL pisw AS TVINSERTSTRUCTW PTR) AS HTREEITEM
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_INSERTITEMW, 0, CAST(LPARAM, CAST(TVINSERTSTRUCTW PTR, pisw))))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.InsertItem (BYVAL hTreeView AS HWND, BYREF isw AS TVINSERTSTRUCTW) AS HTREEITEM
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_INSERTITEMW, 0, CAST(LPARAM, CAST(TVINSERTSTRUCTW PTR, @isw))))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.InsertItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL hInsertAfter AS HTREEITEM, _
BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   DIM tvinsert AS TVINSERTSTRUCTW
   tvinsert.hParent             = hParent
   tvinsert.hInsertAfter        = hInsertAfter
   tvinsert.Item.iImage         = iImage
   tvinsert.Item.iSelectedImage = iSelectedImage
   tvinsert.Item.lParam         = lParam
   tvinsert.Item.mask           = TVIF_TEXT OR TVIF_IMAGE OR TVIF_SELECTEDIMAGE OR TVIF_PARAM
   tvinsert.Item.pszText        = pwszText
   IF pwszText <> LPSTR_TEXTCALLBACK THEN
      tvinsert.Item.cchTextMax  = LEN(*pwszText)
   END IF
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_INSERTITEMW, 0, CAST(..LPARAM, CAST(TVINSERTSTRUCTW PTR, @tvinsert))))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.Insert (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL hInsertAfter AS HTREEITEM, _
BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0, BYVAL pwszText AS WSTRING PTR) AS HTREEITEM
   DIM tvinsert AS TVINSERTSTRUCTW
   tvinsert.hParent             = hParent
   tvinsert.hInsertAfter        = hInsertAfter
   tvinsert.Item.iImage         = iImage
   tvinsert.Item.iSelectedImage = iSelectedImage
   tvinsert.Item.lParam         = 0
   tvinsert.Item.mask           = TVIF_TEXT OR TVIF_IMAGE OR TVIF_SELECTEDIMAGE OR TVIF_PARAM
   tvinsert.Item.pszText        = pwszText
   IF pwszText <> LPSTR_TEXTCALLBACK THEN
      tvinsert.Item.cchTextMax  = LEN(*pwszText)
   END IF
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_INSERTITEMW, 0, CAST(..LPARAM, CAST(TVINSERTSTRUCTW PTR, @tvinsert))))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Inserts the item at the end of the list in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.AppendItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   RETURN CTreeView.InsertItem(hTreeView, hParent, TVI_LAST, pwszText, lParam, iImage, iSelectedImage)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Inserts the item at the beginning of the list in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.InsertFirstItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   RETURN CTreeView.InsertItem(hTreeView, hParent, TVI_FIRST, pwszText, lParam, iImage, iSelectedImage)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Adds the item as the root item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.AddRootItem (BYVAL hTreeView AS HWND, BYVAL pwszText AS WSTRING PTR, _
BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   RETURN CTreeView.InsertItem(hTreeView, NULL, TVI_ROOT, pwszText, lParam, iImage, iSelectedImage)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Inserts the item into the list in alphabetical order.
' ========================================================================================
PRIVATE FUNCTION CTreeView.InsertSortedItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
   RETURN CTreeView.InsertItem(hTreeView, hParent, TVI_SORT, pwszText, lParam, iImage, iSelectedImage)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes an item and all its children from a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.DeleteItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_DELETEITEM, 0, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Deletes all items from a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.DeleteAllItems (BYVAL hTreeView AS HWND) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_DELETEITEM, 0, CAST(LPARAM, TVI_ROOT))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Deletes all items from a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.Reset (BYVAL hTreeView AS HWND) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_DELETEITEM, 0, CAST(LPARAM, TVI_ROOT))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Expands or collapses the list of child items associated with the specified parent item, if any.
' ========================================================================================
PRIVATE FUNCTION CTreeView.Expand (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_EXPAND, code, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Expands the list
' ========================================================================================
PRIVATE FUNCTION CTreeView.Expand (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_EXPAND, TVE_EXPAND, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Partially expands the list
' ========================================================================================
PRIVATE FUNCTION CTreeView.ExpandPartial (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_EXPAND, TVE_EXPAND OR TVE_EXPANDPARTIAL, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Collapses the list
' ========================================================================================
PRIVATE FUNCTION CTreeView.Collapse (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_EXPAND, TVE_COLLAPSE, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Collapses the list and removes the child items.
' ========================================================================================
PRIVATE FUNCTION CTreeView.CollapseReset (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_EXPAND, TVE_COLLAPSE OR TVE_COLLAPSERESET, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Collapses the list if it is expanded or expands it if it is collapsed.
' ========================================================================================
PRIVATE FUNCTION CTreeView.Toggle (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_EXPAND, TVE_TOGGLE, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Expands the list of child items, if any, associated with the specified parent node.
' ========================================================================================
PRIVATE SUB CTreeView.ExpandChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DIM hChildNode AS HTREEITEM
   DO WHILE hNode
      ' // Expand the node
      CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)
      ' // Get the first child node
      hChildNode = CTreeView.GetChild(hTreeView, hNode)
      IF hChildNode THEN CTreeView.ExpandChildItems(hTreeView, hChildNode)
      hNode = NULL
   LOOP
END SUB
' ========================================================================================
' ========================================================================================
' Expands the list of child items, if any, associated with the specified parent node and
' the sibling nodes below it.
' ========================================================================================
PRIVATE SUB CTreeView.ExpandAllChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DIM hChildNode AS HTREEITEM
   DO WHILE hNode
      ' // Expand the node
      CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)
      ' // Get the first child node
      hChildNode = CTreeView.GetChild(hTreeView, hNode)
      IF hChildNode THEN CTreeView.ExpandAllChildItems(hTreeView, hChildNode)
      ' // Get the next sibling item
      hNode = CTreeView.GetNextSibling(hTreeView, hNode)
   LOOP
END SUB
' ========================================================================================
' ========================================================================================
' Expands the list of sibling items, if any, associated with the specified parent node.
' ========================================================================================
PRIVATE SUB CTreeView.ExpandSiblings (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DIM hChildNode AS HTREEITEM
   DO WHILE hNode
      ' // Expand the node
      CTreeView.Expand(hTreeView, hNode, TVM_EXPAND)
      ' // Get the next sibling item
      hNode = CTreeView.GetNextSibling(hTreeView, hNode)
   LOOP
END SUB
' ========================================================================================
' ========================================================================================
' Expands all the list of items.
' Note: This is a very slow process if the control has many items because of the continuous
' redrawing; therefore, disable redrawing before calling it with
'   SendMessageW(hTreeView, WM_SETREDRAW, FALSE, 0)
' and reenable drawing once it has ended with
'   SendMessageW(hTreeView, WM_SETREDRAW, TRUE, 0)
' followed by a redrawing of the control
'   InvalidateRect hTreeView, NULL, CTRUE
'   UpdateWindow hTreeView
' ========================================================================================
PRIVATE SUB CTreeView.ExpandAllItems (BYVAL hTreeView AS HWND)
   DIM hNode AS HTREEITEM = CTreeView.GetRoot(hTreeView)
   IF hNode THEN CTreeView.ExpandAllChildItems(hTreeView, hNode)
END SUB
' ========================================================================================
' ========================================================================================
' * Collapses the list of child items, if any, associated with the specified parent node.
' ========================================================================================
PRIVATE SUB CTreeView.CollapseChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DIM hChildNode AS HTREEITEM
   DO WHILE hNode
      ' // Collapse the node
      CTreeView.Expand(hTreeView, hNode, TVE_COLLAPSE)
      ' // Get the first child node
      hChildNode = CTreeView.GetChild(hTreeView, hNode)
      IF hChildNode THEN CTreeView.CollapseChildItems(hTreeView, hChildNode)
      hNode = NULL
   LOOP
END SUB
' ========================================================================================
' ========================================================================================
' Collapses the list of sibling items, if any, associated with the specified parent node.
' ========================================================================================
PRIVATE SUB CTreeView.CollapseSiblings (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DIM hChildNode AS HTREEITEM
   DO WHILE hNode
      ' // Collapse the node
      CTreeView.Expand(hTreeView, hNode, TVE_COLLAPSE)
      ' // Get the next sibling item
      hNode = CTreeView.GetNextSibling(hTreeView, hNode)
   LOOP
END SUB
' ========================================================================================
' ========================================================================================
' Collapses the list of child items, if any, associated with the specified parent node and
' the sibling nodes below it.
' ========================================================================================
PRIVATE SUB CTreeView.CollapseAllChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
   DIM hChildNode AS HTREEITEM
   DO WHILE hNode
      ' // Collapse the node
      CTreeView.Expand(hTreeView, hNode, TVE_COLLAPSE)
      ' // Get the first child node
      hChildNode = CTreeView.GetChild(hTreeView, hNode)
      IF hChildNode THEN CTreeView.CollapseAllChildItems(hTreeView, hChildNode)
      ' // Get the next sibling item
      hNode = CTreeView.GetNextSibling(hTreeView, hNode)
   LOOP
END SUB
' ========================================================================================
' ========================================================================================
' * Collapses all the list of items.
' ========================================================================================
PRIVATE SUB CTreeView.CollapseAllItems (BYVAL hTreeView AS HWND)
   DIM hNode AS HTREEITEM = CTreeView.GetRoot(hTreeView)
   IF hNode THEN CTreeView.CollapseAllChildItems(hTreeView, hNode)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves some or all of a treeview item's state attributes.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL mask AS UINT) AS UINT
   RETURN SendMessageW(hTreeView, TVM_GETITEMSTATE, CAST(WPARAM, hItem), CAST(LPARAM, mask))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns TRUE if the bold attribute is set, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetBold (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN (CTreeView.GetItemState(hTreeView, hItem, TVIS_BOLD) AND TVIS_BOLD) = TVIS_BOLD
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves some or all of a treeview item's state attributes.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetCheckState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS UINT
   RETURN SendMessageW(hTreeView, TVM_GETITEMSTATE, CAST(WPARAM, hItem), CAST(LPARAM, TVIS_STATEIMAGEMASK)) SHR 12
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns TRUE if the item is checked, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.IsItemChecked (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN CTreeView.GetCheckState(hTreeView, hItem) = 1
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns TRUE if the item is checked, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetCheck (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN CTreeView.GetCheckState(hTreeView, hItem) = 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of characters in the incremental search string.
' If the treeview control is not in incremental search mode, the return value is zero.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetISearchStringLen (BYVAL hTreeView AS HWND) AS LONG
   RETURN SendMessageW(hTreeView, TVM_GETISEARCHSTRING, 0, CAST(LPARAM, NULL))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the incremental search string for a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetISearchString (BYVAL hTreeView AS HWND, BYVAL pwsz AS WSTRING PTR) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_GETISEARCHSTRING, 0, CAST(LPARAM, pwsz))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetISearchString (BYVAL hTreeView AS HWND) AS DWSTRING
   DIM nLen AS LONG, dwsSearch AS DWSTRING
   nLen = SendMessageW(hTreeView, TVM_GETISEARCHSTRINGW, 0, NULL)
   dwsSearch = WSPACE(nLen + 1)
   nLen = SendMessageW(hTreeView, TVM_GETISEARCHSTRINGW, 0, CAST(LPARAM, STRPTR(dwsSearch)))
   RETURN LEFT(dwsSearch, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the lParam value from a Treeview
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetlParam (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS LPARAM
   DIM tvi AS TVITEMW
   tvi.hItem = hItem
   tvi.mask  = TVIF_HANDLE OR TVIF_PARAM
   SendMessageW(hTreeView, TVM_GETITEMW, 0, CAST(LPARAM, @tvi))
   RETURN tvi.lParam
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a treeview item's state attributes.
' ========================================================================================
PRIVATE SUB CTreeView.SetItemState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL state AS UINT, BYVAL statemask AS UINT)
   DIM tvi AS TVITEMW
   tvi.mask  = TVIF_STATE
   tvi.hItem = hItem
   tvi.stateMask = statemask
   tvi.state = state
   SendMessageW hTreeView, TVM_SETITEMW, 0, CAST(LPARAM, @tvi)
END SUB
' ========================================================================================

' ========================================================================================
' * Sets/unsets the bold attribute of the specified item.
' ========================================================================================
PRIVATE SUB CTreeView.SetBold (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fBold AS BOOLEAN)
   CTreeView.SetItemState(hTreeView, hItem, IIF(fBold = 0, 0, TVIS_BOLD), TVIS_BOLD)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the text of the specified item.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR, BYVAL cchtextmax AS LONG) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM tvi AS TVITEMW
   tvi.hitem = hItem
   tvi.mask = TVIF_TEXT
   tvi.psztext = pwszText
   tvi.cchtextmax = cchtextmax
   RETURN SendMessageW(hTreeView, TVM_GETITEMW, 0, cast(LPARAM, cast(TVITEMW PTR, @tvi)))
END FUNCTION
' ========================================================================================
' * Retrieves the text of the specified item.
' Returns the retrieved text.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL cchTextMax AS LONG = 0) AS DWSTRING
   DIM tvi AS TVITEMW, dwsText AS DWSTRING, p AS LONG
   IF cchtextmax < 1 THEN cchtextmax = MAX_PATH + 1
   dwsText = WSPACE(cchtextmax + 1)
   tvi.hitem = hItem
   tvi.mask = TVIF_TEXT
   tvi.psztext = STRPTR(dwsText)
   tvi.cchtextmax = cchtextmax + 1
   IF SendMessageW(hTreeView, TVM_GETITEMW, 0, CAST(LPARAM, @tvi)) = FALSE THEN EXIT FUNCTION
   p = INSTR(dwsText, CHR(0))
   IF p THEN dwsText = LEFT(dwsText, p - 1)
   FUNCTION = dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets some or all of a treeview item's attributes.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetItem (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMW PTR) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SETITEMW, 0, cast(WPARAM, pitem))
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetItem (BYVAL hTreeView AS HWND, BYREF item AS TVITEMW) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SETITEMW, 0, cast(WPARAM, @item))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetItemEx (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMEXW PTR) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SETITEMW, 0, cast(WPARAM, pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetItemEx (BYVAL hTreeView AS HWND, BYREF item AS TVITEMEXW) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SETITEMW, 0, cast(WPARAM, @item))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text of the specified item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DIM tvi AS TVITEMW
   tvi.hitem = hItem
   tvi.mask = TVIF_TEXT
   tvi.psztext = pwszText
   tvi.cchtextmax = LEN(*pwszText)
   RETURN SendMessageW(hTreeView, TVM_SETITEMW, 0, cast(LPARAM, @tvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Sets the text of the specified item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   DIM tvi AS TVITEMW
   tvi.hitem = hItem
   tvi.mask = TVIF_TEXT
   tvi.psztext = pwszText
   tvi.cchtextmax = LEN(*pwszText)
   RETURN SendMessageW(hTreeView, TVM_SETITEMW, 0, cast(LPARAM, @tvi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the treeview item that bears the specified relationship to a specified item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetNextItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS HTREEITEM
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_GETNEXTITEM, code, CAST(LPARAM, hItem)))
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the first child item of the specified treeview item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetChild (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_CHILD)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the currently selected item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetSelection (BYVAL hTreeView AS HWND) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, NULL, TVGN_CARET)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the currently selected item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetSelect (BYVAL hTreeView AS HWND) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, NULL, TVGN_CARET)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the treeview item that is the target of a drag-and-drop operation.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetDropHilight (BYVAL hTreeView AS HWND) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, NULL, TVGN_DROPHILITE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the first visible item in a treeview control window.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetFirstVisible (BYVAL hTreeView AS HWND) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, NULL, TVGN_FIRSTVISIBLE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the next sibling item of a specified item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetNextSibling (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_NEXT)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the next sibling item of a specified item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetNext (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_NEXT)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the treeview item that bears the TVGN_NEXTSELECTED relationship to a specified tree item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetNextSelected (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_NEXTSELECTED)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the next visible item that follows a specified item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetNextVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_NEXTVISIBLE)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieves the parent item of the specified treeview item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetParent (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_PARENT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text of the parent item of the specified treeview item.
' Usage example:
' DIM wszText AS WSTRING * 260
' CTreeView.GetParentText(hTreeView, hItem, @wszText, 260)
' AfxMsg(wszText)
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetParentText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM hNode AS HTREEITEM = CTreeView.GetNextItem(hTreeView, hItem, TVGN_PARENT)
   IF hNode THEN RETURN CTreeView.GetItemText(hTreeView, hNode, pwszText, cchTextMax)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Retrieves the text of the parent item of the specified treeview item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetParentText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL cchTextMax AS LONG = 0) AS DWSTRING
   DIM hNode AS HTREEITEM = CTreeView.GetNextItem(hTreeView, hItem, TVGN_PARENT)
   IF hNode THEN RETURN CTreeView.GetItemText(hTreeView, hNode, cchTextMax)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the topmost or very first item of the treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetRoot (BYVAL hTreeView AS HWND) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, NULL, TVGN_ROOT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the previous sibling item of a specified item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetPrevSibling (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_PREVIOUS)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetPrevious (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_PREVIOUS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the first visible item that precedes a specified item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetPrevVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, hItem, TVGN_PREVIOUSVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves some or all of a treeview item's state attributes.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetLastVisible (BYVAL hTreeView AS HWND) AS HTREEITEM
   RETURN CTreeView.GetNextItem(hTreeView, NULL, TVGN_LASTVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for an exact string in a tree view node. Search is case sensitive.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CTreeView.ItemExists (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM cbLen AS LONG = LEN(*pwszText)
   IF cbLen = 0 THEN EXIT FUNCTION
   DIM dwsItemText AS DWSTRING = WSPACE(cbLen + 1)
   DIM hItem AS HTREEITEM = CTreeView.GetChild(hTreeView, hNode)
   DO
      IF hItem = NULL THEN EXIT FUNCTION
      IF CTreeView.GetItemText(hTreeView, hItem, *dwsItemText, LEN(dwsItemText)) = FALSE THEN EXIT DO
      IF dwsItemText = *pwszText THEN
         FUNCTION = TRUE
         EXIT DO
      END IF
      hItem = CTreeView.GetNextSibling(hTreeView, hItem)
   LOOP
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for an exact string in a tree view node. Search is case insensitive.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION CTreeView.ItemExistsIgnoreCase (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
   IF pwszText = NULL THEN EXIT FUNCTION
   DIM cbLen AS LONG = LEN(*pwszText)
   IF cbLen = 0 THEN EXIT FUNCTION
   DIM dwsItemText AS DWSTRING = WSPACE(cbLen + 1)
   DIM hItem AS HTREEITEM = CTreeView.GetChild(hTreeView, hNode)
   DO
      IF hItem = NULL THEN EXIT FUNCTION
      IF CTreeView.GetItemText(hTreeView, hItem, *dwsItemText, LEN(dwsItemText)) = FALSE THEN EXIT DO
      IF UCASE(dwsItemText) = UCASE(*pwszText) THEN
         FUNCTION = TRUE
         EXIT DO
      END IF
      hItem = CTreeView.GetNextSibling(hTreeView, hItem)
   LOOP
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a dragging bitmap for the specified item in a treeview control. The method also
' creates an image list for the bitmap and adds the bitmap to the image list.
' ========================================================================================
PRIVATE FUNCTION CTreeView.CreateDragImage (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hTreeView, TVM_CREATEDRAGIMAGE, 0, CAST(LPARAM, hItem)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Begins in-place editing of the specified item's text, replacing the text of the item
' with a single-line edit control containing the text.
' ========================================================================================
PRIVATE FUNCTION CTreeView.EditLabel (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HWND
   RETURN CAST(HWND, SendMessageW(hTreeView, TVM_EDITLABEL, 0, CAST(LPARAM, hItem)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Ends the editing of a treeview item's label.
' ========================================================================================
PRIVATE FUNCTION CTreeView.EndEditLabelNow (BYVAL hTreeView AS HWND, BYVAL fCancel AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_ENDEDITLABELNOW, fCancel, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Ensures that a treeview item is visible, expanding the parent item or scrolling the
' treeview control, if necessary.
' ========================================================================================
PRIVATE FUNCTION CTreeView.EnsureVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_ENSUREVISIBLE, 0, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current background color of the control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetBkColor (BYVAL hTreeView AS HWND) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves a count of the items in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetCount (BYVAL hTreeView AS HWND) AS UINT
   RETURN SendMessageW(hTreeView, TVM_GETCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the edit control being used to edit a treeview item's text.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetEditControl (BYVAL hTreeView AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hTreeView, TVM_GETEDITCONTROL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended style for a specified treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetExtendedStyle (BYVAL hTreeView AS HWND) AS DWORD
   RETURN SendMessageW(hTreeView, TVM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the normal or state image list associated with a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetImageList (BYVAL hTreeView AS HWND, BYVAL iImage AS LONG) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hTreeView, TVM_GETIMAGELIST, iImage, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the amount, in pixels, that child items are indented relative to their parent items.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetIndent (BYVAL hTreeView AS HWND) AS UINT
   RETURN SendMessageW(hTreeView, TVM_GETINDENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color used to draw the insertion mark for the tree view.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetInsertMarkColor (BYVAL hTreeView AS HWND) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the current height of the treeview items.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemHeight (BYVAL hTreeView AS HWND) AS LONG
   RETURN SendMessageW(hTreeView, TVM_GETITEMHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Retrieves the largest possible bounding rectangle that constitutes the "hit zone" for a
' specified part of an item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYREF rc AS RECT, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS BOOLEAN
   DIM info AS TVGETITEMPARTRECTINFO
   info.hti = hitem
   info.prc = VARPTR(rc)
   info.partID = partid
   RETURN SendMessageW(hTreeView, TVM_GETITEMPARTRECT, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL prc AS RECT PTR, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS BOOLEAN
   DIM info AS TVGETITEMPARTRECTINFO
   info.hti = hitem
   info.prc = prc
   info.partID = partid
   RETURN SendMessageW(hTreeView, TVM_GETITEMPARTRECT, 0, CAST(LPARAM, @info))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS RECT
   DIM info AS TVGETITEMPARTRECTINFO, rc AS RECT
   info.hti = hitem
   info.prc = VARPTR(rc)
   info.partID = partid
   SendMessageW(hTreeView, TVM_GETITEMPARTRECT, 0, CAST(LPARAM, @info))
   RETURN rc
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Retrieves the bounding rectangle for a treeview item and indicates whether the item is visible.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYREF rc AS RECT, BYVAL code AS BOOLEAN) AS BOOLEAN
   IF VARPTR(rc) = 0 THEN RETURN FALSE
   *CPTR(HTREEITEM PTR, @rc) = hitem
   RETURN SendMessageW(hTreeView, TVM_GETITEMRECT, code, CAST(LPARAM, @rc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL prc AS RECT PTR, BYVAL code AS BOOLEAN) AS BOOLEAN
   IF prc = NULL THEN RETURN FALSE
   *CPTR(HTREEITEM PTR, prc) = hitem
   RETURN SendMessageW(hTreeView, TVM_GETITEMRECT, code, CAST(LPARAM, prc))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS BOOLEAN) AS RECT
   DIM rc AS RECT
   *CPTR(HTREEITEM PTR, @rc) = hItem
   SendMessageW(hTreeView, TVM_GETITEMRECT, code, CAST(LPARAM, @rc))
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current line color.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetLineColor (BYVAL hTreeView AS HWND) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_GETLINECOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the maximum scroll time for the treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetScrollTime (BYVAL hTreeView AS HWND) AS UINT
   RETURN SendMessageW(hTreeView, TVM_GETSCROLLTIME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current text color of the control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetTextColor (BYVAL hTreeView AS HWND) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_GETTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the child Tooltip control used by a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.GetToolTips (BYVAL hTreeView AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hTreeView, TVM_GETTOOLTIPS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Obtains the number of items that can be fully visible in the client window of a
' treeview control.
' ========================================================================================
FUNCTION CTreeView.GetVisibleCount (BYVAL hTreeView AS HWND) AS UINT
   RETURN SendMessageW(hTreeView, TVM_GETVISIBLECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the location of the specified point relative to the client area of a
' treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.HitTest (BYVAL hTreeView AS HWND, BYVAL pht AS TVHITTESTINFO PTR) AS HTREEITEM
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_HITTEST, 0, CAST(LPARAM, pht)))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.HitTest (BYVAL hTreeView AS HWND, BYREF ht AS TVHITTESTINFO) AS HTREEITEM
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_HITTEST, 0, CAST(LPARAM, @ht)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps an accessibility ID to an HTREEITEM.
' ========================================================================================
PRIVATE FUNCTION CTreeView.MapAccIDToHTREEITEM (BYVAL hTreeView AS HWND, BYVAL id AS UINT) AS HTREEITEM
   RETURN CAST(HTREEITEM, SendMessageW(hTreeView, TVM_MAPACCIDTOHTREEITEM, id, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps an HTREEITEM to an accessibility ID.
' ========================================================================================
PRIVATE FUNCTION CTreeView.MapHTREEITEMToAccID (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS UINT
   RETURN SendMessageW(hTreeView, TVM_MAPHTREEITEMTOACCID, CAST(WPARAM, hItem), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws a specified treeview control item in the style used to indicate the target of a
' drag-and-drop operation.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SelectDropTarget (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SELECTITEM, TVGN_DROPHILITE, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Selects the specified treeview item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SelectItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SELECTITEM, TVGN_CARET, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CTreeView.SelectItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SELECTITEM, code, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Unselects the selected item.
' ========================================================================================
PRIVATE FUNCTION CTreeView.UnSelect (BYVAL hTreeView AS HWND) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SELECTITEM, TVGN_CARET, NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the treeview control vertically to ensure that the specified item is visible.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SelectSetFirstVisible (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information used to determine auto-scroll characteristics.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetAutoScrollInfo (BYVAL hTreeView AS HWND, BYVAL uPixPerSec AS UINT, BYVAL uUpdateTime AS UINT) AS LRESULT
   RETURN SendMessageW(hTreeView, TVM_SETAUTOSCROLLINFO, uPixPerSec, uUpdateTime)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the background color of the control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetBkColor (BYVAL hTreeView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_SETBKCOLOR, 0, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the item's state image to "checked" or "unchecked."
' ========================================================================================
PRIVATE SUB CTreeView.SetCheckState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fCheck AS BOOLEAN)
   DIM ix AS LONG = IIF(fCheck = TRUE, IndexToStateImageMask(2), IndexToStateImageMask(1))
   CTreeView.SetItemState hTreeView, hItem, ix, TVIS_STATEIMAGEMASK
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CTreeView.SetCheck (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fCheck AS BOOLEAN)
   DIM ix AS LONG = IIF(fCheck = TRUE, IndexToStateImageMask(2), IndexToStateImageMask(1))
   CTreeView.SetItemState hTreeView, hItem, ix, TVIS_STATEIMAGEMASK
END SUB
' ========================================================================================

' ========================================================================================
' Sets the extended style for a specified TreeView control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetExtendedStyle (BYVAL hTreeView AS HWND, BYVAL dwExStyle AS DWORD, BYVAL mask AS UINT) AS HRESULT
   RETURN SendMessageW(hTreeView, TVM_SETEXTENDEDSTYLE, mask, dwExStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the normal or state image list for a treeview control and redraws the control
' using the new images. When the TreeView control is destroyed, any attached ImageList is
' automatically destroyed.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetImageList (BYVAL hTreeView AS HWND, BYVAL himl AS HIMAGELIST, BYVAL iImage AS LONG) AS HIMAGELIST
   RETURN CAST(HIMAGELIST, SendMessageW(hTreeView, TVM_SETIMAGELIST, iImage, CAST(LPARAM, himl)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the width of indentation for a treeview control and redraws the control to reflect
' the new width.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetIndent (BYVAL hTreeView AS HWND, BYVAL indent AS LONG) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SETINDENT, indent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the insertion mark in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetInsertMark (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fAfter AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SETINSERTMARK, fAfter, CAST(LPARAM, hItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color used to draw the insertion mark for the tree view.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetInsertMarkColor (BYVAL hTreeView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_SETINSERTMARKCOLOR, 0, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the height of the treeview items.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetItemHeight (BYVAL hTreeView AS HWND, BYVAL cyItem AS SHORT) AS LONG
   RETURN SendMessageW(hTreeView, TVM_SETITEMHEIGHT, cyItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current line color.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetLineColor (BYVAL hTreeView AS HWND, BYVAL clrLine AS COLORREF) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_SETLINECOLOR, 0, clrLine)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum scroll time for the treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetScrollTime (BYVAL hTreeView AS HWND, BYVAL uMaxScrollTime AS UINT) AS UINT
   RETURN SendMessageW(hTreeView, TVM_SETSCROLLTIME, uMaxScrollTime, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Sets the text color of the control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetTextColor (BYVAL hTreeView AS HWND, BYVAL clrText AS COLORREF) AS COLORREF
   RETURN SendMessageW(hTreeView, TVM_SETTEXTCOLOR, 0, clrText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a treeview control's child Tooltip control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetToolTips (BYVAL hTreeView AS HWND, BYVAL hwndTT AS HWND) AS HWND
   RETURN CAST(HWND, SendMessageW(hTreeView, TVM_SETTOOLTIPS, CAST(WPARAM, hwndTT), 0))
END FUNCTION
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Shows the infotip for a specified item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.ShowInfoTip (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM) AS DWORD
   RETURN SendMessageW(hTreeView, TVM_SHOWINFOTIP, 0, CAST(LPARAM, hitem))
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Sorts the child items of the specified parent item in a treeview control.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SortChildren (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM, BYVAL fRecurse AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SORTCHILDREN, fRecurse, CAST(LPARAM, hitem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sorts treeview items using an application-defined callback function that compares the items.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SortChildrenCB (BYVAL hTreeView AS HWND, BYVAL psort AS TVSORTCB PTR, BYVAL fRecurse AS BOOLEAN) AS BOOLEAN
   RETURN SendMessageW(hTreeView, TVM_SORTCHILDRENCB, fRecurse, CAST(LPARAM, psort))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Set button dark mode.
' ========================================================================================
PRIVATE FUNCTION CTreeView.SetDarkMode(BYVAL hTreeView AS HWND) AS HRESULT
   RETURN SetWindowTheme(hTreeView, "DarkMode_Explorer", NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Remove button dark mode.
' ========================================================================================
PRIVATE FUNCTION CTreeView.RemoveDarkMode(BYVAL hTreeView AS HWND) AS HRESULT
   RETURN SetWindowTheme(hTreeView, NULL, NULL)
END FUNCTION
' ========================================================================================

END NAMESPACE
