' ########################################################################################
' Microsoft Windows
' Contents: ADO - GetString example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the GetString method.
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

' // Create a Recordset object
DIM pRecordset AS CAdoRecordset

' // Open the recordset
DIM dvSource AS DVARIANT = "SELECT * FROM Publishers"
pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

PRINT pRecordset.GetString

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
