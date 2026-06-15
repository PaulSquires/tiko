' ########################################################################################
' Microsoft Windows
' File: ImageGetHorizontalResolution.bas
' Contents: GDI+ Flat API - ImageGetHorizontalResolution example
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
' The following example retrieves the horizontal resolution, in dots per inch, of an image.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "climber.jpg"

' // Get the width of the image
DIM resolution AS SINGLE = image.GetHorizontalResolution
PRINT "The horizontal resolution is " & STR(resolution) & " dots per inch"

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
