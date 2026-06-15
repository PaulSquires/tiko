# CToolbar Class

A toolbar is a control that contains one or more buttons. Each button, when clicked by a user, sends a command message to the parent window. Typically, the buttons in a toolbar correspond to items in the application's menu, providing an additional and more direct way for the user to access an application's commands.

See: [About Toolbar Controls](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-controls-overview)

**Include file**: CToolbar.inc

| Name       | Description |
| ---------- | ----------- |
| [AddBitmap](#addbitmap) | Adds one or more images to the list of button images available for a toolbar. |
| [AddButton](#addbutton) | Adds a button to a toolbar. |
| [AddButtons](#addbuttons) | Adds one or more buttons to a toolbar. |
| [AddSeparator](#addseparator) | Adds a separator to a toolbar. |
| [AddString](#addstring) | Adds a new string to the toolbar's string pool. |
| [AutoSize](#autorize) | Causes a toolbar to be resized. |
| [ButtonCount](#buttoncount) | Retrieves a count of the buttons currently in the toolbar. |
| [ButtonStructSize](#buttonstructsize) | Retrieves a count of the buttons currently in the toolbar. |
| [ChangeBitmap](#changebitmap) | Retrieves a count of the buttons currently in the toolbar. |
| [CheckButton](#checkbutton) | Checks a given button in a toolbar. |
| [CommandToIndex](#commandtoindex) | Retrieves the zero-based index for the button associated with the specified command identifier. |
| [Customize](#customsize) | Displays the Customize Toolbar dialog box. |
| [DeleteButton](#deletebutton) | Deletes a button from the toolbar. |
| [DisableButton](#disablebutton) | Disables the specified button in a toolbar. |
| [EnableButton](#enablebutton) | Enables the specified button in a toolbar. |
| [GetAnchorHighlight](#getanchorhighlight) | Retrieves the anchor highlight setting for a toolbar. |
| [GetBitmap](#getbitmap) | Retrieves the index of the bitmap associated with a button in a toolbar. |
| [GetBitmapFlags](#getbitmapflags) | Retrieves the flags that describe the type of bitmap to be used. |
| [GetButton](#getbutton) | Retrieves information about the specified button in a toolbar. |
| [GetButtonHeight](#getbuttonheight) | Retrieves the current height of toolbar buttons, in pixels. |
| [GetButtonInfo](#getbuttoninfo) | Retrieves extended information for a button in a toolbar. |
| [GetButtonSize](#getbuttonsize) | Retrieves the current width and height of toolbar buttons, in pixels. |
| [GetButtonText](#getbuttontext) | Retrieves the display text of a button on a toolbar. |
| [GetButtonTextLength](#getbuttontextlength) | Retrieves the length of the display text of a button on a toolbar. |
| [GetButtonWidth](#getbuttonwidth) | Retrieves the current width of toolbar buttons, in pixels. |
| [GetColorScheme](#getcolorscheme) | Retrieves the color scheme information from the toolbar control. |
| [GetDisabledImageList](#getdisabledimagelist) | Retrieves the image list that a toolbar control uses to display inactive buttons. |
| [GetExtendedStyle](#getextendedstyle) | Retrieves the extended styles for a toolbar control. |
| [GetHorizontalPadding](#gethorizontalpadding) | Retrieves the horizontal padding for a toolbar control. |
| [GetHotImageList](#gethotimagelist) | Retrieves the image list that a toolbar control uses to display hot buttons. |
| [GetHotItem](#gethotitem) | Retrieves the index of the hot item in a toolbar. |
| [GetImageList](#getimagelist) | Retrieves the image list that a toolbar control uses to display buttons in their default state. |
| [GetImageListCount](#getimagelistcount) | Returns the number of image lists. |
| [GetInsertMark](#getinsertmark) | Retrieves the current insertion mark for the toolbar. |
| [GetInsertMarkColor](#getinsertmarkcolor) | Retrieves the color used to draw the insertion mark for the toolbar. |
| [GetItemRect](#getitemrect) | Retrieves the bounding rectangle of a button in a toolbar. |
| [GetMaxSize](#getmaxsize) | Retrieves the total size of all of the visible buttons and separators in the toolbar. |
| [GetMetrics](#getmetrics) | Retrieves the metrics of a toolbar control. |
| [GetObject](#getobject) | Retrieves the IDropTarget for a toolbar control. |
| [GetPadding](#getpadding) | Retrieves the padding for a toolbar control. |
| [GetRect](#getrect) | Retrieves the bounding rectangle for a specified toolbar button. |
| [GetRows](#getrows) | Retrieves the number of rows of buttons in a toolbar with the TBSTYLE_WRAPABLE style. |
| [GetState](#getstate) | Retrieves information about the state of the specified button in a toolbar, such as whether it is enabled, pressed, or checked. |
| [GetString](#getstring) | Retrieves a string from a toolbar's string pool. |
| [GetStyle](#getstyle) | Retrieves the styles currently in use for a toolbar control. |
| [GetTextRows](#gettextrows) | Retrieves the number of rows of buttons in a toolbar with the TBSTYLE_WRAPABLE style. |
| [GetTooltips](#gettooltips) | Retrieves the handle to the tooltip control, if any, associated with the toolbar. |
| [GetVerticalPadding](#getverticalpadding) | Retrieves the vertical padding for a toolbar control. |
| [HideButton](#hidebutton) | Hides or shows the specified button in a toolbar. |
| [HighlightButton](#highlightbutton) | Sets the highlight state of a given button in a toolbar control. |
| [HitTest](#hittest) | Determines where a point lies in a toolbar control. |
| [Indeterminate](#intermediate) | Sets or clears the indeterminate state of the specified button in a toolbar. |
| [InsertButton](#insertbutton) | Inserts a button in a toolbar. |
| [InsertMarkHitTest](#insertmarkhittest) | Retrieves the insertion mark information for a point in a toolbar. |
| [InsertSeparator](#insertseparator) | Inserts a separator in a toolbar. |
| [IsButtonChecked](#isbuttonchecked) | Determines whether the specified button in a toolbar is checked. |
| [IsButtonEnabled](#isbuttonenabled) | Determines whether the specified button in a toolbar is enabled. |
| [IsButtonHidden](#isbuttonhidden) | Determines whether the specified button in a toolbar is hidden. |
| [IsButtonHighlighted](#isbuttonhighlighted) | Checks the highlight state of a toolbar button. |
| [IsButtonIndeterminate](#isbuttonindeterminate) | Determines whether the specified button in a toolbar is indeterminate. |
| [IsButtonPressed](#isbuttonpressed) | Determines whether the specified button in a toolbar is pressed. |
| [LoadImages](#loadimages) | Loads system-defined button images into a toolbar control's image list. |
| [MakeOpaque](#makeopaque) | Makes the toolbar opaque by removing the TBSTYLE_TRANSPARENT style. |
| [MapAccelerator](#mapaccelerator) | Determines the ID of the button that corresponds to the specified accelerator character. |
| [MarkButton](#markbutton) | Sets the highlight state of a given button in a toolbar control. |
| [MoveButton](#movebutton) | Moves a button from one index to another. |
| [PressButton](#pressbutton) | Presses the specified button in a toolbar. |
| [ReleaseButton](#pressbutton) | Releases the specified button in a toolbar. |
| [RemoveDarkMode](#removedarkmode) | Removes the toolbar dark mode. |
| [ReplaceBitmap](#replacebitmap) | Replaces an existing bitmap with a new bitmap. |
| [SaveRestore](#saverestore) | Send this message to initiate saving or restoring a toolbar state. |
| [SetAnchorHighlight](#setanchorhighlight) | Sets the anchor highlight setting for a toolbar. |
| [SetBitmapSize](#setbitmapsize) | Sets the size of the bitmapped images to be added to a toolbar. |
| [SetButtonInfo](#setbuttoninfo) | Sets the information for an existing button in a toolbar. |
| [SetButtonSize](#setbuttonsize) | Sets the size of buttons on a toolbar. |
| [SetButtonWidth](#setbuttonwidth) | Sets the minimum and maximum button widths in the toolbar control. |
| [SetCmdId](#setcmdid) | Sets the command identifier of a toolbar button. |
| [SetColorScheme](#setcolorscheme) | Sets the color scheme information for the toolbar control. |
| [SetDarkMode](#setdarkmode) | Sets the toolbar dark mode. |
| [SetDisabledImageList](#setdisabledimagelist) | Sets the image list that the toolbar control will use to display disabled buttons. |
| [SetDrawTextFlags](#setdrawtextflags) | Sets the text drawing flags for the toolbar. |
| [SetExtendedStyle](#setextendedstyle) | Sets the extended styles for a toolbar control. |
| [SetHotImageList](#sethotimagelist) | Sets the image list that the toolbar control will use to display hot buttons. |
| [SetHotItem](#sethotitem) | Sets the hot item in a toolbar. |
| [SetImageList](#setimagelist) | Sets the image list that the toolbar will use to display buttons that are in their default state. |
| [SetIndent](#setindent) | Sets the indentation for the first button in a toolbar control. |
| [SetInsertMark](#setinsertmark) | Sets the current insertion mark for the toolbar. |
| [SetInsertMarkColor](#setinsertmarkcolor) | Sets the color used to draw the insertion mark for the toolbar. |
| [SetListGap](#setlistgap) | Sets the distance between the toolbar buttons on a specific toolbar. |
| [SetMaxTextRows](#setmaxtextrows) | Sets the maximum number of text rows displayed on a toolbar button. |
| [SetMetrics](#setmetrics) | Sets the metrics of a toolbar control. |
| [SetPadding](#setpadding) | Sets the padding for a toolbar control. |
| [SetParent](#setparent) | Sets the window to which the toolbar control sends notification messages. |
| [SetPressedImageList](#setpressedimagelist) | Sets the image list that the toolbar uses to display buttons that are in a pressed state. |
| [SetRows](#setrows) | Sets the number of rows of buttons in a toolbar. |
| [SetState](#setstate) | Sets the state for the specified button in a toolbar. |
| [SetStyle](#setstyle) | Sets the style for a toolbar control. |
| [SetToolTips](#settoolTips) | Associates a tooltip control with a toolbar. |
| [SetWindowTheme](#setwindowtheme) | Sets the visual style of a toolbar control. |
| [UncheckButton](#checkbutton) | Unchecks a given button in a toolbar. |
| [UnhideButton](#hidebutton) | Unhides the specified button in a toolbar. |
| [UnhighlightButton](#highlightbutton) | Removes the highlight state of a given button in a toolbar control. |

---

### AddBitmap

Adds one or more images to the list of button images available for a toolbar.

```
FUNCTION AddBitmap (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYVAL ptabm AS TBADDBITMAP PTR) AS LONG
FUNCTION AddBitmap (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYREF tabm AS TBADDBITMAP) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *nButtons* | Number of button images in the bitmap. If *ptabm* specifies a system-defined bitmap, this parameter is ignored. |
| *ptabm* | Pointer to a **TBADDBITMAP** structure that contains the identifier of a bitmap resource and the handle to the module instance with the executable file that contains the bitmap resource. |
| *tabm* | A **TBADDBITMAP** structure that contains the identifier of a bitmap resource and the handle to the module instance with the executable file that contains the bitmap resource. |

#### Return value

Returns the index of the first new image if successful, or -1 otherwise.

#### Remarks

If the toolbar was created using the **CreateWindowExW** function, you must send the **TB_BUTTONSTRUCTSIZE** message to the toolbar before sending **TB_ADDBITMAP**.

---

### AddButton

Adds one button to a toolbar.

```
FUNCTION AddButton (BYVAL hToolbar AS HWND, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
   BYVAL fsState AS UBYTE = 0, BYVAL fsStyle AS UBYTE = 0, BYVAL dwData AS DWORD_PTR = 0, _
   BYVAL pwszText AS WSTRING PTR = NULL) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idxBitmap* | Zero-based index of the button image. |
| *idCommand* | Command identifier associated with the button. This identifier is used in a WM_COMMAND message when the button is chosen. |
| *fsState* | Button state flags. This member can be a combination of the values listed in [Toolbar Button States](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-button-states).|
| *fsStyle* | Button style. This member can be a combination of the button style values listed in [Toolbar Control and Button Styles](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-control-and-button-styles). |
| *dwData* | Application-defined value. |
| *pwszText* | Pointer to a Unicode string that contains text for the button. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the toolbar was created using the **CreateWindowExW** function, you must send the **TB_BUTTONSTRUCTSIZE** message to the toolbar before sending **TB_ADDBUTTONSW**.

---

### AddButtons

Adds one or more buttons to a toolbar.

```
FUNCTION AddButtons (BYVAL hToolbar AS HWND, BYVAL nButtons AS DWORD, BYVAL lpButtons AS TBBUTTON PTR) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *nButtons* | Number of buttons to add. |
| *lpButtons* | Pointer to an array of **TBBUTTON** structures that contain information about the buttons to add. There must be the same number of elements in the array as buttons specified by *nButtons*. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

If the toolbar was created using the **CreateWindowExW** function, you must send the **TB_BUTTONSTRUCTSIZE** message to the toolbar before sending **TB_ADDBUTTONSW**.

See [TB_SETIMAGELIST](https://learn.microsoft.com/en-us/windows/win32/controls/tb-setimagelist) for a discussion of how to assign bitmaps to toolbar buttons from one or more image lists.

---

### AddSeparator

Adds a separator to a toolbar.

```
FUNCTION AddSeparator (BYVAL hToolbar AS HWND, BYVAL nWidth AS LONG = 0) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *nWidth* | Width of the separator, in pixels

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### AddString

Adds a new string to the toolbar's string pool.

```
FUNCTION AddString (BYVAL hToolbar AS HWND, BYVAL hInst AS HINSTANCE, BYVAL idString AS INT_PTR) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *hInst* | Handle to the module instance with an executable file that contains the string resource. If *idString* instead points to a character array with one or more strings, set this parameter to NULL. |
| *idString* | Resource identifier for the string resource, or a pointer to an array of characters. See Remarks. |

#### Return value

Returns the index of the first new string if successful, or -1 otherwise.

#### Remarks

If *hInst* is NULL, *idString* points to a character array with one or more null-terminated strings. The last string in the array must be terminated with two null characters.

If *hInst* is the HINSTANCE of the application or of another module containing a string resource, *idString* is the resource identifier of the string. Each item in the string must begin with an arbitrary separator character, and the string must end with two such characters. For example, the text for three buttons might appear in the string table as "/New/Open/Save//". The message returns the index of "New" in the toolbar's string pool, and the other items are in consecutive positions.

---

### AutoSize

Causes a toolbar to be resized.

```
SUB AutoSize (BYVAL hToolbar AS HWND)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Remarks

An application sends the **TB_AUTOSIZE** message after causing the size of a toolbar to change either by setting the button or bitmap size or by adding strings for the first time.

---

### ButtonCount

Retrieves a count of the buttons currently in the toolbar.

```
FUNCTION ButtonCount (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the count of the buttons.

---

### ButtonStructSize

Specifies the size of the **TBBUTTON** structure.

```
SUB ButtonStructSize (BYVAL hToolbar AS HWND, BYVAL cb AS LONG)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *cb* | Size, in bytes, of the **TBBUTTON** structure. |

#### Remarks

The system uses the size to determine which version of the common control dynamic-link library (DLL) is being used.

If an application uses the **CreateWindowExW** function to create the toolbar, the application must send this message to the toolbar before sending the **TB_ADDBITMAP** or **TB_ADDBUTTONS** message.

---

### ChangeBitmap

Changes the bitmap for a button in a toolbar.

```
FUNCTION ChangeBitmap (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL iBitmap AS WORD) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button that is to receive a new bitmap. |
| *iBitmap* | Zero-based index of an image in the toolbar's image list. The system displays the specified image in the button. Set this parameter to I_IMAGECALLBACK, and the toolbar will send the TBN_GETDISPINFO notification to retrieve the image index when it is needed. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### CheckButton

Checks or unchecks a given button in a toolbar.

```
FUNCTION CheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fCheck AS SHORT) AS BOOLEAN
FUNCTION CheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
FUNCTION UncheckButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button to check. |
| *fCheck* | If TRUE, the check is added. If FALSE, the check is removed. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When a button is checked, it is displayed in the pressed state.

---

### CommandToIndex

Retrieves the zero-based index for the button associated with the specified command identifier.

```
FUNCTION CommandToIndex (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier associated with the button. |

#### Return value

Returns the zero-based index for the button or -1 if the specified command identifier is invalid.

---

### Customize

Displays the **Customize Toolbar** dialog box.

```
SUB Customize (BYVAL hToolbar AS HWND)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Note

The toolbar must handle the **TBN_QUERYINSERT** and **TBN_QUERYDELETE** notifications for the **Customize Toolbar** dialog box to appear. If the toolbar does not handle those notifications, **TB_CUSTOMIZE** has no effect.

---

### DeleteButton

Deletes a button from the toolbar.

```
FUNCTION DeleteButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *nButton* | Zero-based index of the button to delete. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### DisableButton

Disables the specified button in a toolbar.

```
FUNCTION DisableButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button to disable. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### EnableButton

Enables the specified button in a toolbar.

```
FUNCTION EnableButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button to enable. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

When a button has been enabled, it can be pressed and checked.

---

### GetAnchorHighlight

Retrieves the anchor highlight setting for a toolbar.

```
FUNCTION GetAnchorHighlight (BYVAL hToolbar AS HWND) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a Boolean value that indicates if anchor highlighting is set. If this value is nonzero, anchor highlighting is enabled. If this value is zero, it is disabled.

---

### GetBitmap

Retrieves the index of the bitmap associated with a button in a toolbar.

```
FUNCTION GetBitmap (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button whose bitmap index is to be retrieved. |

#### Return value

Returns the index of the bitmap if successful, or zero otherwise.

---

### GetBitmapFlags

Retrieves the flags that describe the type of bitmap to be used.

```
FUNCTION GetBitmapFlags (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a **DWORD** value that describes the type of bitmap that should be used. If this return value has the **TBBF_LARGE** flag set, applications should use large bitmaps (24 x 24); otherwise, applications should use small bitmaps (16 x 16). All other bits are reserved.

#### Remarks

The value returned by **TB_GETBITMAPFLAGS** is only advisory. The toolbar control recommends large or small bitmaps based upon whether the user has chosen large or small fonts.

---

### GetButton

Retrieves information about the specified button in a toolbar.

```
FUNCTION GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYVAL ptbb AS TBBUTTON PTR) AS BOOLEAN
FUNCTION GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYREF tbb AS TBBUTTON) AS BOOLEAN
FUNCTION GetButton (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS TBBUTTON
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *nButton* | Zero-based index of the button for which to retrieve information. |
| *ptbb* | Pointer to the **TBBUTTON** structure that receives the button information. |
| *tbb* | A **TBBUTTON** structure that receives the button information. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### GetButtonHeight

Retrieves the current height of toolbar buttons, in pixels.

```
FUNCTION GetButtonHeight (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

---

### GetButtonInfo

Retrieves extended information for a button in a toolbar.

```
FUNCTION GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL ptbbi AS TBBUTTONINFOW PTR) AS LONG
FUNCTION GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF tbbi AS TBBUTTONINFOW) AS LONG
FUNCTION GetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG) AS TBBUTTONINFOW
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iID* | Command identifier of the button. |
| *ptbbi* | Pointer to a **TBBUTTONINFOW** structure that receives the button information. The **cbSize** and **dwMask** members of this structure must be filled in prior to sending this message. |
| *tbbi* | A **TBBUTTONINFOW** structure that receives the button information. The **cbSize** and **dwMask** members of this structure must be filled in prior to sending this message. |

#### Return value

Returns the zero-based index of the button, or -1 if an error occurs.

#### Remarks

When you use **TB_ADDBUTTONSW** or **TB_INSERTBUTTONW** to place buttons on the toolbar, the button text is commonly specified by its string pool index. **TB_GETBUTTONINFOW** will not retrieve this string. To use **TB_GETBUTTONINFOW** to retrieve button text, you must first set the text string with **TB_SETBUTTONINFOW**. Once you have set the button text with **TB_SETBUTTONINFOW**, you can no longer use the string pool index.

---

### GetButtonSize

Retrieves the current width and height of toolbar buttons, in pixels.

```
FUNCTION GetButtonSize (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a **DWORD** value that contains the width and height values in the low word and high word, respectively.

---

### GetButtonWidth

Retrieves the current width of toolbar buttons, in pixels.

```
FUNCTION GetButtonWidth (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

---

### GetButtonText

Retrieves the display text of a button on a toolbar.

```
FUNCTION GetButtonText (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL pBuffer AS WSTRING PTR) AS LONG
FUNCTION GetButtonText (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS DWSTRING
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button whose text is to be retrieved. |
| *pBuffer* | Pointer to a buffer that receives the button text. |

#### Return value

Returns the length, in characters, of the string pointed to by *idButton*. The length does not include the terminating null character. If unsuccessful, the return value is -1.

#### Remarks

Security Warning: Using the first overloades function incorrectly might compromise the security of your program. This function does not provide a way for you to know the size of the buffer. If you use this function, first call the function passing NULL in the *pBuffer*, this returns the number of characters, excluding NULL that are required. Then call the function a second time to retrieve the string.

The returned string corresponds to the text that is currently displayed by the button.

---

### GetButtonTextLength

Retrieves the length of the display text of a button on a toolbar.

```
FUNCTION GetButtonTextLength (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button whose text length is to be retrieved. |

---

### GetColorScheme

Retrieves the color scheme information from the toolbar control.

```
FUNCTION GetColorScheme (BYVAL hToolbar AS HWND, BYVAL pcs AS COLORSCHEME PTR) AS BOOLEAN
FUNCTION GetColorScheme (BYVAL hToolbar AS HWND, BYREF cs AS COLORSCHEME) AS BOOLEAN
FUNCTION GetColorScheme (BYVAL hToolbar AS HWND) AS COLORSCHEME
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *pcs* | Pointer to a **COLORSCHEME** structure that will receive the color scheme information. |
| *pcs* | A **COLORSCHEME** structure that will receive the color scheme information. |

#### Return value

Returns nonzero if successful, or zero otherwise.

---

### GetDisabledImageList

Retrieves the image list that a toolbar control uses to display inactive buttons.

```
FUNCTION GetDisabledImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the handle to the inactive image list, or NULL if no inactive image list is set.

---

### GetExtendedStyle

Retrieves the extended styles for a toolbar control.

```
FUNCTION GetExtendedStyle (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a **DWORD** that represents the styles currently in use for the toolbar control. This value can be a combination of extended styles.

---

### GetPadding

Retrieves the padding for a toolbar control.

```
FUNCTION GetPadding (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a **DWORD** value that contains the horizontal padding in the low word and the vertical padding in the high word, in pixels.

---

### GetHorizontalPadding

Retrieves the horizontal padding for a toolbar control.

```
FUNCTION GetHorizontalPadding (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

---

### GetVerticalPadding

Retrieves the vertical padding for a toolbar control.

```
FUNCTION GetVerticalPadding (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

---

### GetHotImageList

Retrieves the image list that a toolbar control uses to display hot buttons.

```
FUNCTION GetHotImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the handle to the image list that the control uses to display hot buttons, or NULL if no hot image list is set.

#### Remarks

A button is hot when the cursor is over it. Toolbar controls must have the **TBSTYLE_FLAT** or **TBSTYLE_LIST** style to have hot items.

---

### GetHotItem

Retrieves the index of the hot item in a toolbar.

```
FUNCTION GetHotItem (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the index of the hot item, or -1 if no hot item is set. Toolbar controls that do not have the **TBSTYLE_FLAT** style do not have hot items.

---

### GetImageList

Retrieves the image list that a toolbar control uses to display buttons in their default state. A toolbar control uses this image list to display buttons when they are not hot or disabled.

```
FUNCTION GetImageList (BYVAL hToolbar AS HWND) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the handle to the image list, or NULL if no image list is set.

---

### GetImageListCount

Gets the number of image lists associated with the toolbar.

```
FUNCTION GetImageListCount (BYVAL hToolbar AS HWND) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the number of image lists.

---

### GetInsertMark

Retrieves the current insertion mark for the toolbar.

```
FUNCTION GetInsertMark (BYVAL hToolbar AS HWND) AS TBINSERTMARK
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a **TBINSERTMARK** structure that receives the insertion mark.

---

### GetInsertMarkColor

Retrieves the current insertion mark for the toolbar.

```
FUNCTION GetInsertMarkColor (BYVAL hToolbar AS HWND) AS COLORREF
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns a **COLORREF** value that contains the current insertion mark color.

---

### GetItemRect

Retrieves the bounding rectangle of a button in a toolbar.

```
FUNCTION GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hToolbar AS HWND, BYVAL nButton AS LONG) AS RECT
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *nButton* | Zero-based index of the button for which to retrieve information. |
| *prc* | Pointer to a **RECT** structure that receives the client coordinates of the bounding rectangle. |
| *rc* | A **RECT** structure that receives the client coordinates of the bounding rectangle. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

This message does not retrieve the bounding rectangle for buttons whose state is set to the **TBSTATE_HIDDEN** value.

---

### GetMaxSize

Retrieves the total size of all of the visible buttons and separators in the toolbar.

```
FUNCTION GetMaxSize (BYVAL hToolbar AS HWND, BYVAL psize AS SIZE PTR) AS BOOLEAN
FUNCTION GetMaxSize (BYVAL hToolbar AS HWND, BYREF sz AS SIZE) AS BOOLEAN
FUNCTION GetMaxSize (BYVAL hToolbar AS HWND) AS SIZE
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *psize* | Pointer to a **SIZE** structure that receives the size of the items. |
| *sz* | A **SIZE** structure that receives the size of the items. |

#### Return value

Returns nonzero if successful, or zero otherwise.

---

### GetMetrics

Retrieves the metrics of a toolbar control.

```
SUB GetMetrics (BYVAL hToolbar AS HWND, BYVAL ptbMetrics AS TBMETRICS PTR)
SUB GetMetrics (BYVAL hToolbar AS HWND, BYREF tbMet AS TBMETRICS)
FUNCTION GetMetrics (BYVAL hToolbar AS HWND) AS TBMETRICS
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *ptbMetrics* | Pointer to a **TBMETRICS** structure that receives the toolbar metrics. |
| *tbMetrics* | A **TBMETRICS** structure that receives the toolbar metrics. |

#### Note

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### GetObject

Retrieves a pointer to the **IDropTarget** interface for a toolbar control.

```
FUNCTION GetObject (BYVAL hToolbar AS HWND) AS IDropTarget PTR
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Remarks

The toolbar's **IDropTarget** is used by the toolbar when objects are dragged over or dropped onto it.

---

### GetRect

Retrieves the bounding rectangle for a specified toolbar button.

```
FUNCTION GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL prc AS RECT PTR) AS BOOLEAN
FUNCTION GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF rc AS RECT) AS BOOLEAN
FUNCTION GetRect (BYVAL hToolbar AS HWND, BYVAL iID AS LONG) AS RECT
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iID* | Command identifier of the button. |
| *prc* | Pointer to a **RECT** structure that will receive the bounding rectangle information. |
| *rc* | A **RECT** structure that will receive the bounding rectangle information. |

#### Remarks

Returns nonzero if successful, or zero otherwise.

#### Remarks

This message does not retrieve the bounding rectangle for buttons whose state is set to the TBSTATE_HIDDEN value.

---

### GetRows

Retrieves the number of rows of buttons in a toolbar with the **TBSTYLE_WRAPABLE** style.

```
FUNCTION GetRows (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Remarks

Returns the number of rows.

---

### GetState

Retrieves information about the state of the specified button in a toolbar, such as whether it is enabled, pressed, or checked.

```
FUNCTION GetState (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button for which to retrieve information. |

#### Remarks

Returns the button state information if successful, or -1 otherwise. The button state information can be a combination of the values listed in [Toolbar Button States](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-button-states).

---

### GetString

Retrieves a string from a toolbar's string pool.

```
FUNCTION GetString (BYVAL hToolbar AS HWND, BYVAL iString AS SHORT, _
   BYVAL pBuffer AS WSTRING PTR, BYVAL cchMax AS SHORT) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iString* | The index of the string. |
| *pBuffer* | Pointer to a buffer used to return the string. |
| *cchMax* | The he length of the lParam buffer. |

#### Return value

Returns the string length if successful, or -1 otherwise.

#### Remarks

This message returns the specified string from the toolbar's string pool. It does not necessarily correspond to the text string currently being displayed by a button. To retrieve a button's current text string, call the **GetButtonText** method.

---

### GetStyle

Retrieves the styles currently in use for a toolbar control.

```
FUNCTION GetStyle (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Remarks

Returns a **DWORD** value that is a combination of toolbar control styles.

---

### GetTextRows

Retrieves the maximum number of text rows that can be displayed on a toolbar button.

```
FUNCTION GetTextRows (BYVAL hToolbar AS HWND) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Remarks

Returns an INT value representing the maximum number of text rows that the control will display for a button.

---

### GetTooltips

Retrieves the handle to the tooltip control, if any, associated with the toolbar.

```
FUNCTION GetTooltips (BYVAL hToolbar AS HWND) AS HWND
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

Returns the handle to the tooltip control, or NULL if the toolbar has no associated tooltip.

---

### HideButton

Hides or shows the specified button in a toolbar.

```
FUNCTION HideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fShow AS SHORT) AS BOOLEAN
FUNCTION HideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
FUNCTION UnhideButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button to hide or show. |
| *fShow* | TRUE to hidden the button or FALSE to show it. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### HighlightButton

Sets the highlight state of a given button in a toolbar control.

```
FUNCTION HighlightButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
FUNCTION UnhighlightButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier for a toolbar button. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### HitTest

Determines where a point lies in a toolbar control.

```
FUNCTION HitTest (BYVAL hToolbar AS HWND, BYVAL pptHitTest AS POINT PTR) AS LONG
FUNCTION HitTest (BYVAL hToolbar AS HWND, BYREF ptHitTest AS POINT) AS LONG
FUNCTION HitTest (BYVAL hToolbar AS HWND) AS POINT
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *pptHitTest* | Pointer to a **POINT** structure that contains the x-coordinate of the hit test in the x member and the y-coordinate of the hit test in the y member. The coordinates are relative to the toolbar's client area. |
| *ptHitTest* | A **POINT** structure that contains the x-coordinate of the hit test in the x member and the y-coordinate of the hit test in the y member. The coordinates are relative to the toolbar's client area. |

#### Return value

Returns an integer value. If the return value is zero or a positive value, it is the zero-based index of the nonseparator item in which the point lies. If the return value is negative, the point does not lie within a button. The absolute value of the return value is the index of a separator item or the nearest nonseparator item.

---

### Indeterminate

Sets or clears the indeterminate state of the specified button in a toolbar.

```
FUNCTION Indeterminate (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fIndeterminate AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button whose indeterminate state is to be set or cleared. |
| *fIndeterminate* | TRUE to set the indeterminate state or FALSE to clear it. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### InsertButton

Inserts a button in a toolbar.

```
FUNCTION InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL pButton AS TBBUTTON PTR) AS BOOLEAN
FUNCTION InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYREF Button AS TBBUTTON) AS BOOLEAN
FUNCTION InsertButton (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL idxBitmap AS LONG, _
   BYVAL idCommand AS LONG, BYVAL fsState AS UBYTE = 0, BYVAL fsStyle AS UBYTE = 0, BYVAL dwData AS DWORD_PTR = 0, _
   BYVAL pwszText AS WSTRING PTR = NULL) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idxButton* | Zero-based index of a button. The message inserts the new button to the left of this button. |
| *pButton* | Pointer to a **TBBUTTON** structure containing information about the button to insert. |
| *Button* | A **TBBUTTON** structure containing information about the button to insert. |
| *idxBitmap* | Zero-based index of the button image. Set this member to I_IMAGECALLBACK, and the toolbar will send the **TBN_GETDISPINFO** notification code to retrieve the image index when it is needed. |
| *idCommand* | Command identifier associated with the button. This identifier is used in a WM_COMMAND message when the button is chosen. |
| *fsState* | Button state flags. This member can be a combination of the values listed in [Toolbar Button States](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-button-states). |
| *fsStyle* | Button style. This member can be a combination of the button style values listed in Toolbar Control and [Button Styles](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-control-and-button-styles). |
| *dwData* | Application-defined value. |
| *pwszText* | Pointer to a string buffer that contains text for the button. |

---

### InsertMarkHitTest

Retrieves the insertion mark information for a point in a toolbar.

```
FUNCTION InsertMarkHitTest (BYVAL hToolbar AS HWND, BYVAL ppt AS POINT PTR, BYVAL ptbim AS TBINSERTMARK PTR) AS BOOLEAN
FUNCTION InsertMarkHitTest (BYVAL hToolbar AS HWND, BYREF pt AS POINT, BYVAL tbim AS TBINSERTMARK) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *ppt* | Pointer to a **POINT** structure that contains the hit test coordinates, relative to the client area of the toolbar. |
| *pt* | A **POINT** structure that contains the hit test coordinates, relative to the client area of the toolbar. |
| *ptbim* | Pointer to a **TBINSERTMARK** structure that receives the insertion mark information. |
| *tbim* | A **TBINSERTMARK** structure that receives the insertion mark information. |

#### Return value

Returns nonzero if the point is an insertion mark, or zero otherwise.

---

### InsertSeparator

Inserts a separator in a toolbar.

```
FUNCTION InsertSeparator (BYVAL hToolbar AS HWND, BYVAL idxButton AS LONG, BYVAL nWidth AS LONG = 0) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idxButton* | Zero-based index of a button. The message inserts the new separator to the left of this button. |
| *nWidth* | Width of the separator, in pixels

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### IsButtonChecked

Determines whether the specified button in a toolbar is checked.

```
FUNCTION IsButtonChecked (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |

#### Return value

Returns nonzero if the button is checked, or zero otherwise.

---

### IsButtonEnabled

Determines whether the specified button in a toolbar is enabled.

```
FUNCTION IsButtonEnabled (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |

#### Return value

Returns nonzero if the button is enabled, or zero otherwise.

---

### IsButtonHidden

Determines whether the specified button in a toolbar is hidden.

```
FUNCTION IsButtonHidden (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |

#### Return value

Returns nonzero if the button is hidden, or zero otherwise.

---

### IsButtonHighlighted

Checks the highlight state of a toolbar button.

```
FUNCTION IsButtonHighlighted (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |

#### Return value

Returns nonzero if the button is highlighted, or zero otherwise.

---

### IsButtonIndeterminate

Determines whether the specified button in a toolbar is indeterminate.

```
FUNCTION IsButtonIndeterminate (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |

#### Return value

Returns nonzero if the button is indeterminate, or zero otherwise.

---

### IsButtonPressed

Determines whether the specified button in a toolbar is pressed.

```
FUNCTION IsButtonPressed (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |

#### Return value

Returns nonzero if the button is pressed, or zero otherwise.

---

### LoadImages

Loads system-defined button images into a toolbar control's image list.

```
FUNCTION LoadImages (BYVAL hToolbar AS HWND, BYVAL iBitmapID AS DWORD, BYVAL hinst AS HINSTANCE) AS LONG
FUNCTION LoadImages (BYVAL hToolbar AS HWND, BYVAL iBitmapID AS DWORD) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iBitmapID* | Identifier of a system-defined button image list. This parameter can be set to one of the following values (see below). |
| *hInst* | Instance handle. This parameter must be set to HINST_COMMCTRL. |

| Value | Meaning |
| ----- | ------- |
| **IDB_HIST_LARGE_COLOR** | Windows Explorer bitmaps in large size. |
| **IDB_HIST_SMALL_COLOR** | Windows Explorer bitmaps in small size. |
| **IDB_STD_LARGE_COLOR** | Standard bitmaps in large size. |
| **IDB_STD_SMALL_COLOR** | Standard bitmaps in small size. |
| **IDB_VIEW_LARGE_COLOR** | View bitmaps in large size. |
| **IDB_VIEW_SMALL_COLOR** | View bitmaps in small size. |
| **IDB_HIST_NORMAL** | Windows Explorer travel buttons and favorites bitmaps in normal state. |
| **IDB_HIST_HOT** | Windows Explorer travel buttons and favorites bitmaps in hot state. |
| **IDB_HIST_DISABLED** | Windows Explorer travel buttons and favorites bitmaps in disabled state. |
| **IDB_HIST_PRESSED** | Windows Explorer travel buttons and favorites bitmaps in pressed state. |

#### Return value

The count of images in the image list. Returns zero if the toolbar has no image list or if the existing image list is empty.

#### Remarks

You must use the proper image index values when you prepare **TBBUTTON** structures prior to sending the **TB_ADDBUTTONSW** message. For a list of image index values for these preset bitmaps, see [Toolbar Standard Button Image Index Values](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-standard-button-image-index-values).

---

### MakeOpaque

Makes the toolbar opaque by removing the TBSTYLE_TRANSPARENT style.

```
SUB MakeOpaque (BYVAL hToolbar AS HWND)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

---

### MapAccelerator

Determines the ID of the button that corresponds to the specified accelerator character.

```
FUNCTION MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD, BYVAL pIDBtn AS DWORD PTR) AS BOOLEAN
FUNCTION MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD, BYREF IDBtn AS DWORD) AS BOOLEAN
FUNCTION MapAccelerator (BYVAL hToolbar AS HWND, BYVAL chAccel AS DWORD) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *chAccel* | The accelerator character. |
| *IDBtn* | Pointer to a DWORD. On return, if successful, this parameter will hold the id of the button that has *chAccel* as its accelerator character. |
| *IDBtn* | A DWORD. On return, if successful, this parameter will hold the id of the button that has *chAccel* as its accelerator character. |

#### Return value

Returns a nonzero value if one of the buttons has *chAccel* as its accelerator character, or zero otherwise.

---

### MarkButton

Sets the highlight state of a given button in a toolbar control.

```
FUNCTION MarkButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fHighlight AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier for a toolbar button. |
| *fHighlight* | TRUE to highlight the button; FALSE to set the button to its default state. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### MoveButton

Moves a button from one index to another.

```
FUNCTION MoveButton (BYVAL hToolbar AS HWND, BYVAL uOldPos AS DWORD, BYVAL uNewPos AS DWORD) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *uOldPos* | Zero-based index of the button to be moved. |
| *uNewPos* | Zero-based index where the button will be moved. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### PressButton

Presses or releases the specified button in a toolbar.

```
FUNCTION PressButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fPress AS SHORT) AS BOOLEAN
FUNCTION PressButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
FUNCTION ReleaseButton (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button to press or release. |
| *fPress* | If TRUE, the button is pressed. If FALSE, the button is released. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### RemoveDarkMode

Removes the toolbar dark mode.

```
FUNCTION RemoveDarkMode (BYVAL hToolbar AS HWND) AS HRESULT
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

---

### ReplaceBitmap

Replaces an existing bitmap with a new bitmap.

```
FUNCTION ReplaceBitmap (BYVAL hToolbar AS HWND, BYVAL ptbrb AS TBREPLACEBITMAP PTR) AS BOOLEAN
FUNCTION ReplaceBitmap (BYVAL hToolbar AS HWND, BYREF tbrb AS TBREPLACEBITMAP) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *ptbrb* | Pointer to a **TBREPLACEBITMAP** structure that contains the information of the bitmap to be replaced and the new bitmap. |
| *tbrb* | A **TBREPLACEBITMAP** structure that contains the information of the bitmap to be replaced and the new bitmap. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SaveRestore

Send this message to initiate saving or restoring a toolbar state.

```
SUB SaveRestore (BYVAL hToolbar AS HWND, BYVAL fSave AS LONG, BYVAL ptbsp AS TBSAVEPARAMSW PTR)
SUB SaveRestore (BYVAL hToolbar AS HWND, BYVAL fSave AS LONG, BYREF tbsp AS TBSAVEPARAMSW)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *fSave* | Save or restore flag. If this parameter is TRUE, the information is saved. If it is FALSE, the information is restored. |
| *ptbsp* | Pointer to a **TBSAVEPARAMS** structure that specifies the registry key, subkey, and value name for the toolbar state information. |
| *tbsp* | A **TBSAVEPARAMS** structure that specifies the registry key, subkey, and value name for the toolbar state information. |

---

### SetAnchorHighlight

Sets the anchor highlight setting for a toolbar.

```
FUNCTION SetAnchorHighlight (BYVAL hToolbar AS HWND, BYVAL fAnchor AS BOOLEAN) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *fAnchor* | BOOL value that specifies if anchor highlighting is enabled or disabled. If this value is nonzero, anchor highlighting will be enabled. If this value is zero, anchor highlighting will be disabled. |

#### Return value

Returns the previous anchor highlight setting. If this value is nonzero, anchor highlighting was enabled. If this value is zero, anchor highlighting was disabled.

#### Remarks

Anchor highlighting in a toolbar means that the last highlighted item will remain highlighted until another item is highlighted. This occurs even if the cursor leaves the toolbar control.

---

### SetBitmapSize

Sets the size of the bitmapped images to be added to a toolbar.

```
FUNCTION SetBitmapSize (BYVAL hToolbar AS HWND, BYVAL dxBitmap AS SHORT, BYVAL dyBitmap AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *dxBitmap* | The width, in pixels, of the bitmapped images. |
| *dyBitmap* | The height, in pixels, of the bitmapped images. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

The size can be set only before adding any bitmaps to the toolbar. If an application does not explicitly set the bitmap size, the size defaults to 16 by 15 pixels.

---

### SetButtonInfo

Sets the information for an existing button in a toolbar.

```
FUNCTION SetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYVAL ptbbi AS TBBUTTONINFOW PTR) AS LONG
FUNCTION SetButtonInfo (BYVAL hToolbar AS HWND, BYVAL iID AS LONG, BYREF tbbi AS TBBUTTONINFOW) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iID* | Button identifier. |
| *ptbbi* | Pointer to a **TBBUTTONINFO** structure that contains the new button information. The **cbSize** and **dwMask** members of this structure must be filled in prior to sending this message. |
| *tbbi* | A **TBBUTTONINFO** structure that contains the new button information. The **cbSize** and **dwMask** members of this structure must be filled in prior to sending this message. |

#### Return value

Returns nonzero if successful, or zero otherwise.

#### Remarks

Text is commonly assigned to buttons when they are added to a toolbar by specifying the index of a string in the toolbar's string pool. If you use a **TB_SETBUTTONINFO** to assign new text to a button, it will permanently override the text from the string pool. You can change the text by calling **TB_SETBUTTONINFO** again, but you cannot reassign the string from the string pool

---

### SetButtonSize

Sets the size of buttons on a toolbar.

```
FUNCTION SetButtonSize (BYVAL hToolbar AS HWND, BYVAL dxButton AS SHORT, BYVAL dyButton AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *dxButton* | The width, in pixels, of the buttons. |
| *dyButton* | The height, in pixels, of the buttons. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetButtonWidth

Sets the minimum and maximum button widths in the toolbar control.

```
FUNCTION SetButtonWidth (BYVAL hToolbar AS HWND, BYVAL cxMin AS SHORT, BYVAL cxMax AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *cxMin* | The minimum button width, in pixels. Toolbar buttons will never be narrower than this value. |
| *cxMax* | The maximum button width, in pixels. If button text is too wide, the control displays it with ellipsis points. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetCmdId

Sets the command identifier of a toolbar button.

```
FUNCTION SetCmdId (BYVAL hToolbar AS HWND, BYVAL index AS SHORT, BYVAL cmdid AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *index* | Zero-based index of the button whose command identifier is to be set. |
| *cmdid* | Command identifier. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetColorScheme

Sets the color scheme information for the toolbar control.

```
SUB SetColorScheme (BYVAL hToolbar AS HWND, BYVAL pcs AS COLORSCHEME PTR)
SUB SetColorScheme (BYVAL hToolbar AS HWND, BYREF cs AS COLORSCHEME)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *pcs* | Pointer to a **COLORSCHEME** structure that contains the color scheme information. |
| *cs* | A **COLORSCHEME** structure that contains the color scheme information. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetDarkMode

Sets the toolbar dark mode.

```
FUNCTION SetDarkMode (BYVAL hToolbar AS HWND) AS HRESULT
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

---

### SetDisabledImageList

Sets the image list that the toolbar control will use to display disabled buttons.

```
FUNCTION SetDisabledImageList (BYVAL hToolbar AS HWND, BYVAL himlNewDisabled AS HIMAGELIST) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *himlNewDisabled* | Handle to the image list that will be set. |

#### Return value

Returns the handle to the image list previously used to display disabled buttons, or NULL if no image list was previously set.

---

### SetDrawTextFlags

Sets the text drawing flags for the toolbar.

```
FUNCTION SetDrawTextFlags (BYVAL hToolbar AS HWND, BYVAL dwMask AS DWORD, BYVAL dwDTFlags AS DWORD) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *dwMask* | One or more of the DT_ flags, specified in **DrawText**, that indicate which bits in *dwDTFlags* will be used when drawing the text. |
| *dwDTFlags* | One or more of the DT_ flags, specified in **DrawText**, that indicate how the button text will be drawn. This value will be passed to the **DrawText** function when the button text is drawn. |

#### Return value

Returns the previous text drawing flags.

#### Remarks

The *dwMask* parameter allows you to specify which flags will be used when drawing the text, even if these flags are turned off. For example, if you do not want the DT_CENTER flag used when drawing text, you would add the DT_CENTER flag to *dwMask* and not specify the DT_CENTER flag in *dwDTFlags*. This prevents the control from passing the DT_CENTER flag to the **DrawText** function.

---

### SetExtendedStyle

Sets the extended styles for a toolbar control.

```
FUNCTION SetExtendedStyle (BYVAL hToolbar AS HWND, BYVAL dwExStyle AS DWORD) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *dwExStyle* | Value specifying the new extended styles. This parameter can be a combination of [extended styles](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-extended-styles). |

#### Return value

Returns a DWORD that represents the previous extended styles. This value can be a combination of extended styles.

---

### SetHotImageList

Sets the image list that the toolbar control will use to display hot buttons.

```
FUNCTION SetHotImageList (BYVAL hToolbar AS HWND, BYVAL himlNewHot AS HIMAGELIST) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *himlNewHot* | Handle to the image list that will be set. |

#### Return value

Returns the handle to the image list previously used to display hot buttons, or NULL if no image list was previously set.

#### Remarks

A button is hot when the cursor is over it. Toolbar controls must have the **TBSTYLE_FLAT** or **TBSTYLE_LIST** style to have hot items.

---

### SetHotItem

Sets the hot item in a toolbar.

```
FUNCTION SetHotItem (BYVAL hToolbar AS HWND, BYVAL iHot AS LONG) AS LONG
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iHot* | Index of the item that will be made hot. If this value is -1, none of the items will be hot. |

#### Return value

Returns the index of the previous hot item, or -1 if there was no hot item.

#### Remarks

The behavior of this message is not defined for toolbars that do not have the TBSTYLE_FLAT style.

---

### SetImageList

Sets the image list that the toolbar uses to display buttons that are in their default state.

```
FUNCTION SetImageList (BYVAL hToolbar AS HWND, BYVAL himlNew AS HIMAGELIST) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *himlNew* | Handle to the image list to set. If this parameter is NULL, no images are displayed in the buttons. |

#### Return value

Returns the handle to the image list previously used to display buttons in their default state, or NULL if no image list was previously set.

#### Remarks

Your application is responsible for freeing the image list after the toolbar is destroyed.

The **TB_SETIMAGELIST** message cannot be combined with **TB_ADDBITMAP**. It also cannot be used with toolbars created with **CreateToolbarEx**, which calls **TB_ADDBITMAP** internally. When you create a toolbar with **CreateToolbarEx** or use **TB_ADDBITMAP** to add images, the toolbar manages the image list internally. Attempting to modify it with **TB_SETIMAGELIST** has unpredictable consequences.

---

### SetIndent

Sets the indentation for the first button in a toolbar control.

```
FUNCTION SetIndent (BYVAL hToolbar AS HWND, BYVAL iIndent AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iIndent* | Value specifying the indentation, in pixels. |

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

---

### SetInsertMark

Sets the current insertion mark for the toolbar.

```
SUB SetInsertMark (BYVAL hToolbar AS HWND, BYVAL ptbim AS TBINSERTMARK PTR)
SUB SetInsertMark (BYVAL hToolbar AS HWND, BYREF tbim AS TBINSERTMARK)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *ptbim* | Pointer to a **TBINSERTMARK** structure that contains the insertion mark. |
| *tbim* | A **TBINSERTMARK** structure that contains the insertion mark. |

---

### SetInsertMarkColor

Sets the color used to draw the insertion mark for the toolbar.

```
FUNCTION SetInsertMarkColor (BYVAL hToolbar AS HWND, BYVAL clrInsertMark AS COLORREF) AS COLORREF
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *clrInsertMark* | **COLORREF** value that contains the new insertion mark color. |

#### Return value

Returns a **COLORREF** value that contains the previous insertion mark color.

---

### SetListGap

Sets the distance between the toolbar buttons on a specific toolbar.

```
SUB SetListGap (BYVAL hToolbar AS HWND, BYVAL gap AS DWORD)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *gap* | The gap, in pixels, between buttons on the toolbar. |

#### Remarks

The gap between buttons only applies to the toolbar control window that receives this message. Receipt of this message triggers a repaint of the toolbar, if the toolbar is currently visible.

---

### SetMaxTextRows

Sets the maximum number of text rows displayed on a toolbar button.

```
FUNCTION SetMaxTextRows (BYVAL hToolbar AS HWND, BYVAL iMaxRows AS LONG) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iMaxRows* | Maximum number of rows of text that can be displayed. |

#### Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

#### Remarks

To cause text to wrap, you must set the maximum button width by sending a **TB_SETBUTTONWIDTH** message. The text wraps at a word break; line breaks ("\n") in the text are ignored. Text in **TBSTYLE_LIST** toolbars is always shown on a single line.

---

### SetMetrics

Sets the metrics of a toolbar control.

```
SUB SetMetrics (BYVAL hToolbar AS HWND, BYVAL ptbMetrics AS TBMETRICS PTR)
SUB SetMetrics (BYVAL hToolbar AS HWND, BYREF tbMet AS TBMETRICS)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *ptbMetrics* | Pointer to a **TBMETRICS** structure that contains the toolbar metrics to set. |
| *tbMet* | A **TBMETRICS** structure that contains the toolbar metrics to set. |

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### SetPadding

Sets the padding for a toolbar control.

```
FUNCTION SetPadding (BYVAL hToolbar AS HWND, BYVAL cx AS SHORT, BYVAL cy AS SHORT) AS DWORD
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *cx* | The horizontal padding, in pixels. |
| *cy* | The vertical padding, in pixels. |

#### Return value

Returns a **DWORD** value that contains the previous horizontal padding in the **LOWORD** and the previous vertical padding in the **HIWORD**, in pixels.

#### Remarks

The padding values are used to create a blank area between the edge of the button and the button's image and/or text. Where and how much padding is actually applied depends on the type of the button and whether it has an image. The horizontal padding is applied to both the right and left of the button, and the vertical padding is applied to both the top and bottom of the button. Padding is only applied to buttons that have the **TBSTYLE_AUTOSIZE** style.

---

### SetParent

Sets the window to which the toolbar control sends notification messages.

```
FUNCTION SetParent (BYVAL hToolbar AS HWND, BYVAL hwndParent AS HWND) AS HWND
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *hwndParent* | Handle to the window to receive notification messages. |

#### Return value

The return value is a handle to the previous notification window, or NULL if there is no previous notification window.

#### Remarks

The **TB_SETPARENT** message does not change the parent window that was specified when the control was created. Calling the **GetParent** function for a toolbar control will return the actual parent window, not the window specified in **TB_SETPARENT**. To change the control's parent window, call the **SetParent** function.

---

### SetPressedImageList

Sets the image list that the toolbar uses to display buttons that are in a pressed state.

```
FUNCTION SetPressedImageList (BYVAL hToolbar AS HWND, BYVAL iImageID AS DWORD, BYVAL himlNew AS HIMAGELIST) AS HIMAGELIST
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *iImageID* | The index of the image list. If you use only one image list, set this parameter to zero. |
| *himlNew* | Handle to the image list to set. If this parameter is NULL, no images are displayed in the buttons. |

#### Return value

Returns the handle to the image list previously used to display buttons in their pressed state, or NULL if no such image list was previously set.

#### Remarks

Your application is responsible for freeing the image list after the toolbar is destroyed.

The **TB_SETPRESSEDIMAGELIST** message cannot be combined with **TB_ADDBITMAP**. It also cannot be used with toolbars created with **CreateToolbarEx**, which calls **TB_ADDBITMAP** internally. When you create a toolbar with **CreateToolbarEx** or use **TB_ADDBITMAP** to add images, the toolbar manages the image list internally. Attempting to modify it with **TB_SETPRESSEDIMAGELIST** has unpredictable consequences.

---

### SetRows

Sets the number of rows of buttons in a toolbar.

```
SUB SetRows (BYVAL hToolbar AS HWND, BYVAL cRows AS WORD, BYVAL fLarger AS BOOLEAN, BYVAL prc AS RECT PTR)
SUB SetRows (BYVAL hToolbar AS HWND, BYVAL cRows AS WORD, BYVAL fLarger AS BOOLEAN, BYREF rc AS RECT)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *cRows* | The number of rows requested. The minimum number of rows is one, and the maximum number of rows is equal to the number of buttons in the toolbar |
| *fLarger* | Indicates whether to create more rows than requested when the system cannot create the number of rows specified by wParam. If TRUE, the system creates more rows. If FALSE, the system creates fewer rows. |
| *prc* | Pointer to a **RECT** structure that receives the bounding rectangle of the toolbar after the rows are set. |
| *rc* | A **RECT** structure that receives the bounding rectangle of the toolbar after the rows are set. |

#### Remarks

Because the system does not break up button groups when setting the number of rows, the resulting number of rows might differ from the number requested.

---

### SetState

Sets the state for the specified button in a toolbar.

```
FUNCTION SetState (BYVAL hToolbar AS HWND, BYVAL idButton AS LONG, BYVAL fState AS SHORT) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *idButton* | Command identifier of the button. |
| *fState* | A is a combination of values listed in [Toolbar Button States](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-button-states). |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetStyle

Sets the style for a toolbar control.

```
SUB SetStyle (BYVAL hToolbar AS HWND, BYVAL dwStyle AS DWORD)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *dwStyle* | Value specifying the styles to be set for the control. This value can be a combination of [toolbar control styles](https://learn.microsoft.com/en-us/windows/win32/controls/toolbar-control-and-button-styles). |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

---

### SetToolTips

Associates a tooltip control with a toolbar.

```
SUB SetToolTips (BYVAL hToolbar AS HWND, BYVAL hwndToolTip AS HWND)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *hwndToolTip* | Handle to the tooltip control. |

#### Remarks

Any buttons added to a toolbar before sending the **TB_SETTOOLTIPS** message will not be registered with the tooltip control.

---

### SetWindowTheme

Sets the visual style of a toolbar control.

```
SUB SetWindowTheme (BYVAL hToolbar AS HWND, BYVAL pwszTheme AS WSTRING PTR)
```

| Parameter | Description |
| ------- | -------------- |
| *hToolbar* | Handle to the toolbar control. |
| *pwszTheme* | Pointer to a Unicode string that contains the toolbar visual style to set. |

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

Sending this message is equivalent to calling **SetWindowTheme** on the toolbar and its tooltip control, if any.

---
