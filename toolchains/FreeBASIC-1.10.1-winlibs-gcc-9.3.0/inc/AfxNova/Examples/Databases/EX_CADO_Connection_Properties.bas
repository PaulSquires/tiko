' ########################################################################################
' Microsoft Windows
' Contents: ADO - Properties collection example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the Properties collection of the Connection object.
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

' // Create an instance of the CAdoProperties class
' // with a reference to the Peoperties collection.
DIM pProperties AS CAdoProperties = pConnection.Properties
PRINT "Number of properties: "; pProperties.Count

' // Create an instance of the CAdoProperty class
' // with a reference to a Property object.
DIM pProperty AS CAdoProperty = pProperties.Item("DBMS Version")

' // Print the value of the property
PRINT "DBMS version : "; pProperty.Value

' // === Close the connection
pConnection.Close


PRINT
PRINT "Press any key..."
SLEEP
