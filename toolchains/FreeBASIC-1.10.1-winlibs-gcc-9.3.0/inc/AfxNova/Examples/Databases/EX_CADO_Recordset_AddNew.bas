' ########################################################################################
' Microsoft Windows
' Contents: ADO - AddNew example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the AddNew method.
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
pRecordset.Open("Publishers", pConnection, adOpenKeyset, adLockOptimistic, adCmdTableDirect)

pRecordset.AddNew
   pRecordset.Collect("PubID") = DVARIANT(10000, "LONG")
   pRecordset.Collect("Name") = "Wile E. Coyote"
   pRecordset.Collect("Company Name") = "Warner Brothers Studios"
   pRecordset.Collect("Address") = "4000 Warner Boulevard"
   pRecordset.Collect("City") = "Burbank, CA. 91522"

DIM hr AS HRESULT = pRecordset.Update
IF hr = S_OK THEN
   print "Record updated"
ELSE
   print pRecordset.GetErrorInfo(hr)
END IF

PRINT
PRINT "Press any key..."
SLEEP
