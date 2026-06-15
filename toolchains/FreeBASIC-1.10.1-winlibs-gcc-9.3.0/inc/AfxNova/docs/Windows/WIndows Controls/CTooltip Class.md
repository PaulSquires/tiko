# CTooltip Class

Tooltips appear automatically, or pop up, when the user pauses the mouse pointer over a tool or some other UI element. The tooltip appears near the pointer and disappears when the user clicks a mouse button, moves the pointer away from the tool, or simply waits for a few seconds.

See: [About Tooltip Controls](https://learn.microsoft.com/en-us/windows/win32/controls/tooltip-controls)

**Include file**: CTooltip.inc

| Name       | Description |
| ---------- | ----------- |
| [Activate](#activate) | Activates a Tooltip control. |
| [AddTool](#addtool) | Registers a tool with a Tooltip control. |
| [AddTooltip](#addtooltip) | Creates a Tooltip for a control. |
| [AdjustRect](#adjustrect) | Calculates a Tooltip control's text display rectangle from its window rectangle, or the tooltip window rectangle needed to display a specified text display rectangle. |
| [DeActivate](#activate) | Deactivates a Tooltip control. |
| [DelTool](#deltool) | Removes a tool from a Tooltip control. |
| [DeleteTooltip](#deletetooltip) | Removes a tool from a Tooltip control. |
| [EnumTools](#enumtools) | Retrieves the information that a Tooltip control maintains about the current tool--that is, the tool for which the Tooltip is currently displaying text. |
| [GetBubbleSize](#getbubblesize) | Returns the width and height of a Tooltip control. |
| [GetCurrentTool](#getcurrenttool) | Retrieves the information for the current tool in a Tooltip control. |
| [GetDelayTime](#getdelaytime) | Retrieves the information for the current tool in a Tooltip control. |
| [GetMargin](#getmargin) | Retrieves the top, left, bottom, and right margins set for a Tooltip window. |
| [GetMaxTipWidth](#getmaxtipwidth) | Retrieves the maximum width for a Tooltip window. |
| [GetText](#gettext) | Retrieves the text of a Tooltip control. |
| [GetTipBkColor](#gettipbkcolor) | Retrieves the background color in a Tooltip window. |
| [GetTipTextColor](#gettiptextcolor) | Retrieves the text color in a Tooltip window. |
| [GetTitle](#gettitle) | Retrieves the titlñe of a Tooltip window. |
| [GetToolCount](#gettoolcount) | Retrieves a count of the tools maintained by a Tooltip control. |
| [GetToolInfo](#gettoolinfo) | Retrieves the information that a Tooltip control maintains about a tool. |
| [HitTest](#hittest) | Tests a point to determine whether it is within the bounding rectangle of the specified tool and, if it is, retrieves information about the tool. |
| [NewToolRect](#newtoolrect) | Sets a new bounding rectangle for a tool. |
| [Pop](#pop) | Removes a displayed Tooltip window from view. |
| [Popup](#popup) | Causes the Tooltip to display at the coordinates of the last mouse message. |
| [RelayEvent](#relayevent) | Passes a mouse message to a Tooltip control for processing. |
| [SetDelayTime](#setdelaytime) | Sets the initial, pop-up, and reshow durations for a Tooltip control. |
| [SetMargin](#setmargin) | Sets the top, left, bottom, and right margins for a Tooltip window. |
| [SetMaxTipWidth](#setmaxtipwidth) | Sets the maximum width for a Tooltip window. |
| [SetTipBkColor](#settipbkcolor) | Sets the background color in a Tooltip window. |
| [SetTipTextColor](#settiptextcolor) | Sets the text color in a Tooltip window. |
| [SetTitle](#settitle) | Adds a standard icon and title string to a Tooltip. |
| [SetToolInfo](#settoolinfo) | Sets the information that a Tooltip control maintains for a tool. |
| [SetWindowTheme](#setwindowtheme) | Sets the visual style of a Tooltip control. |
| [SetDarkMode](#setdarkmode) | Sets the dark mode visual style of a Tooltip control. |
| [SetTooltipText](#settooltiptext) | Sets/replaces the text of a Tooltip control. |
| [TrackActivate](#trackactivate) | Activates a tracking Tooltip. |
| [TrackDeactivate](#trackactivate) | Deactivates a tracking Tooltip. |
| [TrackPosition](#trackposition) | Sets the position of a tracking Tooltip. |
| [Update](#update) | Forces the current Tooltip to be redrawn. |
| [UpdateTipText](#updatetiptext) | Sets the Tooltip text for a tool. |

---

### Activate

Activates or deactivates a Tooltip control.

```
SUB Activate (BYVAL hTooltip AS HWND, BYVAL fActivate AS BOOLEAN)
SUB Activate (BYVAL hTooltip AS HWND)
SUB Deactivate (BYVAL hTooltip AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *fActivate* | Activation flag. If this parameter is TRUE, the tooltip control is activated. If it is FALSE, the tooltip control is deactivated. |

---

### AddTool

Registers a tool with a Tooltip control.

```
FUNCTION AddTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure containing information that the tooltip control needs to display text for the tool. The cbSize member of this structure must be filled in before sending this message. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Although the name of the message implicitly indicates the "addition of a tool", it must be made clear that this message merely records a set of specific settings for what is called "a tool", however a ToolTip can be displayed even when there is no "tool" itself (a visual control with a handle). For this reason, this message should be interpreted as "add a set of specific settings for the display of a ToolTip ". A ToolTip window can be displayed in several different ways and each of these ways can be registered via the TTM_ADDTOOL message.

---

### AddToolTip

Creates a Tooltip for a control.

```
FUNCTION AddTooltip (BYVAL hwnd AS HWND, BYREF wszText AS CONST WSTRING = "", _
   BYVAL bBalloon AS BOOLEAN = FALSE, BYVAL bCentered AS BOOLEAN = FALSE) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hwnd* | The handle of the window or control. |
| *wszText* | The Tooltip text. |
| *bBalloon* | Balloon tip (TRUE or FALSE). |
| *bCentered* | Centered (TRUE or FALSE). |

#### Return value

The handle of the Tooltip control

---

### AdjustRect

Calculates a Tooltip control's text display rectangle from its window rectangle, or the tooltip window rectangle needed to display a specified text display rectangle.

```
FUNCTION AdjustRect (BYVAL hTooltip AS HWND, BYVAL fLarger AS BOOLEAN, BYVAL lprc AS RECT PTR) AS BOOLEAN
FUNCTION AdjustRect (BYVAL hTooltip AS HWND, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *fLarger* | Value that specifies which operation to perform. If TRUE, *lprc* is used to specify a text-display rectangle and it receives the corresponding window rectangle. If FALSE, *lprc* is used to specify a window rectangle and it receives the corresponding text display rectangle. |
| *lprc* | Pointer tp a **RECT** structure to hold either a tooltip window rectangle or a text display rectangle. |
| *rc* | A **RECT** structure to hold either a tooltip window rectangle or a text display rectangle. |

#### Return value

Returns a nonzero value if the rectangle is successfully adjusted, and returns zero if an error occurs.

#### Remarks

This message is particularly useful when you want to use a tooltip control to display the full text of a string that is usually truncated. It is commonly used with listview and treeview controls. You typically send this message in response to a **TTN_SHOW** notification code so that you can position the tooltip control properly.

The tooltip window rectangle is somewhat larger than the text display rectangle that bounds the tooltip string. The window origin is also offset up and to the left from the origin of the text display rectangle. To position the text display rectangle, you must calculate the corresponding window rectangle and use that rectangle to position the tooltip. **TTM_ADJUSTRECT** handles this calculation for you.

If you set wParam to TRUE, **TTM_ADJUSTRECT** takes the size and position of the desired tooltip text display rectangle, and passes back the size and position of the tooltip window needed to display the text in the specified position. If you set wParam to FALSE, you can specify a tooltip window rectangle and **TTM_ADJUSTRECT** will return the size and position of its text rectangle.

The following code fragment illustrates the use of the **TTM_ADJUSTRECT** message to position a tooltip control to display the full text of a control's string in place of a truncated string. The application-defined GetMyItemRect function returns the text rectangle that will be needed to display the tooltip text directly over the truncated string. The details of how this function is implemented will depend on the particular control. **TTM_ADJUSTRECT** is used to send this text rectangle to the tooltip control. It returns an appropriately sized and positioned window rectangle that is then used to position the tooltip window.

---

### DelTool

Removes a tool from a Tooltip control.

```
SUB DelTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure. The hwnd and uId members identify the tool to remove, and the **cbSize** member must specify the size of the structure. All other members are ignored. |
| *ti* | A **TOOLINFOW** structure. The hwnd and uId members identify the tool to remove, and the **cbSize** member must specify the size of the structure. All other members are ignored. |

---

### DeleteTooltip

Removes a tool from a Tooltip control.

```
SUB DeleteTooltip (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *hwnd* | Handle of the window or control |

---

### EnumTools

Retrieves the information that a Tooltip control maintains about the current tool--that is, the tool for which the Tooltip is currently displaying text.

```
FUNCTION EnumTools (BYVAL hTooltip AS HWND, BYVAL iTool AS DWORD, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
FUNCTION EnumTools (BYVAL hTooltip AS HWND, BYVAL iTool AS DWORD, BYREF ti AS TOOLINFOW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *iTool* | Zero-based index of the tool for which to retrieve information. |
| *lpti* | Pointer to a **TOOLINFOW** structure that receives information about the tool. Set the cbSize member of this structure to sizeof(TOOLINFOW) before sending this message. Allocate a buffer. Set the *lpszText* member to point to the buffer to receive the tool text. There is no way to determine the required buffer size. However, tool text, as returned at the *lpszText* member of the **TOOLINFOW** structure, has a maximum length of 80 TCHARs, including the terminating NULL. If the text exceeds this length, it is truncated. |

#### Return value

Returns FALSE whether or not a tool was enumerated.

#### Remarks
Security Warning: Using this message might compromise the security of your program. This message does not provide a way for the message receiver to know the size of the buffer or to specify the size of the buffer.

---

### GetBubbleSize

Returns the width and height of a tooltip control.

```
FUNCTION GetBubbleSize (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS DWORD
FUNCTION GetBubbleSize (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to the tooltip **TOOLINFOW** structure. |
| *ti* | A tooltip **TOOLINFOW** structure. |

#### Return value

Returns the width of the tooltip in the low word and the height in the high word if successful. Otherwise, it returns FALSE.

#### Remarks

If the **TTF_TRACK** and **TTF_ABSOLUTE** flags are set in the *uFlags* member of the tooltip **TOOLINFOW** structure, this message can be used to help position the tooltip accurately.

---

### GetCurrentTool

Retrieves the information for the current tool in a tooltip control.

```
FUNCTION GetCurrentTool (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
FUNCTION GetCurrentTool (BYVAL hTooltip AS HWND, BYVAL ti AS TOOLINFOW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure that receives information about the current tool. If this value is NULL, the return value indicates the existence of the current tool without actually retrieving the tool information. If this value is not NULL, the cbSize member of the **TOOLINFOW** structure must be filled in before sending this message. |
| *ti* | A **TOOLINFOW** structure that receives information about the current tool. If this value is NULL, the return value indicates the existence of the current tool without actually retrieving the tool information. If this value is not NULL, the cbSize member of the **TOOLINFOW** structure must be filled in before sending this message. |

#### Return value

Returns nonzero if successful, or zero otherwise. If **lpti** is NULL, returns nonzero if a current tool exists, or zero otherwise.

---

### GetDelayTime

Retrieves the initial, pop-up, and reshow durations currently set for a tooltip control.

```
FUNCTION GetDelayTime (BYVAL hTooltip AS HWND, BYVAL flag AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *flag* | Flag that specifies which duration value will be retrieved. This parameter can have one of the following values: |

| Value | Meaning |
| ----- | ------- |
| **TTDT_AUTOPOP** | Retrieve the amount of time the tooltip window remains visible if the pointer is stationary within a tool's bounding rectangle. |
| **TTDT_INITIAL** | Retrieve the amount of time the pointer must remain stationary within a tool's bounding rectangle before the tooltip window appears. |
| **TTDT_RESHOW** | Retrieve the amount of time it takes for subsequent tooltip windows to appear as the pointer moves from one tool to another. |

#### Return value

Returns a LONG value with the specified duration in milliseconds.

---

### GetMargin

Retrieves the top, left, bottom, and right margins set for a tooltip window. A margin is the distance, in pixels, between the tooltip window border and the text contained within the tooltip window.

```
SUB GetMargin (BYVAL hTooltip AS HWND, BYVAL lprc AS RECT PTR)
SUB GetMargin (BYVAL hTooltip AS HWND, BYREF rc AS RECT)
FUNCTION GetMargin (BYVAL hTooltip AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lprc* | Pointer to a **RECT** structure that will receive the margin information. The members of the **RECT** structure do not define a bounding rectangle. For the purpose of this message, the structure members are interpreted as follows: |
| *rc* | A **RECT** structure that will receive the margin information. The members of the **RECT** structure do not define a bounding rectangle. For the purpose of this message, the structure members are interpreted as follows: |

| Value | Maning |
| ----- | ------ |
| **left** | Distance between left border and left end of tooltip text, in pixels. |
| **top** | Distance between top border and top of tooltip text, in pixels. |
| **right** | Distance between right border and right end of tooltip text, in pixels. |
| **bottom** | Distance between bottom border and bottom of tooltip text, in pixels. |

#### Remarks

All four margins default to zero when you create the tooltip control.

---

### GetMaxTipWidth

Retrieves the maximum width for a tooltip window.

```
FUNCTION GetMaxTipWidth (BYVAL hTooltip AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

#### Return value

Returns a LONG value that represents the maximum tooltip width, in pixels. If no maximum width was set previously, the message returns -1.

#### Remarks

The maximum tooltip width value does not indicate a tooltip window's actual width. Rather, if a tooltip string exceeds the maximum width, the control breaks the text into multiple lines, using spaces to determine line breaks. If the text cannot be segmented into multiple lines, it will be displayed on a single line. The length of this line may exceed the maximum tooltip width.

---

### GetText

Retrieves the text of a Tooltip control.

```
FUNCTION GetText (BYVAL hTooltip AS HWND, BYVAL numChars AS DWORD, BYVAL lpti AS TOOLINFOW PTR)
FUNCTION GetText (BYVAL hTooltip AS HWND, BYVAL numChars AS DWORD, BYREF ti AS TOOLINFOW)
FUNCTION GetText (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND, BYVAL numChars AS DWORD) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *numChars* | The number of characters, including the terminating NULL, to copy to the buffer pointed to by *lpszText*. |
| *lpti* | Pointer to a **TOOLINFOW** structure. Set the **cbSize** member of this structure to sizeof(TOOLINFO) before sending this message. Set the hwnd and uId members to identify the tool for which to retrieve information. Allocate a buffer of size specified by *numChars*. Set the *lpszText* member to point to the buffer to receive the tool text. |
| *ti* | A **TOOLINFOW** structure. Set the **cbSize** member of this structure to sizeof(TOOLINFO) before sending this message. Set the hwnd and uId members to identify the tool for which to retrieve information. Allocate a buffer of size specified by *numChars*. Set the *lpszText* member to point to the buffer to receive the tool text. |

---

### GetTipBkColor

Retrieves the background color in a Tooltip window.

```
FUNCTION GetTipBkColor (BYVAL hTooltip AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

#### Return value

Returns a **COLORREF** value that represents the background color.

---

### GetTipTextColor

Retrieves the text color in a tooltip window.

```
FUNCTION GetTipTextColor (BYVAL hTooltip AS HWND) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

#### Return value

Returns a **COLORREF** value that represents the text color.

---

### GetTitle

Retrieve information concerning the title of a tooltip control.

```
FUNCTION GetTitle (BYVAL hTooltip AS HWND, BYVAL pTTGetTitle AS TTGETTITLE PTR)
FUNCTION GetTitle (BYVAL hTooltip AS HWND, BYREF tTTGetTitle AS TTGETTITLE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *pTTGetTitle* | Pointer to a **TTGETTITLE** structure that contains information about a tooltip title. |
| *pTTGetTitle* | Pointer to a **TTGETTITLE** structure that contains information about a tooltip title. |

#### Return value

Returns a **COLORREF** value that represents the text color.

#### Note

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0

---

### GetToolCount

Retrieves a count of the tools maintained by a tooltip control.

```
FUNCTION GetToolCount (BYVAL hTooltip AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

#### Return value

Returns a count of tools.

---

### GetToolInfo

Retrieves the information that a tooltip control maintains about a tool.

```
FUNCTION GetToolInfo (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR) AS BOOLEAN
FUNCTION GetToolInfo (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW) AS BOOLEAN
FUNCTION GetToolInfo (BYVAL hTooltip AS HWND) AS TOOLINFOW
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure. When sending the message, the hwnd and uId members identify a tool, and the cbSize member must specify the size of the structure. When using this message to retrieve the tooltip text, ensure that the *lpszText* member of the **TOOLINFOW** structure points to a valid buffer of adquate size |
| *ti* | A **TOOLINFOW** structure. When sending the message, the hwnd and uId members identify a tool, and the cbSize member must specify the size of the structure. When using this message to retrieve the tooltip text, ensure that the *lpszText* member of the **TOOLINFOW** structure points to a valid buffer of adquate size |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the tooltip control includes the tool, the **TOOLINFOW** structure receives information about the tool.

---

### HitTest

Tests a point to determine whether it is within the bounding rectangle of the specified tool and, if it is, retrieves information about the tool.

```
FUNCTION HitTest (BYVAL hTooltip AS HWND, BYVAL lphti AS TTHITTESTINFOW PTR) AS BOOLEAN
FUNCTION HitTest (BYVAL hTooltip AS HWND, BYREF phti AS TTHITTESTINFOW) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lphti* | Pointer to a **TTHITTESTINFO** structure. When sending the message, the *hwnd* member must specify the handle to a tool and the pt member must specify the coordinates of a point. If the return value is TRUE, the **ti** member (a **TOOLINFOW** structure) receives information about the tool that occupies the point. The **cbSize** member of the ti structure must be filled in before sending this message. |

#### Return value

Returns TRUE if the tool occupies the specified point, or FALSE otherwise.

#### Remarks

This message must be sent when the tool has the **TTF_TRACK** flag set. For more information on this flag, see **TOOLINFOW**. **TTM_HITTEST** will fail if **TTF_TRACK** is not set, regardless if the hit point is in the tools rectangle or not.

---

### NewToolRect

Sets a new bounding rectangle for a tool.

```
SUB NewToolRect (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
SUB NewToolRect (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure. The **hwnd** and uId members identify a tool, and the rect member specifies the new bounding rectangle. The **cbSize** member of this structure must be filled in before sending this message. |
| *ti* | A **TOOLINFOW** structure. The **hwnd** and uId members identify a tool, and the rect member specifies the new bounding rectangle. The **cbSize** member of this structure must be filled in before sending this message. |

---

### Pop

Removes a displayed tooltip window from view.

```
SUB Pop (BYVAL hTooltip AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

---

### Popup

Causes the tooltip to display at the coordinates of the last mouse message.

```
SUB Popup (BYVAL hTooltip AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

**Note**: To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### RelayEvent

Passes a mouse message to a tooltip control for processing.

```
SUB RelayEvent (BYVAL hTooltip AS HWND, BYVAL lpmsg AS tagMSG PTR)
SUB RelayEvent (BYVAL hTooltip AS HWND, BYREF msg AS tagMSG)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpmsg* | Pointer to an **MSG** structure that contains the message to relay. |
| *msg* | A **MSG** structure that contains the message to relay. |

#### Remarks

A tooltip control processes only the following messages passed to it by the **TTM_RELAYEVENT** message:

* WM_LBUTTONDOWN
* WM_LBUTTONUP
* WM_MBUTTONDOWN
* WM_MBUTTONUP
* WM_MOUSEMOVE
* WM_NCMOUSEMOVE
* WM_RBUTTONDOWN
* WM_RBUTTONUP

All other messages are ignored.

---

### SetDelayTime

Sets the initial, pop-up, and reshow durations for a tooltip control.

```
SUB SetDelayTime (BYVAL hTooltip AS HWND, BYVAL flag AS DWORD, BYVAL iTime AS SHORT)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *flag* | Flag that specifies which time value to set. This parameter can be one of the following values (see below). |
| *iTime* | The delay time, in milliseconds.  |

| Value | Meaning |
| ----- | ------- |
| **TTDT_AUTOPOP** | Set the amount of time a tooltip window remains visible if the pointer is stationary within a tool's bounding rectangle. To return the autopop delay time to its default value, set *iTime* to -1. |
| **TTDT_INITIAL** | Set the amount of time a pointer must remain stationary within a tool's bounding rectangle before the tooltip window appears. To return the initial delay time to its default value, set *iTime* to -1. |
| **TTDT_RESHOW** | Set the amount of time it takes for subsequent tooltip windows to appear as the pointer moves from one tool to another. To return the reshow delay time to its default value, set *iTime* to -1. |
| **TTDT_AUTOMATIC** | Set all three delay times to default proportions. The autopop time will be ten times the initial time and the reshow time will be one fifth the initial time. If this flag is set, use a positive value of *iTime* to specify the initial time, in milliseconds. Set *iTime* to a negative value to return all three delay times to their default values. |

#### Remarks

The default delay times are based on the double-click time. For the default double-click time of 500 ms, the initial, autopop, and reshow delay times are 500ms, 5000ms, and 100ms respectively. The following code fragment uses the **GetDoubleClickTime** function to determine the three delay times for any system.
```
initial = GetDoubleClickTime();
autopop = GetDoubleClickTime() * 10;
reshow = GetDoubleClickTime() / 5;
```
---

### SetMargin

Sets the top, left, bottom, and right margins for a tooltip window. A margin is the distance, in pixels, between the tooltip window border and the text contained within the tooltip window.

```
SUB SetMargin (BYVAL hTooltip AS HWND, BYVAL lprc AS RECT PTR)
SUB SetMargin (BYVAL hTooltip AS HWND, BYREF rc AS RECT)
SUB SetMargin (BYVAL hTooltip AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lprc* | Pointer to a **RECT** structure that contains the margin information to be set. The members of the **RECT** structure do not define a bounding rectangle. For the purpose of this message, the structure members are interpreted as follows: |
| *rc* | A **RECT** structure that contains the margin information to be set. The members of the **RECT** structure do not define a bounding rectangle. For the purpose of this message, the structure members are interpreted as follows: |

| Value | Meaning |
| ----- | ------- |
| **top** | Distance between top border and top of tooltip text, in pixels. |
| **left** | Distance between left border and left end of tooltip text, in pixels. |
| **bottom** | Distance between bottom border and bottom of tooltip text, in pixels. |
| **right** | Distance between right border and right end of tooltip text, in pixels. |

#### Remarks

This message has no effect when the application runs on Windows Vista and visual styles are enabled for the tooltip. You can disable visual styles for the tooltip by using **SetWindowTheme**.

---

### SetMaxTipWidth

Sets the maximum width for a tooltip window, in pixels.

```
FUNCTION SetMaxTipWidth (BYVAL hTooltip AS HWND, BYVAL iWidth AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *iWidth* | Maximum tooltip window width, in pixels; or -1 to allow any width. |

#### Return value

Returns the previous maximum tooltip width.

#### Remarks

The maximum width value does not indicate a tooltip window's actual width. Rather, if a tooltip string exceeds the maximum width, the control breaks the text into multiple lines, using spaces to determine line breaks. If the text cannot be segmented into multiple lines, it is displayed on a single line, which may exceed the maximum tooltip width.

---


### SetTipBkColor

Sets the background color in a tooltip window.

```
SUB SetTipBkColor (BYVAL hTooltip AS HWND, BYVAL clr AS COLORREF)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *clr* | The new background color. |

#### Remarks

When visual styles are enabled, this message has no effect.

---

### SetTipTextColor

Sets the text color in a tooltip window.

```
SUB SetTipTextColor (BYVAL hTooltip AS HWND, BYVAL clr AS COLORREF)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *clr* | The new text color. |

#### Remarks

When visual styles are enabled, this message has no effect.

---

### SetTitle

Adds a standard icon and title string to a tooltip.

```
FUNCTION SetTitle (BYVAL hTooltip AS HWND, BYVAL nIcon AS LONG, BYVAL pwszTitle AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *nIcon* | Set *nIcon* to one of the following values to specify the icon to be displayed. As of Windows Vista and later, this parameter can also contain an **HICON value**. Any value greater than **TTI_ERROR_LARGE** is assumed to be an **HICON**. See table below. |
| *pwszTitle* | Pointer to the title string. You must assign a value to *nIcon*. |

| Value | Meaning |
| ----- | ------- |
| **TTI_NONE** | No icon. |
| **TTI_INFO** | Info icon. |
| **TTI_WARNING** | Warning icon. |
| **TTI_ERROR** | Error icon. |
| **TTI_INFO_LARGE** | Large error icon. |
| **TTI_WARNING_LARGE** | Large error icon. |
| **TTI_ERROR_LARGE** | Large error icon. |

#### Return value

Returns TRUE if successful, FALSE if not.

#### Remarks

The title of a tooltip appears above the text, in a different font. It is not sufficient to have a title; the tooltip must have text as well, or it is not displayed.

When *nIcon* contains an **HICON**, a copy of the icon is created by the tooltip window.

When calling **TTM_SETTITLE**, the string pointed to by *pwszTitle* must not exceed 100 TCHARs in length, including the terminating NULL.

---

### SetToolInfo

Sets the information that a tooltip control maintains for a tool.

```
SUB SetToolInfo (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
SUB SetToolInfo (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure that specifies the information to set. The **cbSize** member of this structure must be set before sending this message. |
| *ti* | A **TOOLINFOW** structure that specifies the information to set. The **cbSize** member of this structure must be set before sending this message. |

#### Remarks

Some internal properties of a tool are established when the tool is created, and are not recomputed when a **TTM_SETTOOLINFO** message is sent. If you simply assign values to a **TOOLINFOW** structure and pass it to the tooltip control with a **TTM_SETTOOLINFO** message, these properties may be lost. Instead, your application should first request the tool's current **TOOLINFOW** structure by sending the tooltip control a **TTM_GETTOOLINFO** message. Then, modify the members of this structure as needed and pass it back to the tooltip control with **TTM_SETTOOLINFO**.

When calling **TTM_SETTOOLINFO**, the string pointed to by the lpszText member of the **TOOLINFOW** structure must not exceed 80 characters in length, including the terminating NULL.

---

### SetWindowTheme

Sets the visual style of a tooltip control.

```
SUB SetWindowTheme (BYVAL hTooltip AS HWND, BYVAL pwszTheme AS WSTRING PTR)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *pwszTheme* | Pointer to a Unicode string that contains the tooltip visual style to set. |

**Note**: To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### SetDarkMode

Sets the dark mode visual style of a Tooltip control.

```
SUB SetDarkMode (BYVAL hTooltip AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

---

### SetTooltipText

Sets/replaces the text of a Tooltip control

```
FUNCTION SetTooltipText (BYVAL hTooltip AS HWND, BYVAL hwnd AS HWND, BYREF wszText AS CONST WSTRING)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *hwnd* | The handle of the window or control. |
| *wszText* | The tppltip text to set. |

---

### TrackActivate

Activates or deactivates a tracking tooltip.

```
SUB TrackActivate (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
SUB TrackActivate (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
SUB TrackDeactivate (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
SUB TrackDeactivate (BYVAL hTooltip AS HWND, BYREF ti AS TOOLINFOW)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure that identifies the tool to which this message applies. The hwnd and uId members identify the tool, and the cbSize member specifies the size of the structure. All other members are ignored. |
| *ti* | A **TOOLINFOW** structure that identifies the tool to which this message applies. The hwnd and uId members identify the tool, and the cbSize member specifies the size of the structure. All other members are ignored. |

---

### TrackPosition

Sets the position of a tracking tooltip.

```
SUB TrackPosition (BYVAL hTooltip AS HWND, BYVAL xPos AS LONG, BYVAL yPos AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *xPos* | The x-coordinate of the point at which the tracking tooltip will be displayed, in screen coordinates.  |
| *yPos* | The y-coordinate of the point at which the tracking tooltip will be displayed, in screen coordinates.  |

#### Remarks

The tooltip control chooses where to display the tooltip window based on the coordinates you provide with this message. This causes the tooltip window to appear beside the tool to which it corresponds. To have tooltip windows displayed at specific coordinates, include the **TTF_ABSOLUTE** flag in the **uFlags** member of the **TOOLINFOW** structure when adding the tool.

---

### Update

Forces the current tooltip to be redrawn.

```
SUB Update (BYVAL hTooltip AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |

---

### UpdateTipText

Sets the tooltip text for a tool.

```
SUB UpdateTipText (BYVAL hTooltip AS HWND, BYVAL lpti AS TOOLINFOW PTR)
SUB UpdateTipText (BYVAL hTooltip AS HWND, BYVAL ti AS TOOLINFOW)
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lpti* | Pointer to a **TOOLINFOW** structure. The hinst and lpszText members must specify the instance handle and the address of the text. The *hwnd* and *uId* members identify the tool to update. The **cbSize** member of this structure must be filled in before sending this message. |

---

### WindowFromPoint

Allows a subclass procedure to cause a tooltip to display text for a window other than the one beneath the mouse cursor.

```
FUNCTION WindowFromPoint (BYVAL hTooltip AS HWND, BYVAL lppt AS POINT PTR) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTooltip* | The handle of the Tooltip control. |
| *lppt* | Pointer to a **POINT** structure that defines the point to be checked. |

#### Return value

The return value is the handle to the window that contains the point, or NULL if no window exists at the specified point.

#### Remarks

This message is intended to be processed by an application that subclasses a tooltip. It is not intended to be sent by an application. A tooltip sends this message to itself before displaying the text for a window. By changing the coordinates of the point specified by *lppt*, the subclass procedure can cause the tooltip to display text for a window other than the one beneath the mouse cursor.

---
