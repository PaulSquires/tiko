' ########################################################################################
' Microsoft Windows
' File: GdipGetEmHeight.bas
' Contents: GDI+ Flat API - GdipGetEmHeight example
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
' This example gets the em height of a font family for a given style. This value is
' expressed in design units, and it's crucial for converting other font metrics (like
' ascent, descent, and line spacing) into pixel values.
' For example, if the em height is 2048 and the ascent is 1638, then:
' ascentPixels = (fontSize * 1638) / 2048
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create the font family
DIM fontFamily AS GpFontFamily PTR
hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)

' // Get em height for regular style
DIM emHeight AS UINT16
hStatus = GdipGetEmHeight(fontFamily, FontStyleRegular, @emHeight)

' // Display result
PRINT "Em Height (design units): "; emHeight

' // Cleanup
IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
