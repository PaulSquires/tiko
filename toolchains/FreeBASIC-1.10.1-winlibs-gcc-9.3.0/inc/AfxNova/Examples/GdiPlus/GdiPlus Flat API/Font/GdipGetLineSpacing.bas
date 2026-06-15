' ########################################################################################
' Microsoft Windows
' File: GdipGetLineSpacing.bas
' Contents: GDI+ Flat API - GdipGetLineSpacing example
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
' This example retrieves the recommended vertical distancebetween baselines of consecutive
' lines of text for a given font family and style. This value is returned in design units,
' and it's essential for calculating consistent line heights in custom text layouts.
' It includes the cell ascent, cell descent, and any internal leading.
' It defines how much vertical space should be allocated between lines of text.
' It’s not necessarily the sum of ascent and descent—it may include extra spacing for readability.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create a font family
DIM fontFamily AS GpFontFamily PTR
hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)

' // Get line spacing for regular style
DIM spacing AS UINT16
hStatus = GdipGetLineSpacing(fontFamily, FontStyleRegular, @spacing)

' // Display result
PRINT "Line Spacing (design units): "; spacing

' // Cleanup
IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
