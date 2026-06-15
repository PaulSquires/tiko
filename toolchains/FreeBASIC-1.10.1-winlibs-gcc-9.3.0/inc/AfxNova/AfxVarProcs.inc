' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxVarProcs.inc
' Purpose:  VARIANT wrapper procedures.
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
#include once "win/shtypes.bi"
#include once "crt/limits.bi"
#INCLUDE ONCE "AfxNova/AfxWin.inc"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' // Renamed from tagPSTIME_FLAGS to AFX_tagPSTIME_FLAGS to avoid conflicts
' // if propvarutil.bi is ever added to the FB headers.
ENUM AFX_tagPSTIME_FLAGS
   PSTF_UTC = &h00000000
   PSTF_LOCAL = &h00000001
END ENUM
TYPE AFX_PSTIME_FLAGS AS LONG

' ########################################################################################
'                                *** VARIANT WRAPPERS ***
' ########################################################################################

' ========================================================================================
' For the API PROPVARIANT and VARIANT Functions see:
' https://msdn.microsoft.com/en-us/library/windows/desktop/bb762286%28v=vs.85%29.aspx
' ========================================================================================

' ========================================================================================
' Retrieves the element count of a variant structure.
' Note: Requires Windows XP SP2 or superior.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetElementCount (BYVAL pvarIn AS VARIANT PTR) AS ULONG
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetElementCount AS FUNCTION (BYVAL varIn AS VARIANT PTR) AS ULONG
   pVariantGetElementCount = DyLibSymbol(pLib, "VariantGetElementCount")
   IF pVariantGetElementCount = NULL THEN EXIT FUNCTION
   FUNCTION = pVariantGetElementCount(pvarIn)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the contents of a buffer stored in a VARIANT structure of type VT_ARRRAY | VT_UI1.
' Parameters:
' - pvarIn : [in] Reference to a source VARIANT structure.
' - pv     : [out] Pointer to a buffer of length cb bytes.
' - cb     : [in] The size of the pv buffer, in bytes. The buffer should be the same size as
'            the data to be extracted.
' Return value:
' Returns one of the following values:
' - S_OK         : Data successfully extracted.
' - E_INVALIDARG : The VARIANT was not of type VT_ARRRAY OR VT_UI1.
' - E_FAIL       : The VARIANT buffer value had fewer than cb bytes.
' Note: Requires Windows XP SP2 or superior.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToBuffer (BYVAL pvarIn AS VARIANT PTR, BYVAL pv AS LPVOID, BYVAL cb AS ULONG) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToBuffer AS FUNCTION (BYVAL pvarIn AS VARIANT PTR, BYVAL pv AS LPVOID, BYVAL cb AS ULONG) AS HRESULT
   pVariantToBuffer = DyLibSymbol(pLib, "VariantToBuffer")
   IF pVariantToBuffer = NULL THEN FUNCTION = E_FAIL
   FUNCTION = pVariantToBuffer(pvarIn, pv, cb)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the variant value of a variant structure to a string.
' Parameters:
' - pvarIn  : [in] Reference to a source variant structure.
' - pwszBuf : [in] Pointer to a buffer of length *cchBuf* bytes. When this function returns,
'             contains the first *cchBuf* bytes of the extracted buffer value.
' - cchBuf  : [in] The size of the *pwszBuf* buffer, in bytes.
' Return value:
' If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToString (BYVAL pvarIn AS VARIANT PTR, BYVAL pwszBuf AS WSTRING PTR, BYVAL cchBuf AS UINT) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToString AS FUNCTION (BYVAL pVar AS VARIANT PTR, BYVAL pwszBuf AS WSTRING PTR, BYVAL cchBuf AS UINT) AS HRESULT
   pVariantToString = DyLibSymbol(pLib, "VariantToString")
   IF pVariantToString = NULL THEN FUNCTION = E_FAIL
   FUNCTION = pVariantToString(pvarIn, pwszBuf, cchBuf)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts the string property value of a variant structure. If no value exists, then the
' specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToStringWithDefault (BYVAL varIn AS VARIANT PTR, BYVAL pszDefault AS LPCWSTR) AS PCWSTR
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToStringWithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pszDefault AS LPCWSTR) AS PCWSTR
   pVariantToStringWithDefault = DyLibSymbol(pLib, "VariantToStringWithDefault")
   IF pVariantToStringWithDefault THEN FUNCTION = pVariantToStringWithDefault(varIn, pszDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the variant value of a variant structure to a string.
' Parameters:
' - pvarIn   : [in] Reference to a source variant structure.
' - ppwszBuf : [out] Pointer to a buffer that contains the extracted string exists.
' Return value:
' If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToStringAlloc (BYVAL pvarIn AS VARIANT PTR, BYVAL ppwszBuf AS WSTRING PTR PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToStringAlloc AS FUNCTION (BYVAL pVar AS VARIANT PTR, BYVAL ppwszBuf AS WSTRING PTR PTR) AS HRESULT
   pVariantToStringAlloc = DyLibSymbol(pLib, "VariantToStringAlloc")
   IF pVariantToStringAlloc = NULL THEN FUNCTION = E_FAIL
   FUNCTION = pVariantToStringAlloc(pvarIn, ppwszBuf)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure based on a string resource imbedded in an executable file.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromResource (BYVAL hinst AS HINSTANCE, BYVAL id AS UINT, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromResource AS FUNCTION (BYVAL hinst AS HINSTANCE, BYVAL id AS UINT, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromResource = DyLibSymbol(pLib, "InitVariantFromResource")
   IF pInitVariantFromResource THEN FUNCTION = pInitVariantFromResource(hinst, id, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with the contents of a buffer.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromBuffer (BYVAL pv AS VOID PTR, BYVAL cb AS UINT, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromBuffer AS FUNCTION (BYVAL pv AS VOID PTR, BYVAL cb AS UINT, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromBuffer = DyLibSymbol(pLib, "InitVariantFromBuffer")
   IF pInitVariantFromBuffer THEN FUNCTION = pInitVariantFromBuffer(pv, cb, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure based on a GUID. The structure is initialized as a VT_BSTR type.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromGUIDAsString (BYVAL guid AS IID PTR, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromGUIDAsString AS FUNCTION (BYVAL guid AS IID PTR, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromGUIDAsString = DyLibSymbol(pLib, "InitVariantFromGUIDAsString")
   IF pInitVariantFromGUIDAsString THEN FUNCTION = pInitVariantFromGUIDAsString(guid, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with the contents of a FILETIME structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromFileTime (BYVAL pft AS FILETIME PTR, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromFileTime AS FUNCTION (BYVAL pft AS FILETIME PTR, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromFileTime = DyLibSymbol(pLib, "InitVariantFromFileTime")
   IF pInitVariantFromFileTime THEN FUNCTION = pInitVariantFromFileTime(pft, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of FILETIME structures.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromFileTimeArray (BYVAL prgft AS FILETIME PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromFileTimeArray AS FUNCTION (BYVAL prgft AS FILETIME PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromFileTimeArray = DyLibSymbol(pLib, "InitVariantFromFileTimeArray")
   IF pInitVariantFromFileTimeArray THEN FUNCTION = pInitVariantFromFileTimeArray(prgft, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a string stored in a STRRET structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromStrRet (BYVAL pstrret AS STRRET PTR, BYVAL pidl AS PCUITEMID_CHILD, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromStrRet AS FUNCTION (BYVAL pstrret AS STRRET PTR, BYVAL pidl AS PCUITEMID_CHILD, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromStrRet = DyLibSymbol(pLib, "InitVariantFromStrRet")
   IF pInitVariantFromStrRet THEN FUNCTION = pInitVariantFromStrRet(pstrret, pidl, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a value stored in another VARIANT structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromVariantArrayElem (BYVAL varIn AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromVariantArrayElem AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromVariantArrayElem = DyLibSymbol(pLib, "InitVariantFromVariantArrayElem")
   IF pInitVariantFromVariantArrayElem THEN FUNCTION = pInitVariantFromVariantArrayElem(varIn, iElem, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure from an array of Boolean values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromBooleanArray (BYVAL prgf AS WINBOOL PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromBooleanArray AS FUNCTION (BYVAL prgf AS WINBOOL PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromBooleanArray = DyLibSymbol(pLib, "InitVariantFromBooleanArray")
   IF pInitVariantFromBooleanArray THEN FUNCTION = pInitVariantFromBooleanArray(prgf, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of 16-bit integer values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromInt16Array (BYVAL prgf AS SHORT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromInt16Array AS FUNCTION (BYVAL prgf AS SHORT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromInt16Array = DyLibSymbol(pLib, "InitVariantFromInt16Array")
   IF pInitVariantFromInt16Array THEN FUNCTION = pInitVariantFromInt16Array(prgf, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of unsigned 16-bit integer values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromUInt16Array (BYVAL prgf AS USHORT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromUInt16Array AS FUNCTION (BYVAL prgf AS SHORT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromUInt16Array = DyLibSymbol(pLib, "InitVariantFromUInt16Array")
   IF pInitVariantFromUInt16Array THEN FUNCTION = pInitVariantFromUInt16Array(prgf, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of 32-bit integer values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromInt32Array (BYVAL prgn AS LONG PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromInt32Array AS FUNCTION (BYVAL prgn AS LONG PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromInt32Array = DyLibSymbol(pLib, "InitVariantFromInt32Array")
   IF pInitVariantFromInt32Array THEN FUNCTION = pInitVariantFromInt32Array(prgn, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of unsigned 32-bit integer values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromUInt32Array (BYVAL prgn AS ULONG PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromUInt32Array AS FUNCTION (BYVAL prgn AS ULONG PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromUInt32Array = DyLibSymbol(pLib, "InitVariantFromUInt32Array")
   IF pInitVariantFromUInt32Array THEN FUNCTION = pInitVariantFromUInt32Array(prgn, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of 64-bit integer values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromInt64Array (BYVAL prgn AS LONGINT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromInt64Array AS FUNCTION (BYVAL prgn AS LONGINT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromInt64Array = DyLibSymbol(pLib, "InitVariantFromInt64Array")
   IF pInitVariantFromInt64Array THEN FUNCTION = pInitVariantFromInt64Array(prgn, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of unsigned 64-bit integer values.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromUInt64Array (BYVAL prgn AS ULONGINT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromUInt64Array AS FUNCTION (BYVAL prgn AS ULONGINT PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromUInt64Array = DyLibSymbol(pLib, "InitVariantFromUInt64Array")
   IF pInitVariantFromUInt64Array THEN FUNCTION = pInitVariantFromUInt64Array(prgn, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of values of type DOUBLE.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromDoubleArray (BYVAL prgn AS DOUBLE PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromDoubleArray AS FUNCTION (BYVAL prgn AS DOUBLE PTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromDoubleArray = DyLibSymbol(pLib, "InitVariantFromDoubleArray")
   IF pInitVariantFromDoubleArray THEN FUNCTION = pInitVariantFromDoubleArray(prgn, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an array of strings.
' ========================================================================================
PRIVATE FUNCTION AfxVariantFromStringArray (BYVAL prgsz AS PCWSTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pInitVariantFromStringArray AS FUNCTION (BYVAL prgsz AS PCWSTR, BYVAL cElems AS ULONG, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pInitVariantFromStringArray = DyLibSymbol(pLib, "InitVariantFromStringArray")
   IF pInitVariantFromStringArray THEN FUNCTION = pInitVariantFromStringArray(prgsz, cElems, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the value of a Boolean property from a VARIANT structure. If no value can be
' extracted, then a default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToBoolean (BYVAL varIn AS VARIANT PTR, BYVAL pfRet AS WINBOOL PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToBoolean AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pfRet AS WINBOOL PTR) AS HRESULT
   pVariantToBoolean = DyLibSymbol(pLib, "VariantToBoolean")
   IF pVariantToBoolean THEN FUNCTION = pVariantToBoolean(varIn, pfRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts a BOOL value from a VARIANT structure. If no value exists, then the specified
' default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToBooleanWithDefault (BYVAL varIn AS VARIANT PTR, BYVAL fDefault AS WINBOOL) AS WINBOOL
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToBooleanWithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL fDefault AS WINBOOL) AS WINBOOL
   pVariantToBooleanWithDefault = DyLibSymbol(pLib, "VariantToBooleanWithDefault")
   IF pVariantToBooleanWithDefault THEN FUNCTION = pVariantToBooleanWithDefault(varIn, fDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the Int16 property value of a variant structure. If no value can be extracted,
' then a default value is assigned by this function.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt16 (BYVAL varIn AS VARIANT PTR, BYVAL piRet AS SHORT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt16 AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL piRet AS SHORT PTR) AS HRESULT
   pVariantToInt16 = DyLibSymbol(pLib, "VariantToInt16")
   IF pVariantToInt16 THEN FUNCTION = pVariantToInt16(varIn, piRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts an Int16 property value of a variant structure. If no value exists, then the
' specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt16WithDefault (BYVAL varIn AS VARIANT PTR, BYVAL iDefault AS SHORT) AS SHORT
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   DIM pVariantToInt16WithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL iDefault AS SHORT) AS SHORT
   pVariantToInt16WithDefault = DyLibSymbol(pLib, "VariantToInt16WithDefault")
   IF pVariantToInt16WithDefault THEN FUNCTION = pVariantToInt16WithDefault(varIn, iDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts an unsigned Int16 property value of a variant structure. If no value can be
' extracted, then a default value is assigned by this function.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt16 (BYVAL varIn AS VARIANT PTR, BYVAL puiRet AS USHORT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt16 AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL puiRet AS USHORT PTR) AS HRESULT
   pVariantToUInt16 = DyLibSymbol(pLib, "VariantToUInt16")
   IF pVariantToUInt16 THEN FUNCTION = pVariantToUInt16(varIn, puiRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts an unsigned Int16 property value of a variant structure. If no value exists,
' then the specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt16WithDefault (BYVAL varIn AS VARIANT PTR, BYVAL uiDefault AS USHORT) AS USHORT
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt16WithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL uiDefault AS USHORT) AS USHORT
   pVariantToUInt16WithDefault = DyLibSymbol(pLib, "VariantToUInt16WithDefault")
   IF pVariantToUInt16WithDefault THEN FUNCTION = pVariantToUInt16WithDefault(varIn, uiDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts an Int32 property value of a variant structure. If no value can be extracted,
' then a default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt32 (BYVAL varIn AS VARIANT PTR, BYVAL plRet AS LONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt32 AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL plRet AS LONG PTR) AS HRESULT
   pVariantToInt32 = DyLibSymbol(pLib, "VariantToInt32")
   IF pVariantToInt32 THEN FUNCTION = pVariantToInt32(varIn, plRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts an Int32 property value of a variant structure. If no value exists, then the
' specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt32WithDefault (BYVAL varIn AS VARIANT PTR, BYVAL lDefault AS LONG) AS LONG
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt32WithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL lDefault AS LONG) AS LONG
   pVariantToInt32WithDefault = DyLibSymbol(pLib, "VariantToInt32WithDefault")
   IF pVariantToInt32WithDefault THEN FUNCTION = pVariantToInt32WithDefault(varIn, lDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts unsigned Int32 property value of a variant structure. If no value can be
' extracted, then a default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt32 (BYVAL varIn AS VARIANT PTR, BYVAL pulRet AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt32 AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pulRet AS ULONG PTR) AS HRESULT
   pVariantToUInt32 = DyLibSymbol(pLib, "VariantToUInt32")
   IF pVariantToUInt32 THEN FUNCTION = pVariantToUInt32(varIn, pulRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts an unsigned Int32 property value of a variant structure. If no value currently
' exists, then the specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt32WithDefault (BYVAL varIn AS VARIANT PTR, BYVAL ulDefault AS ULONG) AS ULONG
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt32WithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL ulDefault AS ULONG) AS ULONG
   pVariantToUInt32WithDefault = DyLibSymbol(pLib, "VariantToUInt32WithDefault")
   IF pVariantToUInt32WithDefault THEN FUNCTION = pVariantToUInt32WithDefault(varIn, ulDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts an Int64 property value of a variant structure. If no value can be extracted,
' then a default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt64 (BYVAL varIn AS VARIANT PTR, BYVAL pllRet AS LONGINT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt64 AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pllRet AS LONGINT PTR) AS HRESULT
   pVariantToInt64 = DyLibSymbol(pLib, "VariantToInt64")
   IF pVariantToInt64 THEN FUNCTION = pVariantToInt64(varIn, pllRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts an Int64 property value of a variant structure. If no value exists, then the
' specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt64WithDefault (BYVAL varIn AS VARIANT PTR, BYVAL llDefault AS LONGINT) AS LONGINT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt64WithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL llDefault AS LONGINT) AS LONGINT
   pVariantToInt64WithDefault = DyLibSymbol(pLib, "VariantToInt64WithDefault")
   IF pVariantToInt64WithDefault THEN FUNCTION = pVariantToInt64WithDefault(varIn, llDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts unsigned Int64 property value of a variant structure. If no value can be
' extracted, then a default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt64 (BYVAL varIn AS VARIANT PTR, BYVAL pullRet AS ULONGINT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt64 AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pullRet AS ULONGINT PTR) AS HRESULT
   pVariantToUInt64 = DyLibSymbol(pLib, "VariantToUInt64")
   IF pVariantToUInt64 THEN FUNCTION = pVariantToUInt64(varIn, pullRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts an unsigned Int64 property value of a variant structure. If no value currently
' exists, then the specified default value is returned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt64WithDefault (BYVAL varIn AS VARIANT PTR, BYVAL ullDefault AS ULONGINT) AS ULONGINT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt64WithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL ullDefault AS ULONGINT) AS ULONGINT
   pVariantToUInt64WithDefault = DyLibSymbol(pLib, "VariantToUInt64WithDefault")
   IF pVariantToUInt64WithDefault THEN FUNCTION = pVariantToUInt64WithDefault(varIn, ullDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a DOUBLE value from a VARIANT structure. If no value can be extracted, then a
' default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToDouble (BYVAL varIn AS VARIANT PTR, BYVAL pdblRet AS DOUBLE PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToDouble AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pdblRet AS DOUBLE PTR) AS HRESULT
   pVariantToDouble = DyLibSymbol(pLib, "VariantToDouble")
   IF pVariantToDouble THEN FUNCTION = pVariantToDouble(varIn, pdblRet)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts a DOUBLE value from a VARIANT structure. If no value can be extracted, then a
' default value is assigned.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToDoubleWithDefault (BYVAL varIn AS VARIANT PTR, BYVAL dblDefault AS DOUBLE) AS DOUBLE
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToDoubleWithDefault AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL dblDefault AS DOUBLE) AS DOUBLE
   pVariantToDoubleWithDefault = DyLibSymbol(pLib, "VariantToDoubleWithDefault")
   IF pVariantToDoubleWithDefault THEN FUNCTION = pVariantToDoubleWithDefault(varIn, dblDefault)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a GUID property value of a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToGUID (BYVAL varIn AS VARIANT PTR, BYVAL pguid AS GUID PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToGUID AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pguid AS GUID PTR) AS HRESULT
   pVariantToGUID = DyLibSymbol(pLib, "VariantToGUID")
   IF pVariantToGUID THEN FUNCTION = pVariantToGUID(varIn, pguid)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a GUID property value of a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToDosDateTime (BYVAL varIn AS VARIANT PTR, BYVAL pwDate AS WORD PTR, BYVAL pwTime AS WORD PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToDosDateTime AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pwDate AS WORD PTR, BYVAL pwTime AS WORD PTR) AS HRESULT
   pVariantToDosDateTime = DyLibSymbol(pLib, "VariantToDosDateTime")
   IF pVariantToDosDateTime THEN FUNCTION = pVariantToDosDateTime(varIn, pwDate, pwTime)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' If the source variant is a VT_BSTR, extracts string and places it into a STRRET structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToStrRet (BYVAL varIn AS VARIANT PTR, BYVAL pstrret AS STRRET PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToStrRet AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL pstrret AS STRRET PTR) AS HRESULT
   pVariantToStrRet = DyLibSymbol(pLib, "VariantToStrRet")
   IF pVariantToStrRet THEN FUNCTION = pVariantToStrRet(varIn, pstrret)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a FILETIME structure from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToFileTime (BYVAL varIn AS VARIANT PTR, BYVAL stfOut AS AFX_PSTIME_FLAGS, BYVAL pftOut AS FILETIME PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToFileTime AS FUNCTION (BYVAL varIn AS VARIANT PTR, BYVAL stfOut AS AFX_PSTIME_FLAGS, BYVAL pftOut AS FILETIME PTR) AS HRESULT
   pVariantToFileTime = DyLibSymbol(pLib, "VariantToFileTime")
   IF pVariantToFileTime THEN FUNCTION = pVariantToFileTime(varIn, stfOut, pftOut)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts an array of Boolean values from a VARIANT structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToBooleanArray (BYVAL pvar AS VARIANT PTR, BYVAL prgf AS WINBOOL PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToBooleanArray AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgf AS WINBOOL PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToBooleanArray = DyLibSymbol(pLib, "VariantToBooleanArray")
   IF pVariantToBooleanArray THEN FUNCTION = pVariantToBooleanArray(pvar, prgf, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Allocates an array of BOOL values then extracts data from a VARIANT structure into that array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToBooleanArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgf AS WINBOOL PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToBooleanArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgf AS WINBOOL PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToBooleanArrayAlloc = DyLibSymbol(pLib, "VariantToBooleanArrayAlloc")
   IF pVariantToBooleanArrayAlloc THEN FUNCTION = pVariantToBooleanArrayAlloc(pvar, pprgf, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into an Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt16Array (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS SHORT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt16Array AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS SHORT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToInt16Array = DyLibSymbol(pLib, "VariantToInt16Array")
   IF pVariantToInt16Array THEN FUNCTION = pVariantToInt16Array(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt16ArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS SHORT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt16ArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS SHORT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToInt16ArrayAlloc = DyLibSymbol(pLib, "VariantToInt16ArrayAlloc")
   IF pVariantToInt16ArrayAlloc THEN FUNCTION = pVariantToInt16ArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt16Array (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS USHORT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt16Array AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS USHORT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToUInt16Array = DyLibSymbol(pLib, "VariantToUInt16Array")
   IF pVariantToUInt16Array THEN FUNCTION = pVariantToUInt16Array(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt16ArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS USHORT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt16ArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS USHORT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToUInt16ArrayAlloc = DyLibSymbol(pLib, "VariantToUInt16ArrayAlloc")
   IF pVariantToUInt16ArrayAlloc THEN FUNCTION = pVariantToUInt16ArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt32Array (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS LONG PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt32Array AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS LONG PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToInt32Array = DyLibSymbol(pLib, "VariantToInt32Array")
   IF pVariantToInt32Array THEN FUNCTION = pVariantToInt32Array(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt32ArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS LONG PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt32ArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS LONG PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToInt32ArrayAlloc = DyLibSymbol(pLib, "VariantToInt32ArrayAlloc")
   IF pVariantToInt32ArrayAlloc THEN FUNCTION = pVariantToInt32ArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int16 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt32Array (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS ULONG PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt32Array AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS ULONG PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToUInt32Array = DyLibSymbol(pLib, "VariantToUInt32Array")
   IF pVariantToUInt32Array THEN FUNCTION = pVariantToUInt32Array(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int32 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt32ArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS ULONG PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt32ArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS ULONG PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToUInt32ArrayAlloc = DyLibSymbol(pLib, "VariantToUInt32ArrayAlloc")
   IF pVariantToUInt32ArrayAlloc THEN FUNCTION = pVariantToUInt32ArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int64 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt64Array (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS LONGINT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt64Array AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS LONGINT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToInt64Array = DyLibSymbol(pLib, "VariantToInt64Array")
   IF pVariantToInt64Array THEN FUNCTION = pVariantToInt64Array(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated Int64 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToInt64ArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS LONGINT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToInt64ArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS LONGINT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToInt64ArrayAlloc = DyLibSymbol(pLib, "VariantToInt64ArrayAlloc")
   IF pVariantToInt64ArrayAlloc THEN FUNCTION = pVariantToInt64ArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int64 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt64Array (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS ULONGINT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt64Array AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS ULONGINT PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToUInt64Array = DyLibSymbol(pLib, "VariantToUInt64Array")
   IF pVariantToUInt64Array THEN FUNCTION = pVariantToUInt64Array(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated Int64 array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToUInt64ArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS ULONGINT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToUInt64ArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS ULONGINT PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToUInt64ArrayAlloc = DyLibSymbol(pLib, "VariantToUInt64ArrayAlloc")
   IF pVariantToUInt64ArrayAlloc THEN FUNCTION = pVariantToUInt64ArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts an array of DOUBLE values from a VARIANT structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToDoubleArray (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS DOUBLE PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToDoubleArray AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgn AS DOUBLE PTR, BYVAL crgn AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToDoubleArray = DyLibSymbol(pLib, "VariantToDoubleArray")
   IF pVariantToDoubleArray THEN FUNCTION = pVariantToDoubleArray(pvar, prgn, crgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Allocates an array of DOUBLE values then extracts data from a VARIANT structure into that array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToDoubleArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS DOUBLE PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToDoubleArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgn AS DOUBLE PTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToDoubleArrayAlloc = DyLibSymbol(pLib, "VariantToDoubleArrayAlloc")
   IF pVariantToDoubleArrayAlloc THEN FUNCTION = pVariantToDoubleArrayAlloc(pvar, pprgn, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts data from a vector structure into a string array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToStringArray (BYVAL pvar AS VARIANT PTR, BYVAL prgsz AS PWSTR, BYVAL crgsz AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToStringArray AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL prgsz AS PWSTR, BYVAL crgsz AS ULONG, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToStringArray = DyLibSymbol(pLib, "VariantToStringArray")
   IF pVariantToStringArray THEN FUNCTION = pVariantToStringArray(pvar, prgsz, crgsz, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Extracts data from a vector structure into a newly-allocated string array.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToStringArrayAlloc (BYVAL pvar AS VARIANT PTR, BYVAL pprgsz AS PWSTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToStringArrayAlloc AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL pprgsz AS PWSTR PTR, BYVAL pcElem AS ULONG PTR) AS HRESULT
   pVariantToStringArrayAlloc = DyLibSymbol(pLib, "VariantToStringArrayAlloc")
   IF pVariantToStringArrayAlloc THEN FUNCTION = pVariantToStringArrayAlloc(pvar, pprgsz, pcElem)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single Boolean element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetBooleanElem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pfVal AS WINBOOL PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetBooleanElem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pfVal AS WINBOOL PTR) AS HRESULT
   pVariantGetBooleanElem = DyLibSymbol(pLib, "VariantGetBooleanElem")
   IF pVariantGetBooleanElem THEN FUNCTION = pVariantGetBooleanElem(pvar, iElem, pfVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single Int16 element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetInt16Elem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pfVal AS SHORT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetInt16Elem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pfVal AS SHORT PTR) AS HRESULT
   pVariantGetInt16Elem = DyLibSymbol(pLib, "VariantGetInt16Elem")
   IF pVariantGetInt16Elem THEN FUNCTION = pVariantGetInt16Elem(pvar, iElem, pfVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single unsigned Int16 element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetUInt16Elem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS USHORT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetUInt16Elem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS USHORT PTR) AS HRESULT
   pVariantGetUInt16Elem = DyLibSymbol(pLib, "VariantGetUInt16Elem")
   IF pVariantGetUInt16Elem THEN FUNCTION = pVariantGetUInt16Elem(pvar, iElem, pnVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single Int32 element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetInt32Elem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS LONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetInt32Elem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS LONG PTR) AS HRESULT
   pVariantGetInt32Elem = DyLibSymbol(pLib, "VariantGetInt32Elem")
   IF pVariantGetInt32Elem THEN FUNCTION = pVariantGetInt32Elem(pvar, iElem, pnVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single unsigned Int32 element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetUInt32Elem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS ULONG PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetUInt32Elem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS ULONG PTR) AS HRESULT
   pVariantGetUInt32Elem = DyLibSymbol(pLib, "VariantGetUInt32Elem")
   IF pVariantGetUInt32Elem THEN FUNCTION = pVariantGetUInt32Elem(pvar, iElem, pnVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single Int64 element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetInt64Elem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS LONGINT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetInt64Elem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS LONGINT PTR) AS HRESULT
   pVariantGetInt64Elem = DyLibSymbol(pLib, "VariantGetInt64Elem")
   IF pVariantGetInt64Elem THEN FUNCTION = pVariantGetInt64Elem(pvar, iElem, pnVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single unsigned Int64 element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetUInt64Elem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS ULONGINT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetUInt64Elem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS ULONGINT PTR) AS HRESULT
   pVariantGetUInt64Elem = DyLibSymbol(pLib, "VariantGetUInt64Elem")
   IF pVariantGetUInt64Elem THEN FUNCTION = pVariantGetUInt64Elem(pvar, iElem, pnVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts one double element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetDoubleElem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS DOUBLE PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetDoubleElem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL pnVal AS DOUBLE PTR) AS HRESULT
   pVariantGetDoubleElem = DyLibSymbol(pLib, "VariantGetDoubleElem")
   IF pVariantGetDoubleElem THEN FUNCTION = pVariantGetDoubleElem(pvar, iElem, pnVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts a single wide string element from a variant structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantGetStringElem (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL ppszVal AS PWSTR PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantGetStringElem AS FUNCTION (BYVAL pvar AS VARIANT PTR, BYVAL iElem AS ULONG, BYVAL ppszVal AS PWSTR PTR) AS HRESULT
   pVariantGetStringElem = DyLibSymbol(pLib, "VariantGetStringElem")
   IF pVariantGetStringElem THEN FUNCTION = pVariantGetStringElem(pvar, iElem, ppszVal)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Frees the memory and references used by an array of VARIANT structures stored in an array.
' ========================================================================================
PRIVATE SUB AfxClearVariantArray (BYVAL pvars AS VARIANT PTR, BYVAL cvars AS UINT)
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT SUB
   DIM pClearVariantArray AS SUB (BYVAL pvars AS VARIANT PTR, BYVAL cvars AS UINT)
   pClearVariantArray = DyLibSymbol(pLib, "ClearVariantArray")
   IF pClearVariantArray THEN pClearVariantArray(pvars, cvars)
   DyLibFree(pLib)
END SUB
' ========================================================================================

' ========================================================================================
' Compares two variant structures, based on default comparison rules.
' ========================================================================================
PRIVATE FUNCTION AfxVariantCompare (BYVAL var1 AS VARIANT PTR, BYVAL var2 AS VARIANT PTR) AS INT_
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantCompare AS FUNCTION (BYVAL var1 AS VARIANT PTR, BYVAL var2 AS VARIANT PTR) AS INT_
   pVariantCompare = DyLibSymbol(pLib, "VariantCompare")
   IF pVariantCompare THEN FUNCTION = pVariantCompare(var1, var2)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts the contents of a PROPVARIANT structure to a VARIANT structure.
' ========================================================================================
PRIVATE FUNCTION AfxPropVariantToVariant (BYVAL pPropVar AS PROPVARIANT PTR, BYVAL pVar AS VARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pPropVariantToVariant AS FUNCTION (BYVAL pPropVar AS PROPVARIANT PTR, BYVAL pVar AS VARIANT PTR) AS HRESULT
   pPropVariantToVariant = DyLibSymbol(pLib, "PropVariantToVariant")
   IF pPropVariantToVariant THEN FUNCTION = pPropVariantToVariant(pPropVar, pVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies the contents of a VARIANT structure to a PROPVARIANT structure.
' ========================================================================================
PRIVATE FUNCTION AfxVariantToPropVariant (BYVAL pVar AS VARIANT PTR, BYVAL pPropVar AS PROPVARIANT PTR) AS HRESULT
   FUNCTION = E_POINTER
   DIM AS ANY PTR pLib = DyLibLoad("propsys.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pVariantToPropVariant AS FUNCTION (BYVAL pVar AS VARIANT PTR, BYVAL pPropVar AS PROPVARIANT PTR) AS HRESULT
   pVariantToPropVariant = DyLibSymbol(pLib, "VariantToPropVariant")
   IF pVariantToPropVariant THEN FUNCTION = pVariantToPropVariant(pVar, pPropVar)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Variant types
' ========================================================================================
PRIVATE FUNCTION AfxGetVarType (BYVAL pvar AS VARIANT PTR) AS VARTYPE
   RETURN pvar->vt
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVarTypeFloat (BYVAL vt AS VARTYPE) AS BOOLEAN
   RETURN (vt = VT_R4 OR vt = VT_R8)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVariantArray (BYVAL pvar AS VARIANT PTR) AS BOOLEAN
   RETURN (pvar->vt AND VT_ARRAY)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVariantString (BYVAL pvar AS VARIANT PTR) AS BOOLEAN
   RETURN AfxVariantToStringWithDefault(pvar, NULL) <> NULL
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVarTypeSignedInteger (BYVAL vt AS VARTYPE) AS BOOLEAN
   DIM fRet AS BOOLEAN
   SELECT CASE vt
      CASE VT_I1, VT_I2, VT_I4, VT_I8
         fRet = TRUE
   END SELECT
   RETURN fRet
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVarTypeUnsignedInteger (BYVAL vt AS VARTYPE) AS BOOLEAN
   DIM fRet AS BOOLEAN
   SELECT CASE vt
      CASE VT_UI1, VT_UI2, VT_UI4, VT_UI8
         fRet = TRUE
   END SELECT
   RETURN fRet
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVarTypeInteger (BYVAL vt AS VARTYPE) AS BOOLEAN
   RETURN AfxIsVarTypeSignedInteger(vt) OR AfxIsVarTypeUnsignedInteger(vt)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION AfxIsVarTypeNumber (BYVAL vt AS VARTYPE) AS BOOLEAN
   RETURN (AfxIsVarTypeInteger(vt)) OR (AfxIsVarTypeFloat(vt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the contents of a VARIANT and returns them as a DWSTRING.
' When pvarIn contains an array, each element of the array is appended to the resulting
' string separated with a semicolon and a space.
' For variants that contains an array of bytes, use AfxVariantToBuffer.
' Parameters:
' - pvarIn = Pointer to the variant.
' - bClear = Clear the contents of the variant (TRUE or FALSE).
' Return value:
' - If the function succeeds, it returns the contents of the variant in string form;
'   if it fails, it returns an empty string and the contents of the variant aren't cleared.
' ========================================================================================
PRIVATE FUNCTION AfxVarToStr OVERLOAD (BYVAL pvarIn AS VARIANT PTR, BYVAL bClear AS BOOLEAN = FALSE) AS DWSTRING

   DIM dws AS DWSTRING
   IF pvarIn = NULL THEN RETURN ""

   SELECT CASE pvarIn->vt

      ' // Unsupported by VariantToStringAlloc
      CASE VT_ERROR : dws = WSTR(pvarin->scode)
      CASE VT_R4 : dws = WSTR(pvarIn->fltVal)
      CASE VT_CY   ' // Currency
         DIM s AS STRING = STR(pvarIn->cyVal.int64 / 10000)
         DIM p AS LONG = INSTR(s, ".")
         DIM dec AS STRING
         IF p THEN
            dec = MID(s + "0000", p + 1, 4)
            s = LEFT(s, p) & dec
         END IF
         IF s = "0" THEN s = "0.0000"
         RETURN s
      CASE VT_CY OR VT_BYREF   ' // BYREF CURRENCY
         DIM _cy AS CY = *pVarIn->pcyVal
         DIM s AS STRING = STR(_cy.int64 / 10000)
         DIM p AS LONG = INSTR(s, ".")
         DIM dec AS STRING
         IF p THEN
            dec = MID(s + "0000", p + 1, 4)
            s = LEFT(s, p) & dec
         END IF
         IF s = "0" THEN s = "0.0000"
         RETURN s
      CASE VT_DECIMAL   ' // Decimal
         DIM bstrOut AS BSTR
         VarBstrFromDec(@pVarIn->decVal, 0, 0, @bstrOut)
         DIM s AS STRING = *cast(WSTRING PTR, bstrOut)
         SysFreeString(bstrOut)
         RETURN s
      CASE VT_DECIMAL OR VT_BYREF   ' // BYREF DECIMAL
         DIM bstrOut AS BSTR
         DIM dec AS DECIMAL = *pVarIn->pdecVal
         VarBstrFromDec(@dec, 0, 0, @bstrOut)
         DIM s AS STRING = *cast(WSTRING PTR, bstrOut)
         SysFreeString(bstrOut)
         RETURN s

      ' // VT_BYREF variants
      CASE VT_BSTR OR VT_BYREF : IF pVarIn->pbstrVal THEN dws = *pVarin->pbstrVal
      CASE VT_BOOL OR VT_BYREF : IF pVarIn->pboolVal THEN dws = WSTR(*pVarIn->pboolVal)
      CASE VT_I1 OR VT_BYREF   : IF pVarIn->pcVal    THEN dws = WSTR(*pVarIn->pcVal)
      CASE VT_UI1 OR VT_BYREF  : IF pVarIn->pbVal    THEN dws = WSTR(*pVarIn->pbVal)
      CASE VT_I2 OR VT_BYREF   : IF pVarIn->piVal    THEN dws = WSTR(*pVarIn->piVal)
      CASE VT_UI2 OR VT_BYREF  : IF pVarIn->piVal    THEN dws = WSTR(*pVarIn->puiVal)
      CASE VT_INT OR VT_BYREF  : IF pVarIn->pintVal  THEN dws = WSTR(*pVarIn->pintVal)
      CASE VT_UINT OR VT_BYREF : IF pVarIn->puintVal THEN dws = WSTR(*pVarIn->puintVal)
      CASE VT_I4 OR VT_BYREF   : IF pVarIn->plVal    THEN dws = WSTR(*pVarIn->plVal)
      CASE VT_UI4 OR VT_BYREF  : IF pVarIn->pulVal   THEN dws = WSTR(*pVarIn->pulVal)
      CASE VT_I8 OR VT_BYREF   : IF pVarIn->pllVal   THEN dws = WSTR(*pVarIn->pllVal)
      CASE VT_UI8 OR VT_BYREF  : IF pVarIn->pullVal  THEN dws = WSTR(*pVarIn->pullVal)
      CASE VT_R4 OR VT_BYREF   : IF pvarIn->pfltVal  THEN dws = WSTR(*pvarIn->pfltVal)
      CASE VT_R8 OR VT_BYREF   : IF pvarIn->pdblVal  THEN dws = WSTR(*pvarIn->pdblVal)

      ' // Array of floats
      CASE VT_ARRAY OR VT_R4
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS SINGLE PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData(pvarIn->parray)

      ' // Array of doubles
      CASE VT_ARRAY OR VT_R8
         IF pvarIn->parray = NULL THEN RETURN ""
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         DIM pvData AS DOUBLE PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData(pvarIn->parray)

      ' // Array of signed shorts or bools
      CASE VT_ARRAY OR VT_I2, VT_ARRAY OR VT_BOOL
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS SHORT PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += STR(pvData[i - lBound_])  ' Adjust index relative to base
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData(pvarIn->parray)

      ' // Array of unsigned shorts
      CASE VT_ARRAY OR VT_UI2
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS USHORT PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i - lBound_])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData pvarIn->parray

      ' // Array of signed longs
      CASE VT_ARRAY OR VT_I4, VT_ARRAY OR VT_INT
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS LONG PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i - lBound_])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData pvarIn->parray

      ' // Array of unsigned longs
      CASE VT_ARRAY OR VT_UI4, VT_ARRAY OR VT_UINT
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS ULONG PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i - lBound_])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData pvarIn->parray

      ' // Array of longints
      CASE VT_ARRAY OR VT_I8
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS LONGINT PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i - lBound_])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData pvarIn->parray

      ' // Array of unsigned longints
      CASE VT_ARRAY OR VT_UI8
         IF pvarIn->parray = NULL THEN RETURN ""
         ' Get array bounds
         DIM lBound_ AS LONG, uBound_ AS LONG
         IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
         IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
         ' Access the data
         DIM pvData AS ULONGINT PTR
         IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
         ' Format the array contents
         FOR i AS LONG = lBound_ TO uBound_
            IF i > lBound_ THEN dws += " "
            dws += WSTR(pvData[i - lBound_])
            IF i < uBound_ THEN dws += ";"
         NEXT
         SafeArrayUnaccessData pvarIn->parray

      ' // Array of variants
         CASE VT_ARRAY OR VT_VARIANT
            IF pvarIn->parray = NULL THEN RETURN ""
            DIM vt AS USHORT
            IF SafeArrayGetVartype(pvarIn->parray, @vt) <> S_OK THEN RETURN ""
            IF vt <> VT_VARIANT THEN RETURN ""  ' Ensure it's an array of VARIANTs
            DIM lBound_ AS LONG, uBound_ AS LONG
            IF SafeArrayGetLBound(pvarIn->parray, 1, @lBound_) <> S_OK THEN RETURN ""
            IF SafeArrayGetUBound(pvarIn->parray, 1, @uBound_) <> S_OK THEN RETURN ""
            DIM pvData AS VARIANT PTR
            IF SafeArrayAccessData(pvarIn->parray, @pvData) <> S_OK THEN RETURN ""
            FOR i AS LONG = lBound_ TO uBound_
               DIM ppwszBuf AS WSTRING PTR
               IF AfxVariantToStringAlloc(@pvData[i], @ppwszBuf) = S_OK AND ppwszBuf <> NULL THEN
                  IF i = lBound_ THEN
                     dws += *ppwszBuf
                     IF uBound_ > lBound_ THEN dws += ";"
                  ELSE
                     dws += " " & *ppwszBuf
                     IF i < uBound_ THEN dws += ";"
                  END IF
                  CoTaskMemFree ppwszBuf
               END IF
            NEXT
            SafeArrayUnaccessData(pvarIn->parray)

      ' // Other...
      CASE ELSE
         DIM ppwszBuf AS WSTRING PTR
         DIM hr AS HRESULT = AfxVariantToStringAlloc(pvarIn, @ppwszBuf)
         IF hr <> S_OK OR ppwszBuf = NULL THEN RETURN ""
         dws = *ppwszBuf
         CoTaskMemFree ppwszBuf

   END SELECT

   ' // Clear the passed variant
   IF bClear THEN VariantClear(pVarIn)
   ' // Return the string
   RETURN dws

END FUNCTION
' ========================================================================================

' ========================================================================================
' Allows to pass the variant by reference, i.e. AfxVarToStr(v), instead of using AfxVarToStr(@v)
' This also allows to use directly the result of a function that returns a VARIANT or a DVARIANT,
' e.g. AfxVarToStr(AfxVarFromLong(83838), TRUE), AfxVarToStr(AfxCVarFromLong(83838)), while
' trying to use the first overloaded function, e.g. AfxVarToStr(@AfxVarFromLong(83838), TRUE),
' gives an apparently bogus compiler error: Error 7: Expected ")".
' ========================================================================================
PRIVATE FUNCTION AfxVarToStr OVERLOAD (BYREF varIn AS VARIANT, BYVAL bClear AS BOOLEAN = FALSE) AS DWSTRING
   RETURN AfxVarToStr(@varIn, bClear)
END FUNCTION
' ========================================================================================

END NAMESPACE
