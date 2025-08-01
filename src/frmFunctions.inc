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
''  frmFunctions.inc
''   

#include once "frmFunctions.bi"
#include once "clsDB2.bi"

' ========================================================================================
' Reparse any dirty files
' ========================================================================================
function frmFunctions_ReparseFiles() as long
    '  Need to re-parse any dirty files. This is especially important for QuickRun scenarios
    '  where the file is never physically saved.
    dim pDoc as clsDocument ptr = gApp.pDocList
    do until pDoc = 0
        If cbool(SciExec( pDoc->hWindow(0), SCI_GETMODIFY, 0, 0 )) orelse pDoc->UserModified then
            pDoc->bNeedsParsing = true
            pDoc->ParseDocument()
        end if
        pDoc = pDoc->pDocNext
    loop   
    function = 0
end function

' ========================================================================================
' Get the Functions line number from the Listbox line
' ========================================================================================
function getFunctionsLineNumber( byval wszCaption as CWSTR ) as long
    ' do not use Parse for this because line may contain embedded % in description
    ' lineNum%functionName%prototype
    dim as long nLineNum 
    dim as long f1
    f1 = instr(wszCaption, "%")
    if f1 then nLineNum = val(left(wszCaption, f1-1))
    function = nLineNum
end function

' ========================================================================================
' Get the Functions function name from the Listbox line
' ========================================================================================
function getFunctionsFunctionName( byval wszCaption as CWSTR ) as CWSTR
    ' do not use Parse for this because line may contain embedded % in description
    ' lineNum%functionName%prototype
    dim as CWSTR wszTemp
    dim as long f1
    f1 = instr(wszCaption, "%")
    if f1 then wszTemp = mid(wszCaption, f1 + 1)
    f1 = instr(wszTemp, "%")
    if f1 then wszTemp = left(wszTemp, f1 - 1)
    function = wszTemp
end function

' ========================================================================================
' Get the Functions prototype from the Listbox line
' ========================================================================================
function getFunctionsPrototype( byval wszCaption as CWSTR ) as CWSTR
    ' do not use Parse for this because line may contain embedded % in description
    ' lineNum%functionName%prototype
    dim as CWSTR wszTemp
    dim as long f1
    f1 = instr(wszCaption, "%")
    if f1 then wszTemp = mid(wszCaption, f1 + 1)
    f1 = instr(wszTemp, "%")
    if f1 then wszTemp = mid(wszTemp, f1 + 1)
    function = wszTemp
end function

' ========================================================================================
' Expand/Collapse all Functions Nodes
' ========================================================================================
function frmFunctions_ExpandAll() as long
    dim pDoc as clsDocument ptr = gApp.pDocList
    do until pDoc = 0
        pDoc->bFunctionsExpanded = true
        pDoc = pDoc->pDocNext
    loop
    LoadFunctionsFiles()
    function = 0
end function

function frmFunctions_CollapseAll() as long
    dim pDoc as clsDocument ptr = gApp.pDocList
    do until pDoc = 0
        pDoc->bFunctionsExpanded = false
        pDoc = pDoc->pDocNext
    loop
    LoadFunctionsFiles()
    function = 0
end function   

' ========================================================================================
' Select the listbox item that matches the incoming pDoc item. Do not open nodes to
' find a possible hidden document because the user may have purposely closed a node
' and we should not re-open it automatically.
' ========================================================================================
function frmFunctions_SelectItemData( byval pDoc as clsDocument ptr ) as boolean
    ' Select the Function List listbox item where the ItemData holds the pDoc handle.
    for i as long = 0 to ListBox_GetCount( HWND_FRMFUNCTIONS_LISTBOX ) - 1 
        if ListBox_GetItemData(HWND_FRMFUNCTIONS_LISTBOX, i) = pDoc then
            ListBox_SetCurSel( HWND_FRMFUNCTIONS_LISTBOX, i )
            if ListBox_GetTopIndex( HWND_FRMFUNCTIONS_LISTBOX ) <> i then
                ListBox_SetTopIndex( HWND_FRMFUNCTIONS_LISTBOX, i )
            end if   
            AfxRedrawWindow( HWND_FRMFUNCTIONS_LISTBOX )
            return true
        end if   
    next 
    return false
end function


' ========================================================================================
' Position all child windows. Called manually and/or by WM_SIZE
' ========================================================================================
function frmFunctions_PositionWindows() as LRESULT
    ' Get the entire client area
    dim as Rect rc
    GetClientRect( HWND_FRMFUNCTIONS, @rc )

    SetWindowPos( HWND_FRMFUNCTIONS_LISTBOX, 0, _
                    rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, _
                    SWP_NOZORDER )

    function = 0
end function


' ========================================================================================
' Process WM_DESTROY message for window/dialog: frmFunctions
' ========================================================================================
function frmFunctions_OnDestroy( byval hwnd as HWND ) as LRESULT 
    dim pWindow as CWindow ptr = AfxCWindowPtr(hwnd)
    if pWindow then delete(pWindow)
    HWND_FRMFUNCTIONS = 0
    function = 0
end function


' ========================================================================================
' Process WM_SIZE message for window/dialog: frmFunctions
' ========================================================================================
function frmFunctions_OnSize( _
            byval hwnd as HWND, _
            byval state as UINT, _
            byval cx as long, _
            byval cy as long _
            ) as LRESULT
    if state <> SIZE_MINIMIZED then
        ' Position all of the child windows
        frmFunctions_PositionWindows
    end if
    function = 0
end function
        
' ========================================================================================
' Process WM_PAINT message for window/dialog: frmFunctions
' ========================================================================================
function frmFunctions_OnPaint( byval hwnd as HWND ) as LRESULT
    dim as clsDoubleBuffer b

    b.BeginDoubleBuffer(hwnd)
    b.SetBackColors( ghPanel.BackColor, ghPanel.BackColorHot )
    b.PaintClientRect()
    b.EndDoubleBuffer()
    
    function = 0
end function


' ========================================================================================
' Process WM_MEASUREITEM message for window/dialog: frmFunctions
' ========================================================================================
function frmFunctions_OnMeasureItem( _
            byval hwnd as HWND, _
            byval lpmis as MEASUREITEMSTRUCT ptr _
            ) as long
    ' Set the height of the list box items. 
    dim as long nHeight = iif(gConfig.CompactMenus, EXPLORERITEM_HEIGHT_COMPACT, EXPLORERITEM_HEIGHT)
    dim pWindow as CWindow ptr = AfxCWindowPtr(hwnd)
    lpmis->itemHeight = pWindow->ScaleY(nHeight)
        
    function = 0
end function


' ========================================================================================
' Process WM_DRAWITEM message for window/dialog: frmFunctions
' ========================================================================================
function frmFunctions_OnDrawItem( _
            byval hwnd as HWND, _
            byval lpdis as const DRAWITEMSTRUCT ptr _
            ) as long

    dim pWindow as CWindow ptr = AfxCWindowPtr(HWND_FRMMAIN)
    if pWindow = 0 then exit function

    if lpdis = 0 then exit function
    
    if ( lpdis->itemAction = ODA_DRAWENTIRE ) orelse _
        ( lpdis->itemAction = ODA_SELECT ) orelse _
        ( lpdis->itemAction = ODA_FOCUS ) then

        dim as clsDoubleBuffer b

        b.BeginDoubleBuffer(lpdis->hwndItem, lpdis->hDC, lpdis->rcItem)

        dim as boolean IsHot = false
        dim as boolean isNodeHeader = false
        dim as boolean isIconDown = false
        
        if isMouseOverRECT(lpdis->hwndItem, b.rcClient) then IsHot = true   
        if isMouseOverWindow( HWND_FRMPANEL_VSCROLLBAR ) then IsHot = false
        if ListBox_GetSel(lpdis->hwndItem, lpdis->itemID) then IsHot = true

        dim as COLORREF backclr = iif( IsHot, ghPanel.BackColorHot,  ghPanel.BackColor)
        dim as COLORREF foreclr = iif( IsHot, ghPanel.ForeColorHot,  ghPanel.ForeColor)
        b.SetForeColors(foreclr, foreclr)
        b.SetBackColors(backclr, backclr)

        dim as CWSTR wszCaption = AfxGetListBoxText(lpdis->hwndItem, lpdis->ItemID)
        dim as clsDocument ptr pDoc = cast(clsDocument ptr, lpdis->itemData)

       ' if this is a "node" header
        if left(wszCaption, 4) = "true" then
            isNodeHeader = true
            isIconDown = true
            if pDoc then wszCaption = AfxStrPathName( "NAMEX", pDoc->DiskFilename )
        elseif left(wszCaption, 5) = "false" then
            isNodeHeader = true
            isIconDown = false
            if pDoc then wszCaption = AfxStrPathName( "NAMEX", pDoc->DiskFilename )
        else
            ' must be a function line 
            wszCaption = getFunctionsFunctionName( wszCaption )
        end if

        ' Create our rect that works with the entire line
        dim as RECT rc
        SetRect( @rc, 0, 0, b.rcClientWidth, b.rcClientHeight )
        dim as RECT rcText = rc 
        dim as RECT rcBitmap = rc 
        
        ' Paint the entire background
        b.PaintRect( @rc )

        ' indent the text based on its type
        if isNodeHeader then
            b.SetFont( SYMBOLFONT_10 )
            rcBitmap.right = rcBitmap.left + pWindow->ScaleX(20)
            dim as CWSTR wszBitmap = iif(isIconDown, wszIconChevronDown, wszIconChevronRight) 
            b.PaintText( wszBitmap, @rcBitmap, DT_CENTER )

            b.SetFont( GUIFONT_10 )
            rcText.left = rcBitmap.right
            b.PaintText( wszCaption, @rcText, DT_LEFT )
        else
            ' This would be a regular file.
            rcBitmap.left = rcText.left + pWindow->ScaleX(20)
            rcBitmap.right = rcBitmap.left + pWindow->ScaleX(20) 

            b.SetFont( GUIFONT_10 )  ' use GUI rather than SYMBOL b/c of dot icon
            b.PaintText( wszIconDocument, @rcBitmap, DT_CENTER )

            b.SetFont( GUIFONT_10 )
            rcText.left = rcBitmap.right
            b.PaintText( wszCaption, @rcText, DT_LEFT )
        end if

        b.EndDoubleBuffer()

    end if   

    function = true
    
end function

' ========================================================================================
' Process WM_COMMAND message for window/dialog: frmFunctions
' ========================================================================================
function frmFunctions_OnCommand( _
            byval hwnd as HWND, _
            byval id as long, _
            byval hwndCtl as HWND, _
            byval codeNotify as UINT _
            ) as LRESULT

    select case codeNotify
        case LBN_SELCHANGE
            ' update the highlighting of the current line
            AfxRedrawWindow(hwndCtl)
            ' update the scrollbar position if necessary
            frmFunctions_PositionWindows()
    end select      

    function = 0
end function


' ========================================================================================
' frmFunctions Window procedure
' ========================================================================================
function frmFunctions_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    select case uMsg
        HANDLE_MSG (hwnd, WM_DESTROY,     frmFunctions_OnDestroy)
        HANDLE_MSG (hwnd, WM_SIZE,        frmFunctions_OnSize)
        HANDLE_MSG (hwnd, WM_PAINT,       frmFunctions_OnPaint)
        HANDLE_MSG (hwnd, WM_COMMAND,     frmFunctions_OnCommand)
        HANDLE_MSG (hwnd, WM_MEASUREITEM, frmFunctions_OnMeasureItem)
        HANDLE_MSG (hwnd, WM_DRAWITEM,    frmFunctions_OnDrawItem)
    
    case WM_ERASEBKGND
        return true

    end select
    
    ' for messages that we don't deal with
    function = DefWindowProc( hwnd, uMsg, wParam, lParam )

end function

' ========================================================================================
' frmFunctionsListBox_SubclassProc 
' ========================================================================================
function frmFunctionsListBox_SubclassProc ( _
            byval hWin   as HWND, _                 ' // Control window handle
            byval uMsg   as UINT, _                 ' // Type of message
            byval _wParam as WPARAM, _               ' // First message parameter
            byval _lParam as LPARAM, _               ' // Second message parameter
            byval uIdSubclass as UINT_PTR, _        ' // The subclass ID
            byval dwRefData as DWORD_PTR _          ' // Pointer to reference data
            ) as LRESULT

    static as long accumDelta
    
    static as CWSTR wszPrevTooltip 
    static as HWND hTooltip
    if (uMsg = WM_DESTROY) andalso (IsWindow(hToolTip)) then DestroyWindow(hToolTip)
        
    ' keep track of last index we were over so that we only issue a 
    ' repaint if the cursor has moved off of the line
    static as long nLastIdx = -1
        
    select case uMsg
        case MSG_USER_LOAD_FUNCTIONSFILES
            LoadFunctionsFiles()

        case WM_MOUSEWHEEL
            ' accumulate delta until scroll one line (up +120, down -120). 
            ' 120 is the Microsoft default delta
            dim as long zDelta = GET_WHEEL_DELTA_WPARAM( _wParam )
            dim as long nTopIndex = SendMessage( hWin, LB_GETTOPINDEX, 0, 0 ) 
            accumDelta = accumDelta + zDelta
            if accumDelta >= 120 then       ' scroll up 3 lines
                nTopIndex = nTopIndex - 3
                nTopIndex = max( 0, nTopIndex )
                SendMessage( hWin, LB_SETTOPINDEX, nTopIndex, 0 ) 
                accumDelta = 0
                frmPanel_PositionWindows
            elseif accumDelta <= -120 then  ' scroll down 3 lines
                nTopIndex = nTopIndex + 3
                SendMessage( hWin, LB_SETTOPINDEX, nTopIndex, 0 ) 
                accumDelta = 0
                frmPanel_PositionWindows 
            end if
            
        case WM_MOUSEMOVE
            ' Track that we are over the control in order to catch the 
            ' eventual WM_MOUSEHOVER and WM_MOUSELEAVE events
            dim tme as TrackMouseEvent
            tme.cbSize = sizeof(TrackMouseEvent)
            tme.dwFlags = TME_HOVER or TME_LEAVE
            tme.hwndTrack = hWin
            tme.dwHoverTime = 1
            TrackMouseEvent(@tme) 
            
            if IsWindow(hTooltip) = 0 then hTooltip = AfxAddTooltip( hWin, "", false, false )

            ' get the item rect that the mouse is over and only invalidate
            ' that instead of the entire listbox
            dim as RECT rc
            dim as long idx = Listbox_ItemFromPoint( hWin, GET_X_LPARAM(_lParam), GET_Y_LPARAM(_lParam)) 
            ' The return value contains the index of the nearest item in the LOWORD. The HIWORD is zero 
            ' if the specified point is in the client area of the list box, or one if it is outside the 
            ' client area.
            if hiword(idx) <> 1 then
                if idx <> nLastIdx then
                    ListBox_GetItemRect( hWin, idx, @rc )
                    InvalidateRect( hWin, @rc, true )
                    ListBox_GetItemRect( hWin, nLastIdx, @rc )
                    InvalidateRect( hWin, @rc, true )
                    nLastIdx = idx
                end if
            end if
                            
        case WM_MOUSEHOVER
            dim as CWSTR wszTooltip 
            dim as long idx = Listbox_ItemFromPoint( hWin, GET_X_LPARAM(_lParam), GET_Y_LPARAM(_lParam)) 
            ' The return value contains the index of the nearest item in the LOWORD. The HIWORD is zero 
            ' if the specified point is in the client area of the list box, or one if it is outside the 
            ' client area.
            if hiword(idx) <> 1 then
                wszTooltip = ""
                dim as CWSTR wszCaption = AfxGetListBoxText( hWin, idx )
                if (left(wszCaption, 4) = "true") orelse (left(wszCaption, 5) = "false") then
                    dim as clsDocument ptr pDoc = cast(clsDocument ptr, ListBox_GetItemData( hWin, idx ))
                    if pDoc then wszTooltip = pDoc->DiskFilename
                else
                    ' Get the function prototype and display it in popup multiline tooltip
                    wszTooltip = getFunctionsPrototype(wszCaption)
                    if len(wszTooltip) then
                        SendMessage( hTooltip, TTM_SETMAXTIPWIDTH, 0, 300 )
                        wszTooltip = FormatCodetip( wszTooltip )
                    end if   
                end if
                ' Display the tooltip
                if wszPrevTooltip <> wszTooltip then
                    AfxSetTooltipText( hTooltip, hWin, wszTooltip )
                    wszPrevTooltip = wszTooltip
                end if   
            end if
            
        case WM_MOUSELEAVE
            wszPrevTooltip = ""
            nLastIdx = -1
            AfxRedrawWindow(hWin)   
            
        case WM_LBUTTONUP
            ' determine if we clicked on a function name or a node header
            dim as RECT rc
            dim as long idx = Listbox_ItemFromPoint( hWin, GET_X_LPARAM(_lParam), GET_Y_LPARAM(_lParam)) 
            ' The return value contains the index of the nearest item in the LOWORD. The HIWORD is zero 
            ' if the specified point is in the client area of the list box, or one if it is outside the 
            ' client area.
            if hiword(idx) <> 1 then
                dim as clsDocument ptr pDoc = cast(clsDocument ptr, ListBox_GetItemData( hWin, idx ))
                dim as CWSTR wszCaption = AfxGetListBoxText( hWin, idx )
                if (left(wszCaption, 4) = "true") orelse (left(wszCaption, 5) = "false") then
                    OpenSelectedDocument( pDoc->DiskFilename )
                else
                    ' Attempt to show the function name
                    dim as long nLineNum = getFunctionsLinenumber( wszCaption )
                    dim as CWSTR wszFunctionName = getFunctionsFunctionName( wszCaption )
                    dim as CWSTR wszDiskFilename 
                    if pDoc then wszDiskFilename = pDoc->DiskFilename
                    OpenSelectedDocument( wszDiskFilename, wszFunctionName, nLineNum )
                end if
            end if

                                    
        case WM_ERASEBKGND
            ' if the number of lines in the listbox maybe less than the number per page then 
            ' calculate from last item to bottom of listbox, otherwise calculate based on
            ' the mod of the lineheight to listbox height so we can color the partial line
            ' that won't be displayed at the bottom of the list.
            dim as RECT rc = GetListBoxEmptyClientArea( hWin )
            if rc.top < rc.bottom then
                dim as HDC _hDC = cast(HDC, _wParam)
                PaintRect( _hDC, @rc, ghPanel.BackColor )
            end if
            return true
        
        Case WM_DESTROY
            ' REQUIRED: Remove control subclassing
            RemoveWindowSubclass( hWin, @frmFunctionsListBox_SubclassProc, uIdSubclass )
    end select
    
    ' For messages that we don't deal with
    function = DefSubclassProc( hWin, uMsg, _wParam, _lParam )

end function


' ========================================================================================
' frmFunctions_Show
' ========================================================================================
function frmFunctions_Show( byval hWndParent as HWND ) as LRESULT

    '  Create the main window and child controls
    dim pWindow as CPanelWindow ptr = new CPanelWindow

    HWND_FRMFUNCTIONS = pWindow->Create( hWndParent, @frmFunctions_WndProc )
    ' Disable background erasing by only assigning the one style
    pWindow->ClassStyle = CS_DBLCLKS

    HWND_FRMFUNCTIONS_LISTBOX = _ 
        pWindow->AddControl("LISTBOX", , IDC_FRMFUNCTIONS_LISTBOX, "", 0, 0, 0, 0, _
        WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or WS_TABSTOP or _
        LBS_NOINTEGRALHEIGHT or LBS_OWNERDRAWFIXED or LBS_HASSTRINGS or LBS_NOTIFY, _
        WS_EX_LEFT or WS_EX_RIGHTSCROLLBAR, , _
        cast(SUBCLASSPROC, @frmFunctionsListBox_SubclassProc), _
        IDC_FRMFUNCTIONS_LISTBOX, cast(DWORD_PTR, @pWindow))

    function = 0
    
end function


' ========================================================================================
' Simple QuickSort of Filename array
' ========================================================================================
function QuickSortpDocs( pDocs() as clsDocument ptr, lo as long, hi as long ) as long
    dim as long i, j
    dim as CWSTR pivot
    
    if lo < hi then
        i = lo : j = hi
        pivot = ucase( pDocs( (lo+hi)/2 )->DiskFilename )
        do
            while ucase(pDocs(i)->DiskFilename) < pivot and i < hi: i += 1: wend
            while ucase(pDocs(j)->DiskFilename) > Pivot and j > lo: j -= 1: wend
            if i <= j then swap pDocs(i), pDocs(j): i += 1: j -= 1
        loop while i <= j
        if lo < j then QuickSortpDocs( pDocs(), lo, j )
        if hi > i then QuickSortpDocs( pDocs(), i, hi )
    end if
    
    function = 0
end function

' ========================================================================================
' Simple QuickSort of Function Name array
' ========================================================================================
function QuickSortFuncs( a() as FUNCTION_NODE_TYPE, lo as long, hi as long ) as long
    dim as long i, j
    dim as CWSTR pivot
    
    if lo < hi then
        i = lo : j = hi
        pivot = ucase( a( (lo+hi)/2 ).wszFunctionName )
        do
            while ucase(a(i).wszFunctionName) < pivot and i < hi: i += 1: wend
            while ucase(a(j).wszFunctionName) > Pivot and j > lo: j -= 1: wend
            if i <= j then swap a(i), a(j): i += 1: j -= 1
        loop while i <= j
        if lo < j then QuickSortFuncs( a(), lo, j )
        if hi > i then QuickSortFuncs( a(), i, hi )
    end if
    
    function = 0
end function


' ========================================================================================
' LoadFilesAndFunctions
' This will clear the current list of files in the listbox and repopulate it.
' ========================================================================================
function LoadFilesAndFunctions() as long
    dim as HWND hList = GetDlgItem(HWND_FRMFUNCTIONS, IDC_FRMFUNCTIONS_LISTBOX)
    
    ' Hide the listbox while it is loading so that we don't get the unpainted
    ' white background from the empty listbox
    ShowWindow( hList, SW_HIDE )
    
    ' Save the topindex because we will restore it after filling the new contents 
    dim as long nTopIndex = SendMessage( hList, LB_GETTOPINDEX, 0, 0 ) 

    ' Clear all content from the listbox
    ListBox_ResetContent(hList)
    
    dim wszText as wstring * MAX_PATH

    dim pData as DB2_DATA ptr
    dim as CWSTR wszNodeName
    
    ' Filename node line format. The drawing routine will parse this string to determine
    ' what glyph to display as well as the filename only portion of the diskfilename.
    ' true     ' expanded node
    ' false    ' collapsed node
    ' Function node line format. 
    ' 231%FunctionName%prototype  ' function starts at line 231 of the file

    ' **** FEB 8, 2022. Change approach to NOT allow the Functions list to be expanded
    ' or collapsed. This should lead to a better user experience because the now all
    ' functions are always shown and available and the user can easily activate the base
    ' filename by clicking on it. The user can also still always navigate between files
    ' via the Explorer.
    ' Leave the expand/collapse code in case it is decided later to revert this approach.
    
    ' Iterate all pDoc in the project/files list. Create an array and then
    ' sort it alphabetically.
    dim as long ub, idx
    redim pDocs(any) as clsDocument ptr
    
    dim pDoc as clsDocument ptr = gApp.pDocList
    do until pDoc = 0
        ub = ubound(pDocs) + 1
        redim preserve pDocs(ub)
        pDocs(ub) = pDoc
        pDoc = pDoc->pDocNext
    loop

    QuickSortpDocs( pDocs(), lbound(pDocs), ubound(pDocs) )
    
    ' Get the functions (and sort them) for each file
    redim arrFuncs(any) as FUNCTION_NODE_TYPE
    
    for i as long = lbound(pDocs) to ubound(pDocs)
    
        dim as CWSTR wszFilename = ucase(pDocs(i)->DiskFilename)
        wszText = wstr(pDocs(i)->bFunctionsExpanded)
        idx = Listbox_AddString( hList, @wszText )
        ListBox_SetItemData( hList, idx, pDocs(i) )
        pDocs(i)->bHasFunctions = false
        
        if pDocs(i)->bFunctionsExpanded then
            gdb2.dbRewind()
            do 
                pData = gdb2.dbGetNext
                if pData = 0 then exit do
                if pData->deleted then continue do
                if pData->nFileType <> DB2_FILETYPE_USERCODE then continue do
                select case pData->id 
                    case DB2_FUNCTION
                        if wszFilename = ucase(pData->fileName) then
                            wszNodeName = pData->ElementName
                            if len(pData->GetSet) then 
                                wszNodeName = wszNodeName & " " & pData->GetSet
                            end if
                            ub = ubound(arrFuncs) + 1
                            redim preserve arrFuncs(ub)
                            arrFuncs(ub).wszFunctionName = wszNodeName
                            arrFuncs(ub).wszPrototype = pData->CallTip
                            arrFuncs(ub).nLineNumber = pData->nLineStart
                        end if
                end select
            loop      
            
            quickSortFuncs( arrFuncs(), lbound(arrFuncs), ubound(arrFuncs) )

            for ii as long = lbound(arrFuncs) to ubound(arrFuncs)
                wszText = wstr(arrFuncs(ii).nLineNumber) & _
                            "%" & ltrim(arrFuncs(ii).wszFunctionName) & _
                            "%" & trim(arrFuncs(ii).wszPrototype)
                idx = Listbox_AddString( hList, @wszText )
                ListBox_SetItemData( hList, idx, pDocs(i) )
                pDocs(i)->bHasFunctions = true
            next 
            erase arrFuncs  
        end if

    next      

    ' Restore the top index so the list displays like it did before being reset
    SendMessage( hList, LB_SETTOPINDEX, nTopIndex, 0 ) 

    ' Ensure that Listbox is now properly sized and then show 
    ' the listbox now that it is fully populated (only if it contains any
    ' items because zero items can produce white background).
    if ListBox_GetCount( hList ) then ShowWindow( hList, SW_SHOW )
    frmFunctions_PositionWindows()

    AfxRedrawWindow( hList )

    ' Determine if the VScroll bar has changed size or is now hidden/shown
    frmPanel_PositionWindows

    function = 0
end function


' ========================================================================================
' LoadFunctionsOnly
' This will clear the current list of files in the listbox and repopulate it.
' ========================================================================================
function LoadFunctionsOnly() as long
    dim as HWND hList = GetDlgItem(HWND_FRMFUNCTIONS, IDC_FRMFUNCTIONS_LISTBOX)
    
    ' Hide the listbox while it is loading so that we don't get the unpainted
    ' white background from the empty listbox
    ShowWindow( hList, SW_HIDE )
    
    ' Save the topindex because we will restore it after filling the new contents 
    dim as long nTopIndex = SendMessage( hList, LB_GETTOPINDEX, 0, 0 ) 

    ' Clear all content from the listbox
    ListBox_ResetContent(hList)
    
    dim wszText as wstring * MAX_PATH

    dim pData as DB2_DATA ptr
    dim as CWSTR wszNodeName
    dim as long ub, idx
    
    ' 231%FunctionName%prototype  ' function starts at line 231 of the file

    ' Get the functions (and sort them) 
    redim arrFuncs(any) as FUNCTION_NODE_TYPE
    
    gdb2.dbRewind()
    do 
        pData = gdb2.dbGetNext
        if pData = 0 then exit do
        if pData->deleted then continue do
        if pData->nFileType <> DB2_FILETYPE_USERCODE then continue do
        select case pData->id 
            case DB2_FUNCTION
                wszNodeName = pData->ElementName
                if len(pData->GetSet) then
                    wszNodeName = wszNodeName & " " & pData->GetSet
                end if
                ub = ubound(arrFuncs) + 1
                redim preserve arrFuncs(ub)
                arrFuncs(ub).wszFunctionName = wszNodeName
                arrFuncs(ub).wszPrototype = pData->CallTip
                arrFuncs(ub).nLineNumber = pData->nLineStart
        end select
    loop      
            
    quickSortFuncs( arrFuncs(), lbound(arrFuncs), ubound(arrFuncs) )

    for ii as long = lbound(arrFuncs) to ubound(arrFuncs)
        wszText = wstr(arrFuncs(ii).nLineNumber) & _
                "%" & ltrim(arrFuncs(ii).wszFunctionName) & _
                "%" & trim(arrFuncs(ii).wszPrototype)
        idx = Listbox_AddString( hList, @wszText )
        ListBox_SetItemData( hList, idx, 0 )
    next 
    erase arrFuncs  

    ' Restore the top index so the list displays like it did before being reset
    SendMessage( hList, LB_SETTOPINDEX, nTopIndex, 0 ) 

    ' Ensure that Listbox is now properly sized and then show 
    ' the listbox now that it is fully populated (only if it contains any
    ' items because zero items can produce white background).
    if ListBox_GetCount( hList ) then ShowWindow( hList, SW_SHOW )
    frmFunctions_PositionWindows()

    AfxRedrawWindow( hList )

    ' Determine if the VScroll bar has changed size or is now hidden/shown
    frmPanel_PositionWindows

    function = 0
end function

' ========================================================================================
' LoadFunctionsFiles
' This will clear the current list of files in the listbox and repopulate it.
' ========================================================================================
function LoadFunctionsFiles() as long
    ' Call the specific function to load the listbox based on whether we want to
    ' to show Files & Functions, or just Functions only.
    if gFunctionsDisplay = FunctionsDisplayState.ViewAsTree then
        LoadFilesAndFunctions()   
    elseif gFunctionsDisplay = FunctionsDisplayState.ViewAsList then
        LoadFunctionsOnly()   
    end if
    function = 0
end function

' ========================================================================================
' frmFunctions_ViewAsTree / frmFunctions_ViewAsList
' Set the global view state for the list and then reload the list.
' ========================================================================================
function frmFunctions_ViewAsTree() as long
    if gFunctionsDisplay = FunctionsDisplayState.ViewAsTree then exit function
    gFunctionsDisplay = FunctionsDisplayState.ViewAsTree 
    LoadFunctionsFiles()
    function = 0
end function

function frmFunctions_ViewAsList() as long
    if gFunctionsDisplay = FunctionsDisplayState.ViewAsList then exit function
    gFunctionsDisplay = FunctionsDisplayState.ViewAsList
    LoadFunctionsFiles()
    function = 0
end function


