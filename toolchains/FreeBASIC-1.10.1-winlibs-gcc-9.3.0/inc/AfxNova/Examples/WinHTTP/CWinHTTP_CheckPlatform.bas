' ########################################################################################
' Microsoft Windows
' Contents: CWinHttpRequest - CheckPlatform
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' The following example checks if the current platform is supported.
' ========================================================================================

#cmdline "-s console"
#include once "AfxNova/CWinHttpRequest.inc"
using AfxNova

IF AfxWinHttpCheckPlatform THEN
   PRINT "This platform is supported by WinHTTP."
ELSE
   PRINT "This platform is NOT supported by WinHTTP."
END IF

PRINT
PRINT "Press any key..."
SLEEP
