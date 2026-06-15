' ########################################################################################
' Microsoft Windows
' Contents: ADO - Recordset Field example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Field method of the Fields collection.
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
pRecordset.CursorLocation = adUseClient

' // Open the recordset
DIM dvSource AS DVARIANT = "SELECT * FROM Publishers"
pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // Get a reference to the Fields collection
DIM pFields AS CAdoFields = pRecordset.Fields

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the contents of the fields
   DIM pField AS CAdoField
   pField.Attach(pFields.Item("Name"))
   DIM dvRes AS DVARIANT = pField.Value
   PRINT "Name: "; dvRes; " - "; WSTR(pField.ActualSize); " - "; WSTR(pField.DefinedSize)
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
