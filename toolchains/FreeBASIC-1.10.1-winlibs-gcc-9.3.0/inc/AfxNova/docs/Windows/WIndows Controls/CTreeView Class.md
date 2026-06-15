# CTreeView Class

A tree-view control is a window that displays a hierarchical list of items, such as the headings in a document, the entries in an index, or the files and directories on a disk. Each item consists of a label and an optional bitmapped image, and each item can have a list of subitems associated with it. By clicking an item, the user can expand or collapse the associated list of subitems.

See: [About Tree-View Controls](https://learn.microsoft.com/en-us/windows/win32/controls/tree-view-controls)

**Include file**: CTreeView.inc

| Name       | Description |
| ---------- | ----------- |
| [AddRootItem](#addrootitem) | Adds the item as the root item in a treeview control. |
| [AppendItem](#appenditem) | Inserts the item at the end of the list in a treeview control. |
| [Collapse](#collapse) | Collapses the list. |
| [CollapseAllItems](#collapseallitems) | Collapses all the list of items. |
| [CollapseAllChildItems](#collapseallchilditems) | Collapses the list of child items, if any, associated with the specified parent node and the sibling nodes below it. |
| [CollapseChildItems](#collapsechilditems) | Collapses the list of child items, if any, associated with the specified parent node. |
| [CollapseReset](#collapsereset) | Collapses the list and removes the child items. |
| [CollapseSiblings](#collapsesiblings) | Collapses the list of sibling items, if any, associated with the specified parent node. |
| [CreateDragImage](#createdragimage) | Creates a dragging bitmap for the specified item in a treeview control. |
| [DeleteAllItems](#deleteallitems) | Deletes all items from a treeview control. |
| [DeleteItem](#deleteitem) | Removes an item and all its children from a treeview control. |
| [EditLabel](#editlabel) | Begins in-place editing of the specified item's text, replacing the text of the item with a single-line edit control containing the text. |
| [EndEditLabelNow](#endeditlabelnow) | Ends the editing of a treeview item's label. |
| [EnsureVisible](#ensurevisible) | Ensures that a treeview item is visible, expanding the parent item or scrolling the treeview control, if necessary. |
| [Expand](#expand) | Expands or collapses the list of child items associated with the specified parent item, if any. |
| [ExpandAllChildItems](#expandallchilditems) | Expands the list of child items, if any, associated with the specified parent node and the sibling nodes below it. |
| [ExpandAllItems](#expandallitems) | Expands all the list of items. |
| [ExpandChildItems](#expandchilditems) | Expands the list of child items, if any, associated with the specified parent node. |
| [ExpandPartial](#expandpartial) | Partially expands the list. |
| [ExpandSiblings](#expandsiblings) | Expands the list of sibling items, if any, associated with the specified parent node. |
| [GetBkColor](#getbkcolor) | Retrieves the current background color of the control. |
| [GetBold](#getbold) | Returns TRUE if the bold attribute is set, or FALSE otherwise. |
| [GetCheck](#getcheck) | Returns TRUE if the item is checked, or FALSE otherwise. |
| [GetCheckState](#getcheckstate) | Retrieves some or all of a treeview item's state attributes. |
| [GetChild](#getchild) | Retrieves the first child item of the specified treeview item. |
| [GetCount](#getcount) | Retrieves a count of the items in a treeview control. |
| [GetDropHilight](#getdrophilight) | Retrieves the treeview item that is the target of a drag-and-drop operation. |
| [GetEditControl](#geteditcontrol) | Retrieves the handle to the edit control being used to edit a treeview item's text. |
| [GetExtendedStyle](#getextendedstyle) | Retrieves the extended style for a specified treeview control. |
| [GetFirstVisible](#getdfirstvisible) | Retrieves the first visible item in a treeview control window. |
| [GetImageList](#getimagelist) | Retrieves the handle to the normal or state image list associated with a treeview control. |
| [GetIndent](#getindent) | Retrieves the amount, in pixels, that child items are indented relative to their parent items. |
| [GetInsertMarkColor](#getinsertmarkcolor) | Retrieves the color used to draw the insertion mark for the tree view. |
| [GetISearchString](#getisearchstring) | Retrieves the incremental search string for a treeview control. |
| [GetISearchStringLen](#getisearchstringlen) | Returns the number of characters in the incremental search string. |
| [GetItem](#getitem) | Retrieves some or all of a treeview item's attributes. |
| [GetItemEx](#getitemes) | Retrieves some or all of a treeview item's attributes. |
| [GetItemHeight](#getitemheight) | Retrieves the current height of the treeview items. |
| [GetItemPartRect](#getitempartrect) | Retrieves the largest possible bounding rectangle that constitutes the "hit zone" for a specified part of an item. |
| [GetItemRect](#getitemrect) | Retrieves the bounding rectangle for a treeview item and indicates whether the item is visible. |
| [GetItemState](#getitemstate) | Retrieves some or all of a treeview item's state attributes. |
| [GetItemText](#getitemtext) | Retrieves the text of the specified item. |
| [GetLastVisible](#getlastvisible) | Retrieves some or all of a treeview item's state attributes. |
| [GetLineColor](#getlinecolor) | Gets the current line color. |
| [GetlParam](#getlparam) | Retrieves the lParam value from a Treeview. |
| [GetSelect](#getselection) | Retrieves the currently selected item in a treeview control. |
| [GetSelection](#getselection) | Retrieves the currently selected item in a treeview control. |
| [GetNext](#getnext) | Retrieves the next sibling item of a specified item in a treeview control. |
| [GetNextItem](#getnextitem) | Retrieves the treeview item that bears the specified relationship to a specified item. |
| [GetNextSelected](#getnextselected) | Retrieves the treeview item that bears the TVGN_NEXTSELECTED relationship to a specified tree item. |
| [GetNextSibling](#getnextsibling) | Retrieves the next sibling item of a specified item in a treeview control. |
| [GetNextVisible](#getnextvisible) | Retrieves the next visible item that follows a specified item in a treeview control. |
| [GetParent](#getparent) | Retrieves the parent item of the specified treeview item. |
| [GetParentText](#getparenttext) | Retrieves the text of the parent item of the specified treeview item. |
| [GetPrevSibling](#getprevsibling) | Retrieves the previous sibling item of a specified item in a treeview control. |
| [GetPrevious](#getprevsibling) | Retrieves the previous sibling item of a specified item in a treeview control. |
| [GetPrevVisible](#getprevvisible) | Retrieves the first visible item that precedes a specified item in a treeview control. |
| [GetRoot](#getroot) | Retrieves the topmost or very first item of the treeview control. |
| [GetScrollTime](#getscrolltime) | Retrieves the maximum scroll time for the treeview control. |
| [GetTextColor](#gettextcolor) | Retrieves the current text color of the control. |
| [GetToolTips](#gettooltips) | Retrieves the handle to the child Tooltip control used by a treeview control. |
| [GetVisibleCount](#getvisiblecount) | Obtains the number of items that can be fully visible in the client window of a treeview control. |
| [HitTest](#hittest) | Determines the location of the specified point relative to the client area of a treeview control. |
| [InsertItem](#insertitem) | Inserts a new item in a treeview control. |
| [InsertFirstItem](#insertfirstitem) | Inserts the item at the beginning of the list in a treeview control. |
| [InsertSortedItem](#insertsorteditem) | Inserts the item into the list in alphabetical order. |
| [IsItemChecked](#isitemchecked) | Returns TRUE if the item is checked, or FALSE otherwise. |
| [ItemExists](#itemexists) | Searches for an exact string in a tree view node. Search is case sensitive. |
| [ItemExistsIgnoreCase](#itemexistsignorecase) | Searches for an exact string in a tree view node. Search is case insensitive. |
| [MapAccIDToHTREEITEM](#mapaccidtohtreeitem) | Maps an accessibility ID to an HTREEITEM. |
| [MapHTREEITEMToAccID](#Maphtreeitemtoaccid) | Maps an HTREEITEM to an accessibility ID. |
| [Reset](#deleteallitems) | Deletes all items from a treeview control. |
| [SelectDropTarget](#selectdroptarget) | Redraws a specified treeview control item in the style used to indicate the target of a drag-and-drop operation. |
| [SelectItem](#selectitem) | Selects the specified treeview item. |
| [SelectSetFirstVisible](#selectsetfirstvisible) | Scrolls the treeview control vertically to ensure that the specified item is visible. |
| [SetAutoScrollInfo](#setautoscrollinfo) | Sets information used to determine auto-scroll characteristics. |
| [SetBkColor](#setbkcolor) | Sets the background color of the control. |
| [SetBold](#setbold) | Sets/unsets the bold attribute of the specified item. |
| [SetCheck](#setcheck) | Sets the item's state image to "checked" or "unchecked." |
| [SetCheckState](#setcheck) | Sets the item's state image to "checked" or "unchecked." |
| [SetExtendedStyle](#setextendedstyle) | Sets the extended style for a specified TreeView control. |
| [SetImageList](#setimagelist) | Sets the normal or state image list for a treeview control and redraws the control using the new images. |
| [SetIndent](#setindent) | Sets the width of indentation for a treeview control and redraws the control to reflect the new width. |
| [SetInsertMark](#setinsertmark) | Sets the insertion mark in a treeview control. |
| [SetInsertMarkColor](#setinsertmarkcolor) | Sets the color used to draw the insertion mark for the tree view. |
| [SetItem](#setitem) | Sets some or all of a treeview item's attributes. |
| [SetItemEx](#setitemex) | Sets some or all of a treeview item's attributes. |
| [SetItemHeight](#setitemheight) | Sets the height of the treeview items. |
| [SetItemState](#setitemstate) | Sets a treeview item's state attributes. |
| [SetItemText](#setitemtext) | Sets the text of the specified item. |
| [SetLineColor](#setlinecolor) | Sets the current line color. |
| [SetScrollTime](#setscrolltime) | Sets the maximum scroll time for the treeview control. |
| [SetText](#settext) | Sets the text of the specified item. |
| [SetTextColor](#settextcolor) | Sets the text color of the control. |
| [SetToolTips](#settooltips) | Sets a treeview control's child Tooltip control. |
| [Toggle](#toggle) | Collapses the list if it is expanded or expands it if it is collapsed. |
| [Unselect](#unselect) | Unselects the selected item. |

---

### AddRootItem

Adds the item as the root item in a treeview control.

```
FUNCTION AddRootItem (BYVAL hTreeView AS HWND, BYVAL pwszText AS WSTRING PTR, _
   BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pwszText* | Pointer to a null-terminated string that contains the item text if the structure specifies item attributes. If this member is the LPSTR_TEXTCALLBACK value, the parent window is responsible for storing the name. In this case, the tree-view control sends the parent window a TVN_GETDISPINFO notification code when it needs the item text for displaying, sorting, or editing and a TVN_SETDISPINFO notification code when the item text changes. If the structure is receiving item attributes, this member is the address of the buffer that receives the item text. Note that although the tree-view control allows any length string to be stored as item text, only the first 260 characters are displayed. |
| *lParam* | A value to associate with the item. |
| *iImage* | Index in the tree-view control's image list of the icon image to use when the item is in the nonselected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |
| *iSelectedImage* | Index in the tree-view control's image list of the icon image to use when the item is in the selected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |

---

### AppendItem

Adds the item as the root item in a treeview control.

```
FUNCTION AppendItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL pwszText AS WSTRING PTR, _
   BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hParent* | Handle to the parent item. If this member is the TVI_ROOT value or NULL, the item is inserted at the root of the tree-view control. |
| *pwszText* | Pointer to a null-terminated string that contains the item text if the structure specifies item attributes. If this member is the LPSTR_TEXTCALLBACK value, the parent window is responsible for storing the name. In this case, the tree-view control sends the parent window a TVN_GETDISPINFO notification code when it needs the item text for displaying, sorting, or editing and a TVN_SETDISPINFO notification code when the item text changes. If the structure is receiving item attributes, this member is the address of the buffer that receives the item text. Note that although the tree-view control allows any length string to be stored as item text, only the first 260 characters are displayed. |
| *lParam* | A value to associate with the item. |
| *iImage* | Index in the tree-view control's image list of the icon image to use when the item is in the nonselected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |
| *iSelectedImage* | Index in the tree-view control's image list of the icon image to use when the item is in the selected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |

---

### Collapse

Collapses the list.

```
FUNCTION Collapse (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the parent item that will be expanded or collapsed. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

---

### CollapseAllItems

Collapses all the list of items.

```
SUB CollapseAllItems (BYVAL hTreeView AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

---

### CollapseAllChildItems

Collapses the list of child items, if any, associated with the specified parent node and the sibling nodes below it.

```
SUB CollapseAllChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | The handle of the parent node. |

---

### CollapseChildItems

Collapses the list of child items, if any, associated with the specified parent node.

```
SUB CollapseChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | The handle of the parent node. |

---

### CollapseReset

Collapses the list and removes the child items.

```
FUNCTION CollapseReset (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the parent item that will be collapsed. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

---

### CollapseSiblings

Collapses the list of sibling items, if any, associated with the specified parent node.

```
SUB CollapseSiblings (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | The handle of the parent node. |

---

### CreateDragImage

Creates a dragging bitmap for the specified item in a treeview control.

```
FUNCTIOON CreateDragImage (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item that receives the new dragging bitmap. |

#### Return value

Returns the handle to the image list to which the dragging bitmap was added if successful, or NULL otherwise.

#### Remarks

If you create a tree-view control without an associated image list, you cannot use the **CreateDragImage** method to create the image to display during a drag operation. You must implement your own method of creating a drag cursor.

Your application is responsible for destroying the image list when it is no longer needed.

---

### DeleteAllItems

Deletes all items from a treeview control. **Reset** is an alias for this method.

```
FUNCTION DeleteAllItems (BYVAL hTreeView AS HWND) AS BOOLEAN
FUNCTION Reset (BYVAL hTreeView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

---

### DeleteItem

Removes an item and all its children from a treeview control.

```
FUNCTION DeleteItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item to delete. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

---


### EditLabel

Begins in-place editing of the specified item's text, replacing the text of the item with a single-line edit control containing the text. This method implicitly selects and focuses the specified item.

```
FUNCTION EditLabel (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item to edit. |

#### Return value

Returns the handle to the edit control used to edit the item text if successful, or NULL otherwise.

#### Remarks

This method sends a **TVN_BEGINLABELEDIT** notification code to the parent of the tree-view control.

When the user completes or cancels editing, the edit control is destroyed and the handle is no longer valid. You can subclass the edit control, but do not destroy it.

The control must have the focus before you call this method. Focus can be set using the **SetFocus** function.

---

### EndEditLabelNow

Ends the editing of a tree-view item's label.

```
FUNCTION EndEditLabelNow (BYVAL hTreeView AS HWND, BYVAL fCancel AS BOOLEAN) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *fCancel* | Variable that indicates whether the editing is canceled without being saved to the label. If this parameter is TRUE, the system cancels editing without saving the changes. Otherwise, the system saves the changes to the label. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

#### Remarks

This method causes the **TVN_ENDLABELEDIT** notification code to be sent to the parent window of the tree-view control.

---

### EnsureVisible

Ensures that a treeview item is visible, expanding the parent item or scrolling the treeview control, if necessary.

```
FUNCTION EnsureVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

#### Remarks

If the **EnsureVisible** method expands the parent item, the parent window receives the **TVN_ITEMEXPANDING** and **TVN_ITEMEXPANDED** notification codes.

---

### Expand

Expands or collapses the list of child items associated with the specified parent item, if any.

```
FUNCTION Expand (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS BOOLEAN
```

Expands the list of child items associated with the specified parent item, if any.

```
FUNCTION Expand (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the parent item that will be expanded or collapsed. |
| *code* | Action flag. |

Action flag. This parameter can be one or more of the following values:

| Value | Meaning |
| ----- | ------- |
| **TVE_COLLAPSE** | Collapses the list. |
| **TVE_COLLAPSERESET** | Collapses the list and removes the child items. The TVIS_EXPANDEDONCE state flag is reset. This flag must be used with the TVE_COLLAPSE flag. |
| **TVE_EXPAND** | Expands the list. |
| **TVE_EXPANDPARTIAL** | Partially expands the list. In this state the child items are visible and the parent item's plus sign (+), indicating that it can be expanded, is displayed. This flag must be used in combination with the TVE_EXPAND flag. |
| **TVE_TOGGLE** | Collapses the list if it is expanded or expands it if it is collapsed. |

#### Return value

Returns TRUE if the operation was successful, or FALSE otherwise.

#### Remarks

Expanding a node that is already expanded is considered a successful operation and returns TRUE. Collapsing a node returns FALSE if the node is already collapsed; otherwise it returns TRUE. Attempting to expand or collapse a node that has no children is considered a failure and **Expand** returns FALSE.

When an item is first expanded by a **TVM_EXPAND** message, the action generates **TVN_ITEMEXPANDING** and **TVN_ITEMEXPANDED** notification codes and the item's **TVIS_EXPANDEDONCE** state flag is set. As long as this state flag remains set, subsequent **TVM_EXPAND** messages do not generate **TVN_ITEMEXPANDING** or **TVN_ITEMEXPANDED** notifications. To reset the **TVIS_EXPANDEDONCE** state flag, you must send a **TVM_EXPAND** message with the **TVE_COLLAPSE** and **TVE_COLLAPSERESET** flags set. Attempting to explicitly set **TVIS_EXPANDEDONCE** will result in unpredictable behavior.

The expand operation may fail if the owner of the treeview control denies the operation in response to a **TVN_ITEMEXPANDING** notification.

---

### ExpandAllChildItems

Expands the list of child items, if any, associated with the specified parent node and the sibling nodes below it.

```
SUB ExpandAllChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | The handle of the parent node. |

---

### ExpandAllItems

Expands all the list of items.

```
SUB ExpandAllItems (BYVAL hTreeView AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

---

### ExpandChildItems

Expands the list of child items, if any, associated with the specified parent node.

```
SUB ExpandChildItems (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | The handle of the parent node. |

---

### ExpandPartial

Partially expands the list.

```
FUNCTION ExpandPartial (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the parent item that will be expanded. |

---

### ExpandSiblings

Expands the list of sibling items, if any, associated with the specified parent node.

```
SUB ExpandSiblings (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | The handle of the parent node. |

---

### GetBkColor

Retrieves the current background color of the control.

```
FUNCTION GetBkColor (BYVAL hTreeView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns a **COLORREF** value that represents the current background color. If this value is -1, the control is using the system color for the background color.

---

### GetBold

Returns TRUE if the bold attribute is set, or FALSE otherwise.

```
FUNCTION GetBold (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

---

### GetCheck

Returns TRUE if the item is checked, or FALSE otherwise.

```
FUNCTION GetCheck (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

---

### GetCheckState

Retrieves some or all of a treeview item's state attributes.

```
FUNCTION GetCheckState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

#### Return value

Returns a UINT value that is equivalent to the state member of **TVITEMEX**. The state bits that are both true and were specified in mask will be set.

---

### GetChild

Retrieves the first child item of the specified treeview item.

```
FUNCTION GetChild (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetCount

Retrieves a count of the items in a treeview control.

```
FUNCTION GetCount (BYVAL hTreeView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the number of items in a treeview control.

---

### GetDropHilight

Retrieves the treeview item that is the target of a drag-and-drop operation.

```
FUNCTION GetDropHilight (BYVAL hTreeView AS HWND) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetEditControl

Retrieves the handle to the edit control being used to edit a treeview item's text.

```
FUNCTION GetEditControl (BYVAL hTreeView AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

The handle to the edit control being used to edit a tree-view item's text, or NULL if no item is being edited.

#### Remarks

When label editing begins, an edit control is created but not positioned or displayed. Before it is displayed, the tree-view control sends its parent window a **TVN_BEGINLABELEDIT** notification code.

To customize label editing, implement a handler for **TVN_BEGINLABELEDIT** and have it use **GetEditControl** method to send a **TVM_GETEDITCONTROL** message to the tree-view control. If a label is being edited, the return value will be a handle to the edit control. Use this handle to customize the edit control by sending the usual EM_XXX messages.

---

### GetExtendedStyle

Retrieves the extended style for a specified treeview control.

```
FUNCTION GetExtendedStyle (BYVAL hTreeView AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the value of extended style. For more information on styles, see [Tree-View Control Extended Styles](https://learn.microsoft.com/en-us/windows/win32/controls/tree-view-control-window-extended-styles).

#### Remarks

The extended styles for a tree-view control have nothing to do with the extended styles used with function **CreateWindowExW** or function **SetWindowLongPtrW**.

---

### GetFirstVisible

etrieves the first visible item in a tree-view control window.

```
FUNCTION GetFirstVisible (BYVAL hTreeView AS HWND) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetImageList

Retrieves the handle to the normal or state image list associated with a tree-view control.

```
FUNCTION GetImageList (BYVAL hTreeView AS HWND, BYVAL iImage AS LONG) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *iImage* | Type of image list to retrieve. This parameter can be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **TVSIL_NORMAL** | Indicates the normal image list, which contains selected, nonselected, and overlay images for the items of a tree-view control. |
| **TVSIL_STATE** | Indicates the state image list. You can use state images to indicate application-defined item states. A state image is displayed to the left of an item's selected or nonselected image. |

#### Return value

Returns an **HIMAGELIST** handle to the specified image list.

---

### GetIndent

Retrieves the amount, in pixels, that child items are indented relative to their parent items. 

```
FUNCTION GetIndent (BYVAL hTreeView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the amount of indentation.

---

### GetInsertMarkColor

Retrieves the color used to draw the insertion mark for the tree view.

```
FUNCTION GetInsertMarkColor (BYVAL hTreeView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns a **COLORREF** value that contains the current insertion mark color.

---

### GetISearchString

Retrieves the incremental search string for a tree-view control. The tree-view control uses the incremental search string to select an item based on characters typed by the user

```
FUNCTION GetISearchString (BYVAL hTreeView AS HWND, BYVAL pwsz AS WSTRING PTR) AS BOOLEAN
FUNCTION GetISearchString (BYVAL hTreeView AS HWND) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pwsz* | Pointer to the buffer that receives the incremental search string. |

#### Return value

Returns TRUE if the string is retrieved; FALSE otherwise.

If the tree-view control is not in incremental search mode, the return value is zero.

**Security Warning**: Using the first overloaded method incorrectly might compromise the security of your program. You must allocate a large enough buffer to hold the string. First call the method **GetISearchStringLen**.

---

### GetISearchStringLen

Returns the number of characters in the incremental search string.

```
FUNCTION GetISearchStringLen (BYVAL hTreeView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

---

### GetItem

Retrieves some or all of a treeview item's attributes.

```
FUNCTION GetItem (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMW PTR) AS BOOLEAN
FUNCTION GetItem (BYVAL hTreeView AS HWND, BYREF item AS TVITEMW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pitem* | Pointer to a **TVITEMW** structure that specifies the information to retrieve and receives information about the item. With version 4.71 and later, you can use the **GetItemEx** method. |
| *item* | A **TVITEMW** structure that specifies the information to retrieve and receives information about the item. With version 4.71 and later, you can use the **GetItemEx** method. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When the **TVM_GETITEM** message is sent, the **hItem** member of the **TVITEMW** structure identifies the item to retrieve information about, and the mask member specifies the attributes to retrieve.

If the **TVIF_TEXT** flag is set in the mask member of the **TVITEMW** structure, the *pszText* member must point to a valid buffer and the **cchTextMax** member must be set to the number of characters in that buffer. The returned text will not necessarily be stored in the original buffer passed by the application. It is possible that **pszText** will point to text in a new buffer rather than place it in the old buffer.

---

### GetItemEx

Retrieves some or all of a treeview item's attributes.

```
FUNCTION GetItemEx (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMEXW PTR) AS BOOLEAN
FUNCTION GetItemEx (BYVAL hTreeView AS HWND, BYREF item AS TVITEMEXW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pitem* | Pointer to a **TVITEMEXW** structure that specifies the information to retrieve and receives information about the item. |
| *item* | A **TVITEMEXW** structure that specifies the information to retrieve and receives information about the item. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When the **TVM_GETITEM** message is sent, the **hItem** member of the **TVITEMEXW** structure identifies the item to retrieve information about, and the mask member specifies the attributes to retrieve.

If the **TVIF_TEXT** flag is set in the mask member of the **TVITEMEXW** structure, the *pszText* member must point to a valid buffer and the **cchTextMax** member must be set to the number of characters in that buffer. The returned text will not necessarily be stored in the original buffer passed by the application. It is possible that **pszText** will point to text in a new buffer rather than place it in the old buffer.

---

### GetItemHeight

Retrieves the current height of the treeview items.

```
FUNCTION GetItemHeight (BYVAL hTreeView AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the height of the items, in pixels.

---

### GetItemPartRect

Retrieves the largest possible bounding rectangle that constitutes the "hit zone" for a specified part of an item.

```
FUNCTION GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL prc AS RECT PTR, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS BOOLEAN
FUNCTION GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYREF rc AS RECT, BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS BOOLEAN
FUNCTION GetItemPartRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL partid AS TVITEMPART = TVGIPR_BUTTON) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the tree-view item. |
| *prc* | Pointer to a **RECT** structure that receives the bounding rectangle. The caller is responsible for allocating this structure. The coordinates received are relative to the upper-left corner of the tree-view control. |
| *rc* | A **RECT** structure that receives the bounding rectangle. The caller is responsible for allocating this structure. The coordinates received are relative to the upper-left corner of the tree-view control. |
| *partid* | ID of the item part. This value must be **TVGIPR_BUTTON** (0x0001). |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

This method returns the largest possible bounding rectangle such that for every (x,y) coordinate within the rectangle, a click by the user at that coordinate would constitute a hit on that part of the item.

---

### GetItemRect

Retrieves the bounding rectangle for a tree-view item and indicates whether the item is visible.

```
FUNCTION GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL prc AS RECT PTR, BYVAL code AS BOOLEAN) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYREF rc AS RECT, BYVAL code AS BOOLEAN) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS BOOLEAN) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the tree-view item. |
| *prc* | Pointer to a **RECT** structure that receives the bounding rectangle. The caller is responsible for allocating this structure. The coordinates received are relative to the upper-left corner of the tree-view control. |
| *rc* | A **RECT** structure that receives the bounding rectangle. The caller is responsible for allocating this structure. The coordinates received are relative to the upper-left corner of the tree-view control. |
| *code* | Value specifying the portion of the item for which to retrieve the bounding rectangle. If this parameter is TRUE, the bounding rectangle includes only the text of the item. Otherwise, it includes the entire line that the item occupies in the tree-view control. |

#### Return value

If the item is visible and the bounding rectangle is successfully retrieved, the return value is TRUE. Otherwise, the it returns FALSE and does not retrieve the bounding rectangle.

---

### GetItemState

Retrieves some or all of a tree-view item's state attributes.

```
FUNCTION GetItemState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL mask AS UINT) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |
| *mask* | Mask used to specify the states to query for. It is equivalent to the mask member of **TVITEMEXW**. |

#### Return value

Returns a UINT value that is equivalent to the state member of **TVITEMEXW**. The state bits that are both true and were specified in mask will be set.

---

### GetItemText

Retrieves the text of the specified item.

```
FUNCTION GetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL pwszText AS WSTRING PTR, BYVAL cchtextmax AS LONG) AS BOOLEAN
FUNCTION GetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL cchTextMax AS LONG = 0) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |
| *pwszText* | Pointer to a null-terminated string that will receive the item text. |
| *cchTextMax* | Size of the buffer pointed to by the *pwszText* member, in characters. If this structure is being used to set item attributes, this member is ignored. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetLastVisible

Retrieves the last expanded item in a tree-view control. This does not retrieve the last item visible in the tree-view window. 

```
FUNCTION GetLastVisible (BYVAL hTreeView AS HWND) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetLineColor

Gets the current line color.

```
FUNCTION GetLineColor (BYVAL hTreeView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the current line color, or the CLR_DEFAULT value if none has been specified.

#### Remarks

This message only retrieves line colors. To retrieve the colors of the plus sign (+) and minus sign (-) inside the buttons, use the **GetTextColor** method.

---

### GetlParam

Retrieves the **lParam** value from a Treeview.

```
FUNCTION GetlParam (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS LPARAM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

---

### GetSelection

Retrieves the currently selected item in a treeview control.

```
FUNCTION GetSelection (BYVAL hTreeView AS HWND) AS HTREEITEM
FUNCTION GetSelect (BYVAL hTreeView AS HWND) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetNext

Retrieves the next sibling item of a specified item in a treeview control.

```
FUNCTION GetNext (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetNextItem

Retrieves the tree-view item that bears the specified relationship to a specified item.

```
FUNCTION GetNextItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |
| *code* | Flag specifying the item to retrieve. This parameter can be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **TVGN_CARET** | Retrieves the currently selected item. You can use the **GetSelection** method to send this message. |
| **TVGN_CHILD** | Retrieves the first child item of the item specified by the hitem parameter. You can use the **GetChild** method to send this message. |
| **TVGN_DROPHILITE** | Retrieves the item that is the target of a drag-and-drop operation. You can use the **GetDropHilight** method to send this message. |
| **TVGN_FIRSTVISIBLE** | Retrieves the first visible item. You can use the **GetFirstVisible** method to send this message. |
| **TVGN_NEXT** | Retrieves the next sibling item. You can use the **GetNextSibling** method to send this message. |
| **TVGN_NEXTSELECTED** | Windows Vista and later. Retrieves the next selected item. You can use the **GetNextSelected** method to send this message. |
| **TVGN_NEXTVISIBLE** | Retrieves the next visible item that follows the specified item. The specified item must be visible. Use the **TVM_GETITEMRECT** message to determine whether an item is visible. You can use the **GetNextVisible** method to send this message. |
| **TVGN_PARENT** | Retrieves the parent of the specified item. You can use the **GetParent** method to send this message. |
| **TVGN_PREVIOUS** | Retrieves the previous sibling item. You can use the **GetPrevSibling** method to send this message. |
| **TVGN_PREVIOUSVISIBLE** | Retrieves the first visible item that precedes the specified item. The specified item must be visible. Use the **TVM_GETITEMRECT** message to determine whether an item is visible. You can use the **GetPrevVisible** method to send this message. |
| **TVGN_ROOT** | Retrieves the topmost or very first item of the tree-view control. You can use the **GetRoot** method to send this message. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

#### Remarks

This method will return NULL if the item being retrieved is the root node of the tree. For example, if you use this method with the **TVGN_PARENT** flag on a first-level child of the tree view's root node, the method will return NULL.

---

### GetNextSelected

Retrieves the tree-view item that bears the **TVGN_NEXTSELECTED** relationship to a specified tree item.

```
FUNCTION GetNextSelected (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

#### Return value

Returns the handle to an item, or NULL if no item is found with the **TVGN_NEXTSELECTED** relationship.

#### Remarks

Used to find the next selected item when there are multiple items selected.

---

### GetNextSibling

Retrieves the next sibling item of a specified item in a tree-view control.

```
FUNCTION GetNextSibling (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetNextVisible

Retrieves the next visible item that follows a specified item in a tree-view control. 

```
FUNCTION GetNextVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. The specified item must be visible. Use the **TVM_GETITEMRECT** message to determine whether an item is visible. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetParent

Retrieves the parent item of the specified tree-view item.

```
FUNCTION GetParent (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. |

#### Return value

Returns the handle to the item if successful. For most cases, the message returns a NULL value to indicate an error. See the Remarks section for details.

#### Remarks

This method will return NULL if the parent of the specified item is the root node of the tree.

---

### GetParentText

Retrieves the text of the parent item of the specified treeview item.

```
FUNCTION GetParentText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
FUNCTION GetParentText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, _
   BYVAL cchTextMax AS LONG = 0) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. |
| *pwszText* | Pointer to a null-terminated string that will receive the item text. |
| *cchTextMax* | Size of the buffer pointed to by the *pwszText* member, in characters. If this structure is being used to set item attributes, this member is ignored. |

---

### GetPrevSibling

Retrieves the previous sibling item of a specified item in a tree-view control.

```
FUNCTION GetPrevSibling (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
FUNCTION GetPrevious (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetPrevVisible

Retrieves the first visible item that precedes a specified item in a tree-view control.

```
FUNCTION GetPrevVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. The specified item must be visible. Use the **GetItemRect** method to determine whether an item is visible. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetRoot

Retrieves the topmost or very first item of the treeview control.

```
FUNCTION GetPrevVisible (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. The specified item must be visible. Use the **GetItemRect** method to determine whether an item is visible. |

#### Return value

Returns the handle to the item if successful, or NULL otherwise.

---

### GetScrollTime

Retrieves the maximum scroll time for the tree-view control.

```
FUNCTION GetScrollTime (BYVAL hTreeView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the maximum scroll time, in milliseconds.

#### Remarks

The maximum scroll time is the longest amount of time that a scroll operation can take. Scrolling will be adjusted so that the scroll will take place within the maximum scroll time. A scroll operation may take less time than the maximum.

---

### GetTextColor

Retrieves the current text color of the control.

```
FUNCTION GetTextColor (BYVAL hTreeView AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns a **COLORREF** value that represents the current text color. If this value is -1, the control is using the system color for the text color.

---

### GetToolTips

Retrieves the handle to the child tooltip control used by a tree-view control.

```
FUNCTION GetToolTips (BYVAL hTreeView AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the handle to the child tooltip control, or NULL if the control is not using tooltips.

---

### GetVisibleCount

Obtains the number of items that can be fully visible in the client window of a tree-view control.

```
FUNCTION GetVisibleCount (BYVAL hTreeView AS HWND) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |

#### Return value

Returns the number of items that can be fully visible in the client window of the tree-view control.

#### Remarks

The number of items that can be fully visible may be greater than the number of items in the control. The control calculates this value by dividing the height of the client window by the height of an item.

Note that the return value is the number of items that can be fully visible. If you can see all of 20 items and part of one more item, the return value is 20.

---

### HitTest

Determines the location of the specified point relative to the client area of a tree-view control. 

```
FUNCTION HitTest (BYVAL hTreeView AS HWND, BYVAL pht AS TVHITTESTINFO PTR) AS HTREEITEM
FUNCTION HitTest (HitTest (BYVAL hTreeView AS HWND, BYREF ht AS TVHITTESTINFO) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pht* | Pointer to a **TVHITTESTINFO** structure. When the message is sent, the **pt** member specifies the coordinates of the point to test. When the message returns, the **hItem** member is the handle to the item at the specified point or NULL if no item occupies the point. Also, when the message returns, the **flags** member is a hit test value that indicates the location of the specified point. For a list of hit test values, see the description of the **TVHITTESTINFO** structure. |
| *ht* | A **TVHITTESTINFO** structure. When the message is sent, the **pt** member specifies the coordinates of the point to test. When the message returns, the **hItem** member is the handle to the item at the specified point or NULL if no item occupies the point. Also, when the message returns, the **flags** member is a hit test value that indicates the location of the specified point. For a list of hit test values, see the description of the **TVHITTESTINFO** structure. |

#### Return value

Returns the handle to the tree-view item that occupies the specified point, or NULL if no item occupies the point.

---

### InsertItem

Inserts a new item in a tree-view control.

```
FUNCTION InsertItem (BYVAL hTreeView AS HWND, BYVAL pisw AS TVINSERTSTRUCTW PTR) AS HTREEITEM
FUNCTION InsertItem (BYVAL hTreeView AS HWND, BYREF isw AS TVINSERTSTRUCTW) AS HTREEITEM
FUNCTION InsertItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL hInsertAfter AS HTREEITEM, _
   BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS LPARAM = 0, BYVAL iImage AS LONG = 0, _
   BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
FUNCTION Insert (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, BYVAL hInsertAfter AS HTREEITEM, _
   BYVAL iImage AS LONG = 0, BYVAL iSelectedImage AS LONG = 0, BYVAL pwszText AS WSTRING PTR) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pisw* | Pointer to a **TVINSERTSTRUCTW** structure that specifies the attributes of the tree-view item. |
| *isw* | A **TVINSERTSTRUCTW** structure that specifies the attributes of the tree-view item. |
| *hParenmt* | Handle to the parent item. If this member is the **TVI_ROOT** value or NULL, the item is inserted at the root of the tree-view control. |
| *hInsertAfter* | Handle to the item after which the new item is to be inserted, or one of the following values:<br>**TVI_FIRST**: Inserts the item at the beginning of the list.<br>**TVI_LAST**: Inserts the item at the end of the list.<br>**TVI_ROOT**: Add the item as a root item.<br>**TVI_SORT**: Inserts the item into the list in alphabetical order. |
| *iImage* | Index in the tree-view control's image list of the icon image to use when the item is in the nonselected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |
| *iSelectedImage* | Index in the tree-view control's image list of the icon image to use when the item is in the selected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |
| *pwszText* | Pointer to a null-terminated string that contains the item text if the structure specifies item attributes. If this member is the LPSTR_TEXTCALLBACK value, the parent window is responsible for storing the name. In this case, the tree-view control sends the parent window a TVN_GETDISPINFO notification code when it needs the item text for displaying, sorting, or editing and a TVN_SETDISPINFO notification code when the item text changes. If the structure is receiving item attributes, this member is the address of the buffer that receives the item text. Note that although the tree-view control allows any length string to be stored as item text, only the first 260 characters are displayed. |

#### Return value

Returns the **HTREEITEM** handle to the new item if successful, or NULL otherwise.

---

### InsertFirstItem

Inserts the item at the beginning of the list in a treeview control.

```
FUNCTION InsertFirstItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
   BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, _
   BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hParent* | Handle to the parent item. If this member is the **TVI_ROOT** value or NULL, the item is inserted at the root of the tree-view control. |
| *pwszText* | Pointer to a null-terminated string that contains the item text if the structure specifies item attributes. If this member is the LPSTR_TEXTCALLBACK value, the parent window is responsible for storing the name. In this case, the tree-view control sends the parent window a TVN_GETDISPINFO notification code when it needs the item text for displaying, sorting, or editing and a TVN_SETDISPINFO notification code when the item text changes. If the structure is receiving item attributes, this member is the address of the buffer that receives the item text. Note that although the tree-view control allows any length string to be stored as item text, only the first 260 characters are displayed. |
| *lParam* | A value to associate with the item. |
| *iImage* | Index in the tree-view control's image list of the icon image to use when the item is in the nonselected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |
| *iSelectedImage* | Index in the tree-view control's image list of the icon image to use when the item is in the selected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |

#### Return value

Returns the **HTREEITEM** handle to the new item if successful, or NULL otherwise.

---

### InsertSortedItem

Inserts the item into the list in alphabetical order.

```
FUNCTION InsertSortedItem (BYVAL hTreeView AS HWND, BYVAL hParent AS HTREEITEM, _
   BYVAL pwszText AS WSTRING PTR, BYVAL lParam AS ..LPARAM = 0, BYVAL iImage AS LONG = 0, _
   BYVAL iSelectedImage AS LONG = 0) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hParent* | Handle to the parent item. If this member is the **TVI_ROOT** value or NULL, the item is inserted at the root of the tree-view control. |
| *pwszText* | Pointer to a null-terminated string that contains the item text if the structure specifies item attributes. If this member is the LPSTR_TEXTCALLBACK value, the parent window is responsible for storing the name. In this case, the tree-view control sends the parent window a TVN_GETDISPINFO notification code when it needs the item text for displaying, sorting, or editing and a TVN_SETDISPINFO notification code when the item text changes. If the structure is receiving item attributes, this member is the address of the buffer that receives the item text. Note that although the tree-view control allows any length string to be stored as item text, only the first 260 characters are displayed. |
| *lParam* | A value to associate with the item. |
| *iImage* | Index in the tree-view control's image list of the icon image to use when the item is in the nonselected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |
| *iSelectedImage* | Index in the tree-view control's image list of the icon image to use when the item is in the selected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a TVN_GETDISPINFO notification code to retrieve the index when it needs to display the image. |

#### Return value

Returns the **HTREEITEM** handle to the new item if successful, or NULL otherwise.

---

### IsItemChecked

Returns TRUE if the item is checked, or FALSE otherwise.

```
FUNCTION IsItemChecked (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. |

---

### ItemExists

Searches for an exact string in a tree view node. Search is case sensitive.

```
FUNCTION ItemExists (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | Handle to a node. |
| *pwszText* | The string to search. |

#### Returen value

Returns TRUE if the string exists, or FALSE otherwise.

---

### ItemExistsIgnoreCase

Searches for an exact string in a tree view node. Search is case insensitive.

```
FUNCTION ItemExistsIgnoreCase (BYVAL hTreeView AS HWND, BYVAL hNode AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hNode* | Handle to a node. |
| *pwszText* | The string to search. |

#### Returen value

Returns TRUE if the string exists, or FALSE otherwise.

---

### MapAccIDToHTREEITEM

Maps an accessibility ID to an **HTREEITEM**.

```
FUNCTION MapAccIDToHTREEITEM (BYVAL hTreeView AS HWND, BYVAL id AS UINT) AS HTREEITEM
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *id* | The accessibility ID to map to an HTREEITEM. |

#### Returen value

Returns the **HTREEITEM** to which the specified accessibility ID is mapped.

#### Remarks

To use **MapAccIDToHTREEITEM**, specify Comctl32.dll version 6 in the manifest.

**Note**: The accessibility ID is not the same as that mentioned in **IAccessibleObject**. This is a unique ID used for treeview items as long as treeitems do not exceed the max limit of UINT.

---

### MapHTREEITEMToAccID

Maps an **HTREEITEM** to an accessibility ID.

```
FUNCTION MapHTREEITEMToAccID (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | The value to be mapped. |

#### Returen value

Returns an accessibility ID.

#### Remarks

To use **MapHTREEITEMToAccID**, specify Comctl32.dll version 6 in the manifest.

**Note**: The accessibility ID is not the same as that mentioned in **IAccessibleObject**. This is a unique ID used for treeview items as long as treeitems do not exceed the max limit of UINT.

---

### SelectDropTarget

Redraws a specified tree-view control item in the style used to indicate the target of a drag-and-drop operation.

```
FUNCTION SelectDropTarget (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. If the hitem parameter is NULL, the control is set to have no selected item. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the specified item is the child of a collapsed parent item, the parent's list of child items is expanded to reveal the specified item. In this case, the parent window receives the **TVN_ITEMEXPANDING** and **TVN_ITEMEXPANDED** notification codes.

Using the **SelectDropTarget** method is equivalent to sending the **TVM_SELECTITEM** message with its flag parameter set to the **TVGN_DROPHILITE** value.

---

### SelectItem

Selects the specified tree-view item.

```
FUNCTION SelectItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
FUNCTION SelectItem (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL code AS UINT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. If the hitem parameter is NULL, the control is set to have no selected item. |
| *code* | Action flag. This parameter can be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **TVGN_CARET** | Sets the selection to the given item. The control's parent window receives the TVN_SELCHANGING and TVN_SELCHANGED notification codes. |
| **TVGN_DROPHILITE** | Redraws the given item in the style used to indicate the target of a drag-and-drop operation. |
| **TVGN_FIRSTVISIBLE** | Ensures that the specified item is visible, and, if possible, displays it at the top of the control's window. Tree-view controls display as many items as will fit in the window. If the specified item is near the bottom of the control's hierarchy of items, it might not become the first visible item, depending on how many items fit in the window. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the specified item is the child of a collapsed parent item, the parent's list of child items is expanded to reveal the specified item. In this case, the parent window receives the **TVN_ITEMEXPANDING** and **TVN_ITEMEXPANDED** notification codes.

---

### SelectSetFirstVisible

Scrolls the tree-view control vertically to ensure that the specified item is visible. If possible, the specified item becomes the first visible item at the top of the control's window.

```
FUNCTION SelectSetFirstVisible (BYVAL hTreeView AS HWND, BYVAL hitem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hitem* | Handle to an item. If the *hitem* parameter is NULL, the control is set to have no selected item. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Tree-view controls display as many items as will fit in the window. If the specified item is near the bottom of the control's hierarchy of items, it might not become the first visible item, depending on how many items fit in the window.

If the specified item is the child of a collapsed parent item, the parent's list of child items is expanded to reveal the specified item. In this case, the parent window receives the **TVN_ITEMEXPANDING** and **TVN_ITEMEXPANDED** notification codes.

Using the **SelectSetFirstVisible** method is equivalent to sending the **TVM_SELECTITEM** message with its flag parameter set to the **TVGN_FIRSTVISIBLE** value.

---

### SetAutoScrollInfo

Sets information used to determine auto-scroll characteristics.

```
FUNCTION SetAutoScrollInfo (BYVAL hTreeView AS HWND, BYVAL uPixPerSec AS UINT, BYVAL uUpdateTime AS UINT) AS LRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *uPixPerSec* | Specifies pixels per second. The offset to scroll is divided by the uPixPerSec to determine the total duration of the auto-scroll. |
| *uUpdateTime* | Specifies the redraw time interval. Redraw at every elapsed interval, until the item is scrolled into view. Given uPixPerSec, the location of the item is calculated and a repaint occurs. Set this value to create smooth scrolling. |

#### Return value

Returns TRUE.

#### Remarks

Autoscroll information is used to scroll a nonvisible item into view. The control must have the **TVS_EX_AUTOHSCROLL** extended style.

---

### SetBkColor

Sets the background color of the control.

```
FUNCTION SetBkColor (BYVAL hTreeView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *ckr* | **COLORREF** value that contains the new background color. If this argument is -1, the control will revert to using the system color for the background color. |

#### Return value

Returns a **COLORREF** value that represents the previous background color. If this value is -1, the control was using the system color for the background color.

---

### SetBold

Sets/unsets the bold attribute of the specified item.

```
SUB SetBold (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fBold AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. |
| *fBold* | TRUE to set the item bold or FALSE otherwise.|

---

### SetCheck

Sets the item's state image to "checked" or "unchecked.".

```
SUB SetCheck (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fCheck AS BOOLEAN)
SUB SetCheckState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fCheck AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to an item. |
| *fCheck* | TRUE to check the item or FALSE touncheck it.|

---

### SetExtendedStyle

Sets the extended style for a specified TreeView control.

```
FUNCTION SetExtendedStyle (BYVAL hTreeView AS HWND, BYVAL dwExStyle AS DWORD, BYVAL mask AS UINT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *dwExStyle* | Value that indicates the extended style. For more information on styles, see [Tree-View Control Extended Styles](https://learn.microsoft.com/en-us/windows/win32/controls/tree-view-control-window-extended-styles). |
| *mask* | Mask used to select the styles to be set. |

#### Return value

If this mwthod succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

---

### SetImageList

Sets the normal or state image list for a tree-view control and redraws the control using the new images.

```
FUNCTION SetImageList (BYVAL hTreeView AS HWND, BYVAL himl AS HIMAGELIST, BYVAL iImage AS LONG = TVSIL_NORMAL) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *himl* | The **HIMAGELIST** handle to the image list. If *himl* is NULL, the message removes the specified image list from the tree-view control. |
| *iImage* | Type of image list to set. This parameter can be one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **TVSIL_NORMAL** | Indicates the normal image list, which contains selected, nonselected, and overlay images for the items of a tree-view control. |
| **TVSIL_STATE** | Indicates the state image list. You can use state images to indicate application-defined item states. A state image is displayed to the left of an item's selected or nonselected image. |

#### Return value

Returns the **HIMAGELIST** handle to the previous image list, if any, or NULL otherwise.

---

### SetInsertMark

Sets the insertion mark in a treeview control.

```
FUNCTION SetInsertMark (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL fAfter AS BOOLEAN) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | **HTREEITEM** that specifies at which item the insertion mark will be placed. If this argument is NULL, the insertion mark is removed. |
| *fAfter* | bOOLEAN value that specifies if the insertion mark is placed before or after the specified item. If this argument is nonzero, the insertion mark will be placed after the item. If this argument is zero, the insertion mark will be placed before the item. |

#### Return value

Returns nonzero if successful, or zero otherwise.

---

### SetInsertMarkColor

Sets the color used to draw the insertion mark for the tree view.

```
FUNCTION SetInsertMarkColor (BYVAL hTreeView AS HWND, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *clr* | **COLORREF** value that contains the new insertion mark color. |

#### Return value

Returns a **COLORREF** value that contains the previous insertion mark color.

---

### SetItem

Sets some or all of a tree-view item's attributes.

```
FUNCTION SetItem (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMW PTR) AS BOOLEAN
FUNCTION SetItem (BYVAL hTreeView AS HWND, BYREF item AS TVITEMW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pitem* | Pointer to a **TVITEMW** structure that contains the new item attributes. |
| *item* | A **TVITEMW** structure that contains the new item attributes. |

#### Return value

Returns a nonzero value if successful, or zero otherwise.

#### Remarks

The **hItem** member of the **TVITEMW** structure identifies the item, and the **mask** member specifies which attributes to set.

---

### SetItemEx

Sets some or all of a tree-view item's attributes.

```
FUNCTION SetItemEx (BYVAL hTreeView AS HWND, BYVAL pitem AS TVITEMEXW PTR) AS BOOLEAN
FUNCTION SetItemEx (BYVAL hTreeView AS HWND, BYREF item AS TVITEMEXW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *pitem* | Pointer to a **TVITEMEXW** structure that contains the new item attributes. |
| *item* | A **TVITEMEXW** structure that contains the new item attributes. |

#### Return value

Returns a nonzero value if successful, or zero otherwise.

#### Remarks

The **hItem** member of the **TVITEMEXW** structure identifies the item, and the **mask** member specifies which attributes to set.

---

### SetItemHeight

Sets the height of the tree-view items.

```
FUNCTION SetItemHeight (BYVAL hTreeView AS HWND, BYVAL cyItem AS SHORT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *cyItem* | New height of every item in the tree view, in pixels. Heights less than 1 will be set to 1. If this argument is not even, it will be rounded down to the nearest even value. If this argument is -1, the control will revert to using its default item height. |

#### Return value

Returns the previous height of the items, in pixels.

#### Remarks

The tree-view control uses this value for the height of all items. To modify the height of individual items, see the description of the **iIntegral** member of the **TVITEMEXW** structure.

---

### SetItemState

Sets a tree-view item's state attributes

```
SUB SetItemState (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL state AS UINT, BYVAL statemask AS UINT)
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |
| *state* | Set of bit flags and image list indexes that indicate the item's state. |
| *statemask* | Bits of the state member that are valid. |

#### Return value

Returns the previous height of the items, in pixels.

#### Remarks

The tree-view control uses this value for the height of all items. To modify the height of individual items, see the description of the **iIntegral** member of the **TVITEMEXW** structure.

---

### SetLineColor

Sets the current line color.

```
FUNCTION SetLineColor (BYVAL hTreeView AS HWND, BYVAL clrLine AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *clrLine* | A **COLORREF** that specifies the new line color. Use the CLR_DEFAULT value to restore the system default colors. |

#### Return value

Returns the previous line color.

#### Remarks

This method only changes line colors. To change the colors of the plus sign (+) and minus sign (-) inside the buttons, use the **SetTextColor** macro.

---

### SetScrollTime

Sets the maximum scroll time for the tree-view control.

```
FUNCTION SetScrollTime (BYVAL hTreeView AS HWND, BYVAL uMaxScrollTime AS UINT) AS UINT
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *uMaxScrollTime* | New maximum scroll time, in milliseconds. If this value is less than 100, it will be rounded up to 100. |

#### Return value

Returns the previous scroll time, in milliseconds.

#### Remarks

The maximum scroll time is the longest amount of time that a scroll operation can take. Scrolling will be adjusted so that the scroll will take place within the maximum scroll time. A scroll operation may take less time than the maximum.

---

### SetText

Sets the text of the specified item.

```
FUNCTION SetText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
FUNCTION SetItemText (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the item. |
| *pwszText* | Pointer to a unicode string with the text to set. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetTextColor

Sets the text color of the control.

```
FUNCTION SetTextColor (BYVAL hTreeView AS HWND, BYVAL clrText AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *clrText* | **COLORREF** value that contains the new text color. If this argument is -1, the control will revert to using the system color for the text color. |

#### Return value

Returns a **COLORREF** value that represents the previous text color. If this value is -1, the control was using the system color for the text color.

---

### SetToolTips

Sets a tree-view control's child tooltip control.

```
FUNCTION SetToolTips (BYVAL hTreeView AS HWND, BYVAL hwndTT AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hwndTT* | Handle to a tooltip control. |

#### Return value

Returns the handle to tooltip control previously set for the tree-view control, or NULL if tooltips were not previously used.

#### Remarks

When created, tree-view controls automatically create a child tooltip control. To prevent a tree-view control from using tooltips, create the control with the **TVS_NOTOOLTIPS** style.

---

### Toggle

Collapses the list if it is expanded or expands it if it is collapsed.

```
FUNCTION Toggle (BYVAL hTreeView AS HWND, BYVAL hItem AS HTREEITEM) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the parent item that will be expanded or collapsed. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### Unselect

Unselects the selected item.

```
FUNCTION UnSelect (BYVAL hTreeView AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTreeView* | The handle of the TreeView control. |
| *hItem* | Handle to the parent item that will be expanded or collapsed. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---
