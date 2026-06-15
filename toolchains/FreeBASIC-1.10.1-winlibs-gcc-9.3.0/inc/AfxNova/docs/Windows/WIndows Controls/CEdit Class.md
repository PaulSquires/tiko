# CEdit Class

`CEdit` is a class on top of the Edit control. An *edit control* is a rectangular control window typically used in a dialog box to permit the user to enter and edit text by typing on the keyboard. The system automatically processes all user-initiated text operations and notifies the application when the operations are completed.

See: [About Edit Controls](https://learn.microsoft.com/en-us/windows/win32/controls/about-edit-controls)

**Include file**: CEdit.inc.

| Name       | Description |
| ---------- | ----------- |
| [CanUndo](#canundo) | Determines whether there are any actions in an edit control's undo queue. |
| [CharFromPos](#charfrompos) | Gets information about the character closest to a specified point in the client area of an edit control. |
| [Clear](#clear) | Deletes (clears) the current selection, if any, from the edit control. |
| [Copy](#copy) | Copies the current selection to the clipboard in CF_TEXT format. |
| [Cut](#cut) | Deletes (cuts) the current selection, if any, in the edit control and copy the deletedtext to the clipboard in CF_TEXT format. |
| [Disable](#disable) | Disables a button |
| [EmptyUndoBuffer](#emptyundobuffer) | Resets the undo flag of an edit control. |
| [Enable](#enable) | Enables a button. |
| [FmtLines](#fmtlines) | Sets a flag that determines whether a multiline edit control includes soft line-break characters. |
| [GetCueBannerText](#getcuebannertext) | Gets the text that is displayed as the textual cue, or tip, in an edit control. |
| [GetFirstVisibleLine](#getfirstvisibleline) | Gets the zero-based index of the uppermost visible line in a multiline edit control. |
| [GetHandle](#gethandle) | Gets a handle of the memory currently allocated for a multiline edit control's text. |
| [GetIMEStatus](#getimestatus) | Retrieves a set of status flags that indicate how the edit control interacts with the Input Method Editor (IME). |
| [GetLimitText](#getlimittext) | Gets the current text limit for an edit control. The return value is the text limit. |
| [GetLine](#getline) | Copies a line of text from an edit control. |
| [GetLineCount](#getlinecount) | Gets the number of lines in a multiline edit control. |
| [GetMargins](#getmargins) | Returns the width of the left margin in the LOWORD, and the width of the right margin in the HIWORD. |
| [GetLeftMargin](#getleftmargin) | Returns the width of the left margin for an edit control. |
| [GetRightMargin](#getrightmargin) | Returns the width of the right margin for an edit control. |
| [GetModify](#getmodify) | Gets the state of an edit control's modification flag. |
| [GetPasswordChar](#getpasswordchar) | Gets the password character that an edit control displays when the user enters text. |
| [GetRect](#getrect) | Gets the formatting rectangle of an edit control. |
| [GetSel](#getsel) | Gets the starting and ending character positions of the current selection in an edit control. |
| [GetSelStart](#getselstart) | Gets the starting character position of the current selection in an edit control. |
| [GetSelEnd](#getselend) | Gets the ending character position of the current selection in an edit control. |
| [GetText](#gettext) | Retrieves the text from an edit control. |
| [GetTextLength](#gettextlength) | Retrieves the text length from an edit control. |
| [GetThumb](#getthumb) | Gets the position of the scroll box (thumb) in the vertical scroll bar of a multiline edit control. |
| [GetWordBreakProc](#GetWordBreakProc) | Gets the address of the currently registered word-break procedure. |
| [HideBalloonTip](#hideballoontip) | Hides any balloon tip associated with an edit control. |
| [LimitText](#limittext) | Sets the text limit of an edit control. |
| [LineFromChar](#linefromchar) | Gets the index of the line that contains the specified character index in a multiline edit control. |
| [LineIndex](#lineindex) | Gets the character index of the first character of a specified line in a multiline edit control. |
| [LineLength](#linelength) | Retrieves the length, in characters, of a line in an edit control. |
| [LineScroll](#linescoll) | Scrolls the text in a multiline edit control. |
| [Paste](#paste) | Copies the current content of the clipboard to the edit control at the current caretposition. Data is inserted only if the clipboard contains data in CF_TEXT format. |
| [PosFromChar](#posfromchar) | Retrieves the client area coordinates of a specified character in an edit control. |
| [RemoveDarkMode](#removedarkmode) | Removes dark mode from the button. |
| [ReplaceSel](#replacesel) | Replaces the current selection in an edit control with the specified text. |
| [Scroll](#scroll) | Scrolls the text vertically in a multiline edit control. |
| [ScrollCaret](#scrollcaret) | Scrolls the caret into view in an edit control. |
| [SetCueBannerText](#setcuebannertext) | Sets the textual cue, or tip, that is displayed by the edit control to prompt the user for information. |
| [SetCueBannerTextFocused](#setcuebannertextfocused) | Sets the text that is displayed as the textual cue, or tip, for an edit control. |
| [SetDarkMode](#setdarknode) | Sets the dark mode of the edit control. |
| [SetHandle](#sethandle) | Sets the handle of the memory that will be used by a multiline edit control. |
| [SetIMEStatus](#setimestatus) | Sets the status flags that determine how an edit control interacts with the Input Method Editor (IME). |
| [SetLimitText](#limittext) | Sets the text limit of an edit control. |
| [SetMargins](#setmargins) | Sets the widths of the left and right margins for an edit control. |
| [SetLeftMargin](#setleftmargin) | Sets the width of the left margin for an edit control. |
| [SetRightMargin](#setrightmargin) | Sets the width of the left margin for an edit control. |
| [SetModify](#setmodify) | Sets or clears the modification flag for an edit control. |
| [SetPasswordChar](#setpasswordchar) | Sets or removes the password character for an edit control. |
| [SetReadOnly](#setreadonly) | Sets or removes the read-only style (ES_READONLY) of an edit control. |
| [SetRect](#setrect) | Sets the formatting rectangle of a multiline edit control. |
| [SetRectNoPaint](#setrectnopaint) | Sets the formatting rectangle of a multiline edit control, but itdoes not redraw the edit control window. |
| [SetSel](#setsel) | Selects a range of characters in an edit control. |
| [SetTabStops](#settabstops) | Sets the tab stops in a multiline edit control. |
| [SetText](#settext) | Sets the text of an edit control. |
| [SetWordBreakProc](#setwordbreakproc) | ' Replaces an edit control's default Wordwrap function with an application-defined Wordwrap function. |
| [ShowBalloonTip](#showballoontip) | Displays a balloon tip associated with an edit control. |
| [Undo](#undo) | Undoes the last edit control operation in the control's undo queue. |

---

### CanUndo

Determines whether there are any actions in an edit control's undo queue.
```
FUNCTION CanUndo (BYVAL hEdit AS HWND) AS BOOLEAN
```
#### Return value

If there are actions in the control's undo queue, the return value is true. If the undo queue is empty, the return value is false.

#### Usage example
```
CEdit.CanUndo(hEdit)
```
---

### CharFromPos

Gets information about the character closest to a specified point in the client area of an edit control.
```
FUNCTION CharFromPos (BYVAL hEdit AS HWND, BYVAL x AS SHORT, BYVAL y AS SHORT) AS DWORD
```
| Parameter | Description |
| --------- | ----------- |
| x | The x-coordinate of a point in the control's client area. |
| y | The y-coordinate of a point in the control's client area. |

#### Remarks

The coordinates are in screen units and are relative to the upper-left corner of the control's client area.
 
#### Return value

The **LOWORD** specifies the zero-based index of the character nearest the specified point. This index is relative to the beginning of the control, not the beginning of the line. If the specified point is beyond the last character in the edit control, the return value indicates the last character in the control. The **HIWORD** specifies the zero-based index of the line that contains the character. For single-line edit controls, this value is zero. The index indicates the line delimiter if the specified point is beyond the last visible character in a line.

---

### Clear

Sends a message to an edit control to delete (clear) the current selection, if any, from the edit control.
```
SUB Clear (BYVAL hEdit AS HWND)
```
#### Return value

This method does not return a value.

#### Usage example

```
CEdit.Clear(hEdit)
```
---

### Copy

Sends a message to an edit control to copy the current selection to the clipboard in CF_TEXT format.
```
SUB Copy (BYVAL hEdit AS HWND)
```
#### Usage example

```
CEdit.Copy(hEdit)
```
---

### Cut

Sends a message to an edit control to delete (cut) the current selection, if any, in the edit control and copy the deleted text to the clipboard in CF_TEXT format.
```
SUB Cut (BYVAL hEdit AS HWND)
```
#### Usage example

```
CEdit.Cut(hEdit)
```
---

### Disable

Disables mouse and keyboard input to the specified window or control. When input is disabled, the window does not receive input such as mouse clicks and key presses.
```
SUB Disable (BYVAL hEdit AS HWND)
```
#### Return value

Returns FALSE if the control was previously disabled; otherwise TRUE.

#### Usage example

```
CEdit.Disable(hEdit)
```
#### Remarks

If the window is being disabled, the system sends a **WM_CANCELMODE** message. If the enabled state of a window is changing, the system sends a **WM_ENABLE** message after the **WM_CANCELMODE** message. If a window is already disabled, its child windows are implicitly disabled, although they are not sent a **WM_ENABLE** message.

A window must be enabled before it can be activated. For example, if an application is displaying a modeless dialog box and has disabled its main window, the application must enable the main window before destroying the dialog box. Otherwise, another window will receive the keyboard focus and be activated. If a child window is disabled, it is ignored when the system tries to determine which window should receive mouse messages.

By default, a window is enabled when it is created. To create a window that is initially disabled, an application can specify the **WS_DISABLED** style in the **CreateWindow** or **CreateWindowEx** function. After a window has been created, an application can use **EnableWindow** API function to enable or disable the window.

An application can use this function to disable a control in a dialog box. A disabled control cannot receive the keyboard focus, nor can a user gain access to it.

---

### Enable

Enables mouse and keyboard input to the specified window or control. When input is enabled, the window receives all input.
```
SUB Enable (BYVAL hEdit AS HWND)
```
#### Return value

Returns FALSE if the control was previously enabled; otherwise TRUE.

#### Usage example

```
CEdit.Enable(hEdit)
```

#### Remarks

If the window is being disabled, the system sends a **WM_CANCELMODE** message. If the enabled state of a window is changing, the system sends a **WM_ENABLE** message after the **WM_CANCELMODE** message. If a window is already disabled, its child windows are implicitly disabled, although they are not sent a **WM_ENABLE** message.

A window must be enabled before it can be activated. For example, if an application is displaying a modeless dialog box and has disabled its main window, the application must enable the main window before destroying the dialog box. Otherwise, another window will receive the keyboard focus and be activated. If a child window is disabled, it is ignored when the system tries to determine which window should receive mouse messages.

By default, a window is enabled when it is created. To create a window that is initially disabled, an application can specify the **WS_DISABLED** style in the **CreateWindow** or **CreateWindowEx** function. After a window has been created, an application can use the **EnableWindow** API function to enable or disable the window.

An application can use this method to enable a control in a dialog box.

---

### EmptyUndoBuffer

Resets the undo flag of an edit control. The undo flag is set whenever an operation within the edit control can be undone. 
```
SUB EmptyUndoBuffer (BYVAL hEdit AS HWND)
```

#### Remarks

This method empties all undo and redo buffers. The undo flag is automatically reset whenever the edit control receives a **WM_SETTEXT** or **EM_SETHANDLE** message.

#### Usage example

```
CEdit.EmptyUndoBuffer(hEdit)
```
---

### FmtLines

Sets a flag that determines whether a multiline edit control includes soft line-break characters. A soft line break consists of two carriage returns and a line feed and is inserted at the end of a line that is broken because of wordwrapping.
```
SUB FmtLines (BYVAL hEdit AS HWND, BYVAL AddEolFlag AS BOOLEAN) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *AddEolFlag* | A value of TRUE inserts the characters; a value of FALSE removes them. |

#### Return value

The return value is identical to the *AddEolFlag* parameter.

#### Remarks

This message affects only the buffer returned by the **GetHandle** method and the text returned by the **WM_GETTEXT** message. It has no effect on the display of the text within the edit control.

The **EM_FMTLINES** message does not affect a line that ends with a hard line break. A hard line break consists of one carriage return and a line feed.

The size of the text changes when this message is processed.

#### Usage example

```
CEdit.FmtLines(hEdit, TRUE)
```
---

### GetCueBannerText

Gets the text that is displayed as the textual cue, or tip, in an edit control.
```
FUNCTION GetCueBannerText (BYVAL pwszText AS WSTRING PTR, BYVAL cchText AS LONG) AS BOOLEAN
FUNCTION CEdit.GetCueBannerText (BYVAL hEdit AS HWND, BYVAL cchText AS DWORD) AS DWSTRING
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *pwszText* | A pointer to a Unicode buffer that receives the text set as the textual cue. The caller is responsible for allocating the buffer. |
| *cchText* | The size of the buffer pointed to by *pwszText* in characters, including the terminating NULL. |

#### Remarks

To use this method, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### GetFirstVisibleLine

Gets the zero-based index of the uppermost visible line in a multiline edit control.
```
FUNCTION CEdit.GetFirstVisibleLine (BYVAL hEdit AS HWND) AS LONG
```

#### Return value

The return value is the zero-based index of the uppermost visible line in a multiline edit control.

For single-line edit controls, the return value is the zero-based index of the first visible character.

#### Remarks

The number of lines and the length of the lines in an edit control depend on the width of the control and the current Wordwrap setting.

#### Usage example

```
DIM nLine AS LONG = CEdit.GetFirstVisibleLine(hEdit)
```
---

### GetHandle

Gets a handle of the memory currently allocated for a multiline edit control's text.
```
FUNCTION GetHandle (BYVAL hEdit AS HWND) AS HLOCAL
```
#### Return value

The return value is a memory handle identifying the buffer that holds the content of the edit control. If an error occurs, such as sending the message to a single-line edit control, the return value is zero.

#### Remarks

If the function succeeds, the application can access the contents of the edit control by casting the return value to **HLOCAL** and passing it to **LocalLock**. **LocalLock** returns a pointer to a buffer that is a null-terminated array of characters. For example, The application may not change the contents of the buffer. To unlock the buffer, the application calls **LocalUnlock** before allowing the edit control to receive new messages.

If your application cannot abide by the restrictions imposed by **EM_GETHANDLE**, use the **GetWindowTextLength** and **GetWindowText** functions to copy the contents of the edit control into an application-provided buffer.

#### Usage example

```
DIM h AS HLOCAL = CEdit.GetHandle(hEdit)
```
---

### GetIMEStatus

Gets a set of status flags that indicate how the edit control interacts with the Input Method Editor (IME).
```
FUNCTION GetIMEStatus (BYVAL hEdit AS HWND, BYVAL nStatusType AS LONG) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *nStatusType* | The type of status to retrieve. This parameter can be the following value:<br>**EMSIS_COMPOSITIONSTRING**: Sets behavior for handling the composition string. |

#### Return value

Data specific to the type of status to retrieve. With the **EMSIS_COMPOSITIONSTRING** value for *nStatusType*, this return value is one or more of the following values.

| Return code | Description |
| ----------- | ----------- |
| **EIMES_GETCOMPSTRATONCE** | If this flag is set, the edit control hooks the **WM_IME_COMPOSITION** message with fFlags set to **GCS_RESULTSTR** and returns the result string immediately. If this flag is not set, the edit control passes the **WM_IME_COMPOSITION** message to the default window procedure and processes the result string from the **WM_CHAR** message; this is the default behavior of the edit control. |
| **EIMES_CANCELCOMPSTRINFOCUS** | If this flag is set, the edit control cancels the composition string when it receives the **WM_SETFOCUS** message. If this flag is not set, the edit control does not cancel the composition string; this is the default behavior of the edit control. |
| **EIMES_COMPLETECOMPSTRKILLFOCUS** | If this flag is set, the edit control completes the composition string upon receiving the **WM_KILLFOCUS** message. If this flag is not set, the edit control does not complete the composition string; this is the default behavior of the edit control. |

#### Usage example

```
DIM status AS LONG = CEdit.GetIMEStatus(hEdit, EMSIS_COMPOSITIONSTRING)
```
---

### GetLimitText

Gets a set of status flags that indicate how the edit control interacts with the Input Method Editor (IME).
```
FUNCTION GetLimitText (BYVAL hEdit AS HWND) AS DWORD
```
#### Return value

The return value is the text limit.

#### Remarks

The text limit is the maximum amount of text, in characters, that the control can contain.

```
DIM txtLimit AS DWORD = CEdit.GetLimitText(hEdit)
```
---

### GetLine

Copies a line of text from an edit control and places it in a specified buffer. You can send this message to either an edit control or a rich edit control.
```
FUNCTION GetLine (BYVAL hEdit AS HWND, BYVAL which AS DWORD) AS DWSTRING
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *which* | The zero-based index of the line to retrieve from a multiline edit control. A value of zero specifies the topmost line. This parameter is ignored by a single-line edit control. |

#### Return value

The return value is the number of characters copied. The return value is zero if the line number specified by the *which* parameter is greater than the number of lines in the edit control.

#### Remarks

The copied line does not contain a terminating null character.

#### Usage example
```
DIM dwsText AS DWSTRING = CEdit.GetLine(hEdit, 5)
```
---

### GetLineCount

Gets the number of lines in a multiline edit control.
```
FUNCTION GetLineCount (BYVAL hEdit AS HWND) AS LONG
```

#### Return value

The return value is an integer specifying the total number of text lines in the multiline edit control or rich edit control. If the control has no text, the return value is 1. The return value will never be less than 1.

#### Remarks

Retrieves the total number of text lines, not just the number of lines that are currently visible.

If the Wordwrap feature is enabled, the number of lines can change when the dimensions of the editing window change.

#### Usage example
```
DIM lineCount AS LONG = CEdit.GetLineCount(hEdit)
```
---

### GetMargins

Gets the widths of the left and right margins for an edit control.
```
FUNCTION GetMargins (BYVAL hEdit AS HWND) AS DWORD
```

#### Return value

Returns the width of the left margin in the LOWORD, and the width of the right margin in the HIWORD.

#### Usage example
```
DIM dwMargins AS DWORD = CEdit.GetMargins(hEdit)
```
---

### GetLeftMargin

Gets the width of the left margin for an edit control.
```
FUNCTION GetLeftMargin (BYVAL hEdit AS HWND) AS WORD
```

#### Return value

Returns the width of the left margin.

#### Usage example
```
DIM leftMargin AS WORD = CEdit.GetLeftMargin(hEdit)
```
---

### GetRigthMargin

Gets the width of the right margin for an edit control.
```
FUNCTION GetRightMargin (BYVAL hEdit AS HWND) AS WORD
```

#### Return value

Returns the width of the right margin.

#### Usage example
```
DIM rightMargin AS WORD = CEdit.GetRightMargin(hEdit)
```
---

### GetModify

Gets the state of an edit control's modification flag. The flag indicates whether the contents of the edit control have been modified.

```
FUNCTION GetModify (BYVAL hEdit AS HWND) AS BOOLEAN
```

#### Return value

If the contents of edit control have been modified, the return value is TRUE; otherwise, it is FALSE.

#### Remarks

The system automatically clears the modification flag to zero when the control is created. If the user changes the control's text, the system sets the flag to nonzero. You can send the EM_SETMODIFY message to the edit control to set or clear the flag.

#### Usage example
```
DIM bModify AS BOOLEAN = CEdit.GetModify(hEdit)
```
---

### GetPasswordChar

Gets the password character that an edit control displays when the user enters text. 
```
FUNCTION GetPasswordChar (BYVAL hEdit AS HWND) AS LONG
```

#### Return value

The return value specifies the character to be displayed in place of any characters typed by the user. If the return value is NULL, there is no password character, and the control displays the characters typed by the user.

#### Remarks

If an edit control is created with the **ES_PASSWORD** style, the default password character is set to an asterisk (*). If an edit control is created without the **ES_PASSWORD** style, there is no password character. To change the password character, send the **SetPasswordChar** method.

Multiline edit controls do not support the password style or messages.

#### Usage example
```
DIM c AS LOMG = CEdit.GetPasswordChar(hEdit)
```
---

### GetRect

Gets the formatting rectangle of an edit control. The formatting rectangle is the limiting rectangle into which the control draws the text. The limiting rectangle is independent of the size of the edit-control window.

```
SUB CEdit.GetRect (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
SUB GetRect (BYVAL hEdit AS HWND, BYREF rc AS RECT)
FUNCTION GetRect (NYVAL hEdit AS HWND) AS RECT
```
| Parameter | Description |
| --------- | ----------- |
| *prc* | A pointer to a **RECT** structure that receives the formatting rectangle. |
| *rc* | A **RECT** structure that receives the formatting rectangle. |

#### Return value

Gets the formatting rectangle of an edit control. The formatting rectangle is the limiting rectangle into which the control draws the text. The limiting rectangle is independent of the size of the edit-control window.

#### Usage examples
```
DIM rc AS RECT
CEdit.GetRect(hEdit, @rc)
CEdit.GetRect(hEdit, rc)
rc = CEdit.GetRect(hEdit)
```
---

### GetSel

Gets the starting and ending character positions (in characters) of the current selection in an edit control.
```
FUNCTION CEdit.GetSel (BYVAL hEdit AS HWND, BYVAL pdwStartPos AS DWORD PTR, BYVAL pdwEndPos AS DWORD PTR) AS LONG
FUNCTION GetSel (BYVAL hEdit AS HWND, BYREF dwStartPos AS DWORD, BYREF dwEndPos AS DWORD) AS LONG
FUNCTION GetSel (BYVAL hEdit AS HWND) AS POINTL
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control |
| *dwStartPos* | A pointer to a DWORD value that receives the starting position of the selection. This parameter can be NULL. |
| *dwEndPos* | A pointer to a DWORD value that receives the position of the first unselected character after the end of the selection. This parameter can be NULL. |

#### Return value

The starting and ending character positions (in characters) of the current selection in an edit control.

#### Remarks

If there is no selection, the starting and ending values are both the position of the caret.

#### Usage examples
```
DIM AS DWORD dwStartPos, dwEndPos
CEdit.GetSel(hEdit, @dwStartPos, @dwEndPos)
CEdit.GetSel(hEdit, dwStartPos, dwEndPos)
DIM pt AS POINTL
pt = CEdit.GetSel(hEdit)
```
---

### GetSelStart

Gets the starting character position of the current selection in an edit control.
```
FUNCTION GetSelStart (BYVAL hEdit AS HWND) AS DWORD
```

#### Return value

The starting character position of the current selection in an edit control.

#### Remarks

If there is no selection, the starting and ending values are both the position of the caret.

#### Usage example
```
DIM sel AS DWORD = CEdit.GetSelStart(hEdit)
```
---

### GetSelEnd

Gets the ending character position of the current selection in an edit control.
```
FUNCTION GetSelEnd (BYVAL hEdit AS HWND) AS DWORD
```
#### Return value

The ending character position of the current selection in an edit control.

#### Remarks

If there is no selection, the starting and ending values are both the position of the caret.

#### Usage example
```
DIM sel AS DWORD = CEdit.GetSelEnd(hEdit)
```
---

### GetText

Retrieves the text in a edit control.
```
FUNCTION GetText (BYVAL hEdit AS HWND) AS DWSTRING
```
#### Return value

The retrieved text.

#### Usage example

```
DIM dwsText AS DWSTRING = CEdit.GetText(hEdit)
```
---

### GetTextLength

Retrieves the length of the text in a edit control.
```
FUNCTION GetTextLength (BYVAL hEdit AS HWND) AS LONG
```
#### Return value

The length of the text in a edit control.

#### Usage example
```
DIM nLen AS LONG = CEdit.GetTextLength(hEdit)
```
---

### GetThumb

Gets the position of the scroll box (thumb) in the vertical scroll bar of a multiline edit control.
```
FUNCTION GetThumb (BYVAL HEdit AS HWND) AS LONG
```
#### Return value

The position of the scroll box.

#### Usage example

```
DIM nPos AS LONG = CEdit.GetThumb(hEdit)
```
---

### GetWordBreakProc

Gets the address of the current Wordwrap function.
```
FUNCTION GetWordBreakProc (BYVAL hEdit AS HWND) AS LONG_PTR
```
#### Return value

The address of the current Wordwrap function.

#### Usage example

```
DIM proc AS LONG_PTR = CEdit.GetWordBreakProc(hEdit)
```
---

### HideBalloonTip

Hides any balloon tip associated with an edit control.
```
FUNCTION HideBalloonTip (BYVAL hEdit AS HWND) AS BOOLEAN
```
#### Return value

If the method succeeds, it returns TRUE. Otherwise it returns FALSE.

To use this method, you must provide a manifest specifying Comclt32.dll version 6.0.

```
DIM bRes AS BOOLEAN = CEdit.HideBalloonTip(hEdit)
```
---

### <a name="limittext"></a>LimitText / SetLimitText

Sets the text limit of an edit control. The text limit is the maximum amount of text, in characters, that the user can type into the edit control.
```
SUB LimitText (BYVAL hEdit AS HWND, BYVAL chMax AS DWORD)
SUB SetLimitText (BYVAL hEdit AS HWND, BYVAL chMax AS DWORD)
```

| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *chMax* | The maximum number of characters the user can enter. This number does not include the terminating null character. |

#### Usage examples
```
CEdit.LimitText(hEdit, 50)
CEdit.SetLimitText(hEdit, 50)
```
---

### LineFromChar

Gets the index of the line that contains the specified character index in a multiline edit control. A character index is the zero-based index of the character from the beginning of the edit control. 
```
FUNCTION LineFromChar (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *index* | The character index of the character contained in the line whose number is to be retrieved. If this parameter is -1, it retrieves either the line number of the current line (the line containing the caret) or, if there is a selection, the line number of the line containing the beginning of the selection. |

#### Return value

The return value is the zero-based line number of the line containing the character index specified by *index*.

---

### LineIndex

Gets the character index of the first character of a specified line in a multiline edit control. A character index is the zero-based index of the character from the beginning of the edit control.
```
FUNCTION LineIndex (BYVAL hEdit AS HWND, BYVAL nLine AS LONG) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nLine* | The zero-based line number. A value of -1 specifies the current line number (the line that contains the caret). |

#### Return value

The return value is the character index of the line specified in the *nLine* parameter, or it is -1 if the specified line number is greater than the number of lines in the edit control.

---

### LineLength

Retrieves the length, in characters, of a line in an edit control.
```
FUNCTION LineLength (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *index* | The character index of a character in the line whose length is to be retrieved. If this parameter is greater than the number of characters in the control, the return value is zero.This parameter can be -1. In this case, the method returns the number of unselected characters on lines containing selected characters. For example, if the selection extended from the fourth character of one line through the eighth character from the end of the next line, the return value would be 10 (three characters on the first line and seven on the next). |

#### Return value

The length, in characters, of a line in an edit control.

#### Usage example
```
DIM nLen AS LONG = CEdit.LineLength(hEdit, 5)
```
---

### LineScroll

Scrolls the text in a multiline edit control.
```
FUNCTION LineScroll (BYVAL hEdit AS HWND, BYVAL x AS LONG, BYVAL y AS LONG) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *x* | The number of characters to scroll horizontally. |
| *y* | The number of characters to scroll vertically. |

#### Return value

If the message is sent to a multiline edit control, the return value is TRUE.

If the message is sent to a single-line edit control, the return value is FALSE.

#### Remarks

The control does not scroll vertically past the last line of text in the edit control. If the current line plus the number of lines specified by the lParam parameter exceeds the total number of lines in the edit control, the value is adjusted so that the last line of the edit control is scrolled to the top of the edit-control window.

The **LineScroll** method scrolls the text vertically or horizontally in a multiline edit control. It can be used to scroll horizontally past the last character of any line.

---

### <a name="paste"></a>Paste

Copies the current content of the clipboard to the edit control at the current caret position. Data is inserted only if the clipboard contains data in CF_TEXT format.
```
SUB Paste (BYVAL hEdit AS HWND)
```
#### Usage example

```
CEdit.Paste(hEdit)
```
---

### PosFromChar

Retrieves the client area coordinates of a specified character in an edit control.
```
FUNCTION PosFromChar (BYVAL hEdit AS HWND, BYVAL index AS LONG) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *index* | The zero-based index of the character. |

#### Return value

The return value contains the client area coordinates of the character. The **LOWORD** contains the horizontal coordinate and the **HIWORD** contains the vertical coordinate.

#### Remarks

A returned coordinate can be a negative value if the specified character is not displayed in the edit control's client area. The coordinates are truncated to integer values.

If the character is a line delimiter, the returned coordinates indicate a point just beyond the last visible character in the line. If the specified index is greater than the index of the last character in the control, the control returns -1.

---

### ReplaceSel

Replaces the selected text in an edit control or a rich edit control with the specified text.
```
SUB ReplaceSel (BYVAL hEdit AS HWND, BYVAL bCanBeUndone AS BOOLEAN, BYVAL pwszText AS WSTRING PTR)
```
| Parameter | Description |
| --------- | ----------- |
| *bCanBeUndone* | Specifies whether the replacement operation can be undone. If this is TRUE, the operation can be undone. If this is FALSE, the operation cannot be undone. |
| *pwszText* | A pointer to a null-terminated string containing the replacement text. |

#### Remarks

Use the **ReplaceSel** mrthod to replace only a portion of the text in an edit control. To replace all of the text, use the **SetText** method.

If there is no selection, the replacement text is inserted at the caret.

#### Usage example
```
CEdit.ReplaceSel(hEdit, TRUE, "new text")
```
---

### Scroll

Scrolls the text vertically in a multiline edit control. This message is equivalent to sending a **WM_VSCROLL** message to the edit control.
```
FUNCTION Scroll (BYVAL hEdit AS HWND, BYVAL nAction AS LONG) AS DWORD
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nAction* | The action the scroll bar is to take. This parameter can be one of the following values. |

| Value | Meaning |
| ----- | ------- |
| SB_LINEDOWN | Scrolls down one line. |
| SB_LINEUP | Scrolls up one line. |
| SB_PAGEDOWN | Scrolls down one page. |
| SB_PAGEUP | Scrolls up one page. |

#### Return value

If the method is successful, the HIWORD of the return value is TRUE, and the LOWORD is the number of lines that the command scrolls. The number returned may not be the same as the actual number of lines scrolled if the scrolling moves to the beginning or the end of the text. If the wParam parameter specifies an invalid value, the return value is FALSE.

#### Remarks

To scroll to a specific line or character position, use the **LineScroll** method. To scroll the caret into view, use the **ScrollCaret** method.

#### Usage example
```
CEdit.Scroll(hEdit, SB_LINEDOWN)
```
---

### ScrollCaret

Scrolls the caret into view in an edit control.
```
SUB ScrollCaret (BYVAL HEdit AS HWND)
```
#### Return value

This method does not return a value.

#### Usage example
```
CEdit.ScrollCaret(hEdit)
```
---

### SetCueBannerText

Sets the text that is displayed as the textual cue, or tip, for an edit control.
```
SUB SetCueBannerText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR, BYVAL fDrawFocused AS BOOLEAN = FALSE) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *pwszText* | A pointer to a Unicode string that contains the text to display as the textual cue. |
| *bDrawFocused* | TRUE if the cue banner should show even when the edit control has focus; otherwise, FALSE. FALSE is the default behavior—the cue banner disappears when the user clicks in the control. |

#### Return value

If the message succeeds, it returns TRUE. Otherwise it returns FALSE.

#### Usage example
```
CEdit.SetCueBanneText(hEdit, "Cue text)
```
---

### SetHandle

Sets the handle of the memory that will be used by a multiline edit control.
```
SUB SetHandle (BYVAL hEdit AS HWND; BYVAL hLocal AS ..HLOCAL)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *hLocal* | A handle to the memory buffer the edit control uses to store the currently displayed text instead of allocating its own memory. If necessary, the control reallocates this memory. |

#### Return value

This method does not return a value.

#### Remarks
Before an application sets a new memory handle, it should call the **GetHandle** method to retrieve the handle of the current memory buffer and should free that memory.

An edit control automatically reallocates the given buffer whenever it needs additional space for text, or it removes enough text so that additional space is no longer needed.

Calling **SetHandle** clears the undo buffer (the **Undo** method returns zero) and the internal modification flag (**GetModify** returns zero). The edit control window is redrawn.

---

### SetIMEStatus

Sets the status flags that determine how an edit control interacts with the Input Method Editor (IME).
```
SUB SetIMEStatus (BYVAL hEdit AS HWND, BYVAL nStatusType AS LONG, BYVAL flags AS DWORD) AS DWORD
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nStatusType* | The type of status to set. This parameter can be **EMSIS_COMPOSITIONSTRING**. |
| *flags* | Data specific to the status type. If *nStatusType* is **EMSIS_COMPOSITIONSTRING**, this parameter can be one or more of the following values. |

| Value | Meaning |
| ----- | ------- |
| **EIMES_GETCOMPSTRATONCE** | If this flag is set, the edit control hooks the **WM_IME_COMPOSITION** message with fFlags set to **GCS_RESULTSTR** and returns the result string immediately. If this flag is not set, the edit control passes the **WM_IME_COMPOSITION** message to the default window procedure and processes the result string from the **WM_CHAR** message; this is the default behavior of the edit control. |
| **EIMES_CANCELCOMPSTRINFOCUS** | If this flag is set, the edit control cancels the composition string when it receives the **WM_SETFOCUS** message. If this flag is not set, the edit control does not cancel the composition string; this is the default behavior of the edit control. |
| **EIMES_COMPLETECOMPSTRKILLFOCUS** | If this flag is set, the edit control completes the composition string upon receiving the **WM_KILLFOCUS** message. If this flag is not set, the edit control does not complete the composition string; this is the default behavior of the edit control. |

#### Return value

Returns the previous value of the *flags* parameter.

---

### SetMargins

Sets the widths of the left and right margins for an edit control. The message redraws the control to reflect the new margins.
```
SUB SetMargins (BYVAL hEdit AS HWND, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nMargins* | One or more of the following values:<br>**EC_LEFTMARGIN**: Sets the left margin.<br>**EC_RIGHTMARGIN**: Sets the right margin. |
| *nWidth* | The low-order word specifies the new width of the left margin, in pixels. The high-order word specifies the new width of the right margin, in pixels. |

#### Return value

This method does not return a value.

---

### SetLeftMargin

Sets the width of the left margin for an edit control. The message redraws the control to reflect the new margins.
```
SUB SetLeftMargin (BYVAL hEdit AS HWND, BYVAL nWidth AS WORD)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nWidth* | The new width of the left margin, in pixels. |

#### Usage example
```
CEdit.SetLeftMargin(hEdit, 30)
```
---

### SetRightMargin

Sets the width of the right margin for an edit control. The message redraws the control to reflect the new margins.
```
SUB SetRightMargin (BYVAL hEdit AS HWND, BYVAL nWidth AS WORD)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nWidth* | The new width of the right margin, in pixels. |

#### Usage example
```
CEdit.SetRightMargin(hEdit, 30)
```
---

### SetModify

Sets or clears the modification flag for an edit control. The modification flag indicates whether the text within the edit control has been modified.
```
SUB SetModify (BYVAL hEdit AS HWND, BYVAL bModify AS BOOLEAN)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *bModify* | The new value for the modification flag. A value of TRUE indicates the text has been modified, and a value of FALSE indicates it has not been modified. |

#### Usage example
```
CEdit.SetModify(hEdit, TRUE)
```
---

### SetPasswordChar

Sets or removes the password character for an edit control. When a password character is set, that character is displayed in place of the characters typed by the user.
```
SUB SetPasswordChar (BYVAL hEdit AS HWND, BYVAL dwchar AS DWORD)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *dwchar* | The character to be displayed in place of the characters typed by the user. If this parameter is zero, the control removes the current password character and displays the characters typed by the user. |

#### Remarks

When an edit control receives the **EM_SETPASSWORDCHAR** message, the control redraws all visible characters using the character specified by the *dwchar* parameter. If *dwchar* is zero, the control redraws all visible characters using the characters typed by the user.

If an edit control is created with the **ES_PASSWORD** style, the default password character is set to an asterisk (*). If an edit control is created without the **ES_PASSWORD** style, there is no password character. The **ES_PASSWORD** style is removed if the **SetPasswordChar** method is called with the *dwchar* parameter set to zero.

Multiline edit controls do not support the password style or messages.

---

### SetReadOnly

Sets or removes the read-only style (**ES_READONLY**) of an edit control.
```
FUNCTION SetReadOnly (BYVAL hEdit AS HWND, BYVAL bReadOnly AS BOOLEAN) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *bReadOnly* | Specifies whether to set or remove the **ES_READONLY** style. A value of TRUE sets the **ES_READONLY** style; a value of FALSE removes the **ES_READONLY** style. |

#### Return value

If the operation succeeds, the return value is TRUE. If the operation fails, the return value is FALSE.

#### Remarks

When an edit control has the **ES_READONLY** style, the user cannot change the text within the edit control.

To determine whether an edit control has the **ES_READONLY** style, use the **GetWindowLong** function with the **GWL_STYLE** flag.

#### Usage example
```
CEdit.SetReadOnly(hEdit, TRUE)
```
---

### SetRect

Sets the formatting rectangle of a multiline edit control. The formatting rectangle is the limiting rectangle into which the control draws the text. The limiting rectangle is independent of the size of the edit control window. This message is processed only by multiline edit controls.
```
SUB SetRect (BYVAL hEdit AS HWND, BYVAL prc AS RECT PTR)
SUB SetRect (BYVAL hEdit AS HWND, BYREF rc AS RECT)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *prc* | A pointer to a **RECT** structure that specifies the new dimensions of the rectangle. If this parameter is NULL, the formatting rectangle is set to its default values. |
| *rc* | A **RECT** structure that specifies the new dimensions of the rectangle. If this parameter is NULL, the formatting rectangle is set to its default values. |

#### Remarks

Setting *prc* to NULL has no effect if a touch device is installed, or if **SetRect** is called from a thread that has a hook installed (see **SetWindowsHookEx**). In these cases, *prc* should contain a valid pointer to a **RECT** structure.

The **SetRect** method causes the text of the edit control to be redrawn. To change the size of the formatting rectangle without redrawing the text, use the **SetRectNoPaint** method.

When an edit control is first created, the formatting rectangle is set to a default size. You can use the **SetRect** method to make the formatting rectangle larger or smaller than the edit control window.

If the edit control does not have a horizontal scroll bar, and the formatting rectangle is set to be larger than the edit control window, lines of text exceeding the width of the edit control window (but smaller than the width of the formatting rectangle) are clipped instead of wrapped.

If the edit control contains a border, the formatting rectangle is reduced by the size of the border. If you are adjusting the rectangle returned by an **GetRect** method, you must remove the size of the border before using the rectangle with the **SetRect** method.

---

### SetRectNoPaint

Sets the formatting rectangle of a multiline edit control. The **SetRectNoPain** method is identical to the **SetRect** message, except that **SetRectNoPaint** does not redraw the edit control window.

The formatting rectangle is the limiting rectangle into which the control draws the text. The limiting rectangle is independent of the size of the edit control window.

This message is processed only by multiline edit controls.
```
SUB SetRectNoPaint (BYVAL hEdit AS HWND, BYREF rc AS RECT)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *prc* | A pointer to a **RECT** structure that specifies the new dimensions of the rectangle. If this parameter is NULL, the formatting rectangle is set to its default values. |
| *rc* | A **RECT** structure that specifies the new dimensions of the rectangle. If this parameter is NULL, the formatting rectangle is set to its default values. |

---

### SetSel

Selects a range of characters in an edit control. 
```
SUB SetSel (BYVAL hEdit AS HWND, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *nStart* | The starting character position of the selection. |
| *nEnd* | The ending character position of the selection. |

#### Return value

This method does not return a value.

#### Remarks

The start value can be greater than the end value. The lower of the two values specifies the character position of the first character in the selection. The higher value specifies the position of the first character beyond the selection.

The start value is the anchor point of the selection, and the end value is the active end. If the user uses the SHIFT key to adjust the size of the selection, the active end can move but the anchor point remains the same.

If the start is 0 and the end is -1, all the text in the edit control is selected. If the start is -1, any current selection is deselected.

The control displays a flashing caret at the end position regardless of the relative values of start and end.

#### Usage example
```
CEdit.SetSel(hEdit, 10, 20)
```
---

### SetTabPos

Sets the tab stops in a multiline edit control. When text is copied to the control, any tab character in the text causes space to be generated up to the next tab stop. This message is processed only by multiline edit controls.
```
FUNCTION SetTabStops (BYVAL hEdit AS HWND, BYVAL cTabs AS LONG, BYVAL prgTabStops AS LONG) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *cTabs* | The number of tab stops contained in the array. If this parameter is zero, the *prgTabStops* parameter is ignored and default tab stops are set at every 32 dialog template units. If this parameter is 1, tab stops are set at every n dialog template units, where n is the distance pointed to by the *prgTabStops* parameter. If this parameter is greater than 1, *prgTabStops* is a pointer to an array of tab stops. |
| *prgTabStops* | A pointer to an array of unsigned integers specifying the tab stops, in dialog template units. If the *cTabs* parameter is 1, this parameter is a pointer to an unsigned integer containing the distance between all tab stops, in dialog template units. |

#### Remarks

This method does not automatically redraw the edit control window. If the application is changing the tab stops for text already in the edit control, it should call the **InvalidateRect** function to redraw the edit control window.

The values specified in the array are in dialog template units, which are the device-independent units used in dialog box templates. To convert measurements from dialog template units to screen units (pixels), use the **MapDialogRect** function.

---

### SetText

Changes the text of the edit control.
```
FUNCTION SetText (BYVAL hEdit AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *pwszText* | The new text. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE.

#### Remarks

The **SetText** method does not expand tab characters (ASCII code 0x09). Tab characters are displayed as vertical bar (|) characters.

#### Usage example
```
CEdit.SetTextl(hEdit, "New text")
```
---

### SetWordBreakProc

Replaces an edit control's default Wordwrap function with an application-defined Wordwrap function. You can send this message to either an edit control or a rich edit control.
```
SUB SetWordBreakProc (BYAL hEdit AS HWND, BYVAL pfn AS LONG_PTR)
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *pfn* | The address of the application-defined Wordwrap function. For more information about breaking lines, see the description of the [EditWordBreakProc](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nc-winuser-editwordbreakprocw) callback function. |

#### Remarks

A Wordwrap function scans a text buffer that contains text to be sent to the screen, looking for the first word that does not fit on the current screen line. The Wordwrap function places this word at the beginning of the next line on the screen.

A Wordwrap function defines the point at which the system should break a line of text for multiline edit controls, usually at a space character that separates two words. Either a multiline or a single-line edit control might call this function when the user presses arrow keys in combination with the CTRL key to move the caret to the next word or previous word. The default Wordwrap function breaks a line of text at a space character. The application-defined function may define the Wordwrap to occur at a hyphen or a character other than the space character.

---

### <a name="showballoontip"></a>ShowBalloonTip

Displays a balloon tip associated with an edit control.
```
FUNCTION ShowBalloonTip (BYVAL hEdit AS HWND, BYVAL peditballoontip AS EDITBALLOONTIP PTR) AS BOOLEAN
FUNCTION ShowBalloonTip (BYVAL hEdit AS HWND, BYREF edittip AS EDITBALLOONTIP) AS BOOLEAN
FUNCTION ShowBalloonTip (BYVAL hEdit AS HWND, BYVAL pwszTitle AS WSTRING PTR, _
   BYVAL pwszText AS WSTRING PTR, BYVAL iIcon AS LONG) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hEdit* | The handle of the edit control. |
| *peditballoontip* | A pointer to an **EDITBALLOONTIP** structure that contains information about the balloon tip to display. |
| *pwszTitle* | The title of the ballon tip. |
| *pwszText* | The text of the ballon tip. |
| *iIcon* | type of icon to associate with the balloon tip. This member can be one of the following values. |

| Value | Meaning |
| ----- | ------- |
| *TTI_ERROR* | Use the error icon. |
| *TTI_INFO* | Use the information icon. |
| *TTI_NONE* | Use no icon. |
| *TTI_WARNING* | Use the warning icon. |
| *TTI_INFO_LARGE* | Use the large information icon. This is assumed to be an HICON value. |
| *TTI_WARNING_LARGE* | Use the large warning icon. This is assumed to be an HICON value. |
| *TTI_ERROR_LARGE* | Use the large error icon. This is assumed to be an HICON value. |

#### Return value

If the message succeeds, it returns TRUE. Otherwise it returns FALSE.

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### Undo

Undoes the last edit control operation in the control's undo queue.
```
SUB Undo (BYVAL hEdit AS HWND)
```
#### Return value

For a single-line edit control, the return value is always TRUE.

For a multiline edit control, the return value is TRUE if the undo operation is successful, or FALSE if the undo operation fails.

#### Usage example

```
CEdit.Undo(hEdit)
```
#### Remarks

An undo operation can also be undone. For example, you can restore deleted text with the first **Undo** message, and remove the text again with a second **Undo** message as long as there is no intervening edit operation.

---


### SetDarkMode

Sets the dark mode of the edit control.

```
FUNCTION SetDarkMode (BYVAL hEdit AS HWND) AS HRESULT
```

#### Example usage
```
CButton.SetDarkMode(hEdit)
```
---

### RemoveDarkMode

Removes dark mode from the button.

```
FUNCTION RemoveDarkMode (BYVAL hEdit AS HWND) AS HRESULT
```

#### Example usage
```
CButton.RemoveDarkMode(hEdit)
```
---
