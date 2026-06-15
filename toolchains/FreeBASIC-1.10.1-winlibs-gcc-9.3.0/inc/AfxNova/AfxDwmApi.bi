' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxDwmApi.bi
' Purpose:  Translation of DwmApi.h
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2025 José Roca
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
#include once "win/winapifamily.bi"
#include once "win/wtypes.bi"
#include once "win/uxtheme.bi"

extern "Windows"

' // Blur behind data structures
CONST DWM_BB_ENABLE                = &h00000001   ' // fEnable has been specified
CONST DWM_BB_BLURREGION            = &h00000002   ' // hRgnBlur has been specified
CONST DWM_BB_TRANSITIONONMAXIMIZED = &h00000004   ' // fTransitionOnMaximized has been specified

TYPE _DWM_BLURBEHIND
	dwFlags AS DWORD
	fEnable AS BOOL
	hRgnBlur AS HRGN
	fTransitionOnMaximized AS BOOL
END TYPE

TYPE DWM_BLURBEHIND AS _DWM_BLURBEHIND
TYPE PDWM_BLURBEHIND AS _DWM_BLURBEHIND PTR

' // Window attributes
TYPE DWMWINDOWATTRIBUTE AS LONG
ENUM
	DWMWA_NCRENDERING_ENABLED = 1          ' // [get] Is non-client rendering enabled/disabled
	DWMWA_NCRENDERING_POLICY               ' // [set] DWMNCRENDERINGPOLICY - Non-client rendering policy
	DWMWA_TRANSITIONS_FORCEDISABLED        ' // [set] Potentially enable/forcibly disable transitions
	DWMWA_ALLOW_NCPAINT                    ' // [set] Allow contents rendered in the non-client area to be visible on the DWM-drawn frame.
	DWMWA_CAPTION_BUTTON_BOUNDS            ' // [get] Bounds of the caption button area in window-relative space.
	DWMWA_NONCLIENT_RTL_LAYOUT             ' // [set] Is non-client content RTL mirrored
	DWMWA_FORCE_ICONIC_REPRESENTATION      ' // [set] Force this window to display iconic thumbnails.
	DWMWA_FLIP3D_POLICY                    ' // [set] Designates how Flip3D will treat the window.
	DWMWA_EXTENDED_FRAME_BOUNDS            ' // [get] Gets the extended frame bounds rectangle in screen space
	DWMWA_HAS_ICONIC_BITMAP                ' // [set] Indicates an available bitmap when there is no better thumbnail representation.
	DWMWA_DISALLOW_PEEK                    ' // [set] Don't invoke Peek on the window.
	DWMWA_EXCLUDED_FROM_PEEK               ' // [set] LivePreview exclusion information
	DWMWA_CLOAK                            ' // [set] Cloak or uncloak the window
	DWMWA_CLOAKED                          ' // [get] Gets the cloaked state of the window
	DWMWA_FREEZE_REPRESENTATION            ' // [set] BOOL, Force this window to freeze the thumbnail without live update
	DWMWA_PASSIVE_UPDATE_MODE              ' // [set] BOOL, Updates the window only when desktop composition runs for other reasons
	DWMWA_USE_HOSTBACKDROPBRUSH            ' // [set] BOOL, Allows the use of host backdrop brushes for the window.
	DWMWA_USE_IMMERSIVE_DARK_MODE = 20     ' // [set] BOOL, Allows a window to either use the accent color, or dark, according to the user Color Mode preferences.
	DWMWA_WINDOW_CORNER_PREFERENCE = 33    ' // [set] WINDOW_CORNER_PREFERENCE, Controls the policy that rounds top-level window corners
	DWMWA_BORDER_COLOR                     ' // [set] COLORREF, The color of the thin border around a top-level window
	DWMWA_CAPTION_COLOR                    ' // [set] COLORREF, The color of the caption
	DWMWA_TEXT_COLOR                       ' // [set] COLORREF, The color of the caption text
	DWMWA_VISIBLE_FRAME_BORDER_THICKNESS   ' // [get] UINT, width of the visible border around a thick frame window                       ' 
	DWMWA_SYSTEMBACKDROP_TYPE              ' // [get, set] SYSTEMBACKDROP_TYPE, Controls the system-drawn backdrop material of a window, including behind the non-client area.
	DWMWA_REDIRECTIONBITMAP_ALPHA          ' // [set] BOOL, GDI redirection bitmap containspremultiplied alpha
	DWMWA_LAST
END ENUM

TYPE DWM_WINDOW_CORNER_PREFERENCE AS LONG
ENUM
	DWMWCP_DEFAULT = 0      ' // Let the system decide whether or not to round window corners
	DWMWCP_DONOTROUND = 1   ' // Never round window corners
	DWMWCP_ROUND = 2        ' // Round the corners if appropriate
	DWMWCP_ROUNDSMALL = 3   ' // Round the corners if appropriate, with a small radius
END ENUM

CONST DWMWA_COLOR_DEFAULT = &hFFFFFFFF   ' // Use this constant to reset any window part colors to the system default behavior
CONST DWMWA_COLOR_NONE = &hFFFFFFFE      ' // Use this constant to specify that a window part should not be rendered

' // Types used with DWMWA_SYSTEMBACKDROP_TYPE
TYPE DWM_SYSTEMBACKDROP_TYPE AS LONG
ENUM
	DWMSBT_AUTO              ' // [Default] Let DWM automatically decide the system-drawn backdrop for this window.
	DWMSBT_NONE              ' // Do not draw any system backdrop.
	DWMSBT_MAINWINDOW        ' // Draw the backdrop material effect corresponding to a long-lived window.
	DWMSBT_TRANSIENTWINDOW   ' // Draw the backdrop material effect corresponding to a transient window.
	DWMSBT_TABBEDWINDOW      ' // Draw the backdrop material effect corresponding to a window with a tabbed title bar.
END ENUM

' // Non-client rendering policy attribute values
TYPE DWMNCRENDERINGPOLICY AS LONG
ENUM
	DWMNCRP_USEWINDOWSTYLE   ' // Enable/disable non-client rendering based on window style
	DWMNCRP_DISABLED         ' // Disabled non-client rendering; window style is ignored
	DWMNCRP_ENABLED          ' // Enabled non-client rendering; window style is ignored
	DWMNCRP_LAST
END ENUM

' // Values designating how Flip3D treats a given window.
TYPE DWMFLIP3DWINDOWPOLICY AS LONG
ENUM
	DWMFLIP3D_DEFAULT        ' // Hide or include the window in Flip3D based on window style and visibility.
	DWMFLIP3D_EXCLUDEBELOW   ' // Display the window under Flip3D and disabled.
	DWMFLIP3D_EXCLUDEABOVE   ' // Display the window above Flip3D and enabled.
	DWMFLIP3D_LAST
END ENUM

' // Cloaked flags describing why a window is cloaked.
CONST DWM_CLOAKED_APP = &h00000001
CONST DWM_CLOAKED_SHELL = &h00000002
CONST DWM_CLOAKED_INHERITED = &h00000004

TYPE HTHUMBNAIL AS HANDLE
TYPE PHTHUMBNAIL AS HTHUMBNAIL PTR

CONST DWM_TNP_RECTDESTINATION      = &h00000001   ' // A value for the "rcDestination" member has been specified.
CONST DWM_TNP_RECTSOURCE           = &h00000002   ' // A value for the "rcSource" member has been specified.
CONST DWM_TNP_OPACITY              = &h00000004   ' // A value for the "opacity" member has been specified.
CONST DWM_TNP_VISIBLE              = &h00000008   ' // A value for the "fVisible" member has been specified.
CONST DWM_TNP_SOURCECLIENTAREAONLY = &h00000010   ' // A value for the "fSourceClientAreaOnly" member has been specified.

TYPE _DWM_THUMBNAIL_PROPERTIES
	dwFlags AS DWORD                ' // Specifies which members of this struct have been specified
	rcDestination AS RECT           ' // The area in the destination window where the thumbnail will be rendered
	rcSource AS RECT                ' // The region of the source window to use as the thumbnail.  By default, the entire window is used as the thumbnail
	opacity AS BYTE                 ' // The opacity with which to render the thumbnail.  0 is fully transparent, while 255 is fully opaque.  The default value is 255
	fVisible AS BOOL                ' // Whether the thumbnail should be visible.  The default is FALSE
	fSourceClientAreaOnly AS BOOL   ' // Whether only the client area of the source window should be included in the thumbnail.  The default is FALSE
END TYPE

TYPE DWM_THUMBNAIL_PROPERTIES AS _DWM_THUMBNAIL_PROPERTIES
TYPE PDWM_THUMBNAIL_PROPERTIES AS _DWM_THUMBNAIL_PROPERTIES PTR

' // Video enabling apis
TYPE DWM_FRAME_COUNT AS ULONGLONG
TYPE QPC_TIME AS ULONGLONG

TYPE _UNSIGNED_RATIO
	uiNumerator AS UINT32
	uiDenominator AS UINT32
END TYPE

TYPE UNSIGNED_RATIO AS _UNSIGNED_RATIO

TYPE _DWM_TIMING_INFO
	cbSize AS UINT32                            ' // ize of the structure
   ' // Data on DWM composition overall
	rateRefresh AS UNSIGNED_RATIO               ' // Monitor refresh rate
	qpcRefreshPeriod AS QPC_TIME                ' // Actual period
	rateCompose AS UNSIGNED_RATIO               ' // composition rate
	qpcVBlank AS QPC_TIME                       ' // QPC time at a VSync interupt
   ' // DWM refresh count of the last vsync. DWM refresh count is a 64bit number where zero is the first refresh the DWM woke up to process
	cRefresh AS DWM_FRAME_COUNT
   ' // DX refresh count at the last Vsync Interupt. DX refresh count is a 32bit number with zero
   ' // being the first refresh after the card was initialized DX increments a counter when ever a VSync ISR is processed
   ' // It is possible for DX to miss VSyncs. There is not a fixed mapping between DX and DWM refresh counts
   ' // because the DX will rollover and may miss VSync interupts
	cDXRefresh AS UINT
	qpcCompose AS QPC_TIME                      ' // QPC time at a compose time.
	cFrame AS DWM_FRAME_COUNT                   ' // Frame number that was composed at qpcCompose
	cDXPresent AS UINT                          ' // The present number DX uses to identify renderer frames
	cRefreshFrame AS DWM_FRAME_COUNT            ' // Refresh count of the frame that was composed at qpcCompose
	cFrameSubmitted AS DWM_FRAME_COUNT          ' // DWM frame number that was last submitted
	cDXPresentSubmitted AS UINT                 ' // DX Present number that was last submitted
	cFrameConfirmed AS DWM_FRAME_COUNT          ' // DWM frame number that was last confirmed presented
	cDXPresentConfirmed AS UINT                 ' // DX Present number that was last confirmed presented
	cRefreshConfirmed AS DWM_FRAME_COUNT        ' // The target refresh count of the last. frame confirmed completed by the GPU
	cDXRefreshConfirmed AS UINT                 ' // DX refresh count when the frame was confirmed presented
	cFramesLate AS DWM_FRAME_COUNT              ' // Number of frames the DWM presented late AKA Glitches
	cFramesOutstanding AS UINT                  ' // the number of composition frames that have been issued but not confirmed completed
   ' // Following fields are only relavent when an HWND is specified Display frame
	cFrameDisplayed AS DWM_FRAME_COUNT          ' // Last frame displayed
	qpcFrameDisplayed AS QPC_TIME               ' // QPC time of the composition pass when the frame was displayed
	cRefreshFrameDisplayed AS DWM_FRAME_COUNT   ' // Count of the VSync when the frame should have become visible
   ' // Complete frames: DX has notified the DWM that the frame is done rendering
	cFrameComplete AS DWM_FRAME_COUNT           ' // ID of the the last frame marked complete (starts at 0)
	qpcFrameComplete AS QPC_TIME                ' // QPC time when the last frame was marked complete
   ' // Pending frames: The application has been submitted to DX but not completed by the GPU
	cFramePending AS DWM_FRAME_COUNT            ' // ID of the the last frame marked pending (starts at 0)
	qpcFramePending AS QPC_TIME                 ' // QPC time when the last frame was marked pending
	cFramesDisplayed AS DWM_FRAME_COUNT         ' // number of unique frames displayed
	cFramesComplete AS DWM_FRAME_COUNT          ' // number of new completed frames that have been received
	cFramesPending AS DWM_FRAME_COUNT           ' // number of new frames submitted to DX but not yet complete
	cFramesAvailable AS DWM_FRAME_COUNT         ' // number of frames available but not displayed, used or dropped
	cFramesDropped AS DWM_FRAME_COUNT           ' // number of rendered frames that were never displayed because composition occured too late
	cFramesMissed AS DWM_FRAME_COUNT            ' // number of times an old frame was composed when a new frame should have been used but was not available
	cRefreshNextDisplayed AS DWM_FRAME_COUNT    ' // the refresh at which the next frame is scheduled to be displayed
	cRefreshNextPresented AS DWM_FRAME_COUNT    ' // the refresh at which the next DX present is scheduled to be displayed
	cRefreshesDisplayed AS DWM_FRAME_COUNT      ' // The total number of refreshes worth of content for this HWND that have been displayed by the DWM since DwmSetPresentParameters was called
	cRefreshesPresented AS DWM_FRAME_COUNT      ' // The total number of refreshes worth of content that have been presented by the application since DwmSetPresentParameters was called
	cRefreshStarted AS DWM_FRAME_COUNT          ' // The actual refresh # when content for this window started to be displayed  it may be different than that requested
   ' // Total number of pixels DX redirected to the DWM. If Queueing is used the full buffer is transfered on each present.
   ' // If not queuing it is possible only a dirty region is updated
	cPixelsReceived AS ULONGLONG                
   ' // Total number of pixels drawn. Does not take into account if the window
   ' //  is only partial drawn do to clipping or dirty rect management
	cPixelsDrawn AS ULONGLONG
   ' // The number of buffers in the flipchain that are empty. An application can present that number of times and guarantee
   ' // it won't be blocked waiting for a buffer to become empty to present to
	cBuffersEmpty AS DWM_FRAME_COUNT
END TYPE

TYPE DWM_TIMING_INFO AS _DWM_TIMING_INFO

TYPE DWM_SOURCE_FRAME_SAMPLING AS LONG
ENUM
   ' // Use the first source frame that includes the first refresh of the output frame
	DWM_SOURCE_FRAME_SAMPLING_POINT
   ' // use the source frame that includes the most refreshes of out the output frame
   ' // in case of multiple source frames with the same coverage the last will be used
	DWM_SOURCE_FRAME_SAMPLING_COVERAGE
   ' // Sentinel value
	DWM_SOURCE_FRAME_SAMPLING_LAST
END ENUM

#define c_DwmMaxQueuedBuffers 8
#define c_DwmMaxMonitors 16
#define c_DwmMaxAdapters 16

TYPE _DWM_PRESENT_PARAMETERS
	cbSize AS UINT32
	fQueue AS BOOL
	cRefreshStart AS DWM_FRAME_COUNT
	cBuffer AS UINT
	fUseSourceRate AS BOOL
	rateSource AS UNSIGNED_RATIO
	cRefreshesPerFrame AS UINT
	eSampling AS DWM_SOURCE_FRAME_SAMPLING
END TYPE
TYPE DWM_PRESENT_PARAMETERS AS _DWM_PRESENT_PARAMETERS

CONST DWM_FRAME_DURATION_DEFAULT = -1

DECLARE FUNCTION DwmDefWindowProc LIB "dwmapi.dll" ALIAS "DwmDefWindowProc" (BYVAL hwnd AS HWND, BYVAL msg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM, BYVAL plResult AS LRESULT PTR) AS BOOL
DECLARE FUNCTION DwmEnableBlurBehindWindow LIB "dwmapi.dll" ALIAS "DwmEnableBlurBehindWindow" (BYVAL hwnd AS HWND, BYVAL msg AS UINT, BYVAL pBlurBehind AS DWM_BLURBEHIND PTR) AS HRESULT

CONST DWM_EC_DISABLECOMPOSITION = 0
CONST DWM_EC_ENABLECOMPOSITION = 1

DECLARE FUNCTION DwmEnableComposition LIB "dwmapi.dll" ALIAS "DwmEnableComposition" (BYVAL uCompositionAction AS UINT) AS HRESULT
DECLARE FUNCTION DwmEnableMMCSS LIB "dwmapi.dll" ALIAS "DwmEnableMMCSS" (BYVAL fEnableMMCSS AS BOOL) AS HRESULT
DECLARE FUNCTION DwmExtendFrameIntoClientArea LIB "dwmapi.dll" ALIAS "DwmExtendFrameIntoClientArea" (BYVAL hWnd AS HWND, BYVAL pMarInset AS CONST MARGINS PTR) AS HRESULT
DECLARE FUNCTION DwmGetColorizationColor LIB "dwmapi.dll" ALIAS "DwmGetColorizationColor" (BYVAL pcrColorization AS DWORD PTR, BYVAL pfOpaqueBlend AS BOOL PTR) AS HRESULT
DECLARE FUNCTION DwmGetCompositionTimingInfo LIB "dwmapi.dll" ALIAS "DwmGetCompositionTimingInfo" (BYVAL hwnd AS HWND, BYVAL pTimingInfo AS DWM_TIMING_INFO PTR) AS HRESULT
DECLARE FUNCTION DwmGetWindowAttribute LIB "dwmapi.dll" ALIAS "DwmGetWindowAttribute" (BYVAL hwnd AS HWND, BYVAL dwAttribute AS DWORD, BYVAL pvAttribute AS PVOID, BYVAL cbAttribute AS DWORD) AS HRESULT
DECLARE FUNCTION DwmIsCompositionEnabled LIB "dwmapi.dll" ALIAS "DwmIsCompositionEnabled" (BYVAL pfEnabled AS BOOL PTR) AS HRESULT
DECLARE FUNCTION DwmModifyPreviousDxFrameDuration LIB "dwmapi.dll" ALIAS "DwmModifyPreviousDxFrameDuration" (BYVAL hwnd AS HWND, BYVAL cRefreshes AS INT_, BYVAL fRelative AS BOOL) AS HRESULT
DECLARE FUNCTION DwmQueryThumbnailSourceSize LIB "dwmapi.dll" ALIAS "DwmQueryThumbnailSourceSize" (BYVAL hThumbnail AS HTHUMBNAIL, BYVAL pSize AS PSIZE) AS HRESULT
DECLARE FUNCTION DwmRegisterThumbnail LIB "dwmapi.dll" ALIAS "DwmRegisterThumbnail" (BYVAL hwndDestination AS HWND, BYVAL hwndSource AS HWND, BYVAL phThumbnailId AS PHTHUMBNAIL) AS HRESULT
DECLARE FUNCTION DwmSetDxFrameDuration LIB "dwmapi.dll" ALIAS "DwmSetDxFrameDuration" (BYVAL hwnd AS HWND, BYVAL cRefreshes AS INT_) AS HRESULT
DECLARE FUNCTION DwmSetPresentParameters LIB "dwmapi.dll" ALIAS "DwmSetPresentParameters" (BYVAL hwnd AS HWND, BYVAL pPresentParams AS DWM_PRESENT_PARAMETERS PTR) AS HRESULT
DECLARE FUNCTION DwmSetWindowAttribute LIB "dwmapi.dll" ALIAS "DwmSetWindowAttribute" (BYVAL hwnd AS HWND, BYVAL dwAttribute AS DWORD, BYVAL pvAttribute AS LPCVOID, BYVAL cbAttribute AS DWORD) AS HRESULT
DECLARE FUNCTION DwmUnregisterThumbnail LIB "dwmapi.dll" ALIAS "DwmUnregisterThumbnail" (BYVAL hThumbnailId AS HTHUMBNAIL) AS HRESULT
DECLARE FUNCTION DwmUpdateThumbnailProperties LIB "dwmapi.dll" ALIAS "DwmUpdateThumbnailProperties" (BYVAL hThumbnailId AS HTHUMBNAIL, BYVAL ptnProperties AS DWM_THUMBNAIL_PROPERTIES PTR) AS HRESULT

#if _WIN32_WINNT >= &h0601
#define DWM_SIT_DISPLAYFRAME    &h00000001   ' // Display a window frame around the provided bitmap
DECLARE FUNCTION DwmSetIconicThumbnail LIB "dwmapi.dll" ALIAS "DwmSetIconicThumbnail" (BYVAL hwnd AS HWND, BYVAL hbmp AS HBITMAP, BYVAL dwSITFlags AS DWORD) AS HRESULT
DECLARE FUNCTION DwmSetIconicLivePreviewBitmap LIB "dwmapi.dll" ALIAS "DwmSetIconicLivePreviewBitmap" (BYVAL hwnd AS HWND, BYVAL hbmp AS HBITMAP, BYVAL pptClient AS POINT PTR, BYVAL dwSITFlags AS DWORD) AS HRESULT
DECLARE FUNCTION DwmInvalidateIconicBitmaps LIB "dwmapi.dll" ALIAS "DwmInvalidateIconicBitmaps" (BYVAL hwnd AS HWND) AS HRESULT
#endif ' /* _WIN32_WINNT >= 0x0601 */

DECLARE FUNCTION DwmAttachMilContent LIB "dwmapi.dll" ALIAS "DwmAttachMilContent" (BYVAL hwnd AS HWND) AS HRESULT
DECLARE FUNCTION DwmDetachMilContent LIB "dwmapi.dll" ALIAS "DwmDetachMilContent" (BYVAL hwnd AS HWND) AS HRESULT
DECLARE FUNCTION DwmFlush LIB "dwmapi.dll" ALIAS "DwmFlush" () AS HRESULT

#ifndef MILCORE_KERNEL_COMPONENT
#ifndef _MIL_MATRIX3X2D_DEFINED
TYPE _MilMatrix3x2D
	S_11 AS DOUBLE
	S_12 AS DOUBLE
	S_21 AS DOUBLE
	S_22 AS DOUBLE
	DX AS DOUBLE
	DY AS DOUBLE
END TYPE
TYPE MilMatrix3x2D AS _MilMatrix3x2D
#define _MIL_MATRIX3X2D_DEFINED
#endif ' // _MIL_MATRIX3X2D_DEFINED

'#ifndef MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF
'' // Compatibility for Vista dwm api.
'TYPE MilMatrix3x2D MIL_MATRIX3X2D
'#define MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF
'#endif // MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF

DECLARE FUNCTION DwmGetGraphicsStreamTransformHint LIB "dwmapi.dll" ALIAS "DwmGetGraphicsStreamTransformHint" (BYVAL uIndex AS UINT, BYVAL PTRansform AS MilMatrix3x2D PTR) AS HRESULT
DECLARE FUNCTION DwmGetGraphicsStreamClient LIB "dwmapi.dll" ALIAS "DwmGetGraphicsStreamClient" (BYVAL uIndex AS UINT, BYVAL pClientUuid AS UUID PTR) AS HRESULT
#endif ' // MILCORE_KERNEL_COMPONENT

DECLARE FUNCTION DwmGetTransportAttributes LIB "dwmapi.dll" ALIAS "DwmGetTransportAttributes" (BYVAL pfIsRemoting AS BOOL PTR, BYVAL pfIsConnected AS BOOL PTR, BYVAL pDwGeneration AS DWORD PTR) AS HRESULT

TYPE DWMTRANSITION_OWNEDWINDOW_TARGET AS LONG
ENUM
	DWMTRANSITION_OWNEDWINDOW_NULL       = -1
	DWMTRANSITION_OWNEDWINDOW_REPOSITION = 0
END ENUM

DECLARE FUNCTION DwmTransitionOwnedWindow LIB "dwmapi.dll" ALIAS "DwmTransitionOwnedWindow" (BYVAL hwnd AS HWND, BYVAL target AS DWMTRANSITION_OWNEDWINDOW_TARGET) AS HRESULT

TYPE GESTURE_TYPE AS LONG
ENUM
	GT_PEN_TAP = 0
	GT_PEN_DOUBLETAP = 1
	GT_PEN_RIGHTTAP = 2
	GT_PEN_PRESSANDHOLD = 3
	GT_PEN_PRESSANDHOLDABORT = 4
	GT_TOUCH_TAP = 5
	GT_TOUCH_DOUBLETAP = 6
	GT_TOUCH_RIGHTTAP = 7
	GT_TOUCH_PRESSANDHOLD = 8
	GT_TOUCH_PRESSANDHOLDABORT = 9
	GT_TOUCH_PRESSANDTAP = 10
END ENUM

DECLARE FUNCTION DwmRenderGesture LIB "dwmapi.dll" ALIAS "DwmRenderGesture" (BYVAL gt AS GESTURE_TYPE, BYVAL cContacts AS UINT, BYVAL pdwPointerID AS DWORD PTR, BYVAL pPoints AS POINT PTR) AS HRESULT
DECLARE FUNCTION DwmTetherContact LIB "dwmapi.dll" ALIAS "DwmTetherContact" (BYVAL dwPointerID AS DWORD, BYVAL fEnable AS BOOL, BYVAL ptTether AS POINT) AS HRESULT

TYPE DWM_SHOWCONTACT AS LONG
ENUM
	DWMSC_DOWN      = &h00000001
	DWMSC_UP        = &h00000002
	DWMSC_DRAG      = &h00000004
	DWMSC_HOLD      = &h00000008
	DWMSC_PENBARREL = &h00000010
	DWMSC_NONE      = &h00000000
	DWMSC_ALL       = &hFFFFFFFF
END ENUM

'DEFINE_ENUM_FLAG_OPERATORS(DWM_SHOWCONTACT);

DECLARE FUNCTION DwmShowContact LIB "dwmapi.dll" ALIAS "DwmShowContact" (BYVAL dwPointerID AS DWORD, BYVAL eShowContact AS DWM_SHOWCONTACT) AS HRESULT

TYPE DWM_TAB_WINDOW_REQUIREMENTS AS LONG
ENUM
	DWMTWR_NONE = &h0000                    ' // This result means the window meets all requirements requested.
	DWMTWR_IMPLEMENTED_BY_SYSTEM = &h0001   ' // In some configurations, admin/user setting or mode of the system means that windows won't be tabbed
                                           ' // This requirement says that the system/mode must implement tabbing and if it does not nothing can be done to change this.
	DWMTWR_WINDOW_RELATIONSHIP = &h0002     ' // The window has an owner or parent so is ineligible for tabbing.
	DWMTWR_WINDOW_STYLES = &h0004           ' // The window has styles that make it ineligible for tabbing. To be eligible windows must:
                                           ' // Have the WS_OVERLAPPEDWINDOW (WS_CAPTION, WS_THICKFRAME, etc.) styles set.
                                           ' // Not have WS_POPUP, WS_CHILD or WS_DLGFRAME set. Not have WS_EX_TOPMOST or WS_EX_TOOLWINDOW set.
	DWMTWR_WINDOW_REGION = &h0008           ' // The window has a region (set using SetWindowRgn) making it ineligible.
	DWMTWR_WINDOW_DWM_ATTRIBUTES = &h0010   ' // The window is ineligible due to its Dwm configuration.
                                           ' // It must not extended its client area into the title bar using DwmExtendFrameIntoClientArea
                                           ' // It must not have DWMWA_NCRENDERING_POLICY set to DWMNCRP_ENABLED
	DWMTWR_WINDOW_MARGINS = &h0020          ' // The window is ineligible due to it's margins, most likely due to custom handling in WM_NCCALCSIZE.
                                           ' // The window must use the default window margins for the non-client area.
	DWMTWR_TABBING_ENABLED = &h0040         ' // The window has been explicitly opted out by setting DWMWA_TABBING_ENABLED to FALSE.
	DWMTWR_USER_POLICY = &h0080             ' // The user has configured this application to not participate in tabbing.
	DWMTWR_GROUP_POLICY = &h0100            ' // The group policy has configured this application to not participate in tabbing.
	DWMTWR_APP_COMPAT = &h0200              ' // This is set if app compat has blocked tabs for this window. Can be overridden per window by setting
                                           ' // DWMWA_TABBING_ENABLED to TRUE. That does not override any other tabbing requirements.
END ENUM

'DEFINE_ENUM_FLAG_OPERATORS(DWM_TAB_WINDOW_REQUIREMENTS);

DECLARE FUNCTION DwmGetUnmetTabRequirements LIB "dwmapi.dll" ALIAS "DwmGetUnmetTabRequirements" ( _
   BYVAL appWindow AS HWND, BYVAL value AS DWM_TAB_WINDOW_REQUIREMENTS PTR) AS HRESULT

end extern


' ########################################################################################
'                                        WRAPPERS
' ########################################################################################

' ========================================================================================
' Allows the window frame for this window to be drawn in dark mode colors.
' ========================================================================================
PRIVATE FUNCTION AfxEnableDarkModeForWindow (BYVAL hwnd AS HWND) AS HRESULT
   DIM value AS BOOL = CTRUE
   RETURN DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, @value, SIZEOF(value))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Draw windows with rounded corners.
' Supported starting with Windows 11 Build 22000.
' ========================================================================================
PRIVATE FUNCTION AfxSetWindowCornerPreference (BYVAL hwnd AS HWND, BYVAL preference AS LONG) AS HRESULT
   RETURN DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, @preference, SIZEOF(preference))
END FUNCTION
' ========================================================================================

' ########################################################################################
