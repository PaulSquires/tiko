' ========================================================================================
' The following example shows how to open an HTTP connection, sends an HTTP request to
' load an image, returns the response body as a stream of bytes and saves it to a file.
' ========================================================================================

#cmdline "-s console"
#include once "AfxNova/CWinHttpRequest.inc"
#include once "Afx/CStream.inc"
using AfxNova

' // Create an instance of the CWinHttp class
DIM pWHttp AS CWinHttpRequest

' // Open an HTTP connection to an HTTP resource
pWHttp.Open "GET", "http://microsoft.com"
' // Send an HTTP request to the HTTP server
pWHttp.Send

' // Wait for response with a timeout of 5 seconds
DIM iSucceeded AS LONG = pWHttp.WaitForResponse(5)

' // Open a file stream
DIM pFileStream AS CFileStream = pWHttp.GetResponseStream
DIM cbSize AS LONG = pFileStream.GetSize
DIM buffer(cbSize) AS BYTE
DIM cbRead AS ULONG = pFileStream.Read(@buffer(0), cbSize)
DIM fn AS LONG = FREEFILE
OPEN "response.txt" FOR BINARY AS #fn
PUT #fn, 1, buffer()
CLOSE #fn
PRINT "File saved"

PRINT
PRINT "Press any key..."
SLEEP
