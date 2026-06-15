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
#include once "AfxNova/AfxCOM.inc"
#include once "AfxNova/CWinHttpRequest.inc"
#include once "AfxNova/CWinHttpRequestEvents.inc"
using AfxNova

' ########################################################################################
' CWinHttpRequestEventsImpl class
' Implementation of the IWinHttpRequestEvents callback interface
' ########################################################################################

TYPE CWinHttpRequestEventsImpl EXTENDS CWinHttpRequestEvents

   DECLARE VIRTUAL SUB OnResponseStart (BYVAL Status AS LONG, BYVAL ContentType AS AFX_BSTR)
   DECLARE VIRTUAL SUB OnResponseDataAvailable (BYVAL Data AS SAFEARRAY PTR)
   DECLARE VIRTUAL SUB OnResponseFinished ()
   DECLARE VIRTUAL SUB OnError (BYVAL ErrorNumber AS LONG, BYVAL ErrorDescription AS AFX_BSTR)

END TYPE
' ########################################################################################

SUB CWinHttpRequestEventsImpl.OnResponseStart (BYVAL Status AS LONG, BYVAL ContentType AS AFX_BSTR)
   OutputDebugStringW("CWinHttpRequestEventsImpl.OnResponseStart")
END SUB
SUB CWinHttpRequestEventsImpl.OnResponseDataAvailable (BYVAL pData AS SAFEARRAY PTR)
   OutputDebugStringW("CWinHttpRequestEventsImpl.OnResponseDataAvailable")
END SUB
SUB CWinHttpRequestEventsImpl.OnResponseFinished
   OutputDebugStringW("CWinHttpRequestEventsImpl.OnResponseFinished")
END SUB
SUB CWinHttpRequestEventsImpl.OnError (BYVAL ErrorNumber AS LONG, BYVAL ErrorDescription AS AFX_BSTR)
   OutputDebugStringW("CWinHttpRequestEventsImpl.OnError")
END SUB

' ########################################################################################

' // Create an instance of the CWinHttpRequest class
DIM pWHttp AS CWinHttpRequest
' // Set the events sink
DIM pEvtSink AS ANY PTR = NEW CWinHttpRequestEventsImpl
pWHttp.SetEvents(pEvtSink)

' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Send an HTTP request to the HTTP server
pWHttp.Send
' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)
' // Get the response headers
DIM dwsResponseHeaders AS DWSTRING = pWHttp.GetAllResponseHeaders
PRINT dwsResponseHeaders

PRINT
PRINT "Press any key..."
SLEEP
