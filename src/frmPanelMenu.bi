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

#pragma once

type PANEL_MENU_TYPE
    wszCaption      as DWSTRING
    wszTooltip      as DWSTRING
    id              as long
    rc              as RECT   
    isPrevHot       as boolean
end type

' Values for each panel menu button are set in frmPanelMenu_PositionWindows
dim shared gPanelMenu(0 to 8) as PANEL_MENU_TYPE

declare function frmPanelMenu_FormatTooltip( byval id as integer ) as DWSTRING
declare function frmPanelMenu_PositionWindows() as LRESULT
declare function frmPanelMenu_Show( byval hWndParent as HWnd ) as LRESULT

