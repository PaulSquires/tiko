' ########################################################################################
' Microsoft Windows
' File: AfxWmiProcs.inc
' Contents: Miscellaneous WMI wrapper functions
' Compiler: Free Basic 32 & 64 bit
' Copyright (c) 2026 José Roca.
'
' License: Distributed under the MIT license.
'
' Permission is hereby granted, free of charge, to any person obtaining a copy of this
' software and associated documentation files (the “Software”), to deal in the Software
' without restriction, including without limitation the rights to use, copy, modify, merge,
' publish, distribute, sublicense, and/or sell copies of the Software, and to permit
' persons to whom the Software is furnished to do so, subject to the following conditions:

' The above copyright notice and this permission notice shall be included in all copies or
' substantial portions of the Software.

' THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
' INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
' PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
' FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
' OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
' DEALINGS IN THE SOFTWARE.'
' ########################################################################################

#pragma once
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/CWmiDisp.inc"
USING AfxNova

' ========================================================================================
' Retrieves the baseboard (also known as a motherboard or system board) serial number.
' ========================================================================================
PRIVATE FUNCTION AfxGetBaseBoardSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_BaseBoard")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Bios serial number.
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_BIOS")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the manufacturer serial number.
' Contrarily to the serial number returned by AfxGetDiskDriveSerialNumber, this one won't
' change even if you format your hard drive.
' Requires Windows Vista+.
' ========================================================================================
PRIVATE FUNCTION AfxGetManufacturerSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_PhysicalMedia")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the disk drive serial number.
' Contrarily to the serial number returned by AfxGetManufacturerSerialNumber, that does not
' change, this one will change every time the hard drive is formatted.
' Requires Windows Vista+.
' ========================================================================================
PRIVATE FUNCTION AfxGetDiskDriveSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_DiskDrive")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the system running on the Windows-based computer. The following list identifiers
' the returned value: "X86-based PC", "MIPS-based PC", "Alpha-based PC", "Power PC",
' "SH-x PC", "StrongARM PC", "64-bit Intel PC", "64-bit Alpha PC", "Unknown", "X86-Nec98 PC".
' ========================================================================================
PRIVATE FUNCTION AfxGetSystemType (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SystemType FROM Win32_ComputerSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SystemType")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of the computer in use, such as laptop, desktop, or Tablet.
' Not available in Windows Server 2003, Windows XP, Windows 2000, Windows NT 4.0, and Windows Me/98/95.
' Value   Meaning
' ------- --------------------------------------------
' 0 (&H0) Unspecified
' 1 (&H1) Desktop
' 2 (&H2) Mobile
' 3 (&H3) Workstation
' 4 (&H4) Enterprise Server
' 5 (&H5) Small Office and Home Office (SOHO) Server
' 6 (&H6) Appliance PC
' 7 (&H7) Performance Server
' 8 (&H8) Maximum
' ========================================================================================
PRIVATE FUNCTION AfxGetPCSystemType (BYREF wszServerName AS WSTRING = ".") AS USHORT
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT PCSystemType FROM Win32_ComputerSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("PCSystemType"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the disk drive from which the Windows operating system starts.
' Example: "\Device\Harddisk0"
' ========================================================================================
PRIVATE FUNCTION AfxGetBootDevice (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT BootDevice FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("BootDevice")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Type of build used for an operating system.
' Examples: "retail build", "checked build", "Multiprocessor Free".
' ========================================================================================
PRIVATE FUNCTION AfxGetOSBuildType (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT BuildType FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("BuildType")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Short description of the object—a one-line string. The string includes the operating
' system version. For example, "Microsoft Windows 7 Enterprise ". This property can be localized.
' Windows Vista and Windows 7: This property may contain trailing characters. For example,
' the string "Microsoft Windows 7 Enterprise " (trailing space included) may be necessary
' to retrieve information using this property.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSCaption (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT Caption FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("Caption")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number, in minutes, an operating system is offset from Greenwich mean time (GMT).
' The number is positive, negative, or zero.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSCurrentTimeZone (BYREF wszServerName AS WSTRING = ".") AS USHORT
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT CurrentTimeZone FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("CurrentTimeZone"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Name of the registered user of the operating system. Example: "Ben Smith".
' ========================================================================================
PRIVATE FUNCTION AfxGetOSRegisteredUser (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT RegisteredUser FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("RegisteredUser")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Company name for the registered user of the operating system.
' Example: "Microsoft Corporation"
' ========================================================================================
PRIVATE FUNCTION AfxGetOSOrganization (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT Organization FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("Organization")
END FUNCTION
' ========================================================================================

' ========================================================================================
' The date in which the OS was installed.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSInstallDate (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT InstallDate FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("InstallDate")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Date and time the operating system was last restarted.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSLastBootUpTime (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT LastBootUpTime FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("LastBootUpTime")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Encryption level for secure transactions: 40-bit, 128-bit, or n-bit.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSEncryptionLevel (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT EncryptionLevel FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("EncryptionLevel"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number, in kilobytes, of physical memory currently unused and available.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSFreePhysicalMemory (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT FreePhysicalMemory FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("FreePhysicalMemory"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number, in kilobytes, that can be mapped into the operating system paging files without
' causing any other pages to be swapped out.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSFreeSpaceInPagingFiles (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT FreeSpaceInPagingFiles FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("FreeSpaceInPagingFiles"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number, in kilobytes, of virtual memory currently unused and available.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSFreeVirtualMemory (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT FreeVirtualMemory FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("FreeVirtualMemory"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum number of process contexts the operating system can support. The default value
' set by the provider is 4294967295 (0xFFFFFFFF). If there is no fixed maximum, the value
' should be 0 (zero). On systems that have a fixed maximum, this object can help diagnose
' failures that occur when the maximum is reached—if unknown, enter 4294967295 (0xFFFFFFFF).
' ========================================================================================
PRIVATE FUNCTION AfxGetOSMaxNumberOfProcesses (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT MaxNumberOfProcesses FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("MaxNumberOfProcesses"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum number, in kilobytes, of memory that can be allocated to a process.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSMaxProcessMemorySize (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT MaxProcessMemorySize FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("MaxProcessMemorySize"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number of process contexts currently loaded or running on the operating system.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSNumberOfProcesses (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT NumberOfProcesses FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("NumberOfProcesses"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number of user sessions for which the operating system is storing state information currently.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSNumberOfUsers (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT NumberOfUsers FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("NumberOfUsers"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Number, in kilobytes, of virtual memory. For example, this may be calculated by adding
' the amount of total RAM to the amount of paging space, that is, adding the amount of
' memory in or aggregated by the computer system to the property, SizeStoredInPagingFiles.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSTotalVirtualMemorySize (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT TotalVirtualMemorySize FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("TotalVirtualMemorySize"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Total amount, in kilobytes, of physical memory available to the operating system. This
' value does not necessarily indicate the true amount of physical memory, but what is
' reported to the operating system as available to it.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSTotalVisibleMemorySize (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT TotalVisibleMemorySize FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("TotalVisibleMemorySize"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Media Access Control (MAC) address of the network adapter. A MAC address is assigned by
' the manufacturer to uniquely identify the network adapter. Example: "00:80:C7:8F:6C:96".
' ========================================================================================
PRIVATE FUNCTION AfxGetNetworkAdapterMACAddress (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT MACAddress FROM Win32_NetworkAdapterConfiguration")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("MACAddress")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the physical sector size of the physical disk, in bytes. For example: for 4K native
' and 512-byte emulated disks, the value of this property should be 4096.
' ========================================================================================
PRIVATE FUNCTION AfxGetPhysicalDiskSectorSize (BYREF wszServerName AS WSTRING = ".") AS UINT64
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\Microsoft\Windows\Storage"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT PhysicalSectorSize FROM MSFT_PhysicalDisk")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("PhysicalSectorSize"))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the total physical storage size of the disk, in bytes.
' ========================================================================================
PRIVATE FUNCTION AfxGetPhysicalDiskSize (BYREF wszServerName AS WSTRING = ".") AS UINT64
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\Microsoft\Windows\Storage"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT Size FROM MSFT_PhysicalDisk")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("Size"))
END FUNCTION
' ========================================================================================
