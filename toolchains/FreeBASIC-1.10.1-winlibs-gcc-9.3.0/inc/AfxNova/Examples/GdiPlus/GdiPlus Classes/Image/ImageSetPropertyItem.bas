' ########################################################################################
' Microsoft Windows
' File: ImageSetPropertyItem.bas
' Contents: GDI+ Flat API - ImageSetPropertyItem example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CGdiPlus.inc"
USING AfxNova

' ========================================================================================
' The following console application creates a Image object based on a JPEG file.
' The code calls the SetPropertyItem method of that Image object to set the title
' of the image.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "BERRY_Halle_01.jpg"

' // Set new title
DIM titleText AS STRING = "Halle Berry"
DIM prop As PropertyItem
prop.id = PropertyTagImageTitle
prop.length = LEN(titleText) + 1  ' Include null terminator
prop.type = PropertyTagTypeASCII
prop.value = STRPTR(titleText)

IF image.SetPropertyItem(@prop) = StatusOk THEN
   PRINT "Title set successfully"
ELSE
   PRINT "Failed to set title"
 END IF

' // Get the encoder GUID for the .jpg image type
DIM clsidEncoder AS GUID = AfxGdipGetEncoderClsid("image/jpeg")
' // Save the file with another name
IF image.Save("modified.jpg", @clsidEncoder, NULL) = StatusOk THEN
   PRINT "File saved"
ELSE
   PRINT "Failed to save the file"
END IF

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
