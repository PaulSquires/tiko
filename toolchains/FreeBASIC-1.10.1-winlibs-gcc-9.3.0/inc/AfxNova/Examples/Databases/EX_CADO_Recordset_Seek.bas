' ########################################################################################
' Microsoft Windows
' Contents: ADO - Seek example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Seek property of the Recordset object.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CADODB.inc"
USING AfxNova

' // Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // Set the cursor location
DIM pRecordset AS CAdoRecordset
pRecordset.CursorLocation = adUseServer

' // Open the recordset
DIM dvSource AS DVARIANT = "Publishers"
DIM hr AS HRESULT = pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdTableDirect)

' // Set the index
pRecordset.Index = "PrimaryKey"

' // Seek the record 70
pRecordset.Seek 70, 1

' // Parse the recordset
DO WHILE NOT pRecordset.EOF
   ' // Get the contents
   DIM dvRes1 AS DVARIANT = pRecordset.Collect("PubID")
   DIM dvRes2 AS DVARIANT = pRecordset.Collect("Name")
   DIM dvRes3 AS DVARIANT = pRecordset.Collect("Company Name")
   PRINT dvRes1 & " " & dvRes2 & " " & dvRes3
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
