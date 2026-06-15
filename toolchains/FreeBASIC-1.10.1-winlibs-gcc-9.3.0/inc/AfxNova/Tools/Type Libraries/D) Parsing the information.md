# Parsing the information

To parse the type library information we need to call the methods of the **ITypeInfo** interface.

This is my definition of that interface:

```
' ########################################################################################
' Interface name = ITypeInfo
' Extracts information about the characteristics and capabilities of objects from type libraries.
' Inherited interface = IUnknown
' ########################################################################################

TYPE Afx_ITypeInfo AS Afx_ITypeInfo_
#ifndef __Afx_ITypeInfo_INTERFACE_DEFINED__
#define __Afx_ITypeInfo_INTERFACE_DEFINED__
TYPE Afx_ITypeInfo_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetTypeAttr (BYVAL ppTypeAttr AS TYPEATTR PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTypeComp (BYVAL ppTComp AS ITypeComp PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFuncDesc (BYVAL index AS UINT, BYVAL ppFuncDesc AS FUNCDESC PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetVarDesc (BYVAL index AS UINT, BYVAL ppVarDesc AS VARDESC PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetNames (BYVAL memid AS MEMBERID, BYVAL rgBstrNames AS AFX_BSTR PTR, BYVAL cMaxNames AS UINT, BYVAL pcNames AS UINT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRefTypeOfImplType (BYVAL index AS UINT, BYVAL pRefType AS HREFTYPE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetImplTypeFlags (BYVAL index AS UINT, BYVAL pImplTypeFlags AS INT_ PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetIDsOfNames (BYVAL rgszNames AS LPOLESTR PTR, BYVAL cNames AS UINT, BYVAL pMemId AS MEMBERID PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Invoke (BYVAL pvInstance AS PVOID, BYVAL memid AS MEMBERID, BYVAL wFlags AS WORD, BYVAL pDispParams AS DISPPARAMS PTR, BYVAL pVarResult AS VARIANT PTR, BYVAL pExcepInfo AS EXCEPINFO PTR, BYVAL puArgErr AS UINT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDocumentation (BYVAL memid AS MEMBERID, BYVAL pBstrName AS AFX_BSTR PTR, BYVAL pBstrDocString AS AFX_BSTR PTR, BYVAL pdwHelpContext AS DWORD PTR, BYVAL pBstrHelpFile AS AFX_BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDllEntry (BYVAL memid AS MEMBERID, BYVAL invKind AS INVOKEKIND, BYVAL pBstrDllName AS AFX_BSTR PTR, BYVAL pBstrName AS AFX_BSTR PTR, BYVAL pwOrdinal AS WORD PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRefTypeInfo (BYVAL hRefType AS HREFTYPE, BYVAL ppTInfo AS Afx_ITypeInfo PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AddressOfMember (BYVAL memid AS MEMBERID, BYVAL invKind AS INVOKEKIND, BYVAL ppv AS PVOID PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateInstance (BYVAL pUnkOuter AS IUnknown PTR, BYVAL riid AS CONST IID CONST PTR, BYVAL ppvObj AS PVOID PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMops (BYVAL memid AS MEMBERID, BYVAL pBstrMops AS AFX_BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetContainingTypeLib (BYVAL ppTLib AS Afx_ITypeLib PTR PTR, BYVAL pIndex AS UINT PTR) AS HRESULT
   DECLARE ABSTRACT SUB      ReleaseTypeAttr (BYVAL pTypeAttr AS TYPEATTR PTR)
   DECLARE ABSTRACT SUB      ReleaseFuncDesc (BYVAL pFuncDesc AS FUNCDESC PTR)
   DECLARE ABSTRACT SUB      ReleaseVarDesc (BYVAL pVarDesc AS VARDESC PTR)
END TYPE
#endif
```

To extract the type library information first wee need to rerieve how many **TypeInfos** it contains:

```
   ' // Retrieves the number of TypeInfos
   TypeInfoCount = m_pTypeLib->GetTypeInfoCount
   IF TypeInfoCount = 0 THEN
      TLB_MsgBox m_pWindow->hWindow, "This TypeLib doesn't have type infos", _
         MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
      RETURN S_FALSE
   END IF
```

```
   FOR i = 0 TO TypeInfoCount - 1
      ' // Retrieves the TypeKind
      hr = m_pTypeLib->GetTypeInfoType(i, @pTKind)
      IF hr <> S_OK THEN
         TLB_MsgBox m_pWindow->hWindow, "Error &H" & HEX$(hr, 8) & " retrieving the info type", _
            MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
         EXIT FOR
      END IF
      ' // Retrieves the ITypeInfo interface
      hr = m_pTypeLib->GetTypeInfo(i, @pTypeInfo)
      IF hr <> S_OK OR pTypeInfo = NULL THEN
         TLB_MsgBox m_pWindow->hWindow, "Error &H" & HEX$(hr, 8) & " retrieving the ITypeInfo interface", _
            MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
         EXIT FOR
      END IF

      ' // Gets the address of a pointer to the TYPEATTR structure
      hr = pTypeInfo->GetTypeAttr(@pTypeAttr)
      IF hr <> S_OK OR pTypeAttr = NULL THEN
         TLB_MsgBox m_pWindow->hWindow, "Error &H" & HEX$(hr, 8) & " retrieving the address of the TypeAttr structure", _
            MB_OK OR MB_ICONERROR OR MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
         EXIT FOR
      END IF
      ...
      ...
      ...
   NEXT
```

Inside the loop, we will process each block of information separately according its type:

```
      SELECT CASE pTKind
         CASE TKIND_COCLASS   ' // CoClasses
            ...
            ...
            ...
         CASE TKIND_RECORD, TKIND_UNION   ' // Structures and unions
            ...
            ...
            ...
         CASE TKIND_ALIAS   ' // Aliases and typedefs
            ...
            ...
            ...
         CASE TKIND_ENUM, TKIND_MODULE   ' // Enumerations and modules
            ...
            ...
            ...
         CASE TKIND_INTERFACE, TKIND_DISPATCH   ' // Interfaces
            ...
            ...
            ...
      END SELECT
```

### Getting the ProgID from the registry

```
' ========================================================================================
' Gets the ProgID from the registry.
' ========================================================================================
FUNCTION TLB_GetProgID (BYVAL pwszGuid AS WSTRING PTR) AS DWSTRING

   ' // Name of the subkey to open
   DIM wszKey AS WSTRING * MAX_PATH = "CLSID\" & *pwszGuid & "\ProgID"
   DIM hKey AS HKEY   ' // Handle of the opened key
   RegOpenKeyExW HKEY_CLASSES_ROOT, @wszKey, 0, KEY_READ, @hKey
   IF hKey = NULL THEN RETURN ""
   DIM dwIdx AS DWORD = 0                   ' // Index of the value to be retrieved
   DIM cValueName AS DWORD = MAX_PATH       ' // Size of wszValueName
   DIM cbData AS DWORD = MAX_PATH           ' // Size of wszKeyValue
   DIM keyType AS DWORD                     ' // Type of data
   DIM wszKeyValue AS WSTRING * MAX_PATH    ' // Buffer that receives the data
   DIM wszValueName AS WSTRING * MAX_PATH   ' // Name of the value
   RegEnumValueW hKey, dwIdx, @wszValueName, @cValueName, NULL, @keyType, cast(BYTE PTR, @wszKeyValue), @cbData
   RegCloseKey hKey
   RETURN wszKeyValue

END FUNCTION
' ========================================================================================
```

```
' ========================================================================================
' Gets the Version Independent ProgID from the registry.
' ========================================================================================
FUNCTION TLB_GetVersionIndependentProgID (BYVAL pwszGuid AS WSTRING PTR) AS DWSTRING

   ' // Name of the subkey to open
   DIM wszKey AS WSTRING * MAX_PATH = "CLSID\" & *pwszGuid & "\VersionIndependentProgID"
   DIM hKey AS HKEY   ' // Handle of the opened key
   RegOpenKeyExW HKEY_CLASSES_ROOT, @wszKey, 0, KEY_READ, @hKey
   IF hKey = NULL THEN RETURN ""
   DIM dwIdx AS DWORD = 0                   ' // Index of the value to be retrieved
   DIM cValueName AS DWORD = MAX_PATH       ' // Size of wszValueName
   DIM cbData AS DWORD = MAX_PATH           ' // Size of wszKeyValue
   DIM keyType AS DWORD                     ' // Type of data
   DIM wszKeyValue AS WSTRING * MAX_PATH    ' // Buffer that receives the data
   DIM wszValueName AS WSTRING * MAX_PATH   ' // Name of the value
   RegEnumValueW hKey, dwIdx, @wszValueName, @cValueName, NULL, @keyType, cast(BYTE PTR, @wszKeyValue), @cbData
   RegCloseKey hKey
   RETURN wszKeyValue

END FUNCTION
' ========================================================================================
```

### Getting the InprocServer32

```
' ========================================================================================
' Gets the InprocServer32 from the registry.
' ========================================================================================
FUNCTION TLB_GetInprocServer32 (BYVAL pwszGuid AS WSTRING PTR) AS DWSTRING

   ' // Name of the subkey to open
   DIM wszKey AS WSTRING * MAX_PATH = "CLSID\" & *pwszGuid & "\InprocServer32"
   DIM hKey AS HKEY   ' // Handle of the opened key
   RegOpenKeyExW HKEY_CLASSES_ROOT, @wszKey , 0, KEY_READ, @hKey
   IF hKey = NULL THEN RETURN ""
   DIM dwIdx AS DWORD = 0                   ' // Index of the value to be retrieved
   DIM cValueName AS DWORD = MAX_PATH       ' // Size of wszValueName
   DIM cbData AS DWORD = MAX_PATH           ' // Size of wszKeyValue
   DIM keyType AS DWORD                     ' // Type of data
   DIM wszKeyValue AS WSTRING * MAX_PATH    ' // Buffer that receives the data
   DIM wszValueName AS WSTRING * MAX_PATH   ' // Name of the value
   RegEnumValueW hKey, dwIdx, @wszValueName, @cValueName, NULL, @keyType, cast(BYTE PTR, @wszKeyValue), @cbData
   RegCloseKey hKey
   RETURN wszKeyValue

END FUNCTION
' ========================================================================================
```

### Getting the implemented interface

```
' ========================================================================================
' Retrieves the implemented interface.
' ========================================================================================
FUNCTION TLB_GetImplementedInterface (BYVAL pTypeInfo AS Afx_ITypeInfo PTR, BYVAL idx AS LONG = 0) AS DWSTRING

   DIM pRefType AS HREFTYPE   ' // Address to a referenced type description
   DIM hr AS HRESULT = pTypeInfo->GetRefTypeOfImplType(idx, @pRefType)
   IF hr <> S_OK OR pRefType = NULL THEN RETURN ""
   DIM pImplTypeInfo AS Afx_ITypeInfo PTR   ' // Implemented interface type info
   hr = pTypeInfo->GetRefTypeInfo(pRefType, @pImplTypeInfo)
   IF hr <> S_OK OR pImplTypeInfo = NULL THEN RETURN ""
   DIM dwsName AS DWSTRING, bstrName AS AFX_BSTR   ' // interface name
   pImplTypeInfo->GetDocumentation(-1, @bstrName, NULL, NULL, NULL)
   pImplTypeInfo->Release
   dwsName = *bstrName
   SysFreeString bstrName
   RETURN dwsName

END FUNCTION
' ========================================================================================
```

### Getting the inherited interface

```
' ========================================================================================
' Retrieves the inherited interface
' ========================================================================================
FUNCTION TLB_GetInheritedInterface (BYVAL pTypeInfo AS Afx_ITypeInfo PTR, BYVAL idx AS LONG = 0) AS DWSTRING

   DIM pRefType AS HREFTYPE   ' // Address to a referenced type description
   DIM hr AS HRESULT = pTypeInfo->GetRefTypeOfImplType(idx, @pRefType)
   IF hr <> S_OK OR pRefType = NULL THEN RETURN ""
   DIM pImplTypeInfo AS Afx_ITypeInfo PTR   ' // Implied interface type info
   hr = pTypeInfo->GetRefTypeInfo (pRefType, @pImplTypeInfo)
   IF hr <> S_OK OR pImplTypeInfo = NULL THEN RETURN ""
   DIM pTypeAttr AS TYPEATTR PTR   ' // Address of a pointer to the TYPEATTR structure
   hr = pImplTypeInfo->GetTypeAttr(@pTypeAttr)
   DIM dwsInterfaceName AS DWSTRING
   IF hr = S_OK AND pTypeAttr <> NULL THEN
      IF @pTypeAttr->cImplTypes = 1 THEN
         dwsInterfaceName = TLB_GetImplementedInterface(pImplTypeInfo, 0)
         pImplTypeInfo->ReleaseTypeAttr(pTypeAttr)
      END IF
   END IF
   pImplTypeInfo->Release
   RETURN dwsInterfaceName

END FUNCTION
' ========================================================================================
```

### Getting the base class

```
' ========================================================================================
' Retrieves the base class
' ========================================================================================
FUNCTION TLB_GetBaseClass (BYVAL pTypeLib AS Afx_ITypeLib PTR, BYREF dwsItemName AS DWSTRING) AS DWSTRING

   DIM pTypeInfo               AS Afx_ITypeInfo PTR   ' // TypeInfo interface
   DIM pTypeAttr               AS TYPEATTR PTR        ' // Address of a pointer to the TYPEATTR structure
   DIM pRefType                AS DWORD               ' // Address to a referenced type description
   DIM pRefTypeInfo            AS Afx_ITypeInfo PTR   ' // Referenced TypeInfo interface
   DIM pRefTypeAttr            AS TYPEATTR PTR        ' // Referenced TYPEATTR structure
   DIM dwsInheritedInterface   AS DWSTRING            ' // Inherited interface

   ' // Number of type infos
   DIM TypeInfoCount AS LONG = pTypeLib->GetTypeInfoCount
   IF TypeInfoCount = 0 THEN RETURN ""

   FOR i AS LONG = 0 TO TypeInfoCount - 1
      ' // Get the info type
      DIM pTKind AS TYPEKIND
      DIM hr AS HRESULT = pTypeLib->GetTypeInfoType(i, @pTKind)
      IF hr <> S_OK THEN EXIT FOR
      ' // Get the type info
      hr = pTypeLib->GetTypeInfo(i, @pTypeInfo)
      IF hr <> S_OK THEN EXIT FOR
      ' // Get the type attribute
      hr = pTypeInfo->GetTypeAttr(@pTypeAttr)
      IF hr <> S_OK OR pTypeAttr = NULL THEN EXIT FOR
      ' // If it is an interface...
      IF pTKind = TKIND_INTERFACE OR pTKind = TKIND_DISPATCH THEN
         ' // Get the name of the interface
         DIM dwsName AS DWSTRING, bstrName AS AFX_BSTR
         hr = pTypeLib->GetDocumentation(i, @bstrName, NULL, NULL, NULL)
         dwsName = *bstrName
         SysFreeString bstrName
         ' // If it is the one we are looking for...
         IF dwsName = dwsItemName THEN
            ' // If it inherits from another interface, recursively search the methods
            IF (pTypeAttr->wTypeFlags AND TYPEFLAG_FDUAL) = TYPEFLAG_FDUAL THEN
               dwsInheritedInterface = TLB_GetInheritedInterface(pTypeInfo, -1)
            ELSE
               dwsInheritedInterface = TLB_GetImplementedInterface(pTypeInfo)
            END IF
            ' // Check also that the interface doesn't inherit from itself!
            IF UCASE(dwsInheritedInterface) <> "IUNKNOWN" AND UCASE(dwsInheritedInterface) <> "IDISPATCH" AND UCASE(dwsInheritedInterface) <> UCASE(*bstrName) THEN
               dwsInheritedInterface = TLB_GetBaseClass(pTypeLib, dwsInheritedInterface)
            END IF
         END IF
      END IF
      pTypeInfo->ReleaseTypeAttr(pTypeAttr) : pTypeAttr = NULL
      pTypeInfo->Release : pTypeInfo = NULL
   NEXT

   IF pTypeAttr THEN pTypeInfo->ReleaseTypeAttr(pTypeAttr)
   IF pTypeInfo THEN pTypeInfo->Release

   RETURN dwsInheritedInterface

END FUNCTION
' ========================================================================================
```
