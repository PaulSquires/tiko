' ########################################################################################
' Microsoft Windows
' Contents: ADO - Recordset Save as XML
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Save method of the Recordset object
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

' // Open the recordset
DIM pRecordset AS CAdoRecordset
DIM dwsSource AS DWSTRING = "SELECT * FROM Publishers"
pRecordset.Open(dwsSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // Save the recordset as XML
DIM wszFileName AS WSTRING * MAX_PATH = "Publishers.xml"
IF AfxFileExists(wszFileName) THEN KILL wszFileName
IF pRecordset.Save(wszFileName, adPersistXML) = S_OK THEN
   PRINT "Recordset saved"
ELSE
   PRINT "Save failed"
END IF

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
