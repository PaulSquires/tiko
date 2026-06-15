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
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
IF pServices.ServicesPtr = NULL THEN EXIT DO
 
' // Get an instance of the printer "OKI B410" --> change me
DIM hr AS HRESULT = pServices.Get("Win32_Printer.DeviceID='OKI B410'")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : EXIT DO

' // Number of properties
PRINT "Number of properties: ", pServices.PropsCount
PRINT

' // Display some properties
PRINT "Port name: "; pServices.PropValue("PortName")
PRINT "Attributes: "; pServices.PropValue("Attributes")
PRINT "Paper sizes supported: "; pServices.PropValue("PaperSizesSupported")

EXIT DO   ' // exit the fake loop
LOOP

PRINT
PRINT "Press any key..."
SLEEP
