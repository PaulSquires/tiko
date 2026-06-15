' ########################################################################################
' Microsoft Windows
' File: GdipEmfToWmfBits.bas
' Contents: GDI+ Flat API - GdipEmfToWmfBits example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2025 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#cmdline "-s console"
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"

' ========================================================================================
' Convert EMF to a WMF bitstream.
' It operates directly on a Windows HENHMETAFILE handle.
' This example loads an EMF file, converts it to WMF bits using GdipEmfToWmfBits,
' and writes the result to a WMF file.
' GetEnhMetaFileW does no work with EMF+ files.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

DIM hemf AS HENHMETAFILE
DIM cbData16 AS UINT
DIM result AS UINT

' // Load the EMF file
hemf = GetEnhMetaFileW("EMF13.emf")
IF hemf = NULL THEN
   PRINT "Failed to load EMF file"
   SLEEP
   END
END IF

' // First call to get required buffer size
cbData16 = GdipEmfToWmfBits(hemf, 0, NULL, MM_ANISOTROPIC, EmfToWmfBitsFlagsDefault)

' // Allocate buffer
DIM pData16 AS UBYTE PTR = CAllocate(cbData16)

' // Convert EMF to WMF bits
result = GdipEmfToWmfBits(hemf, cbData16, pData16, MM_ANISOTROPIC, EmfToWmfBitsFlagsDefault)

' // Write to WMF file
DIM hFile AS HANDLE = CreateFile("output.wmf", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
IF hFile <> INVALID_HANDLE_VALUE THEN
   DIM bytesWritten AS DWORD
   WriteFile(hFile, pData16, result, @bytesWritten, NULL)
   CloseHandle(hFile)
   PRINT "WMF file written successfully."
ELSE
   PRINT "Failed to create WMF file."
END IF

' // Cleanup
IF pData16 THEN DEALLOCATE(pData16)
IF hemf THEN DeleteEnhMetaFile(hemf)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
