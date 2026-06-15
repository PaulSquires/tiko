' ########################################################################################
' Platform: Microsoft Windows
' Filename: CSysInfo.inc
' Contents: System information static class
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2026 José Roca
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
#INCLUDE ONCE "win/wincrypt.bi"
#INCLUDE ONCE "win/iphlpapi.bi"
#INCLUDE ONCE "AfxNova/AfxWin.inc"
#INCLUDE ONCE "AfxNova/AfxWsh.inc"
'#INCLUDE ONCE "AfxNova/DWSTRING.inc"
USING AfxNova

' // The linker fails when calling GetUserNameExW because the function is not exported by libsecur32.dll.a
DECLARE FUNCTION __GetUserNameExW LIB "secur32.dll" ALIAS "GetUserNameExW" (BYVAL NameFormat AS LONG, BYVAL lpNameBuffer AS LPWSTR, BYVAL nSize AS PULONG) as BOOLEAN

NAMESPACE AfxNova

' ========================================================================================
' CSysInfo class
' ========================================================================================
TYPE CSysInfo

Private:
   m_pData AS ANY PTR   ' Not used by the static functions, but we can't have an empty type.

Protected:
   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

Public:

   ' // Operating system
   DECLARE STATIC FUNCTION GetWindowsVersion () AS LONG
   DECLARE STATIC FUNCTION GetWindowsMajorVersion () AS LONG
   DECLARE STATIC FUNCTION GetWindowsMinorVersion () AS LONG
   DECLARE STATIC FUNCTION GetWindowsPlatform () AS LONG
   DECLARE STATIC FUNCTION GetWindowsBuild () AS LONG
   DECLARE STATIC FUNCTION IsPlatformNT () AS BOOLEAN
   DECLARE STATIC FUNCTION GetFileVersion (BYVAL pwszFileName AS WSTRING PTR) AS LONG
   DECLARE STATIC FUNCTION GetServicePack () AS DWSTRING
   DECLARE STATIC FUNCTION GetWindowsFeatureUpdate () AS DWSTRING
   DECLARE STATIC FUNCTION GetProcessorArchitecture () AS DWSTRING
   DECLARE STATIC FUNCTION GetProcessorsCount () AS LONG
   DECLARE STATIC FUNCTION GetSystemType () AS LONG
   DECLARE STATIC FUNCTION GetComputerName () AS DWSTRING
   DECLARE STATIC FUNCTION GetUserName () AS DWSTRING
   DECLARE STATIC FUNCTION GetUserDomain () AS DWSTRING
   DECLARE STATIC FUNCTION IsUserAnAdmin () AS BOOLEAN
   DECLARE STATIC FUNCTION IsProcessElevated () AS BOOLEAN
   DECLARE STATIC FUNCTION GetComputerNameDnsDomain () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNameDnsFullyQualified () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNameDnsHostname () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNameNetBIOS () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNamePhysicalDnsDomain () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNamePhysicalDnsFullyQualified () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNamePhysicalDnsHostname () AS DWSTRING
   DECLARE STATIC FUNCTION GetComputerNamePhysicalNetBIOS () AS DWSTRING
   DECLARE STATIC FUNCTION GetProductInfo () AS DWORD
   DECLARE STATIC FUNCTION GetMACAddress () AS STRING
   DECLARE STATIC FUNCTION GetMACAddressEx () AS STRING
   DECLARE STATIC FUNCTION GetAllMACAddresses (macs() AS STRING) AS LONG
   DECLARE STATIC FUNCTION GetAllPhysicalMACAddresses (macs() AS STRING) AS LONG
   DECLARE STATIC FUNCTION GetACP () AS UINT

   ' // Memory information
   DECLARE STATIC FUNCTION MemoryLoad () AS DWORD
   DECLARE STATIC FUNCTION TotalPhysicalMemory () AS DWORDLONG
   DECLARE STATIC FUNCTION AvailablePhysicalMemory () AS DWORDLONG
   DECLARE STATIC FUNCTION TotalPageFile () AS DWORDLONG
   DECLARE STATIC FUNCTION AvailablePageFile () AS DWORDLONG
   DECLARE STATIC FUNCTION TotalVirtualMemory () AS DWORDLONG
   DECLARE STATIC FUNCTION AvailableVirtualMemory () AS DWORDLONG
   DECLARE STATIC FUNCTION GetPhysicallyInstalledSystemMemory () AS ULONGLONG

   ' // Disk information
   DECLARE STATIC FUNCTION GetSystemDrive () AS DWSTRING
   DECLARE STATIC FUNCTION GetSystemDirectory () AS DWSTRING
   DECLARE STATIC FUNCTION GetWindowsDirectory () AS DWSTRING
   DECLARE STATIC FUNCTION GetTempPath () AS DWSTRING
   DECLARE STATIC FUNCTION GetSystemWow64Directory () AS DWSTRING

   ' // Display information
   DECLARE STATIC FUNCTION ScreenWidth () AS LONG
   DECLARE STATIC FUNCTION ScreenHeight () AS LONG
   DECLARE STATIC FUNCTION ScreenColors () AS DWORD
   DECLARE STATIC FUNCTION ScreenRefreshRate () AS DWORD
   
   ' // Power status
   DECLARE STATIC FUNCTION ACLineStatus () AS UBYTE
   DECLARE STATIC FUNCTION BatteryChargeStatus () AS UBYTE
   DECLARE STATIC FUNCTION BatteryLifePercent () AS UBYTE
'   DECLARE STATIC FUNCTION BatterySaverStatus () AS UBYTE
   DECLARE STATIC FUNCTION BatteryLifeTime () AS LONG
   DECLARE STATIC FUNCTION BatteryFullLifeTime () AS LONG
   
END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CSysInfo
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CSysInfo
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
'                               *** OPERATING SYSTEM ***
' ========================================================================================

' ========================================================================================
' * Returns the Windows version
' Platform 1:
'   400 Windows 95
'   410 Windows 98
'   490 Windows ME
' Platform 2:
'   400 Windows NT
'   500 Windows 2000
'   501 Windows XP
'   502 Windows Server 2003
'   600 Windows Vista and Windows Server 2008
'   601 Windows 7
'   602 Windows 8
'   603 Windows 8.1
'  1000 Windows 10/11
' Note 1: As Windows 95 and Windows NT return the same version number, we also need to call
' GetWindowsPlatform to differentiate them.
' Note 2: As Windows 10 and Windows 11 return the same version number, we also need to call
' AfxWindowsBuild to differentiate them. Windows 11 is Windows 10 build 21996 and higher.
' Note 3: GetVersion returns version 6.02 (Windows 8) in Windows 10 if the application has
' not a manifest.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsVersion () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion THEN
      DIM osverinfo AS OSVERSIONINFOEXW
      osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
      IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
         FUNCTION = (osverinfo.dwMajorVersion + osverinfo.dwMinorVersion / 100) * 100
      END IF
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsMajorVersion () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion THEN
      DIM osverinfo AS OSVERSIONINFOEXW
      osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
      IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
         FUNCTION = osverinfo.dwMajorVersion
      END IF
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsMinorVersion () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion THEN
      DIM osverinfo AS OSVERSIONINFOEXW
      osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
      IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
         FUNCTION = osverinfo.dwMinorVersion
      END IF
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the Windows platform
'   1 Windows 95/98/ME
'   2 Windows NT/2000/XP/Server/Vista/Windows 7/10/11
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsPlatform () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion THEN
      DIM osverinfo AS OSVERSIONINFOEXW
      osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
      IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
         FUNCTION = osverinfo.dwPlatformId
      END IF
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the Windows build
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsBuild () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion THEN
      DIM osverinfo AS OSVERSIONINFOEXW
      osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
      IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
         FUNCTION = osverinfo.dwBuildNumber
      END IF
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the Windows Platform is NT; FALSE, otherwise.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.IsPlatformNT () AS BOOLEAN
   DIM osvi AS OSVERSIONINFOW
   osvi.dwOSVersionInfoSize = SIZEOF(osvi)
   GetVersionExW(@osvi)
   RETURN (VER_PLATFORM_WIN32_NT = osvi.dwPlatformId)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the version of specified file multiplied by 100, e.g. 601 for version 6.01.
' Example: DIM ver AS LONG = CSysInfo.GetFileVersion("COMCTL32.DLL")
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetFileVersion (BYVAL pwszFileName AS WSTRING PTR) AS LONG
   DIM pvsffi AS VS_FIXEDFILEINFO PTR, dwHandle AS DWORD
   DIM cbLen AS DWORD = GetFileVersionInfoSizeW(pwszFileName, @dwHandle)
   IF cbLen = 0 THEN EXIT FUNCTION
   DIM pVerInfo AS HANDLE = HeapAlloc(GetProcessHeap, HEAP_ZERO_MEMORY, cbLen)
   IF pVerInfo = NULL THEN EXIT FUNCTION
   IF GetFileVersionInfoW(pwszFileName, dwHandle, cbLen, pVerInfo) THEN
      IF VerQueryValueW(pVerInfo, "\", @pvsffi, @cbLen) THEN
         DIM wMajor AS WORD = HIWORD(pvsffi->dwFileVersionMS)
         DIM wMinor AS WORD = LOWORD(pvsffi->dwFileVersionMS)
         FUNCTION = (wMajor + wMinor / 100) * 100
      END IF
   END IF
   HeapFree(GetProcessHeap, 0, pVerInfo)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the service-pack version string. This member contains a null-terminated string, such
' as "Service Pack 3", which indicates the latest service pack installed on the system. If
' no service pack is installed, it returns an empty string.
' In modern versions of Windows (8, 8.1, 10, 11), Microsoft stopped using Service Packs.
' Instead of SP1, SP2, etc., it now uses feature updates (1903, 21H2, 23H2…).
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetServicePack () AS DWSTRING
   DIM osverinfo AS RTL_OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   DIM hLib AS ANY PTR = LoadLibraryW("ntdll.dll")
   IF hLib = NULL THEN FUNCTION = "" : EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion THEN
      IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
         FUNCTION = osverinfo.szCSDVersion
      END IF
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the Windows feature uodate versión, e.g. 22H2.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsFeatureUpdate () AS DWSTRING
   RETURN AfxRegRead("HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\DisplayVersion")
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the processor architecture of the operating system.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetProcessorArchitecture () AS DWSTRING
   DIM SysInfo AS SYSTEM_INFO
   GetNativeSystemInfo(@SysInfo)
   DIM dws AS DWSTRING
   SELECT CASE SysInfo.wProcessorArchitecture
      CASE 0 : dws = "x86"
      CASE 5 : dws = "ARM"
      CASE 6 : dws = "IA64"
      CASE 9 : dws = "AMD64"
      CASE 12 : dws = "ARM64"
      CASE ELSE
         dws = "UNKNOWN"
   END SELECT
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the number of processors.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetProcessorsCount () AS LONG
   DIM SysInfo AS SYSTEM_INFO
   GetSystemInfo (@SysInfo)
   RETURN SysInfo.dwNumberOfProcessors
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the system type of the operating system.
' On a 32-bit operating system, the value is 32 and on a 64-bit operating system it is 64.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetSystemType () AS LONG
   DIM SysInfo AS SYSTEM_INFO
   GetNativeSystemInfo(@SysInfo)
   ' PROCESSOR_ARCHITECTURE_ARM64 = 12
   RETURN IIF(SysInfo.wProcessorArchitecture = PROCESSOR_ARCHITECTURE_AMD64 _
      OR SysInfo.wProcessorArchitecture = 12, 64, 32)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the computer name of the current system.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerName () AS DWSTRING
   DIM buffer AS WSTRING * MAX_COMPUTERNAME_LENGTH + 1
   DIM dwBufLen AS DWORD = SIZEOF(buffer)
   GetComputerNameW(buffer, @dwBufLen)
   RETURN buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the name of the user associated with the current thread.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetUserName () AS DWSTRING
   DIM buffer AS WSTRING * 260
   DIM dwBufLen AS DWORD = SIZEOF(buffer)
   GetUserNameW(buffer, @dwBufLen)
   RETURN buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the user associated with the current thread.
' ========================================================================================
' EXTENDED_NAME_FORMAT is an enumeration
PRIVATE FUNCTION CSysInfo.GetUserDomain () AS DWSTRING
   ' // Get the needed size for the buffer
   DIM cbLen AS ULONG
   ' NameSamCompatible = 2
   __GetUserNameExW(2, NULL, @cbLen)
   IF cbLen = 0 THEN RETURN ""
   DIM dwsBuffer AS DWSTRING = WSPACE(cbLen)
   IF __GetUserNameExW(2, *dwsBuffer, @cbLen) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests whether the current user is a member of the Administrator's group.
' Caller is NOT expected to be impersonating anyone and is expected to be able to
' open its own process and process token.
' See: http://msdn.microsoft.com/en-us/library/windows/desktop/aa376389%28v=vs.85%29.aspx
' Return Value:
'   TRUE - Caller has Administrators local group.
'   FALSE - Caller does not have Administrators local group.
' Note: Replacement for the Windows API function IsUserAnAdmin because Microsoft warns
' about the use of this function and advices to call CheckTokenMembership directly.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.IsUserAnAdmin () AS BOOLEAN
   DIM IsMember AS LONG, AdministratorsGroup AS SID PTR
   DIM ntAuthority AS SID_IDENTIFIER_AUTHORITY = ({0, 0, 0, 0, 0, 5})
   IF AllocateAndInitializeSid(@NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, _
      DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, @AdministratorsGroup) = 0 THEN EXIT FUNCTION
   IF CheckTokenMembership(NULL, AdministratorsGroup, @IsMember) <> 0 THEN
      FUNCTION = IsMember
   END IF
   FreeSid(AdministratorsGroup)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks if the process is running with real administrative privileges.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.IsProcessElevated () AS BOOLEAN
   DIM hToken AS HANDLE
   IF OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, @hToken) = 0 THEN RETURN FALSE
   DIM elevation AS TOKEN_ELEVATION
   DIM dwSize AS DWORD = SIZEOF(elevation)
   IF GetTokenInformation(hToken, TokenElevation, @elevation, SIZEOF(elevation), @dwSize) = 0 THEN
      CloseHandle(hToken)
      RETURN FALSE
   END IF
   CloseHandle(hToken)
   RETURN (elevation.TokenIsElevated <> 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the amount of actual physical memory, in bytes.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.MemoryLoad () AS DWORD
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.dwMemoryLoad
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the amount of actual physical memory, in bytes.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.TotalPhysicalMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullTotalPhys
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the amount of physical memory currently available, in bytes. This is the amount
' of physical memory that can be immediately reused without having to write its contents
' to disk first. It is the sum of the size of the standby, free, and zero lists.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.AvailablePhysicalMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullAvailPhys
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current committed memory limit for the system or the current process, whichever
' is smaller, in bytes.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.TotalPageFile () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullTotalPageFile
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns maximum amount of memory the current process can commit, in bytes. This value is
' equal to or smaller than the system-wide available commit value.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.AvailablePageFile () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullAvailPageFile
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns size of the user-mode portion of the virtual address space of the calling process,
' in bytes. This value depends on the type of process, the type of processor, and the
' configuration of the operating system. For example, this value is approximately 2 GB for
' most 32-bit processes on an x86 processor and approximately 3 GB for 32-bit processes
' that are large address aware running on a system with 4-gigabyte tuning enabled.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.TotalVirtualMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullTotalVirtual
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns amount of unreserved and uncommitted memory currently in the user-mode portion
' of the virtual address space of the calling process, in bytes.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.AvailableVirtualMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullAvailVirtual
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the amount of RAM that is physically installed on the computer, in kilobytes.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetPhysicallyInstalledSystemMemory () AS ULONGLONG
   DIM mem AS ULONGLONG
   ..GetPhysicallyInstalledSystemMemory(@mem)
   RETURN mem
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the system drive name, e.g. "C:".
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetSystemDrive () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   GetWindowsDirectoryW(@path, MAX_PATH)
   RETURN LEFT(path, 2)   ' "C:"
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the system directory.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetSystemDirectory () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   ..GetSystemDirectoryW(@path, MAX_PATH)
   RETURN path
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the Windows directory.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetWindowsDirectory () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   ..GetWindowsDirectoryW(@path, MAX_PATH)
   RETURN path
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the directory designated for temporary files.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetTempPath () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   ..GetTempPathW(MAX_PATH, @path)
   RETURN path
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the system directory used by WOW64.
' This directory is not present on 32-bit Windows.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetSystemWow64Directory () AS DWSTRING
   DIM cbLen AS UINT = GetSystemWow64DirectoryW(NULL, 0)
   IF cbLen = 0 THEN RETURN ""
   DIM dwsBuffer AS DWSTRING = WSPACE(cbLen)
   cbLen = GetSystemWow64DirectoryW(*dwsBuffer, cbLen)
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the width of the screen, in pixels.
' ScreenWidth is virtualized for DPI.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.ScreenWidth () AS LONG
   DIM rc AS RECT
   GetWindowRect(GetDesktopWindow, @rc)
   RETURN rc.right - rc.left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the height of the screen, in pixels.
' ScreenHeight is virtualized for DPI.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.ScreenHeight () AS LONG
   DIM rc AS RECT
   GetWindowRect(GetDesktopWindow, @rc)
   RETURN rc.bottom - rc.top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the color resolution, in bits per pixel, of the display device.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.ScreenColors () AS DWORD
   DIM dm AS DEVMODEW
   dm.dmSize = SIZEOF(dm)
   EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, @dm)
   RETURN dm.dmBitsPerPel
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the frequency, in hertz (cycles per second), of the display device in a
' particular mode. This value is also known as the display device's vertical refresh rate.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.ScreenRefreshRate () AS DWORD
   DIM dm AS DEVMODEW
   dm.dmSize = SIZEOF(dm)
   EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, @dm)
   RETURN dm.dmDisplayFrequency
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the AC power status. This member can be one of the following values:
' Offline (0), Online(1), Unknown status (255)
' ========================================================================================
PRIVATE FUNCTION CSysInfo.ACLineStatus () AS UBYTE
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.ACLineStatus
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the AC power status. This member can be one of the following values:
' 1 = High—the battery capacity is at more than 66 percent
' 2 = Low—the battery capacity is at less than 33 percent
' 4 = Critical—the battery capacity is at less than five percent
' 8 = Charging
' 128 = No system battery
' 255 = Unknown status—unable to read the battery flag information
' The value is zero if the battery is not being charged and the battery capacity is
' between low and high.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.BatteryChargeStatus () AS UBYTE
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.BatteryFlag
END FUNCTION
' ========================================================================================

' ========================================================================================
' The percentage of full battery charge remaining. This member can be a value in the range
' 0 to 100, or 255 if status is unknown.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.BatteryLifePercent () AS UBYTE
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.BatteryLifePercent
END FUNCTION
' ========================================================================================

' ========================================================================================
' The status of battery saver. To participate in energy conservation, avoid resource
' intensive tasks when battery saver is on. To be notified when this value changes, call
' the RegisterPowerSettingNotification function with the power setting GUID, GUID_POWER_SAVING_STATUS.
' 0 = Battery saver is off.
' 1 = Battery saver on. Save energy where possible.
' Note: This flag and the GUID_POWER_SAVING_STATUS GUID were introduced in Windows 10.
' This flag was previously reserved, named Reserved1, and had a value of 0.
' ========================================================================================
'PRIVATE FUNCTION CSysInfo.BatterySaverStatus () AS UBYTE
'   DIM sps AS SYSTEM_POWER_STATUS
'   GetSystemPowerStatus(@sps)
'   RETURN sps.Reserved1   ' SystemStatusFlag
'END FUNCTION
' ========================================================================================

' ========================================================================================
' The number of seconds of battery life remaining, or –1 if remaining seconds are unknown
' or if the device is connected to AC power.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.BatteryLifeTime () AS LONG
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.BatteryLifeTime
END FUNCTION
' ========================================================================================

' ========================================================================================
' The number of seconds of battery life when at full charge, or –1 if full battery lifetime
' is unknown or if the device is connected to AC power.
' The system is only capable of estimating BatteryFullLifeTime based on calculations on
' BatteryLifeTime and BatteryLifePercent. Without smart battery subsystems, this value may
' not be accurate enough to be useful.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.BatteryFullLifeTime () AS LONG
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.BatteryFullLifeTime
END FUNCTION
' ========================================================================================

' ========================================================================================
' The name of the DNS domain assigned to the local computer. If the local computer is a
' node in a cluster, dwsBuffer receives the DNS domain name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNameDnsDomain () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNameDnsDomain, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNameDnsDomain, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The fully qualified DNS name that uniquely identifies the local computer. This name is a
' combination of the DNS host name and the DNS domain name, using the form HostName.DomainName.
' If the local computer is a node in a cluster, dwsBuffer receives the fully qualified DNS
' name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNameDnsFullyQualified () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNameDnsFullyQualified, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNameDnsFullyQualified, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The DNS host name of the local computer. If the local computer is a node in a cluster,
' dwsBuffer receives the DNS host name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNameDnsHostname () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNameDnsHostname, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNameDnsHostname, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The NetBIOS name of the local computer. If the local computer is a node in a cluster,
' dwsBuffer receives the NetBIOS name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNameNetBIOS () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNameNetBIOS, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNameNetBIOS, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The name of the DNS domain assigned to the local computer. If the local computer is a
' node in a cluster, dwsBuffer receives the DNS domain name of the local computer, not the
' name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNamePhysicalDnsDomain () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNamePhysicalDnsDomain, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNamePhysicalDnsDomain, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The fully qualified DNS name that uniquely identifies the computer. If the local computer
' is a node in a cluster, lpBuffer receives the fully qualified DNS name of the local
' computer, not the name of the cluster virtual server.
' The fully qualified DNS name is a combination of the DNS host name and the DNS domain
' name, using the form HostName.DomainName.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNamePhysicalDnsFullyQualified () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNamePhysicalDnsFullyQualified, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNamePhysicalDnsFullyQualified, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The DNS host name of the local computer. If the local computer is a node in a cluster,
' dwsBuffer receives the DNS host name of the local computer, not the name of the cluster
' virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNamePhysicalDnsHostname () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNamePhysicalDnsHostname, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNamePhysicalDnsHostname, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' The DNS host name of the local computer. If the local computer is a node in a cluster,
' dwsBuffer receives the DNS host name of the local computer, not the name of the cluster
' virtual server.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetComputerNamePhysicalNetBIOS () AS DWSTRING
   DIM dwSize AS DWORD
   ' // First call: obtain required size
   GetComputerNameExW(ComputerNamePhysicalNetBIOS, NULL, @dwSize)
   ' // If dwSize <= 1, there is no configured DNS domain
   IF dwSize <= 1 THEN RETURN ""
   ' // Reserve buffer of the exact size
   DIM dwsBuffer AS DWSTRING = WSPACE(dwSize)
   ' // Second call: get the real name
   IF GetComputerNameExW(ComputerNamePhysicalNetBIOS, *dwsBuffer, @dwSize) = 0 THEN RETURN ""
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the product type for the operating system on the local computer, and maps the
' type to the product types supported by the specified operating system.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetProductInfo () AS DWORD
   DIM dwReturnedProductType AS DWORD
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   DIM osverinfo AS OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   IF pfnRtlGetVersion THEN pfnRtlGetVersion(@osverinfo)
   FreeLibrary hLib
   ..GetProductInfo(osverinfo.dwMajorVersion, osverinfo.dwMinorVersion, 0, 0, @dwReturnedProductType)
   RETURN dwReturnedProductType
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the MAC address of a machine's Ethernet card.
' This function only supports one NIC card on your PC.
' Remarks: I have needes to call the UuidCreateSequential function dynamically because,
' the time of writing, the library for the RPCRT4.DLL seems broken and the linker fails.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetMACAddress () AS STRING
   ' // Generate a new guid
   DIM rguid AS UUID
   DIM AS ANY PTR pLib = DyLibLoad("RPCRT4.DLL")
   IF pLib = NULL THEN RETURN ""
   DIM pProc AS FUNCTION (BYVAL Uuid AS UUID PTR) AS RPC_STATUS
   pProc = DyLibSymbol(pLib, "UuidCreateSequential")
   IF pProc THEN pProc(@rguid)
   DyLibFree(pLib)
   ' //  Convert it to a string
   DIM pwsz AS WSTRING PTR
   StringFromIID(@rguid, CAST(LPOLESTR PTR, @pwsz))
   IF pwsz = NULL THEN RETURN ""
   DIM s AS STRING
   s = MID(*pwsz, 26, 12)
   CoTaskMemFree(pwsz)
   s = MID(s, 1, 2) & "-" & MID(s, 3, 2) & "-" & MID(s, 5, 2) & "-" & _
       MID(s, 7, 2) & "-" & MID(s, 9, 2) & "-" & MID(s, 11, 2)
   RETURN s
END FUNCTION
' ========================================================================================

' ========================================================================================
' Get the MAC address of the first valid physical adapter using GetAdaptersAddresses.
' This is the modern and Microsoft-recommended method.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetMACAddressEx () AS STRING
   DIM size AS ULONG
   ' // First call: Get the needed size
   GetAdaptersAddresses(AF_UNSPEC, _
                        GAA_FLAG_SKIP_ANYCAST OR GAA_FLAG_SKIP_MULTICAST OR _
                        GAA_FLAG_SKIP_DNS_SERVER OR GAA_FLAG_SKIP_FRIENDLY_NAME, _
                        NULL, NULL, @size)
   IF size = 0 THEN RETURN ""
   ' // Allocate buffer
   DIM pAddrs AS IP_ADAPTER_ADDRESSES PTR
   pAddrs = CAST(IP_ADAPTER_ADDRESSES PTR, Allocate(size))
   IF pAddrs = NULL THEN RETURN ""
   ' // Second call: get real data
   IF GetAdaptersAddresses(AF_UNSPEC, _
                           GAA_FLAG_SKIP_ANYCAST OR GAA_FLAG_SKIP_MULTICAST OR _
                           GAA_FLAG_SKIP_DNS_SERVER OR GAA_FLAG_SKIP_FRIENDLY_NAME, _
                           NULL, pAddrs, @size) <> 0 THEN
      Deallocate(pAddrs)
      RETURN ""
   END IF
   ' // Enumerate adapters
   DIM pCurr AS IP_ADAPTER_ADDRESSES PTR = pAddrs
   WHILE pCurr <> NULL
      ' // Ignore adapters with no MAC address or MAC addresses of length 0
      IF pCurr->PhysicalAddressLength >= 6 THEN
         ' Build the MAC address
         DIM mac AS STRING = ""
         FOR i AS LONG = 0 TO pCurr->PhysicalAddressLength - 1
            mac &= HEX(pCurr->PhysicalAddress(i), 2)
            IF i < pCurr->PhysicalAddressLength - 1 THEN mac &= "-"
         NEXT
         Deallocate(pAddrs)
         RETURN mac
      END IF
      pCurr = pCurr->Next
    WEND
    Deallocate(pAddrs)
    RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Populate a dynamic array of STRINGs with all the real MAC addresses of the system.
' The array is passed by reference and resized internally.
' Return value:
'    The number of elements in the array or -1 on failure.
' Usage example
'    DIM macs(ANY) AS STRING
'    DIM count AS LONG = CSysInfo.GetAllMACAddresses(macs())
'    FOR i AS LONG = LBOUND(macs) TO UBOUND(macs)
'      PRINT macs(i)
'    NEXT
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetAllMACAddresses (macs() AS STRING) AS LONG
   ERASE macs   ' In case it has previous contents
   DIM size AS ULONG = 0
   ' // First call: Get the needed size
   GetAdaptersAddresses(AF_UNSPEC, _
                        GAA_FLAG_SKIP_ANYCAST OR GAA_FLAG_SKIP_MULTICAST OR _
                        GAA_FLAG_SKIP_DNS_SERVER OR GAA_FLAG_SKIP_FRIENDLY_NAME, _
                        NULL, NULL, @size)
   IF size = 0 THEN RETURN -1
   ' // Allocate buffer
   DIM pAddrs AS IP_ADAPTER_ADDRESSES PTR
   pAddrs = CAST(IP_ADAPTER_ADDRESSES PTR, Allocate(size))
   IF pAddrs = NULL THEN RETURN -1
   ' // Second call: get real data
   IF GetAdaptersAddresses(AF_UNSPEC, _
                           GAA_FLAG_SKIP_ANYCAST OR GAA_FLAG_SKIP_MULTICAST OR _
                           GAA_FLAG_SKIP_DNS_SERVER OR GAA_FLAG_SKIP_FRIENDLY_NAME, _
                           NULL, pAddrs, @size) <> 0 THEN
      Deallocate(pAddrs)
      RETURN -1
   END IF
   DIM pCurr AS IP_ADAPTER_ADDRESSES PTR = pAddrs
   DIM count AS LONG = -1
   WHILE pCurr <> NULL
      IF pCurr->PhysicalAddressLength >= 6 THEN
         DIM s AS STRING = ""
         FOR i AS INTEGER = 0 TO pCurr->PhysicalAddressLength - 1
            s &= HEX(pCurr->PhysicalAddress(i), 2)
            IF i < pCurr->PhysicalAddressLength - 1 THEN s &= "-"
         NEXT
         count += 1
         REDIM PRESERVE macs(count)
         macs(count) = s
      END IF
      pCurr = pCurr->Next
    WEND
    Deallocate(pAddrs)
    RETURN count + 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Populate a dynamic array of STRINGs with all *real* MAC addresses (Ethernet/Wi-Fi).
' Filters out virtual adapters, tunnels, Bluetooth, Hyper-V, loopback, etc.
' Returns: Number of MACs found, or -1 on failure.
' Usage example:
'    DIM macs(ANY) AS STRING
'    DIM count AS LONG = CSysInfo.GetAllPhysicalMACAddresses(macs())
'    FOR i AS LONG = LBOUND(macs) TO UBOUND(macs)
'       PRINT macs(i)
'    NEXT
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetAllPhysicalMACAddresses (macs() AS STRING) AS LONG
   ERASE macs   ' In case it has previous contents
   DIM size AS ULONG
   ' // First call: get required buffer size
   GetAdaptersAddresses(AF_UNSPEC, _
                        GAA_FLAG_SKIP_ANYCAST OR GAA_FLAG_SKIP_MULTICAST OR _
                        GAA_FLAG_SKIP_DNS_SERVER OR GAA_FLAG_SKIP_FRIENDLY_NAME, _
                        NULL, NULL, @size)
   IF size = 0 THEN RETURN -1
   ' // Allocate buffer
   DIM pAddrs AS IP_ADAPTER_ADDRESSES PTR
   pAddrs = CAST(IP_ADAPTER_ADDRESSES PTR, Allocate(size))
   IF pAddrs = NULL THEN RETURN -1
   ' Second call: get actual data
   IF GetAdaptersAddresses(AF_UNSPEC, _
                           GAA_FLAG_SKIP_ANYCAST OR GAA_FLAG_SKIP_MULTICAST OR _
                           GAA_FLAG_SKIP_DNS_SERVER OR GAA_FLAG_SKIP_FRIENDLY_NAME, _
                           NULL, pAddrs, @size) <> 0 THEN
      Deallocate(pAddrs)
      RETURN -1
   END IF
   DIM pCurr AS IP_ADAPTER_ADDRESSES PTR = pAddrs
   DIM count AS LONG = -1
   WHILE pCurr <> NULL
      ' // Skip adapters without valid MAC
      IF pCurr->PhysicalAddressLength < 6 THEN
         pCurr = pCurr->Next
         CONTINUE WHILE
      END IF
      ' // Skip adapters that are not UP
      IF pCurr->OperStatus <> IfOperStatusUp THEN
         pCurr = pCurr->Next
         CONTINUE WHILE
      END IF
      ' // Skip virtual / tunnel / loopback / Bluetooth / Hyper-V
      SELECT CASE pCurr->IfType
         CASE IF_TYPE_SOFTWARE_LOOPBACK, _
              IF_TYPE_TUNNEL, _
              IF_TYPE_IEEE1394, _
              IF_TYPE_PROP_VIRTUAL
            pCurr = pCurr->Next
            CONTINUE WHILE
      END SELECT
      ' // Accept only Ethernet or Wi-Fi
      IF pCurr->IfType = IF_TYPE_ETHERNET_CSMACD OR _
         pCurr->IfType = IF_TYPE_IEEE80211 THEN
         DIM s AS STRING = ""
         FOR i AS INTEGER = 0 TO pCurr->PhysicalAddressLength - 1
            s &= HEX(pCurr->PhysicalAddress(i), 2)
            IF i < pCurr->PhysicalAddressLength - 1 THEN s &= "-"
         NEXT
         count += 1
         REDIM PRESERVE macs(count)
         macs(count) = s
      END IF
      pCurr = pCurr->Next
   WEND
   Deallocate(pAddrs)
   RETURN count + 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current Windows ANSI code page (ACP) identifier for the operating system.
' ========================================================================================
PRIVATE FUNCTION CSysInfo.GetACP () AS UINT
   RETURN ..GetACP
END FUNCTION
' ========================================================================================

END NAMESPACE
