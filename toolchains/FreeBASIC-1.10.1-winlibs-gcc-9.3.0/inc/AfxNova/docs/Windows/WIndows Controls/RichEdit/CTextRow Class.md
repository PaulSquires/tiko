# CTextRow Class

Class that wraps all the methods of the **ITextRow** interface.

| Name       | Description |
| ---------- | ----------- |
| [CONSTRUCTORS](#constructors) | Called when a class variable is created. |
| [DESTRUCTOR](#destructor) | Called automatically when a class variable goes out of scope or is destroyed. |
| [LET](#let) | Assignment operator. |
| [CAST](#cast) | Cast operator. |
| [TextRowPtr](#textrowptr) | Returns a pointer to the underlying **ITextRow** interface. |
| [Attach](#attach) | Attaches an **ITextRow** interface pointer to the class. |
| [Detach](#detach) | Detaches the underlying **ITextRow** interface pointer from the class. |

---

### ITextRow Interface

The **ITextRow** interface provides methods to insert one or more identical table rows, and to retrieve and change table row properties. To insert nonidentical rows, call **Insert** for each different row configuration.

The **ITextRow** interface inherits from the **IDispatch** interface. **ITextRow** also has these types of members:

| Name       | Description |
| ---------- | ----------- |
| [GetAlignment](#getalignment) | Gets the horizontal alignment of a row. |
| [SetAlignment](#setalignment) | Sets the horizontal alignment of a row. |
| [GetCellCount](#getcellcount) | Gets the count of cells in a row. |
| [SetCellCount](#setcellcount) | Sets the count of cells in a row. |
| [GetCellCountCache](#getcellcountcache) | Gets the count of cells cached for this row. |
| [SetCellCountCache](#setcellcountcache) | Sets the count of cells cached for this row. |
| [GetCellIndex](#getcellindex) | Gets the index of the active cell to get or set parameters for. |
| [SetCellIndex](#setcellindex) | Sets the index of the active cell to get or set parameters for. |
| [GetCellMargin](#getcellmargin) | Gets the cell margin of this row. |
| [SetCellMargin](#setcellmargin) | Sets the cell margin of this row. |
| [GetHeight](#getheight) | Gets the height of the row. |
| [SetHeight](#setheight) | Sets the height of the row. |
| [GetIndent](#getindent) | Gets the indent of this row. |
| [SetIndent](#setindent) | Sets the indent of this row. |
| [GetKeepTogether](#getkeeptogether) | Gets whether this row is allowed to be broken across pages. |
| [SetKeepTogether](#setkeeptogether) | Sets whether this row is allowed to be broken across pages. |
| [GetKeepWithNext](#getkeepwithnext) | Gets whether this row should appear on the same page as the row that follows it. |
| [SetKeepWithNext](#setkeepwithnext) | Sets whether this row should appear on the same page as the row that follows it. |
| [GetNestLevel](#getnestlevel) | Gets the nest level of a table. |
| [GetRTL](#getrtl) | Gets whether this row has right-to-left orientation. |
| [SetRTL](#setrtl) | Sets whether this row has right-to-left orientation. |
| [GetCellAlignment](#getcellalignment) | Gets the vertical alignment of the active cell. |
| [SetCellAlignment](#setcellalignment) | Sets the vertical alignment of the active cell. |
| [GetCellColorBack](#getcellcolorback) | Gets the background color of the active cell. |
| [SetCellColorBack](#setcellcolorback) | Sets the background color of the active cell. |
| [GetCellColorFore](#getcellcolorfore) | Gets the foreground color of the active cell. |
| [SetCellColorFore](#setcellcolorfore) | Sets the foreground color of the active cell. |
| [GetCellMergeFlags](#getcellmergeflags) | Gets the merge flags of the active cell. |
| [SetCellMergeFlags](#setcellmergeflags) | Sets the merge flags of the active cell. |
| [GetCellShading](#getcellshading) | Gets the shading of the active cell. |
| [SetCellShading](#setcellshading) | Sets the shading of the active cell. |
| [GetCellVerticalText](#getcellverticaltext) | Gets the vertical-text setting of the active cell. |
| [SetCellVerticalText](#setcellverticaltext) | Sets the vertical-text setting of the active cell. |
| [GetCellWidth](#getcellwidth) | Gets the width of the active cell. |
| [SetCellWidth](#setcellwidth) | Sets the width of the active cell. |
| [GetCellBorderColors](#getcellbordercolors) | Gets the border colors of the active cell. |
| [GetCellBorderWidths](#getcellborderwidths) | Gets the border widths of the active cell. |
| [SetCellBorderColors](#setcellbordercolors) | Sets the border colors of the active cell. |
| [SetCellBorderWidths](#setcellborderwidths) | Sets the border widths of the active cell. |
| [Apply](#apply) | Applies the formatting attributes of this text row object to the specified rows in the associated **ITextRange2**. |
| [CanChange](#canchange) | Determines whether changes can be made to this row. |
| [GetProperty](#getproperty) | Gets the value of the specified property. |
| [Insert](#insert) | Inserts a row, or rows, at the location identified by the associated **ITextRange2** object. |
| [IsEqual](#isequal) | Compares two table rows to determine if they have the same properties. |
| [Reset](#reset) | Resets a row. |
| [SetProperty](#setproperty) | Sets the value of the specified property. |

---

### Methods inherited from CTextObjectBase Class

| Name       | Description |
| ---------- | ----------- |
| [GetLastResult](#getlastresult) | Returns the last result code |
| [SetResult](#setresult) | Sets the last result code. |
| [GetErrorInfo](#geterrorinfo) | Returns a description of the last result code. |

---

## CONSTRUCTORS

Called when a `CTextRow` class variable is created.

```
DECLARE CONSTRUCTOR
DECLARE CONSTRUCTOR (BYVAL pTextRow AS ITextRow PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

## CONSTRUCTOR (Empty)

Can be used, for example, when we have an **ITextRow** interface pointer returned by a function and we want to attach it to a new instance of the **CTextRow** class. To get a pointer to the **ITextRow** interface call the **GetRow** method of the **CTextDocument2** class.

```
DIM pCTextRow AS CTextRow
pCTextRow.Attach(pTextRow)
```
## CONSTRUCTOR (ITextRow PTR)

```
CONSTRUCTOR CTextRow (BYVAL pTextRow AS ITextRow PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter | Description |
| --------- | ----------- |
| *pTextRow* | An **ITextRow** interface pointer. |
| *fAddRef* | Optional. **TRUE** to increment the reference count of the passed **ITextRow** interface pointer; otherwise, **FALSE**. Default is **FALSE**. |

#### Return value

A pointer to the new instance of the class.

---

## DESTRUCTOR

Called automatically when a class variable goes out of scope or is destroyed.

```
DESTRUCTOR CTextRow
```
---

## LET

Assignment operator. The assigned pointer must be an "addrefed" one.

```
OPERATOR LET (BYVAL pTextRow AS ITextRow PTR)
```
---

## CAST

Cast operator.

```
OPERATOR CAST () AS ITextRow PTR
```
---

## TextRowPtr

Returns a pointer to the underlying **ITextRow** interface

```
FUNCTION TextRowPtr () AS ITextRow PTR
```
---

## Attach

Attaches an **ITextRow** interface pointer to the class.

```
FUNCTION Attach (BYVAL pTextRow AS ITextRow PTR, BYVAL fAddRef AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pTextRow* | The **ITextRow** interface pointer to attach. |
| *fAddRef* | **TRUE** to increment the reference count of the object; otherwise, **FALSE**. Default is **FALSE**. |

+++

## Detach

Detaches the interface pointer from the class

```
FUNCTION Detach () AS ITextRow PTR
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
FUNCTION CTOMBase.GetErrorInfo () AS DWSTRING
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

## GetAlignment

Gets the horizontal alignment of a row.

```
FUNCTION GetAlignment () AS LONG
```

#### Return value

The horizontal alignment. It can be one of the following values.

| Constant | Value | Meaning |
| -------- | ----- | ------- |
| **tomAlignLeft** | 0 | Text aligns with the left margin. |
| **tomAlignCenter** | 1 | Text is centered between the margins. |
| **tomAlignRight** | 2 | Text aligns with the right margin. |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetAlignment

Sets the horizontal alignment of a row.

```
FUNCTION SetAlignment (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The new horizontal alignment. It can be one of the following values. |

| Constant | Value | Meaning |
| -------- | ----- | ------- |
| **tomAlignLeft** | 0 | Text aligns with the left margin. |
| **tomAlignCenter** | 1 | Text is centered between the margins. |
| **tomAlignRight** | 2 | Text aligns with the right margin. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCellCount

Gets the count of cells in this row.

```
FUNCTION GetCellCount () AS LONG
```

#### Return value

The cell count for this row.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellCount

Sets the count of cells in a row.

```
FUNCTION SetCellCount (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The row cell count. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCellCountCache

Gets the count of cells cached for this row.

```
FUNCTION GetCellCountCache () AS LONG
```

#### Return value

The cached cell count.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellCountCache

Sets the count of cells cached for a row.

```
FUNCTION SetCellCountCache (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The row cell count. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

If all cells are identical, properties need to be cached only for the cell with index 0. If the cached count is less than the cell count, the cell parameters for index CellCountCache – 1 are used for cells with larger indices.

---

## GetCellIndex

Gets the index of the active cell to get or set parameters for.

```
FUNCTION GetCellIndex () AS LONG
```

#### Return value

The cell index.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellIndex

Sets the index of the active cell.

```
FUNCTION SetCellIndex (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The cell index. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

You can get or set parameters for an active cell.

If the cell index is greater than the cell count, and the cell index is less that 63 (the maximum cell count), then the cell count is increased to cell index + 1.

---

## GetCellMargin

Gets the cell margin of this row.

```
FUNCTION GetCellMargin () AS LONG
```

#### Return value

The cell margin.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellMargin

Sets the cell margin of a row.

```
FUNCTION SetCellMargin (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The cell margin. The cell margin is used for all cells in the row and is typically about 108 twips or 0.075 inches. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetHeight

Gets the height of the row.

```
FUNCTION GetHeight () AS LONG
```

#### Return value

The row height. A value of 0 indicates autoheight.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetHeight

Sets the cell margin of a row.

```
FUNCTION SetHeight (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The row height. A value of 0 indicates autoheight. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetIndent

Gets the indent of this row.

```
FUNCTION GetIndent () AS LONG
```

#### Return value

The indent of the row.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetIndent

Sets the indent of a row.

```
FUNCTION SetIndent (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The row indent. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetKeepTogether

Gets whether this row is allowed to be broken across pages.

```
FUNCTION GetKeepTogether () AS LONG
```

#### Return value

A **tomBool** value that indicates whether this row can be broken across pages.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetKeepTogether

Sets whether this row is allowed to be broken across pages.

```
FUNCTION SetKeepTogether (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | A **tomBool** value that indicates whether this row can be broken across pages. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetKeepWithNext

Gets whether this row is allowed to be broken across pages.

```
FUNCTION GetKeepWithNext () AS LONG
```

#### Return value

A **tomBool** value that indicates whether this row can be broken across pages.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetNestLevel

Gets the nest level of a table.

```
FUNCTION GetNestLevel () AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The nest level. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The nest level of the table is identified by the associated **ITextRange2** object. If there is only a single table, the nest level is 1. If there is no table, the nest level is 0.

---

## GetRTL

Gets whether this row has right-to-left orientation.

```
FUNCTION GetRTL () AS LONG
```

#### Return value

A **tomBool** value that indicates whether this row has right-to-left orientation.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetRTL

Sets whether this row has right-to-left orientation.

```
FUNCTION SetRTL (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | A **tomBool** value that can be one of the following. |

| Value | Meaning |
| ----- | ------- |
| **tomTrue** | Right-to-left orientation. |
| **tomFalse** | Left-to-right orientation. |
| **tomToggle** | Toggles the orientation. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCellAlignment

Gets the vertical alignment of the active cell.

```
FUNCTION GetCellAlignment () AS LONG
```

#### Return value

The vertical alignment.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellAlignment

Sets the vertical alignment of the active cell.

```
FUNCTION SetCellAlignment (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The vertical alignment. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## >GetCellColorBack

Gets the background color of the active cell.

```
FUNCTION GetCellColorBack () AS LONG
```

#### Return value

The background color.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellColorBack

Sets the background color of the active cell.

```
FUNCTION SetCellColorBack (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The background color. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

See **GetCellShading** to see how the background color is used together with the foreground color.

---

## GetCellColorFore

Gets the foreground color of the active cell.

```
FUNCTION GetCellColorFore () AS LONG
```

#### Return value

Gets the foreground color of the active cell.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellColorFore

Sets the foreground color of the active cell.

```
FUNCTION SetCellColorFore (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The foreground color. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

See **GetCellShading** to see how the foreground color is used together with the background color.

---

## GetCellMergeFlags

Gets the merge flags of the active cell.

```
FUNCTION GetCellMergeFlags () AS LONG
```

#### Return value

The merge flag of the active cell. The flag can be one of the following:

| Flag | Meaning |
| --------- | ----------- |
| **tomHContCell** | Any cell except the start in a horizontally merged cell set. |
| **tomHStartCell** | The top cell in vertically merged cell set. |
| **tomVLowCell** | Any cell except the top cell in a vertically merged cell set. |
| **tomVTopCell** | The top cell in vertically merged cell set. |

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellMergeFlags

Sets the merge flags of the active cell.

```
FUNCTION SetCellMergeFlags (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The merge flag. It can be one of these values. |

| Flag | Meaning |
| --------- | ----------- |
| **tomHContCell** | Any cell except the start in a horizontally merged cell set. |
| **tomHStartCell** | The top cell in vertically merged cell set. |
| **tomVLowCell** | Any cell except the top cell in a vertically merged cell set. |
| **tomVTopCell** | The top cell in vertically merged cell set. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCellShading

Gets the shading of the active cell.

```
FUNCTION GetCellShading () AS LONG
```

#### Return value

The shading of the active cell. See Remarks.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The shading is given in hundredths of a percent, so full shading is given by the value 10000. The shading percentage determines the mix of the cell foreground and background colors to be used for the cell background. A shading of 0 uses the cell background color alone. A shading of 10000 (100%) uses the foreground color alone. Values in between mix the foreground and background colors, weighting the background with (10000 – CellShading)/1000 and the foreground with CellShading/1000. These ratios are applied to the red, green, and blue channels independently of one another.

---

## SetCellShading

Sets the shading of the active cell.

```
FUNCTION SetCellShading (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The shading of the active cell. |

#### Remarks

The shading is given in hundredths of a percent, so full shading is given by the value 10000. The shading percentage determines the mix of the cell foreground and background colors to be used for the cell background. A shading of 0 uses the cell background color alone. A shading of 10000 (100%) uses the foreground color alone. Values in between mix the foreground and background colors, weighting the background with (10000 – CellShading)/1000 and the foreground with CellShading/1000. These ratios are applied to the red, green, and blue channels independently of one another.

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCellVerticalText

Gets the vertical-text setting of the active cell.

This property is not currently implemented.

```
FUNCTION GetCellVerticalText () AS LONG
```

#### Return value

The vertical-text setting.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellVerticalText

Sets the vertical-text setting of the active cell.

This property is not currently implemented.

```
FUNCTION SetCellVerticalText (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The vertical-text setting. |

---

## GetCellWidth

Gets the width of the active cell.

```
FUNCTION GetCellWidth () AS LONG
```

#### Return value

The width of the active cell, in twips.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The width of the cell, and/or the entire row, must be less than 22 inches (1440 x 22).

---

## SetCellWidth

Sets the active cell width in twips.

```
FUNCTION SetCellWidth (BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The width of the active cell. |

#### Remarks

The total width of the entire row must be less than 22 inches, or 1440×22.

---

## GetCellBorderColors

Gets the border colors of the active cell.

```
FUNCTION GetCellBorderColors (BYVAL pcrLeft AS LONG PTR, BYVAL pcrTop AS LONG PTR, _
   BYVAL pcrRight AS LONG PTR, BYVAL pcrBottom AS LONG PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pcrLeft* | The active-cell left border color. |
| *pcrTop* | The active-cell top border color. |
| *pcrRight* | The active-cell right border color. |
| *pcrBottom* | The active-cell bottom border color. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetCellBorderWidths

Gets the border widths of the active cell.

```
FUNCTION GetCellBorderWidths (BYVAL pduLeft AS LONG PTR, BYVAL pduTop AS LONG PTR, _
   BYVAL pduRight AS LONG PTR, BYVAL pduBottom AS LONG PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pduLeft* | The active-cell left border width. |
| *pduTop* | The active-cell top border width. |
| *pduRight* | The active-cell right border width. |
| *pduBottom* | The active-cell bottom border width. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellBorderColors

Sets the border colors of the active cell.

```
FUNCTION SetCellBorderColors (BYVAL crLeft AS LONG, BYVAL crTop AS LONG, _
   BYVAL crRight AS LONG, BYVAL crBottom AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *crLeft* | The left border color. |
| *crTop* | The top border color. |
| *crRight* | The right border color. |
| *crBottom* | The bottom border color. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## SetCellBorderWidths

Sets the border widths of the active cell.

```
FUNCTION SetCellBorderWidths (BYVAL duLeft AS LONG, BYVAL duTop AS LONG, _
   BYVAL duRight AS LONG, BYVAL duBottom AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *duLeft* | The left border width. |
| *duTop* | The top border width. |
| *duRight* | The right border width. |
| *duBottom* | The bottom border width. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## Apply

Applies the formatting attributes of this text row object to the specified rows in the associated **ITextRange2**.

```
FUNCTION Apply (BYVAL cRow AS LONG, BYVAL Flags AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *cRow* | The number of rows to apply this text row object to. |
| *Flags* | A flag that controls how the formatting attributes are applied. It can be one of the following values. |

| Value | Meaning |
| ----- | ------- |
| **tomCellStructureChangeOnly** | Apply formatting attributes only to cell widths or the cell count (enables you to change column widths or insert/delete columns without changing other properties, such as cell borders). |
| **tomRowApplyDefault** | Apply formatting attributes to the full application, not just cell widths and count. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## CanChange

Determines whether changes can be made to this row.

```
FUNCTION CanChange () AS LONG
```

#### Return value

A **tomBool** indicating whether the row can be edited. It is **tomTrue** only if the row can be edited.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## GetProperty

Gets the value of the specified property.

```
FUNCTION GetProperty (BYVAL nType AS LONG) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *nType* | The ID of the property to retrieve. |

#### Return value

The value for the property.

#### Result code

If the method succeeds, **GetLastResult** returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## Insert

Inserts a row, or rows, at the location identified by the associated **ITextRange2** object.

```
FUNCTION Insert (BYVAL cRow AS LONG) AS HRESULT
```

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## IsEqual

Compares two table rows to determine if they have the same properties.

```
FUNCTION IsEqual (BYVAL pRow AS ITextRow PTR) AS LONG
```

| Parameter | Description |
| --------- | ----------- |
| *pRow* | The row to compare to. |

#### Return value

The comparison result: **tomTrue** if equal, and **tomFalse** if not.

#### Result code

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---

## Reset

Resets a row.

```
FUNCTION Reset (BYVAL Value AS LONG = tomRowUpdate) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *Value* | The **tomRowUpdate reset value: Update the row to have the properties of the table row identified by the associated text range. |

#### Return value

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Result code | Description |
| ----------- | ----------- |
| **E_ACCESSDENIED** | Write access is denied. | 
| **E_OUTOFMEMORY** | Insufficient memory. | 

---

## SetProperty

Sets the value of the specified property.

```
FUNCTION SetProperty (BYVAL nType AS LONG, BYVAL Value AS LONG) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *nType* | The ID of the property to set. |
| *Value* | The value to set. |

#### Return value

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

---
