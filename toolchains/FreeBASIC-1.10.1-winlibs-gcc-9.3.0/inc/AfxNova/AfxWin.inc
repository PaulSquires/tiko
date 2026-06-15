' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxWin.inc
' Purpose:  Assorted Windows wrapper functions
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
#INCLUDE ONCE "win/commctrl.bi"
#INCLUDE ONCE "win/ole2.bi"
#INCLUDE ONCE "win/psapi.bi"
#INCLUDE ONCE "win/shlobj.bi"
#INCLUDE ONCE "win/KnownFolders.bi"
#INCLUDE ONCE "win/commdlg.bi"
#INCLUDE ONCE "win/cderr.bi"
#INCLUDE ONCE "crt/string.bi"
#INCLUDE ONCE "win/wincrypt.bi"
#INCLUDE ONCE "win/iphlpapi.bi"
#INCLUDE ONCE "win/wininet.bi"
#INCLUDE ONCE "AfxNova/DWSTRProcs.inc"
#INCLUDE ONCE "AfxNova/AfxPath.inc"
#INCLUDE ONCE "AfxNova/AfxTime.inc"
'#INCLUDE ONCE "AfxNova/AfxWsh.inc"   ' Don't include it; creates a circular dependency
#INCLUDE ONCE "AfxNova/AfxExt.bi"   ' // Windows API extensions
USING AfxNova

' // The linker fails when calling GetUserNameExW because the function is not exported by libsecur32.dll.a
DECLARE FUNCTION __GetUserNameExW LIB "secur32.dll" ALIAS "GetUserNameExW" (BYVAL NameFormat AS LONG, BYVAL lpNameBuffer AS LPWSTR, BYVAL nSize AS PULONG) as BOOLEAN

NAMESPACE AfxNova

' ========================================================================================
' Enables visual styles without using a manifest in the application.
' ========================================================================================
PRIVATE FUNCTION AfxEnableVisualStyles () AS BOOLEAN

   ' // Fill the ACTCTXW structure
   DIM actCtx AS ACTCTXW
   actCtx.cbSize = SIZEOF(ACTCTXW)
   actCtx.dwFlags = ACTCTX_FLAG_RESOURCE_NAME_VALID OR ACTCTX_FLAG_SET_PROCESS_DEFAULT OR ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID

   ' // Get system directory
   DIM systemDir AS WSTRING * MAX_PATH
   DIM cch AS UINT = GetSystemDirectoryW(@systemDir, MAX_PATH)
   IF cch >= MAX_PATH THEN RETURN FALSE  ' Ensure buffer is not exceeded
   systemDir[cch] = ASC("\")  ' Append backslash
   actCtx.lpAssemblyDirectory = @systemDir
   DIM wszSource AS WSTRING * MAX_PATH = systemDir & "shell32.dll"
   actCtx.lpSource = CAST(WSTRING PTR, @wszSource)  ' Use shell32.dll's manifest
   actCtx.lpResourceName = CAST(WSTRING PTR, 124)   ' Resource ID for the manifest (IDR_MANIFEST = 1, RT_MANIFEST = 24)

   ' // Create the activation context
   DIM hActCtx AS HANDLE = CreateActCtxW(@actCtx)
   IF hActCtx = INVALID_HANDLE_VALUE THEN RETURN FALSE

   ' // Activate the context
   DIM activationCookie AS ULONG_PTR
   ActivateActCtx(hActCtx, @activationCookie)

   ' // Deactivate and release the context
   DeactivateActCtx(0, activationCookie)
   ReleaseActCtx(hActCtx)
   RETURN TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' * Helper procedures to display feedback and errors
' The Windows API MessageBox can be used instead.
' ========================================================================================
PRIVATE FUNCTION AfxMsg OVERLOAD (BYREF wszText AS WSTRING, BYREF wszCaption AS WSTRING = "Message", BYVAL uType AS DWORD = 0) AS LONG
   RETURN MessageBoxW(GetActiveWindow, @wszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION AfxMsg OVERLOAD (BYVAL pwszText AS WSTRING PTR, BYREF wszCaption AS WSTRING = "Message", BYVAL uType AS DWORD = 0) AS LONG
   RETURN MessageBoxW(GetActiveWindow, pwszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION AfxMsg OVERLOAD (BYVAL hWin AS HWND, BYREF wszText AS WSTRING, BYREF wszCaption AS WSTRING = "Message", BYVAL uType AS DWORD = 0) AS LONG
   RETURN MessageBoxW(hWin, @wszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxMsg OVERLOAD (BYVAL hWin AS HWND, BYVAL pwszText AS WSTRING PTR, BYREF wszCaption AS WSTRING = "Message", BYVAL uType AS DWORD = 0) AS LONG
   RETURN MessageBoxW(hWin, pwszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================

' ========================================================================================
'PowerBasic's MsgBox has the style and c aption parameters reversed
' ========================================================================================
PRIVATE FUNCTION MsgBox OVERLOAD (BYREF wszText AS WSTRING, BYVAL uType AS DWORD = 0, BYREF wszCaption AS WSTRING = "Message") AS LONG
   RETURN MessageBoxW(GetActiveWindow, @wszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION MsgBox OVERLOAD (BYVAL pwszText AS WSTRING PTR, BYVAL uType AS DWORD = 0, BYREF wszCaption AS WSTRING = "Message") AS LONG
   RETURN MessageBoxW(GetActiveWindow, pwszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================
' ========================================================================================
' PowerBasic has no parameter for the parent window.
' ========================================================================================
PRIVATE FUNCTION MsgBox OVERLOAD (BYVAL hwnd AS HWND, BYREF wszText AS WSTRING, BYVAL uType AS DWORD = 0, BYREF wszCaption AS WSTRING = "Message") AS LONG
   RETURN MessageBoxW(hWnd, @wszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION MsgBox OVERLOAD (BYVAL hwnd AS HWND, BYREF pwszText AS WSTRING PTR, BYVAL uType AS DWORD = 0, BYREF wszCaption AS WSTRING = "Message") AS LONG
   RETURN MessageBoxW(hWnd, pwszText, @wszCaption, MB_APPLMODAL OR uType)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates, displays, and operates a task dialog.
' Needed if we use AfxEnableVisualStyles instead of a manifest.
' Otherwise, the linker will search the function in comctl32.dll version 5 instead of 6
' and it will fail because it does not exist in versions prior to 6.
' ========================================================================================
#if _WIN32_WINNT >= &h0600
PRIVATE FUNCTION AfxTaskDialog (BYVAL hwndOwner AS HWND, BYVAL hInst AS HINSTANCE, BYVAL pwszWindowTitle AS PCWSTR, BYVAL pwszMainInstruction AS PCWSTR, BYVAL pwszContent AS PCWSTR, BYVAL dwCommonButtons AS TASKDIALOG_COMMON_BUTTON_FLAGS, BYVAL pwszIcon AS PCWSTR, BYVAL pnButton AS LONG PTR) AS HRESULT
   DIM hLib AS HMODULE = LoadLibraryW("comctl32.dll")
   IF hLib = NULL THEN RETURN HRESULT_FROM_WIN32(GetLastError)
   DIM pfnTaskDialog AS FUNCTION (BYVAL hwndOwner AS HWND, BYVAL hInst AS HINSTANCE, BYVAL pwszWindowTitle AS PCWSTR, BYVAL pwszMainInstruction AS PCWSTR, BYVAL pwszContent AS PCWSTR, BYVAL dwCommonButtons AS TASKDIALOG_COMMON_BUTTON_FLAGS, BYVAL pwszIcon AS PCWSTR, BYVAL pnButton AS LONG PTR) AS HRESULT
   pfnTaskDialog = CAST(ANY PTR, GetProcAddress(hLib, "TaskDialog"))
   DIM hr AS HRESULT
   IF pfnTaskDialog THEN hr = pfnTaskDialog(hwndOwner, hInst, pwszWindowTitle, pwszMainInstruction, pwszContent, dwCommonButtons, pwszIcon, pnButton)
   FreeLibrary hLib
   RETURN hr
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxTaskDialogIndirect (BYVAL pTaskConfig AS CONST TASKDIALOGCONFIG PTR, BYVAL pnButton AS LONG PTR, BYVAL pnRadioButton AS LONG PTR, BYVAL pfVerificationFlagChecked AS BOOL PTR) AS HRESULT
   DIM hLib AS HMODULE = LoadLibraryW("comctl32.dll")
   IF hLib = NULL THEN RETURN HRESULT_FROM_WIN32(GetLastError)
   DIM pfnTaskDialogIndirect AS FUNCTION (BYVAL pTaskConfig AS CONST TASKDIALOGCONFIG PTR, BYVAL pnButton AS LONG PTR, BYVAL pnRadioButton AS LONG PTR, BYVAL pfVerificationFlagChecked AS BOOL PTR) AS HRESULT
   pfnTaskDialogIndirect = CAST(ANY PTR, GetProcAddress(hLib, "TaskDialogIndirect"))
   DIM hr AS HRESULT
   IF pfnTaskDialogIndirect THEN hr = pfnTaskDialogIndirect(pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked)
   FreeLibrary hLib
   RETURN hr
END FUNCTION
#endif
' ========================================================================================

' ========================================================================================
' Returns command line parameters used to call the program
' Unicode replacement for FreeBasic's Command keyword.
' Usage: result = AfxCommand ( [ index ] )
' Parameter:
' - index : Zero-based index for a particular command-line argument.
' Return Value
'   Returns the command-line arguments(s).
' Description
'   - AfxCommand returns command-line arguments passed to the program upon execution.
'   - If index is less than zero (< 0), a space-separated list of all command-line arguments
'   is returned, otherwise, a single argument is returned. A value of zero (0) returns the
'   name of the executable; and values of one (1) and greater return each command-line argument.
'   - If index is greater than the number of arguments passed to the program, a null
'     string ("") is returned.
' ========================================================================================
PRIVATE FUNCTION AfxCommand (BYVAL nIndex AS LONG = -1) AS DWSTRING
   DIM pArgsList AS WSTRING PTR PTR, nArgs AS LONG, dwsArgs AS DWSTRING
   pArgsList = CAST(WSTRING PTR PTR, CommandLineToArgvW(GetCommandLineW, @nArgs))
   IF pArgsList = NULL OR nIndex > nArgs THEN RETURN dwsArgs
   IF nIndex < 0 THEN
      FOR i AS LONG = 1 TO nArgs - 1
         dwsArgs += *pArgsList[i] & " "
      NEXT
      dwsArgs = RTRIM(dwsArgs)
   ELSE
      dwsArgs = *pArgsList[nIndex]
   END IF
   LocalFree CAST(HLOCAL, pArgsList)
   RETURN dwsArgs
END FUNCTION
' ========================================================================================
#define WCommand AfxCommand
' ========================================================================================

' ========================================================================================
' Returns the number of command line arguments used to call the program
' ========================================================================================
FUNCTION AfxCommandLineCount() AS LONG
    DIM nArgs AS LONG
    DIM pArgs AS WSTRING PTR PTR = CommandLineToArgvW(GetCommandLineW, @nArgs)
    IF pArgs THEN LocalFree CAST(HLOCAL, pArgs)
    RETURN nArgs
END FUNCTION
' ========================================================================================
#define WCommandArgsc AfxCommandLineCount
' ========================================================================================

' ========================================================================================
' * Returns the description of the specified Windows error code.
' ========================================================================================
PRIVATE FUNCTION AfxGetWinErrMsg (BYVAL dwError AS DWORD) AS DWSTRING
   DIM cbLen AS DWORD, pBuffer AS WSTRING PTR, dwsMsg AS DWSTRING
   cbLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER OR _
           FORMAT_MESSAGE_FROM_SYSTEM OR FORMAT_MESSAGE_IGNORE_INSERTS, _
           NULL, dwError, BYVAL MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), _
           cast(LPWSTR, @pBuffer), 0, NULL)
   IF cbLen THEN
      dwsMsg = *pBuffer
      LocalFree pBuffer
   END IF
   RETURN dwsMsg
END FUNCTION
' ========================================================================================

' ========================================================================================
' Processes pending Windows messages.
' Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow
' your application to be responsive to user input.
' ========================================================================================
PRIVATE SUB AfxDoEvents (BYVAL hWin AS HWND = NULL)
   DIM uMsg AS MSG
   IF hWin = NULL THEN hWin = GetActiveWindow
   WHILE PeekMessageW(@uMsg, NULL, 0, 0, PM_REMOVE)
      ' // Determines whether a message is intended for the specified
      ' // dialog box and, if it is, processes the message.
      IF IsDialogMessageW(hWin, @uMsg) = 0 THEN
         ' // Translates virtual-key messages into character messages.
         TranslateMessage @uMsg
         ' // Dispatches a message to a window procedure.
         DispatchMessageW @uMsg
      END IF
   WEND
END SUB
' ========================================================================================

' ========================================================================================
' Processes pending Windows messages.
' Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow
' your application to be responsive to user input.
' ========================================================================================
PRIVATE SUB AfxPumpMessages
   DIM uMsg AS MSG
   WHILE PeekMessageW(@uMsg, NULL, 0, 0, PM_REMOVE)
      ' // Translates virtual-key messages into character messages.
      TranslateMessage @uMsg
      ' // Dispatches a message to a window procedure.
      DispatchMessageW @uMsg
   WEND
END SUB
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
PRIVATE FUNCTION AfxWindowsVersion () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion = NULL THEN EXIT FUNCTION
   DIM osverinfo AS OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
      FUNCTION = (osverinfo.dwMajorVersion + osverinfo.dwMinorVersion / 100) * 100
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================
#define AfxGetWindowsVersion AfxWindowsVersion
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION AfxWindowsMajorVersion () AS LONG
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
#define AfxGetWindowsMajorVersion AfxWindowsMajorVersion
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION AfxWindowsMinorVersion () AS LONG
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
#define AfxGetWindowsMinorVersion AfxWindowsMinorVersion
' ========================================================================================

' ========================================================================================
' Returns the full Windows version as a string.
' ========================================================================================
PRIVATE FUNCTION AfxWindowsVersionStr () AS DWSTRING
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion = NULL THEN EXIT FUNCTION
   DIM dwsVer AS DWSTRING
   DIM osverinfo AS OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
      FUNCTION = WSTR(osverinfo.dwMajorVersion) + "." + WSTR(osverinfo.dwMinorVersion) + "." + WSTR(osverinfo.dwBuildNumber)
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================
#define AfxGetWindowsVersionStr AfxWindowsVersionStr
' ========================================================================================

' ========================================================================================
' * Returns the Windows platform
'   1 Windows 95/98/ME
'   2 Windows NT/2000/XP/Server/Vista/Windows 7/10/11
' ========================================================================================
PRIVATE FUNCTION AfxWindowsPlatform () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion = NULL THEN EXIT FUNCTION
   DIM osverinfo AS OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
      FUNCTION = osverinfo.dwPlatformId
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================
#define AfxGetWindowsPlatform AfxWindowsPlatform
' ========================================================================================

' ========================================================================================
' * Returns the Windows build
' ========================================================================================
PRIVATE FUNCTION AfxWindowsBuild () AS LONG
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   IF pfnRtlGetVersion = NULL THEN EXIT FUNCTION
   DIM osverinfo AS OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   IF pfnRtlGetVersion(@osverinfo) = 0 THEN   ' STATUS_SUCCESS
      FUNCTION = osverinfo.dwBuildNumber
   END IF
   FreeLibrary hLib
END FUNCTION
' ========================================================================================
#define AfxGetWindowsBuild AfxWindowsBuild
' ========================================================================================

' ========================================================================================
' * Returns TRUE if the Windows Platform is NT; FALSE, otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxIsPlatformNT () AS BOOLEAN
   DIM osvi AS OSVERSIONINFOW
   osvi.dwOSVersionInfoSize = SIZEOF(osvi)
   GetVersionExW(@osvi)
   FUNCTION = (VER_PLATFORM_WIN32_NT = osvi.dwPlatformId)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the version of specified file multiplied by 100, e.g. 601 for version 6.01.
' Example: DIM ver AS LONG = AfxGetFileVersion("COMCTL32.DLL")
' ========================================================================================
PRIVATE FUNCTION AfxGetFileVersion (BYVAL pwszFileName AS WSTRING PTR) AS LONG
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
#define AfxComCtlVersion AfxGetFileVersion("COMCTL32.DLL")
' ========================================================================================

' ========================================================================================
' * Retrieves the path of the Windows directory.
' ========================================================================================
PRIVATE FUNCTION AfxGetWinDir () AS DWSTRING
   DIM wszWinDir AS WSTRING * MAX_PATH
   GetWindowsDirectoryW(wszWinDir, SIZEOF(wszWinDir) \ 2)
   RETURN wszWinDir
END FUNCTION
' ========================================================================================
#define AfxWindowsDirectory AfxGetWinDir
#define AfxWinDir AfxGetWinDir
' ========================================================================================

' ========================================================================================
' Retrieves the path of the directory designated for temporary files.
' ========================================================================================
PRIVATE FUNCTION AfxGetTempPath () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   ..GetTempPathW(MAX_PATH, @path)
   RETURN path
END FUNCTION
' ========================================================================================
#define AfxTempPath AfxGetTempPath
' ========================================================================================

' ========================================================================================
' Retrieves the path of the system directory used by WOW64.
' This directory is not present on 32-bit Windows.
' ========================================================================================
PRIVATE FUNCTION AfxGetSystemWow64Directory () AS DWSTRING
   DIM cbLen AS UINT = GetSystemWow64DirectoryW(NULL, 0)
   IF cbLen = 0 THEN RETURN ""
   DIM dwsBuffer AS DWSTRING = WSPACE(cbLen)
   cbLen = GetSystemWow64DirectoryW(*dwsBuffer, cbLen)
   RETURN dwsBuffer
END FUNCTION
' ========================================================================================
#define AfxSystemWow64Directory AfxGetSystemWow64Directory
' ========================================================================================

' ========================================================================================
' Returns the system drive name, e.g. "C:".
' ========================================================================================
PRIVATE FUNCTION AfxSystemDrive () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   GetWindowsDirectoryW(@path, MAX_PATH)
   RETURN LEFT(path, 2)   ' "C:"
END FUNCTION
' ========================================================================================
#define AfxGetSystemDrive AfxSystemDrive
' ========================================================================================

' ========================================================================================
' Retrieves the path of the system directory.
' ========================================================================================
PRIVATE FUNCTION AfxSystemDirectory () AS DWSTRING
   DIM path AS WSTRING * MAX_PATH
   ..GetSystemDirectoryW(@path, MAX_PATH)
   RETURN path
END FUNCTION
' ========================================================================================
#define AfxGetSystemDirectory AfxSystemDirectory
' ========================================================================================

' ========================================================================================
' * Returns the path of the program which is currently executing.
' The path name has not a trailing backslash, except if it is a drive, e.g. "C:\".
' * Unicode replacement for FreeBasic's ExePath function.
' ========================================================================================
PRIVATE FUNCTION AfxGetExePath () AS DWSTRING
   DIM buffer AS WSTRING * MAX_PATH, p AS LONG
   GetModuleFileNameW(NULL, buffer, SIZEOF(buffer)\2)
   p = INSTRREV(buffer, ANY ":/\")
   IF p THEN
      buffer = LEFT(buffer, p)
      PathRemoveBackslashW(buffer)
   END IF
   RETURN buffer
END FUNCTION
' ========================================================================================
#define AfxExePath AfxGetExePath
' ========================================================================================

' ========================================================================================
' * Returns the path of the program which is currently executing.
' The path has a trailing backslash.
' ========================================================================================
PRIVATE FUNCTION AfxGetExePathName () AS DWSTRING
   DIM buffer AS WSTRING * MAX_PATH, p AS LONG
   GetModuleFileNameW(NULL, buffer, SIZEOF(buffer)\2)
   p = INSTRREV(buffer, ANY ":/\")
   RETURN LEFT(buffer, p)
END FUNCTION
' ========================================================================================
#define AfxExePathName AfxGetExePathName
' ========================================================================================

' ========================================================================================
' * Returns the file name of the program which is currently executing.
' ========================================================================================
PRIVATE FUNCTION AfxGetExeFileName () AS DWSTRING
   DIM buffer AS WSTRING * MAX_PATH, p AS LONG
   GetModuleFileNameW(NULL, buffer, SIZEOF(buffer)\2)
   p = INSTRREV(buffer, ANY ":/\")
   IF p THEN buffer = MID(buffer, p + 1)
   p = INSTRREV(buffer, ".")
   IF p THEN buffer = LEFT(buffer, p - 1)
   RETURN buffer
END FUNCTION
' ========================================================================================
#define AfxExeFileName AfxGetExeFileName
' ========================================================================================

' ========================================================================================
' * Returns the file name and extension of the program which is currently executing.
' ========================================================================================
PRIVATE FUNCTION AfxGetExeFileNameX () AS DWSTRING
   DIM buffer AS WSTRING * MAX_PATH, p AS LONG
   GetModuleFileNameW(NULL, buffer, SIZEOF(buffer)\2)
   p = INSTRREV(buffer, ANY ":/\")
   IF p THEN buffer = MID(buffer, p + 1)
   RETURN buffer
END FUNCTION
' ========================================================================================
#define AfxExeFileNameX AfxGetExeFileNameX
' ========================================================================================

' ========================================================================================
' * Returns the extension (with a leading period) of the program which is currently executing.
' ========================================================================================
PRIVATE FUNCTION AfxGetExeFileExt () AS DWSTRING
   DIM buffer AS WSTRING * MAX_PATH, p AS LONG
   GetModuleFileNameW(NULL, buffer, SIZEOF(buffer)\2)
   p = INSTRREV(buffer, ".")
   IF p THEN RETURN MID(buffer, p) ELSE RETURN buffer
END FUNCTION
' ========================================================================================
#define AfxExeFileExt AfxGetExeFileExt
' ========================================================================================

' ========================================================================================
' * Returns the full path of the program which is currently executing.
' ========================================================================================
PRIVATE FUNCTION AfxGetExeFullPath () AS DWSTRING
   DIM buffer AS WSTRING * MAX_PATH, cb AS LONG
   cb = GetModuleFileNameW(NULL, buffer, SIZEOF(buffer)\2)
   RETURN LEFT(buffer, cb)
END FUNCTION
' ========================================================================================
#define AfxExeFullPath AfxGetExeFullPath
' ========================================================================================

' ========================================================================================
' * Parses a path/filename and returns the file name portion. That is the text to the right
' of the last backslash (\) or colon (:), ending just before the last period (.). The file
' extension is excluded.
' ========================================================================================
PRIVATE FUNCTION AfxGetFileName (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM dwsPath AS DWSTRING = wszPath
   DIM p AS LONG
   p = INSTRREV(dwsPath, ANY ":/\")
   IF p THEN dwsPath = MID(dwsPath, p + 1)
   p = INSTRREV(dwsPath, ".")
   IF p THEN
      dwsPath = LEFT(dwsPath, p - 1)
   ELSE
      dwsPath = ""
   END IF
   RETURN dwsPath
END FUNCTION
' ========================================================================================
#define AfxFileName AfxGetFileName
' ========================================================================================

' ========================================================================================
' * Parses a path/filename and returns the file name portion. That is the text to the right
' of the last backslash (\) or colon (:), ending just before the last period (.).
' ========================================================================================
PRIVATE FUNCTION AfxGetFileNameX (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM dwsPath AS DWSTRING = wszPath
   DIM p AS LONG
   p = INSTRREV(dwsPath, ANY ":/\")
   IF p THEN RETURN MID(dwsPath, p + 1) ELSE RETURN dwsPath
END FUNCTION
' ========================================================================================
#define AfxFileNameX AfxGetFileNameX
' ========================================================================================

' ========================================================================================
' * Parses a path/filename and returns the extension portion of the path/file name. That is
' the last period (.) in the string plus the text to the right of it.
' ========================================================================================
PRIVATE FUNCTION AfxGetFileExt (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM dwsPath AS DWSTRING = wszPath
   DIM p AS LONG
   p = INSTRREV(dwsPath, ".")
   IF p THEN RETURN MID(dwsPath, p) ELSE RETURN dwsPath
END FUNCTION
' ========================================================================================
#define AfxFileExt AfxGetFileExt
' ========================================================================================

' ========================================================================================
' * Retrieves the current directory for the current process.
' ========================================================================================
PRIVATE FUNCTION AfxGetCurrentDirectory () AS DWSTRING
   DIM wszCurDir AS WSTRING * MAX_PATH
   GetCurrentDirectoryW(MAX_PATH, wszCurDir)
   RETURN wszCurDir
END FUNCTION
' ========================================================================================
#define AfxGetCurDir AfxGetCurrentDirectory
#define AfxCurDir AfxGetCurrentDirectory
' ========================================================================================

' ========================================================================================
' * Changes the current directory for the current process.
' - lpPathName : The path to the new current directory. This parameter may specify a relative
'     path or a full path. In either case, the full path of the specified directory
'     is calculated and stored as the current directory.
' Return value:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
'   To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxSetCurrentDirectory (BYVAL pwszPathName AS LPCWSTR) AS BOOLEAN
   RETURN SetCurrentDirectoryW(pwszPathName)
END FUNCTION
' ========================================================================================
#define AfxSetCurDir AfxSetCurrentDirectory
' ========================================================================================

' ========================================================================================
' * Unicode replacement for Free Basic's ChDir.
' Return value: Returns 0 on success or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION AfxChDir (BYVAL pwszPathName AS LPCWSTR) AS LONG
   DIM res AS LONG = SetCurrentDirectoryW(pwszPathName)
   IF res = 0 THEN RETURN -1 ELSE RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts the specified path to its long form.
' ========================================================================================
PRIVATE FUNCTION AfxGetLongPathName (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM wszLongPath AS WSTRING * MAX_PATH
   GetLongPathNameW(wszPath, wszLongPath, SIZEOF(wszLongPath)\2)
   RETURN wszLongPath
END FUNCTION
' ========================================================================================
#define AfxLongPathName AfxGetLongPathName
' ========================================================================================

' ========================================================================================
' * Retrieves the short path form of the specified path.
' ========================================================================================
PRIVATE FUNCTION AfxGetShortPathName (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM wszShortPath AS WSTRING * MAX_PATH
   GetShortPathNameW(wszPath, wszShortPath, SIZEOF(wszShortPath)\2)
   RETURN wszShortPath
END FUNCTION
' ========================================================================================
#define AfxShortPathName AfxGetShortPathName
' ========================================================================================

' ========================================================================================
' * Parses a path/filename and returns the path portion. That is the text up to and including
' the last backslash (\) or colon (:).
' ========================================================================================
PRIVATE FUNCTION AfxGetPathName (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM dwsPath AS DWSTRING = wszPath
   DIM p AS LONG
   p = INSTRREV(dwsPath, ANY ":\/")
   IF p THEN RETURN LEFT(dwsPath, p)
   RETURN ""
END FUNCTION
' ========================================================================================
#define AfxPathName AfxGetPathName
' ========================================================================================

' ========================================================================================
' * Returns a string containing the name of the folder for a specified path, i.e. the path
' minus the file name.
' ========================================================================================
PRIVATE FUNCTION AfxGetFolderName (BYREF wszPath AS WSTRING) AS DWSTRING
   DIM dwsPath AS DWSTRING = wszPath
   DIM p AS LONG
   IF INSTRREV(dwsPath, ".") = 0 THEN
      IF RIGHT(dwsPath, 1) = "\" THEN dwsPath = LEFT(dwsPath, LEN(dwsPath) - 1)
      RETURN dwsPath
   END IF
   p = INSTRREV(dwsPath, ANY "\/")
   IF p THEN RETURN LEFT(dwsPath, p - 1)
   RETURN dwsPath
END FUNCTION
' ========================================================================================
#define AfxFolderName AfxGetFolderName
' ========================================================================================

' ========================================================================================
' * Retrieves the path of the specified system DLL.
' ========================================================================================
PRIVATE FUNCTION AfxGetSystemDllPath (BYREF wszDllName AS WSTRING) AS DWSTRING
   DIM wszPath AS WSTRING * MAX_PATH
   DIM hLib AS HMODULE = LoadLibraryW(wszDllName)
   IF hLib THEN
      GetModuleFileNameW(hLib, wszPath, SIZEOF(wszPath)\2)
      FreeLibrary hLib
   END IF
   RETURN wszPath
END FUNCTION
' ========================================================================================
#define AfxSystemDllPath AfxGetSystemDllPath
' ========================================================================================

' ========================================================================================
' Retrieves the path of the executable file given its process identifier.
' ========================================================================================
PRIVATE FUNCTION AfxGetPathFromProcessId (BYVAL dwProcessId AS DWORD) AS DWSTRING
   DIM hProcess AS HANDLE, wszPath AS WSTRING * MAX_PATH
   hProcess = OpenProcess(PROCESS_QUERY_INFORMATION OR PROCESS_VM_READ, FALSE, dwProcessId)
   IF hProcess <> NULL THEN
      GetModuleFileNameExW(hProcess, NULL, wszPath, SIZEOF(wszPath)\2)
      CloseHandle(hProcess)
   END IF
   RETURN wszPath
END FUNCTION
' ========================================================================================
#define AfxPathFromProcessId AfxGetPathFromProcessId
' ========================================================================================

' ========================================================================================
' Retrieves the path of the executable file that created the specified window.
' ========================================================================================
PRIVATE FUNCTION AfxGetPathFromWindowHandle (BYVAL hWin AS HWND) AS DWSTRING
   DIM idProc AS DWORD, hProcess AS HANDLE, wszPath AS WSTRING * MAX_PATH
   GetWindowThreadProcessId(hWin, @idProc)
   IF idProc THEN
      hProcess = OpenProcess(PROCESS_QUERY_INFORMATION OR PROCESS_VM_READ, FALSE, idProc)
      IF hProcess THEN
         GetModuleFileNameExW(hProcess, NULL, wszPath, SIZEOF(wszPath)\2)
         CloseHandle(hProcess)
         RETURN wszPath
      END IF
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================
#define AfxPathFromWindowHandle AfxGetPathFromWindowHandle
' ========================================================================================

#if _WIN32_WINNT = &h0602
' ========================================================================================
' Retrieves the path of an special folder. Requires Windows Vista/Windows 7 or superior.
' - rfid: A reference to the KNOWNFOLDERID that identifies the folder. The folders associated
'   with the known folder IDs might not exist on a particular system.
' - dwFlags: Flags that specify special retrieval options. This value can be 0; otherwise,
'   it is one or more of the KNOWN_FOLDER_FLAG values.
' - hToken: An access token used to represent a particular user. This parameter is usually
'   set to NULL, in which case the function tries to access the current user's instance of
'   the folder. However, you may need to assign a value to hToken for those folders that can
'   have multiple users but are treated as belonging to a single user. The most commonly used
'   folder of this type is Documents.
'   The calling application is responsible for correct impersonation when hToken is non-null.
'   It must have appropriate security privileges for the particular user, including TOKEN_QUERY
'   and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. See Access
'   Control for further discussion of access control issues.
'   https://msdn.microsoft.com/en-us/library/windows/desktop/aa374860(v=vs.85).aspx
'   Assigning the hToken parameter a value of -1 indicates the Default User. This allows
'   clients of SHGetKnownFolderIDList to find folder locations (such as the Desktop folder)
'   for the Default User. The Default User user profile is duplicated when any new user
'   account is created, and includes special folders such as Documents and Desktop.
'   Any items added to the Default User folder also appear in any new user account.
'   Note that access to the Default User folders requires administrator privileges.
' Return value:
'   The path of the requested folder on success, or an empty string on failure.
' Remarks: For a list of KNOWNFOLDERID constants see:
'   https://msdn.microsoft.com/en-us/library/windows/desktop/dd378457(v=vs.85).aspx
' Usage example: AfxGetKnowFolderPath(@FOLDERID_CommonPrograms)
' ========================================================================================
PRIVATE FUNCTION AfxGetKnowFolderPath (BYVAL rfid AS CONST KNOWNFOLDERID CONST PTR, BYVAL dwFlags AS DWORD = 0, BYVAL hToken AS HANDLE = NULL) AS DWSTRING
   DIM pwszPath AS WSTRING PTR
   IF SHGetKnownFolderPath(rfid, dwFlags, hToken, @pwszPath) <> S_OK THEN RETURN ""
   DIM dwsPath AS DWSTRING = *pwszPath
   CoTaskMemFree(pwszPath)
   RETURN dwsPath
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' Retrieves the path of an special folder.
' - nFolder: A CSIDL value that identifies the folder of interest.
' For a list of CSIDL values see:
' https://msdn.microsoft.com/en-us/library/windows/desktop/bb762494(v=vs.85).aspx
' ========================================================================================
PRIVATE FUNCTION AfxGetSpecialFolderLocation (BYVAL nFolder AS LONG) AS DWSTRING
   DIM pidl AS ITEMIDLIST PTR          ' // Pointer to an item identifier list (PIDL)
   DIM wszPath AS WSTRING * MAX_PATH   ' // Folder's path
   IF SHGetSpecialFolderLocation(0, nFolder, @pidl) = S_OK THEN
      SHGetPathFromIDListW pidl, @wszPath
      CoTaskMemFree pidl
      RETURN wszPath
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' // Control_RunDLL is an undocumented procedure in the Shell32.dll which can be used
' // to launch control panel applications. You’ve to pass the name of the control panel
' // file (.cpl) and the tool represented by it will be launched. For launching some
' // control panel applications, you’ve to provide a valid windows handle (hwnd parameter)
' // and program instance (hinstance parameter).
' // This opens the control panel: AfxControlRunDLL(0, 0, "", SW_SHOWNORMAL)
' // This opens the applications wizard: AfxControlRunDLL(0, 0, "appwiz.cpl", SW_SHOWNORMAL)
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxControlRunDLL (BYVAL hWin AS HWND, BYVAL hInst AS HINSTANCE, BYVAL cmd AS WSTRING PTR, BYVAL nCmdShow AS LONG) AS BOOLEAN
   DIM AS ANY PTR pLib = DyLibLoad("shell32.dll")
   IF pLib = 0 THEN EXIT FUNCTION
   DIM pProc AS FUNCTION (BYVAL hWin AS HWND, BYVAL hInst AS HINSTANCE, BYVAL cmd AS WSTRING PTR, BYVAL nCmdShow AS LONG) AS BOOLEAN
   pProc = DyLibSymbol(pLib, "Control_RunDLLW")
   IF pProc = 0 THEN EXIT FUNCTION
   FUNCTION = pProc(hWin, hInst, cmd, nCmdShow)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays a dialog box that enables the user to select a folder.
' - pwszTitle       = A string value that represents the title displayed inside the Browse dialog box.
' - pwszStartFolder = The initial folder that the dialog will show.
' - nFlags          = Optional. A LONG value that contains the options for the method. This can be a
'                     combination of the values listed under the ulFlags member of the BROWSEINFO structure.
'                     See: http://msdn.microsoft.com/en-us/library/windows/desktop/bb773205%28v=vs.85%29.aspx
'                     Default value = BIF_RETURNONLYFSDIRS OR BIF_DONTGOBELOWDOMAIN OR BIF_USENEWUI OR BIF_RETURNFSANCESTORS
' Note: To display the old style dialog, pass -1 in the dwFlags parameter. (Crashes in Windows 10).
' ========================================================================================
' // Browse for folder dialog procedure
PRIVATE FUNCTION AfxBrowseForFolderProc (BYVAL hWin AS HWND, BYVAL uMsg AS UINT, BYVAL wPrm AS WPARAM, BYVAL lPrm AS LPARAM) AS LONG

   DIM wszBuffer AS WSTRING * MAX_PATH

   IF uMsg = BFFM_INITIALIZED THEN
      SendMessageW hWin, BFFM_SETSELECTIONW, CTRUE, cast(LPARAM, lPrm)
   ELSEIF uMsg = BFFM_SELCHANGED THEN
      SHGetPathFromIDListW(cast(ITEMIDLIST PTR, wPrm), @wszBuffer)
      IF wPrm = 0 OR _ ' // No id number
         LEN(wszBuffer) = 0 OR _ ' // No name
         (GetFileAttributesW(wszBuffer) AND FILE_ATTRIBUTE_DIRECTORY) <> FILE_ATTRIBUTE_DIRECTORY OR _ ' // Not a real directory
         MID(wszBuffer, 2, 1) <> ":" THEN ' // Not a local or mapped drive
            SendMessageW hWin, BFFM_ENABLEOK, FALSE, FALSE
      ELSEIF ((GetFileAttributesW(wszBuffer) AND FILE_ATTRIBUTE_SYSTEM) = FILE_ATTRIBUTE_SYSTEM) AND _
            RIGHT(wszBuffer, 2) <> ":\" THEN   ' // Exclude system folders, allow root directories
         SendMessageW hWin, BFFM_ENABLEOK, FALSE, FALSE
      END IF
   END IF
   RETURN 0

END FUNCTION

PRIVATE FUNCTION AfxBrowseForFolder (BYVAL hWin AS HWND, BYVAL pwszTitle AS WSTRING PTR = NULL, _
   BYVAL pwszStartFolder AS WSTRING PTR = NULL, BYVAL nFlags AS LONG = 0) AS DWSTRING

   ' // Initialize the COM library
   CoInitialize NULL

   DIM wszBuffer AS WSTRING * MAX_PATH, bi AS BROWSEINFOW, pidl AS ITEMIDLIST PTR
   IF nFlags = 0 THEN nFlags = BIF_RETURNONLYFSDIRS OR BIF_DONTGOBELOWDOMAIN OR BIF_USENEWUI OR BIF_RETURNFSANCESTORS
   ' // Crashes in Windows 10
'   IF nFlags = -1 THEN nFlags = BIF_RETURNONLYFSDIRS OR BIF_DONTGOBELOWDOMAIN OR BIF_RETURNFSANCESTORS

   bi.hWndOwner = hWin
   bi.lpszTitle = pwszTitle
   bi.ulFlags   = nFlags
   bi.lpfn      = cast(BFFCALLBACK, @AfxBrowseForFolderProc)
   bi.lParam    = cast(LPARAM, pwszStartFolder)
   pidl         = SHBrowseForFolderW(@bi)

   IF pidl THEN
      SHGetPathFromIDListW(pidl, @wszBuffer)
      CoTaskMemFree pidl
   END IF
   RETURN wszBuffer

   ' // Uninitialize the COM library
   CoUninitialize

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an Open dialog box that lets the user specify the drive, directory, and the name
' of a file or set of files to be opened.
' - hwndOwner: A handle to the window that owns the dialog box. This parameter can be any
'   valid window handle, or it can be NULL if the dialog box has no owner.
' - wszTitle: A string to be placed in the title bar of the dialog box. If this member is NULL,
'   the system uses the default title (that is, Save As or Open).
' - wszFile: The file name used to initialize the File Name edit control. When the GetOpenFileName
'   or GetSaveFileName function returns successfully, this buffer contains the drive designator,
'   path, file name, and extension of the selected file.
'   If the OFN_ALLOWMULTISELECT flag is set and the user selects multiple files, the buffer
'   contains the current directory followed by the file names of the selected files. For
'   Explorer-style dialog boxes, the directory and file name strings are NULL separated,
'   with an extra NULL character after the last file name. For old-style dialog boxes, the
'   strings are space separated and the function uses short file names for file names with
'   spaces. You can use the FindFirstFile function to convert between long and short file
'   names. If the user selects only one file, the lpstrFile string does not have a separator
'   between the path and file name.
' - wszInitialDir: The initial directory.
' - wszFilter: A buffer containing pairs of "|" separated filter strings. The first string
'   in each pair is a display string that describes the filter (for example, "Text Files"),
'   and the second string specifies the filter pattern (for example, "*.TXT"). To specify
'   multiple filter patterns for a single display string, use a semicolon to separate the
'   patterns (for example, "*.TXT;*.DOC;*.BAK"). A pattern string can be a combination of
'   valid file name characters and the asterisk (*) wildcard character. Do not include spaces
'   in the pattern string.
'   The system does not change the order of the filters. It displays them in the File Types
'   combo box in the order specified in wszFilter. If wszFilter is NULL, the dialog box
'   does not display any filters.
' - wszDefExt: The default extension. GetOpenFileName and GetSaveFileName append this
'   extension to the file name if the user fails to type an extension. This string can be
'   any length, but only the first three characters are appended. The string should not
'   contain a period (.). If this member is NULL and the user fails to type an extension,
'   no extension is appended.
' - pdwFlags: A set of bit flags you can use to initialize the dialog box. When the dialog
'   box returns, it sets these flags to indicate the user's input. For example, to check
'   if the user has checked the read only checkbox:
'   IF (pdwFlags AND OFN_READONLY) = OFN_READONLY THEN ...
'   This value can be a combination of the following flags:
'   See complete list and explanations at:
'   https://msdn.microsoft.com/en-us/library/windows/desktop/ms646839(v=vs.85).aspx
' - pdwBufLen: The size of the buffer, in charactersm where the names of the selected
'   files will be returned.
' Return value:
'   An string containing a comma separated list of the selected files.
'   Parse the number of ",". If only one, then the user has selected only a file and the
'   string contains the full path. If more, The first substring contains the path and the
'   others the files.
'   If the user has not selected any file, an empty string is returned.
'   On failure, an empty string is returned and, if not null, the pdwBufLen parameter will
'   be filled by the size of the required buffer in characters.
' Usage example:
'   DIM wszFile AS WSTRING * 260 = "*.*"
'   DIM wszInitialDir AS STRING * 260 = CURDIR
'   DIM wszFilter AS WSTRING * 260 = "BAS files (*.BAS)|*.BAS|" & "All Files (*.*)|*.*|"
'   DIM dwFlags AS DWORD = OFN_EXPLORER OR OFN_FILEMUSTEXIST OR OFN_HIDEREADONLY OR OFN_ALLOWMULTISELECT
'   DIM dws AS DWSTRING = AfxOpenFileDialog(hwnd, "", wszFile, wszInitialDir, wszFilter, "BAS", @dwFlags, NULL)
'   AfxMsg dws
' ========================================================================================
PRIVATE FUNCTION AfxOpenFileDialog ( _
   BYVAL hwndOwner AS HWND _                    ' // Parent window
 , BYREF wszTitle AS WSTRING _                  ' // Caption
 , BYREF wszFile AS WSTRING _                   ' // Filename
 , BYREF wszInitialDir AS WSTRING _             ' // Start directory
 , BYREF wszFilter AS WSTRING _                 ' // Filename filter
 , BYREF wszDefExt AS WSTRING _                 ' // Default extension
 , BYVAL pdwFlags AS DWORD PTR = NULL _         ' // Flags
 , BYVAL pdwBufLen AS DWORD PTR = NULL _        ' // Buffer length
 ) AS DWSTRING

   DIM dwFlags AS DWORD, dwBufLen AS DWORD
   IF pdwFlags THEN dwFlags = *pdwFlags
   IF pdwBufLen THEN dwBufLen = *pdwBuflen

   ' // Filter is a sequence of WSTRINGs with a final (extra) double null terminator
   ' // The "|" characters are replaced with nulls
   DIM wszMarkers AS WSTRING * 4 = "||"
   IF RIGHT(wszFilter, 1) <> "|" THEN wszMarkers += "|"
   DIM dwsFilter AS DWSTRING = wszFilter & wszMarkers
   DIM dwFilterStrSize AS DWORD = LEN(dwsFilter)
   ' // Replace markers("|") with nulls
   DIM pchar AS WCHAR PTR = *dwsFilter
   FOR i AS LONG = 0 TO LEN(dwsFilter) - 1
      IF pchar[i] = ASC("|") THEN pchar[i] = 0
   NEXT

   ' // If the initial directory has not been specified, assume the current directory
   ' // FreeBasic 64 bit fails if we pass an empty string and we try to modify wszInitialDir
   DIM _wszInitialDir AS WSTRING * MAX_PATH = wszInitialDir
   IF LEN(_wszInitialDir) = 0 THEN _wszInitialDir = CURDIR
   ' // The size of the buffer must be at least MAX_PATH characters
   IF dwBufLen = 0 THEN
      IF (dwFlags AND OFN_ALLOWMULTISELECT) = OFN_ALLOWMULTISELECT THEN dwBufLen = 32768  ' // 64 Kb buffer
   END IF
   IF dwBufLen < 260 THEN dwBufLen = 260   ' // Make room for at least one path
   ' // Allocate the file name and a marker ("|") to be replaced with a null
   DIM dwsFile AS DWSTRING = wszFile & "|"
   ' // Store the position of the marker
   DIM cbPos AS LONG = LEN(dwsFile) - 1
   ' // Allocate room for the buffer
   IF LEN(dwsFile) < dwBufLen THEN dwsFile += WSPACE(dwBufLen - LEN(dwsFile))
   DIM dwFileStrSize AS DWORD = LEN(dwsFile)
   ' // The filename must be null terminated (replace the marker with a null)
   pchar = *dwsFile
   pchar[cbPos] = 0

   ' // Fill the members of the structure
   DIM ofn AS OPENFILENAMEW
   ofn.lStructSize     = SIZEOF(ofn)
   IF AfxWindowsVersion < 5 THEN ofn.lStructSize = 76
   ofn.hwndOwner       = hwndOwner
   ofn.lpstrFilter     = *dwsFilter
   ofn.nFilterIndex    = 1
   ofn.lpstrFile       = *dwsFile
   ofn.nMaxFile        = dwFileStrSize
   ofn.lpstrInitialDir = @_wszInitialDir
   IF LEN(wszTitle) THEN ofn.lpstrTitle = @wszTitle
   ofn.Flags = dwFlags OR OFN_EXPLORER
   IF LEN(wszDefExt) THEN ofn.lpstrDefExt = @wszDefExt

   ' // Call the open file dialog
   IF GetOpenFilenameW(@ofn) THEN
      IF (dwFlags AND OFN_ALLOWMULTISELECT) = OFN_ALLOWMULTISELECT THEN
         pchar = *dwsFile
         FOR i AS LONG = 0 TO dwFileStrSize - 1
            ' // If double null, exit
            IF pchar[i] = 0 AND pchar[i + 1] = 0 THEN EXIT FOR
            ' // Replace null with ","
            IF pchar[i] = 0 THEN pchar[i] = ASC(",")
         NEXT
      END IF
      ' // Trim trailing spaces
      dwsFile = RTRIM(dwsFile, CHR(32))
      IF RIGHT(dwsFile, 1) = "," THEN dwsFile = LEFT(dwsFile, LEN(dwsFile) - 1)
   ELSE
      ' // Buffer too small
      IF CommDlgExtendedError = FNERR_BUFFERTOOSMALL THEN
         dwBufLen = ASC(dwsFile)
      END IF
      dwsFile = ""
   END IF

   ' // Return the retrieved values
   IF pdwFlags THEN *pdwFlags = ofn.Flags
   IF pdwBufLen THEN *pdwBufLen = dwBufLen
   RETURN dwsFile

END FUNCTION
' ========================================================================================

' ========================================================================================
' The parameters are the same that for AfxOpenFileDialog, except the optional pdwBufferLen.
' In the pdwFlags parameter you may add OFN_OVERWRITEPROMPT to be asked if you want to
' overwrite an existing file.
' Usage example:
'   DIM wszFile AS WSTRING * 260 = "*.*"
'   DIM wszInitialDir AS WSTRING * 260 = CURDIR
'   DIM wszFilter AS WSTRING * 260 = "BAS files (*.BAS)|*.BAS|" & "All Files (*.*)|*.*|"
'   DIM dwFlags AS DWORD = OFN_EXPLORER OR OFN_FILEMUSTEXIST OR OFN_HIDEREADONLY OR OFN_OVERWRITEPROMPT
'   DIM dws AS DWSTRING = AfxSaveFileDialog(hwnd, "", wszFile, wszInitialDir, wszFilter, "BAS", @dwFlags)
'   AfxMsg dws
' ========================================================================================
PRIVATE FUNCTION AfxSaveFileDialog ( _
   BYVAL hwndOwner AS HWND _                    ' // Parent window
 , BYREF wszTitle AS WSTRING _                  ' // Caption
 , BYREF wszFileName AS WSTRING _               ' // Filename
 , BYREF wszInitialDir AS WSTRING _             ' // Start directory
 , BYREF wszFilter AS WSTRING _                 ' // Filename filter
 , BYREF wszDefExt AS WSTRING _                 ' // Default extension
 , BYVAL pdwFlags AS DWORD PTR = NULL _         ' // Flags
 ) AS DWSTRING

   DIM dwFlags AS DWORD
   IF pdwFlags THEN dwFlags = *pdwFlags

   ' // Filter is a sequence of WSTRINGs with a final (extra) double null terminator
   ' // The "|" characters are replaced with nulls
   DIM wszMarkers AS WSTRING * 4 = "||"
   IF RIGHT(wszFilter, 1) <> "|" THEN wszMarkers += "|"
   DIM dwsFilter AS DWSTRING = wszFilter & wszMarkers
   DIM dwFilterStrSize AS DWORD = LEN(dwsFilter)
   ' // Replace markers("|") with nulls
   DIM pchar AS WCHAR PTR = *dwsFilter
   DIM i AS LONG
   FOR i = 0 TO LEN(dwsFilter) - 1
      IF pchar[i] = ASC("|") THEN pchar[i] = 0
   NEXT

   ' // If the initial directory has not been specified, assume the current directory
   ' // FreeBasic 64 bit fails if we pass an empty string and we try to modify wszInitialDir
   DIM _wszInitialDir AS WSTRING * MAX_PATH = wszInitialDir
   IF LEN(_wszInitialDir) = 0 THEN _wszInitialDir = CURDIR
   DIM wszFile AS WSTRING * MAX_PATH = wszFileName
   DIM dwsFile AS DWSTRING = wszFile & "|"
   ' // Store the position of the marker
   DIM cbPos AS LONG = LEN(dwsFile) - 1
   ' // Allocate room for the buffer
   IF LEN(dwsFile) < MAX_PATH THEN dwsFile += SPACE(MAX_PATH - LEN(dwsFile))
   DIM dwFileStrSize AS DWORD = LEN(dwsFile)
   ' // The filename must be null terminated (replace the marker with a null)
   pchar = *dwsFile
   pchar[cbPos] = 0

   ' // Fill the members of the structure
   DIM ofn AS OPENFILENAMEW
   ofn.lStructSize     = SIZEOF(ofn)
   IF AfxWindowsVersion < 5 THEN ofn.lStructSize = 76
   ofn.lpstrFilter     = *dwsFilter
   ofn.nFilterIndex    = 1
   ofn.lpstrFile       = *dwsFile
   ofn.nMaxFile        = dwFileStrSize
   ofn.lpstrInitialDir = @_wszInitialDir
   IF LEN(wszTitle) THEN ofn.lpstrTitle = @wszTitle
   ofn.Flags = dwFlags OR OFN_EXPLORER
   IF LEN(wszDefExt) THEN ofn.lpstrDefExt = @wszDefExt

   ' // Call the save filename dialog
   IF GetSaveFilenameW(@ofn) = 0 THEN dwsFile = ""

   ' // Return the retrieved values
   IF pdwFlags THEN *pdwFlags = ofn.Flags
   RETURN dwsFile

END FUNCTION
' ========================================================================================

' ========================================================================================
' * Displays Windows System Information.
' - hwnd = Handle to the parent window or NULL.
' Returns TRUE on success or FALSE on failure.
' ========================================================================================
PRIVATE FUNCTION AfxShowSysInfo (BYVAL hWin AS HWND) AS BOOLEAN
   DIM hk AS HKEY, wszPath AS WSTRING * MAX_PATH, cbData AS DWORD = SIZEOF(wszPath)\2
   IF RegOpenKeyExW(HKEY_LOCAL_MACHINE, "Software\Microsoft\Shared Tools\MSInfo", 0, _
                    KEY_QUERY_VALUE, @hk) <> ERROR_SUCCESS THEN EXIT FUNCTION
   RegQueryValueExW hk, "Path", 0, 0, cast(LPBYTE, @wszPath), @cbData
   RegCloseKey hk
   IF LEN(wszPath) = 0 THEN EXIT FUNCTION
   IF ShellExecuteW(hWin, "open", @wszPath, NULL, NULL, SW_SHOWNORMAL) > 32 THEN FUNCTION = TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the choose color dialog.
' - hParent = Handle to the parent window or null.
' - rgbDefaultColor = Optional. Initial default color.
' - lpCustColors = Optional. A pointer to an array of 16 values that contain red, green,
'   blue (RGB) values for the custom color boxes in the dialog box. If the user modifies
'   these colors, the system updates the array with the new RGB values.
' Return value: The selected color, or -1 if the user has canceled the dialog.
' ========================================================================================
PRIVATE FUNCTION AfxChooseColorDialog (BYVAL hParent AS HWND, BYVAL rgbDefaultColor AS COLORREF = 0, BYVAL lpCustColors AS COLORREF PTR = NULL) AS LONG
   DIM ColorSpec AS CHOOSECOLORW, lCustomColor(15) AS LONG
   ColorSpec.lStructSize  = SIZEOF(ColorSpec)
   ColorSpec.hwndOwner    = hParent     ' // Handle of owner window.  If 0, dialog appears at top/left.
   IF lpCustColors = NULL THEN
      FOR lCounter AS LONG = 0 TO 15
         lCustomColor(lCounter) = BGR(0, lCounter * 16, (15 - lCounter) * 16)
      NEXT
      ColorSpec.lpCustColors = VARPTR(lCustomColor(0))
   ELSE
      ColorSpec.lpCustColors = lpCustColors
   END IF
   ColorSpec.rgbResult = rgbDefaultColor
   ColorSpec.Flags = ColorSpec.Flags OR CC_RGBINIT OR CC_FULLOPEN
   FUNCTION =  IIF(ChooseColorW(@ColorSpec), Colorspec.rgbResult, -1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the MAC address of a machine's Ethernet card.
' This function only supports one NIC card on your PC.
' Remarks: I have needed to call the UuidCreateSequential function dynamically because,
' the time of writing, the library for the RPCRT4.DLL seems broken and the linker fails.
' ========================================================================================
PRIVATE FUNCTION AfxGetMACAddress () AS STRING
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
PRIVATE FUNCTION AfxGetMACAddressEx () AS STRING
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
' Populates a dynamic array of STRINGs with all the real MAC addresses of the system.
' The array is passed by reference and resized internally.
' Return value:
'    The number of elements in the array or -1 on failure.
' Usage example
'    DIM macs(ANY) AS STRING
'    DIM count AS LONG = AfxGetAllMACAddresses(macs())
'    FOR i AS LONG = LBOUND(macs) TO UBOUND(macs)
'      PRINT macs(i)
'    NEXT
' ========================================================================================
PRIVATE FUNCTION AfxGetAllMACAddresses (macs() AS STRING) AS LONG
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
' Populates a dynamic array of STRINGs with all *real* MAC addresses (Ethernet/Wi-Fi).
' Filters out virtual adapters, tunnels, Bluetooth, Hyper-V, loopback, etc.
' Returns: Number of MACs found, or -1 on failure.
' Usage example:
'    DIM macs(ANY) AS STRING
'    DIM count AS LONG = AfxGetAllPhysicalMACAddresses(macs())
'    FOR i AS LONG = LBOUND(macs) TO UBOUND(macs)
'       PRINT macs(i)
'    NEXT
' ========================================================================================
PRIVATE FUNCTION AfxGetAllPhysicalMACAddresses (macs() AS STRING) AS LONG
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
' Extracts resource data and returns it as a string.
' Parameters:
' - hInstance       = [in] A handle to the module whose portable executable file or an accompanying
'                     MUI file contains the resource. If this parameter is NULL, the function searches
'                     the module used to create the current process.
' - wszResourceName = [in] Name of the resource. If the resource is an image that uses an integral
'                     identifier, wszResourceName should begin with a number symbol (#)
'                     followed by the identifier in an ASCII format, e.g., "#998". Otherwise,
'                     use the text identifier name for the image. Only images embedded as raw data
'                     (type RCDATA) are valid. These must be in format .png, .jpg, .gif, .tiff.
' - pResourceType   = Type of the resource, e.g. RT_RCDATA. For a list of predefined resource types see:
'                     https://docs.microsoft.com/en-us/windows/desktop/menurc/resource-types
' Return Value:
'    A string containing the resource data.
' Example:
' DIM strResData AS STRING = AfxExtractResource(NULL, "IDI_ARROW_RIGHT", RT_RCDATA)
'   - where IDI_ARROW_RIGHT is the identifier in the resource file for
'     IDI_ARROW_RIGHT RCDATA ".\Resources\arrow_right_64.png"
' --or--
' DIM strResData AS STRING = AfxExtractResource(NULL, "#111", RT_RCDATA)
'   - where "#111" is the identifier in the resource file for
'   - 111 RCDATA ".\Resources\VEGA_PAZ_01.jpg"
' -----
' // Write the resource data to a file
' DIM hFile AS HANDLE = CreateFileW("PazVega.jpg", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
' IF hFile THEN
'    DIM dwBytesWritten AS DWORD
'    DIM bSuccess AS BOOLEAN = WriteFile(hFile, STRPTR(strResData), LEN(strResData), @dwBytesWritten, NULL)
'    CloseHandle(hFile)
'    print bSuccess
' END IF
' ========================================================================================
PRIVATE FUNCTION AfxExtractResource (BYVAL hInstance AS HINSTANCE, _
   BYREF wszResourceName AS WSTRING, BYVAL pResourceType AS LPWSTR = MAKEINTRESOURCEW(10)) AS STRING

   ' // Find the resource
   DIM hRes AS HRSRC
   IF LEFT(wszResourceName, 1) = "#" THEN
      DIM wID AS WORD = VAL(MID(wszResourceName, 2))
      DIM dwID AS DWORD = MAKELONG(wID, 0)
      hRes = FindResourceW(hInstance, MAKEINTRESOURCEW(dwID), pResourceType)
   ELSE
      hRes = FindResourceW(hInstance, wszResourceName, pResourceType)
   END IF
   IF hRes = NULL THEN RETURN ""
   ' // Retrieve the resource size
   DIM ResSize AS DWORD = SizeofResource(hInstance, hRes)
   IF ResSize = 0 THEN RETURN ""
   ' // Lock the resource
   DIM pResData AS LPVOID = LockResource(LoadResource(hInstance, hRes))
   IF pResData = NULL THEN RETURN ""
   DIM strResData AS STRING = SPACE(ResSize)
   memcpy STRPTR(strResData), pResData, ResSize
   RETURN strResData

END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts resource data and saves it to a file.
' Parameters:
' - hInstance       = [in] A handle to the module whose portable executable file or an accompanying
'                     MUI file contains the resource. If this parameter is NULL, the function searches
'                     the module used to create the current process.
' - wszResourceName = [in] Name of the resource. If the resource is an image that uses an integral
'                     identifier, wszResourceName should begin with a number symbol (#)
'                     followed by the identifier in an ASCII format, e.g., "#998". Otherwise,
'                     use the text identifier name for the image. Only images embedded as raw data
'                     (type RCDATA) are valid. These must be in format .png, .jpg, .gif, .tiff.
' - wszFileName     = Path of the file where to save the extracted resource.
' - pResourceType   = Type of the resource, e.g. RT_RCDATA. For a list of predefined resource types see:
'                     https://docs.microsoft.com/en-us/windows/desktop/menurc/resource-types
' Return Value:
'    Returns TRUE on success or FALSE on failure.
' Example:
'    AfxExtractResourceToFile(NULL, "IDI_ARROW_RIGHT", "IDI_ARROW_RIGHT.png", RT_RCDATA)
'    where IDI_ARROW_RIGHT is the identifier in the resource file for
'    IDI_ARROW_RIGHT RCDATA ".\Resources\arrow_right_64.png"
' Example:
'    AfxExtractResourceToFile(NULL, "#111", "VEGA_PAZ_01.jpg", RT_RCDATA)
'    where "#111" is the identifier in the resource file for
'    111 RCDATA ".\Resources\VEGA_PAZ_01.jpg"
' ========================================================================================
PRIVATE FUNCTION AfxExtractResourceToFile (BYVAL hInstance AS HINSTANCE, BYREF wszResourceName AS WSTRING, _
   BYREF wszFileName AS WSTRING, BYVAL pResourceType AS LPWSTR = MAKEINTRESOURCEW(10)) AS BOOLEAN

   ' // Find the resource
   DIM hRes AS HRSRC
   IF LEFT(wszResourceName, 1) = "#" THEN
      DIM wID AS WORD = VAL(MID(wszResourceName, 2))
      DIM dwID AS DWORD = MAKELONG(wID, 0)
      hRes = FindResourceW(hInstance, MAKEINTRESOURCEW(dwID), pResourceType)
   ELSE
      hRes = FindResourceW(hInstance, wszResourceName, pResourceType)
   END IF
   IF hRes = NULL THEN RETURN FALSE
   ' // Retrieve the resource size
   DIM ResSize AS DWORD = SizeofResource(hInstance, hRes)
   IF ResSize = 0 THEN RETURN FALSE
   ' // Lock the resource
   DIM pResData AS LPVOID = LockResource(LoadResource(hInstance, hRes))
   IF pResData = NULL THEN RETURN FALSE
   ' // Write the resource data to a file
   DIM hFile AS HANDLE = CreateFileW(wszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN RETURN FALSE
   DIM dwBytesWritten AS DWORD
   DIM bSuccess AS BOOLEAN = WriteFile(hFile, pResData, ResSize, @dwBytesWritten, NULL)
   CloseHandle(hFile)
   RETURN bSuccess

END FUNCTION
' ========================================================================================


' ########################################################################################
'                              *** DPI RELATED PROCEDURES ***
' ########################################################################################

' ========================================================================================
' Sets the current process as dots per inch (dpi) aware.
' Note: SetProcessDPIAware is subject to a possible race condition if a DLL caches dpi
' settings during initialization. For this reason, it is recommended that dpi-aware be set
' through the application (.exe) manifest rather than by calling SetProcessDPIAware.
' Return value: TRUE on success; FALSE on failure.
' ========================================================================================
PRIVATE FUNCTION AfxSetProcessDPIAware () AS BOOLEAN
   DIM AS ANY PTR pLib = DyLibLoad("user32.dll")
   IF pLib = 0 THEN EXIT FUNCTION
   DIM pProc AS FUNCTION () AS LONG
   pProc = DyLibSymbol(pLib, "SetProcessDPIAware")
   IF pProc = 0 THEN EXIT FUNCTION
   FUNCTION = pProc()
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the current process is dots per inch (dpi) aware such that it adjusts
' the sizes of UI elements to compensate for the dpi setting.
' Return value: TRUE or FALSE
' ========================================================================================
PRIVATE FUNCTION AfxIsProcessDPIAware () AS BOOLEAN
   DIM AS ANY PTR pLib = DyLibLoad("user32.dll")
   IF pLib = 0 THEN EXIT FUNCTION
   DIM pProc AS FUNCTION () AS LONG
   pProc = DyLibSymbol(pLib, "IsProcessDPIAware")
   IF pProc = 0 THEN EXIT FUNCTION
   FUNCTION = pProc()
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the value of the UseDpiScaling setting (Vista/Windows 7+).
' Returns TRUE if the OS uses DPI scaling; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxUseDpiScaling () AS BOOLEAN
   DIM hkRes AS HKEY, dwType AS DWORD, dwData AS DWORD, cbData AS DWORD
   IF RegOpenKeyExW(HKEY_CURRENT_USER, "Software\Microsoft\Windows\DWM", 0, KEY_QUERY_VALUE, @hkRes) = ERROR_SUCCESS THEN
      IF hkRes THEN
         cbData = SIZEOF(cbData)
         DIM hr AS LONG = RegQueryValueExW(hkRes, "UseDpiScaling", 0, @dwType, CPTR(BYTE PTR, @dwData), @cbData)
         RegCloseKey hkRes
         IF hr = ERROR_SUCCESS THEN FUNCTION = (dwData <> 0)
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of pixels per logical inch along the screen width of the desktop
' window. In a system with multiple display monitors, this value is the same for all monitors.
' ========================================================================================
PRIVATE FUNCTION AfxLogPixelsX () AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM dpiX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC HWND_DESKTOP, hDC
   FUNCTION = dpiX
END FUNCTION
' ========================================================================================
#define AfxGetDpi AfxLogPixelsX
#define AfxGetDpiX AfxLogPixelsX

' ========================================================================================
' Retrieves the number of pixels per logical inch along the screen height of the desktop
' window. In a system with multiple display monitors, this value is the same for all monitors.
' ========================================================================================
PRIVATE FUNCTION AfxLogPixelsY () AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM dpiY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC HWND_DESKTOP, hDC
   FUNCTION = dpiY
END FUNCTION
' ========================================================================================
#define AfxGetDpiY AfxLogPixelsY

' ========================================================================================
' Retrieves the desktop horizontal scaling ratio.
' ========================================================================================
PRIVATE FUNCTION AfxScaleRatioX () AS SINGLE
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM rxRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   ReleaseDC HWND_DESKTOP, hDC
   FUNCTION = rxRatio
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the desktop vertical scaling ratio.
' ========================================================================================
PRIVATE FUNCTION AfxScaleRatioY () AS SINGLE
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM ryRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
   FUNCTION = ryRatio
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scales an horizontal coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION AfxScaleX (BYVAL cx AS SINGLE) AS SINGLE
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   FUNCTION = cx * (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   ReleaseDC HWND_DESKTOP, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scales a vertical coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION AfxScaleY (BYVAL cy AS SINGLE) AS SINGLE
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   FUNCTION = cy * (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unscales an horizontal coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION AfxUnscaleX (BYVAL cx AS SINGLE) AS SINGLE
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   FUNCTION = cx / (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   ReleaseDC HWND_DESKTOP, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unscales a vertical coordinate according the DPI (dots per pixel) being used by the desktop.
' ========================================================================================
PRIVATE FUNCTION AfxUnscaleY (BYVAL cy AS SINGLE) AS SINGLE
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   FUNCTION = cy / (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if screen resolution meets minimum requirements.
' Parameters:
' - cxMin = Minimum screen resolution width in pixels.
' - cxMin = Minimum screen resolution height in pixels.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxIsResolutionAtLeast (BYVAL cxMin AS LONG, BYVAL cyMin AS LONG) AS BOOLEAN
   DIM ScreenWidth AS LONG = GetSystemMetrics(SM_CXSCREEN)
   DIM ScreenHeight AS LONG = GetSystemMetrics(SM_CYSCREEN)
   IF (cxMin <= ScreenWidth) AND (cyMin <= ScreenHeight) THEN FUNCTION = TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if screen resolution meets minimum requirements in relative pixels,
' e.g. for a screen resolution of 1920x1080 pixels and a DPI of 192 (scaling ratio = 2),
' the maximum relative pixels for a DPI aware application is 960x540.
' - cxMin = Minimum screen resolution width in relative pixels.
' - cxMin = Minimum screen resolution height in relative pixels.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxIsDPIResolutionAtLeast (BYVAL cxMin AS LONG, BYVAL cyMin AS LONG) AS BOOLEAN
   ' // Get de DPI values used by the desktop window
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM dpiX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   DIM dpiY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC HWND_DESKTOP, hDC
   ' // Scale the values
   cxMin = cxMin * dpiX / 96
   cyMin = cyMin * dpiX / 96
   ' // Calculate the width and height of the primary display monitor, in pixels
   DIM ScreenWidth AS LONG = GetSystemMetrics(SM_CXSCREEN)
   DIM ScreenHeight AS LONG = GetSystemMetrics(SM_CYSCREEN)
   IF (cxMin <= ScreenWidth) AND (cyMin <= ScreenHeight) THEN FUNCTION = TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the logical width of the monitor that the window is currently displayed on.
' If the application to which the window belongs is not DPI aware, a monitor with a
' width resolution of 1920 pixels in a computer using 192 DPI, will return 960 pixels.
' ========================================================================================
PRIVATE FUNCTION AfxGetMonitorLogicalWidth (BYVAL hWin AS HWND = NULL) AS DWORD
   ' // Get the monitor that the window is currently displayed on
   IF hWin = NULL THEN hWin = GetDesktopWindow
   DIM hMonitor AS HMONITOR = MonitorFromWindow(hWin, MONITOR_DEFAULTTONEAREST)
   ' // Get the logical width of the monitor.
   DIM miex AS MONITORINFOEXW
   miex.cbSize = SIZEOF(miex)
   GetMonitorInfoW(hMonitor, CAST(LPMONITORINFO, @miex))
   FUNCTION = (miex.rcMonitor.right  - miex.rcMonitor.left)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the logical height of the monitor that the window is currently displayed on.
' If the application to which the window belongs is not DPI aware, a monitor with an
' height resolution of 1080 pixels in a computer using 192 DPI, will return 540 pixels.
' ========================================================================================
PRIVATE FUNCTION AfxGetMonitorLogicalHeight (BYVAL hWin AS HWND = NULL) AS DWORD
   ' // Get the monitor that the window is currently displayed on
   IF hWin = NULL THEN hWin = GetDesktopWindow
   DIM hMonitor AS HMONITOR = MonitorFromWindow(hWin, MONITOR_DEFAULTTONEAREST)
   ' // Get the logical width of the monitor.
   DIM miex AS MONITORINFOEXW
   miex.cbSize = SIZEOF(miex)
   GetMonitorInfoW(hMonitor, CAST(LPMONITORINFO, @miex))
   FUNCTION = (miex.rcMonitor.bottom - miex.rcMonitor.top)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the horizontal scaling of the monitor that the window is currently displayed on.
' If the application to which the window belongs is not DPI aware, a computer using
' 192 DPI, will return an scaling ratio of 2.
' ========================================================================================
PRIVATE FUNCTION AfxGetMonitorHorizontalScaling (BYVAL hWin AS HWND = NULL) AS DWORD
   ' // Get the monitor that the window is currently displayed on
   IF hWin = NULL THEN hWin = GetDesktopWindow
   DIM hMonitor AS HMONITOR = MonitorFromWindow(hWin, MONITOR_DEFAULTTONEAREST)
   ' // Get the logical width and height of the monitor.
   DIM miex AS MONITORINFOEXW
   miex.cbSize = sizeof(miex)
   GetMonitorInfoW(hMonitor, CAST(LPMONITORINFO, @miex))
   DIM cxLogical AS LONG = (miex.rcMonitor.right  - miex.rcMonitor.left)
   DIM cyLogical AS LONG = (miex.rcMonitor.bottom - miex.rcMonitor.top)
   ' // Get the physical width and height of the monitor.
   DIM dm AS DEVMODEW
   dm.dmSize = sizeof(dm)
   dm.dmDriverExtra = 0
   EnumDisplaySettingsW(miex.szDevice, ENUM_CURRENT_SETTINGS, @dm)
   DIM cxPhysical AS LONG = dm.dmPelsWidth
   DIM cyPhysical as LONG = dm.dmPelsHeight
   ' // Calculate the scaling factor.
   DIM horzScale AS DOUBLE = cxPhysical / cxLogical
   DIM vertScale AS DOUBLE = cyPhysical / cyLogical
   FUNCTION = horzScale
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the vertical scaling of the monitor that the window is currently displayed on.
' If the application to which the window belongs is not DPI aware, a computer using
' 192 DPI, will return an scaling ratio of 2.
' ========================================================================================
PRIVATE FUNCTION AfxGetMonitorVerticalScaling (BYVAL hWin AS HWND = NULL) AS DWORD
   ' // Get the monitor that the window is currently displayed on
   IF hWin = NULL THEN hWin = GetDesktopWindow
   DIM hMonitor AS HMONITOR = MonitorFromWindow(hWin, MONITOR_DEFAULTTONEAREST)
   ' // Get the logical width and height of the monitor.
   DIM miex AS MONITORINFOEXW
   miex.cbSize = sizeof(miex)
   GetMonitorInfoW(hMonitor, CAST(LPMONITORINFO, @miex))
   DIM cxLogical AS LONG = (miex.rcMonitor.right  - miex.rcMonitor.left)
   DIM cyLogical AS LONG = (miex.rcMonitor.bottom - miex.rcMonitor.top)
   ' // Get the physical width and height of the monitor.
   DIM dm AS DEVMODEW
   dm.dmSize = sizeof(dm)
   dm.dmDriverExtra = 0
   EnumDisplaySettingsW(miex.szDevice, ENUM_CURRENT_SETTINGS, @dm)
   DIM cxPhysical AS LONG = dm.dmPelsWidth
   DIM cyPhysical as LONG = dm.dmPelsHeight
   ' // Calculate the scaling factor.
   DIM horzScale AS DOUBLE = cxPhysical / cxLogical
   DIM vertScale AS DOUBLE = cyPhysical / cyLogical
   FUNCTION = vertScale
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a specified icon resource with a client-specified system metric.
' See: https://msdn.microsoft.com/en-us/library/windows/desktop/bb775701(v=vs.85).aspx
' ========================================================================================
PRIVATE FUNCTION AfxLoadIconMetric (BYVAL hinst AS HINSTANCE, BYVAL pszName AS PCWSTR, BYVAL lims AS LONG, BYVAL phico AS HICON PTR) AS HRESULT
   DIM AS ANY PTR pLib = DyLibLoad("Comctl32.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pLoadIconMetric AS FUNCTION (BYVAL hinst AS HINSTANCE, BYVAL pszName AS PCWSTR, BYVAL lims AS LONG, BYVAL phico AS HICON PTR) AS HRESULT
   pLoadIconMetric = DyLibSymbol(pLib, "LoadIconMetric")
   IF pLoadIconMetric THEN FUNCTION = pLoadIconMetric(hinst, pszName, lims, phico)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                      *** WINDOW ***
' ########################################################################################

' ========================================================================================
' * Gets the class name of the specified window
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowClassName (BYVAL hWin AS HWND) AS DWSTRING
   DIM wszClassName AS WSTRING * 260
   GetClassNameW hWin, wszClassName, SIZEOF(wszClassName)
   RETURN wszClassName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a window. This function can also be used to retrieve the text of buttons,
' and edit and static controls.
' Example: DIM dws AS DWSTRING = AfxGetWindowText(hwnd)
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowText (BYVAL hWin AS HWND) AS DWSTRING
   DIM nLen AS LONG = GetWindowTextLengthW(hWin)
   DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
   GetWindowTextW(hWin, dwsText, nLen +  1)
   RETURN LEFT(dwsText, nLen)
END FUNCTION
' ========================================================================================
#define AfxSetWindowText SetWindowTextW
' ========================================================================================

' ========================================================================================
' Gets the length of the text of a window.
' Usage example: nLen = AfxGetWindowTextLength(hwnd)
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowTextLength (BYVAL hWin AS HWND) AS LONG
   FUNCTION = SendMessageW(hWin, WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the window styles.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowStyle (BYVAL hWin AS HWND) AS LONG_PTR
   RETURN GetWindowLongPtrW(hWin, GWL_STYLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended window styles.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowExStyle (BYVAL hWin AS HWND) AS LONG_PTR
   RETURN GetWindowLongPtrW(hWin, GWL_EXSTYLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the window styles
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowStyle (BYVAL hWin AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldStyle AS LONG_PTR = GetWindowLongPtrW(hWin, GWL_STYLE)
   SetWindowLongPtrW(hWin, GWL_STYLE, dwStyle)
   SetWindowPos(hWin, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the window extended styles
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowExStyle (BYVAL hWin AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldExStyle AS LONG_PTR = GetWindowLongPtrW(hWin, GWL_EXSTYLE)
   SetWindowLongPtrW(hWin, GWL_EXSTYLE, dwExStyle)
   SetWindowPos(hWin, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldExStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a new style to the specified window.
' - hwnd  = Window handle
' - dwStyle = Style to add
' Return value:
'   The previous window styles
' ========================================================================================
PRIVATE FUNCTION AfxAddWindowStyle (BYVAL hWin AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldStyle AS LONG_PTR = GetWindowLongPtrW(hWin, GWL_STYLE)
   SetWindowLongPtrW(hWin, GWL_STYLE, dwOldStyle OR dwStyle)
   SetWindowPos(hWin, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a new extended style to the specified window.
' - hwnd  = Window handle
' - dwExStyle = Style to add
' Return value:
'   The previous extended window styles
' ========================================================================================
PRIVATE FUNCTION AfxAddWindowExStyle (BYVAL hWin AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldExStyle AS LONG_PTR = GetWindowLongPtrW(hWin, GWL_EXSTYLE)
   SetWindowLongPtrW(hWin, GWL_EXSTYLE, dwOldExStyle OR dwExStyle)
   SetWindowPos(hWin, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldExStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an style from the specified window.
' - hwnd  = Window handle
' - dwStyle = Style to remove
' Return value:
'   The previous window styles
' ========================================================================================
PRIVATE FUNCTION AfxRemoveWindowStyle (BYVAL hWin AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
   DIM dwOldStyle AS LONG_PTR = GetWindowLongPtrW(hWin, GWL_STYLE)
   SetWindowLongPtrW(hWin, GWL_STYLE, dwOldStyle AND (NOT dwStyle))
   SetWindowPos(hWin, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an extended style from the specified window.
' - hwnd  = Window handle
' - dwExStyle = Style to remove
' Return value:
'   The previous window styles
' ========================================================================================
PRIVATE FUNCTION AfxRemoveWindowExStyle (BYVAL hWin AS HWND, BYVAL dwExStyle AS DWORD) AS LONG_PTR
   DIM dwOldExStyle AS LONG_PTR = GetWindowLongPtrW(hWin, GWL_EXSTYLE)
   SetWindowLongPtrW(hWin, GWL_EXSTYLE, dwOldExStyle AND (NOT dwExStyle))
   SetWindowPos(hWin, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED OR SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER)
   RETURN dwOldExStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the dimensions of the bounding rectangle of the specified window. The dimensions
' are given in screen coordinates that are relative to the upper-left corner of the screen.
' Note: To retrieve the height of the desktop window pass the handle returned by the
' API function GetDesktopWindow.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowRect (BYVAL hWin AS HWND) AS RECT
   DIM rc AS RECT
   GetWindowRect(hWin, @rc)
   FUNCTION = rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width in pixels of a window.
' Note: To retrieve the height of the desktop window pass the handle returned by the
' API function GetDesktopWindow.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowWidth (BYVAL hWin AS HWND) AS LONG
   DIM rc AS RECT
   GetWindowRect(hWin, @rc)
   FUNCTION = rc.Right - rc.Left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height in pixels of a window.
' Note: To retrieve the height of the desktop window pass the handle returned by the
' API function GetDesktopWindow.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowHeight (BYVAL hWin AS HWND) AS LONG
   DIM rc AS RECT
   GetWindowRect(hWin, @rc)
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounds of a window without the drop shadows.
' In Windows Vista and later, the Window Rect includes the area occupied by the drop shadow.
' Calling GetWindowRect will have different behavior depending on whether the window has
' ever been shown or not. If the window has not been shown before, GetWindowRect will not
' include the area of the drop shadow.
' To get the window bounds excluding the drop shadow, use DwmGetWindowAttribute, specifying
' DWMWA_EXTENDED_FRAME_BOUNDS. Note that unlike the Window Rect, the DWM Extended Frame Bounds
' are not adjusted for DPI. Getting the extended frame bounds can only be done after the
' window has been shown at least once.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowBounds (BYVAL hWin AS HWND) AS RECT
   DIM rc AS RECT
   DIM AS ANY PTR pLib = DyLibLoad("Dwmapi.DLL")
   IF pLib  THEN
      DIM pProc AS FUNCTION (BYVAL hWin AS .HWND, BYVAL dwAttribute AS DWORD, BYVAL pvAttribute AS ANY PTR, BYVAL cbAttribute AS DWORD) AS HRESULT
      pProc = DyLibSymbol(pLib, "DwmGetWindowAttribute")
      ' DWMWA_EXTENDED_FRAME_BOUNDS = 9
      IF pProc THEN pProc(hWin, 9, @rc, SIZEOF(rc))
      DyLibFree(pLib)
   END IF
   RETURN rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the coordinates of a window's client area. The client coordinates specify the
' upper-left and lower-right corners of the client area. Because client coordinates are
' relative to the upper-left corner of a window's client area, the coordinates of the
' upper-left corner are (0,0).
' Note: To retrieve the height of the desktop window pass the handle returned by the
' API function GetDesktopWindow.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowClientRect (BYVAL hWin AS HWND) AS RECT
   DIM rc AS RECT
   GetClientRect(hWin, @rc)
   FUNCTION = rc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width in pixels of the client area of a window.
' Note: To retrieve the height of the desktop window pass the handle returned by the
' API function GetDesktopWindow.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowClientWidth (BYVAL hWin AS HWND) AS LONG
   DIM rc AS RECT
   GetClientRect(hWin, @rc)
   FUNCTION = rc.Right - rc.Left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height in pixels of the client area of a window.
' Note: To retrieve the height of the desktop window pass the handle returned by the
' API function GetDesktopWindow.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowClientHeight (BYVAL hWin AS HWND) AS LONG
   DIM rc AS RECT
   GetClientRect(hWin, @rc)
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Centers a window on the screen or over another window.
' It also ensures that the placement is done within the work area.
' Parameters:
' - hwnd = Handle of the window.
' - hwndParent = [optional] Handle of the parent window.
' ========================================================================================
PRIVATE SUB AfxCenterWindow (BYVAL hWin AS HWND = NULL, BYVAL hwndParent AS HWND = NULL)

   DIM rc            AS RECT    ' Window coordinates
   DIM rcParent      AS RECT    ' Parent window coordinates
   DIM rcWorkArea    AS RECT    ' Work area coordinates
   DIM pt            AS POINT   ' x and y coordinates of centered window

   ' // Get the coordinates of the window
   GetWindowRect hWin, @rc
   ' // Calculate the width and height of the window
   DIM nWidth AS LONG = rc.Right - rc.Left
   DIM nHeight AS LONG = rc.Bottom - rc.Top
   ' // Get the coordinates of the work area
   IF SystemParametersInfoW(SPI_GETWORKAREA, SIZEOF(rcWorkArea), @rcWorkArea, 0) = 0 THEN
      rcWorkArea.Right  = GetSystemMetrics(SM_CXSCREEN)
      rcWorkArea.Bottom = GetSystemMetrics(SM_CYSCREEN)
   END IF
   ' // Get the coordinates of the parent window
   IF hwndParent THEN
      GetWindowRect hwndParent, @rcParent
   ELSE
      rcParent.Left   = rcWorkArea.Left
      rcParent.Top    = rcWorkArea.Top
      rcParent.Right  = rcWorkArea.Right
      rcParent.Bottom = rcWorkArea.Bottom
   END IF
   ' // Calculate the width and height of the parent window
   DIM nParentWidth AS LONG = rcParent.Right - rcParent.Left
   DIM nParentHeight AS LONG = rcParent.Bottom - rcParent.Top
   ' // Calculate the new x coordinate and adjust for work area
   pt.x = rcParent.Left + ((nParentWidth - nWidth) \ 2)
   IF (pt.x < rcWorkArea.Left) THEN
      pt.x = rcWorkArea.Left
   ELSEIF ((pt.x + nWidth) > rcWorkArea.Right) THEN
      pt.x = rcWorkArea.Right - nWidth
   END IF
   ' // Calculate the new y coordinate and adjust for work area
   pt.y = rcParent.Top  + ((nParentHeight - nHeight) \ 2)
   IF (pt.y < rcWorkArea.Top) THEN
      pt.y = rcWorkArea.Top
   ELSEIF ((pt.y + nHeight) > rcWorkArea.Bottom) THEN
      pt.y = rcWorkArea.Bottom - nHeight
   END IF
   ' // Convert screen coordinates to client area coordinates
   IF (GetWindowLongPtrW(hWin, GWL_STYLE) AND WS_CHILD) = WS_CHILD THEN ScreenToClient hwndParent, @pt
   ' // Reposition the window retaining its size and Z order
   SetWindowPos(hWin, NULL, pt.x, pt.y, 0, 0, SWP_NOSIZE OR SWP_NOZORDER)

END SUB
' ========================================================================================

' ========================================================================================
' Adjusts the bounding rectangle of a window based on the desired size of the client area.
' Parameters:
' - hwnd = The window handle.
' - nWidth and nHeight = The desired size of the client area.
' - rxRatio and ryRatio = Scaling ratios.
' ========================================================================================
PRIVATE SUB AfxSetWindowClientSize (BYVAL hWin AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL rxRatio AS SINGLE = 1, BYVAL ryRatio AS SINGLE = 1)

   ' // Convert the client rectangle to a window rectangle.
   ' // The AdjustWindowRectEx function cannot take menu wrapping into account
   ' // because it doesn't know which menu we are using.
   DIM rc AS RECT, rcTemp  AS RECT
   SetRect(@rc, 0, 0, nWidth * rxRatio, nHeight * ryRatio)
   DIM hMenu AS HANDLE = GetMenu(hWin)
   DIM dwStyle AS DWORD = GetWindowLongPtrW(hWin, GWL_STYLE)
   AdjustWindowRectEx(@rc, dwStyle, (hMenu <> NULL), GetWindowLongPtrW(hWin, GWL_EXSTYLE))
   ' // If there is a menu, we need to check how much wrapping occurs when we set
   ' // the window to the width specified by AdjustWindowRectEX and an infinite
   ' // amount of height. An infinite height allows us to see every single menu wrap.
   IF hMenu <> NULL THEN
      rcTemp = rc
      rcTemp.Bottom = &H7FFF   ' // "Infinite" height
      SendMessageW(hWin, WM_NCCALCSIZE, 0, CAST(LPARAM, @rcTemp))
      ' // Adjust our previous calculation to compensate for menu wrapping.
      rc.Bottom = rc.Bottom + rcTemp.Top
   END IF
   ' // The AdjustWindowRectEx function does not take the WS_VSCROLL or WS_HSCROLL
   ' // styles into account. To account for the scroll bars, we need to call the
   ' // GetSystemMetrics function with SM_CXVSCROLL or SM_CYHSCROLL.
   IF (dwStyle AND WS_HSCROLL) = WS_HSCROLL THEN
      rc.Bottom = rc.Bottom + GetSystemMetrics(SM_CYHSCROLL)
   END IF
   IF (dwStyle AND WS_VSCROLL) = WS_VSCROLL THEN
      rc.Right = rc.Right + GetSystemMetrics(SM_CXVSCROLL)
   END IF
   DIM cx AS LONG = rc.Right - rc.Left
   DIM cy AS LONG = rc.Bottom - rc.Top
   SetWindowPos(hWin, NULL, 0, 0, cx, cy, SWP_NOZORDER OR SWP_NOMOVE OR SWP_NOACTIVATE)

END SUB
' ========================================================================================

' ========================================================================================
' Adjusts the bounding rectangle of a window based on the desired size of the client area.
' Parameters:
' - hwnd = The window handle.
' - nWidth and nHeight = The desired size of the client area.
' The width and height are scaled according the DPI ratios.
' ========================================================================================
PRIVATE SUB AfxSetWindowClientSizeForDpi (BYVAL hWin AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)

   ' // Get the DPI ratios
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM rxRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   DIM ryRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC

   ' // Convert the client rectangle to a window rectangle.
   ' // The AdjustWindowRectEx function cannot take menu wrapping into account
   ' // because it doesn't know which menu we are using.
   DIM rc AS RECT, rcTemp  AS RECT
   SetRect(@rc, 0, 0, nWidth * rxRatio, nHeight * ryRatio)
   DIM hMenu AS HANDLE = GetMenu(hWin)
   DIM dwStyle AS DWORD = GetWindowLongPtrW(hWin, GWL_STYLE)
   AdjustWindowRectEx(@rc, dwStyle, (hMenu <> NULL), GetWindowLongPtrW(hWin, GWL_EXSTYLE))
   ' // If there is a menu, we need to check how much wrapping occurs when we set
   ' // the window to the width specified by AdjustWindowRectEX and an infinite
   ' // amount of height. An infinite height allows us to see every single menu wrap.
   IF hMenu <> NULL THEN
      rcTemp = rc
      rcTemp.Bottom = &H7FFF   ' // "Infinite" height
      SendMessageW(hWin, WM_NCCALCSIZE, 0, CAST(LPARAM, @rcTemp))
      ' // Adjust our previous calculation to compensate for menu wrapping.
      rc.Bottom = rc.Bottom + rcTemp.Top
   END IF
   ' // The AdjustWindowRectEx function does not take the WS_VSCROLL or WS_HSCROLL
   ' // styles into account. To account for the scroll bars, we need to call the
   ' // GetSystemMetrics function with SM_CXVSCROLL or SM_CYHSCROLL.
   IF (dwStyle AND WS_HSCROLL) = WS_HSCROLL THEN
      rc.Bottom = rc.Bottom + GetSystemMetrics(SM_CYHSCROLL)
   END IF
   IF (dwStyle AND WS_VSCROLL) = WS_VSCROLL THEN
      rc.Right = rc.Right + GetSystemMetrics(SM_CXVSCROLL)
   END IF
   DIM cx AS LONG = rc.Right - rc.Left
   DIM cy AS LONG = rc.Bottom - rc.Top
   SetWindowPos(hWin, NULL, 0, 0, cx, cy, SWP_NOZORDER OR SWP_NOMOVE OR SWP_NOACTIVATE)

END SUB
' ========================================================================================

' ========================================================================================
' Centers a control horizontally.
' hCtrl = Handle of the control.
' ========================================================================================
PRIVATE SUB AfxCenterControlH (BYVAL hCtrl AS HWND)
   DIM rc AS RECT, rcParent AS RECT
   ' // Get the coordinates of the control
   GetWindowRect hCtrl, @rc
   DIM nWidthControl AS LONG = rc.Right - rc.Left
   DIM nHeightControl AS LONG = rc.Bottom - rc.Top
   ' // Get the coordinates of the parent window
   DIM hParent AS HWND = GetParent(hCtrl)
   GetClientRect hParent, @rcParent
   DIM nWidthParent AS LONG = rcParent.Right - rcParent.Left
   ' // Calculate the x coordinate to center the control horizontally
   DIM x AS LONG = (nWidthParent - nWidthControl) \ 2
   ' // Convert the y coordinate of the control to client area coordinate
   DIM pt AS POINT
   pt.y = rc.Top
   ScreenToClient hParent, @pt
   MoveWindow hCtrl, x, pt.y, nWidthControl, nHeightControl, CTRUE
END SUB
' ========================================================================================

' ========================================================================================
' Centers a control vertically
' hCtrl = Handle of the control.
' ========================================================================================
PRIVATE SUB AfxCenterControlV (BYVAL hCtrl AS HWND)
   DIM rc AS RECT, rcParent AS RECT
   ' // Get the coordinates of the control
   GetWindowRect hCtrl, @rc
   DIM nWidthControl AS LONG = rc.Right - rc.Left
   DIM nHeightControl AS LONG = rc.Bottom - rc.Top
   ' // Get the coordinates of the parent window
   DIM hParent AS HWND = GetParent(hCtrl)
   GetClientRect hParent, @rcParent
   DIM nHeightParent AS LONG = rcParent.Bottom - rcParent.Top
   ' // Calculate the x coordinate to center the control vertically
   DIM y AS LONG = (nHeightParent - nHeightControl) \ 2
   ' // Convert the x coordinate of the control to client area coordinate
   DIM pt AS POINT
   pt.x = rc.Left
   ScreenToClient hParent, @pt
   MoveWindow hCtrl, pt.x + (nWidthControl \ 2), y, nWidthControl, nHeightControl, CTRUE
END SUB
' ========================================================================================

' ========================================================================================
' Redraws the specified window.
' Do not use it from within a WM_PAINT message.
' ========================================================================================
PRIVATE SUB AfxRedrawWindow (BYVAL hWin AS HWND)
   InvalidateRect hWin, NULL, CTRUE
   UpdateWindow hWin
END SUB
' ========================================================================================

' ========================================================================================
' Redraws the non-client area of the specified window.
' Return value: TRUE or FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxRedrawNonClientArea (BYVAL hWin AS HWND) AS BOOLEAN
   FUNCTION = SetWindowPos(hWin, 0, 0, 0, 0, 0, SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER OR SWP_NOACTIVATE OR SWP_FRAMECHANGED OR SWP_DRAWFRAME)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sends a WM_SIZE message to the specified window.
' Parameters:
' - hwnd = Handle of the window.
' - nResizeType = Type of resizing requested.
' - nWidth = The new width of the client area.
' - nHeight = The new height of the client ara.
' Return value:
' If an application processes this message, it should return zero.
' ========================================================================================
PRIVATE FUNCTION AfxForwardSizeMessage (BYVAL hWin AS HWND, BYVAL nResizeType AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LRESULT
   FUNCTION = SendMessageW(hWin, WM_SIZE, nResizeType, MAKELONG(nWidth, nHeight))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the size, position, and Z order of a child, pop-up, or top-level window.
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowPosForDPI (BYVAL hwnd AS HWND, BYVAL hWndInsertAfter AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, _
   BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL uFlags AS UINT = SWP_NOZORDER) AS BOOLEAN
   ' // Get the DPI ratios
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM rxRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   DIM ryRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
   IF x <> 0 THEN x = x * rxRatio
   IF y <> 0 THEN y = y * ryRatio
   RETURN ..SetWindowPos(hwnd, hWndInsertAfter, x, y, cx * rxRatio, cy * ryRatio, uFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the position and dimensions of the specified window.
' ========================================================================================
PRIVATE FUNCTION AfxMoveWindowForDPI (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS BOOLEAN = TRUE) AS BOOLEAN
   ' // Get the DPI ratios
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM rxRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   DIM ryRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
   IF x <> 0 THEN x = x * rxRatio
   IF y <> 0 THEN y = y * ryRatio
   RETURN ..MoveWindow(hwnd, x, y, nWidth * rxRatio, nHeight * ryRatio, bRepaint)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the location of the top left corner of the window, in pixels.
' The location is relative to the upper-left corner of the client area in the parent window.
' ========================================================================================
PRIVATE SUB AfxGetWindowLocation (BYVAL hWin AS HWND, BYREF nLeft AS LONG, BYREF nTop AS LONG)
   DIM rc AS RECT
   ' // Get the dimensions of the window
   GetWindowRect(hWin, @rc)
   ' // Convert the coordinates to be relative to the parent
   MapWindowPoints(HWND_DESKTOP, GetParent(hWin), CAST(POINT PTR, @rc), 2)
   ' // Return the left and top values
   IF VARPTR(nLeft) THEN nLeft = rc.Left
   IF VARPTR(nTop) THEN nTop = rc.Top
END SUB
' ========================================================================================

' ========================================================================================
' Sets the location of the top left corner of the window, in pixels.
' The location is relative to the upper-left corner of the client area in the parent window.
' Return value: TRUE or FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowLocation (BYVAL hWin AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
   FUNCTION = SetWindowPos(hWin, 0, nLeft, nTop, 0, 0, SWP_NOSIZE OR SWP_NOZORDER)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowLocationForDpi (BYVAL hWin AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
   ' // Get the DPI ratios
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM rxRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   DIM ryRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
   IF nLeft = 0 THEN rxRatio = 1
   IF nTop = 0 THEN ryRatio = 1
   FUNCTION = SetWindowPos(hWin, 0, nLeft * rxRatio, nTop * ryRatio, 0, 0, SWP_NOSIZE OR SWP_NOZORDER)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width and height of the window, in pixels.
' - hwnd = Handle of the window.
' - nWidth = The width of window.
' - nHeight = The height of the window.
' Return value: TRUE or FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowSize (BYVAL hWin AS HWND, BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   DIM rc AS RECT
   ' // Get the dimensions of the window
   FUNCTION = GetWindowRect(hWin, @rc)
   ' // Return the width and height values
   IF VARPTR(nWidth) THEN nWidth = rc.Right - rc.Left
   IF VARPTR(nHeight) THEN nHeight = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size in pixels of the specified window.
' - hwnd = Handle of the window.
' - nWidth = The new width of the windiw.
' - nHeight = The new height of the window.
' Return value: TRUE or FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowSize (BYVAL hWin AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   FUNCTION = SetWindowPos(hWin, NULL, 0, 0, nWidth, nHeight, SWP_NOZORDER OR SWP_NOMOVE)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowSizeForDpi (BYVAL hWin AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
   ' // Get the DPI ratios
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM rxRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSX) / 96)
   DIM ryRatio AS SINGLE = (GetDeviceCaps(hDC, LOGPIXELSY) / 96)
   ReleaseDC HWND_DESKTOP, hDC
   FUNCTION = SetWindowPos(hWin, NULL, 0, 0, nWidth * rxRatio, nHeight * ryRatio, SWP_NOZORDER OR SWP_NOMOVE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Change the visible state of a window.
' Parameters:
' - hwnd = The handle of the window.
' - nShowState
'   SW_FORCEMINIMIZE : Minimizes a window, even if the thread that owns the window is not
'   responding. This flag should only be used when minimizing windows from a different thread.
'   SW_HIDE : Hides the window and activates another window.
'   SW_MAXIMIZE : Maximizes the specified window.
'   SW_MINIMIZE : Minimizes the specified window and activates the next top-level window in the Z order.
'   SW_RESTORE : Activates and displays the window. If the window is minimized or maximized,
'   the system restores it to its original size and position. An application should specify
'   this flag when restoring a minimized window.
'   SW_SHOW : Activates the window and displays it in its current size and position.
'   SW_SHOWDEFAULT : Sets the show state based on the SW_ value specified in the STARTUPINFO
'   structure passed to the CreateProcess function by the program that started the application.
'   SW_SHOWMAXIMIZED : Activates the window and displays it as a maximized window.
'   SW_SHOWMINIMIZED : Activates the window and displays it as a minimized window.
'   SW_SHOWMINNOACTIVE : Displays the window as a minimized window. This value is similar
'   to SW_SHOWMINIMIZED, except the window is not activated.
'   SW_SHOWNA : Displays the window in its current size and position. This value is similar
'   to SW_SHOW, except that the window is not activated.
'   SW_SHOWNOACTIVATE : Displays a window in its most recent size and position. This value is
'   similar to SW_SHOWNORMAL, except that the window is not activated.
'   SW_SHOWNORMAL : Activates and displays a window. If the window is minimized or maximized,
'   the system restores it to its original size and position. An application should specify
'   this flag when displaying the window for the first time.
' Return value:
' TRUE if the window was previously visible.
' FALSE if the window was previously hidden.
' ========================================================================================
PRIVATE FUNCTION AfxShowWindowState (BYVAL hWin AS HWND, BYVAL nShowState AS LONG) AS BOOLEAN
   FUNCTION = ShowWindow(hWin, nShowState)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new icon with a window. The system displays the large icon in the
' ALT+TAB dialog box and the small icon in the window caption.
' Parameters:
' - hwnd  = Window handle
' - hIcon = Handle to the new icon. If this parameter is NULL, the icon is removed.
' - nIconType = ICON_BIG (1) or ICON_SMALL (0).
' The return value is a handle to the previous large or small icon, depending on the value of
' nIconType It is NULL if the window previously had no icon of the type indicated by nIconType.
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowIcon (BYVAL hWin AS HWND, BYVAL nIconType AS LONG, BYVAL _hIcon AS HICON) AS HICON
   RETURN cast(HICON, SendMessageW(hWin, WM_SETICON, nIconType, CAST(LPARAM, _hIcon)))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Brings the thread that created the specified window into the foreground and activates
' the window. Keyboard input is directed to the window, and various visual cues are changed
' for the user. The system assigns a slightly higher priority to the thread that created
' the foreground window than it does to other threads.
' Replacement for the SetForegroundWindow API function, that sometimes fails.
' WARNING: Apparently, AttachThreadInput can lead to a deadlock.
' See: https://blogs.msdn.microsoft.com/oldnewthing/20080801-00/?p=21393
' ========================================================================================
PRIVATE SUB AfxForceSetForegroundWindow (BYVAL hWin AS HWND)
   DIM dwProcessId AS DWORD
   DIM hwndForeground AS .HWND = GetForegroundWindow
   DIM dwThreadId AS DWORD = GetWindowThreadProcessId(hwndForeground, @dwProcessId)
   DIM dwCurThreadId AS DWORD = GetCurrentThreadId
   AttachThreadInput(dwCurThreadId, dwThreadId, CTRUE)
   SetForegroundWindow(hWin)
   BringWindowToTop(hWin)
   SetFocus(hWin)
   AttachThreadInput(dwCurThreadId, dwThreadId, FALSE)
END SUB
' ========================================================================================

' ========================================================================================
' If you use dual (or even triple/quad) displays then you have undoubtedly encountered the
' following situation: You change the physical order of your displays, or otherwise
' reconfigure the logical ordering using your display software. This sometimes has the
' side-effect of changing your desktop coordinates from zero-based to negative starting
' coordinates (i.e. the top-left coordinate of your desktop changes from 0,0 to -1024,-768).
' This effects many Windows programs which restore their last on-screen position whenever
' they are started. Should the user reorder their display configuration this can sometimes
' result in a Windows program subsequently starting in an off-screen position (i.e. at a
' location that used to be visible) - and is now effectively invisible, preventing the
' user from closing it down or otherwise moving it back on-screen.
' The ForceVisibleDisplay function can be called at program start-time right after the
' main window has been created and positioned 'on-screen'. Should the window be positioned
' in an off-screen position, it is forced back onto the nearest display to its last
' position. The user will be unaware this is happening and won't even realise to thank you
' for keeping their user-interface visible, even though they changed their display
' settings.
' Source: http://www.catch22.net/tuts/tips2
' ========================================================================================
PRIVATE SUB AfxForceVisibleDisplay (BYVAL hWin AS HWND)
   ' // Check if the specified window-rectangle is visible on any display
   DIM rc AS RECT
   GetWindowRect(hWin, @rc)
   IF MonitorFromRect(@rc, MONITOR_DEFAULTTONULL) <> NULL THEN EXIT SUB
   ' // Find the nearest display to the rectangle
   DIM hMonitor AS HMONITOR
   DIM mi AS MONITORINFO
   mi.cbSize = SIZEOF(mi)
   hMonitor = MonitorFromRect(@rc, MONITOR_DEFAULTTONEAREST)
   GetMonitorInfoW(hMonitor, @mi)
   ' // Center window rectangle
   rc.left = mi.rcWork.left + ((mi.rcWork.right - mi.rcWork.left) - (rc.right-rc.left)) \ 2
   rc.top = mi.rcWork.top + ((mi.rcWork.bottom - mi.rcWork.top) - (rc.bottom-rc.top)) \ 2
   SetWindowPos(hWin, 0, rc.left, rc.top, 0, 0, SWP_NOACTIVATE OR SWP_NOZORDER OR SWP_NOSIZE)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the window's top-level parent or owner window.
' ========================================================================================
PRIVATE FUNCTION AfxGetTopLevelWindow (BYVAL hWin AS HWND) AS HWND
   DIM hWndParent AS HWND, hWndTmp AS HWND
   IF IsWindow(hWin) = NULL THEN EXIT FUNCTION
   hWndTmp = hWin
   DO
      hWndParent = hWndTmp
      hWndTmp = IIF(GetWindowLongPtrW(hwndParent, GWL_STYLE) AND WS_CHILD, GetParent(hwndParent), GetWindow(hWndParent, GW_OWNER))
      IF hWndTmp = NULL THEN EXIT DO
   LOOP
   FUNCTION = hWndParent
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the window's top-level parent window.
' ========================================================================================
PRIVATE FUNCTION AfxGetTopLevelParent (BYVAL hWin AS HWND) AS HWND
   DIM hWndParent AS HWND, hWndTmp AS HWND
   IF IsWindow(hWin) = NULL THEN EXIT FUNCTION
   hWndParent = hWin
   DO
      hWndTmp = GetParent(hWndParent)
      IF hWndTmp = NULL THEN EXIT DO
      hWndParent = hWndTmp
   LOOP
   FUNCTION = hWndParent
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds the handle of the top-level window or MDI child window that is the ancestor of the
' specified window handle. The reference handle is the handle of any control on the form.
' Code borrowed from a function written by Dominic Mitchell for Phoenix.
' ========================================================================================
PRIVATE FUNCTION AfxGetFormHandle (BYVAL hWin AS HWND) AS HWND
   WHILE (GetWindowLongPtrW(hWin, GWL_STYLE) AND WS_CHILD)
      IF (GetWindowLongPtrW(hWin, GWL_EXSTYLE) AND WS_EX_MDICHILD) THEN EXIT WHILE
      hWin = GetParent(hWin)
   WEND
   FUNCTION = hWin
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle of the control with the specified identifier. The reference handle
' can be the handle of the form or the handle of any other control on the form.
' Parameters:
' - hwnd = Reference window handle.
' - Control identifier.
' Returns the handle of the control or NULL.
' ========================================================================================

' // Enumerates child controls on the specified window.
' // Callback function for AfxGetControlHandle.
' // Parameters:
' // hwnd = Handle of child window.
' // lParam = Address of variable with child window handle
' // Return value: CTRUE or FALSE

PRIVATE FUNCTION AfxGetControlHandle_ChildEnumProc (BYVAL hWin AS HWND, BYVAL lPrm AS LPARAM) AS LONG
   DIM pItem AS HWND PTR
   CAST(LPARAM, pItem) = lPrm
   IF GetDlgCtrlID(hWin) = LOWORD(*pItem) THEN
      *pItem = hWin
      EXIT FUNCTION
   END IF
   FUNCTION = CTRUE
END FUNCTION

PRIVATE FUNCTION AfxGetControlHandle (BYVAL hWin AS HWND, BYVAL wCtrlID AS WORD) AS HWND
   DIM hwndChild AS HWND
   hWin = AfxGetFormHandle(hWin)
   hwndChild = cast(HWND, CAST(DWORD_PTR, wCtrlID))
   EnumChildWindows(hWin, @AfxGetControlHandle_ChildEnumProc, cast(LPARAM, @hwndChild))
   IF hwndChild = wCtrlID THEN FUNCTION = NULL ELSE FUNCTION = hwndChild
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle of the enabled and visible window at the top of the z-order in an
' application.
' Return value: Handle of window at top of z-order or NULL.
' ========================================================================================

' // Callback enumeration procedure for finding the window at the top of the z-order.
' // Parameters:
' // hwnd = Handle of top-level window
' // lParam = Address of variable for window handle

PRIVATE FUNCTION AfxGetTopEnabledWindow_EnumWindowsProc (BYVAL hWin AS HWND, BYVAL lPrm AS LPARAM) AS LONG
   DIM wszClassName AS WSTRING * MAX_PATH, phwndTop AS HWND PTR, dwProcessId  AS DWORD
   IF IsWindowEnabled(hWin) THEN
      IF IsWindowVisible(hWin) THEN
         GetClassNameW hWin, @wszClassName, MAX_PATH
         IF wszClassName <> "tooltips_class32" THEN
            GetWindowThreadProcessId(hWin, @dwProcessId)
            IF dwProcessId = GetCurrentProcessId THEN
               cast(LPARAM, phwndTop) = lPrm
               *phwndTop = hWin
               EXIT FUNCTION
            END IF
         END IF
      END IF
   END IF
   FUNCTION = CTRUE
END FUNCTION

PRIVATE FUNCTION AfxGetTopEnabledWindow () AS HWND
   DIM hwndTop AS HWND
   EnumWindows(@AfxGetTopEnabledWindow_EnumWindowsProc, CAST(LPARAM, @hwndTop))
   FUNCTION = hwndTop
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a window handle given it's process identifier
' ========================================================================================
PRIVATE FUNCTION AfxGethWndFromPID (BYVAL PID AS DWORD) AS HWND
   DIM dwPID AS DWORD, dwThreadID AS DWORD
   ' // Get the first window handle
   DIM hWin AS HWND = FindWindowW(NULL, NULL)
   ' // Enumerate all the windows
   WHILE hWin <> NULL
      ' // If the parent window is NULL, it's a top level window
      IF GetParent(hWin) = NULL THEN
         ' // Get it's process id
         dwThreadID = GetWindowThreadProcessId(hWin, @dwPID)
         IF dwPID = PID THEN
            ' // We have found it
            FUNCTION = hWin
            EXIT WHILE
         END IF
      END IF
      ' // Get the next window handle
      hWin = GetWindow(hWin, GW_HWNDNEXT)
   WEND
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the return value of a message processed in the dialog box procedure.
' Return value: TRUE or FALSE.
' Must be set just before exiting the callback message (not after calling other functions)
' See https://forum.powerbasic.com/forum/user-to-user-discussions/programming/19130-info-dwl_msgresult
' ========================================================================================
PRIVATE FUNCTION AfxSetDlgMsgResult(BYVAL hDlg AS HWND, BYVAL uMsg AS UINT, BYVAL result AS LONG_PTR) AS BOOLEAN
   IF uMsg = WM_CTLCOLORMSGBOX      OR _
      uMsg = WM_CTLCOLOREDIT        OR _
      uMsg = WM_CTLCOLORLISTBOX     OR _
      uMsg = WM_CTLCOLORBTN         OR _
      uMsg = WM_CTLCOLORDLG         OR _
      uMsg = WM_CTLCOLORSCROLLBAR   OR _
      uMsg = WM_CTLCOLORSTATIC      OR _
      uMsg = WM_COMPAREITEM         OR _
      uMsg = WM_VKEYTOITEM          OR _
      uMsg = WM_CHARTOITEM          OR _
      uMsg = WM_QUERYDRAGICON       OR _
      uMsg = WM_INITDIALOG          THEN
      FUNCTION = IIF(SetWindowLongPtrW(hDlg, DWLP_MSGRESULT, result), TRUE, FALSE)
   END IF
END FUNCTION
' ========================================================================================
'#define SetDlgMsgResult(hwnd,msg,result) (iif((msg)=WM_CTLCOLORMSGBOX orelse (msg)=WM_CTLCOLOREDIT orelse
'(msg)=WM_CTLCOLORLISTBOX orelse (msg)=WM_CTLCOLORBTN orelse (msg)=WM_CTLCOLORDLG orelse (msg)=WM_CTLCOLORSCROLLBAR
'orelse (msg)=WM_CTLCOLORSTATIC orelse (msg)=WM_COMPAREITEM orelse (msg)=WM_VKEYTOITEM orelse (msg)=WM_CHARTOITEM
'orelse (msg)=WM_QUERYDRAGICON orelse (msg)=WM_INITDIALOG, cast(WINBOOL, (result)),
'(SetWindowLongPtr((hwnd),DWLP_MSGRESULT,cast(LPARAM, cast(LRESULT, result)),TRUE))))
' ========================================================================================

' ========================================================================================
' // For compatibility with PowerBasic
' ========================================================================================
#define WindowGetHandle(hWin, id) GetDlgItem(hWin, id)
#define WindowGetID(hWin) GetDlgCtrlID(hWin)
#define WindowGetParent(hWin) GetParent(hWin)
#define WindowGetStyle AfxGetWindowStyle
#define WindowGetStyleXX AfxGetWindowExStyle
#define WindowSetID(hWin, newID) SetWindowLongPtrW(hWin, GWLP_ID, newID)
#define WindowSetStyle AfxSetWindowStyle
#define WindowSetStyleXX AfxSetWindowExStyle
#define WindowGetUser(hWin) GetWindowLongPtrW(hWin, GWLP_USERDATA)
#define WindowSetUser(hWin, newVal) SetWindowLongPtrW(hWin, GWLP_USERDATA, cast(LONG_PTR, newVal))
' ========================================================================================

' ########################################################################################
'                                    *** DESKTOP ***
' ########################################################################################

' ========================================================================================
' Retrieves a handle to the desktop window. The desktop window covers the entire screen.
' The desktop window is the area on top of which other windows are painted.
' ========================================================================================
PRIVATE FUNCTION AfxGetDesktopWindow () AS HWND
   RETURN GetDesktopWindow
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the location of the work area on the primary display monitor. The work area is the
' portion of the screen not obscured by the system taskbar or by application desktop toolbars.
' The pvParam parameter must point to a RECT structure that receives the coordinates of the
' work area, expressed in physical pixel size. Any DPI virtualization mode of the caller has
' no effect on this output.
' ========================================================================================
PRIVATE FUNCTION AfxGetDesktopLocation (BYREF x AS LONG, BYREF y AS LONG) AS BOOLEAN
   IF VARPTR(x) = 0 OR VARPTR(y) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   FUNCTION = SystemParametersInfo(SPI_GETWORKAREA, 0, @rc, 0)
   x = rc.Left
   y = rc.Top
   RETURN TRUE
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetDesktopLocationX () AS LONG
   DIM rc AS RECT
   FUNCTION = SystemParametersInfo(SPI_GETWORKAREA, 0, @rc, 0)
   RETURN rc.Left
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetDesktopLocationY () AS LONG
   DIM rc AS RECT
   FUNCTION = SystemParametersInfo(SPI_GETWORKAREA, 0, @rc, 0)
   RETURN rc.Right
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size of the entire desktop, in pixels.
' ========================================================================================
PRIVAtE FUNCTION AfxGetDesktopSize (BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   IF VARPTR(nWidth) = 0 OR VARPTR(nHeight) = 0 THEN RETURN FALSE
   DIM hwndDesktop AS HWND = GetDesktopWindow
   DIM rc AS RECT
   DIM bRes AS BOOLEAN = GetWindowRect(hwndDesktop, @rc)
   IF bRes = FALSE THEN RETURN FALsE
   nWidth = rc.Right - rc.Left
   nHeight = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVAtE FUNCTION AfxGetDesktopWidth () AS LONG
   DIM hwndDesktop AS HWND = GetDesktopWindow
   DIM rc AS RECT
   DIM bRes AS BOOLEAN = GetWindowRect(hwndDesktop, @rc)
   IF bRes = FALSE THEN RETURN 0
   RETURN rc.Right - rc.Left
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVAtE FUNCTION AfxGetDesktopHeight () AS LONG
   DIM hwndDesktop AS HWND = GetDesktopWindow
   DIM rc AS RECT
   DIM bRes AS BOOLEAN = GetWindowRect(hwndDesktop, @rc)
   IF bRes = FALSE THEN RETURN 0
   RETURN rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size of the client area of the desktop, in pixels.
' ========================================================================================
PRIVAtE FUNCTION AfxGetDesktopClientSize (BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS BOOLEAN
   IF VARPTR(nWidth) = 0 OR VARPTR(nHeight) = 0 THEN RETURN FALSE
   DIM hwndDesktop AS HWND = GetDesktopWindow
   DIM rc AS RECT
   DIM bRes AS BOOLEAN = GetClientRect(hwndDesktop, @rc)
   IF bRes = FALSE THEN RETURN FALsE
   nWidth = rc.Right - rc.Left
   nHeight = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVAtE FUNCTION AfxGetDesktopClientWidth () AS LONG
   DIM hwndDesktop AS HWND = GetDesktopWindow
   DIM rc AS RECT
   DIM bRes AS BOOLEAN = GetClientRect(hwndDesktop, @rc)
   IF bRes = FALSE THEN RETURN 0
   RETURN rc.Right - rc.Left
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVAtE FUNCTION AfxGetDesktopClientHeight () AS LONG
   DIM hwndDesktop AS HWND = GetDesktopWindow
   DIM rc AS RECT
   DIM bRes AS BOOLEAN = GetClientRect(hwndDesktop, @rc)
   IF bRes = FALSE THEN RETURN 0
   RETURN rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of pixels per logical inch along the screen width and height.
' In a system with multiple display monitors, this value is the same for all monitors.
' Remarks: The resolution is always specified in pixels.  This procedure is particularly
' useful in drawing items such as rulers and graphs to a "representative physical size".
' There are 25.4 millimeters per inch, so just divide by 25.4 to convert from
' pixels per inch to pixels per millimeter.
' ========================================================================================
PRIVATE SUB AfxGetDesktopPPI (BYREF xPPI AS LONG, BYREF yPPI AS LONG)
   IF VARPTR(xPPI) = 0 OR VARPTR(yPPI) = 0 THEN EXIT SUB
   DIM hDC As ..HDC
   ' // Get the device context for the screen
   hDC = GetDC(NULL)
   ' // Retrieve horizontal and vertical PPI
   xPPI = GetDeviceCaps(hDC, LOGPIXELSX)
   yPPI = GetDeviceCaps(hDC, LOGPIXELSY)
   ' // Release the device context
   ReleaseDC(NULL, hDC)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetDesktopPPIX () AS LONG
   DIM hDC As ..HDC
   ' // Get the device context for the screen
   hDC = GetDC(NULL)
   ' // Retrieve horizontal and vertical PPI
   DIM xPPI AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ' // Release the device context
   ReleaseDC(NULL, hDC)
   RETURN xPPI
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CAfxGetDesktopPPIY () AS LONG
   DIM hDC As ..HDC
   ' // Get the device context for the screen
   hDC = GetDC(NULL)
   ' // Retrieve horizontal and vertical PPI
   DIM yPPI AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ' // Release the device context
   ReleaseDC(NULL, hDC)
   RETURN yPPI
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the coordinates of the work area on the primary display monitor expressed in
' virtual screen coordinates. The work area is the portion of the screen not obscured by
' the system taskbar or by application desktop toolbars. To get the work area of a monitor
' other than the primary display monitor, call the GetMonitorInfo function.
' ========================================================================================
PRIVATE FUNCTION AfxGetWorkAreaRect () AS RECT
   DIM rcWrk AS RECT
   SystemParametersInfo(SPI_GETWORKAREA, 0, @rcWrk, 0)
   FUNCTION = rcWrk
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetWorkAreaWidth () AS LONG
   DIM rcWrk AS RECT
   SystemParametersInfo(SPI_GETWORKAREA, 0, @rcWrk, 0)
   FUNCTION = rcWrk.Right - rcWrk.Left
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxGetWorkAreaHeight () AS LONG
   DIM rcWrk AS RECT
   SystemParametersInfo(SPI_GETWORKAREA, 0, @rcWrk, 0)
   FUNCTION = rcWrk.Bottom - rcWrk.Top
END FUNCTION
' ========================================================================================

' // For compatibility with PowerBasic
#define DesktopGetClient AfxGetDesktopClientSize
#define DesktopGetLoc AfxGetDesktopLocation
#define DesktopGetSize AfxGetDesktopSize

' ########################################################################################
'                                    *** DISPLAY ***
' ########################################################################################

' ========================================================================================
' Retrieves the width of the screen, in pixels.
' ScreenWidth is virtualized for DPI.
' ========================================================================================
PRIVATE FUNCTION AfxScreenWidth () AS LONG
   DIM rc AS RECT
   GetWindowRect(GetDesktopWindow, @rc)
   RETURN rc.right - rc.left
END FUNCTION
' ========================================================================================
#define AfxGetScreenWidth AfxScreenWidth
' ========================================================================================

' ========================================================================================
' Retrieves the height of the screen, in pixels.
' ScreenHeight is virtualized for DPI.
' ========================================================================================
PRIVATE FUNCTION AfxScreenHeight () AS LONG
   DIM rc AS RECT
   GetWindowRect(GetDesktopWindow, @rc)
   RETURN rc.bottom - rc.top
END FUNCTION
' ========================================================================================
#define AfxGetScreenHeight AfxScreenHeight
' ========================================================================================

' ========================================================================================
' Returns the width, in pixels, of the current display device on the computer on which the
' calling thread is running. Contrarily to GetSystemMetrics or GetDeviceCaps, it returns
' the real width even when it is called from an application that is not DPI aware, e.g. an
' application running virtualized in a monitor 1920 pixels width and a DPI of 192, will
' return 960 pixels if it calls GetSystemMetrics or GetDeviceCaps, but will return 1920
' pixels calling EnumDisplaySettingsW.
' ========================================================================================
PRIVATE FUNCTION AfxGetDisplayPixelsWidth () AS DWORD
   DIM dm AS DEVMODEW
   dm.dmSize = SIZEOF(dm)
   EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, @dm)
   FUNCTION = dm.dmPelsWidth
END FUNCTION
' ========================================================================================
#define AfxDisplayPixelsWidth AfxGetDisplayPixelsWidth
' ========================================================================================

' ========================================================================================
' Returns the height, in pixels, of the current display device on the computer on which the
' calling thread is running.
' ========================================================================================
PRIVATE FUNCTION AfxGetDisplayPixelsHeight () AS DWORD
   DIM dm AS DEVMODEW
   dm.dmSize = SIZEOF(dm)
   EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, @dm)
   FUNCTION = dm.dmPelsHeight
END FUNCTION
' ========================================================================================
#define AfxDisplayPixelsHeight AfxGetDisplayPixelsHeight
' ========================================================================================

' ========================================================================================
' Returns the color resolution, in bits per pixel, of the display device.
' ========================================================================================
PRIVATE FUNCTION AfxGetDisplayBitsPerPixel () AS DWORD
   DIM dm AS DEVMODEW
   dm.dmSize = SIZEOF(dm)
   EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, @dm)
   FUNCTION = dm.dmBitsPerPel
END FUNCTION
' ========================================================================================
#define AfxScreenColors AfxGetDisplayBitsPerPixel
#define AfxGetScreenColors AfxGetDisplayBitsPerPixel
' ========================================================================================

' ========================================================================================
' Returns the frequency, in hertz (cycles per second), of the display device in a
' particular mode. This value is also known as the display device's vertical refresh rate.
' ========================================================================================
PRIVATE FUNCTION AfxGetDisplayFrequency () AS DWORD
   DIM dm AS DEVMODEW
   dm.dmSize = SIZEOF(dm)
   EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, @dm)
   FUNCTION = dm.dmDisplayFrequency
END FUNCTION
' ========================================================================================
#define AfxScreenRefreshRate AfxGetDisplayFrequency
#define AfxGetScreenRefreshRate AfxGetDisplayFrequency
' ========================================================================================

' ========================================================================================
' Retrieves the coordinates of the work area on the primary display monitor expressed in
' virtual screen coordinates. The work area is the portion of the screen not obscured by
' the system taskbar or by application desktop toolbars. To get the work area of a monitor
' other than the primary display monitor, call the GetMonitorInfo function.
' ========================================================================================
PRIVATE FUNCTION AfxGetWorkArea () AS RECT
   DIM rcWrk AS RECT
   SystemParametersInfo(SPI_GETWORKAREA, 0, @rcWrk, 0)
   FUNCTION = rcWrk
END FUNCTION
' ========================================================================================
#define AfxWorkArea AfxGetWorkArea
' ========================================================================================


' ########################################################################################
'                                *** METRIC CONVERSIONS ***
' ########################################################################################

' ========================================================================================
' Converts from HiMetric to Pixels
' Note: HiMetric is a scaling unit similar to twips used in computing. It is one
' thousandth of a centimeter and is independent of the screen resolution.
' HiMetric per inch = 2540   ' 1 inch = 2.54 mm
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxHiMetricToPixelsX (BYVAL hm AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM nPixelsPerLogicalInchX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = MulDiv(hm, nPixelsPerLogicalInchX, 2540)
END FUNCTION
' ========================================================================================
' Vertical resolution
PRIVATE FUNCTION AfxHiMetricToPixelsY (BYVAL hm AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM nPixelsPerLogicalInchY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = MulDiv(hm, nPixelsPerLogicalInchY, 2540)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts from Pixels to HiMetric
' Note: HiMetric is a scaling unit similar to twips used in computing. It is one
' thousandth of a centimeter and is independent of the screen resolution.
' HiMetric per inch = 2540   ' 1 inch = 2.54 mm
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxPixelsToHiMetricX (BYVAL cx AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM nPixelsPerLogicalInchX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = MulDiv(cx, 2540, nPixelsPerLogicalInchX)
END FUNCTION
' ========================================================================================
' Vertical resolution
PRIVATE FUNCTION AfxPixelsToHiMetricY (BYVAL cy AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM nPixelsPerLogicalInchY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = MulDiv(cy, 2540, nPixelsPerLogicalInchY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts pixels to point size (1/72 of an inch).
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxPixelsToPointsX (BYVAL pix AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = pix * 72 / LPX
END FUNCTION
' ========================================================================================
' Vertical resolution
PRIVATE FUNCTION AfxPixelsToPointsY (BYVAL pix AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = pix * 72 / LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a point size (1/72 of an inch) to pixels. Horizontal resolution.
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxPointsToPixelsX (BYVAL pts AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = MulDiv(pts, LPX, 72)
END FUNCTION
' ========================================================================================
' Vertical resolution
PRIVATE FUNCTION AfxPointsToPixelsY (BYVAL pts AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = MulDiv(pts, LPY, 72)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts pixels to twips.
' Twips are screen-independent units to ensure that the proportion of screen elements are
' the same on all display systems. A twip is defined as being 1/1440 of an inch.
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxPixelsToTwipsX (BYVAL nPixels AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = (nPixels * 1440) / LPX
END FUNCTION
' ========================================================================================
' Vertical resolution.
PRIVATE FUNCTION AfxPixelsToTwipsY (BYVAL nPixels AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = (nPixels * 1440) / LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts twips to pixels.
' Twips are screen-independent units to ensure that the proportion of screen elements are
' the same on all display systems. A twip is defined as being 1/1440 of an inch.
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxTwipsToPixelsX (BYVAL nTwips AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = (nTwips / 1440) * LPX
END FUNCTION
' ========================================================================================
' Vertical resolution
PRIVATE FUNCTION AfxTwipsToPixelsY (BYVAL nTwips AS LONG) AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = (nTwips / 1440) * LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width of a pixel, in twips.
' Pixel dimensions can vary between systems and may not always be square, so separate
' functions for pixel width and height are required.
' ========================================================================================
' Horizontal resolution
PRIVATE FUNCTION AfxTwipsPerPixelX () AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPX AS LONG = GetDeviceCaps(hDC, LOGPIXELSX)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = 1440 / LPX
END FUNCTION
' ========================================================================================
' Vertical resolution
PRIVATE FUNCTION AfxTwipsPerPixelY () AS LONG
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)
   DIM LPY AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = 1440 / LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts point size to DIP (device independent pixel).
' DIP is defined as 1/96 of an inch and a point is 1/72 of an inch.
' ========================================================================================
PRIVATE FUNCTION AfxPointSizeToDip (BYVAL ptsize AS SINGLE) AS SINGLE
   FUNCTION = (ptsize / 72) * 96
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts the specified dialog box units to screen units (pixels).
' ========================================================================================
PRIVATE FUNCTION AfxDialogUnitsToPixels (BYVAL hDlg AS HWND, BYVAL dluX AS LONG, BYVAL dluY AS LONG, BYREF pixelX AS LONG, BYREF pixelY AS LONG) AS BOOLEAN
   IF hDlg = NULL THEN RETURN FALSE
   IF VARPTR(pixelX) = 0 OR VARPTR(pixelY) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   rc.Left = dluX : rc.Top = dluY
   DIM bResult AS BOOLEAN = MapDialogRect(hDlg, @rc)
   IF bResult = FALSE THEN RETURN FALSE
   IF VARPTR(pixelX) THEN pixelX = rc.Left
   IF VARPTR(pixelY) THEN pixelY = rc.Top
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts the specied screen units (pixels) to dialog box units.
' ========================================================================================
PRIVATE FUNCTION AfxPixelsToDialogUnits (BYVAL hDlg AS HWND, BYVAL pixelX AS LONG, BYVAL pixelY AS LONG, BYREF dluX AS LONG, BYREF dluY AS LONG) AS BOOLEAN
   IF hDlg = NULL THEN RETURN FALSE
   IF VARPTR(pixelX) = 0 OR VARPTR(pixelY) = 0 THEN RETURN FALSE
   DIM rc AS RECT
   rc.Left = pixelX
   rc.Top = pixelY
   DIM bResult AS BOOLEAN = MapDialogRect(hDlg, @rc)
   IF bResult = FALSE THEN RETURN FALSE
   DIM rx AS SINGLE
   rx = rc.Left / pixelX
   DIM ry AS SINGLE
   ry = rc.Top / pixelY
   IF VARPTR(dluX) THEN dluX = pixelX / rx
   IF VARPTR(dluY) THEN dluY = pixelY / ry
   RETURN TRUE
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                    *** CLIPBOARD ***
' ########################################################################################

' ========================================================================================
' Clears the contents of the clipboard.
' Return Value
'   If the function succeeds, the return value is nonzero.
'   If the function fails, the return value is zero.
' ========================================================================================
PRIVATE FUNCTION AfxClearClipboard () AS BOOLEAN
   ' // Opens the clipboard
   IF OpenClipboard(NULL) <> 0 THEN
      ' // Empties the clipboard
      FUNCTION = EmptyClipboard
      ' // Closes the clipboard
      CloseClipboard
   END IF
END FUNCTION
' ========================================================================================
#define ClipboardReset AfxClearClipboard
' ========================================================================================

' ========================================================================================
' Retrieves data from the clipboard in the specified format.
' Parameter
'   cfFormat = Clipboard format.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' ========================================================================================
PRIVATE FUNCTION AfxGetClipboardData (BYVAL uFormat AS DWORD) AS HGLOBAL
   DIM hSource AS HANDLE
   ' // Opens the clipboard
   IF OpenClipboard(NULL) <> 0 THEN
      ' // Retrieves data from the clipboard in the specified format
      hSource = GetClipboardData(uFormat)
      ' // Closes the clipboard
      CloseClipboard
      ' // Exits on failure
      IF hSource = NULL THEN EXIT FUNCTION
   END IF
   ' // Gets the size of the specified global memory object, in bytes
   DIM dwSize AS SIZE_T_ = GlobalSize(hSource)
   ' // Exits on failure
   IF dwSize = 0 THEN EXIT FUNCTION
   ' // Gets a pointer to the source memory object
   DIM pSource AS LPVOID = GlobalLock(hSource)
   ' // Exits on failure
   IF pSource = NULL THEN EXIT FUNCTION
   ' // Allocates the specified number of bytes from the heap
   DIM hDest AS HGLOBAL = GlobalAlloc(GHND_, dwSize)
   ' // Exits on failure
   IF hDest = NULL THEN
      ' // Unlocks the source memory object
      GlobalUnlock hSource
      EXIT FUNCTION
   END IF
   ' // Gets a pointer to the destination memory object
   DIM pDest AS LPVOID = GlobalLock(hDest)
   ' // Exits on failure
   IF pDest = NULL THEN
      ' // Unlocks the source memory object
      GlobalUnlock hSource
      ' // Frees the allocated memory block
      GlobalFree hDest
      EXIT FUNCTION
   END IF
   ' // Copies the data from the source to the destination
   memcpy pDest, pSource, dwSize
   ' // Unlocks the source memory object
   GlobalUnlock hSource
   ' // Unlocks the destination memory object
   GlobalUnlock hDest
   ' // Returns the handle to the data
   FUNCTION = hDest
END FUNCTION
' ========================================================================================
#define ClipboardGetData(fmt) AfxGetClipboardData(fmt)
#define ClipboardGetBitmap AfxGetClipboardData(CF_BITMAP)
' ========================================================================================

' ========================================================================================
' Places a data object into the clipboard.
' Parameters
'   cfFormat = Clipboard format.
'   hData    = Handle to the data in the specified format.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' Remarks
'   The application must not use the hData handle once it has called the AfxSetClipboardData function.
' ========================================================================================
PRIVATE FUNCTION AfxSetClipboardData (BYVAL uFormat AS UINT, BYVAL hData AS HANDLE) AS HANDLE
   ' // Opens the clipboard
   IF OpenClipboard(NULL) <> 0 THEN
      ' // Empties the clipboard
      EmptyClipboard
      ' // Places the data object in the clipboard
      FUNCTION = SetClipboardData(uFormat, hData)
      ' // Closes the clipboard
      CloseClipboard
    END IF
END FUNCTION
' ========================================================================================
#define ClipboardSetData (fmt) AfxSetClipboardData(fmt)
#define ClipboardSetBitmap AfxSetClipboardData(CF_BITMAP)
' ========================================================================================

' ========================================================================================
' Returns a text string from the clipboard in the specified format.
' ========================================================================================
PRIVATE FUNCTION AfxGetClipboardText (BYVAL uFormat AS UINT = CF_UNICODETEXT) AS DWSTRING
   DIM dwsText AS DWSTRING
   ' // Check if the required format is available
   IF IsClipboardFormatAvailable(uFormat) = 0 THEN RETURN ""
   ' // Open the clipboard
   IF OpenClipboard(NULL) = 0 THEN RETURN ""
   ' // Get memory object of clipboard text
   DIM hMem AS HANDLE = GetClipboardData(uFormat)
   IF hMem = NULL THEN
      CloseClipboard
      RETURN ""
   END IF
   ' // Lock it and get a pointer to the data
   DIM pMem AS HGLOBAL = GlobalLock(hMem)
   IF pMem = NULL THEN
      CloseClipboard
      RETURN ""
   END IF
   ' // Get the size of the global lock
   DIM dwSize AS DWORD = GlobalSize(hMem)
   IF dwSize > 0 THEN dwsText.AppendBuffer(pMem, dwSize)
   ' // Releases the memory object
   GlobalUnlock hMem
   ' // Closes the clipboard
   CloseClipboard
   RETURN dwsText
END FUNCTION
' ========================================================================================
#define ClipboardGetText AfxGetClipboardText(CF_TEXT)
#define ClipboardGetOemText AfxGetClipboardText(CF_OEMTEXT)
#define ClipboardGetUnicode AfxGetClipboardText(CF_UNICODETEXT)
' ========================================================================================

' ========================================================================================
' Places an unicode text string into the clipboard.
' Parameter
'   wszText = Text to place in the clipboard.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' ========================================================================================
PRIVATE FUNCTION AfxSetClipboardText (BYREF wszText AS WSTRING, BYVAL uFormat AS UINT = CF_UNICODETEXT) AS HANDLE
   ' // Opens the clipboard
   IF OpenClipboard(NULL) <> 0 THEN
      ' // Empties the clipboard
      EmptyClipboard
      ' // Allocates a global memory block
      DIM hMem AS HGLOBAL = GlobalAlloc(GMEM_MOVEABLE OR GMEM_DDESHARE, (LEN(wszText) + 1) * 2)
      IF hMem <> NULL THEN
         ' // Locks it and gets a pointer to the memory location
         DIM pMem AS LPVOID = GlobalLock(hMem)
         ' // Copies the text into the allocated memory block
         IF pMem <> NULL THEN *CAST(WSTRING PTR, pMem) = wszText & CHR(0, 0)
         ' // Unlocks the memory block
         GlobalUnlock hMem
         ' // Places the text in the clipboard
         DIM hData AS HANDLE = SetClipboardData(uFormat, hMem)
         IF hData <> NULL THEN
            ' // Returns the handle of the data
            FUNCTION = hData
         ELSE
            ' // Frees the memory block
            GlobalFree hMem
         END IF
      END IF
      ' // Closes the clipboard
      CloseClipboard
   END IF
END FUNCTION
' ========================================================================================
#define ClipboardSetText(txt) AfxSetClipboardText(txt, CF_TEXT)
#define ClipboardSetOemText(txt) AfxSetClipboardText(txt, CF_OEMTEXT)
#define ClipboardSetUnicode(txt) AfxSetClipboardText(txt, CF_UNICODETEXT)
' ========================================================================================


' ########################################################################################
'                                      *** FONTS ***
' ########################################################################################

' ========================================================================================
' Font enum
' ========================================================================================
enum
   AFX_FONT_CAPTION = 1    ' // Caption font
   AFX_FONT_SMALLCAPTION   ' // Small caption font
   AFX_FONT_MENU           ' // Font used in menu bars
   AFX_FONT_STATUS         ' // Font used in status bars and tooltips
   AFX_FONT_MESSAGE        ' // Font used in message boxes
   ' // Font settings
   AFX_FONT_HEIGHT         ' // Font height
   AFX_FONT_WEIGHT         ' // Font weight
   AFX_FONT_ITALIC         ' // Font italic
   AFX_FONT_UNDERLINE      ' // Font underline
   AFX_FONT_STRIKEOUT      ' // Font strikeout
   AFX_FONT_CHARSET        ' // Font charset
end enum
' ========================================================================================

' ========================================================================================
' Gets the font with which the window is currently drawing its text.
' Note: You can also use the GetWindowFont macro (windowsx.bi).
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowFont (BYVAL hWin AS HWND) AS HFONT
   FUNCTION = cast(HFONT, SendMessageW(hWin, WM_GETFONT, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font with which the window is currently drawing its text.
' hwnd
'   Handle to the window.
' hFont
'   Handle to the font. If this parameter is NULL, the control uses the default system
'   font to draw text.
' fRedraw
'   Specifies whether the control should be redrawn immediately upon setting the font. If
'   this parameter is TRUE, the control redraws itself.
' ========================================================================================
PRIVATE SUB AfxSetWindowFont (BYVAL hWin AS HWND, BYVAL hFont AS HFONT, BYVAL fRedraw AS LONG = CTRUE)
   SendMessageW(hWin, WM_SETFONT, cast(WPARAM, hFont), fRedraw)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves information about the font being used by a window or control
' Parameter:
' - hwnd = Handle of the window or control.
' Return value:
' - A LOGFONTW structure.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowFontInfo (BYVAL hWin AS HWND) AS LOGFONTW
   ' // Get the handle of the font used by the window or control
   DIM hCurFont AS HFONT = cast(HFONT, SendMessageW(hWin, WM_GETFONT, 0, 0))
   ' // Get the LOGFONTW structure
   DIM lfw AS LOGFONTW
   IF hCurFont THEN GetObjectW(hCurFont, SIZEOF(lfw), @lfw)
   RETURN lfw
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the fonts used by Windows.
' Parameters:
' - nType = The type of font:
'   AFX_FONT_CAPTION, AFX_FONT_SMALLCAPTION, AFX_FONT_MENU, AFX_FONT_STATUS, AFX_FONT_MESSAGE
' - plfw = Pointer to a LOGFONTW structure that receives the font information.
' Return value: TRUE on succes or FALSE on failure.
' To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowsFontInfo (BYVAL nType AS LONG, BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
   DIM ncm AS NONCLIENTMETRICSW
   IF plfw = NULL THEN EXIT FUNCTION
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) = 0 THEN EXIT FUNCTION
   SELECT CASE nType
      CASE AFX_FONT_CAPTION      : *plfw = ncm.lfCaptionFont
      CASE AFX_FONT_SMALLCAPTION : *plfw = ncm.lfSmCaptionFont
      CASE AFX_FONT_MENU         : *plfw = ncm.lfMenuFont
      CASE AFX_FONT_STATUS       : *plfw = ncm.lfStatusFont
      CASE AFX_FONT_MESSAGE      : *plfw = ncm.lfMessageFont
      CASE ELSE
         RETURN FALSE
   END SELECT
   FUNCTION = TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the point size of the fonts used by Windows.
' Parameters:
' - nType = The type of font:
'   AFX_FONT_CAPTION, AFX_FONT_SMALLCAPTION, AFX_FONT_MENU, AFX_FONT_STATUS, AFX_FONT_MESSAGE
' Return value: The point size.
' ========================================================================================
PRIVATE FUNCTION AfxGetWindowsFontPointSize (BYVAL nType AS LONG) AS LONG
   DIM ncm AS NONCLIENTMETRICSW
   IF AfxWindowsVersion >= 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), @ncm, 0) = 0 THEN EXIT FUNCTION
   DIM hDC AS HDC = CreateDCW("DISPLAY", NULL, NULL, NULL)
   IF hDC = NULL THEN EXIT FUNCTION
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   DeleteDC hDC
   DIM nPointSize AS LONG
   SELECT CASE nType
      CASE AFX_FONT_CAPTION      : nPointSize = MulDiv(ncm.lfCaptionFont.lfHeight, 72, cyPixelsPerInch)
      CASE AFX_FONT_SMALLCAPTION : nPointSize = MulDiv(ncm.lfSmCaptionFont.lfHeight, 72, cyPixelsPerInch)
      CASE AFX_FONT_MENU         : nPointSize = MulDiv(ncm.lfMenuFont.lfHeight, 72, cyPixelsPerInch)
      CASE AFX_FONT_STATUS       : nPointSize = MulDiv(ncm.lfStatusFont.lfHeight, 72, cyPixelsPerInch)
      CASE AFX_FONT_MESSAGE      : nPointSize = MulDiv(ncm.lfMessageFont.lfHeight, 72, cyPixelsPerInch)
   END SELECT
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the point size of a font given its logical height
' ========================================================================================
PRIVATE FUNCTION AfxGetFontPointSize (BYVAL nHeight AS LONG) AS LONG
   DIM hDC AS HDC = CreateDCW("DISPLAY", NULL, NULL, NULL)
   IF hDC = NULL THEN EXIT FUNCTION
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   DeleteDC HDC
   DIM nPointSize AS LONG = MulDiv(nHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the logical height of a font given its point size
' ========================================================================================
PRIVATE FUNCTION AfxGetFontHeight (BYVAL nPointSize AS LONG) AS LONG
   DIM hDC AS HDC = CreateDCW("DISPLAY", NULL, NULL, NULL)
   IF hDC = NULL THEN EXIT FUNCTION
   DIM cyPixelsPerInch AS LONG = GetDeviceCaps(hDC, LOGPIXELSY)
   DeleteDC HDC
   DIM nHeight AS LONG = -MulDiv(nPointSize, cyPixelsPerInch, 72)
   FUNCTION = nHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the face name of the font of a window or control.
' Parameters:
' - hwnd = Handle of the window or control.
' - wszNewFaceName = The new face name of the font.
' Return value: The handle of the new font on success, or NULL on failure.
' To get extended error information, call GetLastError.
' Remarks: The returned font must be destroyed with DeleteObject or the macro DeleteFont
' when no longer needed to prevent memory leaks.
' ========================================================================================
PRIVATE FUNCTION AfxModifyFontFaceName (BYVAL hWin AS HWND, BYREF wszNewFaceName AS WSTRING) AS HFONT
   DIM lfw AS LOGFONTW
   IF hWin = NULL OR VARPTR(wszNewFaceName) = NULL THEN EXIT FUNCTION
   ' // Get the handle of the font used by the window
   DIM hCurFont AS HFONT = cast(HFONT, SendMessageW(hWin, WM_GETFONT, 0, 0))
   IF hCurFont = 0 THEN EXIT FUNCTION
   ' // Get the LOGFONTW structure
   IF GetObject(hCurFont, SIZEOF(lfw), @lfw) = 0 THEN EXIT FUNCTION
   ' // Change the face name
   lfw.lfFaceName = wszNewFaceName
   ' // Create a new font
   DIM hNewFont AS HFONT = CreateFontIndirectW(@lfw)
   IF hNewFont = 0 THEN EXIT FUNCTION
   ' // Select the new font and delete the old one
   DIM hDC AS ..HDC = GetDC(hWin)
   DeleteObject(SelectObject(hDC, CAST(HGDIOBJ, hNewFont)))
   ReleaseDC(hWin, hDC)
   SendMessageW(hWin, WM_SETFONT, cast(WPARAM, hNewFont), CTRUE)
   FUNCTION = hNewFont
END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies settings of the font used by a window of control.
' Parameters:
' - hwnd = Handle of the window or control.
' - nSetting : One of the AFX_FONT_xxx constants.
' - nValue: Depends of the nSetting value
'   AFX_FONT_HEIGHT
'      The base is 100. To increase the font a 20% pass 120; to reduce it a 20% pass 80%.
'   AFX_FONT_WEIGHT
'      The weight of the font in the range 0 through 1000. For example, 400 is normal and
'      700 is bold. If this value is zero, a default weight is used.
'      The following values are defined for convenience.
'      FW_DONTCARE (0), FW_THIN (100), FW_EXTRALIGHT (200), FW_ULTRALIGHT (200), FW_LIGHT (300),
'      FW_NORMAL (400), FW_REGULAR (400), FW_MEDIUM (500), FW_SEMIBOLD (600), FW_DEMIBOLD (600),
'      FW_BOLD (700), FW_EXTRABOLD (800), FW_ULTRABOLD (800), FW_HEAVY (900), FW_BLACK (900)
'   AFX_FONT_ITALIC : TRUE or FALSE.
'   AFX_FONT_UNDERLINE : TRUE or FALSE.
'   AFX_FONT_STRIKEOUT : TRUE or FALSE.
'   AFX_FONT_CHARSET
'      The following values are predefined: ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET,
'      DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET,
'      MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET,
'      VIETNAMESE_CHARSET, JOHAB_CHARSET (Korean language edition of Windows), ARABIC_CHARSET and
'      HEBREW_CHARSET (Middle East language edition of Windows), THAI_CHARSET (Thai language
'      edition of Windows).
'      The OEM_CHARSET value specifies a character set that is operating-system dependent.
'      DEFAULT_CHARSET is set to a value based on the current system locale. For example, when
'      the system locale is English (United States), it is set as ANSI_CHARSET.
'      Fonts with other character sets may exist in the operating system. If an application uses
'      a font with an unknown character set, it should not attempt to translate or interpret
'      strings that are rendered with that font.
'      This parameter is important in the font mapping process. To ensure consistent results,
'      specify a specific character set. If you specify a typeface name in the lfFaceName member,
'      make sure that the lfCharSet value matches the character set of the typeface specified in lfFaceName.
' Return value: The handle of the new font on success, or NULL on failure.
' To get extended error information, call GetLastError.
' Remarks: The returned font must be destroyed with DeleteObject or the macro DeleteFont
' when no longer needed to prevent memory leaks.
' ========================================================================================
PRIVATE FUNCTION AfxModifyFontSettings (BYVAL hWin AS HWND, BYVAL nSetting AS LONG, BYVAL nValue AS LONG) AS HFONT
   DIM lfw AS LOGFONTW
   IF IsWindow(hWin) = 0 THEN EXIT FUNCTION
   ' // Get the handle of the font used by the window
   DIM hCurFont AS HFONT = cast(HFONT, SendMessageW(hWin, WM_GETFONT, 0, 0))
   IF hCurFont = NULL THEN EXIT FUNCTION
   ' // Get the LOGFONTW structure
   IF GetObject(hCurFont, SIZEOF(lfw), @lfw) = 0 THEN EXIT FUNCTION
   ' // Change the specified setting
   SELECT CASE nSetting
      CASE AFX_FONT_HEIGHT
         ' // Change the point size
         DIM lPointSize AS LONG = AfxGetFontPointSize(lfw.lfHeight)
         lPointSize = lPointSize * (nValue / 100)
         lfw.lfHeight = -MulDiv(lPointSize, AfxLogPixelsY, 72)
      CASE AFX_FONT_WEIGHT
         ' // Change the font weight
         lfw.lfWeight = nValue
      CASE AFX_FONT_ITALIC
         ' // Change the italic flag
         lfw.lfItalic = CUBYTE(nValue)
      CASE AFX_FONT_UNDERLINE
         ' // Change the underline flag
         lfw.lfUnderline = CUBYTE(nValue)
      CASE AFX_FONT_STRIKEOUT
         ' // Change the strikeout flag
         lfw.lfStrikeOut = CUBYTE(nValue)
      CASE AFX_FONT_CHARSET
         ' // Change the charset
         lfw.lfCharset = CUBYTE(nValue)
      CASE ELSE
         EXIT FUNCTION
   END SELECT
   ' // Create a new font
   DIM hNewFont AS HFONT = CreateFontIndirectW(@lfw)
   IF hNewFont = NULL THEN EXIT FUNCTION
   ' // Select the new font and delete the old one
   DIM hDC AS ..HDC = GetDC(hWin)
   DeleteObject(SelectObject(hDC, CAST(HGDIOBJ, hNewFont)))
   ReleaseDC(hWin, hDC)
   SendMessageW(hWin, WM_SETFONT, CAST(WPARAM, hNewFont), CTRUE)
   FUNCTION = hNewFont
END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the height of the font used by a window of control.
' Parameters:
' - hwnd = Handle of the window or control.
' - nValue: The base is 100. To increase the font a 20% pass 120; to reduce it a 20% pass 80%.
' Return value: The handle of the new font on success, or NULL on failure.
' To get extended error information, call GetLastError.
' Remarks: The returned font must be destroyed with DeleteObject or the macro DeleteFont
' when no longer needed to prevent memory leaks.
' ========================================================================================
PRIVATE FUNCTION AfxModifyFontHeight (BYVAL hWin AS HWND, BYVAL nValue AS LONG) AS HFONT
   FUNCTION = AfxModifyFontSettings(hWin, AFX_FONT_HEIGHT, nValue)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a logical font.
' Parameters:
' - wszFaceName = The typeface name.
' - lPointSize = The point size.
' - DPI = Dots per inch to calculate scaling. Default value = 96 (no scaling). If you pass -1
'   and the application is DPI aware, the DPI value used by the operating system will be used.
' - lWeight = The weight of the font in the range 0 through 1000. For example, 400 is normal
'      and 700 is bold. If this value is zero, a default weight is used.
'      The following values are defined for convenience.
'      FW_DONTCARE (0), FW_THIN (100), FW_EXTRALIGHT (200), FW_ULTRALIGHT (200), FW_LIGHT (300),
'      FW_NORMAL (400), FW_REGULAR (400), FW_MEDIUM (500), FW_SEMIBOLD (600), FW_DEMIBOLD (600),
'      FW_BOLD (700), FW_EXTRABOLD (800), FW_ULTRABOLD (800), FW_HEAVY (900), FW_BLACK (900)
' - bItalic = Italic flag. CTRUE or FALSE
' - bUnderline = Underline flag. CTRUE or FALSE
' - bStrikeOut = StrikeOut flag. CTRUE or FALSE
' - bCharset = Charset.
'      The following values are predefined: ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET,
'      DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET,
'      MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET,
'      VIETNAMESE_CHARSET, JOHAB_CHARSET (Korean language edition of Windows), ARABIC_CHARSET and
'      HEBREW_CHARSET (Middle East language edition of Windows), THAI_CHARSET (Thai language
'      edition of Windows).
'      The OEM_CHARSET value specifies a character set that is operating-system dependent.
'      DEFAULT_CHARSET is set to a value based on the current system locale. For example, when
'      the system locale is English (United States), it is set as ANSI_CHARSET.
'      Fonts with other character sets may exist in the operating system. If an application uses
'      a font with an unknown character set, it should not attempt to translate or interpret
'      strings that are rendered with that font.
'      This parameter is important in the font mapping process. To ensure consistent results,
'      specify a specific character set. If you specify a typeface name in the lfFaceName member,
'      make sure that the lfCharSet value matches the character set of the typeface specified in lfFaceName.
' Return value: The handle of the font or NULL on failure.
' Remarks: The returned font must be destroyed with DeleteObject or the macro DeleteFont
' when no longer needed to prevent memory leaks.
' Usage examples:
'   hFont = AfxCreateFont("MS Sans Serif", 8, , FW_NORMAL, , , , DEFAULT_CHARSET)
'   hFont = AfxCreateFont("Courier New", 10, -1 , FW_BOLD, , , , DEFAULT_CHARSET)
'   hFont = AfxCreateFont("Marlett", 8, -1, FW_NORMAL, , , , SYMBOL_CHARSET)
' ========================================================================================
PRIVATE FUNCTION AfxCreateFont (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, BYVAL DPI AS LONG = 96, _
   BYVAL lWeight AS LONG = 0, BYVAL bItalic AS UBYTE = FALSE, BYVAL bUnderline AS UBYTE = FALSE, _
   BYVAL bStrikeOut AS UBYTE = FALSE, BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS HFONT

   DIM tlfw AS LOGFONTW
   DIM hDC AS HDC = GetDC(HWND_DESKTOP)

   ' // Font scaling
   IF DPI = -1 THEN DPI = GetDeviceCaps(hDC, LOGPIXELSX)
   IF DPI > 0 THEN lPointSize = (lPointSize * DPI) \ GetDeviceCaps(hDC, LOGPIXELSY)

   tlfw.lfHeight         = -MulDiv(lPointSize, .GetDeviceCaps(hDC, LOGPIXELSY), 72)  ' logical font height
   tlfw.lfWidth          =  0                                                        ' average character width
   tlfw.lfEscapement     =  0                                                        ' escapement
   tlfw.lfOrientation    =  0                                                        ' orientation angles
   tlfw.lfWeight         =  lWeight                                                  ' font weight
   tlfw.lfItalic         =  bItalic                                                  ' italic(CTRUE/FALSE)
   tlfw.lfUnderline      =  bUnderline                                               ' underline(CTRUE/FALSE)
   tlfw.lfStrikeOut      =  bStrikeOut                                               ' strikeout(CTRUE/FALSE)
   tlfw.lfCharSet        =  bCharset                                                 ' character set
   tlfw.lfOutPrecision   =  OUT_TT_PRECIS                                            ' output precision
   tlfw.lfClipPrecision  =  CLIP_DEFAULT_PRECIS                                      ' clipping precision
   tlfw.lfQuality        =  DEFAULT_QUALITY                                          ' output quality
   tlfw.lfPitchAndFamily =  FF_DONTCARE                                              ' pitch and family
   tlfw.lfFaceName       =  wszFaceName                                              ' typeface name

   ReleaseDC(HWND_DESKTOP, hDC)
   FUNCTION = CreateFontIndirectW(@tlfw)

END FUNCTION
' ========================================================================================


' ########################################################################################
'                        *** DIBs (Device Independent Bitmaps) ***
' ########################################################################################

' ========================================================================================
' Creates a DIB that applications can write to directly.
' Parameters:
' - hDC     = A handle to a device context.
' - nWidth  = The width of the bitmap, in pixels.
' - nHeight = The height of the bitmap, in pixels.
' - bpp     = Bits per pixel
' - ppvBits = A pointer to a variable that receives a pointer to the location of the
'             DIB bit values. Can be NULL.
' Return value: If the function succeeds, the return value is a handle to the newly
' created DIB, and *ppvBits points to the bitmap bit values.
' If the function fails, the return value is NULL, and *ppvBits is NULL.
' The function can fail if one or more of the input parameters is invalid.
' Remarks:
'   You must delete the returned bitmap handle with DeleteObject when no longer needed to
'   avoid memory leaks.
'   You cannot paste a DIB section from one application into another application.
'   AfxCreateDIBSection does not use the BITMAPINFOHEADER parameters biXPelsPerMeter or
'   biYPelsPerMeter and will not provide resolution information in the BITMAPINFO structure.
' Usage example:
'   DIM hdcWindow AS HDC, hbmp AS HBITMAP, pvBits AS ANY PTR
'   hdcWindow = GetWindowDC(hwnd)   ' where hwnd is the handle of the wanted window or control
'   hbmp = AfxCreateDIBSection(hdcWindow, 10, 10, @pvBits)
'   ReleaseDC(hwnd, hdcWindow)
' ========================================================================================
PRIVATE FUNCTION AfxCreateDIBSection (BYVAL hDC AS HDC, BYVAL nWidth AS DWORD, BYVAL nHeight AS DWORD, BYVAL bpp AS LONG = 0, BYVAL ppvBits AS ANY PTR PTR = NULL) AS HBITMAP
   DIM bi AS BITMAPINFO
   bi.bmiHeader.biSize = SIZEOF(bi.bmiHeader)
   bi.bmiHeader.biWidth = nWidth
   bi.bmiHeader.biHeight = nHeight
   bi.bmiHeader.biPlanes = 1
   bi.bmiHeader.biBitCount = IIF(bpp <> 0, bpp, GetDeviceCaps(hDC, BITSPIXEL_))
   bi.bmiHeader.biCompression = BI_RGB
   FUNCTION = CreateDIBSection(hDC, @bi, DIB_RGB_COLORS, ppvBits, NULL, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a DIB in memory and returns a pointer to it.
' Parameter:
' - pwszFileName = Path of the bitmap file.
' Reutn Value:
'   A pointer to the bitmap file header.
'   Release it with CoTaskMemFree when no longer needed.
' ========================================================================================
PRIVATE FUNCTION AfxDibLoadImage (BYVAL pwszFileName AS WSTRING PTR) AS BITMAPFILEHEADER PTR
   DIM bSuccess AS LONG, dwFileSize AS DWORD, dwHighSize AS DWORD, dwBytesRead AS DWORD
   DIM hFile AS HANDLE, pbmfh AS BITMAPFILEHEADER PTR
   hFile = CreateFileW(pwszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, _
           OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   ' // Get the size of the file
   dwFileSize = GetFileSize(hFile, @dwHighSize)
   IF dwHighSize THEN
      CloseHandle(hFile)
      EXIT FUNCTION
   END IF
   ' // Read the contents of the file. Notice that pmfh has been cast as
   ' // BITMAPFILEHEADER PTR to be able to read the header.
   pbmfh = CoTaskMemAlloc(dwFileSize)
   bSuccess = ReadFile(hFile, pbmfh, dwFileSize, @dwBytesRead, NULL)
   ' // Check for "BM" (&H4D42, i.e. &H42 = "B", &H4D = "M", they are in reverse order)
   IF bSuccess = 0 OR dwBytesRead <> dwFileSize OR pbmfh->bfType <> &h4D42 THEN
      CoTaskMemFree(pbmfh)
      CloseHandle(hFile)
      EXIT FUNCTION
   END IF
   ' // Close the file handle and return a pointer to the data read
   CloseHandle(hFile)
   FUNCTION = pbmfh
END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves a DIB to a file.
' - pwszFileName = Path of the file.
' - pbmfh = Pointer to the bitmap file header.
' Return Value
'   TRUE if the DIB has been saved successfully; FALSE otherwise.
' ========================================================================================
PRIVATE FUNCTION AfxDibSaveImage (BYVAL pwszFileName AS WSTRING PTR, BYVAL pbmfh AS BITMAPFILEHEADER PTR) AS BOOLEAN
   DIM bSuccess AS LONG, dwBytesWritten AS DWORD, hFile  AS HANDLE
   IF pbmfh = NULL THEN EXIT FUNCTION
   hFile = CreateFileW(pwszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   bSuccess = WriteFile(hFile, pbmfh, pbmfh->bfSize, @dwBytesWritten, NULL)
   CloseHandle(hFile)
   IF bSuccess = 0 OR dwBytesWritten <> pbmfh->bfSize THEN
      DeleteFileW(pwszFileName)
      EXIT FUNCTION
   END IF
   FUNCTION = TRUE
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                   *** BITMAPS ***
' ########################################################################################

' ========================================================================================
' Retrieves the width of a bitmap
' ========================================================================================
PRIVATE FUNCTION AfxGetBitmapWidth (BYVAL hBitmap AS HBITMAP) AS LONG
   DIM bm AS BITMAP
   IF hBitmap = NULL THEN EXIT FUNCTION
   IF GetObject(hBitmap, SIZEOF(bm), @bm) THEN FUNCTION = bm.bmWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the height of a bitmap
' ========================================================================================
PRIVATE FUNCTION AfxGetBitmapHeight (BYVAL hBitmap AS HBITMAP) AS LONG
   DIM bm AS BITMAP
   IF hBitmap = NULL THEN EXIT FUNCTION
   IF GetObject(hBitmap, SIZEOF(bm), @bm) THEN FUNCTION = bm.bmHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' Captures the display and returns an handle to a bitmap.
' ========================================================================================
PRIVATE FUNCTION AfxCaptureDisplay () AS HBITMAP
   DIM hScreenDC AS HDC = CreateDCW("DISPLAY", "", "", NULL)
   IF hScreenDC = NULL THEN EXIT FUNCTION
   DIM cx AS LONG = GetDeviceCaps(hScreenDC, HORZRES)
   DIM cy AS LONG = GetDeviceCaps(hScreenDC, VERTRES)
   DIM hMemDC AS HDC = CreateCompatibleDC(hScreenDC)
   IF hMemDC = NULL THEN EXIT FUNCTION
   DIM hBmp AS HBITMAP = CreateCompatibleBitmap(hScreenDC, cx, cy)
   IF hBmp = NULL THEN EXIT FUNCTION
   DIM hBmpOld AS HBITMAP = SelectObject(hMemDC, hBmp)
   ' // Note: CAPTUREBLT flag is required to capture layered windows
   BitBlt(hMemDC, 0, 0, cx, cy, hScreenDC, 0, 0, SRCCOPY OR CAPTUREBLT)
   SelectObject(hMemDC, hBmpOld)
   DeleteDC(hMemDC)
   DeleteDC(hScreenDC)
   FUNCTION = hBmp
END FUNCTION
' ========================================================================================

' ========================================================================================
' Draws a bitmap.
' - hDC     : A handle to the destination device context.
' - xStart  : The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.
' - yStart  : The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.
' - hBitmap : Handle of the bitmap to draw.
' Return value: TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxDrawBitmap (BYVAL _hDC AS HDC, BYVAL xStart AS LONG, BYVAL yStart AS LONG, BYVAL hBitmap AS HBITMAP) AS BOOLEAN
   DIM bm AS BITMAP, hMemDC AS HDC
   IF _hDC = NULL OR hBitmap = NULL THEN EXIT FUNCTION
   hMemDC = CreateCompatibleDC(_hDC)
   IF hMemDC = NULL THEN EXIT FUNCTION
   SelectObject hMemDC, hBitmap
   IF GetObject(hBitmap, SIZEOF(BITMAP), @bm) THEN
      BitBlt _hDC, xStart, yStart, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY
      FUNCTION = TRUE
   END IF
   DeleteDC hMemDC
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                     *** FILES ***
' ########################################################################################

' ========================================================================================
' Determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive.
' - lpRootPathName : The root directory for the drive.
'   A trailing backslash is required. If this parameter is NULL, the function uses the
'   root of the current directory.
' Return value: DRIVE_UNKNOWN (0), DRIVE_NO_ROOT_DIR (1), DRIVE_REMOVABLE (2), DRIVE_FIXED(3),
'   DRIVE_REMOTE (4), DRIVE_CDROM (5), DRIVE_RAMDISK (6).
' ========================================================================================
PRIVATE FUNCTION AfxGetDriveType (BYVAL lpRootPathName AS LPCWSTR) as UINT
   RETURN GetDriveTypeW(lpRootPathName)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a directory for a file or subdirectory with a name that matches a specific name
' (or partial name if wildcards are used).
' Parameter:
' - pwszFileSpec: The directory or path, and the file name, which can include wildcard
'   characters, for example, an asterisk (*) or a question mark (?).
'   This parameter should not be NULL, an invalid string (for example, an empty string or a
'   string that is missing the terminating null character), or end in a trailing backslash (\).
'   If the string ends with a wildcard, period (.), or directory name, the user must have
'   access permissions to the root and all subdirectories on the path. To extend the limit
'   of MAX_PATH wide characters to 32,767 wide characters, prepend "\\?\" to the path.
' Return value:
'   Returns TRUE if the specified file exists or FALSE otherwise.
' Remarks:
'   Prepending the string "\\?\" does not allow access to the root directory.
'   On network shares, you can use a pwszFileSpec in the form of the following:
'   "\\server\service\*". However, you cannot use a pwszFileSpec that points to the share
'   itself; for example, "\\server\service" is not valid.
'   To examine a directory that is not a root directory, use the path to that directory,
'   without a trailing backslash. For example, an argument of "C:\Windows" returns information
'   about the directory "C:\Windows", not about a directory or file in "C:\Windows".
'   To examine the files and directories in "C:\Windows", use an pwszFileSpec of "C:\Windows\*".
'   Be aware that some other thread or process could create or delete a file with this name
'   between the time you query for the result and the time you act on the information.
'   If this is a potential concern for your application, one possible solution is to use
'   the CreateFile function with CREATE_NEW (which fails if the file exists) or OPEN_EXISTING
'   (which fails if the file does not exist).
' ========================================================================================
PRIVATE FUNCTION AfxFileExists (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
   DIM fd AS WIN32_FIND_DATAW
   IF pwszFileSpec = NULL THEN EXIT FUNCTION
   DIM hFind AS HANDLE = FindFirstFileW(pwszFileSpec, @fd)
   IF hFind = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   FindClose hFind
   ' // Make sure that it is not a directory or a temporary file
   IF (fd.dwFileAttributes AND FILE_ATTRIBUTE_DIRECTORY) <> FILE_ATTRIBUTE_DIRECTORY AND _
      (fd.dwFileAttributes AND FILE_ATTRIBUTE_TEMPORARY) <> FILE_ATTRIBUTE_TEMPORARY THEN
      FUNCTION = TRUE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes the specified file.
' Parameter:
' - pwszFileSpec: The full path and name of the file to delete.
' Return value:
'   If the function succeeds, the return value is nonzero.
'   If the function fails, the return value is zero (0). To get extended error information, call GetLastError.
' Remarks:
'   If an application attempts to delete a file that does not exist, this function fails
'   with ERROR_FILE_NOT_FOUND. If the file is a read-only file, the function fails with
'   ERROR_ACCESS_DENIED.
' ========================================================================================
PRIVATE FUNCTION AfxDeleteFile (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
   IF pwszFileSpec = NULL THEN EXIT FUNCTION
   FUNCTION = DeleteFileW(pwszFileSpec)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Replacemet for Free Basic's Kill. Returns zero (0) on success, or non-zero on error.
' ========================================================================================
PRIVATE FUNCTION AfxKill (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
   IF pwszFileSpec = NULL THEN EXIT FUNCTION
   FUNCTION = NOT DeleteFileW(pwszFileSpec)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new directory.
' - lpPathName : The path of the directory to be created.
'   To extend the limit to 32,767 wide characters, prepend "\?" to the path.
' Return value:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
'   To get extended error information, call GetLastError.
'   Possible errors include the following.
'   - ERROR_ALREADY_EXISTS
'     The specified directory already exists.
'   - ERROR_PATH_NOT_FOUND
'     One or more intermediate directories do not exist; this function will only create
'     the final directory in the path.
' ========================================================================================
PRIVATE FUNCTION AfxCreateDirectory (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
   RETURN CreateDirectoryW(lpPathName, NULL)
END FUNCTION
' ========================================================================================
PRIVATE FUNCTION AfxMakeDir (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
   RETURN CreateDirectoryW(lpPathName, NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Unicode replacement for FreeBasic MkDir.
' Returns 0 on success, or -1 on failure.
' ========================================================================================
PRIVATE FUNCTION AfxMkDir (BYVAL lpPathName AS LPCWSTR) AS LONG
   DIM res AS LONG = CreateDirectoryW(lpPathName, NULL)
   IF res = 0 THEN RETURN -1 ELSE RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an existing empty directory.
' - lpPathName : The path of the directory to be removed. This path must specify an empty
'   directory, and the calling process must have delete access to the directory.
' To extend the MAX_PATH limit to 32,767 wide characters prepend "\?" to the path.
' If the function succeeds, the return value is TRUE.
' If the function fails, the return value is FALSE.
' To get extended error information, call GetLastError.
' The AfxRemoveDirectory function marks a directory for deletion on close. Therefore, the
' directory is not removed until the last handle to the directory is closed.
' To recursively delete the files in a directory, use the SHFileOperation function.
' AfxRemoveDirectory removes a directory junction, even if the contents of the target are not
' empty; the function removes directory junctions regardless of the state of the target object.
' ========================================================================================
PRIVATE FUNCTION AfxRemoveDirectory (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
   RETURN RemoveDirectoryW(lpPathName)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxRemoveDir (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
   RETURN RemoveDirectoryW(lpPathName)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Unicode replacement for Free Basic's RmDir.
' Returns 0 on success and -1 on failure.
' ========================================================================================
PRIVATE FUNCTION AfxRmDir (BYVAL lpPathName AS LPCWSTR) AS LONG
   DIM res AS LONG = RemoveDirectoryW(lpPathName)
   IF res = 0 THEN RETURN -1 ELSE RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies an existing file to a new file.
' - lpExistingFileName : The name of an existing file.
'   To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\?" to the path.
'   If lpExistingFileName does not exist, CopyFile fails, and GetLastError returns ERROR_FILE_NOT_FOUND.
' - lpNewFileName : The name of the new file.
'   To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\?" to the path.
' - bFailIfExists
'   If this parameter is TRUE and the new file specified by lpNewFileName already exists, the
'   function fails. If this parameter is FALSE and the new file already exists, the function
'   overwrites the existing file and succeeds.
' Return value:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxCopyFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR, BYVAL bFailIfExists AS BOOLEAN = FALSE) AS BOOLEAN
   RETURN CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Unicode replacement for Free Basic's FileCopy.
' Returns 0 on success, or 1 if an error occurred.
' ========================================================================================
PRIVATE FUNCTION AfxFileCopy (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS LONG
   DIM nRet AS LONG = IIF(CopyFileW(lpExistingFileName, lpNewFileName, FALSE) = 0, 1, 0)
   RETURN nRet
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves an existing file or a directory, including its children.
' - lpExistingFileName : The name of an existing file.
'   To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\?" to the path.
'   If lpExistingFileName does not exist, AfxMoveFile fails, and GetLastError returns ERROR_FILE_NOT_FOUND.
' - lpNewFileName : The name of the new file.
'   To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\?" to the path.
' Return value:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE. To get extended error information, call GetLastError.
' ========================================================================================
PRIVATE FUNCTION AfxMoveFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS BOOLEAN
   RETURN MoveFileW(lpExistingFileName, lpNewFileName)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxRenameFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS BOOLEAN
   RETURN MoveFileW(lpExistingFileName, lpNewFileName)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Unicode replacement for Free Basic's Name function.
' Returns 0 on success, or non-zero on failure.
' ========================================================================================
PRIVATE FUNCTION AfxName (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS LONG
   DIM res AS LONG = MoveFileW(lpExistingFileName, lpNewFileName)
   IF res = 0 THEN RETURN -1 ELSE RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a directory for a file or subdirectory with a name that matches a specific name
' (or partial name if wildcards are used).
' Parameter:
' - pwszFileSpec: The directory or path, and the file name, which can include wildcard
'   characters, for example, an asterisk (*) or a question mark (?).
'   This parameter should not be NULL, an invalid string (for example, an empty string or a
'   string that is missing the terminating null character), or end in a trailing backslash (\).
'   If the string ends with a wildcard, period (.), or directory name, the user must have
'   access permissions to the root and all subdirectories on the path. To extend the limit
'   of MAX_PATH wide characters to 32,767 wide characters, prepend "\\?\" to the path.
' Return value:
'   Returns TRUE if the specified folder exists or FALSE otherwise.
' Remarks
'   Prepending the string "\\?\" does not allow access to the root directory.
'   On network shares, you can use a file spec in the form of the following: "\\server\service\*".
'   However, you cannot use a file spec that points to the share itself; for example,
'   "\\server\service" is not valid.
'   To examine a directory that is not a root directory, use the path to that directory,
'   without a trailing backslash. For example, an argument of "C:\Windows" returns information
'   about the directory "C:\Windows", not about a directory or file in "C:\Windows".
'   To examine the files and directories in "C:\Windows", use a file spec of "C:\Windows\*".
'   Be aware that some other thread or process could create or delete a file with this name
'   between the time you query for the result and the time you act on the information.
'   If this is a potential concern for your application, one possible solution is to use
'   the CreateFile function with CREATE_NEW (which fails if the file exists) or OPEN_EXISTING
'   (which fails if the file does not exist).
' ========================================================================================
PRIVATE FUNCTION AfxFolderExists (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
   DIM fd AS WIN32_FIND_DATAW
   IF pwszFileSpec = NULL THEN EXIT FUNCTION
   DIM hFind AS HANDLE = FindFirstFileW(pwszFileSpec, @fd)
   IF hFind = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   FindClose hFind
   ' // Make sure that it is a directory
   IF (fd.dwFileAttributes AND FILE_ATTRIBUTE_DIRECTORY) = FILE_ATTRIBUTE_DIRECTORY THEN FUNCTION = TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_DIRECTORY) <> FILE_ATTRIBUTE_DIRECTORY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a directory; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsFolder (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_DIRECTORY) = FILE_ATTRIBUTE_DIRECTORY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a system file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsSystemFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_SYSTEM) = FILE_ATTRIBUTE_SYSTEM)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a hidden file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsHiddenFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_HIDDEN) = FILE_ATTRIBUTE_HIDDEN)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a read only file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsReadOnlyFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_READONLY) = FILE_ATTRIBUTE_READONLY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a temporary file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsTemporaryFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_TEMPORARY) = FILE_ATTRIBUTE_TEMPORARY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a normal file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsNormalFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_NORMAL) = FILE_ATTRIBUTE_NORMAL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a compressed file or diectory; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsCompressedFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_COMPRESSED) = FILE_ATTRIBUTE_COMPRESSED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is an encrypted file or diectory; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsEncryptedFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_ENCRYPTED) = FILE_ATTRIBUTE_ENCRYPTED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified file or directory is not to be indexed by the content
' indexing service; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsNotContentIndexedFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) = FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified file is not available immediately; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsOffLineFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_OFFLINE) = FILE_ATTRIBUTE_OFFLINE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a file or directory that has an associated reparse
' point, or a file that is a symbolic link; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsReparsePointFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_REPARSE_POINT) = FILE_ATTRIBUTE_REPARSE_POINT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a sparse file; FALSE, otherwise.
' To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' ========================================================================================
PRIVATE FUNCTION AfxIsSparseFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
   DIM dwAttributes AS DWORD = GetFileAttributesW(wszFileSpec)
   IF dwAttributes = INVALID_FILE_ATTRIBUTES THEN RETURN FALSE
   RETURN ((dwAttributes AND FILE_ATTRIBUTE_SPARSE_FILE) = FILE_ATTRIBUTE_SPARSE_FILE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Unicode replacement for Free Basic's FileDateTime.
' Returns the file's last modified date and time as Date Serial.
' wszFileName : Filename to retrieve date and time for.
' Return Value : Returns a Date Serial.
' Example:
' #include "windows.bi"
' #include "vbcompat.bi"
' #include "AfxNova/AfxWin.inc"
' DIM wszFileName AS WSTRING * MAX_PATH = ExePath & "\Test.bas"
' DIM dt AS DOUBLE = AfxFileDateTime(wszFileName)
' PRINT Format(dt, "yyyy-mm-dd hh:mm AM/PM")
' ========================================================================================
PRIVATE FUNCTION AfxFileDateTime (BYREF wszFileName AS WSTRING) AS DOUBLE
   DIM fd AS WIN32_FIND_DATAW
   DIM hFind AS HANDLE = FindFirstFileW(wszFileName, @fd)
   IF hFind = INVALID_HANDLE_VALUE THEN RETURN 0
   FindClose hFind
   DIM ft AS FILETIME
   FileTimeToLocalFileTime(@fd.ftLastWriteTime, @ft)
   DIM st AS SYSTEMTIME
   FileTimeToSystemTime(@ft, @st)
   DIM dt AS DOUBLE
   SystemTimeToVariantTime @st, @dt
   RETURN dt
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unicode replacement for Free Basic's FileLen.
' Returns the size in bytes of the specified file. Don't use it with folders.
' ========================================================================================
PRIVATE FUNCTION AfxGetFileSize (BYREF wszFileSpec AS WSTRING) AS ULONGLONG
   DIM fd AS WIN32_FIND_DATAW
   DIM hFind AS HANDLE = FindFirstFileW(wszFileSpec, @fd)
   IF hFind = INVALID_HANDLE_VALUE THEN RETURN 0
   FindClose hFind
   IF (fd.dwFileAttributes AND FILE_ATTRIBUTE_DIRECTORY) <> FILE_ATTRIBUTE_DIRECTORY AND _
      (fd.dwFileAttributes AND FILE_ATTRIBUTE_TEMPORARY) <> FILE_ATTRIBUTE_TEMPORARY THEN
      DIM ullSize AS ULONGLONG = (fd.nFileSizeHigh * (&hFFFFFFFFull + 1)) + fd.nFileSizeLow
      RETURN ullSize
   END IF
END FUNCTION
' ========================================================================================
#define AfxFileLen AfxGetFileSize

' ========================================================================================
' Returns the time the file was created.
' - wszFileSpec: The directory or path, and the file name, which can include wildcard characters,
'   for example, an asterisk (*) or a question mark (?).
'   This parameter should not be NULL, an invalid string (for example, an empty string or a
'   string that is missing the terminating null character), or end in a trailing backslash (\).
'   If the string ends with a wildcard, period (.), or directory name, the user must have access
'   permissions to the root and all subdirectories on the path.
'   To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\?\" to the path.
' - bUTC: Pass FALSE if you want to get the time in local time (the NTFS file system stores time
'   values in UTC format, so they are not affected by changes in time zone or daylight saving time).
'   FileTimeToLocalFileTime uses the current settings for the time zone and daylight saving time.
'   Therefore, if it is daylight saving time, it takes daylight saving time into account, even
'   if the file time you are converting is in standard time.
' Usage: AfxFileTimeToDateStr(AfxGetFileCreationTime("C:\Tests\test.bas", FALSE), "dd/MM/yyyy")
' ========================================================================================
PRIVATE FUNCTION AfxGetFileCreationTime (BYREF wszFileSpec AS WSTRING, BYVAL bUTC AS BOOLEAN = TRUE) AS FILETIME
   DIM fd AS WIN32_FIND_DATAW
   DIM hFind AS HANDLE = FindFirstFileW(wszFileSpec, @fd)
   IF hFind <> INVALID_HANDLE_VALUE THEN
      FindClose hFind
      IF bUTC = TRUE THEN
         RETURN fd.ftCreationTime
      ELSE
         DIM FT AS FILETIME
         FileTimeToLocalFileTime(@fd.ftCreationTime, @FT)
         RETURN FT
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed. The NTFS file system delays updates to the
' last access time for a file by up to 1 hour after the last access.
' ========================================================================================
PRIVATE FUNCTION AfxGetFileLastAccessTime (BYREF wszFileSpec AS WSTRING, BYVAL bUTC AS BOOLEAN = TRUE) AS FILETIME
   DIM fd AS WIN32_FIND_DATAW
   DIM hFind AS HANDLE = FindFirstFileW(wszFileSpec, @fd)
   IF hFind <> INVALID_HANDLE_VALUE THEN
      FindClose hFind
      IF bUTC = TRUE THEN
         RETURN fd.ftLastAccessTime
      ELSE
         DIM FT AS FILETIME
         FileTimeToLocalFileTime(@fd.ftLastAccessTime, @FT)
         RETURN FT
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last written to, truncated, or overwritten.
' When writing to a file, the last write time is not fully updated until all handles that
' are used for writing are closed.
' ========================================================================================
PRIVATE FUNCTION AfxGetFileLastWriteTime (BYREF wszFileSpec AS WSTRING, BYVAL bUTC AS BOOLEAN = TRUE) AS FILETIME
   DIM fd AS WIN32_FIND_DATAW
   DIM hFind AS HANDLE = FindFirstFileW(wszFileSpec, @fd)
   IF hFind <> INVALID_HANDLE_VALUE THEN
      FindClose hFind
      IF bUTC = TRUE THEN
         RETURN fd.ftLastWriteTime
      ELSE
         DIM FT AS FILETIME
         FileTimeToLocalFileTime(@fd.ftLastWriteTime, @FT)
         RETURN FT
      END IF
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a file is likely to contain a form of unicode text.
' ========================================================================================
PRIVATE FUNCTION AfxIsFileUnicode (BYREF wszFileName AS WSTRING) AS BOOLEAN
   DIM hFile AS HANDLE = CreateFileW(@wszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, _
                         OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN RETURN FALSE
   DIM dwFileSize AS DWORD, dwHighSize AS DWORD
   dwFileSize = GetFileSize(hFile, @dwHighSize)
   DIM dwBytesToRead AS DWORD = 1024
   IF dwFileSize < dwBytesToRead THEN dwBytesToRead = dwFileSize
   DIM pBuffer AS UBYTE PTR = CAllocate(1, dwBytesToRead)
   DIM bRes AS BOOLEAN, dwBytesRead AS DWORD
   bRes = ReadFile(hFile, pBuffer, dwBytesToRead, @dwBytesRead, NULL)
   IF bRes THEN bRes = IsTextUnicode(pBuffer, dwBytesRead, NULL)
   IF pBuffer THEN DeAllocate(pBuffer)
   IF hFile THEN CloseHandle(hFile)
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scans a text file ans returns the number of occurrences of the specified delimiter.
' Default value is CHR(13, 10), which returns the number of lines.
' ========================================================================================
PRIVATE FUNCTION AfxFileScanA (BYREF wszFileName AS WSTRING, BYREF szDelimiter AS ZSTRING = CHR(13, 10)) AS DWORD
   DIM dwCount AS DWORD, dwFileSize AS DWORD, dwHighSize AS DWORD, dwBytesRead AS DWORD
   IF LEN(szDelimiter) = 0 THEN EXIT FUNCTION
   ' // Open the file
   DIM hFile AS HANDLE = CreateFileW(@wszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, _
                         OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   ' // Get the size of the file
   dwFileSize = GetFileSize(hFile, @dwHighSize)
   DIM pBuffer AS UBYTE PTR
   pBuffer = CAllocate(1, dwFileSize)
   IF pBuffer = NULL THEN EXIT FUNCTION
   DIM bSuccess AS LONG = ReadFile(hFile, pBuffer, dwFileSize, @dwBytesRead, NULL)
   CloseHandle(hFile)
   IF bSuccess = FALSE THEN EXIT FUNCTION
   DIM nLen AS LONG = LEN(szDelimiter)
   DIM pstr AS ANY PTR = pBuffer
   DO
      pstr = strstr(pstr, szDelimiter)
      IF pstr = NULL THEN EXIT DO
      pstr += nLen
      dwCount += 1
   LOOP
   DeAllocate(pBuffer)
   FUNCTION = dwCount
END FUNCTION
' ========================================================================================
' ========================================================================================
' Version for unicode text files.
' ========================================================================================
PRIVATE FUNCTION AfxFileScanW (BYREF wszFileName AS WSTRING, BYREF wszDelimiter AS WSTRING = CHR(13, 10)) AS DWORD
   DIM dwCount AS DWORD, dwFileSize AS DWORD, dwHighSize AS DWORD, dwBytesRead AS DWORD
   IF LEN(wszDelimiter) = 0 THEN EXIT FUNCTION
   ' // Open the file
   DIM hFile AS HANDLE = CreateFileW(@wszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, _
                         OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   ' // Get the size of the file
   dwFileSize = GetFileSize(hFile, @dwHighSize)
   DIM pBuffer AS UBYTE PTR
   pBuffer = CAllocate(1, dwFileSize)
   IF pBuffer = NULL THEN EXIT FUNCTION
   DIM bSuccess AS LONG = ReadFile(hFile, pBuffer, dwFileSize, @dwBytesRead, NULL)
   CloseHandle(hFile)
   IF bSuccess = FALSE THEN EXIT FUNCTION
   DIM nLen AS LONG = LEN(wszDelimiter) * 2
   DIM pstr AS ANY PTR = pBuffer
   DO
      pstr = wcsstr(pstr, @wszDelimiter)
      IF pstr = NULL THEN EXIT DO
      pstr += nLen
      dwCount += 1
   LOOP
   DeAllocate(pBuffer)
   FUNCTION = dwCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves the contents of a string buffer in a temporary file and returns the name of the file.
' ========================================================================================
PRIVATE FUNCTION AfxSaveTempFile (BYVAL pwszBuffer AS WSTRING PTR, BYREF wszExtension AS WSTRING = "") AS DWSTRING
   DIM wszTmpFileName AS WSTRING * MAX_PATH
   DIM wszTmpPath AS WSTRING * MAX_PATH - 14
   DIM dwRes AS DWORD, fn AS LONG
   dwRes = GetTempPathW(MAX_PATH - 14, @wszTmpPath)
   IF dwRes > 0 AND dwRes <= MAX_PATH - 14 THEN
      dwRes = GetTempFileNameW(@wszTmpPath, "TMP", 0, @wszTmpFileName)
      IF dwRes THEN
         fn = FREEFILE
         OPEN wszTmpFileName FOR OUTPUT AS #fn
         IF ERR = 0 THEN
            PRINT #fn, *pwszBuffer
            CLOSE #fn
            DIM newTmpFileName AS WSTRING * MAX_PATH = wszTmpFileName
            IF LEN(wszExtension) THEN newTmpFileName = LEFT(newTmpFileName, LEN(newTmpFileName) -  3) & wszExtension
            IF AfxRenameFile(wszTmpFileName, newTmpFileName) THEN
               RETURN newTmpFileName
            ELSE
               RETURN wszTmpFileName
            END IF
         END IF
      END IF
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves an icon to a file.
' Usage examples:
' DIM hIcon as HICON = LoadIcon(NULL, IDI_INFORMATION)
' DIM hr AS HRESULT = AfxSaveIconToFile(hIcon, "test.ico")
' DIM hIcon AS HICON = cast(HICON, LoadImage(NULL, ExePath & "\" & "MyIco.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE))
' DIM hr AS HRESULT = AfxSaveIconToFile(hIcon, "test2.ico")
' ========================================================================================

TYPE ICONDIR field = 1
   idReserved AS USHORT
   idType     AS USHORT
   idCount    AS USHORT
END TYPE

TYPE ICONDIRENTRY field = 1
   bWidth        AS UBYTE
   bHeight       AS UBYTE
   bColorCount   AS UBYTE
   bReserved     AS UBYTE
   wPlanes       AS USHORT
   wBitCount     AS USHORT
   dwBytesInRes  AS ULONG
   dwImageOffset AS ULONG
END TYPE

FUNCTION AfxSaveIconToFile (BYVAL hIcon AS HICON, BYREF fileName AS WSTRING) AS HRESULT

   IF hIcon = 0 THEN RETURN E_POINTER

   DIM ii AS ICONINFO
   IF GetIconInfo(hIcon, @ii) = 0 THEN RETURN HRESULT_FROM_WIN32(GetLastError())

   ' // Get sizes of color/mask bitmaps
   DIM bmColor AS BITMAP
   DIM bmMask  AS BITMAP
   GetObject(ii.hbmColor, SIZEOF(BITMAP), @bmColor)
   GetObject(ii.hbmMask,  SIZEOF(BITMAP), @bmMask)

   DIM w AS LONG = bmColor.bmWidth
   DIM h AS LONG = bmColor.bmHeight

   ' // Prepare BITMAPINFOHEADER for extracting color pixels (actual height)
   dim biColor AS BITMAPINFOHEADER
   biColor.biSize        = SIZEOF(BITMAPINFOHEADER)
   biColor.biWidth       = w
   biColor.biHeight      = h              ' actual color height for GetDIBits
   biColor.biPlanes      = 1
   biColor.biBitCount    = 32
   biColor.biCompression = BI_RGB
   biColor.biSizeImage   = w * h * 4

   ' // Extract color pixels (XOR)
   REDIM AS UBYTE colorPixels(biColor.biSizeImage - 1)
   DIM hdc AS HDC = GetDC(NULL)
   IF GetDIBits(hdc, ii.hbmColor, 0, h, @colorPixels(0), cast(BITMAPINFO ptr, @biColor), DIB_RGB_COLORS) = 0 THEN
      ReleaseDC(NULL, hdc)
      DeleteObject(ii.hbmColor)
      DeleteObject(ii.hbmMask)
      RETURN HRESULT_FROM_WIN32(GetLastError())
   END IF

   ' // Prepare AND mask (1bpp, bottom-up). Zero mask is acceptable for ARGB icons.
   DIM maskStrideBytes AS LONG = ((w + 31) \ 32) * 4
   DIM maskSize AS LONG = maskStrideBytes * h
   REDIM AS UBYTE maskPixels(maskSize - 1)
   ' Option 1: All zeros (fully opaque). If you prefer true mask, use GetDIBits on ii.hbmMask.

   ' // ICO header for writing (height doubled: XOR + AND)
   dim biWrite AS BITMAPINFOHEADER
   biWrite.biSize        = SIZEOF(BITMAPINFOHEADER)
   biWrite.biWidth       = w
   biWrite.biHeight      = h * 2          ' XOR + AND
   biWrite.biPlanes      = 1
   biWrite.biBitCount    = 32
   biWrite.biCompression = BI_RGB
   biWrite.biSizeImage   = biColor.biSizeImage ' only XOR counted here; mask size appended separately

   ' Build ICONDIR + ICONDIRENTRY
   DIM id AS ICONDIR
   id.idReserved = 0
   id.idType     = 1
   id.idCount    = 1

   DIM entry AS ICONDIRENTRY
   entry.bWidth       = IIF(w >= 256, 0, CINT(w))     ' 0 means 256 in ICO spec
   entry.bHeight      = IIF(h >= 256, 0, CINT(h))
   entry.bColorCount  = 0
   entry.bReserved    = 0
   entry.wPlanes      = 1
   entry.wBitCount    = 32
   entry.dwBytesInRes = SIZEOF(BITMAPINFOHEADER) + biColor.biSizeImage + maskSize
   entry.dwImageOffset = SIZEOF(ICONDIR) + SIZEOF(ICONDIRENTRY)

   ' // Write to file
   DIM hFile AS HANDLE = CreateFileW(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
   IF hFile = INVALID_HANDLE_VALUE THEN
      ReleaseDC(NULL, hdc)
      DeleteObject(ii.hbmColor)
      DeleteObject(ii.hbmMask)
      return HRESULT_FROM_WIN32(GetLastError())
   END IF

   DIM written AS DWORD
   ' 1) ICONDIR
   WriteFile(hFile, @id, SIZEOF(ICONDIR), @written, NULL)
   ' 2) ICONDIRENTRY
   WriteFile(hFile, @entry, SIZEOF(ICONDIRENTRY), @written, NULL)
   ' 3) BITMAPINFOHEADER (with doubled height)
   WriteFile(hFile, @biWrite, SIZEOF(BITMAPINFOHEADER), @written, NULL)
   ' 4) XOR color pixels
   WriteFile(hFile, @colorPixels(0), biColor.biSizeImage, @written, NULL)
   ' 5) AND mask pixels (1bpp, zeroed)
   WriteFile(hFile, @maskPixels(0), maskSize, @written, NULL)

   CloseHandle(hFile)

   ' // Cleanup
   ReleaseDC(NULL, hdc)
   DeleteObject(ii.hbmColor)
   DeleteObject(ii.hbmMask)

   RETURN S_OK

END FUNCTION
' ========================================================================================


' ########################################################################################
'                              *** SYSTEM INFORMATION ***
' ########################################################################################

' ========================================================================================
' * Retrieves the name of the user associated with the current thread.
' ========================================================================================
PRIVATE FUNCTION AfxGetUserName () AS DWSTRING
   DIM buffer AS WSTRING * 260
   DIM dwBufLen AS DWORD = SIZEOF(buffer)\2
   GetUserNameW(buffer, @dwBufLen)
   RETURN buffer
END FUNCTION
' ========================================================================================
#define AfxUserName AfxGetUserName
' ========================================================================================

' ========================================================================================
' * Retrieves the computer name of the current system.
' ========================================================================================
PRIVATE FUNCTION AfxGetComputerName () AS DWSTRING
   DIM buffer AS WSTRING * MAX_COMPUTERNAME_LENGTH + 1
   DIM dwBufLen AS DWORD = SIZEOF(buffer)\2
   GetComputerNameW(buffer, @dwBufLen)
   RETURN buffer
END FUNCTION
' ========================================================================================
#define AfxComputerName AfxGetComputerName
' ========================================================================================

' ========================================================================================
' The DNS host name of the local computer. If the local computer is a node in a cluster,
' dwsBuffer receives the DNS host name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION AfxGetComputerNameDnsHostname () AS DWSTRING
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
#define AfxComputerNameDnsHostname AfxGetComputerNameDnsHostname
' ========================================================================================

' ========================================================================================
' The NetBIOS name of the local computer. If the local computer is a node in a cluster,
' dwsBuffer receives the NetBIOS name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION AfxGetComputerNameNetBIOS () AS DWSTRING
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
#define AfxtComputerNameNetBIOS AfxGetComputerNameNetBIOS
' ========================================================================================

' ========================================================================================
' The fully qualified DNS name that uniquely identifies the local computer. This name is a
' combination of the DNS host name and the DNS domain name, using the form HostName.DomainName.
' If the local computer is a node in a cluster, dwsBuffer receives the fully qualified DNS
' name of the cluster virtual server.
' ========================================================================================
PRIVATE FUNCTION AfxGetComputerNameDnsFullyQualified () AS DWSTRING
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
#define AfxComputerNameDnsFullyQualified AfxGetComputerNameDnsFullyQualified
' ========================================================================================

' ========================================================================================
' Retrieves the name of the user associated with the current thread.
' ========================================================================================
' EXTENDED_NAME_FORMAT is an enumeration
PRIVATE FUNCTION AfxGetUserDomain () AS DWSTRING
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
#define AfxUserDomain AfxGetUserDomain
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
PRIVATE FUNCTION AfxIsUserAnAdmin () AS BOOLEAN
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
' * Returns the bitness of the operating system.
' On a 32-bit operating system, the value is 32 and on a 64-bit operating system it is 64.
' ========================================================================================
PRIVATE FUNCTION AfxWindowsBitness () AS LONG
   DIM SysInfo AS SYSTEM_INFO
   GetNativeSystemInfo(@SysInfo)
   ' PROCESSOR_ARCHITECTURE_ARM64 = 12
   RETURN IIF(SysInfo.wProcessorArchitecture = PROCESSOR_ARCHITECTURE_AMD64 _
      OR SysInfo.wProcessorArchitecture = 12, 64, 32)
END FUNCTION
' ========================================================================================
#define AfxGetProcessorAddressWidth AfxWindowsBitness
' ========================================================================================

' ========================================================================================
' * Retrieves information about the current system.
' ========================================================================================
PRIVATE FUNCTION AfxGetSystemInfo (BYREF metricName AS STRING) AS LONG_PTR
   DIM sysInfo AS SYSTEM_INFO
   GetSystemInfo(@sysInfo)
   SELECT CASE LCASE(metricName)
      CASE "cpucount"
         RETURN sysInfo.dwNumberOfProcessors
      CASE "cpumask"
         RETURN sysInfo.dwActiveProcessorMask
      CASE "granularity"
         RETURN sysInfo.dwAllocationGranularity
      CASE "maxappaddr"
         RETURN CAST(LONG_PTR, sysInfo.lpMaximumApplicationAddress)
      CASE "minappaddr"
         RETURN CAST(LONG_PTR, sysInfo.lpMinimumApplicationAddress)
      CASE "pagesize"
         RETURN sysInfo.dwPageSize
      CASE ELSE
         RETURN -1 ' Invalid metric name
   END SELECT
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the Windows feature update versión, e.g. 22H2.
' ========================================================================================
PRIVATE FUNCTION AfxWindowsFeatureUpdate () AS DWSTRING
   DIM key AS HKEY = HKEY_LOCAL_MACHINE
   DIM subKey AS WSTRING * 260 = "SOFTWARE\Microsoft\Windows NT\CurrentVersion"
   DIM valueName AS WSTRING * 260 = "DisplayVersion"
   DIM buffer AS WSTRING * 256
   DIM bufferSize AS DWORD = SIZEOF(buffer)
   DIM result AS LONG = RegGetValueW(key, @subkey, @valueName, RRF_RT_REG_SZ, NULL, @buffer, @bufferSize)
   IF result = ERROR_SUCCESS THEN RETURN buffer
   RETURN ""
END FUNCTION
' ========================================================================================
#define AfxGetWindowsFeatureUpdate AfxWindowsFeatureUpdate
' ========================================================================================

' ========================================================================================
' * Returns the processor architecture of the operating system.
' ========================================================================================
PRIVATE FUNCTION AfxProcessorArchitecture () AS DWSTRING
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
#define AfxGetProcessorArchitecture AfxProcessorArchitecture
' ========================================================================================

' ========================================================================================
' * Returns the number of processors.
' ========================================================================================
PRIVATE FUNCTION AfxProcessorsCount () AS LONG
   DIM SysInfo AS SYSTEM_INFO
   GetSystemInfo (@SysInfo)
   RETURN SysInfo.dwNumberOfProcessors
END FUNCTION
' ========================================================================================
#define AfxGetProcessorsCount AfxProcessorsCount
' ========================================================================================

' ========================================================================================
' Checks if the process is running with real administrative privileges.
' ========================================================================================
PRIVATE FUNCTION AfxIsProcessElevated () AS BOOLEAN
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
PRIVATE FUNCTION AfxMemoryLoad () AS DWORD
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.dwMemoryLoad
END FUNCTION
' ========================================================================================
#define AfxGetMemoryLoad AfxMemoryLoad
' ========================================================================================

' ========================================================================================
' Returns the amount of actual physical memory, in bytes.
' ========================================================================================
PRIVATE FUNCTION AfxTotalPhysicalMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullTotalPhys
END FUNCTION
' ========================================================================================
#define AfxGetTotalPhysicalMemory AfxTotalPhysicalMemory
' ========================================================================================

' ========================================================================================
' Returns the amount of physical memory currently available, in bytes. This is the amount
' of physical memory that can be immediately reused without having to write its contents
' to disk first. It is the sum of the size of the standby, free, and zero lists.
' ========================================================================================
PRIVATE FUNCTION AfxAvailablePhysicalMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullAvailPhys
END FUNCTION
' ========================================================================================
#define AfxGetAvailablePhysicalMemory AfxAvailablePhysicalMemory
' ========================================================================================

' ========================================================================================
' Returns the current committed memory limit for the system or the current process, whichever
' is smaller, in bytes.
' ========================================================================================
PRIVATE FUNCTION AfxTotalPageFile () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullTotalPageFile
END FUNCTION
' ========================================================================================
#define AfxGetTotalPageFile AfxTotalPageFile
' ========================================================================================

' ========================================================================================
' Returns maximum amount of memory the current process can commit, in bytes. This value is
' equal to or smaller than the system-wide available commit value.
' ========================================================================================
PRIVATE FUNCTION AfxAvailablePageFile () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullAvailPageFile
END FUNCTION
' ========================================================================================
#define AfxGetAvailablePageFile AfxAvailablePageFile
' ========================================================================================

' ========================================================================================
' Returns size of the user-mode portion of the virtual address space of the calling process,
' in bytes. This value depends on the type of process, the type of processor, and the
' configuration of the operating system. For example, this value is approximately 2 GB for
' most 32-bit processes on an x86 processor and approximately 3 GB for 32-bit processes
' that are large address aware running on a system with 4-gigabyte tuning enabled.
' ========================================================================================
PRIVATE FUNCTION AfxTotalVirtualMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullTotalVirtual
END FUNCTION
' ========================================================================================
#define AfxGetTotalVirtualMemory AfxTotalVirtualMemory
' ========================================================================================

' ========================================================================================
' Returns amount of unreserved and uncommitted memory currently in the user-mode portion
' of the virtual address space of the calling process, in bytes.
' ========================================================================================
PRIVATE FUNCTION AfxAvailableVirtualMemory () AS DWORDLONG
   DIM mem AS MEMORYSTATUSEX
   mem.dwLength = SIZEOF(MEMORYSTATUSEX)
   SetLastError(GlobalMemoryStatusEx(@mem))
   RETURN mem.ullAvailVirtual
END FUNCTION
' ========================================================================================
#define AfxGetAvailableVirtualMemory AfxAvailableVirtualMemory
' ========================================================================================

#if _WIN32_WINNT >= &h0600
' ========================================================================================
' Retrieves the amount of RAM that is physically installed on the computer, in kilobytes.
' ========================================================================================
PRIVATE FUNCTION AfxGetPhysicallyInstalledSystemMemory () AS ULONGLONG
   DIM mem AS ULONGLONG
   GetPhysicallyInstalledSystemMemory(@mem)
   RETURN mem
END FUNCTION
' ========================================================================================
#define AfxPhysicallyInstalledSystemMemory AfxGetPhysicallyInstalledSystemMemory
' ========================================================================================

' ========================================================================================
' Retrieves the product type for the operating system on the local computer, and maps the
' type to the product types supported by the specified operating system.
' ========================================================================================
PRIVATE FUNCTION AfxGetProductInfo () AS DWORD
   DIM dwReturnedProductType AS DWORD
   DIM hLib AS HMODULE = LoadLibraryW("NtDll.dll")
   IF hLib = NULL THEN EXIT FUNCTION
   DIM pfnRtlGetVersion AS FUNCTION (BYVAL lpVersionInformation AS OSVERSIONINFOEXW PTR) AS LONG
   pfnRtlGetVersion = CAST(ANY PTR, GetProcAddress(hLib, "RtlGetVersion"))
   DIM osverinfo AS OSVERSIONINFOEXW
   osverinfo.dwOSVersionInfoSize = SIZEOF(osverinfo)
   IF pfnRtlGetVersion THEN pfnRtlGetVersion(@osverinfo)
   FreeLibrary hLib
   GetProductInfo(osverinfo.dwMajorVersion, osverinfo.dwMinorVersion, 0, 0, @dwReturnedProductType)
   RETURN dwReturnedProductType
END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' * Returns TRUE if Windows applications are using dark mode, or FALSE otherwise.
' It affects Win32/UWP applications.
' ========================================================================================
PRIVATE FUNCTION AfxAppsUseDarkMode () AS BOOLEAN
   DIM key AS HKEY = HKEY_CURRENT_USER
   DIM subKey AS WSTRING * 260 = "SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize"
   DIM valueName AS WSTRING * 260 = "AppsUseLightTheme"
   DIM dwValue AS DWORD
   DIM dwSize AS DWORD = SIZEOF(dwValue)
   DIM result AS LONG = RegGetValueW(key, @subkey, @valueName, RRF_RT_REG_DWORD, NULL, @dwValue, @dwSize)
   IF result = ERROR_SUCCESS THEN RETURN (dwValue = 0)   ' // (0 = dark, 1 = light)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns TRUE if Windows is using dark mode, or FALSE otherwise.
' It affects the shell (taskbar, start menu, etc.).
' ========================================================================================
PRIVATE FUNCTION AfxSystemUsesDarkMode () AS BOOLEAN
   DIM key AS HKEY = HKEY_CURRENT_USER
   DIM subKey AS WSTRING * 260 = "SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize"
   DIM valueName AS WSTRING * 260 = "SystemUsesLightTheme"
   DIM dwValue AS DWORD
   DIM dwSize AS DWORD = SIZEOF(dwValue)
   DIM result AS LONG = RegGetValueW(key, @subkey, @valueName, RRF_RT_REG_DWORD, NULL, @dwValue, @dwSize)
   IF result = ERROR_SUCCESS THEN RETURN (dwValue = 0)
 END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the date in which Windows was installed, in Unix time.
' Usage examples:
' PRINT AfxUnixDateStr(AfxWindowsInstallDate, "dd-MM-yyyy")
' PRINT AfxUnixTimeStr(AfxWindowsInstallDate, "hh':'mm':'ss")
' ========================================================================================
PRIVATE FUNCTION AfxWindowsInstallDate () AS DWORD
   DIM key AS HKEY = HKEY_LOCAL_MACHINE
   DIM subKey AS WSTRING * 260 = "SOFTWARE\Microsoft\Windows NT\CurrentVersion"
   DIM valueName AS WSTRING * 260 = "InstallDate"
   DIM dwValue AS DWORD
   DIM dwSize AS DWORD = SIZEOF(dwValue)
   DIM result AS LONG = RegGetValueW(key, @subkey, @valueName, RRF_RT_REG_DWORD, NULL, @dwValue, @dwSize)
   IF result = ERROR_SUCCESS THEN RETURN dwValue
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                   *** POWER STATUS ***
' ########################################################################################

' ========================================================================================
' Retrieves the AC power status. This member can be one of the following values:
' Offline (0), Online(1), Unknown status (255)
' ========================================================================================
PRIVATE FUNCTION AfxACLineStatus () AS UBYTE
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.ACLineStatus
END FUNCTION
' ========================================================================================


' ========================================================================================
' Retrieves the battery charge status. This member can be one of the following values:
' 1 = High—the battery capacity is at more than 66 percent
' 2 = Low—the battery capacity is at less than 33 percent
' 4 = Critical—the battery capacity is at less than five percent
' 8 = Charging
' 128 = No system battery
' 255 = Unknown status—unable to read the battery flag information
' The value is zero if the battery is not being charged and the battery capacity is
' between low and high.
' ========================================================================================
PRIVATE FUNCTION AfxBatteryChargeStatus () AS UBYTE
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.BatteryFlag
END FUNCTION
' ========================================================================================

' ========================================================================================
' The percentage of full battery charge remaining. This member can be a value in the range
' 0 to 100, or 255 if status is unknown.
' ========================================================================================
PRIVATE FUNCTION AfxBatteryLifePercent () AS UBYTE
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
'PRIVATE FUNCTION AfxBatterySaverStatus () AS UBYTE
'   DIM sps AS SYSTEM_POWER_STATUS
'   GetSystemPowerStatus(@sps)
'   RETURN sps.Reserved1   ' SystemStatusFlag
'END FUNCTION
' ========================================================================================

' ========================================================================================
' The number of seconds of battery life remaining, or –1 if remaining seconds are unknown
' or if the device is connected to AC power.
' ========================================================================================
PRIVATE FUNCTION AfxBatteryLifeTime () AS LONG
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
PRIVATE FUNCTION AfxBatteryFullLifeTime () AS LONG
   DIM sps AS SYSTEM_POWER_STATUS
   GetSystemPowerStatus(@sps)
   RETURN sps.BatteryFullLifeTime
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                     *** INTERNET ***
' ########################################################################################

' ========================================================================================
' * Attempts to make a connection to the Internet.
' IF AfxInternetAttemptConnect = ERROR_SUCCESS THEN ? "You can connect to the Internet"
' ========================================================================================
PRIVATE FUNCTION AfxInternetAttemptConnect () AS DWORD
   RETURN InternetAttemptConnect(0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Checks if a connection to the Internet can be established.
' Usage example:
' IF AfxInternetCheckConnection("https://www.freebasic.net/forum/viewforum.php?f=1") THEN ? "Connection succeeded!"
' ========================================================================================
PRIVATE FUNCTION AfxInternetCheckConnection (BYVAL pwszUrl AS WSTRING PTR) AS BOOLEAN
   RETURN InternetCheckConnectionW(pwszUrl, FLAG_ICC_FORCE_CONNECTION, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences.
' Usage example: PRINT AfxInternetCanonicalizeUrl("http://msdn2.microsoft.com/en-us/ library/")
' ========================================================================================
PRIVATE FUNCTION AfxInternetCanonicalizeUrl (BYVAL pwszUrl AS WSTRING PTR, BYVAL dwFlags AS DWORD = 0) AS DWSTRING
   DIM wszUrl AS WSTRING * INTERNET_MAX_PATH_LENGTH
   DIM dwUrlSize AS DWORD = SIZEOF(wszUrl)
   IF InternetCanonicalizeUrlW(pwszUrl, @wszUrl, @dwUrlSize, dwFlags) = FALSE THEN RETURN ""
   RETURN wszUrl
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Combines a base and relative URL into a single URL. The resultant URL is canonicalized.
' Usage example: PRINT AfxInternetCombineUrl("https://www.planetsquires", "/protect/forum/index.php?board=1.0")
' ========================================================================================
PRIVATE FUNCTION AfxInternetCombineUrl (BYVAL pwszBaseUrl AS WSTRING PTR, BYVAL pwszRelativeUrl AS WSTRING PTR, BYVAL dwFlags AS DWORD = 0) AS DWSTRING
   DIM wszUrl AS WSTRING * INTERNET_MAX_PATH_LENGTH
   DIM dwUrlSize AS DWORD = SIZEOF(wszUrl)
   IF InternetCombineUrlW(pwszBaseUrl, pwszRelativeUrl, @wszUrl, @dwUrlSize, dwFlags) = FALSE THEN RETURN ""
   RETURN wszUrl
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the connected state of the local system.
' Returns TRUE or FALSE.
' ========================================================================================
PRIVATE FUNCTION AfxInternetGetConnectedState () AS BOOLEAN
   DIM dwFlags AS DWORD
   RETURN InternetGetConnectedState(@dwFlags, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the connection description
' ========================================================================================
PRIVATE FUNCTION AfxInternetGetConnectionDescription () AS DWORD
   DIM dwFlags AS DWORD
   DIM wszConnectionName AS WSTRING * 260
   InternetGetConnectedStateExW(@dwFlags, @wszConnectionName, SIZEOF(wszConnectionName), 0)
   RETURN dwFlags
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the connection name
' ========================================================================================
PRIVATE FUNCTION AfxInternetGetConnectionName () AS DWSTRING
   DIM dwFlags AS DWORD
   DIM wszConnectionName AS WSTRING * 260
   IF InternetGetConnectedStateExW(@dwFlags, @wszConnectionName, SIZEOF(wszConnectionName), 0) = FALSE THEN RETURN ""
   RETURN wszConnectionName
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the Internet Explorer version (major.minor).
' ========================================================================================
PRIVATE FUNCTION AfxGetInternetExplorerVersion () AS SINGLE
   DIM hk AS HKEY, wszData AS WSTRING * 1024, cbData AS DWORD = SIZEOF(wszData)
   IF RegOpenKeyExW(HKEY_LOCAL_MACHINE, "SOFTWARE\Microsoft\Internet Explorer", 0, _
                    KEY_QUERY_VALUE, @hk) <> ERROR_SUCCESS THEN EXIT FUNCTION
   IF RegQueryValueExW(hk, "Version", NULL, NULL, cast(BYTE PTR, @wszData), @cbData) <> ERROR_SUCCESS THEN
      IF RegQueryValueExW(hk, "svcVersion", NULL, NULL, cast(BYTE PTR, @wszData), @cbData) <> ERROR_SUCCESS THEN wszData = ""
   END IF
   RegCloseKey hk
   FUNCTION = VAL(wszData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the path of the default browser.
' ========================================================================================
PRIVATE FUNCTION AfxGetDefaultBrowserPath () AS DWSTRING
   DIM wszPath AS WSTRING * MAX_PATH, cchOut AS DWORD = SIZEOF(wszPath)\2
   IF SUCCEEDED(AssocQueryStringW(0, ASSOCSTR_EXECUTABLE, "http", "open", wszPath, @cchOut)) THEN RETURN wszPath
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the name of the default browser.
' ========================================================================================
PRIVATE FUNCTION AfxGetDefaultBrowserName () AS DWSTRING
   DIM wszPath AS WSTRING * MAX_PATH, cchOut AS DWORD = SIZEOF(wszPath)\2
   IF SUCCEEDED(AssocQueryStringW(0, ASSOCSTR_EXECUTABLE, "http", "open", wszPath, @cchOut)) THEN
      RETURN AfxGetFileName(wszPath)
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Obsolete.
' Retrieves the handle of the top level window of the web browser.
' Parameter:
'    pwszClassName: The browser class name.
' Return value:
'    The handle of the top level window of the browser.
' Examples:
' DIM hwndBrowser AS HWND = AfxGetBrowserHandle("IEFrame")              ' // Internet Explorer
' DIM hwndBrowser AS HWND = AfxGetBrowserHandle("MozillaWindowClass")   ' // Firefox
' DIM hwndBrowser AS HWND = AfxGetBrowserHandle("Chrome_WidgetWin_1")   ' // Chrome
' ========================================================================================
'PRIVATE FUNCTION AfxEnumThreadWndProc (BYVAL hWin AS HWND, BYVAL lPrm AS LPARAM) AS WINBOOL
'   DIM dwStyle AS DWORD = GetWindowLongPtr(hWin, GWL_STYLE)
'   IF ((dwStyle AND (WS_POPUP OR WS_CHILD)) = 0) AND ((dwStyle AND WS_VISIBLE) <> 0) THEN
'      DIM phwndTop AS HWND PTR
'      CAST(LPARAM, phwndTop) = lPrm
'      *phwndTop = hWin
'      RETURN FALSE
'   END IF
'   RETURN CTRUE
'END FUNCTION
'' ========================================================================================
'' ========================================================================================
'PRIVATE FUNCTION AfxGetBrowserHandle (BYVAL pwszClassName AS WSTRING PTR) AS HWND
'  DIM hwndBrowser AS HWND = FindWindowW(pwszClassName, NULL)
'  IF hwndBrowser = NULL THEN RETURN NULL
'  DIM dwThread AS DWORD = GetWindowThreadProcessId(hwndBrowser, NULL)
'  IF dwThread = 0 THEN RETURN NULL
'  DIM hwndTop AS HWND
'  EnumThreadWindows(dwThread, @AfxEnumThreadWndProc, CAST(LPARAM, @hwndTop))
'  RETURN hwndTop
'END FUNCTION
'' ========================================================================================
'' ========================================================================================
'' Retrieves the top level window handle of Intenet Exploreror Google Chrome.
'' ========================================================================================
'PRIVATE FUNCTION AfxGetChromiumHandle () AS HWND
'   DIM hWin AS HWND = AfxGetBrowserHandle("Chrome_WidgetWin_1")
'   IF hWin = NULL THEN hWin = AfxGetBrowserHandle("Chrome_WidgetWin_2")
'   RETURN  hWin
'END FUNCTION
'' ========================================================================================
'' ========================================================================================
'' Retrieves the top level window handle of Firefox.
'' ========================================================================================
'PRIVATE FUNCTION AfxGetFireFoxHandle () AS HWND
'   RETURN AfxGetBrowserHandle("MozillaWindowClass")
'END FUNCTION
'' ========================================================================================

' ========================================================================================
' * Retrieves the path of the default mail client application.
' ========================================================================================
PRIVATE FUNCTION AfxGetDefaultMailClientPath () AS DWSTRING
   DIM wszPath AS WSTRING * MAX_PATH, cchOut AS DWORD = SIZEOF(wszPath)\2
   IF SUCCEEDED(AssocQueryStringW(0, ASSOCSTR_EXECUTABLE, "mailto", "open", wszPath, @cchOut)) THEN RETURN wszPath
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retrieves the name of the default mail client application.
' ========================================================================================
PRIVATE FUNCTION AfxGetDefaultMailClientName () AS DWSTRING
   DIM wszPath AS WSTRING * MAX_PATH, cchOut AS DWORD = SIZEOF(wszPath)\2
   IF SUCCEEDED(AssocQueryStringW(0, ASSOCSTR_EXECUTABLE, "mailto", "open", wszPath, @cchOut)) THEN
      RETURN AfxGetFileName(wszPath)
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

END NAMESPACE
