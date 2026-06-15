' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxWsh.inc
' Purpose:  Windows scripting host wrappers
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
#INCLUDE ONCE "AfxNova/AfxWsh.bi"
#INCLUDE ONCE "AfxNova/DVARIANT.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' Returns the value of a key or value-name from the registry.
' Usage examples:
' print AfxRegRead("HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\ProcessorNameString")
' print AfxRegRead("HKLM\HARDWARE\DESCRIPTION\System\CentralProcessor\0\~Mhz")
' ========================================================================================
PRIVATE FUNCTION AfxRegRead (BYREF wszKey AS WSTRING) AS DWSTRING
   CoInitialize NULL
      ' // Create an instance of the IWshShell interface
   DIM pWsh AS Afx_IWshShell PTR
   ' pWsh = AfxNewCom("WScript.Shell")  ' // Does not work well in my system
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell_ AS GUID = (&hF935DC21, &h1CF0, &h11D0, {&hAD, &hB9, &h00, &hC0, &h4F, &hD5, &h8A, &h0B})
   DIM hr AS HRESULT = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell_, @pWsh)
   DIM dws AS DWSTRING
   IF pWsh THEN
      DIM bstrKey AS Afx_BSTR = SysAllocString(wszKey)
      DIM vValue AS VARIANT
      hr = pWsh->RegRead(bstrKey, @vValue)
      SysFreeString bstrKey
      IF hr = S_OK THEN
         dws = AfxVarToStr(@vValue)
         VariantClear(@vValue)
      END IF
      pWsh->Release
   END IF
   SetLastError hr
   CoUninitialize
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new key, adds another value-name to an existing key (and assigns it a value),
' or changes the value of an existing value-name.
' Usage examples:
' AfxRegWrite("HKCU\Software\ACME\FortuneTeller\", 1, "REG_BINARY")
' AfxRegWrite("HKCU\Software\ACME\FortuneTeller\MindReader"", "Goocher!", "REG_SZ")
' ========================================================================================
PRIVATE FUNCTION AfxRegWrite (BYREF wszKey AS WSTRING, BYREF dvValue AS DVARIANT, BYREF wszType AS WSTRING) AS HRESULT
   CoInitialize NULL
      ' // Create an instance of the IWshShell interface
   DIM pWsh AS Afx_IWshShell PTR
   ' pWsh = AfxNewCom("WScript.Shell")  ' // Does not work well in my system
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell_ AS GUID = (&hF935DC21, &h1CF0, &h11D0, {&hAD, &hB9, &h00, &hC0, &h4F, &hD5, &h8A, &h0B})
   DIM hr AS HRESULT = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell_, @pWsh)
   DIM dws AS DWSTRING
   IF pWsh THEN
      DIM bstrKey AS Afx_BSTR = SysAllocString(wszKey)
      DIM vType AS VARIANT
      vType.vt = VT_BSTR
      vType.bstrVal = SysAllocString(wszType)
      hr = pWsh->RegWrite(bstrKey, dvValue, @vType)
      SysFreeString bstrKey
      VariantClear @vType
      pWsh->Release
   END IF
   CoUninitialize
   RETURN hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a key or one of its values from the registry.
' Usage examples:
' AfxRegDelete("HKCU\Software\ACME\FortuneTeller\MindReader")
' AfxRegDelete("HKCU\Software\ACME\FortuneTeller\")
' AfxRegDelete("HKCU\Software\ACME\")
' ========================================================================================
PRIVATE FUNCTION AfxRegDelete (BYREF wszKey AS WSTRING) AS HRESULT
   CoInitialize NULL
      ' // Create an instance of the IWshShell interface
   DIM pWsh AS Afx_IWshShell PTR
   ' pWsh = AfxNewCom("WScript.Shell")  ' // Does not work well in my system
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell_ AS GUID = (&hF935DC21, &h1CF0, &h11D0, {&hAD, &hB9, &h00, &hC0, &h4F, &hD5, &h8A, &h0B})
   DIM hr AS HRESULT = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell_, @pWsh)
   IF pWsh THEN
      DIM bstrKey AS Afx_BSTR = SysAllocString(wszKey)
      hr = pWsh->RegDelete(bstrKey)
      SysFreeString bstrKey
   END IF
   CoUninitialize
   RETURN hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds an event entry to a log file.
' Usage example: AfxLogEvent(0, "Logon Script Completed Successfully")
' ========================================================================================
PRIVATE FUNCTION AfxLogEvent (BYVAL nType AS LONG, BYREF wszMessage AS WSTRING) AS HRESULT
   CoInitialize NULL
      ' // Create an instance of the IWshShell interface
   DIM pWsh AS Afx_IWshShell2 PTR
   ' pWsh = AfxNewCom("WScript.Shell")  ' // Does not work well in my system
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell2_ AS GUID = (&h24BE5A30, &hEDFE, &h11D2, {&hB9, &h33, &h00, &h10, &h4B, &h36, &h5C, &h9F})
   DIM hr AS HRESULT = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell2_, @pWsh)
   IF pWsh THEN
      DIM vType AS VARIANT
      vType.vt = VT_I4
      vType.lVal = nType
      DIM bstrMsg AS Afx_BSTR = SysAllocString(wszMessage)
      DIM bstrTarget AS Afx_BSTR = SysALlocString("")
      DIM bSuccess AS VARIANT_BOOL
      hr = pWsh->LogEvent(@vType, bstrMsg, bstrTarget, @bSuccess)
      SysFreeString bstrMsg
      SysFreeString bstrTarget
      pWsh->Release
   END IF
   CoUninitialize
   RETURN hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sends keystrokes to the active window.
' Example:
' AfxRun("calc")
' AfxForceSetForegroundWindow(FindWindow("Windows.UI.Core.CoreWindow", NULL))
' ---or-- AfxForceSetForegroundWindow(FindWindow(NULL, "calc"))
' SLEEP 1000
' AfxSendKeys("1{+}")
' SLEEP 500
' AfxSendKeys("2")
' SLEEP 500
' AfxSendKeys("~")
' SLEEP 500
' AfxSendKeys("*3")
' SLEEP 500
' AfxSendKeys("~")
' SLEEP 2500
' ========================================================================================
PRIVATE FUNCTION AfxSendKeys (BYREF wszKeys AS WSTRING, BYVAL bWait AS BOOLEAN = FALSE) AS HRESULT
   CoInitialize NULL
      ' // Create an instance of the IWshShell2 interface
   DIM pWsh AS Afx_IWshShell2 PTR
   ' pWsh = AfxNewCom("WScript.Shell")  ' // Does not work well in my system
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell2_ AS GUID = (&h24BE5A30, &hEDFE, &h11D2, {&hB9, &h33, &h00, &h10, &h4B, &h36, &h5C, &h9F})
   DIM hr AS HRESULT = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell2_, @pWsh)
   IF pWsh THEN
      DIM bstrKeys AS Afx_BSTR = SysAllocString(wszKeys)
      DIM vWait AS VARIANT
      vWait.vt = VT_BOOL
      vWait.boolVal = bWait
      hr = pWsh->SendKeys(bstrKeys, @vWait)
      SysFreeString(bstrKeys)
      pWsh->Release
   END IF
   CoUninitialize
   RETURN hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Runs a program in a new process.
' Usage example: AfxRun("Calc")
' ========================================================================================
PRIVATE FUNCTION AfxRun (BYREF wszCommand AS WSTRING, BYVAL WindowStyle AS LONG = 0, BYVAL WaitOnReturn AS BOOLEAN = FALSE) AS HRESULT
   CoInitialize NULL
      ' // Create an instance of the IWshShell interface
   DIM pWsh AS Afx_IWshShell PTR
   ' pWsh = AfxNewCom("WScript.Shell")  ' // Does not work well in my system
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell_ AS GUID = (&hF935DC21, &h1CF0, &h11D0, {&hAD, &hB9, &h00, &hC0, &h4F, &hD5, &h8A, &h0B})
   DIM hr AS HRESULT = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell_, @pWsh)
   IF pWsh THEN
      DIM bstrCommand AS Afx_BSTR = SysAllocString(wszCommand)
      DIM vWindowStyle AS VARIANT
      vWindowStyle.vt = VT_I4
      vWindowStyle.lVal = WindowStyle
      DIM vWaitOnReturn AS VARIANT
      vWaitOnReturn.vt = VT_BOOL
      vWaitOnReturn.boolVal = WaitOnReturn
      DIM out_ExitCode AS INT_
      hr = pWsh->Run(bstrCommand, @vWindowStyle, @vWaitOnReturn, @out_ExitCode)
      SysFreeString(bstrCommand)
      pWsh->Release
   END IF
   CoUninitialize
   RETURN hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' CWhsExec class
' Usage example:
' #include "AfxNova/AfxWsh.inc"
' #include "AfxNova/CTextStream.inc"
' USING AfxNova
' DIM pWshExec AS CWhsExec = "%comspec% /c dir"
' IF pWshExec THEN
'    DIM pStdOutStm AS CTextStream = pWshExec.GetStdOut
'    IF pStdOutStm THEN
'       IF pStdOutStm.EOS = FALSE THEN
'           // The console uses the CP_OEMCP code page
'          DIM dwsOut AS DWSTRING
'          dwsOut.OEM = pStdOutStm.ReadAll
'          ' // You can also use
'          ' DIM dwsOut AS DWSTRING = DWSTRING(pStdOutStm.ReadAll, CP_OEMCP)
'          print dwsOut
'       END IF
'    END IF
' END IF
' ========================================================================================

TYPE CWhsExec

Private:
   
   m_Result AS HRESULT                   ' HRESULT code
   m_pWshShell3 AS Afx_IWshShell3 PTR    ' Pointer to the Afx_IWshShell3 interface
   m_pWshExec AS Afx_IWshExec PTR        ' Pointer to the Afx_IWshExec interface

Public:

   DECLARE CONSTRUCTOR (BYREF wszCommand AS WSTRING)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR CAST () AS Afx_IWshExec PTR
   DECLARE FUNCTION GetLastResult () AS HRESULT
   DECLARE FUNCTION GetErrorInfo (BYVAL nError AS LONG = -1) AS DWSTRING
   DECLARE PROPERTY CurrentDirectory () AS DWSTRING
   DECLARE PROPERTY CurrentDirectory (BYREF wszDir AS WSTRING) AS HRESULT
   DECLARE FUNCTION GetStatus () AS WshExecStatus
   DECLARE FUNCTION GetStdIn () AS Afx_ITextStream PTR
   DECLARE FUNCTION GetStdOut () AS Afx_ITextStream PTR
   DECLARE FUNCTION GetStdErr () AS Afx_ITextStream PTR
   DECLARE FUNCTION GetProcessID () AS LONG
   DECLARE FUNCTION GetExitCode () AS LONG
   DECLARE FUNCTION AppActivate (BYREF wszTitle AS WSTRING, BYVAL bWait AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE FUNCTION AppActivate (BYVAL processID AS LONG, BYVAL bWait AS BOOLEAN = FALSE) AS BOOLEAN
   DECLARE SUB Terminate

END TYPE
' ========================================================================================

' ========================================================================================
' Runs an application in a child command-shell, providing access to the StdIn/StdOut/StdErr streams.
' ========================================================================================
PRIVATE CONSTRUCTOR CWhsExec (BYREF wszCommand AS WSTRING)
   CoInitialize NULL
   ' // Create an instance of the IWshShell3 interface
   DIM CLSID_WshShell_ AS GUID = (&h72C24DD5, &hD70A, &h438B, {&h8A, &h42, &h98, &h42, &h4B, &h88, &hAF, &hB8})
   DIM IID_IWshShell3_ AS GUID = (&h41904400, &hBE18, &h11D3, {&hA2, &h8B, &h00, &h10, &h4B, &hD3, &h50, &h90})
   m_Result = CoCreateInstance(@CLSID_WshShell_, NULL, CLSCTX_INPROC_SERVER, @IID_IWshShell3_, @m_pWshShell3)
   IF m_pWshShell3 THEN
      DIM bstrCommand AS AFX_BSTR = SysAllocString(wszCommand)
      m_Result = m_pWshShell3->Exec(bstrCommand, @m_pWshExec)
      SysFreeString bstrCommand
   END IF
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CWhsExec
   IF m_pWshExec THEN m_pWshExec->Release
   IF m_pWshShell3 THEN m_pWshShell3->Release
   CoUninitialize
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Cast operator.
' ========================================================================================
PRIVATE OPERATOR CWhsExec.CAST () AS Afx_IWshExec PTR
   OPERATOR = m_pWshExec
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns the last result code
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetLastResult () AS HRESULT
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a description of the last result code.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetErrorInfo (BYVAL nError AS LONG = -1) AS DWSTRING
   IF nError = -1 THEN nError = m_Result
   DIM cbLen AS DWORD, pBuffer AS WSTRING PTR, dwsMsg AS DWSTRING
   cbLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER OR _
           FORMAT_MESSAGE_FROM_SYSTEM OR FORMAT_MESSAGE_IGNORE_INSERTS, _
           NULL, nError, BYVAL MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), _
           cast(LPWSTR, @pBuffer), 0, NULL)
   IF cbLen THEN
      dwsMsg = *pBuffer
      LocalFree pBuffer
   END IF
   IF nError THEN dwsMsg = "Error &h" + HEX(nError) & CHR(13, 10) + dwsMsg
   RETURN dwsMsg
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current active directory.
' ========================================================================================
PRIVATE PROPERTY CWhsExec.CurrentDirectory () AS DWSTRING
   DIM bstrDir AS AFX_BSTR
   m_Result = m_pWshShell3->get_CurrentDirectory(@bstrDir)
   DIM dws AS DWSTRING
   IF bstrDir THEN dws = *bstrDir
   SysFreeString bstrDir
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
' Changes the current active directory.
' ========================================================================================
PRIVATE PROPERTY CWhsExec.CurrentDirectory (BYREF wszDir AS WSTRING) AS HRESULT
   DIM bstrDir AS AFX_BSTR = SysAllocString(wszDir)
   m_Result = m_pWshShell3->put_CurrentDirectory(bstrDir)
   SysFreeString bstrDir
   RETURN m_Result
END PROPERTY
' ========================================================================================

' ========================================================================================
' Provides status information about a script run with the Exec method.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetStatus () AS WshExecStatus
   DIM nStatus AS WshExecStatus
   m_Result = m_pWshExec->get_Status(@nStatus)
   RETURN nStatus
END FUNCTION
' ========================================================================================

' ========================================================================================
' Exposes the stdin input stream of the IWshExec interface.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetStdIn () AS Afx_ITextStream PTR
   DIM pTextStream AS Afx_ITextStream PTR
   m_Result = m_pWshExec->get_StdIn(@pTextStream)
   RETURN pTextStream
END FUNCTION
' ========================================================================================

' ========================================================================================
' Exposes the stdout output stream of the IWshExec interface.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetStdOut () AS Afx_ITextStream PTR
   DIM pTextStream AS Afx_ITextStream PTR
   m_Result = m_pWshExec->get_StdOut(@pTextStream)
   RETURN pTextStream
END FUNCTION
' ========================================================================================

' ========================================================================================
' Provides access to the stderr output stream of the IWshExec interface.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetStdErr () AS Afx_ITextStream PTR
   DIM pTextStream AS Afx_ITextStream PTR
   m_Result = m_pWshExec->get_StdErr(@pTextStream)
   RETURN pTextStream
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the process ID (PID) for a process started with the Exec method.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetProcessID () AS LONG
   DIM nPID AS LONG
   m_Result = m_pWshExec->get_ProcessID(@nPID)
   RETURN nPID
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the exit code set by a script or program run using the Exec method.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.GetExitCode () AS LONG
   DIM nCode AS LONG
   m_Result = m_pWshExec->get_ExitCode(@nCode)
   RETURN nCode
END FUNCTION
' ========================================================================================

' ========================================================================================
' Activates an application window.
' ========================================================================================
PRIVATE FUNCTION CWhsExec.AppActivate (BYREF wszTitle AS WSTRING, BYVAL bWait AS BOOLEAN = FALSE) AS BOOLEAN
   DIM vApp AS VARIANT
   DIM bstrTitle AS Afx_BSTR = SysAllocString(wszTitle)
   vApp.vt = VT_BSTR
   vApp.bstrVal = bstrTitle
   DIM vWait AS VARIANT
   vWait.vt = VT_BOOL
   vWait.boolVal = bWait
   DIM vSuccess AS VARIANT_BOOL
   m_Result = m_pWshShell3->AppActivate(@vApp, @vWait, @vSuccess)
   VariantClear(@vApp)
   RETURN vSuccess
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CWhsExec.AppActivate (BYVAL processID AS LONG, BYVAL bWait AS BOOLEAN = FALSE) AS BOOLEAN
   DIM vApp AS VARIANT
   vApp.vt = VT_I4
   vApp.lVal = processID
   DIM vWait AS VARIANT
   vWait.vt = VT_BOOL
   vWait.boolVal = bWait
   DIM vSuccess AS VARIANT_BOOL
   m_Result = m_pWshShell3->AppActivate(@vApp, @vWait, @vSuccess)
   RETURN vSuccess
END FUNCTION
' ========================================================================================

' ========================================================================================
' Instructs the script engine to end the process started by the Exec method.
' ========================================================================================
PRIVATE SUB CWhsExec.Terminate
   m_pWshExec->Terminate
END SUB
' ========================================================================================

END NAMESPACE
