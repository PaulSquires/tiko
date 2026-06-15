#cmdline "-s console"
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/CXmlLite.inc"
USING AfxNova

' Helper to create a writable stream
FUNCTION CreateWriteStream(BYREF fileName AS STRING) AS IStream PTR
    DIM pStream AS IStream PTR
    DIM hr AS HRESULT = SHCreateStreamOnFileEx(fileName, STGM_CREATE OR STGM_WRITE, FILE_ATTRIBUTE_NORMAL, TRUE, NULL, @pStream)
    IF FAILED(hr) THEN
        PRINT "Error creating stream for " & fileName & " hr=&h" & HEX(hr)
        RETURN NULL
    END IF
    RETURN pStream
END FUNCTION

SUB WriteXml(BYREF fileName AS STRING, BYREF strencoding AS STRING, BYREF text AS STRING)
    DIM pStream AS IStream PTR = CreateWriteStream(fileName)
    IF pStream = NULL THEN EXIT SUB

    DIM writer AS CXmlWriter
    DIM hr AS HRESULT

    ' Use encoding name overload
    hr = writer.SetOutput(CAST(IUnknown PTR, pStream), strencoding)
    IF FAILED(hr) THEN
        PRINT "SetOutput failed for " & fileName & " hr=&h" & HEX(hr)
        pStream->lpvtbl->Release(pStream)
        EXIT SUB
    END IF

    writer.SetProperty(XmlWriterProperty_Indent, TRUE)

    writer.WriteStartDocument(XmlStandalone_Omit)
    writer.WriteStartElement(NULL, "root", NULL)
    writer.WriteStartElement(NULL, "item", NULL)
    writer.WriteString(text)   ' STRING works fine here
    writer.WriteEndElement()   ' item
    writer.WriteEndElement()   ' root
    writer.WriteEndDocument()
    writer.Flush()

    pStream->lpvtbl->Release(pStream)
END SUB

' Main
WriteXml("utf8.xml", "utf-8", "Hola UTF-8 € ñ")
WriteXml("utf16.xml", "utf-16", "Hola UTF-16 € ñ")
WriteXml("iso8859.xml", "ISO-8859-1", "Hola ISO-8859-1 ñ")
WriteXml("win1252.xml", "windows-1252", "Hola Windows-1252 € ñ")

PRINT "XML files generated with CXmlWriter."
SLEEP
