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

#include once "frmOptionsGeneral.bi"
#include once "clsConfig.bi"


' ========================================================================================
' frmOptionsGeneral Window procedure
' ========================================================================================
function frmOptionsGeneral_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    ' for messages that we don't deal with
    function = DefWindowProc(hwnd, uMsg, wParam, lParam)

end function


' ========================================================================================
' frmOptionsGeneral_Show
' ========================================================================================
function frmOptionsGeneral_Show( byval hwndParent as HWND ) as LRESULT

    '  Create the main window and child controls
    dim pWindow as CWindow ptr = new CWindow

    HWND_FRMOPTIONSGENERAL = pWindow->Create( hwndParent, "", @frmOptionsGeneral_WndProc, 0, 0, 0, 0, _
        WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN, _
        WS_EX_CONTROLPARENT or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    ' Height and width of this child form is set in frmOptions_OnNotify when the treeview option is selected.
    
    pWindow->AddControl("CHECKBOX", , IDC_FRMOPTIONSGENERAL_CHKMULTIPLEINSTANCES, L(119,"Allow multiple instances"), _
        0, 0, 400, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMOPTIONSGENERAL_CHKCOMPILEAUTOSAVE, L(121,"Autosave files before compiling"), _
        0, 21, 400, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMOPTIONSGENERAL_CHKASKEXIT, L(274,"Ask before exiting the editor"), _
        0, 42, 400, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMOPTIONSGENERAL_CHKRESTORESESSION, L(423,"Restore previous session/project files on startup"), _
        0, 63, 400, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMOPTIONSGENERAL_CHKCOMPACTMENUS, L(133,"Use Compact Menu Interface"), _
        0, 84, 400, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMOPTIONSGENERAL_CHKUPDATES, L(91,"Check for Updates"), _
        0, 105, 400, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)

    dim as long idx = 0
    dim as hwnd HWND = HWND_FRMOPTIONSGENERAL
    
    Button_SetCheck( GetDlgItem( hwnd, IDC_FRMOPTIONSGENERAL_CHKMULTIPLEINSTANCES),  gConfig.MultipleInstances)
    Button_SetCheck( GetDlgItem( hwnd, IDC_FRMOPTIONSGENERAL_CHKCOMPILEAUTOSAVE),    gConfig.CompileAutoSave)
    Button_SetCheck( GetDlgItem( hwnd, IDC_FRMOPTIONSGENERAL_CHKASKEXIT),            gConfig.AskExit)
    Button_SetCheck( GetDlgItem( hwnd, IDC_FRMOPTIONSGENERAL_CHKRESTORESESSION),     gConfig.RestoreSession)
    Button_SetCheck( GetDlgItem( hwnd, IDC_FRMOPTIONSGENERAL_CHKCOMPACTMENUS),       gConfig.CompactMenus)
    Button_SetCheck( GetDlgItem( hwnd, IDC_FRMOPTIONSGENERAL_CHKUPDATES),            gConfig.CheckUpdates)

    function = 0
    
end function





