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
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\default:StdRegProv"
IF pServices.ServicesPtr = NULL THEN EXIT DO
 
' // Assign the WMI services object pointer to CDispInvoke
' // CWmiServices.ServicesObj returns an AddRefed pointer, whereas CWmiServices.ServicesPtr not.
DIM pDispServices AS CDispInvoke = CDispInvoke(pServices.ServicesObj)

' Parameters of the GetStringValue method:
' %HKEY_LOCAL_MACHINE ("2147483650") - The value must be specified as an string and in decimal, not hexadecimal.
' vDefKey = [IN]  "2147483650"
' vPath   = [IN]  "Software\Microsoft\Windows NT\CurrentVersion"
' vValue  = [OUT] "ProductName"

DIM bsValue AS BSTRING
DIM dvRes AS DVARIANT = pDispServices.Invoke("GetStringValue", "2147483650", _
    $"Software\Microsoft\Windows NT\CurrentVersion", "ProductName", DVARIANT(bsValue.vptr, VT_BSTR))
PRINT bsValue

EXIT DO   ' // exit the fake loop
LOOP

PRINT
PRINT "Press any key..."
SLEEP
