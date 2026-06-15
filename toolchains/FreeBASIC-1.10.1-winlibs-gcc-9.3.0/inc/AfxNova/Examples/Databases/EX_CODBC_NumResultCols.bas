' ########################################################################################
' Microsoft Windows
' Contents: ODBC - NumResultCols method
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

' // Connect with the database
DIM wszConStr AS WSTRING * 260 = "DRIVER={Microsoft Access Driver (*.mdb)};DBQ=biblio.mdb"
DIM pDbc AS CODBC = wszConStr

' // Allocate an statement object
DIM pStmt AS COdbcStmt = @pDbc
IF pStmt.Handle = NULL THEN PRINT "Failed to allocate the statement handle": SLEEP : END

' // Cursor type
pStmt.SetMultiuserKeysetCursor

' // Generate a result set
pStmt.ExecDirect ("SELECT * FROM Authors ORDER BY Author")

' // Retrieve the number of columns
DIM numCols AS SQLSMALLINT = pStmt.NumResultCols
PRINT "Number of columns:" & STR(numCols)

' // Retrieve the names of the fields (columns)
FOR idx AS LONG = 1 TO numCols
   PRINT "Field #" & STR(idx) & " name: " & pStmt.ColName(idx)
NEXT

PRINT
PRINT "Press any key..."
SLEEP
