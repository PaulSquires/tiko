' ########################################################################################
' Microsoft Windows
' ADO - Events example
' Demonstrates the use of the Connection and Recordset events
' Compiler: FreeBasic 32 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _CADODB_DEBUG_ 1
#include once "AfxNova/CADODB.inc"
USING AfxNova

' ########################################################################################
' // Custom implementation of ADO Connection events
' ########################################################################################
TYPE CAdoConnectionEventsImpl EXTENDS CAdoConnectionEvents
   DECLARE FUNCTION WillConnect (BYVAL ConnectionString AS Afx_BSTR PTR, BYVAL UserID AS Afx_BSTR PTR, BYVAL Password AS Afx_BSTR PTR, BYVAL Options AS LONG PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   DECLARE FUNCTION ConnectComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   DECLARE FUNCTION Disconnect (BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   ' Override any additional method that you wish
END TYPE

FUNCTION CAdoConnectionEventsImpl.WillConnect (BYVAL ConnectionString AS Afx_BSTR PTR, BYVAL UserID AS Afx_BSTR PTR, BYVAL Password AS Afx_BSTR PTR, BYVAL Options AS LONG PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   CADODB_DP("- Connection string: " & **ConnectionString)
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoConnectionEventsImpl.ConnectComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   CADODB_DP("- adStatus: " & WSTR(*adStatus))
   IF *adStatus = adStatusOK THEN
      CADODB_DP("Connection succeeded")
   ELSE
      CADODB_DP("Connection failed")
   END IF
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoConnectionEventsImpl.Disconnect (BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
' ########################################################################################

' ########################################################################################
' // Custom implementation of ADO Recordset events
' ########################################################################################
TYPE CAdoRecordsetEventsImpl EXTENDS CAdoRecordsetEvents
   DECLARE FUNCTION WillMove (BYVAL adReason AS EventReasonEnum, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   DECLARE FUNCTION MoveComplete (BYVAL adReason AS EventReasonEnum, BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   DECLARE FUNCTION EndOfRecordset (BYVAL fMoreData AS VARIANT_BOOL PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   ' Override any additional method that you wish
END TYPE

FUNCTION CAdoRecordsetEventsImpl.WillMove (BYVAL adReason AS EventReasonEnum, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoRecordsetEventsImpl.MoveComplete (BYVAL adReason AS EventReasonEnum, BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoRecordsetEventsImpl.EndOfRecordset (BYVAL fMoreData AS VARIANT_BOOL PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
' ########################################################################################

' // === Create an instance of the Connection object
DIM pConnection AS CAdoConnection
' // === Connect events
DIM pEvtSink AS ANY PTR = NEW CAdoConnectionEventsImpl
pConnection.SetEvents pEvtSink
' // === Open the connection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // === Create a Recordset object
DIM pRecordset AS CAdoRecordset
' // === Connect events
pEvtSink = NEW CAdoRecordsetEventsImpl
pRecordset.SetEvents pEvtSink
' // === Open the recordset
pRecordset.Open("SELECT * FROM Authors", pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the content of the "Author" column
   PRINT pRecordset.Collect("Author")
   ' // Fetch the next row
   IF pRecordset.MoveNext <> S_OK THEN EXIT DO
LOOP

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close


PRINT
PRINT "Press any key..."
SLEEP
