' ########################################################################################
' Microsoft Windows
' File: GdipImageSelectActiveFrame.bas
' Contents: GDI+ Flat API - GdipImageSelectActiveFrame example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

' ========================================================================================
' The following example retrieves the individual frames from a multiple-frame TIFF file.
' The code constructs an Image object from the multiple-frame TIFF file. To retrieve the
' individual frames (pages), the code calls the GdipImageSelectActiveFrame function.
' The first argument passed to the GdipImageSelectActiveFrame function is the address of
' the image. The second argument is the address of a globally unique identifier (GUID) that
' specifies the dimension in which the frames were previously added to the multiple-frame
' TIFF file. The third argument is the zero-based index of the desired page.
' ========================================================================================

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

' ========================================================================================
