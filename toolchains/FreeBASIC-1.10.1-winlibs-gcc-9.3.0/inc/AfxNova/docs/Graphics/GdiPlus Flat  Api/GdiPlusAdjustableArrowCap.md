# AdjustableArrowCap Functions

The **AdjustableArrowCap** functions build a line cap that looks like an arrow.

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift —the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled.

| Name       | Description |
| ---------- | ----------- |
| [GdipCreateAdjustableArrowCap](#gdipcreateadjustablearrowcap) | Creates an adjustable arrow line cap with the specified height and width. |
| [GdipGetAdjustableArrowCapFillState](#gdipgetadjustablearrowcapfillstate) | Determines whether the arrow cap is filled. |
| [GdipGetAdjustableArrowCapHeight](#gdipgetadjustablearrowcapheight) | Gets the height of the arrow cap. The height is the distance from the base of the arrow to its vertex. |
| [GdipGetAdjustableArrowCapMiddleInset](#gdipgetadjustablearrowcapmiddleinset) | Gets the value of the inset. The middle inset is the number of units that the midpoint of the base shifts towards the vertex. |
| [GdipGetAdjustableArrowCapWidth](#gdipgetadjustablearrowcapwidth) | Gets the width of the arrow cap. The width is the distance between the endpoints of the base of the arrow. |
| [GdipSetAdjustableArrowCapFillState](#gdipsetadjustablearrowcapfillstate) | Sets the fill state of the arrow cap. If the arrow cap is not filled, only the outline is drawn. |
| [GdipSetAdjustableArrowCapHeight](#gdipsetadjustablearrowcapheight) | Sets the height of the arrow cap. This is the distance from the base of the arrow to its vertex. |
| [GdipSetAdjustableArrowCapMiddleInset](#gdipsetadjustablearrowcapmiddleinset) | Sets the number of units that the midpoint of the base shifts towards the vertex. |
| [GdipSetAdjustableArrowCapWidth](#gdipsetadjustablearrowcapwidth) | Sets the width of the arrow cap. The width is the distance between the endpoints of the base of the arrow. |

---

## GdipCreateAdjustableArrowCap

Creates an adjustable arrow line cap with the specified height and width. The arrow line cap can be filled or nonfilled. The middle inset defaults to zero.

```
FUNCTION GdipCreateAdjustableArrowCap (BYVAL height AS REAL, BYVAL width AS REAL, _
   BYVAL isFilled AS BOOL, BYVAL cap AS GpAdjustableArrowCap PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *height* | [in] Single precision number that specifies the length, in units, of the arrow from its base to its point. |
| *width* | [in] Single precision number that specifies the distance, in units, between the corners of the base of the arrow. |
| *isFilled* | [in] Boolean value (TRUE or FALSE) that specifies whether the arrow is filled. |
| *cap* | [out] Pointer to a variable that receives a pointer to the new created adjustable arrow line cap. |

#### Return value

If the function succeeds, it returns **Ok**, which is an element of the **GpStatus** enumeration.

If the function fails, it returns one of the other elements of the **GpStatus** enumeration.

#### Example

```
' ========================================================================================
' The following example creates two AdjustableArrowCap objects, arrowCapStart and
' arrowCapEnd, and sets the fill mode to TRUE. The code then creates a Pen object and
' assigns arrowCapStart as the starting line cap for this Pen object and arrowCapEnd as
' the ending line cap. Next, draws a line.
' ========================================================================================
SUB Example_CreateAdjustableArrowCap (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap that is filled.
   DIM arrowCapStart AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @arrowCapStart)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(arrowCapStart, rxRatio)

   ' // Create an AdjustableArrowCap that is not filled.
   DIM arrowCapEnd AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(15, 15, FALSE, @arrowCapEnd)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(arrowCapEnd, rxRatio)

   ' // Create a Pen
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)

   ' Assign arrowCapStart as the start cap.
   hStatus = GdipSetPenCustomStartCap(arrowPen, arrowCapStart)
   ' Assign arrowCapEnd as the end cap.
   hStatus = GdipSetPenCustomEndCap(arrowPen, arrowCapEnd)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

   ' // Cleanup
   IF arrowCapStart THEN GdipDeleteCustomLineCap(arrowCapStart)
   IF arrowCapEnd THEN GdipDeleteCustomLineCap(arrowCapEnd)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

#### Remarks

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift — the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled. The middle inset defaults to zero when an **AdjustableArrowCap** object is constructed.

---

## GdipGetAdjustableArrowCapFillState

Determines whether the arrow cap is filled.

```
FUNCTION GdipGetAdjustableArrowCapFillState (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL fillstate AS BOOL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *fillstate* | [out] Pointer to a variable that receives a boolean value that indicates if the arrow cap is filled (TRUE) or not (FALSE). |

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap object, myArrow, and sets the fill
' mode to TRUE. The code then creates a Pen object and assigns myArrow as the ending line
' cap for this Pen object. Next, the code tests whether myArrow is filled and, if it is,
' draws a line.
' ========================================================================================
SUB Example_IsFilled (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap that is filled.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   ' // Assign myArrow as the start cap.
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // If the cap is filled, draw a line using arrowPen.
   DIM isFilled AS BOOL
   hStatus = GdipGetAdjustableArrowCapFillState(myArrow, @isFilled)
   IF isFilled THEN hStatus = GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

## GdipGetAdjustableArrowCapHeight

Gets the height of the arrow cap. The height is the distance from the base of the arrow to its vertex.

```
FUNCTION GdipGetAdjustableArrowCapHeight (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL height AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *height* | [out] Pointer to a single precision variable that receives a value that indicates the height, in units, of the arrow cap. |

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap, myArrow, and sets the height of the
' cap. The code then creates a Pen, assigns myArrow as the ending line cap for the Pen,
' and draws a capped line. Next, the code gets the height of the arrow cap, creates a new
' arrow cap with height equal to the height of myArrow, assigns the new arrow cap as the
' ending line cap for the Pen, and draws another capped line.
' ========================================================================================
SUB Example_GetHeight (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap with a height of 10 pixels.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

'   // Draw a line using arrowPen.
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 20, 100, 20)

'   // Create a second arrow cap using the height of the first one.
   DIM otherArrow AS GpAdjustableArrowCap PTR
   DIM nHeight AS SINGLE
   hStatus = GdipGetAdjustableArrowCapHeight(myArrow, @nHeight)
   hStatus = GdipCreateAdjustableArrowCap(nHeight, 20, TRUE, @otherArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(otherArrow, rxRatio)

   ' // Assign the new arrow cap as the end cap for arrowPen.
   hStatus = GdipSetPenCustomEndCap(arrowPen, otherArrow)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 55, 100, 55)

   ' // Cleanup
   IF otherArrow THEN GdipDeleteCustomLineCap(otherArrow)
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetAdjustableArrowCapMiddleInset

Gets the value of the inset. The middle inset is the number of units that the midpoint of the base shifts towards the vertex.

```
FUNCTION GdipGetAdjustableArrowCapMiddleInset (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL middleInset AS REAL PTR) AS GpStatus
```
| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *middleInset* | [out] Pointer to a single precision variable that receives a value that specifies the number of units that the midpoint of the base shifts towards the vertex. |

#### Remarks

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift — the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled. The middle inset defaults to zero when an **AdjustableArrowCap** object is constructed.

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap object, myArrow, with middle
' inset set to zero (default value). The code then creates a Pen object, assigns
' myArrow as the ending line cap for this Pen object, and draws a capped line. Next,
' the code gets the middle inset, increments it, and draws another capped line.
' ========================================================================================
SUB Example_GetMiddleInset (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap with width and height set to 10.
   ' // Middle inset defaults to 0 pixels.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLineI(graphics, arrowPen, 0, 20, 100, 20)

   ' // Get the inset of the arrow.
   DIM inset AS SINGLE
   hStatus = GdipGetAdjustableArrowCapMiddleInset(myArrow, @inset)

   ' // Increase inset by 5 pixels and draw another line.
   hStatus = GdipSetAdjustableArrowCapMiddleInset(myArrow, inset + 5)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 50, 100, 50)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetAdjustableArrowCapWidth

Gets the width of the arrow cap. The width is the distance between the endpoints of the base of the arrow.

```
FUNCTION GdipGetAdjustableArrowCapWidth (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL width AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *width* | [out] Pointer to a single precision variable that receives a value that specifies the distance, in units, between the two corners of the base of the arrow. |

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap object, myArrow, and sets the width
' of the cap to 5 pixels. Next, the code creates a Pen object, assigns myArrow as the
' ending line cap for this Pen object, and draws a capped line. The code obtains the width
' using GdipGetAdjustableArrowCapWidth and sets the height equal to the width. The code then
' draws another capped line with the new cap.
' ========================================================================================
SUB Example_GetWidth (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap with a width of 5 pixels.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 5, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

   ' // Get the width of the arrow.
   DIM nWidth AS SINGLE
   hStatus = GdipGetAdjustableArrowCapWidth(myArrow, @nWidth)

   ' // Set height equal to width and draw another line.
   hStatus = GdipSetAdjustableArrowCapHeight(myArrow, nWidth)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)
   GdipDrawLine(graphics, arrowPen, 0, 40, 100, 140)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetAdjustableArrowCapFillState

Sets the fill state of the arrow cap. If the arrow cap is not filled, only the outline is drawn.

```
FUNCTION GdipSetAdjustableArrowCapFillState (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL fillstate AS BOOL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *fillstate* | [in] Boolean (TRUE or FALSE) value that specifies whether the arrow cap is filled. |

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap object, myArrow, and sets the fill
' mode to FALSE. The code then creates a Pen object and assigns myArrow as the ending
' line cap for this Pen object. Next, the code draws a line.
' ========================================================================================
SUB Example_SetFillState (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap. Fill state defaults to TRUE when arrow cap is constructed.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Set fill state to FALSE.
   GdipSetAdjustableArrowCapFillState(myArrow, FALSE)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   ' // Assign myArrow as the start cap.
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line using arrowPen.
   GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

---

## GdipSetAdjustableArrowCapHeight

Sets the height of the arrow cap. This is the distance from the base of the arrow to its vertex.

```
FUNCTION GdipSetAdjustableArrowCapHeight (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL height AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *height* | [in] Single precision value that specifies the height, in units, for the arrow cap. |

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap, pMyArrowCap, and sets the height of the
' cap to 15 pixels. The code then creates a Pen and assigns pMyArrowCap as the ending line cap
' for this Pen. Next, the code draws a capped line.
' ========================================================================================
SUB Example_SetHeight (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap with a width of 5 pixels.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 5, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

   ' // Get the width of the arrow.
   DIM nWidth AS SINGLE
   hStatus = GdipGetAdjustableArrowCapWidth(myArrow, @nWidth)

   ' // Set height equal to width and draw another line.
   hStatus = GdipSetAdjustableArrowCapHeight(myArrow, nWidth)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 40, 100, 140)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetAdjustableArrowCapMiddleInset

Sets the number of units that the midpoint of the base shifts towards the vertex.

```
FUNCTION GdipSetAdjustableArrowCapMiddleInset (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL middleInset AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *middleInset* | [in] Single precision value that specifies the number of units that the midpoint of the base shifts towards the vertex. |

#### Remarks

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift — the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled. The middle inset defaults to zero when an **AdjustableArrowCap** object is constructed.

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap object, myArrow, and sets the middle
' inset of the cap to 5 pixels. The code then creates a Pen object and assigns myArrow as
' the ending line cap for this Pen object. Next, the code draws a capped line.
' ========================================================================================
SUB Example_SetMiddleInset (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)
   ' // Set the middle inmset to 5
   hStatus = GdipSetAdjustableArrowCapMiddleInset(myArrow, 5)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLineI(graphics, arrowPen, 0, 0, 100, 100)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetAdjustableArrowCapWidth

Sets the width of the arrow cap. The width is the distance between the endpoints of the base of the arrow.

```
FUNCTION GdipSetAdjustableArrowCapWidth (BYVAL cap AS GpAdjustableArrowCap PTR, _
   BYVAL width AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *cap* | [in] Pointer to the arrow cap. |
| *width* | [in] Single precision value that specifies the distance, in units, between the two corners of the base of the arrow. |

#### Example

```
' ========================================================================================
' The following example creates an AdjustableArrowCap, myArrow, and sets the width of
' the cap to 10 pixels. The code then creates a Pen, assigns myArrow as the ending
' line cap for this Pen, and draws a capped line. Next, the code sets the width to 15
' pixels, reassigns the arrow cap to the pen, and draws a new capped line.
' ========================================================================================
SUB Example_SetWidth (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   DIM ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create an AdjustableArrowCap with a width of 10 pixels.
   DIM myArrow AS GpAdjustableArrowCap PTR
   hStatus = GdipCreateAdjustableArrowCap(10, 10, TRUE, @myArrow)
   ' // Adjust to DPI by setting the scale width
   hStatus = GdipSetCustomLineCapWidthScale(myArrow, rxRatio)

   ' // Create a Pen, and assign myArrow as the end cap.
   DIM arrowPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_Violet, 1, UnitWorld, @arrowPen)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line using arrowPen.
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 0, 100, 100)

   ' // Get the width of the arrow.
   DIM nWidth AS SINGLE
   GdipGetAdjustableArrowCapWidth(myArrow, @nWidth)

   ' // Set the cap to the new width, and reassign the arrow cap to the pen object.
   hStatus = GdipSetAdjustableArrowCapWidth(myArrow, 15.7)
   hStatus = GdipSetPenCustomEndCap(arrowPen, myArrow)

   ' // Draw a line with new cap
   hStatus = GdipDrawLine(graphics, arrowPen, 0, 40, 100, 140)

   ' // Cleanup
   IF myArrow THEN GdipDeleteCustomLineCap(myArrow)
   IF arrowPen THEN GdipDeletePen(arrowPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

