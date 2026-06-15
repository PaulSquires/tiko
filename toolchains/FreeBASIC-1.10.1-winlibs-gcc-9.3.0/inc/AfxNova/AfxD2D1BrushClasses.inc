' D2D1 brush classes
' To be included by AfxD2D1Objects.inc

' ########################################################################################
' CID2D1GradientStopCollection class
' Represents a collection of D2D1_GRADIENT_STOP objects for linear and radial gradient brushes.
' ########################################################################################

TYPE CID2D1GradientStopCollection
Public:

   m_pGradientStopCollection AS ID2D1GradientStopCollection PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGradientStopCollection AS ID2D1GradientStopCollection PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GradientStopCollection PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GradientStopCollection PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1GradientStopCollection

   DECLARE FUNCTION GetGradientStopCount () AS UINT32
   DECLARE SUB GetGradientStops (BYREF gradientStops AS D2D1_GRADIENT_STOP, BYVAL gradientStopsCount AS UINT32)
   DECLARE FUNCTION GetColorInterpolationGamma () AS D2D1_GAMMA
   DECLARE FUNCTION GetExtendMode () AS D2D1_EXTEND_MODE

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GradientStopCollection class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GradientStopCollection
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GradientStopCollection class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GradientStopCollection (BYVAL pGradientStopCollection AS ID2D1GradientStopCollection PTR)
   D2D1_DP("pGradientStopCollection - " & WSTR(pGradientStopCollection))
   m_pGradientStopCollection = pGradientStopCollection
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GradientStopCollection
   D2D1_DP("m_pGradientStopCollection: " & WSTR(m_pGradientStopCollection))
   IF m_pGradientStopCollection THEN m_pGradientStopCollection->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientStopCollection AS CID2D1GradientStopCollection) AS ID2D1GradientStopCollection PTR
   RETURN gradientStopCollection.m_pGradientStopCollection
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection.@ () AS ID2D1GradientStopCollection PTR PTR
   RETURN @m_pGradientStopCollection
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection.CAST () AS ID2D1GradientStopCollection PTR
   RETURN m_pGradientStopCollection
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   IF m_pGradientStopCollection = NULL THEN RETURN NULL
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1GradientStopCollection PTR, m_pGradientStopCollection)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1GradientStopCollection methods
' ========================================================================================
' ========================================================================================
' Retrieves the number of gradient stops in the collection.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection.GetGradientStopCount () AS UINT32
   D2D1_DP("")
   IF m_pGradientStopCollection = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection->GetGradientStopCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies the gradient stops from the collection into an array of D2D1_GRADIENT_STOP structures.
' ========================================================================================
PRIVATE SUB CID2D1GradientStopCollection.GetGradientStops (BYREF gradientStops AS D2D1_GRADIENT_STOP, BYVAL gradientStopsCount AS UINT32)
   D2D1_DP("")
   IF m_pGradientStopCollection = NULL THEN EXIT SUB
   m_pGradientStopCollection->GetGradientStops(gradientStops, gradientStopsCount)
END SUB
' ========================================================================================

' ========================================================================================
' Indicates the gamma space in which the gradient stops are interpolated.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection.GetColorInterpolationGamma () AS D2D1_GAMMA
   D2D1_DP("")
   IF m_pGradientStopCollection = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection->GetColorInterpolationGamma
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates the behavior of the gradient outside the normalized gradient range.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection.GetExtendMode () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pGradientStopCollection = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection->GetExtendMode
END FUNCTION
' ========================================================================================

' ########################################################################################
' CID2D1GradientStopCollection1 class
' Represents a collection of D2D1_GRADIENT_STOP objects for linear and radial gradient brushes.
' It provides get methods for all the new parameters added to the gradient stop collection.
' ########################################################################################

TYPE CID2D1GradientStopCollection1 EXTENDS CID2D1GradientStopCollection
Public:

   m_pGradientStopCollection1 AS ID2D1GradientStopCollection1 PTR

   DECLARE CONSTRUCTOR (BYVAL pGradientStopCollection1 AS ID2D1GradientStopCollection1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GradientStopCollection1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GradientStopCollection1 PTR

   DECLARE SUB GetGradientStops1 (BYREF gradientStops AS D2D1_GRADIENT_STOP, BYVAL gradientStopsCount AS UINT32)
   DECLARE FUNCTION GetPreInterpolationSpace () AS D2D1_COLOR_SPACE
   DECLARE FUNCTION GetPostInterpolationSpace () AS D2D1_COLOR_SPACE
   DECLARE FUNCTION GetBufferPrecision () AS D2D1_BUFFER_PRECISION
   DECLARE FUNCTION GetColorInterpolationMode () AS D2D1_COLOR_INTERPOLATION_MODE

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GradientStopCollection class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GradientStopCollection1 (BYVAL pGradientStopCollection1 AS ID2D1GradientStopCollection1 PTR)
   D2D1_DP("pGradientStopCollection1 - " & WSTR(pGradientStopCollection1))
   m_pGradientStopCollection1 = pGradientStopCollection1
   IF m_pGradientStopCollection1 THEN m_pGradientStopCollection1->AddRef
   m_pGradientStopCollection = m_pGradientStopCollection1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GradientStopCollection1
   D2D1_DP("m_pGradientStopCollection1: " & WSTR(1))
   IF m_pGradientStopCollection1 THEN m_pGradientStopCollection1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientStopCollection AS CID2D1GradientStopCollection1) AS ID2D1GradientStopCollection1 PTR
   RETURN gradientStopCollection.m_pGradientStopCollection1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection1.@ () AS ID2D1GradientStopCollection1 PTR PTR
   RETURN @m_pGradientStopCollection1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection1.CAST () AS ID2D1GradientStopCollection1 PTR
   RETURN m_pGradientStopCollection1
END OPERATOR
' ========================================================================================

' ========================================================================================
' Copies the gradient stops from the collection into an array of D2D1_GRADIENT_STOP structures.
' ========================================================================================
PRIVATE SUB CID2D1GradientStopCollection1.GetGradientStops1 (BYREF gradientStops AS D2D1_GRADIENT_STOP, BYVAL gradientStopsCount AS UINT32)
   D2D1_DP("")
   IF m_pGradientStopCollection1 = NULL THEN EXIT SUB
   m_pGradientStopCollection1->GetGradientStops1(gradientStops, gradientStopsCount)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the color space of the input colors as well as the space in which gradient stops are interpolated.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection1.GetPreInterpolationSpace () AS D2D1_COLOR_SPACE
   D2D1_DP("")
   IF m_pGradientStopCollection1 = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection1->GetPreInterpolationSpace
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color space after interpolation has occurred.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection1.GetPostInterpolationSpace () AS D2D1_COLOR_SPACE
   D2D1_DP("")
   IF m_pGradientStopCollection1 = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection1->GetPostInterpolationSpace
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the precision of the gradient buffer.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection1.GetBufferPrecision () AS D2D1_BUFFER_PRECISION
   D2D1_DP("")
   IF m_pGradientStopCollection1 = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection1->GetBufferPrecision
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the precision of the gradient buffer.
' ========================================================================================
PRIVATE FUNCTION CID2D1GradientStopCollection1.GetColorInterpolationMode () AS D2D1_COLOR_INTERPOLATION_MODE
   D2D1_DP("")
   IF m_pGradientStopCollection1 = NULL THEN EXIT FUNCTION
   RETURN m_pGradientStopCollection1->GetColorInterpolationMode
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1SolidColorBrush class
' Paints an area with a solid color.
' ########################################################################################

' ========================================================================================
TYPE CID2D1SolidColorBrush
Public:

   m_pSolidColorBrush AS ID2D1SolidColorBrush PTR

   DECLARE CONSTRUCTOR (BYVAL pSolidColorBrush AS ID2D1SolidColorBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1SolidColorBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1SolidColorBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Brush
   DECLARE SUB SetOpacity (BYVAL opacity AS FLOAT)
   DECLARE FUNCTION GetOpacity () AS FLOAT
   DECLARE SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F

   ' // ID2D1SolidColorBrush
   DECLARE SUB SetColor (BYREF clr AS D2D1_COLOR_F)
   DECLARE SUB SetColor (BYVAL clr AS D2D1_COLOR_F PTR)
   DECLARE FUNCTION GetColor () AS D2D1_COLOR_F
   DECLARE SUB GetColor (BYREF clr AS D2D1_COLOR_F)
   DECLARE SUB GetColor (BYVAL clr AS D2D1_COLOR_F PTR)

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1SolidColorBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SolidColorBrush (BYVAL pSolidColorBrush AS ID2D1SolidColorBrush PTR)
   D2D1_DP("pSolidColorBrush - " & WSTR(pSolidColorBrush))
   m_pSolidColorBrush = psolidColorBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1SolidColorBrush
   D2D1_DP("m_pSolidColorBrush: " & WSTR(m_pSolidColorBrush))
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1SolidColorBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF solidColorBrush AS CID2D1SolidColorBrush) AS ID2D1SolidColorBrush PTR
   RETURN solidColorBrush.m_pSolidColorBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1SolidColorBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.@ () AS ID2D1SolidColorBrush PTR PTR
   RETURN @m_pSolidColorBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1SolidColorBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.CAST () AS ID2D1SolidColorBrush PTR
   RETURN m_pSolidColorBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pSolidColorBrush)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1SolidColorBrush.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pBrush AS ID2D1Brush PTR = CAST(ID2D1Brush PTR, m_pSolidColorBrush)
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, pBrush)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================
 
' ========================================================================================
' Inherited ID2D1Brush interface methods
' ========================================================================================
' ========================================================================================
' Sets the degree of opacity of this brush.
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.SetOpacity (BYVAL opacity AS FLOAT)
   D2D1_DP(WSTR(opacity))
   IF m_pSolidColorBrush THEN cast(ID2D1Brush PTR, m_pSolidColorBrush)->SetOpacity(opacity)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the degree of opacity of this brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1SolidColorBrush.GetOpacity () AS FLOAT
   D2D1_DP("")
   IF m_pSolidColorBrush THEN RETURN cast(ID2D1Brush PTR, m_pSolidColorBrush)->GetOpacity
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the transformation applied to the brush.
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN cast(ID2D1Brush PTR, m_pSolidColorBrush)->SetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN cast(ID2D1Brush PTR, m_pSolidColorBrush)->SetTransform(BYVAL transform)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the transform applied to this brush.
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN cast(ID2D1Brush PTR, m_pSolidColorBrush)->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN cast(ID2D1Brush PTR, m_pSolidColorBrush)->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1SolidColorBrush.GetTransform () AS D2D1_MATRIX_3X2_F
   D2D1_DP("")
   DIM transform AS D2D1_MATRIX_3X2_F
   IF m_pSolidColorBrush THEN cast(ID2D1Brush PTR, m_pSolidColorBrush)->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1SolidColorBrush interface methods
' ========================================================================================
' ========================================================================================
' Specifies the color of this solid-color brush.
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.SetColor (BYREF clr AS D2D1_COLOR_F)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->SetColor(clr)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.SetColor (BYVAL clr AS D2D1_COLOR_F PTR)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->SetColor(BYVAL clr)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the color of the solid color brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1SolidColorBrush.GetColor () AS D2D1_COLOR_F
   D2D1_DP("")
   DIM clr AS D2D1_COLOR_F
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->GetColor(clr)
   RETURN clr
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.GetColor (BYREF clr AS D2D1_COLOR_F)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->GetColor(clr)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SolidColorBrush.GetColor (BYVAL clr AS D2D1_COLOR_F PTR)
   D2D1_DP("")
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->GetColor(BYVAL clr)
END SUB
' ========================================================================================


' ########################################################################################
' CID2D1LinearGradientBrush class
' Paints an area with a linear gradient.
' ########################################################################################

' ========================================================================================
TYPE CID2D1LinearGradientBrush
Public:

   m_pLinearGradientBrush AS ID2D1LinearGradientBrush PTR

   DECLARE CONSTRUCTOR (BYVAL pLinearGradientBrush AS ID2D1LinearGradientBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1LinearGradientBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1LinearGradientBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Brush
   DECLARE SUB SetOpacity (BYVAL opacity AS FLOAT)
   DECLARE FUNCTION GetOpacity () AS FLOAT
   DECLARE SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F

   ' // ID2D1LinearGradientBrush
   DECLARE SUB SetStartPoint (BYVAL startPoint AS D2D1_POINT_2F)
   DECLARE SUB SetStartPoint (BYVAL x AS SINGLE, BYVAL y AS SINGLE)
   DECLARE SUB SetEndPoint (BYVAL endPoint AS D2D1_POINT_2F)
   DECLARE SUB SetEndPoint (BYVAL x AS SINGLE, BYVAL y AS SINGLE)
   DECLARE SUB GetStartPoint (BYREF startPoint AS D2D1_POINT_2F)
   DECLARE SUB GetStartPoint (BYVAL startPoint AS D2D1_POINT_2F PTR)
   DECLARE SUB GetEndPoint (BYREF endPoint AS D2D1_POINT_2F)
   DECLARE SUB GetEndPoint (BYVAL endPoint AS D2D1_POINT_2F PTR)
   DECLARE FUNCTION GetEndPoint () AS D2D1_POINT_2F
   DECLARE FUNCTION GetGradientStopCollection () AS ID2D1GradientStopCollection PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1LinearGraientBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1LinearGradientBrush (BYVAL pLinearGradientBrush AS ID2D1LinearGradientBrush PTR)
   D2D1_DP("pLinearGradientBrush - " & WSTR(pLinearGradientBrush))
   m_pLinearGradientBrush = pLinearGradientBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1LinearGradientBrush
   D2D1_DP("m_pLinearGradientBrush: " & WSTR(m_pLinearGradientBrush))
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF linearGradientBrush AS CID2D1LinearGradientBrush) AS ID2D1LinearGradientBrush PTR
   RETURN linearGradientBrush.m_pLinearGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.@ () AS ID2D1LinearGradientBrush PTR PTR
   RETURN @m_pLinearGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.CAST () AS ID2D1LinearGradientBrush PTR
   RETURN m_pLinearGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pLinearGradientBrush)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1LinearGradientBrush.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, m_pLinearGradientBrush)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================
 
' ========================================================================================
' Inherited ID2D1Brush interface methods
' ========================================================================================
' ========================================================================================
' Sets the degree of opacity of this brush.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetOpacity (BYVAL opacity AS FLOAT)
   D2D1_DP(WSTR(opacity))
   IF m_pLinearGradientBrush THEN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->SetOpacity(opacity)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the degree of opacity of this brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1LinearGradientBrush.GetOpacity () AS FLOAT
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN RETURN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->GetOpacity
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the transformation applied to the brush.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->SetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->SetTransform(BYVAL transform)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the transform applied to this brush.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1LinearGradientBrush.GetTransform () AS D2D1_MATRIX_3X2_F
   D2D1_DP("")
   DIM transform AS D2D1_MATRIX_3X2_F
   IF m_pLinearGradientBrush THEN cast(ID2D1Brush PTR, m_pLinearGradientBrush)->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1LinearGradientBrush interface methods
' ========================================================================================
' ========================================================================================
' Sets the starting coordinates of the linear gradient in the brush's coordinate space.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetStartPoint (BYVAL startPoint AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->SetStartPoint(startPoint)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetStartPoint (BYVAL x AS SINGLE, BYVAL y AS SINGLE)
   D2D1_DP("")
   DIM startPoint AS D2D1_POINT_2F = (x, y)
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->SetStartPoint(startPoint)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the ending coordinates of the linear gradient in the brush's coordinate space.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetEndPoint (BYVAL endPoint AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->SetEndPoint(endPoint)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.SetEndPoint (BYVAL x AS SINGLE, BYVAL y AS SINGLE)
   D2D1_DP("")
   DIM endPoint AS D2D1_POINT_2F = (x, y)
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->SetEndPoint(endPoint)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the starting coordinates of the linear gradient.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.GetStartPoint (BYREF startPoint AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->GetStartPoint(startPoint)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.GetStartPoint (BYVAL startPoint AS D2D1_POINT_2F PTR)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->GetStartPoint(BYVAL startPoint)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the ending coordinates of the linear gradient.
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.GetEndPoint (BYREF endPoint AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->GetEndPoint(endPoint)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1LinearGradientBrush.GetEndPoint (BYVAL endPoint AS D2D1_POINT_2F PTR)
   D2D1_DP("")
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->GetEndPoint(BYVAL endPoint)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1LinearGradientBrush.GetEndPoint () AS D2D1_POINT_2F
   D2D1_DP("")
   DIM endPoint AS D2D1_POINT_2F
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->GetEndPoint(endPoint)
   RETURN endPoint
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the ID2D1GradientStopCollection associated with this linear gradient brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1LinearGradientBrush.GetGradientStopCollection () AS ID2D1GradientStopCollection PTR
   D2D1_DP("")
   DIM gradientStopCollection AS ID2D1GradientStopCollection PTR
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->GetGradientStopCollection(gradientStopCollection)
   RETURN gradientStopCollection
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1RadialGradientBrush class
' Paints an area with a radial gradient.
' ########################################################################################

' ========================================================================================
TYPE CID2D1RadialGradientBrush
Public:

   m_pRadialGradientBrush AS ID2D1RadialGradientBrush PTR

   DECLARE CONSTRUCTOR (BYVAL pRadialGradientBrush AS ID2D1RadialGradientBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RadialGradientBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RadialGradientBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Brush
   DECLARE SUB SetOpacity (BYVAL opacity AS FLOAT)
   DECLARE FUNCTION GetOpacity () AS FLOAT
   DECLARE SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F

   ' // ID2D1RadialGradientBrush
   DECLARE SUB SetCenter (BYVAL center AS D2D1_POINT_2F)
   DECLARE SUB SetCenter (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE)
   DECLARE SUB SetGradientOriginOffset (BYVAL gradientOriginOffset AS D2D1_POINT_2F)
   DECLARE SUB SetGradientOriginOffset (BYVAL gradientOriginOffsetX AS SINGLE, BYVAL gradientOriginOffsetXY AS SINGLE)
   DECLARE SUB SetRadiusX (BYVAL radiusX AS FLOAT)
   DECLARE SUB SetRadiusY (BYVAL radiusY AS FLOAT)
   DECLARE FUNCTION GetCenter () AS D2D1_POINT_2F
   DECLARE FUNCTION GetGradientOriginOffset () AS D2D1_POINT_2F
   DECLARE FUNCTION GetRadiusX () AS FLOAT
   DECLARE FUNCTION GetRadiusY () AS FLOAT
   DECLARE FUNCTION GetGradientStopCollection () AS ID2D1GradientStopCollection PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RadialGradientBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RadialGradientBrush (BYVAL pRadialGradientBrush AS ID2D1RadialGradientBrush PTR)
   D2D1_DP("pRadialGradientBrush - " & WSTR(pRadialGradientBrush))
   m_pRadialGradientBrush = pRadialGradientBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RadialGradientBrush
   D2D1_DP("m_pRadialGradientBrush: " & WSTR(m_pRadialGradientBrush))
   IF m_pRadialGradientBrush THEN m_pRadialGradientBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF radialGradientBrush AS CID2D1RadialGradientBrush) AS ID2D1RadialGradientBrush PTR
   RETURN radialGradientBrush.m_pRadialGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.@ () AS ID2D1RadialGradientBrush PTR PTR
   RETURN @m_pRadialGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.CAST () AS ID2D1RadialGradientBrush PTR
   RETURN m_pRadialGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pRadialGradientBrush)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, m_pRadialGradientBrush)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Brush interface methods
' ========================================================================================
' ========================================================================================
' Sets the degree of opacity of this brush.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetOpacity (BYVAL opacity AS FLOAT)
   D2D1_DP(WSTR(opacity))
   IF m_pRadialGradientBrush THEN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->SetOpacity(opacity)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the degree of opacity of this brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetOpacity () AS FLOAT
   D2D1_DP("")
   IF m_pRadialGradientBrush THEN RETURN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->GetOpacity
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the transformation applied to the brush.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pRadialGradientBrush THEN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->SetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pRadialGradientBrush THEN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->SetTransform(BYVAL transform)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the transform applied to this brush.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pRadialGradientBrush THEN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pRadialGradientBrush THEN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetTransform () AS D2D1_MATRIX_3X2_F
   D2D1_DP("")
   DIM transform AS D2D1_MATRIX_3X2_F
   IF m_pRadialGradientBrush THEN cast(ID2D1Brush PTR, m_pRadialGradientBrush)->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1RadialGradientBrush interface methods
' ========================================================================================
' ========================================================================================
' Specifies the center of the gradient ellipse in the brush's coordinate space.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetCenter (BYVAL center AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT SUB
   m_pRadialGradientBrush->SetCenter(center)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetCenter (BYVAL centerX AS SINGLE, BYVAL centerY AS SINGLE)
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT SUB
   DIM center AS D2D1_POINT_2F = (centerX, centerY)
   m_pRadialGradientBrush->SetCenter(center)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies the offset of the gradient origin relative to the gradient ellipse's center.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetGradientOriginOffset (BYVAL gradientOriginOffset AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT SUB
   m_pRadialGradientBrush->SetGradientOriginOffset(gradientOriginOffset)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetGradientOriginOffset (BYVAL gradientOriginOffsetX AS SINGLE, BYVAL gradientOriginOffsetY AS SINGLE)
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT SUB
   DIM gradientOriginOffset AS D2D1_POINT_2F = (gradientOriginOffsetX, gradientOriginOffsetY)
   m_pRadialGradientBrush->SetGradientOriginOffset(gradientOriginOffset)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies the x-radius of the gradient ellipse, in the brush's coordinate space.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetRadiusX (BYVAL radiusX AS SINGLE)
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT SUB
   m_pRadialGradientBrush->SetRadiusX(radiusX)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies the y-radius of the gradient ellipse, in the brush's coordinate space.
' ========================================================================================
PRIVATE SUB CID2D1RadialGradientBrush.SetRadiusY (BYVAL radiusY AS SINGLE)
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT SUB
   m_pRadialGradientBrush->SetRadiusY(radiusY)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the center of the gradient ellipse.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetCenter () AS D2D1_POINT_2F
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT FUNCTION
   DIM center AS D2D1_POINT_2F
   m_pRadialGradientBrush->GetCenter(center)
   RETURN center
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the offset of the gradient origin relative to the gradient ellipse's center.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetGradientOriginOffset () AS D2D1_POINT_2F
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT FUNCTION
   DIM originOffset AS D2D1_POINT_2F
   m_pRadialGradientBrush->GetGradientOriginOffset(originOffset)
   RETURN originOffset
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the x-radius of the gradient ellipse.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetRadiusX () AS FLOAT
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT FUNCTION
   RETURN m_pRadialGradientBrush->GetRadiusX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the y-radius of the gradient ellipse.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetRadiusY () AS FLOAT
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT FUNCTION
   RETURN m_pRadialGradientBrush->GetRadiusY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the ID2D1GradientStopCollection associated with this radial gradient brush object.
' ========================================================================================
PRIVATE FUNCTION CID2D1RadialGradientBrush.GetGradientStopCollection () AS ID2D1GradientStopCollection PTR
   D2D1_DP("")
   IF m_pRadialGradientBrush = NULL THEN EXIT FUNCTION
   DIM gradientStopCollection AS ID2D1GradientStopCollection PTR
   m_pRadialGradientBrush->GetGradientStopCollection(gradientStopCollection)
   RETURN gradientStopCollection
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1BitmapBrush class
' Paints an area with a bitmap.
' ########################################################################################

' ========================================================================================
TYPE CID2D1BitmapBrush
Public:

   m_pBitmapBrush AS ID2D1BitmapBrush PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pID2D1BitmapBrush AS ID2D1BitmapBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1BitmapBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1BitmapBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Brush
   DECLARE SUB SetOpacity (BYVAL opacity AS FLOAT)
   DECLARE FUNCTION GetOpacity () AS FLOAT
   DECLARE SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F

   ' // ID2D1BitmapBrush
   DECLARE SUB SetExtendModeX (BYVAL extendModeX AS D2D1_EXTEND_MODE)
   DECLARE SUB SetExtendModeY (BYVAL extendModeY AS D2D1_EXTEND_MODE)
   DECLARE SUB SetInterpolationMode (BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE)
   DECLARE SUB SetBitmap (BYVAL bitmap AS ID2D1Bitmap PTR)
   DECLARE FUNCTION GetExtendModeX () AS D2D1_EXTEND_MODE
   DECLARE FUNCTION GetExtendModeY () AS D2D1_EXTEND_MODE
   DECLARE FUNCTION GetInterpolationMode () AS D2D1_BITMAP_INTERPOLATION_MODE
   DECLARE FUNCTION GetBitmap () AS ID2D1Bitmap PTR

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapBrush
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1BitmapBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapBrush (BYVAL pBitmapBrush AS ID2D1BitmapBrush PTR)
   D2D1_DP("pBitmapBrush - " & WSTR(pBitmapBrush))
   m_pBitmapBrush = pBitmapBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1BitmapBrush
   D2D1_DP("m_pBitmapBrush: " & WSTR(m_pBitmapBrush))
   IF m_pBitmapBrush THEN m_pBitmapBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1BitmapBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF bitmapBrush AS CID2D1BitmapBrush) AS ID2D1BitmapBrush PTR
   RETURN bitmapBrush.m_pBitmapBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1BitmapBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.@ () AS ID2D1BitmapBrush PTR PTR
   RETURN @m_pBitmapBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1BitmapBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.CAST () AS ID2D1BitmapBrush PTR
   RETURN m_pBitmapBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pBitmapBrush)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, m_pBitmapBrush)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Brush interface methods
' ========================================================================================
' ========================================================================================
' Sets the degree of opacity of this brush.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetOpacity (BYVAL opacity AS FLOAT)
   D2D1_DP(WSTR(opacity))
   IF m_pBitmapBrush THEN cast(ID2D1Brush PTR, m_pBitmapBrush)->SetOpacity(opacity)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the degree of opacity of this brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetOpacity () AS FLOAT
   D2D1_DP("")
   IF m_pBitmapBrush THEN RETURN cast(ID2D1Brush PTR, m_pBitmapBrush)->GetOpacity
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the transformation applied to the brush.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pBitmapBrush THEN cast(ID2D1Brush PTR, m_pBitmapBrush)->SetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pBitmapBrush THEN cast(ID2D1Brush PTR, m_pBitmapBrush)->SetTransform(BYVAL transform)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the transform applied to this brush.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pBitmapBrush THEN cast(ID2D1Brush PTR, m_pBitmapBrush)->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pBitmapBrush THEN cast(ID2D1Brush PTR, m_pBitmapBrush)->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetTransform () AS D2D1_MATRIX_3X2_F
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT FUNCTION
   DIM transform AS D2D1_MATRIX_3X2_F
   IF m_pBitmapBrush THEN cast(ID2D1Brush PTR, m_pBitmapBrush)->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1BitmapBrush interface methods
' ========================================================================================
' ========================================================================================
' Specifies how the brush horizontally tiles those areas that extend past its bitmap.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetExtendModeX (BYVAL extendModeX AS D2D1_EXTEND_MODE)
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT SUB
   m_pBitmapBrush->SetExtendModeX(extendModeX)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies how the brush vertically tiles those areas that extend past its bitmap.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetExtendModeY (BYVAL extendModeY AS D2D1_EXTEND_MODE)
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT SUB
   m_pBitmapBrush->SetExtendModeY(extendModeY)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies the interpolation mode used when the brush bitmap is scaled or rotated.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetInterpolationMode (BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE)
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT SUB
   m_pBitmapBrush->SetInterpolationMode(InterpolationMode)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies the bitmap source that this brush uses to paint.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush.SetBitmap (BYVAL bitmap AS ID2D1Bitmap PTR)
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT SUB
   m_pBitmapBrush->SetBitmap(bitmap)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the method by which the brush horizontally tiles those areas that extend past its bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetExtendModeX () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT FUNCTION
   RETURN m_pBitmapBrush->GetExtendModeX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the method by which the brush vertically tiles those areas that extend past its bitmap.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetExtendModeY () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT FUNCTION
   RETURN m_pBitmapBrush->GetExtendModeY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the interpolation method used when the brush bitmap is scaled or rotated.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetInterpolationMode () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT FUNCTION
   RETURN m_pBitmapBrush->GetInterpolationMode
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bitmap source that this brush uses to paint.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush.GetBitmap () AS ID2D1Bitmap PTR
   D2D1_DP("")
   IF m_pBitmapBrush = NULL THEN EXIT FUNCTION
   DIM bitmap AS ID2D1Bitmap PTR
   m_pBitmapBrush->GetBitmap(bitmap)
   RETURN bitmap
END FUNCTION
' ========================================================================================

' ########################################################################################
' CID2D1BitmapBrush1 class
' Paints an area with a bitmap.
' ########################################################################################

' ========================================================================================
TYPE CID2D1BitmapBrush1 EXTENDS CID2D1BitmapBrush
Public:

   m_pBitmapBrush1 AS ID2D1BitmapBrush1 PTR

   DECLARE CONSTRUCTOR (BYVAL pBitmapBrush1 AS ID2D1BitmapBrush1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1BitmapBrush1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1BitmapBrush1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE SUB SetInterpolationMode1 (BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE)
   DECLARE FUNCTION GetInterpolationMode1 () AS D2D1_BITMAP_INTERPOLATION_MODE

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1BitmapBrush1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapBrush1 (BYVAL pBitmapBrush1 AS ID2D1BitmapBrush1 PTR)
   D2D1_DP("pBitmapBrush - " & WSTR(pBitmapBrush1))
   m_pBitmapBrush1 = pBitmapBrush1
   IF m_pBitmapBrush1 THEN m_pBitmapBrush1->AddRef
   m_pBitmapBrush = CAST(ID2D1BitmapBrush PTR, m_pBitmapBrush1)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1BitmapBrush1
   D2D1_DP("m_pBitmapBrush1: " & WSTR(m_pBitmapBrush1))
   IF m_pBitmapBrush1 THEN m_pBitmapBrush1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying CID2D1BitmapBrush1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF bitmapBrush AS CID2D1BitmapBrush1) AS ID2D1BitmapBrush1 PTR
   RETURN bitmapBrush.m_pBitmapBrush1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying CID2D1BitmapBrush1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.@ () AS ID2D1BitmapBrush1 PTR PTR
   RETURN @m_pBitmapBrush1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1BitmapBrush1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.CAST () AS ID2D1BitmapBrush1 PTR
   RETURN m_pBitmapBrush1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pBitmapBrush1)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Sets the interpolation mode for the brush.
' ========================================================================================
PRIVATE SUB CID2D1BitmapBrush1.SetInterpolationMode1 (BYVAL InterpolationMode AS D2D1_BITMAP_INTERPOLATION_MODE)
   D2D1_DP("")
   IF m_pBitmapBrush1 = NULL THEN EXIT SUB
   m_pBitmapBrush1->SetInterpolationMode1(InterpolationMode)
END SUB
' ========================================================================================
' ========================================================================================
' Returns the current interpolation mode of the brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1BitmapBrush1.GetInterpolationMode1 () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pBitmapBrush1 = NULL THEN EXIT FUNCTION
   RETURN m_pBitmapBrush1->GetInterpolationMode1
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1ImageBrush class
' Represents a brush based on an ID2D1Image.
' ########################################################################################

' ========================================================================================
TYPE CID2D1ImageBrush
Public:

   m_pImageBrush AS ID2D1ImageBrush PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pID2D1ImageBrush AS ID2D1ImageBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1ImageBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1ImageBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Brush
   DECLARE SUB SetOpacity (BYVAL opacity AS FLOAT)
   DECLARE FUNCTION GetOpacity () AS FLOAT
   DECLARE SUB SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F

   ' // ID2D1ImageBrush
   DECLARE SUB SetImage (BYVAL image AS ID2D1Image PTR)
   DECLARE SUB SetExtendModeX (BYVAL extendModeX AS D2D1_EXTEND_MODE)
   DECLARE SUB SetExtendModeY (BYVAL extendModeY AS D2D1_EXTEND_MODE)
   DECLARE SUB SetInterpolationMode (BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE)
   DECLARE SUB SetSourceRectangle (BYREF sourceRectangle AS D2D1_RECT_F)
   DECLARE SUB SetSourceRectangle (BYVAL sourceRectangle AS D2D1_RECT_F PTR)
   DECLARE FUNCTION GetImage () AS ID2D1Image PTR
   DECLARE FUNCTION GetExtendModeX () AS D2D1_EXTEND_MODE
   DECLARE FUNCTION GetExtendModeY () AS D2D1_EXTEND_MODE
   DECLARE FUNCTION GetInterpolationMode () AS D2D1_INTERPOLATION_MODE
   DECLARE FUNCTION GetSourceRectangle () AS D2D1_RECT_F

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1ImageBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1ImageBrush (BYVAL pImageBrush AS ID2D1ImageBrush PTR)
   D2D1_DP("pImageBrush - " & WSTR(pImageBrush))
   m_pImageBrush = pImageBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1ImageBrush
   D2D1_DP("m_pImageBrush: " & WSTR(m_pImageBrush))
   IF m_pImageBrush THEN m_pImageBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1ImageBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF imageBrush AS CID2D1ImageBrush) AS ID2D1ImageBrush PTR
   RETURN imageBrush.m_pImageBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1ImageBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.@ () AS ID2D1ImageBrush PTR PTR
   RETURN @m_pImageBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1ImageBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.CAST () AS ID2D1ImageBrush PTR
   RETURN m_pImageBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pImageBrush)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, m_pImageBrush)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Brush interface methods
' ========================================================================================
' ========================================================================================
' Sets the degree of opacity of this brush.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetOpacity (BYVAL opacity AS FLOAT)
   D2D1_DP(WSTR(opacity))
   IF m_pImageBrush THEN cast(ID2D1Brush PTR, m_pImageBrush)->SetOpacity(opacity)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the degree of opacity of this brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetOpacity () AS FLOAT
   D2D1_DP("")
   IF m_pImageBrush THEN RETURN cast(ID2D1Brush PTR, m_pImageBrush)->GetOpacity
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the transformation applied to the brush.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pImageBrush THEN cast(ID2D1Brush PTR, m_pImageBrush)->SetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pImageBrush THEN cast(ID2D1Brush PTR, m_pImageBrush)->SetTransform(BYVAL transform)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the transform applied to this brush.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   D2D1_DP("")
   IF m_pImageBrush THEN cast(ID2D1Brush PTR, m_pImageBrush)->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   D2D1_DP("")
   IF m_pImageBrush THEN cast(ID2D1Brush PTR, m_pImageBrush)->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetTransform () AS D2D1_MATRIX_3X2_F
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT FUNCTION
   DIM transform AS D2D1_MATRIX_3X2_F
   IF m_pImageBrush THEN cast(ID2D1Brush PTR, m_pImageBrush)->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the image associated with the provided image brush.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetImage (BYVAL image AS ID2D1Image PTR)
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT SUB
   m_pImageBrush->SetImage(image)
END SUB
' ========================================================================================

' ========================================================================================
' Sets how the content inside the source rectangle in the image brush will be extended on the x-axis.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetExtendModeX (BYVAL extendModeX AS D2D1_EXTEND_MODE)
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT SUB
   m_pImageBrush->SetExtendModeX(extendModeX)
END SUB
' ========================================================================================

' ========================================================================================
' Sets how the content inside the source rectangle in the image brush will be extended on the y-axis.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetExtendModeY (BYVAL extendModeY AS D2D1_EXTEND_MODE)
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT SUB
   m_pImageBrush->SetExtendModeY(extendModeY)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the interpolation mode for the image brush.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetInterpolationMode (BYVAL InterpolationMode AS D2D1_INTERPOLATION_MODE)
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT SUB
   m_pImageBrush->SetInterpolationMode(InterpolationMode)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the source rectangle in the image brush.
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetSourceRectangle (BYREF sourceRectangle AS D2D1_RECT_F)
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT SUB
   m_pImageBrush->SetSourceRectangle(sourceRectangle)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1ImageBrush.SetSourceRectangle (BYVAL sourceRectangle AS D2D1_RECT_F PTR)
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT SUB
   m_pImageBrush->SetSourceRectangle(BYVAL sourceRectangle)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the image associated with the image brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetImage () AS ID2D1Image PTR
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT FUNCTION
   DIM image AS ID2D1Image PTR
   m_pImageBrush->GetImage(image)
   RETURN image
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the extend mode of the image brush on the x-axis.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetExtendModeX () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT FUNCTION
   RETURN m_pImageBrush->GetExtendModeX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the extend mode of the image brush on the y-axis.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetExtendModeY () AS D2D1_EXTEND_MODE
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT FUNCTION
   RETURN m_pImageBrush->GetExtendModeY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the interpolation mode of the image brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetInterpolationMode () AS D2D1_INTERPOLATION_MODE
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT FUNCTION
   RETURN m_pImageBrush->GetInterpolationMode
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the rectangle that will be used as the bounds of the image when drawn as an image brush.
' ========================================================================================
PRIVATE FUNCTION CID2D1ImageBrush.GetSourceRectangle () AS D2D1_RECT_F
   D2D1_DP("")
   IF m_pImageBrush = NULL THEN EXIT FUNCTION
   DIM sourceRectangle AS D2D1_RECT_F
   m_pImageBrush->GetSourceRectangle(sourceRectangle)
   RETURN sourceRectangle
END FUNCTION
' ========================================================================================
