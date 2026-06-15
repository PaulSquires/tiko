' ########################################################################################
' Microsoft Windows
' Contents: CWinHttpRequest - GetResponseText
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CWinHttpRequest.inc"
#include once "AfxNova/DWStrProcs.inc"
using AfxNova

' // Create an instance of the CWinHttp class
DIM pWHttp AS CWinHttpRequest

' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://forum.qbasic.at/viewtopic.php?t=8996"

' // Send an HTTP request to the HTTP server
pWHttp.Send

' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)

IF iSucceeded THEN
   ' // Get the response headers
   DIM dwsResponseText AS DWSTRING = pWHttp.GetResponseText
   ' // Extract the version number from the Color Constants title
   DIM dws AS DWSTRING = DWstrExtract(1, dwsResponseText, "Color Constants v", " [")
   print "Online Color Constants version is v" & dws
END IF

PRINT
PRINT "Press any key..."
SLEEP
