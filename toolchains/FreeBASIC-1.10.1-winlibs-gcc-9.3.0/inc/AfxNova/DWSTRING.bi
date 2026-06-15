' ########################################################################################
' Platform: Microsoft Windows
' Filename: DWSTRING.bi
' Purpose:  Implements a dynamic unicode string data type
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
#INCLUDE ONCE "/crt/string.bi"
#INCLUDE ONCE "/crt/wchar.bi"
#INCLUDE ONCE "utf_conv.bi"
#INCLUDE ONCE "win/Ole2.bi"
#INCLUDE ONCE "/fbc-int/array.bi"
USING FBC

' ========================================================================================
' Macro for debug
' To allow debugging, define _DWSTRING_DEBUG_ 1 in your application before including this file.
' To capture and display the messages sent by the Windows function OutputDebugStringW, you
' can use the DebugView tool. See: https://learn.microsoft.com/en-us/sysinternals/downloads/debugview
' ========================================================================================
#ifndef _DWSTRING_DEBUG_
   #define _DWSTRING_DEBUG_ 0
#ENDIF
#ifndef _DWSTRING_DP_
   #define _DWSTRING_DP_ 1
   #MACRO DWSTRING_DP(st)
      #IF (_DWSTRING_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

' ========================================================================================
' Macro for debug
' To allow debugging, define _BSTRING_DEBUG_ 1 in your application before including this file.
' To capture and display the messages sent by the Windows function OutputDebugStringW, you
' can use the DebugView tool. See: https://learn.microsoft.com/en-us/sysinternals/downloads/debugview
' ========================================================================================
#ifndef _BSTRING_DEBUG_
   #define _BSTRING_DEBUG_ 0
#ENDIF
#ifndef _BSTRING_DP_
   #define _BSTRING_DP_ 1
   #MACRO BSTRING_DP(st)
      #IF (_BSTRING_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

' // The definition for BSTR in the FreeBASIC headers was inconveniently changed to WCHAR
#ifndef AFX_BSTR
   #define AFX_BSTR WSTRING PTR
#endif

NAMESPACE AfxNova

' // Forward reference declarations
TYPE DWSTRING_ AS DWSTRING
TYPE BSTRING_ AS BSTRING

' ########################################################################################
'                                *** DWSTRING CLASS ***
' ########################################################################################

TYPE DWSTRING EXTENDS WSTRING

   ' // Don't change the order of these variables
   m_pBuffer AS WSTRING PTR   ' // Pointer to the buffer
   m_BufferLen AS ssize_t     ' // Length in UTF16 characters of the buffer
   m_Capacity AS ssize_t      ' // The total size of the buffer in UTF16 characters

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYREF wszStr AS CONST WSTRING)
   DECLARE CONSTRUCTOR (BYVAL pwszStr AS WSTRING PTR)
   DECLARE CONSTRUCTOR (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0)
   DECLARE CONSTRUCTOR (BYREF dws AS DWSTRING)
   DECLARE CONSTRUCTOR (BYREF bs AS BSTRING_)
   DECLARE CONSTRUCTOR (BYVAL nChars AS LONG, BYREF wszFill AS CONST WSTRING)
   DECLARE CONSTRUCTOR (BYVAL n AS LONGINT)
   DECLARE CONSTRUCTOR (BYVAL n AS DOUBLE)
   DECLARE DESTRUCTOR
   DECLARE PROPERTY Capacity () AS UINT
   DECLARE PROPERTY Capacity (BYVAL nValue AS UINT)
   DECLARE FUNCTION Add (BYVAL pwszStr AS WSTRING PTR) AS BOOLEAN
   DECLARE FUNCTION Add (BYREF ansiStr AS STRING, BYVAL nCodePage AS UINT = 0) AS BOOLEAN
   DECLARE FUNCTION Add (BYREF dws AS DWSTRING) AS BOOLEAN
   DECLARE FUNCTION ResizeBuffer (BYVAL nChars AS UINT, BYVAL bClear AS BOOLEAN = FALSE) AS WSTRING PTR
   DECLARE FUNCTION AppendBuffer (BYVAL memAddr AS ANY PTR, BYVAL nChars AS UINT) AS BOOLEAN
   DECLARE FUNCTION GetBuffer () AS WSTRING PTR
   DECLARE SUB Clear
   DECLARE FUNCTION IsUtf8 (BYREF s AS STRING) AS BOOLEAN
   DECLARE OPERATOR [] (BYVAL nIndex AS UINT) BYREF AS USHORT
   DECLARE OPERATOR CAST () BYREF AS CONST WSTRING
   DECLARE OPERATOR CAST () AS ANY PTR
   DECLARE OPERATOR LET (BYREF wszStr AS WSTRING)
   DECLARE OPERATOR LET (BYVAL pwszStr AS WSTRING PTR)
   DECLARE OPERATOR LET (BYREF ansiStr AS STRING)
   DECLARE OPERATOR LET (BYREF dws AS DWSTRING)
   DECLARE OPERATOR LET (BYREF bs AS BSTRING_)
   DECLARE OPERATOR LET (BYVAL n AS LONGINT)
   DECLARE OPERATOR LET (BYVAL n AS DOUBLE)
   DECLARE OPERATOR += (BYVAL pwszStr AS WSTRING PTR)
   DECLARE OPERATOR += (BYREF dws AS DWSTRING)
   DECLARE OPERATOR += (BYREF bs AS BSTRING_)
   DECLARE OPERATOR += (BYREF ansiStr AS STRING)
   DECLARE OPERATOR += (BYVAL n AS LONGINT)
   DECLARE OPERATOR += (BYVAL n AS DOUBLE)
   DECLARE OPERATOR &= (BYREF wszStr AS WSTRING)
   DECLARE OPERATOR &= (BYREF dws AS DWSTRING)
   DECLARE OPERATOR &= (BYREF bs AS BSTRING_)
   DECLARE OPERATOR &= (BYREF ansiStr AS STRING)
   DECLARE OPERATOR &= (BYVAL n AS LONGINT)
   DECLARE OPERATOR &= (BYVAL n AS DOUBLE)
   DECLARE FUNCTION ChrW (BYVAL codepoint AS UInteger) AS DWSTRING
   DECLARE FUNCTION vptr () AS WSTRING PTR
   DECLARE FUNCTION sptr () AS WSTRING PTR
   DECLARE FUNCTION bstr () AS ..BSTR
   DECLARE PROPERTY utf8 () AS STRING
   DECLARE PROPERTY utf8 (BYREF utf8String AS STRING)
   DECLARE FUNCTION wchar () AS WSTRING PTR
   DECLARE PROPERTY OEM () AS STRING
   DECLARE PROPERTY OEM (BYREF OEMString AS STRING)
   DECLARE PROPERTY JScript () AS STRING

Private:
   DECLARE FUNCTION ScanForSurrogates (BYVAL memAddr AS WSTRING PTR, BYVAL nChars AS LONG, BYVAL searchBrokenOnly AS BOOLEAN = TRUE) AS LONG
   
END TYPE
' ########################################################################################

' ########################################################################################
'                                *** BSTRING CLASS ***
' ########################################################################################
TYPE BSTRING EXTENDS WSTRING

Public:
   m_bstr AS BSTR   ' // The BSTR handle

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYREF bs AS BSTRING)
   DECLARE CONSTRUCTOR (BYREF dws AS DWSTRING)
   DECLARE CONSTRUCTOR (BYREF wszStr AS CONST WSTRING)
'   DECLARE CONSTRUCTOR (BYVAL pwszStr AS WSTRING PTR, BYVAL fAttach AS BOOLEAN = FALSE)
   DECLARE CONSTRUCTOR (BYVAL pwszStr AS WSTRING PTR)
   DECLARE CONSTRUCTOR (BYREF ansiStr AS STRING = "", BYVAL nCodePage AS UINT = 0)
   DECLARE CONSTRUCTOR (BYVAL nChars AS LONG, BYREF wszFill AS CONST WSTRING)
   DECLARE CONSTRUCTOR (BYVAL n AS LONGINT)
   DECLARE CONSTRUCTOR (BYVAL n AS DOUBLE)
   DECLARE DESTRUCTOR
   DECLARE FUNCTION IsUtf8 (BYREF s AS STRING) AS BOOLEAN
   DECLARE SUB Append (BYVAL pwszStr AS WSTRING PTR)
   DECLARE SUB Clear
   DECLARE SUB Attach (BYVAL pbstrSrc AS BSTR)
   DECLARE FUNCTION Detach () AS BSTR
   DECLARE FUNCTION Copy () AS BSTRING
   DECLARE OPERATOR [] (BYVAL nIndex AS UINT) BYREF AS USHORT
   DECLARE OPERATOR CAST () BYREF AS CONST WSTRING
   DECLARE OPERATOR CAST () AS ANY PTR
   DECLARE OPERATOR LET (BYREF bs AS BSTRING)
   DECLARE OPERATOR LET (BYREF dws AS DWSTRING_)
   DECLARE OPERATOR LET (BYREF wsz AS WSTRING)
   DECLARE OPERATOR LET (BYREF s AS STRING)
'   DECLARE OPERATOR LET (BYVAL pwszStr AS WSTRING PTR)
   DECLARE OPERATOR LET (BYVAL n AS LONGINT)
   DECLARE OPERATOR LET (BYVAL n AS DOUBLE)
   DECLARE OPERATOR += (BYVAL pwszStr AS WSTRING PTR)
   DECLARE OPERATOR += (BYREF bs AS BSTRING)
   DECLARE OPERATOR += (BYREF dws AS DWSTRING_)
   DECLARE OPERATOR += (BYREF wsz AS WSTRING)
   DECLARE OPERATOR += (BYREF ansiStr AS STRING)
   DECLARE OPERATOR += (BYVAL n AS LONGINT)
   DECLARE OPERATOR += (BYVAL n AS DOUBLE)
   DECLARE OPERATOR &= (BYVAL pwszStr AS WSTRING PTR)
   DECLARE OPERATOR &= (BYREF bs AS BSTRING)
   DECLARE OPERATOR &= (BYREF dws AS DWSTRING_)
   DECLARE OPERATOR &= (BYREF ansiStr AS STRING)
   DECLARE OPERATOR &= (BYVAL n AS LONGINT)
   DECLARE OPERATOR &= (BYVAL n AS DOUBLE)
   DECLARE FUNCTION vptr () AS BSTR PTR
   DECLARE FUNCTION sptr () AS WSTRING PTR
   DECLARE PROPERTY Utf8 () AS STRING
   DECLARE PROPERTY Utf8 (BYREF utf8String AS STRING)
   DECLARE FUNCTION wchar () AS WSTRING PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Implementation of an indexed double linked-list for the DWSTRING data type
' Usage example:
' 'Function to Create and Return a Pointer to the List
' ----------------------------------------------------------------------------------------
' FUNCTION ProcessData () AS DWSTRING_LIST PTR
'    DIM myList AS DWSTRING_LIST PTR = NEW DWSTRING_LIST
'    ' Simulating result generation
'    myList->AddNode("Result 1")
'    myList->AddNode("Result 2")
'    myList->AddNode("Result 3")
'    ' Return the pointer to the list
'    RETURN myList
' END FUNCTION
' ----------------------------------------------------------------------------------------
' ' Get the results
' DIM myListPtr AS DWSTRING_LIST PTR
' myListPtr = ProcessData()
' ' Retrieve and print the results
' IF myListPtr <> NULL THEN
'    ' Get the number of nodes
'    DIM count AS LONG = myListPtr->Count
'    ' Direct access using 0-based index
'    DIM node AS DWSTRING_NODE PTR
'    node = myListPtr->GetByIndex(1) ' Get second element
'    IF node <> NULL THEN PRINT node->dws
'    ' Delete the list, triggering cleanup automatically
'    Delete myListPtr
' END IF
' ========================================================================================

TYPE DWSTRING_NODE
   dws AS DWSTRING
   pNext AS DWSTRING_NODE PTR
   pPrev AS DWSTRING_NODE PTR
   ' Destructor to clean up memory
   DECLARE DESTRUCTOR
END TYPE

PRIVATE DESTRUCTOR DWSTRING_NODE
END DESTRUCTOR

TYPE DWSTRING_LIST
   head AS DWSTRING_NODE PTR
   tail AS DWSTRING_NODE PTR
   DIM index(ANY) AS DWSTRING_NODE PTR ' Array for indexed access
   count AS LONG ' Number of nodes
   DECLARE SUB AddNode (BYREF newString AS DWSTRING)
   DECLARE FUNCTION GetCount () AS LONG
   DECLARE FUNCTION GetByIndex (BYVAL i AS LONG) AS DWSTRING_NODE PTR
   DECLARE FUNCTION RemoveByIndex (BYVAL index AS LONG) AS BOOLEAN
   ' Destructor: Automatically cleans up when deleted
   DECLARE DESTRUCTOR
END TYPE

PRIVATE DESTRUCTOR DWSTRING_LIST
   DIM current AS DWSTRING_NODE PTR = head
   WHILE current <> NULL
      DIM nextNode AS DWSTRING_NODE PTR = current->pNext
      Delete current
      current = nextNode
   WEND
   ERASE index ' Cleanup index array
END DESTRUCTOR

   ' Add a new DWSTRING to the list
PRIVATE SUB DWSTRING_LIST.AddNode (BYREF newString AS DWSTRING)
   DIM newNode AS DWSTRING_NODE PTR = NEW DWSTRING_NODE
   newNode->dws = newString
   newNode->pNext = NULL
   newNode->pPrev = tail ' Link new node to the current tail
   IF tail <> NULL THEN
      tail->pNext = newNode
   ELSE
      head = newNode
   END IF
   tail = newNode
   ' Update index
   count += 1
   REDIM PRESERVE index(count - 1)
   index(count - 1) = newNode
END SUB

' Get the number of nodes
PRIVATE FUNCTION DWSTRING_LIST.GetCount () AS LONG
   RETURN count
END FUNCTION

' Get node by index
PRIVATE FUNCTION DWSTRING_LIST.GetByIndex (BYVAL idx AS LONG) AS DWSTRING_NODE PTR
   IF idx >= 0 AND idx < count THEN
      RETURN index(idx)
   ELSE
      RETURN NULL ' Out of bounds
   END IF
END FUNCTION

' Remove a node by index
PRIVATE FUNCTION DWSTRING_LIST.RemoveByIndex (BYVAL idx AS LONG) AS BOOLEAN
   IF idx < 0 OR idx >= count THEN RETURN FALSE ' Prevent out-of-bounds deletion
   DIM current AS DWSTRING_NODE PTR = index(idx) ' Get node from index array
   IF current = NULL THEN RETURN FALSE ' Invalid index
   ' Adjust pointers for linked list integrity
   IF current->pPrev <> NULL THEN
      current->pPrev->pNext = current->pNext
   ELSE
      head = current->pNext ' Update head if first node is removed
   END IF
   IF current->pNext <> NULL THEN
      current->pNext->pPrev = current->pPrev
   ELSE
      tail = current->pPrev ' Update tail if last node is removed
   END IF
   ' Remove from index array
   FOR i AS INTEGER = idx TO count - 2
      index(i) = index(i + 1) ' Shift elements down
   NEXT
   REDIM PRESERVE index(count - 2) ' Resize index array
   count -= 1
   DELETE current ' Free memory
   RETURN TRUE
END FUNCTION

END NAMESPACE
