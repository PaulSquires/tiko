' ########################################################################################
' Microsoft Windows
' File: GdipGetMetafileHeaderFromFile.bas
' Contents: GDI+ Flat API - GdipGetMetafileHeaderFromFile example
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
' Using GdipGetMetafileHeaderFromFile to Inspect a Metafile.
' What You Can Learn from the Header
' Type: Indicates if it’s EMF, EMF+, or EMF+ Dual.
' DpiX / DpiY: Resolution of the metafile.
' Bounds: Logical drawing area.
' Version: GDI+ version used to create the metafile.
' Size: Total size of the header structure.
' This function is especially useful for preflight checks before attempting to render or
' convert metafiles.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Specify the metafile path
DIM filename AS WSTRING * 64 = "SampleMetafile.emf"

' // Retrieve the header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromFile(@filename, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header: " & STR(hStatus)
   END
END IF

' // Display some header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)
PRINT "Bounds: (" & header.X & ", " & header.Y & ", " & header.Width & ", " & header.Height & ")"

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
