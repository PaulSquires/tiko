' ########################################################################################
' Microsoft Windows
' Contents: ADO - In-memory recordset example
' Compiler: FreeBasic 32 bit
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CADODB.inc"
USING AfxNova

' // Create an instance of the CAdoRecorset class
DIM pRecordset AS CAdoRecordset
' // Get a reference to the Fields collection
DIM pFields AS CAdoFields = pRecordset.Fields

pFields.Append("Key", adVarChar, 10)
pFields.Append("Item", adVarChar, 20)

pRecordset.Open(adOpenKeyset, adLockOptimistic)

print "Record count: ", pRecordset.Recordcount

pRecordset.AddNew
   pRecordset.Collect("Key") = "One"
   pRecordset.Collect("Item") = "Item one"
'pRecordset.Update

pRecordset.AddNew
   pRecordset.Collect("Key") = "Two"
   pRecordset.Collect("Item") = "Item two"
'pRecordset.Update

pRecordset.AddNew
   pRecordset.Collect("Key") = "Three"
   pRecordset.Collect("Item") = "Item three"
'pRecordset.Update

print "New record count: ", pRecordset.Recordcount

'pRecordset.MoveFirst
pRecordset.AbsolutePosition = 3
DO WHILE NOT pRecordset.EOF
   PRINT pRecordset.Collect("Key")
   PRINT pRecordset.Collect("Item")
   IF pRecordset.MoveNext <> S_OK THEN EXIT DO
LOOP

pRecordset.MoveFirst
PRINT pRecordset.GetString

' // === Close the recordset
pRecordset.Close

PRINT
PRINT "Press any key..."
SLEEP
