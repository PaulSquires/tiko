'//+--------------------------------------------------------------------------
'//  Copyright (c) Microsoft Corporation.  All rights reserved.
'//  Abstract:
'//     DirectX Typography Services public API definitions.
'//----------------------------------------------------------------------------

#pragma once

#include once "win/unknwn.bi"
#include once "win/winerror.bi"
#include once "AfxNova/AfxD2D1.bi"

#ifndef __Afx_IUnknown_INTERFACE_DEFINED__
#define __Afx_IUnknown_INTERFACE_DEFINED__
TYPE Afx_IUnknown AS Afx_IUnknown_
TYPE Afx_IUnknown_ EXTENDS OBJECT
	DECLARE ABSTRACT FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
	DECLARE ABSTRACT FUNCTION AddRef () AS ULONG
	DECLARE ABSTRACT FUNCTION Release () AS ULONG
END TYPE
TYPE LPUNKNOWN AS Afx_IUnknown PTR
#endif

DIM SHARED IID_IDWriteAsyncResult AS GUID = (&hCE25F8FD, &h863B, &h4D13, {&h96, &h51, &hC1, &hF8, &h8D, &hC7, &h3F, &hE2})
DIM SHARED IID_IDWriteBitmapRenderTarget AS GUID = (&h5E5A32A3, &h8DFF, &h4773, {&h9F, &hF6, &h06, &h96, &hEA, &hB7, &h72, &h67})
DIM SHARED IID_IDWriteBitmapRenderTarget1 AS GUID = (&h791E8298, &h3EF3, &h4230, {&h98, &h80, &hC9, &hBD, &hEC, &hC4, &h20, &h64})
DIM SHARED IID_IDWriteBitmapRenderTarget2 AS GUID = (&hC553A742, &hFC01, &h44DA, {&hA6, &h6E, &hB8, &hB9, &hED, &h6C, &h39, &h95})
DIM SHARED IID_IDWriteBitmapRenderTarget3 AS GUID = (&hAEEC37DB, &hC337, &h40F1, {&h8E, &h2A, &h9A, &h41, &hB1, &h67, &hB2, &h38})
DIM SHARED IID_IDWriteColorGlyphRunEnumerator AS GUID = (&hD31FBE17, &hF157, &h41A2, {&h8D, &h24, &hCB, &h77, &h9E, &h05, &h60, &hE8})
DIM SHARED IID_IDWriteColorGlyphRunEnumerator1 AS GUID = (&h7C5F86DA, &hC7A1, &h4F05, {&hB8, &hE1, &h55, &hA1, &h79, &hFE, &h5A, &h35})
DIM SHARED IID_IDWriteFactory AS GUID = (&hB859EE5A, &hD838, &h4B5B, {&hA2, &hE8, &h1A, &hDC, &h7D, &h93, &hDB, &h48})
DIM SHARED IID_IDWriteFactory1 AS GUID = (&h30572F99, &hDAC6, &h41DB, {&hA1, &h6E, &h04, &h86, &h30, &h7E, &h60, &h6A})
DIM SHARED IID_IDWriteFactory2 AS GUID = (&h0439FC60, &hCA44, &h4994, {&h8D, &hEE, &h3A, &h9A, &hF7, &hB7, &h32, &hEC})
DIM SHARED IID_IDWriteFactory3 AS GUID = (&h9A1B41C3, &hD3BB, &h466A, {&h87, &hFC, &hFE, &h67, &h55, &h6A, &h3B, &h65})
DIM SHARED IID_IDWriteFactory4 AS GUID = (&h4B0B5BD3, &h0797, &h4549, {&h8A, &hC5, &hFE, &h91, &h5C, &hC5, &h38, &h56})
DIM SHARED IID_IDWriteFactory5 AS GUID = (&h958DB99A, &hBE2A, &h4F09, {&hAF, &h7D, &h65, &h18, &h98, &h03, &hD1, &hD3})
DIM SHARED IID_IDWriteFactory6 AS GUID = (&hF3744D80, &h21F7, &h42EB, {&hB3, &h5D, &h99, &h5B, &hC7, &h2F, &hC2, &h23})
DIM SHARED IID_IDWriteFactory7 AS GUID = (&h35D0E0B3, &h9076, &h4D2E, {&hA0, &h16, &hA9, &h1B, &h56, &h8A, &h06, &hB4})
DIM SHARED IID_IDWriteFactory8 AS GUID = (&hEE0A7FB5, &hDEF4, &h4C23, {&hA4, &h54, &hC9, &hC7, &hDC, &h87, &h83, &h98})
DIM SHARED IID_IDWriteFont AS GUID = (&hACD16696, &h8C14, &h4F5D, {&h87, &h7E, &hFE, &h3F, &hC1, &hD3, &h27, &h37})
DIM SHARED IID_IDWriteFont1 AS GUID = (&hACD16696, &h8C14, &h4F5D, {&h87, &h7E, &hFE, &h3F, &hC1, &hD3, &h27, &h38})
DIM SHARED IID_IDWriteFont2 AS GUID = (&h29748ed6, &h8c9c, &h4a6a, {&hbe, &h0b, &hd9, &h12, &he8, &h53, &h89, &h44})
DIM SHARED IID_IDWriteFont3 AS GUID = (&h29748ED6, &h8C9C, &h4A6A, {&hBE, &h0B, &hD9, &h12, &hE8, &h53, &h89, &h44})
DIM SHARED IID_IDWriteFontCollection AS GUID = (&hA84CEE02, &h3EEA, &h4EEE, {&hA8, &h27, &h87, &hC1, &hA0, &h2A, &h0F, &hCC})
DIM SHARED IID_IDWriteFontCollection1 AS GUID = (&h53585141, &hD9F8, &h4095, {&h83, &h21, &hD7, &h3C, &hF6, &hBD, &h11, &h6C})
DIM SHARED IID_IDWriteFontCollection2 AS GUID = (&h514039C6, &h4617, &h4064, {&hBF, &h8B, &h92, &hEA, &h83, &hE5, &h06, &hE0})
DIM SHARED IID_IDWriteFontCollection3 AS GUID = (&hA4D055A6, &hF9E3, &h4E25, {&h93, &hB7, &h9E, &h30, &h9F, &h3A, &hF8, &hE9})
DIM SHARED IID_IDWriteFontCollectionLoader AS GUID = (&hCCA920E4, &h52F0, &h492B, {&hBF, &hA8, &h29, &hC7, &h2E, &hE0, &hA4, &h68})
DIM SHARED IID_IDWriteFontDownloadListener AS GUID = (&hB06FE5B9, &h43EC, &h4393, {&h88, &h1B, &hDB, &hE4, &hDC, &h72, &hFD, &hA7})
DIM SHARED IID_IDWriteFontDownloadQueue AS GUID = (&hB71E6052, &h5AEA, &h4FA3, {&h83, &h2E, &hF6, &h0D, &h43, &h1F, &h7E, &h91})
DIM SHARED IID_IDWriteFontFace AS GUID = (&h5F49804D, &h7024, &h4D43, {&hBF, &hA9, &hD2, &h59, &h84, &hF5, &h38, &h49})
DIM SHARED IID_IDWriteFontFace1 AS GUID = (&hA71EFDB4, &h9FDB, &h4838, {&hAD, &h90, &hCF, &hC3, &hBE, &h8C, &h3D, &hAF})
DIM SHARED IID_IDWriteFontFace2 AS GUID = (&hD8B768FF, &h64BC, &h4E66, {&h98, &h2B, &hEC, &h8E, &h87, &hF6, &h93, &hF7})
DIM SHARED IID_IDWriteFontFace3 AS GUID = (&hD37D7598, &h09BE, &h4222, {&hA2, &h36, &h20, &h81, &h34, &h1C, &hC1, &hF2})
DIM SHARED IID_IDWriteFontFace4 AS GUID = (&h27F2A904, &h4EB8, &h441D, {&h96, &h78, &h05, &h63, &hF5, &h3E, &h3E, &h2F})
DIM SHARED IID_IDWriteFontFace5 AS GUID = (&h98EFF3A5, &hB667, &h479A, {&hB1, &h45, &hE2, &hFA, &h5B, &h9F, &hDC, &h29})
DIM SHARED IID_IDWriteFontFace6 AS GUID = (&hC4B1FE1B, &h6E84, &h47D5, {&hB5, &h4C, &hA5, &h97, &h98, &h1B, &h06, &hAD})
DIM SHARED IID_IDWriteFontFace7 AS GUID = (&h3945B85B, &hBC95, &h40F7, {&hB7, &h2C, &h8B, &h73, &hBF, &hC7, &hE1, &h3B})
DIM SHARED IID_IDWriteFontFaceReference AS GUID = (&h5E7FA7CA, &hDDE3, &h424C, {&h89, &hF0, &h9F, &hCD, &h6F, &hED, &h58, &hCD})
DIM SHARED IID_IDWriteFontFaceReference1 AS GUID = (&hC081FE77, &h2FD1, &h41AC, {&hA5, &hA3, &h34, &h98, &h3C, &h4B, &hA6, &h1A})
DIM SHARED IID_IDWriteFontFallback AS GUID = (&hEFA008F9, &hF7A1, &h48BF, {&hB0, &h5C, &hF2, &h24, &h71, &h3C, &hC0, &hFF})
DIM SHARED IID_IDWriteFontFallback1 AS GUID = (&h2397599D, &hDD0D, &h4681, {&hBD, &h6A, &hF4, &hF3, &h1E, &hAA, &hDE, &h77})
DIM SHARED IID_IDWriteFontFallbackBuilder AS GUID = (&hFD882D06, &h8ABA, &h4FB8, {&hB8, &h49, &h8B, &hE8, &hB7, &h3E, &h14, &hDE})
DIM SHARED IID_IDWriteFontFamily AS GUID = (&hDA20D8EF, &h812A, &h4C43, {&h98, &h02, &h62, &hEC, &h4A, &hBD, &h7A, &hDD})
DIM SHARED IID_IDWriteFontFamily1 AS GUID = (&hDA20D8EF, &h812A, &h4C43, {&h98, &h02, &h62, &hEC, &h4A, &hBD, &h7A, &hDF})
DIM SHARED IID_IDWriteFontFamily2 AS GUID = (&h3ED49E77, &hA398, &h4261, {&hB9, &hCF, &hC1, &h26, &hC2, &h13, &h1E, &hF3})
DIM SHARED IID_IDWriteFontFile AS GUID = (&h739D886A, &hCEF5, &h47DC, {&h87, &h69, &h1A, &h8B, &h41, &hBE, &hBB, &hB0})
DIM SHARED IID_IDWriteFontFileEnumerator AS GUID = (&h72755049, &h5FF7, &h435D, {&h83, &h48, &h4B, &hE9, &h7C, &hFA, &h6C, &h7C})
DIM SHARED IID_IDWriteFontFileLoader AS GUID = (&h727CAD4E, &hD6AF, &h4C9E, {&h8A, &h08, &hD6, &h95, &hB1, &h1C, &hAA, &h49})
DIM SHARED IID_IDWriteFontFileStream AS GUID = (&h6D4865FE, &h0AB8, &h4D91, {&h8F, &h62, &h5D, &hD6, &hBE, &h34, &hA3, &hE0})
DIM SHARED IID_IDWriteFontList AS GUID = (&h1A0D8438, &h1D97, &h4EC1, {&hAE, &hF9, &hA2, &hFB, &h86, &hED, &h6A, &hCB})
DIM SHARED IID_IDWriteFontList1 AS GUID = (&hDA20D8EF, &h812A, &h4C43, {&h98, &h02, &h62, &hEC, &h4A, &hBD, &h7A, &hDE})
DIM SHARED IID_IDWriteFontList2 AS GUID = (&hC0763A34, &h77AF, &h445A, {&hB7, &h35, &h08, &hC3, &h7B, &h0A, &h5B, &hF5})
DIM SHARED IID_IDWriteFontResource AS GUID = (&h1F803A76, &h6871, &h48E8, {&h98, &h7F, &hB9, &h75, &h55, &h1C, &h50, &hF2})
DIM SHARED IID_IDWriteFontSet AS GUID = (&h53585141, &hD9F8, &h4095, {&h83, &h21, &hD7, &h3C, &hF6, &hBD, &h11, &h6B})
DIM SHARED IID_IDWriteFontSet1 AS GUID = (&h7E9FDA85, &h6C92, &h4053, {&hBC, &h47, &h7A, &hE3, &h53, &h0D, &hB4, &hD3})
DIM SHARED IID_IDWriteFontSet2 AS GUID = (&hDC7EAD19, &hE54C, &h43AF, {&hB2, &hDA, &h4E, &h2B, &h79, &hBA, &h3F, &h7F})
DIM SHARED IID_IDWriteFontSet3 AS GUID = (&h7C073EF2, &hA7F4, &h4045, {&h8C, &h32, &h8A, &hB8, &hAE, &h64, &h0F, &h90})
DIM SHARED IID_IDWriteFontSet4 AS GUID = (&hEEC175FC, &hBEA9, &h4C86, {&h8B, &h53, &hCC, &hBD, &hD7, &hDF, &h0C, &h82})
DIM SHARED IID_IDWriteFontSetBuilder AS GUID = (&h2F642AFE, &h9C68, &h4F40, {&hB8, &hBE, &h45, &h74, &h01, &hAF, &hCB, &h3D})
DIM SHARED IID_IDWriteFontSetBuilder1 AS GUID = (&h3FF7715F, &h3CDC, &h4DC6, {&h9B, &h72, &hEC, &h56, &h21, &hDC, &hCA, &hFD})
DIM SHARED IID_IDWriteFontSetBuilder2 AS GUID = (&hEE5BA612, &hB131, &h463C, {&h8F, &h4F, &h31, &h89, &hB9, &h40, &h1E, &h45})
DIM SHARED IID_IDWriteGdiInterop AS GUID = (&h1EDD9491, &h9853, &h4299, {&h89, &h8F, &h64, &h32, &h98, &h3B, &h6F, &h3A})
DIM SHARED IID_IDWriteGdiInterop1 AS GUID = (&h4556BE70, &h3ABD, &h4F70, {&h90, &hBE, &h42, &h17, &h80, &hA6, &hF5, &h15})
DIM SHARED IID_IDWriteGlyphRunAnalysis AS GUID = (&h7D97DBF7, &hE085, &h42D4, {&h81, &hE3, &h6A, &h88, &h3B, &hDE, &hD1, &h18})
DIM SHARED IID_IDWriteInlineObject AS GUID = (&h8339FDE3, &h106F, &h47AB, {&h83, &h73, &h1C, &h62, &h95, &hEB, &h10, &hB3})
DIM SHARED IID_IDWriteInMemoryFontFileLoader AS GUID = (&hDC102F47, &hA12D, &h4B1C, {&h82, &h2D, &h9E, &h11, &h7E, &h33, &h04, &h3F})
DIM SHARED IID_IDWriteLocalFontFileLoader AS GUID = (&hB2D9F3EC, &hC9FE, &h4A11, {&hA2, &hEC, &hD8, &h62, &h08, &hF7, &hC0, &hA2})
DIM SHARED IID_IDWriteLocalizedStrings AS GUID = (&h08256209, &h099A, &h4B34, {&hB8, &h6D, &hC2, &h2B, &h11, &h0E, &h77, &h71})
DIM SHARED IID_IDWriteNumberSubstitution AS GUID = (&h14885CC9, &hBAB0, &h4F90, {&hB6, &hED, &h5C, &h36, &h6A, &h2C, &hD0, &h3D})
DIM SHARED IID_IDWritePaintReader AS GUID = (&h8128E912, &h3B97, &h42A5, {&hAB, &h6C, &h24, &hAA, &hD3, &hA8, &h6E, &h54})
DIM SHARED IID_IDWritePixelSnapping AS GUID = (&hEAF3A2DA, &hECF4, &h4D24, {&hB6, &h44, &hB3, &h4F, &h68, &h42, &h02, &h4B})
DIM SHARED IID_IDWriteRemoteFontFileLoader AS GUID = (&h68648C83, &h6EDE, &h46C0, {&hAB, &h46, &h20, &h08, &h3A, &h88, &h7F, &hDE})
DIM SHARED IID_IDWriteRemoteFontFileStream AS GUID = (&h4DB3757A, &h2C72, &h4ED9, {&hB2, &hB6, &h1A, &hBA, &hBE, &h1A, &hFF, &h9C})
DIM SHARED IID_IDWriteRenderingParams AS GUID = (&h2F0DA53A, &h2ADD, &h47CD, {&h82, &hEE, &hD9, &hEC, &h34, &h68, &h8E, &h75})
DIM SHARED IID_IDWriteRenderingParams1 AS GUID = (&h94413CF4, &hA6FC, &h4248, {&h8B, &h50, &h66, &h74, &h34, &h8F, &hCA, &hD3})
DIM SHARED IID_IDWriteRenderingParams2 AS GUID = (&hF9D711C3, &h9777, &h40AE, {&h87, &hE8, &h3E, &h5A, &hF9, &hBF, &h09, &h48})
DIM SHARED IID_IDWriteRenderingParams3 AS GUID = (&hB7924BAA, &h391B, &h412A, {&h8C, &h5C, &hE4, &h4C, &hC2, &hD8, &h67, &hDC})
DIM SHARED IID_IDWriteStringList AS GUID = (&hCFEE3140, &h1157, &h47CA, {&h8B, &h85, &h31, &hBF, &hCF, &h3F, &h2D, &h0E})
DIM SHARED IID_IDWriteTextAnalysisSink AS GUID = (&h5810CD44, &h0CA0, &h4701, {&hB3, &hFA, &hBE, &hC5, &h18, &h2A, &hE4, &hF6})
DIM SHARED IID_IDWriteTextAnalysisSink1 AS GUID = (&hB0D941A0, &h85E7, &h4D8B, {&h9F, &hD3, &h5C, &hED, &h99, &h34, &h48, &h2A})
DIM SHARED IID_IDWriteTextAnalysisSource AS GUID = (&h688E1A58, &h5094, &h47C8, {&hAD, &hC8, &hFB, &hCE, &hA6, &h0A, &hE9, &h2B})
DIM SHARED IID_IDWriteTextAnalysisSource1 AS GUID = (&h639CFAD8, &h0FB4, &h4B21, {&hA5, &h8A, &h06, &h79, &h20, &h12, &h00, &h09})
DIM SHARED IID_IDWriteTextAnalyzer AS GUID = (&hB7E6163E, &h7F46, &h43B4, {&h84, &hB3, &hE4, &hE6, &h24, &h9C, &h36, &h5D})
DIM SHARED IID_IDWriteTextAnalyzer1 AS GUID = (&h80DAD800, &hE21F, &h4E83, {&h96, &hCE, &hBF, &hCC, &hE5, &h00, &hDB, &h7C})
DIM SHARED IID_IDWriteTextAnalyzer2 AS GUID = (&h553A9FF3, &h5693, &h4DF7, {&hB5, &h2B, &h74, &h80, &h6F, &h7F, &h2E, &hB9})
DIM SHARED IID_IDWriteTextFormat AS GUID = (&h9C906818, &h31D7, &h4FD3, {&hA1, &h51, &h7C, &h5E, &h22, &h5D, &hB5, &h5A})
DIM SHARED IID_IDWriteTextFormat1 AS GUID = (&h5F174B49, &h0D8B, &h4CFB, {&h8B, &hCA, &hF1, &hCC, &hE9, &hD0, &h6C, &h67})
DIM SHARED IID_IDWriteTextFormat2 AS GUID = (&hF67E0EDD, &h9E3D, &h4ECC, {&h8C, &h32, &h41, &h83, &h25, &h3D, &hFE, &h70})
DIM SHARED IID_IDWriteTextFormat3 AS GUID = (&h6D3B5641, &hE550, &h430D, {&hA8, &h5B, &hB7, &hBF, &h48, &hA9, &h34, &h27})
DIM SHARED IID_IDWriteTextLayout AS GUID = (&h53737037, &h6D14, &h410B, {&h9B, &hFE, &h0B, &h18, &h2B, &hB7, &h09, &h61})
DIM SHARED IID_IDWriteTextLayout1 AS GUID = (&h9064D822, &h80A7, &h465C, {&hA9, &h86, &hDF, &h65, &hF7, &h8B, &h8F, &hEB})
DIM SHARED IID_IDWriteTextLayout2 AS GUID = (&h1093C18F, &h8D5E, &h43F0, {&hB0, &h64, &h09, &h17, &h31, &h1B, &h52, &h5E})
DIM SHARED IID_IDWriteTextLayout3 AS GUID = (&h07DDCD52, &h020E, &h4DE8, {&hAC, &h33, &h6C, &h95, &h3D, &h83, &hF9, &h2D})
DIM SHARED IID_IDWriteTextLayout4 AS GUID = (&h05A9BF42, &h223F, &h4441, {&hB5, &hFB, &h82, &h63, &h68, &h5F, &h55, &hE9})
DIM SHARED IID_IDWriteTextRenderer AS GUID = (&hEF8A8135, &h5CC6, &h45FE, {&h88, &h25, &hC5, &hA0, &h72, &h4E, &hB8, &h19})
DIM SHARED IID_IDWriteTextRenderer1 AS GUID = (&hD3E0E934, &h22A0, &h427E, {&hAA, &hE4, &h7D, &h95, &h74, &hB5, &h9D, &hB1})
DIM SHARED IID_IDWriteTypography AS GUID = (&h55F1112B, &h1DC2, &h4B3C, {&h95, &h41, &hF4, &h68, &h94, &hED, &h85, &hB6})

TYPE IDWriteAsyncResult AS IDWriteAsyncResult_
TYPE IDWriteBitmapRenderTarget AS IDWriteBitmapRenderTarget_
TYPE IDWriteBitmapRenderTarget1 AS IDWriteBitmapRenderTarget1_
TYPE IDWriteBitmapRenderTarget2 AS IDWriteBitmapRenderTarget2_
TYPE IDWriteBitmapRenderTarget3 AS IDWriteBitmapRenderTarget3_
TYPE IDWriteColorGlyphRunEnumerator AS IDWriteColorGlyphRunEnumerator_
TYPE IDWriteColorGlyphRunEnumerator1 AS IDWriteColorGlyphRunEnumerator1_
TYPE IDWriteFactory AS IDWriteFactory_
TYPE IDWriteFactory1 AS IDWriteFactory1_
TYPE IDWriteFactory2 AS IDWriteFactory2_
TYPE IDWriteFactory3 AS IDWriteFactory3_
TYPE IDWriteFactory4 AS IDWriteFactory4_
TYPE IDWriteFactory5 AS IDWriteFactory5_
TYPE IDWriteFactory6 AS IDWriteFactory6_
TYPE IDWriteFactory7 AS IDWriteFactory7_
TYPE IDWriteFactory8 AS IDWriteFactory8_
TYPE IDWriteFont AS IDWriteFont_
TYPE IDWriteFont1 AS IDWriteFont1_
TYPE IDWriteFont2 AS IDWriteFont2_
TYPE IDWriteFont3 AS IDWriteFont3_
TYPE IDWriteFontCollection AS IDWriteFontCollection_
TYPE IDWriteFontCollection1 AS IDWriteFontCollection1_
TYPE IDWriteFontCollection2 AS IDWriteFontCollection2_
TYPE IDWriteFontCollection3 AS IDWriteFontCollection3_
TYPE IDWriteFontCollectionLoader AS IDWriteFontCollectionLoader_
TYPE IDWriteFontDownloadListener AS IDWriteFontDownloadListener_
TYPE IDWriteFontDownloadQueue AS IDWriteFontDownloadQueue_
TYPE IDWriteFontFace AS IDWriteFontFace_
TYPE IDWriteFontFace1 AS IDWriteFontFace1_
TYPE IDWriteFontFace2 AS IDWriteFontFace2_
TYPE IDWriteFontFace3 AS IDWriteFontFace3_
TYPE IDWriteFontFace4 AS IDWriteFontFace4_
TYPE IDWriteFontFace5 AS IDWriteFontFace5_
TYPE IDWriteFontFace6 AS IDWriteFontFace6_
TYPE IDWriteFontFace7 AS IDWriteFontFace7_
TYPE IDWriteFontFaceReference AS IDWriteFontFaceReference_
TYPE IDWriteFontFaceReference1 AS IDWriteFontFaceReference1_
TYPE IDWriteFontFallback AS IDWriteFontFallback_
TYPE IDWriteFontFallback1 AS IDWriteFontFallback1_
TYPE IDWriteFontFallbackBuilder AS IDWriteFontFallbackBuilder_
TYPE IDWriteFontFamily AS IDWriteFontFamily_
TYPE IDWriteFontFamily1 AS IDWriteFontFamily1_
TYPE IDWriteFontFamily2 AS IDWriteFontFamily2_
TYPE IDWriteFontFile AS IDWriteFontFile_
TYPE IDWriteFontFileEnumerator AS IDWriteFontFileEnumerator_
TYPE IDWriteFontFileLoader AS IDWriteFontFileLoader_
TYPE IDWriteFontFileStream AS IDWriteFontFileStream_
TYPE IDWriteFontList AS IDWriteFontList_
TYPE IDWriteFontList1 AS IDWriteFontList1_
TYPE IDWriteFontList2 AS IDWriteFontList2_
TYPE IDWriteFontResource AS IDWriteFontResource_
TYPE IDWriteFontSet AS IDWriteFontSet_
TYPE IDWriteFontSet1 AS IDWriteFontSet1_
TYPE IDWriteFontSet2 AS IDWriteFontSet2_
TYPE IDWriteFontSet3 AS IDWriteFontSet3_
TYPE IDWriteFontSet4 AS IDWriteFontSet4_
TYPE IDWriteFontSetBuilder AS IDWriteFontSetBuilder_
TYPE IDWriteFontSetBuilder1 AS IDWriteFontSetBuilder1_
TYPE IDWriteFontSetBuilder2 AS IDWriteFontSetBuilder2_
TYPE IDWriteGdiInterop AS IDWriteGdiInterop_
TYPE IDWriteGdiInterop1 AS IDWriteGdiInterop1_
TYPE IDWriteGlyphRunAnalysis AS IDWriteGlyphRunAnalysis_
TYPE IDWriteInlineObject AS IDWriteInlineObject_
TYPE IDWriteInMemoryFontFileLoader AS IDWriteInMemoryFontFileLoader_
TYPE IDWriteLocalFontFileLoader AS IDWriteLocalFontFileLoader_
TYPE IDWriteLocalizedStrings AS IDWriteLocalizedStrings_
TYPE IDWriteNumberSubstitution AS IDWriteNumberSubstitution_
TYPE IDWritePaintReader AS IDWritePaintReader_
TYPE IDWritePixelSnapping AS IDWritePixelSnapping_
TYPE IDWriteRemoteFontFileLoader AS IDWriteRemoteFontFileLoader_
TYPE IDWriteRemoteFontFileStream AS IDWriteRemoteFontFileStream_
TYPE IDWriteRenderingParams AS IDWriteRenderingParams_
TYPE IDWriteRenderingParams1 AS IDWriteRenderingParams1_
TYPE IDWriteRenderingParams2 AS IDWriteRenderingParams2_
TYPE IDWriteRenderingParams3 AS IDWriteRenderingParams3_
TYPE IDWriteStringList AS IDWriteStringList_
TYPE IDWriteTextAnalysisSink AS IDWriteTextAnalysisSink_
TYPE IDWriteTextAnalysisSink1 AS IDWriteTextAnalysisSink1_
TYPE IDWriteTextAnalysisSource AS IDWriteTextAnalysisSource_
TYPE IDWriteTextAnalysisSource1 AS IDWriteTextAnalysisSource1_
TYPE IDWriteTextAnalyzer AS IDWriteTextAnalyzer_
TYPE IDWriteTextAnalyzer1 AS IDWriteTextAnalyzer1_
TYPE IDWriteTextAnalyzer2 AS IDWriteTextAnalyzer2_
TYPE IDWriteTextFormat AS IDWriteTextFormat_
TYPE IDWriteTextFormat1 AS IDWriteTextFormat1_
TYPE IDWriteTextFormat2 AS IDWriteTextFormat2_
TYPE IDWriteTextFormat3 AS IDWriteTextFormat3_
TYPE IDWriteTextLayout AS IDWriteTextLayout_
TYPE IDWriteTextLayout1 AS IDWriteTextLayout1_
TYPE IDWriteTextLayout2 AS IDWriteTextLayout2_
TYPE IDWriteTextLayout3 AS IDWriteTextLayout3_
TYPE IDWriteTextLayout4 AS IDWriteTextLayout4_
TYPE IDWriteTextRenderer AS IDWriteTextRenderer_
TYPE IDWriteTextRenderer1 AS IDWriteTextRenderer1_
TYPE IDWriteTypography AS IDWriteTypography_


'/// The type of a font represented by a single font file.
'/// Font formats that consist of multiple files, e.g. Type 1 .PFM and .PFB, have
'/// separate enum values for each of the file type.
TYPE DWRITE_FONT_FILE_TYPE AS LONG
enum
   ' /// Font type is not recognized by the DirectWrite font system.
   DWRITE_FONT_FILE_TYPE_UNKNOWN
   ' /// OpenType font with CFF outlines.
   DWRITE_FONT_FILE_TYPE_CFF
   ' /// OpenType font with TrueType outlines.
   DWRITE_FONT_FILE_TYPE_TRUETYPE
   ' /// OpenType font that contains a TrueType collection.
   DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION
   ' /// Type 1 PFM font.
   DWRITE_FONT_FILE_TYPE_TYPE1_PFM
   ' /// Type 1 PFB font.
   DWRITE_FONT_FILE_TYPE_TYPE1_PFB
   ' /// Vector .FON font.
   DWRITE_FONT_FILE_TYPE_VECTOR
   ' /// Bitmap .FON font.
   DWRITE_FONT_FILE_TYPE_BITMAP
   ' // The following name is obsolete, but kept as an alias to avoid breaking existing code.
   DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION = DWRITE_FONT_FILE_TYPE_OPENTYPE_COLLECTION
end enum

'/// The file format of a complete font face.
'/// Font formats that consist of multiple files, e.g. Type 1 .PFM and .PFB, have
'/// a single enum entry.
TYPE DWRITE_FONT_FACE_TYPE AS LONG
enum
   ' /// OpenType font face with CFF outlines.
   DWRITE_FONT_FACE_TYPE_CFF
   ' /// OpenType font face with TrueType outlines.
   DWRITE_FONT_FACE_TYPE_TRUETYPE
   ' /// OpenType font face that is a part of a TrueType or CFF collection.
   DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION
   ' /// A Type 1 font face.
   DWRITE_FONT_FACE_TYPE_TYPE1
   ' /// A vector .FON format font face.
   DWRITE_FONT_FACE_TYPE_VECTOR
   ' /// A bitmap .FON format font face.
   DWRITE_FONT_FACE_TYPE_BITMAP
   ' /// Font face type is not recognized by the DirectWrite font system.
   DWRITE_FONT_FACE_TYPE_UNKNOWN
   ' /// The font data includes only the CFF table from an OpenType CFF font.
   ' /// This font face type can be used only for embedded fonts (i.e., custom
   ' /// font file loaders) and the resulting font face object supports only the
   ' /// minimum functionality necessary to render glyphs.
   DWRITE_FONT_FACE_TYPE_RAW_CFF
   ' // The following name is obsolete, but kept as an alias to avoid breaking existing code.
   DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION = DWRITE_FONT_FACE_TYPE_OPENTYPE_COLLECTION
end enum

'/// Specifies algorithmic style simulations to be applied to the font face.
'/// Bold and oblique simulations can be combined via bitwise OR operation.
TYPE DWRITE_FONT_SIMULATIONS AS LONG
enum
   ' /// No simulations are performed.
   DWRITE_FONT_SIMULATIONS_NONE    = &H0000
   ' /// Algorithmic emboldening is performed.
   DWRITE_FONT_SIMULATIONS_BOLD    = &H0001
   ' /// Algorithmic italicization is performed.
   DWRITE_FONT_SIMULATIONS_OBLIQUE = &H0002
end enum

'/// The font weight enumeration describes common values for degree of blackness or thickness of strokes of characters in a font.
'/// Font weight values less than 1 or greater than 999 are considered to be invalid, and they are rejected by font API functions.
TYPE DWRITE_FONT_WEIGHT AS LONG
enum
   ' /// Predefined font weight : Thin (100).
   DWRITE_FONT_WEIGHT_THIN = 100,
   ' /// Predefined font weight : Extra-light (200).
   DWRITE_FONT_WEIGHT_EXTRA_LIGHT = 200,
   ' /// Predefined font weight : Ultra-light (200).
   DWRITE_FONT_WEIGHT_ULTRA_LIGHT = 200,
   ' /// Predefined font weight : Light (300).
   DWRITE_FONT_WEIGHT_LIGHT = 300,
   ' /// Predefined font weight : Semi-light (350).
   DWRITE_FONT_WEIGHT_SEMI_LIGHT = 350,
   ' /// Predefined font weight : Normal (400).
   DWRITE_FONT_WEIGHT_NORMAL = 400,
   ' /// Predefined font weight : Regular (400).
   DWRITE_FONT_WEIGHT_REGULAR = 400,
   ' /// Predefined font weight : Medium (500).
   DWRITE_FONT_WEIGHT_MEDIUM = 500,
   ' /// Predefined font weight : Demi-bold (600).
   DWRITE_FONT_WEIGHT_DEMI_BOLD = 600,
   ' /// Predefined font weight : Semi-bold (600).
   DWRITE_FONT_WEIGHT_SEMI_BOLD = 600,
   ' /// Predefined font weight : Bold (700).
   DWRITE_FONT_WEIGHT_BOLD = 700,
   ' /// Predefined font weight : Extra-bold (800).
   DWRITE_FONT_WEIGHT_EXTRA_BOLD = 800,
   ' /// Predefined font weight : Ultra-bold (800).
   DWRITE_FONT_WEIGHT_ULTRA_BOLD = 800,
   ' /// Predefined font weight : Black (900).
   DWRITE_FONT_WEIGHT_BLACK = 900,
   ' /// Predefined font weight : Heavy (900).
   DWRITE_FONT_WEIGHT_HEAVY = 900,
   ' /// Predefined font weight : Extra-black (950).
   DWRITE_FONT_WEIGHT_EXTRA_BLACK = 950,
   ' /// Predefined font weight : Ultra-black (950).
   DWRITE_FONT_WEIGHT_ULTRA_BLACK = 950
end enum

'/// The font stretch enumeration describes relative change from the normal aspect ratio
'/// as specified by a font designer for the glyphs in a font.
'/// Values less than 1 or greater than 9 are considered to be invalid, and they are rejected by font API functions.
TYPE DWRITE_FONT_STRETCH AS LONG
enum
   ' /// Predefined font stretch : Not known (0).
   DWRITE_FONT_STRETCH_UNDEFINED = 0
   ' /// Predefined font stretch : Ultra-condensed (1).
   DWRITE_FONT_STRETCH_ULTRA_CONDENSED = 1
   ' /// Predefined font stretch : Extra-condensed (2).
   DWRITE_FONT_STRETCH_EXTRA_CONDENSED = 2
   ' /// Predefined font stretch : Condensed (3).
   DWRITE_FONT_STRETCH_CONDENSED = 3
   ' /// Predefined font stretch : Semi-condensed (4).
   DWRITE_FONT_STRETCH_SEMI_CONDENSED = 4
   ' /// Predefined font stretch : Normal (5).
   DWRITE_FONT_STRETCH_NORMAL = 5
   ' /// Predefined font stretch : Medium (5).
   DWRITE_FONT_STRETCH_MEDIUM = 5
   ' /// Predefined font stretch : Semi-expanded (6).
   DWRITE_FONT_STRETCH_SEMI_EXPANDED = 6
   ' /// Predefined font stretch : Expanded (7).
   DWRITE_FONT_STRETCH_EXPANDED = 7
   ' /// Predefined font stretch : Extra-expanded (8).
   DWRITE_FONT_STRETCH_EXTRA_EXPANDED = 8
   ' /// Predefined font stretch : Ultra-expanded (9).
   DWRITE_FONT_STRETCH_ULTRA_EXPANDED = 9
end enum

'/// The font style enumeration describes the slope style of a font face, such as Normal, Italic or Oblique.
'/// Values other than the ones defined in the enumeration are considered to be invalid, and they are rejected by font API functions.
TYPE DWRITE_FONT_STYLE AS LONG
enum
   ' /// Font slope style : Normal.
   DWRITE_FONT_STYLE_NORMAL,
   ' /// Font slope style : Oblique.
   DWRITE_FONT_STYLE_OBLIQUE,
   ' /// Font slope style : Italic.
   DWRITE_FONT_STYLE_ITALIC
end enum

'/// The informational string enumeration identifies a string in a font.
TYPE DWRITE_INFORMATIONAL_STRING_ID AS LONG
enum
   ' /// Unspecified name ID.
   DWRITE_INFORMATIONAL_STRING_NONE
   ' /// Copyright notice provided by the font.
   DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE
   ' /// String containing a version number.
   DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS
   ' /// Trademark information provided by the font.
   DWRITE_INFORMATIONAL_STRING_TRADEMARK
   ' /// Name of the font manufacturer.
   DWRITE_INFORMATIONAL_STRING_MANUFACTURER
   ' /// Name of the font designer.
   DWRITE_INFORMATIONAL_STRING_DESIGNER
   ' /// URL of font designer (with protocol, e.g., http://, ftp://).
   DWRITE_INFORMATIONAL_STRING_DESIGNER_URL
   ' /// Description of the font. Can contain revision information, usage recommendations, history, features, etc.
   DWRITE_INFORMATIONAL_STRING_DESCRIPTION
   ' /// URL of font vendor (with protocol, e.g., http://, ftp://). If a unique serial number is embedded in the URL, it can be used to register the font.
   DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL
   ' /// Description of how the font may be legally used, or different example scenarios for licensed use. This field should be written in plain language, not legalese.
   DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION
   ' /// URL where additional licensing information can be found.
   DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL
   ' /// GDI-compatible family name. Because GDI allows a maximum of four fonts per family, fonts in the same family may have different GDI-compatible family names
   ' /// (e.g., "Arial", "Arial Narrow", "Arial Black").
   DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES
   ' /// GDI-compatible subfamily name.
   DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES
   ' /// Typographic family name preferred by the designer. This enables font designers to group more than four fonts in a single family without losing compatibility with
   ' /// GDI. This name is typically only present if it differs from the GDI-compatible family name.
   DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES
   ' /// Typographic subfamily name preferred by the designer. This name is typically only present if it differs from the GDI-compatible subfamily name.
   DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES
   ' /// Sample text. This can be the font name or any other text that the designer thinks is the best example to display the font in.
   DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT
   ' /// The full name of the font, e.g. "Arial Bold", from name id 4 in the name table.
   DWRITE_INFORMATIONAL_STRING_FULL_NAME
   ' /// The postscript name of the font, e.g. "GillSans-Bold" from name id 6 in the name table.
   DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME
   ' /// The postscript CID findfont name, from name id 20 in the name table.
   DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME
   ' /// Family name for the weight-stretch-style model.
   DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME
   ' /// Script/language tag to identify the scripts or languages that the font was
   ' /// primarily designed to support. See DWRITE_FONT_PROPERTY_ID_DESIGN_SCRIPT_LANGUAGE_TAG
   ' /// for a longer description.
   DWRITE_INFORMATIONAL_STRING_DESIGN_SCRIPT_LANGUAGE_TAG
   ' /// Script/language tag to identify the scripts or languages that the font declares
   ' /// it is able to support.
   DWRITE_INFORMATIONAL_STRING_SUPPORTED_SCRIPT_LANGUAGE_TAG
   ' // Obsolete aliases kept to avoid breaking existing code.
   DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES = DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES
   DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES = DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES
   DWRITE_INFORMATIONAL_STRING_WWS_FAMILY_NAME = DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME
end enum

'/// The DWRITE_FONT_METRICS structure specifies the metrics of a font face that
'/// are applicable to all glyphs within the font face.
type DWRITE_FONT_METRICS
   AS UINT16 designUnitsPerEm
   AS UINT16 ascent
   AS UINT16 descent
   AS INT16 lineGap
   AS UINT16 capHeight
   AS UINT16 xHeight
   AS INT16 underlinePosition
   AS UINT16 underlineThickness
   AS INT16 strikethroughPosition
   AS UINT16 strikethroughThickness
end type

'/// The DWRITE_GLYPH_METRICS structure specifies the metrics of an individual glyph.
'/// The units depend on how the metrics are obtained.
type DWRITE_GLYPH_METRICS
'    /// Specifies the X offset from the glyph origin to the left edge of the black box.
'    /// The glyph origin is the current horizontal writing position.
'    /// A negative value means the black box extends to the left of the origin (often true for lowercase italic 'f').
   AS INT32 leftSideBearing
'    /// Specifies the X offset from the origin of the current glyph to the origin of the next glyph when writing horizontally.
   AS  UINT32 advanceWidth
'    /// Specifies the X offset from the right edge of the black box to the origin of the next glyph when writing horizontally.
'    /// The value is negative when the right edge of the black box overhangs the layout box.
   AS INT32 rightSideBearing
'    /// Specifies the vertical offset from the vertical origin to the top of the black box.
'    /// Thus, a positive value adds whitespace whereas a negative value means the glyph overhangs the top of the layout box.
   AS INT32 topSideBearing
'    /// Specifies the Y offset from the vertical origin of the current glyph to the vertical origin of the next glyph when writing vertically.
'    /// (Note that the term "origin" by itself denotes the horizontal origin. The vertical origin is different.
'    /// Its Y coordinate is specified by verticalOriginY value,
'    /// and its X coordinate is half the advanceWidth to the right of the horizontal origin).
   AS UINT32 advanceHeight
'    /// Specifies the vertical distance from the black box's bottom edge to the advance height.
'    /// Positive when the bottom edge of the black box is within the layout box.
'    /// Negative when the bottom edge of black box overhangs the layout box.
   AS INT32 bottomSideBearing
'    /// Specifies the Y coordinate of a glyph's vertical origin, in the font's design coordinate system.
'    /// The y coordinate of a glyph's vertical origin is the sum of the glyph's top side bearing
'    /// and the top (i.e. yMax) of the glyph's bounding box.
   AS INT32 verticalOriginY
end type

'/// Optional adjustment to a glyph's position. A glyph offset changes the position of a glyph without affecting
'/// the pen position. Offsets are in logical, pre-transform units.
#ifndef DWRITE_GLYPH_OFFSET
type DWRITE_GLYPH_OFFSET
   ' /// Offset in the advance direction of the run. A positive advance offset moves the glyph to the right
   ' /// (in pre-transform coordinates) if the run is left-to-right or to the left if the run is right-to-left.
   FLOAT advanceOffset
   ' /// Offset in the ascent direction, i.e., the direction ascenders point. A positive ascender offset moves
   ' /// the glyph up (in pre-transform coordinates).
   FLOAT ascenderOffset
end type
#endif

'/// Specifies the type of DirectWrite factory object.
'/// DirectWrite factory contains internal state such as font loader registration and cached font data.
'/// In most cases it is recommended to use the shared factory object, because it allows multiple components
'/// that use DirectWrite to share internal DirectWrite state and reduce memory usage.
'/// However, there are cases when it is desirable to reduce the impact of a component,
'/// such as a plug-in from an untrusted source, on the rest of the process by sandboxing and isolating it
'/// from the rest of the process components. In such cases, it is recommended to use an isolated factory for the sandboxed
'/// component.
#ifndef DWRITE_FACTORY_TYPE
TYPE DWRITE_FACTORY_TYPE AS LONG
enum
   ' /// Shared factory allow for re-use of cached font data across multiple in process components.
   ' /// Such factories also take advantage of cross process font caching components for better performance.
   DWRITE_FACTORY_TYPE_SHARED
   ' /// Objects created from the isolated factory do not interact with internal DirectWrite state from other components.
   DWRITE_FACTORY_TYPE_ISOLATED
end enum
#endif

'/// Creates an OpenType tag as a 32bit integer such that
'/// the first character in the tag is the lowest byte,
'/// (least significant on little endian architectures)
'/// which can be used to compare with tags in the font file.
'/// This macro is compatible with DWRITE_FONT_FEATURE_TAG.
'///
'/// Example: DWRITE_MAKE_OPENTYPE_TAG('c','c','m','p')
'/// Dword:   &H706D6363
'#define DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d) ( \
'    (static_cast<UINT32>(static_cast<UINT8>(d)) << 24) | \
'    (static_cast<UINT32>(static_cast<UINT8>(c)) << 16) | \
'    (static_cast<UINT32>(static_cast<UINT8>(b)) << 8)  | \
'     static_cast<UINT32>(static_cast<UINT8>(a)))
#define DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d) (culng(ASC(d)) shl 24) or (culng(ASC(c)) shl 16) or (culng(ASC(b)) shl 8) or culng(ASC(a))

'/// Creates an OpenType tag for glyph positioning and substitution font features.
'#define DWRITE_MAKE_FONT_FEATURE_TAG(a,b,c,d) (static_cast<DWRITE_FONT_FEATURE_TAG>(DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d)))
#define DWRITE_MAKE_FONT_FEATURE_TAG(a,b,c,d) DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d)

'/// Font file loader interface handles loading font file resources of a particular type from a key.
'/// The font file loader interface is recommended to be implemented by a singleton object.
'/// IMPORTANT: font file loader implementations must not register themselves with DirectWrite factory
'/// inside their constructors and must not unregister themselves in their destructors, because
'/// registration and unregistration operations increment and decrement the object reference count respectively.
'/// Instead, registration and unregistration of font file loaders with DirectWrite factory should be performed
'/// outside of the font file loader implementation as a separate step.

' ########################################################################################
' Interface name: IDWriteFontFileLoader
' IID: {727CAD4E-D6AF-4C9E-8A08-D695B11CAA49}
' Documentation string: Font file loader interface handles loading font file resources of a particular type from a key.
' Inherited interface = IUnknown
' Creates a font file stream object that encapsulates an open file resource.
' The resource is closed when the last reference to fontFileStream is released.
' ########################################################################################

#ifndef __IDWriteFontFileLoader_INTERFACE_DEFINED__
#define __IDWriteFontFileLoader_INTERFACE_DEFINED__

TYPE IDWriteFontFileLoader_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CreateStreamFromKey (BYVAL fontFileReferenceKey AS const ANY PTR, BYVAL fontFileReferenceKeySize AS UINT32, BYREF fontFileStream AS IDWriteFontFileStream PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteLocalFontFileLoader
' IID: {B2D9F3EC-C9FE-4A11-A2EC-D86208F7C0A2}
' Documentation string: A built-in implementation of IDWriteFontFileLoader interface that operates on local font files and exposes local font file information from the font file reference key.
' Inherited interface = IDWriteFontFileLoader
' A built-in implementation of IDWriteFontFileLoader interface that operates on local font files
' and exposes local font file information from the font file reference key.
' Font file references created using CreateFontFileReference use this font file loader.
' ########################################################################################

#ifndef __IDWriteLocalFontFileLoader_INTERFACE_DEFINED__
#define __IDWriteLocalFontFileLoader_INTERFACE_DEFINED__

TYPE IDWriteLocalFontFileLoader_ EXTENDS IDWriteFontFileLoader
   DECLARE ABSTRACT FUNCTION GetFilePathLengthFromKey (BYVAL fontFileReferenceKey AS const ANY PTR, BYVAL fontFileReferenceKeySize AS UINT32, BYREF filePathLength AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFilePathFromKey (BYVAL fontFileReferenceKey AS const ANY PTR, BYVAL fontFileReferenceKeySize AS UINT32, BYREF filePath AS WSTRING, BYVAL filePathSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLastWriteTimeFromKey (BYVAL fontFileReferenceKey AS const ANY PTR, BYVAL fontFileReferenceKeySize AS UINT32, BYREF LastWriteTime AS FILETIME) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFileStream
' IID: {6D4865FE-0AB8-4D91-8F62-5DD6BE34A3E0}
' Documentation string: The interface for loading font file data.
' Inherited interface = IUnknown
' The interface for loading font file data.
' ########################################################################################

#ifndef __IDWriteFontFileStream_INTERFACE_DEFINED__
#define __IDWriteFontFileStream_INTERFACE_DEFINED__

TYPE IDWriteFontFileStream_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION ReadFileFragment (BYVAL fragmentStart AS const ANY PTR, BYVAL fileOffset AS UINT64, BYVAL fragmentSize AS UINT64, BYREF fragmentContext AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseFileFragment (BYVAL fragmentContext AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFileSize (BYREF fileSize AS UINT64) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLastWriteTime (BYREF LastWriteTime AS UINT64) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFile
' IID: {739D886A-CEF5-47DC-8769-1A8B41BEBBB0}
' Documentation string: The interface that represents a reference to a font file.
' Inherited interface = IUnknown
' The interface that represents a reference to a font file.
' ########################################################################################

#ifndef __IDWriteFontFile_INTERFACE_DEFINED__
#define __IDWriteFontFile_INTERFACE_DEFINED__

TYPE IDWriteFontFile_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetReferenceKey (BYREF fontFileReferenceKey AS const ANY PTR, BYREF fontFileReferenceKeySize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLoader (BYREF fontFileLoader AS IDWriteFontFileLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Analyze (BYVAL isSupportedFontType AS BOOLEAN PTR, BYREF fontFileType AS DWRITE_FONT_FILE_TYPE, BYREF fontFaceType AS DWRITE_FONT_FACE_TYPE, BYREF numberOfFaces AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################


'/// Represents the internal structure of a device pixel (i.e., the physical arrangement of red,
'/// green, and blue color components) that is assumed for purposes of rendering text.
TYPE DWRITE_PIXEL_GEOMETRY AS LONG
enum
   ' /// The red, green, and blue color components of each pixel are assumed to occupy the same point.
   DWRITE_PIXEL_GEOMETRY_FLAT
   ' /// Each pixel comprises three vertical stripes, with red on the left, green in the center, and
   ' /// blue on the right. This is the most common pixel geometry for LCD monitors.
   DWRITE_PIXEL_GEOMETRY_RGB
   ' /// Each pixel comprises three vertical stripes, with blue on the left, green in the center, and
   ' /// red on the right.
   DWRITE_PIXEL_GEOMETRY_BGR
end enum

'/// Represents a method of rendering glyphs.
TYPE DWRITE_RENDERING_MODE AS LONG
enum
   ' /// Specifies that the rendering mode is determined automatically based on the font and size.
   DWRITE_RENDERING_MODE_DEFAULT
   ' /// Specifies that no antialiasing is performed. Each pixel is either set to the foreground
   ' /// color of the text or retains the color of the background.
   DWRITE_RENDERING_MODE_ALIASED
   ' /// Specifies that antialiasing is performed in the horizontal direction and the appearance
   ' /// of glyphs is layout-compatible with GDI using CLEARTYPE_QUALITY. Use DWRITE_MEASURING_MODE_GDI_CLASSIC
   ' /// to get glyph advances. The antialiasing may be either ClearType or grayscale depending on
   ' /// the text antialiasing mode.
   DWRITE_RENDERING_MODE_GDI_CLASSIC
   ' /// Specifies that antialiasing is performed in the horizontal direction and the appearance
   ' /// of glyphs is layout-compatible with GDI using CLEARTYPE_NATURAL_QUALITY. Glyph advances
   ' /// are close to the font design advances, but are still rounded to whole pixels. Use
   ' /// DWRITE_MEASURING_MODE_GDI_NATURAL to get glyph advances. The antialiasing may be either
   ' /// ClearType or grayscale depending on the text antialiasing mode.
   DWRITE_RENDERING_MODE_GDI_NATURAL
   ' /// Specifies that antialiasing is performed in the horizontal direction. This rendering
   ' /// mode allows glyphs to be positioned with subpixel precision and is therefore suitable
   ' /// for natural (i.e., resolution-independent) layout. The antialiasing may be either
   ' /// ClearType or grayscale depending on the text antialiasing mode.
   DWRITE_RENDERING_MODE_NATURAL
   ' /// Similar to natural mode except that antialiasing is performed in both the horizontal
   ' /// and vertical directions. This is typically used at larger sizes to make curves and
   ' /// diagonal lines look smoother. The antialiasing may be either ClearType or grayscale
   ' /// depending on the text antialiasing mode.
   DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC
   ' /// Specifies that rendering should bypass the rasterizer and use the outlines directly.
   ' /// This is typically used at very large sizes.
   DWRITE_RENDERING_MODE_OUTLINE
'    // The following names are obsolete, but are kept as aliases to avoid breaking existing code.
'    // Each of these rendering modes may result in either ClearType or grayscale antialiasing
'    // depending on the DWRITE_TEXT_ANTIALIASING_MODE.
   DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC         = DWRITE_RENDERING_MODE_GDI_CLASSIC
   DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL         = DWRITE_RENDERING_MODE_GDI_NATURAL
   DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL             = DWRITE_RENDERING_MODE_NATURAL
   DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC   = DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC
end enum

'/// The DWRITE_MATRIX structure specifies the graphics transform to be applied to rendered glyphs.
type DWRITE_MATRIX
   ' /// Horizontal scaling / cosine of rotation
   AS FLOAT m11
   ' /// Vertical shear / sine of rotation
   AS FLOAT m12
   ' /// Horizontal shear / negative sine of rotation
   AS FLOAT m21
   ' /// Vertical scaling / cosine of rotation
   AS FLOAT m22
   ' /// Horizontal shift (always orthogonal regardless of rotation)
   AS FLOAT dx
   ' /// Vertical shift (always orthogonal regardless of rotation)
   AS FLOAT dy
end type

' ########################################################################################
' Interface name: IDWriteRenderingParams
' IID: {2F0DA53A-2ADD-47CD-82EE-D9EC34688E75}
' Documentation string: The interface that represents text rendering settings for glyph rasterization and filtering.
' Inherited interface = IUnknown
' The interface that represents text rendering settings for glyph rasterization and filtering.
' ########################################################################################

#ifndef __IDWriteRenderingParams_INTERFACE_DEFINED__
#define __IDWriteRenderingParams_INTERFACE_DEFINED__

TYPE IDWriteRenderingParams_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetGamma () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetEnhancedContrast () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetClearTypeLevel () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetPixelGeometry () AS DWRITE_PIXEL_GEOMETRY
   DECLARE ABSTRACT FUNCTION GetRenderingMode () AS DWRITE_RENDERING_MODE
END TYPE

#endif

' ########################################################################################


' // Forward declarations of D2D types
'type ID2D1SimplifiedGeometrySink ID2D1SimplifiedGeometrySink_

'type ID2D1SimplifiedGeometrySink AS IDWriteGeometrySink

' ########################################################################################
' Interface name: IDWriteFontFace
' IID: {5F49804D-7024-4D43-BFA9-D25984F53849}
' Documentation string: The interface that represents an absolute reference to a font face.
' Inherited interface = IUnknown
' This interface exposes various font data such as metrics, names, and glyph outlines.
' It contains font face type, appropriate file references and face identification data.
' ########################################################################################

#ifndef __IDWriteFontFace_INTERFACE_DEFINED__
#define __IDWriteFontFace_INTERFACE_DEFINED__

TYPE IDWriteFontFace_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetType () AS DWRITE_FONT_FACE_TYPE
   DECLARE ABSTRACT FUNCTION GetFiles (BYREF numberOfFiles AS UINT32, BYVAL fontFiles AS IDWriteFontFile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetIndex () AS UINT32
   DECLARE ABSTRACT FUNCTION GetSimulations () AS DWRITE_FONT_SIMULATIONS
   DECLARE ABSTRACT FUNCTION IsSymbolFont () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetMetrics (BYREF fontFaceMetrics AS DWRITE_FONT_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphCount () AS UINT16
   DECLARE ABSTRACT FUNCTION GetDesignGlyphMetrics (BYREF glyphIndices AS const UINT16, BYVAL glyphCount AS UINT32, _
           BYREF glyphMetrics AS DWRITE_GLYPH_METRICS, BYVAL isSideways AS BOOLEAN = FALSE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphIndices (BYREF codePoints AS const UINT32, BYVAL codePointCount AS UINT32, _
           BYREF glyphIndices AS const UINT16) AS HRESULT
   DECLARE ABSTRACT FUNCTION TryGetFontTable (BYVAL openTypeTableTag AS UINT32, BYVAL tableData AS const ANY PTR, _
           BYREF tableSize AS UINT32, BYREF tableContext AS ANY PTR, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseFontTable (BYVAL tableContext AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphRunOutline (BYVAL emSize AS FLOAT, BYREF glyphIndices AS const UINT16, _
           BYREF glyphAdvances AS const FLOAT, BYREF glyphOffsets AS const DWRITE_GLYPH_OFFSET, _
           BYVAL glyphCount AS UINT32, BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRecommendedRenderingMode (BYVAL emSize AS FLOAT, BYVAL pixelsPerDip AS FLOAT, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYVAL renderingParams AS IDWriteRenderingParams PTR, BYREF renderingMode AS DWRITE_RENDERING_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGdiCompatibleMetrics (BYVAL emSize AS FLOAT, BYVAL pixelsPerDip AS FLOAT, _
           BYREF transform AS const DWRITE_MATRIX, BYREF fontFaceMetrics AS DWRITE_FONT_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGdiCompatibleGlyphMetrics (BYVAL emSize AS FLOAT, BYVAL pixelsPerDip AS FLOAT, _
           BYREF transform AS const DWRITE_MATRIX, BYVAL useGdiNatural AS BOOLEAN, BYREF glyphIndices AS const UINT16, _
           BYVAL glyphCount AS UINT32, BYREF glyphMetrics AS DWRITE_GLYPH_METRICS, BYVAL isSideways AS BOOLEAN = FALSE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontCollectionLoader
' IID: {CCA920E4-52F0-492B-BFA8-29C72EE0A468}
' Documentation string: The font collection loader interface is used to construct a collection
' of fonts given a particular type of key.
' Inherited interface = IUnknown
' The font collection loader interface is used to construct a collection of fonts given a particular type of key.
' The font collection loader interface is recommended to be implemented by a singleton object.
' IMPORTANT: font collection loader implementations must not register themselves with a DirectWrite factory
' inside their constructors and must not unregister themselves in their destructors, because
' registration and unregistration operations increment and decrement the object reference count respectively.
' Instead, registration and unregistration of font file loaders with DirectWrite factory should be performed
' outside of the font file loader implementation as a separate step.
' ########################################################################################

#ifndef __IDWriteFontCollectionLoader_INTERFACE_DEFINED__
#define __IDWriteFontCollectionLoader_INTERFACE_DEFINED__

TYPE IDWriteFontCollectionLoader_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CreateEnumeratorFromKey (BYVAL factory AS IDWriteFactory PTR, BYVAL collectionKey AS const ANY PTR, _
      BYVAL collectionKeySize AS UINT32, BYREF fontFileEnumerator AS IDWriteFontFileEnumerator PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFileEnumerator
' IID: {72755049-5FF7-435D-8348-4BE97CFA6C7C}
' Documentation string: The font file enumerator interface encapsulates a collection of font files. The font system uses this interface to enumerate font files when building a font collection.
' Inherited interface = IUnknown
' The font file enumerator interface encapsulates a collection of font files. The font system
' uses this interface to enumerate font files when building a font collection.
' ########################################################################################

#ifndef __IDWriteFontFileEnumerator_INTERFACE_DEFINED__
#define __IDWriteFontFileEnumerator_INTERFACE_DEFINED__

TYPE IDWriteFontFileEnumerator_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION MoveNext (BYREF hasCurrentFile AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCurrentFontFile (BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteLocalizedStrings
' IID: {08256209-099A-4B34-B86D-C22B110E7771}
' Documentation string: Represents a collection of strings indexed by locale name.
' Inherited interface = IUnknown
' Represents a collection of strings indexed by locale name.
' ########################################################################################

#ifndef __IDWriteLocalizedStrings_INTERFACE_DEFINED__
#define __IDWriteLocalizedStrings_INTERFACE_DEFINED__

TYPE IDWriteLocalizedStrings_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetCount () AS UINT32
   DECLARE ABSTRACT FUNCTION FindLocaleName (BYREF localeName AS const WSTRING, BYREF index AS UINT32, BYREF exists AS BOOLEAN PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocaleNameLength (BYVAL index AS UINT32, BYREF Length AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocaleName (BYVAL UINT32 AS LONG, BYREF localeName AS WSTRING, BYVAL size AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetStringLength (BYVAL UINT32 AS LONG, BYREF Length AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetString (BYVAL index AS UINT32, BYREF stringBuffer AS WSTRING, BYVAL size AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontCollection
' IID: {A84CEE02-3EEA-4EEE-A827-87C1A02A0FCC}
' Documentation string: The IDWriteFontCollection encapsulates a collection of fonts.
' Inherited interface = IUnknown
' The IDWriteFontCollection encapsulates a collection of font families.
' ########################################################################################

#ifndef __IDWriteFontCollection_INTERFACE_DEFINED__
#define __IDWriteFontCollection_INTERFACE_DEFINED__

TYPE IDWriteFontCollection_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetFontFamilyCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontFamily (BYVAL index AS UINT32, BYREF fontFamily AS IDWriteFontFamily PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION FindFamilyName (BYREF familyName AS const WSTRING, BYVAL index AS UINT32 PTR, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFromFontFace (BYVAL fontFace AS IDWriteFontFace PTR, BYREF Font AS IDWriteFont PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontList
' IID: {1A0D8438-1D97-4EC1-AEF9-A2FB86ED6ACB}
' Documentation string: The IDWriteFontList interface represents a list of fonts.
' Inherited interface = IUnknown
' The IDWriteFontList interface represents an ordered set of fonts that are part of an IDWriteFontCollection.
' ########################################################################################

#ifndef __IDWriteFontList_INTERFACE_DEFINED__
#define __IDWriteFontList_INTERFACE_DEFINED__

TYPE IDWriteFontList_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetFontCollection (BYREF fontCollection AS IDWriteFontCollection PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFont (BYVAL index AS UINT32, BYREF font AS IDWriteFont PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFamily
' IID: {DA20D8EF-812A-4C43-9802-62EC4ABD7ADD}
' Documentation string: The IDWriteFontFamily interface represents a set of fonts that share the same design but are differentiated by weight, stretch, and style.
' Inherited interface = IDWriteFontList
' The IDWriteFontFamily interface represents a set of fonts that share the same design but
' are differentiated by weight, stretch, and style.
' ########################################################################################

#ifndef __IDWriteFontFamily_INTERFACE_DEFINED__
#define __IDWriteFontFamily_INTERFACE_DEFINED__

TYPE IDWriteFontFamily_ EXTENDS IDWriteFontList
   DECLARE ABSTRACT FUNCTION GetFamilyNames (BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFirstMatchingFont (BYVAL weight AS DWRITE_FONT_WEIGHT, BYVAL stretch AS DWRITE_FONT_STRETCH, _
           BYVAL style AS DWRITE_FONT_STYLE, BYREF matchingFont AS IDWriteFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatchingFonts (BYVAL weight AS DWRITE_FONT_WEIGHT, BYVAL stretch AS DWRITE_FONT_STRETCH, _
           BYVAL style AS DWRITE_FONT_STYLE, BYREF matchingFonts AS IDWriteFontList PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFont
' IID: {ACD16696-8C14-4F5D-877E-FE3FC1D32737}
' Documentation string: The IDWriteFont interface represents a physical font in a font collection.
' Inherited interface = IUnknown
' The IDWriteFont interface represents a physical font in a font collection.
' ########################################################################################

#ifndef __IDWriteFont_INTERFACE_DEFINED__
#define __IDWriteFont_INTERFACE_DEFINED__

TYPE IDWriteFont_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetFontFamily (BYREF fontFamily AS IDWriteFontFamily PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetWeight () AS DWRITE_FONT_WEIGHT
   DECLARE ABSTRACT FUNCTION GetStretch () AS DWRITE_FONT_STRETCH
   DECLARE ABSTRACT FUNCTION GetStyle () AS DWRITE_FONT_STYLE
   DECLARE ABSTRACT FUNCTION IsSymbolFont () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetFaceNames (BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetInformationalStrings (BYVAL informationalStringID AS DWRITE_INFORMATIONAL_STRING_ID, _
           BYREF informationalStrings AS IDWriteLocalizedStrings PTR, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSimulations () AS DWRITE_FONT_SIMULATIONS
   DECLARE ABSTRACT FUNCTION GetMetrics (BYREF fontMetrics AS DWRITE_FONT_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasCharacter (BYVAL unicodeValue AS UINT32, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFace (BYREF fontFace AS IDWriteFontFace PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' /// Direction for how reading progresses.
TYPE DWRITE_READING_DIRECTION AS LONG
enum
   ' /// Reading progresses from left to right.
   DWRITE_READING_DIRECTION_LEFT_TO_RIGHT = 0
   ' /// Reading progresses from right to left.
   DWRITE_READING_DIRECTION_RIGHT_TO_LEFT = 1
   ' /// Reading progresses from top to bottom.
   DWRITE_READING_DIRECTION_TOP_TO_BOTTOM = 2
   ' /// Reading progresses from bottom to top.
   DWRITE_READING_DIRECTION_BOTTOM_TO_TOP = 3
end enum

' /// Direction for how lines of text are placed relative to one another.
TYPE DWRITE_FLOW_DIRECTION AS LONG
enum
   ' /// Text lines are placed from top to bottom.
   DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM = 0
   ' /// Text lines are placed from bottom to top.
   DWRITE_FLOW_DIRECTION_BOTTOM_TO_TOP = 1
   ' /// Text lines are placed from left to right.
   DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT = 2
   ' /// Text lines are placed from right to left.
   DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT = 3
end enum

'/// Alignment of paragraph text along the reading direction axis relative to
'/// the leading and trailing edge of the layout box.
TYPE DWRITE_TEXT_ALIGNMENT AS LONG
enum
   ' /// The leading edge of the paragraph text is aligned to the layout box's leading edge.
   DWRITE_TEXT_ALIGNMENT_LEADING
   ' /// The trailing edge of the paragraph text is aligned to the layout box's trailing edge.
   DWRITE_TEXT_ALIGNMENT_TRAILING
   ' /// The center of the paragraph text is aligned to the center of the layout box.
   DWRITE_TEXT_ALIGNMENT_CENTER
   ' /// Align text to the leading side, and also justify text to fill the lines.
   DWRITE_TEXT_ALIGNMENT_JUSTIFIED
end enum

'/// Alignment of paragraph text along the flow direction axis relative to the
'/// flow's beginning and ending edge of the layout box.
TYPE DWRITE_PARAGRAPH_ALIGNMENT AS LONG
enum
   ' /// The first line of paragraph is aligned to the flow's beginning edge of the layout box.
   DWRITE_PARAGRAPH_ALIGNMENT_NEAR
   ' /// The last line of paragraph is aligned to the flow's ending edge of the layout box.
   DWRITE_PARAGRAPH_ALIGNMENT_FAR
   ' /// The center of the paragraph is aligned to the center of the flow of the layout box.
   DWRITE_PARAGRAPH_ALIGNMENT_CENTER
end enum

'/// Word wrapping in multiline paragraph.
TYPE DWRITE_WORD_WRAPPING AS LONG
enum
   ' /// Words are broken across lines to avoid text overflowing the layout box.
   DWRITE_WORD_WRAPPING_WRAP = 0
   ' /// Words are kept within the same line even when it overflows the layout box.
   ' /// This option is often used with scrolling to reveal overflow text.
   DWRITE_WORD_WRAPPING_NO_WRAP = 1
   ' /// Words are broken across lines to avoid text overflowing the layout box.
   ' /// Emergency wrapping occurs if the word is larger than the maximum width.
   DWRITE_WORD_WRAPPING_EMERGENCY_BREAK = 2
   ' /// Only wrap whole words, never breaking words (emergency wrapping) when the
   ' /// layout width is too small for even a single word.
   DWRITE_WORD_WRAPPING_WHOLE_WORD = 3
   ' /// Wrap between any valid characters clusters.
   DWRITE_WORD_WRAPPING_CHARACTER = 4
end enum

'/// The method used for line spacing in layout.
TYPE DWRITE_LINE_SPACING_METHOD AS LONG
enum
   ' /// Line spacing depends solely on the content, growing to accommodate the size of fonts and inline objects.
   DWRITE_LINE_SPACING_METHOD_DEFAULT
   ' /// Lines are explicitly set to uniform spacing, regardless of contained font sizes.
   ' /// This can be useful to avoid the uneven appearance that can occur from font fallback.
   DWRITE_LINE_SPACING_METHOD_UNIFORM
   ' /// Line spacing and baseline distances are proportional to the computed values based on the content, the size of the fonts and inline objects.
   DWRITE_LINE_SPACING_METHOD_PROPORTIONAL
end enum

'/// Text granularity used to trim text overflowing the layout box.
TYPE DWRITE_TRIMMING_GRANULARITY AS LONG
enum
   ' /// No trimming occurs. Text flows beyond the layout width.
   DWRITE_TRIMMING_GRANULARITY_NONE
   ' /// Trimming occurs at character cluster boundary.
   DWRITE_TRIMMING_GRANULARITY_CHARACTER
   ' /// Trimming occurs at word boundary.
   DWRITE_TRIMMING_GRANULARITY_WORD
end enum

'/// Typographic feature of text supplied by the font.
'/// Use DWRITE_MAKE_FONT_FEATURE_TAG() to create a custom one.
TYPE DWRITE_FONT_FEATURE_TAG AS LONG
enum
   DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS               = DWRITE_MAKE_OPENTYPE_TAG("a","f","r","c")
   DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS       = DWRITE_MAKE_OPENTYPE_TAG("c","2","p","c")
   DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS        = DWRITE_MAKE_OPENTYPE_TAG("c","2","s","c")
   DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES               = DWRITE_MAKE_OPENTYPE_TAG("c","a","l","t")
   DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS                = DWRITE_MAKE_OPENTYPE_TAG("c","a","s","e")
   DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION     = DWRITE_MAKE_OPENTYPE_TAG("c","c","m","p")
   DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES                = DWRITE_MAKE_OPENTYPE_TAG("c","l","i","g")
   DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING                     = DWRITE_MAKE_OPENTYPE_TAG("c","p","s","p")
   DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH                    = DWRITE_MAKE_OPENTYPE_TAG("c","s","w","h")
   DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING                 = DWRITE_MAKE_OPENTYPE_TAG("c","u","r","s")
   DWRITE_FONT_FEATURE_TAG_DEFAULT                             = DWRITE_MAKE_OPENTYPE_TAG("d","f","l","t")
   DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES             = DWRITE_MAKE_OPENTYPE_TAG("d","l","i","g")
   DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS                        = DWRITE_MAKE_OPENTYPE_TAG("e","x","p","t")
   DWRITE_FONT_FEATURE_TAG_FRACTIONS                           = DWRITE_MAKE_OPENTYPE_TAG("f","r","a","c")
   DWRITE_FONT_FEATURE_TAG_FULL_WIDTH                          = DWRITE_MAKE_OPENTYPE_TAG("f","w","i","d")
   DWRITE_FONT_FEATURE_TAG_HALF_FORMS                          = DWRITE_MAKE_OPENTYPE_TAG("h","a","l","f")
   DWRITE_FONT_FEATURE_TAG_HALANT_FORMS                        = DWRITE_MAKE_OPENTYPE_TAG("h","a","l","n")
   DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH                = DWRITE_MAKE_OPENTYPE_TAG("h","a","l","t")
   DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS                    = DWRITE_MAKE_OPENTYPE_TAG("h","i","s","t")
   DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES          = DWRITE_MAKE_OPENTYPE_TAG("h","k","n","a")
   DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES                = DWRITE_MAKE_OPENTYPE_TAG("h","l","i","g")
   DWRITE_FONT_FEATURE_TAG_HALF_WIDTH                          = DWRITE_MAKE_OPENTYPE_TAG("h","w","i","d")
   DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS                    = DWRITE_MAKE_OPENTYPE_TAG("h","o","j","o")
   DWRITE_FONT_FEATURE_TAG_JIS04_FORMS                         = DWRITE_MAKE_OPENTYPE_TAG("j","p","0","4")
   DWRITE_FONT_FEATURE_TAG_JIS78_FORMS                         = DWRITE_MAKE_OPENTYPE_TAG("j","p","7","8")
   DWRITE_FONT_FEATURE_TAG_JIS83_FORMS                         = DWRITE_MAKE_OPENTYPE_TAG("j","p","8","3")
   DWRITE_FONT_FEATURE_TAG_JIS90_FORMS                         = DWRITE_MAKE_OPENTYPE_TAG("j","p","9","0")
   DWRITE_FONT_FEATURE_TAG_KERNING                             = DWRITE_MAKE_OPENTYPE_TAG("k","e","r","n")
   DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES                  = DWRITE_MAKE_OPENTYPE_TAG("l","i","g","a")
   DWRITE_FONT_FEATURE_TAG_LINING_FIGURES                      = DWRITE_MAKE_OPENTYPE_TAG("l","n","u","m")
   DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS                     = DWRITE_MAKE_OPENTYPE_TAG("l","o","c","l")
   DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING                    = DWRITE_MAKE_OPENTYPE_TAG("m","a","r","k")
   DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK                  = DWRITE_MAKE_OPENTYPE_TAG("m","g","r","k")
   DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING            = DWRITE_MAKE_OPENTYPE_TAG("m","k","m","k")
   DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS          = DWRITE_MAKE_OPENTYPE_TAG("n","a","l","t")
   DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS                     = DWRITE_MAKE_OPENTYPE_TAG("n","l","c","k")
   DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES                   = DWRITE_MAKE_OPENTYPE_TAG("o","n","u","m")
   DWRITE_FONT_FEATURE_TAG_ORDINALS                            = DWRITE_MAKE_OPENTYPE_TAG("o","r","d","n")
   DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH        = DWRITE_MAKE_OPENTYPE_TAG("p","a","l","t")
   DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS                     = DWRITE_MAKE_OPENTYPE_TAG("p","c","a","p")
   DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES                = DWRITE_MAKE_OPENTYPE_TAG("p","n","u","m")
   DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS                 = DWRITE_MAKE_OPENTYPE_TAG("p","w","i","d")
   DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS                      = DWRITE_MAKE_OPENTYPE_TAG("q","w","i","d")
   DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES                  = DWRITE_MAKE_OPENTYPE_TAG("r","l","i","g")
   DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS                 = DWRITE_MAKE_OPENTYPE_TAG("r","u","b","y")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES                = DWRITE_MAKE_OPENTYPE_TAG("s","a","l","t")
   DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS                = DWRITE_MAKE_OPENTYPE_TAG("s","i","n","f")
   DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS                      = DWRITE_MAKE_OPENTYPE_TAG("s","m","c","p")
   DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS                    = DWRITE_MAKE_OPENTYPE_TAG("s","m","p","l")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","1")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","2")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","3")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","4")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","5")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","6")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","7")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","8")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9                     = DWRITE_MAKE_OPENTYPE_TAG("s","s","0","9")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","0")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","1")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","2")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","3")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","4")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","5")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","6")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","7")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","8")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","1","9")
   DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20                    = DWRITE_MAKE_OPENTYPE_TAG("s","s","2","0")
   DWRITE_FONT_FEATURE_TAG_SUBSCRIPT                           = DWRITE_MAKE_OPENTYPE_TAG("s","u","b","s")
   DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT                         = DWRITE_MAKE_OPENTYPE_TAG("s","u","p","s")
   DWRITE_FONT_FEATURE_TAG_SWASH                               = DWRITE_MAKE_OPENTYPE_TAG("s","w","s","h")
   DWRITE_FONT_FEATURE_TAG_TITLING                             = DWRITE_MAKE_OPENTYPE_TAG("t","i","t","l")
   DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS              = DWRITE_MAKE_OPENTYPE_TAG("t","n","a","m")
   DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES                     = DWRITE_MAKE_OPENTYPE_TAG("t","n","u","m")
   DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS                   = DWRITE_MAKE_OPENTYPE_TAG("t","r","a","d")
   DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS                        = DWRITE_MAKE_OPENTYPE_TAG("t","w","i","d")
   DWRITE_FONT_FEATURE_TAG_UNICASE                             = DWRITE_MAKE_OPENTYPE_TAG("u","n","i","c")
   DWRITE_FONT_FEATURE_TAG_VERTICAL_WRITING                    = DWRITE_MAKE_OPENTYPE_TAG("v","e","r","t")
   DWRITE_FONT_FEATURE_TAG_VERTICAL_ALTERNATES_AND_ROTATION    = DWRITE_MAKE_OPENTYPE_TAG("v","r","t","2")
   DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO                        = DWRITE_MAKE_OPENTYPE_TAG("z","e","r","o")
end enum

'/// The DWRITE_TEXT_RANGE structure specifies a range of text positions where format is applied.
type DWRITE_TEXT_RANGE
   ' /// The start text position of the range.
   AS UINT32 startPosition
   ' /// The number of text positions in the range.
   AS UINT32 length
end type

'/// The DWRITE_FONT_FEATURE structure specifies properties used to identify and execute typographic feature in the font.
type DWRITE_FONT_FEATURE
   ' /// The feature OpenType name identifier.
   AS DWRITE_FONT_FEATURE_TAG nameTag
   ' /// Execution parameter of the feature.
   ' /// The parameter should be non-zero to enable the feature.  Once enabled, a feature can't be disabled again within
   ' /// the same range.  Features requiring a selector use this value to indicate the selector index.
   AS UINT32 parameter
end type

'/// Defines a set of typographic features to be applied during shaping.
'/// Notice the character range which this feature list spans is specified
'/// as a separate parameter to GetGlyphs.
type DWRITE_TYPOGRAPHIC_FEATURES
   ' /// Array of font features.
   AS DWRITE_FONT_FEATURE PTR features
   ' /// The number of features.
   AS UINT32 featureCount
end type

'/// The DWRITE_TRIMMING structure specifies the trimming option for text overflowing the layout box.
type DWRITE_TRIMMING
   ' /// Text granularity of which trimming applies.
   AS DWRITE_TRIMMING_GRANULARITY granularity
   ' /// Character code used as the delimiter signaling the beginning of the portion of text to be preserved,
   ' /// most useful for path ellipsis, where the delimiter would be a slash. Leave this zero if there is no delimiter.
   AS UINT32 delimiter
   ' /// How many occurrences of the delimiter to step back. Leave this zero if there is no delimiter.
   AS UINT32 delimiterCount
end type

' ########################################################################################
' Interface name: IDWriteTextFormat
' IID: {9C906818-31D7-4FD3-A151-7C5E225DB55A}
' Documentation string: The format of text used for text layout purpose.
' Inherited interface = IUnknown
' The format of text used for text layout.
' This object may not be thread-safe and it may carry the state of text format change.
' ########################################################################################

#ifndef __IDWriteTextFormat_INTERFACE_DEFINED__
#define __IDWriteTextFormat_INTERFACE_DEFINED__

TYPE IDWriteTextFormat_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION SetTextAlignment (BYVAL textAlignment AS DWRITE_TEXT_ALIGNMENT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetParagraphAlignment (BYVAL paragraphAlignment AS DWRITE_PARAGRAPH_ALIGNMENT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetWordWrapping (BYVAL wordWrapping AS DWRITE_WORD_WRAPPING) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetReadingDirection (BYVAL readingDirection AS DWRITE_READING_DIRECTION) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFlowDirection (BYVAL flowDirection AS DWRITE_FLOW_DIRECTION) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetIncrementalTabStop (BYVAL incrementalTabStop AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTrimming (BYVAL trimmingOptions AS DWRITE_TRIMMING PTR, BYVAL trimmingSign AS IDWriteInlineObject PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetLineSpacing (BYVAL lineSpacingMethod AS DWRITE_LINE_SPACING_METHOD, BYVAL LineSpacing AS FLOAT, BYVAL baseline AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTextAlignment () AS DWRITE_TEXT_ALIGNMENT
   DECLARE ABSTRACT FUNCTION GetParagraphAlignment () AS DWRITE_PARAGRAPH_ALIGNMENT
   DECLARE ABSTRACT FUNCTION GetWordWrapping () AS DWRITE_WORD_WRAPPING
   DECLARE ABSTRACT FUNCTION GetReadingDirection () AS DWRITE_READING_DIRECTION
   DECLARE ABSTRACT FUNCTION GetFlowDirection () AS DWRITE_FLOW_DIRECTION
   DECLARE ABSTRACT FUNCTION GetIncrementalTabStop () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetTrimming (BYVAL trimmingOptions AS DWRITE_TRIMMING PTR, BYREF trimmingSign AS IDWriteInlineObject PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLineSpacing (BYREF lineSpacingMethod AS DWRITE_LINE_SPACING_METHOD, _
           BYREF LineSpacing AS FLOAT, BYREF baseline AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontCollection (BYREF fontCollection AS IDWriteFontCollection PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFamilyNameLength () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontFamilyName (BYREF fontFamilyName AS WSTRING, BYVAL nameSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontWeight () AS DWRITE_FONT_WEIGHT
   DECLARE ABSTRACT FUNCTION GetFontStyle () AS DWRITE_FONT_STYLE
   DECLARE ABSTRACT FUNCTION GetFontStretch () AS DWRITE_FONT_STRETCH
   DECLARE ABSTRACT FUNCTION GetFontSize () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetLocaleNameLength () AS UINT32
   DECLARE ABSTRACT FUNCTION GetLocaleName (BYREF localeName AS WSTRING, BYVAL nameSize AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTypography
' IID: {55F1112B-1DC2-4B3C-9541-F46894ED85B6}
' Documentation string: Font typography setting.
' Inherited interface = IUnknown
' Font typography setting.
' ########################################################################################

#ifndef __IDWriteTypography_INTERFACE_DEFINED__
#define __IDWriteTypography_INTERFACE_DEFINED__

TYPE IDWriteTypography_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION AddFontFeature (BYVAL fontFeature AS DWRITE_FONT_FEATURE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFeatureCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontFeature (BYVAL fontFeatureIndex AS UINT32, BYREF fontFeature AS DWRITE_FONT_FEATURE) AS HRESULT
END TYPE

#endif

' ########################################################################################

TYPE DWRITE_SCRIPT_SHAPES AS LONG
enum
   ' /// No additional shaping requirement. Text is shaped with the writing system default behavior.
   DWRITE_SCRIPT_SHAPES_DEFAULT = 0
   ' /// Text should leave no visual on display i.e. control or format control characters.
   DWRITE_SCRIPT_SHAPES_NO_VISUAL = 1
end enum

' /// Association of text and its writing system script as well as some display attributes.
type DWRITE_SCRIPT_ANALYSIS
   ' /// Zero-based index representation of writing system script.
   AS UINT16 script
   ' /// Additional shaping requirement of text.
   AS DWRITE_SCRIPT_SHAPES shapes
end type

'/// Condition at the edges of inline object or text used to determine
'/// line-breaking behavior.
TYPE DWRITE_BREAK_CONDITION AS LONG
enum
   ' /// Whether a break is allowed is determined by the condition of the
   ' /// neighboring text span or inline object.
   DWRITE_BREAK_CONDITION_NEUTRAL
   ' /// A break is allowed, unless overruled by the condition of the
   ' /// neighboring text span or inline object, either prohibited by a
   ' /// May Not or forced by a Must.
   DWRITE_BREAK_CONDITION_CAN_BREAK
   ' /// There should be no break, unless overruled by a Must condition from
   ' /// the neighboring text span or inline object.
   DWRITE_BREAK_CONDITION_MAY_NOT_BREAK
   ' /// The break must happen, regardless of the condition of the adjacent
   ' /// text span or inline object.
   DWRITE_BREAK_CONDITION_MUST_BREAK
end enum

' /// Line breakpoint characteristics of a character.
type DWRITE_LINE_BREAKPOINT
   ' /// Breaking condition before the character.
   breakConditionBefore : 2 AS UBYTE
   ' /// Breaking condition after the character.
   breakConditionAfter  : 2 AS UBYTE
   ' /// The character is some form of whitespace, which may be meaningful for justification.
   isWhitespace         : 1 AS UBYTE
   ' /// The character is a soft hyphen, often used to indicate hyphenation points inside words.
   isSoftHyphen         : 1 AS UBYTE
   padding              : 2 AS UBYTE
end type


' /// How to apply number substitution on digits and related punctuation.
TYPE DWRITE_NUMBER_SUBSTITUTION_METHOD AS LONG
enum
   ' /// Specifies that the substitution method should be determined based
   ' /// on LOCALE_IDIGITSUBSTITUTION value of the specified text culture.
   DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE
   ' /// If the culture is Arabic or Farsi, specifies that the number shape
   ' /// depend on the context. Either traditional or nominal number shape
   ' /// are used depending on the nearest preceding strong character or (if
   ' /// there is none) the reading direction of the paragraph.
   DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL
   ' /// Specifies that code points &H30-&H39 are always rendered as nominal numeral
   ' /// shapes (ones of the European number), i.e., no substitution is performed.
   DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE
   ' /// Specifies that number are rendered using the national number shape
   ' /// as specified by the LOCALE_SNATIVEDIGITS value of the specified text culture.
   ' /// </summary>
   DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL
   ' /// Specifies that number are rendered using the traditional shape
   ' /// for the specified culture. For most cultures, this is the same as
   ' /// NativeNational. However, NativeNational results in Latin number
   ' /// for some Arabic cultures, whereas this value results in Arabic
   ' /// number for all Arabic cultures.
   DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL
end enum

' ########################################################################################
' Interface name: IDWriteNumberSubstitution
' IID: {14885CC9-BAB0-4F90-B6ED-5C366A2CD03D}
' Documentation string: Holds the appropriate digits and numeric punctuation for a given locale.
' Inherited interface = IUnknown
' /// Holds the appropriate digits and numeric punctuation for a given locale.
' ########################################################################################

#ifndef __IDWriteNumberSubstitution_INTERFACE_DEFINED__
#define __IDWriteNumberSubstitution_INTERFACE_DEFINED__

TYPE IDWriteNumberSubstitution_ EXTENDS Afx_IUnknown
   ' It has no additional methods
END TYPE

#endif

' ########################################################################################

' /// Shaping output properties per input character.
type DWRITE_SHAPING_TEXT_PROPERTIES
   ' /// This character can be shaped independently from the others
    isShapedAlone        : 1 AS UINT16
   ' /// Reserved for use by shaping engine.
    reserved1            : 1 AS UINT16
   ' /// Glyph shaping can be cut after this point without affecting shaping
   ' /// before or after it. Otherwise, splitting a call to GetGlyphs would
   ' /// cause a reflow of glyph advances and shapes.
    canBreakShapingAfter : 1 AS UINT16
   ' /// Reserved for use by shaping engine.
    reserved             : 13 AS UINT16
end type

' /// Shaping output properties per output glyph.
type DWRITE_SHAPING_GLYPH_PROPERTIES
   ' /// Justification class, whether to use spacing, kashidas, or
   ' /// another method. This exists for backwards compatibility
   ' /// with Uniscribe's SCRIPT_JUSTIFY enum.
   justification        : 4 AS UINT16
   ' /// Indicates glyph is the first of a cluster.
   isClusterStart       : 1 AS UINT16
   ' /// Glyph is a diacritic.
   isDiacritic          : 1 AS UINT16
   ' /// Glyph has no width, mark, ZWJ, ZWNJ, ZWSP, LRM etc.
   ' /// This flag is not limited to just U+200B.
   isZeroWidthSpace     : 1 AS UINT16
   ' /// Reserved for use by shaping engine.
   reserved             : 9 AS UINT16
end type

' ########################################################################################
' Interface name: IDWriteTextAnalysisSource
' IID: {688E1A58-5094-47C8-ADC8-FBCEA60AE92B}
' Documentation string: The interface implemented by the text analyzer's client to provide text to the analyzer.
' Inherited interface = IUnknown
' The interface implemented by the text analyzer's client to provide text to the analyzer.
' ########################################################################################

#ifndef __IDWriteTextAnalysisSource_INTERFACE_DEFINED__
#define __IDWriteTextAnalysisSource_INTERFACE_DEFINED__

TYPE IDWriteTextAnalysisSource_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetTextAtPosition (BYVAL textPosition AS UINT32, BYREF textString AS WSTRING PTR, BYREF textLength AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTextBeforePosition (BYVAL textPosition AS UINT32, BYREF textString AS WSTRING PTR, BYREF textLength AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetParagraphReadingDirection () AS DWRITE_READING_DIRECTION
   DECLARE ABSTRACT FUNCTION GetLocaleName (BYVAL textPosition AS UINT32, BYREF textLength AS UINT32, BYREF localeName AS WSTRING PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetNumberSubstitution (BYVAL textPosition AS UINT32, BYREF textLength AS UINT32, BYREF numberSubstitution AS IDWriteNumberSubstitution PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextAnalysisSink
' IID: {5810CD44-0CA0-4701-B3FA-BEC5182AE4F6}
' Documentation string: The interface implemented by the text analyzer's client to receive the output of a given text analysis.
' Inherited interface = IUnknown
' The interface implemented by the text analyzer's client to receive the output of a given text analysis.
' ########################################################################################

#ifndef __IDWriteTextAnalysisSink_INTERFACE_DEFINED__
#define __IDWriteTextAnalysisSink_INTERFACE_DEFINED__

TYPE IDWriteTextAnalysisSink_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION SetScriptAnalysis (BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYREF scriptAnalysis AS const DWRITE_SCRIPT_ANALYSIS) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetLineBreakpoints (BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYREF lineBreakpoints AS const DWRITE_LINE_BREAKPOINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetBidiLevel (BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYVAL explicitLevel AS UBYTE, BYVAL resolvedLevel AS UBYTE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetNumberSubstitution (BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYVAL numberSubstitution AS IDWriteNumberSubstitution PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextAnalyzer
' IID: {B7E6163E-7F46-43B4-84B3-E4E6249C365D}
' Documentation string: Analyzes various text properties for complex script processing.
' Inherited interface = IUnknown
' Analyzes various text properties for complex script processing.
' ########################################################################################

#ifndef __IDWriteTextAnalyzer_INTERFACE_DEFINED__
#define __IDWriteTextAnalyzer_INTERFACE_DEFINED__

TYPE IDWriteTextAnalyzer_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION AnalyzeScript (BYVAL analysisSource AS IDWriteTextAnalysisSource PTR, BYVAL textPosition AS UINT32, _
           BYVAL textLength AS UINT32, BYVAL analysisSink AS IDWriteTextAnalysisSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AnalyzeBidi (BYVAL analysisSource AS IDWriteTextAnalysisSource PTR, BYVAL textPosition AS UINT32, _
           BYVAL textLength AS UINT32, BYVAL analysisSink AS IDWriteTextAnalysisSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AnalyzeNumberSubstitution (BYVAL analysisSource AS IDWriteTextAnalysisSource PTR, BYVAL textPosition AS UINT32, _
           BYVAL textLength AS UINT32, BYVAL analysisSink AS IDWriteTextAnalysisSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AnalyzeLineBreakpoints (BYVAL analysisSource AS IDWriteTextAnalysisSource PTR, BYVAL textPosition AS UINT32, _
           BYVAL textLength AS UINT32, BYVAL analysisSink AS IDWriteTextAnalysisSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphs (BYREF textString AS const WSTRING, BYVAL textLength AS UINT32, BYVAL fontFace AS IDWriteFontFace PTR, _
           BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN, BYREF scriptAnalysis AS const DWRITE_SCRIPT_ANALYSIS, _
           BYREF localeName AS const WSTRING, BYVAL numberSubstitution AS IDWriteNumberSubstitution PTR, _
           BYREF features AS const DWRITE_TYPOGRAPHIC_FEATURES PTR, BYREF featureRangeLengths AS const UINT32, _
           BYVAL featureRanges AS UINT32, BYVAL maxGlyphCount AS UINT32, BYREF clusterMap AS UINT16, BYREF textProps AS DWRITE_SHAPING_TEXT_PROPERTIES, _
           BYREF glyphIndices AS UINT16, BYREF glyphProps AS DWRITE_SHAPING_GLYPH_PROPERTIES, BYREF actualGlyphCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphPlacements (BYREF textString AS const WSTRING, BYREF clusterMap AS const UINT16, _
           BYREF textProps AS DWRITE_SHAPING_TEXT_PROPERTIES, BYVAL textLength AS UINT32, BYREF glyphIndices AS const UINT16, _
           BYREF glyphProps AS DWRITE_SHAPING_GLYPH_PROPERTIES, BYVAL glyphCount AS UINT32, BYVAL fontFace AS IDWriteFontFace PTR, _
           BYVAL fontEmSize AS FLOAT, BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN, BYVAL scriptAnalysis AS const DWRITE_SCRIPT_ANALYSIS PTR, _
           BYREF localeName AS const WSTRING, BYREF features AS const DWRITE_TYPOGRAPHIC_FEATURES PTR, _
           BYREF featureRangeLengths AS const UINT32, BYVAL featureRanges AS UINT32, BYREF glyphAdvances AS FLOAT, _
           BYREF glyphOffsets AS DWRITE_GLYPH_OFFSET) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGdiCompatibleGlyphPlacements (BYREF textString AS const WSTRING, BYREF clusterMap AS UINT16, _
           BYREF textProps AS DWRITE_SHAPING_TEXT_PROPERTIES, BYVAL textLength AS UINT32, BYREF glyphIndices AS const UINT16, _
           BYREF glyphProps AS const DWRITE_SHAPING_GLYPH_PROPERTIES, BYVAL glyphCount AS UINT32, BYVAL fontFace AS IDWriteFontFace PTR, _
           BYVAL fontEmSize AS FLOAT, BYVAL pixelsPerDip AS FLOAT, BYVAL transform AS ANY PTR, BYVAL useGdiNatural AS BOOLEAN, _
           BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEaN, BYREF scriptAnalysis AS const DWRITE_SCRIPT_ANALYSIS, _
           BYREF localeName AS const WSTRING, BYREF features AS const DWRITE_TYPOGRAPHIC_FEATURES PTR, _
           BYREF featureRangeLengths AS const UINT32, BYVAL featureRanges AS UINT32, BYREF glyphAdvances AS FLOAT, _
           BYREF glyphOffsets AS DWRITE_GLYPH_OFFSET) AS HRESULT
END TYPE

#endif

' ########################################################################################


#ifndef DWRITE_GLYPH_RUN
' /// The DWRITE_GLYPH_RUN structure contains the information needed by renderers
' /// to draw glyph runs. All coordinates are in device independent pixels (DIPs).
type DWRITE_GLYPH_RUN
   ' /// The physical font face to draw with.
   AS IDWriteFontFace PTR fontFace
   ' /// Logical size of the font in DIPs, not points (equals 1/96 inch).
   AS FLOAT fontEmSize
   ' /// The number of glyphs.
   AS UINT32 glyphCount
   ' /// The indices to render.
   AS UINT16 const PTR glyphIndices
   ' /// Glyph advance widths.
   AS FLOAT const PTR glyphAdvances
   ' /// Glyph offsets.
   AS DWRITE_GLYPH_OFFSET const PTR glyphOffsets
   ' /// If true, specifies that glyphs are rotated 90 degrees to the left and
   ' /// vertical metrics are used. Vertical writing is achieved by specifying
   ' /// isSideways = true and rotating the entire run 90 degrees to the right
   ' /// via a rotate transform.
   AS BOOL isSideways
   ' /// The implicit resolved bidi level of the run. Odd levels indicate
   ' /// right-to-left languages like Hebrew and Arabic, while even levels
   ' /// indicate left-to-right languages like English and Japanese (when
   ' /// written horizontally). For right-to-left languages, the text origin
   ' /// is on the right, and text should be drawn to the left.
   AS UINT32 bidiLevel
end type
#endif

#ifndef DWRITE_GLYPH_RUN
' /// The DWRITE_GLYPH_RUN_DESCRIPTION structure contains additional properties
' /// related to those in DWRITE_GLYPH_RUN.
type DWRITE_GLYPH_RUN_DESCRIPTION
   ' /// The locale name associated with this run.
   AS WTRING const PTR localeName
   ' /// The text associated with the glyphs.
   AS WSTRING const PTR string
   ' /// The number of characters (UTF16 code-units).
   ' /// Note that this may be different than the number of glyphs.
   AS UINT32 stringLength
   ' /// An array of indices to the glyph indices array, of the first glyphs of
   ' /// all the glyph clusters of the glyphs to render.
   AS UINT16 const PTR clusterMap
   ' /// Corresponding text position in the original string
   ' /// this glyph run came from.
   AS UINT32 textPosition
end type
#endif

'/// The DWRITE_UNDERLINE structure contains information about the size and
'/// placement of underlines. All coordinates are in device independent
'/// pixels (DIPs).
#ifndef DWRITE_UNDERLINE
type DWRITE_UNDERLINE
   ' /// Width of the underline, measured parallel to the baseline.
   AS FLOAT width
   ' /// Thickness of the underline, measured perpendicular to the baseline.
   AS FLOAT thickness
   ' /// Offset of the underline from the baseline.
   ' /// A positive offset represents a position below the baseline and
   ' /// a negative offset is above.
   AS FLOAT offset
   ' /// Height of the tallest run where the underline applies.
   AS FLOAT runHeight
   ' /// Reading direction of the text associated with the underline.  This
   ' /// value is used to interpret whether the width value runs horizontally
   ' /// or vertically.
   AS DWRITE_READING_DIRECTION readingDirection
   ' /// Flow direction of the text associated with the underline.  This value
   ' /// is used to interpret whether the thickness value advances top to
   ' /// bottom, left to right, or right to left.
   AS DWRITE_FLOW_DIRECTION flowDirection
   ' /// Locale of the text the underline is being drawn under. Can be
   ' /// pertinent where the locale affects how the underline is drawn.
   ' /// For example, in vertical text, the underline belongs on the
   ' /// left for Chinese but on the right for Japanese.
   ' /// This choice is completely left up to higher levels.
   AS WSTRING const PTR localeName
   ' /// The measuring mode can be useful to the renderer to determine how
   ' /// underlines are rendered, e.g. rounding the thickness to a whole pixel
   ' /// in GDI-compatible modes.
   AS DWRITE_MEASURING_MODE measuringMode
end type
#endif

'/// The DWRITE_STRIKETHROUGH structure contains information about the size and
'/// placement of strikethroughs. All coordinates are in device independent
'/// pixels (DIPs).
#ifndef DWRITE_STRIKETHROUGH
type DWRITE_STRIKETHROUGH
   ' /// Width of the strikethrough, measured parallel to the baseline.
   AS FLOAT width
   ' /// Thickness of the strikethrough, measured perpendicular to the baseline.
   AS FLOAT thickness
   ' /// Offset of the strikethrough from the baseline.
   ' /// A positive offset represents a position below the baseline and
   ' /// a negative offset is above.
   AS FLOAT offset
   ' /// Reading direction of the text associated with the strikethrough.  This
   ' /// value is used to interpret whether the width value runs horizontally
   ' /// or vertically.
   AS DWRITE_READING_DIRECTION readingDirection
   ' /// Flow direction of the text associated with the strikethrough.  This
   ' /// value is used to interpret whether the thickness value advances top to
   ' /// bottom, left to right, or right to left.
   AS DWRITE_FLOW_DIRECTION flowDirection
   ' /// Locale of the range. Can be pertinent where the locale affects the style.
   AS WSTRING const PTR localeName
   ' /// The measuring mode can be useful to the renderer to determine how
   ' /// underlines are rendered, e.g. rounding the thickness to a whole pixel
   ' /// in GDI-compatible modes.
   AS DWRITE_MEASURING_MODE measuringMode
end type
#endif

' /// The DWRITE_LINE_METRICS structure contains information about a formatted line of text.
#ifndef DWRITE_LINE_METRICS
type DWRITE_LINE_METRICS
   ' /// The number of total text positions in the line.
   ' /// This includes any trailing whitespace and newline characters.
   AS UINT32 length
   ' /// The number of whitespace positions at the end of the line.  Newline
   ' /// sequences are considered whitespace.
   AS UINT32 trailingWhitespaceLength
   ' /// The number of characters in the newline sequence at the end of the line.
   ' /// If the count is zero, then the line was either wrapped or it is the end of the text.
   AS UINT32 newlineLength
   ' /// Height of the line as measured from top to bottom.
   AS FLOAT height
   ' /// Distance from the top of the line to its baseline.
   AS FLOAT baseline
   ' /// The line is trimmed.
   AS BOOL isTrimmed
end type
#endif

#ifndef DWRITE_CLUSTER_METRICS
' /// The DWRITE_CLUSTER_METRICS structure contains information about a glyph cluster.
type DWRITE_CLUSTER_METRICS
   ' /// The total advance width of all glyphs in the cluster.
   AS FLOAT width
   ' /// The number of text positions in the cluster.
   AS UINT16 length
   ' /// Indicate whether line can be broken right after the cluster.
   canWrapLineAfter : 1 AS UINT16
   ' /// Indicate whether the cluster corresponds to whitespace character.
   isWhitespace : 1 AS UINT16
   ' /// Indicate whether the cluster corresponds to a newline character.
   isNewline : 1 AS UINT16
   ' /// Indicate whether the cluster corresponds to soft hyphen character.
   isSoftHyphen : 1 AS UINT16
   ' /// Indicate whether the cluster is read from right to left.
   isRightToLeft : 1 AS UINT16
   padding : 11 AS UINT16
end type
#endif

#ifndef DWRITE_TEXT_METRICS
' /// Overall metrics associated with text after layout.
' /// All coordinates are in device independent pixels (DIPs).
type DWRITE_TEXT_METRICS
   ' /// Left-most point of formatted text relative to layout box
   ' /// (excluding any glyph overhang).
   AS FLOAT left
   ' /// Top-most point of formatted text relative to layout box
   ' /// (excluding any glyph overhang).
   AS FLOAT top
   ' /// The width of the formatted text ignoring trailing whitespace
   ' /// at the end of each line.
   AS FLOAT width
   ' /// The width of the formatted text taking into account the
   ' /// trailing whitespace at the end of each line.
   AS FLOAT widthIncludingTrailingWhitespace
   ' /// The height of the formatted text. The height of an empty string
   ' /// is determined by the size of the default font's line height.
   AS FLOAT height
   ' /// Initial width given to the layout. Depending on whether the text
   ' /// was wrapped or not, it can be either larger or smaller than the
   ' /// text content width.
   AS FLOAT layoutWidth
   ' /// Initial height given to the layout. Depending on the length of the
   ' /// text, it may be larger or smaller than the text content height.
   AS FLOAT layoutHeight
   ' /// The maximum reordering count of any line of text, used
   ' /// to calculate the most number of hit-testing boxes needed.
   ' /// If the layout has no bidirectional text or no text at all,
   ' /// the minimum level is 1.
   AS UINT32 maxBidiReorderingDepth
   ' /// Total number of lines.
   AS UINT32 lineCount
end type
#endif

#ifndef DWRITE_INLINE_OBJECT_METRICS
' /// Properties describing the geometric measurement of an
' /// application-defined inline object.
type DWRITE_INLINE_OBJECT_METRICS
   ' /// Width of the inline object.
   AS FLOAT width
   ' /// Height of the inline object as measured from top to bottom.
   AS FLOAT height
   ' /// Distance from the top of the object to the baseline where it is lined up with the adjacent text.
   ' /// If the baseline is at the bottom, baseline simply equals height.
   AS FLOAT baseline
   ' /// Flag indicating whether the object is to be placed upright or alongside the text baseline
   ' /// for vertical text.
   AS BOOL  supportsSideways
end type
#endif


'/// The DWRITE_OVERHANG_METRICS structure holds how much any visible pixels
'/// (in DIPs) overshoot each side of the layout or inline objects.
'/// Positive overhangs indicate that the visible area extends outside the layout
'/// box or inline object, while negative values mean there is whitespace inside.
'/// The returned values are unaffected by rendering transforms or pixel snapping.
'/// Additionally, they may not exactly match final target's pixel bounds after
'/// applying grid fitting and hinting.
#ifndef DWRITE_OVERHANG_METRICS
type DWRITE_OVERHANG_METRICS
   ' /// The distance from the left-most visible DIP to its left alignment edge.
   AS FLOAT left
   ' /// The distance from the top-most visible DIP to its top alignment edge.
   AS FLOAT top
   ' /// The distance from the right-most visible DIP to its right alignment edge.
   AS FLOAT right
   ' /// The distance from the bottom-most visible DIP to its bottom alignment edge.
   AS FLOAT bottom
end type
#endif

#ifndef DWRITE_HIT_TEST_METRICS
' /// Geometry enclosing of text positions.
type DWRITE_HIT_TEST_METRICS
   ' /// First text position within the geometry.
   AS UINT32 textPosition
   ' /// Number of text positions within the geometry.
   AS UINT32 length
   ' /// Left position of the top-left coordinate of the geometry.
   AS FLOAT left
   ' /// Top position of the top-left coordinate of the geometry.
   AS FLOAT top
   ' /// Geometry's width.
   AS FLOAT width
   ' /// Geometry's height.
   AS FLOAT height
   ' /// Bidi level of text positions enclosed within the geometry.
   AS UINT32 bidiLevel
   ' /// Geometry encloses text?
   AS BOOL isText
   ' /// Range is trimmed.
   AS BOOL isTrimmed
end type
#endif


' ########################################################################################
' Interface name: IDWriteInlineObject
' IID: {8339FDE3-106F-47AB-8373-1C6295EB10B3}
' Documentation string: The IDWriteInlineObject interface wraps an application defined inline graphic, allowing DWrite to query metrics as if it was a glyph inline with the text.
' Inherited interface = IUnknown
' The IDWriteInlineObject interface wraps an application defined inline graphic,
' allowing DWrite to query metrics as if it was a glyph inline with the text.
' ########################################################################################

#ifndef __IDWriteInlineObject_INTERFACE_DEFINED__
#define __IDWriteInlineObject_INTERFACE_DEFINED__

TYPE IDWriteInlineObject_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION Draw (BYVAL clientDrawingContext AS ANY PTR, BYVAL renderer AS IDWriteTextRenderer PTR, _
           BYVAL originX AS FLOAT, BYVAL originY AS FLOAT, BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN, _
           BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetrics (BYREF metrics AS DWRITE_INLINE_OBJECT_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetOverhangMetrics (BYREF overhangs AS DWRITE_OVERHANG_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBreakConditions (BYREF breakConditionBefore AS DWRITE_BREAK_CONDITION, _
           BYREF breakConditionAfter AS DWRITE_BREAK_CONDITION) AS HRESULT

END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWritePixelSnapping
' IID: {EAF3A2DA-ECF4-4D24-B644-B34F6842024B}
' Documentation string: The IDWritePixelSnapping interface defines the pixel snapping properties of a text renderer.
' Inherited interface = IUnknown
' The IDWritePixelSnapping interface defines the pixel snapping properties of a text renderer.
' ########################################################################################

#ifndef __IDWritePixelSnapping_INTERFACE_DEFINED__
#define __IDWritePixelSnapping_INTERFACE_DEFINED__

TYPE IDWritePixelSnapping_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION IsPixelSnappingDisabled (BYVAL clientDrawingContext AS ANY PTR, BYREF IsDisabled AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCurrentTransform (BYVAL clientDrawingContext AS ANY PTR, BYREF transform AS DWRITE_MATRIX) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPixelsPerDip (BYVAL clientDrawingContext AS ANY PTR, BYREF pixelsPerDip AS FLOAT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextRenderer
' IID: {EF8A8135-5CC6-45FE-8825-C5A0724EB819}
' Documentation string: The IDWriteTextLayout interface represents a set of application-defined callbacks that perform rendering of text, inline objects, and decorations such as underlines.
' Inherited interface = IDWritePixelSnapping
' The IDWriteTextRenderer interface represents a set of application-defined callbacks that
' perform rendering of text, inline objects, and decorations such as underlines.
' ########################################################################################

#ifndef __IDWriteTextRenderer_INTERFACE_DEFINED__
#define __IDWriteTextRenderer_INTERFACE_DEFINED__

TYPE IDWriteTextRenderer_ EXTENDS IDWritePixelSnapping
   DECLARE ABSTRACT FUNCTION DrawGlyphRun (BYVAL clientDrawingContext AS ANY PTR, BYVAL baselineOriginX AS FLOAT, _
           BYVAL baselineOriginY AS FLOAT, BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF glyphRun AS DWRITE_GLYPH_RUN, _
           BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawUnderline (BYVAL clientDrawingContext AS ANY PTR, BYVAL baselineOriginX AS FLOAT, _
           BYVAL baselineOriginY AS FLOAT, BYREF Underline AS const DWRITE_UNDERLINE, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawStrikethrough (BYVAL clientDrawingContext AS ANY PTR, BYVAL baselineOriginX AS FLOAT, _
           BYVAL baselineOriginY AS FLOAT, BYREF StrikeThrough AS DWRITE_STRIKETHROUGH, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawInlineObject (BYVAL clientDrawingContext AS ANY PTR, BYVAL originX AS FLOAT, BYVAL originY AS FLOAT, _
           BYVAL inlineObject AS IDWriteInlineObject PTR, BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextLayout
' IID: {53737037-6D14-410B-9BFE-0B182BB70961}
' Documentation string: The IDWriteTextLayout interface represents a block of text after it has been fully analyzed and formatted.
' Inherited interface = IDWriteTextFormat
' ########################################################################################

#ifndef __IDWriteTextLayout_INTERFACE_DEFINED__
#define __IDWriteTextLayout_INTERFACE_DEFINED__

TYPE IDWriteTextLayout_ EXTENDS IDWriteTextFormat
   DECLARE ABSTRACT FUNCTION SetMaxWidth (BYVAL maxWidth AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetMaxHeight (BYVAL maxHeight AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFontCollection (BYVAL fontCollection AS IDWriteFontCollection PTR, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFontFamilyName (BYREF fontFamilyName AS const WSTRING, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFontWeight (BYVAL fontWeight AS DWRITE_FONT_WEIGHT, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFontStyle (BYVAL fontStyle AS DWRITE_FONT_STYLE, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFontStretch (BYVAL fontStretch AS DWRITE_FONT_STRETCH, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFontSize (BYVAL fontSize AS FLOAT, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetUnderline (BYVAL hasUnderline AS BOOLEAN, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetStrikethrough (BYVAL hasStrikethrough AS BOOLEAN, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetDrawingEffect (BYVAL drawingEffect AS IUnknown PTR, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetInlineObject (BYVAL inlineObject AS IDWriteInlineObject PTR, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTypography (BYVAL typography AS IDWriteTypography PTR, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetLocaleName (BYREF localeName AS const WSTRING, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMaxWidth () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetMaxHeight () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetFontCollection (BYVAL currentPosition AS UINT32, BYREF fontCollection AS IDWriteFontCollection PTR, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFamilyNameLength (BYVAL currentPosition AS UINT32, BYREF nameLength AS UINT32, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFamilyName (BYVAL currentPosition AS UINT32, BYREF fontFamilyName AS WSTRING, _
           BYVAL nameSize AS UINT32, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontWeight (BYVAL currentPosition AS UINT32, BYREF fontWeight AS DWRITE_FONT_WEIGHT, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontStyle (BYVAL currentPosition AS UINT32, BYREF fontStyle AS DWRITE_FONT_STYLE, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontStretch (BYVAL currentPosition AS UINT32, BYREF fontStretch AS DWRITE_FONT_STRETCH, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontSize (BYVAL currentPosition AS UINT32, BYREF fontSize AS FLOAT, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetUnderline (BYVAL currentPosition AS UINT32, BYREF hasUnderline AS BOOLEAN, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetStrikethrough (BYVAL currentPosition AS UINT32, BYREF hasStrikethrough AS BOOLEAN, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDrawingEffect (BYVAL currentPosition AS UINT32, BYREF drawingEffect AS IUnknown PTR, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetInlineObject (BYVAL currentPosition AS UINT32, BYREF inlineObject AS IDWriteInlineObject PTR, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTypography (BYVAL currentPosition AS UINT32, BYREF typography AS IDWriteTypography PTR, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocaleNameLength (BYVAL currentPosition AS UINT32, BYREF nameLength AS UINT32, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocaleName (BYVAL currentPosition AS UINT32, BYREF localeName AS WSTRING, BYVAL nameSize AS UINT32, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION Draw (BYVAL clientDrawingContext AS ANY PTR, BYVAL renderer AS IDWriteTextRenderer PTR, BYVAL originX AS FLOAT, BYVAL originY AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLineMetrics (BYREF lineMetrics AS DWRITE_LINE_METRICS, BYVAL maxLineCount AS UINT32, BYREF actualLineCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMetrics (BYREF textMetrics AS DWRITE_TEXT_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetOverhangMetrics (BYREF overhangs AS DWRITE_OVERHANG_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetClusterMetrics (BYREF clusterMetrics AS DWRITE_CLUSTER_METRICS, BYVAL maxClusterCount AS UINT32, BYREF actualClusterCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION DetermineMinWidth (BYREF minWidth AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION HitTestPoint (BYVAL pointX AS FLOAT, BYVAL pointY AS FLOAT, BYREF isTrailingHit AS BOOLEAN, BYREF isInside AS BOOLEAN, BYREF hitTestMetrics AS DWRITE_HIT_TEST_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION HitTestTextPosition (BYVAL textPosition AS UINT32, BYVAL isTrailingHit AS BOOLEAN, BYREF pointX AS FLOAT, _
           BYREF pointY AS FLOAT, BYREF hitTestMetrics AS DWRITE_HIT_TEST_METRICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION HitTestTextRange (BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYVAL originX AS FLOAT, _
           BYVAL originY AS FLOAT, BYREF hitTestMetrics AS DWRITE_HIT_TEST_METRICS, BYVAL maxHitTestMetricsCount AS UINT32, _
           BYREF actualHitTestMetricsCount AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteBitmapRenderTarget
' IID: {5E5A32A3-8DFF-4773-9FF6-0696EAB77267}
' Documentation string: Encapsulates a 32-bit device independent bitmap and device context, which can be used for rendering glyphs.
' Inherited interface = IUnknown
' Encapsulates a 32-bit device independent bitmap and device context, which can be used for rendering glyphs.
' ########################################################################################

#ifndef __IDWriteBitmapRenderTarget_INTERFACE_DEFINED__
#define __IDWriteBitmapRenderTarget_INTERFACE_DEFINED__

TYPE IDWriteBitmapRenderTarget_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION DrawGlyphRun (BYVAL baselineOriginX AS FLOAT, BYVAL baselineOriginY AS FLOAT, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF glyphRun AS DWRITE_GLYPH_RUN, _
           BYVAL renderingParams AS IDWriteRenderingParams PTR, BYVAL textColor AS COLORREF, BYREF blackBoxRect AS ..RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMemoryDC () AS ..HDC
   DECLARE ABSTRACT FUNCTION GetPixelsPerDip () AS FLOAT
   DECLARE ABSTRACT FUNCTION SetPixelsPerDip (BYVAL pixelsPerDip AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCurrentTransform (BYREF transform AS DWRITE_MATRIX) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetCurrentTransform (BYREF transform AS const DWRITE_MATRIX) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSize (BYREF size AS SIZE) AS HRESULT
   DECLARE ABSTRACT FUNCTION Resize (BYVAL width AS UINT32, BYVAL height AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteGdiInterop
' IID: {1EDD9491-9853-4299-898F-6432983B6F3A}
' Documentation string: The GDI interop interface provides interoperability with GDI.
' Inherited interface = IUnknown
' The GDI interop interface provides interoperability with GDI.
' ########################################################################################

#ifndef __IDWriteGdiInterop_INTERFACE_DEFINED__
#define __IDWriteGdiInterop_INTERFACE_DEFINED__

TYPE IDWriteGdiInterop_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CreateFontFromLOGFONT (BYREF logFont AS const LOGFONTW, BYREF font AS IDWriteFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION ConvertFontToLOGFONT (BYVAL font AS IDWriteFont PTR, BYREF logFont AS LOGFONTW, BYREF isSystemFont AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION ConvertFontFaceToLOGFONT (BYVAL font AS IDWriteFontFace PTR, BYREF logFont AS LOGFONTW) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFaceFromHdc (BYVAL hdc AS ..HDC, BYREF fontFace AS IDWriteFontFace PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapRenderTarget (BYVAL hdc AS ..HDC, BYVAL width AS UINT32, BYVAL Height AS UINT32, BYREF renderTarget AS IDWriteBitmapRenderTarget PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


'/// The DWRITE_TEXTURE_TYPE enumeration identifies a type of alpha texture. An alpha texture is a bitmap of alpha values, each
'/// representing the darkness (i.e., opacity) of a pixel or subpixel.
TYPE DWRITE_TEXTURE_TYPE AS LONG
enum
   ' /// Specifies an alpha texture for aliased text rendering (i.e., bi-level, where each pixel is either fully opaque or fully transparent),
   ' /// with one byte per pixel.
   DWRITE_TEXTURE_ALIASED_1x1
   ' /// Specifies an alpha texture for ClearType text rendering, with three bytes per pixel in the horizontal dimension and
   ' /// one byte per pixel in the vertical dimension.
   DWRITE_TEXTURE_CLEARTYPE_3x1
end enum

' /// Maximum alpha value in a texture returned by IDWriteGlyphRunAnalysis::CreateAlphaTexture.
#define DWRITE_ALPHA_MAX 255

' ########################################################################################
' Interface name: IDWriteGlyphRunAnalysis
' IID: {7D97DBF7-E085-42D4-81E3-6A883BDED118}
' Documentation string: Interface that encapsulates information used to render a glyph run.
' Inherited interface = IUnknown
' Interface that encapsulates information used to render a glyph run.
' ########################################################################################

#ifndef __IDWriteGlyphRunAnalysis_INTERFACE_DEFINED__
#define __IDWriteGlyphRunAnalysis_INTERFACE_DEFINED__

TYPE IDWriteGlyphRunAnalysis_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetAlphaTextureBounds (BYVAL textureType AS DWRITE_TEXTURE_TYPE, BYREF textureBounds AS ..RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateAlphaTexture (BYVAL textureType AS DWRITE_TEXTURE_TYPE, BYREF textureBounds AS const ..RECT, _
           BYVAL alphaValues AS BYTE PTR, BYVAL BufferSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetAlphaBlendParams (BYVAL renderingParams AS IDWriteRenderingParams PTR, BYREF blendGamma AS FLOAT, _
           BYREF blendEnhancedContrast AS FLOAT, BYREF blendClearTypeLevel AS FLOAT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory
' IID: {B859EE5A-D838-4B5B-A2E8-1ADC7D93DB48}
' Documentation string: The root factory interface for all DWrite objects.
' Inherited interface = IUnknown
' The root factory interface for all DWrite objects.
' ########################################################################################

#ifndef __IDWriteFactory_INTERFACE_DEFINED__
#define __IDWriteFactory_INTERFACE_DEFINED__

TYPE IDWriteFactory_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetSystemFontCollection (BYREF fontCollection AS IDWriteFontCollection PTR, BYVAL checkForUpdates AS BOOLEAN = FALSE) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCustomFontCollection (BYVAL collectionLoader AS IDWriteFontCollectionLoader PTR, _
           BYVAL collectionKey AS const ANY PTR, BYVAL collectionKeySize AS UINT32, BYREF fontCollection AS IDWriteFontCollection PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterFontCollectionLoader (BYVAL fontCollectionLoader AS IDWriteFontCollectionLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterFontCollectionLoader (BYVAL fontCollectionLoader AS IDWriteFontCollectionLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFileReference (BYREF filePath AS const WSTRING, BYREF lastWriteTime AS const FILETIME, BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCustomFontFileReference (BYVAL fontFileReferenceKey AS const ANY PTR, BYVAL fontFileReferenceKeySize AS UINT32, _
           BYVAL fontFileLoader AS IDWriteFontFileLoader PTR, BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFace (BYVAL fontFaceType AS DWRITE_FONT_FACE_TYPE, BYVAL numberOfFiles AS UINT32, _
           BYVAL fontFiles AS const IDWriteFontFile PTR, BYVAL faceIndex AS UINT32, BYVAL fontFaceSimulationFlags AS DWRITE_FONT_SIMULATIONS, _
           BYREF fontFace AS IDWriteFontFace PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateRenderingParams (BYREF renderingParams AS IDWriteRenderingParams PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateMonitorRenderingParams (BYVAL monitor AS ..HMONITOR, BYREF renderingParams AS IDWriteRenderingParams PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCustomRenderingParams (BYVAL gamma AS FLOAT, BYVAL enhancedContrast AS FLOAT, _
           BYVAL clearTypeLevel AS FLOAT, BYVAL pixelGeometry AS DWRITE_PIXEL_GEOMETRY, BYVAL renderingMode AS DWRITE_RENDERING_MODE, _
           BYREF renderingParams AS IDWriteRenderingParams PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterFontFileLoader (BYVAL fontFileLoader AS IDWriteFontFileLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterFontFileLoader (BYVAL fontFileLoader AS IDWriteFontFileLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTextFormat (BYREF fontFamilyName AS const WSTRING, BYVAL fontCollection AS IDWriteFontCollection PTR, _
           BYVAL fontWeight AS DWRITE_FONT_WEIGHT, BYVAL fontStyle AS DWRITE_FONT_STYLE, BYVAL fontStretch AS DWRITE_FONT_STRETCH, _
           BYVAL fontSize AS FLOAT, BYREF localeName AS const WSTRING, BYREF textFormat AS IDWriteTextFormat PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTypography (BYREF typography AS IDWriteTypography PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGdiInterop (BYREF gdiInterop AS IDWriteGdiInterop PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTextLayout (BYREF wszstring AS const WSTRING, BYVAL stringLength AS UINT32, _
           BYVAL textFormat AS IDWriteTextFormat PTR, BYVAL maxWidth AS FLOAT, BYVAL maxHeight AS FLOAT, _
           BYREF textLayout AS IDWriteTextLayout PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGdiCompatibleTextLayout (BYREF wszstring AS const WSTRING, BYVAL stringLength AS UINT32, _
           BYVAL textFormat AS IDWriteTextFormat PTR, BYVAL layoutWidth AS FLOAT, BYVAL layoutHeight AS FLOAT, _
           BYVAL pixelsPerDip AS FLOAT, BYREF transform AS const DWRITE_MATRIX, BYVAL useGdiNatural AS BOOLEAN, _
           BYREF textLayout AS IDWriteTextLayout PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateEllipsisTrimmingSign (BYVAL textFormat AS IDWriteTextFormat PTR, BYREF trimmingSign AS IDWriteInlineObject PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTextAnalyzer (BYREF textAnalyzer AS IDWriteTextAnalyzer PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateNumberSubstitution (BYVAL substitutionMethod AS DWRITE_NUMBER_SUBSTITUTION_METHOD, _
           BYREF localeName AS const WSTRING, BYVAL ignoreUserOverride AS BOOLEAN, BYREF numberSubstitution AS IDWriteNumberSubstitution PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGlyphRunAnalysis (BYREF glyphRun AS const DWRITE_GLYPH_RUN, BYVAL pixelsPerDip AS FLOAT, _
           BYREF transform AS const DWRITE_MATRIX, BYVAL renderingMode AS DWRITE_RENDERING_MODE, BYVAL measuringMode AS DWRITE_MEASURING_MODE, _
           BYVAL baselineOriginX AS FLOAT, BYVAL baselineOriginY AS FLOAT, BYREF glyphRunAnalysis AS IDWriteGlyphRunAnalysis PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ========================================================================================
' Creates a DirectWrite factory object that is used for subsequent creation of individual DirectWrite objects.
' ========================================================================================
#ifndef DWriteCreateFactory
DECLARE FUNCTION DWriteCreateFactory LIB "dwrite" ALIAS "DWriteCreateFactory" ( _
   BYVAL factoryType AS DWRITE_FACTORY_TYPE, BYREF iid AS IID, BYVAL factory AS IUnknown PTR) AS HRESULT
#endif
' ========================================================================================

'// Macros used to define DirectWrite error codes.
#define FACILITY_DWRITE &h898
#define DWRITE_ERR_BASE &H5000
#define MAKE_DWRITE_HR(severity, code) MAKE_HRESULT(severity, FACILITY_DWRITE, (DWRITE_ERR_BASE + code))
#define MAKE_DWRITE_HR_ERR(code) MAKE_DWRITE_HR(SEVERITY_ERROR, code)

'// DWrite errors have moved to winerror.h
#define DWRITE_E_FILEFORMAT               _HRESULT_TYPEDEF_(&H88985000)
#define DWRITE_E_UNEXPECTED               _HRESULT_TYPEDEF_(&H88985001)
#define DWRITE_E_NOFONT                   _HRESULT_TYPEDEF_(&H88985002)
#define DWRITE_E_FILENOTFOUND             _HRESULT_TYPEDEF_(&H88985003)
#define DWRITE_E_FILEACCESS               _HRESULT_TYPEDEF_(&H88985004)
#define DWRITE_E_FONTCOLLECTIONOBSOLETE   _HRESULT_TYPEDEF_(&H88985005)
#define DWRITE_E_ALREADYREGISTERED        _HRESULT_TYPEDEF_(&H88985006)
#define DWRITE_E_CACHEFORMAT              _HRESULT_TYPEDEF_(&H88985007)
#define DWRITE_E_CACHEVERSION             _HRESULT_TYPEDEF_(&H88985008)
#define DWRITE_E_UNSUPPORTEDOPERATION     _HRESULT_TYPEDEF_(&H88985009)
#define DWRITE_E_TEXTRENDERERINCOMPATIBLE _HRESULT_TYPEDEF_(&H8898500A)
#define DWRITE_E_FLOWDIRECTIONCONFLICTS   _HRESULT_TYPEDEF_(&H8898500B)
#define DWRITE_E_NOCOLOR                  _HRESULT_TYPEDEF_(&H8898500C)
#define DWRITE_E_REMOTEFONT               _HRESULT_TYPEDEF_(&H8898500D)
#define DWRITE_E_DOWNLOADCANCELLED        _HRESULT_TYPEDEF_(&H8898500E)
#define DWRITE_E_DOWNLOADFAILED           _HRESULT_TYPEDEF_(&H8898500F)
#define DWRITE_E_TOOMANYDOWNLOADS         _HRESULT_TYPEDEF_(&H88985010)


' ########################################################################################
'                                *** dwrite_1.h ***
' ########################################################################################

TYPE DWRITE_PANOSE_FAMILY AS LONG
enum
   DWRITE_PANOSE_FAMILY_ANY = 0
   DWRITE_PANOSE_FAMILY_NO_FIT = 1
   DWRITE_PANOSE_FAMILY_TEXT_DISPLAY = 2
   DWRITE_PANOSE_FAMILY_SCRIPT = 3  ' // or hand written
   DWRITE_PANOSE_FAMILY_DECORATIVE = 4
   DWRITE_PANOSE_FAMILY_SYMBOL = 5  ' // or symbol
   DWRITE_PANOSE_FAMILY_PICTORIAL = DWRITE_PANOSE_FAMILY_SYMBOL
end enum

TYPE DWRITE_PANOSE_SERIF_STYLE AS LONG
enum
   DWRITE_PANOSE_SERIF_STYLE_ANY = 0
   DWRITE_PANOSE_SERIF_STYLE_NO_FIT = 1
   DWRITE_PANOSE_SERIF_STYLE_COVE = 2
   DWRITE_PANOSE_SERIF_STYLE_OBTUSE_COVE = 3
   DWRITE_PANOSE_SERIF_STYLE_SQUARE_COVE = 4
   DWRITE_PANOSE_SERIF_STYLE_OBTUSE_SQUARE_COVE = 5
   DWRITE_PANOSE_SERIF_STYLE_SQUARE = 6
   DWRITE_PANOSE_SERIF_STYLE_THIN = 7
   DWRITE_PANOSE_SERIF_STYLE_OVAL = 8
   DWRITE_PANOSE_SERIF_STYLE_EXAGGERATED = 9
   DWRITE_PANOSE_SERIF_STYLE_TRIANGLE = 10
   DWRITE_PANOSE_SERIF_STYLE_NORMAL_SANS = 11
   DWRITE_PANOSE_SERIF_STYLE_OBTUSE_SANS = 12
   DWRITE_PANOSE_SERIF_STYLE_PERPENDICULAR_SANS = 13
   DWRITE_PANOSE_SERIF_STYLE_FLARED = 14
   DWRITE_PANOSE_SERIF_STYLE_ROUNDED = 15
   DWRITE_PANOSE_SERIF_STYLE_SCRIPT = 16
   DWRITE_PANOSE_SERIF_STYLE_PERP_SANS = DWRITE_PANOSE_SERIF_STYLE_PERPENDICULAR_SANS
   DWRITE_PANOSE_SERIF_STYLE_BONE = DWRITE_PANOSE_SERIF_STYLE_OVAL
end enum

TYPE DWRITE_PANOSE_WEIGHT AS LONG
enum
   DWRITE_PANOSE_WEIGHT_ANY = 0
   DWRITE_PANOSE_WEIGHT_NO_FIT = 1
   DWRITE_PANOSE_WEIGHT_VERY_LIGHT = 2
   DWRITE_PANOSE_WEIGHT_LIGHT = 3
   DWRITE_PANOSE_WEIGHT_THIN = 4
   DWRITE_PANOSE_WEIGHT_BOOK = 5
   DWRITE_PANOSE_WEIGHT_MEDIUM = 6
   DWRITE_PANOSE_WEIGHT_DEMI = 7
   DWRITE_PANOSE_WEIGHT_BOLD = 8
   DWRITE_PANOSE_WEIGHT_HEAVY = 9
   DWRITE_PANOSE_WEIGHT_BLACK = 10
   DWRITE_PANOSE_WEIGHT_EXTRA_BLACK = 11
   DWRITE_PANOSE_WEIGHT_NORD = DWRITE_PANOSE_WEIGHT_EXTRA_BLACK
end enum

TYPE DWRITE_PANOSE_PROPORTION AS LONG
enum
   DWRITE_PANOSE_PROPORTION_ANY = 0
   DWRITE_PANOSE_PROPORTION_NO_FIT = 1
   DWRITE_PANOSE_PROPORTION_OLD_STYLE = 2
   DWRITE_PANOSE_PROPORTION_MODERN = 3
   DWRITE_PANOSE_PROPORTION_EVEN_WIDTH = 4
   DWRITE_PANOSE_PROPORTION_EXPANDED = 5
   DWRITE_PANOSE_PROPORTION_CONDENSED = 6
   DWRITE_PANOSE_PROPORTION_VERY_EXPANDED = 7
   DWRITE_PANOSE_PROPORTION_VERY_CONDENSED = 8
   DWRITE_PANOSE_PROPORTION_MONOSPACED = 9
end enum

TYPE DWRITE_PANOSE_CONTRAST AS LONG
enum
   DWRITE_PANOSE_CONTRAST_ANY = 0
   DWRITE_PANOSE_CONTRAST_NO_FIT = 1
   DWRITE_PANOSE_CONTRAST_NONE = 2
   DWRITE_PANOSE_CONTRAST_VERY_LOW = 3
   DWRITE_PANOSE_CONTRAST_LOW = 4
   DWRITE_PANOSE_CONTRAST_MEDIUM_LOW = 5
   DWRITE_PANOSE_CONTRAST_MEDIUM = 6
   DWRITE_PANOSE_CONTRAST_MEDIUM_HIGH = 7
   DWRITE_PANOSE_CONTRAST_HIGH = 8
   DWRITE_PANOSE_CONTRAST_VERY_HIGH = 9
   DWRITE_PANOSE_CONTRAST_HORIZONTAL_LOW = 10
   DWRITE_PANOSE_CONTRAST_HORIZONTAL_MEDIUM = 11
   DWRITE_PANOSE_CONTRAST_HORIZONTAL_HIGH = 12
   DWRITE_PANOSE_CONTRAST_BROKEN = 13
end enum

TYPE DWRITE_PANOSE_STROKE_VARIATION AS LONG
enum
   DWRITE_PANOSE_STROKE_VARIATION_ANY = 0
   DWRITE_PANOSE_STROKE_VARIATION_NO_FIT = 1
   DWRITE_PANOSE_STROKE_VARIATION_NO_VARIATION = 2
   DWRITE_PANOSE_STROKE_VARIATION_GRADUAL_DIAGONAL = 3
   DWRITE_PANOSE_STROKE_VARIATION_GRADUAL_TRANSITIONAL = 4
   DWRITE_PANOSE_STROKE_VARIATION_GRADUAL_VERTICAL = 5
   DWRITE_PANOSE_STROKE_VARIATION_GRADUAL_HORIZONTAL = 6
   DWRITE_PANOSE_STROKE_VARIATION_RAPID_VERTICAL = 7
   DWRITE_PANOSE_STROKE_VARIATION_RAPID_HORIZONTAL = 8
   DWRITE_PANOSE_STROKE_VARIATION_INSTANT_VERTICAL = 9
   DWRITE_PANOSE_STROKE_VARIATION_INSTANT_HORIZONTAL = 10
end enum

TYPE DWRITE_PANOSE_ARM_STYLE AS LONG
enum
   DWRITE_PANOSE_ARM_STYLE_ANY = 0
   DWRITE_PANOSE_ARM_STYLE_NO_FIT = 1
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_HORIZONTAL = 2
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_WEDGE = 3
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_VERTICAL = 4
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_SINGLE_SERIF = 5
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_DOUBLE_SERIF = 6
   DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_HORIZONTAL = 7
   DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_WEDGE = 8
   DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_VERTICAL = 9
   DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_SINGLE_SERIF = 10
   DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_DOUBLE_SERIF = 11
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_HORZ = DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_HORIZONTAL
   DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_VERT = DWRITE_PANOSE_ARM_STYLE_STRAIGHT_ARMS_VERTICAL
   DWRITE_PANOSE_ARM_STYLE_BENT_ARMS_HORZ = DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_HORIZONTAL
   DWRITE_PANOSE_ARM_STYLE_BENT_ARMS_WEDGE = DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_WEDGE
   DWRITE_PANOSE_ARM_STYLE_BENT_ARMS_VERT = DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_VERTICAL
   DWRITE_PANOSE_ARM_STYLE_BENT_ARMS_SINGLE_SERIF = DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_SINGLE_SERIF
   DWRITE_PANOSE_ARM_STYLE_BENT_ARMS_DOUBLE_SERIF = DWRITE_PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_DOUBLE_SERIF
end enum

TYPE DWRITE_PANOSE_LETTERFORM AS LONG
enum
   DWRITE_PANOSE_LETTERFORM_ANY = 0
   DWRITE_PANOSE_LETTERFORM_NO_FIT = 1
   DWRITE_PANOSE_LETTERFORM_NORMAL_CONTACT = 2
   DWRITE_PANOSE_LETTERFORM_NORMAL_WEIGHTED = 3
   DWRITE_PANOSE_LETTERFORM_NORMAL_BOXED = 4
   DWRITE_PANOSE_LETTERFORM_NORMAL_FLATTENED = 5
   DWRITE_PANOSE_LETTERFORM_NORMAL_ROUNDED = 6
   DWRITE_PANOSE_LETTERFORM_NORMAL_OFF_CENTER = 7
   DWRITE_PANOSE_LETTERFORM_NORMAL_SQUARE = 8
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_CONTACT = 9
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_WEIGHTED = 10
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_BOXED = 11
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_FLATTENED = 12
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_ROUNDED = 13
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_OFF_CENTER = 14
   DWRITE_PANOSE_LETTERFORM_OBLIQUE_SQUARE = 15
end enum

TYPE DWRITE_PANOSE_MIDLINE AS LONG
enum
   DWRITE_PANOSE_MIDLINE_ANY = 0
   DWRITE_PANOSE_MIDLINE_NO_FIT = 1
   DWRITE_PANOSE_MIDLINE_STANDARD_TRIMMED = 2
   DWRITE_PANOSE_MIDLINE_STANDARD_POINTED = 3
   DWRITE_PANOSE_MIDLINE_STANDARD_SERIFED = 4
   DWRITE_PANOSE_MIDLINE_HIGH_TRIMMED = 5
   DWRITE_PANOSE_MIDLINE_HIGH_POINTED = 6
   DWRITE_PANOSE_MIDLINE_HIGH_SERIFED = 7
   DWRITE_PANOSE_MIDLINE_CONSTANT_TRIMMED = 8
   DWRITE_PANOSE_MIDLINE_CONSTANT_POINTED = 9
   DWRITE_PANOSE_MIDLINE_CONSTANT_SERIFED = 10
   DWRITE_PANOSE_MIDLINE_LOW_TRIMMED = 11
   DWRITE_PANOSE_MIDLINE_LOW_POINTED = 12
   DWRITE_PANOSE_MIDLINE_LOW_SERIFED = 13
end enum

TYPE DWRITE_PANOSE_XHEIGHT AS LONG
enum
   DWRITE_PANOSE_XHEIGHT_ANY = 0
   DWRITE_PANOSE_XHEIGHT_NO_FIT = 1
   DWRITE_PANOSE_XHEIGHT_CONSTANT_SMALL = 2
   DWRITE_PANOSE_XHEIGHT_CONSTANT_STANDARD = 3
   DWRITE_PANOSE_XHEIGHT_CONSTANT_LARGE = 4
   DWRITE_PANOSE_XHEIGHT_DUCKING_SMALL = 5
   DWRITE_PANOSE_XHEIGHT_DUCKING_STANDARD = 6
   DWRITE_PANOSE_XHEIGHT_DUCKING_LARGE = 7
   DWRITE_PANOSE_XHEIGHT_CONSTANT_STD = DWRITE_PANOSE_XHEIGHT_CONSTANT_STANDARD
   DWRITE_PANOSE_XHEIGHT_DUCKING_STD = DWRITE_PANOSE_XHEIGHT_DUCKING_STANDARD
end enum

TYPE DWRITE_PANOSE_TOOL_KIND AS LONG
enum
   DWRITE_PANOSE_TOOL_KIND_ANY = 0
   DWRITE_PANOSE_TOOL_KIND_NO_FIT = 1
   DWRITE_PANOSE_TOOL_KIND_FLAT_NIB = 2
   DWRITE_PANOSE_TOOL_KIND_PRESSURE_POINT = 3
   DWRITE_PANOSE_TOOL_KIND_ENGRAVED = 4
   DWRITE_PANOSE_TOOL_KIND_BALL = 5
   DWRITE_PANOSE_TOOL_KIND_BRUSH = 6
   DWRITE_PANOSE_TOOL_KIND_ROUGH = 7
   DWRITE_PANOSE_TOOL_KIND_FELT_PEN_BRUSH_TIP = 8
   DWRITE_PANOSE_TOOL_KIND_WILD_BRUSH = 9
end enum

TYPE DWRITE_PANOSE_SPACING AS LONG
ENUM
   DWRITE_PANOSE_SPACING_ANY = 0
   DWRITE_PANOSE_SPACING_NO_FIT = 1
   DWRITE_PANOSE_SPACING_PROPORTIONAL_SPACED = 2
   DWRITE_PANOSE_SPACING_MONOSPACED = 3
end enum

TYPE DWRITE_PANOSE_ASPECT_RATIO AS LONG
enum
   DWRITE_PANOSE_ASPECT_RATIO_ANY = 0
   DWRITE_PANOSE_ASPECT_RATIO_NO_FIT = 1
   DWRITE_PANOSE_ASPECT_RATIO_VERY_CONDENSED = 2
   DWRITE_PANOSE_ASPECT_RATIO_CONDENSED = 3
   DWRITE_PANOSE_ASPECT_RATIO_NORMAL = 4
   DWRITE_PANOSE_ASPECT_RATIO_EXPANDED = 5
   DWRITE_PANOSE_ASPECT_RATIO_VERY_EXPANDED = 6
end enum

TYPE DWRITE_PANOSE_SCRIPT_TOPOLOGY AS LONG
enum
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_ANY = 0
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_NO_FIT = 1
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_ROMAN_DISCONNECTED = 2
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_ROMAN_TRAILING = 3
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_ROMAN_CONNECTED = 4
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_CURSIVE_DISCONNECTED = 5
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_CURSIVE_TRAILING = 6
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_CURSIVE_CONNECTED = 7
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_BLACKLETTER_DISCONNECTED = 8
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_BLACKLETTER_TRAILING = 9
   DWRITE_PANOSE_SCRIPT_TOPOLOGY_BLACKLETTER_CONNECTED = 10
end enum

TYPE DWRITE_PANOSE_SCRIPT_FORM AS LONG
enum
   DWRITE_PANOSE_SCRIPT_FORM_ANY = 0
   DWRITE_PANOSE_SCRIPT_FORM_NO_FIT = 1
   DWRITE_PANOSE_SCRIPT_FORM_UPRIGHT_NO_WRAPPING = 2
   DWRITE_PANOSE_SCRIPT_FORM_UPRIGHT_SOME_WRAPPING = 3
   DWRITE_PANOSE_SCRIPT_FORM_UPRIGHT_MORE_WRAPPING = 4
   DWRITE_PANOSE_SCRIPT_FORM_UPRIGHT_EXTREME_WRAPPING = 5
   DWRITE_PANOSE_SCRIPT_FORM_OBLIQUE_NO_WRAPPING = 6
   DWRITE_PANOSE_SCRIPT_FORM_OBLIQUE_SOME_WRAPPING = 7
   DWRITE_PANOSE_SCRIPT_FORM_OBLIQUE_MORE_WRAPPING = 8
   DWRITE_PANOSE_SCRIPT_FORM_OBLIQUE_EXTREME_WRAPPING = 9
   DWRITE_PANOSE_SCRIPT_FORM_EXAGGERATED_NO_WRAPPING = 10
   DWRITE_PANOSE_SCRIPT_FORM_EXAGGERATED_SOME_WRAPPING = 11
   DWRITE_PANOSE_SCRIPT_FORM_EXAGGERATED_MORE_WRAPPING = 12
   DWRITE_PANOSE_SCRIPT_FORM_EXAGGERATED_EXTREME_WRAPPING = 13
end enum

TYPE DWRITE_PANOSE_FINIALS AS LONG
enum
   DWRITE_PANOSE_FINIALS_ANY = 0
   DWRITE_PANOSE_FINIALS_NO_FIT = 1
   DWRITE_PANOSE_FINIALS_NONE_NO_LOOPS = 2
   DWRITE_PANOSE_FINIALS_NONE_CLOSED_LOOPS = 3
   DWRITE_PANOSE_FINIALS_NONE_OPEN_LOOPS = 4
   DWRITE_PANOSE_FINIALS_SHARP_NO_LOOPS = 5
   DWRITE_PANOSE_FINIALS_SHARP_CLOSED_LOOPS = 6
   DWRITE_PANOSE_FINIALS_SHARP_OPEN_LOOPS = 7
   DWRITE_PANOSE_FINIALS_TAPERED_NO_LOOPS = 8
   DWRITE_PANOSE_FINIALS_TAPERED_CLOSED_LOOPS = 9
   DWRITE_PANOSE_FINIALS_TAPERED_OPEN_LOOPS = 10
   DWRITE_PANOSE_FINIALS_ROUND_NO_LOOPS = 11
   DWRITE_PANOSE_FINIALS_ROUND_CLOSED_LOOPS = 12
   DWRITE_PANOSE_FINIALS_ROUND_OPEN_LOOPS = 13
end enum

TYPE DWRITE_PANOSE_XASCENT AS LONG
enum
   DWRITE_PANOSE_XASCENT_ANY = 0
   DWRITE_PANOSE_XASCENT_NO_FIT = 1
   DWRITE_PANOSE_XASCENT_VERY_LOW = 2
   DWRITE_PANOSE_XASCENT_LOW = 3
   DWRITE_PANOSE_XASCENT_MEDIUM = 4
   DWRITE_PANOSE_XASCENT_HIGH = 5
   DWRITE_PANOSE_XASCENT_VERY_HIGH = 6
end enum

TYPE DWRITE_PANOSE_DECORATIVE_CLASS AS LONG
enum
   DWRITE_PANOSE_DECORATIVE_CLASS_ANY = 0
   DWRITE_PANOSE_DECORATIVE_CLASS_NO_FIT = 1
   DWRITE_PANOSE_DECORATIVE_CLASS_DERIVATIVE = 2
   DWRITE_PANOSE_DECORATIVE_CLASS_NONSTANDARD_TOPOLOGY = 3
   DWRITE_PANOSE_DECORATIVE_CLASS_NONSTANDARD_ELEMENTS = 4
   DWRITE_PANOSE_DECORATIVE_CLASS_NONSTANDARD_ASPECT = 5
   DWRITE_PANOSE_DECORATIVE_CLASS_INITIALS = 6
   DWRITE_PANOSE_DECORATIVE_CLASS_CARTOON = 7
   DWRITE_PANOSE_DECORATIVE_CLASS_PICTURE_STEMS = 8
   DWRITE_PANOSE_DECORATIVE_CLASS_ORNAMENTED = 9
   DWRITE_PANOSE_DECORATIVE_CLASS_TEXT_AND_BACKGROUND = 10
   DWRITE_PANOSE_DECORATIVE_CLASS_COLLAGE = 11
   DWRITE_PANOSE_DECORATIVE_CLASS_MONTAGE = 12
end enum

TYPE DWRITE_PANOSE_ASPECT AS LONG
enum
   DWRITE_PANOSE_ASPECT_ANY = 0
   DWRITE_PANOSE_ASPECT_NO_FIT = 1
   DWRITE_PANOSE_ASPECT_SUPER_CONDENSED = 2
   DWRITE_PANOSE_ASPECT_VERY_CONDENSED = 3
   DWRITE_PANOSE_ASPECT_CONDENSED = 4
   DWRITE_PANOSE_ASPECT_NORMAL = 5
   DWRITE_PANOSE_ASPECT_EXTENDED = 6
   DWRITE_PANOSE_ASPECT_VERY_EXTENDED = 7
   DWRITE_PANOSE_ASPECT_SUPER_EXTENDED = 8
   DWRITE_PANOSE_ASPECT_MONOSPACED = 9
end enum

TYPE DWRITE_PANOSE_FILL AS LONG
enum
   DWRITE_PANOSE_FILL_ANY = 0
   DWRITE_PANOSE_FILL_NO_FIT = 1
   DWRITE_PANOSE_FILL_STANDARD_SOLID_FILL = 2
   DWRITE_PANOSE_FILL_NO_FILL = 3
   DWRITE_PANOSE_FILL_PATTERNED_FILL = 4
   DWRITE_PANOSE_FILL_COMPLEX_FILL = 5
   DWRITE_PANOSE_FILL_SHAPED_FILL = 6
   DWRITE_PANOSE_FILL_DRAWN_DISTRESSED = 7
end enum

TYPE DWRITE_PANOSE_LINING AS LONG
enum
   DWRITE_PANOSE_LINING_ANY = 0
   DWRITE_PANOSE_LINING_NO_FIT = 1
   DWRITE_PANOSE_LINING_NONE = 2
   DWRITE_PANOSE_LINING_INLINE = 3
   DWRITE_PANOSE_LINING_OUTLINE = 4
   DWRITE_PANOSE_LINING_ENGRAVED = 5
   DWRITE_PANOSE_LINING_SHADOW = 6
   DWRITE_PANOSE_LINING_RELIEF = 7
   DWRITE_PANOSE_LINING_BACKDROP = 8
end enum

TYPE DWRITE_PANOSE_DECORATIVE_TOPOLOGY AS LONG
enum
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_ANY = 0
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_NO_FIT = 1
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_STANDARD = 2
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_SQUARE = 3
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_MULTIPLE_SEGMENT = 4
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_ART_DECO = 5
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_UNEVEN_WEIGHTING = 6
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_DIVERSE_ARMS = 7
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_DIVERSE_FORMS = 8
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_LOMBARDIC_FORMS = 9
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_UPPER_CASE_IN_LOWER_CASE = 10
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_IMPLIED_TOPOLOGY = 11
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_HORSESHOE_E_AND_A = 12
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_CURSIVE = 13
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_BLACKLETTER = 14
   DWRITE_PANOSE_DECORATIVE_TOPOLOGY_SWASH_VARIANCE = 15
end enum

TYPE DWRITE_PANOSE_CHARACTER_RANGES AS LONG
enum
   DWRITE_PANOSE_CHARACTER_RANGES_ANY = 0
   DWRITE_PANOSE_CHARACTER_RANGES_NO_FIT = 1
   DWRITE_PANOSE_CHARACTER_RANGES_EXTENDED_COLLECTION = 2
   DWRITE_PANOSE_CHARACTER_RANGES_LITERALS = 3
   DWRITE_PANOSE_CHARACTER_RANGES_NO_LOWER_CASE = 4
   DWRITE_PANOSE_CHARACTER_RANGES_SMALL_CAPS = 5
end enum

TYPE DWRITE_PANOSE_SYMBOL_KIND AS LONG
enum
   DWRITE_PANOSE_SYMBOL_KIND_ANY = 0
   DWRITE_PANOSE_SYMBOL_KIND_NO_FIT = 1
   DWRITE_PANOSE_SYMBOL_KIND_MONTAGES = 2
   DWRITE_PANOSE_SYMBOL_KIND_PICTURES = 3
   DWRITE_PANOSE_SYMBOL_KIND_SHAPES = 4
   DWRITE_PANOSE_SYMBOL_KIND_SCIENTIFIC = 5
   DWRITE_PANOSE_SYMBOL_KIND_MUSIC = 6
   DWRITE_PANOSE_SYMBOL_KIND_EXPERT = 7
   DWRITE_PANOSE_SYMBOL_KIND_PATTERNS = 8
   DWRITE_PANOSE_SYMBOL_KIND_BOARDERS = 9
   DWRITE_PANOSE_SYMBOL_KIND_ICONS = 10
   DWRITE_PANOSE_SYMBOL_KIND_LOGOS = 11
   DWRITE_PANOSE_SYMBOL_KIND_INDUSTRY_SPECIFIC = 12
end enum

TYPE DWRITE_PANOSE_SYMBOL_ASPECT_RATIO AS LONG
enum
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_ANY = 0
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_NO_FIT = 1
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_NO_WIDTH = 2
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_EXCEPTIONALLY_WIDE = 3
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_SUPER_WIDE = 4
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_VERY_WIDE = 5
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_WIDE = 6
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_NORMAL = 7
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_NARROW = 8
   DWRITE_PANOSE_SYMBOL_ASPECT_RATIO_VERY_NARROW = 9
end enum

TYPE DWRITE_OUTLINE_THRESHOLD AS LONG
enum
   DWRITE_OUTLINE_THRESHOLD_ANTIALIASED
   DWRITE_OUTLINE_THRESHOLD_ALIASED
end enum

TYPE DWRITE_BASELINE AS LONG
enum
   DWRITE_BASELINE_DEFAULT
   DWRITE_BASELINE_ROMAN
   DWRITE_BASELINE_CENTRAL
   DWRITE_BASELINE_MATH
   DWRITE_BASELINE_HANGING
   DWRITE_BASELINE_IDEOGRAPHIC_BOTTOM
   DWRITE_BASELINE_IDEOGRAPHIC_TOP
   DWRITE_BASELINE_MINIMUM
   DWRITE_BASELINE_MAXIMUM
end enum

TYPE DWRITE_VERTICAL_GLYPH_ORIENTATION AS LONG
enum
   DWRITE_VERTICAL_GLYPH_ORIENTATION_DEFAULT
   DWRITE_VERTICAL_GLYPH_ORIENTATION_STACKED
end enum

TYPE DWRITE_GLYPH_ORIENTATION_ANGLE AS LONG
enum
   DWRITE_GLYPH_ORIENTATION_ANGLE_0_DEGREES
   DWRITE_GLYPH_ORIENTATION_ANGLE_90_DEGREES
   DWRITE_GLYPH_ORIENTATION_ANGLE_180_DEGREES
   DWRITE_GLYPH_ORIENTATION_ANGLE_270_DEGREES
end enum

type DWRITE_FONT_METRICS1
   ' --- type DWRITE_FONT_METRICS
   AS UINT16 designUnitsPerEm
   AS UINT16 ascent
   AS UINT16 descent
   AS INT16 lineGap
   AS UINT16 capHeight
   AS UINT16 xHeight
   AS INT16 underlinePosition
   AS UINT16 underlineThickness
   AS INT16 strikethroughPosition
   AS UINT16 strikethroughThickness
   ' --- type DWRITE_FONT_METRICS1
   AS INT16 glyphBoxLeft
   AS INT16 glyphBoxTop
   AS INT16 glyphBoxRight
   AS INT16 glyphBoxBottom
   AS INT16 subscriptPositionX
   AS INT16 subscriptPositionY
   AS INT16 subscriptSizeX
   AS INT16 subscriptSizeY
   AS INT16 superscriptPositionX
   AS INT16 superscriptPositionY
   AS INT16 superscriptSizeX
   AS INT16 superscriptSizeY
   AS BOOL hasTypographicMetrics
end type

type DWRITE_CARET_METRICS
   AS INT16 slopeRise
   AS INT16 slopeRun
   AS INT16 offset
end type

union DWRITE_PANOSE
   AS UINT8 values(0 TO 9)
   AS UINT8 familyKind   ' // this is the only field that never changes meaning

   type text
      AS UINT8 familyKind   ' // = 2 for text
      AS UINT8 serifStyle
      AS UINT8 weight
      AS UINT8 proportion
      AS UINT8 contrast
      AS UINT8 strokeVariation
      AS UINT8 armStyle
      AS UINT8 letterform
      AS UINT8 midline
      AS UINT8 xHeight
   end type

   type script
      AS UINT8 familyKind   ' // = 3 for script
      AS UINT8 toolKind
      AS UINT8 weight
      AS UINT8 spacing
      AS UINT8 aspectRatio
      AS UINT8 contrast
      AS UINT8 scriptTopology
      AS UINT8 scriptForm
      AS UINT8 finials
      AS UINT8 xAscent
   end type

   type decorative
      AS UINT8 familyKind   ' // = 4 for decorative
      AS UINT8 decorativeClass
      AS UINT8 weight
      AS UINT8 aspect
      AS UINT8 contrast
      AS UINT8 serifVariant
      AS UINT8 fill   ' // treatment
      AS UINT8 lining
      AS UINT8 decorativeTopology
      AS UINT8 characterRange
   end type

   type symbol
      AS UINT8 familyKind   ' // = 5 for symbol
      AS UINT8 symbolKind
      AS UINT8 weight
      AS UINT8 spacing
      AS UINT8 aspectRatioAndContrast   ' // hard coded to no-fit (1)
      AS UINT8 aspectRatio94
      AS UINT8 aspectRatio119
      AS UINT8 aspectRatio157
      AS UINT8 aspectRatio163
      AS UINT8 aspectRatio211
   end type
end union

type DWRITE_UNICODE_RANGE
   AS UINT32 first
   AS UINT32 last
end type

type DWRITE_SCRIPT_PROPERTIES
   AS UINT32 isoScriptCode
   AS UINT32 isoScriptNumber
   AS UINT32 clusterLookahead
   AS UINT32 justificationCharacter
   AS UINT32 restrictCaretToClusters      : 1
   AS UINT32 usesWordDividers             : 1
   AS UINT32 isDiscreteWriting            : 1
   AS UINT32 isBlockWriting               : 1
   AS UINT32 isDistributedWithinCluster   : 1
   AS UINT32 isConnectedWriting           : 1
   AS UINT32 isCursiveWriting             : 1
   AS UINT32 reserved                     : 25
end type

type DWRITE_JUSTIFICATION_OPPORTUNITY
   AS FLOAT expansionMinimum
   AS FLOAT expansionMaximum
   AS FLOAT compressionMaximum
   AS UINT32 expansionPriority         : 8
   AS UINT32 compressionPriority       : 8
   AS UINT32 allowResidualExpansion    : 1
   AS UINT32 allowResidualCompression  : 1
   AS UINT32 applyToLeadingEdge        : 1
   AS UINT32 applyToTrailingEdge       : 1
   AS UINT32 reserved                  : 12
end type


' ########################################################################################
' Interface name: IDWriteFactory1
' IID: {30572F99-DAC6-41DB-A16E-0486307E606A}
' Inherited interface = IDWriteFactory
' ########################################################################################

#ifndef __IDWriteFactory1_INTERFACE_DEFINED__
#define __IDWriteFactory1_INTERFACE_DEFINED__

TYPE IDWriteFactory1_ EXTENDS IDWriteFactory
   DECLARE ABSTRACT FUNCTION GetEudcFontCollection (BYREF fontCollection AS IDWriteFontCollection PTR, BYVAL checkForUpdates AS BOOLEAN = FALSE) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCustomRenderingParams1 (BYVAL gamma AS FLOAT, BYVAL enhancedContrast AS FLOAT, _
           BYVAL enhancedContrastGrayscale AS FLOAT, BYVAL clearTypeLevel AS FLOAT, BYVAL pixelGeometry AS DWRITE_PIXEL_GEOMETRY, _
           BYVAL renderingMode AS DWRITE_RENDERING_MODE, BYREF renderingParams AS IDWriteRenderingParams1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace1
' IID: {A71EFDB4-9FDB-4838-AD90-CFC3BE8C3DAF}
' Inherited interface = IDWriteFontFace
' ########################################################################################

#ifndef __IDWriteFontFace1_INTERFACE_DEFINED__
#define __IDWriteFontFace1_INTERFACE_DEFINED__

TYPE IDWriteFontFace1_ EXTENDS IDWriteFontFace
   DECLARE ABSTRACT SUB GetMetrics1 (BYREF fontMetrics AS DWRITE_FONT_METRICS1)
   DECLARE ABSTRACT FUNCTION GetGdiCompatibleMetrics1 (BYVAL emSize AS FLOAT, BYVAL pixelsPerDip AS FLOAT, BYVAL transform AS DWRITE_MATRIX PTR, BYREF fontMetrics AS DWRITE_FONT_METRICS1) AS HRESULT
   DECLARE ABSTRACT SUB GetCaretMetrics (BYREF caretMetrics AS DWRITE_CARET_METRICS)
   DECLARE ABSTRACT FUNCTION GetUnicodeRanges (BYVAL maxRangeCount AS UINT32, BYREF unicodeRanges AS DWRITE_UNICODE_RANGE, BYREF actualRangeCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsMonospacedFont () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetDesignGlyphAdvances (BYVAL glyphCount AS UINT32, BYREF glyphIndices AS const UINT16, BYREF glyphAdvances AS INT32, BYVAL isSideways AS BOOLEAN = FALSE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGdiCompatibleGlyphAdvances (BYVAL emSize AS FLOAT, BYVAL pixelsPerDip AS FLOAT, _
           BYREF transform AS DWRITE_MATRIX, BYVAL useGdiNatural AS BOOLEAN, BYVAL isSideways AS BOOLEAN, _
           BYVAL glyphCount AS UINT32, BYREF glyphIndices AS const UINT16, BYREF glyphAdvances AS INT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetKerningPairAdjustments (BYVAL glyphCount AS UINT32, BYREF glyphIndices AS const UINT16, BYREF glyphAdvanceAdjustments AS INT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasKerningPairs () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetRecommendedRenderingMode1 (BYVAL fontEmSize AS FLOAT, BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT, _
           BYREF transform AS const DWRITE_MATRIX, BYVAL isSideways AS BOOLEAN, BYVAL outlineThreshold AS DWRITE_OUTLINE_THRESHOLD, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF renderingMode AS DWRITE_RENDERING_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetVerticalGlyphVariants (BYVAL glyphCount AS UINT32, BYREF nominalGlyphIndices AS const UINT16, BYREF verticalGlyphIndices AS UINT16) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasVerticalGlyphVariants () AS BOOLEAN
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFont1
' IID: {ACD16696-8C14-4F5D-877E-FE3FC1D32738}
' Inherited interface = IDWriteFont
' ########################################################################################

#ifndef __IDWriteFont1_INTERFACE_DEFINED__
#define __IDWriteFont1_INTERFACE_DEFINED__

TYPE IDWriteFont1_ EXTENDS IDWriteFont
   DECLARE ABSTRACT SUB GetMetrics1 (BYREF fontMetrics AS DWRITE_FONT_METRICS1)
   DECLARE ABSTRACT SUB GetPanose (BYREF panose AS DWRITE_PANOSE)
   DECLARE ABSTRACT FUNCTION GetUnicodeRanges (BYVAL maxRangeCount AS UINT32, BYREF unicodeRanges AS DWRITE_UNICODE_RANGE, BYREF actualRangeCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsMonospacedFont () AS BOOLEAN
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteRenderingParams1
' IID: {94413CF4-A6FC-4248-8B50-6674348FCAD3}
' Inherited interface = IDWriteRenderingParams
' Number of methods = 1
' ########################################################################################

#ifndef __IDWriteRenderingParams1_INTERFACE_DEFINED__
#define __IDWriteRenderingParams1_INTERFACE_DEFINED__

TYPE IDWriteRenderingParams1_ EXTENDS IDWriteRenderingParams
   DECLARE ABSTRACT FUNCTION GetGrayscaleEnhancedContrast () AS FLOAT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextAnalyzer1
' IID: {80DAD800-E21F-4E83-96CE-BFCCE500DB7C}
' Inherited interface = IDWriteTextAnalyzer
' ########################################################################################

#ifndef __IDWriteTextAnalyzer1_INTERFACE_DEFINED__
#define __IDWriteTextAnalyzer1_INTERFACE_DEFINED__

TYPE IDWriteTextAnalyzer1_ EXTENDS IDWriteTextAnalyzer
   DECLARE ABSTRACT FUNCTION ApplyCharacterSpacing (BYVAL leadingSpacing AS FLOAT, BYVAL trailingSpacing AS FLOAT, _
           BYVAL minimumAdvanceWidth AS FLOAT, BYVAL textLength AS UINT32, BYVAL glyphCount AS UINT32, BYREF clusterMap AS const UINT16, _
           BYREF glyphAdvances AS const FLOAT, BYREF glyphOffsets AS const DWRITE_GLYPH_OFFSET, _
           BYREF glyphProperties AS DWRITE_SHAPING_GLYPH_PROPERTIES, BYREF modifiedGlyphAdvances AS FLOAT, _
           BYREF modifiedGlyphOffsets AS DWRITE_GLYPH_OFFSET) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBaseline (BYVAL fontFace AS IDWriteFontFace PTR, BYVAL baseline AS DWRITE_BASELINE, _
           BYVAL isVertical AS BOOLEAN, BYVAL isSimulationAllowed AS BOOLEAN, BYVAL scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS, _
           BYREF localeName AS const WSTRING, BYREF baselineCoordinate AS INT32, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION AnalyzeVerticalGlyphOrientation (BYVAL analysisSource AS IDWriteTextAnalysisSource1 PTR, _
           BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYVAL analysisSink AS IDWriteTextAnalysisSink1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphOrientationTransform (BYVAL glyphOrientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, _
           BYREF isSideways AS BOOLEAN, BYREF transform AS DWRITE_MATRIX) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetScriptProperties (BYVAL scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS, _
           BYREF scriptProperties AS DWRITE_SCRIPT_PROPERTIES) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTextComplexity (BYREF textString AS const WSTRING, BYVAL textLength AS UINT32, _
           BYVAL fontFace AS IDWriteFontFace PTR, BYREF isTextSimple AS BOOLEAN, BYREF textLengthRead AS UINT32, _
           BYREF glyphIndices AS UINT16) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetJustificationOpportunities (BYVAL fontFace AS IDWriteFontFace PTR, BYVAL fontEmSize AS FLOAT, _
           BYVAL scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS, BYVAL textLength AS UINT32, BYVAL glyphCount AS UINT32, _
           BYREF textString AS const WSTRING, BYREF clusterMap AS const UINT16, BYREF glyphProperties AS const DWRITE_SHAPING_GLYPH_PROPERTIES, _
           BYREF justificationOpportunities AS DWRITE_JUSTIFICATION_OPPORTUNITY) AS HRESULT
   DECLARE ABSTRACT FUNCTION JustifyGlyphAdvances (BYVAL lineWidth AS FLOAT, BYVAL glyphCount AS UINT32, _
           BYREF justificationOpportunities AS const DWRITE_JUSTIFICATION_OPPORTUNITY, BYREF glyphAdvances AS FLOAT, _
           BYVAL glyphOffsets AS const DWRITE_GLYPH_OFFSET PTR, BYVAL justifiedGlyphAdvances AS FLOAT PTR, _
           BYREF justifiedGlyphOffsets AS DWRITE_GLYPH_OFFSET) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetJustifiedGlyphs (BYVAL fontFace AS IDWriteFontFace PTR, BYVAL fontEmSize AS FLOAT, _
           BYVAL scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS, BYVAL textLength AS UINT32, BYVAL glyphCount AS UINT32, _
           BYVAL maxGlyphCount AS UINT32, BYREF clusterMap AS const UINT16, BYREF glyphIndices AS const UINT16, _
           BYREF glyphAdvances AS const FLOAT, BYREF justifiedGlyphAdvances AS FLOAT, _
           BYREF justifiedGlyphOffsets AS const DWRITE_GLYPH_OFFSET, BYREF glyphProperties AS const DWRITE_SHAPING_GLYPH_PROPERTIES, _
           BYREF actualGlyphCount AS UINT32, BYREF modifiedClusterMap AS UINT16, BYREF modifiedGlyphIndices AS UINT16, _
           BYREF modifiedGlyphAdvances AS FLOAT, BYREF modifiedGlyphOffsets AS DWRITE_GLYPH_OFFSET) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextAnalysisSource1
' IID: {639CFAD8-0FB4-4B21-A58A-067920120009}
' Inherited interface = IDWriteTextAnalysisSource
' ########################################################################################

#ifndef __IDWriteTextAnalysisSource1_INTERFACE_DEFINED__
#define __IDWriteTextAnalysisSource1_INTERFACE_DEFINED__

TYPE IDWriteTextAnalysisSource1_ EXTENDS IDWriteTextAnalysisSource
   DECLARE ABSTRACT FUNCTION GetVerticalGlyphOrientation (BYVAL textPosition AS UINT32, BYREF textLength AS UINT32, _
           BYREF glyphOrientation AS DWRITE_VERTICAL_GLYPH_ORIENTATION, BYREF bidiLevel AS UBYTE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextAnalysisSink1
' IID: {B0D941A0-85E7-4D8B-9FD3-5CED9934482A}
' Inherited interface = IDWriteTextAnalysisSink
' Number of methods = 1
' ########################################################################################

#ifndef __IDWriteTextAnalysisSink1_INTERFACE_DEFINED__
#define __IDWriteTextAnalysisSink1_INTERFACE_DEFINED__

TYPE IDWriteTextAnalysisSink1_ EXTENDS IDWriteTextAnalysisSink
   DECLARE ABSTRACT FUNCTION SetGlyphOrientation (BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, _
           BYVAL glyphOrientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, BYVAL adjustedBidiLevel AS UBYTE, _
           BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextLayout1
' IID: {9064D822-80A7-465C-A986-DF65F78B8FEB}
' Inherited interface = IDWriteTextLayout
' ########################################################################################

#ifndef __IDWriteTextLayout1_INTERFACE_DEFINED__
#define __IDWriteTextLayout1_INTERFACE_DEFINED__

TYPE IDWriteTextLayout1_ EXTENDS IDWriteTextLayout
   DECLARE ABSTRACT FUNCTION SetPairKerning (BYVAL isPairKerningEnabled AS BOOLEAN, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPairKerning (BYVAL currentPosition AS UINT32, BYREF isPairKerningEnabled AS BOOLEAN, _
           BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetCharacterSpacing (BYVAL leadingSpacing AS FLOAT, BYVAL trailingSpacing AS FLOAT, _
           BYVAL minimumAdvanceWidth AS FLOAT, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCharacterSpacing (BYVAL currentPosition AS UINT32, BYVAL leadingSpacing AS FLOAT PTR, _
           BYREF trailingSpacing AS FLOAT, BYREF minimumAdvanceWidth AS FLOAT, BYREF textRange AS DWRITE_TEXT_RANGE) AS HRESULT
END TYPE

#endif

' ########################################################################################

TYPE DWRITE_TEXT_ANTIALIAS_MODE AS LONG
enum
   DWRITE_TEXT_ANTIALIAS_MODE_CLEARTYPE
   DWRITE_TEXT_ANTIALIAS_MODE_GRAYSCALE
end enum

' ########################################################################################
' Interface name: IDWriteBitmapRenderTarget1
' IID: {791E8298-3EF3-4230-9880-C9BDECC42064}
' Inherited interface = IDWriteBitmapRenderTarget
' ########################################################################################

#ifndef __IDWriteBitmapRenderTarget1_INTERFACE_DEFINED__
#define __IDWriteBitmapRenderTarget1_INTERFACE_DEFINED__

TYPE IDWriteBitmapRenderTarget1_ EXTENDS IDWriteBitmapRenderTarget
   DECLARE ABSTRACT FUNCTION GetTextAntialiasMode () AS DWRITE_TEXT_ANTIALIAS_MODE
   DECLARE ABSTRACT FUNCTION SetTextAntialiasMode (BYVAL antialiasMode AS DWRITE_TEXT_ANTIALIAS_MODE) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
'                                   *** dwrite_2.h ***
' ########################################################################################

TYPE DWRITE_OPTICAL_ALIGNMENT AS LONG
enum
   DWRITE_OPTICAL_ALIGNMENT_NONE
   DWRITE_OPTICAL_ALIGNMENT_NO_SIDE_BEARINGS
end enum

TYPE DWRITE_GRID_FIT_MODE AS LONG
enum
    DWRITE_GRID_FIT_MODE_DEFAULT
    DWRITE_GRID_FIT_MODE_DISABLED
    DWRITE_GRID_FIT_MODE_ENABLED
end enum

type DWRITE_TEXT_METRICS1
   ' --- DWRITE_TEXT_METRICS
   AS FLOAT left
   AS FLOAT top
   AS FLOAT width
   AS FLOAT widthIncludingTrailingWhitespace
   AS FLOAT height
   AS FLOAT layoutWidth
   AS FLOAT layoutHeight
   AS UINT32 maxBidiReorderingDepth
   AS UINT32 lineCount
   ' --- DWRITE_TEXT_METRICS1
   AS FLOAT heightIncludingTrailingWhitespace
end type


' ########################################################################################
' Interface name: IDWriteTextRenderer1
' IID: {D3E0E934-22A0-427E-AAE4-7D9574B59DB1}
' Inherited interface = IDWriteTextRenderer
' ########################################################################################

#ifndef __IDWriteTextRenderer1_INTERFACE_DEFINED__
#define __IDWriteTextRenderer1_INTERFACE_DEFINED__

TYPE IDWriteTextRenderer1_ EXTENDS IDWriteTextRenderer
   DECLARE ABSTRACT FUNCTION DrawGlyphRun2 (BYVAL clientDrawingContext AS ANY PTR, BYVAL baselineOriginX AS FLOAT, _
           BYVAL baselineOriginY AS FLOAT, BYVAL orientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
           BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawUnderline2 (BYVAL clientDrawingContext AS ANY PTR, BYVAL baselineOriginX AS FLOAT, _
           BYVAL baselineOriginY AS FLOAT, BYVAL orientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, _
           BYREF Underline AS DWRITE_UNDERLINE, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawStrikethrough2 (BYVAL clientDrawingContext AS ANY PTR, BYVAL baselineOriginX AS FLOAT, _
           BYVAL baselineOriginY AS FLOAT, BYVAL orientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, _
           BYREF StrikeThrough AS DWRITE_STRIKETHROUGH, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawInlineObject2 (BYVAL clientDrawingContext AS ANY PTR, BYVAL originX AS FLOAT, BYVAL originY AS FLOAT, _
           BYVAL orientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, BYVAL inlineObject AS IDWriteInlineObject PTR, _
           BYVAL isSideways AS BOOLEAN, BYVAL isRightToLeft AS BOOLEAN, BYVAL clientDrawingEffect AS IUnknown PTR) AS HRESULT

END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextFormat1
' IID: {5F174B49-0D8B-4CFB-8BCA-F1CCE9D06C67}
' Inherited interface = IDWriteTextFormat
' Number of methods = 8
' ########################################################################################

#ifndef __IDWriteTextFormat1_INTERFACE_DEFINED__
#define __IDWriteTextFormat1_INTERFACE_DEFINED__

TYPE IDWriteTextFormat1_ EXTENDS IDWriteTextFormat
   DECLARE ABSTRACT FUNCTION SetVerticalGlyphOrientation (BYVAL glyphOrientation AS DWRITE_VERTICAL_GLYPH_ORIENTATION) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetVerticalGlyphOrientation () AS DWRITE_VERTICAL_GLYPH_ORIENTATION
   DECLARE ABSTRACT FUNCTION SetLastLineWrapping (BYVAL isLastLineWrappingEnabled AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLastLineWrapping () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION SetOpticalAlignment (BYVAL opticalAlignment AS DWRITE_OPTICAL_ALIGNMENT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetOpticalAlignment () AS DWRITE_OPTICAL_ALIGNMENT
   DECLARE ABSTRACT FUNCTION SetFontFallback (BYVAL fontFallback AS IDWriteFontFallback PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFallback (BYREF fontFallback AS IDWriteFontFallback PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextLayout2
' IID: {1093C18F-8D5E-43F0-B064-0917311B525E}
' Inherited interface = IDWriteTextLayout1
' ########################################################################################

#ifndef __IDWriteTextLayout2_INTERFACE_DEFINED__
#define __IDWriteTextLayout2_INTERFACE_DEFINED__

TYPE IDWriteTextLayout2_ EXTENDS IDWriteTextLayout1
   DECLARE ABSTRACT FUNCTION GetMetrics2 (BYREF textMetrics AS DWRITE_TEXT_METRICS1) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetVerticalGlyphOrientation (BYVAL glyphOrientation AS DWRITE_VERTICAL_GLYPH_ORIENTATION) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetVerticalGlyphOrientation () AS DWRITE_VERTICAL_GLYPH_ORIENTATION
   DECLARE ABSTRACT FUNCTION SetLastLineWrapping (BYVAL isLastLineWrappingEnabled AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLastLineWrapping () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION SetOpticalAlignment (BYVAL opticalAlignment AS DWRITE_OPTICAL_ALIGNMENT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetOpticalAlignment () AS DWRITE_OPTICAL_ALIGNMENT
   DECLARE ABSTRACT FUNCTION SetFontFallback (BYVAL fontFallback AS IDWriteFontFallback PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFallback (BYREF fontFallback AS IDWriteFontFallback PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextAnalyzer2
' IID: {553A9FF3-5693-4DF7-B52B-74806F7F2EB9}
' Inherited interface = IDWriteTextAnalyzer1
' Number of methods = 3
' ########################################################################################

#ifndef __IDWriteTextAnalyzer2_INTERFACE_DEFINED__
#define __IDWriteTextAnalyzer2_INTERFACE_DEFINED__

TYPE IDWriteTextAnalyzer2_ EXTENDS IDWriteTextAnalyzer1

   DECLARE ABSTRACT FUNCTION GetGlyphOrientationTransform2 (BYVAL glyphOrientationAngle AS DWRITE_GLYPH_ORIENTATION_ANGLE, _
           BYVAL isSideways AS BOOLEAN, BYVAL originX AS FLOAT, BYVAL originY AS FLOAT, BYREF transform AS DWRITE_MATRIX) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTypographicFeatures (BYVAL fontFace AS IDWriteFontFace PTR, BYVAL scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS, _
           BYREF localeName AS const WSTRING, BYVAL maxTagCount AS UINT32, BYREF actualTagCount AS UINT32, BYREF tags AS DWRITE_FONT_FEATURE_TAG) AS HRESULT
   DECLARE ABSTRACT FUNCTION CheckTypographicFeature (BYVAL fontFace AS IDWriteFontFace PTR, BYVAL scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS, _
           BYREF localeName AS const WSTRING, BYVAL featureTag AS DWRITE_FONT_FEATURE_TAG, BYVAL glyphCount AS UINT32, _
           BYREF glyphIndices AS const UINT16, BYREF featureApplies AS const UBYTE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFallback
' IID: {EFA008F9-F7A1-48BF-B05C-F224713CC0FF}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontFallback_INTERFACE_DEFINED__
#define __IDWriteFontFallback_INTERFACE_DEFINED__

TYPE IDWriteFontFallback_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION MapCharacters (BYVAL analysisSource AS IDWriteTextAnalysisSource PTR, BYVAL textPosition AS UINT32, _
           BYVAL textLength AS UINT32, BYVAL baseFontCollection AS IDWriteFontCollection PTR, BYREF baseFamilyName AS const WSTRING, _
           BYVAL baseWeight AS DWRITE_FONT_WEIGHT, BYVAL baseStyle AS DWRITE_FONT_STYLE, BYVAL baseStretch AS DWRITE_FONT_STRETCH, _
           BYREF mappedLength AS UINT32, BYREF mappedFont AS IDWriteFont PTR, BYREF scale AS FLOAT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFallbackBuilder
' IID: {FD882D06-8ABA-4FB8-B849-8BE8B73E14DE}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontFallbackBuilder_INTERFACE_DEFINED__
#define __IDWriteFontFallbackBuilder_INTERFACE_DEFINED__

TYPE IDWriteFontFallbackBuilder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION AddMapping (BYREF ranges AS DWRITE_UNICODE_RANGE, BYVAL rangesCount AS UINT32, _
           BYREF targetFamilyNames AS const WSTRING, BYVAL targetFamilyNamesCount AS UINT32, BYVAL fontCollection AS IDWriteFontCollection PTR, _
           BYREF localeName AS const WSTRING, BYREF baseFamilyName AS const WSTRING, BYVAL scale AS SINGLE = 1.0!) AS HRESULT
   DECLARE ABSTRACT FUNCTION AddMappings (BYVAL fontFallback AS IDWriteFontFallback PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFallback (BYREF fontFallback AS IDWriteFontFallback PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' /// DWRITE_COLOR_F
#ifndef D3DCOLORVALUE
type D3DCOLORVALUE
   union
     AS FLOAT r
     AS FLOAT dvR
   end union
   union
     AS FLOAT g
     AS FLOAT dvG
   end union
   union
     AS FLOAT b
     AS FLOAT dvB
   end union
   union
     AS FLOAT a
     AS FLOAT dvA
   end union
end type
#endif

'typedef D3DCOLORVALUE DWRITE_COLOR_F;
type DWRITE_COLOR_F AS D3DCOLORVALUE


' ########################################################################################
' Interface name: IDWriteFont2
' IID: {29748ed6-8c9c-4a6a-be0b-d912e8538944}
' Inherited interface = IDWriteFont1
' ########################################################################################

#ifndef __IDWriteFont2_INTERFACE_DEFINED__
#define __IDWriteFont2_INTERFACE_DEFINED__

TYPE IDWriteFont2_ EXTENDS IDWriteFont1
   DECLARE ABSTRACT FUNCTION IsColorFont () AS BOOLEAN
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace2
' IID: {D8B768FF-64BC-4E66-982B-EC8E87F693F7}
' Inherited interface = IDWriteFontFace1
' ########################################################################################

#ifndef __IDWriteFontFace2_INTERFACE_DEFINED__
#define __IDWriteFontFace2_INTERFACE_DEFINED__

TYPE IDWriteFontFace2_ EXTENDS IDWriteFontFace1
   DECLARE ABSTRACT FUNCTION IsColorFont () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetColorPaletteCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetPaletteEntryCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetPaletteEntries (BYVAL colorPaletteIndex AS UINT32, BYVAL firstEntryIndex AS UINT32, _
           BYVAL entryCount AS UINT32, BYREF paletteEntries AS DWRITE_COLOR_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRecommendedRenderingMode2 (BYVAL fontEmSize AS FLOAT, BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT, _
           BYREF transform AS DWRITE_MATRIX, BYVAL isSideways AS BOOLEAN, BYVAL outlineThreshold AS DWRITE_OUTLINE_THRESHOLD, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYVAL renderingParams AS IDWriteRenderingParams PTR, _
           BYREF renderingMode AS DWRITE_RENDERING_MODE, BYREF gridFitMode AS DWRITE_GRID_FIT_MODE) AS HRESULT
END TYPE

#endif

' /// Reserved palette entry index that does not specify any palette entry.
#define DWRITE_NO_PALETTE_INDEX &hFFFF

type DWRITE_COLOR_GLYPH_RUN
   AS DWRITE_GLYPH_RUN glyphRun
   AS DWRITE_GLYPH_RUN_DESCRIPTION PTR glyphRunDescription
   AS FLOAT baselineOriginX
   AS FLOAT baselineOriginY
   AS DWRITE_COLOR_F runColor
   AS UINT16 paletteIndex
end type


' ########################################################################################
' Interface name: IDWriteColorGlyphRunEnumerator
' IID: {D31FBE17-F157-41A2-8D24-CB779E0560E8}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteColorGlyphRunEnumerator_INTERFACE_DEFINED__
#define __IDWriteColorGlyphRunEnumerator_INTERFACE_DEFINED__

TYPE IDWriteColorGlyphRunEnumerator_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION MoveNext (BYREF hasRun AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCurrentRun (BYREF colorGlyphRun AS const DWRITE_COLOR_GLYPH_RUN PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteRenderingParams2
' IID: {F9D711C3-9777-40AE-87E8-3E5AF9BF0948}
' Inherited interface = IDWriteRenderingParams1
' ########################################################################################

#ifndef __IDWriteRenderingParams2_INTERFACE_DEFINED__
#define __IDWriteRenderingParams2_INTERFACE_DEFINED__

TYPE IDWriteRenderingParams2_ EXTENDS IDWriteRenderingParams1
   DECLARE ABSTRACT FUNCTION GetGridFitMode () AS DWRITE_GRID_FIT_MODE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory2
' IID: {0439FC60-CA44-4994-8DEE-3A9AF7B732EC}
' Inherited interface = IDWriteFactory1
' ########################################################################################

#ifndef __IDWriteFactory2_INTERFACE_DEFINED__
#define __IDWriteFactory2_INTERFACE_DEFINED__

TYPE IDWriteFactory2_ EXTENDS IDWriteFactory1
   DECLARE ABSTRACT FUNCTION GetSystemFontFallback (BYREF fontFallback AS IDWriteFontFallback PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFallbackBuilder (BYREF fontFallbackBuilder AS IDWriteFontFallbackBuilder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION TranslateColorGlyphRun (BYVAL baselineOriginX AS FLOAT, BYVAL baselineOriginY AS FLOAT, _
           BYREF glyphRun AS DWRITE_GLYPH_RUN, BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF worldToDeviceTransform AS const DWRITE_MATRIX, _
           BYVAL colorPaletteIndex AS UINT32, BYREF colorLayers AS IDWriteColorGlyphRunEnumerator PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCustomRenderingParams2 (BYVAL gamma AS FLOAT, BYVAL enhancedContrast AS FLOAT, _
           BYVAL grayscaleEnhancedContrast AS FLOAT, BYVAL clearTypeLevel AS FLOAT, BYVAL pixelGeometry AS DWRITE_PIXEL_GEOMETRY, _
           BYVAL renderingMode AS DWRITE_RENDERING_MODE, BYVAL gridFitMode AS DWRITE_GRID_FIT_MODE, BYREF renderingParams AS IDWriteRenderingParams2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGlyphRunAnalysis2 (BYREF glyphRun AS DWRITE_GLYPH_RUN, BYREF transform AS const DWRITE_MATRIX, _
           BYVAL renderingMode AS DWRITE_RENDERING_MODE, BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYVAL gridFitMode AS DWRITE_GRID_FIT_MODE, _
           BYVAL antialiasMode AS DWRITE_TEXT_ANTIALIAS_MODE, BYVAL baselineOriginX AS FLOAT, BYVAL baselineOriginY AS FLOAT, _
           BYREF glyphRunAnalysis AS IDWriteGlyphRunAnalysis PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
'                                   *** dwrite_3.h ***
' ########################################################################################

'type IDWriteFontFaceReference AS IDWriteFontFaceReference_
'type IDWriteFont3 AS IDWriteFont3_
'type IDWriteFontFace3 AS IDWriteFontFace3_
'type IDWriteFontSet AS IDWriteFontSet_
'type IDWriteFontSetBuilder AS IDWriteFontSetBuilder_
'type IDWriteFontCollection1 AS IDWriteFontCollection1_
'type IDWriteFontFamily1 AS IDWriteFontFamily1_
'type IDWriteStringList AS IDWriteStringList_
'type IDWriteFontDownloadQueue AS IDWriteFontDownloadQueue_

#ifndef DWRITE_E_REMOTEFONT
#define DWRITE_E_REMOTEFONT    _HRESULT_TYPEDEF_(&h8898500DL)
#endif

#ifndef DWRITE_E_DOWNLOADCANCELLED
#define DWRITE_E_DOWNLOADCANCELLED  _HRESULT_TYPEDEF_(&h8898500EL)
#endif

#ifndef DWRITE_E_DOWNLOADFAILED
#define DWRITE_E_DOWNLOADFAILED  _HRESULT_TYPEDEF_(&h8898500FL)
#endif

#ifndef DWRITE_E_TOOMANYDOWNLOADS
#define DWRITE_E_TOOMANYDOWNLOADS  _HRESULT_TYPEDEF_(&h88985010L)
#endif

TYPE DWRITE_FONT_PROPERTY_ID AS LONG
enum
   DWRITE_FONT_PROPERTY_ID_NONE
   DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME
   DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME
   DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FACE_NAME
   DWRITE_FONT_PROPERTY_ID_FULL_NAME
   DWRITE_FONT_PROPERTY_ID_WIN32_FAMILY_NAME
   DWRITE_FONT_PROPERTY_ID_POSTSCRIPT_NAME
   DWRITE_FONT_PROPERTY_ID_DESIGN_SCRIPT_LANGUAGE_TAG
   DWRITE_FONT_PROPERTY_ID_SUPPORTED_SCRIPT_LANGUAGE_TAG
   DWRITE_FONT_PROPERTY_ID_SEMANTIC_TAG
   DWRITE_FONT_PROPERTY_ID_WEIGHT
   DWRITE_FONT_PROPERTY_ID_STRETCH
   DWRITE_FONT_PROPERTY_ID_STYLE
   DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FACE_NAME
   DWRITE_FONT_PROPERTY_ID_TOTAL = DWRITE_FONT_PROPERTY_ID_STYLE + 1
   DWRITE_FONT_PROPERTY_ID_TOTAL_RS3 = DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FACE_NAME + 1
   ' // Obsolete aliases kept to avoid breaking existing code.
   DWRITE_FONT_PROPERTY_ID_PREFERRED_FAMILY_NAME = DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME
   DWRITE_FONT_PROPERTY_ID_FAMILY_NAME = DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME
   DWRITE_FONT_PROPERTY_ID_FACE_NAME = DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FACE_NAME
end enum

type DWRITE_FONT_PROPERTY
   AS DWRITE_FONT_PROPERTY_ID propertyId
   AS const WSTRING PTR propertyValue
   AS const WSTRING PTR localeName
end type

TYPE DWRITE_LOCALITY AS LONG
enum
   DWRITE_LOCALITY_REMOTE
   DWRITE_LOCALITY_PARTIAL
   DWRITE_LOCALITY_LOCAL
end enum

TYPE DWRITE_RENDERING_MODE1 AS LONG
enum
   DWRITE_RENDERING_MODE1_DEFAULT = DWRITE_RENDERING_MODE_DEFAULT
   DWRITE_RENDERING_MODE1_ALIASED = DWRITE_RENDERING_MODE_ALIASED
   DWRITE_RENDERING_MODE1_GDI_CLASSIC = DWRITE_RENDERING_MODE_GDI_CLASSIC
   DWRITE_RENDERING_MODE1_GDI_NATURAL = DWRITE_RENDERING_MODE_GDI_NATURAL
   DWRITE_RENDERING_MODE1_NATURAL = DWRITE_RENDERING_MODE_NATURAL
   DWRITE_RENDERING_MODE1_NATURAL_SYMMETRIC = DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC
   DWRITE_RENDERING_MODE1_OUTLINE = DWRITE_RENDERING_MODE_OUTLINE
   DWRITE_RENDERING_MODE1_NATURAL_SYMMETRIC_DOWNSAMPLED
end enum

' ########################################################################################
' Interface name: IDWriteRenderingParams3
' IID: {B7924BAA-391B-412A-8C5C-E44CC2D867DC}
' Inherited interface = IDWriteRenderingParams2
' ########################################################################################

#ifndef __IDWriteRenderingParams3_INTERFACE_DEFINED__
#define __IDWriteRenderingParams3_INTERFACE_DEFINED__

TYPE IDWriteRenderingParams3_ EXTENDS IDWriteRenderingParams2
   DECLARE ABSTRACT FUNCTION GetRenderingMode1 () AS DWRITE_RENDERING_MODE1
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory3
' IID: {9A1B41C3-D3BB-466A-87FC-FE67556A3B65}
' Inherited interface = IDWriteFactory2
' ########################################################################################

#ifndef __IDWriteFactory3_INTERFACE_DEFINED__
#define __IDWriteFactory3_INTERFACE_DEFINED__

TYPE IDWriteFactory3_ EXTENDS IDWriteFactory2
   DECLARE ABSTRACT FUNCTION CreateGlyphRunAnalysis3 (BYREF glyphRun AS DWRITE_GLYPH_RUN, BYREF transform AS const DWRITE_MATRIX, _
           BYVAL renderingMode AS DWRITE_RENDERING_MODE1, BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYVAL gridFitMode AS DWRITE_GRID_FIT_MODE, _
           BYVAL antialiasMode AS DWRITE_TEXT_ANTIALIAS_MODE, BYVAL baselineOriginX AS FLOAT, BYVAL baselineOriginY AS FLOAT, _
           BYREF glyphRunAnalysis AS IDWriteGlyphRunAnalysis PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCustomRenderingParams3 (BYVAL gamma AS FLOAT, BYVAL enhancedContrast AS FLOAT, _
           BYVAL grayscaleEnhancedContrast AS FLOAT, BYVAL clearTypeLevel AS FLOAT, BYVAL pixelGeometry AS DWRITE_PIXEL_GEOMETRY, _
           BYVAL renderingMode AS DWRITE_RENDERING_MODE1, BYVAL gridFitMode AS DWRITE_GRID_FIT_MODE, BYREF renderingParams AS IDWriteRenderingParams3 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFaceReference (BYREF filePath AS const WSTRING, BYREF LastWriteTime AS const FILETIME, _
           BYVAL faceIndex AS UINT32, BYVAL fontSimulations AS DWRITE_FONT_SIMULATIONS, BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFaceReference2 (BYVAL fontFile AS IDWriteFontFile PTR, BYVAL faceIndex AS UINT32, _
           BYVAL fontSimulations AS DWRITE_FONT_SIMULATIONS, BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSystemFontSet (BYREF fontSet AS IDWriteFontSet PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontSetBuilder (BYREF fontSetBuilder AS IDWriteFontSetBuilder PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontCollectionFromFontSet (BYVAL fontSet AS IDWriteFontSet PTR, BYREF fontCollection AS IDWriteFontCollection1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSystemFontCollection2 (BYVAL includeDownloadableFonts AS BOOLEAN, BYREF fontCollection AS IDWriteFontCollection1 PTR, _
           BYVAL checkForUpdates AS BOOLEAN = FALSE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontDownloadQueue (BYREF fontDownloadQueue AS IDWriteFontDownloadQueue PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontSet
' IID: {53585141-D9F8-4095-8321-D73CF6BD116B}
' Inherited interface = IUnknown
' Number of methods = 10
' ########################################################################################

#ifndef __IDWriteFontSet_INTERFACE_DEFINED__
#define __IDWriteFontSet_INTERFACE_DEFINED__

TYPE IDWriteFontSet_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetFontCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontFaceReference (BYVAL listIndex AS UINT32, BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION FindFontFaceReference (BYVAL fontFaceReference AS IDWriteFontFaceReference PTR, BYREF listIndex AS UINT32, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION FindFontFace (BYVAL fontFace AS IDWriteFontFace PTR, BYREF listIndex AS UINT32, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPropertyValues (BYVAL listIndex AS UINT32, BYVAL propertyId AS DWRITE_FONT_PROPERTY_ID, _
           BYREF exists AS BOOLEAN, BYREF values AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPropertyValues_2 (BYVAL propertyId AS DWRITE_FONT_PROPERTY_ID, BYREF preferredLocaleNames AS const WSTRING, _
           BYREF values AS IDWriteStringList PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPropertyValues_3 (BYVAL propertyId AS DWRITE_FONT_PROPERTY_ID, BYREF values AS IDWriteStringList PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPropertyOccurrenceCount (BYREF Property AS DWRITE_FONT_PROPERTY, BYREF propertyOccurrenceCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatchingFonts (BYREF fproperties AS DWRITE_FONT_PROPERTY, BYVAL propertyCount AS UINT32, BYREF filteredSet AS IDWriteFontSet PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatchingFonts_2 (BYREF familyName AS const WSTRING, BYVAL fontWeight AS DWRITE_FONT_WEIGHT, _
           BYVAL fontStretch AS DWRITE_FONT_STRETCH, BYVAL fontStyle AS DWRITE_FONT_STYLE, BYREF filteredSet AS IDWriteFontSet PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontSetBuilder
' IID: {2F642AFE-9C68-4F40-B8BE-457401AFCB3D}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontSetBuilder_INTERFACE_DEFINED__
#define __IDWriteFontSetBuilder_INTERFACE_DEFINED__

TYPE IDWriteFontSetBuilder_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION AddFontFaceReference (BYVAL fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AddFontFaceReference_2 (BYVAL fontFaceReference AS IDWriteFontFaceReference PTR, _
           BYREF fproperties AS DWRITE_FONT_PROPERTY, BYVAL propertyCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION AddFontSet (BYVAL fontSet AS IDWriteFontSet PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontSet (BYREF fontSet AS IDWriteFontSet PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontCollection1
' IID: {53585141-D9F8-4095-8321-D73CF6BD116C}
' Inherited interface = IDWriteFontCollection
' ########################################################################################

#ifndef __Afx_IDWriteFontCollection1_INTERFACE_DEFINED__
#define __Afx_IDWriteFontCollection1_INTERFACE_DEFINED__

TYPE IDWriteFontCollection1_ EXTENDS IDWriteFontCollection
   DECLARE ABSTRACT FUNCTION GetFontSet (BYREF fontSet AS IDWriteFontSet PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFamily1 (BYVAL index AS LONG, BYREF fontFamily AS IDWriteFontFamily1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFamily1
' IID: {DA20D8EF-812A-4C43-9802-62EC4ABD7ADF}
' Inherited interface = IDWriteFontFamily
' ########################################################################################

#ifndef __IDWriteFontFamily1_INTERFACE_DEFINED__
#define __IDWriteFontFamily1_INTERFACE_DEFINED__

TYPE IDWriteFontFamily1_ EXTENDS IDWriteFontFamily
   DECLARE ABSTRACT FUNCTION GetFontLocality (BYVAL listIndex AS LONG) AS DWRITE_LOCALITY
   DECLARE ABSTRACT FUNCTION GetFont1 (BYVAL listIndex AS UINT32, BYREF font AS IDWriteFont3 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFaceReference (BYVAL listIndex AS UINT32, BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontList1
' IID: {DA20D8EF-812A-4C43-9802-62EC4ABD7ADE}
' Inherited interface = IDWriteFontList
' ########################################################################################

#ifndef __IDWriteFontList1_INTERFACE_DEFINED__
#define __IDWriteFontList1_INTERFACE_DEFINED__

TYPE IDWriteFontList1_ EXTENDS IDWriteFontList
   DECLARE ABSTRACT FUNCTION GetFontLocality (BYVAL listIndex AS LONG) AS DWRITE_LOCALITY
   DECLARE ABSTRACT FUNCTION GetFont1 (BYVAL listIndex AS UINT32, BYREF font AS IDWriteFont3 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFaceReference (BYVAL listIndex AS UINT32, BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: IDWriteFontFaceReference
' IID: {5E7FA7CA-DDE3-424C-89F0-9FCD6FED58CD}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontFaceReference_INTERFACE_DEFINED__
#define __IDWriteFontFaceReference_INTERFACE_DEFINED__

TYPE IDWriteFontFaceReference_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CreateFontFace (BYREF fontFace AS IDWriteFontFace3 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFaceWithSimulations (BYVAL fontFaceSimulationFlags AS DWRITE_FONT_SIMULATIONS, _
           BYREF fontFace AS IDWriteFontFace3 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Equals (BYVAL fontFaceReference AS IDWriteFontFaceReference PTR) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetFontFaceIndex () AS UINT32
   DECLARE ABSTRACT FUNCTION GetSimulations () AS DWRITE_FONT_SIMULATIONS
   DECLARE ABSTRACT FUNCTION GetFontFile (BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocalFileSize () AS UINT64
   DECLARE ABSTRACT FUNCTION GetFileSize () AS UINT64
   DECLARE ABSTRACT FUNCTION GetFileTime (BYREF LastWriteTime AS FILETIME) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocality () AS DWRITE_LOCALITY
   DECLARE ABSTRACT FUNCTION EnqueueFontDownloadRequest () AS HRESULT
   DECLARE ABSTRACT FUNCTION EnqueueCharacterDownloadRequest (BYREF characters AS const WSTRING, BYVAL characterCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION EnqueueGlyphDownloadRequest (BYREF glyphIndices AS const UINT16, BYVAL glyphCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION EnqueueFileFragmentDownloadRequest (BYVAL fileOffset AS UINT64, BYVAL fragmentSize AS UINT64) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFont3
' IID: {29748ED6-8C9C-4A6A-BE0B-D912E8538944}
' Inherited interface = IDWriteFont2
' ########################################################################################

#ifndef __IDWriteFont3_INTERFACE_DEFINED__
#define __IDWriteFont3_INTERFACE_DEFINED__

TYPE IDWriteFont3_ EXTENDS IDWriteFont2
   DECLARE ABSTRACT FUNCTION CreateFontFace3 (BYREF fontFace AS IDWriteFontFace3 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Equals (BYVAL font AS IDWriteFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFaceReference (BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasCharacter3 (BYVAL unicodeValue AS LONG) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetLocality () AS DWRITE_LOCALITY
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace3
' IID: {D37D7598-09BE-4222-A236-2081341CC1F2}
' Inherited interface = IDWriteFontFace2
' ########################################################################################

#ifndef __IDWriteFontFace3_INTERFACE_DEFINED__
#define __IDWriteFontFace3_INTERFACE_DEFINED__

TYPE IDWriteFontFace3_ EXTENDS IDWriteFontFace2
   DECLARE ABSTRACT FUNCTION GetFontFaceReference (BYREF fontFaceReference AS IDWriteFontFaceReference PTR) AS HRESULT
   DECLARE ABSTRACT SUB GetPanose (BYREF panose AS DWRITE_PANOSE)
   DECLARE ABSTRACT FUNCTION GetWeight () AS DWRITE_FONT_WEIGHT
   DECLARE ABSTRACT FUNCTION GetStretch () AS DWRITE_FONT_STRETCH
   DECLARE ABSTRACT FUNCTION GetStyle () AS DWRITE_FONT_STYLE
   DECLARE ABSTRACT FUNCTION GetFamilyNames (BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFaceNames (BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetInformationalStrings (BYVAL informationalStringID AS DWRITE_INFORMATIONAL_STRING_ID, _
           BYREF informationalStrings AS IDWriteLocalizedStrings PTR, BYREF exists AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasCharacter (BYVAL unicodeValue AS UINT32) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetRecommendedRenderingMode3 (BYVAL fontEmSize AS FLOAT, BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT, _
           BYREF transform AS const DWRITE_MATRIX, BYVAL isSideways AS BOOLEAN, BYVAL outlineThreshold AS DWRITE_OUTLINE_THRESHOLD, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYVAL renderingParams AS IDWriteRenderingParams PTR, _
           BYREF renderingMode AS DWRITE_RENDERING_MODE1, BYREF gridFitMode AS DWRITE_GRID_FIT_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsCharacterLocal (BYVAL unicodeValue AS UINT32) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION IsGlyphLocal (BYVAL glyphId AS UINT16) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION AreCharactersLocal (BYREF characters AS const WSTRING, BYVAL characterCount AS UINT32, _
           BYVAL enqueueIfNotLocal AS BOOLEAN, BYREF isLocal AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION AreGlyphsLocal (BYREF glyphIndices AS const UINT16, BYVAL glyphCount AS UINT32, _
           BYVAL enqueueIfNotLocal AS BOOLEAN, BYREF isLocal AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteStringList
' IID: {CFEE3140-1157-47CA-8B85-31BFCF3F2D0E}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteStringList_INTERFACE_DEFINED__
#define __IDWriteStringList_INTERFACE_DEFINED__

TYPE IDWriteStringList_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetLocaleNameLength (BYVAL listIndex AS UINT32, BYREF length AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocaleName (BYVAL listIndex AS UINT32, BYREF localeName AS const WSTRING, BYVAL size AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetStringLength (BYVAL listIndex AS UINT32, BYREF length AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetString (BYVAL listIndex AS UINT32, BYREF stringBuffer AS const WSTRING, BYVAL stringBufferSize AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontDownloadListener
' IID: {B06FE5B9-43EC-4393-881B-DBE4DC72FDA7}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontDownloadListener_INTERFACE_DEFINED__
#define __IDWriteFontDownloadListener_INTERFACE_DEFINED__

TYPE IDWriteFontDownloadListener_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT SUB DownloadCompleted (BYVAL downloadQueue AS IDWriteFontDownloadQueue PTR, BYVAL context AS IUnknown PTR, BYVAL downloadResult AS HRESULT)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontDownloadQueue
' IID: {B71E6052-5AEA-4FA3-832E-F60D431F7E91}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontDownloadQueue_INTERFACE_DEFINED__
#define __IDWriteFontDownloadQueue_INTERFACE_DEFINED__

TYPE IDWriteFontDownloadQueue_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION AddListener (BYVAL listener AS IDWriteFontDownloadListener PTR, BYREF token AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION RemoveListener (BYVAL token AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsEmpty () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION BeginDownload (BYVAL context AS IUnknown PTR = NULL) AS HRESULT
   DECLARE ABSTRACT FUNCTION CancelDownload () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGenerationCount () AS UINT64
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteGdiInterop1
' IID: {4556BE70-3ABD-4F70-90BE-421780A6F515}
' Inherited interface = IDWriteGdiInterop
' ########################################################################################

#ifndef __IDWriteGdiInterop1_INTERFACE_DEFINED__
#define __IDWriteGdiInterop1_INTERFACE_DEFINED__

TYPE IDWriteGdiInterop1_ EXTENDS IDWriteGdiInterop
   DECLARE ABSTRACT FUNCTION CreateFontFromLOGFONT (BYREF logFont AS const LOGFONTW, BYVAL fontCollection AS IDWriteFontCollection PTR, _
           BYREF font AS IDWriteFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontSignature (BYVAL font AS IDWriteFont PTR, BYREF fontSignature AS FONTSIGNATURE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontSignatureB (BYVAL fontFace AS IDWriteFontFace PTR, BYREF fontSignature AS FONTSIGNATURE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatchingFontsByLOGFONT1 (BYREF logFont AS const LOGFONTA, BYVAL fontSet AS IDWriteFontSet PTR, _
           BYREF filteredSet AS IDWriteFontSet PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

type DWRITE_LINE_METRICS1
   ' --- DWRITE_LINE_METRICS
   AS UINT32 length
   AS UINT32 trailingWhitespaceLength
   AS UINT32 newlineLength
   AS FLOAT height
   AS FLOAT baseline
   AS BOOL isTrimmed
   ' --- DWRITE_LINE_METRICS1
   AS FLOAT leadingBefore
   AS FLOAT leadingAfter
end type

TYPE DWRITE_FONT_LINE_GAP_USAGE AS LONG
enum
   DWRITE_FONT_LINE_GAP_USAGE_DEFAULT
   DWRITE_FONT_LINE_GAP_USAGE_DISABLED
   DWRITE_FONT_LINE_GAP_USAGE_ENABLED
end enum

type DWRITE_LINE_SPACING
   AS DWRITE_LINE_SPACING_METHOD method
   AS FLOAT height
   AS FLOAT baseline
   AS FLOAT leadingBefore
   AS DWRITE_FONT_LINE_GAP_USAGE fontLineGapUsage
end type

' ########################################################################################
' Interface name: IDWriteTextFormat2
' IID: {F67E0EDD-9E3D-4ECC-8C32-4183253DFE70}
' Inherited interface = IDWriteTextFormat1
' ########################################################################################

#ifndef __IDWriteTextFormat2_INTERFACE_DEFINED__
#define __IDWriteTextFormat2_INTERFACE_DEFINED__

TYPE IDWriteTextFormat2_ EXTENDS IDWriteTextFormat1
   DECLARE ABSTRACT FUNCTION SetLineSpacing2 (BYREF lineSpacingOptions AS DWRITE_LINE_SPACING) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLineSpacing2 (BYREF lineSpacingOptions AS DWRITE_LINE_SPACING) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextLayout3
' IID: {07DDCD52-020E-4DE8-AC33-6C953D83F92D}
' Inherited interface = IDWriteTextLayout2
' ########################################################################################

#ifndef __IDWriteTextLayout3_INTERFACE_DEFINED__
#define __IDWriteTextLayout3_INTERFACE_DEFINED__

TYPE IDWriteTextLayout3_ EXTENDS IDWriteTextLayout2
   DECLARE ABSTRACT FUNCTION InvalidateLayout () AS HRESULT
   DECLARE ABSTRACT FUNCTION SetLineSpacing3 (BYREF lineSpacingOptions AS DWRITE_LINE_SPACING) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLineSpacing3 (BYREF lineSpacingOptions AS DWRITE_LINE_SPACING) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLineMetrics3 (BYREF lineMetrics AS DWRITE_LINE_METRICS1, BYVAL maxLineCount AS UINT32, BYREF actualLineCount AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################


type DWRITE_COLOR_GLYPH_RUN1
   ' --- DWRITE_COLOR_GLYPH_RUN
   AS DWRITE_GLYPH_RUN glyphRun
   AS DWRITE_GLYPH_RUN_DESCRIPTION PTR glyphRunDescription
   AS FLOAT baselineOriginX
   AS FLOAT baselineOriginY
   AS DWRITE_COLOR_F runColor
   AS UINT16 paletteIndex
   ' --- DWRITE_COLOR_GLYPH_RUN1
   AS DWRITE_GLYPH_IMAGE_FORMATS glyphImageFormat
   AS DWRITE_MEASURING_MODE measuringMode
end type

type DWRITE_GLYPH_IMAGE_DATA
   AS const void PTR imageData
   AS UINT32 imageDataSize
   AS UINT32 uniqueDataId
   AS UINT32 pixelsPerEm
   AS D2D1_SIZE_U pixelSize
   AS D2D1_POINT_2L horizontalLeftOrigin
   AS D2D1_POINT_2L horizontalRightOrigin
   AS D2D1_POINT_2L verticalTopOrigin
   AS D2D1_POINT_2L verticalBottomOrigin
end type


' ########################################################################################
' Interface name: IDWriteColorGlyphRunEnumerator1
' IID: {7C5F86DA-C7A1-4F05-B8E1-55A179FE5A35}
' Inherited interface = IDWriteColorGlyphRunEnumerator
' ########################################################################################

#ifndef __IDWriteColorGlyphRunEnumerator1_INTERFACE_DEFINED__
#define __IDWriteColorGlyphRunEnumerator1_INTERFACE_DEFINED__

TYPE IDWriteColorGlyphRunEnumerator1_ EXTENDS IDWriteColorGlyphRunEnumerator
   DECLARE ABSTRACT FUNCTION GetCurrentRun1 (BYREF colorGlyphRun AS const DWRITE_COLOR_GLYPH_RUN1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace4
' IID: {27F2A904-4EB8-441D-9678-0563F53E3E2F}
' Inherited interface = IDWriteFontFace3
' ########################################################################################

#ifndef __IDWriteFontFace4_INTERFACE_DEFINED__
#define __IDWriteFontFace4_INTERFACE_DEFINED__

TYPE IDWriteFontFace4_ EXTENDS IDWriteFontFace3
   DECLARE ABSTRACT FUNCTION GetGlyphImageFormats () AS DWRITE_GLYPH_IMAGE_FORMATS
   DECLARE ABSTRACT FUNCTION GetGlyphImageFormats_2 (BYVAL glyphId AS UINT16, BYVAL pixelsPerEmFirst AS UINT32, _
           BYVAL pixelsPerEmLast AS UINT32, BYREF glyphImageFormats AS DWRITE_GLYPH_IMAGE_FORMATS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphImageData (BYVAL glyphId AS UINT16, BYVAL pixelsPerEm AS UINT32, _
           BYVAL glyphImageFormat AS DWRITE_GLYPH_IMAGE_FORMATS, BYREF glyphData AS DWRITE_GLYPH_IMAGE_DATA, _
           BYREF glyphDataContext AS void PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseGlyphImageData (BYVAL glyphDataContext AS void PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory4
' IID: {4B0B5BD3-0797-4549-8AC5-FE915CC53856}
' Inherited interface = IDWriteFactory3
' ########################################################################################

#ifndef __IDWriteFactory4_INTERFACE_DEFINED__
#define __IDWriteFactory4_INTERFACE_DEFINED__

TYPE IDWriteFactory4_ EXTENDS IDWriteFactory3
   DECLARE ABSTRACT FUNCTION TranslateColorGlyphRun4 (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
           BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL desiredGlyphImageFormats AS DWRITE_GLYPH_IMAGE_FORMATS, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF worldAndDpiTransform AS const DWRITE_MATRIX, _
           BYVAL colorPaletteIndex AS UINT32, BYREF colorLayers AS IDWriteColorGlyphRunEnumerator1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION ComputeGlyphOrigins (BYREF glyphRun AS const DWRITE_GLYPH_RUN, BYVAL measuringMode AS DWRITE_MEASURING_MODE, _
           BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF worldAndDpiTransform AS DWRITE_MATRIX, BYREF glyphOrigins AS D2D1_POINT_2F) AS HRESULT
   DECLARE ABSTRACT FUNCTION ComputeGlyphOrigins_2 (BYREF glyphRun AS DWRITE_GLYPH_RUN, BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphOrigins AS D2D1_POINT_2F) AS HRESULT

END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontSetBuilder1
' IID: {3FF7715F-3CDC-4DC6-9B72-EC5621DCCAFD}
' Inherited interface = IDWriteFontSetBuilder
' ########################################################################################

#ifndef __IDWriteFontSetBuilder1_INTERFACE_DEFINED__
#define __IDWriteFontSetBuilder1_INTERFACE_DEFINED__

TYPE IDWriteFontSetBuilder1_ EXTENDS IDWriteFontSetBuilder
   DECLARE ABSTRACT FUNCTION AddFontFile (BYVAL fontFile AS IDWriteFontFile PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteAsyncResult
' IID: {CE25F8FD-863B-4D13-9651-C1F88DC73FE2}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteAsyncResult_INTERFACE_DEFINED__
#define __IDWriteAsyncResult_INTERFACE_DEFINED__

TYPE IDWriteAsyncResult_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetWaitHandle () AS HANDLE
   DECLARE ABSTRACT FUNCTION GetResult () AS HRESULT
END TYPE

#endif

' ########################################################################################

type DWRITE_FILE_FRAGMENT
   AS UINT64 fileOffset
   AS UINT64 fragmentSize
end type

' ########################################################################################
' Interface name: IDWriteRemoteFontFileStream
' IID: {4DB3757A-2C72-4ED9-B2B6-1ABABE1AFF9C}
' Inherited interface = IDWriteFontFileStream
' ########################################################################################

#ifndef __IDWriteRemoteFontFileStream_INTERFACE_DEFINED__
#define __IDWriteRemoteFontFileStream_INTERFACE_DEFINED__

TYPE IDWriteRemoteFontFileStream_ EXTENDS IDWriteFontFileStream
   DECLARE ABSTRACT FUNCTION GetLocalFileSize (BYREF localFileSize AS UINT64) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFileFragmentLocality (BYVAL fileOffset AS UINT64, BYVAL fragmentSize AS UINT64, _
           BYREF isLocal AS BOOLEAN, BYREF partialSize AS UINT64) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocality () AS DWRITE_LOCALITY
   DECLARE ABSTRACT FUNCTION BeginDownload (BYVAL downloadOperationID AS UUID PTR, BYREF fileFragments AS DWRITE_FILE_FRAGMENT, _
           BYVAL fragmentCount AS UINT32, BYREF asyncResult AS IDWriteAsyncResult PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


TYPE DWRITE_CONTAINER_TYPE AS LONG
enum
   DWRITE_CONTAINER_TYPE_UNKNOWN
   DWRITE_CONTAINER_TYPE_WOFF
   DWRITE_CONTAINER_TYPE_WOFF2
end enum


' ########################################################################################
' Interface name: IDWriteRemoteFontFileLoader
' IID: {68648C83-6EDE-46C0-AB46-20083A887FDE}
' Inherited interface = IDWriteFontFileLoader
' ########################################################################################

#ifndef __IDWriteRemoteFontFileLoader_INTERFACE_DEFINED__
#define __IDWriteRemoteFontFileLoader_INTERFACE_DEFINED__

TYPE IDWriteRemoteFontFileLoader_ EXTENDS IDWriteFontFileLoader
   DECLARE ABSTRACT FUNCTION CreateRemoteStreamFromKey (BYVAL fontFileReferenceKey AS const void PTR, _
           BYVAL fontFileReferenceKeySize AS UINT32, BYREF fontFileStream AS IDWriteRemoteFontFileStream PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLocalityFromKey (BYVAL fontFileReferenceKey AS const void PTR, BYVAL fontFileReferenceKeySize AS UINT32, _
           BYREF locality AS DWRITE_LOCALITY) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFileReferenceFromUrl (BYVAL factory AS IDWriteFactory PTR, BYREF baseUrl AS const WSTRING, _
           BYREF fontFileUrl AS const WSTRING, BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteInMemoryFontFileLoader
' IID: {DC102F47-A12D-4B1C-822D-9E117E33043F}
' Inherited interface = IDWriteFontFileLoader
' ########################################################################################

#ifndef __IDWriteInMemoryFontFileLoader_INTERFACE_DEFINED__
#define __IDWriteInMemoryFontFileLoader_INTERFACE_DEFINED__

TYPE IDWriteInMemoryFontFileLoader_ EXTENDS IDWriteFontFileLoader
   DECLARE ABSTRACT FUNCTION CreateInMemoryFontFileReference (BYVAL factory AS IDWriteFactory PTR, BYVAL fontData AS const void PTR, _
           BYVAL fontDataSize AS UINT32, BYVAL ownerObject AS IUnknown PTR, BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFileCount () AS UINT32
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory5
' IID: {958DB99A-BE2A-4F09-AF7D-65189803D1D3}
' Inherited interface = IDWriteFactory4
' ########################################################################################

#ifndef __IDWriteFactory5_INTERFACE_DEFINED__
#define __IDWriteFactory5_INTERFACE_DEFINED__

TYPE IDWriteFactory5_ EXTENDS IDWriteFactory4
   DECLARE ABSTRACT FUNCTION CreateFontSetBuilder5 (BYREF fontSetBuilder AS IDWriteFontSetBuilder1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateInMemoryFontFileLoader (BYREF newLoader AS IDWriteInMemoryFontFileLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateHttpFontFileLoader (BYREF referrerUrl AS const WSTRING, _
           BYREF extraHeaders AS const WSTRING, BYREF newLoader AS IDWriteRemoteFontFileLoader PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AnalyzeContainerType (BYVAL fileData AS const void PTR, BYVAL fileDataSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnpackFontFile (BYVAL containerType AS DWRITE_CONTAINER_TYPE, BYVAL fileData AS const void PTR, _
           BYVAL fileDataSize AS UINT32, BYREF unpackedFontStream AS IDWriteFontFileStream PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

'#define DWRITE_MAKE_FONT_AXIS_TAG(a,b,c,d) (static_cast<DWRITE_FONT_AXIS_TAG>(DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d)))
#define DWRITE_MAKE_FONT_AXIS_TAG(a,b,c,d) DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d)

TYPE DWRITE_FONT_AXIS_TAG AS LONG
enum
    DWRITE_FONT_AXIS_TAG_WEIGHT         = DWRITE_MAKE_FONT_AXIS_TAG("w","g","h","t")
    DWRITE_FONT_AXIS_TAG_WIDTH          = DWRITE_MAKE_FONT_AXIS_TAG("w","d","t","h")
    DWRITE_FONT_AXIS_TAG_SLANT          = DWRITE_MAKE_FONT_AXIS_TAG("s","l","n","t")
    DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE   = DWRITE_MAKE_FONT_AXIS_TAG("o","p","s","z")
    DWRITE_FONT_AXIS_TAG_ITALIC         = DWRITE_MAKE_FONT_AXIS_TAG("i","t","a","l")
end enum

#define DWRITE_STANDARD_FONT_AXIS_COUNT 5

type DWRITE_FONT_AXIS_VALUE
   AS DWRITE_FONT_AXIS_TAG axisTag
   AS FLOAT value
end type

type DWRITE_FONT_AXIS_RANGE
   AS DWRITE_FONT_AXIS_TAG axisTag
   AS FLOAT minValue
   AS FLOAT maxValue
end type

TYPE DWRITE_FONT_FAMILY_MODEL AS LONG
enum
   DWRITE_FONT_FAMILY_MODEL_TYPOGRAPHIC
   DWRITE_FONT_FAMILY_MODEL_WEIGHT_STRETCH_STYLE
end enum

TYPE DWRITE_AUTOMATIC_FONT_AXES AS LONG
enum
   DWRITE_AUTOMATIC_FONT_AXES_NONE         = &h0000
   DWRITE_AUTOMATIC_FONT_AXES_OPTICAL_SIZE = &h0001
end enum

TYPE DWRITE_FONT_AXIS_ATTRIBUTES AS LONG
enum
   DWRITE_FONT_AXIS_ATTRIBUTES_NONE     = &h0000
   DWRITE_FONT_AXIS_ATTRIBUTES_VARIABLE = &h0001
   DWRITE_FONT_AXIS_ATTRIBUTES_HIDDEN   = &h0002
end enum


' ########################################################################################
' Interface name: IDWriteFactory6
' IID: {F3744D80-21F7-42EB-B35D-995BC72FC223}
' Inherited interface = IDWriteFactory5
' ########################################################################################

#ifndef __IDWriteFactory6_INTERFACE_DEFINED__
#define __IDWriteFactory6_INTERFACE_DEFINED__

TYPE IDWriteFactory6_ EXTENDS IDWriteFactory5
   DECLARE ABSTRACT FUNCTION CreateFontFaceReference6 (BYVAL fontFile AS IDWriteFontFile PTR, BYVAL faceIndex AS UINT32, _
           BYVAL fontSimulations AS DWRITE_FONT_SIMULATIONS, BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF fontFaceReference AS IDWriteFontFaceReference1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontResource (BYVAL fontFile AS IDWriteFontFile PTR, BYVAL faceIndex AS UINT32, _
           BYREF fontResource AS IDWriteFontResource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSystemFontSet6 (BYVAL includeDownloadableFonts AS BOOLEAN, BYREF fontSet AS IDWriteFontSet1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSystemFontCollection6 (BYVAL includeDownloadableFonts AS BOOLEAN, BYVAL fontFamilyModel AS DWRITE_FONT_FAMILY_MODEL, BYREF fontCollection AS IDWriteFontCollection2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontCollectionFromFontSet6 (BYVAL fontSet AS IDWriteFontSet PTR, BYVAL fontFamilyModel AS DWRITE_FONT_FAMILY_MODEL, BYREF fontCollection AS IDWriteFontCollection2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontSetBuilder6 (BYREF fontSetBuilder AS IDWriteFontSetBuilder2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTextFormat6 (BYREF fontFamilyName AS const WSTRING, BYVAL fontCollection AS IDWriteFontCollection PTR, _
           BYREF fontAxisValues AS const DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32, BYVAL fontSize AS FLOAT, _
           BYREF localeName AS const WSTRING, BYREF textFormat AS IDWriteTextFormat3 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace5
' IID: {98EFF3A5-B667-479A-B145-E2FA5B9FDC29}
' Inherited interface = IDWriteFontFace4
' ########################################################################################

#ifndef __IDWriteFontFace5_INTERFACE_DEFINED__
#define __IDWriteFontFace5_INTERFACE_DEFINED__

TYPE IDWriteFontFace5_ EXTENDS IDWriteFontFace4
   DECLARE ABSTRACT FUNCTION GetFontAxisValueCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontAxisValues (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasVariations () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetFontResource (BYREF fontResource AS IDWriteFontResource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Equals (BYVAL fontFace AS IDWriteFontFace PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontResource
' IID: {1F803A76-6871-48E8-987F-B975551C50F2}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWriteFontResource_INTERFACE_DEFINED__
#define __IDWriteFontResource_INTERFACE_DEFINED__

TYPE IDWriteFontResource_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetFontFile (BYREF fontFile AS IDWriteFontFile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFaceIndex () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontAxisCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetDefaultFontAxisValues (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisRanges (BYREF fontAxisRanges AS DWRITE_FONT_AXIS_RANGE, BYVAL fontAxisRangeCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisAttributes (BYVAL axisIndex AS UINT32) AS DWRITE_FONT_AXIS_ATTRIBUTES
   DECLARE ABSTRACT FUNCTION GetAxisNames (BYVAL axisIndex AS UINT32, BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetAxisValueNameCount (BYVAL axisIndex AS UINT32) AS UINT32
   DECLARE ABSTRACT FUNCTION GetAxisValueNames (BYVAL axisIndex AS UINT32, BYVAL axisValueIndex AS UINT32, _
           BYREF fontAxisRange AS DWRITE_FONT_AXIS_RANGE, BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION HasVariations () AS BOOL
   DECLARE ABSTRACT FUNCTION CreateFontFace (BYVAL fontSimulations AS DWRITE_FONT_SIMULATIONS, BYREF fontAxisValues AS const DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF fontFace AS IDWriteFontFace5 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFaceReference (BYVAL fontSimulations AS DWRITE_FONT_SIMULATIONS, _
           BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32, _
           BYREF fontFaceReference AS IDWriteFontFaceReference1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFaceReference1
' IID: {C081FE77-2FD1-41AC-A5A3-34983C4BA61A}
' Inherited interface = IDWriteFontFaceReference
' ########################################################################################

#ifndef __IDWriteFontFaceReference1_INTERFACE_DEFINED__
#define __IDWriteFontFaceReference1_INTERFACE_DEFINED__

TYPE IDWriteFontFaceReference1_ EXTENDS IDWriteFontFaceReference
   DECLARE ABSTRACT FUNCTION CreateFontFace1 (BYREF fontFace AS IDWriteFontFace5 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisValueCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontAxisValues (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: IDWriteFontSetBuilder2
' IID: {EE5BA612-B131-463C-8F4F-3189B9401E45}
' Inherited interface = IDWriteFontSetBuilder1
' ########################################################################################

#ifndef __IDWriteFontSetBuilder2_INTERFACE_DEFINED__
#define __IDWriteFontSetBuilder2_INTERFACE_DEFINED__

TYPE IDWriteFontSetBuilder2_ EXTENDS IDWriteFontSetBuilder1
   DECLARE ABSTRACT FUNCTION AddFont (BYVAL fontFile AS IDWriteFontFile PTR, BYVAL fontFaceIndex AS UINT32, _
           BYVAL fontSimulations AS DWRITE_FONT_SIMULATIONS, BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF fontAxisRanges AS DWRITE_FONT_AXIS_RANGE, BYVAL fontAxisRangeCount AS UINT32, _
           BYREF fproperties AS const DWRITE_FONT_PROPERTY, BYVAL propertyCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION AddFontFile2 (BYREF filePath AS const WSTRING) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontSet1
' IID: {7E9FDA85-6C92-4053-BC47-7AE3530DB4D3}
' Inherited interface = IDWriteFontSet
' ########################################################################################

#ifndef __IDWriteFontSet1_INTERFACE_DEFINED__
#define __IDWriteFontSet1_INTERFACE_DEFINED__

TYPE IDWriteFontSet1_ EXTENDS IDWriteFontSet
   DECLARE ABSTRACT FUNCTION GetMatchingFonts (BYREF fontProperty AS const DWRITE_FONT_PROPERTY, BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF matchingFonts AS IDWriteFontSet1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFirstFontResources (BYREF filteredFontSet AS IDWriteFontSet1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFilteredFonts (BYREF fproperties AS const DWRITE_FONT_PROPERTY, _
           BYVAL propertyCount AS UINT32, BYVAL selectAnyProperty AS BOOLEAN, BYREF filteredFontSet AS IDWriteFontSet1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFilteredFonts_2 (BYREF fontAxisRanges AS DWRITE_FONT_AXIS_RANGE, BYVAL fontAxisRangeCount AS UINT32, _
           BYVAL selectAnyRange AS BOOLEAN, BYREF filteredFontSet AS IDWriteFontSet1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFilteredFontsC (BYREF indices AS const UINT32, BYVAL indexCount AS UINT32, _
           BYREF filteredFontSet AS IDWriteFontSet1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFilteredFontIndices (BYREF fproperties AS DWRITE_FONT_PROPERTY, BYVAL propertyCount AS UINT32, _
           BYVAL selectAnyProperty AS BOOLEAN, BYREF indices AS UINT32, BYVAL maxIndexCount AS UINT32, BYREF actualIndexCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFilteredFontIndices_2 (BYREF fontAxisRanges AS const DWRITE_FONT_AXIS_RANGE, _
           BYVAL fontAxisRangeCount AS UINT32, BYVAL selectAnyRange AS BOOLEAN, BYREF indices AS UINT32, _
           BYVAL maxIndexCount AS UINT32, BYREF actualIndexCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisRanges (BYREF fontAxisRanges AS DWRITE_FONT_AXIS_RANGE, _
           BYVAL maxFontAxisRangeCount AS UINT32, BYREF actualFontAxisRangeCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisRanges_2 (BYVAL listIndex AS UINT32, BYREF fontAxisRanges AS DWRITE_FONT_AXIS_RANGE, _
           BYVAL maxFontAxisRangeCount AS UINT32, BYREF actualFontAxisRangeCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFaceReference1 (BYVAL listIndex AS UINT32, BYREF fontFaceReference AS IDWriteFontFaceReference1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontResource (BYVAL listIndex AS UINT32, BYREF fontResource AS IDWriteFontResource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateFontFace (BYVAL listIndex AS UINT32, BYREF fontFace AS IDWriteFontFace5 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontLocality (BYVAL listIndex AS LONG) AS DWRITE_LOCALITY
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontList2
' IID: {C0763A34-77AF-445A-B735-08C37B0A5BF5}
' Inherited interface = IDWriteFontList1
' ########################################################################################

#ifndef __IDWriteFontList2_INTERFACE_DEFINED__
#define __IDWriteFontList2_INTERFACE_DEFINED__

TYPE IDWriteFontList2_ EXTENDS IDWriteFontList1
   DECLARE ABSTRACT FUNCTION GetFontSet (BYREF fontSet AS IDWriteFontSet1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFamily2
' IID: {3ED49E77-A398-4261-B9CF-C126C2131EF3}
' Inherited interface = IDWriteFontFamily1
' Number of methods = 2
' ########################################################################################

#ifndef __IDWriteFontFamily2_INTERFACE_DEFINED__
#define __IDWriteFontFamily2_INTERFACE_DEFINED__

TYPE IDWriteFontFamily2_ EXTENDS IDWriteFontFamily1
   DECLARE ABSTRACT FUNCTION GetMatchingFonts2 (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF matchingFonts AS IDWriteFontList2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontSet (BYREF fontSet AS IDWriteFontSet1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontCollection2
' IID: {514039C6-4617-4064-BF8B-92EA83E506E0}
' Inherited interface = IDWriteFontCollection1
' ########################################################################################

#ifndef __IDWriteFontCollection2_INTERFACE_DEFINED__
#define __IDWriteFontCollection2_INTERFACE_DEFINED__

TYPE IDWriteFontCollection2_ EXTENDS IDWriteFontCollection1
   DECLARE ABSTRACT FUNCTION GetFontFamily2 (BYVAL index AS UINT32, BYREF fontFamily AS IDWriteFontFamily2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatchingFonts (BYREF familyName AS const WSTRING, BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF fontList AS IDWriteFontList2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontFamilyModel () AS DWRITE_FONT_FAMILY_MODEL
   DECLARE ABSTRACT FUNCTION GetFontSet2 (BYREF fontSet AS IDWriteFontSet1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextLayout4
' IID: {05A9BF42-223F-4441-B5FB-8263685F55E9}
' Inherited interface = IDWriteTextLayout3
' ########################################################################################

#ifndef __Afx_IDWriteTextLayout4_INTERFACE_DEFINED__
#define __Afx_IDWriteTextLayout4_INTERFACE_DEFINED__

TYPE IDWriteTextLayout4_ EXTENDS IDWriteTextLayout3
   DECLARE ABSTRACT FUNCTION SetFontAxisValues (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYVAL textRange AS DWRITE_TEXT_RANGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisValueCount (BYVAL CurrentPosition AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisValues (BYVAL currentPosition AS DWRITE_FONT_AXIS_VALUE, _
           BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32, _
           BYREF textRange AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetAutomaticFontAxes () AS DWRITE_AUTOMATIC_FONT_AXES
   DECLARE ABSTRACT FUNCTION SetAutomaticFontAxes (BYVAL automaticFontAxes AS DWRITE_AUTOMATIC_FONT_AXES) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteTextFormat3
' IID: {6D3B5641-E550-430D-A85B-B7BF48A93427}
' Inherited interface = IDWriteTextFormat2
' ########################################################################################

#ifndef __IDWriteTextFormat3_INTERFACE_DEFINED__
#define __IDWriteTextFormat3_INTERFACE_DEFINED__

TYPE IDWriteTextFormat3_ EXTENDS IDWriteTextFormat2
   DECLARE ABSTRACT FUNCTION SetFontAxisValues (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFontAxisValueCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontAxisValues (BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, BYVAL fontAxisValueCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetAutomaticFontAxes () AS DWRITE_AUTOMATIC_FONT_AXES
   DECLARE ABSTRACT FUNCTION SetAutomaticFontAxes (BYVAL automaticFontAxes AS DWRITE_AUTOMATIC_FONT_AXES) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFallback1
' IID: {2397599D-DD0D-4681-BD6A-F4F31EAADE77}
' Inherited interface = IDWriteFontFallback
' ########################################################################################

#ifndef __IDWriteFontFallback1_INTERFACE_DEFINED__
#define __IDWriteFontFallback1_INTERFACE_DEFINED__

TYPE IDWriteFontFallback1_ EXTENDS IDWriteFontFallback
   DECLARE ABSTRACT FUNCTION MapCharacters1 (BYVAL analysisSource AS IDWriteTextAnalysisSource PTR, _
           BYVAL textPosition AS UINT32, BYVAL textLength AS UINT32, BYVAL baseFontCollection AS IDWriteFontCollection PTR, _
           BYREF baseFamilyName AS const WSTRING, BYREF fontAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYREF mappedLength AS UINT32, BYREF scale AS FLOAT, _
           BYREF mappedFontFace AS IDWriteFontFace5 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontSet2
' IID: {DC7EAD19-E54C-43AF-B2DA-4E2B79BA3F7F}
' Inherited interface = IDWriteFontSet1
' ########################################################################################

#ifndef __IDWriteFontSet2_INTERFACE_DEFINED__
#define __IDWriteFontSet2_INTERFACE_DEFINED__

TYPE IDWriteFontSet2_ EXTENDS IDWriteFontSet1
   DECLARE ABSTRACT FUNCTION GetExpirationEvent () AS HANDLE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontCollection3
' IID: {A4D055A6-F9E3-4E25-93B7-9E309F3AF8E9}
' Inherited interface = IDWriteFontCollection2
' ########################################################################################

#ifndef __IDWriteFontCollection3_INTERFACE_DEFINED__
#define __IDWriteFontCollection3_INTERFACE_DEFINED__

TYPE IDWriteFontCollection3_ EXTENDS IDWriteFontCollection2
   DECLARE ABSTRACT FUNCTION GetExpirationEvent () AS HANDLE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory7
' IID: {35D0E0B3-9076-4D2E-A016-A91B568A06B4}
' Inherited interface = IDWriteFactory6
' ########################################################################################

#ifndef __IDWriteFactory7_INTERFACE_DEFINED__
#define __IDWriteFactory7_INTERFACE_DEFINED__

TYPE IDWriteFactory7_ EXTENDS IDWriteFactory6
   DECLARE ABSTRACT FUNCTION GetSystemFontSet7 (BYVAL includeDownloadableFonts AS BOOLEAN, BYREF fontSet AS IDWriteFontSet2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSystemFontCollection7 (BYVAL includeDownloadableFonts AS BOOLEAN, _
           BYVAL fontFamilyModel AS DWRITE_FONT_FAMILY_MODEL, BYREF fontCollection AS IDWriteFontCollection3 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


TYPE DWRITE_FONT_SOURCE_TYPE AS LONG
enum
   DWRITE_FONT_SOURCE_TYPE_UNKNOWN
   DWRITE_FONT_SOURCE_TYPE_PER_MACHINE
   DWRITE_FONT_SOURCE_TYPE_PER_USER
   DWRITE_FONT_SOURCE_TYPE_APPX_PACKAGE
   DWRITE_FONT_SOURCE_TYPE_REMOTE_FONT_PROVIDER
end enum


' ########################################################################################
' Interface name: IDWriteFontSet3
' IID: {7C073EF2-A7F4-4045-8C32-8AB8AE640F90}
' Inherited interface = IDWriteFontSet2
' ########################################################################################

#ifndef __IDWriteFontSet3_INTERFACE_DEFINED__
#define __IDWriteFontSet3_INTERFACE_DEFINED__

TYPE IDWriteFontSet3_ EXTENDS IDWriteFontSet2
   DECLARE ABSTRACT FUNCTION GetFontSourceType (BYVAL fontIndex AS UINT32) AS DWRITE_FONT_SOURCE_TYPE
   DECLARE ABSTRACT FUNCTION GetFontSourceNameLength (BYVAL listIndex AS UINT32) AS UINT32
   DECLARE ABSTRACT FUNCTION GetFontSourceName (BYVAL listIndex AS UINT32, BYREF stringBuffer AS const WSTRING, _
           BYVAL stringBufferSize AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace6
' IID: {C4B1FE1B-6E84-47D5-B54C-A597981B06AD}
' Inherited interface = IDWriteFontFace5
' ########################################################################################

#ifndef __IDWriteFontFace6_INTERFACE_DEFINED__
#define __IDWriteFontFace6_INTERFACE_DEFINED__

TYPE IDWriteFontFace6_ EXTENDS IDWriteFontFace5
   DECLARE ABSTRACT FUNCTION GetFamilyNames6 (BYVAL fontFamilyModel AS DWRITE_FONT_FAMILY_MODEL, BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFaceNames6 (BYVAL fontFamilyModel AS DWRITE_FONT_FAMILY_MODEL, BYREF names AS IDWriteLocalizedStrings PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontSet4
' IID: {EEC175FC-BEA9-4C86-8B53-CCBDD7DF0C82}
' Inherited interface = IDWriteFontSet3
' ########################################################################################

#ifndef __IDWriteFontSet4_INTERFACE_DEFINED__
#define __IDWriteFontSet4_INTERFACE_DEFINED__

TYPE IDWriteFontSet4_ EXTENDS IDWriteFontSet3
   DECLARE ABSTRACT FUNCTION ConvertWeightStretchStyleToFontAxisValues (BYREF inputAxisValues AS DWRITE_FONT_AXIS_VALUE, _
           BYVAL inputAxisCount AS UINT32, BYVAL fontWeight AS DWRITE_FONT_WEIGHT, BYVAL fontStretch AS DWRITE_FONT_STRETCH, _
           BYVAL fontStyle AS DWRITE_FONT_STYLE, BYVAL fontSize AS FLOAT, BYREF outputAxisValues AS DWRITE_FONT_AXIS_VALUE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatchingFonts (BYREF familyName AS const WSTRING, BYREF fontAxisValues AS const DWRITE_FONT_AXIS_VALUE, _
           BYVAL fontAxisValueCount AS UINT32, BYVAL allowedSimulations AS DWRITE_FONT_SIMULATIONS, BYREF matchingFonts AS IDWriteFontSet4 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


type DWRITE_BITMAP_DATA_BGRA32
   AS UINT32 width
   AS UINT32 height
   AS UINT32 PTR pixels
end type


' ########################################################################################
' Interface name: IDWriteBitmapRenderTarget2
' IID: {C553A742-FC01-44DA-A66E-B8B9ED6C3995}
' Inherited interface = IDWriteBitmapRenderTarget1
' ########################################################################################

#ifndef __Afx_IDWriteBitmapRenderTarget2_INTERFACE_DEFINED__
#define __Afx_IDWriteBitmapRenderTarget2_INTERFACE_DEFINED__

TYPE IDWriteBitmapRenderTarget2_ EXTENDS IDWriteBitmapRenderTarget1
   DECLARE ABSTRACT FUNCTION GetBitmapData (BYREF bitmapData AS DWRITE_BITMAP_DATA_BGRA32) AS HRESULT
END TYPE

#endif

' ########################################################################################


#ifndef DWRITE_PAINT_FEATURE_LEVEL
type DWRITE_PAINT_FEATURE_LEVEL AS INT32
enum
   DWRITE_PAINT_FEATURE_LEVEL_NONE = 0
   DWRITE_PAINT_FEATURE_LEVEL_COLR_V0 = 1
   DWRITE_PAINT_FEATURE_LEVEL_COLR_V1 = 2
end enum
#endif

TYPE DWRITE_PAINT_ATTRIBUTES AS LONG
enum
   DWRITE_PAINT_ATTRIBUTES_NONE = 0
   DWRITE_PAINT_ATTRIBUTES_USES_PALETTE = &h01
   DWRITE_PAINT_ATTRIBUTES_USES_TEXT_COLOR = &h02
end enum

type DWRITE_PAINT_COLOR
   AS DWRITE_COLOR_F value
   AS UINT16 paletteEntryIndex
   AS float alphaMultiplier
   AS DWRITE_PAINT_ATTRIBUTES colorAttributes
end type

TYPE DWRITE_COLOR_COMPOSITE_MODE AS LONG
enum
   ' // Porter-Duff modes.
   DWRITE_COLOR_COMPOSITE_CLEAR
   DWRITE_COLOR_COMPOSITE_SRC
   DWRITE_COLOR_COMPOSITE_DEST
   DWRITE_COLOR_COMPOSITE_SRC_OVER
   DWRITE_COLOR_COMPOSITE_DEST_OVER
   DWRITE_COLOR_COMPOSITE_SRC_IN
   DWRITE_COLOR_COMPOSITE_DEST_IN
   DWRITE_COLOR_COMPOSITE_SRC_OUT
   DWRITE_COLOR_COMPOSITE_DEST_OUT
   DWRITE_COLOR_COMPOSITE_SRC_ATOP
   DWRITE_COLOR_COMPOSITE_DEST_ATOP
   DWRITE_COLOR_COMPOSITE_XOR
   DWRITE_COLOR_COMPOSITE_PLUS

   ' // Separable color blend modes.
   DWRITE_COLOR_COMPOSITE_SCREEN
   DWRITE_COLOR_COMPOSITE_OVERLAY
   DWRITE_COLOR_COMPOSITE_DARKEN
   DWRITE_COLOR_COMPOSITE_LIGHTEN
   DWRITE_COLOR_COMPOSITE_COLOR_DODGE
   DWRITE_COLOR_COMPOSITE_COLOR_BURN
   DWRITE_COLOR_COMPOSITE_HARD_LIGHT
   DWRITE_COLOR_COMPOSITE_SOFT_LIGHT
   DWRITE_COLOR_COMPOSITE_DIFFERENCE
   DWRITE_COLOR_COMPOSITE_EXCLUSION
   DWRITE_COLOR_COMPOSITE_MULTIPLY

   ' // Non-separable color blend modes.
   DWRITE_COLOR_COMPOSITE_HSL_HUE
   DWRITE_COLOR_COMPOSITE_HSL_SATURATION
   DWRITE_COLOR_COMPOSITE_HSL_COLOR
   DWRITE_COLOR_COMPOSITE_HSL_LUMINOSITY
end enum

TYPE DWRITE_PAINT_TYPE AS LONG
enum
   ' // The following paint types may be returned for color feature levels greater than
   ' // or equal to DWRITE_PAINT_FEATURE_LEVEL_COLR_V0.
   DWRITE_PAINT_TYPE_NONE
   DWRITE_PAINT_TYPE_LAYERS
   DWRITE_PAINT_TYPE_SOLID_GLYPH

   ' // The following paint types may be returned for color feature levels greater than
   ' // or equal to DWRITE_PAINT_FEATURE_LEVEL_COLR_V1.
   DWRITE_PAINT_TYPE_SOLID
   DWRITE_PAINT_TYPE_LINEAR_GRADIENT
   DWRITE_PAINT_TYPE_RADIAL_GRADIENT
   DWRITE_PAINT_TYPE_SWEEP_GRADIENT
   DWRITE_PAINT_TYPE_GLYPH
   DWRITE_PAINT_TYPE_COLOR_GLYPH
   DWRITE_PAINT_TYPE_TRANSFORM
   DWRITE_PAINT_TYPE_COMPOSITE
end enum

type DWRITE_PAINT_ELEMENT
   AS DWRITE_PAINT_TYPE paintType
   union PAINT_UNION
      type PAINT_LAYERS
         AS UINT32 childCount
      end type
      type PAINT_SOLID_GLYPH
         AS UINT32 glyphIndex
         AS DWRITE_PAINT_COLOR color
      end type
      AS DWRITE_PAINT_COLOR solid
      type PAINT_LINEAR_GRADIENT
         AS UINT32 extendMode
         AS UINT32 gradientStopCount
         AS float x0
         AS float y0
         AS float x1
         AS float y1
         AS float x2
         AS float y2
      end type
      type PAINT_RADIAL_GRADIENT
         AS UINT32 extendMode
         AS UINT32 gradientStopCount
         AS float x0
         AS float y0
         AS float radius0
         AS float x1
         AS float y1
         AS float radius1
      end type
      type PAINT_SWEEP_GRADIENT
         AS UINT32 extendMode
         AS UINT32 gradientStopCount
         AS float centerX
         AS float centerY
         AS float startAngle
         AS float endAngle
      end type
      type PAINT_GLYPH
         AS UINT32 glyphIndex
      end type
      type PAINT_COLOR_GLYPH
         AS UINT32 glyphIndex
         AS D2D_RECT_F clipBox
      end type
      AS DWRITE_MATRIX transform
      type PAINT_COMPOSITE
         AS DWRITE_COLOR_COMPOSITE_MODE mode
      end type
   end union
end type


' ########################################################################################
' Interface name: IDWritePaintReader
' IID: {8128E912-3B97-42A5-AB6C-24AAD3A86E54}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDWritePaintReader_INTERFACE_DEFINED__
#define __IDWritePaintReader_INTERFACE_DEFINED__

TYPE IDWritePaintReader_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION SetCurrentGlyph (BYVAL glyphIndex AS UINT32, BYREF paintElement AS DWRITE_PAINT_ELEMENT, _
           BYVAL structSize AS UINT32, BYREF clipBox AS D2D_RECT_F, BYREF glyphAttributes AS DWRITE_PAINT_ATTRIBUTES) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTextColor (BYREF textColor AS DWRITE_COLOR_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetColorPaletteIndex (BYVAL colorPaletteIndex AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetCustomColorPalette (BYREF paletteEntries AS DWRITE_COLOR_F, BYVAL paletteEntryCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION MoveToFirstChild (BYREF paintElement AS DWRITE_PAINT_ELEMENT, _
           BYVAL structSize AS UINT32 = sizeof(DWRITE_PAINT_ELEMENT)) AS HRESULT
   DECLARE ABSTRACT FUNCTION MoveToNextSibling (BYREF paintElement AS DWRITE_PAINT_ELEMENT, _
           BYVAL structSize AS UINT32 = sizeof(DWRITE_PAINT_ELEMENT)) AS HRESULT
   DECLARE ABSTRACT FUNCTION MoveToParent () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGradientStops (BYVAL firstGradientStopIndex AS UINT32, BYVAL gradientStopCount AS UINT32, _
           BYREF gradientStops AS D2D1_GRADIENT_STOP) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGradientStopColors (BYVAL firstGradientStopIndex AS UINT32, BYVAL gradientStopCount AS UINT32, _
           BYREF gradientStopColors AS DWRITE_PAINT_COLOR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFontFace7
' IID: {3945B85B-BC95-40F7-B72C-8B73BFC7E13B}
' Inherited interface = IDWriteFontFace6
' ########################################################################################

#ifndef __IDWriteFontFace7_INTERFACE_DEFINED__
#define __IDWriteFontFace7_INTERFACE_DEFINED__

TYPE IDWriteFontFace7_ EXTENDS IDWriteFontFace6
   DECLARE ABSTRACT FUNCTION GetPaintFeatureLevel (BYVAL glyphImageFormat AS DWRITE_GLYPH_IMAGE_FORMATS) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreatePaintReader (BYVAL glyphImageFormat AS DWRITE_GLYPH_IMAGE_FORMATS, _
           BYVAL paintFeatureLevel AS DWRITE_PAINT_FEATURE_LEVEL, BYREF paintReader AS IDWritePaintReader PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDWriteFactory8
' IID: {EE0A7FB5-DEF4-4C23-A454-C9C7DC878398}
' Inherited interface = IDWriteFactory7
' ########################################################################################

#ifndef __IDWriteFactory8_INTERFACE_DEFINED__
#define __IDWriteFactory8_INTERFACE_DEFINED__

TYPE IDWriteFactory8_ EXTENDS IDWriteFactory7
   DECLARE ABSTRACT FUNCTION TranslateColorGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS DWRITE_GLYPH_RUN, _
           BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL desiredGlyphImageFormats AS DWRITE_GLYPH_IMAGE_FORMATS, _
           BYVAL paintFeatureLevel AS DWRITE_PAINT_FEATURE_LEVEL, BYVAL measuringMode AS DWRITE_MEASURING_MODE, _
           BYREF worldAndDpiTransform AS const DWRITE_MATRIX, BYVAL colorPaletteIndex AS UINT32, _
           BYREF colorEnumerator AS IDWriteColorGlyphRunEnumerator1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################
