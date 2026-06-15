# CDialog Class

**Introducing CDialog: A Streamlined Dialog Engine for FreeBasic**

`CDialog` is a lightweight yet powerful dialog engine tailored for FreeBasic developers seeking a clean, high-level approach to building Windows dialogs — without sacrificing control or clarity. Inspired by the straightforwardness of PowerBasic’s DDT model, yet engineered with modern design in mind, `CDialog` offers structured, maintainable UI development rooted in the familiar logic of the Windows API.

At its core, `CDialog` replicates and refines the DDT engine, delivering cleaner syntax, robust internal architecture, and simplified message handling. Whether you're building modal or modeless dialogs, adding controls, or managing layout behavior, `CDialog` keeps things intuitive and transparent — no bloat, no black boxes.

Among its standout features is the automatic anchoring system, which minimizes the tedium of UI resizing logic. By applying simple declarative rules, it handles control repositioning and scaling automatically — sparing developers the hassle of manual calculations. Crucially, this system works identically for dialogs defined in pixels or dialog units, providing consistency and flexibility across design styles.

And for those who prefer procedural syntax, `DDT.inc` bridges the gap by exposing DDT-style wrappers atop the `CDialog` class — allowing developers to adopt `CDialog` incrementally or stick with the idioms they already know.

Whether you're modernizing legacy utilities, crafting new tools, or just writing code for fun, `CDialog` delivers a flexible, DPI-aware foundation that respects both your time and your muscle memory.

**Include file**: AfxNova/CDialog.inc.

| Name       | Description |
| ---------- | ----------- |
| [Constructor](#constructor) | Creates instances of the `CDialog` class. |
| [hDialog](#hdialog) | Gets/sets the handle of the dialog. |
| [IsModal](#ismodal) | Checks if the dialog is modal. |
| [IsCustom](#iscustom) | Checks if it is a custom dialog. |
| [UsesPixels](#usespixels) | Checks if the dialog uses pixels. |
| [UsesUnits](#usesunits) | Checks if the dialog uses dialog units. |

---

# Dialog methods

| Name       | Description |
| ---------- | ----------- |
| [DialogNew](#dialognew) | Creates a new dialog using dialog units. |
| [DialogNewPixels](#dialognewpixels) | Creates a new dialog using pixels. |
| [DialogShowModal](#dialogshowmodal) | Shows the dialog as modal. |
| [DialogShowModeless](#dialogshowmodeless) | Shows the dialog as modeless. |
| [DialogEnd](#dialogend) | Ends the dialog. |
| [DialogEndResult](#dialogendresult) | Returns the value passed to DialogEnd. |
| [DialogDoEvents](#dialogdoevents) | Message pump for modeless dialogs. |
| [GetDefId](#getdefid) | Retrieves the identifier of the default push button control for a dialog box. |
| [SetDefId](#setdefid) | Changes the identifier of the default push button for a dialog box. |
| [DialogReposition](#dialogreposition) | Repositions a top-level dialog box so that it fits within the desktop area. |
| [DialogShowState](#dialogshowstate) | Change the visible state of a dialog. |
| [DialogMaximize](#dialogmaximize) | Maximizes the dialog. |
| [DialogMinimize](#dialogminimize) | Minimizes the dialog. |
| [DialogHide](#dialoghide) | Hides the dialog. |
| [DialogNormalize](#dialognormalize) | Makes the dialog visible at its normal size and position. |
| [DialogDisable](#dialogdisable) | Disables the dialog. |
| [DialogEnable](#dialogenable) | Enables the dialog. |
| [DialogRedraw](#dialogredraw) | Redraws the dialog. |
| [DialogForceVisibility](#dialogforcevisibility) | Repositions the dialog if it is off-screen. |
| [DialogCenter](#dialogcenter) | Centers the dialog. |
| [DialogStabilize](#dialogstabilize) | Makes a Dialog stabilized (non-closeable). |
| [DialogNonStable](#dialognonstable) | Makes a Dialog non stable (closeable). |
| [IsDialogStabilized](#isdialogstabilized) | Checks if the dialog is stabilized. |
| [IsDialogNonStable](#isdialognonstable) | Checks if the dialog is non stable. |
| [DialogPost](#dialogpost) | Posts a message in the message queue. |
| [DialogSend](#dialogsends) | Sends a message to the dialog. |
| [DialogGetSize](#dialoggetsize) | Gets the width and height of the dialog. |
| [DialogGetWidth](#dialoggetwidth) | Gets the width of the dialog. |
| [DialogGetHeight](#dialoggetheight) | Gets the height of the dialog. |
| [DialogSetSize](#dialogsetsize) | Sets the size of the dialog. |
| [DialogGetBounds](#dialoggetbounds) | Retrieves the bounds of a window without the drop shadows. |
| [DialogGetClient](#dialoggetclient) | Retrieves the coordinates of the dialog's client area. |
| [DialogGetClientWidth](#dialoggetclientwidth) | Gets the width of the the dialog's client area. |
| [DialogGetClientHeight](#dialoggetclientheight) | Gets the height of the the dialog's client area. |
| [DialogSetClient](#dialogsetclient) | Adjusts the bounding rectangle of the dialog based on the desired size of the client area. |
| [DialogGetText](#dialoggettext) | Gets the text of the dialog caption. |
| [DialogSetText](#dialogsettext) | Sets the text of the dialog caption. |
| [DialogGetLoc](#dialoggetloc) | Gets the location of the top left corner of the window. |
| [DialogSetLoc](#dialogsetloc) | Sets the location of the top left corner of the window. |
| [DialogGetUser](#dialoggetuser) | Retrieves a value from the user data area of the dialog. |
| [DialogSetUser](#dialogsetuser) | Sets a value in the user data area of a dialog. |
| [CBGetDlgMsgResult](#cbgetdlgmsgresult) | Gets the return value of a message processed in the dialog box procedure. |
| [CBSetDlgMsgResult](#cbsetdlgmsgresult) | Sets the return value of a message processed in the dialog box procedure. |

---

# Control methods

| Name       | Description |
| ---------- | ----------- |
| [ControlAdd](#controladd) | Adds a control to the dialog. |
| [ControlSetFocus](#controlsetfocus) | Sets the focus in the specified control of a dialog box. |
| [ControlDisable](#controldisable) | Disables the specified control. |
| [ControlEnable](#controlenable) | Enables the specified control. |
| [ControlGetLoc](#controlgetloc) | Gets the location of the top left corner of the window. |
| [ControlSetLoc](#controlsetloc) | Sets the location of the top left corner of the window. |
| [ControlGetText](#controlgettext) | Retrieves the text in a control or control caption. |
| [ControlSetText](#sontrolsettext) | Sets the text in a control or control caption. |
| [ControlHandle](#controlhandle) | Returns a window handle for the specified control ID. |
| [ControlHide](#controlhide) | Hides the specified control. |
| [ControlNormalize](#controlmormalize) | Makes visible the specified control. |
| [ControlKill](#controlkill) | Destroys the specified control. |
| [ControlShowState](#controlshowstate) | Changes the visible state of a control. |
| [ControlRedraw](#controlredraw) | Redraws the specified control. |
| [ControlPost](#controlpost) | Posts a message in the message queue. |
| [ControlSend](#controlsend) | Sends the specified message to the specified control. |
| [ControlGetSize](#controlgetsize) | Gets the width and height of the control. |
| [ControlGetWidth](#controlgetwidth) | Gets the width of the control. |
| [ControlGetHeight](#controlgetheight) | Gets the height of the control. |
| [ControlSetSize](#controlsetsize) | Sets the width and height of the specified window. |
| [ControlGetClient](#controlgetclient) | Retrieves the coordinates of the control's client area. |
| [ControlGetClientWidth](#controlgetclientwidth) | Gets the width of the control's client area. |
| [ControlGetClientHeight](#controlgetclientheight) | Gets the height of the control's client area. |
| [ControlSetClient](#controlsetclient) | Adjusts the bounding rectangle of the dialog based on the desired size of the client area. |
| [ControlCenterHoriz](#controlcenterhoriz) | Moves the control to the center of the dialog horizontally |
| [ControlCenterVert](#controlcentervert) | Moves the control to the center of the dialog vertically. |
| [ControlGetCheck](#controlgetcheck) | Gets the check state of a radio button or check box. |
| [ControlSetCheck](#controlsetcheck) | Sets the check state of a radio button or check box. |
| [ControlSetOption](#controlsetoption) | Sets the check state for an Option (radio) control, and unsets the check state for other Option buttons in a group. |

---

# Fonts

| Name       | Description |
| ---------- | ----------- |
| [DialogGetFont](#dialoggetfont) | Gets the handle of the font used by the dialog. |
| [DialogGetFontFaceName](#dialoggetfontfacename) | Gets the face name of the font used by the dialog. |
| [DialogGetFontPointSize](#dialoggetfontpointsize) | Gets the point size of the font used by the dialog. |
| [FontNew](#fontnew) | Creates a logical font. |
| [FontEnd](#fontend) | Destroys a font when it is no longer needed. |
| [ControlGetFont](#controlgetfont) | Gets the handle of the font used by the control. |
| [ControlSetFont](#controlsetfont) | Sets the font that a control is to use when drawing text. |
| [ControlGetFontFaceName](#controlgetfontfacename) | Gets the face name of the font used by the control. |
| [ControlGetFontPointSize](#controlgetfontpointsize) | Gets the point size of the font used by the control. |

---

# Images

| Name       | Description |
| ---------- | ----------- |
| [DialogSetIcon](#dialogseticon) | Changes both the dialog icon in the caption, and the icon shown in the ALT+TAB task list. |
| [DialogSetIconEx](#dialogseticonex) | Sets the big and small icons of the dialog. |
| [FindResourceType](#findresourcetype) | Finds the resource type given it's identifier or name. |
| [ControlSetImage](#controlsetimage) | Changes the icon or bitmap displayed in an image label control. |
| [ControlSetImageX](#controlsetimagex) | Changes the icon or bitmap displayed in an image label control. |
| [ControlSetImgButton](#controlsetimagebutton) | Changes the bitmap displayed in an image button control. |
| [ControlSetImgButtonX](#controlsetimagebuttonx) | Changes the bitmap displayed in an image button control. |

---


# Metric conversions

| Name       | Description |
| ---------- | ----------- |
| [DialogUnitsToPixels](#dialogunitstopixels) | Converts the specified dialog box units to screen units (pixels). |
| [DialogUnitsToPixelsRatios](#dialogunitstopixelsratios) | Retrieves the conversion ratios from dialog units to pixels. |
| [DluToPixRX](#dlutopixrx) | Retrieves the conversion ratios from dialog units to pixels. |
| [DluToPixRX](#dlutopixrx) | Retrieves the conversion ratios from dialog units to pixels. |
| [PixelsToDialogUnits](#pixelstodialogunits) | Converts the specified screen units (pixels) to dialog box units. |
| [PixelsToDialogUnitsRatios](#pixelstodialogunitsratios) | Retrieves the conversion ratios from pixels to dialog units. |
| [PixToDluRX](#pixtodlurx) | Retrieves the conversion ratio from pixels to dialog units. |
| [PixToDluRY](#pixtodlury) | Retrieves the conversion ratio from pixels to dialog units. |

---

# DPI scaling

| Name       | Description |
| ---------- | ----------- |
| [rxRatio](rxratio) | Returns the horizontal DPI scaling ratio. |
| [ryRatio](rxratio) | Returns the vertical DPI scaling ratio. |
| [ScaleX](scalex) | Scales an horizontal coordinate according the DPI (dots per pixel) being used by the desktop. |
| [ScaleY](scaley) | Scales a vertical coordinate according the DPI (dots per pixel) being used by the desktop. |
| [UnscaleX](unscalex) | Unscales an horizontal coordinate according the DPI (dots per pixel) being used by the desktop. |
| [UnscaleY](unscaley) | Unscales a vertical coordinate according the DPI (dots per pixel) being used by the desktop. |
| [ScaleRect](scalerect) | Scales a RECT structure according the DPI (dots per pixel) being used by the desktop. |
| [UnscaleRect](unscalerect) | Unscales a RECT structure according the DPI (dots per pixel) being used by the desktop. |

---

# Layout manager

| Name       | Description |
| ---------- | ----------- |
| [AdjustControls](#adjustcontrols) | Adjust the controls size and/or position. |
| [ControlAnchor](#ControlAnchor) | Anchor the control. |
| [GetAnchorItem](#getanchoritem) | Gets the anchor item. |

---

# Colors

| Name       | Description |
| ---------- | ----------- |
| [ControlSetColor](#controlsetcolor) | Sets the colors of the control. |
| [DialogSetColor](#dialogsetcolor) | Sets the background color of the dialog. |
| [DialogDisableRepaintOnResize](#dialogdisablerepaintonresize) | Enable/disable dialog repainting during resizing. |
| [DialogEnableRepaint](#dialogenablerepaint) | Enable/disable dialog repainting during resizing. |
| [GetColorItem](#getcoloritem) | Gets the color item. |
| [IsDialogRepaintDisabled](#isdialogrepaintdisabled) | Checks if repainting is enabled during resizing. |
| [IsDialogRepaintDisabledOnResize](#isdialogrepaintdisabledonresize) | Checks if repainting is enabled during resizing. |

---

# Keyboard accelerators

| Name       | Description |
| ---------- | ----------- |
| [AccelHandle](#accelhandle) | Gets the accelerator table handle. |
| [AccelAttach](#accelattach) | Attaches an accelerator table handle. |
| [AddAccelerator](#addaccelerator) | Adds an accelerator key to the table. |
| [CreateAcceleratorTable](#createacceleratortable) | Creates the accelerator table. |
| [DestroyAcceleratorTable](#destroyacceleratortable) | Destroys the accelerator table. |

---

# Scrollable dialogs

| Name       | Description |
| ---------- | ----------- |
| [DialogSetViewPort](#dialogsetviewport) | Makes a dialog scrollable by shrinking its client area size. |
| [IsDialogScrollable](#isdialogscrollable) | Flag indicating if a dialog is scrollable. |
| [DialogResetScrollBars](#dialogresetscrollbars) | Resets the dikalog scrolling information. |
| [DialogSetupScrollBars](#dialogsetupscrollbars) | Sets the dialog scroll information. |
| [DialogOnVScroll](#dialogonvscroll) | Handles vertical scrollbar messages. |
| [DialogOnHScroll](#dialogonhscroll) | Handles horizontañ scrollbar messages. |
| [DialogOnSize](#dialogonsize) | Handles WM_SIZE messges. |

---

# Helper function

| Name       | Description |
| ---------- | ----------- |
| [CDialogPtr](#cdialogptr) | Returns a pointer to the `CDialog` class given the handle of the window created with it or the handle of any of it's children. |

---

### <a name="constructor"></a>Constructor

Creates instances of the `CDialog` class.

```
CONSTRUCTOR (BYREF fontName AS WSTRING = "Segoe UI", BYVAL ptSize AS LONG = 9, _
   BYVAL fontStyle AS BYTE = 0, BYVAL charset AS BYTE = DEFAULT_CHARSET) 
```
| Parameter  | Description |
| ---------- | ----------- |
| *fontName* | Optional. The font name. Default value: "Segoe UI" |
| *ptSize* | Optional. The font point size. Default value: 9 pt. |
| *fontStyle* | Optional. The font style. 0 = Normal. 2 = Italic. Default value: 0 |
| *charset* | Optional. The font character set. Default value: DEFAULT_CHARSET |

| Charset    | Description |
| ---------- | ----------- |
| **ANSI_CHARSET** | ANSI character set. |
| **ARABIC_CHARSET** | Arabic character set. |
| **BALTIC_CHARSET** | Baltic character set. |
| **CHINESEBIG5_CHARSET** | Traditional Chinese (Big 5) character set. |
| **DEFAULT_CHARSET** | Character set value based on the system default Windows ANSI code page. For example, when the system locale is English (United States), it is set as ANSI_CHARSET. |
| **EASTEUROPE_CHARSET** | Eastern European character set. |
| **GB2312_CHARSET** | Simplified (PRC) Chinese character set. |
| **GREEK_CHARSET** | Greek character set. |
| **HANGEUL_CHARSET** | Korean (Hangul) character set. |
| **HEBREW_CHARSET** | Hebrew character set. |
| **JOHAB_CHARSET** | Korean (Johab) character set. |
| **MAC_CHARSET** | Character set value based on the current system Macintosh code page. This value is used primarily in legacy code and should not generally be needed since modern Macintosh computers use Unicode for encoding. |
| **OEM_CHARSET** | OEM-specific character set. The OEM character set is system dependent. |
| **RUSSIAN_CHARSET** | Cyrillic character set. |
| **SHIFTJIS_CHARSET** | Shift-JIS (Japanese Industry Standard) character set. |
| **SYMBOL_CHARSET** | Windows symbol character set. |
| **THAI_CHARSET** | Thai character set. |
| **TURKISH_CHARSET** | Turkish character set. |
| **VIETNAMESE_CHARSET** | Vietnamese character set. |

#### Usage examples
```
DIM pDialog AS CDialog
DIM pDialog AS CDialog = CDialog("Segoe UI", 9)
DIM pDialog AS CDialog = CDialog("Times New Roman", 10, 2, DEFAULT_CHARSET)
```
---

### <a name="hdialog"></a>hDialog

Returns the dialog handle.

```
PROPERTY hDialog () AS HWND
```
#### Usage example

```
DIM hDlg AS HWND = pDlg.hDialog
```
---

### <a name="ismodal"></a>IsModal

Returns TRUE if the dialog is modal; FALSE otherwise.

```
FUNCTION IsModal () AS BOOLEAN
```
#### Usage example

```
DIM bModal AS BOOLEAN = pDlg.IsModal
```
---

### <a name="iscustom"></a>IsCustom

Returns TRUE if it is a custom dialog; FALSE otherwise.

```
FUNCTION IsCustom () AS BOOLEAN
```
#### Usage example

```
DIM bCustom AS BOOLEAN = pDlg.IsCustom
```
---

### <a name="usespixels"></a>UsesPixels

Returns TRUE if the dialog uses pixels; FALSE otherwise.

```
FUNCTION UsesPixels () AS BOOLEAN
```
#### Usage example

```
DIM bUsesPixels AS BOOLEAN = pDlg.UsesPixels
```
---

### <a name="usesunits"></a>UsesUnits

Returns TRUE if the dialog uses dialog units; FALSE otherwise.

```
FUNCTION UsesUnits () AS BOOLEAN
```
#### Usage example

```
DIM bUsesUnits AS BOOLEAN = pDlg.UsesUnits
```
---

### <a name="dialognew"></a>DialogNew

Creates a dialog in memory. A new empty dialog is created, but not yet displayed. Once the dialog has been created and all of the desired controls have been added with, the dialog can be displayed with the **DialogShowModeless** or **DialogSHowModal** functions.

If a modeless dialog is created, the application must create a **DialogDoEvents** message pump for the duration of the dialog. Failure to provide a message pump can result in disruptions to the display of the dialog, or the inability of the dialog to respond to messages such as button clicks, etc. Modal dialogs do not require a message pump.

To change the displayed state of a dialog (i.e., hidden, minimized, etc) after the dialog has been created, use the **DialogShowState** function.

If a dialog does not have either WS_CHILD or WS_POPUP styles, Windows may enforce a minimum dialog width of some 60-70 dialog units.

You can give to the dialog a class Name of your choice; otherwise, the predefined class #32770" is used.

The overloaded function **DialogNewPixels** uses pixels instead of dialog units.

```
FUNCTION DialogNew (BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
   BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
   BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
```
```
FUNCTION DialogNew (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = HWND_DESKTOP, _
   BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, _
   BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, BYVAL dwStyle AS LONG = 0, _
   BYVAL dwExStyle AS LONG = 0) AS HWND
```
```
FUNCTION DialogNewPixels (BYVAL hParent AS HWND = HWND_DESKTOP, BYREF wszTitle AS WSTRING, _
   BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, _
   BYVAL dwStyle AS LONG = 0, BYVAL dwExStyle AS LONG = 0) AS HWND
```
```
FUNCTION DialogNewPixels (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = HWND_DESKTOP, _
   BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = -1, BYVAL y AS LONG = -1, _
   BYVAL cx AS LONG = 0, BYVAL cy AS LONG = 0, BYVAL dwStyle AS LONG = 0, _
   BYVAL dwExStyle AS LONG = 0) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszClassName* | The class name. |
| *hParent* | Handle of the parent window or dialog. If there is no parent, use zero (0) or HWND_DESKTOP. If the dialog is MODAL, the parent window/dialog will be disabled while this "child" dialog is running. |
| *wszTitle* | The text displayed in the title or caption bar of the dialog. |
| *x*, *y* | Optional location of the top-left corner for the dialog. The location is specified in the same terms (pixels or dialog units) as specified in the **DialogNew** / **DialogNewPixels** functions. If neither *x* and *y* are specified, the dialog is centered on the screen. If CW_USEDEFAULT (&H080000000) is specified, the default Windows position is used (cascading from the upper-left corner). |
| *cx*, *cy* | The width and height of the dialog. The size is specified in the same terms (pixels or dialog units) as specified in the  **DialogNew** / **DialogNewPixels** functions. If the default dialog style (or any other dialog style that includes the WS_CAPTION style) is used, the width and height parameters specify the client size only, and this does not include any caption and border dimensions. 

If the style does not include WS_CAPTION, the width and height specify the overall dialog size, including the caption and border, if any. Note that WS_CAPTION is a combination of the WS_BORDER and WS_DLGFRAME styles. The default dialog style includes WS_BORDER and WS_DLGFRAME styles, so it implicitly includes the WS_CAPTION style. |
| *dwStyle* |  |
| *dwExStyle* |  |

#### Return value

The Windows window handle assigned by Windows. This handle should be used with subsequent **Dialog** and **Control** functions, and may be directly used with Windows API calls.

If the dialog could not be created (i.e., due to low Windows resources), NULL is returned.
