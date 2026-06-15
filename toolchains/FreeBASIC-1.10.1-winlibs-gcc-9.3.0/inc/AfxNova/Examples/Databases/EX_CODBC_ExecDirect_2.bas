' ########################################################################################
' Microsoft Windows
' Contents: ODBC - Get error informaton
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

' ===========================================================================================
' Uses SQLGetDiagRec to retrieve an error description.
' iErrorCode: Optional. The error code returned by some of the methods of this interface.
' ===========================================================================================
PRIVATE FUNCTION _GetErrorInfo (BYVAL HandleType AS SQLSMALLINT, BYVAL Handle AS SQLHANDLE, BYVAL iErrorCode AS SQLRETURN = 0) AS DWSTRING

   DIM iResult AS SQLRETURN
   DIM lNativeError AS SQLINTEGER
   DIM cbbytes AS SQLSMALLINT
   DIM ErrorCount AS SQLINTEGER
   DIM wszSqlState AS ZSTRING * 6
   DIM wszErrMsg AS ZSTRING * SQL_MAX_MESSAGE_LENGTH + 1
   DIM dwsErrMsg AS DWSTRING

'   IF HandleType <> 0 AND Handle <> NULL THEN
'      iResult = SQLGetDiagField(HandleType, Handle, 0, SQL_DIAG_NUMBER, cast(SQLPOINTER, @ErrorCount), SQL_IS_INTEGER, @cbbytes)
'   END IF
'print "-------", ErrorCount
'   IF ErrorCount THEN
'      FOR i AS LONG = 1 TO ErrorCount
         iResult = SQLGetDiagRec(HandleType, Handle, 1, @wszSqlState, @lNativeError, @wszErrMsg, SIZEOF(wszErrMsg), @cbbytes)
print "+++++ ", iResult, cbbytes, len(wszErrMsg), SQL_MAX_MESSAGE_LENGTH
'         IF iResult <> SQL_SUCCESS AND iResult <> SQL_SUCCESS_WITH_INFO THEN EXIT FOR
         dwsErrMsg = wszErrMsg & CHR(13, 10) & "SqlState: " & wszSqlState & "; Native error: " & STR(lNativeError) & CHR(13, 10)
'      NEXT
'   ELSEIF iErrorCode THEN
'      SELECT CASE iErrorCode
'         CASE  -1 : dwsErrMsg = "SQL error" ' "SQL_ERROR"
'         CASE   2 : dwsErrMsg = "Still executing" ' "SQL_STILL_EXECUTING"
'         CASE  -2 : dwsErrMsg = "Invalid handle" '"SQL_INVALID_HANDLE"
'         CASE  99 : dwsErrMsg = "Need data" ' "SQL_NEED_DATA"
'         CASE 100 : dwsErrMsg = "No data" '"SQL_NO_DATA"
'         CASE ELSE
'            dwsErrMsg = "Error " & STR(iErrorCode)
'      END SELECT
'   END IF

   RETURN dwsErrMsg

END FUNCTION
' ===========================================================================================

' // Connect with the database
DIM wszConStr AS WSTRING * 260 = "DRIVER={Microsoft Access Driver (*.mdb)};DBQ=biblio.mdb"
DIM pDbc AS CODBC = wszConStr

' // Allocate an statement object
DIM pStmt AS COdbcStmt = @pDbc
IF pStmt.Handle = NULL THEN PRINT "Failed to allocate the statement handle": SLEEP : END

' // Insert a new record
pStmt.ExecDirect ("INSERT INTO Authors (Au_ID, Author, [Year Born]) VALUES ('999', 'José Roca', 1950)")
print pStmt.GetLastResult; " xxxxxxxxxx"
IF pStmt.Error = FALSE THEN
   PRINT "Record added"
ELSE
   PRINT _GetErrorInfo(SQL_HANDLE_STMT, pStmt.m_hStmt)
END IF

PRINT
PRINT "Press any key..."
SLEEP
