' ########################################################################################
' Microsoft Windows
' File: Gdip_GetFontCollectionFamilyCount.bas
' Contents: GDI+ Flat API - GdipGetFontCollectionFamilyCount example
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
' Gets the number of font families installed.
' ========================================================================================

DIM status AS LONG

' // Initialize GDI+
DIM pObjs AS GdiPlusObjects

' // Create an InstalledFontCollection object
DIM fontCollection AS GpFontCollection PTR
status = GdipNewInstalledFontCollection(@fontCollection)

' // Get the number of font families in the collection
DIM numberFonts AS LONG
status = GdipGetFontCollectionFamilyCount(fontCollection, @numberFonts)

' // Display the result (for example, in console)
PRINT "Number of installed font families: "; numberFonts

' // Buffer for font name
DIM wszName AS WSTRING * 32

' // Allocate array for font family pointers
DIM families(numberFonts - 1) AS GpFontFamily PTR
status = GdipGetFontCollectionFamilyList(fontCollection, numberFonts, @families(0), @numberFonts)
    
' // Print each font family name
FOR i AS LONG = 0 TO numberFonts - 1
   status = GdipGetFamilyName(families(i), @wszName, LANG_NEUTRAL)
   PRINT "Font "; i + 1; ": "; wszName
   GdipDeleteFontFamily(families(i))
NEXT

' // Cleanup
' No delete function exists for installed font collections
' //because it is a shared collection; cleanup is automatic”

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
