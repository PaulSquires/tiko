'    tiko editor - Programmer's Code Editor for the FreeBASIC Compiler
'    Copyright (C) 2016-2025 Paul Squires, PlanetSquires Software
'
'    This program is free software: you can redistribute it and/or modify
'    it under the terms of the GNU General Public License as published by
'    the Free Software Foundation, either version 3 of the License, or
'    (at your option) any later version.
'
'    This program is distributed in the hope that it will be useful,
'    but WITHOUT any WARRANTY; without even the implied warranty of
'    MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See the
'    GNU General Public License for more details.

#include once "frmStatusBar.bi"


' ========================================================================================
' Position all child windows. Called manually and/or by WM_SIZE
' ========================================================================================
function frmStatusBar_PositionWindows() as LRESULT

    dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMMAIN_STATUSBAR)
    if pWindow = 0 then exit function
    
    ' Get the entire client area
    dim as Rect rc
    GetClientRect(HWND_FRMMAIN_STATUSBAR, @rc)

    dim as long i = 0
    dim as long nLeft = rc.left
    dim as long nSpacer = pWindow->ScaleX(4)
    
    ' the text for each panel is set in frmMain_SetStatusbar which then calls this
    ' function to determine proper sizing and placement.
    
    '''' LEFT ALIGNED STATUSBAR PANELS ''''
    i = GOTO_PANEL  ' Ln 23, Col 20
    gSBPanels(i).rc.Left   = nLeft
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nLeft + _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_GOTO
    nLeft = gSBPanels(i).rc.right + nSpacer

    '''' RIGHT ALIGNED STATUSBAR PANELS ''''
    grcGripper = rc
    grcGripper.top = (rc.bottom-rc.top) / 2
    grcGripper.left = rc.right - (nSpacer * 4)
    
    i = CRLF_PANEL  ' CRLF 
    dim as long nRight = grcGripper.left
    gSBPanels(i).rc.Left   = nRight - _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nRight
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_LINEENDINGS
    nRight = gSBPanels(i).rc.left - nSpacer

    i = UTF_PANEL  ' UTF-8
    gSBPanels(i).rc.Left   = nRight - _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nRight 
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_FILEENCODING
    nRight = gSBPanels(i).rc.left - nSpacer

    i = SPACES_PANEL  ' Spaces
    gSBPanels(i).rc.Left   = nRight - _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nRight
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_SPACES
    nRight = gSBPanels(i).rc.left - nSpacer

    i = FILETYPE_PANEL  ' Main/Resource/Module/Normal
    if gApp.IsProjectActive then
        gSBPanels(i).rc.Left   = nRight - _
            pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
        gSBPanels(i).rc.top    = rc.top
        gSBPanels(i).rc.right  = nRight
        gSBPanels(i).rc.bottom = rc.bottom
        gSBPanels(i).nID       = IDM_PROJECTFILETYPE
        nRight = gSBPanels(i).rc.left - nSpacer
    else
        SetRectEmpty( @gSBPanels(i).rc )
    end if
    
    i = BUILD_POPUP_PANEL  ' Build Configuration
    gSBPanels(i).rc.Left   = nRight - _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nRight
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_BUILDCONFIG_POPUP
    nRight = gSBPanels(i).rc.left - nSpacer

    i = BUILD_DIALOG_PANEL  ' Build Configuration dialog
    gSBPanels(i).rc.Left   = nRight - _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nRight
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_BUILDCONFIG
    nRight = gSBPanels(i).rc.left - nSpacer

    i = THEMES_DIALOG_PANEL  ' Themes/Colors dialog
    gSBPanels(i).rc.Left   = nRight - _
        pWindow->ScaleX( getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 4 ) )
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = nRight
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_THEMES
    nRight = gSBPanels(i).rc.left - nSpacer

    '''' THE MESSAGES PANEL FILLS THE REMAINING AVAILABLE SPACE ''''
    i = COMPILE_STATUS_PANEL  ' Compile status and error messages
    gSBPanels(i).rc.Left   = gSBPanels(0).rc.right
    gSBPanels(i).rc.top    = rc.top
    gSBPanels(i).rc.right  = gSBPanels(2).rc.Left
    gSBPanels(i).rc.bottom = rc.bottom
    gSBPanels(i).nID       = IDM_VIEWOUTPUT

    AfxRedrawWindow( HWND_FRMMAIN_STATUSBAR )
    function = 0
end function


' ========================================================================================
' Process WM_SIZE message for window/dialog: frmStatusBar
' ========================================================================================
function frmStatusBar_OnSize( _
            byval hwnd as HWND, _
            byval state as UINT, _
            byval cx as long, _
            byval cy as long _
            ) as LRESULT
    if state <> SIZE_MINIMIZED then
        frmStatusBar_PositionWindows()
    end if
    function = 0
end function


' ========================================================================================
' frmStatusBar Window procedure
' ========================================================================================
function frmStatusBar_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    static as long prev_idxHot = -1
    static as long curr_idxHot = -1
    static as boolean resizing
    static as point prev_pt
    static as HWND hTooltip 

    
    Select Case uMsg
        HANDLE_MSG (hwnd, WM_SIZE, frmStatusBar_OnSize)
    
    case WM_DESTROY
        dim pWindow as CWindow ptr = AfxCWindowPtr(hwnd)
        if pWindow = 0 then delete(pWindow)
        HWND_FRMMAIN_STATUSBAR = 0
        
    case WM_ERASEBKGND
        return true

    case WM_LBUTTONDOWN
        ' Are we over the resize gripper
'      dim as POINT pt: GetCursorPos( @pt )
'      MapWindowPoints( HWND_DESKTOP, hwnd, cast( POINT ptr, @pt ), 1 )
'      if PtInRect( @grcGripper, pt ) then
'         SetCursor LoadImage( Null, MAKEINTRESOURCEW(OCR_SIZENWSE), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE or LR_SHARED )
'         resizing = true
'         prev_pt = pt
            SetCapture( hwnd )
'      end if
        
    case WM_MOUSEMOVE
        dim tme as TrackMouseEvent
        tme.cbSize = sizeof(TrackMouseEvent)
        tme.dwFlags = TME_HOVER or TME_LEAVE
        tme.hwndTrack = hwnd
        tme.dwHoverTime = 20    ' HOVER_DEFAULT is 500
        TrackMouseEvent(@tme) 

        if IsWindow(hTooltip) = 0 then hTooltip = AfxAddTooltip( hwnd, "", false, false )
        
        dim as point pt: GetCursorPos( @pt )
        MapWindowPoints( HWND_DESKTOP, hwnd, cast( point ptr, @pt ), 1 )
        ' Are we over the resize gripper
'      if PtInRect( @grcGripper, pt ) then
'         SetCursor LoadImage( Null, MAKEINTRESOURCEW(OCR_SIZENWSE), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE or LR_SHARED )
'      else
'         SetCursor( LoadCursor( null, IDC_ARROW ))
'      end if
        if resizing then
'         dim as long xDelta = prev_pt.x - pt.x 
'         dim as long yDelta = prev_pt.y - pt.y
'         ' Resize the main form
'         dim as RECT rcMain = AfxGetWindowRect( HWND_FRMMAIN )
'         dim as long nWidth = rcMain.right - rcMain.left - xDelta
'         dim as long nHeight = rcMain.bottom - rcMain.top - yDelta
'         SetWindowPos( HWND_FRMMAIN, 0, 0, 0, nWidth, nHeight, SWP_NOMOVE or SWP_NOZORDER )
        else
            ' Are we over one of the status bar panels
            curr_idxHot = -1
            for i as long = lbound(gSBPanels) to ubound(gSBPanels)
                if PtInRect( @gSBPanels(i).rc, pt ) then
                    ' Only make hot panels that have actual text
                    if len(gSBPanels(i).wszText) then
                        curr_idxHot = i
                        gSBPanels(i).isHot = true
                    end if   
                else   
                    gSBPanels(i).isHot = false
                end if
            next
            if curr_idxHot <> prev_idxHot then
                AfxRedrawWindow( hwnd )
                prev_idxHot = curr_idxHot 
            end if
        end if
            
    case WM_MOUSELEAVE
        for i as long = lbound(gSBPanels) to ubound(gSBPanels)
            gSBPanels(i).isHot = false
        next
        prev_idxHot = -1
        curr_idxHot = -1
        AfxRedrawWindow( hwnd )

    case WM_LBUTTONUP
        dim as point pt: GetCursorPos( @pt )
        MapWindowPoints( HWND_DESKTOP, hwnd, cast( point ptr, @pt ), 1 )
        SetCursor( LoadCursor( null, IDC_ARROW ))
        ReleaseCapture
        resizing = false
        ' Are we over one of the status bar panels
        for i as long = lbound(gSBPanels) to ubound(gSBPanels)
            if PtInRect( @gSBPanels(i).rc, pt ) then
                PostMessage( HWND_FRMMAIN, WM_COMMAND, MAKEWPARAM(gSBPanels(i).nID, 0), 0 )
                exit for
            end if
        next   

    case WM_MOUSEHOVER
        if IsMouseOverRECT(hwnd,  gSBPanels(BUILD_DIALOG_PANEL).rc ) then 
            dim as CWSTR wszTooltip = L(277,"Build Configurations") & "..."
            AfxSetTooltipText( hTooltip, hwnd, wszTooltip )
            AfxRedrawWindow( hwnd )
        end if
        if IsMouseOverRECT(hwnd,  gSBPanels(THEMES_DIALOG_PANEL).rc ) then 
            dim as CWSTR wszTooltip = L(111,"Themes and Fonts")
            AfxSetTooltipText( hTooltip, hwnd, wszTooltip )
            AfxRedrawWindow( hwnd )
        end if
        if IsMouseOverRECT(hwnd,  gSBPanels(COMPILE_STATUS_PANEL).rc ) then 
            dim as CWSTR wszTooltip = L(251,"View Output Window")
            AfxSetTooltipText( hTooltip, hwnd, wszTooltip )
            AfxRedrawWindow( hwnd )
        end if

    case WM_PAINT
        dim as PAINTSTRUCT ps
        dim as HDC hDC
        dim as RECT rc

        dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMMAIN_STATUSBAR)
        if pWindow = 0 then exit function

        hDC = BeginPaint(hwnd, @ps)

        GetClientRect(hwnd, @rc)
        dim as long nWidth = rc.right - rc.left
        dim as long nHeight = rc.bottom - rc.top

        dim memDC as HDC      ' Double buffering
        dim hbit as HBITMAP   ' Double buffering

        memDC = CreateCompatibleDC( hDC )
        hbit  = CreateCompatibleBitmap( hDC, nWidth, nHeight )
        
        SaveDC(memDC)
        
        if hbit then SelectObject( memDC, hbit )

        FillRect( memDC, @rc, ghStatusBar.hPanelBrush )
        
        ' paint the panels
        for i as long = lbound(gSBPanels) to ubound(gSBPanels)
            if (i = BUILD_DIALOG_PANEL) orelse (i = THEMES_DIALOG_PANEL) then
                SelectObject(memDC, ghMenuBar.hFontSymbol)
            else
                SelectObject(memDC, ghStatusBar.hFontStatusBar)
            end if

            SetBkColor( memDC, iif( gSBPanels(i).isHot, ghStatusBar.BackColorHot, ghStatusBar.BackColor) )   
            SetTextColor( memDC, iif( gSBPanels(i).isHot, ghStatusBar.ForeColorHot, ghStatusBar.ForeColor) )
            FillRect( memDC, @gSBPanels(i).rc, iif( gSBPanels(i).isHot, ghStatusBar.hBackBrushHot, ghStatusBar.hBackBrush) )
            dim as long wsStyle = DT_NOPREFIX or DT_CENTER or DT_VCENTER or DT_SINGLELINE
            DrawText( memDC, gSBPanels(i).wszText.sptr, -1, cast(lpRect, @gSBPanels(i).rc), wsStyle )
            
            ' if this is the compile result panel then display the green/success or red/failure "icon"
            if i = COMPILE_STATUS_PANEL then
                if (gApp.IsProjectLoading = false) andalso (gApp.IsFileLoading = false) then
                    dim as COLORREF clr = ghStatusBar.BackColor
                    if gApp.hIconPanel = ghIconGood then clr = ghGeneral.iconsuccess
                    if gApp.hIconPanel = ghIconBad then clr = ghGeneral.iconfail
                    dim as long txtWidth = getTextWidth( HWND_FRMMAIN_STATUSBAR, gSBPanels(i).wszText, ghStatusBar.hFontStatusBar, 0 ) 
                    SetTextColor( memDC, clr )
                    dim as RECT rcBitmap = gSBPanels(i).rc
                    dim as long halfWidth = (rcBitmap.right-rcBitmap.left) / 2
                    rcBitmap.right = rcBitmap.left + halfWidth - pWindow->ScaleX((txtWidth / 2))
                    rcBitmap.left = rcBitmap.right - pWindow->ScaleX(16)

                    if ghMenuBar.hFontSymbol then SelectObject(memDC, ghMenuBar.hFontSymbol)
                    dim as long wsStyle = DT_NOPREFIX or DT_CENTER or DT_VCENTER or DT_SINGLELINE
                    DrawText( memDC, wszIconCompileResult, -1, cast(lpRect, @rcBitmap), wsStyle )
                end if
            end if   
        next

        BitBlt hDC, 0, 0, nWidth, nHeight, memDC, 0, 0, SRCCOPY 

        ' Cleanup
        RestoreDC(memDC, -1)
        if hbit  then DeleteObject(hbit)
        if memDC then DeleteDC(memDC)

        EndPaint hwnd, @ps
        return 0
        
    end Select
    
    ' for messages that we don't deal with
    function = DefWindowProc(hwnd, uMsg, wParam, lParam)

end function


' ========================================================================================
' frmStatusBar_Show
' ========================================================================================
function frmStatusBar_Show( byval hwndParent as HWND ) as LRESULT

    '  Create the main window and child controls
    dim pWindow as CWindow ptr = New CWindow

    HWND_FRMMAIN_STATUSBAR = pWindow->Create( hwndParent, "", @frmStatusBar_WndProc, _
        0, 0, 0, STATUSBAR_HEIGHT, _
        WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_CLIPCHILDREN, _
        WS_EX_CONTROLPARENT or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)

    ' Disable background erasing by only assigning the one style
    pWindow->ClassStyle = CS_DBLCLKS
    
    frmStatusBar_PositionWindows()
    function = 0
    
end function

