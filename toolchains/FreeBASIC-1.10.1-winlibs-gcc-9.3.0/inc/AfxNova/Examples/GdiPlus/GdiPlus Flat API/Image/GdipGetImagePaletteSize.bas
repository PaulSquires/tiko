' ########################################################################################
' Microsoft Windows
' File: GdipGetImagePaletteSize.bas
' Contents: GDI+ Flat API - GdipGetImagePaletteSize example
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
' The following example creates an Image object based on a BMP file. The image in that file
' uses 8 bits per pixel. The code calls the GdipGetImagePaletteSize function to determine
' the size of the image's palette.
' ========================================================================================

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

' ========================================================================================
