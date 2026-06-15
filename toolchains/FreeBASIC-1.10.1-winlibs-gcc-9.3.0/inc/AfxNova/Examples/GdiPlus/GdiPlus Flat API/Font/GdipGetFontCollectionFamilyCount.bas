' ########################################################################################
' Microsoft Windows
' File: GdipGetFontCollectionFamilyCount.bas
' Contents: GDI+ Flat API - GdipGetFontCollectionFamilyCount example
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
' Gets the number of font families installed.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create an InstalledFontCollection object
DIM fontCollection AS GpFontCollection PTR
hStatus = GdipNewInstalledFontCollection(@fontCollection)

' // Get the number of font families in the collection
DIM numberFonts AS LONG
hStatus = GdipGetFontCollectionFamilyCount(fontCollection, @numberFonts)

' // Display the result (for example, in console)
PRINT "Number of installed font families: "; numberFonts

' // Buffer for font name
DIM wszName AS WSTRING * 32

' // Allocate array for font family pointers
DIM families(numberFonts - 1) AS GpFontFamily PTR
hStatus = GdipGetFontCollectionFamilyList(fontCollection, numberFonts, @families(0), @numberFonts)
    
' // Print each font family name
FOR i AS LONG = 0 TO numberFonts - 1
   hStatus = GdipGetFamilyName(families(i), @wszName, LANG_NEUTRAL)
   PRINT "Font "; i + 1; ": "; wszName
   GdipDeleteFontFamily(families(i))
NEXT

' // Cleanup
' No delete function exists for installed font collections
' //because it is a shared collection; cleanup is automatic”

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
