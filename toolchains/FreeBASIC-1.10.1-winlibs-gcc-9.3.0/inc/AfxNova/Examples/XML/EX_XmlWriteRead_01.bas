#cmdline "-s console"
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
