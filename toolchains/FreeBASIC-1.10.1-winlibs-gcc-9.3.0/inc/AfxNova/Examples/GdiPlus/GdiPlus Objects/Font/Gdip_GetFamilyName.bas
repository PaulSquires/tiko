' ########################################################################################
' Microsoft Windows
' File: Gdip_GetFamilyName.bas
' Contents: GDI+ Flat API - GdipGetFamilyName example
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
' This example gets the font family name. The name returned is typically the canonical
' name like "Arial", "Times New Roman", etc. This is handy when listing fonts from a
' collection or verifying font availability.
' ========================================================================================

DIM status AS LONG

' // Create the font family
DIM fontFamily AS GdiPlusFontFamily PTR = NEW GdiPlusFontFamily("Arial")

' // Get the name of the font family
DIM wszName AS WSTRING * LF_FACESIZE
status = GdipGetFamilyName(**fontFamily, @wszName, LANG_NEUTRAL)

' Display result
PRINT "Font family name: "; wszName

' // Cleanup
IF fontFamily THEN Delete(fontFamily)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
