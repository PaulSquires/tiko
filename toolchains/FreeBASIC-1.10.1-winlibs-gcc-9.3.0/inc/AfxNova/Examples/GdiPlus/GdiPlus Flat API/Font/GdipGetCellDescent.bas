' ########################################################################################
' Microsoft Windows
' File: GdipGetCellDescent.bas
' Contents: GDI+ Flat API - GdipGetCellDescent example
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
' This example gets the cell descent of a font family in design units.
' Then combines cell ascent, cell descent, and line spacing to calculate the total line
' height in pixels for a font
' This is crucial for custom layout engines, text editors, or precise UI rendering.
' ascentPixels + descentPixels gives you the actual height of glyphs.
' spacingPixels gives you the recommended line height for consistent vertical spacing.
' ========================================================================================
DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create the font family
DIM fontFamily AS GpFontFamily PTR
hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)

' // Font style and size
DIM style AS LONG = FontStyleRegular
DIM fontSize AS SINGLE = 16.0

' // Get metrics in design units
DIM ascent AS UINT16, descent AS UINT16, spacing AS UINT16, emHeight AS UINT16
GdipGetCellAscent(fontFamily, style, @ascent)
GdipGetCellDescent(fontFamily, style, @descent)
GdipGetLineSpacing(fontFamily, style, @spacing)
GdipGetEmHeight(fontFamily, style, @emHeight)

' // Convert to pixels
DIM ascentPixels AS SINGLE = (fontSize * ascent) / emHeight
DIM descentPixels AS SINGLE = (fontSize * descent) / emHeight
DIM spacingPixels AS SINGLE = (fontSize * spacing) / emHeight

' // Display results
PRINT "Ascent (px): "; ascentPixels
PRINT "Descent (px): "; descentPixels
PRINT "Line spacing (px): "; spacingPixels

' // Cleanup
IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
