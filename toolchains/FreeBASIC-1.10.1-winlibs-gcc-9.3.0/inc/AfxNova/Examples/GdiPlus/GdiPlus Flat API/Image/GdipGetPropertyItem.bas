' ########################################################################################
' Microsoft Windows
' File: GdipGetPropertyItem.bas
' Contents: GDI+ Flat API - GdipGetPropertyItem example
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
' Gets a specified property item (piece of metadata) from an image.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get the size of the specified property item.
DIM itemSize AS UINT
hStatus = GdipGetPropertyItemSize(image, PropertyTagLuminanceTable, @itemSize)

' // Allocate buffer and retrieve item
DIM buffer AS UBYTE PTR = Allocate(itemSize)
hStatus = GdipGetPropertyItem(image, PropertyTagLuminanceTable, itemSize, cast(PropertyItem PTR, buffer))
IF hStatus = S_OK Then
   DIM propItem AS PropertyItem PTR = cast(PropertyItem PTR, buffer)
   DIM values AS UBYTE PTR = cast(UBYTE PTR, propItem->value)
   PRINT "Luminance Table ("; propItem->length; " bytes):"
   FOR i AS LONG = 0 TO propItem->length - 1
      PRINT values[i]; " ";
      IF (i + 1) MOD 16 = 0 THEN PRINT
   NEXT
ELSE
   PRINT "Failed to retrieve luminance table"
END IF

' // Cleanup
IF buffer THEN Deallocate buffer
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
