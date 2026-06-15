# CListBox Class

Wrapper static class on top of all the Windows `ListBox` messages

A list box control contains a simple list from which the user can generally select one or more items. List boxes provide limited flexibility compared with List View controls.

List box items can be represented by text strings, bitmaps, or both. If the list box is not large enough to display all the list box items at once, the list box provides a scroll bar. The user scrolls through the list box items and applies or removes selection status as necessary. Selecting a list box item changes its visual appearance, usually by changing the text and background colors to those specified by the relevant operating system metrics. When the user selects or deselects an item, the system sends a notification message to the parent window of the list box.

There are two types of list boxes: single-selection (the default) and multiple-selection. In a single-selection list box, the user can select only one item at a time. In a multiple-selection list box, the user can select more than one item at a time. To create a multiple-selection list box, specify the **LBS_MULTIPLESEL** or the **LBS_EXTENDEDSEL** style.

The appearance and operation of a list box is controlled by list box styles and window styles. These styles indicate whether the list is sorted, arranged in multiple columns, drawn by the application, and so on.

#### Drag list boxes

A drag list box is a special type of list box that enables the user to drag items from one position to another. An application can use a drag list box to display strings in a particular sequence and enable the user to change the sequence by dragging the items into position.

Drag list boxes have the same window styles and process the same messages as standard list boxes. To create a drag list box, first create a standard list box and then call the **MakeDragList** function.

See: [About List Boxes](https://learn.microsoft.com/en-us/windows/win32/controls/about-list-boxes)

**Include file**: CListBox.inc.

| Name       | Description |
| ---------- | ----------- |
| [AddFile](#addfile) | Adds item data to the list box. |
| [AddItemData](#additemdata) | Adds the specified filename to a list box that contains a directory listing. |
| [AddString](#addstring) | Adds a string to a list box. |
| [CalcHorizontalExtent](#calchorizontalextent) | Calculates the size, in logical units, of the widest string item. |
| [DeleteString](#deletestring) | Deletes a string in a list box. |
| [Dir](#dir) | Adds the names of directories and files that match a specified string and set of file attributes. |
| [Disable](#disable) | Disables the control. |
| [Enable](#enable) | Enables the control. |
| [FindItemData](#finditemdata) | Finds the first item in a list box that has the specified item data. |
| [FindString](#findstring) | Finds the first string in a list box that begins with the specified string. |
| [FindStringExact](#findstringexact) | Finds the first list box string that exactly matches the specified string, except that the search is not case sensitive. |
| [GetAnchorIndex](#getanchorindex) | Gets the index of the anchor item--that is, the item from which a multiple selection starts. |
| [GetCaretIndex](#getcaretindex) | Determines the index of the item that has the focus rectangle in a multiple-selection list box. |
| [GetCount](#getcount) | Gets the number of items in a list box. |
| [GetCurSel](#getcursel) | Gets the index of the currently selected item, if any, in a list box. |
| [GetHorizontalExtent](#gethorizontalextent) | Gets the width, in pixels, that a list box can be scrolled horizontally (the scrollable width) if the list box has a horizontal scroll bar. |
| [GetListBoxInfo](#getlistboxinfo) | Gets the number of items in a list box. |
| [GetItemData](#getitemdata) | Gets the application-defined value associated with the specified list box item. |
| [GetItemHeight](#getitemheight) | Gets the height of items in a list box. |
| [GetItemRect](#getitemrect) | Gets the dimensions of the rectangle that bounds a list box item as it is currently displayed in the list box. |
| [GetLocale](#getlocale) | Gets the current locale of the list box. |
| [GetSel](#getsel) | Gets the selection state of an item. |
| [GetSelCount](#getselcount) | Gets the total number of selected items in a multiple-selection list box. |
| [GetSelect](#getselect) | The listbox is searched to find the first selected item. |
| [GetSelItems](#getselitems) | Fills a buffer with an array of integers that specify the item numbers of selected items in a multiple-selection list box. |
| [GetText](#gettext) | Gets a string from a list box. |
| [GetTextLen](#gettextlen) | Gets the length of a string in a list box. |
| [GetTopIndex](#gettopindex) | Gets the index of the first visible item in a list box. |
| [InitStorage](#initstorage) | Allocates memory for storing list box items. |
| [InsertItemData](#insertitemdata) | Inserts item data to a list box. |
| [InsertString](#insertstring) | Inserts a string into a list box. |
| [ItemFromPoint](#itemfrompoint) | Gets the zero-based index of the item nearest the specified point in a list box. |
| [RemoveDarkMode](#removedarkmode) | Removes the control dark mode. |
| [ReplaceString](#replacestring) | Replaces a string, and his associated data, into a list box. |
| [ResetContent](#resetcontent) | Removes all items from a list box. |
| [SelectItemData](#selectitemdata) | Searches a list box for an item that has the specified item data. |
| [SelectString](#selectstring) | Searches a list box for an item that begins with the characters in a specified string. |
| [SelItemRange](#selitemrange) | Selects one or more consecutive items in a multiple-selection list box. |
| [SelItemRangeEx](#selitemrangeex) | Selects one or more consecutive items in a multiple-selection list box. |
| [SetAnchorIndex](#setanchorindex) | Sets the anchor item--that is, the item from which a multiple selection starts. |
| [SetCaretIndex](#setcaretindex) | Sets the focus rectangle to the item at the specified index in a multiple-selection list box. |
| [SetColumnWidth](#setcolumnwidth) | Sets the width, in pixels, of all columns in a multiple-column list box. |
| [SetCount](#setcount) | Sets the count of items in a list box created with the LBS_NODATA style and not created with the LBS_HASSTRINGS style. |
| [SetCurSel](#setcursel) | Selects a string and scroll it into view, if necessary. |
| [SetDarkMode](#setdarkmode) | Set the control dark mode. |
| [SetHorizontalExtent](#sethorizontalextent) | Sets the width, in pixels, by which a list box can be scrolled horizontally. |
| [SetItemData](#setitemdata) | Sets a value associated with the specified item in a list box. |
| [SetItemHeight](#setitemheight) | Sets the height, in pixels, of items in a list box. |
| [SetLocale](#setlocale) | Sets the current locale of the list box. |
| [SetSel](#setsel) | Selects a string in a list box. |
| [SetTabStops](#settabstops) | Sets the tab-stop positions in a list box. |
| [SetText](#settext) | Sets the text of the specified item. |
| [SetTopIndex](#settopindex) | Ensures that a particular item in a list box is visible. |
| [UnselectString](#unselectstring) | Unselects the specified string in a multiple-selection list box. |

---

### AddFile

Adds the specified filename to a list box that contains a directory listing.

```
FUNCTION CListBox.AddFile (BYVAL hListBox AS HWND, BYVAL pwszFileName AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *pwszFileName* | A pointer to a buffer that specifies the name of the file to add. |

#### Return value

The return value is the zero-based index of the file that was added, or LB_ERR if an error occurs.

#### Remarks

The list box to which *pwszFileName* is added must have been filled by the **DlgDirList** function.

The **LB_INITSTORAGE** message helps speed up the initialization of list boxes that have a large number of items (more than 100). It reserves the specified amount of memory so that subsequent **LB_ADDFILE** messages take the shortest possible time. You can use estimates for the *wParam* and *lParam* parameters. If you overestimate, the extra memory is allocated; if you underestimate, the normal allocation is used for items that exceed the requested amount.

#### Usage example
```
CListBox.AddFile(hListBox, filename)
```
---

### AddItemData

Adds item data to the list box.

```
FUNCTION CListBox.AddItemData (BYVAL hListBox AS HWND, BYVAL pData AS ANY PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *pData* | Specifies the value to be associated with the item. If the list box has an owner-drawn style but not the LBS_HASSTRINGS style, this parameter is stored as item data instead of a string. You can send the LB_GETITEMDATA and LB_SETITEMDATA messages to retrieve or modify the item data. |

#### Return value

The return value is the zero-based index of the string in the list box. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

---

### AddString

Adds a string to a list box. If the list box does not have the LBS_SORT style, the string is added to the end of the list. Otherwise, the string is inserted into the list and the list is sorted.

```
FUNCTION CListBox.AssString(BYVAL hListBox AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *pwszText* | A pointer to the null-terminated string that is to be added. |

#### Return value

The return value is the zero-based index of the string in the list box. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

#### Remarks

If the list box has an owner-drawn style and the LBS_SORT style, but not the LBS_HASSTRINGS style, the system sends the WM_COMPAREITEM message one or more times to the owner of the list box to place the new item properly in the list box.

The LB_INITSTORAGE message helps speed up the initialization of list boxes that have a large number of items (more than 100). It reserves the specified amount of memory so that subsequent LB_ADDSTRING messages take the shortest possible time. You can use estimates for the wParam and lParam parameters. If you overestimate, the extra memory is allocated; if you underestimate, the normal allocation is used for items that exceed the requested amount.

If the list box has the WS_HSCROLL style and you add a string wider than the list box, send an LB_SETHORIZONTALEXTENT message to ensure the horizontal scroll bar appears.

#### Usage example
```
CListBox.AddString(hListBox, "New string")
```
---

### CalcHorizontalExtent

Calculates the size, in logical units, of the widest string item.

```
FUNCTION CListBox.CalcHorizontalExtent(BYVAL hListBox AS HWND) AS LONG
```

#### Return value

Returns the size, in logical units, of the widest string item in the ListBox.

#### Usage example
```
DIM cx AS LONG = CListBox.CalcHorizontalExtent(hListBox)
```
---

### DeleteString

Deletes a string in a list box.

```
FUNCTION CListBox.DeleteString (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the string to be deleted. |

#### Return value

The return value is a count of the strings remaining in the list. The return value is LB_ERR if the *index* parameter specifies an index greater than the number of items in the list.

#### Remarks

If an application creates the list box with an owner-drawn style but without the LBS_HASSTRINGS style, the system sends a WM_DELETEITEM message to the owner of the list box so the application can free any additional data associated with the item.

#### Usage example
```
CListBox.DeleteString(hListBox, 5)
```
---

### AddDir

Adds names to the list displayed by a list box. The message adds the names of directories and files that match a specified string and set of file attributes. It can also add mapped drive letters to the list box.

```
FUNCTION Dir (BYVAL hListBox AS HWND, BYVAL Attr AS DWORD, BYVAL pwszFileSpec AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *Attr* | The attributes of the files or directories to be added to the list box. This parameter can be one or more of the values listed below. |
| *pwszFileSpec* | A pointer to the null-terminated string that specifies an absolute path, relative path, or filename. An absolute path can begin with a drive letter (for example, d:) or a UNC name (for example, \\\\machinename\\sharename). If the string specifies a filename or directory that has the attributes specified by the *Attr* parameter, the filename or directory is added to the list. If the filename or directory name contains wildcard characters (? or *), all files or directories that match the wildcard expression and have the attributes specified by the *Attr* parameter are added to the list. |

| Attribute | Meaning |
| --------- | ----------- |
| **DDL_ARCHIVE** | Includes archived files. |
| **DDL_DIRECTORY** | Includes subdirectories. Subdirectory names are enclosed in square brackets ([ ]). |
| **DDL_DRIVES** | All mapped drives are added to the list. Drives are listed in the form [-x-], where x is the drive letter. |
| **DDL_EXCLUSIVE** | Includes only files with the specified attributes. By default, read/write files are listed even if **DDL_READWRITE** is not specified. |
| **DDL_HIDDEN** | Includes hidden files. |
| **DDL_READONLY** | Includes read-only files. |
| **DDL_READWRITE** | Includes read/write files with no additional attributes. This is the default setting. |
| **DDL_SYSTEM** | Includes system files. |

#### Return value

If the message succeeds, the return value is the zero-based index of the last name added to the list.

If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new strings, the return value is LB_ERRSPACE.

#### Remarks

The LB_INITSTORAGE message helps speed up the initialization of list boxes that have a large number of items (more than 100). It reserves the specified amount of memory so that subsequent LB_DIR messages take the shortest possible time. You can use estimates for the *wParam* and *lParam* parameters. If you overestimate, the extra memory is allocated; if you underestimate, the normal allocation is used for items that exceed the requested amount.

If *Attr* includes the DDL_DIRECTORY flag and *pwszFileSpec* specifies all the subdirectories of a first-level directory, such as C:\\TEMP\\*, the list box will always include a ".." entry for the root directory. This is true even if the root directory has hidden or system attributes and the DDL_HIDDEN and DDL_SYSTEM flags are not specified. The root directory of an NTFS volume has hidden and system attributes.

The list displays long filenames, if any.

#### Usage example
```
CListBox.Adddir(hListBox, DDL_DIRECTORY, filepath)
```
---

### Disable

Disables the control

```
FUNCTION Disable (BYVAL hListBox AS HWND) AS BOOLEAN
```

#### Return value

False if the control was previous disabled; otherwise TRUE.

#### Usage example
```
CListBox.Disable(hListBox)
```
---

### Enable

Enables the control

```
FUNCTION Enable (BYVAL hListBox AS HWND) AS BOOLEAN
```

#### Return value

Return value: False if the control was previous enabled; otherwise TRUE

#### Usage example
```
CListBox.Enable(hListBox)
```
---

### FindItemData

Finds the first item in a list box that has the specified item data.

```
FUNCTION FindItemData (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS ANY PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *indexStart* | The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list box, it continues searching from the top of the list box back to the item specified by the *indexStart* parameter. If *indexStart* is -1, the entire list box is searched from the beginning. |
| *pData* | The data value to find. |

#### Return value

The return value is the index of the matching item, or LB_ERR if the search was unsuccessful.

#### Usage example
```
CListBox.FindItemData(hListBox, 4, pdata)
```
---

### FindString

Finds the first string in a list box that begins with the specified string.

```
FUNCTION FindString (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pwszString AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *indexStart* | The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list box, it continues searching from the top of the list box back to the item specified by the *indexStart* parameter. If *indexStart* is -1, the entire list box is searched from the beginning. |
| *pwszString* | A pointer to the null-terminated string that contains the string for which to search. The search is case independent, so this string can contain any combination of uppercase and lowercase letters. |

#### Return value

The return value is the index of the matching item, or LB_ERR if the search was unsuccessful.

#### Remarks

If the list box has the owner-drawn style but not the LBS_HASSTRINGS style, the action taken by LB_FINDSTRING depends on whether the LBS_SORT style is used. If LBS_SORT is used, the system sends WM_COMPAREITEM messages to the list box owner to determine which item matches the specified string.

#### Usage example
```
CListBox.FindString(hListBox, 4, "strig to find")
```
---

### FindStringExact

Finds the first list box string that exactly matches the specified string, except that the search is not case sensitive.

```
FUNCTION FindStringExact (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pwszSearchString AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *indexStart* | The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list box, it continues searching from the top of the list box back to the item specified by the *indexStart* parameter. If *indexStart* is -1, the entire list box is searched from the beginning. |
| *pwszString* | A pointer to the null-terminated string that contains the string for which to search. The search is case independent, so this string can contain any combination of uppercase and lowercase letters. |

#### Return value

The return value is the index of the matching item, or LB_ERR if the search was unsuccessful.

#### Remarks

This function is only successful if the specified string and a list box item have the same length (except for the null at the end of the specified string) and have exactly the same characters.

If the list box has the owner-drawn style but not the LBS_HASSTRINGS style, the action taken by LB_FINDSTRING depends on whether the LBS_SORT style is used. If LBS_SORT is used, the system sends WM_COMPAREITEM messages to the list box owner to determine which item matches the specified string.

#### Usage example
```
CListBox.FindStringExact(hListBox, 4, "strig to find")
```
---

### GetAnchorIndex

Gets the index of the anchor item that is, the item from which a multiple selection starts. A multiple selection spans all items from the anchor item to the caret item.

```
FUNCTION GetAnchorIndex (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the zero-based index of the anchor item, or LB_ERR if an error occurs.

#### Usage example
```
DIM index AS LONG = CListBox.GetAnchorIndex(hListBox)
```
---

### GetCaretIndex

Retrieves the index of the item that has the focus in a multiple-selection list box. The item may or may not be selected.

```
FUNCTION GetCaretIndex (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the zero-based index of the focused list box item, or 0 if no item has the focus.

#### Remarks

This message can also be used to get the index of the item that is currently selected in a single-selection list box.

#### Usage example
```
DIM index AS LONG = CListBox.GetCaretIndex(hListBox)
```
---

### GetCount

Gets the number of items in a list box.

```
FUNCTION GetCount (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the number of items in the list box, or LB_ERR if an error occurs.

#### Remarks

The returned count is one greater than the index value of the last item (the index is zero-based).

#### Usage example
```
DIM count AS LONG = CListBox.GetCount(hListBox)
```
---

### GetCurSel

Gets the index of the currently selected item, if any, in a list box.

```
FUNCTION GetCurSel (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the zero-based index of the currently selected item. If there is no selection, the return value is LB_ERR.

#### Usage example
```
DIM sel AS LONG = CListBox.GetCurSel(hListBox)
```
---

### GetHorizontalExtent

Gets the width, in pixels, that a list box can be scrolled horizontally (the scrollable width) if the list box has a horizontal scroll bar.

```
FUNCTION GetHorizontalExtent (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the scrollable width, in pixels, of the list box.

#### Remarks

To respond to the LB_GETHORIZONTALEXTENT message, the list box must have been defined with the WS_HSCROLL style.

If the application does not set the horizontal extent of the list box (using LB_SETHORIZONTALEXTENT), the default horizontal extent is zero. Note that the list box does not update its horizontal extent dynamically.

#### Usage example
```
DIM cx AS LONG = CListBox.GetHorizontalExtent(hListBox)
```
---

### GetListBoxInfo

Gets the number of items per column in a specified list box.

```
FUNCTION GetListBoxInfo (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the number of items per column.

#### Remarks

This message is equivalent to **GetListBoxInfo**.

#### Usage example
```
DIM items AS LONG = CListBox.GetListBoxInfo(hListBox)
```
---

### GetItemData

Gets the application-defined value associated with the specified list box item.

```
FUNCTION GetItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS ANY PTR
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The index of the item. |

#### Return value

The return value is the value associated with the item, or LB_ERR if an error occurs. If the item is in an owner-drawn list box and was created without the LBS_HASSTRINGS style, this value was in the lParam parameter of the LB_ADDSTRING or LB_INSERTSTRING message that added the item to the list box. Otherwise, it is the value in the lParam of the LB_SETITEMDATA message.

#### Usage example
```
DIM pData AS ANY PTR = CListBox.GetItemData(hListBox)
```
---

### GetItemHeight

Gets the height of items in a list box.

```
FUNCTION GetItemHeight (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The index of the item. |

#### Return value

The return value is the height, in pixels, of each item in the list box. The return value is the height of the item specified by the wParam parameter if the list box has the LBS_OWNERDRAWVARIABLE style. The return value is LB_ERR if an error occurs.

#### Usage example
```
DIM height AS LONG = CListBox.GetItemHeight(hListBox)
```
---

### GetItemRect

Gets the dimensions of the rectangle that bounds a list box item as it is currently displayed in the list box.

```
FUNCTION GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL prc AS RECT PTR) AS LONG
FUNCTION GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYREF rc AS RECT) AS LONG
FUNCTON GetItemRect (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the item. |
| *prc* | A pointer to a RECT structure that will receive the client coordinates for the item in the list box. |
| *rc* | A RECT structure that will receive the client coordinates for the item in the list box. |

#### Return value

If an error occurs, the return value is LB_ERR.

#### Usage example
```
DIM rc AS RECT
CListBox.GetItemRect(hListBox, 5, @rc)
CListBox.GetItemRect(hListBox, 5, rc)
rc = CListBox.GetItemRect(hListBox, 5)
```
---

### GetLocale

Gets the current locale of the list box. You can use the locale to determine the correct sorting order of displayed text (for list boxes with the LBS_SORT style) and of text added by the LB_ADDSTRING message.

```
FUNCTION GetLocale (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value specifies the current locale of the list box. The HIWORD contains the country/region code and the LOWORD contains the language identifier.

#### Remarks

The language identifier consists of a sublanguage identifier and a primary language identifier. Use the PRIMARYLANGID macro to extract the primary language identifier from the LOWORD of the return value, and the SUBLANGID macro to extract the sublanguage identifier.

#### Usage example
```
DIM locale AS LONG = CListBox.GetLocale(hListBox)
```
---

### GetSel

Gets the selection state of an item.

```
FUNCTION GetSel (BYVAL hListBox AS HWND, BYVAL Index AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the item. |

#### Return value

If an item is selected, the return value is greater than zero; otherwise, it is zero. If an error occurs, the return value is LB_ERR.

#### Usage example
```
DIM bSel AS BOOLEAN = CListBox.GetSel(hListBox)
```
---

### GetSelCount

Gets the total number of selected items in a multiple-selection list box.

```
FUNCTION GetSelCount (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the count of selected items in the list box. If the list box is a single-selection list box, the return value is LB_ERR.

#### Usage example
```
DIM count AS LONG = CListBox.GetSelCount(hListBox)
```
---

### GetSelect

The listbox is searched to find the first selected item. If the item parameter is included, searching starts at that position to facilitate retrieving multiple selected items. If item is omitted, the search starts at the first data item. The index number of the selected item is returned as the result of the function. If no item is selected, the value -1 is returned

```
FUNCTION GetSelect (BYVAL hListBox AS HWND, BYVAL startIndex AS LONG = 0) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *startIndex* | The zero-based index of the starting item. |

#### Return value

The index of the first select index; if no item is selected, the value -1 is returned

#### Usage example
```
DIM index AS LONG = CListBox.GetSelect(hListBox, 4)
```
---

### GetSelItems

Fills a buffer with an array of integers that specify the item numbers of selected items in a multiple-selection list box.

```
FUNCTION GetSelItems (BYVAL hListBox AS HWND, BYVAL items AS DWORD, BYVAL prgItems AS LONG PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *items* | The maximum number of selected items whose item numbers are to be placed in the buffer. |
| *prgItems* | A pointer to a buffer large enough for the number of integers specified by the *items* parameter. |

#### Return value

The return value is the number of items placed in the buffer. If the list box is a single-selection list box, the return value is LB_ERR.

---

### GetText

Gets a string from a list box.

```
FUNCTION GetText (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the item to retrieve. |

#### Return value

The text of the item.

#### Usage example
```
DIM dwsText AS DWSTRING = CListBox.GetText(hListBox, 4)
```
---

### GetTextLen

Gets the length of a string in a list box.

```
FUNCTION GetTextLen (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the string. |

#### Usage example
```
DIM nLen AS LONG = CListBox.GetTextLen(hListBox, 4)
```
---

### GetTopIndex

Gets the index of the first visible item in a list box. Initially the item with index 0 is at the top of the list box, but if the list box contents have been scrolled another item may be at the top. The first visible item in a multiple-column list box is the top-left item.

```
FUNCTION GetTopIndex (BYVAL hListBox AS HWND) AS LONG
```

#### Return value

The return value is the index of the first visible item in the list box.

#### Usage example
```
DIM index AS LONG = CListBox.GetTopIndex(hListBox)
```
---

### InitStorage

Allocates memory for storing list box items. This message can be used before an application adds a large number of items to a list box.

```
FUNCTION InitStorage (BYVAL hListBox AS HWND, BYVAL nItems AS DWORD, BYVAL nBytes AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *nItems* | The number of items for which to reserve space. |
| *nBytes* | The amount of additional memory, in bytes, to allocate for item strings. |

#### Return value

If the message is successful, the return value is the total number of items that the list box can store before a memory reallocation is needed.

If the message fails, the return value is LB_ERRSPACE.

#### Remarks

The LB_INITSTORAGE message helps speed up the initialization of list boxes that have a large number of items (more than 100). It reserves the specified amount of memory so that subsequent LB_ADDSTRING, LB_INSERTSTRING, LB_DIR, and LB_ADDFILE messages are more efficient. You can use estimates for the *nItems* and *nBytes* parameters. If you overestimate, the extra memory remains allocated; if you underestimate, the list box will allocate additional memory as necessary.

The memory required to store a string includes the null terminator. Therefore, if you plan to add 100 strings, each with a length of 10 characters, you would pass a *nItems* of 100 and an *nBytes* of 100 × (10 + 1) × sizeof(TCHAR).

#### Usage example
```
DIM items AS LONG = CListBox.InitStorage(hListBox, nItems, nBytes)
```
---

### InsertItemData

Inserts item data to a list box.

```
FUNCTION InsertItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pData AS ANY PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the position at which to insert the string. If this parameter is -1, the string is added to the end of the list. |
| *pData* | Specifies the value to be associated with the item. |

#### Return value

The return value is the index of the position at which the string was inserted. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

#### Usage example
```
DIM index AS LONG = CListBox.InsertItemData(hListBox, 3, pData)
```
---

### InsertString

Inserts a string or item data into a list box. Unlike the LB_ADDSTRING message, the LB_INSERTSTRING message does not cause a list with the LBS_SORT style to be sorted.

```
FUNCTION InsertString (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the position at which to insert the string. If this parameter is -1, the string is added to the end of the list. |
| *pData* | Specifies the value to be associated with the item. |

#### Return value

The return value is the index of the position at which the string was inserted. If an error occurs, the return value is LB_ERR. If there is insufficient space to store the new string, the return value is LB_ERRSPACE.

#### Remarks

The LB_INITSTORAGE message helps speed up the initialization of list boxes that have a large number of items (more than 100). It reserves the specified amount of memory so that subsequent LB_INSERTSTRING messages take the shortest possible time. You can use estimates for the wParam and lParam parameters. If you overestimate, the extra memory is allocated; if you underestimate, the normal allocation is used for items that exceed the requested amount.

If the list box has WS_HSCROLL style and you insert a string wider than the list box, send an LB_SETHORIZONTALEXTENT message to ensure the horizontal scroll bar appears.

#### Usage example
```
DIM index AS LONG = CListBox.InsertString(hListBox, 3, "Text string")
```
---

### ItemFromPoint

Gets the zero-based index of the item nearest the specified point in a list box.

```
FUNCTION ItemFromPoint (BYVAL hListBox AS HWND, BYVAL x AS SHORT, BYVAL y AS SHORT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *x* | The x-coordinate of a point, relative to the upper-left corner of the client area of the list box. |
| *x* | The y-coordinate of a point, relative to the upper-left corner of the client area of the list box. |

#### Usage example
```
DIM index AS LONG = CListBox.ItemFromPoint(hListBox, x, y)
```
---

### RemoveDarkMode

Removes the control dark mode. Only affects the scroll bars.

```
FUNCTION RemoveDarkMode (BYVAL hListBox AS HWND) AS HRESULT
```
#### Usage example
```
CListBox.RemoveDarkMode(hListBox)
```
---

### ReplaceString

Replaces a string, and his associated data, into a list box.

```
FUNCTION ReplaceString (BYVAL hListBox AS HWND, BYVAL index AS LONG, _
   BYVAL pwszNewText AS WSTRING PTR, BYVAL pNewData AS ANY PTR = NULL) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the string to be deleted. |
| *pwszText* | A pointer to a null-terminated unicode string. |
| *pNewData* | Specifies the value to be associated with the item. Default is NULL. |

#### Return value

The return value is the index of the position at which the string was inserted. As there is not a message to replace a string, the string is deleted and a new string is inserted.

#### Usage example
```
CListBox.ReplaceString(hListBox, 3, "New string")
```
---

### ResetContent

Removes all items from a list box.

```
SUB ResetContent (BYVAL hListBox AS HWND)
```

#### Remarks

If the list box has an owner-drawn style but not the LBS_HASSTRINGS style, the owner of the list box receives a WM_DELETEITEM message for each item in the list box.

#### Usage example
```
CListBox.ResetContent(hListBox)
```
---

### SelectItemData

Searches a list box for an item that has the specified item data. If a matching item is found, the item is selected.

```
SUB SelectItemData (BYVAL hListBox AS HWND, BYVAL indexStart AS LONG, BYVAL pData AS ANY PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *indexStart* | The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list box, it continues searching from the top of the list box back to the item specified by the *indexStart* parameter. If *indexStart* is -1, the entire list box is searched from the beginning. |
| *pData* | The data value to find. |

#### Usage example
```
CListBox.SelectItemData(hListBox, 3, pData)
```
---


### SelectString

Searches a list box for an item that begins with the characters in a specified string. If a matching item is found, the item is selected.

```
FUNCTION SelectString (BYVAL hListBox AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
FUNCTION SelectString (BYVAL hListBox AS HWND, BYVAL index AS LONG =-1) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *start* | The zero-based index of the item before the first item to be searched. When the search reaches the bottom of the list box, it continues searching from the top of the list box back to the item specified by the *start* parameter. If *start* is -1, the entire list box is searched from the beginning. |
| *pwszText* | A pointer to the null-terminated string that contains the prefix for which to search. The search is case independent, so this string can contain any combination of uppercase and lowercase letters. |
| *index* | The zero-based index of the item to be selected. |

#### Usage example
```
CListBox.SelectString(hListBox, 3, "Item 10")
CListBox.SelectString(hListBox, 5)
```
---

### SelItemRange

Selects or deselects one or more consecutive items in a multiple-selection list box.

```
FUNCTION SelItemRange (BYVAL hListBox AS HWND, BYVAL fSel AS BOOLEAN, _
   BYVAL startIndex AS SHORT, BYVAL endIndex AS SHORT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *fSel* | TRUE to select the range of items, or FALSE to deselect it. |
| *startIndex* | The zero-based index of the first item to select.
| *endIndex* | The zero-based index of the last item to select. |

#### Return value

If an error occurs, the return value is LB_ERR.

#### Remarks

Use this message only with multiple-selection list boxes.

This message can select a range only within the first 65,536 items.

#### Usage example
```
CListBox.SelItemRange(hListBox, TRUE, 3, 10)
```
---

### SelItemRangeEx

Selects one or more consecutive items in a multiple-selection list box.

```
FUNCTION SelItemRangeEx (BYVAL hListBox AS HWND, BYVAL startIndex AS LONG, BYVAL endIndex AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *startIndex* | The zero-based index of the first item to select.
| *endIndex* | The zero-based index of the last item to select. |

#### Usage example
```
CListBox.SelItemRangeEx(hListBox, TRUE, 3, 10)
```
---

### SetAnchorIndex

Sets the anchor item that is, the item from which a multiple selection starts. A multiple selection spans all items from the anchor item to the caret item.

```
FUNCTION SetAnchorIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | Specifies the zero-based index of the new anchor item. |

#### Return value

If the message succeeds, the return value is zero.

If the message fails, the return value is LB_ERR.

#### Usage example
```
CListBox.SetAnchorIndex(hListBox, 4)
```
---

### SetCaretIndex

Sets the focus rectangle to the item at the specified index in a multiple-selection list box. If the item is not visible, it is scrolled into view.

```
FUNCTION SetCaretIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL fVisibility AS BOOLEAN = FALSE) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | Specifies the zero-based index of the list box item that is to receive the focus rectangle. |
| *fVisibility* | If this value is FALSE, the item is scrolled until it is fully visible; if it is TRUE, the item is scrolled until it is at least partially visible. |

#### Return value

If an error occurs, the return value is LB_ERR (-1). Otherwise, LB_OKAY (0) is returned.

#### Remarks

If this message is sent to a single-selection list box that does not contain a selected item, the caret index is set to the item specified by the *fVisibility* parameter. If the single-selection list box does contain a selected item, the list box returns LB_ERR.

---

### SetColumnWidth

Sets the width, in pixels, of all columns in a multiple-column list box.

```
SUB SetColumnWidth (BYVAL hListBox AS HWND, BYVAL nWidth AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *nWidth* | Specifies the width, in pixels, of all columns. |

#### Usage example
```
CListBox.SetColumnWidth(hListBox, 100)
```
---

### SetCount

Sets the count of items in a list box created with the LBS_NODATA style and not created with the LBS_HASSTRINGS style.

```
SUB SetCount (BYVAL hListBox AS HWND, BYVAL nCount AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *nCount* | Specifies the new count of items in the list box. |

#### Return value

If an error occurs, the return value is LB_ERR. If there is insufficient memory to store the items, the return value is LB_ERRSPACE.

#### Remarks

The LB_SETCOUNT message is supported only by list boxes created with the LBS_NODATA style and not created with the LBS_HASSTRINGS style. All other list boxes return LB_ERR.

#### Usage example
```
CListBox.SetCount(hListBox, 200)
```
---

### SetCurSel

Selects a string and scrolls it into view, if necessary. When the new string is selected, the list box removes the highlight from the previously selected string.

```
SUB SetCurSel (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | Specifies the zero-based index of the string that is selected. If this parameter is -1, the list box is set to have no selection. |

#### Return value

If an error occurs, the return value is LB_ERR. If the wParam parameter is -1, the return value is LB_ERR even though no error occurred.

#### Remarks

Use this message only with single-selection list boxes. You cannot use it to set or remove a selection in a multiple-selection list box.

#### Usage example
```
CListBox.SetCurSel(hListBox, 200)
```
---

### SetDarkMode

Set the control dark mode. Only affects the scroll bars.

```
FUNCTION CListBox.SetDarkMode (BYVAL hListBox AS HWND) AS HRESULT
```

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

#### Usage example
```
CListBox.SetDarkMode(hListBox)
```
---

### SetHorizontalExtent

Sets the width, in pixels, by which a list box can be scrolled horizontally (the scrollable width). If the width of the list box is smaller than this value, the horizontal scroll bar horizontally scrolls items in the list box. If the width of the list box is equal to or greater than this value, the horizontal scroll bar is hidden.

```
SUB SetHorizontalExtent (BYVAL hListBox AS HWND, BYVAL cxExtent AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *cxExtent* | Specifies the number of pixels by which the list box can be scrolled. |

#### Remarks

To respond to the LB_SETHORIZONTALEXTENT message, the list box must have been defined with the WS_HSCROLL style.

Note that a list box does not update its horizontal extent dynamically.

This message has no effect on a multiple-column list box.

#### Usage example
```
CListBox.SetHorizontalExtent(hListBox, 300)
```
---

### SetItemData

Sets a value associated with the specified item in a list box.

```
FUNCTION SetItemData (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pData AS ANY PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | Specifies the zero-based index of the item. If this value is -1, the *pData* value applies to all items in the list box. |
| *pData* | Specifies the value to be associated with the item. |

#### Return value

If an error occurs, the return value is LB_ERR.

#### Remarks

If the item is in an owner-drawn list box created without the LBS_HASSTRINGS style, this message replaces the value contained in the *pData* parameter of the LB_ADDSTRING or LB_INSERTSTRING message that added the item to the list box.

#### Usage example
```
CListBox.SetItemData(hListBox, 10, pData)
```
---

### SetItemHeight

Sets the height, in pixels, of items in a list box. If the list box has the LBS_OWNERDRAWVARIABLE style, this message sets the height of the item specified by the wParam parameter. Otherwise, this message sets the height of all items in the list box.

```
FUNCTION SetItemHeight (BYVAL hListBox AS HWND, BYVAL nHeight AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | Specifies the zero-based index of the item in the list box. Use this parameter only if the list box has the LBS_OWNERDRAWVARIABLE style; otherwise, set it to zero. |
| *nHeight* | Specifies the height, in pixels, of the item. The maximum height is 255 pixels. |

#### Return value

If the index or height is invalid, the return value is LB_ERR.

#### Usage example
```
CListBox.SetItemHeight(hListBox, 30)
```
---

### SetLocale

Sets the current locale of the list box. You can use the locale to determine the correct sorting order of displayed text (for list boxes with the LBS_SORT style) and of text added by the LB_ADDSTRING message.

```
FUNCTION SetLocale (BYVAL hListBox AS HWND, BYVAL wLocaleID AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *wLocaleID* | Specifies the locale identifier that the list box will use for sorting when adding text. |

#### Return value

The return value is the previous locale identifier. If the wParam parameter specifies a locale that is not installed on the system, the return value is LB_ERR and the current list box locale is not changed.

#### Remarks

Use the MAKELCID macro to construct a locale identifier.

---

### SetSel

Selects an item in a multiple-selection list box and, if necessary, scrolls the item into view.

```
FUNCTION SetSel (BYVAL hListBox AS HWND, BYVAL fSelect AS BOOLEAN, BYVAL index AS LONG = -1) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *fSelect* | Specifies how to set the selection. If this parameter is TRUE, the item is selected and highlighted; if it is FALSE, the highlight is removed and the item is no longer selected. |
| *index* | Specifies the zero-based index of the item to set. If this parameter is -1, the selection is added to or removed from all items, depending on the value of *fSelect*, and no scrolling occurs. |

#### Usage example
```
CListBox.SetSel(hListBox, TRUE, 10)
```
---

### SetTabStops

Sets the tab-stop positions in a list box.

```
FUNCTION SetTabStops (BYVAL hListBox AS HWND, BYVAL cTabs AS LONG, BYVAL prgTabs AS LONG PTR)
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *cTabs* | Specifies the number of tab stops. |
| *prgTabs* | Pointer to the first member of an array of integers containing the tab stops. The integers represent the number of quarters of the average character width for the font that is selected into the list box. For example, a tab stop of 4 is placed at 1.0 character units, and a tab stop of 6 is placed at 1.5 average character units. However, if the list box is part of a dialog box, the integers are in dialog template units. The tab stops must be sorted in ascending order; backward tabs are not allowed. |

#### Return value

If all the specified tabs are set, the return value is TRUE; otherwise, it is FALSE.

#### Remarks

To respond to the LB_SETTABSTOPS message, the list box must have been created with the LBS_USETABSTOPS style.

If *cTabs* is 0 and *prgTabs* is NULL, the default tab stop is two dialog template units. If *cTabs* is 1, the list box will have tab stops separated by the distance specified by *prgTabs*.

If *prgTabs* points to more than a single value, a tab stop will be set for each value in *prgTabs*, up to the number specified by *cTabs*.

The values specified by *prgTabs* are in dialog template units, which are the device-independent units used in dialog box templates. To convert measurements from dialog template units to screen units (pixels), use the **MapDialogRect** function.

---

### SetText

Sets the tab-stop positions in a list box.

```
FUNCTION SetText (BYVAL hListBox AS HWND, BYVAL index AS LONG, BYVAL pwszNewText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the string to be deleted. |
| *pwszNewText* | A pointer to a null-terminated unicode string. |

#### Return value

The return value is the index of the position at which the string was inserted. As there is not a message to replace a string, the string is deleted and a new string is inserted.

#### Usage example
```
CListBox.SetText(hListBox, 3, "New string")
```
---

### SetTopIndex

Ensures that a particular item in a list box is visible.

```
FUNCTION SetTopIndex (BYVAL hListBox AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | The zero-based index of the item in the list box. |

#### Return value

If an error occurs, the return value is LB_ERR.

#### Remarks

The system scrolls the list box contents so that either the specified item appears at the top of the list box or the maximum scroll range has been reached.

#### Usage example
```
CListBox.SetTopIndex(hListBox, 15)
```
---

### UnselectString

Unselects the specified string in a multiple-selection list box.

```
FUNCTION UnselectString (BYVAL hListBox AS HWND, BYVAL index AS LONG = -1) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hListBox* | The handle of the listbox control. |
| *index* | Specifies the zero-based index of the item to unselect. If this parameter is -1, the selection is removed from all items and no scrolling occurs. |

#### Usage example
```
CListBox.UnselectString(hListBox, 5)
```
---
