' ########################################################################################
' Microsoft Windows
' File: GdipEncodeParameters.bas
' Contents: GDI+ Flat API - GdipEncodeParameters example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' ========================================================================================
' Demonstrates how to set the compression and color depth when converting an image
' to the tiff format. The EncoderParameters structure has two members, a dword with
' the number of EncoderParameter structures and an array of EncoderParameter
' structures.
' ========================================================================================

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

' ========================================================================================
