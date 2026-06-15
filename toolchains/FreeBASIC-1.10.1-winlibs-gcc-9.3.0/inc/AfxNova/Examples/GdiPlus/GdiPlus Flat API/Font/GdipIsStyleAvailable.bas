' ########################################################################################
' Microsoft Windows
' File: GdipIsStyleAvailable.bas
' Contents: GDI+ Flat API - GdipIsStyleAvailable example
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
' This example checks whether a specific font style (like bold, italic, underline, etc.)
' is available for a given GpFontFamily. It’s especially useful when working with third-party
' or custom fonts that may not support all style variants.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create a font family
DIM fontFamily AS GpFontFamily PTR
hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)

' // Check if italic style is available
DIM isAvailable AS BOOL
hStatus = GdipIsStyleAvailable(fontFamily, FontStyleItalic, @isAvailable)

IF isAvailable THEN
  PRINT "Italic style is available for Arial."
ELSE
  PRINT "Italic style is NOT available for Arial."
END IF

' // Cleanup
IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
