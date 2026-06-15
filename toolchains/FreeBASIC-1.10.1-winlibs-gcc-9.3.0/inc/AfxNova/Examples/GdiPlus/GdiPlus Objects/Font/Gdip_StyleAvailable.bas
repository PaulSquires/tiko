' ########################################################################################
' Microsoft Windows
' File: Gdip_IsStyleAvailable.bas
' Contents: GDI+ Flat API - GdipIsStyleAvailable example
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
' This example checks whether a specific font style (like bold, italic, underline, etc.)
' is available for a given GpFontFamily. It’s especially useful when working with third-party
' or custom fonts that may not support all style variants.
' ========================================================================================

DIM status AS LONG

' // Create the font family
DIM fontFamily AS GdiPlusFontFamily PTR = NEW GdiPlusFontFamily("Arial")

' // Check if italic style is available
DIM isAvailable AS BOOL
status = GdipIsStyleAvailable(**fontFamily, FontStyleItalic, @isAvailable)

IF isAvailable THEN
  PRINT "Italic style is available for Arial."
ELSE
  PRINT "Italic style is NOT available for Arial."
END IF

' // Cleanup
IF fontFamily THEN Delete(fontFamily)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
