# CTab Class

A tab control is analogous to the dividers in a notebook or the labels in a file cabinet. By using a tab control, an application can define multiple pages for the same area of a window or dialog box. Each page consists of a certain type of information or a group of controls that the application displays when the user selects the corresponding tab.

See: [About Tab Controls](https://learn.microsoft.com/en-us/windows/win32/controls/tab-controls)

**Include file**: CTab.inc.

| Name       | Description |
| ---------- | ----------- |
| [AddTab](#addtab) | Retrieves the number of tabs and calls InsertTab to add a new tab.  |
| [AdjustRect](#adjustrect) | Calculates a tab control's display area given a window rectangle, or calculates the window rectangle that would correspond to a specified display area. |
| [DeleteAllItems](#deleteallitems) | Removes all items from a tab control. |
| [DeleteItem](#deleteitem) | Removes an item from a tab control. |
| [DeselectAll](#deselectall) | Resets items in a tab control, clearing any that were set to the TCIS_BUTTONPRESSED state. |
| [GetCurFocus](#getcurfocus) | Returns the index of the item that has the focus in a tab control. |
| [GetCurSel](#getcursel) | Determines the currently selected tab in a tab control. |
| [GetExtendedStyle](#getextendedstyle) | Retrieves the extended styles that are currently in use for the tab control. |
| [GetImageIndex](#getimageindex) | Gets the 0-based index in the tab control's image list. |
| [GetImageList](#getimagelist) | Retrieves the image list associated with a tab control. |
| [GetItem](#getitem) | Retrieves information about a tab in a tab control. |
| [GetItemCount](#getitemcount) | Retrieves the number of tabs in the tab control. |
| [GetItemRect](#getitemrect) | Retrieves the bounding rectangle for a tab in a tab control. |
| [GetRowCount](#getrowcount) | Retrieves the number of rows of tabs in the tab control. |
| [GetText](#gettext) | Gets the name of a tab in a Tab control. |
| [GetToolTips](#gettooltips) | Retrieves the handle to the ToolTip control associated with a tab control. |
| [HighlightItem](#highlightitem) | Sets the highlight state of a tab item. |
| [HitTest](#hittext) | Determines which tab, if any, is at a specified screen position. |
| [InsertItem](#insertitem) | Inserts a new tab in a tab control. |
| [InsertTab](#inserttab) | Inserts a new tab in a tab control. |
| [RemoveImage](#removeimage) | Removes an image from a tab control's image list. |
| [SetCurFocus](#setcurfocus) | Sets the focus to a specified tab in a tab control. |
| [SetCurSel](#setcursel) | Selects a tab in a tab control. |
| [SetExtendedStyle](#setextendedstyle) | Sets the extended styles that the tab control will use. |
| [SetImageList](#setimagelist) | Assigns an image list to a tab control. |
| [SetImageIndex](#setimageindex) | Sets the zero-based index in the tab control's image list. |
| [SetItem](#setitem) | Sets some or all of a tab's attributes. |
| [SetItemExtra](#setitemextra) | Sets the number of bytes per tab reserved for application-defined data in a tab control. |
| [SetItemSize](#setitemsize) | Sets the width and height of tabs in a fixed-width or owner-drawn tab control. |
| [SetMinTabWidth](#setmintabwidth) | Sets the width and height of tabs in a fixed-width or owner-drawn tab control. |
| [SetPadding](#setpadding) | Sets the amount of space (padding) around each tab's icon and label in a tab control. |
| [SetText](#settext) | Sets the name of a tab in a Tab control. |
| [SetToolTips](#settooltips) | Assigns a ToolTip control to a tab control. You can use this macro or send the |

---

### AddTab

Adds a new tab in a tab control.

```
FUNCTION AddTab (BYVAL hTab AS HWND, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR, _
   BYVAL lParam AS ..LPARAM = 0) AS LONG
```
| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iImage* | Zero-based index of the image in the image list or -1 for no image. |
| *pwszText* | Pointer to a null-terminated string that contains the tab text when item information is being set. |
| *lParam* | Application-defined data associated with the tab control item. |

#### Return value

Returns the index of the new tab if successful, or -1 otherwise.

---

### AdjustRect

Calculates a tab control's display area given a window rectangle, or calculates the window rectangle that would correspond to a specified display area.

```
SUB AdjustRect (BYVAL hTab AS HWND, BYVAL fLarger AS BOOLEAN, BYVAL prc AS RECT PTR)
SUB AdjustRect (BYVAL hTab AS HWND, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT)
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *fLarger* | Operation to perform. If this parameter is TRUE, *prc* specifies a display rectangle and receives the corresponding window rectangle. If this parameter is FALSE, *prc* specifies a window rectangle and receives the corresponding display area. |
| *prc* | Pointer to a **RECT** structure that specifies the given rectangle and receives the calculated rectangle. |
| *rc* | A **RECT** structure that specifies the given rectangle and receives the calculated rectangle. |

#### Remarks

This message applies only to tab controls that are at the top. It does not apply to tab controls that are on the sides or bottom.

#### Usage example

```
DIM rc AS RECT
CTab.AdjustRect(hTab, TRUE, @rc)
CTab.AdjustRect(hTab, FALSE, rc)
```
---

### DeleteAllItems

Removes all items from a tab control. 

```
FUNCTION DeleteAllItems (BYVAL hTab AS HWND) AS BOOLEAN
```

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Usage example

```
CTab.DeleteAllItems(hTab)
```
---

### DeleteItem

Removes an item from a tab control.

```
FUNCTION DeleteItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the item to delete. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Usage example

```
CTab.DeleteItem(hTab, 2)
```
---

### DeselectAll

Resets items in a tab control, clearing any that were set to the TCIS_BUTTONPRESSED state.

```
SUB DeselectAll (BYVAL hTab AS HWND, BYVAL fExcludeFocus AS BOOLEAN)
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *fExcludeFocus* | Flag value that specifies the scope of the item deselection. If this parameter is set to FALSE, all tab items will be reset. If it is set to TRUE, all but the currently selected tab item will be reset. |

#### Usage example

```
CTab.DeselectAll(hTab, TRUE)
```
---

### GetCurFocus

Returns the index of the item that has the focus in a tab control.

```
FUNCTION GetCurFocus (BYVAL hTab AS HWND) AS LONG
```

#### Remarks

The item that has the focus may be different than the selected item.

#### Usage example

```
DIM curFocus AS LONG = CTab.GetCurFocus(hTab)
```

#### Remarks

The item that has the focus may be different than the selected item.

---

### GetCurSel

Determines the currently selected tab in a tab control.

```
FUNCTION GetCurSel (BYVAL hTab AS HWND) AS LONG
```

#### Return value

Returns the index of the selected tab if successful, or -1 if no tab is selected.

#### Usage example

```
DIM curSel AS LONG = CTab.GetCurSel(hTab)
```
---

### GetExtendedStyle

Retrieves the extended styles that are currently in use for the tab control.

```
FUNCTION GetExtendedStyle (BYVAL hTab AS HWND) AS DWORD
```

#### Return value

Returns a DWORD value that represents the extended styles currently in use for the tab control. This value is a combination of tab control extended styles.

#### Usage example

```
DIM style AS DWORD = CTab.GetExtendedStyle(hTab)
```
---

### GetImageIndex

Gets the 0-based index of an image in the tab control's image list.

```
FUNCTION GetImageIndex (BYVAL hTab AS HWND, BYVAL iItem AS DWORD) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the tab. |

#### Return value

Returns the index of the image or -1 if not found.

#### Usage example

```
DIM idx AS LONG = CTab.GetImageIndex(hTab, 1)
```
---

### GetImageList

Retrieves the image list associated with a tab control.

```
FUNCTION GetImageList (BYVAL hTab AS HWND) AS HIMAGELIST
```

#### Return value

Returns the handle to the image list if successful, or NULL otherwise.

#### Usage example

```
DIM hIml AS HIMAGELIST = CTab.GetImageList(hTab)
```
---

### GetItem

Retrieves information about a tab in a tab control.

```
FUNCTION GetItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL ptcitem AS TCITEMW PTR) AS BOOLEAN
FUNCTION GetItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF tcitem AS TCITEMW) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the tab. |
| *ptcitem* | Pointer to a **TCITEM** structure that specifies the information to retrieve and receives information about the tab. When the message is sent, the mask member specifies which attributes to return. If the mask member specifies the **TCIF_TEXT** value, the *pszText* member must contain the address of the buffer that receives the item text, and the *cchTextMax* member must specify the size of the buffer. |
| *tcitem* | A **TCITEM** structure that specifies the information to retrieve and receives information about the tab. When the message is sent, the mask member specifies which attributes to return. If the mask member specifies the TCIF_TEXT value, the *pszText* member must contain the address of the buffer that receives the item text, and the *cchTextMax* member must specify the size of the buffer. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the TCIF_TEXT flag is set in the **mask** member of the **TCITEM** structure, the control may change the *pszText* member of the structure to point to the new text instead of filling the buffer with the requested text. The control may set the *pszText* member to NULL to indicate that no text is associated with the item.

#### Usage example

```
DIM item AS TCITEM
DIM2 bRes AS BOOLEAN = CTab.GetItem(hTab, @item)
DIM2 bRes AS BOOLEAN = CTab.GetItem(hTab, item)
```
---

### GetItemCount

Retrieves the number of tabs in the tab control.

```
FUNCTION GetItemCount (BYVAL hTab AS HWND) AS LONG
```

#### Return value

Returns the number of items if successful, or zero otherwise.

#### Usage example

```
DIM count AS LONG = CTab.GetItemCount(hTab)
```
---

### GetItemRect

Retrieves the bounding rectangle for a tab in a tab control.

```
FUNCTION GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hTab AS HWND, BYVAL iItem AS DWORD) AS RECT
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the tab. |
| *prc* | Pointer to a **RECT** structure that receives the bounding rectangle of the tab, in viewport coordinates. |
| *rc* | A **RECT** structure that receives the bounding rectangle of the tab, in viewport coordinates. |

#### Return valu

Returns TRUE if successful, or FALSE otherwise.

#### Usage example

```
DIM rc AS RECT
CTab.GetItemRect(hTab, @rc)
CTab.GetItemRect(hTab, rc)
rc = GetItemRect(hTab)
```
---

### GetRowCount

Retrieves the number of rows of tabs in the tab control.

```
FUNCTION GetRowCount (BYVAL hTab AS HWND) AS LONG
```

#### Return value

Returns the number of rows of tabs.

#### Remarks

Only tab controls that have the TCS_MULTILINE style can have multiple rows of tabs.

#### Usage example

```
DIM count AS LONG = CTab.GetRowCount(hTab)
```
---

### GetText

Gets the name of a tab in a Tab control.

```
FUNCTION GetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
FUNCTION GetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD) AS DWSTRING
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *nTabIndex* | Zero-based index of the tab. |
| *pwszText* | Pointer to a unicode string that will receive the name of the tab. |
| *cchTextMax* | Size in characters of the buffer pointed to by the *pszText* member. |

```
DIM dwsText AS DWSTRING = CTab.GetText(hTab, 1)
```
---

### GetToolTips

Retrieves the handle to the tooltip control associated with a tab control.

```
FUNCTION GetToolTips (BYVAL hTab AS HWND) AS HWND
```

#### Return value

Returns the handle to the tooltip control if successful, or NULL otherwise.

#### Usage example

```
DIM hTooltips AS HWND = CTab.GetToolTips(hTab)
```
---

### HighlightItem

Sets the highlight state of a tab item.

```
FUNCTION HighlightItem (BYVAL hTab AS HWND, BYVAL idItem AS LONG, BYVAL fHighlight AS WORD) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *idItem* | Zero-based index of the tab. |
| *fHighlight* | Value specifying the highlight state to be set. If this value is nonzero, the tab is highlighted. If this value is zero, the tab is set to its default state. |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Remarks

In Comctl32.dll version 6.0, this macro has no visible effect when a theme is active.

#### Usage example

```
CTab.HighlightItem(hTab, 1, 1)
```
---

### HitTest

Determines which tab, if any, is at a specified screen position.

```
FUNCTION HitTest (BYVAL hTab AS HWND, BYREF pInfo AS TC_HITTESTINFO PTR) AS LONG
FUNCTION HitTest (BYVAL hTab AS HWND, BYREF info AS TC_HITTESTINFO) AS LONG
```
| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *pInfo* | Pointer to a TCHITTESTINFO structure that specifies the screen position to test. |
| *info* | A TCHITTESTINFO structure that specifies the screen position to test. |

#### Return value

Returns the index of the tab, or -1 if no tab is at the specified position.

---

### InsertItem

Inserts a new tab in a tab control.

```
FUNCTION InsertItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYVAL pItem AS TCITEMW PTR) AS LONG
FUNCTION InsertItem (BYVAL hTab AS HWND, BYVAL iItem AS DWORD, BYREF item AS TCITEMW) AS LONG
```
| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the new tab. |
| *pItem* | Pointer to a **TCITEMW** structure that specifies the attributes of the tab. The **dwState** and **dwStateMask** members of this structure are ignored by this message. |
| *item* | A **TCITEMW** structure that specifies the attributes of the tab. The **dwState** and **dwStateMask** members of this structure are ignored by this message. |

#### Return value

Returns the index of the new tab if successful, or -1 otherwise.

---

### InsertTab

Inserts a new tab in a tab control.

```
FUNCTION InsertTab (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL iImage AS LONG, _
   BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0) AS LONG
```
| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *nTabInxex* | Zero-based index of the tab. |
| *iImage* | Zero-based index of the image in the image list or -1 for no image. |
| *pwszText* | Pointer to a null-terminated string that contains the tab text when item information is being set. |
| *lParam* | Application-defined data associated with the tab control item. |

#### Return value

Returns the index of the new tab if successful, or -1 otherwise.

---

### RemoveImage

Removes an image from a tab control's image list.

```
SUB RemoveImage (BYVAL hTab AS HWND, BYVAL iImage AS LONG)
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iImage* | Zero-based index of the image to remove. |

#### Remarks

The tab control updates each tab's image index, so each tab remains associated with the same image as before. If a tab is using the image being removed, the tab will be set to have no image.

#### Usage example

```
CTab.RemoveImage(hTab, 2)
```
---

### SetCurFocus

Sets the focus to a specified tab in a tab control.

```
SUB SetCurFocus (BYVAL hTab AS HWND, BYVAL iItem AS LONG)
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the tab that gets the focus. |

#### Remarks

If the tab control has the TCS_BUTTONS style (button mode), the tab with the focus may be different from the selected tab. For example, when a tab is selected, the user can press the arrow keys to set the focus to a different tab without changing the selected tab. In button mode, **SetCurFocus** sets the input focus to the button associated with the specified tab, but it does not change the selected tab.

If the tab control does not have the TCS_BUTTONS style, changing the focus also changes the selected tab. In this case, the tab control sends the TCN_SELCHANGING and TCN_SELCHANGE notification codes to its parent window.

#### Usage example

```
CTab.SetCurFocus(hTab, 2)
```
---

### SetCurSel

Selects a tab in a tab control.

```
FUNCTION SetCurSel (BYVAL hTab AS HWND, BYVAL iItem AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the tab to select. |

#### Return value

Returns the index of the previously selected tab if successful, or -1 otherwise.

#### Remarks

A tab control does not send a TCN_SELCHANGING or TCN_SELCHANGE notification code when a tab is selected using the TCM_SETCURSEL message.

#### Usage example

```
CTab.SetCurSel(hTab, 2)
```
---

### SetExtendedStyle

Sets the extended styles that the tab control will use.

```
FUNCTION SetExtendedStyle (BYVAL hTab AS HWND, BYVAL dwExStyle AS DWORD) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *dwExStyle* | Value that contains the new tab control extended styles. |

#### Return value

Returns a DWORD value that contains the previous tab control extended styles.

#### Usage example

```
CTab.SetExtendedStyle(hTab, exStyle)
```
---

### SetImageList

Assigns an image list to a tab control.

```
FUNCTION SetImageList (BYVAL hTab AS HWND, BYVAL himl AS HIMAGELIST) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *himl* | Handle to the image list to assign to the tab control. |

#### Return value

Returns the handle to the previous image list, or NULL if there is no previous image list.

#### Usage example

```
DIM hOldImlList AS HIMAGELIST = CTab.SetExtendedStyle(hTab, hIml)
```
---

### SetImageIndex

Sets the zero-based index in the tab control's image list.

```
FUNCTION SetImageIndex (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iImage* | Zero-based index of the tab control's image list. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Usage example

```
CTab.SetImageIndex(hTab, 2)
```
---

### SetItem

Sets some or all of a tab's attributes.

```
FUNCTION SetItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYREF pitem AS TCITEMW PTR) AS LONG
FUNCTION SetItem (BYVAL hTab AS HWND, BYVAL iItem AS LONG, BYREF item AS TCITEMW) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *iItem* | Zero-based index of the item. |
| *pitem* | Pointer to a **TCITEMW** structure that contains the new item attributes. The **mask** member specifies which attributes to set. If the mask member specifies the LVIF_TEXT value, the *pszText* member is the address of a null-terminated string and the *cchTextMax* member is ignored. |
| *item* | A **TCITEMW** structure that contains the new item attributes. The **mask** member specifies which attributes to set. If the mask member specifies the LVIF_TEXT value, the *pszText* member is the address of a null-terminated string and the *cchTextMax* member is ignored. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetItemExtra

Sets the number of bytes per tab reserved for application-defined data in a tab control. 

```
FUNCTION SetItemExtra (BYVAL hTab AS HWND, BYVAL cb AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *cb* | Number of extra bytes. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

By default, the number of extra bytes is four. An application that changes the number of extra bytes cannot use the **TCITEMW** structure to retrieve and set the application-defined data for a tab. Instead, you must define a new structure that consists of the **TCITEMHEADER** structure followed by application-defined members.

An application should only change the number of extra bytes when a tab control does not contain any tabs.

---

### SetItemSize

Sets the width and height of tabs in a fixed-width or owner-drawn tab control. 

```
FUNCTION SetItemSize (BYVAL hTab AS HWND, BYVAL x AS LONG, BYVAL y AS LONG) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *x* | New width, in pixels. |
| *y* | New height, in pixels. |

#### Return value

Returns the old width and height. The width is in the LOWORD of the return value, and the height is in the HIWORD.

#### Usage example

```
CTab.SetItemSize(hTab, 50, 30)
```
---

### SetMinTabWidth

Sets the width and height of tabs in a fixed-width or owner-drawn tab control.

```
FUNCTION SetMinTabWidth (BYVAL hTab AS HWND, BYVAL cx AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *cx* | Minimum width to be set for a tab control item. If this parameter is set to -1, the control will use the default tab width. |

#### Return value

Returns a value that represents the previous minimum tab width.

#### Usage example

```
CTab.SetMinTabWidth(hTab, 50)
```
---

### SetPadding

Sets the amount of space (padding) around each tab's icon and label in a tab control.

```
SUB SetPadding (BYVAL hTab AS HWND, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER)
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *cx* | Amount of horizontal padding, in pixels. |
| *cy* | Amount of vertical padding, in pixels. |

#### Usage example

```
CTab.SetPadding(hTab, 10, 10)
```
---

### SetText

Sets the name of a tab in a Tab control.

```
FUNCTION SetText (BYVAL hTab AS HWND, BYVAL nTabIndex AS DWORD, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *nTabIndex* | Zero-based index of the tab. |
| *pwszText* | Pointer to a unicode string with the name of the tab. |

#### Usage example

```
CTab.SetText(hTab, 2, "New text")
```
---

### SetToolTips

Assigns a ToolTip control to a tab control.

```
SUB SetToolTips (BYVAL hTab AS HWND, BYVAL hwndTT AS HWND)
```

| Parameter | Description |
| ------- | -------------- |
| *hTab* | Handle to the tab control. |
| *hwndTT* | Handle to the tooltip control. |

#### Usage example

```
CTab.SetToolTips(hTab, hwndTT)
```
---
