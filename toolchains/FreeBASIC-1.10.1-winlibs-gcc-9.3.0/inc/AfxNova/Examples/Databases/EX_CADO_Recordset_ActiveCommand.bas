' ########################################################################################
' Microsoft Windows
' Contents: ADO - ActiveCommand example
' Compiler: FreeBasic 32 bit
' Demonstrates the use of the ActiveCommand property.
' Note: Error checking ommited for brevity.
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include once "AfxNova/CADODB.inc"
USING AfxNova

' ========================================================================================
' The ShowActiveCommand routine is given only a Recordset object, yet it must print the
' command text and parameter that created the Recordset. This can be done because the
' Recordset object's ActiveCommand property yields the associated Command object.
' The Command object's CommandText property yields the parameterized command that was
' substituted for the command's parameter placeholder ("?").
' ========================================================================================
SUB ShowActiveCommand (BYREF pConnection AS CAdoConnection, BYREF pRecordset AS CAdoRecordset)

   DIM pCommand AS CAdoCommand = pRecordset.ActiveCommand
   DIM dwsCommandText AS DWSTRING = pCommand.CommandText
   DIM pParameters AS CAdoParameters = pCommand.Parameters
   DIM pParameter AS CAdoParameter = pParameters.Item("Name")
   DIM dvValue AS DVARIANT = pParameter.Value
   PRINT "Command text: "; dwsCommandText
   PRINT "Parameter: "; dvValue

   IF pRecordset.BOF THEN
      PRINT "Name = '"; dvValue; "'not found"
   ELSE
      DIM dvAuthor AS DVARIANT = pRecordset.Collect("Author")
      DIM dvID AS DVARIANT = pRecordset.Collect("Author")
      PRINT "Name= "; dvAuthor; ","; dvID
   END IF

END SUB
' ========================================================================================

' // Open the connection
DIM pConnection AS CAdoConnection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' Set the ADOCommand active connection
DIM pCommand AS CAdoCommand
pCommand.ActiveConnection = pConnection

' //Set the command text
pCommand.CommandText = "SELECT * FROM Authors WHERE Author = ?"
' // Create the parameter
DIM pParameter AS CAdoParameter = pCommand.CreateParameter("Name", adChar, adParamInput, 255, "Bard, Dick")
' // Add the parameter to the collection
DIM pParameters AS CAdoParameters = pCommand.Parameters
pParameters.Append(pParameter)

' // Create the recordset by executing the command string
DIM pRecordset AS CAdoRecordset = pCommand.Execute
' // Display the results
ShowActiveCommand pConnection, pRecordset

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close

PRINT
PRINT "Press any key..."
SLEEP
