' ########################################################################################
' Microsoft Windows
' File: ImageSaveAdd.bas
' Contents: GDI+ Flat API - ImageSaveAdd example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CGdiPlus.inc"
USING AfxNova

' ========================================================================================
' Creating and Saving a Multiple-Frame Image
'
' With certain file formats, you can save multiple images (frames) to a single file. For
' example, you can save several pages to a single TIFF file. To save the first page, call
' the the Save method. To save subsequent pages, call the SaveAdd method.
' The following console application creates a TIFF file with three pages. The images that
' become the pages of the TIFF file come from three disk files. The code first constructs
' three Image objects: multi, page2 and page3. As the individual pages are added to the
' multiImage object, they are also added to the disk file Multiframe.tiff.
' Note that the code calls the Save method (not SaveAdd) to save the first page.
' ========================================================================================

DIM hStatus AS LONG

' // Create three image objects.
DIM multi AS CGpImage = "Shapes.bmp"
DIM page2 AS CGpImage = "Iron.jpg"
DIM page3 AS CGpImage = "House.png"

' // Get TIFF encoder CLSID
DIM clsid As CLSID = AfxGdipGetEncoderClsid("image/tiff")

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
multi.Save("multiframe.tiff", @clsid, @encoderParams)

' // Add second frame
paramValue = EncoderValueFrameDimensionPage
multi.SaveAdd(@page2, @encoderParams)

' // Add third frame
paramValue = EncoderValueFrameDimensionPage
multi.SaveAdd(@page3, @encoderParams)

' // Finalize file
paramValue = EncoderValueFlush
hStatus = multi.SaveAdd(@encoderParams)

IF hStatus = StatusOk THEN PRINT "File saved" ELSE PRINT "Saving failed"

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
