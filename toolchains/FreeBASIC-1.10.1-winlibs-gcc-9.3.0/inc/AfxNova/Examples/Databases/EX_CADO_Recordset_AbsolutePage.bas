' ########################################################################################
' Microsoft Windows
' Contents: ADO - AbsolutePage example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the AbsolutePage property.
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

' // Display five records at a time
DIM nPageSize AS LONG = 5
pRecordset.PageSize = nPageSize
' // Retrieve the number of pages
DIM nPageCount AS LONG = pRecordset.PageCount

' // Parse the recordset
FOR i AS LONG = 1 TO nPageCount
   ' // Set the cursor at the beginning of the page
   pRecordset.AbsolutePage = i
   FOR x AS LONG = 1 TO nPageSize
      ' // Get the content of the "Name" column
      PRINT pRecordset.Collect("Name")
      ' // Fetch the next row
      pRecordset.MoveNext
      IF pRecordset.EOF THEN EXIT FOR
   NEXT
NEXT

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
