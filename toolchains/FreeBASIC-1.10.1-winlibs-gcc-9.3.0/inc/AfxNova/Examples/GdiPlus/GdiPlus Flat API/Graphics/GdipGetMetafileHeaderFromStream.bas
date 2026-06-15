' ########################################################################################
' Microsoft Windows
' File: GdipGetMetafileHeaderFromStream.bas
' Contents: GDI+ Flat API - GdipGetMetafileHeaderFromStream example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "Windows.bi"
#INCLUDE ONCE "win/shlwapi.bi"
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' ========================================================================================
' Inspecting a Metafile Header from a Stream.
' Works with metafiles stored in memory, embedded resources, or custom containers.
' Lets you validate format and compatibility before playback.
' Avoids loading the full GpMetafile object if you just need metadata.
' ========================================================================================

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG

' // Create IStream from file
DIM stream AS IStream PTR
DIM hr AS HRESULT = SHCreateStreamOnFile("SampleMetafile.emf", STGM_READ, @stream)
IF hr <> S_OK OR stream = NULL THEN
   PRINT "Failed to create stream from file. HRESULT = " & HEX(hr)
   END
END IF

' // Retrieve the header
DIM header AS MetafileHeader
hStatus = GdipGetMetafileHeaderFromStream(stream, @header)
IF hStatus <> 0 THEN
   PRINT "Failed to get metafile header from stream: " & STR(hStatus)
   stream->lpvtbl->Release(stream)
   END
END IF

' // Display header info
PRINT "Type: " & STR(header.Type)
PRINT "Version: " & HEX(header.Version)
PRINT "Size: " & STR(header.Size) & " bytes"
PRINT "DPI: " & STR(header.DpiX) & " x " & STR(header.DpiY)
PRINT "Bounds: (" & header.X & ", " & header.Y & ", " & header.Width & ", " & header.Height & ")"

' // Cleanup
stream->lpvtbl->Release(stream)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
