' ########################################################################################
' Microsoft Windows
' File: GdipGetFamilyName.bas
' Contents: GDI+ Flat API - GdipGetFamilyName example
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
' This example gets the font family name. The name returned is typically the canonical
' name like "Arial", "Times New Roman", etc. This is handy when listing fonts from a
' collection or verifying font availability.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create the font family
DIM fontFamily AS GpFontFamily PTR
hStatus = GdipCreateFontFamilyFromName("Arial", NULL, @fontFamily)

' // Get the name of the font family
DIM wszName AS WSTRING * LF_FACESIZE
hStatus = GdipGetFamilyName(fontFamily, @wszName, LANG_NEUTRAL)

' Display result
PRINT "Font family name: "; wszName

' // Cleanup
IF fontFamily THEN GdipDeleteFontFamily(fontFamily)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
