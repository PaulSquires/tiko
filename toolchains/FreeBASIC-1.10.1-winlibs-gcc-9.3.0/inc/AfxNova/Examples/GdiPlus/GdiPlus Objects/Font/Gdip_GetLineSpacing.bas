' ########################################################################################
' Microsoft Windows
' File: Gdip_GetLineSpacing.bas
' Contents: GDI+ Flat API - GdipGetLineSpacing example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
'#define _GDIP_DEBUG_ 1
#INCLUDE ONCE "AfxNova/AfxGdipObjects.inc"
USING AfxNova

' ========================================================================================
' This example retrieves the recommended vertical distancebetween baselines of consecutive
' lines of text for a given font family and style. This value is returned in design units,
' and it's essential for calculating consistent line heights in custom text layouts.
' It includes the cell ascent, cell descent, and any internal leading.
' It defines how much vertical space should be allocated between lines of text.
' It’s not necessarily the sum of ascent and descent—it may include extra spacing for readability.
' ========================================================================================

DIM status AS LONG

' // Create the font family
DIM fontFamily AS GdiPlusFontFamily PTR = NEW GdiPlusFontFamily("Arial")

' // Get line spacing for regular style
DIM spacing AS UINT16
status = GdipGetLineSpacing(**fontFamily, FontStyleRegular, @spacing)

' // Display result
PRINT "Line Spacing (design units): "; spacing

' // Cleanup
IF fontFamily THEN Delete(fontFamily)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
