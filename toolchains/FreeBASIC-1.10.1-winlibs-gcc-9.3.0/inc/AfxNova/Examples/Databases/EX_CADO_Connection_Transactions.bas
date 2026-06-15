' ########################################################################################
' Microsoft Windows
' Contents: ADO - Transaction example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of transactions.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define UNICODE
#include once "AfxNova/CADODB.inc"
USING AfxNova

' // === Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // === Open the recordset
DIM pRecordset AS CAdoRecordset
pRecordset.Open("SELECT * FROM Authors", pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // === Begin a transaction
pConnection.BeginTrans

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the content of the "Author" column
   DIM dvRes AS DVARIANT = pRecordset.Collect("Year Born")
   IF VAL(dvRes) = 1947 THEN pRecordset.Collect("Year Born") = 1900
   ' // Fetch the next row
   IF pRecordset.MoveNext <> S_OK THEN EXIT DO
LOOP

' // === Commit the transaction
'pConnection.CommitTrans
' // === Rollback the transaction because this is a demo
pConnection.RollbackTrans

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
