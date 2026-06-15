' ########################################################################################
' Microsoft Windows
' File: GdipGetImageRawFormat.bas
' Contents: GDI+ Flat API - GdipGetImageRawFormat example
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
' Gets a globally unique identifier (GUID) that identifies the format of the image.
' ========================================================================================

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

' ========================================================================================
