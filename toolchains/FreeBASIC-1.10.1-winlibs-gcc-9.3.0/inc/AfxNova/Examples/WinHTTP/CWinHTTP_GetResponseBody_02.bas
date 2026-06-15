' ########################################################################################
' Microsoft Windows
' Contents: CWinHttpRequest - GetResponseBody
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' returns the response body.
' Note: Error checking ommited for brevity.
' ========================================================================================

#cmdline "-s console"
#include once "AfxNova/CWinHttpRequest.inc"
#include once "Afx/CStream.inc"
using AfxNova

' // Create an instance of the CWinHttp class
DIM pWHttp AS CWinHttpRequest

' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "https://learn.microsoft.com/en-us/archive/msdn-magazine/2012/october/images/jj658963.banner.png"

' // Send an HTTP request to the HTTP server
pWHttp.Send

' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)

' // Get the response body as an array of unsigned bytes.
DIM strResponseBody AS STRING = pWHttp.GetResponseBody

' // Open a file stream
DIM pFileStream AS CFileStream
IF pFileStream.Open("image.png", STGM_CREATE OR STGM_WRITE) = S_OK then
   pFileStream.WriteTextA(strResponseBody)
END IF

PRINT
PRINT "Press any key..."
SLEEP
