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

#include once "frmBuildConfig.bi"
#include once "clsConfig.bi"
#include once "clsTopTabCtl.bi"
#include once "clsDocument.bi"

' Create an array that holds all options in the Build compiler options listbox. The
' description contains a parenthesis enclosed action.
dim shared gBuildOptions(...) as CWSTR => _
    {  _
    "Subsystem to console (-s console)", _
    "Subsystem to GUI (-s gui)", _
    "Compiler 32-bit assembler backend (-gen gas)", _
    "Compiler 64-bit assembler backend (-gen gas64)", _
    "Compiler GCC backend (-gen gcc)", _
    "Compiler LLVM backend (-gen llvm)", _
    "Add error checking (-e)", _
    "Add error checking with RESUME support (-ex)", _
    "Same as -ex with array bounds and null pointer (-exx)", _
    "Enable Assert and AssertWarn code generation (-eassert)", _
    "Add debug information (-g)", _
    "Optimization level 1 for gcc (-Wc -O1)", _
    "Optimization level 2 for gcc (-Wc -O2)", _
    "Optimization level 3 for gcc (-Wc -O3)", _
    "Optimization favor size for gcc (-Wc -Os)", _
    "Optimization favor speed for gcc (-Wc -Ofast)", _
    "Language compatibility FreeBasic (-lang fb)", _
    "Language compatibility FreeBasic Lite (-lang fblite)", _
    "Language compatibility QuickBasic (-lang qb)", _
    "Create DLL and import library (-dll)", _
    "Create static library (-lib)", _
    "Compile only, do not link (-c)", _
    "Do not delete the object files (-C)", _
    "Emit preprocessed output, do not compile (-pp)" _
    }

' ========================================================================================
' Load all of the build descriptions into the listbox
' ========================================================================================
function frmBuildConfig_LoadBuildListBox( byval hParent as HWND ) as Long
    dim hList1 as HWND = GetDlgItem(hParent, IDC_FRMBUILDCONFIG_LIST1)

    ListBox_ResetContent(hList1)
    for i as long = lbound(gConfig.BuildsTemp) to ubound(gConfig.BuildsTemp)
        ListBox_AddString(hList1, gConfig.BuildsTemp(i).wszDescription.sptr)
    NEXT

    function = 0
end function


' ========================================================================================
' Determine the current active build index
' ========================================================================================
function frmBuildConfig_getActiveBuildIndex() as long
    ' determine the default build in case no other build overrides it
    dim as long nDefault
    for i as long = lbound(gConfig.Builds) to ubound(gConfig.Builds)
        if gConfig.Builds(i).IsDefault then
            nDefault = i: exit for
        end if
    next

    ' determine if a project or previous config selection overrides the default
    dim as long idx = -1
    for i as long = lbound(gConfig.Builds) to ubound(gConfig.Builds)
        if gApp.IsProjectActive then
            if gConfig.Builds(i).id = gApp.ProjectBuild then
                idx = i: exit for
            end if
        else
            if gConfig.CompilerBuild = gConfig.Builds(i).id then
                idx = i: exit for
            end if
        end if
    next

    if idx = -1 then idx = nDefault
    function = idx
end function


' ========================================================================================
' Return the string description of the currently selected build configuration
' ========================================================================================
function frmBuildConfig_GetSelectedBuildDescription() as CWSTR
    dim as long nCurSel = frmBuildConfig_getActiveBuildIndex()
    if nCurSel > -1 then
        function = gConfig.Builds(nCurSel).wszDescription
    end if
end function


' ========================================================================================
' Return the string GUID of the currently selected build configuration
' ========================================================================================
function frmBuildConfig_GetSelectedBuildGUID() as string
    dim as long nCurSel = frmBuildConfig_getActiveBuildIndex()
    if nCurSel > -1 then
        function = gConfig.Builds(nCurSel).Id
    end if
end function


' ========================================================================================
' Return the string GUID of the default (if any) build configuration
' ========================================================================================
function frmBuildConfig_GetDefaultBuildGUID() as string
    for i as long = lbound(gConfig.Builds) to ubound(gConfig.Builds)
        if gConfig.Builds(i).IsDefault then 
            return gConfig.Builds(i).Id
        end if   
    next
    function = ""
end function


' ========================================================================================
' Swap two entries in the build Listbox
' ========================================================================================
function frmBuildConfig_SwapListBoxItems( _
            byval Item1 as long, _
            byval Item2 as long _
            ) as long
    dim as hwnd hList1 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_LIST1)
    
    ' Swap the array values
    swap gConfig.BuildsTemp(Item1), gConfig.BuildsTemp(Item2)
    
    ListBox_ReplaceString(hList1, Item1, gConfig.BuildsTemp(Item1).wszDescription)
    ListBox_ReplaceString(hList1, Item2, gConfig.BuildsTemp(Item2).wszDescription)

    function = 0
end function


' ========================================================================================
' Set the build description and compiler options depending on what listbox entry is selected
' ========================================================================================
function frmBuildConfig_SetBuildConfigTextboxes() as long
    dim as HWND hList1 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_LIST1)
    dim as HWND hList2 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_LSTOPTIONS)
    dim as HWND hCheck = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_CHKISDEFAULT)
    dim as HWND hText1 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_TXTDESCRIPTION)
    dim as HWND hText2 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_TXTOPTIONS)
    dim as HWND hOpt32 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_OPT32)
    dim as HWND hOpt64 = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_OPT64)
    dim as HWND hExcl  = GetDlgItem( HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_CHKEXCLUDEPOPUP)
    
    dim as long nCurSel = ListBox_GetCurSel(hList1)
    if nCurSel < 0 then 
        AfxSetWindowText( hText1, "")
        AfxSetWindowText( hText2, "")
        Button_SetCheck( hCheck, 0)
        CheckRadioButton(HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_OPT32, IDC_FRMBUILDCONFIG_OPT64, IDC_FRMBUILDCONFIG_OPT32)
        EnableWindow(hText1, false)
        EnableWindow(hText2, false)
        EnableWindow(hCheck, false)
        EnableWindow(hOpt32, false)
        EnableWindow(hOpt64, false)
        EnableWindow(hList2, false)
        EnableWindow(hExcl,  false)
    else
        AfxSetWindowText( hText1, gConfig.BuildsTemp(nCurSel).wszDescription)
        AfxSetWindowText( hText2, gConfig.BuildsTemp(nCurSel).wszOptions)
        Button_SetCheck( hCheck, gConfig.BuildsTemp(nCurSel).IsDefault)
        Button_SetCheck( hExcl, gConfig.BuildsTemp(nCurSel).ExcludeInPopup)
        if gConfig.BuildsTemp(nCurSel).Is32bit then
            CheckRadioButton(HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_OPT32, IDC_FRMBUILDCONFIG_OPT64, IDC_FRMBUILDCONFIG_OPT32)
        else   
            CheckRadioButton(HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_OPT32, IDC_FRMBUILDCONFIG_OPT64, IDC_FRMBUILDCONFIG_OPT64)
        END IF
        EnableWindow(hText1, true)
        EnableWindow(hText2, true)
        EnableWindow(hCheck, true)
        EnableWindow(hOpt32, true)
        EnableWindow(hOpt64, true)
        EnableWindow(hList2, true)
        EnableWindow(hExcl,  true)
    end if

    ' Set the checkmarks in the OptionList Listbox by redrawing the Listbox
    AfxRedrawWindow(hList2)
        
    function = 0
end function
                

' ========================================================================================
' Process WM_MEASUREITEM message for window/dialog: frmBuildConfig
' ========================================================================================
function frmBuildConfig_OnMeasureItem( _
            byval hwnd as HWND, _
            byval lpmis as MEASUREITEMSTRUCT ptr _
            ) as long
    ' Set the height of the List box items. 
    dim pWindow as CWindow ptr = AfxCWindowPtr(hwnd)
    if pWindow then 
        lpmis->itemHeight = pWindow->ScaleY(FRMBUILDCONFIG_LISTBOX_LINEHEIGHT)
    end if
    function = 0
end function


' ========================================================================================
' Process WM_DRAWITEM message for window/dialog: frmBuildConfig
' ========================================================================================
function frmBuildConfig_OnDrawItem( _
            byval hwnd as HWND, _
            byval lpdis as const DRAWITEMSTRUCT ptr _
            ) as long

    dim memDC as HDC                 ' Double buffering
    dim hbit  as HBITMAP             ' Double buffering
    
    dim as HBRUSH hBrush 
    dim as HICON hCheckBox
    dim as RECT rc, rc2
    dim as long nWidth, nHeight
    dim as CWSTR wszText, wszOptions, wszAction
    
    dim pWindow as CWindow ptr = AfxCWindowPtr(hwnd)
    if pWindow = 0 then exit function
        
    if lpdis->itemID = -1 then exit function
    
    select case lpdis->itemAction
        case ODA_DRAWENTIRE, ODA_SELECT
            if lpdis->CtlID = IDC_FRMBUILDCONFIG_LIST1 then
                wszText = gConfig.BuildsTemp(lpdis->itemID).wszDescription
                hCheckBox = 0
            elseif lpdis->CtlID = IDC_FRMBUILDCONFIG_LSTOPTIONS then
                wszText = gBuildOptions(lpdis->itemID)
                ' Get the selected item in the Builds listbox and then look at the OptionList for
                ' that build for each of the individual OptionList build options.
                dim as long nSelBuild = ListBox_GetCurSel(GetDlgItem(hwnd, IDC_FRMBUILDCONFIG_LIST1))
                if nSelBuild > -1 then 
                    wszOptions = " " & gConfig.BuildsTemp(nSelBuild).wszOptions & " "
                    wszAction  = " " & AfxStrExtract(gBuildOptions(lpdis->itemID), "(", ")") & " "
                    hCheckBox = iif( instr(wszOptions, wszAction), ghIconTick, ghIconNoTick)
                end if
            end if
            
            nWidth  = lpdis->rcItem.right-lpdis->rcItem.left
            nHeight = lpdis->rcItem.bottom-lpdis->rcItem.top 
            
            memDC = CreateCompatibleDC( lpdis->hDC )

            SaveDC(memDC)
                                            
            hbit  = CreateCompatibleBitmap( lpdis->hDC, nWidth, nHeight )
            if hbit then SelectObject( memDC, hbit )

            ' Create our rect that works with the entire line
            SetRect(@rc, 0, 0, nWidth, nHeight)
            FillRect(memDC, @rc, GetSysColorBrush(COLOR_WINDOW))  
            
            ' Draw the tick/untick image
            ' The line height is FRMBUILDCONFIG_LISTBOX_LINEHEIGHT so center the 16x16 icon vertically and horizontally
            rc2 = rc
            if hCheckBox then
                DrawIconEx( memDC, _
                            rc.Left + pWindow->ScaleX(2), _
                            rc.Top + pWindow->ScaleY(2), _
                            hCheckBox, _
                            pWindow->ScaleX(16), pWindow->ScaleY(16), 0, 0, DI_NORMAL) 
                rc2.Left = pWindow->ScaleX(20)
            end if
            
            ' DETERMINE TEXT BACKGROUND
            if (lpdis->itemState and ODS_SELECTED) then     
                SetBkColor(memDC, GetSysColor(COLOR_HIGHLIGHT))   
                SetTextColor(memDC, GetSysColor(COLOR_HIGHLIGHTTEXT))
                hBrush = GetSysColorBrush(COLOR_HIGHLIGHT) 
            else
                SetBkColor(memDC, GetSysColor(COLOR_WINDOW))   
                SetTextColor(memDC, GetSysColor(COLOR_WINDOWTEXT))
                hBrush = GetSysColorBrush(COLOR_WINDOW) 
            end if
                    
            ' Output the text
            SelectObject(memDC, AfxGetWindowFont(lpdis->hwndItem))
            SelectObject(memDC, hBrush)      
            FillRect(memDC, @rc2, hBrush)  

            rc2.Left = rc2.Left + pWindow->ScaleX(4)
            DrawText( memDC, wszText, _
                    -1, cast(lpRect, @rc2), _
                    DT_LEFT or DT_SINGLELINE or DT_VCENTER )

            ' Draw the border edges
            SetBkMode(memDC, TRANSPARENT)   
            DrawEdge( memDC, @rc, EDGE_SUNKEN, BF_BOTTOMRIGHT)

            ' Copy the entire memory bitmap over to the visual display
            BitBlt lpdis->hDC, lpdis->rcItem.left, lpdis->rcItem.top, nWidth, nHeight, memDC, 0, 0, SRCCOPY 

            ' Cleanup
            RestoreDC(memDC, -1)
            
            if hbit  then DeleteObject(hbit)
            if memDC then DeleteDC(memDC)

            return true
    
    end select

    function = 0
end function


' ========================================================================================
' Processes messages for the subclassed ListBox window.
' ========================================================================================
function frmBuildConfig_ProcessListboxClick( _
            byval hwnd as HWND, _
            byval nCurSel as long _
            ) as long
    if nCurSel = -1 then exit function
    
    ' Get the action text for this listbox item. If it exists in the Options
    ' textbox then remove it
    dim as CWSTR wszText = AfxGetWindowText( GetDlgItem(HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_TXTOPTIONS)) & " "
    dim as CWSTR wszAction = AfxStrExtract(gBuildOptions(nCurSel), "(", ")") & " "
    ' If the action exists, remove it. If it does not exist then add it.
    if instr(wszText, wszAction) then
        wszText = trim(AfxStrRemove(wszText, wszAction))
    else
        wszText = trim(wszText) & " " & trim(wszAction)
    end if   
    AfxSetWindowText( GetDlgItem(HWND_FRMBUILDCONFIG, IDC_FRMBUILDCONFIG_TXTOPTIONS), wszText)

    function = 0

end function


' ========================================================================================
' Processes messages for the subclassed ListBox window.
' ========================================================================================
function frmBuildConfig_ListBox_SubclassProc ( _
            byval hwnd   as HWND, _                 ' // Control window handle
            byval uMsg   as UINT, _                 ' // Type of message
            byval wParam as WPARAM, _               ' // First message parameter
            byval lParam as LPARAM, _               ' // Second message parameter
            byval uIdSubclass as UINT_PTR, _        ' // The subclass ID
            byval dwRefData as DWORD_PTR _          ' // Pointer to reference data
            ) as LRESULT

    
    select case uMsg

        case WM_ERASEBKGND
            ' Only erase the bottom portion of the listbox that extends from the last item
            ' to the bottom edge of the listbox. All other lines are already drawn. This helps
            ' reduce screen flicker.
            dim as RECT rc = GetListBoxEmptyClientArea( HWND, FRMBUILDCONFIG_LISTBOX_LINEHEIGHT )
            if rc.top < rc.bottom then
                dim as HDC hDC = cast(HDC, wParam)
                FillRect(hDC, @rc, GetSysColorBrush(COLOR_WINDOW))
            end if
            return true
            
        case WM_GETDLGCODE
            ' All keyboard input
            function = DLGC_WANTALLKEYS
            exit function

        case WM_KEYUP
            select case loword(wParam)
            case VK_SPACE
                dim as long nCurSel = ListBox_GetCurSel(hwnd)
                frmBuildConfig_ProcessListboxClick(hwnd, nCurSel)
                exit function
            case VK_ESCAPE
                PostMessage( GetParent(hwnd), WM_CLOSE, 0, 0 )
                exit function
            end select

        case WM_MOUSEMOVE
        case WM_LBUTTONDOWN
            
        case WM_LBUTTONUP
            ' Handle if the checkbox is clicked
            dim as long nCurSel = ListBox_GetCurSel(hwnd)
            if nCurSel = -1 then exit function
            dim pWindow as CWindow ptr = AfxCWindowPtr(GetParent(hwnd))
            if pWindow = 0 then exit function
            dim as RECT rc: SendMessage(hwnd, LB_GETITEMRECT, nCurSel, cast(LPARAM, @rc))
            ' The checkbox is the first 20x20 area (16x16 icon)
            rc.Left   = rc.Left + pWindow->ScaleX(2)
            rc.Top    = rc.Top  + pWindow->ScaleY(2)
            rc.Right  = rc.Left + pWindow->ScaleX(16)
            rc.Bottom = rc.Top  + pWindow->ScaleY(16)
            dim as point pt = (loword(lParam), hiword(lParam))
            if PtInRect(@rc, pt) then
                frmBuildConfig_ProcessListboxClick(hwnd, nCurSel)
                InvalidateRect(hwnd, @rc, true): UpdateWindow(hwnd)
            END IF
            
        case WM_DESTROY
            ' REQUIRED: Remove control subclassing
            RemoveWindowSubclass hwnd, @frmBuildConfig_ListBox_SubclassProc, uIdSubclass

    End Select

    ' Default processing of Windows messages
    Function = DefSubclassProc(hwnd, uMsg, wParam, lParam)

End Function


' ========================================================================================
' Process WM_CREATE message for window/dialog: frmBuildConfig
' ========================================================================================
function frmBuildConfig_OnCreate( _
            byval hwnd as HWND, _
            byval lpCreateStructPtr as LPCREATESTRUCT _
            ) as boolean

    ' This is a modal popup window so disable the parent window
    DisableAllModeless()

    '  Message cracker macro expects a True to be returned for a successful
    '  OnCreate handler even though returning -1 from a standard WM_CREATE
    '  call would stop creating the window. This is just one of those Windows
    '  inconsistencies.
    return true
end function


' ========================================================================================
' Process WM_COMMAND message for window/dialog: frmBuildConfig
' ========================================================================================
function frmBuildConfig_OnCommand( _
            byval hwnd as HWND, _
            byval id as Long, _
            byval hwndCtl as HWND, _
            byval codeNotify as UINT _
            ) as LRESULT

    dim as HWND hList1 = GetDlgItem( hwnd, IDC_FRMBUILDCONFIG_LIST1)
    dim as long nCurSel = ListBox_GetCurSel(hList1)

    ' Convert a ListBox DoubleClick into pressing OK button action
    if (id = IDC_FRMBUILDCONFIG_LIST1) andalso (codeNotify = LBN_DBLCLK) then
        id = IDOK: codeNotify = BN_CLICKED
    end if
    
    select case id
        case IDC_FRMBUILDCONFIG_LIST1
            if codeNotify = LBN_SELCHANGE then
                frmBuildConfig_SetBuildConfigTextboxes()
            end if
            
        case IDC_FRMBUILDCONFIG_TXTDESCRIPTION
            if codeNotify = EN_CHANGE then
                ' Update the temp array and the Listbox
                if nCurSel > -1 then
                    gConfig.BuildsTemp(nCurSel).wszDescription = AfxGetWindowText(hwndCtl)
                    ListBox_ReplaceString(hList1, nCurSel, gConfig.BuildsTemp(nCurSel).wszDescription)
                end if
            end if
            
        case IDC_FRMBUILDCONFIG_TXTOPTIONS
            if codeNotify = EN_CHANGE then
                ' Update the temp array 
                if nCurSel > -1 then
                    gConfig.BuildsTemp(nCurSel).wszOptions = AfxGetWindowText(hwndCtl)
                    ' Refresh the Options listbox so any manually entered options will
                    ' now be checked in the listbox.
                    AfxRedrawWindow(GetDlgItem(hwnd, IDC_FRMBUILDCONFIG_LSTOPTIONS))
                end if
            end if
            
        case IDC_FRMBUILDCONFIG_OPT32
            if codeNotify = BN_CLICKED then
                ' Update the temp array 
                if nCurSel > -1 then
                    if Button_GetCheck(hwndCtl) then
                        gConfig.BuildsTemp(nCurSel).Is32bit = 1
                        gConfig.BuildsTemp(nCurSel).Is64bit = 0
                    else   
                        gConfig.BuildsTemp(nCurSel).Is32bit = 0
                        gConfig.BuildsTemp(nCurSel).Is64bit = 1
                    end if
                end if
            end if

        case IDC_FRMBUILDCONFIG_OPT64
            if codeNotify = BN_CLICKED then
                ' Update the temp array 
                if nCurSel > -1 then
                    if Button_GetCheck(hwndCtl) then
                        gConfig.BuildsTemp(nCurSel).Is32bit = 0
                        gConfig.BuildsTemp(nCurSel).Is64bit = 1
                    else   
                        gConfig.BuildsTemp(nCurSel).Is32bit = 1
                        gConfig.BuildsTemp(nCurSel).Is64bit = 0
                    end if
                end if
            end if

        case IDC_FRMBUILDCONFIG_CHKISDEFAULT
            if codeNotify = BN_CLICKED then
                ' Update the temp array 
                if nCurSel > -1 then
                    gConfig.BuildsTemp(nCurSel).IsDefault = Button_GetCheck(hwndCtl)
                    ' Can only have 1 entry as the default so ensure all others are reset
                    if Button_GetCheck(hwndCtl) then
                        for i as long = lbound(gConfig.BuildsTemp) to ubound(gConfig.BuildsTemp)
                            if i <> nCurSel then gConfig.BuildsTemp(i).IsDefault = 0
                        next
                    end if
                end if
            end if

        case IDC_FRMBUILDCONFIG_CHKEXCLUDEPOPUP
            if codeNotify = BN_CLICKED then
                ' Update the temp array 
                if nCurSel > -1 then
                    gConfig.BuildsTemp(nCurSel).ExcludeInPopup = Button_GetCheck(hwndCtl)
                end if
            end if

        case IDC_FRMBUILDCONFIG_CMDUP
            if codeNotify = BN_CLICKED then
                if nCurSel > 0 then
                    frmBuildConfig_SwapListboxItems(nCurSel, nCurSel-1)
                end if
            end if

        case IDC_FRMBUILDCONFIG_CMDDOWN
            if codeNotify = BN_CLICKED then
                if nCurSel < ListBox_GetCount(hList1)-1 then
                    frmBuildConfig_SwapListboxItems(nCurSel, nCurSel+1)
                end if
            end if

        case IDC_FRMBUILDCONFIG_CMDINSERT
            if codeNotify = BN_CLICKED then
                if ubound(gConfig.BuildsTemp) = -1 then
                    redim gConfig.BuildsTemp(0)
                    nCurSel = 0
                    redim preserve gConfig.BuildsTemp(ubound(gConfig.BuildsTemp)+1)
                else
                    if nCurSel = -1 then nCurSel = 0
                    ' insert the item above current entry in the internal array
                    for i as long = ubound(gConfig.BuildsTemp) to nCurSel + 1 step -1
                        gConfig.BuildsTemp(i) = gConfig.BuildsTemp(i-1)
                    next
                end if
                gConfig.BuildsTemp(nCurSel).Id = AfxGuidText(AfxGuid())
                gConfig.BuildsTemp(nCurSel).wszDescription = ""
                gConfig.BuildsTemp(nCurSel).wszOptions = ""
                gConfig.BuildsTemp(nCurSel).IsDefault = 0
                gConfig.BuildsTemp(nCurSel).Is32bit = 1
                gConfig.BuildsTemp(nCurSel).Is64bit = 0
                gConfig.BuildsTemp(nCurSel).ExcludeInPopup = 0
                ' reload the listbox
                frmBuildConfig_LoadBuildListBox(hwnd)
                nCurSel = Min(nCurSel, ubound(gConfig.BuildsTemp))
                ListBox_SetCurSel(hList1, nCurSel)
                frmBuildConfig_SetBuildConfigTextboxes()
                SetFocus hList1
            end if

        case IDC_FRMBUILDCONFIG_CMDDELETE
            if codeNotify = BN_CLICKED then
                if nCurSel > -1  then
                    if MessageBox( HWND, L(287, "Are you sure you want to delete this build configuration?"), L(276,"Confirm"), _
                                        MB_YESNOCANCEL or MB_ICONINFORMATION or MB_DEFBUTTON1 ) = IDYES then
                        if ubound(gConfig.BuildsTemp) = 0 then
                            erase gConfig.BuildsTemp
                            nCurSel = -1
                        else
                            ' remove the item from the internal array
                            for i as long = nCurSel to ubound(gConfig.BuildsTemp) - 1
                                gConfig.BuildsTemp(i) = gConfig.BuildsTemp(i+1)
                            next
                            redim preserve gConfig.BuildsTemp(ubound(gConfig.BuildsTemp)-1)
                        end if
                        ' reload the listbox
                        frmBuildConfig_LoadBuildListBox(hwnd)
                        nCurSel = Min(nCurSel, ubound(gConfig.BuildsTemp))
                        ListBox_SetCurSel(hList1, nCurSel)
                        frmBuildConfig_SetBuildConfigTextboxes()
                        SetFocus hList1
                    end if
                end if
            end if

        case IDOK
            If codeNotify = BN_CLICKED then
                ' Copy the temporary items to the main array  
                redim gConfig.Builds(ubound(gConfig.BuildsTemp))
                for i as long = lbound(gConfig.BuildsTemp) to ubound(gConfig.BuildsTemp)
                    gConfig.Builds(i) = gConfig.BuildsTemp(i)   
                next
                erase gConfig.BuildsTemp
                
                ' Set the active project or the active document to the selected build
                if nCurSel > -1 then 
                    If gApp.IsProjectActive then
                        gApp.ProjectBuild = gConfig.Builds(nCurSel).Id
                    else
                        dim pDocMain as clsDocument Ptr 
                        pDocMain = gTTabCtl.GetActiveDocumentPtr()
                        if pDocMain then pDocMain->DocumentBuild = gConfig.Builds(nCurSel).Id
                        gConfig.CompilerBuild = gConfig.Builds(nCurSel).Id
                    end if
                    frmMain_SetStatusbar
                end if
                
                gConfig.SaveConfigFile
                SendMessage( hwnd, WM_CLOSE, 0, 0 )
                exit function
            end if
            
        case IDCANCEL
            If codeNotify = BN_CLICKED then
                SendMessage( hwnd, WM_CLOSE, 0, 0 )
                exit function
            end if
    end select

    function = 0
end function


' ========================================================================================
' Process WM_CLOSE message for window/dialog: frmBuildConfig
' ========================================================================================
function frmBuildConfig_OnClose( byval hwnd as HWND ) as LRESULT
    ' Enables parent window keeping parent's zorder
    EnableAllModeless()
    DestroyWindow( hwnd )
    function = 0
end function


' ========================================================================================
' Process WM_DESTROY message for window/dialog: frmBuildConfig
' ========================================================================================
function frmBuildConfig_OnDestroy( byval hwnd as HWND) as LRESULT
    HWND_FRMBUILDCONFIG = 0
    PostQuitMessage(0)
    function = 0
end function


' ========================================================================================
' frmBuildConfig Window procedure
' ========================================================================================
function frmBuildConfig_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    select case uMsg
        HANDLE_MSG (hwnd, WM_CREATE,      frmBuildConfig_OnCreate)
        HANDLE_MSG (hwnd, WM_CLOSE,       frmBuildConfig_OnClose)
        HANDLE_MSG (hwnd, WM_DESTROY,     frmBuildConfig_OnDestroy)
        HANDLE_MSG (hwnd, WM_COMMAND,     frmBuildConfig_OnCommand)
        HANDLE_MSG (hwnd, WM_MEASUREITEM, frmBuildConfig_OnMeasureItem)
        HANDLE_MSG (hwnd, WM_DRAWITEM,    frmBuildConfig_OnDrawItem)
    end select

    ' for messages that we don't deal with
    function = DefWindowProc(hwnd, uMsg, wParam, lParam)

end function


' ========================================================================================
' frmBuildConfig_Show
' ========================================================================================
function frmBuildConfig_Show( byval hWndParent as HWND ) as LRESULT
    '  Create the main window and child controls
    dim pWindow as CWindow ptr = new CWindow

    dim as HFONT hFontSymbolLarge = pWindow->CreateFont(SYMBOLFONT, 12, FW_NORMAL)

    dim as HWnd hForm = _
        pWindow->Create(hWndParent, L(277,"Build Configurations"), _
            @frmBuildConfig_WndProc, 0, 0, 0, 0, _
            WS_POPUP or WS_CAPTION or WS_SYSMENU or WS_CLIPSIBLINGS or WS_CLIPCHILDREN, _
            WS_EX_DLGMODALFRAME or WS_EX_CONTROLPARENT or WS_EX_LEFT )
    pWindow->SetClientSize(622, 436)
    pWindow->Center(pWindow->hWindow, hWndParent)

    pWindow->AddControl("LISTBOX", , IDC_FRMBUILDCONFIG_LIST1, "", 10, 10, 218, 362, _
        WS_CHILD or WS_VISIBLE or WS_VSCROLL or WS_TABSTOP or LBS_NOTIFY or _
        LBS_NOINTEGRALHEIGHT or LBS_OWNERDRAWFIXED or LBS_HASSTRINGS, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR, , _
        cast(SUBCLASSPROC, @frmBuildConfig_ListBox_SubclassProc), IDC_FRMBUILDCONFIG_LIST1, cast(DWORD_PTR, @pWindow))

    pWindow->AddControl("LABEL", , IDC_FRMBUILDCONFIG_LABEL1, L(278,"Description") & ":", 240, 11, 91, 20, _
        WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or SS_LEFT or SS_NOTIFY, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMBUILDCONFIG_CHKISDEFAULT, L(280,"Set as default"), 380, 10, 240, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("TEXTBOX", , IDC_FRMBUILDCONFIG_TXTDESCRIPTION, "", 240, 32, 372, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or ES_LEFT or ES_AUTOHSCROLL, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->AddControl("RADIOBUTTON", , IDC_FRMBUILDCONFIG_OPT32, "FBC 32-bit", 240, 54, 100, 20, _
        WS_VISIBLE or WS_TABSTOP or BS_AUTORADIOBUTTON or BS_LEFT or BS_VCENTER or WS_GROUP, _
        WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->AddControl("RADIOBUTTON", , IDC_FRMBUILDCONFIG_OPT64, "FBC 64-bit", 342, 54, 100, 20, _
        WS_VISIBLE or WS_TABSTOP or BS_AUTORADIOBUTTON or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)

    pWindow->AddControl("LABEL", , IDC_FRMBUILDCONFIG_LABEL2, L(279,"Compiler Options") & ":", 240, 82, 136, 18, _
        WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or SS_LEFT or SS_NOTIFY, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("TEXTBOX", , IDC_FRMBUILDCONFIG_TXTOPTIONS, "", 240, 103, 372, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or ES_LEFT or ES_AUTOHSCROLL, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->AddControl("LISTBOX", , IDC_FRMBUILDCONFIG_LSTOPTIONS, "", 240, 129, 372, 223, _
        WS_CHILD or WS_VISIBLE or WS_VSCROLL or WS_TABSTOP or LBS_NOTIFY or _
        LBS_NOINTEGRALHEIGHT or LBS_OWNERDRAWFIXED or LBS_HASSTRINGS, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR, , _
        cast(SUBCLASSPROC, @frmBuildConfig_ListBox_SubclassProc), IDC_FRMBUILDCONFIG_LSTOPTIONS, cast(DWORD_PTR, @pWindow))
    pWindow->AddControl("CHECKBOX", , IDC_FRMBUILDCONFIG_CHKEXCLUDEPOPUP, _
        L(284,"Exclude build from status bar popup menu"), 240, 355, 372, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)


    pWindow->AddControl("BUTTON", , IDC_FRMBUILDCONFIG_CMDINSERT, L(281, "Insert"), 8, 388, 74, 28, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("BUTTON", , IDC_FRMBUILDCONFIG_CMDDELETE, L(282, "Delete"), 87, 388, 74, 28, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    
    dim as HWND hCtrl = _
    pWindow->AddControl("BUTTON", , IDC_FRMBUILDCONFIG_CMDUP, wszIconChevronUp, 166, 388, 28, 28, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    AfxSetWindowFont( hCtrl, hFontSymbolLarge, false )     

    hCtrl = _
    pWindow->AddControl("BUTTON", , IDC_FRMBUILDCONFIG_CMDDOWN, wszIconChevronDown, 199, 388, 28, 28, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    AfxSetWindowFont( hCtrl, hFontSymbolLarge, false )     

    pWindow->AddControl("BUTTON", , IDOK, L(0,"OK"), 454, 388, 74, 28, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("BUTTON", , IDCANCEL, L(1,"Cancel"), 536, 388, 74, 28, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)

    HWND_FRMBUILDCONFIG = hForm
    
    ' Copy all of the Builds to the BuildsTemp array because we will work with 
    ' temporary copies until the user hits OK.
    redim gConfig.BuildsTemp(ubound(gConfig.Builds))
    for i as long = lbound(gConfig.Builds) to ubound(gConfig.Builds)
        gConfig.BuildsTemp(i) = gConfig.Builds(i)   
    next
    frmBuildConfig_LoadBuildListBox(hForm)
    
    ' Load the Compiler Options Listbox
    hCtrl = GetDlgItem(hForm, IDC_FRMBUILDCONFIG_LSTOPTIONS)
    for i as long = lbound(gBuildOptions) to ubound(gBuildOptions)
        ListBox_AddString(hCtrl, gBuildOptions(i).sptr)
    next

    
    ' Set the current build selection 
    dim as long nCurSel = frmBuildConfig_getActiveBuildIndex()
    dim hList as HWND = GetDlgItem(hForm, IDC_FRMBUILDCONFIG_LIST1)
    if nCurSel = -1 then nCurSel = 0 
    ListBox_SetCurSel(hList, nCurSel)
    frmBuildConfig_SetBuildConfigTextboxes()
    
    SetFocus GetDlgItem(hForm, IDC_FRMBUILDCONFIG_LIST1)
    
    ' Process Windows messages(modal)
    function = pWindow->DoEvents(SW_SHOW)
    
    ' Delete the frmBuildConfig CWindow class manually allocated memory 
    if pWindow then delete(pWindow)
    if hFontSymbolLarge then DeleteObject(hFontSymbolLarge)
    
end function

