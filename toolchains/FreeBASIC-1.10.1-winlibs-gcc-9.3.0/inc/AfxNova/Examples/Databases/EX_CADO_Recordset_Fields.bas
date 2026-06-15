' ########################################################################################
' Microsoft Windows
' Contents: ADO - Fields example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Fields collection.
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

' // Open the recordset
DIM pRecordset AS CAdoRecordset
DIM dvSource AS DVARIANT = "SELECT * FROM Publishers ORDER BY PubID"
DIM hr AS HRESULT = pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // Get a reference to the Fields collection
DIM pFields AS CAdoFields = pRecordset.Fields

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the contents of the fields
   ' // Note: Instead of pField.Attach / pField.Value, we can use pRecordset.Collect
    DIM pField AS CAdoField
    pField.Attach(pFields.Item("PubID"))
    DIM dvRes1 AS DVARIANT = pField.Value
    pField.Attach(pFields.Item("Name"))
    DIM dvRes2 AS DVARIANT = pField.Value
    pField.Attach(pFields.Item("Company Name"))
    DIM dvRes3 AS DVARIANT = pField.Value
    PRINT dvRes1; " "; dvRes2; " "; dvRes3
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
