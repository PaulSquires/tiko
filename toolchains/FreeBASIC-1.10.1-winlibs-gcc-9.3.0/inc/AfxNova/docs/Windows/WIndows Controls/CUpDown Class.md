# CUpDown control

An up-down control is a pair of arrow buttons that the user can click to increment or decrement a value, such as a scroll position or a number displayed in a companion control (called a buddy window).

See: [About Up-Down Controls](https://learn.microsoft.com/en-us/windows/win32/controls/up-down-controls)

**Include file**: CUpDown.inc


| Name       | Description |
| ---------- | ----------- |
| [GetAccel](#getaccel) | Retrieves acceleration information for an up-down control. |
| [GetBase](#getbase) | Retrieves the current radix base (that is, either base 10 or 16) for an up-down control. |
| [GetBuddy](#getbuddy) | Retrieves the handle to the current buddy window. |
| [GetPos](#getpos) | Retrieves the current position of an up-down control with 16-bit precision. |
| [GetPos32](#getpos32) | Returns the 32-bit position of an up-down control. |
| [GetRange](#getrange) | Retrieves the minimum and maximum positions (range) for an up-down control. |
| [GetRange32](#getrange32) | Retrieves the 32-bit range of an up-down control. |
| [SetAccel](#setaccel) | Sets the acceleration for an up-down control. |
| [SetBase](#setbase) | Sets the radix base for an up-down control. The base value determines whether the buddy window displays numbers in decimal or hexadecimal digits. Hexadecimal numbers are always unsigned, and decimal numbers are signed. |
| [SetAccel](#setaccel) | Sets the acceleration for an up-down control. |
| [SetBuddy](#setbuddy) | Sets the buddy window for an up-down control. |
| [SetPos](#setpos) | Sets the current position for an up-down control with 16-bit precision. |
| [SetPos32](#setpos32) | Sets the position of an up-down control with 32-bit precision. |
| [SetRange](#setRange) | Sets the minimum and maximum positions (range) for an up-down control. |
| [SetRange32](#setRange32) | Sets the 32-bit range of an up-down control. |

---

### GetAccel

Retrieves acceleration information for an up-down control.

```
FUNCTION GetAccel (BYVAL hUpDown AS HWND, BYVAL cAccels AS DWORD, BYVAL pAccels AS UDACCEL PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *cAccels* | Number of elements in the array specified by *paccels*. |
| *pAccels* | Pointer to an array of **UDACCEL** structures that receive acceleration information. |

#### Return value

The return value is the number of accelerators currently set for the control.

---

### GetBase

Retrieves the current radix base (that is, either base 10 or 16) for an up-down control.

```
FUNCTION GetBase (BYVAL hUpDown AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |

#### Return value

The return value is the current base value.

---

### GetBuddy

Retrieves the handle to the current buddy window.

```
FUNCTION GetBuddy (BYVAL hUpDown AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |

#### Return value

The return value is the handle to the current buddy window.

---

### GetPos

Retrieves the current position of an up-down control with 16-bit precision.

```
FUNCTION GetPos (BYVAL hUpDown AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |

#### Return value

If successful, the **HIWORD** is set to zero and the **LOWORD** is set to the control's current position. If an error occurs, the **HIWORD** is set to a nonzero value.

#### Remarks

When processing this message, the up-down control updates its current position based on the caption of the buddy window. The up-down control returns an error if there is no buddy window or if the caption specifies an invalid or out-of-range value. Also, an error flag is set in the **HIWORD** of the return if the control is created without the **UDS_SETBUDDYINT** style, even though it returns a valid position value in the **LOWORD** of the return.

If 32-bit values have been enabled for an up-down control with **SetRange32**, this message returns only the lower 16 bits of the position. To retrieve the full 32-bit position, use **GetPos32**.

---

### GetPos32

Returns the 32-bit position of an up-down control.

```
FUNCTION GetPos32 (BYVAL hUpDown AS HWND, BYVAL pfError AS LONG PTR = NULL) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *pfError*| Pointer to a LONG variable that that is set to zero if the value is successfully retrieved or nonzero if an error occurs. If this parameter is set to NULL, errors are not reported. If **SetPos32** is used in a cross-process situation, this parameter must be NULL. |

#### Return value

Returns the position of an up-down control with 32-bit precision. Applications must check the lParam value to determine whether the return value is valid.

#### Remarks

When it processes this message, the up-down control updates its current position based on the caption of the buddy window. It returns an error if there is no buddy window or if the caption specifies an invalid or out-of-range value.

---

### GetRange

Retrieves the minimum and maximum positions (range) for an up-down control.

```
FUNCTION GetRange (BYVAL hUpDown AS HWND) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |

#### Return value

The return value is a 32-bit value that contains the minimum and maximum positions. The **LOWORD** is the maximum position for the control, and the **HIWORD** is the minimum position.

---

### GetRange32

Retrieves the 32-bit range of an up-down control.

```
SUB GetRange32 (BYVAL hUpDown AS HWND, BYVAL pLow AS LONG PTR, BYVAL pHigh AS LONG PTR)
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *pLow* | Pointer to a signed integer that receives the lower limit of the up-down control range. This parameter may be NULL. |
| *pHigh* | Pointer to a signed integer that receives the upper limit of the up-down control range. This parameter may be NULL. |

---

### SetAccel

Sets the acceleration for an up-down control.

```
FUNCTION SetAccel (BYVAL hUpDown AS HWND, BYVAL cAccels AS DWORD, BYVAL pAccels AS UDACCEL PTR) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *cAccels* | Number of **UDACCEL** structures specified by aAccels.. |
| *pAccels* | Pointer to an array of **UDACCEL** structures that contain acceleration information. Elements should be sorted in ascending order based on the nSec member. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetBase

Sets the radix base for an up-down control. The base value determines whether the buddy window displays numbers in decimal or hexadecimal digits. Hexadecimal numbers are always unsigned, and decimal numbers are signed.

```
FUNCTION SetBase (BYVAL hUpDown AS HWND, BYVAL nBase AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *nBase* | New base value for the control. This parameter can be 10 for decimal or 16 for hexadecimal. |

#### Return value

The return value is the previous base value. If an invalid base is given, the return value is zero.

---

### SetBuddy

Sets the buddy window for an up-down control.

```
FUNCTION SetBuddy (BYVAL hUpDown AS HWND, BYVAL hwndBuddy AS HWND) AS HWND
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *hwndBuddy* | Handle to the new buddy window. |

#### Return value

The return value is the handle to the previous buddy window.

---

### SetPos

Sets the current position for an up-down control with 16-bit precision.

```
FUNCTION SetPos (BYVAL hUpDown AS HWND, BYVAL nPos AS SHORT) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *nPos* | New position for the up-down control. If the parameter is outside the control's specified range, lParam will be set to the nearest valid value. |

#### Return value

The return value is the previous position.

#### Remarks

This message only supports 16-bit positions. If 32-bit values have been enabled for an up-down control with **SetRange32**, use **SepPos32**.

---

### SetPos32

Sets the position of an up-down control with 32-bit precision.

```
FUNCTION SetPos32 (BYVAL hUpDown AS HWND, BYVAL nPos AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *nPos* | Variable of type integer that specifies the new position for the up-down control. If the parameter is outside the control's specified range, *nPos* is set to the nearest valid value. |

#### Return value

Returns the previous position.

---

### SetRange

Sets the minimum and maximum positions (range) for an up-down control.

```
SUB SetRange (BYVAL hUpDown AS HWND, BYVAL nUpper AS SHORT, BYVAL nLower AS SHORT)
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *nUpper* | The maximum position for the up-down control. |
| *nLower* | The minimum position for the up-down control. |

#### Remarks

Neither position can be greater than the **UD_MAXVAL** value or less than the **UD_MINVAL** value. In addition, the difference between the two positions cannot exceed **UD_MAXVAL**.

The maximum position can be less than the minimum position. Clicking the up arrow button moves the current position closer to the maximum position, and clicking the down arrow button moves toward the minimum position.

---

### SetRange32

Sets the 32-bit range of an up-down control.

```
SUB SetRange32 (BYVAL hUpDown AS HWND, BYVAL iLow AS LONG, BYVAL iHigh AS LONG)
```

| Parameter | Description |
| --------- | ----------- |
| *hUpDown* | Handle to the up-down control. |
| *iLow* | Signed integer value that represents the new lower limit of the up-down control range. |
| *iHigh* | Signed integer value that represents the new upper limit of the up-down control range. |

---

### Example

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CUpDown.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_UPDOWN = 1001
CONST IDC_EDIT = 1002

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - UpDown control", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Adds a label control
   pWindow.AddControl("Label", hWin, -1, "How many lines?", 80, 55, 100, 23)
   ' // Adds an edit control
   DIM hEdit AS HWND = pWindow.AddControl("Edit", hWin, IDC_EDIT, "", 200, 55, 50, 23)
   ' // Add an UpDown control (the size and position will be automatically adjusted to the buddy control)
   DIM hUpDown AS HWND = pWindow.AddControl("UpDown", hWin, IDC_UPDOWN)
   ' // Set the edit control as buddy of the updown control
   CUpDown.SetBuddy(hUpDown, hEdit)
   ' // Set the base
   CUpDown.SetBase(hUpDown, 10)
   ' // Set the range
   CUpDown.SetRange32(hUpDown, 0, 100)
   ' // Set the default initial value
   CUpDown.SetPos32(hUpDown, 1)
   ' // Set the focus
   SetFocus hEdit

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
         DIM updown AS NMUPDOWN
         CBNMTYPESET(updown, wParam, lParam)
         IF updown.hdr.idFrom = IDC_UPDOWN AND updown.hdr.code = UDN_DELTAPOS THEN
            ' updown.iPos : Up-down control's current position.
            ' updown.iDelta : proposed change in the up-down control's position.
            ' Return nonzero to prevent the change in the control's position, or zero to allow the change.
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
