' ########################################################################################
' Microsoft Windows
' Contents: ADO - Execute method example (Command object)
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Execute method of the Command object.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include "AfxNova/CADODB.inc"
USING AfxNova

' // === Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"

' // == Create a Command object
DIM pCommand AS CAdoCommand

' // === Set the active connection
pCommand.ActiveConnection = pConnection

' // === Set the CommandText property
pCommand.CommandText = "SELECT TOP 20 * FROM Authors ORDER BY Author"

' // === Create the recordset by executing a query and attaching
' // === the resulting recordset to an instance of the CAdoRecordset class.
DIM pRecordset AS CAdoRecordset = pCommand.Execute

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the content of the "Author" column
   PRINT pRecordset.Collect("Author")
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
