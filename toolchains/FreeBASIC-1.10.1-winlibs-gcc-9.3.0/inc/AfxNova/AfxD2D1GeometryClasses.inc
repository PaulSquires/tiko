' D2D1 brush classes
' To be included by AfxD2D1Objects.inc

' ########################################################################################
' CID2D1Geometry class
' Represents a geometry resource and defines a set of helper methods for manipulating and
' measuring geometric shapes. 
' ########################################################################################

TYPE CID2D1Geometry
Public:

   m_pGeometry AS ID2D1Geometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGeometry AS ID2D1Geometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Geometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Geometry PTR

   ' // ID2D1Resource
   DECLARE FUNCTION GetFactory () AS ID2D1Factory PTR

   ' // ID2D1Geometry
   ' ---
   DECLARE FUNCTION GetBounds (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE FUNCTION GetBounds (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL bounds AS D2D1_RECT_F PTR) AS HRESULT
   DECLARE FUNCTION GetBounds (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_RECT_F
   DECLARE FUNCTION GetBounds (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS D2D1_RECT_F
   ' ---
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, BYVAL bounds AS D2D1_RECT_F PTR) AS HRESULT
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS D2D1_RECT_F
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS D2D1_RECT_F
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL bounds AS D2D1_RECT_F PTR) AS HRESULT
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_RECT_F
   DECLARE FUNCTION GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS D2D1_RECT_F
   ' ---
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYREF contains AS BOOLEAN) AS HRESULT
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL contains AS BOOLEAN PTR) AS HRESULT
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF contains AS BOOLEAN) AS HRESULT
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL contains AS BOOLEAN PTR) AS HRESULT
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS BOOLEAN
   DECLARE FUNCTION StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
           BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS BOOLEAN
   ' ---
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYREF contains AS BOOLEAN) AS HRESULT
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL contains AS BOOLEAN PTR) AS HRESULT
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYREF contains AS BOOLEAN) AS HRESULT
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL contains AS BOOLEAN PTR) AS HRESULT
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS BOOLEAN
   DECLARE FUNCTION FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS BOOLEAN
   ' ---
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
           BYREF relation AS D2D1_GEOMETRY_RELATION) AS HRESULT
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
           BYVAL relation AS D2D1_GEOMETRY_RELATION PTR) AS HRESULT
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS D2D1_GEOMETRY_RELATION
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS D2D1_GEOMETRY_RELATION
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYREF relation AS D2D1_GEOMETRY_RELATION) AS HRESULT
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL relation AS D2D1_GEOMETRY_RELATION PTR) AS HRESULT
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_GEOMETRY_RELATION
   DECLARE FUNCTION CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR) AS D2D1_GEOMETRY_RELATION
   ' ---
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   ' ---
   DECLARE FUNCTION Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   DECLARE FUNCTION Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   DECLARE FUNCTION Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT) AS ID2D1TessellationSink PTR
   DECLARE FUNCTION Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT) AS ID2D1TessellationSink PTR
   DECLARE FUNCTION Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   DECLARE FUNCTION Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   DECLARE FUNCTION Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1TessellationSink PTR
   DECLARE FUNCTION Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1TessellationSink PTR
   ' ---
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
           BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   ' ---
   DECLARE FUNCTION Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   ' ---
   DECLARE FUNCTION ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, BYREF area AS FLOAT) AS HRESULT
   DECLARE FUNCTION ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, BYVAL area AS FLOAT PTR) AS HRESULT
   DECLARE FUNCTION ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS FLOAT
' DECLARE FUNCTION ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS FLOAT
' Conflicts with the function below!
   DECLARE FUNCTION ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF area AS FLOAT) AS HRESULT
   DECLARE FUNCTION ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL area AS FLOAT PTR) AS HRESULT
   DECLARE FUNCTION ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS FLOAT
   DECLARE FUNCTION ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS FLOAT
   ' ---
   DECLARE FUNCTION ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYREF Length AS FLOAT) AS HRESULT
   DECLARE FUNCTION ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL Length AS FLOAT PTR) AS HRESULT
   DECLARE FUNCTION ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF Length AS FLOAT) AS HRESULT
   DECLARE FUNCTION ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL Length AS FLOAT PTR) AS HRESULT
'   DECLARE FUNCTION ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS FLOAT
   DECLARE FUNCTION ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS FLOAT
   DECLARE FUNCTION ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS FLOAT
   ' ---
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYREF point AS D2D1_POINT_2F, BYREF unitTangentVector AS D2D1_POINT_2F) AS HRESULT
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL pt AS D2D1_POINT_2F PTR, BYVAL unitTangentVector AS D2D1_POINT_2F PTR) AS HRESULT
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYREF point AS D2D1_POINT_2F, BYREF unitTangentVector AS D2D1_POINT_2F) AS HRESULT
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL pt AS D2D1_POINT_2F PTR, BYVAL unitTangentVector AS D2D1_POINT_2F PTR) AS HRESULT
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYVAL flatteningTolerance AS FLOAT, BYREF pt AS D2D1_POINT_2F) AS D2D1_POINT_2F
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL flatteningTolerance AS FLOAT, BYVAL pt AS D2D1_POINT_2F PTR) AS D2D1_POINT_2F
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
           BYREF pt AS D2D1_POINT_2F) AS D2D1_POINT_2F
   DECLARE FUNCTION ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
           BYVAL pt AS D2D1_POINT_2F PTR) AS D2D1_POINT_2F
   ' ---
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
           BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   DECLARE FUNCTION Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
           BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Geometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Geometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Geometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Geometry (BYVAL pGeometry AS ID2D1Geometry PTR)
   D2D1_DP("pGeometry - " & WSTR(pGeometry))
   m_pGeometry = pGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1Geometry
   D2D1_DP("m_pGeometry: " & WSTR(m_pGeometry))
   IF m_pGeometry THEN m_pGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1Geometry) AS ID2D1Geometry PTR
   RETURN geometry.m_pGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Geometry.@ () AS ID2D1Geometry PTR PTR
   RETURN @m_pGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Geometry.CAST () AS ID2D1Geometry PTR
   RETURN m_pGeometry
END OPERATOR
' ========================================================================================

' ========================================================================================
' Inherited ID2D1Resource inteface method
' ========================================================================================
' ========================================================================================
' Retrieves the factory associated with this resource.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetFactory () AS ID2D1Factory PTR
   D2D1_DP("")
   IF m_pGeometry = NULL THEN RETURN NULL
   DIM factory AS ID2D1Factory PTR
   DIM pResource AS ID2D1Resource PTR = CAST(ID2D1Resource PTR, m_pGeometry)
   pResource->GetFactory(factory)
   RETURN factory
END FUNCTION
' ========================================================================================

' ========================================================================================
' ID2D1Geometry methods
' ========================================================================================
' ========================================================================================
' Retrieves the bounds of the geometry.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetBounds (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->GetBounds(worldTransform, bounds)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetBounds (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL bounds AS D2D1_RECT_F PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->GetBounds(BYVAL worldTransform, BYVAL bounds)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetBounds (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_RECT_F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM bounds AS D2D1_RECT_F
   SetLastError(m_pGeometry->GetBounds(worldTransform, bounds))
   RETURN bounds
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetBounds (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS D2D1_RECT_F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM bounds AS D2D1_RECT_F
   SetLastError(m_pGeometry->GetBounds(BYVAL worldTransform, bounds))
   RETURN bounds
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounds of the geometry after it has been widened by the specified stroke width
' and style and transformed by the specified matrix.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, worldTransform, flatteningTolerance, bounds)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, BYVAL bounds AS D2D1_RECT_F PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, BYVAL worldTransform, flatteningTolerance, BYVAL bounds)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS D2D1_RECT_F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM bounds AS D2D1_RECT_F
   SetLastError(m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, worldTransform, flatteningTolerance, bounds))
   RETURN bounds
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS D2D1_RECT_F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM bounds AS D2D1_RECT_F
   SetLastError(m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, BYVAL worldTransform, flatteningTolerance, bounds))
   RETURN bounds
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF bounds AS D2D1_RECT_F) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, bounds)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL bounds AS D2D1_RECT_F PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL bounds)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_RECT_F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM bounds AS D2D1_RECT_F
   SetLastError(m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, bounds))
   RETURN bounds
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.GetWidenedBounds (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS D2D1_RECT_F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM bounds AS D2D1_RECT_F
   SetLastError(m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, bounds))
   RETURN bounds
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the geometry's stroke contains the specified point given the specified
' stroke thickness, style, and transform.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYREF contains AS BOOLEAN) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, worldTransform, flatteningTolerance, contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL contains AS BOOLEAN PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, BYVAL worldTransform, flatteningTolerance, BYVAL contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, worldTransform, flatteningTolerance, contains))
   RETURN contains
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, BYVAL worldTransform, flatteningTolerance, contains))
   RETURN contains
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF contains AS BOOLEAN) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL contains AS BOOLEAN PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL contains)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, contains))
   RETURN contains
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.StrokeContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL strokeWidth AS FLOAT, _
   BYVAL strokeStyle AS ID2D1StrokeStyle PTR, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->StrokeContainsPoint(pt, strokeWidth, strokeStyle, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, contains))
   RETURN contains
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the area filled by the geometry would contain the specified point.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYREF contains AS BOOLEAN) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->FillContainsPoint(pt, worldTransform, flatteningTolerance, contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL contains AS BOOLEAN PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->FillContainsPoint(pt, BYVAL worldTransform, flatteningTolerance, BYVAL contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->FillContainsPoint(pt, worldTransform, flatteningTolerance, contains))
   RETURN contains
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->FillContainsPoint(pt, BYVAL worldTransform, flatteningTolerance, contains))
   RETURN contains
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYREF contains AS BOOLEAN) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->FillContainsPoint(pt, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL contains AS BOOLEAN PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->FillContainsPoint(pt, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL contains)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->FillContainsPoint(pt, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, contains))
   RETURN contains
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.FillContainsPoint (BYVAL pt AS D2D1_POINT_2F, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS BOOLEAN
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM contains AS BOOLEAN
   SetLastError(m_pGeometry->FillContainsPoint(pt, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, contains))
   RETURN contains
END FUNCTION
' ========================================================================================

' ========================================================================================
' Describes the intersection between this geometry and the specified geometry.
' The comparison is performed using the default flattening tolerance.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
   BYREF relation AS D2D1_GEOMETRY_RELATION) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CompareWithGeometry(inputGeometry, inputGeometryTransform, flatteningTolerance, relation)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
   BYVAL relation AS D2D1_GEOMETRY_RELATION PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CompareWithGeometry(inputGeometry, BYVAL inputGeometryTransform, flatteningTolerance, BYVAL relation)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS D2D1_GEOMETRY_RELATION
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM relation AS D2D1_GEOMETRY_RELATION
   SetLastError(m_pGeometry->CompareWithGeometry(inputGeometry, inputGeometryTransform, flatteningTolerance, relation))
   RETURN relation
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS D2D1_GEOMETRY_RELATION
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM relation AS D2D1_GEOMETRY_RELATION
   SetLastError(m_pGeometry->CompareWithGeometry(inputGeometry, BYVAL inputGeometryTransform, flatteningTolerance, relation))
   RETURN relation
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, BYREF relation AS D2D1_GEOMETRY_RELATION) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CompareWithGeometry(inputGeometry, inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, relation)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL relation AS D2D1_GEOMETRY_RELATION PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CompareWithGeometry(inputGeometry, BYVAL inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL relation)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F) AS D2D1_GEOMETRY_RELATION
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM relation AS D2D1_GEOMETRY_RELATION
   SetLastError(m_pGeometry->CompareWithGeometry(inputGeometry, inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, relation))
   RETURN relation
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CompareWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR) AS D2D1_GEOMETRY_RELATION
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM relation AS D2D1_GEOMETRY_RELATION
   SetLastError(m_pGeometry->CompareWithGeometry(inputGeometry, BYVAL inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, relation))
   RETURN relation
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a simplified version of the geometry that contains only lines and (optionally)
' cubic Bezier curves and writes the result to an ID2D1SimplifiedGeometrySink.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   RETURN m_pGeometry->Simplify(simplificationOption, worldTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   RETURN m_pGeometry->Simplify(simplificationOption, BYVAL worldTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->Simplify(simplificationOption, worldTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->Simplify(simplificationOption, BYVAL worldTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   RETURN m_pGeometry->Simplify(simplificationOption, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   RETURN m_pGeometry->Simplify(simplificationOption, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->Simplify(simplificationOption, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Simplify (BYVAL simplificationOption AS D2D1_GEOMETRY_SIMPLIFICATION_OPTION, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->Simplify(simplificationOption, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a set of clockwise-wound triangles that cover the geometry after it has been
' transformed using the specified matrix and flattened using the specified tolerance.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Tessellate(worldTransform, flatteningTolerance, tessellationSink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Tessellate(BYVAL worldTransform, flatteningTolerance, tessellationSink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT) AS ID2D1TessellationSink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM tessellationSink AS ID2D1TessellationSink PTR
   SetLastError(m_pGeometry->Tessellate(worldTransform, flatteningTolerance, tessellationSink))
   RETURN tessellationSink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS ID2D1TessellationSink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM tessellationSink AS ID2D1TessellationSink PTR
   SetLastError(m_pGeometry->Tessellate(BYVAL worldTransform, flatteningTolerance, tessellationSink))
   RETURN tessellationSink
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Tessellate(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, tessellationSink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL tessellationSink AS ID2D1TessellationSink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Tessellate(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, tessellationSink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1TessellationSink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM tessellationSink AS ID2D1TessellationSink PTR
   SetLastError(m_pGeometry->Tessellate(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, tessellationSink))
   RETURN tessellationSink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Tessellate (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1TessellationSink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM tessellationSink AS ID2D1TessellationSink PTR
   SetLastError(m_pGeometry->Tessellate(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, tessellationSink))
   RETURN tessellationSink
END FUNCTION
' ========================================================================================

' ========================================================================================
' Combines this geometry with the specified geometry and stores the result in an ID2D1SimplifiedGeometrySink.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, inputGeometryTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, BYVAL inputGeometryTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, inputGeometryTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, BYVAL inputGeometryTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, BYVAL inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYREF inputGeometryTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.CombineWithGeometry (BYVAL inputGeometry AS ID2D1Geometry PTR, _
   BYVAL combineMode AS D2D1_COMBINE_MODE, BYVAL inputGeometryTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLasTError(m_pGeometry->CombineWithGeometry(inputGeometry, combineMode, BYVAL inputGeometryTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the outline of the geometry and writes the result to an ID2D1SimplifiedGeometrySink.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Outline(worldTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Outline(BYVAL worldTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Outline(worldTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Outline(BYVAL worldTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Outline(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Outline(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Outline(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Outline (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Outline(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
' Computes the area of the geometry after it has been transformed by the specified matrix
' and flattened using the specified tolerance.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYREF area AS FLOAT) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeArea(worldTransform, flatteningTolerance, area)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL area AS FLOAT PTR) AS HRESULT
   IF m_pGeometry  = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeArea(BYVAL worldTransform, flatteningTolerance, BYVAL area)
END FUNCTION
' ========================================================================================
' ========================================================================================
'PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
'   BYVAL flatteningTolerance AS FLOAT) AS FLOAT
'   IF m_pGeometry = NULL THEN EXIT FUNCTION
'   DIm area AS FLOAT
'   SetLastError(m_pGeometry->ComputeArea(worldTransform, flatteningTolerance, area))
'   RETURN area
'END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS FLOAT
   IF m_pGeometry  = NULL THEN EXIT FUNCTION
   DIm area AS FLOAT
   RETURN m_pGeometry->ComputeArea(BYVAL worldTransform, flatteningTolerance, area)
   RETURN area
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF area AS FLOAT) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeArea(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, area)
END FUNCTION
'' ========================================================================================
'' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL area AS FLOAT PTR) AS HRESULT
   IF m_pGeometry  = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeArea(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL area)
END FUNCTION
'' ========================================================================================

'' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS FLOAT
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIm area AS FLOAT
   SetLastError(m_pGeometry->ComputeArea(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, area))
   RETURN area
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeArea (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS FLOAT
   IF m_pGeometry  = NULL THEN EXIT FUNCTION
   DIm area AS FLOAT
   RETURN m_pGeometry->ComputeArea(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, area)
   RETURN area
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the length of the geometry as though each segment were unrolled into a line.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYREF Length AS FLOAT) AS HRESULT
   IF m_pGeometry  = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeLength(worldTransform, flatteningTolerance, Length)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL Length AS FLOAT PTR) AS HRESULT
   IF m_pGeometry  = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeLength(BYVAL worldTransform, flatteningTolerance, BYVAL Length)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYREF Length AS FLOAT) AS HRESULT
   IF m_pGeometry  = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeLength(worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, Length)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL Length AS FLOAT PTR) AS HRESULT
   IF m_pGeometry  = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputeLength(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL Length)
END FUNCTION
' ========================================================================================

' ========================================================================================
'PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
'   BYVAL flatteningTolerance AS FLOAT) AS FLOAT
'   IF m_pGeometry  = NULL THEN EXIT FUNCTION
'   DIM length AS FLOAT
'   RETURN m_pGeometry->ComputeLength(worldTransform, flatteningTolerance, Length)
'   RETURN length
'END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT) AS FLOAT
   IF m_pGeometry  = NULL THEN EXIT FUNCTION
   DIM length AS FLOAT
   RETURN m_pGeometry->ComputeLength(BYVAL worldTransform, flatteningTolerance, Length)
   RETURN length
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputeLength (BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS FLOAT
   IF m_pGeometry  = NULL THEN EXIT FUNCTION
   DIM length AS FLOAT
   RETURN m_pGeometry->ComputeLength(BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, Length)
   RETURN length
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the point and tangent vector at the specified distance along the geometry after
' it has been transformed by the specified matrix and flattened using the default tolerance.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYREF pt AS D2D1_POINT_2F, BYREF unitTangentVector AS D2D1_POINT_2F) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputePointAtLength(length, worldTransform, flatteningTolerance, pt, unitTangentVector)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL pt AS D2D1_POINT_2F PTR, BYVAL unitTangentVector AS D2D1_POINT_2F PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputePointAtLength(length, BYVAL worldTransform, flatteningTolerance, BYVAL pt, BYVAL unitTangentVector)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYREF pt AS D2D1_POINT_2F, BYREF unitTangentVector AS D2D1_POINT_2F) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputePointAtLength(length, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, pt, unitTangentVector)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL pt AS D2D1_POINT_2F PTR, BYVAL unitTangentVector AS D2D1_POINT_2F PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->ComputePointAtLength(length, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL pt, BYVAL unitTangentVector)
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYVAL flatteningTolerance AS FLOAT, BYREF pt AS D2D1_POINT_2F) AS D2D1_POINT_2F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM unitTangentVector AS D2D1_POINT_2F
   SetLastError(m_pGeometry->ComputePointAtLength(length, worldTransform, flatteningTolerance, pt, unitTangentVector))
   RETURN unitTangentVector
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL flatteningTolerance AS FLOAT, BYVAL pt AS D2D1_POINT_2F PTR) AS D2D1_POINT_2F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM unitTangentVector AS D2D1_POINT_2F
   SetLastError(m_pGeometry->ComputePointAtLength(length, BYVAL worldTransform, flatteningTolerance, BYVAL pt, unitTangentVector))
   RETURN unitTangentVector
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYREF worldTransform AS const D2D1_MATRIX_3X2_F, _
   BYREF pt AS D2D1_POINT_2F) AS D2D1_POINT_2F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM unitTangentVector AS D2D1_POINT_2F
   SetLastError(m_pGeometry->ComputePointAtLength(length, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, pt, unitTangentVector))
   RETURN unitTangentVector
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.ComputePointAtLength (BYVAL length AS FLOAT, BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, _
   BYVAL pt AS D2D1_POINT_2F PTR) AS D2D1_POINT_2F
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM unitTangentVector AS D2D1_POINT_2F
   SetLastError(m_pGeometry->ComputePointAtLength(length, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL pt, unitTangentVector))
   RETURN unitTangentVector
END FUNCTION
' ========================================================================================

' ========================================================================================
' Widens the geometry by the specified stroke and writes the result to an ID2D1SimplifiedGeometrySink
' after it has been transformed by the specified matrix and flattened using the specified tolerance.
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Widen(strokeWidth, strokeStyle, worldTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
   BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Widen(strokeWidth, strokeStyle, BYVAL worldTransform, flatteningTolerance, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Widen(strokeWidth, strokeStyle, worldTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Widen(strokeWidth, strokeStyle, BYVAL worldTransform, flatteningTolerance, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Widen(strokeWidth, strokeStyle, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL geometrySink AS ID2D1SimplifiedGeometrySink PTR) AS HRESULT
   IF m_pGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pGeometry->Widen(strokeWidth, strokeStyle, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Widen(strokeWidth, strokeStyle, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1Geometry.Widen (BYVAL strokeWidth AS FLOAT, BYVAL strokeStyle AS ID2D1StrokeStyle PTR, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR) AS ID2D1SimplifiedGeometrySink PTR
   IF m_pGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1SimplifiedGeometrySink PTR
   SetLastError(m_pGeometry->Widen(strokeWidth, strokeStyle, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1RectangleGeometry class
' Describes a two-dimensional rectangle.
' ########################################################################################

' ========================================================================================
TYPE CID2D1RectangleGeometry EXTENDS CID2D1Geometry
Public:

   m_pRectangleGeometry AS ID2D1RectangleGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pRectangleGeometry AS ID2D1RectangleGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RectangleGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RectangleGeometry PTR

   DECLARE SUB GetRect (BYREF rc AS D2D1_RECT_F)
   DECLARE SUB GetRect (BYVAL rc AS D2D1_RECT_F PTR)
   DECLARE FUNCTION GetRect () AS D2D1_RECT_F

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RectangleGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RectangleGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Geometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RectangleGeometry (BYVAL pRectangleGeometry AS ID2D1RectangleGeometry PTR)
   D2D1_DP("pRectangleGeometry - " & WSTR(pRectangleGeometry))
   m_pRectangleGeometry = pRectangleGeometry
   IF m_pRectangleGeometry THEN m_pRectangleGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pRectangleGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RectangleGeometry
   D2D1_DP("m_pRectangleGeometry: " & WSTR(m_pRectangleGeometry))
   IF m_pRectangleGeometry THEN m_pRectangleGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1RectangleGeometry) AS ID2D1RectangleGeometry PTR
   RETURN geometry.m_pRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RectangleGeometry.@ () AS ID2D1RectangleGeometry PTR PTR
   RETURN @m_pRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RectangleGeometry.CAST () AS ID2D1RectangleGeometry PTR
   RETURN m_pRectangleGeometry
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the rectangle that describes the rectangle geometry's dimensions.
' ========================================================================================
PRIVATE SUB CID2D1RectangleGeometry.GetRect (BYREF rc AS D2D1_RECT_F)
   IF m_pRectangleGeometry = NULL THEN SetLastError(E_POINTER) : EXIT SUB
   m_pRectangleGeometry->GetRect(rc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RectangleGeometry.GetRect (BYVAL rc AS D2D1_RECT_F PTR)
   IF m_pRectangleGeometry = NULL THEN SetLastError(E_POINTER) : EXIT SUB
   m_pRectangleGeometry->GetRect(BYVAL rc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RectangleGeometry.GetRect () AS D2D1_RECT_F
   IF m_pRectangleGeometry = NULL THEN SetLastError(E_POINTER) : EXIT FUNCTION
   DIM rc AS D2D1_RECT_F
   m_pRectangleGeometry->GetRect(rc)
   RETURN rc
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1RoundedRectangleGeometry class
' Describes a rounded rectangle.
' ########################################################################################

' ========================================================================================
TYPE CID2D1RoundedRectangleGeometry EXTENDS CID2D1Geometry
Public:

   m_pRoundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RoundedRectangleGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RoundedRectangleGeometry PTR

   DECLARE SUB GetRoundedRect (BYREF roundedRect AS D2D1_ROUNDED_RECT)
   DECLARE SUB GetRoundedRect (BYVAL roundedRect AS D2D1_ROUNDED_RECT PTR)
   DECLARE FUNCTION GetRoundedRect () AS D2D1_ROUNDED_RECT

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RoundedRectangleGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RoundedRectangleGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RoundedRectangleGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RoundedRectangleGeometry (BYVAL pRoundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR)
   D2D1_DP("pRoundedRectangleGeometry - " & WSTR(pRoundedRectangleGeometry))
   m_pRoundedRectangleGeometry = pRoundedRectangleGeometry
   IF m_pRoundedRectangleGeometry THEN m_pRoundedRectangleGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pRoundedRectangleGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RoundedRectangleGeometry
   D2D1_DP("m_pRoundedRectangleGeometry: " & WSTR(m_pRoundedRectangleGeometry))
   IF m_pRoundedRectangleGeometry THEN m_pRoundedRectangleGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1RoundedRectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1RoundedRectangleGeometry) AS ID2D1RoundedRectangleGeometry PTR
   RETURN geometry.m_pRoundedRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1RoundedRectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RoundedRectangleGeometry.@ () AS ID2D1RoundedRectangleGeometry PTR PTR
   RETURN @m_pRoundedRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RoundedRectangleGeometry.CAST () AS ID2D1RoundedRectangleGeometry PTR
   RETURN m_pRoundedRectangleGeometry
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the rectangle that describes the rectangle geometry's dimensions.
' ========================================================================================
PRIVATE SUB CID2D1RoundedRectangleGeometry.GetRoundedRect (BYREF roundedRect AS D2D1_ROUNDED_RECT)
   IF m_pRoundedRectangleGeometry = NULL THEN SetLastError(E_POINTER) : EXIT SUB
   m_pRoundedRectangleGeometry->GetRoundedRect(roundedRect)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1RoundedRectangleGeometry.GetRoundedRect (BYVAL roundedRect AS D2D1_ROUNDED_RECT PTR)
   IF m_pRoundedRectangleGeometry = NULL THEN SetLastError(E_POINTER) : EXIT SUB
   m_pRoundedRectangleGeometry->GetRoundedRect(BYVAL roundedRect)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1RoundedRectangleGeometry.GetRoundedRect () AS D2D1_ROUNDED_RECT
   IF m_pRoundedRectangleGeometry = NULL THEN SetLastError(E_POINTER) : EXIT FUNCTION
   DIM roundedRect AS D2D1_ROUNDED_RECT
   m_pRoundedRectangleGeometry->GetRoundedRect(roundedRect)
   RETURN roundedRect
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1EllipseGeometry class
' Represents an ellipse.
' ########################################################################################

' ========================================================================================
TYPE CID2D1EllipseGeometry EXTENDS CID2D1Geometry
Public:

   m_pEllipseGeometry AS ID2D1EllipseGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pEllipseGeometry AS ID2D1EllipseGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1EllipseGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1EllipseGeometry PTR

   DECLARE SUB GetEllipse (BYREF tEllipse AS D2D1_ELLIPSE)
   DECLARE SUB GetEllipse (BYVAL tEllipse AS D2D1_ELLIPSE PTR)
   DECLARE FUNCTION GetEllipse () AS D2D1_ELLIPSE

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1EllipseGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1EllipseGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1EllipseGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1EllipseGeometry (BYVAL pEllipseGeometry AS ID2D1EllipseGeometry PTR)
   D2D1_DP("pEllipseGeometry - " & WSTR(pEllipseGeometry))
   m_pEllipseGeometry = pEllipseGeometry
   IF m_pEllipseGeometry THEN m_pEllipseGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pEllipseGeometry
   IF m_pEllipseGeometry = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1EllipseGeometry
   D2D1_DP("m_pEllipseGeometry: " & WSTR(m_pEllipseGeometry))
   IF m_pEllipseGeometry THEN m_pEllipseGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1EllipseGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1EllipseGeometry) AS ID2D1EllipseGeometry PTR
   RETURN geometry.m_pEllipseGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1EllipseGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1EllipseGeometry.@ () AS ID2D1EllipseGeometry PTR PTR
   RETURN @m_pEllipseGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1EllipseGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1EllipseGeometry.CAST () AS ID2D1EllipseGeometry PTR
   RETURN m_pEllipseGeometry
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the rectangle that describes the rectangle geometry's dimensions.
' ========================================================================================
PRIVATE SUB CID2D1EllipseGeometry.GetEllipse (BYREF tEllipse AS D2D1_ELLIPSE)
   IF m_pEllipseGeometry = NULL THEN SetLastError(E_POINTER) : EXIT SUB
   m_pEllipseGeometry->GetEllipse(tEllipse)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1EllipseGeometry.GetEllipse (BYVAL tEllipse AS D2D1_ELLIPSE PTR)
   IF m_pEllipseGeometry = NULL THEN SetLastError(E_POINTER) : EXIT SUB
   m_pEllipseGeometry->GetEllipse(BYVAL tEllipse)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1EllipseGeometry.GetEllipse () AS D2D1_ELLIPSE
   IF m_pEllipseGeometry = NULL THEN SetLastError(E_POINTER) : EXIT FUNCTION
   DIM tEllipse AS D2D1_ELLIPSE
   m_pEllipseGeometry->GetEllipse(tEllipse)
   RETURN tEllipse
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1GeometryGroup class
' Represents a composite geometry, composed of other ID2D1Geometry objects.
' ########################################################################################

' ========================================================================================
TYPE CID2D1GeometryGroup EXTENDS CID2D1Geometry
Public:

   m_pGeometryGroup AS ID2D1GeometryGroup PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pEllipseGeometry AS ID2D1GeometryGroup PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GeometryGroup PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GeometryGroup PTR

   DECLARE FUNCTION GetFillMode () AS D2D1_FILL_MODE
   DECLARE FUNCTION GetSourceGeometryCount () AS UINT32
   DECLARE FUNCTION GetSourceGeometries (BYREF geometries AS ID2D1Geometry PTR, BYVAL geometriesCount AS UINT32) AS HRESULT
   DECLARE FUNCTION GetSourceGeometries (BYVAL geometries AS ID2D1Geometry PTR PTR, BYVAL geometriesCount AS UINT32) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometryGroup class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometryGroup
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometryGroup class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometryGroup (BYVAL pGeometryGroup AS ID2D1GeometryGroup PTR)
   D2D1_DP("pGeometryGroup - " & WSTR(pGeometryGroup))
   m_pGeometryGroup = pGeometryGroup
   IF m_pGeometryGroup THEN m_pGeometryGroup->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pGeometryGroup
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GeometryGroup
   D2D1_DP("m_pGeometryGroup: " & WSTR(m_pGeometryGroup))
   IF m_pGeometryGroup THEN m_pGeometryGroup->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GeometryGroup interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1GeometryGroup) AS ID2D1GeometryGroup PTR
   RETURN geometry.m_pGeometryGroup
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GeometryGroup interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometryGroup.@ () AS ID2D1GeometryGroup PTR PTR
   RETURN @m_pGeometryGroup
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GeometryGroup interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometryGroup.CAST () AS ID2D1GeometryGroup PTR
   RETURN m_pGeometryGroup
END OPERATOR
' ========================================================================================

' ========================================================================================
' Indicates how the intersecting areas of the geometries contained in this geometry group are combined.
' ========================================================================================
PRIVATE FUNCTION CID2D1GeometryGroup.GetFillMode () AS D2D1_FILL_MODE
   IF m_pGeometryGroup = NULL THEN EXIT FUNCTION
   RETURN m_pGeometryGroup->GetFillMode
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates the number of geometry objects in the geometry group.
' ========================================================================================
PRIVATE FUNCTION CID2D1GeometryGroup.GetSourceGeometryCount () AS UINT32
   IF m_pGeometryGroup = NULL THEN EXIT FUNCTION
   RETURN m_pGeometryGroup->GetSourceGeometryCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the geometries in the geometry group.
' ========================================================================================
PRIVATE FUNCTION CID2D1GeometryGroup.GetSourceGeometries (BYREF geometries AS ID2D1Geometry PTR, BYVAL geometriesCount AS UINT32) AS HRESULT
   IF m_pGeometryGroup = NULL THEN EXIT FUNCTION
   RETURN m_pGeometryGroup->GetSourceGeometries(geometries, geometriesCount)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1GeometryGroup.GetSourceGeometries (BYVAL geometries AS ID2D1Geometry PTR PTR, BYVAL geometriesCount AS UINT32) AS HRESULT
   IF m_pGeometryGroup = NULL THEN EXIT FUNCTION
   RETURN m_pGeometryGroup->GetSourceGeometries(BYVAL geometries, geometriesCount)
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1TransformedGeometry class
' Represents a composite geometry, composed of other ID2D1Geometry objects.
' ########################################################################################

' ========================================================================================
TYPE CID2D1TransformedGeometry EXTENDS CID2D1Geometry
Public:

   m_pTransformedGeometry AS ID2D1TransformedGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pTransformedGeometry AS ID2D1TransformedGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1TransformedGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1TransformedGeometry PTR

   DECLARE SUB GetSourceGeometry (BYREF sourceGeometry AS ID2D1Geometry PTR)
   DECLARE SUB GetSourceGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR PTR)
   DECLARE FUNCTION GetSourceGeometry () AS ID2D1Geometry PTR
   DECLARE SUB GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   DECLARE SUB GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   DECLARE FUNCTION GetTransform () AS D2D1_MATRIX_3X2_F

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1TransformedGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1TransformedGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1TransformedGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1TransformedGeometry (BYVAL pTransformedGeometry AS ID2D1TransformedGeometry PTR)
   D2D1_DP("pTransformedGeometry - " & WSTR(pTransformedGeometry))
   m_pTransformedGeometry = pTransformedGeometry
   IF m_pTransformedGeometry THEN m_pTransformedGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pTransformedGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1TransformedGeometry
   D2D1_DP("m_pTransformedGeometry: " & WSTR(m_pTransformedGeometry))
   IF m_pTransformedGeometry THEN m_pTransformedGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1TransformedGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1TransformedGeometry) AS ID2D1TransformedGeometry PTR
   RETURN geometry.m_pTransformedGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1TransformedGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1TransformedGeometry.@ () AS ID2D1TransformedGeometry PTR PTR
   RETURN @m_pTransformedGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1TransformedGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1TransformedGeometry.CAST () AS ID2D1TransformedGeometry PTR
   RETURN m_pTransformedGeometry
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the geometries in the geometry group.
' ========================================================================================
PRIVATE SUB CID2D1TransformedGeometry.GetSourceGeometry (BYREF sourceGeometry AS ID2D1Geometry PTR)
   IF m_pTransformedGeometry = NULL THEN EXIT SUB
   m_pTransformedGeometry->GetSourceGeometry(sourceGeometry)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1TransformedGeometry.GetSourceGeometry (BYVAL sourceGeometry AS ID2D1Geometry PTR PTR)
   IF m_pTransformedGeometry = NULL THEN EXIT SUB
   m_pTransformedGeometry->GetSourceGeometry(BYVAL sourceGeometry)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1TransformedGeometry.GetSourceGeometry () AS ID2D1Geometry PTR
   IF m_pTransformedGeometry = NULL THEN EXIT FUNCTION
   DIM sourceGeometry AS ID2D1Geometry PTR
   m_pTransformedGeometry->GetSourceGeometry(sourceGeometry)
   RETURN sourceGeometry
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1TransformedGeometry.GetTransform (BYREF transform AS D2D1_MATRIX_3X2_F)
   IF m_pTransformedGeometry = NULL THEN EXIT SUB
   m_pTransformedGeometry->GetTransform(transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1TransformedGeometry.GetTransform (BYVAL transform AS D2D1_MATRIX_3X2_F PTR)
   IF m_pTransformedGeometry = NULL THEN EXIT SUB
   m_pTransformedGeometry->GetTransform(BYVAL transform)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1TransformedGeometry.GetTransform () AS D2D1_MATRIX_3X2_F
   IF m_pTransformedGeometry = NULL THEN EXIT FUNCTION
   DIM transform AS D2D1_MATRIX_3X2_F
   m_pTransformedGeometry->GetTransform(transform)
   RETURN transform
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1PathGeometry class
' Represents a complex shape that may be composed of arcs, curves, and lines.
' ########################################################################################

' ========================================================================================
TYPE CID2D1PathGeometry EXTENDS CID2D1Geometry
Public:

   m_pPathGeometry AS ID2D1PathGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pPathGeometry AS ID2D1PathGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1PathGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1PathGeometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Geometry PTR

   DECLARE FUNCTION Open (BYREF geometrySink AS ID2D1GeometrySink PTR) AS HRESULT
   DECLARE FUNCTION Open () AS ID2D1GeometrySink PTR
   DECLARE FUNCTION Stream (BYVAL geometrySink AS ID2D1GeometrySink PTR) AS HRESULT
   DECLARE FUNCTION GetSegmentCount () AS UINT32
   DECLARE FUNCTION GetFigureCount () AS UINT32

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry (BYVAL pPathGeometry AS ID2D1PathGeometry PTR)
   D2D1_DP("pPathGeometry - " & WSTR(pPathGeometry))
   m_pPathGeometry = pPathGeometry
   IF m_pPathGeometry THEN m_pPathGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pPathGeometry
   IF m_pPathGeometry = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1PathGeometry
   D2D1_DP("m_pPathGeometry: " & WSTR(m_pPathGeometry))
   IF m_pPathGeometry THEN m_pPathGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1PathGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1PathGeometry) AS ID2D1PathGeometry PTR
   RETURN geometry.m_pPathGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1PathGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.@ () AS ID2D1PathGeometry PTR PTR
   RETURN @m_pPathGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1PathGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.CAST () AS ID2D1PathGeometry PTR
   RETURN m_pPathGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.CAST () AS ID2D1Geometry PTR
   RETURN cast(ID2D1Geometry PTR, m_pPathGeometry)
END OPERATOR
' ========================================================================================

' ========================================================================================
' Retrieves the geometry sink that is used to populate the path geometry with figures and segments.
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry.Open (BYREF geometrySink AS ID2D1GeometrySink PTR) AS HRESULT
   IF m_pPathGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pPathGeometry->Open(geometrySink)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry.Open () AS ID2D1GeometrySink PTR
   IF m_pPathGeometry = NULL THEN EXIT FUNCTION
   DIM geometrySink AS ID2D1GeometrySink PTR
   SetLastError(m_pPathGeometry->Open(geometrySink))
   RETURN geometrySink
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies the contents of the path geometry to the specified ID2D1GeometrySink.
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry.Stream (BYVAL geometrySink AS ID2D1GeometrySink PTR) AS HRESULT
   IF m_pPathGeometry = NULL THEN RETURN E_POINTER
   RETURN m_pPathGeometry->Stream(geometrySink)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of segments in the path geometry.
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry.GetSegmentCount () AS UINT32
   IF m_pPathGeometry = NULL THEN  EXIT FUNCTION
   DIM count AS UINT32
   SetLastError(m_pPathGeometry->GetSegmentCount(count))
   RETURN count
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of figures in the path geometry.
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry.GetFigureCount () AS UINT32
   IF m_pPathGeometry = NULL THEN  EXIT FUNCTION
   DIM count AS UINT32
   SetLastError(m_pPathGeometry->GetFigureCount(count))
   RETURN count
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1PathGeometry1 class
' adds functionality to ID2D1PathGeometry.
' ########################################################################################

' ========================================================================================
TYPE CID2D1PathGeometry1 EXTENDS CID2D1PathGeometry
Public:

   m_pPathGeometry1 AS ID2D1PathGeometry1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pPathGeometry1 AS ID2D1PathGeometry1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1PathGeometry1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1PathGeometry1 PTR

   DECLARE FUNCTION ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
      BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
      BYREF pointDescription AS D2D1_POINT_DESCRIPTION) AS HRESULT
   DECLARE FUNCTION ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
      BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
      BYVAL pointDescription AS D2D1_POINT_DESCRIPTION PTR) AS HRESULT
   DECLARE FUNCTION ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
      BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF pointDescription AS D2D1_POINT_DESCRIPTION) AS HRESULT
   DECLARE FUNCTION ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
      BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL pointDescription AS D2D1_POINT_DESCRIPTION PTR) AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry1
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry1 (BYVAL pPathGeometry1 AS ID2D1PathGeometry1 PTR)
   D2D1_DP("pPathGeometry1 - " & WSTR(pPathGeometry1))
   m_pPathGeometry1 = pPathGeometry1
   IF m_pPathGeometry1 THEN m_pPathGeometry1->AddRef
   IF m_pPathGeometry THEN
      m_pPathGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pPathGeometry))
   END iF
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pPathGeometry = m_pPathGeometry1
   m_pGeometry = m_pPathGeometry1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1PathGeometry1
   D2D1_DP("m_pPathGeometry1: " & WSTR(m_pPathGeometry1))
   IF m_pPathGeometry1 THEN m_pPathGeometry1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1PathGeometry1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1PathGeometry1) AS ID2D1PathGeometry1 PTR
   RETURN geometry.m_pPathGeometry1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1PathGeometry1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry1.@ () AS ID2D1PathGeometry1 PTR PTR
   RETURN @m_pPathGeometry1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1PathGeometry1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry1.CAST () AS ID2D1PathGeometry1 PTR
   RETURN m_pPathGeometry1
END OPERATOR
' ========================================================================================

' ========================================================================================
' Computes the point that exists at a given distance along the path geometry along with the
' index of the segment the point is on and the directional vector at that point.
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry1.ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYVAL flatteningTolerance AS FLOAT, _
   BYREF pointDescription AS D2D1_POINT_DESCRIPTION) AS HRESULT
   IF m_pPathGeometry1 = NULL THEN RETURN E_POINTER
   RETURN m_pPathGeometry1->ComputePointAndSegmentAtLength(length, startSegment, worldTransform, flatteningTolerance, pointDescription)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIvaTE FUNCTION CID2D1PathGeometry1.ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL flatteningTolerance AS FLOAT, _
   BYVAL pointDescription AS D2D1_POINT_DESCRIPTION PTR) AS HRESULT
   IF m_pPathGeometry1 = NULL THEN RETURN E_POINTER
   RETURN m_pPathGeometry1->ComputePointAndSegmentAtLength(length, startSegment, BYVAL worldTransform, flatteningTolerance, BYVAL pointDescription)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CID2D1PathGeometry1.ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
   BYREF worldTransform AS const D2D1_MATRIX_3X2_F, BYREF pointDescription AS D2D1_POINT_DESCRIPTION) AS HRESULT
   IF m_pPathGeometry1 = NULL THEN RETURN E_POINTER
   RETURN m_pPathGeometry1->ComputePointAndSegmentAtLength(length, startSegment, worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, pointDescription)
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIvATE FUNCTION CID2D1PathGeometry1.ComputePointAndSegmentAtLength (BYVAL length AS FLOAT, BYVAL startSegment AS UINT32, _
   BYVAL worldTransform AS const D2D1_MATRIX_3X2_F PTR, BYVAL pointDescription AS D2D1_POINT_DESCRIPTION PTR) AS HRESULT
   IF m_pPathGeometry1 = NULL THEN RETURN E_POINTER
   RETURN m_pPathGeometry1->ComputePointAndSegmentAtLength(length, startSegment, BYVAL worldTransform, D2D1_DEFAULT_FLATTENING_TOLERANCE, BYVAL pointDescription)
END FUNCTION
' ========================================================================================

' ########################################################################################
' CID2D1SimplifiedGeometrySink class
' Inherited interface = IUnknown
' ########################################################################################
TYPE CID2D1SimplifiedGeometrySink

Public:

   m_pSimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pSimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1SimplifiedGeometrySink PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1SimplifiedGeometrySink PTR

   ' // ID2D1SimplifiedGeometrySink methods
   DECLARE SUB SetFillMode (BYVAL fillMode AS D2D1_FILL_MODE)
   DECLARE SUB SetSegmentFlags (BYVAL vertexFlags AS D2D1_PATH_SEGMENT)
   DECLARE SUB BeginFigure (BYVAL startPoint AS D2D1_POINT_2F, BYVAL figureBegin AS D2D1_FIGURE_BEGIN)
   DECLARE SUB BeginFigure (BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL figureBegin AS D2D1_FIGURE_BEGIN)
   DECLARE SUB AddLines (BYREF points AS D2D1_POINT_2F, BYVAL pointsCount AS UINT32)
   DECLARE SUB AddLines (BYVAL points AS D2D1_POINT_2F PTR, BYVAL pointsCount AS UINT32)
   DECLARE SUB AddBeziers (BYREF beziers AS const D2D1_BEZIER_SEGMENT, BYVAL beziersCount AS UINT32)
   DECLARE SUB AddBeziers (BYVAL beziers AS const D2D1_BEZIER_SEGMENT PTR, BYVAL beziersCount AS UINT32)
   DECLARE SUB EndFigure (BYVAL figureEnd AS D2D1_FIGURE_END)
   DECLARE FUNCTION Close () AS HRESULT

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SimplifiedGeometrySink
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1SimplifiedGeometrySink class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SimplifiedGeometrySink (BYVAL pSimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink PTR)
   D2D1_DP("pSimplifiedGeometrySink - " & WSTR(pSimplifiedGeometrySink))
   m_pSimplifiedGeometrySink = pSimplifiedGeometrySink
   IF m_pSimplifiedGeometrySink = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1SimplifiedGeometrySink
   D2D1_DP("m_pSimplifiedGeometrySink: " & WSTR(m_pSimplifiedGeometrySink))
   IF m_pSimplifiedGeometrySink THEN m_pSimplifiedGeometrySink->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1SimplifiedGeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1SimplifiedGeometrySink) AS ID2D1SimplifiedGeometrySink PTR
   RETURN geometry.m_pSimplifiedGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1SimplifiedGeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SimplifiedGeometrySink.@ () AS ID2D1SimplifiedGeometrySink PTR PTR
   RETURN @m_pSimplifiedGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying CID2D1SimplifiedGeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SimplifiedGeometrySink.CAST () AS ID2D1SimplifiedGeometrySink PTR
   RETURN m_pSimplifiedGeometrySink
END OPERATOR
' ========================================================================================

' ========================================================================================
' Specifies the method used to determine which points are inside the geometry described by
' this geometry sink and which points are outside.
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.SetFillMode (BYVAL fillMode AS D2D1_FILL_MODE)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->SetFillMode(fillMode)
END SUB
' ========================================================================================

' ========================================================================================
' Specifies stroke and join options to be applied to new segments added to the geometry sink.
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.SetSegmentFlags (BYVAL vertexFlags AS D2D1_PATH_SEGMENT)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->SetSegmentFlags(vertexFlags)
END SUB
' ========================================================================================

' ========================================================================================
' Starts a new figure at the specified point.
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.BeginFigure (BYVAL startPoint AS D2D1_POINT_2F, BYVAL figureBegin AS D2D1_FIGURE_BEGIN)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->BeginFigure(startPoint, figureBegin)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.BeginFigure (BYVAL startPointX AS SINGLE, BYVAL startPointY AS SINGLE, BYVAL figureBegin AS D2D1_FIGURE_BEGIN)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   DIM startPoint AS D2D1_POINT_2F = (startPointX, startPointY)
   m_pSimplifiedGeometrySink->BeginFigure(startPoint, figureBegin)
END SUB
' ========================================================================================

' ========================================================================================
' Creates a sequence of lines using the specified points and adds them to the geometry sink.
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.AddLines (BYREF points AS D2D1_POINT_2F, BYVAL pointsCount AS UINT32)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->AddLines(points, pointsCount)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.AddLines (BYVAL points AS D2D1_POINT_2F PTR, BYVAL pointsCount AS UINT32)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->AddLines(BYVAL points, pointsCount)
END SUB
' ========================================================================================

' ========================================================================================
' Creates a sequence of cubic Bezier curves and adds them to the geometry sink.
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.AddBeziers (BYREF beziers AS const D2D1_BEZIER_SEGMENT, BYVAL beziersCount AS UINT32)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->AddBeziers(beziers, beziersCount)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.AddBeziers (BYVAL beziers AS const D2D1_BEZIER_SEGMENT PTR, BYVAL beziersCount AS UINT32)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->AddBeziers(BYVAL beziers, beziersCount)
END SUB
' ========================================================================================

' ========================================================================================
' Ends the current figure; optionally, closes it.
' ========================================================================================
PRIVATE SUB CID2D1SimplifiedGeometrySink.EndFigure (BYVAL figureEnd AS D2D1_FIGURE_END)
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT SUB
   m_pSimplifiedGeometrySink->EndFigure(figureEnd)
END SUB
' ========================================================================================

' ========================================================================================
' Closes the geometry sink, indicates whether it is in an error state, and resets the sink's error state.
' ========================================================================================
PRIVATE FUNCTION CID2D1SimplifiedGeometrySink.Close () AS HRESULT
   D2D1_DP("")
   IF m_pSimplifiedGeometrySink = NULL THEN EXIT FUNCTION
   RETURN m_pSimplifiedGeometrySink->Close
END FUNCTION
' ========================================================================================


' ########################################################################################
' CID2D1GeometrySink class
' Inherited interface = ID2D1SimplifiedGeometrySink
' ########################################################################################
TYPE CID2D1GeometrySink EXTENDS CID2D1SimplifiedGeometrySink

Public:

   m_pGeometrySink AS ID2D1GeometrySink PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGeometrySink AS ID2D1GeometrySink PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GeometrySink PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GeometrySink PTR

   ' // ID2D1GeometrySink methods
   DECLARE SUB AddLine (BYVAL pt AS D2D1_POINT_2F)
   DECLARE SUB AddLine (BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE)
   DECLARE SUB AddBezier (BYREF bezier AS D2D1_BEZIER_SEGMENT)
   DECLARE SUB AddBezier (BYVAL bezier AS D2D1_BEZIER_SEGMENT PTR)
   DECLARE SUB AddBezier (BYVAL pt1X AS SINGLE, BYVAL pt1Y AS SINGLE, BYVAL pt2X AS SINGLE, _
           BYVAL pt2Y AS SINGLE, BYVAL pt3X AS SINGLE, BYVAL pt3Y AS SINGLE)
   DECLARE SUB AddQuadraticBezier (BYREF bezier AS D2D1_QUADRATIC_BEZIER_SEGMENT)
   DECLARE SUB AddQuadraticBezier (BYVAL bezier AS D2D1_QUADRATIC_BEZIER_SEGMENT PTR)
   DECLARE SUB AddQuadraticBezier (BYVAL pt1X AS SINGLE, BYVAL pt1Y AS SINGLE, BYVAL pt2X AS SINGLE, BYVAL pt2Y AS SINGLE)
   DECLARE SUB AddQuadraticBeziers (BYREF beziers AS D2D1_QUADRATIC_BEZIER_SEGMENT, BYVAL beziersCount AS UINT32)
   DECLARE SUB AddQuadraticBeziers (BYVAL beziers AS D2D1_QUADRATIC_BEZIER_SEGMENT PTR, BYVAL beziersCount AS UINT32)
   DECLARE SUB AddArc (BYREF arc AS D2D1_ARC_SEGMENT)
   DECLARE SUB AddArc (BYVAL arc AS D2D1_ARC_SEGMENT PTR)
   DECLARE SUB AddArc (BYVAL ptX AS SINGLE, BYVAL ptY AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight aS SINGLE, _
           BYVAL rotationAngle AS SINGLE, BYVAL sweepDirection AS D2D1_SWEEP_DIRECTION, BYVAL arcSize AS D2D1_ARC_SIZE)

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometrySink class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometrySink
   D2D1_DP("Default constructor - m_pGeometrySink = " & WSTR(m_pGeometrySink))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometrySink class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometrySink (BYVAL pGeometrySink AS ID2D1GeometrySink PTR)
   D2D1_DP("pGeometrySink - " & WSTR(pGeometrySink))
   m_pGeometrySink = pGeometrySink
   IF m_pGeometrySink THEN m_pGeometrySink->AddRef
   IF m_pSimplifiedGeometrySink THEN
      m_pSimplifiedGeometrySink->Release
      D2D1_DP("Release old factory: " & WSTR(m_pSimplifiedGeometrySink))
   END iF
   m_pSimplifiedGeometrySink = m_pGeometrySink
   IF m_pGeometrySink = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GeometrySink
   D2D1_DP("m_pGeometrySink: " & WSTR(m_pGeometrySink))
   IF m_pGeometrySink THEN m_pGeometrySink->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1GeometrySink) AS ID2D1GeometrySink PTR
   RETURN geometry.m_pGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometrySink.@ () AS ID2D1GeometrySink PTR PTR
   RETURN @m_pGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometrySink.CAST () AS ID2D1GeometrySink PTR
   RETURN m_pGeometrySink
END OPERATOR
' ========================================================================================

' ========================================================================================
' Creates a line segment between the current point and the specified end point and adds it to the geometry sink.
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddLine (BYVAL pt AS D2D1_POINT_2F)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddLine(pt)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddLine (BYVAL endPointX AS SINGLE, BYVAL endPointY AS SINGLE)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   DIM pt AS D2D1_POINT_2F = (endPointX, endPointY)
   m_pGeometrySink->AddLine(pt)
END SUB
' ========================================================================================

' ========================================================================================
' Creates a cubic Bezier curve between the current point and the specified end point.
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddBezier (BYREF bezier AS D2D1_BEZIER_SEGMENT)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddBezier(bezier)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddBezier (BYVAL bezier AS D2D1_BEZIER_SEGMENT PTR)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddBezier(BYVAL bezier)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddBezier (BYVAL pt1X AS SINGLE, BYVAL pt1Y AS SINGLE, BYVAL pt2X AS SINGLE, _
   BYVAL pt2Y AS SINGLE, BYVAL pt3X AS SINGLE, BYVAL pt3Y AS SINGLE)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   DIM pt1 AS D2D1_POINT_2F = (pt1X, pt1Y)
   DIM pt2 AS D2D1_POINT_2F = (pt2X, pt2Y)
   DIM pt3 AS D2D1_POINT_2F = (pt3X, pt3Y)
   DIM segment AS D2D1_BEZIER_SEGMENT
   segment.point1 = pt1
   segment.point2 = pt2
   segment.point3 = pt3
   m_pGeometrySink->AddBezier(segment)
END SUB
' ========================================================================================

' ========================================================================================
' Creates a quadratic Bezier curve between the current point and the specified end point.
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddQuadraticBezier (BYREF bezier AS D2D1_QUADRATIC_BEZIER_SEGMENT)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddQuadraticBezier(bezier)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddQuadraticBezier (BYVAL bezier AS D2D1_QUADRATIC_BEZIER_SEGMENT PTR)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddQuadraticBezier(BYVAL bezier)
END SUB
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddQuadraticBezier (BYVAL pt1X AS SINGLE, BYVAL pt1Y AS SINGLE, BYVAL pt2X AS SINGLE, BYVAL pt2Y AS SINGLE)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   DIM point1 AS D2D1_POINT_2F = (pt1X, pt1Y)
   DIM point2 AS D2D1_POINT_2F = (pt2X, pt2Y)
   DIM segment AS D2D1_QUADRATIC_BEZIER_SEGMENT
   segment.point1 = point1
   segment.point2 = point2
   m_pGeometrySink->AddQuadraticBezier(segment)
END SUB
' ========================================================================================
   DECLARE SUB AddQuadraticBezier (BYVAL pt1X AS SINGLE, BYVAL pt1Y AS SINGLE, BYVAL pt2X AS SINGLE, BYVAL pt2Y AS SINGLE)

' ========================================================================================
' Adds a sequence of quadratic Bezier segments as an array in a single call.
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddQuadraticBeziers (BYREF beziers AS D2D1_QUADRATIC_BEZIER_SEGMENT, BYVAL beziersCount AS UINT32)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddQuadraticBeziers(beziers, beziersCount)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddQuadraticBeziers (BYVAL beziers AS D2D1_QUADRATIC_BEZIER_SEGMENT PTR, BYVAL beziersCount AS UINT32)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddQuadraticBeziers(BYVAL beziers, beziersCount)
END SUB
' ========================================================================================

' ========================================================================================
' Adds a single arc to the path geometry.
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddArc (BYREF arc AS D2D1_ARC_SEGMENT)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddArc(arc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddArc (BYVAL arc AS D2D1_ARC_SEGMENT PTR)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   m_pGeometrySink->AddArc(BYVAL arc)
END SUB
' ========================================================================================
' ========================================================================================
PRIVATE SUB CID2D1GeometrySink.AddArc (BYVAL ptX AS SINGLE, BYVAL ptY AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight aS SINGLE, _
   BYVAL rotationAngle AS SINGLE, BYVAL sweepDirection AS D2D1_SWEEP_DIRECTION, BYVAL arcSize AS D2D1_ARC_SIZE)
   D2D1_DP("")
   IF m_pGeometrySink = NULL THEN EXIT SUB
   DIM pt AS D2D1_POINT_2F = (ptX, ptY)
   DIM size AS D2D1_SIZE_F = (nWidth, nHeight)
   DIM segment AS D2D1_ARC_SEGMENT
   segment.point = pt
   segment.size = size
   segment.rotationAngle = rotationAngle
   segment.sweepDirection = sweepDirection
   segment.arcSize = arcSize
   m_pGeometrySink->AddArc(segment)
END SUB
' ========================================================================================
