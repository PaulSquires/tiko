# CDtPicker Class

A date and time picker (DTP) control provides a simple and intuitive interface through which to exchange date and time information with a user. For example, with a DTP control you can ask the user to enter a date and then easily retrieve the selection.

See: [About Date and Time Picker Controls](https://learn.microsoft.com/en-us/windows/win32/controls/date-and-time-picker-controls)

**Include file**: CDtPicker.inc

| Name       | Description |
| ---------- | ----------- |
| [CloseMonthCal](#closemonthcal) | Closes the date and time picker (DTP) control. |
| [GetDateTimePickerInfo](#getdatetimepickerinfo) | Gets information for a specified date and time picker (DTP) control. |
| [GetIdealSize](#getidealsize) | Gets the size needed to display the control without clipping. |
| [GetMonthCal](#getmonthcal) | Gets the handle to a date and time picker's (DTP) child month calendar control. |
| [GetMonthCalColor](#getmonthcalcolor) | Gets the color for a given portion of the month calendar within a date and time picker (DTP) control. |
| [GetMonthCalFont](#getmonthcalfont) | Gets the font that the date and time picker (DTP) control's child month calendar control is currently using. |
| [GetMonthCalStyle](#getmonthcalstyle) | Gets the style of a specified date and time picker (DTP) control. |
| [GetRange](#getrange) | Gets the current minimum and maximum allowable system times for a date and time picker (DTP) control. |
| [GetSystemtime](#getsystemtime) | Gets the currently selected time from a date and time picker (DTP) control and places it in a specified SYSTEMTIME structure. |
| [SetFormat](#setformat) | Sets the display of a date and time picker (DTP) control based on a given format string. |
| [SetMonthCalColor](#setmonthcalcolor) | Sets the color for a given portion of the month calendar within a date and time picker (DTP) control. |
| [SetMonthCalFont](#setmonthcalfont) | Sets the font to be used by the date and time picker (DTP) control's child month calendar control. |
| [SetMonthCalStyle](#setmonthcalstyle) | Sets the style for a specified date and time picker (DTP) control. |
| [SetRange](#setrange) | Sets the minimum and maximum allowable system times for a date and time picker (DTP) control. |
| [SetSystemtime](#setsystemtime) | Sets a date and time picker (DTP) control to a given date and time. |

---

### CloseMonthCal

Closes the date and time picker (DTP) control.

```
SUB CloseMonthCal (BYVAL hDtp AS HWND)
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |

#### Remarks

Destroys the control and sends a **DTN_CLOSEUP** notification that the control is closing—as opposed to the control is opening (dropping-down as in the **DTN_DROPDOWN** notification)—to the control's parent.

---

### GetDateTimePickerInfo

Gets information for a specified date and time picker (DTP) control.

```
SUB GetDateTimePickerInfo (BYVAL hDtp AS HWND, BYVAL pdtpi AS DATETIMEPICKERINFO PTR)
SUB GetDateTimePickerInfo (BYVAL hDtp AS HWND, BYREF dtpi AS DATETIMEPICKERINFO)
FUNCTION CDtPicker.GetDateTimePickerInfo (BYVAL hDtp AS HWND) AS DATETIMEPICKERINFO
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *pdtpi* | Pointer to a **DATETIMEPICKERINFO** structure. |

---

### GetIdealSize

Gets the size needed to display the control without clipping.

```
FUNCTION GetIdealSize (BYVAL hDtp AS HWND, BYVAL psize AS SIZE PTR) AS BOOLEAN
FUNCTION GetIdealSize (BYVAL hDtp AS HWND, BYREF sz AS SIZE) AS BOOLEAN
FUNCTION GetIdealSize (BYVAL hDtp AS HWND) AS SIZE
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *pdtpi* | A pointer to a **SIZE** structure to receive the size. |

#### Return value

Returns TRUE.

---

### GetMonthCal

Gets the handle to a date and time picker's (DTP) child month calendar control

```
FUNCTION GetMonthCal (BYVAL hDtp AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |

#### Return value

Returns the handle to a DTP control's child month calendar control.

#### Remarks

DTP controls create a child month calendar control when the user clicks the drop-down arrow (**DTN_DROPDOWN** notification). When the month calendar is no longer needed, it is destroyed (a **DTN_CLOSEUP** notification is sent on destruction). So your application must not rely on a static handle to the DTP's child month calendar.

---

### GetMonthCalColor

Gets the color for a given portion of the month calendar within a date and time picker (DTP) control.

```
FUNCTION GetMonthCalColor (BYVAL hDtp AS HWND, BYVAL iColor AS LONG) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *iColor* | A value of type int specifying which month calendar color to retrieve. This value can be one of the following. |

| Value | Meaning |
| ----- | ------- |
| **MCSC_BACKGROUND** | Retrieve the background color displayed between months. |
| **MCSC_MONTHBK** | Retrieve the background color displayed within the month. |
| **MCSC_TEXT** | Retrieve the color used to display text within a month. |
| **MCSC_TITLEBK** | Retrieve the background color displayed in the calendar's title. |
| **MCSC_TITLETEXT** | Retrieve the color used to display text within the calendar's title. |
| **MCSC_TRAILINGTEXT** | Retrieve the color used to display header day and trailing day text. Header and trailing days are the days from the previous and following months that appear on the current month calendar. |

#### Return value

Returns a COLORREF value that represents the color setting for the specified portion of the month calendar control if successful. Otherwise, the method returns -1.

---

### GetMonthCalFont

Gets the font that the date and time picker (DTP) control's child month calendar control is currently using.

```
FUNCTION GetMonthCalFont (BYVAL hDtp AS HWND) AS HFONT
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |

#### Return value

Returns an **HFONT** value that is the handle to the current font.

---

### GetMonthCalStyle

Gets the style of a specified date and time picker (DTP) control.

```
FUNCTION GetMonthCalStyle (BYVAL hDtp AS HWND) AS LRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |

#### Return value

Returns the style value of the control. For more information see [Month Calendar Control Styles](https://learn.microsoft.com/en-us/windows/win32/controls/month-calendar-control-styles).

---

### GetRange

Gets the current minimum and maximum allowable system times for a date and time picker (DTP) control. 

```
FUNCTION GetRange (BYVAL hDtp AS HWND, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *rgst* | A pointer to a two-element array of **SYSTEMTIME** structures. |

#### Return value

Returns a **DWORD** value that is a combination of **GDTR_MIN** or **GDTR_MAX**. The first element of the **SYSTEMTIME** array contains the minimum allowable time. The second element of the **SYSTEMTIME** array contains the maximum allowable time.

#### Remarks

The date and time picker displays only dates/times that fall within the specified range, preventing the user from selecting a date and time that falls outside the range. If the **CDtPicker.SetSystemtime** message specifies a date and time that falls outside the range, it will fail.

#### Usage example
```
DIM rgst (0 TO 1) AS SYSTEMTIME
print CDtPicker.GetRange(hDtp, @rgst(0))
print rgst(0).wDay
print rgst(0).wMonth
print rgst(0).wYear
print rgst(1).wDay
print rgst(1).wMonth
print rgst(1).wYear
```
---

### GetSystemtime

Gets the currently selected time from a date and time picker (DTP) control and places it in a specified SYSTEMTIME structure.

```
FUNCTION GetSystemtime (BYVAL hDtp AS HWND, BYVAL pst AS SYSTEMTIME PTR) AS DWORD
FUNCTION GetSystemtime (BYVAL hDtp AS HWND, BYREF st AS SYSTEMTIME) AS DWORD
FUNCTION GetSystemtime (BYVAL hDtp AS HWND) AS SYSTEMTIME
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *pst* | A pointer to a **SYSTEMTIME** structure. If **GetSystemTime** returns **GDT_VALID**, this structure will contain the currently selected time. Otherwise, it will not contain valid information. This parameter must be a valid pointer; it cannot be NULL. |

#### Return value

Returns **GDT_VALID** if the time information was successfully placed in pst. Returns **GDT_NONE** if the control was set to the **DTS_SHOWNONE** style and the control check box was not selected. Returns **GDT_ERROR** if an error occurs.

---

### SetFormat

Sets the display of a date and time picker (DTP) control based on a given format string. 

```
SUB SetFormat (BYVAL hDtp AS HWND, BYVAL pwsz AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *pwsz* | A pointer to a zero-terminated format unicode string that defines the desired display. Setting this parameter to NULL will reset the control to the default format string for the current style. |

#### Remarks

It is acceptable to include extra characters within the format string to produce a more rich display. However, any nonformat characters must be enclosed within single quotes. For example, the format string "'Today is: 'hh':'m':'s ddddMMMdd', 'yyy" would produce output like "Today is: 04:22:31 Tuesday Mar 23, 1996".

A DTP control tracks locale changes when it is using the default format string. If you set a custom format string, it will not be updated in response to locale changes.

#### Usage examples
```
CDtPicker.SetFormat(hDtp, "dd.MM.yyyy")
CDtPicker.SetFormat(hDtp, "'Today is: 'hh':'m':'s ddddMMMdd', 'yyy")
```

---

### SetMonthCalColor

Sets the color for a given portion of the month calendar within a date and time picker (DTP) control.

```
FUNCTION SetMonthCalColor (BYVAL hDtp AS HWND, BYVAL iColor AS LONG, BYVAL clr AS COLORREF) AS COLORREF
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *iColor* | A value of type int specifying which month calendar color to set. This value can be one of the following (see table below): |
| *hDtp* | A **COLORREF** value that represents the color that will be set for the specified area of the month calendar. |

| Value | Meaning |
| ----- | ------- |
| **MCSC_BACKGROUND** | Set the background color displayed between months. |
| **MCSC_MONTHBK** | Set the background color displayed within the month. |
| **MCSC_TEXT** | Set the color used to display text within a month. |
| **MCSC_TITLEBK** | Set the background color displayed in the calendar's title. |
| **MCSC_TITLETEXT** | Set the color used to display text within the calendar's title. |
| **MCSC_TRAILINGTEXT** | Set the color used to display header day and trailing day text. Header and trailing days are the days from the previous and following months that appear on the current month calendar. |

#### Retun value

Returns a **COLORREF** value that represents the previous color setting for the specified portion of the month calendar control if successful. Otherwise, this message returns -1

#### Remarks

When visual styles are enabled, this macro has no effect except when *iColor* is **MCSC_BACKGROUND**.

---

### SetMonthCalFont

Sets the font to be used by the date and time picker (DTP) control's child month calendar control.

```
SUB SetMonthCalFont (BYVAL hDtp AS HWND, BYVAL hfont AS HFONT, BYVAL fRedraw AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *hfont* | A handle to the font that will be set. |
| *fRedraw* | Specifies whether the control should be redrawn immediately upon setting the font. Setting this parameter to TRUE causes the control to redraw itself. |

---

### SetMonthCalStyle

Sets the style for a specified date and time picker (DTP) control.

```
FUNCTION SetMonthCalStyle (BYVAL hDtp AS HWND, BYVAL dwStyle AS DWORD) AS LRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *dwStyle* | The month calendar styles. [Month Calendar Control Styles](https://learn.microsoft.com/en-us/windows/win32/controls/month-calendar-control-styles) |

#### Return value

Returns the value of the previous style.

---

### SetRange

Sets the minimum and maximum allowable system times for a date and time picker (DTP) control.

```
FUNCTION SetRange (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYVAL rgst AS SYSTEMTIME PTR) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *gd* | A value that specifies which range values are valid. This value can be a combination of the following:<br>**GDTR_MIN**:  The first element in the SYSTEMTIME structure array is valid and will be used to set the minimum allowable system time.<br>**GDTR_MAX**: The second element in the SYSTEMTIME structure array is valid and will be used to set the maximum allowable system time. |
| *rgst* | A pointer to a two-element array of SYSTEMTIME structures. The first element of the SYSTEMTIME array contains the minimum allowable time. The second element of the SYSTEMTIME array contains the maximum allowable time. It is not necessary to fill an array element that is not specified in the *gd* parameter. |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Remarks

The date and time picker displays only dates/times that fall within the specified range, preventing the user from selecting a date and time that falls outside the range. If the **SetSystemtime** method specifies a date and time that falls outside the range, it will fail.

#### Usage example
```
DIM rgst (0 TO 1) AS SYSTEMTIME
rgst(0).wDay = 1
rgst(0).wMonth = 1
rgst(0).wYear = 2016

rgst(1).wDay = 31
rgst(1).wMonth = 12
rgst(1).wYear = 2026

CDtPicker.SetRange(hDtp, GDTR_MIN OR GDTR_MAX, @rgst(0))
```
---

### SetSystemtime

Sets a date and time picker (DTP) control to a given date and time.

```
FUNCTION SetSystemtime (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYVAL pst AS SYSTEMTIME PTR) AS DWORD
FUNCTION SetSystemtime (BYVAL hDtp AS HWND, BYVAL gd AS DWORD, BYREF st AS SYSTEMTIME) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *hDtp* | A handle to the DTP control. |
| *gd* | A value that specifies which range values are valid. This value can be a combination of the following:<br>**GDT_VALID**:  Set the DTP control according to the data within the SYSTEMTIME structure pointed to by pst.<br>**GDT_NONE**: Set the DTP control to "no date" and clear its check box. When this flag is specified, pst is ignored. This flag applies only to DTP controls that are set to the **DTS_SHOWNONE** style. |
| *pst* | A pointer to a **SYSTEMTIME** structure that contains the system time information by which to set the DTP control. |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Usage example
```
DIM st AS SYSTEMTIME
st.wDay = 15
st.wMonth = 8
st.wYear = 2016
CDtPicker.SetSystemTime(hDtp, GDT_VALID, @st)
```
---

### Example

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CDtPicker.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_LABEL = 1001
CONST IDC_DTPICKER = 1002

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Button", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center
   ' // Set the main window background color
   pWindow.SetBackColor(RGB_OLDLACE)

   pWindow.AddControl("Label", hWin, IDC_LABEL, "Select one date with the mouse", 50, 20, 300, 23)
   DIM htDTP AS HWND = pWindow.AddControl("DateTimePicker", hWin, IDC_DTPICKER, "", 100, 60, 150, 23)
   ' // Anchor the controls
   pWindow.AnchorControl(IDC_LABEL, AFX_ANCHOR_WIDTH)
   pWindow.AnchorControl(IDC_DTPICKER, AFX_ANCHOR_WIDTH)

   ' // Set the date
   DIM st AS SYSTEMTIME
   st.wDay = 15
   st.wMonth = 8
   st.wYear = 2026
   CDtPicker.SetSystemTime(htDTP, GDT_VALID, @st)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
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
         ' // Notification messages
         DIM dtp AS NMDATETIMECHANGE
         CBNMTYPESET(dtp, wParam, lParam)
         IF dtp.nmhdr.idfrom = IDC_DTPICKER THEN
            IF dtp.nmhdr.code = DTN_DATETIMECHANGE THEN
               ' // Get the selected date
               DIM wszDate AS WSTRING * 260
               GetDateFormatW LOCALE_USER_DEFAULT, DATE_LONGDATE, @dtp.st, NULL, wszDate, SIZEOF(wszDate)\2
               SetWindowText(GetDlgItem(hwnd, IDC_LABEL), "Selected date: " & wszDate)
            END IF
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
