# CMonthCal Class

A month calendar control implements a calendar-like user interface. This provides the user with a very intuitive and recognizable method of entering or selecting a date. The control also provides the application with the means to obtain and set the date information in the control using existing data types.

See: [About Month Calendar Controls](https://learn.microsoft.com/en-us/windows/win32/controls/month-calendar-controls)

**Include file**: CMontCal.inc

| Name       | Description |
| ---------- | ----------- |
| [GetCalendarBorder](#getcalendarborder) | Gets the border size, in pixels, of a month calendar control. |
| [GetCalendarCount](#getcalendarcount) | Gets the number of calendars currently displayed in the calendar control. |
| [GetCalendarGridInfo](#getcalendargridinfo) | Gets information about a calendar grid. |
| [GetCALID](#getcalid) | Gets the current calendar ID for the given calendar control. |
| [GetColor](#getcolor) | Retrieves the color for a given portion of a month calendar control. |
| [GetCurrentView](#getcurrentview) | Gets the view for a month calendar control.  |
| [GetCurSel](#getcursel) | Retrieves the currently selected date. |
| [GetFirstDayOfWeek](#getfirstdayofweek) | Retrieves the first day of the week for a month calendar control. |
| [GetMaxSelCount](#getmaxselcount) | Retrieves the maximum date range that can be selected in a month calendar control. |
| [GetMaxTodayWidth](#getmaxtodaywidth) | Retrieves the maximum width of the "today" string in a month calendar control. |
| [GetMinReqRect](#getminreqrect) | Retrieves the minimum size required to display a full month in a month calendar control.  |
| [GetMonthDelta](#getmonthdelta) | Retrieves the scroll rate for a month calendar control. |
| [GetMonthRange](#getmonthrange) | Retrieves date information (using SYSTEMTIME structures) that represents the high and low limits of a month calendar control's display. |
| [GetRange](#getrange) | Retrieves the minimum and maximum allowable dates set for a month calendar control. |
| [GetSelRange](#getselrange) | Retrieves date information that represents the upper and lower limits of the date range currently selected by the user. |
| [GetToday](#gettoday) | Retrieves the date information for the date specified as "today" for a month calendar control. |
| [HitTest](#hittest) | Determines which portion of a month calendar control is at a given point on the screen. |
| [SetCalendarBorder](#setcalendarborder) | Sets the border size, in pixels, of a month calendar control. |
| [SetCALID](#setcalid) | Sets the calendar ID for the given calendar control. |
| [SetColor](#setcolor) | Sets the color for a given portion of a month calendar control. |
| [SetCurrentView](#setcurrentview) | Sets the view for a month calendar control. |
| [SetCurSel](#setcursel) | Sets the currently selected date for a month calendar control. If the specified date is not in view, the control updates the display to bring it into view. |
| [SetDayState](#setdaystate) | Sets the day states for all months that are currently visible within a month calendar control. |
| [SetFirstDayOfWeek](#setfirstdayofweek) | Sets the first day of the week for a month calendar control. |
| [SetMaxSelCount](#setmaxselcount) | Sets the maximum number of days that can be selected in a month calendar control. |
| [SetMonthDelta](#setmonthdelta) | Sets the scroll rate for a month calendar control. |
| [SetRange](#setrange) | Sets the minimum and maximum allowable dates for a month calendar control. |
| [SetSelRange](#setselrange) | Sets the selection for a month calendar control to a given date range. |
| [SetToday](#settoday) | Sets the "today" selection for a month calendar control. |
| [SizeRectToMin](#sizerecttomin) | Calculates how many calendars will fit in the given rectangle, and then returns the minimum size that a rectangle needs to be to fit that number of calendars. |

---

### GetCalendarBorder

Gets the border size, in pixels, of a month calendar control.

```
FUNCTION GetCalendarBorder (BYVAL hMonthCal AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

The current border size, in pixels.

---

### GetCalendarCount

Gets the number of calendars currently displayed in the calendar control.

```
FUNCTION GetCalendarCount (BYVAL hMonthCal AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

The number of calendars currently displayed in the calendar control. The maximum number of allowed calendars is 12.

---

### GetCalendarGridInfo

Gets information about a calendar grid.

```
FUNCTION GetCalendarGridInfo (BYVAL hMonthCal AS HWND, BYVAL pInfo AS MCGRIDINFO PTR) AS BOOLEAN
FUNCTION GetCalendarGridInfo (BYVAL hMonthCal AS HWND, BYREF info AS MCGRIDINFO) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *pInfo* | Pointer to an **MCGRIDINFO** structure that contains information about the calendar grid. |

#### Return value

TRUE if successful, otherwise FALSE.

---

### GetCALID

Gets the current calendar ID for the given calendar control.

```
FUNCTION GetCALID (BYVAL hMonthCal AS HWND) AS CALID
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

ID of the current calendar. One of the Calendar Identifiers constants.

---

### GetColor

Retrieves the color for a given portion of a month calendar control.

```
FUNCTION GetColor (BYVAL hMonthCal AS HWND, BYVAL iColor AS LONG) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *iColor* | Value of type int specifying which month calendar color to retrieve. This value can be one of the following: |

| Value | Meaning |
| ----- | ------- |
| **MCSC_BACKGROUND** | Retrieve the background color displayed between months. |
| **MCSC_MONTHBK** | Retrieve the background color displayed within the month. |
| **MCSC_TEXT** | Retrieve the color used to display text within a month. |
| **MCSC_TITLEBK** | Retrieve the background color displayed in the calendar's title. |
| **MCSC_TITLETEXT** | Retrieve the color used to display text within the calendar's title. |
| **MCSC_TRAILINGTEXT** | Retrieve the color used to display header day and trailing day text. Header and trailing days are the days from the previous and following months that appear on the current month calendar. |

#### Return value

Returns a **COLORREF** value that represents the color setting for the specified portion of the month calendar control if successful. Otherwise, the return is -1.

---

### GetCurrentView

Gets the view for a month calendar control.

```
FUNCTION GetCurrentView (BYVAL hMonthCal AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

Current view. One of the following values.

| Return code | Description |
| ----------- | ----------- |
| **MCMV_MONTH** | Monthly view. |
| **MCMV_YEAR** | Annual view. |
| **MCMV_DECADE** | Decade view. |
| **MCMV_CENTURY** | Century view. |

---

### GetCurSel

Retrieves the currently selected date.

```
FUNCTION GetCurSel (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS BOOLEAN
FUNCTION GetCurSel (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS BOOLEAN
FUNCTION GetCurSel (BYVAL hMonthCal AS HWND) AS SYSTEMTIME
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *pst* | Pointer to a **SYSTEMTIME** structure that will receive the currently selected date information. This parameter must be a valid address and cannot be **NULL**. |

---

### GetFirstDayOfWeek

Retrieves the first day of the week for a month calendar control.

```
FUNCTION GetFirstDayOfWeek (BYVAL hMonthCal AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

Returns a **DWORD** value that contains two values. The high word is a **BOOL** value that is nonzero if the first day of the week is set to something other than **LOCALE_IFIRSTDAYOFWEEK**, or zero otherwise. The low word is an **INT** value that represents the first day of the week, where 0 is Monday, 1 is Tuesday, and so on.

---

### GetMaxSelCount

Retrieves the maximum date range that can be selected in a month calendar control.

```
FUNCTION GetMaxSelCount (BYVAL hMonthCal AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

Returns an INT value that represents the total number of days that can be selected for the control.

#### Remarks

You can change the maximum date range that can be selected by using the MCM_SETMAXSELCOUNT message.

---

### GetMaxTodayWidth

Retrieves the maximum width of the "today" string in a month calendar control. This includes the label text and the date text.

```
FUNCTION GetMaxTodayWidth (BYVAL hMonthCal AS HWND) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

Returns the width of the "today" string, in pixels.

---

### GetMinReqRect

Retrieves the minimum size required to display a full month in a month calendar control. Size information is presented in the form of a **RECT** structure.

```
FUNCTION GetMinReqRect (BYVAL hMonthCal AS HWND, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetMinReqRect (BYVAL hMonthCal AS HWND, BYREF rc AS RECT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *prc* | Pointer to a **RECT** structure that will receive bounding rectangle information. This parameter must be a valid address and cannot be **NULL**. |

#### Return value

Returns nonzero and **GetMinReqRect** receives the applicable bounding information if successful. Otherwise, the return is zero.

#### Remarks

The minimum required window size for a month calendar control depends on the currently selected font, control styles, system metrics, and regional settings. When an application changes anything that affects the minimum window size, or processes a **WM_SETTINGCHANGE** message, it should call **GetMinReqRect** to determine the new minimum size.

**Note**: The rectangle returned by **GetMinReqRect** does not include the width of the "Today" string, if it is present. If the **MCS_NOTODAY** style is not set, your application should also retrieve the rectangle that defines the "Today" string width by calling the **GetMaxTodayWidth** method. Use the larger of the two rectangles to ensure that the "Today" string is not clipped.
 
The top and left members of prc will always be zero. The **right** and **bottom** members represent the minimum *cx* and *cy* required for the control.

---

### GetMonthDelta

Retrieves the scroll rate for a month calendar control. The scroll rate is the number of months that the control moves its display when the user clicks a scroll button.

```
FUNCTION GetMonthDelta (BYVAL hMonthCal AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |

#### Return value

If the month delta was previously set using the **SetMonthDelta** method, returns an **INT** value that represents the month calendar's current scroll rate. If the month delta was not previously set using the **SetMonthDelta** metod, or the month delta was reset to the default, returns an INT value that represents the current number of months visible.

---

### GetMonthRange

Retrieves date information (using **SYSTEMTIME** structures) that represents the high and low limits of a month calendar control's display.

```
FUNCTION GetMonthRange (BYVAL hMonthCal AS HWND, BYVAL gmr AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *gmr* | Value specifying the scope of the range limits to be retrieved. This value must be one of the following:<br>**GMR_DAYSTATE**: Include preceding and trailing months of visible range that are only partially displayed.<br>**GMR_VISIBLE**: Include only those months that are entirely displayed.. |
| *rgst* | Pointer to a two-element array of **SYSTEMTIME** structures that will receive the lower and upper limits of the scope specified by *gmr*. The lower and upper limits are placed in *rgst(0)* and *rgst(1)*, respectively. The time members of these structures will not be modified. This parameter must be a valid address and cannot be **NULL**. |

#### Return value

Returns an **INT** value that represents the range, in months, spanned by the two limits returned at *rgst*.

---

### GetRange

Retrieves the minimum and maximum allowable dates set for a month calendar control.

```
FUNCTION GetRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *rgst* | Pointer to a two-element array of **SYSTEMTIME** structures that will receive the date limit information. The minimum limit is set in *rgst(0)* and *rgst(1)* receives the maximum limit. If either element is set to all zeros, then no corresponding limit is set for the month calendar control. The time members of these structures will not be modified. This parameter must be a valid address and cannot be **NULL**. |

#### Return value

Returns a **DWORD** value that can be zero (no limits are set) or a combination of the following values that specify limit information:

| Return code | Description |
| ----------- | ----------- |
| **GDTR_MAX** | There is a maximum limit set for the control; *rgst(0)* is valid and contains the applicable date information. |
| **GDTR_MIN** | There is a minimum limit set for the control; *rgst(1)* is valid and contains the applicable date information. |

---

### GetSelRange

Retrieves date information that represents the upper and lower limits of the date range currently selected by the user.

```
FUNCTION GetSelRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *rgst* | Pointer to a two-element array of **SYSTEMTIME** structures that will receive the lower and upper limits of the user's selection. The lower and upper limits are placed in *rgst(0)* and *rgst(1)*, respectively. The time members of these structures will not be modified. This parameter must be a valid address and cannot be **NULL**. |

#### Return value

Returns nonzero if successful, or zero otherwise. **GetSelRange** will fail if applied to a month calendar control that does not use the **MCS_MULTISELECT** style.

---

### GetToday

Retrieves the date information for the date specified as "today" for a month calendar control. 

```
FUNCTION GetToday (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS BOOLEAN
FUNCTION GetToday (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS BOOLEAN
FUNCTION GetToday (BYVAL hMonthCal AS HWND) AS SYSTEMTIME
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *pst* | Pointer to a **SYSTEMTIME** structure that will receive the date information. The time members of this structure will not be modified. This parameter must be a valid address and cannot be **NULL**. |

#### Return value

Returns nonzero if successful, or zero otherwise.

---

### HitTest

Determines which portion of a month calendar control is at a given point on the screen

```
FUNCTION HitTest (BYVAL hMonthCal AS HWND, BYVAL pinfo AS MCHITTESTINFO PTR) AS DWORD
FUNCTION HitTest (BYVAL hMonthCal AS HWND, BYREF info AS MCHITTESTINFO) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *pinfo* | Pointer to an **MCHITTESTINFO** structure. Upon calling the method, the **cbSize** member must be set to the size of the **MCHITTESTINFO** structure, and pt must be set to the point you want to hit test. |

#### Return value

Sets values in members of the **MCHITTESTINFO** structure at pinfo and returns a **DWORD** value that contains a set of hit test result flags. See the return value description of **MCM_HITTEST** for a list of the hit test result flags.

---

### SetCalendarBorder

Sets the border size, in pixels, of a month calendar control.

```
SUB SetCalendarBorder (BYVAL hMonthCal AS HWND, BYVAL fset AS BOOLEAN, BYVAL xyborder AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *fset* | If **TRUE**, then the border size is set to the number of pixels that xyborder specifies. If **FALSE**, then the border size is reset to the default value specified by the theme, or zero if themes are not being used. |
| *xyborder* |Number of pixels of the border size. |

---

### SetCALID

Sets the calendar ID for the given calendar control. 

```
SUB SetCALID (BYVAL hMonthCal AS HWND, BYVAL calid AS UINT)
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *calid* | Calendar ID. One of the Calendar Identifiers constants. |

| Calendar identifier | Value | Meaning |
| ------------------- | ----- | ------- |
| 1 | CAL_GREGORIAN | Gregorian (localized) |
| 2 | CAL_GREGORIAN_US | Gregorian (English strings always) |
| 3 | CAL_JAPAN | Japanese Emperor Era |
| 4 | CAL_TAIWAN | Taiwan calendar |
| 5 | CAL_KOREA | Korean Tangun Era |
| 6 | CAL_HIJRI | Hijri (Arabic Lunar) |
| 7 | CAL_THAI | Thai |
| 8 | CAL_HEBREW | Hebrew (Lunar) |
| 9 | CAL_GREGORIAN_ME_FRENCH | Gregorian Middle East French |
| 10 | CAL_GREGORIAN_ARABIC | Gregorian Arabic |
| 11 | CAL_GREGORIAN_XLIT_ENGLISH | Gregorian transliterated English |
| 12 | CAL_GREGORIAN_XLIT_FRENCH | Gregorian transliterated French |
| 23 | CAL_UMALQURA | Windows Vista and later: Um Al Qura (Arabic lunar) calendar |

**Note**: The gap in numbering between the identifiers CAL_GREGORIAN_XLIT_FRENCH and CAL_UMALQURA is intentional. The designator for CAL_UMALQURA is 23, not 13.

---

### SetColor

Sets the color for a given portion of a month calendar control.

```
FUNCTION SetColor (BYVAL hMonthCal AS HWND, BYVAL iColor AS LONG, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *clr* | **COLORREF** value that represents the color that will be set for the specified area of the month calendar. |
| *iColor* | Value of type **int** specifying which month calendar color to set. This value can be one of the following: |

| Value | Meaning |
| ----- | ------- |
| **MCSC_BACKGROUND** | Set the background color displayed between months. |
| **MCSC_MONTHBK** | Set the background color displayed within the month. |
| **MCSC_TEXT** | Set the color used to display text within a month. |
| **MCSC_TITLEBK** | Set the background color displayed in the calendar's title. |
| **MCSC_TITLETEXT** | Set the color used to display text within the calendar's title. |
| **MCSC_TRAILINGTEXT** | Set the color used to display header day and trailing day text. Header and trailing days are the days from the previous and following months that appear on the current month calendar. |

#### Return value

Returns a **COLORREF** value that represents the previous color setting for the specified portion of the month calendar control if successful. Otherwise, the return is -1.

#### Remarks

If visual styles are active, this method has no effect except when *iColor* is **MCSC_BACKGROUND**.

---

### SetCurrentView

Sets the view for a month calendar control.

```
FUNCTION SetCurrentView (BYVAL hMonthCal AS HWND, BYVAL dwNewView AS DWORD) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *dwNewView* | New view. One of the following constants. |

| Value | Meaning |
| ----- | ------- |
| **MCMV_MONTH** | Monthly view. |
| **MCMV_YEAR** | Annual view. |
| **MCMV_DECADE** | Decade view. |
| **MCMV_CENTURY** | Century view. |

#### Return value

Returns nonzero if successful, or zero otherwise.

---

### SetCursel

Sets the currently selected date for a month calendar control. If the specified date is not in view, the control updates the display to bring it into view.

```
FUNCTION FUNCTION SetCurSel (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS LONG
FUNCTION SetCurSel (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *pst* | Pointer to a **SYSTEMTIME** structure that contains the date to be set as the current selection. The time members of this structure are ignored. |

#### Return value

Returns nonzero if successful, or zero otherwise. This method will fail if applied to a month calendar control that uses the **MCS_MULTISELECT** style.

---

### SetDayState

Sets the day states for all months that are currently visible within a month calendar control.

```
FUNCTION SetDayState (BYVAL hMonthCal AS HWND, BYVAL cbds AS LONG, BYVAL rgds AS MONTHDAYSTATE PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *cbds* | Value indicating how many elements are in the array that *rgds* points to. |
| *rgds* | Pointer to an array of **MONTHDAYSTATE** values that define how the month calendar control will draw each day in its display. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

An application can explicitly set day state information by using this method, but the state will not persist when a different part of the calendar is scrolled into view. Day state information is usually set in response to the **MCN_GETDAYSTATE** notification code, which is sent whenever the control needs to be refreshed.

The array at *rgds* must contain as many elements as the value returned by the following method:
```
CMonthCal.GetMonthRange(honthCal, GMR_DAYSTATE, NULL)
```
The preceding method returns the total number of months that are in complete or partial view within the month calendar's display.

Keep in mind that the array at rgds must contain **MONTHDAYSTATE** values that correspond with all months currently in the control's display, in chronological order. This includes the two months that may be partially displayed before the first month and after the last month.

---

### SetFirstDayOfWeek

Sets the first day of the week for a month calendar control.

```
FUNCTION SetFirstDayOfWeek (BYVAL hMonthCal AS HWND, BYVAL iDay AS LONG) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *iDay* | Value that specifies which day is to be set as the first day of the week, where 0 is Monday, 1 is Tuesday, and so on. |

#### Return value

Returns a **DWORD** value that contains two values. The high word is a **BOOL** value that is nonzero if the previous first day of the week did not equal **LOCALE_IFIRSTDAYOFWEEK**, or zero otherwise. The low word is an **INT** value that represents the previous first day of the week.

#### Remarks

If the first day of the week is set to anything other than the default (**LOCALE_IFIRSTDAYOFWEEK**), the control will not automatically update first-day-of-the-week changes based on locale changes.

---

### SetMaxSelCount

Sets the maximum number of days that can be selected in a month calendar control.

```
FUNCTION SetMaxSelCount (BYVAL hMonthCal AS HWND, BYVAL iMax AS UINT) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *iMax* | The maximum number of days that can be selected. |

#### Return value

Returns nonzero if successful, or zero otherwise. This method will fail if applied to a month calendar control that does not use the **MCS_MULTISELECT** style.

---

### SetMonthDelta

Sets the scroll rate for a month calendar control. The scroll rate is the number of months that the control moves its display when the user clicks a scroll button.

```
FUNCTION SetMonthDelta (BYVAL hMonthCal AS HWND, BYVAL iDelta AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *iDelta* | Value representing the number of months to be set as the control's scroll rate. If this value is zero, the month delta is reset to the default, which is the number of months displayed in the control. |

#### Return value

Returns a value that represents the previous scroll rate. If the scroll rate was not previously set, the return value is zero.

#### Remarks

The PAGE UP and PAGE DOWN keys, VK_PRIOR and VK_NEXT, change the selected month by one, regardless of the number of months displayed or the value set by **MCM_SETMONTHDELTA**.

---

### SetRange

Sets the minimum and maximum allowable dates for a month calendar control.

```
FUNCTION SetRange (BYVAL hMonthCal AS HWND, BYVAL fWhichLimit AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *fWhichLimit* | Flag values that specify which date limits are being set. This value must be one or both of the following:<br>**GDTR_MAX**: The maximum allowable date is being set. The SYSTEMTIME structure at rgst[1] must contain date information.<br>**GDTR_MIN**: The minimum allowable date is being set. The SYSTEMTIME structure at rgst[0] must contain date information. |
| *rgst* | Pointer to a two-element array of **SYSTEMTIME** structures that contain the date limits. The maximum limit must be in *rgst(1)* if **GDTR_MAX** is specified, and *rgst(0)* must contain the minimum limit if **GDTR_MIN** is specified. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetSelRange

Sets the selection for a month calendar control to a given date range.

```
FUNCTION SetSelRange (BYVAL hMonthCal AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *rgst* | Pointer to a two-element array of **SYSTEMTIME** structures that contain date information representing the selection limits. The first selected date must be specified in *rgst(0)*, and the last selected date must be specified in *rgst(1)*. The time members of these structures are ignored. |

#### Return value

Returns nonzero if successful, or zero otherwise. This macro will fail if applied to a month calendar control that does not use the **MCS_MULTISELECT** style.

---

### SetToday

Sets the "today" selection for a month calendar control. 

```
SUB SetToday (BYVAL hMonthCal AS HWND, BYVAL pst AS SYSTEMTIME PTR)
SUB SetToday (BYVAL hMonthCal AS HWND, BYREF st AS SYSTEMTIME)
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *pst* | Pointer to a **SYSTEMTIME** structure that contains the date to be set as the "today" selection for the control. If this parameter is set to **NULL**, the control returns to the default setting. The time members of this structure are ignored. If the "today" selection is set to any date other than the default, the following conditions apply:<br>* The control will not automatically update the "today" selection when the time passes midnight for the current day.<br>* The control will not automatically update its display based on locale changes. |

---

### SizeRectToMin

Calculates how many calendars will fit in the given rectangle, and then returns the minimum size that a rectangle needs to be to fit that number of calendars.

```
FUNCTION SizeRectToMin (BYVAL hMonthCal AS HWND, BYVAL prc AS RECT PTR) AS LONG
SizeRectToMin (BYVAL hMonthCal AS HWND, BYREF rc AS RECT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hMonthCal* | Handle to a month calendar control. |
| *prc* | On entry, contains a pointer to a **RECT** structure that describes a region that is greater than or equal to the size necessary to fit the desired number of calendars. When this function returns, contains the minimum **RECT** structure that fits this number of calendars. |

---

### Example

```
#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMonthCal.inc"
' // MCN_GETDAYSTATE is wrongly defined in the FreeBasic headers
#undef MCN_GETDAYSTATE
#define MCN_GETDAYSTATE culng(-747)
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_MONTHCAL = 1001
#define BOLDDAY(ds, iDay) ds = ds OR (1 SHL (iDay - 1))

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Month calendar", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Adds the control
   pWindow.AddControl("SysMonthCal32", hWin, IDC_MONTHCAL, "", _
      10, 10, pWindow.ClientWidth - 20, pWindow.ClientHeight - 20, WS_VISIBLE OR WS_TABSTOP OR MCS_DAYSTATE)
   ' // Anchors the control
   pWindow.AnchorControl(IDC_MONTHCAL, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   ' Array to hold day states
   STATIC rgDayState(11) AS MONTHDAYSTATE

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
         ' // Process notification messages
         DIM ptnmsc AS NMSELCHANGE PTR = CAST(NMSELCHANGE PTR, lParam)
         ' // Get selected date
         IF ptnmsc->nmhdr.code = MCN_SELCHANGE THEN
            DIM wszDate AS WSTRING * 260
            wszDate = "Day: " & WSTR(ptnmsc->stSelStart.wDay) & " " & _
                      "Month: " & WSTR(ptnmsc->stSelStart.wMonth) & " " & _
                      "Year: " & WSTR(ptnmsc->stSelStart.wYear)
            SendMessageW hwnd, WM_SETTEXT, 0, CAST(LPARAM, @wszDate)
            ' Note: Don't use MessageBox here or you will get non-stop messages!
            EXIT FUNCTION
         END IF

         ' // Set the day state
         DIM pnmhdr AS LPNMHDR = CAST(LPNMHDR, lParam)
         IF pnmhdr->code = MCN_GETDAYSTATE THEN
            DIM pDayState AS LPNMDAYSTATE = CAST(LPNMDAYSTATE, lParam)
            FOR i AS INTEGER = 0 TO pDayState->cDayState - 1
                rgDayState(i) = 0
                BOLDDAY(rgDayState(i), 1)
                BOLDDAY(rgDayState(i), 15)
            NEXT
            pDayState->prgDayState = @rgDayState(0)
            RETURN TRUE
         END IF


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
