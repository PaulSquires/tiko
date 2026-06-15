' ########################################################################################
' Microsoft Windows
' Contents: ADO - Properties collection example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Recordset Properties collection.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
'#define _CADODB_DEBUG_ 1
#include once "AfxNova/CADODB.inc"
USING AfxNova

' // === Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // === Open the recordset
DIM pRecordset AS CAdoRecordset
DIM dwsSource AS DWSTRING = "SELECT * FROM Publishers ORDER BY PubID"
DIM hr AS HRESULT = pRecordset.Open(dwsSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // Parse the Properties collection
DIM pProperties AS CAdoProperties = pRecordset.Properties
DIM nCount AS LONG = pProperties.Count
FOR i AS LONG = 0 TO nCount - 1
   DIM pProperty AS CAdoProperty = pProperties.Item(i)
   PRINT "Property name: "; pProperty.Name; " - Attributes: "; WSTR(pProperty.Attributes)
NEXT

' // === Close the connection
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
