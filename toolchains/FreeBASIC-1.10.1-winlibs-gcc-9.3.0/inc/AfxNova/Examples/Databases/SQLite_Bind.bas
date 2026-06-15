' Binding
#cmdline "-s console"
#define UNICODE
#INCLUDE ONCE "AfxNova/AfxWin.inc"
#INCLUDE ONCE "AfxNova/CSQLite3.inc"
USING AfxNova

' // Optional: Specify the DLL path and/or name
' // This allows to use a DLL with a different name that sqlite3.dll,
' // located anywhere, avoiding the neeed to have multiple copies of the same dll.
DIM pSql AS CSQLite = ExePath & "\sqlite3_64.dll"
IF pSql.m_hLib = NULL THEN END

' // Create a new database
' // I'm deleting and recreating the database for testing purposes
DIM dwsDbName AS DWSTRING = AfxGetExePathName & "Test.sdb"
IF AfxFileExists(dwsDbName) THEN AfxDeleteFile(dwsDbName)
DIM pDbc AS CSQLiteDb = dwsDbName

' // Create a table
IF pDbc.Exec("CREATE TABLE t (xyz text)") <> SQLITE_DONE THEN
   AfxMsg "Unable to create the table"
   END
END IF

' // Prepare the statement
DIM sql AS DWSTRING = "INSERT INTO t (xyz) VALUES (?)"
DIM pStmt AS CSqliteStmt = pDbc.Prepare(sql)
' // Bind the text
pStmt.BindText(1, "fruit")
' // Execute the prepared statement
pStmt.Step_
PRINT "Row id was", pDbc.LastInsertRowId

' // Prepare a query
pStmt.hStmt = pDbc.Prepare("SELECT * FROM t")
' // Read the value
pStmt.GetRow
PRINT pStmt.ColumnText("xyz")

PRINT
PRINT "Press any key..."
SLEEP
