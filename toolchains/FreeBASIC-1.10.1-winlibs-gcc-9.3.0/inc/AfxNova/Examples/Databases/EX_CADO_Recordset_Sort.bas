' ########################################################################################
' Microsoft Windows
' Contents: ADO - Sort example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Sort property.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include "AfxNova/CADODB.inc"
USING AfxNova

' // Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"

' // Set the cursor location
DIM pRecordset AS CAdoRecordset
pRecordset.CursorLocation = adUseClient

' // Open the recordset
pRecordset.Open("Publishers", pConnection, adOpenKeyset, adLockOptimistic, adCmdTableDirect)

' // Set the Sort property
pRecordset.Sort = "City ASC, Name ASC"

' // Parse the recordset
DO WHILE NOT pRecordset.EOF
   ' // Get the contents of the "City" and "Name" columns
   DIM dvRes1 AS DVARIANT = pRecordset.Collect("City")
   DIM dvRes2 AS DVARIANT = pRecordset.Collect("Name")
   PRINT dvRes1 & " " & dvRes2
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
