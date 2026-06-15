' ########################################################################################
' Microsoft Windows
' File: GdipGetMetafileHeaderFromMetaFile.bas
' Contents: GDI+ Flat API - GdipGetMetafileHeaderFromMetaFile example
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
' Inspecting a Metafile Object with GdipGetMetafileHeaderFromMetafile.
' Works with any GpMetafile object—whether recorded or loaded.
' Lets you inspect the metafile after transformations or drawing.
' Ideal for runtime checks, logging, or conditional rendering.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Load a metafile from disk
DIM metafile AS GpMetafile PTR
DIM filename AS WSTRING * 64 = "SampleMetafile.emf"
hStatus = GdipCreateMetafileFromFile(@filename, @metafile)
IF hStatus <> 0 OR metafile = NULL THEN
   PRINT "Failed to load metafile: " & STR(hStatus)
   END
END IF

' // Retrieve the header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromMetafile(metafile, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header: " & STR(hStatus)
   GdipDisposeImage(metafile)
   END
END IF

' // Display header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)
PRINT "Bounds: (" & header.X & ", " & header.Y & ", " & header.Width & ", " & header.Height & ")"

' // Cleanup
GdipDisposeImage(metafile)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
