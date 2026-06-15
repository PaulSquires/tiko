' ########################################################################################
' Microsoft Windows
' File: GdipFindFirstImageItem.bas
' Contents: GDI+ Flat API - GdipFindFirstImageItem example
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

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("sample.jpg", @image)   ' --> change me

' // JPEG requires 1-byte description buffer
DIM descBuffer(0) AS BYTE
DIM itemData AS ImageItemData
itemData.Desc = @descBuffer(0)
itemData.DescSize = 1
itemData.DataSize = 0

' // Try to find first metadata item
hStatus = GdipFindFirstImageItem(image, @itemData)
IF hStatus <> 0 THEN
  PRINT "No custom metadata items found in JPEG"
ELSE
  DIM itemCount AS LONG = 1
  DO
      PRINT "Metadata Item "; itemCount
      PRINT "  DescSize: "; itemData.DescSize
      PRINT "  DataSize: "; itemData.DataSize
      PRINT "  Desc Byte: "; descBuffer(0)
      PRINT "-----------------------------"
      itemCount += 1
      hStatus = GdipFindNextImageItem(image, @itemData)
  LOOP WHILE hStatus = 0
END IF

' // Cleanup
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
