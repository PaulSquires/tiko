# Graphics Functions

The **Graphics** functions provide methods for drawing lines, curves, figures, images, and text. A **Graphics** object stores attributes of the display device and attributes of the items to be drawn.

| Name       | Description |
| ---------- | ----------- |
| [GdipBeginContainer](#gdipbegincontainer) | Begins a new graphics container. |
| [GdipBeginContainerI](#gdipbegincontainer1) | Begins a new graphics container. |
| [GdipBeginContainer2](#gdipbegincontainer2) | Begins a new graphics container. |
| [GdipComment](#gdipcomment) | Adds a text comment to an existing metafile. |
| [GdipCreateFromHDC](#gdipcreatefromhdc) | Creates a **Graphics** object that is associated with a specified device context. |
| [GdipCreateFromHDC2](#gdipcreatefromHdc2) | Creates a **Graphics** object that is associated with a specified device context and a specified device handle. |
| [GdipCreateFromHWND](#gdipcreatefromhwnd) | Creates a **Graphics** object that is associated with a specified window. |
| [GdipCreateFromHWNDICM](#gdipcreatefromhwndicm) | Creates a **Graphics** object that is associated with a specified window. This function uses ICM. |
| [GdipCreateHalftonePalette](#gdipcreatehalftonepalette) | Gets a Windows halftone palette. |
| [GdipCreateMetafileFromEmf](#gdipcreatemetafilefromemf) | Creates a Microsoft Windows GDI+ Metafile object for playback based on a Windows Graphics Device Interface (GDI) Enhanced Metafile (EMF) file. |
| [GdipCreateMetafileFromFile](#gdipcreatemetafilefromfile) | Creates a **Metafile** object for playback. |
| [GdipCreateMetafileFromStream](#gdipcreatemetafilefromstream) | Creates a **Metafile** object from an **IStream** interface for playback. |
| [GdipCreateMetafileFromWmf](#gdipcreatemetafilefromwmf) | Creates a Microsoft Windows GDI+ Metafile object for recording. The format will be placeable metafile. |
| [GdipCreateMetafileFromWmfFile](#gdipcreatemetafilefromwmffile) | Creates a Microsoft Windows GDI+ **Metafile** object for playback. |
| [GdipCreateStreamOnFile](#gdipcreatestreamonfile) | Returns a pointer to an **IStream** interface based on a file. |
| [GdipDeleteGraphics](#gdipdeletegraphics) | Deletes the specified **Graphics** object. |
| [GdipDrawArc](#gdipdrawarc) | Draws an arc. The arc is part of an ellipse. |
| [GdipDrawArcI](#gdipdrawarc) | Draws an arc. The arc is part of an ellipse. |
| [GdipDrawBezier](#gdipdrawbezier) | Draws a Bezier spline. |
| [GdipDrawBezierI](#gdipdrawbezier) | Draws a Bezier spline. |
| [GdipDrawBeziers](#gdipdrawbeziers) | Draws a sequence of connected Bezier splines. |
| [GdipDrawBeziersI](#gdipdrawbeziers) | Draws a sequence of connected Bezier splines. |
| [GdipDrawClosedCurve](#gdipdrawclosedcurve) | Draws a closed cardinal spline. |
| [GdipDrawClosedCurveI](#gdipdrawclosedcurve) | Draws a closed cardinal spline. |
| [GdipDrawClosedCurve2](#gdipdrawclosedcurve2) | Draws a closed cardinal spline. |
| [GdipDrawClosedCurve2I](#gdipdrawclosedcurve2) | Draws a closed cardinal spline. |
| [GdipDrawCurve](#gdipdrawcurve) | Draws a cardinal spline. |
| [GdipDrawCurveI](#gdipdrawcurve) | Draws a cardinal spline. |
| [GdipDrawCurve2](#gdipdrawcurve2) | Draws a cardinal spline. |
| [GdipDrawCurve2I](#gdipdrawcurve2) | Draws a cardinal spline. |
| [GdipDrawCurve3](#gdipdrawcurve3) | Draws a cardinal spline. |
| [GdipDrawCurve3I](#gdipdrawcurve3) | Draws a cardinal spline. |
| [GdipDrawDriverString](#gdipdrawdriverstring) | Draws characters at the specified positions. The function gives the client complete control over the appearance of text. The function assumes that the client has already set up the format and layout to be applied. |
| [GdipDrawEllipse](#gdipdrawellipse) | Draws an ellipse. |
| [GdipDrawEllipseI](#gdipdrawellipse) | Draws an ellipse. |
| [GdipDrawImage](#gdipdrawimage) | Draws an image at a specified location. |
| [GdipDrawImageI](#gdipdrawimage) | Draws an image at a specified location. |
| [GdipDrawImageFX](#gdipdrawimagefx) | Draws a portion of an image after applying a specified effect. |
| [GdipDrawImagePointRect](#gdipdrawimagepointrect) | Draws an image at a specified location. |
| [GdipDrawImagePointRectI](#gdipdrawimagepointrect) | Draws an image at a specified location. |
| [GdipDrawImagePoints](#gdipdrawimagepoints) | Draws an image at a specified location. |
| [GdipDrawImagePointsI](#gdipdrawimagepoints) | Draws an image at a specified location. |
| [GdipDrawImagePointsRect](#gdipdrawimagepointsrect) | Draws an image at a specified location. |
| [GdipDrawImagePointsRectI](#gdipdrawimagepointsrect) | Draws an image at a specified location. |
| [GdipDrawImageRect](#gdipdrawimagerect) | Draws an image at a specified location. |
| [GdipDrawImageRectI](#gdipdrawimagerect) | Draws an image at a specified location. |
| [GdipDrawImageRectRect](#gdipdrawimagerectrect) | Draws an image at a specified location. |
| [GdipDrawImageRectRectI](#gdipdrawimagerectrect) | Draws an image at a specified location. |
| [GdipDrawLine](#gdipdrawline) | Draws a line that connects two points. |
| [GdipDrawLineI](#gdipdrawline) | Draws a line that connects two points. |
| [GdipDrawLines](#gdipdrawlines) | Draws a sequence of connected lines. |
| [GdipDrawLinesI](#gdipdrawlines) | Draws a sequence of connected lines. |
| [GdipDrawPath](#gdipdrawpath) | Draws a sequence of lines and curves defined by a **GraphicsPath** object. |
| [GdipDrawPie](#gdipdrawpie) | Draws a pie. |
| [GdipDrawPieI](#gdipdrawpie) | Draws a pie. |
| [GdipDrawPolygon](#gdipdrawpolygon) | Draws a polygon. |
| [GdipDrawPolygonI](#gdipdrawpolygon) | Draws a polygon. |
| [GdipDrawRectangle](#gdipdrawrectangle) | Draws a rectangle. |
| [GdipDrawRectangleI](#gdipdrawrectangle) | Draws a rectangle. |
| [GdipDrawRectangles](#gdipdrawrectangles) | Draws a sequence of rectangles. |
| [GdipDrawRectanglesI](#gdipdrawrectangles) | Draws a sequence of rectangles. |
| [GdipDrawString](#gdipdrawstring) | Draws a string based on a font, a layout rectangle, and a format. |
| [GdipEndContainer](#gdipendcontainer) | Closes a graphics container that was previously opened by the **GdipBeginContainer** method. |
| [GdipEnumerateMetafileDestPoint](#gdipenumeratemetafiledestpoint) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileDestPointI](#gdipenumeratemetafiledestpoint) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileDestPoints](#gdipenumeratemetafiledestpoints) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileDestPointsI](#gdipenumeratemetafiledestpoints) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileDestRect](#gdipenumeratemetafiledestrect) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileDestRectI](#gdipenumeratemetafiledestrect) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileSrcRectDestPoint](#gdipenumeratemetafilesrcrectdestpoint) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileSrcRectDestPointI](#gdipenumeratemetafilesrcrectdestpoint) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileSrcRectDestPoints](#gdipenumeratemetafilesrcrectdestpoints) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileSrcRectDestPointsI](#gdipenumeratemetafilesrcrectdestpoints) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileSrcRectDestRect](#gdipenumeratemetafilesrcrectdestrect) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipEnumerateMetafileSrcRectDestRectI](#gdipenumeratemetafilesrcrectdestrect) | Calls an application-defined callback function for each record in a specified metafile. |
| [GdipFillClosedCurve](#gdipfillclosedcurve) | Creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline. |
| [GdipFillClosedCurveI](#gdipfillclosedcurve) | Creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline. |
| [GdipFillClosedCurve2](#gdipfillclosedcurve2) | Creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline. |
| [GdipFillClosedCurve2I](#gdipfillclosedcurve2) | Creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline. |
| [GdipFillEllipse](#gdipfillellipse) | Uses a brush to fill the interior of an ellipse that is specified by coordinates and dimensions. |
| [GdipFillEllipseI](#gdipfillellipse) | Uses a brush to fill the interior of an ellipse that is specified by coordinates and dimensions. |
| [GdipFillPath](#gdipfillpath) | Uses a brush to fill the interior of a path. |
| [GdipFillPie](#gdipfillpie) | Uses a brush to fill the interior of a pie. |
| [GdipFillPieI](#gdipfillpie) | Uses a brush to fill the interior of a pie. |
| [GdipFillPolygon](#gdipfillpolygon) | Uses a brush to fill the interior of a polygon. |
| [GdipFillPolygonI](#gdipfillpolygon) | Uses a brush to fill the interior of a polygon. |
| [GdipFillPolygon2](#gdipfillpolygon2) | Uses a brush to fill the interior of a polygon. |
| [GdipFillPolygon2I](#gdipfillpolygon2) | Uses a brush to fill the interior of a polygon. |
| [GdipFillRectangle](#gdipfillrectangle) | Uses a brush to fill the interior of a rectangle. |
| [GdipFillRectangleI](#gdipfillrectangle) | Uses a brush to fill the interior of a rectangle. |
| [GdipFillRectangles](#gdipfillrectangles) | Uses a brush to fill the interior of rectangles. |
| [GdipFillRectanglesI](#gdipfillrectangles) | Uses a brush to fill the interior of rectangles. |
| [GdipFillRegion](#gdipfillregion) | Uses a brush to fill a specified region. |
| [GdipFlush](#GdipFlush) | Flushes all pending graphics operations. |
| [GdipGetClip](#Gdipgetclip) | Gets the clipping region of the **Graphics** object. |
| [GdipGetClipBounds](#Gdipgetclipbounds) | Gets a rectangle that encloses the clipping region of the **Graphics** object. |
| [GdipGetClipBoundsI](#Gdipgetclipbounds) | Gets a rectangle that encloses the clipping region of the **Graphics** object. |
| [GdipGetCompositingMode](#gdipgetcompositingmode) | Gets the compositing mode currently set for the **Graphics** object. |
| [GdipGetCompositingQuality](#gdipgetcompositingquality) | Gets the compositing quality currently set for the **Graphics** object. |
| [GdipGetDC](#gdipgetdc) | Gets a handle to the device context associated with the **Graphics** object. |
| [GdipGetDpiX](#gdipgetdpix) | Gets the horizontal resolution, in dots per inch, of the display device associated with the **Graphics** object. |
| [GdipGetDpiY](#gdipgetdpiy) | Gets the vertical resolution, in dots per inch, of the display device associated with the **Graphics** object. |
| [GdipGetHemfFromMetafile](#gdipgethemffrommetafile) | Gets a Windows handle to an Enhanced Metafile (EMF) file. |
| [GdipGetImageDecoders](#gdipgetimagedecoders) | Gets an array of **ImageCodecInfo** objects that contain information about the available image decoders. |
| [GdipGetImageDecodersSize](#gdipgetimagedecoderssize) | Gets the number of available image decoders and the total size of the array of **ImageCodecInfo** objects that is returned by the **GdipGetImageDecoders** function. |
| [GdipGetImageEncoders](#gdipgetimageencoders) | The **GdipGetImageEncoders** function gets an array of **ImageCodecInfo** structures that contain information about the available image encoders. |
| [GdipGetImageEncodersSize](#gdipgetimageencodersize) | The **GdipGetImageEncodersSize** function gets the number of available image encoders and the total size of the array of **ImageCodecInfo** structures that is returned by the **GdipGetImageEncoders** function. |
| [GdipGetImageGraphicsContext](#gdipgetimagegraphicscontext) | Creates a **Graphics** object that is associated with an **Image** object. |
| [GdipGetInterpolationMode](#gdipgetinterpolationmode) | Gets the interpolation mode currently set for the **Graphics** object. The interpolation mode determines the algorithm that is used when images are scaled or rotated. |
| [GdipGetMetafileDownLevelRasterizationLimit](#gdipgetmetafiledownlevelrasterizationlimit) | Gets the rasterization limit currently set for this metafile. |
| [GdipGetMetafileHeaderFromEmf](#gdipgetmetafileheaderfromemf) | Gets the metafile header. |
| [GdipGetMetafileHeaderFromFile](#gdipgetmetafileheaderfromfile) | Gets the metafile header. |
| [GdipGetMetafileHeaderFromMetafile](#gdipgetmetafileheaderfrommetafile) | Gets the metafile header. |
| [GdipGetMetafileHeaderFromStream](#gdipgetmetafileheaderfromstream) | Gets the metafile header. |
| [GdipGetMetafileHeaderFromEmf](#gdipgetmetafileheaderfromemf) | Gets the metafile header. |
| [GdipGetNearestColor](#gdipgetnearestcolor) | Gets the nearest color to the color that is passed in. |
| [GdipGetPageScale](#gdipgetpagescale) | Gets the scaling factor currently set for the page transformation of this Graphics object. The page transformation converts page coordinates to device coordinates. |
| [GdipGetPageUnit](#gdipgetpageunit) | Gets the unit of measure currently set for the **Graphics** object. |
| [GdipGetPixelOffsetMode](#gdipgetpixeloffsetmode) | Gets the pixel offset mode currently set for the **Graphics** object. |
| [GdipGetRenderingOrigin](#gdipgetrenderingorigin) | Gets the rendering origin currently set for the **Graphics** object. |
| [GdipGetSmoothingMode](#gdipgetsmoothingmode) | Determines whether smoothing (antialiasing) is applied to the **Graphics** object. |
| [GdipGetTextContrast](#gdipgettextcontrast) | Gets the contrast value currently set for this Graphics object. The contrast value is used for antialiasing text. |
| [GdipGetTextRenderingHint](#gdipgettextrenderinghint) | Gets the text rendering mode currently set for the **Graphics** object. |
| [GdipGetVisibleClipBounds](#gdipgetvisibleclipbounds) | Gets a rectangle that encloses the visible clipping region of the **Graphics** object. |
| [GdipGetVisibleClipBoundsI](#gdipgetvisibleclipbounds) | Gets a rectangle that encloses the visible clipping region of the **Graphics** object. |
| [GdipGetWorldTransform](#gdipgetworldtransform) | Gets the world transformation matrix of the **Graphics** object. |
| [GdipGraphicsClear](#gdipgraphicsclear) | Clears a **Graphics** object to a specified color. |
| [GdipGraphicsSetAbort](#gdipgraphicssetabort) | Not used in Microsoft Windows GDI+ versions 1.0 and 1.1. |
| [GdipIsClipEmpty](#gdipisclipempty) | Determines whether the clipping region of the **Graphics** object is empty. |
| [GdipIsVisibleClipEmpty](#gdipisvisibleclipempty) | Determines whether the visible clipping region of the **Graphics** object is empty. |
| [GdipIsVisiblePoint](#gdipisvisiblepoint) | Determines whether the specified point is inside the visible clipping region of the **Graphics** object. |
| [GdipIsVisiblePointI](#gdipisvisiblepoint) | Determines whether the specified point is inside the visible clipping region of the **Graphics** object. |
| [GdipIsVisibleRect](#gdipisvisiblerect) | Determines whether the specified point is inside the visible clipping region of this Graphics object. |
| [GdipIsVisibleRectI](#gdipisvisiblerect) | Determines whether the specified point is inside the visible clipping region of this Graphics object. |
| [GdipMeasureCharacterRanges](#gdipmeasurecharacterranges) | Gets a set of regions each of which bounds a range of character positions within a string. |
| [GdipMeasureDriverString](#gdipmeasuredriverstring) | Measures the bounding box for the specified characters and their corresponding positions. |
| [GdipMeasureString](#gdipmeasurestring) | Measures the extent of the string in the specified font, format, and layout rectangle. |
| [GdipMultiplyWorldTransform](#gdipmultiplyworldtransform) | Updates the **Graphics** object's world transformation matrix with the product of itself and another matrix. |
| [GdipPlayMetafileRecord](#gdipplaymetafilerecord) | Plays a metafile record. |
| [GdipRecordMetafile](#Gdiprecordmetafile) | Creates a **Metafile** object for recording. |
| [GdipRecordMetafileI](#Gdiprecordmetafile) | Creates a **Metafile** object for recording. |
| [GdipRecordMetafileFileName](#gdiprecordmetafilefilename) | Creates a **Metafile** object for recording. |
| [GdipRecordMetafileFileNameI](#gdiprecordmetafilefilename) | Creates a **Metafile** object for recording. |
| [GdipRecordMetafileStream](#gdiprecordmetafilestream) | Creates a **Metafile** object for recording to an **IStream** interface. |
| [GdipRecordMetafileStreamI](#gdiprecordmetafilestream) | Creates a **Metafile** object for recording to an **IStream** interface. |
| [GdipReleaseDC](#gdipreleasedc) | Releases a device context handle obtained by a previous call to the **GdipGetDC** function. |
| [GdipResetClip](#gdipresetclip) | Sets the clipping region of the **Graphics** object to an infinite region. |
| [GdipResetPageTransform](#gdipresetpagetransform) | Resets the page transform matrix to identity. |
| [GdipResetWorldTransform](#gdipresetworldtransform) | Resets the world transformation matrix of the **Graphics** to the identity matrix. |
| [GdipRestoreGraphics](#gdiprestoregraphics) | Sets the state of the **Graphics** object to the state stored by a previous call to the **Save** method of the **Graphics** object. |
| [GdipRotateWorldTransform](#gdiprotateworldtransform) | Updates the world transformation matrix of the **Graphics** object with the product of itself and a rotation matrix. |
| [GdipSaveGraphics](#gdipsavegraphics) | Saves the current state (transformations, clipping region, and quality settings) of the **Graphics** object. You can restore the state later by calling the **GdipRestoreGraphics** function. |
| [GdipScaleWorldTransform](#gdipscaleworldtransform) | Updates the **Graphics** object's world transformation matrix with the product of itself and a scaling matrix. |
| [GdipSetClipGraphics](#gdipsetclipgraphics) | Updates the clipping region of this Graphics object to a region that is the combination of itself and the clipping region of another **Graphics** object. |
| [GdipSetClipHrgn](#gdipsetcliphrgn) | Updates the clipping region of the **Graphics** object to a region that is the combination of itself and a GDI region. |
| [GdipSetClipPath](#gdipsetclippath) | Updates the clipping region of the **Graphics** object to a region that is the combination of itself and the region specified by a graphics path. |
| [GdipSetClipRect](#gdipsetcliprect) | Updates the clipping region of the **Graphics** object to a region that is the combination of itself and a rectangle. |
| [GdipSetClipRectI](#gdipsetcliprect) | Updates the clipping region of the **Graphics** object to a region that is the combination of itself and a rectangle. |
| [GdipSetCompositingMode](#gdipsetcompositingmode) | Sets the compositing mode of the **Graphics** object. |
| [GdipSetCompositingQuality](#gdipsetcompositingquality) | Sets the compositing quality of the **Graphics** object. |
| [GdipSetInterpolationMode](#gdipsetinterpolationmode) | Sets the interpolation mode of the **Graphics** object. |
| [GdipSetMetafileDownLevelRasterizationLimit](#gdipsetmetafiledownlevelrasterizationlimit) | Sets the resolution for certain brush bitmaps that are stored in this metafile. |
| [GdipSetPageScale](#gdipsetpagescale) | Sets the scaling factor for the page transformation of the **Graphics** object. The page transformation converts page coordinates to device coordinates. |
| [GdipSetPageUnit](#gdipsetpageunit) | Sets the unit of measure for the **Graphics** object. The page unit belongs to the page transformation, which converts page coordinates to device coordinates. |
| [GdipSetPixelOffsetMode](#gdipsetpixeloffsetmode) | Sets the pixel offset mode of the **Graphics** object. |
| [GdipSetRenderingOrigin](#gdipsetrenderingorigin) | Sets the rendering origin of the **Graphics** object. |
| [GdipSetSmoothingMode](#gdipsetsmoothingmode) | Sets the render quality of the **Graphics** object. |
| [GdipSetTextRenderingHint](#gdipsettextrenderinghint) | Sets the text rendering mode of the **Graphics** object. |
| [GdipSetWorldTransform](#gdipsetworldtransform) | Sets the world transformation of the **Graphics** object. |
| [GdipTransformPoints](#gdiptransformpoints) | Converts an array of points from one coordinate space to another. The conversion is based on the current world and page transformations of the **Graphics** object. |
| [GdipTransformPointsI](#gdiptransformpoints) | Converts an array of points from one coordinate space to another. The conversion is based on the current world and page transformations of the **Graphics** object. |
| [GdipTranslateClip](#gdiptranslateclip) | Translates the clipping region of the **Graphics** object. |
| [GdipTranslateClipI](#gdiptranslateclip) | Translates the clipping region of the **Graphics** object. |
| [GdipTranslateWorldTransform](#gdiptranslateworldtransform) | Updates the **Graphics** object's world transformation matrix with the product of itself and a translation matrix. |

---

## GdipBeginContainer

Begins a new graphics container.

```
FUNCTION GdipBeginContainer (BYVAL graphics AS GpGraphics PTR, BYVAL dstrect AS GpRectF PTR, _
   BYVAL srcrect AS GpRectF PTR, BYVAL unit AS GpUnit, BYVAL state AS GraphicsContainer PTR) AS GpStatus
```
```
FUNCTION GdipBeginContainerI (BYVAL graphics AS GpGraphics PTR, BYVAL dstrect AS GpRect PTR, _
   BYVAL srcrect AS GpRect PTR, BYVAL unit AS GpUnit, BYVAL state AS GraphicsContainer PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *dstrect* | [in] Reference to a rectangle that, together with *srcrect*, specifies a transformation for the container. |
| *srcrect* | [in] Reference to a rectangle that, together with *dstrect*, specifies a transformation for the container. |
| *unit* | [in] Unit of measure for the container. |
| *state* | [out] Pointer to a **GraphicsContainer** object variable that receives a value that identifies the container. |

#### Remarks

Use this function to create nested graphics containers. Graphics containers are used to retain graphics state, such as transformations, clipping regions, and various rendering properties.

The **GdipBeginContainer** function returns a value of type **GraphicsContainer**. When you have finished using a container, pass that value to the **GdipEndContainer** function.

When you call the **GdipBeginContainer** function, an information block that holds the state of the **Graphics** object is put on a stack. The **GdipBeginContainer** function returns a value that identifies that information block. When you pass the identifying value to the **GdipEndContainer** function, the information block is removed from the stack and is used to restore the **Graphics** object to the state it was in at the time of the **GdipBeginContainer** call.

Containers can be nested; that is, you can call the **GdipBeginContainer** function several times before you call the **GdipEndContainer** function. Each time you call the **GdipBeginContainer** function, an information block is put on the stack, and you receive an identifier for the information block. When you pass one of those identifiers to the **GdipEndContainer** function, the **Graphics** object is returned to the state it was in at the time of the **GdipBeginContainer** call that returned that particular identifier. The information block placed on the stack by that **GdipBeginContainer** call is removed from the stack, and all information blocks placed on that stack after that **GdipBeginContainer** call are also removed.

Calls to the **GdipSaveGraphics** function place information blocks on the same stack as calls to the **GdipBeginContainer** function. Just as an **GdipEndContainer** call is paired with a **GdipBeginContainer** call, a **GdipRestoreGraphics** call is paired with a **GdipSaveGraphics** call.

**Caution**: When you call **GdipEndContainer**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipBeginContainerare** removed from the stack. Likewise, when you call **GdipRestoreGraphics**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipSaveGraphics** are removed from the stack.

For more information about graphics containers, see [Nested Graphics Containers](https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-nested-graphics-containers-use).

#### Example

```
' ========================================================================================
' This example demonstrates how to use GdipBeginContainer and GdipEndContainer
' to isolate transformations and rendering settings within a scoped graphics container.
' ========================================================================================
SUB Example_BeginContainer (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Draw a base rectangle (no transformation)
   DIM basePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2.0, UnitWorld, @basePen)
   hStatus = GdipDrawRectangle(graphics, basePen, 20, 20, 100, 50)

   ' // Begin container
   DIM container AS GraphicsContainer
   hStatus = GdipBeginContainer2(graphics, @container)

   ' // Apply transformation inside container
   hStatus = GdipTranslateWorldTransform(graphics, 150, 0, MatrixOrderPrepend)
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderAppend)

   ' // Draw transformed rectangle
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 2.0, UnitWorld, @redPen)
   hStatus = GdipDrawRectangle(graphics, redPen, 20, 20, 100, 50)

   ' // End container (restores previous state)
   hStatus = GdipEndContainer(graphics, container)

   ' // Draw another rectangle (back to original state)
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 2.0, UnitWorld, @bluePen)
   hStatus = GdipDrawRectangle(graphics, bluePen, 20, 90, 100, 50)

   ' // Cleanup
   IF basePen THEN GdipDeletePen(basePen)
   IF redPen THEN GdipDeletePen(redPen)
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipBeginContainer2

Begins a new graphics container. It is a variation of **GdipBeginContainer**.

```
FUNCTION GdipBeginContainer2 (BYVAL graphics AS GpGraphics PTR, BYVAL state AS GraphicsContainer PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *state* | [out] Pointer to a **GraphicsContainer** object variable that receives a value that identifies the container. |

#### Example

```
' ========================================================================================
' This example demonstrates how to use GdipBeginContainer and GdipEndContainer
' to isolate transformations and rendering settings within a scoped graphics container.
' ========================================================================================
SUB Example_BeginContainer2 (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Draw base rectangle
   DIM basePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2.0, UnitWorld, @basePen)
   hStatus = GdipDrawRectangle(graphics, basePen, 20, 20, 100, 50)

   ' // Begin container using GdipBeginContainer2
   DIM container AS GraphicsContainer
   hStatus = GdipBeginContainer2(graphics, @container)

   ' // Apply transformation inside container
   hStatus = GdipTranslateWorldTransform(graphics, 100, 100, MatrixOrderAppend)

   ' // Draw transformed rectangle
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 2.0, UnitWorld, @redPen)
   hStatus = GdipDrawRectangle(graphics, redPen, 20, 20, 100, 50)

   ' // End container (restores previous state)
   hStatus = GdipEndContainer(graphics, container)

   ' // Draw another rectangle (back to original state)
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 2.0, UnitWorld, @bluePen)
   hStatus = GdipDrawRectangle(graphics, bluePen, 20, 90, 100, 50)

   ' // Cleanup
   IF basePen THEN GdipDeletePen(basePen)
   IF redPen THEN GdipDeletePen(redPen)
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipComment

Adds a text comment to an existing metafile.

```
FUNCTION GdipComment (BYVAL graphics AS GpGraphics PTR, BYVAL sizeData AS UINT, _
   BYVAL byteDdata AS BYTE PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *sizeData* | [in] Integer that specifies the number of bytes in the value of the data parameter. |
| *byteData* | [in] Pointer to a buffer that contains the comment. |

#### Example

```
' ========================================================================================
' Adds a comment to a metafile
' ========================================================================================
SUB Example_GdipComment (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create an IStream to hold the metafile
   DIM stream AS IStream PTR
   hStatus = CreateStreamOnHGlobal(NULL, TRUE, @stream)
   IF hStatus <> 0 OR stream = NULL THEN
      PRINT "Failed to create stream."
      EXIT SUB
   END IF

   ' // Define frame rectangle for the metafile
   DIM rcfFrame AS GpRectF = (0.0, 0.0, 400.0, 300.0)

   ' Record metafile into stream
   DIM description AS WSTRING * 64 = "Metafile with Comment"
   DIM metafile AS GpMetafile PTR
   hStatus = GdipRecordMetafileStream(stream, hdc, EmfTypeEmfPlusOnly, @rcfFrame, _
                                      MetafileFrameUnitPixel, @description, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      PRINT "Failed to record metafile: "; hStatus
      stream->lpvtbl->Release(stream)
      EXIT SUB
   END IF

   ' // Create graphics object for recording
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)
   IF hStatus <> 0 OR graphics = NULL THEN
      PRINT "Failed to get graphics context: "; hStatus
      GdipDisposeImage(metafile)
      stream->lpvtbl->Release(stream)
      EXIT SUB
   END IF

   ' // Draw something into the metafile
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_GREEN, 4.0, UnitPixel, @pen)
   hStatus = GdipDrawEllipse(graphics, pen, 50, 50, 200, 150)

   ' // Add a comment to the metafile
   DIM commentText AS STRING = "This is a custom embedded comment"
   hStatus = GdipComment(graphics, LEN(commentText), STRPTR(commentText))
   IF hStatus = StatusOk THEN
      AfxMsg "Comment added successfully."
   ELSE
      AfxMsg "Failed to add comment: hStatus: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)
   IF stream THEN stream->lpvtbl->Release(stream)

END SUB
' ========================================================================================
```
---

## GdipCreateFromHDC

Creates a **Graphics** object that is associated with a specified device context.

```
FUNCTION GdipCreateFromHDC (BYVAL hdc AS HDC, BYVAL graphics AS GpGraphics PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hdc* | [in] Handle to a device context that will be associated with the new **Graphics** object. |
| *graphics* | [out] Pointer to a **GpGraphics** object variable that receives a pointer to the new created **Graphics** object. |

#### Remarks

When you use this function to create a **Graphics** object, make sure that the **Graphics** object is deleted before the device context is released.

#### Example

```
' // Create a graphics object from the device context
DIM graphics AS GpGraphics PTR
DIM hStatus ASLONG = GdipCreateFromHDC(hdc, @graphics)
```
---

## GdipCreateFromHDC2

Creates a **Graphics** object that is associated with a specified device context and a specified device handle.

```
FUNCTION GdipCreateFromHDC2 (BYVAL hdc AS HDC, BYVAL hDevice AS HANDLE, _
   BYVAL graphics AS GpGraphics PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hdc* | [in] Handle to a device context that will be associated with the new **Graphics** object. |
| *hdevice* | [in] Handle to a device that will be associated with the new Graphics object (e.g., printer or display surface). |
| *graphics* | [out] Pointer to a **GpGraphics** object variable that receives a pointer to the new created **Graphics** object. |

#### Remarks

When you use this function to create a **Graphics** object, make sure that the **Graphics** object is deleted before the device context is released.

#### Example

```
' ========================================================================================
' This example demonstrates how to use GdipCreateFromHDC2 with a device handle,
' and how to create a bitmap from a graphics object for off-screen rendering.
' ========================================================================================
SUB Example_CreateFromHDC2 (BYVAL hdc AS HDC)

   DIM hStatus AS LONG
   DIM graphics AS GpGraphics PTR

   DIM hPrinter AS HANDLE
   DIM printerName AS WSTRING * 128 = "Microsoft Print to PDF"
   IF OpenPrinter(printerName, @hPrinter, NULL) = FALSE THEN EXIT SUB

   ' // Create graphics object using HDC and device handle
   hStatus = GdipCreateFromHDC2(hdc, hPrinter, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a bitmap from the graphics object
   DIM bitmap AS GpBitmap PTR
   hStatus = GdipCreateBitmapFromGraphics(300, 200, graphics, @bitmap)

   ' // Create a graphics object from the bitmap
   DIM bmpGraphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(bitmap, @bmpGraphics)

   ' // Draw something on the bitmap
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_GREEN, @brush)
   hStatus = GdipFillRectangle(bmpGraphics, brush, 50, 50, 200, 100)

   ' // Save the bitmap as a .png
   DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/png")  ' Helper function to get PNG encoder
   GdipSaveImageToFile(bitmap, "output.png", @clsid, NULL)

   ' // Close the printer object
   IF hPrinter THEN ClosePrinter(hPrinter)

   ' // Draw message on the window
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   IF hStatus = StatusOk THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPoint, @font)
      GdipDeleteFontFamily(fontFamily)
   END IF

   DIM textBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @textBrush)

   DIM rcf AS GpRectF
   rcf.x = 50 : rcf.y = 80 : rcf.Width = 350 : rcf.Height = 90
   DIM wszText AS WSTRING * 128 = "Image saved to output.png"
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, NULL, textBrush)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF bmpGraphics THEN GdipDeleteGraphics(bmpGraphics)
   IF bitmap THEN GdipDisposeImage(bitmap)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipCreateFromHWND

Creates a **Graphics** object that is associated with a specified window.

```
FUNCTION GdipCreateFromHWND (BYVAL hwnd AS HWND, BYVAL graphics AS GpGraphics PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | [in] Handle to a window that will be associated with the new **Graphics** object. |
| *graphics* | [out] Pointer to a **GpGraphics** object variable that receives a pointer to the new created **Graphics** object. |

---

## GdipCreateFromHWNDICM

Creates a **Graphics** object that is associated with a specified window. It explicitly enables Image Color Management (ICM) for accurate color representation.

```
FUNCTION GdipCreateFromHWNDICM (BYVAL hwnd AS HWND, BYVAL graphics AS GpGraphics PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | [in] Handle to a window that will be associated with the new **Graphics** object. |
| *graphics* | [out] Pointer to a **GpGraphics** object variable that receives a pointer to the new created **Graphics** object. |

---

## GdipCreateHalftonePalette

Gets a Windows halftone palette.

```
FUNCTION GdipCreateHalftonePalette () AS HPALETTE
```

#### Return value

Returns a handle to a Windows halftone palette.

#### Remarks

The purpose of the **GdipCreateHalftonePalette** function is to enable GDI+ to produce a better quality halftone when the display uses 8 bits per pixel. To display an image using the halftone palette, use the following procedure:

1. Call **GdipCreateHalftonePalette** to get a GDI+ halftone palette.
2. Select the halftone palette into a device context.
3. Realize the palette by calling the **RealizePalette** function.
4. Construct a **Graphics** object from a handle to the device context.
5. Call one of the **GdipDrawImage** functions of the **Graphics** object.

Be sure to delete the palette when you have finished using it. If you do not follow the preceding procedure, then on an 8-bits-per-pixel-display device, the default, 16-color process is used, which results in a lesser quality halftone.

#### Example

```
' ========================================================================================
' The following example draws the same image twice. Before the image is drawn the second
' time, the code gets a halftone palette, selects the palette into a device context, and
' realizes the palette.
' ========================================================================================
SUB Example_HalfTonePalette (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Load image from file
   DIM image AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Draw image at (10, 10)
   hStatus = GdipDrawImage(graphics, image, 10, 10)

'   ' // Get halftone palette
   DIM hPalette AS HPALETTE
   hPalette = GdipCreateHalftonePalette

   ' // Apply palette to HDC
   SelectPalette(hdc, hPalette, FALSE)
   RealizePalette(hdc)

   ' // Create second graphics object and draw image again
   DIM graphics2 AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics2)
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics2, rxRatio, ryRatio, MatrixOrderPrepend)
   ' // Draw the image
   hStatus = GdipDrawImage(graphics2, image, 210, 10)

'   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF graphics2 THEN GdipDeleteGraphics(graphics2)
   IF image THEN GdipDisposeImage(image)
   IF hPalette THEN DeleteObject(hPalette)
   
END SUB
' ========================================================================================
```
---

## GdipCreateMetafileFromEmf

Creates a Microsoft Windows GDI+ Metafile object for playback based on a Windows Graphics Device Interface (GDI) Enhanced Metafile (EMF) file.

```
FUNCTION GdipCreateMetafileFromEmf (BYVAL hEmf AS HENHMETAFILE, BYVAL deleteEmf AS BOOL, _
   BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hEmf* | [in] Windows handle to a metafile. |
| *deleteEmf* | [in] Boolean value that specifies whether the Windows handle to a metafile is deleted when the **Metafile** object is deleted. TRUE specifies that the *hEmf* Windows handle is deleted, and FALSE specifies that the *hEmf* Windows handle is not deleted. The default value is FALSE. |
| *metafile* | [out] Pointer to a **GpMetafile** object variable that receives a pointer to the new created **Metafile** object. |

#### Example

```
' ========================================================================================
' Creates a metafile object for playback.Creates a Microsoft Windows GDI+ Metafile object
' for playback based on a Windows Graphics Device Interface (GDI) Enhanced Metafile (EMF) file.
' ========================================================================================
SUB Example_CreateMetafileFromEmf (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96

   ' Load an existing EMF file using GDI
   DIM hEmf AS HENHMETAFILE
   hEmf = GetEnhMetaFile("EMF13.emf")

   ' // Create a GDI+ Metafile object from the EMF handle
   DIM metafile AS GpMetafile PTR
   hStatus = GdipCreateMetafileFromEmf(hEmf, FALSE, @metafile)
   
   ' // Draw the metafile at a specified location
   hStatus = GdipDrawImage(graphics, metafile, 40 * rxRatio, 30 * ryRatio)

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)
   IF hEmf THEN DeleteEnhMetaFile(hEmf)

END SUB
' ========================================================================================
```
---

## GdipCreateMetafileFromFile

Creates a **Metafile** object for playback.

```
FUNCTION GdipCreateMetafileFromFile (BYVAL fileName AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *fileName* | [in] Pointer to a wide-character string that specifies the name of an existing disk file used to create the **Metafile** object for playback. |
| *metafile* | [out] Pointer to a **GpMetafile** object variable that receives a pointer to the new created **Metafile** object. |

#### Example

```
' ========================================================================================
' Creates a metafile object for playback.
' ========================================================================================
SUB Example_CreateMetafileFromFile (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96

   ' // Load the metafile from disk
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(filename, @metafile)
   
   ' // Draw the image
   hStatus = GdipDrawImage(graphics, metafile, 60 * rxRatio, 10 * ryRatio)

   ' // Cleanup
   IF metafile THEN GdipDisposeImage(metafile)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipCreateMetafileFromStream

Creates a **Metafile** object from an **IStream** interface for playback.

```
FUNCTION GdipCreateMetafileFromStream (BYVAL stream AS IStream PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```
| Parameter  | Description |
| ---------- | ----------- |
| *stream* | [in] Pointer to a Component Object Model (COM) IStream interface that points to a data stream in a file. |
| *metafile* | [out] Pointer to a **GpMetafile** object variable that receives a pointer to the new created **Metafile** object. |

#### Example

**GdipCreateStreamOnFile** returns error 6 (not implemented) in some versions of Windows(e.g. Windows 10). In the example we are using **SHCreateStreamOnFile** as an alternative.

```
' ========================================================================================
SUB Example_CreateMetafileFromStream (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96

   ' // Create IStream from file
   DIM stream AS IStream PTR
   DIM hr AS HRESULT = SHCreateStreamOnFile("SampleMetafile.emf", STGM_READ, @stream)
   IF hr <> S_OK OR stream = NULL THEN
      AfxMsg "Failed to create stream from file. hr = " & HEX(hr)
      EXIT SUB
   END IF

   ' // Create Metafile from stream
   DIM metafile AS GpMetafile PTR
   hStatus = GdipCreateMetafileFromStream(stream, @metafile)
   IF hStatus <> 0 THEN
      AfxMsg "Failed to create metafile from stream: " & STR(hStatus)
      stream->lpvtbl->Release(stream)
      EXIT SUB
   END IF

   ' // Draw the metafile
   hStatus = GdipDrawImage(graphics, metafile, 50.0, 50.0)

   ' // Cleanup
   IF metafile THEN GdipDisposeImage(metafile)
   IF stream THEN stream->lpvtbl->Release(stream)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipCreateMetafileFromWmf

Creates a Microsoft Windows GDI+ **Metafile** object for recording. The format will be placeable metafile.

```
FUNCTION GdipCreateMetafileFromWmf (BYVAL hWmf AS HMETAFILE, BYVAL deleteWmf AS BOOL, _
   BYVAL wmfPlaceableFileHeader AS WmfPlaceableFileHeader PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWmf* | [in] Windows handle to a metafile. |
| *deleteWmf* | [in] Boolean value that specifies whether the Windows handle to a metafile is deleted when the metafile is deleted. TRUE specifies that the *hWmf* Windows handle is deleted, and FALSE specifies that the *hWmf* Windows handle is not deleted. The default value is FALSE.|
| *wmfPlaceableFileHeader* | [in] Pointer to a **WmfPlaceableFileHeader** structure that specifies a preheader preceding the metafile header. |
| *metafile* | [out] Pointer to a **GpMetafile** object variable that receives a pointer to the new created **Metafile** object. |

---

## GdipCreateMetafileFromWmfFile

Creates a Microsoft Windows GDI+ **Metafile** object for playback.

```
FUNCTION GdipCreateMetafileFromWmfFile (BYVAL fileName AS WSTRING PTR, _
   BYVAL wmfPlaceableFileHeader AS WmfPlaceableFileHeader PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *fileName* | [in] Pointer to a null-terminated unicode string that specifies the name of an existing disk file used to create the Metafile object for playback. |
| *wmfPlaceableFileHeader* | [in] Pointer to a **WmfPlaceableFileHeader** structure that specifies a preheader preceding the metafile header. |
| *metafile* | [out] Pointer to a **GpMetafile** object variable that receives a pointer to the new created **Metafile** object. |

#### Remarks

Placeable metafiles are WMF files that contain a preheader preceding the metafile header. The preheader contains additional information for the metafile header of the metafile.

---

## GdipCreateStreamOnFile

Returns a pointer to an **IStream** interface based on a file. The filename parameter specifies the file. The access parameter is a set of flags that must include GENERIC_READ or GENERIC_WRITE. The stream parameter receives a pointer to the **IStream** interface.

```
FUNCTION GdipCreateStreamOnFile (BYVAL fileName AS WSTRING PTR, _
   BYVAL access AS UINT, BYVAL stream AS IStream PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *fileName* | [in] Pointer to a null-terminated unicode string that specifies the name of a file. |
| *access* | [in] Set of flags that must include GENERIC_READ or GENERIC_WRITE. |
| *stream* | [out] Pointer to a variable that receives a pointer to the **IStream** interface. |

#### Remarks

**GdipCreateStreamOnFile** returns error 6 (not implemented) in some versions of Windows(e.g. Windows 10). You can use **SHCreateStreamOnFile** as an alternative.

---

## GdipDeleteGraphics

Deletes the specified **Graphics** object.

```
FUNCTION GdipDeleteGraphics (BYVAL graphics AS GpGraphics PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |

#### Usage example

```
IF graphics THEN GdipDeleteGraphics(graphics)
```
---

## GdipDrawArc

Draws an arc. The arc is part of an ellipse.

```
FUNCTION GdipDrawArc (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, BYVAL x AS REAL, _
   BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL, BYVAL startAngle AS REAL, _
   BYVAL sweepAngle AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawArcI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, BYVAL x AS INT_, _
   BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_, BYVAL startAngle AS REAL, _
   BYVAL sweepAngle AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier spline. |
| *x* | [in] The x-coordinate of the upper-left corner of the bounding rectangle for the ellipse that contains the arc. |
| *y* | [in] The y-coordinate of the upper-left corner of the bounding rectangle for the ellipse that contains the arc. |
| *nWidth* | [in] The width of the ellipse that contains the arc. |
| *nHeight* | [in] The height of the ellipse that contains the arc. |
| *startAngle* | [in] The angle between the x-axis and the starting point of the arc. |
| *sweepAngle* | [in] The angle between the starting and ending points of the arc. |

#### Example

```
' ========================================================================================
' The following example draws a 90-degree arc.
' ========================================================================================
SUB Example_DrawArc (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a red Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 3, UnitWorld, @pen)

   ' // Draw the arc
   hStatus = GdipDrawArc(graphics, pen, 0, 0, 200, 100, 0, 90)

   ' // Cleanup
   IF pen THEN GdipDeleteBrush(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawBezier

Draws a Bezier spline.

```
FUNCTION GdipDrawBezier (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, BYVAL x1 AS REAL, _
   BYVAL y1 AS REAL, BYVAL x2 AS REAL, BYVAL y2 AS REAL, BYVAL x3 AS REAL, BYVAL y3 AS REAL, _
   BYVAL x4 AS REAL, BYVAL y4 AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawBezierI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, BYVAL x1 AS INT_, _
   BYVAL y1 AS INT_, BYVAL x2 AS INT_, BYVAL y2 AS INT_, BYVAL x3 AS INT_, BYVAL y3 AS INT_, _
   BYVAL x4 AS INT_, BYVAL y4 AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *GpGraphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier spline. |
| *x1* | [in] The x-coordinate of the starting point of the Bezier spline. |
| *y1* | [in] The y-coordinate of the starting point of the Bezier spline. |
| *x2* | [in] The x-coordinate of the first control point of the Bezier spline. |
| *y2* | [in] The y-coordinate of the first control point of the Bezier spline. |
| *x3* | [in] The x-coordinate of the second control point of the Bezier spline. |
| *y3* | [in] The y-coordinate of the second control point of the Bezier spline. |
| *x4* | [in] The x-coordinate of the ending point of the Bezier spline. |
| *y4* | [in] The y-coordinate of the ending point of the Bezier spline. |

#### Remarks

A Bezier spline does not pass through its control points. The control points act as magnets, pulling the curve in certain directions to influence the way the Bezier spline bends.

#### Example

```
' ========================================================================================
' The following example draws a Bézier curve.
' ========================================================================================
SUB Example_DrawBezier (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 1, UnitWorld, @greenPen)

   DIM AS SINGLE startPointx, startPointy, ctrlPoint1x, ctrlPoint1y, ctrlPoint2x, ctrlPoint2y, endPointx, endPointy
   startPointx = 100
   startPointy = 100
   ctrlPoint1x = 200
   ctrlPoint1y = 10
   ctrlPoint2x = 350
   ctrlPoint2y = 50
   endPointx = 500
   endPointy = 100

   ' // Draw the curve
   hStatus = GdipDrawBezier(graphics, greenPen, startPointx, startPointy, ctrlPoint1x, ctrlPoint1y, ctrlPoint2x, ctrlPoint2y, endPointx, endPointy)

   ' // Create the brushes
   DIM AS GpBrush PTR redBrush, blueBrush
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @blueBrush)

   ' // Draw the end points and control points.
   hStatus = GdipFillEllipse(graphics, redBrush, 100 - 5, 100 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 500 - 5, 100 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, blueBrush, 200 - 5, 10 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, blueBrush, 350 - 5, 50 - 5, 10, 10)

  ' // Cleanup
   IF blueBrush THEN GdipDeleteBrush(blueBrush)
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawBeziers

Draws a sequence of connected Bezier splines.

```
FUNCTION GdipDrawBeziers (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawBeziersI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier splines. |
| *points* | Pointer to an array of **GpPoint** objects that specify the starting, ending, and control points of the Bezier splines. The ending coordinate of one Bezier spline is the starting coordinate of the next Bezier spline. |
| *count* | [in] Number of elements in the *points* array. |

#### Remarks

A Bezier spline does not pass through its control points. The control points act as magnets, pulling the curve in certain directions to influence the way the Bezier splines bend.

#### Example

```
' ========================================================================================
' The following example draws a pair of Bézier curves.
' ========================================================================================
SUB Example_DrawBeziers (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 1, UnitWorld, @greenPen)

   DIM startPoint AS GpPointF = (100, 100)
   DIM ctrlPoint1 AS GpPointF = (200,  50)
   DIM ctrlPoint2 AS GpPointF = (400,  10)
   DIM endPoint1  AS GpPointF = (500, 100)
   DIM ctrlPoint3 AS GpPointF = (600, 200)
   DIM ctrlPoint4 AS GpPointF = (700, 400)
   DIM endPoint2  AS GpPointF = (500, 500)

   DIM curvePoints(6) AS GpPointF
   curvePoints(0) = startPoint
   curvePoints(1) = ctrlPoint1
   curvePoints(2) = ctrlPoint2
   curvePoints(3) = endPoint1
   curvePoints(4) = ctrlPoint3
   curvePoints(5) = ctrlPoint4
   curvePoints(6) = endPoint2

   ' // Draw the Bézier curves
   hStatus = GdipDrawBeziers(graphics, greenPen, @curvePoints(0), 7)

   ' // Create the brushes
   DIM AS GpBrush PTR redBrush, blueBrush
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @blueBrush)

   ' //Draw the end points and control points.
   hStatus = GdipFillEllipse(graphics, redBrush, 100 - 5, 100 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 500 - 5, 100 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 500 - 5, 500 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, blueBrush, 200 - 5, 50 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, blueBrush, 400 - 5, 10 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, blueBrush, 600 - 5, 200 - 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, blueBrush, 700 - 5, 400 - 5, 10, 10)

   ' // Cleanup
   IF blueBrush THEN GdipDeleteBrush(blueBrush)
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawClosedCurve

Draws a closed cardinal spline.

```
FUNCTION GdipDrawClosedCurve (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawClosedCurve (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier splines. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the coordinates of the closed cardinal spline. The array of **GpPoint** structures must contain a minimum of three elements. |
| *count* | [in] Number of elements in the *points* array. |

### Remarks

Each ending point is the starting point for the next cardinal spline. In a closed cardinal spline, the curve continues through the last point in the points array and connects with the first point in the array.

---

## GdipDrawClosedCurve2

Draws a closed cardinal spline.

```
FUNCTION GdipDrawClosedCurve2 (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_, BYVAL tension AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawClosedCurve2I (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_, BYVAL tension AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier splines. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the coordinates of the closed cardinal spline. The array of PointF structures must contain a minimum of three elements. |
| *count* | [in] Number of elements in the *points* array. |
| *tension* | [in] Simple precision value that specifies how tightly the curve bends though the coordinates of the closed cardinal spline. |

### Remarks

Each ending point is the starting point for the next cardinal spline. In a closed cardinal spline, the curve continues through the last point in the points array and connects with the first point in the array.
#### Example

```
' ========================================================================================
' The following example draws a closed cardinal spline.
' ========================================================================================
SUB Example_DrawClosedCurve (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 3, UnitWorld, @greenPen)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200,  50)
   DIM point3 AS GpPointF = (400,  10)
   DIM point4 AS GpPointF = (500, 100)
   DIM point5 AS GpPointF = (600, 200)
   DIM point6 AS GpPointF = (700, 400)
   DIM point7 AS GpPointF = (500, 500)

   DIM curvePoints(6) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4
   curvePoints(4) = point5
   curvePoints(5) = point6
   curvePoints(6) = point7

   ' // Draw the closed curve
   hStatus = GdipDrawClosedCurve2(graphics, greenPen, @curvePoints(0), 7, 1.0)

   ' // Create the brush
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)

   ' //Draw the points in the curve
   hStatus = GdipFillEllipse(graphics, redBrush, 95, 95, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 495, 95, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 495, 495, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 195, 45, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 395, 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 595, 195, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 695, 395, 10, 10)

   ' // Cleanup
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawCurve

Draws a cardinal spline.

```
FUNCTION GdipDrawCurve (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawCurveI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier splines. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the coordinates that the cardinal spline passes through. |
| *count* | [in] Number of elements in the *points* array. |

#### Remarks

A segment is defined as a curve that connects two consecutive points in the cardinal spline. The ending point of each segment is the starting point for the next.

#### Example:

```
' ========================================================================================
' The following example draws a cardinal spline.
' ========================================================================================
SUB Example_DrawCurve (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 3, UnitWorld, @greenPen)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200, 50)
   DIM point3 AS GpPointF = (400, 10)
   DIM point4 AS GpPointF = (500, 100)

   DIM curvePoints(3) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4

   ' // Specify offset, number of segments to draw, and tension.
   DIM offset AS LONG = 1
   DIM segments AS LONG = 2
   DIM tension AS SINGLE = 1.0

   ' // Draw the curve
   hStatus = GdipDrawCurve(graphics, greenPen, @curvePoints(0), 4)

   ' // Create the brush
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)

   ' // Draw the points in the curve
   hStatus = GdipFillEllipse(graphics, redBrush, 95, 95, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 195, 45, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 395, 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 495, 95, 10, 10)

   ' // Cleanup
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

#### Example

```
' ========================================================================================
' The following example draws a cardinal spline and adds labels to each point.
' ========================================================================================
SUB Example_DrawCurveWithLabels (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 3, UnitWorld, @greenPen)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200, 50)
   DIM point3 AS GpPointF = (400, 30)
   DIM point4 AS GpPointF = (500, 100)

   DIM curvePoints(3) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4

   ' // Specify offset, number of segments to draw, and tension.
   DIM offset AS LONG = 1
   DIM segments AS LONG = 2
   DIM tension AS SINGLE = 1.0

   ' // Draw the curve
   hStatus = GdipDrawCurve(graphics, greenPen, @curvePoints(0), 4)

   ' // Create the brush
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)

   ' // Draw the points in the curve
   hStatus = GdipFillEllipse(graphics, redBrush, 95, 95, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 195, 45, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 395, 25, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 495, 95, 10, 10)

   ' // Create a font family and font
   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   DIM labelBrush AS GpBrush PTR
   DIM layoutRect AS GpRectF
   DIM label AS WSTRING * 32

   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPixel, @font)
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @labelBrush)

   ' // Label each point
   FOR i AS INTEGER = 0 TO 3
      label = "P" & STR(i)
      layoutRect.x = curvePoints(i).x + 10
      layoutRect.y = curvePoints(i).y - 10
      layoutRect.Width = 50
      layoutRect.Height = 20
      hStatus = GdipDrawString(graphics, @label, -1, font, @layoutRect, NULL, labelBrush)
   NEXT

   ' // Cleanup
   IF labelBrush THEN GdipDeleteBrush(labelBrush)
   IF font THEN GdipDeleteFont(font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawCurve2

Draws a cardinal spline.

```
FUNCTION GdipDrawCurve2 (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_, BYVAL tension AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawCurve2I (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_, BYVAL tension AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier splines. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the coordinates that the cardinal spline passes through. |
| *count* | [in] Number of elements in the *points* array. |
| *tension* | [in] Simple precision value that specifies how tightly the curve bends though the coordinates of the cardinal spline. |

#### Remarks

A segment is defined as a curve that connects two consecutive points in the cardinal spline. The ending point of each segment is the starting point for the next.

#### Example
```
' ========================================================================================
' The following example draws a cardinal spline.
' ========================================================================================
SUB Example_DrawCurve2 (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 3, UnitWorld, @greenPen)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200, 50)
   DIM point3 AS GpPointF = (400, 30)
   DIM point4 AS GpPointF = (500, 100)

   DIM curvePoints(3) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4

   ' // Draw a curve with high tension to show sharper bends
   ' // Demonstrates how the tension parameter affects the curvature
   DIM tension AS SINGLE = 2.0
   hStatus = GdipDrawCurve2(graphics, greenPen, @curvePoints(0), 4, tension)

   ' // Create the brush
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)

   ' // Draw the points in the curve
   hStatus = GdipFillEllipse(graphics, redBrush, 95, 95, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 195, 45, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 395, 25, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 495, 95, 10, 10)

   ' // Cleanup
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawCurve3

Draws a cardinal spline.

```
FUNCTION GdipDrawCurve3 (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_, BYVAL offset AS INT_, _
   BYVAL numberOfSegments AS INT_, BYVAL tension AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawCurve3I (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_, BYVAL offset AS INT_, _
   BYVAL numberOfSegments AS INT_, BYVAL tension AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the Bezier splines. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the coordinates that the cardinal spline passes through. |
| *count* | [in] Number of elements in the *points* array. |
| *offset* | [in] Long integer value that specifies the element in the points array that specifies the point at which the cardinal spline begins. |
| *numberOfSegments* | [in] Integer that specifies the number of segments in the cardinal spline. |
| *tension* | [in] Simple precision value that specifies how tightly the curve bends though the coordinates of the cardinal spline. |

#### Remarks

A segment is defined as a curve that connects two consecutive points in the cardinal spline. The ending point of each segment is the starting point for the next. The *numberOfSegments* parameter must not be greater than the count parameter minus the offset parameter plus one.

#### Example

```
' ========================================================================================
' The following example draws a cardinal spline.
' ========================================================================================
SUB Example_DrawCurve3 (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a green Pen
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 3, UnitWorld, @greenPen)

   DIM point1 AS GpPointF = (100, 100)
   DIM point2 AS GpPointF = (200, 50)
   DIM point3 AS GpPointF = (400, 10)
   DIM point4 AS GpPointF = (500, 100)

   DIM curvePoints(3) AS GpPointF
   curvePoints(0) = point1
   curvePoints(1) = point2
   curvePoints(2) = point3
   curvePoints(3) = point4

   ' // Draws only part of the curve using offset and segment count
   ' // This shows how to isolate a portion of the curve
   DIM offset AS LONG = 1
   DIM segments AS LONG = 2
   DIM tension AS SINGLE = 0.5
   hStatus = GdipDrawCurve3(graphics, greenPen, @curvePoints(0), 4, offset, segments, tension)

   ' // Create the brush
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)

   ' // Draw the points in the curve
   hStatus = GdipFillEllipse(graphics, redBrush, 95, 95, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 195, 45, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 395, 5, 10, 10)
   hStatus = GdipFillEllipse(graphics, redBrush, 495, 95, 10, 10)

   ' // Cleanup
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawEllipse

Draws an ellipse.

```
FUNCTION GdipDrawEllipse (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawEllipseI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the ellipse. |
| *x* | [in] The x-coordinate of the upper-left corner of the rectangle that bounds the ellipse. |
| *y* | [in] The y-coordinate of the upper-left corner of the rectangle that bounds the ellipse.  |
| *nWidth* | [in] The width of the rectangle that bounds the ellipse. |
| *nHeight* | [in] The height of the rectangle that bounds the ellipse. |

#### Example

```
' ========================================================================================
' The following example draws an ellipse.
' ========================================================================================
SUB Example_DrawEllipse (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a blue Pen
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1, UnitWorld, @bluePen)

   ' // Initialize the variables that define the ellipse.
   DIM x AS SINGLE = 90.0
   DIM y AS SINGLE = 60.0
   DIM nWidth AS SINGLE = 200.0
   DIM nHeight AS SINGLE = 100.0

   ' // Draw the ellipse
   hStatus = GdipDrawEllipse(graphics, bluePen, x, y, nWidth, nHeight)

   ' // Cleanup
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImage

Draws an image at a specified location.

```
FUNCTION GdipDrawImage (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawImageI (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *x* | [in] The x-coordinate of the upper-left corner of the rendered image. |
| *y* | [in] The y-coordinate of the upper-left corner of the rendered image. |

```
' ========================================================================================
' The following example draws an image with its upper-left corner at (10, 10).
' ========================================================================================
SUB Example_DrawImage (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the Image object
   DIM image AS GpImage PTR
   DIM wszFileName AS WSTRING * 260 = "climber.jpg"
   hStatus = GdipLoadImageFromFile(wszFileName, @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Draw the image
   hStatus = GdipDrawImage(graphics, image, 10, 10)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImageFX

Draws a portion of an image after applying a specified effect.

```
FUNCTION GdipDrawImageFX (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL source AS GpRectF PTR, BYVAL xForm AS GpMatrix PTR, BYVAL effect AS GpEffect PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR, BYVAL srcUnit AS GpUnit) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *source* | [in] Pointer to a **GpRectF** object that specifies the portion of the image to be drawn. |
| *xForm* | [in] Pointer to a **Matrix** object that specifies the parallelogram in which the image portion is rendered. The destination parallelogram is calculated by applying the affine transformation stored in the matrix to the source rectangle. |
| *effect* | [in] Pointer to an **GpEffect** object that specifies an effect or adjustment (for example, a change in contrast) that is applied to the image before rendering. The image is not permanently altered by the effect. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments to be applied when the image is rendered. Can be NULL. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the source rectangle. |

#### Example

```
' ========================================================================================
' Draws a portion of an image after applying a specified effect.
' ========================================================================================
SUB Example_DrawImageFX (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Load image
   DIM image AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image)

   ' // Get image dimensions
   DIM nWidth AS UINT, nHeight AS UINT
   GdipGetImageWidth(image, @nWidth)
   GdipGetImageHeight(image, @nHeight)

   ' // Define source rectangle using actual image size
   DIM srcRect AS GpRectF = (0, 0, nWidth, nHeight)

   ' Create transformation matrix (scale and rotate)
   DIM matrix AS GpMatrix PTR
   hStatus = GdipCreateMatrix(@matrix)
   hStatus = GdipScaleMatrix(matrix, 1.5, 1.5, MatrixOrderAppend)
   hStatus = GdipRotateMatrix(matrix, 30.0, MatrixOrderAppend)

   ' Create blur effect
   DIM effect AS GpEffect PTR
   hStatus = GdipCreateEffect(BlurEffectGuid, @effect)
   DIM blurParams(0 TO 0) AS SINGLE = {5.0}  ' Radius
   hStatus = GdipSetEffectParameters(effect, @blurParams(0), SIZEOF(SINGLE))

   ' Draw image with effect
   hStatus = GdipDrawImageFX(graphics, image, @srcRect, matrix, effect, NULL, UnitPixel)
'   IF hStatus = StatusOk THEN
'      AfxMsg "Image drawn with blur effect."
'   ELSE
'      AfxMsg "Failed to draw image: " & WSTR(hStatus)
'   END IF

   ' // Cleanup
   IF effect THEN GdipDeleteEffect(effect)
   IF matrix THEN GdipDeleteMatrix(matrix)
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImagePointRect

Draws an image at a specified location.

```
FUNCTION GdipDrawImagePointRect (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL srcx AS REAL, BYVAL srcy AS REAL, _
   BYVAL srcwidth AS REAL, BYVAL srcheight AS REAL, BYVAL srcUnit AS GpUnit) AS GpStatus
```
```
FUNCTION GdipDrawImagePointRectI (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL srcx AS INT_, BYVAL srcy AS INT_, _
   BYVAL srcwidth AS INT_, BYVAL srcheight AS INT_, BYVAL srcUnit AS GpUnit) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *x* | [in] The x-coordinate of the upper-left corner of the rendered image. |
| *y* | [in] The y-coordinate of the upper-left corner of the rendered image. |
| *srcx* | [in] The x-coordinate of the upper-left corner of the portion of the source image to be drawn. |
| *srcy* | [in] The y-coordinate of the upper-left corner of the portion of the source image to be drawn. |
| *srcwidth* | [in] The width of the portion of the source image to be drawn. |
| *srcheight* | [in] The height of the portion of the source image to be drawn. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the image. The default value is *UnitPixel*. |

#### Example

```
' ========================================================================================
' The following example draws a portion of an image. The portion of the source image to be
' drawn is scaled to fit the rectangle.
' ========================================================================================
SUB Example_DrawImagePointRect (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the Image object
   DIM image AS GpImage PTR
   DIM wszFileName AS WSTRING * 260 = "climber.jpg"
   hStatus = GdipLoadImageFromFile(wszFileName, @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image, 10, 10)


   ' // Set up the location for the image and the portion of the source to draw.
   DIM x AS SINGLE = 200.0
   DIM y AS SINGLE = 30.0
   DIM srcx AS SINGLE = 70.0
   DIM srcy AS SINGLE = 20.0
   DIM srcwidth AS SINGLE = 100.0
   DIM srcheight AS SINGLE = 200.0
   DIM srcunit AS LONG = UnitPixel

   ' // Draw the image
   hStatus = GdipDrawImagePointRect(graphics, image, x, y, srcx, srcy, srcwidth, srcheight, srcunit)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImagePoints

Draws an image at a specified location.

```
FUNCTION GdipDrawImagePoints (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL dstpoints AS GpPointF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawImagePointsI (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL dstpoints AS GpPoint PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *dstpoints* | [in] Pointer to an array of **GpPoint** structures that specify the area, in a parallelogram, in which to draw the image. |
| *count* | [in] Long integer value that specifies the number of elements in the *destPoints* array. |

#### Remarks

The value of the *count* parameter must equal 3 to specify the coordinates of the upper-left corner, upper-right corner, and lower-left corner of the parallelogram. The coordinate of the lower-right corner is calculated using the three given coordinates, the width, and the height of the image. The image is scaled to fit the parallelogram.

#### Example

```
' ========================================================================================
' The following example draws an image using an array of destination points.
' ========================================================================================
SUB Example_DrawImagePoints (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the Image object
   DIM image AS GpImage PTR
   DIM wszFileName AS WSTRING * 260 = "climber.jpg"
   hStatus = GdipLoadImageFromFile(wszFileName, @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Create an array of GpPointF structures that specify the destination of the image.
   DIM destPoints(2) AS GpPointF
   destPoints(0).x = 30.0 : destPoints(0).y = 30.0
   destPoints(1).x = 250.0 : destPoints(1).y = 50.0
   destPoints(2).x = 175.0 : destPoints(2).y = 120.0

   ' // Draw the image
   hStatus = GdipDrawImagePoints(graphics, image, @destpoints(0), 3)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImagePointsRect

Draws an image at a specified location.

```
FUNCTION GdipDrawImagePointsRect (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_, BYVAL srcx AS REAL, BYVAL srcy AS REAL, _
   BYVAL srcwidth AS REAL, BYVAL srcheight AS REAL, BYVAL srcUnit AS GpUnit, _
   BYVAL imageAttributes AS GpImageAttributes PTR, BYVAL callback AS DrawImageAbort, _
   BYVAL callbackData AS VOID PTR) AS GpStatus
```
```
FUNCTION GdipDrawImagePointsRectI (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_, BYVAL srcx AS INT_, BYVAL srcy AS INT_, _
   BYVAL srcwidth AS INT_, BYVAL srcheight AS INT_, BYVAL srcUnit AS GpUnit, _
   BYVAL imageAttributes AS GpImageAttributes PTR, BYVAL callback AS DrawImageAbort, _
   BYVAL callbackData AS VOID PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the area, in a parallelogram, in which to draw the image. |
| *count* | [in] Long integer value that specifies the number of elements in the *Points* array. |
| *srcx* | [in] The x-coordinate of the upper-left corner of the portion of the source image to be drawn. |
| *srcy* | [in] The y-coordinate of the upper-left corner of the portion of the source image to be drawn. |
| *srcwidth* | [in] The width of the portion of the source image to be drawn. |
| *srcheight* | [in] The height of the portion of the source image to be drawn. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the image. The default value is *UnitPixel*. |
| *imageAttributes* | [in] Pointer to an **GpImageAttributes** structure that specifies the color and size attributes of the image to be drawn. The default value is NULL. |
| *callback* | [in] Callback method used to cancel the drawing in progress. The default value is NULL. |
| *callbackData* | [in] Pointer to additional data used by the method specified by the callback parameter. The default value is NULL. |

#### Remarks

The value of the *count* parameter must equal 3 to specify the coordinates of the upper-left corner, upper-right corner, and lower-left corner of the parallelogram. The coordinate of the lower-right corner is calculated using the three given coordinates, the width, and the height of the image. The portion of the source image to be drawn is scaled to fit the parallelogram.

#### Example

```
' ========================================================================================
' The following example draws the original source image and then draws a portion of the
' image in a specified parallelogram.
' ========================================================================================
SUB Example_DrawImagePointsRect (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the Image object
   DIM image AS GpImage PTR
   DIM wszFileName AS WSTRING * 260 = "pattern.png"
   hStatus = GdipLoadImageFromFile(wszFileName, @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image, 10, 10)

   ' // Define the portion of the image to draw.
   DIM srcX AS SINGLE = 70.0
   DIM srcY AS SINGLE = 20.0
   DIM srcwidth AS SINGLE = 100.0
   DIM srcheight AS SINGLE = 100.0

   ' // Create an array of GpPointF structures that specify the destination of the cropped image.
   DIM destPoints(2) AS GpPointF
   destPoints(0).x = 230.0 : destPoints(0).y = 30.0
   destPoints(1).x = 350.0 : destPoints(1).y = 50.0
   destPoints(2).x = 275.0 : destPoints(2).y = 120.0

   ' // Create an ImageAttributes object that specifies a recoloring from red to blue.
   DIM remapAttributes AS GpImageAttributes PTR
   hStatus = GdipCreateImageAttributes(@remapAttributes)
   DIM redToBlue AS GpColorMap
   redToBlue.oldColor = ARGB_RED
   redToBlue.newColor = ARGB_BLUE
   hStatus = GdipSetImageAttributesRemapTable(remapAttributes, ColorAdjustTypeDefault, TRUE, 1, @redToBlue)

   ' // Draw the cropped image
   hStatus = GdipDrawImagePointsRect(graphics, image, @destPoints(0), 3, srcx, srcy, _
             srcwidth, srcheight, UnitPixel, remapAttributes, NULL, NULL)

   ' // Cleanup
   IF remapAttributes THEN GdipDisposeImageAttributes(remapAttributes)
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImageRect

Draws an image at a specified location.

```
FUNCTION GdipDrawImageRect (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawImageRectI (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *x* | [in] The x-coordinate of the upper-left corner of the destination rectangle at which to draw the image. |
| *y* | [in] The y-coordinate of the upper-left corner of the destination rectangle at which to draw the image. |
| *nWidth* | [in] The width of the destination rectangle at which to draw the image. |
| *nHeight* | [in] The height of the destination rectangle at which to draw the image. |

#### Example

```
' ========================================================================================
' The following example draws the source image, the rectangle that bounds the resized image,
' and then draws the resized image to fit the rectangle.
' ========================================================================================
SUB Example_DrawImageRect (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the Image object
   DIM image AS GpImage PTR
   DIM wszFileName AS WSTRING * 260 = "climber.jpg"
   hStatus = GdipLoadImageFromFile(wszFileName, @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Create a red Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1.0, UnitWorld, @pen)

   ' // Draw the original source image.
   hStatus = GdipDrawImage(graphics, image, 10, 10)

   ' // Draw the rectangle that bounds the image.
   hStatus = GdipDrawRectangle(graphics, pen, 200, 50, 150, 75)

   ' // Draw the image
   hStatus = GdipDrawImageRect(graphics, image, 200 + 1, 50 + 1, 150 - 1, 75 - 1)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawImageRectRect

Draws an image at a specified location.

```
FUNCTION GdipDrawImageRectRect (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL dstx AS REAL, BYVAL dsty AS REAL, BYVAL dstwidth AS REAL, BYVAL dstheight AS REAL, _
   BYVAL srcx AS REAL, BYVAL srcy AS REAL, BYVAL srcwidth AS REAL, BYVAL srcheight AS REAL, _
   BYVAL srcUnit AS GpUnit, BYVAL imageAttributes AS GpImageAttributes PTR, _
   BYVAL callback AS DrawImageAbort, BYVAL callbackData AS VOID PTR) AS GpStatus
```
```
FUNCTION GdipDrawImageRectRectI (BYVAL graphics AS GpGraphics PTR, BYVAL image AS GpImage PTR, _
   BYVAL dstx AS INT_, BYVAL dsty AS INT_, BYVAL dstwidth AS INT_, BYVAL dstheight AS INT_, _
   BYVAL srcx AS INT_, BYVAL srcy AS INT_, BYVAL srcwidth AS INT_, BYVAL srcheight AS INT_, _
   BYVAL srcUnit AS GpUnit, BYVAL imageAttributes AS GpImageAttributes PTR, _
   BYVAL callback AS DrawImageAbort, BYVAL callbackData AS VOID PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *image* | [in] Pointer to an Image object that specifies the image to be drawn. |
| *dstx* | [in] The x-coordinate of the upper-left corner of the drawing area for the image. |
| *dsty* | [in] The y-coordinate of the upper-left corner of the drawing area for the image. |
| *dstwidth* | [in] The width of the drawing area to be drawn. |
| *dstheight* | [in] The height of the drawing area to be drawn. |
| *srcx* | [in] The width of the portion of the source image to be drawn. |
| *srcy* | [in] The height of the portion of the source image to be drawn. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the image. The default value is *UnitPixel*. |
| *imageAttributes* | [in] Pointer to an **GpImageAttributes** structure that specifies the color and size attributes of the image to be drawn. The default value is NULL. |
| *callback* | [in] Callback method used to cancel the drawing in progress. The default value is NULL. |
| *callbackData* | [in] Pointer to additional data used by the method specified by the callback parameter. The default value is NULL. |

#### Remarks

The portion of the source image to be drawn is scaled to fit the rectangle.

#### Example

```
' ========================================================================================
' The following example draws the source image, the rectangle that bounds the resized image,
' and then draws the resized image to fit the rectangle.
' ========================================================================================
SUB Example_DrawImageRectRect (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the Image object
   DIM image AS GpImage PTR
   DIM wszFileName AS WSTRING * 260 = "climber.jpg"
   hStatus = GdipLoadImageFromFile(wszFileName, @image)
   hStatus = GdipBitmapSetResolution(image, dpiX, dpiY)

   ' // Create a red Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1.0, UnitWorld, @pen)

   ' // Draw the original source image.
   hStatus = GdipDrawImage(graphics, image, 10, 10)

   ' // Draw the rectangle that bounds the image.
   hStatus = GdipDrawRectangle(graphics, pen, 200, 50, 150, 75)

   ' // Draw the image
   hStatus = GdipDrawImageRect(graphics, image, 200 + 1, 50 + 1, 150 - 1, 75 - 1)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawLine

Draws a line that connects two points.

```
FUNCTION GdipDrawLine (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x1 AS REAL, BYVAL y1 AS REAL, BYVAL x2 AS REAL, BYVAL y2 AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawLine (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x1 AS INT_, BYVAL y1 AS INT_, BYVAL x2 AS INT_, BYVAL y2 AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the line. |
| *x1* | [in] The x-coordinate of the starting point of the line. |
| *y1* | [in] The y-coordinate of the starting point of the line. |
| *x2* | [in] The x-coordinate of the ending point of the line. |
| *y2* | [in] The y-coordinate of the ending point of the line. |

#### Example

```
' ========================================================================================
' The following example draws a line.
' ========================================================================================
SUB Example_DrawLine (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a blue Pen
   DIM blackPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 4, UnitWorld, @blackPen)

   ' // Initialize the coordinates of the points that define the line.
   DIM AS SINGLE x1, y1, x2, y2
   x1 = 100.0 : y1 = 100.0 : x2 = 300.0 : y2 = 100.0

   ' // Draw the line
   hStatus = GdipDrawLine(graphics, blackPen, x1, y1, x2, y2)

   ' // Cleanup
   IF blackPen THEN GdipDeletePen(blackPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawLines

Draws a sequence of connected lines.

```
FUNCTION GdipDrawLines (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawLinesI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the lines. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the starting and ending points of the lines. |
| *count* | [in] Long integer value that specifies the number of elements in the *points* array. |

#### Remarks

Each line requires a starting point and an ending point. The ending point of each line is the starting point for the next.

#### Example

```
' ========================================================================================
' The following example draws a sequence of connected lines.
' ========================================================================================
SUB Example_DrawLines (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a blue Pen
   DIM blackPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 4, UnitPixel, @blackPen)

   ' // Create an array of GpPointF objects that define the lines to draw.
   DIM point1 AS GpPointF = (10.0, 10.0)
   DIM point2 AS GpPointF = (10.0, 100.0)
   DIM point3 AS GpPointF = (200.0, 50.0)
   DIM point4 AS GpPointF = (250.0, 300.0)

   DIM points(3) AS GpPointF
   points(0) = point1
   points(1) = point2
   points(2) = point3
   points(3) = point4

   ' // Draw the lines
   hStatus = GdipDrawLines(graphics, blackPen, @points(0), 4)

   ' // Cleanup
   IF blackPen THEN GdipDeletePen(blackPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawPath

Draws a sequence of lines and curves defined by a **GraphicsPath** object.

```
FUNCTION GdipDrawPath (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL path AS GpPath PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the path. |
| *path* | [in] Pointer to a **GraphicsPath** object that specifies the sequence of lines and curves that make up the path. |

#### Example

```
' ========================================================================================
' The following example draws a GraphicsPath object.
' ========================================================================================
SUB Example_DrawPath (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a GraphicsPath object, and add an ellipse
   DIM ellipsePath AS GpPath PTR
   hStatus = GdipCreatePath(FillModeAlternate, @ellipsePath)
   hStatus = GdipAddPathEllipseI(ellipsePath, 100, 50, 200, 100)

   ' // Create a Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 3, UnitPixel, @pen)

   ' // Draw ellipsePath.
   hStatus = GdipDrawPath(graphics, pen, ellipsePath)

   ' // Cleanup
   IF ellipsePath THEN GdipDeletePath(ellipsePath)
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawPie

Draws a pie.

```
FUNCTION GdipDrawPie (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL, _
   BYVAL startAngle AS REAL, BYVAL sweepAngle AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawPieI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_, _
   BYVAL startAngle AS REAL, BYVAL sweepAngle AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the pie. |
| *x* | [in] The x-coordinate of the upper-left corner of the rectangle that bounds the ellipse in which to draw the pie. |
| *y* | [in] The y-coordinate of the upper-left corner of the rectangle that bounds the ellipse in which to draw the pie. |
| *nWidth* | [in] The width of the rectangle that bounds the ellipse in which to draw the pie. |
| *nHeight* | [in] The height of the rectangle that bounds the ellipse in which to draw the pie. |
| *startAngle* | [in] Simple precision value that specifies the angle, in degrees, between the x-axis and the starting point of the arc that defines the pie. A positive value specifies clockwise rotation. |
| *sweepAngle* | [in] [in] Simple precision value that specifies the angle, in degrees, between the starting and ending points of the arc that defines the pie. A positive value specifies clockwise rotation. |

#### Example

```
' ========================================================================================
' The following example draws a pie.
' ========================================================================================
SUB Example_DrawPie (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 3, UnitPixel, @pen)

   ' // Define the pie.
   DIM x AS SINGLE = 0.0
   DIM y AS SINGLE = 0.0
   DIM nWidth AS SINGLE = 200.0
   DIM nHeight AS SINGLE = 100.0
   DIM startAngle AS SINGLE = 0.0
   DIM sweepAngle AS SINGLE = 45.0

   ' // Draw the pie
   hStatus = GdipDrawPie(graphics, pen, x, y, nWidth, nHeight, startAngle, sweepAngle)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawPolygon

Draws a polygon.

```
FUNCTION GdipDrawPolygon (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPointF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawPolygonI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL points AS GpPoint PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the polygon. |
| *points* | [in] Pointer to an array of **GpPoint** structures that specify the vertices of the polygon. |
| *count* | [in] Long integer value that specifies the number of elements in the points array. |

#### Remarks

If the first and last coordinates in the points array are not identical, a line is drawn between them to close the polygon.

#### Example

```
' ========================================================================================
' The following example draws a polygon.
' ========================================================================================
SUB Example_DrawPolygon (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 3, UnitPixel, @pen)

   ' // Create an array of PointF objects that define the polygon.
   DIM points(4) AS GpPointF
   points(0).x = 100.0 : points(0).y = 100.0
   points(1).x = 200.0 : points(1).y = 130.0
   points(2).x = 150.0 : points(2).y = 200.0
   points(3).x = 50.0  : points(3).y = 200.0
   points(4).x = 0.0   : points(4).y = 130.0

   ' // Draw the polygon
   hStatus = GdipDrawPolygon(graphics, pen, @points(0), 5)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawRectangle

Draws a rectangle.

```
FUNCTION GdipDrawRectangle (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL) AS GpStatus
```
```
FUNCTION GdipDrawRectangleI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *GpGraphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the rectangle. |
| *x* | [in] The x-coordinate of the upper-left corner of the rectangle. |
| *y* | [in] The y-coordinate of the upper-left corner of the rectangle. |
| *nWidth* | [in] The width of the rectangle. |
| *nHeight* | [in] The height of the rectangle. |

#### Example

```
' ========================================================================================
' The following example draws a rectangle.
' ========================================================================================
SUB Example_DrawRectangle (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 3, UnitPixel, @pen)

   ' // Define the rectangle.
   DIM x AS SINGLE = 30.0
   DIM y AS SINGLE = 30.0
   DIM nWidth AS SINGLE = 340.0
   DIM nHeight AS SINGLE = 190.0

   ' // Draw the rectangle
   hStatus = GdipDrawRectangle(graphics, pen, x, y, nWidth, nHeight)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawRectangles

Draws a sequence of rectangles.

```
FUNCTION GdipDrawRectangles (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL rects AS GpRectF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipDrawRectanglesI (BYVAL graphics AS GpGraphics PTR, BYVAL pen AS GpPen PTR, _
   BYVAL rects AS GpRect PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pen* | [in] Pointer to a pen that is used to draw the rectangles. |
| *rects* | [in] Pointer to an array of **GpRect** structures that specify the coordinates of the rectangles to be drawn.  |
| *count* | [in] Long integer value that specifies the number of elements in the rects array.  |

#### Example

```
' ========================================================================================
' The following example draws a group of rectangles.
' ========================================================================================
SUB Example_DrawRectangles (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a Pen
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 3, UnitPixel, @pen)

   ' // Create an array of GpRectF structures.
   DIM rc(2) AS GpRectF
   rc(0).x = 0.0   : rc(0).y = 0.0   : rc(0).Width = 100.0 : rc(0).Height = 200.0
   rc(1).x = 100.0 : rc(1).y = 200.0 : rc(1).Width = 250.0 : rc(1).Height = 50.0
   rc(2).x = 300.0 : rc(2).y = 0.0   : rc(2).Width = 50.0  : rc(2).Height = 100.0

   ' // Draw the rectangles
   hStatus = GdipDrawRectangles(graphics, pen, @rc(0), 3)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipEndContainer

Closes a graphics container that was previously opened by the **GdipBeginContainer** method.

```
FUNCTION GdipEndContainer (BYVAL graphics AS GpGraphics PTR, _
   BYVAL state AS GraphicsContainer PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *state* | [in] Value (previously returned by **GdipBeginContainer**) that identifies the container to be closed. |

#### Remarks

When you call the **GdipBeginContainer** function, an information block that holds the state of the **Graphics** object is put on a stack. The **GdipBeginContainer** method returns a value that identifies that information block. When you pass the identifying value to the **GdipEndContainer** method, the information block is removed from the stack and is used to restore the **Graphics** object to the state it was in at the time of the **GdipBeginContainer** call.

Containers can be nested; that is, you can call the **GdipBeginContainer** function several times before you call the **GdipEndContainer** function. Each time you call the **GdipBeginContainer** function, an information block is put on the stack, and you receive an identifier for the information block. When you pass one of those identifiers to the **GdipEndContainer** function, the **Graphics** object is returned to the state it was in at the time of the **GdipBeginContainer** call that returned that particular identifier. The information block placed on the stack by that **GdipBeginContainer** call is removed from the stack, and all information blocks placed on that stack after that **GdipBeginContainer** call are also removed.

Calls to the **GdipSaveGraphics** function place information blocks on the same stack as calls to the **GdipBeginContainer** function. Just as an **GdipEndContainer** call is paired with a **GdipBeginContainer** call, a **GdipRestoreGraphics** call is paired with a **GdipSaveGraphics** call.

Caution When you call **GdipEndContainer**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipBeginContainer** are removed from the stack. Likewise, when you call **GdipRestoreGraphics**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipSaveGraphics** are removed from the stack.


#### Example

```
' ========================================================================================
' This example demonstrates how to use GdipBeginContainer and GdipEndContainer
' to isolate transformations and rendering settings within a scoped graphics container.
' ========================================================================================
SUB Example_BeginContainer (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Draw a base rectangle (no transformation)
   DIM basePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2.0, UnitWorld, @basePen)
   hStatus = GdipDrawRectangle(graphics, basePen, 20, 20, 100, 50)

   ' // Begin container
   DIM container AS GraphicsContainer
   hStatus = GdipBeginContainer(graphics, NULL, NULL, UnitWorld, @container)

   ' // Apply transformation inside container
   hStatus = GdipTranslateWorldTransform(graphics, 150, 0, MatrixOrderAppend)
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderAppend)

   ' Draw transformed rectangle
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 2.0, UnitWorld, @redPen)
   hStatus = GdipDrawRectangle(graphics, redPen, 20, 20, 100, 50)

   ' // End container (restores previous state)
   hStatus = GdipEndContainer(graphics, container)

   ' // Draw another rectangle (back to original state)
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 2.0, UnitWorld, @bluePen)
   hStatus = GdipDrawRectangle(graphics, bluePen, 20, 90, 100, 50)

   ' // Cleanup
   IF basePen THEN GdipDeletePen(basePen)
   IF redPen THEN GdipDeletePen(redPen)
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipEnumerateMetafileDestPoint

Calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling **GdipPlayMetafileRecord** in the callback function.

```
FUNCTION GdipEnumerateMetafileDestPoint (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoint AS GpPointF PTR, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *metafile* | [in] Pointer to a metafile to be enumerated. |
| *destPoint* | [in] Reference to a point that specifies the upper-left corner of the displayed metafile. |
| *callback* | [in] Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h. |
| *callbackData* | [in] Pointer to a block of data that is passed to the callback function. The default value is NULL. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments for the displayed metafile. The default value is NULL. |

#### Example

```
' ========================================================================================
' Enumerate and Replay Metafile Records
' Calls your callback for each record in the metafile.
' You can inspect record types, sizes, and optionally replay or skip them.
' The destination point defines where the metafile is rendered.
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WsTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileDestPoint (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Load a metafile
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Create graphics object from HDC
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Destination point
   DIM destPoint AS GpPointF = (50.0, 50.0)

   ' // Enumerate records
   hStatus = GdipEnumerateMetafileDestPoint(graphics, metafile, @destPoint, _
                                            @MetafileCallback, NULL, NULL)
   IF hStatus <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipEnumerateMetafileDestPoints

Calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling **GdipPlayMetafileRecord** in the callback function.

```
FUNCTION GdipEnumerateMetafileDestPoints (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoints AS GpPointF PTR, _
   BYAL count AS INT_, BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```
```
FUNCTION GdipEnumerateMetafileDestPointsI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoints AS GpPoint PTR, _
   BYAL count AS INT_, BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *metafile* | [in] Pointer to a metafile to be enumerated. |
| *destPoints* | [in] Pointer to an array of destination points. This is an array of three points that defines the destination parallelogram for the displayed metafile. |
| *count* | [in] Long integer value  that specifies the number of points in the destPoints array. |
| *callback* | [in] Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h. |
| *callbackData* | [in] Pointer to a block of data that is passed to the callback function. The default value is NULL. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments for the displayed metafile. The default value is NULL. |

#### Example

```
' ========================================================================================
' Enumerate and Replay Metafile at Multiple Points.
' Efficiently renders the same metafile content at multiple locations.
' Lets you inspect or modify records during playback.
' Ideal for stamping, watermarking, or tiled rendering.
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WsTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileDestPoints (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Load a metafile
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Create graphics object from HDC
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Define multiple destination points
   DIM points(2) AS GpPointF
   points(0) = TYPE<GpPointF>(50.0, 50.0)    ' Top-left
   points(1) = TYPE<GpPointF>(250.0, 50.0)   ' Top-right
   points(2) = TYPE<GpPointF>(50.0, 200.0)   ' Bottom-left

   ' // Enumerate and replay metafile records at each point
   hStatus = GdipEnumerateMetafileDestPoints(graphics, metafile, @points(0), 3, _
                                             @MetafileCallback, NULL, NULL)
   IF hStatus <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipEnumerateMetafileDestRect

Calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling **GdipPlayMetafileRecord** in the callback function.

```
FUNCTION GdipEnumerateMetafileDestPoints (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destRect AS GpRectF PTR, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```
```
FUNCTION GdipEnumerateMetafileDestPointsI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destRect AS GpRect PTR, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *metafile* | [in] Pointer to a metafile to be enumerated. |
| *destRect* | [in] [in] Reference to a **GpRect** or **GpRectF** structure that specifies the rectangle in which the metafile is displayed. |
| *callback* | [in] Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h. |
| *callbackData* | [in] Pointer to a block of data that is passed to the callback function. The default value is NULL. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments for the displayed metafile. The default value is NULL. |

#### Example

```
' ========================================================================================
' Enumerate and Replay Metafile Records
' Calls your callback for each record in the metafile.
' Scales and positions metafile content within a defined rectangle.
' Lets you inspect or selectively replay records.
' Ideal for layout-sensitive rendering (e.g. thumbnails, previews, print areas).
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WsTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileDestRect (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Load a metafile
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Create graphics object from HDC
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Define destination rectangle
   DIM destRect AS GpRectF = (50.0, 50.0, 300.0, 200.0)

   ' // Enumerate and replay metafile records
   hStatus = GdipEnumerateMetafileDestRect(graphics, metafile, @destRect, _
                                           @MetafileCallback, NULL, NULL)
   IF hStatus <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipEnumerateMetafileSrcRectDestPoint

Calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling **GdipPlayMetafileRecord** in the callback function.

```
FUNCTION GdipEnumerateMetafileSrcRectDestPoint (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoint AS GpPointF PTR, _
   BYVAL srcRect AS GpRectF, BYVAL srcUnit AS GpUnit, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```
```
FUNCTION GdipEnumerateMetafileSrcRectDestPointI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoint AS GpPoint PTR, _
   BYVAL srcRect AS GpRect, BYVAL srcUnit AS GpUnit, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *metafile* | [in] Pointer to a metafile to be enumerated. |
| *destPoint* | [in] Reference to a point that specifies the upper-left corner of the displayed metafile. |
| *srcRect* | [in] Reference to a rectangle that specifies the portion of the metafile that is displayed. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the source rectangle. |
| *callback* | [in] Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h. |
| *callbackData* | [in] Pointer to a block of data that is passed to the callback function. The default value is NULL. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments for the displayed metafile. The default value is NULL. |

#### Example

```
' ========================================================================================
' Enumerate and Replay Cropped Metafile at a Point.
' Allows you:
' Crop the metafile using srcRect
' Render it at a specific destPoint
' Control units via srcUnit (e.g., UnitPixel, UnitMillimeter)
' Intercept records via a callback
' Apply image attributes (e.g., color adjustments, gamma correction)
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WsTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileSrcRectDestPoint (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Load a metafile
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Create graphics object from HDC
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Define source rectangle (crop area)
   DIM srcRect AS GpRectF = (50.0, 50.0, 200.0, 100.0)

   ' // Define destination point
   DIM destPoint AS GpPointF = (300.0, 100.0)

   ' // Enumerate and replay cropped metafile
   hStatus = GdipEnumerateMetafileSrcRectDestPoint(graphics, metafile, @destPoint, @srcRect, _
                                                   UnitPixel, @MetafileCallback, NULL, NULL)
   IF hStatus <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipEnumerateMetafileSrcRectDestPoints

Calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling **GdipPlayMetafileRecord** in the callback function.

```
FUNCTION GdipEnumerateMetafileSrcRectDestPoints (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoints AS GpPointF PTR, _
   BYVAL count AS INT_, BYVAL srcRect AS GpRectF PTR, BYVAL srcUnit AS GpUnit, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```
```
FUNCTION GdipEnumerateMetafileSrcRectDestPointsI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destPoints AS GpPoint PTR, _
   BYVAL count AS INT_, BYVAL srcRect AS GpRect PTR, BYVAL srcUnit AS GpUnit, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *metafile* | [in] Pointer to a metafile to be enumerated. |
| *destPoints* | [in] Pointer to an array of destination points. This is an array of three points that defines the destination parallelogram for the displayed metafile. |
| *count* | [in] Long integer value that specifies the number of points in the *destPoints* array. |
| *srcRect* | [in] Reference to a rectangle that specifies the portion of the metafile that is displayed. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the source rectangle. |
| *callback* | [in] Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h. |
| *callbackData* | [in] Pointer to a block of data that is passed to the callback function. The default value is NULL. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments for the displayed metafile. The default value is NULL. |

#### Example

```
' ========================================================================================
' Cropped and Transformed Metafile Playback.
' Combines cropping and transforming in one step.
' Destination points define a parallelogram, allowing skew, rotation, and scaling.
' Ideal for advanced rendering scenarios like perspective effects or layout fitting.
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WsTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileSrcRectDestPoints (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Load a metafile
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Create graphics object from HDC
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Define source rectangle (crop area)
   DIM srcRect AS GpRectF = (50.0, 50.0, 200.0, 100.0)

   ' // Define destination parallelogram (3 points)
   DIM destPoints(2) AS GpPointF
   destPoints(0) = TYPE<GpPointF>(300.0, 100.0)   ' Top-left
   destPoints(1) = TYPE<GpPointF>(500.0, 120.0)   ' Top-right (skewed)
   destPoints(2) = TYPE<GpPointF>(280.0, 250.0)   ' Bottom-left

   ' // Enumerate and replay cropped metafile
   hStatus = GdipEnumerateMetafileSrcRectDestPoints(graphics, metafile, @destPoints(0), 3, _
                                                    @srcRect, UnitPixel, @MetafileCallback, NULL, NULL)
   IF hStatus <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipEnumerateMetafileSrcRectDestRect

Calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling **GdipPlayMetafileRecord** in the callback function

```
FUNCTION GdipEnumerateMetafileSrcRectDestRect (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destRect AS GpRectF PTR, _
   BYVAL srcRect AS GpRectF PTR, BYVAL srcUnit AS GpUnit, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```
```
FUNCTION GdipEnumerateMetafileSrcRectDestRectI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL metafile AS GpMetafile PTR, BYVAL destRect AS GpRect PTR, _
   BYVAL srcRect AS GpRect PTR, BYVAL srcUnit AS GpUnit, _
   BYVAL callback AS EnumerateMetafileProc, BYVAL callbackData AS VOID PTR, _
   BYVAL imageAttributes AS GpImageAttributes PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *metafile* | [in] Pointer to a metafile to be enumerated. |
| *destRect* | [in] Pointer to an array of destination points. This is an array of three points that defines the destination parallelogram for the displayed metafile. |
| *srcRect* | [in] Reference to a rectangle that specifies the portion of the metafile that is displayed. |
| *srcUnit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the source rectangle. |
| *callback* | [in] Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h. |
| *callbackData* | [in] Pointer to a block of data that is passed to the callback function. The default value is NULL. |
| *imageAttributes* | [in] Pointer to a **GpImageAttributes** object that specifies color adjustments for the displayed metafile. The default value is NULL. |

#### Example

```
' ========================================================================================
' Cropped Metafile Playback in a Rectangle
' Cropping: Only the portion inside srcRect is processed.
' Scaling and positioning: The content is rendered inside destRect, stretched or shrunk as needed.
' Inspection: The callback lets you analyze or selectively replay records.
' ========================================================================================

' Callback function prototype
FUNCTION MetafileCallback (BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, _
                           BYVAL dataSize AS UINT, BYVAL byteData AS CONST UBYTE PTR, _
                           BYVAL callbackData AS ANY PTR) AS BOOL
   ' You can inspect or modify each record here
   OutputDebugStringW "Record type: " & WsTR(recordType) & " Size: " & WSTR(dataSize)
   RETURN TRUE  ' Continue enumeration
END FUNCTION
' ========================================================================================

' ========================================================================================
SUB Example_EnumerateMetafileSrcRectDestRect (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Load a metafile
   DIM metafile AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
   hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to load metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Create graphics object from HDC
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' // Define source rectangle (crop area)
   DIM srcRect AS GpRectF = (50.0, 50.0, 200.0, 100.0)

   ' // Define destination rectangle (where to draw)
   DIM destRect AS GpRectF = (300.0, 100.0, 400.0, 200.0)

   ' // Enumerate and replay cropped metafile
   hStatus = GdipEnumerateMetafileSrcRectDestRect(graphics, metafile, @destRect, @srcRect, _
                                                  UnitPixel, @MetafileCallback, NULL, NULL)
   IF hStatus <> 0 THEN
      AfxMsg "Enumeration failed: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipFillClosedCurve

Creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline.

```
FUNCTION GdipFillClosedCurve (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPointF, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipFillClosedCurveI (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPoint, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *points* | [in] Pointer to an array of points that this method uses to create a closed cardinal spline. Each point in the array is a point on the spline. |
| *count* | [in] Long integer value that specifies the number of points in the *points* array. |

#### Example

```
' ========================================================================================
' The following example fills a closed cardinal spline.
' ========================================================================================
SUB Example_FillClosedCurve (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create an array of GpPointF objects.
   DIM points(3) AS GpPointF
   points(0).x = 100.0 : points(0).y = 100.0
   points(1).x = 200.0 : points(1).y = 50.0
   points(2).x = 250.0 : points(2).y = 200.0
   points(3).x = 50.0  : points(3).y = 150.0

   ' // Fill the curve.
   hStatus = GdipFillClosedCurve(graphics, brush, @points(0), 4)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillClosedCurve2

Creates a closed cardinal spline from an array of points and uses a brush to fill, according to a specified mode, the interior of the spline.

```
FUNCTION GdipFillClosedCurve2 (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPointF, BYVAL count AS INT_, BYVAL tension AS REAL, _
   BYVAL fillmode AS GpFillMode) AS GpStatus
```
```
FUNCTION GdipFillClosedCurve2I (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPoint, BYVAL count AS INT_, BYVAL tension AS REAL, _
   BYVAL fillmode AS GpFillMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *points* | [in] Pointer to an array of points that this method uses to create a closed cardinal spline. Each point in the array is a point on the spline. |
| *count* | [in] Long integer value that specifies the number of points in the *points* array. |
| *tension* | [in]  Nonnegative real number that specifies how tightly the spline bends as it passes through the points. A value of 0 specifies that the spline is a sequence of straight lines. As the value increases, the curve becomes fuller. The default value is 0.5. |
| *fillmode* | [in] Element of the *GpFillMode* enumeration that specifies how to fill a closed area that is created when the curve passes over itself. |

#### Example

```
' ========================================================================================
' The following example fills a closed cardinal spline.
' ========================================================================================
SUB Example_FillClosedCurve2 (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create an array of GpPointF objects.
   DIM points(3) AS GpPointF
   points(0).x = 100.0 : points(0).y = 100.0
   points(1).x = 200.0 : points(1).y = 50.0
   points(2).x = 250.0 : points(2).y = 200.0
   points(3).x = 50.0  : points(3).y = 150.0

   ' // Fill the curve.
   hStatus = GdipFillClosedCurve2(graphics, brush, @points(0), 4, 1.0, FillModeALternate)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillEllipse

Uses a brush to fill the interior of an ellipse that is specified by coordinates and dimensions.

```
FUNCTION GdipFillEllipse (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL) AS GpStatus
```
```
FUNCTION GdipFillEllipseI (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *points* | [in] Pointer to an array of points that this method uses to create a closed cardinal spline. Each point in the array is a point on the spline. |
| *count* | [in] Long integer value that specifies the number of points in the *points* array. |
| *tension* | [in]  Nonnegative real number that specifies how tightly the spline bends as it passes through the points. A value of 0 specifies that the spline is a sequence of straight lines. As the value increases, the curve becomes fuller. The default value is 0.5. |
| *fillmode* | [in] Element of the *GpFillMode* enumeration that specifies how to fill a closed area that is created when the curve passes over itself. |

#### Example

```
' ========================================================================================
' The following example fills an ellipse that is defined by coordinates and dimensions.
' ========================================================================================
SUB Example_FillEllipse (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create an array of PointF objects.
   DIM AS SINGLE x, y, nWidth, nHeight
   x = 100.0 : y = 50.0 : nWidth = 200.1 : nHeight = 100.4

   ' // Fill the curve.
   hStatus = GdipFillEllipse(graphics, brush, x, y, nWidth, nHeight)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillPath

Uses a brush to fill the interior of a path. If a figure in the path is not closed, this method treats the nonclosed figure as if it were closed by a straight line that connects the figure's starting and ending points.

```
FUNCTION GdipFillPath (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL path AS GpPath PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *path* | [in] Pointer to a **GpPath** object that specifies the path. |

#### Example

```
' ========================================================================================
' The following example fills a path.
' ========================================================================================
SUB Example_FillPath (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a GraphicsPath object, and add an ellipse
   DIM ellipsePath AS GpPath PTR  
   hStatus = GdipCreatePath(FillModeAlternate, @ellipsePath)
   hStatus = GdipAddPathEllipseI(ellipsePath, 100, 50, 200, 100)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Fill ellipsePath.
   hStatus = GdipFillPath(graphics, brush, ellipsePath)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF ellipsePath THEN GdipDeletePath(ellipsePath)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillPie

Uses a brush to fill the interior of a pie.

```
FUNCTION GdipFillPie (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL, _
   BYAL startAngle AS REAL, BYVAL sweepAngle AS REAL) AS GpStatus
```
```
FUNCTION GdipFillPie (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_, _
   BYAL startAngle AS REAL, BYVAL sweepAngle AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *x* | [in] The x-coordinate of the upper-left corner of the rectangle that bounds the ellipse. A curved portion of the ellipse is the arc of the pie. |
| *y* | [in] The y-coordinate of the upper-left corner of the rectangle that bounds the ellipse. |
| *nWidth* | [in] The width of the rectangle that bounds the ellipse. |
| *nHeight* | [in] The height of the rectangle that bounds the ellipse. |
| *startAngle* | [in] Simple precision value that specifies the angle, in degrees, between the x-axis and the starting point of the pie's arc. |
| *sweepAngle* | [in] Simple precision value that specifies the angle, in degrees, between the starting and ending points of the pie's arc. |

#### Remarks

A pie is a portion of the interior of an ellipse (it is bounded by an elliptical curve and two radial lines). The *startAngle* and *sweepAngle* specify the portion of the ellipse to be used.

#### Example

```
' ========================================================================================
' The following example defines a pie and then fills it.
' ========================================================================================
SUB Example_FillPie (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Define the pie shape.
   DIM x AS SINGLE = 0.0
   DIM y AS SINGLE = 2.0
   DIM nWidth AS SINGLE = 200.8
   DIM nHeight AS SINGLE = 100.1
   DIM startAngle AS SINGLE = 0.0
   DIM sweepAngle AS SINGLE = 45.7

   ' // Fill the pie.
   hStatus = GdipFillPie(graphics, brush, x, y, nWidth, nHeight, startAngle, sweepAngle)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillPolygon

Uses a brush to fill the interior of a pie.

```
FUNCTION GdipFillPolygon (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPointF, BYVAL count AS INT_, BYVAL fillMode AS GpFillMode) AS GpStatus
```
```
FUNCTION GdipFillPolygon (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPoint, BYVAL count AS INT_, BYVAL fillMode AS GpFillMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *points* | [in] Pointer to an array of points that make up the vertices of the polygon. The first two points in the array specify the first side of the polygon. Each additional point specifies a new side, the vertices of which include the point and the previous point. If the last point and the first point do not coincide, they specify the last side of the polygon. |
| *count* | [in] Long integer value that specifies the number of points in the points array. |
| *fillMode* | [in] Element of the *GpFillMode* enumeration that specifies how to fill a closed area that is within another closed area and that is created when the curve or path passes over itself.|

#### Example

```
' ========================================================================================
' The following example defines a polygon and fills it.
' ========================================================================================
SUB Example_FillPolygon (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create an array of PointF objects that define the polygon.
   DIM points(4) AS GpPointF
   points(0).x = 100.0 : points(0).y = 100.0
   points(1).x = 150.0 : points(1).y = 130.0
   points(2).x = 150.0 : points(2).y = 200.0
   points(3).x = 50.0  : points(3).y = 200.0
   points(4).x = 0.0   : points(4).y = 130.0

   ' // Fill the polygon.
   hStatus = GdipFillPolygon(graphics, brush, @points(0), 5, FillModeAlternate)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillPolygon2

Uses a brush to fill the interior of a pie.

```
FUNCTION GdipFillPolygon2 (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPointF, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipFillPolygon2I (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL points AS GpPoint, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *points* | [in] Pointer to an array of points that make up the vertices of the polygon. The first two points in the array specify the first side of the polygon. Each additional point specifies a new side, the vertices of which include the point and the previous point. If the last point and the first point do not coincide, they specify the last side of the polygon. |
| *count* | [in] Long integer value that specifies the number of points in the points array. |

#### Example

```
' ========================================================================================
' The following example defines a polygon and fills it.
' ========================================================================================
SUB Example_FillPolygon2 (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create an array of PointF objects that define the polygon.
   DIM points(4) AS GpPointF
   points(0).x = 100.0 : points(0).y = 100.0
   points(1).x = 150.0 : points(1).y = 130.0
   points(2).x = 150.0 : points(2).y = 200.0
   points(3).x = 50.0  : points(3).y = 200.0
   points(4).x = 0.0   : points(4).y = 130.0

   ' // Fill the polygon.
   hStatus = GdipFillPolygon2(graphics, brush, @points(0), 5)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillRectangle

Uses a brush to fill the interior of a rectangle.

```
FUNCTION GdipFillRectangle (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL nWidth AS REAL, BYVAL nHeight AS REAL) AS GpStatus
```
```
FUNCTION GdipFillRectangleI (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL nWidth AS INT_, BYVAL nHeight AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *x* | [in] The x-coordinate of the upper-left corner of the rectangle to be filled. |
| *y* | [in] The y-coordinate of the upper-left corner of the rectangle to be filled. |
| *nWidth* | [in] The width of the rectangle to be filled. |
| *nHeight* | [in] The height of the rectangle to be filled. |

#### Example

```
' ========================================================================================
' The following example defines a rectangle and fills it.
' ========================================================================================
SUB Example_FillRectangle (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Define the rectangle
   DIM x AS SINGLE = 0.5
   DIM y AS SINGLE = 0.5
   DIM nWidth AS SINGLE = 100.8
   DIM nHeight AS SINGLE = 100.8

   ' // Fill the rectangle.
   hStatus = GdipFillRectangle(graphics, brush, x, y, nWidth, nHeight)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillRectangles

Uses a brush to fill the interior of a rectangle.

```
FUNCTION GdipFillRectangles (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL rects AS GpRectF PTR, BYVAL count AS INT_) AS GpStatus
```
```
FUNCTION GdipFillRectanglesI (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL rects AS GpRect PTR, BYVAL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *rects* | [in] Pointer to an array of rectangles to be filled. |
| *count* | [in] Long integer value that specifies the number of rectangles in the *rects* array. |

#### Example

```
' ========================================================================================
' he following example draws a group of rectangles and fills them.
' ========================================================================================
SUB Example_FillRectangles (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create an array of GpRectF objects.
   DIM rects(2) AS GpREctF
   rects(0).x = 0.0 : rects(0).y = 0.0 : rects(0).Width = 100.0 : rects(0).Height = 200.0
   rects(1).x = 100.5 : rects(1).y = 200.5 : rects(1).Width = 200.5 : rects(1).Height = 50.5
   rects(2).x = 300.8 : rects(2).y = 0.8 : rects(2).Width = 50.8 : rects(2).Height = 150.8

   ' // Fill the rectangles.
   hStatus = GdipFillRectangles(graphics, brush, @rects(0), 3)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFillRegion

Uses a brush to fill a specified region.

```
FUNCTION GdipFillRegion (BYVAL graphics AS GpGraphics PTR, BYVAL brush AS GpBrush, _
   BYVAL region AS GpRegion PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *brush* | [in] Pointer to a **Brush** object that is used to paint the interior of the spline. |
| *region* | [in] Pointer to a region to be filled. |

#### Remarks

Because a region describes a set of pixels, a pixel is considered either fully inside, or fully outside the region. Consequently, **GdipFillRegion** does not antialias the edges of the region.

#### Example

```
' ========================================================================================
' The following example creates a region from a rectangle and then fills the region.
' ========================================================================================
SUB Example_FillRegion (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Create a Region object from a rectangle.
   DIM rcf AS GpRectF, region AS GpRegion PTR
   rcf.x = 0 : rcf.y = 0 : rcf.Width = 200 : rcf.Height = 100
   hStatus = GdipCreateRegionRect(@rcf, @region)

   ' // Fill the rectangle.
   hStatus = GdipFillRegion(graphics, brush, region)
   
   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipFlush

Flushes all pending graphics operations.

```
FUNCTION GdipFlush (BYVAL graphics AS GpGraphics PTR, BYVAL intention AS GpFlushIntention) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *intention* | [in] Element of the **FlushIntention** enumeration that specifies whether pending operations are flushed immediately (not executed) or executed as soon as possible. |

#### Example

```
' ========================================================================================
' Using GdipFlush to Finalize Drawing.
' FlushIntentionFlush ensures all drawing commands are executed immediately.
' ========================================================================================
SUB Example_GdipFlush (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Draw something simple
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, AfxGdipPointsToPixels(3, TRUE), UnitPixel, @pen)
   hStatus = GdipDrawEllipse(graphics, pen, 50, 50, 150, 100)

   ' // Flush all pending operations
   hStatus = GdipFlush(graphics, FlushIntentionFlush)

   ' // Optional: draw confirmation text
   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   DIM brush AS GpSolidFill PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPixel, @font)
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   DIM layout AS GpRectF = (10.0, 10.0, 300.0, 30.0)
   hStatus = GdipDrawString(graphics, "Flush complete", -1, font, @layout, NULL, brush)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF font THEN GdipDeleteFont(font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetClip

Gets the clipping region of the **Graphics** object.

```
FUNCTION GdipGetClip (BYVAL graphics AS GpGraphics PTR, BYVAL region AS GpRegion PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *region* | [out] Pointer to a **GpRegion** variable that receives the clipping region. |

#### Example

```
' ========================================================================================
' The following example sets a clipping region. Next, the code gets the clipping region,
' stores it in a Region object, and then uses the stored object to fill the region.
' ========================================================================================
SUB Example_GetClip (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set a clipping region
   hStatus = GdipSetClipRect(graphics, 100, 50, 200, 120, CombineModeReplace)

   ' // Get the clipping region.
   DIM region AS GpRegion PTR
   hStatus = GdipCreateRegion(@region)
   hStatus = GdipGetClip(graphics, region)

   ' // Create brush and fill region
   DIM brush As GpSolidFill PTR
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @brush)
   hStatus = GdipFillRegion(graphics, brush, region)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF region THEN GdipDeleteRegion(region)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetClipBounds

Gets a rectangle that encloses the clipping region of the **Graphics** object.

```
FUNCTION GdipGetClipBounds (BYVAL graphics AS GpGraphics PTR, BYVAL rect AS GpRectF PTR) AS GpStatus
```
```
FUNCTION GdipGetClipBoundsI (BYVAL graphics AS GpGraphics PTR, BYVAL rect AS GpRect PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *rect* | [out] Pointer to a **GpRect** structure that receives the rectangle that encloses the clipping region. |

#### Remarks

The world transformation is applied to the clipping region and then the enclosing rectangle is calculated.

If you do not explicitly set the clipping region of a **Graphics** object, its clipping region is infinite. When the clipping region is infinite, **GdipGetClipBounds** returns a large rectangle. The *x* and *y* data members of that rectangle are large negative numbers, and the *width* and *heigh* data members are large positive numbers.

#### Example

```
' ========================================================================================
' The following example sets a clipping region, gets the rectangle that encloses the
' clipping region, and then fills the rectangle.
' ========================================================================================
SUB Example_GetClipBounds (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Define initial region and rectangle
   DIM region1 AS GpRegion PTR
   DIM region2 AS GpRegion PTR
   DIM rect1 AS GpRectF = (25, 25, 100, 50)
   DIM rect2 AS GpRectF = (40, 60, 100, 50)
   DIM enclosingRect AS GpRectF

   ' // Create region from rect1
   hStatus = GdipCreateRegionRect(@rect1, @region1)

   ' // Union with rect2
   hStatus = GdipCombineRegionRect(region1, @rect2, CombineModeUnion)

   ' // Set clipping region
   hStatus = GdipSetClipRegion(graphics, region1, CombineModeReplace)

   ' // Get current clipping region
   hStatus = GdipCreateRegion(@region2)
   hStatus = GdipGetClip(graphics, region2)

   ' // Create brush and fill region
   DIM brush As GpSolidFill PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(100, 0, 0, 255), @brush)
   hStatus = GdipFillRegion(graphics, brush, region2)

   ' // Get enclosing rectangle of clipping region
   hStatus = GdipGetClipBounds(graphics, @enclosingRect)

   ' // Reset clip
   hStatus = GdipResetClip(graphics)

   ' // Create pen and draw rectangle
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 1.5, UnitWorld, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, enclosingRect.X, enclosingRect.Y, enclosingRect.Width, enclosingRect.Height)

    ' Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF brush THEN GdipDeleteBrush(brush)
   IF region1 THEN GdipDeleteRegion(region1)
   IF region2 THEN GdipDeleteRegion(region2)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetCompositingMode

Gets the compositing mode currently set for the **Graphics** object.

```
FUNCTION GdipGetCompositingMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL compositingMode AS CompositingMode PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *compositingMode* | [out] Pointer to a variable that receives the compositing mode currently set for the **Graphics** object. |

#### Remarks

Suppose you create a **GpSolidBrush** object based on a color that has an alpha component of 192, which is about 75 percent of 255. If your **Graphics** object has its compositing mode set to **CompositingModeSourceOver**, then areas filled with the solid brush are a blend that is 75 percent brush color and 25 percent background color. If your **Graphics** object has its compositing mode set to **CompositingModeSourceCopy**, then the background color is not blended with the brush color. However, the color rendered by the brush has an intensity that is 75 percent of what it would be if the alpha component were 255.

#### Example

```
' ========================================================================================
' The following example creates a Graphics object and sets its compositing mode to
' CompositingModeSourceCopy. The code creates a SolidBrush object based on a color with an
' alpha component of 128. The code passes the address of that brush to the GdipFillRectangle
' function to fill a rectangle with a color that is not blended with the background color.
' The call to the GdipSetCompositingMode function demonstrates how to obtain the compositing
' mode (which is already known in this case). The code determines whether the compositing
' mode is CompositingModeSourceCopy and if so, changes it to CompositingModeSourceOver.
' Then the code calls GdipFillRectangle a second time to fill a rectangle with a color that
' is a half-and-half blend of the brush color and the background color.
' ========================================================================================
SUB Example_GetCompositingMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush object with an alpha-blended color.
   DIM alphaBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(128, 255, 0, 0), @alphaBrush)

   ' // Set the compositing mode to CompositingModeSourceCopy, and fill a rectangle.
   hStatus = GdipSetCompositingMode(graphics, CompositingModeSourceCopy)
   hStatus = GdipFillRectangle(graphics, alphaBrush, 0, 0, 100, 100)

   ' // Get the compositing mode.
   DIM compMode AS CompositingMode
   hStatus = GdipGetCompositingMode(graphics, @compMode)

   ' // Change the compositing mode if it is CompositingModeSourceCopy.
   IF compMode = CompositingModeSourceCopy THEN
      hStatus = GdipSetCompositingMode(graphics, CompositingModeSourceOver)
   END IF
   ' // Fill a rectangle
   hStatus = GdipFillRectangle(graphics, alphaBrush, 0, 100, 100, 100)

   ' // Cleanup
   IF alphaBrush THEN GdipDeleteBrush(alphaBrush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetCompositingQuality

Gets the compositing quality currently set for the **Graphics** object.

```
FUNCTION GdipGetCompositingQuality (BYVAL graphics AS GpGraphics PTR, _
   BYVAL compositingQuality AS CompositingQuality PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *CompositingQuality* | [out] Pointer to a variable that receives the compositing quality currently set for the **Graphics** object. |

#### Example

```
' ========================================================================================
' The following example creates a Graphics object and sets its compositing quality to
' CompositingQualityHighQuality. The code creates a SolidBrush object based on a color
' with an alpha component of 128. The code passes the address of that brush to the
' GdipFillRectangle function. The call to the GdipGetCompositingQuality function
' demonstrates how to obtain the compositing quality (which is already known in this case).
' The code determines whether the compositing quality is CompositingQualityHighQuality and
' if so, changes it to CompositingQualityHighSpeed. Then the code calls the GdipFillRectangle
' function a second time. The second rectangle is filled with the same brush that was used
' to fill the first rectangle, but the result is different because of the compositing
' quality setting.
' ========================================================================================
SUB Example_GetCompositingQuality (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush object with an alpha-blended color.
   DIM alphaBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(128, 255, 0, 0), @alphaBrush)

   ' // Set the compositing quality to CompositingQualityHighQuality, and fill a rectangle.
   hStatus = GdipSetCompositingQuality(graphics, CompositingQualityHighQuality)
   hStatus = GdipFillRectangle(graphics, alphaBrush, 0, 0, 100, 100)

   ' // Get the compositing quality.
   DIM compQuality AS CompositingQuality
   hStatus = GdipGetCompositingQuality(graphics, @compQuality)

   ' // Change the compositing mode if it is CompositingModeSourceCopy.
   IF compQuality = CompositingQualityHighQuality THEN
      GdipSetCompositingQuality(graphics, CompositingQualityHighSpeed)
   END IF
   hStatus = GdipFillRectangle(graphics, alphaBrush, 0, 100, 100, 100)

   ' // Cleanup
   IF alphaBrush THEN GdipDeleteBrush(alphaBrush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetDC

Gets a handle to the device context associated with the **Graphics** object.

```
FUNCTION GdipGetDC (BYVAL graphics AS GpGraphics PTR, BYVAL hdc AS HDC PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *hdc* | [out] Handle to the device context associated with the **Graphics** object. |

#### Remarks

Each call to the **GdipGetDC** fujnction should be paired with a call to the **GdipReleaseDC** function. Do not call any **Graphics** functions between the calls to **GdipGetDC** and **GdipReleaseDC**. If you attempt to call a **Graphics** function between **GdipGetDC** and **GdipReleaseDC**, the method will fail and will return *ObjectBusy*.

Any state changes you make to the device context between **GdipGetDC** and **GdipReleaseDC** will be ignored by GDI+ and will not be reflected in rendering done by GDI+.

---

## GdipGetDpiX

Gets the horizontal resolution, in dots per inch, of the display device associated with the **Graphics** object.

```
FUNCTION GdipGetDpiX (BYVAL graphics AS GpGraphics PTR, BYVAL dpi AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *dpi* | [out] Pointer to a variable that receives the horizontal resolution, in dots per inch, of the display device associated with the **Graphics** object. |

### Example

```
' ========================================================================================
' The following example gets the horizontal resolution, in dots per inch, of the display
' device and uses that value to convert pixels to inches. Then the code draws two rectangles
' that have the same width: one measured in inches and one measured in pixels.
' ========================================================================================
SUB Example_GetDpiX (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set the unit of measure for graphics to inches.
   hStatus = GdipSetPageUnit(graphics, UnitInch)

   ' // Use dpiX to convert pixels to inches, and draw a rectangle that has a width of 100 pixels.
   DIM side AS SINGLE = 100.0 / dpiX
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 3, UnitPixel, @bluePen)
   hStatus = GdipDrawRectangle(graphics, bluePen, 0.0, 0.0, side, side)

   ' // Set the unit of measure for graphics to pixels.
   hStatus = GdipSetPageUnit(graphics, UnitPixel)

   ' // Draw a 100-pixel square.
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 3, UnitPixel, @redPen)
   hStatus = GdipDrawRectangle(graphics, redPen, 120, 0, 100, 100)

   ' // Cleanup
   IF redPen THEN GdipDeletePen(redPen)
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetDpiY

Gets the vertical resolution, in dots per inch, of the display device associated with the **Graphics** object.

```
FUNCTION GdipGetDpiY (BYVAL graphics AS GpGraphics PTR, BYVAL dpi AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *dpi* | [out] Pointer to a variable that receives the vertical resolution, in dots per inch, of the display device associated with the **Graphics** object. |

#### Example

```
' ========================================================================================
' The following example gets the horizontal resolution, in dots per inch, of the display
' device and uses that value to convert pixels to inches. Then the code draws two rectangles
' that have the same width: one measured in inches and one measured in pixels.
' ========================================================================================
SUB Example_GetDpiY (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set the unit of measure for graphics to inches.
   hStatus = GdipSetPageUnit(graphics, UnitInch)

   ' // Use dpiX to convert pixels to inches, and draw a rectangle that has a width of 100 pixels.
   DIM side AS SINGLE = 100.0 / dpiX
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 3, UnitPixel, @bluePen)
   hStatus = GdipDrawRectangle(graphics, bluePen, 0.0, 0.0, side, side)

   ' // Set the unit of measure for graphics to pixels.
   hStatus = GdipSetPageUnit(graphics, UnitPixel)

   ' // Draw a 100-pixel square.
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 3, UnitPixel, @redPen)
   hStatus = GdipDrawRectangle(graphics, redPen, 120, 0, 100, 100)

   ' // Cleanup
   IF redPen THEN GdipDeletePen(redPen)
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetHemfFromMetafile

Gets a Windows handle to an Enhanced Metafile (EMF) file.

```
FUNCTION GdipGetHemfFromMetafile (BYVAL metafile AS GpMetafile PTR, BYVAL hEmf AS HENHMETAFILE PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *hEmf* | [out] Pointer to a variable that receives the Windows handle to an Enhanced Metafile (EMF) file. |

#### Remarks

This method sets the **Metafile** object to an invalid state. The user is responsible for calling **DeleteEnhMetafile**, to delete the Windows handle.

#### Example

```
' ========================================================================================
' Extract and Save EMF from a GDI+ Metafile.
' Lets you save a GDI+ metafile using classic WinAPI.
' Enables interoperability with legacy GDI tools and viewers.
' Essential for exporting vector graphics from GDI+ workflows.
' ========================================================================================
SUB Example_GetHemfFromMetafile (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Define frame rectangle
   DIM rcfFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Metafile for export"

   ' // Record metafile
   DIM metafile AS GpMetafile PTR
   hStatus = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcfFrame, MetafileFrameUnitPixel, @description, @metafile)
   IF hStatus <> 0 THEN
      AfxMsg "Recording failed: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Draw into metafile
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 2.0, UnitPixel, @pen)
   hStatus = GdipDrawEllipse(graphics, pen, 50.0, 50.0, 200.0, 100.0)

   ' // Cleanup drawing
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

   ' // Extract HENHMETAFILE
   DIM hEmf AS HENHMETAFILE
   hStatus = GdipGetHemfFromMetafile(metafile, @hEmf)
   IF hStatus <> 0 OR hEmf = 0 THEN
      AfxMsg "Failed to extract EMF handle: " & STR(hStatus)
   ELSE
      ' // Save to disk
      DIM saved AS HENHMETAFILE
      saved = CopyEnhMetaFile(hEmf, "exported.emf")
      IF saved THEN DeleteEnhMetaFile(saved)
      DeleteEnhMetaFile(hEmf)
      AfxMsg "Metafile saved to exported.emf"
   END IF

   ' // Dispose metafile
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipGetImageDecoders

Gets an array of **ImageCodecInfo** objects that contain information about the available image decoders.

```
FUNCTION GdipGetImageDecoders (BYVAL numDecoders AS UINT, BYVAL size AS UINT, _
   BYVAL decoders AS ImageCodecInfo PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *numDecoders* | [in] Long integer value that specifies the number of available image decoders. Call **GdipGetImageDecodersSize** to determine this number. |
| *size* | [in] Long integer value that specifies the size, in bytes, of the array of **ImageCodecInfo** objects. Call **GdipGetImageDecodersSize** to determine this number. |
| *decoders* | [out] Pointer to a buffer that receives the array of **ImageCodecInfo** objects. You must allocate memory for this buffer. Call **GdipGetImageDecodersSize** to determine the size of the required buffer. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' Lists Available Image Decoders

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG
DIM numDecoders AS UINT
DIM size AS UINT

' // Get size and count of decoders
hStatus = GdipGetImageDecodersSize(@numDecoders, @size)
IF hStatus <> 0 OR size = 0 THEN
   PRINT "Failed to get decoder size: "; hStatus
   END
END IF

' Allocate memory for decoder array
DIM decoders AS ImageCodecInfo PTR
decoders = CAllocate(size)

' Get decoder info
hStatus = GdipGetImageDecoders(numDecoders, size, decoders)
IF hStatus <> 0 THEN
   PRINT "Failed to get image decoders: "; hStatus
   Deallocate(decoders)
   END
END IF

' Print decoder details
FOR i AS LONG = 0 TO numDecoders - 1
   DIM codec AS ImageCodecInfo PTR = decoders + i
   PRINT "Format: "; *codec->FormatDescription
   PRINT "MimeType: "; *codec->MimeType
   PRINT "DLL: "; *codec->DllName
   PRINT "Filename Extension: "; *codec->FilenameExtension
   PRINT "--------------------------------"
NEXT

' //Cleanup
Deallocate(decoders)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageDecodersSize

Gets the number of available image decoders and the total size of the array of **ImageCodecInfo** objects that is returned by the **GdipGetImageDecoders** function.

```
FUNCTION GdipGetImageDecodersSize (BYVAL numDecoders AS UINT PTR, BYVAL size AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *numDecoders* | [out] Pointer to a variable that receives the number of available image decoders. |
| *size* | [out] Pointer to a variable that receives the total size, in bytes, of the array of **ImageCodecInfo** structures that is returned by the **GdipGetImageDecoders** function. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' Number of Available Image Decoders

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG
DIM numDecoders AS UINT
DIM size AS UINT

' // Get size and count of decoders
hStatus = GdipGetImageDecodersSize(@numDecoders, @size)
IF hStatus <> 0 OR size = 0 THEN
   PRINT "Failed to get decoder size: "; hStatus
   END
END IF

PRINT "Number of decoders: "; numDecoders
```
---

## GdipGetImageEncoders

The **GdipGetImageEncoders** function gets an array of **ImageCodecInfo** structures that contain information about the available image encoders.

```
FUNCTION GetImageEncoders (BYVAL numEncoders AS UINT, BYVAL size AS UINT, _
   BYVAL encoders AS ImageCodecInfo PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *numEncoders* | [in] Long ingteger value that specifies the number of available image encoders. Call **GdipGetImageEncodersSize** to determine this number. |
| *size* | [in] Long ingteger value that specifies the size, in bytes, of the array of **ImageCodecInfo** structures. Call **GdipGetImageEncodersSize** to determine this number. |
| *encoders* | [out] Pointer to a buffer that receives the array of **ImageCodecInfo** structures. You must allocate memory for this buffer. Call **GdipGetImageEncodersSize** to determine the size of the required buffer. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' Lists Available Image Encoders

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG
DIM numEncoders AS UINT
DIM size AS UINT

' // Get size and count of decoders
hStatus = GdipGetImageEncodersSize(@numEncoders, @size)
IF hStatus <> 0 OR size = 0 THEN
   PRINT "Failed to get decoder size: "; hStatus
   END
END IF

' // Allocate memory for encoder array
DIM encoders AS ImageCodecInfo PTR
encoders = CAllocate(size)

' // Get encoder info
hStatus = GdipGetImageEncoders(numEncoders, size, encoders)
IF hStatus <> 0 THEN
   PRINT "Failed to get image encoders: "; hStatus
   Deallocate(encoders)
   END
END IF

' // Print encoder details
FOR i AS LONG = 0 TO numEncoders - 1
   DIM codec AS ImageCodecInfo PTR = encoders + i
   PRINT "Format: "; *codec->FormatDescription
   PRINT "MimeType: "; *codec->MimeType
   PRINT "DLL: "; *codec->DllName
   PRINT "Filename Extension: "; *codec->FilenameExtension
   PRINT "--------------------------------"
NEXT

' // Cleanup
Deallocate((encoders))

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

#### Helper function

```
' ========================================================================================
' Helper function to retrieve the encoder's clsid
' Parameter:
' - wszMimeType = Mime type.
' Return value:
'   The encoder clsid.
' ========================================================================================
PRIVATE FUNCTION AfxGdipGetEncoderClsid (BYREF wszMimeType AS WSTRING) AS GUID
   ' // Initialize Gdiplus
   DIM token AS ULONG_PTR = AfxGdipInit
   IF token = 0 THEN EXIT FUNCTION
   ' // The GdipGetImageEncodersSize function gets the number of available image encoders
   ' // and the total size of the array of ImageCodecInfo structures
   DIM numEncoders AS DWORD, nSize AS DWORD
   GdipGetImageEncodersSize(@numEncoders, @nSize)
   DIM pImageCodecInfo AS ImageCodecInfo PTR
   pImageCodecInfo = CAllocate(nSize, 1)
   ' // Gets an array of ImageCodecInfo structures that contain information about the
   ' // available image encoders.
   DIM hr AS LONG = GdipGetImageEncoders(numEncoders, nSize, pImageCodecInfo)
   IF hr = 0 THEN
      DIM i AS LONG
      FOR i = 0 TO numEncoders - 1
         IF UCASE(*CAST(WSTRING PTR, pImageCodecInfo[i].MimeType)) = UCASE(wszMimeType) THEN
            FUNCTION = pImageCodecInfo[i].Clsid
            EXIT FOR
         END IF
      NEXT
   END IF
   Deallocate(pImageCodecInfo)
   ' // Shutdown Gdiplus
   GdiplusShutdown token
END FUNCTION
' ========================================================================================

' // Get the CLSID for the .jog mime type
DIM clsidEncoder AS GUID = AfxGdipGetEncoderClsid("image/png")
```
---

## GdipGetImageEncodersSize

The **GdipGetImageEncodersSize** function gets the number of available image encoders and the total size of the array of **ImageCodecInfo** structures that is returned by the **GdipGetImageEncoders** function.

```
FUNCTION GdipGetImageEncodersSize (BYVAL numEncoders AS UINT PTR, BYVAL size AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *numEncoders* | [out] Pointer to a variable that receives the number of available image encoders. |
| *size* | [out] Pointer to a variable that receives the total size, in bytes, of the array of **ImageCodecInfo** structures that is returned by **GdipGetImageEncoders**. |

#### Example

```
DIM numEncoders AS DWORD, nSize AS DWORD
GdipGetImageEncodersSize(@numEncoders, @nSize)
```
---

## GdipGetImageGraphicsContext

Creates a **Graphics** object that is associated with an **Image** object.

```
FUNCTION GdipGetImageGraphicsContext (BYVAL image AS GpImage PTR, BYVAL graphics AS GpGraphics PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object that will be associated with the new **Graphics** object. |
| *graphics* | [out] Pointer to a variable that receives the new **Graphics** object. |

#### Example

```
SUB Example_RecordMetafileFileName (BYVAL hdc AS HDC)
   DIM hStatus AS LONG
   ' // Create a Metafile object for recording
   DIM metafile AS GpMetaFile PTR
   DIM wszFileName AS WSTRING * 64 = "MetafileTest.emf"
   hStatus = GdipRecordMetafileFileName(wszFileName, hdc, EmfTypeEmfPlusDual, NULL, _
             MetafileFrameUnitGdi, "", @metafile)
   ' // Create a Graphics object that is associated with the Metafile object
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)
...
...
...
END SUB
```
---

## GdipGetInterpolationMode

Gets the interpolation mode currently set for the **Graphics** object. The interpolation mode determines the algorithm that is used when images are scaled or rotated.

```
FUNCTION GdipGetInterpolationMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL interpolationMode AS InterpolationMode PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *InterpolationMode* | [out] Pointer to a variable that receives the element of the **InterpolationMode** enumeration that specifies the interpolation mode. |

#### Interpolation mode

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| *InterpolationModeInvalid* | -1 | Used internally |
| *InterpolationModeDefault* | 0 | Specifies the default interpolation mode. |
| *InterpolationModeLowQuality* | 1 | Specifies a low-quality mode. |
| *InterpolationModeHighQuality* | 2 | Specifies a high-quality mode. |
| *InterpolationModeBilinear* | 3 | Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size. |
| *InterpolationModeBicubic* | 4 | Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size. |
| *InterpolationModeNearestNeighbor* | 5 | Specifies nearest-neighbor interpolation. |
| *InterpolationModeHighQualityBilinear* | 6 | Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking. |
| *InterpolationModeHighQualityBicubic* | 7 | Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images. |

#### Example

```
' ========================================================================================
' Retrieve Current Interpolation Mode.
' ========================================================================================
SUB Example_GetInterpolationMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   DIM mode AS InterpolationMode
   hStatus = GdipGetInterpolationMode(graphics, @mode)
   IF hStatus = StatusOk THEN
      AfxMsg "Current interpolation mode: " & WSTR(mode)
   ELSE
      AfxMsg "Failed to get interpolation mode: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetMetafileDownLevelRasterizationLimit

Gets the rasterization limit currently set for this metafile. The rasterization limit is the resolution used for certain brush bitmaps that are stored in the metafile. For a detailed explanation of the rasterization limit, see **GdipGetMetafileHeaderFromEmf**.

```
FUNCTION GdipGetMetafileDownLevelRasterizationLimit (BYVAL metafile AS GpMetafile PTR, _
   BYVAL metafileRasterizationLimitDpi AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *metafile* | [in] Pointer to the **Metafile** object. |
| *metafileRasterizationLimitDpi* | [out] Pointer to a variable that receives the rasterization limit in dots per inch (dpi). |

#### Example

```
' ========================================================================================
' Record Metafile and Set/Get Rasterization Limit
' Metafile is recorded, not loaded—required for setting the rasterization limit.
' Limit is set before drawing, which ensures it affects rasterization.
' Saved using GdipGetHemfFromMetafile, not GdipSaveImageToFile.
' ========================================================================================
SUB Example_MetafileDownLevelRasterizationLimit (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Define the frame rectangle
   DIM rcfFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Rasterization limit test"

   ' // Record a new EMF+ metafile
   DIM metafile AS GpMetafile PTR
   hStatus = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcfFrame, MetafileFrameUnitPixel, @description, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to record metafile: " & STR(hStatus)
      EXIT SUB
   END IF

   ' // Set rasterization limit (must be done before drawing)
   DIM dpiLimit AS UINT = 150
   hStatus = GdipSetMetafileDownLevelRasterizationLimit(metafile, dpiLimit)
   IF hStatus <> 0 THEN
      AfxMsg "Failed to set rasterization limit: " & STR(hStatus)
   END IF

   ' // Draw into the metafile
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 2.0, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 50.0, 50.0, 200.0, 100.0)

   ' // Flush graphics
   hStatus = GdipFlush(graphics, FlushIntentionFlush)

   ' // Retrieve rasterization limit
   DIM currentLimit AS UINT
   hStatus = GdipGetMetafileDownLevelRasterizationLimit(metafile, @currentLimit)
   IF hStatus = 0 THEN
      AfxMsg "Current rasterization limit: " & STR(currentLimit) & " DPI"
   ELSE
      AfxMsg "Failed to get rasterization limit: " & STR(hStatus)
   END IF

   ' // Save metafile to disk
   DIM hEmf AS HENHMETAFILE
   hStatus = GdipGetHemfFromMetafile(metafile, @hEmf)
   IF hEmf THEN
      DIM saved AS HENHMETAFILE = CopyEnhMetaFile(hEmf, "RasterizedOutput.emf")
      IF saved THEN DeleteEnhMetaFile(saved)
      DeleteEnhMetaFile(hEmf)
   END IF

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```

#### Example

```
' ========================================================================================
' Compare Low vs High DPI Rasterization.
' Low DPI version will look pixelated or blurry, especially with gradients or textures.
' High DPI version will appear crisp and smooth, but may result in larger file size.
' ========================================================================================
SUB Example_SetMetafileDownLevelRasterizationLimit (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   DIM rcfFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Rasterization test"

   ' --- Low DPI Metafile ---
   DIM metafileLow AS GpMetafile PTR
   hStatus = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcfFrame, MetafileFrameUnitPixel, @description, @metafileLow)
   GdipSetMetafileDownLevelRasterizationLimit(metafileLow, 72)  ' Low quality

   DIM graphicsLow AS GpGraphics PTR
   GdipGetImageGraphicsContext(metafileLow, @graphicsLow)
   DIM brush AS GpBrush PTR
   GdipCreateSolidFill(ARGB_GREEN, @brush)
   GdipFillRectangle(graphicsLow, brush, 50.0, 50.0, 200.0, 100.0)
   GdipFlush(graphicsLow, FlushIntentionFlush)
   GdipDeleteGraphics(graphicsLow)

   ' --- High DPI Metafile ---
   DIM metafileHigh AS GpMetafile PTR
   hStatus = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcfFrame, MetafileFrameUnitPixel, @description, @metafileHigh)
   GdipSetMetafileDownLevelRasterizationLimit(metafileHigh, 300)  ' High quality

   DIM graphicsHigh AS GpGraphics PTR
   GdipGetImageGraphicsContext(metafileHigh, @graphicsHigh)
   GdipFillRectangle(graphicsHigh, brush, 50.0, 50.0, 200.0, 100.0)
   GdipFlush(graphicsHigh, FlushIntentionFlush)
   GdipDeleteGraphics(graphicsHigh)

   ' --- Playback ---
   DIM playback AS GpGraphics PTR
   GdipCreateFromHDC(hdc, @playback)

   ' Label and draw low DPI version
   DIM rcf AS GpRectF = (10, 10, 100, 20)
   GdipDrawString(playback, "Low DPI", -1, NULL, @rcf, NULL, brush)
   GdipDrawImage(playback, metafileLow, 10.0, 30.0)

   ' Label and draw high DPI version
   DIM rcf2 AS GpRectF = (320, 10, 100, 20)
   GdipDrawString(playback, "High DPI", -1, NULL, @rcf2, NULL, brush)
   GdipDrawImage(playback, metafileHigh, 320.0, 30.0)

   ' Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF playback THEN GdipDeleteGraphics(playback)
   IF metafileLow THEN GdipDisposeImage(metafileLow)
   IF metafileHigh THEN GdipDisposeImage(metafileHigh)

END SUB
' ========================================================================================
```
---

## GdipGetMetafileHeaderFromEmf

Gets the header of the metafile.

```
FUNCTION GdipGetMetafileHeaderFromEmf (BYVAL hEmf AS HENHMETAFILE PTR, BYVAL header AS MetafileHeader PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hEmf* | [in] Windows handle to a metafile. |
| *header* | [out] Pointer to a variable that receives the header, which contains the attributes of the metafile. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' ========================================================================================
' Inspecting EMF Metadata with GdipGetMetafileHeaderFromEmf.
' Type: Tells you if it’s EMF, EMF+, or EMF+ Dual.
' DpiX / DpiY: Resolution of the metafile.
' Size: Total size in bytes.
' Bounds: Logical drawing bounds.
' EmfPlusFlags: Indicates if GDI+ records are present.
' This is especially useful for validating metafiles before playback or conversion.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Load an EMF file using GDI
DIM hEmf AS HENHMETAFILE
hEmf = GetEnhMetaFile("SampleMetafile.emf")
IF hEmf = 0 THEN
   PRINT "Failed to load EMF file."
   END
END IF

' // Retrieve the metafile header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromEmf(hEmf, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header: " & STR(hStatus)
   DeleteEnhMetaFile(hEmf)
   END
END IF

' // Display some header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)

' // Cleanup
DeleteEnhMetaFile(hEmf)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetMetafileHeaderFromFile

Gets the header of the metafile.

```
FUNCTION GdipGetMetafileHeaderFromFile (BYVAL filename AS WSTRING PTR, BYVAL header AS MetafileHeader PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *filename* | [in] Pointer to a wide-character string that specifies the name of an existing **Metafile** object that contains the header. |
| *header* | [out] Pointer to a variable that receives the header, which contains the attributes of the metafile. |

#### Example

```
' ========================================================================================
' Using GdipGetMetafileHeaderFromFile to Inspect a Metafile.
' What You Can Learn from the Header
' Type: Indicates if it’s EMF, EMF+, or EMF+ Dual.
' DpiX / DpiY: Resolution of the metafile.
' Bounds: Logical drawing area.
' Version: GDI+ version used to create the metafile.
' Size: Total size of the header structure.
' This function is especially useful for preflight checks before attempting to render or
' convert metafiles.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Specify the metafile path
DIM filename AS WSTRING * 64 = "SampleMetafile.emf"

' // Retrieve the header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromFile(@filename, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header: " & STR(hStatus)
   END
END IF

' // Display some header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)
PRINT "Bounds: (" & header.X & ", " & header.Y & ", " & header.Width & ", " & header.Height & ")"

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetMetafileHeaderFromMetafile

Gets the header of the metafile.

```
FUNCTION GdipGetMetafileHeaderFromMetafile (BYVAL metafile AS GpMetafile PTR, BYVAL header AS MetafileHeader PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *metafile* | [in] Pointer to a wide-character string that specifies the name of an existing **Metafile** object that contains the header. |
| *header* | [out] Pointer to a variable that receives the header, which contains the attributes of the metafile. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' ========================================================================================
' Inspecting a Metafile Object with GdipGetMetafileHeaderFromMetafile.
' Works with any GpMetafile object—whether recorded or loaded.
' Lets you inspect the metafile after transformations or drawing.
' Ideal for runtime checks, logging, or conditional rendering.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Load a metafile from disk
DIM metafile AS GpMetafile PTR
DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
IF hStatus <> 0 OR metafile = NULL THEN
   PRINT "Failed to load metafile: " & STR(hStatus)
   END
END IF

' // Retrieve the header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromMetafile(metafile, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header: " & STR(hStatus)
   GdipDisposeImage(metafile)
   END
END IF

' // Display header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)
PRINT "Bounds: (" & header.X & ", " & header.Y & ", " & header.Width & ", " & header.Height & ")"

' // Cleanup
GdipDisposeImage(metafile)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetMetafileHeaderFromStream

Gets the header of the metafile.

```
FUNCTION GdipGetMetafileHeaderFromStream (BYVAL stream AS IStream PTR, BYVAL header AS MetafileHeader PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *stream* | [in] Pointer to an **IStream** interface that points to a stream of data in a file. |
| *header* | [out] Pointer to a variable that receives the header, which contains the attributes of the metafile. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "Windows.bi"
#INCLUDE ONCE "win/shlwapi.bi"

' ========================================================================================
' Inspecting a Metafile Header from a Stream.
' Works with metafiles stored in memory, embedded resources, or custom containers.
' Lets you validate format and compatibility before playback.
' Avoids loading the full GpMetafile object if you just need metadata.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Create IStream from file
DIM stream AS IStream PTR
DIM hr AS HRESULT = SHCreateStreamOnFile("SampleMetafile.emf", STGM_READ, @stream)
IF hr <> S_OK OR stream = NULL THEN
   PRINT "Failed to create stream from file. HRESULT = " & HEX(hr)
   END
END IF

' // Retrieve the header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromStream(stream, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header from stream: " & STR(hStatus)
   stream->lpvtbl->Release(stream)
   END
END IF

' // Display header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)
PRINT "Bounds: (" & header.X & ", " & header.Y & ", " & header.Width & ", " & header.Height & ")"

' // Cleanup
stream->lpvtbl->Release(stream)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetMetafileHeaderFromEmf

Gets the header of the metafile.

```
FUNCTION GdipGetMetafileHeaderFromEmf (BYVAL hEmf AS HENHMETAFILE, BYVAL header AS MetafileHeader PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *hEmf* | [in] Windows handle to a metafile. |
| *header* | [out] Pointer to a variable that receives the header, which contains the attributes of the metafile. |

---

## GdipGetNearestColor

Gets the nearest color to the color that is passed in. This method works on 8-bits per pixel or lower display devices for which there is an 8-bit color palette.

```
FUNCTION GdipGetNearestColor (BYVAL graphics AS GpGraphics PTR, BYVAL argb AS ARGB PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *argb* | [in, out] Pointer to a variable that, on input, specifies the color to be tested and, on output, receives the nearest color found in the color palette. |

#### Example

```
' ========================================================================================
' The following example creates a Color object and fills a rectangle with that color. It
' then gets the nearest 8-bit color and fills a second rectangle with that color.
' ========================================================================================
SUB Example_GetNearestColor (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a Brush object, and fill a rectangle with that brush.
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_Violet, @brush)
   ' // Fill the rectangle.
   hStatus = GdipFillRectangle(graphics, brush, 0, 0, 100, 100)

   ' // Get the nearest 8-bit color, and fill a second rectangle with that color.
   DIM colour AS ARGB
   hStatus = GdipGetNearestColor(graphics, @colour)
   DIM brush2 AS GpBrush PTR
   hStatus = GdipCreateSolidFill(colour, @brush2)
   hStatus = GdipFillRectangle(graphics, brush, 120, 0, 100, 100)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF brush2 THEN GdipDeleteBrush(brush2)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetPageScale

Gets the scaling factor currently set for the page transformation of the **Graphics** object. The page transformation converts page coordinates to device coordinates.

```
FUNCTION GdipGetPageScale (BYVAL graphics AS GpGraphics PTR, BYVAL scale AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *scale* | [out] Pointer to a variable thatg receives the scaling factor currently set for the page transformation of the **Graphics** object. |

#### Remarks

**GdipSetPageUnit** changes the measurement unit (e.g., inches, millimeters).

**GdipSetPageScale** applies a scaling factor to that unit.

**GdipGetPageScale** retrieves the current scale factor, which affects how coordinates are transformed from page units to device units.

This is particularly useful when you're preparing content for printing or want consistent layout across devices with different DPI settings.

#### Example

```
' ========================================================================================
' The following example gets the scaling factor currently set for the page transformation
' of the Graphics object. 
' ========================================================================================
SUB Example_GetPageScale (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set page unit to inches
   hStatus = GdipSetPageUnit(graphics, UnitInch)

   ' // Set page scale to 2.0 (double size)
   hStatus = GdipSetPageScale(graphics, 2.0)

   ' // Retrieve current page scale
   DIM scale AS SINGLE
   hStatus = GdipGetPageScale(graphics, @scale)

   ' Output the scale value
   AfxMsg("Current page scale: " & WSTR(scale))

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetPageUnit

Gets the unit of measure currently set for the **Graphics** object.

```
FUNCTION GdipGetPageUnit (BYVAL graphics AS GpGraphics PTR, BYVAL unit AS GpUnit PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *unit* | [out] Pointer to a variable that receives an element of the **GpUnit** enumeration that indicates the unit of measure currently set for the **Graphics** object. |

#### Example

```
' ========================================================================================
' The following example gets the unit of measure currently set for the Graphics object.
' ========================================================================================
SUB Example_GetPageUnit (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set page unit to inches
   hStatus = GdipSetPageUnit(graphics, UnitInch)

   ' // Set page scale to 2.0 (double size)
   hStatus = GdipSetPageScale(graphics, 2.0)

   ' // Retrieve current page unit
   DIM unit AS GpUnit
   hStatus = GdipGetPageUnit(graphics, @unit)

   ' // Output the page unit
   AfxMsg("Current page unit: " & WSTR(unit))

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetPixelOffsetMode

Gets the pixel offset mode currently set for the **Graphics** object.

```
FUNCTION GdipGetPixelOffsetMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL pixelOffsetMode AS PixelOffsetMode PTR) AS GpStatus
```

PowerBA
| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pixelOffsetMode* | [out] Pointer to a variable that receives an element of the *PixelOffsetMode* enumeration that specifies the pixel offset mode. |

#### Example

```
' ========================================================================================
' Using GdipGetPixelOffsetMode to Inspect Rendering Behavior.
' PixelOffsetModeHalf is often used for high-quality rendering, aligning drawing to pixel centers.
' PixelOffsetModeNone disables offsetting, which can result in sharper but less smooth edges.
' This setting affects how lines, shapes, and text are rendered—especially when anti-aliasing is enabled.
' ========================================================================================
SUB Example_GetPixelOffsetMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Optionally set a pixel offset mode
   hStatus = GdipSetPixelOffsetMode(graphics, PixelOffsetModeHalf)

   ' // Retrieve the current pixel offset mode
   DIM offsetMode AS PixelOffsetMode
   hStatus = GdipGetPixelOffsetMode(graphics, @offsetMode)

   ' // Display the result
   DIM modeName AS STRING
   SELECT CASE offsetMode
      CASE PixelOffsetModeNone: modeName = "None"
      CASE PixelOffsetModeHalf: modeName = "Half"
      CASE PixelOffsetModeHighQuality: modeName = "HighQuality"
      CASE PixelOffsetModeHighSpeed: modeName = "HighSpeed"
      CASE PixelOffsetModeInvalid: modeName = "Invalid"
      CASE ELSE: modeName = "Unknown"
   END SELECT

   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   DIM brush AS GpSolidFill PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPixel, @font)
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   DIM layout AS GpRectF = (10.0, 10.0, 300.0, 20.0)
   hStatus = GdipDrawString(graphics, "PixelOffsetMode: " & modeName, -1, font, @layout, NULL, brush)

   ' Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF font THEN GdipDeleteFont(font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetRenderingOrigin

Gets the rendering origin currently set for the **Graphics** object. The rendering origin is used to set the dither origin for 8-bits per pixel and 16-bits per pixel dithering and is also used to set the origin for hatch brushes.

```
FUNCTION GdipGetRenderingOrigin (BYVAL graphics AS GpGraphics PTR, _
   BYVAL x AS INT_ PTR, BYVAL y AS INT_ PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *x* | [out] Pointer to a variable that receives the x-coordinate of the rendering origin. |
| *y* | [out] Pointer to a variable that receives the y-coordinate of the rendering origin. |

#### Example

```
' ========================================================================================
' This example draws two rectangles using an Hatch brush with different rendering origins.
' ========================================================================================
SUB Example_GetRenderingOrigin (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' Create a hatch brush
   DIM brush AS GpHatch PTR
   GdipCreateHatchBrush(HatchStyleCross, ARGB_BLACK, ARGB_LIGHTGRAY, @brush)

   ' // Draw first rectangle with default origin
   GdipFillRectangle(graphics, brush, 35, 50, 150, 100)

   ' // Set rendering origin and draw a second rectangle
   GdipSetRenderingOrigin(graphics, 10, 10)
   GdipFillRectangle(graphics, brush, 215, 50, 150, 100)

   ' // Get the rendering origin
   DIM AS LONG x, y
   GdipGetRenderingOrigin(graphics, @x, @y)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetSmoothingMode

Determines whether smoothing (antialiasing) is applied to the **Graphics** object.

```
FUNCTION GdipGetSmoothingMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL smoothingMode AS SmoothingMode PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *smoothingMode* | [out] Pointer to a variable that receives an element of the *SmoothingMode* enumeration that specifies whether smoothing (antialiasing) is applied to lines and curves. |

#### Return Values

If smoothing (antialiasing) is applied to the **Graphics** object, this method returns *SmoothingModeAntiAlias*. If smoothing (antialiasing) is not applied to the **Graphics** object, this method returns *SmoothingModeNone*. *SmoothingModeAntiAlias* and *SmoothingModeNone* are elements of the **SmoothingMode** enumeration.

#### Remarks

To get the render quality level for text, use the **GetTextRenderingHint** method.

#### Example

```
' ========================================================================================
' The following example creates a solid brush based on a color that has an alpha component
' of 128. The code uses that brush to paint two ellipses. The first ellipse is painted with
' the compositing mode set to CompositingQualityHighSpeed, and the second ellipse is painted
' with the compositing mode set to CompositingQualityHighQuality.
' ========================================================================================
SUB Example_SetSmoothingMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush object with an alpha-blended color.
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @brush)

   ' // Set the smoothing mode to SmoothingModeHighSpeed, and fill an ellipse.
   hStatus = GdipSetSmoothingMode(graphics, SmoothingModeHighSpeed)
   hStatus = GdipFillEllipse(graphics, brush, 20, 50, 200, 100)

   ' // Get the smoothing mode
   DIM mode AS SmoothingMode
   hStatus = GdipGetSmoothingMode(graphics, @mode)
   AfxMsg WSTR(mode)

   ' // Set the smoothing mode to SmoothingModeHighQuality, and fill an ellipse.
   hStatus = GdipSetSmoothingMode(graphics, SmoothingModeHighQuality)
   hStatus = GdipFillEllipse(graphics, brush, 230, 50, 200, 100)

   ' // Get the smoothing mode
   hStatus = GdipGetSmoothingMode(graphics, @mode)
   
   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetTextContrast

Gets the contrast value currently set for the **Graphics** object. The contrast value is used for antialiasing text.

```
FUNCTION GdipGetTextContrast (BYVAL graphics AS GpGraphics PTR, BYVAL contrast AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *contrast* | [out] Pointer to a variable that receives the contrast value for antialiasing text. |
```
' ========================================================================================
' This example sets and retrieves the text contrast level of a Graphics object.
' It draws text with a high contrast setting to demonstrate its effect.
' ========================================================================================
SUB Example_SetTextContrast (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set text contrast to maximum (12)
   hStatus = GdipSetTextContrast(graphics, 12)

   ' // Retrieve current contrast setting
   DIM contrast AS UINT
   hStatus = GdipGetTextContrast(graphics, @contrast)

   ' // Create font and brush
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   IF hStatus = StatusOk THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixelsX(12, TRUE), FontStyleRegular, UnitPoint, @font)
      GdipDeleteFontFamily(fontFamily)
    END IF

   ' // Create a black brush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' Draw text with high contrast
   DIM rcf AS GpRectF
   DIM wszText AS WSTRING * 128
   wszText = "Text contrast level: " & contrast
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, NULL, brush)

   ' // Cleanup
   IF font THEN GdipDeleteFont(font)
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetTextRenderingHint

Gets the text rendering mode currently set for the **Graphics** object.

```
FUNCTION GdipGetTextRenderingHint (BYVAL graphics AS GpGraphics PTR, _
   BYVAL mode AS TextRenderingHint PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *mode* | [out] Pointer to a variable that receives an element of the **TextRenderingHint** enumeration that specifies the process currently used by the **Graphics** object to render text. |

#### Example

```
' ========================================================================================
' The following example sets the text rendering hint to two different values and draws text
' to demonstrate each value.
' ========================================================================================
SUB Example_SetTextRenderingHint (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

 ' // Set the text rendering hint to TextRenderingHintSingleBitPerPixel.
   hStatus = GdipSetTextRenderingHint(graphics, TextRenderingHintSingleBitPerPixel)

   ' // Create the font
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   IF hStatus = StatusOk THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPoint, @font)
      GdipDeleteFontFamily(fontFamily)
   END IF   

   ' // Create a solid brush
   DIM brush AS GpBRush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Draw text
   DIM rcf AS GpRectF, format AS GpStringFormat PTR
   DIM wszText AS WSTRING *  128 = "Low quality rendering"
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, format, brush)

   ' // Get the text rendering hint
   DIM mode AS TextRenderingHint
   hStatus = GdipGetTextRenderingHint(graphics, @mode)
   AfxMsg WSTR(mode)

   ' // Set the text rendering hint to TextRenderingHintAntiAlias.
   hStatus = GdipSetTextRenderingHint(graphics, TextRenderingHintAntiAlias)

   ' // Get the text rendering hint
   hStatus = GdipGetTextRenderingHint(graphics, @mode)
   AfxMsg WSTR(mode)

   ' // Draw more text to demonstrate the difference.
   rcf.y = 50
   wszText = "High quality rendering"
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, format, brush)

   ' // Cleanup
   IF font THEN GdipDeleteFont(font)
   IF brush THEN GdipDeleteBrush(brush)
   IF format THEN GdipDeleteStringFormat(format)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetVisibleClipBounds

Gets a rectangle that encloses the visible clipping region of the **Graphics** object. The visible clipping region is the intersection of the clipping region of this Graphics object and the clipping region of the window.

```
FUNCTION GdipGetVisibleClipBounds (BYVAL graphics AS GpGraphics PTR, BYVAL rect AS GpRectF PTR) AS GpStatus
```
```
FUNCTION GdipGetVisibleClipBoundsI (BYVAL graphics AS GpGraphics PTR, BYVAL rect AS GpRect PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *rect* | [out] Pointer to a **GpRect** structure that receives the rectangle that encloses the visible clipping region. |

#### Example

```
' ========================================================================================
' The following example sets the clipping region for the Graphics object. It then gets a
' rectangle that encloses the visible clipping region and fills that rectangle.
' ========================================================================================
SUB Example_GetVisibleClipBounds (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set clipping region to a rectangle
   hStatus = GdipSetClipRect(graphics, 50, 50, 300, 150, CombineModeReplace)

   ' // Get the visible clipping bounds
   DIM boundRect AS GpRectF
   hStatus = GdipGetVisibleClipBounds(graphics, @boundRect)

   ' // Create a solid brush (opaque red)
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @brush)

   ' // Fill the bounding rectangle
   hStatus = GdipFillRectangle(graphics, brush, boundRect.X, boundRect.Y, boundRect.Width, boundRect.Height)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGetWorldTransform

Gets the world transformation matrix of the **Graphics** object.

```
FUNCTION GdipGetWorldTransform (BYVAL graphics AS GpGraphics PTR, BYVAL matrix AS GpMatrix PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *matrix* | [out] Pointer to a variable that receives the transformation matrix. |

#### Example

```
' ========================================================================================
' The following example calls the GdipRotateWorldTransform function to set the world
' transformation matrix of the Graphics object. Then the code calls the GdipGetWorldTransform
' method of the Graphics object to obtain its world transformation matrix (which now represents
' a 30-degree rotation). The call to GetElements copies the elements of the retrieved
' matrix to an array.
' ========================================================================================
SUB Example_GetWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Apply rotation transform
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderPrepend)

   ' // Create a matrix object
   DIM matrix AS GpMatrix PTR
   hStatus = GdipCreateMatrix(@matrix)

   ' // Get current world transform matrix
   hStatus = GdipGetWorldTransform(graphics, @matrix)

   ' // Extract matrix elements
   DIM elements(5) AS sINGLE
   hStatus = GdipGetMatrixElements(matrix, @elements(0))

    ' // Inspect elements
   FOR j AS LONG = 0 To 5
      OutputDebugStringW("Element(" & WSTR(j) & ") = " & WSTR(elements(j)))
   NEXT

    ' Cleanup
    If matrix Then GdipDeleteMatrix(matrix)
    If graphics Then GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipGraphicsClear

Clears a **Graphics** object to a specified color.

```
FUNCTION GdipGraphicsClear (BYVAL graphics AS GpGraphics PTR, BYVAL color AS ARGB) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *color* | [in] ARGB color to paint the background. |

#### Example

```
' ========================================================================================
' Using GdipGraphicsClear to Reset the Drawing Surface.
' ========================================================================================
SUB Example_GdipGraphicsClar (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Clear the surface to light gray
   hStatus = GdipGraphicsClear(graphics, ARGB_LIGHTGRAY)

   ' // Draw something after clearing
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 3.0, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 50, 50, 150, 100)

   ' // Optional: draw confirmation text
   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   DIM brush AS GpSolidFill PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPixel, @font)
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   DIM layout AS GpRectF = (10.0, 10.0, 300.0, 20.0)
   hStatus = GdipDrawString(graphics, "Canvas cleared", -1, font, @layout, NULL, brush)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF font THEN GdipDeleteFont(font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================

```
---

## GdipGraphicsSetAbort

Not used in Microsoft Windows GDI+ versions 1.0 and 1.1.

```
FUNCTION GdipGraphicsSetAbort (BYVAL graphics AS GpGraphics PTR, _
   BYVAL pIAbort AS GdiplusAbort PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pIAbort* | [in] Pointer to the abort callback function. |

---

## GdipIsClipEmpty

Determines whether the clipping region of the **Graphics** object is empty.

```
FUNCTION GdipIsClipEmpty (BYVAL graphics AS GpGraphics PTR, _
   BYVAL pIAbresultort AS BOOL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pIAbresultort* | [out] Pointer to a variable that receives a boolean value that determines whether the clipping region of this Graphics object is empty (TRUE) or not (FALSE). |

#### Remarks

If the clipping region of a **Graphics** object is empty, there is no area left in which to draw. Consequently, nothing will be drawn when the clipping region is empty.

#### Example

```
' ========================================================================================
' The following example determines whether the clipping region is empty and, if it isn't,
' draws a rectangle.
' ========================================================================================
SUB Example_IsClipEmpty (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Check if the clipping region is empty
   DIM isEmpty AS BOOL
   hStatus = GdipIsClipEmpty(graphics, @isEmpty)

   ' // If not empty, draw a rectangle
   DIM pen AS GpPen PTR
   IF isEmpty = FALSE THEN
      hStatus = GdipCreatePen1(ARGB_BLACK, 3.0, UnitPixel, @pen)
      hStatus = GdipDrawRectangle(graphics, pen, 0, 0, 100, 100)
   END IF

   ' // Cleanup
   IF pen Then GdipDeletePen(pen)
   IF graphics Then GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipIsVisibleClipEmpty

Determines whether the visible clipping region of the **Graphics** object is empty. The visible clipping region is the intersection of the clipping region of the **Graphics** object and the clipping region of the window.

```
FUNCTION GdipIsVisibleClipEmpty (BYVAL graphics AS GpGraphics PTR, _
   BYVAL result AS BOOL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *result* | [out] Pointer to a variable that receives a boolean value that determines whether the visible clipping region of this Graphics object is empty (TRUE) or not (FALSE). |

#### Remarks

If the clipping region of a **Graphics** object is empty, there is no area left in which to draw. Consequently, nothing will be drawn when the clipping region is empty.

#### Example

```
' ========================================================================================
' The following example determines whether the clipping region is empty and, if it isn't,
' draws a rectangle.
' ========================================================================================
SUB Example_IsVisibleClipEmpty (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Check if the visible clipping region is empty
   DIM isVisibleEmpty AS BOOL
   hStatus = GdipIsVisibleClipEmpty(graphics, @isVisibleEmpty)

   ' If not empty, draw a rectangle
   IF isVisibleEmpty = FALSE THEN
      DIM pen AS GpPen PTR
      hStatus = GdipCreatePen1(GDIP_ARGB(255, 0, 0, 0), 3.0, UnitPixel, @pen)
      hStatus = GdipDrawRectangle(graphics, pen, 0, 0, 100, 100)
      IF pen THEN GdipDeletePen(pen)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipIsVisiblePoint

Determines whether the specified point is inside the visible clipping region of this Graphics object. The visible clipping region is the intersection of the clipping region of the **Graphics** object and the clipping region of the window.

```
FUNCTION GdipIsVisiblePoint (BYVAL graphics AS GpGraphics PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL, BYVAL reault AS BOOL PTR) AS GpStatus
```
```
FUNCTION GdipIsVisiblePoint (BYVAL graphics AS GpGraphics PTR, _
   BYVAL x AS INT_, BYVAL y AS INT_, BYVAL reault AS BOOL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *x* | [in] The x-coordinate of the point to test. |
| *y* | [in] The x-coordinate of the point to test. |
| *reault* | [out] Pointer to a variable that receives a boolean value that determines whether the specified point is inside the visible clipping region of the **Graphics** object (TRUE) or not (FALSE). |

#### Example

```
' ========================================================================================
' The following example creates a Point object and determines whether the point is visible
' on the display device. If it is, it fills an ellipse that represents the point.
' ========================================================================================
SUB Example_IsVisiblePoint (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Define the point to test
   DIM x AS SINGLE = 100.0
   DIM y AS SINGLE = 100.0

   ' // Check if the point is visible in the current clipping region
   DIM isVisible AS BOOL
   hStatus = GdipIsVisiblePoint(graphics, x, y, @isVisible)

   ' // If visible, draw a small ellipse at that point
   IF isVisible THEN
      DIM brush AS GpBrush PTR
      hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)
      hStatus = GdipFillEllipse(graphics, brush, x, y, 5.0, 5.0)
      IF brush THEN GdipDeleteBrush(brush)
   END IF

   ' // Cleanup
   IF graphics Then GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipIsVisibleRect

Determines whether the specified point is inside the visible clipping region of this Graphics object. The visible clipping region is the intersection of the clipping region of the **Graphics** object and the clipping region of the window.

```
FUNCTION GdipIsVisibleRect (BYVAL graphics AS GpGraphics PTR, BYVAL x AS REAL, BYVAL y AS REAL, _
   BYVAL nWidth AS REAL, BYVAL nHeight AS REAL, BYVAL reault AS BOOL PTR) AS GpStatus
```
```
FUNCTION GdipIsVisibleRect (BYVAL graphics AS GpGraphics PTR, BYVAL x AS INT_, BYVAL y AS INT_, _
   BYVAL nWidth AS INT_, BYVAL nHeight AS INT_, BYVAL reault AS BOOL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *x* | [in] The x-coordinate of the rectangle to test. |
| *y* | [in] The x-coordinate of the rectangle to test. |
| *reault* | [out] Pointer to a variable that receives a boolean value that determines whether the specified rectangle intersects the visible clipping region of this Graphics object (TRUE) or not (FALSE). |

#### Example

```
' ========================================================================================
' The following example creates a GpRectF object and determines whether the rectangle
' is contained within the visible clip region of the Graphics object. If it is, fills the
' rectangle.
' ========================================================================================
SUB Example_IsVisibleRect (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Define the rectangle to test
   DIM visibleRect AS GpRectF = (0.0, 0.0, 100.0, 100.0)

   ' // Check if the rectangle is visible in the current clipping region
   DIM isVisible AS BOOL
   hStatus = GdipIsVisibleRect(graphics, visibleRect.X, visibleRect.Y, visibleRect.Width, visibleRect.Height, @isVisible)

   ' If visible, fill the rectangle
   IF isVisible THEN
      DIM brush AS GpBRush PTR
      hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)
      hStatus = GdipFillRectangle(graphics, brush, visibleRect.X, visibleRect.Y, visibleRect.Width, visibleRect.Height)
      IF brush THEN GdipDeleteBrush(brush)
   End If

   ' // Cleanup
   IF graphics Then GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipMultiplyWorldTransform

Updates the **Graphics** object's world transformation matrix with the product of itself and another matrix.

```
FUNCTION GdipMultiplyWorldTransform (BYVAL graphics AS GpGraphics PTR, _
   BYVAL matrix AS GpMatrix PTR, BYVAL order AS GpMatrixOrder) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *matrix* | [in] Pointer to a matrix that will be multiplied by the world transformation matrix of the **Graphics** object. |
| *order* | [in] Element of the **MatrixOrder** enumeration that specifies the order of multiplication. *MatrixOrderPrepend* specifies that the passed matrix is on the left, and *MatrixOrderAppend* specifies that the passed matrix is on the right. The default value is *MatrixOrderPrepend*. |

#### Example

```
' ========================================================================================
' The following example calls the GdipRotateWorldTransform function to fill its world
' transformation matrix with the elements that represent a 30-degree rotation. Then the
' code calls the GdipMultiplyWorldTransform function to replace the world transformation
' matrix (which represents the 30-degree rotation) of the Graphics object with the product
' of itself and a translation matrix. At that point, the world transformation matrix of
' the Graphics object represents a composite transformation: first rotate, then translate.
' Finally, the code calls the GdipDrawEllipse function to draw an ellipse that is rotated
' and translated.
' ========================================================================================
SUB Example_MultiplyWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create transformation matrix and apply translation
   DIM matrix AS GpMatrix PTR
   hStatus = GdipCreateMatrix(@matrix)
   hStatus = GdipTranslateMatrix(@Matrix, 150.0, 100.0, MatrixOrderPrepend)

    ' // Apply rotation first
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderPrepend)
    ' // Then apply translation via matrix multiplication
   hStatus = GdipMultiplyWorldTransform(graphics, matrix, MatrixOrderAppend)
   ' // Create pen and draw ellipse
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1, UnitPixel, @pen)
   hStatus = GdipDrawEllipse(graphics, pen, -80, -40, 160, 80)

   ' // Cleanup
   IF matrix THEN GdipDeleteMatrix(matrix)
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipPlayMetafileRecord

Plays a metafile record.

```
FUNCTION GdipPlayMetafileRecord (BYVAL metafile AS GpMetafile PTR, _
   BYVAL recordType AS EmfPlusRecordType, BYVAL flags AS UINT, BYVAL dataSize AS UINT, _
   BYVAL data AS BYTE PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *metafile* | [in] Pointer to the **Metafile** object. |
| *recordtype* | [in] Element of the **EmfPlusRecordType** enumeration that specifies the type of metafile record to be played. |
| *flags* | [in] Set of flags that specify attributes of the record to be played. |
| *dataSize* | [in] Long integer value that specifies the number of bytes contained in the record data. |
| *data* | [in] Pointer to an array of bytes that contains the record data. |

---

## GdipRecordMetafile

Creates a **Metafile** object for recording.

```
FUNCTION GdipRecordMetafile (BYVAL referenceHdc AS HDC, BYVAL type AS EmfType, _
   BYVAL frameRect AS GpRectF PTR, BYVAL frameUnit AS MetafileFrameUnit, _
   BYVAL description AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```
```
FUNCTION GdipRecordMetafileI (BYVAL referenceHdc AS HDC, BYVAL type AS EmfType, _
   BYVAL frameRect AS GpRect PTR, BYVAL frameUnit AS MetafileFrameUnit, _
   BYVAL description AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *referenceHdc* | [in] Windows handle to a device context that contains attributes of the display device that is used to record the metafile. |
| *type* |[in] Element of the EmfType enumeration that specifies the type of metafile that will be recorded. The default value is *EmfTypeEmfPlusDual*. !
| *frameRect* | [in] Reference to a rectangle that bounds the metafile display. |
| *frameUnit* | [in] Element of the **MetafileFrameUnit** enumeration that specifies the unit of measure for *frameRect*. The default value is *MetafileFrameUnitGdi*. |
| *description* | [in] Pointer to a wide-character string that specifies the descriptive name of the metafile. The default value is NULL. |
| *metafile* | [out] Pointer to a **GpMetafile** variable that receives a pointer to the new created **Metafile** object. |

#### Remarks

When recording to a file, the file must be writable, and GDI+ must be able to obtain an exclusive lock on the file.

#### Example

```
' ========================================================================================
' Using GdipRecordMetafile to create and save a metafile.
' ========================================================================================
SUB Example_RecordMetafile (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' Record the metafile
   DIM metafile AS GpMetafile PTR
   DIM rcFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Recorded with GdipRecordMetafile"
   hStatus = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcFrame, MetafileFrameUnitPixel, @description, @metafile)

   ' Create graphics context from metafile
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)

   ' Draw into the metafile
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 2.0, UnitPixel, @pen)
   hStatus = GdipDrawEllipse(graphics, pen, 50.0, 50.0, 200.0, 100.0)

   ' Flush graphics to ensure commands are committed
   hStatus = GdipFlush(graphics, FlushIntentionFlush)

   ' Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

   ' Dispose metafile — this finalizes and writes it to disk
   IF metafile THEN
      DIM hEmf AS HENHMETAFILE
      hStatus = GdipGetHemfFromMetafile(metafile, @hEmf)
      IF hEmf THEN
         ' Save to file
         CopyEnhMetaFile(hEmf, "recorded.emf")
         DeleteEnhMetaFile(hEmf)
         AfxMsg "Metafile saved as ""recorded.emf"""
      END IF
      GdipDisposeImage(metafile)
   END IF

END SUB
' ========================================================================================
```
---

## GdipRecordMetafileFileName

Creates a **Metafile** object for recording.

```
FUNCTION GdipRecordMetafileFileName (BYVAL fileName AS WSTRING PTR, BYVAL referenceHdc AS HDC, _
   BYVAL type AS EmfType, BYVAL frameRect AS GpRectF PTR, BYVAL frameUnit AS MetafileFrameUnit, _
   BYVAL description AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```
```
FUNCTION GdipRecordMetafileFileNameI (BYVAL fileName AS WSTRING PTR, BYVAL referenceHdc AS HDC, _
   BYVAL type AS EmfType, BYVAL frameRect AS GpRect PTR, BYVAL frameUnit AS MetafileFrameUnit, _
   BYVAL description AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *fileName* | [in] Pointer to a wide-character string that specifies the name of the file in which the metafile will be saved. |
| *referenceHdc* | [in] Windows handle to a device context that contains attributes of a display device. |
| *type* |[in] Element of the **EmfType** enumeration that specifies the type of metafile that will be recorded. The default value is *EmfTypeEmfPlusDual*. !
| *frameRect* | [in] Reference to a rectangle that bounds the metafile display. |
| *frameUnit* | [in] Element of the **MetafileFrameUnit** enumeration that specifies the unit of measure for *frameRect*. The default value is *MetafileFrameUnitGdi*. |
| *description* | [in] Pointer to a wide-character string that specifies the descriptive name of the metafile. The default value is NULL. |
| *metafile* | [out] Pointer to a **GpMetafile** variable that receives a pointer to the new created **Metafile** object. |

#### Remarks

When recording to a file, the file must be writable, and GDI+ must be able to obtain an exclusive lock on the file.

#### Example

```
' ========================================================================================
' The following example creates a Metafile. The code uses the Metafile to record a sequence
' of graphics commands and then saves the recorded commands in a file named MetafileTest.emf.
' Note that the function that creates the metafile (GdipRecordMetafileFileName) receives a
' device context handle, and we retrieve a Graphics handle calling the GdipGetImageGraphicsContext
' function passing the metafile handle. The recording stops (and the recorded commands are
' saved to the file) when the Graphics handle is deleted with GdipDeleteGraphics. To display
' the metafile, a new Graphics handle is retrieved calling the GdipCreateFromHDC function
' and passing the Graphics and Metafile handles to the GdipDrawImage function. Note that
' the code uses the same Metafile handle to record and to display (play back) the metafile.
' A metafile contains its own graphics state, which is defined by the Graphics object used
' to record the metafile. Any properties of the Graphics object (clip region, world
' transformation, smoothing mode, and the like) that you set while recording the metafile
' will be stored in the metafile. When you display the metafile, the drawing will be done
' according to those stored properties.
' ========================================================================================
SUB Example_RecordMetafileFileName (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a Metafile object for recording
   DIM metafile AS GpMetaFile PTR
   DIM wszFileName AS WSTRING * 64 = "MetafileTest.emf"
   hStatus = GdipRecordMetafileFileName(wszFileName, hdc, EmfTypeEmfPlusDual, NULL, _
             MetafileFrameUnitGdi, "", @metafile)
   IF hStatus <> StatusOk THEN EXIT SUB

   ' // Create a Graphics object that is associated with the Metafile object
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)

   ' // Get the DPI scaling ratios
   DIM dpiX AS SINGLE
   hStatus = GdipGetDpiX(graphics, @dpiX)
   DIM rxRatio AS SINGLE = dpiX / 96
   DIM dpiY AS SINGLE
   hStatus = GdipGetDpiY(graphics, @dpiY)
   Dim ryRatio AS SINGLE = dpiY / 96

'   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a pen and a solid brush
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_LIGHTGREEN, 1 * rxRatio, UnitPixel, @greenPen)
   ' // Add a rectangle and an ellipse to the metafile
   hStatus = GdipDrawRectangle(graphics, greenPen, 50, 10, 25, 75)
   hStatus = GdipDrawEllipse(graphics, greenPen, 100, 10, 25, 75)
   ' // Add an ellipse (drawn with antialiasing) to the metafile.
   hStatus = GdipSetSmoothingMode(graphics, SmoothingModeHighQuality)
   hStatus = GdipDrawEllipse(graphics, greenPen, 150, 10, 25, 75)
   ' // Add some text (drawn with antialiasing) to the metafile.
   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   IF fontFamily THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(18, TRUE), FontStyleRegular, UnitPixel, @font)
      GdipDeleteFontFamily(fontFamily)
   END IF
   hStatus = GdipSetTextRenderingHint(graphics, TextRenderingHintAntiAlias)
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderPrepend)
   DIM wszText AS WSTRING * 64 = "Smooth Text"
   DIM rcf AS GpRectF
   rcf.x = 50.0 : rcf.y = 50.0
   DIM solidBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @solidBrush)
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, NULL, solidBrush)
   ' // Stop recording by deleting the Graphics object
   GdipDeleteGraphics(graphics)
   ' // Free resources
   IF font THEN GdipDeleteFont(font)
   IF solidBrush THEN GdipDeleteBrush(solidBrush)
   IF greenPen THEN GdipDeletePen(greenPen)

   ' // Create a Graphics object that is associated with the device context
   DIM playbackGraphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @playbackGraphics)
   IF playbackGraphics THEN
      ' // Display the metafile
       hStatus = GdipDrawImage(playbackGraphics, metafile, 60 * rxRatio, 10 * ryRatio)
      ' // Delete the Graphics object
      GdipDeleteGraphics(playbackGraphics)
   END IF

   ' // Dispose the Metafile object
   IF @metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipRecordMetafileStream

Creates a **Metafile** object for recording to an **IStream** interface.

```
FUNCTION GdipRecordMetafileStream (BYVAL stream AS IStream PTR, BYVAL referenceHdc AS HDC, _
   BYVAL type AS EmfType, BYVAL frameRect AS GpRectF PTR, BYVAL frameUnit AS MetafileFrameUnit, _
   BYVAL description AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```
```
FUNCTION GdipRecordMetafileStreamI (BYVAL stream AS IStream PTR, BYVAL referenceHdc AS HDC, _
   BYVAL type AS EmfType, BYVAL frameRect AS GpRect PTR, BYVAL frameUnit AS MetafileFrameUnit, _
   BYVAL description AS WSTRING PTR, BYVAL metafile AS GpMetafile PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *stream* | [in] Pointer to a **IStream** interface that points to a stream of data in a file. When the commands are recorded, they will be saved to this stream. |
| *type* |[in] Element of the **EmfType** enumeration that specifies the type of metafile that will be recorded. The default value is *EmfTypeEmfPlusDual*. !
| *frameRect* | [in] Reference to a rectangle that bounds the metafile display. |
| *frameUnit* | [in] Element of the **MetafileFrameUnit** enumeration that specifies the unit of measure for *frameRect*. The default value is *MetafileFrameUnitGdi*. |
| *description* | [in] Pointer to a wide-character string that specifies the descriptive name of the metafile. The default value is NULL. |
| *metafile* | [out] Pointer to a **GpMetafile** variable that receives a pointer to the new created **Metafile** object. |

#### Remarks

When recording to a file, the file must be writable, and GDI+ must be able to obtain an exclusive lock on the file.

#### Example

```
' ========================================================================================
' Recording a Metafile to an IStream.
' Avoids writing to disk—great for embedded or transient graphics.
' Can be reused or saved later using GetHGlobalFromStream and CopyEnhMetaFile.
' Enables advanced scenarios like metafile serialization or embedding in custom formats.
' ========================================================================================
SUB Example_RecordMetafileStream (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create an IStream for memory storage
   DIM stream AS IStream PTR
   hStatus = CreateStreamOnHGlobal(0, TRUE, @stream)
   IF hStatus <> 0 OR stream = NULL THEN
      AfxMsg "Failed to create memory stream."
      EXIT SUB
   END IF

   ' // Define the frame rectangle
   DIM rcFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Metafile recorded to stream"

   ' // Record metafile to stream
   DIM metafile AS GpMetafile PTR
   hStatus = GdipRecordMetafileStream(stream, hdc, EmfTypeEmfPlusDual, @rcFrame, MetafileFrameUnitPixel, @description, @metafile)
   IF hStatus <> 0 THEN
      AfxMsg "GdipRecordMetafileStream failed: " & STR(hStatus)
      stream->lpvtbl->Release(stream)
      EXIT SUB
   END IF

   ' // Create graphics object from metafile
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)

   ' // Draw something into the metafile
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 2.0, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 50.0, 50.0, 200.0, 100.0)

   ' // Flush and cleanup
   hStatus = GdipFlush(graphics, FlushIntentionFlush)
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

   ' // Playback: create graphics from HDC and draw the metafile
   DIM playbackGraphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @playbackGraphics)
   hStatus = GdipDrawImage(playbackGraphics, metafile, 10.0, 10.0)

   ' // Cleanup
   IF playbackGraphics THEN GdipDeleteGraphics(playbackGraphics)
   IF metafile THEN GdipDisposeImage(metafile)
   IF stream THEN stream->lpvtbl->Release(stream)

END SUB
' ========================================================================================
```
---

## GdipReleaseDC

Releases a device context handle obtained by a previous call to the **GdipGetDC** function.

```
FUNCTION GdipReleaseDC (BYVAL graphics AS GpGraphics PTR, BYVAL hdc AS HDC) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *hdc* | [in] Handle to a device context obtained by a previous call to the **GdipGetDC** function. |

---

## GdipResetClip

Sets the clipping region of the **Graphics** object to an infinite region.

```
FUNCTION GdipResetClip (BYVAL graphics AS GpGraphics PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |

#### Example

```
' ========================================================================================
' The following example creates a Graphics object and sets its clipping region to a rectangle.
' The code fills two ellipses that intersect the rectangular clipping region. The first
' ellipse is clipped, but the second ellipse is not clipped because it is filled after a
' call to GdipResetClip.
' ========================================================================================
SUB Example_ResetClip (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set the clipping region, and draw its outline.
   hStatus = GdipSetClipRect(graphics, 100, 50, 200, 120, CombineModeReplace)
   DIM blackPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2, UnitPixel, @blackPen)
   hStatus = GdipDrawRectangle(graphics, blackPen, 100, 50, 200, 120)

   ' // Fill a clipped ellipse in red.
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @redBrush)
   hStatus = GdipFillEllipse(graphics, redBrush, 80, 40, 100, 70)

   ' // Reset the clipping region.
   hStatus = GdipResetClip(graphics)

   ' // Fill an unclipped ellipse with blue.
   DIM blueBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @blueBrush)
   hStatus = GdipFillEllipse(graphics, blueBrush, 160, 150, 100, 60)

   ' // Cleanup
   IF blackPen THEN GdipDeletePen(blackPen)
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF blueBrush THEN GdipDeleteBrush(blueBrush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipResetPageTransform

Resets the page transform matrix to identity.

```
FUNCTION GdipResetPageTransform (BYVAL graphics AS GpGraphics PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |

#### Example

```
' ========================================================================================
' This example draws a rectangle using milimeters scaled by 2, clears that setting using
' GdipResetPageTransform and draws a second rectangle using pixels.
' ========================================================================================
SUB Example_ResetPageTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96

   ' // Set custom page transformation
   hStatus = GdipSetPageUnit(graphics, UnitMillimeter)
   hStatus = GdipSetPageScale(graphics, 2.0)

   ' Draw a rectangle using millimeters
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1.0, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 0, 0, 30, 20)  ' 3cm x 2cm

   ' // Reset page transform to default (UnitPixel, scale 1.0)
   hStatus = GdipResetPageTransform(graphics)
   ' // Set the scale transform to the dpi ratios
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Draw another rectangle using default pixel units
   hStatus = GdipDrawRectangle(graphics, pen, 270, 0, 100, 100)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipResetWorldTransform

Resets the world transformation matrix of the **Graphics** to the identity matrix.

```
FUNCTION GdipResetWorldTransform (BYVAL graphics AS GpGraphics PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |

#### Example

```
' ========================================================================================
' The following example sets the world transformation of a Graphics object to a 45-degree
' rotation and then draws a rectangle. The code calls the GdipResetWorldTransform method
' of the Graphics object and then draws a second rectangle. No rotation transformation is
' applied to the second rectangle.
' ========================================================================================
SUB Example_ResetWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

 ' // Rotate the transformation and draw a rectangle.
   hStatus = GdipRotateWorldTransform(graphics, 45.0, MatrixOrderPrepend)
   DIm blackPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 1, UnitPixel, @blackPen)
   hStatus = GdipDrawRectangle(graphics, blackPen, 100, 0, 100, 50)

   ' // Reset the transformation to identity, and draw a second rectangle.
   hStatus = GdipResetWorldTransform(graphics)
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1, UnitPixel, @redPen)
   hStatus = GdipDrawRectangle(graphics, redPen, 100, 0, 100, 50)

   ' // Cleanup
   IF redPen THEN GdipDeletePen(redPen)
   IF blackPen THEN GdipDeletePen(blackPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipRestoreGraphics

Sets the state of the **Graphics** object to the state stored by a previous call to the **GdipSaveGraphics** function.

```
FUNCTION GdipRestoreGraphics (BYVAL graphics AS GpGraphics PTR, _
   BYVAL state AS GraphicsState) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *state* | [in] 32-bit value (returned by a previous call to the **GdipSaveGraphics** function) that identifies a block of saved state. |

#### Remarks

When you call the **GdipSaveGraphics** function, an information block that holds the state of the **Graphics** object is put on a stack. The **GdipSaveGraphics** function returns a value that identifies that information block. When you pass the identifying value to the **GdipRestoreGraphics** method, the information block is removed from the stack and is used to restore the **Graphics** object to the state it was in at the time of the **GdipSaveGraphics** call. Note that the identifier returned by a given call to the **GdipSaveGraphics** function can be passed only once to the **GdipRestoreGraphics** function.

Calls to the **GdipSaveGraphics** function can be nested; that is, you can call the **GdipSaveGraphics** function several times before you call the **GdipRestoreGraphics** function. Each time you call the **GdipSaveGraphics** function, an information block is put on the stack, and you receive an identifier for the information block. When you pass one of those identifiers to the **GdipRestoreGraphics** function, the **Graphics** object is returned to the state it was in at the time of the **GdipSaveGraphics** call that returned that particular identifier. The information block placed on the stack by that **GdipSaveGraphics** call is removed from the stack, and all information blocks placed on that stack after that **GdipSaveGraphics** call are also removed.

Calls to the **GdipBeginContainer** function place information blocks on the same stack as calls to the **GdipSaveGraphics** function. Just as a **GdipRestoreGraphics** call is paired with a **GdipSaveGraphics** call, an **GdipEndContainer** call is paired with a **GdipBeginContainer** call.

Caution When you call **GdipRestoreGraphics**, all information blocks placed on the stack (by **GdipRestoreGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipSaveGraphics** are removed from the stack. Likewise, When you call **GdipEndContainer**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipBeginContainer** are removed from the stack.

#### Example

```
' ========================================================================================
' Restoring Only the First of Two Nested Saved States
' The following example sets the world transformation of a Graphics object to a rotation and
' then saves the state of the Graphics object. Next, the code calls GdipTranslateWorldTransform,
' and saves the state again. Then the code calls ScaleTransform. At that point, the world
' transformation of the Graphics object is a composite transformation: first rotate, then
' translate, then scale. The code uses a red pen to draw an ellipse that is transformed by
' that composite transformation.
' The code passes state1, which was returned by the first call to Save, to the GdipRestoreGraphics
' function, and draws the ellipse again using a green pen. The green ellipse is rotated but
' not translated or scaled.
' Next the code attempts to restore the state identified by state2. The attempt fails because
' the call GdipRestoreGraphics(state1) removed the information blocks identified by both
' state1 and state2 from the stack.
' ========================================================================================
SUB Example_RestoreGraphics (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Apply rotation
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderPrepend)
   DIM state1 AS GraphicsState
   hStatus = GdipSaveGraphics(graphics, @state1)

   ' // Apply translation
   hStatus = GdipTranslateWorldTransform(graphics, 100.0, 0.0, MatrixOrderAppend)
   DIM state2 AS GraphicsState
   hStatus = GdipSaveGraphics(graphics, @state2)

   ' // Apply scaling
   hStatus = GdipScaleWorldTransform(graphics, 1.0, 3.0, MatrixOrderAppend)

   ' // Draw red ellipse (rotate + translate + scale)
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1.0, UnitWorld, @redPen)
   hStatus = GdipDrawEllipse(graphics, redPen, 0, 0, 100, 20)

   ' // Restore to state1 and draw the ellipse again. 
   ' // Only the rotation transformation applies.
     hStatus = GdipRestoreGraphics(graphics, state1)
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_GREEN, 1.0, UnitWorld, @greenPen)
   hStatus = GdipDrawEllipse(graphics, greenPen, 0, 0, 100, 20)

   ' // The information block identified by state2 has been lost.
   ' // The following call to Restore has no effect because
   ' // GdipRestoreGraphics(state1) removed from the stack the
   ' // information blocks identified by state1 and state2.
     hStatus = GdipRestoreGraphics(graphics, state2)
   DIM bluePen AS GpPen PTR

   ' // The Graphics object is still in the state identified by state1.
   ' // The following code draws a blue ellipse on top of the previously
   ' // drawn green ellipse.
   hStatus = GdipCreatePen1(ARGB_BLUE, 1.0, UnitWorld, @bluePen)
   hStatus = GdipDrawEllipse(graphics, bluePen, 0, 0, 100, 20)

   ' // Cleanup
   IF bluePen THEN GdipDeletePen(bluePen)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF redPen THEN GdipDeletePen(redPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

See another example in **GdipSaveGraphics**.

---

## GdipRotateWorldTransform

Updates the world transformation matrix of the **Graphics** object with the product of itself and a rotation matrix.

```
FUNCTION GdipRotateWorldTransform (BYVAL graphics AS GpGraphics PTR, BYVAL angle AS REAL, _
   BYVAL order AS GpMatrixOrder) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *angle* | [in] value that specifies the angle, in degrees, of rotation. | 
| *order* | [in] Element of the **MatrixOrder** enumeration that specifies the order of multiplication. *MatrixOrderPrepend* specifies that the rotation matrix is on the left, and *MatrixOrderAppend* specifies that the rotation matrix is on the right. The default value is *MatrixOrderPrepend*. | 

#### Example

```
' ========================================================================================
' The following example sets the world transformation of a Graphics object to a translation.
' The call to GdipRotateWorldTransform multiplies the Graphics object's existing world
' transformation matrix (translation) by a rotation matrix. The MatrixOrderAppend argument
' specifies that the multiplication is done with the rotation matrix on the right. At that
' point, the world transformation matrix of the Graphics object represents a composite
' transformation: first translate, then rotate. The call to GdipDrawEllipse draws a translated
' and rotated ellipse.
' ========================================================================================
SUB Example_RotatetWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1 * rxRatio, UnitPixel, @pen)
   hStatus = GdipTranslateWorldTransform(graphics, 100.0, 0.0, MatrixOrderPrepend)
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderAppend)
   hStatus = GdipDrawEllipse(graphics, pen, 0, 0, 200, 80)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSaveGraphics

Saves the current state (transformations, clipping region, and quality settings) of a **Graphics** object. You can restore the state later by calling the **GdipRestoreGraphics** function.

```
FUNCTION GdipSaveGraphics (BYVAL graphics AS GpGraphics PTR, BYVAL state AS GraphicsState PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *state* | [out] A value that identifies the saved state. Pass this value to the **GdipRestoreGraphics** function when you want to restore the state. |

#### Remarks

When you call the **GdipSaveGraphics** function, an information block that holds the state of the **Graphics** object is put on a stack. The **GdipSaveGraphics** function returns a value that identifies that information block. When you pass the identifying value to the **GdipRestoreGraphics** function, the information block is removed from the stack and is used to restore the **Graphics** object to the state it was in at the time of the **GdipSaveGraphics** call. Note that the identifier returned by a given call to the **GdipSaveGraphics** function can be passed only once to the **GdipRestoreGraphics** function.

Calls to the **GdipSaveGraphics** function can be nested; that is, you can call the **GdipSaveGraphics** function several times before you call the **GdipRestoreGraphics** function. Each time you call the **GdipSaveGraphics** function, an information block is put on the stack, and you receive an identifier for the information block. When you pass one of those identifiers to the **GdipRestoreGraphics** function, the **Graphics** object is returned to the state it was in at the time of the **GdipSaveGraphics** call that returned that particular identifier. The information block placed on the stack by that **GdipSaveGraphics** call is removed from the stack, and all information blocks placed on that stack after that **GdipSaveGraphics** call are also removed.

Calls to the **GdipBeginContainer** function place information blocks on the same stack as calls to the **GdipSaveGraphics** function. Just as a **GdipRestoreGraphics** call is paired with a **GdipSaveGraphics** call, an **GdipEndContainer** call is paired with a **GdipBeginContainer** call.

Caution When you call **GdipRestoreGraphics**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipSaveGraphics** are removed from the stack. Likewise, When you call **GdipEndContainer**, all information blocks placed on the stack (by **GdipSaveGraphics** or by **GdipBeginContainer**) after the corresponding call to **GdipBeginContainer** are removed from the stack.

#### Example

```
' ========================================================================================
' The following example sets the world transformation of a Graphics object to a rotation and
' then saves the state of the Graphics object. Next, the code calls GdipTranslateWorldTransform,
' and saves the state again. Then the code calls GdipScaleTransform. At that point, the world
' transformation of the Graphics object is a composite transformation: first rotate, then
' translate, then scale. The code uses a red pen to draw an ellipse that is transformed by
' that composite transformation.
' The code passes state2, which was returned by the second call to GdipSaveGraphics, to the
' GdipRestoreGraphics function, and draws the ellipse again using a green pen. The green
' ellipse is rotated and translated but not scaled. Finally the code passes state1, which
' was returned by the first call to GdipSaveGraphics, to the GdipRestoreGraphics function,
' and draws the ellipse again using a blue pen. The blue ellipse is rotated but not
' translated or scaled.
' ========================================================================================
SUB Example_SaveGraphics (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Apply rotation
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderPrepend)
   DIM state1 AS GraphicsState
   hStatus = GdipSaveGraphics(graphics, @state1)

   ' // Apply translation
   hStatus = GdipTranslateWorldTransform(graphics, 100.0, 0.0, MatrixOrderAppend)
   DIM state2 AS GraphicsState
   hStatus = GdipSaveGraphics(graphics, @state2)

   ' // Apply scaling
   hStatus = GdipScaleWorldTransform(graphics, 1.0, 3.0, MatrixOrderAppend)

   ' // Draw red ellipse (rotate + translate + scale)
   DIM redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1.0, UnitWorld, @redPen)
   hStatus = GdipDrawEllipse(graphics, redPen, 0, 0, 100, 20)

   ' Restore to state2 (rotate + translate)
   hStatus = GdipRestoreGraphics(graphics, state2)
   DIM greenPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_GREEN, 1.0, UnitWorld, @greenPen)
   hStatus = GdipDrawEllipse(graphics, greenPen, 0, 0, 100, 20)

   ' // Restore to state1 (rotate only)
   hStatus = GdipRestoreGraphics(graphics, state1)
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1.0, UnitWorld, @bluePen)
   hStatus = GdipDrawEllipse(graphics, bluePen, 0, 0, 100, 20)

   ' // Cleanup
   IF bluePen THEN GdipDeletePen(bluePen)
   IF greenPen THEN GdipDeletePen(greenPen)
   IF redPen THEN GdipDeletePen(redPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipScaleWorldTransform

Updates the **Graphics** object's world transformation matrix with the product of itself and a scaling matrix.

```
FUNCTION GdipScaleWorldTransform (BYVAL graphics AS GpGraphics PTR, BYVAL sx AS REAL, _
   BYVAL sy AS REAL, BYVAL order AS GpMatrixOrder) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *sx* | [in] The horizontal scaling factor in the scaling matrix. |
| *sy* | [in] The vertical scaling factor in the scaling matrix. | 
| *order* | [in] Element of the **MatrixOrder** enumeration that specifies the order of multiplication. *MatrixOrderPrepend* specifies that the scaling matrix is on the left, and *MatrixOrderAppend* specifies that the scaling matrix is on the right. The default value is *MatrixOrderPrepend*. |

#### Example

```
' ========================================================================================
' The following example sets the world transformation of a Graphics object to a translation.
' The call to GdipScaleWorldTransform multiplies the Graphics object's existing world
' transformation matrix (translation) by a scaling matrix. The MatrixOrderAppend argument
' specifies that the multiplication is done with the scaling matrix on the right. At that
' point, the world transformation matrix of the Graphics object represents a composite
' transformation: first translate, then scale. The call to GdipDrawEllipse draws a translated
' and scaled ellipse.
' ========================================================================================
SUB Example_ScaletWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1 * rxRatio, UnitPixel, @pen)
   hStatus = GdipTranslateWorldTransform(graphics, 70.0, 70.0, MatrixOrderAppend)   ' // first translate
   hStatus = GdipScaleWorldTransform(graphics, 3.0, 1.0, MatrixOrderAppend)         ' // then scale
   hStatus = GdipDrawEllipse(graphics, pen, 0, 0, 50, 50)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetClipGraphics

Updates the clipping region of the **Graphics** object to a region that is the combination of itself and the clipping region of another **Graphics** object.

```
FUNCTION GdipSetClipGraphics (BYVAL graphics AS GpGraphics PTR, BYVAL srcgraphics sx AS GpGraphics PTR, _
   BYVAL combineMode AS CombineMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *srcgraphics* | [in] Pointer to a **Graphics** object that contains the clipping region to be combined with the clipping region of the **Graphics** object. |
| *combineMode* |[in] Element of the **CombineMode** enumeration that specifies how the specified region is combined with the clipping region of the **Graphics** object. The default value is *CombineModeReplace*. | 

#### Example

```
' ========================================================================================
' This example demonstrates how to share a clipping region between two GDI+ Graphics objects
' while maintaining DPI-aware rendering:
' It creates two Graphics objects from the same device context and applies DPI scaling to both.
' A blue rectangle is drawn using the first graphics object.
' A clipping rectangle is defined on the first graphics object, scaled to match the DPI.
' The clipping region is then copied to the second graphics object using GdipSetClipGraphics.
' A red rectangle is drawn using the second graphics object, but only the portion inside the
' shared clipping region is visible—effectively masking the red rectangle over part of the blue one.
' ========================================================================================
SUB Example_SetClipGraphics (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   DIM bluePen AS GpPen PTR
   GdipCreatePen1(ARGB_BLUE, 2.0, UnitPixel, @bluePen)
   GdipDrawRectangle(graphics, bluePen, 0.0, 0.0, 200.0, 200.0)

   ' // Set a clipping rectangle on graphics
   GdipSetClipRect(graphics, 50.0 * rxRatio, 50.0 * rxRatio, 100.0 * rxRatio, 100.0 * rxRatio, CombineModeReplace)

   ' // Create a second graphics object
   DIM graphics2 AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics2)
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics2, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Apply graphics's clipping region to graphics2
   GdipSetClipGraphics(graphics2, graphics, CombineModeReplace)

   ' // Create pen and draw with graphics2
   DIM pen AS GpPen PTR
   GdipCreatePen1(ARGB_RED, 2.0, UnitPixel, @pen)
   GdipDrawRectangle(graphics2, pen, 0.0, 0.0, 200.0, 200.0)
    
   ' Cleanup
   IF pen Then GdipDeletePen(pen)
   IF graphics Then GdipDeleteGraphics(graphics)
   IF graphics2 Then GdipDeleteGraphics(graphics2)

END SUB
' ========================================================================================
```
---

## GdipSetClipHrgn

Updates the clipping region of the **Graphics** object to a region that is the combination of itself and a GDI region.

```
FUNCTION GdipSetClipHrgn (BYVAL graphics AS GpGraphics PTR, BYVAL hRgn AS HRGN, _
   BYVAL combineMode AS CombineMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *hRgn* | [in] Handle to a GDI region to be combined with the clipping region of the **Graphics** object. This is provided for legacy code. New applications should pass a **Region** object as the first parameter. |
| *combineMode* |[in] Element of the **CombineMode** enumeration that specifies how the specified region is combined with the clipping region of the **Graphics** object. The default value is *CombineModeReplace*. | 

#### Remarks

This function assumes that the GDI region specified by hRgn is already in device units, so it does not transform the coordinates of the GDI region.

#### Example

```
' ========================================================================================
' This example demonstrates how to apply a GDI clipping region to a GDI+ Graphics object in a DPI-aware way:
' It creates a Graphics object from a device context and applies DPI scaling using GdipScaleWorldTransform.
' A GDI ellipse region (HRGN) is created with coordinates scaled to match the DPI.
' The region is applied as a clipping mask using GdipSetClipHrgn.
' A solid black brush fills a large rectangle (250 × 250), but only the portion inside the
' elliptical clip is rendered—creating a masked fill effect.
' ========================================================================================
SUB Example_SetClipHrgn (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' Create a GDI region (ellipse)
   DIM hRgn As HRGN
   hRgn = CreateEllipticRgn(50 * rxRatio, 50 * rxRatio, 200 * rxRatio, 200 * rxRatio)

   ' // Apply the region as a clip
   hStatus = GdipSetClipHrgn(graphics, hRgn, CombineModeReplace)

   ' // Create a solidbrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Fill the rectangle.
   hStatus = GdipFillRectangle(graphics, brush, 0, 0, 250, 250)

   ' // Cleanup
   IF hRgn THEN DeleteObject(hRgn)
   IF brush THEN GdipDeletePen(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetClipPath

Updates the clipping region of the **Graphics** object to a region that is the combination of itself and the region specified by a graphics path. If a figure in the path is not closed, this method treats the nonclosed figure as if it were closed by a straight line that connects the figure's starting and ending points.

```
FUNCTION GdipSetClipPath (BYVAL graphics AS GpGraphics PTR, BYVAL path AS GpPath PTR, _
   BYVAL combineMode AS CombineMode) AS GpStatus
```
```
FUNCTION GdipSetClipPath (BYVAL graphics AS GpGraphics PTR, BYVAL path AS GpPath PTR, _
   BYVAL combineMode AS CombineMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *path* | [in] Pointer to a **GraphicsPath** object that specifies the region to be combined with the clipping region of this Graphics object. |
| *combineMode* |[in] Element of the **CombineMode** enumeration that specifies how the specified region is combined with the clipping region of the **Graphics** object. The default value is *CombineModeReplace*. | 

#### Example

```
' ========================================================================================
' Elliptical Clip Using Path.
' This example demonstrates how to use GdipSetClipPath to apply an elliptical clipping
' region to a GDI+ Graphics object:
' It creates a GraphicsPath containing an ellipse.
' The path is set as the clipping region using GdipSetClipPath.
' A solid black brush fills a large rectangle (300 × 300), but only the portion inside the
' elliptical clip is rendered—creating a masked fill effect.
' DPI scaling is applied to ensure consistent rendering across high-resolution displays.
' ========================================================================================
SUB Example_SetClipPath (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a path with an ellipse
   DIM path As GpPath Ptr
   GdipCreatePath(FillModeAlternate, @path)
   GdipAddPathEllipse(path, 50.0, 50.0, 150.0, 150.0)

   ' // Apply the path as a clipping region
   GdipSetClipPath(graphics, path, CombineModeReplace)

   ' // Fill a rectangle to test the clip
   Dim brush As GpBrush Ptr
   GdipCreateSolidFill(ARGB_BLACK, @brush)
   GdipFillRectangle(graphics, brush, 0, 0, 250, 250)

   ' // Cleanup
   IF brush THEN GdipDeletePen(brush)
   IF path THEN GdipDeletePath(path)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetClipRect

Updates the clipping region of the **Graphics** object to a region that is the combination of itself and a rectangle.

```
FUNCTION GdipSetClipRect (BYVAL graphics AS GpGraphics PTR, BYVAL x AS REAL, BYVAL y AS REAL, _
   BYVAL width AS REAL, BYVAL height AS REAL, BYVAL combineMode AS CombineMode) AS GpStatus
```
```
FUNCTION GdipSetClipRectI (BYVAL graphics AS GpGraphics PTR, BYVAL x AS INT_, BYVAL y AS INT_, _
   BYVAL width AS INT_, BYVAL height AS INT_, BYVAL combineMode AS CombineMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *x* | [in] The x-coordinate of the rectangle to be combined with the clipping region of the **Graphics** object. |
| *y* | [in] The y-coordinate of the rectangle to be combined with the clipping region of the **Graphics** object. |
| *width* | [in] The width of the rectangle to be combined with the clipping region of the **Graphics** object. |
| *height* | [in] The height of the rectangle to be combined with the clipping region of the **Graphics** object. |
| *combineMode* |[in] Element of the **CombineMode** enumeration that specifies how the specified region is combined with the clipping region of the **Graphics** object. The default value is *CombineModeReplace*. | 

#### Example

```
' ========================================================================================
' The following example uses a rectangle to update a clipping region and then draws a
' rectangle that demonstrates the updated clipping region.
' ========================================================================================
SUB Example_SetClipRect (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @brush)

   ' // Set the clipping region to its exclusion.
   hStatus = GdipSetClipRect(graphics, 125, 50, 200, 200, CombineModeReplace)

   ' // Fill a rectangle to demonstrate the clipping region.
   hStatus = GdipFillRectangle(graphics, brush, 0, 0, 400, 310)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
#### Example
```
' ========================================================================================
' The following example sets a clipping region and updates the clipping region. It then
' draws rectangles to demonstrate the effective clipping region.
' ========================================================================================
SUB Example_SetClipRect2 (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set the clipping region.
   hStatus = GdipSetClipRect(graphics, 0.5, 0.5, 200.5, 200.5, CombineModeReplace)

   ' // Update the clipping region to the portion of the rectangle that
   ' // intersects with the current clipping region.
   hStatus = GdipSetClipRect(graphics, 100.5, 100.5, 200.5, 200.5, CombineModeIntersect)

   ' // Create a solid brush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @brush)

   ' // Fill a rectangle to demonstrate the effective clipping region.
   hStatus = GdipFillRectangle(graphics, brush, 0, 0, 450, 320)

   ' // Reset the clipping region to infinite.
   hStatus = GdipResetClip(graphics)

   ' // Draw clipRect and intersectRect.
   DIM blackPen AS GpPen PTR, redPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 1, UnitWorld, @blackPen)
   hStatus = GdipCreatePen1(ARGB_RED, 1, UnitWorld, @redPen)
   hStatus = GdipDrawRectangle(graphics, blackPen, 0.5, 0.5, 200.5, 200.5)
   hStatus = GdipDrawRectangle(graphics, redPen, 100.5, 100.5, 200.5, 200.5)

   ' // Cleanup
   IF blackPen THEN GdipDeletePen(blackPen)
   IF redPen THEN GdipDeletePen(redPen)
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

#### Example

```
' ========================================================================================
' The following example sets a clipping region and updates the clipping region. It then
' draws rectangles to demonstrate the effective clipping region.
' ========================================================================================
SUB Example_IntersectClip (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Define clipping rectangle
   DIM clipRect AS GpRectF = (0.5, 0.5, 200.5, 200.5)
   hStatus = GdipSetClipRect(graphics, clipRect.X, clipRect.Y, clipRect.Width, clipRect.Height, CombineModeReplace)

   ' // Define intersection rectangle
   DIM intRect AS GpRectF = (100.5, 100.5, 200.5, 200.5)
   hStatus = GdipSetClipRect(graphics, intRect.X, intRect.Y, intRect.Width, intRect.Height, CombineModeIntersect)

   ' // Create solid brush (opaque blue)
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(255, 0, 0, 255), @brush)

   ' // Fill a large rectangle to show clipping effect
   hStatus = GdipFillRectangle(graphics, brush, 0, 0, 500, 500)

   ' // Reset clipping region
   hStatus = GdipResetClip(graphics)

   ' // Create pens
   DIM AS GpPen PTR penBlack, penRed
   hStatus = GdipCreatePen1(GDIP_ARGB(255, 0, 0, 0), 2.0, UnitPixel, @penBlack)
   hStatus = GdipCreatePen1(GDIP_ARGB(255, 255, 0, 0), 2.0, UnitPixel, @penRed)

   ' // Draw clipRect and intersectRect outlines
   hStatus = GdipDrawRectangle(graphics, penBlack, clipRect.X, clipRect.Y, clipRect.Width, clipRect.Height)
   hStatus = GdipDrawRectangle(graphics, penRed, intRect.X, intRect.Y, intRect.Width, intRect.Height)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF penBlack THEN GdipDeletePen(penBlack)
   IF penRed THEN GdipDeletePen(penRed)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetCompositingMode

Sets the compositing mode of the **Graphics** object.

```
FUNCTION GdipSetCompositingMode (BYVAL graphics AS GpGraphics PTR, _
    BYVAL combineMode AS CombineMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *combineMode* | [in] Element of the **CompositingMode** enumeration that specifies the compositing mode. |

####  Remarks

Suppose you create a **SolidBrush** object based on a color that has an alpha component of 192, which is about 75 percent of 255. If your Graphics object has its compositing mode set to *CompositingModeSourceOver*, then areas filled with the solid brush are a blend that is 75 percent brush color and 25 percent background color. If your **Graphics** object has its compositing mode set to *CompositingModeSourceCopy*, then the background color is not blended with the brush color. However, the color rendered by the brush has an intensity that is 75 percent of what it would be if the alpha component were 255.

You cannot use *CompositingModeSourceCopy* along with *TextRenderingHintClearTypeGridFit*.

#### Example

```
' ========================================================================================
' The following example creates a Graphics object and sets its compositing mode to
' CompositingModeSourceOver. The code creates a solid brush based on a color that has an
' alpha component of 128. The code passes the address of that brush to the GdipFillRectangle
' function to fill a rectangle with a color that is a half-and-half blend of the brush color
' and the background color. Then the code sets the compositing mode of the Graphics object
' to CompositingModeSourceCopy and fills a second rectangle with the same brush. In that
' second rectangle, the brush color is not blended with the background color.
' ========================================================================================
SUB Example_SetCompositingMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush object with an alpha-blended color.
   DIM alphaBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(180, 255, 0, 0), @alphaBrush)

   ' // Set the compositing mode to CompositingModeSourceOver, and fill a rectangle.
   hStatus = GdipSetCompositingMode(graphics, CompositingModeSourceOver)
   hStatus = GdipFillRectangle(graphics, alphaBrush, 0, 0, 100, 100)

   ' // Set the compositing mode to CompositingModeSourceCopy, and fill a rectangle.
   hStatus = GdipSetCompositingMode(graphics, CompositingModeSourceCopy)
   hStatus = GdipFillRectangle(graphics, alphaBrush, 100, 0, 100, 100)

   ' // Cleanup
   IF alphaBrush THEN GdipDeleteBrush(alphaBrush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetCompositingQuality

Sets the compositing quality of the **Graphics** object.

```
FUNCTION GdipSetCompositingQuality (BYVAL graphics AS GpGraphics PTR, _
    BYVAL compositingQuality AS CompositingQuality) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *CompositingQuality* | [in] Element of the **CompositingQuality** enumeration that specifies the compositing quality. |

#### Example

```
' ========================================================================================
' The following example creates a solid brush based on a color that has an alpha component
' of 128. The code uses that brush to paint two rectangles. The first rectangle is painted
' with the compositing mode set to CompositingQualityHighSpeed, and the second rectangle is
' painted with the compositing mode set to CompositingQualityHighQuality.
' ========================================================================================
SUB Example_SetCompositingQuality (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush object with an alpha-blended color.
   DIM alphaBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(180, 255, 0, 0), @alphaBrush)

   ' // Set the compositing quality to CompositingQualityHighSpeed, and fill a rectangle.
   hStatus = GdipSetCompositingQuality(graphics, CompositingQualityHighSpeed)
   hStatus = GdipFillRectangle(graphics, alphaBrush, 0, 0, 100, 100)

   ' // Set the compositing quality to CompositingQualityHighQuality, and fill a rectangle.
   hStatus = GdipSetCompositingQuality(graphics, CompositingQualityHighQuality)
   hStatus = GdipFillRectangle(graphics, alphaBrush, 100, 0, 100, 100)

   ' // Cleanup
   IF alphaBrush THEN GdipDeleteBrush(alphaBrush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetInterpolationMode

Sets the interpolation mode of the **Graphics** object. The interpolation mode determines the algorithm that is used when images are scaled or rotated.

```
FUNCTION GdipSetInterpolationMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL interpolationMode AS InterpolationMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *interpolationMode* | [in] Element of the **InterpolationMode** enumeration that specifies the interpolation mode. |

#### Interpolation mode

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| *InterpolationModeInvalid* | -1 | Used internally |
| *InterpolationModeDefault* | 0 | Specifies the default interpolation mode. |
| *InterpolationModeLowQuality* | 1 | Specifies a low-quality mode. |
| *InterpolationModeHighQuality* | 2 | Specifies a high-quality mode. |
| *InterpolationModeBilinear* | 3 | Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size. |
| *InterpolationModeBicubic* | 4 | Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size. |
| *InterpolationModeNearestNeighbor* | 5 | Specifies nearest-neighbor interpolation. |
| *InterpolationModeHighQualityBilinear* | 6 | Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking. |
| *InterpolationModeHighQualityBicubic* | 7 | Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images. |

#### Example

```
' ========================================================================================
' Set the interpolation mode.
' ========================================================================================
SUB Example_SetInterpolationMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

    ' // Set the interpolation mode
   hStatus = GdipSetInterpolationMode(graphics, InterpolationModeHighQuality)

   ' // Get the interpolation mode
   DIM mode AS InterpolationMode
   hStatus = GdipGetInterpolationMode(graphics, @mode)
   IF hStatus = StatusOk THEN
      AfxMsg "Current interpolation mode: " & WSTR(mode)
   ELSE
      AfxMsg "Failed to get interpolation mode: " & WSTR(hStatus)
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetMetafileDownLevelRasterizationLimit

Sets the resolution for certain brush bitmaps that are stored in this metafile.

```
FUNCTION GdipSetMetafileDownLevelRasterizationLimit (BYVAL metafile AS GpMetafile PTR, _
    BYVAL metafileRasterizationLimitDpi AS UINT) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *metafile* | [in] Pointer to the **Metafile** object. |
| *metafileRasterizationLimitDpi* | [in] Non-negative long integer value that specifies the resolution in dots per inch (dpi). If you set this parameter equal to 0, the resolution is set to match the resolution of the device context handle that was passed to the Metafile constructor. If you set this parameter to a value greater than 0 but less than 10, the resolution is left unchanged. |

#### Remarks

The purpose of this method is to prevent metafiles from becoming too large as a result of texture and gradient brushes being stored at high resolution. Suppose you construct a **Metafile** object (for recording an *EmfTypeEmfOnly* metafile) based on the device context of a printer that has a resolution of 600 dpi. Also suppose you create a path gradient brush or a texture brush based on a **Bitmap** object that has a resolution of 96 dpi. If the bitmap that represents that brush is stored in the metafile with a resolution of 96 dpi, it will require much less space than if it is stored with a resolution of 600 dpi.

The default rasterization limit for metafiles is 96 dpi. So if you do not call this method at all, path gradient brush and texture brush bitmaps are stored with a resolution of 96 dpi.

The rasterization limit has an effect on metafiles of type *EmfTypeEmfOnly* and *EmfTypeEmfPlusDual*, but it has no effect on metafiles of type *EmfTypeEmfPlusOnly*.

### Example

```
' ========================================================================================
' Record Metafile and Set/Get Rasterization Limit
' Metafile is recorded, not loaded—required for setting the rasterization limit.
' Limit is set before drawing, which ensures it affects rasterization.
' Saved using GdipGetHemfFromMetafile, not GdipSaveImageToFile.
' ========================================================================================
SUB Example_MetafileDownLevelRasterizationLimit (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Define the frame rectangle
   DIM rcfFrame AS GpRectF = (0.0, 0.0, 300.0, 200.0)
   DIM description AS WSTRING * 64 = "Rasterization limit test"

   ' // Record a new EMF+ metafile
   DIM metafile AS GpMetafile PTR
   hStatus = GdipRecordMetafile(hdc, EmfTypeEmfPlusDual, @rcfFrame, MetafileFrameUnitPixel, @description, @metafile)
   IF hStatus <> 0 OR metafile = NULL THEN
      AfxMsg "Failed to record metafile: " & STR(hStatus)
      EXIT SUB
   END IF

   ' // Set rasterization limit (must be done before drawing)
   DIM dpiLimit AS UINT = 150
   hStatus = GdipSetMetafileDownLevelRasterizationLimit(metafile, dpiLimit)
   IF hStatus <> 0 THEN
      AfxMsg "Failed to set rasterization limit: " & STR(hStatus)
   END IF

   ' // Draw into the metafile
   DIM graphics AS GpGraphics PTR
   hStatus = GdipGetImageGraphicsContext(metafile, @graphics)
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 2.0, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 50.0, 50.0, 200.0, 100.0)

   ' // Flush graphics
   hStatus = GdipFlush(graphics, FlushIntentionFlush)

   ' // Retrieve rasterization limit
   DIM currentLimit AS UINT
   hStatus = GdipGetMetafileDownLevelRasterizationLimit(metafile, @currentLimit)
   IF hStatus = 0 THEN
      AfxMsg "Current rasterization limit: " & STR(currentLimit) & " DPI"
   ELSE
      AfxMsg "Failed to get rasterization limit: " & STR(hStatus)
   END IF

   ' // Save metafile to disk
   DIM hEmf AS HENHMETAFILE
   hStatus = GdipGetHemfFromMetafile(metafile, @hEmf)
   IF hEmf THEN
      DIM saved AS HENHMETAFILE = CopyEnhMetaFile(hEmf, "RasterizedOutput.emf")
      IF saved THEN DeleteEnhMetaFile(saved)
      DeleteEnhMetaFile(hEmf)
   END IF

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)

END SUB
' ========================================================================================
```
---

## GdipSetPageScale

Sets the scaling factor for the page transformation of the **Graphics** object. The page transformation converts page coordinates to device coordinates.

```
FUNCTION GdipSetPageScale (BYVAL graphics AS GpGraphics PTR, BYVAL scale AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *scale* | [in] The scaling factor. |

#### Remarks

**GdipSetPageUnit** changes the measurement unit (e.g., inches, millimeters).

**GdipSetPageScale** applies a scaling factor to that unit.

**GdipGetPageScale** retrieves the current scale factor, which affects how coordinates are transformed from page units to device units.

This is particularly useful when you're preparing content for printing or want consistent layout across devices with different DPI settings.

#### Example

```
' ========================================================================================
' The following example sets the world transformation and the page transformation of a
' Graphics object. The page unit and the page scale both belong to the page transformation.
' The code sets the page unit to millimeters and sets the page scale to 10. The call to
' the GdipDrawRectangle method draws a rectangle that has a width of 3 centimeters
' (UnitMillimeter along with a scaling factor of 10) and a height of 2 centimeters.
' The rectangle is translated 4 centimeters to the right and 1 centimeter down by the world
' transformation.
' ========================================================================================
SUB Example_SetPageScale (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96

   ' // Set the world transformation.
   hStatus = GdipTranslateWorldTransform(graphics, 4.0, 1.0, MatrixOrderPrepend)

   ' // Set the page transformation.
   hStatus = GdipSetPageUnit(graphics, UnitMillimeter)
   hStatus = GdipSetPageScale(graphics, 10.0)
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 0, 0, 3, 2)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetPageUnit

Sets the unit of measure for the **Graphics** object. The page unit belongs to the page transformation, which converts page coordinates to device coordinates.

```
FUNCTION GdipSetPageUnit (BYVAL graphics AS GpGraphics PTR, BYVAL unit AS GpUnit) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *unit* | [in] Element of the **GpUnit** enumeration that specifies the unit of measure for the **Graphics** object. |

#### Remarks

```
' ========================================================================================
' The following example draws two rectangles: one measured in pixels and one measured in inches.
' ========================================================================================
SUB Example_SetPageUnit (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96

   ' // Set the page units to pixels, and draw a rectangle.
   hStatus = GdipSetPageUnit(graphics, UnitPixel)
   DIM blackPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 1 * rxRatio, UnitPixel, @blackPen)
   hStatus = GdipDrawRectangle(graphics, blackPen, 0, 0, 100  * rxRatio, 100  * rxRatio)

 ' // Set the page units to inches, and draw a rectangle.
   hStatus = GdipSetPageUnit(graphics, UnitInch)
   DIM bluePen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1 * rxRatio, UnitPixel, @bluePen)
   hStatus = GdipDrawRectangle(graphics, bluePen, 2, 0, 1, 1)

   ' // Cleanup
   IF blackPen THEN GdipDeletePen(blackPen)
   IF bluePen THEN GdipDeletePen(bluePen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetPixelOffsetMode

Sets the pixel offset mode of the **Graphics** object.

```
FUNCTION GdipSetPixelOffsetMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL pixelOffsetMode AS PixelOffsetMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *pixelOffsetMode* | [in] Element of the **PixelOffsetMode** enumeration that specifies the pixel offset mode. |

#### Example

```
' ========================================================================================
' This example creates a Graphics object from a device context, sets the pixel offset mode
' quality to PixelOffsetModeHighQuality and draws a line.
' ========================================================================================
SUB Example_SetPixelOffsetMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set pixel offset mode to high quality
   GdipSetPixelOffsetMode(graphics, PixelOffsetModeHighQuality)

   ' // Draw a line or shape
   DIM pen AS GpPen PTR
   GdipCreatePen1(ARGB_RED, 2.0 * rxRatio, UnitPixel, @pen)
   GdipDrawLine(graphics, pen, 100.0, 120.0, 300.0, 120.0)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetRenderingOrigin

Sets the rendering origin of the **Graphics** object. The rendering origin is used to set the dither origin for 8-bits-per-pixel and 16-bits-per-pixel dithering and is also used to set the origin for hatch brushes.

```
FUNCTION GdipSetRenderingOrigin (BYVAL graphics AS GpGraphics PTR, _
   BYVAL x AS REAL, BYVAL y AS REAL) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *x* | [in] The x-coordinate of the rendering origin. |
| *y* | [in] The y-coordinate of the rendering origin. |

#### Example

```
' ========================================================================================
' This example draws two rectangles using an Hatch brush with different rendering origins.
' ========================================================================================
SUB Example_SetRenderingOrigin (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' Create a hatch brush
   DIM brush AS GpHatch PTR
   GdipCreateHatchBrush(HatchStyleCross, ARGB_BLACK, ARGB_LIGHTGRAY, @brush)

   ' // Draw first rectangle with default origin
   GdipFillRectangle(graphics, brush, 35, 50, 150, 100)

   ' // Set rendering origin and draw a second rectangle
   GdipSetRenderingOrigin(graphics, 10, 10)
   GdipFillRectangle(graphics, brush, 215, 50, 150, 100)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetSmoothingMode

Sets the render quality of the **Graphics** object.

```
FUNCTION GdipSetSmoothingMode (BYVAL graphics AS GpGraphics PTR, _
   BYVAL smoothingMode AS SmoothingMode) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *smoothingMode* | [in] Element of the **SmoothingMode** enumeration that specifies whether smoothing (antialiasing) is applied to lines and curves. |

#### Remarks

To get the rendering quality for text, use the **GdipGetTextRenderingHint** function. The higher the level of quality of the smoothing mode, the slower the performance.

#### Example

```
' ========================================================================================
' The following example creates a solid brush based on a color that has an alpha component
' of 128. The code uses that brush to paint two ellipses. The first ellipse is painted with
' the compositing mode set to CompositingQualityHighSpeed, and the second ellipse is painted
' with the compositing mode set to CompositingQualityHighQuality.
' ========================================================================================
SUB Example_SetSmoothingMode (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a SolidBrush object with an alpha-blended color.
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @brush)

   ' // Set the smoothing mode to SmoothingModeHighSpeed, and fill an ellipse.
   hStatus = GdipSetSmoothingMode(graphics, SmoothingModeHighSpeed)
   hStatus = GdipFillEllipse(graphics, brush, 20, 50, 200, 100)

   ' // Set the smoothing mode to SmoothingModeHighQuality, and fill an ellipse.
   hStatus = GdipSetSmoothingMode(graphics, SmoothingModeHighQuality)
   hStatus = GdipFillEllipse(graphics, brush, 230, 50, 200, 100)
   
   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetTextContrast

Sets the contrast level (0-12) currently set for the **Graphics** object. The contrast value is used for antialiasing text. Higher values increase contrast, improving readability on LCD screens.

```
FUNCTION GdipSetTextContrast (BYVAL graphics AS GpGraphics PTR, BYVAL contrast AS UINT) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *contrast* | [in] The contrast value for antialiasing text. |

#### Example

```
' ========================================================================================
' This example sets and retrieves the text contrast level of a Graphics object.
' It draws text with a high contrast setting to demonstrate its effect.
' ========================================================================================
SUB Example_SetTextContrast (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set text contrast to maximum (12)
   hStatus = GdipSetTextContrast(graphics, 12)

   ' // Retrieve current contrast setting
   DIM contrast AS UINT
   hStatus = GdipGetTextContrast(graphics, @contrast)

   ' // Create font and brush
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   IF hStatus = StatusOk THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPoint, @font)
      GdipDeleteFontFamily(fontFamily)
    END IF

   ' // Create a black brush
   DIM brush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' Draw text with high contrast
   DIM rcf AS GpRectF
   DIM wszText AS WSTRING * 128
   wszText = "Text contrast level: " & contrast
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, NULL, brush)

   ' // Cleanup
   IF font THEN GdipDeleteFont(font)
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetTextRenderingHint

Sets the text rendering mode of the **Graphics** object.

```
FUNCTION GdipSetTextRenderingHint (BYVAL graphics AS GpGraphics PTR, _
   BYVAL mode AS TextRenderingHint) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *mode* | [in] Element of the **TextRenderingHint** enumeration that specifies the process currently used by this Graphics object to render text. |

#### Example

```
' ========================================================================================
' The following example sets the text rendering hint to two different values and draws text
' to demonstrate each value.
' ========================================================================================
SUB Example_SetTextRenderingHint (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Set the text rendering hint to TextRenderingHintSingleBitPerPixel.
   hStatus = GdipSetTextRenderingHint(graphics, TextRenderingHintSingleBitPerPixel)

   ' // Create the font
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   IF hStatus = StatusOk THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(12, TRUE), FontStyleRegular, UnitPoint, @font)
      GdipDeleteFontFamily(fontFamily)
   END IF   

   ' // Create a solid brush
   DIM brush AS GpBRush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @brush)

   ' // Draw text
   DIM rcf AS GpRectF, format AS GpStringFormat PTR
   DIM wszText AS WSTRING *  128 = "Low quality rendering"
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, format, brush)

   ' // Set the text rendering hint to TextRenderingHintAntiAlias.
   hStatus = GdipSetTextRenderingHint(graphics, TextRenderingHintAntiAlias)

   ' // Draw more text to demonstrate the difference.
   rcf.y = 50
   wszText = "High quality rendering"
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, format, brush)

   ' // Cleanup
   IF font THEN GdipDeleteFont(font)
   IF brush THEN GdipDeleteBrush(brush)
   IF format THEN GdipDeleteStringFormat(format)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipSetWorldTransform

Sets the world transformation of the **Graphics** object.

```
FUNCTION GdipSetWorldTransform (BYVAL graphics AS GpGraphics PTR, _
   BYVAL matrix AS GpMatrix PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *matrix* | [in] Pointer to a **Matrix** object that specifies the world transformation. |

#### Example

```
' ========================================================================================
' The following example creates a rotation matrix and passes the address of that matrix to
' the GdipSetWorldTransform function. The code calls the GdipDrawRectangle function to draw
' a rotated rectangle.
' ========================================================================================
SUB Example_SetWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a transformation matrix
   DIM matrix AS GpMatrix PTR
   hStatus = GdipCreateMatrix(@matrix)

   ' // Rotate 30 degrees and translate by (100, 50)
   GdipRotateMatrix(matrix, 30.0, MatrixOrderAppend)
   GdipTranslateMatrix(matrix, 100.0, 50.0, MatrixOrderAppend)

   ' // Apply the matrix to the graphics object
   GdipSetWorldTransform(graphics, matrix)

   ' Draw a rectangle using the transformed coordinates
   DIM pen AS GpPen PTR
   GdipCreatePen1(ARGB_BLUE, 2.0, UnitPixel, @pen)
   GdipDrawRectangle(graphics, pen, 0, 0, 150, 100)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF matrix THEN GdipDeleteMatrix(matrix)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipTransformPoints

Converts an array of points from one coordinate space to another. The conversion is based on the current world and page transformations of the **Graphics** object.

```
FUNCTION GdipTransformPoints (BYVAL graphics AS GpGraphics PTR, _
   BYVAL destSpace AS GpCoordinateSpace, BYVAL srcSpace AS GpCoordinateSpace, _
   BYVAL points AS GpPointF PTR, BYV AL count AS INT_) AS GpStatus
```
```
FUNCTION GdipTransformPointsI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL destSpace AS GpCoordinateSpace, BYVAL srcSpace AS GpCoordinateSpace, _
   BYVAL points AS GpPoint PTR, BYV AL count AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *destSpace* | [in] Element of the **CoordinateSpace** enumeration that specifies the destination coordinate space. |
| *srcSpace* | [in] Element of the **CoordinateSpace** enumeration that specifies the source coordinate space. |
| *points* | [in, out] Pointer to an array that, on input, holds the points to be converted and, on output, holds the converted points. |
| *count* | [in] Long integer value that specifies the number of elements in the pts array. |

####  Remarks

The world transformation converts points from the world coordinate space to the page coordinate space. The page transformation converts points from the page coordinate space to the device coordinate space.

#### Example

```
' ========================================================================================
' The following example creates a Graphics object and sets its world transformation to a
' translation 40 units right and 30 units down. Then the code creates an array of points
' and passes the address of that array to the GdipTransformPoints method of the same Graphics
' object. The points in the array are transformed by the world transformation of the Graphics
' object. The code calls the GdipDrawLine method twice: once to connect the two points before
' the transformation and once to connect the two points after the transformation.
' ========================================================================================
SUB Example_TransformPoints (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

  ' // Draw a line that connects the two points.
   ' // No transformation has been performed yet.
   DIM pts(1) AS GpPointF, pen AS GpPen PTR
   pts(0).x = 0 : pts(0).y = 0 : pts(1).x = 100 : pts(1).y = 50
   hStatus = GdipCreatePen1(ARGB_BLACK, 1 * rxRatio, UnitPixel, @pen)
   hStatus = GdipDrawLine(graphics, pen, pts(0).x, pts(0).y, pts(1).x, pts(1).y)

   ' // Set the world transformation of the Graphics object.
   hStatus = GdipTranslateWorldTransform(graphics, 40, 30, MatrixOrderPrepend)

   ' // Transform the points in the array from world to page coordinates.
   hStatus = GdipTransformPoints(graphics, CoordinateSpacePage, CoordinateSpaceWorld, @pts(0), 2)

   ' // It is the world transformation that takes points from world
   ' // space to page space. Because the world transformation is a
   ' // translation 40 to the right and 30 down, the
   ' // points in the array are now (40, 30) and (140, 80).

   ' // Draw a line that connects the transformed points.
   DIM pen2 AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLUE, 1 * rxRatio, UnitPixel, @pen2)
   hStatus = GdipResetWorldTransform(graphics)
   hStatus = GdipDrawLine(graphics, pen2, pts(0).x, pts(0).y, pts(1).x, pts(1).y)

   ' // Cleanup
   IF pen2 THEN GdipDeletePen(pen2)
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipTranslateClip

Translates the clipping region of the **Graphics** object.

```
FUNCTION GdipTranslateClip (BYVAL graphics AS GpGraphics PTR, _
   BYVAL dx AS REAL, BYVAL dy AS REAL) AS GpStatus
```
```
FUNCTION GdipTranslateClipI (BYVAL graphics AS GpGraphics PTR, _
   BYVAL dx AS INT_, BYVAL dy AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *dx* | [in] The horizontal component of the translation. |
| *dy* | [in] The vertical component of the translation. |

#### Example

```
' ========================================================================================
' The following example creates a Graphics object and sets its clipping region. The code
' translates the clipping region 100 units to the right and then fills a large rectangle
' that is clipped by the translated region.
' ========================================================================================
SUB Example_TranslateClip (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

  ' // Set the clipping region.
   hStatus = GdipSetClipRect(graphics, 0, 0, 100, 50, CombineModeReplace)

   ' // Translate the clipping region.
   hStatus = GdipTranslateClip(graphics, 40, 30)

   ' // Fill an ellipse that is clipped by the translated clipping region.
   DIM brush AS GpBRush PTR
   hStatus = GdipCreateSolidFill(ARGB_RED, @brush)
   hStatus = GdipFillEllipse(graphics, brush, 20, 40, 100, 80)

   ' // Draw the outline of the clipping region (rectangle).
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2, UnitPixel, @pen)
   hStatus = GdipDrawRectangle(graphics, pen, 40, 30, 100, 50)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF brush THEN GdipDeleteBrush(brush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipTranslateWorldTransform

Updates this Graphics object's world transformation matrix with the product of itself and a translation matrix.

```
FUNCTION GdipTranslateWorldTransform (BYVAL graphics AS GpGraphics PTR, _
   BYVAL dx AS REAL, BYVAL dy AS REAL, BYVAL order AS GpMatrixOrder) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *dx* | [in] The horizontal component of the translation. |
| *dy* | [in] The vertical component of the translation. |
| *order* | [in] Element of the **MatrixOrder** enumeration that specifies the order of multiplication. *MatrixOrderPrepend* specifies that the translation matrix is on the left, and *MatrixOrderAppend* specifies that the translation matrix is on the right. The default value is *MatrixOrderPrepend*. |

#### Example

```
' ========================================================================================
' The following example sets the world transformation of a Graphics object to a rotation.
' The call to GdipTranslateWorldTransform multiplies the Graphics object's existing world
' transformation matrix (rotation) by a translation matrix. The MatrixOrderAppend argument
' specifies that the multiplication is done with the translation matrix on the right. At
' that point, the world transformation matrix of the Graphics object represents a composite
' transformation: first rotate, then translate. The call to GdipDrawEllipse draws a rotated
' and translated ellipse.
' ========================================================================================
SUB Example_TranslateWorldTransform (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_RED, 1 * rxRatio, UnitPixel, @pen)
   hStatus = GdipRotateWorldTransform(graphics, 30.0, MatrixOrderPrepend)
   hStatus = GdipTranslateWorldTransform(graphics, 100.0, 50.0, MatrixOrderAppend)
   hStatus = GdipDrawEllipse(graphics, pen, 0, 0, 200, 80)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawDriverString

Draws characters at the specified positions. The method gives the client complete control over the appearance of text. The method assumes that the client has already set up the format and layout to be applied.

```
FUNCTION GdipDrawDriverString (BYVAL graphics AS GpGraphics PTR, BYVAL text AS CONST UINT16 PTR, _
         BYVAL length AS INT_, BYVAL font AS CONST GpFont PTR, BYVAL brush AS CONST GpBrush PTR, _
         BYVAL positions AS CONST GpPointF PTR, BYVAL flags AS INT_, _
         BYVAL matrix AS CONST GpMatrix PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *text* | [in] Pointer to an array of 16-bit values. If the *DriverStringOptionsCmapLookup* flag is set, each value specifies a Unicode character to be displayed. Otherwise, each value specifies an index to a font glyph that defines a character to be displayed. |
| *length* | [in] Long integer value that specifies the number of values in the text array. The length parameter can be set to 1 if the string is null terminated. |
| *font* | [in] Pointer to a **Font** object that specifies the family name, size, and style of the font that is to be applied to the string. |
| *brush* | [in] Pointer to a **Brush** object that is used to fill the string. |
| *positions* | [in] If the *DriverStringOptionsRealizedAdvance* flag is set, positions is a pointer to a **GpPointF** structure that specifies the position of the first glyph. Otherwise, positions is an array of **GpPointF** structures, each of which specifies the origin of an individual glyph. |
| *flags* | [in] Long integer value  that specifies the options for the appearance of the string. This value must be an element of the *DriverStringOptions* enumeration or the result of a bitwise **OR** applied to two or more of these elements. |
| *matrix* | [in] Pointer to a **Matrix** object that specifies the transformation matrix to apply to each value in the text array. |

#### Example

```
' ========================================================================================
' GdipDrawDriverString is a GDI+ function that draws individual characters at precise
' positions, giving you full control over glyph placement and rendering. Unlike GdipDrawString,
' which handles layout automatically, this method lets you:
' - Specify each character as a Unicode value or glyph index.
' - Define exact coordinates for each glyph.
' - Apply custom transformations via a matrix.
' - Use flags to control layout behavior (e.g. advance spacing or cmap lookup).
' It’s ideal for advanced text rendering scenarios like custom typesetting, vertical text,
' or non-standard scripts where layout precision is critical.
' ========================================================================================
SUB Example_DrawDriverString (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create a font
   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   GdipCreateFont(fontFamily, AfxGdipPointsToPixels(16, TRUE), FontStyleRegular, UnitPixel, @font)

   ' // Create a solid brush
   DIM brush AS GpBrush PTR
   GdipCreateSolidFill(ARGB_RED, @brush)

   ' // Define the text as an array of UINT16 (Unicode characters)
   DIM text(4) AS UINT16 = {ASC("H"), ASC("e"), ASC("l"), ASC("l"), ASC("o")}

   ' // Define positions for each glyph
   DIM positions(4) AS GpPointF
   FOR i AS LONG = 0 TO 4
      positions(i).x = 50.0 + i * 20.0
      positions(i).y = 100.0
   NEXT

   ' // Draw the driver string
   GdipDrawDriverString(graphics, @text(0), 5, font, brush, @positions(0), DriverStringOptionsCmapLookup, NULL)

   ' // Cleanup
   IF brush THEN GdipDeleteBrush(brush)
   IF font THEN GdipDeleteFont(font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDrawString

Draws a string based on a font, a layout rectangle, and a format.

```
FUNCTION GdipDrawString (BYVAL graphics AS GpGraphics PTR, BYVAL string AS CONST WSTRING PTR, __
         BYVAL length AS INT_, BYVAL font AS CONST GpFont PTR, BYVAL layoutRect AS CONST GpRectF PTR, _
         BYVAL stringFormat AS CONST GpStringFormat PTR, BYVAL brush AS CONST GpBrush PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *string* | [in] Pointer to a wide-character string to be drawn. |
| *length* | [in] Long integer value that specifies the number of characters in the string array. The length parameter can be set to 1 if the string is null terminated. |
| *font* | [in] Pointer to a **Font** object that specifies the font attributes (the family name, the size, and the style of the font) to use. |
| *layoutRect* | [in] Reference to a rectangle that bounds the string. |
| *stringFormat* | [in] Pointer to a **StringFormat** object that specifies text layout information and display manipulations to be applied to the string. |
| *brush* | [in] Pointer to a **Brush** object that is used to fill the string. |

#### Example

```
' ========================================================================================
' The following example creates a Font object from a family name and uses it to draw text.
' ========================================================================================
SUB Example_Drawstring (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create the font
   DIM fontFamily As GpFontFamily PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   DIm font AS GpFont PTR
   IF hStatus = StatusOk THEN
      hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(16, TRUE), FontStyleRegular, UnitPoint, @font)
      GdipDeleteFontFamily(fontFamily)
   END IF

   ' // Create a solid brush
   DIM blackBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLACK, @blackBrush)

   ' // Draw the string
   DIM rcf AS GpRectF = (30, 30, 0, 0)
   DIM wszText AS WSTRING * 64 = "Sample text"
   hStatus = GdipDrawString(graphics, wszText, LEN(wszText), font, @rcf, NULL, blackBrush)

   ' // Cleanup
   IF font THEN GdipDeleteFont(font)
   IF blackBrush THEN GdipDeleteBrush(blackBrush)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipMeasureCharacterRanges

```
FUNCTION GdipMeasureCharacterRanges (BYVAL graphics AS GpGraphics PTR, _
         BYVAL string AS CONST WSTRING PTR, BYVAL length AS INT_, _
         BYVAL font AS GpFont PTR, BYVAL layoutRect AS GpRectF PTR, _
         BYVAL stringFormat AS GpStringFormat PTR, BYVAL regionCount AS INT_, _
         BYVAL regions AS GpRegion PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *string* | [in] Pointer to a wide-character string. |
| *length* | [in] Long integer value that specifies the number of characters in the string array. If the string parameter points to a NULL-terminated string, this parameter can be set to 1. |
| *font* | [in] Pointer to a **Font** object that specifies the font characteristics (the family name, size, and style of the font) to be applied to the string. |
| *layoutRect* | [in] Reference to a rectangle that bounds the string. |
| *stringFormat* | [in] Pointer to a **StringFormat** object that specifies the character ranges and layout information, such as alignment, trimming, tab stops, and so forth. |
| *regionCount* | [in] Long integer value that specifies the number of regions that are expected to be received into the regions array. This number should be equal to the number of character ranges currently in the **StringFormat** object. |
| *regions* | [out] Pointer to an array of **Region** objects that receives the regions, each of which bounds a range of text. |

#### Example

```
' ========================================================================================
' The following example defines three ranges of character positions within a string and
' sets those ranges in a StringFormat object. Next, the MeasureCharacterRanges method is
' used to get the three regions of the display that are occupied by the characters that
' are specified by the ranges. This is done for three different layout rectangles to show
' how the regions change according to the layout of the string. Also, on the third repetition
' of this, the string format flags are changed so that the regions measured will include
' trailing spaces.
' ========================================================================================
SUB Example_MeasureCharacterRanges (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create font
   DIM fontFamily AS GpFontFamily PTR
   DIM font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Times New Roman", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(16, TRUE), FontStyleRegular, UnitPixel, @font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

   ' // Create brushes and pen
   DIM blueBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(ARGB_BLUE, @blueBrush)
   DIM redBrush AS GpBrush PTR
   hStatus = GdipCreateSolidFill(GDIP_ARGB(100, 255, 0, 0), @redBrush)
   DIM blackPen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 1.0, UnitPixel, @blackPen)
   hStatus = GdipScalePenTransform(blackPen, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create string format
   DIM stringFormat As GpStringFormat PTR
   hStatus = GdipStringFormatGetGenericDefault(@stringFormat)

   ' // Define character ranges
   DIM charRanges(2) As GpCharacterRange
   charRanges(0).First = 3  : charRanges(0).Length = 5
   charRanges(1).First = 15 : charRanges(1).Length = 2
   charRanges(2).First = 30 : charRanges(2).Length = 15
   hStatus = GdipSetStringFormatMeasurableCharacterRanges(stringFormat, 3, @charRanges(0))

   ' // Allocate regions
   DIM regions(2) AS GpRegion PTR
   FOR i AS LONG = 0 TO 2
      hStatus = GdipCreateRegion(@regions(i))
   NEXT

   ' // Text to draw
   DIM text AS WSTRING * 128 = "The quick, brown fox easily jumps over the lazy dog."

   ' // Measure and draw for layoutRectA
   DIM layoutRectA AS GpRectF = (20.0, 20.0, 130.0, 130.0)
   hStatus = GdipMeasureCharacterRanges(graphics, @text, -1, font, @layoutRectA, stringFormat, 3, @regions(0))
   hStatus = GdipDrawString(graphics, @text, -1, font, @layoutRectA, stringFormat, blueBrush)
   hStatus = GdipDrawRectangle(graphics, blackPen, layoutRectA.X, layoutRectA.Y, layoutRectA.Width, layoutRectA.Height)
   FOR i AS LONG = 0 TO 2
      hStatus = GdipFillRegion(graphics, redBrush, regions(i))
   NEXT

   ' // Measure and draw for layoutRectB
   DIM layoutRectB AS GpRectF = (160.0, 20.0, 165.0, 130.0)
   hStatus = GdipMeasureCharacterRanges(graphics, @text, -1, font, @layoutRectB, stringFormat, 3, @regions(0))
   hStatus = GdipDrawString(graphics, @text, -1, font, @layoutRectB, stringFormat, blueBrush)
   hStatus = GdipDrawRectangle(graphics, blackPen, layoutRectB.X, layoutRectB.Y, layoutRectB.Width, layoutRectB.Height)
   FOR i AS LONG = 0 TO 2
      hStatus = GdipFillRegion(graphics, redBrush, regions(i))
   NEXT

   ' // Set trailing space flag and draw for layoutRectC
   DIM layoutRectC As GpRectF = (335.0, 20.0, 165.0, 130.0)
   hStatus = GdipSetStringFormatFlags(stringFormat, StringFormatFlagsMeasureTrailingSpaces)
   hStatus = GdipMeasureCharacterRanges(graphics, @text, -1, font, @layoutRectC, stringFormat, 3, @regions(0))
   hStatus = GdipDrawString(graphics, @text, -1, font, @layoutRectC, stringFormat, blueBrush)
   hStatus = GdipDrawRectangle(graphics, blackPen, layoutRectC.X, layoutRectC.Y, layoutRectC.Width, layoutRectC.Height)
   FOR i AS LONG = 0 TO 2
      hStatus = GdipFillRegion(graphics, redBrush, regions(i))
   NEXT

   ' // Cleanup
   FOR i AS LONG = 0 TO 2
      IF regions(i) THEN GdipDeleteRegion(regions(i))
   NEXT
   IF font THEN GdipDeleteFont(font)
   IF stringFormat THEN GdipDeleteStringFormat(stringFormat)
   IF blueBrush THEN GdipDeleteBrush(blueBrush)
   IF redBrush THEN GdipDeleteBrush(redBrush)
   IF blackPen THEN GdipDeletePen(blackPen)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipMeasureDriverString

Measures the bounding box for the specified characters and their corresponding positions.

```
FUNCTION GdipMeasureDriverString (BYVAL graphics AS GpGraphics PTR, _
         BYVAL text AS CONST UINT16 PTR, BYVAL length AS INT_, _
         BYVAL font AS CONST GpFont PTR, BYVAL positions AS CONST GpPointF PTR, _
         BYVAL flags AS INT_, BYVAL matrix AS CONST GpMatrix PTR, _
         BYVAL boundingBox AS GpRectF PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *text* | [in] Pointer to an array of 16-bit values. If the *DriverStringOptionsCmapLookup* flag is set, each value specifies a Unicode character to be displayed. Otherwise, each value specifies an index to a font glyph that defines a character to be displayed. |
| *length* | [in] Long integer value that specifies the number of values in the text array. The length parameter can be set to 1 if the string is null terminated. |
| *font* | [in] Pointer to a **Font** object that specifies the family name, size, and style of the font to be applied to the string. |
| *positions* | [in] If the *DriverStringOptionsRealizedAdvance* flag is set, positions is a pointer to a **GpPointF** structure that specifies the position of the first glyph. Otherwise, positions is an array of PointF objects, each of which specifies the origin of an individual glyph. |
| *flags* | [in] Long integer value that specifies the options for the appearance of the string. This value must be an element of the *DriverStringOptions* enumeration or the result of a bitwise **OR** applied to two or more of these elements. |
| *matrix* | [in] Pointer to a **Matrix** object that specifies the transformation matrix to apply to each value in the text array. |
| *boundingBox* | [out] Pointer to a **GpRectF** structure that receives the rectangle that bounds the string. |

#### Example

```
' ========================================================================================
' This example measures the exact bounding rectangle of glyphs drawn with GdipDrawDriverString.
' Accounts for DPI scaling via GdipScaleWorldTransform.
' Uses DriverStringOptionsCmapLookup to interpret text as Unicode characters.
' ========================================================================================
SUB Example_MeasureDriverString (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create font (Arial, 16pt)
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(16, TRUE), FontStyleRegular, UnitPixel, @font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

   ' // Define text and positions
   DIM text(4) AS UINT16 = {ASC("H"), ASC("e"), ASC("l"), ASC("l"), ASC("o")}
   DIM positions(4) AS GpPointF
   FOR i AS INTEGER = 0 TO 4
       positions(i).x = 50.0 + i * 20.0
       positions(i).y = 100.0
   NEXT

   ' // Measure bounding box
   DIM boundingBox AS GpRectF
   hStatus = GdipMeasureDriverString(graphics, @text(0), 5, font, @positions(0), DriverStringOptionsCmapLookup, NULL, @boundingBox)

   ' // Optional: draw bounding box for visualization
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 1.0, UnitPixel, @pen)
   hStatus = GdipScalePenTransform(pen, rxRatio, ryRatio, MatrixOrderPrepend)
   hStatus = GdipDrawRectangle(graphics, pen, boundingBox.X, boundingBox.Y, boundingBox.Width, boundingBox.Height)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF font THEN GdipDeleteFont(font)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipMeasureString

Measures the extent of the string in the specified font, format, and layout rectangle.

```
FUNCTION GdipMeasureString (BYVAL graphics AS GpGraphics PTR, BYVAL string AS CONST WSTRING PTR, _
   BYVAL length AS INT_, BYVAL font AS CONST GpFont PTR, BYVAL layoutRect AS CONST GpRectF PTR, _
   BYVAL stringFormat AS CONST GpStringFormat PTR, BYVAL boundingBox AS GpRectF PTR, _
   BYVAL codepointsFitted AS INT_ PTR, BYVAL linesFilled AS INT_ PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *graphics* | [in] Pointer to the **Graphics** object. |
| *string* | [in] Pointer to a wide-character string to be measured. |
| *length* | [in] Integer that specifies the number of characters in the string array. The length parameter can be set to 1 if the string is null terminated. |
| *font* | [in] Pointer to a **Font** object that specifies the family name, size, and style of the font to be applied to the string. |
| *layoutRect* | [in] Reference to the rectangle that bounds the string. |
| *stringFormat* | [in] Pointer to a **StringFormat** object that specifies the layout information, such as alignment, trimming, tab stops, and so forth. |
| *boundingBox* | [out] Pointer to a **GpRectF** structure that receives the rectangle that bounds the string. |
| *codepointsFitted* | [out] Pointer to a variable that receives the number of characters that actually fit into the layout rectangle. The default value is a NULL pointer. |
| *linesFilled* | [out] Pointer to an variable that receives the number of lines that fit into the layout rectangle. The default value is a NULL pointer. |

#### Example

```
' ========================================================================================
' The following example measures the extent of the string in the specified font, format,
' and layout rectangle.
' ========================================================================================
SUB Example_MeasureString (BYVAL hdc AS HDC)

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
   Dim ryRatio AS SINGLE = dpiY / 96
   ' // Set the scale transform
   hStatus = GdipScaleWorldTransform(graphics, rxRatio, ryRatio, MatrixOrderPrepend)

   ' // Create font (Arial, 16pt)
   DIM fontFamily AS GpFontFamily PTR, font AS GpFont PTR
   hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)
   hStatus = GdipCreateFont(fontFamily, AfxGdipPointsToPixels(16, TRUE), FontStyleRegular, UnitPixel, @font)
   IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

   ' // Create string format (default)
   DIM stringFormat AS GpStringFormat Ptr
   hStatus = GdipStringFormatGetGenericDefault(@stringFormat)

   ' // Measure string
   DIM boundRect AS GpRectF
   DIM layoutRect AS GpRectF = (0.0, 0.0, 100.0, 50.0)
   DIM text As WString * 64 = "Measure Text"
   hStatus = GdipMeasureString(graphics, @text, -1, font, @layoutRect, stringFormat, @boundRect, NULL, NULL)

   ' // Draw bounding rectangle
   DIM pen AS GpPen PTR
   hStatus = GdipCreatePen1(ARGB_BLACK, 2.0, UnitPixel, @pen)
   hStatus = GdipScalePenTransform(pen, rxRatio, ryRatio, MatrixOrderPrepend)
   hStatus = GdipDrawRectangle(graphics, pen, boundRect.X, boundRect.Y, boundRect.Width, boundRect.Height)

   ' // Cleanup
   IF pen THEN GdipDeletePen(pen)
   IF font THEN GdipDeleteFont(font)
   IF stringFormat THEN GdipDeleteStringFormat(stringFormat)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---
