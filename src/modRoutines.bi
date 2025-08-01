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

#include once "frmListView.bi"


' Size = 32 bytes
TYPE HH_AKLINK 
    cbStruct     as long         ' int       cbStruct;     // sizeof this structure
    fReserved    as boolean      ' BOOL      fReserved;    // must be FALSE (really!)
    pszKeywords  as wstring ptr  ' LPCTSTR   pszKeywords;  // semi-colon separated keywords
    pszUrl       as wstring ptr  ' LPCTSTR   pszUrl;       // URL to jump to if no keywords found (may be NULL)
    pszMsgText   as wstring ptr  ' LPCTSTR   pszMsgText;   // Message text to display in MessageBox if pszUrl is NULL and no keyword match
    pszMsgTitle  as wstring ptr  ' LPCTSTR   pszMsgTitle;  // Message text to display in MessageBox if pszUrl is NULL and no keyword match
    pszWindow    as wstring ptr  ' LPCTSTR   pszWindow;    // Window to display URL in
    fIndexOnFail as boolean      ' BOOL      fIndexOnFail; // Displays index if keyword lookup fails.
END TYPE

#Define HH_DISPLAY_TOPIC   0000 
#Define HH_DISPLAY_TOC     0001
#Define HH_KEYWORD_LOOKUP  0013
#Define HH_HELP_CONTEXT    0015

dim shared as any ptr gpHelpLib

declare function CompleteIncludeFilename( byval pDoc as clsDocument ptr, byval wszFilename as string ) as string
declare function getTextWidth( byval hwnd as HWND, byref wszText as wstring, byval FontIndex as long ) as long
declare function SpawnPreviousInstance() as boolean
declare function ReloadDocument( byref wszFilename as wstring ) as long
declare function ShowContextHelp( byval id as long ) as long
declare function isMouseOverRECT( byval hWin as HWND, byval rc as RECT ) as boolean
declare function isMouseOverWindow( byval hChild as HWND ) as boolean
declare function DisableAllModeless() as long
declare function EnableAllModeless() as long
declare function GetTemporaryFilename( byref wszFolder as wstring, byref wszExtension as wstring) as string
declare function GetFontCharSetID(byref wzCharsetName as CWSTR ) as long
declare function UnicodeToUtf8(byval wzUnicode as CWSTR) as string
declare function Utf8ToAnsi(byref strUtf8 as string) as string
declare function AnsiToUtf8( byref sAnsi as string ) as string
declare function isUTF8encoded(byref s as string) as boolean
declare function ConvertTextBuffer( byval pDoc as clsDocument ptr, byval FileEncoding as long ) as Long
declare function GetFileToString( byref wszFilename as const wstring, byref txtBuffer as string, byval pDoc as clsDocument ptr ) as boolean
declare function IsCurrentLineIncludeFilename() as boolean
declare function OpenSelectedDocument( byref wszFilename as wstring, byref wszFunctionName as wstring = "", byval nLineNumber as long = -1 ) as clsDocument ptr
declare function ProcessToCurdriveProject( byval wzFilename as CWSTR ) as CWSTR
declare function ProcessFromCurdriveProject( byval wzFilename as CWSTR ) as CWSTR
declare function ProcessToCurdriveApp( byval wzFilename as CWSTR ) as CWSTR
declare function ProcessFromCurdriveApp( byval wzFilename as CWSTR ) as CWSTR
declare function AfxIFileOpenDialogW( byval hwndOwner as HWND, byval idButton as long) as wstring Ptr
declare function AfxIFileOpenDialogMultiple( byval hwndOwner as HWND, byval idButton as long) as IShellItemArray ptr
declare function AfxIFileSaveDialog( byval hwndOwner as HWND, byval pwszFileName as wstring Ptr, byval pwszDefExt as wstring Ptr, byval id as long = 0, byval sigdnName as SIGDN = SIGDN_FILESYSPATH ) as wstring Ptr
declare function LV_InsertItem( byval hWndControl as HWND, byval iRow as long, byval iColumn as long, byval pwszText as wstring ptr, byval lParam as LPARAM = 0 ) as boolean
declare function LV_GetItemText( byval hWndControl as HWND, byval iRow as long, byval iColumn as long, byval pwszText as wstring ptr, byval nTextMax as long ) as boolean
declare function LV_SetItemText( byval hWndControl as HWND, byval iRow as long, byval iColumn as long, byval pwszText as wstring ptr, byval nTextMax as long ) as long
declare function LoadLocalizationFile( byref wszFileName as CWSTR, byval IsEnglish as boolean = false ) as boolean
declare function GetProcessImageName( byval pe32w as PROCESSENTRY32W ptr, byval pwszExeName as wstring ptr ) as long
declare function IsProcessRunning( byval pwszExeFileName as wstring ptr ) as boolean
declare function GetRunExecutableFilename() as CWSTR
declare function GetListBoxEmptyClientArea( byval hListBox as HWND ) as RECT
declare function frmListView_SelectItem( byval hLV as HWND, byval nLineNum as long ) as long
declare function frmListView_GetCount( byval hLV as HWND ) as long
declare function frmListView_AddString( byval hLV as HWND, byval wszText as CWSTR ) as long
declare function frmListView_DeleteAllItems( byval hLV as HWND ) as long
declare function frmListView_GetItemText( byval hLV as HWND, byval nLineNum as long, byval nColNum as long ) as CWSTR
declare function frmListView_GetSelection( byval hLV as HWND ) as long
declare function frmListView_AddColumn( _
    byval hLV as HWND, byval nColNum as long, byval wszText as CWSTR, byval nWidth as long ) as long
declare function frmListView_SetForeColors( _
    byval hLV as HWND, byval ForeColor as COLORREF, byval ForeColorHot as COLORREF ) as long
declare function frmListView_SetBackColors( _
    byval hLV as HWND, byval BackColor as COLORREF, byval BackColorHot as COLORREF ) as long
declare function frmListView_SetScrollBarColors( _
    byval hLV as HWND, byval ScrollBarBackColor as COLORREF, byval ScrollBarForeColor as COLORREF, _
    byval ScrollBarDividerColor as COLORREF ) as long
declare function frmListView_GetPointer( byval hLV as HWND ) as LISTVIEW_DATA_TYPE ptr
declare function frmListView_DeleteBlankFirstLine( byval hLV as HWND ) as long
                                            


