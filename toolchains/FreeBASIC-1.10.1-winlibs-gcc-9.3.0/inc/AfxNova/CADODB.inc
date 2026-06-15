' ########################################################################################
' Platform: Microsoft Windows
' File: CADODB.inc
' Contents: ADO classes
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
#include once "AfxNova/AfxAdo.bi"
#include once "AfxNova/AfxCOM.inc"
#include once "AfxNova/DWSTRING.inc"
#include once "AfxNova/DVARIANT.inc"
USING AfxNova

NAMESPACE AfxNova

' ########################################################################################
' CAdoBase class
' ########################################################################################
TYPE CAdoBase

   DIM m_Result AS HRESULT
   DIM m_bUninitCOM AS BOOLEAN

   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR
   DECLARE FUNCTION GetLastResult () AS HRESULT
   DECLARE FUNCTION SetResult (BYVAL Result AS HRESULT) AS HRESULT

END TYPE
' ########################################################################################

' ========================================================================================
' Default constructor
' ========================================================================================
CONSTRUCTOR CAdoBase
   CADODB_DP("")
   ' // Initialize the COM library
   IF m_bUninitCOM = FALSE THEN
      DIM hr AS HRESULT = CoInitialize(NULL)
      IF hr = S_OK OR hr = S_FALSE THEN m_bUninitCOM = TRUE
   END IF
END CONSTRUCTOR
' ========================================================================================

' ===========================================================================================
' Destructor
' ===========================================================================================
DESTRUCTOR CAdoBase
   CADODB_DP("")
   ' // Free the COM library
   IF m_bUninitCOM THEN CoUninitialize
END DESTRUCTOR
' ===========================================================================================

' ========================================================================================
' Returns the last result
' ========================================================================================
PRIVATE FUNCTION CAdoBase.GetLastResult () AS HRESULT
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the last result code.
' ========================================================================================
PRIVATE FUNCTION CAdoBase.SetResult (BYVAL Result AS HRESULT) AS HRESULT
   m_Result = Result
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ===========================================================================================
' Returns the description of an ADO runtime error
' ===========================================================================================
PRIVATE FUNCTION AfxAdoGetRuntimeErrorInfo (BYVAL wError AS WORD) AS DWSTRING

   DIM dws AS DWSTRING

   SELECT CASE wError
      CASE 3000 ' &HBB8 - %adErrProviderFailed
         dws = "Provider failed to perform the requested operation."
      CASE 3001 ' &HBB9 - %adErrInvalidArgument
         dws = "Arguments are of the wrong type, are out of acceptable range, or are in conflict with one another."
      CASE 3002 ' &HBBA - %adErrOpeningFile
         dws = "File could not be opened."
      CASE 3003 ' &HBBB - %adErrReadFile
         dws = "File could not be read."
      CASE 3004 ' &HBBC - %adErrWriteFile
         dws = "Write to file failed."
      CASE 3021 ' &HBCD - %adErrNoCurrentRecord
         dws = "Either BOF or EOF is True, or the current record has been deleted. Requested operation requires a current record."
      CASE 3219 ' &HC93 - %adErrIllegalOperation
         dws = "Operation is not allowed in this context."
      CASE 3220 ' &HC94 - %adErrCantChangeProvider
         dws = "Supplied provider is different from the one already in use."
      CASE 3246 ' &HCAE - %adErrInTransaction
         dws = "Connection object cannot be explicitly closed while in a transaction."
      CASE 3251 ' &HCB3 - %adErrFeatureNotAvailable
         dws = "Object or provider is not capable of performing requested operation."
      CASE 3265 ' &HCC1 - %adErrItemNotFound
         dws = "Item cannot be found in the collection corresponding to the requested name or ordinal."
      CASE 3367 ' &HD27 - %adErrObjectInCollection
         dws = "Object is already in collection. Cannot append."
      CASE 3420 ' &HD5C - %adErrObjectNotSet
         dws = "Object is no longer valid."
      CASE 3421 ' &HD5D - %adErrDataConversion
         dws = "Application uses a value of the wrong type for the current operation."
      CASE 3704 ' &HE78 - %adErrObjectClosed
         dws = "Operation is not allowed when the object is closed. "
      CASE 3705 ' &HE79 - %adErrObjectOpen
         dws = "Operation is not allowed when the object is open. "
      CASE 3706 ' &HE7A - %adErrProviderNotFound
         dws = "Provider cannot be found. It may not be properly installed."
      CASE 3707 ' &HE7B - %adErrBoundToCommand
         dws = "Cannot change the ActiveConnection property of a Recordset object which has a Command object as its source."
      CASE 3708 ' &HE7C - %adErrInvalidParamInfo
         dws = "Parameter object is improperly defined. Inconsistent or incomplete information was provided."
      CASE 3709 ' &HE7D - %adErrInvalidConnection
         dws = "The connection cannot be used to perform this operation. It is either closed or invalid in this context."
      CASE 3710 ' &HE7E - %adErrNotReentrant
         dws = "Operation cannot be performed while processing event. "
      CASE 3711 ' &HE7F - %adErrStillExecuting
         dws = "Operation cannot be performed while executing asynchronously."
      CASE 3712 ' &HE80 - %adErrOperationCancelled
         dws = "Operation has been cancelled by the user."
      CASE 3713 ' &HE81 - %adErrStillConnecting
         dws = "Operation cannot be performed while connecting aynchronously. "
      CASE 3714 ' &HE82 - %adErrInvalidTransaction
         dws = "Coordinating transaction is invalid or has not started."
      CASE 3715 ' &HE83 - %adErrNotExecuting
         dws = "Operation cannot be performed while not executing."
      CASE 3716 ' &HE84 - %adErrUnsafeOperation
         dws = "Safety settings on this computer prohibit accessing a data source on another domain."
'      CASE 3717 ' &HE85 - %adwrnSecurityDialog
'         For internal use only. Don't use.
'      CASE 3718 ' &HE86 - %adwrnSecurityDialogHeader
'         For internal use only. Don't use.
      CASE 3719 ' &HE87 - %adErrIntegrityViolation
         dws = "Data value conflicts with the integrity constraints of the field."
      CASE 3720 ' &HE88 - %adErrPermissionDenied
         dws = "Insufficent permission prevents writing to the field."
      CASE 3721 ' &HE89 - %adErrDataOverflow
         dws = "Data value is too large to be represented by the field data type."
      CASE 3722 ' &HE8A - %adErrSchemaViolation
         dws = "Data value conflicts with the data type or constraints of the field."
      CASE 3723 ' &HE8B - %adErrSignMismatch
         dws = "Conversion failed because the data value was signed and the field data type used by the provider was unsigned."
      CASE 3724 ' &HE8C - %adErrCantConvertvalue
         dws = "Data value cannot be converted for reasons other than sign mismatch or data overflow. For example, conversion would have truncated data."
      CASE 3725 ' &HE8D - %adErrCantCreate
         dws = "Data value cannot be set or retrieved because the field data type was unknown, or the provider had insufficient resources to perform the operation."
      CASE 3726 ' &HE8E - %adErrColumnNotOnThisRow
         dws = "Record does not contain this field."
      CASE 3727 ' &HE8F - %adErrURLDoesNotExist
         dws = "Either the source URL or the parent of the destination URL does not exist."
      CASE 3728 ' &HE90 - %adErrTreePermissionDenied
         dws = "Permissions are insufficient to access tree or subtree. "
      CASE 3729 ' &HE91 - %adErrInvalidURL
         dws = "URL contains invalid characters. Make sure the URL is typed correctly."
      CASE 3730 ' &HE92 - %adErrResourceLocked
         dws = "Object represented by the specified URL is locked by one or more other processes. Wait until the process has finished and attempt the operation again."
      CASE 3731 ' &HE93 - %adErrResourceExists
         dws = "Copy operation cannot be performed. Object named by destination URL already exists. Specify adCopyOverwrite to replace the object."
      CASE 3732 ' &HE94 - %adErrCannotComplete
         dws = "Server cannot complete the operation."
      CASE 3733 ' &HE95 - %adErrVolumeNotFound
         dws = "Provider cannot locate the storage device indicated by the URL. Make sure the URL is typed correctly."
      CASE 3734 ' &HE96 - %adErrOutOfSpace
         dws = "Operation cannot be performed. Provider cannot obtain enough storage space."
      CASE 3735 ' &HE97 - %adErrResourceOutOfScope
         dws = "Source or destination URL is outside the scope of the current record."
      CASE 3736 ' &HE98 - %adErrUnavailable
         dws = "Operation failed to complete and the status is unavailable. The field may be unavailable or the operation was not attempted."
      CASE 3737 ' &HE99 - %adErrURLNamedRowDoesNotExist
         dws = "Record named by this URL does not exist."
      CASE 3738 ' &HE9A - %adErrDelResOutOfScope
         dws = "URL of the object to be deleted is outside the scope of the current record."
      CASE 3739 ' &HE9B - %adErrPropInvalidColumn
         dws = "Cannot apply property to field"
      CASE 3740 ' &HE9C - %adErrPropInvalidOption
         dws = "Attribute property invalid"
      CASE 3741 ' &HE9D - %adErrPropInvalidValue
         dws = "Invalid property value"
      CASE 3742 ' &HE9E - %adErrPropConflicting
         dws = "Property values conflict with each other"
      CASE 3743 ' &HE9F - %adErrPropNotAllSettable
         dws = "Cannot set property or read-only"
      CASE 3744 ' &HEA0 - %adErrPropNotSet
         dws = "Optional property value not set"
      CASE 3745 ' &HEA1 - %adErrPropNotSettable
         dws = "Read-only property cannot be set"
      CASE 3746 ' &HEA2 - %adErrPropNotSupported
         dws = "Property not supported by provider"
      CASE 3747 ' &HEA3 - %adErrCatalogNotSet
         dws = "Operation requires a valid ParentCatalog."
      CASE 3748 ' &HEA4 - %adErrCantChangeConnection
         dws = "Connection was denied. New connection you requested has different characteristics than the one already in use."
      CASE 3749 ' &HEA5 - %adErrFieldsUpdateFailed
         dws = "Fields update failed. For further information, examine the Status property of individual field objects."
      CASE 3750 ' &HEA6 - %adErrDenyNotSupported
         dws = "Provider does not support sharing restrictions."
      CASE 3751 ' &HEA7 - %adErrDenyTypeNotSupported
         dws = "Provider does not support the requested kind of sharing restriction."
      CASE 3753 ' 3753 - %adErrProviderNotSpecified
         dws = "Provider not specified"
      CASE 3754 ' &HEAA - %adErrConnectionStringTooLong
         dws = "Connection string too long"
      CASE ELSE
         dws = "Unknown error"
   END SELECT

   FUNCTION = dws

END FUNCTION
' ===========================================================================================

' ===========================================================================================
' Retrieves information from the ADO Errors collection
' ===========================================================================================
PRIVATE FUNCTION AfxAdoGetErrorInfo (BYVAL pConnection AS AFX_ADOConnection PTR, BYVAL nError AS HRESULT = 0) AS DWSTRING

   DIM hr             AS HRESULT             ' // Result code
   DIM pErrors        AS Afx_ADOErrors PTR   ' // Reference to the Errors collection
   DIM pError         AS Afx_ADOError PTR    ' // Reference to the Error object
   DIM wError         AS WORD                ' // ADO runtime error
   DIM i              AS LONG                ' // Loop counter
   DIM nCount         AS LONG                ' // Number of errors
   DIM dwsErrorText   AS DWSTRING            ' // String to return the result
   DIM cbMsgLen       AS DWORD               ' // Length of the returned message
   DIM pBuffer        AS WSTRING PTR         ' // Pointer to the buffer
   DIM dwsDescription AS DWSTRING            ' // Description of the ADO runtime error
   DIM dvIndex        AS DVARIANT            ' // Index

   IF pConnection = NULL THEN RETURN ""

   ' Get a reference to the errors collection
   pConnection->get_Errors(@pErrors)
   IF pErrors THEN
      ' Get the number of errors
      pErrors->get_Count(@nCount)
      ' The errors collection is zero based
      FOR i = 0 TO nCount - 1
         ' Get a reference to the error object
         DIM dvIndex AS DVARIANT = DVARIANT(i, "LONG")
         pErrors->get_Item(dvIndex, @pError)
         IF pError THEN
            DIM eNumber AS LONG
            pError->get_Number(@eNumber)
            dwsErrorText += "OLE DB provider error" & CHR(13, 10)
            dwsErrorText += "Error number: " & WSTR(eNumber) & " [&h" & HEX(eNumber, 8) & "]" & CHR(13, 10)
            DIM bstrDescription AS AFX_BSTR
            pError->get_Description(@bstrDescription)
            IF SysStringLen(bstrDescription) THEN dwsErrorText += *bstrDescription & CHR(13, 10)
            SysFreeString bstrDescription
            DIM bstrSource AS AFX_BSTR
            pError->get_Source(@bstrSource)
            IF SysStringLen(bstrSource) THEN dwsErrorText += "Source: " & *bstrSource & CHR(13, 10)
            SysFreeString bstrSource
            DIM bstrSqlState AS AFX_BSTR
            pError->get_SQLState(@bstrSqlState)
            IF SysStringLen(bstrSqlState) THEN dwsErrorText += "SqlState: " & *bstrSqlState & CHR(13, 10)
            SysFreeString bstrSqlState
            DIM eNativeError AS LONG
            pError->get_NativeError(@eNativeError)
            dwsErrorText += "Native error: " & WSTR(eNativeError) & CHR(13, 10)
            DIM bstrHelpFile AS AFX_BSTR
            pError->get_HelpFile(@bstrHelpFile)
            IF SysStringLen(bstrHelpFile) THEN dwsErrorText += "Help file: " & *bstrHelpFile & CHR(13, 10)
            SysFreeString bstrHelpFile
            DIM eHelpContext AS LONG
            pError->get_HelpContext(@eHelpContext)
            dwsErrorText += "Help context: " & WSTR(eHelpContext) & CHR(13, 10)
            ' Release the error object
            pError->Release
         END IF
      NEXT
      ' Clear the errors collection
      pErrors->Clear
      ' Release the errors collection
      pErrors->Release
      IF nCount THEN RETURN dwsErrorText
   END IF

   ' Must be an ADO runtime error
   IF nError = 0 THEN RETURN ""
   wError = nError
   dwsDescription = AfxAdoGetRuntimeErrorInfo(wError)
   IF LEN(dwsDescription) THEN
      dwsErrorText += "ADO runtime error" & CHR(13, 10)
      dwsErrorText += "Error code: " & WSTR(nError) & " [&h" & HEX(nError, 8) & "]" & CHR(13, 10)
      dwsErrorText += "Description: " & dwsDescription
   ELSE
      ' If it is not a Provider or an ADO runtime error then must be a Windows error
      cbMsgLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER OR _
                 FORMAT_MESSAGE_FROM_SYSTEM OR FORMAT_MESSAGE_IGNORE_INSERTS, _
                 NULL, nError, BYVAL MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), _
                 cast(LPWSTR, @pBuffer), 0, NULL)
      IF cbMsgLen THEN
         dwsErrorText += "Windows error" & CHR(13, 10)
         dwsErrorText += "Error code:" & WSTR(nError) & " [&h" & HEX(nError, 8) & "]"
         dwsErrorText += "Description: " & *pBuffer
         LocalFree pBuffer
      END IF
   END IF

   RETURN dwsErrorText

END FUNCTION
' ===========================================================================================

#include once "AfxNova/CAdoErrors.inc"
#include once "AfxNova/CAdoConnection.inc"
#include once "AfxNova/CAdoCommand.inc"
#include once "AfxNova/CAdoRecordset.inc"
#include once "AfxNova/CAdoFields.inc"
#include once "AfxNova/CAdoProperties.inc"
#include once "AfxNova/CAdoParameters.inc"
#include once "AfxNova/CAdoRecord.inc"
#include once "AfxNova/CAdoStream.inc"
#include once "AfxNova/CAdoEvents.inc"

END NAMESPACE
