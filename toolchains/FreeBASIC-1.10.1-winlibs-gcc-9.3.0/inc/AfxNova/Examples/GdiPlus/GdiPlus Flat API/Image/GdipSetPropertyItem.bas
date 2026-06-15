' ########################################################################################
' Microsoft Windows
' File: GdipSetPropertyItem.bas
' Contents: GDI+ Flat API - GdipSetPropertyItem example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' The following console application creates a Image object based on a JPEG file.
' The code calls the GdipSetPropertyItem function of that Image object to set the title
' of the image.

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("BERRY_Halle_01.jpg", @image)   ' --> change me

 ' // Set new title
 DIM titleText AS STRING = "Halle Berry"
 DIM prop As PropertyItem
 prop.id = PropertyTagImageTitle
 prop.length = LEN(titleText) + 1  ' Include null terminator
 prop.type = PropertyTagTypeASCII
 prop.value = STRPTR(titleText)

 IF GdipSetPropertyItem(image, @prop) = 0 Then
   PRINT "Title set successfully"
ELSE
   PRINT "Failed to set title"
 END IF

' // Save the modified file
AfxGdipSaveImageToJpeg(image, "modified.jpg")

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
