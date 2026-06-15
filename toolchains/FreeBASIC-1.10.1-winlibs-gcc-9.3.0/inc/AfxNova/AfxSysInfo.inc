' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxSysInfo.inc
' Contents: System information wrapper functions
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2025 José Roca
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
#INCLUDE ONCE "win/winioctl.bi"
#INCLUDE ONCE "AfxNova/AfxWin.inc"
#INCLUDE ONCE "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' // Converts four characters into a little endian dword
' // Usage example:
' // DIM rsmb AS DWORD = MAKEFOURCCLE("RSMB")
' // Print HEX(rsmb, 8)  ' Output: &h52534D42
' ========================================================================================
#ifndef MAKEFOURCCLE
PRIVATE FUNCTION MAKEFOURCCLE (BYREF s AS STRING) AS DWORD
   IF LEN(s) <> 4 THEN RETURN 0   ' // input string must be exactly 4 characters
   ' Combine bytes in little-endian order
   RETURN ASC(MID(s, 4, 1)) OR _
          ASC(MID(s, 3, 1)) SHL 8 OR _
          ASC(MID(s, 2, 1)) SHL 16 OR _
          ASC(MID(s, 1, 1)) SHL 24
END FUNCTION
#endif
' ========================================================================================

' ========================================================================================
' // Converts four characters into a big endian dword
' // DIM rsmb AS DWORD = MAKEFOURCCBE("RSMB")
' // Print HEX(rsmb, 8)  ' Output: &h424D5352
' ========================================================================================
#ifndef MAKEFOURCCBE
PRIVATE FUNCTION MAKEFOURCCBE (BYREF s AS STRING) AS DWORD
   IF LEN(s) <> 4 THEN RETURN 0   ' // input string must be exactly 4 characters
   ' Combine bytes in big-endian order
   RETURN ASC(MID(s, 4, 1)) SHL 24 OR _
          ASC(MID(s, 3, 1)) SHL 16 OR _
          ASC(MID(s, 2, 1)) SHL 8 OR _
          ASC(MID(s, 1, 1))
END FUNCTION
#endif
' ========================================================================================

' ========================================================================================
' The raw SMBIOS table provider ('RSMB') retrieves the contents of the raw SMBIOS firmware
' table. The pFirmwareTableBuffer parameter of the GetSystemFirmwareTable function 
' receives the following data:
' ========================================================================================
#ifndef RawSMBIOSData
TYPE RawSMBIOSData
   Used20CallingMethod AS BYTE
   SMBIOSMajorVersion AS BYTE
   SMBIOSMinorVersion AS BYTE
   DmiRevision AS BYTE
   Length As DWORD
   SMBIOSTableData(0) AS BYTE
END TYPE
#endif

#ifndef RawSMBIOSTable
TYPE RawSMBIOSTable
   ' // Spec version 2.0+
   AS BYTE Type       ' // Offset 00h - Platform Firmware Information indicator
   AS BYTE Length     ' // Offset 01h - 12h + number of Firmware Characteristics Extension Bytes
   AS WORD Handle     ' // Offset 02h - Varies
END TYPE
#endif

' Type 0 - Firmware information
#ifndef RawSMBIOSBiosInfo
TYPE RawSMBIOSBiosInfo
   AS RawSMBIOSTable Header
   ' // Spec 2.0+
   AS BYTE Vendor               ' // Offset 04h - String number of the Firmware Vendor's Name
   AS BYTE Version              ' // Offset 05h - String number of the Firmware Version
   AS WORD StartingAddrSeg      ' // Offset 06h - Bios Starting Address Segment
   AS BYTE ReleaseDate          ' // Offset 08h - Firmware Release Date
   AS BYTE ROMSize              ' // Offset 09h - Firmware ROM Size
   AS ULONG64 Characteristics   ' // Offset 0Ah - Firmware Characteistics
   ' // Spec 2.4+
   AS BYTE Extension(1)         ' // Offset 12h - Firmware Characteristics Extension Bytes
   AS BYTE MajorRelease         ' // Offset 14h - Platform Firmare Major Release
   AS BYTE MinorRelease         ' // Offset 15h - Platform Firmare Minor Release
   AS BYTE ECFirmwareMajor      ' // Offset 16h - Embedded Controller Firmare Major Release
   AS BYTE ECFirmwareMinor      ' // Offset 17h - Embedded Controller Firmare Major Release
   ' // Spec 3.1+
   AS WORD EFROMSize            ' // Offset 18h - Extended Firmware ROM Size
END TYPE
#endif

' Type 1 - System information
#ifndef RawSMBIOSSystemInfo
TYPE RawSMBIOSSystemInfo
   ' // Spec 2.0+
   AS RawSMBIOSTable Header
   AS BYTE Manufacturer   ' // Offset 04h - Manufacturer
   AS BYTE ProductName    ' // Offset 05h - Product name
   AS BYTE Version        ' // Offset 06h - Version
   AS BYTE SerialNumber   ' // Offset 07h - Serial number
   ' // Spec 2.1+
   AS BYTE UUID(15)       ' // Offset 08h - 16 bytes - Universal unique ID number
   AS BYTE Wakeup_Type    ' // Offset 18h - Enum
   ' // Spec 2.4+
   AS BYTE SKUNumber      ' // Offset 19h - SKU Number
   AS BYTE Family         ' // Offset 1Ah - Family
END TYPE
#endif

' ########################################################################################
' CBiosTable class
' Loads and owns the SMBIOS memory block.
' ########################################################################################

' ========================================================================================
TYPE CBiosTable

   Private:
      m_pTable AS RawSMBIOSTable PTR   ' // Pointer to the raw firmware bios table
      m_pRaw AS RawSMBIOSData PTR      ' // Pointer to the persistent firmware bios data

   Public:
      DECLARE CONSTRUCTOR (BYVAL wantedType AS BYTE)
      DECLARE DESTRUCTOR ()
      DECLARE FUNCTION GetTable() AS RawSMBIOSTable PTR
      DECLARE FUNCTION FindTable (BYVAL wantedType AS BYTE) AS BOOLEAN
      DECLARE FUNCTION GetString (BYVAL index AS BYTE) AS DWSTRING

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CBiosTable class and retrieves the specified firmware table.
' ========================================================================================
PRIVATE CONSTRUCTOR CBiosTable (BYVAL wantedType AS BYTE)
   ' // Retrieve the system firmware table
   DIM size AS DWORD = GetSystemFirmwareTable(MAKEFOURCCLE("RSMB"), 0, 0, 0)
   IF size = 0 THEN EXIT CONSTRUCTOR
   ' // Allocate a buffer for the firmware table
   DIM pRoot AS ANY PTR = Allocate(size)
   IF pRoot = NULL THEN EXIT CONSTRUCTOR
   ' // Retrieves the specified firmware table from the firmware table provider
   IF GetSystemFirmwareTable(MAKEFOURCCLE("RSMB"), 0, pRoot, size) <> size THEN
      Deallocate(pRoot)
      EXIT CONSTRUCTOR
   END IF
   ' // Store the pointer to the persistent firmware bios data
   m_pRaw = CAST(RawSMBIOSData PTR, pRoot)
   ' // Find the address of the SMBIOS Table
   IF NOT this.FindTable(wantedType) THEN
      Deallocate(pRoot)
      EXIT CONSTRUCTOR
   END IF
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Deallocates the persistent firmware table data.
' ========================================================================================
PRIVATE DESTRUCTOR CBiosTable
    IF m_pRaw <> NULL THEN Deallocate(m_pRaw)
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns a pointer to the raw SMBIOS table.
' ========================================================================================
PRIVATE FUNCTION CBiosTable.GetTable() AS RawSMBIOSTable PTR
    RETURN m_pTable
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieve the RawSMBIOSTable pointer
' ========================================================================================
PRIVATE FUNCTION CBiosTable.FindTable (BYVAL wantedType AS BYTE) AS BOOLEAN
   IF m_pRaw = NULL THEN RETURN FALSE
   DIM pData AS BYTE PTR = @m_pRaw->SMBIOSTableData(0)
   DIM i AS LONG
   WHILE i < m_pRaw->Length
      DIM structType AS BYTE = pData[i]
      DIM structLength AS BYTE = pData[i + 1]
      IF structLength = 0 THEN EXIT WHILE  ' Corrupted data
      ' It is the type we are looking for?
      IF structType = wantedType THEN
         m_pTable = CAST(RawSMBIOSTable PTR, pData + i)
         RETURN TRUE
      END IF
      ' Advance to the strings section
      DIM pNext AS BYTE PTR = pData + i + structLength
      ' Skip strings until a double null is found
      WHILE (pNext[0] <> 0) OR (pNext[1] <> 0)
         pNext += 1
      WEND
      pNext += 2  ' Skip the double null
      i = pNext - pData
   WEND
   RETURN FALSE   ' Not found
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieve the SMBIOS string
' ========================================================================================
PRIVATE FUNCTION CBiosTable.GetString (BYVAL index AS BYTE) AS DWSTRING
   IF m_pTable = NULL THEN RETURN ""
   IF index = 0 THEN RETURN ""
   DIM pData AS BYTE PTR = cast(BYTE PTR, m_pTable)
   DIM structLength AS BYTE = m_pTable->Length
   ' First string immediately after the formatted part
   DIM pStr AS BYTE PTR = pData + structLength
   DIM current AS LONG = 1
   DIM result AS DWSTRING
   WHILE TRUE
      ' End of all strings? (double zero)
      IF pStr[0] = 0 AND pStr[1] = 0 THEN EXIT WHILE
      IF current = index THEN
         ' Extract string
         WHILE *pStr <> 0
            result += WCHR(*pStr)
            pStr += 1
         WEND
         RETURN result
      END IF
      ' Skip current string
      WHILE *pStr <> 0
         pStr += 1
      WEND
      ' Skip the terminating zero
      pStr += 1
      current += 1
   WEND
   RETURN ""
END FUNCTION
' ========================================================================================


' ########################################################################################

' ========================================================================================
' Generic SMBIOS string accessor: type + offset
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosString (BYVAL wantedType AS BYTE, BYVAL offset AS LONG) AS DWSTRING
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS RawSMBIOSTable PTR = pBios.GetTable
   IF pTable = NULL THEN RETURN ""
   DIM idx AS BYTE = CAST(BYTE PTR, pTable)[offset]
   IF idx = 0 THEN RETURN ""
   RETURN pBios.GetString(idx)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosByte OVERLOAD (BYVAL wantedType AS BYTE, BYVAL offset AS LONG) AS BYTE
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS BYTE PTR = CAST(BYTE PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   RETURN pTable[offset]
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosByte OVERLOAD (BYVAL wantedType AS BYTE, BYVAL offset AS LONG, BYVAL bitAnd AS BYTE) AS BYTE
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS BYTE PTR = CAST(BYTE PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   RETURN pTable[offset] AND bitAnd
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosUByte OVERLOAD (BYVAL wantedType AS BYTE, BYVAL offset AS LONG) AS UBYTE
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS UBYTE PTR = CAST(UBYTE PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   RETURN pTable[offset]
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosUByte OVERLOAD (BYVAL wantedType AS BYTE, BYVAL offset AS LONG, BYVAL bitAnd AS BYTE) AS UBYTE
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS UBYTE PTR = CAST(UBYTE PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   RETURN pTable[offset] AND bitAnd
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosWord OVERLOAD (BYVAL wantedType AS BYTE, BYVAL offset AS LONG) AS WORD
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS WORD PTR = CAST(WORD PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   RETURN pTable[offset]
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosDWord (BYVAL wantedType AS BYTE, BYVAL offset AS LONG) AS DWORD
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS DWORD PTR = CAST(DWORD PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   RETURN pTable[offset]
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosQWord (BYVAL wantedType AS BYTE, BYVAL offset AS LONG) AS ULONGINT
   DIM pBios AS CBiosTable = wantedType
   DIM pTable AS BYTE PTR = CAST(BYTE PTR, pBios.GetTable)
   IF pTable = NULL THEN RETURN 0
   ' 8 bytes (QWORD)
   DIM ch AS ULONGINT
   FOR i AS LONG = 0 TO 7
      ch OR= (CULNGINT(pTable[offset + i]) SHL (i * 8))
   NEXT
   RETURN ch
END FUNCTION
' ========================================================================================

' // Macros:

' --- Type 0: BIOS Information ---
#define SMBIOS_BIOSVendor               AfxGetBiosString(0, &h04)
#define SMBIOS_BIOSVersion              AfxGetBiosString(0, &h05)
#define SMBIOS_BIOSReleaseDate          AfxGetBiosString(0, &h08)
'#define SMBIOS_BiosROMSize              AfxGetBiosByte(0, &h09)
#define SMBIOS_FirmwareCharacteristics  AfxGetBiosQWord(0, &h0A)
'DIM ch AS ULONGINT = SMBIOS_FirmwareCharacteristics
'IF (ch AND &h0000000000000001ULL) THEN print "ISA supported"
'IF (ch AND &h0000000000000002ULL) THEN print "MCA supported"
'IF (ch AND &h0000000000000004ULL) THEN print "EISA supported"
'IF (ch AND &h0000000000000008ULL) THEN print "PCI supported"
'IF (ch AND &h0000000000000010ULL) THEN print "PCMCIA supported"
'IF (ch AND &h0000000000000020ULL) THEN print "Plug-and-Play supported"
'IF (ch AND &h0000000000000040ULL) THEN print "APM supported"
'IF (ch AND &h0000000000000080ULL) THEN print "BIOS upgradeable"
'IF (ch AND &h0000000000000100ULL) THEN print "BIOS shadowing allowed"
'IF (ch AND &h0000000000000200ULL) THEN print "VL-VESA supported"
'IF (ch AND &h0000000000000400ULL) THEN print "ESCD supported"
'IF (ch AND &h0000000000000800ULL) THEN print "Boot from CD supported"
'IF (ch AND &h0000000000001000ULL) THEN print "Selectable boot supported"
'IF (ch AND &h0000000000002000ULL) THEN print "BIOS ROM socketed"
'IF (ch AND &h0000000000004000ULL) THEN print "Boot from PCMCIA supported"
'IF (ch AND &h0000000000008000ULL) THEN print "EDD supported"
'IF (ch AND &h0000000000010000ULL) THEN print "Japanese floppy supported"
'IF (ch AND &h0000000000020000ULL) THEN print "NEC floppy supported"
'IF (ch AND &h0000000000040000ULL) THEN print "LS-120 supported"
'IF (ch AND &h0000000000080000ULL) THEN print "ATAPI ZIP supported"
'IF (ch AND &h0000000000100000ULL) THEN print "Boot from IEEE1394 supported"
'IF (ch AND &h0000000000200000ULL) THEN print "Smart battery supported"

' --- Type 1: System Information ---
#define SMBIOS_SystemManufacturer       AfxGetBiosString(1, &h04)
#define SMBIOS_SystemProductName        AfxGetBiosString(1, &h05)
#define SMBIOS_SystemVersion            AfxGetBiosString(1, &h06)
#define SMBIOS_SystemSerialNumber       AfxGetBiosString(1, &h07)
#define SMBIOS_SystemSKUNumber          AfxGetBiosString(1, &h19)
#define SMBIOS_SystemFamily             AfxGetBiosString(1, &h1A)
#define SMBIOS_WakeupType               AfxGetBiosByte(1, 18)
' ========================================================================================
' BIOS Characteristics Extension Bytes (Type 0, offsets 12h y 13h)
' ========================================================================================
#define SMBIOS_BIOSCharacteristicsExt1  AfxGetBiosByte(0, &h12)
' ========================================================================================
'IF (b AND &h01) THEN print "ACPI supported"
'IF (b AND &h02) THEN print "USB legacy supported"
'IF (b AND &h04) THEN print "AGP supported"
'IF (b AND &h08) THEN print "I2O boot supported"
'IF (b AND &h10) THEN print "LS-120 boot supported"
'IF (b AND &h20) THEN print "ATAPI ZIP boot supported"
'IF (b AND &h40) THEN print "1394 boot supported"
'IF (b AND &h80) THEN print "Smart battery supported"
' ========================================================================================
#define SMBIOS_BIOSCharacteristicsExt2  AfxGetBiosByte(0, &h13)
' ========================================================================================
'IF (b AND &h01) THEN print "BIOS boot spec supported"
'IF (b AND &h02) THEN print "Function key-initiated network boot supported"
'IF (b AND &h04) THEN print "Targeted content distribution supported"
'IF (b AND &h08) THEN print "UEFI supported"
'IF (b AND &h10) THEN print "SMBIOS table describes virtual machine"
' ========================================================================================
PRIVATE FUNCTION BIOS_SystemUUID () AS STRING
   DIM pBios AS CBiosTable = 1
   DIM pTable AS RawSMBIOSTable PTR = pBios.GetTable
   IF pTable = NULL THEN RETURN ""
   DIM p AS BYTE PTR = CAST(BYTE PTR, pTable) + &h08
   ' SMBIOS UUID is 16 bytes
   DIM uuid AS STRING
   FOR i AS LONG = 0 TO 15
      uuid &= HEX(p[i], 2)
      IF i = 3 OR i = 5 OR i = 7 OR i = 9 THEN uuid &= "-"
   NEXT
   RETURN uuid
END FUNCTION
' ========================================================================================

' --- Type 2: Baseboard ---
#define SMBIOS_BaseBoardManufacturer  AfxGetBiosString(2, &h04)
#define SMBIOS_BaseBoardProduct       AfxGetBiosString(2, &h05)
#define SMBIOS_BaseBoardVersion       AfxGetBiosString(2, &h06)
#define SMBIOS_BaseBoardSerialNumber  AfxGetBiosString(2, &h07)
#define SMBIOS_BaseBoardAssetTag      AfxGetBiosString(2, &h08)

' --- Type 3: Chassis ---
#define SMBIOS_ChassisManufacturer    AfxGetBiosString(3, &h04)
#define SMBIOS_ChassisVersion         AfxGetBiosString(3, &h06)
#define SMBIOS_ChassisSerialNumber    AfxGetBiosString(3, &h07)
#define SMBIOS_ChassisAssetTag        AfxGetBiosString(3, &h08)
#define SMBIOS_ChassisType            AfxGetBiosByte(3, &h05, &h7F)   ' bits 0-6
#define SMBIOS_ChassisLockPresent     AfxGetBiosByte(3, &h05, &h80)   ' bit 7

' --- Type 4: Processor ---
#define SMBIOS_ProcessorSocket        AfxGetBiosString(4, &h04)
#define SMBIOS_ProcessorType          AfxGetBiosByte(4, &h05)
#define SMBIOS_ProcessorFamily        AfxGetBiosUByte(4, &h06)
#define SMBIOS_ProcessorManufacturer  AfxGetBiosString(4, &h07)
#define SMBIOS_ProcessorID            AfxGetBiosQWord(4, &h08)
#define SMBIOS_ProcessorVersion       AfxGetBiosString(4, &h10)
'#define SMBIOS_ProcessorVoltage       AfxGetBiosUByte(4, &h11)   ' // deprecated
'#define SMBIOS_ProcessorExternalClock AfxGetBiosWord(4, &h12)
'#define SMBIOS_ProcessorMaxSpeed      AfxGetBiosWord(4, &h14)
'#define SMBIOS_ProcessorCurrentSpeed  AfxGetBiosWord(4, &h16)
'#define SMBIOS_ProcessorSerialNumber  AfxGetBiosString(4, &h20)
'#define SMBIOS_ProcessorAssetTag      AfxGetBiosString(4, &h21)
'#define SMBIOS_ProcessorPartNumber    AfxGetBiosString(4, &h22)
'#define SMBIOS_ProcessorCoreCount     AfxGetBiosByte(4, &h23)
'#define SMBIOS_ProcessorThreadCount   AfxGetBiosByte(4, &h25)

' --- Type 17: Memory Device ---
'#define SMBIOS_MemoryDeviceLocator       AfxGetBiosString(17, &h10)
'#define SMBIOS_MemoryDeviceBankLocator   AfxGetBiosString(17, &h11)
'#define SMBIOS_MemoryDeviceManufacturer  AfxGetBiosString(17, &h17)
'#define SMBIOS_MemoryDeviceSerialNumber  AfxGetBiosString(17, &h18)
''#define SMBIOS_MemoryDeviceAssetTag      AfxGetBiosString(17, &h19)
'#define SMBIOS_MemoryDevicePartNumber    AfxGetBiosString(17, &h1A)


' ########################################################################################
'                    *** IOCTL - Device Input and Output Control ***
' ########################################################################################

' ========================================================================================
' Retrieves the number of cylinders of the specified disk.
' Parameter: wszPath = Drive to open.
' Usage example: DIM cylinders AS LONGLONG = IOCTL_GetCylinders("//./PhysicalDrive0")
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetCylinders (BYREF wszPath AS WSTRING = "//./PhysicalDrive0") AS LONGLONG

   DIM hDevice AS HANDLE   ' // handle to the drive to be examined
   hDevice = CreateFileW (wszPath, _                              ' // drive to open
                         0, _                                     ' // no access to the drive
                         FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                         NULL, _                                  ' // default security attributes
                         OPEN_EXISTING, _                         ' // disposition
                         0, _                                     ' // file attributes
                         NULL _                                   ' // do not copy file attributes
                         )

   DIM pdg AS DISK_GEOMETRY_EX, bytesReturned AS DWORD
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN 0

   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, _            ' // device to be queried
                            IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, _   ' // operation to perform
                            NULL, 0, _                            ' // no input buffer
                            @pdg, sizeof(pdg), _                  ' // output buffer
                            @bytesReturned, _                     ' // # bytes returned
                            NULL)                                 ' // synchronous I/O
   CloseHandle(hDevice)
   RETURN pdg.Geometry.Cylinders.QuadPart

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size of the specified disk.
' Parameter: wszPath = Drive to open.
' Return value: The disk size
' Usage example: DIM diskSize AS LONGLONG = IOCTL_GetDiskSize("//./PhysicalDrive0")
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetDiskSize (BYREF wszPath AS WSTRING = "//./PhysicalDrive0") AS LONGLONG

   DIM hDevice AS HANDLE   ' // handle to the drive to be examined
   hDevice = CreateFileW (wszPath, _                              ' // drive to open
                         0, _                                     ' // no access to the drive
                         FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                         NULL, _                                  ' // default security attributes
                         OPEN_EXISTING, _                         ' // disposition
                         0, _                                     ' // file attributes
                         NULL _                                   ' // do not copy file attributes
                         )
   DIM pdg AS DISK_GEOMETRY_EX, bytesReturned AS DWORD
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN 0
   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, _            ' // device to be queried
                            IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, _   ' // operation to perform
                            NULL, 0, _                            ' // no input buffer
                            @pdg, sizeof(pdg), _                  ' // output buffer
                            @bytesReturned, _                     ' // # bytes returned
                            NULL)                                 ' // synchronous I/O
   CloseHandle(hDevice)
   RETURN pdg.DiskSize.QuadPart

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of media.
' Parameter: wszPath = Drive to open.
' Return value: The type od media.
' Usage example: DIM mt AS MEDIA_TYPE = IOCTL_GetMediaType("//./PhysicalDrive0")
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetMediaType (BYREF wszPath AS WSTRING = "//./PhysicalDrive0") AS MEDIA_TYPE

   DIM hDevice AS HANDLE   ' // handle to the drive to be examined
   hDevice = CreateFileW (wszPath, _                              ' // drive to open
                         0, _                                     ' // no access to the drive
                         FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                         NULL, _                                  ' // default security attributes
                         OPEN_EXISTING, _                         ' // disposition
                         0, _                                     ' // file attributes
                         NULL _                                   ' // do not copy file attributes
                         )
   DIM pdg AS DISK_GEOMETRY_EX, bytesReturned AS DWORD
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN 0
   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, _            ' // device to be queried
                            IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, _   ' // operation to perform
                            NULL, 0, _                            ' // no input buffer
                            @pdg, sizeof(pdg), _                  ' // output buffer
                            @bytesReturned, _                     ' // # bytes returned
                            NULL)                                 ' // synchronous I/O
   CloseHandle(hDevice)
   RETURN pdg.Geometry.MediaType

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of tracks per cylinder.
' Parameter: wszPath = Drive to open.
' Return value: The tracks per cylinder
' Usage example: DIM tpc AS DWORD = IOCTL_GetTracksPerCylinder("//./PhysicalDrive0")
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetTracksPerCylinder (BYREF wszPath AS WSTRING = "//./PhysicalDrive0") AS DWORD

   DIM hDevice AS HANDLE   ' // handle to the drive to be examined
   hDevice = CreateFileW (wszPath, _                              ' // drive to open
                         0, _                                     ' // no access to the drive
                         FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                         NULL, _                                  ' // default security attributes
                         OPEN_EXISTING, _                         ' // disposition
                         0, _                                     ' // file attributes
                         NULL _                                   ' // do not copy file attributes
                         )
   DIM pdg AS DISK_GEOMETRY_EX, bytesReturned AS DWORD
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN 0
   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, _            ' // device to be queried
                            IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, _   ' // operation to perform
                            NULL, 0, _                            ' // no input buffer
                            @pdg, sizeof(pdg), _                  ' // output buffer
                            @bytesReturned, _                     ' // # bytes returned
                            NULL)                                 ' // synchronous I/O
   CloseHandle(hDevice)
   RETURN pdg.Geometry.TracksPerCylinder

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of sectors per track
' Parameter: wszPath = Drive to open.
' Return value: The number of sectors per track.
' Usage example: DIM spt AS DWORD = IOCTL_GetSectorsPerTrack("//./PhysicalDrive0")
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetSectorsPerTrack (BYREF wszPath AS WSTRING = "//./PhysicalDrive0") AS DWORD

   DIM hDevice AS HANDLE   ' // handle to the drive to be examined
   hDevice = CreateFileW (wszPath, _                              ' // drive to open
                         0, _                                     ' // no access to the drive
                         FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                         NULL, _                                  ' // default security attributes
                         OPEN_EXISTING, _                         ' // disposition
                         0, _                                     ' // file attributes
                         NULL _                                   ' // do not copy file attributes
                         )
   DIM pdg AS DISK_GEOMETRY_EX, bytesReturned AS DWORD
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN 0
   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, _            ' // device to be queried
                            IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, _   ' // operation to perform
                            NULL, 0, _                            ' // no input buffer
                            @pdg, sizeof(pdg), _                  ' // output buffer
                            @bytesReturned, _                     ' // # bytes returned
                            NULL)                                 ' // synchronous I/O
   CloseHandle(hDevice)
   RETURN pdg.Geometry.SectorsPerTrack

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of bytes per sector.
' Parameter: wszPath = Drive to open.
' Return value: The number of bytes per sector.
' Usage example: DIM bps AS DWORD = IOCTL_GetBytesPerSector("//./PhysicalDrive0")
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetBytesPerSector (BYREF wszPath AS WSTRING = "//./PhysicalDrive0") AS DWORD

   DIM hDevice AS HANDLE   ' // handle to the drive to be examined
   hDevice = CreateFileW (wszPath, _                              ' // drive to open
                         0, _                                     ' // no access to the drive
                         FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                         NULL, _                                  ' // default security attributes
                         OPEN_EXISTING, _                         ' // disposition
                         0, _                                     ' // file attributes
                         NULL _                                   ' // do not copy file attributes
                         )
   DIM pdg AS DISK_GEOMETRY_EX, bytesReturned AS DWORD
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN 0
   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, _            ' // device to be queried
                            IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, _   ' // operation to perform
                            NULL, 0, _                            ' // no input buffer
                            @pdg, sizeof(pdg), _                  ' // output buffer
                            @bytesReturned, _                     ' // # bytes returned
                            NULL)                                 ' // synchronous I/O
   CloseHandle(hDevice)
   RETURN pdg.Geometry.BytesPerSector

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieve STORAGE_DEVICE_DESCRIPTOR using the IOCTL_STORAGE_QUERY_PROPERTY
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetStorageDeviceDescriptor (BYREF wszFileName AS WSTRING = "//./PhysicalDrive0") AS PSTORAGE_DEVICE_DESCRIPTOR

   DIM hDevice AS HANDLE = CreateFileW(wszFileName, _                          ' // device to open
                                       0, _                                     ' // no access to the drive
                                       FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                                       NULL, _                                  ' // default security attributes
                                       OPEN_EXISTING, _                         ' // disposition
                                       0, _                                     ' // file attributes
                                       NULL _                                   ' // do not copy file attributes
                                       )
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN NULL

   DIM query AS STORAGE_PROPERTY_QUERY
   query.PropertyId = StorageDeviceProperty
   query.QueryType = PropertyStandardQuery

   ' // First call: get the need size for the full descriptor
   DIM header AS STORAGE_DESCRIPTOR_HEADER
   DIM bytesReturned AS DWORD
   DIM bResult AS BOOLEAN = DeviceIoControl (hDevice, IOCTL_STORAGE_QUERY_PROPERTY, _
                                             @query, sizeof(query), _
                                             @header, sizeof(header), _
                                             @bytesReturned, NULL)
   IF bResult = FALSE THEN
      CloseHandle(hDevice)
      RETURN NULL
   END IF

   ' // Allocate the device descriptor
   DIM pDesc AS PSTORAGE_DEVICE_DESCRIPTOR = cast(PSTORAGE_DEVICE_DESCRIPTOR, Allocate(header.Size))
   ' // Second call: Get the descriptor
   bResult = DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, _
                             @query, sizeof(query), _
                             pDesc, header.Size, _
                             @bytesReturned, NULL)
   CloseHandle(hDevice)
   RETURN pDesc

END FUNCTION
' ========================================================================================
' ========================================================================================
' Retrieve the string stored at the specified offset of the STORAGE_DEVICE_DESCRIPTOR stucture.
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetStorageDeviceDescriptorString (BYVAL desc AS PSTORAGE_DEVICE_DESCRIPTOR, BYVAL offset AS DWORD) AS STRING
   IF offset = 0 THEN RETURN ""
   DIM pstr AS ZSTRING PTR = cast(ZSTRING PTR, cast(BYTE PTR, desc) + offset)
   IF pstr THEN RETURN *pstr
END FUNCTION
' ========================================================================================

' Usage example:

'DIM d AS PSTORAGE_DEVICE_DESCRIPTOR
'd = IOCTL_GetStorageDeviceDescriptor("//./PhysicalDrive0")

'IF d <> 0 THEN
'   print "Vendor: "; IOCTL_GetStorageDeviceDescriptorString(d, d->VendorIdOffset)
'   print "Product: "; IOCTL_GetStorageDeviceDescriptorString(d, d->ProductIdOffset)
'   print "Serial: "; IOCTL_GetStorageDeviceDescriptorString(d, d->SerialNumberOffset)
'   print "BusType: "; d->BusType
'   ' // Deallocate the STORAGE_DEVICE_DESCRIPTOR structure
'   Deallocate(d)
'END IF

' ========================================================================================
' Retrieves the serial number of the specified device.
' wszPath: The name of the file or device to be created or opened.
'          You may use either forward slashes (/) or backslashes (\) in this name.
' - Drives  : "//./PhysicalDrive0" -> "//./C:"
'             "//./PhysicalDrive1" -> "//./D:"
' - Volumes : "//./C:"
' - Drivers : "//./DriverName"
' Return value:
'   The retrieved serial number on success or an empty string om failure.
'   To retrieve an error code, use GetLastError.
'   To retrieve a localized error code, use AfxGetWinErrMsg(GetLastError).
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetDeviceSerialNumber (BYREF wszFileName AS WSTRING = "//./PhysicalDrive0") AS STRING

   DIM hDevice AS HANDLE = CreateFileW(wszFileName, _                           ' // device to open
                                       0, _                                     ' // no access to the drive
                                       FILE_SHARE_READ OR FILE_SHARE_WRITE, _   ' // share mode
                                       NULL, _                                  ' // default security attributes
                                       OPEN_EXISTING, _                         ' // disposition
                                       0, _                                     ' // file attributes
                                       NULL _                                   ' // do not copy file attributes
                                       )
   IF hDevice = INVALID_HANDLE_VALUE THEN RETURN ""

   DIM query AS STORAGE_PROPERTY_QUERY
   query.PropertyId = StorageDeviceProperty
   query.QueryType = PropertyStandardQuery

   ' // First call: get the need size for the full descriptor
   DIM header AS STORAGE_DESCRIPTOR_HEADER
   DIM bytesReturned AS DWORD
   DIM bResult AS BOOLEAN = DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, _
                                            @query, sizeof(query), _
                                            @header, sizeof(header), _
                                            @bytesReturned, NULL)
   IF bResult = FALSE THEN
      CloseHandle(hDevice)
      RETURN ""
   END IF

   ' // Allocate the device descriptor
   DIM pDesc AS PSTORAGE_DEVICE_DESCRIPTOR = cast(PSTORAGE_DEVICE_DESCRIPTOR, Allocate(header.Size))
   ' // Second call: Get the descriptor
   bResult = DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, _
                             @query, sizeof(query), _
                             pDesc, header.Size, _
                             @bytesReturned, NULL)
   CloseHandle(hDevice)
   IF bResult = FALSE THEN RETURN ""
   IF pDesc->SerialNumberOffset = 0 THEN RETURN ""

   ' // Retrieve the string
   DIM serialNumber AS STRING
   DIM pstr AS ZSTRING PTR = cast(ZSTRING PTR, cast(BYTE PTR, pDesc) + pDesc->SerialNumberOffset)
   IF pstr THEN serialNumber = *pstr
   Deallocate(pDesc)
   RETURN serialNumber

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the physical location of a specified volume on one or more disks.
' wszVolume: Volume path, e.g. "//./C:"
' Returns: Disk number on success, or -1 on failure.
' Usage example:
' DIM disk AS LONG = IOCTL_GetVolumeDiskNumber("//./C:")
' PRINT "C: is in PhysicalDrive" & STR(disk)
' ========================================================================================
PRIVATE FUNCTION IOCTL_GetVolumeDiskNumber (BYREF wszVolume AS WSTRING) AS LONG

   DIM hVolume AS HANDLE = CreateFileW (wszVolume, _
                                        0, _
                                        FILE_SHARE_READ OR FILE_SHARE_WRITE, _
                                        NULL, _
                                        OPEN_EXISTING, _
                                        0, _
                                        NULL )
   IF hVolume = INVALID_HANDLE_VALUE THEN RETURN -1

    ' // First try with a small buffer
    DIM smallBuf AS VOLUME_DISK_EXTENTS
    DIM bytesReturned AS DWORD

    DIM bResult AS BOOLEAN = DeviceIoControl (hVolume, IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS, _
                                              NULL, 0, _
                                              @smallBuf, sizeof(smallBuf), _
                                              @bytesReturned, NULL )
    IF bResult = FALSE THEN
        CloseHandle(hVolume)
        RETURN -1
    END IF

    ' // If only one extent, no need to allocate more
    IF smallBuf.NumberOfDiskExtents = 1 THEN
        CloseHandle(hVolume)
        RETURN smallBuf.Extents(0).DiskNumber
    END IF

    ' // Allocate buffer for multiple extents
    DIM bufSize AS DWORD = sizeof(VOLUME_DISK_EXTENTS) + _
                           (smallBuf.NumberOfDiskExtents - 1) * sizeof(DISK_EXTENT)
    DIM pExt AS VOLUME_DISK_EXTENTS PTR = cast(VOLUME_DISK_EXTENTS PTR, Allocate(bufSize))
    bResult = DeviceIoControl( hVolume, IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS, _
                               NULL, 0, _
                               pExt, bufSize, _
                               @bytesReturned, NULL )
    CloseHandle(hVolume)
    IF bResult = FALSE THEN
        Deallocate(pExt)
        RETURN -1
    END IF

    DIM diskNum AS LONG = pExt->Extents(0).DiskNumber
    Deallocate(pExt)
    RETURN diskNum

END FUNCTION
' ========================================================================================

END NAMESPACE
