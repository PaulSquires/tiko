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
pStream.Type_ = adTypeText
pStream.LineSeparator = adCRLF
pStream.Open

' // Write some text to it
pStream.WriteText "This is a test string", adWriteLine
pStream.WriteText "This is another test string", adWriteLine

' // Set the position at the beginning of the file
pStream.Position = 0
' // Read the lines
DIM dwsText AS DWSTRING = pStream.ReadText(adReadLine)
print dwsText
dwsText = pStream.ReadText(adReadLine)
print dwsText

' // Save the contents to a file
pStream.SaveToFile "TestStream.txt", adSaveCreateOverWrite
pStream.Close

PRINT
PRINT "Press any key..."
SLEEP
