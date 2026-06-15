' ########################################################################################
' Microsoft Windows
' File: ImageGetFlags.bas
' Contents: GDI+ Flat API - ImageGetFlags example
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
' The following example retrieves the flags of an image.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "climber.jpg"

' // Get the image flags
DIM flags AS UINT = image.GetFlags
PRINT "Image flags &h" & HEX(flags)

' // Interpret the flags
IF (flags AND ImageFlagsHasAlpha) THEN PRINT "Has Alpha Channel"
IF (flags AND ImageFlagsHasRealDPI) THEN PRINT "Has real DPI"
' ... etc.

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
