# CCombo Class

A `Combobox` combines the features of a ListBox and a Edit control. The user can enter a new value, as with a Edit control, or the user can select an existing value, as with a ListBox.

See: [About Combo Boxes](https://learn.microsoft.com/en-us/windows/win32/controls/about-combo-boxes)

**Include file**: CCombo.inc

| Name       | Description |
| ---------- | ----------- |
| [AddString](#addstring) | Adds a string to the list box of a combo box. |
| [CalcHorizontalExtent](#calchorizontalextent) | Calculates the size, in logical units, of the widest string item. |
| [DeleteString](#deletestring) | Deletes a string in the list box of a combo box. |
| [Dir](#dir) | Adds the names of directories and files that match a specified string and set of file attributes. |
| [Disable](#disable) | Disables a combobox. |
| [Enable](#enable) | Enables a combobox. |
| [FindString](#findstring) | Searches the list box of a combo box for an item beginning with the characters in a specified string. |
| [FindStringExact](#findstringexact) | Finds the first list box string in a combo box that matches the string specified in the start parameter. |
| [GetComboBoxInfo](#getcomboboxinfo) | Retrieves information about the specified combo box. |
| [GetCount](#getcount) | Retrieves the number of items in the list box of a combo box. |
| [GetCueBannerText](#getcuebannertext) | Gets the cue banner text displayed in the edit control of a combo box. |
| [GetCurSel](#getcursel) | Retrieves the index of the currently selected item, if any, in the list box of a combo box. |
| [GetDroppedControlRect](#getdroppedcontrolrect) | Retrieves the screen coordinates of a combo box in its dropped-down state. |
| [GetDroppedState](#getdroppedstate) | Determines whether the list box of a combo box is dropped down. |
| [GetDroppedWidth](#getdroppedwidth) | Retrieves the minimum allowable width, in pixels, of the list box of a combo box with the CBS_DROPDOWN or CBS_DROPDOWNLIST style. |
| [GetEditBoxHandle](#geteditboxhandle) | Retrieves the handle to the edit box of the combobox. |
| [GetEditSel](#geteditsel) | Gets the starting and ending character positions of the current selection in the edit control of a combo box. |
| [GetExtendedUI](#getextendedui) | Determines whether a combo box has the default user interface or the extended user interface. |
| [GetHorizontalExtent](#gethorizontalextent) | Retrieves from a combo box the width, in pixels, by which the list box can be scrolled horizontally (the scrollable width). This is applicable only if the list box has a horizontal scroll bar. |
| [GetItemData](#getitemdata) | Retrieves the application-supplied value associated with the specified item in the combo box. |
| [GetItemHeight](#getitemheight) | Retrieves the height of list items in a combo box. |
| [GetLbText](#getlbtext) | Gets a string from the list of a combo box. |
| [GetLbTextLen](#getlbtextlen) | Retrieve the length, in characters, of a string in the list of a combo box. |
| [GetListBoxHandle](#getlistboxhandle) | Retrieves the handle to the drop-down list of the combobox. |
| [GetLocale](#getlocale) | Retrieves the current locale of the combo box. |
| [GetMinVisible](#getminvisible) | Gets the minimum number of visible items in the drop-down list of a combo box. |
| [GetSelCount](#getselcount) | Returns the number of selected items, if any, in the list box of a combo box. |
| [GetState](#getstate) | Returns TRUE if the specified item is selected; FALSE, otherwise. |
| [GetText](#gettext) | Retrieves the text in a combobox control. |
| [GetTextLength](#gettextlength) | Retrieves the length of a text item in a combobox control. |
| [GetTopIndex](#gettopindex) | Retrieves the zero-based index of the first visible item in the list box portion of a combo box. |
| [HideDropDown](#hidedropdown) | Hides the list box of a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style. |
| [InsertString](#insertstring) | Inserts a string into the list box of a combo box. |
| [LimitText](#limittext) | Limits the length of the text the user may type into the edit control of a combo box. |
| [RemoveDarkMode](#removedarkmode) | Removes the control dark mode. |
| [ReplaceText](#replacetext) | Replaces the text of an item in a combobox control. |
| [ResetContent](#resetcontent) | Removes all items from the list box and edit control of a combo box. |
| [SelectString](#selectstring) | Searches the list of a combo box for an item that begins with the characters in a specified string. If a matching item is found, it is selected and copied to the edit control. |
| [SetCueBannerText](#setcuebannertext) | Gets the cue banner text displayed in the edit control of a combo box. |
| [SetCurSel](#setcursel) | Selects a string in the list of a combo box. If necessary, the list scrolls the string into view. |
| [SetDarkMode](#setdarkmode) | Sets the control dark mode. |
| [SetDroppedWidth](#setdroppedwidth) | Sets the maximum allowable width, in pixels, of the list box of a combo box with the CBS_DROPDOWN or CBS_DROPDOWNLIST style. |
| [SetEditSel](#seteditsel) | Selects characters in the edit control of a combo box. |
| [SetExtendedUI](#setextendedui) | Selects either the default user interface or the extended user interface for a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style. |
| [SetHorizontalExtent](#sethorizontalextent) | Sets the width, in pixels, by which a list box can be scrolled horizontally. |
| [SetItemData](#setitemdata) | Sets the value associated with the specified item in a combo box. |
| [SetItemHeight](#setitemheight) | Sets the height of list items or the selection field in a combo box. |
| [SetLocale](#setlocale) | Sets the current locale of the combo box. |
| [SetMinVisible](#setminvisible) | Sets the minimum number of visible items in the drop-down list of a combo box. |
| [SetText](#settext) | Sets the text of a combobox control. |
| [SetTopIndex](#settopindex) | Ensures that a particular item is visible in the list box of a combo box. |
| [ShowDropDown](#showdropdown) | Shows the list box of a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style. |
| [UnselectString](#unselectstring) | Unselects any current selection. |

---

# CComboEx Class

`ComboBoxEx` controls are combo box controls that provide native support for item images. To make item images easily accessible, the control provides image list support. By using this control, you can provide the functionality of a combo box without having to manually draw item graphics.

**Include file**: CCombo.inc

| Name       | Description |
| ---------- | ----------- |
| [DeleteItem](#deleteitem) | Removes an item from a ComboBoxEx control. |
| [GetComboControl](#getcombocontrol) | Returns the handle to the combo box control within the ComboBoxEx control. |
| [GetEditControl](#geteditcontrol) | Returns the handle to the edit control within the ComboBoxEx control. |
| [GetExtendedStyle](#getextendedstyle) | Returns a DWORD value that contains the ComboBoxEx control extended styles in use for the control. |
| [GetImageList](#getimagelist) | Retrieves the handle to an image list assigned to a ComboBoxEx control. |
| [GetItem](#getitem) | Retrieves item information for a given ComboBoxEx item. |
| [HasEditChanged](#haseditchanged) | Determines whether or not the user has changed the text of a ComboBoxEx edit control. |
| [InsertItem](#insertitem) | Returns the index at which the new item was inserted if successful, or -1 otherwise. |
| [RemoveDarkMode](#removedarkmode) | Removes the control dark mode. |
| [SetExtendedStyle](#setextendedstyle) | Sets extended styles within a ComboBoxEx control. |
| [SetImageList](#setimagelist) | Returns the handle to the image list previously associated with the control, or returns NULL if no image list was previously set. |
| [SetItem](#setitem) | Sets the attributes for an item in a ComboBoxEx control. |
| [SetWindowTheme](#setwindowtheme) | Sets the visual style of a ComboboxEx control. |
| [SetDarkMode](#setdarkmode) | Sets the control dark mode. |

---

### AddString

Adds a string to the list box of a combo box. If the combo box does not have the CBS_SORT style, the string is added to the end of the list.

```
FUNCTION AddString (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *pwszText* | A pointer to the null-terminated string to be added. If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, the value of the *pwszText* parameter is stored as item data rather than the string it would otherwise point to. The item data can be retrieved or modified by sending the CB_GETITEMDATA or CB_SETITEMDATA message. |

#### Return value

The return value is the zero-based index to the string in the list box of the combo box. If an error occurs, the return value is CB_ERR. If insufficient space is available to store the new string, it is CB_ERRSPACE.

#### Remarks

If you create an owner-drawn combo box with the CBS_SORT style but without the CBS_HASSTRINGS style, the WM_COMPAREITEM message is sent one or more times to the owner of the combo box so the new item can be properly placed in the list.

To insert a string at a specific location within the list, use the CB_INSERTSTRING message.

If the combo box has WS_HSCROLL style and you add a string wider than the combo box, send a LB_SETHORIZONTALEXTENT message to ensure the horizontal scroll bar appears.

Comclt32.dll version 5.0 or later: If CBS_LOWERCASE or CBS_UPPERCASE is set, the Unicode version of CB_ADDSTRING alters the string. If using read-only global memory, this causes the application to fail.

#### Usage example
```
CCombo.AddString(hCombo, "New text")
```
---

### CalcHorizontalExtent

Calculates the size, in logical units, of the widest string item.

```
FUNCTION CalcHorizontalExtent (BYVAL hCombo AS HWND) AS LONG
```

#### Usage example
```
CCombo.CalcHorizontalExtent(hCombo)
```
---

### DeleteString

Adds a string to the list box of a combo box. If the combo box does not have the CBS_SORT style, the string is added to the end of the list.

```
FUNCTION DeleteString (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the string to delete. |

#### Return value

The return value is a count of the strings remaining in the list. If the wParam parameter specifies an index greater than the number of items in the list, the return value is CB_ERR.

#### Remarks

If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, the system sends a WM_DELETEITEM message to the owner of the combo box so the application can free any additional data associated with the item.

#### Usage example
```
CCombo.DeleteString(hCombo, 4)
```
---

### Dir

Adds names to the list displayed by the combo box. The message adds the names of directories and files that match a specified string and set of file attributes. CB_DIR can also add mapped drive letters to the list.

```
FUNCTION Dir (BYVAL hCombo AS HWND, BYVAL attr AS UINT, BYVAL pwszFileSpec AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *attr* | The attributes of the files or directories to be added to the combo box. This parameter can be one or more of the following values (see list below). |
| *pwszFileSpec* | Pointer to a null-terminated string that specifies an absolute path, relative path, or file name. An absolute path can begin with a drive letter (for example, d:) or a UNC name (for example, \\machinename\sharename). If the string specifies a file name or directory that has the attributes specified by the *attr* parameter, the file name or directory is added to the list. If the file name or directory name contains wildcard characters (? or *), all files or directories that match the wildcard expression and have the attributes specified by the *attr* parameter are added to the list displayed in the combo box. |

| Attribue | Meaning |
| -------- | ------- |
| **DDL_ARCHIVE** | Includes archived files. |
| **DDL_DIRECTORY** | Includes subdirectories, which are enclosed in square brackets ([ ]). |
| **DDL_DRIVES** | All mapped drives are added to the list. Drives are listed in the form [-x-], where x is the drive letter. |
| **DDL_EXCLUSIVE** | Includes only files with the specified attributes. By default, read/write files are listed even if DDL_READWRITE is not specified. |
| **DDL_HIDDEN** | Includes hidden files. |
| **DDL_READONLY** | Includes read-only files. |
| **DDL_READWRITE** | Includes read/write files with no additional attributes. This is the default. |
| **DDL_SYSTEM** | Includes system files. |

#### Return value

If the message succeeds, the return value is the zero-based index of the last name added to the list.

If an error occurs, the return value is CB_ERR. If there is insufficient space to store the new strings, the return value is CB_ERRSPACE.

#### Remarks

If *attr* includes the DDL_DIRECTORY flag and *pwszFileSpec* specifies all the subdirectories of a first-level directory, such as C:\TEMP\*, the list box will always include a ".." entry for the root directory. This is true even if the root directory has hidden or system attributes and the DDL_HIDDEN and DDL_SYSTEM flags are not specified. The root directory of an NTFS volume has hidden and system attributes.

The list displays long file names, if any.

---

### Disable

Disables the combobox. Returns FALSE if the combobox was previously disabled; otherwise TRUE.

```
FUNCTION Disable (BYVAL hCombo AS HWND) AS BOOLEAN
```

#### Usage example
```
CCombo.Disable(hCombo)
```
---

### Enable

Enables the combobox. Returns FALSE if the combobox was previously enabled; otherwise TRUE.

```
FUNCTION Enable (BYVAL hCombo AS HWND) AS BOOLEAN
```

#### Usage example
```
CCombo.Enable(hCombo)
```
---

### FindString

Searches the list box of a combo box for an item beginning with the characters in a specified string.

```
FUNCTION FindString (BYVAL hCombo AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *start* | The zero-based index of the item preceding the first item to be searched. When the search reaches the bottom of the list box, it continues from the top of the list box back to the item specified by the *start* parameter. If *start* is -1, the entire list box is searched from the beginning. |
| *pwszText* | A pointer to the null-terminated string that contains the characters for which to search. The search is not case sensitive, so this string can contain any combination of uppercase and lowercase letters. |

#### Return value

The return value is the zero-based index of the matching item. If the search is unsuccessful, it is CB_ERR.

#### Remarks

If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, what the CB_FINDSTRING message does depends on whether your application uses the CBS_SORT style. If you use the CBS_SORT style, WM_COMPAREITEM messages are sent to the owner of the combo box to determine which item matches the specified string. If you do not use the CBS_SORT style, the CB_FINDSTRING message searches for a list item that matches the value of the *pwszText* parameter.

#### Usage example
```
CCombo.FindString(hCombo, 0, "String text")
```
---

### FindStringExact

Finds the first list box string in a combo box that matches the string specified in the *start* parameter.

```
FUNCTION FindStringExact (BYVAL hCombo AS HWND, BYVAL start AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *start* | The zero-based index of the item preceding the first item to be searched. When the search reaches the bottom of the list box, it continues from the top of the list box back to the item specified by the wParam parameter. If wParam is -1, the entire list box is searched from the beginning. |
| *pwszText* | A pointer to the null-terminated string for which to search. The search is not case sensitive, so this string can contain any combination of uppercase and lowercase letters. |

#### Return value

The return value is the zero-based index of the matching item. If the search is unsuccessful, it is CB_ERR.

#### Remarks

This function is successful only if the specified string and a combo box item have the same length (except for the terminating null character) and the same characters.

If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, the functionality of CB_FINDSTRINGEXACT message depends on whether your application uses the CBS_SORT style. If you use the CBS_SORT style, WM_COMPAREITEM messages are sent to the owner of the combo box to determine which item matches the specified string. If you do not use the CBS_SORT style, the CB_FINDSTRINGEXACT message searches for a list item that matches the value of the *pwszText* parameter.

#### Usage example
```
CCombo.FindStringExact(hCombo, 0, "String text")
```
---

### GetComboBoxInfo

Finds the first list box string in a combo box that matches the string specified in the *start* parameter.

```
FUNCTION GetComboBoxInfo (BYVAL hCombo AS HWND, BYVAL pcbi AS COMBOBOXINFO PTR) AS BOOLEAN
FUNCTION GetComboBoxInfo (BYVAL hCombo AS HWND, BYREF cbi AS COMBOBOXINFO) AS BOOLEAN
FUNCTION GetComboBoxInfo (BYVAL hCombo AS HWND) AS COMBOBOXINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *pcbi* | A pointer to a **COMBOBOXINFO** structure that receives the information. |
| *cbi* | A **COMBOBOXINFO** structure that receives the information. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

#### Remarks

This message is equivalent to **GetComboBoxInfo**.

#### Usage examples
```
DIM cbi AS COMBOBOXINFO
CCombo.GetComboBoxInfo(hCombo, @cbi)
CCombo.GetComboBoxInfo(hCombo, cbi)
cbi = CCombo.GetComboBoxInfo(hCombo)
```
---

### GetCount

Gets the number of items in the list box of a combo box.

```
FUNCTION GetCount (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

The return value is the number of items in the list box. If an error occurs, it is CB_ERR.

#### Remarks

The index is zero-based, so the returned count is one greater than the index value of the last item.

#### Usage example
```
DIM count AS LONG = CCombo.GetCount(hCombo)
```
---

### GetCueBannerText

Gets the cue banner text displayed in the edit control of a combo box.

```
FUNCTION GetCueBannerText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS DWORD) AS BOOLEAN
FUNCTION GetCueBannerText (BYVAL hCombo AS HWND, BYVAL cchText AS DWORD) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *pwszText* | A pointer to a Unicode string buffer that receives the cue banner text. The calling application is responsible for allocating the memory for the buffer. The buffer size must be equal to the length of the cue banner string in characters, plus 1—for the terminating NULL character. |
| *cchText* | The size of the buffer pointed to by pwszText in characters. |

#### Return value

Returns TRUE if successful, or an error value otherwise.

#### Usage example
```
DIM dwsText AS DWSTRING = CCombo.GetCueBannerText(hCombo, 260)
```
---

### GetCurSel

Retrieves the index of the currently selected item, if any, in the list box of a combo box.

```
FUNCTION GetCurSel (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

The return value is the zero-based index of the currently selected item. If no item is selected, it is CB_ERR.

#### Usage example
```
DIM idx AS LONG = CCombo.GetCurSel(hCombo)
```
---

### GetDroppedControlRect

Retrieves the screen coordinates of a combo box in its dropped-down state

```
FUNCTION GetDroppedControlRect (BYVAL hCombo AS HWND, BYVAL prc AS RECT PTR)
FUNCTION GetDroppedControlRect (BYVAL hCombo AS HWND, BYREF rc AS RECT)
FUNCTION GetDroppedControlRect (BYVAL hCombo AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *prc* | A pointer to the **RECT** structure that receives the coordinates of the combo box in its dropped-down state. |
| *rc* | A **RECT** structure that receives the coordinates of the combo box in its dropped-down state. |

#### Return value

If the message succeeds, the return value is nonzero.

If the message fails, the return value is zero.

#### Usage examples
```
DIM rc AS RECT
CCombo.GetDroppedControlRect(hCombo, @rc)
CCombo.GetDroppedControlRect(hCombo, rc)
rc = CCombo.GetDroppedControlRect(hCombo)
```
---

### GetDroppedState

Determines whether the list box of a combo box is dropped down.

```
FUNCTION GetDroppedState (BYVAL hCombo AS HWND) AS BOOLEAN
```

#### Return value

If the list box is visible, the return value is TRUE; otherwise, it is FALSE.

#### Usage example
```
DIM state AS BOOLEAN = CCombo.GetDroppedState(hCombo)
```
---

### GetDroppedWidth

Retrieves the minimum allowable width, in pixels, of the list box of a combo box with the CBS_DROPDOWN or CBS_DROPDOWNLIST style.

```
FUNCTION GetDroppedWidth (BYVAL hCombo AS HWND) AS LONG
```

#### Usage example
```
DIM nWidth AS LONG = CCombo.GetDroppedWidth(hCombo)
```

#### Return value

If the message succeeds, the return value is the width, in pixels.

If the message fails, the return value is CB_ERR.

#### Remarks

By default, the minimum allowable width of the drop-down list box is zero. The width of the list box is either the minimum allowable width or the combo box width, whichever is larger.

---

### GetEditBoxHandle

Retrieves the handle to the edit box of the combobox.

```
FUNCTION GetEditBoxHandle (BYVAL hCombo AS HWND) AS HWND
```

#### Return value

Returns the handle to the edit box of the combobox.

#### Usage example
```
DIM hEdit AS HWND = CCombo.GetEditBoxHandle(hCombo)
```
---

### GetEditSel

Gets the starting and ending character positions of the current selection in the edit control of a combo box.

```
FUNCTION GetEditSel (BYVAL hCombo AS HWND, BYVAL pdwStart AS DWORD PTR, BYVAL pdwEnd AS DWORD PTR)
FUNCTION GetEditSel (BYVAL hCombo AS HWND, BYREF dwStart AS DWORD, BYREF dwEnd AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *pdwStart* | A pointer to a DWORD value that receives the starting position of the selection. This parameter can be NULL. |
| *pdwEnd* | A pointer to a DWORD value that receives the ending position of the selection. This parameter can be NULL. |
| *dwStart* | A DWORD variable that receives the starting position of the selection. |
| *dwEnd* | A DWORD variable that receives the ending position of the selection. |

#### Return value

The return value is a zero-based DWORD value with the starting position of the selection in the LOWORD and with the ending position of the first character after the last selected character in the HIWORD.

#### Usage examples
```
DIM dwStart AS DWORD, dwEnd AS DWORD
CCombo.GetEditSel(hCombo, @dwStart, @dwEnd)
CCombo.GetEditSel(hCombo, dwStart, dwEnd)
```
---

### GetExtendedUI

Determines whether a combo box has the default user interface or the extended user interface.

```
FUNCTION GetExtendedUI (BYVAL hCombo AS HWND) AS BOOLEAN
```

#### Return value

If the combo box has the extended user interface, the return value is TRUE; otherwise, it is FALSE.

#### Remarks

By default, the F4 key opens or closes the list and the DOWN ARROW changes the current selection. In a combo box with the extended user interface, the F4 key is disabled and pressing the DOWN ARROW key opens the drop-down list.

#### Usage example
```
DIM b AS BOOLEAN = CCombo.GetExtendedUI(hCombo)
```
---

### GetHorizontalExtent

Gets the width, in pixels, that the list box can be scrolled horizontally (the scrollable width). This is applicable only if the list box has a horizontal scroll bar.

```
FUNCTION GetHorizontalExtent (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

The return value is the scrollable width, in pixels.

#### Usage example
```
DIM extent AS LONG = CCombo.GetHorizontalExtent(hCombo)
```
---

### GetItemData

Retrieves the application-supplied value associated with the specified item in the combo box.

```
FUNCTION GetItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG_PTR
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item. |

#### Return value

The return value is the value associated with the item. If an error occurs, it is CB_ERR.

If the item is in an owner-drawn combo box created without the CBS_HASSTRINGS style, the return value is the value contained in the lParam parameter of the CB_ADDSTRING or CB_INSERTSTRING message, that added the item to the combo box. If the CBS_HASSTRINGS style was not used, the return value is the lParam parameter contained in a CB_SETITEMDATA message.

#### Usage example
```
DIM dat AS LONG_PTR = CCombo.GetItemData(hCombo, 5)
```
---

### GetItemHeight

Determines the height of list items or the selection field in a combo box.

```
FUNCTION GetItemHeight (BYVAL hCombo AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control whose height is to be retrieved. This parameter must be -1 to retrieve the height of the selection field. It must be zero to retrieve the height of list items, unless the combo box has the CBS_OWNERDRAWVARIABLE style. In that case, the wParam parameter is the zero-based index of a specific list item. |

#### Usage example
```
DIM nHeight AS LONG = CCombo.GetItemHeight(hCombo, 5)
```
---

### GetLbText

Gets a string from the list of a combo box.

```
FUNCTION GetLbText (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item. |

#### Usage example
```
DIM dwsText AS DWSTRING = CCombo.GetLbText(hCombo, 5)
```
---

### GetLbTextLen

Gets the length, in characters, of a string in the list of a combo box.

```
FUNCTION GetLbTextLen (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item. |

#### Return value

The return value is the length of the string, in characters, excluding the terminating null character.

If the *index* parameter does not specify a valid index, the return value is CB_ERR.

#### Remarks

Under certain conditions, the return value is larger than the actual length of the text. This occurs with certain mixtures of ANSI and Unicode, and is due to the operating system allowing for the possible existence of double-byte character set (DBCS) characters within the text. The return value, however, will always be at least as large as the actual length of the text; so you can always use it to guide buffer allocation. This behavior can occur when an application uses both ANSI functions and common dialogs, which use Unicode.

To obtain the exact length of the text, use the WM_GETTEXT, LB_GETTEXT, or CB_GETLBTEXT messages, or the GetWindowText function.

#### Usage example
```
DIM nLen AS LONG = CCombo.GetLbTextLen(hCombo, 5)
```
---

### GetListBoxHandle

Retrieves the handle to the drop-down list of the combobox

```
FUNCTION GetListBoxHandle (BYVAL hCombo AS HWND) AS HWND
```

#### Return value

Returns the handle of the list box control of the combobox.

#### Usage example
```
DIM hLb AS HWBD = CCombo.GetListBoxHandle(hCombo)
```
---

### Getocale

Retrieves the current locale of the combo box. The locale is used to determine the correct sorting order of displayed text for combo boxes with the CBS_SORT style and text added by using the CB_ADDSTRING message.

```
FUNCTION Getocale (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

The return value specifies the current locale of the combo box. The HIWORD contains the country/region code and the LOWORD contains the language identifier.

#### Remarks

The language identifier is made up of a sublanguage identifier and a primary language identifier. The PRIMARYLANGID macro obtains the primary language identifier and the SUBLANGID macro obtains the sublanguage identifier.

#### Usage example
```
DIM lc AS LONG = CCombo.GetLocale(hCombo)
```
---

### GetMinVisible

Gets the minimum number of visible items in the drop-down list of a combo box.

```
FUNCTION GetMinVisible (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

The return value is the minimum number of visible items.

#### Remarks

When the number of items in the drop-down list is greater than the minimum, the combo box uses a scroll bar.

This message is ignored if the combo box control has style CBS_NOINTEGRALHEIGHT.

To use CB_GETMINVISIBLE, the application must specify comctl32.dll version 6 in the manifest.

#### Usage example
```
DIM minVisible AS LONG = CCombo.GetMinVisible(hCombo)
```
---

### GetSelCount

Returns the number of selected items, if any, in the list box of a combo box.

```
FUNCTION GetSelCount (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

Return 1 or 0.

#### Usage example
```
DIM count AS LONG = CCombo.GetSelCount(hCombo)
```
---

### GetState

Returns TRUE if the specified item is selected; FALSE, otherwise.

```
FUNCTION GetState (BYVAL hCombo AS HWND, BYVAL item AS LONG) AS BOOLEAN
```

#### Usage example
```
DIM bState AS BOOLEAN = CCombo.GetState(hCombo)
```
---

### GetText

Retrieves the text of the edit control in a combobox or the text of an item in the list.

```
FUNCTION GetText (BYVAL hCombo AS HWND) AS DWSTRING
FUNCTION GetText (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item. |

#### Usage examples
```
DIM dwsText AS DWSTRING = CCombo.GetText(hCombo)
DIM dwsText AS DWSTRING = CCombo.GetText(hCombo, 5)
```
---

### GetTextLength

Retrieves the length of the text of the edit control in a combobox or the text of an item in the list.

```
FUNCTION GetTextLength (BYVAL hCombo AS HWND) AS LONG
FUNCTION GetTextLength (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item. |

#### Usage examples
```
DIM mLen AS LONG = CCombo.GetTextLenth(hCombo)
DIM mLen AS LONG = CCombo.GetTextLenth(hCombo, 5)
```
---

### GetTopIndex

Retrieves the zero-based index of the first visible item in the list box portion of a combo box. Initially, the item with index 0 is at the top of the list box, but if the list box contents have been scrolled, another item may be at the top.

```
FUNCTION GetTopIndex (BYVAL hCombo AS HWND) AS LONG
```

#### Return value

If the message is successful, the return value is the index of the first visible item in the list box of the combo box.

If the message fails, the return value is CB_ERR.

#### Usage example
```
DIM idx AS LONG = CCombo.GetTopIndex(hCombo)
```
---

### HideDropDown

Hides the list box of a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.

```
SUB HideDropDown (BYVAL hCombo AS HWND)
```

#### Usage example
```
CCombo.HideDropDown(hCombo)
```
---

### InsertString

Inserts a string into the list box of a combo box. Unlike the **AddString** methods, this method does not cause a list with the CBS_SORT style to be sorted.

```
FUNCTION InsertString (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the position at which to insert the string. If this parameter is -1, the string is added to the end of the list. |
| *pwszText* | A pointer to the null-terminated string to be inserted. If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, the value of the *pwszText* parameter is stored rather than the string to which it would otherwise point. |

#### Return value

The return value is the index of the position at which the string was inserted. If an error occurs, the return value is CB_ERR. If there is insufficient space available to store the new string, it is CB_ERRSPACE.

If the combo box has WS_HSCROLL style and you insert a string wider than the combo box, you should send a LB_SETHORIZONTALEXTENT message to ensure the horizontal scroll bar appears.

#### Usage example
```
CCombo.InsertString(hCombo, 4, "New string")
```
---

### LimitText

Limits the length of the text the user may type into the edit control of a combo box.

```
SUB LimitText (BYVAL hCombo AS HWND, BYVAL chLimit AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *chLimit* | The maximum number of characters the user can enter, not including the terminating null character. If this parameter is zero, the text length is limited to &h7FFFFFFE characters. |

## Remarks
If the combo box does not have the CBS_AUTOHSCROLL style, setting the text limit to be larger than the size of the edit control has no effect.

The CB_LIMITTEXT message limits only the text the user can enter. It has no effect on any text already in the edit control when the message is sent, nor does it affect the length of the text copied to the edit control when a string in the list box is selected.

The default limit to the text a user can enter in the edit control is 30,000 characters.

#### Usage example
```
CCombo.LimitText(hCombo, 260)
```
---

### RemoveDarkMode

Removes the control dark mode.

```
FUNCTION RemoveDarkMode (BYVAL hCombo AS HWND) AS HRESULT
FUNCTION RemoveDarkMode (BYVAL hComboEx AS HWND) AS HRESULT
```

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

#### Usage example
```
CCombo.RemoveDarkMode(hCombo)
CCombo.RemoveDarkMode(hComboEx)
```
---

### ReplaceText

Replaces the text of an item in a combobox control.

```
FUNCTION ReplaceText (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item. |
| *pwszText* | A pointer to the null-terminated string to replace the text of thne item. |

#### Remarks

As this control has not a replace message, this function first deletes the specified string and the inserts a new one with the new text.

#### Usage example
```
CCombo.ReplaceText(hCombo, 5 , "New text")
```
---

### ResetContent

Removes all items from the list box and edit control of a combo box.

```
FUNCTION ResetContent (BYVAL hCombo AS HWND)
```
#### Return value

This message always returns CB_OKAY.

#### Remarks

If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, the owner of the combo box receives a WM_DELETEITEM message for each item in the combo box.

#### Usage example
```
CCombo.ResetContent(hCombo)
```
---

### SelectString

Searches the list of a combo box for an item that begins with the characters in a specified string. If a matching item is found, it is selected and copied to the edit control.

```
FUNCTION SelectString (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | The zero-based index of the item preceding the first item to be searched. When the search reaches the bottom of the list, it continues from the top of the list back to the item specified by the *index* parameter. If *index* is -1, the entire list is searched from the beginning. |
| *pwszText* | A pointer to the null-terminated string that contains the characters for which to search. The search is not case sensitive, so this string can contain any combination of uppercase and lowercase letters. |

#### Return value

If the string is found, the return value is the index of the selected item. If the search is unsuccessful, the return value is CB_ERR and the current selection is not changed.

#### Remarks

A string is selected only if the characters from the starting point match the characters in the prefix string.

If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, what the CB_SELECTSTRING message does depends on whether you use the CBS_SORT style. If the CBS_SORT style is used, the system sends WM_COMPAREITEM messages to the owner of the combo box to determine which item matches the specified string. If you do not use the CBS_SORT style, CB_SELECTSTRING attempts to match the DWORD value against the value of the *pwszText* parameter.

#### Usage example
```
CCombo.SelectString(hCombo, -1 , "Text to find")
```
---

### SetCueBannerText

Sets the cue banner text that is displayed for the edit control of a combo box.

```
FUNCTION SetCueBannerText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *pwszText* | A pointer to a null-terminated Unicode string buffer that contains the text. |

#### Return value

Returns 1 if successful, or an error value otherwise.

#### Remarks

The cue banner is text that is displayed in the edit control of a combo box when there is no selection.

#### Usage example
```
CCombo.SetCueBannerText(hCombo, "Cue banner text")
```
---

### SetCurSel

Selects a string in the list of a combo box. If necessary, the list scrolls the string into view. The text in the edit control of the combo box changes to reflect the new selection, and any previous selection in the list is removed.

```
FUNCTION SetCurSel (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | Specifies the zero-based index of the string to select. If this parameter is -1, any current selection in the list is removed and the edit control is cleared. |

#### Return value

If the message is successful, the return value is the index of the item selected. If *index* is greater than the number of items in the list or if wParam is -1, the return value is CB_ERR and the selection is cleared.

#### Usage example
```
CCombo.SeCurSel(hCombo, 10)
```
---

### SetDarkMode

Sets the control dark mode.

```
FUNCTION SetDarkMode (BYVAL hCombo AS HWND) AS HRESULT
FUNCTION SetDarkMode (BYVAL hComboEx AS HWND) AS HRESULT
```

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

#### Usage example
```
CCombo.SetDarkMode(hCombo)
CCombo.SetDarkMode(hComboEx)
```
---

### SetDroppedWidth

Sets the maximum allowable width, in pixels, of the list box of a combo box with the CBS_DROPDOWN or CBS_DROPDOWNLIST style.

```
FUNCTION SetDroppedWidth (BYVAL hCombo AS HWND, BYVAL nWidth AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *nWidth* | The minimum allowable width of the list box, in pixels. |

#### Return value

If the message is successful, The return value is the new width of the list box.

If the message fails, the return value is CB_ERR.

#### Usage example
```
CCombo.SetDroppedWidth(hCombo, 200)
```
---

### SetEditSel

Selects characters in the edit control of a combo box.

```
FUNCTION SetEditSel (BYVAL hCombo AS HWND, BYVAL nStart AS SHORT, BYVAL nEnd AS SHORT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *nStart* | The starting popsition. |
| *nEmd* | The endimg popsition. |

#### Return value

If the message succeeds, the return value is TRUE. If the message is sent to a combo box with the CBS_DROPDOWNLIST style, it is CB_ERR.

#### Remarks

The positions are zero-based. The first character of the edit control is in the zero position. The first character after the last selected character is in the ending position. For example, to select the first four characters of the edit control, use a starting position of 0 and an ending position of 4.

#### Usage example
```
CCombo.SetEditSel(hCombo, 10, 30)
```
---

### SetExtendedUI

Selects either the default user interface or the extended user interface for a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.

```
FUNCTION SetExtendedUI (BYVAL hCombo AS HWND, BYVAL flag AS BOOLEAN) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *flag* | A BOOL that specifies whether the combo box uses the extended UI (TRUE) or the default UI (FALSE). |

#### Return value

If the operation succeeds, the return value is CB_OKAY. If an error occurs, it is CB_ERR.

#### Remarks

By default, the F4 key opens or closes the list and the DOWN ARROW changes the current selection. In the extended UI, the F4 key is disabled and the DOWN ARROW key opens the drop-down list. The mouse wheel, which normally scrolls through the items in the list, has no effect when the extended UI is set.

#### Usage example
```
CCombo.SetExtendedUI(hCombo, TRUE)
```
---

### SetHorizontalExtent

Sets the width, in pixels, by which a list box can be scrolled horizontally (the scrollable width). If the width of the list box is smaller than this value, the horizontal scroll bar horizontally scrolls items in the list box. If the width of the list box is equal to or greater than this value, the horizontal scroll bar is hidden or, if the combo box has the CBS_DISABLENOSCROLL style, disabled.

```
FUNCTION SetHorizontalExtent (BYVAL hCombo AS HWND, BYVAL nWidth AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *nWidth* | Specifies the scrollable width of the list box, in pixels. |

#### Usage example
```
CCombo.SetHorizontalExtent(hCombo, 300)
```
---

### SetItemData

Sets the value associated with the specified item in a combo box.

```
FUNCTION SetItemData (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL nData AS LONG_PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | Specifies the item's zero-based index. |
| *nData* | Specifies the new value to be associated with the item. |

#### Usage example
```
CCombo.SetItemData(hCombo, 3, <data>)
```
---

### SetItemHeight

Sets the height of list items or the selection field in a combo box.

```
FUNCTION SetItemHeight (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL nHeight AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | Specifies the component of the combo box for which to set the height. This parameter must be 1 to set the height of the selection field. It must be zero to set the height of list items, unless the combo box has the CBS_OWNERDRAWVARIABLE style. In that case, the *index* parameter is the zero-based index of a specific list item. |
| *nHeight* | Specifies the height, in pixels, of the combo box component identified by *index*. |

#### Usage example
```
CCombo.SetItemHeight(hCombo, 1, 50)
```
---

### SetLocale

Sets the current locale of the combo box. If the combo box has the CBS_SORT style and strings are added using CB_ADDSTRING, the locale of a combo box affects how list items are sorted.  The return value is the previous locale identifier. If lcid specifies a locale not installed on the system, the return value is CB_ERR and the current combo box locale is not changed.

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *lcid* | Specifies the locale identifier for the combo box to use for sorting when adding text. |

#### Usage example
```
CCombo.SetLocale(hCombo, 1, <locale identifier>)
```

#### Return value

The return value is the previous locale identifier. If *lcid* specifies a locale not installed on the system, the return value is CB_ERR and the current combo box locale is not changed.

#### Remarks

Use the MAKELCID macro to construct a locale identifier and the MAKELANGID macro to construct a language identifier. The language identifier is made up of a primary language identifier and a sublanguage identifier.

#### Usage example
```
CCombo.SetLocale(hCombo, 1, <locale identifier>)
```
---

### SetMinVisible

Sets the minimum number of visible items in the drop-down list of a combo box.

```
FUNCTION SetMinVisible (BYVAL hCombo AS HWND, BYVAL iMinVisible AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *iMinVisible* | Specifies the minimum number of visible items. |

#### Return value

If the message is successful, the return value is TRUE. Otherwise the return value is FALSE.

#### Remarks

When the number of items in the drop-down list is greater than the minimum, the combo box uses a scroll bar. By default, 30 is the minimum number of visible items.

This message is ignored if the combo box control has style CBS_NOINTEGRALHEIGHT.

To use CB_SETMINVISIBLE, the application must specify comctl32.dll version 6 in the manifest.

#### Usage example
```
CCombo.SetMinVisible(hCombo, 20)
```
---

### SetText

Sets the text of a combobox control.

```
FUNCTION SetText (BYVAL hCombo AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
FUNCTION SetText (BYVAL hCombo AS HWND, BYVAL index AS LONG, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *pwszText* | A pointer to the null-terminated string to be inserted. If you create the combo box with an owner-drawn style but without the CBS_HASSTRINGS style, the value of the lParam parameter is stored rather than the string to which it would otherwise point. |
| *index* | The zero-based index of the item. |

#### Return value

If the message is successful, the return value is TRUE. Otherwise the return value is FALSE.

The overloaded function that accepts an index to a item returns the index of the position at which the string was inserted. If an error occurs, the return value is CB_ERR. 

#### Remarks

The overloaded function that accepts an index to a item does not replace the existing text, but deletes the existing string and inserts a new one.

#### Usage examples
```
CCombo.SetText(hCombo, "New text")
CCombo.SetText(hCombo, 5, "New text")
```
---

### SetTopIndex

Ensures that a particular item is visible in the list box of a combo box. The system scrolls the list box contents so that either the specified it. If the message is successful, the return value is zero. If the message fails, the return value is CB_ERR.

```
FUNCTION SetTopIndex (BYVAL hCombo AS HWND, BYVAL index AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hCombo* | The handle of the combo box control. |
| *index* | Specifies the zero-based index of the list item. |

#### Return value

If the message is successful, the return value is zero.

If the message fails, the return value is CB_ERR.

#### Usage example
```
CCombo.SetTopIndex(hCombo, 10)
```
---

### ShowDropDown

Shows the list box of a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.

```
SUB ShowDropDown (BYVAL hCombo AS HWND)
```

#### Usage example
```
CCombo.ShowDropDown(hCombo)
```
---

### UnselectString

Unselects any current selection.

```
FUNCTION UnselectString (BYVAL hCombo AS HWND) AS LONG
```

#### Usage example
```
CCombo.UnselectString(hCombo)
```
---

### DeleteItem

Removes an item from a ComboBoxEx control.

```
FUNCTION DeleteItem (BYVAL hComboEx AS HWND, BYVAL iIndex AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *iIndex* | The zero-based index of the item to be removed. |

#### Return value

Returns an value that represents the number of items remaining in the control. If *iIndex* is invalid, the message returns CB_ERR.

#### Usage example
```
CComboEx.DeleteItem(hComboEx, 4)
```
---

### GetComboControl

Gets the handle to the child combo box control.

```
FUNCTION GetComboControl (BYVAL hComboEx AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |

#### Return value

Returns the handle to the combo box control within the ComboBoxEx control.

#### Usage example
```
DIM hComboEx AS HWND = CComboEx.GetComboControl(hComboEx)
```
---

### GetEditControl

Gets the handle to the edit control portion of a ComboBoxEx control. A ComboBoxEx control uses an edit box when it is set to the CBS_DROPDOWN style.

```
FUNCTION GetEditControl (BYVAL hComboEx AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |

#### Return value

Returns the handle to the edit control within the ComboBoxEx control if it uses the CBS_DROPDOWN style. Otherwise, the message returns NULL.

#### Usage example
```
DIM hComboEx AS HWND = CComboEx.GetEditControl(hComboEx)
```
---

### GetExtendedStyle

Gets the extended styles that are in use for a ComboBoxEx control.

```
FUNCTION GetExtendedStyle (BYVAL hComboEx AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |

#### Return value

Returns a DWORD value that contains the ComboBoxEx control extended styles in use for the control.

#### Usage example
```
DIM dwStyle AS DWORD = CComboEx.GetExtendedStyle(hComboEx)
```
---

### GetImageList

Gets the handle to an image list assigned to a ComboBoxEx control.

```
FUNCTION GetImageList (BYVAL hComboEx AS HWND) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |

#### Return value

Returns the handle to the image list assigned to the control if successful, or NULL otherwise.

#### Usage example
```
DIM hIml AS HIMAGELIST = CComboEx.GetImageList(hComboEx)
```
---

### GetItem

Gets item information for a given ComboBoxEx item.

```
FUNCTION GetItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS BOOLEAN
FUNCTION GetItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS BOOLEAN
FUNCTION GetItem (BYVAL hComboEx AS HWND) AS COMBOBOXEXITEMW
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *pCBItem* | A pointer to a COMBOBOXEXITEM structure that receives the item information. |
| *CBItem* | A COMBOBOXEXITEM structure that receives the item information. |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Usage example
```
DIM cbi AS COMBOBOXEXITEM
CComboEx.GetItem(hComboEx, @cbi)
CComboEx.GetItem(hComboEx, cbi)
cbi = CComboEx.GetItem(hComboEx)
```
---

### HasEditChanged

Determines whether the user has changed the text of a ComboBoxEx edit control.

```
FUNCTION HasEditChanged (BYVAL hComboEx AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |

#### Return value

Returns TRUE if the text in the control's edit box has been changed, or FALSE otherwise.

#### Remarks

A ComboBoxEx control uses an edit box control when it is set to the CBS_DROPDOWN style. You can retrieve the edit box control's window handle by sending a CBEM_GETEDITCONTROL message.

When the user begins editing, you will receive a CBEN_BEGINEDIT notification. When editing is complete, or the focus changes, you will receive a CBEN_ENDEDIT notification. The CBEM_HASEDITCHANGED message is only useful for determining whether the text has been changed if it is sent before the CBEN_ENDEDIT notification. If the message is sent afterward, it will return FALSE. For example, suppose the user starts to edit the text in the edit box but changes focus, generating a CBEN_ENDEDIT notification. If you then send a CBEM_HASEDITCHANGED message, it will return FALSE, even though the text has been changed.

The CBS_SIMPLE style does not work correctly with CBEM_HASEDITCHANGED.

#### Usage example
```
DIM bChanged AS BOOLEAN = CComboEx.HasEditChanged(hComboEx)
```
---

### InsertItem

Inserts a new item in a ComboBoxEx control.

```
FUNCTION InsertItem (BYVAL hComboEx AS HWND, BYVAL pCBItem AS COMBOBOXEXITEMW PTR) AS LONG
FUNCTION InsertItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *pCBItem* | A pointer to a COMBOBOXEXITEM structure that contains information about the item to be inserted. When the message is sent, the iItem member must be set to indicate the zero-based index at which to insert the item. To insert an item at the end of the list, set the iItem member to -1. |
| *CBItem* | A COMBOBOXEXITEM structure that contains information about the item to be inserted. When the message is sent, the iItem member must be set to indicate the zero-based index at which to insert the item. To insert an item at the end of the list, set the iItem member to -1. |

#### Return value

Returns the index at which the new item was inserted if successful, or -1 otherwise.

---

### SetExtendedStyle

Sets extended styles within a ComboBoxEx control.

```
FUNCTION SetExtendedStyle (BYVAL hComboEx AS HWND, BYVAL dwExMask AS DWORD, BYVAL dwExStyle AS DWORD) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *dwExMask* | A DWORD value that indicates which styles in *dwExStyle* are to be affected. Only the extended styles in wParam will be changed. If this parameter is zero, then all of the styles in *dwExStyle* will be affected. |
| *dwExStyle* | A DWORD value that contains the ComboBoxEx Control Extended Styles to set for the control. |

#### Return value

Returns a DWORD value that contains the extended styles previously used for the control.

#### Remarks

*dwExStyle* enables you to modify one or more extended styles without having to retrieve the existing styles first. For example, if you pass CBES_EX_NOEDITIMAGE for *dwExMAsk* and 0 for *dwExStyle*, the CBES_EX_NOEDITIMAGE style will be cleared, but all other styles will remain the same.

If you try to set an extended style for a ComboBoxEx control created with the CBS_SIMPLE style, it may not repaint properly.

---

### SetImageList

Sets an image list for a ComboBoxEx control.

```
FUNCTION SetImageList (BYVAL hComboEx AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *himl* | A handle to the image list to be set for the control. |

#### Return value

Returns the handle to the image list previously associated with the control, or returns NULL if no image list was previously set.

#### Remarks

The height of images in your image list might change the size requirements of the ComboBoxEx control. It is recommended that you resize the control after sending this message to ensure that it is displayed properly.

#### Usage example
```
DIM hOldIml AS HIMAGELIST = CComboEx.SetImageList(hComboEx, <new image list handle>)
```
---

### SetItem

Sets the attributes for an item in a ComboBoxEx control.

```
FUNCTION SetItem (BYVAL hComboEx AS HWND, BYREF pCBItem AS COMBOBOXEXITEMW PTR) AS BOOLEAN
FUNCTION SetItem (BYVAL hComboEx AS HWND, BYREF CBItem AS COMBOBOXEXITEMW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *pCBItem* | A pointer to a COMBOBOXEXITEM structure that contains the item information to be set. When the message is sent, the mask member of the structure must be set to indicate which attributes are valid and the iItem member must specify the zero-based index of the item to be modified. Setting the iItem member to -1 will modify the item displayed in the edit control. |
| *CBItem* | A COMBOBOXEXITEM structure that contains the item information to be set. When the message is sent, the mask member of the structure must be set to indicate which attributes are valid and the iItem member must specify the zero-based index of the item to be modified. Setting the iItem member to -1 will modify the item displayed in the edit control. |

---

### SetWindowTheme

Sets the visual style of a ComboBoxEx control.

```
SUB SetWindowTheme (BYVAL hComboEx AS HWND, BYVAL pwszStyle AS WSTRING PTR)
```

| Parameter | Description |
| --------- | ----------- |
| *hComboEx* | The handle of the ComboBoxEx control. |
| *pwszStyle* | A pointer to a Unicode string that contains the control visual style to set. |

---
