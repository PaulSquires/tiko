' ########################################################################################
' Microsoft Windows
' File: GdipGetImagePalette.bas
' Contents: GDI+ Flat API - GdipGetImagePalette example
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
' uses 8 bits per pixel. The code calls the **GdipGetImagePaletteSize** function to determine
' the size of the image's palette. The call to **Allocate** allocates a buffer large enough
' to receive the palette, and the call to **GdipGetImagePalette** fills that buffer. The code
' displays the number of colors in the palette (*_palette->Count*) and then displays the ARGB
' values of the first five colors in the palette.
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

' ========================================================================================
