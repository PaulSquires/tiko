' ########################################################################################
' Microsoft Windows
' Contents: ADO - Stream example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Stream object.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CADODB.inc"
USING AfxNova

' // Open a stream in memory
DIM pStream AS CAdoStream
pStream.Charset = "_autodetect"
pStream.Open
' // Load a file in the stream
DIM hr AS HRESULT = pStream.LoadFromFile(ExePath & "\Test1.bas")
' // Read all the text
PRINT pStream.ReadText

DO WHILE NOT pStream.EOS
   PRINT pStream.ReadText(adReadLine)
LOOP

' // Close the stream
pStream.Close

PRINT
PRINT "Press any key..."
SLEEP
