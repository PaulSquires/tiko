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

#Define IDC_FRMOPTIONSEDITOR2_CHKCODETIPS            1000
#Define IDC_FRMOPTIONSEDITOR2_CHKAUTOCOMPLETE        1001
#Define IDC_FRMOPTIONSEDITOR2_CHKAUTOINDENTATION     1002
#Define IDC_FRMOPTIONSEDITOR2_CHKCHARAUTOCOMPLETE    1003
#Define IDC_FRMOPTIONSEDITOR2_CHKFORNEXTVARIABLE     1004
#Define IDC_FRMOPTIONSEDITOR2_CHKBRACEHIGHLIGHT      1005
#Define IDC_FRMOPTIONSEDITOR2_CHKOCCURRENCEHIGHLIGHT 1006

declare function frmOptionsEditor2_Show( byval hWndParent as HWND ) as LRESULT


