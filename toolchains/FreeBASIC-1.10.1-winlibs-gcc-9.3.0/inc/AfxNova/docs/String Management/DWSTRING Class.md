# DWSTRING Class

The `DWSTRING` class implements a dynamic unicode null terminated string. Free Basic has a dynamic string data type (STRING). a fixed-length ansi data type (ZSTRING) and a fixed-length unicode data type (WSTRING), but it lacks a dynamic unicode string. `DWSTRING` behaves as if it was a native data type, working transparently with all of the intrinsic Free Basic string functions and operators (consult the FreeBasic documentation for a list of them and how they work). One important diference is that `VARPTR` and the `@` operator don't return the address of the buffer, but the address of the class. To get the address of the buffer use `STRPTR` or the `*` operator.

**Include file**: AfxNova/DWSTRING.inc.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#constructors) | Initialize the class with the specified value. |
| [Capacity](#capacity) | Gets/sets the size of the internal buffer. |
| [Operator \*](#operator*) | One * returns the address of the `DWSTRING` buffer.<br> Two ** returns the address of the start of the string data. |
| [Operator Cast](#operatorcast) | Returns a pointer to the `DWSTRING` buffer or the string data.<br>Casting is automatic. You don't have to call this operator. |
| [ChrW](#chrw) | Returns a wide-character string from a codepoint. |
| [bstr](#bstr) | Returns the contents of the `DWSTRING` as a `BSTR`. |
| [OEM](#oem) | Converts from Unicode to OEM code page. |
| [Utf8](#utf8) | Converts from UTF8 to Unicode and from Unicode to UTF8. |
| [vptr](#vptr) | Returns the address of the string buffer. |
| [wchar](#wchar) | Returns the string data as a new unicode string allocated with **CoTaskMemAlloc**. |
| [JScript](#jscript) | Converts the DWSTRING content into a safe JavaScript expression for use with WebView2 ExecuteScript. |

# <a name="constructors"></a>Constructors

```
CONSTRUCTOR
CONSTRUCTOR (BYREF wszStr AS CONST WSTRING)
CONSTRUCTOR (BYVAL pwszStr AS WSTRING PTR)
CONSTRUCTOR (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0)
CONSTRUCTOR (BYREF dws AS DWSTRING)
CONSTRUCTOR (BYREF bs AS BSTRING)
CONSTRUCTOR (BYVAL nChars AS LONG, BYREF wszFill AS CONST WSTRING)
CONSTRUCTOR (BYVAL n AS LONGINT)
CONSTRUCTOR (BYVAL n AS DOUBLE)
```
1. Creates an empty Unicode string buffer with an initial null-terminated string.
```
Example: DIM dws AS DWSTRING
```
2. Initializes a `DWSTRING` instance from a wide string pointer.
```
DIM wsz AS WSTRING * 30 = "This is a test string"
DIM dwsText AS DWSTRING = wsz
```
3. Initializes a `DWSTRING` from an ANSI or UTF-8 encoded string, with optional code page support.
```
Example: DIM s AS STRING = "Hello, world"
         DIM dws AS DWSTRING = s
Example: DIM dws AS DWSTRING = DWSTRING("Hello, utf", CP_UTF8)
```
For a list of code pages see: [Code Page Identifiers](https://msdn.microsoft.com/en-us/library/windows/desktop/dd317756(v=vs.85).aspx)

5. Creates a copy of an existing `DWSTRING`.
```
Example: DIM dws1 AS DWSTRING = "Test string"
         DIM dws2 AS DWSTRING = dws1
```
6. Creates a `DWSTRING` with a fixed-length buffer, initialized with a fill character.
```
Example: DIM dws AS DWSTRING = DWSTRING(260, " ")
```
7. Initializes a `DWSTRING` with a numeric value, allowing automatic conversion.
```
Example: DIM dwsNum AS DWSTRING = 12345
Example: DIM dwsFloat AS DWSTRING = 3.1415
```

#### Remarks

`DWSTRING` works transparently with literals and Free Basic native strings, e.g.
```
DIM dws AS DWSTRING = "One"
DIM s AS STRING = "Three"
dws = dws & " Two " & s
PRINT dws
```
It can be used with Windows API functions, e.g.
```
DIM nLen AS LONG = SendMessageW(hwnd, WM_GETTEXTLENGTH, 0, 0)
DIM dwsText AS DWSTRING = WSPACE(nLen + 1)
SendMessageW(hwnd, WM_GETTEXT, nLen + 1, cast(LPARAM, *cwsText))
dwsText = LEFT(dwsText, LEN(dwsText) - 1)
PRINT dwsText
```
We can use arrays of `DWSTRING` strings transparently, e.g.
```
DIM rg(1 TO 10) AS DWSTRING
FOR i AS LONG = 1 TO 10
   rg(i) = "string " & i
NEXT
FOR i AS LONG = 1 TO 10
   PRINT rg(i)
NEXT
```
A two-dimensional array
```
DIM rg2 (1 TO 2, 1 TO 2) AS DWSTRING
rg2(1, 1) = "string 1 1"
rg2(1, 2) = "string 1 2"
rg2(2, 1) = "string 2 1"
rg2(2, 2) = "string 2 2"
PRINT rg2(2, 1)
```

REDIM PRESERVE / ERASE
```
REDIM rg(0) AS DWSTRING
rg(0) = "string 0"
REDIM PRESERVE rg(0 TO 2) AS DWSTRING
rg(1) = "string 1"
rg(2) = "string 2"
PRINT rg(0)
PRINT rg(1)
PRINT rg(2)
ERASE rg
```
You can also use it with files:

Using FreeBasic intrinsic statements:
```
DIM dws AS DWSTRING = "Дмитрий Дмитриевич Шостакович"
DIM f AS LONG = FREEFILE
OPEN "Test.txt" FOR OUTPUT ENCODING "utf16" AS #f
PRINT #f, dws
CLOSE #f
```
Using the Windows API:
```
' // Writing to a file
DIM dwsFilename AS DWSTRING = "тест.txt"
DIM dwsText AS DWSTRING = "Дмитрий Дмитриевич Шостакович"
DIM hFile AS HANDLE = CreateFileW(dwsFilename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
IF hFile THEN
   DIM dwBytesWritten AS DWORD
   DIM bSuccess AS LONG = WriteFile(hFile, dwsText, LEN(dwsText) * 2, @dwBytesWritten, NULL)
   CloseHandle(hFile)
END IF
```
```
' // Read the file
hFile = CreateFileW(dwsFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL)
IF hFile THEN
   DIM dwFileSize AS DWORD = GetFileSize(hFile, NULL)
   IF dwFileSize THEN
      DIM dwsOut AS DWSTRING = WSPACE(dwFileSize \ 2)
      DIM bSuccess AS LONG = ReadFile(hFile, *dwsOut, dwFileSize, NULL, NULL)
      CloseHandle(hFile)
      PRINT dwsOut
   END IF
END IF
```

Notice that, contrarily to **CreateFileW**, FreeBasic's OPEN statement doesn't allow to use unicode for the file name.

---

# Operators

### <a name="operator*"></a>Operator *

Dereferences the `DWSTRING`.<br>One * returns the address of the `DWSTRING` buffer.<br>Two ** returns the address of the start of the string data.

```
OPERATOR * (BYREF dws AS DWSTRING) AS WSTRING PTR
```
---

# Casting and Conversions

### <a name="operatorcast"></a>Operator Cast

```
OPERATOR CAST () BYREF AS CONST WSTRING
OPERATOR CAST () AS ANY PTR
```

Returns a pointer to the `DWSTRING` buffer or the string data. These operators aren't called directly.

---

### <a name="bstr"></a>bstr

Returns the contents of the `DWSTRING` as a BSTR.

```
FUNCTION bstr () AS BSTR
```
---

### <a name="oem"></a>OEM

Converts from Unicode to OEM code page and from OEM to Unicode.

```
PROPERTY OEM () AS STRING
PROPERTY OEM (BYREF OEMString AS STRING)
```
---

### <a name="utf8"></a>Utf8

Converts from UTF8 to Unicode and from Unicode to UTF8.

```
PROPERTY Utf8() AS STRING
PROPERTY Utf8 (BYREF utf8String AS STRING)
```
---

### <a name="vptr"></a>vptr

Returns the address of the string buffer.

```
FUNCTION vptr () AS WSTRING PTR
```
---

### <a name="wchar"></a>wchar

Returns the string data as a new unicode string allocated with **CoTaskMemAlloc**.

```
FUNCTION wchar () AS WSTRING PTR
```

Useful when we need to pass a pointer to a null terminated wide string to a function or method that will release it. If we pass a WSTRING it will GPF. If the length of the input string is 0, **CoTaskMemAlloc** allocates a zero-length item and returns a valid pointer to that item. If there is insufficient memory available, **CoTaskMemAlloc** returns NULL.

---

# Methods

### <a name="capacity"></a>Capacity

Gets/sets the size of the internal buffer. The size is the number of bytes which can be stored without further expansion.

```
PROPERTY Capacity() AS UINT
PROPERTY Capacity (BYVAL nValue AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nValue* | The new capacity value, in bytes. If the new capacity is equal to the current capacity, no operation is performed; is it is smaller, the buffer is shortened and the contents that exceed the new capacity are lost. If you pass an odd number, 1 is added to the value to make it even. |

---

### <a name="chrw"></a>ChrW

Returns a wide-character string from a codepoint. If the codepoint is higher than 65535, the value returned a surrogate pair.

```
FUNCTION ChrW (BYVAL codePoint AS UInteger) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *codepoint* | The code point. |

---

### <a name="jscript"></a>JScript

Converts the `DWSTRING` content into a safe JavaScript expression for use with `WebView2` **ExecuteScript**.

```
PROPERTY DWSTRING.JScript () AS STRING
```

`WebView2` requires UTF-8 text when passing strings to JavaScript. This property takes the internal UTF-8 byte sequence of the `DWSTRING` and generates a JavaScripy expression of the form:
```
new TextDecoder('utf-8').decode(Uint8Array.from([b1,b2,b3,...]))
```
This guarantees that any Unicode text (including accents, symbols and emojis) is transmitted correctly to JavaScript without escaping issues, broken quotes, or encoding mismatches.

The user can therefore pass `DWSTRING` values directly to **ExecuteScript** without worrying about UTF-8 handling or manual escaping.

#### Usage example:

```
m_pWebView->ExecuteScript("console.log(" & myString.JScript & ");")
```

#### Notes

The returned value is valid JavaScript code, not a literal string.

---
