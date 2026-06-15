' ########################################################################################
' Microsoft Windows
' Contents: ODBC - Retrieves the cursor name.
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
' // Sets the cursor name
pStmt.SetCursorName "MyCursor"
' // Gets the cursor name
PRINT "Cursor name: " & pStmt.GetCursorName

PRINT
PRINT "Press any key..."
SLEEP
