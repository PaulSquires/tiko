' ########################################################################################
' Microsoft Windows
' Contents: ADO - Recordset Save
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

' // Create an scoped instance of the CAdoRecordset class
SCOPE
   DIM pRecordset AS CAdoRecordset
   ' // Set the cursor location
   pRecordset.CursorLocation = adUseClient

   ' // Open the recordset
   DIM dvSource AS DVARIANT = "SELECT * FROM Publishers"
   pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

   ' // Save the recordset
   DIM wszFileName AS WSTRING * MAX_PATH = "Publishers.dat"
   IF AfxFileExists(wszFileName) THEN KILL wszFileName
   IF pRecordset.Save(wszFileName, adPersistADTG) = S_OK THEN
      PRINT "Recordset saved"
   ELSE
      PRINT "Save failed"
   END IF
   pRecordset.Close
END SCOPE

IF AfxFileExists("Publishers.dat") THEN
   ' // Reopen the recordset
   DIM pRecordset AS CAdoRecordset
   DIM dvSource AS DVARIANT = "Publishers.dat"
   DIM hr AS HRESULT = pRecordset.Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdFile)
   IF hr = S_OK THEN
      ' // Parse the recordset
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         ' // Get the contents
         DIM dvRes1 AS DVARIANT = pRecordset.Collect("PubID")
         DIM dvRes2 AS DVARIANT = pRecordset.Collect("Name")
         DIM dvRes3 AS DVARIANT = pRecordset.Collect("Company Name")
         PRINT dvRes1 + " " + dvRes2 + " " + dvRes3
         ' // Fetch the next row
         IF pRecordset.MoveNext <> S_OK THEN EXIT DO
      LOOP
   END IF
   pRecordset.Close
END IF

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
