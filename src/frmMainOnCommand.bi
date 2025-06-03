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

enum eFileClose
    EFC_CLOSECURRENT
    EFC_CLOSEALL
    EFC_CLOSEALLFORWARD
    EFC_CLOSEALLOTHERS
    EFC_CLOSEALLBACKWARD 
end enum

declare function OnCommand_FileNew( byval hwnd as HWND ) as clsDocument ptr
declare function OnCommand_FileOpen( byval hwnd as HWND, byval bShowInTab as boolean = true ) as LRESULT
declare function OnCommand_FileSave( byval hwnd as HWND, byval pDoc as clsDocument ptr, _
        byval bSaveAs as boolean = false, byval bSaveAll as boolean = false ) as LRESULT
declare function OnCommand_FileSaveDeclares( byval hwnd as HWND ) as LRESULT
declare function OnCommand_FileSaveAll( byval hwnd as HWND ) as LRESULT
declare function OnCommand_FileClose( byval hwnd as HWND, byval veFileClose as eFileClose, byval nTabNum as long = -1 ) as LRESULT
declare function OnCommand_FileExplorerMessage( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_FileAutoSave( byval hwnd as HWND ) as LRESULT
declare function OnCommand_FileAutoSaveStartTimer() as LRESULT
declare function OnCommand_FileAutoSaveKillTimer() as LRESULT
declare function OnCommand_FileAutoSaveGenerateFilename( byval wszFilename as CWSTR ) as CWSTR
declare function OnCommand_FileAutoSaveFileCheck( byval wszFilename as CWSTR ) as CWSTR
declare function OnCommand_FileLoadSession( byval hwnd as HWND ) as LRESULT
declare function OnCommand_FileSaveSession( byval hwnd as HWND ) as LRESULT
declare function OnCommand_FileCloseSession( byval hwnd as HWND ) as LRESULT

declare function OnCommand_EditRedo( byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditUndo( byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditCut( byval pDoc as clsDocument ptr, byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditCopy( byval pDoc as clsDocument ptr, byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditPaste( byval pDoc as clsDocument ptr, byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditFindDialog() as LRESULT
declare function OnCommand_EditReplaceDialog() as LRESULT
declare function OnCommand_EditFindInFiles( byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditFindActions( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_EditReplaceActions( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_EditIndentBlock( byval pDoc as clsDocument ptr, byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditUnIndentBlock( byval pDoc as clsDocument ptr, byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditSelectAll( byval pDoc as clsDocument ptr, byval hEdit as HWND ) as LRESULT
declare function OnCommand_EditEncoding( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_EditCommon( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT

declare function OnCommand_SearchGotoDefinition( byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_SearchGotoLastPosition() as LRESULT
declare function OnCommand_SearchGotoCompileError( byval bMoveNext as boolean ) as long
declare function OnCommand_SearchGotoFile( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_SearchBookmarks( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT

declare function OnCommand_ViewFunctionList() as LRESULT
declare function OnCommand_ViewBookmarksList() as LRESULT
declare function OnCommand_ViewExplorer() as LRESULT
declare function OnCommand_ViewOutput() as LRESULT
declare function OnCommand_ViewFold( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_ViewZoom( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_ViewToDo() as LRESULT
declare function OnCommand_ViewNotes() as LRESULT
declare function OnCommand_ViewRestoreMain() as LRESULT
declare function OnCommand_ViewExplorerPosition() as LRESULT

declare function OnCommand_ProjectSave( byval HWnd as HWnd, byval bSaveAs as BOOLEAN = False ) as LRESULT
declare function OnCommand_ProjectClose( byval hwnd as HWND ) as LRESULT
declare function OnCommand_ProjectNew( byval hwnd as HWND ) as LRESULT
declare function OnCommand_ProjectOpen( byval hwnd as HWND ) as LRESULT
declare function OnCommand_ProjectFilesAdd( byval hwnd as HWND ) as LRESULT
declare function OnCommand_ProjectSetFileType( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT
declare function OnCommand_ProjectRemove( byval id as long, byval pDoc as clsDocument ptr ) as LRESULT

declare function OnCommand_CompileCommon( byval id as long ) as LRESULT

declare function frmMain_OnCommand( byval hwnd as HWND, _
                                    byval id as Long, _
                                    byval hwndCtl as HWND, _
                                    byval codeNotify as UINT _
                                    ) as LRESULT
