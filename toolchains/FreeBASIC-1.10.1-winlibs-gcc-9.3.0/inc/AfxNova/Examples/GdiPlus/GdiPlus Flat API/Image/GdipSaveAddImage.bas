' ########################################################################################
' Microsoft Windows
' File: GdipSaveAddImage.bas
' Contents: GDI+ Flat API - GdipSaveAddImage example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' ========================================================================================
' Creating and Saving a Multiple-Frame Image
'
' With certain file formats, you can save multiple images (frames) to a single file. For
' example, you can save several pages to a single TIFF file. To save the first page, call
' the GdipSaveImageToFile function. To save subsequent pages, call the GdipSaveAddImage
' function.
' The following console application creates a TIFF file with three pages. The images that
' become the pages of the TIFF file come from three disk files. The code first constructs
' three Image objects: multi, page2 and page3. As the individual pages are added to the
' multiImage object, they are also added to the disk file Multiframe.tif.
' Note that the code calls GdipSaveImageToFile (not GdipSaveAddImage) to save the first
' page. The second argument passed to the GdipSaveImageToFile function is the name of the
' disk file that will eventually contain several frames. The third argument passed to the
' GdipSaveImageToFile function specifies the encoder that will be used to convert the data
' in the multiImage object to the format (in this case TIFF) required by the disk file.
' That same encoder is used automatically by all subsequent calls to the GdipSaveAddImage
' function of the multiImage object.
' The fourth argument passed to the GdipSaveImageToFile function is the address of an
' EncoderParameters structure The EncoderParameters structure has an array that contains
' a single EncoderParameter structure. The Guid member of that EncoderParameter structure
' is set to EncoderSaveFlag. The Value member of the EncoderParameter structure points to
' an ULONG variable that contains the value EncoderValueMultiFrame.
' The code saves the second and third pages by calling the GdipSaveAddImage function.
' The first argument passed to the GdipSaveAddImage function is the address of the multi
' object. The second argument is the address of an Image object. The image in that Image
' object is added to the multiImage object and is also added to the Multiframe.tif disk
' file. The third argument passed to the GdipSaveAddImage function is the address of the
' same EncoderParameters structure that was used by the GdipSaveImageToFile function. The
' difference is that the ULONG pointed to by the Value member now contains the value
' EncoderValueFrameDimensionPage. Finally, the file is closed calling the GdipSaveAdd
' function with the Value member of the EncoderParameter structure pointing to a ULONG
' variable that contains the value EncoderValueFlush.
' The main function relies on the helper function GdiPlusGetEncoderClsid to retrieve the
' guid of the TIFF encoder.
' ========================================================================================

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

' ========================================================================================
