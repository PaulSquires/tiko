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


#Define IDC_FRMOPTIONSGENERAL_CHKMULTIPLEINSTANCES  1000
#Define IDC_FRMOPTIONSGENERAL_CHKCOMPILEAUTOSAVE    1001
#Define IDC_FRMOPTIONSGENERAL_CHKCLOSEFUNCLIST      1002
#Define IDC_FRMOPTIONSGENERAL_CHKCLOSEPROJMGR       1003
#Define IDC_FRMOPTIONSGENERAL_CHKASKEXIT            1004
#Define IDC_FRMOPTIONSGENERAL_CHKHIDETOOLBAR        1005
#Define IDC_FRMOPTIONSGENERAL_CHKRESTORESESSION     1006
#Define IDC_FRMOPTIONSGENERAL_CHKCOMPACTMENUS       1007
#Define IDC_FRMOPTIONSGENERAL_CHKAUTOSAVE           1008

declare function frmOptionsGeneral_Show( byval hWndParent as HWND ) as LRESULT
