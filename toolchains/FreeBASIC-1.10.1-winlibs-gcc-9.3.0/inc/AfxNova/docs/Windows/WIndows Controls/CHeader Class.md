# CHeader Class

A header control is a window that is usually positioned above columns of text or numbers. It contains a title for each column, and it can be divided into parts. The user can drag the dividers that separate the parts to set the width of each column.

See: https://learn.microsoft.com/en-us/windows/win32/controls/header-controls

**Include file**: CHeader.inc

| Name       | Description |
| ---------- | ----------- |
| [ClearAllFilters](#clearallfilters) | Clears all of the filters for a given header control. |
| [ClearFilter](#clearfilter) | Clears the filter for a given header control. |
| [CreateDragImage](#createdragimage) | Creates a transparent version of an item image within an existing header control. |
| [DeleteItem](#deleteitem) | Deletes an item from a header control. |
| [EditFilter](#editfilter) | Moves the input focus to the edit box when a filter button has the focus. |
| [GetBitmapMargin](#getbitmapmargin) | Gets the width of the margin (in pixels) of a bitmap in an existing header control. |
| [GetFocusedItem](#getfocuseditem) | Gets the item in a header control that has the focus. |
| [GetImageList](#getimagelist) | Gets the handle to the image list that has been set for an existing header control. |
| [GetItem](#getitem) | Gets information about an item in a header control. |
| [GetItemCount](#getitemcount) | Gets a count of the items in a header control. |
| [GetItemDropDownRect](#getitemdropdownrect) | Gets the coordinates of the drop-down button for a specfied item in a header control. The header control must be of type HDF_SPLITBUTTON. |
| [GetItemRect](#getitemrect) | Gets the bounding rectangle for a given item in a header control. |
| [GetItemOrder](#getitemorder) | Gets the order of the specified item of a header control. |
| [GetItemText](#getitemtext) | Gets the text of the specified column. |
| [GetItemWidth](#getitemwidth) | Gets the width of the specified item of a header control. |
| [GetOrderArray](#getordearray) | Gets the current left-to-right order of items in a header control. |
| [GetOverflowRect](#getoverflowrect) | Gets the coordinates of the drop-down overflow area for a specified header control. The header control must be of type HDF_SPLITBUTTON. |
| [GetStateImageList](#getstateimagelist) | Gets the handle to the image list that has been set for an existing header control state. |
| [GetText](#getitemtext) | Gets the text of the specified column. |
| [HitTest](#hittest) | Tests a point to determine which header item, if any, is at the specified point. |
| [InsertItem](#insertitem) | Inserts a new item into a header control. |
| [Layout](#layout) | Retrieves the correct size and position of a header control within the parent window. |
| [OrderToIndex](#ordertoindex) | Retrieves an index value for an item based on its order in the header control. |
| [SetBitmapMargin](#setbitmapmargin) | Sets the width of the margin for a bitmap in an existing header control. |
| [SetFilterChangeTimeout](#setfilterchangetimeout) | Sets the timeout interval between the time a change takes place in the filter attributes and the posting of an HDN_FILTERCHANGE notification. |
| [SetFocusedItem](#setfocuseditem) | Sets the focus to a specified item in a header control. |
| [SetHotDivider](#sethotdivider) | Changes the color of a divider between header items to indicate the destination of an external drag-and-drop operation. |
| [SetImageList](#setimagelist) | Assigns an image list to an existing header control. |
| [SetItem](#setitem) | Sets the attributes of the specified item in a header control. |
| [SetItemOrder](#setitemorder) | Sets the order of the specified item of a header control. |
| [SetItemText](#setitemtext) | Sets the text of the specified item. |
| [SetText](#setitemtext) | Sets the text of the specified item. |
| [SetItemWidth](#setitemwidth) | Sets the width of the specified item of a header control. |
| [SetOrderArray](#setorderarray) | Sets the left-to-right order of header items. |
| [SetStateImageList](#setstateimagelist) | Assigns an image list to an existing header control. |
| [SetDarkMode](#setdarkmode) | Set header dark mode. |
| [RemoveDarkMode](#removedarkmode) | Remove header dark mode. |

---

### ClearAllFilters

Clears all of the filters for a given header control.

```
FUNCTION ClearAllFilters (BYVAL hHeader AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

Returns TRUE or FALSE.

---

### ClearFilter

Clears the filter for a given header control. 

```
FUNCTION ClearFilter (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | A column value indicating which filter to clear. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

### Remarks

If the column value is specified as -1, all the filters are cleared, and the HDN_FILTERCHANGE notification is sent only once.

---

### CreateDragImage

Creates a semi-transparent version of an item's image for use as a dragging image.

```
FUNCTION CreateDragImage (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS HIMAGELIST
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The zero-based index of the item within the header control. The image assigned to this item is the basis for the transparent image. |

#### Return value

Returns a handle to an image list that contains the new image as its only element.

---

### DeleteItem

Deletes an item from a header control.

```
FUNCTION DeleteItem (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The zero-based index of the item to delete. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### EditFilter

Moves the input focus to the edit box when a filter button has the focus.

```
FUNCTION EditFilter (BYVAL hHeader AS HWND, BYVAL i AS LONG, BYVAL fDiscardChanges AS BOOLEAN) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | A value specifying the column to edit. |
| *fDiscardChanges* | A flag that specifies how to handle the user's editing changes. Use this flag to specify what to do if the user is in the process of editing the filter when the message is sent.<br>**TRUE**: Discard the changes made by the user.;<br>**FALSE**: Accept the changes made by the user. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetBitmapMargin

Gets the width of the margin (in pixels) of a bitmap in an existing header control.

```
FUNCTION GetBitmapMargin (BYVAL hHeader AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

Returns the width of the bitmap margin in pixels. If the bitmap margin was not previously specified, the default value of 3*GetSystemMetrics (CX_EDGE) is returned.

---

### GetFocusedItem

Gets the item in a header control that has the focus.

```
FUNCTION GetBitmapMargin (BYVAL hHeader AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

Returns the index of the item in focus.

---

### GetImageList

Gets the handle to the image list that has been set for an existing header control.

```
FUNCTION GetImageList (BYVAL hHeader AS HWND) AS HIMAGELIST
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

Returns the handle to the image list that is set for the header control.

---

### GetItem

Gets information about an item in a header control.

```
FUNCTION GetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS BOOLEAN
FUNCTION GetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS BOOLEAN
FUNCTION GetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD) AS HDITEMW
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The index of the item for which information is to be retrieved. |
| *phdi* | A pointer to an **HDITEM** structure. When the message is sent, the **mask** member indicates the type of information being requested. When the message returns, the other members receive the requested information. If the **mask** member specifies zero, the message returns **TRUE** but copies no information to the structure. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the **HDI_TEXT** flag is set in the mask member of the **HDITEM** structure, the control may change the **pszText** member of the structure to point to the new text instead of filling the buffer with the requested text. Applications should not assume that the text will always be placed in the requested buffer.

---

### GetItemCount

Gets a count of the items in a header control.

```
FUNCTION GetItemCount (BYVAL hHeader AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetItemDropDownRect

Gets the coordinates of the drop-down button for a specified item in a header control. The header control must be of type **HDF_SPLITBUTTON**.

```
FUNCTION GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetItemDropDownRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The zero-based index of the header control item for which to retrieve the bounding rectangle. |
| *prc* | A pointer to a **RECT** structure to receive the bounding rectangle information. The message sender is responsible for allocating this structure. The coordinates returned in the **RECT** structure are expressed as screen coordinates. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetItemRect

Gets the bounding rectangle for a given item in a header control.

```
FUNCTION GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The zero-based index of the header control item for which to retrieve the bounding rectangle. |
| *prc* | A pointer to a **RECT** structure that receives the bounding rectangle information. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetItemOrder

Gets the order of the specified item of a header control.

```
FUNCTION GetItemOrder (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The zero-based index of the header control item for which to retrieve the order. |

#### Return value

The order of the item.

---

### GetItemText

Gets the text of the specified column.

```
FUNCTION GetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, _
   BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS BOOLEAN
FUNCTION GetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS DWSTRING
FUNCTION GetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, _
   BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG = MAX_PATH + 1) AS BOOLEAN
FUNCTION GetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The zero-based index of the header control item for which to retrieve the text. |
| *pwszText* | A pointer to an item string. If the text is being retrieved from the control, this member must be initialized to point to a character buffer. If this member is set to **LPSTR_TEXTCALLBACK**, the control will request text information for this item by sending an **HDN_GETDISPINFO** notification code. Note that although the header control allows a string of any length to be stored as item text, only the first 260 characters are displayed. |
| *cchTextMax* |  Maximum number of characters to return. Both this value and the size of the buffer pointed by pwszText must be one character bigger that the wanted length of the text to return to make room for the null character terminator. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

The second overlodes method returns the retrieved text.

---

### GetItemWidth

Gets the width of the specified item of a header control.

```
FUNCTION GetItemWidth (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The zero-based index of the header control item for which to retrieve the width. |

#### Return value

The width of the item.

---

### GetOrderArray

Gets the current left-to-right order of items in a header control.

```
FUNCTION GetOrderArray (BYVAL hHeader AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iCount* | The number of integer elements that *lpiArray* can hold. This value must be equal to the number of items in the control (see **GetItemCount**). |
| *lpiArray* | A pointer to an array of integers that receive the index values for items in the header. |

#### Return value

Returns nonzero if successful, and the buffer at *lpiArray* receives the item number of each item in the header control in the order in which they appear from left to right. Returns zero otherwise.

## Remarks

The number of elements in *lpiArray* is specified in iCount and must be equal to the number of items in the control. For example, the following code fragment will reserve enough memory to hold the index values.

---

### GetOverflowRect

Gets the coordinates of the drop-down overflow area for a specified header control. The header control must be of type **HDF_SPLITBUTTON**.

```
FUNCTION GetOverflowRect (BYVAL hHeader AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetOverflowRect (BYVAL hHeader AS HWND, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetOverflowRect (BYVAL hHeader AS HWND) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *prc* | A pointer to a **RECT** structure to receive the bounding rectangle information.The message sender is responsible for allocating this structure. The coordinates returned in the **RECT** structure are expressed as screen coordinates. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetStateImageList

Gets the handle to the image list that has been set for an existing header control state.

```
FUNCTION GetStateImageList (BYVAL hHeader AS HWND) AS HIMAGELIST
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

Returns the handle to the image list that is set for the header control state.

---

### HitTest

Tests a point to determine which header item, if any, is at the specified point.

```
FUNCTION HitTest (BYVAL hHeader AS HWND, BYVAL phdhti AS HDHITTESTINFO PTR) AS LONG
FUNCTION HitTest (BYVAL hHeader AS HWND, BYREF hdhti AS HDHITTESTINFO) AS LONG
FUNCTION HitTest (BYVAL hHeader AS HWND) AS HDHITTESTINFO
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *phdhti* | A pointer to an **HDHITTESTINFO** structure that contains the position to test and receives information about the results of the test. |

#### Return value

Returns the index of the item at the specified position, if any, or -1 otherwise.

---

### InsertItem

Inserts a new item into a header control.

```
FUNCTION InsertItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS LONG
FUNCTION InsertItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The index of the item after which the new item is to be inserted. The new item is inserted at the end of the header control if i is greater than or equal to the number of items in the control. If i is zero, the new item is inserted at the beginning of the header control. |
| *phdi* | A pointer to an **HDITEMW** structure that contains information about the new item. |

#### Return value

Returns the index of the new item if successful, or -1 otherwise.

---

### Layout

Retrieves the correct size and position of a header control within the parent window.

```
FUNCTION Layout (BYVAL hHeader AS HWND, BYVAL phdl AS HDLAYOUT PTR) AS BOOLEAN
FUNCTION Layout (BYVAL hHeader AS HWND, BYREF hdl AS HDLAYOUT) AS BOOLEAN
FUNCTION Layout (BYVAL hHeader AS HWND) AS HDLAYOUT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *phdi* | A pointer to an **HDLAYOUT** structure. The prc member specifies the coordinates of a rectangle, and the pwpos member receives the size and position for the header control within the rectangle. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### OrderToIndex

Retrieves an index value for an item based on its order in the header control.

```
FUNCTION OrderToIndex (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The order that the item appears within the header control, from left to right. The index value of the item in the far left column would be 0, the next item to the right would be 1, and so on. |

#### Return value

Returns an int that specifies the index of the item. If i is invalid (negative or too large), the return equals i.

---

### SetBitmapMargin

Sets the width of the margin for a bitmap in an existing header control.

```
FUNCTION SetBitmapMargin (BYVAL hHeader AS HWND, BYVAL iWidth AS DWORD) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iWidth* | The width, specified in pixels, of the margin that surrounds a bitmap within an existing header control. |

#### Return value

Returns width of the bitmap margin in pixels. If the bitmap margin was not previously specified, the default value of 3*GetSystemMetrics (CX_EDGE) is returned.

---

### SetFilterChangeTimeout

Sets the timeout interval between the time a change takes place in the filter attributes and the posting of an **HDN_FILTERCHANGE** notification.

```
FUNCTION SetFilterChangeTimeout (BYVAL hHeader AS HWND, BYVAL i AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The timeout value, in milliseconds. |

#### Return value

Returns the index of the filter control being modified.

---

### SetFocusedItem

Sets the focus to a specified item in a header control.

```
FUNCTION SetFocusedItem (BYVAL hHeader AS HWND, BYVAL iItem AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The index of item. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetHotDivider

Changes the color of a divider between header items to indicate the destination of an external drag-and-drop operation.

```
FUNCTION SetHotDivider (BYVAL hHeader AS HWND, BYVAL fPos AS BOOLEAN, BYVAL dwInputValue AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *fPos* | A value specifying how dw is to be interpreted. The value in this field can be one of the following:<br>**TRUE**: Indicates that dw holds client coordinates of the pointer.<br>**FALSE**: Indicates that dw holds a divider index value. |
| *dwInputValue* | The value held here is interpreted depending on the value of *fPos*. If *fPos* is TRUE, dw represents the x- and y- client coordinates of the pointer. The x-coordinate is in the low word, and the y-coordinate is in the high word. Upon receiving the message, the header control highlights the appropriate divider based on the dw coordinates. If *fPos* is **FALSE**, *dwInputValue* represents the integer index of the divider that will be highlighted. |

##### Return value

Returns the index of the divider that the control highlighted.

#### Remarks

A header control set to the **HDS_DRAGDROP** style produces this effect automatically. This message is intended to be used when the owner of the control handles drag-and-drop operations manually.

---

### SetImageList

Assigns an image list to an existing header control.

```
FUNCTION SetImageList (BYVAL hHeader AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *himl* | A handle to an image list. |

#### Return value

Returns the handle to the image list previously assigned to the header control, or **NULL** if there is no previous image list.

---

### SetItem

Sets the attributes of the specified item in a header control. 

```
FUNCTION SetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYVAL phdi AS HDITEMW PTR) AS LONG
FUNCTION SetItem (BYVAL hHeader AS HWND, BYVAL i AS DWORD, BYREF hdi AS HDITEMW) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *i* | The index of the item whose attributes are to be changed. |
| *phdi* | A pointer to an **HDITEM** structure that contains item information. When this message is sent, the **mask** member of the structure must be set to indicate which attributes are being set |

#### Return value

Returns nonzero upon success, or zero otherwise.

---

### SetItemOrder

Sets the order of the specified item of a header control.

```
FUNCTION SetItemOrder (BYVAL hHeader AS HWND, BYVAL nItem AS LONG, BYVAL iOrder AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The index of the item whose attributes are to be changed. |
| *iOrder* | The order in which the item appears within the header control, from left to right. That is, the value for the far left item is 0. The value for the next item to the right is 1, and so on. |


#### Return value

Returns TRUE upon success, or FALSE otherwise.

---

### SetItemText

Sets the text of the specified item.

```
FUNCTION SetItemText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
FUNCTION SetText (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The index of the item whose text will be changed. |
| *pwszText* | The text to set. |


#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetItemWidth

Sets the width of the specified item of a header control.

```
FUNCTION SetItemWidth (BYVAL hHeader AS HWND, BYVAL iItem AS LONG, BYVAL nWidth AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iItem* | The index of the item whose width will be changed. |
| *nWidth* | The new width of the item. |


#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetOrderArray

Sets the left-to-right order of header items.

```
FUNCTION SetOrderArray (BYVAL hHeader AS HWND, BYVAL iCount AS LONG, BYVAL lpiArray AS LONG PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *iCount* | The size of the buffer at lpiArray, in elements. This value must equal the value returned by **GetItemCount**. |
| *lpiArray* | A pointer to an array that specifies the order in which items should be displayed, from left to right. For example, if the contents of the array are {2,0,1}, the control displays item 2, item 0, and item 1, from left to right. |


#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetStateImageList

Assigns an image list to an existing header control state.

```
FUNCTION SetStateImageList (BYVAL hHeader AS HWND, BYVAL himl AS HIMAGELIST) AS HIMAGELIST
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |
| *himl* | A handle to an image list control. |

#### Return value

Returns the handle to the image list previously assigned to the header control state, or NULL if there is no previous image list.

---

### SetDarkMode

Sets the header dark mode.

```
FUNCTION SetDarkMode (BYVAL hHeader AS HWND) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

### RemoveDarkMode

Removes the header dark mode.

```
FUNCTION RemoveDarkMode (BYVAL hHeader AS HWND) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hHeader* | The handle of the header control. |

#### Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

### Example

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CHeader.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_HEADER = 1001

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Header control", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Add the header control.
   DIM hHeader AS HWND = pWindow.AddControl("Header", hWin, IDC_HEADER)
   ' // Insert items
   DIM thdi AS HDITEMW
   DIM wszItem AS WSTRING * 260
   wszItem   = "Item 1"
   thdi.Mask = HDI_WIDTH OR HDI_FORMAT OR HDI_TEXT
   thdi.fmt  = HDF_LEFT OR HDF_STRING
   thdi.cxy  = pWindow.ScaleX(80)
   thdi.pszText  = @wszItem
   thdi.cchTextMax = LEN(wszItem)
   CHeader.InsertItem(hHeader, 1, @thdi)
   wszItem   = "Item 2"
   CHeader.InsertItem(hHeader, 2, @thdi)
   wszItem   = "Item 3"
   CHeader.InsertItem(hHeader, 3, @thdi)
   wszItem   = "Item 4"
   CHeader.InsertItem(hHeader, 4, @thdi)
   wszItem   = "Item 5"
   CHeader.InsertItem(hHeader, 5, @thdi)

   ' // Adds a button
   DIM hButton AS HWND = pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(hButton, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         ' // Retrieve the header item clicked
         DIM hd AS NMHEADERW
         CBNMTYPESET(hd, wParam, lParam)
         IF hd.hdr.idFrom = IDC_HEADER THEN
            SELECT CASE hd.hdr.code
               CASE HDN_ITEMCLICKW
                  MessageBox hwnd, "You have clicked item " & WSTR(hd.iItem + 1), "Message", MB_OK
            END SELECT
         END IF

      CASE WM_SIZE
         ' // Resize the header control
         DIM hHeader AS HWND = GetDLgItem(hwnd, IDC_HEADER)
         DIM thdl AS HDLAYOUT, twp AS WINDOWPOS, trc AS RECT
         GetClientRect hwnd, @trc
         thdl.prc = @trc
         thdl.pwpos = @twp
         CHeader.Layout(hHeader, @thdl)
         SetWindowPos hHeader, NULL, twp.x, twp.y, twp.cx, twp.cy, SWP_NOZORDER OR SWP_NOACTIVATE
         RETURN 0

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

### Example: Dark mode

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CHeader.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_HEADER = 1001

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Header control", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center
   ' // Set the back color of the window
   pWindow.SetBackColor(RGB_BLACK)

   ' // Add the header control.
   DIM hHeader AS HWND = pWindow.AddControl("Header", hWin, IDC_HEADER)
   ' // Use dark mode theme
   SetWindowTheme(hHeader, "DarkMode_ItemsView", NULL)

   ' // Insert items
   DIM thdi AS HDITEMW
   DIM wszItem AS WSTRING * 260
   wszItem   = "Item 1"
   thdi.Mask = HDI_WIDTH OR HDI_FORMAT OR HDI_TEXT
   thdi.fmt  = HDF_LEFT OR HDF_STRING
   thdi.cxy  = pWindow.ScaleX(80)
   thdi.pszText  = @wszItem
   CHeader.InsertItem(hHeader, 1, @thdi)
   wszItem   = "Item 2"
   CHeader.InsertItem(hHeader, 2, @thdi)
   wszItem   = "Item 3"
   CHeader.InsertItem(hHeader, 3, @thdi)
   wszItem   = "Item 4"
   CHeader.InsertItem(hHeader, 4, @thdi)
   wszItem   = "Item 5"
   CHeader.InsertItem(hHeader, 5, @thdi)

   ' // Adds a button
   DIM hButton AS HWND = pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Set button dark mode
   SetWindowTheme(hButton, "DarkMode_Explorer", NULL)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_NOTIFY
         ' // Retrieve the header item clicked
         DIM hd AS NMHEADERW
         CBNMTYPESET(hd, wParam, lParam)
         IF hd.hdr.idFrom = IDC_HEADER THEN
            SELECT CASE hd.hdr.code
               CASE HDN_ITEMCLICKW
                  MessageBox hwnd, "You have clicked item " & WSTR(hd.iItem + 1), "Message", MB_OK
            END SELECT
         END IF

         ' // Change the colors of the header control
         DIM nmh AS NMHDR
         CBNMTYPESET(nmh, wParam, lParam)
         IF nmh.idFrom = IDC_HEADER THEN
            IF nmh.code = NM_CUSTOMDRAW THEN
               DIM nmcd AS NMCUSTOMDRAW
               CBNMTYPESET(nmcd, wParam, lParam)
               ' // Check the drawing stage
               SELECT CASE nmcd.dwDrawStage
                  ' // Prior to painting
                  CASE CDDS_PREPAINT
                     ' // Tell Windows we want individual notification of each item being drawn
                     RETURN CDRF_NOTIFYITEMDRAW
                     ' // Notification of each item being drawn
                  CASE CDDS_ITEMPREPAINT
                     ' // Set text color of the header
                     SetTextColor(nmcd.hdc, RGB_WHITE)
                     SetBkMode(nmcd.hdc, TRANSPARENT)
                     RETURN CDRF_DODEFAULT
               END SELECT
            END IF
         END IF

      CASE WM_SIZE
         ' // Resize the header control
         DIM hHeader AS HWND = GetDLgItem(hwnd, IDC_HEADER)
         DIM thdl AS HDLAYOUT, twp AS WINDOWPOS, trc AS RECT
         GetClientRect hwnd, @trc
         thdl.prc = @trc
         thdl.pwpos = @twp
         CHeader.Layout(hHeader, @thdl)
         SetWindowPos hHeader, NULL, twp.x, twp.y, twp.cx, twp.cy, SWP_NOZORDER OR SWP_NOACTIVATE
         RETURN 0

      CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```
---
