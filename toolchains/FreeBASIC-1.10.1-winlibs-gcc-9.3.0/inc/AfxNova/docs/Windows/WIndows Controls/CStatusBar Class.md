# CStatusBar Class

A *status bar* is a horizontal window at the bottom of a parent window in which an application can display various kinds of status information. The status bar can be divided into parts to display more than one type of information.

See: [Status Bars](https://learn.microsoft.com/en-us/windows/win32/controls/status-bars)

**Include file**: CStatusBar.inc

| Name       | Description |
| ---------- | ----------- |
| [GetBorders](#getborders) | Retrieves the current widths of the horizontal, and vertical borders of a status window, and the width of the border between rectangles. |
| [GetHeight](#getheight) | Returns the height of the status bar. |
| [GetIcon](#geticon) | Retrieves the icon for a part in a status bar. |
| [GetParts](#getparts) | Retrieves a count of the parts in a status window and the coordinate of the right edge of the specified number of parts. |
| [GetPartsCount](#getpartscount) | Retrieves a count of the parts in a status window. |
| [GetRect](#getrect) | Retrieves the bounding rectangle of a part in a status window. |
| [GetText](#gettext) | Retrieves the text from the specified part of a status window. |
| [GetTextDrawingMode](#gettextdrawingmode) | Retrieves the type of operation used to draw the text. |
| [GetTextLength](#gettextlength) | Retrieves the length, in characters, of the text from the specified part of a status window. |
| [GetTipText](#gettiptext) | Retrieves the tooltip text for a part in a status bar. |
| [IsSimple](#issimple) | Checks a status bar control to determine if it is in simple mode. |
| [SetBkColor](#setbkcolor) | Sets the background color in a status bar. |
| [SetFont](#setfont) | Sets the font that the status bar is to use when drawing text. |
| [SetIcon](#seticon) | Sets the icon for a part in a status bar. |
| [SetMinHeight](#setminheight) | Sets the minimum length, in pixels, of a status window's drawing area. |
| [SetParts](#setparts) | Sets the number of parts in a status window and the coordinate of the right edge of each part. |
| [SetText](#settext) | Sets the text in the specified part of a status window. |
| [SetTipText](#settiptext) | Sets the tooltip text for a part in a status bar. |
| [Simple](#simple) | Specifies whether a status window displays simple text or displays all window parts set by a previous SB_SETPARTS message. |

---

### GetBorders

Retrieves the current widths of the horizontal, and vertical borders of a status window, and the width of the border between rectangles.

```
FUNCTION GetBorders (BYVAL hStatusBar AS HWND, BYVAL rgBorders AS LONG PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *rgBorders* | Pointer to an integer array that has three elements. The first element receives the width of the horizontal border, the second receives the width of the vertical border, and the third receives the width of the border between rectangles. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The borders determine the spacing between the outside edge of the window and the rectangles within the window that contain text. The borders also determine the spacing between rectangles.

---

### GetHeight

Returns the height of the status bar.

```
FUNCTION GetHeight (BYVAL hStatusBar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |

---

### GetIcon

Retrieves the icon for a part in a status bar.

```
FUNCTION GetIcon (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS HICON
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part that contains the icon to be retrieved. If this parameter is -1, the status bar is assumed to be a Simple Mode status bar. |

#### Return value

Returns the handle to the icon if successful, or NULL otherwise.

---

### GetParts

Retrieves a count of the parts in a status window. The message also retrieves the coordinate of the right edge of the specified number of parts.

```
FUNCTION GetParts (BYVAL hStatusBar AS HWND, BYVAL nParts AS DWORD, BYVAL rgRightCoords AS LONG PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nParts* | Number of parts for which to retrieve coordinates. If this parameter is greater than the number of parts in the window, the message retrieves coordinates for existing parts only. |
| *rgRightCoords* | Pointer to an integer array that has the same number of elements as parts specified by wParam. Each element in the array receives the client coordinate of the right edge of the corresponding part. If an element is set to -1, the position of the right edge for that part extends to the right edge of the window. To retrieve the current number of parts, set this parameter to zero. |

#### Return value

Returns the number of parts in the status bar..

---

### GetPartsCount

Retrieves a count of the parts in a status window.

```
FUNCTION GetPartsCount (BYVAL hStatusBar AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |

---

### GetRect

Retrieves the bounding rectangle of a part in a status window.

```
FUNCTION GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYVAL lprc AS RECT PTR) AS LONG
FUNCTION GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYREF rc AS RECT) AS LONG
FUNCTION GetRect (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part whose bounding rectangle is to be retrieved. |
| *lprc* | Pointer to a **RECT** structure that receives the bounding rectangle. |
| *rc* | A **RECT** structure that receives the bounding rectangle. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetText

Retrieves the text from the specified part of a status window.

```
FUNCTION GetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD, BYVAL pwszText AS WSTRING PTR) AS DWORD
FUNCTION GetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part from which to retrieve text. |
| *pwszText* | Pointer to the buffer that receives the text as a null-terminated string. Use the SB_GETTEXTLENGTH message to determine the required size of the buffer. |

#### Remarks

**First overloaded method**: Returns a 32-bit value that consists of two 16-bit values. The low word specifies the length, in characters, of the text. The high word specifies the type of operation used to draw the text. The type can be one of the following values.

| Return code | Description |
| ----------- | ----------- |
| **0** | The text is drawn with a border to appear lower than the plane of the window. |
| **SBT_NOBORDERS** | The text is drawn without borders. |
| **SBT_POPOUT** | The text is drawn with a border to appear higher than the plane of the window. |
| **SBT_RTLREADING** | The text displays in the opposite direction of the text in the parent window. |

This message returns a maximum of 65,535 characters. If the text string is longer than that, it is truncated. If the text has the **SBT_OWNERDRAW** drawing type, this message returns the 32-bit value associated with the text instead of the length and operation type. Normal windows display text left-to-right (LTR). Windows can be *mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). If **SBT_RTLREADING** is set, the *pwszText* string reads in the opposite direction from the text in the parent window.
 
**Second overloaded method**: Returns the text of the specified part.

---

### GetTextDrawingMode

Retrieves the type of operation used to draw the text.

```
FUNCTION GetTextDrawingMode (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part from which to retrieve text. |

#### Return value

he type can be one of the following values.

| Return code | Description |
| ----------- | ----------- |
| **0** | The text is drawn with a border to appear lower than the plane of the window. |
| **SBT_NOBORDERS** | The text is drawn without borders. |
| **SBT_POPOUT** | The text is drawn with a border to appear higher than the plane of the window. |
| **SBT_RTLREADING** | The text displays in the opposite direction of the text in the parent window. |

---

### GetTextLength

Retrieves the length, in characters, of the text from the specified part of a status window.

```
FUNCTION GetTextLength (BYVAL hStatusBar AS HWND, BYVAL nPart AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part from which to retrieve text. |

---

### GetTipText

Retrieves the tooltip text for a part in a status bar. The status bar must be created with the **SBT_TOOLTIPS** style to enable tooltips.

```
FUNCTION GetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS WORD, BYVAL pwszText AS WSTRING PTR, BYVAL wLen AS WORD)
FUNCTION GetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS WORD) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part that receives the tooltip text. |
| *pwszText* | Pointer to a character buffer that receives the tooltip text. |
| *wLen* | The size of the buffer at *pwszText*, in characters. |

Using this message incorrectly can cause problems for your application. For example, if the text is too large for the *pwszText* buffer, it could cause a buffer overflow.

The second overloaded method uses a buffer of 65,535 characters, which is the maximum length that **SB_GETTIPTEXTW** can return, avoiding a possible buffer overrun.

---

### IsSimple

Checks a status bar control to determine if it is in simple mode.

```
FUNCTION IsSimple (BYVAL hStatusBar AS HWND) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |

#### Return value

Returns TRUE if the status bar control is in simple mode, or FALSE otherwise.

---

### SetBkColor

Sets the background color in a status bar.

```
FUNCTION SetBkColor (BYVAL hStatusBar AS HWND, BYVAL clrBk AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *clrBk* | **COLORREF** value that specifies the new background color. Specify the CLR_DEFAULT value to cause the status bar to use its default background color. |

#### Return value

Returns the previous background color, or CLR_DEFAULT if the background color is the default color.

---

### SetFont

Sets the font that the status bar is to use when drawing text.

```
SUB SetFont (BYVAL hStatusBar AS HWND, BYVAL hFont AS HFONT, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *hFont* | Sets the font that the status bar is to use when drawing text. |
| *fRedraw* | Specifies whether the control should be redrawn immediately upon setting the font. If this parameter is TRUE, the control redraws itself. |

#### Return value

Returns the previous background color, or CLR_DEFAULT if the background color is the default color.

---

### SetIcon

Sets the icon for a part in a status bar.

```
FUNCTION SetIcon (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL hIcon AS HICON) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part that will receive the icon. If this parameter is -1, the status bar is assumed to be a simple status bar. |
| *hIcon* | Handle to the icon to be set. If this value is NULL, the icon is removed from the part. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The status bar will not destroy the icon. It is the calling application's responsibility to keep track of and destroy any icons.

---

### SetMinHeight

Sets the minimum height of a status window's drawing area.

```
SUB SetMinHeight (BYVAL hStatusBar AS HWND, BYVAL minHeight AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *minHeight* | Minimum height, in pixels, of the window. |

#### Remarks

The minimum height is the sum of wParam and twice the width, in pixels, of the vertical border of the status window. An application must send the **WM_SIZE** message to the status window to redraw the window. The *wParam* and *lParam* parameters of the **WM_SIZE** message should be set to zero.

---

### SetParts

Sets the number of parts in a status window and the coordinate of the right edge of each part.

```
FUNCTION SetParts (BYVAL hStatusBar AS HWND, BYVAL dwParts AS DWORD, BYVAL rgWidths AS LONG PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *dwParts* | Number of parts to set (cannot be greater than 256). |
| *rgWidths* | Pointer to an integer array. The number of elements is specified in *dwParts*. Each element specifies the position, in client coordinates, of the right edge of the corresponding part. If an element is -1, the right edge of the corresponding part extends to the border of the window. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetText

Sets the text in the specified part of a status window.

```
FUNCTION SetText (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL pwszText AS WSTRING PTR, _
   BYVAL uType AS DWORD = 0) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | The zero-based index of the part to set. If it is set to **SB_SIMPLEID**, the status window is assumed to be a simple mode status bar; that is, a status bar with only one part. |
| *pwszText* | Pointer to a null-terminated string that specifies the text to set. If *nPart* is **SBT_OWNERDRAW**, this parameter represents 32 bits of data. The parent window must interpret the data and draw the text when it receives the **WM_DRAWITEM** message. |
| *uType* | The  type of the drawing operation. This parameter can be one of the following values. |

| Return code | Description |
| ----------- | ----------- |
| **0** | The text is drawn with a border to appear lower than the plane of the window. |
| **SBT_NOBORDERS** | The text is drawn without borders. |
| **SBT_OWNERDRAW** | The text is drawn by the parent window. A simple mode status bar does not support owner drawing. |
| **SBT_POPOUT** | The text is drawn with a border to appear higher than the plane of the window. |
| **SBT_RTLREADING** | The text displays in the opposite direction of the text in the parent window. |
| **SBT_NOTABPARSING** | Tab characters are ignored. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The message invalidates the portion of the window that has changed, causing it to display the new text when the window next receives the WM_PAINT message.

Normal windows display text left-to-right (LTR). Windows can be mirrored to display languages such as Hebrew or Arabic that read right-to-left (RTL). If **SBT_RTLREADING** is set, the *pwszText* string will read in the opposite direction from the text in the parent window.

---

### SetTipText

Sets the tooltip text for a part in a status bar. The status bar must have been created with the **SBT_TOOLTIPS** style to enable tooltips.

```
SUB SetTipText (BYVAL hStatusBar AS HWND, BYVAL nPart AS LONG, BYVAL pwszTipText AS WSTRING PTR)
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *nPart* | Zero-based index of the part that will receive the tooltip text. |
| *pwszTipText* | Pointer to a character buffer that contains the new tooltip text. |

#### Remarks

This tooltip text is displayed in two situations:

* When the corresponding pane in the status bar contains only an icon.
* When the corresponding pane in the status bar contains text that is truncated due to the size of the pane.

---

### Simple

Specifies whether a status window displays simple text or displays all window parts set by a previous **SB_SETPARTS** message.

```
SUB Simple (BYVAL hStatusBar AS HWND, BYVAL fSimple AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *hStatusBar* | The handle of the status bar control. |
| *fSimple* | Display type flag. If this parameter is TRUE, the window displays simple text. If it is FALSE, it displays multiple parts. |

#### Remarks

If the status window is being changed from nonsimple to simple, or vice versa, the window is immediately redrawn.

---
