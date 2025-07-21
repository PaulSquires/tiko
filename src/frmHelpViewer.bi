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

#include once "Afx/AfxRichEdit.inc"

#define IDC_FRMHELPVIEWER_LEFTPANEL        1000
#define IDC_FRMHELPVIEWER_RIGHTPANEL       1001
#define IDC_FRMHELPVIEWER_VSCROLLBAR       1002

type HELPVIEWER_TYPE
    as POINT ptSplitPrev
    as long  xDeltaSplitter
    as CWSTR Filenames(any)
    as CWSTR Topics(any)
end type

dim shared as HELPVIEWER_TYPE gHelpViewer

declare function frmHelpViewer_Show( byval hWndParent as HWND ) as LRESULT

