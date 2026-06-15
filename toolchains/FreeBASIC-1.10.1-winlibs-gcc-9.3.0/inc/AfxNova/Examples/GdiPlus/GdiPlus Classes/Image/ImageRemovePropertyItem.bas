' ########################################################################################
' Microsoft Windows
' File: ImageRemovePropertyItem.bas
' Contents: GDI+ Flat API - ImageRemovePropertyItem example
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
' Removes a property item (piece of metadata) from an Image object.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "BERRY_Halle_01.jpg"

' // Get the size of the property
DIM size AS UINT = image.GetPropertyItemSize(PropertyTagImageTitle)
PRINT "Before removal, title size = "; size; " bytes"

' // Remove the property
image.RemovePropertyItem(PropertyTagImageTitle)

' // Get the size again
size = 0
size = image.GetPropertyItemSize(PropertyTagImageTitle)
PRINT "After removal, title size = "; size; " bytes"

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
