' ########################################################################################
' Microsoft Windows
' File: ImageGetPhysicalDimension.bas
' Contents: GDI+ Flat API - ImageGetPhysicalDimension example
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
' The following example retrieves the width and height of an image.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "climber.jpg"

' // Get the width and height of the image
DIM sizef AS GpSizeF = image.GetPhysicalDimension
PRINT "Image width: " & WSTR(sizef.Width)
PRINT "Image height: " & WSTR(sizef.Height)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
