' ########################################################################################
' Microsoft Windows
' WMI example.
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
DIM pServices AS CWmiServices = ( _
   $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2:Win32_Process")
IF pServices.ServicesPtr = NULL THEN EXIT DO
 
' // Assign the WMI services object pointer to CDispInvoke
' // CWmiServices.ServicesObj returns an AddRefed pointer, whereas CWmiServices.ServicesPtr not.
DIM pDispServices AS CDispInvoke = CDispInvoke(pServices.ServicesObj)

' // Note: Although the WMI documentation says that this OUT parameter is an UInt32,
' // it only works if I use "LONG".
DIM ProcessId AS LONG
pDispServices.Invoke("Create", "notepad.exe", AfxDVarOptPrm, AfxDVarOptPrm, DVARIANT(@ProcessId, "LONG"))
PRINT "Process id: ", ProcessId

EXIT DO   ' // exit the fake loop
LOOP

PRINT
PRINT "Press any key..."
SLEEP
