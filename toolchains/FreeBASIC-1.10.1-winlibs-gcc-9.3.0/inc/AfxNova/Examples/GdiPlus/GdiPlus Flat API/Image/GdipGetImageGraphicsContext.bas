' ########################################################################################
' Microsoft Windows
' File: GdipGetImageGraphicsContext.bas
' Contents: GDI+ Flat API - GdipGetImageGraphicsContext example
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
' The following example draws on a Bitmap using GdipGetImageGraphicsContext.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create a bitmap to draw on
DIM bmp AS GpBitmap PTR
hStatus = GdipCreateBitmapFromFile("climber.jpg", @bmp)

' // Get a graphics context tied to the bitmap
DIM graphics AS GpGraphics PTR
hStatus = GdipGetImageGraphicsContext(CAST(GpImage PTR, bmp), @graphics)

' // Set smoothing mode for better quality
hStatus = GdipSetSmoothingMode(graphics, SmoothingModeAntiAlias)

' // Create a red brush
DIM brush AS GpSolidFill PTR
hStatus = GdipCreateSolidFill(&HFFFF0000, @brush)  ' ARGB: opaque red

' // Draw a filled ellipse onto the bitmap
hStatus = GdipFillEllipse(graphics, brush, 50, 50, 100, 60)

' // Save the modified bitmap to a new file
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")
hStatus = GdipSaveImageToFile(CAST(GpImage PTR, bmp), "modified.jpg", @clsid, NULL)

IF hStatus = S_OK THEN PRINT "File saved" ELSE PRINT "Failure"

' // Cleanup
IF brush THEN GdipDeleteBrush(brush)
IF graphics THEN GdipDeleteGraphics(graphics)
IF bmp THEN GdipDisposeImage(CAST(GpImage PTR, bmp))

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP


' ========================================================================================
