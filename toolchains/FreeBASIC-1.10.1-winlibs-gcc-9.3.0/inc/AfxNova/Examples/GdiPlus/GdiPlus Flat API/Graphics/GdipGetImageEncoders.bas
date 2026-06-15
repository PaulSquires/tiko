' ########################################################################################
' Microsoft Windows
' File: GdipGetImageEncoders.bas
' Contents: GDI+ Flat API - GdipGetImageEncoders example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' Lists Available Image Encoders

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG
DIM numEncoders AS UINT
DIM size AS UINT

' // Get size and count of decoders
hStatus = GdipGetImageEncodersSize(@numEncoders, @size)
IF hStatus <> 0 OR size = 0 THEN
   PRINT "Failed to get decoder size: "; hStatus
   END
END IF

' // Allocate memory for encoder array
DIM encoders AS ImageCodecInfo PTR
encoders = CAllocate(size)

' // Get encoder info
hStatus = GdipGetImageEncoders(numEncoders, size, encoders)
IF hStatus <> 0 THEN
   PRINT "Failed to get image encoders: "; hStatus
   Deallocate(encoders)
   END
END IF

' // Print encoder details
FOR i AS LONG = 0 TO numEncoders - 1
   DIM codec AS ImageCodecInfo PTR = encoders + i
   PRINT "Format: "; *codec->FormatDescription
   PRINT "MimeType: "; *codec->MimeType
   PRINT "DLL: "; *codec->DllName
   PRINT "Filename Extension: "; *codec->FilenameExtension
   PRINT "--------------------------------"
NEXT

' // Cleanup
Deallocate((encoders))

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
