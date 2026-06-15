' ########################################################################################
' Microsoft Windows
' File: ImageGetRawFormat.bas
' Contents: GDI+ Flat API - ImageGetRawFormat example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

' ========================================================================================
' Gets a globally unique identifier ( GUID) that identifies the format of an Image object.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "climber.jpg"

' // Get the pixel format
DIM rguid AS GUID = image.GetRawFormat
PRINT "Gud: " & AfxGuidText(rguid)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
