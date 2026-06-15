' ########################################################################################
' Microsoft Windows
' Contents: ADO - AbsolutePosition example
' Compiler: FreeBasic 32 bit
' This example demonstrates how the AbsolutePosition property can track the progress of a
' loop that enumerates all the records of a Recordset. It uses the CursorLocation property
' to enable the AbsolutePosition property by setting the cursor to a client cursor.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CADODB.inc"
USING AfxNova

' // === Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // === Set the cursor location
DIM pRecordset AS CAdoRecordset
pRecordset.CursorLocation = adUseClient

' // === Open the recordset
pRecordset.Open("Publishers", pConnection, adOpenKeyset, adLockOptimistic, adCmdTable)

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the content of the "Name" column
   DIM dvRes AS DVARIANT = pRecordset.Collect("Name")
   PRINT "Position: "; pRecordset.AbsolutePosition; " "; dvRes
   ' // Fetch the next row
   IF pRecordset.MoveNext <> S_OK THEN EXIT DO
LOOP

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
