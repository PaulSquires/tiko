' ########################################################################################
' Microsoft Windows
' File: GdipIsMatrixEqual.bas
' Contents: GDI+ Flat API - GdipIsMatrixEqual example
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
' Determines whether the elements of a matrix are equal to the elements of another matrix.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create the matrices
DIM matrix AS GpMatrix PTR
hStatus = GdipCreateMatrix2(1, 2, 1, 1, 2, 2, @matrix)

DIM matrix2 AS GpMatrix PTR
hStatus = GdipCreateMatrix2(1, 2, 1, 1, 2, 2, @matrix2)

DIM result AS BOOL
hStatus = GdipIsMatrixEqual(matrix, matrix2, @result)
IF result THEN PRINT "They are the same"  ELSE PRINT "They are the different"

' // Cleanup
IF matrix THEN GdipDeleteMatrix(matrix)
IF matrix2 THEN GdipDeleteMatrix(matrix2)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
