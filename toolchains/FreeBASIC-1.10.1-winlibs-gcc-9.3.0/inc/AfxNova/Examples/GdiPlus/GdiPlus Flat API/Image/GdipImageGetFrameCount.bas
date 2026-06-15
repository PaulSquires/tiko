' ########################################################################################
' Microsoft Windows
' File: GdipImageGetFrameCount.bas
' Contents: GDI+ Flat API - GdipImageGetFrameCount example
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
' Gets the number of frame dimensions in the image object and the identifier of the frame.
' ========================================================================================

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

' ========================================================================================
