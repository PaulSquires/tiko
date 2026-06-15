# CTrackbar Class

A trackbar is a window that contains a slider (sometimes called a thumb) in a channel, and optional tick marks. When the user moves the slider, using either the mouse or the direction keys, the trackbar sends notification messages to indicate the change.

See: [About Trackbar Controls](https://learn.microsoft.com/en-us/windows/win32/controls/trackbar-controls)

**Include file**: CTrackbar.inc

| Name       | Description |
| ---------- | ----------- |
| [ClearSel](#clearsel) | Clears the current selection range in a trackbar. |
| [ClearTics](#clearticks) | Removes the current tick marks from a trackbar. This message does not remove the first and last tick marks, which are created automatically by the trackbar. |
| [GetBuddy](#getbuddy) | Retrieves the handle to a trackbar control buddy window at a given location. |
| [GetChannelRect](#getchannelrect) | Retrieves the size and position of the bounding rectangle for a trackbar's channel. |
| [GetLineSize](#getlinesize) | Retrieves the number of logical positions the trackbar's slider moves in response to keyboard input from the arrow keys, such as the or keys. |
| [GetNumTics](#getnumtics) | Retrieves the number of tick marks in a trackbar. |
| [GetPageSize](#getpagesize) | Retrieves the number of logical positions the trackbar's slider moves in response to keyboard. |
| [GetPos](#getpos) | Retrieves the current logical position of the slider in a trackbar. |
| [GetPTics](#getptics) | Retrieves the address of an array that contains the positions of the tick marks for a trackbar. |
| [GetRangeMax](#getrangemax) | Retrieves the maximum position for the slider in a trackbar. |
| [GetRangeMin](#getrangemin) | Retrieves the minimum position for the slider in a trackbar. |
| [GetSelEnd](#getselend) | Retrieves the ending position of the current selection range in a trackbar. |
| [GetSelStart](#getselstart) | Retrieves the starting position of the current selection range in a trackbar. |
| [GetThumbLength](#getthumblength) | Retrieves the length of the slider in a trackbar. |
| [GetThumbRect](#getthumbrect) | Retrieves the length of the slider in a trackbar. |
| [GetTic](#gettic) | Retrieves the length of the slider in a trackbar. |
| [GetTicPos](#getticpos) | Retrieves the length of the slider in a trackbar. |
| [GetTooltips](#gettooltips) | Retrieves the handle to the ToolTip control assigned to the trackbar, if any. |
| [SetBuddy](#setbuddy) | Assigns a window as the buddy window for a trackbar control. |
| [SetLineSize](#setlinesize) | Sets the number of logical positions the trackbar's slider moves in response to keyboard input from the arrow keys, such as the or keys. |
| [SetPageSize](#setpagesize) | Sets the number of logical positions the trackbar's slider moves in response to keyboard input. |
| [SetPos](#setpos) | Sets the current logical position of the slider in a trackbar. |
| [SetRange](#setrange) | Sets the range of minimum and maximum logical positions for the slider in a trackbar. |
| [SetRangeMax](#setrangemax) | Sets the maximum logical position for the slider in a trackbar. |
| [SetRangeMin](#setrangemin) | Sets the minimum logical position for the slider in a trackbar. |
| [SetSel](#setsel) | Sets the starting and ending positions for the available selection range in a trackbar. |
| [SetSelEnd](#setselend) | Sets the ending logical position of the current selection range in a trackbar. |
| [SetSelStart](#setselstart) | Sets the starting logical position of the current selection range in a trackbar. |
| [SetThumbLength](#setthumblength) | Sets the length of the slider in a trackbar. |
| [SetTic](#settic) | Sets a tick mark in a trackbar at the specified logical position. |
| [SetTicFreq](#setticfreq) | Sets the interval frequency for tick marks in a trackbar. |
| [SetTipSide](#settipside) | Positions a ToolTip control used by a trackbar control. |
| [SetToolTips](#settooltips) | Assigns a ToolTip control to a trackbar control. |

---

### ClearSel

Clears the current selection range in a trackbar.

```
SUB ClearSel (BYVAL hTrackbar AS HWND, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *fRedraw* | Redraw flag. If this parameter is TRUE, the trackbar is redrawn after the selection is cleared. |

#### Remarks

A trackbar can have a selection range only if you specified the **TBS_ENABLESELRANGE** style when you created it.

---

### ClearTics

Removes the current tick marks from a trackbar. This message does not remove the first and last tick marks, which are created automatically by the trackbar.

```
SUB ClearTics (BYVAL hTrackbar AS HWND, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *fRedraw* | Redraw flag. If this parameter is TRUE, the trackbar is redrawn after the tick marks are cleared. If this parameter is FALSE, the message clears the tick marks but does not redraw the trackbar. |

---

### GetBuddy

Retrieves the handle to a trackbar control buddy window at a given location. The specified location is relative to the control's orientation (horizontal or vertical).

```
FUNCTION GetBuddy (BYVAL hTrackbar AS HWND, BYVAL fLocation AS BOOLEAN) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *fLocation* | Value indicating which buddy window handle will be retrieved, by relative location. This value can be one of the following: |

| Value | Meaning |
| ----- | ------- |
| **TRUE** | Retrieves the handle to the buddy to the left of the trackbar. If the trackbar control uses the TBS_VERT style, the message will retrieve the buddy above the trackbar. |
| **FALSE** | Retrieves the handle to the buddy to the right of the trackbar. If the trackbar control uses the TBS_VERT style, the message will retrieve the buddy below the trackbar. |

#### Return value

Returns the handle to the buddy window at the location specified by *fLocation*, or NULL if no buddy window exists at that location.

---

### GetChannelRect

Retrieves the size and position of the bounding rectangle for a trackbar's channel. (The channel is the area over which the slider moves. It contains the highlight when a range is selected.)

```
SUB GetChannelRect (BYVAL hTrackbar AS HWND, BYVAL prc AS RECT PTR)
SUB GetChannelRect (BYVAL hTrackbar AS HWND, BYREF rc AS RECT)
FUNCTION GetChannelRect (BYVAL hTrackbar AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *prc* | Pointer to a **RECT** structure. The message fills this structure with the channel's bounding rectangle, in client coordinates of the trackbar's window. |

---

### GetLineSize

Retrieves the number of logical positions the trackbar's slider moves in response to keyboard input from the arrow keys, such as the or keys. The logical positions are the integer increments in the trackbar's range of minimum to maximum slider positions.

```
FUNCTION GetLineSize (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the line size for the trackbar.

#### Remarks

The default setting for the line size is 1.

The trackbar also sends a **WM_HSCROLL** or **WM_VSCROLL** message with the **TB_LINEUP** and **TB_LINEDOWN** notification codes to its parent window when the user presses the arrow keys.

---

### GetNumTics

Retrieves the number of tick marks in a trackbar.

```
FUNCTION GetNumTics (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

If no tick flag is set, it returns 2 for the beginning and ending ticks. If **TBS_NOTICKS** is set, it returns zero. Otherwise, it takes the difference between the range minimum and maximum, divides by the tick frequency, and adds 2.

#### Remarks

The **TBM_GETNUMTICS** message counts all of the tick marks, including the first and last tick marks created by the trackbar.

---

### GetPageSize

Retrieves the number of logical positions the trackbar's slider moves in response to keyboard input, such as the or keys, or mouse input, such as clicks in the trackbar's channel. The logical positions are the integer increments in the trackbar's range of minimum to maximum slider positions.

```
FUNCTION GetPageSize (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the page size for the trackbar.

#### Remarks

The trackbar also sends a **WM_HSCROLL** or **WM_VSCROLL** message with the **TB_PAGEUP** and **TB_PAGEDOWN** notification codes to its parent window when it receives keyboard or mouse input that scrolls the page.

---

### GetPos

Retrieves the current logical position of the slider in a trackbar. The logical positions are the integer values in the trackbar's range of minimum to maximum slider positions.

```
FUNCTION GetPos (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the current logical position of the trackbar's slider.

---

### GetPTics

Retrieves the address of an array that contains the positions of the tick marks for a trackbar.

```
FUNCTION GetPTics (BYVAL hTrackbar AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns the address of an array of DWORD values. The elements of the array specify the logical positions of the trackbar's tick marks, not including the first and last tick marks created by the trackbar. The logical positions can be any of the integer values in the trackbar's range of minimum to maximum slider positions.

#### Remarks

The number of elements in the array is two less than the tick count returned by the **TBM_GETNUMTICS** message. Note that the values in the array may include duplicate positions and may not be in sequential order. The returned pointer is valid until you change the trackbar's tick marks.

---

### GetRangeMax

Retrieves the maximum position for the slider in a trackbar.

```
FUNCTION GetRangeMax (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the maximum position in the trackbar's range of minimum to maximum slider positions.

---

### GetRangeMin

Retrieves the minimum position for the slider in a trackbar.

```
FUNCTION GetRangeMin (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the minimum position in the trackbar's range of minimum to maximum slider positions.

---

### GetSelEnd

Retrieves the ending position of the current selection range in a trackbar.

```
FUNCTION GetSelEnd (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the ending position of the current selection range.

#### Remarks

A trackbar can have a selection range only if you specified the **TBS_ENABLESELRANGE** style when you created it.

---

### GetSelStart

Retrieves the starting position of the current selection range in a trackbar.

```
FUNCTION GetSelStart (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns a 32-bit value that specifies the starting position of the current selection range.

#### Remarks

A trackbar can have a selection range only if you specified the **TBS_ENABLESELRANGE** style when you created it.

---

### GetThumbLength

Retrieves the length of the slider in a trackbar.

```
FUNCTION GetThumbLength (BYVAL hTrackbar AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns the length, in pixels, of the slider.

---

### GetThumbRect

Retrieves the size and position of the bounding rectangle for the slider in a trackbar.

```
SUB GetThumbRect (BYVAL hTrackbar AS HWND, BYVAL prc AS RECT PTR)
SUB GetThumbRect (BYVAL hTrackbar AS HWND, BYREF rc AS RECT)
FUNCTION GetThumbRect (BYVAL hTrackbar AS HWND) AS RECT
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *prc* | Pointer to a **RECT** structure. The message fills this structure with the bounding rectangle of the trackbar's slider in client coordinates of the trackbar's window. |

---

### GetTic

Retrieves the logical position of a tick mark in a trackbar. The logical position can be any of the integer values in the trackbar's range of minimum to maximum slider positions.

```
FUNCTION GetTic (BYVAL hTrackbar AS HWND, BYVAL iTic AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *iTic* | Zero-based index identifying a tick mark. Valid indexes are in the range from zero to two less than the tick count returned by the **TBM_GETNUMTICS** message. |

#### Return value

Returns the logical position of the specified tick mark, or -1 if *iTic* does not specify a valid index.

---

### GetTicPos

Retrieves the current physical position of a tick mark in a trackbar.

```
FUNCTION GetTicPos (BYVAL hTrackbar AS HWND, BYVAL iTic AS DWORD) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *iTic* | Zero-based index identifying a tick mark. The positions of the first and last tick marks are not directly available via this message. |

#### Return value

Returns the distance, in client coordinates, from the left or top of the trackbar's client area to the specified tick mark. The return value is the x-coordinate of the tick mark for a horizontal trackbar or the y-coordinate for a vertical trackbar. If *iTic* is not a valid index, the return value is -1.

Remarks
Because the first and last tick marks are not available through this message, valid indexes are offset from their tick position on the trackbar. If the difference between **TBM_GETRANGEMIN** and **TBM_GETRANGEMAX** is less than two, then there is no valid index and this message will fail.

The following illustrates the relation between the ticks on a trackbar, the ticks available through this message, and their zero-based indexes.

```
0 1 2 3 4 5 6 7 8 9    // Tick positions seen on the trackbar.
  1 2 3 4 5 6 7 8      // Tick positions whose position can be identified.
  0 1 2 3 4 5 6 7      // Index numbers for the identifiable positions.
```
---

### GetTooltips

Retrieves the handle to the tooltip control assigned to the trackbar, if any.

```
FUNCTION GetTooltips (BYVAL hTrackbar AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |

#### Return value

Returns the handle to the tooltip control assigned to the trackbar, or NULL if tooltips are not in use. If the trackbar control does not use the **TBS_TOOLTIPS** style, the return value is NULL.

---

### SetBuddy

Assigns a window as the buddy window for a trackbar control. Trackbar buddy windows are automatically displayed in a location relative to the control's orientation (horizontal or vertical).

```
FUNCTION SetBuddy (BYVAL hTrackbar AS HWND, BYVAL fLocation AS BOOLEAN, BYVAL hwndBuddy AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *fLocation* | Value specifying the location at which to display the buddy window. This value can be one of the following:<br>**TRUE**: The buddy will appear to the left of the trackbar if the trackbar control uses the TBS_HORZ style. If the trackbar uses the TBS_VERT style, the buddy appears above the trackbar control.<br>**FALSE**: The buddy will appear to the right of the trackbar if the trackbar control uses the TBS_HORZ style. If the trackbar uses the TBS_VERT style, the buddy appears below the trackbar control. |
| *hTrackbar* | Handle to the window that will be set as the trackbar control's buddy. |

#### Return value

Returns the handle to the window that was previously assigned to the control at that location.

#### Note

Trackbar controls support up to two buddy windows. This can be useful when you must display text or images at each end of the control.

---

### SetLineSize

Sets the number of logical positions the trackbar's slider moves in response to keyboard input from the arrow keys, such as the or keys. The logical positions are the integer increments in the trackbar's range of minimum to maximum slider positions.

```
FUNCTION SetLineSize (BYVAL hTrackbar AS HWND, BYVAL lLineSize AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lLineSize* | New line size. |

#### Remarks

The default setting for the line size is 1.

The trackbar also sends a **WM_HSCROLL** or **WM_VSCROLL** message with the **TB_LINEUP** and **TB_LINEDOWN** notification codes to its parent window when the user presses the arrow keys.

---

### SetPageSize

Sets the number of logical positions the trackbar's slider moves in response to keyboard input, such as the or keys, or mouse input, such as clicks in the trackbar's channel. The logical positions are the integer increments in the trackbar's range of minimum to maximum slider positions.

```
FUNCTION SetPageSize (BYVAL hTrackbar AS HWND, BYVAL lPageSize AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lPageSize* | New page size. |

#### Return value

Returns a 32-bit value that specifies the previous page size.

#### Remarks

The trackbar also sends a WM_HSCROLL or WM_VSCROLL message with the TB_PAGEUP and TB_PAGEDOWN notification codes to its parent window when it receives keyboard or mouse input that scrolls the page.

---

### SetPos

Sets the current logical position of the slider in a trackbar.

```
SUB SetPos (BYVAL hTrackbar AS HWND, BYVAL fPosition AS BOOLEAN, BYVAL lPosition AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *fPosition* | Redraw flag. If this parameter is **TRUE**, the message redraws the control with the slider at the position given by *lPosition*. If this parameter is **FALSE**, the message does not redraw the slider at the new position. Note that the message sets the value of the slider position (as returned by the **TBM_GETPOS** message) regardless of the *fPosition* parameter. |
| *lPosition* | New logical position of the slider. Valid logical positions are the integer values in the trackbar's range of minimum to maximum slider positions. If this value is outside the control's maximum and minimum range, the position is set to the maximum or minimum value. |

#### Return value

Returns a 32-bit value that specifies the previous page size.

#### Remarks

The trackbar also sends a WM_HSCROLL or WM_VSCROLL message with the TB_PAGEUP and TB_PAGEDOWN notification codes to its parent window when it receives keyboard or mouse input that scrolls the page.

---

### SetRange

Sets the range of minimum and maximum logical positions for the slider in a trackbar.

```
SUB SetRange (BYVAL hTrackbar AS HWND, BYVAL lMinimum AS LONG, BYVAL lMaximum AS LONG, _
   BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lMinimum* | Redraw flag. If this parameter is **TRUE**, the trackbar is redrawn after the range is set. If this parameter is **FALSE**, the message sets the range but does not redraw the trackbar. |
| *fRedraw* | The LOWORD specifies the minimum position for the slider, and the HIWORD specifies the maximum position. |

#### Remarks
If the current slider position is outside the new range, the **TBM_SETRANGE** message sets the slider position to the new maximum or minimum value.

Because this message takes two 16-bit unsigned integer values, the maximum range that this message can specify is from 0 to 65,535. To specify larger range values, use the **TBM_SETRANGEMIN** and **TBM_SETRANGEMAX** messages.

---

### SetRangeMax

Sets the maximum logical position for the slider in a trackbar.

```
SUB SetRangeMax (BYVAL hTrackbar AS HWND, BYVAL lMaximum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lMaximum* | Maximum position for the slider. |
| *fRedraw* | Redraw flag. If this parameter is **TRUE**, the trackbar is redrawn after the range is set. If this parameter is **FALSE**, the message sets the range but does not redraw the trackbar. |

#### Remarks

If the current slider position is greater than the new maximum, the **TBM_SETRANGEMAX** message sets the slider position to the new maximum value.

---

### SetRangeMin

Sets the minimum logical position for the slider in a trackbar.

```
SUB SetRangeMin (BYVAL hTrackbar AS HWND, BYVAL lMinimum AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lMinimum* | Minimum position for the slider. |
| *fRedraw* | Redraw flag. If this parameter is **TRUE**, the trackbar is redrawn after the range is set. If this parameter is **FALSE**, the message sets the range but does not redraw the trackbar. |

#### Remarks

If the current slider position is greater than the new maximum, the **TBM_SETRANGEMAX** message sets the slider position to the new maximum value.

---

### SetSel

Sets the starting and ending positions for the available selection range in a trackbar.

```
SUB SetSel (BYVAL hTrackbar AS HWND, BYVAL iStart AS SHORT, BYVAL iEnd AS SHORT, _
   BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *iStart* | The starting logical position for the selection range. |
| *iEnd* | The ending logical position for the selection range. |

#### Remarks

This message is ignored if the trackbar does not have the **TBS_ENABLESELRANGE** style.

**TBM_SETSEL** allows you to restrict the pointer to only a portion of the range available to the progress bar.

---

### SetSelEnd

Sets the ending logical position of the current selection range in a trackbar. This message is ignored if the trackbar does not have the **TBS_ENABLESELRANGE** style.

```
SUB SetSelEnd (BYVAL hTrackbar AS HWND, BYVAL lEnd AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lEnd* | Ending logical position of the selection range. |
| *fRedraw* | Redraw flag. If this parameter is **TRUE**, the message redraws the trackbar after the selection range is set. If this parameter is **FALSE**, the message sets the selection range but does not redraw the trackbar. |

---

### SetSelStart

Sets the starting logical position of the current selection range in a trackbar. This message is ignored if the trackbar does not have the **TBS_ENABLESELRANGE** style.

```
SUB SetSelStart (BYVAL hTrackbar AS HWND, BYVAL lStart AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lStart* | Starting logical position of the selection range. |
| *fRedraw* | Redraw flag. If this parameter is **TRUE**, the message redraws the trackbar after the selection range is set. If this parameter is **FALSE**, the message sets the selection range but does not redraw the trackbar. |

---

### SetThumbLength

Sets the length of the slider in a trackbar. This message is ignored if the trackbar does not have the **TBS_FIXEDLENGTH** style.

```
SUB SetThumbLength (BYVAL hTrackbar AS HWND, BYVAL iLength AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *iLength* | Length, in pixels, of the slider. |

---

### SetTic

Sets a tick mark in a trackbar at the specified logical position.

```
FUNCTION SetTic (BYVAL hTrackbar AS HWND, BYVAL lPosition AS LONG) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *lPosition* | Position of the tick mark. This parameter can be any of the integer values in the trackbar's range of minimum to maximum slider positions. |

#### Return value

Returns TRUE if the tick mark is set, or FALSE otherwise.

#### Remarks

A trackbar creates its own first and last tick marks. Do not use this message to set the first and last tick marks.

---

### SetTicFreq

Sets the interval frequency for tick marks in a trackbar. For example, if the frequency is set to two, a tick mark is displayed for every other increment in the trackbar's range. The default setting for the frequency is one; that is, every increment in the range is associated with a tick mark.

```
SUB SetTicFreq (BYVAL hTrackbar AS HWND, BYVAL wFreq AS WORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *wFreq* | Frequency of the tick marks. |

#### Remarks

The trackbar must have the **TBS_AUTOTICKS** style to use this message.

---

### SetTipSide

Positions a tooltip control used by a trackbar control. Trackbar controls that use the **TBS_TOOLTIPS** style display tooltips.

```
FUNCTION SetTipSide (BYVAL hTrackbar AS HWND, BYVAL fLocation AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *fLocation* | Value representing the location at which to display the tooltip control. This value can be one of the following: |

| Value | Meaning |
| ----- | ------- |
| **TBTS_TOP** | The tooltip control will be positioned above the trackbar. This flag is for use with horizontal trackbars. |
| **TBTS_LEFT** | The tooltip control will be positioned to the left of the trackbar. This flag is for use with vertical trackbars. |
| **TBTS_BOTTOM** | The tooltip control will be positioned below the trackbar. This flag is for use with horizontal trackbars. |
| **TBTS_RIGHT** | The tooltip control will be positioned to the right of the trackbar. This flag is for use with vertical trackbars. |

#### Return value

Returns a value that represents the tooltip control's previous location. The return value equals one of the possible values for *fLocation*.

---

### SetToolTips

Assigns a tooltip control to a trackbar control.

```
FUNCTION SetToolTips (BYVAL hTrackbar AS HWND, BYVAL hwndTT AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hTrackbar* | Handle to the trackbar control. |
| *hwndTT* | Handle to an existing tooltip control. |

#### Return value

The return value for this message is not used.

#### Remarks

When a trackbar control is created with the **TBS_TOOLTIPS** style, it creates a default tooltip control that appears next to the slider, displaying the slider's current position.

---
