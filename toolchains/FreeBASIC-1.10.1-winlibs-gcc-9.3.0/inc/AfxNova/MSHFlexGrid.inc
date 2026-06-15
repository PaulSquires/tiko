' ########################################################################################
' Microsoft Windows
' File: MSHFlxgd.inc
' Copyright (c) 2026 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSHierarchicalFlexGridLib
' Documentation string: Microsoft Hierarchical FlexGrid Control 6.0 (OLEDB)
' GUID: {0ECD9B60-23AA-11D0-B351-00A0C9055D8E}
' Version: 6.0, Locale ID = 0
' Attributes: 10 [&h0000000A]  [Control] [HasDiskImage]
' Help file: C:\WINDOWS\HELP\MSHFlx98.chm
' License key: 1F3D5522-3F42-11d1-B2FA-00A0C908FB55
' ########################################################################################

#pragma once
#include once "windows.bi"
#include once "AfxNova/AfxAdo.bi"
#include once "AfxNova/RGB_Colors.bi"
#include once "AfxNova/RGB_Colors.bi"
#include once "vbCompat.bi"
USING AfxNova

NAMESPACE AfxNova

' ========================================================================================
' Macro for debug
' To allow debugging, define _CMSHGRID_DEBUG_ 1 in your application before including this file.
' ========================================================================================
#ifndef _CMSHGRID_DEBUG_
   #define _CMSHGRID_DEBUG_ 0
#ENDIF
#ifndef _CMSHGRID_DP_
   #define _CMSHGRID_DP_ 1
   #MACRO CMSHGRID_DP(st)
      #IF (_CMSHGRID_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

' ========================================================================================
' Macro for debug
' To allow debugging, define _CMSHGRIDEVT_DEBUG_ 1 in your application before including this file.
' ========================================================================================
#ifndef _CMSHGRIDEVT_DEBUG_
   #define _CMSHGRIDEVT_DEBUG_ 0
#ENDIF
#ifndef _CMSHGRIDEVT_DP_
   #define _CMSHGRIDEVT_DP_ 1
   #MACRO CMSHGRIDEVT_DP(st)
      #IF (_CMSHGRIDEVT_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

' ========================================================================================
' License key
' ========================================================================================

CONST RTLKEY_MSHFlexGrid = "1F3D5522-3F42-11d1-B2FA-00A0C908FB55"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

CONST PROGID_MSHFlexGrid6 = "MSHierarchicalFlexGridLib.MSHFlexGrid.6"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

'CLSID_MSHFlexGrid = GUID$("{0ECD9B64-23AA-11D0-B351-00A0C9055D8E}")

'DIM SHARED AFX_CLSID_DataObject AS GUID = (&h2334D2B2, &h713E, &h11CF, {&h8A, &hE5, &h00, &hAA, &h00, &hC0, &h09, &h05})
'DIM SHARED AFX_CLSID_DataObjectFiles AS GUID = (&h2334D2B4, &h713E, &h11CF, {&h8A, &hE5, &h00, &hAA, &h00, &hC0, &h09, &h05})
DIM SHARED AFX_CLSID_MSHFlexGrid AS GUID = (&h0ECD9B64, &h23AA, &h11D0, {&hB3, &h51, &h00, &hA0, &hC9, &h05, &h5D, &h8E})

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

'IID_IMSHFlexGrid = GUID$("{0ECD9B62-23AA-11D0-B351-00A0C9055D8E}")
'IID_DMSHFlexGridEvents = GUID$("{0ECD9B63-23AA-11D0-B351-00A0C9055D8E}")

DIM SHARED AFX_IID_DMSHFlexGridEvents AS GUID = (&h0ECD9B63, &h23AA, &h11D0, {&hB3, &h51, &h00, &hA0, &hC9, &h05, &h5D, &h8E})
DIM SHARED AFX_IID_IMSHFlexGrid AS GUID = (&h0ECD9B62, &h23AA, &h11D0, {&hB3, &h51, &h00, &hA0, &hC9, &h05, &h5D, &h8E})
'DIM SHARED AFX_IID_IRecordset AS GUID = (&h0000050E, &h0000, &h0010, {&h80, &h00, &h00, &hAA, &h00, &h6D, &h2E, &hA4})
DIM SHARED AFX_IID_IVBDataObject AS GUID = (&h2334D2B1, &h713E, &h11CF, {&h8A, &hE5, &h00, &hAA, &h00, &hC0, &h09, &h05})
DIM SHARED AFX_IID_IVBDataObjectFiles AS GUID = (&h2334D2B3, &h713E, &h11CF, {&h8A, &hE5, &h00, &hAA, &h00, &hC0, &h09, &h05})
DIM SHARED AFX_IID_Afx_IDataSource AS GUID = (&hCD000029, &h8B95, &h11D1, {&h82, &hDB, &h00, &hC0, &h4F, &hB1, &h62, &h5D})
'CONST AFX_IID_Afx_IDataSource = "{CD000029-8B95-11D1-82DB-00C04FB1625D}"

' ========================================================================================
' Enumerations
' ========================================================================================

' // Alignment Constants.
ENUM AlignmentSettings
   flexAlignLeftTop = 0
   flexAlignLeftCenter = 1
   flexAlignLeftBottom = 2
   flexAlignCenterTop = 3
   flexAlignCenterCenter = 4
   flexAlignCenterBottom = 5
   flexAlignRightTop = 6
   flexAlignRightCenter = 7
   flexAlignRightBottom = 8
   flexAlignGeneral = 9
END ENUM

' // AllowUserResizing Constants
ENUM AllowUserResizeSettings
   flexResizeNone = 0
   flexResizeColumns = 1
   flexResizeRows = 2
   flexResizeBoth = 3
END ENUM

' // Appearance Constants
ENUM AppearanceSettings
   flexFlat = 0
   flex3D = 1
END ENUM

' // Band Display Constants
ENUM BandDisplaySettings
   flexBandDisplayHorizontal = 0
   flexBandDisplayVertical = 1
END ENUM

' // BorderStyle Constants
ENUM BorderStyleSettings
   flexBorderNone = 0
   flexBorderSingle = 1
END ENUM

' // Cell Type Constants
ENUM CellTypeSettings
   flexCellTypeStandard = 0
   flexCellTypeFixed = 1
   flexCellTypeHeader = 2
   flexCellTypeIndent = 3
   flexCellTypeUnpopulated = 4
END ENUM

' // Clipboard format constants.
' // IID: {D8898462-742F-11CF-8AEA-00AA00C00905}
ENUM ClipBoardConstants
   flexCFText = 1   ' CF_TEXT (ANSI text)
   flexCFBitmap = 2   ' CF_BITMAP
   flexCFMetafile = 3   ' CF_METAFILEPICT
   flexCFDIB = 8   ' CF_DIB (Device Independent Bitmap)
   flexCFPalette = 9   ' CF_PALETTE
   flexCFEMetafile = 14   ' CF_ENHMETAFILE
   flexCFFiles = 15   ' CF_HDROP (file drop list)
   flexCFRTF = &hFFFFBF01   ' Custom VB6 runtime RTF clipboard format
END ENUM

' // ColHeader Constants
ENUM ColHeaderSettings
   flexColHeaderOff = 0
   flexColHeaderOn = 1
END ENUM

' State transition constants for the DragOver and OLEDragOver events.
' // IID: {D8898464-742F-11CF-8AEA-00AA00C00905}
ENUM DragOverConstants
   flexEnter = 0
   flexLeave = 1
   flexOver = 2
END ENUM

' // Error constants
ENUM ErrorConstants
   flexerrIllegaFunctionCall = 5   ' (&h00000005)
   flexerrObjIllegalUse = 425   ' (&h000001A9)
   flexerrClipInvalidFormat = 461   ' (&h000001CD)
   flexerrDataObjectLocked = 672   ' (&h000002A0)
   flexerrExpectedAnArgument = 673   ' (&h000002A1)
   flexerrRecursiveOLEDrag = 674   ' (&h000002A2)
   flexerrUserFormatNotBinArray = 675   ' (&h000002A3)
   flexerrDataNotSetForFormat = 676   ' (&h000002A4)
   flexerrUnknownError = 600   ' (&h00000258)
   flexerrSubscript = 381   ' (&h0000017D)
   flexerrBadValue = 380   ' (&h0000017C)
   flexerrGetNotSupported = 394   ' (&h0000018A)
   flexerrSetNotPermitted = 387   ' (&h00000183)
   flexerrOutOfMemory = 7   ' (&h00000007)
   flexerrVB30000 = 30000   ' (&h00007530)
   flexerrVB30001 = 30001   ' (&h00007531)
   flexerrVB30002 = 30002   ' (&h00007532)
   flexerrVB30004 = 30004   ' (&h00007534)
   flexerrVB30005 = 30005   ' (&h00007535)
   flexerrVB30006 = 30006   ' (&h00007536)
   flexerrVB30008 = 30008   ' (&h00007538)
   flexerrVB30009 = 30009   ' (&h00007539)
   flexerrVB30010 = 30010   ' (&h0000753A)
   flexerrVB30011 = 30011   ' (&h0000753B)
   flexerrVB30013 = 30013   ' (&h0000753D)
   flexerrVB30014 = 30014   ' (&h0000753E)
   flexerrVB30015 = 30015   ' (&h0000753F)
   flexerrVB30016 = 30016   ' (&h00007540)
   flexerrVB30017 = 30017   ' (&h00007541)
   flexerrFORMATSTRING = 30018   ' (&h00007542)
   flexerrBadBandNumber = 30019   ' (&h00007543)
   flexerrBadBandColIndex = 30020   ' (&h00007544)
   flexerrNotAvailableWithBandedData = 30021   ' (&h00007545)
   flexerrUnknownBinding = 30022   ' (&h00007546)
   flexerrHROWsNotReleased = 30023   ' (&h00007547)
END ENUM

' // FillStyle Constants
ENUM FillStyleSettings
   flexFillSingle = 0
   flexFillRepeat = 1
END ENUM

' // FocusRect Constants
ENUM FocusRectSettings
   flexFocusNone = 0
   flexFocusLight = 1
   flexFocusHeavy = 2
END ENUM

' // GridLines Constants
ENUM GridLineSettings
   flexGridNone = 0
   flexGridFlat = 1
   flexGridInset = 2
   flexGridRaised = 3
   flexGridDashes = 4
   flexGridDots = 5
END ENUM

' // Highlight Constants
ENUM HighLightSettings
   flexHighlightNever = 0
   flexHighlightAlways = 1
   flexHighlightWithFocus = 2
END ENUM

' // MergeCells Constants
ENUM MergeCellsSettings
   flexMergeNever = 0
   flexMergeFree = 1
   flexMergeRestrictRows = 2
   flexMergeRestrictColumns = 3
   flexMergeRestrictAll = 4
END ENUM

' // Documentation string: MousePointer Constants
ENUM MousePointerSettings
   flexDefault = 0
   flexArrow = 1
   flexCross = 2
   flexIBeam = 3
   flexIcon = 4
   flexSize = 5
   flexSizeNESW = 6
   flexSizeNS = 7
   flexSizeNWSE = 8
   flexSizeEW = 9
   flexUpArrow = 10
   flexHourglass = 11
   flexNoDrop = 12
   flexArrowHourGlass = 13
   flexArrowQuestion = 14
   flexSizeAll = 15
   flexCustom = 99
END ENUM

' // Constants for the OLEDragMode property (but not the DragMode or OLEDropMode properties).
' // IID: {D8898460-742F-11CF-8AEA-00AA00C00905}
ENUM OLEDragConstants
   flexOLEDragManual = 0
   flexOLEDragAutomatic = 1
END ENUM

' // Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' // IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
ENUM OLEDropConstants
   flexOLEDropNone = 0
   flexOLEDropManual = 1
END ENUM

' // Drop effect constants for OLE drag and drop events.
' // IID: {D8898463-742F-11CF-8AEA-00AA00C00905}
ENUM OLEDropEffectConstants
   flexOLEDropEffectNone = 0
   flexOLEDropEffectCopy = 1
   flexOLEDropEffectMove = 2
   flexOLEDropEffectScroll = &h80000000
END ENUM

' // Documentation string: PictureType Constants
ENUM PictureTypeSettings
   flexPictureColor = 0
   flexPictureMonochrome = 1
END ENUM

' // Row Sizing Constants
ENUM RowSizingSettings
   flexRowSizeIndividual = 0
   flexRowSizeAll = 1
END ENUM

' // ScrollBars Constants
ENUM ScrollBarsSettings
   flexScrollBarNone = 0
   flexScrollBarHorizontal = 1
   flexScrollBarVertical = 2
   flexScrollBarBoth = 3
END ENUM

' // SelectionMode Constants
ENUM SelectionModeSettings
   flexSelectionFree = 0
   flexSelectionByRow = 1
   flexSelectionByColumn = 2
END ENUM

' // Sort Constants.
ENUM SortSettings
   flexSortNone = 0
   flexSortGenericAscending = 1
   flexSortGenericDescending = 2
   flexSortNumericAscending = 3
   flexSortNumericDescending = 4
   flexSortStringNoCaseAscending = 5
   flexSortStringNoCaseDescending = 6
   flexSortStringAscending = 7
   flexSortStringDescending = 8
   flexSortCustom = 9
END ENUM

' // TextStyle Constants
ENUM TextStyleSettings
   flexTextFlat = 0
   flexTextRaised = 1
   flexTextInset = 2
   flexTextRaisedLight = 3
   flexTextInsetLight = 4
END ENUM

' // ColWordWrapOption Constants
ENUM WordWrapSettings
   flexSingleLine = 0
   flexWordBreak = 1
   flexWordEllipsis = 2
   flexWordBreakEllipsis = 3
END ENUM

' // VB6 system color constants
#ifndef vbSystemColors
#define vbSystemColors
CONST vbScrollBars           = &H80000000   ' Scroll bar color
CONST vbDesktop              = &H80000001   ' Desktop color
CONST vbActiveTitleBar       = &H80000002   ' Color of the title bar for the active window
CONST vbInactiveTitleBar     = &H80000003   ' Color of the title bar for the inactive window
CONST vbMenuBar              = &H80000004   ' Menu background color
CONST vbWindowBackground     = &H80000005   ' Window background color
CONST vbWindowFrame          = &H80000006   ' Window frame color
CONST vbMenuText             = &H80000007   ' Color of text on menus
CONST vbWindowText           = &H80000008   ' Color of text in windows
CONST vbTitleBarText         = &H80000009   ' Color of text in caption, size box, and scroll arrow
CONST vbActiveBorder         = &H8000000A   ' Border color of active window
CONST vbInactiveBorder       = &H8000000B   ' Border color of inactive window
CONST vbApplicationWorkspace = &H8000000C   ' Background color of multiple-document interface (MDI) applications
CONST vbHighlight            = &H8000000D   ' Background color of items selected in a control
CONST vbHighlightText        = &H8000000E   ' Text color of items selected in a control
CONST vbButtonFace           = &H8000000F   ' Color of shading on the face of command buttons
CONST vbButtonShadow         = &H80000010   ' Color of shading on the edge of command buttons
CONST vbGrayText             = &H80000011   ' Grayed (disabled) text
CONST vbButtonText           = &H80000012   ' Text color on push buttons
CONST vbInactiveCaptionText  = &H80000013   ' Color of text in an inactive caption
CONST vb3DHighlight          = &H80000014   ' Highlight color for 3-D display elements
CONST vb3DDKShadow           = &H80000015   ' Darkest shadow color for 3-D display elements
CONST vb3DLight              = &H80000016   ' Second lightest 3-D color after vb3DHighlight
CONST vbInfoText             = &H80000017   ' Color of text in ToolTips
CONST vbInfoBackground       = &H80000018   ' Background color of ToolTips
#endif

' // VB6 color constants
#ifndef vbColors
#define vbColors
CONST vbRed     = &HFF       ' Red
CONST vbGreen   = &hFF00     ' Green
CONST vbYellow  = &HFFFF     ' Yellow
CONST vbBlue    = &HFF0000   ' Blue
CONST vbMagenta = &HFF00FF   ' Magenta
CONST vbCyan    = &HFFFF00   ' Cyan
CONST vbWhite   = &HFFFFFF   ' White
#endif

#ifndef vbCLipboardFormats
#define vbCLipboardFormats
' Clipboard / OLE formats
CONST vbCFText      = 1
CONST vbCFBitmap    = 2
CONST vbCFMetafile  = 3
CONST vbCFDIB       = 8
CONST vbCFPalette   = 9
CONST vbCFEMetafile = 14
CONST vbCFFiles     = 15
CONST vbCFRTF       = 16   ' Rich Text Format (VB extension)
#endif

#ifndef vbDropEffects
#define vbDropEffects
CONST vbDropEffectNone = 0   ' Drop target cannot accept the data.
CONST vbDropEffectCopy = 1   ' Drop results in a copy of data from the source to the target. The original data is unaltered by the drag operation.
CONST vbDropEffectMove = 2   ' Drop results in data being moved from drag source to drop source. The drag source should remove the data from itself after the move.
CONST vbDropEffectScroll = -2147483648   ' (&H80000000) - Scrolling is occurring or about to occur in the target component. This value is used in conjunction with the other values.
                                         ' Note   Use only if you are performing your own scrolling in the target component.
#endif

' // Dual interfaces - Forward references

TYPE Afx_IMSHFlexGrid AS Afx_IMSHFlexGrid_
'TYPE Afx_IRecordset AS Afx_IRecordset_
TYPE Afx_IVBDataObject AS Afx_IVBDataObject_
TYPE Afx_IVBDataObjectFiles AS Afx_IVBDataObjectFiles_
TYPE Afx_IDataSource AS Afx_IDataSource_

' // Event interfaces - Forward references

TYPE Afx_DMSHFlexGridEvents AS Afx_DMSHFlexGridEvents_

' // Dual interfaces

' ########################################################################################
' Interface name: Afx_IDataSource
' IID: {CD000029-8B95-11D1-82DB-00C04FB1625D}
' Documentation string: Defines methods, properties, and collections used to extract messages from or embed messages into other CDO message body parts.
' Attributes =  4544 [&h000011C0] [Dual] [Nonextensible] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 12
' ########################################################################################

#ifndef __Afx_IDataSource_INTERFACE_DEFINED__
#define __Afx_IDataSource_INTERFACE_DEFINED__

TYPE Afx_Afx_IDataSource_ EXTENDS Afx_IDispatch
   DECLARE ABSTRACT FUNCTION get_SourceClass (BYVAL varSourceClass AS AFX_BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Source (BYVAL varSource AS Afx_IUnknown PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_IsDirty (BYVAL pIsDirty AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_IsDirty (BYVAL pIsDirty AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_SourceURL (BYVAL varSourceURL AS AFX_BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ActiveConnection (BYVAL varActiveConnection AS Afx_AdoConnection PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SaveToObject (BYVAL Source AS Afx_IUnknown PTR, BYVAL InterfaceName AS AFX_BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OpenObject (BYVAL Source AS Afx_IUnknown PTR, BYVAL InterfaceName AS AFX_BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SaveTo (BYVAL SourceURL AS AFX_BSTR, BYVAL ActiveConnection AS Afx_IDispatch PTR, BYVAL Mode AS ConnectModeEnum, BYVAL CreateOptions AS RecordCreateOptionsEnum, BYVAL Options AS RecordOpenOptionsEnum, BYVAL UserName AS AFX_BSTR, BYVAL Password AS AFX_BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Open (BYVAL SourceURL AS AFX_BSTR, BYVAL ActiveConnection AS Afx_IDispatch PTR, BYVAL Mode AS ConnectModeEnum, BYVAL CreateOptions AS RecordCreateOptionsEnum = -1, BYVAL Options AS RecordOpenOptionsEnum, BYVAL UserName AS AFX_BSTR, BYVAL Password AS AFX_BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Save () AS HRESULT
   DECLARE ABSTRACT FUNCTION SaveToContainer (BYVAL ContainerURL AS AFX_BSTR, BYVAL ActiveConnection AS Afx_IDispatch PTR, BYVAL Mode AS ConnectModeEnum, BYVAL CreateOptions AS RecordCreateOptionsEnum, BYVAL Options AS RecordOpenOptionsEnum, BYVAL UserName AS AFX_BSTR, BYVAL Password AS AFX_BSTR) AS HRESULT
END TYPE

#endif

' ########################################################################################
' Interface name: IVBDataObject
' IID: {2334D2B1-713E-11CF-8AE5-00AA00C00905}
' Attributes =  4560 [&h000011D0] [Hidden] [Dual] [Nonextensible] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 5
' ########################################################################################

#ifndef __Afx_IVBDataObject_INTERFACE_DEFINED__
#define __Afx_IVBDataObject_INTERFACE_DEFINED__

TYPE Afx_IVBDataObject_ EXTENDS Afx_IDispatch
   DECLARE ABSTRACT FUNCTION Clear () AS HRESULT
   DECLARE ABSTRACT FUNCTION GetData (BYVAL sFormat AS SHORT, BYVAL pvData AS VARIANT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetFormat (BYVAL sFormat AS SHORT, BYVAL pbFormatSupported AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetData (BYVAL vValue AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND), BYVAL vFormat AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Files (BYVAL pFiles AS Afx_IVBDataObjectFiles PTR PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IVBDataObjectFiles
' IID: {2334D2B3-713E-11CF-8AE5-00AA00C00905}
' Attributes =  4560 [&h000011D0] [Hidden] [Dual] [Nonextensible] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 6
' ########################################################################################

#ifndef __Afx_IVBDataObjectFiles_INTERFACE_DEFINED__
#define __Afx_IVBDataObjectFiles_INTERFACE_DEFINED__

TYPE Afx_IVBDataObjectFiles_ EXTENDS Afx_IDispatch
   DECLARE ABSTRACT FUNCTION get_Item (BYVAL lIndex AS LONG, BYVAL bstrItem AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Count (BYVAL plCount AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Add (BYVAL bstrFilename AS BSTR, BYVAL vIndex AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)) AS HRESULT
   DECLARE ABSTRACT FUNCTION Clear () AS HRESULT
   DECLARE ABSTRACT FUNCTION Remove (BYVAL vIndex AS VARIANT) AS HRESULT
   DECLARE ABSTRACT FUNCTION _NewEnum (BYVAL ppUnk AS IUnknown PTR PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IMSHFlexGrid
' IID: {0ECD9B62-23AA-11D0-B351-00A0C9055D8E}
' Attributes =  4560 [&h000011D0] [Hidden] [Dual] [Nonextensible] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 287
' ########################################################################################

#ifndef __Afx_IMSHFlexGrid_INTERFACE_DEFINED__
#define __Afx_IMSHFlexGrid_INTERFACE_DEFINED__

TYPE Afx_IMSHFlexGrid_ EXTENDS Afx_IDispatch
   DECLARE ABSTRACT FUNCTION get_Rows (BYVAL Rows AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Rows (BYVAL Rows AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Cols (BYVAL BandNumber AS LONG = 0, BYVAL Cols AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Cols (BYVAL BandNumber AS LONG = 0, BYVAL Cols AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FixedRows (BYVAL FixedRows AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FixedRows (BYVAL FixedRows AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FixedCols (BYVAL FixedCols AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FixedCols (BYVAL FixedCols AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Version (BYVAL Version AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FormatString (BYVAL FormatString AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FormatString (BYVAL FormatString AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TopRow (BYVAL TopRow AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TopRow (BYVAL TopRow AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_LeftCol (BYVAL LeftCol AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_LeftCol (BYVAL LeftCol AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Row (BYVAL Row AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Row (BYVAL Row AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Col (BYVAL Col AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Col (BYVAL Col AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowSel (BYVAL RowSel AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowSel (BYVAL RowSel AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColSel (BYVAL ColSel AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColSel (BYVAL ColSel AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Text (BYVAL Text AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Text (BYVAL Text AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColor (BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColor (BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ForeColor (BYVAL ForeColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ForeColor (BYVAL ForeColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorBand (BYVAL BandNumber AS LONG, BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorBand (BYVAL BandNumber AS LONG, BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ForeColorBand (BYVAL BandNumber AS LONG, BYVAL ForeColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ForeColorBand (BYVAL BandNumber AS LONG, BYVAL ForeColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorHeader (BYVAL BandNumber AS LONG, BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorHeader (BYVAL BandNumber AS LONG, BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ForeColorHeader (BYVAL BandNumber AS LONG, BYVAL ForeColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ForeColorHeader (BYVAL BandNumber AS LONG, BYVAL ForeColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorIndent (BYVAL BandNumber AS LONG, BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorIndent (BYVAL BandNumber AS LONG, BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorFixed (BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorFixed (BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ForeColorFixed (BYVAL ForeColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ForeColorFixed (BYVAL ForeColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorSel (BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorSel (BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ForeColorSel (BYVAL ForeColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ForeColorSel (BYVAL ForeColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorBkg (BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorBkg (BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BackColorUnpopulated (BYVAL BackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BackColorUnpopulated (BYVAL BackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_WordWrap (BYVAL WordWrap AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_WordWrap (BYVAL WordWrap AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Font (BYVAL Font AS IFont PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_Font (BYVAL Font AS IFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontWidth (BYVAL FontWidth AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontWidth (BYVAL FontWidth AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontFixed (BYVAL Font AS IFont PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_FontFixed (BYVAL Font AS IFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontWidthFixed (BYVAL FontWidth AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontWidthFixed (BYVAL FontWidth AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontBand (BYVAL BandNumber AS LONG, BYVAL Font AS IFont PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_FontBand (BYVAL BandNumber AS LONG, BYVAL Font AS IFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontWidthBand (BYVAL BandNumber AS LONG, BYVAL FontWidth AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontWidthBand (BYVAL BandNumber AS LONG, BYVAL FontWidth AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontHeader (BYVAL BandNumber AS LONG, BYVAL Font AS IFont PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_FontHeader (BYVAL BandNumber AS LONG, BYVAL Font AS IFont PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontWidthHeader (BYVAL BandNumber AS LONG, BYVAL FontWidth AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontWidthHeader (BYVAL BandNumber AS LONG, BYVAL FontWidth AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontName (BYVAL CellFontName AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontName (BYVAL CellFontName AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontSize (BYVAL CellFontSize AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontSize (BYVAL CellFontSize AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontBold (BYVAL CellFontBold AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontBold (BYVAL CellFontBold AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontItalic (BYVAL CellFontItalic AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontItalic (BYVAL CellFontItalic AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontUnderline (BYVAL CellFontUnderline AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontUnderline (BYVAL CellFontUnderline AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontStrikeThrough (BYVAL CellFontStrikeThrough AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontStrikeThrough (BYVAL CellFontStrikeThrough AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellFontWidth (BYVAL CellFontWidth AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellFontWidth (BYVAL CellFontWidth AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TextStyle (BYVAL TextStyle AS TextStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TextStyle (BYVAL TextStyle AS TextStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TextStyleFixed (BYVAL TextStyle AS TextStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TextStyleFixed (BYVAL TextStyle AS TextStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TextStyleBand (BYVAL BandNumber AS LONG, BYVAL TextStyle AS TextStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TextStyleBand (BYVAL BandNumber AS LONG, BYVAL TextStyle AS TextStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TextStyleHeader (BYVAL BandNumber AS LONG, BYVAL TextStyle AS TextStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TextStyleHeader (BYVAL BandNumber AS LONG, BYVAL TextStyle AS TextStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ScrollTrack (BYVAL ScrollTrack AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ScrollTrack (BYVAL ScrollTrack AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FocusRect (BYVAL FocusRect AS FocusRectSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FocusRect (BYVAL FocusRect AS FocusRectSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_HighLight (BYVAL HighLight AS HighLightSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_HighLight (BYVAL HighLight AS HighLightSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Redraw (BYVAL Redraw AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Redraw (BYVAL Redraw AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ScrollBars (BYVAL ScrollBars AS ScrollBarsSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ScrollBars (BYVAL ScrollBars AS ScrollBarsSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MouseRow (BYVAL MouseRow AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MouseCol (BYVAL MouseCol AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellLeft (BYVAL CellLeft AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellTop (BYVAL CellTop AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellWidth (BYVAL CellWidth AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellHeight (BYVAL CellHeight AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowHeightMin (BYVAL RowHeightMin AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowHeightMin (BYVAL RowHeightMin AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FillStyle (BYVAL FillStyle AS FillStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FillStyle (BYVAL FillStyle AS FillStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLines (BYVAL GridLines AS GridLineSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLines (BYVAL GridLines AS GridLineSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLinesFixed (BYVAL GridLines AS GridLineSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLinesFixed (BYVAL GridLines AS GridLineSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridColor (BYVAL GridColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridColor (BYVAL GridColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridColorFixed (BYVAL GridColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridColorFixed (BYVAL GridColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridColorUnpopulated (BYVAL GridColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridColorUnpopulated (BYVAL GridColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridColorBand (BYVAL BandNumber AS LONG, BYVAL GridColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridColorBand (BYVAL BandNumber AS LONG, BYVAL GridColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridColorHeader (BYVAL BandNumber AS LONG, BYVAL GridColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridColorHeader (BYVAL BandNumber AS LONG, BYVAL GridColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridColorIndent (BYVAL BandNumber AS LONG, BYVAL GridColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridColorIndent (BYVAL BandNumber AS LONG, BYVAL GridColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellBackColor (BYVAL CellBackColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellBackColor (BYVAL CellBackColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellForeColor (BYVAL CellForeColor AS OLE_COLOR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellForeColor (BYVAL CellForeColor AS OLE_COLOR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellAlignment (BYVAL CellAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellAlignment (BYVAL CellAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellTextStyle (BYVAL CellTextStyle AS TextStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellTextStyle (BYVAL CellTextStyle AS TextStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellPictureAlignment (BYVAL CellPictureAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_CellPictureAlignment (BYVAL CellPictureAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Clip (BYVAL Clip AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Clip (BYVAL Clip AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Sort (BYVAL settings AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_SelectionMode (BYVAL SelectionMode AS SelectionModeSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_SelectionMode (BYVAL SelectionMode AS SelectionModeSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MergeCells (BYVAL MergeCells AS MergeCellsSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_MergeCells (BYVAL MergeCells AS MergeCellsSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_AllowBigSelection (BYVAL AllowBigSelection AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_AllowBigSelection (BYVAL AllowBigSelection AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_AllowUserResizing (BYVAL AllowUserResizing AS AllowUserResizeSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_AllowUserResizing (BYVAL AllowUserResizing AS AllowUserResizeSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BorderStyle (BYVAL BorderStyle AS BorderStyleSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BorderStyle (BYVAL BorderStyle AS BorderStyleSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_hWnd (BYVAL hWnd AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Enabled (BYVAL Enabled AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Enabled (BYVAL Enabled AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Appearance (BYVAL Appearance AS AppearanceSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_Appearance (BYVAL Appearance AS AppearanceSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MousePointer (BYVAL MousePointer AS MousePointerSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_MousePointer (BYVAL MousePointer AS MousePointerSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MouseIcon (BYVAL MouseIcon AS IPicture PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_MouseIcon (BYVAL MouseIcon AS IPicture PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_PictureType (BYVAL PictureType AS PictureTypeSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_PictureType (BYVAL PictureType AS PictureTypeSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Picture (BYVAL Picture AS IPicture PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellPicture (BYVAL CellPicture AS IPicture PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_CellPicture (BYVAL CellPicture AS IPicture PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AboutBox () AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TextArray (BYVAL Index AS LONG, BYVAL TextArray AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TextArray (BYVAL Index AS LONG, BYVAL TextArray AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColAlignment (BYVAL Index AS LONG, BYVAL ColAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColAlignment (BYVAL Index AS LONG = -1, BYVAL ColAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColAlignmentFixed (BYVAL Index AS LONG, BYVAL ColAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColAlignmentFixed (BYVAL Index AS LONG = -1, BYVAL ColAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL ColAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG = -1, BYVAL ColAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL ColAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG = -1, BYVAL ColAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColWidth (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL ColWidth AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColWidth (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL ColWidth AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowHeight (BYVAL Index AS LONG, BYVAL RowHeight AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowHeight (BYVAL Index AS LONG, BYVAL RowHeight AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MergeRow (BYVAL Index AS LONG, BYVAL MergeRow AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_MergeRow (BYVAL Index AS LONG, BYVAL MergeRow AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_MergeCol (BYVAL Index AS LONG, BYVAL MergeCol AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_MergeCol (BYVAL Index AS LONG, BYVAL MergeCol AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowPosition (BYVAL Index AS LONG, BYVAL rhs AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColPosition (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL rhs AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowData (BYVAL Index AS LONG, BYVAL RowData AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowData (BYVAL Index AS LONG, BYVAL RowData AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColData (BYVAL Index AS LONG, BYVAL ColData AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColData (BYVAL Index AS LONG, BYVAL ColData AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_TextMatrix (BYVAL Row AS LONG, BYVAL Col AS LONG, BYVAL TextMatrix AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_TextMatrix (BYVAL Row AS LONG, BYVAL Col AS LONG, BYVAL TextMatrix AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION AddItem (BYVAL Item AS BSTR, BYVAL Index AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)) AS HRESULT
   DECLARE ABSTRACT FUNCTION RemoveItem (BYVAL Index AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION Clear () AS HRESULT
   DECLARE ABSTRACT FUNCTION Refresh () AS HRESULT
   DECLARE ABSTRACT FUNCTION ClearStructure () AS HRESULT
   DECLARE ABSTRACT FUNCTION get_DataSource (BYVAL Data_Source AS Afx_IDataSource PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_DataSource (BYVAL Data_Source AS Afx_IDataSource PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_DataMember (BYVAL Data_Member AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_DataMember (BYVAL Data_Member AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowIsVisible (BYVAL Index AS LONG, BYVAL RowIsVisible AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColIsVisible (BYVAL Index AS LONG, BYVAL ColIsVisible AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowPos (BYVAL Index AS LONG, BYVAL RowPos AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColPos (BYVAL Index AS LONG, BYVAL ColPos AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLineWidth (BYVAL GridLineWidth AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLineWidth (BYVAL GridLineWidth AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLineWidthFixed (BYVAL GridLineWidth AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLineWidthFixed (BYVAL GridLineWidth AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLineWidthUnpopulated (BYVAL GridLineWidth AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLineWidthUnpopulated (BYVAL GridLineWidth AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLineWidthBand (BYVAL BandNumber AS LONG, BYVAL GridLineWidth AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLineWidthBand (BYVAL BandNumber AS LONG, BYVAL GridLineWidth AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLineWidthHeader (BYVAL BandNumber AS LONG, BYVAL GridLineWidth AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLineWidthHeader (BYVAL BandNumber AS LONG, BYVAL GridLineWidth AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLineWidthIndent (BYVAL BandNumber AS LONG, BYVAL GridLineWidth AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLineWidthIndent (BYVAL BandNumber AS LONG, BYVAL GridLineWidth AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FixedAlignment (BYVAL Index AS LONG, BYVAL FixedAlignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FixedAlignment (BYVAL Index AS LONG, BYVAL FixedAlignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontName (BYVAL FontName AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontName (BYVAL FontName AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontSize (BYVAL FontSize AS SINGLE PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontSize (BYVAL FontSize AS SINGLE) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontBold (BYVAL FontBold AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontBold (BYVAL FontBold AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontItalic (BYVAL FontItalic AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontItalic (BYVAL FontItalic AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontStrikethru (BYVAL FontStrikethru AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontStrikethru (BYVAL FontStrikethru AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontStrikeThrough (BYVAL FontStrikeThrough AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontStrikeThrough (BYVAL FontStrikeThrough AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_FontUnderline (BYVAL FontUnderline AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_FontUnderline (BYVAL FontUnderline AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RightToLeft (BYVAL RightToLeft AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RightToLeft (BYVAL RightToLeft AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Recordset (BYVAL Recordset AS Afx_ADORecordset PTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_Recordset (BYVAL Recordset AS Afx_ADORecordset PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Rowset (BYVAL Rowset AS VARIANT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION putref_Rowset (BYVAL Rowset AS VARIANT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColHeader (BYVAL BandNumber AS LONG, BYVAL ColHeader AS ColHeaderSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColHeader (BYVAL BandNumber AS LONG, BYVAL ColHeader AS ColHeaderSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL Caption AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL Caption AS BSTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION BandColIndex (BYVAL BandColIndex AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BandData (BYVAL BandData AS LONG, BYVAL Data AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BandData (BYVAL BandData AS LONG, BYVAL Data AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BandDisplay (BYVAL BandDisplay AS BandDisplaySettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BandDisplay (BYVAL BandDisplay AS BandDisplaySettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BandExpandable (BYVAL BandNumber AS LONG, BYVAL BandExpandable AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BandExpandable (BYVAL BandNumber AS LONG, BYVAL BandExpandable AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLinesBand (BYVAL BandNumber AS LONG, BYVAL GridLines AS GridLineSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLinesBand (BYVAL BandNumber AS LONG, BYVAL GridLines AS GridLineSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLinesHeader (BYVAL BandNumber AS LONG, BYVAL GridLines AS GridLineSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLinesHeader (BYVAL BandNumber AS LONG, BYVAL GridLines AS GridLineSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLinesIndent (BYVAL BandNumber AS LONG, BYVAL GridLines AS GridLineSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLinesIndent (BYVAL BandNumber AS LONG, BYVAL GridLines AS GridLineSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_GridLinesUnpopulated (BYVAL GridLines AS GridLineSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_GridLinesUnpopulated (BYVAL GridLines AS GridLineSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BandIndent (BYVAL BandNumber AS LONG, BYVAL BandIndent AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_BandIndent (BYVAL BandNumber AS LONG, BYVAL BandIndent AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_BandLevel (BYVAL BandLevel AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_Bands (BYVAL Bands AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_CellType (BYVAL CellType AS CellTypeSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowSizingMode (BYVAL RowSizingMode AS RowSizingSettings PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowSizingMode (BYVAL RowSizingMode AS RowSizingSettings) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_DataField (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL DataField AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CollectBandFieldNameInfo (BYVAL force_collection AS LONG) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetBandName (BYVAL BandNumber AS LONG, BYVAL BandName AS BSTR PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION CountColumnsInBand (BYVAL BandNumber AS LONG, BYVAL Cols AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION GetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, BYVAL ColName AS BSTR PTR, BYVAL Caption AS BSTR PTR, BYVAL Hidden AS VARIANT_BOOL PTR, BYVAL RowsetColIndex AS LONG PTR, BYVAL Alignment AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION SetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, BYVAL ColName AS BSTR, BYVAL Caption AS BSTR, BYVAL Hidden AS VARIANT_BOOL, BYVAL RowsetColIndex AS LONG, BYVAL Alignment AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION ApplyBandFieldNameInfoChanges () AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowExpandable (BYVAL RowExpandable AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_RowExpanded (BYVAL RowExpanded AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_RowExpanded (BYVAL RowExpanded AS VARIANT_BOOL) AS HRESULT
   DECLARE ABSTRACT FUNCTION CollapseAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
   DECLARE ABSTRACT FUNCTION ExpandAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColWordWrapOption (BYVAL Index AS LONG, BYVAL ColWordWrapOption AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColWordWrapOption (BYVAL Index AS LONG = -1, BYVAL ColWordWrapOption AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL ColWordWrapOption AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG = -1, BYVAL ColWordWrapOption AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG, BYVAL ColWordWrapOption AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIndex AS LONG = -1, BYVAL ColWordWrapOption AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_ColWordWrapOptionFixed (BYVAL Index AS LONG, BYVAL ColWordWrapOption AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_ColWordWrapOptionFixed (BYVAL Index AS LONG = -1, BYVAL ColWordWrapOption AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION get_OLEDropMode (BYVAL psOLEDropMode AS OLEDropConstants PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION put_OLEDropMode (BYVAL psOLEDropMode AS OLEDropConstants) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLEDrag () AS HRESULT
END TYPE

#endif

' ########################################################################################

' ########################################################################################
' Interface name: IRecordset
' IID: {0000050E-0000-0010-8000-00AA006D2EA4}
' Attributes =  4432 [&h00001150] [Hidden] [Dual] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 0
' ########################################################################################

'#ifndef __Afx_IRecordset_INTERFACE_DEFINED__
'#define __Afx_IRecordset_INTERFACE_DEFINED__

'#endif

' ########################################################################################

' ########################################################################################
' Interface name: IVBDataObject
' IID: {2334D2B1-713E-11CF-8AE5-00AA00C00905}
' Attributes =  4560 [&h000011D0] [Hidden] [Dual] [Nonextensible] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 5
' ########################################################################################

'#ifndef __Afx_IVBDataObject_INTERFACE_DEFINED__
'#define __Afx_IVBDataObject_INTERFACE_DEFINED__

'TYPE Afx_IVBDataObject_ EXTENDS Afx_IDispatch
'   DECLARE ABSTRACT FUNCTION Clear () AS HRESULT
'   DECLARE ABSTRACT FUNCTION GetData (BYVAL sFormat AS SHORT, BYVAL pvData AS VARIANT PTR) AS HRESULT
'   DECLARE ABSTRACT FUNCTION GetFormat (BYVAL sFormat AS SHORT, BYVAL pbFormatSupported AS VARIANT_BOOL PTR) AS HRESULT
'   DECLARE ABSTRACT FUNCTION SetData (BYVAL vValue AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND), BYVAL vFormat AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)) AS HRESULT
'   DECLARE ABSTRACT FUNCTION get_Files (BYVAL pFiles AS Afx_IVBDataObjectFiles PTR PTR) AS HRESULT
'END TYPE

'#endif

' ########################################################################################

' ########################################################################################
' Interface name: IVBDataObjectFiles
' IID: {2334D2B3-713E-11CF-8AE5-00AA00C00905}
' Attributes =  4560 [&h000011D0] [Hidden] [Dual] [Nonextensible] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 6
' ########################################################################################

'#ifndef __Afx_IVBDataObjectFiles_INTERFACE_DEFINED__
'#define __Afx_IVBDataObjectFiles_INTERFACE_DEFINED__

'TYPE Afx_IVBDataObjectFiles_ EXTENDS Afx_IDispatch
'   DECLARE ABSTRACT FUNCTION get_Item (BYVAL lIndex AS LONG, BYVAL bstrItem AS BSTR PTR) AS HRESULT
'   DECLARE ABSTRACT FUNCTION get_Count (BYVAL plCount AS LONG PTR) AS HRESULT
'   DECLARE ABSTRACT FUNCTION Add (BYVAL bstrFilename AS BSTR, BYVAL vIndex AS VARIANT = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)) AS HRESULT
'   DECLARE ABSTRACT FUNCTION Clear () AS HRESULT
'   DECLARE ABSTRACT FUNCTION Remove (BYVAL vIndex AS VARIANT) AS HRESULT
'   DECLARE ABSTRACT FUNCTION _NewEnum (BYVAL ppUnk AS IUnknown PTR PTR) AS HRESULT
'END TYPE

'#endif

' ########################################################################################


' // Event interfaces

' ########################################################################################
' Interface name: DMSHFlexGridEvents
' IID: {0ECD9B63-23AA-11D0-B351-00A0C9055D8E}
' Attributes =  4096 [&h00001000] [Dispatchable]
' Inherited interface = IDispatch
' Number of methods = 22
' ########################################################################################

#ifndef __Afx_DMSHFlexGridEvents_INTERFACE_DEFINED__
#define __Afx_DMSHFlexGridEvents_INTERFACE_DEFINED__

TYPE Afx_DMSHFlexGridEvents_ EXTENDS Afx_IDispatch
   DECLARE ABSTRACT FUNCTION Click () AS HRESULT
   DECLARE ABSTRACT FUNCTION KeyDown (BYVAL KeyCode AS SHORT PTR, BYVAL Shift AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION DblClick () AS HRESULT
   DECLARE ABSTRACT FUNCTION KeyPress (BYVAL KeyAscii AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION KeyUp (BYVAL KeyCode AS SHORT PTR, BYVAL Shift AS SHORT) AS HRESULT
   DECLARE ABSTRACT FUNCTION MouseDown (BYVAL Button AS SHORT, BYVAL Shift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   DECLARE ABSTRACT FUNCTION MouseMove (BYVAL Button AS SHORT, BYVAL Shift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   DECLARE ABSTRACT FUNCTION MouseUp (BYVAL Button AS SHORT, BYVAL Shift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   DECLARE ABSTRACT FUNCTION SelChange () AS HRESULT
   DECLARE ABSTRACT FUNCTION RowColChange () AS HRESULT
   DECLARE ABSTRACT FUNCTION EnterCell () AS HRESULT
   DECLARE ABSTRACT FUNCTION LeaveCell () AS HRESULT
   DECLARE ABSTRACT FUNCTION Scroll () AS HRESULT
   DECLARE ABSTRACT FUNCTION Compare (BYVAL Row1 AS LONG, BYVAL Row2 AS LONG, BYVAL Cmp AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Collapse (BYVAL Cancel AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION Expand (BYVAL Cancel AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLEStartDrag (BYVAL Data AS Afx_IVBDataObject PTR PTR, BYVAL AllowedEffects AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLEGiveFeedback (BYVAL Effect AS LONG PTR, BYVAL DefaultCursors AS VARIANT_BOOL PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLESetData (BYVAL Data AS Afx_IVBDataObject PTR PTR, BYVAL DataFormat AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLECompleteDrag (BYVAL Effect AS LONG PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLEDragOver (BYVAL Data AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, BYVAL Button AS SHORT PTR, BYVAL Shift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR, BYVAL State AS SHORT PTR) AS HRESULT
   DECLARE ABSTRACT FUNCTION OLEDragDrop (BYVAL Data AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, BYVAL Button AS SHORT PTR, BYVAL Shift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR) AS HRESULT
END TYPE

#endif

' ########################################################################################

' +++++++++++++++++++++
' ########################################################################################
' CMSHFlexGrid class
' ########################################################################################
TYPE CMSHFlexGrid
   
Private:
   m_grid AS Afx_IMSHFlexGrid PTR
   m_Result AS HRESULT
   m_dwCookie AS DWORD

Public:
   DECLARE CONSTRUCTOR (BYVAL pDisp AS IDispatch PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
   DECLARE DESTRUCTOR
   DECLARE FUNCTION GetLastResult () AS LONG
   DECLARE FUNCTION SetResult (BYVAL Result AS LONG) AS LONG
   DECLARE FUNCTION GetErrorInfo (BYVAL dwError AS LONG = -1) AS DWSTRING
'   DECLARE FUNCTION hWnd () AS LONG
   DECLARE FUNCTION hWnd () AS HWND
   DECLARE FUNCTION AddItem (BYREF Item AS WSTRING, BYVAL Index AS LONG = -1) AS HRESULT
   DECLARE FUNCTION RemoveItem (BYVAL Index AS LONG) AS HRESULT
   DECLARE PROPERTY AllowBigSelection () AS BOOLEAN
   DECLARE PROPERTY AllowBigSelection (BYVAL bAllowBigSelection AS BOOLEAN)
   DECLARE PROPERTY AllowUserResizing () AS AllowUserResizeSettings
   DECLARE PROPERTY AllowUserResizing (BYVAL bAllowUserResizing AS AllowUserResizeSettings)
   DECLARE PROPERTY BackColor () AS OLE_COLOR
   DECLARE PROPERTY BackColor (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DECLARE PROPERTY BackColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorBand () AS OLE_COLOR
   DECLARE PROPERTY BackColorBand (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DECLARE PROPERTY BackColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorHeader () AS OLE_COLOR
   DECLARE PROPERTY BackColorHeader (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorIndent (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DECLARE PROPERTY BackColorIndent (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorIndent () AS OLE_COLOR
   DECLARE PROPERTY BackColorIndent (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorFixed () AS OLE_COLOR
   DECLARE PROPERTY BackColorFixed (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorSel () AS OLE_COLOR
   DECLARE PROPERTY BackColorSel (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorBkg () AS OLE_COLOR
   DECLARE PROPERTY BackColorBkg (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY BackColorUnpopulated () AS OLE_COLOR
   DECLARE PROPERTY BackColorUnpopulated (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY ForeColor () AS OLE_COLOR
   DECLARE PROPERTY ForeColor (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY ForeColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DECLARE PROPERTY ForeColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY ForeColorFixed () AS OLE_COLOR
   DECLARE PROPERTY ForeColorFixed (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY ForeColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DECLARE PROPERTY ForeColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY ForeColorHeader () AS OLE_COLOR
   DECLARE PROPERTY ForeColorHeader (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY ForeColorSel () AS OLE_COLOR
   DECLARE PROPERTY ForeColorSel (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY Rows () AS LONG
   DECLARE PROPERTY Rows (BYVAL nRows AS LONG)
   DECLARE PROPERTY Cols (BYVAL BandBumber AS LONG) AS LONG
   DECLARE PROPERTY Cols (BYVAL BandNumber AS LONG, BYVAL nCols AS LONG)
   DECLARE PROPERTY Cols () AS LONG
   DECLARE PROPERTY Cols (BYVAL nCols AS LONG)
   DECLARE PROPERTY FixedRows () AS LONG
   DECLARE PROPERTY FixedRows (BYVAL nRows AS LONG)
   DECLARE PROPERTY FixedCols () AS LONG
   DECLARE PROPERTY FixedCols (BYVAL nCols AS LONG)
   DECLARE PROPERTY FixedAlignment (BYVAL Index AS LONG) AS SHORT
   DECLARE PROPERTY FixedAlignment (BYVAL Index AS LONG, BYVAL alignment AS SHORT)
   DECLARE PROPERTY Row () AS LONG
   DECLARE PROPERTY Row (BYVAL nRow AS LONG)
   DECLARE PROPERTY Col () AS LONG
   DECLARE PROPERTY Col (BYVAL nCol AS LONG)
   DECLARE PROPERTY RowSel () AS LONG
   DECLARE PROPERTY RowSel (BYVAL nRow AS LONG)
   DECLARE PROPERTY ColSel () AS LONG
   DECLARE PROPERTY ColSel (BYVAL nCol AS LONG)
   DECLARE PROPERTY TopRow () AS LONG
   DECLARE PROPERTY TopRow (BYVAL nRow AS LONG)
   DECLARE PROPERTY LeftCol () AS LONG
   DECLARE PROPERTY LeftCol (BYVAL nCol AS LONG)
   DECLARE PROPERTY GridLines () AS GridLineSettings
   DECLARE PROPERTY GridLines (BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesFixed () AS GridLineSettings
   DECLARE PROPERTY GridLinesFixed (BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesBand (BYVAL BandNumber AS LONG) AS GridLineSettings 
   DECLARE PROPERTY GridLinesBand (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesBand () AS GridLineSettings 
   DECLARE PROPERTY GridLinesBand (BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesHeader (BYVAL BandNumber AS LONG) AS GridLineSettings 
   DECLARE PROPERTY GridLinesHeader (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesHeader () AS GridLineSettings 
   DECLARE PROPERTY GridLinesHeader (BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesIndent (BYVAL BandNumber AS LONG) AS GridLineSettings 
   DECLARE PROPERTY GridLinesIndent (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesIndent () AS GridLineSettings 
   DECLARE PROPERTY GridLinesIndent (BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridLinesUnpopulated () AS GridLineSettings 
   DECLARE PROPERTY GridLinesUnpopulated (BYVAL value AS GridLineSettings)
   DECLARE PROPERTY GridColor () AS OLE_COLOR 
   DECLARE PROPERTY GridColor (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY GridColorFixed () AS OLE_COLOR 
   DECLARE PROPERTY GridColorFixed (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY GridColorUnpopulated () AS OLE_COLOR 
   DECLARE PROPERTY GridColorUnpopulated (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY GridColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR 
   DECLARE PROPERTY GridColorBand (BYVAL BandNumber AS LONG, BYVAL value AS OLE_COLOR)
   DECLARE PROPERTY GridColorBand () AS OLE_COLOR 
   DECLARE PROPERTY GridColorBand (BYVAL value AS OLE_COLOR)
   DECLARE PROPERTY GridColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR 
   DECLARE PROPERTY GridColorHeader (BYVAL BandNumber AS LONG, BYVAL value AS OLE_COLOR)
   DECLARE PROPERTY GridColorHeader () AS OLE_COLOR 
   DECLARE PROPERTY GridColorHeader (BYVAL value AS OLE_COLOR)
   DECLARE PROPERTY GridColorIndent (BYVAL BandNumber AS LONG) AS OLE_COLOR 
   DECLARE PROPERTY GridColorIndent (BYVAL BandNumber AS LONG, BYVAL value AS OLE_COLOR)
   DECLARE PROPERTY GridColorIndent () AS OLE_COLOR 
   DECLARE PROPERTY GridColorIndent (BYVAL value AS OLE_COLOR)
   DECLARE PROPERTY RowHeight (BYVAL Index AS LONG) AS LONG
   DECLARE PROPERTY RowHeight (BYVAL Index AS LONG, BYVAL rHeight AS LONG)
   DECLARE PROPERTY RowHeightMin () AS LONG
   DECLARE PROPERTY RowHeightMin (BYVAL rHeightMin AS LONG)
   DECLARE PROPERTY ColWidth (BYVAL Index AS LONG) AS LONG
   DECLARE PROPERTY ColWidth (BYVAL Index AS LONG, BYVAL nWidth AS LONG)
   DECLARE FUNCTION ColWidth2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0) AS LONG
   DECLARE FUNCTION ColWidth2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL nWidth AS LONG) AS HRESULT
   DECLARE PROPERTY RowIsVisible (BYVAL Index AS LONG) AS BOOLEAN
   DECLARE PROPERTY ColIsVisible (BYVAL Index AS LONG) AS BOOLEAN
   DECLARE PROPERTY RowPos (BYVAL Index AS LONG) AS LONG
   DECLARE PROPERTY ColPos (BYVAL Index AS LONG) AS LONG
   DECLARE PROPERTY RowPosition (BYVAL Index AS LONG, BYVAL newPos AS LONG)
   DECLARE PROPERTY ColPosition (BYVAL Index AS LONG, BYVAL newPos AS LONG)
   DECLARE FUNCTION ColPosition2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL newPos AS LONG) AS HRESULT
   DECLARE PROPERTY MergeRow (BYVAL Index AS LONG) AS BOOLEAN
   DECLARE PROPERTY MergeRow (BYVAL Index AS LONG, BYVAL merge AS BOOLEAN)
   DECLARE PROPERTY MergeCol (BYVAL Index AS LONG) AS BOOLEAN
   DECLARE PROPERTY MergeCol (BYVAL Index AS LONG, BYVAL merge AS BOOLEAN)
   DECLARE PROPERTY MergeCells () AS MergeCellsSettings
   DECLARE PROPERTY MergeCells (BYVAL merge AS MergeCellsSettings)
   DECLARE FUNCTION Clear () AS HRESULT
   DECLARE FUNCTION ClearStructure () AS HRESULT
   DECLARE FUNCTION Refresh () AS HRESULT
   DECLARE PROPERTY Redraw () AS BOOLEAN
   DECLARE PROPERTY Redraw (BYVAL bRedraw AS BOOLEAN)
   DECLARE PROPERTY TextArray (BYVAL Index AS LONG) AS DWSTRING
   DECLARE PROPERTY TextArray (BYVAL Index AS LONG, BYREF wszText AS WSTRING)
   DECLARE FUNCTION TextMatrix (BYVAL nRow AS LONG, BYVAL nCol AS LONG) AS DWSTRING
   DECLARE FUNCTION TextMatrix (BYVAL nRow AS LONG, BYVAL nCol AS LONG, BYREF wszText AS WSTRING) AS HRESULT
   DECLARE PROPERTY Text () AS DWSTRING
   DECLARE PROPERTY Text (BYREF wszText AS WSTRING)
   DECLARE PROPERTY FormatString () AS DWSTRING
   DECLARE PROPERTY FormatString (BYREF wszText AS WSTRING)
   DECLARE PROPERTY DataSource () AS Afx_IDataSource PTR
   DECLARE PROPERTY DataSource (BYVAL Data_Source AS Afx_IDataSource PTR)
   DECLARE PROPERTY DataMember () AS DWSTRING
   DECLARE PROPERTY DataMember (BYREF wszDataMember AS WSTRING)
   DECLARE PROPERTY Recordset () AS Afx_ADORecordset PTR
   DECLARE PROPERTY Recordset (BYVAL rs AS Afx_ADORecordset PTR)
   DECLARE PROPERTY Rowset () AS VARIANT
   DECLARE PROPERTY Rowset (BYVAL v AS VARIANT)
   DECLARE PROPERTY FillStyle () AS FillStyleSettings
   DECLARE PROPERTY FillStyle (BYVAL style AS FillStyleSettings)
   DECLARE PROPERTY Clip () AS DWSTRING
   DECLARE PROPERTY Clip (BYREF wszClip AS WSTRING)
   DECLARE PROPERTY SelectionMode () AS SelectionModeSettings
   DECLARE PROPERTY SelectionMode (BYVAL selMode AS SelectionModeSettings)
   DECLARE PROPERTY Sort (BYVAL settings AS SHORT)
   DECLARE PROPERTY BorderStyle () AS BorderStyleSettings
   DECLARE PROPERTY BorderStyle (BYVAL style AS BorderStyleSettings)
   DECLARE PROPERTY Appearance () AS AppearanceSettings
   DECLARE PROPERTY Appearance (BYVAL app AS AppearanceSettings)
   DECLARE PROPERTY Enabled () AS BOOLEAN
   DECLARE PROPERTY Enabled (BYVAL bEnabled AS BOOLEAN)
   DECLARE PROPERTY WordWrap () AS BOOLEAN
   DECLARE PROPERTY WordWrap (BYVAL bWrap AS BOOLEAN)
   DECLARE PROPERTY FocusRect () AS FocusRectSettings
   DECLARE PROPERTY FocusRect (BYVAL bFocusRect AS FocusRectSettings)
   DECLARE PROPERTY Highlight () AS HighLightSettings
   DECLARE PROPERTY Highlight (BYVAL bHighlight AS HighLightSettings)
   DECLARE PROPERTY RowData (BYVAL Index AS LONG) AS LONG
   DECLARE PROPERTY RowData (BYVAL Index AS LONG, BYVAL nData AS LONG)
   DECLARE PROPERTY BandData (BYVAL band AS LONG) AS LONG
   DECLARE PROPERTY BandData (BYVAL band AS LONG, BYVAL nData AS LONG)
   DECLARE PROPERTY BandDisplay () AS BandDisplaySettings
   DECLARE PROPERTY BandDisplay (BYVAL settings AS BandDisplaySettings)
   DECLARE PROPERTY BandExpandable (BYVAL BandNumber AS LONG) AS BOOLEAN
   DECLARE PROPERTY BandExpandable (BYVAL BandNumber AS LONG, BYVAL bExpandable AS BOOLEAN)
   DECLARE PROPERTY RowExpandable () AS BOOLEAN
   DECLARE PROPERTY RowExpanded () AS BOOLEAN
   DECLARE PROPERTY RowExpanded (BYVAL bRowExpanded AS BOOLEAN)
   DECLARE FUNCTION CollapseAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
   DECLARE FUNCTION ExpandAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
   DECLARE PROPERTY GridLineWidth () AS SHORT
   DECLARE PROPERTY GridLineWidth (BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthFixed () AS SHORT
   DECLARE PROPERTY GridLineWidthFixed (BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthUnpopulated () AS SHORT
   DECLARE PROPERTY GridLineWidthUnpopulated (BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthBand (BYVAL BandNumber AS LONG) AS SHORT
   DECLARE PROPERTY GridLineWidthBand (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthBand () AS SHORT
   DECLARE PROPERTY GridLineWidthBand (BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthHeader (BYVAL BandNumber AS LONG) AS SHORT
   DECLARE PROPERTY GridLineWidthHeader (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthHeader () AS SHORT
   DECLARE PROPERTY GridLineWidthHeader (BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthIndent (BYVAL BandNumber AS LONG) AS SHORT
   DECLARE PROPERTY GridLineWidthIndent (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
   DECLARE PROPERTY GridLineWidthIndent () AS SHORT
   DECLARE PROPERTY GridLineWidthIndent (BYVAL nWidth AS SHORT)
   DECLARE FUNCTION Bands () AS LONG
   DECLARE FUNCTION BandLevel () AS LONG
   DECLARE FUNCTION BandColIndex () AS LONG
   DECLARE PROPERTY BandIndent (BYVAL BandNumber AS LONG) AS LONG
   DECLARE PROPERTY BandIndent (BYVAL BandNumber AS LONG, BYVAL nCols AS LONG)
   DECLARE PROPERTY BandIndent () AS LONG
   DECLARE PROPERTY BandIndent (BYVAL nCols AS LONG)
   DECLARE FUNCTION GetBandName (BYVAL BandNumber AS LONG) AS DWSTRING
   DECLARE FUNCTION CountColumnsInBand (BYVAL BandNumber AS LONG) AS LONG
   DECLARE FUNCTION CollectBandFieldNameInfo (BYVAL force_collection AS LONG) AS HRESULT
   DECLARE FUNCTION GetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, _
                    BYVAL ColName AS BSTR PTR, BYVAL Caption AS BSTR PTR, BYVAL Hidden AS VARIANT_BOOL PTR, _
                    BYVAL RowsetColIndex AS LONG PTR, BYVAL Alignment AS SHORT PTR) AS HRESULT
   DECLARE FUNCTION SetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, _
                    BYVAL ColName AS BSTR, BYVAL Caption AS BSTR, BYVAL Hidden AS VARIANT_BOOL, _
                    BYVAL RowsetColIndex AS LONG, BYVAL Alignment AS SHORT) AS HRESULT
   DECLARE FUNCTION ApplyBandFieldNameInfoChanges () AS HRESULT
   DECLARE FUNCTION DataField (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS DWSTRING
   DECLARE PROPERTY RowSizingMode () AS RowSizingSettings
   DECLARE PROPERTY RowSizingMode (BYVAL sizingMode AS RowSizingSettings)
   DECLARE PROPERTY ColWordWrapOption (BYVAL Index AS LONG) AS WordWrapSettings
   DECLARE PROPERTY ColWordWrapOption (BYVAL Index AS LONG, BYVAL opt AS WordWrapSettings)
   DECLARE FUNCTION ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS WordWrapSettings
   DECLARE FUNCTION ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYVAL opt AS WordWrapSettings) AS HRESULT
   DECLARE FUNCTION ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS WordWrapSettings
   DECLARE FUNCTION ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYVAL opt AS WordWrapSettings) AS HRESULT
   DECLARE PROPERTY ColWordWrapOptionFixed (BYVAL Index AS LONG) AS WordWrapSettings
   DECLARE PROPERTY ColWordWrapOptionFixed (BYVAL Index AS LONG, BYVAL opt AS WordWrapSettings)
   DECLARE FUNCTION MouseRow (BYVAL Index AS LONG) AS LONG
   DECLARE FUNCTION MouseRow () AS LONG
   DECLARE FUNCTION MouseCol () AS LONG
   DECLARE PROPERTY MousePointer () AS MousePointerSettings
   DECLARE PROPERTY MousePointer (BYVAL settings AS MousePointerSettings)
   DECLARE PROPERTY MouseIcon () AS IPicture PTR
   DECLARE PROPERTY MouseIcon (BYVAL pic AS IPicture PTR)
   DECLARE PROPERTY ColHeader (BYVAL BandNumber AS LONG) AS ColHeaderSettings
   DECLARE PROPERTY ColHeader (BYVAL BandNumber AS LONG, BYVAL settings AS ColHeaderSettings)
   DECLARE PROPERTY ColHeader () AS ColHeaderSettings
   DECLARE PROPERTY ColHeader (BYVAL settings AS ColHeaderSettings)
   DECLARE FUNCTION ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS DWSTRING
   DECLARE FUNCTION ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYREF wszCaption AS WSTRING) AS HRESULT
   DECLARE FUNCTION ColHeaderCaption (BYVAL BandColIdx AS LONG) AS DWSTRING
   DECLARE FUNCTION ColHeaderCaption (BYVAL BandColIdx AS LONG, BYREF wszCaption AS WSTRING) AS HRESULT
   DECLARE PROPERTY ScrollBars () AS ScrollBarsSettings
   DECLARE PROPERTY ScrollBars (BYVAL settings AS ScrollBarsSettings)
   DECLARE PROPERTY ScrollTrack () AS BOOLEAN
   DECLARE PROPERTY ScrollTrack (BYVAL bTrack AS BOOLEAN)
   DECLARE PROPERTY OLEDropMode () AS OLEDropConstants
   DECLARE PROPERTY OLEDropMode (BYVAL dropMode AS OLEDropConstants)
   DECLARE FUNCTION OLEDrag () AS HRESULT
   DECLARE PROPERTY TextStyle () AS TextStyleSettings
   DECLARE PROPERTY TextStyle (BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY TextStyleFixed () AS TextStyleSettings
   DECLARE PROPERTY TextStyleFixed (BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY TextStyleBand (BYVAL BandNumber AS LONG) AS TextStyleSettings
   DECLARE PROPERTY TextStyleBand (BYVAL BandNumber AS LONG, BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY TextStyleBand () AS TextStyleSettings
   DECLARE PROPERTY TextStyleBand (BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY TextStyleHeader (BYVAL BandNumber AS LONG) AS TextStyleSettings
   DECLARE PROPERTY TextStyleHeader (BYVAL BandNumber AS LONG, BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY TextStyleHeader () AS TextStyleSettings
   DECLARE PROPERTY TextStyleHeader (BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY CellType () AS CellTypeSettings
   DECLARE PROPERTY CellHeight () AS LONG
   DECLARE PROPERTY CellWidth () AS LONG
   DECLARE PROPERTY CellLeft () AS LONG
   DECLARE PROPERTY CellTop () AS LONG
   DECLARE PROPERTY CellBackColor () AS OLE_COLOR
   DECLARE PROPERTY CellBackColor (BYVAL bkColor AS OLE_COLOR)
   DECLARE PROPERTY CellForeColor () AS OLE_COLOR
   DECLARE PROPERTY CellForeColor (BYVAL clr AS OLE_COLOR)
   DECLARE PROPERTY CellAlignment () AS SHORT
   DECLARE PROPERTY CellAlignment (BYVAL nAlignment AS SHORT)
   DECLARE PROPERTY CellTextStyle () AS TextStyleSettings
   DECLARE PROPERTY CellTextStyle (BYVAL style AS TextStyleSettings)
   DECLARE PROPERTY CellPictureAlignment () AS SHORT
   DECLARE PROPERTY CellPictureAlignment (BYVAL nAlignment AS SHORT)
   DECLARE PROPERTY ColAlignment (BYVAL Index AS LONG) AS SHORT
   DECLARE PROPERTY ColAlignment (BYVAL Index AS LONG, BYVAL nAlignment AS SHORT)
   DECLARE PROPERTY ColAlignmentFixed (BYVAL Index AS LONG) AS SHORT
   DECLARE PROPERTY ColAlignmentFixed (BYVAL Index AS LONG, BYVAL nAlignment AS SHORT)
   DECLARE FUNCTION ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS SHORT
   DECLARE FUNCTION ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   DECLARE FUNCTION ColAlignmentBand (BYVAL BandColIdx AS LONG) AS SHORT
   DECLARE FUNCTION ColAlignmentBand (BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   DECLARE FUNCTION ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS SHORT
   DECLARE FUNCTION ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   DECLARE FUNCTION ColAlignmentHeader (BYVAL BandColIdx AS LONG) AS SHORT
   DECLARE FUNCTION ColAlignmentHeader (BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   DECLARE PROPERTY Font () AS IFont PTR
   DECLARE PROPERTY Font (BYVAL pFont AS IFont PTR)
   DECLARE PROPERTY FontName () AS DWSTRING
   DECLARE PROPERTY FontName (BYREF wszFont AS WSTRING)
   DECLARE PROPERTY FontSize () AS SINGLE
   DECLARE PROPERTY FontSize (BYVAL nSize AS SINGLE)
   DECLARE PROPERTY FontBold () AS BOOLEAN
   DECLARE PROPERTY FontBold (BYVAL bBold AS VARIANT_BOOL)
   DECLARE PROPERTY FontItalic () AS BOOLEAN
   DECLARE PROPERTY FontItalic (BYVAL bItalic AS VARIANT_BOOL)
   DECLARE PROPERTY FontStrikethru () AS BOOLEAN
   DECLARE PROPERTY FontStrikethru (BYVAL bStrikeThrough AS VARIANT_BOOL)
   DECLARE PROPERTY FontStrikeThrough () AS BOOLEAN
   DECLARE PROPERTY FontStrikeThrough (BYVAL bStrikeThrough AS VARIANT_BOOL)
   DECLARE PROPERTY FontUnderline () AS BOOLEAN
   DECLARE PROPERTY FontUnderline (BYVAL bUnderline AS VARIANT_BOOL)
   DECLARE PROPERTY RightToLeft () AS BOOLEAN
   DECLARE PROPERTY RightToLeft (BYVAL bRightToLeft AS VARIANT_BOOL)
   DECLARE PROPERTY FontWidth () AS SINGLE
   DECLARE PROPERTY FontWidth (BYVAL nWidth AS SINGLE)
   DECLARE PROPERTY FontFixed () AS IFont PTR
   DECLARE PROPERTY FontFixed (BYVAL pFont AS IFont PTR)
   DECLARE PROPERTY FontWidthFixed () AS SINGLE
   DECLARE PROPERTY FontWidthFixed (BYVAL nWidth AS SINGLE)
   DECLARE PROPERTY FontBand (BYVAL BandNumber AS LONG) AS IFont PTR
   DECLARE PROPERTY FontBand (BYVAL BandNumber AS LONG, BYVAL pFont AS IFont PTR)
   DECLARE PROPERTY FontWidthBand (BYVAL BandNumber AS LONG) AS SINGLE
   DECLARE PROPERTY FontWidthBand (BYVAL BandNumber AS LONG, BYVAL nWidth AS SINGLE)
   DECLARE PROPERTY FontHeader (BYVAL BandNumber AS LONG) AS IFont PTR
   DECLARE PROPERTY FontHeader (BYVAL BandNumber AS LONG, BYVAL pFont AS IFont PTR)
   DECLARE PROPERTY FontWidthHeader (BYVAL BandNumber AS LONG) AS SINGLE
   DECLARE PROPERTY FontWidthHeader (BYVAL BandNumber AS LONG, BYVAL nWidth AS SINGLE)
   DECLARE PROPERTY CellFontName () AS DWSTRING
   DECLARE PROPERTY CellFontName (BYREF wszFontName AS WSTRING)
   DECLARE PROPERTY CellFontSize () AS SINGLE
   DECLARE PROPERTY CellFontSize (BYVAL nSize AS SINGLE)
   DECLARE PROPERTY CellFontBold () AS BOOLEAN
   DECLARE PROPERTY CellFontBold (BYVAL bBold AS VARIANT_BOOL)
   DECLARE PROPERTY CellFontItalic () AS BOOLEAN
   DECLARE PROPERTY CellFontItalic (BYVAL bItalic AS VARIANT_BOOL)
   DECLARE PROPERTY CellFontUnderline () AS BOOLEAN
   DECLARE PROPERTY CellFontUnderline (BYVAL bUnderline AS VARIANT_BOOL)
   DECLARE PROPERTY CellFontStrikeThrough () AS BOOLEAN
   DECLARE PROPERTY CellFontStrikeThrough (BYVAL bStrikeThrouh AS VARIANT_BOOL)
   DECLARE PROPERTY CellFontWidth () AS SINGLE
   DECLARE PROPERTY CellFontWidth (BYVAL nWidth AS SINGLE)
   DECLARE PROPERTY PictureType () AS PictureTypeSettings
   DECLARE PROPERTY PictureType (BYVAL picType AS PictureTypeSettings)
   DECLARE PROPERTY CellPicture () AS IPicture PTR
   DECLARE PROPERTY CellPicture (BYVAL pic AS IPicture PTR)
   DECLARE PROPERTY Picture () AS IPicture PTR
   DECLARE FUNCTION AboutBox () AS HRESULT
   DECLARE FUNCTION Version () AS SHORT
   DECLARE FUNCTION SetEvents (BYVAL pEvtSink AS ANY PTR) AS HRESULT

END TYPE

' ========================================================================================
PRIVATE CONSTRUCTOR CMSHFlexGrid (BYVAL pDisp AS IDispatch PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
   m_grid = cast(ANY PTR, pDisp)
   IF fAddRef THEN
      IF m_grid THEN AfxSafeAddRef(m_grid)
   END IF   
   CMSHGRID_DP("m_grid: " & WSTR(m_grid))
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CMSHFlexGrid
   CMSHGRID_DP("m_grid: " & WSTR(m_grid))
   IF m_dwCookie THEN AfxUnAdvise(m_grid, AFX_IID_DMSHFlexGridEvents, m_dwCookie)
   IF m_grid THEN AfxSafeRelease(m_grid)
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the last result code
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.GetLastResult () AS HRESULT
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the last result code.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.SetResult (BYVAL Result AS HRESULT) AS HRESULT
   m_Result = Result
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a description of the last result code.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.GetErrorInfo (BYVAL nError AS LONG = -1) AS DWSTRING
   IF nError = -1 THEN nError = m_Result
   DIM cbLen AS DWORD, pBuffer AS WSTRING PTR, dwsMsg AS DWSTRING
   cbLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER OR _
           FORMAT_MESSAGE_FROM_SYSTEM OR FORMAT_MESSAGE_IGNORE_INSERTS, _
           NULL, nError, BYVAL MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), _
           cast(LPWSTR, @pBuffer), 0, NULL)
   IF cbLen THEN
      dwsMsg = *pBuffer
      LocalFree pBuffer
   END IF
   IF nError THEN dwsMsg = "Error &h" + HEX(nError) & CHR(13, 10) + dwsMsg
   RETURN dwsMsg
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the window handle assigned by the Windows operating system to the grid control.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.hWnd () AS ..HWND
   DIM hWin AS LONG
   m_Result = m_grid->get_hWnd(@hWin)
   CMSHGRID_DP("hWnd: " & WSTR(hWin))
'   RETURN cptr(..HWND, cint(hWin))
   RETURN cast(..HWND, hWin)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a row to an MSHFlexGrid.
' Parameters:
'   Item: Required. A string expression displayed in the newly added row. To add multiple
'         strings (for multiple columns in the row), use the tab character to separate each string. 
'   Index: Optional. A Long value indicating the position within the control. This position
'          is where the new row is placed. For the first row, index=0. If index is omitted,
'          the new row becomes the last row in the band. Note that index is BandColIndex in the MSHFlexGrid. 
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.AddItem (BYREF Item AS WSTRING, BYVAL Index AS LONG = -1) AS HRESULT
   CMSHGRID_DP("Index: " & WSTR(index))
   DIM v AS VARIANT
   IF Index = -1 THEN
      v = TYPE(VT_ERROR,0,0,0,DISP_E_PARAMNOTFOUND)
   ELSE
      v.vt = VT_I4
      v.lVal = Index
   END IF
   DIM bstrItem AS Afx_BSTR = SysAllocString(Item)
   m_Result = m_grid->AddItem(bstrItem, v)
   SysFreeString(bstrItem)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the row at the specified index and automatically shifts all subsequent rows up
' to fill the gap. 
' Index: A Long value indicating representing the zero-based position of the row to be deleted.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.RemoveItem (BYVAL Index AS LONG) AS HRESULT
   CMSHGRID_DP("Index: " & WSTR(index))
   m_Result = m_grid->RemoveItem(Index)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether clicking on a column or row header should
' cause the entire column or row to be selected.
' True: Default. When the user clicks the header, the entire column or row is selected. 
' False: When the user clicks the header, only the header is selected. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.AllowBigSelection () AS BOOLEAN
   CMSHGRID_DP("")
   DIM bAllowBigSelection AS VARIANT_BOOL
   m_Result = m_grid->get_AllowBigSelection(@bAllowBigSelection)
   PROPERTY = bAllowBigSelection
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.AllowBigSelection (BYVAL bAllowBigSelection AS BOOLEAN)
   CMSHGRID_DP(WSTR(bAllowBigSelection))
   m_Result = m_grid->put_AllowBigSelection(cast(VARIANT_BOOL, bAllowBigSelection))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether the user can use the mouse to resize rows
' and columns in the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.AllowUserResizing () AS AllowUserResizeSettings
   CMSHGRID_DP("")
   DIM bAllowUserResizing AS AllowUserResizeSettings
   m_Result = m_grid->get_AllowUserResizing(@bAllowUserResizing)
   PROPERTY = bAllowUserResizing
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.AllowUserResizing (BYVAL bAllowUserResizing AS AllowUserResizeSettings)
   CMSHGRID_DP(WSTR(bAllowUserResizing))
   m_Result = m_grid->put_AllowUserResizing(bAllowUserResizing)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the non-fixed cells.
' BackColor affects the color of all non-fixed cells. To set the background color of
' individual cells, use the CellBackColor property.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColor () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColor(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColor (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColor(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of a band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorBand(BandNumber, @clr)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorBand(BandNumber, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorBand () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorBand(0, @clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorBand (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorBand(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of a band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorHeader(BandNumber, @clr)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorHeader(BandNumber, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorHeader () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorHeader(0, @clr)
   CMSHGRID_DP("Coloe: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorHeader (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorHeader(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the indented area of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorIndent (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorIndent(0, @clr)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorIndent (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorIndent(0, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorIndent () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorIndent(0, @clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorIndent (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorIndent(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the fixed cells of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorFixed () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorFixed(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorFixed (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorFixed(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the selected cells of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorSel () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorSel(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorSel (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorSel(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorBkg () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorBkg(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorBkg (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorBkg(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the unpopulated area of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorUnpopulated () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_BackColorUnpopulated(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BackColorUnpopulated (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_BackColorUnpopulated(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text color for all non-fixed cells in the control.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColor () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_ForeColor(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColor (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_ForeColor(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text color for the data cells within a specific band (level) of a hierarchical display.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_ForeColorBand(BandNumber, @clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   m_Result = m_grid->put_ForeColorBand(BandNumber, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text color for all fixed cells in the control.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorFixed () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_ForeColorFixed(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorFixed (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_ForeColorFixed(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text color for the data cells within a specific band (level) of a hierarchical display.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_ForeColorHeader(BandNumber, @clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Color: " & HEX(clr))
   m_Result = m_grid->put_ForeColorHeader(BandNumber, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorHeader () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_ForeColorHeader(0, @clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorHeader (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_ForeColorHeader(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text color for cells that have been highlighted or selected by the user.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorSel () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_ForeColorSel(@clr)
   CMSHGRID_DP("Color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ForeColorSel (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("Color: " & HEX(clr))
   m_Result = m_grid->put_ForeColorSel(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the total number of rows in the grid.
' It is used both to set the capacity of the grid and to retrieve the current row count.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Rows () AS LONG
   DIM nRows AS LONG
   m_Result = m_grid->get_Rows(@nRows)
   CMSHGRID_DP("Rows: " & WSTR(nRows))
   PROPERTY = nRows
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Rows (BYVAL nRows AS LONG)
   CMSHGRID_DP("Rows: " & WSTR(nRows))
   m_Result = m_grid->put_Rows(nRows)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the total number of columns in the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Cols (BYVAL BandNumber AS LONG) AS LONG
   DIM nCols AS LONG
   m_Result = m_grid->get_Cols(BandNumber, @nCols)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Cols: " & WSTR(nCols))
   PROPERTY = nCols
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Cols (BYVAL BandNumber AS LONG, BYVAL nCols AS LONG)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " Cols: " & WSTR(nCols))
   m_Result = m_grid->put_Cols(BandNumber, nCols)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Cols () AS LONG
   DIM nCols AS LONG
   m_Result = m_grid->get_Cols(0, @nCols)
   CMSHGRID_DP("Cols: " & WSTR(nCols))
   PROPERTY = nCols
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Cols (BYVAL nCols AS LONG)
   CMSHGRID_DP("Cols: " & WSTR(nCols))
   m_Result = m_grid->put_Cols(0, nCols)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the total number of fixed rows in the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FixedRows () AS LONG
   DIM nRows AS LONG
   m_Result = m_grid->get_FixedRows(@nRows)
   CMSHGRID_DP("Rows: " & WSTR(nRows))
   PROPERTY = nRows
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FixedRows (BYVAL nRows AS LONG)
   CMSHGRID_DP("Rows: " & WSTR(nRows))
   m_Result = m_grid->put_FixedRows(nRows)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the total number of fixed columns in the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FixedCols () AS LONG
   DIM nCols AS LONG
   m_Result = m_grid->get_FixedCols(@nCols)
   CMSHGRID_DP("Cols: " & WSTR(nCols))
   PROPERTY = nCols
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FixedCols (BYVAL nCols AS LONG)
   CMSHGRID_DP("Cols: " & WSTR(nCols))
   m_Result = m_grid->put_FixedCols(nCols)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Allows you to align column headers independently of the data in the scrollable cells.
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FixedAlignment (BYVAL Index AS LONG) AS SHORT
   DIM alignment AS SHORT
   m_Result = m_grid->get_FixedAlignment(Index, @alignment)
   CMSHGRID_DP("Index: " & WSTR(Index) & " - Alignment: " & WSTR(alignment))
   PROPERTY = alignment
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FixedAlignment (BYVAL Index AS LONG, BYVAL alignment AS SHORT)
   CMSHGRID_DP("Index: " & WSTR(Index) & " - Alignment: " & WSTR(alignment))
   m_Result = m_grid->put_FixedAlignment(Index, alignment)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the row position of the active cell or the start of a selection.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Row () AS LONG
   DIM nRow AS LONG
   m_Result = m_grid->get_Row(@nRow)
   CMSHGRID_DP("Row: " & WSTR(nRow))
   PROPERTY = nRow
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Row (BYVAL nRow AS LONG)
   CMSHGRID_DP("Row: " & WSTR(nRow))
   m_Result = m_grid->put_Row(nRow)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the column position of the active cell or the start of a selection.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Col () AS LONG
   DIM nCol AS LONG
   m_Result = m_grid->get_Col(@nCol)
   CMSHGRID_DP("Col: " & WSTR(nCol))
   PROPERTY = nCol
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Col (BYVAL nCol AS LONG)
   CMSHGRID_DP("Col: " & WSTR(nCol))
   m_Result = m_grid->put_Col(nCol)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the start or end row for a range of cells. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowSel () AS LONG
   DIM nRow AS LONG
   m_Result = m_grid->get_RowSel(@nRow)
   CMSHGRID_DP("Row: " & WSTR(nRow))
   PROPERTY = nRow
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowSel (BYVAL nRow AS LONG)
   CMSHGRID_DP("Row: " & WSTR(nRow))
   m_Result = m_grid->put_RowSel(nRow)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the start or end column for a range of cells. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColSel () AS LONG
   DIM nCol AS LONG
   m_Result = m_grid->get_ColSel(@nCol)
   CMSHGRID_DP("Col: " & WSTR(nCol))
   PROPERTY = nCol
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColSel (BYVAL nCol AS LONG)
   CMSHGRID_DP("Col: " & WSTR(nCol))
   m_Result = m_grid->put_ColSel(nCol)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the uppermost visible row (other than a fixed row) in the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TopRow () AS LONG
   DIM nRow AS LONG
   m_Result = m_grid->get_TopRow(@nRow)
   CMSHGRID_DP("Row: " & WSTR(nRow))
   PROPERTY = nRow
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TopRow (BYVAL nRow AS LONG)
   CMSHGRID_DP("Row: " & WSTR(nRow))
   m_Result = m_grid->put_TopRow(nRow)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the left-most visible non fixed column in the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.LeftCol () AS LONG
   DIM nCol AS LONG
   m_Result = m_grid->get_LeftCol(@nCol)
   CMSHGRID_DP("Col: " & WSTR(nCol))
   PROPERTY = nCol
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.LeftCol (BYVAL nCol AS LONG)
   CMSHGRID_DP("Col: " & WSTR(nCol))
   m_Result = m_grid->put_LeftCol(nCol)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether lines are drawn between cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLines () AS GridLineSettings
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLines(@value)
   CMSHGRID_DP("settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLines (BYVAL value AS GridLineSettings)
   CMSHGRID_DP("settings: " & WSTR(value))
   m_Result = m_grid->put_GridLines(value)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether lines are drawn between fixed cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesFixed () AS GridLineSettings
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesFixed(@value)
   CMSHGRID_DP("settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesFixed (BYVAL value AS GridLineSettings)
   CMSHGRID_DP("settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesFixed(value)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether lines are drawn between fixed cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesBand (BYVAL BandNumber AS LONG) AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesBand(BandNumber, @value)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesBand (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesBand(BandNumber, value)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesBand () AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesBand(0, @value)
   CMSHGRID_DP(" settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesBand (BYVAL value AS GridLineSettings)
   CMSHGRID_DP(" settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesBand(0, value)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether lines are drawn within the header area
' of a specified band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesHeader (BYVAL BandNumber AS LONG) AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesHeader(BandNumber, @value)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesHeader (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesHeader(BandNumber, value)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesHeader () AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesHeader(0, @value)
   CMSHGRID_DP("settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesHeader (BYVAL value AS GridLineSettings)
   CMSHGRID_DP("settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesHeader(0, value)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether lines are drawn within the indented area
' of a specified band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesIndent (BYVAL BandNumber AS LONG) AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesIndent(BandNumber, @value)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesIndent (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesIndent(BandNumber, value)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesIndent () AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesIndent(0, @value)
   CMSHGRID_DP("settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesIndent (BYVAL value AS GridLineSettings)
   CMSHGRID_DP("settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesIndent(0, value)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether lines are drawn within the unpopulated
' areas of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesUnpopulated () AS GridLineSettings 
   DIM value AS GridLineSettings
   m_Result = m_grid->get_GridLinesUnpopulated(@value)
   CMSHGRID_DP("settings: " & WSTR(value))
   PROPERTY = value
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLinesUnpopulated (BYVAL value AS GridLineSettings)
   CMSHGRID_DP("settings: " & WSTR(value))
   m_Result = m_grid->put_GridLinesUnpopulated(value)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the line color used between the cells of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColor () AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColor(@clr)
   CMSHGRID_DP("color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColor (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("color: " & HEX(clr))
   m_Result = m_grid->put_GridColor(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the line color used between fixed cells of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorFixed () AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorFixed(@clr)
   CMSHGRID_DP("color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorFixed (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("color: " & HEX(clr))
   m_Result = m_grid->put_GridColorFixed(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the line color used for the "unpopulated" region—space within a hierarchical
' band structure that is reserved but currently empty. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorUnpopulated () AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorUnpopulated(@clr)
   CMSHGRID_DP("color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorUnpopulated (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("color: " & HEX(clr))
   m_Result = m_grid->put_GridColorUnpopulated(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the color of the gridlines specifically for a targeted hierarchical band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorBand(BandNumber, @clr)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - color: " & HEX(clr))
   m_Result = m_grid->put_GridColorBand(BandNumber, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorBand () AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorBand(0, @clr)
   CMSHGRID_DP("color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorBand (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("color: " & HEX(clr))
   m_Result = m_grid->put_GridColorBand(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the color of the gridlines specifically for the header area of a
' designated hierarchical band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorHeader(BandNumber, @clr)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - color: " & HEX(clr))
   m_Result = m_grid->put_GridColorHeader(BandNumber, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorHeader () AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorHeader(0, @clr)
   CMSHGRID_DP("color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorHeader (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("color: " & HEX(clr))
   m_Result = m_grid->put_GridColorHeader(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the color within the indented area of a specific hierarchical band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorIndent (BYVAL BandNumber AS LONG) AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorIndent(BandNumber, @clr)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorIndent (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - color: " & HEX(clr))
   m_Result = m_grid->put_GridColorIndent(BandNumber, clr)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorIndent () AS OLE_COLOR 
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_GridColorIndent(0, @clr)
   CMSHGRID_DP("color: " & HEX(clr))
   PROPERTY = clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridColorIndent (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP("color: " & HEX(clr))
   m_Result = m_grid->put_GridColorIndent(0, clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the height of the specified row, in twips.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowHeight (BYVAL Index AS LONG) AS LONG
   DIM rHeight AS LONG
   m_Result = m_grid->get_RowHeight(Index, @rHeight)
   CMSHGRID_DP("index: " & WSTR(index) & " - height: " & WSTR(rHeight))
   RETURN rHeight
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowHeight (BYVAL Index AS LONG, BYVAL rHeight AS LONG)
   CMSHGRID_DP("index: " & WSTR(index) & " - height: " & WSTR(rHeight))
   m_Result = m_grid->put_RowHeight(Index, rHeight)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the minimum row height for the entire control, in twips.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowHeightMin () AS LONG
   DIM rHeightMin AS LONG
   m_Result = m_grid->get_RowHeightMin(@rHeightMin)
   CMSHGRID_DP("height: " & WSTR(rHeightMin))
   RETURN rHeightMin
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowHeightMin (BYVAL rHeightMin AS LONG)
   CMSHGRID_DP("height: " & WSTR(rHeightMin))
   m_Result = m_grid->put_RowHeightMin(rHeightMin)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the width of the column in the specified band, in twips.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColWidth (BYVAL Index AS LONG) AS LONG
   DIM nWidth AS LONG
   m_Result = m_grid->get_ColWidth(Index, 0, @nWidth)
   CMSHGRID_DP("index: " & WSTR(index) & " - width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColWidth (BYVAL Index AS LONG, BYVAL nWidth AS LONG)
   CMSHGRID_DP("index: " & WSTR(index) & " - width: " & WSTR(nWidth))
   m_Result = m_grid->put_ColWidth(Index, 0, nWidth)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColWidth2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0) AS LONG
   DIM nWidth AS LONG
   m_Result = m_grid->get_ColWidth(Index, BandNumber, @nWidth)
   CMSHGRID_DP("index: " & WSTR(index) & " - BAndNumber" & WSTR(BandNumber) & " - width: " & WSTR(nWidth))
   RETURN nWidth
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColWidth2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL nWidth AS LONG) AS HRESULT
   CMSHGRID_DP("index: " & WSTR(index) & " - BAndNumber" & WSTR(BandNumber) & " - width: " & WSTR(nWidth))
   m_Result = m_grid->put_ColWidth(Index, BandNumber, nWidth)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a Boolean value indicating if any part of the row is visible to the user. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowIsVisible (BYVAL Index AS LONG) AS BOOLEAN
   DIM isVisible AS VARIANT_BOOL
   m_Result = m_grid->get_RowIsVisible(Index, @isVisible)
   CMSHGRID_DP("index: " & WSTR(index) & " - visible: " & WSTR(isVisible))
   RETURN isVisible
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns a Boolean value indicating if any part of the column is visible to the user. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColIsVisible (BYVAL Index AS LONG) AS BOOLEAN
   DIM isVisible AS VARIANT_BOOL
   m_Result = m_grid->get_ColIsVisible(Index, @isVisible)
   CMSHGRID_DP("index: " & WSTR(index) & " - visible: " & WSTR(isVisible))
   RETURN isVisible
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the distance, in twips, between the upper-left corner of the grid and the
' upper-left corner of a specified row.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowPos (BYVAL Index AS LONG) AS LONG
   DIM nPos AS LONG
   m_Result = m_grid->get_RowPos(Index, @nPos)
   CMSHGRID_DP("index: " & WSTR(index) & " - pos: " & WSTR(nPos))
   RETURN nPos
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the distance, in twips, between the upper-left corner of the control and the
' upper-left corner of a specified column.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColPos (BYVAL Index AS LONG) AS LONG
   DIM nPos AS LONG
   m_Result = m_grid->get_ColPos(Index, @nPos)
   CMSHGRID_DP("index: " & WSTR(index) & " - pos: " & WSTR(nPos))
   RETURN nPos
END PROPERTY
' ========================================================================================

' ========================================================================================
' Sets the position of an MSHFlexGrid row, allowing you to move rows to specific positions.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowPosition (BYVAL Index AS LONG, BYVAL newPos AS LONG)
   CMSHGRID_DP("index: " & WSTR(index) & " - newPos: " & WSTR(newPos))
   m_Result = m_grid->put_RowPosition(Index, newPos)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Sets the position of an MSHFlexGrid column, allowing you to move columns to specific positions.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColPosition (BYVAL Index AS LONG, BYVAL newPos AS LONG)
   CMSHGRID_DP("index: " & WSTR(index) & " - newPos: " & WSTR(newPos))
   m_Result = m_grid->put_ColPosition(Index, 0, newPos)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColPosition2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL newPos AS LONG) AS HRESULT
   CMSHGRID_DP("index: " & WSTR(index) & " - BandNumber: " & WSTR(BAndNUmber) & " - newPos: " & WSTR(newPos))
   m_Result = m_grid->put_ColPosition(Index, BandNumber, newPos)
   FUNCTION = m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines which rows can have their contents merged.
' This property must be True to use the MergeCells property.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MergeRow (BYVAL Index AS LONG) AS BOOLEAN
   DIM bRes AS VARIANT_BOOL
   m_Result = m_grid->get_MergeRow(Index, @bRes)
   CMSHGRID_DP("index: " & WSTR(index) & " - merge: " & WSTR(bRes))
   RETURN bRes
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MergeRow (BYVAL Index AS LONG, BYVAL merge AS BOOLEAN)
   CMSHGRID_DP("index: " & WSTR(index) & " - merge: " & WSTR(merge))
   m_Result = m_grid->put_MergeRow(Index, cast(VARIANT_BOOL, merge))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines which columns can have their contents merged.
' This property must be True to use the MergeCells property.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MergeCol (BYVAL Index AS LONG) AS BOOLEAN
   DIM bRes AS VARIANT_BOOL
   m_Result = m_grid->get_MergeCol(Index, @bRes)
   CMSHGRID_DP("index: " & WSTR(index) & " - merge: " & WSTR(bRes))
   RETURN bRes
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MergeCol (BYVAL Index AS LONG, BYVAL merge AS BOOLEAN)
   CMSHGRID_DP("index: " & WSTR(index) & " - merge: " & WSTR(merge))
   m_Result = m_grid->put_MergeCol(Index, cast(VARIANT_BOOL, merge))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether cells with the same contents should be
' grouped in a single cell spanning multiple rows or columns.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MergeCells () AS MergeCellsSettings
   DIM merge AS MergeCellsSettings
   m_Result = m_grid->get_MergeCells(@merge)
   CMSHGRID_DP(" settings: " & WSTR(merge))
   RETURN merge
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MergeCells (BYVAL merge AS MergeCellsSettings)
   CMSHGRID_DP(" settings: " & WSTR(merge))
   m_Result = m_grid->put_MergeCells(merge)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Clears the contents of the MSHFlexGrid. This includes all text, pictures, and cell formatting.
' This method does not affect the number of rows and columns within the MSHFlexGrid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.Clear () AS HRESULT
   m_Result = m_grid->Clear
   CMSHGRID_DP(" hResult: " & WSTR(m_Result))
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Reset the control's internal column mapping and band information when it is bound to a data source.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ClearStructure () AS HRESULT
   m_Result = m_grid->ClearStructure
   CMSHGRID_DP(" hResult: " & WSTR(m_Result))
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' It ensures that any pending visual changes—such as property updates, cell coloring, or
' text changes—are rendered on the screen without waiting for the operating system's standard paint cycle.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.Refresh () AS HRESULT
   m_Result = m_grid->Refresh
   CMSHGRID_DP(" hResult: " & WSTR(m_Result))
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines which columns can have their contents merged.
' This property must be True to use the MergeCells property.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Redraw () AS BOOLEAN
   DIM bRedraw AS VARIANT_BOOL
   m_Result = m_grid->get_Redraw(@bRedraw)
   CMSHGRID_DP(" Result: " & WSTR(bRedraw))
   RETURN bRedraw
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Redraw (BYVAL bRedraw AS BOOLEAN)
   CMSHGRID_DP("Redraw: " & WSTR(bRedraw))
   m_Result = m_grid->put_Redraw(cast(VARIANT_BOOL, bRedraw))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text contents of an arbitrary cell.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextArray (BYVAL Index AS LONG) AS DWSTRING
   CMSHGRID_DP("Index: " & WSTR(Index))
   DIM bstrText AS BSTR
   m_Result = m_grid->get_TextArray(Index, @bstrText)
   DIM dws AS DWSTRING = *bstrText
   SysFreeString bstrText
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextArray (BYVAL Index AS LONG, BYREF wszText AS WSTRING)
   CMSHGRID_DP("Index: " & WSTR(Index))
   DIM bstrText AS AFX_BSTR = SysAllocString(wszText)
   m_Result = m_grid->put_TextArray(Index, bstrText)
   SysFreeString bstrText
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the text contents of an arbitrary cell.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.TextMatrix (BYVAL nRow AS LONG, BYVAL nCol AS LONG) AS DWSTRING
   CMSHGRID_DP("Row: " & WSTR(nRow) & " - Col: " & WSTR(nCol))
   DIM bstrText AS BSTR
   m_Result = m_grid->get_TextMatrix(nRow, nCol, @bstrText)
   DIM dws AS DWSTRING = *bstrText
   SysFreeString bstrText
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.TextMatrix (BYVAL nRow AS LONG, BYVAL nCol AS LONG, BYREF wszText AS WSTRING) AS HRESULT
   CMSHGRID_DP("Row: " & WSTR(nRow) & " - Col: " & WSTR(nCol))
   DIM bstrText AS AFX_BSTR = SysAllocString(wszText)
   m_Result = m_grid->put_TextMatrix(nRow, nCol, bstrText)
   SysFreeString bstrText
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines which columns can have their contents merged.
' This property must be True to use the MergeCells property.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Text () AS DWSTRING
   CMSHGRID_DP("")
   DIM bstrText AS BSTR
   m_Result = m_grid->get_Text(@bstrText)
   DIM dws AS DWSTRING = *bstrText
   SysFreeString bstrText
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Text (BYREF wszText AS WSTRING)
   CMSHGRID_DP("")
   DIM bstrText AS AFX_BSTR = SysAllocString(wszText)
   m_Result = m_grid->put_Text(bstrText)
   SysFreeString bstrText
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the column widths, alignments, fixed row text, and fixed column text of the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FormatString () AS DWSTRING
   CMSHGRID_DP("")
   DIM bstrText AS BSTR
   m_Result = m_grid->get_FormatString(@bstrText)
   DIM dws AS DWSTRING = *bstrText
   SysFreeString bstrText
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FormatString (BYREF wszText AS WSTRING)
   CMSHGRID_DP("")
   DIM bstrText AS AFX_BSTR = SysAllocString(wszText)
   m_Result = m_grid->put_FormatString(bstrText)
   SysFreeString bstrText
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the data source.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.DataSource () AS Afx_IDataSource PTR
   DIM Data_Source AS Afx_IDataSource PTR
   m_Result = m_grid->get_DataSource(@Data_Source)
   CMSHGRID_DP(WSTR(Data_Source))
   RETURN Data_Source
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.DataSource (BYVAL Data_Source AS Afx_IDataSource PTR)
   CMSHGRID_DP(WSTR(Data_Source))
   m_Result = m_grid->putref_DataSource(Data_Source)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the data member.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.DataMember () AS DWSTRING
   CMSHGRID_DP("")
   DIM Data_Member AS BSTR
   m_Result = m_grid->get_DataMember(@Data_Member)
   DIM dws AS DWSTRING = *Data_Member
   SysFreeString Data_Member
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.DataMember (BYREF wszDataMember AS WSTRING)
   CMSHGRID_DP("")
   DIM bstrDataMember AS AFX_BSTR = SysAllocString(wszDataMember)
   m_Result = m_grid->put_DataMember(bstrDataMember)
   SysFreeString bstrDataMember
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the recordset.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Recordset () AS Afx_ADORecordset PTR
   DIM rs AS Afx_ADORecordset PTR
   m_Result = m_grid->get_Recordset(@rs)
   CMSHGRID_DP(WSTR(rs))
   RETURN rs
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Recordset (BYVAL rs AS Afx_ADORecordset PTR)
   CMSHGRID_DP(WSTR(rs))
   m_Result = m_grid->putref_Recordset(rs)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Rowset () AS VARIANT
   DIM v AS VARIANT
   m_Result = m_grid->get_Rowset(@v)
   CMSHGRID_DP(WSTR(""))
   RETURN v
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Rowset (BYVAL v AS VARIANT)
   CMSHGRID_DP(WSTR(""))
   m_Result = m_grid->putref_Rowset(v)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether setting the Text property, or one of the
' cell formatting properties, applies the change to all selected cells within the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FillStyle () AS FillStyleSettings
   DIM style AS FillStyleSettings
   m_Result = m_grid->get_FillStyle(@style)
   CMSHGRID_DP(WSTR("settings: " & WSTR(style)))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FillStyle (BYVAL style AS FillStyleSettings)
   CMSHGRID_DP(WSTR("settings: " & WSTR(style)))
   m_Result = m_grid->put_FillStyle(style)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the contents of the cells in the MSHFlexGrid's selected region.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Clip () AS DWSTRING
   CMSHGRID_DP("")
   DIM bstrClip AS BSTR
   m_Result = m_grid->get_Clip(@bstrClip)
   DIM dws AS DWSTRING = *bstrClip
   SysFreeString bstrClip
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Clip (BYREF wszClip AS WSTRING)
   CMSHGRID_DP("")
   DIM bstrClip AS AFX_BSTR = SysAllocString(wszClip)
   m_Result = m_grid->put_Clip(bstrClip)
   SysFreeString bstrClip
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether an MSHFlexGrid should allow regular cell
' selection, selection by rows, or selection by columns.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.SelectionMode () AS SelectionModeSettings
   DIM selMode AS SelectionModeSettings
   m_Result = m_grid->get_SelectionMode(@selMode)
   CMSHGRID_DP(WSTR("settings: " & WSTR(selMode)))
   RETURN selMode
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.SelectionMode (BYVAL selMode AS SelectionModeSettings)
   CMSHGRID_DP(WSTR("settings: " & WSTR(selMode)))
   m_Result = m_grid->put_SelectionMode(selMode)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Sets a value that sorts selected rows according to selected criteria.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Sort (BYVAL settings AS SHORT)
   CMSHGRID_DP(WSTR("settings: " & WSTR(settings)))
   m_Result = m_grid->put_Sort(settings)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Specifies whether the grid is surrounded by a single-line border or no border at all.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BorderStyle () AS BorderStyleSettings
   DIM style AS BorderStyleSettings
   m_Result = m_grid->get_BorderStyle(@style)
   CMSHGRID_DP(WSTR("settings: " & WSTR(style)))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BorderStyle (BYVAL style AS BorderStyleSettings)
   CMSHGRID_DP(WSTR("settings: " & WSTR(style)))
   m_Result = m_grid->put_BorderStyle(style)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the paint style of the control.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Appearance () AS AppearanceSettings
   DIM app AS AppearanceSettings
   m_Result = m_grid->get_Appearance(@app)
   CMSHGRID_DP(WSTR("settings: " & WSTR(app)))
   RETURN app
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Appearance (BYVAL app AS AppearanceSettings)
   CMSHGRID_DP(WSTR("settings: " & WSTR(app)))
   m_Result = m_grid->put_Appearance(app)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Determines whether the grid can respond to user-generated events such as mouse clicks,
' keyboard navigation, or scrolling.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Enabled () AS BOOLEAN
   CMSHGRID_DP("")
   DIM bEnabled AS VARIANT_BOOL
   m_Result = m_grid->get_Enabled(@bEnabled)
   RETURN bEnabled
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Enabled (BYVAL bEnabled AS BOOLEAN)
   CMSHGRID_DP("")
   m_Result = m_grid->put_Enabled(cast(VARIANT_BOOL, bEnabled))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether a cell displays multiple lines of text
' or one long line of text.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.WordWrap () AS BOOLEAN
   DIM bWrap AS VARIANT_BOOL
   m_Result = m_grid->get_WordWrap(@bWrap)
   CMSHGRID_DP(WSTR(bWrap))
   RETURN bWrap
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.WordWrap (BYVAL bWrap AS BOOLEAN)
   CMSHGRID_DP(WSTR(bWrap))
   m_Result = m_grid->put_WordWrap(cast(VARIANT_BOOL, bWrap))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether the MSHFlexGrid should draw a focus
' rectangle around the current cell.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FocusRect () AS FocusRectSettings
   DIM bFocusRect AS FocusRectSettings
   m_Result = m_grid->get_FocusRect(@bFocusRect)
   CMSHGRID_DP("settings: " & WSTR(bFocusRect))
   RETURN bFocusRect
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FocusRect (BYVAL bFocusRect AS FocusRectSettings)
   CMSHGRID_DP("settings: " & WSTR(bFocusRect))
   m_Result = m_grid->put_FocusRect(bFocusRect)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Determines whether selected cells appear highlighted within the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Highlight () AS HighLightSettings
   DIM bHighlight AS HighLightSettings
   m_Result = m_grid->get_HighLight(@bHighlight)
   CMSHGRID_DP("settings: " & WSTR(bHighlight))
   RETURN bHighlight
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Highlight (BYVAL bHighlight AS HighLightSettings)
   CMSHGRID_DP("settings: " & WSTR(bHighlight))
   m_Result = m_grid->put_HighLight(bHighlight)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets an arbitrary long value associated with each row. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowData (BYVAL Index AS LONG) AS LONG
   DIM nData AS LONG
   m_Result = m_grid->get_RowData(Index, @nData)
   CMSHGRID_DP("index: " & WSTR(index) & " - data: " & WSTR(nData))
   RETURN nData
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowData (BYVAL Index AS LONG, BYVAL nData AS LONG)
   CMSHGRID_DP("index: " & WSTR(index) & " - data: " & WSTR(nData))
   m_Result = m_grid->put_RowData(Index, nData)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets an arbitrary long value associated with each band. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandData (BYVAL band AS LONG) AS LONG
   DIM nData AS LONG
   m_Result = m_grid->get_BandData(band, @nData)
   CMSHGRID_DP("band: " & WSTR(band) & " - data: " & WSTR(nData))
   RETURN nData
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandData (BYVAL band AS LONG, BYVAL nData AS LONG)
   CMSHGRID_DP("band: " & WSTR(band) & " - data: " & WSTR(nData))
   m_Result = m_grid->put_BandData(band, nData)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Specifies how the bands display within the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandDisplay () AS BandDisplaySettings
   DIM settings AS BandDisplaySettings
   m_Result = m_grid->get_BandDisplay(@settings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   RETURN settings
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandDisplay (BYVAL settings AS BandDisplaySettings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   m_Result = m_grid->put_BandDisplay(settings)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns and sets a value that determines whether the row in the current band can be
' expanded and collapsed.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandExpandable (BYVAL BandNumber AS LONG) AS BOOLEAN
   DIM bExpandable AS VARIANT_BOOL
   m_Result = m_grid->get_BandExpandable(BandNumber, @bExpandable)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - expandable: " & WSTR(bExpandable))
   RETURN bExpandable
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandExpandable (BYVAL BandNumber AS LONG, BYVAL bExpandable AS BOOLEAN)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - expandable: " & WSTR(bExpandable))
   m_Result = m_grid->put_BandExpandable(BandNumber, cast(VARIANT_BOOL, bExpandable))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Specify whether the current row is expanded or collapsed. The current row is defined by
' the Col and Row properties.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowExpandable () AS BOOLEAN
   DIM bExpandable AS VARIANT_BOOL
   m_Result = m_grid->get_RowExpandable(@bExpandable)
   CMSHGRID_DP(WSTR(bExpandable))
   RETURN bExpandable
END PROPERTY
' ========================================================================================

' ========================================================================================
' Indicates or sets whether the current row is expanded. The current row is determined
' by the Row and Col properties.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowExpanded () AS BOOLEAN
   DIM bRowExpanded AS VARIANT_BOOL
   m_Result = m_grid->get_RowExpanded (@bRowExpanded)
   CMSHGRID_DP(WSTR(bRowExpanded))
   RETURN bRowExpanded
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowExpanded (BYVAL bRowExpanded AS BOOLEAN)
   CMSHGRID_DP(WSTR(bRowExpanded))
   m_Result = m_grid->put_RowExpanded(cast(VARIANT_BOOL, bRowExpanded))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Collapses all rows of the specified band within the MSHFlexGrid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.CollapseAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber))
   m_Result = m_grid->CollapseAll(BandNumber)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Collapses all rows of the specified band within the MSHFlexGrid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ExpandAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber))
   m_Result = m_grid->ExpandAll(BandNumber)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets the preferred width, in pixels, for the current line.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidth () AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidth (@nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidth (BYVAL nWidth AS SHORT)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidth(nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the preferred width, in pixels, of the fixed areas of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthFixed () AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthFixed (@nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthFixed (BYVAL nWidth AS SHORT)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthFixed(nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the preferred width, in pixels, of the unpopulated areas of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthUnpopulated () AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthUnpopulated (@nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthUnpopulated (BYVAL nWidth AS SHORT)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthUnpopulated(nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the preferred width, in pixels, of the bands of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthBand (BYVAL BandNumber AS LONG) AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthBand (BandNumber, @nWidth)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthBand (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthBand(BandNumber, nWidth)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthBand () AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthBand (0, @nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthBand (BYVAL nWidth AS SHORT)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthBand(0, nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the preferred width, in pixels, of the headers of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthHeader (BYVAL BandNumber AS LONG) AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthHeader (BandNumber, @nWidth)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthHeader (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthHeader(BandNumber, nWidth)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthHeader () AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthHeader (0, @nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthHeader (BYVAL nWidth AS SHORT)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthHeader(0, nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the preferred width, in pixels, of the grid lines drawn within the
' indentation area of the hierarchical display. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthIndent (BYVAL BandNumber AS LONG) AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthIndent (BandNumber, @nWidth)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthIndent (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthIndent(BandNumber, nWidth)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthIndent () AS SHORT
   DIM nWidth AS SHORT
   m_Result = m_grid->get_GridLineWidthIndent (0, @nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.GridLineWidthIndent (BYVAL nWidth AS SHORT)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   m_Result = m_grid->put_GridLineWidthIndent(0, nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the total number of bands in an MSHFlexGrid. The MSHFlexGrid always has a minimum
' of one band. When the MSHFlexGrid is bound to a standard Recordset, the entire MSHFlexGrid
' is treated as one band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.Bands () AS LONG
   DIM nBands AS LONG
   m_Result = m_grid->get_Bands (@nBands)
   CMSHGRID_DP("bands: " & WSTR(nBands))
   RETURN nBands
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the band number that contains the current cell. The band numbers begin at 0.
' The current cell is defined by the Col and Row properties. 
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.BandLevel () AS LONG
   DIM nBandLevel AS LONG
   m_Result = m_grid->get_BandLevel(@nBandLevel)
   CMSHGRID_DP(WSTR(nBandLevel))
   RETURN nBandLevel
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the band number that contains the current cell. The band numbers begin at 0.
' The current cell is defined by the Col and Row properties. 
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.BandColIndex () AS LONG
   DIM Index AS LONG
   m_Result = m_grid->BandColIndex(@Index)
   CMSHGRID_DP(WSTR(Index))
   RETURN Index
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the number of columns by which to indent a band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandIndent (BYVAL BandNumber AS LONG) AS LONG
   DIM nCols AS LONG
   m_Result = m_grid->get_BandIndent(BandNumber, @nCols)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " - cols: " & WSTR(nCols))
   RETURN nCols
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandIndent (BYVAL BandNumber AS LONG, BYVAL nCols AS LONG)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNUmber) & " - cols: " & WSTR(nCols))
   m_Result = m_grid->put_BandIndent(BandNumber, nCols)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandIndent () AS LONG
   DIM nCols AS LONG
   m_Result = m_grid->get_BandIndent (0, @nCols)
   CMSHGRID_DP(WSTR(nCols))
   RETURN nCols
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.BandIndent (BYVAL nCols AS LONG)
   CMSHGRID_DP(WSTR(nCols))
   m_Result = m_grid->put_BandIndent(0, nCols)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the name of the specified band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.GetBandName (BYVAL BandNumber AS LONG) AS DWSTRING
   CMSHGRID_DP(WSTR(BandNumber))
   DIM dwsName AS DWSTRING, bstrName AS AFX_BSTR
   m_Result = m_grid->GetBandName(BandNumber, @bstrName)
   dwsName = *bstrName
   RETURN dwsName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of columns of the specified band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.CountColumnsInBand (BYVAL BandNumber AS LONG) AS LONG
   DIM nCols AS LONG
   m_Result = m_grid->CountColumnsInBand(BandNumber, @nCols)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - Cols: " & WSTR(nCols))
   RETURN nCols
END FUNCTION
' ========================================================================================

' ========================================================================================
' Forces the grid to collect or refresh internal band and field name information from the
' bound hierarchical Recordset.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.CollectBandFieldNameInfo (BYVAL force_collection AS LONG) AS HRESULT
   CMSHGRID_DP(WSTR(force_collection))
   m_Result = m_grid->CollectBandFieldNameInfo(force_collection)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves all metadata for a specific column within a specific band (hierarchical level).
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.GetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, _
BYVAL ColName AS BSTR PTR, BYVAL Caption AS BSTR PTR, BYVAL Hidden AS VARIANT_BOOL PTR, _
BYVAL RowsetColIndex AS LONG PTR, BYVAL Alignment AS SHORT PTR) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber))
   m_Result = m_grid->GetColumnInBandInfo(BandNumber, UIIndex, ColName, Caption, Hidden, RowsetColIndex, Alignment)
   RETURN m_Result
END FUNCTION
' ========================================================================================
' ========================================================================================
' Sets or updates the metadata for a specific column within a specific band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.SetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, _
BYVAL ColName AS BSTR, BYVAL Caption AS BSTR, BYVAL Hidden AS VARIANT_BOOL, _
BYVAL RowsetColIndex AS LONG, BYVAL Alignment AS SHORT) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber))
   m_Result = m_grid->SetColumnInBandInfo(BandNumber, UIIndex, ColName, Caption, Hidden, RowsetColIndex, Alignment)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Applies any pending changes to the internal band/field metadata previously modified
' through internal methods such as SetColumnInBandInfo.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ApplyBandFieldNameInfoChanges () AS HRESULT
   CMSHGRID_DP("")
   m_Result = m_grid->ApplyBandFieldNameInfoChanges
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the name of the field bound to the specified column in the specified band. 
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.DataField (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS DWSTRING
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx))
   DIM dtField AS AFX_BSTR, dws AS DWSTRING
   m_Result = m_grid->get_DataField(BandNumber, BandColIdx, @dtField)
   dws = *dtField
   SysFreeString dtField
   RETURN dws
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets a value that describes the sizing mode of the rows in the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowSizingMode () AS RowSizingSettings
   DIM sizingMode AS RowSizingSettings
   m_Result = m_grid->get_RowSizingMode (@sizingMode)
   CMSHGRID_DP("sizin gmode: " & WSTR(sizingMode))
   RETURN sizingMode
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RowSizingMode (BYVAL sizingMode AS RowSizingSettings)
   CMSHGRID_DP("sizin gmode: " & WSTR(sizingMode))
   m_Result = m_grid->put_RowSizingMode(sizingMode)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets how text wraps or is truncated within a specific column.
' Unlike the global WordWrap property, this allows for more granular, column-level control. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColWordWrapOption (BYVAL Index AS LONG) AS WordWrapSettings
   DIM opt AS SHORT
   m_Result = m_grid->get_ColWordWrapOption(Index, @opt)
   CMSHGRID_DP("index: " & WSTR(index) & " - settings: " & WSTR(opt))
   RETURN opt
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColWordWrapOption (BYVAL Index AS LONG, BYVAL opt AS WordWrapSettings)
   CMSHGRID_DP("index: " & WSTR(index) & " - settings: " & WSTR(opt))
   m_Result = m_grid->put_ColWordWrapOption(Index, cast(SHORT, opt))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets how text wraps or is truncated within a specific band.
' Unlike the global WordWrap property, which targets a single column index, this property
' applies the specified wrapping rule to every column in the designated band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS WordWrapSettings
   DIM opt AS SHORT
   m_Result = m_grid->get_ColWordWrapOptionBand(BandNumber, BandColIdx, @opt)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx))
   RETURN opt
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYVAL opt AS WordWrapSettings) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - setting: " & WSTR(opt))
   m_Result = m_grid->put_ColWordWrapOptionBand(BandNumber, BandColIdx, cast(SHORT, opt))
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets how text wraps or is truncated within a specific column header.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS WordWrapSettings
   DIM opt AS SHORT
   m_Result = m_grid->get_ColWordWrapOptionHeader(BandNumber, BandColIdx, @opt)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - setting: " & WSTR(opt))
   RETURN opt
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYVAL opt AS WordWrapSettings) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - setting: " & WSTR(opt))
   m_Result = m_grid->put_ColWordWrapOptionHeader(BandNumber, BandColIdx, cast(SHORT, opt))
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets how text wraps or is truncated within the fixed columns (the non-scrolling
' columns usually located on the far left of the grid).
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColWordWrapOptionFixed (BYVAL Index AS LONG) AS WordWrapSettings
   DIM opt AS SHORT
   m_Result = m_grid->get_ColWordWrapOptionFixed(Index, @opt)
   CMSHGRID_DP("index: " & WSTR(Index) & " - setting: " & WSTR(opt))
   RETURN opt
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColWordWrapOptionFixed (BYVAL Index AS LONG, BYVAL opt AS WordWrapSettings)
   CMSHGRID_DP("index: " & WSTR(Index) & " - setting: " & WSTR(opt))
   m_Result = m_grid->put_ColWordWrapOptionFixed(Index, cast(SHORT, opt))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the zero-based index of the row under the mouse pointer.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.MouseRow () AS LONG
   DIM nRow AS LONG
   m_Result = m_grid->get_MouseRow(@nRow)
   CMSHGRID_DP("row: " & WSTR(nRow))
   RETURN nRow
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the zero-based index of the column under the mouse pointer.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.MouseCol () AS LONG
   DIM nCol AS LONG
   m_Result = m_grid->get_MouseCol(@nCol)
   CMSHGRID_DP("col: " & WSTR(nCol))
   RETURN nCol
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets the default arrow cursor to different standard system shapes or a custom image. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MousePointer () AS MousePointerSettings
   DIM settings AS MousePointerSettings
   m_Result = m_grid->get_MousePointer(@settings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   RETURN settings
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MousePointer (BYVAL settings AS MousePointerSettings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   m_Result = m_grid->put_MousePointer(settings)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a custom image (typically an .ico or .cur file) to the mouse cursor when
' it is positioned over the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MouseIcon () AS IPicture PTR
   DIM pic AS IPicture PTR
   m_Result = m_grid->get_MouseIcon(@pic)
   CMSHGRID_DP("IPicture PTR: " & WSTR(pic))
   RETURN pic
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.MouseIcon (BYVAL pic AS IPicture PTR)
   CMSHGRID_DP("IPicture PTR: " & WSTR(pic))
   m_Result = m_grid->putref_MouseIcon(pic)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Specifies whether headers should display for the specified band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColHeader (BYVAL BandNumber AS LONG) AS ColHeaderSettings
   DIM settings AS ColHeaderSettings
   m_Result = m_grid->get_ColHeader(BandNumber, @settings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(settings))
   RETURN settings
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColHeader (BYVAL BandNumber AS LONG, BYVAL settings AS ColHeaderSettings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - settings: " & WSTR(settings))
   m_Result = m_grid->put_ColHeader(BandNumber, settings)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColHeader () AS ColHeaderSettings
   DIM settings AS ColHeaderSettings
   m_Result = m_grid->get_ColHeader(0, @settings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   RETURN settings
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColHeader (BYVAL settings AS ColHeaderSettings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   m_Result = m_grid->put_ColHeader(0, settings)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Specifies the caption to display in the header of the specified column and band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS DWSTRING
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx))
   DIM bstrCaption AS AFX_BSTR, dws AS DWSTRING
   m_Result = m_grid->get_ColHeaderCaption(BandNumber, BandColIdx, @bstrCaption)
   dws = *bstrCaption
   SysFreeString bstrCaption
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYREF wszCaption AS WSTRING) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx))
   DIM bstrCaption AS AFX_BSTR = SysAllocString(wszCaption)
   m_Result = m_grid->put_ColHeaderCaption(BandNumber, BandColIdx, bstrCaption)
   SysFreeString bstrCaption
   RETURN m_Result
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColHeaderCaption (BYVAL BandColIdx AS LONG) AS DWSTRING
   CMSHGRID_DP("BandColIdx: " & WSTR(BandColIdx))
   DIM bstrCaption AS AFX_BSTR, dws AS DWSTRING
   m_Result = m_grid->get_ColHeaderCaption(0, BandColIdx, @bstrCaption)
   dws = *bstrCaption
   SysFreeString bstrCaption
   RETURN dws
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColHeaderCaption (BYVAL BandColIdx AS LONG, BYREF wszCaption AS WSTRING) AS HRESULT
   CMSHGRID_DP("BandColIdx: " & WSTR(BandColIdx))
   DIM bstrCaption AS AFX_BSTR = SysAllocString(wszCaption)
   m_Result = m_grid->put_ColHeaderCaption(0, BandColIdx, bstrCaption)
   SysFreeString bstrCaption
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether an MSHFlexGrid has horizontal and/or vertical scroll bars.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ScrollBars () AS ScrollBarsSettings
   DIM settings AS ScrollBarsSettings
   m_Result = m_grid->get_ScrollBars(@settings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   RETURN settings
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ScrollBars (BYVAL settings AS ScrollBarsSettings)
   CMSHGRID_DP("settings: " & WSTR(settings))
   m_Result = m_grid->put_ScrollBars(settings)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines whether the MSHFlexGrid should scroll its contents
' while the user moves the scroll box along the scroll bars.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ScrollTrack () AS BOOLEAN
   DIM bTrack AS VARIANT_BOOL
   m_Result = m_grid->get_ScrollTrack(@bTrack)
   CMSHGRID_DP(WSTR(bTrack))
   RETURN bTrack
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ScrollTrack (BYVAL bTrack AS BOOLEAN)
   CMSHGRID_DP(WSTR(bTrack))
   m_Result = m_grid->put_ScrollTrack(cast(VARIANT_BOOL, bTrack))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Determines how the grid acts as a "drop target" for OLE drag-and-drop operations, such
' as dragging files from Windows Explorer or text from another application into the grid. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.OLEDropMode () AS OLEDropConstants
   DIM dropMode AS OLEDropConstants
   m_Result = m_grid->get_OLEDropMode(@dropMode)
   CMSHGRID_DP(WSTR(dropMode))
   RETURN dropMode
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.OLEDropMode (BYVAL dropMode AS OLEDropConstants)
   CMSHGRID_DP(WSTR(dropMode))
   m_Result = m_grid->put_OLEDropMode(dropMode)
END PROPERTY
' ========================================================================================

' ========================================================================================
' The OLEDrag method and OLEDragMode property enable the grid to act as a source for OLE
' drag-and-drop operations, allowing data to be dragged from the grid to other controls or
' applications.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.OLEDrag () AS HRESULT
   CMSHGRID_DP("")
   m_Result = m_grid->OLEDrag
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets the three-dimensional style for text within a specific band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleBand (BYVAL BandNumber AS LONG) AS TextStyleSettings
   DIM style AS TextStyleSettings
   m_Result = m_grid->get_TextStyleBand(BandNumber, @style)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - style: " & WSTR(style))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleBand (BYVAL BandNumber AS LONG, BYVAL style AS TextStyleSettings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - style: " & WSTR(style))
   m_Result = m_grid->put_TextStyleBand(BandNumber, style)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleBand () AS TextStyleSettings
   DIM style AS TextStyleSettings
   m_Result = m_grid->get_TextStyleBand(0, @style)
   CMSHGRID_DP("style: " & WSTR(style))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleBand (BYVAL style AS TextStyleSettings)
   CMSHGRID_DP("style: " & WSTR(style))
   m_Result = m_grid->put_TextStyleBand(0, style)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the three-dimensional style for text within a specific band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleHeader (BYVAL BandNumber AS LONG) AS TextStyleSettings
   DIM style AS TextStyleSettings
   m_Result = m_grid->get_TextStyleHeader(BandNumber, @style)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - style: " & WSTR(style))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleHeader (BYVAL BandNumber AS LONG, BYVAL style AS TextStyleSettings)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - style: " & WSTR(style))
   m_Result = m_grid->put_TextStyleHeader(BandNumber, style)
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleHeader () AS TextStyleSettings
   DIM style AS TextStyleSettings
   m_Result = m_grid->get_TextStyleHeader(0, @style)
   CMSHGRID_DP("style: " & WSTR(style))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.TextStyleHeader (BYVAL style AS TextStyleSettings)
   CMSHGRID_DP("style: " & WSTR(style))
   m_Result = m_grid->put_TextStyleHeader(0, style)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the type of the current, active, cell of the MSHFlexGrid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellType () AS CellTypeSettings
   DIM nType AS CellTypeSettings
   m_Result = m_grid->get_CellType(@nType)
   CMSHGRID_DP("style: " & WSTR(nType))
   RETURN nType
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the height of the currently selected cell in twips. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellHeight () AS LONG
   DIM nHeight AS LONG
   m_Result = m_grid->get_CellHeight(@nHeight)
   CMSHGRID_DP("height: " & WSTR(nHeight))
   RETURN nHeight
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the width of the currently selected cell in twips. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellWidth () AS LONG
   DIM nWidth AS LONG
   m_Result = m_grid->get_CellWidth(@nWidth)
   CMSHGRID_DP("width: " & WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the distance between the left edge of the grid control and the left edge of the
' currently selected cell, measured in twips. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellLeft () AS LONG
   DIM nLeft AS LONG
   m_Result = m_grid->get_CellLeft(@nLeft)
   CMSHGRID_DP(WSTR(nLeft))
   RETURN nLeft
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns the distance from the top edge of the control to the top edge of the currently
' selected cell, measured in twips. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellTop () AS LONG
   DIM nTop AS LONG
   m_Result = m_grid->get_CellTop(@nTop)
   CMSHGRID_DP(WSTR(nTop))
   RETURN nTop
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the background color of the currently active cell or a selected range of cells. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellBackColor () AS OLE_COLOR
   DIM bkColor AS OLE_COLOR
   m_Result = m_grid->get_CellBackColor(@bkColor)
   CMSHGRID_DP(WSTR(bkColor))
   RETURN bkColor
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellBackColor (BYVAL bkColor AS OLE_COLOR)
   CMSHGRID_DP(WSTR(bkColor))
   m_Result = m_grid->put_CellBackColor(bkColor)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the foreground color of the currently active cell or a selected range of cells. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellForeColor () AS OLE_COLOR
   DIM clr AS OLE_COLOR
   m_Result = m_grid->get_CellForeColor(@clr)
   CMSHGRID_DP(WSTR(clr))
   RETURN clr
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellForeColor (BYVAL clr AS OLE_COLOR)
   CMSHGRID_DP(WSTR(clr))
   m_Result = m_grid->put_CellForeColor(clr)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the horizontal and vertical alignment of text within the currently
' selected cell or range of cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellAlignment () AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_CellAlignment(@nAlignment)
   CMSHGRID_DP(WSTR(nAlignment))
   RETURN nAlignment
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellAlignment (BYVAL nAlignment AS SHORT)
   CMSHGRID_DP(WSTR(nAlignment))
   m_Result = m_grid->put_CellAlignment(nAlignment)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the 3D visual style of the text for a specific cell or a selected range of cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellTextStyle () AS TextStyleSettings
   DIM style AS TextStyleSettings
   m_Result = m_grid->get_CellTextStyle(@style)
   CMSHGRID_DP("settings: " & WSTR(style))
   RETURN style
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellTextStyle (BYVAL style AS TextStyleSettings)
   CMSHGRID_DP("settings: " & WSTR(style))
   m_Result = m_grid->put_CellTextStyle(style)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the alignment of pictures in a cell or range of selected cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellPictureAlignment () AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_CellPictureAlignment(@nAlignment)
   CMSHGRID_DP(WSTR(nAlignment))
   RETURN nAlignment
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellPictureAlignment (BYVAL nAlignment AS SHORT)
   CMSHGRID_DP(WSTR(nAlignment))
   m_Result = m_grid->put_CellPictureAlignment(nAlignment)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets Returns or sets the alignment of text in a column.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColAlignment (BYVAL Index AS LONG) AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_ColAlignment(Index, @nAlignment)
   CMSHGRID_DP(WSTR(nAlignment))
   RETURN nAlignment
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColAlignment (BYVAL Index AS LONG, BYVAL nAlignment AS SHORT)
   CMSHGRID_DP(WSTR(nAlignment))
   m_Result = m_grid->put_ColAlignment(Index, nAlignment)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets Returns or sets the alignment of text within the fixed columns of the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColAlignmentFixed (BYVAL Index AS LONG) AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_ColAlignmentFixed(Index, @nAlignment)
   CMSHGRID_DP(WSTR(nAlignment))
   RETURN nAlignment
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.ColAlignmentFixed (BYVAL Index AS LONG, BYVAL nAlignment AS SHORT)
   CMSHGRID_DP(WSTR(nAlignment))
   m_Result = m_grid->put_ColAlignmentFixed(Index, nAlignment)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the alignment of data within a specific column of a hierarchical band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_ColAlignmentBand(BandNumber, BandColIdx, @nAlignment)
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   RETURN nAlignment
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WSTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   m_Result = m_grid->put_ColAlignmentBand(BandNumber, BandColIdx, nAlignment)
   RETURN m_Result
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentBand (BYVAL BandColIdx AS LONG) AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_ColAlignmentBand(0, BandColIdx, @nAlignment)
   CMSHGRID_DP("BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   RETURN nAlignment
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentBand (BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   CMSHGRID_DP("BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   m_Result = m_grid->put_ColAlignmentBand(0, BandColIdx, nAlignment)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets the alignment of data within the column headers of a specific band.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_ColAlignmentHeader(BandNumber, BandColIdx, @nAlignment)
   CMSHGRID_DP("BandNumber: " & WsTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   RETURN nAlignment
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   CMSHGRID_DP("BandNumber: " & WsTR(BandNumber) & " - BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   m_Result = m_grid->put_ColAlignmentHeader(BandNumber, BandColIdx, nAlignment)
   RETURN m_Result
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentHeader (BYVAL BandColIdx AS LONG) AS SHORT
   DIM nAlignment AS SHORT
   m_Result = m_grid->get_ColAlignmentHeader(0, BandColIdx, @nAlignment)
   CMSHGRID_DP("BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   RETURN nAlignment
END FUNCTION
' ========================================================================================
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.ColAlignmentHeader (BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
   CMSHGRID_DP("BandColIdx: " & WSTR(BandColIdx) & " - Aligment: " & WSTR(nAlignment))
   m_Result = m_grid->put_ColAlignmentHeader(0, BandColIdx, nAlignment)
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns or sets the default font, or the font for individual cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Font () AS IFont PTR
   DIM pFont AS IFont PTR
   m_Result = m_grid->get_Font(@pFont)
   CMSHGRID_DP("IFont PTR: " & WSTR(pFont))
   RETURN pFont
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Font (BYVAL pFont AS IFont PTR)
   CMSHGRID_DP("IFont PTR: " & WSTR(pFont))
   m_Result = m_grid->putref_Font(pFont)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the name of the default font.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontName () AS DWSTRING
   DIM bstrFont AS AFX_BSTR
   m_Result = m_grid->get_FontName(@bstrFont)
   DIM dws AS DWSTRING = *bstrFont
   SysFreeString bstrFont
   CMSHGRID_DP(dws)
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontName (BYREF wszFont AS WSTRING)
   CMSHGRID_DP(wszFont)
   DIM bstrFont AS AFX_BSTR = SysALlocString(wszFont)
   m_Result = m_grid->put_FontName(bstrFont)
   SysFreeString bstrFont
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the size of the default font.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontSize () AS SINGLE
   DIM nSize AS SINGLE
   m_Result = m_grid->get_FontSize(@nSize)
   CMSHGRID_DP(WSTR(nSize))
   RETURN nSize
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontSize (BYVAL nSize AS SINGLE)
   CMSHGRID_DP(WSTR(nSize))
   m_Result = m_grid->put_FontSize(nSize)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the bold attribute of the default font.
' True if the bold attribute is set; False, otherwise.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontBold () AS BOOLEAN
   DIM bBold AS VARIANT_BOOL
   m_Result = m_grid->get_FontBold(@bBold)
   CMSHGRID_DP(WSTR(bBold))
   RETURN bBold
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontBold (BYVAL bBold AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bBold))
   m_Result = m_grid->put_FontBold(cast(VARIANT_BOOL, bBold))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the italic attribute of the default font.
' True if the italic attribute is set; False, otherwise.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontItalic () AS BOOLEAN
   DIM bItalic AS VARIANT_BOOL
   m_Result = m_grid->get_FontItalic(@bItalic)
   CMSHGRID_DP(WSTR(bItalic))
   RETURN bItalic
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontItalic (BYVAL bItalic AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bItalic))
   m_Result = m_grid->put_FontItalic(cast(VARIANT_BOOL, bItalic))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the strike through attribute of the default font.
' True if the strike through attribute is set; False, otherwise.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontStrikethru () AS BOOLEAN
   DIM bStrikeThrough AS VARIANT_BOOL
   m_Result = m_grid->get_FontStrikethru(@bStrikeThrough)
   CMSHGRID_DP(WSTR(bStrikeThrough))
   RETURN bStrikeThrough
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontStrikethru (BYVAL bStrikeThrough AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bStrikeThrough))
   m_Result = m_grid->put_FontStrikethru(cast(VARIANT_BOOL, bStrikeThrough))
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontStrikeThrough () AS BOOLEAN
   DIM bStrikeThrough AS VARIANT_BOOL
   m_Result = m_grid->get_FontStrikeThrough(@bStrikeThrough)
   CMSHGRID_DP(WSTR(bStrikeThrough))
   RETURN bStrikeThrough
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontStrikeThrough (BYVAL bStrikeThrough AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bStrikeThrough))
   m_Result = m_grid->put_FontStrikeThrough(cast(VARIANT_BOOL, bStrikeThrough))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the underline through attribute of the default font.
' True if the underline through attribute is set; False, otherwise.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontUnderline () AS BOOLEAN
   DIM bUnderline AS VARIANT_BOOL
   m_Result = m_grid->get_FontUnderline(@bUnderline)
   CMSHGRID_DP(WSTR(bUnderline))
   RETURN bUnderline
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontUnderline (BYVAL bUnderline AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bUnderline))
   m_Result = m_grid->put_FontUnderline(cast(VARIANT_BOOL, bUnderline))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the rigth to left attribute of the default font.
' True if the underline through attribute is set; False, otherwise.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RightToLeft () AS BOOLEAN
   DIM bRightToLeft AS VARIANT_BOOL
   m_Result = m_grid->get_RightToLeft(@bRightToLeft)
   CMSHGRID_DP(WSTR(bRightToLeft))
   RETURN bRightToLeft
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.RightToLeft (BYVAL bRightToLeft AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bRightToLeft))
   m_Result = m_grid->put_RightToLeft(cast(VARIANT_BOOL, bRightToLeft))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the width, in points, of the font to be used for text displayed within the grid.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidth () AS SINGLE
   DIM nWidth AS SINGLE
   m_Result = m_grid->get_FontWidth(@nWidth)
   CMSHGRID_DP(WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidth (BYVAL nWidth AS SINGLE)
   CMSHGRID_DP(WSTR(nWidth))
   m_Result = m_grid->put_FontWidth(nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a Font object used to display text in all fixed rows and fixed columns
' (the non-scrolling headers).
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontFixed () AS IFont PTR
   DIM pFont AS IFont PTR
   m_Result = m_grid->get_FontFixed(@pFont)
   CMSHGRID_DP(WSTR(pFont))
   RETURN pFont
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontFixed (BYVAL pFont AS IFont PTR)
   CMSHGRID_DP(WSTR(pFont))
   m_Result = m_grid->putref_FontFixed(pFont)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the width, in points, of the font to be used for all fixed rows and fixed
' columns (the non-scrolling headers).
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidthFixed () AS SINGLE
   DIM nWidth AS SINGLE
   m_Result = m_grid->get_FontWidthFixed(@nWidth)
   CMSHGRID_DP(WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidthFixed (BYVAL nWidth AS SINGLE)
   CMSHGRID_DP(WSTR(nWidth))
   m_Result = m_grid->put_FontWidthFixed(nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a Font object used for data cells within a specific hierarchical band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontBand (BYVAL BandNumber AS LONG) AS IFont PTR
   DIM pFont AS IFont PTR
   m_Result = m_grid->get_FontBand(BandNumber, @pFont)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - font: " & WSTR(pFont)))
   RETURN pFont
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontBand (BYVAL BandNumber AS LONG, BYVAL pFont AS IFont PTR)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - font: " & WSTR(pFont)))
   m_Result = m_grid->putref_FontBand(BandNumber, pFont)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the width of the font for the data cells within a specific hierarchical band. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidthBand (BYVAL BandNumber AS LONG) AS SINGLE
   DIM nWidth AS SINGLE
   m_Result = m_grid->get_FontWidthBand(BandNumber, @nWidth)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - width: " & WSTR(nWidth)))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidthBand (BYVAL BandNumber AS LONG, BYVAL nWidth AS SINGLE)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - width: " & WSTR(nWidth)))
   m_Result = m_grid->put_FontWidthBand(BandNumber, nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a Font object used specifically for the column headers of a particular
' hierarchical band.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontHeader (BYVAL BandNumber AS LONG) AS IFont PTR
   DIM pFont AS IFont PTR
   m_Result = m_grid->get_FontHeader(BandNumber, @pFont)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - font: " & WSTR(pFont)))
   RETURN pFont
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontHeader (BYVAL BandNumber AS LONG, BYVAL pFont AS IFont PTR)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - font: " & WSTR(pFont)))
   m_Result = m_grid->putref_FontHeader(BandNumber, pFont)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the width of the font used in the column headers for a specific hierarchical band. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidthHeader (BYVAL BandNumber AS LONG) AS SINGLE
   DIM nWidth AS SINGLE
   m_Result = m_grid->get_FontWidthHeader(BandNumber, @nWidth)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - width: " & WSTR(nWidth)))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.FontWidthHeader (BYVAL BandNumber AS LONG, BYVAL nWidth AS SINGLE)
   CMSHGRID_DP(WSTR("BandNumber: " & WSTR(BandNumber) & " - width: " & WSTR(nWidth)))
   m_Result = m_grid->put_FontWidthHeader(BandNumber, nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the typeface (font name) for the currently active cell or a selected range of cells.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontName () AS DWSTRING
   DIM bstrName AS AFX_BSTR
   m_Result = m_grid->get_CellFontName(@bstrName)
   DIM dws AS DWSTRING = *bstrName
   SysFreeString bstrName
   CMSHGRID_DP("font name: " & dws)
   RETURN dws
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontName (BYREF wszFontName AS WSTRING)
   CMSHGRID_DP("font name: " & wszFontName)
   DIM bstrName AS AFX_BSTR = SysAllocString(wszFontName)
   m_Result = m_grid->put_CellFontName(bstrName)
   SysFreeString bstrName
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the size, in points, for the current cell text.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontSize () AS SINGLE
   DIM nSize AS SINGLE
   m_Result = m_grid->get_CellFontSize(@nSize)
   CMSHGRID_DP(WSTR(nSize))
   RETURN nSize
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontSize (BYVAL nSize AS SINGLE)
   CMSHGRID_DP(WSTR(nSize))
   m_Result = m_grid->put_CellFontSize(nSize)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that specifies if the underline style is applied to the current cell text.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontBold () AS BOOLEAN
   DIM bBold AS VARIANT_BOOL
   m_Result = m_grid->get_CellFontBold(@bBold)
   CMSHGRID_DP(WSTR(bBold))
   RETURN bBold
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontBold (BYVAL bBold AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bBold))
   m_Result = m_grid->put_CellFontBold(cast(VARIANT_BOOL, bBold))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that specifies if the underline style is applied to the current cell text.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontItalic () AS BOOLEAN
   DIM bItalic AS VARIANT_BOOL
   m_Result = m_grid->get_CellFontItalic(@bItalic)
   CMSHGRID_DP(WSTR(bItalic))
   RETURN bItalic
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontItalic (BYVAL bItalic AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bItalic))
   m_Result = m_grid->put_CellFontItalic(cast(VARIANT_BOOL, bItalic))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that specifies if the underline style is applied to the current cell text.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontUnderline () AS BOOLEAN
   DIM bUnderline AS VARIANT_BOOL
   m_Result = m_grid->get_CellFontUnderline(@bUnderline)
   CMSHGRID_DP(WSTR(bUnderline))
   RETURN bUnderline
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontUnderline (BYVAL bUnderline AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bUnderline))
   m_Result = m_grid->put_CellFontUnderline (cast(VARIANT_BOOL, bUnderline))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets a value that determines if the Strikethrough style is applied to the current cell text.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontStrikeThrough () AS BOOLEAN
   DIM bStrikeThrouh AS VARIANT_BOOL
   m_Result = m_grid->get_CellFontStrikeThrough(@bStrikeThrouh)
   CMSHGRID_DP(WSTR(bStrikeThrouh))
   RETURN bStrikeThrouh
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontStrikeThrough (BYVAL bStrikeThrouh AS VARIANT_BOOL)
   CMSHGRID_DP(WSTR(bStrikeThrouh))
   m_Result = m_grid->put_CellFontStrikeThrough (cast(VARIANT_BOOL, bStrikeThrouh))
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the width, in points, for the current cell text. 
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontWidth () AS SINGLE
   DIM nWidth AS SINGLE
   m_Result = m_grid->get_CellFontWidth(@nWidth)
   CMSHGRID_DP(WSTR(nWidth))
   RETURN nWidth
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellFontWidth (BYVAL nWidth AS SINGLE)
   CMSHGRID_DP(WSTR(nWidth))
   m_Result = m_grid->put_CellFontWidth (nWidth)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Returns or sets the type of picture to be generated by the Picture property.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.PictureType () AS PictureTypeSettings
   DIM picType AS PictureTypeSettings
   m_Result = m_grid->get_PictureType(@picType)
   CMSHGRID_DP("picture type: " & WSTR(picType))
   RETURN picType
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.PictureType (BYVAL picType AS PictureTypeSettings)
   CMSHGRID_DP("picture type: " & WSTR(picType))
   m_Result = m_grid->put_PictureType (picType)
END PROPERTY
' ========================================================================================

' ========================================================================================
' eturns a snapshot of the entire grid control as a picture object. This picture is suitable
' for printing, saving to disk, copying to the clipboard, or assigning to a different control.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.Picture () AS IPicture PTR
   DIM pic AS IPicture PTR
   m_Result = m_grid->get_Picture(@pic)
   CMSHGRID_DP(WSTR(pic))
   RETURN pic
END PROPERTY
' ========================================================================================

' ========================================================================================
' eturns a snapshot of the entire grid control as a picture object. This picture is suitable
' for printing, saving to disk, copying to the clipboard, or assigning to a different control.
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellPicture () AS IPicture PTR
   DIM pic AS IPicture PTR
   m_Result = m_grid->get_CellPicture(@pic)
   CMSHGRID_DP(WSTR(pic))
   RETURN pic
END PROPERTY
' ========================================================================================
' ========================================================================================
PRIVATE PROPERTY CMSHFlexGrid.CellPicture (BYVAL pic AS IPicture PTR)
   CMSHGRID_DP(WSTR(pic))
   m_Result = m_grid->putref_CellPicture (pic)
END PROPERTY
' ========================================================================================

' ========================================================================================
' Displays an about box
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.AboutBox () AS HRESULT
   CMSHGRID_DP("")
   m_Result = m_grid->AboutBox
   RETURN m_Result
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the version number of the grid control.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.Version () AS SHORT
   DIM ver AS SHORT
   m_Result = m_grid->get_Version(@ver)
   CMSHGRID_DP(WSTR(ver))
   RETURN ver
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the events sink.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGrid.SetEvents (BYVAL pEvtSink AS ANY PTR) AS HRESULT
   ' // Disable events
   IF pEvtSink = NULL THEN
      IF m_dwCookie THEN
         DIM hr AS HRESULT = AfxUnadvise(m_grid, AFX_IID_DMSHFlexGridEvents, m_dwCookie)
         IF hr <> S_OK THEN RETURN hr
         m_dwCookie = 0
      ELSE
         SetResult(E_POINTER)
         RETURN E_POINTER
      END IF
   END IF
   ' // Set events
   IF m_dwCookie THEN
      DIM hr AS HRESULT = AfxUnadvise(m_grid, AFX_IID_DMSHFlexGridEvents, m_dwCookie)
      IF hr <> S_OK THEN RETURN hr
      m_dwCookie = 0
   END IF
   SetResult(AfxAdvise(m_grid, pEvtSink, AFX_IID_DMSHFlexGridEvents, @m_dwCookie))
   RETURN m_Result
END FUNCTION
' ========================================================================================

' // Events
#include once "MSHFlexGridEvents.inc"

END NAMESPACE
