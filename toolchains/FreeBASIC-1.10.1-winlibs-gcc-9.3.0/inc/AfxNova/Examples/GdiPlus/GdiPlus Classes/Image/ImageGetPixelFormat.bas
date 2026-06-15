' ########################################################################################
' Microsoft Windows
' File: ImageGetPixelFormat.bas
' Contents: GDI+ Flat API - ImageGetPixelFormat example
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
' This example creates an Image object, gets the pixel format of the Image object and
' compares the obtained value to particular pixel format constants.
' ========================================================================================

' // Create a Bitmap object from a JPEG file.
DIM image AS CGpImage = "climber.jpg"

' // Get the pixel format
DIM fmt AS PixelFormat = image.GetPixelFormat

DIM strFormat AS STRING
SELECT CASE fmt
   CASE PixelFormat1bppIndexed    : strFormat = "1 bpp indexed"
   CASE PixelFormat4bppIndexed    : strFormat = "4 bpp indexed"
   CASE PixelFormat8bppIndexed    : strFormat = "8 bpp indexed"
   CASE PixelFormat16bppGrayScale : strFormat = "16 bpp gray scale"
   CASE PixelFormat16bppRGB555    : strFormat = "16 bpp RGB 555"
   CASE PixelFormat16bppRGB565    : strFormat = "16 bpp RGB 565"
   CASE PixelFormat16bppARGB1555  : strFormat = "16 bpp ARGB 1555"
   CASE PixelFormat24bppRGB       : strFormat = "24 bpp RGB"
   CASE PixelFormat32bppRGB       : strFormat = "32 bpp RGB"
   CASE PixelFormat32bppARGB      : strFormat = "32 bpp ARGB"
   CASE PixelFormat32bppPARGB     : strFormat = "32 bpp PARGB"
   CASE PixelFormat48bppRGB       : strFormat = "48 bpp RGB"
   CASE PixelFormat64bppARGB      : strFormat = "64 bpp ARGB"
   CASE PixelFormat64bppPARGB     : strFormat = "64 bpp PARGB"
   CASE ELSE
      strFormat = STR(fmt)
END SELECT

PRINT "The pixel format of the image is " & strFormat

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
