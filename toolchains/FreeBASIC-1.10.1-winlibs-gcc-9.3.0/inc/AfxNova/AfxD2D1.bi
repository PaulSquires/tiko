' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxD2D1.bi
' Contents: Direct2D headers
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2026 José Roca
' Adaptation of the C++ headers. (c) Microsoft Corporation.

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

' IMPORTANT:
' FreeBasic is NOT ABI-compatible with MSVC when returning structures by value.
' All COM methods that return a struct in C++ MUST be rewritten to return it BYREF or
' via pointer in FreeBasic. Otherwise the vtable becomes corrupted.

' In Microsoft C++ (MSVC ABI):
' - Small structures (8, 12, 16 bytes…) may be returned in registers
'   (XMM0/XMM1 or RAX/RDX), depending on size and alignment.
' - If they cannot be returned in registers, the compiler uses a hidden pointer
'   (sret / return buffer) passed by the caller.
'
' FreeBasic does NOT follow this ABI.

' CONSEQUENCE:
' Any COM method that returns a structure BY VALUE will corrupt the call sequence,
' desynchronize the vtable, and cause subsequent methods to return invalid data or crash.
'
' Therefore, in all COM interfaces (Direct2D, DirectWrite, WIC, etc.),
' methods that return structures in C++ MUST be translated in FreeBasic as:
'
'     SUB MethodName (BYREF result AS STRUCT_TYPE)
'
' or alternatively:
'
'     SUB MethodName (BYVAL pResult AS STRUCT_TYPE PTR)
'
' Never return structures BY VALUE in FreeBasic when implementing COM.
'
' ENUMERATIONS
'
' In FreeBasic, the size of an Enum instance will be always that of an Integer
' (no matter how many defined symbols are just declarations for the compiler assignment).
'
' CONSEQUENCE
' The XXX_FORCE_DWORD = &hffffffff members have no effect in FreeBasic.
' Therefore, I have used declarations like TYPE DXGI_FORMAT AS LONG to force the values
' to be 32-bit, no matter if you use te 32 or the 64-bit compiler.


#pragma once
#include once "windows.bi"
#include once "win/unknwn.bi"
#include once "win/winerror.bi"
'#include <D2DErr.h>
'#include <D2DBaseTypes.h>
'#include once "dxgiformat.bi"
'#pragma region Desktop Family
'#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
'#include <d3d10_1.h>
'#else
'#include <d3dcommon.h>
'#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifndef __Afx_IUnknown_INTERFACE_DEFINED__
#define __Afx_IUnknown_INTERFACE_DEFINED__
TYPE Afx_IUnknown AS Afx_IUnknown_
TYPE Afx_IUnknown_ EXTENDS OBJECT
	DECLARE ABSTRACT FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
	DECLARE ABSTRACT FUNCTION AddRef () AS ULONG
	DECLARE ABSTRACT FUNCTION Release () AS ULONG
END TYPE
TYPE AFX_LPUNKNOWN AS Afx_IUnknown PTR
#endif


' ########################################################################################
'                                   *** d2dbasetypes.h ***
' ########################################################################################

#ifndef D3DCOLORVALUE
type D3DCOLORVALUE
   AS float r
   AS float g
   AS float b
   AS float a
end type
#endif

TYPE D2D_MATRIX_3X2_F
   m11 AS FLOAT
   m12 AS FLOAT
   m21 AS FLOAT
   m22 AS FLOAT
   m31 AS FLOAT
   m32 AS FLOAT
END TYPE

TYPE D2D_MATRIX_4X3_F
   m11 AS FLOAT
   m12 AS FLOAT
   m13 AS FLOAT
   m21 AS FLOAT
   m22 AS FLOAT
   m23 AS FLOAT
   m31 AS FLOAT
   m32 AS FLOAT
   m33 AS FLOAT
   m41 AS FLOAT
   m42 AS FLOAT
   m43 AS FLOAT
END TYPE

TYPE D2D_MATRIX_4X4_F
   m11 AS FLOAT
   m12 AS FLOAT
   m13 AS FLOAT
   m14 AS FLOAT
   m21 AS FLOAT
   m22 AS FLOAT
   m23 AS FLOAT
   m24 AS FLOAT
   m31 AS FLOAT
   m32 AS FLOAT
   m33 AS FLOAT
   m34 AS FLOAT
   m41 AS FLOAT
   m42 AS FLOAT
   m43 AS FLOAT
   m44 AS FLOAT
END TYPE

TYPE D2D_MATRIX_5X4_F
   m11 AS FLOAT
   m12 AS FLOAT
   m13 AS FLOAT
   m14 AS FLOAT
   m21 AS FLOAT
   m22 AS FLOAT
   m23 AS FLOAT
   m24 AS FLOAT
   m31 AS FLOAT
   m32 AS FLOAT
   m33 AS FLOAT
   m34 AS FLOAT
   m41 AS FLOAT
   m42 AS FLOAT
   m43 AS FLOAT
   m44 AS FLOAT
   m51 AS FLOAT
   m52 AS FLOAT
   m53 AS FLOAT
   m54 AS FLOAT
END TYPE

type D2D_POINT_2F
   AS FLOAT x
   AS FLOAT y
end type

#define D2D_POINT_2L POINT

type D2D_POINT_2U
   AS UINT32 x
   AS UINT32 y
end type

type D2D_RECT_F
   AS FLOAT left
   AS FLOAT top
   AS FLOAT right
   AS FLOAT bottom
end type

type D2D_RECT_U
   AS UINT32 left
   AS UINT32 top
   AS UINT32 right
   AS UINT32 bottom
end type

#define D2D_RECT_L RECT

type D2D_SIZE_F
   AS FLOAT width
   AS FLOAT height
end type

type D2D_SIZE_U
   AS UINT32 width
   AS UINT32 height
end type

' --- ver dcommon ---
'#define D2D1_POINT_2U D2D_POINT_2U
'#define D2D1_POINT_2F D2D_POINT_2F
'#define D2D1_RECT_F D2D_RECT_F
'#define D2D1_RECT_U D2D_RECT_U
'#define D2D1_SIZE_F D2D_SIZE_F
'#define D2D1_SIZE_U D2D_SIZE_U
#define D2D1_COLOR_F D2D_COLOR_F
'#define D2D1_MATRIX_3X2_F D2D_MATRIX_3X2_F
#define D2D1_TAG UINT64


type D2D_VECTOR_2F
   AS FLOAT x
   AS FLOAT y
end type

type D2D_VECTOR_3F
   AS FLOAT x
   AS FLOAT y
   AS FLOAT z
end type

type D2D_VECTOR_4F
   AS FLOAT x
   AS FLOAT y
   AS FLOAT z
   AS FLOAT w
end type

' ########################################################################################
'                                   *** D2DErr.h ***
' ########################################################################################

' NOTE: The winerror.bi file provided by FreeBasic is outdated.

' D2D Status Codes

#define FACILITY_D2D &h899
#define MAKE_D2DHR(sev,code) MAKE_HRESULT(sev,FACILITY_D2D,(code))
#define MAKE_D2DHR_ERR(code) MAKE_D2DHR(1,code)

' D2D error codes
' // Error codes shared with WINCODECS

' // The pixel format is not supported.
#define WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT   _HRESULT_TYPEDEF_(&h88982f80)
#define D2DERR_UNSUPPORTED_PIXEL_FORMAT   WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT

' // Error codes that were already returned in prior versions and were part of the MIL facility.

' // Error codes mapped from WIN32 where there isn't already another HRESULT based define

' // The supplied buffer was too small to accommodate the data.
#define D2DERR_INSUFFICIENT_BUFFER   HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)

' // The file specified was not found.
#define D2DERR_FILE_NOT_FOUND   HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)

' // D2D specific codes now live in winerror.h

' /* may be defined from d2derr.h */
#define D2DERR_WRONG_STATE                           _HRESULT_TYPEDEF_(&h88990001)
#define D2DERR_NOT_INITIALIZED                       _HRESULT_TYPEDEF_(&h88990002)
#define D2DERR_UNSUPPORTED_OPERATION                 _HRESULT_TYPEDEF_(&h88990003)
#define D2DERR_SCANNER_FAILED                        _HRESULT_TYPEDEF_(&h88990004)
#define D2DERR_SCREEN_ACCESS_DENIED                  _HRESULT_TYPEDEF_(&h88990005)
#define D2DERR_DISPLAY_STATE_INVALID                 _HRESULT_TYPEDEF_(&h88990006)
#define D2DERR_ZERO_VECTOR                           _HRESULT_TYPEDEF_(&h88990007)
#define D2DERR_INTERNAL_ERROR                        _HRESULT_TYPEDEF_(&h88990008)
#define D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED          _HRESULT_TYPEDEF_(&h88990009)
#define D2DERR_INVALID_CALL                          _HRESULT_TYPEDEF_(&h8899000A)
#define D2DERR_NO_HARDWARE_DEVICE                    _HRESULT_TYPEDEF_(&h8899000B)
#define D2DERR_RECREATE_TARGET                       _HRESULT_TYPEDEF_(&h8899000C)
#define D2DERR_TOO_MANY_SHADER_ELEMENTS              _HRESULT_TYPEDEF_(&h8899000D)
#define D2DERR_SHADER_COMPILE_FAILED                 _HRESULT_TYPEDEF_(&h8899000E)
#define D2DERR_MAX_TEXTURE_SIZE_EXCEEDED             _HRESULT_TYPEDEF_(&h8899000F)
#define D2DERR_UNSUPPORTED_VERSION                   _HRESULT_TYPEDEF_(&h88990010)
#define D2DERR_BAD_NUMBER                            _HRESULT_TYPEDEF_(&h88990011)
#define D2DERR_WRONG_FACTORY                         _HRESULT_TYPEDEF_(&h88990012)
#define D2DERR_LAYER_ALREADY_IN_USE                  _HRESULT_TYPEDEF_(&h88990013)
#define D2DERR_POP_CALL_DID_NOT_MATCH_PUSH           _HRESULT_TYPEDEF_(&h88990014)
#define D2DERR_WRONG_RESOURCE_DOMAIN                 _HRESULT_TYPEDEF_(&h88990015)
#define D2DERR_PUSH_POP_UNBALANCED                   _HRESULT_TYPEDEF_(&h88990016)
#define D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT   _HRESULT_TYPEDEF_(&h88990017)
#define D2DERR_INCOMPATIBLE_BRUSH_TYPES              _HRESULT_TYPEDEF_(&h88990018)
#define D2DERR_WIN32_ERROR                           _HRESULT_TYPEDEF_(&h88990019)
#define D2DERR_TARGET_NOT_GDI_COMPATIBLE             _HRESULT_TYPEDEF_(&h8899001A)
#define D2DERR_TEXT_EFFECT_IS_WRONG_TYPE             _HRESULT_TYPEDEF_(&h8899001B)
#define D2DERR_TEXT_RENDERER_NOT_RELEASED            _HRESULT_TYPEDEF_(&h8899001C)
#define D2DERR_EXCEEDS_MAX_BITMAP_SIZE               _HRESULT_TYPEDEF_(&h8899001D)
#define D2DERR_INVALID_GRAPH_CONFIGURATION           _HRESULT_TYPEDEF_(&h8899001E)
#define D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION  _HRESULT_TYPEDEF_(&h8899001F)
#define D2DERR_CYCLIC_GRAPH                          _HRESULT_TYPEDEF_(&h88990020)
#define D2DERR_BITMAP_CANNOT_DRAW                    _HRESULT_TYPEDEF_(&h88990021)
#define D2DERR_OUTSTANDING_BITMAP_REFERENCES         _HRESULT_TYPEDEF_(&h88990022)
#define D2DERR_ORIGINAL_TARGET_NOT_BOUND             _HRESULT_TYPEDEF_(&h88990023)
#define D2DERR_INVALID_TARGET                        _HRESULT_TYPEDEF_(&h88990024)
#define D2DERR_BITMAP_BOUND_AS_TARGET                _HRESULT_TYPEDEF_(&h88990025)
#define D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES      _HRESULT_TYPEDEF_(&h88990026)
#define D2DERR_INTERMEDIATE_TOO_LARGE                _HRESULT_TYPEDEF_(&h88990027)
#define D2DERR_EFFECT_IS_NOT_REGISTERED              _HRESULT_TYPEDEF_(&h88990028)
#define D2DERR_INVALID_PROPERTY                      _HRESULT_TYPEDEF_(&h88990029)
#define D2DERR_NO_SUBPROPERTIES                      _HRESULT_TYPEDEF_(&h8899002A)
#define D2DERR_PRINT_JOB_CLOSED                      _HRESULT_TYPEDEF_(&h8899002B)
#define D2DERR_PRINT_FORMAT_NOT_SUPPORTED            _HRESULT_TYPEDEF_(&h8899002C)
#define D2DERR_TOO_MANY_TRANSFORM_INPUTS             _HRESULT_TYPEDEF_(&h8899002D)
#define D2DERR_INVALID_GLYPH_IMAGE                   _HRESULT_TYPEDEF_(&h8899002E)

' ########################################################################################
'                                 *** dxgicommon.h ***
' ########################################################################################

type DXGI_RATIONAL
   AS UINT Numerator
   AS UINT Denominator
end type

'// The following values are used with DXGI_SAMPLE_DESC::Quality:
CONST DXGI_STANDARD_MULTISAMPLE_QUALITY_PATTERN = &hffffffff
CONST DXGI_CENTER_MULTISAMPLE_QUALITY_PATTERN = &hfffffffe

type DXGI_SAMPLE_DESC
   AS UINT Count
   AS UINT Quality
END TYPE

TYPE DXGI_COLOR_SPACE_TYPE AS LONG
enum
   DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709             = 0
   DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709             = 1
   DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709           = 2
   DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020          = 3
   DXGI_COLOR_SPACE_RESERVED                           = 4
   DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601      = 5
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601         = 6
   DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601           = 7
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709         = 8
   DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709           = 9
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020        = 10
   DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020          = 11
   DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020          = 12
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020      = 13
   DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020        = 14
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020     = 15
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020   = 16
   DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020            = 17
   DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020    = 18
   DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020      = 19
   DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709           = 20
   DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020          = 21
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709         = 22
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020        = 23
   DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020     = 24
   DXGI_COLOR_SPACE_CUSTOM                             = &hFFFFFFFF
end enum

' ########################################################################################
'                                 *** dxgiformat.h ***
' ########################################################################################
TYPE DXGI_FORMAT AS LONG
enum
   DXGI_FORMAT_UNKNOWN	                   = 0
   DXGI_FORMAT_R32G32B32A32_TYPELESS       = 1
   DXGI_FORMAT_R32G32B32A32_FLOAT          = 2
   DXGI_FORMAT_R32G32B32A32_UINT           = 3
   DXGI_FORMAT_R32G32B32A32_SINT           = 4
   DXGI_FORMAT_R32G32B32_TYPELESS          = 5
   DXGI_FORMAT_R32G32B32_FLOAT             = 6
   DXGI_FORMAT_R32G32B32_UINT              = 7
   DXGI_FORMAT_R32G32B32_SINT              = 8
   DXGI_FORMAT_R16G16B16A16_TYPELESS       = 9
   DXGI_FORMAT_R16G16B16A16_FLOAT          = 10
   DXGI_FORMAT_R16G16B16A16_UNORM          = 11
   DXGI_FORMAT_R16G16B16A16_UINT           = 12
   DXGI_FORMAT_R16G16B16A16_SNORM          = 13
   DXGI_FORMAT_R16G16B16A16_SINT           = 14
   DXGI_FORMAT_R32G32_TYPELESS             = 15
   DXGI_FORMAT_R32G32_FLOAT                = 16
   DXGI_FORMAT_R32G32_UINT                 = 17
   DXGI_FORMAT_R32G32_SINT                 = 18
   DXGI_FORMAT_R32G8X24_TYPELESS           = 19
   DXGI_FORMAT_D32_FLOAT_S8X24_UINT        = 20
   DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS    = 21
   DXGI_FORMAT_X32_TYPELESS_G8X24_UINT     = 22
   DXGI_FORMAT_R10G10B10A2_TYPELESS        = 23
   DXGI_FORMAT_R10G10B10A2_UNORM           = 24
   DXGI_FORMAT_R10G10B10A2_UINT            = 25
   DXGI_FORMAT_R11G11B10_FLOAT             = 26
   DXGI_FORMAT_R8G8B8A8_TYPELESS           = 27
   DXGI_FORMAT_R8G8B8A8_UNORM              = 28
   DXGI_FORMAT_R8G8B8A8_UNORM_SRGB         = 29
   DXGI_FORMAT_R8G8B8A8_UINT               = 30
   DXGI_FORMAT_R8G8B8A8_SNORM              = 31
   DXGI_FORMAT_R8G8B8A8_SINT               = 32
   DXGI_FORMAT_R16G16_TYPELESS             = 33
   DXGI_FORMAT_R16G16_FLOAT                = 34
   DXGI_FORMAT_R16G16_UNORM                = 35
   DXGI_FORMAT_R16G16_UINT                 = 36
   DXGI_FORMAT_R16G16_SNORM                = 37
   DXGI_FORMAT_R16G16_SINT                 = 38
   DXGI_FORMAT_R32_TYPELESS                = 39
   DXGI_FORMAT_D32_FLOAT                   = 40
   DXGI_FORMAT_R32_FLOAT                   = 41
   DXGI_FORMAT_R32_UINT                    = 42
   DXGI_FORMAT_R32_SINT                    = 43
   DXGI_FORMAT_R24G8_TYPELESS              = 44
   DXGI_FORMAT_D24_UNORM_S8_UINT           = 45
   DXGI_FORMAT_R24_UNORM_X8_TYPELESS       = 46
   DXGI_FORMAT_X24_TYPELESS_G8_UINT        = 47
   DXGI_FORMAT_R8G8_TYPELESS               = 48
   DXGI_FORMAT_R8G8_UNORM                  = 49
   DXGI_FORMAT_R8G8_UINT                   = 50
   DXGI_FORMAT_R8G8_SNORM                  = 51
   DXGI_FORMAT_R8G8_SINT                   = 52
   DXGI_FORMAT_R16_TYPELESS                = 53
   DXGI_FORMAT_R16_FLOAT                   = 54
   DXGI_FORMAT_D16_UNORM                   = 55
   DXGI_FORMAT_R16_UNORM                   = 56
   DXGI_FORMAT_R16_UINT                    = 57
   DXGI_FORMAT_R16_SNORM                   = 58
   DXGI_FORMAT_R16_SINT                    = 59
   DXGI_FORMAT_R8_TYPELESS                 = 60
   DXGI_FORMAT_R8_UNORM                    = 61
   DXGI_FORMAT_R8_UINT                     = 62
   DXGI_FORMAT_R8_SNORM                    = 63
   DXGI_FORMAT_R8_SINT                     = 64
   DXGI_FORMAT_A8_UNORM                    = 65
   DXGI_FORMAT_R1_UNORM                    = 66
   DXGI_FORMAT_R9G9B9E5_SHAREDEXP          = 67
   DXGI_FORMAT_R8G8_B8G8_UNORM             = 68
   DXGI_FORMAT_G8R8_G8B8_UNORM             = 69
   DXGI_FORMAT_BC1_TYPELESS                = 70
   DXGI_FORMAT_BC1_UNORM                   = 71
   DXGI_FORMAT_BC1_UNORM_SRGB              = 72
   DXGI_FORMAT_BC2_TYPELESS                = 73
   DXGI_FORMAT_BC2_UNORM                   = 74
   DXGI_FORMAT_BC2_UNORM_SRGB              = 75
   DXGI_FORMAT_BC3_TYPELESS                = 76
   DXGI_FORMAT_BC3_UNORM                   = 77
   DXGI_FORMAT_BC3_UNORM_SRGB              = 78
   DXGI_FORMAT_BC4_TYPELESS                = 79
   DXGI_FORMAT_BC4_UNORM                   = 80
   DXGI_FORMAT_BC4_SNORM                   = 81
   DXGI_FORMAT_BC5_TYPELESS                = 82
   DXGI_FORMAT_BC5_UNORM                   = 83
   DXGI_FORMAT_BC5_SNORM                   = 84
   DXGI_FORMAT_B5G6R5_UNORM                = 85
   DXGI_FORMAT_B5G5R5A1_UNORM              = 86
   DXGI_FORMAT_B8G8R8A8_UNORM              = 87
   DXGI_FORMAT_B8G8R8X8_UNORM              = 88
   DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM  = 89
   DXGI_FORMAT_B8G8R8A8_TYPELESS           = 90
   DXGI_FORMAT_B8G8R8A8_UNORM_SRGB         = 91
   DXGI_FORMAT_B8G8R8X8_TYPELESS           = 92
   DXGI_FORMAT_B8G8R8X8_UNORM_SRGB         = 93
   DXGI_FORMAT_BC6H_TYPELESS               = 94
   DXGI_FORMAT_BC6H_UF16                   = 95
   DXGI_FORMAT_BC6H_SF16                   = 96
   DXGI_FORMAT_BC7_TYPELESS                = 97
   DXGI_FORMAT_BC7_UNORM                   = 98
   DXGI_FORMAT_BC7_UNORM_SRGB              = 99
   DXGI_FORMAT_AYUV                        = 100
   DXGI_FORMAT_Y410                        = 101
   DXGI_FORMAT_Y416                        = 102
   DXGI_FORMAT_NV12                        = 103
   DXGI_FORMAT_P010                        = 104
   DXGI_FORMAT_P016                        = 105
   DXGI_FORMAT_420_OPAQUE                  = 106
   DXGI_FORMAT_YUY2                        = 107
   DXGI_FORMAT_Y210                        = 108
   DXGI_FORMAT_Y216                        = 109
   DXGI_FORMAT_NV11                        = 110
   DXGI_FORMAT_AI44                        = 111
   DXGI_FORMAT_IA44                        = 112
   DXGI_FORMAT_P8                          = 113
   DXGI_FORMAT_A8P8                        = 114
   DXGI_FORMAT_B4G4R4A4_UNORM              = 115
   DXGI_FORMAT_P208                        = 130
   DXGI_FORMAT_V208                        = 131
   DXGI_FORMAT_V408                        = 132
   DXGI_FORMAT_FORCE_UINT                  = &hffffffff
end enum
' ########################################################################################

' ########################################################################################
'                                *** dxgitype.h ***
' ########################################################################################

#define _FACDXGI    &h87a
#define MAKE_DXGI_HRESULT(code) MAKE_HRESULT(1, _FACDXGI, code)
#define MAKE_DXGI_STATUS(code)  MAKE_HRESULT(0, _FACDXGI, code)

'// DXGI error messages have moved to winerror.h

#define DXGI_CPU_ACCESS_NONE       = 0
#define DXGI_CPU_ACCESS_DYNAMIC    = 1
#define DXGI_CPU_ACCESS_READ_WRITE = 2 
#define DXGI_CPU_ACCESS_SCRATCH    = 3
#define DXGI_CPU_ACCESS_FIELD      = 15

type DXGI_RGB
   AS float Red
   AS float Green
   AS float Blue
end type

#define DXGI_RGBA D3DCOLORVALUE

type DXGI_GAMMA_CONTROL
   AS DXGI_RGB Scale
   AS DXGI_RGB Offset
   AS DXGI_RGB GammaCurve(1024)
end type

type DXGI_GAMMA_CONTROL_CAPABILITIES
   AS BOOL ScaleAndOffsetSupported
   AS float MaxConvertedValue
   AS float MinConvertedValue
   AS UINT NumGammaControlPoints
   AS float ControlPointPositions(1024)
end type

TYPE DXGI_MODE_SCANLINE_ORDER AS LONG
enum
   DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED        = 0
   DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE        = 1
   DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST  = 2
   DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST  = 3
end enum

TYPE DXGI_MODE_SCALING AS LONG
enum
   DXGI_MODE_SCALING_UNSPECIFIED   = 0
   DXGI_MODE_SCALING_CENTERED      = 1
   DXGI_MODE_SCALING_STRETCHED     = 2
end enum

TYPE DXGI_MODE_ROTATION AS LONG
enum
   DXGI_MODE_ROTATION_UNSPECIFIED  = 0
   DXGI_MODE_ROTATION_IDENTITY     = 1
   DXGI_MODE_ROTATION_ROTATE90     = 2
   DXGI_MODE_ROTATION_ROTATE180    = 3
   DXGI_MODE_ROTATION_ROTATE270    = 4
end enum

type DXGI_MODE_DESC
   AS UINT Width
   AS UINT Height
   AS DXGI_RATIONAL RefreshRate
   AS DXGI_FORMAT Format
   AS DXGI_MODE_SCANLINE_ORDER ScanlineOrdering
   AS DXGI_MODE_SCALING Scaling
end type

type DXGI_JPEG_DC_HUFFMAN_TABLE
   AS BYTE CodeCounts(11)
   AS BYTE CodeValues(11)
end type

type DXGI_JPEG_AC_HUFFMAN_TABLE
   AS BYTE CodeCounts(15)
   AS BYTE CodeValues(161)
end type

type DXGI_JPEG_QUANTIZATION_TABLE
   AS BYTE Elements(63)
end type

' ########################################################################################

' ########################################################################################
'                                *** dcommon.h ***
' ########################################################################################

TYPE D3D_FEATURE_LEVEL AS LONG
enum
  D3D_FEATURE_LEVEL_1_0_GENERIC
  D3D_FEATURE_LEVEL_1_0_CORE
  D3D_FEATURE_LEVEL_9_1
  D3D_FEATURE_LEVEL_9_2
  D3D_FEATURE_LEVEL_9_3
  D3D_FEATURE_LEVEL_10_0
  D3D_FEATURE_LEVEL_10_1
  D3D_FEATURE_LEVEL_11_0
  D3D_FEATURE_LEVEL_11_1
  D3D_FEATURE_LEVEL_12_0
  D3D_FEATURE_LEVEL_12_1
  D3D_FEATURE_LEVEL_12_2
end enum

TYPE DWRITE_MEASURING_MODE AS LONG
enum
   DWRITE_MEASURING_MODE_NATURAL
   DWRITE_MEASURING_MODE_GDI_CLASSIC
   DWRITE_MEASURING_MODE_GDI_NATURAL
end enum

TYPE DWRITE_GLYPH_IMAGE_FORMATS AS LONG
enum
   DWRITE_GLYPH_IMAGE_FORMATS_NONE = &h00000000
   DWRITE_GLYPH_IMAGE_FORMATS_TRUETYPE = &h00000001
   DWRITE_GLYPH_IMAGE_FORMATS_CFF = &h00000002
   DWRITE_GLYPH_IMAGE_FORMATS_COLR = &h00000004
   DWRITE_GLYPH_IMAGE_FORMATS_SVG = &h00000008
   DWRITE_GLYPH_IMAGE_FORMATS_PNG = &h00000010
   DWRITE_GLYPH_IMAGE_FORMATS_JPEG = &h00000020
   DWRITE_GLYPH_IMAGE_FORMATS_TIFF = &h00000040
   DWRITE_GLYPH_IMAGE_FORMATS_PREMULTIPLIED_B8G8R8A8 = &h00000080
   DWRITE_GLYPH_IMAGE_FORMATS_COLR_PAINT_TREE = &h00000100
end enum

TYPE D2D1_ALPHA_MODE AS LONG
enum
   D2D1_ALPHA_MODE_UNKNOWN = 0
   D2D1_ALPHA_MODE_PREMULTIPLIED = 1
   D2D1_ALPHA_MODE_STRAIGHT = 2
   D2D1_ALPHA_MODE_IGNORE = 3
   D2D1_ALPHA_MODE_FORCE_DWORD = &hffffffff
end enum

type D2D1_PIXEL_FORMAT
   AS DXGI_FORMAT format
   AS D2D1_ALPHA_MODE alphaMode
end type

#define D2D1_POINT_2F D2D_POINT_2F
#define D2D1_POINT_2U D2D_POINT_2U
#define D2D1_POINT_2L D2D_POINT_2L
#define D2D1_RECT_F D2D_RECT_F
#define D2D1_RECT_U D2D_RECT_U
#define D2D1_RECT_L D2D_RECT_L
#define D2D1_SIZE_F D2D_SIZE_F
#define D2D1_SIZE_U D2D_SIZE_U
#define D2D1_MATRIX_3X2_F D2D_MATRIX_3X2_F

' ########################################################################################

' ========================================================================================
' IIDs (Interface identifiers) - d2d1.h
' ========================================================================================

DIM SHARED IID_ID2D1Resource AS GUID                 = TYPE<GUID>(&h2cd90691, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1Image AS GUID                    = TYPE<GUID>(&h65019f75, &h8da2, &h497c, {&hb3, &h2c, &hdf, &ha3, &h4e, &h48, &hed, &he6})
DIM SHARED IID_ID2D1Bitmap AS GUID                   = TYPE<GUID>(&ha2296057, &hea42, &h4099, {&h98, &h3b, &h53, &h9f, &hb6, &h50, &h54, &h26})
DIM SHARED IID_ID2D1GradientStopCollection AS GUID   = TYPE<GUID>(&h2cd906a7, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1Brush AS GUID                    = TYPE<GUID>(&h2cd906a8, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1BitmapBrush AS GUID              = TYPE<GUID>(&h2cd906aa, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1SolidColorBrush AS GUID          = TYPE<GUID>(&h2cd906a9, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1LinearGradientBrush AS GUID      = TYPE<GUID>(&h2cd906ab, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1RadialGradientBrush AS GUID      = TYPE<GUID>(&h2cd906ac, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1StrokeStyle AS GUID              = TYPE<GUID>(&h2cd9069d, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1Geometry AS GUID                 = TYPE<GUID>(&h2cd906a1, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1RectangleGeometry AS GUID        = TYPE<GUID>(&h2cd906a2, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1RoundedRectangleGeometry AS GUID = TYPE<GUID>(&h2cd906a3, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1EllipseGeometry AS GUID          = TYPE<GUID>(&h2cd906a4, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1GeometryGroup AS GUID            = TYPE<GUID>(&h2cd906a6, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1TransformedGeometry AS GUID      = TYPE<GUID>(&h2cd906bb, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1SimplifiedGeometrySink AS GUID   = TYPE<GUID>(&h2cd9069e, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1GeometrySink AS GUID             = TYPE<GUID>(&h2cd9069f, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1TessellationSink AS GUID         = TYPE<GUID>(&h2cd906c1, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1PathGeometry AS GUID             = TYPE<GUID>(&h2cd906a5, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1Mesh AS GUID                     = TYPE<GUID>(&h2cd906c2, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1Layer AS GUID                    = TYPE<GUID>(&h2cd9069b, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1DrawingStateBlock AS GUID        = TYPE<GUID>(&h28506e39, &hebf6, &h46a1, {&hbb, &h47, &hfd, &h85, &h56, &h5a, &hb9, &h57})
DIM SHARED IID_ID2D1RenderTarget AS GUID             = TYPE<GUID>(&h2cd90694, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1BitmapRenderTarget AS GUID       = TYPE<GUID>(&h2cd90695, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})
DIM SHARED IID_ID2D1DCRenderTarget AS GUID           = TYPE<GUID>(&h1c51bc64, &hde61, &h46fd, {&h98, &h99, &h63, &ha5, &hd8, &hf0, &h39, &h50})
DIM SHARED IID_ID2D1GdiInteropRenderTarget AS GUID   = TYPE<GUID>(&he0db51c3, &h6f77, &h4bae, {&hb3, &hd5, &he4, &h75, &h09, &hb3, &h58, &h38})
DIM SHARED IID_ID2D1Factory AS GUID                  = TYPE<GUID>(&h06152247, &h6f50, &h465a, {&h92, &h45, &h11, &h8b, &hfd, &h3b, &h60, &h07})
DIM SHARED IID_ID2D1HwndRenderTarget AS GUID         = TYPE<GUID>(&h2cd90698, &h12e2, &h11dc, {&h9f, &hed, &h00, &h11, &h43, &ha0, &h55, &hf9})

'// Forward declarations
TYPE IDWriteTextFormat AS IDWriteTextFormat_
TYPE IDWriteTextLayout AS IDWriteTextLayout_
TYPE IDWriteRenderingParams AS IDWriteRenderingParams_
TYPE IDXGISurface AS IDXGISurface_
TYPE IWICBitmap AS IWICBitmap_
TYPE IWICBitmapSource AS IWICBitmapSource_

TYPE ID2D1Bitmap AS ID2D1Bitmap_
TYPE ID2D1BitmapBrush AS ID2D1BitmapBrush_
TYPE ID2D1BitmapRenderTarget AS ID2D1BitmapRenderTarget_
TYPE ID2D1Brush AS ID2D1Brush_
TYPE ID2D1DCRenderTarget AS ID2D1DCRenderTarget_
TYPE ID2D1DrawingStateBlock AS ID2D1DrawingStateBlock_
TYPE ID2D1EllipseGeometry AS ID2D1EllipseGeometry_
TYPE ID2D1Factory AS ID2D1Factory_
TYPE ID2D1GdiInteropRenderTarget AS ID2D1GdiInteropRenderTarget_
TYPE ID2D1Geometry AS ID2D1Geometry_
TYPE ID2D1GeometryGroup AS ID2D1GeometryGroup_
TYPE ID2D1GeometrySink AS ID2D1GeometrySink_
TYPE ID2D1GradientStopCollection AS ID2D1GradientStopCollection_
TYPE ID2D1HwndRenderTarget AS ID2D1HwndRenderTarget_
TYPE ID2D1Image AS ID2D1Image_
TYPE ID2D1Layer AS ID2D1Layer_
TYPE ID2D1LinearGradientBrush AS ID2D1LinearGradientBrush_
TYPE ID2D1Mesh AS ID2D1Mesh_
TYPE ID2D1PathGeometry AS ID2D1PathGeometry_
TYPE ID2D1RadialGradientBrush AS ID2D1RadialGradientBrush_
TYPE ID2D1RectangleGeometry AS ID2D1RectangleGeometry_
TYPE ID2D1RenderTarget AS ID2D1RenderTarget_
TYPE ID2D1Resource AS ID2D1Resource_
TYPE ID2D1RoundedRectangleGeometry AS ID2D1RoundedRectangleGeometry_
TYPE ID2D1SimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink_
TYPE ID2D1SolidColorBrush AS ID2D1SolidColorBrush_
TYPE ID2D1StrokeStyle AS ID2D1StrokeStyle_
TYPE ID2D1TessellationSink AS ID2D1TessellationSink_
TYPE ID2D1TransformedGeometry AS ID2D1TransformedGeometry_

'#define D2D1_INVALID_TAG ULONGLONG_MAX
#define D2D1_INVALID_TAG 18446744073709551615ULL
#define D2D1_DEFAULT_FLATTENING_TOLERANCE 0.25f

' ========================================================================================
' This defines the superset of interpolation mode supported by D2D APIs and built-in effects
' ========================================================================================
CONST D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR = 0
CONST D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR = 1
CONST D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC = 2
CONST D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR = 3
CONST D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC = 4
CONST D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC = 5
CONST D2D1_INTERPOLATION_MODE_DEFINITION_FANT = 6
CONST D2D1_INTERPOLATION_MODE_DEFINITION_MIPMAP_LINEAR = 7

TYPE DWRITE_GLYPH_OFFSET
   advanceOffset AS FLOAT
   ascenderOffset AS FLOAT
END TYPE

TYPE IDWriteFontFace AS IDWriteFontFace_

TYPE DWRITE_GLYPH_RUN
   fontFace AS IDWriteFontFace PTR
   fontEmSize AS FLOAT
   glyphCount AS UINT32
   glyphIndices AS UINT16 PTR
   glyphAdvances AS FLOAT PTR
   glyphOffsets AS DWRITE_GLYPH_OFFSET PTR
   isSideways AS BOOL
   bidiLevel AS UINT32
END TYPE

' ========================================================================================
' This determines what gamma is used for interpolation/blending.
' ========================================================================================
TYPE D2D1_GAMMA AS LONG
enum
   D2D1_GAMMA_2_2 = 0
   D2D1_GAMMA_1_0 = 1
   D2D1_GAMMA_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Specifies what the contents are of an opacity mask.
' ========================================================================================
TYPE D2D1_OPACITY_MASK_CONTENT AS LONG
enum
   D2D1_OPACITY_MASK_CONTENT_GRAPHICS = 0
   D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL = 1
   D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE = 2
   D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Enum which describes how to sample from a source outside its base tile.
' ========================================================================================
TYPE D2D1_EXTEND_MODE AS LONG
enum
   D2D1_EXTEND_MODE_CLAMP = 0
   D2D1_EXTEND_MODE_WRAP = 1
   D2D1_EXTEND_MODE_MIRROR = 2
   D2D1_EXTEND_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Enum which describes the manner in which we render edges of non-text primitives.
' ========================================================================================
TYPE D2D1_ANTIALIAS_MODE AS LONG
enum
   D2D1_ANTIALIAS_MODE_PER_PRIMITIVE = 0
   D2D1_ANTIALIAS_MODE_ALIASED = 1
   D2D1_ANTIALIAS_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes the antialiasing mode used for drawing text.
' ========================================================================================
TYPE D2D1_TEXT_ANTIALIAS_MODE AS LONG
enum
   D2D1_TEXT_ANTIALIAS_MODE_DEFAULT = 0
   D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE = 1
   D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE = 2
   D2D1_TEXT_ANTIALIAS_MODE_ALIASED = 3
   D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Specifies the algorithm that is used when images are scaled or rotated. Note
' Starting in Windows 8, more interpolations modes are available. See
' D2D1_INTERPOLATION_MODE for more info.
' ========================================================================================
TYPE D2D1_BITMAP_INTERPOLATION_MODE AS LONG
enum
   D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR = D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR
   D2D1_BITMAP_INTERPOLATION_MODE_LINEAR = D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR
   D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Modifications made to the draw text call that influence how the text is rendered.
' ========================================================================================
TYPE D2D1_DRAW_TEXT_OPTIONS AS LONG
enum
   D2D1_DRAW_TEXT_OPTIONS_NO_SNAP = &h00000001
   D2D1_DRAW_TEXT_OPTIONS_CLIP = &h00000002
   D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT = &h00000004
   D2D1_DRAW_TEXT_OPTIONS_DISABLE_COLOR_BITMAP_SNAPPING = &h00000008
   D2D1_DRAW_TEXT_OPTIONS_NONE = &h00000000
   D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD = &hffffffff
end enum

#ifndef D3DCOLORVALUE
type D3DCOLORVALUE
  AS FLOAT r
  AS FLOAT g
  AS FLOAT b
  AS FLOAT a
end type
#endif

#define D2D_COLOR_F D3DCOLORVALUE

' ========================================================================================
' Describes the pixel format and dpi of a bitmap.
' ========================================================================================
type D2D1_BITMAP_PROPERTIES
   AS D2D1_PIXEL_FORMAT pixelFormat
   AS FLOAT dpiX
   AS FLOAT dpiY
end type

' ========================================================================================
' Contains the position and color of a gradient stop.
' ========================================================================================
type D2D1_GRADIENT_STOP
   AS FLOAT position
   AS D2D1_COLOR_F color
end type

' ========================================================================================
' Describes the opacity and transformation of a brush.
' ========================================================================================
type D2D1_BRUSH_PROPERTIES
   AS FLOAT opacity
   AS D2D1_MATRIX_3X2_F transform
end type

' ========================================================================================
' Describes the extend modes and the interpolation mode of an ID2D1BitmapBrush.
' ========================================================================================
type D2D1_BITMAP_BRUSH_PROPERTIES
   AS D2D1_EXTEND_MODE extendModeX
   AS D2D1_EXTEND_MODE extendModeY
   AS D2D1_BITMAP_INTERPOLATION_MODE interpolationMode
end type

' ========================================================================================
' Contains the starting point and endpoint of the gradient axis for an ID2D1LinearGradientBrush.
' ========================================================================================
type D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
   AS D2D1_POINT_2F startPoint
   AS D2D1_POINT_2F endPoint
end type

' ========================================================================================
' Contains the gradient origin offset and the size and position of the gradient
' ellipse for an ID2D1RadialGradientBrush.
' ========================================================================================
type D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
   AS D2D1_POINT_2F center
   AS D2D1_POINT_2F gradientOriginOffset
   AS FLOAT radiusX
   AS FLOAT radiusY
end type

' ========================================================================================
' Differentiates which of the two possible arcs could match the given arc parameters.
' ========================================================================================
TYPE D2D1_ARC_SIZE AS LONG
enum
   D2D1_ARC_SIZE_SMALL = 0
   D2D1_ARC_SIZE_LARGE = 1
   D2D1_ARC_SIZE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Enum which describes the drawing of the ends of a line.
' ========================================================================================
TYPE D2D1_CAP_STYLE AS LONG
enum
   D2D1_CAP_STYLE_FLAT = 0
   D2D1_CAP_STYLE_SQUARE = 1
   D2D1_CAP_STYLE_ROUND = 2
   D2D1_CAP_STYLE_TRIANGLE = 3
   D2D1_CAP_STYLE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes the sequence of dashes and gaps in a stroke.
' ========================================================================================
TYPE D2D1_DASH_STYLE AS LONG
enum
   D2D1_DASH_STYLE_SOLID = 0
   D2D1_DASH_STYLE_DASH = 1
   D2D1_DASH_STYLE_DOT = 2
   D2D1_DASH_STYLE_DASH_DOT = 3
   D2D1_DASH_STYLE_DASH_DOT_DOT = 4
   D2D1_DASH_STYLE_CUSTOM = 5
   D2D1_DASH_STYLE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Enum which describes the drawing of the corners on the line.
' ========================================================================================
TYPE D2D1_LINE_JOIN AS LONG
enum
   D2D1_LINE_JOIN_MITER = 0
   D2D1_LINE_JOIN_BEVEL = 1
   D2D1_LINE_JOIN_ROUND = 2
   D2D1_LINE_JOIN_MITER_OR_BEVEL = 3
   D2D1_LINE_JOIN_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' This enumeration describes the type of combine operation to be performed.
' ========================================================================================
TYPE D2D1_COMBINE_MODE AS LONG
enum
   D2D1_COMBINE_MODE_UNION = 0
   D2D1_COMBINE_MODE_INTERSECT = 1
   D2D1_COMBINE_MODE_XOR = 2
   D2D1_COMBINE_MODE_EXCLUDE = 3
   D2D1_COMBINE_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes how one geometry object is spatially related to another geometry object.
' ========================================================================================
TYPE D2D1_GEOMETRY_RELATION AS LONG
enum
   D2D1_GEOMETRY_RELATION_UNKNOWN = 0
   D2D1_GEOMETRY_RELATION_DISJOINT = 1
   D2D1_GEOMETRY_RELATION_IS_CONTAINED = 2
   D2D1_GEOMETRY_RELATION_CONTAINS = 3
   D2D1_GEOMETRY_RELATION_OVERLAP = 4
   D2D1_GEOMETRY_RELATION_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Specifies how simple the output of a simplified geometry sink should be.
' ========================================================================================
TYPE D2D1_GEOMETRY_SIMPLIFICATION_OPTION AS LONG
enum
   D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES = 0
   D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES = 1
   D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Indicates whether the given figure is filled or hollow.
' ========================================================================================
TYPE D2D1_FIGURE_BEGIN AS LONG
enum
   D2D1_FIGURE_BEGIN_FILLED = 0
   D2D1_FIGURE_BEGIN_HOLLOW = 1
   D2D1_FIGURE_BEGIN_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Indicates whether the figure is open or closed on its end point.
' ========================================================================================
TYPE D2D1_FIGURE_END AS LONG
enum
   D2D1_FIGURE_END_OPEN = 0
   D2D1_FIGURE_END_CLOSED = 1
   D2D1_FIGURE_END_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes a cubic bezier in a path.
' ========================================================================================
type D2D1_BEZIER_SEGMENT
   AS D2D1_POINT_2F point1
   AS D2D1_POINT_2F point2
   AS D2D1_POINT_2F point3
end type

' ========================================================================================
' Describes a triangle.
' ========================================================================================
type D2D1_TRIANGLE
   AS D2D1_POINT_2F point1
   AS D2D1_POINT_2F point2
   AS D2D1_POINT_2F point3
end type

' ========================================================================================
' Indicates whether the given segment should be stroked, or, if the join between
' this segment and the previous one should be smooth.
' ========================================================================================
TYPE D2D1_PATH_SEGMENT AS LONG
enum
   D2D1_PATH_SEGMENT_NONE = &h00000000
   D2D1_PATH_SEGMENT_FORCE_UNSTROKED = &h00000001
   D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN = &h00000002
   D2D1_PATH_SEGMENT_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Defines the direction that an elliptical arc is drawn.
' ========================================================================================
TYPE D2D1_SWEEP_DIRECTION AS LONG
enum
   D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE = 0
   D2D1_SWEEP_DIRECTION_CLOCKWISE = 1
   D2D1_SWEEP_DIRECTION_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Specifies how the intersecting areas of geometries or figures are combined to
' form the area of the composite geometry.
' ========================================================================================
TYPE D2D1_FILL_MODE AS LONG
enum
   D2D1_FILL_MODE_ALTERNATE = 0
   D2D1_FILL_MODE_WINDING = 1
   D2D1_FILL_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes an arc that is defined as part of a path.
' ========================================================================================
type D2D1_ARC_SEGMENT
   AS D2D1_POINT_2F point
   AS D2D1_SIZE_F size
   AS FLOAT rotationAngle
   AS D2D1_SWEEP_DIRECTION sweepDirection
   AS D2D1_ARC_SIZE arcSize
end type

' ========================================================================================
' Contains the control point and end point for a quadratic Bezier segment.
' ========================================================================================
type D2D1_QUADRATIC_BEZIER_SEGMENT
   AS D2D1_POINT_2F point1
   AS D2D1_POINT_2F point2
end type

' ========================================================================================
' Contains the center point, x-radius, and y-radius of an ellipse.
' ========================================================================================
type D2D1_ELLIPSE
   AS D2D1_POINT_2F point
   AS FLOAT radiusX
   AS FLOAT radiusY
end type

' ========================================================================================
' Contains the dimensions and corner radii of a rounded rectangle.
' ========================================================================================
type D2D1_ROUNDED_RECT
   AS D2D1_RECT_F rect
   AS FLOAT radiusX
   AS FLOAT radiusY
end type

' ========================================================================================
' Properties, aside from the width, that allow geometric penning to be specified.
' ========================================================================================
type D2D1_STROKE_STYLE_PROPERTIES
   AS D2D1_CAP_STYLE startCap
   AS D2D1_CAP_STYLE endCap
   AS D2D1_CAP_STYLE dashCap
   AS D2D1_LINE_JOIN lineJoin
   AS FLOAT miterLimit
   AS D2D1_DASH_STYLE dashStyle
   AS FLOAT dashOffset
end type

' ========================================================================================
' Specified options that can be applied when a layer resource is applied to create a layer.
' ========================================================================================
TYPE D2D1_LAYER_OPTIONS AS LONG
enum
   D2D1_LAYER_OPTIONS_NONE = &h00000000
   D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE = &h00000001
   D2D1_LAYER_OPTIONS_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Contains the content bounds, mask information, opacity settings, and other options for a layer resource.
' ========================================================================================
type D2D1_LAYER_PARAMETERS
   AS D2D1_RECT_F contentBounds
   AS ID2D1Geometry PTR geometricMask
   AS D2D1_ANTIALIAS_MODE maskAntialiasMode
   AS D2D1_MATRIX_3X2_F maskTransform
   AS FLOAT opacity
   AS ID2D1Brush PTR opacityBrush
   AS D2D1_LAYER_OPTIONS layerOptions
end type

' ========================================================================================
' Describes whether a window is occluded.
' ========================================================================================
TYPE D2D1_WINDOW_STATE AS LONG
enum
   D2D1_WINDOW_STATE_NONE = &h0000000
   D2D1_WINDOW_STATE_OCCLUDED = &h0000001
   D2D1_WINDOW_STATE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes whether a render target uses hardware or software rendering, or if
' Direct2D should select the rendering mode.
' ========================================================================================
TYPE D2D1_RENDER_TARGET_TYPE AS LONG
enum
   D2D1_RENDER_TARGET_TYPE_DEFAULT = 0
   D2D1_RENDER_TARGET_TYPE_SOFTWARE = 1
   D2D1_RENDER_TARGET_TYPE_HARDWARE = 2
   D2D1_RENDER_TARGET_TYPE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes the minimum DirectX support required for hardware rendering by a render target.
' ========================================================================================
TYPE D2D1_FEATURE_LEVEL AS LONG
enum
   D2D1_FEATURE_LEVEL_DEFAULT = 0
   D2D1_FEATURE_LEVEL_9 = D3D_FEATURE_LEVEL_9_1
   D2D1_FEATURE_LEVEL_10 = D3D_FEATURE_LEVEL_10_0
   D2D1_FEATURE_LEVEL_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes how a render target is remoted and whether it should be
' GDI-compatible. This enumeration allows a bitwise combination of its member values.
' ========================================================================================
TYPE D2D1_RENDER_TARGET_USAGE AS LONG
enum
   D2D1_RENDER_TARGET_USAGE_NONE = &h00000000
   D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING = &h00000001
   D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE = &h00000002
   D2D1_RENDER_TARGET_USAGE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Describes how present should behave.
' ========================================================================================
TYPE D2D1_PRESENT_OPTIONS AS LONG
enum
   D2D1_PRESENT_OPTIONS_NONE = &h00000000
   D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS = &h00000001
   D2D1_PRESENT_OPTIONS_IMMEDIATELY = &h00000002
   D2D1_PRESENT_OPTIONS_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Contains rendering options (hardware or software), pixel format, DPI information,
' remoting options, and Direct3D support requirements for a render target.
' ========================================================================================
type D2D1_RENDER_TARGET_PROPERTIES
   AS D2D1_RENDER_TARGET_TYPE type
   AS D2D1_PIXEL_FORMAT pixelFormat
   AS FLOAT dpiX
   AS FLOAT dpiY
   AS D2D1_RENDER_TARGET_USAGE usage
   AS D2D1_FEATURE_LEVEL minLevel
end type

' ========================================================================================
' Contains the HWND, pixel size, and presentation options for an ID2D1HwndRenderTarget.
' ========================================================================================
type D2D1_HWND_RENDER_TARGET_PROPERTIES
   AS HWND hwnd
   AS D2D1_SIZE_U pixelSize
   AS D2D1_PRESENT_OPTIONS presentOptions
end type

' ========================================================================================
' Specifies additional features supportable by a compatible render target when it
' is created. This enumeration allows a bitwise combination of its member values.
' ========================================================================================
TYPE D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS AS LONG
enum
   D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE = &h00000000
   D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE = &h00000001
   D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Allows the drawing state to be atomically created. This also specifies the
' drawing state that is saved into an IDrawingStateBlock object.
' ========================================================================================
type D2D1_DRAWING_STATE_DESCRIPTION
   AS D2D1_ANTIALIAS_MODE antialiasMode
   AS D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
   AS D2D1_TAG tag1
   AS D2D1_TAG tag2
   AS D2D1_MATRIX_3X2_F transform
end type

' ========================================================================================
' Specifies how a device context is initialized for GDI rendering when it is
' retrieved from the render target.
' ========================================================================================
TYPE D2D1_DC_INITIALIZE_MODE AS LONG
enum
   D2D1_DC_INITIALIZE_MODE_COPY = 0
   D2D1_DC_INITIALIZE_MODE_CLEAR = 1
   D2D1_DC_INITIALIZE_MODE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Indicates the debug level to be output by the debug layer.
' ========================================================================================
TYPE D2D1_DEBUG_LEVEL AS LONG
enum
   D2D1_DEBUG_LEVEL_NONE = 0
   D2D1_DEBUG_LEVEL_ERROR = 1
   D2D1_DEBUG_LEVEL_WARNING = 2
   D2D1_DEBUG_LEVEL_INFORMATION = 3
   D2D1_DEBUG_LEVEL_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Specifies the threading model of the created factory and all of its derived resources.
' ========================================================================================
TYPE D2D1_FACTORY_TYPE AS LONG
enum
   D2D1_FACTORY_TYPE_SINGLE_THREADED = 0
   D2D1_FACTORY_TYPE_MULTI_THREADED = 1
   D2D1_FACTORY_TYPE_FORCE_DWORD = &hffffffff
end enum

' ========================================================================================
' Allows additional parameters for factory creation.
' ========================================================================================
type D2D1_FACTORY_OPTIONS
   AS D2D1_DEBUG_LEVEL debugLevel
end type


' ########################################################################################
' * Interface name: ID2D1Resource
' IID: {2CD90691-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents a Direct2D drawing resource.
' Inherited interface = IUnknown
' The root interface for all resources in D2D.
' ########################################################################################

#ifndef __ID2D1Resource_INTERFACE_DEFINED__
#define __ID2D1Resource_INTERFACE_DEFINED__

TYPE ID2D1Resource_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT SUB GetFactory (BYREF factory AS ID2D1Factory PTR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Image
' IID: {65019F75-8DA2-497C-B32C-DFA34E48EDE6}
' Inherited interface = ID2D1Resource
' Represents a producer of pixels that can fill an arbitrary 2D plane.
' It has no additional members that ID2D1Resource
' ########################################################################################

#ifndef __ID2D1Image_INTERFACE_DEFINED__
#define __ID2D1Image_INTERFACE_DEFINED__

TYPE ID2D1Image_ EXTENDS ID2D1Resource
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Bitmap
' IID: {A2296057-EA42-4099-983B-539FB6505426}
' Documentation string: Root bitmap resource, linearly scaled on a draw call.
' Inherited interface = ID2D1Image
' ########################################################################################

#ifndef __ID2D1Bitmap_INTERFACE_DEFINED__
#define __ID2D1Bitmap_INTERFACE_DEFINED__

TYPE ID2D1Bitmap_ EXTENDS ID2D1Image
'   DECLARE ABSTRACT FUNCTION GetSize () AS D2D1_SIZE_F
   DECLARE ABSTRACT SUB GetSize (BYREF size AS D2D1_SIZE_F)
'   DECLARE ABSTRACT FUNCTION GetPixelSize () AS D2D1_SIZE_U
   DECLARE ABSTRACT SUB GetPixelSize (BYREF pizelSize AS D2D1_SIZE_U)
'   DECLARE ABSTRACT FUNCTION GetPixelFormat () AS D2D1_PIXEL_FORMAT
   DECLARE ABSTRACT SUB GetPixelFormat (BYREF pixelFormat AS D2D1_PIXEL_FORMAT)
   DECLARE ABSTRACT SUB GetDpi (BYREF DpiX AS FLOAT, BYREF DpiY AS FLOAT)
   DECLARE ABSTRACT FUNCTION CopyFromBitmap (BYREF destPoint AS const D2D1_POINT_2U, BYVAL bitmap AS ID2D1Bitmap PTR, BYREF srcRect AS const D2D1_RECT_U) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyFromRenderTarget (BYREF destPoint AS const D2D1_POINT_2U, BYVAL renderTarget AS ID2D1RenderTarget PTR, BYREF srcRect AS const D2D1_RECT_U) AS HRESULT
   DECLARE ABSTRACT FUNCTION CopyFromMemory (BYREF dstRect AS const D2D1_RECT_U, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GradientStopCollection
' IID: {2CD906A7-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents an collection of gradient stops that can then be the
' source resource for either a linear or radial gradient brush.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1GradientStopCollection_INTERFACE_DEFINED__
#define __ID2D1GradientStopCollection_INTERFACE_DEFINED__

TYPE ID2D1GradientStopCollection_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION GetGradientStopCount () AS UINT32
   DECLARE ABSTRACT SUB GetGradientStops (BYREF gradientStops AS D2D1_GRADIENT_STOP, BYVAL gradientStopsCount AS UINT32)
   DECLARE ABSTRACT FUNCTION GetColorInterpolationGamma () AS D2D1_GAMMA
   DECLARE ABSTRACT FUNCTION GetExtendMode () AS D2D1_EXTEND_MODE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Brush
' IID: {2CD906A8-12E2-11DC-9FED-001143A055F9}
' Documentation string: The root brush interface. All brushes can be used to fill or pen a geometry.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1Brush_INTERFACE_DEFINED__
#define __ID2D1Brush_INTERFACE_DEFINED__

TYPE ID2D1Brush_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT SUB SetOpacity (BYVAL opacity AS FLOAT)
   DECLARE ABSTRACT SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE ABSTRACT FUNCTION GetOpacity () AS FLOAT
   DECLARE ABSTRACT SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1BitmapBrush
' IID: {2CD906AA-12E2-11DC-9FED-001143A055F9}
' Documentation string: A bitmap brush allows a bitmap to be used to fill a geometry.
' Inherited interface = ID2D1Brush
' ########################################################################################

#ifndef __ID2D1BitmapBrush_INTERFACE_DEFINED__
#define __ID2D1BitmapBrush_INTERFACE_DEFINED__

TYPE ID2D1BitmapBrush_ EXTENDS ID2D1Brush
   DECLARE ABSTRACT SUB SetExtendModeX (BYVAL extendModeX AS D2D1_EXTEND_MODE)
   DECLARE ABSTRACT SUB SetExtendModeY (BYVAL extendModeY AS D2D1_EXTEND_MODE)
   DECLARE ABSTRACT SUB SetInterpolationMode (BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE)
   DECLARE ABSTRACT SUB SetBitmap (BYVAL bitmap AS ID2D1Bitmap PTR)
   DECLARE ABSTRACT FUNCTION GetExtendModeX () AS D2D1_EXTEND_MODE
   DECLARE ABSTRACT FUNCTION GetExtendModeY () AS D2D1_EXTEND_MODE
   DECLARE ABSTRACT FUNCTION GetInterpolationMode () AS D2D1_BITMAP_INTERPOLATION_MODE
   DECLARE ABSTRACT SUB GetBitmap (BYREF bitmap AS ID2D1Bitmap PTR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1SolidColorBrush
' IID: {2CD906A9-12E2-11DC-9FED-001143A055F9}
' Documentation string: Paints an area with a solid color.
' Inherited interface = ID2D1Brush
' ########################################################################################

#ifndef __ID2D1SolidColorBrush_INTERFACE_DEFINED__
#define __ID2D1SolidColorBrush_INTERFACE_DEFINED__

TYPE ID2D1SolidColorBrush_ EXTENDS ID2D1Brush
   DECLARE ABSTRACT SUB SetColor (BYREF color AS D2D1_COLOR_F)
'   DECLARE ABSTRACT FUNCTION GetColor () AS D2D1_COLOR_F
   DECLARE ABSTRACT SUB GetColor (BYREF AS D2D1_COLOR_F)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1LinearGradientBrush
' IID: {2CD906AB-12E2-11DC-9FED-001143A055F9}
' Documentation string: Paints an area with a linear gradient.
' Inherited interface = ID2D1Brush
' ########################################################################################

#ifndef __ID2D1LinearGradientBrush_INTERFACE_DEFINED__
#define __ID2D1LinearGradientBrush_INTERFACE_DEFINED__

TYPE ID2D1LinearGradientBrush_ EXTENDS ID2D1Brush
   DECLARE ABSTRACT SUB SetStartPoint (BYVAL startPoint AS D2D1_POINT_2F)
   DECLARE ABSTRACT SUB SetEndPoint (BYVAL endPoint AS D2D1_POINT_2F)
'   DECLARE ABSTRACT FUNCTION GetStartPoint () AS D2D1_POINT_2F
   DECLARE ABSTRACT SUB GetStartPoint (BYREF startPoint AS D2D1_POINT_2F)
'   DECLARE ABSTRACT FUNCTION GetEndPoint () AS D2D1_POINT_2F
   DECLARE ABSTRACT SUB GetEndPoint (BYREF endPoint AS D2D1_POINT_2F)
   DECLARE ABSTRACT SUB GetGradientStopCollection (BYREF gradientStopCollection AS ID2D1GradientStopCollection PTR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1RadialGradientBrush
' IID: {2CD906AC-12E2-11DC-9FED-001143A055F9}
' Documentation string: Paints an area with a radial gradient.
' Inherited interface = ID2D1Brush
' ########################################################################################

#ifndef __ID2D1RadialGradientBrush_INTERFACE_DEFINED__
#define __ID2D1RadialGradientBrush_INTERFACE_DEFINED__

TYPE ID2D1RadialGradientBrush_ EXTENDS ID2D1Brush
   DECLARE ABSTRACT SUB SetCenter (BYVAL center AS D2D1_POINT_2F)
   DECLARE ABSTRACT SUB SetGradientOriginOffset (BYVAL gradientOriginOffset AS D2D1_POINT_2F)
   DECLARE ABSTRACT SUB SetRadiusX (BYVAL radiusX AS FLOAT)
   DECLARE ABSTRACT SUB SetRadiusY (BYVAL radiusY AS FLOAT)
'   DECLARE ABSTRACT FUNCTION GetCenter () AS D2D1_POINT_2F
   DECLARE ABSTRACT SUB GetCenter (BYREF center AS D2D1_POINT_2F)
'   DECLARE ABSTRACT FUNCTION GetGradientOriginOffset () AS D2D1_POINT_2F
   DECLARE ABSTRACT SUB GetGradientOriginOffset (BYREF offset AS D2D1_POINT_2F)
   DECLARE ABSTRACT FUNCTION GetRadiusX () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetRadiusY () AS FLOAT
   DECLARE ABSTRACT SUB GetGradientStopCollection (BYREF gradientStopCollection AS ID2D1GradientStopCollection PTR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1StrokeStyle
' IID: {2CD9069D-12E2-11DC-9FED-001143A055F9}
' Documentation string: Describes the caps, miter limit, line join, and dash information for a stroke.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1StrokeStyle_INTERFACE_DEFINED__
#define __ID2D1StrokeStyle_INTERFACE_DEFINED__

TYPE ID2D1StrokeStyle_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION GetStartCap () AS D2D1_CAP_STYLE
   DECLARE ABSTRACT FUNCTION GetEndCap () AS D2D1_CAP_STYLE
   DECLARE ABSTRACT FUNCTION GetDashCap () AS D2D1_CAP_STYLE
   DECLARE ABSTRACT FUNCTION GetMiterLimit () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetLineJoin () AS D2D1_LINE_JOIN
   DECLARE ABSTRACT FUNCTION GetDashOffset () AS FLOAT
   DECLARE ABSTRACT FUNCTION GetDashStyle () AS D2D1_DASH_STYLE
   DECLARE ABSTRACT FUNCTION GetDashesCount () AS UINT32
   DECLARE ABSTRACT SUB GetDashes (BYREF dashes AS FLOAT, BYVAL dashesCount AS UINT32)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Geometry
' IID: {2CD906A1-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents a geometry resource and defines a set of helper methods
' for manipulating and measuring geometric shapes. Interfaces that inherit from ID2D1Geometry
' define specific shapes.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1Geometry_INTERFACE_DEFINED__
#define __ID2D1Geometry_INTERFACE_DEFINED__

TYPE ID2D1Geometry_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION GetBounds (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION StrokeContainsPoint (BYVAL point AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
      BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYREF contains AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION FillContainsPoint (BYVAL point AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYREF contains AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
      BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
      BYREF relation AS D2D1_GEOMETRY_RELATION) AS HRESULT
   DECLARE ABSTRACT FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
      BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
      BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
      BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYREF area AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYREF Length AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
      BYVAL flatteningTolerance AS FLOAT, BYREF pt AS D2D1_POINT_2F, BYREF unitTangentVector AS D2D1_POINT_2F) AS HRESULT
   DECLARE ABSTRACT FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
      BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################
 
 ' ########################################################################################
' Interface name: ID2D1RectangleGeometry
' IID: {2CD906A2-12E2-11DC-9FED-001143A055F9}
' Documentation string: Describes a two-dimensional rectangle.
' Inherited interface = ID2D1Geometry
' Number of methods = 1
' ########################################################################################

#ifndef __ID2D1RectangleGeometry_INTERFACE_DEFINED__
#define __ID2D1RectangleGeometry_INTERFACE_DEFINED__

TYPE ID2D1RectangleGeometry_ EXTENDS ID2D1Geometry
   DECLARE ABSTRACT SUB GetRect (BYREF rect AS D2D1_RECT_F)
END TYPE

#endif

' ########################################################################################
 
 ' ########################################################################################
' Interface name: ID2D1RoundedRectangleGeometry
' IID: {2CD906A3-12E2-11DC-9FED-001143A055F9}
' Documentation string: Describes a rounded rectangle.
' Inherited interface = ID2D1Geometry
' ########################################################################################

#ifndef __ID2D1RoundedRectangleGeometry_INTERFACE_DEFINED__
#define __ID2D1RoundedRectangleGeometry_INTERFACE_DEFINED__

TYPE ID2D1RoundedRectangleGeometry_ EXTENDS ID2D1Geometry
   DECLARE ABSTRACT SUB GetRoundedRect (BYREF roundedRect AS D2D1_ROUNDED_RECT)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1EllipseGeometry
' IID: {2CD906A4-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents an ellipse.
' Inherited interface = ID2D1Geometry
' ########################################################################################

#ifndef __ID2D1EllipseGeometry_INTERFACE_DEFINED__
#define __ID2D1EllipseGeometry_INTERFACE_DEFINED__

TYPE ID2D1EllipseGeometry_ EXTENDS ID2D1Geometry
   DECLARE ABSTRACT SUB GetEllipse (BYREF ellipse AS D2D1_ELLIPSE)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GeometryGroup
' IID: {2CD906A6-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents a composite geometry, composed of other ID2D1Geometry objects.
' Inherited interface = ID2D1Geometry
' ########################################################################################

#ifndef __ID2D1GeometryGroup_INTERFACE_DEFINED__
#define __ID2D1GeometryGroup_INTERFACE_DEFINED__

TYPE ID2D1GeometryGroup_ EXTENDS ID2D1Geometry
   DECLARE ABSTRACT FUNCTION GetFillMode () AS D2D1_FILL_MODE
   DECLARE ABSTRACT FUNCTION GetSourceGeometryCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetSourceGeometries (BYREF geometries AS ID2D1Geometry PTR, BYVAL geometriesCount AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1TransformedGeometry
' IID: {2CD906BB-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents a geometry that has been transformed.
' Inherited interface = ID2D1Geometry
' ########################################################################################

#ifndef __ID2D1TransformedGeometry_INTERFACE_DEFINED__
#define __ID2D1TransformedGeometry_INTERFACE_DEFINED__

TYPE ID2D1TransformedGeometry_ EXTENDS ID2D1Geometry
   DECLARE ABSTRACT SUB GetSourceGeometry (BYREF sourceGeometry AS ID2D1Geometry PTR)
   DECLARE ABSTRACT SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1SimplifiedGeometrySink
' IID: {2CD9069E-12E2-11DC-9FED-001143A055F9}
' Documentation string: Describes a geometric path that does not contain quadratic bezier curves or arcs.
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __ID2D1SimplifiedGeometrySink_INTERFACE_DEFINED__
#define __ID2D1SimplifiedGeometrySink_INTERFACE_DEFINED__

TYPE ID2D1SimplifiedGeometrySink_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT SUB SetFillMode (BYVAL fillMode AS D2D1_FILL_MODE)
   DECLARE ABSTRACT SUB SetSegmentFlags (BYVAL vertexFlags AS D2D1_PATH_SEGMENT)
   DECLARE ABSTRACT SUB BeginFigure (BYVAL startPoint AS D2D1_POINT_2F, BYVAL figureBegin AS D2D1_FIGURE_BEGIN)
   DECLARE ABSTRACT SUB AddLines (BYREF points AS D2D1_POINT_2F, BYVAL pointsCount AS UINT32)
   DECLARE ABSTRACT SUB AddBeziers (BYREF beziers AS const D2D1_BEZIER_SEGMENT, BYVAL beziersCount AS UINT32)
   DECLARE ABSTRACT SUB EndFigure (BYVAL figureEnd AS D2D1_FIGURE_END)
   DECLARE ABSTRACT FUNCTION Close () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GeometrySink
' IID: {2CD9069F-12E2-11DC-9FED-001143A055F9}
' Documentation string: Describes a geometric path that can contain lines, arcs, cubic Bezier curves, and quadratic Bezier curves.
' Inherited interface = ID2D1SimplifiedGeometrySink
' ########################################################################################

#ifndef __ID2D1GeometrySink_INTERFACE_DEFINED__
#define __ID2D1GeometrySink_INTERFACE_DEFINED__

TYPE ID2D1GeometrySink_ EXTENDS ID2D1SimplifiedGeometrySink
   DECLARE ABSTRACT SUB AddLine (BYVAL point AS D2D1_POINT_2F)
   DECLARE ABSTRACT SUB AddBezier (BYREF bezier AS D2D1_BEZIER_SEGMENT)
   DECLARE ABSTRACT SUB AddQuadraticBezier (BYREF bezier AS D2D1_QUADRATIC_BEZIER_SEGMENT)
   DECLARE ABSTRACT SUB AddQuadraticBeziers (BYREF beziers AS D2D1_QUADRATIC_BEZIER_SEGMENT, BYVAL beziersCount AS UINT32)
   DECLARE ABSTRACT SUB AddArc (BYREF arc AS D2D1_ARC_SEGMENT)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1TessellationSink
' IID: {2CD906C1-12E2-11DC-9FED-001143A055F9}
' Documentation string: Populates an ID2D1Mesh object with triangles.
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __ID2D1TessellationSink_INTERFACE_DEFINED__
#define __ID2D1TessellationSink_INTERFACE_DEFINED__

TYPE ID2D1TessellationSink_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT SUB AddTriangles (BYREF triangles AS D2D1_TRIANGLE, BYVAL trianglesCount AS UINT32)
   DECLARE ABSTRACT FUNCTION Close () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1PathGeometry
' IID: {2CD906A5-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents a complex shape that may be composed of arcs, curves, and lines.
' Inherited interface = ID2D1Geometry
' ########################################################################################

#ifndef __ID2D1PathGeometry_INTERFACE_DEFINED__
#define __ID2D1PathGeometry_INTERFACE_DEFINED__

TYPE ID2D1PathGeometry_ EXTENDS ID2D1Geometry
   DECLARE ABSTRACT FUNCTION Open (BYREF geometrySink AS ID2D1GeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Stream (BYREF geometrySink AS ID2D1GeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSegmentCount (BYREF count AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFigureCount (BYREF count AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Mesh
' IID: {2CD906C2-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents a set of vertices that form a list of triangles.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1Mesh_INTERFACE_DEFINED__
#define __ID2D1Mesh_INTERFACE_DEFINED__

TYPE ID2D1Mesh_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION Open (BYREF tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Layer
' IID: {2CD9069B-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents the backing store required to render a layer.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1Layer_INTERFACE_DEFINED__
#define __ID2D1Layer_INTERFACE_DEFINED__

TYPE ID2D1Layer_ EXTENDS ID2D1Resource
'   DECLARE ABSTRACT FUNCTION GetSize () AS D2D1_SIZE_F
   DECLARE ABSTRACT SUB GetSize (BYREF size AS D2D1_SIZE_F)
END TYPE

#endif

' ########################################################################################
' Interface name: ID2D1DrawingStateBlock
' IID: {28506E39-EBF6-46A1-BB47-FD85565AB957}
' Documentation string: Represents the drawing state of a render target: the antialiasing
' mode, transform, tags, and text-rendering options.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1DrawingStateBlock_INTERFACE_DEFINED__
#define __ID2D1DrawingStateBlock_INTERFACE_DEFINED__

TYPE ID2D1DrawingStateBlock_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT SUB GetDescription (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION)
   DECLARE ABSTRACT SUB SetDescription (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION)
   DECLARE ABSTRACT SUB SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE ABSTRACT SUB GetTextRenderingParams (BYREF textRenderingParams AS IDWriteRenderingParams PTR)
END TYPE

#endif

' ########################################################################################
' * Interface name: ID2D1RenderTarget
' IID: {2CD90694-12E2-11DC-9FED-001143A055F9}
' Documentation string: Represents an object that can receive drawing commands. Interfaces
' that inherit from ID2D1RenderTarget render the drawing commands they receive in different ways.
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1RenderTarget_INTERFACE_DEFINED__
#define __ID2D1RenderTarget_INTERFACE_DEFINED__

TYPE ID2D1RenderTarget_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION CreateBitmap (BYVAL size AS D2D1_SIZE_U, BYVAL srcData AS const ANY PTR, _
      BYVAL pitch AS UINT32, BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES, BYREF bitmap AS ID2D1Bitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR, _
      BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES, BYREF bitmap AS ID2D1Bitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSharedBitmap (BYREF iid AS IID, BYVAL data AS ANY PTR, _
      BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES, BYREF bitmap AS ID2D1Bitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES, _
      BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, BYREF bitmapBrush AS ID2D1BitmapBrush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSolidColorBrush (BYREF color AS D2D1_COLOR_F, BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
      BYREF solidColorBrush AS ID2D1SolidColorBrush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGradientStopCollection (BYREF gradientStops AS D2D1_GRADIENT_STOP, _
      BYVAL gradientStopsCount AS UINT32, BYVAL colorInterpolationGamma AS D2D1_GAMMA, BYVAL extendMode AS D2D1_EXTEND_MODE, _
      BYREF gradientStopCollection AS ID2D1GradientStopCollection PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateLinearGradientBrush (BYREF linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES, _
      BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR, _
      BYREF linearGradientBrush AS ID2D1LinearGradientBrush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateRadialGradientBrush (BYREF radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES, _
      BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR, _
      BYREF radialGradientBrush AS ID2D1RadialGradientBrush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F, _
      BYREF desiredPixelSize AS const D2D1_SIZE_U, BYREF desiredFormat AS const D2D1_PIXEL_FORMAT, _
      BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS, BYREF bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateLayer (BYREF size AS const D2D1_SIZE_F, BYREF layer AS ID2D1Layer PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateMesh (BYREF mesh AS ID2D1Mesh PTR) AS HRESULT
   DECLARE ABSTRACT SUB DrawLine (BYVAL point0 AS D2D1_POINT_2F, BYVAL point1 AS D2D1_POINT_2F, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE ABSTRACT SUB DrawRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE ABSTRACT SUB FillRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR)
   DECLARE ABSTRACT SUB DrawRoundedRectangle (BYREF roundedRect AS const D2D1_ROUNDED_RECT, _
      BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE ABSTRACT SUB FillRoundedRectangle (BYREF roundedRect AS const D2D1_ROUNDED_RECT, BYVAL brush AS ID2D1Brush PTR)
   DECLARE ABSTRACT SUB DrawEllipse (BYREF ellipse AS const D2D1_ELLIPSE, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE ABSTRACT SUB FillEllipse (BYREF ellipse AS const D2D1_ELLIPSE, BYVAL brush AS ID2D1Brush PTR)
   DECLARE ABSTRACT SUB DrawGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE ABSTRACT SUB FillGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR, BYVAL opacityBrush AS ID2D1Brush PTR = NULL)
   DECLARE ABSTRACT SUB FillMesh (BYVAL mesh AS ID2D1Mesh PTR, BYVAL brush AS ID2D1Brush PTR)
   DECLARE ABSTRACT SUB FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL content AS D2D1_OPACITY_MASK_CONTENT, BYREF destinationRectangle AS const D2D1_RECT_F, _
      BYREF sourceRectangle AS const D2D1_RECT_F)
   DECLARE ABSTRACT SUB DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF destinationRectangle AS const D2D1_RECT_F, _
      BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
      BYREF sourceRectangle AS const D2D1_RECT_F)
   DECLARE ABSTRACT SUB DrawText (BYREF wzSstr AS WSTRING, BYVAL stringLength AS UINT32, BYVAL textFormat AS IDWriteTextFormat PTR, _
      BYREF layoutRect AS D2D1_RECT_F, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
      BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE ABSTRACT SUB DrawTextLayout (BYVAL origin AS D2D1_POINT_2F, BYVAL textLayout AS IDWriteTextLayout PTR, _
      BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE)
   DECLARE ABSTRACT SUB DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
      BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE ABSTRACT SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE ABSTRACT SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE ABSTRACT SUB SetAntialiasMode (BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   DECLARE ABSTRACT FUNCTION GetAntialiasMode () AS D2D1_ANTIALIAS_MODE
   DECLARE ABSTRACT SUB SetTextAntialiasMode (BYVAL textAntialiasMode AS D2D1_TEXT_ANTIALIAS_MODE)
   DECLARE ABSTRACT FUNCTION GetTextAntialiasMode () AS D2D1_TEXT_ANTIALIAS_MODE
   DECLARE ABSTRACT SUB SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE ABSTRACT SUB GetTextRenderingParams (BYREF textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE ABSTRACT SUB SetTags (BYVAL tag1 AS D2D1_TAG, BYVAL tag2 AS D2D1_TAG)
   DECLARE ABSTRACT SUB GetTags (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL)
   DECLARE ABSTRACT SUB PushLayer (BYREF layerParameters AS D2D1_LAYER_PARAMETERS, BYVAL layer AS ID2D1Layer PTR)
   DECLARE ABSTRACT SUB PopLayer ()
   DECLARE ABSTRACT FUNCTION Flush (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL) AS HRESULT
   DECLARE ABSTRACT SUB SaveDrawingState (BYVAL drawingStateBlock AS ID2D1DrawingStateBlock PTR)
   DECLARE ABSTRACT SUB RestoreDrawingState (BYVAL drawingStateBlock AS ID2D1DrawingStateBlock PTR)
   DECLARE ABSTRACT SUB PushAxisAlignedClip (BYREF clipRect AS D2D1_RECT_F, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   DECLARE ABSTRACT SUB PopAxisAlignedClip ()
   DECLARE ABSTRACT SUB Clear (BYREF clearColor AS const D2D1_COLOR_F)
   DECLARE ABSTRACT SUB BeginDraw ()
   DECLARE ABSTRACT FUNCTION EndDraw (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL) AS HRESULT
'   DECLARE ABSTRACT FUNCTION GetPixelFormat () AS D2D1_PIXEL_FORMAT
   DECLARE ABSTRACT SUB GetPixelFormat (BYREF pixelFormat AS D2D1_PIXEL_FORMAT)
   DECLARE ABSTRACT SUB SetDpi (BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT)
   DECLARE ABSTRACT SUB GetDpi (BYREF dpiX AS FLOAT, BYREF dpiY AS FLOAT)
'   DECLARE ABSTRACT FUNCTION GetSize () AS D2D1_SIZE_F
   DECLARE ABSTRACT SUB GetSize (BYREF size AS D2D1_SIZE_F)
'   DECLARE ABSTRACT FUNCTION GetPixelSize () AS D2D1_SIZE_U
   DECLARE ABSTRACT SUB GetPixelSize (BYREF pixelSize AS D2D1_SIZE_U)
   DECLARE ABSTRACT FUNCTION GetMaximumBitmapSize () AS UINT32
   DECLARE ABSTRACT FUNCTION IsSupported (BYREF renderTargetProperties AS const D2D1_RENDER_TARGET_PROPERTIES) AS BOOLEAN
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1BitmapRenderTarget
' IID: {2CD90695-12E2-11DC-9FED-001143A055F9}
' Documentation string: Renders to an intermediate texture created by the CreateCompatibleRenderTarget method.
' Inherited interface = ID2D1RenderTarget
' ########################################################################################

#ifndef __ID2D1BitmapRenderTarget_INTERFACE_DEFINED__
#define __ID2D1BitmapRenderTarget_INTERFACE_DEFINED__

TYPE ID2D1BitmapRenderTarget_ EXTENDS ID2D1RenderTarget
   DECLARE ABSTRACT FUNCTION GetBitmap (BYREF bitmap AS ID2D1Bitmap PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1HwndRenderTarget
' IID: {2CD90698-12E2-11DC-9FED-001143A055F9}
' Documentation string: Renders drawing instructions to a window.
' Inherited interface = ID2D1RenderTarget
' ########################################################################################

#ifndef __ID2D1HwndRenderTarget_INTERFACE_DEFINED__
#define __ID2D1HwndRenderTarget_INTERFACE_DEFINED__

TYPE ID2D1HwndRenderTarget_ EXTENDS ID2D1RenderTarget
   DECLARE ABSTRACT FUNCTION CheckWindowState () AS D2D1_WINDOW_STATE
   DECLARE ABSTRACT FUNCTION Resize (BYREF pixelSize AS D2D1_SIZE_U) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetHwnd () AS HWND
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GdiInteropRenderTarget
' IID: {E0DB51C3-6F77-4BAE-B3D5-E47509B35838}
' Documentation string: Provides access to an device context that can accept GDI drawing commands.
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __ID2D1GdiInteropRenderTarget_INTERFACE_DEFINED__
#define __ID2D1GdiInteropRenderTarget_INTERFACE_DEFINED__

TYPE ID2D1GdiInteropRenderTarget_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE, BYREF hDC AS ..HDC) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseDC (BYREF rcUpdate AS const RECT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DCRenderTarget
' IID: {1C51BC64-DE61-46FD-9899-63A5D8F03950}
' Documentation string: Issues drawing commands to a GDI device context.
' Inherited interface = ID2D1RenderTarget
' ########################################################################################

#ifndef __ID2D1DCRenderTarget_INTERFACE_DEFINED__
#define __ID2D1DCRenderTarget_INTERFACE_DEFINED__

TYPE ID2D1DCRenderTarget_ EXTENDS ID2D1RenderTarget
   DECLARE ABSTRACT FUNCTION BindDC (BYVAL hDC AS ..HDC, BYREF subRect AS const RECT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory
' IID: {06152247-6F50-465A-9245-118BFD3B6007}
' Documentation string: Creates Direct2D resources.
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __ID2D1Factory_INTERFACE_DEFINED__
#define __ID2D1Factory_INTERFACE_DEFINED__

TYPE ID2D1Factory_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION ReloadSystemMetrics () AS HRESULT
   DECLARE ABSTRACT SUB GetDesktopDpi (BYREF dpiX AS FLOAT, BYREF dpiY AS FLOAT)
   DECLARE ABSTRACT FUNCTION CreateRectangleGeometry (BYREF rectangle AS D2D1_RECT_F, BYREF rectangleGeometry AS ID2D1RectangleGeometry PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateRoundedRectangleGeometry (BYREF roundedRectangle AS D2D1_ROUNDED_RECT, BYREF roundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateEllipseGeometry (BYREF ellipse AS const D2D1_ELLIPSE, BYREF ellipseGeometry AS ID2D1EllipseGeometry PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGeometryGroup (BYVAL fillMode AS D2D1_FILL_MODE, BYVAL geometries AS ID2D1Geometry PTR, _
      BYVAL geometriesCount AS UINT32, BYREF geometryGroup AS ID2D1GeometryGroup PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTransformedGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR, BYREF transform AS D2D1_MATRIX_3X2_F, _
      BYREF transformedGeometry AS ID2D1TransformedGeometry PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreatePathGeometry (BYREF pathGeometry AS ID2D1PathGeometry PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateStrokeStyle (BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES, _
      BYREF dashes AS const FLOAT, BYVAL dashesCount AS UINT32, BYREF strokeStyle AS ID2D1StrokeStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDrawingStateBlock (BYREF drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION, _
      BYVAL textRenderingParams AS IDWriteRenderingParams PTR, BYREF drawingStateBlock AS ID2D1DrawingStateBlock PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateWicBitmapRenderTarget (BYVAL target AS IWICBitmap PTR, BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES, _
      BYREF renderTarget AS ID2D1RenderTarget PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateHwndRenderTarget (BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES, _
      BYREF hwndRenderTargetProperties AS D2D1_HWND_RENDER_TARGET_PROPERTIES, BYREF hwndRenderTarget AS ID2D1HwndRenderTarget PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDxgiSurfaceRenderTarget (BYVAL dxgiSurface AS IDXGISurface PTR, _
      BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES, BYREF renderTarget AS ID2D1RenderTarget PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDCRenderTarget (BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES, _
      BYREF dcRenderTarget AS ID2D1DCRenderTarget PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ========================================================================================
' Creates a factory object that can be used to create Direct2D resources.
' ========================================================================================
DECLARE FUNCTION D2D1CreateFactory LIB "d2d1" ALIAS "D2D1CreateFactory" (BYVAL factoryType AS D2D1_FACTORY_TYPE, _
   BYREF riid AS IID, BYREF factoryOptions AS const D2D1_FACTORY_OPTIONS, BYREF pIFactory AS ANY PTR) AS HRESULT
' ========================================================================================

' ========================================================================================
' Creates a rotation transformation that rotates by the specified angle about the specified point.
' ========================================================================================
DECLARE SUB D2D1MakeRotateMatrix LIB "d2d1" ALIAS "D2D1MakeRotateMatrix" (BYVAL angle AS FLOAT, _
   BYVAL center AS D2D1_POINT_2F, BYREF matrix AS D2D1_MATRIX_3X2_F)
' ========================================================================================

' ========================================================================================
' Creates a skew transformation that has the specified x-axis angle, y-axis angle, and center point.
' ========================================================================================
DECLARE SUB D2D1MakeSkewMatrix LIB "d2d1" ALIAS "D2D1MakeSkewMatrix" (BYVAL angleX AS FLOAT, BYVAL angleY AS FLOAT, _
   BYVAL center AS D2D1_POINT_2F, BYREF matrix AS D2D1_MATRIX_3X2_F)
' ========================================================================================

' ========================================================================================
' Creates a skew transformation that has the specified x-axis angle, y-axis angle, and center point.
' ========================================================================================
DECLARE FUNCTION D2D1IsMatrixInvertible LIB "d2d1" ALIAS "D2D1IsMatrixInvertible" (BYREF matrix AS D2D1_MATRIX_3X2_F) AS BOOLEAN
' ========================================================================================

' ========================================================================================
' Creates a skew transformation that has the specified x-axis angle, y-axis angle, and center point.
' ========================================================================================
DECLARE FUNCTION D2D1InvertMatrix LIB "d2d1" ALIAS "D2D1InvertMatrix" (BYREF matrix AS D2D1_MATRIX_3X2_F) AS BOOLEAN
' ========================================================================================

TYPE DWRITE_FACTORY_TYPE AS LONG
enum
   DWRITE_FACTORY_TYPE_SHARED
   DWRITE_FACTORY_TYPE_ISOLATED
end enum

' ========================================================================================
' Creates a DirectWrite factory object that is used for subsequent creation of individual DirectWrite objects.
' ========================================================================================
DECLARE FUNCTION DWriteCreateFactory LIB "dwrite" Alias "DWriteCreateFactory" (BYVAL factoryType AS DWRITE_FACTORY_TYPE, _
   BYREF riid AS IID, BYREF factory AS ANY PTR) AS HRESULT
' ========================================================================================

' ########################################################################################
'                                    *** d2d1_1.h ***
' ########################################################################################

#ifndef IID_ID2D1ColorContext
DIM SHARED IID_ID2D1ColorContext AS GUID = TYPE<GUID>(&h1C4820BB, &h5771, &h4518, {&hA5, &h81, &h2F, &hE4, &hDD, &h0E, &hC6, &h57})
#endif
#ifndef IID_IWICColorContext
DIM SHARED IID_IWICColorContext AS GUID = TYPE<GUID>(&h3c613a02, &h34b2, &h44ea, {&h9a, &h7c, &h45, &hae, &ha9, &hc6, &hfd, &h6d})
#endif
#ifndef IID_IWICImagingFactory
DIM SHARED IID_IWICImagingFactory AS GUID = TYPE<GUID>(&hec5ec8a9, &hc395, &h4314, {&h9c, &h77, &h54, &hd7, &ha9, &h35, &hff, &h70})
#endif
#ifndef IID_IPrintDocumentPackageTarget
DIM SHARED IID_IPrintDocumentPackageTarget AS GUID = TYPE<GUID>(&h1b8efec4, &h3019, &h4c27, {&h96, &h4e, &h36, &h72, &h02, &h15, &h69, &h06})
#endif

type ID2D1ColorContext AS ID2D1ColorContext_
type IWICColorContext AS IWICColorContext_
type IWICImagingFactory AS IWICImagingFactory_
type IPrintDocumentPackageTarget AS IPrintDocumentPackageTarget_
type IDWriteFactory AS IDWriteFactory_

type DWRITE_GLYPH_RUN_DESCRIPTION AS DWRITE_GLYPH_RUN_DESCRIPTION_
type D2D1_PROPERTY_BINDING AS D2D1_PROPERTY_BINDING_

'/// Function pointer to construct a new effect once registered.
'typedef HRESULT (CALLBACK *PD2D1_EFFECT_FACTORY)(
'    _Outptr_ IUnknown **effectImpl
'    );
type PD2D1_EFFECT_FACTORY AS FUNCTION (BYREF effectImpl AS IUnknown PTR) AS HRESULT

DIM SHARED IID_ID2D1GdiMetafileSink AS GUID = TYPE<GUID>(&h82237326, &h8111, &h4F7C, {&hBC, &hF4, &hB5, &hC1, &h17, &h55, &h64, &hFE})
DIM SHARED IID_ID2D1GdiMetafile AS GUID = TYPE<GUID>(&h2F543DC3, &hCFC1, &h4211, {&h86, &h4F, &hCF, &hD9, &h1C, &h6F, &h33, &h95})
DIM SHARED IID_ID2D1CommandSink AS GUID = TYPE<GUID>(&h54D7898A, &hA061, &h40A7, {&hBE, &hC7, &hE4, &h65, &hBC, &hBA, &h2C, &h4F})
DIM SHARED IID_ID2D1CommandList AS GUID = TYPE<GUID>(&hB4F34A19, &h2383, &h4D76, {&h94, &hF6, &hEC, &h34, &h36, &h57, &hC3, &hDC})
DIM SHARED IID_ID2D1PrintControl AS GUID = TYPE<GUID>(&h2C1D867D, &hC290, &h41C8, {&hAE, &h7E, &h34, &hA9, &h87, &h02, &hE9, &hA5})
DIM SHARED IID_ID2D1ImageBrush AS GUID = TYPE<GUID>(&hFE9E984D, &h3F95, &h407C, {&hB5, &hDB, &hCB, &h94, &hD4, &hE8, &hF8, &h7C})
DIM SHARED IID_ID2D1BitmapBrush1 AS GUID = TYPE<GUID>(&h41343A53, &hE41A, &h49A2, {&h91, &hCD, &h21, &h79, &h3B, &hBB, &h62, &hE5})
DIM SHARED IID_ID2D1StrokeStyle1 AS GUID = TYPE<GUID>(&h10A72A66, &hE91C, &h43F4, {&h99, &h3F, &hDD, &hF4, &hB8, &h2B, &h0B, &h4A})
DIM SHARED IID_ID2D1PathGeometry1 AS GUID = TYPE<GUID>(&h62BAA2D2, &hAB54, &h41B7, {&hB8, &h72, &h78, &h7E, &h01, &h06, &hA4, &h21})
DIM SHARED IID_ID2D1Properties AS GUID = TYPE<GUID>(&h483473D7, &hCD46, &h4F9D, {&h9D, &h3A, &h31, &h12, &hAA, &h80, &h15, &h9D})
DIM SHARED IID_ID2D1Bitmap1 AS GUID = TYPE<GUID>(&hA898A84C, &h3873, &h4588, {&hB0, &h8B, &hEB, &hBF, &h97, &h8D, &hF0, &h41})
DIM SHARED IID_ID2D1GradientStopCollection1 AS GUID = (&hAE1572F4, &h5DD0, &h4777, {&h99, &h8B, &h92, &h79, &h47, &h2A, &hE6, &h3B})
DIM SHARED IID_ID2D1DrawingStateBlock1 AS GUID = TYPE<GUID>(&h689F1F85, &hC72E, &h4E33, {&h8F, &h19, &h85, &h75, &h4E, &hFD, &h5A, &hCE})
DIM SHARED IID_ID2D1Device AS GUID = TYPE<GUID>(&h47DD575D, &hAC05, &h4CDD, {&h80, &h49, &h9B, &h02, &hCD, &h16, &hF4, &h4C})
DIM SHARED IID_ID2D1DeviceContext AS GUID = TYPE<GUID>(&hE8F7FE7A, &h191C, &h466D, {&hAD, &h95, &h97, &h56, &h78, &hBD, &hA9, &h98})
DIM SHARED IID_ID2D1Effect AS GUID = TYPE<GUID>(&h28211A43, &h7D89, &h476F, {&h81, &h81, &h2D, &h61, &h59, &hB2, &h20, &hAD})
DIM SHARED IID_ID2D1Factory1 AS GUID = TYPE<GUID>(&hBB12D362, &hDAEE, &h4B9A, {&hAA, &h1D, &h14, &hBA, &h40, &h1C, &hFA, &h1F})
DIM SHARED IID_ID2D1Multithread AS GUID = TYPE<GUID>(&h31E6E7BC, &hE0FF, &h4D46, {&h8C, &h64, &hA0, &hA8, &hC4, &h1C, &h15, &hD3})

type ID2D1GdiMetafileSink AS ID2D1GdiMetafileSink_
type ID2D1GdiMetafile AS ID2D1GdiMetafile_
type ID2D1CommandSink AS ID2D1CommandSink_
type ID2D1CommandList AS ID2D1CommandList_
type ID2D1PrintControl AS ID2D1PrintControl_
type ID2D1ImageBrush AS ID2D1ImageBrush_
type ID2D1BitmapBrush1 AS ID2D1BitmapBrush1_
type ID2D1StrokeStyle1 AS ID2D1StrokeStyle1_
type ID2D1PathGeometry1 AS ID2D1PathGeometry1_
type ID2D1Properties AS ID2D1Properties_
type ID2D1Bitmap1 AS ID2D1Bitmap1_
type ID2D1GradientStopCollection1 AS ID2D1GradientStopCollection1_
type ID2D1DrawingStateBlock1 AS ID2D1DrawingStateBlock1_
type ID2D1Device AS ID2D1Device_
type ID2D1DeviceContext AS ID2D1DeviceContext_
type ID2D1Effect AS ID2D1Effect_
type ID2D1Factory1 AS ID2D1Factory1_
type ID2D1Multithread AS ID2D1Multithread_

'#define D2D1_INVALID_PROPERTY_INDEX UINT_MAX
CONST D2D1_INVALID_PROPERTY_INDEX = &hFFFFFFFF
'typedef D2D_RECT_L D2D1_RECT_L;
'typedef D2D_POINT_2L D2D1_POINT_2L;

#define D2D1_RECT_L D2D_RECT_L
'#define D2D1_POINT_2L D2D_POINT_2L

'/// This defines the valid property types that can be used in an effect property interface.
TYPE D2D1_PROPERTY_TYPE AS LONG
enum
   D2D1_PROPERTY_TYPE_UNKNOWN = 0
   D2D1_PROPERTY_TYPE_STRING = 1
   D2D1_PROPERTY_TYPE_BOOL = 2
   D2D1_PROPERTY_TYPE_UINT32 = 3
   D2D1_PROPERTY_TYPE_INT32 = 4
   D2D1_PROPERTY_TYPE_FLOAT = 5
   D2D1_PROPERTY_TYPE_VECTOR2 = 6
   D2D1_PROPERTY_TYPE_VECTOR3 = 7
   D2D1_PROPERTY_TYPE_VECTOR4 = 8
   D2D1_PROPERTY_TYPE_BLOB = 9
   D2D1_PROPERTY_TYPE_IUNKNOWN = 10
   D2D1_PROPERTY_TYPE_ENUM = 11
   D2D1_PROPERTY_TYPE_ARRAY = 12
   D2D1_PROPERTY_TYPE_CLSID = 13
   D2D1_PROPERTY_TYPE_MATRIX_3X2 = 14
   D2D1_PROPERTY_TYPE_MATRIX_4X3 = 15
   D2D1_PROPERTY_TYPE_MATRIX_4X4 = 16
   D2D1_PROPERTY_TYPE_MATRIX_5X4 = 17
   D2D1_PROPERTY_TYPE_COLOR_CONTEXT = 18
   D2D1_PROPERTY_TYPE_FORCE_DWORD = &hffffffff
end enum

'/// This defines the list of system properties present on the root effect property interface.
TYPE D2D1_PROPERTY AS LONG
enum
   D2D1_PROPERTY_CLSID = &h80000000
   D2D1_PROPERTY_DISPLAYNAME = &h80000001
   D2D1_PROPERTY_AUTHOR = &h80000002
   D2D1_PROPERTY_CATEGORY = &h80000003
   D2D1_PROPERTY_DESCRIPTION = &h80000004
   D2D1_PROPERTY_INPUTS = &h80000005
   D2D1_PROPERTY_CACHED = &h80000006
   D2D1_PROPERTY_PRECISION = &h80000007
   D2D1_PROPERTY_MIN_INPUTS = &h80000008
   D2D1_PROPERTY_MAX_INPUTS = &h80000009
   D2D1_PROPERTY_FORCE_DWORD = &hffffffff
end enum

'/// This defines the indices of sub-properties that may be present on any parent property.
TYPE D2D1_SUBPROPERTY AS LONG
enum
   D2D1_SUBPROPERTY_DISPLAYNAME = &h80000000
   D2D1_SUBPROPERTY_ISREADONLY = &h80000001
   D2D1_SUBPROPERTY_MIN = &h80000002
   D2D1_SUBPROPERTY_MAX = &h80000003
   D2D1_SUBPROPERTY_DEFAULT = &h80000004
   D2D1_SUBPROPERTY_FIELDS = &h80000005
   D2D1_SUBPROPERTY_INDEX = &h80000006
   D2D1_SUBPROPERTY_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_BITMAP_OPTIONS AS LONG
enum
   D2D1_BITMAP_OPTIONS_NONE = &h00000000
   D2D1_BITMAP_OPTIONS_TARGET = &h00000001
   D2D1_BITMAP_OPTIONS_CANNOT_DRAW = &h00000002
   D2D1_BITMAP_OPTIONS_CPU_READ = &h00000004
   D2D1_BITMAP_OPTIONS_GDI_COMPATIBLE = &h00000008
   D2D1_BITMAP_OPTIONS_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_COMPOSITE_MODE AS LONG
enum
   D2D1_COMPOSITE_MODE_SOURCE_OVER = 0
   D2D1_COMPOSITE_MODE_DESTINATION_OVER = 1
   D2D1_COMPOSITE_MODE_SOURCE_IN = 2
   D2D1_COMPOSITE_MODE_DESTINATION_IN = 3
   D2D1_COMPOSITE_MODE_SOURCE_OUT = 4
   D2D1_COMPOSITE_MODE_DESTINATION_OUT = 5
   D2D1_COMPOSITE_MODE_SOURCE_ATOP = 6
   D2D1_COMPOSITE_MODE_DESTINATION_ATOP = 7
   D2D1_COMPOSITE_MODE_XOR = 8
   D2D1_COMPOSITE_MODE_PLUS = 9
   D2D1_COMPOSITE_MODE_SOURCE_COPY = 10
   D2D1_COMPOSITE_MODE_BOUNDED_SOURCE_COPY = 11
   D2D1_COMPOSITE_MODE_MASK_INVERT = 12
   D2D1_COMPOSITE_MODE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_BUFFER_PRECISION AS LONG
enum
   D2D1_BUFFER_PRECISION_UNKNOWN = 0
   D2D1_BUFFER_PRECISION_8BPC_UNORM = 1
   D2D1_BUFFER_PRECISION_8BPC_UNORM_SRGB = 2
   D2D1_BUFFER_PRECISION_16BPC_UNORM = 3
   D2D1_BUFFER_PRECISION_16BPC_FLOAT = 4
   D2D1_BUFFER_PRECISION_32BPC_FLOAT = 5
   D2D1_BUFFER_PRECISION_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_MAP_OPTIONS AS LONG
enum
   D2D1_MAP_OPTIONS_NONE = 0
   D2D1_MAP_OPTIONS_READ = 1
   D2D1_MAP_OPTIONS_WRITE = 2
   D2D1_MAP_OPTIONS_DISCARD = 4
   D2D1_MAP_OPTIONS_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_INTERPOLATION_MODE AS LONG
enum
   D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR = D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR
   D2D1_INTERPOLATION_MODE_LINEAR = D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR
   D2D1_INTERPOLATION_MODE_CUBIC = D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC
   D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR = D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR
   D2D1_INTERPOLATION_MODE_ANISOTROPIC = D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC
   D2D1_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC = D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC
   D2D1_INTERPOLATION_MODE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_UNIT_MODE AS LONG
enum
   D2D1_UNIT_MODE_DIPS = 0
   D2D1_UNIT_MODE_PIXELS = 1
   D2D1_UNIT_MODE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_COLOR_SPACE AS LONG
enum
   D2D1_COLOR_SPACE_CUSTOM = 0
   D2D1_COLOR_SPACE_SRGB = 1
   D2D1_COLOR_SPACE_SCRGB = 2
   D2D1_COLOR_SPACE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_DEVICE_CONTEXT_OPTIONS AS LONG
enum
   D2D1_DEVICE_CONTEXT_OPTIONS_NONE = 0
   D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS = 1
   D2D1_DEVICE_CONTEXT_OPTIONS_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_STROKE_TRANSFORM_TYPE AS LONG
enum
   D2D1_STROKE_TRANSFORM_TYPE_NORMAL = 0
   D2D1_STROKE_TRANSFORM_TYPE_FIXED = 1
   D2D1_STROKE_TRANSFORM_TYPE_HAIRLINE = 2
   D2D1_STROKE_TRANSFORM_TYPE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_PRIMITIVE_BLEND AS LONG
enum
   D2D1_PRIMITIVE_BLEND_SOURCE_OVER = 0
   D2D1_PRIMITIVE_BLEND_COPY = 1
   D2D1_PRIMITIVE_BLEND_MIN = 2
   D2D1_PRIMITIVE_BLEND_ADD = 3
   D2D1_PRIMITIVE_BLEND_MAX = 4
   D2D1_PRIMITIVE_BLEND_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_THREADING_MODE AS LONG
enum
   D2D1_THREADING_MODE_SINGLE_THREADED = D2D1_FACTORY_TYPE_SINGLE_THREADED
   D2D1_THREADING_MODE_MULTI_THREADED = D2D1_FACTORY_TYPE_MULTI_THREADED
   D2D1_THREADING_MODE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_COLOR_INTERPOLATION_MODE AS LONG
enum
   D2D1_COLOR_INTERPOLATION_MODE_STRAIGHT = 0,
   D2D1_COLOR_INTERPOLATION_MODE_PREMULTIPLIED = 1,
   D2D1_COLOR_INTERPOLATION_MODE_FORCE_DWORD = &hffffffff
end enum

'typedef D2D_VECTOR_2F D2D1_VECTOR_2F;
'typedef D2D_VECTOR_3F D2D1_VECTOR_3F;
'typedef D2D_VECTOR_4F D2D1_VECTOR_4F;

#define D2D1_VECTOR_2F D2D_VECTOR_2F
#define D2D1_VECTOR_3F D2D_VECTOR_3F
#define D2D1_VECTOR_4F D2D_VECTOR_4F

type D2D1_BITMAP_PROPERTIES1
   AS D2D1_PIXEL_FORMAT pixelFormat
   AS FLOAT dpiX
   AS FLOAT dpiY
   AS D2D1_BITMAP_OPTIONS bitmapOptions
   AS ID2D1ColorContext PTR colorContext
end type

type D2D1_MAPPED_RECT
   AS UINT32 pitch
   AS BYTE PTR bits
end type

type D2D1_RENDERING_CONTROLS
   AS D2D1_BUFFER_PRECISION bufferPrecision
   AS D2D1_SIZE_U tileSize
end type

type D2D1_EFFECT_INPUT_DESCRIPTION
   AS ID2D1Effect PTR effect
   AS UINT32 inputIndex
   AS D2D1_RECT_F inputRectangle
end type

'typedef D2D_MATRIX_4X3_F D2D1_MATRIX_4X3_F;
'typedef D2D_MATRIX_4X4_F D2D1_MATRIX_4X4_F;
'typedef D2D_MATRIX_5X4_F D2D1_MATRIX_5X4_F;

#define D2D1_MATRIX_4X3_F D2D_MATRIX_4X3_F
#define D2D1_MATRIX_4X4_F D2D_MATRIX_4X4_F
#define D2D1_MATRIX_5X4_F D2D_MATRIX_5X4_F

type D2D1_POINT_DESCRIPTION
   AS D2D1_POINT_2F point
   AS D2D1_POINT_2F unitTangentVector
   AS UINT32 endSegment
   AS UINT32 endFigure
   AS FLOAT lengthToEndSegment
end type

type D2D1_IMAGE_BRUSH_PROPERTIES
   AS D2D1_RECT_F sourceRectangle
   AS D2D1_EXTEND_MODE extendModeX
   AS D2D1_EXTEND_MODE extendModeY
   AS D2D1_INTERPOLATION_MODE interpolationMode
end type

type D2D1_BITMAP_BRUSH_PROPERTIES1
   AS D2D1_EXTEND_MODE extendModeX
   AS D2D1_EXTEND_MODE extendModeY
   AS D2D1_INTERPOLATION_MODE interpolationMode
end type

type D2D1_STROKE_STYLE_PROPERTIES1
   AS D2D1_CAP_STYLE startCap
   AS D2D1_CAP_STYLE endCap
   AS D2D1_CAP_STYLE dashCap
   AS D2D1_LINE_JOIN lineJoin
   AS FLOAT miterLimit
   AS D2D1_DASH_STYLE dashStyle
   AS FLOAT dashOffset
   AS D2D1_STROKE_TRANSFORM_TYPE transformType
end type

TYPE D2D1_LAYER_OPTIONS1 AS LONG
enum
   D2D1_LAYER_OPTIONS1_NONE = 0
   D2D1_LAYER_OPTIONS1_INITIALIZE_FROM_BACKGROUND = 1
   D2D1_LAYER_OPTIONS1_IGNORE_ALPHA = 2
   D2D1_LAYER_OPTIONS1_FORCE_DWORD = &hffffffff
end enum

type D2D1_LAYER_PARAMETERS1
   AS D2D1_RECT_F contentBounds
   AS ID2D1Geometry PTR geometricMask
   AS D2D1_ANTIALIAS_MODE maskAntialiasMode
   AS D2D1_MATRIX_3X2_F maskTransform
   AS FLOAT opacity
   AS ID2D1Brush PTR opacityBrush
   AS D2D1_LAYER_OPTIONS1 layerOptions
end type

TYPE D2D1_PRINT_FONT_SUBSET_MODE AS LONG
enum
   D2D1_PRINT_FONT_SUBSET_MODE_DEFAULT = 0
   D2D1_PRINT_FONT_SUBSET_MODE_EACHPAGE = 1
   D2D1_PRINT_FONT_SUBSET_MODE_NONE = 2
   D2D1_PRINT_FONT_SUBSET_MODE_FORCE_DWORD = &hffffffff
end enum

type D2D1_DRAWING_STATE_DESCRIPTION1
   AS D2D1_ANTIALIAS_MODE antialiasMode
   AS D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode
   AS D2D1_TAG tag1
   AS D2D1_TAG tag2
   AS D2D1_MATRIX_3X2_F transform
   AS D2D1_PRIMITIVE_BLEND primitiveBlend
   AS D2D1_UNIT_MODE unitMode
end type

type D2D1_PRINT_CONTROL_PROPERTIES
   AS D2D1_PRINT_FONT_SUBSET_MODE fontSubset
   AS FLOAT rasterDPI
   AS D2D1_COLOR_SPACE colorSpace
end type

type D2D1_CREATION_PROPERTIES
   AS D2D1_THREADING_MODE threadingMode
   AS D2D1_DEBUG_LEVEL debugLevel
   AS D2D1_DEVICE_CONTEXT_OPTIONS options
end type


' ########################################################################################
' Interface name: ID2D1GdiMetafileSink
' IID: {82237326-8111-4F7C-BCF4-B5C1175564FE}
' Inherited interface = IUnknown
' User-implementable interface for introspecting on a metafile.
' ########################################################################################

#ifndef __ID2D1GdiMetafileSink_INTERFACE_DEFINED__
#define __ID2D1GdiMetafileSink_INTERFACE_DEFINED__

TYPE ID2D1GdiMetafileSink_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION ProcessRecord (BYVAL recordType AS DWORD, BYVAL recordData AS const ANY PTR, BYVAL recordDataSize AS DWORD) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GdiMetafile
' IID: {2F543DC3-CFC1-4211-864F-CFD91C6F3395}
' Inherited interface = ID2D1Resource
' Interface encapsulating a GDI/GDI+ metafile.
' ########################################################################################

#ifndef __ID2D1GdiMetafile_INTERFACE_DEFINED__
#define __ID2D1GdiMetafile_INTERFACE_DEFINED__

TYPE ID2D1GdiMetafile_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION stream (BYVAL sink AS ID2D1GdiMetafileSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBounds (BYREF bounds AS D2D1_RECT_F) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1CommandSink
' IID: {54D7898A-A061-40A7-BEC7-E465BCBA2C4F}
' Inherited interface = IUnknown
' Caller-supplied implementation of an interface to receive the recorded command list.
' ########################################################################################

#ifndef __ID2D1CommandSink_INTERFACE_DEFINED__
#define __ID2D1CommandSink_INTERFACE_DEFINED__

TYPE ID2D1CommandSink_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION BeginDraw () AS HRESULT
   DECLARE ABSTRACT FUNCTION EndDraw () AS HRESULT
   DECLARE ABSTRACT FUNCTION SetAntialiasMode (BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTags (BYVAL tag1 AS D2D1_TAG, BYVAL tag2 AS D2D1_TAG) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTextAntialiasMode (BYVAL textAntialiasMode AS D2D1_TEXT_ANTIALIAS_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTransform (BYREF transform AS const D2D1_MATRIX_3X2_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPrimitiveBlend (BYVAL primitiveBlend AS D2D1_PRIMITIVE_BLEND) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetUnitMode (BYVAL unitMode AS D2D1_UNIT_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION Clear (BYREF color AS D2D1_COLOR_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS DWRITE_GLYPH_RUN, _
      BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL foregroundBrush AS ID2D1Brush PTR, _
      BYVAL measuringMode AS DWRITE_MEASURING_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawLine (BYVAL point0 AS D2D1_POINT_2F, BYVAL point1 AS D2D1_POINT_2F, _
      BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR, _
      BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF destinationRectangle AS D2D1_RECT_F, _
      BYVAL opacity AS FLOAT, BYVAL interpolationMode AS D2D1_INTERPOLATION_MODE, BYREF sourceRectangle AS const D2D1_RECT_F, _
      BYREF perspectiveTransform AS D2D1_MATRIX_4X4_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawImage (BYVAL image AS ID2D1Image PTR, BYREF targetOffset AS const D2D1_POINT_2F, _
      BYREF imageRectangle AS const D2D1_RECT_F, BYVAL interpolationMode AS D2D1_INTERPOLATION_MODE, BYVAL compositeMode AS D2D1_COMPOSITE_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGdiMetafile (BYVAL gdiMetafile AS ID2D1GdiMetafile PTR, BYREF targetOffset AS D2D1_POINT_2F) AS HRESULT
   DECLARE ABSTRACT FUNCTION FillMesh (BYVAL mesh AS ID2D1Mesh PTR, BYVAL brush AS ID2D1Brush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
      BYREF destinationRectangle AS const D2D1_RECT_F, BYREF sourceRectangle AS const D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION FillGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR, BYVAL opacityBrush AS ID2D1Brush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION FillRectangle (BYREF rect AS D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION PushAxisAlignedClip (BYREF clipRect AS D2D1_RECT_F, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE) AS HRESULT
   DECLARE ABSTRACT FUNCTION PushLayer (BYREF layerParameters1 AS D2D1_LAYER_PARAMETERS1, BYVAL layer AS ID2D1Layer PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION PopAxisAlignedClip () AS HRESULT
   DECLARE ABSTRACT FUNCTION PopLayer () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1CommandList
' IID: {B4F34A19-2383-4D76-94F6-EC343657C3DC}
' Inherited interface = ID2D1Image
' The commandList interface.
' ########################################################################################

#ifndef __ID2D1CommandList_INTERFACE_DEFINED__
#define __ID2D1CommandList_INTERFACE_DEFINED__

TYPE ID2D1CommandList_ EXTENDS ID2D1Image
   DECLARE ABSTRACT FUNCTION Stream (BYVAL sink AS ID2D1CommandSink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Close () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1PrintControl
' IID: {2C1D867D-C290-41C8-AE7E-34A98702E9A5}
' Inherited interface = IUnknown
' Converts Direct2D primitives stored in an ID2D1CommandList into a fixed page
' representation. The print sub-system then consumes the primitives.
' ########################################################################################

#ifndef __ID2D1PrintControl_INTERFACE_DEFINED__
#define __ID2D1PrintControl_INTERFACE_DEFINED__

TYPE ID2D1PrintControl_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION AddPage (BYVAL commandList AS ID2D1CommandList PTR, BYVAL pageSize AS D2D_SIZE_F, _
      BYVAL pagePrintTicketStream AS IStream PTR, BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL) AS HRESULT
   DECLARE ABSTRACT FUNCTION Close () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1ImageBrush
' IID: {FE9E984D-3F95-407C-B5DB-CB94D4E8F87C}
' Inherited interface = ID2D1Brush
' Provides a brush that can take any effect, command list or bitmap and use it to fill a 2D shape.
' ########################################################################################

#ifndef __ID2D1ImageBrush_INTERFACE_DEFINED__
#define __ID2D1ImageBrush_INTERFACE_DEFINED__

TYPE ID2D1ImageBrush_ EXTENDS ID2D1Brush
   DECLARE ABSTRACT SUB SetImage (BYVAL image AS ID2D1Image PTR)
   DECLARE ABSTRACT SUB SetExtendModeX (BYVAL extendModeX AS D2D1_EXTEND_MODE)
   DECLARE ABSTRACT SUB SetExtendModeY (BYVAL extendModeY AS D2D1_EXTEND_MODE)
   DECLARE ABSTRACT SUB SetInterpolationMode (BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE)
   DECLARE ABSTRACT SUB SetSourceRectangle (BYREF sourceRectangle AS D2D1_RECT_F)
   DECLARE ABSTRACT SUB GetImage (BYREF image AS ID2D1Image PTR)
   DECLARE ABSTRACT FUNCTION GetExtendModeX () AS D2D1_EXTEND_MODE
   DECLARE ABSTRACT FUNCTION GetExtendModeY () AS D2D1_EXTEND_MODE
   DECLARE ABSTRACT FUNCTION GetInterpolationMode () AS D2D1_INTERPOLATION_MODE
   DECLARE ABSTRACT SUB GetSourceRectangle (BYREF sourceRectangle AS D2D1_RECT_F)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1BitmapBrush1
' IID: {41343A53-E41A-49A2-91CD-21793BBB62E5}
' Inherited interface = ID2D1BitmapBrush
' A bitmap brush allows a bitmap to be used to fill a geometry.  Interpolation
' mode is specified with D2D1_INTERPOLATION_MODE
' ########################################################################################

#ifndef __ID2D1BitmapBrush1_INTERFACE_DEFINED__
#define __ID2D1BitmapBrush1_INTERFACE_DEFINED__

TYPE ID2D1BitmapBrush1_ EXTENDS ID2D1BitmapBrush
   ' /// Sets the interpolation mode used when this brush is used.
   DECLARE ABSTRACT SUB SetInterpolationMode1 (BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE)
   DECLARE ABSTRACT FUNCTION GetInterpolationMode1 () AS D2D1_INTERPOLATION_MODE
END TYPE
 
#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1StrokeStyle1
' IID: {10A72A66-E91C-43F4-993F-DDF4B82B0B4A}
' Inherited interface = ID2D1StrokeStyle
' Extends a stroke style to allow nominal width strokes.
' ########################################################################################

#ifndef __ID2D1StrokeStyle1_INTERFACE_DEFINED__
#define __ID2D1StrokeStyle1_INTERFACE_DEFINED__

TYPE ID2D1StrokeStyle1_ EXTENDS ID2D1StrokeStyle
   DECLARE ABSTRACT FUNCTION GetStrokeTransformType () AS D2D1_STROKE_TRANSFORM_TYPE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1PathGeometry1
' IID: {62BAA2D2-AB54-41B7-B872-787E0106A421}
' Inherited interface = ID2D1PathGeometry
' The ID2D1PathGeometry1 interface adds functionality to ID2D1PathGeometry. In
' particular, it provides the path geometry-specific ComputePointAndSegmentAtLength method.
' ########################################################################################

#ifndef __ID2D1PathGeometry1_INTERFACE_DEFINED__
#define __ID2D1PathGeometry1_INTERFACE_DEFINED__

TYPE ID2D1PathGeometry1_ EXTENDS ID2D1PathGeometry
   DECLARE ABSTRACT FUNCTION ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
      BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
      BYREF pointDescription AS D2D1_POINT_DESCRIPTION) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Properties
' IID: {483473D7-CD46-4F9D-9D3A-3112AA80159D}
' Inherited interface = IUnknown
' Represents a set of run-time bindable and discoverable properties that allow a
' data-driven application to modify the state of a Direct2D effect.
' ########################################################################################

#ifndef __ID2D1Properties_INTERFACE_DEFINED__
#define __ID2D1Properties_INTERFACE_DEFINED__

TYPE ID2D1Properties_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetPropertyCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetPropertyName (BYVAL index AS UINT32, BYREF wszName AS WSTRING, BYVAL nameCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPropertyNameLength (BYVAL index AS UINT32) AS UINT32
   DECLARE ABSTRACT FUNCTION GetType (BYVAL index AS UINT32) AS D2D1_PROPERTY_TYPE
   DECLARE ABSTRACT FUNCTION GetPropertyIndex (BYREF wszName AS WSTRING) AS UINT32
   DECLARE ABSTRACT FUNCTION SetValueByName (BYREF wszName AS WSTRING, BYVAL type AS D2D1_PROPERTY_TYPE, _
      BYVAL data AS const BYTE PTR, BYVAL dataSize AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetValue (BYVAL index AS UINT32, BYVAL type AS D2D1_PROPERTY_TYPE, _
      BYVAL data AS BYTE PTR, BYVAL dataSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetValueByName (BYREF wszName AS WSTRING, BYVAL type AS D2D1_PROPERTY_TYPE, _
      BYVAL data AS BYTE PTR, BYVAL dataSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetValue (BYVAL index AS UINT32, BYVAL type AS D2D1_PROPERTY_TYPE, _
      BYVAL data AS BYTE PTR, BYVAL dataSize AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetValueSize (BYVAL index AS UINT32) AS UINT32
   DECLARE ABSTRACT FUNCTION GetSubProperties (BYVAL index AS UINT32, BYREF subProperties AS ID2D1Properties PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Effect
' IID: {28211A43-7D89-476F-8181-2D6159B220AD}
' Inherited interface = ID2D1Properties
' Number of methods = 5
' The effect interface. Properties control how the effect is rendered. The effect
' is Drawn with the DrawImage call.
' ########################################################################################

#ifndef __ID2D1Effect_INTERFACE_DEFINED__
#define __ID2D1Effect_INTERFACE_DEFINED__

TYPE ID2D1Effect_ EXTENDS ID2D1Properties
   DECLARE ABSTRACT SUB SetInput (BYVAL index AS UINT32, BYVAL input AS ID2D1Image PTR, BYVAL Invalidate AS BOOLEAN)
   DECLARE ABSTRACT FUNCTION SetInputCount (BYVAL inputCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT SUB GetInput (BYVAL index AS UINT32, BYREF input AS ID2D1Image PTR)
   DECLARE ABSTRACT FUNCTION GetInputCount () AS UINT32
   DECLARE ABSTRACT SUB GetOutput (BYREF outputImage AS ID2D1Image PTR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Bitmap1
' IID: {A898A84C-3873-4588-B08B-EBBF978DF041}
' Inherited interface = ID2D1Bitmap
' Represents a bitmap that can be used as a surface for an ID2D1DeviceContext or
' mapped into system memory, and can contain additional color context information.
' ########################################################################################

#ifndef __ID2D1Bitmap1_INTERFACE_DEFINED__
#define __ID2D1Bitmap1_INTERFACE_DEFINED__

TYPE ID2D1Bitmap1_ EXTENDS ID2D1Bitmap
   DECLARE ABSTRACT SUB GetColorContext (BYREF colorContext AS ID2D1ColorContext PTR)
   DECLARE ABSTRACT FUNCTION GetOptions () AS D2D1_BITMAP_OPTIONS
   DECLARE ABSTRACT FUNCTION GetSurface (BYREF dxgiSurface AS IDXGISurface PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Map (BYVAL options AS D2D1_MAP_OPTIONS, BYREF mappedRect AS D2D1_MAPPED_RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION Unmap () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1ColorContext
' IID: {1C4820BB-5771-4518-A581-2FE4DD0EC657}
' Inherited interface = ID2D1Resource
' Represents a color context that can be used with an ID2D1Bitmap1 object.
' ########################################################################################

#ifndef __ID2D1ColorContext_INTERFACE_DEFINED__
#define __ID2D1ColorContext_INTERFACE_DEFINED__

TYPE ID2D1ColorContext_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION GetColorSpace () AS D2D1_COLOR_SPACE
   DECLARE ABSTRACT FUNCTION GetProfileSize () AS UINT32
   DECLARE ABSTRACT FUNCTION GetProfile (BYVAL profile AS BYTE PTR, BYVAL profileSize AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GradientStopCollection1
' IID: {AE1572F4-5DD0-4777-998B-9279472AE63B}
' Inherited interface = ID2D1GradientStopCollection
' Represents an collection of gradient stops that can then be the source resource
' for either a linear or radial gradient brush.
' ########################################################################################

#ifndef __ID2D1GradientStopCollection1_INTERFACE_DEFINED__
#define __ID2D1GradientStopCollection1_INTERFACE_DEFINED__

TYPE ID2D1GradientStopCollection1_ EXTENDS ID2D1GradientStopCollection
   DECLARE ABSTRACT SUB GetGradientStops1 (BYREF gradientStops AS D2D1_GRADIENT_STOP, BYVAL gradientStopsCount AS UINT32)
   DECLARE ABSTRACT FUNCTION GetPreInterpolationSpace () AS D2D1_COLOR_SPACE
   DECLARE ABSTRACT FUNCTION GetPostInterpolationSpace () AS D2D1_COLOR_SPACE
   DECLARE ABSTRACT FUNCTION GetBufferPrecision () AS D2D1_BUFFER_PRECISION
   DECLARE ABSTRACT FUNCTION GetColorInterpolationMode () AS D2D1_COLOR_INTERPOLATION_MODE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1DrawingStateBlock1
' IID: {689F1F85-C72E-4E33-8F19-85754EFD5ACE}
' Inherited interface = ID2D1DrawingStateBlock
' Represents drawing state.
' ########################################################################################

#ifndef __ID2D1DrawingStateBlock1_INTERFACE_DEFINED__
#define __ID2D1DrawingStateBlock1_INTERFACE_DEFINED__

TYPE ID2D1DrawingStateBlock1_ EXTENDS ID2D1DrawingStateBlock
   DECLARE ABSTRACT SUB GetDescription1 (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1)
   DECLARE ABSTRACT SUB SetDescription1 (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DeviceContext
' IID: {E8F7FE7A-191C-466D-AD95-975678BDA998}
' Inherited interface = ID2D1RenderTarget
' The device context represents a set of state and a command buffer that is used
' to render to a target bitmap.
' ########################################################################################

#ifndef __ID2D1DeviceContext_INTERFACE_DEFINED__
#define __ID2D1DeviceContext_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext_ EXTENDS ID2D1RenderTarget
   DECLARE ABSTRACT FUNCTION CreateBitmap (BYVAL size AS D2D1_SIZE_U, BYVAL sourceData AS const ANY PTR, _
      BYVAL pitch AS UINT32, BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES1, BYREF bitmap AS ID2D1Bitmap1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR,_
      BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES1, BYREF bitmap AS ID2D1Bitmap1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorContext (BYVAL space AS D2D1_COLOR_SPACE, BYVAL profile AS BYTE PTR, _
      BYVAL profileSize AS UINT32, BYREF colorContext AS ID2D1ColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorContextFromFilename (BYREF filename AS WSTRING, BYREF colorContext AS ID2D1ColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorContextFromWicColorContext (BYVAL wicColorContext AS IWICColorContext PTR, BYVAL colorContext AS ID2D1ColorContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapFromDxgiSurface (BYVAL surface AS IDXGISurface PTR, _
      BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES1, BYREF bitmap AS ID2D1Bitmap1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateEffect (BYREF effectId AS CLSID, BYREF effect AS ID2D1Effect PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGradientStopCollection (BYREF straightAlphaGradientStops AS const D2D1_GRADIENT_STOP, _
      BYVAL straightAlphaGradientStopsCount AS UINT32, BYVAL preInterpolationSpace AS D2D1_COLOR_SPACE, _
      BYVAL postInterpolationSpace AS D2D1_COLOR_SPACE, BYVAL bufferPrecision AS D2D1_BUFFER_PRECISION, _
      BYVAL extendMode AS D2D1_EXTEND_MODE, BYVAL colorInterpolationMode AS D2D1_COLOR_INTERPOLATION_MODE, _
      BYREF gradientStopCollection1 AS ID2D1GradientStopCollection1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateImageBrush (BYVAL image AS ID2D1Image PTR, BYREF imageBrushProperties AS D2D1_IMAGE_BRUSH_PROPERTIES, _
      BYREF brushProperties AS D2D1_BRUSH_PROPERTIES, BYREF imageBrush AS ID2D1ImageBrush PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES1, _
      BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, BYREF bitmapBrush AS ID2D1BitmapBrush1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateCommandList (BYREF commandList AS ID2D1CommandList PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsDxgiFormatSupported (BYVAL format AS DXGI_FORMAT) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION IsBufferPrecisionSupported (BYVAL bufferPrecision AS D2D1_BUFFER_PRECISION) AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetImageLocalBounds (BYVAL image AS ID2D1Image PTR, BYREF localBounds AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetImageWorldBounds (BYVAL image AS ID2D1Image PTR, BYREF worldBounds AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGlyphRunWorldBounds (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS DWRITE_GLYPH_RUN, _
      BYVAL measuringMode AS DWRITE_MEASURING_MODE, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT SUB GetDevice (BYREF device AS ID2D1Device PTR)
   DECLARE ABSTRACT SUB SetTarget (BYVAL image AS ID2D1Image PTR)
   DECLARE ABSTRACT SUB GetTarget (BYREF image AS ID2D1Image PTR)
   DECLARE ABSTRACT SUB SetRenderingControls (BYREF renderingControls AS D2D1_RENDERING_CONTROLS)
   DECLARE ABSTRACT SUB GetRenderingControls (BYREF renderingControls AS D2D1_RENDERING_CONTROLS)
   DECLARE ABSTRACT SUB SetPrimitiveBlend (BYVAL primitiveBlend AS D2D1_PRIMITIVE_BLEND)
   DECLARE ABSTRACT FUNCTION GetPrimitiveBlend () AS D2D1_PRIMITIVE_BLEND
   DECLARE ABSTRACT SUB SetUnitMode (BYVAL unitMode AS D2D1_UNIT_MODE)
   DECLARE ABSTRACT FUNCTION GetUnitMode () AS D2D1_UNIT_MODE
   DECLARE ABSTRACT SUB DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
      BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL foregroundBrush AS ID2D1Brush PTR, _
      BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE ABSTRACT SUB DrawImage (BYVAL image AS ID2D1Image PTR, BYVAL targetOffset AS const D2D1_POINT_2F PTR, _
      BYREF imageRectangle AS const D2D1_RECT_F, BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE = D2D1_INTERPOLATION_MODE_LINEAR, _
      BYVAL compositeMode AS D2D1_COMPOSITE_MODE = D2D1_COMPOSITE_MODE_SOURCE_OVER)
   DECLARE ABSTRACT SUB DrawGdiMetafile (BYVAL gdiMetafile AS ID2D1GdiMetafile PTR, BYVAL targetOffset AS const D2D1_POINT_2F PTR)
   DECLARE ABSTRACT SUB DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF destinationRectangle AS D2D1_RECT_F, _
      BYVAL opacity AS FLOAT, BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE, BYREF sourceRectangle AS D2D1_RECT_F, _
      BYREF perspectiveTransform AS D2D1_MATRIX_4X4_F)
   DECLARE ABSTRACT SUB PushLayer (BYREF layerParameters AS D2D1_LAYER_PARAMETERS1, BYVAL layer AS ID2D1Layer PTR)
   DECLARE ABSTRACT FUNCTION InvalidateEffectInputRectangle (BYVAL effect AS ID2D1Effect PTR, BYVAL input AS UINT32, _
      BYREF inputRectangle AS const D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEffectInvalidRectangleCount (BYVAL effect AS ID2D1Effect PTR, BYREF rectangleCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEffectInvalidRectangles (BYVAL effect AS ID2D1Effect PTR, BYREF rectangles AS D2D1_RECT_F, BYVAL rectanglesCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEffectRequiredInputRectangles (BYVAL renderEffect AS ID2D1Effect PTR, BYREF renderImageRectangle AS const D2D1_RECT_F, _
      BYREF inputDescriptions AS const D2D1_EFFECT_INPUT_DESCRIPTION, BYREF requiredInputRects AS D2D1_RECT_F, BYVAL inputCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT SUB FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
      BYREF destinationRectangle AS const D2D1_RECT_F, BYREF sourceRectangle AS const D2D1_RECT_F)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device
' IID: {47DD575D-AC05-4CDD-8049-9B02CD16F44C}
' Inherited interface = ID2D1Resource
' The device defines a resource domain whose objects and device contexts can be used together.
' ########################################################################################

#ifndef __ID2D1Device_INTERFACE_DEFINED__
#define __ID2D1Device_INTERFACE_DEFINED__

TYPE ID2D1Device_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION CreateDeviceContext (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext AS ID2D1DeviceContext PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreatePrintControl (BYVAL wicFactory AS IWICImagingFactory PTR, _
      BYVAL documentTarget AS IPrintDocumentPackageTarget PTR, BYREF printControlProperties AS D2D1_PRINT_CONTROL_PROPERTIES, _
      BYREF printControl AS ID2D1PrintControl PTR) AS HRESULT
   DECLARE ABSTRACT SUB SetMaximumTextureMemory (BYVAL maximumInBytes AS UINT64)
   DECLARE ABSTRACT FUNCTION GetMaximumTextureMemory () AS UINT64
   DECLARE ABSTRACT SUB ClearResources (BYVAL millisecondsSinceUse AS UINT32)
END TYPE

#endif

' ########################################################################################

TYPE IDXGIDevice AS IDXGIDevice_

' ########################################################################################
' * Interface name: ID2D1Factory1
' IID: {BB12D362-DAEE-4B9A-AA1D-14BA401CFA1F}
' Inherited interface = ID2D1Factory
' Creates Direct2D resources.
' ########################################################################################

#ifndef __ID2D1Factory1_INTERFACE_DEFINED__
#define __ID2D1Factory1_INTERFACE_DEFINED__

TYPE ID2D1Factory1_ EXTENDS ID2D1Factory
   DECLARE ABSTRACT FUNCTION CreateDevice (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice AS ID2D1Device PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateStrokeStyle1 (BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES1, _
      BYREF dashes AS const FLOAT, BYVAL dashesCount AS UINT32, BYREF strokeStyle AS ID2D1StrokeStyle1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreatePathGeometry1 (BYREF pathGeometry AS ID2D1PathGeometry1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDrawingStateBlock1 (BYREF drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1, _
      BYVAL textRenderingParams AS IDWriteRenderingParams PTR, BYREF drawingStateBlock AS ID2D1DrawingStateBlock1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGdiMetafile (BYVAL metafileStream AS IStream PTR, BYREF metafile AS ID2D1GdiMetafile PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterEffectFromStream (BYREF ClassId AS CLSID, BYVAL propertyXml AS IStream PTR, _
      BYREF bindings AS const D2D1_PROPERTY_BINDING, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterEffectFromString (BYREF ClassId AS CLSID, BYREF propertyXml AS WSTRING, _
      BYREF bindings AS const D2D1_PROPERTY_BINDING, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS PD2D1_EFFECT_FACTORY) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterEffect (BYREF ClassId AS CLSID) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRegisteredEffects (BYREF effects AS CLSID, BYVAL effectsCount AS UINT32, _
      BYREF effectsReturned AS UINT32, BYREF effectsRegistered AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEffectProperties (BYREF effectId AS CLSID, BYREF d2d1properties AS ID2D1Properties PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Multithread
' IID: {31E6E7BC-E0FF-4D46-8C64-A0A8C41C15D3}
' Inherited interface = IUnknown
' A locking mechanism from a Direct2D factory that Direct2D uses to control
' exclusive resource access in an app that is uses multiple threads.
' ########################################################################################

#ifndef __ID2D1Multithread_INTERFACE_DEFINED__
#define __ID2D1Multithread_INTERFACE_DEFINED__

TYPE ID2D1Multithread_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetMultithreadProtected () AS BOOLEAN
   DECLARE ABSTRACT SUB Enter ()
   DECLARE ABSTRACT SUB Leave ()
END TYPE

#endif

' ########################################################################################

' ########################################################################################
'                               *** D2D1 Functions ***
' ########################################################################################

' ========================================================================================
' Creates a new Direct2D device associated with the provided DXGI device.
' ========================================================================================
DECLARE FUNCTION D2D1CreateDevice LIB "d2d1" ALIAS "D2D1CreateDevice" (BYVAL dxgiDevice AS IDXGIDevice PTR, _
   BYREF creationProperties AS const D2D1_CREATION_PROPERTIES, BYREF d2dDevice AS ID2D1Device PTR) AS HRESULT
' ========================================================================================

' ========================================================================================
' Creates a new Direct2D device context associated with a DXGI surface.
' ========================================================================================
DECLARE FUNCTION D2D1CreateDeviceContext LIB "d2d1" ALIAS "D2D1CreateDeviceContext" (BYVAL dxgiSurface AS IDXGISurface PTR, _
   BYREF creationProperties AS const D2D1_CREATION_PROPERTIES, BYREF d2dDeviceContext AS ID2D1DeviceContext PTR) AS HRESULT
' ========================================================================================

' ========================================================================================
' Converts the given color from one colorspace to another.
' ========================================================================================
'DECLARE FUNCTION D2D1ConvertColorSpace LIB "d2d1" ALIAS "D2D1ConvertColorSpace" (BYREF sourceColorSpace AS D2D1_COLOR_SPACE, _
'   BYREF destinationColorSpace AS D2D1_COLOR_SPACE, BYREF color AS D2D1_COLOR_F) AS D2D1_COLOR_F
DECLARE SUB D2D1ConvertColorSpace LIB "d2d1" ALIAS "D2D1ConvertColorSpace" (BYREF sourceColorSpace AS D2D1_COLOR_SPACE, _
   BYREF destinationColorSpace AS D2D1_COLOR_SPACE, BYREF sourceColor AS D2D1_COLOR_F, BYREF convertedColor AS D2D1_COLOR_F)
' ========================================================================================

' ========================================================================================
' Returns the sine and cosine of an angle.
' ========================================================================================
DECLARE SUB D2D1SinCos LIB "d2d1" ALIAS "D2D1SinCos" (BYVAL angle AS FLOAT, BYREF s AS FLOAT, BYREF c AS FLOAT)
' ========================================================================================

' ========================================================================================
' Returns the tangent of an angle.
' ========================================================================================
DECLARE FUNCTION D2D1Tan LIB "d2d1" ALIAS "D2D1Tan" (BYVAL angle AS FLOAT) AS FLOAT
' ========================================================================================

' ========================================================================================
' Returns the length of a 3 dimensional vector.
' ========================================================================================
DECLARE FUNCTION D2D1Vec3Length LIB "d2d1" ALIAS "D2D1Vec3Length" (BYVAL x AS FLOAT, BYVAL y AS FLOAT, BYVAL z AS FLOAT) AS FLOAT
' ========================================================================================


' ########################################################################################
'                                   *** d2d1_2.h ***
' ########################################################################################

DIM SHARED IID_ID2D1GeometryRealization AS GUID = TYPE<GUID>(&hA16907D7, &hBC02, &h4801, {&h99, &hE8, &h8C, &hF7, &hF4, &h85, &hF7, &h74})
DIM SHARED IID_ID2D1DeviceContext1 AS GUID = TYPE<GUID>(&hD37F57E4, &h6908, &h459F, {&hA1, &h99, &hE7, &h2F, &h24, &hF7, &h99, &h87})
DIM SHARED IID_ID2D1Device1 AS GUID = TYPE<GUID>(&hD21768E1, &h23A4, &h4823, {&hA1, &h4B, &h7C, &h3E, &hBA, &h85, &hD6, &h58})
DIM SHARED IID_ID2D1Factory2 AS GUID = TYPE<GUID>(&h94F81A73, &h9212, &h4376, {&h9C, &h58, &hB1, &h6A, &h3A, &h0D, &h39, &h92})
DIM SHARED IID_ID2D1CommandSink1 AS GUID = TYPE<GUID>(&h9EB767FD, &h4269, &h4467, {&hB8, &hC2, &hEB, &h30, &hCB, &h30, &h57, &h43})

' // Forward references
TYPE ID2D1GeometryRealization AS ID2D1GeometryRealization_
TYPE ID2D1DeviceContext1 AS ID2D1DeviceContext1_
TYPE ID2D1Device1 AS ID2D1Device1_
TYPE ID2D1Factory2 AS ID2D1Factory2_
TYPE ID2D1CommandSink1 AS ID2D1CommandSink1_

TYPE D2D1_RENDERING_PRIORITY AS LONG
enum
   D2D1_RENDERING_PRIORITY_NORMAL = 0
   D2D1_RENDERING_PRIORITY_LOW = 1
   D2D1_RENDERING_PRIORITY_FORCE_DWORD = &hffffffff
end enum

' ########################################################################################
' Interface name: ID2D1GeometryRealization
' IID: {a16907d7-bc02-4801-99e8-8cf7f485f774}
' Inherited interface = ID2D1Resource
' Encapsulates a device- and transform-dependent representation of a filled or stroked geometry.
' ########################################################################################

#ifndef __ID2D1GeometryRealization_INTERFACE_DEFINED__
#define __ID2D1GeometryRealization_INTERFACE_DEFINED__

TYPE ID2D1GeometryRealization_ EXTENDS ID2D1Resource
   ' It has no additional methods
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DeviceContext1
' IID: {D37F57E4-6908-459F-A199-E72F24F79987}
' Inherited interface = ID2D1DeviceContext
' ########################################################################################

#ifndef __ID2D1DeviceContext1_INTERFACE_DEFINED__
#define __ID2D1DeviceContext1_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext1_ EXTENDS ID2D1DeviceContext
   DECLARE ABSTRACT FUNCTION CreateFilledGeometryRealization (BYVAL geometry AS ID2D1Geometry PTR, BYVAL flatteningTolerance AS FLOAT, BYREF geometryRealization AS ID2D1GeometryRealization PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateStrokedGeometryRealization (BYVAL geometry AS ID2D1Geometry PTR, BYVAL flatteningTolerance AS FLOAT, _
           BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF geometryRealization AS ID2D1GeometryRealization PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGeometryRealization (BYVAL geometryRealization AS ID2D1GeometryRealization PTR, BYVAL brush AS ID2D1Brush PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device1
' IID: {D21768E1-23A4-4823-A14B-7C3EBA85D658}
' Inherited interface = ID2D1Device
' ########################################################################################

#ifndef __ID2D1Device1_INTERFACE_DEFINED__
#define __ID2D1Device1_INTERFACE_DEFINED__

TYPE ID2D1Device1_ EXTENDS ID2D1Device
   DECLARE ABSTRACT FUNCTION GetRenderingPriority () AS D2D1_RENDERING_PRIORITY
   DECLARE ABSTRACT SUB SetRenderingPriority (BYVAL renderingPriority AS D2D1_RENDERING_PRIORITY)
   DECLARE ABSTRACT FUNCTION CreateDeviceContext1 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext1 AS ID2D1DeviceContext1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory2
' IID: {94F81A73-9212-4376-9C58-B16A3A0D3992}
' Inherited interface = ID2D1Factory1
' This creates a new Direct2D device from the given IDXGIDevice.
' ########################################################################################

#ifndef __ID2D1Factory2_INTERFACE_DEFINED__
#define __ID2D1Factory2_INTERFACE_DEFINED__

TYPE ID2D1Factory2_ EXTENDS ID2D1Factory1
   DECLARE ABSTRACT FUNCTION CreateDevice1 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice1 AS ID2D1Device1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: ID2D1CommandSink1
' IID: {9EB767FD-4269-4467-B8C2-EB30CB305743}
' Inherited interface = ID2D1CommandSink
' ########################################################################################

#ifndef __ID2D1CommandSink1_INTERFACE_DEFINED__
#define __ID2D1CommandSink1_INTERFACE_DEFINED__

TYPE ID2D1CommandSink1_ EXTENDS ID2D1CommandSink
   DECLARE ABSTRACT FUNCTION SetPrimitiveBlend1 (BYVAL primitiveBlend AS D2D1_PRIMITIVE_BLEND) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ========================================================================================
' Computes the maximum factor by which a given transform can stretch any vector.
' ========================================================================================
DECLARE FUNCTION D2D1ComputeMaximumScaleFactor LIB "d2d1" ALIAS "D2D1ComputeMaximumScaleFactor" (BYREF matrix AS const D2D1_MATRIX_3X2_F) AS FLOAT
' ========================================================================================


' ########################################################################################
'                                   *** d2d1_3.h ***
' ########################################################################################

DIM SHARED IID_ID2D1InkStyle AS GUID = TYPE<GUID>(&hBAE8B344, &h23FC, &h4071, {&h8C, &hB5, &hD0, &h5D, &h6F, &h07, &h38, &h48})
DIM SHARED IID_ID2D1Ink AS GUID = TYPE<GUID>(&hB499923B, &h7029, &h478F, {&hA8, &hB3, &h43, &h2C, &h7C, &h5F, &h53, &h12})
DIM SHARED IID_ID2D1GradientMesh AS GUID = TYPE<GUID>(&hF292E401, &hC050, &h4CDE, {&h83, &hD7, &h04, &h96, &h2D, &h3B, &h23, &hC2})
DIM SHARED IID_ID2D1ImageSource AS GUID = TYPE<GUID>(&hC9B664E5, &h74A1, &h4378, {&h9A, &hC2, &hEE, &hFC, &h37, &hA3, &hF4, &hD8})
DIM SHARED IID_ID2D1ImageSourceFromWic AS GUID = TYPE<GUID>(&h77395441, &h1C8F, &h4555, {&h86, &h83, &hF5, &h0D, &hAB, &h0F, &hE7, &h92})
DIM SHARED IID_ID2D1TransformedImageSource AS GUID = TYPE<GUID>(&h7F1F79E5, &h2796, &h416C, {&h8F, &h55, &h70, &h0F, &h91, &h14, &h45, &hE5})
DIM SHARED IID_ID2D1LookupTable3D AS GUID = TYPE<GUID>(&h53DD9855, &hA3B0, &h4D5B, {&h82, &hE1, &h26, &hE2, &h5C, &h5E, &h57, &h97})
DIM SHARED IID_ID2D1DeviceContext2 AS GUID = TYPE<GUID>(&h394EA6A3, &h0C34, &h4321, {&h95, &h0B, &h6C, &hA2, &h0F, &h0B, &hE6, &hC7})
DIM SHARED IID_ID2D1Device2 AS GUID = TYPE<GUID>(&hA44472E1, &h8DFB, &h4E60, {&h84, &h92, &h6E, &h28, &h61, &hC9, &hCA, &h8B})
DIM SHARED IID_ID2D1Factory3 AS GUID = TYPE<GUID>(&h0869759F, &h4F00, &h413F, {&hB0, &h3E, &h2B, &hDA, &h45, &h40, &h4D, &h0F})
DIM SHARED IID_ID2D1CommandSink2 AS GUID = TYPE<GUID>(&h3BAB440E, &h417E, &h47DF, {&hA2, &hE2, &hBC, &h0B, &hE6, &hA0, &h09, &h16})
DIM SHARED IID_ID2D1GdiMetafile1 AS GUID = TYPE<GUID>(&h2E69F9E8, &hDD3F, &h4BF9, {&h95, &hBA, &hC0, &h4F, &h49, &hD7, &h88, &hDF})
DIM SHARED IID_ID2D1GdiMetafileSink1 AS GUID = TYPE<GUID>(&hFD0ECB6B, &h91E6, &h411E, {&h86, &h55, &h39, &h5E, &h76, &h0F, &h91, &hB4})
DIM SHARED IID_ID2D1SpriteBatch AS GUID = TYPE<GUID>(&h4DC583BF, &h3A10, &h438A, {&h87, &h22, &hE9, &h76, &h52, &h24, &hF1, &hF1})
DIM SHARED IID_ID2D1DeviceContext3 AS GUID = TYPE<GUID>(&h235A7496, &h8351, &h414C, {&hBC, &hD4, &h66, &h72, &hAB, &h2D, &h8E, &h00})
DIM SHARED IID_ID2D1Device3 AS GUID = TYPE<GUID>(&h852F2087, &h802C, &h4037, {&hAB, &h60, &hFF, &h2E, &h7E, &hE6, &hFC, &h01})
DIM SHARED IID_ID2D1Factory4 AS GUID = TYPE<GUID>(&hBD4EC2D2, &h0662, &h4BEE, {&hBA, &h8E, &h6F, &h29, &hF0, &h32, &hE0, &h96})
DIM SHARED IID_ID2D1CommandSink3 AS GUID = TYPE<GUID>(&h18079135, &h4CF3, &h4868, {&hBC, &h8E, &h06, &h06, &h7E, &h6D, &h24, &h2D})
DIM SHARED IID_ID2D1SvgGlyphStyle AS GUID = TYPE<GUID>(&hAF671749, &hD241, &h4DB8, {&h8E, &h41, &hDC, &hC2, &hE5, &hC1, &hA4, &h38})
DIM SHARED IID_ID2D1DeviceContext4 AS GUID = TYPE<GUID>(&h8C427831, &h3D90, &h4476, {&hB6, &h47, &hC4, &hFA, &hE3, &h49, &hE4, &hDB})
DIM SHARED IID_ID2D1Device4 AS GUID = TYPE<GUID>(&hD7BDB159, &h5683, &h4A46, {&hBC, &h9C, &h72, &hDC, &h72, &h0B, &h85, &h8B})
DIM SHARED IID_ID2D1Factory5 AS GUID = TYPE<GUID>(&hC4349994, &h838E, &h4B0F, {&h8C, &hAB, &h44, &h99, &h7D, &h9E, &hEA, &hCC})
DIM SHARED IID_ID2D1CommandSink4 AS GUID = TYPE<GUID>(&hC78A6519, &h40D6, &h4218, {&hB2, &hDE, &hBE, &hEE, &hB7, &h44, &hBB, &h3E})
DIM SHARED IID_ID2D1ColorContext1 AS GUID = TYPE<GUID>(&h1AB42875, &hC57F, &h4BE9, {&hBD, &h85, &h9C, &hD7, &h8D, &h6F, &h55, &hEE})
DIM SHARED IID_ID2D1DeviceContext5 AS GUID = TYPE<GUID>(&h7836D248, &h68CC, &h4DF6, {&hB9, &hE8, &hDE, &h99, &h1B, &hF6, &h2E, &hB7})
DIM SHARED IID_ID2D1Device5 AS GUID = TYPE<GUID>(&hD55BA0A4, &h6405, &h4694, {&hAE, &hF5, &h08, &hEE, &h1A, &h43, &h58, &hB4})
DIM SHARED IID_ID2D1Factory6 AS GUID = TYPE<GUID>(&hF9976F46, &hF642, &h44C1, {&h97, &hCA, &hDA, &h32, &hEA, &h2A, &h26, &h35})
DIM SHARED IID_ID2D1CommandSink5 AS GUID = TYPE<GUID>(&h7047DD26, &hB1E7, &h44A7, {&h95, &h9A, &h83, &h49, &hE2, &h14, &h4F, &hA8})
DIM SHARED IID_ID2D1DeviceContext6 AS GUID = TYPE<GUID>(&h985F7E37, &h4ED0, &h4A19, {&h98, &hA3, &h15, &hB0, &hED, &hFD, &hE3, &h06})
DIM SHARED IID_ID2D1Device6 AS GUID = TYPE<GUID>(&h7BFEF914, &h2D75, &h4BAD, {&hBE, &h87, &hE1, &h8D, &hDB, &h07, &h7B, &h6D})
DIM SHARED IID_ID2D1Factory7 AS GUID = TYPE<GUID>(&hBDC2BDD3, &hB96C, &h4DE6, {&hBD, &hF7, &h99, &hD4, &h74, &h54, &h54, &hDE})
DIM SHARED IID_ID2D1DeviceContext7 AS GUID = TYPE<GUID>(&hEC891CF7, &h9B69, &h4851, {&h9D, &hEF, &h4E, &h09, &h15, &h77, &h1E, &h62})
DIM SHARED IID_ID2D1Device7 AS GUID = TYPE<GUID>(&hF07C8968, &hDD4E, &h4BA6, {&h9C, &hBD, &hEB, &h6D, &h37, &h52, &hDC, &hBB})
DIM SHARED IID_ID2D1Factory8 AS GUID = TYPE<GUID>(&h677C9311, &hF36D, &h4B1F, {&hAE, &h86, &h86, &hD1, &h22, &h3F, &hFD, &h3A})

TYPE ID2D1InkStyle AS ID2D1InkStyle_
TYPE ID2D1Ink AS ID2D1Ink_
TYPE ID2D1GradientMesh AS ID2D1GradientMesh_
TYPE ID2D1ImageSource AS ID2D1ImageSource_
TYPE ID2D1ImageSourceFromWic AS ID2D1ImageSourceFromWic_
TYPE ID2D1TransformedImageSource AS ID2D1TransformedImageSource_
TYPE ID2D1LookupTable3D AS ID2D1LookupTable3D_
TYPE ID2D1DeviceContext2 AS ID2D1DeviceContext2_
TYPE ID2D1Device2 AS ID2D1Device2_
TYPE ID2D1Factory3 AS ID2D1Factory3_
TYPE ID2D1CommandSink2 AS ID2D1CommandSink2_
TYPE ID2D1GdiMetafile1 AS ID2D1GdiMetafile1_
TYPE ID2D1GdiMetafileSink1 AS ID2D1GdiMetafileSink1_
TYPE ID2D1SpriteBatch AS ID2D1SpriteBatch_
TYPE ID2D1DeviceContext3 AS ID2D1DeviceContext3_
TYPE ID2D1Device3 AS ID2D1Device3_
TYPE ID2D1Factory4 AS ID2D1Factory4_
TYPE ID2D1CommandSink3 AS ID2D1CommandSink3_
TYPE ID2D1SvgGlyphStyle AS ID2D1SvgGlyphStyle_
TYPE ID2D1DeviceContext4 AS ID2D1DeviceContext4_
TYPE ID2D1Device4 AS ID2D1Device4_
TYPE ID2D1Factory5 AS ID2D1Factory5_
TYPE ID2D1CommandSink4 AS ID2D1CommandSink4_
TYPE ID2D1ColorContext1 AS ID2D1ColorContext1_
TYPE ID2D1DeviceContext5 AS ID2D1DeviceContext5_
TYPE ID2D1Device5 AS ID2D1Device5_
TYPE ID2D1Factory6 AS ID2D1Factory6_
TYPE ID2D1CommandSink5 AS ID2D1CommandSink5_
TYPE ID2D1DeviceContext6 AS ID2D1DeviceContext6_
TYPE ID2D1Device6 AS ID2D1Device6_
TYPE ID2D1Factory7 AS ID2D1Factory7_
TYPE ID2D1DeviceContext7 AS ID2D1DeviceContext7_
TYPE ID2D1Device7 AS ID2D1Device7_
TYPE ID2D1Factory8 AS ID2D1Factory8_

TYPE ID2D1SvgDocument AS ID2D1SvgDocument_

TYPE IWICBitmapFrameDecode AS IWICBitmapFrameDecode_
TYPE IDWriteFontFace AS IDWriteFontFace_

TYPE D2D1_INK_NIB_SHAPE AS LONG
enum
   D2D1_INK_NIB_SHAPE_ROUND = 0
   D2D1_INK_NIB_SHAPE_SQUARE = 1
   D2D1_INK_NIB_SHAPE_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_ORIENTATION AS LONG
enum
   D2D1_ORIENTATION_DEFAULT = 1
   D2D1_ORIENTATION_FLIP_HORIZONTAL = 2
   D2D1_ORIENTATION_ROTATE_CLOCKWISE180 = 3
   D2D1_ORIENTATION_ROTATE_CLOCKWISE180_FLIP_HORIZONTAL = 4
   D2D1_ORIENTATION_ROTATE_CLOCKWISE90_FLIP_HORIZONTAL = 5
   D2D1_ORIENTATION_ROTATE_CLOCKWISE270 = 6
   D2D1_ORIENTATION_ROTATE_CLOCKWISE270_FLIP_HORIZONTAL = 7
   D2D1_ORIENTATION_ROTATE_CLOCKWISE90 = 8
   D2D1_ORIENTATION_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_IMAGE_SOURCE_LOADING_OPTIONS AS LONG
enum
   D2D1_IMAGE_SOURCE_LOADING_OPTIONS_NONE = 0
   D2D1_IMAGE_SOURCE_LOADING_OPTIONS_RELEASE_SOURCE = 1
   D2D1_IMAGE_SOURCE_LOADING_OPTIONS_CACHE_ON_DEMAND = 2
   D2D1_IMAGE_SOURCE_LOADING_OPTIONS_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS AS LONG
enum
   D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS_NONE = 0
   D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS_LOW_QUALITY_PRIMARY_CONVERSION = 1
   D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_TRANSFORMED_IMAGE_SOURCE_OPTIONS AS LONG
enum
   D2D1_TRANSFORMED_IMAGE_SOURCE_OPTIONS_NONE = 0
   D2D1_TRANSFORMED_IMAGE_SOURCE_OPTIONS_DISABLE_DPI_SCALE = 1
   D2D1_TRANSFORMED_IMAGE_SOURCE_OPTIONS_FORCE_DWORD = &hffffffff
end enum

type D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES
   AS D2D1_ORIENTATION orientation
   AS FLOAT scaleX
   AS FLOAT scaleY
   AS D2D1_INTERPOLATION_MODE interpolationMode
   AS D2D1_TRANSFORMED_IMAGE_SOURCE_OPTIONS options
end type

type D2D1_INK_POINT
   AS FLOAT x
   AS FLOAT y
   AS FLOAT radius
end type

type D2D1_INK_BEZIER_SEGMENT
   AS D2D1_INK_POINT point1
   AS D2D1_INK_POINT point2
   AS D2D1_INK_POINT point3
end type

type D2D1_INK_STYLE_PROPERTIES
   AS D2D1_INK_NIB_SHAPE nibShape
   AS D2D1_MATRIX_3X2_F nibTransform
end type

TYPE D2D1_PATCH_EDGE_MODE AS LONG
enum
   D2D1_PATCH_EDGE_MODE_ALIASED = 0
   D2D1_PATCH_EDGE_MODE_ANTIALIASED = 1
   D2D1_PATCH_EDGE_MODE_ALIASED_INFLATED = 2
   D2D1_PATCH_EDGE_MODE_FORCE_DWORD = &hffffffff
end enum

type D2D1_GRADIENT_MESH_PATCH
   AS D2D1_POINT_2F point00
   AS D2D1_POINT_2F point01
   AS D2D1_POINT_2F point02
   AS D2D1_POINT_2F point03
   AS D2D1_POINT_2F point10
   AS D2D1_POINT_2F point11
   AS D2D1_POINT_2F point12
   AS D2D1_POINT_2F point13
   AS D2D1_POINT_2F point20
   AS D2D1_POINT_2F point21
   AS D2D1_POINT_2F point22
   AS D2D1_POINT_2F point23
   AS D2D1_POINT_2F point30
   AS D2D1_POINT_2F point31
   AS D2D1_POINT_2F point32
   AS D2D1_POINT_2F point33
   AS D2D1_COLOR_F color00
   AS D2D1_COLOR_F color03
   AS D2D1_COLOR_F color30
   AS D2D1_COLOR_F color33
   AS D2D1_PATCH_EDGE_MODE topEdgeMode
   AS D2D1_PATCH_EDGE_MODE leftEdgeMode
   AS D2D1_PATCH_EDGE_MODE bottomEdgeMode
   AS D2D1_PATCH_EDGE_MODE rightEdgeMode
end type

TYPE D2D1_SPRITE_OPTIONS AS LONG
enum
   D2D1_SPRITE_OPTIONS_NONE = 0
   D2D1_SPRITE_OPTIONS_CLAMP_TO_SOURCE_RECTANGLE = 1
   D2D1_SPRITE_OPTIONS_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION AS LONG
enum
   D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION_DEFAULT = 0
   D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION_DISABLE = 1
   D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION_FORCE_DWORD = &hffffffff
end enum

TYPE D2D1_GAMMA1 AS LONG
enum
    D2D1_GAMMA1_G22 = D2D1_GAMMA_2_2
    D2D1_GAMMA1_G10 = D2D1_GAMMA_1_0
    D2D1_GAMMA1_G2084 = 2
    D2D1_GAMMA1_FORCE_DWORD = &hffffffff
end enum

type D2D1_SIMPLE_COLOR_PROFILE
   AS D2D1_POINT_2F redPrimary
   AS D2D1_POINT_2F greenPrimary
   AS D2D1_POINT_2F bluePrimary
   AS D2D1_POINT_2F whitePointXZ
   AS D2D1_GAMMA1 gamma
end type

TYPE D2D1_COLOR_CONTEXT_TYPE AS LONG
enum
   D2D1_COLOR_CONTEXT_TYPE_ICC = 0
   D2D1_COLOR_CONTEXT_TYPE_SIMPLE = 1
   D2D1_COLOR_CONTEXT_TYPE_DXGI = 2
   D2D1_COLOR_CONTEXT_TYPE_FORCE_DWORD = &hffffffff
end enum

' ########################################################################################
' Interface name: ID2D1InkStyle
' IID: {BAE8B344-23FC-4071-8CB5-D05D6F073848}
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1InkStyle_INTERFACE_DEFINED__
#define __ID2D1InkStyle_INTERFACE_DEFINED__

TYPE ID2D1InkStyle_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT SUB SetNibTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE ABSTRACT SUB GetNibTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE ABSTRACT SUB SetNibShape (BYVAL nibShape AS D2D1_INK_NIB_SHAPE)
   DECLARE ABSTRACT FUNCTION GetNibShape () AS D2D1_INK_NIB_SHAPE
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Ink
' IID: {B499923B-7029-478F-A8B3-432C7C5F5312}
' Inherited interface = ID2D1Resource
' Number of methods = 10
' ########################################################################################

#ifndef __ID2D1Ink_INTERFACE_DEFINED__
#define __ID2D1Ink_INTERFACE_DEFINED__

TYPE ID2D1Ink_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT SUB SetStartPoint (BYVAL startPoint AS D2D1_INK_POINT PTR)
'   DECLARE ABSTRACT FUNCTION GetStartPoint () AS D2D1_INK_POINT
   DECLARE ABSTRACT SUB GetStartPoint (BYREF startPoint AS D2D1_INK_POINT)
   DECLARE ABSTRACT FUNCTION AddSegments (BYREF segments AS D2D1_INK_BEZIER_SEGMENT, BYVAL segmentsCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION RemoveSegmentsAtEnd (BYVAL segmentsCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSegments (BYVAL startSegment AS UINT32, BYREF segments AS const D2D1_INK_BEZIER_SEGMENT, BYVAL segmentsCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSegmentAtEnd (BYREF segment AS D2D1_INK_BEZIER_SEGMENT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSegmentCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetSegments (BYVAL startSegment AS UINT32, BYREF segments AS D2D1_INK_BEZIER_SEGMENT, BYVAL segmentsCount AS UINT32) AS HRESULT
   DECLARE ABSTRACT FUNCTION StreamAsGeometry (BYVAL inkStyle AS ID2D1InkStyle PTR, BYREF worldTransform AS D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBounds (BYVAL inkStyle AS ID2D1InkStyle PTR, BYREF worldTransform AS D2D1_MATRIX_3X2_F, BYREF bounds AS D2D1_RECT_F) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GradientMesh
' IID: {F292E401-C050-4CDE-83D7-04962D3B23C2}
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1GradientMesh_INTERFACE_DEFINED__
#define __ID2D1GradientMesh_INTERFACE_DEFINED__

TYPE ID2D1GradientMesh_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION GetPatchCount () AS UINT32
   DECLARE ABSTRACT FUNCTION GetPatches (BYVAL startIndex AS UINT32, BYREF patches AS D2D1_GRADIENT_MESH_PATCH, BYVAL patchesCount AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1ImageSource
' IID: {C9B664E5-74A1-4378-9AC2-EEFC37A3F4D8}
' Inherited interface = ID2D1Image
' ########################################################################################

#ifndef __ID2D1ImageSource_INTERFACE_DEFINED__
#define __ID2D1ImageSource_INTERFACE_DEFINED__

TYPE ID2D1ImageSource_ EXTENDS ID2D1Image
   DECLARE ABSTRACT FUNCTION OfferResources () AS HRESULT
   DECLARE ABSTRACT FUNCTION TryReclaimResources (BYREF resourcesDiscarded AS BOOLEAN) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1ImageSourceFromWic
' IID: {77395441-1C8F-4555-8683-F50DAB0FE792}
' Inherited interface = ID2D1ImageSource
' ########################################################################################

#ifndef __ID2D1ImageSourceFromWic_INTERFACE_DEFINED__
#define __ID2D1ImageSourceFromWic_INTERFACE_DEFINED__

TYPE ID2D1ImageSourceFromWic_ EXTENDS ID2D1ImageSource
   DECLARE ABSTRACT FUNCTION EnsureCached (BYREF rectangleToFill AS D2D1_RECT_U) AS HRESULT
   DECLARE ABSTRACT FUNCTION TrimCache (BYREF rectangleToPreserve AS D2D1_RECT_U) AS HRESULT
   DECLARE ABSTRACT SUB GetSource (BYREF wicBitmapSource AS IWICBitmapSource PTR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1TransformedImageSource
' IID: {7F1F79E5-2796-416C-8F55-700F911445E5}
' Inherited interface = ID2D1Image
' ########################################################################################

#ifndef __ID2D1TransformedImageSource_INTERFACE_DEFINED__
#define __ID2D1TransformedImageSource_INTERFACE_DEFINED__

TYPE ID2D1TransformedImageSource_ EXTENDS ID2D1Image
   DECLARE ABSTRACT SUB GetSource (BYREF imageSource AS ID2D1ImageSource PTR)
   DECLARE ABSTRACT SUB GetProperties (BYREF imageSrcProperties AS D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1LookupTable3D
' IID: {53DD9855-A3B0-4D5B-82E1-26E25C5E5797}
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1LookupTable3D_INTERFACE_DEFINED__
#define __ID2D1LookupTable3D_INTERFACE_DEFINED__

TYPE ID2D1LookupTable3D_ EXTENDS ID2D1Resource
   ' It has not additional methods
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DeviceContext2
' IID: {394EA6A3-0C34-4321-950B-6CA20F0BE6C7}
' Inherited interface = ID2D1DeviceContext1
' Number of methods = 11
' ########################################################################################

#ifndef __ID2D1DeviceContext2_INTERFACE_DEFINED__
#define __ID2D1DeviceContext2_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext2_ EXTENDS ID2D1DeviceContext1
   DECLARE ABSTRACT FUNCTION CreateInk (BYREF startPoint AS D2D1_INK_POINT, BYREF ink AS ID2D1Ink PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateInkStyle (BYREF inkStyleProperties AS D2D1_INK_STYLE_PROPERTIES, BYREF inkStyle AS ID2D1InkStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateGradientMesh (BYREF patches AS D2D1_GRADIENT_MESH_PATCH, BYVAL patchesCount AS UINT32, BYREF gradientMesh AS ID2D1GradientMesh PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateImageSourceFromWic (BYVAL wicBitmapSource AS IWICBitmapSource PTR, BYVAL loadingOptions AS D2D1_IMAGE_SOURCE_LOADING_OPTIONS, BYVAL alphaMode AS D2D1_ALPHA_MODE, BYREF imageSource AS ID2D1ImageSourceFromWic PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateLookupTable3D (BYVAL precision AS D2D1_BUFFER_PRECISION, BYREF extents AS const UINT32, BYVAL data AS BYTE PTR, BYVAL dataCount AS UINT32, BYREF strides AS const UINT32, BYREF lookupTable AS ID2D1LookupTable3D PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateImageSourceFromDxgi (BYREF surfaces AS IDXGISurface PTR, BYVAL surfaceCount AS UINT32, BYVAL colorSpace AS DXGI_COLOR_SPACE_TYPE, BYVAL options AS D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS, BYREF imageSource AS ID2D1ImageSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGradientMeshWorldBounds (BYVAL gradientMesh AS ID2D1GradientMesh PTR, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawInk (BYVAL ink AS ID2D1Ink PTR, BYVAL brush AS ID2D1Brush PTR, BYVAL inkStyle AS ID2D1InkStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGradientMesh (BYVAL gradientMesh AS ID2D1GradientMesh PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGdiMetafile2 (BYVAL gdiMetafile AS ID2D1GdiMetafile PTR, BYREF destinationRectangle AS D2D1_RECT_F, BYREF sourceRectangle AS D2D1_RECT_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateTransformedImageSource (BYVAL imageSource AS ID2D1ImageSource PTR, BYREF imgSrcProperties AS D2D1_TRANSFORMED_IMAGE_SOURCE_PROPERTIES, BYREF transformedImageSource AS ID2D1TransformedImageSource PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device2
' IID: {A44472E1-8DFB-4E60-8492-6E2861C9CA8B}
' Inherited interface = ID2D1Device1
' ########################################################################################

#ifndef __ID2D1Device2_INTERFACE_DEFINED__
#define __ID2D1Device2_INTERFACE_DEFINED__

TYPE ID2D1Device2_ EXTENDS ID2D1Device1
   DECLARE ABSTRACT FUNCTION CreateDeviceContext2 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext2 AS ID2D1DeviceContext2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION FlushDeviceContexts (BYVAL bitmap AS ID2D1Bitmap PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDxgiDevice (BYREF dxgiDevice AS IDXGIDevice PTR) AS HRESULT
END TYPE
    
#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory3
' IID: {0869759F-4F00-413F-B03E-2BDA45404D0F}
' Inherited interface = ID2D1Factory2
' ########################################################################################

#ifndef __ID2D1Factory3_INTERFACE_DEFINED__
#define __ID2D1Factory3_INTERFACE_DEFINED__

TYPE ID2D1Factory3_ EXTENDS ID2D1Factory2
   DECLARE ABSTRACT FUNCTION CreateDevice2 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice2 AS ID2D1Device2 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: ID2D1CommandSink2
' IID: {3BAB440E-417E-47DF-A2E2-BC0BE6A00916}
' Inherited interface = ID2D1CommandSink1
' ########################################################################################

#ifndef __ID2D1CommandSink2_INTERFACE_DEFINED__
#define __ID2D1CommandSink2_INTERFACE_DEFINED__

TYPE ID2D1CommandSink2_ EXTENDS ID2D1CommandSink1
   DECLARE ABSTRACT FUNCTION DrawInk (BYVAL ink AS ID2D1Ink PTR, BYVAL brush AS ID2D1Brush PTR, BYVAL inkStyle AS ID2D1InkStyle PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGradientMesh (BYVAL gradientMesh AS ID2D1GradientMesh PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawGdiMetafile (BYVAL gdiMetafile AS ID2D1GdiMetafile PTR, BYREf destinationRectangle AS D2D1_RECT_F, BYREF sourceRectangle AS D2D1_RECT_F) AS HRESULT
END TYPE
    
#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GdiMetafile1
' IID: {2E69F9E8-DD3F-4BF9-95BA-C04F49D788DF}
' Inherited interface = ID2D1GdiMetafile
' ########################################################################################

#ifndef __ID2D1GdiMetafile1_INTERFACE_DEFINED__
#define __ID2D1GdiMetafile1_INTERFACE_DEFINED__

TYPE ID2D1GdiMetafile1_ EXTENDS ID2D1GdiMetafile
   DECLARE ABSTRACT FUNCTION GetDpi (BYREF dpiX AS FLOAT, BYREF dpiY AS FLOAT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSourceBounds (BYREF bounds AS D2D1_RECT_F) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1GdiMetafileSink1
' IID: {FD0ECB6B-91E6-411E-8655-395E760F91B4}
' Inherited interface = ID2D1GdiMetafileSink
' ########################################################################################

#ifndef __ID2D1GdiMetafileSink1_INTERFACE_DEFINED__
#define __ID2D1GdiMetafileSink1_INTERFACE_DEFINED__

TYPE ID2D1GdiMetafileSink1_ EXTENDS ID2D1GdiMetafileSink
   DECLARE ABSTRACT FUNCTION ProcessRecord1 (BYVAL recordType AS DWORD, BYVAL recordData AS const ANY PTR, BYVAL recordDataSize AS DWORD, BYVAL flags AS UINT32) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1SpriteBatch
' IID: {4DC583BF-3A10-438A-8722-E9765224F1F1}
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1SpriteBatch_INTERFACE_DEFINED__
#define __ID2D1SpriteBatch_INTERFACE_DEFINED__

TYPE ID2D1SpriteBatch_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION AddSprites (BYVAL spriteCount AS UINT32, BYREF destinationRectangles AS const D2D1_RECT_F, _
           BYREF sourceRectangles AS const D2D1_RECT_U, BYREF colors AS const D2D1_COLOR_F, BYREF transforms AS const D2D1_MATRIX_3X2_F, _
           BYVAL destinationRectanglesStride AS UINT32 = sizeof(D2D1_RECT_F), BYVAL sourceRectanglesStride AS UINT32 = sizeof(D2D1_RECT_U), _
           BYVAL colorsStride AS UINT32 = sizeof(D2D1_COLOR_F), BYVAL transformsStride AS UINT32 = sizeof(D2D1_MATRIX_3X2_F)) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSprites (BYVAL startIndex AS UINT32, BYVAL spriteCount AS UINT32, _
           BYREF destinationRectangles AS const D2D1_RECT_F, BYREF sourceRectangles AS const D2D1_RECT_U, _
           BYREF colors AS D2D1_COLOR_F, BYREF transforms AS D2D1_MATRIX_3X2_F, _
           BYVAL destinationRectanglesStride AS UINT32 = sizeof(D2D1_RECT_U), BYVAL sourceRectanglesStride AS UINT32 = sizeof(D2D1_RECT_U), _
           BYVAL colorsStride AS UINT32 = sizeof(D2D1_COLOR_F), BYVAL transformsStride AS UINT32 = sizeof(D2D1_MATRIX_3X2_F) ) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSprites (BYVAL startIndex AS UINT32, BYVAL spriteCount AS UINT32, _
           BYREF destinationRectangles AS D2D1_RECT_F, BYREF sourceRectangles AS D2D1_RECT_U, _
           BYREF colors AS D2D1_COLOR_F, BYREF transforms AS D2D1_MATRIX_3X2_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSpriteCount () AS UINT32
   DECLARE ABSTRACT SUB Clear
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' ** Interface name: ID2D1DeviceContext3
' IID: {235A7496-8351-414C-BCD4-6672AB2D8E00}
' Inherited interface = ID2D1DeviceContext2
' ########################################################################################

#ifndef __ID2D1DeviceContext3_INTERFACE_DEFINED__
#define __ID2D1DeviceContext3_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext3_ EXTENDS ID2D1DeviceContext2
   DECLARE ABSTRACT FUNCTION CreateSpriteBatch (BYREF spriteBatch AS ID2D1SpriteBatch PTR) AS HRESULT
   DECLARE ABSTRACT SUB DrawSpriteBatch (BYVAL spriteBatch AS ID2D1SpriteBatch PTR, BYVAL startIndex AS UINT32, _
           BYVAL spriteCount AS UINT32, BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
           BYVAL spriteOptions AS D2D1_SPRITE_OPTIONS = D2D1_SPRITE_OPTIONS_NONE)
END TYPE
    
#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device3
' IID: {852F2087-802C-4037-AB60-FF2E7EE6FC01}
' Inherited interface = ID2D1Device2
' ########################################################################################

#ifndef __ID2D1Device3_INTERFACE_DEFINED__
#define __ID2D1Device3_INTERFACE_DEFINED__

TYPE ID2D1Device3_ EXTENDS ID2D1Device2
   DECLARE ABSTRACT FUNCTION CreateDeviceContext3 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext3 AS ID2D1DeviceContext3 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory4
' IID: {BD4EC2D2-0662-4BEE-BA8E-6F29F032E096}
' Inherited interface = ID2D1Factory3
' ########################################################################################

#ifndef __ID2D1Factory4_INTERFACE_DEFINED__
#define __ID2D1Factory4_INTERFACE_DEFINED__

TYPE ID2D1Factory4_ EXTENDS ID2D1Factory3
   DECLARE ABSTRACT FUNCTION CreateDevice3 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice3 AS ID2D1Device3 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1CommandSink3
' IID: {18079135-4CF3-4868-BC8E-06067E6D242D}
' Inherited interface = ID2D1CommandSink2
' ########################################################################################

#ifndef __ID2D1CommandSink3_INTERFACE_DEFINED__
#define __ID2D1CommandSink3_INTERFACE_DEFINED__

TYPE ID2D1CommandSink3_ EXTENDS ID2D1CommandSink2
   DECLARE ABSTRACT FUNCTION DrawSpriteBatch (BYVAL spriteBatch AS ID2D1SpriteBatch PTR, BYVAL startIndex AS UINT32, _
           BYVAL spriteCount AS UINT32, BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE, _
           BYVAL spriteOptions AS D2D1_SPRITE_OPTIONS) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1SvgGlyphStyle
' IID: {AF671749-D241-4DB8-8E41-DCC2E5C1A438}
' Inherited interface = ID2D1Resource
' ########################################################################################

#ifndef __ID2D1SvgGlyphStyle_INTERFACE_DEFINED__
#define __ID2D1SvgGlyphStyle_INTERFACE_DEFINED__

TYPE ID2D1SvgGlyphStyle_ EXTENDS ID2D1Resource
   DECLARE ABSTRACT FUNCTION SetFill (BYVAL brush AS ID2D1Brush PTR) AS HRESULT
   DECLARE ABSTRACT SUB GetFill (BYREF brush AS ID2D1Brush PTR)
   DECLARE ABSTRACT FUNCTION SetStroke (BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, _
           BYVAL dashes AS FLOAT PTR = NULL, BYVAL dashesCount AS UINT32, BYVAL dashOffset AS FLOAT = 1.0!) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetStrokeDashesCount () AS UINT32
   DECLARE ABSTRACT SUB GetStroke (BYREF brush AS ID2D1Brush PTR, BYREF strokeWidth AS FLOAT PTR = NULL, _
           BYREF dashes AS FLOAT = NULL, BYVAL dashesCount AS UINT32, BYREF dashOffset AS FLOAT = NULL)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DeviceContext4
' IID: {8C427831-3D90-4476-B647-C4FAE349E4DB}
' Inherited interface = ID2D1DeviceContext3
' ########################################################################################

#ifndef __ID2D1DeviceContext4_INTERFACE_DEFINED__
#define __ID2D1DeviceContext4_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext4_ EXTENDS ID2D1DeviceContext3
   DECLARE ABSTRACT FUNCTION CreateSvgGlyphStyle (BYREF svgGlyphStyle AS ID2D1SvgGlyphStyle PTR) AS HRESULT
   DECLARE ABSTRACT SUB DrawText2 (BYREF wszString AS const WSTRING, BYVAL stringLength AS UINT32, _
           BYVAL textFormat AS IDWriteTextFormat PTR, BYREF layoutRect AS D2D1_RECT_F, BYVAL defaultFillBrush AS ID2D1Brush PTR, _
           BYVAL svgGlyphStyle AS ID2D1SvgGlyphStyle PTR, BYVAL colorPaletteIndex AS UINT32 = 0, _
           BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE ABSTRACT SUB DrawTextLayout2 (BYVAL origin AS D2D1_POINT_2F, BYVAL textLayout AS IDWriteTextLayout PTR, _
           BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL svgGlyphStyle AS ID2D1SvgGlyphStyle PTR, BYVAL colorPaletteIndex AS UINT32, _
           BYVAL pptions AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT)
   DECLARE ABSTRACT SUB DrawColorBitmapGlyphRun (BYVAL glyphImageFormat AS DWRITE_GLYPH_IMAGE_FORMATS, BYVAL baselineOrigin AS D2D1_POINT_2F, _
           BYREF glyphRun AS DWRITE_GLYPH_RUN, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL, _
           BYVAL bitmapSnapOption AS D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION = D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION_DEFAULT)
   DECLARE ABSTRACT FUNCTION DrawSvgGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS DWRITE_GLYPH_RUN, _
           BYVAL defaultFillBrush AS ID2D1Brush PTR = NULL, BYVAL svgGlyphStyle AS ID2D1SvgGlyphStyle PTR = NULL, _
           BYVAL colorPaletteIndex AS UINT32 = 0, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorBitmapGlyphImage (BYVAL glyphImageFormat AS DWRITE_GLYPH_IMAGE_FORMATS, _
           BYVAL glyphOrigin AS D2D1_POINT_2F, BYVAL fontFace AS IDWriteFontFace PTR, BYVAL fontEmSize AS FLOAT, _
           BYVAL glyphIndex AS UINT16, BYVAL isSideways AS BOOLEAN, BYREF worldTransform AS D2D1_MATRIX_3X2_F, _
           BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT, BYREF glyphTransform AS D2D1_MATRIX_3X2_F, _
           BYREF glyphImage AS ID2D1Image PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSvgGlyphImage (BYVAL glyphOrigin AS D2D1_POINT_2F, BYVAL fontFace AS IDWriteFontFace PTR, _
           BYVAL fontEmSize AS FLOAT, BYVAL glyphIndex AS UINT16, BYVAL isSideways AS BOOLEAN, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL svgGlyphStyle AS ID2D1SvgGlyphStyle PTR, BYVAL colorPaletteIndex AS UINT32, _
           BYREF glyphTransform AS D2D1_MATRIX_3X2_F, BYREF glyphImage AS ID2D1CommandList PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device4
' IID: {D7BDB159-5683-4A46-BC9C-72DC720B858B}
' Inherited interface = ID2D1Device3
' ########################################################################################

#ifndef __ID2D1Device4_INTERFACE_DEFINED__
#define __ID2D1Device4_INTERFACE_DEFINED__

TYPE ID2D1Device4_ EXTENDS ID2D1Device3
   DECLARE ABSTRACT FUNCTION CreateDeviceContext4 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext4 AS ID2D1DeviceContext4 PTR) AS HRESULT
   DECLARE ABSTRACT SUB SetMaximumColorGlyphCacheMemory (BYVAL maximumInBytes AS UINT64)
   DECLARE ABSTRACT FUNCTION GetMaximumColorGlyphCacheMemory () AS UINT64
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory5
' IID: {C4349994-838E-4B0F-8CAB-44997D9EEACC}
' Inherited interface = ID2D1Factory4
' ########################################################################################

#ifndef __ID2D1Factory5_INTERFACE_DEFINED__
#define __ID2D1Factory5_INTERFACE_DEFINED__

TYPE ID2D1Factory5_ EXTENDS ID2D1Factory4
   DECLARE ABSTRACT FUNCTION CreateDevice4 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice4 AS ID2D1Device4 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1CommandSink4
' IID: {C78A6519-40D6-4218-B2DE-BEEEB744BB3E}
' Inherited interface = ID2D1CommandSink3
' ########################################################################################

#ifndef __ID2D1CommandSink4_INTERFACE_DEFINED__
#define __ID2D1CommandSink4_INTERFACE_DEFINED__

TYPE ID2D1CommandSink4_ EXTENDS ID2D1CommandSink3
   DECLARE ABSTRACT FUNCTION SetPrimitiveBlend2 (BYVAL primitiveBlend AS D2D1_PRIMITIVE_BLEND) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1ColorContext1
' IID: {1AB42875-C57F-4BE9-BD85-9CD78D6F55EE}
' Inherited interface = ID2D1ColorContext
' ########################################################################################

#ifndef __ID2D1ColorContext1_INTERFACE_DEFINED__
#define __ID2D1ColorContext1_INTERFACE_DEFINED__

TYPE ID2D1ColorContext1_ EXTENDS ID2D1ColorContext
   DECLARE ABSTRACT FUNCTION GetColorContextType () AS D2D1_COLOR_CONTEXT_TYPE
   DECLARE ABSTRACT FUNCTION GetDXGIColorSpace () AS DXGI_COLOR_SPACE_TYPE
   DECLARE ABSTRACT FUNCTION GetSimpleColorProfile (BYREF simpleProfile AS D2D1_SIMPLE_COLOR_PROFILE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DeviceContext5
' IID: {7836D248-68CC-4DF6-B9E8-DE991BF62EB7}
' Inherited interface = ID2D1DeviceContext4
' ########################################################################################

#ifndef __ID2D1DeviceContext5_INTERFACE_DEFINED__
#define __ID2D1DeviceContext5_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext5_ EXTENDS ID2D1DeviceContext4
   DECLARE ABSTRACT FUNCTION CreateSvgDocument (BYVAL inputXmlStream AS IStream PTR, BYVAL viewportSize AS D2D1_SIZE_F, BYREF svgDocument AS ID2D1SvgDocument PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DrawSvgDocument (BYVAL svgDocument AS ID2D1SvgDocument PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorContextFromDxgiColorSpace (BYVAL colorSpace AS DXGI_COLOR_SPACE_TYPE, BYREF colorContext AS ID2D1ColorContext1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateColorContextFromSimpleColorProfile (BYREF simpleProfile AS D2D1_SIMPLE_COLOR_PROFILE, BYREF colorContext AS ID2D1ColorContext1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device5
' IID: {D55BA0A4-6405-4694-AEF5-08EE1A4358B4}
' Inherited interface = ID2D1Device4
' ########################################################################################

#ifndef __ID2D1Device5_INTERFACE_DEFINED__
#define __ID2D1Device5_INTERFACE_DEFINED__

TYPE ID2D1Device5_ EXTENDS ID2D1Device4
   DECLARE ABSTRACT FUNCTION CreateDeviceContext5 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext5 AS ID2D1DeviceContext5 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory6
' IID: {F9976F46-F642-44C1-97CA-DA32EA2A2635}
' Inherited interface = ID2D1Factory5
' ########################################################################################

#ifndef __ID2D1Factory6_INTERFACE_DEFINED__
#define __ID2D1Factory6_INTERFACE_DEFINED__

TYPE ID2D1Factory6_ EXTENDS ID2D1Factory5
   DECLARE ABSTRACT FUNCTION CreateDevice5 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice5 AS ID2D1Device5 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1CommandSink5
' IID: {7047DD26-B1E7-44A7-959A-8349E2144FA8}
' Inherited interface = ID2D1CommandSink4
' ########################################################################################

TYPE D2D1_BLEND_MODE AS LONG
enum
   D2D1_BLEND_MODE_MULTIPLY = 0,
   D2D1_BLEND_MODE_SCREEN = 1,
   D2D1_BLEND_MODE_DARKEN = 2,
   D2D1_BLEND_MODE_LIGHTEN = 3,
   D2D1_BLEND_MODE_DISSOLVE = 4,
   D2D1_BLEND_MODE_COLOR_BURN = 5,
   D2D1_BLEND_MODE_LINEAR_BURN = 6,
   D2D1_BLEND_MODE_DARKER_COLOR = 7,
   D2D1_BLEND_MODE_LIGHTER_COLOR = 8,
   D2D1_BLEND_MODE_COLOR_DODGE = 9,
   D2D1_BLEND_MODE_LINEAR_DODGE = 10,
   D2D1_BLEND_MODE_OVERLAY = 11,
   D2D1_BLEND_MODE_SOFT_LIGHT = 12,
   D2D1_BLEND_MODE_HARD_LIGHT = 13,
   D2D1_BLEND_MODE_VIVID_LIGHT = 14,
   D2D1_BLEND_MODE_LINEAR_LIGHT = 15,
   D2D1_BLEND_MODE_PIN_LIGHT = 16,
   D2D1_BLEND_MODE_HARD_MIX = 17,
   D2D1_BLEND_MODE_DIFFERENCE = 18,
   D2D1_BLEND_MODE_EXCLUSION = 19,
   D2D1_BLEND_MODE_HUE = 20,
   D2D1_BLEND_MODE_SATURATION = 21,
   D2D1_BLEND_MODE_COLOR = 22,
   D2D1_BLEND_MODE_LUMINOSITY = 23,
   D2D1_BLEND_MODE_SUBTRACT = 24,
   D2D1_BLEND_MODE_DIVISION = 25,
   D2D1_BLEND_MODE_FORCE_DWORD = &hffffffff
end enum

#ifndef __ID2D1CommandSink5_INTERFACE_DEFINED__
#define __ID2D1CommandSink5_INTERFACE_DEFINED__

TYPE ID2D1CommandSink5_ EXTENDS ID2D1CommandSink4
   DECLARE ABSTRACT FUNCTION BlendImage (BYVAL image AS ID2D1Image PTR, BYVAL blendMode AS D2D1_BLEND_MODE, _
           BYREF targetOffset AS D2D1_POINT_2F, BYREF imageRectangle AS D2D1_RECT_F, BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1DeviceContext6
' IID: {985F7E37-4ED0-4A19-98A3-15B0EDFDE306}
' Inherited interface = ID2D1DeviceContext5
' ########################################################################################

#ifndef __ID2D1DeviceContext6_INTERFACE_DEFINED__
#define __ID2D1DeviceContext6_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext6_ EXTENDS ID2D1DeviceContext5
   DECLARE ABSTRACT SUB BlendImage (BYVAL image AS ID2D1Image PTR, BYVAL blendMode AS D2D1_BLEND_MODE, _
           BYREF targetOffset AS D2D1_POINT_2F, BYREF imageRectangle AS D2D1_RECT_F, _
           BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE = D2D1_INTERPOLATION_MODE_LINEAR)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device6
' IID: {7BFEF914-2D75-4BAD-BE87-E18DDB077B6D}
' Inherited interface = ID2D1Device5
' ########################################################################################

#ifndef __ID2D1Device6_INTERFACE_DEFINED__
#define __ID2D1Device6_INTERFACE_DEFINED__

TYPE ID2D1Device6_ EXTENDS ID2D1Device5
   DECLARE ABSTRACT FUNCTION CreateDeviceContext6 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext6 AS ID2D1DeviceContext6 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory7
' IID: {BDC2BDD3-B96C-4DE6-BDF7-99D4745454DE}
' Inherited interface = ID2D1Factory6
' ########################################################################################

#ifndef __ID2D1Factory7_INTERFACE_DEFINED__
#define __ID2D1Factory7_INTERFACE_DEFINED__

TYPE ID2D1Factory7_ EXTENDS ID2D1Factory6
   DECLARE ABSTRACT FUNCTION CreateDevice6 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice6 AS ID2D1Device6 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

type DWRITE_PAINT_FEATURE_LEVEL AS LONG
enum
   DWRITE_PAINT_FEATURE_LEVEL_NONE = 0
   DWRITE_PAINT_FEATURE_LEVEL_COLR_V0 = 1
   DWRITE_PAINT_FEATURE_LEVEL_COLR_V1 = 2
end enum

' ########################################################################################
' * Interface name: ID2D1DeviceContext7
' IID: {EC891CF7-9B69-4851-9DEF-4E0915771E62}
' Inherited interface = ID2D1DeviceContext6
' ########################################################################################

#ifndef __ID2D1DeviceContext7_INTERFACE_DEFINED__
#define __ID2D1DeviceContext7_INTERFACE_DEFINED__

TYPE ID2D1DeviceContext7_ EXTENDS ID2D1DeviceContext6
   DECLARE ABSTRACT FUNCTION GetPaintFeatureLevel () AS DWRITE_PAINT_FEATURE_LEVEL
   DECLARE ABSTRACT SUB DrawPaintGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
           BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL colorPaletteIndex AS UINT32 = 0, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE ABSTRACT SUB DrawGlyphRunWithColorSupport (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
           BYREF glyphRunDescription AS const DWRITE_GLYPH_RUN_DESCRIPTION, BYVAL foregroundBrush AS ID2D1Brush PTR, _
           BYVAL svgGlyphStyle AS ID2D1SvgGlyphStyle PTR, BYVAL colorPaletteIndex AS UINT32 = 0, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL, _
           BYVAL bitmapSnapOption AS D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION = D2D1_COLOR_BITMAP_GLYPH_SNAP_OPTION_DEFAULT)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: ID2D1Device7
' IID: {F07C8968-DD4E-4BA6-9CBD-EB6D3752DCBB}
' Inherited interface = ID2D1Device6
' ########################################################################################

#ifndef __ID2D1Device7_INTERFACE_DEFINED__
#define __ID2D1Device7_INTERFACE_DEFINED__

TYPE ID2D1Device7_ EXTENDS ID2D1Device6
   DECLARE ABSTRACT FUNCTION CreateDeviceContext7 (BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS, BYREF deviceContext AS ID2D1DeviceContext7 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' * Interface name: ID2D1Factory8
' IID: {677C9311-F36D-4B1F-AE86-86D1223FFD3A}
' Inherited interface = ID2D1Factory7
' ########################################################################################

#ifndef __ID2D1Factory8_INTERFACE_DEFINED__
#define __ID2D1Factory8_INTERFACE_DEFINED__

TYPE ID2D1Factory8_ EXTENDS ID2D1Factory7
   DECLARE ABSTRACT FUNCTION CreateDevice7 (BYVAL dxgiDevice AS IDXGIDevice PTR, BYREF d2dDevice7 AS ID2D1Device7 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ========================================================================================
' Returns the interior points for a gradient mesh patch based on the points defining a Coons patch.
' Note This function is called by the GradientMeshPatchFromCoonsPatch function and is not intended to be used directly.
' ========================================================================================
DECLARE SUB D2D1GetGradientMeshInteriorPointsFromCoonsPatch LIB "d2d1" ALIAS "D2D1GetGradientMeshInteriorPointsFromCoonsPatch" ( _
   BYVAL pPoint0 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint1 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint2 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint3 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint4 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint5 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint6 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint7 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint8 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint9 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint10 AS D2D1_POINT_2F PTR, _
   BYVAL pPoint11 AS D2D1_POINT_2F PTR, _
   BYVAL pTensorPoint11 AS D2D1_POINT_2F PTR, _
   BYVAL pTensorPoint12 AS D2D1_POINT_2F PTR, _
   BYVAL pTensorPoint21 AS D2D1_POINT_2F PTR, _
   BYVAL pTensorPoint22 AS D2D1_POINT_2F PTR)
' ========================================================================================

' // Include files
#include once "AfxNova/AfxWinCodec.bi"
#include once "AfxNova/AfxDWrite.bi"
#include once "AfxNova/AfxDxgi.bi"
#include once "AfxNova/AfxD2D1helper.bi"
#include once "AfxNova/AfxD2D1svg.bi"
#include once "AfxNova/AfxD2d1Effects.bi"
