' ########################################################################################
' Microsoft Windows
' File: GdipGetEncoderParameterListSize.bas
' Contents: GDI+ Flat API - GdipGetEncoderParameterListSize example
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
' Gets the size, in bytes, of the parameter list for a specified image encoder.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("RYDER_Winona_01.jpg", @image)

' // Get the JPEG encoder CLSID
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")

' // Get size of parameter list
DIM listSize AS UINT
hStatus = GdipGetEncoderParameterListSize(image, @clsid, @listSize)
PRINT "Size of parameters list: ", listSize

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
