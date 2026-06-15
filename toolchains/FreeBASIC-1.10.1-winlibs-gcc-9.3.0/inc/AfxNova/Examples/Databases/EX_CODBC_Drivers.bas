' ########################################################################################
' Microsoft Windows
' Contents: ODBC - Retrieves the PDBC drivers.
' Compiler: FreeBasic 32 bit
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/COdbc.inc"
USING AfxNova

' // Create a connection object and connect with the database
' // We need to call it to create the environment handle
DIM wszConStr AS WSTRING * 260 = "DRIVER={Microsoft Access Driver (*.mdb)};DBQ=biblio.mdb"
DIM pDbc AS CODBC = wszConStr
IF pDbc.Handle = NULL THEN PRINT "Unable to create the connection handle" : SLEEP : END

DIM wDirection AS WORD
DIM dwsDriverAttributes AS DWSTRING
DIM dwsDriverDesc AS DWSTRING

wDirection = SQL_FETCH_FIRST
DO
   dwsDriverDesc = ""
   dwsDriverAttributes = ""
   IF SQL_SUCCEEDED(pDbc.GetDrivers(wDirection, dwsDriverDesc, dwsDriverAttributes)) = 0 THEN EXIT DO
   ? "Driver description: " & dwsDriverDesc
   ? "Driver attributes: " & dwsDriverAttributes
   wDirection = SQL_FETCH_NEXT
LOOP

PRINT
PRINT "Press any key..."
SLEEP
