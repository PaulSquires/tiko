# CTextDocument2 Class

Class that wraps all the methods of the **ITextDocument** and **ITextDocument2** interfaces.

| Name       | Description |
| ---------- | ----------- |
| [CONSTRUCTORS](#constructors) | Called when a class variable is created. |
| [DESTRUCTOR](#destructor) | Called automatically when a class variable goes out of scope or is destroyed. |
| [LET](#let) | Assignment operator. |
| [CAST](#cast) | Cast operator. |
| [TextDocumentPtr](#textdocumentptr) | Returns a pointer to the underlying **ITextDocument2** interface. |
| [Attach](#attach) | Attaches an **ITextDocument2** interface pointer to the class. |
| [Detach](#detach) | Detaches the underlying **ITextDocument2** interface pointer from the class. |

---

### ITextDocument Interface

The **ITextDocument** interface is the Text Object Model (TOM) top-level interface, which retrieves the active selection and range objects for any story in the document—whether active or not. It enables the application to:

- Open and save documents.
- Control undo behavior and screen updating.
- Find a range from a screen position.
- Get an **ITextStoryRanges** story enumerator.

#### When to implement

Applications typically do not implement the **ITextDocument** interface. Microsoft text solutions, such as rich edit controls, implement **ITextDocument** as part of their TOM implementation.

#### When to Use

Applications can retrieve an **ITextDocument** pointer from a rich edit control. To do this, send an **EM_GETOLEINTERFACE** message to retrieve an **IRichEditOle** object from a rich edit control. Then, call the object's **IUnknown::QueryInterface** method to retrieve an **ITextDocument** pointer.

#### Inheritance

The **ITextDocument** interface inherits from the IDispatch interface. **ITextDocument** also has these types of members:

| Name       | Description |
| ---------- | ----------- |
| [GetName](#getname) | Gets the file name of this document. |
| [GetSelection](#getselection) | Gets the active selection. |
| [GetStoryCount](#getstorycount) | Gets the count of stories in this document. |
| [GetStoryRanges](#getstoryranges) | Gets the story collection object used to enumerate the stories in a document. |
| [GetSaved](#getsaved) | Gets a value that indicates whether changes have been made since the file was last saved. |
| [SetSaved](#setsaved) | Sets the document **Saved** property. |
| [GetDefaultTabStop](#getdefaulttabstop) | Gets the default tab width. |
| [SetDefaultTabStop](#setdefaulttabstop) | Sets the default tab stop, which is used when no tab exists beyond the current display position. |
| [New_](#new_) | Opens a new document. |
| [Open](#open) | Opens a specified document. There are parameters to specify access and sharing privileges, creation and conversion of the file, as well as the code page for the file. |
| [Save](#save) | Saves the document. |
| [Freeze](#freeze) | Increments the freeze count. |
| [Unfreeze](#unfreeze) | Decrements the freeze count. |
| [BeginEditCollection](#begineditcollection) | Turns on edit collection (also called *undo grouping*). |
| [EndEditCollection](#endeditcollection) | Turns off edit collection (also called *undo grouping*). |
| [Undo](#undo) | Performs a specified number of undo operations. |
| [Redo](#redo) | Performs a specified number of redo operations. |
| [Range](#range) | Retrieves a text range object for a specified range of content in the active story of the document. |
| [RangeFromPoint](#rangefrompoint) | Retrieves a range for the content at or nearest to the specified point on the screen. |

---

### ITextDocument2 Interface

Extends the **ITextDocument** interface, adding methods that enable the Input Method Editor (IME) to drive the rich edit control, and methods to retrieve other interfaces such as **ITextDisplays**, **ITextRange2**, **ITextFont2**, **ITextPara2**, and so on.

Some **ITextDocument2** methods used with the IME need access to the current window handle (HWND). Use the **GetWindow** method of the **ITextDocument2** interface to retrieve the handle.

| Name       | Description |
| ---------- | ----------- |
| [GetCaretType](#getcarettype) | Gets the caret type. |
| [SetCaretType](#setcarettype) | Sets the caret type. |
| [GetDisplays](#getdisplays) | Gets the displays collection for this Text Object Model (TOM) engine instance. |
| [GetDocumentFont](#getdocumentfont) | Gets an object that provides the default character format information for this instance of the Text Object Model (TOM) engine. |
| [SetDocumentFont](#setdocumentfont) | Sets the default paragraph formatting for this instance of the Text Object Model (TOM) engine. |
| [GetDocumentPara](#getdocumentpara) | Gets an object that provides the default paragraph format information for this instance of the Text Object Model (TOM) engine. |
| [SetDocumentPara](#setdocumentpara) | Sets the default paragraph formatting for this instance of the Text Object Model (TOM) engine. |
| [GetEastAsianFlags](#geteastasianflags) | Gets the East Asian flags. |
| [GetGenerator](#getgenerator) | Gets the name of the Text Object Model (TOM) engine. |
| [SetIMEInProgress](#setimeinprogress) | Sets the state of the Input Method Editor (IME) in-progress flag. |
| [GetNotificationMode](#getnotificationmode) | Gets the notification mode. |
| [SetNotificationMode](#setnotificationmode) | Sets the notification mode. Use **tomTrue** to turn on notifications, or **tomFalse** to turn them off. |
| [GetSelection2](#getselection2) | Gets the active selection. |
| [GetStoryRanges2](#getstoryranges2) | Gets an object for enumerating the stories in a document. |
| [GetTypographyOptions](#gettypographyoptions) | Gets the typography options. |
| [GetVersion](#getversion) | Gets the version number of the Text Object Model (TOM) engine. |
| [GetWindow](#getwindow) | Gets the handle of the window that the Text Object Model (TOM) engine is using to display output. |
| [AttachMsgFilter](#attachmsgfilter) | Attaches a new message filter to the edit instance. All window messages that the edit instance receives are forwarded to the message filter. |
| [CheckTextLimit](#checktextlimit) | Checks whether the number of characters to be added would exceed the maximum text limit. |
| [GetCallManager](#getcallmanager) | Gets the call manager. |
| [GetClientRect](#getclientrect) | Retrieves the client rectangle of the rich edit control. |
| [GetEffectColor](#geteffectcolor) | Retrieves the color used for special text attributes. |
| [GetImmContext](#getimmcontext) | Gets the Input Method Manager (IMM) input context from the Text Object Model (TOM) host. |
| [GetPreferredFont](#getpreferredfont) | Retrieves the preferred font for a particular character repertoire and character position. |
| [GetProperty](#getproperty) | Retrieves the value of a property. |
| [GetStrings](#getstrings) | Gets a collection of rich-text strings. |
| [Notify](#notify) | Notifies the Text Object Model (TOM) engine client of particular Input Method Editor (IME) events. |
| [Range2](#range2) | Retrieves a new text range for the active story of the document. |
| [RangeFromPoint2](#rangefrompoint2) | Retrieves the degenerate range at (or nearest to) a particular point on the screen. |
| [ReleaseCallManager](#releasecallmanager) | Releases the call manager. |
| [ReleaseImmContext](#releaseimmcontext) | Releases an Input Method Manager (IMM) input context. |
| [SetEffectColor](#seteffectcolor) | Specifies the color to use for special text attributes. |
| [SetProperty](#setproperty) | Specifies a new value for a property. |
| [SetTypographyOptions](#settypographyoptions) | Specifies the typography options for the document. |
| [SysBeep](#sysbeep) | Generates a system beep. |
| [Update](#update) | Updates the selection and caret. |
| [UpdateWindow](#updatewindow) | Notifies the client that the view has changed and the client should update the view if the Text Object Model (TOM) engine is in-place active. |
| [GetMathProperties](#getmathproperties) | Gets the math properties for the document. |
| [SetMathProperties](#setmathproperties) | Specifies the math properties to use for the document. |
| [GetActiveStory](#getactivestory) | Gets the active story; that is, the story that receives keyboard and mouse input. |
| [SetActiveStory](#setactivestory) | Sets the active story; that is, the story that receives keyboard and mouse input. |
| [GetMainStory](#getmainstory) | Gets the main story. |
| [GetNewStory](#getnewstory) | Gets a new story. Not implemented. |
| [GetStory](#getstory) | Retrieves the story that corresponds to a particular index. |

---

### Methods inherited from CTextObjectBase Class

| Name       | Description |
| ---------- | ----------- |
| [GetLastResult](#getlastresult) | Returns the last result code |
| [SetResult](#setresult) | Sets the last result code. |
| [GetErrorInfo](#geterrorinfo) | Returns a description of the last result code. |

---

## CONSTRUCTORS

Called when a `CTextDocument2` class variable is created.

```
DECLARE CONSTRUCTOR
DECLARE CONSTRUCTOR (BYVAL hRichEdit AS HWND)
DECLARE CONSTRUCTOR (BYVAL pTextDocument2 AS ITextDocument2 PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

## CONSTRUCTOR (Empty)

Can be used, for example, when we have an **ITextDocument2** interface pointer returned by a function and we want to attach it to a new instance of the **CTextDocument2** class.

```
DIM pCTextDocument2 AS CTextDocument2
pCTextDocument2.Attach(pTextDocument2)
```
## CONSTRUCTOR (hRichEdit)

| Parameter | Description |
| --------- | ----------- |
| *hRichEdit* | Handle of the Rich Edit control. |

```
CONSTRUCTOR CTextDocument2 (BYVAL hRichEdit AS HWND)
```

## CONSTRUCTOR (ITextDocument2 PTR)

```
CONSTRUCTOR CTextDocument2 (BYVAL pTextDocument2 AS ITextDocument2 PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *pTextDocument2* | An **ITextDocument2** interface pointer. |
| *fAddRef* | Optional. TRUE to increment the reference count of the passed **ITextDocument2** interface pointer; otherwise, FALSE. Default is FALSE. |

#### Return value

A pointer to the new instance of the class.

#### Usage examples

To use with the dotted syntax.

```
SCOPE
   ' // Create a new instance of the CTextDocument2 class
   DIM pTextDocument2 AS CTextDocument2 = hRichEdit
   ' // Get the number of characters of the text in the Rich Edit control
   DIM numChars AS LONG = RichEdit_GetTextLength(hRichEdit)
   ' // Get the 0-based range of all the text
   DIM pCRange2 AS CTextRange2 = pCTextDoc.Range2(0, numChars)
   ' // Get the text
   DIM dwsText AS DWSTRING = pCRange2.GetText2(0)
   ' // The CTextDocument2 class and the CTextRange2 class will be destroyed when the scope ends
END SCOPE
```

To use with the pointer syntax.

```
' // Create a new instance of the CTextDocument2 class
DIM pCTextDocument2 AS CTextDocument2 PTR = NEW CTextDocument2(hRichEdit)
' // Get the number of characters of the text in the Rich Edit control
DIM numChars AS LONG = RichEdit_GetTextLength(hRichEdit)
' // Get the 0-based range of all the text
DIM pCRange2 AS CTextRange2 = pCTextDoc->Range2(0, numChars)
' // Get the text
DIM dwsText AS DWSTRING = pCRange2->GetText2(0)
' // Delete the range
Delete pCRange2
' // Delete the class
Delete pCTextDocument2
```

## DESTRUCTOR

Called automatically when a class variable goes out of scope or is destroyed.

```
DESTRUCTOR CTextDocument2
```
---

## LET

Assignment operator.  The assigned pointer must be an "addrefed" one.

```
OPERATOR LET (BYVAL pTextDocument2 AS ITextDocument2 PTR)
```
---

## CAST

Cast operator.

```
OPERATOR CAST () AS ITextDocument2 PTR
```
---

## TextDocumentPtr

Returns a pointer to the underlying **ITextDocument2** interface

```
FUNCTION TextDocumentPtr () AS ITextDocument2 PTR
```
---

## Attach

Attaches an **ITextDocument2** interface pointer to the class.

```
FUNCTION Attach (BYVAL pTextDocument2 AS ITextDocument2 PTR, _
   BYVAL fAddRef AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pTextDocument2* | The **ITextDocument2** interface pointer to attach. |
| *fAddRef* | **TRUE** to increment the reference count of the object. Default is FALSE. |

---

## Detach

Detaches the underlying **ITextDocument2** interface pointer from the class

```
FUNCTION Detach () AS ITextDocument2 PTR
```
---

## GetLastResult

Returns the last result code

```
FUNCTION GetLastResult () AS HRESULT
```
---

## SetResult

Sets the last result code.

```
FUNCTION SetResult (BYVAL Result AS HRESULT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Result* | The **HRESULT** error code returned by the methods. |

---

## GetErrorInfo

Returns a description of the last result code.

```
PRIVATE FUNCTION GetErrorInfo (BYVAL nError AS LONG = -1) AS DWSTRING
```
---

## GetName

Gets the file name of this document. This is the **ITextDocument** default property.

```
FUNCTION GetName () AS DWSTRING
```
#### Return value

The filename of this document, or an empty string if there is not a filename associated with this object.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **S_FALSE** | No file name associated with this object. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory for output string. |

---

## GetSelection

Gets the active selection.

```
FUNCTION GetSelection () AS ITextSelection PTR
```
#### Return value

The **ITextSelection** pointer of the active selection.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **S_FALSE** | Indicates no active selection. |
| **E_INVALIDARG** | Invalid argument. |

---

## GetStoryCount

Gets the count of stories in this document.

```
FUNCTION GetStoryCount () AS LONG
```
#### Return value

The number of stories in the document.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |

---

## GetStoryRanges

Gets the story collection object used to enumerate the stories in a document.

```
FUNCTION GetStoryRanges () AS ITextStoryRanges PTR
```
#### Return value

A pointer to the **ITextStoryRanges** interface.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_NOTIMPL** | Not implemented; only one story in this document. |

#### Remarks

Invoke this method only if **GetStoryCount** returns a value greater than 1.

---

## GetSaved

Gets a value that indicates whether changes have been made since the file was last saved.

```
FUNCTION GetSaved () AS LONG
```
#### Return value

The value **tomTrue** if no changes have been made since the file was last saved, or the value tomFalse if there are unsaved changes.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |

---

## SetSaved

Sets the document **Saved** property.

```
FUNCTION SetSaved (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | New value of the **Saved** property. It can be one of the following values:<br>**tomTrue**. No changes to the file since the last time it was saved.<br>**tomFalse**. There are changes to the file. |

#### Return value

The return value is **S_OK**.

---

## GetDefaultTabStop

Gets the default tab width.

```
FUNCTION GetDefaultTabStop () AS SINGLE
```

#### Return value

The default tab width.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |

---

## SetDefaultTabStop

Sets the default tab stop, which is used when no tab exists beyond the current display position.

```
FUNCTION SetDefaultTabStop (BYVAL Value AS SINGLE = 36.0) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | New default tab setting, in floating-point points. Default value is 36.0 points, that is, 0.5 inches. |

If the method succeeds it returns S_OK. If the method fails, it returns one of the following COM error codes. For more information on COM error codes, see Error Handling in COM.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

---

## New_

Opens a new document.

```
FUNCTION New_ () AS HRESULT
```

#### Return value

If the method succeeds, it returns S_OK.

#### Remarks

If another document is open, this method saves any current changes and closes the current document before opening a new one.

---

## Open

Opens a specified document. There are parameters to specify access and sharing privileges, creation and conversion of the file, as well as the code page for the file.

```
FUNCTION Open (BYVAL pVar AS VARIANT PTR, BYVAL Flags AS LONG = 0, BYVAL CodePage AS LONG = 0) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pVar* | A **VARIANT** that specifies the name of the file to open. |
| *Flags* | **tomRTF**: Open as RTF. **tomText**: Open as text ANSI or Unicode. |
| *CodePage* | The code page to use for the file. Zero (the default value) means **CP_ACP** (ANSI code page) unless the file begins with a Unicode BOM 0xfeff, in which case the file is considered to be Unicode. Note that code page 1200 is Unicode, **CP_UTF8** is UTF-8. |

#### Return value

The return value can be an **HRESULT** value that corresponds to a system error or COM error code, including one of the following values.

| Result code | Description |
| ----------- | ----------- |
| **S_OK** | Method succeeds. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_NOTIMPL** | Feature not implemented. |

---

## Save

Saves the document.

```
FUNCTION Save (BYVAL pVar AS VARIANT PTR, BYVAL Flags AS LONG, BYVAL CodePage AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pVar* | The save target. This parameter is a **VARIANT**, which can be a file name, or **NULL**. |
| *Flags* | File creation, open, share, and conversion flags. For a list of possible values, see **Open**. |
| *CodePage* | The specified code page. Common values are **CP_ACP** (zero: system ANSI code page), 1200 (Unicode), and 1208 (UTF-8). |

#### Return value

The return value can be an **HRESULT** value that corresponds to a system error or COM error code, including one of the following values.

| Result code | Description |
| ----------- | ----------- |
| **S_OK** | Method succeeds. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_NOTIMPL** | Feature not implemented. |

#### Remarks

To use the parameters that were specified for opening the file, use zero values for the parameters.

If *pVar* is null or missing, the file name given by this document's name is used. If both of these are missing or null, the method fails.

If *pVar* specifies a file name, that name should replace the current Name property. Similarly, the *Flags* and *CodePage* arguments can overrule those supplied in the **Open** method and define the values to use for files created with the **New_** method.

Unicode plain-text files should be saved with the Unicode byte-order mark (0xFEFF) as the first character. This character should be removed when the file is read in; that is, it is only used for import/export to identify the plain text as Unicode and to identify the byte order of that text. Microsoft Notepad adopted this convention, which is now recommended by the Unicode standard.

---

## Freeze

Increments the freeze count.

```
FUNCTION Freeze () AS LONG
```

#### Return value

The updated freeze count.

#### Result code

If the count is nonzero, **GetLastResult** returns **S_OK**. If the count is zero, it returns **FALSE**.

#### Remarks

If the freeze count is nonzero, screen updating is disabled. This allows a sequence of editing operations to be performed without the performance loss and flicker of screen updating. To decrement the freeze count, call the **Unfreeze** method.

---

## Unfreeze

Decrements the freeze count.

```
FUNCTION Unfreeze () AS LONG
```

#### Return value

The updated freeze count.

#### Result code

If the freeze count is zero, **GetLastResult** returns **S_OK**. If the method fails, it returns **S_FALSE**, indicating that the freeze count is nonzero.

#### Remarks

If the freeze count goes to zero, screen updating is enabled. This method cannot decrement the count below zero, and no error occurs if it is executed with a zero freeze count.

Note, if edit collection is active, screen updating is suppressed, even if the freeze count is zero.

---

## BeginEditCollection

Turns on edit collection (also called *undo grouping*).

```
FUNCTION BeginEditCollection () AS HRESULT
```

#### Return value

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Return code | Description |
| ----------- | ----------- |
| **S_OK** | Method succeeds. |
| **S_FALSE** | Undo is not enabled. |
| **E_NOTIMPL** | Feature not implemented. |

#### Remarks

A single **Undo** command undoes all changes made while edit collection is turned on.

---

## EndEditCollection

Turns off edit collection (also called *undo grouping*).

```
FUNCTION EndEditCollection () AS HRESULT
```

#### Return value

If the method succeeds, it returns **S_OK**. If the method fails, it returns a COM error code.

| Return value | Description |
| ------------ | ----------- |
| **S_OK** | Method succeeds. |
| **E_NOTIMPL** | Feature not implemented. |

#### Remarks

The screen is unfrozen unless the freeze count is nonzero.

---

## Undo

Performs a specified number of undo operations.

```
FUNCTION Undo (BYVAL Count AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *Count* | The specified number of undo operations. If the value of this parameter is **tomFalse**, undo processing is suspended. If this parameter is **tomTrue**, undo processing is restored. |

#### Return value

The actual count of undo operations performed.

#### Result code

If all of the *Count* undo operations were performed, **GetLastResult** returns **S_OK**. If the method fails, it returns **S_FALSE**, indicating that less than *Count* undo operations were performed.

---

## Redo

Performs a specified number of redo operations.

```
FUNCTION Redo (BYVAL Count AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *Count* | The number of redo operations specified. |

#### Return value

The actual count of redo operations performed.

#### Result code

If the method succeeds **GetLastResult** returns **S_OK**. If the method fails, it returns the following COM error code.

| Result code | Description |
| ----------- | ----------- |
| **S_OK** | Method succeeds. |
| **S_FALSE** | Less than Count redo operations were performed. |

---

## Range

Retrieves a text range object for a specified range of content in the active story of the document.

```
FUNCTION Range (BYVAL cpActive AS LONG = 0, BYVAL cpAnchor AS LONG = 0) AS ITextRange PTR
```

| Parameter | Description |
| --------- | ----------- |
| *cpActive* | The start position of new range. The default value is zero, which represents the start of the document. |
| *cpAnchor* | The end position of new range. The default value is zero. |

### Return value

Pointer to a **ITextRange** interface to the specified text range.

---

## RangeFromPoint

Retrieves a range for the content at or nearest to the specified point on the screen.

```
FUNCTION RangeFromPoint (BYVAL x AS LONG, BYVAL y AS LONG) AS ITextRange PTR
```

| Parameter | Description |
| --------- | ----------- |
| *x* | The horizontal coordinate of the specified point, in screen coordinates. |
| *y* | The vertical coordinate of the specified point, in screen coordinates. |

### Return value

Pointer to a **ITextRange** interface that corresponds to the specified point.

#### Result code

If the method succeeds **GetLastResult** returns **S_OK**. If the method fails, it returns the following COM error code.

| Result code | Description |
| ----------- | ----------- |
| **S_OK** | Method succeeds. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

---

## GetCaretType

Gets the caret type.

```
FUNCTION GetCaretType () AS LONG
```

### Return value

The caret type. It can be one of the following values:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **tomKoreanBlockCaret** | &h1 | The Korean block caret. |
| **tomNormalCaret** | 0 | Normal caret. |
| **tomNullCaret** | &h2 | NULL caret (caret suppressed) |

#### Result code

If the method succeeds **GetLastResult** returns **S_OK**. If the method fails, it returns an **HRESULT** error code.

---

## SetCaretType

Sets the caret type.

```
FUNCTION SetCaretType (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The new caret type. It can be one of the following values: |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **tomKoreanBlockCaret** | &h1 | The Korean block caret. |
| **tomNormalCaret** | 0 | Normal caret. |
| **tomNullCaret** | &h2 | NULL caret (caret suppressed) |

#### Result code

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetDisplays

Gets the displays collection for this Text Object Model (TOM) engine instance.

```
FUNCTION GetDisplays () AS ITextDisplays PTR
```

### Return value

A pointer to the **ITextDisplays** interface.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The rich edit control doesn't implement this method.

---

## GetDocumentFont

Gets an object that provides the default character format information for this instance of the Text Object Model (TOM) engine.

```
FUNCTION GetDocumentFont () AS ITextFont2 PTR
```

### Return value

A pointer to the **ITextFont2** interface.

### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetDocumentFont

Sets the default character formatting for this instance of the Text Object Model (TOM) engine.

```
FUNCTION SetDocumentFont (BYVAL pFont AS ITextFont2 PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pFont* | The font object that provides the default character formatting. |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

You can also set the default character formatting by calling the **Reset** method of the **ITextFont** interface with a value of **tomDefault**.

---

## GetDocumentPara

Gets an object that provides the default paragraph format information for this instance of the Text Object Model (TOM) engine.

```
FUNCTION GetDocumentPara () AS ITextPara2 PTR
```

#### Return value

A pointer to the **ITextPara2** interface.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetDocumentPara

Sets the default paragraph formatting for this instance of the Text Object Model (TOM) engine.

```
FUNCTION SetDocumentPara (BYVAL pPara AS ITextPara2 PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pPara* | The paragraph object that provides the default paragraph formatting. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

You can also set the default character formatting by calling the **Reset** method of the **ITextFont** interface with a value of **tomDefault**.

---

## GetEastAsianFlags

Gets an object that provides the default paragraph format information for this instance of the Text Object Model (TOM) engine.

```
FUNCTION GetEastAsianFlags () AS LONG
```

#### Return value

The East Asian flags. This parameter can be a combination of the following values.

| Value | Meaning |
| ----- | ------- |
| *tomRE10Mode* | TOM version 1.0 emulation mode. |
| *tomUseAtFont* | Use @ fonts for CJK vertical text. |
| *tomTextFlowMask* | A mask for the following four text orientations. |
| *tomTextFlowES* | Ordinary left-to-right horizontal text. |
| *tomTextFlowSW* | Ordinary East Asian vertical text. |
| *tomTextFlowWN* | An alternative orientation. |
| *tomTextFlowNE* | An alternative orientation. |
| *tomUsePassword* | Use password control. |
| *tomNoIME* | Turn off IME operation (see **ES_NOIME**). |
| *tomSelfIME* | The rich edit host handles IME operation (see **ES_SELFIME**) . |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetGenerator

Gets the name of the Text Object Model (TOM) engine.

```
FUNCTION GetGenerator () AS DWSTRING
```

#### Return value

The name of the TOM engine.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetIMEInProgress

Sets the state of the Input Method Editor (IME) in-progress flag.

```
FUNCTION SetIMEInProgress (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | Use **tomTrue** to turn on the IME in-progress flag, or **tomFalse** to turn it off. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetNotificationMode

Gets the notification mode.

```
FUNCTION GetNotificationMode () AS LONG
```

#### Return value

The notification mode. This parameter is set to **tomTrue** if notifications are active, or **tomFalse** if not.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetNotificationMode

Sets the notification mode.

```
FUNCTION SetNotificationMode (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The notification mode. Use **tomTrue** to turn on notifications, or **tomFalse** to turn them off. |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetSelection2

Gets the active selection.

```
FUNCTION GetSelection2 () AS ITextSelection2 PTR
```

#### Return value

A pointer to the **ITextSelection2** interface of the selection. This pointer is **NULL** if the rich edit control is not in-place active.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetStoryRanges2

Gets an object for enumerating the stories in a document.

```
FUNCTION GetStoryRanges2 () AS ITextStoryRanges2 PTR
```

#### Return value

A pointer to the **ITextStoryRanges2** interface used for enumerating stories.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

Call this method only if the **GetStoryCount** method returns a value that is greater than one.

---

## GetTypographyOptions

Gets the typography options.

```
FUNCTION GetTypographyOptions () AS LONG
```

#### Return value

A combination of the following typography options.

| Value | Meaning |
| ----- | ------- |
| **TO_ADVANCEDTYPOGRAPHY** | Advanced typography (special line breaking and line formatting) is turned on. |
| **TO_SIMPLELINEBREAK** | Normal line breaking and formatting is used. |

#### Return value

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetVersion

Gets the version number of the Text Object Model (TOM) engine.

```
FUNCTION GetVersion () AS LONG
```

#### Return value

The version number. Byte 3 gives the major version number, byte 2 the minor version number, and the low-order 16 bits give the build number.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetWindow

Gets the handle of the window that the Text Object Model (TOM) engine is using to display output.

```
FUNCTION GetWindow () AS __int64
```

#### Return value

The handle of the window that the TOM engine is using.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

A rich edit control doesn't need to own the window that the TOM engine is using. For example, the rich edit control might be windowless.

The Input Method Editor (IME) needs the handle of the window that is receiving keyboard messages. This method retrieves that handle.

---

## AttachMsgFilter

Attaches a new message filter to the edit instance. All window messages that the edit instance receives are forwarded to the message filter.

```
FUNCTION AttachMsgFilter (BYVAL pFilter AS IUnknown PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pFilter* | The message filter. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The message filter must be bound to the document before it can be used.

---

## CheckTextLimit

Checks whether the number of characters to be added would exceed the maximum text limit.

```
FUNCTION CheckTextLimit (BYVAL cch AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *cch* | The number of characters to be added. |

#### Return value

The number of characters that exceed the maximum text limit. This parameter is 0 if the number of characters does not exceed the limit.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCallManager

Gets the call manager.

```
FUNCTION GetCallManager () AS IUnknown PTR
```

#### Return value

The call manager object.

#### Result code

If the method succeeds,**GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The call manager object is opaque to the caller. The Text Object Model (TOM) engine uses the object to handle internal notifications for particular scenarios.

---

## GetClientRect

Retrieves the client rectangle of the rich edit control.

```
FUNCTION GetClientRect (BYVAL nType AS LONG, BYVAL pLeft AS LONG PTR, _
   BYVAL pTop AS LONG PTR, BYVAL pRight AS LONG PTR, BYVAL pBottom AS LONG PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *nType* | The client rectangle retrieval options. It can be a combination of the following values.<br>**tomClientCoord**. Retrieve the rectangle in client coordinates. If this value isn't specified, the function retrieves screen coordinates.<br>**tomIncludeInset**. Add left and top insets to the left and top coordinates of the client rectangle, and subtract right and bottom insets from the right and bottom coordinates.<br>**tomTransform**. Use a world transform (XFORM) provided by the host application to transform the retrieved rectangle coordinates. |
| *pLeft* | The x-coordinate of the upper-left corner of the rectangle. |
| *pTop* | The y-coordinate of the upper-left corner of the rectangle. |
| *pRight* | The x-coordinate of the lower-right corner of the rectangle. |
| *pBottom* | The y-coordinate of the lower-right corner of the rectangle. |

#### Return value

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetEffectColor

Retrieves the color used for special text attributes.

```
FUNCTION GetEffectColor (BYVAL Index AS LONG) AS ULONG
```

| Parameter | Description |
| --------- | ----------- |
| *Index* | The index of the color to retrieve. It can be one of the following values. |

| Index | Meaning |
| --------- | ----------- |
| 0 | Text color. |
| 1 | RGB(0, 0, 0) |
| 2 | RGB(0, 0, 255) |
| 3 | RGB(0, 255, 255) |
| 4 | RGB(0, 255, 0) |
| 5 | RGB(255, 0, 255) |
| 6 | RGB(255, 0, 0) |
| 7 | RGB(255, 255, 0) |
| 8 | RGB(255, 255, 255) |
| 9 | RGB(0, 0, 128) |
| 10 | RGB(0, 128, 128) |
| 11 | RGB(0, 128, 0) |
| 12 | RGB(128, 0, 128) |
| 13 | RGB(128, 0, 0) |
| 14 | RGB(128, 128, 0) |
| 15 | RGB(128, 128, 128) |
| 16 | RGB(192, 192, 192) |

#### Return value

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

### Remarks

The first 16 index values are for special underline colors. If an index between 1 and 16 hasn't been defined by a call to the **GetEffectColor** method, **GetEffectColor** returns the corresponding Microsoft Word default color.

---

## GetPreferredFont

Retrieves the preferred font for a particular character repertoire and character position.

```
FUNCTION GetPreferredFont (BYVAL cp AS LONG, BYVAL CodePage AS LONG, _
   BYVAL Options AS LONG, BYVAL curCodepage AS LONG, BYVAL curFontSize AS LONG, BYREF dwsFontName AS DWSTRING, _
   BYVAL pPitchAndFamily AS LONG PTR, BYVAL pNewFontSize AS LONG PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *cp* | The character position for the preferred font. |
| *CharRep* | The character repertoire index for the preferred font. It can be one of the following values: **tomAboriginal**, **tomAnsi**, **tomArabic**, **tomArmenian**, **tomBaltic**, **tomBengali**, **tomBIG5**, **tomBraille**, **tomCherokee**, **tomCyrillic**, **tomDefaultCharRep**, **tomDevanagari**, **tomEastEurope**, **tomEmoji**, **tomEthiopic**, **tomGB2312**, **tomGeorgian**, **tomGreek**, **tomGujarati**, **tomGurmukhi**, **tomHangul**, **tomHebrew**, **tomJamo**, **tomKannada**, **tomKayahli**, **tomKharoshthi**, **tomKhmer**, **tomLao**, **tomLimbu**, **tomMac**, **tomMalayalam**, **tomMongolian**, **tomMyanmar**, **tomNewTaiLu**, **tomOEM**, **tomOgham**, **tomOriya**, **tomPC437**, **tomRunic**, **tomShiftJIS**, **tomSinhala**, **tomSylotinagr**, **tomSymbol**, **tomSyriac**, **tomTaiLe**, **tomTamil**, **tomTelugu**, **tomThaana**, **tomThai**, **tomTibetan**, **tomTurkish**, **tomUsymbol**, **tomVietnamese**, **tomYi**. |
| *Options* | The preferred font options. The low-order word can be a combination of the following values.<br>**tomIgnoreCurrentFont**, **tomMatchCharRep**, **tomMatchFontSignature**, **tomMatchAscii**, **tomGetHeightOnly**, **tomMatchMathFont**. If the high-order word of Options is tomUseTwips, the font heights are given in twips. |
| *curCharRep* | The index of the current character repertoire. |
| *curFontSize* | The current font size. |
| *dwsFontName* | [OUT] The font name. |
| *pPitchAndFamily* | [OUT] The font pitch and family. |
| *pNewFontSize* | [OUT] The new font size. |

#### Return value

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetImmContext

Gets the Input Method Manager (IMM) input context from the Text Object Model (TOM) host.

```
FUNCTION GetImmContext () AS __int64
```

#### Return value

The IMM input context.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetProperty

Retrieves the value of a property.

```
FUNCTION GetProperty (BYVAL nType AS LONG) AS LONG
```
| Parameter | Description |
| --------- | ----------- |
| *nType* | The identifier of the property to retrieve. It can be one of the following property IDs: **tomCanCopy**, **tomCanRedo**, **tomCanUndo**, **tomDocMathBuild**, **tomMathInterSpace**, **tomMathIntraSpace**, **tomMathLMargin**, **tomMathPostSpace**, **tomMathPreSpace**, **tomMathRMargin**, **tomMathWrapIndent**, **tomMathWrapRight**, **tomUndoLimit**, **tomEllipsisMode**, **tomEllipsisState** |

#### Return value

The value of the property.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetStrings

Gets a collection of rich-text strings.

```
FUNCTION GetStrings () AS ITextStrings PTR
```

#### Return value

A pointer to the **ITextStrings** interface of the collection of rich-text strings.

---

## Notify

Notifies the Text Object Model (TOM) engine client of particular Input Method Editor (IME) events.

```
FUNCTION Notify (BYVAL nNotify AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *nNotify* | An IME notification code. |

#### Rerturn value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## Range2

Retrieves a new text range for the active story of the document.

```
FUNCTION Range2 (BYVAL cpActive AS LONG = 0, BYVAL cpAnchor AS LONG = 0) AS ITextRange2 PTR
```

| Parameter | Description |
| --------- | ----------- |
| *cpActive* | The active end of the new text range. The default value is 0; that is, the beginning of the story. |
| *cpAnchor* | The anchor end of the new text range. The default value is 0. |

#### Return value

The new text range.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## RangeFromPoint2

Retrieves the degenerate range at (or nearest to) a particular point on the screen.

```
FUNCTION RangeFromPoint2 (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nType AS LONG) AS ITextRange2 PTR
```

| Parameter | Description |
| --------- | ----------- |
| *x* | The x-coordinate of a point, in screen coordinates. |
| *y* | The y-coordinate of a point, in screen coordinates. |
| *nType* | The alignment type of the specified point. For a list of valid values, see the [GetPoint](https://learn.microsoft.com/en-us/windows/win32/api/tom/nf-tom-itextrange-getpoint) method of the **ITextRange** interface. |

#### Result code

If the method succeeds, **GetLastResult^^ returns **NOERROR**. Otherwise, it returns an **HRESUL** error code.

---

## ReleaseCallManager

Releases the call manager.

```
FUNCTION ReleaseCallManager (BYVAL pVoid AS IUnknown PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pvoid* | The call manager object to release. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## ReleaseImmContext

Releases an Input Method Manager (IMM) input context.

```
FUNCTION ReleaseImmContext (BYVAL Context AS __int64) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Context* | The IMM input context to release. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetEffectColor

Specifies the color to use for special text attributes.

```
FUNCTION SetEffectColor (BYVAL Index AS LONG, BYVAL Value AS ULONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Index* | The index of the color to retrieve. For a list of values, see the table below. |
| *Value* | The new color for the specified index. |

| Index | Meaning |
| --------- | ----------- |
| 0 | Text color. |
| 1 | RGB(0, 0, 0) |
| 2 | RGB(0, 0, 255) |
| 3 | RGB(0, 255, 255) |
| 4 | RGB(0, 255, 0) |
| 5 | RGB(255, 0, 255) |
| 6 | RGB(255, 0, 0) |
| 7 | RGB(255, 255, 0) |
| 8 | RGB(255, 255, 255) |
| 9 | RGB(0, 0, 128) |
| 10 | RGB(0, 128, 128) |
| 11 | RGB(0, 128, 0) |
| 12 | RGB(128, 0, 128) |
| 13 | RGB(128, 0, 0) |
| 14 | RGB(128, 128, 0) |
| 15 | RGB(128, 128, 128) |
| 16 | RGB(192, 192, 192) |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The first 16 index values are for special underline colors. If an index between 1 and 16 hasn't been defined by a call to the **SetEffectColor** method of the **ITextDocument2** interface, the corresponding Microsoft Word default color is used.

---

## SetProperty

Specifies a new value for a property.

```
FUNCTION SetProperty (BYVAL nType AS LONG, BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *nType* | The identifier of the property. It can be one of the following property IDs: **tomCanCopy**, **tomCanRedo**, **tomCanUndo**, **tomDocMathBuild**, **tomMathInterSpace**, **tomMathIntraSpace**, **tomMathLMargin**, **tomMathPostSpace**, **tomMathPreSpace**, **tomMathRMargin**, **tomMathWrapIndent**, **tomMathWrapRight**, **tomUndoLimit**, **tomEllipsisMode**, **tomEllipsisState**. |
| *Value* | The new property value. |

#### Return value

If the method succeeds, it returns *NOERRO*. Otherwise, it returns an *HRESULT* error code.

---

## SetTypographyOptions

Specifies the typography options for the document.

```
FUNCTION SetTypographyOptions (BYVAL Options AS LONG, BYVAL Mask AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Options* | The typography options to set. For a list of possible options, see the table below. |
| *Mask* | A mask identifying the options to set. For example, to turn on **TO_ADVANCEDTYPOGRAPHY**, call *SetTypographyOptions (TO_ADVANCEDTYPOGRAPHY, TO_ADVANCEDTYPOGRAPHY)*. |

Typography options.

| Value | Meaning |
| ----- | ------- |
| **TO_ADVANCEDTYPOGRAPHY** | Advanced typography (special line breaking and line formatting) is turned on. |
| **TO_SIMPLELINEBREAK** | Normal line breaking and formatting is used. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SysBeep

Generates a system beep.

```
FUNCTION SysBeep () AS HRESULT
```

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## Update

Updates the selection and caret.

```
FUNCTION Update (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | Scroll flag. Use tomTrue to scroll the caret into view. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## UpdateWindow

Notifies the client that the view has changed and the client should update the view if the Text Object Model (TOM) engine is in-place active.

```
FUNCTION UpdateWindow () AS HRESULT
```

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetMathProperties

Gets the math properties for the document.

```
FUNCTION GetMathProperties () AS LONG
```

#### Return value

A combination of the following math properties:

| Property | Meaning |
| -------- | ----------- |
| *tomMathDispAlignMask* | Display-mode alignment mask. |
| *tomMathDispAlignCenter* | Center (default) alignment. |
| *tomMathDispAlignLeft* | Left alignment. |
| *tomMathDispAlignRight* | Right alignment. |
| *tomMathDispIntUnderOver* | Display-mode integral limits location. |
| *tomMathDispFracTeX* | Display-mode nested fraction script size. |
| *tomMathDispNaryGrow* | Math-paragraph n-ary grow. |
| *tomMathDocEmptyArgMask* | Empty arguments display mask. |
| *tomMathDocEmptyArgAuto* | Automatically use a dotted square to denote empty arguments, if necessary. |
| *tomMathDocEmptyArgAlways* | Always use a dotted square to denote empty arguments. |
| *tomMathDocEmptyArgNever* | Don't denote empty arguments. |
| *tomMathDocSbSpOpUnchanged* | Display the underscore (_) and caret (^) as themselves. |
| *tomMathDocDiffMask* | Style mask for the **tomMathDocDiffUpright**, **tomMathDocDiffItalic**, **tomMathDocDiffOpenItalic** options. |
| *tomMathDocDiffItalic* | Use italic (default) for math differentials. |
| *tomMathDocDiffUpright* | Use an upright font for math differentials. |
| *tomMathDocDiffOpenItalic* | Use open italic (default) for math differentials. |
| *tomMathDispNarySubSup* | Math-paragraph non-integral n-ary limits location. |
| *tomMathDispDef* | Math-paragraph spacing defaults. |
| *tomMathEnableRtl* | Enable right-to-left (RTL) math zones in RTL paragraphs. |
| *tomMathBrkBinMask* | Equation line break mask. |
| *tomMathBrkBinBefore* | Break before binary/relational operator. |
| *tomMathBrkBinAfter* | Break after binary/relational operator. |
| *tomMathBrkBinDup* | Duplicate binary/relational before/after. |
| *tomMathBrkBinSubMask* | Duplicate mask for minus operator. |
| *tomMathBrkBinSubMM* | - - (minus on both lines). |
| *tomMathBrkBinSubPM* | + - |
| *tomMathBrkBinSubMP* | - + |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetMathProperties

Sets the math properties for the document.

```
FUNCTION SetMathProperties (BYVAL Options AS LONG, BYVAL Mask AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Options* | The math properties to set. For a list of possible properties, see the table below. |
| *Mask* | The math mask. For a list of possible masks, see the table below. |

| Property | Meaning |
| -------- | ----------- |
| *tomMathDispAlignMask* | Display-mode alignment mask. |
| *tomMathDispAlignCenter* | Center (default) alignment. |
| *tomMathDispAlignLeft* | Left alignment. |
| *tomMathDispAlignRight* | Right alignment. |
| *tomMathDispIntUnderOver* | Display-mode integral limits location. |
| *tomMathDispFracTeX* | Display-mode nested fraction script size. |
| *tomMathDispNaryGrow* | Math-paragraph n-ary grow. |
| *tomMathDocEmptyArgMask* | Empty arguments display mask. |
| *tomMathDocEmptyArgAuto* | Automatically use a dotted square to denote empty arguments, if necessary. |
| *tomMathDocEmptyArgAlways* | Always use a dotted square to denote empty arguments. |
| *tomMathDocEmptyArgNever* | Don't denote empty arguments. |
| *tomMathDocSbSpOpUnchanged* | Display the underscore (_) and caret (^) as themselves. |
| *tomMathDocDiffMask* | Style mask for the **tomMathDocDiffUpright**, **tomMathDocDiffItalic**, **tomMathDocDiffOpenItalic** options. |
| *tomMathDocDiffItalic* | Use italic (default) for math differentials. |
| *tomMathDocDiffUpright* | Use an upright font for math differentials. |
| *tomMathDocDiffOpenItalic* | Use open italic (default) for math differentials. |
| *tomMathDispNarySubSup* | Math-paragraph non-integral n-ary limits location. |
| *tomMathDispDef* | Math-paragraph spacing defaults. |
| *tomMathEnableRtl* | Enable right-to-left (RTL) math zones in RTL paragraphs. |
| *tomMathBrkBinMask* | Equation line break mask. |
| *tomMathBrkBinBefore* | Break before binary/relational operator. |
| *tomMathBrkBinAfter* | Break after binary/relational operator. |
| *tomMathBrkBinDup* | Duplicate binary/relational before/after. |
| *tomMathBrkBinSubMask* | Duplicate mask for minus operator. |
| *tomMathBrkBinSubMM* | - - (minus on both lines). |
| *tomMathBrkBinSubPM* | + - |
| *tomMathBrkBinSubMP* | - + |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetActiveStory

Gets the active story; that is, the story that receives keyboard and mouse input.

```
FUNCTION GetActiveStory () AS ITextStory PTR
```

#### Return value

A pointer to the **ITextStory** interface of the active story.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetActiveStory

Sets the active story; that is, the story that receives keyboard and mouse input.

```
FUNCTION SetActiveStory (BYVAL pStory AS ITextStory PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pStory* | The story to set as active. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetMainStory

Gets the main story.

```
FUNCTION GetMainStory () AS ITextStory PTR
```

#### Return value

A pointer to the **ITextStory** interface of the main story.

#### Result code

If this method succeeds, **GetLastResult** returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

A rich edit control automatically includes the main story; a call to the **GetNewStory** method is not required.

---

## GetNewStory

Gets a new story. Not implemented.

```
FUNCTION GetNewStory () AS ITextStory PTR
```

#### Return value

A pointer to the **ITextStory** interface of the new story.

#### Result code

If this method succeeds, **GetLastResult** returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

## GetStory

Retrieves the story that corresponds to a particular index.

```
FUNCTION GetStory (BYVAl Index AS LONG) AS ITextStory PTR
```

| Parameter | Description |
| --------- | ----------- |
| *Index* | The index of the story to retrieve. |

#### Return value

A pointer to the **ITextStory** interface of the requested story.

#### Result code

If this method succeeds, **GetLastResult** returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---
