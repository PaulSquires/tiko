' ########################################################################################
' Microsoft Windows
' File: GdipImageGetAllPropertyItems.bas
' Contents: GDI+ Flat API - GdipImageGetAllPropertyItems example
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
' The following example creates an Image object based on a JPEG file. The code calls the
' GetAllPropertyItems method of that Image object to obtain its property items (metadata).
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Load the original image from file
DIM image AS GpImage PTR
hStatus = GdipLoadImageFromFile("climber.jpg", @image)

' // Get total buffer size and number of properties
DIM totalSize AS UINT, numProps AS UINT, buffer AS UBYTE PTR
hStatus = GdipGetPropertySize(image, @totalSize, @numProps)
IF hStatus = 0 THEN
   ' // Allocate buffer and retrieve all property items
   buffer = Allocate(totalSize)
   hStatus = GdipGetAllPropertyItems(image, totalSize, numProps, cast(PropertyItem PTR, buffer))
   IF hStatus = 0 THEN
      DIM propItem AS PropertyItem PTR
      FOR i AS LONG = 0 TO numProps - 1
         propItem = cast(PropertyItem PTR, buffer + i * SIZEOF(PropertyItem))
         PRINT "Property ID: &h"; HEX(propItem->id)
         PRINT "Type: "; propItem->type; " Length: "; propItem->length
         SELECT CASE propItem->type
            CASE PropertyTagTypeASCII
               PRINT "Value: "; *cast(ZSTRING PTR, propItem->value)
            CASE PropertyTagTypeByte
               DIM b AS UBYTE PTR = Cast(UBYTE PTR, propItem->value)
               FOR j AS LONG = 0 TO propItem->length - 1
                  PRINT b[j]; " ";
               NEXT
               PRINT
            CASE PropertyTagTypeShort
               DIM s AS USHORT PTR = cast(USHORT PTR, propItem->value)
                  FOR j AS LONG = 0 TO propItem->length \ 2 - 1
                     PRINT s[j]; " ";
                  NEXT
                  PRINT
            CASE PropertyTagTypeLong
               DIM l AS ULONG PTR = cast(ULONG PTR, propItem->value)
               FOR j AS LONG = 0 TO propItem->length \ 4 - 1
                  PRINT l[j]; " ";
               NEXT
               PRINT
            CASE ELSE
               PRINT "Unsupported type"
         END SELECT
         PRINT "---------------------------"
      NEXT
   ELSE
      PRINT "Failed to retrieve property items"
   END IF
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
