' ########################################################################################
' Microsoft Windows
' File: GdipGetMetafileHeaderFromEmf.bas
' Contents: GDI+ Flat API - GdipGetMetafileHeaderFromEmf example
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
' Inspecting EMF Metadata with GdipGetMetafileHeaderFromEmf.
' Type: Tells you if it’s EMF, EMF+, or EMF+ Dual.
' DpiX / DpiY: Resolution of the metafile.
' Size: Total size in bytes.
' Bounds: Logical drawing bounds.
' EmfPlusFlags: Indicates if GDI+ records are present.
' This is especially useful for validating metafiles before playback or conversion.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Load an EMF file using GDI
DIM hEmf AS HENHMETAFILE
hEmf = GetEnhMetaFile("SampleMetafile.emf")
IF hEmf = 0 THEN
   PRINT "Failed to load EMF file."
   END
END IF

' // Retrieve the metafile header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromEmf(hEmf, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header: " & STR(hStatus)
   DeleteEnhMetaFile(hEmf)
   END
END IF

' // Display some header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)

' // Cleanup
DeleteEnhMetaFile(hEmf)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
