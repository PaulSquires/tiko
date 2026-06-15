#cmdline "-s console"
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
