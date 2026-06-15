# CXmlLite Class

`CXmlLite` is a class that wraps the `XmlLite` interfaces.

The `XmlLite` library allows developers to build high-performance XML-based applications that provide a high degree of interoperability with other applications that adhere to the XML 1.0 standard. The primary goals of `XmlLite` are ease of use, performance, and standards compliance.

#### XmlLite Usage Scenarios

XML can be used as a format for storing documents, such as Microsoft Office Word documents. It can also be used to encode data for marshalling method calls across machine boundaries (SOAP). Businesses can use XML for sending and receiving purchase orders and invoices. Web technologies can use XML to send data between the Web server and the client's Web browser. Database servers can return the data from queries in XML for further processing by other applications. Because it is such a flexible format, XML can be used in a vast variety of scenarios.

The focus of `XmlLite` is on performance. `XmlLite` enables developers to write efficient (fast) code to read and write XML documents. In most scenarios, `XmlLite` parses faster than either the DOM in MSXML or SAX2 in MSXML.

Because `XmlLite` is oriented towards optimum performance, it does not provide for document validation. Validation via XSD schemas or DTDs is not supported. If you require validation, it is recommended that you use either MSXML or System.XML.

If you read a document that refers to an external XSD schema, the `XmlLite` reader ignores the external schema. Even if the document is invalid per the schema, the `XmlLite` reader will report no errors.

If you read a document that contains an inline schema, the `XmlLite` reader returns all of the elements and attributes of the inline schema, just as if they were parts of the XML document.

`XmlLite` does not support scripting languages. If you need to use XML from JScript or Visual Basic Scripting Edition (VBScript), it is more appropriate to use the Document Object Model (DOM) in MSXML.

Document Type Definitions (DTDs) are supported, but only for entity expansion and defaults for attributes, not for document validation. If you require DTD validation, it is recommended that you use either MSXML or System.XML.

If you enable DTDs, note the following: If you use `XmlLite` to read a document that refers to a DTD and the document is not valid per that DTD, no error will be thrown.

---

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#constructors) | Creates instances of the classes. |
| [Destructors](#destructors) | Destroys the classes and frees resources. |
| [GetErrorInfo](#geterrorinfo) | Returns a description of the last result code. |
| [GetLastResult](#getlastresult) | Returns the last result code. |
| [SetResult](#setresult) | Sets the last result code. |

| Name       | Description |
| ---------- | ----------- |
| [Enumerated types](#enumtypes) | Enumerated constants in the XmlLite programming interface. |
| [Error codes](#errorcodes) | XmlLite error codes and their associated symbolic codes and descriptions. |
| [IXmlReader Properties](#readerproperties) | Your application can get properties via the **GetProperty** (IXmlReader) method, and can set properties via the **SetProperty** (IXmlReader) method. |
| [IXmlWriter Properties](#writerproperties) | Your application can get properties via the **GetProperty** (IXmlWriter) method, and can set properties via the **SetProperty** (IXmlWriter) method. |

## CXmlReader

This class is a programming interface for reading XML.It implements the methods and properties that allow you to process XML.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [GetAttributeCount](#getattributecount) | Returns the number of attributes in the current node. |
| [GetBaseUri](#getbaseuri) | Gets the base URI of the token, if applicable. |
| [GetDepth](#getdepth) | Returns the depth of the current node in the document. |
| [GetLineNumber](#getlinenumber) | Gets the line number where the reader is positioned in the document. |
| [GetLinePosition](#getlinenposition) | Gets the line position where the reader is positioned in the document. |
| [GetLocalName](#getlocalname) | Allows the client to determine the difference between elements that have a closing tag, but do not contain content, and elements that do not have a closing tag. |
| [GetNamespaceUri](#getnamespaceuri) | Gets the namespace URI of the node that the reader is currently positioned on. |
| [GetNodeType](#getnodetype) | Provides the type of the current node. |
| [GetPrefix](#getprefix) | Gets the namespace prefix of the node that the reader is currently positioned on. |
| [GetProperty](#getpropertyreader) | Returns the specified property. A program can get properties at any time. |
| [GetQualifiedName](#getqualifiedname) | Gets the qualified name of the node that the reader is currently positioned on. |
| [GetValue](#getvalue) | Returns the value of the current token, if applicable. |
| [IsDefault](#isdefault) | Indicates whether the attribute was specified in the source document or implied by the Document Type Definition (DTD). |
| [IsEmptyElement](#isemptyelement) | Allows the client to determine the difference between elements that have a closing tag, but do not contain content, and elements that do not have a closing tag. |
| [IsEOF](#iseof) | Returns TRUE if the end of the input is reached. |
| [MoveToFirstAttribute](#movetofirstattribute) | Moves the reader position to the first attribute within the current node. |
| [MoveToNextAttribute](#movetonextattribute) | Advances the reader to the next attribute. |
| [MoveToAttributeByName](#movetoattributebyname) | Moves the reader to the attribute with the specified name. |
| [MoveToElement](#movetoelement) | Moves to the element that owns the current attribute node. |
| [Read](#read) | Reads the next node from the stream and returns the type of the node. |
| [ReadValueChunk](#readvaluechunk) | Reads up to a maximum of the specified chunk size (as available) from the value of the current node and copy the value into the specified buffer. |
| [SetInput](#setinput) | Sets the input source of the XML document to be parsed. |
| [SetProperty](#setpropertyreader) | Sets the specified property. |

---

## CXmlWriter Class

This class is a programming interface for writing XML.It implements the methods and properties that allow you write XML.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Flush](#flushwriter) | Flushes whatever is in the buffer to the underlying stream and then flushes the underlying stream. |
| [GetProperty](#getpropertywriter) | Returns the specified property. A program can get properties at any time. |
| [SetOutput](#setoutput) | Sets the output stream for the writer. |
| [SetProperty](#setpropertywriter) | Sets the specified property. |
| [WriteAttributes](#writeattributes) | Copies attributes from the specified source IXmlReader to the IXmlWriter. |
| [WriteAttributeString](#writeattributestring) | Writes an attribute. |
| [WriteCData](#writecdata) | Writes out a CDATA section that contains the specified text. |
| [WriteCharEntity](#writecharentity) | Writes a character entity for the provided Unicode character value. |
| [WriteChars](#writechars) | Writes out the specified text content, escaping markup. |
| [WriteComment](#writecomment) | Writes out a comment that contains the specified text. |
| [WriteDocType](#writedoctype) | Writes out the <!DOCTYPE ...> declaration with the specified name and optional attributes. |
| [WriteElementString](#writeelementstring) | Writes out an element with the specified prefix, name, namespace, and value. |
| [WriteEndDocument](#writeenddocument) | Closes any open elements or attributes, then closes the current document. |
| [WriteEndElement](#writeendelement) | Closes one element. |
| [WriteEntityRef](#writeentityref) | Writes out an entity reference with the specified name. |
| [WriteFullEndElement](#writefullendelement) | Closes one element and pops the corresponding namespace scope. |
| [WriteName](#writename) | Writes out the specified name, ensuring that the name is valid according to the XML specification. |
| [WriteNmToken](#writenmtoken) | Writes out the specified name, ensuring that the name is a valid NmToken according to the XML specification. |
| [WriteNode](#writenode) | Copies the current node from the specified source IXmlReader to the IXmlWriter. |
| [WriteNodeShallow](#writenodeshallow) | Copies the current node from the specified source IXmlReader to the IXmlWriter, without writing the children of the current node. |
| [WriteProcessingInstruction](#writeprocessinginstruction) | Writes a processing instruction. |
| [WriteQualifiedName](#writequalifiedname) |  Writes out the specified namespace-qualified name by looking up the prefix that is in scope for the specified namespace. |
| [WriteRaw](#writeraw) | Enables the caller to write out raw markup manually. |
| [WriteRawChars](#writerawchars) | Writes out raw markup manually. |
| [WriteStartDocument](#writestartdocument) | Writes out the XML declaration with the version "1.0". The encoding attribute is determinedby the implementation of IXmlWriterOutput. By default, the encoding is UTF-8. |
| [WriteStartElement](#writestartElement) | Writes out the specified start tag and associates it with the specified namespace. |
| [WriteString](#writestring) | Writes out the specified text content, escaping any markup in the content. |
| [WriteSurrogateCharEntity](#writesurrogatecharentity) | Forces the generation of a surrogate character entity for the specified string value. |
| [WriteWhitespace](#writewhitespace) | Writes out the specified white space. |

---

## CXmlWriterLite Class

This class is a programming interface for writing XML quickly, introduced in Windows 10. It implements an interface with most of the same methods as `IXmlWriter`, except for **WriteQualifiedName**. Some method signatures are slightly different between **IXmlWriter** and **IXmlWriterLite**. For more information, see the individual method topics. **IXmlWriterLite** can be used anywhere **IXmlWriter** is used. **IXmlWriterLite** is faster than **IXmlWriter** because it skips validation of namespaces and attributes, and does not maintain information that is required to automatically close tags. Use **IXmlWriterLite** when you can maintain complete XML document correctness in your code, and output speed is of highest importance. Otherwise, we recommend that you use **IXmlWriter** for its ease of coding and the XML validation it provides.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Flush](#flushwriter) | Flushes whatever is in the buffer to the underlying stream and then flushes the underlying stream. |
| [GetProperty](#getpropertywriter) | Returns the specified property. A program can get properties at any time. |
| [SetOutput](#setoutput) | Sets the output stream for the writer. |
| [SetProperty](#setpropertywriter) | Sets the specified property. |
| [WriteAttributes](#writeattributes) | Copies attributes from the specified source IXmlReader to the IXmlWriter. |
| [WriteAttributeString](#writeattributestringlite) | Writes an attribute. |
| [WriteCData](#writecdata) | Writes out a CDATA section that contains the specified text. |
| [WriteCharEntity](#writecharentity) | Writes a character entity for the provided Unicode character value. |
| [WriteChars](#writechars) | Writes out the specified text content, escaping markup. |
| [WriteComment](#writecomment) | Writes out a comment that contains the specified text. |
| [WriteDocType](#writedoctype) | Writes out the <!DOCTYPE ...> declaration with the specified name and optional attributes. |
| [WriteElementString](#writeelementstringlite) | Writes out an element with the specified prefix, name, namespace, and value. |
| [WriteEndDocument](#writeenddocument) | Closes any open elements or attributes, then closes the current document. |
| [WriteEndElement](#writeendelementlite) | Closes one element. |
| [WriteEntityRef](#writeentityref) | Writes out an entity reference with the specified name. |
| [WriteFullEndElement](#writefullendelementlite) | Closes one element and pops the corresponding namespace scope. |
| [WriteName](#writename) | Writes out the specified name, ensuring that the name is valid according to the XML specification. |
| [WriteNmToken](#writenmtoken) | Writes out the specified name, ensuring that the name is a valid NmToken according to the XML specification. |
| [WriteNode](#writenodewriter) | Copies the current node from the specified source IXmlReader to the IXmlWriter. |
| [WriteNodeShallow](#writenodeshallow) | Copies the current node from the specified source IXmlReader to the IXmlWriter, without writing the children of the current node. |
| [WriteProcessingInstruction](#writeprocessinginstruction) | Writes a processing instruction. |
| [WriteRaw](#writeraw) | Enables the caller to write out raw markup manually. |
| [WriteRawChars](#writerawchars) | Writes out raw markup manually. |
| [WriteStartDocument](#writestartdocument) | Writes out the XML declaration with the version "1.0". The encoding attribute is determinedby the implementation of IXmlWriterOutput. By default, the encoding is UTF-8. |
| [WriteStartElement](#writestartelementlite) | Writes out the specified start tag and associates it with the specified namespace. |
| [WriteString](#writestring) | Writes out the specified text content, escaping any markup in the content. |
| [WriteSurrogateCharEntity](#writesurrogatecharentity) | Forces the generation of a surrogate character entity for the specified string value. |
| [WriteWhitespace](#writewhitespace) | Writes out the specified white space. |

---

#### Example

```
'#CONSOLE ON
#define UNICODE
#define _WIN32_WINNT &h0602
'#define _CXMLLITE_DEBUG_ 1
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

SCOPE

DIM pWriter AS CXmlWriterLite
DIM hr AS HRESULT

' // Fake loop to avoid multiple IF/END IF nesting
DO
   
   ' // Create an output stream
   DIM pFileOutputStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("output.xml", STGM_CREATE OR STGM_WRITE, FILE_ATTRIBUTE_NORMAL, TRUE, NULL, @pFileOutputStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFileEx error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the output source
   hr = pWriter.SetOutput(cast(IUnknown PTR, pFileOutputStream))
   IF FAILED(hr) THEN
      PRINT "IXmlWriter.SetOutput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Write the XML document
   pWriter.WriteStartDocument(XmlStandalone_Yes)
   pWriter.WriteStartElement("bookstore")

   pWriter.WriteStartElement("book")
   pWriter.WriteAttributeString("category", "children")
      pWriter.WriteElementString("title", "Harry Potter")
      pWriter.WriteElementString("author", "J K. Rowling")
      pWriter.WriteElementString("year", "2005")
      pWriter.WriteElementString("price", "29.99")
   pWriter.WriteEndElement("book")

   pWriter.WriteEndElement("bookstore")
   pWriter.WriteEndDocument

   PRINT "XML file written successfully."
   PRINT "Press any key"
   SLEEP

   ' // Unconditional exit
   EXIT DO
LOOP

END SCOPE

SCOPE

DIM pReader AS CXmlReader
DIM hr AS HRESULT

DO
   ' // Open read-only input stream
   DIM pFileInputStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("output.xml", STGM_READ, FILE_ATTRIBUTE_NORMAL, FALSE, NULL, @pFileInputStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the DtdProcessing_Prohibit property
   hr = pReader.SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)

   ' // Set the input source of the XML document to be parsed
   hr = pReader.SetInput(cast(IUnknown PTR, pFileInputStream))
   IF FAILED(hr) THEN
      PRINT "IXmlReader.SetInput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Parse the xml file
   DIM nodeType AS XmlNodeType
   DO
      hr = pReader.Read(@nodeType)
      IF hr <> S_OK THEN EXIT DO
      SELECT CASE nodeType
      CASE XmlNodeType_Element
         PRINT "Element: "; pReader.GetLocalName
         ' // If the element has attributes, iterate through them
         IF pReader.MoveToFirstAttribute = S_OK THEN
            DO
               PRINT "  Attribute: "; pReader.GetLocalName; " = "; pReader.GetValue
            LOOP WHILE pReader.MoveToNextAttribute = S_OK
            pReader.MoveToElement ' return to the element
         END IF
      CASE XmlNodeType_Text
         PRINT "Value: "; pReader.GetValue
      CASE XmlNodeType_EndElement
         PRINT "End element: "; pReader.GetLocalName
      END SELECT

   LOOP

   ' // Unconditional exit
   EXIT DO
LOOP

END SCOPE

PRINT
PRINT "Press any key"
SLEEP
```
---

## <a name="enumtypes"></a>Enumerated types

Enumerated constants in the `XmlLite` programming interface.

### DtdProcessing enumeration

Values that indicate how an IXmlWriter processes a Document Type Definition (DTD).
```
enum DtdProcessing
    DtdProcessing_Prohibit = 0
    DtdProcessing_Parse = 1  
end enum
```
#### DtdProcessing_Prohibit

Prohibits DTDs in the input XML. If a DTD is detected in the input, the parser will return an error and move reader to an error state. Further calls to the reader will continue to return errors and the reader will be in error state. The reader can be reset by calling SetInput(NULL).

#### DtdProcessing_Parse

Allows DTDs in the document and will parse DTDs as per the XML 1.0 specification.

#### XmlConformanceLevel enumeration

Values for specifying the conformance level on an IXmlReader.

```
enum XmlConformanceLevel
    XmlConformanceLevel_Auto = 0
    XmlConformanceLevel_Document = 1
    XmlConformanceLevel_Fragment = 2
end enum
```

#### XmlConformanceLevel_Auto

The reader automatically detects whether to perform document or fragment checking.

#### XmlConformanceLevel_Document

The input should be a well-formed XML document as defined in the XML specification For more information, see the Extensible Markup Language (XML) 1.0 Specification.

#### XmlConformanceLevel_Fragment

The input should be treated as a XML fragment. In this case, the input should conform to the Well-Formed Parsed Entities section of the XML specification. For more information, see Section 4.3.2 of the Extensible Markup Language (XML) 1.0 Specification.

This value is not supported for IXmlReader in this release. IXmlWriter does support this setting.

### XmlNodeType enumeration

Values that indicate the type of a current node.
```
enum XmlNodeType
    XmlNodeType_None = 0
    XmlNodeType_Element = 1
    XmlNodeType_Attribute = 2
    XmlNodeType_Text = 3
    XmlNodeType_CDATA = 4
    XmlNodeType_ProcessingInstruction = 7
    XmlNodeType_Comment = 8
    XmlNodeType_DocumentType = 10
    XmlNodeType_Whitespace = 13
    XmlNodeType_EndElement = 15
    XmlNodeType_XmlDeclaration = 17
end enum
```
#### XmlNodeType_None

Node type: none.

#### XmlNodeType_Element

Node type: Element.

#### XmlNodeType_Attribute

Node type: Attribute.

#### XmlNodeType_Text

Node type: Text.

#### XmlNodeType_CDATA

Node type: CDATA.

#### XmlNodeType_ProcessingInstruction

Node type: ProcessingInstruction.

#### XmlNodeType_Comment

Node type: Comment.

#### XmlNodeType_DocumentType

Node type: DocumentType.

#### XmlNodeType_Whitespace

Node type: Whitespace.

#### XmlNodeType_EndElement

Node type: EndElement.

#### XmlNodeType_XmlDeclaration

Node type: XmlDeclaration.

### XmlReadState enumeration

Values that indicate the state of an IXmlReader.
```
enum XmlReadState
    XmlReadState_Initial = 0
    XmlReadState_Interactive = 1
    XmlReadState_Error = 2
    XmlReadState_EndOfFile = 3
    XmlReadState_Closed = 4
```
#### XmlReadState_Initial

The state the reader is in after the input to the reader has been initialized. For example, **SetInput** has been successfully called.

#### XmlReadState_Interactive

The state the reader is in during parsing. Typically, the reader enters this state after the first call to Read. The reader remains in this state until it reaches the end of the file, an unrecoverable error occurs, or the underlying stream is closed.

#### XmlReadState_Error

The state the reader is in when unrecoverable errors are encountered.

#### XmlReadState_EndOfFile

The state the reader is in when the end of file is reached.

#### XmlReadState_Closed

The state the reader is in when the underlying stream is closed. This is also the initial state the reader is in when the reader is created.

### XmlStandalone enumeration

Values that indicate how an IXmlWriter produces the standalone attribute of the XML declaration.
```
enum XmlStandalone
    XmlStandalone_Omit = 0
    XmlStandalone_Yes = 1
    XmlStandalone_No = 2
end enum
```
#### XmlStandalone_Omit

Omits the standalone attribute.

#### XmlStandalone_Yes

Writes the standalone attribute with the value "yes".

#### XmlStandalone_No

Writes the standalone attribute with the value "no".

---

## <a name="errorcodes"></a>Error codes

XmlLite error codes and their associated symbolic codes and descriptions.

| Symbol | Hex code | Description |
| ------ | -------- | ----------- |
| MX_E_INPUTEND | &hC00CEE01 | unexpected end of input |
| MX_E_ENCODING | &hC00CEE02 | unrecognized encoding |
| MX_E_ENCODINGSWITCH | &hC00CEE03 | unable to switch the encoding |
| MX_E_ENCODINGSIGNATURE | &hC00CEE04 | unrecognized input signature |
| WC_E_WHITESPACE | &hC00CEE21 | whitespace expected |
| WC_E_SEMICOLON | 0xC00CEE22 | semicolon expected |
| WC_E_GREATERTHAN | &hC00CEE23 | '>' expected |
| WC_E_QUOTE | &hC00CEE24 | quote expected |
| WC_E_EQUAL | &hC00CEE25 | equal expected |
| WC_E_LESSTHAN | &hC00CEE26 | well-formedness constraint: no '<' in attribute value |
| WC_E_HEXDIGIT | &hC00CEE27 | hexadecimal digit expected |
| WC_E_DIGIT | &hC00CEE28 | decimal digit expected |
| WC_E_LEFTBRACKET | &hC00CEE29 | '\[' expected |
| WC_E_LEFTPAREN | &hC00CEE2A | '(' expected |
| WC_E_XMLCHARACTER | &hC00CEE2B | illegal xml character |
| WC_E_NAMECHARACTER | &hC00CEE2C | illegal name character |
| WC_E_SYNTAX | &hC00CEE2D | incorrect document syntax |
| WC_E_CDSECT | &hC00CEE2E | incorrect CDATA section syntax |
| WC_E_COMMENT | &hC00CEE2F | incorrect comment syntax |
| WC_E_CONDSECT | 0&h00CEE30 | incorrect conditional section syntax |
| WC_E_DECLATTLIST | &hC00CEE31 | incorrect ATTLIST declaration syntax |
| WC_E_DECLDOCTYPE | &hC00CEE32 | incorrect DOCTYPE declaration syntax |
| WC_E_DECLELEMENT | &hC00CEE33 | incorrect ELEMENT declaration syntax |
| WC_E_DECLENTITY | &hC00CEE34 | incorrect ENTITY declaration syntax |
| WC_E_DECLNOTATION | &hC00CEE35 | incorrect NOTATION declaration syntax |
| WC_E_NDATA | &hC00CEE36 | NDATA expected |
| WC_E_PUBLIC | &hC00CEE37 | PUBLIC expected |
| WC_E_SYSTEM | &hC00CEE38 | SYSTEM expected |
| WC_E_NAME | &hC00CEE39 | name expected |
| WC_E_ROOTELEMENT | 0&h00CEE3A | one root element |
| WC_E_ELEMENTMATCH | &hC00CEE3B | well-formedness constraint: element type match |
| WC_E_UNIQUEATTRIBUTE | &hC00CEE3C | well-formedness constraint: unique attribute spec |
| WC_E_TEXTXMLDECL | &hC00CEE3D | text/xmldecl not at the beginning of input |
| WC_E_LEADINGXML | &hC00CEE3E | leading "xml" |
| WC_E_TEXTDECL | &hC00CEE3F | incorrect text declaration syntax |
| WC_E_XMLDECL | &hC00CEE40 | incorrect xml declaration syntax |
| WC_E_ENCNAME | &hC00CEE41 | incorrect encoding name syntax |
| WC_E_PUBLICID | &hC00CEE42 | incorrect public identifier syntax |
| WC_E_PESINTERNALSUBSET | &hC00CEE43 | well-formedness constraint: pes in internal subset |
| WC_E_PESBETWEENDECLS | &hC00CEE44 | well-formedness constraint: pes between declarations |
| WC_E_NORECURSION | &hC00CEE45 | well-formedness constraint: no recursion |
| WC_E_ENTITYCONTENT | &hC00CEE46 | entity content not well formed |
| WC_E_UNDECLAREDENTITY | &hC00CEE47 | well-formedness constraint: undeclared entity |
| WC_E_PARSEDENTITY | &hC00CEE48 | well-formedness constraint: parsed entity |
| WC_E_NOEXTERNALENTITYREF | &hC00CEE49 | well-formedness constraint: no external entity references |
| WC_E_PI | &hC00CEE4A | incorrect processing instruction syntax |
| WC_E_SYSTEMID | &hC00CEE4B | incorrect system identifier syntax |
| WC_E_QUESTIONMARK | &hC00CEE4C | '?' expected |
| WC_E_CDSECTEND | &hC00CEE4D | no ']]>' in element content |
| WC_E_MOREDATA | &hC00CEE4E | not all chunks of value have been read |
| WC_E_DTDPROHIBITED | &hC00CEE4F | DTD was found but is prohibited |
| WC_E_INVALIDXMLSPACE | &hC00CEE50 | xml:space attribute with invalid value |
| NC_E_QNAMECHARACTER | &hC00CEE61 | illegal qualified name character |
| NC_E_QNAMECOLON | &hC00CEE62 | multiple colons in qualified name |
| NC_E_NAMECOLON | &hC00CEE63 | colon in name |
| NC_E_DECLAREDPREFIX | &hC00CEE64 | declared prefix |
| NC_E_UNDECLAREDPREFIX | &hC00CEE65 | undeclared prefix |
| NC_E_EMPTYURI | &hC00CEE66 | non default namespace with empty uri |
| NC_E_XMLPREFIXRESERVED | &hC00CEE67 | "xml" prefix is reserved and must have the http://www.w3.org/XML/1998/namespace URI |
| NC_E_XMLNSPREFIXRESERVED | &hC00CEE68 | "xmlns" prefix is reserved for use by XML |
| NC_E_XMLURIRESERVED | &hC00CEE69 | xml namespace URI (http://www.w3.org/XML/1998/namespace) must be assigned only to prefix "xml" |
| NC_E_XMLNSURIRESERVED | &hC00CEE6A | xmlns namespace URI (http://www.w3.org/2000/xmlns/) is reserved and must not be used |
| SC_E_MAXELEMENTDEPTH | &hc00cee81 | element depth exceeds limit in XmlReaderProperty_MaxElementDepth |
| SC_E_MAXENTITYEXPANSION | 0xc00cee82 | entity expansion exceeds limit in XmlReaderProperty_MaxEntityExpansion |
| WR_E_NONWHITESPACE | &hC00CEF01 | writer: specified string is not whitespace |
| WR_E_NSPREFIXDECLARED | &hC00CEF02 | writer: namespace prefix is already declared with a different namespace |
| WR_E_NSPREFIXWITHEMPTYNSURI | &hC00CEF03 | writer: It is not allowed to declare a namespace prefix with empty URI (for example xmlns:p=””). |
| WR_E_DUPLICATEATTRIBUTE | &hC00CEF04 | writer: duplicate attribute |
| WR_E_XMLNSPREFIXDECLARATION | &hC00CEF05 | writer: can not redefine the xmlns prefix |
| WR_E_XMLPREFIXDECLARATION | &hC00CEF06 | writer: xml prefix must have the http://www.w3.org/XML/1998/namespace URI |
| WR_E_XMLURIDECLARATION | &hC00CEF07 | writer: xml namespace URI (http://www.w3.org/XML/1998/namespace) must be assigned only to prefix "xml" |
| WR_E_XMLNSURIDECLARATION | &hC00CEF08 | writer: xmlns namespace URI (http://www.w3.org/2000/xmlns/) is reserved and must not be used |
| WR_E_NAMESPACEUNDECLARED | &hC00CEF09 | writer: namespace is not declared |
| WR_E_INVALIDXMLSPACE | &hC00CEF0A | writer: invalid value of xml:space attribute (allowed values are "default" and "preserve") |
| WR_E_INVALIDACTION | &hC00CEF0B | writer: performing the requested action would result in invalid XML document |
| WR_E_INVALIDSURROGATEPAIR | &hC00CEF0C | writer: input contains invalid or incomplete surrogate pair |
| XML_E_INVALID_DECIMAL | &hC00CE01D | character in character entity is not a decimal digit as was expected. |
| XML_E_INVALID_HEXIDECIMAL | &hC00CE01E | character in character entity is not a hexadecimal digit as was expected. |
| XML_E_INVALID_UNICODE | &hC00CE01F | character entity has invalid Unicode value. |

## <a name="readerproperties"></a>IXmlReader properties

Your application can get properties via the **GetProperty** method, and can set properties via the **SetProperty** method. |

| Property | Description |
| -------- | ----------- |
| *XmlReaderProperty_ConformanceLevel* | Specifies which level of conformance should be checked by the reader. |
| *XmlReaderProperty_DtdProcessing* | Specifies whether Document Type Definitions (DTDs) are prohibited or allowed in the document. |
| *XmlReaderProperty_MaxElementDepth* | Allows the user to set the maximum levels of nesting in elements. |
| *XmlReaderProperty_MaxEntityExpansion* | Allows the user to set the maximum number of entities that resolves to 3 or more characters. |
| *XmlReaderProperty_MultiLanguage* | A pointer to an instance of **IMultiLanguage2** (MLANG). |
| *XmlReaderProperty_RandomAccess* | Indicates whether the reader should use random access on the input stream. |
| *XmlReaderProperty_ReadState* | Reports the state of the reader. |
| *XmlReaderProperty_XmlResolver* | Provides an implementation of the **IXmlResolver** interface for the reader to enable external entity resolution. |

#### Note

These "properties" are actually implemented just as individual constants within the *XmlReaderProperty* enumerated type. However, because these constants signify different characteristics of the XML reader, they have been treated separately.

---

## <a name="writerproperties"></a>IXmlWriter properties

Your application can get properties via the **GetProperty** method, and can set properties via the **SetProperty** method. |

| Property | Description |
| -------- | ----------- |
| *XmlWriterProperty_ByteOrderMark* | Specifies whether the writer should write a Byte Order Mark (BOM) to the beginning of the output. |
| *XmlWriterProperty_ConformanceLevel* | Specifies which level of conformance should be output by the writer. |
| *XmlWriterProperty_Indent* | Specifies whether to indent the XML output. |
| *XmlWriterProperty_MultiLanguage* | Specifies an implementation of the **IMultiLanguage2** to use for encodings which are not natively supported. |
| *XmlWriterProperty_OmitXmlDeclaration* | Specifies whether the writer should omit the XML declaration at the beginning of the document. |
	
#### Note

These "properties" are actually implemented just as individual constants within the *XmlWriterProperty* enumerated type. However, because these constants signify different characteristics of the XML writer, they have been treated separately.

---

## Constructors

```
CONSTRUCTOR CXmlReader
```
Deault constructor. Creates a new `IXmlReader`. After creating the reader, the input stream for the reader can be set by using the **SetOutput** method of the reader.
```
CONSTRUCTOR CXmlReader (BYVAL pInputStream AS IUnknown PTR, BYVAL nEncodingPage AS UINT, _
   BYVAL fEncodingHint AS BOOLEAN = FALSE, BYVAL pwszBAseURi AS LPCWSTR = NULL)
```
Creates an instance of `IXmlReader` with the provided parameters. This is normally used when the input stream does not have a BOM.
```
CONSTRUCTOR CXmlReader (BYVAL pInputStream AS IUnknown PTR, BYVAL LPCWSTR AS LPCWSTR, _
   BYVAL fEncodingHint AS BOOLEAN = FALSE, BYVAL pwszBAseURi AS LPCWSTR = NULL)
```
Creates an instance of IXmlReader with the provided parameters. This is normally used when the input stream does not have a BOM.

```
CONSTRUCTOR CXmlWriter
```
Deault constructor. Creates a new `IXmlWriter`. After creating the writer, the output stream for the writer can be set by using the **SetOutput** method of the writer.
```
CONSTRUCTOR CXmlWriter (BYVAL pOutputStream AS IUnknown PTR, BYVAL nEncodingPage AS UINT)
```
Creates an instance of `IXmlWriter` with the specified parameters.
```
CONSTRUCTOR CXmlWriter (BYVAL pOutputStream AS IUnknown PTR, BYVAL nEncodingPage AS LPCWSTR)
```
Creates an instance of `IXmlWriter` with the specified parameters.

```
CONSTRUCTOR CXmlWriterLite
```
Deault constructor. Creates a new `IXmlWriterLite`. After creating the writer, the output stream for the writer can be set by using the **SetOutput** method of the writer.
```
CONSTRUCTOR CXmlWriterLite (BYVAL pOutputStream AS IUnknown PTR, BYVAL nEncodingPage AS UINT)
```
Creates an instance of `IXmlWriterLite` with the specified parameters.
```
CONSTRUCTOR CXmlWriterLite (BYVAL pOutputStream AS IUnknown PTR, BYVAL nEncodingPage AS LPCWSTR)
```
Creates an instance of `IXmlWriterLite` with the specified parameters.

---

## Destructors

Destroys the classes and frees resources.

```
DESTRUCTOR CXmlReader
```
```
DESTRUCTOR CXmlWriter
```
```
DESTRUCTOR CXmlWriterLite
```

---

## GetErrorInfo

Returns a description of the last result code.

```
FUNCTION GetErrorInfo (BYVAL nError AS LONG = -1) AS DWSTRING
```
---

## GetLastResult

Returns the result code returned by the last executed method.

```
FUNCTION GetLastResult () AS HRESULT
```
---

## SetResult

Sets the last result code.
```
FUNCTION SetResult (BYVAL Result AS HRESULT) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *Result* | The **HRESULT** error code returned by the methods. |

---

## GetAttributeCount

Returns the number of attributes in the current node.
```
FUNCTION GetAttributeCount () AS UINT
```

#### Remarks

For `Element`, `XmlDeclaration`, and `DocumentType` nodes, this method returns the number of attributes for the node.

For `Attribute` nodes, the method returns the number of attributes for the `Element` node that owns the current attribute.

For any other nodes the method returns 0.

Consider the following example:
```
<?xml version="1.0" encoding="utf-8" ?>  
<book name=”My Funny Book” publisher="Funny Book Press" address="123 Infinite Loop">  
    ...  
</book>
```
While on the `xml` declaration, `version`, or `encoding`, the attribute count will be 2.

While on `book`, `name`, `publisher`, or `address` the attribute count will be 3.

This method allows the application writer to inspect the number of attributes on the node. This enables the allocation of an appropriate amount of memory for storing the attributes if necessary. This can provide performance benefits.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetBaseUri

Gets the base URI of the token, if applicable.

```
FUNCTION GetBaseUri () AS DWSTRING
```

#### Remarks

The base URI tells you where the nodes came from. If there is no base URI for the nodes being returned (for example, if the nodes were parsed from an in-memory string), the base URI is an empty string.

When parsing the content of an element, the base URI can change. This is most often the case when using streaming APIs such as **ReadValueChunk**. For example, suppose you have an element node that contains text content which includes an entity reference:
```
<item>1234&ref1;5678</item> 
```
When positioned on the text `1234`, the base URI is reported as the base URI of the document. When positioned on the `&ref1`; entity reference, the base URI is reported as the resolved location for the entity if the entity contains markup and is external to the document. An example of an entity with markup is:
```
<!ENTITY ref1 "<a>Hello XML Markup</a>">
```
If the entity is just text with no markup, the XML parsing continues until the end of the next element is reached (in the previous example, `</item>`). Therefore, the base URI property is always the same as the base URI for the document. For example, an element that contains the following entity reference (`&ref2;`) does not have a different base URI for that entity reference:
```
<!ENTITY ref2 "just some text">
```
The only time the base URI property for an entity reference that contains only text can be different from the base URI of the document is when the `ResolveUri` method is called on `IXmlResolver`.

Another case where the base URI can change during parsing is when an XML document is composed of chunks of data aggregated from Document Type Definitions (DTDs). See the W3C XML specification for more details. The granularity of base URI information in that specification applies to this property.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetDepth

Returns the depth of the current node in the document.
```
FUNCTION GetDepth () AS UINT
```
#### Remarks

The depth is the level of nesting of the current node. The depth of an attribute is one greater than the depth of the element that contains it.

This method is intended to be used primarily to defend against denial of service attacks in which a malicious XML document could cause a malfunction in the parser due to excessively nested nodes.

Retrieving the depth while positioned on an `XmlNodeType_Element` or `XmlNodeType_EndElement` node returns the depth before processing the node. For example, consider the following document:
```
<Parent>  
<Child>  
</Child>  
</Parent>
```
When positioned on the `<Parent>` start node, the depth is reported as 0.

When positioned on the `<Child>` start node, the depth is reported as 1.

When positioned on the `</Child>` end node, the depth is reported as 2.

When positioned on the `</Parent>` end node, the depth is reported as 1.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetLineNumber

Gets the line number where the reader is positioned in the document.
```
FUNCTION GetLineNumber () AS UINT
```

#### Remarks

This method is most useful for reporting the line number if an error occurs.

The starting number is 1. For example, if the XML document is `<root/>` and the reader is on `<`, the line number is 1 and the line position is 1.

When you are about to read a node that contains whitespace and text, this method returns the line number of the first non-whitespace text. This may not be what you expect; you may expect the line number of the start of the node. However, XmlLite's focus is on high performance, and for performance the reader advances to the first non-whitespace text. This method returns the line number where the reader is currently positioned in the document, not the line number of the start of the next node.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetLinePosition

Gets the line position where the reader is positioned in the document.
```
FUNCTION GetLinePosition () AS UINT
```

#### Remarks

This method is most useful for reporting the position on the line if an error occurs.

The starting number is 1. For example, if the XML document is `<root/>` and the reader is on `<`, the line number is 1 and the line position is 1.

When you are about to read a node that contains whitespace and text, this method returns the position of the first non-whitespace text. This may not be what you expect; you may expect the position of the first character of the node. However, XmlLite's focus is on high performance, and for performance the reader advances to the first non-whitespace text. This method returns the line position where the reader is positioned in the document, not the first position of the next node.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetLocalName

Gets the local name of the node that the reader is currently positioned on. If no local name is available, this method returns an empty string.
```
FUNCTION GetLocalName () AS DWSTRING
```
#### Return value

The local name of the node that the reader is currently positioned on. The returned string is always NULL terminated.

If no local name is available, the returned string is empty.

#### Remarks

If the reader is positioned on the element `<p:abc/>`, for example, this method returns the string "abc"

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetNamespaceUri

Gets the namespace URI of the node that the reader is currently positioned on. If no namespace URI is available, returns an empty string.
```
FUNCTION GetNamespaceUri () AS DWSTRING
```

#### Return value

The namespace URI of the node that the reader is currently positioned on. The returned string is always NULL terminated.

If no namespace URI is available, the returned string is empty.

#### Remarks

For example, returns `"u://1"` for the element `<xyz:abc xmlns:xyz="u://1" />`.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetNodeType

Returns the type of the current node.
```
FUNCTION GetNodeType () AS XmlNodeType 
```

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetPrefix

Gets the namespace prefix of the node that the reader is currently positioned on. If no prefix is available, returns an empty string.
```
FUNCTION GetPrefix () AS DWSTRING
```
#### Remarks

This method returns the namespace prefix. For example, if you call this method for an element `<xyz:abc xmlns:xyz="u://1" />`, it returns `"xyz"`.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## <a name="getpropertyreader"></a>GetProperty (CXmlReader)

Returns the specified property. A program can get properties at any time.
```
FUNCTION GetProperty (BYVAL nProperty AS UINT) AS LONG_PTR
```
#### Return value

The enumeration that identifies the property to be retrieved. For more information, see **IXmlReader Properties**.

#### GetLastResult

Returns S_OK if no error is generated. If an invalid property name is passed, returns E_NOTIMPL.

#### Remarks

Although, most of the values returned are native or simple types, a few are COM objects. For example, the **XmlReaderProperty_MultiLanguage** property references a COM **IMultiLanguage2** instance. In these cases, the pointer returned by a successful call to the **GetProperty** method should be released through a call to the standard COM **IUnknown.Release** function.

---

## GetQualifiedName

Gets the qualified name of the node that the reader is currently positioned on. If no qualified name is available, returns an empty string.
```
FUNCTION GetQualifiedName () AS DWStRING
```
#### Remarks

This method does not expand namespace prefixes. For example, if the reader is positioned on the element `<p:abc />`, this method returns the string "p:abc".

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## GetValue

Returns the value of the current token, if applicable.
```
FUNCTION GetValue () AS DWSTRING
```
#### Remarks

Returns the value of the current token, if applicable. This method does not process or interpret the value returned.

This method does not return to the start of a value that has already been partially read. In other words, if **ReadValueChunk** has already been called while the reader is positioned on this text node, **GetValue** will return only the part of the value that has not already been read.

This method returns an empty string if the reader is positioned on an element node.

When the reader is positioned on a processing instruction, this method returns the content of the processing instruction. For example, when the reader is positioned on the text node of the processing instruction `<?xyz abc?>`, **GetValue** returns the string "abc".

When the reader is positioned on the content of a document type declaration, **GetValue** returns the content of the internal Document Type Definition (DTD) that is referenced by the document type declaration.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## IsDefault

Indicates whether the attribute was specified in the source document or implied by the Document Type Definition (DTD).
```
FUNCTION IsDefault () AS BOOLEAN
```
#### Return value

Returns TRUE if the attribute was implied by the DTD. If the attribute was not implied by the DTD, or the node is not an attribute, returns FALSE.

#### Remarks

Because DTDs allow only attributes to be defined with defaults, this property is TRUE only for attribute nodes.

---

## IsEmptyElement

This method allows the client to determine the difference between elements that have a closing tag, but do not contain content, and elements that do not have a closing tag.
```
FUNCTION IsEmptyElement () AS BOOLEAN
```

#### Return value

Returns TRUE if the current element ends with />; otherwise, returns FALSE.

#### Remarks

**IsEmptyElement** returns FALSE for the following element:
```
<element attribute="123"></element>  
```
**IsEmptyElement** returns TRUE for the following element:
```
<element attribute="123"/>  
```
Note that when writing elements, an `XmlNodeType_EndElement` node is not generated for empty element start tags.

If the method is not applicable, it will return FALSE.

You should save the value of **IsEmptyElement** before processing attributes, or call **MoveToElement** to make **IsEmptyElement** valid after processing attributes.

**IsEmptyElement** returns FALSE when `XmlReader` is positioned on an attribute node, even if attribute's parent element is empty.

---

## IsEOF

Returns TRUE if the end of the input is reached.
```
FUNCTION IsEOF () AS BOOLEAN
```
---

## MoveToFirstAttribute

Moves the reader position to the first attribute within the current node.
```
FUNCTION MoveToFirstAttribute () AS HRESULT
```
#### Return value

Returns **S_OK** if no error is generated. Returns **E_PENDING** if the data is unavailable, and the stream is paused. If there are no attributes on the current node, returns **S_FALSE** and does not move the position of the reader.

#### Remarks

This method is most often used to return to the beginning of the attribute list. If the data is unavailable this method returns **E_PENDING** and the reader does not move forward.

After this method is called, the attributes collection on the element is still accessible; the application can then call other methods that move the reader within the attributes collection.

---

## MoveToNextAttribute

Advances the reader to the next attribute.
```
FUNCTION MoveToNextAttribute () AS HRESULT
```
#### Return value

Returns **S_OK** if no error is generated. Returns **E_PENDING** if the data is unavailable, and the stream is paused. Returns **S_FALSE** if there are no more attributes on this element.

#### Remarks

This method moves the reader through the list of attributes. Moving through attributes invalidates properties for the element, because the element properties are replaced with attribute properties. If the attribute is unavailable this method returns **E_PENDING** and the stream is paused. If there are no more attributes, this method returns **S_FALSE** and the reader does not move forward. If the reader is positioned on an element, this method moves the reader to the first attribute of the element.

After this method is called, the attributes collection on this element is still accessible. The application can then call other methods that move the reader within the attributes collection.

---

## MoveToAttributeByName

Moves the reader to the attribute with the specified name.
```
FUNCTION MoveToAttributeByName (BYVAL pwszLocalName AS LPCWSTR, BYVAL pwszNamespaceUri AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszLocalName* | The local name of the attribute. |
| *pwszNamespaceUri* | The namespace of the attribute. If pwszNamespaceUri is NULL, the search will match only attributes with no namespaces. |

#### Return value

Returns **S_OK** if no error is generated. Returns **E_PENDING** if the data is unavailable, and the stream is paused. If the attribute is not found, this method returns **S_FALSE** and leaves the position of the reader unchanged.

#### Remarks

This method is implemented as a convenience. You can use this method if you have to get the value of one or two attributes, and you are not very concerned about performance.

Using this method frequently might decrease performance. The normal programming pattern is to iterate through all of the attributes on an element and save all values in a data construct that is under your own control. Calling this method does not allow the parser to return all attributes in the most efficient manner.

After this method is called, the attributes collection on this element is still accessible. The application can then call other methods that move the reader within the attributes collection.

If the attribute is temporarily unable to be read this method returns **E_PENDING**.

---

## MoveToElement

Moves to the element that owns the current attribute node. After navigating through the attributes on an element, use this method to move the reader back to the element.
```
FUNCTION MoveToElement () AS HRESULT
```
#### Remarks

This method behaves the same way for attributes of elements within the document itself, attributes of an `XmlNodeType_XmlDeclaration`, and attributes of an `XmlNodeType_DocumentType` declaration.

#### GeLastResult

Returns **S_OK** if no error is generated.

---

## Read

Reads the next node from the stream and returns the type of the node.
```
FUNCTION Read (BYVAL nodeType AS XmlNodeType PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *nodeType* | Returns the type of node that is read. This value can be NULL, in which case the node type will not be returned. |

#### Return value

Returns **S_OK** if no error is generated. Returns **E_PENDING** if the data is unavailable, and the stream is paused. At the end of the input stream, returns **S_FALSE**.

#### Remarks

In `XmlLite`, the reader is positioned on a node. When you get the value and attributes of the node, you get them for the node on which the reader is positioned. The Read method moves the position of the reader to the next node in the stream; subsequent calls to the methods that get the values, name, and attributes return them for the new node.

This method skips attributes. To read attributes use the **MoveToFirstAttribute**, **MoveToNextAttribute**, and **MoveToAttributeByName** methods.

This method returns **E_PENDING** if the data is unavailable, and the stream is paused. The handling of the **E_PENDING** return value is up to the calling method.

---

## ReadValueChunk

This method will read up to a maximum of the specified chunk size (as available) from the value of the current node and copy the value into the specified buffer.
```
FUNCTION ReadValueChunk (BYVAL buffer AS WSTRING PTR, BYVAL chunkSize AS UINT, BYVAL pcwchRead AS UINT PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *buffer* | You must pass in a buffer that is at least *chunkSize* characters long. The value of the token will be read into the buffer. |
| *chunkSize* | The chunk size required, in characters. Any value from 0 to 4G is valid for chunk size. |
| *pcwchRead* | The size of the string read. This argument cannot be NULL. |

#### Return value

Returns **S_OK** if no error is generated. Returns **E_PENDING** if the data is unavailable, and the stream is paused. Returns **S_FALSE** if no more content is available to be read.

#### Remarks

The size of the buffer should be greater than or equal to that of the specified chunk size.

If the remaining value is shorter than the required chunk size, the method will return only the remaining value and notify the call through the pcwchRead argument of its size.

This method will not span a surrogate pair. When the number of characters requested would split a surrogate pair, this method returns one fewer character than the number requested.

If the content is temporarily unable to be read this method returns **E_PENDING** and does not move forward.

#### Usage example
```
DIM buffer AS WSTRING * 128   ' room for 128 characters
DIM cbRead AS UINT
DIM hr AS HRESULT

DO
    hr = pReader.ReadValueChunk(@buffer, 127, @cbRead)
    IF hr = S_OK AND cbRead > 0 THEN
        PRINT buffer
    END IF
LOOP WHILE hr = S_OK AND cbRead > 0
```
---

## SetInput

Sets the input source of the XML document to be parsed.
```
FUNCTION SetInput (BYVAL pInputStream AS IUnknown PTR) AS HRESULT
FUNCTION SetInput (BYVAL pInputStream AS IUnknown PTR, BYVAL nEncodingPage AS UINT) AS HRESULT
FUNCTION SetInput (BYVAL pInputStream AS IUnknown PTR, BYVAL nEncodingName AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pInputStream* | The input stream to be parsed. |

#### GeLastResult

Returns **S_OK** if no error is generated.

#### Remarks

The input source can be one of the following types:

A class derived from `IStream` or `ISequentialStream`. The reader will use defaults for all the additional properties of the input.

A code page:

* UTF-8 (65001) -> Universal option, recommended for almost all projects.
* UTF-16 (1200/1201) -> When working with Windows APIs or requiring internal compatibility.
* ISO-8859-1 / Windows-1252 -> Only for compatibility with older European systems.
* Asian code pages -> Only if required by the target system.

An encoding string:

* "utf-8" -> Universal option, recommended for almost all projects.
* "utf-16" -> When working with Windows APIs or requiring internal compatibility.
* "ISO-8859-1" -> For compatibility with older European systems.
* "windows-1252"  > For compatibility with older European systems.

NULL. This resets the input, releasing the previously set input object.

#### Subtle points

If you pass "utf-8" as a name, **XmlLite** will honor the XML declaration and BOM if present.

If you pass a code page, **XmlLite** uses that as a hard hint, even if the XML declaration disagrees. That's useful for legacy files but can override the document's self-declared encoding.

BOM presence is critical for utf-16 detection. Without BOM, you'll need to force encoding via the overloades method.

#### Example

```
'#CONSOLE ON
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

DIM pReader AS CXmlReader
DIM hr AS HRESULT

' // Fake loop to avoid multiple IF/END IF nesting
DO
   
   ' // Open read-only input stream
   DIM pFileStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("books.xml", STGM_READ, FILE_ATTRIBUTE_NORMAL, FALSE, NULL, @pFileStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the DtdProcessing_Prohibit property
   hr = pReader.SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)

   ' // Set the input source of the XML document to be parsed
   hr = pReader.SetInput(cast(IUnknown PTR, pFileStream))
   IF FAILED(hr) THEN
      PRINT "IXmlReader.SetInput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Parse the xml file
   DIM nodeType AS XmlNodeType
   DO
      hr = pReader.Read(@nodeType)
      IF hr <> S_OK THEN EXIT DO
      SELECT CASE nodeType
         CASE XmlNodeType_XmlDeclaration
            PRINT "XmlDeclaration"
         CASE XmlNodeType_Element
            IF pReader.IsEmptyElement THEN
               PRINT "Empty"
            ELSE
               PRINT "Element: ", pReader.GetLocalName
            END IF
         CASE XmlNodeType_EndElement
            IF pReader.IsEmptyElement THEN
               PRINT "Empty"
            ELSE
               PRINT "End element: ", pReader.GetLocalName
            END IF
         CASE XmlNodeType_Text
            PRINT "Value: ", pReader.GetValue
      END SELECT
   LOOP

   ' // Unconditional exit
   EXIT DO
LOOP

PRINT
PRINT "Press any key"
SLEEP
```

#### Example

```
'#CONSOLE ON
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

DIM pReader AS CXmlReader
DIM hr AS HRESULT

' // Fake loop to avoid multiple IF/END IF nesting
DO
   
   ' // Open read-only input stream
   DIM pFileStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("stocks.xml", STGM_READ, FILE_ATTRIBUTE_NORMAL, FALSE, NULL, @pFileStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the DtdProcessing_Prohibit property
   hr = pReader.SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)

   ' // Set the input source of the XML document to be parsed
   ' // Code pages:
   ' // UTF-8 (65001) -> Universal option, recommended for almost all projects.
   ' // UTF-16 (1200/1201) -> When working with Windows APIs or requiring internal compatibility.
   ' // ISO-8859-1 / Windows-1252 -> Only for compatibility with older European systems.
   ' // Asian code pages -> Only if required by the target system.
'   hr = pReader.SetInput(cast(IUnknown PTR, pFileStream), 65001)
   hr = pReader.SetInput(cast(IUnknown PTR, pFileStream), "utf-8")
   IF FAILED(hr) THEN
      PRINT "IXmlReader.SetInput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Parse the xml file
   DIM nodeType AS XmlNodeType
   DO
      hr = pReader.Read(@nodeType)
      IF hr <> S_OK THEN EXIT DO
      SELECT CASE nodeType
         CASE XmlNodeType_XmlDeclaration
            PRINT "XmlDeclaration"
         CASE XmlNodeType_Element
            IF pReader.IsEmptyElement THEN
               PRINT "Empty"
            ELSE
               PRINT "Element: ", pReader.GetLocalName
            END IF
         CASE XmlNodeType_EndElement
            IF pReader.IsEmptyElement THEN
               PRINT "Empty"
            ELSE
               PRINT "End element: ", pReader.GetLocalName
            END IF
         CASE XmlNodeType_Text
            PRINT "Value: ", pReader.GetValue
      END SELECT
   LOOP

   ' // Unconditional exit
   EXIT DO
LOOP

PRINT
PRINT "Press any key"
SLEEP
```
---

## <a name="setpropertyreader"></a>SetProperty (CXmlReader)

Sets the specified property.
```
FUNCTION SetProperty (BYVAL nProperty AS UINT, BYVAL pValue AS LONG_PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *nProperty* | The enumeration that identifies the property to be retrieved. For more information, see **IXmlReader Properties**. |
| *pValue* | The property value. |

#### GeLastResult

Returns **S_OK** if no error is generated. If an invalid property name is passed, returns **E_NOTIMPL**.

#### Remarks

A program should only set properties before parsing starts—that is, before the first call to **Read**.

The following code sets the `XmlReaderProperty_DtdProcessing` property to prohibit DTDs.
```
hr = pReader->SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)
IF FAILED(hr) THEN
    PRINT "Error setting XmlReaderProperty_DtdProcessing, error is ", hr)
END IF
```
---

## <a name="flushwriter"></a>Flush (CXmlWriter / CXmlWriterLite)

Flushes whatever is in the buffer to the underlying stream and then flushes the underlying stream.
```
FUNCTION Flush () AS HRESULT
```
#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

If the flush operation fails, this typically indicates an error in the underlying stream. In this case, the writer may not be in a recoverable state.

If the output stream for the writer is an **IStream** interface, this method will also flush the underlying stream by calling the **IStream.Commit** Method of the output stream.

---

## <a name="getpropertywriter"></a>GetProperty (CXmlWriter / CXmlWriterLite)

Returns the specified property. A program can get properties at any time.
```
FUNCTION GetProperty (BYVAL nProperty AS UINT) AS LONG_PTR
```
| Parameter | Description |
| --------- | ----------- |
| *nProperty* | The enumeration that identifies the property to be retrieved. For more information, see **IXmlReader Properties**. |

#### GetLastResult

Returns **S_OK** if no error is generated. If an invalid property name is passed, returns **E_NOTIMPL**.

#### Remarks

Although, most of the values returned are native or simple types, a few are COM objects. For example, the **XmlReaderProperty_MultiLanguage** property references a COM **IMultiLanguage2** instance. In these cases, the pointer returned by a successful call to the **GetProperty** method should be released through a call to the standard COM **IUnknown.Release** function.

---

## SetOutput

Sets the output stream for the writer.
```
FUNCTION SetOutput (BYVAL pOutputStream AS IUnknown PTR) AS HRESULT
FUNCTION SetOutput (BYVAL pOutputStream AS IUnknown PTR, BYVAL nEncodingPage AS UINT) AS HRESULT
FUNCTION SetOutput (BYVAL pOutputStream AS IUnknown PTR, BYVAL pwszEncodingName AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pOutput* | The output stream for the writer. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

`IXmlWriter` can accept several types of output stream:

A class derived from **ISequentialStream**

The writer will write the output to the provided ISequentialStream using the default UTF-8 encoding.

A class derived from **IStream**

The writer will write the output to the provided IStream using the default UTF-8 encoding.

The output source can be one of the following types:

A class derived from `IStream` or `ISequentialStream`. The reader will use defaults for all the additional properties of the input.

A code page:

* UTF-8 (65001) -> Universal option, recommended for almost all projects.
* UTF-16 (1200/1201) -> When working with Windows APIs or requiring internal compatibility.
* ISO-8859-1 / Windows-1252 -> Only for compatibility with older European systems.
* Asian code pages -> Only if required by the target system.

An encoding string:

* "utf-8" -> Universal option, recommended for almost all projects.
* "utf-16" -> When working with Windows APIs or requiring internal compatibility.
* "ISO-8859-1" -> For compatibility with older European systems.
* "windows-1252"  > For compatibility with older European systems.

**NULL**

This resets the writer, releasing the previously set output object. This forces the writer to flush all the data into the stream, but does not force the stream itself to flush.

Use the **Flush** method to force the writer to write out all the buffered data to the output stream.

#### Subtle points

If you pass "utf-8" as a name, **XmlLite** will honor the XML declaration and BOM if present.

If you pass a code page, **XmlLite** uses that as a hard hint, even if the XML declaration disagrees. That's useful for legacy files but can override the document's self-declared encoding.

BOM presence is critical for utf-16 detection. Without BOM, you'll need to force encoding via the overloades method.

#### Example

```
'#CONSOLE ON
#define UNICODE
#define _WIN32_WINNT &h0602
'#define _CXMLLITE_DEBUG_ 1
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

SCOPE

DIM pWriter AS CXmlWriter
DIM hr AS HRESULT

' // Fake loop to avoid multiple IF/END IF nesting
DO
   
   ' // Create an output stream
   DIM pFileOutputStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("output.xml", STGM_READ OR STGM_WRITE, FILE_ATTRIBUTE_NORMAL, FALSE, NULL, @pFileOutputStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the output source
   hr = pWriter.SetOutput(cast(IUnknown PTR, pFileOutputStream))
   IF FAILED(hr) THEN
      PRINT "IXmlWriter.SetOutput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Write the XML document
   pWriter.WriteStartDocument(XmlStandalone_Yes)
   pWriter.WriteStartElement(NULL, "bookstore", NULL)

   pWriter.WriteStartElement(NULL, "book", NULL)
   pWriter.WriteAttributeString(NULL, "category", NULL, "children")
      pWriter.WriteElementString(NULL, "title", NULL, "Harry Potter")
      pWriter.WriteElementString(NULL, "author", NULL, "J K. Rowling")
      pWriter.WriteElementString(NULL, "year", NULL, "2005")
      pWriter.WriteElementString(NULL, "price", NULL, "29.99")
   pWriter.WriteEndElement ' book

   pWriter.WriteEndElement ' bookstore
   pWriter.WriteEndDocument

   PRINT "XML file written successfully."
   PRINT "Press any key"
   SLEEP

   ' // Unconditional exit
   EXIT DO
LOOP

END SCOPE

SCOPE

DIM pReader AS CXmlReader
DIM hr AS HRESULT

DO
   ' // Open read-only input stream
   DIM pFileInputStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("output.xml", STGM_READ, FILE_ATTRIBUTE_NORMAL, FALSE, NULL, @pFileInputStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the DtdProcessing_Prohibit property
   hr = pReader.SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)

   ' // Set the input source of the XML document to be parsed
   hr = pReader.SetInput(cast(IUnknown PTR, pFileInputStream))
   IF FAILED(hr) THEN
      PRINT "IXmlReader.SetInput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Parse the xml file
   DIM nodeType AS XmlNodeType
   DO
      hr = pReader.Read(@nodeType)
      IF hr <> S_OK THEN EXIT DO
      SELECT CASE nodeType
      CASE XmlNodeType_Element
         PRINT "Element: "; pReader.GetLocalName
         ' // If the element has attributes, iterate through them
         IF pReader.MoveToFirstAttribute = S_OK THEN
            DO
               PRINT "  Attribute: "; pReader.GetLocalName; " = "; pReader.GetValue
            LOOP WHILE pReader.MoveToNextAttribute = S_OK
            pReader.MoveToElement ' return to the element
         END IF
      CASE XmlNodeType_Text
         PRINT "Value: "; pReader.GetValue
      CASE XmlNodeType_EndElement
         PRINT "End element: "; pReader.GetLocalName
      END SELECT

   LOOP

   ' // Unconditional exit
   EXIT DO
LOOP

END SCOPE

PRINT
PRINT "Press any key"
SLEEP
```

#### Example

```
'#CONSOLE ON
#define UNICODE
#define _WIN32_WINNT &h0602
'#define _CXMLLITE_DEBUG_ 1
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

' =========================
' Writer: Creates several books
' =========================
SCOPE

' // Fake loop to avoid multiple IF/END IF nesting
DO

   DIM pWriter AS CXmlWriter
   DIM hr AS HRESULT

   ' // Create an output stream
   DIM pFileOutputStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("books2.xml", STGM_CREATE OR STGM_WRITE, FILE_ATTRIBUTE_NORMAL, TRUE, NULL, @pFileOutputStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the output source
   hr = pWriter.SetOutput(cast(IUnknown PTR, pFileOutputStream))
   IF FAILED(hr) THEN
      PRINT "SetOutput error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Write the XML document
   pWriter.WriteStartDocument(XmlStandalone_Yes)
   pWriter.WriteStartElement(NULL, "bookstore", NULL)

      ' // First book
      pWriter.WriteStartElement(NULL, "book", NULL)
      pWriter.WriteAttributeString(NULL, "category", NULL, "children")
         pWriter.WriteElementString(NULL, "title", NULL, "Harry Potter")
         pWriter.WriteElementString(NULL, "author", NULL, "J K. Rowling")
         pWriter.WriteElementString(NULL, "year", NULL, "2005")
         pWriter.WriteElementString(NULL, "price", NULL, "29.99")
      pWriter.WriteEndElement ' book

      ' // Second book
      pWriter.WriteStartElement(NULL, "book", NULL)
      pWriter.WriteAttributeString(NULL, "category", NULL, "fiction")
         pWriter.WriteElementString(NULL, "title", NULL, "The Hobbit")
         pWriter.WriteElementString(NULL, "author", NULL, "J R. R. Tolkien")
         pWriter.WriteElementString(NULL, "year", NULL, "1937")
         pWriter.WriteElementString(NULL, "price", NULL, "19.99")
      pWriter.WriteEndElement ' book

   pWriter.WriteEndElement ' bookstore
   pWriter.WriteEndDocument

   PRINT "XML file written successfully."
   PRINT "Press any key"
   SLEEP

   ' // Unconditional exit
   EXIT DO
LOOP

END SCOPE

' ==========================
' Reader: read several books
' ==========================
SCOPE

DO
   
   DIM pReader AS CXmlReader
   DIM hr AS HRESULT

   ' // Open read-only input stream
   DIM pFileInputStream AS IStream PTR
   hr = SHCreateStreamOnFileEx("books2.xml", STGM_READ, FILE_ATTRIBUTE_NORMAL, FALSE, NULL, @pFileInputStream)
   IF FAILED(hr) THEN
      PRINT "SHCreateStreamOnFile error &h" & HEX(hr)
      EXIT DO
   END IF

   ' // Set the DtdProcessing_Prohibit property
   hr = pReader.SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)
   hr = pReader.SetInput(cast(IUnknown PTR, pFileInputStream))

   DIM nodeType AS XmlNodeType
   DO
      hr = pReader.Read(@nodeType)
      IF hr <> S_OK THEN EXIT DO

      SELECT CASE nodeType
         CASE XmlNodeType_Element
            PRINT "Element: "; pReader.GetLocalName

            ' // If there are attributes, display them
            IF pReader.MoveToFirstAttribute() = S_OK THEN
               DO
                  PRINT "  Attribute: "; pReader.GetLocalName; " = "; pReader.GetValue
               LOOP WHILE pReader.MoveToNextAttribute() = S_OK
               pReader.MoveToElement()
            END IF

         CASE XmlNodeType_Text
            PRINT "Value: "; pReader.GetValue

         CASE XmlNodeType_EndElement
            PRINT "End element: "; pReader.GetLocalName
      END SELECT
   LOOP

   ' // Unconditional exit
   EXIT DO
LOOP

END SCOPE

PRINT
PRINT "Press any key"
SLEEP
```
---

## <a name="setpropertywriter"></a>SetProperty (CXmlWriter / CXmlWriterLite)

Sets the specified property.
```
FUNCTION SetProperty (BYVAL nProperty AS UINT, BYVAL pValue AS LONG_PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *nProperty* | The enumeration that identifies the property to be retrieved. For more information, see **IXmlWriter Properties**. |
| *pValue* | The property value. |

#### Return value

Returns **S_OK** if no error is generated. If an invalid property name is passed, returns **E_NOTIMPL**.

#### Remarks

After writing starts, it is not recommended that you call this method.

The following code sets the `XmlReaderProperty_DtdProcessing` property to prohibit DTDs.
```
hr = pWriter->SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit)
IF FAILED(hr) THEN
    PRINT "Error setting XmlReaderProperty_DtdProcessing, error is ", hr)
END IF
```
---

## <a name="writeattributes"></a>WriteAttributes

Copies attributes from the specified source `IXmlReader` to the IXmlWriter`.
```
FUNCTION WriteAttributes (BYVAL pReader AS Afx_IXmlReader PTR, BYVAL fWriteDefaultAttributes AS BOOLEAN) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pReader* | The reader to copy the attributes from. This argument cannot be NULL. |
| *fWriteDefaultAttributes* | Specifies whether to also copy the default attributes from the reader. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

The attributes copied depend on the current position of the reader:

If the reader is positioned on an element node, this method copies all of the attributes contained by the element.

If the reader is positioned on an attribute node, this method copies the current attribute and the rest of the attributes contained by the element.

If the reader is positioned on an *XmlNodeType_XmlDeclaration*, this method writes out all the attributes of the declaration.

If the reader is positioned on any other node type, calling this method has no effect.

#### Usage example

```
pWriter->WriteAttributes(pReader, FALSE)
```
---

## <a name="writeattributestring"></a>WriteAttributeString (CXmlWriter)

Writes an attribute.
```
FUNCTION WriteAttributeString (BYVAL pwszPrefix AS LPCWSTR, BYVAL pwszLocalName AS LPCWSTR, _
   BYVAL pwszNamespaceUri AS LPCWSTR, BYVAL pwszValue AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszPrefix* | The namespace prefix for the attribute. NULL is equivalent to an empty string. |
| *pwszLocalName* | The local name of the attribute. NULL is a valid value only if *pwszPrefix* has a value of `xmlns`. |
| *pwszNamespaceUri* | The namespace URI for the attribute. NULL is equivalent to an empty string. |
| *pwszValue* | The value of the attribute. NULL is equivalent to an empty string. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

When the attribute name is `xmlns`, this method also treats the attribute as a namespace declaration and associates the declared prefix with the specified namespace. In this case, if a namespace has already been specified for this element, that namespace is overridden and any child elements written with the original namespace are automatically written out as part of the new namespace.

If NULL is supplied for *pwszLocalName* and the value of *pwszPrefix* is not `xmlns`, this method returns an error.

---

## <a name="writeattributestringlite"></a>WriteAttributeString (CXmlWriterLite)

Writes an attribute.
```
FUNCTION WriteAttributeString (BYVAL pwszQName AS WSTRING PTR, _
   BYVAL pwszValue AS Const WSTRING PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszQName* | The qualified name for the attribute. NULL causes an error. |
| *pwszValue* | The value of the attribute. NULL is equivalent to an empty string. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

Creates an attribute in the current element by using *pwszQName* as the qualified name for the attribute and *pwszValue* as the attribute value. **WriteAttributeString** performs no validation that the attribute name or value is allowed in the current element. When the attribute name is xmlns or xmlns:prefix, this method creates the attribute as a namespace declaration. This associates the default namespace or, if present, the declared prefix with the namespace URI specified in *pwszValue*. Because **IXmlWriterLite** performs no namespace validation, you must be careful not to create duplicate or conflicting namespace declarations.

---

## WriteCData

Writes out a CDATA section that contains the specified text.
```
FUNCTION WriteCData (BYVAL pwszText AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszText* | The content of the CDATA section. NULL is equivalent to an empty string. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

This method produces a CDATA section in the following format, where text is the provided text:
```
<![CDATA[text]]>  
```

When the pwszText parameter is NULL, this method produces a CDATA section that contains no content, like this:

```
<![CDATA[]]>  
```
If the text block provided contains the characters `"]]>"`, which denote the end of a CDATA section, the writer creates a second CDATA section that contains the content after the second `"]"` character. This prevents the CDATA section from being truncated.

This method does not combine adjacent CDATA sections, even if there have been no other method calls between calls to the **WriteCData** method.

---

## WriteCharEntity

Writes a character entity for the provided Unicode character value. This method writes the character entity in hexadecimal format.
```
FUNCTION WriteCharEntity (BYVAL wch AS WCHAR PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *wch* | The charater to write. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

This method does not accept surrogate pairs. To write a surrogate pair, see **WriteSurrogateCharEntity**.

---

## WriteChars

Writes out the specified text content, escaping markup.
```
FUNCTION WriteChars (BYVAL pwch AS WSTRING PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwch* | The characters to write. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

If characters is NULL, this method writes out the text with no data content. That is, the value written is "".

Surrogate pair characters cannot be split across multiple buffer writes when the **WriteChars** method is called. Therefore, surrogate pairs require special handling. The XML specification defines the valid ranges for surrogate pairs.

---

## WriteComment

Writes out a comment that contains the specified text.
```
FUNCTION WriteComment (BYVAL pwszComment AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszComment* | The text of the comment. NULL is equivalent to an empty string. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

This method produces a comment in the following format, where text is the text provided:
```
<!-- text -->
```
If the text block provided contains the characters `"-->"`, which denote the end of a comment, this method will insert a space between the two `"-"` characters. This change to the text prevents the writer from producing an XML document that is not well-formed.

If the *pwszComment* parameter is NULL, the writer produces a comment that does not contain any text.

---

## WriteDocType

Writes out the <!DOCTYPE ...> declaration with the specified name and optional attributes.
```
FUNCTION WriteDocType (BYVAL pwszName AS LPCWSTR, BYVAL pwszPublicId AS LPCWSTR, _
   BYVAL pwszSystemId AS LPCWSTR, BYVAL pwszSubset AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszName* | The name of the DOCTYPE. This parameter cannot be empty or NULL. |
| *pwszPublicId* | If non-NULL, this method writes `PUBLIC "pubid" "sysid"` where pubid and sysid are replaced with the value of the specified arguments. NULL indicates that the public ID is to be omitted; this is not equivalent to an empty string. |
| *pwszSystemId* | If *pwszPublicId* is NULL and *pwszSystemId* is non-NULL, the method writes `SYSTEM "sysid"` where sysid is replaced with the value of this argument. NULL indicates that the system ID is to be omitted; this is not equivalent to an empty string. |
| *pwszSubset* | If non-NULL, the method writes `[subset]` where subset is replaced with the value of this argument. If this parameter is NULL, no subset is written out. If no subset is written, the square brackets are not written either. NULL is not equivalent to an empty string; an empty string argument will cause the brackets to be written. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

The **WriteDocType** method does not check for invalid characters in *pwszSystemId* and *pwszPublicId* values. It also does not check for valid Document Type Definition (DTD)/XML syntax.

```
DIM subset AS WSTRING * 260 = _
L"<!ELEMENT Employees (Employee)+>\n"  
L"<!ELEMENT Employee EMPTY>\n"  
L"<!ATTLIST Employee firstname CDATA #REQUIRED>\n"  
L"<!ENTITY Company 'Microsoft'>\n";
```
Results in the following XML:
```
<!DOCTYPE Employees [<!ELEMENT Employees (Employee)+>  
<!ELEMENT Employee EMPTY>  
<!ATTLIST Employee firstname CDATA #REQUIRED>  
<!ENTITY Company 'Microsoft'>  
]>
```
---

## <a name="writeelementstring"></a>WriteElementString (CXmlWriter)

Writes out an element with the specified prefix, name, namespace, and value.

```
FUNCTION WriteElementString (BYVAL pwszPrefix AS LPCWSTR, BYVAL pwszLocalName AS LPCWSTR, _
   BYVAL pwszNamespaceUri AS LPCWSTR, BYVAL pwszValue AS LPCWSTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszPrefix* | The namespace prefix of the element. NULL is equivalent to an empty string. |
| *pwszLocalName* | The local name of the element. NULL will result in an error. |
| *pwszNamespaceUri* | The namespace URI of the element. NULL is equivalent to an empty string. |
| *pwszValue* | The value of the element. NULL indicates that there is no content to write. In contrast, an empty string indicates that this element has an empty value. |

#### Return value

Returns **S_OK** if no error is generated.

#### Usage example
```
pWriter->WriteElementString(NULL, "myElement", NULL, "myValue")
```
---

## <a name="writeelementstringlite"></a>WriteElementString (CXmlWriterLite)

Writes out an element by using the specified prefix, name, namespace, and value.

```
FUNCTION WriteElementString (BYVAL pwszQName AS WSTRING PTR, BYVAL pwszValue AS LPCWSTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszQName* | The qualified name of the element. NULL causes an error. |
| *pwszValue* | The value of the element. NULL indicates that there is no content to write. In contrast, an empty string indicates that this element has an empty value. |

#### Return value

Returns **S_OK** if no error is generated.

#### Usage example
```
pWriter->WriteElementString("myElement", "myValue")
```
---

## WriteEndDocument

Closes any open elements or attributes, then closes the current document. To reinitialize the writer so that a new document can be written, you must call **SetOutput**.

```
FUNCTION WriteEndDocument () AS HRESULT
```
#### Return value

Returns **S_OK** if no error is generated.

---

## <a name="writeendelement"></a>WriteEndElement (CXmlWriter)

Closes one element. If the element contains no content, this method writes a short end tag `("/>")`. Otherwise, this method writes the full end tag.

```
FUNCTION WriteEndElement () AS HRESULT
```
#### Return value

Returns **S_OK** if no error is generated.

---

## <a name="writeendelementlite"></a>WriteEndElement (CXmlWriterLite)

Closes one element. If the element contains no content, this method writes a short end tag `("/>")`. Otherwise, this method writes the full end tag.

```
FUNCTION WriteEndElement (BYVAL pwszQName AS WSTRING PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszQName* | The qualified name of the element to close. NULL causes an error. |

#### Return value

Returns **S_OK** if no error is generated.

---

## WriteEntityRef

Writes out an entity reference with the specified name.

```
FUNCTION WriteEntityRef (BYVAL pwszName AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszName* | The name of the entity reference. NULL is not valid. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

This method produces an entity reference in the following format, where name is the name provided:
```
&name;
```
This method returns an error if NULL is supplied for the name.

#### Usage example
```
pWriter->WriteEntityRef("myEntity")
```
---

## <a name="writefullendelement"></a>WriteFullEndElement (CXmlWriter)

Closes one element and pops the corresponding namespace scope. This method always writes the full end tag.
```
FUNCTION WriteFullEndElement () AS HRESULT
```
#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

Use this method in cases where it is important to guarantee a full end tag. For example, you might use this method if you are writing an HTML `<script>` element. In HTML, a script block must be always be closed with the full end tag `</script>` for browsers to properly interpret the block.

---

## <a name="writefullendelementlite"></a>WriteFullEndElement (CXmlWriterLite)

Closes the named element. This method always writes the full end tag.
```
FUNCTION WriteFullEndElement (BYVAL pwszQName AS CONST WSTRING PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszName* | The qualified name of the element to close. NULL causes an error. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

Use this method when you must guarantee a full end tag. For example, you might use this method if you are writing an HTML `<script>` element. In HTML, a script block must always be closed with the full end tag `</script>` for browsers to correctly interpret the block.

---

## WriteName

Writes out the specified name, ensuring that the name is valid according to the XML specification.
```
FUNCTION WriteName (BYVAL pwszName AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszName* | The name to write.. NULL is invalid. |

#### Return value

Returns **S_OK** if no error is generated. Returns an error if pwszName is NULL or the name is not valid. An example of an invalid name is one that starts with a colon `(":")`.

#### Remarks

WriteName ensures that the name is valid according to the Namespaces in XML specification.

#### Usage example
```
pWriter->WriteName("myName")
```
---

## WriteNmToken

Writes out the specified name, ensuring that the name is a valid `NmToken` according to the XML specification.
```
FUNCTION WriteNmToken (BYVAL pwszNmToken AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszName* | The name to write.. NULL is invalid. |

#### Return value

Returns **S_OK** if no error is generated. Returns an error if pwszNmToken is NULL or the name is not a valid `NmToken`.

#### Remarks

If NULL is supplied for the name, an error is returned.

#### Usage example
```
 pWriter->WriteNmToken("myNmToken")
```
---

## WriteNode

Copies the current node from the specified source **IXmlReader** to the **IXmlWriter**. This method moves the **IXmlReader** source to the start of the next sibling node, reading all of the child nodes of the current node. If the reader is in the initial state, this method copies all of the nodes in the reader.

```
FUNCTION WriteNode (BYVAL pReader AS Afx_IXmlReader PTR, BYVAL fWriteDefaultAttributes AS BOOLEAN) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pReader* | The reader to read from. |
| *fWriteDefaultAttributes* | Specifies whether to also copy the default attributes from the specified **IXmlReader**. |

#### Return value

Returns **S_FALSE** if no error is generated.

#### Remarks

When the **IXmlReader** is already at the end of the input, or has been closed, the reader contains no nodes to be written. In this case, this method does not write any nodes to the writer.

When the **IXmlReader** has an **IXmlResolver** specified, Entity Reference nodes may have been resolved with that resolver. For the **IXmlReader**, the resolved entity is a child node of the Entity Reference node.

Notice that attribute nodes have no siblings, but are instead considered as metadata contained by element nodes. Therefore, attribute nodes cannot be copied individually.

The specified **IXmlReader** can supply default attributes from a Document Type Definition (DTD). When the *fWriteDefaultAttributes* property is set to TRUE, all default values from the supplied data source are written to the output. When the *fWriteDefaultAttributes* property is set to FALSE, no default values from the supplied data source are written to the output.

The following table shows the actions this method takes, depending on the **XmlNodeType** of the current node.

| XmlNodeType | Description |
| ----------- | ----------- |
| None | This occurs when the reader is in the XmlReaderState_Initial state. If there is no XmlNodeType, the writer writes out all the nodes regardless of type. That is, the writer consumes the IXmlReader and writes out all the nodes read, including attributes, processing instructions, comments, and so on. |
| Element | The writer writes out the element node and all child nodes of the element. It also writes out all attributes of all nodes that are written out. |
| Attribute | This node type is not directly supported when writing. Attributes are written out when their parent element is written. To write individual attributes, use the WriteAttributes method or the or WriteAttributeString method. This node type is primarily used when reading and parsing documents. |
| Text | The writer writes out the text node. |
| CDATA | The writer writes out the CDATA section node. |
| EntityReference | The writer writes the Entity Reference node. |
| ProcessingInstruction | The writer writes the PI node. |
| Comment | The writer writes the Comment node. |
| DocumentType | The writer writes the DocType node. |
| Whitespace | The writer writes the Whitespace node. |
| SignificantWhitespace | The writer writes the Significant Whitespace node. |
| EndElement | No operation. |
| EndEntity | This node type is not supported when writing. Entities are automatically ending when writing them. |
| XmlDeclaration | Writes out the XmlDeclaration node.. |

#### Note

If the specified **IXmlReader** returns white space and the **XmlWriterProperty_Indent** property is set to TRUE, both the reader and the writer can indent nodes.

---

## WriteNodeShallow

Copies the current node from the specified source **IXmlReader** to the **IXmlWriter**, without writing the children of the current node.

```
FUNCTION WriteNodeShallow (BYVAL pReader AS Afx_IXmlReader PTR, BYVAL fWriteDefaultAttributes AS BOOLEAN) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pReader* | The reader to read from. |
| *fWriteDefaultAttributes* | Specifies whether to also copy the default attributes or elements from the supplied **IXmlReader**. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

This method copies the current node from the specified **IXmlReader** to the **IXmlWriter**, without writing the children of the current node. This method is similar to **WriteNode**, except that it will only write the current node. It will not close the node, and will not move the reader forward.

---

## WriteProcessingInstruction

Writes a processing instruction.

```
FUNCTION WriteProcessingInstruction (BYVAL pwszName AS LPCWSTR, BYVAL pwszText AS LPCWSTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszName* | The name of the processing instruction. This parameter cannot be NULL. |
| *pwszText* | The text content of the processing instruction. NULL is equivalent to an empty string. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

The writer creates a processing instruction by writing the provided name and text with a space after the name.

If the pwszText parameter is NULL, this method returns **S_OK** and writes a processing instruction with no text content.

If the text block provided contains the characters `"?>"`, which denote the end of a processing instruction, the writer inserts a space after the `"?"` character. This change to the text prevents the writer from producing an XML document that is not well-formed.

#### Usage example
```
pWriter->WriteProcessingInstruction("xml-stylesheet", "href=\"mystyle.css\" title=\"Compact\" type=\"text/css\"")
```
---

## WriteQualifiedName

Writes out the specified namespace-qualified name by looking up the prefix that is in scope for the specified namespace.

```
FUNCTION WriteQualifiedName (BYVAL pwszLocalName AS LPCWSTR PTR, BYVAL pwszNamespaceUri AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszLocalName* | The local name to write. NULL is not valid. |
| *pwszNamespaceUri* | The namespace URI of the name to write. NULL is equivalent to the empty string. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

This method outputs the qualified name given the specified namespace and local name. If the provided namespace is not in scope, then this method returns an error. If the provided namespace is in scope and the namespace has a namespace prefix, then this method writes the qualified name with the prefix. If the namespace provided is the current default namespace, the name does not need a prefix and this method does not produce one.

The **WriteQualifiedName** method returns an error if pwszLocalName is NULL or the name is not valid according to the Namespaces in XML specification. An example of this is if the name starts with a colon (":").

---

## WriteRaw

Enables the caller to write out raw markup manually. You can avoid creating entities for special characters by using this method.

```
FUNCTION WriteRaw (BYVAL pwszData AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszData* | The data to write. Writes nothing if NULL. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

If *pwszData* is NULL, nothing is written. In contrast, if this parameter is an empty string, an empty text entry is written. That is, the value written is "".

#### Usage example
```
pWriter->WriteRaw("<elementWrittenRaw/>")
```
---

## WriteRawChars

Writes out raw markup manually. Using this method allows an application to avoid creating entities for special characters.

```
FUNCTION WriteRawChars (BYVAL pwch AS CONST WSTRING PTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwch* | Pointer to the characters to write. NULL is valid only if count is zero. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

Writes nothing if the count parameter is 0 or if the characters parameter is NULL.

#### Usage example
```
pWriter->WriteRawChars("<rawCharacters/>")
```
---

## WriteStartDocument

Writes out the XML declaration with the version "1.0". The encoding attribute is determined by the implementation of **IXmlWriterOutput**. By default, the encoding is UTF-8.

```
FUNCTION WriteStartDocument (BYVAL standalone AS XmlStandalone) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *standalone* | If *XmlStandalone_Omit* does not write a standalone attribute in the XML declaration, one of the following occurs: If *XmlStandalone_No*, the writer writes standalone="no". If *XmlStandalone_Yes*, the writer writes standalone="yes". |

#### Return value

Returns **S_OK** if no error is generated.

#### Usage example

```
pWriter->WriteStartDocument(XmlStandalone_Omit)
```
---

## <a name="writestartelement"></a>WriteStartElement (CXmlWriter)

Writes out the specified start tag and associates it with the specified namespace.
```
FUNCTION WriteStartElement (BYVAL pwszPrefix AS LPCWSTR, BYVAL pwszLocalName AS LPCWSTR, _
   BYVAL pwszNamespaceUri AS LPCWSTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszPrefix* | The namespace prefix of the element. A NULL value is equivalent to an empty string. |
| *pwszLocalName* | The local name of the element. A NULL value is not valid. |
| *pwszNamespaceUri* | The namespace URI of the element. NULL is equivalent to an empty string. |

#### Return value

Returns S_OK if no error is generated.

#### Remarks

After calling this method, an application can either write attributes or write content. To write content, use **WriteComment**, **WriteString**, or **WriteStartElement**.

A program must call **WriteEndElement** to close the element. The **WriteEndElement** method might write a full end tag, or it might close the element using the short form. The **WriteFullEndElement** method always writes a full end tag.

#### Usahe example

```
pWriter->WriteStartElement(NULL, "containsEntity", NULL)
```
---

## <a name="writestartelementlite"></a>WriteStartElement (CXmlWriterLite)

Writes out the specified start tag.
```
WriteStartElement (BYVAL pwszQName AS CONST WSTRING PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszQName* | The qualified name of the element to open. NULL causes an error. |

#### Return value

Returns S_OK if no error is generated.

#### Remarks

After calling this method, an application can either write attributes or write content. To write content, use **WriteComment**, **WriteString**, or **WriteStartElement**.

A program must call **WriteEndElement** or **WriteFullEndElement** to close the element. The **WriteEndElement** method might write a full end tag, or it might close the element by using the short form. The **WriteFullEndElement** method always writes a full end tag.

#### Usage example

```
pWriter->WriteEndElement("containsEntity")
```
---

## WriteString

Writes out the specified text content, escaping any markup in the content.
```
FUNCTION WriteString (BYVAL pwszText AS LPCWSTR) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *pwszText* | The text to write. NULL is valid and indicates that no operation is to be performed. |

#### Return value

Returns **S_OK** if no error is generated.

#### Remarks

If the value is NULL, this method returns **S_OK** but does not write any content. In contrast, if *pwzText* is an empty string, the value written is "".

Surrogate pair characters cannot be split across multiple buffers when this method is called. Therefore, surrogate pairs require special handling. The XML specification defines the valid ranges for surrogate pairs. To write a surrogate pair, see **WriteSurrogateCharEntity**.

#### Usage example
```
pWriter->WriteString("Markup is <escaped> for this string")
```
---

## WriteSurrogateCharEntity

Forces the generation of a surrogate character entity for the specified string value.

```
FUNCTION WriteSurrogateCharEntity (BYVAL wchLow AS WCHAR, BYVAL wchHigh AS WCHAR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *wchLow* | Low-surrogate for the pair. The code value must be in the range U+DC00 - U+DFFF. |
| *wchHigh* | High-surrogate for the pair. The code value must be in the range U+D800 - U+DBFF. |

#### Return value

Returns S_OK if no error is generated.

#### Remarks

A surrogate pair is defined as character code consisting of a sequence of two Unicode values, where the first value is a high-surrogate and the second value is a low-surrogate. The *lowChar* and *highChar* parameters must be a valid surrogate character pair, otherwise an error is returned and the writer does not produce output. The writer writes surrogate pairs in hexadecimal format.

#### Usage example
```
WriteSurrogateCharEntity(&hD800, &hDC00)
```
---

## WriteWhitespace

Writes out the specified white space.

```
FUNCTION WriteWhitespace (BYVAL pwszWhitespace AS LPCWSTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pwszWhitespace* | The white space to write. NULL is valid and indicates that no operation is to be performed. |

#### Return value

Returns S_OK if no error is generated.

#### Remarks

Use this method to manually format an XML document.

When the whitespace parameter is NULL, this method returns **S_OK** without writing any content. In contrast, if the parameter is an empty string, the value written is "".

#### Usage example

```
pWriter->WriteWhitespace("\n")
```
---
