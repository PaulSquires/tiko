' ########################################################################################
' Microsoft Windows
' File: GdipGetImageDecoders.bas
' Contents: GDI+ Flat API - GdipGetImageDecoders example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' Lists Available Image Decoders

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hStatus AS LONG
DIM numDecoders AS UINT
DIM size AS UINT

' // Get size and count of decoders
hStatus = GdipGetImageDecodersSize(@numDecoders, @size)
IF hStatus <> 0 OR size = 0 THEN
   PRINT "Failed to get decoder size: "; hStatus
   END
END IF

' Allocate memory for decoder array
DIM decoders AS ImageCodecInfo PTR
decoders = CAllocate(size)

' Get decoder info
hStatus = GdipGetImageDecoders(numDecoders, size, decoders)
IF hStatus <> 0 THEN
   PRINT "Failed to get image decoders: "; hStatus
   Deallocate(decoders)
   END
END IF

' Print decoder details
FOR i AS LONG = 0 TO numDecoders - 1
   DIM codec AS ImageCodecInfo PTR = decoders + i
   PRINT "Format: "; *codec->FormatDescription
   PRINT "MimeType: "; *codec->MimeType
   PRINT "DLL: "; *codec->DllName
   PRINT "Filename Extension: "; *codec->FilenameExtension
   PRINT "--------------------------------"
NEXT

' //Cleanup
Deallocate(decoders)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
