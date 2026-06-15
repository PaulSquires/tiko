' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxD2D1Objects.inc
' Purpose:  D2D1 objects
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2026 José Roca
'
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

#pragma once
#include once "AfxNova/AfxD2D1.bi"

' ========================================================================================
' Macro for debug
' To allow debugging, define _D2D1_DEBUG_ 1 in your application before including this file.
' ========================================================================================
#ifndef _D2D1_DEBUG_
   #define _D2D1_DEBUG_ 0
#ENDIF
#ifndef _D2D1_DP_
   #define _D2D1_DP_ 1
   #MACRO D2D1_DP(st)
      #IF (_D2D1_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

NAMESPACE AfxNova

' ########################################################################################
' CD2D1Factory class
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory
Public:

   m_pFactory AS ID2D1Factory PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR
   DECLARE SUB GetDesktopDpi (BYREF dpiX AS SINGLE, BYREF dpiY AS SINGLE)
   DECLARE SUB GetDesktopDpi (BYVAL dpiX AS SINGLE PTR, BYVAL dpiY AS SINGLE PTR)
   DECLARE FUNCTION GetDpi () AS SINGLE
   DECLARE FUNCTION GetDpiX () AS SINGLE
   DECLARE FUNCTION GetDpiY () AS SINGLE
   DECLARE FUNCTION ReloadSystemMetrics () AS HRESULT
   DECLARE FUNCTION CreateRectangleGeometry (BYREF rectangle AS D2D1_RECT_F) AS ID2D1RectangleGeometry PTR
   DECLARE FUNCTION CreateRectangleGeometry (BYVAL rectangle AS D2D1_RECT_F PTR) AS ID2D1RectangleGeometry PTR
   DECLARE FUNCTION CreateRoundedRectangleGeometry (BYREF roundedRectangle AS D2D1_ROUNDED_RECT) AS ID2D1RoundedRectangleGeometry PTR
   DECLARE FUNCTION CreateRoundedRectangleGeometry (BYVAL roundedRectangle AS D2D1_ROUNDED_RECT PTR) AS ID2D1RoundedRectangleGeometry PTR
   DECLARE FUNCTION CreateEllipseGeometry (BYREF ellipse AS const D2D1_ELLIPSE) AS ID2D1EllipseGeometry PTR
   DECLARE FUNCTION CreateEllipseGeometry (BYVAL ellipse AS const D2D1_ELLIPSE PTR) AS ID2D1EllipseGeometry PTR
   DECLARE FUNCTION CreateGeometryGroup (BYVAL fillMode AS D2D1_FILL_MODE, BYVAL geometries AS ID2D1Geometry PTR, _
           BYVAL geometriesCount AS UINT32) AS ID2D1GeometryGroup PTR
   DECLARE FUNCTION CreateTransformedGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR, BYREF transform AS D2D1_MATRIX_3X2_F) AS ID2D1TransformedGeometry PTR
   DECLARE FUNCTION CreateTransformedGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR, BYVAL transform AS D2D1_MATRIX_3X2_F PTR) AS ID2D1TransformedGeometry PTR
   DECLARE FUNCTION CreatePathGeometry () AS ID2D1PathGeometry PTR
   DECLARE FUNCTION CreateStrokeStyle (BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES, _
           BYREF dashes AS const FLOAT, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle PTR
   DECLARE FUNCTION CreateStrokeStyle (BYVAL strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES PTR, _
           BYVAL dashes AS const FLOAT PTR, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle PTR
   DECLARE FUNCTION CreateDrawingStateBlock (BYREF drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION, _
           BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock PTR
   DECLARE FUNCTION CreateDrawingStateBlock (BYVAL drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION PTR, _
           BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock PTR
   DECLARE FUNCTION CreateDrawingStateBlock (BYREF drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION) AS ID2D1DrawingStateBlock PTR
   DECLARE FUNCTION CreateDrawingStateBlock (BYVAL drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION PTR) AS ID2D1DrawingStateBlock PTR
   DECLARE FUNCTION CreateDrawingStateBlock () AS ID2D1DrawingStateBlock PTR
   DECLARE FUNCTION CreateWicBitmapRenderTarget (BYVAL target AS IWICBitmap PTR, _
           BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES) AS ID2D1RenderTarget PTR
   DECLARE FUNCTION CreateWicBitmapRenderTarget (BYVAL target AS IWICBitmap PTR, _
           BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR) AS ID2D1RenderTarget PTR
   DECLARE FUNCTION CreateHwndRenderTarget (BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES, _
           BYREF hwndRenderTargetProperties AS D2D1_HWND_RENDER_TARGET_PROPERTIES) AS ID2D1HwndRenderTarget PTR
   DECLARE FUNCTION CreateHwndRenderTarget (BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR, _
           BYVAL hwndRenderTargetProperties AS D2D1_HWND_RENDER_TARGET_PROPERTIES PTR) AS ID2D1HwndRenderTarget PTR
   DECLARE FUNCTION CreateDxgiSurfaceRenderTarget (BYVAL dxgiSurface AS IDXGISurface PTR, _
           BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES) AS ID2D1RenderTarget PTR
   DECLARE FUNCTION CreateDxgiSurfaceRenderTarget (BYVAL dxgiSurface AS IDXGISurface PTR, _
           BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR) AS ID2D1RenderTarget PTR
   DECLARE FUNCTION CreateDCRenderTarget (BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES) AS ID2D1DCRenderTarget PTR
   DECLARE FUNCTION CreateDCRenderTarget (BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR) AS ID2D1DCRenderTarget PTR
   DECLARE FUNCTION CreateDCRenderTarget (BYVAL targetType AS D2D1_RENDER_TARGET_TYPE = D2D1_RENDER_TARGET_TYPE_DEFAULT,  _
           BYVAL pixelFormat AS DXGI_FORMAT = DXGI_FORMAT_B8G8R8A8_UNORM, BYVAL alphaMode AS D2D1_ALPHA_MODE = D2D1_ALPHA_MODE_IGNORE,  _
           BYVAL dpiX AS SINGLE = -1, BYVAL dpiY AS SINGLE = -1, BYVAL usage AS D2D1_RENDER_TARGET_USAGE = D2D1_RENDER_TARGET_USAGE_NONE, _
           BYVAL minLevel AS D2D1_FEATURE_LEVEL = D2D1_FEATURE_LEVEL_DEFAULT) AS ID2D1DCRenderTarget PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory
   D2D1_DP("Default constructor - m_pFactory = " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory, BYVAL NULL, m_pFactory))
   D2D1_DP("m_pFactory - " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory
   D2D1_DP("m_pFactory: " & WSTR(m_pFactory))
   IF m_pFactory THEN m_pFactory->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory) AS ID2D1Factory PTR
   RETURN factory.m_pFactory
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory.@ () AS ID2D1Factory PTR PTR
   RETURN @m_pFactory
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory.CAST () AS ID2D1Factory PTR
   RETURN m_pFactory
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns the DPI value
' ========================================================================================
PRIVATE SUB CD2D1Factory.GetDesktopDpi (BYREF dpiX AS SINGLE, BYREF dpiY AS SINGLE)
   m_pFactory->GetDesktopDpi(dpiX, dpiY)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CD2D1Factory.GetDesktopDpi (BYVAL dpiX AS SINGLE PTR, BYVAL dpiY AS SINGLE PTR)
   m_pFactory->GetDesktopDpi(BYVAL dpiX, BYVAL dpiY)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.GetDpi () AS SINGLE
   IF m_pFactory = NULL THEN RETURN 0
   DIM AS SINGLE dpix, dpiY
   m_pFactory->GetDesktopDpi(dpiX, dpiY)
   RETURN dpix
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns the horizontal DPI value of the desktop
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.GetDpiX () AS SINGLE
   IF m_pFactory = NULL THEN RETURN 0
   DIM AS SINGLE dpiX, dpiY
   m_pFactory->GetDesktopDpi(dpiX, dpiY)
   RETURN dpiX
END FUNCTION
' ========================================================================================
' ========================================================================================
' Returns the vertical DPI value of the desktop
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.GetDpiY () AS SINGLE
   IF m_pFactory = NULL THEN RETURN 0
   DIM AS SINGLE dpiX, dpiY
   m_pFactory->GetDesktopDpi(dpiX, dpiY)
   RETURN dpiY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Forces the factory to refresh any system defaults that it might have changed since factory creation.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.ReloadSystemMetrics () AS HRESULT
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN E_POINTER
   RETURN m_pFactory->ReloadSystemMetrics
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1RectangleGeometry.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateRectangleGeometry (BYREF rectangle AS D2D1_RECT_F) AS ID2D1RectangleGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM rectangleGeometry AS ID2D1RectangleGeometry PTR
   SetLastError(m_pFactory->CreateRectangleGeometry(rectangle, rectangleGeometry))
   RETURN rectangleGeometry
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateRectangleGeometry (BYVAL rectangle AS D2D1_RECT_F PTR) AS ID2D1RectangleGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM rectangleGeometry AS ID2D1RectangleGeometry PTR
   SetLastError(m_pFactory->CreateRectangleGeometry(BYVAL rectangle, rectangleGeometry))
   RETURN rectangleGeometry
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1RoundedRectangleGeometry.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateRoundedRectangleGeometry (BYREF roundedRectangle AS D2D1_ROUNDED_RECT) AS ID2D1RoundedRectangleGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM roundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR
   SetLastError(m_pFactory->CreateRoundedRectangleGeometry(roundedRectangle, roundedRectangleGeometry))
   RETURN roundedRectangleGeometry
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateRoundedRectangleGeometry (BYVAL roundedRectangle AS D2D1_ROUNDED_RECT PTR) AS ID2D1RoundedRectangleGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM roundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR
   SetLastError(m_pFactory->CreateRoundedRectangleGeometry(BYVAL roundedRectangle, roundedRectangleGeometry))
   RETURN roundedRectangleGeometry
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1EllipseGeometry.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateEllipseGeometry (BYREF ellipse AS const D2D1_ELLIPSE) AS ID2D1EllipseGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM ellipseGeometry AS ID2D1EllipseGeometry PTR
   SetLastError(m_pFactory->CreateEllipseGeometry(ellipse, ellipseGeometry))
   RETURN ellipseGeometry
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateEllipseGeometry (BYVAL ellipse AS const D2D1_ELLIPSE PTR) AS ID2D1EllipseGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM ellipseGeometry AS ID2D1EllipseGeometry PTR
   SetLastError(m_pFactory->CreateEllipseGeometry(BYVAL ellipse, ellipseGeometry))
   RETURN ellipseGeometry
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1GeometryGroup, which is an object that holds other geometries.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateGeometryGroup (BYVAL fillMode AS D2D1_FILL_MODE, BYVAL geometries AS ID2D1Geometry PTR, _
BYVAL geometriesCount AS UINT32) AS ID2D1GeometryGroup PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM geometryGroup AS ID2D1GeometryGroup PTR
   SetLastError(m_pFactory->CreateGeometryGroup(fillMode, geometries, geometriesCount, geometryGroup))
   RETURN geometryGroup
END FUNCTION
' ========================================================================================

' ========================================================================================
' Transforms the specified geometry and stores the result as an ID2D1TransformedGeometry object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateTransformedGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR, _
BYREF transform AS D2D1_MATRIX_3X2_F) AS ID2D1TransformedGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM transformedGeometry AS ID2D1TransformedGeometry PTR
   SetLastError(m_pFactory->CreateTransformedGeometry(sourceGeometry, transform, transformedGeometry))
   RETURN transformedGeometry
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateTransformedGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR, _
BYVAL transform AS D2D1_MATRIX_3X2_F PTR) AS ID2D1TransformedGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM transformedGeometry AS ID2D1TransformedGeometry PTR
   SetLastError(m_pFactory->CreateTransformedGeometry(sourceGeometry, BYVAL transform, transformedGeometry))
   RETURN transformedGeometry
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an empty ID2D1PathGeometry.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreatePathGeometry () AS ID2D1PathGeometry PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM pathGeometry AS ID2D1PathGeometry PTR
   SetLastError(m_pFactory->CreatePathGeometry(pathGeometry))
   RETURN pathGeometry
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1StrokeStyle that describes start cap, dash pattern, and other features of a stroke.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateStrokeStyle (BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES, _
BYREF dashes AS const FLOAT, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM strokeStyle AS ID2D1StrokeStyle PTR
   SetLastError(m_pFactory->CreateStrokeStyle(strokeStyleProperties, dashes, dashesCount, strokeStyle))
   RETURN strokeStyle
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateStrokeStyle (BYVAL strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES PTR, _
BYVAL dashes AS const FLOAT PTR, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM strokeStyle AS ID2D1StrokeStyle PTR
   SetLastError(m_pFactory->CreateStrokeStyle(BYVAL strokeStyleProperties, BYVAL dashes, dashesCount, strokeStyle))
   RETURN strokeStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1DrawingStateBlock that can be used with the SaveDrawingState and
' RestoreDrawingState methods of a render target.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDrawingStateBlock (BYREF drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION, _
BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock PTR
   SetLastError(m_pFactory->CreateDrawingStateBlock(drawingStateDescription, textRenderingParams, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDrawingStateBlock (BYVAL drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION PTR, _
BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock PTR
   SetLastError(m_pFactory->CreateDrawingStateBlock(BYVAL drawingStateDescription, textRenderingParams, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================
  ' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDrawingStateBlock (BYREF drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION) AS ID2D1DrawingStateBlock PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock PTR
   SetLastError(m_pFactory->CreateDrawingStateBlock(drawingStateDescription, NULL, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDrawingStateBlock (BYVAL drawingStateDescription AS const D2D1_DRAWING_STATE_DESCRIPTION PTR) AS ID2D1DrawingStateBlock PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock PTR
   SetLastError(m_pFactory->CreateDrawingStateBlock(BYVAL drawingStateDescription, NULL, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDrawingStateBlock () AS ID2D1DrawingStateBlock PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock PTR
   SetLastError(m_pFactory->CreateDrawingStateBlock(BYVAL NULL, NULL, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a render target that renders to a Microsoft Windows Imaging Component (WIC) bitmap.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateWicBitmapRenderTarget (BYVAL target AS IWICBitmap PTR, _
BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES) AS ID2D1RenderTarget PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM renderTarget AS ID2D1RenderTarget PTR
   SetLastError(m_pFactory->CreateWicBitmapRenderTarget(target, renderTargetProperties, renderTarget))
   RETURN renderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateWicBitmapRenderTarget (BYVAL target AS IWICBitmap PTR, _
BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR) AS ID2D1RenderTarget PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM renderTarget AS ID2D1RenderTarget PTR
   SetLastError(m_pFactory->CreateWicBitmapRenderTarget(target, BYVAL renderTargetProperties, renderTarget))
   RETURN renderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1HwndRenderTarget, a render target that renders to a window.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateHwndRenderTarget (BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES, _
BYREF hwndRenderTargetProperties AS D2D1_HWND_RENDER_TARGET_PROPERTIES) AS ID2D1HwndRenderTarget PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM hwndRenderTarget AS ID2D1HwndRenderTarget PTR
   SetLastError(m_pFactory->CreateHwndRenderTarget(renderTargetProperties, hwndRenderTargetProperties, hwndRenderTarget))
   RETURN hwndRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateHwndRenderTarget (BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR, _
BYVAL hwndRenderTargetProperties AS D2D1_HWND_RENDER_TARGET_PROPERTIES PTR) AS ID2D1HwndRenderTarget PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM hwndRenderTarget AS ID2D1HwndRenderTarget PTR
   SetLastError(m_pFactory->CreateHwndRenderTarget(BYVAL renderTargetProperties, BYVAL hwndRenderTargetProperties, hwndRenderTarget))
   RETURN hwndRenderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a render target that draws to a DirectX Graphics Infrastructure (DXGI) surface.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDxgiSurfaceRenderTarget (BYVAL dxgiSurface AS IDXGISurface PTR, _
BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES) AS ID2D1RenderTarget PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM renderTarget AS ID2D1RenderTarget PTR
   SetLastError(m_pFactory->CreateDxgiSurfaceRenderTarget(dxgiSurface, renderTargetProperties, renderTarget))
   RETURN renderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDxgiSurfaceRenderTarget (BYVAL dxgiSurface AS IDXGISurface PTR, _
BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR) AS ID2D1RenderTarget PTR
   D2D1_DP("")
   IF m_pFactory = NULL THEN RETURN NULL
   DIM renderTarget AS ID2D1RenderTarget PTR
   SetLastError(m_pFactory->CreateDxgiSurfaceRenderTarget(dxgiSurface, BYVAL renderTargetProperties, renderTarget))
   RETURN renderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a render target that draws to a Windows Graphics Device Interface (GDI) device context.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDCRenderTarget (BYREF renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES) AS ID2D1DCRenderTarget PTR
   D2D1_DP("BYREF props: " & WSTR(VARPTR(renderTargetProperties)))
   IF m_pFactory = NULL THEN RETURN NULL
   DIM pRenderTarget AS ID2D1DCRenderTarget PTR
   SetLastError(m_pFactory->CreateDCRenderTarget(renderTargetProperties, pRenderTarget))
   D2D1_DP(WSTR(pRenderTarget))
   RETURN pRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDCRenderTarget (BYVAL renderTargetProperties AS D2D1_RENDER_TARGET_PROPERTIES PTR) AS ID2D1DCRenderTarget PTR
   D2D1_DP("BYVAL props: " & WSTR(renderTargetProperties))
   IF m_pFactory = NULL THEN RETURN NULL
   DIM pRenderTarget AS ID2D1DCRenderTarget PTR
   SetLastError(m_pFactory->CreateDCRenderTarget(BYVAL renderTargetProperties, pRenderTarget))
   D2D1_DP(WSTR(pRenderTarget))
   RETURN pRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory.CreateDCRenderTarget (BYVAL targetType AS D2D1_RENDER_TARGET_TYPE = D2D1_RENDER_TARGET_TYPE_DEFAULT,  _
BYVAL pixelFormat AS DXGI_FORMAT = DXGI_FORMAT_B8G8R8A8_UNORM, BYVAL alphaMode AS D2D1_ALPHA_MODE = D2D1_ALPHA_MODE_IGNORE,  _
BYVAL dpiX AS SINGLE = -1, BYVAL dpiY AS SINGLE = -1, BYVAL usage AS D2D1_RENDER_TARGET_USAGE = D2D1_RENDER_TARGET_USAGE_NONE, _
BYVAL minLevel AS D2D1_FEATURE_LEVEL = D2D1_FEATURE_LEVEL_DEFAULT) AS ID2D1DCRenderTarget PTR

   D2D1_DP("targetType: " & WSTR(targetType))
   IF m_pFactory = NULL THEN RETURN NULL
   ' // DPI values
   DIM AS SINGLE _dpiX, _dpiY
   m_pFactory->GetDesktopDpi(_dpiX, _dpiY)
   IF dpiX = -1 THEN dpiX = _dpiX
   IF dpiY = -1 THEN dpiY = _dpiY
   ' // Render target properties
   DIM props AS D2D1_RENDER_TARGET_PROPERTIES
   props.type = targetType
   props.pixelFormat = D2D1_PixelFormat(pixelFormat, alphaMode)
   props.dpiX = dpiX
   props.dpiY = dpiY
   props.usage = usage
   props.minLevel = minLevel
   ' // Create the render target
   DIM pRenderTarget AS ID2D1DCRenderTarget PTR
   SetLastError(m_pFactory->CreateDCRenderTarget(props, pRenderTarget))
   D2D1_DP(WSTR(pRenderTarget))
   RETURN pRenderTarget

END FUNCTION
' ========================================================================================

' ########################################################################################
' CD2D1Factory1 class
' Creates Direct2D resources.
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory1 EXTENDS CD2D1Factory
Public:

   m_pFactory1 AS ID2D1Factory1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device PTR
   DECLARE FUNCTION CreateStrokeStyle1 (BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES1, _
           BYREF dashes AS const FLOAT, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle1 PTR
   DECLARE FUNCTION CreateStrokeStyle1 (BYVAL strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES1 PTR, _
           BYREF dashes AS const FLOAT PTR, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle1 PTR
   DECLARE FUNCTION CreatePathGeometry1 () AS ID2D1PathGeometry1 PTR
   DECLARE FUNCTION CreateDrawingStateBlock1 (BYREF drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1, _
           BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock1 PTR
   DECLARE FUNCTION CreateDrawingStateBlock1 (BYVAL drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR, _
           BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock1 PTR
   DECLARE FUNCTION CreateDrawingStateBlock1 (BYREF drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1) AS ID2D1DrawingStateBlock1 PTR
   DECLARE FUNCTION CreateDrawingStateBlock1 (BYVAL drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR) AS ID2D1DrawingStateBlock1 PTR
   DECLARE FUNCTION CreateDrawingStateBlock1 () AS ID2D1DrawingStateBlock1 PTR
   DECLARE FUNCTION CreateGdiMetafile (BYVAL metafileStream AS IStream PTR) AS ID2D1GdiMetafile PTR
   DECLARE FUNCTION RegisterEffectFromStream (BYREF ClassId AS CLSID, BYVAL propertyXml AS IStream PTR, _
           BYREF bindings AS const D2D1_PROPERTY_BINDING, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   DECLARE FUNCTION RegisterEffectFromStream (BYVAL ClassId AS CLSID PTR, BYVAL propertyXml AS IStream PTR, _
           BYVAL bindings AS const D2D1_PROPERTY_BINDING PTR, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   DECLARE FUNCTION RegisterEffectFromString (BYREF ClassId AS CLSID, BYREF propertyXml AS WSTRING, _
           BYREF bindings AS const D2D1_PROPERTY_BINDING, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   DECLARE FUNCTION RegisterEffectFromString (BYVAL ClassId AS CLSID PTR, BYREF propertyXml AS WSTRING, _
           BYVAL bindings AS const D2D1_PROPERTY_BINDING PTR, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   DECLARE FUNCTION GetRegisteredEffects (BYREF effects AS CLSID, BYVAL effectsCount AS UINT32, _
           BYREF effectsReturned AS UINT32, BYREF effectsRegistered AS UINT32) AS HRESULT
   DECLARE FUNCTION GetRegisteredEffects (BYVAL effects AS CLSID PTR, BYVAL effectsCount AS UINT32, _
           BYVAL effectsReturned AS UINT32 PTR, BYVAL effectsRegistered AS UINT32 PTR) AS HRESULT
   DECLARE FUNCTION UnregisterEffect (BYREF ClassId AS CLSID) AS HRESULT
   DECLARE FUNCTION UnregisterEffect (BYVAL ClassId AS CLSID PTR) AS HRESULT
   DECLARE FUNCTION GetEffectProperties (BYREF effectId AS CLSID) AS ID2D1Properties PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory1 class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory1
   D2D1_DP("Default constructor - m_pFactory1 = " & WSTR(m_pFactory1))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory1 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory1 interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory1, BYVAL NULL, m_pFactory1))
   D2D1_DP("m_pFactory1 - " & WSTR(m_pFactory1))
   ' // Increment the reference count
   IF m_pFactory1 THEN m_pFactory1->AddRef
   ' // Release the base factory if there is one
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END iF
   ' // Assign the new factory pointer to the base class
   m_pFactory = m_pFactory1
   D2D1_DP("Assign new factory: " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory1
   D2D1_DP("m_pFactory1: " & WSTR(m_pFactory1))
   IF m_pFactory1 THEN m_pFactory1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory1) AS ID2D1Factory1 PTR
   RETURN factory.m_pFactory1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory1.@ () AS ID2D1Factory1 PTR PTR
   RETURN @m_pFactory1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory1.CAST () AS ID2D1Factory1 PTR
   RETURN m_pFactory1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory1.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory1)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateDevice (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM d2dDevice AS ID2D1Device PTR
   SetLastError(m_pFactory1->CreateDevice(dxgiDevice, d2dDevice))
   RETURN d2dDevice
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a ID2D1StrokeStyle1 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateStrokeStyle1 (BYREF strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES1, _
BYREF dashes AS const FLOAT, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM strokeStyle AS ID2D1StrokeStyle1 PTR
   SetLastError(m_pFactory1->CreateStrokeStyle1(strokeStyleProperties, dashes, dashescount, strokeStyle))
   RETURN strokeStyle
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateStrokeStyle1 (BYVAL strokeStyleProperties AS D2D1_STROKE_STYLE_PROPERTIES1 PTR, _
BYREF dashes AS const FLOAT PTR, BYVAL dashesCount AS UINT32) AS ID2D1StrokeStyle1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM strokeStyle AS ID2D1StrokeStyle1 PTR
   SetLastError(m_pFactory1->CreateStrokeStyle1(BYVAL strokeStyleProperties, BYVAL dashes, dashescount, strokeStyle))
   RETURN strokeStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1PathGeometry1 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreatePathGeometry1 () AS ID2D1PathGeometry1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM pathGeometry AS ID2D1PathGeometry1 PTR
   SetLastError(m_pFactory1->CreatePathGeometry1(pathGeometry))
   RETURN pathGeometry
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new drawing state block, this can be used in subsequent SaveDrawingState and
' RestoreDrawingState operations on the render target.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateDrawingStateBlock1 (BYREF drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1, _
BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock1 PTR
   SetLastError(m_pFactory1->CreateDrawingStateBlock1(drawingStateDescription, textRenderingParams, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateDrawingStateBlock1 (BYVAL drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR, _
BYVAL textRenderingParams AS IDWriteRenderingParams PTR) AS ID2D1DrawingStateBlock1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock1 PTR
   SetLastError(m_pFactory1->CreateDrawingStateBlock(BYVAL drawingStateDescription, textRenderingParams, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateDrawingStateBlock1 (BYREF drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1) AS ID2D1DrawingStateBlock1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock1 PTR
   SetLastError(m_pFactory1->CreateDrawingStateBlock1(drawingStateDescription, BYVAL NULL, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateDrawingStateBlock1 (BYVAL drawingStateDescription AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR) AS ID2D1DrawingStateBlock1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock1 PTR
   SetLastError(m_pFactory1->CreateDrawingStateBlock1(BYVAL drawingStateDescription, BYVAL NULL, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateDrawingStateBlock1 () AS ID2D1DrawingStateBlock1 PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM drawingStateBlock AS ID2D1DrawingStateBlock1 PTR
   SetLastError(m_pFactory1->CreateDrawingStateBlock1(BYVAL NULL, BYVAL NULL, drawingStateBlock))
   RETURN drawingStateBlock
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new ID2D1GdiMetafile object that you can use to replay metafile content.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.CreateGdiMetafile (BYVAL metafileStream AS IStream PTR) AS ID2D1GdiMetafile PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM metafile AS ID2D1GdiMetafile PTR
   SetLastError(m_pFactory1->CreateGdiMetafile(metafileStream, metafile))
   RETURN metafile
END FUNCTION
' ========================================================================================

' ========================================================================================
' Registers an effect within the factory instance with the property XML specified as a stream.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.RegisterEffectFromStream (BYREF ClassId AS CLSID, BYVAL propertyXml AS IStream PTR, _
BYREF bindings AS const D2D1_PROPERTY_BINDING, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->RegisterEffectFromStream(ClassId, propertyXml, bindings, bindingsCount, effectFactory))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.RegisterEffectFromStream (BYVAL ClassId AS CLSID PTR, BYVAL propertyXml AS IStream PTR, _
BYVAL bindings AS const D2D1_PROPERTY_BINDING PTR, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->RegisterEffectFromStream(BYVAL ClassId, propertyXml, BYVAL bindings, bindingsCount, effectFactory))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Registers an effect within the factory instance with the property XML specified as a string.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.RegisterEffectFromString (BYREF ClassId AS CLSID, BYREF propertyXml AS WSTRING, _
BYREF bindings AS const D2D1_PROPERTY_BINDING, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->RegisterEffectFromString(ClassId, propertyXml, bindings, bindingsCount, effectFactory))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.RegisterEffectFromString (BYVAL ClassId AS CLSID PTR, BYREF propertyXml AS WSTRING, _
BYVAL bindings AS const D2D1_PROPERTY_BINDING PTR, BYVAL bindingsCount AS UINT32, BYVAL effectFactory AS const PD2D1_EFFECT_FACTORY) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->RegisterEffectFromString(BYVAL ClassId, propertyXml, BYVAL bindings, bindingsCount, effectFactory))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unregisters an effect within the factory instance that corresponds to the classId provided.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.UnregisterEffect (BYREF ClassId AS CLSID) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->UnregisterEffect(ClassId))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.UnregisterEffect (BYVAL ClassId AS CLSID PTR) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->UnregisterEffect(BYVAL ClassId))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the class IDs of the currently registered effects and global effects on this factory.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.GetRegisteredEffects (BYREF effects AS CLSID, BYVAL effectsCount AS UINT32, _
BYREF effectsReturned AS UINT32, BYREF effectsRegistered AS UINT32) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->GetRegisteredEffects(effects, effectsCount, effectsReturned, effectsRegistered))
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.GetRegisteredEffects (BYVAL effects AS CLSID PTR, BYVAL effectsCount AS UINT32, _
BYVAL effectsReturned AS UINT32 PTR, BYVAL effectsRegistered AS UINT32 PTR) AS HRESULT
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN E_POINTER
   RETURN(m_pFactory1->GetRegisteredEffects(BYVAL effects, effectsCount, BYVAL effectsReturned, BYVAL effectsRegistered))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the properties of an effect.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory1.GetEffectProperties (BYREF effectId AS CLSID) AS ID2D1Properties PTR
   D2D1_DP("")
   IF m_pFactory1 = NULL THEN RETURN NULL
   DIM d2d1properties AS ID2D1Properties PTR
   SetLastError(m_pFactory1->GetEffectProperties(effectId, d2d1properties))
   RETURN d2d1properties
END FUNCTION
' ========================================================================================

' ########################################################################################
' CD2D1Factory2 class
' Creates Direct2D resources.
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory2 EXTENDS CD2D1Factory1
Public:

   m_pFactory2 AS ID2D1Factory2 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory2 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory2 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice1 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device1 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory2 class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory2
   D2D1_DP("Default constructor - m_pFactory2 = " & WSTR(m_pFactory2))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory2 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory2 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory2 interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory2, BYVAL NULL, m_pFactory2))
   D2D1_DP("m_pFactory2 - " & WSTR(m_pFactory2))
   ' // Release the inherited factories
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END iF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END iF
   ' // Assign the new factory pointer to the inherited factories
   IF m_pFactory2 THEN m_pFactory2->AddRef
   m_pFactory1 = m_pFactory2
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))
   IF m_pFactory2 THEN m_pFactory2->AddRef
   m_pFactory = m_pFactory2
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory2
   D2D1_DP("m_pFactory2: " & WSTR(m_pFactory2))
   IF m_pFactory2 THEN m_pFactory2->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory2 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory2) AS ID2D1Factory2 PTR
   RETURN factory.m_pFactory2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory2 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory2.@ () AS ID2D1Factory2 PTR PTR
   RETURN @m_pFactory2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory2 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory2.CAST () AS ID2D1Factory2 PTR
   RETURN m_pFactory2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory2.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory2)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device1 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory2.CreateDevice1 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device1 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory2 = NULL THEN RETURN NULL
   DIM d2dDevice1 AS ID2D1Device1 PTR
   SetLastError(m_pFactory2->CreateDevice(dxgiDevice, d2dDevice1))
   RETURN d2dDevice1
END FUNCTION
' ========================================================================================

' ########################################################################################
' CD2D1Factory3 class
' Creates Direct2D resources.
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory3 EXTENDS CD2D1Factory2
Public:

   m_pFactory3 AS ID2D1Factory3 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory3 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory3 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice2 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device2 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory3 class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory3
   D2D1_DP("Default constructor - m_pFactory3 = " & WSTR(m_pFactory3))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory3 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory3 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory2 interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory3, BYVAL NULL, m_pFactory3))
   D2D1_DP("m_pFactory3 - " & WSTR(m_pFactory3))
   ' // Release the inherited factories
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END iF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END iF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END iF
   ' // Assign the new factory pointer to the inherited factories
   IF m_pFactory3 THEN m_pFactory3->AddRef
   m_pFactory2 = m_pFactory3
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))
   IF m_pFactory3 THEN m_pFactory3->AddRef
   m_pFactory1 = m_pFactory3
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))
   IF m_pFactory3 THEN m_pFactory3->AddRef
   m_pFactory = m_pFactory3
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory3
   D2D1_DP("m_pFactory3: " & WSTR(m_pFactory3))
   IF m_pFactory3 THEN m_pFactory3->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory3 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory3) AS ID2D1Factory3 PTR
   RETURN factory.m_pFactory3
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory3 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory3.@ () AS ID2D1Factory3 PTR PTR
   RETURN @m_pFactory3
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory3 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory3.CAST () AS ID2D1Factory3 PTR
   RETURN m_pFactory3
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory3.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory3)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device1 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory3.CreateDevice2 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device2 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory3 = NULL THEN RETURN NULL
   DIM d2dDevice2 AS ID2D1Device2 PTR
   SetLastError(m_pFactory3->CreateDevice2(dxgiDevice, d2dDevice2))
   RETURN d2dDevice2
END FUNCTION
' ========================================================================================


' ########################################################################################
' CD2D1Factory4 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory4 EXTENDS CD2D1Factory3
Public:

   m_pFactory4 AS ID2D1Factory4 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory4 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory4 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice3 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device3 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory4
   D2D1_DP("Default constructor - m_pFactory4 = " & WSTR(m_pFactory4))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory4 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory4 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory4
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory4, BYVAL NULL, m_pFactory4))
   D2D1_DP("m_pFactory4 - " & WSTR(m_pFactory4))
   ' // Release inherited factories
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory3 = m_pFactory4
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory2 = m_pFactory4
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory1 = m_pFactory4
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory = m_pFactory4
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory4
   D2D1_DP("m_pFactory4: " & WSTR(m_pFactory4))
   IF m_pFactory4 THEN m_pFactory4->Release
END DESTRUCTOR
' =================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory4 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory4) AS ID2D1Factory4 PTR
   RETURN factory.m_pFactory4
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory4 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory4.@ () AS ID2D1Factory4 PTR PTR
   RETURN @m_pFactory4
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory4 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory4.CAST () AS ID2D1Factory4 PTR
   RETURN m_pFactory4
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory4.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory4)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device3 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory4.CreateDevice3 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device3 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory4 = NULL THEN RETURN NULL
   DIM d2dDevice3 AS ID2D1Device3 PTR
   SetLastError(m_pFactory4->CreateDevice3(dxgiDevice, d2dDevice3))
   RETURN d2dDevice3
END FUNCTION
' =================================================================================

' ########################################################################################
' CD2D1Factory5 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory5 EXTENDS CD2D1Factory4
Public:

   m_pFactory5 AS ID2D1Factory5 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory5 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory5 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice4 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device4 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory5
   D2D1_DP("Default constructor - m_pFactory5 = " & WSTR(m_pFactory5))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory5 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory5 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory5
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory5, BYVAL NULL, m_pFactory5))
   D2D1_DP("m_pFactory5 - " & WSTR(m_pFactory5))
   ' // Release inherited factories
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory4 = m_pFactory5
   D2D1_DP("Assign m_pFactory4: " & WSTR(m_pFactory4))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory3 = m_pFactory5
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory2 = m_pFactory5
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory1 = m_pFactory5
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory = m_pFactory5
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory5
   D2D1_DP("m_pFactory5: " & WSTR(m_pFactory5))
   IF m_pFactory5 THEN m_pFactory5->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory5 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory5) AS ID2D1Factory5 PTR
   RETURN factory.m_pFactory5
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory5 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory5.@ () AS ID2D1Factory5 PTR PTR
   RETURN @m_pFactory5
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory5 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory5.CAST () AS ID2D1Factory5 PTR
   RETURN m_pFactory5
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory5.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory5)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device4 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory5.CreateDevice4 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device4 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory5 = NULL THEN RETURN NULL
   DIM d2dDevice4 AS ID2D1Device4 PTR
   SetLastError(m_pFactory5->CreateDevice4(dxgiDevice, d2dDevice4))
   RETURN d2dDevice4
END FUNCTION
' ========================================================================================

' ########################################################################################
' CD2D1Factory6 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory6 EXTENDS CD2D1Factory5
Public:

   m_pFactory6 AS ID2D1Factory6 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory6 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory6 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice5 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device5 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory6
   D2D1_DP("Default constructor - m_pFactory6 = " & WSTR(m_pFactory6))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory6 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory6 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory6
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory6, BYVAL NULL, m_pFactory6))
   D2D1_DP("m_pFactory6 - " & WSTR(m_pFactory6))
   ' // Release inherited factories
   IF m_pFactory5 THEN
      m_pFactory5->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory5))
   END IF
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory5 = m_pFactory6
   D2D1_DP("Assign m_pFactory5: " & WSTR(m_pFactory5))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory4 = m_pFactory6
   D2D1_DP("Assign m_pFactory4: " & WSTR(m_pFactory4))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory3 = m_pFactory6
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory2 = m_pFactory6
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory1 = m_pFactory6
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory = m_pFactory6
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory6
   D2D1_DP("m_pFactory6: " & WSTR(m_pFactory6))
   IF m_pFactory6 THEN m_pFactory6->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory6 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory6) AS ID2D1Factory6 PTR
   RETURN factory.m_pFactory6
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory6 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory6.@ () AS ID2D1Factory6 PTR PTR
   RETURN @m_pFactory6
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory6 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory6.CAST () AS ID2D1Factory6 PTR
   RETURN m_pFactory6
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory6.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory6)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device5 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory6.CreateDevice5 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device5 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory6 = NULL THEN RETURN NULL
   DIM d2dDevice5 AS ID2D1Device5 PTR
   SetLastError(m_pFactory6->CreateDevice5(dxgiDevice, d2dDevice5))
   RETURN d2dDevice5
END FUNCTION
' ========================================================================================


' ########################################################################################
' CD2D1Factory7 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory7 EXTENDS CD2D1Factory6
Public:

   m_pFactory7 AS ID2D1Factory7 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory7 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory7 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice6 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device6 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory7
   D2D1_DP("Default constructor - m_pFactory7 = " & WSTR(m_pFactory7))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory7 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory7 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory7
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory7, BYVAL NULL, m_pFactory7))
   D2D1_DP("m_pFactory7 - " & WSTR(m_pFactory7))
   ' // Release inherited factories
   IF m_pFactory6 THEN
      m_pFactory6->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory6))
   END IF
   IF m_pFactory5 THEN
      m_pFactory5->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory5))
   END IF
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory7 THEN m_pFactory7->AddRef
   m_pFactory6 = m_pFactory7
   D2D1_DP("Assign m_pFactory6: " & WSTR(m_pFactory6))

   IF m_pFactory7 THEN m_pFactory7->AddRef
   m_pFactory = m_pFactory7
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory7
   D2D1_DP("m_pFactory7: " & WSTR(m_pFactory7))
   IF m_pFactory7 THEN m_pFactory7->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory7 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory7) AS ID2D1Factory7 PTR
   RETURN factory.m_pFactory7
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory7 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory7.@ () AS ID2D1Factory7 PTR PTR
   RETURN @m_pFactory7
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory7 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory7.CAST () AS ID2D1Factory7 PTR
   RETURN m_pFactory7
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory7.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory7)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device6 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory7.CreateDevice6 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device6 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory7 = NULL THEN RETURN NULL
   DIM d2dDevice6 AS ID2D1Device6 PTR
   SetLastError(m_pFactory7->CreateDevice6(dxgiDevice, d2dDevice6))
   RETURN d2dDevice6
END FUNCTION
' ========================================================================================


' ########################################################################################
' CD2D1Factory8 class
' Creates Direct2D resources.
' Not yet implemented.
' ########################################################################################

TYPE CD2D1Factory8 EXTENDS CD2D1Factory7
Public:

   m_pFactory8 AS ID2D1Factory8 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory8 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory8 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

   DECLARE FUNCTION CreateDevice7 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device7 PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory8
   D2D1_DP("Default constructor - m_pFactory8 = " & WSTR(m_pFactory8))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory8 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory8 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory8
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory8, BYVAL NULL, m_pFactory8))
   D2D1_DP("m_pFactory8 - " & WSTR(m_pFactory8))
   ' // Release inherited factories
   IF m_pFactory7 THEN
      m_pFactory7->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory7))
   END IF
   IF m_pFactory6 THEN
      m_pFactory6->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory6))
   END IF
   IF m_pFactory5 THEN
      m_pFactory5->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory5))
   END IF
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory7 = m_pFactory8
   D2D1_DP("Assign m_pFactory7: " & WSTR(m_pFactory7))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory6 = m_pFactory8
   D2D1_DP("Assign m_pFactory6: " & WSTR(m_pFactory6))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory5 = m_pFactory8
   D2D1_DP("Assign m_pFactory5: " & WSTR(m_pFactory5))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory4 = m_pFactory8
   D2D1_DP("Assign m_pFactory4: " & WSTR(m_pFactory4))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory3 = m_pFactory8
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory2 = m_pFactory8
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory1 = m_pFactory8
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory = m_pFactory8
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory8
   D2D1_DP("m_pFactory8: " & WSTR(m_pFactory8))
   IF m_pFactory8 THEN m_pFactory8->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory8 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory8) AS ID2D1Factory8 PTR
   RETURN factory.m_pFactory8
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory8  interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory8 .@ () AS ID2D1Factory8  PTR PTR
   RETURN @m_pFactory8
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory8 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory8.CAST () AS ID2D1Factory8 PTR
   RETURN m_pFactory8
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory8.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory8)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a ID2D1Device7 object.
' ========================================================================================
PRIVATE FUNCTION CD2D1Factory8.CreateDevice7 (BYVAL dxgiDevice AS IDXGIDevice PTR) AS ID2D1Device7 PTR
   D2D1_DP("dxgiDevice: " & WSTR(dxgiDevice))
   IF m_pFactory8 = NULL THEN RETURN NULL
   DIM d2dDevice7 AS ID2D1Device7 PTR
   SetLastError(m_pFactory8->CreateDevice7(dxgiDevice, d2dDevice7))
   RETURN d2dDevice7
END FUNCTION
' ========================================================================================

' ########################################################################################
' CID2D1StrokeStyle class
' Describes the caps, miter limit, line join, and dash information for a stroke.
' ########################################################################################

TYPE CID2D1StrokeStyle
Public:

   m_pStrokeStyle AS ID2D1StrokeStyle PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pStrokeStyle AS ID2D1StrokeStyle PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1StrokeStyle PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1StrokeStyle PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1StrokeStyle
   DECLARE FUNCTION GetStartCap () AS D2D1_CAP_STYLE
   DECLARE FUNCTION GetEndCap () AS D2D1_CAP_STYLE
   DECLARE FUNCTION GetDashCap () AS D2D1_CAP_STYLE
   DECLARE FUNCTION GetMiterLimit () AS FLOAT
   DECLARE FUNCTION GetLineJoin () AS D2D1_LINE_JOIN
   DECLARE FUNCTION GetDashOffset () AS FLOAT
   DECLARE FUNCTION GetDashStyle () AS D2D1_DASH_STYLE
   DECLARE FUNCTION GetDashesCount () AS UINT32
   DECLARE SUB GetDashes (BYREF dashes AS FLOAT, BYVAL dashesCount AS UINT32)
   

END TYPE
' ========================================================================================


' ========================================================================================
' Creates an instance of the CID2D1StrokeStyle class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1StrokeStyle
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1StrokeStyle class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1StrokeStyle (BYVAL pStrokeStyle AS ID2D1StrokeStyle PTR)
   D2D1_DP("pStrokeStyle - " & WSTR(pStrokeStyle))
   m_pStrokeStyle = pStrokeStyle
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1StrokeStyle
   D2D1_DP("m_pStrokeStyle: " & WSTR(m_pStrokeStyle))
   IF m_pStrokeStyle THEN m_pStrokeStyle->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientStopCollection AS CID2D1StrokeStyle) AS ID2D1StrokeStyle PTR
   RETURN gradientStopCollection.m_pStrokeStyle
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1StrokeStyle interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1StrokeStyle.@ () AS ID2D1StrokeStyle PTR PTR
   RETURN @m_pStrokeStyle
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1StrokeStyle interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1StrokeStyle.CAST () AS ID2D1StrokeStyle PTR
   RETURN m_pStrokeStyle
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN RETURN NULL
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ANY PTR, m_pStrokeStyle)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1StrokeStyle inteface methods
' ========================================================================================
' ========================================================================================
' Retrieves the type of shape used at the beginning of a stroke.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetStartCap () AS D2D1_CAP_STYLE
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetStartCap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of shape used at the end of a stroke.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetEndCap () AS D2D1_CAP_STYLE
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetEndCap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a value that specifies how the ends of each dash are drawn.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetDashCap () AS D2D1_CAP_STYLE
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetDashCap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the limit on the ratio of the miter length to half the stroke's thickness.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetMiterLimit () AS FLOAT
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetMiterLimit
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of joint used at the vertices of a shape's outline.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetLineJoin () AS D2D1_LINE_JOIN
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetLineJoin
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a value that specifies how far in the dash sequence the stroke will start.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetDashOffset () AS FLOAT
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetDashOffset
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a value that describes the stroke's dash pattern.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetDashStyle () AS D2D1_DASH_STYLE
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetDashStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a value that specifies how far in the dash sequence the stroke will start.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle.GetDashesCount () AS UINT32
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle->GetDashesCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a value that specifies how far in the dash sequence the stroke will start.
' ========================================================================================
PRIVATE SUB CID2D1StrokeStyle.GetDashes (BYREF dashes AS FLOAT, BYVAL dashesCount AS UINT32)
   D2D1_DP("")
   IF m_pStrokeStyle = NULL THEN EXIT SUB
   m_pStrokeStyle->GetDashes(dashes, dashesCount)
END SUB
' ========================================================================================

' ########################################################################################
' CID2D1StrokeStyle1 class
' Describes the caps, miter limit, line join, and dash information for a stroke.
' ########################################################################################

TYPE CID2D1StrokeStyle1 EXTENDS CID2D1StrokeStyle
Public:

   m_pStrokeStyle1 AS ID2D1StrokeStyle1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pStrokeStyle1 AS ID2D1StrokeStyle1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1StrokeStyle1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1StrokeStyle1 PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1StrokeStyle1
   DECLARE FUNCTION GetStrokeTransformType () AS D2D1_STROKE_TRANSFORM_TYPE

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1StrokeStyle1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1StrokeStyle1
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1StrokeStyle1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1StrokeStyle1 (BYVAL pStrokeStyle1 AS ID2D1StrokeStyle1 PTR)
   D2D1_DP("pStrokeStyle1 - " & WSTR(pStrokeStyle1))
   m_pStrokeStyle1 = pStrokeStyle1
   ' // Increment the reference count
   IF m_pStrokeStyle1 THEN m_pStrokeStyle1->AddRef
   ' // Release the base factory if there is one
   IF m_pStrokeStyle THEN
      m_pStrokeStyle->Release
      D2D1_DP("Release old stroke style: " & WSTR(m_pStrokeStyle))
   END iF
   ' // Assign the new factory pointer to the base class
   m_pStrokeStyle = m_pStrokeStyle1
   D2D1_DP("Assign new stroke style: " & WSTR(m_pStrokeStyle))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1StrokeStyle1
   D2D1_DP("m_pStrokeStyle1: " & WSTR(m_pStrokeStyle1))
   IF m_pStrokeStyle1 THEN m_pStrokeStyle1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying CID2D1StrokeStyle1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientStopCollection AS CID2D1StrokeStyle1) AS ID2D1StrokeStyle1 PTR
   RETURN gradientStopCollection.m_pStrokeStyle1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1StrokeStyle1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1StrokeStyle1.@ () AS ID2D1StrokeStyle1 PTR PTR
   RETURN @m_pStrokeStyle1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1StrokeStyle1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1StrokeStyle1.CAST () AS ID2D1StrokeStyle1 PTR
   RETURN m_pStrokeStyle1
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle1.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   IF m_pStrokeStyle1 = NULL THEN RETURN NULL
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ANY PTR, m_pStrokeStyle1)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1StrokeStyle1 methods
' ========================================================================================
' ========================================================================================
' Gets the stroke transform type.
' ========================================================================================
PRIVATE FUNCTION CID2D1StrokeStyle1.GetStrokeTransformType () AS D2D1_STROKE_TRANSFORM_TYPE
   D2D1_DP("")
   IF m_pStrokeStyle1 = NULL THEN EXIT FUNCTION
   RETURN m_pStrokeStyle1->GetStrokeTransformType
END FUNCTION
' ========================================================================================

' ########################################################################################
' CID2D1Multithread class
' A locking mechanism from a Direct2D factory that Direct2D uses to control exclusive
' resource access in an app that is uses multiple threads.
' ########################################################################################

TYPE CID2D1Multithread
Public:

   m_pMultithread AS ID2D1Multithread PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pMultithread AS ID2D1Multithread PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Multithread PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Multithread PTR

   DECLARE FUNCTION GetMultithreadProtected () AS BOOLEAN
   DECLARE SUB Enter ()
   DECLARE SUB Leave ()

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Multithread class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Multithread
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Multithread class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Multithread (BYVAL pMultithread AS ID2D1Multithread PTR)
   D2D1_DP("pMultithread - " & WSTR(pMultithread))
   m_pMultithread = pMultithread
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1Multithread
   D2D1_DP("m_pMultithread: " & WSTR(m_pMultithread))
   IF m_pMultithread THEN m_pMultithread->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying CID2D1Multithread interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientMultithread AS CID2D1Multithread) AS ID2D1Multithread PTR
   RETURN gradientMultithread.m_pMultithread
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Multithread interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Multithread.@ () AS ID2D1Multithread PTR PTR
   RETURN @m_pMultithread
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Multithread interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Multithread.CAST () AS ID2D1Multithread PTR
   RETURN m_pMultithread
END OPERATOR
' ========================================================================================

' ========================================================================================
' Returns whether the Direct2D factory was created with the D2D1_FACTORY_TYPE_MULTI_THREADED flag.
' ========================================================================================
PRIVATE FUNCTION CID2D1Multithread.GetMultithreadProtected () AS BOOLEAN
   D2D1_DP("")
   IF m_pMultithread = NULL THEN RETURN FALSE
   RETURN m_pMultithread->GetMultithreadProtected
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enters the Direct2D API critical section, if it exists.
' ========================================================================================
PRIVATE SUB CID2D1Multithread.Enter
   D2D1_DP("")
   IF m_pMultithread THEN m_pMultithread->Enter
END SUB
' ========================================================================================

' ========================================================================================
' Leaves the Direct2D API critical section, if it exists.
' ========================================================================================
PRIVATE SUB CID2D1Multithread.Leave
   D2D1_DP("")
   IF m_pMultithread THEN m_pMultithread->Leave
END SUB
' ========================================================================================

#include once "AfxNova/AfxD2D1RenderTargetClasses.inc"
#include once "AfxNova/AfxD2D1BrushClasses.inc"
#include once "AfxNova/AfxD2D1GeometryClasses.inc"
#include once "AfxNova/AfxD2D1ImageClasses.inc"

END NAMESPACE

