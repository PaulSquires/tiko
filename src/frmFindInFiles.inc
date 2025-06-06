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

#include once "frmFindInFiles.bi"
#include once "frmOutput.bi"
#include once "clsDocument.bi"


''
''
function FindInFiles_ProcessFile( _
            byref pStreamResults as CTextStream, _
            byref wszFindText as wstring, _
            byref wszFilename as wstring, _
            byval bMatchCase  as boolean, _
            byval bWholeWords as boolean _
            ) as long

    dim as long nLineNum = 0
    dim as long nFoundPos, nStartPos 
    dim as boolean bUnicode = AfxIsFileUnicode( wszFilename )
    
    dim pStream as CTextStream  

    if pStream.Open( wszFilename, IOMODE_FORREADING, false, bUnicode ) = S_OK then
    
        dim as CWSTR wszLine, wszResult, wszLookLine
        
        if bMatchCase = false then wszFindText = ucase(wszFindText)
        
        do until pStream.EOS
            wszLine = pStream.ReadLine

            nLineNum = nLineNum + 1
            
            if len(wszLine) < len(wszFindText) then continue do
            
            wszLookLine = iif(bMatchCase, wszLine, ucase(wszLine))

            nFoundPos = instr( 1, wszLookLine, wszFindText ) 
            
            do until nFoundPos = 0    
                nStartPos = nFoundPos + len(wszFindText)
                if bWholeWords then
                    ' Only give a positive match if the character before and after the match
                    ' position is not an alphanumeric or space.
                    dim as long chLeftChar  = asc(wszLine, nFoundPos - 1)
                    dim as long chRightChar = asc(wszLine, nFoundPos + len(wszFindText))
                    
                    ' If word is enclosed by spaces then it is okay. 
                    if ( chLeftChar = 32 ) andalso ( chRightChar = 32 ) then 
                        ' okay
                    elseif IsCharAlphaNumeric( chLeftChar ) orelse _
                            IsCharAlphaNumeric( chRightChar ) then _
                        nFoundPos = 0
                    end if   
                end if
            
                ' If we still have a valid result after doing the bWholeWords test then
                ' output the result to the results text file.
                if nFoundPos > 0 then   
                    wszResult = wszFilename & ":" & nLineNum & ":" & wszLine
                    pStreamResults.WriteLine wszResult
                    ' We have found a match within the line. No need to continue searching
                    ' on this line because we don't want multiple copies outputted to the file.
                    exit do
                end if   

                nFoundPos = instr( nStartPos, wszLookLine, wszFindText ) 
            loop   
            
        loop                        
        pStream.Close

    else
        ' ? "ERROR: "; wszFilename, bUnicode, pStream.GetErrorInfo
    end if
    
    function = 0
end function


''
''
function FindInFiles_RecursiveFileSearch( _
            byref pStreamResults as CTextStream, _
            byref wszFindText as wstring, _
            byref wszFilePath as wstring, _
            wszFileSpecs() as CWSTR, _
            byval bSubFolders as boolean, _
            byval bMatchCase  as boolean, _
            byval bWholeWords as boolean _
            ) as Long
                                
    dim pFinder as CFindFile
    
    if pFinder.FindFile( wszFilePath & "\*.*" ) = S_OK then
        do
            if pFinder.IsDots then   
                ' skip
            elseif pFinder.IsFolder then
                if bSubFolders then
                    FindInFiles_RecursiveFileSearch( _
                                pStreamResults, _
                                wszFindText, _
                                pFinder.FilePath, _
                                wszFileSpecs(), _ 
                                bSubFolders, _
                                bMatchCase, _
                                bWholeWords _
                                )
                end if
            else
                dim as boolean bProcessFile = false
                dim as CWSTR wszExt
            
                for i as long = lbound(wszFileSpecs) to ubound(wszFileSpecs)
                    bProcessFile = false
                    ' Check if the file spec is a wildcard or a matching filename.
                    if instr( wszFileSpecs(i), "*" ) then
                        wszExt = ucase(ltrim(AfxStrPathName("EXTN", wszFileSpecs(i)), "."))
                        if (ucase(pFinder.FileExt) = wszExt) orelse (wszExt = "*") then
                            ' bypass know binary files
                            select case ucase(pFinder.FileExt)
                            case "EXE", "DLL", "GIF", "PNG", "JPG", "JPEG", "BMP", "ICO", _
                                    "TIFF", "CHM", "CHW", "CUR", "XLS", "XLSX", "PDF", "ZIP", _
                                    "SVG", "RAR"
                                bProcessFile = false
                            case else   
                                bProcessFile = true
                            end select
                        end if
                    else
                        ' Check if the filename matches.
                        if ucase(wszFileSpecs(i)) = ucase(pFinder.FilePath) then
                            bProcessFile = true
                        end if
                    end if
                    
                    if bProcessFile then
                        FindInFiles_ProcessFile( _
                                        pStreamResults, _
                                        wszFindText, _
                                        pFinder.FilePath, _
                                        bMatchCase, _
                                        bWholeWords _
                                        )
                        exit for
                    end if
                next
            
            end if

            if pFinder.FindNext = 0 then exit do
        loop
    end if
    pFinder.Close

    function = 0
end function



' ========================================================================================
' Set the states of the various controls
' ========================================================================================
function frmFindInFiles_SetControlStates() as long

    Button_SetCheck( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKWHOLEWORDS),  gFindInFiles.nWholeWord )
    Button_SetCheck( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKMATCHCASE),   gFindInFiles.nMatchCase )
    Button_SetCheck( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKSUBFOLDERS),  gFindInFiles.nSearchSubFolders )

    Button_SetCheck( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKCURRENTDOC),  gFindInFiles.nSearchCurrentDoc )
    Button_SetCheck( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKALLOPENDOCS), gFindInFiles.nSearchAllOpenDocs )
    Button_SetCheck( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKPROJECT),     gFindInFiles.nSearchProject )
    
    dim as long bEnable = true
    
    if (gFindInFiles.nSearchCurrentDoc = BST_CHECKED) orelse _
        (gFindInFiles.nSearchAllOpenDocs = BST_CHECKED) orelse _
        (gFindInFiles.nSearchProject = BST_CHECKED ) then
        bEnable = false   
    end if
    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFILES), bEnable )    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFOLDER), bEnable )    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CMDFILES), bEnable )    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CMDFOLDERS), bEnable )    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKSUBFOLDERS), bEnable )    
    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKCURRENTDOC), _
                    iif( gTTabCtl.GetActiveDocumentPtr, true, false) )     
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKALLOPENDOCS), _
                    iif( gTTabCtl.GetItemCount, true, false) )     
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_CHKPROJECT), _
                    gApp.IsProjectActive )     

    function = 0
end function


' ========================================================================================
' Add a string to the Find combobox (ensure no duplicates)
' ========================================================================================
function frmFindInFiles_AddToFindCombo( byref wszText as string ) as long
    dim as long i
    dim as long nFound = -1
    
    wszText = trim(wszText)
    if len(wszText) = 0 then exit function
    
    ' See if the string already exists in the combobox
    for i = 0 to ubound(gFindInFiles.txtFindCombo)
        if gFindInFiles.txtFindCombo(i) = wszText then
            nFound = i: exit for
        end if
    next

    if nFound = -1 then  ' was not found
        for i = ubound(gFindInFiles.txtFindCombo) to 1 step -1
            gFindInFiles.txtFindCombo(i) = gFindInFiles.txtFindCombo(i-1)
        next   
        gFindInFiles.txtFindCombo(0) = wszText
    end if
    
    gFindInFiles.txtFind = wszText
    
    function = 0
end function


' ========================================================================================
' Add a string to the Files combobox (ensure no duplicates)
' ========================================================================================
function frmFindInFiles_AddToFilesCombo( byref wszText as wstring ) as long
    dim as long i
    dim as long nFound = -1
    
    ' Array is current 0 to 10 dimension
    wszText = trim(wszText)
    
    if len(wszText) = 0 then exit function
    
    ' See if the string already exists in the combobox
    for i = 0 to ubound(gFindInFiles.txtFilesCombo)
        if gFindInFiles.txtFilesCombo(i) = wszText then
            nFound = i: exit for
        end if
    next
    
    if nFound = -1 then  ' was not found
        ' Move all entries down onw and add the text at the beginning of the list.
        for i = ubound(gFindInFiles.txtFilesCombo) to 1 step -1
            gFindInFiles.txtFilesCombo(i) = gFindInFiles.txtFilesCombo(i-1)
        next   
        gFindInFiles.txtFilesCombo(0) = wszText
    end if
    
    gFindInFiles.txtFiles = wszText

    function = 0
end function


' ========================================================================================
' Add a string to the Folders combobox (ensure no duplicates)
' ========================================================================================
function frmFindInFiles_AddToFolderCombo( byref wszText as wstring ) as long
    dim as long i
    dim as long nFound = -1
    
    wszText = trim(wszText)
    if len(wszText) = 0 then exit function
    
    ' See if the string already exists in the combobox
    for i = 0 to ubound(gFindInFiles.txtFolderCombo)
        if gFindInFiles.txtFolderCombo(i) = wszText then
            nFound = i: exit for
        end if
    next
    
    if nFound = -1 then  ' was not found
        for i = ubound(gFindInFiles.txtFolderCombo) to 1 step -1
            gFindInFiles.txtFolderCombo(i) = gFindInFiles.txtFolderCombo(i-1)
        next   
        gFindInFiles.txtFolderCombo(0) = wszText
    end if
    
    gFindInFiles.txtFolder = wszText

    function = 0
end function


' ========================================================================================
' File search procedure (shell out to builtin Windows "findstr" utility
' ========================================================================================
function frmFindInFiles_DoFindInFilesEx() as long
    dim ShExecInfo as SHELLEXECUTEINFOW  
    dim as CWSTR DQ = wchr(34)
    
    dim as HCURSOR hCurSave = GetCursor()
    SetCursor( LoadCursor(0, IDC_WAIT) )

    ' Ensure that the text in the find textbox has been added to the combobox. Need to do
    ' this to ensure that manually typed in text has been captured.
    dim wszFindText As wstring * MAX_PATH
    wszFindText = AfxGetWindowText( GetDlgItem(HWnd_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFIND))
    
    if len(wszFindText) = 0 then
        SetFocus( GetDlgItem(HWnd_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFIND) )
        exit function      
    end if
    
    gFindInFiles.txtFind = wszFindText
    frmFindInFiles_AddToFindCombo(gFindInFiles.txtFind)
    
    ' What folder to start searching in
    gFindInFiles.txtFolder = trim(AfxGetWindowText( GetDlgItem(HWND_FRMFINDINFILES,IDC_FRMFINDINFILES_COMBOFOLDER) ))
    if len(gFindInFiles.txtFolder) = 0 then 
        gFindInFiles.txtFolder = AfxGetExePathName
        AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES,IDC_FRMFINDINFILES_COMBOFOLDER), gFindInFiles.txtFolder )
    end if
    
    frmFindInFiles_AddToFolderCombo(gFindInFiles.txtFolder)
    
    if right(gFindInFiles.txtFolder,1) <> "\" then gFindInFiles.txtFolder = gFindInFiles.txtFolder & "\"
    dim wszFolder as CWSTR = gFindInFiles.txtFolder 

    ' What files are we searching in
    dim as boolean bInString
    dim as long ub
    dim as CWSTR wszFiles, wszSearchFiles, wszFilename
    
    wszFiles = trim(AfxGetWindowText( GetDlgItem(HWnd_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFILES)))
    gFindInFiles.txtFiles = wszFiles
    frmFindInFiles_AddToFilesCombo( gFindInFiles.txtFiles )
    
    dim wszFileSpecs(any) as CWSTR
    ' Examples:
    '     dim wszFileSpecs(2) as CWSTR
    '     wszFileSpecs(0) = "*.bas"
    '     wszFileSpecs(1) = "*.bi"
    '     wszFileSpecs(2) = "*.inc"

    ' Look at the files to determine if multiple files or file types need to be searched for.
    if instr( wszFiles, DQ ) then
        ' In order to better parse the string for the filenames, replace any spaces within the
        ' filenames with special character (Ascii(8)); then parse; and finally replace the special character.
        for i as long = 0 to len(wszFiles) - 1
            select case wszFiles[i]
            case 34      ' double quote
                bInString = not bInString 
            case 32      ' space
                if bInString then wszFiles[i] = 8   
            end select
        NEXT
        
        ' Clean the string to remove any duplicate remaining spaces
        wszFiles = AfxStrShrink(wszFiles)

        ' This is a list of double quoted filenames to search
        dim as long nCount = AfxStrParseCount(wszFiles, " ")

        for i as long = 1 to nCount
            wszFilename = trim( AfxStrParse(wszFiles, i, " "), DQ )
            ' Put back any special characters to spaces again
            wszFilename = AfxStrReplace(wszFilename, wchr(8), " " )
            ' Add it to our list of wszFileSpecs
            ub = ubound(wszFileSpecs) + 1
            redim preserve wszFileSpecs( ub )
            wszFileSpecs(ub) = wszFolder & wszFilename
        next   

    else
        ' This is a list of patterns to use (*.bas *.bi) etc
        dim as long nCount = AfxStrParseCount( wszFiles, " " )
        for i as long = 1 to nCount
            ub = ubound(wszFileSpecs) + 1
            redim preserve wszFileSpecs( ub )
            wszFileSpecs(ub) = wszFolder & AfxStrParse( wszFiles, i, " " )
        next   
    end if
        

    ' Create a results file to capture the results
    dim pStreamResults as CTextStream  ' (create)(utf16)
    dim as CWSTR wszSearchResults = AfxGetExePathName & "_searchresults.txt"
    if pStreamResults.Create( wszSearchResults, true, true) = S_OK then 

        dim as boolean bWholeWord  = iif( gFindInFiles.nWholeWord = BST_CHECKED, true, false )
        dim as boolean bMatchCase  = iif( gFindInFiles.nMatchCase = BST_CHECKED, true, false )
        dim as boolean bSubFolders = iif( gFindInFiles.nSearchSubFolders = BST_CHECKED, true, false )
        
        if (gFindInFiles.nSearchProject = BST_CHECKED) or _
            (gFindInFiles.nSearchCurrentDoc = BST_CHECKED) or _
            (gFindInFiles.nSearchAllOpenDocs = BST_CHECKED) then 

            dim pDoc as clsDocument ptr = gApp.pDocList
            do until pDoc = 0
                wszFilename = ""
                
                if gFindInFiles.nSearchProject = BST_CHECKED then
                    wszFilename = pDoc->DiskFilename
                end if   
                
                if gFindInFiles.nSearchAllOpenDocs = BST_CHECKED then 
                    if gTTabCtl.GetTabIndexFromFilename( pDoc->DiskFilename ) <> -1 then
                        wszFilename = pDoc->DiskFilename
                    end if   
                end if
                
                if gFindInFiles.nSearchCurrentDoc = BST_CHECKED then
                    if pDoc = gTTabCtl.GetActiveDocumentPtr() then
                        wszFilename = pDoc->DiskFilename
                    end if
                end if

                FindInFiles_ProcessFile( _
                                pStreamResults, _
                                gFindInFiles.txtFind, _
                                wszFilename, _
                                bMatchCase, _
                                bWholeWord _
                                )
                        
                pDoc = pDoc->pDocNext
            loop   

        else
            FindInFiles_RecursiveFileSearch( _
                        pStreamResults, _
                        gFindInFiles.txtFind, _
                        gFindInFiles.txtFolder, _
                        wszFileSpecs(), _
                        bSubFolders, _      ' Search subfolders
                        bMatchCase, _       ' Match case
                        bWholeWord _        ' Whole words
                        )
        end if
        
        pStreamResults.Close
    else
        ' ? "Error creating _FindResults.txt file."
    end if   

    frmOutput_UpdateSearchListview( wszSearchResults )
    
    SetCursor( hCurSave )
        
    function = 0
end function


' ========================================================================================
' Process WM_COMMAND message for window/dialog: frmFindInFiles
' ========================================================================================
function frmFindInFiles_OnCommand( _
            byval hwnd as HWND, _
            byval id as long, _
            byval hwndCtl as HWND, _
            byval codeNotify As UINT _
            ) as LRESULT

    select case id
        case IDOK  ' Find Next
            if codeNotify = BN_CLICKED then
                EnableWindow(hwndCtl, false)
                frmFindInFiles_DoFindInFilesEx()
                EnableWindow(hwndCtl, true)
                exit function
            end if  
            
        case IDCANCEL  ' Close
            if codeNotify = BN_CLICKED then
                SendMessage( HWnd, WM_CLOSE, 0, 0)
                exit function
            end if

        case IDC_FRMFINDINFILES_COMBOFIND
            ' Catch the dropdown of the Find combobox so we can populate it
            if codeNotify = CBN_DROPDOWN then
                ' Add any previous search terms to the combobox
                dim as long i
                dim wszText as wstring * MAX_PATH
                wszText = AfxGetWindowText(hwndCtl)
                frmFindInFiles_AddToFindCombo(str(wszText))
                ComboBox_ResetContent(hwndCtl)
                for i = 0 To ubound(gFindInFiles.txtFindCombo)
                    if len(gFindInFiles.txtFindCombo(i)) then 
                        wszText = gFindInFiles.txtFindCombo(i)
                        ComboBox_AddString( hwndCtl, @wszText )
                    end if   
                next
                wszText = gFindInFiles.txtFind
                i = ComboBox_FindStringExact( hwndCtl, -1, @wszText )
                ComboBox_SetCurSel(hwndCtl, i)
            end if

        case IDC_FRMFINDINFILES_COMBOFILES
            ' Catch the dropdown of the Files combobox so we can populate it
            if codeNotify = CBN_DROPDOWN then
                ' Add any previous search terms to the combobox
                dim as long i
                dim wszText as wstring * MAX_PATH
                wszText = AfxGetWindowText(hwndCtl)
                frmFindInFiles_AddToFilesCombo(str(wszText))
                ComboBox_ResetContent(hwndCtl)
                for i = 0 to ubound(gFindInFiles.txtFilesCombo)
                    if len(gFindInFiles.txtFilesCombo(i)) then 
                        wszText = gFindInFiles.txtFilesCombo(i)
                        ComboBox_AddString( hwndCtl, @wszText )
                    end if   
                next
                wszText = gFindInFiles.txtFiles
                i = ComboBox_FindStringExact( hwndCtl, -1, @wszText )
                ComboBox_SetCurSel(hwndCtl, i)
            end if
        
        case IDC_FRMFINDINFILES_COMBOFOLDER
            ' Catch the dropdown of the Files combobox so we can populate it
            If codeNotify = CBN_DROPDOWN Then
                ' Add any previous search terms to the combobox
                dim as long i
                dim wszText as wstring * MAX_PATH
                wszText = AfxGetWindowText(hwndCtl)
                frmFindInFiles_AddToFolderCombo(str(wszText))
                ComboBox_ResetContent(hwndCtl)
                for i = 0 to ubound(gFindInFiles.txtFolderCombo)
                    if len(gFindInFiles.txtFolderCombo(i)) then 
                        wszText = gFindInFiles.txtFolderCombo(i)
                        ComboBox_AddString( hwndCtl, @wszText )
                    end if   
                next
                wszText = gFindInFiles.txtFolder
                i = ComboBox_FindStringExact( hwndCtl, -1, @wszText )
                ComboBox_SetCurSel(hwndCtl, i)
            end if

        case IDC_FRMFINDINFILES_CMDFILES
            if codeNotify = BN_CLICKED then
                ' Display the Open File Dialog
                dim pItems as IShellItemArray ptr = AfxIFileOpenDialogMultiple(hwnd, IDM_FILEOPEN)
                if pItems = null then exit function
                dim dwItemCount as long, i as long, idx as long, pItem as IShellItem ptr, pwszName as wstring ptr
                pItems->lpVtbl->GetCount(pItems, @dwItemCount)
                
                dim wszFolder as CWSTR
                dim wszFiles as CWSTR

                for i = 0 to dwItemCount - 1
                    pItems->lpVtbl->GetItemAt(pItems, i, @pItem)
                    if pItem then
                        pItem->lpVtbl->GetDisplayName(pItem, SIGDN_FILESYSPATH, @pwszName)
                        if pwszName then 
                            wszFolder = AfxStrPathName("PATH", *pwszName)
                            AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES,IDC_FRMFINDINFILES_COMBOFOLDER), wszFolder)
                            wszFiles = wszFiles + chr(34) + AfxStrPathName("NAMEX", *pwszName) + chr(34, 32)
                            CoTaskMemFree(pwszName)
                            pwszName = null
                        end if
                        pItem->lpVtbl->Release(pItem)
                        pItem = null
                    end if
                next
                AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES,IDC_FRMFINDINFILES_COMBOFILES), wszFiles)
                gFindInFiles.txtFiles = str(wszFiles)
                pItems->lpVtbl->Release(pItems)
                exit function
            end if

        Case IDC_FRMFINDINFILES_CMDFOLDERS
            If codeNotify = BN_CLICKED Then
                static wszStartFolder as CWSTR
                dim wszFolder as CWSTR
                if len(wszStartFolder) = 0 then wszStartFolder = AfxGetExePathName
                wszFolder = AfxBrowseForFolder( HWND_FRMFINDINFILES, L(261,"Choose the folder to search in:"), wszStartFolder )
                if len(wszFolder) then
                    AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES,IDC_FRMFINDINFILES_COMBOFOLDER), wszFolder)
                    gFindInFiles.txtFolder = str(wszFolder)
                end if
                exit function
            end if

        case IDC_FRMFINDINFILES_CHKMATCHCASE
            if codeNotify = BN_CLICKED then
                gFindInFiles.nMatchCase = Button_GetCheck(hwndCtl)
                exit function
            end if

        case IDC_FRMFINDINFILES_CHKWHOLEWORDS
            if codeNotify = BN_CLICKED then
                gFindInFiles.nWholeWord = Button_GetCheck(hwndCtl)
                exit function
            end if

        case IDC_FRMFINDINFILES_CHKSUBFOLDERS
            if codeNotify = BN_CLICKED then
                gFindInFiles.nSearchSubFolders = Button_GetCheck(hwndCtl)
                exit function
            end if

        case IDC_FRMFINDINFILES_CHKCURRENTDOC
            if codeNotify = BN_CLICKED then
                gFindInFiles.nSearchCurrentDoc = Button_GetCheck(hwndCtl)
                gFindInFiles.nSearchAllOpenDocs = BST_UNCHECKED
                gFindInFiles.nSearchProject = BST_UNCHECKED
                frmFindInFiles_SetControlStates
                exit function
            end if

        case IDC_FRMFINDINFILES_CHKALLOPENDOCS
            if codeNotify = BN_CLICKED then
                gFindInFiles.nSearchAllOpenDocs = Button_GetCheck(hwndCtl)
                gFindInFiles.nSearchCurrentDoc = BST_UNCHECKED
                gFindInFiles.nSearchProject = BST_UNCHECKED
                frmFindInFiles_SetControlStates
                exit function
            end if

        case IDC_FRMFINDINFILES_CHKPROJECT
            if codeNotify = BN_CLICKED then
                gFindInFiles.nSearchProject = Button_GetCheck(hwndCtl)
                gFindInFiles.nSearchAllOpenDocs = BST_UNCHECKED
                gFindInFiles.nSearchCurrentDoc = BST_UNCHECKED
                frmFindInFiles_SetControlStates
                exit function
            end if

    end select

    function = 0
end function


' ========================================================================================
' Process WM_CLOSE message for window/dialog: frmFindInFiles
' ========================================================================================
function frmFindInFiles_OnClose( byval hwnd as HWND ) as LRESULT
    ' Enables parent window keeping parent's zorder
    EnableAllModeless()
    DestroyWindow hwnd
    function = 0
end function


' ========================================================================================
' Process WM_CREATE message for window/dialog: frmFindInFiles
' ========================================================================================
function frmFindInFiles_OnCreate( _
            byval hwnd as HWND, _
            byval lpCreateStructPtr as LPCREATESTRUCT _
            ) as boolean

    ' This is a modal popup window so disable the parent window
    DisableAllModeless()

    '  Message cracker macro expects a True to be returned for a successful
    '  OnCreate handler even though returning -1 from a standard WM_CREATE
    '  call would stop creating the window. This is just one of those Windows
    '  inconsistencies.
    return true
end function

' ========================================================================================
' Process WM_DESTROY message for window/dialog: frmFindInFiles
' ========================================================================================
function frmFindInFiles_OnDestroy( byval hwnd as HWND ) As LRESULT 
    ' Save the search parameters for later instances of the find/replace dialog
    gFindInFiles.nWholeWord = Button_GetCheck( GetDlgItem(hwnd, IDC_FRMFINDINFILES_CHKWHOLEWORDS) )  
    gFindInFiles.nMatchCase = Button_GetCheck( GetDlgItem(hwnd, IDC_FRMFINDINFILES_CHKMATCHCASE) )    
    gFindInFiles.nSearchSubFolders = Button_GetCheck( GetDlgItem(hwnd, IDC_FRMFINDINFILES_CHKSUBFOLDERS) )    
    gFindInFiles.nSearchCurrentDoc = Button_GetCheck( GetDlgItem(hwnd, IDC_FRMFINDINFILES_CHKCURRENTDOC) )
    gFindInFiles.nSearchAllOpenDocs = Button_GetCheck( GetDlgItem(hwnd, IDC_FRMFINDINFILES_CHKALLOPENDOCS) )
    gFindInFiles.nSearchProject = Button_GetCheck( GetDlgItem(hwnd, IDC_FRMFINDINFILES_CHKPROJECT) )
    gFindInFiles.txtFind = AfxGetWindowText( GetDlgItem(HWnd_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFIND))
    gFindInFiles.txtLastFind = gFindInFiles.txtFind 
    gFindInFiles.txtFiles = AfxGetWindowText( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFILES))
    gFindInFiles.txtFolder = AfxGetWindowText( GetDlgItem(HWND_FRMFINDINFILES,IDC_FRMFINDINFILES_COMBOFOLDER))

    HWND_FRMFINDINFILES = 0

    PostQuitMessage(0)

    function = 0
end function


' ========================================================================================
' frmFindInFiles Window procedure
' ========================================================================================
function frmFindInFiles_WndProc( _
            byval hwnd   as HWND, _
            byval uMsg   as UINT, _
            byval wParam as WPARAM, _
            byval lParam as LPARAM _
            ) as LRESULT

    select case uMsg
        HANDLE_MSG (hwnd, WM_CREATE,   frmFindInFiles_OnCreate)
        HANDLE_MSG (hwnd, WM_CLOSE,    frmFindInFiles_OnClose)
        HANDLE_MSG (hwnd, WM_DESTROY,  frmFindInFiles_OnDestroy)
        HANDLE_MSG (hwnd, WM_COMMAND,  frmFindInFiles_OnCommand)
    end select

    function = DefWindowProc(hwnd, uMsg, wParam, lParam)

end function


' ========================================================================================
' frmFindInFiles_Show
' ========================================================================================
function frmFindInFiles_Show( byval hWndParent as HWND ) as LRESULT
    '  Create the main window and child controls
    dim pWindow as CWindow ptr = new CWindow
    pWindow->DPI = AfxCWindowOwnerPtr(hwndParent)->DPI

    HWND_FRMFINDINFILES = _
    pWindow->Create(hwndParent, L(256,"Find In Files"), @frmFindInFiles_WndProc, 0, 0, 0, 0, _
        WS_POPUP or WS_CAPTION or WS_SYSMENU or WS_CLIPSIBLINGS or WS_CLIPCHILDREN, _
        WS_EX_DLGMODALFRAME or WS_EX_CONTROLPARENT or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->SetClientSize(515, 222)
    pWindow->Center
    
    pWindow->AddControl("LABEL", , IDC_FRMFINDINFILES_LBLFINDWHAT, L(159,"Find What") & ":", 7, 19, 70, 16, _
        WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or SS_RIGHT or SS_NOTIFY, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("LABEL", , IDC_FRMFINDINFILES_LABEL1, L(259,"In Files") & ":", 7, 48, 70, 16, _
        WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or SS_RIGHT or SS_NOTIFY, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("LABEL", , IDC_FRMFINDINFILES_LABEL1, L(260,"In Folder") & ":", 7, 78, 70, 16, _
        WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or SS_RIGHT or SS_NOTIFY, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("COMBOBOX", , IDC_FRMFINDINFILES_COMBOFIND, "", 85, 17, 317, 22, _
        WS_CHILD or WS_VISIBLE or WS_VSCROLL or WS_TABSTOP or CBS_DROPDOWN or CBS_AUTOHSCROLL, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->AddControl("COMBOBOX", , IDC_FRMFINDINFILES_COMBOFILES, "", 85, 46, 317, 21, _
        WS_CHILD or WS_VISIBLE or WS_VSCROLL or WS_TABSTOP or CBS_DROPDOWN or CBS_AUTOHSCROLL, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->AddControl("COMBOBOX", , IDC_FRMFINDINFILES_COMBOFOLDER, "", 85, 75, 317, 21, _
        WS_CHILD or WS_VISIBLE or WS_VSCROLL or WS_TABSTOP or CBS_DROPDOWN or CBS_AUTOHSCROLL, _
        WS_EX_CLIENTEDGE or WS_EX_LEFT or WS_EX_LTRREADING or WS_EX_RIGHTSCROLLBAR)
    pWindow->AddControl("BUTTON", , IDOK, L(158,"Find"), 414, 16, 90, 24, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_DEFPUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("BUTTON", , IDC_FRMFINDINFILES_CMDFILES, "...", 414, 45, 24, 24, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("BUTTON", , IDC_FRMFINDINFILES_CMDFOLDERS, "...", 414, 74, 24, 24, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("BUTTON", , IDCANCEL, L(161,"Close"), 414, 105, 90, 24, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_PUSHBUTTON or BS_NOTIFY or BS_CENTER or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("GROUPBOX", , IDC_FRMFINDINFILES_FRAMEOPTIONS, L(167,"Options"), 16, 105, 386, 107, _
        WS_CHILD or WS_VISIBLE or BS_TEXT or BS_LEFT or BS_NOTIFY or BS_GROUPBOX, _
        WS_EX_TRANSPARENT or WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMFINDINFILES_CHKWHOLEWORDS, L(162,"Match Whole Words"), 26, 123, 167, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMFINDINFILES_CHKMATCHCASE, L(163,"Match Case"), 26, 143, 167, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMFINDINFILES_CHKSUBFOLDERS, L(258,"Search Subfolders"), 26, 163, 167, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)

    pWindow->AddControl("CHECKBOX", , IDC_FRMFINDINFILES_CHKCURRENTDOC, L(408,"Current Document"), 195, 123, 167, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMFINDINFILES_CHKALLOPENDOCS, L(409,"All Open Documents"), 195, 143, 167, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)
    pWindow->AddControl("CHECKBOX", , IDC_FRMFINDINFILES_CHKPROJECT, L(410,"Current Project"), 195, 163, 167, 20, _
        WS_CHILD or WS_VISIBLE or WS_TABSTOP or BS_TEXT or BS_NOTIFY or BS_AUTOCHECKBOX or BS_LEFT or BS_VCENTER, _
        WS_EX_LEFT or WS_EX_LTRREADING)

    dim as long i, nCount, startPos, endPos, startLine, endLine
    dim as string buffer, sFind, sFiles, sFolder
    
    dim pDoc as clsDocument ptr = gTTabCtl.GetActiveDocumentPtr()
    if pDoc then
        ' Fills the search box with the selected word.
        ' If there are carriage returns or/and line feeds, this mean that
        ' there is a block selected, instead of a word, so avoid it.
        buffer = pDoc->GetSelText()
        if len(buffer) then
            if pDoc->IsMultilineSelection = false then
                sFind = buffer
                gFindInFiles.txtLastFind = buffer
            end if
        else
            sFind = gFindInFiles.txtLastFind
        end if
    end if
    frmFindInFiles_AddToFindCombo(sFind)

    if len(gFindInFiles.txtFilesCombo(0)) = 0 then sFiles = "*.bas *.bi *.inc"
    frmFindInFiles_AddToFilesCombo(sFiles)
    
    if len(gFindInFiles.txtFolderCombo(0)) = 0 then 
        if gApp.IsProjectActive then
            sFolder = AfxStrPathName("PATH", gApp.ProjectFilename)
        else
            sFolder = AfxGetExePathName 
        end if
    end if
    frmFindInFiles_AddToFolderCombo(sFolder)
    
    if gApp.IsProjectActive then
        gFindInFiles.nSearchProject = BST_CHECKED
        frmFindInFiles_SetControlStates
    end if

    AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFIND), gFindInFiles.txtFind )    
    AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFILES), gFindInFiles.txtFiles )    
    AfxSetWindowText( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFOLDER), gFindInFiles.txtFolder )    
    EnableWindow( GetDlgItem(HWND_FRMFINDINFILES, IDOK), true )
    
    frmFindInFiles_SetControlStates

    ShowWindow HWND_FRMFINDINFILES, SW_SHOW
    SetFocus( GetDlgItem(HWND_FRMFINDINFILES, IDC_FRMFINDINFILES_COMBOFIND) )

    ' Process Windows messages(modal)
    function = pWindow->DoEvents( SW_SHOW )
    
    ' Delete the CWindow class manually allocated memory 
    delete pWindow

    function = 0
end function

