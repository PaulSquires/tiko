# CListView Class

A list-view control is a window that displays a collection of items. List-view controls provide several ways to arrange and display items and are much more flexible than simple List Boxes. For example, additional information about each item can be displayed in columns to the right of the icon and label.

See: [About List-View Controls](https://learn.microsoft.com/en-us/windows/win32/controls/list-view-controls-overview)

**Include file**: CListView.inc

| Name       | Description |
| ---------- | ----------- |
| [AddColumn](#addcolumn) | Inserts a new column in a list-view control. |
| [AddItem](#additem) | Inserts a new item in a list-view control. |
| [AppendItem](#appenditem) | Appends a new item in a list-view control. |
| [ApproximateViewRect](#approximateviewrect) | Calculates the approximate width and height required to display a given number of items. |
| [Arrange](#arrange) | Arranges items in icon view. |
| [AutoSizeColumns](#autosizecolumns) | Automatically sizes all the columns of a listview. |
| [AutoSizeHeader](#autosizeheader) | Automatically sizes all the columns of the header of a listview. |
| [CancelEditLabel](#canceleditlabel) | Cancels an item text editing operation. |
| [CreateDragImage](#createdragimage) | Creates a drag image list for the specified item. |
| [DeleteAllItems](#deleteallitems) | Removes all items from a list-view control. |
| [DeleteColumn](#deletecolumn) | Removes a column from a list-view control. |
| [DeleteItem](#deleteitem) | Removes an item from a list-view control. |
| [EditLabel](#editlabel) | Begins in-place editing of the specified list-view item's text. The message implicitly selects and focuses the specified item. |
| [EnableGroupView](#enablegroupview) | Removes an item from a list-view control. |
| [EnsureVisible](#ensurevisible) | Ensures that a list-view item is either entirely or partially visible, scrolling the list-view control if necessary. |
| [FindItem](#finditem) | Searches for a list-view item with the specified characteristics. |
| [FindString](#findstring) | Searches for a list-view item with the specified text. |
| [FitContent](#fitcontent) | Automatically sizes the specified column. |
| [FitHeader](#fitheader) | Automatically sizes the column to fit the header text. |
| [GetBkColor](#getbkcolor) | Gets the background color of a list-view control. |
| [GetBkImage](#getbkimage) | Gets the background image in a list-view control. |
| [GetCallbackMask](#getcallbackmask) | Gets the background image in a list-view control. |
| [GetCheckState](#getcheckstate) | Determines if an item in a list-view control is selected. This should be used only for list-view controls that have the LVS_EX_CHECKBOXES style. |
| [GetColumn](#getcolumn) | Gets the attributes of a list-view control's column. |
| [GetColumnCount](#getcolumncount) | Gets the number of columns of a listview. |
| [GetColumnOrder](#getcolumnorder) | Gets the order of the specified column of the listview's header control. |
| [GetColumnText](#getcolumntext) | Gets the text of a list-view control's column. |
| [GetColumnOrderArray](#getcolumnorderarray) | Gets the current left-to-right order of columns in a list-view control. |
| [GetColumnWidth](#getcolumnwidth) | Gets the width of a column in report or list view. |
| [GetCountPerPage](#getcountperpage) | Calculates the number of items that can fit vertically in the visible area of a list-view control when in list or report view. |
| [GetEditControl](#geteditcontrol) | Gets the handle to the edit control being used to edit a list-view item's text. |
| [GetEmptyText](#getemptytext) | Gets the text meant for display when the list-view control appears empty. |
| [GetExtendedListViewStyle](#getextendedlistviewstyle) | Gets the extended styles that are currently in use for a given list-view control. |
| [GetFocusedGroup](#getfocusedgroup) | Gets the group that has the focus. |
| [GetFocusedItem](#getfocuseditem) | Gets the item that has the focus, which may or may not be selected. |
| [GetFooterInfo](#getfooterinfo) | Gets information on the footer of a specified list-view control. |
| [GetFooterItem](#getfooteritem) | Gets information on a footer item for a specified list-view control. |
| [GetFooterItemRect](#getfooteritemrect) | Gets information on a footer item for a specified list-view control. |
| [GetFooterRect](#getfooterrect) | Gets information on a footer item for a specified list-view control. |
| [GetGroupCount](#getgroupcount) | Gets the number of groups. |
| [GetGroupHeaderImageList](#getgroupheaderimagelist) | Gets the group header image list that has been set for an existing list-view control. |
| [GetGroupInfo](#getgroupinfo) | Gets group information. |
| [GetGroupInfoByIndex](#getgroupinfobyindex) | Gets information on a specified group. |
| [GetGroupMetrics](#getgroupmetrix) | Gets information about the display of groups. |
| [GetGroupRect](#getgrouprect) | Gets the rectangle for a specified group. |
| [GetGroupState](#getgroupstate) | Gets the state for a specified group. |
| [GetHeader](#getheader) | Gets the handle to the header control used by a list-view control. |
| [GetHeaderText](#getheadertext) | Gets the text of the specified column of the header of a listview control. |
| [GetHotCursor](#gethotcursor) | Gets the HCURSOR used when the pointer is over an item while hot tracking is enabled. |
| [GetHotItem](#gethotitem) | Gets the index of the hot item. |
| [GetHoverTime](#gethovertime) | Gets the amount of time that the mouse cursor must hover over an item before it is selected. |
| [GetImageList](#getimagelist) | Gets the handle to an image list used for drawing list-view items. |
| [GetInsertMark](#getinsertmark) | Gets the position of the insertion point. |
| [GetInsertMarkColor](#getinsertmarkcolor) | Gets the color of the insertion point. |
| [GetInsertMarkRect](#getinsertmarkrect) | Gets the rectangle that bounds the insertion point. |
| [GetISearchString](#getisearchstring) | Gets the incremental search string of a list-view control. |
| [GetISearchStringLen](#getisearchstringlen) | Gets the length of the incremental search string of a list-view control. |
| [GetItem](#getitem) | Gets some or all of a list-view item's attributes. |
| [GetItemCount](#getitemcount) | Gets the number of items in a list-view control. |
| [GetItemIndexRect](#getitemindexrect) | Gets the bounding rectangle for all or part of a subitem in the current view of a specified list-view control. |
| [GetItemPosition](#getitemposition) | Gets the position of a list-view item. |
| [GetItemRect](#getitemrect) | Gets the bounding rectangle for all or part of an item in the current view. |
| [GetItemSpacing](#getitemspacing) | Determines the spacing between items in a list-view control. |
| [GetItemHorizontalSpacing](#getitemhorizontalspacing) | Determines the horizontal spacing between items in a list-view control. |
[ GetItemVerticalSpacing](#getitemverticalspacing) | Determines the vertical spacing between items in a list-view control. |
| [GetItemState](#getitemstate) | Gets the state of a list-view item. |
| [GetItemText](#getitemtext) | Gets the text of a list-view item or subitem. |
| [GetNextItem](#getnextitem) | Searches for a list-view item that has the specified properties and bears the specified relationship to a specified item. |
| [GetNextItemIndex](#getnextitemindex) | Gets the index of the item in a particular list-view control that has the specified properties and relationship to another specific item. |
| [GetNumberOfWorkAreas](#getnumberofworkareas) | Gets the number of working areas in a list-view control. |
| [GetOrderArray](#getorderarray) | Gets the current left-to-right order of items in the header of a listview control. |
| [GetOrigin](#getorigin) | Gets the current view origin for a list-view control. |
| [GetOutlineColor](#getoutlinecolor) | Gets the color of the border of a list-view control if the LVS_EX_BORDERSELECT extended window style is set. |
| [GetSelectedColumn](#getselectedcolumn) | Gets an integer that specifies the selected column. |
| [GetSelectedCount](#getselectedcount) | Determines the number of selected items in a list-view control. |
| [GetSelection](#getselection) | Returns the zero-based index of the currently selected item. |
| [GetSelectionMark](#getselectionmark) | Gets the selection mark from a list-view control. |
| [GetStringWidth](#getstringwidth) | Determines the width of a specified string using the specified list-view control's current font. |
| [GetSubItemRect](#getsubitemrect) | Gets information about the rectangle that surrounds a subitem in a list-view control. |
| [GetText](#getitemtext) | Gets the text of a list-view item or subitem. |
| [GetTextBkColor](#gettextbkcolor) | Gets the text background color of a list-view control. |
| [GetTextColor](#gettextcolor) | Gets the text color of a list-view control. |
| [GetTileInfo](#gettileinfo) | Gets information about a tile in a list-view control. |
| [GetTileViewInfo](#gettileviewinfo) | Gets information about a list-view control in tile view. |
| [GetToolTips](#getttoltips) | Gets the ToolTip control that the list-view control uses to display tooltips. |
| [GetTooltipsFont](#getttoltipsfont) | Retrieves the font used by the ToolTip control that the list-view control uses to display tooltips. |
| [GetTopIndex](#gettopindex) | Gets the index of the topmost visible item when in list or report view. |
| [GetView](#getview) | Gets the current view of a list-view control. |
| [GetViewRect](#getviewrect) | Gets the bounding rectangle of all items in the list-view control. |
| [GetWorkAreas](#getworkareas) | Gets the working areas from a list-view control. |
| [HasGroup](#hasgroup) | Determines whether the list-view control has a specified group. |
| [HitTest](#hittest) | Determines which list-view item, if any, is at a specified position. |
| [HitTestEx](#hittestex) | Determines which list-view item, if any, is at a specified position. |
| [InsertColumn](#insertcolumn) | Inserts a new column in a list-view control. |
| [InsertGroup](#insertgroup) | Inserts a group into a list-view control. |
| [InsertGroupSorted](#insertgroupsorted) | Inserts a group into an ordered list of groups. |
| [InsertItem](#insertitem) | Inserts a new item in a list-view control. |
| [InsertMarkHitTest](#insertmarkhittest) | Retrieves the insertion point closest to a specified point. |
| [IsGroupViewEnabled](#isgroupviewenabled) | Checks whether the list-view control has group view enabled. |
| [IsItemVisible](#isitemvisible) | Indicates whether an item in the list-view control is visible. |
| [MakeHeaderFlat](#makeheaderflat) | Removes the HDS_BUTTONS style from the header control to give it a flat appearance. |
| [MapIDToIndex](#mapidtoindex) | Maps the ID of an item to an index. |
| [MapIndexToID](#mapindextoid) | Maps the index of an item to a unique ID. |
| [ModifyHeaderFont](#modifyheaderfont) | Modifies the font used by the listview header. |
| [RedrawItems](#redrawitems) | Forces a list-view control to redraw a range of items. |
| [RemoveAllGroups](#removeallgroups) | Removes all groups from a list-view control. |
| [RemoveDarkMode](#removedarkmode) | Removes the listview dark mode. |
| [RemoveGroup](#removegroup) | Removes a group from a list-view control. |
| [Scroll](#scroll) | Scrolls the content of a list-view control. |
| [SelectAllItems](#selectallitems) | Selects all items. |
| [SelectItem](#selectitem) | Selects a ListView item. |
| [SetBkColor](#setbkcolor) | Sets the background color of a list-view control. |
| [SetBkImage](#setbkimage) | Sets the background image in a list-view control. |
| [SetCallbackMask](#setcallbackmask) | Changes the callback mask for a list-view control. |
| [SetCheckState](#setcheckstate) | Selects or deselects an item in a list-view control. |
| [SetColumn](#setcolumn) | Sets the attributes of a list-view column. |
| [SetColumnOrderArray](#setcolumnorderarray) | Sets the left-to-right order of columns in a list-view control. |
| [SetColumnWidth](#setcolumnwidth) | Used to change the width of a column in report view or the width of all columns in list-view mode. |
| [SetDarkMode](#setdarkmode) | Sets the listview dark mode. |
| [SetExtendedListViewStyle](#setextendedlistviewstyle) | Sets extended styles for list-view controls. |
| [SetExtendedListViewStyleEx](#setextendedlistviewstyleex) | Sets extended styles for list-view controls using the style mask. |
| [SetGroupHeaderImageList](#setgroupheaderimagelist) | Assigns an image list to the group header of a list-view control. |
| [SetGroupInfo](#setgroupinfo) | Sets group information. |
| [SetGroupMetrics](#setgroupmetrics) | Sets information about the display of groups. |
| [SetGroupState](#setgroupstate) | Sets the state for a specified group. |
| [SetHeaderFont](#setheaderfont) | Sets the font of the header. |
| [SetHotCursor](#sethotcursor) | Sets the HCURSOR that the list-view control uses when the pointer is over an item while hot tracking is enabled. |
| [SetHotItem](#sethotitem) | Sets the hot item in a list-view control. |
| [SetHoverTime](#sethovertime) | Sets the amount of time that the mouse cursor must hover over an item before it is selected. |
| [SetIconSpacing](#seticonspacing) | Sets the spacing between icons in list-view controls set to the LVS_ICON style. |
| [SetImageList](#setimagelist) | Assigns an image list to a list-view control. |
| [SetInfoTip](#setinfotip) | Sets tooltip text. |
| [SetInsertMark](#setinsertmark) | Sets the insertion point to the defined position. |
| [SetInsertMarkColor](#setinsertmarkcolor) | Sets the color of the insertion point. |
| [SetItem](#setitem) | Sets some or all of a list-view item's attributes. |
| [SetItemCount](#setitemcount) | Causes the list-view control to allocate memory for the specified number of items. |
| [SetItemCountEx](#setitemcountex) | Sets the virtual number of items in a virtual list view. |
| [SetItemIndexState](#setitemindexstate) | Sets the state of a specified list-view item. |
| [SetItemPosition](#setitemposition) | Moves an item to a specified position in a list-view control (in icon or small icon view). |
| [SetItemPosition32](#setitemposition32) | Moves an item to a specified position in a list-view control (in icon or small icon view). |
| [SetItemState](#setitemstate) | Changes the state of an item in a list-view control. |
| [SetItemText](#setitemtext) | Changes the text of a list-view item or subitem. |
| [SetOutlineColor](#setoutlinecolor) | Sets the color of the border of a list-view control if the LVS_EX_BORDERSELECT extended window style is set. |
| [SetSelectedColumn](#setselectedcolumn) | Sets the index of the selected column. |
| [SetSelectionMark](#setselectionmark) | Sets the selection mark in a list-view control. |
| [SetText](#setitemtext) | Changes the text of a list-view item or subitem. |
| [SetTextBkColor](#settextbkcolor) | Sets the background color of text in a list-view control. |
| [SetTextColor](#settextcolor) | Sets the text color of a list-view control. |
| [SetTileInfo](#settileinfo) | Sets information for an existing tile of a list-view control. |
| [SetTileViewInfo](#settileviewinfo) | Sets information that a list-view control uses in tile view. |
| [SetToolTips](#settooltips) | Sets the ToolTip control that the list-view control will use to display tooltips. |
| [SetTooltipsFont](#settooltipsfont) | Sets the font used by the ToolTip control that the list-view control uses to display tooltips. |
| [SetView](#setview) | Sets the view of a list-view control. |
| [SetWorkAreas](#setworkareas) | Sets the working areas within a list-view control. |
| [SortGroups](#sortgroups) | Uses an application-defined comparison function to sort groups by ID within a list-view control. |
| [SortItems](#sortitems) | Uses an application-defined comparison function to sort the items of a list-view control. |
| [SortItemsEx](#sortitemsex) | Uses an application-defined comparison function to sort the items of a list-view control. |
| [SubItemHitTest](#subitemhittest) | Determines which list-view item or subitem is located at a given position. |
| [SubItemHitTestEx](#subitemhittestex) | Determines which list-view item or subitem is located at a given position. |
| [UnselectAllItems](#unselectallitems) | Unselects all items. |
| [UnselectItem](#unselectitem) | Unselects an item in a ListView. |
| [Update](#update) | Updates a list-view item. |

---

### AddColumn

Inserts a new column in a list-view control.

```
FUNCTION AddColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF wszText AS WSTRING, _
   BYVAL nWidth AS LONG, BYVAL nFormat AS LONG = LVCFMT_LEFT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | Zero-based index of the new column. |
| *wszText* | The column header text. |
| *nWidth* | The width of the column, in pixels. |
| *nFormat* | Alignment of the column header and the subitem text in the column. The alignment of the leftmost column is always **LVCFMT_LEFT**; it cannot be changed. This member can be a combination of the following values. Note that not all combinations are valid.

| Value | Meaning |
| ----- | ------- |
| **LVCFMT_LEFT** | Text is left-aligned. |
| **LVCFMT_RIGHT** | Text is right-aligned. |
| **LVCFMT_CENTER** | Text is centered. |
| **LVCFMT_JUSTIFYMASK** | A bitmask used to select those bits of fmt that control field justification. To check the format of a column, use a logical "and" to combine LCFMT_JUSTIFYMASK with fmt. You can then use a switch statement to determine whether the LVCFMT_LEFT, LVCFMT_RIGHT, or LVCFMT_CENTER bits are set. |
| **LVCFMT_IMAGE** | Version 4.70. The item displays an image from an image list. |
| **LVCFMT_BITMAP_ON_RIGHT** | Version 4.70. The bitmap appears to the right of text. This does not affect an image from an image list assigned to the header item. |
| **LVCFMT_COL_HAS_IMAGES** | Version 4.70. The header item contains an image in the image list. |
| **LVCFMT_FIXED_WIDTH** | Version 6.00 and Windows Vista. Can't resize the column; same as HDF_FIXEDWIDTH. |
| **LVCFMT_NO_DPI_SCALE** | Version 6.00 and Windows Vista. If not set, CCM_DPISCALE will govern scaling up fixed width. |
| **LVCFMT_FIXED_RATIO** | Version 6.00 and Windows Vista. Width will augment with the row height. |
| **LVCFMT_SPLITBUTTON** | Version 6.00 and Windows Vista. Column is a split button (same as HDF_SPLITBUTTON). The header of the column displays a split button (same as HDF_SPLITBUTTON).|

#### Usage example
```
DIM wszText AS WSTRING * 260
FOR i AS LONG = 1 TO 5
   wszText = "Column " & STR(i)
   CListView.AddColumn(i, wszText, 50)
NEXT
```
---

### AddItem

Inserts a new item in a list-view control.

```
FUNCTION AddItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iImage AS LONG, _
   BYREF wszText AS WSTRING) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iItem* | Index at which the new item should be inserted. If this value is greater than the number of items currently contained by the listview control, the new item will be appended to the end of the list and assigned the correct index. Examine the return value to determine the actual index assigned to the item. |
| *iImage* | Index of the item's icon in the control's image list. |
| *wszText* | The item text. |

#### Return value

Returns the index of the new item if successful, or -1 otherwise.

---

### AppendItem

Appends a new item in a list-view control.

```
FUNCTION AppendItem (BYVAL hListView AS HWND, BYVAL iImage AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iImage* | Zero-based index of the item's icon in the control's image list. |
| *pwszText* | The item text. |

#### Return value

Returns the index of the new item if successful, or -1 otherwise.

---

### ApproximateViewRect

Calculates the approximate width and height required to display a given number of items.

```
FUNCTION ApproximateViewRect (BYVAL hListView AS HWND, BYVAL iWidth AS SHORT, _
   BYVAL iHeight AS SHORT, BYVAL iCount AS LONG) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iWidth* | The proposed x-dimension of the control, in pixels. This parameter can be -1 to allow the message to use the current width value. |
| *iHeight* | The proposed y-dimension of the control, in pixels. This parameter can be -1 to allow the message to use the current height value. |
| *iCount* | The number of items to be displayed in the control. If this parameter is -1, the message uses the total number of items in the control. |

#### Return value

Returns a DWORD value that holds the approximate width (in the LOWORD) and height (in the HIWORD) needed to display the items, in pixels.

---

### Arrange

Arranges items in icon view.

```
FUNCTION Arrange (BYVAL hListView AS HWND, BYVAL code AS UINT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *code* | One of the following values that specifies alignment: |

| Value | Meaning |
| ----- | ------- |
| **LVA_ALIGNLEFT** | Not implemented. Apply the LVS_ALIGNLEFT style instead. |
| **LVA_ALIGNTOP** | Not implemented. Apply the LVS_ALIGNTOP style instead. |
| **LVA_DEFAULT** | Aligns items according to the list-view control's current alignment styles (the default value). |
| **LVA_SNAPTOGRID** | Snaps all icons to the nearest grid position. |

#### Return value

Returns TRUE if successful; otherwise, FALSE.

---

### AutoSizeColumns

Automatically sizes all the columns of a listview

```
FUNCTION AutoSizeColumns (BYVAL hListView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

---

### AutoSizeHeader

Automatically sizes all the columns of the header of a listview

```
FUNCTION AutoSizeHeader (BYVAL hListView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

---

### CancelEditLabel

Cancels an item text editing operation.

```
FUNCTION AutoSizeHeader (BYVAL hListView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Remarks

To use **CancelEditLabel**, specify Comctl32.dll version 6 in the manifest.

---

### CreateDragImage

Creates a drag image list for the specified item.

```
FUNCTION CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL lpptUpLeft AS POINT PTR) AS HIMAGELIST
FUNCTION CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF tUpLeft AS POINT) AS HIMAGELIST
FUNCTION CreateDragImage (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the item. |
| *lpptUpLeft* | A pointer to a **POINT** structure that receives the initial location of the upper-left corner of the image, in view coordinates. |
| *tUpLeft* | A **POINT** structure that receives the initial location of the upper-left corner of the image, in view coordinates. |
| *x* | Specifies the x-coordinate of the point. |
| *y* | Specifies the y-coordinate of the point. |

#### Return value

Returns the handle to the drag image list if successful, or NULL otherwise.

#### Remarks

Your application is responsible for destroying the image list when it is no longer needed.

---

### DeleteAllItems

Removes all items from a list-view control.

```
FUNCTION DeleteAllItems (BYVAL hListView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When a list-view control receives the **LVM_DELETEALLITEMS** message, it sends the **LVN_DELETEALLITEMS** notification code to its parent window.

---

### DeleteColumn

Removes a column from a list-view control.

```
FUNCTION DeleteColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | An index of the column to delete. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Deleting column zero of a list-view control is supported only in ComCtl32.dll version 6 and later. Version 5 also supports deleting column zero, but only after you use CCM_SETVERSION to set the version to 5 or later. In versions prior to version 5, if you must delete column zero, insert a zero length dummy column zero and delete column one and above.

---

### DeleteItem

Removes an item from a list-view control.

```
FUNCTION DeleteItem (BYVAL hListView AS HWND, BYVAL i AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | An index of the list-view item to delete. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### EditLabel

Begins in-place editing of the specified list-view item's text. The message implicitly selects and focuses the specified item.

```
FUNCTION EditLabel (BYVAL hListView AS HWND, BYVAL i AS LONG) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. To cancel editing, set i to -1. |

#### Return value

Returns the handle to the edit control that is used to edit the item text if successful, or NULL otherwise.

#### Remarks

When the user completes or cancels editing, the edit control is destroyed and the handle is no longer valid. You can subclass the edit control, but you should not destroy it.

The control must have the focus before you send this message to the control. Focus can be set using the **SetFocus** function.

---

### EnableGroupView

Enables or disables whether the items in a list-view control display as a group.

```
FUNCTION EnableGroupView (BYVAL hListView AS HWND, BYVAL fEnable AS BOOLEAN) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *fEnable* | Boolean TRUE or FALSE. |

#### Return value

Returns one of the following values:

| Return code | Description |
| 0 | The ability to display list-view items as a group is already enabled or disabled. |
| 1 | The state of the control was successfully changed. |
| -1 | The operation failed. |

#### Remarks

To use **EnableGroupView**, specify Comctl32.dll version 6 in the manifest.

---

### EnsureVisible

Ensures that a list-view item is either entirely or partially visible, scrolling the list-view control if necessary. 

```
FUNCTION EnsureVisible (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL fPartialOK AS BOOLEAN) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. |
| *fPartialOK* | A value specifying whether the item must be entirely visible. If this parameter is TRUE, no scrolling occurs if the item is at least partially visible. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### FindItem

Searches for a list-view item with the specified characteristics.

```
FUNCTION FindItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYVAL pvfi AS LVFINDINFOW PTR) AS LONG
FUNCTION FindItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYREF vfi AS LVFINDINFOW) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iStart* | The index of the item after which to begin the search, or -1 to start from the beginning. |
| *pvfi* | A pointer to an **LVFINDINFOW** structure that contains information about what to search for. |
| *vfi* | An **LVFINDINFOW** structure that contains information about what to search for. |

#### Return value

Returns the index of the item if successful, or -1 otherwise.

---

### FindString

Searches for a list-view item with the specified text.

```
FUNCTION FindString (BYVAL hListView AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pwszText* | The unicode string to find. |

#### Return value

Returns the index of the item if successful, or -1 otherwise.

---

### FitContent

Automatically sizes the specified column.

```
FUNCTION FitContent (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | An index to the column to autosize. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### FitHeader

Automatically sizes the column to fit the header text. If you use this value with the last column, its width is set to fill the remaining width of the list-view control.

```
FUNCTION FitHeader (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | An index to the column to autosize. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Assume that you have a 2-column list-view control with a width of 500 pixels. If the width of column zero is set to 200 pixels, and you send this message with iCol = 1 the second (and last) column will be 300 pixels wide.

---

### GetBkColor

Gets the background color of a list-view control.

```
FUNCTION GetBkColor (BYVAL hListView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the background color of the list-view control.

---

### GetBkImage

Gets the background image in a list-view control.

```
FUNCTION GetBkImage (BYVAL hListView AS HWND, BYVAL pvbki AS LVBKIMAGEW PTR) AS BOOLEAN
FUNCTION GetBkImage (BYVAL hListView AS HWND, BYREF vbki AS LVBKIMAGEW) AS BOOLEAN
FUNCTION GetBkImage (BYVAL hListView AS HWND) AS LVBKIMAGEW
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pvbki* | A pointer to a **LVBKIMAGE** structure that will receive the background image information. |
| *vbki* | A **LVBKIMAGE** structure that will receive the background image information. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetCallbackMask

Gets the callback mask for a list-view control.

```
FUNCTION GetCallbackMask (BYVAL hListView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the callback mask.

---

### GetCheckState

Determines if an item in a list-view control is selected. This should be used only for list-view controls that have the **LVS_EX_CHECKBOXES** style.

```
FUNCTION GetCheckState (BYVAL hListView AS HWND, BYVAL i AS LONG) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the item for which to retrieve the check state. |

#### Return value

Returns nonzero if the given item is selected, or zero otherwise. If this method is applied to a list-view control that does not have check boxes enabled, the return value is not reliable.

---

### GetColumn

Gets the attributes of a list-view control's column. 

```
FUNCTION GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS BOOLEAN
FUNCTION GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS BOOLEAN
FUNCTION GetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LVCOLUMNW
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The index of the column. |
| *pcol* | A pointer to an **LVCOLUMNW** structure that specifies the information to retrieve and receives information about the column. The **mask** member specifies which column attributes to retrieve. If the mask member specifies the **LVCF_TEXT** value, the **pszText** member must contain the address of the buffer that receives the item text, and the **cchTextMax** member must specify the size of the buffer. |
| *col* | An **LVCOLUMNW** structure that specifies the information to retrieve and receives information about the column. The **mask** member specifies which column attributes to retrieve. If the mask member specifies the **LVCF_TEXT** value, the **pszText** member must contain the address of the buffer that receives the item text, and the **cchTextMax** member must specify the size of the buffer. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetColumnCount

Gets the number of columns of a listview.

```
FUNCTION GetColumnCount (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the number of items if successful, or -1 otherwise.

---

### GetColumnOrder

Gets the order of the specified column of the listview's header control.

```
FUNCTION GetColumnOrder (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The column number. |

#### Return value

The order in which the item appears within the header control, from left to right. That is, the value for the far left item is 0. The value for the next item to the right is 1, and so on.

---

### GetColumnText

Gets the text of a list-view control's column.

```
FUNCTION GetColumnText (BYVAL hListView AS HWND, BYVAL iCol AS LONG, _
   BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The column number. |
| *cchTextMax* | The maximum number of characters to be returned. |

#### Return value

The column name.

---

### GetColumnOrderArray

Gets the current left-to-right order of columns in a list-view control.

```
FUNCTION GetColumnOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCount* | The number of columns in the list-view control. |
| *lpiArray* | A pointer to an array of integers that will receive the index values of the columns in the list-view control. The array must be large enough to hold *iCount* elements. |

#### Return value

If successful, returns nonzero and the buffer at *lpiArray* receives the column index of each column in the control in the order they appear from left to right. Otherwise, the return value is zero.

---

### GetColumnWidth

Gets the width of a column in report or list view.

```
FUNCTION GetColumnWidth (BYVAL hListView AS HWND, BYVAL iCol AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The column number. |

#### Return value

Returns the column width if successful, or zero otherwise. If this method is used on a list-view control with the **LVS_REPORT** style and the specified column does not exist, the return value is undefined.

---

### GetCountPerPage

Calculates the number of items that can fit vertically in the visible area of a list-view control when in list or report view. Only fully visible items are counted.

```
FUNCTION GetCountPerPage (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the number of fully visible items if successful. If the current view is icon or small icon view, the return value is the total number of items in the list-view control.

---

### GetEditControl

Gets the handle to the edit control being used to edit a list-view item's text.

```
FUNCTION GetEditControl (BYVAL hListView AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the handle to the edit control if successful, or NULL otherwise.

#### Remarks

When label editing begins, an edit control is created, positioned, and initialized. Before it is displayed, the list-view control sends its parent window an LVN_BEGINLABELEDIT notification code.

To customize label editing, implement a handler for **LVN_BEGINLABELEDIT** and have it use **GetEditControl** to send an **LVM_GETEDITCONTROL** message to the list-view control. If a label is being edited, the return value will be a handle to the edit control. Use this handle to customize the edit control by sending the usual **EM_XXX** messages.

When the user completes or cancels editing, the edit control is destroyed and the handle is no longer valid. You can subclass the edit control, but you should not destroy it. To cancel editing, you can send the list-view control a **WM_CANCELMODE** message.

The list-view item being edited is the currently focused item—that is, the item in the focused state. To find an item based on its state, use the **LVM_GETNEXTITEM** message.

---

### GetEmptyText

Gets the text meant for display when the list-view control appears empty.

```
FUNCTION GetEmptyText (BYVAL hListView AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pwszText* | A pointer to a null-terminated, Unicode buffer of size specified by *cchText* to receive the text. The caller is responsible for allocating the buffer. |
| *cchText* | The size of the buffer pointed to by *pszText*, including the terminating NULL. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetExtendedListViewStyle

Gets the extended styles that are currently in use for a given list-view control.

```
FUNCTION GetExtendedListViewStyle (BYVAL hListView AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns a DWORD value that represents the styles currently in use for a given list-view control. This can be a combination of extended styles.

---

### GetFocusedGroup

Gets the group that has the focus.

```
FUNCTION GetFocusedGroup (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the index of the group with state of LVGS_FOCUSED, or -1 if there is no group with state of LVGS_FOCUSED.

---

### GetFocusedItem

Gets the item that has the focus, which may or may not be selected.

```
FUNCTION GetFocusedItem (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the index of the next item if successful, or -1 otherwise.

---

### GetFooterInfo

Gets information on the footer of a specified list-view control.

```
FUNCTION GetFooterInfo (BYVAL hListView AS HWND, BYVAL pvfi AS LVFOOTERINFO PTR) AS BOOLEAN
FUNCTION GetFooterInfo (BYVAL hListView AS HWND, BYREF vfi AS LVFOOTERINFO) AS BOOLEAN
FUNCTION GetFooterInfo (BYVAL hListView AS HWND) AS LVFOOTERINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pvfi* | A pointer to a **LVFOOTERINFO** structure to receive information depending on the value of the mask member. The calling application is responsible for allocating this structure and setting the mask member. |
| *vfi* | A **LVFOOTERINFO** structure to receive information depending on the value of the mask member. The calling application is responsible for allocating this structure and setting the mask member. |

#### Return value

Returns TRUE.

---

### GetFooterItem

Gets information on a footer item for a specified list-view control.

```
FUNCTION GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL pfi AS LVFOOTERITEM PTR) AS BOOLEAN
FUNCTION GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYREF fi AS LVFOOTERITEM) AS BOOLEAN
FUNCTION GetFooterItem (BYVAL hListView AS HWND, BYVAL iItem AS UINT) AS LVFOOTERITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *item* | An index of the item. |
| *pfi* | A pointer to a **LVFOOTERITEM** structure to receive a value for the state and/or pszText members according to the value of the mask member. The caller is responsible for allocating this structure and setting its members to indicate to the receiver what information to return. |
| *fi* | A **LVFOOTERITEM** structure to receive a value for the state and/or pszText members according to the value of the mask member. The caller is responsible for allocating this structure and setting its members to indicate to the receiver what information to return. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetFooterItemRect

Gets the coordinates of a footer for a specified item in a list-view control. 

```
FUNCTION GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetFooterItemRect (BYVAL hListView AS HWND, BYVAL iItem AS UINT) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *item* | An index of the item. |
| *prc* | A pointer to a **RECT** structure to receive the coordinates. The calling application is responsible for allocating this structure. The coordinates received are expressed as client coordinates. |
| *rc* | A **RECT** structure to receive the coordinates. The calling application is responsible for allocating this structure. The coordinates received are expressed as client coordinates. | |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetFooterRect

Gets the coordinates of the footer for a specified list-view control.

```
FUNCTION GetFooterRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetFooterRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetFooterRect (BYVAL hListView AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *item* | An index of the item. |
| *prc* | A pointer to a **RECT** structure to receive the coordinates. The caller is responsible for allocating this structure. The coordinates received are expressed as client coordinates. |
| *rc* | A **RECT** structure to receive the coordinates. The caller is responsible for allocating this structure. The coordinates received are expressed as client coordinates. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetGroupCount

Gets the number of groups.

```
FUNCTION GetGroupCount (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the number of groups if successful, or -1 otherwise.

#### Remarks

To use **GetGroupCount**, specify Comctl32.dll version 6 in the manifest.

---

### GetGroupHeaderImageList

Gets the group header image list that has been set for an existing list-view control.

```
FUNCTION GetGroupHeaderImageList (BYVAL hListView AS HWND) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the handle to the group header image list if successful, or NULL otherwise.

#### Remarks

To specify an image list another way, such as, by large icons, small icons, or state images, send the **LVM_GETIMAGELIST** message explicitly.

---

### GetGroupInfo

Gets group information.

```
FUNCTION GetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
FUNCTION GetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYREF grp AS LVGROUP) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iGroupId* | An ID that specifies the group whose information is retrieved. |
| *pgrp* | A pointer an **LVGROUP** structure that receives the retrieved information. Set the **cbSize** member of this structure to sizeof(LVGROUP). |

#### Return value

Returns the ID of the group if successful, or -1 otherwise.

#### Remarks

Before attempting to retrieve the header for a group, first ensure that the group does not have the **LBGS_NOHEADER** style.

To use **GetGroupInfo**, specify Comctl32.dll version 6 in the manifest.

---

### GetGroupInfoByIndex

Gets information on a specified group

```
FUNCTION GetGroupInfoByIndex (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYREF pgrp AS LVGROUP PTR) AS BOOLEAN
FUNCTION GetGroupInfoByIndex (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYREF grp AS LVGROUP) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iIndex* | The index of the group. |
| *pgrp* | A pointer to an **LVGROUP** structure to receive information on the group specified by *iIndex*. The calling application is responsible for allocating memory for the structure and any buffers in the structure, such as, the one pointed to by **pszHeader**. Set any contingent members of the structure, such as, **cchHeader**—the size of the buffer pointed to by **pszHeader** in characters, including the terminating NULL. Set **cbSize** to the size of **LVGROUP** in bytes. The message receiver is responsible for setting the structure members with information for the group specified by *iIndex*. |

#### Return value

Returns the ID of the group if successful, or -1 otherwise.

#### Remarks

Before attempting to retrieve the header for a group, first ensure that the group does not have the LBGS_NOHEADER style.

To use **GetGroupInfo**, specify Comctl32.dll version 6 in the manifest.

---

### GetGroupMetrics

Gets information about the display of groups.

```
SUB GetGroupMetrics (BYVAL hListView AS HWND, BYVAL pGroupMetrics AS LVGROUPMETRICS PTR)
SUB GetGroupMetrics (BYVAL hListView AS HWND, BYREF GroupMetrics AS LVGROUPMETRICS)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pGroupMetrics* | A pointer to an **LVGROUPMETRICS** structure that receives the retrieved metrics. |
| *GroupMetrics* | An **LVGROUPMETRICS** structure that receives the retrieved metrics. |

#### Remarks

To use **GetGroupMetrics**, specify Comctl32.dll version 6 in the manifest.

---

### GetGroupRect

Gets the rectangle for a specified group.

```
FUNCTION GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, _
   BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, _
   BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetGroupRect (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL nType AS LONG) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iGroupId* | Specifies the group by iGroupId (see LVGROUP structure). |
| *nType* | Specifies the type of rectangle to retrieve. This parameter must be one of the following values (see table below). |
| *prc* | A pointer to a **RECT** structure to receive information on the group specified by **iGroupId**. The message receiver is responsible for setting the structure members with information for the group specified by **iGroupId**. The calling application is responsible for allocating memory for the structure. |
| *rc* | A **RECT** structure to receive information on the group specified by **iGroupId**. The message receiver is responsible for setting the structure members with information for the group specified by **iGroupId**. The calling application is responsible for allocating memory for the structure. |

**Rectangle type**:

| Value | Meaning |
| ----- | ------- |
| **LVGGR_GROUP** | Coordinates of the entire expanded group. |
| **LVGGR_HEADER** | Coordinates of the header only (collapsed group). |
| **LVGGR_LABEL** | Coordinates of the label only. |
| **LVGGR_SUBSETLINK** | Coordinates of the subset link only (markup subset). A list-view control can limit the number of visible items displayed in each group. A link is presented to the user to allow the user to expand the group. This flag will return the bounding rectangle of the subset link if the group is a subset (group state of LVGS_SUBSETED, see structure LVGROUP, member state). This flag is provided so that accessibility applications can locate the link. |

#### Remarks

Returns TRUE if successful, or FALSE otherwise.

---

### GetGroupState

Gets the state for a specified group.

```
FUNCTION GetGroupState (BYVAL hListView AS HWND, BYVAL dwGroupId AS UINT, BYVAL dwMask AS UINT) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *dwGroupId* | Specifies the group by **iGroupId** (see LVGROUP structure). |
| *dwMask* | Specifies the state values to retrieve. This is a combination of the flags listed for the **state** member of LVGROUP. |

#### Remarks

Returns the combination of state values that are set. For example, if **dwMask** is LVGS_COLLAPSED and the value returned is zero, the LVGS_COLLAPSED state is not set. Zero is returned if the group is not found.

---

### GetHeader

Gets the handle to the header control used by a list-view control. 

```
FUNCTION GetHeader (BYVAL hListView AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Remarks

Returns the handle to the header control.

---

### GetHeaderText

Gets the text of the specified column of the header of a listview control.

```
FUNCTION GetHeaderText (BYVAL hListView AS HWND, BYVAL iCol AS LONG, _
   BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The Zero-based index of the column. |
| *cchTextMax* | Maximum number of characters to return, including the terminating null character. |

#### Remarks

Returns the retrieved text.

---

### GetHotCursor

Gets the HCURSOR used when the pointer is over an item while hot tracking is enabled. 

```
FUNCTION GetHotCursor (BYVAL hListView AS HWND) AS HCURSOR
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns an HCURSOR value that is the handle to the cursor that the list-view control uses when hot tracking is enabled.

#### Remarks

A list-view control uses hot tracking and hover selection when the LVS_EX_TRACKSELECT style is set.

---

### GetHotItem

Gets the index of the hot item.

```
FUNCTION GetHotItem (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the index of the item that is currently hot.

---

### GetHoverTime

Gets the amount of time that the mouse cursor must hover over an item before it is selected.

```
FUNCTION GetHoverTime (BYVAL hListView AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the amount of time, in milliseconds, that the mouse cursor must hover over an item before it is selected. If the return value is (DWORD)-1, then the hover time is the default hover time.

#### Remarks

The hover time only affects list-view controls that have the LVS_EX_TRACKSELECT, LVS_EX_ONECLICKACTIVATE, or LVS_EX_TWOCLICKACTIVATE extended list-view style.

---

### GetImageList

Gets the handle to an image list used for drawing list-view items.

```
FUNCTION GetImageList (BYVAL hListView AS HWND, BYVAL iImageList AS LONG) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iImageList* | The image list to retrieve. This parameter can be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **LVSIL_NORMAL** | Image list with large icons. |
| **LVSIL_SMALL** | Image list with small icons. |
| **LVSIL_STATE** | Image list with state images. |
| **LVSIL_GROUPHEADER** | Image list for group header. |

#### Return value

Returns the handle to the specified image list if successful, or NULL otherwise.

---

### GetInsertMark

Gets the position of the insertion point.

```
FUNCTION GetInsertMark (BYVAL hListView AS HWND, BYVAL pvim AS LVINSERTMARK PTR) AS BOOLEAN
FUNCTION GetInsertMark (BYVAL hListView AS HWND, BYREF vim AS LVINSERTMARK) AS BOOLEAN
FUNCTION GetInsertMark (BYVAL hListView AS HWND) AS LVINSERTMARK
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pvim* | Pointer to a **LVINSERTMARK** structure that receives the position of the insertion point. |
| *vim* | A **LVINSERTMARK** structure that receives the position of the insertion point. |

#### Return value

Returns TRUE if successful, or FALSE otherwise. Returns FALSE if the size in the **cbSize** member of the **LVINSERTMARK** structure does not equal the actual size of the structure.

#### Remarks

To use this method, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### GetInsertMarkColor

Gets the color of the insertion point.

```
FUNCTION GetInsertMarkColor (BYVAL hListView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns a **COLORREF** value that contains the color of the insertion point.

#### Remarks

To use **GetInsertMarkColor**, specify Comctl32.dll version 6 in the manifest

---

### GetInsertMarkRect

Gets the rectangle that bounds the insertion point.

```
FUNCTION GetInsertMarkRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS LONG
FUNCTION GetInsertMarkRect (BYVAL hListView AS HWND, BYREF prc AS RECT) AS LONG
FUNCTION GetInsertMarkRect (BYVAL hListView AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *prc* | Pointer to a **RECT** structure that contains the coordinates of a rectangle that bounds the insertion point. |
| *rc* | A **RECT** structure that contains the coordinates of a rectangle that bounds the insertion point. |

#### Return value

Returns one of the following values.

| Return code | Description |
| ----------- | ----------- |
| 0 | No insertion point found. |
| 1 | Insertion point found. |

#### Remarks

To use **GetInsertMarkRect**, specify Comctl32.dll version 6 in the manifest

---

### GetISearchString

Gets the incremental search string of a list-view control. 

```
FUNCTION GetISearchString (BYVAL hListView AS HWND) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the incremental search string.

#### Remarks

The incremental search string is the character sequence that the user types while the list view has the input focus. Each time the user types a character, the system appends the character to the search string and then searches for a matching item. If the system finds a match, it selects the item and, if necessary, scrolls it into view.

A time-out period is associated with each character that the user types. If the time-out period elapses before the user types another character, the incremental search string is reset.

---

### GetISearchStringLen

Gets the length of the incremental search string of a list-view control.

```
FUNCTION GetISearchStringLen (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the length of the incremental search string.

#### Remarks

The incremental search string is the character sequence that the user types while the list view has the input focus. Each time the user types a character, the system appends the character to the search string and then searches for a matching item. If the system finds a match, it selects the item and, if necessary, scrolls it into view.

A time-out period is associated with each character that the user types. If the time-out period elapses before the user types another character, the incremental search string is reset.

---

### GetItem

Gets some or all of a list-view item's attributes.

```
FUNCTION GetItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS BOOLEAN
FUNCTION GetItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pitem* | A pointer to an **LVITEMW** structure that specifies the information to retrieve and receives information about the list-view item. |
| *item* | An **LVITEMW** structure that specifies the information to retrieve and receives information about the list-view item. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When the **LVM_GETITEM** message is sent, the **iItem** and **iSubItem** members identify the item or subitem to retrieve information about and the mask member specifies which attributes to retrieve. For a list of possible values, see the description of the **LVITEM** structure.

If the **LVIF_TEXT** flag is set in the mask member of the **LVITEMW** structure, the **pszText** member must point to a valid buffer and the **cchTextMax** member must be set to the number of characters in that buffer. Applications should not assume that the text will necessarily be placed in the specified buffer. The control may instead change the pszText member of the structure to point to the new text rather than place it in the buffer.

If the mask member specifies the **LVIF_STATE** value, the stateMask member must specify the item state bits to retrieve. On output, the state member contains the values of the specified state bits.

---

### GetItemCount

Gets the number of items in a list-view control.

```
FUNCTION GetItemCount (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the number of items.

---

### GetItemIndexRect

Gets the bounding rectangle for all or part of a subitem in the current view of a specified list-view control.

```
FUNCTION GetItemIndexRect (BYVAL hListView AS HWND, BYVAL pvii AS LVITEMINDEX PTR, _
   BYVAL iSubItem AS LONG, BYVAL code AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetItemIndexRect (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, _
   BYVAL iSubItem AS LONG, BYVAL code AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetItemIndexRect (BYVAL hListView AS HWND, BYREF vii AS LVITEMINDEX, _
   BYVAL iSubItem AS LONG, BYVAL code AS LONG) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *lvii* | A pointer to a **LVITEMINDEX++ structure for the parent item of the subitem. The caller is responsible for allocating this structure and setting its members. *plvii* must not be NULL. |
| *iSubItem* | The index of the subitem. |
| *code* | The portion of the list-view subitem for which to retrieve the bounding rectangle. This parameter must be one of the following values (see table below): |
| *prc* | A pointer to a **RECT** structure to receive the coordinates. The caller is responsible for allocating this structure. *prc* must not be NULL. |

| Value | Meaning |
| ----- | ------- |
| **LVIR_BOUNDS** | Returns the bounding rectangle of the entire subitem, including the icon and label. |
| **LVIR_ICON** | Returns the bounding rectangle of the icon or small icon of the subitem. |
| **LVIR_LABEL** | Returns the bounding rectangle of the subitem text. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If *iSubItem* is zero, this method returns the coordinates of the rectangle to the item pointed to by *plvii*. The value *LVIR_SELECTBOUNDS* for the parameter *code* is not supported.

---

### GetItemPosition

Gets the position of a list-view item. 

```
FUNCTION GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL ppt AS POINT PTR) AS BOOLEAN
FUNCTION GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF pt AS POINT) AS BOOLEAN
FUNCTION GetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG) AS POINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. |
| *ppt* | A pointer to a **POINT** structure that receives the position of the item's upper-left corner, in view coordinates. |
| *pt* | A pointer to a **POINT** structure that receives the position of the item's upper-left corner, in view coordinates. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetItemRect

Gets the bounding rectangle for all or part of an item in the current view.

```
FUNCTION GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL code AS LONG) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. |
| *prc* | A pointer to a **RECT** structure that receives the bounding rectangle. |
| *rc* | A **RECT** structure that receives the bounding rectangle. |
| *code* | The portion of the list-view item from which to retrieve the bounding rectangle. This parameter must be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **LVIR_BOUNDS** | Returns the bounding rectangle of the entire subitem, including the icon and label. |
| **LVIR_ICON** | Returns the bounding rectangle of the icon or small icon of the subitem. |
| **LVIR_LABEL** | Returns the bounding rectangle of the subitem text. |
| **LVIR_SELECTBOUNDS** | Returns the union of the LVIR_ICON and LVIR_LABEL rectangles, but excludes columns in report view. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetItemSpacing

Determines the spacing between items in a list-view control.

```
FUNCTION GetItemSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *fSmall* | A view for which to retrieve the item spacing. This parameter is TRUE for small icon view, or FALSE for icon view. |

#### Return value

Returns the amount of spacing between items. The horizontal spacing is contained in the LOWORD and the vertical spacing is contained in the HIWORD.

---

### GetItemHorizontalSpacing

Determines the horizomtal spacing between items in a list-view control.

```
FUNCTION GetItemHorizontalSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *fSmall* | A view for which to retrieve the item spacing. This parameter is TRUE for small icon view, or FALSE for icon view. |

#### Return value

Returns the horizontal spacing between items.

---

### GetItemVerticalSpacing

Determines the vertical spacing between items in a list-view control.

```
FUNCTION GetItemVerticalSpacing (BYVAL hListView AS HWND, BYVAL fSmall AS BOOLEAN) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *fSmall* | A view for which to retrieve the item spacing. This parameter is TRUE for small icon view, or FALSE for icon view. |

#### Return value

Returns the vertical spacing between items.

---

### GetItemState

Gets the state of a list-view item.

```
FUNCTION GetItemState (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL mask AS LONG) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. |
| *mask* | The state information to retrieve. This parameter can be a combination of the following values: |

| Value | Meaning |
| ----- | ------- |
| **LVIS_CUT** | The item is marked for a cut-and-paste operation. |
| **LVIS_DROPHILITED** | The item is highlighted as a drag-and-drop target. |
| **LVIS_FOCUSED** | The item has the focus, so it is surrounded by a standard focus rectangle. Although more than one item may be selected, only one item can have the focus. |
| **LVIS_SELECTED** | The item is selected. The appearance of a selected item depends on whether it has the focus and also on the system colors used for selection. |
| **LVIS_OVERLAYMASK** | Use this mask to retrieve the item's overlay image index. |
| **LVIS_STATEIMAGEMASK** | Use this mask to retrieve the item's state image index. |

#### Return value

Returns the current state for the specified item. The only valid bits in the return value are those that correspond to the bits set in the mask parameter.

#### Remarks

An item's state information includes a set of bit flags as well as image list indexes that indicate the item's state image and overlay image.

---

### GetItemText

Gets the text of a list-view item or subitem.

```
SUB GetItemText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, _
   BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG  = MAX_PATH + 1)
FUNCTION GetText (BYVAL hListView AS HWND, BYVAL item AS LONG, BYVAL iSubItem AS LONG, _
   BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *item* | The index of the list-view item. |
| *iSubItem* | The index of the subitem. To retrieve the item text, set iSubItem_ to zero. |
| *pwszText* | A pointer to a buffer that receives the item or subitem text. |
| *cchTextMax* | The number of characters in the *pwszText* buffer. |

---

### GetNextItem

Searches for a list-view item that has the specified properties and bears the specified relationship to a specified item.

```
FUNCTION GetNextItem (BYVAL hListView AS HWND, BYVAL iStart AS LONG, BYVAL flags AS UINT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iStart* | The index of the item with which to begin the search, or -1 to find the first item that matches the specified flags. The specified item itself is excluded from the search. |
| *flags* | The geometric relation of the requested item to the specified item and, if specified, the state of the requested item. For a list of possible values, see the description of the lParam parameter in the **LVM_GETNEXTITEM** message. If an item does not have all of the specified state flags set, the search continues with the next item. |

#### Return value

Returns the index of the next item if successful, or -1 otherwise.

---

### GetNextItemIndex

Gets the index of the item in a particular list-view control that has the specified properties and relationship to another specific item.

```
FUNCTION GetNextItemIndex (BYVAL hListView AS HWND, BYVAL plvii AS LVITEMINDEX PTR, BYVAL flags AS ..LPARAM) AS LONG
FUNCTION GetNextItemIndex (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, BYVAL flags AS ..LPARAM) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvii* | A pointer to the **LVITEMINDEX** structure with which the item begins the search, or -1 to find the first item that matches the specified flags. The calling process is responsible for allocating this structure and setting its members. |
| *lvii* | A **LVITEMINDEX** structure with which the item begins the search, or -1 to find the first item that matches the specified flags. The calling process is responsible for allocating this structure and setting its members. | |
| *flags* | The relationship to the item specified in parameter plvii. This can be one or a combination of the following values: |

| Value | Meaning |
| ----- | ------- |
| **LVNI_ALL** | Searches for a subsequent item by index, the default value. |
| **LVNI_ABOVE** | Searches for an item that is above the specified item. |
| **LVNI_BELOW** | Searches for an item that is below the specified item. |
| **LVNI_TOLEFT** | Searches for an item to the left of the specified item. |
| **LVNI_PREVIOUS** | Windows Vista and later: Searches for the item that is previous to the specified item. The LVNI_PREVIOUS flag is not directional (LVNI_ABOVE will find the item positioned above, while LVNI_PREVIOUS will find the item ordered before.) The LVNI_PREVIOUS flag essentially reverses the logic of the search performed via the LVM_GETNEXTITEM or LVM_GETNEXTITEMINDEX messages. |
| **LVNI_TORIGHT** | Searches for an item to the right of the specified item. |
| **LVNI_DIRECTIONMASK** | Windows Vista and later: A directional flag mask with value as follows: LVNI_ABOVE OR LVNI_BELOW OR LVNI_TOLEFT OR LVNI_TORIGHT. The state of the item to find can be specified with one or a combination of the following values: |
| **LVNI_CUT** | The item has the LVIS_CUT state flag set. |
| **LVNI_DROPHILITED** | The item has the LVIS_DROPHILITED state flag set. |
| **LVNI_FOCUSED** | The item has the LVIS_FOCUSED state flag set. |
| **LVNI_SELECTED** | The item has the LVIS_SELECTED state flag set. |
| **LVNI_STATEMASK** | Windows Vista and later: A state flag mask with value as follows: LVNI_FOCUSED OR LVNI_SELECTED OR LVNI_CUT OR LVNI_DROPHILITED. |
| **LVNI_VISIBLEORDER** | Windows Vista and later: Search the visible order. |
| **LVNI_VISIBLEONLY** | Windows Vista and later: Search the visible items. |
| **LVNI_SAMEGROUPONLY** | Windows Vista and later: Search the current group. |

If an item does not have all of the specified state flags set, the search continues with the next item.

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Note that the following flags, for use only with Windows Vista, are mutually exclusive of any other flags in use: LVNI_PREVIOUS, LVNI_VISIBLEONLY, LVNI_SAMEGROUPONLY, LVNI_VISIBLEORDER, LVNI_DIRECTIONMASK, and LVNI_STATEMASK.

---

### GetNumberOfWorkAreas

Gets the number of working areas in a list-view control.

```
FUNCTION GetNumberOfWorkAreas (BYVAL hListView AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

The number of working areas in the list-view control.

---

### GetOrderArray

Gets the current left-to-right order of items in the header of a listview control.

```
FUNCTION GetOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS DWORD, BYVAL lpi AS LONG PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCount* | The number of integer elements that *lpi* can hold. This value must be equal to the number of items in the control (see HDM_GETITEMCOUNT). |
| *lpi* | A pointer to an array of integers that receive the index values for items in the header. |

#### Return value

Returns nonzero if successful, and the buffer at *lpi* receives the item number for each item in the header control in the order in which they appear from left to right. Otherwise, the message returns zero.

#### Remarks

The number of elements in *lpi* is specified in *iCount* and must be equal to the number of items in the control. For example, the following code fragment will reserve enough memory to hold the index values.

---

### GetOrigin

Gets the current view origin for a list-view control.

```
FUNCTION GetOrigin (BYVAL hListView AS HWND, BYVAL pptOrg AS POINT PTR) AS BOOLEAN
FUNCTION GetOrigin (BYVAL hListView AS HWND, BYREF ptOrg AS POINT) AS BOOLEAN
FUNCTION GetOrigin (BYVAL hListView AS HWND) AS POINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pptOrg* | A pointer to a **POINT** structure that receives the view origin. |
| *ptOrg* | A **POINT** structure that receives the view origin. |

#### Return value

Returns TRUE if successful, or FALSE if the current view is list or report view.

---

### GetOutlineColor

Gets the color of the border of a list-view control if the **LVS_EX_BORDERSELECT** extended window style is set.

```
FUNCTION GetOutlineColor (BYVAL hListView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns a **COLORREF** structure that contains the color of the border of a list-view control.

#### Remarks

To use **GetOutlineColor**, specify Comctl32.dll version 6 in the manifest.

---

### GetSelectedColumn

Gets an integer that specifies the selected column.

```
FUNCTION GetSelectedColumn (BYVAL hListView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns a UINT that specifies the selected column.

#### Remarks

To use **GetSelectedColumn**, specify Comctl32.dll version 6 in the manifest.

---

### GetSelectedCount

Determines the number of selected items in a list-view control.

```
FUNCTION GetSelectedCount (BYVAL hListView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the number of selected items.

---

### GetSelection

Returns the zero-based index of the currently selected item.

```
FUNCTION GetSelection (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

THe zero-based index of the currently selected item.

---

### GetSelectionMark

Gets the selection mark from a list-view control.

```
FUNCTION GetSelectionMark (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the zero-based selection mark, or -1 if there is no selection mark.

#### Remarks

The selection mark is the item index from which a multiple selection starts.

---

### GetStringWidth

Determines the width of a specified string using the specified list-view control's current font.

```
FUNCTION GetStringWidth (BYVAL hListView AS HWND, BYREF wszText AS WSTRING) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *wszText* | A pointer to a null-terminated string. |

#### Return value

Returns the string width if successful, or zero otherwise.

#### Remarks

The **GetStringWidth** method returns the exact width, in pixels, of the specified string. If you use the returned string width as the column width in a call to the **SetColumnWidth** metod, the string will be truncated. To retrieve the column width that can contain the string without truncating it, you must add padding to the returned string width.

---

### GetSubItemRect

Gets information about the rectangle that surrounds a subitem in a list-view control. This method is intended to be used only on list-view controls that use the **LVS_REPORT** style.

```
FUNCTION GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, _
   BYVAL nCode AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, _
   BYVAL nCode AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetSubItemRect (BYVAL hListView AS HWND, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, _
   BYVAL nCode AS LONG) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iItem* | The index of the subitem's parent item. |
| *iSubItem* | The one-based index of the subitem. |
| *nCode* | A portion of the list-view subitem for which to retrieve the bounding rectangle information. This value can be one of the following: See table below. |
| *iSubItem* | The one-based index of the subitem. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetTextBkColor

Gets the text background color of a list-view control.

```
FUNCTION GetTextBkColor (BYVAL hListView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the background color of the text.

---

### GetTextColor

Gets the text color of a list-view control.

```
FUNCTION GetTextColor (BYVAL hListView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the text color.

---

### GetTileInfo

Gets information about a tile in a list-view control.

```
SUB GetTileInfo (BYVAL hListView AS HWND, BYVAL pti AS LVTILEINFO PTR)
SUB GetTileInfo (BYVAL hListView AS HWND, BYREF ti AS LVTILEINFO)
FUNCTION GetTileInfo (BYVAL hListView AS HWND) AS LVTILEINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pti* | Pointer to an **LVTILEINFO** structure that receives the retrieved information. |
| *ti* | An **LVTILEINFO** structure that receives the retrieved information. |

#### Remarks

To use **GetTileInfo**, specify Comctl32.dll version 6 in the manifest.

---

### GetTileViewInfo

Gets information about a list-view control in tile view.

```
SUB GetTileViewInfo (BYVAL hListView AS HWND, BYVAL ptvi AS LVTILEVIEWINFO PTR)
SUB GetTileViewInfo (BYVAL hListView AS HWND, BYREF tvi AS LVTILEVIEWINFO)
FUNCTION GetTileViewInfo (BYVAL hListView AS HWND) AS LVTILEVIEWINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *ptvi* | Pointer to an **LVTILEVIEWINFO** structure that receives the retrieved information. |
| *tvi* | An **LVTILEVIEWINFO** structure that receives the retrieved information. |

#### Remarks

To use **GetTileViewInfo**, specify Comctl32.dll version 6 in the manifest.

---

### GetToolTips

Gets the tooltip control that the list-view control uses to display tooltips.

```
FUNCTION GetToolTips (BYVAL hListView AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the handle to the tooltip control.

---

### GetTooltipsFont

Retrieves the font used by the ToolTip control that the list-view control uses to display tooltips.

```
FUNCTION GetTooltipsFont (BYVAL hListView AS HWND) AS HFONT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

The return value is a handle to the font used by the control, or NULL if the control is using the system font.

---

### GetTopIndex

Gets the index of the topmost visible item when in list or report view.

```
FUNCTION GetTopIndex (BYVAL hListView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns the index of the item if successful, or zero if the list-view control is in icon or small icon view.

---

### GetView

Gets the current view of a list-view control.

```
FUNCTION GetView (BYVAL hListView AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns a DWORD that specifies the current view.

#### Remarks

To use **GetView**, specify Comctl32.dll version 6 in the manifest. 

---

### GetViewRect

Gets the bounding rectangle of all items in the list-view control. The list view must be in icon or small icon view.

```
FUNCTION GetViewRect (BYVAL hListView AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetViewRect (BYVAL hListView AS HWND, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetViewRect (BYVAL hListView AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *prc* | A pointer to a **RECT** structure that receives the bounding rectangle. All coordinates are relative to the visible area of the list-view control. |
| *rc* | A **RECT** structure that receives the bounding rectangle. All coordinates are relative to the visible area of the list-view control. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetWorkAreas

Gets the working areas from a list-view control. 

```
SUB GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYVAL prc AS RECT PTR)
SUB GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYREF rc AS RECT)
FUNCION GetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *nWorkAreas* | The number of **RECT** structures in the array at *prc*. |
| *prc* | A pointer to an array of **RECT** structures that receive the working areas of the list-view control. Values in these structures are in client coordinates. *nWorkAreas* specifies the number of structures in this array. |
| *rc* | An array of **RECT** structures that receive the working areas of the list-view control. Values in these structures are in client coordinates. *nWorkAreas* specifies the number of structures in this array. |

---

### HasGroup

Determines whether the list-view control has a specified group.

```
FUNCION HasGroup (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iGroupId* | ID of the group. |

#### Return value

Returns TRUE if the list-view control has the specified group, or FALSE otherwise.

#### Remarks

To use ListView_HasGroup, specify Comctl32.dll version 6 in the manifest

---

### HitTest

Determines which list-view item, if any, is at a specified position.

```
FUNCION HitTest (BYVAL hListView AS HWND, BYVAL pinfo AS LVHITTESTINFO PTR) AS LONG
FUNCION HitTest (BYVAL hListView AS HWND, BYREF info AS LVHITTESTINFO) AS LONG
FUNCION HitTest (BYVAL hListView AS HWND) AS LVHITTESTINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pinfo* | A pointer to an **LVHITTESTINFO** structure that contains the position to hit test and receives information about the results of the hit test. |
| *info* | An **LVHITTESTINFO** structure that contains the position to hit test and receives information about the results of the hit test. |

#### Return value

Returns the index of the item at the specified position, if any, or -1 otherwise.

---

### HitTestEx

Determines which list-view item, if any, is at a specified position.

```
FUNCION HitTestEx (BYVAL hListView AS HWND, BYREF pinfo AS LVHITTESTINFO PTR) AS LONG
FUNCION HitTestEx (BYVAL hListView AS HWND, BYREF info AS LVHITTESTINFO) AS LONG
FUNCION HitTestEx (BYVAL hListView AS HWND) AS LVHITTESTINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pinfo* | A pointer to an **LVHITTESTINFO** structure that contains the position to hit test and receives information about the results of the hit test. |
| *info* | An **LVHITTESTINFO** structure that contains the position to hit test and receives information about the results of the hit test. |

#### Return value

Returns the index of the item at the specified position, if any, or -1 otherwise.

#### Remarks

This method passes -1 as the wParam of the message, specifying that the **iGroup** and **iSubItem** members of *pinfo* are retrieved.

---

### InsertColumn

Inserts a new column in a list-view control.

```
FUNCTION InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS LONG
FUNCTION InsertColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The index of the new column. |
| *pcol* | A pointer to an **LVCOLUMNW** structure that contains the attributes of the new column. |
| *col* | An **LVCOLUMNW** structure that contains the attributes of the new column. |

#### Return value

Returns the index of the new column if successful, or -1 otherwise.

#### Remarks

Columns are visible only in report (details) view.

---

### InsertGroup

Inserts a group into a list-view control.

```
FUNCTION InsertGroup (BYVAL hListView AS HWND, BYVAL index AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
FUNCTION InsertGroup (BYVAL hListView AS HWND, BYVAL index AS LONG, BYREF grp AS LVGROUP) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *index* | Index where the group is to be added. If this is -1, the group is added at the end of the list. |
| *pgrp* | Pointer to a **LVGROUP** structure that contains the group to add. |
| *grp* | A **LVGROUP** structure that contains the group to add. |

#### Return value

Returns the index of the item that the group was added to, or -1 if the operation failed.

#### Remarks

To turn on group mode, call **LVM_ENABLEGROUPVIEW** or **EnableGroupView**.

To use **InsertGroup**, specify Comctl32.dll version 6 in the manifest.

---

### InsertGroupSorted

Inserts a group into an ordered list of groups.

```
SUB InsertGroupSorted (BYVAL hListView AS HWND, BYVAL pstructInsert AS LVINSERTGROUPSORTED PTR)
SUB InsertGroupSorted (BYVAL hListView AS HWND, BYREF structInsert AS LVINSERTGROUPSORTED)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pstructInsert* | Pointer to an **LVINSERTGROUPSORTED** structure that contains the group to insert. |
| *structInsert* | An **LVINSERTGROUPSORTED** structure that contains the group to insert. |

#### Return value

Returns the index of the item that the group was added to, or -1 if the operation failed.

#### Remarks

To use **InsertGroupSorted**, specify Comctl32.dll version 6 in the manifest.

---

### InsertItem

Inserts a new item in a list-view control.

```
FUNCTION InsertItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS LONG
FUNCTION InsertItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pitem* | A pointer to an **LVITEMW** structure that specifies the attributes of the list-view item. Use the iItem member to specify the zero-based index at which the new item should be inserted. If this value is greater than the number of items currently contained by the listview control, the new item will be appended to the end of the list and assigned the correct index. Examine the method's return value to determine the actual index assigned to the item. |

#### Return value

Returns the index of the new item if successful, or -1 otherwise.

#### Remarks

You cannot use **InsertItem** or **LVM_INSERTITEM** to insert subitems. The **iSubItem** member of the **LVITEMW** structure must be zero. See **LVM_SETITEM** for information on setting subitems.

If a list-view control has the **LVS_EX_CHECKBOXES** style set, any value placed in bits 12 through 15 of the state member of the **LVITEMW** structure will be ignored. When an item is added with this style set, it will always be set to the unchecked state.

If a list-view control has either the **LVS_SORTASCENDING** or **LVS_SORTDESCENDING** window style, an **LVM_INSERTITEM** message will fail if you try to insert an item that has **LPSTR_TEXTCALLBACK** as the **pszText** member of its **LVITEMW** structure.

The **InsertItem** method will insert the new item in the proper position in the sort order if the following conditions hold:

* You are using one of the LVS_SORTXXX styles.
* You are not using the LVS_OWNERDRAW style.
* The **pszText** member of the structure pointed to by pitem is not set to LPSTR_TEXTCALLBACK.

---

### InsertMarkHitTest

Retrieves the insertion point closest to a specified point.

```
FUNCTION InsertMarkHitTest (BYVAL hListView AS HWND, BYVAL ppt AS POINT PTR, _
   BYVAL pvim AS LVINSERTMARK PTR) AS BOOLEAN
FUNCTION InsertMarkHitTest (BYVAL hListView AS HWND, BYREF pt AS POINT, _
   BYREF vim AS LVINSERTMARK) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *ppt* | Pointer to a **POINT** structure that contains the hit test coordinates. |
| *pvim* | Pointer to an **LVINSERTMARK** structure that specifies the insertion point closest to the coordinates defined by the *ppt* parameter. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

To use **InsertMarkHitTest**, specify Comctl32.dll version 6 in the manifest.

---

### IsGroupViewEnabled

Checks whether the list-view control has group view enabled.

```
FUNCTION IsGroupViewEnabled (BYVAL hListView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns TRUE if group view is enabled, or FALSE otherwise.

#### Remarks

To use **IsGroupViewEnabled**, specify Comctl32.dll version 6 in the manifest.

---

### IsItemVisible

Indicates whether an item in the list-view control is visible.

```
FUNCTION IsItemVisible (BYVAL hListView AS HWND, BYVAL index AS UINT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

Returns TRUE if group view is enabled, or FALSE otherwise.

---

### MakeHeaderFlat

Removes the HDS_BUTTONS style from the header control to give it a flat appearance.

```
SUB MakeHeaderFlat (BYVAL hListView AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

---

### MapIDToIndex

Maps the ID of an item to an index.

```
FUNCTION MapIDToIndex (BYVAL hListView AS HWND, BYVAL id AS UINT) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *id* | A UINT that contains the unique ID of an item. |

#### Return value

Returns the most current index.

#### Remarks

List-view controls internally track items by index. This can present problems because indexes can change during the control's existence.

You can use this method to tag an item with an ID when you create the item. You use this ID to guarantee uniqueness during the existence of the list-view control.

To uniquely identify an item, take the index that returns from a call such IComponent.GetDisplayInfo and call **LVM_MAPINDEXTOID**. The return value is a unique ID.

If you need to know the index of an item after creating an ID, call **LVM_MAPIDTOINDEX** with the unique ID and it returns the most current index.

**Note**: In a multithreaded environment, you can only be sure the correct index is returned on the thread that hosts the list-view control, not on background threads.
 
To use **apIDToIndex**, specify Comctl32.dll version 6 in the manifest.

---

### MapIndexToID

Maps the index of an item to a unique ID.

```
FUNCTION MapIndexToID (BYVAL hListView AS HWND, BYVAL index AS UINT) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *index* | A UINT that contains the index of an item. |

#### Return value

Returns a unique ID.

#### Remarks

List-view controls internally track items by index. This can present problems because indexes can change during the control's existence.

You can use this method to tag an item with an ID when you create the item. You use this ID to guarantee uniqueness during the existence of the list-view control.

To uniquely identify an item, take the index that is returned from a call such IComponent.GetDisplayInfo and call **LVM_MAPINDEXTOID**. The return value is a unique ID.

**Note**: In a multithreaded environment, you can only be sure the correct index is returned on the thread that hosts the list-view control, not on background threads.
 
To use **MapIndexToID**, specify Comctl32.dll version 6 in the manifest.

---

### ModifyHeaderFont

Modifies the font used by the listview header.

```
FUNCTION ModifyHeaderFont (BYVAL hListView AS HWND, BYREF wszFaceName AS WSTRING, _
   BYVAL lPointSize AS LONG, BYVAL lWeight AS LONG, BYVAL bItalic AS BYTE, BYVAL bUnderline AS BYTE, _
   BYVAL bStrikeOut AS BYTE, BYVAL bCharSet AS BYTE) AS HFONT              
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *wszFaceName* | The name of the font. |
| *lPointSize* | The font point size. |
| *lWeight* | The font weight. |
| *bItalic* | Italic, true or false. |
| *bUnderline* | Underline, true or false. |
| *bStrikeOut* | StrikeOut, true or false. |
| *bCharset* | Character set. |

#### Return value

The handle of the new font. The returned font must be destroyed with **DeleteObject** when no longer needed to prevent memory leaks.

---

### RedrawItems

Forces a list-view control to redraw a range of items.

```
FUNCTION RedrawItems (BYVAL hListView AS HWND, BYVAL iFirst AS LONG, BYVAL iLast AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iFirst* | The index of the first item to redraw. |
| *iLast* | The index of the last item to redraw. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The specified items are not actually redrawn until the list-view window receives a **WM_PAINT** message to repaint. To repaint immediately, call the **UpdateWindow** function after using this method.

---

### RemoveAllGroups

Removes all groups from a list-view control.

```
SUB RemoveAllGroups (BYVAL hListView AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Remarks

To use **RemoveAllGroups**, specify Comctl32.dll version 6 in the manifest.

---

### RemoveDarkMode

Removes the listview dark mode.

```
FUNCTION RemoveDarkMode (BYVAL hListView AS HWND) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

---

### RemoveGroup

Removes a group from a list-view control.

```
FUNCTION RemoveGroup (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iGroupId* | Identifier (ID) that specifies the group to remove. |

#### Return Values

Returns the index of the group if successful, or -1 otherwise.

---

### Scroll

Scrolls the content of a list-view control.

```
FUNCTION Scroll (BYVAL hListView AS HWND, BYVAL dx AS LONG, BYVAL dy AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *dx* | A value of type int that specifies the amount of horizontal scrolling, in pixels, relative to the current position of the list view content. If the list-view control is in list view, this value is rounded up to the nearest number of pixels that form a whole column. |
| *dy* | A value of type int that specifies the amount of vertical scrolling, in pixels, relative to the current position of the list view content. |

#### Return Values

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When the list-view control is in report view, the control can only be scrolled vertically in whole line increments. Therefore, the dy parameter will be rounded to the nearest number of pixels that form a whole line increment. For example, if the height of a line is 16 pixels and 8 is passed for dy, the list will be scrolled by 16 pixels (1 line). If 7 is passed for dy, the list will be scrolled 0 pixels (0 lines).

---

### SelectAllItems

Selects all items.

```
SUB SelectAllItems (BYVAL hListView AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

---

### SelectItem

Selects a ListView item.

```
SUB SelectItem (BYVAL hListView AS HWND, BYVAL iIndex AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iIndex* | Index of the item to select. |

#### Remarks

Windows does not provide a separate message or function to set the current selection in a listview. Instead, it defines item states or LVIS_* values that determine the listview item's appearance and functionality. LVIS_FOCUSED and LVIS_SELECTED in particular are the states that determine a listview item's selection state. Note that the last parameter passed to this method is a mask specifying which bits are about to change. LVIS_FOCUSED and LVIS_SELECTED are defined in commctrl.inc as &H0001 and &H0002 respectively, so you need to set the last four bits of the mask.

---

### SetBkColor

Sets the background color of a list-view control. 

```
FUNCTION SetBkColor (BYVAL hListView AS HWND, BYVAL clrBk AS COLORREF) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *clrBk* | The background color to set or the CLR_NONE value for no background color. List-view controls with background colors redraw themselves significantly faster than those without background colors. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetBkImage

Sets the background image in a list-view control.

```
FUNCTION SetBkImage (BYVAL hListView AS HWND, BYVAL pvbki AS LVBKIMAGE PTR) AS BOOLEAN
FUNCTION SetBkImage (BYVAL hListView AS HWND, BYREF vbki AS LVBKIMAGE) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pvbki* | A pointer to an **LVBKIMAGE** structure that contains the new background image information. |
| *vbki* | An **LVBKIMAGE** structure that contains the new background image information. |

#### Return value

Returns nonzero if successful, or zero otherwise. Returns zero if the **ulFlags** member of the **LVBKIMAGE** structure is **LVBKIF_SOURCE_NONE**.

#### Remarks

Because the list-view control uses OLE COM to manipulate the background images, the calling application must call **CoInitialize** or **OleInitialize** before using this method. It is best to call one of these functions when the application is initialized and call either **CoUninitialize** or **OleUninitialize** when the application is terminating.

---

### SetCallbackMask

Changes the callback mask for a list-view control.

```
FUNCTION SetCallbackMask (BYVAL hListView AS HWND, BYVAL mask AS DWORD) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *mask* | The value of the callback mask. The bits of the mask indicate the item states or images for which the application stores the current state data. This value can be any combination of the following constants: |

| Value | Meaning |
| ----- | ------- |
| **LVIS_CUT** | The item is marked for a cut-and-paste operation. |
| **LVIS_DROPHILITED** | The item is highlighted as a drag-and-drop target. |
| **LVIS_FOCUSED** | The item has the focus, so it is surrounded by a standard focus rectangle. Although more than one item may be selected, only one item can have the focus. |
| **LVIS_SELECTED** | The item is selected. The appearance of a selected item depends on whether it has the focus and also on the system colors used for selection. |
| **LVIS_OVERLAYMASK** | Use this mask to retrieve the item's overlay image index. |
| **LVIS_STATEIMAGEMASK** | Use this mask to retrieve the item's state image index. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The *callback mask* of a list-view control is a set of bit flags that specify the item states for which the application, rather than the control, stores the current data. The callback mask applies to all of the control's items, unlike the callback item designation, which applies to a specific item. The callback mask is zero by default, meaning that the list-view control stores all item state information. After creating a list-view control and initializing its items, you can use the **SetCallbackMask** method or **LVM_SETCALLBACKMASK** message to change the callback mask. To retrieve the current callback mask, send the **LVM_GETCALLBACKMASK** message.

For more information about overlay images and state images, see [List-View Image Lists](https://learn.microsoft.com/en-us/windows/win32/controls/list-view-controls-overview).

For more information on list-view callbacks, see [Callback Items and the Callback Mask](https://learn.microsoft.com/en-us/windows/win32/controls/list-view-controls-overview)

---

### SetCheckState

Selects or deselects an item in a list-view control.

```
SUB SetCheckState (BYVAL hListView AS HWND, BYVAL iIndex AS LONG, BYVAL fCheck AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iIndex* | The index of the item for which to set the check state. |
| *fCheck* |  value that is set to TRUE to select the item, or FALSE to deselect it. |

#### Remarks

This method should only be used for list-view controls with the **LVS_EX_CHECKBOXES** style.

---

### SetColumn

Sets the attributes of a list-view column.

```
FUNCTION SetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL pcol AS LVCOLUMNW PTR) AS BOOLEAN
FUNCTION SetColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYREF col AS LVCOLUMNW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pcol* | A pointer to an **LVCOLUMNW** structure that contains the new column attributes. The mask member specifies which column attributes to set. If the mask member specifies the **LVCF_TEXT** value, the pszText member is the address of a null-terminated string and the cchTextMax member is ignored. |
| *col* | An **LVCOLUMNW** structure that contains the new column attributes. The mask member specifies which column attributes to set. If the mask member specifies the **LVCF_TEXT** value, the pszText member is the address of a null-terminated string and the cchTextMax member is ignored. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetColumnOrderArray

Sets the left-to-right order of columns in a list-view control.

```
SUB SetColumnOrderArray (BYVAL hListView AS HWND, BYVAL iCount AS LONG, BYVAL prgi AS LONG PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCount* | The number of columns in the list-view control. |
| *prgi* | A pointer to an array specifying the order in which columns should be displayed, from left to right. For example, if the contents of the array are {2,0,1}, the control displays column 2, column 0, and column 1, from left to right. |

---

### SetColumnWidth

Used to change the width of a column in report view or the width of all columns in list-view mode.

```
FUNCTION SetColumnWidth (BYVAL hListView AS HWND, BYVAL iCol AS LONG, BYVAL cx AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The zero-based index of a valid column. For list-view mode, this parameter must be set to zero. |
| *cx* | The new width of the column, in pixels. For report-view mode, the following special values are supported: |

| Value | Meaning |
| ----- | ------- |
| **LVSCW_AUTOSIZE** | Automatically sizes the column. |
| **LVSCW_AUTOSIZE_USEHEADER** | Automatically sizes the column to fit the header text. If you use this value with the last column, its width is set to fill the remaining width of the list-view control |

---

### SetDarkMode

Sets the listview dark mode.

```
FUNCTION SetDarkMode (BYVAL hListView AS HWND) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

---

### SetExtendedListViewStyle

Sets extended styles for list-view controls.

```
SUB SetExtendedListViewStyle (BYVAL hListView AS HWND, BYVAL dwExStyle AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *dwExStyle* | A DWORD value that specifies the extended list-view control style. This parameter can be a combination of [Extended List-View Styles](https://learn.microsoft.com/en-us/windows/win32/controls/extended-list-view-styles). |

#### Remarks

For backward compatibility reasons, the **SetExtendedListViewStyle** method has not been updated to use *dwExMask*. To use the *dwExMask* value, use the **SetExtendedListViewStyleEx** method.

When you use this method to set the **LVS_EX_CHECKBOXES** style, any previously set state image index will be discarded. All check boxes will be initialized to the unchecked state. The state image index is contained in bits 12 through 15 of the state member of the **LVITEMW** structure.

---

### SetExtendedListViewStyleEx

Sets extended styles for list-view controls using the style mask.

```
SUB SetExtendedListViewStyleEx (BYVAL hListView AS HWND, BYVAL dwExMask AS DWORD, BYVAL dwExStyle AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *dwExMask* | A DWORD value that specifies which styles in dw are to be affected. This parameter can be a combination of [Extended List-View Styles](https://learn.microsoft.com/en-us/windows/win32/controls/extended-list-view-styles). Only the extended styles in dwMask will be changed. All other styles will be maintained as they are. If this parameter is zero, all of the styles in dw will be affected. |
| *dwExStyle* | A DWORD value that specifies the extended list-view control styles to set. This parameter can be a combination of [Extended List-View Styles](https://learn.microsoft.com/en-us/windows/win32/controls/extended-list-view-styles). Styles that are not set, but that are specified in dwMask, are removed. |

---

### SetGroupHeaderImageList

Assigns an image list to the group header of a list-view control.

```
FUNCTION SetGroupHeaderImageList (BYVAL hListView AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *himl* | A handle to the image list. |

#### Return value

Returns the handle to the group header image list previously associated with the control if successful, or NULL otherwise.

#### Remarks

The current image list will be destroyed when the list-view control is destroyed unless the **LVS_SHAREIMAGELISTS** style is set. If you use this message to replace one image list with another, your application must explicitly destroy all image lists other than the current one.

---

### SetGroupInfo

Sets group information.

```
FUNCTION SetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYVAL pgrp AS LVGROUP PTR) AS LONG
FUNCTION SetGroupInfo (BYVAL hListView AS HWND, BYVAL iGroupId AS LONG, BYREF grp AS LVGROUP) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iGroupId* | ID that specifies the group whose information is to be set. |
| *pgrp* | Pointer to a **LVGROUP** structure that contains the information to set. |
| *pgrp* | An **LVGROUP** structure that contains the information to set. |

#### Return value

Returns the index of the group if successful, or -1 otherwise.

#### Remarks

To use **SetGroupInfo**, specify Comctl32.dll version 6 in the manifest.

---

### SetGroupMetrics

Sets information about the display of groups.

```
SUB SetGroupMetrics (BYVAL hListView AS HWND, BYVAL pGroupMetrics AS LVGROUPMETRICS PTR)
SUB SetGroupMetrics (BYVAL hListView AS HWND, BYREF GroupMetrics AS LVGROUPMETRICS)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pGroupMetrics* | Pointer to an **LVGROUPMETRICS** structure that contains the metrics to set. |
| pGroupMetrics* | An **LVGROUPMETRICS** structure that contains the metrics to set. |

#### Remarks

To use **SetGroupInfo**, specify Comctl32.dll version 6 in the manifest.

---

### SetGroupState

Sets the state for a specified group.

```
FUNCTION SetGroupState (BYVAL hListView AS HWND, BYVAL dwGroupId AS UINT, _
   BYVAL dwMask AS UINT, BYVAL dwState AS UINT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *dwGroupId* | Specifies the group by iGroupId (see LVGROUP structure). |
| *dwMask* | Specifies the state values to set or clear. This is a combination of the flags listed for the **state** member of **LVGROUP**. |
| *dwState* | Specifies the state values to set. States that are not included here but are included in **dwMask** are cleared. |

#### Return value

Returns the ID of the group (iGroupId) if successful, or -1 otherwise.

#### Remarks

To use **SetGroupState**, specify Comctl32.dll version 6 in the manifest.

---

### SetHeaderFont

Sets the font used by the listview header.

```
FUNCTION ModifyHeaderFont (BYVAL hListView AS HWND, BYREF wszFaceName AS WSTRING, _
   BYVAL lPointSize AS LONG, BYVAL lWeight AS LONG, BYVAL bItalic AS BYTE, BYVAL bUnderline AS BYTE, _
   BYVAL bStrikeOut AS BYTE, BYVAL bCharSet AS BYTE) AS HFONT              
```
| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *wszFaceName* | The name of the font. |
| *lPointSize* | The font point size. |
| *lWeight* | The font weight. |
| *bItalic* | Italic, true or false. |
| *bUnderline* | Underline, true or false. |
| *bStrikeOut* | StrikeOut, true or false. |
| *bCharset* | Character set. |

#### Return value

The handle of the new font. The returned font must be destroyed with **DeleteObject** when no longer needed to prevent memory leaks.

---

### SetHotCursor

Sets the **HCURSOR** that the list-view control uses when the pointer is over an item while hot tracking is enabled. To check whether hot tracking is enabled, call **SystemParametersInfo**.

```
FUNCTION SetHotCursor (BYVAL hListView AS HWND, BYVAL hCur AS HCURSOR) AS HCURSOR
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *hCur* | A handle to the cursor to be set. |

#### Return value

Returns an HCURSOR value that is the cursor that was previously used when the pointer was over an item.

#### Remarks

A list-view control uses hot tracking and hover selection when the **LVS_EX_TRACKSELECT** style is set.

---

### SetHotItem

Sets the hot item in a list-view control.

```
FUNCTION SetHotItem (BYVAL hListView AS HWND, BYVAL iIndex AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iIndex* | The zero-based index of the item to be set as the hot item. |

#### Return value

Returns the index of the item that was previously hot.

---

### SetHoverTime

Sets the amount of time that the mouse cursor must hover over an item before it is selected.

```
SUB SetHoverTime (BYVAL hListView AS HWND, BYVAL dwHoverTimeMs AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *dwHoverTimeMs* | The new amount of time, in milliseconds, that the mouse cursor must hover over an item before it is selected. If this value is (DWORD)-1, then the hover time is set to the default hover time. |

#### Remarks

The hover time only affects list-view controls that have the LVS_EX_TRACKSELECT, LVS_EX_ONECLICKACTIVATE, or LVS_EX_TWOCLICKACTIVATE extended list-view style.

---

### SetIconSpacing

Sets the spacing between icons in list-view controls set to the LVS_ICON style.

```
FUNCTION SetIconSpacing (BYVAL hListView AS HWND, BYVAL cx AS SHORT, BYVAL cy AS SHORT) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *cx* | The distance, in pixels, to set between icons on the x-axis. |
| *cy* | The distance, in pixels, to set between icons on the y-axis. |

#### Return value

Returns a DWORD value that contains the previous x-axis distance in the low word, and the previous y-axis distance in the high word.

#### Remarks

The *cx* and *cy* parameters are relative to the upper-left corner of an icon bitmap. Therefore, to set spacing between icons that do not overlap, the *cx* or *cy* values must include the size of the icon, plus the amount of empty space desired between icons. Values that do not include the width of the icon will result in overlaps.

When defining the icon spacing, *cx* and *cy* must set to 4 or larger. Smaller values will not yield the desired layout. You can reset *cx* and *cy* to the default spacing by setting both values to -1. This approach only allows you to reset both default settings. You cannot reset only *cx* or *cy* to the default setting by setting one of them to -1.

---

### SetImageList

Assigns an image list to a list-view control.

```
FUNCTION SetImageList (BYVAL hListView AS HWND, BYVAL himl AS HIMAGELIST, _
   BYVAL nImageList AS LONG) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *himl* | A handle to the list-view control. |
| *nImageList* | The type of image list. This parameter can be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **LVSIL_NORMAL** | Image list with large icons. |
| **LVSIL_SMALL** | Image list with small icons. |
| **LVSIL_STATE** | Image list with state images. |
| **LVSIL_GROUPHEADER** | Image list for group header. |

#### Return value

Returns the handle to the image list previously associated with the control if successful, or NULL otherwise.

#### Remarks

The current image list will be destroyed when the list-view control is destroyed unless the **LVS_SHAREIMAGELISTS** style is set. If you use this message to replace one image list with another, your application must explicitly destroy all image lists other than the current one.

---

### SetInfoTip

Sets tooltip text.

```
FUNCTION SetInfoTip (BYVAL hListView AS HWND, BYVAL plvInfoTip AS LVSETINFOTIP PTR) AS BOOLEAN
FUNCTION SetInfoTip (BYVAL hListView AS HWND, BYREF lvInfoTip AS LVSETINFOTIP) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvInfoTip* | Pointer to a **LVSETINFOTIP** structure that contains the information to set. |
| *lvInfoTip* | A **LVSETINFOTIP** structure that contains the information to set. |

#### Return value

Returns TRUE if the tooltip text is set successfully, or FALSE otherwise.

#### Remarks

To use **SetInfoTip**, specify Comctl32.dll version 6 in the manifest.

---

### SetInsertMark

Sets the insertion point to the defined position. 

```
FUNCTION SetInsertMark (BYVAL hListView AS HWND, BYVAL plvim AS LVINSERTMARK PTR) AS BOOLEAN
FUNCTION SetInsertMark (BYVAL hListView AS HWND, BYREF lvim AS LVINSERTMARK) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvim* | Pointer to a **LVINSERTMARK** structure that specifies where to set the insertion point. |
| *lvim* | A **LVINSERTMARK** structure that specifies where to set the insertion point. |

#### Return value

Returns TRUE if successful, or FALSE otherwise. Returns FALSE if the size of the **LVINSERTMARK** structure's cbSize member does not equal the actual size of the structure, or when an insertion point does not apply in the current view.

#### Remarks

To use **SetInsertMark**, specify Comctl32.dll version 6 in the manifest.

---

### SetInsertMarkColor

Sets the color of the insertion point.

```
FUNCTION SetInsertMarkColor (BYVAL hListView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *clr* | **COLORREF** structure that specifies the color to set the insertion point. |

#### Return value

Returns a **COLORREF** structure set to the previous color.

#### Remarks

To use **SetInsertMarkColor**, specify Comctl32.dll version 6 in the manifest.

---

### SetItem

Sets some or all of a list-view item's attributes.

```
FUNCTION SetItem (BYVAL hListView AS HWND, BYVAL pitem AS LVITEMW PTR) AS BOOLEAN
FUNCTION SetItem (BYVAL hListView AS HWND, BYREF item AS LVITEMW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *pitem* | A pointer to an **LVITEMW** structure that contains the new item attributes. The **iItem** and **iSubItem** members identify the item or subitem, and the mask member specifies which attributes to set. If the mask member specifies the **LVIF_TEXT** value, the **pszText** member is the address of a null-terminated string and the **cchTextMax** member is ignored. If the mask member specifies the LVIF_STATE value, the **stateMask** member specifies which item states to change, and the state member contains the values for those states. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

To set the attributes of a list-view item, set the iItem member of the **LVITEM"** structure to the index of the item, and set the **iSubItem** member to zero. For an item, you can use the state, **pszText**, **iImage**, and **lParam** members of the **LVITEMW** structure to modify these item parameters.

To set the text of a subitem, set the **iItem** and **iSubItem** members to indicate the specific subitem, and use the **pszText** member to specify the text. Alternatively, you can use the **SetItemText** method to set the text of a subitem. You cannot set the **state** or **lParam** members for subitems because subitems do not have these attributes. In version 4.70 and later, you can set the **iImage** member for subitems. The subitem image will be displayed if the list-view control has the **LVS_EX_SUBITEMIMAGES** extended style. Previous versions will ignore the subitem image.

---

### SetItemCount

Causes the list-view control to allocate memory for the specified number of items.

```
FUNCTION SetItemCount (BYVAL hListView AS HWND, BYVAL cItems AS LONG) AS LRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *cItems* | The number of items that the list-view control will contain. |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Remarks

If the list-view control was created without the **LVS_OWNERDATA** style, this method causes the control to allocate its internal data structures for the specified number of items. This prevents the control from having to allocate the data structures every time an item is added.

If the list-view control was created with the **LVS_OWNERDATA** style (a virtual list view), the **SetItemCountEx** method should be used.

---

### SetItemCountEx

Sets the virtual number of items in a virtual list view.

```
FUNCTION SetItemCountEx (BYVAL hListView AS HWND, BYVAL cItems AS LONG, BYVAL dwFlags AS LONG) AS LRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *cItems* | The number of items that the list-view control will contain. |
| *dwFlags* | Values that specify the behavior of the list-view control after resetting the item count. This value can be a combination of the following: |

| Value | Meaning |
| ----- | ------- |
| **LVSICF_NOINVALIDATEALL** | The list-view control will not repaint unless affected items are currently in view. |
| **LVSICF_NOSCROLL** | The list-view control will not change the scroll position when the item count changes |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Remarks

This method is intended only for list-view controls that use the **LVS_OWNERDATA** and **LVS_REPORT** or **LVS_LIST** styles.

If the list-view control was created with the **LVS_OWNERDATA** style, this method sets the virtual number of items that the control contains.

If the list-view control was created without the **LVS_OWNERDATA** style, the **SetItemCount** method should be used.

---

### SetItemIndexState

Sets the state of a specified list-view item.

```
FUNCTION SetItemIndexState (BYVAL hListView AS HWND, BYVAL plvii AS LVITEMINDEX PTR, _
   BYVAL dwData AS UINT, BYVAL mask AS UINT) AS HRESULT
FUNCTION SetItemIndexState (BYVAL hListView AS HWND, BYREF lvii AS LVITEMINDEX, _
   BYVAL dwData AS UINT, BYVAL mask AS UINT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvii* | A pointer to an **LVITEMINDEX** structure for the item. The caller is responsible for allocating this structure and setting the members. |
| *dwData* | The state to set on the item as one or more (as a bitwise combination) of the [List-View Item States flags](https://learn.microsoft.com/en-us/windows/win32/controls/list-view-item-states). |
| *mask* | The valid bits of the state specified by parameter data. For more information, see the **stateMask** member of the [LVITEMW](https://learn.microsoft.com/en-us/windows/win32/api/commctrl/ns-commctrl-lvitemw) structure.

#### Return value

Returns one of the following values of type HRESULT.

| Return code | Description |
| ----- | ------- |
| **E_FAIL** | The state could not be set. |
| **E_UNEXPECTED** | The list-view control was not ready for the operation. |
| **S_OK** | The operation was successful. |
	
---

### SetItemPosition

Moves an item to a specified position in a list-view control (in icon or small icon view).

```
FUNCTION SetItemPosition (BYVAL hListView AS HWND, BYVAL i AS LONG, _
   BYVAL x AS SHORT, BYVAL y AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. |
| *x* | The new x-position of the item's upper-left corner, in view coordinates. |
| *y* | The new y-position of the item's upper-left corner, in view coordinates. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the list-view control has the **LVS_AUTOARRANGE** style, the list-view control is arranged after the position of the item is set.

On Windows Vista, calling this method on a list-view control with the **LVS_AUTOARRANGE** style does nothing, and the return value is FALSE.

---

### SetItemPosition32

Moves an item to a specified position in a list-view control (in icon or small icon view). This method differs from the **SetItemPosition** method in that it uses 32-bit coordinates. 

```
SUB SetItemPosition32 (BYVAL hListView AS HWND, BYVAL i AS LONG, _
   BYVAL x AS LONG, BYVAL y AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. |
| *x* | The new x-position of the item's upper-left corner, in view coordinates. |
| *y* | The new y-position of the item's upper-left corner, in view coordinates. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the list-view control has the **LVS_AUTOARRANGE** style, the list-view control is arranged after the position of the item is set.

On Windows Vista, calling this method on a list-view control with the **LVS_AUTOARRANGE** style does nothing, and the return value is FALSE.

---

### SetItemState

Changes the state of an item in a list-view control. 

```
SUB SetItemState (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL dwState AS DWORD, BYVAL mask AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The index of the list-view item. If this parameter is -1, then the state change is applied to all items. |
| *dwState* | New state bits for the item. The **mask** parameter indicates the valid bits of the data parameter. The method ignores bits in the data parameter if the corresponding bit is not set in the mask parameter. The low-order byte contains a set of bit flags that indicate the item's state. This byte can be a combination of the following values: |

| Value | Meaning |
| ----- | ------- |
| **LVIS_CUT** | The item is marked for a cut-and-paste operation. |
| **LVIS_DROPHILITED** | The item is highlighted as a drag-and-drop target. |
| **LVIS_FOCUSED** | The item has the focus, so it is surrounded by a standard focus rectangle. Although more than one item may be selected, only one item can have the focus. |
| **LVIS_SELECTED** | The item is selected. The appearance of a selected item depends on whether it has the focus and also on the system colors used for selection. |

Bits of the data parameter that you want to set or clear. You can use **SetItemState** both to set and to clear bits. To set an item's overlay image index, set the **LVIS_OVERLAYMASK** bits. To set an item's state image index, set the **LVIS_STATEIMAGEMASK** bits.

#### Remarks

An item's state value includes a set of bit flags that indicate the item's state. The state value can also include image list indexes that indicate the item's state image and overlay image.

The *mask* parameter specifies the state bits you want to modify, and the data parameter specifies the new value for those bits. To set a bit in the item's internal state, set it in both the mask and data parameters. To clear a bit in the item's internal state, set it in the *mask* parameter and clear it in the data parameter. To leave a bit unchanged in the item's internal state, clear it in the *mask* parameter.

Bits 8 through 11 of the data parameter specify the one-based index of an overlay image in the control's image lists. Both the full-sized icon image list and the small icon image list can have overlay images. The overlay image is superimposed over the item's icon image. If these bits are zero, the item has no overlay image. To isolate these bits, use the **LVIS_OVERLAYMASK** mask. To specify an overlay index, use the **INDEXTOOVERLAYMASK** macro.

Bits 12 through 15 of the data parameter specify the one-based index of an image in the control's state image list. The state image is displayed next to an item's icon to indicate an application-defined state. If these bits are zero, the item has no state image. To isolate these bits, use the **LVIS_STATEIMAGEMASK** mask. To specify a state image index, use the **INDEXTOSTATEIMAGEMASK** macro.

---

### SetItemText

Changes the text of a list-view item or subitem.

```
SUB SetItemText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL pwszText AS WSTRING)
FUNCTION SetText (BYVAL hListView AS HWND, BYVAL i AS LONG, BYREF wszText AS WSTRING)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *i* | The zero-based index of the list-view item. |
| *iSubItem* | The one-based index of the subitem. To set the item label, set **iSubItem** to zero. |
| *pwszText* | A pointer to a null-terminated string that contains the new text. This parameter can be LPSTR_TEXTCALLBACK to indicate a callback item for which the parent window stores the text. In this case, the list-view control sends the parent an LVN_GETDISPINFO notification code when it needs the text. This parameter can be NULL. !
| *wszText* | The new text. |

---

### SetOutlineColor

Sets the color of the border of a list-view control if the **LVS_EX_BORDERSELECT** extended window style is set.

```
FUNCTION SetOutlineColor (BYVAL hListView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *clr* | **COLORREF** structure that specifies the color to set the border. |

#### Return value

Returns a **COLORREF** structure that contains the outline color.

#### Remarks

To use **SetOutlineColor**, specify Comctl32.dll version 6 in the manifest.

---

### SetSelectedColumn

Sets the index of the selected column.

```
SUB SetSelectedColumn (BYVAL hListView AS HWND, BYVAL iCol AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iCol* | The column index. |

#### Remarks

To use **SetSelectedColumn**, specify Comctl32.dll version 6 in the manifest. 

---

### SetSelectionMark

Sets the selection mark in a list-view control.

```
FUNCTION SetSelectionMark (BYVAL hListView AS HWND, BYVAL iIndex AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iIndex* | The zero-based index of the list-view item to be selected. |

#### Return value

Returns the previous selection mark, or -1 if there is no previous selection mark.

#### Remarks

The selection mark is the item index from which a multiple selection starts. This macro does not affect the selection state of the item.

---

### SetTextBkColor

Sets the background color of text in a list-view control.

```
FUNCTION SetTextBkColor (BYVAL hListView AS HWND, BYVAL clrTextBk AS COLORREF) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *clrTextBk* | The new text background color. This can be CLR_NONE for no background color. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetTextColor

Sets the text color of a list-view control.

```
FUNCTION SetTextColor (BYVAL hListView AS HWND, BYVAL clrText AS COLORREF) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *clrText* | The new text color. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetTileInfo

Sets information for an existing tile of a list-view control.

```
FUNCTION SetTileInfo (BYVAL hListView AS HWND, BYVAL plvtinfo AS LVTILEINFO PTR) AS BOOLEAN
FUNCTION SetTileInfo (BYVAL hListView AS HWND, BYREF lvtinfo AS LVTILEINFO) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvtinfo* | Pointer to an **LVTILEINFO** structure that contains the information to set. |
| *lvtinfo* | An **LVTILEINFO** structure that contains the information to set. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

To use **SetTileInfo**, specify Comctl32.dll version 6 in the manifest.

---

### SetTileViewInfo

Sets information that a list-view control uses in tile view.

```
FUNCTION SetTileViewInfo (BYVAL hListView AS HWND, BYVAL plvtvinfo AS LVTILEVIEWINFO PTR) AS BOOLEAN
FUNCTION SetTileViewInfo (BYVAL hListView AS HWND, BYREF lvtvinfo AS LVTILEVIEWINFO) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvtvinfo* | Pointer to an **LVTILEVIEWINFO** structure that contains the information to set. |
| *lvtvinfo* | An **LVTILEVIEWINFO** structure that contains the information to set. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

To use **SetTileViewInfo**, specify Comctl32.dll version 6 in the manifest.

---

### SetToolTips

Sets the tooltip control that the list-view control will use to display tooltips.

```
FUNCTION SetToolTips (BYVAL hListView AS HWND, BYVAL hwndToolTip AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *hwndToolTip* | A handle to the tooltip control to be set. |

#### Return value

Returns the handle to the previous tooltip control.

---

### SetTooltipsFont

Sets the tooltip control that the list-view control will use to display tooltips.

```
SUB SetTooltipsFont (BYVAL hListView AS HWND, BYVAL hFont AS HFONT = NULL, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *hFont* | Handle to the font. If this parameter is NULL, the control uses the default system font to draw text. |
| *fRedraw* | Specifies whether the control should be redrawn immediately upon setting the font. If this parameter is TRUE, the control redraws itself. |

#### Return value

Returns the handle to the previous tooltip control.

---

### SetView

Sets the view of a list-view control.

```
FUNCTION SetView (BYVAL hListView AS HWND, BYVAL iView AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iView* | DWORD that specifies the view. |

#### Return value

Returns 1 if successful, or UINT_MAX otherwise. For example, returns UINT_MAX if the view is invalid.

#### Remarks

To use **SetView**, specify Comctl32.dll version 6 in the manifest. 

---

### SetWorkAreas

Sets the working areas within a list-view control.

```
SUB SetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYVAL prc AS RECT PTR)
SUB SetWorkAreas (BYVAL hListView AS HWND, BYVAL nWorkAreas AS LONG, BYREF rc AS RECT)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *nWorkAreas* | The number of **RECT** structures in the array at prc. The maximum number of working areas allowed is defined by the **LV_MAX_WORKAREAS** value. |
| *prc* | A pointer to an array of **RECT** structures that contain the new working areas of the list-view control. Values in these structures are in client coordinates. If this parameter is NULL, the working area will be set to the client area of the control. *nWorkAreas* specifies the number of structures in this array. |
| *rc* | An array of **RECT** structures that contain the new working areas of the list-view control. Values in these structures are in client coordinates. If this parameter is NULL, the working area will be set to the client area of the control. *nWorkAreas* specifies the number of structures in this array. |

---

### SortGroups

Uses an application-defined comparison function to sort groups by ID within a list-view control. 

```
FUNCTION SortGroups (BYVAL hListView AS HWND, BYVAL _pfnGroupCompare AS PFNLVGROUPCOMPARE PTR, _
   BYVAL _plv AS ANY PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *_pfnGroupCompare* | Pointer to an application-defined comparison function, **LVGroupCompare**. |
| *_plv* | Void pointer to the application-defined information. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

To use **SortGroups**, specify Comctl32.dll version 6 in the manifest. 

---

### SortItems

Uses an application-defined comparison function to sort the items of a list-view control. The index of each item changes to reflect the new sequence.

```
FUNCTION SortItems (BYVAL hListView AS HWND, BYVAL _pfnCompare AS PFNLVCOMPARE PTR, _
   BYVAL _lPrm AS LPARAM) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *_pfnCompare* | A pointer to the application-defined comparison function. The comparison function is called during the sort operation each time the relative order of two list items needs to be compared. |
| *_lPrm* | The application-defined value that is passed to the comparison function. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The comparison function has the following form.
```
FUNCTION CompareFunc(BYVAL lParam1 AS LPARAM, BYVAL lParam2 AS LPARAM, BYVAL _lPrm AS LPARAM) AS LONG
```
The *lParam1* parameter is the value associated with the first item being compared; and the *lParam2* parameter is the value associated with the second item. These are the values that were specified in the *lParam* member of the items' **LVITEMW** structure when they were inserted into the list. The *_lPrm* parameter is the same value passed to the **LVM_SORTITEMS** message.

The comparison function must return a negative value if the first item should precede the second, a positive value if the first item should follow the second, or zero if the two items are equivalent.

---

### SortItemsEx

Uses an application-defined comparison function to sort the items of a list-view control. The index of each item changes to reflect the new sequence.

```
FUNCTION SortItemsEx (BYVAL hListView AS HWND, BYVAL _pfnCompare AS PFNLVCOMPARE PTR, _
   BYVAL _lPrm AS LPARAM) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *_pfnCompare* | A pointer to the application-defined comparison function. The comparison function is called during the sort operation each time the relative order of two list items needs to be compared. |
| *_lPrm* | The application-defined value that is passed to the comparison function. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The comparison function has the following form.
```
FUNCTION CompareFunc(BYVAL lParam1 AS LPARAM, BYVAL lParam2 AS LPARAM, BYVAL _lPrm AS LPARAM) AS LONG
```
The *lParam1* parameter is the value associated with the first item being compared; and the *lParam2* parameter is the value associated with the second item. These are the values that were specified in the *lParam* member of the items' **LVITEMW** structure when they were inserted into the list. The *_lPrm* parameter is the same value passed to the **LVM_SORTITEMS** message.

The comparison function must return a negative value if the first item should precede the second, a positive value if the first item should follow the second, or zero if the two items are equivalent.

This metod is similar to **SortItems**, except for the type of information passed to the comparison function. With **SortItemsEx**, the item's index is passed instead of its *lparam* value.

**Note**: During the sorting process, the list-view contents are unstable. If the callback function sends any messages to the list-view control aside from **LVM_GETITEM** (**GetItem**), the results are unpredictable.

---

### SubItemHitTest

Determines which list-view item or subitem is located at a given position.

```
FUNCTION SubItemHitTest (BYVAL hListView AS HWND, BYVAL plvhti AS LVHITTESTINFO PTR) AS LONG
FUNCTION SubItemHitTest (BYVAL hListView AS HWND, BYREF lvhti AS LVHITTESTINFO) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvhti* | A pointer to an **LVHITTESTINFO** structure. The **POINT** structure within **LVHITTESTINFO** must be set to the client coordinates to be hit-tested. |
| *lvhti* | An **LVHITTESTINFO** structure. The **POINT** structure within **LVHITTESTINFO** must be set to the client coordinates to be hit-tested. |

#### Return value

Returns the index of the item or subitem tested, if any, or -1 otherwise. If an item or subitem is at the given coordinates, the fields of the **LVHITTESTINFO** structure will be filled with the applicable hit information.

---

### SubItemHitTestEx

Determines which list-view item or subitem is located at a given position.

```
FUNCTION SubItemHitTestEx (BYVAL hListView AS HWND, BYVAL plvhti AS LVHITTESTINFO PTR) AS LONG
FUNCTION SubItemHitTestEx (BYVAL hListView AS HWND, BYREF lvhti AS LVHITTESTINFO) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *plvhti* | A pointer to an **LVHITTESTINFO** structure. The **POINT** structure within **LVHITTESTINFO** must be set to the client coordinates to be hit-tested. |
| *lvhti* | An **LVHITTESTINFO** structure. The **POINT** structure within **LVHITTESTINFO** must be set to the client coordinates to be hit-tested. |

#### Return value

Returns the index of the item or subitem tested, if any, or -1 otherwise. If an item or subitem is at the given coordinates, the fields of the **LVHITTESTINFO** structure will be filled with the applicable hit information.

#### Remarks

This macro passes -1 as the wparam of the message, specifying that the **iGroup** member of *plvhti* is retrieved.

---

### UnselectAllItems

Unselects all items.

```
SUB UnselectAllItems (BYVAL hListView AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |

---

### UnselectItem

Unselects an item in a ListView.

```
SUB UnselectItem (BYVAL hListView AS HWND, BYVAL iIndex AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iIndex* | The index of the item to unselect. |

---

### Update

Updates a list-view item. If the list-view control has the **LVS_AUTOARRANGE** style, this method causes the list-view control to be arranged.

```
FUNCTION Update (BYVAL hListView AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListView* | Handle to the ListView control. |
| *iItem* | The index of the item to update. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---
