' ########################################################################################
' Platform: Microsoft Windows
' Filename: BSTRING.inc
' Purpose:  Implementation of the BSTR (COM unicode strings) data type.
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
#include once "AfxNova/DWSTRING.bi"
#include once "AfxNova/DWSTRING.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' Constructors
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING
   BSTRING_DP("Default")
   ' // Do nothing.
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYREF bs AS BSTRING)
   m_bstr = SysAllocString(bs)
   BSTRING_DP("BSTRING - " & ..WSTR(m_bstr))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYREF dws AS DWSTRING)
   m_bstr = SysAllocString(dws)
   BSTRING_DP("DWSTRING - " & ..WSTR(m_bstr))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the DWSTRING with the contents of the passed WSTRING.
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYREF wszStr AS CONST WSTRING)
   DWSTRING_DP("BYREF WSTRING")
   IF VARPTR(wszStr) = NULL THEN
      m_bstr = SysAllocString("")
   ELSEIF .LEN(wszStr) = 0 THEN
      m_bstr = SysAllocString("")
   ELSE
      m_bstr = SysAllocString(wszStr)
   END IF
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' If the passed pointer is a BSTR, it is atached to the class; otherwise, a new BSTR is created.
' It is unsafe because if a BSTRING is passed, the BSTR pointer will attached and two classes
' will attempt to release the same pointer. Use the Attach method instead.
' ========================================================================================
'PRIVATE CONSTRUCTOR BSTRING (BYVAL pwszStr AS WSTRING PTR, BYVAL fAttach AS BOOLEAN = FALSE)
'   BSTRING_DP("-1- BSTRING CONSTRUCTOR - SysAllocString - m_bstr = " & ..WSTR(m_bStr) & " - pwszStr = " & ..WSTR(pwszStr) & " - " & *pwszStr)
'   IF pwszStr = NULL THEN
'      m_bstr = SysAllocString("")
'   ELSE
'      ' Detect if the passed handle is an OLE string.
'      ' If it is an OLE string it must have a descriptor; otherwise, don't.
'      ' Get the length in bytes looking at the descriptor and divide by 2 to get the number of
'      ' unicode characters, that is the value returned by the FreeBASIC LEN operator.
'      DIM res AS DWORD = PEEK(DWORD, CAST(ANY PTR, pwszStr) - 4) \ 2
'      ' If the retrieved length is the same that the returned by LEN, then it must be an OLE string
'      IF res = .LEN(*pwszStr) AND fAttach = TRUE THEN
'         ' Attach the passed handle to the class
'         m_bstr = pwszStr
'      ELSE
'         ' Allocate an OLE string with the contents of the string pointed by pwszStr
'         m_bstr = SysAllocString(pwszStr)
'      END IF
'   END IF
'   BSTRING_DP("-2- BSTRING CONSTRUCTOR - SysAllocString - " & ..WSTR(m_bstr))
'END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYVAL pwszStr AS WSTRING PTR)
   BSTRING_DP("WSTRING PTR - pwszStr = " & ..WSTR(pwszStr))
   IF pwszStr = NULL THEN
      ' // Allocate an empty string
      m_bstr = SysAllocString("")
   ELSE
      ' Allocate an OLE string with the contents of the string pointed by pwszStr
      m_bstr = SysAllocString(pwszStr)
   END IF
   BSTRING_DP("m_bstr - " & ..WSTR(m_bstr))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYREF ansiStr AS STRING = "", BYVAL nCodePage AS UINT = 0)
   BSTRING_DP("STRING - " & ansiStr)
   IF nCodePage = CP_UTF8 THEN   ' // check if it is really valid utf-8
      IF this.IsUtf8(ansiStr) = FALSE THEN nCodePage = CP_ACP
   END IF
   IF nCodePage = CP_UTF8 THEN
      DIM dwLen AS DWORD = MultiByteToWideChar(CP_UTF8, 0, STRPTR(ansiStr), -1, NULL, 0)
      IF dwLen THEN
         m_bstr = SysAllocString(..WSTR(SPACE(dwLen)))
         MultiByteToWideChar(CP_UTF8, 0, STRPTR(ansiStr), -1, m_bstr, dwLen * 2)
      ELSE
         m_bstr = SysAllocString("")
      END IF
   ELSE
      IF .LEN(ansiStr) THEN
         m_bstr = SysAllocString(..WSTR(ansiStr))
         MultiByteToWideChar(nCodePage, MB_PRECOMPOSED, STRPTR(ansiStr), -1, m_bstr, .LEN(ansiStr) * 2)
      ELSE
         m_bstr = SysAllocString("")
      END IF
   END IF
   BSTRING_DP("STRING - " & ..WSTR(m_bstr))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Allocates a BSTRING wih a length of nChars characters.
' wszFill = A WString whose first character is to be used to fill the string. If wszFill
' is empty or null, it will be filled with spaces.
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYVAL nChars AS LONG, BYREF wszFill AS CONST WSTRING)
   BSTRING_DP("chars = " & ..WSTR(nChars))
   IF nChars < 1 THEN nChars = 1
   IF LEN(wszFill) THEN
      m_bstr = SysAllocString(WSTRING(nChars, wszFill))
   ELSE
      DIM _wszFill AS WSTRING * 2 = " "
      m_bstr = SysAllocString(WSTRING(nChars, _wszFill))
   END IF
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the BSTRING with a number.
' These two constructors are needed to allow to use a number with the & operator.
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYVAL n AS LONGINT)
   m_bstr = SysAllocString(..WSTR(n))
   BSTRING_DP("LONGINT - " & ..WSTR(m_bstr))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR BSTRING (BYVAL n AS DOUBLE)
   m_bstr = SysAllocString(..WSTR(n))
   BSTRING_DP("DOUBLE - " & ..WSTR(m_bstr))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Destructor
' ========================================================================================
PRIVATE DESTRUCTOR BSTRING
   IF m_bstr THEN SysFreeString m_bstr
   BSTRING_DP(..WSTR(m_bstr))
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' * Appends a string to the BSTRING.
' ========================================================================================
PRIVATE SUB BSTRING.Append (BYVAL pwszStr AS WSTRING PTR)
   DIM n1 AS UINT = SysStringLen(m_bstr)
   DIM nLen AS UINT = .LEN(*pwszStr)
   IF nLen = 0 THEN EXIT SUB
   DIM b AS BSTR = SysAllocStringLen(NULL, n1 + nLen)
   IF b = NULL THEN EXIT SUB
   memcpy(b, m_bstr, n1 * SIZEOF(WSTRING))
   memcpy(b + n1, pwszStr, nLen * SIZEOF(WSTRING))
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = b
   BSTRING_DP("handle: " & ..WSTR(m_bstr))
END SUB
' ========================================================================================

' ========================================================================================
' Detect if the codification is valid utf-8
' ========================================================================================
FUNCTION BSTRING.IsUtf8 (BYREF s AS STRING) AS BOOLEAN
   IF LEN(s) = 0 THEN RETURN FALSE
   ' // Detect if it has a UTF-8 BOM
   IF LEN(s) >= 3 THEN
      IF ASC(s,1) = &hEF AND ASC(s,2) = &hBB AND ASC(s,3) = &hBF THEN RETURN TRUE
   END IF
   DIM wLen AS LONG = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, STRPTR(s), LEN(s), NULL, 0)
   RETURN (wLen <> 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Frees the m_bstr member.
' ========================================================================================
PRIVATE SUB BSTRING.Clear
   BSTRING_DP("handle: " & ..WSTR(m_bstr))
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = NULL
END SUB
' ========================================================================================

' ========================================================================================
' Attaches a BSTR to the BSTRING object by setting the m_bstr member to pbstrSrc.
' The purpose of this method is to attach a BSTR pointer returned by a function that
' returns a BSTR pointer directly. Attaching it ensures that the BSTR will be freed when
' the BSTRING is destroyed. Don't attach a BSTRING to another BSTRING because each BSTRING
' will try to free the same BSTR when they are destroyed.
' ========================================================================================
PRIVATE SUB BSTRING.Attach (BYVAL pbstrSrc AS BSTR)
   ' // Check if the passed pointer is really a BSTR
   DIM res AS DWORD = PEEK(DWORD, CAST(ANY PTR, pbstrSrc) - 4) \ 2
  ' // If the retrieved length is the same that the returned by LEN, then it must be an OLE string
   IF res = LEN(pbstrSrc) \2 THEN
      IF m_bstr THEN SysFreeString(m_bstr)
      m_bstr = pbstrSrc
   END IF
   BSTRING_DP("handle: " & ..WSTR(m_bstr))
END SUB
' ========================================================================================

' ========================================================================================
' Detaches the BSTR pointer from the BSTRING object.
' ========================================================================================
PRIVATE FUNCTION BSTRING.Detach () AS BSTR
   BSTRING_DP("handle: " & ..WSTR(m_bstr))
   DIM pbstr AS BSTR = m_bstr
   m_bstr = NULL
   RETURN pbstr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Allocates and returns a copy of this BSTRING.
' ========================================================================================
PRIVATE FUNCTION BSTRING.Copy () AS BSTRING
   BSTRING_DP("handle: " & ..WSTR(m_bstr))
   RETURN SysAllocStringLen(m_bstr, SysStringLen(m_bstr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the BSTR pointer
' ========================================================================================
PRIVATE OPERATOR BSTRING.CAST () AS ANY PTR
   BSTRING_DP("ANY PTR - handle: " & ..WSTR(m_bstr))
   OPERATOR =  CAST(ANY PTR, m_bstr)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns a pointer to the string data (same as **)
' ========================================================================================
PRIVATE OPERATOR BSTRING.CAST () BYREF AS CONST WSTRING
   BSTRING_DP("BYREF WSTRING - handle: " & ..WSTR(m_bstr))
   OPERATOR = *CAST(WSTRING PTR, m_bstr)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns the corresponding ASCII or Unicode integer representation of the character at
' the zero-based position specified by the nIndex parameter (0 for the first character,
' 1 for the second, etc.), e.g. value = dws[1]. To change the value: dws[1] = value.
' Example:
'   DIM bsText AS BSTRING = "This is my text."
'   bsText[1] = ASC("X")
'   PRINT bsText
' ========================================================================================
PRIVATE OPERATOR BSTRING.[] (BYVAL nIndex AS UINT) BYREF AS USHORT
   BSTRING_DP("index: " & ..WSTR(nIndex))
   OPERATOR = *CAST(USHORT PTR, CAST(ANY PTR, m_bstr + nIndex))
END OPERATOR
' ========================================================================================

' ========================================================================================
' Assigns new text to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.LET (BYREF bs AS BSTRING)
   BSTRING_DP("handle: " & ..WSTR(m_bstr))
   IF m_bstr = bs.m_bstr THEN  EXIT OPERATOR  ' // If the user has done cbs = cbs, ignore it
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = SysAllocString(bs)
   BSTRING_DP("new handle: " & ..WSTR(m_bstr))
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.LET (BYREF dws AS DWSTRING)
   BSTRING_DP("DWSTRING - handle: " & ..WSTR(m_bstr))
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = SysAllocString(dws)
   BSTRING_DP("DWSTRING - new handle: " & ..WSTR(m_bstr))
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.LET (BYREF wsz AS WSTRING)
   BSTRING_DP("WSTRING - handle: " & ..WSTR(m_bstr))
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = SysAllocString(wsz)
   BSTRING_DP("STRING - new handle: " & ..WSTR(m_bstr))
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.LET (BYREF s AS STRING)
   BSTRING_DP("STRING - handle: " & ..WSTR(m_bstr))
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = SysAllocString(s)
   BSTRING_DP("STRING - new handle: " & ..WSTR(m_bstr))
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.Let (BYVAL n AS LONGINT)
   BSTRING_DP("LONGINT - " & ..WSTR(n))
   this.Clear
   DIM wsz AS WSTRING * 260 = .WSTR(n)
   m_bstr = SysAllocString(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.Let (BYVAL n AS DOUBLE)
   BSTRING_DP("DOUBLE - " & ..WSTR(n))
   this.Clear
   DIM wsz AS WSTRING * 260 = .WSTR(n)
   m_bstr = SysAllocString(wsz)
END OPERATOR
' ========================================================================================

' ========================================================================================
' If the passed pointer is a BSTR, it is atached to the class; otherwise, a new BSTR is created.
' It is unsafe because if a BSTRING is assigned, the BSTR pointer will be attached and two classes
' will attempt to release the same pointer. Use the Attach method instead.
' ========================================================================================
'PRIVATE OPERATOR BSTRING.LET (BYVAL pwszStr AS WSTRING PTR)
'   BSTRING_DP("-1- BSTRING LET - WSTRING PTR " & ..WSTR(pwszStr) & " - m_bstr = " & ..WSTR(m_bstr))
'   ' Free the current OLE string
'   IF m_bstr THEN SysFreeString(m_bstr)
'   ' Detect if the passed handle is an OLE string.
'   ' If it is an OLE string it must have a descriptor; otherwise, don't.
'   ' Get the length in bytes looking at the descriptor and divide by 2 to get the number of
'   ' unicode characters, that is the value returned by the FreeBASIC LEN operator.
'   DIM res AS DWORD = PEEK(DWORD, CAST(ANY PTR, pwszStr) - 4) \ 2
'   ' If the retrieved length is the same that the returned by LEN, then it must be an OLE string
'   IF res = .LEN(*pwszStr) THEN
'      ' Attach the passed handle to the class
'      m_bstr = pwszStr
'   ELSE
'      ' Allocate an OLE string with the contents of the string pointed by pwszStr
'      m_bstr = SysAllocString(pwszStr)
'   END IF
'   BSTRING_DP("-2- BSTRING LET - WSTRING PTR " & ..WSTR(pwszStr) & " - m_bstr = " & ..WSTR(m_bstr))
'END OPERATOR
' ========================================================================================

' ========================================================================================
' Frees the underlying BSTR and returns a pointer to a new empty allocated BSTR.
' To pass the underlying BSTR to an OUT BYVAL BSTR PTR parameter.
' If we pass a BSTRING to a procedure with an OUT BSTR parameter without first freeing it
' we will have a memory leak.
' ========================================================================================
PRIVATE FUNCTION BSTRING.vptr () AS BSTR PTR
   BSTRING_DP("vptr")
   IF m_bstr THEN SysFreeString(m_bstr)
   m_bstr = SysAllocString("") ' Allocate empty BSTR
   RETURN @m_bstr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the address of the BSTRING string data (same as **)
' ========================================================================================
PRIVATE FUNCTION BSTRING.sptr () AS WSTRING PTR
   BSTRING_DP("sptr")
   RETURN cast(WSTRING PTR, m_bstr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts the BSTRING to UTF8.
' ========================================================================================
'PRIVATE PROPERTY BSTRING.Utf8 () AS STRING
'   BSTRING_DP("STRING - TO Utf8")
'   DIM cbLen AS INTEGER, bstrLen AS LONG
'   IF m_bstr = NULL THEN RETURN ""
'   bstrLen = SysStringLen(m_bstr)
'   DIM buffer AS STRING = STRING(bstrLen * 5 + 1, 0)
'   PROPERTY = *cast(ZSTRING PTR, WCharToUTF(1, cast(WSTRING PTR, m_bstr), bstrLen, STRPTR(buffer), @cbLen))
'END PROPERTY
' ========================================================================================
PRIVATE PROPERTY BSTRING.Utf8 () AS STRING
   BSTRING_DP("STRING - TO Utf8")
   IF m_bstr = NULL THEN RETURN ""
   DIM bstrLen AS LONG = SysStringLen(m_bstr)
   DIM cbLen AS LONG = WideCharToMultiByte(CP_UTF8, 0, cast(WSTRING PTR, m_bstr), bstrLen, NULL, 0, NULL, NULL)
   IF cbLen = 0 THEN RETURN ""
   DIM buffer AS STRING = STRING(cbLen, 0)
   WideCharToMultiByte(CP_UTF8, 0, cast(WSTRING PTR, m_bstr), bstrLen, STRPTR(buffer), cbLen, NULL, NULL)
   RETURN buffer
END PROPERTY
' ========================================================================================

' ========================================================================================
' Converts UTF8 to unicode and assigns it to the BSTRING.
' ========================================================================================
PRIVATE PROPERTY BSTRING.Utf8 (BYREF utf8String AS STRING)
   BSTRING_DP("STRING - FROM Utf8")
   IF m_bstr THEN SysFreeString(m_bstr)
   DIM dwLen AS DWORD = MultiByteToWideChar(CP_UTF8, 0, STRPTR(utf8String), -1, NULL, 0)
   IF dwLen THEN
      m_bstr = SysAllocString(..WSTR(SPACE(dwLen)))
      MultiByteToWideChar(CP_UTF8, 0, STRPTR(utf8String), -1, m_bstr, dwLen * 2)
   ELSE
      m_bstr = SysAllocString("")
   END IF
END PROPERTY
' ========================================================================================

' =====================================================================================
' Returns the contents of the BSTRING as a WSTRING allocated with CoTaskMemAlloc.
' Free the returned string later with CoTaskMemFree.
' Note: This is useful when we need to pass a pointer to a null terminated wide string to a
' function or method that will release it. If we pass a WSTRING it will GPF.
' If the length of the input string is 0, CoTaskMemAlloc allocates a zero-length item and
' returns a valid pointer to that item. If there is insufficient memory available,
' CoTaskMemAlloc returns NULL.
' =====================================================================================
PRIVATE FUNCTION BSTRING.wchar () AS WSTRING PTR
   DIM pwchar AS WSTRING PTR
   DIM nLen AS LONG = SysStringLen(m_bstr) * 2
   pwchar = CoTaskMemAlloc(nLen)
   IF pwchar = NULL THEN RETURN NULL
   IF nLen THEN memcpy pwchar, m_bstr, nLen
   IF nLen = 0 THEN *pwchar = CHR(0)
   BSTRING_DP("pwchar: " & ..WSTR(pwchar))
   RETURN pwchar
END FUNCTION
' =====================================================================================

' ########################################################################################
' The following overloaded operators are needed because the length of the string needs to
' be updated and the intrinsic FreeBasic operators won't do it because they will treat the
' variable as a WSTRING, not as a BSTR.
' ########################################################################################

' ========================================================================================
' Appends a string to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.+= (BYVAL pwszStr AS WSTRING PTR)
   BSTRING_DP("WSTRING PTR")
   this.Append(pwszStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a BSTRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.+= (BYREF bs AS BSTRING)
   BSTRING_DP("BSTRING")
   this.Append(bs)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a DWSTRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.+= (BYREF dws AS DWSTRING)
   BSTRING_DP("DWSTRING")
   this.Append(dws)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a STRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.+= (BYREF s AS STRING)
   BSTRING_DP("STRING")
   this.Append(s)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a number to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.+= (BYVAL n AS LONGINT)
   BSTRING_DP("LONGINT - " & ..WSTR(n))
   DIM wsz AS WSTRING * 40 = ..WSTR(n)
   this.Append(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.+= (BYVAL n AS DOUBLE)
   BSTRING_DP("DOUBLE - " & ..WSTR(n))
   DIM wsz AS WSTRING * 40 = ..WSTR(n)
   this.Append(wsz)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a string to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.&= (BYVAL pwszStr AS WSTRING PTR)
   BSTRING_DP("WSTRING PTR")
   this.Append(pwszStr)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a BSTRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.&= (BYREF bs AS BSTRING)
   BSTRING_DP("BSTRING")
   this.Append(bs)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a DWSTRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.&= (BYREF dws AS DWSTRING)
   BSTRING_DP("DWSTRING")
   this.Append(dws)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a STRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.&= (BYREF s AS STRING)
   BSTRING_DP("STRING")
   this.Append(s)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a number to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR BSTRING.&= (BYVAL n AS LONGINT)
   BSTRING_DP("LONGINT - " & ..WSTR(n))
   DIM wsz AS WSTRING * 40 = ..WSTR(n)
   this.Append(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR BSTRING.&= (BYVAL n AS DOUBLE)
   BSTRING_DP("DOUBLE  " & ..WSTR(n))
   DIM wsz AS WSTRING * 40 = ..WSTR(n)
   this.Append(wsz)
END OPERATOR
' ========================================================================================

END NAMESPACE

' ########################################################################################
'                         *** GLOBAL OPERATORS AND FUNCTIONS ***
' ########################################################################################

' // Outside a namespace because they are global
USING AfxNova

' ========================================================================================
' Global operator.
' Returns the length, in characters, of the BSTRING.
' ========================================================================================
PRIVATE OPERATOR LEN (BYREF bs AS BSTRING) AS UINT
   OPERATOR = SysStringLen(bs)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Global operator.
' One * returns the BSTR handle. Same as STRPTR.
' Two ** deferences the string data. Same AS *STRPTR.
' ========================================================================================
PRIVATE OPERATOR * (BYREF bs AS BSTRING) AS WSTRING PTR
   OPERATOR = bs.m_bstr
END OPERATOR
' ========================================================================================

' ========================================================================================
' Concatenates two strings.
' Overloaded because the it fails without ambigous call when we use a combination
' of different data types and literals.
' The operator + doesn't have problems with this.
' ========================================================================================
PRIVATE OPERATOR & (BYREF bs1 AS BSTRING, BYREF bs2 AS BSTRING) AS BSTRING
   BSTRING_DP("BSTRING+BSTRING")
   OPERATOR = bs1 + bs2
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR & (BYREF bs AS BSTRING, BYREF dws AS DWSTRING) AS BSTRING
   BSTRING_DP("BSTRING+DWSTRING")
   OPERATOR = bs + dws
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR & (BYREF dws AS DWSTRING, BYREF bs AS BSTRING) AS BSTRING
   BSTRING_DP("DWSTRING+BSTRING")
   OPERATOR = dws + bs
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR & (BYREF bs AS BSTRING, BYREF s AS STRING) AS BSTRING
   BSTRING_DP("BSTRING+STRING")
   OPERATOR = bs + s
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR & (BYREF s AS STRING, BYREF bs AS BSTRING) AS BSTRING
   BSTRING_DP("STRING+BSTRING")
   OPERATOR = s + bs
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns the leftmost substring of a string
' Overloaded because the intrinsic LEFT operator fails with an ambiguous call error.
' ========================================================================================
PRIVATE FUNCTION Left OVERLOAD (BYREF bs AS BSTRING, BYVAL nChars AS INTEGER) AS BSTRING
   RETURN LEFT(**bs, nChars)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the rightmost substring of a string
' Overloaded because the intrinsic LEFT operator fails with an ambiguous call error.
' ========================================================================================
PRIVATE FUNCTION Right OVERLOAD (BYREF bs AS BSTRING, BYVAL nChars AS INTEGER) AS BSTRING
   RETURN RIGHT(**bs, nChars)
END FUNCTION
' ========================================================================================
