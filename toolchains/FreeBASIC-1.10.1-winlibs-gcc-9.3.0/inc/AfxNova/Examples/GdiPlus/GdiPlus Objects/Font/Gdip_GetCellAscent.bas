' ########################################################################################
' Microsoft Windows
' File: Gdip_GetCellAscent.bas
' Contents: GDI+ Flat API - GdipGetCellAscent example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _GDIP_DEBUG_ 1
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdipObjects.inc"
USING AfxNova

' ========================================================================================
' This example gets the cell ascent of a font family in design units, which is essential
' for calculating vertical text metrics like baseline alignment and line spacing.
' ========================================================================================

DIM status AS LONG

' // Create the font family
DIM fontFamily AS GdiPlusFontFamily PTR = NEW GdiPlusFontFamily("Arial")

' // Get the cell ascent for regular style
DIM ascent AS UINT16
status = GdipGetCellAscent(**fontFamily, FontStyleRegular, @ascent)

' // Display result
PRINT "Cell Ascent (design units): "; ascent

' // Cleanup
IF fontFamily THEN Delete(fontFamily)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
