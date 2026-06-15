' ########################################################################################
' Microsoft Windows
' File: ImageGetFrameDimensionsCount.bas
' Contents: GDI+ Flat API - ImageGetFrameDimensionsCount example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CGdiPlus.inc"
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
USING AfxNova

' ========================================================================================
' Gets the number of frame dimensions in the image object and the identifier of the frame.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "MultiFrame.tiff"

' // How many frame dimensions does the Image object have?
DIM nCount AS UINT = image.GetFrameDimensionsCount
PRINT "The number of dimensions is " & STR(nCount)

' // Get the list of frame dimensions from the Image object.
DIM rgDimensionIDs(nCount - 1) AS GUID
image.GetFrameDimensionsList(@rgDimensionIDs(0), nCount)

' // Display the GUID of the first (and only) frame dimension.
DIM strGuid AS STRING = AfxGuidText(rgDimensionIDs(0))
'   strGuid = AfxGuidText(rgDimensionIDs(0))
PRINT "The first (and only) dimension ID is " & strGuid

' // Get the number of frames in the first dimension.
DIM frameCount AS UINT = image.GetFrameCount(@rgDimensionIDs(0))
PRINT "The number of frames in that dimension is " & STR(frameCount)

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
