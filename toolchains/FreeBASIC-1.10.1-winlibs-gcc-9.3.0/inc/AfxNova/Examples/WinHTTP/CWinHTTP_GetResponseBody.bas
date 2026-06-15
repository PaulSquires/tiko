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
using AfxNova

' // Create an instance of the CWinHttp class
DIM pWHttp AS CWinHttpRequest

' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"

' // Send an HTTP request to the HTTP server
pWHttp.Send

' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)

' // Get the response body
DIM strResponseBody AS STRING = pWHttp.GetResponseBody
PRINT strResponseBody

PRINT
PRINT "Press any key..."
SLEEP
