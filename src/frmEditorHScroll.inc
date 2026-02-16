'    tiko editor - Programmer's Code Editor for the FreeBASIC Compiler
'    Copyright (C) 2016-2026 Paul Squires, PlanetSquires Software
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
''  frmEditorHScroll.inc
''   

#include once "frmEditorHScroll.bi"

    
' ========================================================================================
' frmEditorHScroll Window procedure
' ========================================================================================
function frmEditorHScroll_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    static as point prev_pt   ' screen pt.y cursor position
    static as long prev_xOffset
    dim as long idxWindow = iif( hwnd = HWND_FRMEDITOR_HSCROLLBAR(0), 0, 1 )

    select case uMsg
        case WM_NCDESTROY
            ' delete the allocated memory for window
            dim as CWindow ptr pWindow = AfxCWindowPtr(hwnd)
            if pWindow then delete(pWindow)
            if hwnd = HWND_FRMEDITOR_HSCROLLBAR(0) then HWND_FRMEDITOR_HSCROLLBAR(0) = 0
            if hwnd = HWND_FRMEDITOR_HSCROLLBAR(1) then HWND_FRMEDITOR_HSCROLLBAR(1) = 0
            return 0
                
        case WM_LBUTTONDOWN
            dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
            if pDoc = 0 then exit select

            dim as POINT pt
            GetCursorPos( @pt )

            dim as RECT rcClient
            GetClientRect( hwnd, @rcClient )

            MapWindowPoints( hwnd, HWND_DESKTOP, cast(point ptr, @rcClient), 2 )

            if PtInRect( @rcClient, pt ) then
                prev_pt = pt
                gApp.bDragActive = true
                SetCapture( hwnd )
            end if

'        case WM_LBUTTONDOWN
'            dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
'            if pDoc then
'                gApp.SuppressNotify = true   ' prevent SCN_UPDATEUI
'                dim as long delta = 0
'                dim as point pt: GetCursorPos( @pt )
'                dim as RECT rc = gEditorHScroll(idxWindow).rc ' covert copy to screen coordinates
'                MapWindowPoints( HWND_FRMEDITOR_HSCROLLBAR(idxWindow), HWND_DESKTOP, cast(point ptr, @rc), 2)
'                if PtInRect( @rc, pt ) then
'                    prev_pt = pt
'                    gApp.bDragActive = true
'                    SetCapture( hwnd )
'                elseif pt.x < rc.left then
'                    delta = -(rc.left - pt.x)
'                elseif pt.x > rc.right then
'                    delta = pt.x - rc.right
'                end if
                
'                ' The client area was clicked
'                if delta <> 0 then
'                    dim as RECT rc: GetClientRect( HWND_FRMEDITOR_HSCROLLBAR(idxWindow), @rc )
'                    dim as long xOffset = SciExec( pDoc->hWindow(idxWindow), SCI_GETXOFFSET, 0, 0 )
'                    gEditorHScroll(idxWindow).rc = rc
'                    gEditorHScroll(idxWindow).rc.left = xOffset
'                    gEditorHScroll(idxWindow).rc.right = xOffset + ((rc.right / gEditorHScroll(idxWindow).lineLength) * rc.right)

'                    if gEditorHScroll(idxWindow).rc.right + delta < rc.right then
'                        xOffset = xOffset + delta
'                        xOffset = max( 0, xOffset )
'                        if xOffset <> prev_xOffset then
'                            SendMessage( pDoc->hWindow(idxWindow), SCI_SETXOFFSET, xOffset, 0) 
'                            prev_xOffset = xOffset
'                            AfxRedrawWindow( HWND_FRMEDITOR_HSCROLLBAR(idxWindow) )
'                        end if   
'                    end if
'                end if
'            end if
            
        case WM_MOUSEMOVE

            if gApp.bDragActive = false then exit select

            dim as POINT pt
            GetCursorPos( @pt )

            dim as long deltaThumb = pt.x - prev_pt.x
            if deltaThumb = 0 then exit select

            prev_pt = pt

            dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
            if pDoc = 0 then exit select

            dim as long trackWidth
            dim as RECT rcClient
            GetClientRect( hwnd, @rcClient )
            trackWidth = rcClient.right - rcClient.left

            dim as long visibleWidth = gEditorHScroll(idxWindow).clientWidth
            dim as long documentWidth = gEditorHScroll(idxWindow).lineLength

            dim as long maxDocScroll = documentWidth - visibleWidth
            if maxDocScroll <= 0 then exit select

            ' Calculate thumb size
            dim as double ratio = visibleWidth / documentWidth
            dim as long thumbWidth = ratio * trackWidth
            dim as long maxThumbPos = trackWidth - thumbWidth

            if maxThumbPos <= 0 then exit select

            ' Convert thumb delta to document delta
            dim as double docPerPixel = maxDocScroll / maxThumbPos
            dim as long deltaDoc = deltaThumb * docPerPixel

            dim as long xOffset = SciExec( pDoc->hWindow(idxWindow), SCI_GETXOFFSET, 0, 0 )
            xOffset += deltaDoc

            ' Clamp in document space
            if xOffset < 0 then xOffset = 0
            if xOffset > maxDocScroll then xOffset = maxDocScroll

            SendMessage( pDoc->hWindow(idxWindow), SCI_SETXOFFSET, xOffset, 0 )
            AfxRedrawWindow( hwnd )

            return 0

'        case WM_MOUSEMOVE
'            if gApp.bDragActive then
'                dim as POINT pt: GetCursorPos( @pt )
'                if pt.x <> prev_pt.x then 
'                    dim as long delta = pt.x - prev_pt.x 

'                    prev_pt = pt
                    
'                    dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
'                    if pDoc then
'                        dim as RECT rc: GetClientRect( HWND_FRMEDITOR_HSCROLLBAR(idxWindow), @rc )
'                        dim as long xOffset = SciExec( pDoc->hWindow(idxWindow), SCI_GETXOFFSET, 0, 0 )
'                        gEditorHScroll(idxWindow).rc = rc
'                        gEditorHScroll(idxWindow).rc.left = xOffset
'                        gEditorHScroll(idxWindow).rc.right = xOffset + ((rc.right / gEditorHScroll(idxWindow).lineLength) * rc.right)

'                        if gEditorHScroll(idxWindow).rc.right + delta < rc.right then
'                            xOffset = xOffset + delta
'                            xOffset = max( 0, xOffset )
'                            if xOffset <> prev_xOffset then
'                                SendMessage( pDoc->hWindow(idxWindow), SCI_SETXOFFSET, xOffset, 0) 
'                                prev_xOffset = xOffset
'                                AfxRedrawWindow( HWND_FRMEDITOR_HSCROLLBAR(idxWindow) )
'                            end if   
'                        end if
'                    end if
'                end if
'            end if
            
        case WM_LBUTTONUP   
            gApp.SuppressNotify = false   ' allow SCN_UPDATEUI
            gApp.bDragActive = false
            prev_pt.x = 0
            prev_pt.y = 0
            ReleaseCapture
            
        case WM_ERASEBKGND
            return true

        case WM_PAINT
            dim as clsDoubleBuffer b
            b.BeginDoubleBuffer(hwnd)

            ' Paint background
            b.SetBackColors( ghEditor.BackColorScrollBar, ghEditor.BackColorScrollBar )
            b.PaintClientRect()

            dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
            if pDoc then

                dim as long trackWidth = b.rcClient.right - b.rcClient.left
                dim as long visibleWidth = gEditorHScroll(idxWindow).clientWidth
                dim as long documentWidth = gEditorHScroll(idxWindow).lineLength

                dim as long xOffset = SciExec( pDoc->hWindow(idxWindow), SCI_GETXOFFSET, 0, 0 )

                dim as long thumbWidth
                dim as long thumbLeft

                dim as long maxDocScroll = documentWidth - visibleWidth

                if documentWidth <= visibleWidth orelse maxDocScroll <= 0 then
                    ' No scrolling needed
                    thumbWidth = trackWidth
                    thumbLeft = 0
                else
                    ' Thumb size proportional to visible area
                    dim as double ratio = visibleWidth / documentWidth
                    thumbWidth = ratio * trackWidth

                    dim as long maxThumbPos = trackWidth - thumbWidth

                    ' Thumb position proportional to xOffset
                    thumbLeft = (xOffset / maxDocScroll) * maxThumbPos
                end if

                gEditorHScroll(idxWindow).rc = b.rcClient
                gEditorHScroll(idxWindow).rc.left = thumbLeft
                gEditorHScroll(idxWindow).rc.right = thumbLeft + thumbWidth

                b.SetBackColors( ghEditor.ForeColorScrollBar, ghEditor.ForeColorScrollBar )
                b.PaintRect( @gEditorHScroll(idxWindow).rc )
            end if

            b.EndDoubleBuffer()
            return 0

'        case WM_PAINT
'            dim as clsDoubleBuffer b

'            b.BeginDoubleBuffer(hwnd)
'            b.SetBackColors( ghEditor.BackColorScrollBar, ghEditor.BackColorScrollBar )
'            b.PaintClientRect()

'            dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
'            if pDoc then
'                b.SetBackColors( ghEditor.ForeColorScrollBar, ghEditor.ForeColorScrollBar )

'                ' Total window client width
'                dim as long clientWidth = b.rcClient.right - b.rcClient.left

'                ' Sum all margins
'                dim as long totalMarginWidth = 0
'                'for i as long = 0 to SC_MAX_MARGIN - 1
'                '    totalMarginWidth += SciExec( pDoc->hWindow(idxWindow), SCI_GETMARGINWIDTHN, i, 0)
'                'next

'                ' Visible text area width
'                dim as long visibleTextWidth = clientWidth - totalMarginWidth

'                ' Current horizontal scroll offset (pixels)
'                dim as long GetXOffset = SciExec( pDoc->hWindow(idxWindow), SCI_GETXOFFSET, 0, 0 )

'                dim as long thumbWidth = 0
'                dim as long trackWidth = clientWidth

'                if gEditorHScroll(idxWindow).lineLength <= visibleTextWidth then 
'                    thumbWidth = 0
'                else
'                    dim as double ratio = (visibleTextWidth / gEditorHScroll(idxWindow).lineLength)
'                    thumbWidth = ratio * trackWidth
'                end if

'                gEditorHScroll(idxWindow).rc = b.rcClient
'                gEditorHScroll(idxWindow).rc.left = GetXOffset
'                gEditorHScroll(idxWindow).rc.right = GetXOffset + thumbWidth

'                b.PaintRect( @gEditorHScroll(idxWindow).rc )
'            end if
            
'            b.EndDoubleBuffer()

'            return 0

    end Select

    ' for messages that we don't deal with
    function = DefWindowProc( hwnd, uMsg, wParam, lParam )

end function


' ========================================================================================
' frmEditorHScroll_Show
' ========================================================================================
function frmEditorHScroll_Show( byval hWndParent as HWND ) as LRESULT

    '  Create the main window and child controls
    dim pWindow as CPanelWindow ptr

    for i as long = 0 to 1
        pWindow = new CPanelWindow
        HWND_FRMEDITOR_HSCROLLBAR(i) = pWindow->Create( hWndParent, _
            @frmEditorHScroll_WndProc, 0, 0, 0, SCROLLBAR_HEIGHT, _
            WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN, WS_EX_NOACTIVATE )
    next
    
    function = 0
    
end function


' ========================================================================================
' frmEditorHScroll_NeedScrollBar
' Determine based on visible line lengths if a scrollbar should be displayed
' ========================================================================================
function frmEditorHScroll_NeedScrollBar( _
            byval pDoc as clsDocument ptr, _
            byval idxWindow as long _
            ) as long

    dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMMAIN)
    if pWindow = 0 Then exit function

    dim as RECT rc = AfxGetWindowRect( pDoc->hWindow(idxWindow) )
    MapWindowPoints( HWND_DESKTOP, HWND_FRMMAIN, cast(point ptr, @rc), 2 )
    
    dim as long GetFirstVisibleLine, GetLinesOnScreen
    dim as long ClientWidth = (rc.right - rc.left)
    dim as long ClientHeight = (rc.bottom - rc.top)

    dim as long GetXOffset, endPos
    dim as boolean needHSB = false
    
    ' Calculate total margin width
    dim as long totalMarginWidth = 0
    for i as long = 0 to SC_MAX_MARGIN - 1
        totalMarginWidth += SciExec( pDoc->hWindow(idxWindow), SCI_GETMARGINWIDTHN, i, 0 )
    next

    ' Visible TEXT area width (important) 
    dim as long visibleTextWidth = clientWidth - totalMarginWidth
    if visibleTextWidth < 0 then visibleTextWidth = 0

    GetFirstVisibleLine = SciExec( pDoc->hWindow(idxWindow), SCI_GETFIRSTVISIBLELINE, 0, 0)
    GetLinesOnScreen    = SciExec( pDoc->hWindow(idxWindow), SCI_LINESONSCREEN, 0, 0)
    
    dim as long maxWidth = 0

    for i as long = 0 to GetLinesOnScreen - 1
        dim as long docLine = GetFirstVisibleLine + i
        
        ' Safety check
        if docLine >= SciExec( pDoc->hWindow(idxWindow), SCI_GETLINECOUNT, 0, 0) then exit for

        ' Get end position of this line
        dim as long endPos = SciExec( pDoc->hWindow(idxWindow), SCI_GETLINEENDPOSITION, docLine, 0)

        ' Convert to X coordinate in pixels
        dim as long x = SciExec( pDoc->hWindow(idxWindow), SCI_POINTXFROMPOSITION, 0, endPos)

        if x > maxWidth then maxWidth = x

    next

    GetXOffset = SciExec( pDoc->hWindow(idxWindow), SCI_GETXOFFSET, 0, 0 )
    if (maxWidth > visibleTextWidth) orelse (GetXOffset <> 0) then 
        needHSB = true
    end if

    gEditorHScroll(idxWindow).lineLength = maxWidth
    gEditorHScroll(idxWindow).clientWidth = visibleTextWidth

    function = iif( needHSB, SW_SHOWNOACTIVATE, SW_HIDE )
end function

        
function frmEditorHScroll_DoNeedScrollBar( byval pDoc as clsDocument ptr ) as long
    for i as long = lbound(pDoc->hWindow) to ubound(pDoc->hWindow)
        dim as boolean isVisible = IsWindowVisible( HWND_FRMEDITOR_HSCROLLBAR(i) )
        dim as long curState = iif(isVisible, SW_SHOWNOACTIVATE, SW_HIDE)
        dim as long newState = SW_HIDE
        if isMouseOverWindow( pDoc->hWindow(i) ) orelse _
            isMouseOverWindow( HWND_FRMEDITOR_HSCROLLBAR(i) ) then 
            newState = frmEditorHScroll_NeedScrollBar( pDoc, i )
        end if
        if newState <> curState then 
            ShowWindow( HWND_FRMEDITOR_HSCROLLBAR(i), newState )
            frmMain_PositionWindows()
        end if
    next
    function = 0
end function
    
    
