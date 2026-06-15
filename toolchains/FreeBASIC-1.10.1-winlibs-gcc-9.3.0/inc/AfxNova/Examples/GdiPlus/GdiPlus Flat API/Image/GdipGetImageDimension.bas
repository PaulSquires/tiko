' ########################################################################################
' Microsoft Windows
' File: GdipGetImageDimension.bas
' Contents: GDI+ Flat API - GdipGetImageDimension example
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
' The following example retrieves the width and height, in pixels, of an image.
' ========================================================================================

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

' ========================================================================================
