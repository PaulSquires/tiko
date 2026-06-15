' ########################################################################################
' Microsoft Windows
' File: GdipSaveImageToStream.bas
' Contents: GDI+ Flat API - GdipSaveImageToStream example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' ========================================================================================
' The following example creates two Image objects: one constructed from a JPEG file and
' one constructed from a PNG file. The code creates a compound file with two streams and
' saves the two images to those streams.
' ========================================================================================

' // Create two image objects.
DIM image1 AS GpImage PTR
DIM image2 AS GpImage PTR
GdipLoadImageFromFile("Iron.jpg", @image1)
GdipLoadImageFromFile("House.png", @image2)

' // Create compound file
DIM storage AS IStorage PTR
DIM compoundFileName AS WSTRING * 260 = "CompoundFile.cmp"
StgCreateDocfile(@compoundFileName, STGM_READWRITE OR STGM_CREATE OR STGM_SHARE_EXCLUSIVE, 0, @storage)

' Create two streams
DIM stream1 AS IStream PTR
DIM stream2 AS IStream PTR
DIM streamName1 AS WSTRING * 260 = "StreamImage1"
DIM streamName2 AS WSTRING * 260 = "StreamImage2"
storage->lpvtbl->CreateStream(storage, @streamName1, STGM_READWRITE Or STGM_SHARE_EXCLUSIVE, 0, 0, @stream1)
storage->lpvtbl->CreateStream(storage, @streamName2, STGM_READWRITE Or STGM_SHARE_EXCLUSIVE, 0, 0, @stream2)

' // Get encoder CLSIDs
DIM jpgClsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")
DIM pngClsid AS CLSID = AfxGdipGetEncoderClsid("image/png")

' // Save images to streams
hStatus = GdipSaveImageToStream(image1, stream1, @jpgClsid, NULL)
hStatus = GdipSaveImageToStream(image2, stream2, @pngClsid, NULL)

PRINT "File saved"

' // Cleanup
IF image1 THEN GdipDisposeImage(image1)
IF image2 THEN GdipDisposeImage(image2)
IF stream1 THEN stream1->lpvtbl->Release(stream1)
IF stream2 THEN stream2->lpvtbl->Release(stream2)
IF storage THEN storage->lpvtbl->Release(storage)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
