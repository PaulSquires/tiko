' ########################################################################################
' Microsoft Windows
' File: Gdip_GetEmHeight.bas
' Contents: GDI+ Flat API - GdipGetEmHeight example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
'#define _GDIP_DEBUG_ 1
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdipObjects.inc"
USING AfxNova

' ========================================================================================
' This example gets the em height of a font family for a given style. This value is
' expressed in design units, and it's crucial for converting other font metrics (like
' ascent, descent, and line spacing) into pixel values.
' For example, if the em height is 2048 and the ascent is 1638, then:
' ascentPixels = (fontSize * 1638) / 2048
' ========================================================================================

DIM status AS LONG

' // Create the font family
DIM fontFamily AS GdiPlusFontFamily PTR = NEW GdiPlusFontFamily("Arial")

' // Get em height for regular style
DIM emHeight AS UINT16
status = GdipGetEmHeight(**fontFamily, FontStyleRegular, @emHeight)

' // Display result
PRINT "Em Height (design units): "; emHeight

' // Cleanup
IF fontFamily THEN Delete(fontFamily)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
