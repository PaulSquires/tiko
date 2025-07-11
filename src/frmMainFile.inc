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

#include once "frmMain.bi"
#include once "clsDocument.bi"

' ========================================================================================
' Create a new editing window
' ========================================================================================
function OnCommand_FileNew( byval hwnd as HWND ) as clsDocument ptr
    dim pDoc as clsDocument ptr
    
    ' Create the new pDoc object and assign blank text buffer to it which will
    ' automatically create the scintilla windows.
    pDoc = gApp.CreateEmptyDocument( true )
    pDoc->AssignTextBuffer()

    ' Load Explorer names first SetFocusTab will highlight it.
    LoadExplorerFiles()
    LoadFunctionsFiles()

    ' Add the new document to the top tabcontrol
    dim as long iTab = gTTabCtl.AddTab( pDoc )  
    gTTabCtl.SetFocusTab(iTab)
    frmMain_PositionWindows
    frmMain_SetFocusToCurrentCodeWindow
    
    function = pDoc
end function


' ========================================================================================
' Open one or more files for editing
' ========================================================================================
function OnCommand_FileOpen( _
            byval hwnd as HWND, _
            byval bShowInTab as boolean = true, _
            byval bIsTemplate as boolean = false _
            ) as LRESULT

    ' This function is called from these top menu items:
    ' File / Open File
    ' Project / Add Files to Project
    
    ' Display the Open File Dialog
    dim pItems as IShellItemArray ptr = AfxIFileOpenDialogMultiple(hwnd, IDM_FILEOPEN)
    if pItems = null then exit function
    dim dwItemCount as long, i as long, pItem as IShellItem ptr, pwszName as wstring ptr
    pItems->lpVtbl->GetCount(pItems, @dwItemCount)
    
    ' Variable length array to hold all filenames to open. 
    dim AllFilenames(dwItemCount - 1) as CWSTR
    
    ' Variable length array to hold sequence of TabCtrl tabs to open. We save the sequence
    ' here and open them only after all over documents have been loaded. This will look
    ' visually more appealing for those files that will display in the top Tab Control.
    dim pDocTabs(dwItemCount - 1) as clsDocument ptr

    SetCursor( LoadCursor(0, IDC_WAIT) )
    dim pDoc as clsDocument ptr
    pDoc = gTTabCtl.GetActiveDocumentPtr()
    if pDoc then SciExec( pDoc->hWindow(0), SCI_SETCURSOR, SC_CURSORWAIT, 0 )

    ' Prevent the constant updating of the app caption bar with filename
    gApp.IsFileLoading = true  
    gApp.FileLoadingCount = 0
    
    for i = 0 To dwItemCount - 1
        pItems->lpVtbl->GetItemAt(pItems, i, @pItem)
        if pItem then
            pItem->lpVtbl->GetDisplayName(pItem, SIGDN_FILESYSPATH, @pwszName)
            if pwszName then 
                AllFilenames(i) = *pwszName
                CoTaskMemFree(pwszName)
                pwszName = null
            end if
            pItem->lpVtbl->Release(pItem)
            pItem = null
        end if
    next
    pItems->lpVtbl->Release(pItems)
    
    ' Loop through all file names and create pDoc objects. Load the text into the
    ' buffers and parse it. We do not create scintilla window until the document is
    ' asked to be displayed.
    for i = lbound(AllFilenames) to ubound(AllFilenames)
        if len(AllFilenames(i)) = 0 then continue for

        ' Save the folder where this file was opened from into the gApp.wszLastOpenFolder
        ' variable so that subsequent uses of the File Open dialog will default to this folder.
        if i = lbound(AllFilenames) then 
            gApp.wszLastOpenFolder = AfxStrPathName( "PATH", AllFilenames(i) )
        end if

        ' Test to see if the file is already loaded in the editor. if it is, then
        ' bypass loading it again thereby creating multiple ghost instances.
        dim pDoc as clsDocument ptr
        dim pDocSearch as clsDocument ptr
        
        if bIsTemplate then
            pDoc = gApp.CreateEmptyDocument( true )
            pDoc->LoadDiskFile( AllFilenames(i), true, true )
        else
            pDocSearch = gApp.GetDocumentPtrByFilename(AllFilenames(i)) 
            if pDocSearch = 0 then
                pDoc = gApp.CreateEmptyDocument()
                pDoc->LoadDiskFile( AllFilenames(i) )
                ' Set type of file based on file extension (used to categorize project files)
                pDoc->SetProjectFileType()
            end if    
        end if
        
        if (bShowInTab = true) andalso (pDoc <> 0) then pDocTabs(i) = pDoc
        if (bShowInTab = true) andalso (pDocSearch <> 0) then pDocTabs(i) = pDocSearch
    next


    ' Loop through all files that are tagged to be displayed in the top tabcontrol.
    ' Files being added to a Project do not get added to the tabe control.
    dim as long iTab = -1
    for i = lbound(pDocTabs) to ubound(pDocTabs)
        if pDocTabs(i) = 0 then continue for
        iTab = gTTabCtl.GetTabIndexByDocumentPtr(pDocTabs(i))
        if iTab = -1 then 
            pDocTabs(i)->AssignTextBuffer()
            ' If this is a Template then set the buffer dirty (Templates would have IsNewFlag)
            if pDocTabs(i)->IsNewFlag then
                pDocTabs(i)->UserModified = true
            end if
            ' Add the new document to the top tabcontrol
            iTab = gTTabCtl.AddTab(pDocTabs(i))  
            UpdateMRUList(pDocTabs(i)->DiskFilename) 
        end if
    next   

    ' Load Explorer names first SetFocusTab will highlight it.
    LoadExplorerFiles()
    LoadFunctionsFiles()
    if iTab > -1 then gTTabCtl.SetFocusTab(iTab)

    gApp.IsFileLoading = false
    
    ' reset filename loading text that displays in StatusBar panel
    gApp.wszPanelText = ""   

    SetCursor( LoadCursor(0, IDC_ARROW) )
    ResetScintillaCursors
    frmMain_PositionWindows
    frmMain_SetFocusToCurrentCodeWindow
    
    function = 0

end function


' ========================================================================================
' Save the incoming pDoc file to disk
' ========================================================================================
function OnCommand_FileSave( _
            byval hwnd as HWND, _
            byval pDoc as clsDocument ptr, _
            byval bSaveAs as boolean, _
            byval bSaveAll as boolean _
            ) as boolean

    if gApp.GetDocumentCount = 0 then exit function
    
    dim as long i, iStart, iEnd
    
    if bSaveAll then
        ' Save All
        iStart = 0
        iEnd = gTTabCtl.GetItemCount - 1
    else
        ' Save
        iStart = gTTabCtl.GetTabIndexByDocumentPtr(pDoc)
        iEnd = iStart
    end if 

    for i = iStart to iEnd
        ' Get the document pointer and then save file to disk
        if gTTabCtl.IsSafeIndex(i) then
            pDoc = gTTabCtl.tabs(i).pDoc
            if pDoc = 0 then continue for
        end if   

        If (cbool(SciExec( pDoc->hWindow(0), SCI_GETMODIFY, 0, 0 ) <> 0)) orelse _
           (pDoc->UserModified = true) orelse (bSaveAs = true) then   
            ' Do the actual saving to disk
            dim wszFilename as CWSTR = pDoc->DiskFilename
            if pDoc->SaveFile(bSaveAs) = false then
                pDoc->ApplyProperties
                pDoc->ParseDocument()
                ' Apply document properties to this file because the file extension may have
                ' changed. for example from Untitled to *.bas
                if pDoc->DiskFilename <> wszFilename then
                    if gApp.IsProjectActive then
                        gApp.ProjectSetFileType( pDoc, pDoc->ProjectFileType )    
                    end if
                end if
            else
                'return true   
                exit for
            end if
        end if    

        ' Ensure that the Tab displays the correct filename in case it was changed
        gTTabCtl.SetTabText(-1)
    next
    
    LoadExplorerFiles()
    LoadFunctionsFiles()

    frmMain_SetFocusToCurrentCodeWindow

    function = false
end function


' ========================================================================================
' Rename the incoming pDoc file to disk
' ========================================================================================
function OnCommand_FileRename( _
            byval hwnd as HWND, _
            byval pDoc as clsDocument ptr _
            ) as LRESULT

    dim wszFilename_original  as wstring * MAX_PATH
    dim wszFilename_AutoSave  as wstring * MAX_PATH
    dim wszFilename  as wstring * MAX_PATH
    dim wszExtension as wstring * MAX_PATH

    ' Display the Rename Dialog (Save File Dialog)
    wszFilename_original = pDoc->DiskFilename
    dim pwszName as wstring ptr = AfxIFileSaveDialog(HWND_FRMMAIN, @wszFilename_original, @wszExtension, IDM_FILERENAME)
    if pwszName then
        wszFilename = *pwszName
        ' Apply document properties to this file because the file extension may have
        ' changed. for example from Untitled to *.bas
        if pDoc->DiskFilename <> wszFilename then
            if gApp.IsProjectActive then
                gApp.ProjectSetFileType( pDoc, pDoc->ProjectFileType )    
            end if
        end if
        ' If we are trying to rename and overwrite an existing file (we would have already gotten
        ' the popup message warning to replace the file), then we need to delete that file first 
        ' otherwise the AfxRenameFile will fail.
        if AfxFileExists(wszFilename) then AfxDeleteFile(wszFilename)
        if AfxRenameFile( wszFilename_original, wszFilename ) then
            pDoc->DiskFilename = wszFilename
        end if    

        CoTaskMemFree(pwszName)

    else
        return false
    end if

    LoadExplorerFiles()
    LoadFunctionsFiles()

    frmMain_SetFocusToCurrentCodeWindow

    function = 0
end function


' ========================================================================================
' Save all open files to disk
' ========================================================================================
function OnCommand_FileSaveAll( byval hwnd as HWND ) as boolean

    if gTTabCtl.GetItemCount = 0 then exit function
                
    return OnCommand_FileSave( hwnd, 0, false, true )
end function


' ========================================================================================
' Close current (or all) open file(s)
' ========================================================================================
function OnCommand_FileClose( _
            byval hwnd as HWND, _
            byval veFileClose as eFileClose, _
            byval nTabNum as long = -1 _
            ) as LRESULT

    dim wText as wstring * MAX_PATH  
    dim pDoc as clsDocument ptr
    dim as long r
    
    ' if a Project is not active then we need to save the current non-project notes
    ' when this file is closed. It is possible that this file is being closed and
    ' a project is being opened.
    if gApp.IsProjectActive = false then
        gApp.NonProjectNotes = AfxGetWindowText(GetDlgItem(HWND_FRMOUTPUT, IDC_FRMOUTPUT_TXTNOTES))
    end if
    
    ' Build a list of files to check
    dim as long nCurSel 
    ' if the incoming nTabNum is -1 then we want to close the current
    ' active document, otherwise close the specified tab.
    nCurSel = iif(nTabNum = -1, gTTabCtl.CurSel, nTabNum)

    dim as long nCount = gTTabCtl.GetItemCount

    if nCount = 0 then return true
    
    redim bCloseIndex(nCount - 1) as boolean

    for i as long = 0 to nCount - 1 
        SELECT CASE veFileClose
            case EFC_CLOSEALL:         bCloseIndex(i) = true
            case EFC_CLOSECURRENT:     bCloseIndex(i) = iif(i = nCurSel, true, false)
            case EFC_CLOSEALLOTHERS:   bCloseIndex(i) = iif(i <> nCurSel, true, false)
            case EFC_CLOSEALLFORWARD:  bCloseIndex(i) = iif(i > nCurSel, true, false) 
            case EFC_CLOSEALLBACKWARD: bCloseIndex(i) = iif(i < nCurSel, true, false)
        end select
    next
    
    ' Save the pDoc of the current active document in case we need to us it after
    ' the deletes are done to restore the correct tab index.
    dim as clsDocument ptr pDocActive = gTTabCtl.tabs(gTTabCtl.CurSel).pDoc
    
    ' Must do everything in reverse order because when Tabs are removed
    ' then the indexes would be out of sync if done in ascending order.
    for i as long = nCount - 1 to 0 step -1
        if bCloseIndex(i) = false then continue for

        pDoc = gTTabCtl.GetDocumentPtr(i)
        if pDoc = 0 then return true

        if IsWindow(pDoc->hWindow(0)) = 0 then continue for
    
        if cbool(SciExec( pDoc->hWindow(0), SCI_GETMODIFY, 0, 0)) orelse _
            (pDoc->UserModified = true) then
            
            gTTabCtl.SetFocusTab(i)
            r = MessageBox( hwnd, L(76,"Save current changes?") & wstr(" ") & wText, @wstr(APPNAME), _
                            MB_YESNOCANCEL Or MB_ICONQUESTION)
            if r = IDCANCEL then exit function
            if r = IDYES then 
                r = pDoc->SaveFile()
                if r = true then exit function   ' save was cancelled
                elseif r = IDNO then
            end if
        end if
        
        ' Hide the Scintilla editing windows
        for ii as long = lbound(pDoc->hWindow) to ubound(pDoc->hWindow)
            ShowWindow( pDoc->hWindow(ii), SW_HIDE)
        next
        SetRectEmpty( @pDoc->rcSplitButton )
        
        ' remove tab from gTTabCtl.tabs() array
        gTTabCtl.RemoveElement(i)
            
        ' Only remove this document from the global collection if it is not
        ' part of any active Project or if it is new/unsaved file. Files that are part of a project are
        ' all closed (tabs/nodes) automatically in one shot rather than individually.
        dim as boolean bRemoveFile 
        if pDoc->IsNewFlag = true then 
            bRemoveFile = true
        else
            bRemoveFile = iif( gApp.IsProjectActive, false, true )
        end if

        if bRemoveFile then
            ' Remove all references from the gdb2 database. Only remove the reference
            ' if the file is not part of an active project, otherwise, we will lose
            ' references to function names, etc.
            gdb2.dbDelete( pDoc->DiskFilename )
            ' Save positioning information to be saved to project file
            pDoc->SetDocInfo()   
            gApp.RemoveDocument( pDoc )
            LoadExplorerFiles()
        end if
    next
        
    ' Set the active tab to the closest tab to the one just removed if it was the 
    ' current active tab that was removed.
    if (veFileClose = EFC_CLOSECURRENT) andalso (nCurSel = gTTabCtl.CurSel) then
        dim as long idx = gTTabCtl.CurSel - 1
        gTTabCtl.CurSel = -1  ' it is no longer valid
        if idx < lbound(gTTabCtl.tabs) then idx = lbound(gTTabCtl.tabs)
        if gTTabCtl.IsSafeIndex( idx ) then
            gTTabCtl.CurSel = gTTabCtl.SetFocusTab( idx )
        end if
    else
        ' we need to set our gTTabCtl.CurSel to the correct array index because
        ' the array has been resized and the cursel would no longer be valid.
        gTTabCtl.CurSel = -1  ' it is no longer valid
        if pDoc then gTTabCtl.CurSel = gTTabCtl.SetTabIndexByDocumentPtr(pDocActive)
    end if

    frmMain_PositionWindows
    frmExplorer_PositionWindows
    frmTopTabs_PositionWindows
    
    ' important to repaint the workspace to remove any separator bar and splitter
    ' rectangle should all documents be closed. Removes screen artifacts.
    AfxRedrawWindow( HWND_FRMMAIN )
    
    function = true
end function


' ========================================================================================
' Message received from Explorer popup menu
' ========================================================================================
function OnCommand_FileExplorerMessage( _
            byval id as long, _
            byval pDoc as clsDocument ptr _
            ) as LRESULT
    
    if id = IDM_FILEOPEN_EXPLORERLISTBOX then
        OpenSelectedDocument( pDoc->DiskFilename )

    elseif id = IDM_FILESAVE_EXPLORERLISTBOX then
        OnCommand_FileSave( HWND_FRMMAIN, pDoc, false )

    elseif id = IDM_FILESAVEAS_EXPLORERLISTBOX then
        OnCommand_FileSave( HWND_FRMMAIN, pDoc, true )

    elseif id = IDM_FILERENAME_EXPLORERLISTBOX then
        OnCommand_FileRename( HWND_FRMMAIN, pDoc )

    elseif IDM_FILECLOSE_EXPLORERLISTBOX then
        dim as long nCurSel = gTTabCtl.GetTabIndexByDocumentPtr( pDoc )
        if nCurSel <> -1 then
            OnCommand_FileClose( HWND_FRMMAIN, EFC_CLOSECURRENT, nCurSel )
        end if   
    end if   

    function = 0
end function


' ========================================================================================
' Load a previously saved session
' ========================================================================================
function OnCommand_FileLoadSession( byval hwnd as HWND ) as LRESULT
    ' Display the Open File Dialog
    dim pwszName as wstring ptr = AfxIFileOpenDialogW(hwnd, IDM_LOADSESSION)
    if pwszName then 
        if gApp.IsProjectActive then 
            if OnCommand_ProjectClose(hwnd) = false then exit function
        else   
            if OnCommand_FileClose(hwnd, EFC_CLOSEALL) = false then exit function
        end if
        ' Clear any previous info from the Output windows
        frmOutput_ResetAllControls()
        gConfig.LoadSessionFile(*pwszName) 
        CoTaskMemFree(pwszName)
    end if
    function = 0
end function


' ========================================================================================
' Save a session
' ========================================================================================
function OnCommand_FileSaveSession( byval hwnd as HWND ) as LRESULT
    dim wszFilename  as wstring * MAX_PATH = ""
    dim wszExtension as wstring * MAX_PATH = "session"
    dim pwszName as wstring ptr = AfxIFileSaveDialog(HWND_FRMMAIN, @wszFilename, @wszExtension, IDM_SAVESESSION)
    if pwszName then
        gConfig.SaveSessionFile(*pwszName)
        CoTaskMemFree(pwszName)
    end if
    function = 0
end function


' ========================================================================================
' Close a session
' ========================================================================================
function OnCommand_FileCloseSession( byval hwnd as HWND ) as LRESULT
    gConfig.wszLastActiveSession = ""
    gConfig.SaveConfigFile()
    gConfig.CloseSessionFile(gApp.SessionFilename)
    function = 0
end function
        
