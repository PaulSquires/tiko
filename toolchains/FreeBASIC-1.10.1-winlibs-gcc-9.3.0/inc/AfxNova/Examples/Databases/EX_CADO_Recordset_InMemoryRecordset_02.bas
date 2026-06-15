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

pRecordset.CursorLocation = adUseClient
pRecordset.Open(adOpenKeyset, adLockOptimistic)

pRecordset.AddNew
   pRecordset.Collect("Key") = "One"
   pRecordset.Collect("Item") = "Item one"

pRecordset.AddNew
   pRecordset.Collect("Key") = "Two"
   pRecordset.Collect("Item") = "Item two"

pRecordset.AddNew
   pRecordset.Collect("Key") = "Three"
   pRecordset.Collect("Item") = "Item three"

' // Start searching from the first record (adBookmarkFirst)
' // You can also start from the current record (the default value, adBookmarkCurrent)
' // or from the last record (adBookmarkLast). The default search direction is
' // adSearchForward. If you want to perform a backwards search, you will have to
' // specify adSearchBackward in the search direction parameter.
IF pRecordset.Find("Key = 'Two'", adBookmarkFirst) = S_OK THEN
   PRINT pRecordset.Collect("Item")
ELSE
   PRINT "Record not found"
END IF

' // === Close the recordset
pRecordset.Close

PRINT
PRINT "Press any key..."
SLEEP
