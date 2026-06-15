' ########################################################################################
' Microsoft Windows
' Contents: ADO - Find example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Find method.
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

' // Open the recordset
DIM pRecordset AS CAdoRecordset
DIM dvSource AS DVARIANT = "SELECT * FROM Publishers ORDER By PubID"
pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

pRecordset.Find("PubID = #70#")
DIM dvRes1 AS DVARIANT = pRecordset.Collect("PubID")
DIM dvRes2 AS DVARIANT = pRecordset.Collect("Name")
PRINT dvRes1 & " " & dvRes2

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
