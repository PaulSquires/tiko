' Basic steps
#cmdline "-s console"
#define UNICODE
'#define _CSQLITE_DEBUG_ 1
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
DIM dwsDbName AS DWSTRING = ExePath & "\Test.sdb"
IF AfxFileExists(dwsDbName) THEN AfxDeleteFile(dwsDbName)
DIM pDbc AS CSQLiteDb = dwsDbName

' // Create a table
IF pDbc.Exec("CREATE TABLE t (xyz text)") <> SQLITE_DONE THEN
   AfxMsg "Unable to create the table"
   END
END IF

' // Insert rows
IF pDbc.Exec("INSERT INTO t (xyz) VALUES ('fruit')") <> SQLITE_DONE THEN AfxMsg "INSERT failed"
IF pDbc.Exec("INSERT INTO t (xyz) VALUES ('fish')") <> SQLITE_DONE THEN AfxMsg "INSERT failed"

' // Prepare a query
DIM pStmt AS CSqliteStmt = pDbc.Prepare("SELECT * FROM t")
PRINT "Column count: ", pStmt.ColumnCount
' // Read the column names and values
DO
   ' // Fetch rows of the result set
   IF pStmt.GetRow = SQLITE_DONE THEN EXIT DO
   ' // Read the columns and values
   FOR i AS LONG = 0 TO pStmt.ColumnCount- 1
      ' // Get the value using the number of column...
      PRINT pStmt.ColumnName(i)
      PRINT pStmt.ColumnText(i)
      ' // ...or using the column name
      PRINT pStmt.ColumnText("xyz")
   NEXT
LOOP

PRINT
PRINT "Press any key..."
SLEEP
