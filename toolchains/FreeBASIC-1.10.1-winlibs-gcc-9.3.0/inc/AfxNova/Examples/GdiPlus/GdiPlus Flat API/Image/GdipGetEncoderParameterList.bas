' ########################################################################################
' Microsoft Windows
' File: GdipGetEncoderParameterList.bas
' Contents: GDI+ Flat API - GdipGetEncoderParameterList example
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
' Gets a list of the parameters supported by a specified image encoder.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("RYDER_Winona_01.jpg", @image)

' // Get the JPEG encoder CLSID
DIM clsid AS CLSID = AfxGdipGetEncoderClsid("image/jpeg")

' // Get size of parameter list
DIM listSize AS UINT
hStatus = GdipGetEncoderParameterListSize(image, @clsid, @listSize)

' Allocate buffer and retrieve list
DIM buffer As UBYTE Ptr = Allocate(listSize)
hStatus = GdipGetEncoderParameterList(image, @clsid, listSize, cast(EncoderParameters PTR, buffer))
IF hStatus = 0 THEN
   DIM epList AS EncoderParameters PTR = Cast(EncoderParameters PTR, buffer)
   PRINT "Encoder supports "; epList->Count; " parameters:"
   FOR i AS LONG = 0 TO epList->Count - 1
      DIM ep AS EncoderParameter PTR = @epList->Parameter(i)
      PRINT "Parameter "; i
      PRINT "  GUID: "; Hex(ep->Guid.Data1)
      PRINT "  Type: "; ep->Type
      PRINT "  Number of values: "; ep->NumberOfValues
      PRINT "  Value pointer: "; ep->Value
      PRINT "-----------------------------"
   NEXT
ELSE
   PRINT "Failed to retrieve encoder parameter list"
END IF

' // Cleanup
IF buffer THEN Deallocate(buffer)
IF image THEN GdipDisposeImage(image)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
