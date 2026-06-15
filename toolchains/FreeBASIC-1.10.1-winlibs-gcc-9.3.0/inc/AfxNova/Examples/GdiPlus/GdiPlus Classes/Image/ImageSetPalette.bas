' ########################################################################################
' Microsoft Windows
' File: ImageSetPalette.bas
' Contents: GDI+ Flat API - ImageSetPalette example
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
' The SetImagePalette method sets a custom color palette for an image object in GDI+.
' This only applies to indexed pixel formats like 1bpp, 4bpp, or 8bpp images (e.g., GIFs or 8-bit BMPs).
' It replaces the image’s current palette with a new one you define.
' The palette must match the image’s pixel format (e.g., 256 colors for 8bpp).
' Useful for customizing color mapping, reducing color depth, or preparing images
' for formats that require indexed color.
' If you try to use it on a 24-bit or 32-bit image, it won’t work—those formats don’t use palettes.
' ========================================================================================

' Create a bitmap with 8bpp indexed format
DIM nWidth AS LONG = 64
DIM nHeight AS LONG = 64
DIM bmp AS CGpBitmap = CGpBitmap(nWidth, nHeight, 0, PixelFormat8bppIndexed, NULL)
IF bmp.GetLastStatus <> StatusOk THEN PRINT "Failed to create indexed bitmap" : END

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
bmp.SetPalette(paletteptr)
IF bmp.GetLastStatus = StatusOk THEN
   PRINT "Palette set successfully"
ELSE
   PRINT "Failed to set palette. Status = "; bmp.GetLastStatus
END IF

' // Cleanup
IF paletteBuffer THEN Deallocate(paletteBuffer)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
