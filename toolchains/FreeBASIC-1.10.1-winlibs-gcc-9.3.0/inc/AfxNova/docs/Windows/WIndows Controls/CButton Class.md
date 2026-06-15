# CButton Class

Wrapper static class on top of all the Windows `Button` messages.

A button control is a small, rectangular child window that can be clicked on and off. Buttons can be used alone or in groups and can either be labeled or appear without text. A button typically changes appearance when the user clicks it.

Typical buttons are the check box, radio button, and pushbutton. A `CButton` object can become any of these, based on the button style specified at its initialization by the **AddControl** method of the `CWindow`class.

See: [About Buttons](https://learn.microsoft.com/en-us/windows/win32/controls/about-buttons)

**Include file**: CButton.inc.

| Name       | Description |
| ---------- | ----------- |
| [Check](#check) | Changes the button's state to checked. |
| [Click](#click) | Simulates the user clicking a button. |
| [DeleteBitmap](#deletebitmap) | Deletes a bitmap associated with a button. |
| [DeleteIcon](#deleteicon) | Deletes an icon associated with a button. |
| [DeleteImage](#deleteimage) | Deletes an image (icon or bitmap) associated with a button. |
| [Disable](#disable) | Disables the button. |
| [Enable](#enable) | Enables the button. |
| [GetCheck](#getcheck) | Gets the check state of a radio button or check box.  |
| [GetIdealSize](#getidealsize) | Gets the size of the button that best fits its text and image, if an image list is present. |
| [GetBitmap](#getbitmap) | Retrieves a handle to the bitmap associated with the button. |
| [GetIcon](#geticon) | Retrieves a handle to the icon associated with the button. |
| [GetImage](#getimage) | Retrieves a handle to the image (icon or bitmap) associated with the button. |
| [GetImageList](#getimagelist) | Gets the BUTTON_IMAGELIST structure that describes the image list assigned to a button control.  |
| [GetNote](#getnote) | Gets the text of the note associated with the Command Link button. |
| [GetNoteLength](#getnotelength) | Gets the length of the note text that may be displayed in the description for a command link. |
| [GetSplitImageList](#getsplitimagelist) | Gets the handle of the split button image list. |
| [GetSplitInfo](#getsplitinfo) | Gets information for a specified split button control. |
| [GetSplitGlyphSize](#getsplitglyphsize) | Gets the size of the glyph in the image list. |
| [GetSplitStyle](#getsplitstyle) | Gets the style of the split button. |
| [GetState](#getstate) | Retrieves the state of a button or check box. |
| [GetStyle](#getstyle) | Retrieves the style of the button. |
| [GetText](#gettext) | Retrieves the text in a button control. |
| [GetTextLength](#gettextlength) | Retrieves the length of the text in a button control. |
| [GetTextMargin](#gettextmargin) | Retrieves the margins used to draw text in a button control. |
| [Gray](#gray) | Sets the button state to grayed, indicating an indeterminate state. |
| [Indeterminate](#indeterminate) | Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the BS_3STATE or BS_AUTO3STATE style. |
| [RemoveDarkMode](#removedarkmode) | Remove the dark mode of the button. |
| [SetCheck](#setcheck) | Sets the check state of a radio button or check box. |
| [SetDarkMode](#setdarkmode) | Sets the dark mode of the button. |
| [SetDontClick](#setdontclick) | Sets a flag on a radio button that controls the generation of BN_CLICKED messages when the button receives focus. |
| [SetDropDownState](#setdropdownstate) | Sets the drop down state for a specified button with style of BS_SPLITBUTTON. |
| [SetElevationRequiredState](#setelevationrequiredstate) | Sets the elevation required state for a specified button or command link to display an elevated icon. |
| [SetIcon](#seticon) | Associates a new icon with the button. |
| [SetImage](#setimage) | Associates a new image (icon or bitmap) with the button. |
| [SetImageList](#setimagelist) | Assigns an image list to a button control. |
| [SetNote](#setnote) | Sets the text of the note associated with a specified Command Link button. |
| [SetSplitGlyphSize](#setsplitglyphsize) | Sets the split size (glyph area) of a split button (BCSIF_SIZE). |
| [SetSplitInfo](#setsplitinfo) | Sets information for a specified split button control. |
| [SetSplitStyle](#setsplitstyle) | Sets the split style of a split button. |
| [SetState](#setstate) | Sets the highlight state of a button. |
| [SetStyle](#setstyle) | Sets the style of a button. |
| [SetText](#settext) | Sets the text of a button. |
| [SetTextMargin](#settextmargin) | Sets the margins for drawing text in a button control. |
| [Uncheck](#uncheck) | Unchecks the button.

---

### Check

Changes the button's state to checked.

```
SUB CButton.Check (BYVAL hButton AS HWND)
```
#### Usage example
```
CButton.Check(hButton)
```
---

### Click

Simulates the user clicking a button. This message causes the button to receive the **WM_LBUTTONDOWN** and **WM_LBUTTONUP** messages, and the button's parent window to receive a **BN_CLICKED** notification code.

```
SUb Click (BYVAL hButton AS HWND)
```
#### Remarks

If the button is in a dialog box and the dialog box is not active, the **BM_CLICK** message might fail. To ensure success in this situation, call the **SetActiveWindow** function to activate the dialog box before sending the **BM_CLICK** message to the button.

#### Usage example
```
CButton.Click(hButton)
```
---

### DeleteBitmap

Deletes a bitmap associated with a button. Returns TRUE or FALSE.

```
FUNCTION DeleteBitmap (BYVAL hButton AS HWND) AS BOOLEAN
```

#### Usage example
```
CButton.DeleteBitmap(hButton)
```
---

### DeleteIcon

Deletes an icon associated with a button. Returns TRUE or FALSE.

```
FUNCTION DeleteIcon (BYVAL hButton AS HWND) AS BOOLEAN
```

#### Usage example
```
CButton.DeleteIcon(hButton)
```
---

### DeleteImage

Deletes an image (icon or bitmap) associated with a button. Returns TRUE or FALSE.

```
FUNCTION DeleteImage (BYVAL hButton AS HWND, BYVAL ImageType AS DWORD) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle of the button control. |
| *ImageType* | The type of image to delete. This parameter can be one of the following values: |

| Value | Meaning |
| ------------ | ----------- |
| **IMAGE_BITMAP** | A bitmap. |
| **IMAGE_ICON** | An icon. |

#### Usage examples
```
CButton.Deleteimage(hButton, IMAGE_BITMAP)
CButton.Deleteimage(hButton, IMAGE_ICON)
```
---

### Disable

Disables the button. Returns FALSE if the button was previously disabled; otherwise TRUE.

```
FUNCTION Disable (BYVAL hButton AS HWND) AS BOOLEAN
```

#### Usage example
```
CButton.Disable(hButton)
```
---

### Enable

Enables the button. Returns FALSE if the button was previously enabled; otherwise TRUE.

```
FUNCTION Enable (BYVAL hButton AS HWND) AS BOOLEAN
```

#### Usage example
```
CButton.Enable(hButton)
```
---

### GetCheck

Gets the check state of a radio button or check box. 

```
FUNCTION GetCheck (BYVAL hButton AS HWND) AS LRESULT
```
#### Return value

The return value from a button created with the **BS_AUTOCHECKBOX**, **BS_AUTORADIOBUTTON**, **BS_AUTO3STATE**, **BS_CHECKBOX**, **BS_RADIOBUTTON**, or **BS_3STATE** style can be one of the following.

| Return code  | Description |
| ------------ | ----------- |
| **BST_CHECKED** | Button is checked. |
| **BST_INDETERMINATE** | Button is grayed, indicating an indeterminate state (applies only if the button has the **BS_3STATE** or **BS_AUTO3STATE** style). |
| **BST_UNCHECKED** | Button is cleared. |

#### Usage example
```
DIM bst AS LRESULT = CButton.GetCheck(hButton)
```
---

### GetIdealSize

Gets the size of the button that best fits its text and image, if an image list is present.

```
FUNCTION GetIdealSize (BYVAL hButton AS HWND, BYVAL pSize AS SIZE PTR) AS BOOLEAN
FUNCTION GetIdealSize (BYVAL hButton AS HWND, BYREF sz AS SIZE) AS BOOLEAN
FUNCTION GetIdealSize (BYVAL hButton AS HWND) AS SIZE
```

| Parameter  | Description |
| ---------- | ----------- |
| *tsize* | A pointer to a **SIZE** structure that receives the desired size of the button, including text and image list, if present. The calling application is responsible for allocating this structure. Set the **cx** and **cy** members to zero to have the ideal height and width returned in the **SIZE** structure. To specify a button width, set the **cx** member to the desired button width. The system will calculate the ideal height for this width and return it in the **cy** member. |

#### Return value

If the message succeeds, it returns TRUE. Otherwise it returns FALSE.

#### Remarks

If no special button width is desired, then you must set both members of **SIZE** to zero to calculate and return the ideal height and width. If the value of the **cx** member is greater than zero, then this value is considered the desired button width, and the ideal height for this width is calculated and returned in the **cy** member.

This message is most applicable to PushButtons. When sent to a PushButton, the message retrieves the bounding rectangle required to display the button's text. Additionally, if the PushButton has an image list, the bounding rectangle is also sized to include the button's image.

When sent to a button of any other type, the size of the control's window rectangle is retrieved.

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage examples
```
DIM sz AS SIZE
DIM res AS BOOLEAN = CButton.GetIdealSize(hButton, @sz)
DIM res AS BOOLEAN = CButton.GetIdealSize(hButton, sz)
sz = CButton.GetIdealSize(hButton)
```
---

### GetBitmap

Retrieves a handle to the bitmap associated with the button.

```
FUNCTION GetBitmap (BYVAL hButton AS HWND) AS HANDLE
```

#### Return value

The return value is a handle to the bitmap, if any; otherwise, it is NULL.

#### Usage example
```
DIM hBmp AS HBIRMAP = CButton.GetBitmap(hButton)
```
---

### GetIcon

Retrieves a handle to the icon associated with the button.

#### Return value

The return value is a handle to the icon, if any; otherwise, it is NULL.

#### Usage example
```
DIM hicon AS HICON = CButton.GetIcon(hButton)
```
---

### GetImage

Retrieves a handle to the image (icon or bitmap) associated with the button.

```
FUNCTION GetImage (BYVAL hButton AS HWND, BYVAL imgType AS LONG) AS HANDLE
```

| Parameter | Description |
| --------- | ----------- |
| *imgType* | The type of image to associate with the button. This parameter can be one of the following values. |

| Value | Meaning |
| ------------ | ----------- |
| **IMAGE_BITMAP** | A bitmap. |
| **IMAGE_ICON** | An icon. |

#### Return value

The return value is a handle to the image, if any; otherwise, it is NULL.

#### Usage examples
```
DIM hBmp AS HBITMAP = CButton.GetIcon(hButton, IMAGE_BITMAP)
DIM hIcon AS HICON = CButton.GetIcon(hButton, IMAGE_ICON)
```
---

### GetImageList

Gets the **BUTTON_IMAGELIST** structure that describes the image list assigned to a button control. 

```
FUNCTION GetImageList (BYVAL hButton AS HWND, BYVAL pbuttonImagelist AS BUTTON_IMAGELIST PTR) AS BOOLEAN
FUNCTION GetImageList (BYVAL hButton AS HWND, BYREF buttonImagelist AS BUTTON_IMAGELIST) AS BOOLEAN
FUNCTION GetImageList (BYVAL hButton AS HWND) AS BUTTON_IMAGELIST
```

| Parameter | Description |
| --------- | ----------- |
| *pbuttonImagelist* | A pointer to a **BUTTON_IMAGELIST** structure that receives the image list information. |
| *buttonImagelist* | A **BUTTON_IMAGELIST** structure that receives the image list information. |

#### Usage examples
```
DIM bi AS BUTTON_IMAGELIST
CButton.GetImageList(hButton, @bi)
CButton.GetImageList(hButton, bi)
bi = CButton.GetImageList(hButton)
```
---

### GetNote

Gets the text of the note associated with the Command Link button.

```
FUNCTION GetNote (BYVAL hButton AS HWND) AS DWSTRING
```

#### Remarks

The **BCM_GETNOTE** message works only with buttons that have the **BS_COMMANDLINK** or **BS_DEFCOMMANDLINK** button style.

#### Usage example
```
DIM dwsNote AS DWSTRING = CButton.GetNote(hButton)
```
---

### GetNoteLength

Gets the length of the note text that may be displayed in the description for a command link.

```
FUNCTION GetNoteLength (BYVAL hButton AS HWND) AS LONG
```

#### Return value

Returns the length of the note text in Unicode characters, not including any terminating NULL, or zero if there is no note text.

#### Usage example
```
DIM cbNote AS LONG = CButton.GetNoteLength(hButton)
```
---

### GetSplitImageList

Gets the handle of the split button image list.

```
FUNCTION GetSplitImageList (BYVAL hButton AS HWND) AS HIMAGELIST
```

#### Return value

The handle of the split button image list.

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage example
```
DIM himl AS HIMAGELIST = CButton.GetSplitImageList
```
---

### GetSplitInfo

Gets information for a split button control. 

```
FUNCTION GetSplitInfo (BYVAL hButton AS HWND, BYVAL pinfo AS BUTTON_SPLITINFO PTR) AS BOOLEAN
FUNCTION GetSplitInfo (BYVAL hButton AS HWND, BYVAL info AS BUTTON_SPLITINFO) AS BOOLEAN
FUNCTION GetSplitInfo (BYVAL hButton AS HWND) AS BUTTON_SPLITINFO
```

| Parameter | Description |
| --------- | ----------- |
| *pinfo* | A pointer to a **BUTTON_SPLITINFO** structure to receive information on the button. The caller is responsible for allocating the memory for the structure. Set the **mask** member of this structure to determine what information to receive. |
| *info* | A **BUTTON_SPLITINFO** structure to receive information on the button. The caller is responsible for allocating the memory for the structure. Set the **mask** member of this structure to determine what information to receive. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage examples
```
info AS BUTTON_SPLITINFO
CButton.GetSplitInfo(hButton, @info)
CButton.GetSplitInfo(hButton, info)
info = CButton.GetSplitInfo(hButton)
```
---

### GetSplitGlyphSize

Gets the size of the glyph in the image list.

```
FUNCTION GetSplitGlyphSize (BYVAL hButton AS HWND) AS SIZE
```

#### Return value

A **SIZE** structure that specifies the size of the glyph.

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage examples
```
DIM sz AS SIZE = CButton.GetSplitGlyphSize(hButton)
```
---

### GetSplitStyle

Gets the split button style.

```
FUNCTION GetSplitStyle (BYVAL hButton AS HWND) AS UINT
```

#### Return value

The split button style. Can be be one or more of the following flags.

| Value | Description |
| ------------ | ----------- |
| **BCSS_ALIGNLEFT** | Align the image or glyph horizontally with the left margin. |
| **BCSS_IMAGE** | Draw an icon image as the glyph. |
| **BCSS_NOSPLIT** | No split. |
| **BCSS_STRETCH** | Stretch glyph, but try to retain aspect ratio. |

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage examples
```
DIM dwStyle AS UINT  = CButton.GetSplitStyle(hButton)
```
---

### GetState

Retrieves the state of a button or check box. 

```
FUNCTION GetState (BYVAL hButton AS HWND) AS LRESULT
```

#### Return value

The return value specifies the current state of the button. It is a combination of the following values.

| Return code  | Description |
| ------------ | ----------- |
| **BST_CHECKED** | The button is checked. |
| **BST_DROPDOWNPUSHED** | The button is in the drop-down state. Applies only if the button has the **TBSTYLE_DROPDOWN** style. |
| **BST_FOCUS** | The button has the keyboard focus. |
| **BST_HOT** | The button is hot; that is, the mouse is hovering over it. |
| **BST_INDETERMINATE** | The state of the button is indeterminate. Applies only if the button has the **BS_3STATE** or **BS_AUTO3STATE** style. |
| **BST_PUSHED** | The button is being shown in the pushed state. |
| **BST_UNCHECKED** | No special state. Equivalent to zero. |

#### Usage example
```
DIM bst AS LRESULT = CButton.GetState(hButton)
```
---

### GetStyle

Retrieves the style of the button.

```
FUNCTION GetStyle (BYVAL hButton AS HWND) AS DWORD
```

#### Return value

The style of the button.

#### Usage example
```
DIM dwStyle AS DWORD = CButton.GetStyle(hButton)
```
---

### GetText

Retrieves the text in a button control.

```
FUNCTION GetText (BYVAL hButton AS HWND) AS DWSTRING
```

#### Usage example
```
DIM dwsText AS DWSTRING = CButton.GetText(hButton)
```
---

### GetTextLength

Determines the length, in characters, of the text associated with a button.

```
FUNCTION GetTextLength (BYVAL hButton AS HWND) AS LONG
```

#### Usage example
```
DIM cbLen AS LONG = CButton.GetTextLength(hButton)
```

#### Return value

The return value is the length of the text in characters, not including the terminating null character.

---

### GetTextMargin

Retrieves the margins used to draw text in a button control.

```
FUNCTION GetTextMargin (BYVAL hButton AS HWND, BYVAL pMargin AS RECT PTR) AS BOOLEAN
FUNCTION GetTextMargin (BYVAL hButton AS HWND, BYREF pMargin AS RECT) AS BOOLEAN
FUNCTION GetTextMargin (BYVAL hButton AS HWND) AS RECT
```
| Parameter | Description |
| --------- | ----------- |
| *pMargin* | A pointer to a **RECT** structure that contains the margins to use for drawing text. |
| *margin* | A **RECT** structure that contains the margins to use for drawing text. |

#### Return value

If the message succeeds, it returns TRUE. Otherwise it returns FALSE.

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage example
```
DIM rc AS RECT
CButton.GetTextMargin(hButton, @rc)
CButton.GetTextMargin(hButton, rc)
rc = CButton.GetTextMargin(hButton)
```
---

### Gray

Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the **BS_3STATE** or **BS_AUTO3STATE** style.

```
SUB Gray (BYVAL hButton AS HWND)
```

#### Usage example
```
CButton.Gray(hButton)
```
---

### Indeterminate

Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the **BS_3STATE** or **BS_AUTO3STATE** style.

```
SUB Indeterminate (BYVAL hButton AS HWND)
```
#### Usage example
```
CButton.Indeterminate(hButton)
```
---

### SetBitmap

Associates a new bitmap with the button.

```
FUNCTION SetBitmap (BYVAL hButton AS HWND, BYVAL hbmp AS HBITMAP) AS HBITMAP
```

| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle of the button control. |
| *hBmp* | Handle of bitmap. |

#### Return value

The return value is a handle to the bitmap previously associated with the button, if any; otherwise, it is NULL.

#### Usage example
```
CButton.SetBitmap(hButton, hBmp)
```
---

### SetCheck

Sets the check state of a radio button or check box.

```
SUB SetCheck (BYVAL hButton AS HWND, BYVAL checkState AS LONG)
```
| Value | Meaning |
| ----- | ----------- |
| *checkState* | The check state. This parameter can be one of the following values. |

| Parameter | Description |
| --------- | ----------- |
| **BST_CHECKED** | Sets the button state to checked. |
| **BST_INDETERMINATE** | Sets the button state to grayed, indicating an indeterminate state. Use this value only if the button has the **BS_3STATE** or **BS_AUTO3STATE** style. |
| **BST_UNCHECKED** | Sets the button state to cleared. |

#### Return value

This message always returns zero.

#### Remarks

The **BM_SETCHECK** message has no effect on push buttons.

#### Usage example
```
CButton.SetCheck(hButton, BST_CHECKED)
```
---

### SetDontClick

Sets a flag on a radio button that controls the generation of BN_CLICKED messages when the button receives focus.

```
SUB SetDontClick (BYVAL hButton AS HWND, BYVAL fState AS BOOLEAN)
```

| Parameter | Description |
| --------- | ----------- |
| *fState* | A BOOLEAN that specifies the state. TRUE to set the flag, otherwise FALSE. |

#### Usage example
```
CButton.SetDontClick(hButton, TRUE)
```

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

---

### SetDropdownState

Sets the drop down state for a specified button with style of **BS_SPLITBUTTON**.
```
FUNCTION SetDropDownState (BYVAL hButton AS HWND, BYVAL fDropDown AS BOOLEAN) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *fDropDown* | A BOOLEAN that is TRUE for state of **BST_DROPDOWNPUSHED**, or FALSE otherwise. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage example
```
CButton.SetDropDownState(hButton, TRUE)
```
---

### SetElevationRequiredState

Sets the elevation required state for a specified button or command link to display an elevated icon.

```
FUNCTION SetElevationRequiredState (BYVAL fRequired AS BOOLEAN) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *fRequired* | A BOOL that is TRUE to draw an elevated icon, or FALSE otherwise. |

#### Return value

Returns 1 if successful, or an error code otherwise.

#### Remarks

An application must be manifested to use comctl32.dll version 6 to gain this functionality.

#### Usage example
```
CButton.SetElevationRequiredState(hButton, TRUE)
```
---

### SetIcon

Associates a new icon with the button.

```
FUNCTION SetIcon (BYVAL hButton AS HWND, BYVAL hIcon AS HICON) AS HICON
```

| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle of the button control. |
| *hIcon* | Handle of icon. |

#### Return value

The return value is a handle to the icon previously associated with the button, if any; otherwise, it is NULL.

#### Usage example
```
CButton.SetIcon(hButton, hIcon)
```
---

### SetImage

Associates a new image (icon or bitmap) with the button. The return value is a handle to the image previously associated with the button, if any; otherwise, it is NULL.

```
FUNCTION SetImage (BYVAL hButton AS HWND, BYVAL ImageType AS DWORD, BYVAL hImage AS HANDLE) AS HANDLE
```

| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle of the button control. |
| *ImageType* | The type of image to delete. This parameter can be one of the following values (se below): |
| *hImage* | Handle of the icon or bitmap. |

| Value | Meaning |
| ------------ | ----------- |
| **IMAGE_BITMAP** | A bitmap. |
| **IMAGE_ICON** | An icon. |

#### Return value

The return value is a handle to the image (icon or bitmap) previously associated with the button, if any; otherwise, it is NULL.

#### Usage examples
```
CButton.SetImage(hButton, IMAGE_BITMAP, hBmp)
CButton.SetImage(hButton, IMAGE_ICON, hIcon)
```
---

### SetImageList

Assigns an image list to a button control.

```
FUNCTION SetImageList (BYVAL hButton AS HWND, BYVAL pbuttonImagelist AS BUTTON_IMAGELIST PTR) AS BOOLEAN
FUNCTION SetImageList (BYVAL hButton AS HWND, BYVAL himl AS HIMAGELIST, BYVAL nLeft AS LONG, _
   BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG, BYVAL uALign AS UINT = 0) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle to the button control. |
| *pbuttonImagelist* | A pointer to a **BUTTON_IMAGELIST** structure that contains image list information. |

| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle to the button control. |
| *hImageList* | The handle to the image list. |
| *nLeft* | The x-coordinate of the upper-left corner of the rectangle for the image. |
| *nTop* | The y-coordinate of the upper-left corner of the rectangle for the image. |
| *nRight* | The x-coordinate of the lower-right corner of the rectangle for the image. |
| *nBottom* | The y-coordinate of the lower-right corner of the rectangle for the image. |
| *uAlign* | The alignment to use. This parameter can be one of the following values: |

| Value  | Meaning |
| ------ | ------- |
| **BUTTON_IMAGELIST_ALIGN_LEFT** | Align the image with the left margin. |
| **BUTTON_IMAGELIST_ALIGN_RIGHT** | Align the image with the right margin. |
| **BUTTON_IMAGELIST_ALIGN_TOP** | Align the image with the top margin. |
| **BUTTON_IMAGELIST_ALIGN_BOTTOM** | Align the image with the bottom margin. |
| **BUTTON_IMAGELIST_ALIGN_CENTER** |  Center the image. |

The default value is **BUTTON_IMAGELIST_ALIGN_LEFT**.

#### Return value

If the message succeeds, it returns TRUE. Otherwise it returns FALSE.

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

The image list referred to in the himl member of the **BUTTON_IMAGELIST** structure should contain either a single image to be used for all states or individual images for each state. The following states are defined in vssym32.h.
```
enum PUSHBUTTONSTATES {
    PBS_NORMAL = 1,
    PBS_HOT = 2,
    PBS_PRESSED = 3,
    PBS_DISABLED = 4,
    PBS_DEFAULTED = 5,
    PBS_STYLUSHOT = 6,
};
```
Note that **PBS_STYLUSHOT** is used only on tablet computers.

Each value is an index to the appropriate image in the image list. If only one image is present, it is used for all states. If the image list contains more than one image, each index corresponds to one state of the button. If an image is not provided for each state, nothing is drawn for those states without images.

---

### SetNote

Sets the text of the note associated with a specified command link button.

```
FUNCTION SetNote (BYREF pwsz AS WSTRING) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *pwsz* | A pointer to a null-terminated unicode string that contains the note. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Beginning with comctl32 DLL version 6.01, command link buttons may have a note.

The **BCM_SETNOTE** message works only with the **BS_COMMANDLINK** and **BS_DEFCOMMANDLINK** button styles.

The note text is displayed underneath the main caption. Command Link buttons require extra vertical space; if the control is too short, Windows will hide the note and render a single-line layout. ake the button taller to ensure the note becomes visible.

#### Usage examples
```
CButton.SetNote(hButton, "My note")
```
---

### SetSplitImageList

Sets the image list used as split glyph (BCSIF_IMAGE / BCSIF_GLYPH).

```
FUNCTON SetSplitImageList (BYVAL hButton AS HWND, BYVAL himlGlyph AS HIMAGELIST) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle to the button control. |
| *himlGlyph* | The handle of the image list. |

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0.

#### Usage examples
```
CButton.SetNote(hButton, himlGlyph)
```
---

### SetSplitInfo

Sets information for a specified split button control.

```
FUNCTION SetSplitInfo (BYVAL hButton AS HWND, BYVAL pinfo AS BUTTON_SPLITINFO PTR) AS BOOLEAN
FUNCTION SetSplitInfo (BYVAL hButton AS HWND, BYREF info AS BUTTON_SPLITINFO) AS BOOLEAN
```

| Parameter | Description |
| --------- | ----------- |
| *hButton* | Handle of the button control. |
| *pinfo* | A pointer to a **BUTTON_SPLITINFO** structure containing information about the split button. |
| *info* | A **BUTTON_SPLITINFO** structure containing information about the split button. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

---

### SetSplitGlyphSize

Sets the split size (glyph area) of a split button.

```
SetSplitGlyphSize (BYVAL hButton AS HWND, BYVAL cx AS LONG, BYVAL cy AS LONG) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hButton* | Handle of the button control. |
| *cx* | The width of the glyph area. |
| *cy* | The height of the glyph area. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

#### Usage examples
```
CButton.SetSplitGlyphSize(hButton, 30, 30)
```
---

### SetSplitStyle

Sets the split style of a split button

```
FUNCTION SetSplitStyle (BYVAL hButton AS HWND, BYVAL uStyle AS UINT) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hButton* | Handle of the button control. |
| *uStyle* | The split button style. Value must be one or more of the following flags: |

| Value  | Meaning |
| ------ | ------- |
| **BCSS_ALIGNLEFT** | Align the image or glyph horizontally with the left margin. |
| **BCSS_IMAGE** | Draw an icon image as the glyph. |
| **BCSS_NOSPLIT** | No split. |
| **BCSS_STRETCH** | Stretch glyph, but try to retain aspect ratio. |

#### Return value

Returns TRUE if successful, or FALSE otherwise.

#### Remarks

Use this message only with the **BS_SPLITBUTTON** and **BS_DEFSPLITBUTTON** button styles.

#### Usage examples
```
CButton.SetSplitStyle(hButton, BCSS_ALIGNLEFT)
```
---

### SetState

Sets the highlight state of a button. The highlight state indicates whether the button is highlighted as if the user had pushed it. 

```
SUB SetState (BYVAL hButton AS HWND, BYVAL bstate AS BOOLEAN)
```
| Parameter | Description |
| --------- | ----------- |
| *bstate* | A BOOLEAN that specifies whether the button is highlighted. A value of TRUE highlights the button. A value of FALSE removes any highlighting. |

#### Remarks

Highlighting affects only the appearance of a button. It has no effect on the check state of a radio button or check box.

A button is automatically highlighted when the user positions the cursor over it and presses and holds the left mouse button. The highlighting is removed when the user releases the mouse button.

#### Usage example
```
CButton.SetState(hButton, TRUE)
```
---

### SetStyle

Sets the style of a button.

```
SUB SetStyle (BYVAL hButton AS HWND, BYVAL dwStyle AS DWORD, BYVAL fRedraw AS BOOLEAN)
```
| Parameter | Description |
| --------- | ----------- |
| *dwStyle* | The button style. This parameter can be a combination of button styles. |
| *fRedraw* | A BOOLEAN that specifies whether the button is to be redrawn. A value of TRUE redraws the button; a value of FALSE does not redraw the button. |

For a table of button styles, see [Button Styles](https://learn.microsoft.com/en-us/windows/win32/controls/button-styles).

---

### SetText

Sets the text of a button.

```
FUNCTION SetText (BYVAL hButton AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle of te button control. |
| *pwszText* | The new text. |

#### Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.

#### Usage example
```
CButton.SetText(hButton, "Ok")
```
---

### SetTextMargin

Sets the margins used to draw text in a button control.

```
FUNCTION SetTextMargin (BYVAL hButton AS HWND, BYVAL pMargin AS RECT PTR) AS BOOLEAN
FUNCTION SetTextMargin (BYVAL hButton AS HWND, BYREF margin AS RECT) AS BOOLEAN
FUNCTION SetTextMargin (BYVAL hButton AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, _
   BYVAL nRight AS LONG, BYVAL nBottom AS LONG) AS BOOLEAN
```
| Parameter | Description |
| --------- | ----------- |
| *hButton* | The handle of the button control. |
| *pMargin* | A pointer to a **RECT** structure that specifies the margins to use for drawing text. |
| *margin* | A **RECT** structure that specifies the margins to use for drawing text. |
| *nLeft* | The left margin. |
| *nTop* | The top margin. |
| *nRight* | The right margin. |
| *nBottom* | The bottom margin. |

#### Return value

If the message succeeds, it returns TRUE. Otherwise it returns FALSE.

#### Remarks

To use this message, you must provide a manifest specifying Comclt32.dll version 6.0. For more information on manifests, see Enabling Visual Styles.

---

### Uncheck

Unchecks the button.

```
SUB CButton.Uncheck ()
```

#### Example usage
```
CButton.Uncheck(hButton)
```
---

### SetDarkMode

Sets the dark mode of the button.

```
FUNCTION SetDarkMode(BYVAL hButton AS HWND) AS HRESULT
```

#### Example usage
```
CButton.SetDarkMode(hButton)
```
---

### RemoveDarkMode

Removes dark mode from the button.

```
FUNCTION RemoveDarkMode (BYVAL hButton AS HWND) AS HRESULT
```

#### Example usage
```
CButton.RemoveDarkMode(hButton)
```
---
