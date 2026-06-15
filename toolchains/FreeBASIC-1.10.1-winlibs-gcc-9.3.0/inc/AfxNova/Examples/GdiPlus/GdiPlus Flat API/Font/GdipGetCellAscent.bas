' ########################################################################################
' Microsoft Windows
' File: GdipGetCellAscent.bas
' Contents: GDI+ Flat API - GdipGetCellAscent example
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
' This example gets the cell ascent of a font family in design units, which is essential
' for calculating vertical text metrics like baseline alignment and line spacing.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create the font family
DIM fontFamily AS GpFontFamily PTR
hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)

' // Get the cell ascent for regular style
DIM ascent AS UINT16
hStatus = GdipGetCellAscent(fontFamily, FontStyleRegular, @ascent)

' // Display result
PRINT "Cell Ascent (design units): "; ascent

' // Cleanup
IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
