# Windows Management Instrumentation (WMI)

Windows Management Instrumentation (WMI) is the infrastructure for management data and operations on Windows-based operating systems. 

`CWmiServices` is a wrapper class on top of the WMI scripting interfaces.

`CWmiServices` supports three ways of retrieving information.

* The first one uses an enumerator (the standard **IEnumVARIANT** interface).
* The second way is to call the **GetNamedProperties** method after executing the query. **GetNamedProperties** generates a named collection of properties. This has the advantage of not having to use **CDispInvoke**.
* The third way is to use the **Get** method. It retrieves an object, that is either a class definition or an instance, based on the specified object path. Using this object, it generates a named collection of properties. The disadvantage over **ExecQuery** is that you can't choose the properties to return: it returns all the properties of the specified WMI class.

**Include file**: AfxNova/CWmiDisp.inc.

# Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor (Moniker)](#constructor1) | Connects to WMI using a moniker. |
| [Constructor (Server)](#constructor2) | Connects to the namespace that is specified on the *wszNamespace* parameter on the computer that is specified in the *wszServer* parameter. The target computer can be either local or remote, but it must have WMI installed. |

---

# Methods

| Name       | Description |
| ---------- | ----------- |
| [ExecQuery](#execquery) | Executes a query to retrieve objects. |
| [Get](#get) | Retrieves an object, that is either a class definition or an instance, based on the object path. |
| [GetErrorCodeText](#geterrorcodetext) | Returns the text string description associated with the WMI error code. |
| [GetFacilityCodeText](#getfacilitycodetext) | Returns the name of the subsystem where the error occurred, such as "Windows", "WBEM", "SSPI", or "RPC". |
| [GetLastResult](#getlastresult) | Returns the last result code. |
| [GetNamedProperties](#getnamedproperties) | Retrieves a named collection of the properties for the current class or instance. |
| [InstancesOf](#instancesof) | Creates an enumerator that returns the instances of a specified class according to the user-specified selection criteria. |
| [NewEnum](#newenum) | Retrieves an enumerator for the collection. |
| [NextObject](#nextobject) | Retrieves the next item in the enumeration sequence. |
| [ObjectsCount](#objectscount) | Returns the number of objects in the collection. |
| [ObjectSetPtr](#objectsetptr) | Returns a pointer to the **ISWbemObjectSet** interface. Don't call **IUnknown_Release** on it. |
| [PropertySetPtr](#propertysetptr) | Returns a pointer to the **ISWbemPropertySet** interface. Don't call **IUnknown_Release** on it. |
| [PropsCount](#propscount) | Returns the number of objects in the property set collection. |
| [PropValue](#propvalue) | Retrieves the variant value of the WMI property. |
| [ResetEnum](#resetenum) | Resets the enumeration sequence to the beginning. |
| [ServicesObj](#servicesobj) | Returns a counted reference of the underlying dispatch pointer. You must release it, e.g. calling call **IUnknown_Release** or the function **AfxSafeRelease** when no longer need it. |
| [ServicesPtr](#servicesptr) | Returns a pointer to the ISWbemServices interface. Don't call **IUnknown_Release** on it. |
| [WmiDateToStr](#wmidatetostr) | Converts a date and time value in the CIM DATETIME format to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy". |
| [WmiTimeToFileTime](#wmitimetofiletime) | Converts a date and time value in the CIM DATETIME format to the FILETIME format. |
| [WmiTimeToStr](#wmitimetostr) | Converts a date and time value in the CIM DATETIME format to a string containing the date based on the specified mask, e.g. "hh':'mm':'ss tt". |

---

## <a name="constructor1"></a>Constructor (Moniker)

Connects to WMI using a moniker.

```
CONSTRUCTOR CWmiServices (BYREF wszDisplayName AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszDisplayName* | The display name for the object to be created. |

#### Examples

```
' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
```

This example uses **CWmiServices** and **CDispInvoke** to easily set the specified printer as the default printer:

```
' // Connect with WMI in the local computer and get the properties of the specified printer
DIM pDisp AS CDispInvoke = CWmiServices( _
   $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2:" & _
   "Win32_Printer.DeviceID='OKI B410'").ServicesObj

' // Set the printer as the default printer
DIM dvRes AS DVARIANT = pDisp.Invoke("SetDefaultPrinter")
print "Result: ", VAL(dvRes)
```
---

## <a name="constructor2"></a>Constructor (Server)

Connects to the namespace that is specified on the *wszNamespace* parameter on the computer that is specified in the *wszServer* parameter. The target computer can be either local or remote, but it must have WMI installed.

```
CONSTRUCTOR CWmiServices (BYREF wszServer AS WSTRING, BYREF wszNamespace AS WSTRING, _
   BYREF wszUser AS WSTRING = "", BYREF wszPassword AS WSTRING = "", _
   BYREF wszLocale AS WSTRING = "", BYREF wszAuthority AS WSTRING = "", _
   BYVAL iSecurityFlags AS LONG = wbemConnectFlagUseMaxWait)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszServer* | The computer name to which you are connecting. If the remote computer is in a different domain than the user account under which you log in, then use the fully qualified computer name. If you do not provide this parameter, the call defaults to the local computer.<br>Example: server1.network.fabrikam<br>You also can use an IP address in this parameter. If the IP address is in IPv6 format, the target computer must be running IPv6. An address in IPv4 looks like 111.222.333.444. An IP address in IPv6 format looks like 2010:836B:4179::836B:4179 |
| *wszNamespace* | A string that specifies the namespace to which you log on. For example, to log on to the root\default namespace, use root\\default. If you do not specify this parameter, it defaults to the namespace that is configured as the default namespace for scripting.<br>Example: DIM pServices AS CWmiServices = CWmiServices(".", "root\\cimv2")<br>where "." is a shortcut for the local computer. |
| *wszPassword* | A string that specifies the password to use when attempting to connect. Leave the parameter blank to use the current security context. The *wszPassword* parameter should only be used with connections to remote WMI servers. If you attempt to specify *wszPassword* for a local WMI connection, the connection attempt fails. If Kerberos authentication is in use then the username and password that is specified in *wszUser* and *wszPassword* cannot be intercepted on the network. |
| *wszLocale* | A string that specifies the localization code. If you want to use the current locale, leave it blank. If not blank, this parameter must be a string that indicates the desired locale where information must be retrieved. For Microsoft locale identifiers, the format of the string is "MS_xxxx", where xxxx is a string in the hexadecimal form that indicates the LCID. For example, American English would appear as "MS_409". |
| *wszAuthority* | Optional.<br>"": This parameter is optional. However, if specified, only Kerberos or NTLMDomain can be used.<br> "Kerberos": If the *wszAuthority* parameter begins with the string "Kerberos:", then Kerberos authentication is used and this parameter should contain a Kerberos principal name. The Kerberos principal name is specified as Kerberos:domain, such as Kerberos:fabrikam where fabrikam is the server to which you are  attempting to connect. Example: "Kerberos:DOMAIN"<br>"NTLMDomain": To use NT Lan Manager (NTLM) authentication, you must specify it as NTLMDomain:domain, such as NTLMDomain:fabrikam where fabrikam is the name of the domain. Example: "NTLMDomain:DOMAIN"<br>If you leave this parameter blank, the operating system negotiates with COM to determine whether NTLM or Kerberos authentication is used. This parameter should only be used with connections to remote WMI servers. If you attempt to set the authority for a local WMI connection, the connection attempt fails.<br>Note: If the domain is specified in *wszUser*, which is the preferred location, then it must not be specified here. Specifying the domain in both parameters results in an Invalid Parameter error. |
| *iSecurityFlags* | Optional. Used to pass flag values to the *ConnectServer* method of the **ISWbemLocator** interface.<br>*0 (&h0)*: A value of 0 for this parameter causes the call to *ConnectServer* to return only after the connection to the server is established. This could cause your program to stop responding indefinitely if the connection cannot be established.<br>*wbemConnectFlagUseMaxWait (128 (&H80))*<> The *ConnectServer* call is guaranteed to return in 2 minutes or less. Use this flag to prevent your program from ceasing to respond indefinitely if the connection cannot be established. |

#### Return value

If successful, WMI returns an **SWbemServices** object that is bound to the namespace that is specified in *wszNamespace* on the computer that is specified in *wszServer*.

**Usage example** (with the local computer):

```
DIM pServices AS CWmiServices = CWmiServices(".", "root\cimv2")
```

### Remarks

The *ConnectServer* method is often used when connecting to an account with a different username and password—credentials—on a remote computer because you cannot specify a different password in a moniker string.

Using an IPv4 address to connect to a remote server may result in unexpected behavior. The likely cause is stale DNS entries in your environment. In these circumstances, the stale PTR entry for the machine will be used, with unpredictable results. To avoid this behavior, you can append a period (".") to the IP address before calling *ConnectServer*. This causes the reverse DNS lookup to fail, but may allow the *ConnectServer* call to succeed on the correct machine.

---

## ExecQuery

Executes a query to retrieve objects. These objects are available through the retrieved **SWbemObjectSet** collection.

```
FUNCTION ExecQuery (BYREF wszQuery AS WSTRING, BYVAL iFlags AS LONG = wbemFlagReturnWhenComplete) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszQuery* | Required. A string that contains the text of the query. This parameter cannot be blank. |
| *iFlags* | Optional. An integer that determines the behavior of the query and determines whether this call returns immediately. The default value for this parameter is *wbemFlagReturnWhenComplete*. This parameter can accept the following values. |

| Flag       | Description |
| ---------- | ----------- |
| *wbemFlagForwardOnly* | Causes a forward-only enumerator to be returned. Forward-only enumerators are generally much faster and use less memory than conventional enumerators, but they do not allow calls to **SWbemObject.Clone_**. |
| *wbemFlagReturnWhenComplete* | Causes this call to block until the query is complete. This flag calls the method in the synchronous mode. |
| *wbemFlagBidirectional* | Causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator. |
| *wbemFlagReturnImmediately* | Causes the call to return immediately. |
| *wbemQueryFlagPrototype* | Used for prototyping. This flag stops the query from happening and returns an object that looks like a typical result object. |
| *wbemFlagUseAmendedQualifiers* | Causes WMI to return class amendment data with the base class definition. |

#### Return value

Returns S_OK (0) on success, or an HRESULT code on failure.

#### Examples

Using an enumerator (the standard **IEnumVARIANT** interface) to retrieve the information:

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Count: ", nCount

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
PRINT "Caption: "; pDispServ.Get("Caption")
PRINT "Serial number: "; pDispServ.Get("SerialNumber")
```

If the query returns more than one object, then we will use a loop:

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount

' // Enumerate the objects
FOR i AS LONG = 0 TO nCount - 1
   PRINT "--- Index " & STR(i) & " ---"
   DIM pDispServ AS CDispInvoke = pServices.NextObject
   PRINT "Caption: "; pDispServ.Get("Caption")
   PRINT "Capabilities "; pDispServ.Get("Capabilities")
NEXT
```

To improve enumeration performance set the *iFlags* parameter of the **ExecQuery** method to *WbemFlagReturnImmediately* and *WbemFlagForwardOnly* (the combined value of these flags is 48) to allow semisynchronous return of the data with an enumerator that discards each item from WMI as it is delivered. In this case don't call the **ObjectsCount** method because it will return 0, since the operation has not been completed.

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS", 48)

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
PRINT "Caption: "; pDispServ.Get("Caption")
PRINT "Serial number: "; pDispServ.Get("SerialNumber")
```

If there are several objects in the collection, we can use a loop:

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer", 48)

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke
DO
   pDispServ = pServices.NextObject
   IF pDispServ.DispPtr = NULL THEN EXIT DO
   PRINT "Caption: "; pDispServ.Get("Caption")
   PRINT "Capabilities "; pDispServ.Get("Capabilities")
LOOP
```

Calling the **GetNamedProperties** method after executing the query. **GetNamedProperties** generates a named collection of properties. This has the advantage of not having to use **CDispInvoke**.

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount

' // Get a collection of named properties
IF pServices.GetNamedProperties <> S_OK THEN PRINT "Failed to get the named properties"

' // Retrieve the value of the properties
PRINT pServices.PropValue("Caption")
PRINT pServices.PropValue("SerialNumber")
```

**Using a loop**:

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount

' // Enumerate the objects
FOR i AS LONG = 0 TO nCount - 1
   PRINT "--- Index " & STR(i) & " ---"
   ' // Get a collection of named properties
   IF pServices.GetNamedProperties(i) = S_OK THEN
      PRINT pServices.PropValue("Caption")
      PRINT pServices.PropValue("Capabilities")
   END IF
NEXT
```

#### Example

The following example monitors process performance information.

```
DO   ' // fake loop to avoid nested IFs/ENDIFs

   ' // Connect to WMI using a moniker
   ' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
   IF pServices.ServicesPtr = NULL THEN EXIT DO

   ' // Execute a query
   DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Process")
   IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : EXIT DO

   ' // Get the number of objects retrieved
   DIM nCount AS LONG = pServices.ObjectsCount
   print "Number of objects: ", nCount
   IF nCount = 0 THEN PRINT "No objects found" : EXIT DO

   ' // Enumerate the objects
   FOR i AS LONG = 0 TO nCount - 1
      PRINT "--- Index " & STR(i) & " ---"
      ' // Get a collection of named properties
      IF pServices.GetNamedProperties(i) = S_OK THEN
         PRINT pServices.PropValue("Name")
         PRINT pServices.PropValue("ProcessID")
         PRINT pServices.PropValue("ThreadCount")
         PRINT pServices.PropValue("PageFileUsage")
         PRINT pServices.PropValue("PageFaults")
         PRINT pServices.PropValue("WorkingSetSize")
      END IF
   NEXT

   EXIT DO   ' // Inconditional exit
LOOP
```

Using an enumerator:

```
DO   ' // fake loop to avoid nested IFs/ENDIFs

   ' // Connect to WMI using a moniker
   ' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
   IF pServices.ServicesPtr = NULL THEN EXIT DO

   ' // Execute a query
   DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Process", 48)
   IF hr <> S_OK THEN PRINT AfxWmiGetErrorCodeText(hr) : EXIT DO

   ' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
   ' // and retrieve the properties using the CDispInvoke class.
   DIM pDispServ AS CDispInvoke
   DO
      pDispServ = pServices.NextObject
      IF pDispServ.DispPtr = NULL THEN EXIT DO
      PRINT "Name: "; pDispServ.Get("Name")
      PRINT "ProcessID "; pDispServ.Get("ProcessID")
      PRINT "ThreadCount "; pDispServ.Get("ThreadCount")
      PRINT "PageFileUsage "; pDispServ.Get("PageFileUsage")
      PRINT "PageFaults "; pDispServ.Get("PageFaults")
      PRINT "WorkingSetSize "; pDispServ.Get("WorkingSetSize")
   LOOP

   EXIT DO   ' // Inconditional exit
LOOP
```
---

## Get

Retrieves an object, that is either a class definition or an instance, based on the object path. This method retrieves only objects from the namespace that is associated with the current **SWbemServices** object.

```
FUNCTION Get (BYREF wszObjectPath AS WsTRING, BYVAL iFlags AS LONG = 0, _
   BYVAL objWbemNamedValueSet AS Afx_IDispatch PTR = NULL) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszObjectPath* | A string that contains the object path of the object to retrieve. If this value is empty, the empty object that is returned can become a new class. |
| *iFlags* | Optional. An integer value that determines the behavior of the query. This parameter can accept the following value: *wbemFlagUseAmendedQualifiers*: Causes WMI to return class amendment data with the base class definition. |
| *objWbemNamedValueSet* | Optional. Typically, this is undefined. Otherwise, this is an **SWbemNamedValueSet** object whose elements represent the context information that can be used by the provider that is servicing the request. A provider that supports or requires such information must document the recognized value names, data type of the value, allowed values, and semantics. |

#### Return value

S_OK on success or an error code.

May return one of the error codes in the following list:

| Error      | Value       | Description |
| ---------- | ----------- | ----------- |
| *wbemErrAccessDenied* | -2147749891 (&h80041003) | Current user does not have the permission to access the object. |
| *wbemErrFailed* | -2147749889 (&h80041001) | Unspecified error. |
| *wbemErrInvalidParameter* | -2147749896 (&h80041008) | A specified parameter is not valid. |
| *wbemErrInvalidObjectPath* | -2147749946 (&h8004103A) | Specified path was not valid. |
| *wbemErrNotFound* | -2147749890 (&h80041002) | Requested object could not be found. |
| *wbemErrOutOfMemory* | -2147749894 (&h80041006) | Not enough memory to complete the operation. |

#### Example

```
#include "AfxNova/CWmiDisp.inc"
using AfxNova

' // Connect to WMI using a moniker
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
 
' // Get an instance of the printer "OKI B410" --> change me
DIM hr AS HRESULT = pServices.Get("Win32_Printer.DeviceID='OKI B410'")

' // Number of properties
PRINT "Number of properties: ", pServices.PropsCount
PRINT

' // Display some properties
PRINT "Port name: "; pServices.PropValue("PortName")
PRINT "Attributes: "; pServices.PropValue("Attributes")
PRINT "Paper sizes supported: "; pServices.PropValue("PaperSizesSupported")
```

Example

```
#include "AfxNpva/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
'DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"
' Use the constructor for server connection, just for trying...
DIM pServices AS CWmiServices = CWmiServices(".", "root\cimv2")
 
 '// Get an instance of a file --> change me
DIM dwsPath AS DWSTRING = ExePath & "\EX_CWMI_Get_01.bas"   ' --> change me
DIM hr AS HRESULT = pServices.Get("CIM_DataFile.Name='" & dwsPath & "'")

' // Number of properties
PRINT "Number of properties: ", pServices.PropsCount
PRINT

' // Display some properties
PRINT "Relative path: "; pServices.PropValue("Path")
PRINT "FileName: "; pServices.PropValue("FileName")
PRINT "Extension: "; pServices.PropValue("Extension")
PRINT "Size: "; pServices.PropValue("Filesize")
'PRINT pServices.PropValue("LastModified")
PRINT "Date last modified: "; pServices.WmiDateToStr(pServices.PropValue("LastModified"), "dd-MM-yyyy")   ' // change the mask if needed
```
---

## GetErrorCodeText

Returns the text string description associated with the WMI error code.

```
FUNCTION GetErrorCodeText (BYVAL hRes AS HRESULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRes* | The WMI error code. |

#### Return value

The localized text string description associated with the WMI error code.

---

## GetFacilityCodeText

Returns the name of the subsystem where the error occurred, such as "Windows", "WBEM", "SSPI", or "RPC".

```
FUNCTION GetFacilityCodeText (BYVAL hRes AS HRESULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hRes* | The WMI error code. |

#### Return value

The name of the subsystem where the error occurred.

---

## GetLastResult

Returns the result code returned by the last executed method.

```
FUNCTION GetLastResult () AS HRESULT
```
---

## GetNamedProperties

Retrieves a named collection of the properties for the current class or instance.

```
FUNCTION GetNamedProperties (BYVAL idx AS LONG = 0) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The zero-based index of the member of the collection. |

#### Return value

S_OK on success or an error code.

May return one of the error codes in the following list:

| Error      | Value       | Description |
| ---------- | ----------- | ----------- |
| *wbemErrFailed* | -2147749889 (&h80041001) | Unspecified error. |
| *wbemErrInvalidParameter* | -2147749896 (&h80041008) | A specified parameter is not valid. |
| *wbemErrOutOfMemory* | -2147749894 (&h80041006) | Not enough memory to complete the operation. |

#### Examples

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Number of objects: ", nCount

' // Get a collection of named properties
IF pServices.GetNamedProperties <> S_OK THEN PRINT "Failed to get the named properties"

' // Retrieve the value of the properties
PRINT pServices.PropValue("Caption")
PRINT pServices.PropValue("SerialNumber")
```

Using a loop:

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT * FROM Win32_Printer")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Number of objects: ", nCount

' // Enumerate the objects
FOR i AS LONG = 0 TO nCount - 1
   PRINT "--- Index " & STR(i) & " ---"
   ' // Get a collection of named properties
   IF pServices.GetNamedProperties(i) = S_OK THEN
      PRINT pServices.PropValue("Caption")
      PRINT pServices.PropValue("Capabilities")
   END IF
NEXT
```
---

## InstancesOf

Creates an enumerator that returns the instances of a specified class according to the user-specified selection criteria. This method implements a simple query. More complex queries may require the use of the **ExecQuery** method. By default, the method is called in the semisynchronous mode.

```
FUNCTION InstancesOf (BYREF wszClass AS WSTRING, BYVAL iFlags AS LONG = wbemFlagReturnImmediately) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszClass* | Required. A string that contains the name of the class for which instances are desired. This parameter cannot be blank. |
| *iFlags* | Optional. This parameter determines how detailed the call enumerates and if this call returns immediately. The default value for this parameter is *wbemFlagReturnImmediately*. This parameter can accept the following values. |

| Flag       | Description |
| ---------- | ----------- |
| *wbemFlagForwardOnly* | Causes a forward-only enumerator to be returned. Forward-only enumerators are generally much faster and use less memory than conventional enumerators, but they do not allow calls to **SWbemObject.Clone_**. |
| *wbemFlagReturnWhenComplete* | Causes this call to block until the query is complete. This flag calls the method in the synchronous mode. |
| *wbemFlagBidirectional* | Causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator. |
| *wbemFlagReturnImmediately* | Causes the call to return immediately. |
| *wbemQueryFlagPrototype* | Used for prototyping. This flag stops the query from happening and returns an object that looks like a typical result object. |
| *wbemFlagUseAmendedQualifiers* | Causes WMI to return class amendment data with the base class definition. |

#### Return value

S_OK on success or an error code.

#### Example

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Retrieve the instances of
DIM hr AS HRESULT = pServices.InstancesOf("Win32_Printer")

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke
DO
   pDispServ = pServices.NextObject
   IF pDispServ.DispPtr = NULL THEN EXIT DO
   PRINT "Caption: "; pDispServ.Get("Caption")
   PRINT "Capabilities "; pDispServ.Get("Capabilities")
LOOP
```
---

## NewEnum

Retrieves an enumerator for the collection.

Note: If **ExecQuery** has been called using the *wbemFlagReturnImmediately* flag, the enumerator won't be available until the operation has completed.

```
FUNCTION NewEnum () AS BOOLEAN
```

#### Return value

TRUE if the enumerator has been retrieved or FALSE otherwise.

---

## NextObject

Retrieves the next item in the enumeration sequence.

Note: The first time that you call this method, it retrieves the first item.

```
FUNCTION NextObject () AS DVARIANT
```

#### Return value

Te retrieved object.

#### Example

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS")

' // Get the number of objects retrieved
DIM nCount AS LONG = pServices.ObjectsCount
print "Count: ", nCount

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
PRINT "Caption: "; pDispServ.Get("Caption")
PRINT "Serial number: "; pDispServ.Get("SerialNumber")
```

To improve enumeration performance set the *iFlags* parameter of the **ExecQuery** method to *WbemFlagReturnImmediately* and *WbemFlagForwardOnly* (the combined value of these flags is 48) to allow semisynchronous return of the data with an enumerator that discards each item from WMI as it is delivered. In this case don't call the **ObjectsCount** method because it will return 0, since the operation has not been completed.

```
#include "AfxNova/CWmiDisp.inc"
USING AfxNova

' // Connect to WMI using a moniker
' // Note: $ is used to avoid the pedantic warning of the compiler about escape characters
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2"

' // Execute a query
DIM hr AS HRESULT = pServices.ExecQuery("SELECT Caption, SerialNumber FROM Win32_BIOS", 48)

' // Enumerate the objects using the standard IEnumVARIANT enumerator (NextObject method)
' // and retrieve the properties using the CDispInvoke class.
DIM pDispServ AS CDispInvoke = pServices.NextObject
PRINT "Caption: "; pDispServ.Get("Caption")
PRINT "Serial number: "; pDispServ.Get("SerialNumber")
```
---

## ObjectsCount

Returns the number of objects in the collection.

```
FUNCTION ObjectsCount () AS LONG
```

#### Remarks

If **ExecQuery** has been called without the *wbemFlagReturnWhenComplete* flag, this method will return 0 because the operation has not been completed.

---

## ObjectSetPtr

Returns a pointer to the **ISWbemObjectSet** interface. Don't call **IUnknown_Release** on it.

```
FUNCTION ObjectSetPtr () AS ANY PTR
```
---

## PropertySetPtr

Returns a pointer to the **ISWbemPropertySet** interface. Don't call **IUnknown_Release** on it.

```
FUNCTION PropertySetPtr () AS ANY PTR
```
---

## PropsCount

Returns the number of objects in the property set collection.

```
FUNCTION PropsCount () AS LONG
```
---

## PropValue

Gets/sets the variant value of the WMI property.

```
PROPERTY PropValue (BYREF wszName AS WSTRING) AS DVARIANT
PROPERTY PropValue (BYREF wszName AS WSTRING, BYREF dvValue AS DVARIANT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszName* | Name of the property to retrieve. |
| *dvValue* | The variant value to set. |

---

## ResetEnum

Resets the enumeration sequence to the beginning.

```
FUNCTION ResetEnum () AS BOOLEAN
```

#### Return value

TRUE if the enumerator has been reset or FALSE otherwise.

---

## ServicesObj

Returns a counted reference of the underlying dispatch pointer. You must release it, e.g. calling call **IUnknown_Release** or the function **AfxSafeRelease** when no longer need it.

```
FUNCTION ServicesObj () AS ANY PTR
```

#### Return value

A counted reference to the **ISWbemServices** interface. Because it is a an addrefered pointer, you must release it when no longer needed.

---

## ServicesPtr

Returns a pointer to the **ISWbemServices** interface. Don't call IUnknown_Release on it.

```
FUNCTION ServicesPtr () AS ANY PTR
```
---

## WmiDateToStr

Converts a date and time value in the CIM DATETIME format to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION WmiDateToStr (BYVAL pwszDateTime AS WSTRING PTR, BYREF wszMask AS WSTRING, _
   BYVAL bIsLocal AS BOOLEAN = TRUE) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszDateTime* | The date and time value in the CIM DATETIME format. |
| *wszMask* | A picture string that is used to form the date. |
| *bIsLocal* | Indicates whether the returned value is interpreted as local time. The UTC property then contains the local time converted to the correct Coordinated Universal Times (UTC) offset. If the value is FALSE, then the value is interpreted as UTC with a zero (0) offset. |

The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.

For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy".

The following table defines the format types used to represent days:

| Format type | Description |
| ---------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months:

| Format type | Description |
| ---------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years:

| Format type | Description |
| ---------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Return value

The formatted date as a string.

---

## WmiTimeToFileTime

Converts a date and time value in the CIM DATETIME format to the FILETIME format.

```
FUNCTION WmiTimeToFileTime (BYVAL pwszDateTime AS WSTRING PTR, BYVAL bIsLocal AS BOOLEAN = TRUE) AS FILETIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszDateTime* | The date and time value in the CIM DATETIME format. |
| *bIsLocal* | Indicates whether the returned value is interpreted as local time. The UTC property then contains the local time converted to the correct Coordinated Universal Times (UTC) offset. If the value is FALSE, then the value is interpreted as UTC with a zero (0) offset. |

#### Return value

The date and time value as a **FILETIME** structure.

---

## WmiTimeToStr

Converts a date and time value in the CIM DATETIME format to a string containing the date based on the specified mask, e.g. "hh':'mm':'ss tt".

```
FUNCTION WmiTimeToStr (BYVAL pwszDateTime AS WSTRING PTR, BYREF wszMask AS WSTRING, _
   BYVAL bIsLocal AS BOOLEAN = TRUE) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszDateTime* | The date and time value in the CIM DATETIME format. |
| *wszMask* | A picture string that is used to form the time. |
| *bIsLocal* | Indicates whether the returned value is interpreted as local time. The UTC property then contains the local time converted to the correct Coordinated Universal Times (UTC) offset. If the value is FALSE, then the value is interpreted as UTC with a zero (0) offset. |

|Picture     | Description |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted date as a string.

---

### Examples to call methods of WMI classes

```
#cmdline "-s console"
#include "AfxNova/CWmiDisp.inc"
using AfxNova

DO   ' // fake loop to allow early exit

' // Connect to WMI using a moniker
DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\.\root\default:StdRegProv"
IF pServices.ServicesPtr = NULL THEN EXIT DO
 
' // Assign the WMI services object pointer to CDispInvoke
' // CWmiServices.ServicesObj returns an AddRefed pointer, whereas CWmiServices.ServicesPtr not.
DIM pDispServices AS CDispInvoke = CDispInvoke(pServices.ServicesObj)

' Parameters of the GetStringValue method:
' %HKEY_LOCAL_MACHINE ("2147483650") - The value must be specified as an string and in decimal, not hexadecimal.
' vDefKey = [IN]  "2147483650"
' vPath   = [IN]  "Software\Microsoft\Windows NT\CurrentVersion"
' vValue  = [OUT] "ProductName"

DIM bsValue AS BSTRING
DIM dvRes AS DVARIANT = pDispServices.Invoke("GetStringValue", "2147483650", _
    $"Software\Microsoft\Windows NT\CurrentVersion", "ProductName", DVARIANT(bsValue.vptr, VT_BSTR))
PRINT bsValue

EXIT DO   ' // exit the fake loop
LOOP
```
---

```
#cmdline "-s console"
#include "AfxNova/CWmiDisp.inc"
using AfxNova

DO   ' // fake loop to allow early exit

' // Connect to WMI using a moniker
DIM pServices AS CWmiServices = ( _
   $"winmgmts:{impersonationLevel=impersonate}!\\.\root\cimv2:Win32_Process")
IF pServices.ServicesPtr = NULL THEN EXIT DO
 
' // Assign the WMI services object pointer to CDispInvoke
' // CWmiServices.ServicesObj returns an AddRefed pointer, whereas CWmiServices.ServicesPtr not.
DIM pDispServices AS CDispInvoke = CDispInvoke(pServices.ServicesObj)

' // Note: Although the WMI documentation says that this OUT parameter is an UInt32,
' // it only works if I use "LONG".
DIM ProcessId AS LONG
pDispServices.Invoke("Create", "notepad.exe", AfxDVarOptPrm, AfxDVarOptPrm, DVARIANT(@ProcessId, "LONG"))
PRINT "Process id: ", ProcessId

EXIT DO   ' // exit the fake loop
LOOP
```
---

### Miscellaneous wrapper functions

```
' ========================================================================================
' Retrieves the baseboard (also known as a motherboard or system board) serial number.
' ========================================================================================
PRIVATE FUNCTION AfxGetBaseBoardSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_BaseBoard")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================
```

```
' ========================================================================================
' Retrieves the Bios serial number.
' ========================================================================================
PRIVATE FUNCTION AfxGetBiosSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_BIOS")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Retrieves the manufacturer serial number.
' Contrarily to the serial number returned by AfxGetDiskDriveSerialNumber, this one won't
' change even if you format your hard drive.
' Requires Windows Vista+.
' ========================================================================================
PRIVATE FUNCTION AfxGetManufacturerSerialNumber (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_PhysicalMedia")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Retrieves the disk drive serial number.
' Contrarily to the serial number returned by AfxGetManufacturerSerialNumber, that does not
' change, this one will change every time the hard drive is formatted.
' Requires Windows Vista+.
' ========================================================================================
PRIVATE FUNCTION AfxGetDiskDriveSerialNumber (BYREF wszServerName AS WSTRING = ".") AS STRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SerialNumber FROM Win32_DiskDrive")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SerialNumber")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Retrieves the system running on the Windows-based computer. The following list identifiers
' the returned value: "X86-based PC", "MIPS-based PC", "Alpha-based PC", "Power PC",
' "SH-x PC", "StrongARM PC", "64-bit Intel PC", "64-bit Alpha PC", "Unknown", "X86-Nec98 PC".
' ========================================================================================
PRIVATE FUNCTION AfxGetSystemType (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT SystemType FROM Win32_ComputerSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("SystemType")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Retrieves the type of the computer in use, such as laptop, desktop, or Tablet.
' Not available in Windows Server 2003, Windows XP, Windows 2000, Windows NT 4.0, and Windows Me/98/95.
' Value   Meaning
' ------- --------------------------------------------
' 0 (&H0) Unspecified
' 1 (&H1) Desktop
' 2 (&H2) Mobile
' 3 (&H3) Workstation
' 4 (&H4) Enterprise Server
' 5 (&H5) Small Office and Home Office (SOHO) Server
' 6 (&H6) Appliance PC
' 7 (&H7) Performance Server
' 8 (&H8) Maximum
' ========================================================================================
PRIVATE FUNCTION AfxGetPCSystemType (BYREF wszServerName AS WSTRING = ".") AS USHORT
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT PCSystemType FROM Win32_ComputerSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("PCSystemType"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Retrieves the name of the disk drive from which the Windows operating system starts.
' Example: "\Device\Harddisk0"
' ========================================================================================
PRIVATE FUNCTION AfxGetBootDevice (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT BootDevice FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("BootDevice")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Type of build used for an operating system.
' Examples: "retail build", "checked build", "Multiprocessor Free".
' ========================================================================================
PRIVATE FUNCTION AfxGetOSBuildType (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT BuildType FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("BuildType")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Short description of the object—a one-line string. The string includes the operating
' system version. For example, "Microsoft Windows 7 Enterprise ". This property can be localized.
' Windows Vista and Windows 7: This property may contain trailing characters. For example,
' the string "Microsoft Windows 7 Enterprise " (trailing space included) may be necessary
' to retrieve information using this property.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSCaption (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT Caption FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("Caption")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number, in minutes, an operating system is offset from Greenwich mean time (GMT).
' The number is positive, negative, or zero.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSCurrentTimeZone (BYREF wszServerName AS WSTRING = ".") AS USHORT
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT CurrentTimeZone FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("CurrentTimeZone"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Name of the registered user of the operating system. Example: "Ben Smith".
' ========================================================================================
PRIVATE FUNCTION AfxGetOSRegisteredUser (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT RegisteredUser FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("RegisteredUser")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Company name for the registered user of the operating system.
' Example: "Microsoft Corporation"
' ========================================================================================
PRIVATE FUNCTION AfxGetOSOrganization (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT Organization FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("Organization")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' The date in which the OS was installed.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSInstallDate (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT InstallDate FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("InstallDate")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Date and time the operating system was last restarted.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSLastBootUpTime (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT LastBootUpTime FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("LastBootUpTime")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Encryption level for secure transactions: 40-bit, 128-bit, or n-bit.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSEncryptionLevel (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT EncryptionLevel FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("EncryptionLevel"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number, in kilobytes, of physical memory currently unused and available.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSFreePhysicalMemory (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT FreePhysicalMemory FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("FreePhysicalMemory"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number, in kilobytes, that can be mapped into the operating system paging files without
' causing any other pages to be swapped out.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSFreeSpaceInPagingFiles (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT FreeSpaceInPagingFiles FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("FreeSpaceInPagingFiles"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number, in kilobytes, of virtual memory currently unused and available.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSFreeVirtualMemory (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT FreeVirtualMemory FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("FreeVirtualMemory"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Maximum number of process contexts the operating system can support. The default value
' set by the provider is 4294967295 (0xFFFFFFFF). If there is no fixed maximum, the value
' should be 0 (zero). On systems that have a fixed maximum, this object can help diagnose
' failures that occur when the maximum is reached—if unknown, enter 4294967295 (0xFFFFFFFF).
' ========================================================================================
PRIVATE FUNCTION AfxGetOSMaxNumberOfProcesses (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT MaxNumberOfProcesses FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("MaxNumberOfProcesses"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Maximum number, in kilobytes, of memory that can be allocated to a process.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSMaxProcessMemorySize (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT MaxProcessMemorySize FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("MaxProcessMemorySize"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number of process contexts currently loaded or running on the operating system.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSNumberOfProcesses (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT NumberOfProcesses FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("NumberOfProcesses"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number of user sessions for which the operating system is storing state information currently.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSNumberOfUsers (BYREF wszServerName AS WSTRING = ".") AS ULONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT NumberOfUsers FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("NumberOfUsers"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Number, in kilobytes, of virtual memory. For example, this may be calculated by adding
' the amount of total RAM to the amount of paging space, that is, adding the amount of
' memory in or aggregated by the computer system to the property, SizeStoredInPagingFiles.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSTotalVirtualMemorySize (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT TotalVirtualMemorySize FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("TotalVirtualMemorySize"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Total amount, in kilobytes, of physical memory available to the operating system. This
' value does not necessarily indicate the true amount of physical memory, but what is
' reported to the operating system as available to it.
' ========================================================================================
PRIVATE FUNCTION AfxGetOSTotalVisibleMemorySize (BYREF wszServerName AS WSTRING = ".") AS ULONGLONG
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT TotalVisibleMemorySize FROM Win32_OperatingSystem")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("TotalVisibleMemorySize"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Media Access Control (MAC) address of the network adapter. A MAC address is assigned by
' the manufacturer to uniquely identify the network adapter. Example: "00:80:C7:8F:6C:96".
' ========================================================================================
PRIVATE FUNCTION AfxGetNetworkAdapterMACAddress (BYREF wszServerName AS WSTRING = ".") AS DWSTRING
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\cimv2"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN ""
   pServices.ExecQuery("SELECT MACAddress FROM Win32_NetworkAdapterConfiguration")
   pServices.GetNamedProperties
   RETURN pServices.PropValue("MACAddress")
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Gets the physical sector size of the physical disk, in bytes. For example: for 4K native
' and 512-byte emulated disks, the value of this property should be 4096.
' ========================================================================================
PRIVATE FUNCTION AfxGetPhysicalDiskSectorSize (BYREF wszServerName AS WSTRING = ".") AS UINT64
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\Microsoft\Windows\Storage"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT PhysicalSectorSize FROM MSFT_PhysicalDisk")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("PhysicalSectorSize"))
END FUNCTION
' ========================================================================================
```
---

```
' ========================================================================================
' Gets the total physical storage size of the disk, in bytes.
' ========================================================================================
PRIVATE FUNCTION AfxGetPhysicalDiskSize (BYREF wszServerName AS WSTRING = ".") AS UINT64
   DIM pServices AS CWmiServices = $"winmgmts:{impersonationLevel=impersonate}!\\" & wszServerName & $"\root\Microsoft\Windows\Storage"
   DIM nError AS DWORD = GetLastError
   IF nError THEN AfxMsg(__FUNCTION__ & CHR(13,10) & "Error: &h" & HEX(nError, 8) & CHR(13,10) & AfxWmiGetErrorCodeText(nError))
   IF pServices.ServicesPtr = NULL THEN RETURN 0
   pServices.ExecQuery("SELECT Size FROM MSFT_PhysicalDisk")
   pServices.GetNamedProperties
   RETURN VAL(pServices.PropValue("Size"))
END FUNCTION
' ========================================================================================
```
---
