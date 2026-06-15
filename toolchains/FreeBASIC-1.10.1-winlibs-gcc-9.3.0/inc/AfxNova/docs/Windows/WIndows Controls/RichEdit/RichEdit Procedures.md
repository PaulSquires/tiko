# RichEdit Procedures

The RichEdit procedures provides detailed descriptions of various procedures related to Rich Edit controls in Windows. It includes a table with procedure names and their descriptions, followed by detailed explanations of each procedure, including their parameters, return values, and usage examples. The procedures cover a wide range of functionalities such as URL detection, autocorrect, clipboard operations, undo/redo actions, character formatting, and various other features and settings for Rich Edit controls.

| Name       | Description |
| ---------- | ----------- |
| [RichEdit_AutoUrlDetect](#richedit_autourldetect) | Enables or disables automatic detection of URLs by a rich edit control. |
| [RichEdit_CallAutocorrectProc](#richedit_callautocorrectproc) | Calls the application-defined autocorrect callback procedure. |
| [RichEdit_CanPaste](#richedit_canpaste) | Determines whether a rich edit control can paste a specified clipboard format. |
| [RichEdit_CanRedo](#richedit_canredo) | Determines whether there are any actions in the rich edit control redo queue. |
| [RichEdit_CanUndo](#richedit_canundo) | Determines whether there are any actions in the rich edit control undo queue. |
| [RichEdit_CharFromPos](#richedit_charfrompos) | Retrieves information about the character closest to a specified point in the client area of a rich edit control. |
| [RichEdit_DisplayBand](#richedit_displayband) | Displays a portion of the contents of a rich edit control, as previously formatted for a device using the EM_FORMATRANGE message. |
| [RichEdit_EmptyUndoBuffer](#richedit_emptyundobuffer) | Resets the undo flag of a rich edit control. The undo flag is set whenever an operation within the rich edit control can be undone. |
| [RichEdit_ExGetSel](#richedit_exgetdel) | Retrieves the starting and ending character positions of the selection in a rich edit control. |
| [RichEdit_ExLimitText](#richedit_exlimittext) | Sets an upper limit to the amount of text the user can type or paste into a rich edit control. |
| [RichEdit_ExLineFromChar](#richedit_exlinefromchar) | Determines which line contains the specified character in a rich edit control. |
| [RichEdit_ExSetSel](#richedit_exsetsel) | Selects a range of characters and/or Component Object Model (COM) objects in a Microsoft Rich Edit control. |
| [RichEdit_FindText](#richedit_findtext) | Finds text within a rich edit control. |
| [RichEdit_FindTextEx](#richedit_findtextex) | Finds text within a rich edit control. |
| [RichEdit_FindWordBreak](#richedit_findwordbreak) | Finds the next word break before or after the specified character position or retrieves information about the character at that position. |
| [RichEdit_FormatRange](#richedit_formatrange) | Formats a range of text in a rich edit control for a specific device. |
| [RichEdit_GetAutoCorrectProc](#richedit_getautovorrectproc) | Gets a pointer to the application-defined **AutoCorrectProc** callback function. |
| [RichEdit_GetAutoUrlDetect](#richedit_getautourldetect) | Indicates whether the auto URL detection is turned on in the rich edit control. |
| [RichEdit_GetBidiOptions](#richedit_getbidioptions) | Indicates the current state of the bidirectional options in the rich edit control. |
| [RichEdit_GetCharFormat](#richedit_getcharformat) | Determines the current character formatting in a rich edit control. |
| [RichEdit_GetCTFModeBias](#richedit_getctfmodebias) | Retrieves the Text Services Framework mode bias values for a Microsoft Rich Edit control. |
| [RichEdit_GetCTFOpenStatus](#richedit_getctfopenstatus) | Determines if the Text Services Framework (TSF) keyboard is open or closed. |
| [RichEdit_GetEditStyle](#richedit_geteditstyle) | Retrieves the current edit style flags. |
| [RichEdit_GetEditStyleEx](#richedit_geteditstyleex) | Retrieves the current extended edit style flags. |
| [RichEdit_GetEllipsisMode](#richedit_getellipsismode) | Retrieves the current ellipsis mode. |
| [RichEdit_GetEllipsisState](#richedit_getellipsisstate) | Retrieves the current ellipsis state. |
| [RichEdit_GetEventMask](#richedit_geteventmask) | Retrieves the event mask for a rich edit control. The event mask specifies which notification messages the control sends to its parent window. |
| [RichEdit_GetFirstVisibleLine](#richedit_getfirstvisibleline) | Retrieves the zero-based index of the uppermost visible line in a multiline rich edit control. |
| [RichEdit_GetHyphenateInfo](#richedit_gethyphenateinfo) | Retrieves information about hyphenation for a Microsoft Rich Edit control. |
| [RichEdit_GetIMEColor](#richedit_getimecolor) | Retrieves the Input Method Editor (IME) composition color. This message is available only in Asian-language versions of the operating system. |
| [RichEdit_GetIMECompMode](#richedit_getimecompMode) | Retrieves the current IME mode for a rich edit control. |
| [RichEdit_GetIMECompText](#richedit_getimecomptext) | Retrieves the Input Method Editor (IME) composition text. |
| [RichEdit_GetIMEModeBias](#richedit_getimemodebias) | Retrieves the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control. |
| [RichEdit_GetIMEOptions](#richedit_getimeoptions) | Retrieves the current Input Method Editor (IME) options. This message is available only in Asian-language versions of the operating system. |
| [RichEdit_GetIMEProperty](#richedit_getimeproperty) | Retrieves the property and capabilities of the Input Method Editor (IME) associated with the current input locale. |
| [RichEdit_GetLangOptions](#richEdit_getlangoptions) | Retrieves a rich edit control's option settings for Input Method Editor (IME) and Asian language support. |
| [RichEdit_GetLimitText](#richedit_getlimittext) | Retrieves the current text limit for a rich edit control. |
| [RichEdit_GetLine](#richedit_getline) | Copies a line of text from a rich edit control. |
| [RichEdit_GetLineCount](#richedit_getlinecount) | Retrieves the number of lines in a multiline rich edit control. |
| [RichEdit_GetModify](#richedit_getmodify) | Retrieves the state of a rich edit control's modification flag. The flag indicates whether the contents of the rich edit control have been modified. |
| [RichEdit_GetOleInterface](#richedit_getoleinterface) | Retrieves an IRichEditOle object that a client can use to access a rich edit control's Component Object Model (COM) functionality. |
| [RichEdit_GetOptions](#richedit_getoptions) | Retrieves rich edit control options. |
| [RichEdit_GetPageRotate](#richedit_getpagerotate) | Deprecated. Retrieves the text layout for a Microsoft Rich Edit control. |
| [RichEdit_GetParaFormat](#richedit_getparaformat) | Retrieves the paragraph formatting of the current selection in a rich edit control. |
| [RichEdit_GetPasswordChar](#richedit_getpasswordchar) | Retrieves the password character that a rich edit control displays when the user enters text. |
| [RichEdit_GetPunctuation](#richedit_getpunctuation) | Retrieves the current punctuation characters for the rich edit control. |
| [RichEdit_GetRect](#richedit_getrect) | Retrieves the formatting rectangle of a rich edit control. |
| [RichEdit_GetRedoName](#richedit_getredoname) | Retrieves the type of the next action, if any, in the control's redo queue. |
| [RichEdit_GetScrollPos](#richedit_getscrollpos) | Obtains the current scroll position of the edit control. |
| [RichEdit_GetSel](#richedit_getsel) | Retrieves the starting and ending character positions of the current selection in a rich edit control. |
| [RichEdit_GetSelText](#richedit_getseltext) | Retrieves the currently selected text in a rich edit control. |
| [RichEdit_GetStoryType](#richedit_getstorytype) | Gets the story type. |
| [RichEdit_GetTableParams](#richedit_gettableparams) | Retrieves the table parameters for a table row and the cell parameters for the specified number of cells. |
| [RichEdit_GetText](#richedit_gettext) | Retrieves the text from a rich edit control. |
| [RichEdit_GetTextEx](#richedit_gettextex) | Retrieves all of the text from the rich edit control in any particular code base you want. |
| [RichEdit_GetTextLength](#richedit_gettextlength) | Retrieves the length of all text in a rich edit control. |
| [RichEdit_GetTextLengthEx](#richedit_gettextlengthex) | Calculates text length in various ways. It is usually called before creating a buffer to receive the text from the control. |
| [RichEdit_GetTextMode](#richedit_gettextmode) | Retrieves the current text mode and undo level of a rich edit control. |
| [RichEdit_GetTextRange](#richedit_gettextrange) | Retrieves a specified range of characters from a rich edit control. |
| [RichEdit_GetThumb](#richedit_getthumb) | Retrieves the position of the scroll box (thumb) in the vertical scroll bar of a multiline rich edit control. |
| [RichEdit_GetTouchOptions](#richedit_gettouchoptions) | Retrieves the touch options that are associated with a rich edit control. |
| [RichEdit_GetTypographyOptions](#richedit_gettypographyoptions) | Returns the current state of the typography options of a rich edit control. |
| [RichEdit_GetUndoName](#richedit_getundoname) | Retrieves the type of the next undo action, if any. |
| [RichEdit_GetWordBreakProc](#richedit_getwordbreakproc) | Retrieves the address of the current Wordwrap function. |
| [RichEdit_GetWordBreakProcEx](#richedit_getwordbreakprocex) | Retrieves the address of the currently registered extended word-break procedure. |
| [RichEdit_GetWordWrapMode](#richedit_getwordwrapmode) | Retrieves the current word wrap and word-break options for the rich edit control. |
| [RichEdit_GetZoom](#richedit_getzoom) | Retrieves the current zoom ratio, which is always between 1/64 and 64. |
| [RichEdit_HideSelection](#richedit_hideselection) | Hides or shows the selection in a rich edit control. |
| [RichEdit_InsertImage](#richedit_insertimage) | Replaces the selection with a blob that displays an image. |
| [RichEdit_InsertTable](#richedit_inserttable) | Inserts one or more identical table rows with empty cells. |
| [RichEdit_IsIME](#richedit_isime) | Determines if current input locale is an East Asian locale. |
| [RichEdit_LimitText](#richedit_limittext) | Sets the text limit of a rich edit control. The text limit is the maximum amount of text, in characters, that the user can type into the edit control. |
| [RichEdit_LineFromChar](#richedit_linefromchar) | Retrieves the index of the line that contains the specified character index in a multiline rich edit control. |
| [RichEdit_LineIndex](#richedit_lineindex) | Retrieves the character index of the first character of a specified line in a multiline rich edit control. |
| [RichEdit_LineLength](#richedit_linelength) | Retrieves the length, in characters, of a line in a rich edit control. |
| [RichEdit_LineScroll](#richedit_linescroll) | Scrolls the text in a multiline rich edit control. |
| [RichEdit_PasteSpecial](#richedit_pastespecial) | Pastes a specific clipboard format in a rich edit control. |
| [RichEdit_PosFromChar](#richedit_posfromchar) | Retrieves the client area coordinates of a specified character in a rich edit control. |
| [RichEdit_Reconversion](#richedit_reconversion) | Invokes the Input Method Editor (IME) reconversion dialog box. |
| [RichEdit_Redo](#richedit_redo) | Redoes the next action in the control's redo queue. |
| [RichEdit_ReplaceSel](#richedit_replacesel) | Replaces the current selection in a rich edit control with the specified text. |
| [RichEdit_RequestResize](#richedit_requestresize) | Forces a rich edit control to send an EN_REQUESTRESIZE notification message to its parent window. |
| [RichEdit_Scroll](#richedit_scroll) | Scrolls the text vertically in a multiline rich edit control. |
| [RichEdit_ScrollCaret](#richedit_scrollcaret) | Scrolls the caret into view in a rich edit control. |
| [RichEdit_SelectionType](#richedit_selectiontype) | Determines the selection type for a rich edit control. |
| [RichEdit_SetAutocorrectProc](#richedit_setautocorrectproc) | Sets a pointer to the application-defined **AutoCorrectProc** callback procedure. |
| [RichEdit_SetBidiOptions](#richedit_setbidioptions) | Sets the current state of the bidirectional options in the rich edit control. |
| [RichEdit_SetBkgndColor](#richedit_setbkgndcolor) | Sets the background color for a rich edit control. |
| [RichEdit_SetCharFormat](#richedit_setcharformat) | Sets character formatting in a rich edit control. |
| [RichEdit_SetCTFModeBias](#richedit_setctfmodebias) | Sets the Text Services Framework (TSF) mode bias for a Microsoft Rich Edit control. |
| [RichEdit_SetCTFOpenStatus](#richedit_setctfopenstatus) | Opens or closes the Text Services Framework (TSF) keyboard. |
| [RichEdit_SetEditStyle](#richedit_seteditstyle) | Sets the current edit style flags. |
| [RichEdit_SetEditStyleEx](#richedit_seteditstyleex) | Sets the current edit style flags for a rich edit control. |
| [RichEdit_SetEllipsisMode](#richedit_setellipsismode) | Sets the current ellipsis mode for a rich edit control. |
| [RichEdit_SetEventMask](#richedit_seteventmask) | Sets the event mask for a rich edit control. |
| [RichEdit_SetFontSize](#richedit_setfontsize) | Sets the font size for the selected text. |
| [RichEdit_SetHyphenateInfo](#richedit_sethyphenateinfo) | Sets the way a Microsoft Rich Edit control does hyphenation. |
| [RichEdit_SetIMEColor](#richedit_setimecolor) | Sets the Input Method Editor (IME) composition color. |
| [RichEdit_SetIMEModeBias](#richedit_setimemodebias) | Sets the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control. |
| [RichEdit_SetIMEOptions](#richedit_setimeoptions) | Sets the Input Method Editor (IME) options. |
| [RichEdit_SetLangOptions](#richedit_setlangoptions) | Sets options for Input Method Editor (IME) and Asian language support in a rich edit control. |
| [RichEdit_SetLimitText](#richedit_setlimittext) | Sets the text limit of a rich edit control. The text limit is the maximum amount of text, in characters, that the user can type into the edit control. |
| [RichEdit_SetMargins](#richedit_setmargins) | Sets the widths of the left and right margins for a rich edit control. The message redraws the control to reflect the new margins. |
| [RichEdit_SetModify](#richedit_setmodify) | Sets or clears the modification flag for a rich edit control. The modification flag indicates whether the text within the rich edit control has been modified. |
| [RichEdit_SetOleCallback](#richedit_setolecallback) | Gives a rich edit control an IRichEditOleCallback object that the control uses to get OLE-related resources and information from the client. |
| [RichEdit_SetOptions](#richedit_setoptions) | Sets the options for a rich edit control. |
| [RichEdit_SetPageRotate](#richedit_setpagerotate) | Deprecated. Sets the text layout for a Microsoft Rich Edit control. |
| [RichEdit_SetPalette](#RichEdit_SetPalette) | Deprecated. Sets the text layout for a Microsoft Rich Edit control. |
| [RichEdit_SetParaFormat](#richedit_setparaformat) | Sets the paragraph formatting for the current selection in a rich edit control. |
| [RichEdit_SetPasswordChar](#richedit_setpasswordchar) | Sets or removes the password character for a rich edit control. When a password character is set, that character is displayed in place of the characters typed by the user. |
| [RichEdit_SetPunctuation](#richedit_setpunctuation) | Sets the punctuation characters for a rich edit control. |
| [RichEdit_SetReadOnly](#richedit_setreadonly) | Sets or removes the read-only style (ES_READONLY) of a rich edit control. |
| [RichEdit_SetRect](#richedit_setrect) | Sets the formatting rectangle of a multiline rich edit control. |
| [RichEdit_SetRectNP](#richedit_setrectnp) | Sets the formatting rectangle of a multiline rich edit control. |
| [RichEdit_SetScrollPos](#richedit_setscrollpos) | Tells the rich edit control to scroll to a particular point. |
| [RichEdit_SetSel](#richedit_setsel) | Selects a range of characters in a rich edit control. |
| [RichEdit_SetStoryType](#richedit_setstorytype) | Sets the story type. |
| [RichEdit_SetTableParams](#richedit_settablearams) | Changes the parameters of rows in a table. |
| [RichEdit_SetTabStops](#richedit_settabstops) | Sets the tab stops in a multiline rich edit control. |
| [RichEdit_SetTargetDevice](#richedit_settargetdevice) | Sets the target device and line width used for WYSIWYG formatting in a rich edit control. |
| [RichEdit_SetText](#richedit_settext) | Sets the text of an edit control. |
| [RichEdit_SetTextExW](#richedit_settextexw) | Combines the functionality of WM_SETTEXT and EM_REPLACESEL and adds the ability to set text using a code page and to use either Rich Text Format (RTF) rich text or plain text. |
| [RichEdit_SetTextMode](#richedit_settextmode) | Sets the text mode or undo level of a rich edit control. |
| [RichEdit_SetTouchOptions](#richedit_settouchoptions) | Sets the touch options associated with a rich edit control. |
| [RichEdit_SetTypographyOptions](#richedit_settypographyoptions) | Sets the text mode or undo level of a rich edit control. |
| [RichEdit_SetUIAName](#richedit_setuiamame) | Sets the name of a rich edit control for UI Automation (UIA). |
| [RichEdit_SetUndoLimit](#richedit_setundolimit) | Sets the maximum number of actions that can stored in the undo queue. |
| [RichEdit_SetWordBreakProc](#richedit_setwordbreakproc) | Replaces a rich edit control's default Wordwrap function with an application-defined wordwrap function. |
| [RichEdit_SetWordBreakProcEx](#richedit_setwordnreakprocex) | Sets the extended word-break procedure. |
| [RichEdit_SetWordWrapMode](#richedit_setwordwrapmode) | Sets the word-wrapping and word-breaking options for the rich edit control. |
| [RichEdit_SetZoom](#richedit_setzoom) | Sets the zoom ratio anywhere between 1/64 and 64. |
| [RichEdit_ShowScrollBar](#richedit_showscrollbar) | Shows or hides one of the scroll bars in the Text Host window. |
| [RichEdit_StopGroupTyping](#richedit_stopgrouptyping) | Stops the control from collecting additional typing actions into the current undo action. |
| [RichEdit_StreamIn](#richedit_streamin) | Replaces the contents of a rich edit control with a stream of data provided by an application defined–EditStreamCallback callback function. |
| [RichEdit_StreamOut](#richedit_streamout) | Causes a rich edit control to pass its contents to an application–defined EditStreamCallback callback function. |
| [RichEdit_Undo](#richedit_undo) | This message undoes the last edit control operation in the control's undo queue. |

---

# RichEdit Helper Procedures

| Name       | Description |
| ---------- | ----------- |
| [RichEdit_GetRtfText](#richedit_getrtftext) | Retrieves formatted text from a Rich Edit control |
| [RichEdit_LoadRtfFromFile](#richedit_loadrtffromfile) | Loads a Rich Text File into a Rich Edit control. |
| [RichEdit_LoadRtfFromResource](#richedit_loadrtffromresource) | Loads a Rich Text Resource File into a Rich Edit control. |
| [RichEdit_SetFont](#richedit_setfont) | Sets the font used by a rich edit control. |

---

## RichEdit_AutoUrlDetect

Enables or disables automatic detection of URLs by a rich edit control.

```
FUNCTION RichEdit_AutoUrlDetect (BYVAL hRichEdit AS HWND, BYVAL fUrlDetect AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fUrlDetect* | Specify 0 to disable automatic link detection, or one of the following values to enable various kinds of detection. |

| fUrlDetect value  | Description |
| --------------- | ----------- |
| AURL_DISABLEMIXEDLGC | **Windows 8**: Disable recognition of domain names that contain labels with characters belonging to more than one of the following scripts: Latin, Greek, and Cyrillic. |
| AURL_ENABLEDRIVELETTERS | **Windows 8**: Recognize file names that have a leading drive specification, such as c:\temp. |
| AURL_ENABLEEA | This value is deprecated; use **AURL_ENABLEEAURLS** instead. |
| AURL_ENABLEEAURLS | Recognize URLs that contain East Asian characters. |
| AURL_ENABLEEMAILADDR | **Windows 8**: Recognize email addresses. |
| AURL_ENABLETELNO | **Windows 8**: Recognize telephone numbers. |
| AURL_ENABLEURL | **Windows 8**: Recognize URLs that include the path. |

#### Return value

If the message succeeds, the return value is zero.

If the message fails, the return value is a nonzero value. For example, the message might fail due to insufficient memory or an invalid detection option.

#### Remarks

If automatic URL detection is enabled (that is, *fUrlDetect* includes **AURL_ENABLEURL**), the rich edit control scans any modified text to determine whether the text matches the format of a URL (or more generally in Windows 8 or later an IRI International Resource Identifier). The control detects URLs that begin with the following scheme names:

- callto
- file
- ftp
- gopher
- http
- https
- mailto
- news
- notes
- nntp
- onenote
- outlook
- prospero
- tel
- telnet
- wais
- webcal

When automatic link detection is enabled, the rich edit control removes the **CFE_LINK** effect from modified text that does not have a format recognized by the control. If your application uses the **CFE_LINK** effect to mark other types of text, do not enable automatic link detection. The rich edit control does not check whether a detected link exists; that responsibility belongs to the client.

A rich edit control sends the [EN_LINK](https://learn.microsoft.com/en-us/windows/win32/controls/en-link) notification when it receives various messages while the mouse pointer is over text that has the **CFE_LINK** effect. 

---

## RichEdit_CallAutocorrectProc

Calls the autocorrect callback function that is stored by the **RichEdit_SetAutocorrectProc** message, provided that the text preceding the insertion point is a candidate for autocorrection.

```
FUNCTION RichEdit_CallAutocorrectProc (BYVAL hRichEdit AS HWND, BYVAL char AS WCHAR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *char* | A character of type **WCHAR**. If this character is a tab (U+0009), and the character preceding the insertion point isn't a tab, then the character preceding the insertion point is treated as part of the autocorrect candidate string instead of as a string delimiter; otherwise, *char* has no effect. |

#### Return value

The return value is zero if the message succeeds, or nonzero if an error occurs.

---

## RichEdit_CanPaste

Determines whether a rich edit control can paste a specified clipboard format.

```
FUNCTION RichEdit_CanPaste (BYVAL hRichEdit AS HWND, BYVAL clipformat AS LONG) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *clipformat* | Specifies the [Clipboard Formats](https://learn.microsoft.com/en-us/windows/win32/dataxchg/clipboard-formats) to try. To try any format currently on the clipboard, set this parameter to zero. |

#### Return value

If the clipboard format can be pasted, the return value is a nonzero value.

If the clipboard format cannot be pasted, the return value is zero.

---

## RichEdit_CanRedo

Determines whether there are any actions in the rich control redo queue.

```
FUNCTION RichEdit_CanRedo (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If there are actions in the control redo queue, the return value is a nonzero value.

If the redo queue is empty, the return value is zero.

---

## RichEdit_CanUndo

Determines whether there are any actions in the rich edit control undo queue.

```
FUNCTION RichEdit_CanUndo (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If there are actions in the control's undo queue, the return value is nonzero.

If the undo queue is empty, the return value is zero.

---

## RichEdit_CharFromPos

Gets information about the character closest to a specified point in the client area of a rich edit control.

```
FUNCTION RichEdit_CharFromPos (BYVAL hRichEdit AS HWND, BYVAL lppl AS POINTL PTR) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lppl* | A pointer to a [POINTL](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-pointl) structure that contains the horizontal and vertical coordinates of a point in the control's client area. The coordinates are in screen units and are relative to the upper-left corner of the control's client area. |

#### Return value

The return value specifies the zero-based character index of the character nearest the specified point. The return value indicates the last character in the edit control if the specified point is beyond the last character in the control.

---

## RichEdit_DisplayBand

Displays a portion of the contents of a rich edit control, as previously formatted for a device using the [EM_FORMATRANGE]([url](https://learn.microsoft.com/en-us/windows/win32/controls/em-formatrange)) message.

```
FUNCTION RichEdit_DisplayBand (BYVAL hRichEdit AS HWND, BYVAL lprc AS RECT PTR) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lprc* | A pointer to a [RECT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect) structure specifying the display area of the device. |

#### Return value

If the operation succeeds, the return value is **TRUE**.

If the operation fails, the return value is **FALSE**.

#### Remarks

Text and Component Object Model (COM) objects are clipped by the rectangle. The application does not need to set the clipping region.

Banding is the process by which a single page of output is generated using one or more separate rectangles, or bands. When all bands are placed on the page, a complete image results. This approach is often used by raster printers that do not have sufficient memory or ability to image a full page at one time. Banding devices include most dot matrix printers as well as some laser printers.

---

## RichEdit_EmptyUndoBuffer

Resets the undo flag of an edit control. The undo flag is set whenever an operation within the edit control can be undone.

```
SUB RichEdit_EmptyUndoBuffer (BYVAL hRichEdit AS HWND)
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

---

## RichEdit_ExGetSel

Retrieves the starting and ending character positions of the selection in a rich edit control.

```
SUB RichEdit_ExGetSel (BYVAL hRichEdit AS HWND, BYVAL lpchr AS CHARRANGE PTR)
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpchr* | A pointer to a [CHARRANGE](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-charrange) structure that receives the selection range. |

#### CHARRANGE structure
```
type _charrange field = 4
	cpMin as LONG
	cpMax as LONG
end type

type CHARRANGE as _charrange
```
| Member  | Description |
| ------- | ----------- |
| *cpMin* | Character position index immediately preceding the first character in the range. |
| *cpMax* | Character position immediately following the last character in the range. |

#### Usage example
```
DIM chrRange AS CHARRANGE
RichEdit_ExGetSel(hRichEdit, @chrRange)
```
---

## RichEdit_ExLimitText

Sets an upper limit to the amount of text the user can type or paste into a rich edit control.

```
SUB RichEdit_ExLimitText (BYVAL hRichEdit AS HWND, BYVAL dwLimit AS DWORD)
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *dwLimit* | Specifies the maximum amount of text that can be entered. If this parameter is zero, the default maximum is used, which is 64K characters. A COM object counts as a single character. |

#### Remarks

The text limit set by the **RichEdit_ExLimitText** message does not limit the amount of text that you can stream into a rich edit control using the **RichEdit_StreamIn** message with the *pedst* parameter set to SF_TEXT. However, it does limit the amount of text that you can stream into a rich edit control using the **RichEdit_StreamIn** message with the *pedst* parameter set set to SF_RTF.

Before **RichEdit_ExLimitText** is called, the default limit to the amount of text a user can enter is 32,767 characters.

---

## RichEdit_ExLineFromChar

Determines which line contains the specified character in a rich edit control.

```
FUNCTION RichEdit_ExLineFromChar (BYVAL hRichEdit AS HWND, BYVAL iIndex AS LONG) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *iIndex* | Zero-based index of the character. |

#### Return value

Returns the zero-based index of the line.

---

## RichEdit_ExSetSel

Selects a range of characters or Component Object Model (COM) objects in a Microsoft Rich Edit control.

```
FUNCTION RichEdit_ExSetSel (BYVAL hRichEdit AS HWND, BYVAL lpcr AS CHARRANGE PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpcr* | A pointer to a [CHARRANGE](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-charrange) structure that specifies the selection range. |

#### CHARRANGE structure
```
type _charrange field = 4
	cpMin as LONG
	cpMax as LONG
end type

type CHARRANGE as _charrange
```
| Member  | Description |
| ------- | ----------- |
| *cpMin* | Character position index immediately preceding the first character in the range. |
| *cpMax* | Character position immediately following the last character in the range. |

#### Return value

The return value is the selection that is actually set.

#### Usage example

```
DIM chrRange AS CHARRANGE = TYPE<CHARRANGE>(3, 12)
RichEdit_ExSetSel(hRichEdit, @chrRange)
```
---

## RichEdit_FindText

Finds text within a rich edit control.

```
FUNCTION RichEdit_FindText (BYVAL hRichEdit AS HWND, BYVAL fOptions AS DWORD, BYVAL lpft AS FINDTEXTW PTR) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fOptions* | Specifies the parameters of the search operation. This parameter can be one or more of the following values.<br>**FR_DOWN**. If set, the operation searches from the end of the current selection to the end of the document. If not set, the operation searches from the end of the current selection to the beginning of the document.<br>**FR_MATCHALEFHAMZA**. By default, Arabic and Hebrew alefs with different accents are all matched by the alef character. Set this flag if you want the search to differentiate between alefs with different accents.<br>**FR_MATCHCASE**. If set, the search operation is case-sensitive. If not set, the search operation is case-insensitive.<br>**FR_MATCHDIAC**. By default, Arabic and Hebrew diacritical marks are ignored. Set this flag if you want the search operation to consider diacritical marks.<br>**FR_MATCHKASHIDA**. By default, Arabic and Hebrew kashidas are ignored. Set this flag if you want the search operation to consider kashidas.<br>**FR_WHOLEWORD**. If set, the operation searches only for whole words that match the search string. If not set, the operation also searches for word fragments that match the search string.|
| *lpft* | A pointer to a [FINDTEXTW](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-findtextw) structure containing information about the find operation. |

#### Return value

If the target string is found, the return value is the zero-based position of the first character of the match. If the target is not found, the return value is -1.

---

## RichEdit_FindTextEx

Finds Unicode text within a rich edit control.

```
FUNCTION RichEdit_FindTextEx (BYVAL hRichEdit AS HWND, BYVAL fOptions AS DWORD, BYVAL lpftexw AS FINDTEXTEXW PTR) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fOptions* | Specifies the parameters of the search operation. This parameter can be one or more of the following values.<br>**FR_DOWN**. If set, the operation searches from the end of the current selection to the end of the document. If not set, the operation searches from the end of the current selection to the beginning of the document.<br>**FR_MATCHALEFHAMZA**. By default, Arabic and Hebrew alefs with different accents are all matched by the alef character. Set this flag if you want the search to differentiate between alefs with different accents.<br>**FR_MATCHCASE**. If set, the search operation is case-sensitive. If not set, the search operation is case-insensitive.<br>**FR_MATCHDIAC**. By default, Arabic and Hebrew diacritical marks are ignored. Set this flag if you want the search operation to consider diacritical marks.<br>**FR_MATCHKASHIDA**. By default, Arabic and Hebrew kashidas are ignored. Set this flag if you want the search operation to consider kashidas.<br>**FR_WHOLEWORD**. If set, the operation searches only for whole words that match the search string. If not set, the operation also searches for word fragments that match the search string.|
| *lpftexw* | A pointer to a [FINDTEXTEXW](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-findtextexw) structure containing information about the find operation. |

#### Return value

If the target string is found, the return value is the zero-based position of the first character of the match. If the target is not found, the return value is -1.

#### Remarks

**RichEdit_FindTextEx** uses the [FINDTEXTEXW](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-findtextexw) structure, while **RichEdit_FindText** uses the [FINDTEXTW](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-findtextw) structure. The difference is that EM_FINDTEXTEXW reports the range of text that was found.

---

## RichEdit_FindWordBreak

Finds the next word break before or after the specified character position or retrieves information about the character at that position.

```
FUNCTION RichEdit_FindWordBreak (BYVAL hRichEdit AS HWND, BYVAL fOperation AS DWORD, BYVAL dwStartPos AS DWORD) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, EM_FINDWORDBREAK, fOperation, dwStartPos)
END FUNCTION
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fOperation* | Specifies the find operation. This parameter can be one of the following values.<br>**WB_CLASSIFY**. Returns the character class and word-break flags of the character at the specified position.<br>**WB_ISDELIMITER**. Returns **TRUE** if the character at the specified position is a delimiter, or **FALSE** otherwise.<br>**WB_LEFT**. Finds the nearest character before the specified position that begins a word.<br>**WB_LEFTBREAK**. Finds the next word end before the specified position. This value is the same as WB_PREVBREAK.<br>**WB_MOVEWORDLEFT**. Finds the next character that begins a word before the specified position. This value is used during CTRL+LEFT ARROW key processing. This value is the similar to WB_MOVEWORDPREV. See Remarks for more information.<br>**WB_MOVEWORDRIGHT**. Finds the next character that begins a word after the specified position. This value is used during CTRL+right key processing. This value is similar to WB_MOVEWORDNEXT. See Remarks for more information.<br>**WB_RIGHT**. Finds the next character that begins a word after the specified position.<br>**WB_RIGHTBREAK**. Finds the next end-of-word delimiter after the specified position. This value is the same as WB_NEXTBREAK. |
| *dwStartPos* | Zero-based character starting position. |

#### Return value

The message returns a value based on the *fOperation* parameter.

| Return code  | Description |
| ------------ | ----------- |
| **WB_CLASSIFY** | Returns the character class and word-break flags of the character at the specified position. |
| **WB_ISDELIMITER** | Returns **TRUE** if the character at the specified position is a delimiter; otherwise it returns **FALSE**. |
| **Others** | Returns the character index of the word break. |

#### Remarks

If *fOperation* is **WB_LEFT** and **WB_RIGHT**, the word-break procedure finds word breaks only after delimiters. This matches the functionality of an edit control. If *fOperation* is **WB_MOVEWORDLEFT** or **WB_MOVEWORDRIGHT**, the word-break procedure also compares character classes and word-break flags.

For information about character classes and word-break flags, see [Word and Line Breaks](https://learn.microsoft.com/en-us/windows/win32/controls/use-word-and-line-break-information).

---

## RichEdit_FormatRange

Formats a range of text in a rich edit control for a specific device.

```
FUNCTION RichEdit_FormatRange (BYVAL hRichEdit AS HWND, BYVAL fRender AS LONG, BYVAL lpfr AS FORMATRANGE PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fRender* | Specifies whether to render the text. If this parameter is not zero, the text is rendered. Otherwise, the text is just measured. |
| *lpfr* | A pointer to a [FORMATRANGE](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-formatrange) structure containing information about the output device, or **NULL** to free information cached by the control. |

#### Return value

This message returns the index of the last character that fits in the region, plus 1.

#### Remarks

This message is typically used to format the content of rich edit control for an output device such as a printer.

After using this message to format a range of text, it is important that you free cached information by sending **EM_FORMATRANGE** again, but with lParam set to **NULL**; otherwise, a memory leak will occur. Also, after using this message for one device, you must free cached information before using it again for a different device.

---

## RichEdit_GetAutoCorrectProc

Gets a pointer to the application-defined [AutoCorrectProc](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-autocorrectproc) callback function.

```
FUNCTION RichEdit_GetAutoCorrectProc (BYVAL hRichEdit AS HWND) AS LONG_PTR
```

#### Return value

Returns a pointer to the application-defined [AutoCorrectProc](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-autocorrectproc) callback function.

---

## RichEdit_GetAutoUrlDetect

Indicates whether the auto URL detection is turned on in the rich edit control.

```
FUNCTION RichEdit_GetAutoUrlDetect (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If auto-URL detection is active, the return value is 1.

If auto-URL detection is inactive, the return value is 0.

#### Remarks

When auto URL detection is on, Microsoft Rich Edit is constantly checking typed text for a valid URL. Rich Edit recognizes URLs that start with these prefixes:

- http:
- file:
- mailto:
- ftp:
- https:
- gopher:
- nntp:
- prospero:
- telnet:
- news:
- wais:
- outlook:

Rich Edit also recognizes standard path names that start with \\\. When Rich Edit locates a URL, it changes the URL text color, underlines the text, and notifies the client using [EN_LINK](https://learn.microsoft.com/en-us/windows/win32/controls/en-link).

---

## RichEdit_GetBidiOptions

Indicates the current state of the bidirectional options in the rich edit control.

```
SUB RichEdit_GetBidiOptions (BYVAL hRichEdit AS HWND, BYVAL lpbo AS BIDIOPTIONS PTR)
   SendMessageW hRichEdit, EM_GETBIDIOPTIONS, 0, cast(LPARAM, lpbo)
END SUB
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpbo* | A pointer to a [BIDIOPTIONS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-bidioptions) structure that receives the current state of the bidirectional options in the rich edit control. |

#### Remarks

This message sets the values of the **wMask** and **wEffects** members to the value of the current state of the bidirectional options in the rich edit control.

---

## RichEdit_GetCharFormat

Determines the character formatting in a rich edit control.

```
FUNCTION RichEdit_GetCharFormat (BYVAL hRichEdit AS HWND, BYVAL fOption AS DWORD, BYVAL lpcf AS CHARFORMATW PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fOption* | Specifies the range of text from which to retrieve formatting. It can be one of the following values.<br>**SCF_DEFAULT** The default character formatting.<br>**SCF_SELECTION** The current selection's character formatting. |
| *lpcf* | A pointer to a [CHARFORMAT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-charformata) structure that receives the attributes of the first character. The **dwMask** member specifies which attributes are consistent throughout the entire selection. For example, if the entire selection is either in italics or not in italics, CFM_ITALIC is set; if the selection is partly in italics and partly not, CFM_ITALIC is not set. |

#### Return value

This message returns the value of the **dwMask** member of the [CHARFORMAT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-charformata) structure.

---

## RichEdit_GetCTFModeBias

Retrieves the Text Services Framework mode bias values for a Microsoft Rich Edit control.

```
FUNCTION RichEdit_GetCTFModeBias (BYVAL hRichEdit AS HWND) AS LONG
   FUNCTION = SendMessageW(hRichEdit, EM_GETCTFMODEBIAS, 0, 0)
END FUNCTION
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The current Text Services Framework mode bias value.

#### Remarks

To get the IME mode bias, call **RichEdit_GetIMEModeBias**.

---

## RichEdit_GetCTFOpenStatus

Determines if the Text Services Framework (TSF) keyboard is open or closed.

```
FUNCTION RichEdit_GetCTFOpenStatus (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If the TSF keyboard is open, the return value is **TRUE**. Otherwise, it is **FALSE**.

---

## RichEdit_GetEditStyle

Retrieves the current edit style flags.

```
FUNCTION RichEdit_GetEditStyle (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

Returns the current edit style flags, which can include one or more of the following values:

| Return code  | Description |
| ------------ | ----------- |
| **SES_BEEPONMAXTEXT** | Rich Edit will call the system beeper if the user attempts to enter more than the maximum characters. |
| **SES_BIDI** | Turns on bidirectional processing. This is automatically turned on by Rich Edit if any of the following window styles are active: WS_EX_RIGHT, WS_EX_RTLREADING, WS_EX_LEFTSCROLLBAR. However, this setting is useful for handling these window styles when using a custom implementation of ITextHost (default: 0). |
| **SES_CTFALLOWEMBED** | **Windows XP with SP1**: Allow embedded objects to be inserted using TSF (default: 0). |
| **SES_CTFALLOWPROOFING** | **Windows XP with SP1**: Allows TSF proofing tips (default: 0). |
| **SES_CTFALLOWSMARTTAG** | **Windows XP with SP1**: Allows TSF SmartTag tips (default: 0). |
| **SES_CTFNOLOCK** | **Windows 8**: Do not allow the TSF lock read/write access. This pauses TSF input. |
| **SES_DEFAULTLATINLIGA** | **Windows 8**: Fonts with an fi ligature are displayed with default OpenType features resulting in improved typography (default: 0). |
| **SES_DRAFTMODE** | **Windows XP with SP1**: Use draft mode fonts to display text. Draft mode is an accessibility option where the control displays the text with a single font; the font is determined by the system setting for the font used in message boxes. For example, accessible users may read text easier if it is uniform, rather than a mix of fonts and styles (default: 0). |
| **SES_EMULATE10** | **Windows 8**: Emulate RichEdit 1.0 behavior.<br>**Note**: If you really want this behavior, use the Windows riched32.dll instead of riched20.dll or msftedit.dll. Riched32.dll had more functionality. |
| **SES_EMULATESYSEDIT** | When this bit is on, rich edit attempts to emulate the system edit control (default: 0). |
| **SES_EXTENDBACKCOLOR** | Extends the background color all the way to the edges of the client rectangle (default: 0). |
| **SES_HIDEGRIDLINES** | **Windows XP with SP1**: If the width of table gridlines is zero, gridlines are not displayed. This is equivalent to the hide gridlines feature in Word's table menu (default: 0). |
| **SES_HYPERLINKTOOLTIPS** | **Windows 8**: When the cursor is over a link, display a tooltip with the target link address (default: 0). |
| **SES_LOGICALCARET** | **Windows 8**: Provide logical caret information instead of a caret bitmap as described in [ITextHost::TxSetCaretPos]([url](https://learn.microsoft.com/en-us/windows/win32/api/textserv/nf-textserv-itexthost-txsetcaretpos))(default: 0). |
| **SES_LOWERCASE** | Converts all input characters to lowercase (default: 0). |
| **SES_MAPCPS** | Obsolete. Do not use. |
| **SES_MULTISELECT** | **Windows 8**: Enable multiselection with individual mouse selections made while the Ctrl key is pressed (default: 0). |
| **SES_NOEALINEHEIGHTADJUST** | **Windows 8**: Do not adjust line height for East Asian text (default: 0 which adjusts the line height by 15%). |
| **SES_NOFOCUSLINKNOTIFY** | Sends EN_LINK notification from links that do not have focus. |
| **SES_NOIME** | Disallows IMEs for this instance of the rich edit control (default: 0). |
| **SES_NOINPUTSEQUENCECHK** | When this bit is on, rich edit does not verify the sequence of typed text. Some languages (such as Thai and Vietnamese) require verifying the input sequence order before submitting it to the backing store (default: 0). |
| **SES_SCROLLONKILLFOCUS** | When KillFocus occurs, scroll to the beginning of the text (character position equal to 0) (default: 0). |
| **SES_SMARTDRAGDROP** | **Windows 8**: Add or delete a space according to the context when dropping text (default: 0). |
| **SES_USECRLF** | Obsolete. Do not use. |
| **SES_WORDDRAGDROP** | **Windows 8**: If word select is active, ensure that the drop location is at a word boundary (default: 0). |
| **SES_UPPERCASE** | Converts all input characters to uppercase (default: 0). |
| **SES_USEAIMM** | Uses the Active IMM input method component that ships with Internet Explorer 4.0 or later (default: 0). |
| **SES_USEATFONT** | **Windows XP with SP1**: Uses an @ font, which is designed for vertical text; this is used with the ES_VERTICAL window style. The name of an @ font begins with the @ symbol, for example, "@Batang" (default: 0, but is automatically turned on for vertical text layout). |
| **SES_USECTF** | **Windows XP with SP1**: Turns on TSF support. (default: 0). |
| **SES_XLTCRCRLFTOCR** | Turns on translation of CRCRLFs to CRs. When this bit is on and a file is read in, all instances of CRCRLF will be converted to hard CRs internally. This will affect the text wrapping. Note that if such a file is saved as plain text, the CRs will be replaced by CRLFs. This is the .txt standard for plain text (default: 0, which deletes CRCRLFs on input). |

---

## RichEdit_GetEditStyleEx

Retrieves the current extended edit style flags.

```
FUNCTION RichEdit_GetEditStyleEx (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

Returns the extended edit style flags, which can include one or more of the following values.

| Return code | Description |
| ----------- | ----------- |
| **SES_EX_HANDLEFRIENDLYURL** | Display friendly name links with the same text color and underlining as automatic links, provided that temporary formatting isn't used or uses text autocolor (default: 0). |
| **SES_EX_MULTITOUCH** | Enable touch support in Rich Edit. This includes selection, caret placement, and context-menu invocation. When this flag is not set, touch is emulated by mouse commands, which do not take touch-mode specifics into account (default: 0). |
| **SES_EX_NOACETATESELECTION** | Display selected text using classic Windows selection text and background colors instead of background acetate color (default: 0). |
| **SES_EX_NOMATH** | Disable insertion of math zones (default: 1). To enable math editing and display, send the **RichEdit_SetEditStyleEx** message with *fStyle* set to 0, and *fMask* set to SES_EX_NOMATH. |
| **SES_EX_NOTABLE** | Disable insertion of tables. The **RichEdit_InsertTable** message returns **E_FAIL** and RTF tables are skipped (default: 0). |
| **SES_EX_USESINGLELINE** | Enable a multiline control to act like a single-line control with the ability to scroll vertically when the single-line height is greater than the window height (default: 0). |
| **SES_HIDETEMPFORMAT** | Hide temporary formatting that is created when **ITextFont.Reset** is called with **tomApplyTmp**. For example, such formatting is used by spell checkers to display a squiggly underline under possibly misspelled words. |
| **SES_EX_USEMOUSEWPARAM** | Use *wParam* when handling the **WM_MOUSEMOVE** message and do not call **GetAsyncKeyState**. |

---

## RichEdit_GetEllipsisMode

Retrieves the current ellipsis mode. When enabled, an ellipsis ( ) is displayed for text that doesn't fit in the display window. The ellipsis is only used when the control is not active. When active, scroll bars are used to reveal text that doesn't fit into the display window.

```
FUNCTION RichEdit_GetEllipsisMode (BYVAL hRichEdit AS HWND, BYVAL pmode AS DWORD PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pmode* | Pointer to a DWORD which receives one of the following values.<br>**ELLIPSIS_NONE**. No ellipsis is used.<br>**ELLIPSIS_END**. Ellipsis at the end (forced break).<br>**ELLIPSIS_WORD**. Ellipsis at the end (word break). |

#### Return value

If *pmode* is not NULL, the return value equals TRUE; otherwise, the return value equals FALSE.

---

## RichEdit_GetEllipsisState

Retrieves the current ellipsis state.

```
FUNCTION RichEdit_GetEllipsisState (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is **TRUE** if an ellipsis is being displayed and **FALSE** otherwise.

---

## RichEdit_GetEventMask

Retrieves the event mask for a rich edit control. The event mask specifies which notification messages the control sends to its parent window.

```
FUNCTION RichEdit_GetEventMask (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

This message returns the event mask for the rich edit control.

---

## RichEdit_GetFirstVisibleLine

Retrieves the zero-based index of the uppermost visible line in a multiline edit control. You can send this message to either an edit control or a rich edit control.

```
FUNCTION RichEdit_GetFirstVisibleLine (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is the zero-based index of the uppermost visible line in a multiline edit control.

For single-line rich edit controls, the return value is zero.

---

## RichEdit_GetHyphenateInfo

Retrieves information about hyphenation for a Microsoft Rich Edit control.

```
SUB RichEdit_GetHyphenateInfo (BYVAL hRichEdit AS HWND, BYVAL lphi AS HYPHENATEINFO PTR)
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lphi* | A pointer to a [HYPHENATEINFO](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-hyphenateinfo) structure. |

---

## RichEdit_GetIMEColor

Retrieves the Input Method Editor (IME) composition color. This message is available only in Asian-language versions of the operating system.

```
FUNCTION RichEdit_GetIMEColor (BYVAL hRichEdit AS HWND, BYVAL rgCmpclr AS COMPCOLOR PTR) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *rgCmpclr* | A four-element array of [COMPCOLOR](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-compcolor) structures that receives the composition color. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

---

## RichEdit_GetIMECompMode

Retrieves the current Input Method Editor (IME) mode for a rich edit control.

```
FUNCTION RichEdit_GetIMECompMode (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is one of the following values.

| Return code | Description |
| ----------- | ----------- |
| **ICM_NOTOPEN** | IME is not open. |
| **ICM_LEVEL3** | True inline mode. |
| **ICM_LEVEL2** | Level 2. |
| **ICM_LEVEL2_5** | Level 2.5. |
| **ICM_LEVEL2_SUI** | Special UI. |

---

## RichEdit_GetIMECompText

Retrieves the Input Method Editor (IME) composition text.

```
FUNCTION RichEdit_GetIMECompText (BYVAL hRichEdit AS HWND, BYVAL lpict AS IMECOMPTEXT PTR, BYVAL buffer AS ANY PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpict* | A pointer to the [IMECOMPTEXT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-imecomptext) structure. |
| *buffer* | The buffer that receives the composition text. The size of this buffer is contained in the *cb* member of the **IMECOMPTEXT** structure. |

#### Return value

If successful, the return value is the number of Unicode characters copied to the buffer. Otherwise, it is zero.

#### Remarks

This message only takes Unicode strings.

**Security Warning**: Be sure to have a buffer sufficient for the size of the input. Failure to do so could cause problems for your application.

---

## RichEdit_GetIMEModeBias

Retrieves the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control.

```
FUNCTION RichEdit_GetIMEModeBias (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

This message returns the current IME mode bias setting.

#### Remarks

To get the Text Services Framework mode bias, use **RichEdit_GetCTFModeBias**.

The application should call **RichEdit_IsIME** before calling this function.

---

## RichEdit_GetIMEOptions

Retrieves the current Input Method Editor (IME) options. This message is available only in Asian-language versions of the operating system.

```
FUNCTION RichEdit_GetIMEOptions (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

This message returns one or more of the IME option flag values described in the **RichEdit_SetIMEOptions** message.

---

## RichEdit_GetIMEProperty

Retrieves the property and capabilities of the Input Method Editor (IME) associated with the current input locale.

```
FUNCTION RichEdit_GetIMEProperty (BYVAL hRichEdit AS HWND, BYVAL figp AS DWORD) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *figp* | Specifies the type of property information to retrieve. This parameter can be one of the following values. |

| Value  | Meaning |
| ------ | ----------- |
| **IGP_PROPERTY** | Property information. |
| **IGP_CONVERSION** | Conversion capabilities. |
| **IGP_SENTENCE** | Sentence mode capabilities. |
| **IGP_UI** | User interface capabilities. |
| **IGP_SETCOMPSTR** | Composition string capabilities. |
| **IGP_SELECT** | Selection inheritance capabilities. |
| **IGP_GETIMEVERSION** | Retrieves the system version number for which the specified IME was created. |

#### Return value

Returns the property or capability value, depending on the value of the *figp* parameter.

#### Remarks

If *figp* is **IGP_PROPERTY**, it returns one or more of the following values.

| Requirement  | Meaning |
| ------------ | ----------- |
| **IME_PROP_AT_CARET** | If set, conversion window is at the caret position. If clear, the window is near caret position. |
| **IME_PROP_SPECIAL_UI** | If set, IME has a nonstandard user interface. The application should not draw in the IME window. |
| **IME_PROP_CANDLIST_START_FROM_1** | If set, strings in the candidate list are numbered starting at 1. If clear, strings start at zero. |
| **IME_PROP_UNICODE** | If set, the IME is viewed as a UnicodeIME. The system and the IME will communicate through the UnicodeIME interface. If clear, IME will use the ANSI interface to communicate with the system. |
| **IME_PROP_COMPLETE_ON_UNSELECT** | If set, conversion window is at the caret position. If clear, the window is near caret position. |
| **IME_PROP_ACCEPT_WIDE_VKEY** | If set, the IME processes the injected Unicode that came from the **SendInput** function by using VK_PACKET. If clear, the IME might not process the injected Unicode, and the injected Unicode might be sent to the application directly. |

If *figp* is **IGP_UI**, it returns one or more of the following values.

| Requirement  | Meaning |
| ------------ | ----------- |
| **UI_CAP_2700** | Supports text escapement values of 0 or 2700. For more information, see **lfEscapement**. |
| **UI_CAP_ROT90** | Supports text escapement values of 0, 900, 1800, or 2700. For more information, see **lfEscapement**. |
| **UI_CAP_ROTANY** | Supports any text escapement value. For more information, see **lfEscapement**. |
	
If *figp* is **IGP_SETCOMPSTR**, it returns one or more of the following values.

| Requirement  | Meaning |
| ------------ | ----------- |
| **SCS_CAP_COMPSTR** | Can create the composition string by calling the **ImmSetCompositionString** function with the SCS_SETSTR value. |
| **SCS_CAP_MAKEREAD** | Can create the reading string from corresponding composition string when using the **ImmSetCompositionString** function with SCS_SETSTR and without setting *lpRead*. |
| **SCS_CAP_SETRECONVERTSTRING** | This IME can support reconversion. Use ImmSetCompositionString to do the reconversion. |

If *figp* is **IGP_SELECT**, it returns one or more of the following values.

| Requirement  | Meaning |
| ------------ | ----------- |
| **SELECT_CAP_CONVMODE** | Inherits conversion mode when a new IME is selected. |
| **SELECT_CAP_SENTENCE** | Inherits sentence mode when a new IME is selected. |

If *figp* is **IGP_GETIMEVERSION**, it returns one or more of the following values.

| Requirement  | Meaning |
| ------------ | ----------- |
| **IMEVER_0310** | The IME was created for Windows 3.1. |
| **IMEVER_0400** | The IME was created for Windows 95 or later. |

This message is similar to **ImmGetProperty**, except that it uses the current input locale. The application should call **RichEdit_IsIME** before calling this function.

---

## RichEdit_GetLangOptions

Retrieves a rich edit control's option settings for Input Method Editor (IME) and Asian language support.

```
FUNCTION RichEdit_GetLangOptions (BYVAL hRichEdit AS HWND) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

Returns the IME and Asian language settings, which can be zero or more of the following values.

| Return code  | Description |
| ------------ | ----------- |
| **IMF_AUTOFONT** | If this flag is set, the control automatically changes fonts when the user explicitly changes to a different keyboard layout. It is useful to turn off **IMF_AUTOFONT** for universal Unicode fonts. This option is turned on by default (1). |
| **IMF_AUTOFONTSIZEADJUST** | If this flag is set, the control scales font-bound font sizes from insertion point size according to script. For example, Asian fonts are slightly larger than Western ones. This option is turned on by default (1). |
| **IMF_AUTOKEYBOARD** | If this flag is set, the control automatically changes the keyboard layout when the user explicitly changes to a different font, or when the user explicitly changes the insertion point to a new location in the text. Will be turned on automatically for bidirectional controls. For all other controls, it is turned off by default. This option is turned off by default (0). |
| **IMF_DISABLEAUTOBIDIAUTOKEYBOARD** | **Windows 8**: If this flag is set, the control uses language neutral logic for automatic keyboard switching. This option is turned off by default (0). |
| **IMF_DUALFONT** | If this flag is set, the control uses dual-font mode. Used for Asian language support. The control uses an English font for ASCII text and a Asian font for Asian text. This option is turned on by default (1). |
| **IMF_IMEALWAYSSENDNOTIFY** | This flag controls how the rich edit control notifies the client during IME composition:<br>0: No **EN_CHANGE** or **EN_SELCHANGE** notifications during undetermined state. Send notification when the final string comes in. This is the default.<br>1: Send **EN_CHANGE** and **EN_SELCHANGE** events during undetermined state. |
| **IMF_IMECANCELCOMPLETE** | This flag determines how the control uses the composition string of an IME if the user cancels it. If this flag is set, the control discards the composition string. If this flag is not set, the control uses the composition string as the result string. This option is turned off by default (0). |
| **IMF_NOIMPLICITLANG** | **Windows 8**: If this flag is set, disable stamping keyboard input with the keyboard language and ensuring that non-East Asian language IDss are compatible with the character repertoire. This option is turned off by default (0). |
| **IMF_NOKBDLIDFIXUP** | **Windows 8**: If this flag is set, the rich edit control disables stamping keyboard language on an empty control. This option is turned off by default (0). |
| **IMF_SPELLCHECKING** | **Windows 8**: If this flag is set, the rich edit control turns on spell checking. This option is turned off by default (0). |
| **IMF_TKBAUTOCORRECTION** | **Windows 8**: If this flag is set, enable touch keyboard autocorrect. This option is turned off by default (0). |
| **IMF_TKBPREDICTION** | **Windows 10**: Ignored.<br>**Windows 8**: If this flag is set, the rich edit control enables touch keyboard prediction. This option is turned off by default (0). |
| **IMF_UIFONTS** | Use user-interface default fonts. This option is turned off by default (0). |

#### Remarks

The **IMF_AUTOFONT** flag is set by default. The **IMF_AUTOKEYBOARD** and **IMF_IMECANCELCOMPLETE** flags are cleared by default.

---

## RichEdit_GetLimitText

Retrieves the current text limit for an edit control. You can send this message to either an edit control or a rich edit control.

```
FUNCTION RichEdit_GetLimitText (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is the text limit.

#### Remarks

The text limit is the maximum amount of text, in characters, that the control can contain. For ANSI text, this is the number of bytes; for Unicode text, this is the number of characters. Two documents with the same character limit will yield the same text limit, even if one is ANSI and the other is Unicode.

---

## RichEdit_GetLine

Copies a line of text from a rich edit control.

```
FUNCTION RichEdit_GetLine (BYVAL hRichEdit AS HWND, BYVAL which AS DWORD) AS DWSTRING
```
**Note**: Before sending the EM_GETLINE message, the first word of the buffer has to be set to the size, in characters, of the buffer. The size in the first word is overwritten by the copied line.

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *which* | The zero-based index of the line to retrieve from a multiline edit control. A value of zero specifies the topmost line. |

#### Return value

A copy of the line.

---

## RichEdit_GetLineCount

Retrieves the number of lines in a multiline rich edit control.

```
FUNCTION RichEdit_GetLineCount (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is an integer specifying the total number of text lines in the multiline edit control or rich edit control. If the control has no text, the return value is 1. The return value will never be less than 1.

### Remarks

The **EM_GETLINECOUNT** message retrieves the total number of text lines, not just the number of lines that are currently visible.

If the Wordwrap feature is enabled, the number of lines can change when the dimensions of the editing window change.

---

## RichEdit_GetModify

Retrieves the state of a rich edit control's modification flag. The flag indicates whether the contents of the rich edit control have been modified.

```
FUNCTION RichEdit_GetModify (BYVAL hRichEdit AS HWND) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If the contents of edit control have been modified, the return value is nonzero; otherwise, it is zero.

### Remarks

The system automatically clears the modification flag to zero when the control is created. If the user changes the control's text, the system sets the flag to nonzero. You can send the **RichEdit_SetModify** message to the edit control to set or clear the flag.

---

## RichEdit_GetOleInterface

Retrieves an **IRichEditOle** object that a client can use to access a rich edit control's Component Object Model (COM) functionality.

```
FUNCTION RichEdit_GetOleInterface (BYVAL hRichEdit AS HWND, BYVAL ppObject AS IUnknown PTR PTR) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *ppObject* | Pointer to a pointer that receives the **IRichEditOle** object. The control calls the **AddRef** method for the object before returning, so the calling application must call the **Release** method when it is done with the object. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

---

## RichEdit_GetOptions

Retrieves rich edit control options.

```
FUNCTION RichEdit_GetOptions (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

This message returns a combination of the current option flag values described in the **RichEdit_SetOptions** message.

---

## RichEdit_GetPageRotate

Deprecated. Retrieves the text layout for a Microsoft Rich Edit control.

```
FUNCTION RichEdit_GetPageRotate (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The current text layout. For a list of possible text layout values, see **RichEdit_SetPageRotate**.

---

## RichEdit_GetParaFormat

Retrieves the paragraph formatting of the current selection in a rich edit control.

```
FUNCTION RichEdit_GetParaFormat (BYVAL hRichEdit AS HWND, BYVAL pParaFmt AS PARAFORMAT PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pParaFmt* | Pointer to a [PARAFORMAT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-paraformat) structure that receives the paragraph formatting attributes of the current selection. If more than one paragraph is selected, the structure receives the attributes of the first paragraph, and the **dwMask** member specifies which attributes are consistent throughout the entire selection. |

#### Return value

This message returns the value of the **dwMask** member of the [PARAFORMAT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-paraformat) structure.

---

## RichEdit_GetPasswordChar

Retrieves the password character that a rich edit control displays when the user enters text.

```
FUNCTION RichEdit_GetPasswordChar (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value specifies the character to be displayed in place of any characters typed by the user. If the return value is **NULL**, there is no password character, and the control displays the characters typed by the user.

#### Remarks

If an edit control is created with the **ES_PASSWORD** style, the default password character is set to an asterisk (*). If an edit control is created without the **ES_PASSWORD** style, there is no password character. To change the password character, send the **RichEdit_SetPasswordChar** message.

---

## RichEdit_GetPunctuation

Retrieves the current punctuation characters for the rich edit control.

```
FUNCTION RichEdit_GetPunctuation (BYVAL hRichEdit AS HWND, BYVAL punctype AS DWORD, BYVAL lppunct AS PUNCTUATION PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *punctype* | The punctuation type can be one of the following values.<br>**PC_LEADING**. Leading punctuation characters.<br>**PC_FOLLOWING**. Following punctuation characters.<br>**PC_DELIMITER**. Delimiter.<br>**PC_OVERFLOW**. Not supported |
| *lppunct* | Pointer to a [PUNCTUATION](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-punctuation) structure that receives the punctuation characters. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

---

## RichEdit_GetRect

Retrieves the formatting rectangle of an edit control. The formatting rectangle is the limiting rectangle into which the control draws the text. The limiting rectangle is independent of the size of the edit-control window.

```
SUB RichEdit_GetRect (BYVAL hRichEdit AS HWND, BYVAL prc AS RECT PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *prc* | A pointer to a [RECT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect) structure that receives the formatting rectangle. |

#### Remarks

You can modify the formatting rectangle of a multiline edit control by using the **RichEdit_SeRect** and **RichEdit_SeRectNP** messages.

Under certain conditions, **RichEdit_GetRect** might not return the exact values that **RichEdit_SeRect** and **RichEdit_SeRectNP** set it will be approximately correct, but it can be off by a few pixels.

The formatting rectangle does not include the selection bar, which is an unmarked area to the left of each paragraph. When clicked, the selection bar selects the line.

---

## RichEdit_GetRedoName

Retrieves the type of the next action, if any, in the rich edit control's redo queue.

```
FUNCTION RichEdit_GetRedoName (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If the redo queue for the control is not empty, the value returned is an [UNDONAMEID](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ne-richedit-undonameid) enumeration value that indicates the type of the next action in the control's redo queue.

If there are no redoable actions or the type of the next redoable action is unknown, the return value is zero.

#### UNDONAMEID enumeration

| Name              | Value | Description |
| ----------------- | ----- | ----------- |
| **UID_UNKNOWN**   |   0   | The type of undo action is unknown. |
| **UID_TYPING**    |   1   | Typing operation. |
| **UID_DELETE**    |   2   | Delete operation. |
| **UID_DRAGDROP**  |   3   | Drag-and-drop operation. |
| **UID_CUT**       |   4   | Cut operation. |
| **UID_PASTE**     |   5   | Paste operation. |
| **UID_AUTOTABLE** |   6   | Automatic table insertion; for example, typing +---+---+<Enter> to insert a table row. |

#### Remarks

The types of actions that can be undone or redone include typing, delete, drag-drop, cut, and paste operations. This information can be useful for applications that provide an extended user interface for undo and redo operations, such as a drop-down list box of redoable actions.

---

## RichEdit_GetScrollPos

Retrieves the current scroll position of the edit control.

```
FUNCTION RichEdit_GetScrollPos (BYVAL hRichEdit AS HWND, BYVAL lppt AS POINT PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lppt* | Pointer to a [POINT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-point) structure. After calling **RichEdit_GetScrollPos**, this parameters contains a point in the virtual text space of the document, expressed in pixels. This point will be the point that is currently located in the upper-left corner of the edit control window. |

#### Remarks

The values returned in the [POINT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-point) structure are 16-bit values (even in the 32-bit wide fields).

---

## RichEdit_GetSel

Retrieves the starting and ending character positions of the current selection in a rich edit control.

```
FUNCTION RichEdit_GetSel (BYVAL hRichEdit AS HWND, BYVAL pdwStartPos AS DWORD PTR, BYVAL pdwEndPos AS DWORD PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pdwStartPos* | A pointer to a **DWORD** value that receives the starting position of the selection. This parameter can be **NULL**. |
| *pdwEndPos* | A pointer to a **DWORD** value that receives the position of the first unselected character after the end of the selection. This parameter can be **NULL**. |

#### Return value

The return value is a zero-based value with the starting position of the selection in the **LOWORD** and the position of the first character after the last selected character in the **HIWORD**. If either of these values exceeds 65,535, the return value is -1.

It is better to use the values returned in *pdwStartPos* and *pdwEndPos* because they are full 32-bit values.

#### Remarks

If there is no selection, the starting and ending values are both the position of the caret.

You can also use the **EM_EXGETSEL** message to retrieve the same information. **EM_EXGETSEL** also returns starting and ending character positions as 32-bit values. A combination of the use of **EM_EXGETSEL** and **EM_GETSELTEXT** are used in the **RichEdit_GetSelText** function to retrieve the selected text as a **DWSTRING**.

---

## RichEdit_GetSelText

Retrieves the currently selected text in a rich edit control.

```
FUNCTION RichEdit_GetSelText (BYVAL hRichEdit AS HWND) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The selected text as a **DWSTRING** (dynamic unicode string).

---

## RichEdit_GetStoryType

Gets the story type.

```
FUNCTION RichEdit_GetStoryTpe (BYVAL hRichEdit AS HWND, BYVAL Index AS DWORD) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *Index* | The story index. |

#### Return value

Returns the story type, which can be a client-defined custom value, or one of the following values:

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **tomCommentsStory** | 4 | The story used for comments. |
| **tomEndnotesStory** | 3 | The story used for endnotes. |
| **tomEvenPagesFooterStory** | 8 | The story containing footers for even pages. |
| **tomEvenPagesHeaderStory** | 6 | The story containing headers for even pages. |
| **tomFindStory** | 128 | The story used for a Find dialog. |
| **tomFirstPageFooterStory** | 11 | The story containing the footer for the first page. |
| **tomFirstPageHeaderStory** | 10 | The story containing the header for the first page. |
| **tomFootnotesStory** | 2 | The story used for footnotes. |
| **tomMainTextStory** | 1 | The main story always exists for a rich edit control. |
| **tomPrimaryFooterStory** | 9 | The story containing footers for odd pages. |
| **tomPrimaryFooterStory** | 7 | The story containing headers for odd pages. |
| **tomReplaceStory** | 129 | The story used for a Replace dialog. |
| **tomScratchStory** | 127 | The scratch story. |
| **tomTextFrameStory** | 5 | The story used for a text box. |
| **tomUnknownStory** | 0 | No special type. |

---

## RichEdit_GetTableParams

Retrieves the table parameters for a table row and the cell parameters for the specified number of cells.

```
FUNCTION RichEdit_GetTableParams (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, _
   BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lptp* | A pointer to a [TABLEROWPARMS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-tablerowparms) structure. |
| *lptcp* | A pointer to a [TABLECELLPARMS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-tablecellparms) structure. |

#### Return value

Returns S_OK if successful, or one of the following error codes.

| Return code  | Description |
| ------------ | ----------- |
| **E_FAIL** | Changes cannot be made. This can occur if the control is a plain-text or single-line control, or if the insertion point is inside a math object. It also occurs if tables are disabled if the **RichEdit_SetEditStyleEx** message sets the **SES_EX_NOTABLE** value. |
| **E_INVALIDARG** | The *lptp* or *lptcp* parameters are NULL or point to an invalid structure. The **cbRow** member of the **TABLEROWPARMS** structure must equal sizeof(TABLEROWPARMS) or sizeof(TABLEROWPARMS) 2*sizeof(long). The latter value is the size of the RichEdit 4.1 **TABLEROWPARMS** structure. The **cbCell** member of the **TABLEROWPARMS** structure must equal sizeof(TABLECELLPARMS). The query character position must be at a table row delimiter. |
| **E_OUTOFMEMORY** | Insufficient memory is available. |

#### Remarks

This message gets the table parameters for the row at the character position specified by the **cpStartRow** member of the **TABLEROWPARMS** structure, and the number of cells specified by the **cCells** member of the **TABLECELLPARMS** structure.

The character position specified by the **cpStartRow** member of the **TABLEROWPARMS** structure should be at the start of the table row, or at the end delimiter of the table row. If **cpStartRow** is set to 1, the character position is given by the current selection. In this case, position the selection at the end of the row (between the cell mark and the end delimiter of the table row), or select the row.

---

## RichEdit_GetText

Retrieves the text from a rich edit control.

```
FUNCTION RichEdit_GetText (BYVAL hRichEdit AS HWND) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Remarks

The Windows API function **GetWindowTextW** can also be used to retrive the text of a rich edit control, but it cannot retrieve the text of a control in another application.

---

## RichEdit_GetTextEx

Retrieves all of the text from the rich edit control in any particular code base you want.

```
FUNCTION RichEdit_GetTextEx (BYVAL hRichEdit AS HWND, BYVAL lpgtex AS GETTEXTEX PTR, BYVAL buffer AS ANY PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpgtex* | Pointer to a [GETTEXTEX](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-gettextex) structure, which indicates how to translate the text before putting it into the output buffer. |
| *buffer* | Pointer to the buffer to receive the text. The size of this buffer, in bytes, is specified by the *cb* member of the [GETTEXTEX](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-gettextex) structure. Use the **RichEdit_GetTextLength** message to get the required size of the buffer. |

#### Return value

The return value is the number of characters copied into the output buffer, not including the null terminator.

#### Remarks

If the size of the output buffer is less than the size of the text in the control, the edit control will copy text from its beginning and place it in the buffer until the buffer is full. A terminating null character will still be placed at the end of the buffer.

---

## RichEdit_GetTextLength

Retrieves the length of all text in a rich edit control.

```
FUNCTION RichEdit_GetTextLength (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is the length of the text in characters, not including the terminating null character.

#### Remarks

When the **WM_GETTEXTLENGTH** message is sent, the **DefWindowProc** function returns the length, in characters, of the text. Under certain conditions, the **DefWindowProc** function returns a value that is larger than the actual length of the text. This occurs with certain mixtures of ANSI and Unicode, and is due to the system allowing for the possible existence of double-byte character set (DBCS) characters within the text. The return value, however, will always be at least as large as the actual length of the text; you can thus always use it to guide buffer allocation. This behavior can occur when an application uses both ANSI functions and common dialogs, which use Unicode.

To retrieve the text, you can also use the **AfxGetWindowText** function, the **WM_GETTEXT** message, or the Windows API **GetWindowTextW** function.

---

## RichEdit_GetTextLengthEx

Calculates text length in various ways. It is usually called before creating a buffer to receive the text from the control.

```
FUNCTION RichEdit_GetTextLengthEx (BYVAL hRichEdit AS HWND, BYVAL lpgtex AS GETTEXTLENGTHEX PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpgtex* | Pointer to a [GETTEXTLENGTHEX](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-gettextlengthex) structure that receives the text length information. |

#### Return value

The message returns the number of characters in the edit control, depending on the setting of the flags in the [GETTEXTLENGTHEX](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-gettextlengthex) structure. If incompatible flags were set in the *flags* member, the message returns **E_INVALIDARG**.

#### Remarks

This message is a fast and easy way to determine the number of characters in the Unicode version of the rich edit control. However, for a non-Unicode target code page you will potentially be converting to a combination of single-byte and double-byte characters.

---

## RichEdit_GetTextMode

Retrieves the current text mode and undo level of a rich edit control.

```
FUNCTION RichEdit_GetTextMode (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is one or more values from the [TEXTMODE](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ne-richedit-textmode) enumeration type. The values indicate the current text mode and undo level of the control.

#### TEXTMODE enumeration

| Name              | Value | Description |
| ----------------- | ----- | ----------- |
| **TM_PLAINTEXT**  |   1   | Indicates plain-text mode, in which the control is similar to a standard edit control. |
| **TM_RICHTEXT**   |   2   | Indicates rich-text mode, in which the control has the standard rich edit functionality. Rich-text mode is the default setting. |
| **TM_SINGLELEVELUNDO**  |   4   | The control allows the user to undo only the last action in the undo queue. |
| **TM_MULTILEVELUNDO** |   8   | The control supports multiple undo actions. This is the default setting. Use the *RichEdit_SetUndoLimit* message to set the maximum number of undo actions. |
| **TM_SINGLECODEPAGE** |  16   | The control only allows the English keyboard and a keyboard corresponding to the default character set. For example, you could have Greek and English. Note that this prevents Unicode text from entering the control. For example, use this value if a Rich Edit control must be restricted to ANSI text. |
| **TM_MULTICODEPAGE** |  32   | The control allows multiple code pages and Unicode text into the control. This is the default setting. |

---

## RichEdit_GetTextRange

Retrieves a specified range of characters from a rich edit control.

```
FUNCTION RichEdit_GetTextRange (BYVAL hRichEdit AS HWND, BYVAL lptrg AS TEXTRANGEW PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lptrg* | Pointer to a [TEXTRANGEW](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-textrangew) structure that specifies the range of characters to retrieve and a buffer to copy the characters to. |

#### Return value

The message returns the number of characters copied, not including the terminating null character.

---

## RichEdit_GetThumb

Retrieves the position of the scroll box (thumb) in the vertical scroll bar of a multiline edit control.

```
FUNCTION RichEdit_GetThumb (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is the position of the scroll box.

---

## RichEdit_GetTouchOptions

Retrieves the touch options that are associated with a rich edit control.

```
FUNCTION RichEdit_GetTouchOptions (BYVAL hRichEdit AS HWND, BYVAL Options AS LONG PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *Options* | The touch options to retrieve. It can be one of the following values. |

| Value  | Meaning |
| ------ | ------- |
| **RTO_SHOWHANDLES** | Retrieves whether the touch grippers are visible. |
| **RTO_DISABLEHANDLES** | Retrieving this flag is not implemented. |

#### Return value

Returns the value of the option specified by the *Options* parameter. It is nonzero if *Options* is **RTO_SHOWHANDLES** and the touch grippers are visible; zero, otherwise.

---

## RichEdit_GetTypographyOptions

Returns the current state of the typography options of a rich edit control.

```
FUNCTION RichEdit_GetTypographyOptions (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

Returns the current typography options. For a list of options, see [EM_SETTYPOGRAPHYOPTIONS](https://learn.microsoft.com/en-us/windows/win32/controls/em-settypographyoptions).

#### Remarks

You can turn on advanced line breaking by sending the **RichEdit_SetTypographyOPtions** message. Advanced and normal line breaking may also be turned on automatically by the rich edit control if it is needed for certain languages.

---

## RichEdit_GetUndoName

Retrieves the type of the next undo action, if any.

```
FUNCTION RichEdit_GetUndoName (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If there is an undo action, the value returned is an [UNDONAMEID](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ne-richedit-undonameid) enumeration value that indicates the type of the next action in the control's undo queue.

If there are no actions that can be undone or the type of the next undo action is unknown, the return value is zero.

#### UNDONAMEID enumeration

| Name              | Value | Description |
| ----------------- | ----- | ----------- |
| **UID_UNKNOWN**   |   0   | The type of undo action is unknown. |
| **UID_TYPING**    |   1   | Typing operation. |
| **UID_DELETE**    |   2   | Delete operation. |
| **UID_DRAGDROP**  |   3   | Drag-and-drop operation. |
| **UID_CUT**       |   4   | Cut operation. |
| **UID_PASTE**     |   5   | Paste operation. |
| **UID_AUTOTABLE** |   6   | Automatic table insertion; for example, typing +---+---+<Enter> to insert a table row. |

#### Remarks

The types of actions that can be undone or redone include typing, delete, drag, drop, cut, and paste operations. This information can be useful for applications that provide an extended user interface for undo and redo operations, such as a drop-down list box of actions that can be undone.

---

## RichEdit_GetWordBreakProc

Retrieves the address of the current Wordwrap function.

```
FUNCTION RichEdit_GetWordBreakProc (BYVAL hRichEdit AS HWND) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value specifies the address of the application-defined Wordwrap function. The return value is **NULL** if no Wordwrap function exists.

#### Remarks

A Wordwrap function scans a text buffer that contains text to be sent to the display, looking for the first word that does not fit on the current display line. The wordwrap function places this word at the beginning of the next line on the display. A Wordwrap function defines the point at which the system should break a line of text for multiline edit controls, usually at a space character that separates two words.

---

## RichEdit_GetWordBreakProcEx

Retrieves the address of the currently registered extended word-break procedure.

```
FUNCTION RichEdit_GetWordBreakProcEx (BYVAL hRichEdit AS HWND) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The message returns the address of the currently registered extended word-break procedure.

---

## RichEdit_GetWordWrapMode

Retrieves the current word wrap and word-break options for the rich edit control.

```
FUNCTION RichEdit_GetWordWrapMode (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The message returns the current word wrap and word-break options.

#### Remarks

This message is supported only in Asian-language versions of Microsoft Rich Edit 1.0. It is not supported in any later versions of Rich Edit. This message must not be sent by the application-defined, word-break procedure.

---

## RichEdit_GetZoom

Retrieves the current zoom ratio, which is always between 1/64 and 64.

```
FUNCTION RichEdit_GetZoom (BYVAL hRichEdit AS HWND, BYVAL pzNum AS DWORD PTR, BYVAL pzDen AS DWORD PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pzNum* | A pointer to a **DWORD** value that receives the numerator of the zoom ratio. |
| *pzDen* | A pointer to a **DWORD** value that receives the denominator of the zoom ratio.. |

#### Return value
The message returns **TRUE** if message is processed, which it will be if both *pzNum* and *pzDen* are not **NULL**.

---

## RichEdit_HideSelection

Hides or shows the selection in a rich edit control.

```
SUB RichEdit_HideSelection (BYVAL hRichEdit AS HWND, BYVAL fHide AS DWORD)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fHide* | Value specifying whether to hide or show the selection. If this parameter is zero, the selection is shown. Otherwise, the selection is hidden. |

---

## RichEdit_InsertImage

Replaces the selection with a blob that displays an image.

```
FUNCTION RichEdit_InsertImage (BYVAL hRichEdit AS HWND, BYVAL lpip AS RICHEDIT_IMAGE_PARAMETERS PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lpip* | A pointer to a [RICHEDIT_IMAGE_PARAMETERS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-richedit_image_parameters) structure that contains the image blob. |

#### Return value

Returns S_OK if successful, or one of the following error codes.

| Return code  | Description |
| ------------ | ----------- |
| **E_FAIL** | Cannot insert the image. |
| **E_INVALIDARG** | The *lpip* parameter is NULL or points to an invalid image. |
| **E_OUTOFMEMORY** | Insufficient memory is available. |

---

## RichEdit_InsertTable

Inserts one or more identical table rows with empty cells.

```
FUNCTION RichEdit_InsertTable (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, _
   BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
```
| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lptp* | A pointer to a [TABLEROWPARMS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-tablerowparms) structure. |
| *lptcp* | A pointer to a [TABLECELLPARMS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-tablecellparms) structure. |

#### Return value

Returns **S_OK** if the table is inserted, or an error code if not.

#### Remarks

If the **cpStartRow** member of the **TABLEROWPARMS** is –1, this message deletes the selected text (if any), and then inserts empty table rows with the row and cell parameters given by *lptp^* and *lptcp*. It leaves the selection pointing to the start of the first cell in the first row. The client can then populate the table cells by pointing the selection (or an **ITextRange**) to the various cell end marks and inserting and formatting the desired text. Such text can include nested table rows. Alternatively, if the **cpStartRow** member of the **TABLEROWPARMS** is 0 or greater, table rows are inserted at the character position given by **cpStartRow**. This only changes the current selection if the table is inserted inside the selected text.

A Microsoft Rich Edit table consists of a sequence of table rows which, in turn, consist of sequences of paragraphs. A table row starts with the special two-character delimiter paragraph U+FFF9 U+000D and ends with the two-character delimiter paragraph U+FFFB U+000D. Each cell is terminated by the cell mark U+0007, which is treated as a hard end-of-paragraph mark just as U+000D (CR) is. The table row and cell parameters are treated as special paragraph formatting of the table-row delimiters. The formatting contains the information in the **TABLEROWPARMS** structure. The cell parameters given by the **TABLECELLPARMS** structure are stored in an expanded version of the tabs array. This format allows tables to be nested within other tables, up to fifteen levels deep.

---

## RichEdit_IsIME

Determines if current input locale is an East Asian locale.

```
FUNCTION RichEdit_IsIME (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

Returns **TRUE** if it is an East Asian locale. Otherwise, it returns **FALSE**.

---

## RichEdit_LimitText

Sets the text limit of a rich edit control. The text limit is the maximum amount of text, in characters, that the user can type into the edit control.

```
SUB RichEdit_LimitText (BYVAL hRichEdit AS HWND, BYVAL chMax AS DWORD)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *chMax* | The maximum number of characters the user can enter. If this parameter is zero, the text length is set to 64,000 characters. |

#### Return value

This message does not return a value.

#### Remarks

The **RichEdit_LimitText** message limits only the text the user can enter. It does not affect any text already in the edit control when the message is sent, nor does it affect the length of the text copied to the edit control by the **RichEdit_SetText** message. If an application uses the **RichEdit_SetTExt** message to place more text into an edit control than is specified in the **RichEdit_LimitText** message, the user can edit the entire contents of the edit control.

#### Note

**RichEdit_LimitText** ad **RichEdit_SetLimitText** are the same message.

---

## RichEdit_LineFromChar

Retrieves the index of the line that contains the specified character index in a multiline rich edit control.

```
FUNCTION RichEdit_LineFromChar (BYVAL hRichEdit AS HWND, BYVAL index AS DWORD) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *index* | The character index of the character contained in the line whose number is to be retrieved. If this parameter is -1, **RichEdit_LineFromChar** retrieves either the line number of the current line (the line containing the caret) or, if there is a selection, the line number of the line containing the beginning of the selection. |

#### Return value

The return value is the zero-based line number of the line containing the character index specified by *index*.

---

## RichEdit_LineIndex

Retrieves the character index of the first character of a specified line in a multiline rich edit control.

```
FUNCTION RichEdit_LineIndex (BYVAL hRichEdit AS HWND, BYVAL nLine AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nLine* | The zero-based line number. A value of -1 specifies the current line number (the line that contains the caret). |

#### Return value

The return value is the character index of the line specified in the *nLine* parameter, or it is -1 if the specified line number is greater than the number of lines in the edit control.

---

## RichEdit_LineLength

Retrieves the length, in characters, of a line in a rich edit control.

```
FUNCTION RichEdit_LineLength (BYVAL hRichEdit AS HWND, BYVAL index AS DWORD) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *index* | The character index of a character in the line whose length is to be retrieved. If this parameter is greater than the number of characters in the control, the return value is zero.<br>This parameter can be -1. In this case, the message returns the number of unselected characters on lines containing selected characters. For example, if the selection extended from the fourth character of one line through the eighth character from the end of the next line, the return value would be 10 (three characters on the first line and seven on the next). |

#### Return value

If *index* is greater than the number of characters in the control, the return value is zero.

---

## RichEdit_LineScroll

Scrolls the text in a multiline rich edit control.

```
FUNCTION RichEdit_LineScroll (BYVAL hRichEdit AS HWND, BYVAL y AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *y* | The number of lines to scroll vertically. |

#### Return value

**TRUE** or **FALSE**.

#### Remarks

The control does not scroll vertically past the last line of text in the edit control. If the current line plus the number of lines specified by the *y* parameter exceeds the total number of lines in the edit control, the value is adjusted so that the last line of the edit control is scrolled to the top of the edit-control window.

---

## RichEdit_PasteSpecial

Pastes a specific clipboard format in a rich edit control.

```
SUB RichEdit_PasteSpecial (BYVAL hRichEdit AS HWND, BYVAL clpfmt AS DWORD, BYVAL lprps AS REPASTESPECIAL PTR)
   SendMessageW hRichEdit, EM_PASTESPECIAL, clpfmt, cast(LPARAM, lprps)
END SUB
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *clpfmt* | Specifies the [ Clipboard Formats](https://learn.microsoft.com/en-us/windows/win32/dataxchg/clipboard-formats). |
| *lprps* | Pointer to a [REPASTESPECIAL](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-repastespecial) structure or **NULL**. If an object is being pasted, the [REPASTESPECIAL](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-repastespecial) structure is filled in with the desired display aspect. If *clpfmt* is **NULL** or the *dwAspect* member is zero, the display aspect used will be the contents of the object descriptor. |

---

## RichEdit_PosFromChar

Retrieves the client area coordinates of a specified character in a rich edit control.

```
SUB RichEdit_PosFromChar (BYVAL hRichEdit AS HWND, BYVAL pt AS POINTL PTR, BYVAL index as DWORD)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pt* | A pointer to a [POINTL](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-pointl) structure that receives the client area coordinates of the character. The coordinates are in screen units and are relative to the upper-left corner of the control's client area. |
| *index* | The zero-based index of the character. |

#### Remarks

A returned coordinate can be a negative value if the specified character is not displayed in the edit control's client area. The coordinates are truncated to integer values.

If the character is a line delimiter, the returned coordinates indicate a point just beyond the last visible character in the line. If the specified index is greater than the index of the last character in the control, the control returns -1.

---

## RichEdit_Reconversion

Invokes the Input Method Editor (IME) reconversion dialog box.

```
FUNCTION RichEdit_Reconversion (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

This message always returns zero.

---

## RichEdit_Redo

Redoes the next action in the control's redo queue.

```
FUNCTION RichEdit_Redo (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If the **Redo** operation succeeds, the return value is a nonzero value.

If the **Redo** operation fails, the return value is zero.

#### Remarks

To determine whether there are any actions in the control's redo queue, send the **RichEdit_CanRedo** message.

---

## RichEdit_ReplaceSel

Replaces the current selection in a rich edit control with the specified text.

```
SUB RichEdit_ReplaceSel (BYVAL hRichEdit AS HWND, BYVAL bCanBeUndone AS LONG, BYVAL pwszText AS WSTRING PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *bCanBeUndone* | Specifies whether the replacement operation can be undone. If this is **TRUE**, the operation can be undone. If this is **FALSE**, the operation cannot be undone. |
| *pwszText* | A pointer to a null-terminated string containing the replacement text. |

#### Remarks

Use the **RichEdit_ReplaceSel** message to replace only a portion of the text in an edit control. To replace all of the text, use the **RichEdit_SetText** message or the **SetWindowText** Windows API function.

If there is no selection, the replacement text is inserted at the caret.

In a rich edit control, the replacement text takes the formatting of the character at the caret or, if there is a selection, of the first character in the selection.

---

## RichEdit_RequestResize

Forces a rich edit control to send an **EN_REQUESTRESIZE** notification message to its parent window.

```
SUB RichEdit_RequestResize (BYVAL hRichEdit AS HWND)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Remarks

This message is useful during **WM_SIZE** processing for the parent of a bottomless rich edit control.

---

## RichEdit_Scroll

Scrolls the text vertically in a multiline rich edit control.

```
FUNCTION RichEdit_Scroll (BYVAL hRichEdit AS HWND, BYVAL nAction AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nAction* | The action the scroll bar is to take. This parameter can be one of the following values:<br>**SB_LINEDOWN**. Scrolls down one line.<br>**SB_LINEUP**. Scrolls up one line.<br>**SB_PAGEDOWN**. Scrolls down one page.<br>**SB_PAGEUP**. Scrolls up one page. |

#### Return value

If the message is successful, the **HIWORD** of the return value is **TRUE**, and the **LOWORD** is the number of lines that the command scrolls. The number returned may not be the same as the actual number of lines scrolled if the scrolling moves to the beginning or the end of the text. If the *nAction* parameter specifies an invalid value, the return value is **FALSE**.

#### Remarks

To scroll to a specific line or character position, use the **RichEdit_LineScroll** message. To scroll the caret into view, use the **RichEdit_ScrollCaret** message.

---

## RichEdit_ScrollCaret

Scrolls the caret into view in a rich edit control.

```
SUB RichEdit_ScrollCaret (BYVAL hRichEdit AS HWND)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is not meaningful.

---

## RichEdit_SelectionType

Determines the selection type for a rich edit control.

```
FUNCTION RichEdit_SelectionType (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

If the selection is not empty, the return value is a set of flags containing one or more of the following values.

| Return code  | Description |
| ------------ | ----------- |
| **SEL_TEXT** | Text.|
| **SEL_OBJECT** | At least one COM object. |
| **SEL_MULTICHAR** | More than one character of text. |
| **SEL_MULTIOBJECT** | More than one COM object. |

#### Remarks

This message is useful during **WM_SIZE** processing for the parent of a bottomless rich edit control.

---

## RichEdit_SetAutoCorrectProc

Sets a pointer to the application-defined [AutoCorrectProc](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-autocorrectproc) callback function.

```
FUNCTION RichEdit_SetAutoCorrectProc (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pfn* | Pointer to an [AutoCorrectProc](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-autocorrectproc) function. |

#### Return value

If the operation succeeds, the return value is zero. If the operation fails, the return value is a nonzero value.

---

## RichEdit_SetBidiOptions

Sets the current state of the bidirectional options in the rich edit control.

```
SUB RichEdit_SetBidiOptions (BYVAL hRichEdit AS HWND, BYVAL pOptions AS BIDIOPTIONS PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pOptions* | Pointer to a [BIDIOPTIONS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-bidioptions) structure that indicates how to set the state of the bidirectional options in the rich edit control. |

#### Remarks

The rich edit control must be in plain text mode or **RichEdit_SetBidiOptions** will not do anything.

In plain text controls, **RichEdit_SetBidiOptions** automatically determines the paragraph direction and/or alignment based on the context rules. These rules state that the direction and/or alignment is derived from the first strong character in the control. A strong character is one from which text direction can be determined (see Unicode Standard version 2.0). The paragraph direction and/or alignment is applied to the default format.

**RichEdit_SetBidiOptions** only switches the default paragraph format to RTL (right to left) if it finds an RTL character.

---

## RichEdit_SetBkgndColor

Sets the background color for a rich edit control.

```
FUNCTION RichEdit_SetBkgndColor (BYVAL hRichEdit AS HWND, BYVAL pSysColor AS DWORD, BYVAL pBkColor AS DWORD) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pSysColor* | Specifies whether to use the system color. If this parameter is a nonzero value, the background is set to the window background system color. Otherwise, the background is set to the specified color. |
| *pBkColor* | A [COLORREF](https://learn.microsoft.com/en-us/windows/win32/gdi/colorref) structure specifying the color if *pSysColor* is zero. To generate a COLORREF, use the RGB macro (renamed as BGR in the FreeBasic Windows headers). |

#### Return value

This message returns the original background color.

---

## RichEdit_SetCharFormat

Sets character formatting in a rich edit control.

```
FUNCTION RichEdit_SetCharFormat (BYVAL hRichEdit AS HWND, BYVAL chfmt AS DWORD, BYVAL lpcf AS CHARFORMATW PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *chfmt* | Character formatting that applies to the control. If this parameter is zero, the default character format is set. Otherwise, it can be one of the following values (see Formatting values below). |
| *lpcf* | Pointer to a [CHARFORMAT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-charformata) structure specifying the character formatting to use. Only the formatting attributes specified by the **dwMask** member are changed. The **szFaceName** and **bCharSet** members may be overruled when invalid for characters, for example: Arial on kanji characters. |

#### Formatting values

| Value  | Meaning |
| ------ | ------- |
| **SCF_ALL** | Applies the formatting to all text in the control. Not valid with **SCF_SELECTION** or **SCF_WORD**. |
| **SCF_ASSOCIATEFONT** | **RichEdit 4.1**: Associates a font to a given script, thus changing the default font for that script. To specify the font, use the following members of **CHARFORMAT2**: yHeight, bCharSet, bPitchAndFamily, szFaceName, and lcid. |
| **SCF_ASSOCIATEFONT2** | **RichEdit 4.1**: Associates a surrogate (plane-2) font to a given script, thus changing the default font for that script. To specify the font, use the following members of **CHARFORMAT2**: yHeight, bCharSet, bPitchAndFamily, szFaceName, and lcid. |
| **SCF_CHARREPFROMLCID** | Gets the character repertoire from the LCID. |
| **SCF_DEFAULT** | **RichEdit 4.1**: Sets the default font for the control. |
| **SPF_DONTSETDEFAULT** | Prevents setting the default paragraph format when the rich edit control is empty. |
| **SCF_NOKBUPDATE** | **RichEdit 4.1**: Prevents keyboard switching to match the font. For example, if an Arabic font is set, normally the automatic keyboard feature for Bidi languages changes the keyboard to an Arabic keyboard. |
| **SCF_SELECTION** | Applies the formatting to the current selection. If the selection is empty, the character formatting is applied to the insertion point, and the new character format is in effect only until the insertion point changes. |
| **SPF_SETDEFAULT** | Sets the default paragraph formatting attributes. |
| **SCF_SMARTFONT** | Apply the font only if it can handle script. |
| **SCF_USEUIRULES** | **RichEdit 4.1**: Used with **SCF_SELECTION**. Indicates that format came from a toolbar or other UI tool, so UI formatting rules should be used instead of literal formatting. |
| **SCF_WORD** | Applies the formatting to the selected word or words. If the selection is empty but the insertion point is inside a word, the formatting is applied to the word. The **SCF_WORD** value must be used in conjunction with the **SCF_SELECTION** value. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

#### Remarks

If this message is sent more than once with the same parameters, the effect on the text is toggled. That is, sending the message once produces the effect, sending the message twice cancels the effect, and so forth.

---

## RichEdit_SetCTFModeBias

Sets the Text Services Framework (TSF) mode bias for a rich edit control.

```
FUNCTION RichEdit_SetCTFModeBias (BYVAL hRichEdit AS HWND, BYVAL nModeBias AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nModeBias* | Mode bias value. This can be one of the following values below. |

| Mode bias value  | Meaning |
| ---------------- | ------- |
| **CTFMODEBIAS_DEFAULT** | There is no mode bias. |
| **CTFMODEBIAS_FILENAME** | The bias is to a filename. |
| **CTFMODEBIAS_NAME** | The bias is to a name. |
| **CTFMODEBIAS_READING** | The bias is to the reading. |
| **CTFMODEBIAS_DATETIME** | The bias is to a date or time. |
| **CTFMODEBIAS_CONVERSATION** | The bias is to a conversation. |
| **CTFMODEBIAS_NUMERIC** | The bias is to a number. |
| **CTFMODEBIAS_HIRAGANA** | The bias is to hiragana strings. |
| **CTFMODEBIAS_KATAKANA** | The bias is to katakana strings. |
| **CTFMODEBIAS_HANGUL** | The bias is to Hangul characters. |
| **CTFMODEBIAS_HALFWIDTHKATAKANA** | The bias is to half-width katakana strings. |
| **CTFMODEBIAS_FULLWIDTHALPHANUMERIC** | The bias is to full-width alphanumeric characters. |
| **CTFMODEBIAS_HALFWIDTHALPHANUMERIC** | The bias is to half-width alphanumeric characters. |

#### Return value

If successful, the return value is the new TSF mode bias value. If unsuccessful, the return value is the old TSF mode bias value.

#### Remarks

When a Microsoft Rich Edit application uses TSF, it can select the TSF mode bias. This message sets the criteria by which an alternative choice appears at the top of the list for selection.

To get the mode bias for the Input Method Editor (IME), use **RichEdit_GetModeBias**.

---

## RichEdit_SetCTFOpenStatus

Opens or closes the Text Services Framework (TSF) keyboard.

```
FUNCTION RichEdit_SetCTFOpenStatus (BYVAL hRichEdit AS HWND, BYVAL fTSFkbd AS LONG) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fTSFkbd* | To turn on the TSF keyboard, use **TRUE**. To turn off the TSF keyboard, use **FALSE**. |

#### Return value

If successful, this message returns **TRUE**. If unsuccessful, this message returns **FALSE**.

---

## RichEdit_SetEditStyle

Sets the current edit style flags.

```
FUNCTION RichEdit_SetEditStyle (BYVAL hRichEdit AS HWND, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fStyle* | Specifies one or more edit style flags. For a list of possible values, see **RichEdit_GetEditStyle**. |
| *fMask* | A mask consisting of one or more of the *fTSFkbd* values. Only the values specified in this mask will be set or cleared. This allows a single flag to be set or cleared without reading the current flag states. |

#### Return value

The return value is the state of the edit style flags after the rich edit control has attempted to implement your edit style changes. The edit style flags are a set of flags that indicate the current edit style.

---

## RichEdit_SetEditStyleEx

Sets the current edit style flags for a rich edit control.

```
FUNCTION RichEdit_SetEditStyleEx (BYVAL hRichEdit AS HWND, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fStyle* | Specifies one or more edit style flags. For a list of possible values, see table below. |
| *fMask* | A mask consisting of one or more of the *fStyle* values. Only the values specified in this mask will be set or cleared. This allows a single flag to be set or cleared without reading the current flag states. |

| Edit style flag | Description |
| --------------- | ----------- |
| **SES_EX_HANDLEFRIENDLYURL** | Display friendly name links with the same text color and underlining as automatic links, provided that temporary formatting isn't used or uses text autocolor (default: 0). |
| **SES_EX_MULTITOUCH** | Enable touch support in Rich Edit. This includes selection, caret placement, and context-menu invocation. When this flag is not set, touch is emulated by mouse commands, which do not take touch-mode specifics into account (default: 0). |
| **SES_EX_NOACETATESELECTION** | Display selected text using classic Windows selection text and background colors instead of background acetate color (default: 0). |
| **SES_EX_NOMATH** | Disable insertion of math zones (default: 1). To enable math editing and display, send the **RichEdit_SetEditStyleEx** message with *fStyle* set to 0, and *fMask* set to SES_EX_NOMATH. |
| **SES_EX_NOTABLE** | Disable insertion of tables. The **RichEdit_InsertTable** message returns **E_FAIL** and RTF tables are skipped (default: 0). |
| **SES_EX_USESINGLELINE** | Enable a multiline control to act like a single-line control with the ability to scroll vertically when the single-line height is greater than the window height (default: 0). |
| **SES_HIDETEMPFORMAT** | Hide temporary formatting that is created when **ITextFont.Reset** is called with **tomApplyTmp**. For example, such formatting is used by spell checkers to display a squiggly underline under possibly misspelled words. |
| **SES_EX_USEMOUSEWPARAM** | Use *wParam* when handling the **WM_MOUSEMOVE** message and do not call **GetAsyncKeyState**. |

#### Return value

The return value is the state of the edit style flags after the rich edit control has attempted to implement your edit style changes. The edit style flags are a set of flags that indicate the current edit style.

---

## RichEdit_SetEllipsisMode

Sets the current ellipsis mode. When enabled, an ellipsis ( ) is displayed for text that doesn't fit in the display window. The ellipsis is only used when the control isn't active. When active, scroll bars are used to reveal text that doesn't fit into the display window.

```
FUNCTION RichEdit_SetElipsisMode (BYVAL hRichEdit AS HWND, BYVAL fMode AS DWORD) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fMode* | One of the values listed below. |

| Value  | Meaning |
| ------ | ----------- |
| **ELLIPSIS_NONE** | No ellipsis is used. |
| **ELLIPSIS_END** | Ellipsis at the end (forced break). |
| **ELLIPSIS_WORD** | Ellipsis at the end (word break). |

The bits for these values all fit in the **ELLIPSIS_MASK**.

---

## RichEdit_SetEventMask

Sets the event mask for a rich edit control.

```
FUNCTION RichEdit_SetEventMask (BYVAL hRichEdit AS HWND, BYVAL fMask AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fMask* | New event mask for the rich edit control. For a list of event masks, see **Rich Edit Control Event Mask Flags** below. |


#### Rich Edit Control Event Mask Flags

The event mask specifies which notification codes a rich edit control sends to its parent window. The event mask can be none or a combination of these values.

| Flag  | Description |
| ----- | ----------- |
| **ENM_CHANGE** | Sends **EN_CHANGE** notifications. |
| **ENM_CLIPFORMAT** | Sends **EN_CLIPFORMAT** notifications. |
| **ENM_CORRECTTEXT** | Sends **EN_CORRECTTEXT** notifications. |
| **ENM_DRAGDROPDONE** | Sends **EN_DRAGDROPDONE** notifications. |
| **ENM_DROPFILES** | Sends **EN_DROPFILES** notifications. |
| **ENM_IMECHANGE** | **Microsoft Rich Edit 1.0 only**: Sends **EN_IMECHANGE** notifications when the IME conversion status has changed. Only for Asian-language versions of the operating system. |
| **ENM_KEYEVENTS** | Sends **EN_MSGFILTER** notifications for keyboard events. |
| **ENM_LINK** | **Rich Edit 2.0 and later**: Sends **EN_LINK** notifications when the mouse pointer is over text that has the CFE_LINK and one of several mouse actions is performed. |
| **ENM_LOWFIRTF** | Sends **EN_LOWFIRTF** notifications. |
| **ENM_MOUSEEVENTS** | Sends **EN_MSGFILTER** notifications for mouse events. |
| **ENM_OBJECTPOSITIONS** | Sends **EN_OBJECTPOSITIONS** notifications. |
| **ENM_PARAGRAPHEXPANDED** | Sends **EN_PARAGRAPHEXPANDED** notifications. |
| **ENM_PROTECTED** | Sends **EN_PROTECTED** notifications. |
| **ENM_REQUESTRESIZE** | Sends EN_REQUESTRESIZE notifications. |
| **ENM_SCROLL** | Sends EN_HSCROLL and EN_VSCROLL notifications. |
| **ENM_SCROLLEVENTS** | Sends **EN_MSGFILTER** notifications for mouse wheel events. |
| **ENM_SELCHANGE** | Sends **EN_SELCHANGE** notifications. |
| **ENM_UPDATE** | Sends EN_UPDATE notifications.<br>**Rich Edit 2.0 and later**: this flag is ignored and the **EN_UPDATE** notifications are always sent. However, if Rich Edit 3.0 emulates Microsoft Rich Edit 1.0, you must use this flag to send **EN_UPDATE** notifications. |

#### Return value

This message returns the previous event mask.

#### Remarks

The default event mask is **ENM_NONE** in which case no notifications are sent to the parent window. You can retrieve and set the event mask for a rich edit control by using the **RichEdit_GetEvenMask** and **RichEdit_SetEventMask** messages.

---

## RichEdit_SetFontSize

Sets the font size for the selected text.

```
FUNCTION RichEdit_SetFontSize (BYVAL hRichEdit AS HWND, BYVAL ptsize AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *ptsize* | Change in point size of the selected text. The result will be rounded according to values shown in the following table. This parameter should be in the range of -1637 to 1638. The resulting font size will be within the range of 1 to 1638. |

#### Return value

If no error occurred, the return value is TRUE.

If an error occurred, the return value is FALSE.

#### Remarks

You can easily get the font size by sending the **RichdEdit_GetCharFormat** message.

Rich Edit first adds *ptsize* to the current font size and then uses the resulting size and the following table to determine the rounding value.

| Band  | Rounding value |
| ----- | ----------- |
| <=12 | 1 |
| 28 | 2 |
| 36 | 0 |
| 48 | 0 |
| 72 | 0 |
| 80 | 0 |
| 80 | 10 |

If the resulting font size is not evenly divisible by the rounding value, the font size is then rounded to a number evenly divisible by the rounding value. So if the font size is less than or equal to 12, the rounding value will be 1. Similarly, if the font size is less than or equal to 28, the rounding value is 2. For values greater than 28, font sizes are rounded to the next band. So, the font size jumps to 36, 48, 72, 80. After 80, all rounding is done in increments of ten points.

The font size is rounded up or down depending on the sign of *ptsize*. If *ptsize* is positive, the rounding is always up. Otherwise, rounding is always down. So, if the current font size is 10 and *ptsize* is 3, the resulting font size would be 14 (10 + 3 = 13, which is not divisible by 2, so the size rounds up to 14). Conversely, if the current font size is 14 and *ptsize* is -3, the resulting font size would be 10 (14 - 3 = 11, which is not divisible by 2, so the size rounds down to 10).

The change is applied to each part of the selection. So, if some of the text is 10pt and some 20pt, after a call with *ptsize* set to 1, the font sizes become 11pt and 22pt, respectively.

Additional examples are shown in the following table.

| Original font size  | ptsize | Resulting font size |
| ------------------- | ------ | ------------------- |
| 7 | 1 | 8 |
| 7 | 3 | 10 |
| 10 | 3 | 14 |
| 14 | -3 | 10 |
| 28 | 1 | 36 |
| 28 | 3 | 36 |
| 80 | 1 | 90 |
| 80 | -1 | 72 |

---

## RichEdit_SetHyphenateInfo

Sets the way a Microsoft Rich Edit control does hyphenation.

```
SUB RichEdit_SetHyphenateInfo (BYVAL hRichEdit AS HWND, BYVAL phinfo AS HYPHENATEINFO PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *phinfo* | Pointer to a [HYPHENATEINFO](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-hyphenateinfo) structure. |

---

## RichEdit_SetIMEColor

Sets the Input Method Editor (IME) composition color.

```
FUNCTION RichEdit_SetIMEColor (BYVAL hRichEdit AS HWND, BYVAL pcompcolor AS COMPCOLOR PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pcompcolor* | Pointer to a [COMPCOLOR](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-compcolor) structure that contains the composition color to be set. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

#### Note

This message is supported only in Asian-language versions of Microsoft Rich Edit 1.0. It is not supported in any later versions.

---

## RichEdit_SetIMEModeBias

Sets the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control.

```
FUNCTION RichEdit_SetIMEModeBias (BYVAL hRichEdit AS HWND, BYVAL nModeBias AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nModeBias* | IME mode bias value. It can be one of the following.<br>**IMF_SMODE_PLAURALCLAUSE**. Sets the IME mode bias to Name.<br>**IMF_SMODE_NONE**. No bias. |

#### Return value

This message returns the new IME mode bias setting.

#### Remarks

When the IME generates a list of alternative choices for a set of characters, this message sets the criteria by which some of the choices will appear at the top of the list.

To set the Text Services Framework (TSF) mode bias, use **RichEdit_SetCTFModeBias**.

The application should call **RichEdit_IsIME** before calling this function.

---

## RichEdit_SetIMEOptions

Sets the Input Method Editor (IME) options.

```
FUNCTION RichEdit_SetIMEOptions (BYVAL hRichEdit AS HWND, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fCoop* | Specifies one of the following values.<br>**ECOOP_SET**. Sets the options to those specified by *fOptions*.<br>**COOP_OR**. Combines the specified options with the current options.<br>**ECOOP_AND**. Retains only those current options that are also specified by *fOptions*.<br>**ECOOP_XOR**. Logically exclusive OR the current options with those specified by *fOptions*. |
| *fOptions* | Specifies one of more of the following values.<br>**IMF_CLOSESTATUSWINDOW**. Closes the IME status window when the control receives the input focus.<br>**IMF_FORCEACTIVE**. Activates the IME when the control receives the input focus.<br>**IMF_FORCEDISABLE**. Disables the IME when the control receives the input focus.<br>**IMF_FORCEENABLE**. Enables the IME when the control receives the input focus.<br>**IMF_FORCEINACTIVE**. Inactivates the IME when the control receives the input focus.<br>**IMF_FORCENONE**. Disables IME handling.<br>**IMF_FORCEREMEMBER**. Restores the previous IME status when the control receives the input focus.<br>**IMF_MULTIPLEEDIT**. Specifies that the composition string will not be canceled or determined by focus changes. This allows an application to have separate composition strings on each rich edit control.<br>**IMF_VERTICAL**. Note: used in Rich Edit 2.0 and later. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

#### Note

This message is supported only in Asian-language versions of Microsoft Rich Edit 1.0. It is not supported in any later versions.

---

## RichEdit_SetLangOptions

Sets options for Input Method Editor (IME) and Asian language support in a rich edit control.

```
FUNCTION RichEdit_SetLangOptions (BYVAL hRichEdit AS HWND, BYVAL lgoptions AS LONG) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lgoptions* | Specifies the language options. For a list of possible values, see [EM_GETLANGOPTIONS](https://learn.microsoft.com/en-us/windows/win32/controls/em-getlangoptions). |

#### Return value

This message returns a value of 1.

### Remarks

The **RichEdit_SetLangOptions** message controls the following:

- Automatic font binding.
- Automatic keyboard switching.
- Automatic font size adjustment.
- Use of user-interface default fonts instead of document default fonts.
- Notifications to client during IME composition.
- How IME aborts composition mode.
- Spell checking, autocorrect, and touch keyboard prediction.

This message sets the values of all language option flags. To change a subset of the flags, send the **RichEdit-GetLangOptions** message to get the current option flags, change the flags that you need to change, and then send the **RichEdit_SetLangOptions** message with the result.

---

## RichEdit_SetLimitText

Sets the text limit of a rich edit control. The text limit is the maximum amount of text, in characters, that the user can type into the edit control.

```
SUB RichEdit_SetLimitText (BYVAL hRichEdit AS HWND, BYVAL chMax AS DWORD)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *chMax* | The maximum number of characters the user can enter. If this parameter is zero, the text length is set to 64,000 characters. |

#### Remarks

The **RichEdit_SetLimitText** message limits only the text the user can enter. It does not affect any text already in the edit control when the message is sent, nor does it affect the length of the text copied to the edit control by the **RichEdit_SetText** message. If an application uses the **RichEdit_SetText** message to place more text into an edit control than is specified in the **RichEdit_SetLimitText** message, the user can edit the entire contents of the edit control.

#### Note

**RichEdit_SetLimitText** ad **RichEdit_LimitText** are the same message.

---

## RichEdit_SetMargins

Sets the widths of the left and right margins for a rich edit control. The message redraws the control to reflect the new margins.

```
PRIVATE SUB RichEdit_SetMargins (BYVAL hRichEdit AS HWND, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nMargins* | TThe margins to set. This parameter can be one or more of the following values.<br>**EC_LEFTMARGIN**. Sets the left margin.<br>**EC_RIGHTMARGIN**. Sets the right margin.<br>**EC_USEFONTINFO**. Sets the left and right margins to a narrow width calculated using the text metrics of the control's current font. If no font has been set for the control, the margins are set to zero. The *nWidth* parameter is ignored. |
| *nWidth* | The **LOWORD** specifies the new width of the left margin, in pixels. This value is ignored if *nMargins* does not include **EC_LEFTMARGIN**.<br>**Rich Edit 3.0 and later**: The **LOWORD** can specify the **EC_USEFONTINFO** value to set the left margin to a narrow width calculated using the text metrics of the control's current font. If no font has been set for the control, the margin is set to zero.<br>The **HIWORD** specifies the new width of the right margin, in pixels. This value is ignored if *nMargins* does not include **EC_RIGHTMARGIN**.<br>**Rich Edit 3.0 and later**: The **HIWORD** can specify the **EC_USEFONTINFO** value to set the right margin to a narrow width calculated using the text metrics of the control's current font. If no font has been set for the control, the margin is set to zero |

**RichEdit_SetLimitText** ad **RichEdit_LimitText** are the same message.

---

## RichEdit_SetModify

Sets or clears the modification flag for a rich edit control. The modification flag indicates whether the text within the rich edit control has been modified.

```
SUB RichEdit_SetModify (BYVAL hRichEdit AS HWND, BYVAL fModify AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fModify* | The new value for the modification flag. A value of **TRUE** indicates the text has been modified, and a value of **FALSE** indicates it has not been modified. |

#### Remarks

The system automatically clears the modification flag to zero when the control is created. If the user changes the control's text, the system sets the flag to nonzero. You can send the **RichEdit_GetModify** message to the edit control to retrieve the current state of the flag.

Rich Edit 1.0: Objects created without the **REO_DYNAMICSIZE** flag will lock in their extents when the modify flag is set to **FALSE**.

---

## RichEdit_SetOleCallback

Gives a rich edit control an **IRichEditOleCallback** object that the control uses to get OLE-related resources and information from the client.

```
FUNCTION RichEdit_SetOleCallback (BYVAL hRichEdit AS HWND, BYVAL pCallback AS ANY PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pCallback* | Pointer to an **IRichEditOleCallback** object. The control calls the **AddRef** method for the object before returning. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

---

## RichEdit_SetOptions

Sets the options for a rich edit control.

```
FUNCTION RichEdit_SetOptions (BYVAL hRichEdit AS HWND, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fCoop* | Specifies the operation, which can be one of these values.<br>**ECOOP_SET**. Sets the options to those specified by *fOptions*.<br>**ECOOP_OR**. Combines the specified options with the current options.<br>**ECOOP_AND**. Retains only those current options that are also specified by *fOptions*.<br>**ECOOP_XOR**. Logically exclusive OR the current options with those specified by *fOptions*. |
| *fOptions* | Specifies one or more of the following values.<br>**ECO_AUTOWORDSELECTION**- Automatic selection of word on double-click.<br>**ECO_AUTOVSCROLL**. Same as **ES_AUTOVSCROLL** style.<br>**ECO_AUTOHSCROLL**. Same as **ES_AUTOHSCROLL** style.<br>**ECO_NOHIDESEL**. Same as **ES_NOHIDESEL** style.<br>**ECO_READONLY**. Same as **ES_READONLY** style.<br>**ECO_WANTRETURN**. Same as **ES_WANTRETURN** style.<br>**ECO_SELECTIONBAR**. Same as **ES_SELECTIONBAR** style.<br>**ECO_VERTICAL**. Same as **ES_VERTICAL** style. Available in Asian-language versions only. |

#### Return value

This message returns the current options of the edit control.

---

## RichEdit_SetPageRotate

Deprecated. Sets the text layout for a Microsoft Rich Edit control.

```
FUNCTION RichEdit_SetPageRotate (BYVAL hRichEdit AS HWND, BYVAL txtlayout AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *txtlayout* | Text layout value. This can be one of the following values.<br>**EPR_0**. Text flows from left to right and from top to bottom.<br>**EPR_90**. Text flows from bottom to top and from left to right.<br>**EPR_180**. Text flows from right to left and from bottom to top.<br>**EPR_270**. Text flows from top to bottom and from right to left.<br>**EPR_SE**. Windows 8: Text flows top to bottom and left to right (Mongolian text layout). |

#### Return value

Return value is the new text layout value.

#### Remarks

This message sets the text layout for the entire document. However, embedded contents are not rotated and must be rotated separately by the application.

---

## RichEdit_SetPalette

Changes the palette that a rich edit control uses for its display window.

```
SUB RichEdit_SetPalette (BYVAL hRichEdit AS HWND, BYVAL newPalette AS HPALETTE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *newPalette* | Handle to the new palette used by the rich edit control. |

#### Remarks

The rich edit control does not check whether the new palette is valid.

---

## RichEdit_SetParaFormat

Sets the paragraph formatting for the current selection in a rich edit control.

```
FUNCTION RichEdit_SetParaFormat (BYVAL hRichEdit AS HWND, BYVAL pfmt AS PARAFORMAT PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pfmt* | pointer to a [PARAFORMAT](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-paraformat) structure specifying the new paragraph formatting attributes. Only the attributes specified by the **dwMask** member are changed. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

---

## RichEdit_SetPasswordChar

Sets or removes the password character for a rich edit control. When a password character is set, that character is displayed in place of the characters typed by the user.

```
SUB RichEdit_SetPasswordChar (BYVAL hRichEdit AS HWND, BYVAL dwchar AS DWORD)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *dwchar* | The character to be displayed in place of the characters typed by the user. If this parameter is zero, the control removes the current password character and displays the characters typed by the user. |

#### Return value

This message does not return a value.

#### Remarks

When an edit control receives the **EM_SETPASSWORDCHAR** message, the control redraws all visible characters using the character specified by the dwchar parameter. If *dwchar* is zero, the control redraws all visible characters using the characters typed by the user.

If an edit control is created with the **ES_PASSWORD** style, the default password character is set to an asterisk (*). If an edit control is created without the **ES_PASSWORD** style, there is no password character. The **ES_PASSWORD** style is removed if an **EM_SETPASSWORDCHAR** message is sent with the *dwchar* parameter set to zero.

**Edit controls**: Multiline edit controls do not support the password style or messages.

**Rich Edit**: Supported in Microsoft Rich Edit 2.0 and later. Both single-line and multiline edit controls support the password style and messages.

---

## RichEdit_SetPunctuation

Sets the punctuation characters for a rich edit control.

```
FUNCTION RichEdit_SetPunctuation (BYVAL hRichEdit AS HWND, BYVAL punctype AS LONG, BYVAL ppunct AS PUNCTUATION PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *punctype* | Specifies the punctuation type, which can be one of the following values.<br>**PC_LEADING**. Leading punctuation characters.<br>**PC_FOLLOWING**. Following punctuation characters.<br>**PC_DELIMITER**. Delimiter.<br>**PC_OVERFLOW**. Not supported. |
| *ppunct* | Pointer to a [PUNCTUATION](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-punctuation) structure that contains the punctuation characters. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

### Note

This message is supported only in Asian-language versions of Microsoft Rich Edit 1.0. It is not supported in any later versions.

---

## RichEdit_SetReadOnly

Sets or removes the read-only style (**ES_READONLY**) of a rich edit control.

```
FUNCTION RichEdit_SetReadOnly (BYVAL hRichEdit AS HWND, BYVAL fReadOnly AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fReadOnly* | Specifies whether to set or remove the **ES_READONLY** style. A value of **TRUE** sets the **ES_READONLY+* style; a value of **FALSE** removes the **ES_READONLY** style. |

#### Return value

If the operation succeeds, the return value is nonzero.

If the operation fails, the return value is zero.

#### Remarks

When an edit control has the **ES_READONLY** style, the user cannot change the text within the edit control.

To determine whether an edit control has the **ES_READONLY** style, use the Windows API **GetWindowLong** function with the **GWL_STYLE** flag.

**Rich Edit**: Supported in Microsoft Rich Edit 1.0 and later.

---

## RichEdit_SetRect

Sets the formatting rectangle of a multiline rich edit control.

```
SUB RichEdit_SetRect (BYVAL hRichEdit AS HWND, BYVAL fCoord AS LONG, BYVAL prect AS RECT PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fCoord* | **Rich Edit 2.0 and later**: Indicates whether *prect* specifies absolute or relative coordinates. A value of zero indicates absolute coordinates. A value of 1 indicates offsets relative to the current formatting rectangle. (The offsets can be positive or negative.)<br>**Edit controls and Rich Edit 1.0**: This parameter is not used and must be zero. |
| *prect* | A pointer to a [RECT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect) structure that specifies the new dimensions of the rectangle. If this parameter is **NULL**, the formatting rectangle is set to its default values. |

#### Remarks

Setting *prect* to **NULL** has no effect if a touch device is installed, or if **EM_SETRECT** is sent from a thread that has a hook installed (see [SetWindowsHookEx](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexw)). In these cases, *prect* should contain a valid pointer to a [RECT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect) structure.

The **EM_SETRECT** message causes the text of the edit control to be redrawn. To change the size of the formatting rectangle without redrawing the text, use the **EM_SETRECTNP** message.

When an edit control is first created, the formatting rectangle is set to a default size. You can use the **EM_SETRECT** message to make the formatting rectangle larger or smaller than the edit control window.

If the edit control does not have a horizontal scroll bar, and the formatting rectangle is set to be larger than the edit control window, lines of text exceeding the width of the edit control window (but smaller than the width of the formatting rectangle) are clipped instead of wrapped.

If the edit control contains a border, the formatting rectangle is reduced by the size of the border. If you are adjusting the rectangle returned by an **EM_GETRECT** message, you must remove the size of the border before using the rectangle with the **EM_SETRECT** message.

**Rich Edit**: Supported in Microsoft Rich Edit 1.0 and later. The formatting rectangle does not include the selection bar, which is an unmarked area to the left of each paragraph. When the user clicks in the selection bar, the corresponding line is selected.

---

## RichEdit_SetRectNP

Sets the formatting rectangle of a multiline rich edit control. The **EM_SETRECTNP** message is identical to the **EM_SETRECT** message, except that **EM_SETRECTNP** does not redraw the edit control window.

The formatting rectangle is the limiting rectangle into which the control draws the text. The limiting rectangle is independent of the size of the edit control window.

This message is processed only by multiline edit controls. You can send this message to either an edit control or a rich edit control.

```
SUB RichEdit_SetRectNP (BYVAL hRichEdit AS HWND, BYVAL fCoord AS LONG, BYVAL prect AS RECT PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *fCoord* | **Rich Edit 3.0 and later**: Indicates whether *prect* specifies absolute or relative coordinates. A value of zero indicates absolute coordinates. A value of 1 indicates offsets relative to the current formatting rectangle. (The offsets can be positive or negative.)<br>**Edit controls: This parameter is not used and must be zero. |
| *prect* | A pointer to a [RECT](https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect) structure that specifies the new dimensions of the rectangle. If this parameter is **NULL**, the formatting rectangle is set to its default values. |

#### Remarks

**Rich Edit**: Supported in Microsoft Rich Edit 3.0 and later.

---

## RichEdit_SetScrollPos

Scrolls the contents of a rich edit control to the specified point.

```
FUNCTION RichEdit_SetScrollPos (BYVAL hRichEdit AS HWND, BYVAL pt AS POINT PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pt* | Pointer to a [POINT]((https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-point)) structure which specifies a point in the virtual text space of the document, expressed in pixels. The document will be scrolled until this point is located in the upper-left corner of the edit control window. If you want to change the view such that the upper left corner of the view is two lines down and one character in from the left edge. You would pass a point of (7, 22).<br>The rich edit control checks the x and y coordinates and adjusts them if necessary, so that a complete line is displayed at the top. It also ensures that the text is never completely scrolled off the view rectangle. |

#### Return value

This message always returns 1.

---

## RichEdit_SetSel

Selects a range of characters in an edit control.

```
SUB RichEdit_SetSel (BYVAL hRichEdit AS HWND, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nStart* | The starting character position of the selection. |
| *nEnd* | The ending character position of the selection. |

#### Remarks

The start value can be greater than the end value. The lower of the two values specifies the character position of the first character in the selection. The higher value specifies the position of the first character beyond the selection.

The start value is the anchor point of the selection, and the end value is the active end. If the user uses the SHIFT key to adjust the size of the selection, the active end can move but the anchor point remains the same.

If the start is 0 and the end is -1, all the text in the edit control is selected. If the start is -1, any current selection is deselected.

**Edit controls**: The control displays a flashing caret at the end position regardless of the relative values of start and end.

**Rich Edit**: Supported in Microsoft Rich Edit 1.0 and later.

If the edit control has the **ES_NOHIDESEL** style, the selected text is highlighted regardless of whether the control has focus. Without the **ES_NOHIDESEL** style, the selected text is highlighted only when the edit control has the focus.

---

## RichEdit_SetStoryType

Sets the story type.

```
FUNCTION RichEdit_SetStoryType (BYVAL hRichEdit AS HWND, BYVAL Index AS LONG, BYVAL dwType AS DWORD) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *Index* | The story index. |
| *dwType* | The new story type. See the list below. |

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **tomCommentsStory** | 4 | The story used for comments. |
| **tomEndnotesStory** | 3 | The story used for endnotes. |
| **tomEvenPagesFooterStory** | 8 | The story containing footers for even pages. |
| **tomEvenPagesHeaderStory** | 6 | The story containing headers for even pages. |
| **tomFindStory** | 128 | The story used for a Find dialog. |
| **tomFirstPageFooterStory** | 11 | The story containing the footer for the first page. |
| **tomFirstPageHeaderStory** | 10 | The story containing the header for the first page. |
| **tomFootnotesStory** | 2 | The story used for footnotes. |
| **tomMainTextStory** | 1 | The main story always exists for a rich edit control. |
| **tomPrimaryFooterStory** | 9 | The story containing footers for odd pages. |
| **tomPrimaryFooterStory** | 7 | The story containing headers for odd pages. |
| **tomReplaceStory** | 129 | The story used for a Replace dialog. |
| **tomScratchStory** | 127 | The scratch story. |
| **tomTextFrameStory** | 5 | The story used for a text box. |
| **tomUnknownStory** | 0 | No special type. |

#### Return value

The story type that was set.

---

## RichEdit_SetTableParams

Changes the parameters of rows in a table.

```
FUNCTION RichEdit_SetTableParams (BYVAL hRichEdit AS HWND, BYVAL lptp AS TABLEROWPARMS PTR, _
   BYVAL lptcp AS TABLECELLPARMS PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *lptp* | A pointer to a [TABLEROWPARMS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-tablerowparms) structure. |
| *lptcp* | A pointer to a [TABLECELLPARMS](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-tablecellparms) structure. |

#### Return value

Returns **S_OK** if successful, or one of the following error codes.

| Return code  | Description |
| ------------ | ----------- |
| **E_FAIL** | Changes cannot be made. This can occur if the control is a plain-text or single-line control, or if the insertion point is inside a math object. It also occurs if tables are disabled if the **RichEdit_SetEditStyleEx** message sets the **SES_EX_NOTABLE** value. |
| **E_INVALIDARG** | The *lptp* or *lptcp* parameters are NULL or point to an invalid structure. The **cbRow** member of the **TABLEROWPARMS** structure must equal sizeof(TABLEROWPARMS) or sizeof(TABLEROWPARMS) 2*sizeof(long). The latter value is the size of the RichEdit 4.1 **TABLEROWPARMS** structure. The **cbCell** member of the **TABLEROWPARMS** structure must equal sizeof(TABLECELLPARMS). The query character position must be at a table row delimiter. |
| **E_OUTOFMEMORY** | Insufficient memory is available. |

#### Remarks

This message changes the parameters of the number of rows specified by the **cRow** member of the **TABLEROWPARMS** structure, if the table has that many consecutive rows. If **cRow** is less than 0, the message iterates until the end of the table. If the new cell count differs from the current cell count by +1 or 1, it inserts or deletes the cell at the index specified by the **iCell** member of **TABLEROWPARMS**. The starting table row is identified by a character position. This position is specified by **cpStartRow** members with values that are greater than or equal to zero. The position should be inside the table row, but not inside a nested table, unless you want to change that table s parameters. If the **cpStartRow** member is 1, the character position is given by the current selection. For this, position the selection anywhere inside the table row, or select the row with the active end of the selection at the end of the table row.

---

## RichEdit_SetTabStops

Sets the tab stops in a multiline rich edit control. The **EM_SETTABSTOPS** message sets the tab stops in a multiline edit control. When text is copied to the control, any tab character in the text causes space to be generated up to the next tab stop. This message is processed only by multiline edit controls.

```
FUNCTION RichEdit_SetTabStops (BYVAL hRichEdit AS HWND, BYVAL nTabs AS LONG, BYVAL rgTabStops AS LONG_PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nTabs* | The number of tab stops contained in the array. If this parameter is zero, the *rgTabStops* parameter is ignored and default tab stops are set at every 32 dialog template units. If this parameter is 1, tab stops are set at every n dialog template units, where n is the distance pointed to by the *rgTabStops* parameter. If this parameter is greater than 1, *rgTabStops* is a pointer to an array of tab stops. |
| *rgTabStops* | A pointer to an array of unsigned integers specifying the tab stops, in dialog template units. If the *nTabs* parameter is 1, this parameter is a pointer to an unsigned integer containing the distance between all tab stops, in dialog template units. |

#### Return value

If all the tabs are set, the return value is *TRUE*.

If all the tabs are not set, the return value is *FALSE*.

#### Remarks

The **EM_SETTABSTOPS** message does not automatically redraw the edit control window. If the application is changing the tab stops for text already in the edit control, it should call the Windows API **InvalidateRect** function to redraw the edit control window.

The values specified in the array are in dialog template units, which are the device-independent units used in dialog box templates. To convert measurements from dialog template units to screen units (pixels), use the Windows API **MapDialogRect** function.

**Rich Edit**: Supported in Microsoft Rich Edit 3.0 and later. A rich edit control can have the maximum number of tab stops specified by **MAX_TAB_STOPS**.

---

## RichEdit_SetTargetDevice

Sets the target device and line width used for WYSIWYG formatting in a rich edit control.

```
FUNCTION RichEdit_SetTargetDevice (BYVAL hRichEdit AS HWND, BYVAL hDC AS HDC, BYVAL lnwidth AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *hDC* | HDC [Handle to a Device Context] for the target device. |
| *lnwidth* | Line width to use for formatting. |

#### Return value

The return value is zero if the operation fails, or nonzero if it succeeds.

#### Remarks

The HDC for the default printer can be obtained as follows.

```
DIM hdc AS HDC
DIM pd AS PRINTDLGW
pd.lStructSize = SIZEOF(pd)
pd.flags = PD_RETURNDC OR PD_RETURNDEFAULT
IF PrintDlgW(@pd) THEN
   hdc =  = pd.hDC
END IF
```

If *lnwidth* is zero, no line breaks are created.

---

## RichEdit_SetText

Sets the text of an edit control.

```
FUNCTION RichEdit_SetText (BYVAL hRichEdit AS HWND, BYVAL pwszText AS WSTRING PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pwszText* | A pointer to a null-terminated string that is the window text. |

#### Return value

The return value is **TRUE** if the text is set.

---

## RichEdit_SetTextExW

Sets the text of an edit control. Combines the functionality of the **WM_SETTEXT** and **EM_REPLACESEL** messages, and adds the ability to set text using a code page and to use either rich text or plain text.

```
FUNCTION RichEdit_SetTextExW (BYVAL hRichEdit AS HWND, BYVAL pstex AS SETTEXTEX PTR, BYVAL pwszText AS WSTRING PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pstex* | Pointer to a [SETTEXTEX](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-settextex) structure that specifies flags and an optional code page to use in translating to Unicode. |
| *pwszText* | Pointer to the null-terminated text to insert. This text is an ANSI string, unless the code page is 1200 (Unicode). If *pwszText* starts with a valid RTF ASCII sequence for example, "{\rtf" or "{urtf" the text is read in using the RTF reader. |

#### Return value

If the operation is setting all of the text and succeeds, the return value is 1.

If the operation is setting the selection and succeeds, the return value is the number of bytes or characters copied.

If the operation fails, the return value is zero.

---

## RichEdit_SetTextMode

Sets the text mode or undo level of a rich edit control. The message fails if the control contains any text.

```
FUNCTION RichEdit_SetTextMode (BYVAL hRichEdit AS HWND, BYVAL pvalues AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pvalues* | One or more values from the [TEXTMODE](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ne-richedit-textmode) enumeration type. The values specify the new settings for the control's text mode and undo level parameters. |

Specify one of the following values to set the text mode parameter. If you do not specify a text mode value, the text mode remains at its current setting.

| Value  | Meaning |
| ------ | ----------- |
| **TM_PLAINTEXT** | Indicates plain text mode, in which the control is similar to a standard edit control. For more information about plain text mode, see the **Remarks** section. |
| **TM_RICHTEXT** | Indicates rich text mode, in which the control has standard rich edit functionality. Rich text mode is the default setting. |

Specify one of the following values to set the undo level parameter. If you do not specify an undo level value, the undo level remains at its current setting.

| Value  | Meaning |
| ------ | ----------- |
| **TM_SINGLELEVELUNDO** | The control allows the user to undo only the last action that can be undone. |
| **TM_MULTILEVELUNDO** | The control supports multiple undo operations. This is the default setting. Use the **RichEdit_SetUndoLimit** message to set the maximum number of undo actions. |

Specify one of the following values to set the code page parameter. If you do not specify an code page value, the code page remains at its current setting.

| Value  | Meaning |
| ------ | ----------- |
| **TM_SINGLECODEPAGE** | The control only allows the English keyboard and a keyboard corresponding to the default character set. For example, you could have Greek and English. Note that this prevents Unicode text from entering the control. For example, use this value if a Rich Edit control must be restricted to ANSI text. |
| **TM_MULTICODEPAGE** | The control allows multiple code pages and Unicode text into the control. This is the default setting. |

#### Return value

If the message succeeds, the return value is zero.

If the message fails, the return value is a nonzero value.

#### Remarks

In rich text mode, a rich edit control has standard rich edit functionality. However, in plain text mode, the control is similar to a standard edit control:

- The text in a plain text control can have only one format (such as Bold, 10pt Arial).
- The user cannot paste rich text formats, such as Rich Text Format (RTF) or embedded objects into a plain text control.
- Rich text mode controls always have a default end-of-document marker or carriage return, to format paragraphs. Plain text controls, on the other hand, do not need the default, end-of-document marker, so it is omitted.

The control must contain no text when it receives the **RichEdit_SetText** message. To ensure there is no text, send a **RichEdit_SetText** message with an empty string ("").

---

## RichEdit_SetTouchOptions

Sets the touch options associated with a rich edit control.

```
SUB RichEdit_SetTouchOptions (BYVAL hRichEdit AS HWND, BYVAL Options AS LONG, BYVAL fEnable AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *Options* | The touch options to set. It can be one of the following values. |
| *fEnable* | Set to **TRUE** to show/enable the touch selection handles, or **FALSE** to hide/disable the touch selection handles. |

| Value  | Meaning |
| ------ | ------- |
| **RTO_SHOWHANDLES** | Show or hide the touch gripper handles, depending on the value of *Options*. |
| **RTO_DISABLEHANDLES** | Enable or disable the touch gripper handles, depending on the value of *Options*. When handles are disabled, they are hidden if they are visible and remain hidden until an **RichEdit_SetTouchOptions** message changes their status. |

---

## RichEdit_SetTypographyOptions

Sets the current state of the typography options of a rich edit control.

```
FUNCTION RichEdit_SetTypographyOptions (BYVAL hRichEdit AS HWND, BYVAL pto AS LONG, BYVAL fMask AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pto* | Specifies one or both of the following values.<br>**TO_ADVANCEDTYPOGRAPHY**. Advanced line breaking and line formatting is turned on.<br>**TO_SIMPLELINEBREAK**. Faster line breaking for simple text (requires **TO_ADVANCEDTYPOGRAPHY**). |
| *fMask* | A mask consisting of one or more of the flags in *pto*. Only the flags that are set in this mask will be set or cleared. This allows a single flag to be set or cleared without reading the current flag states. |

#### Return value

Returns **TRUE** if *pto* is valid, otherwise **FALSE**.

#### Remarks

Advanced line breaking is turned on automatically by the rich edit control when needed, such as for handling complex scripts like Arabic and Hebrew, and for mathematics. It s also needed for justified paragraphs, hyphenation, and other typographic features.

---

## RichEdit_SetUIAName

Sets the name of a rich edit control for UI Automation (UIA).

```
FUNCTION RichEdit_SetUIAName (BYVAL hRichEdit AS HWND, BYVAL pwszName AS WTRING PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *bstrName* | A pointer to the null-terminated name string. |

#### Return value

**TRUE** if the name for UIA is successfully set, otherwise **FALSE**.

---

## RichEdit_SetUndoLimit

Sets the maximum number of actions that can stored in the undo queue of a rich edit control.

```
FUNCTION RichEdit_SetUndoLimit (BYVAL hRichEdit AS HWND, BYVAL maxactions AS DWORD) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *maxactions* | Specifies the maximum number of actions that can be stored in the undo queue. |

#### Return value

The return value is the new maximum number of undo actions for the rich edit control. This value may be less than *maxactions* if memory is limited.

#### Remarks

By default, the maximum number of actions in the undo queue is 100. If you increase this number, there must be enough available memory to accommodate the new number. For better performance, set the limit to the smallest possible value.

Setting the limit to zero disables the **Undo** feature.

---

## RichEdit_SetWordBreakProc

Replaces a rich edit control's default Wordwrap function with an application-defined Wordwrap function.

```
SUB RichEdit_SetWordBreakProc (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pfn* | The address of the application-defined Wordwrap function. For more information about breaking lines, see the description of the [EditWordBreakProc](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nc-winuser-editwordbreakprocw) callback function. |

#### Remarks

A Wordwrap function scans a text buffer that contains text to be sent to the screen, looking for the first word that does not fit on the current screen line. The Wordwrap function places this word at the beginning of the next line on the screen.

A Wordwrap function defines the point at which the system should break a line of text for multiline edit controls, usually at a space character that separates two words. Either a multiline or a single-line edit control might call this function when the user presses arrow keys in combination with the CTRL key to move the caret to the next word or previous word. The default Wordwrap function breaks a line of text at a space character. The application-defined function may define the Wordwrap to occur at a hyphen or a character other than the space character.

**Rich Edit**: Supported in Microsoft Rich Edit 1.0 and later.

---

## RichEdit_SetWordBreakProcEx

Sets the extended word-break procedure.

```
FUNCTION RichEdit_SetWordBreakProcEx (BYVAL hRichEdit AS HWND, BYVAL pfn AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pfn* | Pointer to an [EditWordBreakProcEx](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-editwordbreakprocex) function, or **NULL** to use the default procedure. |

#### Return value

This message returns the address of the previous extended word-break procedure.

---

## RichEdit_SetWordWrapMode

Sets the word-wrapping and word-breaking options for a rich edit control.

```
FUNCTION RichEdit_SetWordWrapMode (BYVAL hRichEdit AS HWND, BYVAL values AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *pvalues* | Specifies one or more of the following values. |

| Value  | Meaning |
| ------ | ------- |
| **WBF_WORDWRAP** | Enables Asian-specific word wrap operations, such as kinsoku in Japanese. |
| **WBF_WORDBREAK** | Enables English word-breaking operations in Japanese and Chinese. Enables Hangeul word-breaking operation. |
| **WBF_OVERFLOW** | Recognizes overflow punctuation. (Not currently supported.) |
| **WBF_LEVEL1** | Sets the Level 1 punctuation table as the default. |
| **WBF_LEVEL2** | Sets the Level 2 punctuation table as the default. |
| **WBF_CUSTOM** | Sets the application-defined punctuation table. |

#### Return value

This message returns the current word-wrapping and word-breaking options.

#### Remarks

This message must not be sent by the application defined word breaking procedure.

---

## RichEdit_SetZoom

Sets the zoom ratio for a multiline edit control or a rich edit control. The ratio must be a value between 1/64 and 64. The edit control needs to have the **ES_EX_ZOOMABLE** extended style set, for this message to have an effect, see [Edit Control Extended Styles](https://learn.microsoft.com/en-us/windows/win32/controls/edit-control-window-extended-styles).

```
FUNCTION RichEdit_SetZoom (BYVAL hRichEdit AS HWND, BYVAL zNum AS DWORD, BYVAL zDen AS DWORD) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *zNum* | Numerator of the zoom ratio. |
| *zDen* | Denominator of the zoom ratio. These parameters can have the following values. |

| Value  | Meaning |
| ------ | ------- |
| **Both 0** | Turns off zooming by using the **EM_SETZOOM** message (zooming may still occur using [TxGetExtent](https://learn.microsoft.com/en-us/windows/win32/api/textserv/nf-textserv-itexthost-txgetextent). |
| **1/64 < (wParam / lParam) < 64** | Zooms display by the zoom ratio numerator/denominator |

#### Return value

If the new zoom setting is accepted, the return value is **TRUE**.

If the new zoom setting is not accepted, the return value is **FALSE**.

---

## RichEdit_ShowScrollBar

Shows or hides one of the scroll bars in the host window of a rich edit control.

```
SUB RichEdit_ShowScrollBar (BYVAL hRichEdit AS HWND, BYVAL nScrollBar AS DWORD, BYVAL fShow AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *nScrollBar* | Identifies which scroll bar to display: horizontal or vertical. This parameter must be **SB_VERT** or **SB_HORZ**. |
| *fShow* | Specifies whether to show the scroll bar or hide it. Specify **TRUE** to show the scroll bar and **FALSE** to hide it. |

#### Remarks

This message is only valid when the control is in-place active. Calls made while the control is inactive may fail.

---

## RichEdit_StopGroupTyping

Stops a rich edit control from collecting additional typing actions into the current undo action. The control stores the next typing action, if any, into a new action in the undo queue.

```
FUNCTION RichEdit_StopGroupTyping (BYVAL hRichEdit AS HWND) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

The return value is zero. This message cannot fail.

#### Remarks
A rich edit control groups consecutive typing actions, including characters deleted by using the BackSpace key, into a single undo action until one of the following events occurs:

- The control receives an **EM_STOPGROUPTYPING** message.
- The control loses focus.
- The user moves the current selection, either by using the arrow keys or by clicking the mouse.
- The user presses the **Delete** key.
- The user performs any other action, such as a paste operation that does not involve typing.

You can send the **RichEdit_StopGroupTyping** message to break consecutive typing actions into smaller undo groups. For example, you could send **RichEdit_StopGroupTyping** after each character or at each word break.

---

## RichEdit_StreamIn

Replaces the contents of a rich edit control with a stream of data provided by an application defined [EditStreamCallback](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-editstreamcallback) callback function.

```
FUNCTION RichEdit_StreamIn (BYVAL hRichEdit AS HWND, BYVAL psf AS LONG, BYVAL pedst AS EDITSTREAM PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *psf* | Specifies the data format and replacement options. This value must be one of the following values (see table below). |
| *pedst* | Pointer to an [EDITSTREAM](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-editstream) structure. On input, the **pfnCallback** member of this structure must point to an application defined **EditStreamCallback** function. On output, the **dwError** member can contain a nonzero error code if an error occurred. |

#### Data format and replacement options

| Value  | Meaning |
| ------ | ------- |
| **SF_RTF** | RTF |
| **SF_TEXT** | Text |

In addition, you can specify the following flags.

| Value  | Meaning |
| ------ | ------- |
| **SFF_PLAINRTF** | If specified, only keywords common to all languages are streamed in. Language-specific RTF keywords in the stream are ignored. If not specified, all keywords are streamed in. You can combine this flag with the **SF_RTF** flag. |
| **SFF_SELECTION** | If specified, the data stream replaces the contents of the current selection. If not specified, the data stream replaces the entire contents of the control. You can combine this flag with the **SF_TEXT** or **SF_RTF** flags. |
| **SF_UNICODE** | **Rich Edit 2.0 and later**: Indicates Unicode text. You can combine this flag with the **SF_TEXT** flag. |
| **SF_USECODEPAGE** | **Rich Edit 3.0 and later**: Reads UTF-8 RTF and text using other code pages. The code page is set in the high word of *psf*. For example, for UTF-8 RTF, set *psf* to (CP_UTF8 << 16) | SF_USECODEPAGE | SF_RTF. |

#### Return value

This message returns the number of characters read.

#### Remarks

When you send an **RichEdit_StreamIn** message, the rich edit control makes repeated calls to the **EditStreamCallback** function specified by the **pfnCallback** member of the [EDITSTREAM](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-editstream) structure. Each time the callback function is called, it fills a buffer with data to read into the control. This continues until the callback function indicates that the stream-in operation has been completed or an error occurs.

---

## RichEdit_StreamOut

Causes a rich edit control to pass its contents to an application defined [EditStreamCallback](https://learn.microsoft.com/en-us/windows/win32/api/richedit/nc-richedit-editstreamcallback) callback function. The callback function can then write the stream of data to a file or any other location that it chooses.

```
FUNCTION RichEdit_StreamOut (BYVAL hRichEdit AS HWND, BYVAL psf AS LONG, BYVAL pedst AS EDITSTREAM PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *psf* | Specifies the data format and replacement options. This value must be one of the following values (see table below). |
| *pedst* | Pointer to an [EDITSTREAM](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-editstream) structure. On input, the **pfnCallback** member of this structure must point to an application defined **EditStreamCallback** function. On output, the **dwError** member can contain a nonzero error code if an error occurred. |

#### Data format and replacement options

| Value  | Meaning |
| ------ | ------- |
| **SF_RTF** | RTF |
| **SF_RTFNOOBJS** | RTF with spaces in place of COM objects. |
| **SF_TEXT** | Text |
| **SF_TEXTIZED** | Text with a text representation of COM objects. |

The **SF_RTFNOOBJS** option is useful if an application stores COM objects itself, as RTF representation of COM objects is not very compact. The control word, \objattph, followed by a space denotes the object position.

In addition, you can specify the following flags.

| Value  | Meaning |
| ------ | ------- |
| **SFF_PLAINRTF** | If specified, the rich edit control streams out only the keywords common to all languages, ignoring language-specific keywords. If not specified, the rich edit control streams out all keywords. You can combine this flag with the SF_RTF or **SF_RTFNOOBJS** flag. |
| **SFF_SELECTION** | If specified, the rich edit control streams out only the contents of the current selection. If not specified, the control streams out the entire contents. You can combine this flag with any of data format values. |
| **SF_UNICODE** | **Rich Edit 2.0 and later**: Indicates Unicode text. You can combine this flag with the **SF_TEXT** flag. |
| **SF_USECODEPAGE** | **Rich Edit 3.0 and later**: Reads UTF-8 RTF and text using other code pages. The code page is set in the high word of *psf*. For example, for UTF-8 RTF, set *psf* to (CP_UTF8 << 16) | SF_USECODEPAGE | SF_RTF. |

#### Return value

This message returns the number of characters written to the data stream.

#### Remarks

When you send an **RichEdit_StreamOut** message, the rich edit control makes repeated calls to the **EditStreamCallback** function specified by the **pfnCallback** member of the [EDITSTREAM](https://learn.microsoft.com/en-us/windows/win32/api/richedit/ns-richedit-editstream) structure.  Each time it calls the callback function, the control passes a buffer containing a portion of the contents of the control. This process continues until the control has passed all its contents to the callback function, or until an error occurs.

---

## RichEdit_Undo

This message undoes the last edit control operation in the control's undo queue.

```
FUNCTION RichEdit_Undo (BYVAL hRichEdit AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

For a single-line edit control, the return value is always **TRUE**.

For a multiline edit control, the return value is **TRUE** if the undo operation is successful, or **FALSE** if the undo operation fails.

#### Remarks

**Edit controls and Rich Edit 1.0**: An undo operation can also be undone. For example, you can restore deleted text with the first **EM_UNDO** message, and remove the text again with a second **EM_UNDO** message as long as there is no intervening edit operation.

**Rich Edit 2.0 and later**: The undo feature is multilevel so sending two **EM_UNDO** messages will undo the last two operations in the undo queue. To redo an operation, send the **EM_REDO** message.

**Rich Edit**: Supported in Microsoft Rich Edit 1.0 and later.

---

## RichEdit_SetFont

Sets the font used by a rich edit control.

```
FUNCTION RichEdit_SetFont (BYVAL hRichEdit AS HWND, BYREF wszFaceName AS WSTRING, BYVAL ptsize AS LONG) AS LRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *wszFaceName* | The font name. |
| *ptsize* | The font size in points. |

#### Return value

If the operation succeeds, the return value is a nonzero value.

If the operation fails, the return value is zero.

---

## RichEdit_LoadRtfFromFile

Loads the contents of a RTF file into a Rich Edit control.

```
FUNCTION RichEdit_LoadRtfFromFile (BYVAL hRichEdit AS HWND, BYREF wszFileName AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *wszFileName* | The name of the RTF file to load. |

#### Return value

If the operation succeeds, the return value is **TRUE**.

If the operation fails, the return value is **FALSE**.

---

## RichEdit_LoadRtfFromResource

Loads a RTF resource file into a Rich Edit control.

```
FUNCTION RichEdit_LoadRtfFromResourceW (BYVAL hRichEdit AS HWND, BYVAL hInstance AS HINSTANCE, _
   BYREF wszResourceName AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |
| *hInstance* | The instance handle. |
| *wszResourceName* | The name of the resource to load. |

#### Return value

If the operation succeeds, the return value is **TRUE**.

If the operation fails, the return value is **FALSE**.

---

## RichEdit_GetRtfText

Retrieves RTF formatted text from a Rich Edit control.

```
FUNCTION RichEdit_GetRtfText (BYVAL hRichEdit AS HWND) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRichEdit* | The handle of the rich edit control. |

#### Return value

Returns the retrieved text or a null string.

---
