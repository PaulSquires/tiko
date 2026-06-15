' ########################################################################################
' Microsoft Windows
' WMI Get method example
' Compiler: FreeBasic 32 & 64 bit bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#include "AfxNova/CWmiDisp.inc"
using AfxNova

DO   ' // fake loop to allow early exit

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN EXIT DO

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : EXIT DO

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Number of objects: ", nCount
IF nCount = 0 THEN PRINT "No objects found" : EXIT DO

' // Enumerate the objects
FOR i AS LONG = 0 TO nCount - 1
   PRINT "--- Index " & STR(i) & " ---"
   ' // Get a collection of named properties
   IF pServices.GetNamedProperties(i) = S_OK THEN
      PRINT pServices.PropValue("Caption")
      PRINT pServices.PropValue("Capabilities")
   END IF
NEXT

EXIT DO   ' // exit the fake loop
LOOP

PRINT
PRINT "Press any key..."
SLEEP
