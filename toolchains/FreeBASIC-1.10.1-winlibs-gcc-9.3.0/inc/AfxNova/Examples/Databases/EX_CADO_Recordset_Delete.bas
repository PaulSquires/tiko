' ########################################################################################
' Microsoft Windows
' Contents: ADO - Delete_ example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Delete_ method.
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
DIM dvSource AS DVARIANT = "SELECT * FROM Publishers WHERE PubID=10000"
pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

DIM dvRes AS DVARIANT = pRecordset.Collect("PubID")
IF VAL(dvRes) = 10000 THEN
   pRecordset.Delete_ adAffectCurrent
   PRINT "Record deleted"
ELSE
   PRINT "Record not found"
END IF

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close


PRINT
PRINT "Press any key..."
SLEEP
