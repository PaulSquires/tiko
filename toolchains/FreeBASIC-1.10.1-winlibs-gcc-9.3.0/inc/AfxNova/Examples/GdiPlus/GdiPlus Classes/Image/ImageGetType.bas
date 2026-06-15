' ########################################################################################
' Microsoft Windows
' File: ImageGetType.bas
' Contents: GDI+ Flat API - ImageGetType example
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
' The following example gets the type (bitmap or metafile) of an Image object.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "climber.jpg"

' // Get the type of the image
DIM imageType AS LONG = image.GetType
IF imageType = ImageTypeBitmap THEN PRINT "The type of image is ImageTypeBitmap"

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
