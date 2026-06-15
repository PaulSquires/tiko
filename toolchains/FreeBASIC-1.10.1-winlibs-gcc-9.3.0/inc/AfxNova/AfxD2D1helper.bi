#pragma once

' // To be included by AfxD2D1.inc only, not directly

' ========================================================================================
' Decrements the reference count for an interface on an object.
' The function returns the new reference count. This value is intended to be used only
' for test purposes.
' When the reference count on an object reaches zero, Release must cause the interface
' pointer to free itself. When the released pointer is the only existing reference to an
' object (whether the object supports single or multiple interfaces), the implementation
' must free the object.
' ========================================================================================
PRIVATE FUNCTION D2D1_SafeRelease (BYREF pv AS ANY PTR) AS ULONG
   IF pv = NULL THEN RETURN 0
   FUNCTION = cast(IUnknown PTR, pv)->lpvtbl->Release(pv)
   pv = NULL
END FUNCTION
' ========================================================================================

' ########################################################################################
'                                 *** d2d1helper.h ***
' ########################################################################################

' ========================================================================================
' Creates an identity matrix.
' ========================================================================================
PRIVATE FUNCTION D2D1_IdentityMatrix () AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = 1.0
   m.m12 = 0.0
   m.m21 = 0.0
   m.m22 = 1.0
   m.m31 = 0.0
   m.m32 = 0.0
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the maximum floating-point value.
' ========================================================================================
PRIVATE FUNCTION D2D1_FloatMax () AS FLOAT
   RETURN 3.402823466e+38!
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_POINT_2F structure that contains the specified x-coordinates and y-coordinates.
' ========================================================================================
PRIVATE FUNCTION D2D1_Point2F (BYVAL x AS FLOAT = 0.0, BYVAL y AS FLOAT = 0.0) AS D2D1_POINT_2F
   DIM p2f AS D2D1_POINT_2F
   p2f.x = x
   p2f.y = y
   RETURN p2f
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_POINT_2F  structure that contains the specified x-coordinates and y-coordinates.
' ========================================================================================
PRIVATE FUNCTION D2D1_Point2U (BYVAL x AS DWORD = 0, BYVAL y AS DWORD = 0) AS D2D1_POINT_2U
   DIM p2u AS D2D1_POINT_2U
   p2u.x = x
   p2u.y = y
   RETURN p2u
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_SIZE_F  structure that contains the specified width and height.
' ========================================================================================
PRIVATE FUNCTION D2D1_SizeF (BYVAL nWidth AS FLOAT = 0.0, BYVAL nHeight AS FLOAT = 0.0) AS D2D1_SIZE_F
   DIM sf AS D2D1_SIZE_F
   sf.width = nWidth
   sf.height = nHeight
   RETURN sf
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_SIZE_F  structure that contains the specified width and height.
' ========================================================================================
PRIVATE FUNCTION D2D1_SizeU (BYVAL nWidth AS UINT32 = 0, BYVAL nHeight AS UINT32 = 0) AS D2D1_SIZE_U
   DIM su AS D2D1_SIZE_U
   su.width = nWidth
   su.height = nHeight
   RETURN su
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_RECT_F  structure that contains the specified dimensions.
' ========================================================================================
PRIVATE FUNCTION D2D1_RectF (BYVAL nLeft AS FLOAT = 0.0, BYVAL nTop AS FLOAT = 0.0, BYVAL nRight AS FLOAT = 0.0, BYVAL nBottom AS FLOAT = 0.0) AS D2D1_RECT_F
   DIM rf AS D2D1_RECT_F
   rf.left = nLeft
   rf.top = nTop
   rf.right = nRight
   rf.bottom = nBottom
   RETURN rf
END FUNCTION
' ========================================================================================
 
' ========================================================================================
' Creates a D2D1_RECT_U structure that contains the specified dimensions.
' ========================================================================================
PRIVATE FUNCTION D2D1_RectU (BYVAL nLeft AS UINT32 = 0, BYVAL nTop AS UINT32 = 0, BYVAL nRight AS UINT32 = 0, BYVAL nBottom AS UINT32 = 0) AS D2D1_RECT_U
   DIM ru AS D2D1_RECT_U
   ru.left = nLeft
   ru.top = nTop
   ru.right = nRight
   ru.bottom = nBottom
   RETURN ru
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a rectangle that has its upper-left corner set to (negative infinity,
' negative infinity) and its lower-right corner set to (infinity, infinity).
' ========================================================================================
PRIVATE FUNCTION D2D1_InfiniteRect () AS D2D1_RECT_F
   DIM rf AS D2D1_RECT_F
   rf.left = -3.402823466e+38
   rf.top = -3.402823466e+38
   rf.right = 3.402823466e+38
   rf.bottom = 3.402823466e+38
   RETURN rf
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_ARC_SEGMENT structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_ArcSegment ( _
   BYREF pf AS D2D1_POINT_2F, _
   BYREF sf AS D2D1_SIZE_F, _
   BYVAL rotationAngle AS FLOAT, _
   BYVAL sweepDirection AS D2D1_SWEEP_DIRECTION, _
   BYVAL arcSize AS D2D1_ARC_SIZE _
   ) AS D2D1_ARC_SEGMENT

   DIM arcseg AS D2D1_ARC_SEGMENT
   arcseg.point = pf
   arcseg.size = sf
   arcseg.rotationAngle = rotationAngle
   arcseg.sweepDirection = sweepDirection
   arcseg.arcSize = arcSize
   RETURN arcseg

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_BEZIER_SEGMENT structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_BezierSegment ( _
   BYREF point1 AS D2D1_POINT_2F, _
   BYREF point2 AS D2D1_POINT_2F, _
   BYREF point3 AS D2D1_POINT_2F _
   ) AS D2D1_BEZIER_SEGMENT

   DIM bzseg AS D2D1_BEZIER_SEGMENT
   bzseg.point1 = point1
   bzseg.point2 = point2
   bzseg.point3 = point3
   RETURN bzseg

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_ELLIPSE structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_EllipseF OVERLOAD ( _
   BYVAL center AS D2D1_POINT_2F, _
   BYVAL radiusX AS FLOAT, _
   BYVAL radiusY AS FLOAT _
   ) AS D2D1_ELLIPSE

   DIM e AS D2D1_ELLIPSE
   e.point = center
   e.radiusX = radiusX
   e.radiusY = radiusY
   RETURN e

END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_EllipseF OVERLOAD ( _
   BYVAL x AS FLOAT, _
   BYVAL y AS FLOAT, _
   BYVAL radiusX AS FLOAT, _
   BYVAL radiusY AS FLOAT _
   ) AS D2D1_ELLIPSE

   DIM center AS D2D1_POINT_2F
   center.x = x
   center. y = y
   DIM e AS D2D1_ELLIPSE
   e.point = center
   e.radiusX = radiusX
   e.radiusY = radiusY
   RETURN e

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_ROUNDED_RECT structure.
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_RoundedRect OVERLOAD ( _
   BYREF rc AS D2D1_RECT_F, _
   BYVAL radiusX AS FLOAT, _
   BYVAL radiusY AS FLOAT _
   ) AS D2D1_ROUNDED_RECT

   DIM r AS D2D1_ROUNDED_RECT
   r.rect = rc
   r.radiusX = radiusX
   r.radiusY = radiusY
   RETURN r

END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_RoundedRect OVERLOAD ( _
   BYVAL nLeft AS FLOAT, _
   BYVAL nTop AS FLOAT, _
   BYVAL nRight AS FLOAT, _
   BYVAL nBottom AS FLOAT, _
   BYVAL radiusX AS FLOAT, _
   BYVAL radiusY AS FLOAT _
   ) AS D2D1_ROUNDED_RECT

   DIM rf AS D2D1_RECT_F
   rf.left = nLeft
   rf.top = nTop
   rf.right = nRight
   rf.bottom = nBottom
   DIM r AS D2D1_ROUNDED_RECT
   r.rect = rf
   r.radiusX = radiusX
   r.radiusY = radiusY
   RETURN r

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_BRUSH_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_BrushProperties ( _
   BYVAL opacity AS FLOAT = 1.0, _
   BYREF transform AS D2D1_MATRIX_3X2_F = D2D1_IdentityMatrix() _
   ) AS D2D1_BRUSH_PROPERTIES

   DIM bprop AS D2D1_BRUSH_PROPERTIES
   bprop.opacity = opacity
   bprop.transform = transform
   RETURN bprop

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_QUADRATIC_BEZIER_SEGMENT structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_QuadraticBezierSegment ( _
   BYREF point1 AS D2D1_POINT_2F, _
   BYREF point2 AS D2D1_POINT_2F _
   ) AS D2D1_QUADRATIC_BEZIER_SEGMENT

   DIM qbs AS D2D1_QUADRATIC_BEZIER_SEGMENT
   qbs.point1 = point1
   qbs.point2 = point2
   RETURN qbs

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_STROKE_STYLE_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_StrokeStyleProperties ( _
   BYVAL startCap AS D2D1_CAP_STYLE = D2D1_CAP_STYLE_FLAT, _
   BYVAL endCap AS D2D1_CAP_STYLE = D2D1_CAP_STYLE_FLAT, _
   BYVAL dashCap AS D2D1_CAP_STYLE = D2D1_CAP_STYLE_FLAT, _
   BYVAL lineJoin AS D2D1_LINE_JOIN = D2D1_LINE_JOIN_MITER, _
   BYVAL miterLimit AS FLOAT = 10.0, _
   BYVAL dashStyle AS D2D1_DASH_STYLE = D2D1_DASH_STYLE_SOLID, _
   BYVAL dashOffset AS FLOAT  = 0.0 _
   ) AS D2D1_STROKE_STYLE_PROPERTIES

   DIM ssp AS D2D1_STROKE_STYLE_PROPERTIES
   ssp.startCap = startCap
   ssp.endCap = endCap
   ssp.dashCap = dashCap
   ssp.lineJoin = lineJoin
   ssp.miterLimit = miterLimit
   ssp.dashStyle = dashStyle
   ssp.dashOffset = dashOffset
   RETURN ssp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_BITMAP_BRUSH_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_BitmapBrushProperties ( _
   BYVAL extendModeX AS D2D1_EXTEND_MODE = D2D1_EXTEND_MODE_CLAMP, _
   BYVAL extendModeY AS D2D1_EXTEND_MODE = D2D1_EXTEND_MODE_CLAMP, _
   BYREF interpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR _
   ) AS D2D1_BITMAP_BRUSH_PROPERTIES

   DIM bbp AS D2D1_BITMAP_BRUSH_PROPERTIES
   bbp.extendModeX = extendModeX
   bbp.extendModeY = extendModeY
   bbp.interpolationMode = interpolationMode
   RETURN bbp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_LinearGradientBrushProperties ( _
   BYREF startPoint AS const D2D1_POINT_2F, _
   BYREF endPoint AS const D2D1_POINT_2F _
   ) AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES

   DIM lgbp AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
   lgbp.startPoint = startPoint
   lgbp.endPoint = endPoint
   RETURN lgbp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_RadialGradientBrushProperties ( _
   BYREF center AS D2D1_POINT_2F, _
   BYREF gradientOriginOffset AS D2D1_POINT_2F, _
   BYVAL radiusX AS FLOAT, _
   BYVAL radiusY AS FLOAT _
   ) AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES

   DIM rgbp AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
   rgbp.center = center
   rgbp.gradientOriginOffset = gradientOriginOffset
   rgbp.radiusX = radiusX
   rgbp.radiusY = radiusY
   RETURN rgbp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_PIXEL_FORMAT structure.
' Note: Parameters declared as optional taking advantage that the default values,
' DXGI_FORMAT_UNKNOWN and D2D1_ALPHA_MODE_UNKNOWN are both 0.
' ========================================================================================
PRIVATE FUNCTION D2D1_PixelFormat ( _
   BYVAL dxgiFormat AS DXGI_FORMAT = DXGI_FORMAT_UNKNOWN, _
   BYVAL alphaMode AS D2D1_ALPHA_MODE = D2D1_ALPHA_MODE_UNKNOWN _
   ) AS D2D1_PIXEL_FORMAT

   DIM pxf AS D2D1_PIXEL_FORMAT
   pxf.format = dxgiFormat
   pxf.alphaMode = alphaMode
   RETURN pxf

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_BITMAP_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_BitmapProperties ( _
   BYREF pixelFormat AS D2D1_PIXEL_FORMAT = D2D1_PixelFormat(), _
   BYVAL dpiX AS FLOAT = 96.0, _
   BYVAL dpiY AS FLOAT = 96.0 _
   ) AS D2D1_BITMAP_PROPERTIES

   DIM bmp AS D2D1_BITMAP_PROPERTIES
   bmp.pixelFormat = pixelFormat
   bmp.dpiX = dpiX
   bmp.dpiY = dpiY
   RETURN bmp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_RENDER_TARGET_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_RenderTargetProperties ( _
   BYVAL nType AS D2D1_RENDER_TARGET_TYPE =  D2D1_RENDER_TARGET_TYPE_DEFAULT, _
   BYREF pixelFormat AS D2D1_PIXEL_FORMAT = D2D1_PixelFormat(), _
   BYVAL dpiX AS FLOAT = 0.0, _
   BYVAL dpiY AS FLOAT = 0.0, _
   BYVAL usage AS D2D1_RENDER_TARGET_USAGE = D2D1_RENDER_TARGET_USAGE_NONE, _
   BYVAL minLevel AS D2D1_FEATURE_LEVEL = D2D1_FEATURE_LEVEL_DEFAULT _
   ) AS D2D1_RENDER_TARGET_PROPERTIES

   DIM rtp AS D2D1_RENDER_TARGET_PROPERTIES
   rtp.type = nType
   rtp.pixelFormat = pixelFormat
   rtp.dpiX = dpiX
   rtp.dpiY = dpiY
   rtp.usage = usage
   rtp.minLevel = minLevel
   RETURN rtp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_HWND_RENDER_TARGET_PROPERTIES structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_HwndRenderTargetProperties OVERLOAD ( _
   BYVAL hwnd AS HWND, _
   BYREF pixelSize AS D2D1_SIZE_U = D2D1_SizeU(0, 0), _
   BYVAL presentOptions AS D2D1_PRESENT_OPTIONS  = D2D1_PRESENT_OPTIONS_NONE _
   ) AS D2D1_HWND_RENDER_TARGET_PROPERTIES

   DIM hrtp AS D2D1_HWND_RENDER_TARGET_PROPERTIES
   hrtp.hwnd = hwnd
   hrtp.pixelSize = pixelSize
   hrtp.presentOptions = presentOptions
   RETURN hrtp

END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_HwndRenderTargetProperties OVERLOAD ( _
   BYVAL hwnd AS HWND, _
   BYREF pixelWidth AS UINT32 = 0, _
   BYREF pixelHeight AS UINT32 = 0, _
   BYVAL presentOptions AS D2D1_PRESENT_OPTIONS  = D2D1_PRESENT_OPTIONS_NONE _
   ) AS D2D1_HWND_RENDER_TARGET_PROPERTIES

   DIM hrtp AS D2D1_HWND_RENDER_TARGET_PROPERTIES
   hrtp.hwnd = hwnd
   DIM pixelSize AS D2D1_SIZE_U = (pixelWidth, pixelHeight)
   hrtp.pixelSize = pixelSize
   hrtp.presentOptions = presentOptions
   RETURN hrtp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_LAYER_PARAMETERS structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_LayerParameters ( _
   BYREF contentBounds AS D2D1_RECT_F = D2D1_InfiniteRect(), _
   BYVAL geometricMask AS ID2D1Geometry PTR = NULL, _
   BYVAL maskAntialiasMode AS D2D1_ANTIALIAS_MODE = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, _
   BYREF maskTransform AS D2D1_MATRIX_3X2_F = D2D1_IdentityMatrix(), _
   BYREF opacity AS FLOAT = 1.0, _
   BYVAL opacityBrush AS ID2D1Brush PTR = NULL, _
   BYVAL layerOptions AS D2D1_LAYER_OPTIONS  = D2D1_LAYER_OPTIONS_NONE _
   ) AS D2D1_LAYER_PARAMETERS

   DIM lprms AS D2D1_LAYER_PARAMETERS
   lprms.contentBounds = contentBounds
   lprms.geometricMask = geometricMask
   lprms.maskAntialiasMode = maskAntialiasMode
   lprms.maskTransform = maskTransform
   lprms.opacity = opacity
   lprms.opacityBrush = opacityBrush
   lprms.layerOptions = layerOptions
   RETURN lprms

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_DRAWING_STATE_DESCRIPTION structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_DrawingStateDescription ( _
   BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, _
   BYVAL textAntialiasMode AS D2D1_TEXT_ANTIALIAS_MODE = D2D1_TEXT_ANTIALIAS_MODE_DEFAULT, _
   BYVAL tag1 AS D2D1_TAG = 0, _
   BYVAL tag2 AS D2D1_TAG = 0, _
   BYREF transform AS D2D1_MATRIX_3X2_F = D2D1_IdentityMatrix() _
   ) AS D2D1_DRAWING_STATE_DESCRIPTION

   DIM dsd AS D2D1_DRAWING_STATE_DESCRIPTION
   dsd.antialiasMode = antialiasMode
   dsd.textAntialiasMode = textAntialiasMode
   dsd.tag1 = tag1
   dsd.tag2 = tag2
   dsd.transform = transform
   RETURN dsd

END FUNCTION
' ========================================================================================

'//
'// Colors, this enum defines a set of predefined colors.
'//
enum KnowColor
   D2D1_AliceBlue            = &HF0F8FF
   D2D1_AntiqueWhite         = &HFAEBD7
   D2D1_Aqua                 = &H00FFFF
   D2D1_Aquamarine           = &H7FFFD4
   D2D1_Azure                = &HF0FFFF
   D2D1_Beige                = &HF5F5DC
   D2D1_Bisque               = &HFFE4C4
   D2D1_Black                = &H000000
   D2D1_BlanchedAlmond       = &HFFEBCD
   D2D1_Blue                 = &H0000FF
   D2D1_BlueViolet           = &H8A2BE2
   D2D1_Brown                = &HA52A2A
   D2D1_BurlyWood            = &HDEB887
   D2D1_CadetBlue            = &H5F9EA0
   D2D1_Chartreuse           = &H7FFF00
   D2D1_Chocolate            = &HD2691E
   D2D1_Coral                = &HFF7F50
   D2D1_CornflowerBlue       = &H6495ED
   D2D1_Cornsilk             = &HFFF8DC
   D2D1_Crimson              = &HDC143C
   D2D1_Cyan                 = &H00FFFF
   D2D1_DarkBlue             = &H00008B
   D2D1_DarkCyan             = &H008B8B
   D2D1_DarkGoldenrod        = &HB8860B
   D2D1_DarkGray             = &HA9A9A9
   D2D1_DarkGreen            = &H006400
   D2D1_DarkKhaki            = &HBDB76B
   D2D1_DarkMagenta          = &H8B008B
   D2D1_DarkOliveGreen       = &H556B2F
   D2D1_DarkOrange           = &HFF8C00
   D2D1_DarkOrchid           = &H9932CC
   D2D1_DarkRed              = &H8B0000
   D2D1_DarkSalmon           = &HE9967A
   D2D1_DarkSeaGreen         = &H8FBC8F
   D2D1_DarkSlateBlue        = &H483D8B
   D2D1_DarkSlateGray        = &H2F4F4F
   D2D1_DarkTurquoise        = &H00CED1
   D2D1_DarkViolet           = &H9400D3
   D2D1_DeepPink             = &HFF1493
   D2D1_DeepSkyBlue          = &H00BFFF
   D2D1_DimGray              = &H696969
   D2D1_DodgerBlue           = &H1E90FF
   D2D1_Firebrick            = &HB22222
   D2D1_FloralWhite          = &HFFFAF0
   D2D1_ForestGreen          = &H228B22
   D2D1_Fuchsia              = &HFF00FF
   D2D1_Gainsboro            = &HDCDCDC
   D2D1_GhostWhite           = &HF8F8FF
   D2D1_Gold                 = &HFFD700
   D2D1_Goldenrod            = &HDAA520
   D2D1_Gray                 = &H808080
   D2D1_Green                = &H008000
   D2D1_GreenYellow          = &HADFF2F
   D2D1_Honeydew             = &HF0FFF0
   D2D1_HotPink              = &HFF69B4
   D2D1_IndianRed            = &HCD5C5C
   D2D1_Indigo               = &H4B0082
   D2D1_Ivory                = &HFFFFF0
   D2D1_Khaki                = &HF0E68C
   D2D1_Lavender             = &HE6E6FA
   D2D1_LavenderBlush        = &HFFF0F5
   D2D1_LawnGreen            = &H7CFC00
   D2D1_LemonChiffon         = &HFFFACD
   D2D1_LightBlue            = &HADD8E6
   D2D1_LightCoral           = &HF08080
   D2D1_LightCyan            = &HE0FFFF
   D2D1_LightGoldenrodYellow = &HFAFAD2
   D2D1_LightGreen           = &H90EE90
   D2D1_LightGray            = &HD3D3D3
   D2D1_LightPink            = &HFFB6C1
   D2D1_LightSalmon          = &HFFA07A
   D2D1_LightSeaGreen        = &H20B2AA
   D2D1_LightSkyBlue         = &H87CEFA
   D2D1_LightSlateGray       = &H778899
   D2D1_LightSteelBlue       = &HB0C4DE
   D2D1_LightYellow          = &HFFFFE0
   D2D1_Lime                 = &H00FF00
   D2D1_LimeGreen            = &H32CD32
   D2D1_Linen                = &HFAF0E6
   D2D1_Magenta              = &HFF00FF
   D2D1_Maroon               = &H800000
   D2D1_MediumAquamarine     = &H66CDAA
   D2D1_MediumBlue           = &H0000CD
   D2D1_MediumOrchid         = &HBA55D3
   D2D1_MediumPurple         = &H9370DB
   D2D1_MediumSeaGreen       = &H3CB371
   D2D1_MediumSlateBlue      = &H7B68EE
   D2D1_MediumSpringGreen    = &H00FA9A
   D2D1_MediumTurquoise      = &H48D1CC
   D2D1_MediumVioletRed      = &HC71585
   D2D1_MidnightBlue         = &H191970
   D2D1_MintCream            = &HF5FFFA
   D2D1_MistyRose            = &HFFE4E1
   D2D1_Moccasin             = &HFFE4B5
   D2D1_NavajoWhite          = &HFFDEAD
   D2D1_Navy                 = &H000080
   D2D1_OldLace              = &HFDF5E6
   D2D1_Olive                = &H808000
   D2D1_OliveDrab            = &H6B8E23
   D2D1_Orange               = &HFFA500
   D2D1_OrangeRed            = &HFF4500
   D2D1_Orchid               = &HDA70D6
   D2D1_PaleGoldenrod        = &HEEE8AA
   D2D1_PaleGreen            = &H98FB98
   D2D1_PaleTurquoise        = &HAFEEEE
   D2D1_PaleVioletRed        = &HDB7093
   D2D1_PapayaWhip           = &HFFEFD5
   D2D1_PeachPuff            = &HFFDAB9
   D2D1_Peru                 = &HCD853F
   D2D1_Pink                 = &HFFC0CB
   D2D1_Plum                 = &HDDA0DD
   D2D1_PowderBlue           = &HB0E0E6
   D2D1_Purple               = &H800080
   D2D1_Red                  = &HFF0000
   D2D1_RosyBrown            = &HBC8F8F
   D2D1_RoyalBlue            = &H4169E1
   D2D1_SaddleBrown          = &H8B4513
   D2D1_Salmon               = &HFA8072
   D2D1_SandyBrown           = &HF4A460
   D2D1_SeaGreen             = &H2E8B57
   D2D1_SeaShell             = &HFFF5EE
   D2D1_Sienna               = &HA0522D
   D2D1_Silver               = &HC0C0C0
   D2D1_SkyBlue              = &H87CEEB
   D2D1_SlateBlue            = &H6A5ACD
   D2D1_SlateGray            = &H708090
   D2D1_Snow                 = &HFFFAFA
   D2D1_SpringGreen          = &H00FF7F
   D2D1_SteelBlue            = &H4682B4
   D2D1_Tan                  = &HD2B48C
   D2D1_Teal                 = &H008080
   D2D1_Thistle              = &HD8BFD8
   D2D1_Tomato               = &HFF6347
   D2D1_Turquoise            = &H40E0D0
   D2D1_Violet               = &HEE82EE
   D2D1_Wheat                = &HF5DEB3
   D2D1_White                = &HFFFFFF
   D2D1_WhiteSmoke           = &HF5F5F5
   D2D1_Yellow               = &HFFFF00
   D2D1_YellowGreen          = &H9ACD32
end enum

CONST AS UINT32 sc_redShift   = 16
CONST AS UINT32 sc_greenShift = 8
CONST AS UINT32 sc_blueShift  = 0

'static const UINT32 sc_redMask = 0xff << sc_redShift;
'static const UINT32 sc_greenMask = 0xff << sc_greenShift;
'static const UINT32 sc_blueMask = 0xff << sc_blueShift;

CONST AS UINT32 sc_redMask = &H00FF0000
CONST AS UINT32 sc_greenMask = &H0000FF00
CONST AS UINT32 sc_blueMask = &H000000FF

' ========================================================================================
' Helper method for ColorF.
' ========================================================================================
PRIVATE FUNCTION D2D1_InitColorF( _
   BYVAL urgb AS UINT32, _
   BYVAL alpha AS FLOAT _
   ) AS D2D1_COLOR_F

   DIM cf AS D2D1_COLOR_F
   cf.r = ((urgb AND sc_redMask) shr sc_redShift) / 255.0
   cf.g = ((urgb AND sc_greenMask) shr sc_greenShift) / 255.0
   cf.b = ((urgb AND sc_blueMask) shr sc_blueShift) / 255.0
   cf.a = alpha
   RETURN cf

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_COLOR_F structure that contains the specified RGB and alpha values.
' ========================================================================================
PRIVATE FUNCTION D2D1_ColorF OVERLOAD ( _
   BYVAL urgb AS UINT32, _
   BYVAL a AS FLOAT  = 1.0 _
   ) AS D2D1_COLOR_F

   RETURN D2D1_InitColorF(urgb, a)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_COLOR_F structure that contains the specified red, green, blue, and alpha values.
' ========================================================================================
PRIVATE FUNCTION D2D1_ColorF OVERLOAD ( _
   BYVAL red AS FLOAT, _
   BYVAL green AS FLOAT, _
   BYVAL blue AS FLOAT, _
   BYVAL alpha AS FLOAT = 1.0 _
   ) AS D2D1_COLOR_F

   DIM cf AS D2D1_COLOR_F
   cf.r = red
   cf.g = green
   cf.b = blue
   cf.a = alpha
   RETURN cf

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_GRADIENT_STOP structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_GradientStop OVERLOAD ( _
   BYVAL position AS FLOAT, _
   BYREF clr AS D2D1_COLOR_F _
   ) AS D2D1_GRADIENT_STOP

   DIM gstop AS D2D1_GRADIENT_STOP
   gstop.position = position
   gstop.color = clr
   RETURN gstop

END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_GradientStop OVERLOAD ( _
   BYVAL position AS FLOAT, _
   BYVAL clr AS UINT32, _
   BYVAL alpha AS FLOAT = 1.0 _
   ) AS D2D1_GRADIENT_STOP

   DIM gstop AS D2D1_GRADIENT_STOP
   gstop.position = position
   gstop.color = D2D1_ColorF(clr, alpha)
   RETURN gstop

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_MATRIX_3X2_F structure that contains the specified values.
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix3x2F ( _
   BYVAL m11 AS FLOAT, _
   BYVAL m12 AS FLOAT, _
   BYVAL m21 AS FLOAT, _
   BYVAL m22 AS FLOAT, _
   BYVAL m31 AS FLOAT, _
   BYVAL m32 AS FLOAT _
   ) AS D2D1_MATRIX_3X2_F

   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = m11
   m.m12 = m12
   m.m21 = m21
   m.m22 = m22
   m.m31 = m31
   m.m32 = m32
   RETURN m

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a translation transformation that has the specified width and height displacements.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixTranslation OVERLOAD (BYREF tsize AS D2D1_SIZE_F) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = 1.0
   m.m12 = 0.0
   m.m21 = 0.0
   m.m22 = 1.0
   m.m31 = tsize.width
   m.m32 = tsize.height
   RETURN m
END FUNCTION
' ========================================================================================
' ========================================================================================
' Creates a translation transformation that has the specified x and y displacements.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixTranslation OVERLOAD (BYVAL x AS FLOAT, BYVAL y AS FLOAT) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = 1.0
   m.m12 = 0.0
   m.m21 = 0.0
   m.m22 = 1.0
   m.m31 = x
   m.m32 = y
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a scale transformation that has the specified scale factors and center point.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixScale OVERLOAD (BYREF tsize AS D2D1_SIZE_F, BYVAL center AS D2D1_POINT_2F = D2D1_Point2F()) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = tsize.width
   m.m12 = 0.0
   m.m21 = 0.0
   m.m22 = tsize.height
   m.m31 = center.x - tsize.width * center.x
   m.m32 = center.y - tsize.height * center.y
   RETURN m
END FUNCTION
' ========================================================================================
' ========================================================================================
' Creates a scale transformation that has the specified scale factors and center point.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixScale OVERLOAD (BYVAL x AS FLOAT, BYVAL y AS FLOAT, BYVAL center AS D2D1_POINT_2F = D2D1_Point2F()) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = x
   m.m12 = 0.0
   m.m21 = 0.0
   m.m22 = y
   m.m31 = center.x - x * center.x
   m.m32 = center.y - y * center.y
   RETURN m
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixScale OVERLOAD (BYVAL x AS FLOAT, BYVAL y AS FLOAT, BYVAL centerX AS FLOAT, BYVAL centerY AS FLOAT) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = x
   m.m12 = 0.0!
   m.m21 = 0.0!
   m.m22 = y
   m.m31 = centerX - x * centerX
   m.m32 = centerY - y * centerY
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a rotation transformation that has the specified angle and center point.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixRotation OVERLOAD (BYVAL angle AS FLOAT, BYVAL center AS D2D1_POINT_2F = D2D1_Point2F()) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   D2D1MakeRotateMatrix(angle, center, m)
   RETURN m
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixRotation OVERLOAD (BYVAL angle AS FLOAT, BYVAL centerX AS FLOAT = 0.0!, BYVAL centerY AS FLOAT = 0.0!) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   DIM center AS D2D1_POINT_2F =  (centerX, centerY)
   D2D1MakeRotateMatrix(angle, center, m)
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a skew transformation that has the specified x-axis and y-axis values and center point.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixSkew OVERLOAD (BYVAL angleX AS FLOAT, BYVAL angleY AS FLOAT, BYVAL center AS D2D1_POINT_2F = D2D1_Point2F()) AS D2D1_MATRIX_3X2_F
   DIM skew AS D2D1_MATRIX_3X2_F
   D2D1MakeSkewMatrix(angleX, angleY, center, skew)
   RETURN skew
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixSkew OVERLOAD (BYVAL angleX AS FLOAT, BYVAL angleY AS FLOAT, BYVAL centerX AS FLOAT = 0.0!, BYVAL centerY AS FLOAT = 0.0!) AS D2D1_MATRIX_3X2_F
   DIM skew AS D2D1_MATRIX_3X2_F
   DIM center AS D2D1_POINT_2F = (centerX, centerY)
   D2D1MakeSkewMatrix(angleX, angleY, center, skew)
   RETURN skew
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the determinant of the matrix.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixDeterminant (BYREF m AS D2D1_MATRIX_3X2_F) AS FLOAT
   RETURN (m.m11 * m.m22) - (m.m12 * m.m21)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the matrix is invertible.
' ========================================================================================
PRIVATE FUNCTION D2D1_IsInvertibleMatrix (BYREF m AS D2D1_MATRIX_3X2_F) AS BOOLEAN
   RETURN D2D1IsMatrixInvertible(m)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inverts the matrix, if it is invertible.
' ========================================================================================
PRIVATE SUB D2D1_InvertMatrix (BYREF m AS D2D1_MATRIX_3X2_F)
   D2D1InvertMatrix(m)
END SUB
' ========================================================================================

' ========================================================================================
' Indicates whether this matrix is the identity matrix.
' ========================================================================================
PRIVATE FUNCTION D2D1_IsIdentityMatrix (BYREF m AS D2D1_MATRIX_3X2_F) AS LONG
   RETURN (m.m11 = 1.0 AND m.m12 = 0.0 AND m.m21 = 0.0 AND m.m22 = 1.0 AND m.m31 = 0.0 AND m.m32 = 0.0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Multiplies the specified matrices and returns the result.
' ========================================================================================
'PRIVATE SUB D2D1_SetProduct (BYREF a AS D2D1_MATRIX_3X2_F, BYREF b AS D2D1_MATRIX_3X2_F)
'   a.m11 = a.m11 * b.m11 + a.m12 * b.m21
'   a.m12 = a.m11 * b.m12 + a.m12 * b.m22
'   a.m21 = a.m21 * b.m11 + a.m22 * b.m21
'   a.m22 = a.m21 * b.m12 + a.m22 * b.m22
'   a.m31 = a.m31 * b.m11 + a.m32 * b.m21 + b.m31
'   a.m32 = a.m31 * b.m12 + a.m32 * b.m22 + b.m32
'END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION D2D1_MultiplyMatrices (BYREF a AS D2D1_MATRIX_3X2_F, BYREF b AS D2D1_MATRIX_3X2_F) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = a.m11 * b.m11 + a.m12 * b.m21
   m.m12 = a.m11 * b.m12 + a.m12 * b.m22
   m.m21 = a.m21 * b.m11 + a.m22 * b.m21
   m.m22 = a.m21 * b.m12 + a.m22 * b.m22
   m.m31 = a.m31 * b.m11 + a.m32 * b.m21 + b.m31
   m.m32 = a.m31 * b.m12 + a.m32 * b.m22 + b.m32
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' Uses the specified matrix to transform the specified point and returns the result.
' ========================================================================================
PRIVATE FUNCTION D2D1_MatrixTransformPoint (BYREF pt AS D2D1_POINT_2F, BYREF m AS D2D1_MATRIX_3X2_F) AS D2D1_POINT_2F
   DIM result AS D2D1_POINT_2F
   result.x = pt.x * m.m11 + pt.y * m.m21 + m.m31
   result.y = pt.x * m.m12 + pt.y * m.m22 + m.m32
   RETURN result
END FUNCTION
' ========================================================================================


' ========================================================================================
'                                *** GLOBAL OPERATORS ***
' ========================================================================================

' ========================================================================================
' Multiplies the specified matrices and returns the result.
' ========================================================================================
PRIVATE OPERATOR * (BYREF a AS D2D1_MATRIX_3X2_F, BYREF b AS D2D1_MATRIX_3X2_F) AS D2D1_MATRIX_3X2_F
   DIM m AS D2D1_MATRIX_3X2_F
   m.m11 = a.m11 * b.m11 + a.m12 * b.m21
   m.m12 = a.m11 * b.m12 + a.m12 * b.m22
   m.m21 = a.m21 * b.m11 + a.m22 * b.m21
   m.m22 = a.m21 * b.m12 + a.m22 * b.m22
   m.m31 = a.m31 * b.m11 + a.m32 * b.m21 + b.m31
   m.m32 = a.m31 * b.m12 + a.m32 * b.m22 + b.m32
   RETURN m
END OPERATOR
' ========================================================================================

' ========================================================================================
PRIVATE OPERATOR * (BYREF pt AS D2D1_POINT_2F, BYREF m AS D2D1_MATRIX_3X2_F) AS D2D1_POINT_2F
   OPERATOR = D2D1_MatrixTransformPoint(pt, m)
END OPERATOR
' ========================================================================================

' ========================================================================================
PRIVATE OPERATOR = (BYREF size1 AS D2D1_SIZE_U, BYREF size2 AS D2D1_SIZE_U) AS BOOLEAN
   RETURN (size1.width = size2.width) AND (size1.height = size2.height)
END OPERATOR
' ========================================================================================

' ========================================================================================
PRIVATE OPERATOR = (BYREF rect1 AS D2D1_RECT_U, BYREF rect2 AS D2D1_RECT_U) AS BOOLEAN
   RETURN (rect1.left = rect2.left) AND (rect1.top = rect2.top) AND (rect1.right = rect2.right) AND (rect1.bottom = rect2.bottom)
END OPERATOR
' ========================================================================================


' ########################################################################################
'                                 *** D2D1_1Helper.h ***
' ########################################################################################

' ========================================================================================
' Creates a D2D1_MATRIX_4X3_F structure that contains the specified values.
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x3F OVERLOAD ( _
   BYVAL m11 AS FLOAT, _
   BYVAL m12 AS FLOAT, _
   BYVAL m13 AS FLOAT, _
   BYVAL m21 AS FLOAT, _
   BYVAL m22 AS FLOAT, _
   BYVAL m23 AS FLOAT, _
   BYVAL m31 AS FLOAT, _
   BYVAL m32 AS FLOAT, _
   BYVAL m33 AS FLOAT, _
   BYVAL m41 AS FLOAT, _
   BYVAL m42 AS FLOAT, _
   BYVAL m43 AS FLOAT _
   ) AS D2D1_MATRIX_4X3_F

   DIM m AS D2D1_MATRIX_4X3_F
   m.m11 = m11
   m.m12 = m12
   m.m13 = m13
   m.m21 = m21
   m.m22 = m22
   m.m23 = m23
   m.m31 = m31
   m.m32 = m32
   m.m33 = m33
   m.m41 = m41
   m.m42 = m42
   m.m43 = m43
   RETURN m

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x3F OVERLOAD () AS D2D1_MATRIX_4X3_F
   DIM m AS D2D1_MATRIX_4X3_F
   m.m11 = 1
   m.m12 = 0
   m.m13 = 0
   m.m21 = 0
   m.m22 = 1
   m.m23 = 0
   m.m31 = 0
   m.m32 = 0
   m.m33 = 1
   m.m41 = 0
   m.m42 = 0
   m.m43 = 0
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' Represents a 4-by-4 matrix.
' D2D1_MATRIX_4X4 is a new name for the D2D1_MATRIX_4X4_F structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4F OVERLOAD ( _
   BYVAL m11 AS FLOAT, _
   BYVAL m12 AS FLOAT, _
   BYVAL m13 AS FLOAT, _
   BYVAL m14 AS FLOAT, _
   BYVAL m21 AS FLOAT, _
   BYVAL m22 AS FLOAT, _
   BYVAL m23 AS FLOAT, _
   BYVAL m24 AS FLOAT, _
   BYVAL m31 AS FLOAT, _
   BYVAL m32 AS FLOAT, _
   BYVAL m33 AS FLOAT, _
   BYVAL m34 AS FLOAT, _
   BYVAL m41 AS FLOAT, _
   BYVAL m42 AS FLOAT, _
   BYVAL m43 AS FLOAT, _
   BYVAL m44 AS FLOAT _
   ) AS D2D1_MATRIX_4X4_F

   DIM m AS D2D1_MATRIX_4X4_F
   m.m11 = m11
   m.m12 = m12
   m.m13 = m13
   m.m14 = m14
   m.m21 = m21
   m.m22 = m22
   m.m23 = m23
   m.m24 = m24
   m.m31 = m31
   m.m32 = m32
   m.m33 = m33
   m.m34 = m34
   m.m41 = m41
   m.m42 = m42
   m.m43 = m43
   m.m44 = m44
   RETURN m

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4F OVERLOAD () AS D2D1_MATRIX_4X4_F

   DIM m AS D2D1_MATRIX_4X4_F
   m.m11 = 1
   m.m12 = 0
   m.m13 = 0
   m.m14 = 0
   m.m21 = 0
   m.m22 = 1
   m.m23 = 0
   m.m24 = 0
   m.m31 = 0
   m.m32 = 0
   m.m33 = 1
   m.m34 = 0
   m.m41 = 0
   m.m42 = 0
   m.m43 = 0
   m.m44 = 1
   RETURN m

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE OPERATOR = (BYREF m AS D2D1_MATRIX_4X4_F, BYREF r AS D2D1_MATRIX_4X4_F) AS BOOLEAN
   RETURN m.m11 = r.m11 AND m.m12 = r.m12 AND m.m13 = r.m13 AND m.m14 = r.m14 AND _
          m.m21 = r.m21 AND m.m22 = r.m22 AND m.m23 = r.m23 AND m.m24 = r.m24 AND _
          m.m31 = r.m31 AND m.m32 = r.m32 AND m.m33 = r.m33 AND m.m34 = r.m34 AND _
          m.m41 = r.m41 AND m.m42 = r.m42 AND m.m43 = r.m43 AND m.m44 = r.m44
END OPERATOR
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FTranslation (BYVAL x AS FLOAT, BYVAL y AS FLOAT, BYVAL z AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM translation AS D2D1_MATRIX_4X4_F
   translation.m11 = 1.0 : translation.m12 = 0.0 : translation.m13 = 0.0 : translation.m14 = 0.0
   translation.m21 = 0.0 : translation.m22 = 1.0 : translation.m23 = 0.0 : translation.m24 = 0.0
   translation.m31 = 0.0 : translation.m32 = 0.0 : translation.m33 = 1.0 : translation.m34 = 0.0
   translation.m41 = x :   translation.m42 = y :   translation.m43 = z :   translation.m44 = 1.0
   RETURN translation
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FScale (BYVAL x AS FLOAT, BYVAL y AS FLOAT, BYVAL z AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM scale AS D2D1_MATRIX_4X4_F
   scale.m11 = x :   scale.m12 = 0.0 : scale.m13 = 0.0 : scale.m14 = 0.0
   scale.m21 = 0.0 : scale.m22 = y :   scale.m23 = 0.0 : scale.m24 = 0.0
   scale.m31 = 0.0 : scale.m32 = 0.0 : scale.m33 = z :   scale.m34 = 0.0
   scale.m41 = 0.0 : scale.m42 = 0.0 : scale.m43 = 0.0 : scale.m44 = 1.0
   RETURN scale
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FRotationX (BYVAL degreeX AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM angleInRadian AS FLOAT = degreeX * (3.141592654 / 180.0)
   DIM AS FLOAT sinAngle, cosAngle
   D2D1SinCos(angleInRadian, sinAngle, cosAngle)
   DIM m AS D2D1_MATRIX_4X4_F
   m.m11 = 1 : m.m12 = 0         :  m.m13 = 0        : m.m14 = 0
   m.m21 = 0 : m.m22 = cosAngle  :  m.m23 = sinAngle : m.m24 = 0
   m.m31 = 0 : m.m32 = -sinAngle :  m.m33 = cosAngle : m.m34 = 0
   m.m41 = 0 : m.m42 = 0         :  m.m43 = 0        : m.m44 = 1
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FRotationY (BYVAL degreeY AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM angleInRadian AS FLOAT = degreeY * (3.141592654 / 180.0)
   DIM AS FLOAT sinAngle, cosAngle
   D2D1SinCos(angleInRadian, sinAngle, cosAngle)
   DIM m AS D2D1_MATRIX_4X4_F
   m.m11 =  cosAngle : m.m12 = 0 : m.m13 = -sinAngle : m.m14 = 0
   m.m21 =  0        : m.m22 = 1 : m.m23 =  0        : m.m24 = 0
   m.m31 =  sinAngle : m.m32 = 0 : m.m33 =  cosAngle : m.m34 = 0
   m.m41 =  0        : m.m42 = 0 : m.m43 =  0        : m.m44 = 1
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FRotationZ (BYVAL degreeZ AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM angleInRadian AS FLOAT = degreeZ * (3.141592654 / 180.0)
   DIM AS FLOAT sinAngle, cosAngle
   D2D1SinCos(angleInRadian, sinAngle, cosAngle)
   DIM m AS D2D1_MATRIX_4X4_F
   m.m11 =  cosAngle  : m.m12 = sinAngle : m.m13 = 0  : m.m14 = 0
   m.m21 =  -sinAngle : m.m22 = cosAngle : m.m23 = 0  : m.m24 = 0
   m.m31 =  0         : m.m32 = 0        : m.m33 = 1  : m.m34 = 0
   m.m41 =  0         : m.m42 = 0        : m.m43 = 0  : m.m44 = 1
   RETURN m
END FUNCTION
' ========================================================================================

' ========================================================================================
' 3D Rotation matrix for an arbitrary axis specified by x, y and z
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FRotationArbitraryAxis (BYVAL x AS FLOAT, BYVAL y AS FLOAT, BYVAL z AS FLOAT, BYVAL degree AS FLOAT) AS D2D1_MATRIX_4X4_F
   ' // Normalize the vector represented by x, y, and z
   DIM magnitude AS FLOAT = D2D1Vec3Length(x, y, z)
   x /= magnitude
   y /= magnitude
   z /= magnitude

   DIM angleInRadian AS FLOAT = degree * (3.141592654 / 180.0)
   DIM AS FLOAT sinAngle, cosAngle
   D2D1SinCos(angleInRadian, sinAngle, cosAngle)

   DIM AS FLOAT oneMinusCosAngle = 1 - cosAngle
   DIM rotationArb AS D2D1_MATRIX_4X4_F

   rotationArb.m11 = 1 + oneMinusCosAngle * (x * x - 1)
   rotationArb.m12 = z * sinAngle + oneMinusCosAngle *  x * y
   rotationArb.m13 = -y * sinAngle + oneMinusCosAngle *  x * z
   rotationArb.m14 = 0

   rotationArb.m21 = -z * sinAngle + oneMinusCosAngle *  y * x
   rotationArb.m22 = 1 + oneMinusCosAngle * (y * y - 1)
   rotationArb.m23 = x  * sinAngle + oneMinusCosAngle *  y * z
   rotationArb.m24 = 0
   
   rotationArb.m31 = y * sinAngle + oneMinusCosAngle *  z * x
   rotationArb.m32 = -x * sinAngle + oneMinusCosAngle *  z * y
   rotationArb.m33 = 1 + oneMinusCosAngle * (z * z - 1)
   rotationArb.m34 = 0

   rotationArb.m41 = 0
   rotationArb.m42 = 0
   rotationArb.m43 = 0
   rotationArb.m44 = 1

   RETURN rotationArb

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FSkewX (BYVAL degreeX AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM AS FLOAT angleInRadian = degreeX * (3.141592654 / 180.0)
   DIM AS FLOAT tanAngle = D2D1Tan(angleInRadian)
   DIM skewX AS D2D1_MATRIX_4X4_F
   skewX.m11 =  1        : skewX.m12 = 0 : skewX.m13 = 0  : skewX.m14 = 0
   skewX.m21 =  tanAngle : skewX.m22 = 1 : skewX.m23 = 0  : skewX.m24 = 0
   skewX.m31 =  0        : skewX.m32 = 0 : skewX.m33 = 1  : skewX.m34 = 0
   skewX.m41 =  0        : skewX.m42 = 0 : skewX.m43 = 0  : skewX.m44 = 1
   RETURN skewX
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FSkewY (BYVAL degreeY AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM AS FLOAT angleInRadian = degreeY * (3.141592654 / 180.0)
   DIM AS FLOAT tanAngle = D2D1Tan(angleInRadian)
   DIM skewY AS D2D1_MATRIX_4X4_F
   skewY.m11 =  1 : skewY.m12 = tanAngle : skewY.m13 = 0  : skewY.m14 = 0
   skewY.m21 =  0 : skewY.m22 = 1        : skewY.m23 = 0  : skewY.m24 = 0
   skewY.m31 =  0 : skewY.m32 = 0        : skewY.m33 = 1  : skewY.m34 = 0
   skewY.m41 =  0 : skewY.m42 = 0        : skewY.m43 = 0  : skewY.m44 = 1
   RETURN skewY
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FPerspectiveProjection (BYVAL depth AS FLOAT) AS D2D1_MATRIX_4X4_F
   DIM AS FLOAT proj
   IF depth > 0 THEN proj = -1/depth
   DIM projection AS D2D1_MATRIX_4X4_F
   projection.m11 =  1 : projection.m12 = 0 : projection.m13 = 0  : projection.m14 = 0
   projection.m21 =  0 : projection.m22 = 1 : projection.m23 = 0  : projection.m24 = 0
   projection.m31 =  0 : projection.m32 = 0 : projection.m33 = 1  : projection.m34 = proj
   projection.m41 =  0 : projection.m42 = 0 : projection.m43 = 0  : projection.m44 = 1
   RETURN projection
END FUNCTION
' ========================================================================================

' ========================================================================================
'PRIVATE FUNCTION D2D1_Matrix4x4FDeterminant (BYREF m AS D2D1_MATRIX_4X4_F) AS FLOAT
'   DIM AS FLOAT minor1 = m.m41 * (m.m12 * (m.m23 * m.m34 - m.m33 * m.m24) - m.m13 * (m.m22 * m.m34 - m.m24 * m.m32) + m.m14 * (m.m22 * m.m33 - m.m23 * m.m32))
'   DIM AS FLOAT minor2 = m.m42 * (m.m11 * (m.m21 * m.m34 - m.m31 * m.m24) - m.m13 * (m.m21 * m.m34 - m.m24 * m.m31) + m.m14 * (m.m21 * m.m33 - m.m23 * m.m31))
'   DIM AS FLOAT minor3 = m.m43 * (m.m11 * (m.m22 * m.m34 - m.m32 * m.m24) - m.m12 * (m.m21 * m.m34 - m.m24 * m.m31) + m.m14 * (m.m21 * m.m32 - m.m22 * m.m31))
'   DIM AS FLOAT minor4 = m.m44 * (m.m11 * (m.m22 * m.m33 - m.m32 * m.m23) - m.m12 * (m.m21 * m.m33 - m.m23 * m.m31) + m.m13 * (m.m21 * m.m32 - m.m22 * m.m31))
'   RETURN minor1 - minor2 + minor3 - minor4
'END FUNCTION
' ========================================================================================

' ========================================================================================
' NOTE: The original determinant in d2d1_2helper.h contains errors in the minors.
' This version corrects these errors and correctly calculates the determinant of a 4x4
' matrix by expanding along the first row.
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FDeterminant (BYREF m AS D2D1_MATRIX_4X4_F) AS FLOAT
   DIM AS FLOAT minor1 = m.m11 * (m.m22 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * (m.m32 * m.m44 - m.m34 * m.m42) + m.m24 * (m.m32 * m.m43 - m.m33 * m.m42))
   DIM AS FLOAT minor2 = m.m12 * (m.m21 * (m.m33 * m.m44 - m.m34 * m.m43) - m.m23 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m43 - m.m33 * m.m41))
   DIM AS FLOAT minor3 = m.m13 * (m.m21 * (m.m32 * m.m44 - m.m34 * m.m42) - m.m22 * (m.m31 * m.m44 - m.m34 * m.m41) + m.m24 * (m.m31 * m.m42 - m.m32 * m.m41))
   DIM AS FLOAT minor4 = m.m14 * (m.m21 * (m.m32 * m.m43 - m.m33 * m.m42) - m.m22 * (m.m31 * m.m43 - m.m33 * m.m41) + m.m23 * (m.m31 * m.m42 - m.m32 * m.m41))
   RETURN minor1 - minor2 + minor3 - minor4
END FUNCTION
' ========================================================================================

' ========================================================================================
'PRIVATE FUNCTION D2D1_Matrix4x4FIsIdentity (BYREF m AS D2D1_MATRIX_4X4_F) AS BOOLEAN
'   return m.m11 = 1 AND m.m12 = 0 AND m.m13 = 0 AND m.m14 = 0 _
'      AND m.m21 = 0 AND m.m22 = 1 AND m.m23 = 0 AND m.m24 = 0 _
'      AND m.m31 = 0 AND m.m32 = 0 AND m.m33 = 1 AND m.m34 = 0 _
'      AND m.m41 = 0 AND m.m42 = 0 AND m.m43 = 0 AND m.m44 = 1
'END FUNCTION
' ========================================================================================

' ========================================================================================
' NOTE: This function uses a tolerance (epsilon) to compensate for rounding errors
' typical in cumulative transformation matrices. Exact comparison with 1 and 0 may fail
' even when the matrix is effectively the identity.
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FIsIdentity (BYREF m AS D2D1_MATRIX_4X4_F) AS BOOLEAN
    CONST eps AS FLOAT = 0.00001
    RETURN _
        ABS(m.m11 - 1) < eps AND ABS(m.m12) < eps AND ABS(m.m13) < eps AND ABS(m.m14) < eps AND _
        ABS(m.m21) < eps AND ABS(m.m22 - 1) < eps AND ABS(m.m23) < eps AND ABS(m.m24) < eps AND _
        ABS(m.m31) < eps AND ABS(m.m32) < eps AND ABS(m.m33 - 1) < eps AND ABS(m.m34) < eps AND _
        ABS(m.m41) < eps AND ABS(m.m42) < eps AND ABS(m.m43) < eps AND ABS(m.m44 - 1) < eps
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix4x4FSetProduct (BYREF a AS D2D1_MATRIX_4X4_F, BYREF b AS D2D1_MATRIX_4X4_F) AS D2D1_MATRIX_4X4_F

   DIM r AS D2D1_MATRIX_4X4_F

   r.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31 + a.m14 * b.m41
   r.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32 + a.m14 * b.m42
   r.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33 + a.m14 * b.m43
   r.m14 = a.m11 * b.m14 + a.m12 * b.m24 + a.m13 * b.m34 + a.m14 * b.m44

   r.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31 + a.m24 * b.m41
   r.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32 + a.m24 * b.m42
   r.m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33 + a.m24 * b.m43
   r.m24 = a.m21 * b.m14 + a.m22 * b.m24 + a.m23 * b.m34 + a.m24 * b.m44

   r.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31 + a.m34 * b.m41
   r.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32 + a.m34 * b.m42
   r.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33 + a.m34 * b.m43
   r.m34 = a.m31 * b.m14 + a.m32 * b.m24 + a.m33 * b.m34 + a.m34 * b.m44

   r.m41 = a.m41 * b.m11 + a.m42 * b.m21 + a.m43 * b.m31 + a.m44 * b.m41
   r.m42 = a.m41 * b.m12 + a.m42 * b.m22 + a.m43 * b.m32 + a.m44 * b.m42
   r.m43 = a.m41 * b.m13 + a.m42 * b.m23 + a.m43 * b.m33 + a.m44 * b.m43
   r.m44 = a.m41 * b.m14 + a.m42 * b.m24 + a.m43 * b.m34 + a.m44 * b.m44

   RETURN r

END FUNCTION
' ========================================================================================

' ========================================================================================
' Multiplies the specified matrices and returns the result.
' ========================================================================================
PRIVATE OPERATOR * (BYREF a AS D2D1_MATRIX_4X4_F, BYREF b AS D2D1_MATRIX_4X4_F) AS D2D1_MATRIX_4X4_F
   OPERATOR = D2D1_Matrix4x4FSetProduct(a, b)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a D2D1_MATRIX_5X4_F structure that contains the specified values.
' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix5x4F OVERLOAD ( _
   BYVAL m11 AS FLOAT, _
   BYVAL m12 AS FLOAT, _
   BYVAL m13 AS FLOAT, _
   BYVAL m14 AS FLOAT, _
   BYVAL m21 AS FLOAT, _
   BYVAL m22 AS FLOAT, _
   BYVAL m23 AS FLOAT, _
   BYVAL m24 AS FLOAT, _
   BYVAL m31 AS FLOAT, _
   BYVAL m32 AS FLOAT, _
   BYVAL m33 AS FLOAT, _
   BYVAL m34 AS FLOAT, _
   BYVAL m41 AS FLOAT, _
   BYVAL m42 AS FLOAT, _
   BYVAL m43 AS FLOAT, _
   BYVAL m44 AS FLOAT, _
   BYVAL m51 AS FLOAT, _
   BYVAL m52 AS FLOAT, _
   BYVAL m53 AS FLOAT, _
   BYVAL m54 AS FLOAT _
   ) AS D2D1_MATRIX_5X4_F

   DIM m AS D2D1_MATRIX_5X4_F
   m.m11 = m11
   m.m12 = m12
   m.m13 = m13
   m.m14 = m14
   m.m21 = m21
   m.m22 = m22
   m.m23 = m23
   m.m24 = m24
   m.m31 = m31
   m.m32 = m32
   m.m31 = m33
   m.m32 = m34
   m.m41 = m41
   m.m42 = m42
   m.m43 = m43
   m.m44 = m44
   m.m51 = m51
   m.m52 = m52
   m.m53 = m53
   m.m53 = m54
   RETURN m

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Matrix5x4F OVERLOAD () AS D2D1_MATRIX_5X4_F

   DIM m AS D2D1_MATRIX_5X4_F
   m.m11 = 1
   m.m12 = 0
   m.m13 = 0
   m.m14 = 0
   m.m21 = 0
   m.m22 = 1
   m.m23 = 0
   m.m24 = 0
   m.m31 = 0
   m.m32 = 0
   m.m33 = 1
   m.m34 = 0
   m.m41 = 0
   m.m42 = 0
   m.m43 = 0
   m.m44 = 1
   m.m51 = 0
   m.m52 = 0
   m.m53 = 0
   m.m53 = 0
   RETURN m

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_DRAWING_STATE_DESCRIPTION1 structure.
' ========================================================================================
PRIVATE FUNCTION D2D1_DrawingStateDescription1 OVERLOAD (BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, _
BYVAL textAntialiasMode AS D2D1_TEXT_ANTIALIAS_MODE = D2D1_TEXT_ANTIALIAS_MODE_DEFAULT, BYVAL tag1 AS D2D1_TAG = 0, _
BYVAL tag2 AS D2D1_TAG = 0, BYREF transform AS D2D1_MATRIX_3X2_F = D2D1_IdentityMatrix(), _
BYVAL primitiveBlend AS D2D1_PRIMITIVE_BLEND = D2D1_PRIMITIVE_BLEND_SOURCE_OVER, _
BYVAL unitMode AS D2D1_UNIT_MODE = D2D1_UNIT_MODE_DIPS) AS D2D1_DRAWING_STATE_DESCRIPTION1

   DIM AS D2D1_DRAWING_STATE_DESCRIPTION1 drawingStateDescription1
   drawingStateDescription1.antialiasMode = antialiasMode
   drawingStateDescription1.textAntialiasMode = textAntialiasMode
   drawingStateDescription1.tag1 = tag1
   drawingStateDescription1.tag2 = tag2
   drawingStateDescription1.transform = transform
   drawingStateDescription1.primitiveBlend = primitiveBlend
   drawingStateDescription1.unitMode = unitMode
   RETURN drawingStateDescription1

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_DrawingStateDescription1 OVERLOAD (BYREF desc AS const D2D1_DRAWING_STATE_DESCRIPTION, _
BYVAL primitiveBlend AS D2D1_PRIMITIVE_BLEND = D2D1_PRIMITIVE_BLEND_SOURCE_OVER, BYVAL unitMode AS D2D1_UNIT_MODE = D2D1_UNIT_MODE_DIPS) _
AS D2D1_DRAWING_STATE_DESCRIPTION1

   DIM AS D2D1_DRAWING_STATE_DESCRIPTION1 drawingStateDescription1
   drawingStateDescription1.antialiasMode = desc.antialiasMode
   drawingStateDescription1.textAntialiasMode = desc.textAntialiasMode
   drawingStateDescription1.tag1 = desc.tag1
   drawingStateDescription1.tag2 = desc.tag2
   drawingStateDescription1.transform = desc.transform
   drawingStateDescription1.primitiveBlend = primitiveBlend
   drawingStateDescription1.unitMode = unitMode
   RETURN drawingStateDescription1

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_BitmapProperties1 (BYVAL bitmapOptions AS D2D1_BITMAP_OPTIONS = D2D1_BITMAP_OPTIONS_NONE, _
BYVAL pixelFormat AS const D2D1_PIXEL_FORMAT = D2D1_PixelFormat(), BYVAL dpiX AS FLOAT = 96.0, BYVAL dpiY AS FLOAT = 96.0, _
BYVAL colorContext AS ID2D1ColorContext PTR = NULL) AS D2D1_BITMAP_PROPERTIES1

   DIM AS D2D1_BITMAP_PROPERTIES1 bitmapProperties
   bitmapProperties.pixelFormat = pixelFormat
   bitmapProperties.dpiX = dpiX
   bitmapProperties.dpiY = dpiY
   bitmapProperties.bitmapOptions = bitmapOptions
   bitmapProperties.colorContext = colorContext
   RETURN bitmapProperties

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_LayerParameters1 (BYREF contentBounds AS const D2D1_RECT_F = D2D1_InfiniteRect(), _
BYVAL geometricMask AS ID2D1Geometry PTR = NULL, BYVAL maskAntialiasMode AS D2D1_ANTIALIAS_MODE = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, _
BYREF maskTransform AS D2D1_MATRIX_3X2_F = D2D1_IdentityMatrix(), BYVAL opacity AS FLOAT = 1.0, BYVAL opacityBrush AS ID2D1Brush PTR = NULL, _
BYVAL layerOptions AS D2D1_LAYER_OPTIONS1 = D2D1_LAYER_OPTIONS1_NONE) AS D2D1_LAYER_PARAMETERS1

   DIM AS D2D1_LAYER_PARAMETERS1 layerParameters
   layerParameters.contentBounds = contentBounds
   layerParameters.geometricMask = geometricMask
   layerParameters.maskAntialiasMode = maskAntialiasMode
   layerParameters.maskTransform = maskTransform
   layerParameters.opacity = opacity
   layerParameters.opacityBrush = opacityBrush
   layerParameters.layerOptions = layerOptions
   RETURN layerParameters

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_StrokeStyleProperties1 (BYVAL startCap AS D2D1_CAP_STYLE = D2D1_CAP_STYLE_FLAT, _
BYVAL endCap AS D2D1_CAP_STYLE = D2D1_CAP_STYLE_FLAT, BYVAL dashCap AS D2D1_CAP_STYLE = D2D1_CAP_STYLE_FLAT, _
BYVAL lineJoin AS D2D1_LINE_JOIN = D2D1_LINE_JOIN_MITER, BYVAL miterLimit AS FLOAT = 10, _
BYVAL dashStyle AS D2D1_DASH_STYLE = D2D1_DASH_STYLE_SOLID, BYVAL dashOffset AS FLOAT = 0.0, _
BYVAL transformType AS D2D1_STROKE_TRANSFORM_TYPE = D2D1_STROKE_TRANSFORM_TYPE_NORMAL) AS D2D1_STROKE_STYLE_PROPERTIES1

   DIM AS D2D1_STROKE_STYLE_PROPERTIES1 strokeStyleProperties
   strokeStyleProperties.startCap = startCap
   strokeStyleProperties.endCap = endCap
   strokeStyleProperties.dashCap = dashCap
   strokeStyleProperties.lineJoin = lineJoin
   strokeStyleProperties.miterLimit = miterLimit
   strokeStyleProperties.dashStyle = dashStyle
   strokeStyleProperties.dashOffset = dashOffset
   strokeStyleProperties.transformType = transformType
   RETURN strokeStyleProperties

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_ImageBrushProperties (BYVAL sourceRectangle AS D2D1_RECT_F, _
BYVAL extendModeX AS D2D1_EXTEND_MODE = D2D1_EXTEND_MODE_CLAMP, BYVAL extendModeY AS D2D1_EXTEND_MODE = D2D1_EXTEND_MODE_CLAMP, _
BYVAL interpolationMode AS D2D1_INTERPOLATION_MODE = D2D1_INTERPOLATION_MODE_LINEAR) AS D2D1_IMAGE_BRUSH_PROPERTIES

   DIM AS D2D1_IMAGE_BRUSH_PROPERTIES imageBrushProperties
   imageBrushProperties.extendModeX = extendModeX
   imageBrushProperties.extendModeY = extendModeY
   imageBrushProperties.interpolationMode = interpolationMode
   imageBrushProperties.sourceRectangle = sourceRectangle
   RETURN imageBrushProperties

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_ImageBrushProperties1 (BYVAL extendModeX AS D2D1_EXTEND_MODE = D2D1_EXTEND_MODE_CLAMP, _
BYVAL extendModeY AS D2D1_EXTEND_MODE = D2D1_EXTEND_MODE_CLAMP, _
BYVAL interpolationMode AS D2D1_INTERPOLATION_MODE = D2D1_INTERPOLATION_MODE_LINEAR) AS D2D1_BITMAP_BRUSH_PROPERTIES1

   DIM AS D2D1_BITMAP_BRUSH_PROPERTIES1 bitmapBrush1Properties
   bitmapBrush1Properties.extendModeX = extendModeX
   bitmapBrush1Properties.extendModeY = extendModeY
   bitmapBrush1Properties.interpolationMode = interpolationMode
   RETURN bitmapBrush1Properties

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_PrintControlProperties (BYVAL fontSubsetMode AS D2D1_PRINT_FONT_SUBSET_MODE = D2D1_PRINT_FONT_SUBSET_MODE_DEFAULT, _
BYVAL rasterDpi AS FLOAT = 150.0, BYVAL colorSpace AS D2D1_COLOR_SPACE = D2D1_COLOR_SPACE_SRGB) AS D2D1_PRINT_CONTROL_PROPERTIES

   DIM AS D2D1_PRINT_CONTROL_PROPERTIES printControlProps
   printControlProps.fontSubset = fontSubsetMode
   printControlProps.rasterDPI = rasterDpi
   printControlProps.colorSpace = colorSpace
   RETURN printControlProps

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_RenderingControls (BYVAL bufferPrecision AS D2D1_BUFFER_PRECISION, _
BYVAL tileSize AS D2D1_SIZE_U) AS D2D1_RENDERING_CONTROLS

   DIM AS D2D1_RENDERING_CONTROLS renderingControls
   renderingControls.bufferPrecision = bufferPrecision
   renderingControls.tileSize = tileSize
   RETURN renderingControls

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_EffectInputDescription (BYVAL effect AS ID2D1Effect PTR, BYVAL inputIndex AS UINT32, _
BYVAL inputRectangle AS D2D1_RECT_F) AS D2D1_EFFECT_INPUT_DESCRIPTION

   DIM AS D2D1_EFFECT_INPUT_DESCRIPTION description
   description.effect = effect
   description.inputIndex = inputIndex
   description.inputRectangle = inputRectangle
   return description

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_CreationProperties (BYVAL threadingMode AS D2D1_THREADING_MODE, BYVAL debugLevel AS D2D1_DEBUG_LEVEL, _
BYVAL options AS D2D1_DEVICE_CONTEXT_OPTIONS) AS D2D1_CREATION_PROPERTIES

   DIM AS D2D1_CREATION_PROPERTIES creationProperties
   creationProperties.threadingMode = threadingMode
   creationProperties.debugLevel = debugLevel
   creationProperties.options = options
   RETURN creationProperties

END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Vector2F (BYVAL x AS FLOAT = 0.0, BYVAL y AS FLOAT = 0.0) AS D2D1_VECTOR_2F
   DIM AS D2D1_VECTOR_2F vec2
   vec2.x = x
   vec2.y = y
   RETURN vec2
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Vector3F (BYVAL x AS FLOAT = 0.0, BYVAL y AS FLOAT = 0.0, BYVAL z AS FLOAT = 0.0) AS D2D1_VECTOR_3F
   DIM AS D2D1_VECTOR_3F vec3
   vec3.x = x
   vec3.y = y
   vec3.y = z
   RETURN vec3
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Vector_4F (BYVAL x AS FLOAT = 0.0, BYVAL y AS FLOAT = 0.0, BYVAL z AS FLOAT = 0.0, BYVAL w AS FLOAT = 0.0) AS D2D1_VECTOR_4F
   DIM AS D2D1_VECTOR_4F vec4
   vec4.x = x
   vec4.y = y
   vec4.y = z
   vec4.y = w
   RETURN vec4
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_Point2L (BYVAL x AS INT32 = 0, BYVAL y AS INT32 = 0) AS D2D1_POINT_2L
   DIM pt2l AS D2D1_POINT_2L
   pt2l.x = x
   pt2l.y = y
   RETURN pt2l
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION D2D1_RectL (BYVAL nLeft AS INT32 = 0, BYVAL nTop AS INT32 = 0, BYVAL nRight AS INT32 = 0, BYVAL nBottom AS INT32 = 0) AS D2D1_RECT_L
   DIM rcl AS D2D1_RECT_L
   rcl.left = nLeft
   rcl.top = nTop
   rcl.right = nRight
   rcl.bottom = nBottom
   RETURN rcl
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies how the Crop effect handles the crop rectangle falling on fractional pixel coordinates.
' ========================================================================================
#ifndef D2D1_BORDER_MODE
enum D2D1_BORDER_MODE
   D2D1_BORDER_MODE_SOFT = 0
   D2D1_BORDER_MODE_HARD = 1
   D2D1_BORDER_MODE_FORCE_DWORD = &hffffffff
end enum
#endif

' ========================================================================================
' Sets a bitmap as an effect input, while inserting a DPI compensation effect
' to preserve visual appearance as the device context's DPI changes.
 ' ========================================================================================
'PRIVATE FUNCTION D2D1_SetDpiCompensatedEffectInput (BYVAL deviceContext AS ID2D1DeviceContext PTR, _
'BYVAL effect AS ID2D1Effect PTR, BYVAL inputIndex AS UINT32, BYVAL inputBitmap AS ID2D1Bitmap PTR, _
'BYVAL interpolationMode AS D2D1_INTERPOLATION_MODE = D2D1_INTERPOLATION_MODE_LINEAR, _
'BYVAL borderMode AS D2D1_BORDER_MODE = D2D1_BORDER_MODE_HARD) AS HRESULT

'   DIM hr AS HRESULT = S_OK
'   DIM AS ID2D1Effect PTR dpiCompensationEffect = NULL

'   IF inputBitmap = NULL THEN
'      effect->SetInput(inputIndex, NULL)
'      RETURN hr
'   ED IF

'   hr = deviceContext->CreateEffect(CLSID_D2D1DpiCompensation, @&dpiCompensationEffect)
'   IF SUCCEEDED(hr) THEN
'      IF SUCCEEDED(hr) THEN
'         dpiCompensationEffect->SetInput(0, inputBitmap)
'         DIM AS D2D1_POINT_2F bitmapDpi
'         inputBitmap->GetDpi(@bitmapDpi.x, @bitmapDpi.y)
'         hr = dpiCompensationEffect->SetValue(D2D1_DPICOMPENSATION_PROP_INPUT_DPI, bitmapDpi)
'      END IF
'      IF SUCCEEDED(hr) THEN
'         hr = dpiCompensationEffect->SetValue(D2D1_DPICOMPENSATION_PROP_INTERPOLATION_MODE, interpolationMode)
'      END IF
'      IF SUCCEEDED(hr) THEN
'         hr = dpiCompensationEffect->SetValue(D2D1_DPICOMPENSATION_PROP_BORDER_MODE, borderMode)
'      END IF
'      IF SUCCEEDED(hr) THEN
'         effect->SetInputEffect(inputIndex, dpiCompensationEffect)
'      END IF
'      IF dpiCompensationEffect THEN
'         dpiCompensationEffect->Release()
'      END IF
'   END IF

'   RETURN hr
'END FUNCTION
' ========================================================================================


' ########################################################################################
'                                 *** D2D1_2Helper.h ***
' ########################################################################################

' ========================================================================================
' Computes the appropriate flattening tolerance to pass to APIs that take a flattening
' tolerance (for instance, ID2D1DeviceContext1.CreateFilledGeometryRealization).
' ========================================================================================
PRIVATE FUNCTION D2D1_ComputeFlatteningTolerance (BYREF matrix AS D2D1_MATRIX_3X2_F, _
BYVAL dpiX AS FLOAT = 96.0, BYVAL dpiY AS FLOAT = 96.0, BYVAL maxZoomFactor AS FLOAT = 1.0) AS FLOAT

'   DIM dpiDependentTransform AS D2D1_MATRIX_3X2_F = matrix * D2D1_MatrixScale(dpiX/96.0, dpiY/96.0)
   DIM dpiDependentTransform AS D2D1_MATRIX_3X2_F = D2D1_MultiplyMatrices(matrix, D2D1_MatrixScale(dpiX/96.0, dpiY/96.0))
   DIM absMaxZoomFactor AS FLOAT = IIF(maxZoomFactor > 0, maxZoomFactor, -maxZoomFactor)
   RETURN D2D1_DEFAULT_FLATTENING_TOLERANCE / (absMaxZoomFactor * D2D1ComputeMaximumScaleFactor(dpiDependentTransform))

END FUNCTION
' ========================================================================================


' ########################################################################################
'                                 *** D2D1_3Helper.h ***
' ########################################################################################

' ========================================================================================
' Creates a D2D1_GRADIENT_MESH_PATCH structure that contains the given control points, colors, and boundary flags.
' ========================================================================================
PRIVATE FUNCTION D2D1_GradientMeshPatch ( _
   BYVAL point00 AS D2D1_POINT_2F, _
   BYVAL point01 AS D2D1_POINT_2F, _
   BYVAL point02 AS D2D1_POINT_2F, _
   BYVAL point03 AS D2D1_POINT_2F, _
   BYVAL point10 AS D2D1_POINT_2F, _
   BYVAL point11 AS D2D1_POINT_2F, _
   BYVAL point12 AS D2D1_POINT_2F, _
   BYVAL point13 AS D2D1_POINT_2F, _
   BYVAL point20 AS D2D1_POINT_2F, _
   BYVAL point21 AS D2D1_POINT_2F, _
   BYVAL point22 AS D2D1_POINT_2F, _
   BYVAL point23 AS D2D1_POINT_2F, _
   BYVAL point30 AS D2D1_POINT_2F, _
   BYVAL point31 AS D2D1_POINT_2F, _
   BYVAL point32 AS D2D1_POINT_2F, _
   BYVAL point33 AS D2D1_POINT_2F, _
   BYVAL color00 AS D2D1_COLOR_F, _
   BYVAL color03 AS D2D1_COLOR_F, _
   BYVAL color30 AS D2D1_COLOR_F, _
   BYVAL color33 AS D2D1_COLOR_F,_
   BYVAL topEdgeMode AS D2D1_PATCH_EDGE_MODE, _
   BYVAL leftEdgeMode AS D2D1_PATCH_EDGE_MODE, _
   BYVAL bottomEdgeMode AS D2D1_PATCH_EDGE_MODE, _
   BYVAL rightEdgeMode AS D2D1_PATCH_EDGE_MODE _
   ) AS D2D1_GRADIENT_MESH_PATCH

   DIM AS D2D1_GRADIENT_MESH_PATCH newPatch
   newPatch.point00 = point00
   newPatch.point01 = point01
   newPatch.point02 = point02
   newPatch.point03 = point03 
   newPatch.point10 = point10
   newPatch.point11 = point11
   newPatch.point12 = point12
   newPatch.point13 = point13 
   newPatch.point20 = point20
   newPatch.point21 = point21
   newPatch.point22 = point22
   newPatch.point23 = point23 
   newPatch.point30 = point30
   newPatch.point31 = point31
   newPatch.point32 = point32
   newPatch.point33 = point33 

   newPatch.color00 = color00
   newPatch.color03 = color03
   newPatch.color30 = color30
   newPatch.color33 = color33

   newPatch.topEdgeMode = topEdgeMode
   newPatch.leftEdgeMode = leftEdgeMode
   newPatch.bottomEdgeMode = bottomEdgeMode
   newPatch.rightEdgeMode = rightEdgeMode

   RETURN newPatch
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_GRADIENT_MESH_PATCH from a given Coons patch description.
' ========================================================================================
PRIVATE FUNCTION D2D1_GradientMeshPatchFromCoonsPatch ( _
   BYVAL point0 AS D2D1_POINT_2F, _
   BYVAL point1 AS D2D1_POINT_2F, _
   BYVAL point2 AS D2D1_POINT_2F, _
   BYVAL point3 AS D2D1_POINT_2F, _
   BYVAL point4 AS D2D1_POINT_2F, _
   BYVAL point5 AS D2D1_POINT_2F, _
   BYVAL point6 AS D2D1_POINT_2F, _
   BYVAL point7 AS D2D1_POINT_2F, _
   BYVAL point8 AS D2D1_POINT_2F, _
   BYVAL point9 AS D2D1_POINT_2F, _
   BYVAL point10 AS D2D1_POINT_2F, _
   BYVAL point11 AS D2D1_POINT_2F, _
   BYVAL color0 AS D2D1_COLOR_F, _
   BYVAL color1 AS D2D1_COLOR_F, _
   BYVAL color2 As D2D1_COLOR_F, _
   BYVAL color3 AS D2D1_COLOR_F, _
   BYVAL topEdgeMode AS D2D1_PATCH_EDGE_MODE, _
   BYVAL leftEdgeMode AS D2D1_PATCH_EDGE_MODE, _
   BYVAL bottomEdgeMode AS D2D1_PATCH_EDGE_MODE, _
   BYVAL rightEdgeMode AS D2D1_PATCH_EDGE_MODE _
   ) AS D2D1_GRADIENT_MESH_PATCH

   DIM AS D2D1_GRADIENT_MESH_PATCH newPatch
   newPatch.point00 = point0
   newPatch.point01 = point1
   newPatch.point02 = point2
   newPatch.point03 = point3
   newPatch.point13 = point4
   newPatch.point23 = point5
   newPatch.point33 = point6
   newPatch.point32 = point7
   newPatch.point31 = point8
   newPatch.point30 = point9
   newPatch.point20 = point10
   newPatch.point10 = point11

   D2D1GetGradientMeshInteriorPointsFromCoonsPatch( _
      @point0, _
      @point1, _
      @point2, _
      @point3, _
      @point4, _
      @point5, _
      @point6, _
      @point7, _
      @point8, _
      @point9, _
      @point10, _
      @point11, _
      @newPatch.point11, _
      @newPatch.point12, _
      @newPatch.point21, _
      @newPatch.point22 _
      )

      newPatch.color00 = color0
      newPatch.color03 = color1
      newPatch.color33 = color2
      newPatch.color30 = color3
      newPatch.topEdgeMode = topEdgeMode
      newPatch.leftEdgeMode = leftEdgeMode
      newPatch.bottomEdgeMode = bottomEdgeMode
      newPatch.rightEdgeMode = rightEdgeMode

      RETURN newPatch
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_INK_POINT structure
' ========================================================================================
PRIVATE FUNCTION D2D1_InkPoint (BYREF pt AS const D2D1_POINT_2F, BYVAL radius AS FLOAT) AS D2D1_INK_POINT
   DIM inkPoint AS D2D1_INK_POINT
   inkPoint.x = pt.x
   inkPoint.y = pt.y
   inkPoint.radius = radius
   RETURN inkPoint
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_INK_BEZIER_SEGMENT structure
' ========================================================================================
PRIVATE FUNCTION D2D1_InkBezierSegment ( _
   BYREF point1 AS const D2D1_INK_POINT, _
   BYREF point2 AS const D2D1_INK_POINT, _
   BYREF point3 AS const D2D1_INK_POINT) AS D2D1_INK_BEZIER_SEGMENT

   DIM inkBezierSegment AS D2D1_INK_BEZIER_SEGMENT
   inkBezierSegment.point1 = point1
   inkBezierSegment.point2 = point2
   inkBezierSegment.point3 = point3
   RETURN inkBezierSegment

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_INK_STYLE_PROPERTIES structure
' ========================================================================================
PRIVATE FUNCtION D2D1_InkStyleProperties (BYVAL nibShape AS D2D1_INK_NIB_SHAPE, _
   BYREF nibTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_INK_STYLE_PROPERTIES

   DIM inkStyleProperties AS D2D1_INK_STYLE_PROPERTIES
   inkStyleProperties.nibShape = nibShape
   inkStyleProperties.nibTransform = nibTransform
   RETURN inkStyleProperties

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a rectangle that has its upper-left corner set to (0u, 0u) and its lower-right
' corner set to (infinity, infinity).
' ========================================================================================
PRIVATE FUNCTION D2D1_InfiniteRectU () AS D2D1_RECT_U
   ' UINT_MAX = &hFFFFFFFF
   DIM AS D2D1_RECT_U rect = (0, 0, &hFFFFFFFF, &hFFFFFFFF)
   RETURN rect
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a D2D1_SIMPLE_COLOR_PROFILE structure
' ========================================================================================
PRIVATE FUNCTION D2D1_SimpleColorProfile ( _
   BYREF redPrimary AS const D2D1_POINT_2F, _
   BYREF greenPrimary AS const D2D1_POINT_2F, _
   BYREF bluePrimary AS const D2D1_POINT_2F, _
   BYREF gamma AS const D2D1_GAMMA1, _
   BYREF whitePointXZ AS const D2D1_POINT_2F _
   ) AS D2D1_SIMPLE_COLOR_PROFILE

   DIM AS D2D1_SIMPLE_COLOR_PROFILE simpleColorProfile
   simpleColorProfile.redPrimary = redPrimary
   simpleColorProfile.greenPrimary = greenPrimary
   simpleColorProfile.bluePrimary = bluePrimary
   simpleColorProfile.gamma = gamma
   simpleColorProfile.whitePointXZ = whitePointXZ
   RETURN simpleColorProfile

END FUNCTION
' ========================================================================================
