# CProgBar Class

A progress bar is a window that an application can use to indicate the progress of a lengthy operation.

It consists of a rectangle that is animated as an operation progresses.

See: [About Progress Bar Controls](https://learn.microsoft.com/en-us/windows/win32/controls/progress-bar-control)

**Include file**: CProgBar.inc


| Name       | Description |
| ---------- | ----------- |
| [DeltaPos](#deltapos) | Advances the current position of a progress bar by a specified increment. |
| [GetBarColor](#getbarcolor) | Gets the color of the progress bar. |
| [GetBkColor](#getbkcolor) | Gets the background color of the progress bar. |
| [GetHighLimit](#gethighlimit) | Retrieves the current high limit of a given progress bar control. |
| [GetLowLimit](#getlowlimit) | Retrieves the current low limit of a given progress bar control. |
| [GetMaxRange](#getmaxrange) | Retrieves the current maximum range of a given progress bar control. |
| [GetMinRange](#getminrange) | Retrieves the current minimum range of a given progress bar control. |
| [GetPos](#getpos) | Retrieves the current position of the progress bar. |
| [GetRange](#getrange) | Retrieves information about the current high and low limits of a given progress bar control. |
| [GetState](#getstate) | Returns the current state of the progress bar. |
| [IncPos](#incpos) | Advances the current position for a progress bar by the specified increment. |
| [SetBarColor](#setbarcolor) | Sets the color of the progress indicator bar in the progress bar control. |
| [SetBkColor](#setbkcolor) | Sets the background color in the progress bar. |
| [SetMarquee](#setmarquee) | Sets the progress bar to marquee mode. |
| [SetMarqueeOff](#setmarqueeoff) | Sets the progress bar marquee mode to off. |
| [SetMarqueeOn](#setmarqueeon) | Sets the progress bar to marquee mode. |
| [SetPos](#setpos) | Sets the current position for a progress bar. |
| [SetRange](#setrange) | Sets the current position for a progress bar. |
| [SetRange32](#setrange32) | Sets the minimum and maximum values for a progress bar to 32-bit values. |
| [SetState](#setstate) | Sets the state of the progress bar. |
| [SetStep](#setstep) | Specifies the step increment for a progress bar. |
| [StepIt](#stepit) | Advances the current position for a progress bar by the step increment. |

---

### DeltaPos

Advances the current position of a progress bar by a specified increment and redraws the bar to reflect the new position.

```
FUNCTION DeltaPos (BYVAL hProgBar AS HWND, BYVAL nIncrement AS LONG) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *nIncrement* | Amount to advance the position. |

#### Return value

Returns the previous position.

#### Remarks

If the increment results in a value outside the range of the control, the position is set to the nearest boundary.

The behavior of this message is undefined if it is sent to a control that has the **PBS_MARQUEE** style.

---

### GetBarColor

Gets the color of the progress bar.

```
FUNCTION GetBarColor (BYVAL hProgBar AS HWND) AS COLORREF
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

Returns the color of the progress bar.

#### Remarks

This is the color set by the **PBM_SETBARCOLOR** message. The default value is **CLR_DEFAULT**, which is defined in commctrl.bi.

This function only affects the classic mode, not any visual style.

---

### GetBkColor

Gets the background color of the progress bar.

```
FUNCTION GetBkColor (BYVAL hProgBar AS HWND) AS COLORREF
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

Returns the background color of the progress bar.

#### Remarks

This is the color set by the **PBM_SETBKCOLOR** message. The default value is **CLR_DEFAULT**, which is defined in commctrl.bi.

This function only affects the classic mode, not any visual style.

---

### GetHighLimit

Retrieves the current high limit of a given progress bar control.

```
FUNCTION GetHighLimit (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

The current high limit.

---

### GetLowLimit

Retrieves the current low limit of a given progress bar control.

```
FUNCTION GetLowLimit (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

The current low limit.

---

### GetMaxRange

Retrieves the current maximum range of a given progress bar control.

```
FUNCTION GetMaxRange (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

The current maximum range.

---

### GetMinRange

Retrieves the current minimum range of a given progress bar control.

```
FUNCTION GetMinRange (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

The current minimum range.

---

### GetPos

Retrieves the current position of the progress bar.

```
FUNCTION GetPos (BYVAL hProgBar AS HWND) AS DWORD
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

The current position.

---

### GetRange

Retrieves information about the current high and low limits of a given progress bar control.

```
FUNCTION GetRange (BYVAL hProgBar AS HWND, BYVAL fWhichLimit AS BOOLEAN, BYVAL pPBRange AS PBRANGE PTR) AS LONG
FUNCTION GetRange (BYVAL hProgBar AS HWND, BYVAL fWhichLimit AS BOOLEAN, BYREF range AS PBRANGE) AS LONG
FUNCTION GetRange (BYVAL hProgBar AS HWND, BYVAL fWhichLimit AS BOOLEAN) AS PBRANGE
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *fWhichLimit* | Flag value specifying which limit value is to be used as the message's return value. This parameter can be one of the following values:<br>**TRUE**: Return the low limit.<br>**FALSE**: Return the high limit. |
| *pPBRange* | Pointer to a **PBRANGE** structure that is to be filled with the high and low limits of the progress bar control. If this parameter is set to NULL, the control will return only the limit specified by wParam. |

#### Return value

Returns an INT that represents the limit value specified by wParam. If *pPBRange* is not NULL, *pPBRange* must point to a **PBRANGE** structure that is to be filled with both limit values.

---

### GetState

Gets the state of the progress bar.

```
FUNCTION GetState (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

Returns the current state of the progress bar. One of the following values.

| Return code | Description |
| ----------- | ----------- |
| **PBST_NORMAL** | In progress. |
| **PBST_ERROR** | Error. |
| **PBST_PAUSED** | Paused. |

---

### IncPos

Advances the current position for a progress bar by the specified increment and redraws the bar to reflect the new position.

```
FUNCTION IncPos (BYVAL hProgBar AS HWND, BYVAL nIncVal AS LONG) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *nIncVal* | Signed integer that becomes the new position. If *nIncVal* is outside the range of the control, the position is set to the closest boundary. Do not send this message to a control that has the **PBS_MARQUEE** style. |

---

### SetBarColor

Sets the color of the progress indicator bar in the progress bar control.

```
FUNCTION SetBarColor (BYVAL hProgBar AS HWND, BYVAL clrBar AS COLORREF) AS COLORREF
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *clrBar* | The **COLORREF** value that specifies the new progress indicator bar color. Specifying the **CLR_DEFAULT** value causes the progress bar to use its default progress indicator bar color. |

#### Return value

Returns the previous progress indicator bar color, or **CLR_DEFAULT** if the progress indicator bar color is the default color.

#### Remarks

When visual styles are enabled, this message has no effect.

---

### SetBkColor

Sets the background color in the progress bar.

```
FUNCTION SetBkColor (BYVAL hProgBar AS HWND, BYVAL clrBk AS COLORREF) AS COLORREF
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *clrBk* | **COLORREF** value that specifies the new background color. Specify the **CLR_DEFAULT** value to cause the progress bar to use its default background color. |

#### Return value

Returns the previous background color, or **CLR_DEFAULT** if the background color is the default color.

#### Remarks

When visual styles are enabled, this message has no effect.

---

### SetMarquee

Sets the progress bar to marquee mode. This causes the progress bar to move like a marquee.

```
FUNCTION SetMarquee (BYVAL hProgBar AS HWND, BYVAL fOn AS BOOLEAN, BYVAL dwAnimationSpeed AS DWORD) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *fOn* | Indicates whether to turn the marquee mode on or off. |
| *dwAnimationSpeed* | Time, in milliseconds, between marquee animation updates. If this parameter is zero, the marquee animation is updated every 30 milliseconds. |

#### Return value

Always returns TRUE.

#### Remarks

Use this message when you do not know the amount of progress toward completion but wish to indicate that progress is being made.

Call the **SetMarquee** method to start or stop the animation.

You must set the control style to **PBS_MARQUEE** before attempting to start the animation.

This message requires ComCtl32.dll version 6.00 or later.

---

### SetMarqueeOff

Sets the progress bar marquee mode to off.

```
FUNCTION SetMarqueeOff (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

Always returns TRUE.

#### Remarks

Call the **SetMarqueeOff** method to stop the animation.

This message requires ComCtl32.dll version 6.00 or later.

---

### SetMarqueeOn

Sets the progress bar marquee mode to on.

```
FUNCTION SetMarqueeOn (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

Always returns TRUE.

#### Remarks

Call the **SetMarqueeOn** method to start the animation.

This message requires ComCtl32.dll version 6.00 or later.

---

### SetPos

Sets the current position for a progress bar and redraws the bar to reflect the new position.

```
FUNCTION SetPos (BYVAL hProgBar AS HWND, BYVAL nNewPos AS LONG) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *nNewPos* | Signed integer that becomes the new position. |

#### Return value

Returns the previous position.

#### Remarks

If *nNewPos* is outside the range of the control, the position is set to the closest boundary.

Do not send this message to a control that has the **PBS_MARQUEE** style.

---

### SetRange

Sets the minimum and maximum values for a progress bar and redraws the bar to reflect the new range.

```
FUNCTION SetRange (BYVAL hProgBar AS HWND, BYVAL nMinRange AS WORD, BYVAL nMaxRange AS WORD) AS DWORD
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *nMinRange* | Minimum range value. By default, the minimum value is zero. |
| *nMaxRange* | Maximum range value. This value must be greater than *nMinRange*. By default, the maximum value is 100. |

#### Return value

*nMinRange* specifies the minimum range value, and *nMaxRange* specifies the maximum range value. The minimum range value must not be negative. By default, the minimum value is zero. The maximum range value must be greater than the minimum range value. By default, the maximum range value is 100.

#### Remarks

If you do not set the range values, the system sets the minimum value to 0 and the maximum value to 100. Because this message expresses the range as a 16-bit unsigned integer, it can extend from 0 to 65,535. The minimum value in the range can be from 0 to 65,535. Likewise, the maximum value can be from 0 to 65,535.

To set a larger range, call **SetRange32**.

---

### SetRange32

Sets the minimum and maximum values for a progress bar to 32-bit values, and redraws the bar to reflect the new range.

```
FUNCTION SetRange32 (BYVAL hProgBar AS HWND, BYVAL nMinRange AS LONG, BYVAL nMaxRange AS LONG) AS DWORD
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *nMinRange* | Minimum range value. By default, the minimum value is zero. |
| *nMaxRange* | Maximum range value. This value must be greater than *nMinRange*. By default, the maximum value is 100. |

#### Return value

Returns a **DWORD** value that holds the previous 16-bit low limit in its **LOWORD** and the previous 16-bit high limit in its **HIWORD**. If the previous ranges were 32-bit values, the return value consists of the **LOWORD**s of both 32-bit limits.

---

### SetState

Sets the state of the progress bar.

```
FUNCTION SetState (BYVAL hProgBar AS HWND, BYVAL iState AS LONG) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *iState* | State of the progress bar that is being set. One of the following values. |

| Value | Description |
| ----- | ----------- |
| **PBST_NORMAL** | In progress. |
| **PBST_ERROR** | Error. |
| **PBST_PAUSED** | Paused. |

#### Return value

Returns the previous state.

---

### SetStep

Specifies the step increment for a progress bar. The step increment is the amount by which the progress bar increases its current position whenever it receives a **PBM_STEPIT** message. By default, the step increment is set to 10.

```
FUNCTION SetStep (BYVAL hProgBar AS HWND, BYVAL nStepInc AS LONG) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |
| *nStepInc* | New step increment. |

#### Return value

Returns the previous step increment.

---

### StepIt

Advances the current position for a progress bar by the step increment and redraws the bar to reflect the new position. An application sets the step increment by sending the PBM_SETSTEP message.

```
FUNCTION StepIt (BYVAL hProgBar AS HWND) AS LONG
```

| Name       | Description |
| ---------- | ----------- |
| *hProgBar* | A handle to a progress bar. |

#### Return value

Returns the previous position.

#### Remarks

When the position exceeds the maximum range value, this message resets the current position so that the progress indicator starts over again from the beginning.

---

### Example

Demonstrates the use of the Statusbar and ProgressBar controls.  In this example, the progress bar has been made child of the status bar.

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CStatusBar.inc"
#INCLUDE ONCE "AfxNova/CProgBar.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_START = 1001
CONST IDC_STATUSBAR = 1002
CONST IDC_PROGRESSBAR = 1003

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Status bar with progress bar", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Add a status bar
   DIM hStatusbar AS HWND = pWindow.AddControl("Statusbar", , IDC_STATUSBAR)
   ' // Set the parts
   DIM rgParts(1 TO 2) AS LONG = {pWindow.ScaleX(160), -1}
   IF CStatusBar.SetParts(hStatusBar, 2, @rgParts(1)) THEN
      CStatusBar.Simple(hStatusBar, FALSE)
   END IF

   ' // Adds a progress bar to the status bar
   DIM hProgBar AS HWND = pWindow.AddControl("ProgressBar", hStatusbar, IDC_PROGRESSBAR, "", 0, 2, 160, 18)
   ' // Set the range
   CProgBar.SetRange32(hProgBar, 0, 100)
   ' // Set the initial position
   CProgBar.SetPos(hProgBar, 0)
   ' // Disable theme for the control
   SetWindowTheme(hProgBar, "", "")

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDC_START, "&Start", 20, 20, 75, 23)

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
            CASE IDC_START
               ' // Retrieve the handle to the progress bar
               DIM hProgBar AS HWND = GetDlgItem(GetDlgItem(hwnd, IDC_STATUSBAR), IDC_PROGRESSBAR)
               ' *** Test code ***
               ' // Sets the step increment
               CProgBar.SetStep(hProgBar, 1)
               ' // Draws the bar
               FOR i AS LONG = 1 TO 100
                  ' // Advances the current position for a progress bar by the step
                  ' // increment and redraws the bar to reflect the new position
                  CProgBar.StepIt(hProgBar)
                  SLEEP 10
               NEXT
               ' // Clears the bar by reseting its position to 0
               CProgBar.SetPos(hProgBar, 0)
         END SELECT
         RETURN 0

      CASE WM_SIZE
         ' // Resizes the status bar and redraws it
         DIM hStatusBar AS HWND = GetDlgItem(hwnd, IDC_STATUSBAR)
         SendMessageW hStatusBar, WM_SIZE, wParam, lParam
         InvalidateRect hStatusBar, NULL, CTRUE
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
