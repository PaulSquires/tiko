' ########################################################################################
' Microsoft Windows
' File: GdipGetPropertySize.bas
' Contents: GDI+ Flat API - GdipGetPropertySize example
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
' Gets the total size, in bytes, of all the property items stored in an Image object.
' It also gets the number of property items stored in the Image object.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("BERRY_Halle_01.jpg", @image)

DIM AS UINT totalBufferSize, numProperties
hStatus = GdipGetPropertySize(image, @totalBufferSize, @numProperties)
IF hStatus = StatusOK THEN
   print "Total buffer size: " & WSTR(totalBufferSize)
   print "Number of properties: " & WSTR(numProperties)
END IF

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
