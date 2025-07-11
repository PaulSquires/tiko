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

#pragma once

#Define IDC_FRMFINDREPLACE_TXTFIND                  1000
#Define IDC_FRMFINDREPLACE_TXTREPLACE               1001

declare function frmFindReplace_HighlightSearches() as long
declare function frmFindReplace_PositionWindows() as LRESULT
declare function frmFindReplace_Show( byval hWndParent as HWND, byval fShowReplace as boolean ) as LRESULT
declare function frmFindReplace_PositionMainWindow() as LRESULT

