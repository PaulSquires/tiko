' ########################################################################################
' Microsoft Windows
' WMI enumeration example
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
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_BIOS")
IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : EXIT DO

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Count: ", nCount
IF nCount = 0 THEN PRINT "No objects found" : EXIT DO

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
IF pDispServ.DispPtr THEN
   PRINT "BIOS version: : "; pDispServ.Get("BIOSVersion")
   PRINT "BIOS characteristics:"; pDispServ.Get("BIOSCharacteristics")
   PRINT "Build number: "; pDispServ.Get("BuildNumber")
   PRINT "Caption: "; pDispServ.Get("Caption")
   PRINT "Current language: "; pDispServ.Get("CurrentLanguage")
   PRINT "Description: "; pDispServ.Get("Description")
   PRINT "Identification code: "; pDispServ.Get("IdentificationCode")
   PRINT "Installable languages: "; pDispServ.Get("InstallableLanguages")
   PRINT "Install date: "; pDispServ.Get("InstallDate")
   PRINT "Language edition: "; pDispServ.Get("LanguageEdition")
   PRINT "List of languages: "; pDispServ.Get("ListOfLanguages")
   PRINT "Manufacturer: "; pDispServ.Get("Manufacturer")
   PRINT "Other target OS: "; pDispServ.Get("OtherTargetOS")
   PRINT "Primary BIOS: "; pDispServ.Get("PrimaryBIOS")
   PRINT "Release date: "; pServices.WmiDateToStr(pDispServ.Get("ReleaseDate"), "dd-MM-yyyy")
   PRINT "Serial number: "; pDispServ.Get("SerialNumber")
   PRINT "SMBIOS BIOS version: "; pDispServ.Get("SMBIOSBIOSVersion")
   PRINT "SMBIOS major version: "; pDispServ.Get("SMBIOSMajorVersion")
   PRINT "SMBIOS minor version: "; pDispServ.Get("SMBIOSMinorVersion")
   PRINT "SMBIOS present: "; pDispServ.Get("SMBIOSPresent")
   PRINT "Software element ID: "; pDispServ.Get("SoftwareElementID")
   PRINT "Software element state: "; pDispServ.Get("SoftwareElementState")
   PRINT "Target operating system: "; pDispServ.Get("TargetOperatingSystem")
   PRINT "Version: "; pDispServ.Get("Version")
END IF

EXIT DO   ' // exit the fake loop
LOOP

PRINT
PRINT "Press any key..."
SLEEP
