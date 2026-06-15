# CPager Class

A pager control is a window container that is used with a window that does not have enough display area to show all of its content. The pager control allows the user to scroll to the area of the window that is not currently in view.

See: [About Pager Controls](https://learn.microsoft.com/en-us/windows/win32/controls/pager-controls)

**Include file**: CPager.inc

| Name       | Description |
| ---------- | ----------- |
| [ForwardMouse](#forwardmouse) | Enables or disables mouse forwarding for the pager control. |
| [GetBkColor](#getbkcolor) | Retrieves the current background color for the pager control. |
| [GetBorder](#getborder) | Retrieves the current border size for the pager control. |
| [GetButtonSize](#getbuttonsize) | Retrieves the current button size for the pager control. |
| [GetButtonState](#getbuttonstate) | Retrieves the state of the specified button in a pager control. |
| [GetDropTarget](#getdroptarget) | Retrieves a pager control's IDropTarget interface pointer. |
| [GetPos](#getpos) | Retrieves the current scroll position of the pager control. |
| [RecalcSize](#recalcsize) | Forces the pager control to recalculate the size of the contained window. |
| [SetBkColor](#setbkcolor) | Sets the current background color for the pager control. |
| [SetBorder](#setborder) | Sets the current border size for the pager control. |
| [SetButtonSize](#setbuttonsize) | Sets the current button size for the pager control. |
| [SetChild](#setchild) | Sets the contained window for the pager control. |
| [SetPos](#setpos) | Sets the scroll position for the pager control.  |

---

### ForwardMouse

Enables or disables mouse forwarding for the pager control. When mouse forwarding is enabled, the pager control forwards **WM_MOUSEMOVE** messages to the contained window. 

```
SUB ForwardMouse (BYVAL hPager AS HWND, BYVAL bForward AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *bForward* | BOOL value that determines if mouse forwarding is enabled or disabled. If this value is nonzero, mouse forwarding is enabled. If this value is zero, mouse forwarding is disabled. |

#### Usage example

```
CPager.ForwardMouse(hPager, TRUE)
```
---

### GetBkColor

Retrieves the current background color for the pager control.

```
FUNCTION GetBkColor (BYVAL hPager AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *bForward* | BOOL value that determines if mouse forwarding is enabled or disabled. If this value is nonzero, mouse forwarding is enabled. If this value is zero, mouse forwarding is disabled. |

#### Return value

Returns the current background color.

#### Remarks

By default, the pager control will use the system button face color as the background color. This is the same color that can be retrieved by calling GetSysColorBrush with **COLOR_BTNFACE**.

#### Usage example

```
DIM bkColor AS COLORREF = CPager.GetBkColor(hPager)
```
---

### GetBorder

Retrieves the current border size for the pager control. 

```
FUNCTION GetBorder (BYVAL hPager AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |

#### Return value

Returns the current border size, in pixels.

#### Usage example

```
DIM nSize AS LONG = CPager.GetBorder(hPager)
```
---

### GetButtonSize

Retrieves the current button size for the pager control.

```
FUNCTION GetButtonSize (BYVAL hPager AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |

#### Return value

Returns the current button size, in pixels.

#### Usage example

```
DIM nSize AS LONG = CPager.GetButtonSize(hPager)
```
---

### GetButtonState

Retrieves the state of the specified button in a pager control.

```
FUNCTION GetButtonState (BYVAL hPager AS HWND, BYVAL iButton AS LONG) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *iButton* | Indicates which button to retrieve the state for. |

** iButton state values **

| Value | Meaning |
| ----- | ------- |
| **PGB_TOPORLEFT** | Indicates the top button in a **PGS_VERT** pager control or the left button in a **PGS_HORZ** pager control. |
| **PGB_BOTTOMORRIGHT** | Indicates the bottom button in a **PGS_VERT** pager control or the right button in a **PGS_HORZ** pager control. |

#### Return value

Returns the state of the button specified in lParam. This will be one or more of the following values (if more than one value is returned they will be combined using a bitwise OR):

| Return code | Description |
| ----------- | ----------- |
| **PGF_INVISIBLE** | The button is not visible. |
| **PGF_NORMAL** | The button is in normal state. |
| **PGF_NORMAL** | The button is in normal state. |
| **PGF_GRAYED** | The button is in grayed state. |
| **PGF_DEPRESSED** | The button is in pressed state. |
| **PGF_HOT** | The button is in hot state. |

#### Usage example

```
DIM state AS LONG = CPager.GetButtonState(hPager, PGB_TOPORLEFT)
```
---

### GetDropTarget

Retrieves a pager control's **IDropTarget** interface pointer.

```
FUNCTION GetDropTarget (BYVAL hPager AS HWND, BYVAL ppdt AS IDropTarget PTR PTR)
FUNCTION GetDropTarget (GetDropTarget (BYVAL hPager AS HWND) AS IDropTarget PTR
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *ppdt* | Pointer to an IDropTarget pointer that receives the interface pointer. It is the caller's responsibility to call Release on this pointer when it is no longer needed. |

#### Return value

Returns the pager control's **IDropTarget** interface pointer.

#### Usage examples

```
DIM pdt AS IDropTarget PTR
CPager.GetDropTarget(hPager, @pdt))
pdt = CPager.GetDropTarget(hPager)
```
---

### GetPos

Retrieves the current scroll position of the pager control.

```
FUNCTION GetPos (BYVAL hPager AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |

#### Return value

Returns the current scroll position, in pixels.

#### Usage example

```
DIM pos AS LOG = CPager.GetPos(hPager)
```
---

### RecalcSize

Forces the pager control to recalculate the size of the contained window. Using this macro will result in a **PGN_CALCSIZE** notification being sent.

```
SUB RecalcSize (BYVAL hPager AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |

#### Usage example

```
CPager.RecalcSize(hPager)
```
---

### SetBkColor

Sets the current background color for the pager control.

```
FUNCTION SetBkColor (BYVAL hPager AS HWND, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *clr* | **COLORREF** value that contains the new background color of the pager control. |

#### Return value

Returns a **COLORREF** value that contains the previous background color.

#### Usage example

```
CPager.SetBkColor(hPager, RGB_BLUE)
```

#### Remarks

By default, the pager control will use the system button face color as the background color. This is the same color that can be retrieved by calling GetSysColorBrush with **COLOR_BTNFACE**.

---

### SetBorder

Sets the current border size for the pager control. 

```
FUNCTION SetBorder (BYVAL hPager AS HWND, BYVAL iBorder AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *iBorder* | New size of the border, in pixels. This value should not be larger than the pager button or less than zero. If iBorder is too large, the border will be drawn the same size as the button. If *iBorder* is negative, the border size will be set to zero. |

#### Return value

Returns the previous border size, in pixels.

#### Usage example

```
CPager.SetBorder(hPager, 2)
```
---

### SetButtonSize

Sets the current button size for the pager control.

```
FUNCTION SetButtonSize (BYVAL hPager AS HWND, BYVAL iSize AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *iSize* | The new button size, in pixels. |

#### Return value

Returns the previous button size, in pixels.

#### Usage example

```
DIM nSize AS LONG = CPager.SetButtonSize(hPager, 25)
```

#### Remarks

If the pager control has the **PGS_HORZ** style, the button size determines the width of the pager buttons. If the pager control has the **PGS_VERT** style, the button size determines the height of the pager buttons. By default, the pager control sets its button size to three-fourths of the width of the scroll bar.

---

### SetChild

Sets the contained window for the pager control. This macro will not change the parent of the contained window; it only assigns a window handle to the pager control for scrolling. In most cases, the contained window will be a child window. If this is the case, the contained window should be a child of the pager control.

```
SUB SetChild (BYVAL hPager AS HWND, BYVAL hwndChild AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *hwndChild* | Handle to the window to be contained. |

#### Return value

Returns the previous button size, in pixels.

#### Usage example

```
DIM nSize AS LONG = CPager.SetButtonSize(hPager, 25)
```
---

### SetPos

Sets the scroll position for the pager control. 

```
FUNCTION SetPos (BYVAL hPager AS HWND, BYVAL iPos AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hPager* | Handle to the pager control. |
| *iPos* | The new scroll position, in pixels. |

#### Usage example

```
CPager.SetPos(hPager, 20)
```
---
