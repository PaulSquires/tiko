' D2D1 render target classes
' To be included by AfxD2D1Objects.inc

' ########################################################################################
' CID2D1RenderTarget class
' ########################################################################################

' ========================================================================================
TYPE CID2D1RenderTarget
Public:

   m_pRenderTarget AS ID2D1RenderTarget PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pRenderTarget AS ID2D1RenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RenderTarget PTR

   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR
   ' ---
   DECLARE FUNCTION CreateBitmap (BYVAL size AS D2D1_SIZE_U, BYVAL srcData AS const ANY PTR, _
           BYVAL pitch AS UINT32, BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   DECLARE FUNCTION CreateBitmap (BYVAL size AS D2D1_SIZE_U, BYVAL srcData AS const ANY PTR, _
           BYVAL pitch AS UINT32, BYVAL bitmapProperties AS D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   DECLARE FUNCTION CreateBitmap (BYVAL nWidth AS UINT32, BYVAL nHeight AS UINT32, BYVAL srcData AS const ANY PTR, _
           BYVAL pitch AS UINT32, BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   DECLARE FUNCTION CreateBitmap (BYVAL nWidth AS UINT32, BYVAL nHeight AS UINT32, BYVAL srcData AS const ANY PTR, _
           BYVAL pitch AS UINT32, BYVAL bitmapProperties AS D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   ' ---
   DECLARE FUNCTION CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR, _
           BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   DECLARE FUNCTION CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR, _
           BYVAL bitmapProperties AS const D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   DECLARE FUNCTION CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR) AS ID2D1Bitmap PTR
   ' ---
   DECLARE FUNCTION CreateSharedBitmap (BYREF iid AS IID, BYVAL pdata AS ANY PTR, _
           BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   DECLARE FUNCTION CreateSharedBitmap (BYVAL iid AS IID PTR, BYVAL pdata AS ANY PTR, _
           BYVAL bitmapProperties AS const D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   ' ---
   DECLARE FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES, _
           BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES) AS ID2D1BitmapBrush PTR
   DECLARE FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES PTR, _
           BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR) AS ID2D1BitmapBrush PTR
   DECLARE FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, _
           BYREF bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES) AS ID2D1BitmapBrush PTR
   DECLARE FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, _
           BYVAL bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES PTR) AS ID2D1BitmapBrush PTR
   DECLARE FUNCTION CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR) AS ID2D1BitmapBrush PTR
   ' ---
   DECLARE FUNCTION CreateSolidColorBrush (BYREF clr AS D2D1_COLOR_F, _
           BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES) AS ID2D1SolidColorBrush PTR
   DECLARE FUNCTION CreateSolidColorBrush (BYVAL clr AS D2D1_COLOR_F PTR, _
           BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR) AS ID2D1SolidColorBrush PTR
   DECLARE FUNCTION CreateSolidColorBrush (BYVAL clr AS D2D1_COLOR_F PTR) AS ID2D1SolidColorBrush PTR

   ' // ====== Gradient stop collection ======
   DECLARE FUNCTION CreateGradientStopCollection (BYREF gradientStops AS D2D1_GRADIENT_STOP, _
           BYVAL gradientStopsCount AS UINT32, BYVAL colorInterpolationGamma AS D2D1_GAMMA, _
           BYVAL extendMode AS D2D1_EXTEND_MODE) AS ID2D1GradientStopCollection PTR
   DECLARE FUNCTION CreateGradientStopCollection (BYVAL gradientStops AS D2D1_GRADIENT_STOP PTR, _
           BYVAL gradientStopsCount AS UINT32, BYVAL colorInterpolationGamma AS D2D1_GAMMA, _
           BYVAL extendMode AS D2D1_EXTEND_MODE) AS ID2D1GradientStopCollection PTR
   DECLARE FUNCTION CreateGradientStopCollection (BYREF gradientStops AS D2D1_GRADIENT_STOP, _
           BYVAL gradientStopsCount AS UINT32) AS ID2D1GradientStopCollection PTR
   DECLARE FUNCTION CreateGradientStopCollection (BYVAL gradientStops AS D2D1_GRADIENT_STOP PTR, _
           BYVAL gradientStopsCount AS UINT32) AS ID2D1GradientStopCollection PTR

   ' // ====== Linear gradient brush ======
   DECLARE FUNCTION CreateLinearGradientBrush ( _
           BYREF linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES, _
           BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   DECLARE FUNCTION CreateLinearGradientBrush ( _
           BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, _
           BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   ' ---
   DECLARE FUNCTION CreateLinearGradientBrush ( _
           BYVAL linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES PTR, _
           BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   DECLARE FUNCTION CreateLinearGradientBrush ( _
           BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, _
           BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   ' ---
   DECLARE FUNCTION CreateLinearGradientBrush ( _
           BYREF linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   DECLARE FUNCTION CreateLinearGradientBrush ( _
           BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   ' ---

   ' // ====== Radial gradient brush ======
   DECLARE FUNCTION CreateRadialGradientBrush ( _
           BYREF radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES, _
           BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   DECLARE FUNCTION CreateRadialGradientBrush (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE, _
           BYVAL originOffsetX AS SINGLE, BYVAL originOffsetY AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
           BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   ' ---
   DECLARE FUNCTION CreateRadialGradientBrush ( _
           BYVAL radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES PTR, _
           BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   DECLARE FUNCTION CreateRadialGradientBrush (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE, _
           BYVAL originOffsetX AS SINGLE, BYVAL originOffsetY AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
           BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   ' ---
   DECLARE FUNCTION CreateRadialGradientBrush ( _
           BYREF radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   DECLARE FUNCTION CreateRadialGradientBrush (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE, BYVAL originOffsetX AS SINGLE, _
           BYVAL originOffsetY AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
           BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR

   ' // ====== Create compatible render target ======
   DECLARE FUNCTION CreateCompatibleRenderTarget () AS ID2D1BitmapRenderTarget PTR  
   ' ---
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F) AS ID2D1BitmapRenderTarget PTR
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYVAL desiredSize AS const D2D1_SIZE_F PTR) AS ID2D1BitmapRenderTarget PTR
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYVAL desiredSizeWidth AS SINGLE, BYVAL desiredSizeHeight AS SINGLE) AS ID2D1BitmapRenderTarget PTR
   ' ---
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F, _
           BYREF desiredPixelSize AS const D2D1_SIZE_U) AS ID2D1BitmapRenderTarget PTR
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYVAL desiredSize AS const D2D1_SIZE_F PTR, _
           BYVAL desiredPixelSize AS const D2D1_SIZE_U PTR) AS ID2D1BitmapRenderTarget PTR
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYVAL desiredSizeWidth AS SINGLE, BYVAL desiredSizeHeight AS SINGLE, _
           BYVAL desiredPixelSizeWidth AS UINT32, BYVAL desiredPixelSizeWidthHeight AS UINT32) AS ID2D1BitmapRenderTarget PTR
   ' ---
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F, _
           BYREF desiredPixelSize AS const D2D1_SIZE_U, BYREF desiredFormat AS const D2D1_PIXEL_FORMAT, _
           BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS) AS ID2D1BitmapRenderTarget PTR
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYVAL desiredSize AS const D2D1_SIZE_F PTR, _
           BYVAL desiredPixelSize AS const D2D1_SIZE_U PTR, BYVAL desiredFormat AS const D2D1_PIXEL_FORMAT PTR, _
           BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS) AS ID2D1BitmapRenderTarget PTR
   DECLARE FUNCTION CreateCompatibleRenderTarget (BYVAL desiredSizeWidth AS SINGLE, _
           BYVAL desiredSizeHeight AS SINGLE, BYVAL desiredPixelSizeWidth AS UINT32, BYVAL desiredPixelSizeWidthHeight AS UINT32, _
           BYREF desiredFormat AS const D2D1_PIXEL_FORMAT, BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS) AS ID2D1BitmapRenderTarget PTR
   ' ---
   DECLARE FUNCTION CreateLayer (BYREF size AS const D2D1_SIZE_F) AS ID2D1Layer PTR
   DECLARE FUNCTION CreateLayer (BYVAL size AS const D2D1_SIZE_F PTR) AS ID2D1Layer PTR
   DECLARE FUNCTION CreateLayer (BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) AS ID2D1Layer PTR
   DECLARE FUNCTION CreateLayer () AS ID2D1Layer PTR
   ' ---
   DECLARE FUNCTION CreateMesh () AS ID2D1Mesh PTR
   ' ---
   DECLARE SUB DrawLine (BYVAL point0 AS D2D1_POINT_2F, BYVAL point1 AS D2D1_POINT_2F, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE SUB DrawLine (BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, _
           BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   ' ---
   DECLARE SUB DrawRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE SUB DrawRectangle (BYVAL rect AS const D2D1_RECT_F PTR, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE SUB DrawRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, BYVAL right AS SINGLE, _
           BYVAL bottom AS SINGLE, BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   ' ---
   DECLARE SUB FillRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillRectangle (BYVAL rect AS const D2D1_RECT_F PTR, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, BYVAL right AS SINGLE, BYVAL bottom AS SINGLE, BYVAL brush AS ID2D1Brush PTR)
   ' ---
   DECLARE SUB DrawRoundedRectangle (BYREF roundedRect AS const D2D1_ROUNDED_RECT, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE SUB DrawRoundedRectangle (BYVAL roundedRect AS const D2D1_ROUNDED_RECT PTR, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   DECLARE SUB DrawRoundedRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, _
           BYVAL right AS SINGLE, BYVAL bottom AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiuxY AS SINGLE, _
           BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   ' ---
   DECLARE SUB FillRoundedRectangle (BYREF roundedRect AS const D2D1_ROUNDED_RECT, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillRoundedRectangle (BYVAL roundedRect AS const D2D1_ROUNDED_RECT PTR, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillRoundedRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, BYVAL right AS SINGLE, _
           BYVAL bottom AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, BYVAL brush AS ID2D1Brush PTR)
   ' ---
   DECLARE SUB DrawEllipse (BYREF tEllipse AS const D2D1_ELLIPSE, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   DECLARE SUB DrawEllipse (BYVAL tEllipse AS const D2D1_ELLIPSE PTR, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   DECLARE SUB DrawEllipse (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
           BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   ' ---
   DECLARE SUB FillEllipse (BYREF tEllipse AS const D2D1_ELLIPSE, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillEllipse (BYVAL tEllipse AS const D2D1_ELLIPSE PTR, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillEllipse (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL radiusX AS SINGLE, _
           BYVAL radiusY AS SINGLE, BYVAL brush AS ID2D1Brush PTR)
   ' ---
   DECLARE SUB DrawGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   DECLARE SUB FillGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR)
   DECLARE SUB FillMesh (BYVAL mesh AS ID2D1Mesh PTR, BYVAL brush AS ID2D1Brush PTR)
   ' ---
   DECLARE SUB FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL content AS D2D1_OPACITY_MASK_CONTENT, BYREF destinationRectangle AS const D2D1_RECT_F, _
           BYREF sourceRectangle AS const D2D1_RECT_F)
   DECLARE SUB FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
           BYVAL content AS D2D1_OPACITY_MASK_CONTENT, BYVAL destinationRectangle AS const D2D1_RECT_F PTR, _
           BYVAL sourceRectangle AS const D2D1_RECT_F PTR)
   ' ---
   DECLARE SUB DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF destinationRectangle AS const D2D1_RECT_F, _
           BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
           BYREF sourceRectangle AS const D2D1_RECT_F)
   DECLARE SUB DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL destinationRectangle AS const D2D1_RECT_F PTR, _
           BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
           BYVAL sourceRectangle AS const D2D1_RECT_F PTR)
   DECLARE SUB DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL destRectLeft AS SINGLE, BYVAL destRectTop AS SINGLE, _
           BYVAL destRectRight AS SINGLE, BYVAL destRectBottom AS SINGLE, BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
           BYVAL sourceRectangleLeft AS SINGLE, BYVAL sourceRectangleLeftTop AS SINGLE, BYVAL sourceRectangleRight AS SINGLE, BYVAL sourceRectangleBottom AS SINGLE)
   ' ---
   DECLARE SUB DrawText (BYREF wzSstr AS WSTRING, BYVAL stringLength AS UINT32, _
           BYVAL textFormat AS IDWriteTextFormat PTR, BYREF layoutRect AS D2D1_RECT_F, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
           BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE SUB DrawText (BYVAL pwzSstr AS WSTRING PTR, BYVAL stringLength AS UINT32, _
           BYVAL textFormat AS IDWriteTextFormat PTR, BYVAL layoutRect AS D2D1_RECT_F PTR, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
           BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE SUB DrawText (BYREF wzSstr AS WSTRING, BYVAL stringLength AS UINT32, _
           BYVAL textFormat AS IDWriteTextFormat PTR, BYVAL layoutRectLeft AS SINGLE, BYVAL layoutRectTop AS SINGLE, _
           BYVAL layoutRectRight AS SINGLE, BYVAL layoutRectBottom AS SINGLE, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
           BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, _
           BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   ' ---
   DECLARE SUB DrawTextLayout (BYVAL origin AS D2D1_POINT_2F, BYVAL textLayout AS IDWriteTextLayout PTR, _
           BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE) 
   DECLARE SUB DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
           BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE SUB DrawTextLayout (BYVAL originX AS SINGLE, BYVAL originY AS SINGLE, BYVAL textLayout AS IDWriteTextLayout PTR, _
           BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE) 
   ' ---
   DECLARE SUB DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYVAL glyphRun AS const DWRITE_GLYPH_RUN PTR, _
           BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   DECLARE SUB DrawGlyphRun (BYVAL baselineOriginX AS SINGLE, BYVAL baselineOriginY AS SINGLE, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
           BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   ' ---
   DECLARE SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F
   ' ---
   DECLARE SUB SetAntialiasMode (BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   DECLARE FUNCTION GetAntialiasMode () AS D2D1_ANTIALIAS_MODE
   DECLARE SUB SetTextAntialiasMode (BYVAL textAntialiasMode AS D2D1_TEXT_ANTIALIAS_MODE)
   DECLARE FUNCTION GetTextAntialiasMode () AS D2D1_TEXT_ANTIALIAS_MODE
   DECLARE SUB SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE SUB GetTextRenderingParams (BYREF textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE FUNCTION GetTextRenderingParams () AS IDWriteRenderingParams PTR
   DECLARE SUB SetTags (BYVAL tag1 AS D2D1_TAG, BYVAL tag2 AS D2D1_TAG)
   DECLARE SUB GetTags (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL)
   DECLARE SUB GetTags (BYVAL tag1 AS D2D1_TAG PTR = NULL, BYVAL tag2 AS D2D1_TAG PTR = NULL)
   DECLARE SUB PushLayer (BYREF layerParameters AS D2D1_LAYER_PARAMETERS, BYVAL layer AS ID2D1Layer PTR)
   DECLARE SUB PushLayer (BYVAL layerParameters AS D2D1_LAYER_PARAMETERS PTR, BYVAL layer AS ID2D1Layer PTR)
   DECLARE SUB PopLayer
   DECLARE FUNCTION Flush (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL) AS HRESULT
   DECLARE FUNCTION Flush (BYVAL tag1 AS D2D1_TAG PTR = NULL, BYVAL tag2 AS D2D1_TAG PTR = NULL) AS HRESULT
   DECLARE SUB SaveDrawingState (BYVAL drawingStateBlock AS ID2D1DrawingStateBlock PTR)
   DECLARE SUB RestoreDrawingState (BYVAL drawingStateBlock AS ID2D1DrawingStateBlock PTR)
   ' ---
   DECLARE SUB PushAxisAlignedClip (BYREF clipRect AS D2D1_RECT_F, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   DECLARE SUB PushAxisAlignedClip (BYVAL clipRect AS D2D1_RECT_F PTR, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   DECLARE SUB PushAxisAlignedClip (BYVAL clipRectLeft AS SINGLE, BYVAL clipRecTop AS SINGLE, _
           BYVAL clipRectRight AS SINGLE, BYVAL clipRectBottom AS SINGLE, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   ' ---
   DECLARE SUB PopAxisAlignedClip
   DECLARE SUB Clear (BYREF clearColor AS const D2D1_COLOR_F)
   DECLARE SUB Clear (BYVAL clearColor AS const D2D1_COLOR_F PTR)
   DECLARE SUB Clear (BYVAL clearColor AS UINT32, BYVAL alpha AS FLOAT = 1.0)
   DECLARE SUB BeginDraw
   DECLARE FUNCTION EndDraw (BYREF tag1 AS D2D1_TAG, BYREF tag2 AS D2D1_TAG) AS HRESULT
   DECLARE FUNCTION EndDraw (BYVAL tag1 AS D2D1_TAG PTR = NULL, BYVAL tag2 AS D2D1_TAG PTR = NULL) AS HRESULT
   DECLARE SUB GetPixelFormat (BYREF pixelFormat AS D2D1_PIXEL_FORMAT)
   DECLARE SUB GetPixelFormat (BYVAL pixelFormat AS D2D1_PIXEL_FORMAT PTR)
   DECLARE FUNCTION GetPixelFormat () AS D2D1_PIXEL_FORMAT
   DECLARE SUB SetDpi (BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT)
   DECLARE SUB GetDpi (BYREF dpiX AS FLOAT, BYREF dpiY AS FLOAT)
   DECLARE FUNCTION GetDpiX () AS FLOAT
   DECLARE FUNCTION GetDpiY () AS FLOAT
   ' ---
   DECLARE SUB GetSize (BYREF size AS D2D1_SIZE_F)
   DECLARE SUB GetSize (BYVAL size AS D2D1_SIZE_F PTR)
   DECLARE FUNCTION GetSize () AS D2D1_SIZE_F
   DECLARE FUNCTION GetSizeWidth () AS SINGLE
   DECLARE FUNCTION GetSizeHeight () AS SINGLE
   DECLARE SUB GetPixelSize (BYREF pixelSize AS D2D1_SIZE_U)
   DECLARE SUB GetPixelSize (BYVAL pixelSize AS D2D1_SIZE_U PTR)
   DECLARE FUNCTION GetPixelSize () AS D2D1_SIZE_U
   DECLARE FUNCTION GetPixelWidth () AS SINGLE
   DECLARE FUNCTION GetPixelHeight () AS SINGLE
   ' ---
   DECLARE FUNCTION GetMaximumBitmapSize () AS UINT32
   DECLARE FUNCTION IsSupported (BYREF renderTargetProperties AS const D2D1_RENDER_TARGET_PROPERTIES) AS BOOLEAN
   DECLARE FUNCTION IsSupported (BYVAL renderTargetProperties AS const D2D1_RENDER_TARGET_PROPERTIES PTR) AS BOOLEAN

 END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RenderTarget class.
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RenderTarget
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RenderTarget (BYVAL pRenderTarget AS ID2D1RenderTarget PTR)
   D2D1_DP("pRenderTarget - " & WSTR(pRenderTarget))
   m_pRenderTarget = pRenderTarget
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RenderTarget
   D2D1_DP("m_pRenderTarget: " & WSTR(m_pRenderTarget))
   IF m_pRenderTarget THEN m_pRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1RenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1RenderTarget) AS ID2D1RenderTarget PTR
   RETURN renderTarget.m_pRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1RenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RenderTarget.@ () AS ID2D1RenderTarget PTR PTR
   RETURN @m_pRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1RenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RenderTarget.CAST () AS ID2D1RenderTarget PTR
   RETURN m_pRenderTarget
END OPERATOR
' ========================================================================================

' ========================================================================================
' ID2D1Resource
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1RenderTarget PTR, m_pRenderTarget)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an uninitialized Direct2D bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmap (BYVAL size AS D2D1_SIZE_U, BYVAL srcData AS const ANY PTR, _
BYVAL pitch AS UINT32, BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   m_pRenderTarget->CreateBitmap(size, srcData, pitch, bitmapProperties, bitmap)
   RETURN bitmap
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmap (BYVAL size AS D2D1_SIZE_U, BYVAL srcData AS const ANY PTR, _
BYVAL pitch AS UINT32, BYVAL bitmapProperties AS D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLastError(m_pRenderTarget->CreateBitmap(size, srcData, pitch, BYVAL bitmapProperties, bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmap (BYVAL nWidth AS UINT32, BYVAL nHeight AS UINT32, BYVAL srcData AS const ANY PTR, _
BYVAL pitch AS UINT32, BYREF bitmapProperties AS D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM size AS D2D1_SIZE_U = (nwidth, nHeight)
   DIM bitmap AS ID2D1Bitmap PTR
   m_pRenderTarget->CreateBitmap(size, srcData, pitch, bitmapProperties, bitmap)
   RETURN bitmap
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmap (BYVAL nWidth AS UINT32, BYVAL nHeight AS UINT32, BYVAL srcData AS const ANY PTR, _
BYVAL pitch AS UINT32, BYVAL bitmapProperties AS D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM size AS D2D1_SIZE_U = (nwidth, nHeight)
   DIM bitmap AS ID2D1Bitmap PTR
   m_pRenderTarget->CreateBitmap(size, srcData, pitch, BYVAL bitmapProperties, bitmap)
   RETURN bitmap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1Bitmap by copying the specified Microsoft Windows Imaging Component (WIC) bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR, _
BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLastError(m_pRenderTarget->CreateBitmapFromWicBitmap(wicBitmapSource, bitmapProperties, bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR, _
BYVAL bitmapProperties AS const D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLastError(m_pRenderTarget->CreateBitmapFromWicBitmap(wicBitmapSource, BYVAL bitmapProperties, bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapFromWicBitmap (BYVAL wicBitmapSource AS IWICBitmapSource PTR) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLastError(m_pRenderTarget->CreateBitmapFromWicBitmap(wicBitmapSource, BYVAL NULL, bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1Bitmap whose data is shared with another resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateSharedBitmap (BYREF iid AS IID, BYVAL pdata AS ANY PTR, _
BYREF bitmapProperties AS const D2D1_BITMAP_PROPERTIES) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLastError(m_pRenderTarget->CreateSharedBitmap(iid, pdata, bitmapProperties, bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateSharedBitmap (BYVAL iid AS IID PTR, BYVAL pdata AS ANY PTR, _
BYVAL bitmapProperties AS const D2D1_BITMAP_PROPERTIES PTR) AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLastError(m_pRenderTarget->CreateSharedBitmap(BYVAL iid, pdata, BYVAL bitmapProperties, bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1BitmapBrush from the specified bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES, _
BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES) AS ID2D1BitmapBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapBrush AS ID2D1BitmapBrush PTR
   SetLastError(m_pRenderTarget->CreateBitmapBrush(bitmap, bitmapBrushProperties, brushProperties, bitmapBrush))
   RETURN bitmapBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES PTR, _
BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR) AS ID2D1BitmapBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapBrush AS ID2D1BitmapBrush PTR
   SetLastError(m_pRenderTarget->CreateBitmapBrush(bitmap, BYVAL bitmapBrushProperties, BYVAL brushProperties, bitmapBrush))
   RETURN bitmapBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, _
BYREF bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES) AS ID2D1BitmapBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapBrush AS ID2D1BitmapBrush PTR
   SetLastError(m_pRenderTarget->CreateBitmapBrush(bitmap, bitmapBrushProperties, BYVAL NULL, bitmapBrush))
   RETURN bitmapBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateBitmapBrush (BYVAL bitmap AS ID2D1Bitmap PTR, _
BYVAL bitmapBrushProperties AS const D2D1_BITMAP_BRUSH_PROPERTIES PTR) AS ID2D1BitmapBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapBrush AS ID2D1BitmapBrush PTR
   SetLastError(m_pRenderTarget->CreateBitmapBrush(bitmap, BYVAL bitmapBrushProperties, BYVAL NULL, bitmapBrush))
   RETURN bitmapBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateSolidColorBrush (BYREF clr AS D2D1_COLOR_F, _
BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES) AS ID2D1SolidColorBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM solidColorBrush AS ID2D1SolidColorBrush PTR
   SetLastError(m_pRenderTarget->CreateSolidColorBrush(clr, brushProperties, solidColorBrush))
   RETURN solidColorBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateSolidColorBrush (BYVAL clr AS D2D1_COLOR_F PTR, _
BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR) AS ID2D1SolidColorBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM solidColorBrush AS ID2D1SolidColorBrush PTR
   SetLastError(m_pRenderTarget->CreateSolidColorBrush(BYVAL clr, BYVAL brushProperties, solidColorBrush))
   RETURN solidColorBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateSolidColorBrush (BYVAL clr AS D2D1_COLOR_F PTR) AS ID2D1SolidColorBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM solidColorBrush AS ID2D1SolidColorBrush PTR
   SetLastError(m_pRenderTarget->CreateSolidColorBrush(BYVAL clr, BYVAL NULL, solidColorBrush))
   RETURN solidColorBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1GradientStopCollection from the specified array of D2D1_GRADIENT_STOP structures.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateGradientStopCollection (BYREF gradientStops AS D2D1_GRADIENT_STOP, _
BYVAL gradientStopsCount AS UINT32, BYVAL colorInterpolationGamma AS D2D1_GAMMA, _
BYVAL extendMode AS D2D1_EXTEND_MODE) AS ID2D1GradientStopCollection PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM gradientStopCollection AS ID2D1GradientStopCollection PTR
   SetLastError(m_pRenderTarget->CreateGradientStopCollection(gradientStops, gradientStopsCount, colorInterpolationGamma, _
      extendMode, gradientStopCollection))
   RETURN gradientStopCollection
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateGradientStopCollection (BYVAL gradientStops AS D2D1_GRADIENT_STOP PTR, _
BYVAL gradientStopsCount AS UINT32, BYVAL colorInterpolationGamma AS D2D1_GAMMA, _
BYVAL extendMode AS D2D1_EXTEND_MODE) AS ID2D1GradientStopCollection PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM gradientStopCollection AS ID2D1GradientStopCollection PTR
   SetLastError(m_pRenderTarget->CreateGradientStopCollection(BYVAL gradientStops, gradientStopsCount, colorInterpolationGamma, _
      extendMode, gradientStopCollection))
   RETURN gradientStopCollection
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateGradientStopCollection (BYREF gradientStops AS D2D1_GRADIENT_STOP, _
BYVAL gradientStopsCount AS UINT32) AS ID2D1GradientStopCollection PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM gradientStopCollection AS ID2D1GradientStopCollection PTR
   SetLastError(m_pRenderTarget->CreateGradientStopCollection(gradientStops, gradientStopsCount, D2D1_GAMMA_2_2, _
      D2D1_EXTEND_MODE_CLAMP, gradientStopCollection))
   RETURN gradientStopCollection
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateGradientStopCollection (BYVAL gradientStops AS D2D1_GRADIENT_STOP PTR, _
BYVAL gradientStopsCount AS UINT32) AS ID2D1GradientStopCollection PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM gradientStopCollection AS ID2D1GradientStopCollection PTR
   SetLastError(m_pRenderTarget->CreateGradientStopCollection(BYVAL gradientStops, gradientStopsCount, D2D1_GAMMA_2_2, _
      D2D1_EXTEND_MODE_CLAMP, gradientStopCollection))
   RETURN gradientStopCollection
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1LinearGradientBrush object for painting areas with a linear gradient.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLinearGradientBrush ( _
BYREF linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES, _
BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM linearGradientBrush AS ID2D1LinearGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateLinearGradientBrush(linearGradientBrushProperties, brushProperties, _
      gradientStopCollection, linearGradientBrush))
   RETURN linearGradientBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLinearGradientBrush ( _
BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, _
BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM LinearGradientBrushProps AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
   LinearGradientBrushProps.startPoint = D2D1_Point2F(startPointX, startPointY)    ' gradient start
   LinearGradientBrushProps.endPoint   = D2D1_Point2F(endPointX, endPointY)        ' gradient end (vertical)
   DIM linearGradientBrush AS ID2D1LinearGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProps, brushProperties, _
      gradientStopCollection, linearGradientBrush))
   RETURN linearGradientBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLinearGradientBrush ( _
BYVAL linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES PTR, _
BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM linearGradientBrush AS ID2D1LinearGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateLinearGradientBrush(BYVAL linearGradientBrushProperties, BYVAL brushProperties, _
      gradientStopCollection, linearGradientBrush))
   RETURN linearGradientBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLinearGradientBrush ( _
BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, _
BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM LinearGradientBrushProps AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
   LinearGradientBrushProps.startPoint = D2D1_Point2F(startPointX, startPointY)    ' gradient start
   LinearGradientBrushProps.endPoint   = D2D1_Point2F(endPointX, endPointY)        ' gradient end (vertical)
   DIM linearGradientBrush AS ID2D1LinearGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProps, BYVAL brushProperties, _
      gradientStopCollection, linearGradientBrush))
   RETURN linearGradientBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLinearGradientBrush ( _
BYREF linearGradientBrushProperties AS const D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM linearGradientBrush AS ID2D1LinearGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateLinearGradientBrush(linearGradientBrushProperties, BYVAL NULL, _
      gradientStopCollection, linearGradientBrush))
   RETURN linearGradientBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLinearGradientBrush ( _
BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1LinearGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM LinearGradientBrushProps AS D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
   LinearGradientBrushProps.startPoint = D2D1_Point2F(startPointX, startPointY)    ' gradient start
   LinearGradientBrushProps.endPoint   = D2D1_Point2F(endPointX, endPointY)        ' gradient end (vertical)
   DIM linearGradientBrush AS ID2D1LinearGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProps, BYVAL NULL, gradientStopCollection, linearGradientBrush))
   RETURN linearGradientBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates an ID2D1RadialGradientBrush object that can be used to paint areas with a radial gradient.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateRadialGradientBrush ( _
BYREF radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES, _
BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM radialGradientBrush AS ID2D1RadialGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateRadialGradientBrush(radialGradientBrushProperties, brushProperties, _
      gradientStopCollection, radialGradientBrush))
   RETURN radialGradientBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateRadialGradientBrush (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE, _
BYVAL originOffsetX AS SINGLE, BYVAL originOffsetY AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
BYREF brushProperties AS const D2D1_BRUSH_PROPERTIES, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
   radialGradientBrushProperties.center = D2D1_Point2F(centerX, centerY)
   radialGradientBrushProperties.gradientOriginOffset = D2D1_Point2F(originOffsetX, originOffsetY)
   radialGradientBrushProperties.radiusX = radiusX
   radialGradientBrushProperties.radiusY = radiusY
   DIM radialGradientBrush AS ID2D1RadialGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateRadialGradientBrush(radialGradientBrushProperties, brushProperties, _
      gradientStopCollection, radialGradientBrush))
   RETURN radialGradientBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateRadialGradientBrush ( _
BYVAL radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES PTR, _
BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM radialGradientBrush AS ID2D1RadialGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateRadialGradientBrush(BYVAL radialGradientBrushProperties, BYVAL brushProperties, _
      gradientStopCollection, radialGradientBrush))
   RETURN radialGradientBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateRadialGradientBrush (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE, _
BYVAL originOffsetX AS SINGLE, BYVAL originOffsetY AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
BYVAL brushProperties AS const D2D1_BRUSH_PROPERTIES PTR, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
   radialGradientBrushProperties.center = D2D1_Point2F(centerX, centerY)
   radialGradientBrushProperties.gradientOriginOffset = D2D1_Point2F(originOffsetX, originOffsetY)
   radialGradientBrushProperties.radiusX = radiusX
   radialGradientBrushProperties.radiusY = radiusY
   DIM radialGradientBrush AS ID2D1RadialGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateRadialGradientBrush(radialGradientBrushProperties, BYVAL brushProperties, _
      gradientStopCollection, radialGradientBrush))
   RETURN radialGradientBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateRadialGradientBrush ( _
BYREF radialGradientBrushProperties AS const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM radialGradientBrush AS ID2D1RadialGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateRadialGradientBrush(radialGradientBrushProperties, BYVAL NULL, _
      gradientStopCollection, radialGradientBrush))
   RETURN radialGradientBrush
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateRadialGradientBrush ( _
BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE, BYVAL originOffsetX AS SINGLE, BYVAL originOffsetY AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
BYVAL gradientStopCollection AS ID2D1GradientStopCollection PTR) AS ID2D1RadialGradientBrush PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM radialGradientBrushProperties AS D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
   radialGradientBrushProperties.center = D2D1_Point2F(centerX, centerY)
   radialGradientBrushProperties.gradientOriginOffset = D2D1_Point2F(originOffsetX, originOffsetY)
   radialGradientBrushProperties.radiusX = radiusX
   radialGradientBrushProperties.radiusY = radiusY
   DIM radialGradientBrush AS ID2D1RadialGradientBrush PTR
   SetLastError(m_pRenderTarget->CreateRadialGradientBrush(radialGradientBrushProperties, BYVAL NULL, _
      gradientStopCollection, radialGradientBrush))
   RETURN radialGradientBrush
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new bitmap render target for use during intermediate offscreen drawing that is
' compatible with the current render target .
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget () AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(BYVAL NULL, BYVAL NULL, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(desiredSize, BYVAL NULL, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYVAL desiredSize AS const D2D1_SIZE_F PTR) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(BYVAL desiredSize, BYVAL NULL, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYVAL desiredSizeWidth AS SINGLE, BYVAL desiredSizeHeight AS SINGLE) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM desiredSize AS D2D1_SIZE_F = (desiredSizeWidth, desiredSizeHeight)
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(desiredSize, BYVAL NULL, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F, _
BYREF desiredPixelSize AS const D2D1_SIZE_U) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(desiredSize, desiredPixelSize, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYVAL desiredSize AS const D2D1_SIZE_F PTR, _
BYVAL desiredPixelSize AS const D2D1_SIZE_U PTR) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(BYVAL desiredSize, BYVAL desiredPixelSize, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYVAL desiredSizeWidth AS SINGLE, BYVAL desiredSizeHeight AS SINGLE, _
BYVAL desiredPixelSizeWidth AS UINT32, BYVAL desiredPixelSizeWidthHeight AS UINT32) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   DIM desiredSize AS D2D1_SIZE_F = (desiredSizeWidth, desiredSizeHeight)
   DIM desiredPixelSize AS D2D1_SIZE_U = (desiredPixelSizeWidth, desiredPixelSizeWidthHeight)
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(desiredSize, desiredPixelSize, _
      BYVAL NULL, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYREF desiredSize AS const D2D1_SIZE_F, _
BYREF desiredPixelSize AS const D2D1_SIZE_U, BYREF desiredFormat AS const D2D1_PIXEL_FORMAT, _
BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(desiredSize, desiredPixelSize, desiredFormat, options, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYVAL desiredSize AS const D2D1_SIZE_F PTR, _
BYVAL desiredPixelSize AS const D2D1_SIZE_U PTR, BYVAL desiredFormat AS const D2D1_PIXEL_FORMAT PTR, _
BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(BYVAL desiredSize, BYVAL desiredPixelSize, BYVAL desiredFormat, options, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateCompatibleRenderTarget (BYVAL desiredSizeWidth AS SINGLE, _
BYVAL desiredSizeHeight AS SINGLE, BYVAL desiredPixelSizeWidth AS UINT32, BYVAL desiredPixelSizeWidthHeight AS UINT32, _
BYREF desiredFormat AS const D2D1_PIXEL_FORMAT, BYVAL options AS D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS) AS ID2D1BitmapRenderTarget PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM bitmapRenderTarget AS ID2D1BitmapRenderTarget PTR
   DIM desiredSize AS D2D1_SIZE_F = (desiredSizeWidth, desiredSizeHeight)
   DIM desiredPixelSize AS D2D1_SIZE_U = (desiredPixelSizeWidth, desiredPixelSizeWidthHeight)
   SetLastError(m_pRenderTarget->CreateCompatibleRenderTarget(desiredSize, desiredPixelSize, desiredFormat, options, bitmapRenderTarget))
   RETURN bitmapRenderTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a layer resource that can be used with this render target and its compatible render targets.
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLayer (BYREF size AS const D2D1_SIZE_F) AS ID2D1Layer PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM layer AS ID2D1Layer PTR
   SetLastError(m_pRenderTarget->CreateLayer(size, layer))
   RETURN layer
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLayer (BYVAL size AS const D2D1_SIZE_F PTR) AS ID2D1Layer PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM layer AS ID2D1Layer PTR
   SetLastError(m_pRenderTarget->CreateLayer(BYVAL size, layer))
   RETURN layer
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLayer (BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) AS ID2D1Layer PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM size AS D2D1_SIZE_F = (nWidth, nHeight)
   DIM layer AS ID2D1Layer PTR
   SetLastError(m_pRenderTarget->CreateLayer(size, layer))
   RETURN layer
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateLayer () AS ID2D1Layer PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM layer AS ID2D1Layer PTR
   SetLastError(m_pRenderTarget->CreateLayer(BYVAL NULL, layer))
   RETURN layer
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.CreateMesh () AS ID2D1Mesh PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN NULL
   DIM mesh AS ID2D1Mesh PTR
   SetLastError(m_pRenderTarget->CreateMesh(mesh))
   RETURN mesh
END FUNCTION
' ========================================================================================

' ========================================================================================
' Draws a line between the specified points using the specified stroke style.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawLine (BYVAL point0 AS D2D1_POINT_2F, BYVAL point1 AS D2D1_POINT_2F, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawLine(point0, point1, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawLine (BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, _
BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM startPoint AS D2D1_POINT_2F = (startPointX, startPointY)
   DIM endPoint AS D2D1_POINT_2F = (endPointX, endPointY)
   m_pRenderTarget->DrawLine(startPoint, endPoint, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================

' ========================================================================================
' Draws the outline of a rectangle that has the specified dimensions and stroke style.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawRectangle(rect, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawRectangle (BYVAL rect AS const D2D1_RECT_F PTR, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawRectangle(BYVAL rect, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, BYVAL right AS SINGLE, _
BYVAL bottom AS SINGLE, BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM rc AS D2D1_RECT_F = (left, top, right, bottom)
   m_pRenderTarget->DrawRectangle(rc, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillRectangle (BYREF rect AS const D2D1_RECT_F, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillRectangle(rect, brush)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillRectangle (BYVAL rect AS const D2D1_RECT_F PTR, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillRectangle(BYVAL rect, brush)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, BYVAL right AS SINGLE, BYVAL bottom AS SINGLE, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   DIM rc AS D2D1_RECT_F = (left, top, right, bottom)
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillRectangle(rc, brush)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawRoundedRectangle (BYREF roundedRect AS const D2D1_ROUNDED_RECT, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawRoundedRectangle(roundedRect, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawRoundedRectangle (BYVAL roundedRect AS const D2D1_ROUNDED_RECT PTR, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawRoundedRectangle(BYVAL roundedRect, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawRoundedRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, _
BYVAL right AS SINGLE, BYVAL bottom AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, _
BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM rc AS D2D1_RECT_F = (left, top, right, bottom)
   DIM roundedRect AS D2D1_ROUNDED_RECT
   roundedRect.rect = rc
   roundedRect.radiusX =  radiusX
   roundedRect.radiusY =  radiusY
   m_pRenderTarget->DrawRoundedRectangle(roundedRect, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================

' ========================================================================================
' Draws the outline of the specified rounded rectangle using the specified stroke style.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillRoundedRectangle (BYREF roundedRect AS const D2D1_ROUNDED_RECT, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillRoundedRectangle(roundedRect, brush)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillRoundedRectangle (BYVAL roundedRect AS const D2D1_ROUNDED_RECT PTR, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillRoundedRectangle(BYVAL roundedRect, brush)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillRoundedRectangle (BYVAL left AS SINGLE, BYVAL top AS SINGLE, BYVAL right AS SINGLE, _
BYVAL bottom AS SINGLE, BYVAL radiusX AS SINGLE, BYVAL radiusY AS SINGLE, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM rc AS D2D1_RECT_F = (left, top, right, bottom)
   DIM roundedRect AS D2D1_ROUNDED_RECT
   roundedRect.rect = rc
   roundedRect.radiusX =  radiusX
   roundedRect.radiusY =  radiusY
   m_pRenderTarget->FillRoundedRectangle(roundedRect, brush)
END SUB
' ========================================================================================

' ========================================================================================
' Draws the outline of the specified ellipse using the specified stroke style.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawEllipse (BYREF tEllipse AS const D2D1_ELLIPSE, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawEllipse(tEllipse, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawEllipse (BYVAL tEllipse AS const D2D1_ELLIPSE PTR, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawEllipse(BYVAL tEllipse, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawEllipse (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL radiusX AS SINGLE, _
BYVAL radiusY AS SINGLE, BYVAL brush AS ID2D1Brush PTR, BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM ptf AS D2D1_POINT_2F = (x, y)
   DIM e AS D2D1_ELLIPSE
   e.point = ptf
   e.radiusX = radiusX
   e.radiusY = radiusY
   m_pRenderTarget->DrawEllipse(e, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================

' ========================================================================================
' Paints the interior of the specified ellipse.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillEllipse (BYREF tEllipse AS const D2D1_ELLIPSE, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillEllipse(tEllipse, brush)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillEllipse (BYVAL tEllipse AS const D2D1_ELLIPSE PTR, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillEllipse(BYVAL tEllipse, brush)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillEllipse (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL radiusX AS SINGLE, _
BYVAL radiusY AS SINGLE, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM ptf AS D2D1_POINT_2F = (x, y)
   DIM e AS D2D1_ELLIPSE
   e.point = ptf
   e.radiusX = radiusX
   e.radiusY = radiusY
   m_pRenderTarget->FillEllipse(e, brush)
END SUB
' ========================================================================================
'++++++++++++++
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR, _
BYVAL strokeWidth AS FLOAT = 1.0!, BYVAL strokeStyle AS ID2D1StrokeStyle PTR = NULL) 
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawGeometry(geometry, brush, strokeWidth, strokeStyle)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillGeometry (BYVAL geometry AS ID2D1Geometry PTR, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillGeometry(geometry, brush)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillMesh (BYVAL mesh AS ID2D1Mesh PTR, BYVAL brush AS ID2D1Brush PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillMesh(mesh, brush)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
BYVAL content AS D2D1_OPACITY_MASK_CONTENT, BYREF destinationRectangle AS const D2D1_RECT_F, _
BYREF sourceRectangle AS const D2D1_RECT_F)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillOpacityMask(opacityMask, brush, content, destinationRectangle, sourceRectangle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.FillOpacityMask (BYVAL opacityMask AS ID2D1Bitmap PTR, BYVAL brush AS ID2D1Brush PTR, _
BYVAL content AS D2D1_OPACITY_MASK_CONTENT, BYVAL destinationRectangle AS const D2D1_RECT_F PTR, _
BYVAL sourceRectangle AS const D2D1_RECT_F PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->FillOpacityMask(opacityMask, brush, content, BYVAL destinationRectangle, BYVAL sourceRectangle)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYREF destinationRectangle AS const D2D1_RECT_F, _
BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
BYREF sourceRectangle AS const D2D1_RECT_F)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawBitmap(bitmap, destinationRectangle, opacity, InterpolationMode, sourceRectangle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL destinationRectangle AS const D2D1_RECT_F PTR, _
BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
BYVAL sourceRectangle AS const D2D1_RECT_F PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawBitmap(bitmap, BYVAL destinationRectangle, opacity, InterpolationMode, BYVAL sourceRectangle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawBitmap (BYVAL bitmap AS ID2D1Bitmap PTR, BYVAL destRectLeft AS SINGLE, BYVAL destRectTop AS SINGLE, _
BYVAL destRectRight AS SINGLE, BYVAL destRectBottom AS SINGLE, BYVAL opacity AS FLOAT = 1.0!, BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, _
BYVAL sourceRectangleLeft AS SINGLE, BYVAL sourceRectangleLeftTop AS SINGLE, BYVAL sourceRectangleRight AS SINGLE, BYVAL sourceRectangleBottom AS SINGLE)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM destinationRectangle AS D2D1_RECT_F = (destRectLeft, destRectTop, destRectRight, destRectBottom)
   DIM sourceRectangle AS D2D1_RECT_F = (sourceRectangleLeft, sourceRectangleLeftTop, sourceRectangleRight, sourceRectangleBottom)
   m_pRenderTarget->DrawBitmap(bitmap, destinationRectangle, opacity, InterpolationMode, sourceRectangle)
END SUB
' ========================================================================================

' ========================================================================================
' Draws the specified text using the format information provided by an IDWriteTextFormat object.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawText (BYREF wzSstr AS WSTRING, BYVAL stringLength AS UINT32, _
BYVAL textFormat AS IDWriteTextFormat PTR, BYREF layoutRect AS D2D1_RECT_F, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, _
BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawText(wzSstr, stringLength, textFormat, layoutRect, defaultForegroundBrush, options, measuringMode)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawText (BYVAL pwzSstr AS WSTRING PTR, BYVAL stringLength AS UINT32, _
BYVAL textFormat AS IDWriteTextFormat PTR, BYVAL layoutRect AS D2D1_RECT_F PTR, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, _
BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawText(BYVAL pwzSstr, stringLength, textFormat, BYVAL layoutRect, defaultForegroundBrush, options, measuringMode)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawText (BYREF wzSstr AS WSTRING, BYVAL stringLength AS UINT32, _
BYVAL textFormat AS IDWriteTextFormat PTR, BYVAL layoutRectLeft AS SINGLE, BYVAL layoutRectTop AS SINGLE, _
BYVAL layoutRectRight AS SINGLE, BYVAL layoutRectBottom AS SINGLE, BYVAL defaultForegroundBrush AS ID2D1Brush PTR, _
BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE, _
BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM layoutRect AS D2D1_RECT_F = (layoutRectLeft, layoutRectTop, layoutRectRight, layoutRectBottom)
   m_pRenderTarget->DrawText(wzSstr, stringLength, textFormat, layoutRect, defaultForegroundBrush, options, measuringMode)
END SUB
' ========================================================================================

' ========================================================================================
 ' Draws the formatted text described by the specified IDWriteTextLayout object.
 ' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawTextLayout (BYVAL origin AS D2D1_POINT_2F, BYVAL textLayout AS IDWriteTextLayout PTR, _
BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE) 
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawTextLayout(origin, textLayout, defaultFillBrush, options)
END SUB
' ========================================================================================
 ' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawTextLayout (BYVAL originX AS SINGLE, BYVAL originY AS SINGLE, BYVAL textLayout AS IDWriteTextLayout PTR, _
BYVAL defaultFillBrush AS ID2D1Brush PTR, BYVAL options AS D2D1_DRAW_TEXT_OPTIONS = D2D1_DRAW_TEXT_OPTIONS_NONE) 
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM origin AS D2D1_POINT_2F = (originX, originY)
   m_pRenderTarget->DrawTextLayout(origin, textLayout, defaultFillBrush, options)
END SUB
' ========================================================================================

' ========================================================================================
' Draws the specified glyphs.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawGlyphRun(baselineOrigin, glyphRun, foregroundBrush, measuringMode)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawGlyphRun (BYVAL baselineOrigin AS D2D1_POINT_2F, BYVAL glyphRun AS const DWRITE_GLYPH_RUN PTR, _
BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->DrawGlyphRun(baselineOrigin, BYVAL glyphRun, foregroundBrush, measuringMode)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.DrawGlyphRun (BYVAL baselineOriginX AS SINGLE, BYVAL baselineOriginY AS SINGLE, BYREF glyphRun AS const DWRITE_GLYPH_RUN, _
BYVAL foregroundBrush AS ID2D1Brush PTR, BYVAL measuringMode AS DWRITE_MEASURING_MODE = DWRITE_MEASURING_MODE_NATURAL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM baselineOrigin AS D2D1_POINT_2F = (baselineOriginX, baselineOriginY)
   m_pRenderTarget->DrawGlyphRun(baselineOrigin, glyphRun, foregroundBrush, measuringMode)
END SUB
' ========================================================================================

' ========================================================================================
' Applies the specified transform to the render target, replacing the existing transformation.
' All subsequent drawing operations occur in the transformed space.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetTransform(BYVAL transform)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the current transform of the render target.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetTransform () AS D2D1_MATRIX_3X2_F
   D2D1_DP("")
   DIM transform AS D2D1_MATRIX_3X2_F
   IF m_pRenderTarget = NULL THEN RETURN transform
   m_pRenderTarget->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetAntialiasMode (BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetAntialiasMode(antialiasMode)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetAntialiasMode () AS D2D1_ANTIALIAS_MODE
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   RETURN m_pRenderTarget->GetAntialiasMode
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetTextAntialiasMode (BYVAL textAntialiasMode AS D2D1_TEXT_ANTIALIAS_MODE)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetTextAntialiasMode(textAntialiasMode)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetTextAntialiasMode () AS D2D1_TEXT_ANTIALIAS_MODE
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   RETURN m_pRenderTarget->GetTextAntialiasMode
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetTextRenderingParams(textRenderingParams)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetTextRenderingParams (BYREF textRenderingParams AS IDWriteRenderingParams PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetTextRenderingParams(textRenderingParams)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetTextRenderingParams () AS IDWriteRenderingParams PTR
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM textRenderingParams AS IDWriteRenderingParams PTR
   m_pRenderTarget->GetTextRenderingParams(textRenderingParams)
   RETURN textRenderingParams
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetTags (BYVAL tag1 AS D2D1_TAG, BYVAL tag2 AS D2D1_TAG)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetTags(tag1, tag2)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetTags (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetTags(tag1, tag2)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetTags (BYVAL tag1 AS D2D1_TAG PTR = NULL, BYVAL tag2 AS D2D1_TAG PTR = NULL)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetTags(BYVAL tag1, BYVAL tag2)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PushLayer (BYREF layerParameters AS D2D1_LAYER_PARAMETERS, BYVAL layer AS ID2D1Layer PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->PushLayer(layerParameters, layer)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PushLayer (BYVAL layerParameters AS D2D1_LAYER_PARAMETERS PTR, BYVAL layer AS ID2D1Layer PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->PushLayer(BYVAL layerParameters, layer)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PopLayer
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->PopLayer
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.Flush (BYREF tag1 AS D2D1_TAG = NULL, BYREF tag2 AS D2D1_TAG = NULL) AS HRESULT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   RETURN m_pRenderTarget->Flush(tag1, tag2)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.Flush (BYVAL tag1 AS D2D1_TAG PTR = NULL, BYVAL tag2 AS D2D1_TAG PTR = NULL) AS HRESULT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   RETURN m_pRenderTarget->Flush(BYVAL tag1, BYVAL tag2)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SaveDrawingState (BYVAL drawingStateBlock AS ID2D1DrawingStateBlock PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SaveDrawingState(drawingStateBlock)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.RestoreDrawingState (BYVAL drawingStateBlock AS ID2D1DrawingStateBlock PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->RestoreDrawingState(drawingStateBlock)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies a rectangle to which all subsequent drawing operations are clipped.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PushAxisAlignedClip (BYREF clipRect AS D2D1_RECT_F, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->PushAxisAlignedClip(clipRect, antialiasMode)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PushAxisAlignedClip (BYVAL clipRect AS D2D1_RECT_F PTR, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->PushAxisAlignedClip(BYVAL clipRect, antialiasMode)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PushAxisAlignedClip (BYVAL clipRectLeft AS SINGLE, BYVAL clipRecTop AS SINGLE, _
BYVAL clipRectRight AS SINGLE, BYVAL clipRectBottom AS SINGLE, BYVAL antialiasMode AS D2D1_ANTIALIAS_MODE)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM clipRect AS D2D1_RECT_F = (clipRectLeft, clipRecTop, clipRectRight, clipRectBottom)
   m_pRenderTarget->PushAxisAlignedClip(clipRect, antialiasMode)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.PopAxisAlignedClip
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->PopAxisAlignedClip
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.Clear (BYREF clearColor AS const D2D1_COLOR_F)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->Clear(clearColor)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.Clear (BYVAL clearColor AS const D2D1_COLOR_F PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->Clear(BYVAL clearColor)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.Clear (BYVAL clearColor AS UINT32, BYVAL alpha AS FLOAT = 1.0)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   DIM clr AS D2D1_COLOR_F = D2D1_ColorF(clearColor, alpha)
   m_pRenderTarget->Clear(clr)
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.BeginDraw
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->BeginDraw
END SUB
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.EndDraw (BYREF tag1 AS D2D1_TAG, BYREF tag2 AS D2D1_TAG) AS HRESULT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN E_POINTER
   RETURN m_pRenderTarget->EndDraw(tag1, tag2)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.EndDraw (BYVAL tag1 AS D2D1_TAG PTR = NULL, BYVAL tag2 AS D2D1_TAG PTR = NULL) AS HRESULT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN E_POINTER
   RETURN m_pRenderTarget->EndDraw(BYVAL tag1, BYVAL tag2)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetPixelFormat (BYREF pixelFormat AS D2D1_PIXEL_FORMAT)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetPixelFormat(pixelFormat)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetPixelFormat (BYVAL pixelFormat AS D2D1_PIXEL_FORMAT PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetPixelFormat(BYVAL pixelFormat)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetPixelFormat () AS D2D1_PIXEL_FORMAT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM pixelFormat AS D2D1_PIXEL_FORMAT
   m_pRenderTarget->GetPixelFormat(pixelFormat)
   RETURN pixelFormat
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.SetDpi (BYVAL dpiX AS FLOAT, BYVAL dpiY AS FLOAT)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->SetDpi(dpiX, dpiY)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetDpi (BYREF dpiX AS FLOAT, BYREF dpiY AS FLOAT)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetDpi(dpiX, dpiY)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetDpiX () AS FLOAT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM AS FLOAT dpiX, dpiY
   m_pRenderTarget->GetDpi(dpiX, dpiY)
   RETURN dpiX
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetDpiY () AS FLOAT
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM AS FLOAT dpiX, dpiY
   m_pRenderTarget->GetDpi(dpiX, dpiY)
   RETURN dpiY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size of the render target in device-independent pixels.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetSize (BYREF size AS D2D1_SIZE_F)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetSize(size)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetSize (BYVAL size AS D2D1_SIZE_F PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetSize(BYVAL size)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetSize () AS D2D1_SIZE_F
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM size AS D2D1_SIZE_F
   m_pRenderTarget->GetSize(size)
   RETURN size
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetSizeWidth () AS SINGLE
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM size AS D2D1_SIZE_F
   m_pRenderTarget->GetSize(size)
   RETURN size.width
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetSizeHeight () AS SINGLE
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM size AS D2D1_SIZE_F
   m_pRenderTarget->GetSize(size)
   RETURN size.height
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size of the render target in device pixels.
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetPixelSize (BYREF pixelSize AS D2D1_SIZE_U)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetPixelSize(pixelSize)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RenderTarget.GetPixelSize (BYVAL pixelSize AS D2D1_SIZE_U PTR)
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT SUB
   m_pRenderTarget->GetPixelSize(BYVAL pixelSize)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetPixelSize () AS D2D1_SIZE_U
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM pixelSize AS D2D1_SIZE_U
   m_pRenderTarget->GetPixelSize(pixelSize)
   RETURN pixelSize
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetPixelWidth () AS SINGLE
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM pixelSize AS D2D1_SIZE_U
   m_pRenderTarget->GetPixelSize(pixelSize)
   RETURN pixelSize.width
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.GetPixelHeight () AS SINGLE
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN EXIT FUNCTION
   DIM pixelSize AS D2D1_SIZE_U
   m_pRenderTarget->GetPixelSize(pixelSize)
   RETURN pixelSize.height
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.IsSupported (BYREF renderTargetProperties AS const D2D1_RENDER_TARGET_PROPERTIES) AS BOOLEAN
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN FALSE
   m_pRenderTarget->IsSupported(renderTargetProperties)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RenderTarget.IsSupported (BYVAL renderTargetProperties AS const D2D1_RENDER_TARGET_PROPERTIES PTR) AS BOOLEAN
   D2D1_DP("")
   IF m_pRenderTarget = NULL THEN RETURN FALSE
   m_pRenderTarget->IsSupported(BYVAL renderTargetProperties)
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1DCRenderTarget class
' ########################################################################################

' ========================================================================================
TYPE CID2D1DCRenderTarget EXTENDS CID2D1RenderTarget
Public:

   m_pDCRenderTarget AS ID2D1DCRenderTarget PTR

   DECLARE CONSTRUCTOR (BYVAL pDCRenderTarget AS ID2D1DCRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1DCRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1DCRenderTarget PTR

   DECLARE FUNCTION BindDC (BYVAL hDC AS HDC, BYREF subRect AS const RECT) AS HRESULT
   DECLARE FUNCTION BindDC (BYVAL hDC AS HDC, BYVAL subRect AS const RECT PTR) AS HRESULT
   DECLARE FUNCTION BindDC (BYVAL hDC AS HDC, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG) AS HRESULT

END TYPE

' ========================================================================================
' Creates an instance of the CID2D1DCRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DCRenderTarget (BYVAL pDCRenderTarget AS ID2D1DCRenderTarget PTR)
   D2D1_DP("pDCRenderTarget - " & WSTR(pDCRenderTarget))
   m_pDCRenderTarget = pDCRenderTarget
   IF m_pDCRenderTarget THEN m_pDCRenderTarget->AddRef
   m_pRenderTarget = CAST(ID2D1RenderTarget PTR, m_pDCRenderTarget)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1DCRenderTarget
   D2D1_DP("m_pDCRenderTarget: " & WSTR(m_pDCRenderTarget))
   IF m_pDCRenderTarget THEN m_pDCRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1DCRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1DCRenderTarget) AS ID2D1RenderTarget PTR
   RETURN renderTarget.m_pDCRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1DCRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DCRenderTarget.@ () AS ID2D1DCRenderTarget PTR PTR
   RETURN @m_pDCRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1DCRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DCRenderTarget.CAST () AS ID2D1DCRenderTarget PTR
   RETURN m_pDCRenderTarget
END OPERATOR
' ========================================================================================

' ========================================================================================
' Binds the render target to the device context to which it issues drawing commands.
' ========================================================================================
PRIVATE FUNCTION CID2D1DCRenderTarget.BindDC (BYVAL hDC AS HDC, BYREF subRect AS const RECT) AS HRESULT
   D2D1_DP("")
   IF m_pDCRenderTarget = NULL THEN RETURN E_POINTER
   RETURN m_pDCRenderTarget->BindDC(hdc, subRect)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1DCRenderTarget.BindDC (BYVAL hDC AS HDC, BYVAL subRect AS const RECT PTR) AS HRESULT
   D2D1_DP("")
   IF m_pDCRenderTarget = NULL THEN RETURN E_POINTER
   RETURN m_pDCRenderTarget->BindDC(hdc, BYVAL subRect)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1DCRenderTarget.BindDC (BYVAL hDC AS HDC, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG) AS HRESULT
   D2D1_DP("")
   IF m_pDCRenderTarget = NULL THEN RETURN E_POINTER
   DIM rc AS RECT = (nLeft, nTop, nRight, nBottom)
   RETURN m_pDCRenderTarget->BindDC(hdc, rc)
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1HwndRenderTarget class
' Renders drawing instructions to a window.
' ########################################################################################

' ========================================================================================
TYPE CID2D1HwndRenderTarget EXTENDS CID2D1RenderTarget
Public:

   m_pHwndRenderTarget AS ID2D1HwndRenderTarget PTR

   DECLARE CONSTRUCTOR (BYVAL pHwndRenderTarget AS ID2D1HwndRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1HwndRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1HwndRenderTarget PTR

   DECLARE FUNCTION CheckWindowState () AS D2D1_WINDOW_STATE
   DECLARE FUNCTION Resize (BYREF pixelSize AS D2D1_SIZE_U) AS HRESULT
   DECLARE FUNCTION Resize (BYVAL pixelSize AS D2D1_SIZE_U PTR) AS HRESULT
   DECLARE FUNCTION Resize () AS D2D1_SIZE_U
   DECLARE FUNCTION GetHwnd () AS HWND

END TYPE

' ========================================================================================
' Creates an instance of the CID2D1HwndRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1HwndRenderTarget (BYVAL pHwndRenderTarget AS ID2D1HwndRenderTarget PTR)
   D2D1_DP("HwndRenderTarget - " & WSTR(pHwndRenderTarget))
   m_pHwndRenderTarget = pHwndRenderTarget
   IF m_pHwndRenderTarget THEN m_pHwndRenderTarget->AddRef
   m_pRenderTarget = CAST(ID2D1RenderTarget PTR, m_pHwndRenderTarget)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1HwndRenderTarget
   D2D1_DP("m_pHwndRenderTarget: " & WSTR(m_pHwndRenderTarget))
   IF m_pHwndRenderTarget THEN m_pHwndRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1HwndRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1HwndRenderTarget) AS ID2D1HwndRenderTarget PTR
   RETURN renderTarget.m_pHwndRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1HwndRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1HwndRenderTarget.@ () AS ID2D1HwndRenderTarget PTR PTR
   RETURN @m_pHwndRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1HwndRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1HwndRenderTarget.CAST () AS ID2D1HwndRenderTarget PTR
   RETURN m_pHwndRenderTarget
END OPERATOR
' ========================================================================================

' ========================================================================================
' Indicates whether the HWND associated with this render target is occluded.
' ========================================================================================
PRIVATE FUNCTION CID2D1HwndRenderTarget.CheckWindowState () AS D2D1_WINDOW_STATE
   D2D1_DP("")
   IF m_pHwndRenderTarget = NULL THEN RETURN 0
   RETURN m_pHwndRenderTarget->CheckWindowState
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the size of the render target to the specified pixel size.
' ========================================================================================
PRIVATE FUNCTION CID2D1HwndRenderTarget.Resize (BYREF pixelSize AS D2D1_SIZE_U) AS HRESULT
   D2D1_DP("")
   IF m_pHwndRenderTarget = NULL THEN RETURN 0
   RETURN m_pHwndRenderTarget->Resize(pixelSize)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1HwndRenderTarget.Resize (BYVAL pixelSize AS D2D1_SIZE_U PTR) AS HRESULT
   D2D1_DP("")
   IF m_pHwndRenderTarget = NULL THEN RETURN 0
   RETURN m_pHwndRenderTarget->Resize(BYVAL pixelSize)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1HwndRenderTarget.Resize () AS D2D1_SIZE_U
   D2D1_DP("")
   IF m_pHwndRenderTarget = NULL THEN SetLastError(E_POINTER) : EXIT FUNCTION
   DIM pixelSize AS D2D1_SIZE_U
   SetLastError(m_pHwndRenderTarget->Resize(pixelSize))
   RETURN pixelSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the HWND associated with this render target.
' ========================================================================================
PRIVATE FUNCTION CID2D1HwndRenderTarget.GetHwnd () AS HWND
   D2D1_DP("")
   IF m_pHwndRenderTarget = NULL THEN SetLastError(E_POINTER) : EXIT FUNCTION
   RETURN m_pHwndRenderTarget->GetHwnd
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1BitmapRenderTarget class
' Renders to an intermediate texture created by the CreateCompatibleRenderTarget method.
' ########################################################################################

' ========================================================================================
TYPE CID2D1BitmapRenderTarget EXTENDS CID2D1RenderTarget
Public:

   m_pBitmapRenderTarget AS ID2D1BitmapRenderTarget PTR

   DECLARE CONSTRUCTOR (BYVAL pBitmapRenderTarget AS ID2D1BitmapRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1BitmapRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1BitmapRenderTarget PTR

   DECLARE FUNCTION GetBitmap () AS ID2D1Bitmap PTR

END TYPE

' ========================================================================================
' Creates an instance of the CID2D1HwndRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapRenderTarget (BYVAL pBitmapRenderTarget AS ID2D1BitmapRenderTarget PTR)
   D2D1_DP("pBitmapRenderTarget - " & WSTR(pBitmapRenderTarget))
   m_pBitmapRenderTarget = pBitmapRenderTarget
   IF m_pBitmapRenderTarget THEN m_pBitmapRenderTarget->AddRef
   m_pRenderTarget = CAST(ID2D1RenderTarget PTR, m_pBitmapRenderTarget)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1BitmapRenderTarget
   D2D1_DP("m_pBitmapRenderTarget: " & WSTR(m_pBitmapRenderTarget))
   IF m_pBitmapRenderTarget THEN m_pBitmapRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1BitmapRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1BitmapRenderTarget) AS ID2D1BitmapRenderTarget PTR
   RETURN renderTarget.m_pBitmapRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1BitmapRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapRenderTarget.@ () AS ID2D1BitmapRenderTarget PTR PTR
   RETURN @m_pBitmapRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1BitmapRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapRenderTarget.CAST () AS ID2D1BitmapRenderTarget PTR
   RETURN m_pBitmapRenderTarget
END OPERATOR
' ========================================================================================

' ========================================================================================
' Indicates whether the HWND associated with this render target is occluded.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapRenderTarget.GetBitmap () AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pBitmapRenderTarget = NULL THEN RETURN NULL
   DIM bitmap AS ID2D1Bitmap PTR
   SetLasTError(m_pBitmapRenderTarget->GetBitmap(bitmap))
   RETURN bitmap
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1DrawingStateBlock class
' Represents the drawing state of a render target: the antialiasing mode, transform, tags, and text-rendering options.
' ########################################################################################

' ========================================================================================
TYPE CID2D1DrawingStateBlock
Public:

   m_pDrawingStateBlock AS ID2D1DrawingStateBlock PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pDrawingStateBlock AS ID2D1DrawingStateBlock PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1DrawingStateBlock PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1DrawingStateBlock PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // CID2D1DrawingStateBlock methods
   DECLARE SUB GetDescription (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION)
   DECLARE SUB GetDescription (BYVAL stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION PTR)
   DECLARE FUNCTION GetDescription () AS D2D1_DRAWING_STATE_DESCRIPTION
   DECLARE SUB SetDescription (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION)
   DECLARE SUB SetDescription (BYVAL stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION PTR)
   DECLARE SUB SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE SUB GetTextRenderingParams (BYREF textRenderingParams AS IDWriteRenderingParams PTR)
   DECLARE FUNCTION GetTextRenderingParams () AS IDWriteRenderingParams PTR

END TYPE

' ========================================================================================
' Creates an instance of the CID2D1DrawingStateBlock class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DrawingStateBlock
   D2D1_DP(" - Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1DrawingStateBlock class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DrawingStateBlock (BYVAL pDrawingStateBlock AS ID2D1DrawingStateBlock PTR)
   D2D1_DP("pDrawingStateBlock - " & WSTR(pDrawingStateBlock))
   m_pDrawingStateBlock = pDrawingStateBlock
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1DrawingStateBlock
   D2D1_DP("m_pDrawingStateBlock: " & WSTR(m_pDrawingStateBlock))
   IF m_pDrawingStateBlock THEN m_pDrawingStateBlock->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1DrawingStateBlock interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF drawingStateBlock AS CID2D1DrawingStateBlock) AS ID2D1DrawingStateBlock PTR
   RETURN drawingStateBlock.m_pDrawingStateBlock
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1DrawingStateBlock interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DrawingStateBlock.@ () AS ID2D1DrawingStateBlock PTR PTR
   RETURN @m_pDrawingStateBlock
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1DrawingStateBlock interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DrawingStateBlock.CAST () AS ID2D1DrawingStateBlock PTR
   RETURN m_pDrawingStateBlock
END OPERATOR
' ========================================================================================

' // ID2D1Resource method

' ========================================================================================
PRIVATE FUNCTION CID2D1DrawingStateBlock.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1DrawingStateBlock PTR, m_pDrawingStateBlock)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' // ID2D1DrawingStateBlock methods

' ========================================================================================
' Retrieves the antialiasing mode, transform, and tags portion of the drawing state.
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock.GetDescription (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION)
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT SUB
   m_pDrawingStateBlock->GetDescription(stateDescription)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock.GetDescription (BYVAL stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION PTR)
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT SUB
   m_pDrawingStateBlock->GetDescription(BYVAL stateDescription)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1DrawingStateBlock.GetDescription () AS D2D1_DRAWING_STATE_DESCRIPTION
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT FUNCTION
   DIM stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION
   m_pDrawingStateBlock->GetDescription(stateDescription)
   RETURN stateDescription
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the antialiasing mode, transform, and tags portion of the drawing state.
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock.SetDescription (BYREF stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION)
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT SUB
   m_pDrawingStateBlock->SetDescription(stateDescription)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock.SetDescription (BYVAL stateDescription AS D2D1_DRAWING_STATE_DESCRIPTION PTR)
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT SUB
   m_pDrawingStateBlock->SetDescription(BYVAL stateDescription)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies the text-rendering configuration of the drawing state.
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock.SetTextRenderingParams (BYVAL textRenderingParams AS IDWriteRenderingParams PTR)
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT SUB
   m_pDrawingStateBlock->SetTextRenderingParams(textRenderingParams)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the text-rendering configuration of the drawing state.
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock.GetTextRenderingParams (BYREF textRenderingParams AS IDWriteRenderingParams PTR)
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT SUB
   m_pDrawingStateBlock->GetTextRenderingParams(textRenderingParams)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1DrawingStateBlock.GetTextRenderingParams () AS IDWriteRenderingParams PTR
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT FUNCTION
   DIM textRenderingParams AS IDWriteRenderingParams PTR
   m_pDrawingStateBlock->GetTextRenderingParams(textRenderingParams)
   RETURN textRenderingParams
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1DrawingStateBlock1 class
' Implementation of a drawing state block that adds the functionality of primitive blend in
' addition to already existing antialias mode, transform, tags and text rendering mode.
' ########################################################################################

' ========================================================================================
TYPE CID2D1DrawingStateBlock1 EXTENDS CID2D1DrawingStateBlock
Public:

   m_pDrawingStateBlock1 AS ID2D1DrawingStateBlock1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pDrawingStateBlock1 AS ID2D1DrawingStateBlock1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1DrawingStateBlock1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1DrawingStateBlock1 PTR
   DECLARE OPERATOR CAST () AS ID2D1DrawingStateBlock PTR

   DECLARE SUB GetDescription1 (BYREF stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1)
   DECLARE SUB GetDescription1 (BYVAL stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR)
   DECLARE FUNCTION GetDescription1 () AS D2D1_DRAWING_STATE_DESCRIPTION1
   DECLARE SUB SetDescription1 (BYREF stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1)
   DECLARE SUB SetDescription1 (BYVAL stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR)

END TYPE

' ========================================================================================
' Creates an instance of the CID2D1DrawingStateBlock1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DrawingStateBlock1
   D2D1_DP(" - Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1DrawingStateBlock1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DrawingStateBlock1 (BYVAL pDrawingStateBlock1 AS ID2D1DrawingStateBlock1 PTR)
   D2D1_DP("pDrawingStateBlock1 - " & WSTR(pDrawingStateBlock1))
   m_pDrawingStateBlock1 = pDrawingStateBlock1
   IF m_pDrawingStateBlock1 THEN m_pDrawingStateBlock1->AddRef
   IF m_pDrawingStateBlock THEN m_pDrawingStateBlock1->Release
   m_pDrawingStateBlock = m_pDrawingStateBlock1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1DrawingStateBlock1
   D2D1_DP("m_pDrawingStateBlock1: " & WSTR(m_pDrawingStateBlock1))
   IF m_pDrawingStateBlock1 THEN m_pDrawingStateBlock1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1DrawingStateBlock1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF drawingStateBlock1 AS CID2D1DrawingStateBlock1) AS ID2D1DrawingStateBlock1 PTR
   RETURN drawingStateBlock1.m_pDrawingStateBlock1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1DrawingStateBlock1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DrawingStateBlock1.@ () AS ID2D1DrawingStateBlock1 PTR PTR
   RETURN @m_pDrawingStateBlock1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1DrawingStateBlock1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DrawingStateBlock1.CAST () AS ID2D1DrawingStateBlock1 PTR
   RETURN m_pDrawingStateBlock1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1DrawingStateBlock interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DrawingStateBlock1.CAST () AS ID2D1DrawingStateBlock PTR
   RETURN m_pDrawingStateBlock
END OPERATOR
' ========================================================================================

' ========================================================================================
' Gets the antialiasing mode, transform, tags, primitive blend, and unit mode portion of the drawing state.
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock1.GetDescription1 (BYREF stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1)
   D2D1_DP("")
   IF m_pDrawingStateBlock1 = NULL THEN EXIT SUB
   m_pDrawingStateBlock1->GetDescription1(stateDescription1)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock1.GetDescription1 (BYVAL stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR)
   D2D1_DP("")
   IF m_pDrawingStateBlock1 = NULL THEN EXIT SUB
   m_pDrawingStateBlock1->GetDescription1(BYVAL stateDescription1)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1DrawingStateBlock1.GetDescription1 () AS D2D1_DRAWING_STATE_DESCRIPTION1
   D2D1_DP("")
   IF m_pDrawingStateBlock = NULL THEN EXIT FUNCTION
   DIM stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1
   m_pDrawingStateBlock1->GetDescription1(stateDescription1)
   RETURN stateDescription1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the antialiasing mode, transform, and tags portion of the drawing state.
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock1.SetDescription1 (BYREF stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1)
   D2D1_DP("")
   IF m_pDrawingStateBlock1 = NULL THEN EXIT SUB
   m_pDrawingStateBlock1->SetDescription1(stateDescription1)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1DrawingStateBlock1.SetDescription1 (BYVAL stateDescription1 AS D2D1_DRAWING_STATE_DESCRIPTION1 PTR)
   D2D1_DP("")
   IF m_pDrawingStateBlock1 = NULL THEN EXIT SUB
   m_pDrawingStateBlock1->SetDescription1(BYVAL stateDescription1)
END SUB
' ========================================================================================

' ########################################################################################
' CID2D1GdiInteropRenderTarget class
' Provides access to a device context that can accept GDI drawing commands.
' ########################################################################################

' ========================================================================================
TYPE CID2D1GdiInteropRenderTarget EXTENDS CID2D1DrawingStateBlock
Public:

   m_pGdiInteropRenderTarget AS ID2D1GdiInteropRenderTarget PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGdiInteropRenderTarget AS ID2D1GdiInteropRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GdiInteropRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GdiInteropRenderTarget PTR

   DECLARE FUNCTION GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE, BYREF hDC AS ..HDC) AS HRESULT
   DECLARE FUNCTION GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE, BYVAL hDC AS ..HDC PTR) AS HRESULT
   DECLARE FUNCTION GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE) AS ..HDC
   DECLARE FUNCTION ReleaseDC (BYREF rcUpdate AS const RECT) AS HRESULT
   DECLARE FUNCTION ReleaseDC (BYVAL rcUpdate AS const RECT PTR = NULL) AS HRESULT

END TYPE

' ========================================================================================
' Creates an instance of the CID2D1GdiInteropRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GdiInteropRenderTarget
   D2D1_DP(" - Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GdiInteropRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GdiInteropRenderTarget (BYVAL pGdiInteropRenderTarget AS ID2D1GdiInteropRenderTarget PTR)
   D2D1_DP("pGdiInteropRenderTarget - " & WSTR(pGdiInteropRenderTarget))
   m_pGdiInteropRenderTarget = pGdiInteropRenderTarget
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GdiInteropRenderTarget
   D2D1_DP("m_pGdiInteropRenderTarget: " & WSTR(m_pGdiInteropRenderTarget))
   IF m_pGdiInteropRenderTarget THEN m_pGdiInteropRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GdiInteropRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF interopRenderTarget AS CID2D1GdiInteropRenderTarget) AS ID2D1GdiInteropRenderTarget PTR
   RETURN interopRenderTarget.m_pGdiInteropRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1DrawingStateBlock1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GdiInteropRenderTarget.@ () AS ID2D1GdiInteropRenderTarget PTR PTR
   RETURN @m_pGdiInteropRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GdiInteropRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GdiInteropRenderTarget.CAST () AS ID2D1GdiInteropRenderTarget PTR
   RETURN m_pGdiInteropRenderTarget
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the device context associated with this render target.
' ========================================================================================
PRIVATE FUNCTION CID2D1GdiInteropRenderTarget.GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE, BYREF hDC AS ..HDC) AS HRESULT
   D2D1_DP(" - mode: " & WSTR(mode))
   IF m_pGdiInteropRenderTarget = NULL THEN RETURN E_POINTER
   RETURN m_pGdiInteropRenderTarget->GetDC(mode, hdc)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1GdiInteropRenderTarget.GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE, BYVAL hDC AS ..HDC PTR) AS HRESULT
   D2D1_DP(" - mode: " & WSTR(mode))
   IF m_pGdiInteropRenderTarget = NULL THEN RETURN E_POINTER
   RETURN m_pGdiInteropRenderTarget->GetDC(mode, BYVAL hdc)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1GdiInteropRenderTarget.GetDC (BYVAL mode AS D2D1_DC_INITIALIZE_MODE) AS ..HDC
   D2D1_DP(" - mode: " & WSTR(mode))
   IF m_pGdiInteropRenderTarget = NULL THEN EXIT FUNCTION
   DIM hdc AS ..HDC
   SetLastError(m_pGdiInteropRenderTarget->GetDC(mode, hdc))
   RETURN hdc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates that drawing with the device context retrieved using the GetDC method is finished.
' ========================================================================================
PRIVATE FUNCTION CID2D1GdiInteropRenderTarget.ReleaseDC (BYREF rcUpdate AS const RECT) AS HRESULT
   D2D1_DP("")
   RETURN m_pGdiInteropRenderTarget->ReleaseDC(rcUpdate)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1GdiInteropRenderTarget.ReleaseDC (BYVAL rcUpdate AS const RECT PTR = NULL) AS HRESULT
   D2D1_DP("")
   RETURN m_pGdiInteropRenderTarget->ReleaseDC(BYVAL rcUpdate)
END FUNCTION
' ========================================================================================
