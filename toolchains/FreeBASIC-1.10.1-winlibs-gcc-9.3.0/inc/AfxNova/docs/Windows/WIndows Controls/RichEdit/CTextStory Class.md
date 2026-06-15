# CTextStory Class

Class that wraps all the methods of the **ITextStory** interface.

| Name       | Description |
| ---------- | ----------- |
| [CONSTRUCTORS](#constructors) | Called when a class variable is created. |
| [DESTRUCTOR](#destructor) | Called automatically when a class variable goes out of scope or is destroyed. |
| [LET](#let) | Assignment operator. |
| [CAST](#cast) | Cast operator. |
| [TextStoryPtr](#textstoryptr) | Returns a pointer to the underlying **ITextStory** interface. |
| [Attach](#attach) | Attaches an **ITextStory** interface pointer to the class. |
| [Detach](#detach) | Detaches the underlying **ITextStory** interface pointer from the class. |

---

### ITextStory Interface

The **ITextStory** interface methods are used to access shared data from multiple stories, which is stored in the parent **ITextServices** instance.

The stories can be "edited" simultaneously by using individual **ITextRange2** methods, and displayed independently of one another. In addition, one story at a time can be UI active; that is, it receives keyboard and mouse input.

The **ITextStory** is a lightweight interface that does not require an **ITextRange2** object. This allows the client to manipulate a story, which is a faster, smaller object than a complete editing instance.

| Name       | Description |
| ---------- | ----------- |
| [GetActive](#getactive) | Gets the active state of a story. |
| [SetActive](#setactive) | Sets the active state of a story. |
| [GetDisplay](#getdisplay) | Gets a new display for a story. |
| [GetIndex](#getindex) | Gets the index of a story. |
| [GetType](#gettype) | Gets this story's type. |
| [SetType](#settype) | Sets this story's type. |
| [GetProperty](#getproperty) | Gets the value of the specified property. |
| [GetRange](#getrange) | Gets a text range object for the story. |
| [GetText](#gettext) | Gets the text in a story according to the specified conversion flags. |
| [SetFormattedText](#setformattedtext) | Replaces a story’s text with specified formatted text. |
| [SetProperty](#setproperty) | Sets the value of the specified property. |
| [SetText](#settext) | Sets the text in this range. |

---

### Methods inherited from CTextObjectBase Class

| Name       | Description |
| ---------- | ----------- |
| [GetLastResult](#getlastresult) | Returns the last result code |
| [SetResult](#setresult) | Sets the last result code. |
| [GetErrorInfo](#geterrorinfo) | Returns a description of the last result code. |

---

## CONSTRUCTORS

Called when a `CTextStory` class variable is created.

```
DECLARE CONSTRUCTOR
DECLARE CONSTRUCTOR (BYVAL pTextStory AS ITextStory PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

## CONSTRUCTOR (Empty)

Can be used, for example, when we have an **ITextStory** interface pointer returned by a function and we want to attach it to a new instance of the `CTextStory` class. To get a pointer to the **ITextStory** interface call the **GetStory** method of the **CRichEditCtx** class.

```
DIM pCTextStory AS CTextStory
pCTextStory.Attach(pTextStory)
```
## CONSTRUCTOR (ITextStory PTR)

```
CONSTRUCTOR CTextStory (BYVAL pTextStory AS ITextStory PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *pTextStory* | An **ITextStory** interface pointer. |
| *fAddRef* | Optional. **TRUE** to increment the reference count of the passed **ITextStory** interface pointer; otherwise, **FALSE**. Default is **FALSE**. |

#### Return value

A pointer to the new instance of the class.

---

## DESTRUCTOR

Called automatically when a class variable goes out of scope or is destroyed.

```
DESTRUCTOR CTextStory
```
---

## LET

Assignment operator. The assigned pointer must be an "addrefed" one.

```
OPERATOR LET (BYVAL pTextStory AS ITextStory PTR)
```
---

## CAST

Cast operator.

```
OPERATOR CAST () AS ITextStory PTR
```
---

## TextStoryPtr

Returns a pointer to the underlying **ITextStory** interface

```
FUNCTION TextRangePtr () AS ITextStory PTR
```
---

## Attach

Attaches an **ITextStory** interface pointer to the class.

```
FUNCTION Attach (BYVAL pTextStory AS ITextStory PTR, BYVAL fAddRef AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pTextStory* | The **ITextStory** interface pointer to attach. |
| *fAddRef* | **TRUE** to increment the reference count of the object; otherwise, **FALSE**. Default is **FALSE**. |

---

## Detach

Detaches the interface pointer from the class

```
FUNCTION Detach () AS ITextStory PTR
```
---

## GetLastResult

Returns the last result code

```
FUNCTION GetLastResult () AS HRESULT
```

# <a name="SetResult"></a>SetResult

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
FUNCTION GetErrorInfo () AS CWSTR
   IF SUCCEEDED(m_Result) THEN RETURN "Success"
   DIM s AS DWSTRING = "Error &h" & HEX(m_Result, 8)
   SELECT CASE m_Result
      CASE E_POINTER : s += ": E_POINTER - Null pointer"
      CASE S_OK : s += ": S_OK - Success"
      CASE S_FALSE : s += ": S_FALSE - Failure"
      CASE E_NOTIMPL : s += ": E_NOTIMPL - Not implemented."
      CASE E_INVALIDARG : s += ": E_INVALIDARG - Invalid argument"
      CASE E_OUTOFMEMORY : s += ": E_OUTOFMEMORY - Insufficient memory"
'      CASE E_FILENOTFOUND : s += "E_FILENOTFOUND - File not found"
      CASE &h80070002 : s += "E_FILENOTFOUND - File not found"
      CASE E_ACCESSDENIED : s += "E_ACCESSDENIED - Access denied"
      CASE E_FAIL : s += ": E_FAIL - Access denied"
      CASE NOERROR : s += ": NOERROR - Success" '' (same as S_OK)
      CASE CO_E_RELEASED:  : s += ": CO_E_RELEASED: - The object has been released"
      CASE ELSE
         s += "Unknown error"
   END SELECT
   RETURN s
END FUNCTION
```
---

## GetActive

Gets the active state of a story.

```
FUNCTION GetActive () AS LONG
```

#### Return value

The active state. It can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **tomDisplayActive** | The story has no UI or display (fast and lightweight). |
| **tomDisplayUIActive** | The story is UI active; that is, gets keyboard and mouse interactions. |
| **tomInactive** | The story has display, but no UI. |
| **tomUIActive** | The story has display and UI activity. |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetActive

Sets the active state of a story.

```
FUNCTION SetActive (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The active state. It can be one of the following values. |

| Value | Meaning |
| ----- | ------- |
| **tomDisplayActive** | The story has no UI or display (fast and lightweight). |
| **tomDisplayUIActive** | The story is UI active; that is, gets keyboard and mouse interactions. |
| **tomInactive** | The story has display, but no UI. |
| **tomUIActive** | The story has display and UI activity. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetDisplay

Gets a new display for a story.

```
FUNCTION GetDisplay () AS IUnknown PTR
```

#### Return value

The IUnknown interface for a display.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

A story can be displayed by calling **SetActive(tomDisplayActive)**. The **GetDisplay** method is included, in case it might be advantageous to have more than one display for a set of **ITextStory** interfaces.

---

## GetIndex

Gets the index of this story.

```
FUNCTION GetIndex () AS LONG
```

#### Return value

The index of the story.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The index is used with the **GetStory** method of the **ITextDocument2** interface.

---

## GetType

Gets this story's type.

```
FUNCTION GetType () AS LONG
```

#### Return value

This story's type. It can be any of the following values, or a custom client value from 100 to 65535.

| Type | Description |
| ---- | ----------- |
| **tomCommentsStory** | The story used for comments. |
| **tomEndnotesStory** | The story used for endnotes. |
| **tomEvenPagesFooterStory** | The story containing footers for even pages. |
| **tomEvenPagesHeaderStory** |The story containing headers for even pages.|
| **tomFindStory** | The story used for a Find dialog. |
| **tomFirstPageFooterStory** | The story containing the footer for the first page. |
| **tomFirstPageHeaderStory** | The story containing the header for the first page. |
| **tomFootnotesStory** | The story used for footnotes. |
| **tomMainTextStory** | The main story always exists for a rich edit control. |
| **tomPrimaryFooterStory** | The story containing footers for odd pages. |
| **tomPrimaryHeaderStory** | The story containing headers for odd pages. |
| **tomReplaceStory** | The story used for a Replace dialog. |
| **tomScratchStory** | The scratch story. |
| **tomTextFrameStory** | The story used for a text box. |
| **tomUnknownStory** | No special type. |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetType

Sets this story's type.

```
FUNCTION SetType (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | This story's type. It can be any of the following values, or a custom client value from 100 to 65535. |

| Type | Description |
| ---- | ----------- |
| **tomCommentsStory** | The story used for comments. |
| **tomEndnotesStory** | The story used for endnotes. |
| **tomEvenPagesFooterStory** | The story containing footers for even pages. |
| **tomEvenPagesHeaderStory** |The story containing headers for even pages.|
| **tomFindStory** | The story used for a Find dialog. |
| **tomFirstPageFooterStory** | The story containing the footer for the first page. |
| **tomFirstPageHeaderStory** | The story containing the header for the first page. |
| **tomFootnotesStory** | The story used for footnotes. |
| **tomMainTextStory** | The main story always exists for a rich edit control. |
| **tomPrimaryFooterStory** | The story containing footers for odd pages. |
| **tomPrimaryHeaderStory** | The story containing headers for odd pages. |
| **tomReplaceStory** | The story used for a Replace dialog. |
| **tomScratchStory** | The scratch story. |
| **tomTextFrameStory** | The story used for a text box. |
| **tomUnknownStory** | No special type. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetProperty

Gets the value of the specified property.

```
FUNCTION GetProperty (BYVAL nType AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *nType* | The ID of the property. Currently, no extra properties are defined. |

#### Return value

The property value.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetRange

Gets a text range object for the story.

```
FUNCTION GetRange (BYVAL cpActive AS LONG, BYVAL cpAnchor AS LONG) AS ITextRange2 PTR
```

| Parameter | Description |
| --------- | ----------- |
| *cpActive* | The active end of the range. |
| *cpAnchor* | The anchor end of the range. |

#### Return value

The text range object.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetText

Gets the text in a story according to the specified conversion flags.

```
FUNCTION GetText (BYVAL Flags AS LONG) AS DWSTRING
```

| Parameter | Description |
| --------- | ----------- |
| *Flags* | The conversion flags. A *Flags* value of 0 retrieves text the same as **ITextRange.GetText**. Other values include the following: **tomAdjustCRLF, tomAllowFinalEOP, tomFoldMathAlpha, tomIncludeNumbering, tomNoHidden, tomNoMathZoneBrackets, tomLanguageTag, tomTextize, tomTranslateTableCell, tomUseCRLF**. |

#### Return value

The text in the story.

#### Result code

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

#### Remarks

This method is similar to using **ITextRange2.GetText2** for a whole story, but it doesn’t require a range.

---

## SetFormattedText

Replaces a story’s text with specified formatted text.

```
FUNCTION SetFormattedText (BYVAL pUnk AS IUnknown PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pUnk* | The formatted text to replace the story’s text. |

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

#### Remarks

This method calls **IUnknown.QueryInterface** for an **ITextRange2** interface.

---

## SetProperty

Sets the value of the specified property.

```
FUNCTION SetProperty (BYVAL nType AS LONG, BYVAL VaLue AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *nType* | The Microsoft accountID that identifies the property. Currently, no extra properties are defined. |
| *Value* | The new property value. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetText

Replaces the text in a story with the specified text.

```
FUNCTION SetText (BYVAL Flags AS LONG, BYREF wszText AS WstRING) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Flags* | Flags controlling how the text is inserted as defined in the following table: **tomCheckTextLimit, tomMathCFCheck, tomUnhide, tomUnicodeBiDi, tomUnlink**. |
| *wszText* | The new text for this story. If this parameter is **""**, the text in the story is deleted. |

#### Return value

If the method succeeds, **GetLastResult** returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

---
