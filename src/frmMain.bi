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

#Define IDC_FRMMAIN_TOPTABCONTROL                   1000
#Define IDC_FRMMAIN_COMPILETIMER                    1001


'' Last position in document. Used when "Last Position" menu option is selected.
type LASTPOSITION_TYPE
    pDoc       as clsDocument_ Ptr
    nFirstLine as long     ' first visible line on screen
    nPosition  as long     ' Position in Scintilla document where caret is positioned
end type

dim shared gLastPosition as LASTPOSITION_TYPE


declare function frmMain_OpenFileSafely( byval hwnd as HWND, byval bIsNewFile as boolean, byval bIsTemplate as boolean, _
        byval bShowInTab as BOOLEAN, byval bIsInclude as BOOLEAN, Byref wszName as WString, byval pDocIn as clsDocument Ptr, _
        byval wszFileType as CWSTR = FILETYPE_UNDEFINED ) as clsDocument ptr
declare function frmMain_OpenProjectSafely( byval HWnd as HWnd, byref wszProjectFileName as const WString ) as Boolean
declare function frmMain_CalcSplitRect( byval pDoc as clsDocument ptr ) as long
declare function frmMain_GotoFile( byval pDoc as clsDocument ptr, byval nMenuId as long ) as long
declare function frmMain_GotoLastPosition() as long
declare function frmMain_GotoDefinition( byval pDoc as clsDocument Ptr ) as long
declare function frmMain_SetStatusbar() as long
declare function frmMain_SetFocusToCurrentCodeWindow() as long
declare function frmMain_PositionWindows() as LRESULT
declare function frmMain_HighlightWord( byval pDoc as clsDocument ptr, byref text as string ) as long
declare function frmMain_Show( byval hWndParent as HWND ) as LRESULT
