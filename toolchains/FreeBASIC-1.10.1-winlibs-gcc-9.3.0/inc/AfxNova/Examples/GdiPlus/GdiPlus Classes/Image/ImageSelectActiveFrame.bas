' ########################################################################################
' Microsoft Windows
' File: ImageSelectActiveFrame.bas
' Contents: GDI+ Flat API - ImageSelectActiveFrame example
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
' The following example retrieves the individual frames from a multiple-frame TIFF file.
' The code constructs an Image object from the multiple-frame TIFF file. To retrieve the
' individual frames (pages), the code calls the SelectActiveFrame method.
' The first argument passed to the SelectActiveFrame method is the address of a globally
' unique identifier (GUID) that specifies the dimension in which the frames were previously
' added to the multiple-frame TIFF file. The second argument is the zero-based index of
' the desired page.
' ========================================================================================

DIM hStatus AS LONG

' // Load the original image from file
DIM image AS CGpImage = "MultiFrame.tiff"

' // Get the CLSID of the PNG encoder.
DIM EncoderClsid AS GUID = AfxGdipGetEncoderClsid("image/png")

' // Save the first page (index 0).
hStatus = image.SelectActiveFrame(@FrameDimensionPage, 0)
DIM wszFileName AS WSTRING * 260 = "Page0.png"
hStatus = image.Save(@wszFileName, @EncoderClsid, NULL)
IF hStatus = S_OK THEN PRINT "Page 0 saved successfully"

' // Save the second page (index 1).
hStatus = image.SelectActiveFrame(@FrameDimensionPage, 1)
wszFileName = "Page1.png"
hStatus = image.Save(@wszFileName, @EncoderClsid, NULL)
IF hStatus = S_OK THEN PRINT "Page 1 saved successfully"

' // Save the second page (index 2).
hStatus = image.SelectActiveFrame(@FrameDimensionPage, 2)
wszFileName = "Page2.png"
hStatus = image.Save(@wszFileName, @EncoderClsid, NULL)
IF hStatus = S_OK THEN PRINT "Page 2 saved successfully"

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
