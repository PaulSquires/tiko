' ########################################################################################
' Platform: Microsoft Windows
' Filename: DWSTRProcs.inc
' Purpose:  Unicode string procedures
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
#include once "windows.bi"
#include once "win/shlwapi.bi"
#include once "AfxNova/CRegExp.inc"
#include once "AfxNova/AfxArrays.inc"
#include once "AfxNova/AfxSort.inc"
#include once "AfxNova/AfxWin.inc"
USING AfxNova

' ========================================================================================
' Note: additionally, we can call external variadic functions written in C, e.g.
'    DIM wszOut AS WSTRING * 260
'    DIM wszFmt AS WSTRING * 260 = "%s %d + %d = %d."
'    DIM wszText AS WSTRING * 260 = "The answer is"
'    DIM hr AS HRESULT = StringCbPrintfW(@wszOut, SIZEOF(wszOut), @wszFmt, @wszText, 1, 2, 3)
'    print wszOut
' Output: "The answer is 1 + 2 = 3."
' StringCbPrintf function:
' https://msdn.microsoft.com/en-us/library/windows/desktop/ms647510(v=vs.85).aspx
' StringCbPrintf_l (A/W) is similar to StringCbPrintf but includes a parameter for locale
' information.
' StringCbPrintfEx (A/W) adds to the functionality of StringCbPrintf by returning a pointer
' to the end of the destination string as well as the number of bytes left unused in that
' string. Flags may also be passed to the function for additional control.
' StringCbPrintf_lEx (A/W) is similar to StringCbPrintfEx but includes a parameter for
' locale information.
' They can be very useful to do string formatting.
' ========================================================================================

NAMESPACE AfxNova

#if _WIN32_WINNT = &h0602
' ========================================================================================
' * Returns an uppercased version of a string.
' - pwszStr [in]:
'      The string to convert. Cannot have a size of 0.
' - pwszLocaleName [in, optional]:
'      Pointer to a locale name or one of these pre-defined values:
'         LOCALE_NAME_INVARIANT
'         LOCALE_NAME_SYSTEM_DEFAULT
'         LOCALE_NAME_USER_DEFAULT
'      For a table of language culture names see:
'         https://msdn.microsoft.com/es-es/library/ee825488(v=cs.20).aspx
' - dwMapFlags [in, optional]:
'      Flag specifying the type of transformation to use during string mapping or the type
'      of sort key to generate. This parameter can have the following values
'      For a complete list see:
'      https://msdn.microsoft.com/en-us/library/windows/desktop/dd318702(v=vs.85).aspx
' Return value:
'   The uppercased string.
' ========================================================================================
PRIVATE FUNCTION DWStrUCase (BYVAL pwszStr AS WSTRING PTR, _
   BYVAL pwszLocaleName AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT, _
   BYVAL dwMapFlags AS DWORD = 0) AS DWSTRING

   ' // Check the validity of the passed parameters
   IF pwszStr = NULL THEN RETURN ""
   IF LEN(*pwszStr) = 0 THEN RETURN ""
   DIM dwsOut AS DWSTRING = *pwszStr
   ' // Make sure that LCMAP_LOWERCASE is not being used
   dwMapFlags = dwMapFlags AND (NOT LCMAP_LOWERCASE)
   ' // Make sure that LCMAP_LINGUISTIC_CASING OR LCMAP_UPPERCASE is being used
   dwMapFlags OR= LCMAP_LINGUISTIC_CASING OR LCMAP_UPPERCASE
   ' // Usually, the length of the converted string will be the same that the one of
   ' // the input string, so let's try it
   DIM cbLen AS LONG = LCMapStringEx(pwszLocaleName, dwMapFlags, pwszStr, LEN(*pwszStr), _
       dwsOut, LEN(dwsOut), NULL, NULL, 0)
   ' // If the output length is bigger than the input one, request the needed length,
   ' // make the buffer bigger and try it again
   IF cbLen = 0 AND GetLastError = ERROR_INSUFFICIENT_BUFFER THEN
      cbLen = LCMapStringEx(pwszLocaleName, dwMapFlags, pwszStr, LEN(*pwszStr), NULL, 0, NULL, NULL, 0)
      IF cbLen THEN
         dwsOut += WSPACE(cbLen)
         cbLen = LCMapStringEx(pwszLocaleName, dwMapFlags, pwszStr, LEN(*pwszStr), _
                 dwsOut, LEN(dwsOut), NULL, NULL, 0)
      END IF
   END IF
   RETURN dwsOut

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a lowercased version of a string.
' - pwszStr [in]:
'      The string to convert. Cannot have a size of 0.
' - pwszLocaleName [in, optional]:
'      Pointer to a locale name or one of these pre-defined values:
'         LOCALE_NAME_INVARIANT
'         LOCALE_NAME_SYSTEM_DEFAULT
'         LOCALE_NAME_USER_DEFAULT
'      For a table of language culture names see:
'         https://msdn.microsoft.com/es-es/library/ee825488(v=cs.20).aspx
' - dwMapFlags [in, optional]:
'      Flag specifying the type of transformation to use during string mapping or the type
'      of sort key to generate. This parameter can have the following values
'      For a complete list see:
'      https://msdn.microsoft.com/en-us/library/windows/desktop/dd318702(v=vs.85).aspx
' Return value:
'   The lowercased string.
' ========================================================================================
PRIVATE FUNCTION DWStrLCase (BYVAL pwszStr AS WSTRING PTR, _
   BYVAL pwszLocaleName AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT, _
   BYVAL dwMapFlags AS DWORD = 0) AS DWSTRING

   ' // Check the vailidy of the passed parameters
   IF pwszStr = NULL THEN RETURN ""
   IF LEN(*pwszStr) = 0 THEN RETURN ""
   DIM dwsOut AS DWSTRING = *pwszStr
   ' // Make sure that LCMAP_UPPERCASE is not being used
   dwMapFlags = dwMapFlags AND (NOT LCMAP_UPPERCASE)
   ' // Make sure that LCMAP_LINGUISTIC_CASING OR LCMAP_LOWERCASE is being used
   dwMapFlags OR= LCMAP_LINGUISTIC_CASING OR LCMAP_LOWERCASE
   ' // Usually, the length of the converted string will be the same that the one of
   ' // the input string, so let's try it
   DIM cbLen AS LONG = LCMapStringEx(pwszLocaleName, dwMapFlags, pwszStr, LEN(*pwszStr), _
       dwsOut, LEN(dwsOut), NULL, NULL, 0)
   ' // If the output length is bigger than the input one, request the needed length,
   ' // make the buffer bigger and try it again
   IF cbLen = 0 AND GetLastError = ERROR_INSUFFICIENT_BUFFER THEN
      cbLen = LCMapStringEx(pwszLocaleName, dwMapFlags, pwszStr, LEN(*pwszStr), NULL, 0, NULL, NULL, 0)
      IF cbLen THEN
         dwsOut += WSPACE(cbLen)
         cbLen = LCMapStringEx(pwszLocaleName, dwMapFlags, pwszStr, LEN(*pwszStr), _
                 dwsOut, LEN(dwsOut), NULL, NULL, 0)
      END IF
   END IF
   RETURN dwsOut

END FUNCTION
' ========================================================================================
#endif

' ========================================================================================
' * Translates ansi bytes to Unicode chars.
' Parameters:
' - ansiStr = An ansi or UTF8 string.
' - nCodePage = The code page used in the conversion, e.g. 1251 for Russian.
'   If you specify CP_UTF8, it is assumed that ansiStr contains an UTF8 encoded string.
'   If you don't pass an Unicode page, the function will use CP_ACP (0), which is the
'   system default Windows ANSI code page.
' Return value:
'   The converted string as a DWSTRING.
' ========================================================================================
PRIVATE FUNCTION DWStrUcode (BYREF ansiStr AS CONST STRING, BYVAL nCodePage AS LONG = 0) AS DWSTRING
   IF nCodePage = CP_UTF8 THEN
      DIM dwLen AS DWORD = MultiByteToWideChar(CP_UTF8, 0, STRPTR(ansiStr), LEN(ansiStr), NULL, 0)
      IF dwLen THEN
         DIM dws AS DWSTRING = WSPACE(dwLen)
         dwLen = MultiByteToWideChar(CP_UTF8, 0, STRPTR(ansiStr), LEN(ansiStr), dws, dwLen * 2)
         IF dwLen THEN RETURN dws
      END IF
   ELSE
      DIM dws AS DWSTRING = WSPACE(LEN(ansiStr))
      DIM dwLen AS DWORD = MultiByteToWideChar(nCodePage, MB_PRECOMPOSED, STRPTR(ansiStr), LEN(ansiStr), dws, LEN(ansiStr) * 2)
      IF dwLen THEN RETURN dws
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Translates Unicode chars to ansi bytes.
' Parameters:
' - pwszStr = The Unicode string to convert
' - nCodePage = The code page used in the conversion, e.g. 1251 for Russian.
'   If you don't pass an Unicode page, the function will use CP_ACP (0), which is the
'   system default Windows ANSI code page.
' Return value:
'   The converted string.
' ========================================================================================
PRIVATE FUNCTION DWStrAcode (BYVAL pwszStr AS WSTRING PTR, BYVAL nCodePage AS LONG = 0) AS STRING
   IF pwszStr = NULL THEN EXIT FUNCTION
   IF nCodePage = CP_UTF8 THEN
      DIM dwLen AS DWORD = WideCharToMultiByte(CP_UTF8, 0, pwszStr, LEN(*pwszStr), NULL, 0, NULL, NULL)
      IF dwLen THEN
         DIM ansiStr AS STRING = SPACE(dwLen)
         dwLen = WideCharToMultiByte(CP_UTF8, 0, pwszStr, LEN(*pwszStr), STRPTR(ansiStr), LEN(ansiStr), NULL, NULL)
         IF dwLen THEN RETURN ansiStr
      END IF
   ELSE
      DIM ansiStr AS STRING = SPACE(LEN(*pwszStr))
      DIM dwLen AS DWORD = WideCharToMultiByte(nCodePage, 0, pwszStr, LEN(*pwszStr), STRPTR(ansiStr), LEN(ansiStr), NULL, NULL)
      IF dwLen THEN RETURN ansiStr
   ENDIF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts Unicode to utf8.
' Parameters:
' - pwszStr = The Unicode string to convert
' Return value:
'   The converted Unicode string as a utf8 string.
' ========================================================================================
PRIVATE FUNCTION DWStrToUtf8 (BYVAL pwszStr AS WSTRING PTR) AS STRING
   IF pwszStr = NULL THEN EXIT FUNCTION
   DIM dwLen AS DWORD = WideCharToMultiByte(CP_UTF8, 0, pwszStr, LEN(*pwszStr), NULL, 0, NULL, NULL)
   IF dwLen THEN
      DIM utf8Str AS STRING = SPACE(dwLen)
      dwLen = WideCharToMultiByte(CP_UTF8, 0, pwszStr, LEN(*pwszStr), STRPTR(utf8Str), LEN(utf8Str), NULL, NULL)
      IF dwLen THEN RETURN utf8Str
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts utf8 to Unicode.
' Parameters:
' - utf8Str = An UTF8 string.
' Return value:
'   The converted utf8 string as a DWSTRING.
' ========================================================================================
PRIVATE FUNCTION Utf8ToDwstr (BYREF utf8Str AS CONST STRING) AS DWSTRING
   DIM dwLen AS DWORD = MultiByteToWideChar(CP_UTF8, 0, STRPTR(utf8Str), LEN(utf8Str), NULL, 0)
   IF dwLen THEN
      DIM dws AS DWSTRING = WSPACE(dwLen)
      dwLen = MultiByteToWideChar(CP_UTF8, 0, STRPTR(utf8Str), LEN(utf8Str), dws, dwLen * 2)
      IF dwLen THEN RETURN dws
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Transltes Unicode to OEM byte characters.
' Parameters:
' - pwszStr = The Unicode string to convert
' Return value:
'   The converted Unicode string as an OEM string.
' ========================================================================================
PRIVATE FUNCTION DWStrToOem (BYVAL pwszStr AS WSTRING PTR) AS STRING
   IF pwszStr = NULL THEN EXIT FUNCTION
   DIM dwLen AS DWORD = WideCharToMultiByte(CP_OEMCP, 0, pwszStr, LEN(*pwszStr), NULL, 0, NULL, NULL)
   IF dwLen THEN
      DIM oemStr AS STRING = SPACE(dwLen)
      dwLen = WideCharToMultiByte(CP_OEMCP, 0, pwszStr, LEN(*pwszStr), STRPTR(oemStr), LEN(oemStr), NULL, NULL)
      IF dwLen THEN RETURN oemStr
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Traslates a byte string of OEM characters to Unicode.
' Parameters:
' - oemStr = An OEM string.
' Return value:
'   The converted OEM string as a DWSTRING.
' ========================================================================================
PRIVATE FUNCTION OemToDwstr (BYREF oemStr AS CONST STRING) AS DWSTRING
   DIM dwLen AS DWORD = MultiByteToWideChar(CP_OEMCP, 0, STRPTR(oemStr), LEN(oemStr), NULL, 0)
   IF dwLen THEN
      DIM dws AS DWSTRING = WSPACE(dwLen)
      dwLen = MultiByteToWideChar(CP_OEMCP, 0, STRPTR(oemStr), LEN(oemStr), dws, dwLen * 2)
      IF dwLen THEN RETURN dws
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Escapes any potential regex syntax characters in a string and returns a new string
' that can be safely used as a literal pattern.
' ========================================================================================
PRIVATE FUNCTION DWStrEscape (BYREF wszStr AS CONST WSTRING) AS DWSTRING
   IF INSTR(wszStr, ANY "\.^$*+?{}[]()|") = 0 THEN RETURN wszStr
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = TRUE
   pRegExp.Pattern = $"([\\.\^\$\*\+\?\{\}\[\]\(\)\|])"
   RETURN pRegExp.Replace(wszStr, $"\$1")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces all occurrences of wszMatchString in wszSourceString with wszReplaceString
' The replacement can cause wszMainStr to grow or condense in size.
' Example: DWStrReplace("Hello World", "World", "Earth")   ' Output: "Hello Earth"
' Example: DWStrReplace("abacadabra", "bac", "***")        ' Output: "a***adabra"
' Example: DWStrReplace("abacadabra", "[bac]", "*")        ' Output: "*****d**r*"
' ========================================================================================
PRIVATE FUNCTION DWStrReplace (BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, _
   BYREF wszReplaceString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN ""
   IF wszMatchString = "" THEN RETURN wszSourceString
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(wszMatchString)
   END IF
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   pRegExp.Pattern = dwsMatchString
   RETURN pRegExp.Replace(wszSourceString, wszReplaceString)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a copy of a string with substrings removed.
' Example: DWStrRemove("Hello World. Welcome to the Freebasic World", "World")   'Output: "Hello . Welcome to the Freebasic"
' Example: DWStrRemove("abacadabra", "bac")        ' Output: "aaabra"
' Example: DWStrRemove("abacadabra", "[bac]")      ' Output: "dr"
' ========================================================================================
PRIVATE FUNCTION DWStrRemove OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN ""
   IF wszMatchString = "" THEN RETURN wszSourceString
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(wszMatchString)
   END IF
   pRegExp.Pattern = dwsMatchString
   RETURN pRegExp.Remove(wszSourceString)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a copy of a string with substrings removed.
' nStart: The starting position.
' ========================================================================================
PRIVATE FUNCTION DWStrRemove OVERLOAD (BYVAL nStart AS LONG, BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN ""
   IF wszMatchString = "" THEN RETURN wszSourceString
   DIM nLen AS LONG = LEN(wszSourceString)
   IF (nStart = 0) OR (nStart > nLen) THEN RETURN ""
   IF nStart < 0 THEN nStart = nLen + nStart + 1
   ' // Make a copy of wszSourceString from nStart to the end
   DIM dwsSourceString AS DWSTRING = MID(wszSourceString, nStart)
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(wszMatchString)
   END IF
   pRegExp.Pattern = dwsMatchString
   RETURN pRegExp.Remove(dwsSourceString)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a copy of a string with a substring enclosed between the specified delimiters removed.
' Parameters:
'    wszSourceString The main string
'    leftDelimiter The first delimiter
'    rightDelimiter The second delimiter
' Example:
'    DIM dwsText AS DWSTRING = "blah blah (text between parentheses) blah blah"
'    print DWStrRemove(dwsText, "(", ")")   ' Returns "blah blah  blah blah"
' Example:
'    DIM dwsText AS DWSTRING = "As Long var1(34), var2(  73 ), var3(any)"
'    print DWStrRemove(dwsText, "(", ")", TRUE)   ' Returns "As Long var1, var2, var3"
' ========================================================================================
PRIVATE FUNCTION DWStrRemove OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF leftDelimiter AS CONST WSTRING, BYREF rightDelimiter AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN ""
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   ' Escape special characters
   DIM AS DWSTRING dwsLeftDelimiter, dwsRightDelimiter
   dwsLeftDelimiter = DWStrEscape(leftDelimiter)
   dwsRightDelimiter = DWStrEscape(rightDelimiter)
   pRegExp.Pattern = dwsLeftDelimiter & ".+?" & dwsRightDelimiter
   RETURN pRegExp.Replace(wszSourceString, "")
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a copy of a string with a substring enclosed between the specified delimiters removed.
' Parameters:
'    wszSourceString The main string
'    leftDelimiter The first delimiter
'    rightDelimiter The second delimiter
' Example:
'    DIM dwsText AS DWSTRING = "blah blah (text between parentheses) blah blah"
'    print DWStrRemove(10, dwsText, "(", ")")   ' Returns "blah blah  blah blah"
' Example:
'    DIM dwsText AS DWSTRING = "As Long var1(34), var2(  73 ), var3(any)"
'    print DWStrRemove(dwsText, "(", ")", TRUE)   ' Returns "As Long var1, var2, var3"
' ========================================================================================
PRIVATE FUNCTION DWStrRemove OVERLOAD (BYVAL nStart AS LONG, BYREF wszSourceString AS CONST WSTRING, BYREF leftDelimiter AS CONST WSTRING, BYREF rightDelimiter AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN ""
   DIM nLen AS LONG = LEN(wszSourceString)
   IF (nStart = 0) OR (nStart > nLen) THEN RETURN ""
   IF nStart < 0 THEN nStart = nLen + nStart + 1
   ' // Make a copy of wszSourceString from nStart to the end
   DIM dwsSourceString AS DWSTRING = MID(wszSourceString, nStart)
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   ' Escape special characters
   DIM AS DWSTRING dwsLeftDelimiter, dwsRightDelimiter
   dwsLeftDelimiter = DWStrEscape(leftDelimiter)
   dwsRightDelimiter = DWStrEscape(rightDelimiter)
   pRegExp.Pattern = dwsLeftDelimiter & ".+?" & dwsRightDelimiter
   RETURN pRegExp.Replace(dwsSourceString, "")
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Extracts characters from a string up to a character or group of characters.
' Returns a substring of wszSourceString starting with its first character and up to
' (but not including) the first occurrence of wszMatchString.
' Example:
'    DIM dws AS DWSTRING = "abacadabra"
'    Print DWStrExtract(dws, "cad")
'    Output: aba - match on "cad"
' wszMatchStr can specify a list of single characters, enclosed between [], to be searched for
' individually, a match on any one of which will cause the extract operation to be performed
' up to that character.
' Example:
'    DIM dws AS DWSTRING = "abacadabra"
'    Print DWStrExtract(dws, "[dr]")
'    Output: abaca - match on "d"
' ========================================================================================
PRIVATE FUNCTION DWStrExtract OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" OR wszMatchString ="" THEN RETURN wszSourceString
   DIM pRegExp AS CRegExp
   pRegExp.Global = FALSE
   pRegExp.IgnoreCase = IgnoreCase
   ' // This pattern matches the delimiter passed (can consist of a group of one or more characters)
   ' // Passing wszMatchString enclosed between "[]" will match any of the individual characters
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(wszMatchString)
   END IF
   pRegExp.Pattern = "^(.*?)" & dwsMatchString
   pRegExp.Execute(wszSourceString)
   IF pRegExp.SubMatchesCount THEN
      RETURN STRPTR(pRegExp.SubMatchValue(0, 0))
   END IF
   ' // If wszMatchString is not found return all of wszSourceString
   RETURN wszSourceString
END FUNCTION
' ========================================================================================

' ========================================================================================
' * nStart is the optional starting position to begin extracting. If nStart is not specified,
' it will start at position 1. If start is zero, or beyond the length of wszSourceString,
' a nul string is returned.  If start is negative, the starting position is counted from
' right to left: if -1, the search begins at the last character; if -2, the second to last,
' and so forth.
' Example:
'    DIM dws AS DWSTRING = "abracadabra"
'    Print DWStrExtract(5, dws, "dab")   ' Output: "ca" - match on "dab"
' Example:
'    DIM dws AS DWSTRING = "abracadabra"
'    Print DWStrExtract(-7, dws, "dab")   ' Output: "ca" - match on "dab"
' Example: 
'    DIM dws AS DWSTRING = "abracadabra"
'    Print DWStrExtract(-7, dws, "[fr]")   ' Output: "cadab" - match on "r"
' If wszMatchString is not present in wszSourceString (or is null) then all of wszSourceString
' is returned from the nStart position. If nStart is 0 or greater than the length of
' wszSourceString, an empty string is returned.
' ========================================================================================
PRIVATE FUNCTION DWStrExtract OVERLOAD (BYVAL nStart AS LONG, BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN wszSourceString
   IF wszMatchString = "" THEN RETURN wszSourceString
   DIM nLen AS LONG = LEN(wszSourceString)
   IF (nStart = 0) OR (nStart > nLen) THEN RETURN ""
   IF nStart < 0 THEN nStart = nLen + nStart + 1
   ' // Make a copy of wszSourceString from nStart to the end
   DIM dwsSourceString AS DWSTRING = MID(wszSourceString, nStart)
   ' // Do the search
   DIM pRegExp AS CRegExp
   pRegExp.Global = FALSE
   pRegExp.IgnoreCase = IgnoreCase
   ' // This pattern matches the delimiter passed (can consist of a group of one or more characters)
   ' // Passing wszMatchString enclosed between "[]" will match any of the individual characters
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWstrEscape(dwsMatchString)
   END IF
   pRegExp.Pattern = "^(.*?)" & dwsMatchString
   pRegExp.Execute(dwsSourceString)
   IF pRegExp.SubMatchesCount THEN
      RETURN STRPTR(pRegExp.SubMatchValue(0, 0))
   END IF
   ' // If wszMatchString is not found return all of dwsSourceString
   RETURN dwsSourceString
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the portion of a string following the occurrence of a specified delimiter up to
' the second delimiter. If no match is found, an empty string is returned.
' Example:
'    DIM dwsText AS DWSTRING = "blah blah text between parentheses) blah blah"
'    PRINT DWStrExtract(dwsText, "(", ")")
' ========================================================================================
PRIVATE FUNCTION DWStrExtract OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF leftDelimiter AS CONST WSTRING, BYREF rightDelimiter AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN wszSourceString
   IF leftDelimiter = "" OR rightDelimiter = "" THEN RETURN ""
   DIM pRegExp AS CRegExp
   pRegExp.Global = FALSE
   pRegExp.IgnoreCase = IgnoreCase
   ' Escape special characters
   DIM AS DWSTRING dwsLeftDelimiter, dwsRightDelimiter
   dwsLeftDelimiter = DWStrEscape(leftDelimiter)
   dwsRightDelimiter = DWStrEscape(rightDelimiter)
   pRegExp.Pattern = dwsLeftDelimiter & "(.*?)" & dwsRightDelimiter
   pRegExp.Execute(wszSourceString)
   IF pRegExp.SubMatchesCount THEN
      RETURN pRegExp.SubMatchValue(0, 0)
   END IF
   ' // If no match is found, return an empty string
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the portion of a string following the occurrence of a specified delimiter up to
' the second delimiter. If no match is found, an empty string is returned. If nStart is 0
' or greater than the length of wszSourceString, an empty string is returned.
' Example:
'    DIM dwsText AS DWSTRING = "blah blah text between parentheses) blah blah"
'    PRINT DWStrExtract(dwsText, "(", ")")
' ========================================================================================
PRIVATE FUNCTION DWStrExtract OVERLOAD (BYVAL nStart AS LONG, BYREF wszSourceString AS CONST WSTRING, BYREF leftDelimiter AS CONST WSTRING, BYREF rightDelimiter AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   IF wszSourceString = "" THEN RETURN wszSourceString
   IF leftDelimiter = "" OR rightDelimiter = "" THEN RETURN ""
   DIM nLen AS LONG = LEN(wszSourceString)
   IF (nStart = 0) OR (nStart > nLen) THEN RETURN ""
   IF nStart < 0 THEN nStart = nLen + nStart + 1
   DIM dwsSourceString AS DWSTRING = MID(wszSourceString, nStart)
   DIM pRegExp AS CRegExp
   pRegExp.Global = FALSE
   pRegExp.IgnoreCase = IgnoreCase
   DIM dwsLeftDelimiter AS DWSTRING
   DIM dwsRightDelimiter AS DWSTRING
   ' Escape special characters
   dwsLeftDelimiter = DWStrEscape(leftDelimiter)
   dwsRightDelimiter = DWStrEscape(rightDelimiter)
   pRegExp.Pattern = dwsLeftDelimiter & "(.*?)" & dwsRightDelimiter
   pRegExp.Execute(dwsSourceString)
   IF pRegExp.SubMatchesCount THEN
      RETURN pRegExp.SubMatchValue(0, 0)
   END IF
   ' // If no match is found, return an empty string
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string containing only the characters contained in a specified match string.
' If wszMatchString is an empty string, strRetain returns an empty string.
' ========================================================================================
' Usage examples:
 ' DIM dws AS DWSTRING = "abacadabra"
 ' dws = DWStrRetain(dws, "B", TRUE)
 ' print dws
' Output: "bb"
' ----------------------------------------------------------------------------------------
' DIM dws AS DWSTRING = "<p>1234567890<ak;lk;l>1234567890</p>"
' dws = DWStrRetain(dws, "<;/p>", TRUE)
' print dws
' Output: "<p><;;></p>"
' ----------------------------------------------------------------------------------------
' DIM dws AS DWSTRING = "<p>1234567890<ak;lk;l>1234567890</p>"
' dws = DWStrRetain(dws, "0123456789", TRUE)
' print dws
' Output: "12345678901234567890"
' ========================================================================================
PRIVATE FUNCTION DWStrRetain OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(dwsMatchString)
   END IF
   pRegExp.Pattern = "[^" & dwsMatchString & "]"
   RETURN STRPTR(pRegExp.Remove(wszSourceString))
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the portion of a string following the first occurrence of a character or group of characters.
' If wszMatchString is not present in wszMainStr (or is null) then a zero-length empty string is returned.
' Example:
' DIM dws AS DWSTRING = "I think, therefore I am"
' dws = DWStrRemain(dws, ",", TRUE)
' print dws
' Output: " therefore I am"
' ========================================================================================
PRIVATE FUNCTION DWStrRemain OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   DIM pRegExp AS CRegExp
   pRegExp.Global = FALSE
   pRegExp.IgnoreCase = IgnoreCase
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(dwsMatchString)
   END IF
   pRegExp.Pattern = dwsMatchString & "(.*)"
   IF pRegExp.Execute(wszSourceString) THEN
      IF pRegExp.SubMatchesCount THEN
         RETURN STRPTR(pRegExp.SubMatchValue(0, 0))
      END IF
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the portion of a string following the first occurrence of a character or group of characters.
' If wszMatchString is not present in wszMainStr (or is null) then a zero-length empty string is returned.
' * nStart : Starting position to begin the search. If nStart is not specified, the search
' will begin at position 1. If nStart is zero, a nul string is returned. If nStart is
' negative, the starting position is counted from right to left: -1 for the last character,
' -2 for the second to last, etc.
' Example:
' DIM dws AS DWSTRING = "I think, therefore I am"
' dws = DWStrRemain(5, dws, ",", TRUE)
' print dws
' Output: " therefore I am"
' ========================================================================================
PRIVATE FUNCTION DWStrRemain OVERLOAD (BYVAL nStart AS LONG, BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS DWSTRING
   DIM pRegExp AS CRegExp
   pRegExp.Global = FALSE
   pRegExp.IgnoreCase = IgnoreCase
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(dwsMatchString)
   END IF
   pRegExp.Pattern = dwsMatchString & "(.*)"
   DIM bsSrc AS BSTRING
   IF nStart < 0 THEN nStart = LEN(wszSourceString) + nStart + 1
   IF nStart < 0 OR nStart > LEN(wszSourceString) THEN RETURN ""
   bsSrc = MID(wszSourceString, nStart)
   IF pRegExp.Execute(bsSrc) THEN
      IF pRegExp.SubMatchesCount THEN
         RETURN pRegExp.SubMatchValue(0, 0)
      END IF
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Count the number of occurrences of a string or a list of characters within a string.
' Usage:
'    DIM dws AS DWSTRING = "abacadabra"
'    DIM nCount AS LONG = DWStrTally(dws, "bac")
'    PRINT nCount
' Output: Returns 1, counting the string "bac"
' ----------------------------------------------------------------------------------------
'    DIM dws AS DWSTRING = "abacadabra"
'    DIM nCount AS LONG = DWStrTally(dws, "b|a|c")   ' // [bac] is the same that [b|a|c]
'    PRINT nCount
' Output: Returns 8, counting all "b", "a", and "c" characters.
' The | is the OR operator in regular expressions. It means "match b OR a OR c".
' ========================================================================================
PRIVATE FUNCTION DWStrTally (BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS LONG
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(dwsMatchString)
   END IF
   pRegExp.Pattern = dwsMatchString
   IF pRegExp.Execute(wszSourceString) THEN
      RETURN pRegExp.MatchesCount
   END IF
   RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Find the position of the first character in the string that does not match in the match string.
' wstrVerify returns zero if each character in wszSourceString is present in wszMatchString.
' If not, it returns the position of the first non-matching character in wszSourceString.
' nStart: Starting position. If nStart is less than 1 or greater than the length of wszSourceString,
' an empty string is returned.
' Example:
'    DIM dws AS DWSTRING = "123.65,22.5"
'    DIM nPos AS LONG = DWStrVerify(5, dws, "0123456789", TRUE)
'    PRINT nPos
' Output: 7.
' Returns 7 since 5 starts it past the first non-digit ("." at position 4)
' ========================================================================================
PRIVATE FUNCTION DWStrVerify (BYVAL nStart AS LONG, BYREF wszSourceString AS CONST WSTRING, BYREF wszMatchString AS CONST WSTRING, BYVAL IgnoreCase AS BOOLEAN = TRUE) AS LONG
   IF nStart <= 0 OR nStart > LEN(wszSourceString) - 1 THEN RETURN 0
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
      ' Don't escape "[<chars>]", used to specify individual characters to search
   DIM dwsMatchString AS DWSTRING = wszMatchString
   IF LEFT(wszMatchString, 1) <> "[" ANDALSO RIGHT(wszMatchString, 1) <> "]" THEN
      dwsMatchString = DWStrEscape(dwsMatchString)
   END IF
   pRegExp.Pattern = "[^" & dwsMatchString & "]"
   DIM bsSrc AS BSTRING = MID(wszSourceString, nStart)
   IF pRegExp.Execute(bsSrc) THEN
      RETURN pRegExp.MatchPos + nStart - 1
   END IF
   RETURN 0
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string with nCount characters removed from the left, right or mid side of the string.
' - wszSide: "LEFT", "MID" or "RIGHT".
' - wszSourceString: The source string.
' - nCount: Number or characters to remove.
' - nStart: (only MID) Starting position.
' Example: DIM dws AS DWSTRING = DWStrClip("LEFT", "1234567890", 3)     ' Output: "4567890"
' Example: DIM dws AS DWSTRING = DWStrClip("RIGHT", "1234567890", 3)    ' Output: "1234567"
' Example: DIM dws AS DWSTRING = DWStrClip("MID", "1234567890", 3, 4)   ' Output: "1237890"
' ========================================================================================
PRIVATE FUNCTION DWStrClip (BYREF wszSide AS CONST WSTRING, BYREF wszSourceString AS CONST WSTRING, BYVAL nCount AS LONG, BYVAL nStart AS LONG = 0) AS DWSTRING
   DIM dws AS DWSTRING = wszSourceString
   IF nCount <= 0 THEN RETURN dws
   DIM nLen AS LONG = LEN(dws)
   SELECT CASE UCASE(wszSide)
      CASE "LEFT"
         nCount = IIF(nLen < nCount, nLen, nCount)
         dws = MID(wszSourceString, nCount + 1)
         RETURN dws
      CASE "RIGHT"
         nCount = nLen - nCount
         nCount = IIF(nLen < nCount, nLen, nCount)
         dws = LEFT(wszSourceString, nCount)
         RETURN dws
      CASE "MID"
         IF nStart <= 0 THEN RETURN dws
         dws = LEFT(wszSourceString, nStart - 1) + MID(wszSourceString, nStart + nCount)
         RETURN dws
   END SELECT
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Deletes a specified number of characters from a string expression.
' Returns a string based on wszSourceString but with nCount characters deleted
' starting at position nStart. The first character in the string is position 1, etc.
' Usage example:
' DIM dws AS DWSTRING = DWStrDelete("1234567890", 4, 3)   ' Output: 1237890
' ========================================================================================
PRIVATE FUNCTION DWStrDelete (BYREF wszSourceString AS CONST WSTRING, BYVAL nStart AS LONG, BYVAL nCount AS LONG) AS DWSTRING
   DIM nLen AS LONG = LEN(wszSourceString)
   IF nLen = 0 OR nStart <= 0 OR nCount <= 0 OR nStart > nLen THEN RETURN wszSourceString
   RETURN LEFT(wszSourceString, nStart - 1) + MID(wszSourceString, nStart + nCount)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Retuns TRUE if the passed string is muneric.
' Example: PRINT DWStrIsNumeric("1.2345678901234567e+029")   ' Output: true
' Explanation of the pattern used: "^[\+\-]?\d*\.?\d+(?:[Ee][\+\-]?\d+)?$"
'  ^ ? Anchors the match to the start of the string.
'  [\+\-]? ? Matches an optional plus (+) or minus (-) sign at the beginning (for signed numbers).
'  \d* ? Matches zero or more digits before the decimal point (allows integers or leading zero suppression).
'  \.? ? Matches an optional decimal point (if present, allows floating-point numbers).
'  \,? ? Matches an optional decimal point (in Spain, a comma is used instead of a colon).
'  \d+ ? Matches at least one digit after the decimal (ensuring valid numeric values).
'  (?:[Ee][\+\-]?\d+)? ? Handles scientific notation:
'    E or e for exponent notation.
'    [\+\-]? for optional sign after the exponent indicator.
'    \d+ ensures at least one digit in the exponent.
'  $ ? Anchors the match to the end of the string, ensuring a full numeric match.
' ========================================================================================
PRIVATE FUNCTION DWStrIsNumeric (BYREF wszSourcestring AS CONST WSTRING) AS BOOLEAN
   DIM pRegExp AS CRegExp
   pRegExp.Pattern = $"^[\+\-]?\d*\.?\,?\d+(?:[Ee][\+\-]?\d+)?$"
   RETURN pRegExp.Test(wszSourcestring)
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Shrinks a string to use a consistent single character delimiter.
' The purpose of this function is to create a string with consecutive data items (words)
' separated by a consistent single character. This makes it very straightforward to parse
' the results as needed.
' If wszMask is not defined then all leading spaces and trailing spaces are removed entirely.
' All occurrences of two or more spaces are changed to a single space. Therefore, the new
' string returned consists of zero or more words, each separated by a single space character.
' If wszMask is specified, it defines one or more delimiter characters to shrink. All leading
' and trailing mask characters are removed entirely. All occurrences of one or more mask
' characters are replaced with the first character of wszMask The new string returned consists
' of zero or more words, each separated by the character found in the first position of wszMask.
' Example:
' DIM dws AS DWSTRING = DWStrShrink(",,, one , two     three, four,", " ,")
' Output: "one two three four".
' ========================================================================================
PRIVATE FUNCTION DWStrShrink(BYREF wszSourceString AS CONST WSTRING, BYREF wszMask AS CONST WSTRING = "", BYVAL IgnoreCase AS LONG = TRUE) AS DWSTRING
   DIM dwsText AS DWSTRING = wszSourceString
   DIM pRegExp AS CRegExp
   pRegExp.Global = TRUE
   pRegExp.IgnoreCase = IgnoreCase
   IF wszMask = "" THEN
      ' // Change all occurrences of two or more spaces to a single space
      pRegExp.Pattern = "[ ]+"
      dwsText = pRegExp.Replace(dwsText, " ")
   ELSE
      ' // Remove the passed characters
      pRegExp.Pattern = "[" & wszMask & "]+"
      dwsText = pRegExp.Replace(dwsText, LEFT(wszMask, 1))
   END IF
   ' // Remove all leading and trailing spaces
   pRegExp.Pattern = $"^\s+|\s+$"
   dwsText = pRegExp.Replace(dwsText, "")
   RETURN dwsText
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Reverses the contents of a string expression.
' Usage example: DIM dws AS DWSTRING = DWStrReverse("garden")   ' Output: "nedrag"
' ========================================================================================
PRIVATE FUNCTION DWStrReverse (BYREF wszSourceString AS CONST WSTRING) AS DWSTRING
   DIM dwsSourceString AS DWSTRING = wszSourceString
   DIM wszChar AS WSTRING * 2
   DIM nLen AS LONG = LEN(wszSourceString)
   FOR i AS LONG = 1 TO nLen \ 2
      wszChar = MID(dwsSourceString, i, 1)
      MID(dwsSourceString, i, 1) = MID(dwsSourceString, nLen - i + 1, 1)
      MID(dwsSourceString, nLen - i + 1, 1) = wszChar
   NEXT
   RETURN dwsSourceString
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Splits a string into tokens, which are sequences of contiguous characters separated by
' any of the characters that are part of delimiters. Each token is added to a DWSTRING
' (my own dynamic Unicode string data type for FreeBasic) and delimited by a carriage
' return and line feed. The returned string will be parsed later to get the individual tokens.
' Instead of DWSTRING (which is not an intrinsic FreeBasic data type) a buffer could be used.
' wcstok is a C function.
' Parameters:
' - wszStr: The string to split.
' - wszDelimiters: The delimiter characters to use when splitting the string.
' - wszSeparator: Optional. Specifies the separator to use in the returned tokens.
'   If the delimiter expression is the 3-byte value of "," which may be expressed in your
'   source code as the string literal """,""" or as Chr(34,44,34) then a leading and trailing
'   double-quote is added to each token.
' - maxsplits: Optional. Specifies how many splits to do. Default value is -1, which is "all occurrences"
' Return value: A list of tokens separated by the optional seoarator specified in wszSeparator.
' Usage:
' DIM wsz AS WSTRING * 260 = "- This, a sample string."
' DIM dwsTokens AS DWSTRING = wstrSplit(wsz, " ,.-", , -1)
' print "len dwsTokens: ", len(dwsTokens)
' print dwsTokens
' Output: "This","a","sample","string"
' Passing " # " in wszSeparator:
' DIM dwsTokens AS DWSTRING = DWStrSplit(wsz, " ,.-", " # ", -1)
' Output: This # a # sample # string
' ========================================================================================
PRIVATE FUNCTION DWStrSplit (BYREF wszStr AS WSTRING, BYREF wszDelimiters AS WSTRING = " ", BYREF wszSeparator AS WSTRING = CHR(34, 44, 34), BYVAL maxsplits AS LONG = -1) AS DWSTRING
   DIM dws AS DWSTRING = wszStr
   IF maxsplits = 0 THEN RETURN dws
   DIM dwsRes AS DWSTRING, idx AS LONG
   DIM pwsz AS WSTRING PTR = wcstok(dws, @wszDelimiters)
   IF pwsz <> NULL AND wszSeparator = CHR(34, 44, 34) THEN dwsRes += CHR(34)
   WHILE pwsz <> NULL
      dwsRes += *pwsz
      pwsz = wcstok(NULL, @wszDelimiters)
      idx += 1
      IF maxsplits > -1 AND idx = maxsplits THEN
         IF wszSeparator = CHR(34, 44, 34) THEN dwsRes += CHR(34)
         EXIT WHILE
      ELSE
         IF pwsz THEN dwsRes += wszSeparator
      END IF
   WEND
   IF wszSeparator = CHR(34, 44, 34) THEN dwsRes += CHR(34)
   RETURN dwsRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string consisting of all of the strings in an array, each separated by a delimiter.
' If the delimiter is a null (zero-length) string then no separators are inserted between
' the string sections. If the delimiter expression is the 3-byte value of "," which may be
' expressed in your source code as the string literal """,""" or as Chr(34,44,34) then a
' leading and trailing double-quote is added to each string section. This ensures that the
' returned string contains standard comma-delimited quoted fields that can be easily parsed.
' Usage example:
'   DIM rg(1 TO 10) AS DWSTRING
'   FOR i AS LONG = 1 TO 10
'      rg(i) = "string " & i
'   NEXT
'   DIM dws AS DWSTRING
'   DWStrJoin(rg, dws, """,""")
'   print dws
' Instead of DWSTRING, any other data type can be used: BSTRING, STRING...
' ========================================================================================
#macro DWStrJoin(array, dest, delim)
SCOPE
   dest = ""
   IF delim = CHR(34, 44, 34) THEN dest = CHR(34)
   FOR i AS LONG = LBOUND(array) TO UBOUND(array)
      IF UBOUND(array) > -1 THEN
         dest += array(i)
         IF i < UBOUND(array) THEN dest += delim
      END IF
   NEXT
   IF delim = CHR(34, 44, 34) THEN dest += CHR(34)
END SCOPE
#endmacro
' ========================================================================================

' ========================================================================================
' * Inserts a string at a specified position within another string expression.
' Returns a string consisting of wszSourceString with the string wszInsertString inserted
' at nPosition. If nPosition is greater than the length of wszSourceString or <= zero then
' wszInsertString is appended to wszSourceString. The first character in the string is position 1, etc.
' Example: DIM dws AS DWSTRING = DWStrInsert("1234567890", "--", 6)
' ========================================================================================
PRIVATE FUNCTION DWStrInsert (BYREF wszSourceString AS CONST WSTRING, BYREF wszInsertString AS CONST WSTRING, BYVAL nPosition AS LONG) AS DWSTRING
   DIM dws AS DWSTRING = wszSourceString
   IF nPosition <= 0 THEN RETURN dws
   IF nPosition > LEN(wszSourceString) THEN
      dws += wszInsertString
   ELSEIF nPosition = 1 THEN
      dws = wszInsertString + MID(wszSourceString, 1)
   ELSE
      dws = MID(wszSourceString, 1, nPosition - 1) + wszInsertString + MID(wszSourceString, nPosition)
   END IF
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a mixed case version of its string argument.
' Example:
' DIM dws AS DWSTRING = DWstrMCase("Cats aren't AL.WAYS good.")
' Output: Cats Aren'T Al.Ways Good.
' Note: It mimincs the Power Basic's MCase$ function, but I find its rules absurd.
' ========================================================================================
PRIVATE FUNCTION DWStrMCase (BYREF wszSourceString AS WSTRING) AS DWSTRING
   DIM dwRes AS DWSTRING
   Dim PunctSymbols AS DWSTRING = $" .,!?:;()[]{}\""-'?"   ' // List of punctuation symbols
   DIM capitalizeNext AS BOOLEAN = TRUE ' // Flag to indicate when to capitalize
   FOR i AS LONG = 1 TO LEN(wszSourceString)
      DIM currentChar AS DWSTRING = MID(wszSourceString, i, 1)
      IF capitalizeNext THEN
         dwRes &= UCASE(currentChar) ' // Capitalize first letter of a word
      ELSE
         dwRes &= LCASE(currentChar) ' // Force lowercase
      END IF
      ' // Determine if the next character should be capitalized
      capitalizeNext = (INSTR(PunctSymbols, currentChar) > 0)
   NEXT
   RETURN dwRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Adds paired characters to the beginning and end of a string.
' It is particularly useful for enclosing text with parenthesess, quotes, brackets, etc.
' For example: DWstrWrap("Paul", "<", ">") results in <Paul>
' If only one wrap character/string is specified then that character or string is used
' for both sides.
' For example: DWStrWrap("Paul", "'") results in 'Paul'
' If no wrap character/string is specified then double quotes are used.
' For example: DWStrWrap("Paul") results in "Paul"
' ========================================================================================
PRIVATE FUNCTION DWStrWrap OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszLeftChar AS CONST WSTRING, BYREF wszRightChar AS CONST WSTRING) AS DWSTRING
   DIM dws AS DWSTRING = wszLeftChar + wszSourceString & wszRightChar
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION DWStrWrap OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszChar AS CONST WSTRING = CHR(34)) AS DWSTRING
   DIM dws AS DWSTRING = wszChar + wszSourceString + wszChar
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Removes paired characters to the beginning and end of a string.
' It is particularly useful for removing text with parenthesess, quotes, brackets, etc.
' For example: DWStrUnWrap("<Paul>", "<", ">") results in Paul
' If only one unwrap character/string is specified then that character or string is used for both sides.
' For example: DWStrUnWrap("'Paul'", "'") results in Paul
' If no wrap character/string is specified then double quotes are used.
' For example: DWStrUnWrap("""Paul""") results in Paul
' ========================================================================================
PRIVATE FUNCTION DWStrUnWrap OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszLeftChar AS CONST WSTRING, BYREF wszRightChar AS CONST WSTRING) AS DWSTRING
   DIM dws AS DWSTRING = LTRIM(wszSourceString, wszLeftChar)
   dws = RTRIM(dws, wszRightChar)
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION DWStrUnWrap OVERLOAD (BYREF wszSourceString AS CONST WSTRING, BYREF wszChar AS CONST WSTRING = CHR(34)) AS DWSTRING
   DIM dws AS DWSTRING = LTRIM(wszSourceString, wszChar)
   dws = RTRIM(dws, wszChar)
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string consisting of multiple copies of the specified string.
' This function is very similar to STRING (which makes multiple copies of a single character).
' Example: DIM dws AS DWSTRING = DWStrRepeat(5, "Paul")
' ========================================================================================
PRIVATE FUNCTION DWStrRepeat (BYVAL nCount AS LONG, BYREF wszStr AS CONST WSTRING) AS DWSTRING
   DIM dws AS DWSTRING
   IF nCount <= 0 THEN RETURN dws
   ' // Create the final full buffer and insert the strings into it
   ' // in order to avoid nCount concatenations.
   DIM nLen AS LONG = LEN(wszStr)
   dws = WSPACE(nCount * nLen)
   FOR i AS LONG = 0 TO nCount - 1
      MID(dws, (i * nLen) + 1, nLen) = wszStr
   NEXT
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string containing a left-justified (padded) string.
' If the optional parameter wszPadCharacter not specified, the function pads the string with
' space characters to the left. Otherwise, the function pads the string with the first
' character of wszPadCharacter
' Example: DIM dws AS DWSTRING = DWStrLSet("FreeBasic", 20, "*")
' ========================================================================================
PRIVATE FUNCTION DWStrLSet (BYREF wszSourceString AS CONST WSTRING, BYVAL nStringLength AS LONG, BYREF wszPadCharacter AS CONST WSTRING = " ") AS DWSTRING
   DIM dws AS DWSTRING = WSTRING(nStringLength, wszPadCharacter)
   MID(dws, 1, LEN(wszSourceString)) = wszSourceString
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
' Left-aligns a string within the space of another string.
' If wszStr is empty, DWStrLsetAbs leaves the padding positions unchanged from their original
' content, rather than replacing them with spaces as LSET does.
' If wszStr is longer than wszSourceString, DWStrLSetAbs truncates it from the right until it fits
' in the result string.
' Example:
' DIM dws AS DWSTRING = "NameBasic=SuperBasic"
' PRINT DWStrLSetAbs(dws, "FreeBasic")  ' Output: FreeBasic=SuperBasic"
' ========================================================================================
PRIVATE FUNCTION DWStrLSetAbs (BYREF wszSourceString AS CONST WSTRING, BYREF wszStr AS CONST WSTRING) AS DWSTRING
   DIM dwsStr AS DWSTRING = wszStr
   IF dwsStr = "" THEN RETURN wszSourceString
   IF LEN(dwsStr) > LEN(wszSourceString) THEN dwsStr = LEFT(dwsStr, LEN(wszSourceString))
   DIM dws AS DWSTRING = wszSourceString
   MID(dws, 1, LEN(dwsStr)) = dwsStr
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string containing a right-justified (padded) string.
' If the optional parameter wszPadCharacter not specified, the function pads the string with
' space characters to the left. Otherwise, the function pads the string with the first
' character of wszPadCharacter.
' Example: DIM dws AS DWSTRING = DWStrRSet("FreeBasic", 20, "*")
' ========================================================================================
PRIVATE FUNCTION DWStrRSet (BYREF wszSourceString AS CONST WSTRING, BYVAL nStringLength AS LONG, BYREF wszPadCharacter AS CONST WSTRING = " ") AS DWSTRING
   IF LEN(wszSourceString) > nStringLength THEN RETURN LEFT(wszSourceString, nStringLength)
   DIM dws AS DWSTRING = WSTRING(nStringLength, wszPadCharacter)
   MID(dws, nStringLength - LEN(wszSourceString) + 1, LEN(wszSourceString)) = wszSourceString
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Right justify a string into the space of a string variable.
' If the optional parameter wszPadCharacter not specified, the function pads the string with
' space characters to the left. Otherwise, the function pads the string with the first
' character of wszPadCharacter.
' If wszStr is empty, DWStrRSetAbs leaves the padding positions unchanged from their original
' content, rather than replacing them with spaces as RSET does.
' If wszStr is longer than wszSourceString, DWStrRSetAbs truncates it from the right until it fits
' in the result string.
' Example:
' DIM dws AS DWSTRING = "NameBasic=NameBasic"
' PRINT DWStrRSetAbs(dws, "FreeBasic")  ' Output: "NameBasic=FreeBasic"
' ========================================================================================
PRIVATE FUNCTION DWStrRSetAbs (BYREF wszSourceString AS CONST WSTRING, BYREF wszStr AS CONST WSTRING) AS DWSTRING
   DIM dwsStr AS DWSTRING = wszStr
   IF dwsStr = "" THEN RETURN wszSourceString
   IF LEN(dwsStr) > LEN(wszSourceString) THEN dwsStr = RIGHT(dwsStr, LEN(wszSourceString))
   DIM dws AS DWSTRING = wszSourceString
   DIM nPos AS LONG = LEN(wszSourceString) - LEN(dwsStr) + 1
   IF nPos < 1 THEN nPos = 1
   MID(dws, nPos, LEN(dwsStr)) = dwsStr
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns a string containing a centered (padded) string.
' If the optional parameter wszPadCharacter not specified, the function pads the string with
' space characters to the left. Otherwise, the function pads the string with the first
' character of wszPadCharacter.
' Example: DIM dws AS DWSTRING = DWStrCSet("FreeBasic", 20, "*")
' ========================================================================================
PRIVATE FUNCTION DWStrCSet (BYREF wszSourceString AS CONST WSTRING, BYVAL nStringLength AS LONG, BYREF wszPadCharacter AS CONST WSTRING = " ") AS DWSTRING
   IF LEN(wszSourceString) > nStringLength THEN RETURN LEFT(wszSourceString, nStringLength)
   DIM dws AS DWSTRING = WSTRING(nStringLength, wszPadCharacter)
   MID(dws, (nStringLength - LEN(wszSourceString)) \ 2 + 1, LEN(wszSourceString)) = wszSourceString
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Returns a string containing a centered string within the space of another string.
' Example: DIM dwsPad AS DWSTRING = "COOL COOL COOL COOL COOL"
'          DIM dws AS DWSTRING = "..FreeBasic is.."
'          PRINT DWStrCSetAbs(dwsPad, dws)
' Result: "COOL..FreeBasic is..COOL"
' ========================================================================================
PRIVATE FUNCTION DWStrCSetAbs (BYREF wszPadString AS CONST WSTRING, BYREF wszString AS CONST WSTRING) AS DWSTRING
   IF LEN(wszString) > LEN(wszPadString) THEN RETURN wszPadString
   DIM dwsOut AS DWSTRING = wszPadString
   MID(dwsOut, (LEN(wszPadString) - LEN(wszString)) \ 2 + 1, LEN(wszString)) = wszString
   RETURN dwsOut
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the index of the first character in a string that doesn't belong to a specified set of characters.
' Example:
'   DIM dwsText AS DWSTRING = "129th"
'   DIM dwsSet AS DWSTRING = "1234567890"
'   DIM n AS LONG = DWStrSpn(dwsText, dwsSet)
'   PRINT "The initial number has " & WSTR(n) & " digits"   ' Output: 3
' The C wcsspn function can also be used.
' ========================================================================================
PRIVATE FUNCTION DWStrSpn (BYREF wszText AS CONST WSTRING, BYREF wszSet AS CONST WSTRING, BYVAL IgnoreCase AS LONG = TRUE) AS LONG
   IF IgnoreCase THEN
      RETURN StrSpnW(@wszText, @wszSet)
   ELSE
      RETURN StrCSpnIW(@wszText, @wszSet)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Converts a numeric value into a string that represents the number expressed as a size
' value in bytes, kilobytes, megabytes, or gigabytes, depending on the size.
' ========================================================================================
PRIVATE FUNCTION DWStrFormatByteSize (BYVAL ull AS LONGLONG) AS DWSTRING
   DIM wsz AS WSTRING *  260 = WSPACE(260)
   StrFormatByteSizeW(ull, @wsz, 260)
   RETURN wsz
END FUNCTION
' ========================================================================================
' ========================================================================================
' Converts a numeric value into a string that represents the number expressed as a size
' value in kilobytes.
' ========================================================================================
PRIVATE FUNCTION DWStrFormatKBSize (BYVAL ull AS LONGLONG) AS DWSTRING
   DIM wsz AS WSTRING * 260 = WSPACE(260)
   StrFormatKBSizeW(ull, @wsz, 260)
   RETURN wsz
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a time interval, specified in milliseconds, to a string.
' Parameters:
' - dwTimeMS: The time interval, in milliseconds.
' - digits  : The maximum number of significant digits to be represented in the output
'             string. Some examples are:
'             dwTimeMS digits   cwsOut
'             -------- ------ -----------
'                34000    3         34 sec.
'                34000    2         34 sec.
'                34000    1         30 sec.
'                74000    3  1 min. 14 sec.
'                74000    2  1 min. 10 sec.
'                74000    1  1 min.
' ========================================================================================
PRIVATE FUNCTION DWStrFromTimeInterval (BYVAL dwTimeMS AS DWORD, BYVAL digits AS LONG) AS DWSTRING
   DIM dws AS DWSTRING = WSPACE(260)
   StrFromTimeIntervalW(dws, 260, dwTimeMS, digits)
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Returns the count of delimited fields from a string expression.
' If wszMainStr is empty (a null string) or contains no delimiter character(s), the string
' is considered to contain exactly one sub-field. In this case, wstrParseCount returns the value 1.
' Delimiter contains a string (one or more characters) that must be fully matched.
' Delimiters are case-sensitive.
' Example: DIM nCount AS LONG = DWStrParseCount("one,two,three", ",")   ' Output: 3
' Example: DIM nCount AS LONG = DWStrParseCount("1;2,3", ",;")          ' Output: 3
' ========================================================================================
PRIVATE FUNCTION DWStrParseCount (BYREF wszSourceString AS CONST WSTRING, BYREF wszDelimiter AS CONST WSTRING = ",") AS LONG
   DIM nCount AS LONG = 1
   DIM nPos AS LONG = 1
   DO
      nPos = INSTR(nPos, wszSourceString, ANY wszDelimiter)
      IF nPos = 0 THEN EXIT DO
      nCount += 1
      nPos += LEN(wszDelimiter)
   LOOP
   RETURN nCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns delimited fields from a string expression.
' Delimiter contains a set of characters (one or more), any of which may act as a delimiter character.
' If nPosition evaluates to zero or is outside of the actual field count, an empty string is returned.
' If nPosition is negative then fields are searched from the right to left of the MainString.
' Delimiters are case-sensitive.
' Example: DIM dws AS DWSTRING = DWStrParse("one,two,three")           ' Output: one
' Example: DIM dws AS DWSTRING = DWStrParse("one;two,three", 1, ";")   ' Output: one
' Example: DIM dws AS DWSTRING = DWStrParse("1;2,3", 2, ",;")          ' Output: 2
' ========================================================================================
PRIVATE FUNCTION DWStrParse (BYREF wszSourceString AS CONST WSTRING, BYVAL index AS LONG = 1, BYREF wszDelimiter AS CONST WSTRING = ",") AS DWSTRING

   DIM dws AS DWSTRING
   IF LEN(wszSourceString) = 0 THEN RETURN dws
   DIM nCount AS LONG, nStart AS LONG
   DIM nPos AS LONG = 1
   DIM fReverse AS BOOLEAN = IIF(index < 0, TRUE, FALSE)
   index = ABS(index)

   IF fReverse THEN
      ' *** Reverse search ***
      ' // Get the start of the token by searching in reverse
      nPos = InstrRev(wszSourceString, ANY wszDelimiter)
      DO WHILE nPos > 0   ' if not found loop will be skipped
         nStart = nPos + 1
         nCount += 1
         nPos = nPos - 1
         IF nCount = index THEN EXIT DO
         nPos = InStrRev(wszSourceString, ANY wszDelimiter, nPos)
      LOOP
      IF nPos = 0 THEN nStart = 1
      ' // Now continue forward to get the end of the token
      nPos = INSTR(nStart, wszSourceString, ANY wszDelimiter)
      IF nPos > 0 OR nCount = index THEN
         IF nPos = 0 THEN
            dws = MID(wszSourceString, nStart)
         ELSE
            dws = MID(wszSourceString, nStart, nPos - nStart)
         END IF
      END IF
   ELSE
      ' *** Forward search ***
      DO
         nStart = nPos
         nPos = INSTR(nPos, wszSourceString, ANY wszDelimiter)
         IF nPos THEN
            nCount += 1
            nPos += 1
         END IF
      LOOP UNTIL nPos = 0 OR nCount = index
      IF nPos > 0 OR nCount = index - 1 THEN
         IF nPos = 0 THEN
            dws = MID(wszSourceString, nStart)
         ELSE
            dws = MID(wszSourceString, nStart, nPos - 1 - nStart)
         END IF
      END IF
   END IF

   ' // Return the result
   RETURN dws

END FUNCTION
' ========================================================================================

' ========================================================================================
'  * Parses a path/file name to extract component parts.
'  This function evaluates a text path/file text name, and returns a requested part of the
'  name. The functionality is strictly one of string parsing alone.
'  wszOption is one of the following words which is used to specify the requested part:
'  PATH
'        Returns the path portion of the path/file Name. That is the text up to and
'        including the last backslash (\) or colon (:).
'  NAME
'        Returns the name portion of the path/file Name. That is the text to the right
'        of the last backslash (\) or colon (:), ending just before the last period (.).
'  EXTN
'        Returns the extension portion of the path/file name. That is the last
'        period (.) in the string plus the text to the right of it.
'  NAMEX
'        Returns the name and the EXTN parts combined.
' ========================================================================================
PRIVATE FUNCTION DWStrPathName (BYREF wszOption AS CONST WSTRING, BYREF wszFileSpec AS WSTRING) AS DWSTRING
   DIM dws AS DWSTRING
   IF LEN(wszFileSpec) = 0 THEN RETURN dws
   SELECT CASE UCASE(wszOption)
      CASE "PATH"
         ' // Returns the path portion of file spec
         DIM nPos AS LONG = InstrRev(wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(wszFileSpec, 1, nPos)
      CASE "NAME"
         ' // Retrieve the full filename
         dws = wszFileSpec
         DIM nPos AS LONG = InstrRev(wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(wszFileSpec, nPos + 1)
         ' // Retrieve the filename
         nPos = InstrRev(dws, ".")
         IF nPos THEN dws = MID(dws, 1, nPos - 1)
      CASE "NAMEX"
         ' // Retrieve the name and extension combined
         DIM nPos AS LONG = InStrRev(wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(wszFileSpec, nPos + 1) ELSE dws = wszFileSpec
      CASE "EXTN"
         ' // Retrieve the name and extension combined
         DIM nPos AS LONG = InstrRev(wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(wszFileSpec, nPos + 1) ELSE dws = wszFileSpec
         ' // Retrieve the extension
         nPos = InStrRev(dws, ".")
         IF nPos THEN dws = MID(dws, nPos) ELSE dws = ""
   END SELECT
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path for a file name.
' Parameters:
' - wszOption: This is one of the following words which is used to specify the requested part:
'   FULL: Return the full drive/path/file name.
'   PATH: Return the path portion of the path/file name.
'         That is the text up to and including the last backslash (\).
'   NAME: Return the name portion of the path/file name.
'         That is the text to the right of the last backslash (\), ending just before the last period (.) in the string.
'   EXTN: Return the extension portion of the path/file name.
'         That is the last period (.) in the string plus the text to the right of it.
'   NAMEX: Return the NAME and the EXTN parts combined.
' - wszFileSpec: A file name which is expected to exist on disk. It must not be an ambiguous
'   name -- that is, it may not include a query (?) or an asterisk (*) character.
' - wszOtherDirs: An optional path string which includes one or more paths to be searched
'   to find wszFileSpec. If multiple path names are included in this string, they must
'   each be separated by a semicolon (;) delimiter. If wszOtherDirs: is not given, or it is
'   a nul (zero-length) string, the following directories are searched:
'      - The directory from which the application was loaded.
'      - The current directory.
'      - The standard directories such as System32 and the directories specified in the PATH
'        environment variable.
'   To expedite the process or enable wstrPathScan to search a wider range of directories,
'   use the wszOtherDirs parameter to specify one or more directories to be searched first.
' Return value:
'   If the file is found, it returns either the full path/file name, or a selected part of it.
'   If the file is not found, a nul (zero-length)  is returned. If you wish to simply parse
'   a text file name, without regard to its validation on disk, you should use the companion
'   function wstrPathName.
' ========================================================================================
PRIVATE FUNCTION DWStrPathScan (BYREF wszOption AS CONST WSTRING, BYREF wszFileSpec AS CONST WSTRING, BYREF wszOtherDirs AS CONST WSTRING = "") AS DWSTRING
   IF wszFileSpec = "" THEN RETURN ""
   DIM _wszFilespec AS WSTRING * MAX_PATH = wszFileSpec
   DIM nCount AS LONG, rgOtherDirs(ANY) AS WSTRING PTR
   DIM dwsOtherDirs AS DWSTRING = wszOtherDirs
   IF LEN(dwsOtherDirs) = 0 THEN dwsOtherDirs = ExePath & ";" &  CURDIR
   nCount = DWstrParseCount(dwsOtherDirs, ";")
   IF nCount THEN
      REDIM rgOtherDirs(0 TO nCount)
      FOR i AS LONG = 0 TO nCount - 1
         rgOtherDirs(i) = STRPTR(DWStrParse(dwsOtherDirs, i + 1, ";"))
      NEXT
      rgOtherDirs(nCount) = NULL
      IF PathFindOnPathW(@_wszFilespec, @rgotherDirs(0)) = 0 THEN _wszFilespec = ""
   END IF
   DIM dws AS DWSTRING = _wszFileSpec
   IF LEN(_wszFileSpec) = 0 THEN RETURN dws
   SELECT CASE UCASE(wszOption)
      CASE "FULL"
         RETURN _wszFileSpec
      CASE "PATH"
         ' // Returns the path portion of file spec
         DIM nPos AS LONG = InstrRev(_wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(_wszFileSpec, 1, nPos)
      CASE "NAME"
         ' // Retrieve the full filename
         dws = _wszFileSpec
         DIM nPos AS LONG = InstrRev(_wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(_wszFileSpec, nPos + 1)
         ' // Retrieve the filename
         nPos = InstrRev(dws, ".")
         IF nPos THEN dws = MID(dws, 1, nPos - 1)
      CASE "NAMEX"
         ' // Retrieve the name and extension combined
         DIM nPos AS LONG = InStrRev(_wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(_wszFileSpec, nPos + 1) ELSE dws = _wszFileSpec
      CASE "EXTN"
         ' // Retrieve the name and extension combined
         DIM nPos AS LONG = InstrRev(_wszFileSpec, ANY ":/\")
         IF nPos THEN dws = MID(_wszFileSpec, nPos + 1) ELSE dws = _wszFileSpec
         ' // Retrieve the extension
         nPos = InStrRev(dws, ".")
         IF nPos THEN dws = MID(dws, nPos) ELSE dws = ""
   END SELECT
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts an array of bytes into a formatted string.
' Note: Wrapped because, at the time of writing, it is not supported by the provided
' FreeBasic crypt32 import library.
' ========================================================================================
PRIVATE FUNCTION DWStrCryptBinaryToStringA (BYVAL pbBinary AS CONST UBYTE PTR, BYVAL cbBinary AS DWORD, _
BYVAL dwFlags AS DWORD, BYVAL pszString AS LPSTR, BYVAL pcchString AS DWORD PTR) AS WINBOOL
   DIM AS ANY PTR pLib = DyLibLoad("crypt32.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pCryptBinaryToStringA AS FUNCTION (BYVAL pbBinary AS CONST UBYTE PTR, BYVAL cbBinary AS DWORD, _
       BYVAL dwFlags AS DWORD, BYVAL pszString AS LPSTR, BYVAL pcchString AS DWORD PTR) AS WINBOOL
   pCryptBinaryToStringA = DyLibSymbol(pLib, "CryptBinaryToStringA")
   IF pCryptBinaryToStringA THEN FUNCTION = pCryptBinaryToStringA(pbBinary, cbBinary, dwFlags, pszString, pcchString)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION DWStrCryptBinaryToStringW (BYVAL pbBinary AS CONST UBYTE PTR, BYVAL cbBinary AS DWORD, _
BYVAL dwFlags AS DWORD, BYVAL pszString AS LPWSTR, BYVAL pcchString AS DWORD PTR) AS WINBOOL
   DIM AS ANY PTR pLib = DyLibLoad("crypt32.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pCryptBinaryToStringW AS FUNCTION (BYVAL pbBinary AS CONST UBYTE PTR, BYVAL cbBinary AS DWORD, _
       BYVAL dwFlags AS DWORD, BYVAL pszString AS LPWSTR, BYVAL pcchString AS DWORD PTR) AS WINBOOL
   pCryptBinaryToStringW = DyLibSymbol(pLib, "CryptBinaryToStringW")
   IF pCryptBinaryToStringW THEN FUNCTION = pCryptBinaryToStringW(pbBinary, cbBinary, dwFlags, pszString, pcchString)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a formatted string into an array of bytes.
' ========================================================================================
PRIVATE FUNCTION DWStrCryptStringToBinaryA (BYVAL pszString AS LPCSTR, BYVAL cchString AS DWORD, _
BYVAL dwFlags AS DWORD, BYVAL pbBinary AS UBYTE PTR, BYVAL pcbBinary AS DWORD PTR, _
BYVAL pdwSkip AS DWORD PTR, BYVAL pdwFlags AS DWORD PTR) AS WINBOOL
   DIM AS ANY PTR pLib = DyLibLoad("crypt32.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pCryptStringToBinaryA AS FUNCTION (BYVAL pszString AS LPCSTR, BYVAL cchString AS DWORD, _
       BYVAL dwFlags AS DWORD, BYVAL pbBinary AS UBYTE PTR, BYVAL pcbBinary AS DWORD PTR, _
       BYVAL pdwSkip AS DWORD PTR, BYVAL pdwFlags AS DWORD PTR) AS WINBOOL
   pCryptStringToBinaryA = DyLibSymbol(pLib, "CryptStringToBinaryA")
   IF pCryptStringToBinaryA THEN FUNCTION = pCryptStringToBinaryA(pszString, cchString, dwFlags, pbBinary, pcbBinary, pdwSkip, pdwFLags)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION DWStrCryptStringToBinaryW (BYVAL pwszString AS LPCWSTR, BYVAL cchString AS DWORD, _
BYVAL dwFlags AS DWORD, BYVAL pbBinary AS UBYTE PTR, BYVAL pcbBinary AS DWORD PTR, _
BYVAL pdwSkip AS DWORD PTR, BYVAL pdwFlags AS DWORD PTR) AS WINBOOL
   DIM AS ANY PTR pLib = DyLibLoad("crypt32.dll")
   IF pLib = NULL THEN EXIT FUNCTION
   DIM pCryptStringToBinaryW AS FUNCTION (BYVAL pwszString AS LPCWSTR, BYVAL cchString AS DWORD, _
       BYVAL dwFlags AS DWORD, BYVAL pbBinary AS UBYTE PTR, BYVAL pcbBinary AS DWORD PTR, _
       BYVAL pdwSkip AS DWORD PTR, BYVAL pdwFlags AS DWORD PTR) AS WINBOOL
   pCryptStringToBinaryW = DyLibSymbol(pLib, "CryptStringToBinaryW")
   IF pCryptStringToBinaryW THEN FUNCTION = pCryptStringToBinaryW(pwszString, cchString, dwFlags, pbBinary, pcbBinary, pdwSkip, pdwFLags)
   DyLibFree(pLib)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION DWStrBase64EncodeA (BYREF strData AS STRING) AS STRING
   DIM cchStr AS DWORD, strOut AS STRING
   DIM bRes AS LONG = DWStrCryptBinaryToStringA(STRPTR(strData), LEN(strData), CRYPT_STRING_BASE64, NULL, @cchStr)
   IF bRes = 0 OR cchStr = 0 THEN EXIT FUNCTION
   strOut = SPACE(cchStr)
   bRes = DWStrCryptBinaryToStringA(STRPTR(strData), LEN(strData), CRYPT_STRING_BASE64, STRPTR(strOut), @cchStr)
   FUNCTION = strOut
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION DWStrBase64EncodeW (BYREF dwsData AS DWSTRING) AS DWSTRING
   DIM cchStr AS DWORD, dwsOut AS DWSTRING
   DIM bRes AS LONG = DWStrCryptBinaryToStringW(dwsData, LEN(dwsData) * 2, CRYPT_STRING_BASE64, NULL, @cchStr)
   IF bRes = 0 OR cchStr = 0 THEN EXIT FUNCTION
   dwsOut = WSPACE(cchStr)
   bRes = DWStrCryptBinaryToStringW(dwsData, LEN(dwsData) * 2, CRYPT_STRING_BASE64, dwsOut, @cchStr)
   FUNCTION = dwsOut
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION DWStrBase64DecodeA (BYREF strData AS STRING) AS STRING
   DIM cbBinary AS DWORD, strOut AS STRING
   DIM bRes AS LONG = DWStrCryptStringToBinaryA(STRPTR(strData), LEN(strData), CRYPT_STRING_BASE64, NULL, @cbBinary, NULL, NULL)
   IF bRes = 0 OR cbBinary = 0 THEN EXIT FUNCTION
   strOut = SPACE(cbBinary)
   bRes = DWStrCryptStringToBinaryA(STRPTR(strData), LEN(strData), CRYPT_STRING_BASE64, STRPTR(strOut), @cbBinary, NULL, NULL)
   FUNCTION = strOut
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION DWStrBase64DecodeW (BYREF dwsData AS DWSTRING) AS DWSTRING
   DIM cbBinary AS DWORD, dwsOut AS DWSTRING
   DIM bRes AS LONG = DWStrCryptStringToBinaryW(dwsData, LEN(dwsData) * 2, CRYPT_STRING_BASE64, NULL, @cbBinary, NULL, NULL)
   IF bRes = 0 OR cbBinary = 0 THEN EXIT FUNCTION
   dwsOut = WSPACE(cbBinary \ 2)
   bRes = DWStrCryptStringToBinaryW(dwsData, LEN(dwsData) * 2, CRYPT_STRING_BASE64, dwsOut, @cbBinary, NULL, NULL)
   FUNCTION = dwsOut
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                UNICODE - SURROGATES
' ########################################################################################

'const HIGH_SURROGATE_START = &hd800
'const HIGH_SURROGATE_END = &hdbff
'const LOW_SURROGATE_START = &hdc00
'const LOW_SURROGATE_END = &hdfff
'#define IS_HIGH_SURROGATE(wch) (((wch) >= HIGH_SURROGATE_START) andalso ((wch) <= HIGH_SURROGATE_END))
'#define IS_LOW_SURROGATE(wch) (((wch) >= LOW_SURROGATE_START) andalso ((wch) <= LOW_SURROGATE_END))
'#define IS_SURROGATE_PAIR(hs, ls) (IS_HIGH_SURROGATE(hs) andalso IS_LOW_SURROGATE(ls))

' ========================================================================================
' Checks if the specified string has surrogates.
' ========================================================================================
PRIVATE FUNCTION DWStrHasSurrogates (BYREF wszStr AS WSTRING) AS BOOLEAN
   FOR i AS LONG = 1 TO LEN(wszStr)
      IF ASC(wszStr, i) >= &hD800 AND ASC(wszStr, i) <= &hDBFF THEN RETURN TRUE
   NEXT
   RETURN False
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks whether a UTF-16 encoded string contains valid high-low surrogate pairs.
' ========================================================================================
PRIVATE FUNCTION DWStrIsValidSurrogatePair (BYVAL high AS USHORT, BYVAL low AS USHORT) AS BOOLEAN
   RETURN (high >= &hD800 AND high <= &hDBFF) AND (low >= &hDC00 AND low <= &hDFFF)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a surrogate pair to a Unicode code point.
' Extracts the actual Unicode code point from a valid surrogate pair.
' ========================================================================================
PRIVATE FUNCTION DWStrSurrogatePairToCodePoint (BYVAL high AS USHORT, BYVAL low AS USHORT) AS ULONG
   IF IS_SURROGATE_PAIR(high, low) THEN
      RETURN ((high - &hD800) * &h400) + (low - &hDC00) + &h10000
  END IF
  RETURN 0  ' Invalid surrogate pair
END FUNCTION
' ========================================================================================

' ========================================================================================
' Encode Unicode code point as surrogate pair.
' Converts a Unicode code point (above U+FFFF) back into its high and low surrogate pair.
' ========================================================================================
PRIVATE SUB DWStrCodePointToSurrogatePair (BYVAL codePoint AS ULONG, BYREF high AS USHORT, BYREF low AS USHORT)
   IF codePoint >= &H10000 AND codePoint <= &h10FFFF THEN
      high = &hD800 + ((codePoint - &h10000) \ &h400)
      low = &hDC00 + ((codePoint - &h10000) MOD &h400)
   ELSE
      high = 0 : low = 0
   END IF
END SUB
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
PRIVATE FUNCTION DWStrScanForSurrogates( _
   BYVAL memAddr AS WSTRING PTR, _
   BYVAL nChars AS LONG, _
   BYVAL searchBrokenOnly AS BOOLEAN = TRUE) AS LONG

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

' =====================================================================================
' Returns a wide-character string from a codepoint.
' The codepoint returned is the sum of a surrogate pair.
' =====================================================================================
PRIVATE FUNCTION DWStrChrW (BYVAL codepoint AS UInteger) AS DWSTRING
   If codepoint <= &hFFFF Then RETURN WCHR(codepoint)
   ' Convert to UTF-16 surrogate pair for higher codepoints
   DIM AS USHORT highSurrogate = &hD800 OR ((codepoint - &h10000) SHR 10)
   DIM AS USHORT lowSurrogate = &hDC00 OR ((codepoint - &h10000) AND &h3FF)
   RETURN WCHR(highSurrogate) + WCHR(lowSurrogate)
END FUNCTION
' =====================================================================================

' ########################################################################################
'                                      ENVIRONMENT
' ########################################################################################

' ========================================================================================
' Retrieves the contents of the specified variable from the environment block of the
' calling process.
' - pwszName : The name of the environment variable.
' Return value: The contents of the specified environment variable.
' Example: DIM dws AS DWSTRING = DWStrEnviron("path")
' ========================================================================================
PRIVATE FUNCTION DWStrEnviron (BYVAL pwszName AS LPCWSTR) AS DWSTRING
   DIM wszBuffer AS WSTRING * 32767
   DIM cb AS DWORD = GetEnvironmentVariableW(pwszName, @wszBuffer, 32767)
   RETURN LEFT(wszBuffer, cb)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the contents of the specified environment variable for the current process.
' - pwszName : The name of the environment variable.
'              The operating system creates the environment variable if it does not exist
'              and pwszValue is not NULL.
' - pszValue : The contents of the environment variable.
'              The maximum size of a user-defined environment variable is 32,767 characters.
' Return value:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
'   To get extended error information, call GetLastError.
' Example: DWStrSetEnviron("path", "c:")
' ========================================================================================
PRIVATE FUNCTION DWStrSetEnviron OVERLOAD (BYVAL pwszName AS LPCWSTR, BYVAL pwszValue AS LPCWSTR) AS BOOLEAN
   RETURN SetEnvironmentVariableW(pwszName, pwszValue)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the contents of the specified environment variable for the current process.
' - varexpr = Name and setting of an environment variable in the following (or equivalent)
'   form: varname=varstring. (varname being the name of the environment variable, and
'   varstring being its text value to set).
' Returns 0 on success, or -1 on failure.
' Example: AfxSetEnviron "path=c:"
' ========================================================================================
PRIVATE FUNCTION DWStrSetEnviron OVERLOAD (BYREF varexp AS WSTRING) AS BOOLEAN
   DIM dwsName AS DWSTRING = DWStrExtract(1, varexp, "=")
   IF LEN(dwsName) = 0 THEN RETURN TRUE
   dwsName = TRIM(dwsName)
   DIM dwsValue AS DWSTRING
   DIM p AS LONG = INSTR(varexp, "=")
   IF p = 0 THEN RETURN TRUE
   dwsValue = MID(varexp, p + 1)
   dwsValue = TRIM(dwsValue)
   IF LEN(dwsValue) = 0 THEN RETURN TRUE
   RETURN NOT SetEnvironmentVariable(dwsName, dwsValue)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the specified environment variable from the current process.
' - pwszName : The name of the environment variable to remove.
' Return value:
'   If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
'   To get extended error information, call GetLastError.
' Example: DWStrRemoveEnviron("TEMP")
' ========================================================================================
PRIVATE FUNCTION DWStrRemoveEnviron (BYVAL pwszName AS LPCWSTR) AS BOOLEAN
   RETURN SetEnvironmentVariableW(pwszName, NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Expands environment-variable strings and replaces them with the values defined for the current user.
' To specify the environment block for a particular user or the system, use the Windows API
' ExpandEnvironmentStringsForUser function.
' ========================================================================================
PRIVATE FUNCTION DWstrExpandEnvironmentStrings (BYREF wszInput AS WSTRING) AS DWSTRING
   DIM wszBuffer AS WSTRING * 32767
   IF ExpandEnvironmentStringsW(wszInput, wszBuffer, 32767) THEN
      RETURN wszBuffer
   END IF
   RETURN ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the environment variables for the current process.
' ========================================================================================
PRIVATE FUNCTION DWStrGetEnvironmentStrings () AS SAFEARRAY PTR
   DIM lpEnv AS LPWSTR = GetEnvironmentStringsW
   IF lpEnv = NULL THEN RETURN NULL
   DIM p AS LPWSTR = lpEnv
   DIM count AS LONG
   ' First pass: count entries
   WHILE *p <> 0
      count += 1
      DIM entry AS DWSTRING = p
      p += LEN(entry) + 1
   WEND
   ' Create SAFEARRAY
   DIM bounds AS SAFEARRAYBOUND
   bounds.lLbound = 0
   bounds.cElements = count
   DIM psa AS SAFEARRAY PTR = SafeArrayCreate(VT_BSTR, 1, @bounds)
   IF psa = NULL THEN
      FreeEnvironmentStringsW(lpEnv)
      RETURN NULL
   END IF
   ' Second pass: fill array
   p = lpEnv
   FOR i AS LONG = 0 TO count - 1
      DIM bstr AS BSTR = SysAllocString(p)
      SafeArrayPutElement(psa, @i, bstr)
      p += LEN(p) + 1
   NEXT
   FreeEnvironmentStringsW(lpEnv)
   RETURN psa
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of environment string.
' ========================================================================================
PRIVATE FUNCTION DWStrEnvironCount () AS LONG
   DIM lpEnv AS LPWSTR = GetEnvironmentStringsW
   IF lpEnv = NULL THEN RETURN 0
   DIM p AS LPWSTR = lpEnv
   DIM count AS LONG
   ' First pass: count entries
   WHILE *p <> 0
      count += 1
      DIM entry AS DWSTRING = p
      p += LEN(entry) + 1
   WEND
   FreeEnvironmentStringsW(lpEnv)
   RETURN count
END FUNCTION
' ========================================================================================


' ########################################################################################
'                                      LOCALE INFORMATION
' ########################################################################################
' Requires Windows Vista or superior.
#if _WIN32_WINNT = &h0602

' ========================================================================================
' Retrieves the user default locale name.
' ========================================================================================
PRIVATE FUNCTION DWStrGetUserDefaultLocaleName () AS DWSTRING
   DIM wszLocaleName AS WSTRING * LOCALE_NAME_MAX_LENGTH
   DIM res AS LONG = GetUserDefaultLocaleName(@wszLocaleName, LOCALE_NAME_MAX_LENGTH)
   RETURN wszLocaleName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the abbreviated native day name for the specified day (1 = Monday, etc.).
' ========================================================================================
PRIVATE FUNCTION DWStrAbbrevDayName (BYVAL nDay AS LONG, BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   IF nDay < 1 OR nDay > 7 THEN RETURN ""
   GetLocaleInfoEx(pwszLocale, LOCALE_SABBREVDAYNAME1 + nDay - 1, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns the abbreviated native month name for the specified month.
' ========================================================================================
PRIVATE FUNCTION DWStrAbbrevMonthName (BYVAL nMonth AS LONG, BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   IF nMonth < 1 OR nMonth > 12 THEN RETURN ""
   GetLocaleInfoEx(pwszLocale, LOCALE_SABBREVMONTHNAME1 + nMonth - 1, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Full localized name of the country/region.
' Deprecated. See LocalizedCountryName.
' ========================================================================================
PRIVATE FUNCTION DWStrCountryName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SCOUNTRY, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' String used as the local monetary symbol. The maximum number of characters allowed for
' this string is 13, including a terminating null character. For example, in the United
' States, this symbol is "$".
' ========================================================================================
PRIVATE FUNCTION DWStrCurrencySymbol (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SCURRENCY, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================

' ========================================================================================
' Character(s) for the date separator. The maximum number of characters allowed for this
' string is four, including a terminating null character.
' This constant is deprecated. A custom locale might not have a single, uniform separator
' character. For example, a format such as "12/31, 2006" is valid.
' See DWStrShortDateFormatString.
' ========================================================================================
PRIVATE FUNCTION DWStrDateSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SDATE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns the native day name for the specified day (1 = Monday, etc.).
' ========================================================================================
PRIVATE FUNCTION DWStrDayName (BYVAL nDay AS LONG, BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   IF nDay < 1 OR nDay > 7 THEN RETURN ""
   GetLocaleInfoEx(pwszLocale, LOCALE_SDAYNAME1 + nDay - 1, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Character(s) used for the decimal separator, for example, "." in "3.14" or "," in "3,14".
' The maximum number of characters allowed for this string is four, including a terminating
' null character.
' ========================================================================================
PRIVATE FUNCTION DWStrDecimalSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SDECIMAL, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sizes for each group of digits to the left of the decimal. The maximum number of characters
' allowed for this string is ten, including a terminating null character. An explicit size
' is needed for each group, and sizes are separated by semicolons. If the last value is 0,
' the preceding value is repeated. For example, to group thousands, specify 3;0. Indic
' locales group the first thousand and then group by hundreds. For example, 12,34,56,789
' is represented by 3;2;0.
' ========================================================================================
PRIVATE FUNCTION DWStrDigitsGrouping (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SGROUPING, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Primary language name included in a localized display name.
' Deprecated. See DWStrLocalizedDisplayName.
' ========================================================================================
PRIVATE FUNCTION DWStrDisplayName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLANGDISPLAYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Full English name of the country/region.
' ========================================================================================
PRIVATE FUNCTION DWStrEnglishCountryName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SENGCOUNTRY, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' The full English name of the currency associated with the locale.
' ========================================================================================
PRIVATE FUNCTION DWStrEnglishCurrencyName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SENGCURRNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Display name of the locale in English. Usually the display name consists of the language
' and the country/region, for example, German (Germany) for Deutsch (Deutschland).
' ========================================================================================
PRIVATE FUNCTION DWStrEnglishDisplayName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SENGLISHDISPLAYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Full English name of the language from ISO Standard 639.
' ========================================================================================
PRIVATE FUNCTION DWStrEnglishLanguageName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SENGLANGUAGE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Three characters of the international monetary symbol specified in ISO 4217, followed by
' the character separating this string from the amount. The maximum number of characters
' allowed for this string is nine, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrInternationalMonetarySymbol (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SINTLSYMBOL, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' The abbreviated name of the language based entirely on the ISO Standard 639 values, in
' lowercase form, for example, "en" for English. The maximum number of characters allowed
' for this string is nine, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrISO639LanguageName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SISO639LANGNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Three-letter ISO language name, in lowercase form (ISO 639-2 three-letter code for the
' language), for example, "eng" for English. The maximum number of characters allowed for
' this string is nine, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrISO639LanguageName2 (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SISO639LANGNAME2, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Country/region name, based on ISO Standard 3166, for example, "US" for the United States.
' The maximum number of characters allowed for this string is nine, including a terminating
' null character.
' ========================================================================================
PRIVATE FUNCTION DWStrISO3166CountryName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SISO3166CTRYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Three-letter ISO region name (ISO 3166 three-letter code for the country/region), for
' example, "USA" for the United States. The maximum number of characters allowed for this
' string is nine, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrISO3166CountryName2 (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SISO3166CTRYNAME2, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Full localized name of the language.
' Deprecated. See DWStrLocalizedLanguageName.
' ========================================================================================
PRIVATE FUNCTION DWStrLanguageName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLANGUAGE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Character(s) used to separate list items, for example, a comma is used in many locales.
' The maximum number of characters allowed for this string is four, including a
' terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrListItemsSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLIST, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Locale name, a multi-part tag to uniquely identify the locale.
' The maximum number of characters allowed for this string is 85, including a terminating
' null character. The tag is based on the language tagging conventions of RFC 4646.
' ========================================================================================
PRIVATE FUNCTION DWStrLocaleName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Full localized name of the country/region, for example, Deutschland for Germany.
' The maximum number of characters allowed for this string is 80, including a terminating
' null character. Since this name is based on the localization of the product, it changes
' for each localized version.
' ========================================================================================
PRIVATE FUNCTION DWStrLocalizedCountryName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLOCALIZEDCOUNTRYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Windows 7 and later: Full localized name of the locale for the user interface language,
' for example, Deutsch (Deutschland) for German (Germany)" There is no limit on the number
' of characters allowed for this string. Since this name is based on the localization of
' the product, it changes for each localized version.
' ========================================================================================
PRIVATE FUNCTION DWStrLocalizedDisplayName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLOCALIZEDDISPLAYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Full localized primary name of the user interface language included in a localized
' display name, for example, Deutsch representing German. Since this name is based on the
' localization of the product, it changes for each localized version.
' ========================================================================================
PRIVATE FUNCTION DWStrLocalizedLanguageName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLOCALIZEDDISPLAYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Long date formatting string for the locale. The maximum number of characters allowed for
' this string is 80, including a terminating null character. The string can consist of a
' combination of day, month, year, and era format pictures and any string of characters
' enclosed in single quotes. Characters in single quotes remain as specified. For example,
' the Spanish (Spain) long date is "dddd, dd' de 'MMMM' de 'yyyy". Locales can define
' multiple long date formats.
' ========================================================================================
PRIVATE FUNCTION DWStrLongDateFormatString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SLONGDATE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Character(s) used as the monetary decimal separator. The maximum number of characters
' allowed for this string is four, including a terminating null character. For example,
' if a monetary amount is displayed as "$3.40", just as "three dollars and forty cents"
' is displayed in the United States, then the monetary decimal separator is ".".
' ========================================================================================
PRIVATE FUNCTION DWStrMonetaryDecimalSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SMONDECIMALSEP, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sizes for each group of monetary digits to the left of the decimal. The maximum number
' of characters allowed for this string is ten, including a terminating null character.
' An explicit size is needed for each group, and sizes are separated by semicolons. If the
' last value is 0, the preceding value is repeated. For example, to group thousands,
' specify 3;0. Indic languages group the first thousand and then group by hundreds. For
' example 12,34,56,789 is represented by 3;2;0.
' ========================================================================================
PRIVATE FUNCTION DWStrMonetaryGrouping (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SMONGROUPING, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Character(s) used as the monetary separator between groups of digits to the left of the
' decimal. The maximum number of characters allowed for this string is four, including a
' terminating null character. Typically, the groups represent thousands. However, depending
' on the value specified for LOCALE_SMONGROUPING, they can represent something else.
' ========================================================================================
PRIVATE FUNCTION DWStrMonetaryThousandsSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SMONTHOUSANDSEP, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Format string for displaying only the month and the day. The formatting is similar to
' that defined for LOCALE_SLONGDATE. For example, if the month/day pattern is the full
' month name followed by the day number with leading zeros, as in "September 03", the
' format string is "MMMM dd". The string can consist of a combination of day and month
' format pictures and any string of characters enclosed in single quotes.
' Characters in single quotes remain as specified, for example, 'de' for Spanish (Spain).
' A locale can specify only one month/day format.
' ========================================================================================
PRIVATE FUNCTION DWStrMonthDayFormatString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SMONTHDAY, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns the native month name for the specified month.
' ========================================================================================
PRIVATE FUNCTION DWStrMonthName (BYVAL nMonth AS LONG, BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   IF nMonth < 1 OR nMonth > 12 THEN RETURN ""
   GetLocaleInfoEx(pwszLocale, LOCALE_SMONTHNAME1 + nMonth - 1, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' String value for "Not a number", for example, "Nan" for the English (United States) locale.
' There is no limit on the number of characters allowed for this string.
' ========================================================================================
PRIVATE FUNCTION DWStrNanString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM nLen AS LONG, wstrBuf AS DWSTRING
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SNAN, BYVAL NULL, 0)
   IF nLen = 0 THEN RETURN ""
   wstrBuf = WSPACE(nLen)
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SNAN, STRPTR(wstrBuf), nLen)
   RETURN RTRIM(wstrBuf)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Native name of the country/region, for example, España for Spain. The maximum number of
' characters allowed for this string is 80, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrNativeCountryName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNATIVECTRYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' The native name of the currency associated with the locale, in the native language of
' the locale. There is no limit on the number of characters allowed for this string.
' ========================================================================================
PRIVATE FUNCTION DWStrNativeCurrencyName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNATIVECURRNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Native equivalents of ASCII 0 through 9. The maximum number of characters allowed for
' this string is eleven, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrNativeDigits (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNATIVEDIGITS, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Display name of the locale in its native language, for example, Deutsch (Deutschland)
' for the locale German (Germany).
' ========================================================================================
PRIVATE FUNCTION DWStrNativeDisplayName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNATIVEDISPLAYNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Native name of the language. The maximum number of characters allowed for this string
' is 80, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrNativeLanguageName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNATIVELANGNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' String value for "negative infinity", for example, "-Infinity" for the English (United
' States) locale. There is no limit on the number of characters allowed for this string.
' ========================================================================================
PRIVATE FUNCTION DWStrNegativeInfinityString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM nLen AS LONG, wstrBuf AS DWSTRING
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SNEGINFINITY, NULL, 0)
   IF nLen = 0 THEN RETURN ""
   wstrBuf = WSPACE(nLen)
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SNEGINFINITY, STRPTR(wstrBuf), nLen)
   RETURN RTRIM(wstrBuf)
END FUNCTION
' ========================================================================================
' ========================================================================================
' String value for the negative sign, for example, "-" for the English (United States) locale.
' The maximum number of characters allowed for this string is five, including a terminating
' null character.
' ========================================================================================
PRIVATE FUNCTION DWStrNegativeSign (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SNEGATIVESIGN, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' OpenType language tag used to retrieve culturally appropriate typographic features from a font.
' ========================================================================================
PRIVATE FUNCTION DWStrOpenTypeLanguageTag (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SOPENTYPELANGUAGETAG, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Symbol used to indicate the permille (U+2030) symbol, that is, ‰.
' ========================================================================================
PRIVATE FUNCTION DWStrPermilleSymbol (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SPERMILLE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Windows Vista and later: String value for "positive infinity", for example, "Infinity"
' for the English (United States) locale. There is no limit on the number of characters
' allowed for the string.
' ========================================================================================
PRIVATE FUNCTION DWStrPositiveInfinityString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM nLen AS LONG, wstrBuf AS DWSTRING
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SPOSINFINITY, BYVAL NULL, 0)
   IF nLen = 0 THEN RETURN ""
   wstrBuf = WSPACE(nLen)
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SPOSINFINITY, STRPTR(wstrBuf), nLen)
   RETURN RTRIM(wstrBuf)
END FUNCTION
' ========================================================================================
' ========================================================================================
' String value for the positive sign, for example, "+" for the English (United States)
' locale. The maximum number of characters allowed for this string is five, including a
' terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrPositiveSign (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SPOSITIVESIGN, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' A string representing a list of scripts, using the 4-character notation used in ISO 15924.
' Each script name consists of four Latin characters and the list is arranged in alphabetical
' order with each name, including the last, followed by a semicolon.
' ========================================================================================
PRIVATE FUNCTION DWStrScriptsList (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM nLen AS LONG, wstrBuf AS DWSTRING
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SSCRIPTS, BYVAL NULL, 0)
   IF nLen = 0 THEN RETURN ""
   wstrBuf = WSPACE(nLen)
   nLen = GetLocaleInfoEx(pwszLocale, LOCALE_SSCRIPTS, STRPTR(wstrBuf), nLen)
   RETURN RTRIM(wstrBuf)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Short date formatting string for the locale. The maximum number of characters allowed
' for this string is 80, including a terminating null character. The string can consist of
' a combination of day, month, year, and era format pictures. For example, "M/d/yyyy"
' indicates that September 3, 2004 is written 9/3/2004.
' ========================================================================================
PRIVATE FUNCTION DWStrShortDateFormatString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SSHORTDATE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Short native name of the specified day of the week.
' ========================================================================================
PRIVATE FUNCTION DWStrShortestDayName (BYVAL nDay AS LONG, BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   IF nDay < 1 OR nDay > 7 THEN RETURN ""
   GetLocaleInfoEx(pwszLocale, LOCALE_SSHORTESTDAYNAME1 + nDay - 1, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Short time formatting string for the locale. Patterns are typically derived by removing
' the "ss" (seconds) value from the long time format pattern.
' For example, if the long time format is "h:mm:ss tt", the short time format is most
' likely "h:mm tt". This constant can specify multiple formats in a semicolon-delimited
' list. However, the preferred short time format should be the first value listed.
' ========================================================================================
PRIVATE FUNCTION DWStrShortTimeFormatString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SSHORTTIME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Name of the locale to use for sorting or casing behavior.
' ========================================================================================
PRIVATE FUNCTION DWStrSortLocale (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SSORTLOCALE, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' The full localized name of the sort for the specified locale identifier, dependent on
' the language of the shell. This constant is used to determine casing and sorting behavior.
' ========================================================================================
PRIVATE FUNCTION DWStrSortName (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SSORTNAME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Characters that are used to separate groups of digits to the left of the decimal. The
' maximum number of characters allowed for this string is four, including a terminating
' null character. Typically, these groups represent thousands. However, depending on the
' value specified for LOCALE_SGROUPING, they can represent something else.
' ========================================================================================
PRIVATE FUNCTION DWStrThousandsSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_STHOUSAND, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Time formatting strings for the locale. The maximum number of characters allowed for
' this string is 80, including a terminating null character. The string can consist of a
' combination of hour, minute, and second format pictures.
' ========================================================================================
PRIVATE FUNCTION DWStrTimeFormatString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_STIMEFORMAT, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' Character(s) for the time separator. The maximum number of characters allowed for this
' string is four, including a terminating null character.
' ========================================================================================
PRIVATE FUNCTION DWStrTimeSeparator (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_STIME, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================
' ========================================================================================
' The year-month formatting string for the locale. The maximum number of characters allowed
' for this string is 80, including a terminating null character. This string shows the
' proper format for a date string that contains only the year and the month, using format
' pictures as defined in Day, Month, Year, and Era Format Pictures.
' ========================================================================================
PRIVATE FUNCTION DWStrYearMonthFormatString (BYVAL pwszLocale AS WSTRING PTR = LOCALE_NAME_USER_DEFAULT) AS DWSTRING
   DIM wszBuf AS WSTRING * 260
   GetLocaleInfoEx(pwszLocale, LOCALE_SYEARMONTH, wszBuf, SIZEOF(wszBuf)\2)
   RETURN wszBuf
END FUNCTION
' ========================================================================================

#endif


' ########################################################################################
'                                      LINKED LIST
' ########################################################################################

' Usage example:
' // Build the linked list
' DIM List AS DWStrList PTR = NEW DWStrList
' List->Add("Result 1")
' List->Add("Result 2")
' List->Add("Result 3")
' List->Insert(1, "New string")
' List->Replace(2, "Replaced string")
' // Retrieve and print the results
' FOR i AS LONG = 1 TO List->Count
'    PRINT List->Item(i)
' NEXT
' // Delete the list
' Delete List

'TYPE DWStrNode
'   dws AS DWSTRING
'   pNext AS DWStrNode PTR
'   pPrev AS DWStrNode PTR
'   DECLARE DESTRUCTOR
'END TYPE

'DESTRUCTOR DWStrNode
''   OutputDebugStringW "DWStrNode destructor"
'END DESTRUCTOR

'TYPE DWStrList
'   head AS DWStrNode PTR
'   tail AS DWStrNode PTR
'   nodes AS LONG ' number of nodes
'   DIM rgIdx(ANY) AS DWStrNode PTR ' array for indexed access
'   DECLARE DESTRUCTOR
'   DECLARE FUNCTION Add (BYREF dws AS DWSTRING) AS LONG
'   DECLARE FUNCTION Count () AS LONG
'   DECLARE FUNCTION Item (BYVAL idx AS LONG) AS DWSTRING
'   DECLARE FUNCTION Remove (BYVAL idx AS LONG) AS BOOLEAN
'   DECLARE FUNCTION Insert (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
'   DECLARE FUNCTION Replace (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
'   DECLARE SUB Clear
'END TYPE

'PRIVATE DESTRUCTOR DWStrList
''   OutputDebugStringW "DWStrList destructor"
'   ' // Delete all the nodes
'   FOR i AS LONG = LBOUND(rgIdx) TO UBOUND(rgIdx)
'      Delete rgIdx(i)
'   NEXT
'   ' // Erase array of indexes
'   ERASE rgIdx
'END DESTRUCTOR

'PRIVATE SUB DWStrList.Clear
''   OutputDebugStringW "DWStrList Clear"
'   FOR i AS LONG = LBOUND(rgIdx) TO UBOUND(rgIdx)
'      Delete rgIdx(i)
'   NEXT
'   ERASE rgIdx
'   head = NULL
'   tail = NULL
'   nodes = 0
'END SUB

'   ' Add a new DWSTRING to the list
'PRIVATE FUNCTION DWStrList.Add (BYREF dws AS DWSTRING) AS LONG
'   DIM newNode AS DWStrNode PTR = NEW DWStrNode
'   newNode->dws = dws
'   newNode->pNext = NULL
'   newNode->pPrev = tail ' Link new node to the current tail
'   IF tail <> NULL THEN
'      tail->pNext = newNode
'   ELSE
'      head = newNode
'   END IF
'   tail = newNode
'   ' Update rgIdx
'   nodes += 1
'   REDIM PRESERVE rgIdx(nodes - 1)
'   rgIdx(nodes - 1) = newNode
'   RETURN nodes
'END FUNCTION

'' Get the number of nodes
'PRIVATE FUNCTION DWStrList.Count () AS LONG
'   RETURN nodes
'END FUNCTION

'PRIVATE FUNCTION DWStrList.Item (BYVAL idx AS LONG) AS DWSTRING
'   idx -= 1   ' make it one-based
'   IF idx >= 0 AND idx < nodes THEN
'      RETURN rgIdx(idx)->dws
'   END IF
'   RETURN ""
'END FUNCTION

'' Remove a node by index
'PRIVATE FUNCTION DWStrList.Remove (BYVAL idx AS LONG) AS BOOLEAN
'   idx -= 1   ' make it one-based
'   IF idx < 0 OR idx >= nodes THEN RETURN FALSE ' Prevent out-of-bounds deletion
'   DIM current AS DWStrNode PTR = rgIdx(idx) ' Get node from rgIdx array
'   IF current = NULL THEN RETURN FALSE ' Invalid rgIdx
'   ' Adjust pointers for linked list integrity
'   IF current->pPrev <> NULL THEN
'      current->pPrev->pNext = current->pNext
'   ELSE
'      head = current->pNext ' Update head if first node is removed
'   END IF
'   IF current->pNext <> NULL THEN
'      current->pNext->pPrev = current->pPrev
'   ELSE
'      tail = current->pPrev ' Update tail if last node is removed
'   END IF
'   ' Remove from rgIdx array
'   FOR i AS INTEGER = idx TO nodes - 2
'      rgIdx(i) = rgIdx(i + 1) ' Shift elements down
'   NEXT
'   REDIM PRESERVE rgIdx(nodes - 2) ' Resize rgIdx array
'   nodes -= 1
'   DELETE current ' Free memory
'   RETURN TRUE
'END FUNCTION

'PRIVATE FUNCTION DWStrList.Replace (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
'   idx -= 1   ' make it one-based
'   IF idx >= 0 AND idx < nodes THEN
'      rgIdx(idx)->dws = dws
'      RETURN TRUE
'   END IF
'   RETURN FALSE
'END FUNCTION

'PRIVATE FUNCTION DWStrList.Insert (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
'   idx -= 1
'   IF idx < 0 OR idx > nodes THEN RETURN FALSE ' Out of bounds
'   DIM newNode AS DWStrNode PTR = NEW DWStrNode
'   newNode->dws = dws
'   IF idx = nodes THEN
'      this.Add(dws) ' Insert at tail behaves like Add
'      RETURN TRUE
'   END IF
'   DIM current AS DWStrNode PTR = rgIdx(idx)
'   newNode->pNext = current
'   newNode->pPrev = current->pPrev
'   IF current->pPrev <> NULL THEN
'      current->pPrev->pNext = newNode
'   ELSE
'      head = newNode ' Inserting at head
'   END IF
'   current->pPrev = newNode
'   ' Update rgIdx array
'   REDIM PRESERVE rgIdx(nodes)
'   FOR i AS LONG = nodes TO idx + 1 STEP -1
'      rgIdx(i) = rgIdx(i - 1)
'   NEXT
'   rgIdx(idx) = newNode
'   nodes += 1
'   RETURN TRUE
'END FUNCTION
' ########################################################################################

TYPE DWStrNode
   dws AS DWSTRING
   pNext AS DWStrNode PTR
   DECLARE DESTRUCTOR
END TYPE

DESTRUCTOR DWStrNode
END DESTRUCTOR

TYPE DWStrList
   head AS DWStrNode PTR
   tail AS DWStrNode PTR
   nodes AS LONG
   DIM rgIdx(ANY) AS DWStrNode PTR
   DECLARE DESTRUCTOR
   DECLARE FUNCTION Add (BYREF dws AS DWSTRING) AS LONG
   DECLARE FUNCTION Count () AS LONG
   DECLARE FUNCTION Item (BYVAL idx AS LONG) AS DWSTRING
   DECLARE FUNCTION Remove (BYVAL idx AS LONG) AS BOOLEAN
   DECLARE FUNCTION Insert (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
   DECLARE FUNCTION Replace (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
   DECLARE SUB Clear
END TYPE

PRIVATE DESTRUCTOR DWStrList
   FOR i AS LONG = LBOUND(rgIdx) TO UBOUND(rgIdx)
      DELETE rgIdx(i)
   NEXT
   ERASE rgIdx
END DESTRUCTOR

PRIVATE SUB DWStrList.Clear
   FOR i AS LONG = LBOUND(rgIdx) TO UBOUND(rgIdx)
      DELETE rgIdx(i)
   NEXT
   ERASE rgIdx
   head = NULL
   tail = NULL
   nodes = 0
END SUB

PRIVATE FUNCTION DWStrList.Add (BYREF dws AS DWSTRING) AS LONG
   DIM newNode AS DWStrNode PTR = NEW DWStrNode
   newNode->dws = dws
   newNode->pNext = NULL
   IF tail <> NULL THEN
      tail->pNext = newNode
   ELSE
      head = newNode
   END IF
   tail = newNode
   nodes += 1
   REDIM PRESERVE rgIdx(nodes - 1)
   rgIdx(nodes - 1) = newNode
   RETURN nodes
END FUNCTION

PRIVATE FUNCTION DWStrList.Count () AS LONG
   RETURN nodes
END FUNCTION

PRIVATE FUNCTION DWStrList.Item (BYVAL idx AS LONG) AS DWSTRING
   idx -= 1
   IF idx >= 0 AND idx < nodes THEN
      RETURN rgIdx(idx)->dws
   END IF
   RETURN ""
END FUNCTION

PRIVATE FUNCTION DWStrList.Replace (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
   idx -= 1
   IF idx >= 0 AND idx < nodes THEN
      rgIdx(idx)->dws = dws
      RETURN TRUE
   END IF
   RETURN FALSE
END FUNCTION

PRIVATE FUNCTION DWStrList.Remove (BYVAL idx AS LONG) AS BOOLEAN
   idx -= 1
   IF idx < 0 OR idx >= nodes THEN RETURN FALSE
   DIM current AS DWStrNode PTR = rgIdx(idx)
   ' Adjust head/tail
   IF head = current THEN head = current->pNext
   IF tail = current THEN
      IF idx > 0 THEN
         tail = rgIdx(idx - 1)
         tail->pNext = NULL
      ELSE
         tail = NULL
      END IF
   ELSE
      rgIdx(idx - 1)->pNext = current->pNext
   END IF
   DELETE current
   FOR i AS LONG = idx TO nodes - 2
      rgIdx(i) = rgIdx(i + 1)
   NEXT
   REDIM PRESERVE rgIdx(nodes - 2)
   nodes -= 1
   RETURN TRUE
END FUNCTION

PRIVATE FUNCTION DWStrList.Insert (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
   idx -= 1
   IF idx < 0 OR idx > nodes THEN RETURN FALSE
   DIM newNode AS DWStrNode PTR = NEW DWStrNode
   newNode->dws = dws
   IF idx = nodes THEN RETURN (Add(dws) > 0)
   DIM prevNode AS DWStrNode PTR = IIF(idx > 0, rgIdx(idx - 1), NULL)
   DIM current AS DWStrNode PTR = rgIdx(idx)
   newNode->pNext = current
   IF prevNode <> NULL THEN
      prevNode->pNext = newNode
   ELSE
      head = newNode
   END IF
   REDIM PRESERVE rgIdx(nodes)
   FOR i AS LONG = nodes TO idx + 1 STEP -1
      rgIdx(i) = rgIdx(i - 1)
   NEXT
   rgIdx(idx) = newNode
   nodes += 1
   RETURN TRUE
END FUNCTION

END NAMESPACE

' ########################################################################################
