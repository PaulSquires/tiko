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
    

''
''  frmPanelMenu.inc
''   

#include once "frmPanel.bi"
#include once "frmPanelMenu.bi"


' ========================================================================================
' Format the tooltip based on menu id
' ========================================================================================
function frmPanelMenu_FormatTooltip( byval id as integer ) as CWSTR
    dim as CWSTR wszTooltip = getMenuText(id)
    dim as CWSTR wszCaption = rtrim(AfxStrParse(wszTooltip, 1, wchr(9)), "...")
    dim as CWSTR wszShortcut = AfxStrParse(wszTooltip, 2, wchr(9))
    
    if len(wszShortcut) then wszShortcut = " (" & wszShortcut & ")"
    
    return wszCaption & wszShortcut
end function


' ========================================================================================
' Position all child windows. Called manually and/or by WM_SIZE
' ========================================================================================
function frmPanelMenu_PositionWindows() as LRESULT

    dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMPANEL_MENU)
    if pWindow = 0 then exit function
    
    ' Get the entire client area
    dim as Rect rc
    GetClientRect( HWND_FRMPANEL_MENU, @rc )

    dim as long nButtonWidth = pWindow->ScaleX( 24 )
    dim as long nButtonHeight = pWindow->ScaleY( 24 )
    dim as long nLeft = pWindow->ScaleX( 10 )
    dim as long nTop = pWindow->ScaleY( 8 )
    dim as long nRight = rc.right - pWindow->ScaleX( 6 )

    gPanelMenu(0).wszCaption = wszIconExplorer
    gPanelMenu(0).id = IDM_VIEWEXPLORER
    gPanelMenu(0).rc = type(nLeft, nTop, nLeft + nButtonWidth, nTop + nButtonHeight)
    gPanelMenu(0).wszTooltip = frmPanelMenu_FormatTooltip(IDM_VIEWEXPLORER)
    
    nLeft += nButtonWidth
    gPanelMenu(1).wszCaption = wszIconFunctions
    gPanelMenu(1).id = IDM_FUNCTIONLIST
    gPanelMenu(1).rc = type(nLeft, nTop, nLeft + nButtonWidth, nTop + nButtonHeight)
    gPanelMenu(1).wszTooltip = frmPanelMenu_FormatTooltip(IDM_FUNCTIONLIST)
    
    ' Bookmarks
    nLeft += nButtonWidth
    gPanelMenu(2).wszCaption = wszIconBookmarks
    gPanelMenu(2).id = IDM_BOOKMARKSLIST
    gPanelMenu(2).rc = type(nLeft, nTop, nLeft + nButtonWidth, nTop + nButtonHeight)
    gPanelMenu(2).wszTooltip = frmPanelMenu_FormatTooltip(IDM_BOOKMARKSLIST)

    ' Settings (Environment Options)
    nLeft += nButtonWidth
    gPanelMenu(3).wszCaption = wszIconSettings
    gPanelMenu(3).id = IDM_OPTIONSDIALOG
    gPanelMenu(3).rc = type(nLeft, nTop, nLeft + nButtonWidth, nTop + nButtonHeight)
    gPanelMenu(3).wszTooltip = frmPanelMenu_FormatTooltip(IDM_OPTIONSDIALOG)
    
    ' Build & Execute
    nLeft = nRight - nButtonWidth
    gPanelMenu(5).wszCaption = wszIconBuildExecute
    gPanelMenu(5).id = IDM_BUILDEXECUTE
    gPanelMenu(5).rc = type(nLeft, nTop, nLeft + nButtonWidth, nTop + nButtonHeight)
    gPanelMenu(5).wszTooltip = frmPanelMenu_FormatTooltip(IDM_BUILDEXECUTE)
    
    ' Compile
    nLeft -= nButtonWidth
    gPanelMenu(4).wszCaption = wszIconCompile
    gPanelMenu(4).id = IDM_COMPILE
    gPanelMenu(4).rc = type(nLeft, nTop, nLeft + nButtonWidth, nTop + nButtonHeight)
    gPanelMenu(4).wszTooltip = frmPanelMenu_FormatTooltip(IDM_COMPILE)

    function = 0
end function


' ========================================================================================
' Process WM_SIZE message for window/dialog: frmPanel
' ========================================================================================
function frmPanelMenu_OnSize( _
            byval hwnd as HWND, _
            byval state as UINT, _
            byval cx as long, _
            byval cy as long _
            ) as LRESULT
    if state <> SIZE_MINIMIZED then
        ' Position all of the child windows
        frmPanelMenu_PositionWindows
    end if
    function = 0
end function
        

' ========================================================================================
' Process WM_PAINT message for window/dialog: frmPanelMenu
' ========================================================================================
function frmPanelMenu_OnPaint( byval hwnd as HWND ) as LRESULT
            
    dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMPANEL_MENU)
    if pWindow = 0 then exit function

    dim as PAINTSTRUCT ps
    dim as HDC hDc
    dim as HPEN hPenNull
    dim as HPEN hPenSolid 
    dim as RECT rc
    
    dim as long wsStyle 
    
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

    FillRect( memDC, @rc, ghPanel.hPanelBrush )

    for i as integer = lbound(gPanelMenu) to ubound(gPanelMenu)
        dim as CWSTR wszCaption = gPanelMenu(i).wszCaption
        dim as RECT rc = gPanelMenu(i).rc
        dim as integer id = gPanelMenu(i).id
        
        SetTextColor( memDC, ghPanel.ForeColorHot )
        if isMouseOverRECT( hwnd, rc ) then
            SelectObject( memDC, ghPanel.hBackBrushHot )
            SetBkColor( memDC, ghPanel.BackColorHot )
        else
            SelectObject( memDC, ghPanel.hPanelBrush )
            SetBkColor( memDC, ghPanel.BackColor )
        end if

        if (hPenNull = 0) then hPenNull = CreatePen( PS_NULL, 1, 0 )  ' null/invisible pen
        SelectObject( memDC, hPenNull )
        RoundRect( memDC, rc.left, rc.top, rc.right, rc.bottom, 20, 20 )
        
        wsStyle = DT_NOPREFIX or DT_CENTER or DT_VCENTER or DT_SINGLELINE
        SelectObject( memDC, ghMenuBar.hFontSymbol )
        DrawText( memDC, wszCaption, -1, cast(lpRect, @rc), wsStyle )
        
        ' Should we underline this icon as actively selected    
        dim as boolean bDrawUnderline = false
        if (id = IDM_VIEWEXPLORER) andalso _
            (gPanel.hActiveChild = HWND_FRMEXPLORER) then bDrawUnderline = true
        if (id = IDM_FUNCTIONLIST) andalso _
            (gPanel.hActiveChild = HWND_FRMFUNCTIONS) then bDrawUnderline = true
        if (id = IDM_BOOKMARKSLIST) andalso _
            (gPanel.hActiveChild = HWND_FRMBOOKMARKS) then bDrawUnderline = true
        
        if bDrawUnderline then
            rc.left += pWindow->ScaleX(2)
            rc.right -= pWindow->ScaleX(2)
            if (hPenSolid = 0) then hPenSolid = CreatePen( PS_SOLID, 1, ghPanel.ForeColorHot )
            SelectObject( memDC, hPenSolid)
            MoveToEx( memDC, rc.left, rc.bottom, null )
            LineTo( memDC, rc.right, rc.bottom )   
        end if
        
    next
    
    BitBlt( hDC, 0, 0, nWidth, nHeight, memDC, 0, 0, SRCCOPY )

    ' Cleanup
    RestoreDC( memDC, -1 )
    
    if hPenNull  then DeleteObject( hPenNull )
    if hPenSolid then DeleteObject( hPenSolid )
    if hbit      then DeleteObject( hbit )
    if memDC     then DeleteDC( memDC )

    EndPaint( hwnd, @ps )

    function = 0
end function



' ========================================================================================
' frmPanelMenu Window procedure
' ========================================================================================
function frmPanelMenu_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    static wszPrevTooltip as CWSTR

    static hTooltip as HWND
    if (uMsg = WM_DESTROY) andalso (IsWindow(hToolTip)) then DestroyWindow(hToolTip)

    select case uMsg
        HANDLE_MSG (hwnd, WM_SIZE,  frmPanelMenu_OnSize)
        HANDLE_MSG (hwnd, WM_PAINT, frmPanelMenu_OnPaint)
    
    case WM_ERASEBKGND
        return true

    case WM_MOUSEMOVE
        dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMPANEL_MENU)
        if pWindow = 0 then exit function

        dim tme as TrackMouseEvent
        tme.cbSize = sizeof(TrackMouseEvent)
        tme.dwFlags = TME_HOVER or TME_LEAVE
        tme.dwHoverTime = 20    ' HOVER_DEFAULT is 500
        tme.hwndTrack = hwnd
        TrackMouseEvent(@tme) 
        
        if IsWindow(hTooltip) = 0 then hTooltip = AfxAddTooltip( hwnd, "", false, false )

        for i as integer = lbound(gPanelMenu) to ubound(gPanelMenu)
            dim as boolean isHot = isMouseOverRECT(hwnd, gPanelMenu(i).rc)
            if isHot <> gPanelMenu(i).isPrevHot then
                gPanelMenu(i).isPrevHot = isHot
                AfxRedrawWindow( hwnd )
            end if
        next

    case WM_LBUTTONDOWN
        dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMPANEL_MENU)
        if pWindow = 0 then exit function

        
    case WM_LBUTTONUP
        dim as integer id = -1
        for i as integer = lbound(gPanelMenu) to ubound(gPanelMenu)
            dim as boolean isHot = isMouseOverRECT(hwnd, gPanelMenu(i).rc)
            if isHot then
                id = gPanelMenu(i).id
                exit for
            end if
        next
        if id <> -1 then
            frmMain_OnCommand( HWND_FRMMAIN, id, 0, 0 )
            AfxRedrawWindow(hwnd)
        end if


    case WM_MOUSELEAVE
        for i as integer = lbound(gPanelMenu) to ubound(gPanelMenu)
            gPanelMenu(i).isPrevHot = false
        next
        AfxRedrawWindow(hwnd)


    case WM_MOUSEHOVER
        dim as CWSTR wszTooltip 
        for i as integer = lbound(gPanelMenu) to ubound(gPanelMenu)
            dim as boolean isHot = isMouseOverRECT(hwnd, gPanelMenu(i).rc)
            if isHot then
                wszTooltip = gPanelMenu(i).wszTooltip
                exit for
            end if
        next
        if wszTooltip <> wszPrevTooltip then
            AfxSetTooltipText( hTooltip, hwnd, wszTooltip )
            wszPrevTooltip = wszTooltip
            AfxRedrawWindow( hwnd )
        end if
        
    end select

    ' for messages that we don't deal with
    function = DefWindowProc( hwnd, uMsg, wParam, lParam )

end function


' ========================================================================================
' frmPanelMenu_Show
' ========================================================================================
function frmPanelMenu_Show( byval hwndParent as hwnd ) as LRESULT

    '  Create the main window and child controls
    dim pWindow as CWindow ptr = new CWindow

    HWND_FRMPANEL_MENU = pWindow->Create( hwndParent, "Panel Menu", @frmPanelMenu_WndProc, _
        0, 0, 0, 0, _
        WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN, _
        WS_EX_CONTROLPARENT or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    ' Disable background erasing by only assigning the one style
    pWindow->ClassStyle = CS_DBLCLKS

    function = 0
    
end function
