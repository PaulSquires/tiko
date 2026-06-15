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
'DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
' Use the constructor for server connection, just for trying...
DIM pServices AS CWmiServices = CWmiServices(".", "root\cimv2")
IF pServices.ServicesPtr = NULL THEN EXIT DO
 
 '// Get an instance of a file --> change me
DIM dwsPath AS DWSTRING = ExePath & "\EX_CWMI_Get_02.bas"   ' --> change me
DIM hr AS HRESULT = pServices.Get("CIM_DataFile.Name='" & dwsPath & "'")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : EXIT DO

' // Number of properties
PRINT "Number of properties: ", pServices.PropsCount
PRINT

' // Display some properties
PRINT "Relative path: "; pServices.PropValue("Path")
PRINT "FileName: "; pServices.PropValue("FileName")
PRINT "Extension: "; pServices.PropValue("Extension")
PRINT "Size: "; pServices.PropValue("Filesize")
PRINT "Last modified: "; pServices.PropValue("LastModified")
PRINT "Last modified: "; pServices.WmiDateToStr(pServices.PropValue("LastModified"), "dd-MM-yyyy")

EXIT DO   ' // exit the fake loop
LOOP

PRINT
PRINT "Press any key..."
SLEEP
