' ########################################################################################
' Platform: Microsoft Windows
' Filename: DWSTRING.inc
' Purpose:  Implements a dynamic unicode data type
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

' // Include files
#pragma once
#include once "AfxNova/DWSTRING.bi"
#include once "AfxNova/BSTRING.inc"
#include once "AfxNova/DWStrProcs.inc"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING
   DWSTRING_DP("Default")
   ' // Create a minimal initial buffer to make room for the teminating null
   this.ResizeBuffer(1, TRUE)
   DWSTRING_DP("Default - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Attempts to allocate, or reserve, nChars number of characters from the free store (heap).
' wszFill = A WString whose first character is to be used to fill the string.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYVAL nChars AS LONG, BYREF wszFill AS CONST WSTRING)
   DWSTRING_DP("nChars = " & ..WSTR(nChars))
   IF nChars < 1 THEN nChars = 1
   IF LEN(wszFill) THEN
      this.Add(WSTRING(nChars, wszFill))
   ElsE
      this.ResizeBuffer(nChars, TRUE)
   END IF
   DWSTRING_DP("nChars - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the DWSTRING with the contents of the passed WSTRING.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYREF wszStr AS CONST WSTRING)
   DWSTRING_DP("BYREF WSTRING")
   IF VARPTR(wszStr) = NULL THEN
      this.ResizeBuffer(1)
   ELSEIF .LEN(wszStr) = 0 THEN
      this.ResizeBuffer(1)
   ELSE
      this.Add(wszStr)
   END IF
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the DWSTRING with the contents of the passed WSTRING.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYVAL pwszStr AS WSTRING PTR)
   DWSTRING_DP("WSTRING PTR - pwszStr: " & ..WSTR(pwszStr))
   IF pwszStr = NULL THEN
      this.ResizeBuffer(1)
   ELSEIF .LEN(*pwszStr) = 0 THEN
      this.ResizeBuffer(1)
   ELSE
      this.Add(pwszStr)
   END IF
   DWSTRING_DP("WSTRING PTR - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the DWSTRING with the contents of the passed STRING.
' The default codepage is 0 (CP_ACP). You can pass CP_UTF8 to assign utf-8 strings.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0)
   DWSTRING_DP("STRING - code page: " & WSTR(nCodePage))
   IF .LEN(ansiStr) = 0 THEN
      this.ResizeBuffer(1)
   ELSE
      this.Add(ansiStr, nCodePage)
   END IF
   DWSTRING_DP("STRING - buffer: " & ..WSTR(m_pBuffer) & " - code page: " & WSTR(nCodePage))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the DWSTRING with the contents of the passed DWSTRING.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYREF dws AS DWSTRING)
   DWSTRING_DP("DWSTRING")
   IF dws.m_BufferLen = 0 THEN
      this.ResizeBuffer(1)
   ELSE
      this.Add(dws)
   END IF
   DWSTRING_DP("DWSTRING - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
' Initializes the DWSTRING with the contents of the passed BSTRING.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYREF bs AS BSTRING)
   DWSTRING_DP("BSTRING")
   ' Copy the string into the buffer and update the length
   this.AppendBuffer(cast(ANY PTR, bs.m_bstr), SysStringLen(bs))
   DWSTRING_DP("BSTRING - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Initializes the DWSTRING with a number.
' These two constructors are needed to allow to use a number with the & operator.
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYVAL n AS LONGINT)
   DWSTRING_DP("LONGINT - n = " & ..WSTR(n))
   DIM wsz AS WSTRING * 40 = ..WSTR(n)
   this.Add(wsz)
   DWSTRING_DP("LONGINT - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR DWSTRING (BYVAL n AS DOUBLE)
   DWSTRING_DP("DOUBLE - n = " & ..WSTR(n))
   DIM wsz AS WSTRING * 40 = ..WSTR(n)
   this.Add(wsz)
   DWSTRING_DP("DOUBLE - buffer: " & ..WSTR(m_pBuffer))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Destructor
' ========================================================================================
PRIVATE DESTRUCTOR DWSTRING
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
   IF m_pBuffer THEN Deallocate(m_pBuffer)
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns a pointer to the DWSTRING buffer.
' To avoid excesive use of casting when used with my other data types and procedures.
' ========================================================================================
PRIVATE OPERATOR DWSTRING.CAST () AS ANY PTR
   DWSTRING_DP("ANY PTR - buffer: " & ..WSTR(m_pBuffer))
   OPERATOR = m_pBuffer
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the string data (same as **).
' ========================================================================================
PRIVATE OPERATOR DWSTRING.CAST () BYREF AS CONST WSTRING
   DWSTRING_DP("BYREF AS WSTRING - buffer: " & ..WSTR(m_pBuffer))
   OPERATOR = *m_pBuffer
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns the corresponding ASCII or Unicode integer representation of the character at
' the zero-based position specified by the nIndex parameter (0 for the first character,
' 1 for the second, etc.), e.g. value = dws[1]. To change the value: dws[1] = value.
' Example:
'   DIM dwsText AS DWSTRING = "This is my text."
'   dwsText[1] = ASC("X")
'   PRINT dwsText
' ========================================================================================
PRIVATE OPERATOR DWSTRING.[] (BYVAL nIndex AS UINT) BYREF AS USHORT
   DWSTRING_DP("index: " & ..WSTR(nIndex) & " - " & "buffer: " & ..WSTR(m_pBuffer))
   OPERATOR = *CAST(USHORT PTR, m_pBuffer + nIndex)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Assigns new text to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYREF wszStr AS WSTRING)
   DWSTRING_DP("BYREF WSTRING")
   this.Clear : this.Add(wszStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYVAL pwszStr AS WSTRING PTR)
   DWSTRING_DP("WSTRING PTR")
   this.Clear : this.Add(*pwszStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYREF ansiStr AS STRING)
   DWSTRING_DP("STRING")
   this.Clear : this.Add(ansiStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYREF dws AS DWSTRING)
   DWSTRING_DP("DWSTRING - buffer: " & ..WSTR(m_pBuffer) & " - buffer in: " & ..WSTR(dws.m_pBuffer))
   IF m_pBuffer = dws.m_pBuffer THEN EXIT OPERATOR   ' // Ignore dws = dws
   this.Clear : this.Add(dws)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYREF bs AS BSTRING)
   DWSTRING_DP("BSTRING")
   this.Clear
   DIM AS LONG nLenString = SysStringLen(bs)
   this.ResizeBuffer(nLenString)
   ' Copy the string into the buffer and update the length
   this.AppendBuffer(cast(ANY PTR, bs.m_bstr), nLenString)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Assigns a number to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYVAL n AS LONGINT)
   DWSTRING_DP("LONGINT")
   this.Clear : DIM wsz AS WSTRING * 40 = ..WSTR(n) : this.Add(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.Let (BYVAL n AS DOUBLE)
   DWSTRING_DP("DOUBLE")
   this.Clear : DIM wsz AS WSTRING * 40 = ..WSTR(n) : this.Add(wsz)
END OPERATOR
' ========================================================================================

' ========================================================================================
' The size of the internal string buffer is retrieved and returned to the caller. The size
' is the number of characters which can be stored without further expansion.
' ========================================================================================
PRIVATE PROPERTY DWSTRING.Capacity() AS UINT
   DWSTRING_DP(..WSTR(m_Capacity))
   PROPERTY = m_Capacity
END PROPERTY
' ========================================================================================

' ========================================================================================
' The internal string buffer is expanded to the specified number of characters. If the new
' capacity is smaller than the current capacity, the buffer is shortened and the contents
' that exceed the new capacity are lost.
' ========================================================================================
PRIVATE PROPERTY DWSTRING.Capacity (BYVAL nValue AS UINT)
   DWSTRING_DP(..WSTR(nValue))
   IF nValue = m_Capacity THEN EXIT PROPERTY
   this.ResizeBuffer(nValue)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Converts the DWSTRING to UTF8.
' ========================================================================================
'PRIVATE PROPERTY DWSTRING.Utf8 () AS STRING
'   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
'   DIM cbLen AS INTEGER
'   IF m_BufferLen = 0 THEN RETURN ""
'   DIM buffer AS STRING = STRING(m_BufferLen * 5 + 1, 0)
'   PROPERTY = *cast(ZSTRING PTR, WCharToUTF(1, m_pBuffer, m_BufferLen * 2, STRPTR(buffer), @cbLen))
'END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY DWSTRING.Utf8 () AS STRING
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
   DIM cbLen AS LONG = WideCharToMultiByte(CP_UTF8, 0, m_pBuffer, -1, NULL, 0, NULL, NULL)
   DIM s AS STRING = STRING(cbLen, 0)
   WideCharToMultiByte(CP_UTF8, 0, m_pBuffer, -1, STRPTR(s), cbLen, NULL, NULL)
   RETURN LEFT(s, cbLen - 1) ' Remove null terminator
END PROPERTY
' ========================================================================================

' ========================================================================================
' Converts UTF8 to unicode and assigns it to the DWSTRING.
' ========================================================================================
PRIVATE PROPERTY DWSTRING.Utf8 (BYREF utf8String AS STRING)
   DWSTRING_DP("")
   this.Clear
   this.Add(utf8String, CP_UTF8)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Converts the DWSTRING to OEM.
' ========================================================================================
PRIVATE PROPERTY DWSTRING.OEM () AS STRING
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
   DIM cbLen AS INTEGER
   IF m_BufferLen = 0 THEN RETURN ""
   DIM buffer AS STRING = STRING(m_BufferLen * 2, 0)
   ' Convert from Unicode to OEM code page
   DIM nConverted AS LONG = WideCharToMultiByte(CP_OEMCP, 0, m_pBuffer, -1, STRPTR(buffer), LEN(buffer), NULL, NULL)
   IF nConverted > 0 THEN
      RETURN LEFT(buffer, nConverted - 1)  ' Remove null terminator
   ELSE
      RETURN *m_pBuffer
   END IF
END PROPERTY
' ========================================================================================

' ========================================================================================
' JScript (PROPERTY)
' ------------------
' Converts the DWSTRING content into a safe JavaScript expression for use with
' WebView2 ExecuteScript.
'
' WebView2 requires UTF-8 text when passing strings to JavaScript. This property
' takes the internal UTF-8 byte sequence of the DWSTRING and generates a JS
' expression of the form:
'
'     new TextDecoder('utf-8').decode(Uint8Array.from([b1,b2,b3,...]))
'
' This guarantees that any Unicode text (including accents, symbols and emojis)
' is transmitted correctly to JavaScript without escaping issues, broken quotes,
' or encoding mismatches.
'
' The user can therefore pass DWSTRING values directly to ExecuteScript without
' worrying about UTF-8 handling or manual escaping.
'
' Usage example:
' m_pWebView->ExecuteScript("console.log(" & myString.JScript & ");")
'
' Notes:
' - The returned value is valid JavaScript code, not a literal string.
' - Ideal for passing arbitrary text safely from FreeBasic to JavaScript.
' ========================================================================================
' ========================================================================================
'PRIVATE PROPERTY DWSTRING.JScript () AS STRING
'   DWSTRING_DP("")
'   DIM utf8Text AS STRING = this.utf8
'   DIM js AS STRING = "new TextDecoder('utf-8').decode(Uint8Array.from(["
'   DIM L AS LONG = LEN(utf8Text)
'   FOR i AS LONG = 1 TO L
'      js += STR(ASC(MID(utf8Text, i, 1)))
'      IF i < L THEN js += ","
'   NEXT
'   js += "]))"
'   RETURN js
'END PROPERTY
' ========================================================================================
PRIVATE PROPERTY DWSTRING.JScript () AS STRING
   DWSTRING_DP("")
   DIM utf8Text AS STRING = this.utf8
   DIM p AS UBYTE PTR = STRPTR(utf8Text)
   DIM js AS STRING = "new TextDecoder('utf-8').decode(Uint8Array.from(["
   DIM L AS LONG = LEN(utf8Text)
   FOR i AS LONG = 0 TO L - 1
      js += STR(p[i])
      IF i < L - 1 THEN js += ","
   NEXT
   js += "]))"
   RETURN js
END PROPERTY
' ========================================================================================

' ========================================================================================
' Converts OEM to unicode and assigns it to the DWSTRING.
' ========================================================================================
PRIVATE PROPERTY DWSTRING.OEM (BYREF OEMString AS STRING)
   DWSTRING_DP("")
   this.Clear
   this.Add(OEMString, CP_OEMCP)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Resizes the internal buffer capacity
' ========================================================================================
PRIVATE FUNCTION DWSTRING.ResizeBuffer (BYVAL nChars AS UINT, BYVAL bClear AS BOOLEAN = FALSE) AS WSTRING PTR
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer) & " - chars: " & ..WSTR(nChars))
   ' // Allocate a buffer of nChars utf16 characters + 1 for the terminating null
   DIM pNewBuffer AS WSTRING PTR = IIF(bClear, CAllocate((nChars + 1) * 2), Allocate((nChars + 1) * 2))
   ' // The user has requested to reduce the capacity.
   ' // The buffer is shortened and the contents that exceed the new capacity are lost.
   IF nChars < m_BufferLen THEN m_BufferLen = nChars
   IF m_pBuffer THEN
      ' // Copy the old buffer in the new one
      wmemmove(pNewBuffer, m_pBuffer, m_BufferLen)
      ' // Deallocate the old buffer
      Deallocate m_pBuffer
   END IF
   ' // Update the capacity
   m_Capacity = nChars
   ' // Store the new pointer
   m_pBuffer = pNewBuffer
   ' // Mark the end of the string with a double null
   m_pBuffer[m_BufferLen] = 0
   DWSTRING_DP("new buffer: " & ..WSTR(m_pBuffer))
   RETURN m_pBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scans a UTF-16 buffer (passed as a pointer to WSTRING) in chunks of 64 
' characters. Returns the 0-based index (relative to memAddr) of the first
' broken surrogate found, or -1 if none is found.
'
' Parameters:
'   memAddr            - pointer to the UTF-16 buffer
'   nChars             - number of UTF-16 code units (USHORTs) to scan
'   searchBrokenOnly   - Optional (default TRUE): if TRUE, only broken surrogates 
'                        are signaled. If FALSE, returns the position of the first 
'                        surrogate (valid or not). 
'
' Note:
'   This version avoids repeated casting by caching memAddr as a USHORT pointer 
'   and uses bitmask comparisons instead of range comparisons.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.ScanForSurrogates ( _
   BYVAL memAddr AS WSTRING PTR, _
   BYVAL nChars AS LONG, _
   BYVAL searchBrokenOnly AS BOOLEAN = TRUE) AS LONG

   DWSTRING_DP("memAddr: " & ..WSTR(memAddr) & " - chars = " & ..WSTR(nChars))
   DIM localPtr AS USHORT PTR = CAST(USHORT PTR, memAddr)
   DIM AS LONG i, chunkSize = 64

   FOR i = 0 TO nChars - 1 STEP chunkSize
      DIM AS LONG endPos = i + chunkSize - 1
      IF endPos >= nChars THEN endPos = nChars - 1
      DIM AS LONG j
      FOR j = i TO endPos
         DIM AS USHORT ch = localPtr[j]
         IF NOT searchBrokenOnly THEN
            ' // Check for any surrogate (high or low)
            IF (ch And &HFC00) = &HD800 OR (ch And &HFC00) = &HDC00 THEN
               RETURN j
            END IF
         ELSE
            ' // Check only for broken surrogates:
            ' // If it's a high surrogate
            IF (ch And &HFC00) = &HD800 THEN
               ' Look ahead if possible
               IF j + 1 < nChars THEN
                  DIM AS USHORT nextCh = localPtr[j + 1]
                  ' // If the following code unit is not a low surrogate,
                  ' // then ch is a broken high surrogate.
                  IF (nextCh And &HFC00) <> &HDC00 THEN
                     RETURN j
                  ELSE
                     ' // Valid surrogate pair; skip the next code unit.
                     j += 1
                     CONTINUE FOR
                  END IF
               ELSE
                  ' // High surrogate is the last element in the block.
                  RETURN j
               END IF
            ' // If it's a low surrogate on its own.
            ELSEIF (ch And &HFC00) = &HDC00 THEN
               RETURN j
            END IF
         END IF
      NEXT
   NEXT

   RETURN -1 ' // No (broken) surrogates found.
END FUNCTION
' ========================================================================================

' ========================================================================================
' Appends the specified number of characters from the specified memory address to the end
' of the buffer. This version uses the pointer-based ScanForSurrogates function to detect
' and fix any broken surrogates in the input before appending.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.AppendBuffer (BYVAL memAddr AS ANY PTR, BYVAL nChars AS UINT) AS BOOLEAN
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer) & " - chars = " & ..WSTR(nChars))
   IF memAddr = NULL OR nChars = 0 THEN RETURN FALSE

   ' // Use the pointer-based scan routine, which returns the 0-based index of a broken surrogate,
   ' // or -1 if the block is clean.
   DIM localPtr AS USHORT PTR = CAST(USHORT PTR, memAddr)
   DIM localLen AS LONG = nChars

   ' -------------------------------------------------------------------------------------------------
   ' Conditionally, check for broken surrogates and fix them
   ' -------------------------------------------------------------------------------------------------
   #if defined(__AFX_CHECKSURROGATES__)
   ' // Get the first broken surrogate index in the new block (relative to localPtr).
   DIM brokenIndex AS LONG = ScanForSurrogates(localPtr, localLen)
   WHILE brokenIndex <> -1
      DIM pCode AS USHORT PTR = localPtr + brokenIndex
      DIM ch AS USHORT = *pCode
      ' // Instead of checking using range comparisons, use bitwise masking.
      IF (ch AND &HFC00) = &HD800 THEN
         ' // High surrogate: check if there is a following low surrogate.
         IF (brokenIndex + 1) < localLen THEN
            DIM nextCh AS USHORT = *(pCode + 1)
            ' // If the next unit is not a low surrogate, it is broken.
            IF (nextCh AND &HFC00) <> &HDC00 THEN
               *pCode = &HFFFD
            END IF
         ELSE
            ' // High surrogate at end of block.
            *pCode = &HFFFD
         END IF
       ELSEIF (ch AND &HFC00) = &HDC00 THEN
         ' // Isolated low surrogate.
         *pCode = &HFFFD
      END IF
      ' // Resume scanning immediately after the found/fixed surrogate.
      DIM newStart AS LONG = brokenIndex + 1
      IF newStart >= localLen THEN EXIT WHILE
      DIM subBroken AS LONG = ScanForSurrogates(localPtr + newStart, localLen - newStart)
      IF subBroken = -1 THEN
         EXIT WHILE
      ELSE
         brokenIndex = newStart + subBroken
      END IF
   WEND
   #endif

   ' -------------------------------------------------------------------------------------------------
   ' Now that the input block is cleared of broken surrogates, proceed to append it to m_pBuffer.
   ' -------------------------------------------------------------------------------------------------

   ' // Number of characters to append
   DIM nSize AS UINT = m_BufferLen + nChars
   ' // If there is not enough capacity, resize the buffer
   IF nSize > m_Capacity THEN this.ResizeBuffer(nSize * 2)
   ' // Copy the passed buffer
   IF m_pBuffer = NULL THEN RETURN FALSE
   wmemmove(m_pBuffer + m_BufferLen, memAddr, nChars)
   ' // Update the length of the buffer
   m_BufferLen += nChars
   ' // Mark the end of the string with a double null
   m_pBuffer[m_BufferLen] = 0
   DWSTRING_DP("new buffer: " & ..WSTR(m_pBuffer))
   RETURN TRUE

END FUNCTION
' ========================================================================================

 ' ========================================================================================
' Returns a pointer to the DWSTRING buffer.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.GetBuffer () AS WSTRING PTR
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
   RETURN m_pBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' All data in the class object is erased. Actually, we only set the buffer length to zero,
' indicating no string in the buffer. The allocated memory for the buffer is deallocated
' when the class is destroyed.
' ========================================================================================
PRIVATE SUB DWSTRING.Clear
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer) & " - len: " & ..WSTR(m_BufferLen))
   m_BufferLen = 0
   m_pBuffer[m_BufferLen] = 0
END SUB
' ========================================================================================

' ========================================================================================
' Detect if the codification is valid utf-8
' ========================================================================================
FUNCTION DWSTRING.IsUtf8 (BYREF s AS STRING) AS BOOLEAN
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
' The string parameter is appended to the string held in the class. If the internal string
' buffer overflows, the class will automatically extend it to an appropriate size.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.Add (BYVAL pwszStr AS WSTRING PTR) AS BOOLEAN
   DWSTRING_DP("WSTRING PTR - buffer: " & ..WSTR(m_pBuffer))
   RETURN this.AppendBuffer(pwszStr, .LEN(*pwszStr))
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION DWSTRING.Add (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0) AS BOOLEAN
   DWSTRING_DP("STRING - buffer: " & ..WSTR(m_pBuffer) & " - codepage: " & ..WSTR(nCodePage))
   IF .LEN(ansiStr) = 0 THEN RETURN FALSE
   ' // Create the wide string from the incoming ansi string
   DIM dwLen AS UINT, pbuffer AS ANY PTR
   DIM bRes AS BOOLEAN = TRUE   ' // assume success for now
   IF nCodePage = CP_UTF8 THEN   ' // check if it is really valid utf-8
      IF this.IsUtf8(ansiStr) = FALSE THEN nCodePage = CP_ACP
   END IF
   IF nCodePage = CP_UTF8 THEN
      dwLen = MultiByteToWideChar(CP_UTF8, 0, STRPTR(ansiStr), .LEN(ansiStr), NULL, 0)
      IF dwLen = 0 THEN RETURN FALSE
      pbuffer = Allocate(dwLen * 2)
      dwLen = MultiByteToWideChar(CP_UTF8, 0, STRPTR(ansiStr), .LEN(ansiStr), pbuffer, dwLen)
      IF dwLen = 0 THEN bRes = FALSE
   ELSE
      dwLen = MultiByteToWideChar(nCodePage, MB_PRECOMPOSED, STRPTR(ansiStr), .LEN(ansiStr), NULL, 0)
      IF dwLen = 0 THEN RETURN FALSE
      pbuffer = Allocate(dwLen * 2)
      dwLen = MultiByteToWideChar(nCodePage, MB_PRECOMPOSED, STRPTR(ansiStr), .LEN(ansiStr), pbuffer, dwLen)
      IF dwLen = 0 THEN bRes = FALSE
   END IF
   IF bRes = FALSE THEN
      IF pBuffer THEN Deallocate(pbuffer)
      RETURN bRes
   END IF
   ' // Copy the string into the buffer
   IF pbuffer THEN
      ' Copy the string into the buffer and update the length
      bRes = this.AppendBuffer(pbuffer, dwLen)
      ' // Deallocate the buffer
      IF pBuffer THEN Deallocate(pbuffer)
   END IF
   RETURN bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION DWSTRING.Add (BYREF dws AS DWSTRING) AS BOOLEAN
   DWSTRING_DP("DWSTRING")
   RETURN this.AppendBuffer(dws.m_pBuffer, dws.m_BufferLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Appends a string to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.+= (BYVAL pwszStr AS WSTRING PTR)
   DWSTRING_DP("WSTRING PTR")
   this.Add(pwszStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a string to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.+= (BYREF ansiStr AS STRING)
   DWSTRING_DP("STRING")
   this.Add(ansiStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a DWSTRING to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.+= (BYREF dws AS DWSTRING)
   DWSTRING_DP("DWSTRING")
   this.Add(dws)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a BSTRING to the BSTRING.
' ========================================================================================
PRIVATE OPERATOR DWSTRING.+= (BYREF bs AS BSTRING)
   DWSTRING_DP("BSTRING")
   this.Add(bs)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.+= (BYVAL n AS LONGINT)
   DWSTRING_DP("LONGINT")
   DIM wsz AS WSTRING * 260 = .WSTR(n)
   this.Add(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.+= (BYVAL n AS DOUBLE)
   DWSTRING_DP("DOUBLE")
   DIM wsz AS WSTRING * 260 = .WSTR(n)
   this.Add(wsz)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Appends a WSTRING to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.&= (BYREF wszStr AS WSTRING)
   DWSTRING_DP("WSTRING")
   this.Add(wszStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a string to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.&= (BYREF ansiStr AS STRING)
   DWSTRING_DP("STRING")
   this.Add(ansiStr)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a DWSTRING to the DWSTRING
' ========================================================================================
PRIVATE OPERATOR DWSTRING.&= (BYREF dws AS DWSTRING)
   DWSTRING_DP("DWSTRING")
   this.Add(dws)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Appends a BSTRING to the DWSTRING.
' ========================================================================================
PRIVATE OPERATOR DWSTRING.&= (BYREF bs AS BSTRING)
   DWSTRING_DP("BSTRING")
   this.Add(bs)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.&= (BYVAL n AS LONGINT)
   DWSTRING_DP("LONGINT - value: " & ..WSTR(n))
   DIM wsz AS WSTRING * 260 = ..WSTR(n)
   this.Add(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR DWSTRING.&= (BYVAL n AS DOUBLE)
   DWSTRING_DP("DOUBLE - value: " & ..WSTR(n))
   DIM wsz AS WSTRING * 260 = ..WSTR(n)
   this.Add(wsz)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the DWSTRING buffer.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.vptr () AS WSTRING PTR
   DWSTRING_DP("vptr - buffer: " & ..WSTR(m_pBuffer))
   RETURN cast(WSTRING PTR, m_pBuffer)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the address of the DWSTRING buffer.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.sptr () AS WSTRING PTR
   DWSTRING_DP("sptr - buffer: " & ..WSTR(m_pBuffer))
   RETURN cast(WSTRING PTR, m_pBuffer)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a copy of the contents of the DWSTRING AS a BSTR.
' The returned handle must be freed with SysFreeString to avoid memory leaks.
' ========================================================================================
PRIVATE FUNCTION DWSTRING.bstr () AS ..BSTR
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
   RETURN SysAllocString(m_pBuffer)
END FUNCTION
' ========================================================================================

' =====================================================================================
' Returns a copy of the contents of the DWSTRING as a WSTRING allocated with CoTaskMemAlloc.
' Free the returned string later with CoTaskMemFree.
' Note: This is useful when we need to pass a pointer to a null terminated wide string to a
' function or method that will release it. If we pass a WSTRING it will GPF.
' If the length of the input string is 0, CoTaskMemAlloc allocates a zero-length item and
' returns a valid pointer to that item. If there is insufficient memory available,
' CoTaskMemAlloc returns NULL.
' =====================================================================================
PRIVATE FUNCTION DWSTRING.wchar () AS WSTRING PTR
   DIM pwchar AS WSTRING PTR
   DIM nLen AS LONG = m_BufferLen * 2
   pwchar = CoTaskMemAlloc(nLen)
   IF pwchar = NULL THEN RETURN NULL
   IF nLen THEN memcpy pwchar, m_pBuffer, nLen
   IF nLen = 0 THEN *pwchar = CHR(0)
   DWSTRING_DP("buffer: " & ..WSTR(m_pBuffer))
   RETURN pwchar
END FUNCTION
' =====================================================================================

' =====================================================================================
' Returns a wide-character string from a codepoint. Returns a wide-character string from
' a codepoint. If the codepoint is higher than 65535, the value returned is the sum of
' a surrogate pair.
' =====================================================================================
PRIVATE FUNCTION DWSTRING.ChrW (BYVAL codepoint AS UInteger) AS DWSTRING
   DWSTRING_DP("codepoint " & ..WSTR(codepoint))
   If codepoint <= &HFFFF Then RETURN WCHR(codepoint)
   ' Convert to UTF-16 surrogate pair for higher codepoints
   DIM AS USHORT highSurrogate = &HD800 OR ((codepoint - &H10000) SHR 10)
   DIM AS USHORT lowSurrogate = &HDC00 OR ((codepoint - &H10000) AND &H3FF)
   RETURN WCHR(highSurrogate) + WCHR(lowSurrogate)
END FUNCTION
' =====================================================================================

END NAMESPACE

' ########################################################################################
'                         *** GLOBAL OPERATORS AND FUNCTIONS ***
' ########################################################################################

' // Outside a namespace because they are global
USING AfxNova

' ========================================================================================
' Global operator.
' Returns the length, in characters, of the DWSTRING.
' ========================================================================================
PRIVATE OPERATOR LEN OVERLOAD (BYREF dws AS DWSTRING) AS UINT
   OPERATOR = dws.m_BufferLen
END OPERATOR
' ========================================================================================

' ========================================================================================
' Global operator.
' One * returns the address of the start of the string data.
' Two ** deferences de string data.
' ========================================================================================
PRIVATE OPERATOR * (BYREF dws AS DWSTRING) AS WSTRING PTR
   OPERATOR = dws.m_pBuffer
END OPERATOR
' ========================================================================================

' ========================================================================================
' Concatenates two strings.
' Overloaded because the it fails without ambigous call when we use a combination
' of different data types and literals.
' The operator + doesn't have problems with this.
' ========================================================================================
PRIVATE OPERATOR & (BYREF dws1 AS DWSTRING, BYREF dws2 AS DWSTRING) AS DWSTRING
   DWSTRING_DP("DWSTRING+DWSTRING")
   OPERATOR = dws1 + dws2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Already defined in BSTRING.inc
' ========================================================================================
'PRIVATE OPERATOR & (BYREF dws AS DWSTRING, BYREF bs AS BSTRING) AS DWSTRING
'   DWSTRING_DP("DWSTRING OPERATOR & - DWSTRING+BSTRING")
'   OPERATOR = dws + bs
'END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR & (BYREF dws AS DWSTRING, BYREF s AS STRING) AS DWSTRING
   DWSTRING_DP("DWSTRING+STRING")
   OPERATOR = dws + s
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR & (BYREF s AS STRING, BYREF dws AS DWSTRING) AS DWSTRING
   DWSTRING_DP("STRING+DWSTRING")
   OPERATOR = s + dws
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns the leftmost substring of a string
' Overloaded because the intrinsic LEFT operator fails with an ambiguous call error.
' ========================================================================================
PRIVATE FUNCTION Left OVERLOAD (BYREF dws AS DWSTRING, BYVAL nChars AS INTEGER) AS DWSTRING
   RETURN .LEFT(**dws, nChars)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the rightmost substring of a string
' Overloaded because the intrinsic LEFT operator fails with an ambiguous call error.
' ========================================================================================
PRIVATE FUNCTION Right OVERLOAD (BYREF dws AS DWSTRING, BYVAL nChars AS INTEGER) AS DWSTRING
   RETURN .RIGHT(**dws, nChars)
END FUNCTION
' ========================================================================================