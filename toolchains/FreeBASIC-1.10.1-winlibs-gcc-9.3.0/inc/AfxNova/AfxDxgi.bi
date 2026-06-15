#pragma once

#include once "windows.bi"
#include once "win/ole2.bi"

' /* Headers for imported files */

#include once "win/oaidl.bi"
#include once "win/ocidl.bi"
#include once "AfxNova/AfxD2D1.bi"

DIM SHARED IID_IDXGIAdapter AS GUID = (&h2411E7E1, &h12AC, &h4CCF, {&hBD, &h14, &h97, &h98, &hE8, &h53, &h4D, &hC0})
DIM SHARED IID_IDXGIAdapter1 AS GUID = (&h29038F61, &h3839, &h4626, {&h91, &hFD, &h08, &h68, &h79, &h01, &h1A, &h05})
DIM SHARED IID_IDXGIAdapter2 AS GUID = (&h0AA1AE0A, &hFA0E, &h4B84, {&h86, &h44, &hE0, &h5F, &hF8, &hE5, &hAC, &hB5})
DIM SHARED IID_IDXGIAdapter3 AS GUID = (&h645967A4, &h1392, &h4310, {&hA7, &h98, &h80, &h53, &hCE, &h3E, &h93, &hFD})
DIM SHARED IID_IDXGIAdapter4 AS GUID = (&h3C8D99D1, &h4FBF, &h4181, {&hA8, &h2C, &hAF, &h66, &hBF, &h7B, &hD2, &h4E})
DIM SHARED IID_IDXGIDecodeSwapChain AS GUID = (&h2633066B, &h4514, &h4C7A, {&h8F, &hD8, &h12, &hEA, &h98, &h05, &h9D, &h18})
DIM SHARED IID_IDXGIDevice AS GUID = (&h54EC77FA, &h1377, &h44E6, {&h8C, &h32, &h88, &hFD, &h5F, &h44, &hC8, &h4C})
DIM SHARED IID_IDXGIDevice1 AS GUID = (&h77DB970F, &h6276, &h48BA, {&hBA, &h28, &h07, &h01, &h43, &hB4, &h39, &h2C})
DIM SHARED IID_IDXGIDevice2 AS GUID = (&h05008617, &hFBFD, &h4051, {&hA7, &h90, &h14, &h48, &h84, &hB4, &hF6, &hA9})
DIM SHARED IID_IDXGIDevice3 AS GUID = (&h6007896C, &h3244, &h4AFD, {&hBF, &h18, &hA6, &hD3, &hBE, &hDA, &h50, &h23})
DIM SHARED IID_IDXGIDevice4 AS GUID = (&h95B4F95F, &hD8DA, &h4CA4, {&h9E, &hE6, &h3B, &h76, &hD5, &h96, &h8A, &h10})
DIM SHARED IID_IDXGIDeviceSubObject AS GUID = (&h3D3E0379, &hF9DE, &h4D58, {&hBB, &h6C, &h18, &hD6, &h29, &h92, &hF1, &hA6})
DIM SHARED IID_IDXGIDisplayControl AS GUID = (&hEA9DBF1A, &hC88E, &h4486, {&h85, &h4A, &h98, &hAA, &h01, &h38, &hF3, &h0C})
DIM SHARED IID_IDXGIFactory AS GUID = (&h7B7166EC, &h21C7, &h44AE, {&hB2, &h1A, &hC9, &hAE, &h32, &h1A, &hE3, &h69})
DIM SHARED IID_IDXGIFactory1 AS GUID = (&h770AAE78, &hF26F, &h4DBA, {&hA8, &h29, &h25, &h3C, &h83, &hD1, &hB3, &h87})
DIM SHARED IID_IDXGIFactory2 AS GUID = (&h50C83A1C, &hE072, &h4C48, {&h87, &hB0, &h36, &h30, &hFA, &h36, &hA6, &hD0})
DIM SHARED IID_IDXGIFactory3 AS GUID = (&h25483823, &hCD46, &h4C7D, {&h86, &hCA, &h47, &hAA, &h95, &hB8, &h37, &hBD})
DIM SHARED IID_IDXGIFactory4 AS GUID = (&h1BC6EA02, &hEF36, &h464F, {&hBF, &h0C, &h21, &hCA, &h39, &hE5, &h16, &h8A})
DIM SHARED IID_IDXGIFactory5 AS GUID = (&h7632E1F5, &hEE65, &h4DCA, {&h87, &hFD, &h84, &hCD, &h75, &hF8, &h83, &h8D})
DIM SHARED IID_IDXGIFactory6 AS GUID = (&hC1B6694F, &hFF09, &h44A9, {&hB0, &h3C, &h77, &h90, &h0A, &h0A, &h1D, &h17})
DIM SHARED IID_IDXGIFactory7 AS GUID = (&hA4966EED, &h76DB, &h44DA, {&hB4, &hC1, &hEE, &h9A, &h74, &hFB, &h20, &hA8})
DIM SHARED IID_IDXGIFactoryMedia AS GUID = (&h41E7D1F2, &hA591, &h4F7B, {&hA2, &hE5, &hFA, &h9C, &h84, &h3E, &h1C, &h12})
DIM SHARED IID_IDXGIKeyedMutex AS GUID = (&h9D8E1289, &hD7B3, &h465F, {&h81, &h26, &h25, &h0E, &h34, &h9A, &hF8, &h5D})
DIM SHARED IID_IDXGIObject AS GUID = (&hAEC22FB8, &h76F3, &h4639, {&h9B, &hE0, &h28, &hEB, &h43, &hA6, &h7A, &h2E})
DIM SHARED IID_IDXGIOutput AS GUID = (&hAE02EEDB, &hC735, &h4690, {&h8D, &h52, &h5A, &h8D, &hC2, &h02, &h13, &hAA})
DIM SHARED IID_IDXGIOutput1 AS GUID = (&h00CDDEA8, &h939B, &h4B83, {&hA3, &h40, &hA6, &h85, &h22, &h66, &h66, &hCC})
DIM SHARED IID_IDXGIOutput2 AS GUID = (&h595E39D1, &h2724, &h4663, {&h99, &hB1, &hDA, &h96, &h9D, &hE2, &h83, &h64})
DIM SHARED IID_IDXGIOutput3 AS GUID = (&h8A6BB301, &h7E7E, &h41F4, {&hA8, &hE0, &h5B, &h32, &hF7, &hF9, &h9B, &h18})
DIM SHARED IID_IDXGIOutput4 AS GUID = (&hDC7DCA35, &h2196, &h414D, {&h9F, &h53, &h61, &h78, &h84, &h03, &h2A, &h60})
DIM SHARED IID_IDXGIOutput5 AS GUID = (&h80A07424, &hAB52, &h42EB, {&h83, &h3C, &h0C, &h42, &hFD, &h28, &h2D, &h98})
DIM SHARED IID_IDXGIOutput6 AS GUID = (&h068346E8, &hAAEC, &h4B84, {&hAD, &hD7, &h13, &h7F, &h51, &h3F, &h77, &hA1})
DIM SHARED IID_IDXGIOutputDuplication AS GUID = (&h191CFAC3, &hA341, &h470D, {&hB2, &h6E, &hA8, &h64, &hF4, &h28, &h31, &h9C})
DIM SHARED IID_IDXGIResource AS GUID = (&h035F3AB4, &h482E, &h4E50, {&hB4, &h1F, &h8A, &h7F, &h8B, &hD8, &h96, &h0B})
DIM SHARED IID_IDXGIResource1 AS GUID = (&h30961379, &h4609, &h4A41, {&h99, &h8E, &h54, &hFE, &h56, &h7E, &hE0, &hC1})
DIM SHARED IID_IDXGISurface AS GUID = (&hCAFCB56C, &h6AC3, &h4889, {&hBF, &h47, &h9E, &h23, &hBB, &hD2, &h60, &hEC})
DIM SHARED IID_IDXGISurface1 AS GUID = (&h4AE63092, &h6327, &h4C1B, {&h80, &hAE, &hBF, &hE1, &h2E, &hA3, &h2B, &h86})
DIM SHARED IID_IDXGISurface2 AS GUID = (&hABA496DD, &hB617, &h4CB8, {&hA8, &h66, &hBC, &h44, &hD7, &hEB, &h1F, &hA2})
DIM SHARED IID_IDXGISwapChain AS GUID = (&h310D36A0, &hD2E7, &h4C0A, {&hAA, &h04, &h6A, &h9D, &h23, &hB8, &h88, &h6A})
DIM SHARED IID_IDXGISwapChain1 AS GUID = (&h790A45F7, &h0D42, &h4876, {&h98, &h3A, &h0A, &h55, &hCF, &hE6, &hF4, &hAA})
DIM SHARED IID_IDXGISwapChain2 AS GUID = (&hA8BE2AC4, &h199F, &h4946, {&hB3, &h31, &h79, &h59, &h9F, &hB9, &h8D, &hE7})
DIM SHARED IID_IDXGISwapChain3 AS GUID = (&h94D99BDB, &hF1F8, &h4AB0, {&hB2, &h36, &h7D, &hA0, &h17, &h0E, &hDA, &hB1})
DIM SHARED IID_IDXGISwapChain4 AS GUID = (&h3D585D5A, &hBD4A, &h489E, {&hB1, &hF4, &h3D, &hBC, &hB6, &h45, &h2F, &hFB})
DIM SHARED IID_IDXGISwapChainMedia AS GUID = (&hDD95B90B, &hF05F, &h4F6A, {&hBD, &h65, &h25, &hBF, &hB2, &h64, &hBD, &h84})

#ifndef _FACDXGI
#define _FACDXGI    &h87a
#endif

#ifndef MAKE_DXGI_STATUS
#define MAKE_DXGI_STATUS(x)                         MAKE_HRESULT(0, _FACDXGI, x)
#endif
#ifndef MAKE_DXGI_HRESULT
#define MAKE_DXGI_HRESULT(code) MAKE_HRESULT(1, _FACDXGI, code)
#endif

'#if 0
'typedef HANDLE HMONITOR;
'typedef struct _LUID {
'    DWORD LowPart;
'    LONG HighPart;
'} LUID;
'typedef struct _LUID *PLUID;
'#endif

#ifndef DXGI_CPU_ACCESS_NONE
#define DXGI_CPU_ACCESS_NONE       =  0
#endif
#ifndef DXGI_CPU_ACCESS_DYNAMIC
#define DXGI_CPU_ACCESS_DYNAMIC    = 1
#endif
#ifndef DXGI_CPU_ACCESS_READ_WRITE
#define DXGI_CPU_ACCESS_READ_WRITE = 2 
#endif
#ifndef DXGI_CPU_ACCESS_SCRATCH
#define DXGI_CPU_ACCESS_SCRATCH    = 3
#endif
#ifndef DXGI_CPU_ACCESS_FIELD
#define DXGI_CPU_ACCESS_FIELD      = 15
#endif

TYPE DXGI_USAGE AS UINT
CONST DXGI_USAGE_SHADER_INPUT = &h10
CONST DXGI_USAGE_RENDER_TARGET_OUTPUT = &h20
CONST DXGI_USAGE_BACK_BUFFER = &h40
CONST DXGI_USAGE_SHARED = &h80
CONST DXGI_USAGE_READ_ONLY = &h100
CONST DXGI_USAGE_DISCARD_ON_PRESENT = &h200
CONST DXGI_USAGE_UNORDERED_ACCESS = &h400
CONST DXGI_ENUM_MODES_INTERLACED = 1
CONST DXGI_ENUM_MODES_SCALING = 2
CONST DXGI_RESOURCE_PRIORITY_MINIMUM = &h28000000
CONST DXGI_RESOURCE_PRIORITY_LOW = &h50000000
CONST DXGI_RESOURCE_PRIORITY_NORMAL = &h78000000
CONST DXGI_RESOURCE_PRIORITY_HIGH = &hA0000000
CONST DXGI_RESOURCE_PRIORITY_MAXIMUM = &hC8000000
CONST DXGI_MAP_READ = &h1
CONST DXGI_MAP_WRITE = &h2
CONST DXGI_MAP_DISCARD = &h4

TYPE DXGI_SWAP_EFFECT AS LONG
enum
   DXGI_SWAP_EFFECT_DISCARD = 0
   DXGI_SWAP_EFFECT_SEQUENTIAL = 1
   DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3
   DXGI_SWAP_EFFECT_FLIP_DISCARD = 4
end enum

TYPE DXGI_RESIDENCY AS LONG
enum
   DXGI_RESIDENCY_FULLY_RESIDENT = 1
   DXGI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY = 2
   DXGI_RESIDENCY_EVICTED_TO_DISK = 3
end enum

type DXGI_SURFACE_DESC
   AS UINT Width
   AS UINT Height
   AS DXGI_FORMAT Format
   AS DXGI_SAMPLE_DESC SampleDesc
end type

type DXGI_MAPPED_RECT
   AS INT_ Pitch
   AS BYTE PTR pBits
end type

type DXGI_OUTPUT_DESC
   DeviceName AS WSTRING * 32
   AS RECT DesktopCoordinates
   AS BOOL AttachedToDesktop
   AS DXGI_MODE_ROTATION Rotation
   AS HMONITOR Monitor
end type

type DXGI_FRAME_STATISTICS
   AS UINT PresentCount
   AS UINT PresentRefreshCount
   AS UINT SyncRefreshCount
   AS LARGE_INTEGER SyncQPCTime
   AS LARGE_INTEGER SyncGPUTime
end type

type DXGI_ADAPTER_DESC
   AS WSTRING * 128 Description
   AS UINT VendorId
   AS UINT DeviceId
   AS UINT SubSysId
   AS UINT Revision
   AS SIZE_T DedicatedVideoMemory
   AS SIZE_T DedicatedSystemMemory
   AS SIZE_T SharedSystemMemory
   AS LUID AdapterLuid
end type

TYPE DXGI_SWAP_CHAIN_FLAG AS LONG
enum
   DXGI_SWAP_CHAIN_FLAG_NONPREROTATED = &h1
   DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH = &h2
   DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE = &h4
   DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT = &h8
   DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER = &h10
   DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY = &h20
   DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT = &h40
   DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER = &h80
   DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO = &h100
   DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO = &h200
   DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED = &h400
   DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING = &h800
   DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = &h1000
end enum

type DXGI_SWAP_CHAIN_DESC
   AS DXGI_MODE_DESC BufferDesc
   AS DXGI_SAMPLE_DESC SampleDesc
   AS DXGI_USAGE BufferUsage
   AS UINT BufferCount
   AS HWND OutputWindow
   AS BOOL Windowed
   AS DXGI_SWAP_EFFECT SwapEffect
   AS UINT Flags
end type

type DXGI_SHARED_RESOURCE
   AS HANDLE Handle
end type

'// Forward references
TYPE IDXGIObject AS IDXGIObject_
TYPE IDXGIDeviceSubObject As IDXGIDeviceSubObject_
TYPE IDXGIResource AS IDXGIResource_
TYPE IDXGIKeyedMutex AS IDXGIKeyedMutex_
TYPE IDXGISurface AS IDXGISurface_
TYPE IDXGISurface1 AS IDXGISurface1_
TYPE IDXGIOutput AS IDXGIOutput_
TYPE IDXGIAdapter AS IDXGIAdapter_
TYPE IDXGISwapChain AS IDXGISwapChain_
TYPE IDXGIFactory AS IDXGIFactory_
TYPE IDXGIDevice AS IDXGIDevice_
TYPE IDXGIAdapter1 AS IDXGIAdapter1_
TYPE IDXGIDevice1 AS IDXGIDevice1_
TYPE IDXGIFactory1 AS IDXGIFactory1_
TYPE IDXGIOutputDuplication AS IDXGIOutputDuplication_
TYPE IDXGISurface2 AS IDXGISurface2_
TYPE IDXGIResource1 AS IDXGIResource1_
TYPE IDXGIDisplayControl AS IDXGIDisplayControl_
TYPE IDXGIDevice2 AS IDXGIDevice2_
TYPE IDXGISwapChain1 AS IDXGISwapChain1_
TYPE IDXGIFactory2 AS IDXGIFactory2_
TYPE IDXGIAdapter2 AS IDXGIAdapter2_
TYPE IDXGIOutput1 AS IDXGIOutput1_
TYPE IDXGIDevice3 AS IDXGIDevice3_
TYPE IDXGISwapChain2 AS IDXGISwapChain2_
TYPE IDXGIOutput2 AS IDXGIOutput2_
TYPE IDXGIFactory3 AS IDXGIFactory3_
TYPE IDXGIDecodeSwapChain AS IDXGIDecodeSwapChain_
TYPE IDXGIFactoryMedia AS IDXGIFactoryMedia_
TYPE IDXGISwapChainMedia AS IDXGISwapChainMedia_
TYPE IDXGIOutput3 AS IDXGIOutput3_
TYPE IDXGISwapChain3 AS IDXGISwapChain3_
TYPE IDXGIOutput4 AS IDXGIOutput4_
TYPE IDXGIFactory4 AS IDXGIFactory4_
TYPE IDXGIAdapter3 AS IDXGIAdapter3_
TYPE IDXGIOutput5 AS IDXGIOutput5_
TYPE IDXGISwapChain4 AS IDXGISwapChain4_
TYPE IDXGIDevice4 AS IDXGIDevice4_
TYPE IDXGIFactory5 AS IDXGIFactory5_
TYPE IDXGIAdapter4 AS IDXGIAdapter4_
TYPE IDXGIOutput6 AS IDXGIOutput6_
TYPE IDXGIFactory6 AS IDXGIFactory6_

' ########################################################################################
' Interface name: IDXGIObject
' IID: {AEC22FB8-76F3-4639-9BE0-28EB43A67A2E}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDXGIObject_INTERFACE_DEFINED__
#define __IDXGIObject_INTERFACE_DEFINED__

TYPE IDXGIObject_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION SetPrivateData (BYREF name AS GUID, BYVAL DataSize AS UINT, BYVAL pData AS const ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPrivateDataInterface (BYREF name AS GUID, BYVAL pUnknown AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetPrivateData (BYREF name AS GUID, BYVAL pDataSize AS UINT PTR, BYVAL pData AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetParent (BYREF riid AS IID, BYREF ppPparent AS ANY PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDeviceSubObject
' IID: {3D3E0379-F9DE-4D58-BB6C-18D62992F1A6}
' Inherited interface = IDXGIObject
' ########################################################################################

#ifndef __IDXGIDeviceSubObject_INTERFACE_DEFINED__
#define __IDXGIDeviceSubObject_INTERFACE_DEFINED__

TYPE IDXGIDeviceSubObject_ EXTENDS IDXGIObject
   DECLARE ABSTRACT FUNCTION GetDevice (BYREF riid AS IID, BYREF ppDevice AS ANY PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIResource
' IID: {035F3AB4-482E-4E50-B41F-8A7F8BD8960B}
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#ifndef __IDXGIResource_INTERFACE_DEFINED__
#define __IDXGIResource_INTERFACE_DEFINED__

TYPE IDXGIResource_ EXTENDS IDXGIDeviceSubObject
   DECLARE ABSTRACT FUNCTION GetSharedHandle (BYREF sharedHandle AS HANDLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetUsage (BYREF usage AS DXGI_USAGE) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetEvictionPriority (BYVAL EvictionPriority AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetEvictionPriority (BYREF EvictionPriority AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIKeyedMutex
' IID: {9D8E1289-D7B3-465F-8126-250E349AF85D}
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#ifndef __IDXGIKeyedMutex_INTERFACE_DEFINED__
#define __IDXGIKeyedMutex_INTERFACE_DEFINED__

TYPE IDXGIKeyedMutex_ EXTENDS IDXGIDeviceSubObject
   DECLARE ABSTRACT FUNCTION AcquireSync (BYVAL Key AS UINT64, BYVAL dwMilliseconds AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseSync (BYVAL Key AS UINT64) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGISurface
' IID: {CAFCB56C-6AC3-4889-BF47-9E23BBD260EC}
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#ifndef __IDXGISurface_INTERFACE_DEFINED__
#define __IDXGISurface_INTERFACE_DEFINED__

TYPE IDXGISurface_ EXTENDS IDXGIDeviceSubObject
   DECLARE ABSTRACT FUNCTION GetDesc (BYREF desc AS DXGI_SURFACE_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION Map (BYREF lockedRect AS DXGI_MAPPED_RECT, BYVAL MapFlags AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION Unmap () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGISurface1
' IID: {4AE63092-6327-4C1B-80AE-BFE12EA32B86}
' Inherited interface = IDXGISurface
' Number of methods = 2
' ########################################################################################

#ifndef __IDXGISurface1_INTERFACE_DEFINED__
#define __IDXGISurface1_INTERFACE_DEFINED__

TYPE IDXGISurface1_ EXTENDS IDXGISurface
   DECLARE ABSTRACT FUNCTION GetDC (BYVAL Discard AS BOOLEAN, BYREF hdc AS ..HDC) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseDC (BYREF dirtyRect AS RECT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIOutput
' IID: {AE02EEDB-C735-4690-8D52-5A8DC20213AA}
' Inherited interface = IDXGIObject
' ########################################################################################

#ifndef __IDXGIOutput_INTERFACE_DEFINED__
#define __IDXGIOutput_INTERFACE_DEFINED__

TYPE IDXGIOutput_ EXTENDS IDXGIObject
   DECLARE ABSTRACT FUNCTION GetDesc (BYREF desc AS DXGI_OUTPUT_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDisplayModeList (BYVAL EnumFormat AS DXGI_FORMAT, BYVAL Flags AS UINT, BYREF numModes AS UINT, BYREF desc AS DXGI_MODE_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION FindClosestMatchingMode (BYREF modeToMatch AS DXGI_MODE_DESC, BYREF closestMatch AS DXGI_MODE_DESC, BYVAL pConcernedDevice AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION WaitForVBlank () AS HRESULT
   DECLARE ABSTRACT FUNCTION TakeOwnership (BYVAL pDevice AS IUnknown PTR, BYVAL Exclusive AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT SUB ReleaseOwnership ()
   DECLARE ABSTRACT FUNCTION GetGammaControlCapabilities (BYREF gammaCaps AS DXGI_GAMMA_CONTROL_CAPABILITIES) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetGammaControl (BYREF array AS const DXGI_GAMMA_CONTROL) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGammaControl (BYREF array AS DXGI_GAMMA_CONTROL) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetDisplaySurface (BYREF scanoutSurface AS IDXGISurface) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDisplaySurfaceData (BYVAL pDestination AS IDXGISurface PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameStatistics (BYREF stats AS DXGI_FRAME_STATISTICS) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIAdapter
' IID: {2411E7E1-12AC-4CCF-BD14-9798E8534DC0}
' Inherited interface = IDXGIObject
' ########################################################################################

#ifndef __IDXGIAdapter_INTERFACE_DEFINED__
#define __IDXGIAdapter_INTERFACE_DEFINED__

TYPE IDXGIAdapter_ EXTENDS IDXGIObject
   DECLARE ABSTRACT FUNCTION EnumOutputs (BYVAL output AS UINT, BYREF ppOutput AS IDXGIOutput PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDesc (BYREF desc AS DXGI_ADAPTER_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION CheckInterfaceSupport (BYREF interfaceName AS GUID, BYREF UMDVersion AS LARGE_INTEGER) AS HRESULT
END TYPE

#endif

' ########################################################################################

CONST DXGI_MAX_SWAP_CHAIN_BUFFERS = 16
CONST DXGI_PRESENT_TEST = &h00000001
CONST DXGI_PRESENT_DO_NOT_SEQUENCE = &h00000002
CONST DXGI_PRESENT_RESTART = &h00000004
CONST DXGI_PRESENT_DO_NOT_WAIT = &h00000008
CONST DXGI_PRESENT_STEREO_PREFER_RIGHT = &h00000010
CONST DXGI_PRESENT_STEREO_TEMPORARY_MONO = &h00000020
CONST DXGI_PRESENT_RESTRICT_TO_OUTPUT = &h00000040
CONST DXGI_PRESENT_USE_DURATION = &h00000100
CONST DXGI_PRESENT_ALLOW_TEARING = &h00000200

' ########################################################################################
' Interface name: IDXGISwapChain
' IID: {310D36A0-D2E7-4C0A-AA04-6A9D23B8886A}
' Inherited interface = IDXGIDeviceSubObject
' ########################################################################################

#ifndef __IDXGISwapChain_INTERFACE_DEFINED__
#define __IDXGISwapChain_INTERFACE_DEFINED__

TYPE IDXGISwapChain_ EXTENDS IDXGIDeviceSubObject
   DECLARE ABSTRACT FUNCTION Present (BYVAL SyncInterval AS UINT, BYVAL Flags AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBuffer (BYVAL Buffer AS UINT, BYREF riid AS IID, BYREF ppSurface AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetFullscreenState (BYVAL Fullscreen AS BOOLEAN, BYVAL pTarget AS IDXGIOutput PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFullscreenState (BYREF Fullscreen AS BOOLEAN, BYREF ppTarget AS IDXGIOutput PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDesc (BYREF desc AS DXGI_SWAP_CHAIN_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION ResizeBuffers (BYVAL BufferCount AS UINT, BYVAL Width AS UINT, BYVAL Height AS UINT, BYVAL NewFormat AS DXGI_FORMAT, BYVAL SwapChainFlags AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION ResizeTarget (BYREF NewTargetParameters AS DXGI_MODE_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetContainingOutput (BYREF ppOutput AS IDXGIOutput PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameStatistics (BYREF stats AS DXGI_FRAME_STATISTICS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetLastPresentCount (BYREF LastPresentCount AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

CONST DXGI_MWA_NO_WINDOW_CHANGES = &h1
CONST DXGI_MWA_NO_ALT_ENTER      = &h2
CONST DXGI_MWA_NO_PRINT_SCREEN   = &h4
CONST DXGI_MWA_VALID             = &h7

' ########################################################################################
' Interface name: IDXGIFactory
' IID: {7B7166EC-21C7-44AE-B21A-C9AE321AE369}
' Inherited interface = IDXGIObject
' ########################################################################################

#ifndef __IDXGIFactory_INTERFACE_DEFINED__
#define __IDXGIFactory_INTERFACE_DEFINED__

TYPE IDXGIFactory_ EXTENDS IDXGIObject
   DECLARE ABSTRACT FUNCTION EnumAdapters (BYVAL Adapter AS UINT, BYREF ppAdapter AS IDXGIAdapter PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION MakeWindowAssociation (BYVAL WindowHandle AS HWND, BYVAL Flags AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetWindowAssociation (BYREF WindowHandle AS HWND) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSwapChain (BYVAL pDevice AS IUnknown PTR, BYREF desc AS DXGI_SWAP_CHAIN_DESC, BYREF ppSwapChain AS IDXGISwapChain PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSoftwareAdapter (BYVAL Module AS HMODULE, BYREF ppAdapter AS IDXGIAdapter PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDevice
' IID: {54EC77FA-1377-44E6-8C32-88FD5F44C84C}
' Inherited interface = IDXGIObject
' ########################################################################################

#ifndef __IDXGIDevice_INTERFACE_DEFINED__
#define __IDXGIDevice_INTERFACE_DEFINED__

TYPE IDXGIDevice_ EXTENDS IDXGIObject
   DECLARE ABSTRACT FUNCTION GetAdapter (BYREF pAdapter AS IDXGIAdapter PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSurface (BYREF desc AS const DXGI_SURFACE_DESC, BYVAL NumSurfaces AS UINT, BYVAL Usage AS DXGI_USAGE, BYREF SharedResource AS const DXGI_SHARED_RESOURCE, BYREF ppSurface AS IDXGISurface PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION QueryResourceResidency (BYREF ppResources AS const IUnknown PTR, BYREF ResidencyStatus AS DXGI_RESIDENCY, BYVAL NumResources AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetGPUThreadPriority (BYVAL Priority AS INT_) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetGPUThreadPriority (BYREF Priority AS INT_) AS HRESULT
END TYPE

#endif

' ########################################################################################


TYPE DXGI_ADAPTER_FLAG AS LONG
enum
   DXGI_ADAPTER_FLAG_NONE = 0
   DXGI_ADAPTER_FLAG_REMOTE = 1
   DXGI_ADAPTER_FLAG_SOFTWARE = 2
   DXGI_ADAPTER_FLAG_FORCE_DWORD = &hffffffff
end enum

type DXGI_ADAPTER_DESC1
   AS WSTRING * 128 Description
   AS UINT VendorId
   AS UINT DeviceId
   AS UINT SubSysId
   AS UINT Revision
   AS SIZE_T DedicatedVideoMemory
   AS SIZE_T DedicatedSystemMemory
   AS SIZE_T SharedSystemMemory
   AS LUID AdapterLuid
   AS UINT Flags
end type

type DXGI_DISPLAY_COLOR_SPACE
   PrimaryCoordinates (0 TO 7, 0 TO 1) AS FLOAT
   WhitePoints (0 TO 15, 0 TO 1) AS FLOAT
end type

' ########################################################################################
' Interface name: IDXGIAdapter1
' IID: {29038F61-3839-4626-91FD-086879011A05}
' Inherited interface = IDXGIAdapter
' ########################################################################################

#ifndef __IDXGIAdapter1_INTERFACE_DEFINED__
#define __IDXGIAdapter1_INTERFACE_DEFINED__

TYPE IDXGIAdapter1_ EXTENDS IDXGIAdapter
   DECLARE ABSTRACT FUNCTION GetDesc1 (BYREF desc AS DXGI_ADAPTER_DESC1) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDevice1
' IID: {77DB970F-6276-48BA-BA28-070143B4392C}
' Inherited interface = IDXGIDevice
' ########################################################################################

#ifndef __IDXGIDevice1_INTERFACE_DEFINED__
#define __IDXGIDevice1_INTERFACE_DEFINED__

TYPE IDXGIDevice1_ EXTENDS IDXGIDevice
   DECLARE ABSTRACT FUNCTION SetMaximumFrameLatency (BYVAL MaxLatency AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMaximumFrameLatency (BYREF MaxLatency AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactory1
' IID: {770AAE78-F26F-4DBA-A829-253C83D1B387}
' Inherited interface = IDXGIFactory
' ########################################################################################

#ifndef __IDXGIFactory1_INTERFACE_DEFINED__
#define __IDXGIFactory1_INTERFACE_DEFINED__

TYPE IDXGIFactory1_ EXTENDS IDXGIFactory
   DECLARE ABSTRACT FUNCTION EnumAdapters1 (BYVAL Adapter AS UINT, BYREF ppAdapter AS IDXGIAdapter1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsCurrent () AS BOOLEAN
END TYPE

#endif

' ########################################################################################


' ########################################################################################
'                                *** dxgi1_2.h ***
' ########################################################################################

CONST DXGI_ENUM_MODES_STEREO = &H4
CONST DXGI_ENUM_MODES_DISABLED_STEREO = &h8
CONST DXGI_SHARED_RESOURCE_READ = &h80000000
CONST DXGI_SHARED_RESOURCE_WRITE = &H1

TYPE DXGI_OFFER_RESOURCE_PRIORITY AS LONG
enum
   DXGI_OFFER_RESOURCE_PRIORITY_LOW = 1
   DXGI_OFFER_RESOURCE_PRIORITY_NORMAL = 2
   DXGI_OFFER_RESOURCE_PRIORITY_HIGH = 3
end enum

TYPE DXGI_ALPHA_MODE AS LONG
enum
   DXGI_ALPHA_MODE_UNSPECIFIED = 0
   DXGI_ALPHA_MODE_PREMULTIPLIED = 1
   DXGI_ALPHA_MODE_STRAIGHT = 2
   DXGI_ALPHA_MODE_IGNORE = 3
   DXGI_ALPHA_MODE_FORCE_DWORD = &hffffffff
end enum

type DXGI_OUTDUPL_MOVE_RECT
   AS POINT SourcePoint
   AS RECT DestinationRect
end type

type DXGI_OUTDUPL_DESC
   AS DXGI_MODE_DESC ModeDesc
   AS DXGI_MODE_ROTATION Rotation
   AS BOOL DesktopImageInSystemMemory
end type

type DXGI_OUTDUPL_POINTER_POSITION
   AS POINT Position
   AS BOOL Visible
end type

TYPE DXGI_OUTDUPL_POINTER_SHAPE_TYPE AS LONG
enum
   DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME = &h1
   DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR = &h2
   DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR = &h4
end enum

type DXGI_OUTDUPL_POINTER_SHAPE_INFO
   AS UINT Type
   AS UINT Width
   AS UINT Height
   AS UINT Pitch
   AS POINT HotSpot
end type

type DXGI_OUTDUPL_FRAME_INFO
   AS LARGE_INTEGER LastPresentTime
   AS LARGE_INTEGER LastMouseUpdateTime
   AS UINT AccumulatedFrames
   AS BOOL RectsCoalesced
   AS BOOL ProtectedContentMaskedOut
   AS DXGI_OUTDUPL_POINTER_POSITION PointerPosition
   AS UINT TotalMetadataBufferSize
   AS UINT PointerShapeBufferSize
end type

type DXGI_MODE_DESC1
   AS UINT Width
   AS UINT Height
   AS DXGI_RATIONAL RefreshRate
   AS DXGI_FORMAT Format
   AS DXGI_MODE_SCANLINE_ORDER ScanlineOrdering
   AS DXGI_MODE_SCALING Scaling
   AS BOOL Stereo
end type

' ########################################################################################
' Interface name: IDXGIOutputDuplication
' IID: {191CFAC3-A341-470D-B26E-A864F428319C}
' Inherited interface = IDXGIObject
' Number of methods = 8
' ########################################################################################

#ifndef __IDXGIOutputDuplication_INTERFACE_DEFINED__
#define __IDXGIOutputDuplication_INTERFACE_DEFINED__

TYPE IDXGIOutputDuplication_ EXTENDS IDXGIObject
   DECLARE ABSTRACT FUNCTION GetDesc (BYREF desc AS DXGI_OUTDUPL_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION AcquireNextFrame (BYVAL TimeoutInMilliseconds AS UINT, BYREF FrameInfo AS DXGI_OUTDUPL_FRAME_INFO, BYREF ppDesktopResource AS IDXGIResource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameDirtyRects (BYVAL DirtyRectsBufferSize AS UINT, BYREF DirtyRectsBuffer AS RECT, BYREF DirtyRectsBufferSizeRequired AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameMoveRects (BYVAL MoveRectsBufferSize AS UINT, BYREF MoveRectBuffer AS DXGI_OUTDUPL_MOVE_RECT, BYREF MoveRectsBufferSizeRequired AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFramePointerShape (BYVAL PointerShapeBufferSize AS UINT, BYVAL pPointerShapeBuffer AS ANY PTR, BYREF PointerShapeBufferSizeRequired AS UINT, BYREF PointerShapeInfo AS DXGI_OUTDUPL_POINTER_SHAPE_INFO) AS HRESULT
   DECLARE ABSTRACT FUNCTION MapDesktopSurface (BYREF LockedRect AS DXGI_MAPPED_RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnMapDesktopSurface () AS HRESULT
   DECLARE ABSTRACT FUNCTION ReleaseFrame () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGISurface2
' IID: {ABA496DD-B617-4CB8-A866-BC44D7EB1FA2}
' Inherited interface = IDXGISurface1
' ########################################################################################

#ifndef __IDXGISurface2_INTERFACE_DEFINED__
#define __IDXGISurface2_INTERFACE_DEFINED__

TYPE IDXGISurface2_ EXTENDS IDXGISurface1
   DECLARE ABSTRACT FUNCTION GetResource (BYREF riid AS IID, BYREF ppParentResource AS ANY PTR, BYREF SubresourceIndex AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIResource1
' IID: {30961379-4609-4A41-998E-54FE567EE0C1}
' Inherited interface = IDXGIResource
' ########################################################################################

#ifndef __IDXGIResource1_INTERFACE_DEFINED__
#define __IDXGIResource1_INTERFACE_DEFINED__

TYPE IDXGIResource1_ EXTENDS IDXGIResource
   DECLARE ABSTRACT FUNCTION CreateSubresourceSurface (BYVAL index AS UINT, BYREF ppSurface AS IDXGISurface2 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSharedHandle (BYREF Attributes AS SECURITY_ATTRIBUTES, BYVAL dwAccess AS DWORD, BYREF name AS WSTRING, BYREF Handle AS ..HANDLE) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDisplayControl
' IID: {EA9DBF1A-C88E-4486-854A-98AA0138F30C}
' Inherited interface = IUnknown
' Number of methods = 2
' ########################################################################################

#ifndef __IDXGIDisplayControl_INTERFACE_DEFINED__
#define __IDXGIDisplayControl_INTERFACE_DEFINED__

TYPE IDXGIDisplayControl_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION IsStereoEnabled () AS BOOLEAN
   DECLARE ABSTRACT SUB SetStereoEnabled (BYVAL Enabled AS BOOLEAN)
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDevice2
' IID: {05008617-FBFD-4051-A790-144884B4F6A9}
' Inherited interface = IDXGIDevice1
' ########################################################################################

#ifndef __IDXGIDevice2_INTERFACE_DEFINED__
#define __IDXGIDevice2_INTERFACE_DEFINED__

TYPE IDXGIDevice2_ EXTENDS IDXGIDevice1
   DECLARE ABSTRACT FUNCTION OfferResources (BYVAL NumResources AS UINT, BYREF ppResources AS const IDXGIResource PTR, BYVAL Priority AS DXGI_OFFER_RESOURCE_PRIORITY) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReclaimResources (BYVAL NumResources AS UINT, BYREF ppResources AS const IDXGIResource PTR, BYREF Discarded AS BOOLEAN) AS HRESULT
   DECLARE ABSTRACT FUNCTION EnqueueSetEvent (BYVAL hEvent AS HANDLE) AS HRESULT
END TYPE

#endif

' ########################################################################################

TYPE DXGI_SCALING AS LONG
enum
   DXGI_SCALING_STRETCH = 0
   DXGI_SCALING_NONE = 1
   DXGI_SCALING_ASPECT_RATIO_STRETCH = 2
end enum

type DXGI_SWAP_CHAIN_DESC1
   AS UINT Width
   AS UINT Height
   AS DXGI_FORMAT Format
   AS BOOL Stereo
   AS DXGI_SAMPLE_DESC SampleDesc
   AS DXGI_USAGE BufferUsage
   AS UINT BufferCount
   AS DXGI_SCALING Scaling
   AS DXGI_SWAP_EFFECT SwapEffect
   AS DXGI_ALPHA_MODE AlphaMode
   AS UINT Flags
end type

type DXGI_SWAP_CHAIN_FULLSCREEN_DESC
   AS DXGI_RATIONAL RefreshRate
   AS DXGI_MODE_SCANLINE_ORDER ScanlineOrdering
   AS DXGI_MODE_SCALING Scaling
   AS BOOL Windowed
end type

type DXGI_PRESENT_PARAMETERS
   AS UINT DirtyRectsCount
   AS RECT PTR pDirtyRects
   AS RECT PTR pScrollRect
   AS POINT PTR pScrollOffset
end type

' ########################################################################################
' Interface name: IDXGISwapChain1
' IID: {790A45F7-0D42-4876-983A-0A55CFE6F4AA}
' Inherited interface = IDXGISwapChain
' ########################################################################################

#ifndef __IDXGISwapChain1_INTERFACE_DEFINED__
#define __IDXGISwapChain1_INTERFACE_DEFINED__

TYPE IDXGISwapChain1_ EXTENDS IDXGISwapChain
   DECLARE ABSTRACT FUNCTION GetDesc1 (BYVAL desc AS DXGI_SWAP_CHAIN_DESC1) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFullscreenDesc (BYREF desc AS DXGI_SWAP_CHAIN_FULLSCREEN_DESC) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetHwnd (BYREF hwnd AS ..HWND) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetCoreWindow (BYREF riid AS IID, BYREF ppunk AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Present1 (BYVAL SyncInterval AS UINT, BYVAL PresentFlags AS UINT, BYREF pPresentParameters AS const DXGI_PRESENT_PARAMETERS) AS HRESULT
   DECLARE ABSTRACT FUNCTION IsTemporaryMonoSupported () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION GetRestrictToOutput (BYREF ppRestrictToOutput AS IDXGIOutput PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetBackgroundColor (BYREF color AS const DXGI_RGBA) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBackgroundColor (BYREF color AS DXGI_RGBA) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetRotation (BYVAL rotation AS DXGI_MODE_ROTATION) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetRotation (BYREF Rotation AS DXGI_MODE_ROTATION) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactory2
' IID: {50C83A1C-E072-4C48-87B0-3630FA36A6D0}
' Inherited interface = IDXGIFactory1
' ########################################################################################

#ifndef __IDXGIFactory2_INTERFACE_DEFINED__
#define __IDXGIFactory2_INTERFACE_DEFINED__

TYPE IDXGIFactory2_ EXTENDS IDXGIFactory1
   DECLARE ABSTRACT FUNCTION IsWindowedStereoEnabled () AS BOOLEAN
   DECLARE ABSTRACT FUNCTION CreateSwapChainForHwnd (BYVAL pDevice AS IUnknown PTR, BYVAL hwnd AS HWND, BYREF desc AS DXGI_SWAP_CHAIN_DESC1, BYREF FullscreenDesc AS const DXGI_SWAP_CHAIN_FULLSCREEN_DESC, BYVAL pRestrictToOutput AS IDXGIOutput PTR, BYREF ppSwapChain AS IDXGISwapChain1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSwapChainForCoreWindow (BYVAL pDevice AS IUnknown PTR, BYVAL pWindow AS IUnknown PTR, BYVAL desc AS const DXGI_SWAP_CHAIN_DESC1, BYVAL pRestrictToOutput AS IDXGIOutput PTR, BYREF ppSwapChain AS IDXGISwapChain1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSharedResourceAdapterLuid (BYVAL hResource AS HANDLE, BYREF Luid AS ..LUID) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterStereoStatusWindow (BYVAL WindowHandle AS HWND, BYVAL wMsg AS UINT, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterStereoStatusEvent (BYVAL hEvent AS HANDLE, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterStereoStatus (BYVAL dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterOcclusionStatusWindow (BYVAL WindowHandle AS HWND, BYVAL wMsg AS UINT, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterOcclusionStatusEvent (BYVAL hEvent AS HANDLE, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterOcclusionStatus (BYVAL dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateSwapChainForComposition (BYVAL pDevice AS IUnknown PTR, BYREF desc AS const DXGI_SWAP_CHAIN_DESC1, BYVAL pRestrictToOutput AS IDXGIOutput PTR, BYREF ppSwapChain AS IDXGISwapChain1 PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

TYPE DXGI_GRAPHICS_PREEMPTION_GRANULARITY AS LONG
enum
   DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY = 0
   DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY = 1
   DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY = 2
   DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY = 3
   DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY = 4
end enum

TYPE DXGI_COMPUTE_PREEMPTION_GRANULARITY AS LONG
enum
   DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY = 0
   DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY = 1
   DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY = 2
   DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY = 3
   DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY = 4
end enum

type DXGI_ADAPTER_DESC2
   Description AS WSTRING * 128
   AS UINT VendorId
   AS UINT DeviceId
   AS UINT SubSysId
   AS UINT Revision
   AS SIZE_T DedicatedVideoMemory
   AS SIZE_T DedicatedSystemMemory
   AS SIZE_T SharedSystemMemory
   AS LUID AdapterLuid
   AS UINT Flags
   AS DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity
   AS DXGI_COMPUTE_PREEMPTION_GRANULARITY ComputePreemptionGranularity
end type

' ########################################################################################
' Interface name: IDXGIAdapter2
' IID: {0AA1AE0A-FA0E-4B84-8644-E05FF8E5ACB5}
' Inherited interface = IDXGIAdapter1
' ########################################################################################

#ifndef __IDXGIAdapter2_INTERFACE_DEFINED__
#define __IDXGIAdapter2_INTERFACE_DEFINED__

TYPE IDXGIAdapter2_ EXTENDS IDXGIAdapter1
   DECLARE ABSTRACT FUNCTION GetDesc2 (BYREF desc AS DXGI_ADAPTER_DESC2) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIOutput1
' IID: {00CDDEA8-939B-4B83-A340-A685226666CC}
' Inherited interface = IDXGIOutput
' Number of methods = 4
' ########################################################################################

#ifndef __IDXGIOutput1_INTERFACE_DEFINED__
#define __IDXGIOutput1_INTERFACE_DEFINED__

TYPE IDXGIOutput1_ EXTENDS IDXGIOutput
   DECLARE ABSTRACT FUNCTION GetDisplayModeList1 (BYVAL EnumFormat AS DXGI_FORMAT, BYVAL flags AS UINT, BYREF NumModes AS UINT, BYREF desc AS DXGI_MODE_DESC1) AS HRESULT
   DECLARE ABSTRACT FUNCTION FindClosestMatchingMode1 (BYREF ModeToMatch AS const DXGI_MODE_DESC1, BYREF closestMatch AS DXGI_MODE_DESC1, BYVAL pConcernedDevice AS IUnknown PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDisplaySurfaceData1 (BYVAL pDestination AS IDXGIResource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION DuplicateOutput (BYVAL pDevice AS IUnknown PTR, BYREF ppOutputDuplication AS IDXGIOutputDuplication PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
'                                *** dxgi1_3.h ***
' ########################################################################################

type DXGI_MATRIX_3X2_F
   AS float _11
   AS float _12
   AS float _21
   AS float _22
   AS float _31
   AS float _32
end type

type DXGI_DECODE_SWAP_CHAIN_DESC
  AS  UINT Flags
end type

TYPE DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS AS LONG
enum
   DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE = &h1
   DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709 = &h2
   DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC = &h4
end enum

TYPE DXGI_FRAME_PRESENTATION_MODE AS LONG
enum
   DXGI_FRAME_PRESENTATION_MODE_COMPOSED = 0
   DXGI_FRAME_PRESENTATION_MODE_OVERLAY = 1
   DXGI_FRAME_PRESENTATION_MODE_NONE = 2
   DXGI_FRAME_PRESENTATION_MODE_COMPOSITION_FAILURE = 3
end enum

type DXGI_FRAME_STATISTICS_MEDIA
   AS UINT PresentCount
   AS UINT PresentRefreshCount
   AS UINT SyncRefreshCount
   AS LARGE_INTEGER SyncQPCTime
   AS LARGE_INTEGER SyncGPUTime
   AS DXGI_FRAME_PRESENTATION_MODE CompositionMode
   AS UINT ApprovedPresentDuration
end type

TYPE DXGI_OVERLAY_SUPPORT_FLAG AS LONG
enum
   DXGI_OVERLAY_SUPPORT_FLAG_DIRECT = &h1
   DXGI_OVERLAY_SUPPORT_FLAG_SCALING = &h2
end enum


' ########################################################################################
' Interface name: IDXGIDevice3
' IID: {6007896C-3244-4AFD-BF18-A6D3BEDA5023}
' Inherited interface = IDXGIDevice2
' ########################################################################################

#ifndef __IDXGIDevice3_INTERFACE_DEFINED__
#define __IDXGIDevice3_INTERFACE_DEFINED__

TYPE IDXGIDevice3_ EXTENDS IDXGIDevice2
   DECLARE ABSTRACT SUB Trim ()
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGISwapChain2
' IID: {A8BE2AC4-199F-4946-B331-79599FB98DE7}
' Inherited interface = IDXGISwapChain1
' ########################################################################################

#ifndef __IDXGISwapChain2_INTERFACE_DEFINED__
#define __IDXGISwapChain2_INTERFACE_DEFINED__

TYPE IDXGISwapChain2_ EXTENDS IDXGISwapChain1
   DECLARE ABSTRACT FUNCTION SetSourceSize (BYVAL width AS UINT, BYVAL height AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSourceSize (BYREF width AS UINT, BYREF height AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetMaximumFrameLatency (BYVAL MaxLatency AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMaximumFrameLatency (BYREF MaxLatency AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFrameLatencyWaitableObject () AS HANDLE
   DECLARE ABSTRACT FUNCTION SetMatrixTransform (BYREF Matrix AS DXGI_MATRIX_3X2_F) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetMatrixTransform (BYREF Matrix AS DXGI_MATRIX_3X2_F) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: IDXGIOutput2
' IID: {595E39D1-2724-4663-99B1-DA969DE28364}
' Inherited interface = IDXGIOutput1
' ########################################################################################

#ifndef __IDXGIOutput2_INTERFACE_DEFINED__
#define __IDXGIOutput2_INTERFACE_DEFINED__

TYPE IDXGIOutput2_ EXTENDS IDXGIOutput1
   DECLARE ABSTRACT FUNCTION SupportsOverlays () AS BOOLEAN
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactory3
' IID: {25483823-CD46-4C7D-86CA-47AA95B837BD}
' Inherited interface = IDXGIFactory2
' ########################################################################################

#ifndef __IDXGIFactory3_INTERFACE_DEFINED__
#define __IDXGIFactory3_INTERFACE_DEFINED__

TYPE IDXGIFactory3_ EXTENDS IDXGIFactory2
   DECLARE ABSTRACT FUNCTION GetCreationFlags () AS UINT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDecodeSwapChain
' IID: {2633066B-4514-4C7A-8FD8-12EA98059D18}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDXGIDecodeSwapChain_INTERFACE_DEFINED__
#define __IDXGIDecodeSwapChain_INTERFACE_DEFINED__

TYPE IDXGIDecodeSwapChain_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION PresentBuffer (BYVAL BufferToPresent AS UINT, BYVAL SyncInterval AS UINT, BYVAL UINT AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetSourceRect (BYREF rc AS RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetTargetRect (BYREF rc AS RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetDestSize (BYVAL width AS UINT, BYVAL height AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetSourceRect (BYREF rc AS RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetTargetRect (BYREF rc AS RECT) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetDestSize (BYREF width AS UINT, BYREF height AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetColorSpace (BYVAL ColorSpace AS DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColorSpace () AS DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactoryMedia
' IID: {41E7D1F2-A591-4F7B-A2E5-FA9C843E1C12}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDXGIFactoryMedia_INTERFACE_DEFINED__
#define __IDXGIFactoryMedia_INTERFACE_DEFINED__

TYPE IDXGIFactoryMedia_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION CreateSwapChainForCompositionSurfaceHandle (BYVAL pDevice AS IUnknown PTR, BYVAL hSurface AS HANDLE, _
      BYREF dec AS DXGI_SWAP_CHAIN_DESC1, BYVAL pRestrictToOutput AS IDXGIOutput PTR, BYREF ppSwapChain AS IDXGISwapChain1 PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CreateDecodeSwapChainForCompositionSurfaceHandle (BYVAL pDevice AS IUnknown PTR, BYVAL hSurface AS HANDLE, _
      BYREF desc AS DXGI_DECODE_SWAP_CHAIN_DESC, BYVAL pYuvDecodeBuffers AS IDXGIResource PTR, BYVAL pRestrictToOutput AS IDXGIOutput PTR, _
      BYREF ppSwapChain AS IDXGIDecodeSwapChain PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGISwapChainMedia
' IID: {DD95B90B-F05F-4F6A-BD65-25BFB264BD84}
' Inherited interface = IUnknown
' ########################################################################################

#ifndef __IDXGISwapChainMedia_INTERFACE_DEFINED__
#define __IDXGISwapChainMedia_INTERFACE_DEFINED__

TYPE IDXGISwapChainMedia_ EXTENDS Afx_IUnknown
   DECLARE ABSTRACT FUNCTION GetFrameStatisticsMedia (BYREF Stats AS DXGI_FRAME_STATISTICS_MEDIA) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetPresentDuration (BYVAL Duration AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION CheckPresentDurationSupport (BYVAL DesiredPresentDuration AS UINT, BYREF ClosestSmallerPresentDuration AS UINT, BYREF ClosestLargerPresentDuration AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIOutput3
' IID: {8A6BB301-7E7E-41F4-A8E0-5B32F7F99B18}
' Inherited interface = IDXGIOutput2
' ########################################################################################

#ifndef __IDXGIOutput3_INTERFACE_DEFINED__
#define __IDXGIOutput3_INTERFACE_DEFINED__

TYPE IDXGIOutput3_ EXTENDS IDXGIOutput2
   DECLARE ABSTRACT FUNCTION CheckOverlaySupport (BYVAL EnumFormat AS DXGI_FORMAT, BYVAL pConcernedDevice AS IUnknown PTR, BYREF Flags AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################


#define DXGI_CREATE_FACTORY_DEBUG &h1

DECLARE FUNCTION CreateDXGIFactory2 LIB "Dxgi" ALIAS "CreateDXGIFactory2" (BYVAL flags AS UINT, BYREF factory AS ANY PTR) AS HRESULT

DECLARE FUNCTION DXGIGetDebugInterface1 LIB "Dxgi" ALIAS "DXGIGetDebugInterface1" (BYVAL flags AS UINT, BYREF iid AS IID, BYREF debug AS ANY PTR) AS HRESULT



' ########################################################################################
'                                *** dxgi1_4.h ***
' ########################################################################################

TYPE DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG AS LONG
enum
   DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT = &h1
   DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT = &h2
end enum

TYPE DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG AS LONG
enum
   DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT = &h1
end enum

TYPE DXGI_MEMORY_SEGMENT_GROUP AS LONG
enum
   DXGI_MEMORY_SEGMENT_GROUP_LOCAL = &h0
   DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL = &h1
end enum

type DXGI_QUERY_VIDEO_MEMORY_INFO
   AS UINT64 Budget
   AS UINT64 CurrentUsage
   AS UINT64 AvailableForReservation
   AS UINT64 CurrentReservation
end type


' ########################################################################################
' Interface name: IDXGISwapChain3
' IID: {94D99BDB-F1F8-4AB0-B236-7DA0170EDAB1}
' Inherited interface = IDXGISwapChain2
' ########################################################################################

#ifndef __IDXGISwapChain3_INTERFACE_DEFINED__
#define __IDXGISwapChain3_INTERFACE_DEFINED__

TYPE IDXGISwapChain3_ EXTENDS IDXGISwapChain2
   DECLARE ABSTRACT FUNCTION GetCurrentBackBufferIndex () AS UINT
   DECLARE ABSTRACT FUNCTION CheckColorSpaceSupport (BYVAL ColorSpace AS DXGI_COLOR_SPACE_TYPE, BYREF ColorSpaceSupport AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetColorSpace1 (BYVAL ColorSpace AS DXGI_COLOR_SPACE_TYPE) AS HRESULT
   DECLARE ABSTRACT FUNCTION ResizeBuffers1 (BYVAL BufferCount AS UINT, BYVAL width AS UINT, BYVAL height AS UINT, _
           BYVAL format AS DXGI_FORMAT, BYVAL SwapChainFlags AS UINT, BYREF CreationNodeMask AS const UINT, BYREF ppPresentQueue AS const IUnknown PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: IDXGIOutput4
' IID: {DC7DCA35-2196-414D-9F53-617884032A60}
' Inherited interface = IDXGIOutput3
' ########################################################################################

#ifndef __IDXGIOutput4_INTERFACE_DEFINED__
#define __IDXGIOutput4_INTERFACE_DEFINED__

TYPE IDXGIOutput4_ EXTENDS IDXGIOutput3
   DECLARE ABSTRACT FUNCTION CheckOverlayColorSpaceSupport (BYVAL format AS DXGI_FORMAT, BYVAL ColorSpace AS DXGI_COLOR_SPACE_TYPE, _
           BYVAL pConcernedDevice AS IUnknown PTR, BYREF Flags AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactory4
' IID: {1BC6EA02-EF36-464F-BF0C-21CA39E5168A}
' Inherited interface = IDXGIFactory3
' ########################################################################################

#ifndef __IDXGIFactory4_INTERFACE_DEFINED__
#define __IDXGIFactory4_INTERFACE_DEFINED__

TYPE IDXGIFactory4_ EXTENDS IDXGIFactory3
   DECLARE ABSTRACT FUNCTION EnumAdapterByLuid (BYVAL AdapterLuid AS LUID, BYREF riid AS IID, BYREF ppvAdapter AS ANY PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION EnumWarpAdapter (BYREF riid AS IID, BYREF ppvAdapter AS ANY PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIAdapter3
' IID: {645967A4-1392-4310-A798-8053CE3E93FD}
' Inherited interface = IDXGIAdapter2
' Number of methods = 6
' ########################################################################################

#ifndef __IDXGIAdapter3_INTERFACE_DEFINED__
#define __IDXGIAdapter3_INTERFACE_DEFINED__

TYPE IDXGIAdapter3_ EXTENDS IDXGIAdapter2
   DECLARE ABSTRACT FUNCTION RegisterHardwareContentProtectionTeardownStatusEvent (BYVAL hEvent AS HANDLE, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterHardwareContentProtectionTeardownStatus (BYVAL dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION QueryVideoMemoryInfo (BYVAL NodeIndex AS UINT, BYVAL MemorySegmentGroup AS DXGI_MEMORY_SEGMENT_GROUP, BYREF VideoMemoryInfo AS DXGI_QUERY_VIDEO_MEMORY_INFO) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetVideoMemoryReservation (BYVAL NodeIndex AS UINT, BYVAL MemorySegmentGroup AS DXGI_MEMORY_SEGMENT_GROUP, BYVAL Reservation AS UINT64) AS HRESULT
   DECLARE ABSTRACT FUNCTION RegisterVideoMemoryBudgetChangeNotificationEvent (BYVAL hEvent AS HANDLE, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterVideoMemoryBudgetChangeNotification (BYVAL dwCookie AS DWORD) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
'                                *** dxgi1_5.h ***
' ########################################################################################

TYPE DXGI_OUTDUPL_FLAG AS LONG
enum
   DXGI_OUTDUPL_COMPOSITED_UI_CAPTURE_ONLY = &h1
end enum

TYPE DXGI_HDR_METADATA_TYPE AS LONG
enum
   DXGI_HDR_METADATA_TYPE_NONE = &h0
   DXGI_HDR_METADATA_TYPE_HDR10 = &h1
   DXGI_HDR_METADATA_TYPE_HDR10PLUS = &h2
end enum

TYPE DXGI_OFFER_RESOURCE_FLAGS AS LONG
enum
   DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT = &h1
end enum

TYPE DXGI_RECLAIM_RESOURCE_RESULTS AS LONG
enum
   DXGI_RECLAIM_RESOURCE_RESULT_OK = &h0
   DXGI_RECLAIM_RESOURCE_RESULT_DISCARDED = &h1
   DXGI_RECLAIM_RESOURCE_RESULT_NOT_COMMITTED = &h2
end enum

TYPE DXGI_FEATURE AS LONG
enum
   DXGI_FEATURE_PRESENT_ALLOW_TEARING = &h0
end enum

type DXGI_HDR_METADATA_HDR10
   AS UINT16 RedPrimary(0 TO 1)
   AS UINT16 GreenPrimary(0 TO 1)
   AS UINT16 BluePrimary(0 TO 1)
   AS UINT16 WhitePoint(0 TO 1)
   AS UINT MaxMasteringLuminance
   AS UINT MinMasteringLuminance
   AS UINT16 MaxContentLightLevel
   AS UINT16 MaxFrameAverageLightLevel
end type

type DXGI_HDR_METADATA_HDR10PLUS
   AS BYTE Data(0 TO 71)
end type


' ########################################################################################
' Interface name: IDXGIOutput5
' IID: {80A07424-AB52-42EB-833C-0C42FD282D98}
' Inherited interface = IDXGIOutput4
' ########################################################################################

#ifndef __IDXGIOutput5_INTERFACE_DEFINED__
#define __IDXGIOutput5_INTERFACE_DEFINED__

TYPE IDXGIOutput5_ EXTENDS IDXGIOutput4
   DECLARE ABSTRACT FUNCTION DuplicateOutput1 (BYVAL pDevice AS IUnknown PTR, BYVAL flags AS UINT, BYVAL SupportedFormatsCount AS UINT, _
           BYREF SupportedFormats AS DXGI_FORMAT, BYREF ppOutputDuplication AS IDXGIOutputDuplication PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGISwapChain4
' IID: {3D585D5A-BD4A-489E-B1F4-3DBCB6452FFB}
' Inherited interface = IDXGISwapChain3
' ########################################################################################

#ifndef __IDXGISwapChain4_INTERFACE_DEFINED__
#define __IDXGISwapChain4_INTERFACE_DEFINED__

TYPE IDXGISwapChain4_ EXTENDS IDXGISwapChain3
   DECLARE ABSTRACT FUNCTION SetHDRMetaData (BYVAL nType AS DXGI_HDR_METADATA_TYPE, BYVAL size AS UINT, BYVAL pMetaData AS ANY PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIDevice4
' IID: {95B4F95F-D8DA-4CA4-9EE6-3B76D5968A10}
' Inherited interface = IDXGIDevice3
' ########################################################################################

#ifndef __IDXGIDevice4_INTERFACE_DEFINED__
#define __IDXGIDevice4_INTERFACE_DEFINED__

TYPE IDXGIDevice4_ EXTENDS IDXGIDevice3
   DECLARE ABSTRACT FUNCTION OfferResources1 (BYVAL NumResources AS UINT, BYREF ppResources AS IDXGIResource PTR, BYVAL Priority AS DXGI_OFFER_RESOURCE_PRIORITY, BYVAL flags AS UINT) AS HRESULT
   DECLARE ABSTRACT FUNCTION ReclaimResources1 (BYVAL NumResources AS UINT, BYREF ppResources AS const IDXGIResource PTR, BYREF pResults AS DXGI_RECLAIM_RESOURCE_RESULTS) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactory5
' IID: {7632E1F5-EE65-4DCA-87FD-84CD75F8838D}
' Inherited interface = IDXGIFactory4
' ########################################################################################

#ifndef __IDXGIFactory5_INTERFACE_DEFINED__
#define __IDXGIFactory5_INTERFACE_DEFINED__

TYPE IDXGIFactory5_ EXTENDS IDXGIFactory4
   DECLARE ABSTRACT FUNCTION CheckFeatureSupport (BYVAL Feature AS DXGI_FEATURE, BYVAL pFeatureSupportData AS ANY PTR, BYVAL FeatureSupportDataSize AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
'                                *** dxgi1_6.h ***
' ########################################################################################

TYPE DXGI_ADAPTER_FLAG3 AS LONG
enum
   DXGI_ADAPTER_FLAG3_NONE = &h0
   DXGI_ADAPTER_FLAG3_REMOTE = &h1
   DXGI_ADAPTER_FLAG3_SOFTWARE = &h2
   DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE = &h4
   DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES = &h8
   DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES = &h10
   DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE = &h20
   DXGI_ADAPTER_FLAG3_FORCE_DWORD = &hffffffff
end enum

TYPE DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS AS LONG
enum
   DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_FULLSCREEN = &h1
   DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_WINDOWED = &h2
   DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAG_CURSOR_STRETCHED = &h4
end enum

TYPE DXGI_GPU_PREFERENCE AS LONG
enum
   DXGI_GPU_PREFERENCE_UNSPECIFIED = &h0
   DXGI_GPU_PREFERENCE_MINIMUM_POWER = &h1
   DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE = &h2
end enum

type DXGI_ADAPTER_DESC3
   Description AS WSTRING * 128
   AS UINT VendorId
   As UINT DeviceId
   AS UINT SubSysId
   AS UINT Revision
   AS SIZE_T DedicatedVideoMemory
   AS SIZE_T DedicatedSystemMemory
   As SIZE_T SharedSystemMemory
   AS LUID AdapterLuid
   AS DXGI_ADAPTER_FLAG3 Flags
   AS DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity
   AS DXGI_COMPUTE_PREEMPTION_GRANULARITY ComputePreemptionGranularity
end type

type DXGI_OUTPUT_DESC1
   DeviceName AS WSTRING * 32
   AS RECT DesktopCoordinates
   AS BOOL AttachedToDesktop
   AS DXGI_MODE_ROTATION Rotation
   AS HMONITOR Monitor
   AS UINT BitsPerColor
   AS DXGI_COLOR_SPACE_TYPE ColorSpace
   AS FLOAT RedPrimary(0 TO 1)
   AS FLOAT GreenPrimary(0 TO 1)
   AS FLOAT BluePrimary(0 TO 1)
   As FLOAT WhitePoint(0 TO 1)
   AS FLOAT MinLuminance
   AS FLOAT MaxLuminance
   AS FLOAT MaxFullFrameLuminance
end type


' ########################################################################################
' Interface name: IDXGIAdapter4
' IID: {3C8D99D1-4FBF-4181-A82C-AF66BF7BD24E}
' Inherited interface = IDXGIAdapter3
' ########################################################################################

#ifndef __IDXGIAdapter4_INTERFACE_DEFINED__
#define __IDXGIAdapter4_INTERFACE_DEFINED__

TYPE IDXGIAdapter4_ EXTENDS IDXGIAdapter3
   DECLARE ABSTRACT FUNCTION GetDesc3 (BYREF desc AS DXGI_ADAPTER_DESC3) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIOutput6
' IID: {068346E8-AAEC-4B84-ADD7-137F513F77A1}
' Inherited interface = IDXGIOutput5
' ########################################################################################

#ifndef __IDXGIOutput6_INTERFACE_DEFINED__
#define __IDXGIOutput6_INTERFACE_DEFINED__

TYPE IDXGIOutput6_ EXTENDS IDXGIOutput5
   DECLARE ABSTRACT FUNCTION GetDesc1 (BYREF desc AS DXGI_OUTPUT_DESC1) AS HRESULT
   DECLARE ABSTRACT FUNCTION CheckHardwareCompositionSupport (BYREF Flags AS UINT) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IDXGIFactory6
' IID: {C1B6694F-FF09-44A9-B03C-77900A0A1D17}
' Inherited interface = IDXGIFactory5
' ########################################################################################

#ifndef __IDXGIFactory6_INTERFACE_DEFINED__
#define __IDXGIFactory6_INTERFACE_DEFINED__

TYPE IDXGIFactory6_ EXTENDS IDXGIFactory5
   DECLARE ABSTRACT FUNCTION EnumAdapterByGpuPreference (BYVAL Adapter AS UINT, BYVAL GpuPreference AS DXGI_GPU_PREFERENCE, _
           BYREF riid AS IID, BYREF ppvAdapter AS ANY PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################


' ########################################################################################
' Interface name: IDXGIFactory7
' IID: {A4966EED-76DB-44DA-84C1-EE9A7AFB20A8}
' Inherited interface = IDXGIFactory6
' ########################################################################################

#ifndef __IDXGIFactory7_INTERFACE_DEFINED__
#define __IDXGIFactory7_INTERFACE_DEFINED__

TYPE IDXGIFactory7_ EXTENDS IDXGIFactory6
   DECLARE ABSTRACT FUNCTION RegisterAdaptersChangedEvent (BYVAL hEvent AS HANDLE, BYREF dwCookie AS DWORD) AS HRESULT
   DECLARE ABSTRACT FUNCTION UnregisterAdaptersChangedEvent (BYVAL dwCookie AS DWORD) AS HRESULT
END TYPE

#endif

' ########################################################################################
