#cmdline "-s console"
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

' Helper to create a writable stream
FUNCTION CreateWriteStream(byref fileName AS STRING) AS IStream PTR
    DIM pStream AS IStream PTR
    DIM hr AS HRESULT = SHCreateStreamOnFileEx(fileName, STGM_CREATE OR STGM_WRITE, FILE_ATTRIBUTE_NORMAL, TRUE, NULL, @pStream)
    IF FAILED(hr) THEN
        PRINT "Error creating stream for " & fileName & " hr=&h" & HEX(hr)
        RETURN NULL
    END IF
    RETURN pStream
END FUNCTION

' Write XML using code page overload
SUB WriteXmlWithCodePage(byref fileName AS STRING, byval codePage AS UINT, byref text AS STRING)
    DIM pStream AS IStream PTR = CreateWriteStream(fileName)
    IF pStream = NULL THEN EXIT SUB

    DIM writer AS CXmlWriter
    DIM hr AS HRESULT

    ' Use code page overload
    hr = writer.SetOutput(CAST(IUnknown PTR, pStream), codePage)
    IF FAILED(hr) THEN
        PRINT "SetOutput(codePage) failed for " & fileName & " hr=&h" & HEX(hr)
        pStream->lpvtbl->Release(pStream)
        EXIT SUB
    END IF

    writer.SetProperty(XmlWriterProperty_Indent, TRUE)

    writer.WriteStartDocument(XmlStandalone_Omit)
    writer.WriteStartElement(NULL, "root", NULL)
    writer.WriteStartElement(NULL, "item", NULL)
    writer.WriteString(text)
    writer.WriteEndElement()   ' item
    writer.WriteEndElement()   ' root
    writer.WriteEndDocument()
    writer.Flush()

    pStream->lpvtbl->Release(pStream)
END SUB

' Main: generate files with different code pages
WriteXmlWithCodePage("utf8_codepage.xml", 65001, "Hola UTF-8 € ñ")
WriteXmlWithCodePage("utf16le_codepage.xml", 1200, "Hola UTF-16 LE € ñ")
WriteXmlWithCodePage("utf16be_codepage.xml", 1201, "Hola UTF-16 BE € ñ")
WriteXmlWithCodePage("win1252_codepage.xml", 1252, "Hola Windows-1252 € ñ")

PRINT "XML files generated with CXmlWriter using code page overload."
SLEEP
