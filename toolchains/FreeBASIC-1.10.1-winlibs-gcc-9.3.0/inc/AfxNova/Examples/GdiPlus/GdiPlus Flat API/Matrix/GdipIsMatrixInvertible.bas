' ########################################################################################
' Microsoft Windows
' File: GdipIsMatrixInvertible.bas
' Contents: GDI+ Flat API - GdipIsMatrixInvertible example
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
' Determines whether a matrix is invertible.
' ========================================================================================

DIM hStatus AS LONG

' // Initialize GDI+
DIM token AS ULONG_PTR = AfxGdipInit

' // Create the matrix
DIM matrix AS GpMatrix PTR
hStatus = GdipCreateMatrix2(3.0, 0.0, 0.0, 2.0, 20.0, 10.0, @matrix)

DIM result AS BOOL
hStatus = GdipIsMatrixInvertible(matrix, @result)
IF result THEN PRINT "The matrix is invertible"  ELSE PRINT "The matrix is not invertible"

' // Cleanup
IF matrix THEN GdipDeleteMatrix(matrix)

' // Shutdown GDI+
AfxGdipShutdown token

PRINT
PRINT "Press any key"
SLEEP

' ========================================================================================
