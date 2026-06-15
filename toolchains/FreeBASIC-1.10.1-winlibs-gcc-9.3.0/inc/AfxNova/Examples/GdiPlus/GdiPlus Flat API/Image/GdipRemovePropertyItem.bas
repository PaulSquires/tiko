' ########################################################################################
' Microsoft Windows
' File: GdipRemovePropertyItem.bas
' Contents: GDI+ Flat API - GdipRemovePropertyItem example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("BERRY_Halle_01.jpg", @image)   ' --> change me

' // Check if property exists
DIM size AS UINT
hStatus = GdipGetPropertyItemSize(image, PropertyTagImageTitle, @size)
PRINT "hStatus: ", hStatus
PRINT "Before removal, title size = "; size; " bytes"

' // Remove the property
hStatus = GdipRemovePropertyItem(image, PropertyTagImageTitle)

' // Check again
size = 0
hStatus = GdipGetPropertyItemSize(image, PropertyTagImageTitle, @size)
PRINT "After removal, title size = "; size; " bytes"

' // optional: save the modified image.

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
