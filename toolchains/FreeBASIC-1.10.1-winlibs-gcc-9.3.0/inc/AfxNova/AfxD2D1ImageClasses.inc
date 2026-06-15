' D2D1 brush classes
' To be included by AfxD2D1Objects.inc

' ########################################################################################
' CID2D1Bitmap class
' Represents a bitmap that has been bound to an ID2D1RenderTarget.
' ########################################################################################

TYPE CID2D1Bitmap
Public:

   m_pBitmap AS ID2D1Bitmap PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pBitmap AS ID2D1Bitmap PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Bitmap PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Bitmap PTR
   DECLARE OPERATOR CAST () AS ID2D1Image PTR

   ' // ID2D1Image (= ID2D1Resource)
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Bitmap methods
   DECLARE FUNCTION GetSize () AS D2D1_SIZE_F
   DECLARE FUNCTION GetPixelSize () AS D2D1_SIZE_U
   DECLARE FUNCTION GetPixelFormat () AS D2D1_PIXEL_FORMAT
   DECLARE SUB GetDpi (BYREF DpiX AS FLOAT, BYREF DpiY AS FLOAT)
   DECLARE SUB GetDpi (BYVAL DpiX AS FLOAT PTR, BYVAL DpiY AS FLOAT PTR)
   DECLARE FUNCTION CopyFromBitmap (BYREF destPoint AS const D2D1_POINT_2U, BYVAL bitmap AS ID2D1Bitmap PTR, BYREF srcRect AS const D2D1_RECT_U) AS HRESULT
   DECLARE FUNCTION CopyFromBitmap (BYVAL destPoint AS const D2D1_POINT_2U PTR, BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL srcRect AS const D2D1_RECT_U PTR) AS HRESULT
   DECLARE FUNCTION CopyFromBitmap (BYVAL  AS const UINT32, BYVAL destPointY AS const UINT32, BYVAL bitmap AS ID2D1Bitmap PTR, _
           BYVAL srcRectLeft AS UINT32, BYVAL srcRectTop AS UINT32, BYVAL srcRectRight AS UINT32, BYVAL srcRectBottom AS UINT32) AS HRESULT
   DECLARE FUNCTION CopyFromRenderTarget (BYREF destPoint AS const D2D1_POINT_2U, BYVAL renderTarget AS ID2D1RenderTarget PTR, BYREF srcRect AS const D2D1_RECT_U) AS HRESULT
   DECLARE FUNCTION CopyFromRenderTarget (BYVAL destPoint AS const D2D1_POINT_2U PTR, BYVAL renderTarget AS ID2D1RenderTarget PTR, BYVAL srcRect AS const D2D1_RECT_U PTR) AS HRESULT
   DECLARE FUNCTION CopyFromRenderTarget (BYVAL destPointX AS const UINT32, BYVAL destPointY AS const UINT32, BYVAL renderTarget AS ID2D1RenderTarget PTR, _
           BYVAL srcRectLeft AS UINT32, BYVAL srcRectTop AS UINT32, BYVAL srcRectRight AS UINT32, BYVAL srcRectBottom AS UINT32) AS HRESULT
   DECLARE FUNCTION CopyFromMemory (BYREF dstRect AS const D2D1_RECT_U, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT
   DECLARE FUNCTION CopyFromMemory (BYVAL dstRect AS const D2D1_RECT_U PTR, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT
   DECLARE FUNCTION CopyFromMemory (BYVAL dstRectLeft AS UINT32, BYVAL dstRectTop AS UINT32, _
           BYVAL dstRectRight AS UINT32, BYVAL dstRectBottom AS UINT32, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Bitmap class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Bitmap
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Bitmap class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Bitmap (BYVAL pBitmap AS ID2D1Bitmap PTR)
   D2D1_DP("pBitmap - " & WSTR(pBitmap))
   m_pBitmap = pBitmap
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1Bitmap
   D2D1_DP("m_pBitmap: " & WSTR(m_pBitmap))
   IF m_pBitmap THEN m_pBitmap->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Bitmap interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF bitmap AS CID2D1Bitmap) AS ID2D1Bitmap PTR
   RETURN bitmap.m_pBitmap
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Bitmap interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Bitmap.@ () AS ID2D1Bitmap PTR PTR
   RETURN @m_pBitmap
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Bitmap interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Bitmap.CAST () AS ID2D1Bitmap PTR
   RETURN m_pBitmap
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR CID2D1Bitmap.CAST () AS ID2D1Image PTR
   RETURN CAST(ID2D1Image PTR, m_pBitmap)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Image ( = ID2D1Resource) inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   IF m_pBitmap = NULL THEN RETURN NULL
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ANY PTR, m_pBitmap)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size, in device-independent pixels (DIPs), of the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.GetSize () AS D2D1_SIZE_F
   IF m_pBitmap = NULL THEN EXIT FUNCTION
   DIM size AS D2D1_SIZE_F
   m_pBitmap->GetSize(size)
   RETURN size
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size, in device-dependent units (pixels), of the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.GetPixelSize () AS D2D1_SIZE_U
   IF m_pBitmap = NULL THEN EXIT FUNCTION
   DIM size AS D2D1_SIZE_U
   m_pBitmap->GetPixelSize(size)
   RETURN size
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the pixel format and alpha mode of the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.GetPixelFormat () AS D2D1_PIXEL_FORMAT
   IF m_pBitmap = NULL THEN EXIT FUNCTION
   DIM pixelFormat AS D2D1_PIXEL_FORMAT
   m_pBitmap->GetPixelFormat(pixelFormat)
   RETURN pixelFormat
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the pixel format and alpha mode of the bitmap.
' ========================================================================================
PRIVATE SUB CID2D1Bitmap.GetDpi (BYREF DpiX AS FLOAT, BYREF DpiY AS FLOAT)
   IF m_pBitmap = NULL THEN EXIT SUB
   m_pBitmap->GetDpi(DpiX, DpiY)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1Bitmap.GetDpi (BYVAL DpiX AS FLOAT PTR, BYVAL DpiY AS FLOAT PTR)
   IF m_pBitmap = NULL THEN EXIT SUB
   m_pBitmap->GetDpi(BYVAL DpiX, BYVAL DpiY)
END SUB
' ========================================================================================

' ========================================================================================
' Copies the specified region from the specified bitmap into the current bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromBitmap (BYREF destPoint AS const D2D1_POINT_2U, BYVAL bitmap AS ID2D1Bitmap PTR, BYREF srcRect AS const D2D1_RECT_U) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   RETURN m_pBitmap->CopyFromBitmap(destPoint, bitmap, srcRect)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromBitmap (BYVAL destPoint AS const D2D1_POINT_2U PTR, BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL srcRect AS const D2D1_RECT_U PTR) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   RETURN m_pBitmap->CopyFromBitmap(BYVAL destPoint, bitmap, BYVAL srcRect)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromBitmap (BYVAL destPointX AS const UINT32, BYVAL destPointY AS const UINT32, BYVAL bitmap AS ID2D1Bitmap PTR, _
   BYVAL srcRectLeft AS UINT32, BYVAL srcRectTop AS UINT32, BYVAL srcRectRight AS UINT32, BYVAL srcRectBottom AS UINT32) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   DIM destPoint AS D2D1_POINT_2U = (destPointX, destPointY)
   DIM srcRect AS D2D1_RECT_U = (srcRectLeft, srcRectTop, srcRectRight, srcRectBottom)
   RETURN m_pBitmap->CopyFromBitmap(destPoint, bitmap, srcRect)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies the specified region from the specified bitmap into the current bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromRenderTarget (BYREF destPoint AS const D2D1_POINT_2U, BYVAL renderTarget AS ID2D1RenderTarget PTR, BYREF srcRect AS const D2D1_RECT_U) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   RETURN m_pBitmap->CopyFromRenderTarget(destPoint, renderTarget, srcRect)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromRenderTarget (BYVAL destPoint AS const D2D1_POINT_2U PTR, BYVAL renderTarget AS ID2D1RenderTarget PTR, BYVAL srcRect AS const D2D1_RECT_U PTR) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   RETURN m_pBitmap->CopyFromRenderTarget(BYVAL destPoint, renderTarget, BYVAL srcRect)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromRenderTarget (BYVAL destPointX AS const UINT32, BYVAL destPointY AS const UINT32, BYVAL renderTarget AS ID2D1RenderTarget PTR, _
   BYVAL srcRectLeft AS UINT32, BYVAL srcRectTop AS UINT32, BYVAL srcRectRight AS UINT32, BYVAL srcRectBottom AS UINT32) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   DIM destPoint AS D2D1_POINT_2U = (destPointX, destPointY)
   DIM srcRect AS D2D1_RECT_U = (srcRectLeft, srcRectTop, srcRectRight, srcRectBottom)
   RETURN m_pBitmap->CopyFromRenderTarget(destPoint, renderTarget, srcRect)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies the specified region from memory into the current bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromMemory (BYREF dstRect AS const D2D1_RECT_U, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   RETURN m_pBitmap->CopyFromMemory(dstRect, srcData, pitch)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromMemory (BYVAL dstRect AS const D2D1_RECT_U PTR, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   RETURN m_pBitmap->CopyFromMemory(BYVAL dstRect, srcData, pitch)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap.CopyFromMemory (BYVAL dstRectLeft AS UINT32, BYVAL dstRectTop AS UINT32, _
   BYVAL dstRectRight AS UINT32, BYVAL dstRectBottom AS UINT32, BYVAL srcData AS ANY PTR, BYVAL pitch AS UINT32) AS HRESULT
   IF m_pBitmap = NULL THEN RETURN E_POINTER
   DIM dstRect AS D2D1_RECT_U = (dstRectLeft, dstRectTop, dstRectRight, dstRectBottom)
   RETURN m_pBitmap->CopyFromMemory(dstRect, srcData, pitch)
END FUNCTION
' ========================================================================================

' ########################################################################################
' CID2D1Bitmap1 class
' Represents a bitmap that has been bound to an ID2D1RenderTarget.
' ########################################################################################

TYPE CID2D1Bitmap1 EXTENDS CID2D1Bitmap
Public:

   m_pBitmap1 AS ID2D1Bitmap1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pBitmap1 AS ID2D1Bitmap1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Bitmap1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Bitmap1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Image PTR

   ' // ID2D1Bitmap1 methods
   DECLARE FUNCTION GetColorContext () AS ID2D1ColorContext PTR
   DECLARE FUNCTION GetOptions () AS D2D1_BITMAP_OPTIONS
   DECLARE FUNCTION GetSurface () AS IDXGISurface PTR
   DECLARE FUNCTION Map (BYVAL options AS D2D1_MAP_OPTIONS) AS D2D1_MAPPED_RECT
   DECLARE FUNCTION Unmap () AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Bitmap1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Bitmap1
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Bitmap1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Bitmap1 (BYVAL pBitmap1 AS ID2D1Bitmap1 PTR)
   D2D1_DP("pBitmap1 - " & WSTR(pBitmap1))
   m_pBitmap1 = pBitmap1
   IF m_pBitmap1 THEN m_pBitmap1->AddRef
   IF m_pBitmap THEN m_pBitmap->Release
   m_pBitmap = m_pBitmap1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1Bitmap1
   D2D1_DP("m_pBitmap1: " & WSTR(m_pBitmap1))
   IF m_pBitmap1 THEN m_pBitmap1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Bitmap1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF bitmap1 AS CID2D1Bitmap1) AS ID2D1Bitmap1 PTR
   RETURN bitmap1.m_pBitmap1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Bitmap1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Bitmap1.@ () AS ID2D1Bitmap1 PTR PTR
   RETURN @m_pBitmap1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Bitmap1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Bitmap1.CAST () AS ID2D1Bitmap1 PTR
   RETURN m_pBitmap1
END OPERATOR
' ========================================================================================
' ========================================================================================
PRIVATE OPERATOR CID2D1Bitmap1.CAST () AS ID2D1Image PTR
   RETURN CAST(ID2D1Image PTR, m_pBitmap)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Gets the color context information associated with the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap1.GetColorContext () AS ID2D1ColorContext PTR
   IF m_pBitmap1 = NULL THEN RETURN NULL
   DIM colorContext AS ID2D1ColorContext PTR
   m_pBitmap1->GetColorContext(colorContext)
   RETURN colorContext
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the options used in creating the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap1.GetOptions () AS D2D1_BITMAP_OPTIONS
   IF m_pBitmap1 = NULL THEN EXIT FUNCTION
   RETURN m_pBitmap1->GetOptions
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets either the surface that was specified when the bitmap was created, or the default
' surface created when the bitmap was created.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap1.GetSurface () AS IDXGISurface PTR
   IF m_pBitmap1 = NULL THEN RETURN NULL
   DIM dxgiSurface AS IDXGISurface PTR
   m_pBitmap1->GetSurface(dxgiSurface)
   RETURN dxgiSurface
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps the given bitmap into memory.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap1.Map (BYVAL options AS D2D1_MAP_OPTIONS) AS D2D1_MAPPED_RECT
   IF m_pBitmap1 = NULL THEN EXIT FUNCTION
   DIM mappedRect AS D2D1_MAPPED_RECT
   SetLastError(m_pBitmap1->Map(options, mappedRect))
   RETURN mappedRect
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unnmaps the bitmap from memory.
' ========================================================================================
PRIVATE FUNCTION CID2D1Bitmap1.Unmap () AS HRESULT
   IF m_pBitmap1 = NULL THEN EXIT FUNCTION
   RETURN m_pBitmap1->Unmap
END FUNCTION
' ========================================================================================

' ########################################################################################
' ID2D1ColorContext class
' Represents a color context that can be used with an ID2D1Bitmap1 object.
' ########################################################################################

TYPE CID2D1ColorContext
Public:

   m_pColorContext AS ID2D1ColorContext PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pColorContext AS ID2D1ColorContext PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1ColorContext PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1ColorContext PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1ColorContext methods
   DECLARE FUNCTION GetColorSpace () AS D2D1_COLOR_SPACE
   DECLARE FUNCTION GetProfileSize () AS UINT32
   DECLARE FUNCTION GetProfile (BYVAL profile AS BYTE PTR, BYVAL profileSize AS UINT32) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the ID2D1ColorContext class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1ColorContext
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the ID2D1ColorContext class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1ColorContext (BYVAL pColorContext AS ID2D1ColorContext PTR)
   D2D1_DP("pColorContext - " & WSTR(pColorContext))
   m_pColorContext = pColorContext
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1ColorContext
   D2D1_DP("m_pColorContext: " & WSTR(m_pColorContext))
   IF m_pColorContext THEN m_pColorContext->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1ColorContext interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF colorContext AS CID2D1ColorContext) AS ID2D1ColorContext PTR
   RETURN colorContext.m_pColorContext
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1ColorContext interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ColorContext.@ () AS ID2D1ColorContext PTR PTR
   RETURN @m_pColorContext
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1ColorContext interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ColorContext.CAST () AS ID2D1ColorContext PTR
   RETURN m_pColorContext
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, m_pColorContext)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1ColorContext methods
' ========================================================================================
' ========================================================================================
' Gets the color space of the color context.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext.GetColorSpace () AS D2D1_COLOR_SPACE
   IF m_pColorContext = NULL THEN EXIT FUNCTION
   RETURN m_pColorContext->GetColorSpace
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the size of the color profile associated with the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext.GetProfileSize () AS UINT32
   IF m_pColorContext = NULL THEN EXIT FUNCTION
   RETURN m_pColorContext->GetProfileSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the size of the color profile associated with the bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext.GetProfile (BYVAL profile AS BYTE PTR, BYVAL profileSize AS UINT32) AS HRESULT
   IF m_pColorContext = NULL THEN EXIT FUNCTION
   RETURN m_pColorContext->GetProfile(profile, profileSize)
END FUNCTION
' ========================================================================================


' ########################################################################################
' ID2D1ColorContext1 class
' Represents a color context that can be used with an ID2D1Bitmap1 object.
' ########################################################################################

TYPE CID2D1ColorContext1 EXTENDS CID2D1ColorContext
Public:

   m_pColorContext1 AS ID2D1ColorContext1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pColorContext1 AS ID2D1ColorContext1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1ColorContext1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1ColorContext1 PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1ColorContext1 methods
   DECLARE FUNCTION GetColorContextType () AS D2D1_COLOR_CONTEXT_TYPE
   DECLARE FUNCTION GetDXGIColorSpace () AS DXGI_COLOR_SPACE_TYPE
   DECLARE FUNCTION GetSimpleColorProfile () AS D2D1_SIMPLE_COLOR_PROFILE

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the ID2D1ColorContext1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1ColorContext1
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the ID2D1ColorContext1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1ColorContext1 (BYVAL pColorContext1 AS ID2D1ColorContext1 PTR)
   D2D1_DP("pColorContext1 - " & WSTR(pColorContext1))
   m_pColorContext1 = pColorContext1
   IF m_pColorContext1 THEN m_pColorContext1->AddRef
   IF m_pColorContext THEN m_pColorContext->Release
   m_pColorContext = m_pColorContext1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1ColorContext1
   D2D1_DP("m_pColorContext1: " & WSTR(m_pColorContext1))
   IF m_pColorContext1 THEN m_pColorContext1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1ColorContext1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF colorContext AS CID2D1ColorContext1) AS ID2D1ColorContext1 PTR
   RETURN colorContext.m_pColorContext1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1ColorContext1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ColorContext1.@ () AS ID2D1ColorContext1 PTR PTR
   RETURN @m_pColorContext1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1ColorContext interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ColorContext1.CAST () AS ID2D1ColorContext1 PTR
   RETURN m_pColorContext1
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the color context type.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext1.GetColorContextType () AS D2D1_COLOR_CONTEXT_TYPE
   IF m_pColorContext1 = NULL THEN EXIT FUNCTION
   RETURN m_pColorContext1->GetColorContextType
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the DXGI color space of this context. Returns DXGI_COLOR_SPACE_CUSTOM when color context type is ICC.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext1.GetDXGIColorSpace () AS DXGI_COLOR_SPACE_TYPE
   IF m_pColorContext1 = NULL THEN EXIT FUNCTION
   RETURN m_pColorContext1->GetDXGIColorSpace
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the DXGI color space of this context. Returns DXGI_COLOR_SPACE_CUSTOM when color context type is ICC.
' ========================================================================================
PRIVATE FUNCTION CID2D1ColorContext1.GetSimpleColorProfile () AS D2D1_SIMPLE_COLOR_PROFILE
   IF m_pColorContext1 = NULL THEN EXIT FUNCTION
   DIM simpleProfile AS D2D1_SIMPLE_COLOR_PROFILE
   SetLastError(m_pColorContext1->GetSimpleColorProfile(simpleProfile))
   RETURN simpleProfile
END FUNCTION
' ========================================================================================
