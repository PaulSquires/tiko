' ########################################################################################
' Microsoft Windows
' Contents: ADO - GetRows example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the GetRows method.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CADODB.inc"
#include "AfxNova/DSafeArray.inc"
USING AfxNova

' // Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // Open the recordset
DIM pRecordset AS CAdoRecordset
DIM dwsSource AS DWSTRING = "SELECT TOP 20 * FROM Publishers ORDER BY Name"
DIM hr AS HRESULT = pRecordset.Open(dwsSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // GetRows returns a pointer to a two-dimensional safe array
' // that we are going to attach to an instance of the CSafeArray class
DIM dsa AS DSafeArray = DSafeArray(pRecordset.GetRows, TRUE)

' // Print the contents of the safe array
FOR j AS LONG = dsa.LBound(2) TO dsa.UBound(2)
   FOR i AS LONG = dsa.LBound(1) TO dsa.UBound(1)
      PRINT dsa.GetVar(i, j)
   NEXT
   PRINT
NEXT

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
