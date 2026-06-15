#pragma once
#include once "windows.bi"
#include once "win/ole2.bi"

'/* header files for imported files */
#include once "win/wtypes.bi"
#include once "win/propidl.bi"
#include once "win/ocidl.bi"
#include once "AfxNova/Afxd2d1.bi"

'#include <intsafe.h>
#define WINCODEC_SDK_VERSION1 &h0236
#define WINCODEC_SDK_VERSION2 &h0237

'#ifndef __Afx_IUnknown_INTERFACE_DEFINED__
'#define __Afx_IUnknown_INTERFACE_DEFINED__
'TYPE Afx_IUnknown AS Afx_IUnknown_
'TYPE Afx_IUnknown_ EXTENDS OBJECT
'	DECLARE ABSTRACT FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
'	DECLARE ABSTRACT FUNCTION AddRef () AS ULONG
'	DECLARE ABSTRACT FUNCTION Release () AS ULONG
'END TYPE
'TYPE AFX_LPUNKNOWN AS Afx_IUnknown PTR
'#endif

#ifndef __Afx_IStream_INTERFACE_DEFINED__
#define __Afx_IStream_INTERFACE_DEFINED__
'TYPE Afx_IStream AS Afx_IStream_
'TYPE Afx_IStream_ EXTENDS Afx_IUnknown
TYPE Afx_IStream EXTENDS Afx_IUnknown
	DECLARE ABSTRACT FUNCTION Read (BYVAL pv AS ANY PTR, BYVAL cb AS ULONG, BYVAL pcbRead AS ULONG PTR) AS HRESULT
	DECLARE ABSTRACT FUNCTION Write (BYVAL pv AS CONST ANY PTR, BYVAL cb AS ULONG, BYVAL pcbWritten AS ULONG PTR) AS HRESULT
	DECLARE ABSTRACT FUNCTION Seek (BYVAL dlibMove AS LARGE_INTEGER, BYVAL dwOrigin AS DWORD, BYVAL plibNewPosition AS ULARGE_INTEGER PTR) AS HRESULT
	DECLARE ABSTRACT FUNCTION SetSize (BYVAL libNewSize as ULARGE_INTEGER) AS HRESULT
	DECLARE ABSTRACT FUNCTION CopyTo (BYVAL pstm AS Afx_IStream ptr, BYVAL cb AS ULARGE_INTEGER, BYVAL pcbRead AS ULARGE_INTEGER PTR, BYVAL pcbWritten AS ULARGE_INTEGER PTR) AS HRESULT
	DECLARE ABSTRACT FUNCTION Commit (BYVAL grfCommitFlags AS DWORD) AS HRESULT
	DECLARE ABSTRACT FUNCTION Revert () AS HRESULT
	DECLARE ABSTRACT FUNCTION LockRegion (BYVAL libOffset AS ULARGE_INTEGER, BYVAL cb AS ULARGE_INTEGER, BYVAL dwLockType AS DWORD) AS HRESULT
	DECLARE ABSTRACT FUNCTION UnlockRegion (BYVAL libOffset as ULARGE_INTEGER, BYVAL cb AS ULARGE_INTEGER, BYVAL dwLockType AS DWORD) AS HRESULT
	DECLARE ABSTRACT FUNCTION Stat (BYVAL pstatstg AS STATSTG PTR, BYVAL grfStatFlag AS DWORD) AS HRESULT
	DECLARE ABSTRACT FUNCTION Clone (BYREF ppstm AS IStream PTR) AS HRESULT
END TYPE
TYPE AFX_LPSTREAM AS Afx_IStream PTR
#endif

' // WIC GUIDs and CLSIDs
DIM SHARED CLSID_WICImagingFactory AS GUID = (&hCACAF262, &h9370, &h4615, {&hA1, &h3B, &h9F, &h55, &h39, &hDA, &h4C, &h0A})
DIM SHARED CLSID_WICImagingFactory1 AS GUID = (&hCACAF262, &h9370, &h4615, {&hA1, &h3B, &h9F, &h55, &h39, &hDA, &h4C, &h0A})
DIM SHARED CLSID_WICImagingFactory2 AS GUID = (&h317D06E8, &h5F24, &h433D, {&hBD, &hF7, &h79, &hCE, &h68, &hD8, &hAB, &hC2})

' // Decoders
DIM SHARED CLSID_WICAdngDecoder AS GUID = TYPE<GUID>(&h981d9411, &h909e, &h42a7, {&h8f, &h5d, &ha7, &h47, &hff, &h05, &h2e, &hdb})
DIM SHARED CLSID_WICBmpDecoder AS GUID = TYPE<GUID>(&h6B462062, &h7CBF, &h400D, {&h9F, &hDB, &h81, &h3D, &hD1, &h0F, &h27, &h78})
DIM SHARED CLSID_WICDdsDecoder AS GUID = TYPE<GUID>(&h9053699f, &ha341, &h429d, {&h9e, &h90, &hee, &h43, &h7c, &hf8, &h0c, &h73})
DIM SHARED CLSID_WICGifDecoder AS GUID = TYPE<GUID>(&h381DDA3C, &h9CE9, &h4834, {&hA2, &h3E, &h1F, &h98, &hF8, &hFC, &h52, &hBE})
DIM SHARED CLSID_WICHeifDecoder AS GUID = TYPE<GUID>(&he9A4A80a, &h44fe, &h4DE4, {&h89, &h71, &h71, &h50, &hB1, &h0a, &h51, &h99})
DIM SHARED CLSID_WICIcoDecoder AS GUID = TYPE<GUID>(&hC61BFCDF, &h2E0F, &h4AAD, {&hA8, &hD7, &hE0, &h6B, &hAF, &hEB, &hCD, &hFE})
DIM SHARED CLSID_WICJpegDecoder AS GUID = TYPE<GUID>(&h9456A480, &hE88B, &h43EA, {&h9E, &h73, &h0B, &h2D, &h9B, &h71, &hB1, &hCA})
DIM SHARED CLSID_WICJpegXLEncoder AS GUID = TYPE<GUID>(&h0e4ecd3b, &h1ba6, &h4636, {&h81, &h98, &h56, &hc7, &h30, &h40, &h96, &h4a})
DIM SHARED CLSID_WICPngDecoder AS GUID = TYPE<GUID>(&h389EA17B, &h5078, &h4CDE, {&hB6, &hEF, &h25, &hC1, &h51, &h75, &hC7, &h51})
DIM SHARED CLSID_WICPngDecoder1 AS GUID = TYPE<GUID>(&h389EA17B, &h5078, &h4CDE, {&hB6, &hEF, &h25, &hC1, &h51, &h75, &hC7, &h51})
DIM SHARED CLSID_WICPngDecoder2 AS GUID = TYPE<GUID>(&he018945b, &haa86, &h4008, {&h9b, &hd4, &h67, &h77, &ha1, &he4, &h0c, &h11})
DIM SHARED CLSID_WICTiffDecoder AS GUID = TYPE<GUID>(&hB54E85D9, &hFE23, &h499F, {&h8B, &h88, &h6A, &hCE, &hA7, &h13, &h75, &h2B})
DIM SHARED CLSID_WICWmpDecoder AS GUID = TYPE<GUID>(&ha26cec36, &h234c, &h4950, {&hae, &h16, &he3, &h4a, &hac, &he7, &h1d, &h0d})

' // Encoders
DIM SHARED CLSID_WICBmpEncoder AS GUID = TYPE<GUID>(&h69BE8BB4, &hD66D, &h47C8, {&h86, &h5A, &hED, &h15, &h89, &h43, &h37, &h82})
DIM SHARED CLSID_WICDdsEncoder AS GUID = TYPE<GUID>(&ha61dde94, &h66ce, &h4ac1, {&h88, &h1b, &h71, &h68, &h05, &h88, &h89, &h5e})
DIM SHARED CLSID_WICGifEncoder AS GUID = TYPE<GUID>(&h114f5598, &h0b22, &h40a0, {&h86, &ha1, &hc8, &h3e, &ha4, &h95, &had, &hbd})
DIM SHARED CLSID_WICHeifEncoder AS GUID = TYPE<GUID>(&h0dbecec1, &h9eb3, &h4860, {&h9c, &h6f, &hdd, &hbe, &h86, &h63, &h45, &h75})
DIM SHARED CLSID_WICJpegEncoder AS GUID = TYPE<GUID>(&h1A34F5C1, &h4A5A, &h46DC, {&hB6, &h44, &h1F, &h45, &h67, &hE7, &hA6, &h76})
DIM SHARED CLSID_WICJpegQualcommPhoneEncoder AS GUID = TYPE<GUID>(&h68ed5c62, &hf534, &h4979, {&hb2, &hb3, &h68, &h6a, &h12, &hb2, &hb3, &h4c})
DIM SHARED CLSID_WICJpegXLDecoder AS GUID = TYPE<GUID>(&hfc6ceece, &haef5, &h4a23, {&h96, &hec, &h59, &h84, &hff, &hb4, &h86, &hd9})
DIM SHARED CLSID_WICPngEncoder AS GUID = TYPE<GUID>(&h27949969, &h876A, &h41D7, {&h94, &h47, &h56, &h8F, &h6A, &h35, &hA4, &hDC})
DIM SHARED CLSID_WICRAWDecoder AS GUID = TYPE<GUID>(&h41945702, &h8302, &h44A6, {&h94, &h45, &hAC, &h98, &hE8, &hAF, &hA0, &h86})
DIM SHARED CLSID_WICTiffEncoder AS GUID = TYPE<GUID>(&h0131BE10, &h2001, &h4C5F, {&hA9, &hB0, &hCC, &h88, &hFA, &hB6, &h4C, &hE8})
DIM SHARED CLSID_WICWebpDecoder AS GUID = TYPE<GUID>(&h7693E886, &h51C9, &h4070, {&h84, &h19, &h9F, &h70, &h73, &h8E, &hC8, &hFA})
DIM SHARED CLSID_WICWmpEncoder AS GUID = TYPE<GUID>(&hac4ce3cb, &he1c1, &h44cd, {&h82, &h15, &h5a, &h16, &h65, &h50, &h9e, &hc2})

DIM SHARED CLSID_WICIcnsEncoder AS GUID = (&h312FB6F1, &hB767, &h409D, {&h8A, &h6D, &h0F, &hC1, &h54, &hD4, &hF0, &h5C})

' // Container formats
DIM SHARED GUID_ContainerFormatAdng AS GUID = TYPE<GUID>(&hf3ff6d0d, &h38c0, &h41c4, {&hb1, &hfe, &h1f, &h38, &h24, &hf1, &h7b, &h84})
DIM SHARED GUID_ContainerFormatBmp AS GUID = TYPE<GUID>(&h0af1d87e, &hfcfe, &h4188, {&hbd, &heb, &ha7, &h90, &h64, &h71, &hcb, &he3})
DIM SHARED GUID_ContainerFormatPng AS GUID = TYPE<GUID>(&h1b7cfaf4, &h713f, &h473c, {&hbb, &hcd, &h61, &h37, &h42, &h5f, &hae, &haf})
DIM SHARED GUID_ContainerFormatIco AS GUID = TYPE<GUID>(&ha3a860c4, &h338f, &h4c17, {&h91, &h9a, &hfb, &ha4, &hb5, &h62, &h8f, &h21})
DIM SHARED GUID_ContainerFormatJpeg AS GUID = TYPE<GUID>(&h19e4a5aa, &h5662, &h4fc5, {&ha0, &hc0, &h17, &h58, &h02, &h8e, &h10, &h57})
DIM SHARED GUID_ContainerFormatTiff AS GUID = TYPE<GUID>(&h163bcc30, &he2e9, &h4f0b, {&h96, &h1d, &ha3, &he9, &hfd, &hb7, &h88, &ha3})
DIM SHARED GUID_ContainerFormatGif AS GUID = TYPE<GUID>(&h1f8a5601, &h7d4d, &h4cbd, {&h9c, &h82, &h1b, &hc8, &hd4, &hee, &hb9, &ha5})
DIM SHARED GUID_ContainerFormatWmp AS GUID = TYPE<GUID>(&h57a37caa, &h367a, &h4540, {&h91, &h6b, &hf1, &h83, &hc5, &h09, &h3a, &h4b})
DIM SHARED GUID_ContainerFormatDds AS GUID = TYPE<GUID>(&h9967cb95, &h2e85, &h4ac8, {&h8c, &ha2, &h83, &hd7, &hcc, &hd4, &h25, &hc9})
DIM SHARED GUID_ContainerFormatHeif AS GUID = TYPE<GUID>(&he1e62521, &h6787, &h405b, {&ha3, &h39, &h50, &h07, &h15, &hb5, &h76, &h3f})
DIM SHARED GUID_ContainerFormatWebp AS GUID = TYPE<GUID>(&he094b0e2, &h67f2, &h45b3, {&hb0, &hea, &h11, &h53, &h37, &hca, &h7c, &hf3})
DIM SHARED GUID_ContainerFormatRaw AS GUID = TYPE<GUID>(&hfe99ce60, &hf19c, &h433c, {&ha3, &hae, &h00, &hac, &hef, &ha9, &hca, &h21})
DIM SHARED GUID_ContainerFormatJpegXL AS GUID = TYPE<GUID>(&hfec14e3f, &h427a, &h4736, {&haa, &he6, &h27, &hed, &h84, &hf6, &h93, &h22})

' // Component identifiers
DIM SHARED CLSID_WICImagingCategories AS GUID = TYPE<GUID>(&hfae3d380, &hfea4, &h4623, {&h8c, &h75, &hc6, &hb6, &h11, &h10, &hb6, &h81})
DIM SHARED CATID_WICBitmapDecoders AS GUID = TYPE<GUID>(&h7ed96837, &h96f0, &h4812, {&hb2, &h11, &hf1, &h3c, &h24, &h11, &h7e, &hd3})
DIM SHARED CATID_WICBitmapEncoders AS GUID = TYPE<GUID>(&hac757296, &h3522, &h4e11, {&h98, &h62, &hc1, &h7b, &he5, &ha1, &h76, &h7e})
DIM SHARED CATID_WICPixelFormats AS GUID = TYPE<GUID>(&h2b46e70f, &hcda7, &h473e, {&h89, &hf6, &hdc, &h96, &h30, &ha2, &h39, &h0b})
DIM SHARED CATID_WICFormatConverters AS GUID = TYPE<GUID>(&h7835eae8, &hbf14, &h49d1, {&h93, &hce, &h53, &h3a, &h40, &h7b, &h22, &h48})
DIM SHARED CATID_WICMetadataReader AS GUID = TYPE<GUID>(&h05af94d8, &h7174, &h4cd2, {&hbe, &h4a, &h41, &h24, &hb8, &h0e, &he4, &hb8})
DIM SHARED CATID_WICMetadataWriter AS GUID = TYPE<GUID>(&habe3b9a4, &h257d, &h4b97, {&hbd, &h1a, &h29, &h4a, &hf4, &h96, &h22, &h2e})
DIM SHARED CLSID_WICHeifMetadataReader AS GUID = TYPE<GUID>(&hacddfc3f, &h85ec, &h41bc, {&hbd, &hef, &h1b, &hc2, &h62, &he4, &hdb, &h05})
DIM SHARED CLSID_WICHeifMetadataWriter AS GUID = TYPE<GUID>(&h3ae45e79, &h40bc, &h4401, {&hac, &he5, &hdd, &h3c, &hb1, &h6e, &h6a, &hfe})
DIM SHARED CLSID_WICWebpAnimMetadataReader AS GUID = TYPE<GUID>(&h76f9911, &ha348, &h465c, {&ha8, &h07, &ha2, &h52, &hf3, &hf3, &hd3, &hde})
DIM SHARED CLSID_WICWebpAnmfMetadataReader AS GUID = TYPE<GUID>(&h85a10b03, &hc9f6, &h439f, {&hbe, &h5e, &hc0, &hfb, &hef, &h67, &h80, &h7c})

' // Format converters
DIM SHARED CLSID_WICDefaultFormatConverter AS GUID = TYPE<GUID>(&h1A3F11DC, &hB514, &h4B17, {&h8C, &h5F, &h21, &h54, &h51, &h38, &h52, &hF1})
DIM SHARED CLSID_WICFormatConverterHighColor AS GUID = TYPE<GUID>(&hac75d454, &h9f37, &h48f8, {&hb9, &h72, &h4e, &h19, &hbc, &h85, &h60, &h11})
DIM SHARED CLSID_WICFormatConverterNChannel AS GUID = TYPE<GUID>(&hc17cabb2, &hd4a3, &h47d7, {&ha5, &h57, &h33, &h9b, &h2e, &hfb, &hd4, &hf1})
DIM SHARED CLSID_WICFormatConverterWMPhoto AS GUID = TYPE<GUID>(&h9cb5172b, &hd600, &h46ba, {&hab, &h77, &h77, &hbb, &h7e, &h3a, &h00, &hd9})
DIM SHARED CLSID_WICPlanarFormatConverter AS GUID = TYPE<GUID>(&h184132b8, &h32f8, &h4784, {&h91, &h31, &hdd, &h72, &h24, &hb2, &h34, &h38})

' // Metadata handlers: https://learn.microsoft.com/pt-br/windows/win32/wic/-wic-guids-clsids:
'GUID_MetadataFormatUnknown	0xA45E592F, 0x9078, 0x4A7C, 0xAD, 0xB5, 0x4E, 0xDC, 0x4F, 0xD6, 0x1B, 0x1F
'GUID_MetadataFormatIfd	0x537396C6, 0x2D8A, 0x4BB6, 0x9B, 0xF8, 0x2F, 0x0A, 0x8E, 0x2A, 0x3A, 0xDF
'GUID_MetadataFormatSubIfd	0x58A2E128, 0x2DB9, 0x4E57, 0xBB, 0x14, 0x51, 0x77, 0x89, 0x1E, 0xD3, 0x31
'GUID_MetadataFormatExif	0x1C3C4F9D, 0xB84A, 0x467D, 0x94, 0x93, 0x36, 0xCF, 0xBD, 0x59, 0xEA, 0x57
'GUID_MetadataFormatGps	0x7134AB8A, 0x9351, 0x44AD, 0xAF, 0x62, 0x44, 0x8D, 0xB6, 0xB5, 0x02, 0xEC
'GUID_MetadataFormatInterop	0xED686F8E, 0x681F, 0x4C8B, 0xBD, 0x41, 0xA8, 0xAD, 0xDB, 0xF6, 0xB3, 0xFC
'GUID_MetadataFormatApp0	0x79007028, 0x268D, 0x45d6, 0xA3, 0xC2, 0x35, 0x4E, 0x6A, 0x50, 0x4B, 0xC9
'GUID_MetadataFormatApp1	0x8FD3DFC3, 0xF951, 0x492B, 0x81, 0x7F, 0x69, 0xC2, 0xE6, 0xD9, 0xA5, 0xB0
'GUID_MetadataFormatApp13	0x326556A2, 0xF502, 0x4354, 0x9C, 0xC0, 0x8E, 0x3F, 0x48, 0xEA, 0xF6, 0xB5
'GUID_MetadataFormatIPTC	0x4FAB0914, 0xE129, 0x4087, 0xA1, 0xD1, 0xBC, 0x81, 0x2D, 0x45, 0xA7, 0xB5
'GUID_MetadataFormatIRB	0x16100D66, 0x8570, 0x4BB9, 0xB9, 0x2D, 0xFD, 0xA4, 0xB2, 0x3E, 0xCE, 0x67
'GUID_MetadataFormat8BIMIPTC	0x0010568c, 0x0852, 0x4e6a, 0xb1, 0x91, 0x5c, 0x33, 0xac, 0x5b, 0x04, 0x30
'GUID_MetadataFormat8BIMResolutionInfo	0x739F305D, 0x81DB, 0x43CB, 0xAC, 0x5E, 0x55, 0x01, 0x3E, 0xF9, 0xF0, 0x03
'GUID_MetadataFormat8BIMIPTCDigest	0x1CA32285, 0x9CCD, 0x4786, 0x8B, 0xD8, 0x79, 0x53, 0x9D, 0xB6, 0xA0, 0x06
'GUID_MetadataFormatXMP	0xBB5ACC38, 0xF216, 0x4CEC, 0xA6, 0xC5, 0x5F, 0x6E, 0x73, 0x97, 0x63, 0xA9
'GUID_MetadataFormatThumbnail	0x243dcee9, 0x8703, 0x40ee, 0x8e, 0xf0, 0x22, 0xa6, 0x0, 0xb8, 0x5, 0x8c
'GUID_MetadataFormatChunktEXt	0x568d8936, 0xc0a9, 0x4923, 0x90, 0x5d, 0xdf, 0x2b, 0x38, 0x23, 0x8f, 0xbc
'GUID_MetadataFormatXMPStruct	0x22383CF1, 0xED17, 0x4E2E, 0xAF, 0x17, 0xD8, 0x5B, 0x8F, 0x6B, 0x30, 0xD0
'GUID_MetadataFormatXMPBag	0x833CCA5F, 0xDCB7, 0x4516, 0x80, 0x6F, 0x65, 0x96, 0xAB, 0x26, 0xDC, 0xE4
'GUID_MetadataFormatXMPSeq	0x63E8DF02, 0xEB6C,0x456C, 0xA2, 0x24, 0xB2, 0x5E, 0x79, 0x4F, 0xD6, 0x48
'GUID_MetadataFormatXMPAlt	0x7B08A675, 0x91AA, 0x481B, 0xA7, 0x98, 0x4D, 0xA9, 0x49, 0x08, 0x61, 0x3B
'GUID_MetadataFormatLSD	0xE256031E, 0x6299, 0x4929, 0xB9, 0x8D, 0x5A, 0xC8, 0x84, 0xAF, 0xBA, 0x92
'GUID_MetadataFormatIMD	0xBD2BB086, 0x4D52, 0x48DD, 0x96, 0x77, 0xDB, 0x48, 0x3E, 0x85, 0xAE, 0x8F
'GUID_MetadataFormatGCE	0x2A25CAD8, 0xDEEB, 0x4C69, 0xA7, 0x88, 0xE, 0xC2, 0x26, 0x6D, 0xCA, 0xFD
'GUID_MetadataFormatAPE	0x2E043DC2, 0xC967, 0x4E05, 0x87, 0x5E, 0x61, 0x8B, 0xF6, 0x7E, 0x85, 0xC3
'GUID_MetadataFormatJpegChrominance	0xF73D0DCF, 0xCEC6, 0x4F85, 0x9B, 0x0E, 0x1C, 0x39, 0x56, 0xB1, 0xBE, 0xF7
'GUID_MetadataFormatJpegLuminance	0x86908007, 0xEDFC, 0x4860, 0x8D, 0x4B, 0x4E, 0xE6, 0xE8, 0x3E, 0x60, 0x58
'GUID_MetadataFormatJpegComment	0x220E5F33, 0xAFD3, 0x474E, 0x9D, 0x31, 0x7D, 0x4F, 0xE7, 0x30, 0xF5, 0x57
'GUID_MetadataFormatGifComment	0xC4B6E0E0, 0xCFB4, 0x4AD3, 0xAB, 0x33, 0x9A, 0xAD, 0x23, 0x55, 0xA3, 0x4A
'GUID_MetadataFormatChunkgAMA	0xF00935A5, 0x1D5D, 0x4CD1, 0x81, 0xB2, 0x93, 0x24, 0xD7, 0xEC, 0xA7, 0x81
'GUID_MetadataFormatChunkbKGD	0xE14D3571, 0x6B47, 0x4DEA, 0xB6, 0xA, 0x87, 0xCE, 0xA, 0x78, 0xDF, 0xB7
'GUID_MetadataFormatChunkiTXt	0xC2BEC729, 0xB68, 0x4B77, 0xAA, 0xE, 0x62, 0x95, 0xA6, 0xAC, 0x18, 0x14
'GUID_MetadataFormatChunkcHRM	0x9DB3655B, 0x2842, 0x44B3, 0x80, 0x67, 0x12, 0xE9, 0xB3, 0x75, 0x55, 0x6A
'GUID_MetadataFormatChunkhIST	0xC59A82DA, 0xDB74, 0x48A4, 0xBD, 0x6A, 0xB6, 0x9C, 0x49, 0x31, 0xEF, 0x95
'GUID_MetadataFormatChunkiCCP	0xEB4349AB, 0xB685, 0x450F, 0x91, 0xB5, 0xE8, 0x2, 0xE8, 0x92, 0x53, 0x6C
'GUID_MetadataFormatChunksRGB	0xC115FD36, 0xCC6F, 0x4E3F, 0x83, 0x63, 0x52, 0x4B, 0x87, 0xC6, 0xB0, 0xD9
'GUID_MetadataFormatChunktIME	0x6B00AE2D, 0xE24B, 0x460A, 0x98, 0xB6, 0x87, 0x8B, 0xD0, 0x30, 0x72, 0xFD
'GUID_MetadataFormatHeif	0x817EF3E1, 0x1288, 0x45F4, 0xA8, 0x52, 0x26, 0x0D, 0x9E, 0x7C, 0xCE, 0x83
'GUID_MetadataFormatWebpANIM	0x6dc4fda6, 0x78e6, 0x4102, 0xae, 0x35, 0xbc, 0xfa, 0x1e, 0xdc, 0xc7, 0x8b
'GUID_MetadataFormatWebpANMF	0x43c105ee, 0xb93b, 0x4abb, 0xb0, 0x3, 0xa0, 0x8c, 0xd, 0x87, 0x4, 0x71
 

DIM SHARED CLSID_WICAPEMetadataReader AS GUID = (&h1767B93A, &hB021, &h44EA, {&h92, &h0F, &h86, &h3C, &h11, &hF4, &hF7, &h68})
DIM SHARED CLSID_WICGCEMetadataReader AS GUID = (&hB92E345D, &hF52D, &h41F3, {&hB5, &h62, &h08, &h1B, &hC7, &h72, &hE3, &hB9})
DIM SHARED CLSID_WICGifCommentMetadataReader AS GUID = (&h32557D3B, &h69DC, &h4F95, {&h83, &h6E, &hF5, &h97, &h2B, &h2F, &h61, &h59})
DIM SHARED CLSID_WICIMDMetadataReader AS GUID = (&h7447A267, &h0015, &h42C8, {&hA8, &hF1, &hFB, &h3B, &h94, &hC6, &h83, &h61})
DIM SHARED CLSID_WICLSDMetadataReader AS GUID = (&h41070793, &h59E4, &h479A, {&hA1, &hF7, &h95, &h4A, &hDC, &h2E, &hF5, &hFC})
DIM SHARED CLSID_WICPngChrmMetadataReader AS GUID = (&hF90B5F36, &h367B, &h402A, {&h9D, &hD1, &hBC, &h0F, &hD5, &h9D, &h8F, &h62})
DIM SHARED CLSID_WICPngGamaMetadataReader AS GUID = (&h3692CA39, &hE082, &h4350, {&h9E, &h1F, &h37, &h04, &hCB, &h08, &h3C, &hD5})
DIM SHARED CLSID_WICPngTextMetadataReader AS GUID = (&h4B59AFCC, &hB8C3, &h408A, {&hB6, &h70, &h89, &hE5, &hFA, &hB6, &hFD, &hA7})
DIM SHARED CLSID_WICUnknownMetadataReader AS GUID = (&h699745C2, &h5066, &h4B82, {&hA8, &hE3, &hD4, &h04, &h78, &hDB, &hEC, &h8C})

' // Vendor identification
DIM SHARED GUID_VendorMicrosoft AS GUID = TYPE<GUID>(&hf0e749ca, &hedef, &h4589, {&ha7, &h3a, &hee, &he, &h62, &h6a, &h2a, &h2b})
DIM SHARED GUID_VendorMicrosoftBuiltIn AS GUID = TYPE<GUID>(&h257a30fd, &h6b6, &h462b, {&hae, &ha4, &h63, &hf7, &hb, &h86, &he5, &h33})
' MSDN cita en https://learn.microsoft.com/pt-br/windows/win32/wic/-wic-guids-clsids:
' GUID_VendorMicrosoft	0x69fd0fdc, 0xa866, 0x4108, 0xb3, 0xb2, 0x98, 0x44, 0x7f, 0xa9, 0xed, 0xd4

'/* Forward Declarations */ 

type IWICPalette AS IWICPalette_
type IWICBitmapSource AS IWICBitmapSource_
type IWICFormatConverter AS IWICFormatConverter_
type IWICPlanarFormatConverter AS IWICPlanarFormatConverter_
type IWICBitmapScaler AS IWICBitmapScaler_
type IWICBitmapClipper AS IWICBitmapClipper_
type IWICBitmapFlipRotator AS IWICBitmapFlipRotator_
type IWICBitmapLock AS IWICBitmapLock_
type IWICBitmap AS IWICBitmap_
type IWICColorContext AS IWICColorContext_
type IWICColorTransform AS IWICColorTransform_
type IWICFastMetadataEncoder AS IWICFastMetadataEncoder_
type IWICStream AS IWICStream_
type IWICEnumMetadataItem AS IWICEnumMetadataItem_
type IWICMetadataQueryReader AS IWICMetadataQueryReader_
type IWICMetadataQueryWriter AS IWICMetadataQueryWriter_
type IWICBitmapEncoder AS IWICBitmapEncoder_
type IWICBitmapFrameEncode AS IWICBitmapFrameEncode_
type IWICPlanarBitmapFrameEncode AS IWICPlanarBitmapFrameEncode_
type IWICImageEncoder AS IWICImageEncoder_
type IWICBitmapDecoder AS IWICBitmapDecoder_
type IWICBitmapSourceTransform AS IWICBitmapSourceTransform_
type IWICBitmapSourceTransform2 AS IWICBitmapSourceTransform2_
type IWICPlanarBitmapSourceTransform AS IWICPlanarBitmapSourceTransform_
type IWICBitmapFrameDecode AS IWICBitmapFrameDecode_
type IWICProgressiveLevelControl AS IWICProgressiveLevelControl_
type IWICDisplayAdaptationControl AS IWICDisplayAdaptationControl_
type IWICProgressCallback AS IWICProgressCallback_
type IWICBitmapCodecProgressNotification AS IWICBitmapCodecProgressNotification_
type IWICComponentInfo AS IWICComponentInfo_
type IWICFormatConverterInfo AS IWICFormatConverterInfo_
type IWICBitmapCodecInfo AS IWICBitmapCodecInfo_
type IWICBitmapEncoderInfo AS IWICBitmapEncoderInfo_
type IWICBitmapDecoderInfo AS IWICBitmapDecoderInfo_
type IWICPixelFormatInfo AS IWICPixelFormatInfo_
type IWICPixelFormatInfo2 AS IWICPixelFormatInfo2_
type IWICImagingFactory AS IWICImagingFactory_
type IWICImagingFactory2 AS IWICImagingFactory2_
type IWICDevelopRawNotificationCallback AS IWICDevelopRawNotificationCallback_
type IWICDevelopRaw AS IWICDevelopRaw_
type IWICDdsDecoder AS IWICDdsDecoder_
type IWICDdsEncoder AS IWICDdsEncoder_
type IWICDdsFrameDecode AS IWICDdsFrameDecode_
type IWICJpegFrameDecode AS IWICJpegFrameDecode_
type IWICJpegFrameEncode AS IWICJpegFrameEncode_

type ID2D1Device AS ID2D1Device_
type ID2D1Image AS ID2D1Image_
type WICColor AS UINT32

type WICRect
   AS INT_ X
   AS INT_ Y
   AS INT_ Width
   AS INT_ Height
end type

TYPE WICInProcPointer AS BYTE PTR

enum WICColorContextType
   WICColorContextUninitialized= 0
   WICColorContextProfile= &h1
   WICColorContextExifColorSpace	= &h2
end enum

CONST WIC_JPEG_MAX_COMPONENT_COUNT = 4
CONST WIC_JPEG_MAX_TABLE_INDEX = 3
CONST WIC_JPEG_SAMPLE_FACTORS_ONE = &h11
CONST WIC_JPEG_SAMPLE_FACTORS_THREE_420 = &h111122 
CONST WIC_JPEG_SAMPLE_FACTORS_THREE_422 = &h111121
CONST WIC_JPEG_SAMPLE_FACTORS_THREE_440 = &h111112
CONST WIC_JPEG_SAMPLE_FACTORS_THREE_444 = &h111111
CONST WIC_JPEG_QUANTIZATION_BASELINE_ONE = 0
CONST WIC_JPEG_QUANTIZATION_BASELINE_THREE = &h10100
CONST WIC_JPEG_HUFFMAN_BASELINE_ONE = 0
CONST WIC_JPEG_HUFFMAN_BASELINE_THREE = &h111100

'typedef /* [public] */ REFGUID REFWICPixelFormatGUID
#define REFWICPixelFormatGUID REFGUID
'typedef /* [public] */ GUID WICPixelFormatGUID
#define WICPixelFormatGUID GUID

DIM SHARED IID_WICPixelFormatDontCare AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h00})
#define IID_WICPixelFormatUndefined GUID_WICPixelFormatDontCare
DIM SHARED IID_WICPixelFormat1bppIndexed AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h01})
DIM SHARED IID_WICPixelFormat2bppIndexed AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h02})
DIM SHARED IID_WICPixelFormat4bppIndexed AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h03})
DIM SHARED IID_WICPixelFormat8bppIndexed AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h04})
DIM SHARED IID_WICPixelFormatBlackWhite AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h05})
DIM SHARED IID_WICPixelFormat2bppGray AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h06})
DIM SHARED IID_WICPixelFormat4bppGray AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h07})
DIM SHARED IID_WICPixelFormat8bppGray AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h08})
DIM SHARED IID_WICPixelFormat8bppAlpha AS GUID = TYPE<GUID>(&he6cd0116, &heeba, &h4161, {&haa, &h85, &h27, &hdd, &h9f, &hb3, &ha8, &h95})
DIM SHARED IID_WICPixelFormat8bppDepth AS GUID = TYPE<GUID>(&h4c9c9f45, &h1d89, &h4e31, {&h9b, &hc7, &h69, &h34, &h3a, &h0d, &hca, &h69})
DIM SHARED IID_WICPixelFormat8bppGain AS GUID = TYPE<GUID>(&ha884022a, &haf13, &h4c16, {&hb7, &h46, &h61, &h9b, &hf6, &h18, &hb8, &h78})
DIM SHARED IID_WICPixelFormat16bppBGR555 AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h09})
DIM SHARED IID_WICPixelFormat16bppBGR565 AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h0a})
DIM SHARED IID_WICPixelFormat16bppBGRA5551 AS GUID = TYPE<GUID>(&h05ec7c2b, &hf1e6, &h4961, {&had, &h46, &he1, &hcc, &h81, &h0a, &h87, &hd2})
DIM SHARED IID_WICPixelFormat16bppGray AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h0b})
DIM SHARED IID_WICPixelFormat24bppBGR AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h0c})
DIM SHARED IID_WICPixelFormat24bppRGB AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h0d})
DIM SHARED IID_WICPixelFormat32bppBGR AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h0e})
DIM SHARED IID_WICPixelFormat32bppBGRA AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h0f})
DIM SHARED IID_WICPixelFormat32bppPBGRA AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h10})
DIM SHARED IID_WICPixelFormat32bppGrayFloat AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h11})
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE)
DIM SHARED IID_WICPixelFormat32bppRGB AS GUID = TYPE<GUID>(&hd98c6b95, &h3efe, &h47d6, {&hbb, &h25, &heb, &h17, &h48, &hab, &h0c, &hf1})
'#endif
DIM SHARED IID_WICPixelFormat32bppRGBA AS GUID = TYPE<GUID>(&hf5c7ad2d, &h6a8d, &h43dd, {&ha7, &ha8, &ha2, &h99, &h35, &h26, &h1a, &he9})
DIM SHARED IID_WICPixelFormat32bppPRGBA AS GUID = TYPE<GUID>(&h3cc4a650, &ha527, &h4d37, {&ha9, &h16, &h31, &h42, &hc7, &heb, &hed, &hba})
DIM SHARED IID_WICPixelFormat48bppRGB AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h15})
DIM SHARED IID_WICPixelFormat48bppBGR AS GUID = TYPE<GUID>(&he605a384, &hb468, &h46ce, {&hbb, &h2e, &h36, &hf1, &h80, &he6, &h43, &h13})
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE)
DIM SHARED IID_WICPixelFormat64bppRGB AS GUID = TYPE<GUID>(&ha1182111, &h186d, &h4d42, {&hbc, &h6a, &h9c, &h83, &h03, &ha8, &hdf, &hf9})
'#endif
DIM SHARED IID_WICPixelFormat64bppRGBA AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h16})
DIM SHARED IID_WICPixelFormat64bppBGRA AS GUID = TYPE<GUID>(&h1562ff7c, &hd352, &h46f9, {&h97, &h9e, &h42, &h97, &h6b, &h79, &h22, &h46})
DIM SHARED IID_WICPixelFormat64bppPRGBA AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h17})
DIM SHARED IID_WICPixelFormat64bppPBGRA AS GUID = TYPE<GUID>(&h8c518e8e, &ha4ec, &h468b, {&hae, &h70, &hc9, &ha3, &h5a, &h9c, &h55, &h30})
DIM SHARED IID_WICPixelFormat16bppGrayFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h13})
DIM SHARED IID_WICPixelFormat32bppBGR101010 AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h14})
DIM SHARED IID_WICPixelFormat48bppRGBFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h12})
DIM SHARED IID_WICPixelFormat48bppBGRFixedPoint AS GUID = TYPE<GUID>(&h49ca140e, &hcab6, &h493b, {&h9d, &hdf, &h60, &h18, &h7c, &h37, &h53, &h2a})
DIM SHARED IID_WICPixelFormat96bppRGBFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h18})
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE)
DIM SHARED IID_WICPixelFormat96bppRGBFloat AS GUID = TYPE<GUID>(&he3fed78f, &he8db, &h4acf, {&h84, &hc1, &he9, &h7f, &h61, &h36, &hb3, &h27})
'#endif
DIM SHARED IID_WICPixelFormat128bppRGBAFloat AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h19})
DIM SHARED IID_WICPixelFormat128bppPRGBAFloat AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h1a})
DIM SHARED IID_WICPixelFormat128bppRGBFloat AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h1b})
DIM SHARED IID_WICPixelFormat32bppCMYK AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h1c})
DIM SHARED IID_WICPixelFormat64bppRGBAFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h1d})
DIM SHARED IID_WICPixelFormat64bppBGRAFixedPoint AS GUID = TYPE<GUID>(&h356de33c, &h54d2, &h4a23, {&hbb, &h4, &h9b, &h7b, &hf9, &hb1, &hd4, &h2d})
DIM SHARED IID_WICPixelFormat64bppRGBFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h40})
DIM SHARED IID_WICPixelFormat128bppRGBAFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h1e})
DIM SHARED IID_WICPixelFormat128bppRGBFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h41})
DIM SHARED IID_WICPixelFormat64bppRGBAHalf AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h3a})
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE)
DIM SHARED IID_WICPixelFormat64bppPRGBAHalf AS GUID = TYPE<GUID>(&h58ad26c2, &hc623, &h4d9d, {&hb3, &h20, &h38, &h7e, &h49, &hf8, &hc4, &h42})
'#endif
DIM SHARED IID_WICPixelFormat64bppRGBHalf AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h42})
DIM SHARED IID_WICPixelFormat48bppRGBHalf AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h3b})
DIM SHARED IID_WICPixelFormat32bppRGBE AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h3d})
DIM SHARED IID_WICPixelFormat16bppGrayHalf AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h3e})
DIM SHARED IID_WICPixelFormat32bppGrayFixedPoint AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h3f})
DIM SHARED IID_WICPixelFormat32bppRGBA1010102 AS GUID = TYPE<GUID>(&h25238D72, &hFCF9, &h4522, {&hb5, &h14, &h55, &h78, &he5, &had, &h55, &he0})
DIM SHARED IID_WICPixelFormat32bppRGBA1010102XR AS GUID = TYPE<GUID>(&h00DE6B9A, &hC101, &h434b, {&hb5, &h02, &hd0, &h16, &h5e, &he1, &h12, &h2c})
DIM SHARED IID_WICPixelFormat32bppR10G10B10A2 AS GUID = TYPE<GUID>(&h604e1bb5, &h8a3c, &h4b65, {&hb1, &h1c, &hbc, &h0b, &h8d, &hd7, &h5b, &h7f})
DIM SHARED IID_WICPixelFormat32bppR10G10B10A2HDR10 AS GUID = TYPE<GUID>(&h9c215c5d, &h1acc, &h4f0e, {&ha4, &hbc, &h70, &hfb, &h3a, &he8, &hfd, &h28})
DIM SHARED IID_WICPixelFormat64bppCMYK AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h1f})
DIM SHARED IID_WICPixelFormat24bpp3Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h20})
DIM SHARED IID_WICPixelFormat32bpp4Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h21})
DIM SHARED IID_WICPixelFormat40bpp5Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h22})
DIM SHARED IID_WICPixelFormat48bpp6Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h23})
DIM SHARED IID_WICPixelFormat56bpp7Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h24})
DIM SHARED IID_WICPixelFormat64bpp8Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h25})
DIM SHARED IID_WICPixelFormat48bpp3Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h26})
DIM SHARED IID_WICPixelFormat64bpp4Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h27})
DIM SHARED IID_WICPixelFormat80bpp5Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h28})
DIM SHARED IID_WICPixelFormat96bpp6Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h29})
DIM SHARED IID_WICPixelFormat112bpp7Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h2a})
DIM SHARED IID_WICPixelFormat128bpp8Channels AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h2b})
DIM SHARED IID_WICPixelFormat40bppCMYKAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h2c})
DIM SHARED IID_WICPixelFormat80bppCMYKAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h2d})
DIM SHARED IID_WICPixelFormat32bpp3ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h2e})
DIM SHARED IID_WICPixelFormat40bpp4ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h2f})
DIM SHARED IID_WICPixelFormat48bpp5ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h30})
DIM SHARED IID_WICPixelFormat56bpp6ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h31})
DIM SHARED IID_WICPixelFormat64bpp7ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h32})
DIM SHARED IID_WICPixelFormat72bpp8ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h33})
DIM SHARED IID_WICPixelFormat64bpp3ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h34})
DIM SHARED IID_WICPixelFormat80bpp4ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h35})
DIM SHARED IID_WICPixelFormat96bpp5ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h36})
DIM SHARED IID_WICPixelFormat112bpp6ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h37})
DIM SHARED IID_WICPixelFormat128bpp7ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h38})
DIM SHARED IID_WICPixelFormat144bpp8ChannelsAlpha AS GUID = TYPE<GUID>(&h6fddc324, &h4e03, &h4bfe, {&hb1, &h85, &h3d, &h77, &h76, &h8d, &hc9, &h39})
DIM SHARED IID_WICPixelFormat8bppY AS GUID = TYPE<GUID>(&h91B4DB54, &h2DF9, &h42F0, {&hB4, &h49, &h29, &h09, &hBB, &h3D, &hF8, &h8E})
DIM SHARED IID_WICPixelFormat8bppCb AS GUID = TYPE<GUID>(&h1339F224, &h6BFE, &h4C3E, {&h93, &h02, &hE4, &hF3, &hA6, &hD0, &hCA, &h2A})
DIM SHARED IID_WICPixelFormat8bppCr AS GUID = TYPE<GUID>(&hB8145053, &h2116, &h49F0, {&h88, &h35, &hED, &h84, &h4B, &h20, &h5C, &h51})
DIM SHARED IID_WICPixelFormat16bppCbCr AS GUID = TYPE<GUID>(&hFF95BA6E, &h11E0, &h4263, {&hBB, &h45, &h01, &h72, &h1F, &h34, &h60, &hA4})
DIM SHARED IID_WICPixelFormat16bppYQuantizedDctCoefficients AS GUID = TYPE<GUID>(&hA355F433, &h48E8, &h4A42, {&h84, &hD8, &hE2, &hAA, &h26, &hCA, &h80, &hA4})
DIM SHARED IID_WICPixelFormat16bppCbQuantizedDctCoefficients AS GUID = TYPE<GUID>(&hD2C4FF61, &h56A5, &h49C2, {&h8B, &h5C, &h4C, &h19, &h25, &h96, &h48, &h37})
DIM SHARED IID_WICPixelFormat16bppCrQuantizedDctCoefficients AS GUID = TYPE<GUID>(&h2FE354F0, &h1680, &h42D8, {&h92, &h31, &hE7, &h3C, &h05, &h65, &hBF, &hC1})

TYPE WICBitmapCreateCacheOption AS LONG
enum
   WICBitmapNoCache = 0
   WICBitmapCacheOnDemand = &h1
   WICBitmapCacheOnLoad	= &h2
   WICBITMAPCREATECACHEOPTION_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICDecodeOptions AS LONG
enum
   WICDecodeMetadataCacheOnDemand = 0
   WICDecodeMetadataCacheOnLoad = &h1
   WICMETADATACACHEOPTION_FORCE_DWORD = &h7fffffff
end enum

TYPE WICBitmapEncoderCacheOption AS LONG
enum
   WICBitmapEncoderCacheInMemory	= 0
   WICBitmapEncoderCacheTempFile	= &h1
   WICBitmapEncoderNoCache	= &h2
   WICBITMAPENCODERCACHEOPTION_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICComponentType AS LONG
enum
   WICDecoder = &h1
   WICEncoder = &h2
   WICPixelFormatConverter = &h4
   WICMetadataReader = &h8
   WICMetadataWriter = &h10
   WICPixelFormat = &h20
   WICAllComponents = &h3f
   WICCOMPONENTTYPE_FORCE_DWORD = &h7fffffff
end enum

TYPE WICComponentEnumerateOptions AS LONG
enum
   WICComponentEnumerateDefault = 0
   WICComponentEnumerateRefresh = &h1
   WICComponentEnumerateDisabled = &h80000000
   WICComponentEnumerateUnsigned = &h40000000
   WICComponentEnumerateBuiltInOnly = &h20000000
   WICCOMPONENTENUMERATEOPTIONS_FORCE_DWORD = &h7fffffff
end enum

type WICBitmapPattern
   AS ULARGE_INTEGER Position
   AS ULONG Length
   AS BYTE PTR Pattern
   AS BYTE PTR Mask
   AS BOOL EndOfStream
end type

TYPE WICBitmapInterpolationMode AS LONG
enum
   WICBitmapInterpolationModeNearestNeighbor = 0
   WICBitmapInterpolationModeLinear	= &h1
   WICBitmapInterpolationModeCubic = &h2
   WICBitmapInterpolationModeFant = &h3
   WICBitmapInterpolationModeHighQualityCubic = &h4
   WICBITMAPINTERPOLATIONMODE_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICBitmapPaletteType AS LONG
enum
   WICBitmapPaletteTypeCustom	= 0
   WICBitmapPaletteTypeMedianCut	= &h1
   WICBitmapPaletteTypeFixedBW = &h2
   WICBitmapPaletteTypeFixedHalftone8 = &h3
   WICBitmapPaletteTypeFixedHalftone27	= &h4
   WICBitmapPaletteTypeFixedHalftone64	= &h5
   WICBitmapPaletteTypeFixedHalftone125 = &h6
   WICBitmapPaletteTypeFixedHalftone216 = &h7
   WICBitmapPaletteTypeFixedWebPalette	= WICBitmapPaletteTypeFixedHalftone216
   WICBitmapPaletteTypeFixedHalftone252 = &h8
   WICBitmapPaletteTypeFixedHalftone256 = &h9
   WICBitmapPaletteTypeFixedGray4 = &ha
   WICBitmapPaletteTypeFixedGray16 = &hb
   WICBitmapPaletteTypeFixedGray256	= &hc
   WICBITMAPPALETTETYPE_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICBitmapDitherType AS LONG
enum
   WICBitmapDitherTypeNone	= 0
   WICBitmapDitherTypeSolid = 0
   WICBitmapDitherTypeOrdered4x4	= &h1
   WICBitmapDitherTypeOrdered8x8	= &h2
   WICBitmapDitherTypeOrdered16x16 = &h3
   WICBitmapDitherTypeSpiral4x4 = &h4
   WICBitmapDitherTypeSpiral8x8 = &h5
   WICBitmapDitherTypeDualSpiral4x4	= &h6
   WICBitmapDitherTypeDualSpiral8x8	= &h7
   WICBitmapDitherTypeErrorDiffusion = &h8
   WICBITMAPDITHERTYPE_FORCE_DWORD = &h7fffffff
end enum

TYPE WICBitmapAlphaChannelOption AS LONG
enum
   WICBitmapUseAlpha	= 0
   WICBitmapUsePremultipliedAlpha = &h1
   WICBitmapIgnoreAlpha	= &h2
   WICBITMAPALPHACHANNELOPTIONS_FORCE_DWORD = &h7fffffff
end enum

TYPE WICBitmapTransformOptions AS LONG
enum
   WICBitmapTransformRotate0 = 0
   WICBitmapTransformRotate90	= &h1
   WICBitmapTransformRotate180 = &h2
   WICBitmapTransformRotate270 = &h3
   WICBitmapTransformFlipHorizontal	= &h8
   WICBitmapTransformFlipVertical = &h10
   WICBITMAPTRANSFORMOPTIONS_FORCE_DWORD = &h7fffffff
end enum

TYPE WICBitmapLockFlags AS LONG
enum
   WICBitmapLockRead	= &h1
   WICBitmapLockWrite = &h2
   WICBITMAPLOCKFLAGS_FORCE_DWORD = &h7fffffff
end enum

TYPE WICBitmapDecoderCapabilities AS LONG
enum
   WICBitmapDecoderCapabilitySameEncoder = &h1
   WICBitmapDecoderCapabilityCanDecodeAllImages	= &h2
   WICBitmapDecoderCapabilityCanDecodeSomeImages = &h4
   WICBitmapDecoderCapabilityCanEnumerateMetadata = &h8
   WICBitmapDecoderCapabilityCanDecodeThumbnail	= &h10
   WICBITMAPDECODERCAPABILITIES_FORCE_DWORD = &h7fffffff
end enum

TYPE WICProgressOperation AS LONG
enum
   WICProgressOperationCopyPixels = &h1
   WICProgressOperationWritePixels = &h2
   WICProgressOperationAll	= &hffff
   WICPROGRESSOPERATION_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICProgressNotification AS LONG
enum
   WICProgressNotificationBegin = &h10000
   WICProgressNotificationEnd	= &h20000
   WICProgressNotificationFrequent = &h40000
   WICProgressNotificationAll	= &hffff0000
   WICPROGRESSNOTIFICATION_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICComponentSigning AS LONG
enum
   WICComponentSigned = &h1
   WICComponentUnsigned	= &h2
   WICComponentSafe = &h4
   WICComponentDisabled	= &h80000000
   WICCOMPONENTSIGNING_FORCE_DWORD = &h7fffffff
end enum

TYPE WICGifLogicalScreenDescriptorProperties AS LONG
enum
   WICGifLogicalScreenSignature = &h1
   WICGifLogicalScreenDescriptorWidth = &h2
   WICGifLogicalScreenDescriptorHeight	= &h3
   WICGifLogicalScreenDescriptorGlobalColorTableFlag = &h4
   WICGifLogicalScreenDescriptorColorResolution	= &h5
   WICGifLogicalScreenDescriptorSortFlag = &h6
   WICGifLogicalScreenDescriptorGlobalColorTableSize = &h7
   WICGifLogicalScreenDescriptorBackgroundColorIndex = &h8
   WICGifLogicalScreenDescriptorPixelAspectRatio = &h9
   WICGifLogicalScreenDescriptorProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICGifImageDescriptorProperties AS LONG
enum
   WICGifImageDescriptorLeft = &h1
   WICGifImageDescriptorTop = &h2
   WICGifImageDescriptorWidth	= &h3
   WICGifImageDescriptorHeight = &h4
   WICGifImageDescriptorLocalColorTableFlag = &h5
   WICGifImageDescriptorInterlaceFlag = &h6
   WICGifImageDescriptorSortFlag	= &h7
   WICGifImageDescriptorLocalColorTableSize = &h8
   WICGifImageDescriptorProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICGifGraphicControlExtensionProperties AS LONG
enum
   WICGifGraphicControlExtensionDisposal = &h1
   WICGifGraphicControlExtensionUserInputFlag = &h2
   WICGifGraphicControlExtensionTransparencyFlag = &h3
   WICGifGraphicControlExtensionDelay = &h4
   WICGifGraphicControlExtensionTransparentColorIndex	= &h5
   WICGifGraphicControlExtensionProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICGifApplicationExtensionProperties AS LONG
enum
   WICGifApplicationExtensionApplication = &h1
   WICGifApplicationExtensionData = &h2
   WICGifApplicationExtensionProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICGifCommentExtensionProperties AS LONG
enum
   WICGifCommentExtensionText = &h1
   WICGifCommentExtensionProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICJpegCommentProperties AS LONG
enum
   WICJpegCommentText = &h1
   WICJpegCommentProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICJpegLuminanceProperties AS LONG
enum
   WICJpegLuminanceTable = &h1
   WICJpegLuminanceProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICJpegChrominanceProperties AS LONG
enum
   WICJpegChrominanceTable	= &h1
   WICJpegChrominanceProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WIC8BIMIptcProperties AS LONG
enum
   WIC8BIMIptcPString = 0
   WIC8BIMIptcEmbeddedIPTC	= &h1
   WIC8BIMIptcProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WIC8BIMResolutionInfoProperties AS LONG
enum
   WIC8BIMResolutionInfoPString = &h1
   WIC8BIMResolutionInfoHResolution	= &h2
   WIC8BIMResolutionInfoHResolutionUnit = &h3
   WIC8BIMResolutionInfoWidthUnit = &h4
   WIC8BIMResolutionInfoVResolution	= &h5
   WIC8BIMResolutionInfoVResolutionUnit = &h6
   WIC8BIMResolutionInfoHeightUnit = &h7
   WIC8BIMResolutionInfoProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WIC8BIMIptcDigestProperties AS LONG
enum
   WIC8BIMIptcDigestPString = &h1
   WIC8BIMIptcDigestIptcDigest = &h2
   WIC8BIMIptcDigestProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICPngGamaProperties AS LONG
enum
   WICPngGamaGamma = &h1
   WICPngGamaProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngBkgdProperties AS LONG
enum
   WICPngBkgdBackgroundColor = &h1
   WICPngBkgdProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngItxtProperties AS LONG
enum
   WICPngItxtKeyword	= &h1
   WICPngItxtCompressionFlag = &h2
   WICPngItxtLanguageTag = &h3
   WICPngItxtTranslatedKeyword = &h4
   WICPngItxtText	= &h5
   WICPngItxtProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngChrmProperties AS LONG
enum
   WICPngChrmWhitePointX = &h1
   WICPngChrmWhitePointY = &h2
   WICPngChrmRedX	= &h3
   WICPngChrmRedY	= &h4
   WICPngChrmGreenX = &h5
   WICPngChrmGreenY = &h6
   WICPngChrmBlueX = &h7
   WICPngChrmBlueY = &h8
   WICPngChrmProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngHistProperties AS LONG
enum
   WICPngHistFrequencies = &h1
   WICPngHistProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngIccpProperties AS LONG
enum
   WICPngIccpProfileName = &h1
   WICPngIccpProfileData = &h2
   WICPngIccpProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngSrgbProperties AS LONG
enum
   WICPngSrgbRenderingIntent = &h1
   WICPngSrgbProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngTimeProperties AS LONG
enum
   WICPngTimeYear	= &h1
   WICPngTimeMonth = &h2
   WICPngTimeDay = &h3
   WICPngTimeHour = &h4
   WICPngTimeMinute = &h5
   WICPngTimeSecond = &h6
   WICPngTimeProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICHeifProperties AS LONG
enum
   WICHeifOrientation = &h1
   WICHeifProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICHeifHdrProperties AS LONG
enum
   WICHeifHdrMaximumLuminanceLevel = &h1
   WICHeifHdrMaximumFrameAverageLuminanceLevel = &h2
   WICHeifHdrMinimumMasteringDisplayLuminanceLevel	= &h3
   WICHeifHdrMaximumMasteringDisplayLuminanceLevel	= &h4
   WICHeifHdrCustomVideoPrimaries = &h5
   WICHeifHdrProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICWebpAnimProperties AS LONG
enum
   WICWebpAnimLoopCount	= &h1
   WICWebpAnimProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICWebpAnmfProperties AS LONG
enum
   WICWebpAnmfFrameDuration = &h1
   WICWebpAnmfProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICJpegXLAnimProperties AS LONG
enum
   WICJpegXLAnimLoopCount = &h1
   WICJpegXLAnimFrameTicksPerSecondNumerator	= &h2
   WICJpegXLAnimFrameTicksPerSecondDenominator = &h3
   WICJpegXLAnimProperties_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICJpegXLAnimFrameProperties AS LONG
enum
   WICJpegXLAnimFrameDurationInTicks = &h1
   WICJpegXLAnimFrameName = &h2
   WICJpegXLAnimFrameProperties_FORCE_DWORD = &h7fffffff
end enum

TYPE WICSectionAccessLevel AS LONG
enum
   WICSectionAccessLevelRead = &h1
   WICSectionAccessLevelReadWrite = &h3
   WICSectionAccessLevel_FORCE_DWORD = &h7fffffff
end enum

TYPE WICPixelFormatNumericRepresentation AS LONG
enum
   WICPixelFormatNumericRepresentationUnspecified = 0
   WICPixelFormatNumericRepresentationIndexed = &h1
   WICPixelFormatNumericRepresentationUnsignedInteger	= &h2
   WICPixelFormatNumericRepresentationSignedInteger = &h3
   WICPixelFormatNumericRepresentationFixed = &h4
   WICPixelFormatNumericRepresentationFloat = &h5
   WICPixelFormatNumericRepresentation_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPlanarOptions AS LONG
enum
   WICPlanarOptionsDefault	= 0
   WICPlanarOptionsPreserveSubsampling	= &h1
   WICPLANAROPTIONS_FORCE_DWORD = &h7fffffff
end enum

TYPE WICJpegIndexingOptions AS LONG
enum
   WICJpegIndexingOptionsGenerateOnDemand	= 0
   WICJpegIndexingOptionsGenerateOnLoad = &h1
   WICJpegIndexingOptions_FORCE_DWORD = &h7fffffff
end enum

TYPE WICJpegTransferMatrix AS LONG
enum
   WICJpegTransferMatrixIdentity	= 0
   WICJpegTransferMatrixBT601	= &h1
   WICJpegTransferMatrix_FORCE_DWORD = &h7fffffff
end enum

TYPE WICJpegScanType AS LONG
enum
   WICJpegScanTypeInterleaved	= 0
   WICJpegScanTypePlanarComponents = &h1
   WICJpegScanTypeProgressive	= &h2
   WICJpegScanType_FORCE_DWORD = &h7fffffff
end enum

type WICImageParameters
   AS D2D1_PIXEL_FORMAT PixelFormat
   AS FLOAT DpiX
   AS FLOAT DpiY
   AS FLOAT Top
   AS FLOAT Left
   AS UINT32 PixelWidth
   AS UINT32 PixelHeight
end type

type WICBitmapPlaneDescription
   AS WICPixelFormatGUID Format
   AS UINT Width
   AS UINT Height
end type

type WICBitmapPlane
   AS WICPixelFormatGUID Format
   AS BYTE PTR pbBuffer
   AS UINT cbStride
   AS UINT cbBufferSize
end type

type WICJpegFrameHeader
   AS UINT Width
   AS UINT Height
   AS WICJpegTransferMatrix TransferMatrix
   AS WICJpegScanType ScanType
   AS UINT cComponents
   AS DWORD ComponentIdentifiers
   AS DWORD SampleFactors
   AS DWORD QuantizationTableIndices
end type

type WICJpegScanHeader
   AS UINT cComponents
   AS UINT RestartInterval
   AS DWORD ComponentSelectors
   AS DWORD HuffmanTableIndices
   AS BYTE StartSpectralSelection
   AS BYTE EndSpectralSelection
   AS BYTE SuccessiveApproximationHigh
   AS BYTE SuccessiveApproximationLow
end type

DIM SHARED IID_IWICPalette AS GUID = TYPE<GUID>(&h00000040, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

' ########################################################################################
' Interface name: IWICPalette
' IID: {00000040-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IWICPalette_INTERFACE_DEFINED__
#define __IWICPalette_INTERFACE_DEFINED__

TYPE IWICPalette_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION InitializePredefined (BYVAL ePaletteType AS WICBitmapPaletteType, BYVAL fAddTransparentColor AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeCustom (BYREF colors AS WICColor, BYVAL cCount AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromBitmap (BYVAL pISurface AS IWICBitmapSource PTR, BYVAL cCount AS UINT, BYVAL fAddTransparentColor AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromPalette (BYVAL pIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetType (BYREF pePaletteType AS WICBitmapPaletteType) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorCount (BYREF cCount AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColors (BYVAL cCount AS UINT, BYREF Colors AS WICColor, BYREF cActualColors AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsBlackWhite (BYREF fIsBlackWhite AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsGrayscale (BYREF fIsGrayscale AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasAlpha (BYREF fHasAlpha AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapSource
' IID: {00000120-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapSource AS GUID = (&h00000120, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICBitmapSource_INTERFACE_DEFINED__
#define __IWICBitmapSource_INTERFACE_DEFINED__

TYPE IWICBitmapSource_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetSize (BYREF uiWidth AS UINT, BYREF uiHeight AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPixelFormat (BYREF PixelFormat AS WICPixelFormatGUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetResolution (BYREF DpiX AS DOUBLE, BYREF DpiY AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyPalette (BYVAL pIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyPixels (BYREF rc AS WICRect, BYVAL cbStride AS UINT, BYVAL cbBufferSize AS UINT, BYVAL pbBuffer AS BYTE PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICFormatConverter
' IID: {00000301-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IWICBitmapSource
' ########################################################################################

DIM SHARED IID_IWICFormatConverter AS GUID = (&h00000301, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICFormatConverter_INTERFACE_DEFINED__
#define __IWICFormatConverter_INTERFACE_DEFINED__

TYPE IWICFormatConverter_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pISource AS IWICBitmapSource PTR, BYREF dstFormat AS WICPixelFormatGUID, _
      BYVAL dither AS WICBitmapDitherType, BYVAL pIPalette AS IWICPalette PTR, BYVAL alphaThresholdPercent AS DOUBLE, BYVAL paletteTranslate AS WICBitmapPaletteType) AS HRESULT
   DECLARE ABSTRACT FUNCTION CanConvert (BYREF srcPixelFormat AS WICPixelFormatGUID, BYREF dstPixelFormat AS WICPixelFormatGUID, BYREF fCanConvert AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICPlanarFormatConverter
' IID: {BEBEE9CB-83B0-4DCC-8132-B0AAA55EAC96}
' Inherited interface = IWICBitmapSource
' ########################################################################################

DIM SHARED IID_IWICPlanarFormatConverter AS GUID = (&hBEBEE9CB, &h83B0, &h4DCC, {&h81, &h32, &hB0, &hAA, &hA5, &h5E, &hAC, &h96})

#ifndef __IWICPlanarFormatConverter_INTERFACE_DEFINED__
#define __IWICPlanarFormatConverter_INTERFACE_DEFINED__

TYPE IWICPlanarFormatConverter_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Initialize (BYREF ppPlanes AS IWICBitmapSource PTR, BYVAL cPlanes AS UINT, _
      BYREF dstFormat AS WICPixelFormatGUID, BYVAL dither AS WICBitmapDitherType, BYVAL pIPalette AS IWICPalette PTR, _
      BYVAL alphaThresholdPercent AS DOUBLE, BYVAL paletteTranslate AS WICBitmapPaletteType) AS HRESULT
   DECLARE ABSTRACT FUNCTION CanConvert (BYREF SrcPixelFormats AS const WICPixelFormatGUID, BYVAL cSrcPlanes AS UINT, _
      BYREF dstPixelFormat AS WICPixelFormatGUID, BYREF fCanConvert AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapScaler
' IID: {00000302-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IWICBitmapSource
' Number of methods = 1
' ########################################################################################

DIM SHARED IID_IWICBitmapScaler AS GUID = (&h00000302, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICBitmapScaler_INTERFACE_DEFINED__
#define __IWICBitmapScaler_INTERFACE_DEFINED__

TYPE IWICBitmapScaler_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pISource AS IWICBitmapSource PTR, BYVAL uiWidth AS UINT, BYVAL uiHeight AS UINT, BYVAL mode AS WICBitmapInterpolationMode) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapClipper
' IID: {E4FBCF03-223D-4E81-9333-D635556DD1B5}
' Inherited interface = IWICBitmapSource
' Number of methods = 1
' ########################################################################################

DIM SHARED IID_IWICBitmapClipper AS GUID = (&hE4FBCF03, &h223D, &h4E81, {&h93, &h33, &hD6, &h35, &h55, &h6D, &hD1, &hB5})

#ifndef __IWICBitmapClipper_INTERFACE_DEFINED__
#define __IWICBitmapClipper_INTERFACE_DEFINED__

TYPE IWICBitmapClipper_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pISource AS IWICBitmapSource PTR, BYREF rc AS const WICRect) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapFlipRotator
' IID: {5009834F-2D6A-41CE-9E1B-17C5AFF7A782}
' Inherited interface = IWICBitmapSource
' ########################################################################################

DIM SHARED IID_IWICBitmapFlipRotator AS GUID = (&h5009834F, &h2D6A, &h41CE, {&h9E, &h1B, &h17, &hC5, &hAF, &hF7, &hA7, &h82})

#ifndef __IWICBitmapFlipRotator_INTERFACE_DEFINED__
#define __IWICBitmapFlipRotator_INTERFACE_DEFINED__

TYPE IWICBitmapFlipRotator_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pISource AS IWICBitmapSource PTR, BYVAL options AS WICBitmapTransformOptions) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapLock
' IID: {00000123-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapLock AS GUID = (&h00000123, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICBitmapLock_INTERFACE_DEFINED__
#define __IWICBitmapLock_INTERFACE_DEFINED__

TYPE IWICBitmapLock_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetSize (BYREF uiWidth AS UINT, BYREF uiHeight AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetStride (BYREF cbStride AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDataPointer (BYREF cbBufferSize AS UINT, BYREF pbData AS WICInProcPointer) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPixelFormat (BYREF pPixelFormat AS WICPixelFormatGUID) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmap
' IID: {00000121-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IWICBitmapSource
' ########################################################################################

DIM SHARED IID_IWICBitmap AS GUID = TYPE<GUID>(&h00000121, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICBitmap_INTERFACE_DEFINED__
#define __IWICBitmap_INTERFACE_DEFINED__

TYPE IWICBitmap_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Lock (BYREF rcLock AS WICRect, BYVAL flags AS DWORD, BYREF pILock AS IWICBitmapLock) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPalette (BYVAL pIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetResolution (BYVAL dpiX AS DOUBLE, BYVAL dpiY AS DOUBLE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICColorContext
' IID: {3C613A02-34B2-44EA-9A7C-45AEA9C6FD6D}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef IID_IWICColorContext
DIM SHARED IID_IWICColorContext AS GUID = (&h3C613A02, &h34B2, &h44EA, {&h9A, &h7C, &h45, &hAE, &hA9, &hC6, &hFD, &h6D})
#endif

#ifndef __IWICColorContext_INTERFACE_DEFINED__
#define __IWICColorContext_INTERFACE_DEFINED__

TYPE IWICColorContext_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION InitializeFromFilename (BYREF wszFilename AS WSTRING) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromMemory (BYVAL pbBuffer AS BYTE PTR, BYVAL cbBufferSize AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromExifColorSpace (BYVAL value AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetType (BYREF type AS WICColorContextType) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetProfileBytes (BYVAL cbBuffer AS UINT, BYVAL pbBuffer AS BYTE PTR, BYREF cbActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetExifColorSpace (BYREF Value AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICColorTransform
' IID: {B66F034F-D0E2-40AB-B436-6DE39E321A94}
' Inherited interface = IWICBitmapSource
' ########################################################################################

DIM SHARED IID_IWICColorTransform AS GUID = (&hB66F034F, &hD0E2, &h40AB, {&hB4, &h36, &h6D, &hE3, &h9E, &h32, &h1A, &h94})

#ifndef __IWICColorTransform_INTERFACE_DEFINED__
#define __IWICColorTransform_INTERFACE_DEFINED__

TYPE IWICColorTransform_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pIBitmapSource AS IWICBitmapSource PTR, BYVAL pIContextSource AS IWICColorContext PTR, _
      BYVAL pIContextDest AS IWICColorContext PTR, BYREF pixelFmtDest AS WICPixelFormatGUID) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICFastMetadataEncoder
' IID: {B84E2C09-78C9-4AC4-8BD3-524AE1663A2F}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICFastMetadataEncoder AS GUID = (&hB84E2C09, &h78C9, &h4AC4, {&h8B, &hD3, &h52, &h4A, &hE1, &h66, &h3A, &h2F})

#ifndef __IWICFastMetadataEncoder_INTERFACE_DEFINED__
#define __IWICFastMetadataEncoder_INTERFACE_DEFINED__

TYPE IWICFastMetadataEncoder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Commit () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetadataQueryWriter (BYREF ppIMetadataQueryWriter AS IWICMetadataQueryWriter PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICStream
' IID: {135FF860-22B7-4DDF-B0F6-218F4F299A43}
' Inherited interface = IStream
' ########################################################################################

DIM SHARED IID_IWICStream AS GUID = (&h135FF860, &h22B7, &h4DDF, {&hB0, &hF6, &h21, &h8F, &h4F, &h29, &h9A, &h43})

#ifndef __Afx_IWICStream_INTERFACE_DEFINED__
#define __Afx_IWICStream_INTERFACE_DEFINED__

TYPE IWICStream_ EXTENDS Afx_IStream
   DECLARE ABSTRACT FUNCTION InitializeFromIStream (BYVAL pIStream AS IStream PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromFilename (BYREF wzFilename AS WSTRING, BYVAL dwDesiredAccess AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromMemory (BYVAL pbBuffer AS WICInProcPointer, BYVAL cbBufferSize AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION InitializeFromIStreamRegion (BYVAL pIStream AS IStream PTR, BYVAL ulOffset AS LARGE_INTEGER, BYVAL ulMaxSize AS LARGE_INTEGER) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICEnumMetadataItem
' IID: {DC2BB46D-3F07-481E-8625-220C4AEDBB33}
' Inherited interface = IUnknown
' Number of methods = 4
' ########################################################################################

DIM SHARED IID_IWICEnumMetadataItem AS GUID = (&hDC2BB46D, &h3F07, &h481E, {&h86, &h25, &h22, &h0C, &h4A, &hED, &hBB, &h33})

#ifndef __IWICEnumMetadataItem_INTERFACE_DEFINED__
#define __IWICEnumMetadataItem_INTERFACE_DEFINED__

TYPE IWICEnumMetadataItem_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Next_ (BYVAL ULONG AS LONG, BYREF rgeltSchema AS PROPVARIANT, BYREF rgeltId AS PROPVARIANT, BYREF rgeltValue AS PROPVARIANT, BYREF celtFetched AS ULONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION Skip (BYVAL celt AS ULONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION Reset () AS HRESULT
   DECLARE ABSTRACT FUNCTION Clone (BYREF ppIEnumMetadataItem AS IWICEnumMetadataItem PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICMetadataQueryReader
' IID: {30989668-E1C9-4597-B395-458EEDB808DF}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICMetadataQueryReader AS GUID = (&h30989668, &hE1C9, &h4597, {&hB3, &h95, &h45, &h8E, &hED, &hB8, &h08, &hDF})

#ifndef __IWICMetadataQueryReader_INTERFACE_DEFINED__
#define __IWICMetadataQueryReader_INTERFACE_DEFINED__

TYPE IWICMetadataQueryReader_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetContainerFormat (BYREF guidContainerFormat AS GUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocation (BYVAL cchMaxLength AS UINT, BYVAL wzNamespace AS WSTRING PTR, BYVAL cchActualLength AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetadataByName (BYVAL wzName AS LPCWSTR, BYREF pvarValue AS PROPVARIANT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEnumerator (BYREF ppIEnumString AS IEnumString PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICMetadataQueryWriter
' IID: {A721791A-0DEF-4D06-BD91-2118BF1DB10B}
' Inherited interface = IWICMetadataQueryReader
' ########################################################################################

DIM SHARED IID_IWICMetadataQueryWriter AS GUID = (&hA721791A, &h0DEF, &h4D06, {&hBD, &h91, &h21, &h18, &hBF, &h1D, &hB1, &h0B})

#ifndef __IWICMetadataQueryWriter_INTERFACE_DEFINED__
#define __IWICMetadataQueryWriter_INTERFACE_DEFINED__

TYPE IWICMetadataQueryWriter_ EXTENDS IWICMetadataQueryReader
   DECLARE ABSTRACT FUNCTION SetMetadataByName (BYREF wszName AS WSTRING, BYREF pvarValue AS PROPVARIANT) AS HRESULT
   DECLARE ABSTRACT FUNCTION RemoveMetadataByName (BYREF wszName AS WSTRING) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapEncoder
' IID: {00000103-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapEncoder AS GUID = (&h00000103, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICBitmapEncoder_INTERFACE_DEFINED__
#define __IWICBitmapEncoder_INTERFACE_DEFINED__

TYPE IWICBitmapEncoder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pIStream AS IStream PTR, BYVAL cacheOption AS WICBitmapEncoderCacheOption) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetContainerFormat (BYREF guidContainerFormat AS GUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEncoderInfo (BYREF ppIEncoderInfo AS IWICBitmapEncoderInfo PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetColorContexts (BYVAL cCount AS UINT, BYREF ppIColorContext AS IWICColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPalette (BYVAL pIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetThumbnail (BYVAL pIThumbnail AS IWICBitmapSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPreview (BYVAL pIPreview AS IWICBitmapSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateNewFrame (BYREF ppIFrameEncode AS IWICBitmapFrameEncode PTR, BYREF ppIEncoderOptions AS IPropertyBag2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Commit () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetadataQueryWriter (BYREF ppIMetadataQueryWriter AS IWICMetadataQueryWriter PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapFrameEncode
' IID: {00000105-A8F2-4877-BA0A-FD2B6645FB94}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapFrameEncode AS GUID = (&h00000105, &hA8F2, &h4877, {&hBA, &h0A, &hFD, &h2B, &h66, &h45, &hFB, &h94})

#ifndef __IWICBitmapFrameEncode_INTERFACE_DEFINED__
#define __IWICBitmapFrameEncode_INTERFACE_DEFINED__

TYPE IWICBitmapFrameEncode_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pIEncoderOptions AS IPropertyBag2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSize (BYVAL uiWidth AS UINT, BYVAL uiHeight AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetResolution (BYVAL dpiX AS DOUBLE, BYVAL dpiY AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPixelFormat (BYREF PixelFormat AS WICPixelFormatGUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetColorContexts (BYVAL cCount AS UINT, BYREF ppIColorContext AS IWICColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPalette (BYVAL pIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetThumbnail (BYVAL pIThumbnail AS IWICBitmapSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION WritePixels (BYVAL lineCount AS UINT, BYVAL cbStride AS UINT, BYVAL cbBufferSize AS UINT, BYVAL pbPixels AS BYTE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION WriteSource (BYVAL pIBitmapSource AS IWICBitmapSource PTR, BYREF rc AS WICRect) AS HRESULT
   DECLARE ABSTRACT FUNCTION Commit () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetadataQueryWriter (BYREF ppIMetadataQueryWriter AS IWICMetadataQueryWriter PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################
   
' ########################################################################################
' Interface name: IWICPlanarBitmapFrameEncode
' IID: {F928B7B8-2221-40C1-B72E-7E82F1974D1A}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICPlanarBitmapFrameEncode AS GUID = (&hF928B7B8, &h2221, &h40C1, {&hB7, &h2E, &h7E, &h82, &hF1, &h97, &h4D, &h1A})

#ifndef __IWICPlanarBitmapFrameEncode_INTERFACE_DEFINED__
#define __IWICPlanarBitmapFrameEncode_INTERFACE_DEFINED__

TYPE IWICPlanarBitmapFrameEncode_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION WritePixels (BYVAL lineCount AS LONG, BYVAL pPlanes AS WICBitmapPlane PTR, BYVAL cPlanes AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION WriteSource (BYREF ppPlanes AS IWICBitmapSource PTR, BYVAL cPlanes AS UINT, BYREF rcSource AS WICRect) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICImageEncoder
' IID: {04C75BF8-3CE1-473B-ACC5-3CC4F5E94999}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICImageEncoder AS GUID = (&h04C75BF8, &h3CE1, &h473B, {&hAC, &hC5, &h3C, &hC4, &hF5, &hE9, &h49, &h99})

#ifndef __IWICImageEncoder_INTERFACE_DEFINED__
#define __IWICImageEncoder_INTERFACE_DEFINED__

TYPE Afx_IWICImageEncoder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION WriteFrame (BYVAL pImage AS ID2D1Image PTR, BYVAL pFrameEncode AS IWICBitmapFrameEncode PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION WriteFrameThumbnail (BYVAL pImage AS ID2D1Image PTR, BYVAL pFrameEncode AS IWICBitmapFrameEncode PTR, BYVAL pImageParameters AS WICImageParameters PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION WriteThumbnail (BYVAL pImage AS ID2D1Image PTR, BYVAL pEncoder AS IWICBitmapEncoder PTR, BYVAL pImageParameters AS WICImageParameters PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapDecoder
' IID: {9EDDE9E7-8DEE-47EA-99DF-E6FAF2ED44BF}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapDecoder AS GUID = (&h9EDDE9E7, &h8DEE, &h47EA, {&h99, &hDF, &hE6, &hFA, &hF2, &hED, &h44, &hBF})

#ifndef __IWICBitmapDecoder_INTERFACE_DEFINED__
#define __IWICBitmapDecoder_INTERFACE_DEFINED__

TYPE IWICBitmapDecoder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION QueryCapability (BYVAL pIStream AS IStream PTR, BYREF dwCapability AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION Initialize (BYVAL pIStream AS IStream PTR, BYVAL cacheOptions AS WICDecodeOptions) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetContainerFormat (BYREF guidContainerFormat AS GUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDecoderInfo (BYREF ppIDecoderInfo AS IWICBitmapDecoderInfo PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyPalette (BYVAL pIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetadataQueryReader (BYREF ppIMetadataQueryReader AS IWICMetadataQueryReader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPreview (BYREF ppIBitmapSource AS IWICBitmapSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorContexts (BYVAL cCount AS UINT, BYREF ppIColorContexts AS IWICColorContext PTR, BYREF cActualCount AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetThumbnail (BYREF ppIThumbnail AS IWICBitmapSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameCount (BYREF Count AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrame (BYVAL index AS UINT, BYREF ppIBitmapFrame AS IWICBitmapFrameDecode PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapSourceTransform
' IID: {3B16811B-6A43-4EC9-B713-3D5A0C13B940}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapSourceTransform AS GUID = (&h3B16811B, &h6A43, &h4EC9, {&hB7, &h13, &h3D, &h5A, &h0C, &h13, &hB9, &h40})

#ifndef __IWICBitmapSourceTransform_INTERFACE_DEFINED__
#define __IWICBitmapSourceTransform_INTERFACE_DEFINED__

TYPE IWICBitmapSourceTransform_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CopyPixels (BYREF rc AS WICRect, BYVAL uiWidth AS UINT, BYVAL uiHeight AS UINT, _
      BYREF guidDstFormat AS WICPixelFormatGUID, BYVAL dstTransform AS WICBitmapTransformOptions, _
      BYVAL nStride AS UINT, BYVAL cbBufferSize AS UINT, BYVAL pbBuffer AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetClosestSize (BYVAL puiWidth AS UINT PTR, BYVAL puiHeight AS UINT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetClosestPixelFormat (BYREF guidDstFormat AS WICPixelFormatGUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION DoesSupportTransform (BYVAL dstTransform AS WICBitmapTransformOptions, BYREF fIsSupported AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapSourceTransform2
' IID: {C3373FDF-6D39-4E5F-8E79-BF40C0B7ED77}
' Inherited interface = IWICBitmapSourceTransform
' ########################################################################################

DIM SHARED IID_IWICBitmapSourceTransform2 AS GUID = (&hC3373FDF, &h6D39, &h4E5F, {&h8E, &h79, &hBF, &h40, &hC0, &hB7, &hED, &h77})

#ifndef __IWICBitmapSourceTransform2_INTERFACE_DEFINED__
#define __IWICBitmapSourceTransform2_INTERFACE_DEFINED__

TYPE IWICBitmapSourceTransform2_ EXTENDS IWICBitmapSourceTransform
   DECLARE ABSTRACT FUNCTION GetColorContextsForPixelFormat (BYREF pPixelFormat AS WICPixelFormatGUID, BYVAL cCount AS UINT, _
      BYREF ppIColorContexts AS IWICColorContext PTR, BYREF cActualCount AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICPlanarBitmapSourceTransform
' IID: {3AFF9CCE-BE95-4303-B927-E7D16FF4A613}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICPlanarBitmapSourceTransform AS GUID = (&h3AFF9CCE, &hBE95, &h4303, {&hB9, &h27, &hE7, &hD1, &h6F, &hF4, &hA6, &h13})

#ifndef __IWICPlanarBitmapSourceTransform_INTERFACE_DEFINED__
#define __IWICPlanarBitmapSourceTransform_INTERFACE_DEFINED__

TYPE IWICPlanarBitmapSourceTransform_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION DoesSupportTransform (BYREF uiWidth AS UINT, BYREF uiHeight AS UINT, _
      BYVAL dstTransform AS WICBitmapTransformOptions, BYVAL dstPlanarOptions AS WICPlanarOptions, _
      BYVAL guidDstFormats AS const WICPixelFormatGUID, BYVAL pPlaneDescriptions AS WICBitmapPlaneDescription PTR, _
      BYVAL cPlanes AS UINT, BYREF fIsSupported AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyPixels (BYREF rcSource AS const WICRect, BYVAL uiWidth AS UINT, BYVAL uiHeight AS UINT, _
      BYVAL dstTransform AS WICBitmapTransformOptions, BYVAL dstPlanarOptions AS WICPlanarOptions, _
      BYVAL pDstPlanes AS WICBitmapPlane PTR, BYVAL cPlanes AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapFrameDecode
' IID: {3B16811B-6A43-4EC9-A813-3D930C13B940}
' Inherited interface = IWICBitmapSource
' ########################################################################################

DIM SHARED IID_IWICBitmapFrameDecode AS GUID = (&h3B16811B, &h6A43, &h4EC9, {&hA8, &h13, &h3D, &h93, &h0C, &h13, &hB9, &h40})

#ifndef __IWICBitmapFrameDecode_INTERFACE_DEFINED__
#define __IWICBitmapFrameDecode_INTERFACE_DEFINED__

TYPE IWICBitmapFrameDecode_ EXTENDS IWICBitmapSource
   DECLARE ABSTRACT FUNCTION GetMetadataQueryReader (BYREF ppIMetadataQueryReader AS IWICMetadataQueryReader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorContexts (BYVAL cCount AS UINT, BYREF ppIColorContexts AS IWICColorContext PTR, BYREF cActualCount AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetThumbnail (BYREF ppIThumbnail AS IWICBitmapSource PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICProgressiveLevelControl
' IID: {DAAC296F-7AA5-4DBF-8D15-225C5976F891}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICProgressiveLevelControl AS GUID = (&hDAAC296F, &h7AA5, &h4DBF, {&h8D, &h15, &h22, &h5C, &h59, &h76, &hF8, &h91})

#ifndef __IWICProgressiveLevelControl_INTERFACE_DEFINED__
#define __IWICProgressiveLevelControl_INTERFACE_DEFINED__

TYPE IWICProgressiveLevelControl_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetLevelCount (BYREF cLevels AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCurrentLevel (BYREF nLevel AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetCurrentLevel (BYVAL nLevel AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICDisplayAdaptationControl
' IID: {DE9D91D2-70B4-4F41-836C-25FCD39626D3}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICDisplayAdaptationControl AS GUID = (&hDE9D91D2, &h70B4, &h4F41, {&h83, &h6C, &h25, &hFC, &hD3, &h96, &h26, &hD3})

#ifndef __IWICDisplayAdaptationControl_INTERFACE_DEFINED__
#define __IWICDisplayAdaptationControl_INTERFACE_DEFINED__

TYPE Afx_IWICDisplayAdaptationControl_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION DoesSupportChangingMaxLuminance (BYREF guidDstFormat AS WICPixelFormatGUID, BYREF fIsSupported AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetDisplayMaxLuminance (BYVAL fLuminanceInNits AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDisplayMaxLuminance (BYREF fLuminanceInNits AS FLOAT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICProgressCallback
' IID: {4776F9CD-9517-45FA-BF24-E89C5EC5C60C}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICProgressCallback AS GUID = (&h4776F9CD, &h9517, &h45FA, {&hBF, &h24, &hE8, &h9C, &h5E, &hC5, &hC6, &h0C})

#ifndef __IWICProgressCallback_INTERFACE_DEFINED__
#define __IWICProgressCallback_INTERFACE_DEFINED__

TYPE IWICProgressCallback_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Notify (BYVAL uFrameNum AS ULONG, BYVAL operation AS WICProgressOperation, BYVAL dblProgress AS DOUBLE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapCodecProgressNotification
' IID: {64C1024E-C3CF-4462-8078-88C2B11C46D9}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICBitmapCodecProgressNotification AS GUID = (&h64C1024E, &hC3CF, &h4462, {&h80, &h78, &h88, &hC2, &hB1, &h1C, &h46, &hD9})

#ifndef __IWICBitmapCodecProgressNotification_INTERFACE_DEFINED__
#define __IWICBitmapCodecProgressNotification_INTERFACE_DEFINED__

DECLARE FUNCTION PFNProgressNotification (BYVAL pvData AS LPVOID, BYVAL uFrameNum AS ULONG, BYVAL operation AS WICProgressOperation, BYVAL dblProgress AS DOUBLE) AS HRESULT

TYPE IWICBitmapCodecProgressNotification_ EXTENDS Afx_IUnknown
'   DECLARE ABSTRACT FUNCTION RegisterProgressNotification (BYVAL pfnProgressNotification AS PFNProgressNotification, _
'      BYVAL pvData AS LPVOID, BYVAL dwProgressFlags AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterProgressNotification (BYVAL pfnProgressNotification AS ANY PTR, _
      BYVAL pvData AS LPVOID, BYVAL dwProgressFlags AS DWORD) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICComponentInfo
' IID: {23BC3F0A-698B-4357-886B-F24D50671334}
' Inherited interface = IUnknown
' Number of methods = 8
' ########################################################################################

DIM SHARED IID_IWICComponentInfo AS GUID = (&h23BC3F0A, &h698B, &h4357, {&h88, &h6B, &hF2, &h4D, &h50, &h67, &h13, &h34})

#ifndef __IWICComponentInfo_INTERFACE_DEFINED__
#define __IWICComponentInfo_INTERFACE_DEFINED__

TYPE IWICComponentInfo_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetComponentType (BYVAL pType AS WICComponentType PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCLSID (BYREF clsid AS CLSID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSigningStatus (BYREF Status AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetAuthor (BYVAL cchAuthor AS UINT, BYVAL wzAuthhor AS WSTRING PTR, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetVendorGUID (BYREF guidVendor AS GUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetVersion (BYVAL cchVersion AS UINT, BYVAL wzVersion AS WSTRING PTR, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSpecVersion (BYVAL cchSpecVersion AS UINT, BYVAL wzSpecVersion AS WSTRING PTR, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFriendlyName (BYVAL cchFriendlyName AS UINT, BYREF wzFriendlyName AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICFormatConverterInfo
' IID: {9F34FB65-13F4-4F15-BC57-3726B5E53D9F}
' Inherited interface = IWICComponentInfo
' ########################################################################################

DIM SHARED IID_IWICFormatConverterInfo AS GUID = (&h9F34FB65, &h13F4, &h4F15, {&hBC, &h57, &h37, &h26, &hB5, &hE5, &h3D, &h9F})

#ifndef __IWICFormatConverterInfo_INTERFACE_DEFINED__
#define __IWICFormatConverterInfo_INTERFACE_DEFINED__

TYPE IWICFormatConverterInfo_ EXTENDS IWICComponentInfo
   DECLARE ABSTRACT FUNCTION GetPixelFormats (BYVAL cFormats AS UINT, BYREF pPixelFormatGUIDs AS WICPixelFormatGUID, BYREF cActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateInstance (BYREF ppIConverter AS IWICFormatConverter PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapCodecInfo
' IID: {E87A44C4-B76E-4C47-8B09-298EB12A2714}
' Inherited interface = IWICComponentInfo
' ########################################################################################

DIM SHARED IID_IWICBitmapCodecInfo AS GUID = (&hE87A44C4, &hB76E, &h4C47, {&h8B, &h09, &h29, &h8E, &hB1, &h2A, &h27, &h14})

#ifndef __IWICBitmapCodecInfo_INTERFACE_DEFINED__
#define __IWICBitmapCodecInfo_INTERFACE_DEFINED__

TYPE IWICBitmapCodecInfo_ EXTENDS IWICComponentInfo
   DECLARE ABSTRACT FUNCTION GetContainerFormat (BYREF guidContainerFormat AS GUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPixelFormats (BYVAL cFormats AS UINT, BYREF guidPixelFormats AS GUID, BYREF cActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorManagementVersion (BYVAL cchColorManagementVersion AS UINT, _
      BYREF wzColorManagementVersion AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDeviceManufacturer (BYVAL cchDeviceManufacturer AS UINT, BYREF wzDeviceManufacturer AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDeviceModels (BYVAL cchDeviceModels AS UINT, BYREF wszDeviceModels AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMimeTypes (BYVAL cchMimeTypes AS UINT, BYREF wszMimeTypes AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFileExtensions (BYVAL cchFileExtensions AS UINT, BYREF wszFileExtensions AS WSTRING, BYVAL cchActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION DoesSupportAnimation (BYREF fSupportAnimation AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION DoesSupportChromakey (BYREF fSupportChromakey AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION DoesSupportLossless (BYVAL fSupportLossless AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION DoesSupportMultiframe (BYREF fSupportMultiframe AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION MatchesMimeType (BYREF wszMimeType AS WSTRING, BYREF fMatches AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapEncoderInfo
' IID: {94C9B4EE-A09F-4F92-8A1E-4A9BCE7E76FB}
' Inherited interface = IWICBitmapCodecInfo
' ########################################################################################

DIM SHARED IID_IWICBitmapEncoderInfo AS GUID = (&h94C9B4EE, &hA09F, &h4F92, {&h8A, &h1E, &h4A, &h9B, &hCE, &h7E, &h76, &hFB})

#ifndef __IWICBitmapEncoderInfo_INTERFACE_DEFINED__
#define __IWICBitmapEncoderInfo_INTERFACE_DEFINED__

TYPE IWICBitmapEncoderInfo_ EXTENDS IWICBitmapCodecInfo
   DECLARE ABSTRACT FUNCTION CreateInstance (BYREF ppIBitmapEncoder AS IWICBitmapEncoder PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICBitmapDecoderInfo
' IID: {D8CD007F-D08F-4191-9BFC-236EA7F0E4B5}
' Inherited interface = IWICBitmapCodecInfo
' ########################################################################################

DIM SHARED IID_IWICBitmapDecoderInfo AS GUID = (&hD8CD007F, &hD08F, &h4191, {&h9B, &hFC, &h23, &h6E, &hA7, &hF0, &hE4, &hB5})

#ifndef __IWICBitmapDecoderInfo_INTERFACE_DEFINED__
#define __IWICBitmapDecoderInfo_INTERFACE_DEFINED__

TYPE IWICBitmapDecoderInfo_ EXTENDS IWICBitmapCodecInfo
   DECLARE ABSTRACT FUNCTION GetPatterns (BYVAL cbSizePatterns AS UINT, BYVAL pPatterns AS WICBitmapPattern PTR, _
      BYREF cPatterns AS UINT, BYREF cbPatternsActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION MatchesPattern (BYVAL pIStream AS IStream PTR, BYREF fMatches AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateInstance (BYREF ppIBitmapDecoder AS IWICBitmapDecoder PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICPixelFormatInfo
' IID: {E8EDA601-3D48-431A-AB44-69059BE88BBE}
' Inherited interface = IWICComponentInfo
' ########################################################################################

DIM SHARED IID_IWICPixelFormatInfo AS GUID = (&hE8EDA601, &h3D48, &h431A, {&hAB, &h44, &h69, &h05, &h9B, &hE8, &h8B, &hBE})

#ifndef __IWICPixelFormatInfo_INTERFACE_DEFINED__
#define __IWICPixelFormatInfo_INTERFACE_DEFINED__

TYPE IWICPixelFormatInfo_ EXTENDS IWICComponentInfo
   DECLARE ABSTRACT FUNCTION GetFormatGUID (BYREF Format AS GUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorContext (BYREF ppIColorContext AS IWICColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBitsPerPixel (BYREF uiBitsPerPixel AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetChannelCount (BYREF uiChannelCount AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetChannelMask (BYREF uiChannelIndex AS UINT, BYVAL cbMaskBuffer AS UINT, _
      BYVAL pbMaskBuffer AS BYTE PTR, BYREF cbActual AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICPixelFormatInfo2
' IID: {A9DB33A2-AF5F-43C7-B679-74F5984B5AA4}
' Inherited interface = IWICPixelFormatInfo
' ########################################################################################

DIM SHARED IID_IWICPixelFormatInfo2 AS GUID = (&hA9DB33A2, &hAF5F, &h43C7, {&hB6, &h79, &h74, &hF5, &h98, &h4B, &h5A, &hA4})

#ifndef __IWICPixelFormatInfo2_INTERFACE_DEFINED__
#define __IWICPixelFormatInfo2_INTERFACE_DEFINED__

TYPE IWICPixelFormatInfo2_ EXTENDS IWICPixelFormatInfo
   DECLARE ABSTRACT FUNCTION SupportsTransparency (BYREF fSupportsTransparency AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetNumericRepresentation (BYREF pNumericRepresentation AS WICPixelFormatNumericRepresentation) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICImagingFactory
' IID: {EC5EC8A9-C395-4314-9C77-54D7A935FF70}
' Inherited interface = IUnknown
' Number of methods = 25
' ########################################################################################

#ifndef IID_IWICImagingFactory
DIM SHARED IID_IWICImagingFactory AS GUID = (&hEC5EC8A9, &hC395, &h4314, {&h9C, &h77, &h54, &hD7, &hA9, &h35, &hFF, &h70})
#endif

#ifndef __Afx_IWICImagingFactory_INTERFACE_DEFINED__
#define __Afx_IWICImagingFactory_INTERFACE_DEFINED__

TYPE IWICImagingFactory_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CreateDecoderFromFilename (BYREF wszFilename AS WSTRING, BYREF guidVendor AS const GUID, _
      BYVAL dwDesiredAccess AS DWORD, BYVAL metadataOptions AS WICDecodeOptions, BYREF ppIDecoder AS IWICBitmapDecoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDecoderFromStream (BYVAL pIStream AS IStream PTR, BYREF guidVendor AS GUID, _
      BYVAL metadataOptions AS WICDecodeOptions, BYREF ppIDecoder AS IWICBitmapDecoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDecoderFromFileHandle (BYVAL hFile AS ULONG_PTR, BYREF guidVendor AS GUID, _
      BYVAL metadataOptions AS WICDecodeOptions, BYREF ppIDecoder AS IWICBitmapDecoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateComponentInfo (BYREF clsidComponent AS CLSID, BYREF ppIInfo AS IWICComponentInfo PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDecoder (BYREF guidContainerFormat AS GUID, BYREF guidVendor AS GUID, BYREF ppIDecoder AS IWICBitmapDecoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateEncoder (BYREF guidContainerFormat AS GUID, BYREF guidVendor AS const GUID, BYREF ppIEncoder AS IWICBitmapEncoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreatePalette (BYREF ppIPalette AS IWICPalette PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFormatConverter (BYREF ppIFormatConverter AS IWICFormatConverter PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapScaler (BYREF ppIBitmapScaler AS IWICBitmapScaler PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapClipper (BYREF ppIBitmapClipper AS IWICBitmapClipper PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFlipRotator (BYREF ppIBitmapFlipRotator AS IWICBitmapFlipRotator PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateStream (BYREF ppIWICStream AS IWICStream PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorContext (BYREF ppIWICColorContext AS IWICColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorTransformer (BYREF ppIWICColorTransform AS IWICColorTransform PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmap (BYVAL uiWidth AS UINT, BYVAL uiHeight AS UINT, BYREF PixelFormat AS WICPixelFormatGUID, _
      BYVAL option AS WICBitmapCreateCacheOption, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromSource (BYVAL pIBitmapSource AS IWICBitmapSource PTR, _
      BYVAL option AS WICBitmapCreateCacheOption, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromSourceRect (BYVAL pIBitmapSource AS IWICBitmapSource PTR, BYVAL x AS UINT, _
      BYVAL y AS UINT, BYVAL width AS UINT, BYVAL height AS UINT, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromMemory (BYVAL uiWidth AS UINT, BYVAL uiHeight AS UINT, _
      BYREF pixelFormat AS WICPixelFormatGUID, BYVAL cbStride AS UINT, BYVAL cbBufferSize AS UINT, _
      BYVAL pbBuffer AS BYTE PTR, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromHBITMAP (BYVAL hbitmap AS HBITMAP, BYVAL hPalette AS HPALETTE, _
      BYVAL options AS WICBitmapAlphaChannelOption, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromHICON (BYVAL hIcon AS HICON, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateComponentEnumerator (BYVAL componentTypes AS DWORD, BYVAL options AS DWORD, BYREF ppIEnumUnknown AS IEnumUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFastMetadataEncoderFromDecoder (BYVAL pIDecoder AS IWICBitmapDecoder PTR, _
      BYREF ppIFastEncoder AS IWICFastMetadataEncoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFastMetadataEncoderFromFrameDecode (BYVAL pIFrameDecoder AS IWICBitmapFrameDecode PTR, _
      BYREF ppIFastEncoder AS IWICFastMetadataEncoder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateQueryWriter (BYREF guidMetadataFormat AS GUID, BYREF guidVendor AS const GUID, BYREF ppIQueryWriter AS IWICMetadataQueryWriter PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateQueryWriterFromReader (BYVAL pIQueryReader AS IWICMetadataQueryReader PTR, _
      BYREF guidVendor AS const GUID, BYREF ppIQueryWriter AS IWICMetadataQueryWriter PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICImagingFactory2
' IID: {7B816B45-1996-4476-B132-DE9E247C8AF0}
' Inherited interface = IWICImagingFactory
' ########################################################################################
'EXTERN_C const IID IID_IWICImagingFactory2
DIM SHARED IID_IWICImagingFactory2 AS GUID = TYPE<GUID>(&h7B816B45, &h1996, &h4476, {&hB1, &h32, &hDE, &h9E, &h24, &h7C, &hBA, &hF0})

#ifndef __IWICImagingFactory2_INTERFACE_DEFINED__
#define __IWICImagingFactory2_INTERFACE_DEFINED__

TYPE IWICImagingFactory2_ EXTENDS IWICImagingFactory
   DECLARE ABSTRACT FUNCTION CreateImageEncoder (BYVAL pD2DDevice AS ID2D1Device PTR, _
      BYREF ppWICImageEncoder AS IWICImageEncoder PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ========================================================================================
' Obtains a IWICBitmapSource in the desired pixel format from a given IWICBitmapSource.
' ========================================================================================
DECLARE FUNCTION WICConvertBitmapSource LIB "d2d1" ALIAS "WICConvertBitmapSource" (BYREF dstFormat AS WICPixelFormatGUID, _
   BYVAL pISrc AS IWICBitmapSource PTR, BYREF ppIDst AS IWICBitmapSource PTR) AS HRESULT
' ========================================================================================

' ========================================================================================
' Returns a IWICBitmapSource that is backed by the pixels of a Windows Graphics Device Interface (GDI) section handle.
' ========================================================================================
DECLARE FUNCTION WICCreateBitmapFromSection LIB "d2d1" ALIAS "WICCreateBitmapFromSection" (BYVAL width AS UINT, _
   BYVAL height AS UINT, BYREF pixelFormat AS WICPixelFormatGUID, BYVAL hSection AS HANDLE, BYVAL stride AS UINT, _
   BYVAL offset AS UINT, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
' ========================================================================================

' ========================================================================================
' Returns a IWICBitmapSource that is backed by the pixels of a Windows Graphics Device Interface (GDI) section handle.
' ========================================================================================
DECLARE FUNCTION WICCreateBitmapFromSectionEx LIB "d2d1" ALIAS "WICCreateBitmapFromSectionEx" (BYVAL width AS UINT, _
   BYVAL height AS UINT, BYREF pixelFormat AS WICPixelFormatGUID, BYVAL hSection AS HANDLE, BYVAL stride AS UINT, _
   BYVAL offset AS UINT, BYVAL desiredAccessLevel AS WICSectionAccessLevel, BYREF ppIBitmap AS IWICBitmap PTR) AS HRESULT
' ========================================================================================

' ========================================================================================
' Obtains the short name associated with a given GUID.
' ========================================================================================
DECLARE FUNCTION WICMapGuidToShortName LIB "d2d1" ALIAS "WICMapGuidToShortName" (BYREF guid AS GUID, _
   BYVAL cchName AS UINT, BYREF wszName AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
' ========================================================================================

' ========================================================================================
' Obtains the GUID associated with the given short name.
' ========================================================================================
DECLARE FUNCTION WICMapShortNameToGuid LIB "d2d1" ALIAS "WICMapShortNameToGuid" (BYREF wszName AS WSTRING, BYREF guid AS GUID) AS HRESULT
' ========================================================================================

' ========================================================================================
' Obtains the name associated with a given schema.
' ========================================================================================
DECLARE FUNCTION WICMapSchemaToName LIB "d2d1" ALIAS "WICMapSchemaToName" (BYREF guidMetadataFormat AS GUID, _
   BYREF wszSchema AS WSTRING, BYVAL cchName AS UINT, BYREF wszName AS WSTRING, BYREF cchActual AS UINT) AS HRESULT
' ========================================================================================

#define FACILITY_WINCODEC_ERR &h898
#define WINCODEC_ERR_BASE &h2000
#define MAKE_WINCODECHR(sev, code) MAKE_HRESULT(sev, FACILITY_WINCODEC_ERR, (WINCODEC_ERR_BASE + code))
#define MAKE_WINCODECHR_ERR(code) MAKE_WINCODECHR(1, code)

CONST WINCODEC_ERR_GENERIC_ERROR    = E_FAIL
CONST WINCODEC_ERR_INVALIDPARAMETER = E_INVALIDARG
CONST WINCODEC_ERR_OUTOFMEMORY      = E_OUTOFMEMORY
CONST WINCODEC_ERR_NOTIMPLEMENTED   = E_NOTIMPL
CONST WINCODEC_ERR_ABORTED          = E_ABORT
CONST WINCODEC_ERR_ACCESSDENIED     = E_ACCESSDENIED
CONST WINCODEC_ERR_VALUEOVERFLOW    = &H80070216L  ' INTSAFE_E_ARITHMETIC_OVERFLOW

TYPE WICTiffCompressionOption AS LONG
enum
   WICTiffCompressionDontCare	= 0
   WICTiffCompressionNone = &h1
   WICTiffCompressionCCITT3 = &h2
   WICTiffCompressionCCITT4 = &h3
   WICTiffCompressionLZW = &h4
   WICTiffCompressionRLE = &h5
   WICTiffCompressionZIP = &h6
   WICTiffCompressionLZWHDifferencing = &h7
   WICTIFFCOMPRESSIONOPTION_FORCE_DWORD = &h7fffffff
end enum

TYPE WICJpegYCrCbSubsamplingOption AS LONG
enum
   WICJpegYCrCbSubsamplingDefault = 0
   WICJpegYCrCbSubsampling420	= &h1
   WICJpegYCrCbSubsampling422	= &h2
   WICJpegYCrCbSubsampling444	= &h3
   WICJpegYCrCbSubsampling440	= &h4
   WICJPEGYCRCBSUBSAMPLING_FORCE_DWORD	= &h7fffffff
end enum

TYPE WICPngFilterOption AS LONG
enum
   WICPngFilterUnspecified	= 0
   WICPngFilterNone = &h1
   WICPngFilterSub = &h2
   WICPngFilterUp	= &h3
   WICPngFilterAverage	= &h4
   WICPngFilterPaeth	= &h5
   WICPngFilterAdaptive	= &h6
   WICPNGFILTEROPTION_FORCE_DWORD = &h7fffffff
end enum

TYPE WICHeifCompressionOption AS LONG
enum
   WICHeifCompressionDontCare	= 0
   WICHeifCompressionNone = &h1
   WICHeifCompressionHEVC = &h2
   WICHeifCompressionAV1 = &h3
   WICHEIFCOMPRESSIONOPTION_FORCE_DWORD = &h7fffffff
end enum

TYPE WICNamedWhitePoint AS LONG
enum
   WICWhitePointDefault	= &h1
   WICWhitePointDaylight = &h2
   WICWhitePointCloudy = &h4
   WICWhitePointShade = &h8
   WICWhitePointTungsten = &h10
   WICWhitePointFluorescent = &h20
   WICWhitePointFlash = &h40
   WICWhitePointUnderwater	= &h80
   WICWhitePointCustom = &h100
   WICWhitePointAutoWhiteBalance	= &h200
   WICWhitePointAsShot = WICWhitePointDefault,
   WICNAMEDWHITEPOINT_FORCE_DWORD = &h7fffffff
end enum

TYPE WICRawCapabilities AS LONG
enum
   WICRawCapabilityNotSupported = 0
   WICRawCapabilityGetSupported = &h1
   WICRawCapabilityFullySupported = &h2
   WICRAWCAPABILITIES_FORCE_DWORD = &h7fffffff
end enum

TYPE WICRawRotationCapabilities AS LONG
enum
   WICRawRotationCapabilityNotSupported = 0
   WICRawRotationCapabilityGetSupported = &h1
   WICRawRotationCapabilityNinetyDegreesSupported = &h2
   WICRawRotationCapabilityFullySupported	= &h3
   WICRAWROTATIONCAPABILITIES_FORCE_DWORD	= &h7fffffff
end enum

type WICRawCapabilitiesInfo
   AS UINT cbSize
   AS UINT CodecMajorVersion
   AS UINT CodecMinorVersion
   AS WICRawCapabilities ExposureCompensationSupport
   AS WICRawCapabilities ContrastSupport
   AS WICRawCapabilities RGBWhitePointSupport
   AS WICRawCapabilities NamedWhitePointSupport
   AS UINT NamedWhitePointSupportMask
   AS WICRawCapabilities KelvinWhitePointSupport
   AS WICRawCapabilities GammaSupport
   AS WICRawCapabilities TintSupport
   AS WICRawCapabilities SaturationSupport
   AS WICRawCapabilities SharpnessSupport
   AS WICRawCapabilities NoiseReductionSupport
   AS WICRawCapabilities DestinationColorProfileSupport
   AS WICRawCapabilities ToneCurveSupport
   AS WICRawRotationCapabilities RotationSupport
   AS WICRawCapabilities RenderModeSupport
end type

TYPE WICRawParameterSet AS LONG
enum
   WICAsShotParameterSet = &h1
   WICUserAdjustedParameterSet = &h2
   WICAutoAdjustedParameterSet = &h3
   WICRAWPARAMETERSET_FORCE_DWORD = &h7fffffff
end enum

TYPE WICRawRenderMode AS LONG
enum
   WICRawRenderModeDraft = &h1
   WICRawRenderModeNormal = &h2
   WICRawRenderModeBestQuality = &h3
   WICRAWRENDERMODE_FORCE_DWORD = &h7fffffff
end enum

type WICRawToneCurvePoint
   AS double Input
   AS double Output
end type

type WICRawToneCurve
   AS UINT cPoints
   AS WICRawToneCurvePoint aPoints (0)
end type

CONST WICRawChangeNotification_ExposureCompensation    = &h00000001
CONST WICRawChangeNotification_NamedWhitePoint         = &h00000002
CONST WICRawChangeNotification_KelvinWhitePoint        = &h00000004
CONST WICRawChangeNotification_RGBWhitePoint           = &h00000008
CONST WICRawChangeNotification_Contrast                = &h00000010
CONST WICRawChangeNotification_Gamma                   = &h00000020
CONST WICRawChangeNotification_Sharpness               = &h00000040
CONST WICRawChangeNotification_Saturation              = &h00000080
CONST WICRawChangeNotification_Tint                    = &h00000100
CONST WICRawChangeNotification_NoiseReduction          = &h00000200
CONST WICRawChangeNotification_DestinationColorContext = &h00000400
CONST WICRawChangeNotification_ToneCurve               = &h00000800
CONST WICRawChangeNotification_Rotation                = &h00001000
CONST WICRawChangeNotification_RenderMode              = &h00002000

' ########################################################################################
' Interface name: IWICDevelopRawNotificationCallback
' IID: {95C75A6E-3E8C-4EC2-85A8-AEBCC551E59B}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICDevelopRawNotificationCallback AS GUID = (&h95C75A6E, &h3E8C, &h4EC2, {&h85, &hA8, &hAE, &hBC, &hC5, &h51, &hE5, &h9B})

#ifndef __IWICDevelopRawNotificationCallback_INTERFACE_DEFINED__
#define __IWICDevelopRawNotificationCallback_INTERFACE_DEFINED__

TYPE IWICDevelopRawNotificationCallback_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Notify (BYVAL NotificationMask AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICDevelopRaw
' IID: {FBEC5E44-F7BE-4B65-B7F8-C0C81FEF026D}
' Inherited interface = IWICBitmapFrameDecode
' Number of methods = 32
' ########################################################################################

DIM SHARED IID_IWICDevelopRaw AS GUID = (&hFBEC5E44, &hF7BE, &h4B65, {&hB7, &hF8, &hC0, &hC8, &h1F, &hEF, &h02, &h6D})

#ifndef __IWICDevelopRaw_INTERFACE_DEFINED__
#define __IWICDevelopRaw_INTERFACE_DEFINED__

TYPE IWICDevelopRaw_ EXTENDS IWICBitmapFrameDecode
   DECLARE ABSTRACT FUNCTION QueryRawCapabilitiesInfo (BYREF pInfo AS WICRawCapabilitiesInfo) AS HRESULT
   DECLARE ABSTRACT FUNCTION LoadParameterSet (BYVAL parameterSet AS WICRawParameterSet) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCurrentParameterSet (BYREF ppCurrentParameterSet AS IPropertyBag2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetExposureCompensation (BYVAL ev AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetExposureCompensation (BYREF ev AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetWhitePointRGB (BYVAL Red AS UINT, BYVAL Green AS UINT, BYVAL Blue AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetWhitePointRGB (BYREF Red AS UINT, BYREF Green AS UINT, BYVAL Blue AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetNamedWhitePoint (BYVAL whitePoint AS WICNamedWhitePoint) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetNamedWhitePoint (BYVAL pWhitePoint AS WICNamedWhitePoint PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetWhitePointKelvin (BYVAL WhitePointKelvin AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetWhitePointKelvin (BYREF whitePointKelvin AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetKelvinRangeInfo (BYREF minKelvinTemp AS UINT, BYREF maxKelvinTemp AS UINT, BYREF KelvinTempStepValue AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetContrast (BYVAL Contrast AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetContrast (BYREF Contrast AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetGamma (BYVAL Gamma AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGamma (BYREF pGamma AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSharpness (BYVAL Sharpness AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSharpness (BYREF Sharpness AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSaturation (BYVAL Saturation AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSaturation (BYREF Saturation AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTint (BYVAL Tint AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTint (BYREF Tint AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetNoiseReduction (BYVAL NoiseReduction AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetNoiseReduction (BYREF NoiseReduction AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetDestinationColorContext (BYVAL pColorContext AS IWICColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetToneCurve (BYVAL cbToneCurveSize AS UINT, BYVAL pToneCurve AS WICRawToneCurve PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetToneCurve (BYVAL cbToneCurveBufferSize AS UINT, BYREF pToneCurve AS WICRawToneCurve, _
      BYREF cbActualToneCurveBufferSize AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetRotation (BYVAL rotation AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRotation (BYREF Rotation AS DOUBLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetRenderMode (BYVAL RenderMode AS WICRawRenderMode) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRenderMode (BYREF RenderMode AS WICRawRenderMode) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetNotificationCallback (BYVAL pCallback AS IWICDevelopRawNotificationCallback PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


TYPE WICDdsDimension AS LONG
enum
   WICDdsTexture1D = 0
   WICDdsTexture2D = &h1
   WICDdsTexture3D = &h2
   WICDdsTextureCube	= &h3
   WICDDSTEXTURE_FORCE_DWORD = &h7fffffff
end enum

TYPE WICDdsAlphaMode AS LONG
enum
   WICDdsAlphaModeUnknown = 0
   WICDdsAlphaModeStraight	= &h1
   WICDdsAlphaModePremultiplied = &h2
   WICDdsAlphaModeOpaque = &h3
   WICDdsAlphaModeCustom = &h4
   WICDDSALPHAMODE_FORCE_DWORD = &h7fffffff
end enum

type WICDdsParameters
   AS UINT Width
   AS UINT Height
   AS UINT Depth
   AS UINT MipLevels
   AS UINT ArraySize
   AS DXGI_FORMAT DxgiFormat
   AS WICDdsDimension Dimension
   AS WICDdsAlphaMode AlphaMode
end type


' ########################################################################################
' Interface name: IWICDdsDecoder
' IID: {409CD537-8532-40CB-9774-E2FEB2DF4E9C}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICDdsDecoder AS GUID = (&h409CD537, &h8532, &h40CB, {&h97, &h74, &hE2, &hFE, &hB2, &hDF, &h4E, &h9C})

#ifndef __IWICDdsDecoder_INTERFACE_DEFINED__
#define __IWICDdsDecoder_INTERFACE_DEFINED__

TYPE IWICDdsDecoder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetParameters (BYREF pParameters AS WICDdsParameters) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrame (BYVAL arrayIndex AS UINT, BYVAL mipLevel AS UINT, _
      BYVAL sliceIndex AS UINT, BYREF ppIBitmapFrame AS IWICBitmapFrameDecode PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICDdsEncoder
' IID: {5CACDB4C-407E-41B3-B936-D0F010CD6732}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICDdsEncoder AS GUID = (&h5CACDB4C, &h407E, &h41B3, {&hB9, &h36, &hD0, &hF0, &h10, &hCD, &h67, &h32})

#ifndef __Afx_IWICDdsEncoder_INTERFACE_DEFINED__
#define __Afx_IWICDdsEncoder_INTERFACE_DEFINED__

TYPE Afx_IWICDdsEncoder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION SetParameters (BYREF parameters AS WICDdsParameters) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetParameters (BYREF parameters AS WICDdsParameters) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateNewFrame (BYREF ppIFrameEncode AS IWICBitmapFrameEncode PTR, _
      BYVAL pArrayIndex AS UINT PTR, BYVAL pMipLevel AS UINT PTR, BYVAL pSliceIndex AS UINT PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


type WICDdsFormatInfo
   AS DXGI_FORMAT DxgiFormat
   AS UINT BytesPerBlock
   AS UINT BlockWidth
   AS UINT BlockHeight
end type


' ########################################################################################
' Interface name: IWICDdsFrameDecode
' IID: {3D4C0C61-18A4-41E4-BD80-481A4FC9F464}
' Inherited interface = IUnknown
' Number of methods = 3
' ########################################################################################

DIM SHARED IID_IWICDdsFrameDecode AS GUID = (&h3D4C0C61, &h18A4, &h41E4, {&hBD, &h80, &h48, &h1A, &h4F, &hC9, &hF4, &h64})

#ifndef __IWICDdsFrameDecode_INTERFACE_DEFINED__
#define __IWICDdsFrameDecode_INTERFACE_DEFINED__

TYPE IWICDdsFrameDecode_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetSizeInBlocks (BYREF widthInBlocks AS UINT, BYREF heightInBlocks AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFormatInfo (BYREF formatInfo AS WICDdsFormatInfo) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyBlocks (BYREF rcBoundsInBlocks AS WICRect, BYVAL cbStride AS UINT, _
      BYVAL cbBufferSize AS UINT, BYVAL pbBuffer AS BYTE PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICJpegFrameDecode
' IID: {8939F66E-C46A-4C21-A9D1-98B327CE1679}
' Inherited interface = IUnknown
' ########################################################################################

DIM SHARED IID_IWICJpegFrameDecode AS GUID = (&h8939F66E, &hC46A, &h4C21, {&hA9, &hD1, &h98, &hB3, &h27, &hCE, &h16, &h79})

#ifndef __IWICJpegFrameDecode_INTERFACE_DEFINED__
#define __IWICJpegFrameDecode_INTERFACE_DEFINED__

TYPE IWICJpegFrameDecode_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION DoesSupportIndexing (BYREF fIndexingSupported AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetIndexing (BYVAL options AS WICJpegIndexingOptions, BYVAL horizontalIntervalSize AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION ClearIndexing () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetAcHuffmanTable (BYVAL scanIndex AS UINT, BYVAL tableIndex AS UINT, BYREF AcHuffmanTable AS DXGI_JPEG_AC_HUFFMAN_TABLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDcHuffmanTable (BYVAL scanIndex AS UINT, BYVAL tableIndex AS UINT, BYREF DcHuffmanTable AS DXGI_JPEG_DC_HUFFMAN_TABLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetQuantizationTable (BYVAL scanIndex AS UINT, BYVAL tableIndex AS UINT, BYREF QuantizationTable AS DXGI_JPEG_QUANTIZATION_TABLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameHeader (BYREF frameHeader AS WICJpegFrameHeader) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetScanHeader (BYVAL scanIndex AS UINT, BYREF scanHeader AS WICJpegScanHeader) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyScan (BYVAL scanIndex AS UINT, BYVAL scanOffset AS UINT, BYVAL cbScanData AS UINT, _
      BYVAL pbScanData AS BYTE PTR, BYREF cbScanDataActual AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyMinimalStream (BYVAL streamOffset AS UINT, BYVAL cbStreamData AS UINT, _
      BYVAL pbStreamData AS BYTE PTR, BYVAL cbStreamDataActual AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IWICJpegFrameEncode
' IID: {2F0C601F-D2C6-468C-ABFA-49495D983ED1}
' Inherited interface = IUnknown
' Number of methods = 4
' ########################################################################################

DIM SHARED IID_IWICJpegFrameEncode AS GUID = (&h2F0C601F, &hD2C6, &h468C, {&hAB, &hFA, &h49, &h49, &h5D, &h98, &h3E, &hD1})

#ifndef __IWICJpegFrameEncode_INTERFACE_DEFINED__
#define __IWICJpegFrameEncode_INTERFACE_DEFINED__

TYPE IWICJpegFrameEncode_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetAcHuffmanTable (BYVAL scanIndex AS UINT, BYVAL tableIndex AS UINT, BYREF AcHuffmanTable AS DXGI_JPEG_AC_HUFFMAN_TABLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDcHuffmanTable (BYVAL scanIndex AS UINT, BYVAL tableIndex AS UINT, BYREF DcHuffmanTable AS DXGI_JPEG_DC_HUFFMAN_TABLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetQuantizationTable (BYVAL scanIndex AS UINT, BYVAL tableIndex AS UINT, BYREF QuantizationTable AS DXGI_JPEG_QUANTIZATION_TABLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION WriteScan (BYVAL cbScanData AS UINT, BYVAL pbScanData AS BYTE PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################
