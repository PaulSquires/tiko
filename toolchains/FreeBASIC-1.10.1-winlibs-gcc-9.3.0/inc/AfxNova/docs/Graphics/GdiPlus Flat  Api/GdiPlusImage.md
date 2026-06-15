# Image Functions

The **Image** functions allow loading and saving raster images (bitmaps) and vector images (metafiles). An Image object encapsulates a bitmap or a metafile and stores attributes that you can retrieve by calling various Get functions. You can construct **Image** objects from a variety of file types including BMP, ICON, GIF, JPEG, Exif, PNG, TIFF, WMF, and EMF.

| Name       | Description |
| ---------- | ----------- |
| [GdipCloneImage](#gdipcloneimage) | Creates a new Image object and initializes it with the contents of this Image object. |
| [GdipConvertToEmfPlus](#gdipconverttoemfplus) | Converts a **Metafile** object to the **EMF+** format. |
| [GdipConvertToEmfPlusToFile](#gdipconverttoemfplustofile) | Converts a **Metafile** object to the **EMF+** format. |
| [GdipConvertToEmfPlusToStream](#gdipconverttoemfplustostream) | Converts a **Metafile** object to the **EMF+** format.. |
| [GdipDisposeImage](#gdipdisposeimage) | Disposes the specified **Image** object. |
| [GdipEmfToWmfBits](#gdipemftowmfbits) | Converts an enhanced-format metafile to a Microsoft® Windows® Metafile Format (WMF) metafile and stores the converted records in a specified buffer. |
| [GdipFindFirstImageItem](#gdipfindfirstimageitem) | Retrieves the description and the data size of the first metadata item in an image. |
| [GdipFindNextImageItem](#gdipfindnextimageitem) | Retrieves the description and the data size of the next metadata item in an image. |
| [GdipGetAllPropertyItems](#gdipgetallpropertyitems) | Gets all the property items (metadata) stored in the specified **Image** object. |
| [GdipGetEncoderParameterList](#gdipgetencoderparameterlist) | Gets a list of the parameters supported by a specified image encoder. |
| [GdipGetEncoderParameterListSize](#gdipgetencoderparameterlistsize) | Gets the size, in bytes, of the parameter list for a specified image encoder. |
| [GdipGetImageBounds](#gdipgetimagebounds) | Gets the bounding rectangle of the image. |
| [GdipGetImageDimension](#gdipgetimagedimension) | Gets the width and height, in pixels, of an image. |
| [GdipGetImageFlags](#gdipgetimageflags) | Gets a set of flags that indicate certain attributes of an image. |
| [GdipGetImageGraphicsContext](#gdipgetimagegraphicscontext) | Creates a **Graphics** object that is associated with an **Image** object. |
| [GdipGetImageHeight](#gdipgetimageheight) | Gets the image height, in pixels, of an image. |
| [GdipGetImageHorizontalResolution](#gdipgetimagehorizontalresolution) | Gets the horizontal resolution, in dots per inch, of the image. |
| [GdipGetImageItemData](#gdipgetimageitemdata) | Gets one piece of metadata from an **Image** object. |
| [GdipGetImagePalette](#gdipgetimagepalette) | Gets the color palette of an image. |
| [GdipGetImagePaletteSize](#gdipgetimagepalettesize) | Gets the size, in bytes, of the color palette of an image. |
| [GdipGetImagePixelFormat](#gdipgetimagepixelformat) | Gets the pixel format of an image. |
| [GdipGetImageRawFormat](#gdipgetimagerawformat) | Gets a globally unique identifier (GUID) that identifies the format of the image. |
| [GdipGetImageThumbnail](#gdipgetimagethumbnail) | Gets a thumbnail image from an **Image** object. |
| [GdipGetImageType](#gdipgetimagetype) | Gets the type (bitmap or metafile) of an image. |
| [GdipGetImageVerticalResolution](#GdipGetImageVerticalResolution) | Gets the vertical resolution, in dots per inch, of the image. |
| [GdipGetImageWidth](#gdipgetimagewidth) | Gets the width, in pixels, of an image. |
| [GdipGetPropertyCount](#gdipgetpropertycount) | Gets the number of properties (pieces of metadata) stored in the image. |
| [GdipGetPropertyIdList](#gdipgetpropertyidlist) | Gets a list of the property identifiers used in the metadata of the image. |
| [GdipGetPropertyItem](#gdipgetpropertyitem) | Gets a specified property item (piece of metadata) from an image. |
| [GdipGetPropertyItemSize](#gdipgetpropertyitemsize) | Gets the size, in bytes, of a specified property item of an image. |
| [GdipGetPropertySize](#gdipgetpropertysize) | Gets the total size, in bytes, of all the property items stored in the Image object. |
| [GdipImageForceValidation](#gdipimageforcevalidation) | Forces validation of an image. |
| [GdipImageGetFrameCount](#gdipimagegetframecount) | Gets the number of frames in a specified dimension of an image. |
| [GdipImageGetFrameDimensionsCount](#gdipimagegetframedimensionscount) | Gets the number of frame dimensions in an image. |
| [GdipImageGetFrameDimensionsList](#gdipimagegetframedimensionslist) | Gets the identifiers for the frame dimensions of an image. |
| [GdipGetPropertySize](#gdipgetpropertysize) | Gets the total size, in bytes, of all the property items stored in an **Image** object and also the number of property items stored in the **Image** object. |
| [GdipImageRotateFlip](#gdipimagerotateflip) | Rotates and flips the image. |
| [GdipImageSelectActiveFrame](#gdipimageselectactiveframe) | Selects the frame in the **Image** object specified by a dimension and an index. |
| [GdipImageSetAbort](#gdipimagesetabort) | Sets an application-defined function that is called periodically by Windows GDI+ during time-consuming rendering operations. |
| [GdipLoadImageFromFile](#gdiploadimagefromfile) | Creates an **Image** object based on a file. |
| [GdipLoadImageFromFileICM](#gdiploadimagefromfileicm) | Creates an **Image** object based on a file. |
| [GdipLoadImageFromStream](#gdiploadimagefromstream) | Creates an **Image** object based on a stream. |
| [GdipLoadImageFromStreamICM](#gdiploadimagefromstreamicm) | Creates an **Image** object based on a file. |
| [GdipRemovePropertyItem](#gdipremovepropertyitem) | Removes a property item (piece of metadata) from an image. |
| [GdipSaveAdd](#gdipsaveadd) | Fkushes and finalizes a multframe image file. |
| [GdipSaveAddImage](#gdipsaveaddimage) | Adds a frame to a file or stream specified in a previous call to the **GdipSaveImageToFile** or **GdipSaveImageToStream** functions. |
| [GdipSaveImageToFile](#gdipsaveimagetofile) | Saves an **Image** object to a file. |
| [GdipSaveImageToStream](#gdipsaveimagetostream) | Saves an **Image** object to a stream. |
| [GdipSetImagePalette](#gdipsetimagepalette) | Sets the color palette of an image. |
| [GdipSetPropertyItem](#gdipsetpropertyitem) | Sets a property item (piece of metadata) for an image. If the item already exists, then its contents are updated; otherwise, a new item is added. |

---

## GdipCloneImage

Creates a new **Image** object and initializes it with the contents of this Image object.

```
FUNCTION GdipCloneImage (BYVAL image AS GpImage PTR, BYVAL cloneImage AS GpImage PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *cloneImage* | [out] Pointer to a **GpImage** variable that receives a pointer to the new **Image** object. |

#### Example

The following example creates an **Image** object based on a JPEG file. The code creates a second **Image** object by cloning the first. Then the code calls the **DrawImage** method twice to draw the two images.

```
' ========================================================================================
SUB Example_CloneImage (BYVAL hdc AS HDC)

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

   ' // Load the original image from file
   DIM image1 AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image1)
   ' // Set the resolution of this Image object to the user's DPI settings
   hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image1), dpiX, dpiY)

   ' // Clone the image
   DIM image2 AS GpImage PTR
   hStatus = GdipCloneImage(image1, @image2)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image1, 10, 10)

   ' // Draw the cloned image
   hStatus = GdipDrawImage(graphics, image2, 210, 10)

   ' // Cleanup
   IF image1 THEN GdipDisposeImage(image1)
   IF image2 THEN GdipDisposeImage(image2)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipConvertToEmfPlus

Converts a metafile of the type *MetafileTypeEmf* (4) to the **EMF+** format.

```
FUNCTION ConvertToEmfPlus (BYVAL refGraphics AS GpGraphics PTR, _
   BYVAL conversionFailureFlag AS INT_ PTR, BYVAL emfType AS EmfType, _
   BYVAL description AS WSTRING PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *refGraphics* | [in] Pointer to a **Graphics** object whose state (settings for antialiasing, interpolation, and the like) is applied to the records stored in the converted metafile. |
| *conversionFailureFlag* | Optional. Pointer to a BOOL that receives TRUE if all the metafile records were converted successfully; FALSE otherwise. Pass NULL if you do not want to receive this information. The default value is NULL. |
| *emfType* | Optional. Element of the *EmfType* enumeration that specifies whether the converted file has the *EmfTypeEmfPlusOnly* format or the *EmfTypeEmfPlusDual* format. Do not pass *EmfTypeEmfOnly*. The default value is *EmfTypeEmfPlusOnly*. |
| *description* | Optional. Pointer to a null-terminated wide-character string that is stored in the header of the converted metafile. The default value is NULL. |

#### Remarks

This method replaces the records originally in the **Metafile** object with the converted records. To retain a copy of the original **Metafile** object, call the **GdipCloneImage** function.

If you set the **emfType** parameter to **EmfTypeEmfPlusDual**, the converted metafile contains an Enhanced Metafile (EMF) representation and an EMF+ representation. The EMF representation is the original set of EMF records rather than EMF records converted back from the newly created EMF+ records.

It is possible for the return value to be **Ok** and the value returned in conversionSuccess to be **FALSE**. Sometimes the overall conversion is considered to be successful even if a few individual records failed to convert with complete accuracy. For example, the original metafile might have records or operations that are not supported by Windows GDI+ (or EMF+), in which case those records or operations are emulated.

#### Example

```
' ========================================================================================
' Convert EMF to EMF+ Dual
' refGraphics: Supplies rendering settings like anti-aliasing and interpolation.
' emfType: Use EmfTypeEmfPlusDual for compatibility with GDI and GDI+.
' conversionSuccess: Returns TRUE only if all records were converted.
' description: Optional metadata embedded in the new metafile.
' ========================================================================================
SUB Example_ConvertToEmfPlus (BYVAL hdc AS HDC)

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

   ' // Load original EMF metafile
   DIM original AS GpMetafile PTR
   DIM filename AS WSTRING * 64 = "EMF13.emf"
   hStatus = GdipCreateMetafileFromFile(filename, @original)
   IF hStatus <> 0 OR original = NULL THEN
      AfxMsg "Failed to load original metafile: " & WSTR(hStatus)
      EXIT SUB
   END IF

   ' // Convert to EMF+ Dual format
   DIM success AS BOOL
   DIM outMetafile AS GpMetafile PTR
   DIM description AS WSTRING * 64 = "Converted to EMF+"
   hStatus = GdipConvertToEmfPlus(graphics, original, @success, EmfTypeEmfPlusDual, @description, @outMetafile)
   IF hStatus <> 0 THEN
      AfxMsg "Conversion failed: " & STR(hStatus)
   ELSEIF success THEN
      AfxMsg "Conversion succeeded. EMF+ Dual metafile created."
   ELSE
      AfxMsg "Conversion completed with partial success."
   END IF

   ' // Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF original THEN GdipDisposeImage(original)
   IF outMetafile THEN GdipDisposeImage(outMetafile)

END SUB
' ========================================================================================
```
---

## GdipConvertToEmfPlusToFile

Converts a metafile of the type *MetafileTypeEmf* (4) to the **EMF+** format and saves it to a file.

```
FUNCTION GdipConvertToEmfPlusToFile (BYVAL refGraphics AS GpGraphics PTR, BYVAL filename AS WSTRING PTR, _
   BYVAL conversionFailureFlag AS INT_ PTR, BYVAL emfType AS EmfType, _
   BYVAL description AS WSTRING PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *refGraphics* | [in] Pointer to a **Graphics** object whose state (settings for antialiasing, interpolation, and the like) is applied to the records stored in the converted metafile. |
| *filename* | [in] Pointer to a null-terminated wide-character string that specifies the name of a file to which the converted metafile is saved. |
| *conversionFailureFlag* | Optional. Pointer to a BOOL that receives TRUE if all the metafile records were converted successfully; FALSE otherwise. Pass NULL if you do not want to receive this information. The default value is NULL. |
| *emfType* | Optional. Element of the *EmfType* enumeration that specifies whether the converted file has the *EmfTypeEmfPlusOnly* format or the *EmfTypeEmfPlusDual* format. Do not pass *EmfTypeEmfOnly*. The default value is *EmfTypeEmfPlusOnly*. |
| *description* | Optional. Pointer to a null-terminated wide-character string that is stored in the header of the converted metafile. The default value is NULL. |

#### Remarks

This method replaces the records originally in the **Metafile** object with the converted records. To retain a copy of the original **Metafile** object, call the **GdipCloneImage** function.

If you set the **emfType** parameter to **EmfTypeEmfPlusDual**, the converted metafile contains an Enhanced Metafile (EMF) representation and an EMF+ representation. The EMF representation is the original set of EMF records rather than EMF records converted back from the newly created EMF+ records.

It is possible for the return value to be **Ok** and the value returned in conversionSuccess to be **FALSE**. Sometimes the overall conversion is considered to be successful even if a few individual records failed to convert with complete accuracy. For example, the original metafile might have records or operations that are not supported by Windows GDI+ (or EMF+), in which case those records or operations are emulated.

#### Example

```
' ========================================================================================
' Convert EMF to EMF+ and Save to File.
' ========================================================================================
SUB Example_ConvertToEmfPlusToFile (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' Load original EMF metafile
   DIM metafile AS GpMetafile PTR
   hStatus = GdipCreateMetafileFromFile("EMF13.emf", @metafile)

   ' Convert to EMF+ and save to file
   DIM filename AS WSTRING * 64 = "converted.emf"
   DIM success AS LONG
   DIM description AS WSTRING * 64 = "Converted EMF+"
   DIM converted AS GpMetafile PTR
   hStatus = GdipConvertToEmfPlusToFile(graphics, metafile, @success, @filename, EmfTypeEmfPlusDual, @description, @converted)

   AfxMsg "Conversion status: " & WSTR(hStatus)
   AfxMsg "Conversion success: " & WSTR(success)

   ' Cleanup
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF metafile THEN GdipDisposeImage(metafile)
   IF converted THEN GdipDisposeImage(converted)

END SUB
' ========================================================================================
```

---

## GdipConvertToEmfPlusToStream

Converts a metafile of the type *MetafileTypeEmf* (4) to the **EMF+** format and saves it to a stream.

```
FUNCTION GdipConvertToEmfPlusToStream (BYVAL refGraphics AS GpGraphics PTR, BYVAL stream AS IStream PTR, _
   BYVAL conversionFailureFlag AS INT_ PTR, BYVAL emfType AS EmfType, _
   BYVAL description AS WSTRING PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *refGraphics* | [in] Pointer to a **Graphics** object whose state (settings for antialiasing, interpolation, and the like) is applied to the records stored in the converted metafile. |
| *stream* | [in] Pointer to an **IStream** interface that specifies the stream to which the converted metafile is written. |
| *conversionFailureFlag* | Optional. Pointer to a BOOL that receives TRUE if all the metafile records were converted successfully; FALSE otherwise. Pass NULL if you do not want to receive this information. The default value is NULL. |
| *emfType* | Optional. Element of the *EmfType* enumeration that specifies whether the converted file has the *EmfTypeEmfPlusOnly* format or the *EmfTypeEmfPlusDual* format. Do not pass *EmfTypeEmfOnly*. The default value is *EmfTypeEmfPlusOnly*. |
| *description* | Optional. Pointer to a null-terminated wide-character string that is stored in the header of the converted metafile. The default value is NULL. |

#### Remarks

This method replaces the records originally in the **Metafile** object with the converted records. To retain a copy of the original **Metafile** object, call the **GdipCloneImage** function.

If you set the **emfType** parameter to **EmfTypeEmfPlusDual**, the converted metafile contains an Enhanced Metafile (EMF) representation and an EMF+ representation. The EMF representation is the original set of EMF records rather than EMF records converted back from the newly created EMF+ records.

It is possible for the return value to be **Ok** and the value returned in conversionSuccess to be **FALSE**. Sometimes the overall conversion is considered to be successful even if a few individual records failed to convert with complete accuracy. For example, the original metafile might have records or operations that are not supported by Windows GDI+ (or EMF+), in which case those records or operations are emulated.

#### Example

```
' ========================================================================================
' Convert EMF to EMF+ and Save to Stream.
' ========================================================================================
SUB Example_ConvertToEmfPlusToStream (BYVAL hdc AS HDC)

   DIM hStatus AS LONG

   ' // Create a graphics object from the device context
   DIM graphics AS GpGraphics PTR
   hStatus = GdipCreateFromHDC(hdc, @graphics)

   ' Load original EMF metafile
   DIM metafile AS GpMetafile PTR
   hStatus = GdipCreateMetafileFromFile("EMF13.emf", @metafile)

   ' Create stream to hold converted EMF+
   DIM stream AS IStream PTR
   hStatus = CreateStreamOnHGlobal(NULL, TRUE, @stream)
   IF hStatus <> StatusOk THEN
      AfxMsg "Failed to create stream."
      GdipDisposeImage(metafile)
      GdipDeleteGraphics(graphics)
      EXIT SUB
   END IF

   ' // Convert to EMF+ and write to stream
   DIM success AS LONG
   DIM description AS WSTRING * 64 = "Converted EMF+"
   DIM converted AS GpMetafile PTR
   hStatus = GdipConvertToEmfPlusToStream(graphics, metafile, @success, stream, EmfTypeEmfPlusDual, @description, @converted)

   AfxMsg "Conversion status: " & WSTR(hStatus)
   AfxMsg "Conversion success: " & WSTR(success)

   ' // Cleanup
   IF converted THEN GdipDisposeImage(converted)
   IF stream THEN stream->lpvtbl->Release(stream)
   IF metafile THEN GdipDisposeImage(metafile)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipDisposeImage

Disposes the specified **Image** object.

```
FUNCTION GdipDisposeImage (BYVAL image AS GpImage PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |

#### Usage example

```
IF image THEN GdipDisposeImage(image)
```
---

## GdipEmfToWmfBits

Converts an enhanced-format metafile to a Microsoft® Windows® Metafile Format (WMF) metafile and stores the converted records in a specified buffer.

```
FUNCTION GdipEmfToWmfBits (BYVAL hemf AS HENHMETAFILE, BYVAL cbData16 AS UINT, BYVAL pData16 AS LPBYTE, _
   BYVAL iMapMode AS INT_, BYVAL eFlags AS INT_) AS GpStatus
```
| Parameter  | Description |
| ---------- | ----------- |
| *hemf* | [in] Handle to the enhanced-format metafile that is to be converted. |
| *cbData16* | [in] Unsigned integer that specifies the number of bytes in the buffer pointed to by the *pData16* parameter. |
| *pData16* | [out] Pointer to a buffer that receives the converted records. If *pData16* is NULL, **GdipEmfToWmfBits** returns the number of bytes required to store the converted metafile records. |
| *iMapMode* | [in] Specifies the mapping mode to use in the converted metafile. For a list of possible mapping modes, see **SetMapMode**. The default value is MM_ANISOTROPIC. |
| *eFlags* | [in] Element of the *EmfToWmfBitsFlags* enumeration that specifies options for the conversion. The default value is *EmfToWmfBitsFlagsDefault*. |

#### Return value

If the function succeeds and the buffer pointer is NULL, the return value is the number of bytes required to store the converted records. If the function succeeds and the buffer pointer is a valid pointer, the return value is the size of the metafile data in bytes. If the function fails, the return value is zero.

#### Remarks

When you call **GdipEmfToWmfBits** to determine the size of the required buffer, you must pass the same value for *eFlags* that you pass later when you call **GdipEmfToWmfBits** to perform the conversion. Otherwise, the size returned by the first call to **GdipEmfToWmfBits** will be incorrect.

This function cannot convert metafiles of type *EmfTypeEmfPlusOnly*. If you use this function to convert a metafile of type *EmfTypeEmfPlusDual*, the Enhanced Metafile (EMF) records in that metafile are converted, but the EMF+ records are not converted.

This function converts an enhanced metafile into a WMF metafile so that its picture can be displayed in an application that recognizes the older format.

The **GdipEmfToWmfBits** function does not invalidate the enhanced metafile handle. Call the **DeleteEnhMetaFile** function to release the handle when it is no longer needed.

To create a scalable WMF metafile, specify MM_ANISOTROPIC as the *iMapMode* parameter.

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' ========================================================================================
' Convert EMF to a WMF bitstream.
' It operates directly on a Windows HENHMETAFILE handle.
' This example loads an EMF file, converts it to WMF bits using GdipEmfToWmfBits,
' and writes the result to a WMF file.
' GetEnhMetaFileW does no work with EMF+ files.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hemf AS HENHMETAFILE
DIM cbData16 AS UINT
DIM result AS UINT

' // Load the EMF file
hemf = GetEnhMetaFileW("EMF13.emf")
IF hemf = NULL THEN
   PRINT "Failed to load EMF file"
   SLEEP
   END
END IF

' // First call to get required buffer size
cbData16 = GdipEmfToWmfBits(hemf, 0, NULL, MM_ANISOTROPIC, EmfToWmfBitsFlagsDefault)

' // Allocate buffer
DIM pData16 AS UBYTE PTR = CAllocate(cbData16)

' // Convert EMF to WMF bits
result = GdipEmfToWmfBits(hemf, cbData16, pData16, MM_ANISOTROPIC, EmfToWmfBitsFlagsDefault)

' // Write to WMF file
DIM hFile AS HANDLE = CreateFile("output.wmf", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
IF hFile <> INVALID_HANDLE_VALUE THEN
   DIM bytesWritten AS DWORD
   WriteFile(hFile, pData16, result, @bytesWritten, NULL)
   CloseHandle(hFile)
   PRINT "WMF file written successfully."
ELSE
   PRINT "Failed to create WMF file."
END IF

' // Cleanup
IF pData16 THEN DEALLOCATE(pData16)
IF hemf THEN DeleteEnhMetaFile(hemf)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipFindFirstImageItem

Retrieves the description and the data size of the first metadata item in this Image object.

```
FUNCTION GdipFindFirstImageItem( (BYVAL image AS GpImage PTR, BYVAL item AS ImageItemData PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *item* | [in, out] Pointer to an **ImageItemData** object. On input, the **Desc** member points to a buffer (allocated by the caller) large enough to hold the metadata description (1 byte for JPEG, 4 bytes for PNG, 11 bytes for GIF), and the **DescSize** member specifies the size (1, 4, or 6) of the buffer pointed to by **Desc**. On output, the buffer pointed to by **Desc** receives the metadata description, and the **DataSize** member receives the size, in bytes, of the metadata itself. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("sample.jpg", @image)   ' --> change me

' // JPEG requires 1-byte description buffer
DIM descBuffer(0) AS BYTE
DIM itemData AS ImageItemData
itemData.Desc = @descBuffer(0)
itemData.DescSize = 1
itemData.DataSize = 0

' // Try to find first metadata item
hStatus = GdipFindFirstImageItem(image, @itemData)
IF hStatus <> 0 THEN
  PRINT "No custom metadata items found in JPEG"
ELSE
  DIM itemCount AS LONG = 1
  DO
      PRINT "Metadata Item "; itemCount
      PRINT "  DescSize: "; itemData.DescSize
      PRINT "  DataSize: "; itemData.DataSize
      PRINT "  Desc Byte: "; descBuffer(0)
      PRINT "-----------------------------"
      itemCount += 1
      hStatus = GdipFindNextImageItem(image, @itemData)
  LOOP WHILE hStatus = 0
END IF

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token
```
---

## GdipFindNextImageItem

Used along with the **GdipFindFirstImageItem** method to enumerate the metadata items stored in the image. The GdipFindNextImageItem function retrieves the description and the data size of the next metadata item in the image.

```
FUNCTION GdipFindNextImageItem( (BYVAL image AS GpImage PTR, BYVAL item AS ImageItemData PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *item* | [in, out] Pointer to an **ImageItemData** object. On input, the **Desc** member points to a buffer (allocated by the caller) large enough to hold the metadata description (1 byte for JPEG, 4 bytes for PNG, 11 bytes for GIF), and the **DescSize** member specifies the size (1, 4, or 6) of the buffer pointed to by **Desc**. On output, the buffer pointed to by **Desc** receives the metadata description, and the **DataSize** member receives the size, in bytes, of the metadata itself. |

#### Example

See the example for **GdipFindFirstImageItem**.

---

## GdipGetAllPropertyItems

Gets all the property items (metadata) stored in the specified the image.

```
FUNCTION GdipGetAllPropertyItems (BYVAL image AS GpImage PTR, BYVAL totalBufferSize AS UINT, _
   BYVAL numProperties AS UINT, BYVAL allItems AS PropertyItem PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *totalBufferSize* | [in] Long integer value that specifies the size, in bytes, of the *allItems* buffer. Call the **GdipGetPropertySize** function to obtain the required size. |
| *numProperties* | [in] Long integer value that specifies the number of properties in the image. Call the **GdipGetPropertySize** function to obtain this number. |

#### Example

The following example creates an Image object based on a JPEG file. The code calls the GetAllPropertyItems method of that Image object to obtain its property items (metadata).

The following example creates an Image object based on a JPEG file. The code calls the GetAllPropertyItems method of that Image object to obtain its property items (metadata).

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get total buffer size and number of properties
DIM totalSize AS UINT, numProps AS UINT, buffer AS UBYTE PTR
hStatus = GdipGetPropertySize(image, @totalSize, @numProps)
IF hStatus = 0 THEN
   ' // Allocate buffer and retrieve all property items
   buffer = Allocate(totalSize)
   hStatus = GdipGetAllPropertyItems(image, totalSize, numProps, cast(PropertyItem PTR, buffer))
   IF hStatus = 0 THEN
      DIM propItem AS PropertyItem PTR
      FOR i AS LONG = 0 TO numProps - 1
         propItem = cast(PropertyItem PTR, buffer + i * SIZEOF(PropertyItem))
         PRINT "Property ID: &h"; HEX(propItem->id)
         PRINT "Type: "; propItem->type; " Length: "; propItem->length
         SELECT CASE propItem->type
            CASE PropertyTagTypeASCII
               PRINT "Value: "; *cast(ZSTRING PTR, propItem->value)
            CASE PropertyTagTypeByte
               DIM b AS UBYTE PTR = Cast(UBYTE PTR, propItem->value)
               FOR j AS LONG = 0 TO propItem->length - 1
                  PRINT b[j]; " ";
               NEXT
               PRINT
            CASE PropertyTagTypeShort
               DIM s AS USHORT PTR = cast(USHORT PTR, propItem->value)
                  FOR j AS LONG = 0 TO propItem->length \ 2 - 1
                     PRINT s[j]; " ";
                  NEXT
                  PRINT
            CASE PropertyTagTypeLong
               DIM l AS ULONG PTR = cast(ULONG PTR, propItem->value)
               FOR j AS LONG = 0 TO propItem->length \ 4 - 1
                  PRINT l[j]; " ";
               NEXT
               PRINT
            CASE ELSE
               PRINT "Unsupported type"
         END SELECT
         PRINT "---------------------------"
      NEXT
   ELSE
      PRINT "Failed to retrieve property items"
   END IF
END IF

' // Cleanup
IF buffer THEN Deallocate(buffer)
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetEncoderParameterList

Gets a list of the parameters supported by a specified image encoder.

```
FUNCTION GdipGetEncoderParameterList (BYVAL image AS GpImage PTR, BYVAL clsidEncoder AS CLSID PTR, _
   BYVAL size AS UINT, BYVAL buffer AS EncoderParameters PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *clsidEncoder* | [in] Pointer to a CLSID that specifies the encoder. |
| *size* | [in] Integer that specifies the size, in bytes, of the buffer array. Call the **GdipGetEncoderParameterListSize** method to obtain the required size. |
| *buffer* | [out] Pointer to an EncoderParameters structure that receives the list of supported parameters. |

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("RYDER_Winona_01.jpg", @image)

' // Get the JPEG encoder CLSID
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")

' // Get size of parameter list
DIM listSize AS UINT
hStatus = GdipGetEncoderParameterListSize(image, @clsid, @listSize)

' Allocate buffer and retrieve list
DIM buffer As UBYTE Ptr = Allocate(listSize)
hStatus = GdipGetEncoderParameterList(image, @clsid, listSize, cast(EncoderParameters PTR, buffer))
IF hStatus = 0 THEN
   DIM epList AS EncoderParameters PTR = Cast(EncoderParameters PTR, buffer)
   PRINT "Encoder supports "; epList->Count; " parameters:"
   FOR i AS LONG = 0 TO epList->Count - 1
      DIM ep AS EncoderParameter PTR = @epList->Parameter(i)
      PRINT "Parameter "; i
      PRINT "  GUID: "; Hex(ep->Guid.Data1)
      PRINT "  Type: "; ep->Type
      PRINT "  Number of values: "; ep->NumberOfValues
      PRINT "  Value pointer: "; ep->Value
      PRINT "-----------------------------"
   NEXT
ELSE
   PRINT "Failed to retrieve encoder parameter list"
END IF

' // Cleanup
IF buffer THEN Deallocate(buffer)
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```

## GdipGetEncoderParameterListSize

Gets the size, in bytes, of the parameter list for a specified image encoder.

```
FUNCTION GdipGetEncoderParameterListSize (BYVAL image AS GpImage PTR, BYVAL clsidEncoder AS CLSID PTR, _
   BYVAL size AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *clsidEncoder* | [in] Pointer to a CLSID that specifies the encoder. |
| *size* | [in] Pointer to a variable that receives the size, in bytes, of the parameter list. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("RYDER_Winona_01.jpg", @image)

' // Get the JPEG encoder CLSID
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")

' // Get size of parameter list
DIM listSize AS UINT
hStatus = GdipGetEncoderParameterListSize(image, @clsid, @listSize)
PRINT "Size of parameters list: ", listSize

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageBounds

Gets the bounding rectangle for this image.

```
FUNCTION GdipGetImageBounds (BYVAL image AS GpImage PTR, BYVAL srcRect AS GpRectF PTR, _
   BYVAL srcUnit AS GpUnit PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *srcRect* | [out] Pointer to a **GpRectF** object that receives the bounding rectangle. |
| *srcUnit* | [out] Pointer to a variable that receives an element of the **GpUnit** enumeration that indicates the unit of measure for the bounding rectangle. |

#### Example

The following example creates an Image object based on a metafile and then draws the image. Next, the code calls the Image.GetBounds method to get the bounding rectangle for the image and redraws the a 75 per cent of the image.

```
' ========================================================================================
SUB Example_GetBounds (BYVAL hdc AS HDC)

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

   ' // Load the original image from file
   DIM image AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image)

   ' // Set the resolution of this Image object to the user's DPI settings
   hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image), dpiX, dpiY)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image, 10, 10)

   ' // Get the bounding rectangle for the image (metafile).
   DIM boundsRect AS GpRectF, unit AS GpUnit
   hStatus = GdipGetImageBounds(image, @boundsRect, @unit)

   ' // Draw 75 percent of the image.
   hStatus = GdipDrawImagePointRect(graphics, image, 230, 10, boundsRect.x, boundsRect.y, 0.75 * boundsRect.Width, boundsRect.Height, UnitPixel)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

## GdipGetImageDimension

Gets the width and height, in pixels, of an image.

```
FUNCTION GdipGetImageDimension(BYVAL image AS GpImage PTR, BYVAL nWidth AS REAL PTR, _
   BYVAL nHeight AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *nWidth* | [out] Pointer to a variable thatr eceives the width of the image. |
| *nHeight* | [out] Pointer to a variable thatr eceives the height of the image. |

The following example retrieves the width and height, in pixels, of an image.

```
DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the width and height of the image
DIM AS SINGLE nWidth, nHeight
hStatus = GdipGetImageDimension(image, @nWidth, @nHeight)
PRINT "Image width: " & WSTR(nWidth)
PRINT "Image height: " & WSTR(nHeight)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageFlags

Gets a set of flags that indicate certain attributes of an image.

```
FUNCTION GdipGetImageFlags (BYVAL image AS GpImage PTR, BYVAL flags AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *flags* | [out] Pointer to a variable that receives a value that holds a set of single-bit flags. The flags are defined in the *ImageFlags* enumeration. |

## Example

The following example retrieves the flags of an image.

```
DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the image flags
DIM flags AS UINT
hStatus = GdipGetImageFlags(image, @flags)
PRINT "Image flags &h" & HEX(flags)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipImageForceValidation

Forces validation of the image.

```
FUNCTION GdipImageForceValidation (BYVAL image AS GpImage PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |

#### Example

The following example forces validation of the specified image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the size of the specified property item.
DIM itemSize AS UINT
hStatus = GdipImageForceValidation(image)
PRINT "hStatus: ", hStatus
IF hStatus = 0 THEN PRINT "The image is valid"

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---
## GdipImageGetFrameCount

Gets the number of frames in a specified dimension of the image.

```
FUNCTION GdipImageGetFrameCount (BYVAL image AS GpImage PTR, BYVAL dimensionID AS GUID PTR, _
   BYVAL count AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *dimensionID* | [out] Pointer to a GUID that specifies the dimension. |
| *count* | [out] Pointer to a variable that receives the number of frames in the specified dimension of the image. |

#### Example

This example gets the number of frames in the first dimension of the image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("MultiFrame.tiff", @image)

' // How many frame dimensions does the Image object have?
DIM nCount AS UINT
hStatus = GdipImageGetFrameDimensionsCount(image, @nCount)
PRINT "The number of dimensions is " & STR(nCount)

' // Get the list of frame dimensions from the Image object.
DIM rgDimensionIDs(nCount - 1) AS GUID
hStatus = GdipImageGetFrameDimensionsList(image, @rgDimensionIDs(0), nCount)

' // Display the GUID of the first (and only) frame dimension.
DIM strGuid AS STRING = AfxGuidText(rgDimensionIDs(0))
'   strGuid = GUIDTXT$(rgDimensionIDs(0))
PRINT "The first (and only) dimension ID is " & strGuid

' // Get the number of frames in the first dimension.
DIM frameCount AS UINT
hStatus = GdipImageGetFrameCount(image, @rgDimensionIDs(0), @frameCount)
PRINT "The number of frames in that dimension is " & STR(frameCount)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipImageGetFrameDimensionsCount

Gets the number of frame dimensions in the image.

```
FUNCTION GdipImageGetFrameDimensionsCount (BYVAL image AS GpImage PTR, BYVAL count AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *count* | [out] Pointer to a variable that receives the number of frame dimensions in the image. |

#### Exampñe

This example retrieves te number of frame dimensions of the image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("MultiFrame.tiff", @image)

' // How many frame dimensions does the Image object have?
DIM nCount AS UINT
hStatus = GdipImageGetFrameDimensionsCount(image, @nCount)
PRINT "The number of dimensions is " & STR(nCount)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipImageGetFrameDimensionsList

Gets the number of frame dimensions in the image.

```
FUNCTION GdipImageGetFrameDimensionsList (BYVAL image AS GpImage PTR, BYVAL dimensionIDs AS GUID PTR, _
   BYVAL count AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *dimensionIDs* | [out] Pointer to an array of GUIDs that receives the identifiers. |
| *count* | [in] The number of frame dimensions in the image. |

#### Exampñe

This example gets the number of frame dimensions in the image object and the identifier of the frame.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("MultiFrame.tiff", @image)

' // How many frame dimensions does the Image object have?
DIM nCount AS UINT
hStatus = GdipImageGetFrameDimensionsCount(image, @nCount)
PRINT "The number of dimensions is " & STR(nCount)

' // Get the list of frame dimensions from the Image object.
DIM rgDimensionIDs(nCount - 1) AS GUID
hStatus = GdipImageGetFrameDimensionsList(image, @rgDimensionIDs(0), nCount)

' // Display the GUID of the first (and only) frame dimension.
DIM strGuid AS STRING = AfxGuidText(rgDimensionIDs(0))
'   strGuid = GUIDTXT$(rgDimensionIDs(0))
PRINT "The first (and only) dimension ID is " & strGuid

' // Get the number of frames in the first dimension.
DIM frameCount AS UINT
hStatus = GdipImageGetFrameCount(image, @rgDimensionIDs(0), @frameCount)
PRINT "The number of frames in that dimension is " & STR(frameCount)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageGraphicsContext

Creates a **Graphics** object that is associated with an **Image** object.

```
FUNCTION GdipGetImageGraphicsContext (BYVAL image AS GpImage PTR, BYVAL graphics AS GpGraphics PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object that will be associated with the new **Graphics** object. |
| *graphics* | [in] Pointer to a **Graphics** object that a pointer to the new **Graphics** object. |

## Example

The following example dwas on a Bitmap using GdipGetImageGraphicsContext.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create a bitmap to draw on
DIM bmp AS GpBitmap PTR
hStatus = GdipCreateBitmapFromFile("climber.jpg", @bmp)

' // Get a graphics context tied to the bitmap
DIM graphics AS GpGraphics PTR
hStatus = GdipGetImageGraphicsContext(CAST(GpImage PTR, bmp), @graphics)

' // Set smoothing mode for better quality
hStatus = GdipSetSmoothingMode(graphics, SmoothingModeAntiAlias)

' // Create a red brush
DIM brush AS GpSolidFill PTR
hStatus = GdipCreateSolidFill(&HFFFF0000, @brush)  ' ARGB: opaque red

' // Draw a filled ellipse onto the bitmap
hStatus = GdipFillEllipse(graphics, brush, 50, 50, 100, 60)

' // Save the modified bitmap to a new file
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")
hStatus = GdipSaveImageToFile(CAST(GpImage PTR, bmp), "modified.jpg", @clsid, NULL)

IF hStatus = S_OK THEN PRINT "File saved" ELSE PRINT "Failure"

' // Cleanup
IF brush THEN GdipDeleteBrush(brush)
IF graphics THEN GdipDeleteGraphics(graphics)
IF bmp THEN GdipDisposeImage(CAST(GpImage PTR, bmp))

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageHeight

Gets the height, in pixels, of an image.

```
FUNCTION GdipGetImageHeight (BYVAL image AS GpImage PTR, BYVAL nHeight AS UINT) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *nHeight* | [out] Pointer to a variable that receives the height, in pixels, of this image. |

#### Example

The following example retrieves the height, in pixels, of an image.

```
DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the height of the image
DIM nHeight AS UINT
hStatus = GdipGetImageHeight(image, @nHeight)
PRINT "Image height: " & WSTR(nHeight)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageHorizontalResolution

Retrieves the the horizontal resolution, in dots per inch, of an image.

```
FUNCTION GdipGetImageHorizontalResolution (BYVAL image AS GpImage PTR, BYVAL resolution AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object. |
| *resolution* | [out] Pointer to a SINGLE variable that receives the horizontal resolution, in dots per inch, of this image. |

#### Example

The following example retrieves the the horizontal resolution, in dots per inch, of an image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the width of the image
DIM resolution AS SINGLE
hStatus = GdipGetImageHorizontalResolution(image, @resolution)
PRINT "The horizontal resolution is " & STR(resolution) & " dots per inch"

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageItemData

Gets one piece of metadata from an **Image** object.

```
FUNCTION GdipGetImageItemData (BYVAL image AS GpImage PTR, BYVAL item AS ImageItemData PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object. |
| *item* | [in] Pointer to an **ImageItemData** structure that specifies the item to be retrieved. The **Data** member of the **ImageItemData** structure points to a buffer that receives the custom metadata. If the **Data** member is set to NULL, this method returns the size of the required buffer in the **DataSize** member of the **ImageItemData** object. |

---

## GdipGetImagePalette

Gets the color palette of an image.

```
FUNCTION GdipGetImagePalette (BYVAL image AS GpImage PTR, BYVAL _palette AS ColorPalette PTR, _
   BYVAL nSize AS INT_) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object. |
| *_palette* | [out] Pointer to a **ColorPalette** structure that receives the palette. |
| *_palette* | [in] Long integer value that specifies the size, in bytes, of the palette. Call the **GdipGetPaletteSize** method to determine the size. |

#### Example

The following example creates an Image object based on a BMP file. The image in that file uses 8 bits per pixel. The code calls the **GdipGetImagePaletteSize** function to determine the size of the image's palette. The call to **Allocate** allocates a buffer large enough to receive the palette, and the call to **GdipGetImagePalette** fills that buffer. The code displays the number of colors in the palette (*_palette->Count*) and then displays the ARGB values of the first five colors in the palette.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber8bit.bmp", @image)

' // Get the size of the palette
DIM paletteSize AS LONG
hStatus = GdipGetImagePaletteSize(image, @paletteSize)
PRINT "The size of the palette is" & STR(paletteSize) & " bytes"

' // Allocate buffer
DIM _palette AS ColorPalette PTR
_palette = Allocate(paletteSize)

' // Retrieve the palette
hStatus = GdipGetImagePalette(image, _palette, paletteSize)

' Print first few entries
FOR i AS INTEGER = 0 TO MIN(5, _palette->Count - 1)
   DIM argb AS ARGB = _palette->Entries(i)
   PRINT "Color "; i; ": "; HEX(argb)
NEXT

' // Cleanup
IF _palette THEN Deallocate(_palette)
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```

## GdipGetImagePaletteSize

Gets the size, in bytes, of the color palette of an image.

```
FUNNCTION GdipGetImagePaletteSize (BYVAL image AS GpImage PTR, BYVAL nSize aS INT_ PTR) AS GpStatus
```

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber8bit.bmp", @image)

' // Get the size of the palette
DIM paletteSize AS LONG
hStatus = GdipGetImagePaletteSize(image, @paletteSize)
PRINT "The size of the palette is" & STR(paletteSize) & " bytes"

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImagePixelFormat

Gets the pixel format of an image.

```
FUNCTION GdipGetImagePixelFormat (BYVAL image AS GpImage PTR, BYVAL nFormat AS PixelFormat) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object. |
| *nFormat* | [in] Poingter to a variable that receives an integer value that indicates the pixel format of the image |

#### PixelFormat constants

| Constant | Description |
| -------- | ----------- |
| *PixelFormat1bppIndexed* | Specifies that the format is 1 bit per pixel, indexed. |
| *PixelFormat4bppIndexed* | Specifies that the format is 4 bits per pixel, indexed. |
| *PixelFormat8bppIndexed* | Specifies that the format is 8 bits per pixel, indexed. |
| *PixelFormat16bppARGB1555* | Specifies that the format is 16 bits per pixel; 1 bit is used for the alpha component, and 5 bits each are used for the red, green, and blue components. |
| *PixelFormat16bppGrayScale* | Specifies that the format is 16 bits per pixel, grayscale. |
| *PixelFormat16bppRGB555* | Specifies that the format is 16 bits per pixel; 5 bits each are used for the red, green, and blue components. The remaining bit is not used. |
| *PixelFormat16bppRGB565* | Specifies that the format is 16 bits per pixel; 5 bits are used for the red component, 6 bits are used for the green component, and 5 bits are used for the blue component. |
| *PixelFormat24bppRGB* | Specifies that the format is 24 bits per pixel; 8 bits each are used for the red, green, and blue components. |
| *PixelFormat32bppARGB* | Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components. |
| *PixelFormat32bppPARGB* | Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied according to the alpha component. |
| *PixelFormat32bppRGB* | Specifies that the format is 32 bits per pixel; 8 bits each are used for the red, green, and blue components. The remaining 8 bits are not used. |
| *PixelFormat48bppRGB* | Specifies that the format is 48 bits per pixel; 16 bits each are used for the red, green, and blue components. |
| *PixelFormat64bppARGB* | Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components. |
| *PixelFormat64bppPARGB* | Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied according to the alpha component. |

#### Example

This example creates an Image object, gets the pixel format of the Image object and compares the obtained value to particular pixel format constants.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the pixel format
DIM nFormat AS PixelFormat
hStatus = GdipGetImagePixelFormat(image, @nFormat)

DIM strFormat AS STRING
SELECT CASE nFormat
   CASE PixelFormat1bppIndexed    : strFormat = "1 bpp indexed"
   CASE PixelFormat4bppIndexed    : strFormat = "4 bpp indexed"
   CASE PixelFormat8bppIndexed    : strFormat = "8 bpp indexed"
   CASE PixelFormat16bppGrayScale : strFormat = "16 bpp gray scale"
   CASE PixelFormat16bppRGB555    : strFormat = "16 bpp RGB 555"
   CASE PixelFormat16bppRGB565    : strFormat = "16 bpp RGB 565"
   CASE PixelFormat16bppARGB1555  : strFormat = "16 bpp ARGB 1555"
   CASE PixelFormat24bppRGB       : strFormat = "24 bpp RGB"
   CASE PixelFormat32bppRGB       : strFormat = "32 bpp RGB"
   CASE PixelFormat32bppARGB      : strFormat = "32 bpp ARGB"
   CASE PixelFormat32bppPARGB     : strFormat = "32 bpp PARGB"
   CASE PixelFormat48bppRGB       : strFormat = "48 bpp RGB"
   CASE PixelFormat64bppARGB      : strFormat = "64 bpp ARGB"
   CASE PixelFormat64bppPARGB     : strFormat = "64 bpp PARGB"
   CASE ELSE
      strFormat = STR(nFormat)
END SELECT

PRINT "The pixel format of the image is " & strFormat

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageRawFormat

Gets a globally unique identifier (GUID) that identifies the format of the image.

```
FUNCTION GdipGetImageRawFormat (BYVAL image AS GpImage PTR, BYVAL gformat AS GUID PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object. |
| *gformat* | [out] Pointer to a **GUID** variable that receives the format identifier. |

#### Image format GUIDs

```
' // Image Format GUIDs
Dim Shared ImageFormatBMP       As GUID = Type(&hB96B3CAB, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatEMF       As GUID = Type(&hB96B3CAC, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatEXIF      As GUID = Type(&hB96B3CB2, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatGIF       As GUID = Type(&hB96B3CB0, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatIcon      As GUID = Type(&hB96B3CB5, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatJPEG      As GUID = Type(&hB96B3CAE, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatMemoryBMP As GUID = Type(&hB96B3CB4, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatPNG       As GUID = Type(&hB96B3CAF, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatTIFF      As GUID = Type(&hB96B3CB1, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatUndefined As GUID = Type(&hB96B3CAA, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
Dim Shared ImageFormatWMF       As GUID = Type(&hB96B3CAD, &h0728, &h11D3, {&h9D, &h7B, &h00, &h00, &hF8, &h1E, &hF3, &h2E})
```

#### Example

This example loads a .JPG image and gets the GUID that identifies the format of the image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the pixel format
DIM rguid AS GUID
hStatus = GdipGetImageRawFormat(image, @rguid)

IF IsEqualIID(@rguid, @ImageFormatJPEG) THEN PRINT "The format is JPEG"

' // List of formats
' ImageFormatBMP
' ImageFormatEMF
' ImageFormatEXIF
' ImageFormatGIF
' ImageFormatIcon
' ImageFormatJPEG
' ImageFormatMemoryBMP
' ImageFormatPNG
' ImageFormatTIFF
' ImageFormatUndefined
' ImageFormatWMF

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageThumbnail

Gets a thumbnail image from an **Image** object.

```
FUNCTION GdipGetImageThumbnail (BYVAL image AS GpImage PTR, BYVAL thumbWidth AS UINT, _
   BYVAL thumbHeight AS UINT, BYVAL thumbImage as GpImage PTR, BYVAL callback AS GetThumbnailImageAbort PTR, _
   BYVAL callbackData AS VOID PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *thumbWidth* | [in] Width, in pixels, of the requested thumbnail image. |
| *thumbHeight* | [in] Height, in pixels, of the requested thumbnail image. |
| *thumbImage* | [out] Pointer to an **Image** object that contains the thumbnail image. |
| *callback* | [in] Callback function that you provide. During the process of creating or retrieving the thumbnail image, Microsoft Windows GDI+ calls this function to give you the opportunity to abort the process. The default value is NULL. |
| *callbackData* | [[in] Pointer to a block of memory that contains data to be used by the callback function. The default value is NULL. |

#### Example

The following example creates an Image object based on a JPEG file. The code calls the GdipGetImageThumbnail function and then displays the thumbnail image along with the main image.

```
' ========================================================================================
SUB Example_GetThumbnailImage (BYVAL hdc AS HDC)

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

   ' // Load the original image from file
   DIM image AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image)
   ' // Set the resolution of this Image object to the user's DPI settings
   hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image), dpiX, dpiY)

   ' // Get a 40x40 pixels thumbnail of the image
   DIM thumbnail AS GpImage PTR
   hStatus = GdipGetImageThumbnail(image, 40, 40, @thumbnail, NULL, NULL)
   
   DIM AS LONG nWidth, nHeight
   hStatus = GdipGetImageWidth(thumbnail, @nWidth)
   hStatus = GdipGetImageHeight(thumbnail, @nHeight)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image, 10, 10)
   ' // Draw the thumbnail image
   hStatus = GdipDrawImageRect(graphics, thumbnail, 200, 10, nWidth, nHeight)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF thumbnail THEN GdipDisposeImage(thumbnail)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```

#### Helper functions

```
' =======================================================================================
' Loads an image from disk an converts it to a texture for use with OpenGL.
' Parameters:
' * wszFileSpec = [in] The path of the image.
' * TextureWidth = [out] Width of the texture.
' * TextureHeight = [out] Height of the texture.
' * strTextureData = [out] The texture data.
' Return value:
' * ERROR_FILE_NOT_FOUND = File not found.
' * ERROR_INVALID_DATA = Bad image size.
' * A GdiPlus status value.
' =======================================================================================
PRIVATE FUNCTION AfxGdipLoadTexture OVERLOAD (BYREF wszFileName AS WSTRING, BYREF TextureWidth AS LONG, _
   BYREF TextureHeight AS LONG, BYREF strTextureData AS STRING) AS LONG

   DIM pImage AS GpImage PTR, pThumb AS GpImage PTR
   DIM nStatus AS GpStatus, pixColor AS GDIP_BGRA
   DIM pTextureData AS ANY PTR

   ' // Initialize Gdiplus
   DIM token AS ULONG_PTR = AfxGdipInit
   IF token = NULL THEN FUNCTION = 18 : EXIT FUNCTION   ' // GdiplusNotInitialized

   DO
      ' // Load the image from file
      nStatus = GdipLoadImageFromFile(@wszFileName, @pImage)
      IF nStatus <> 0 THEN EXIT DO
      ' // Get the image width and height
      nStatus = GdipGetImageWidth(pImage, @TextureWidth)
      IF nStatus <> 0 THEN EXIT DO
      nStatus = GdipGetImageHeight(pImage, @TextureHeight)
      IF nStatus <> 0 THEN EXIT DO
      IF TextureWidth <> TextureHeight THEN nStatus = ERROR_INVALID_DATA : EXIT DO
      ' // Check if the texture if a power of 2
      DIM nCount AS LONG, nPos AS LONG = 1
      DO
         nPos = INSTR(nPos, BIN(TextureWidth), "1")
         IF nPos = 0 THEN EXIT DO
         nCount += 1
         nPos += 1
      LOOP
      IF nCount <> 1 THEN nStatus = ERROR_INVALID_DATA : EXIT DO
      ' // Get a thumbnail image from the Image object
      nStatus = GdipGetImageThumbnail(pImage, TextureWidth, TextureHeight, @pThumb, NULL, NULL)
      IF nStatus <> 0 THEN EXIT DO
      ' // Flip the image vertically
      nStatus = GdipImageRotateFlip(pThumb, 6) ' 6 = RotateNoneFlipY
      IF nStatus <> 0 THEN EXIT DO
      ' // Fill the strings with nulls
      strTextureData = STRING(TextureWidth * TextureHeight * 4, CHR(0))
      ' // Get a pointer to the beginning of the string buffer
      pTextureData = STRPTR(strTextureData)
      ' // Swap the red and blue colors
      FOR y AS LONG = 0 TO TextureWidth - 1
         FOR x AS LONG = 0 TO TextureHeight - 1
            GdipBitmapGetPixel(cast(GpBitmap PTR, pThumb), x, y, @pixColor.color)
            SWAP pixColor.red, pixColor.blue
            memcpy pTextureData, @pixColor.color, 4
            pTextureData += 4
         NEXT
      NEXT
      EXIT DO
   LOOP

   ' // Free the image
   IF pImage THEN GdipDisposeImage pImage
   ' // Shutdown Gdiplus
   GdiplusShutdown token

   FUNCTION = nStatus

END FUNCTION
' =======================================================================================
```
```
' =======================================================================================
' Loads an image from a resource file an converts it to a texture for use with OpenGL.
' Parameters:
' * hInstance = [in] The instance handle.
' * wszResourceName = [in] The name of the resource.
' * TextureWidth = [out] Width of the texture.
' * TextureHeight = [out] Height of the texture.
' * strTextureData = [out] The texture data.
' Return value:
' * E_POINTER = Invalid pointer.
' * ERROR_FILE_NOT_FOUND = File not found.
' * ERROR_INVALID_DATA = Bad image size.
' * A GdiPlus status value.
' =======================================================================================
PRIVATE FUNCTION AfxGdipLoadTexture OVERLOAD (BYVAL hInstance AS HINSTANCE, _
   BYREF wszResourceName AS WSTRING, BYREF TextureWidth AS LONG, _
   BYREF TextureHeight AS LONG, BYREF strTextureData AS STRING) AS LONG

   DIM pImage AS GpImage PTR, pThumb AS GpImage PTR
   DIM nStatus AS GpStatus, pixColor AS GDIP_BGRA
   DIM pTextureData AS ANY PTR

   DIM hResource     AS HRSRC                 ' // Resource handle
   DIM pResourceData AS ANY PTR               ' // Pointer to the resoruce data
   DIM hGlobal       AS HGLOBAL               ' // Global memory handle
   DIM pGlobalBuffer AS ANY PTR               ' // Pointer to global memory buffer
   DIM pImageStream  AS IStream PTR           ' // IStream interface pointer
   DIM imageSize     AS DWORD                 ' // Image size


   ' // Initialize Gdiplus
   DIM token AS ULONG_PTR = AfxGdipInit
   IF token = NULL THEN FUNCTION = 18 : EXIT FUNCTION   ' // GdiplusNotInitialized

   DO
      ' // Find the resource and lock it
      hResource = FindResourceW(cast(HMODULE, hInstance), @wszResourceName, CAST(LPCWSTR, RT_RCDATA))
      IF hResource = NULL THEN nStatus = E_POINTER : EXIT DO
      imageSize = SizeofResource(cast(HMODULE, hInstance), hResource)
      IF imageSize = 0 THEN nStatus = ERROR_INVALID_DATA : EXIT DO
      pResourceData = LockResource(LoadResource(cast(HMODULE, hInstance), hResource))
      IF pResourceData = NULL THEN nStatus = E_POINTER : EXIT DO
      ' // Allocate memory to hold the image
      hGlobal = GlobalAlloc(GMEM_MOVEABLE, imageSize)
      IF hGlobal = NULL THEN nStatus = E_POINTER : EXIT DO
      ' // Lock the memory
      pGlobalBuffer = GlobalLock(hGlobal)
      IF pGlobalBuffer = NULL THEN nStatus = E_POINTER : EXIT DO
      ' // Copy the image from the resource file to global memory
      memcpy pGlobalBuffer, pResourceData, imageSize
      ' // Create an stream in global memory
      DIM hr AS HRESULT = CreateStreamOnHGlobal(hGlobal, FALSE, @pImageStream)
      IF hr <> S_OK THEN nStatus = hr : EXIT DO
      ' // Create a bitmap from the data contained in the stream
      nStatus = GdipCreateBitmapFromStream(pImageStream, @cast(GpBitmap PTR, pImage))
      IF nStatus <> 0 THEN EXIT DO
      ' // Get the image width and height
      nStatus = GdipGetImageWidth(pImage, @TextureWidth)
      IF nStatus <> 0 THEN EXIT DO
      nStatus = GdipGetImageHeight(pImage, @TextureHeight)
      IF nStatus <> 0 THEN EXIT DO
      IF TextureWidth <> TextureHeight THEN nStatus = ERROR_INVALID_DATA : EXIT DO
      ' // Check if the texture if a power of 2
      DIM nCount AS LONG, nPos AS LONG = 1
      DO
         nPos = INSTR(nPos, BIN(TextureWidth), "1")
         IF nPos = 0 THEN EXIT DO
         nCount += 1
         nPos += 1
      LOOP
      IF nCount <> 1 THEN nStatus = ERROR_INVALID_DATA : EXIT DO
      ' // Get a thumbnail image from the Image object
      nStatus = GdipGetImageThumbnail(pImage, TextureWidth, TextureHeight, @pThumb, NULL, NULL)
      IF nStatus <> 0 THEN EXIT DO
      ' // Flip the image vertically
      nStatus = GdipImageRotateFlip(pThumb, 6) ' 6 = RotateNoneFlipY
      IF nStatus <> 0 THEN EXIT DO
      ' // Fill the strings with nulls
      strTextureData = STRING(TextureWidth * TextureHeight * 4, CHR(0))
      ' // Get a pointer to the beginning of the string buffer
      pTextureData = STRPTR(strTextureData)
      ' // Swap the red and blue colors
      FOR y AS LONG = 0 TO TextureWidth - 1
         FOR x AS LONG = 0 TO TextureHeight - 1
            GdipBitmapGetPixel(cast(GpBitmap PTR, pThumb), x, y, @pixColor.color)
            SWAP pixColor.red, pixColor.blue
            memcpy pTextureData, @pixColor.color, 4
            pTextureData += 4
         NEXT
      NEXT
      EXIT DO
   LOOP

   ' // Release if IStream interface
   IF pImageStream THEN pImageStream->lpvtbl->Release(pImageStream)
   ' // Unlock the memory
   IF pGlobalBuffer THEN GlobalUnlock(pGlobalBuffer)
   ' // Free the global memory
   IF hGlobal THEN GlobalFree(hGlobal)

   ' // Free the image
   IF pImage THEN GdipDisposeImage pImage
   ' // Shutdown Gdiplus
   GdiplusShutdown token

   FUNCTION = nStatus

END FUNCTION
' =======================================================================================
```
---

## GdipGetImageType

Gets the type (bitmap or metafile) of an image.

```
FUNCTOION GdipGetImageType (BYVAL image AS GpImage PTR, BYVAL imageType AS ImageType PTR) AS GpStatus
```

The following example gets the type (bitmap or metafile) of an Image object.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the image file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the type of the image
DIM imageType AS LONG
hStatus = GdipGetImageType(image, @imageType)

IF imageType = ImageTypeBitmap THEN PRINT "The type of image is ImageTypeBitmap"

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageWidth

Gets the width, in pixels, of an image.

```
FUNCTION GdipGetImageWidth (BYVAL image AS GpImage PTR, BYVAL nWidth AS UINT) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *nWidth* | [out] Pointer to a variable that receives the width, in pixels, of this image. |

#### Example

The following example retrieves de width, in pixels, of an image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the width of the image
DIM nWidth AS UINT
hStatus = GdipGetImageWidth(image, @nWidth)
PRINT "Image width: " & WSTR(nWidth)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetImageVerticalResolution

Retrieves the the vertical resolution, in dots per inch, of an image.

```
FUNCTION GdipGetImageVerticalResolution (BYVAL image AS GpImage PTR, BYVAL resolution AS REAL PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to an **Image** object. |
| *resolution* | [out] Pointer to a SINGLE variable that receives the vertical resolution, in dots per inch, of this image. |

#### Example

The following example retrieves the the vertical resolution, in dots per inch, of an image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the width of the image
DIM resolution AS SINGLE
hStatus = GdipGetImageVerticalResolution(image, @resolution)
PRINT "The vertical resolution is " & STR(resolution) & " dots per inch"

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetPropertyCount

Gets the number of properties (pieces of metadata) stored in the image object.

```
FUNCTION GdipGetPropertyCount (BYVAL image AS GpImage PTR, BYVAL numOfProperty AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *numOfProperty* | [out] Pointer to a variable that receives the number of properties stored in the image. |

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the pixel format
DIM rguid AS GUID
hStatus = GdipGetImageRawFormat(image, @rguid)

' // Get the number of properties
DIm count AS UINT
hStatus = GdipGetPropertyCount(image, @count)
PRINT "Number of properties =" & STR(count)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetPropertyIdList

Gets a list of the property identifiers used in the metadata of the image.

```
FUNCTION GdipGetPropertyIdList (BYVAL image AS GpImage PTR, BYVAL numOfProperty AS UINT, _
   BYVAL list AS PROPID PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *numOfProperty* | [in] Integer that specifies the number of elements in the list array. Call the **GetPropertyCount** method to determine this number. |
| *list* | [out] Pointer to an array that receives the property identifiers. |

#### Example

```
' ========================================================================================
' Gets a list of the property identifiers used in the metadata of an Image object.
' ========================================================================================

'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the pixel format
DIM rguid AS GUID
hStatus = GdipGetImageRawFormat(image, @rguid)

' // Get the number of properties
DIM count AS UINT
hStatus = GdipGetPropertyCount(image, @count)
PRINT "Number of properties =" & STR(count)

' // Get the list of properties
DIM propIDs(count - 1) AS PROPID
hStatus = GdipGetPropertyIdList(image, count, @propIDs(0))
FOR i AS LONG = 0 TO count - 1
   PRINT "PROPID: " & HEX(propIDs(i))
NEXT

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetPropertyItem

Gets a specified property item (piece of metadata) from the image.

```
FUNCTION GdipGetPropertyItem (BYVAL image AS GpImage PTR, BYVAL propId AS PROPID, _
   BYVAL propSize AS UINT, BYVAL buffer AS PropertyItem PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *propId* | [in] The property item to be retrieved. |
| *propSize* | [in] The size, in bytes, of the property item to be retrieved. Call the **GdipGetPropertyItemSize** method to determine the size. |
| *buffer* | [out] Pointer to a **PropertyItem** structure that receives the property item. |

#### Example

This example gets the values of the PropertyTagLuminanceTable property of the image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the size of the specified property item.
DIM itemSize AS UINT
hStatus = GdipGetPropertyItemSize(image, PropertyTagLuminanceTable, @itemSize)

' // Allocate buffer and retrieve item
DIM buffer AS UBYTE PTR = Allocate(itemSize)
hStatus = GdipGetPropertyItem(image, PropertyTagLuminanceTable, itemSize, cast(PropertyItem PTR, buffer))
IF hStatus = S_OK Then
   DIM propItem AS PropertyItem PTR = cast(PropertyItem PTR, buffer)
   DIM values AS UBYTE PTR = cast(UBYTE PTR, propItem->value)
   PRINT "Luminance Table ("; propItem->length; " bytes):"
   FOR i AS LONG = 0 TO propItem->length - 1
      PRINT values[i]; " ";
      IF (i + 1) MOD 16 = 0 THEN PRINT
   NEXT
ELSE
   PRINT "Failed to retrieve luminance table"
END IF

' // Cleanup
IF buffer THEN Deallocate buffer
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetPropertyItemSize

Gets the size, in bytes, of a specified property item of the image.

```
FUNCTION GdipGetPropertyItemSize (BYVAL image AS GpImage PTR, BYVAL propId AS PROPID, _
   BYVAL nSize AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *propId* | [in] The property item to be retrieved. |
| *nSize* | [out] Pointer to a variable that receives the size, in bytes, of a specified property item of the image. |

#### Example

This example gets the size, in bytes, of the PropertyTagLuminanceTable property of the image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the size of the specified property item.
DIM itemSize AS UINT
hStatus = GdipGetPropertyItemSize(image, PropertyTagLuminanceTable, @itemSize)

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipGetPropertySize

The **GdipGetPropertySize** function gets the total size, in bytes, of all the property items stored in an **Image** object. It also also gets the number of property items stored in the **Image** object.

```
FUNCTION GdipGetPropertySize (BYVAL image AS GpImage PTR, BYVAL totalBufferSize AS UINT PTR, _
   BYVAL numProperties AS UINT PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *totalBufferSize* | [out] Pointer to a UINT that receives the total size, in bytes, of all the property items. |
| *numProperties* | [out] Pointer to a UINT that receives the number of property items. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

' ========================================================================================
' Gets the total size, in bytes, of all the property items stored in an Image object.
' It also gets the number of property items stored in the Image object.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("BERRY_Halle_01.jpg", @image)

DIM AS UINT totalBufferSize, numProperties
hStatus = GdipGetPropertySize(image, @totalBufferSize, @numProperties)
IF hStatus = StatusOK THEN
   print "Total buffer size: " & WSTR(totalBufferSize)
   print "Number of properties: " & WSTR(numProperties)
END IF

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipImageRotateFlip

Rotates and flips this image.

```
FUNCTION GdipImageRotateFlip (BYVAL image AS GpImage PTR, BYVAL rfType AS RotateFlipType) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *rfType* | [in] Element of the *RotateFlipType* enumeration that specifies the type of rotation and the type of flip. |

#### Example

The following example creates an Image object based on a JPEG file. The code calls the GdipImageRotateFlip function to rotate the image clockwise 90 degrees and then flip the image vertically. The code draws the image twice: once before and once after the call to GdipImageRotateFlip.

```
' ========================================================================================
SUB GDIP_ImageRotateFlip (BYVAL hdc AS HDC)

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

   ' // Load the image from file
   DIM image AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image)
   ' // Set the resolution of this Image object to the user's DPI settings
   hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image), dpiX, dpiY)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image, 10, 10)
   ' // RotateFlip the image 90 degrees and draw it
   hStatus = GdipImageRotateFlip(image, Rotate90FlipY)
   hStatus = GdipDrawImage(graphics, image, 220, 10)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipImageSelectActiveFrame

Selects the frame in this **Image** object specified by a dimension and an index.

```
FUNCTION GdipImageSelectActiveFrame (BYVAL image AS GpImage PTR, BYVAL dimensionID AS GUID PTR, _
   BYVAL frameIndex AS UINT) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *dimensionID* | [in] Pointer to a GUID that specifies the frame dimension. |
| *frameIndex* | [in] Long integer value that specifies the index of the frame within the specified frame dimension. |

#### Example

The following example retrieves the individual frames from a multiple-frame TIFF file. The code constructs an Image object from the multiple-frame TIFF file. To retrieve the individual frames (pages), the code calls the GdipImageSelectActiveFrame function. The first argument passed to the GdipImageSelectActiveFrame function is the address of the image. The second argument is the address of a globally unique identifier (GUID) that specifies the dimension in which the frames were previously added to the multiple-frame TIFF file. The third argument is the zero-based index of the desired page.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("MultiFrame.tiff", @image)

' // Get the CLSID of the PNG encoder.
DIM EncoderClsid AS GUID = AfxGdipGetEncoderClsid("image/png")

' // Save the first page (index 0).
hStatus = GdipImageSelectActiveFrame(image, @FrameDimensionPage, 0)
DIM wszFileName AS WSTRING * 260 = "Page0.png"
hStatus = GdipSaveImageToFile(image, @wszFileName, @EncoderClsid, NULL)
IF hStatus = S_OK THEN PRINT "Page 0 saved successfully"

' // Save the second page (index 1).
hStatus = GdipImageSelectActiveFrame(image, @FrameDimensionPage, 1)
wszFileName = "Page1.png"
hStatus = GdipSaveImageToFile(image, @wszFileName, @EncoderClsid, NULL)
IF hStatus = S_OK THEN PRINT "Page 1 saved successfully"

' // Save the second page (index 2).
hStatus = GdipImageSelectActiveFrame(image, @FrameDimensionPage, 2)
wszFileName = "Page2.png"
hStatus = GdipSaveImageToFile(image, @wszFileName, @EncoderClsid, NULL)
IF hStatus = S_OK THEN PRINT "Page 2 saved successfully"

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipImageSetAbort

Sets an application-defined function that is called periodically by Windows GDI+ during time-consuming rendering operations.

```
FUNCTION GdipImageSetAbort (BYVAL image AS GpImage PTR, BYVAL abort AS GdiplusAbort PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *abort* | [in] Pointer to a **GdiplusAbort** function. |

#### Remarks

To create a callback method, follow these steps.

1. Create a structure that descends from **GdiplusAbort**, and implement the following function.
HRESULT __stdcall Abort(void)
2. Create data members to hold any data that will be needed by the **Abort** function.
3. Pass the address of the **GdiplusAbort** descendant to the **GdipGraphicsSetAbort** function.

During certain time-consuming rendering operations (for example, a call to the **GdipDrawImage** function), GDI+ calls the **Abort** function periodically. For some operations the callback is every 250 milliseconds; for other operations the callback is not based on a timer. If the **Abort** function returns S_OK, GDI+ continues the rendering operation. If the **Abort** function returns **E_ABORT**, GDI+ aborts the rendering operation.

---

## GdipLoadImageFromFile

Creates an **Image** object based on a file.

```
FUNCTION GdipLoadImageFromFile (BYVAL filename AS WSTRING PTR, BYVAL image AS GpImage PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *filename* | [in] Pointer to a null-terminated unicode string that specifies the name of the file. |
| *image* | [out] Pointer to a **GpImage** variable that receives a pointer to the new created **Image** object. |

#### Example

The following example creates an Image object based on a JPEG file. Then the code calls the GdipDrawImage function to draw the image.

```
' ========================================================================================
SUB Example_LoadImageFromFile (BYVAL hdc AS HDC)

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

   ' // Load the original image from file
   DIM image AS GpImage PTR
   hStatus = GdipLoadImageFromFile("climber.jpg", @image)

   ' // Set the resolution of this Image object to the user's DPI settings
   hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image), dpiX, dpiY)

   ' // Draw the original image
   hStatus = GdipDrawImage(graphics, image, 10, 10)

   ' // Cleanup
   IF image THEN GdipDisposeImage(image)
   IF graphics THEN GdipDeleteGraphics(graphics)

END SUB
' ========================================================================================
```
---

## GdipLoadImageFromStream

Creates an **Image** object based on a stream.

```
FUNCTION GdipLoadImageFromStream (BYVAL stream AS IStream PTR, BYVAL image AS GpImage PTR PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *stream* | [in] Pointer to the stream. |
| *image* | [out] Pointer to a **GpImage** variable that receives a pointer to the loaded **Image** object. |

#### Example

The following example creates two Image objects. Each Image object is based on a stream that is part of a compound file. For an example of creating a compound file, see **GdipSaveImageToStream**. The code calls **StgOpenStorage** to open the compound file and get a pointer to its **IStorage** interface. Then the code calls **IStorage.OpenStream** to get a pointer to an **IStream** interface that represents one of the streams in the compound file. The code constructs an **Image** object based on that **IStream** pointer and then calls **GdipDrawImage** to display the image on the screen. The code uses a similar process to construct an **Image** object based on a second stream that is part of the same compound file.

```
' ========================================================================================
SUB Example_LoadImageFromStream (BYVAL hdc AS HDC)

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

   ' // Open compound file
   DIM fileName As WSTRING * 260 = "CompoundFile.cmp"
   DIM storage AS IStorage PTR
   DIM hr AS HRESULT = StgOpenStorage(@fileName, NULL, STGM_READ OR STGM_SHARE_EXCLUSIVE, NULL, 0, @storage)
   IF FAILED(hr) THEN
      MessageBox(NULL, "StgOpenStorage failed", "Error", MB_OK)
      hStatus = GdipDeleteGraphics(graphics)
      EXIT SUB
   END IF

   ' // Open StreamImage1
   DIM stream1 AS IStream PTR
   DIM streamName1 AS WSTRING * 260 = "StreamImage1"
   hr = storage->lpvtbl->OpenStream(storage, streamName1, NULL, STGM_READ Or STGM_SHARE_EXCLUSIVE, 0, @stream1)

   ' // Open StreamImage2
   DIM stream2 AS IStream PTR
   DIM streamName2 AS WString * 260 = "StreamImage2"
   hr = storage->lpvtbl->OpenStream(storage, streamName2, NULL, STGM_READ Or STGM_SHARE_EXCLUSIVE, 0, @stream2)

   ' // Load image from stream1
   DIM image1 AS GpImage PTR
   hStatus = GdipLoadImageFromStream(stream1, @image1)
   IF hStatus = 0 THEN
      ' // Set the resolution of this Image object to the user's DPI settings
      hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image1), dpiX, dpiY)
      ' // Draw the image
      hStatus = GdipDrawImage(graphics, image1, 10, 10)
   END IF

   ' // Load image from stream2
   DIM image2 AS GpImage PTR
   hStatus = GdipLoadImageFromStream(stream2, @image2)
   IF hStatus = 0 THEN
      ' // Set the resolution of this Image object to the user's DPI settings
      hStatus = GdipBitmapSetResolution(cast(GpBitmap PTR, image2), dpiX, dpiY)
      ' // Draw the image
      hStatus = GdipDrawImage(graphics, image2, 200, 10)
   END IF

   ' // Cleanup
   IF image1 THEN GdipDisposeImage(image1)
   IF image2 THEN GdipDisposeImage(image2)
   IF graphics THEN GdipDeleteGraphics(graphics)
   IF stream1 THEN stream1->lpvtbl->Release(stream1)
   IF stream2 THEN stream2->lpvtbl->Release(stream2)
   IF storage THEN storage->lpvtbl->Release(storage)

END SUB
' ========================================================================================
```
---

## GdipRemovePropertyItem

Removes a property item (piece of metadata) from the image.

```
FUNCTION GdipRemovePropertyItem (BYVAL image AS GpImage PTR, BYVAL propId AS PROPID) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *propId* | [in] [in] Long integer value that identifies the property item to be removed. |

#### Remarks

For a list of property items, see: [Property item descriptions](https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-constant-property-item-descriptions)

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("BERRY_Halle_01.jpg", @image)   ' --> change me

' // Check if property exists
DIM size AS UINT
hStatus = GdipGetPropertyItemSize(image, PropertyTagImageTitle, @size)
PRINT "hStatus: ", hStatus
PRINT "Before removal, title size = "; size; " bytes"

' // Remove the property
hStatus = GdipRemovePropertyItem(image, PropertyTagImageTitle)

' // Check again
size = 0
hStatus = GdipGetPropertyItemSize(image, PropertyTagImageTitle, @size)
PRINT "After removal, title size = "; size; " bytes"

' // optional: save the modified image.

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipSaveAdd

This function is used to fkush and finalize a multframe image file after you've added all the frames with **GdipSaveAddImage**. It closes the multi-frame image file or stream,ensuringthat all added frames are written and the file is complete.Must be called with **EncoderValueFlush** in the **EncoderParameters**.

```
FUNCTION GdipSaveAdd (BYVAL image As GpImage PTR, BYVAL encoderParams AS EncoderParameters PTR) AS GpStatus
```

#### Example

Seethe example for **GdipSaveAddImage**.

---

## GdipSaveAddImage

Adds a frame to a file or stream specified in a previous call to the **GdipSaveImageToFile** or **GdipSaveImageToStream** functions.

```
FUNCTION GdipSaveAddImage (BYVAL image AS GpImage PTR, BYVAL newImage AS GpImage PTR, _
   BYVAL encoderParams AS EncoderParameters PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *newImage* | [in] Pointer to an **Image** object that holds the frame to be added. |
| *encoderParams* | [in] Pointer to an **EncoderParameters** structure that holds parameters required by the image encoder used by the save-add operation. |

#### Example

**Creating and Saving a Multiple-Frame Image**

With certain file formats, you can save multiple images (frames) to a single file. For example, you can save several pages to a single TIFF file. To save the first page, call the **GdipSaveImageToFile** function. To save subsequent pages, call the **GdipSaveAddImage** function.

The following console application creates a TIFF file with three pages. The images that become the pages of the TIFF file come from three disk files. The code first constructs three **Image** objects: multi, page2 and page3. As the individual pages are added to the multiImage object, they are also added to the disk file Multiframe.tif. Note that the code calls **GdipSaveImageToFile** (not **GdipSaveAddImage**) to save the first page. The second argument passed to the **GdipSaveImageToFile** function is the name of the disk file that will eventually contain several frames. The third argument passed to the **GdipSaveImageToFile** function specifies the encoder that will be used to convert the data in the multiImage object to the format (in this case TIFF) required by the disk file.

That same encoder is used automatically by all subsequent calls to the **GdipSaveAddImage** function of the multiImage object.

The fourth argument passed to the **GdipSaveImageToFile** function is the address of an **EncoderParameters** structure The **EncoderParameters** structure has an array that contains a single **EncoderParameter** structure. The **Guid** member of that **EncoderParameter** structure is set to **EncoderSaveFlag**. The **Value** member of the **EncoderParameter** structure points to an ULONG variable that contains the value **EncoderValueMultiFrame**. The code saves the second and third pages by calling the **GdipSaveAddImage** function.

The first argument passed to the **GdipSaveAddImage** function is the address of the multi object. The second argument is the address of an **Image** object. The image in that **Image** object is added to the multiImage object and is also added to the Multiframe.tif disk file. The third argument passed to the **GdipSaveAddImage** function is the address of the same **EncoderParameters** structure that was used by the **GdipSaveImageToFile** function. The difference is that the ULONG pointed to by the Value member now contains the value **EncoderValueFrameDimensionPage**. Finally, the file is closed calling the **GdipSaveAdd** function with the **Value** member of the **EncoderParameter** structure pointing to an ULONG variable that contains the value **EncoderValueFlush**.

The main function relies on the helper function **AfxGdiPlusGetEncoderClsid** to retrieve the guid of the TIFF encoder.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create three image objects.
DIM multi AS GpImage Ptr
DIM page2 AS GpImage Ptr
DIM page3 AS GpImage Ptr
hStatus = GdipLoadImageFromFile("Shapes.bmp", @multi)
hStatus = GdipLoadImageFromFile("Iron.jpg", @page2)
hStatus = GdipLoadImageFromFile("House.png", @page3)

' // Get TIFF encoder CLSID
Dim clsid As CLSID = AfxGdipGetEncoderClsid("image/tiff")

' // Prepare EncoderParameters
DIM encoderParams As EncoderParameters
DIM paramValue As ULONG
encoderParams.Count = 1
encoderParams.Parameter(0).Guid = EncoderSaveFlag
encoderParams.Parameter(0).Type = EncoderParameterValueTypeLong
encoderParams.Parameter(0).NumberOfValues = 1
encoderParams.Parameter(0).Value = @paramValue

' // Save first frame
paramValue = EncoderValueMultiFrame
hStatus = GdipSaveImageToFile(multi, "multiframe.tiff", @clsid, @encoderParams)

' // Add second frame
paramValue = EncoderValueFrameDimensionPage
hStatus = GdipSaveAddImage(multi, page2, @encoderParams)

' // Add third frame
paramValue = EncoderValueFrameDimensionPage
hStatus = GdipSaveAddImage(multi, page3, @encoderParams)

' // Finalize file
paramValue = EncoderValueFlush
hStatus = GdipSaveAdd(multi, @encoderParams)

IF hStatus = S_OK THEN PRINT "File saved" ELSE PRINT "Saving failed"

' // Cleanup
IF page3 THEN GdipDisposeImage(page3)
IF page2 THEN GdipDisposeImage(page2)
IF multi THEN GdipDisposeImage(multi)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipSaveImageToFile

Saves an image to a file.

```
FUNCTION GdipSaveImageToFile (BYVAL image As GpImage PTR, BYVAL finename AS WSTRING PTR, _
   BYVAL clsidEncoder AS CLSID PTR, BYVAL encoderParams AS EncoderParameters PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *finename* | [in] Pointer to a null-terminated unicode string that specifies the path name for the saved image. |
| *clsidEncoder* | [in] Pointer to a **CLSID** that specifies the encoder to use to save the image. |
| *encoderParams* | [in]  Pointer to an **EncoderParameters** structure that holds parameters used by the encoder. The default value is NULL. |

#### Example

This example demonstrates how to set the compression and color depth when converting an image to the tiff format. The **EncoderParameters** structure has two members, a dword with the number of **EncoderParameter** structures and an array of **EncoderParameter** structures.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("RYDER_Winona_01.jpg", @image)

' // Fill and EncoderParameter structure with the compression
DIM compression AS ULONG = EncoderValueCompressionLZW
DIM ep(1) AS EncoderParameter
ep(0).Guid = EncoderCompression
ep(0).NumberOfValues = 1
ep(0).Type = EncoderParameterValueTypeLong
ep(0).Value = @compression

DIM colorDepth AS ULONG = 24
ep(1).Guid = EncoderColorDepth
ep(1).NumberOfValues = 1
ep(1).Type = EncoderParameterValueTypeLong
ep(1).Value = @colorDepth

DIM encoderParams AS EncoderParameters
encoderParams.Count = 2
encoderParams.Parameter(0) = ep(0)
encoderParams.Parameter(1) = ep(1)

' // Get the TIFF encoder CLSID
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/tiff")

' // Save the image with parameters
hStatus = GdipSaveImageToFile(image, "RYDER_Winona_01.tiff", @clsid, @encoderParams)
IF hStatus = 0 THEN
   PRINT "Image converted successfully"
ElSE
   PRINT "Save failed, status = "; hStatus
END IF

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```

#### Helper functions

```
' ========================================================================================
' Saves a GDI+ image to file.
' Parameters:
' - pImage = Pointer to the GDI+ image to save.
' - wszFileName = Path name for the image to be saved.
' - wszMimeType = Mime type.
'   "image/bmp" = Bitmap (.bmp)
'   "image/gif" = GIF (.gif)
'   "image/jpeg" = JPEG (.jpg)
'   "image/png" = PNG (.png)
'   "image/tiff" = TIFF (.tiff)
' Return value:
' If the method succeeds, it returns Ok, which is an element of the Status enumeration.
' If the method fails, it returns one of the other elements of the Status enumeration.
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveImageToFile (BYVAL pImage AS GpImage PTR, BYREF wszFileName AS WSTRING, BYREF wszMimeType AS WSTRING) AS LONG
   IF pImage = NULL OR LEN(TRIM(wszFileName)) = 0 THEN RETURN InvalidParameter
   ' // Initialize Gdiplus
   DIM token AS ULONG_PTR = AfxGdipInit
   IF token = 0 THEN EXIT FUNCTION
   DIM clsidEncoder AS GUID = AfxGdipGetEncoderClsid(wszMimeType)
   FUNCTION = GdipSaveImageToFile(pImage, @wszFileName, @clsidEncoder, NULL)
   ' // Shutdown Gdiplus
   GdiplusShutdown token
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveImageToBmp (BYVAL pImage AS GpImage PTR, BYREF wszFileName AS WSTRING) AS LONG
   FUNCTION = AfxGdipSaveImageToFile(pImage, wszFilename, "image/bmp")
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveImageToJpeg (BYVAL pImage AS GpImage PTR, BYREF wszFileName AS WSTRING) AS LONG
   FUNCTION = AfxGdipSaveImageToFile(pImage, wszFilename, "image/jpeg")
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveImageToPng (BYVAL pImage AS GpImage PTR, BYREF wszFileName AS WSTRING) AS LONG
   FUNCTION = AfxGdipSaveImageToFile(pImage, wszFilename, "image/png")
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveImageToGif (BYVAL pImage AS GpImage PTR, BYREF wszFileName AS WSTRING) AS LONG
   FUNCTION = AfxGdipSaveImageToFile(pImage, wszFilename, "image/gif")
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveImageToTiff (BYVAL pImage AS GpImage PTR, BYREF wszFileName AS WSTRING) AS LONG
   FUNCTION = AfxGdipSaveImageToFile(pImage, wszFilename, "image/tiff")
END FUNCTION
' ========================================================================================
```
```
' ========================================================================================
' Saves a Windows bitmap to file.
' Parameters:
' - hbmp = Handle to the Windows bitmap.
' - wszFileName = Path name for the image to be saved.
' - wszMimeType = Mime type (default: "image/bmp").
'   "image/bmp" = Bitmap (.bmp)
'   "image/gif" = GIF (.gif)
'   "image/jpeg" = JPEG (.jpg)
'   "image/png" = PNG (.png)
'   "image/tiff" = TIFF (.tiff)
' Return value:
' If the method succeeds, it returns Ok, which is an element of the Status enumeration.
' If the method fails, it returns one of the other elements of the Status enumeration.
' ========================================================================================
PRIVATE FUNCTION AfxGdipSaveHBITMAPToFile (BYVAL hbmp AS HBITMAP, BYREF wszFileName AS WSTRING, BYREF wszMimeType AS WSTRING = "image/bmp") AS LONG
   IF hbmp = NULL OR LEN(TRIM(wszFileName)) = 0 THEN RETURN InvalidParameter
   ' // Initialize Gdiplus
   DIM token AS ULONG_PTR = AfxGdipInit
   ' // Create a Bitmap object from an HBITMAP
   DIM pBitmap AS GpBitmap PTR
   GdipCreateBitmapFromHBITMAP(hbmp, NULL, @pBitmap)
   IF pBitmap THEN
      DIM clsidEncoder AS GUID = AfxGdipGetEncoderClsid(wszMimeType)
      FUNCTION = GdipSaveImageToFile(CAST(GpImage PTR, pBitmap), @wszFileName, @clsidEncoder, NULL)
      GdipDisposeImage(cast(GpImage PTR, pBitmap))
   END IF
   IF token = 0 THEN EXIT FUNCTION
   ' // Shutdown Gdiplus
   GdiplusShutdown token
END FUNCTION
' ========================================================================================
```
---

## GdipSaveImageToStream

Saves an image to a stream.

```
FUNCTION GdipSaveImageToStream (BYVAL image AS GpImage PTR, BYVAL stream AS IStream PTR,  _
  BYVAL clsidEncoder AS CLSID PTR, BYVAL encoderParams AS EncoderParameters PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *stream* | [in] Pointer to an **IStream** interface. The implementation of **IStream** must include the Seek, Read, Write, and Stat methods. |
| *clsidEncoder* | [in] Pointer to a **CLSID** that specifies the encoder to use to save the image. |
| *encoderParams* | [in] Pointer to an **EncoderParameters** structure that holds parameters used by the encoder. The default value is NULL. |

#### Example

The following example creates two Image objects: one constructed from a JPEG file and another constructed from a PNG file. The code creates a compound file with two streams and saves the two images to those streams.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create two image objects.
DIM image1 AS GpImage PTR
DIM image2 AS GpImage PTR
GdipLoadImageFromFile("Iron.jpg", @image1)
GdipLoadImageFromFile("House.png", @image2)

' // Create compound file
DIM storage AS IStorage PTR
DIM compoundFileName AS WSTRING * 260 = "CompoundFile.cmp"
StgCreateDocfile(@compoundFileName, STGM_READWRITE OR STGM_CREATE OR STGM_SHARE_EXCLUSIVE, 0, @storage)

' Create two streams
DIM stream1 AS IStream PTR
DIM stream2 AS IStream PTR
DIM streamName1 AS WSTRING * 260 = "StreamImage1"
DIM streamName2 AS WSTRING * 260 = "StreamImage2"
storage->lpvtbl->CreateStream(storage, @streamName1, STGM_READWRITE Or STGM_SHARE_EXCLUSIVE, 0, 0, @stream1)
storage->lpvtbl->CreateStream(storage, @streamName2, STGM_READWRITE Or STGM_SHARE_EXCLUSIVE, 0, 0, @stream2)

' // Get encoder CLSIDs
DIM jpgClsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")
DIM pngClsid AS CLSID = AfxGdipGetEncoderClsid("image/png")

' // Save images to streams
hStatus = GdipSaveImageToStream(image1, stream1, @jpgClsid, NULL)
hStatus = GdipSaveImageToStream(image2, stream2, @pngClsid, NULL)

PRINT "File saved"

' // Cleanup
IF image1 THEN GdipDisposeImage(image1)
IF image2 THEN GdipDisposeImage(image2)
IF stream1 THEN stream1->lpvtbl->Release(stream1)
IF stream2 THEN stream2->lpvtbl->Release(stream2)
IF storage THEN storage->lpvtbl->Release(storage)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipSetPropertyItem

Sets a property item (piece of metadata) for the image. If the item already exists, then its contents are updated; otherwise, a new item is added.

```
FUNCTION GdipSetPropertyItem (BYVAL image AS GpImage PTR, BYVAL item AS PropertyItem PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *item* | [in] Pointer to a **PropertyItem** structure that specifies the property item to be set. |

#### Example

The following console application creates a Image object based on a JPEG file. The code calls the GdipSetPropertyItem function of that Image object to set the title of the image.

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("BERRY_Halle_01.jpg", @image)   ' --> change me

 ' // Set new title
 DIM titleText AS STRING = "Halle Berry"
 DIM prop As PropertyItem
 prop.id = PropertyTagImageTitle
 prop.length = LEN(titleText) + 1  ' Include null terminator
 prop.type = PropertyTagTypeASCII
 prop.value = STRPTR(titleText)

 IF GdipSetPropertyItem(image, @prop) = 0 Then
   PRINT "Title set successfully"
ELSE
   PRINT "Failed to set title"
 END IF

' // Save the modified file
AfxGdipSaveImageToJpeg(image, "modified.jpg")

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---

## GdipSetImagePalette

GdipSetImagePalette sets a custom color palette for an image object in GDI+. This only applies to indexed pixel formats like 1bpp, 4bpp, or 8bpp images (e.g., GIFs or 8-bit BMPs). It replaces the image’s current palette with a new one you define. The palette must match the image’s pixel format (e.g., 256 colors for 8bpp). Useful for customizing color mapping, reducing color depth, or preparing images for formats that require indexed color. If you try to use it on a 24-bit or 32-bit image, it won’t work—those formats don’t use palettes.

```
FUNCTION GdipSetImagePalette (BYVAL image AS GpImage PTR, BYVAL palette_ AS ColorPalette PTR) AS GpStatus
```

| Parameter  | Description |
| ---------- | ----------- |
| *image* | [in] Pointer to the **Image** object. |
| *palette_* | [in] Pointer to a **ColorPalette** structure that specifies the palette. |

#### Example

```
'#CONSOLE ON
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
USING AfxNova

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' Create a bitmap with 8bpp indexed format
DIM bmp AS GpBitmap Ptr
DIM nWidth AS LONG = 64
DIM nHeight AS LONG = 64
hStatus = GdipCreateBitmapFromScan0(nWidth, nHeight, 0, PixelFormat8bppIndexed, NULL, @bmp)
IF hStatus <> 0 THEN PRINT "Failed to create indexed bitmap"

' // Allocate and define a palette
DIM paletteSize AS LONG = SIZEOF(ColorPalette) + (256 * SIZEOF(ARGB))
DIM paletteBuffer AS UBYTE PTR = Allocate(paletteSize)
DIM paletteptr AS ColorPalette PTR = cast(ColorPalette PTR, paletteBuffer)
paletteptr->Flags = 0
paletteptr->Count = 256
FOR i AS LONG = 0 To 255
  paletteptr->Entries(i) = &HFF000000 OR (i SHL 16)  ' Shades of red
NEXT

' // Set the palette
hStatus = GdipSetImagePalette(bmp, paletteptr)
IF hStatus = 0 THEN
   PRINT "Palette set successfully"
ELSE
   PRINT "Failed to set palette. Status = "; hStatus
END IF

' // Cleanup
IF paletteBuffer THEN Deallocate(paletteBuffer)
IF bmp THEN GdipDisposeImage(bmp)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP
```
---
