''    tiko editor - Programmer's Code Editor for the FreeBASIC Compiler
''    Copyright (C) 2016-2025 Paul Squires, PlanetSquires Software
''
''    This program is free software: you can redistribute it and/or modify
''    it under the terms of the GNU General Public License as published by
''    the Free Software Foundation, either version 3 of the License, or
''    (at your option) any later version.
''
''    This program is distributed in the hope that it will be useful,
''    but withOUT any WARRANTY; without even the implied warranty of
''    MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See the
''    GNU General Public License for more details.

''
''
''   modCompileErrors.inc
''

#include once "modCompile.bi"
#include once "modCompileErrors.bi"
#include once "frmListView.bi"


''
''  Set the statusbar text and icon for a good/bad compile
''
function SetCompileStatusBarMessage( _
            byref wszText as wstring, _
            byval hIconCompile as long _
            ) as LRESULT
    gApp.wszPanelText = wszText
    gApp.hIconPanel = hIconCompile
    frmMain_SetStatusbar
    function = 0
end function


''
''  Reset all Scintilla editing cursors
''
function ResetScintillaCursors() as long
    dim as long nCount = gTTabCtl.GetItemCount 

    for i as long = 0 to nCount - 1
        if gTTabCtl.IsSafeIndex(i) = false then continue for
        dim as clsDocument ptr pDoc = gTTabCtl.tabs(i).pDoc
        if pDoc then 
            SciExec( pDoc->hWindow(0), SCI_SETCURSOR, SC_CURSORNORMAL, 0 )
            SciExec( pDoc->hWindow(1), SCI_SETCURSOR, SC_CURSORNORMAL, 0 )
        end if
    next
    function = 0
end function


'' July 2017, attempted to capture STDERR output from a running FB compiled
'' program in order to capture runtime errors. This code works okay on Windows 10
'' but does not PRINT on Windows 7. Also, dkl posted in FB forum that FB prints
'' to STDOUT rather than STDERR. This is too bad.
''
''
function RedirConsoleToFile( _
            byref wszExe as wstring, _
            byref wszCmdLine as wstring, _
            byref sConsoleText as string _
            ) as long

    ' From the MinGW "Getting Started" guide:
    '    MinGW may have problems with paths containing spaces, and if not, usually 
    '    other programs used with MinGW will experience problems with such paths. 
    '    Thus, we strongly recommend that you do not install MinGW in any location 
    '    with spaces in the path name reference; i.e. you should avoid installing 
    '    into any subdirectory of "Program Files" or "My Documents", or the like.
    if instr(wszExe, " ") then
        AfxMsg( "Compile failed (CreateChildProcess)." & vbcrlf & _
                "Please install editor into a folder without spaces." )
        exit function
    end if

    ' Create the child process and read from its standard output
    dim ProcessInfo as PROCESS_INFORMATION
    dim StartupInf  as STARTUPINFO

    ' continue on with the newer CreateProcess compile approach.
    dim SecurityAttribute as SECURITY_ATTRIBUTES
    dim hChildStdOutRead  as PHANDLE
    dim hChildStdOutWrite as PHANDLE
    dim dwReadBytes       as long
    dim sBuffer as string * 4096
    
    ' Set the bInheritHandle flag so pipe handles are inherited.
    SecurityAttribute.nLength              = sizeof(SECURITY_ATTRIBUTES)
    SecurityAttribute.bInheritHandle       = true
    SecurityAttribute.lpSecurityDescriptor = null

    ' Create a pipe for the child process's STDOUT.
    if CreatePipe( @hChildStdOutRead, @hChildStdOutWrite, @SecurityAttribute, byval 0 ) = false then
        '? "error creating pipe"
    else
        StartupInf.cb         = sizeof(STARTUPINFO)
        GetStartupInfo(@StartupInf )  
        StartupInf.hStdError  = hChildStdOutWrite   
        StartupInf.hStdOutput = hChildStdOutWrite  
        StartupInf.dwFlags    = STARTF_USESTDHANDLES or STARTF_USESHOWWINDOW
        StartupInf.wShowWindow = SW_HIDE
        
        ' This call to CreateProcessW will succeed in all cases except for the one
        ' where there are spaces in wszFullExe because once I wrap the string in double
        ' quotes then the call to CreateProcessW fails.

        dim errCode as long 
        errCode = CreateProcessW( _
                    wszExe,  _          ' Create the child process.
                    wszCmdLine, _       ' Command line
                    byval 0,     _      ' Process security attributes
                    byval 0,     _      ' Primary thread security attributes
                    true,        _      ' Handles are inherited
                    byval 0,     _      ' Creation flags  
                    byval 0,     _      ' Use parent's environment
                    byval 0,     _      ' Use parent's current directory
                    @StartupInf,  _     ' STARTUPINFO pointer
                    @ProcessInfo) 
        
        if errCode <> 0 then            

            CloseHandle( hChildStdOutWrite ) ' to avoid ReadFile hanging at the end.
            do
                if ReadFile( hChildStdOutRead, byval varptr(sBuffer), 4096, @dwReadBytes, byval 0 ) = false then 
                    '? "ERROR ReadFile', "GetLastError: "; GetLastError
                    exit do
                end if  
                sConsoleText = sConsoleText & left(sBuffer, dwReadBytes)
                '(at this stage we could SAVE the buffer that we've read from the child to a file, but 
                ' thats an extra ReadFile+WriteFile compared to the direct-to-hFile method)
            loop
            
        else
            '? "CreateChildProcess failed"      
            if instr( wszExe, " " ) then
                AfxMsg( "CreateChildProcess failed. Install editor into folder without spaces." )
            end if    
            if hChildStdOutRead  then CloseHandle( hChildStdOutRead )
            if hChildStdOutWrite then CloseHandle( hChildStdOutWrite )
            exit function
        end if
            
    end if

    ' Close handles to the child process and its primary thread.
    ' Some applications might keep these handles to monitor the status 
    ' of the child process, for example.
    if ProcessInfo.hProcess then CloseHandle( ProcessInfo.hProcess )
    if ProcessInfo.hThread  then CloseHandle( ProcessInfo.hThread )
    if hChildStdOutRead     then CloseHandle( hChildStdOutRead )

    function = 0
end function


''
''
function RunEXE( _
            byval pDocMain as clsDocument ptr, _
            byref wszFileExe as CWSTR, _
            byref wszParam as CWSTR _
            ) as long
                            
    dim as CWSTR wszPath = AfxStrPathname("PATH", wszFileExe)
    dim as CWSTR wszBatchFile = RUNBATCHFILE
    
    ' if option is specified to launch command window prior to running the
    ' compiled program then we do so by executing a shell to a batch file.
    ' This allows being able to see any runtime errors that might be thrown.
    ' Otherwise, simple shell to the program.
    if gConfig.RunViaCommandWindow then
        AfxDeleteFile( wszBatchFile )
        dim pStream as CTextStream
        if pStream.Create(wszBatchFile) = S_OK then
            pStream.WriteLine "@echo off"
            pStream.WriteLine left(wszPath, 2)     ' ensure on correct drive
            pStream.WriteLine "cd " & chr(34) & wszPath & chr(34)   ' change to correct folder
            pStream.WriteLine chr(34) & wszFileExe & chr(34) & " " & wszParam
            pStream.WriteLine "pause"
        end if
        pStream.Close
        wszFileExe = wszBatchFile
        wszParam = ""
    end if
    

    dim ShExecInfo as SHELLEXECUTEINFOW  

    ' Run the EXE
    with ShExecInfo
        .cbSize       = len(SHELLEXECUTEINFOW)
        .fMask        = SEE_MASK_NOCLOSEPROCESS
        .hwnd         = 0
        .lpVerb       = null
        .lpFile       = wszFileExe
        .lpParameters = wszParam   
        .lpDirectory  = 0
        .nShow        = SW_SHOW
        .hInstApp     = 0 
    end with
    ShellExecuteEx(@ShExecInfo)

    function = 0
end function


' ========================================================================================
' Set the cursor to the error position based on the selected line in:
' (1) Compiler Results
' (2) Search Results
' (3) TODO
' ========================================================================================
function SetDocumentErrorPosition( _
            byval hLV as HWND, _
            byval wID as long _
            ) as long

    dim wszErrorLine as wstring * MAX_PATH
    dim wszErrorFile as wstring * MAX_PATH
    
    dim as long nCurSel = frmListView_GetSelection(hLV)
    if nCurSel < 0 then return 0 
    
    dim pDoc as clsDocument ptr 

    ' Get the line number and filename of the selected item
    wszErrorLine = frmListView_GetItemText(hLV, nCurSel, 1)
    wszErrorFile = frmListView_GetItemText(hLV, nCurSel, 2)
    dim as long nLineNum = val(wszErrorLine) - 1   ' because visually the editor is one based line numbers

    ' if we are doing a QuickRun then it must be on the currently loaded
    ' and active file in the editor, therefore simply use that pDoc.
    if wID = IDM_QUICKRUN then
        pDoc = gTTabCtl.GetActiveDocumentPtr()
        if pDoc then wszErrorFile = pDoc->DiskFilename 
    end if
    
    pDoc = OpenSelectedDocument( wszErrorFile, "", nLineNum )
    
    function = 0
end function


''
''
function SetLogFileTextbox() as long
    
    ' Construct the text that will be displayed:
    ' - FBC version, exe name, file size, compile time
    ' - raw log file output
    ' - compile command line used
    dim as CWSTR wszText
    
    if len(gCompile.wszOutputMsg) then 
        gCompile.wszOutputMsg = gCompile.wszOutputMsg + vbcrlf
    end if
    wszText = _
        gCompile.wszOutputMsg + _
        L(178,"Command Line") + ": " + vbcrlf + _
        gCompile.wszFullCommandLine + vbcrlf + vbcrlf + _
        gCompile.wszFullLogFile 
                
    AfxSetWindowText( GetDlgItem( HWND_FRMOUTPUT, IDC_FRMOUTPUT_TXTLOGFILE), wszText )

    ' Reset the type parameters so subsequent compiles will not append
    function = 0
end function


''
''
function ParseLogForError( _
            byref wsLogSt as CWSTR, _
            byval bAllowSuccessMessage as boolean, _
            byval wID as long, _
            byval fCompile64 as boolean, _
            byval fCompilingObjFiles as boolean _
            ) as boolean
    
    ' returns true if error has been detected. This signals to the calling code
    ' that we can break out of performing any further compiles (eg. modules).
    dim wszTemp as wstring * MAX_PATH 

    dim as long Parenthesis_Start, Parenthesis_End, Error_Start       
    dim as long i, NumLines, nextLine, r, nCount, nListViewLine
    dim as long NumWarnings, NumErrors, NumDirectives, IsError, IsWarning
    dim as long nFirstErrorLine = -1
    dim as HWND hLV
    dim as CWSTR wDQ, wst1, wst2, wst3, wst, wst_ucase, wszOutputMsg, wszText        
    dim as boolean fGoodCompile

    wDQ = wchr(34) ' unicode double quotes

    hLV = HWND_FRMOUTPUT_LVRESULTS
    frmListView_DeleteAllItems( hLV )
    
    ' On some Windows systems with tight security policies, the CreateChildProcess used
    ' by the sub RedirConsoleToFile will fail. This seems to happen mostly when trying
    ' to compile using the FB 64 bit compiler on a 32-bit version of Windows. for this
    ' reason we will do a manual check here rather than relying on detecting the error
    ' through the log file string.
    if fCompile64 then   ' trying to compile a 64-bit program
        if AfxWindowsBitness() <> 64 then  ' Windows is not 64 bit
            wsLogSt = "This version of the FreeBASIC compiler is not compatible with the version " & _
                    "of Windows you're running. Check your computer's system information to see " & _
                    "whether you need a x86 (32-bit) or x64 (64-bit) version of the program, and " & _
                    "then contact the software publisher."  
            gCompile.wszFullLogFile = wsLogSt
        end if
    end if

    dim as boolean bReadingCompileOutput = false
    
    ' Parse the log string.
    NumLines = AfxStrParseCount( wsLogSt, vbCrLf)
    
    for nextLine = 1 to NumLines                   
    
        wst = trim(AfxStrParse(wsLogSt, nextLine, vbCrLf))                 
        wst_ucase = ucase(wst)
        
        ' Deal with the situation where we might be trying to compile a 64-bit application
        ' from a 32-bit operating system.
        if left(wst_ucase, 16) = "THIS VERSION OF " then
            fGoodCompile = false
            wszText = "" & chr(9) & "0" & chr(9) & "" & chr(9) & "compiling FAILED: Windows not 64-bit (refer to log file)"
            frmListView_AddString( hLV, wszText )
            wszOutputMsg = wsLogSt: exit For
            exit for
        end if   

        ' Save the FB version and copyright information. 
        if left(wst_ucase, 19) = "FREEBASIC COMPILER " then
            fGoodCompile = true
            wszOutputMsg = wszOutputMsg & wst & vbCrLf: continue For
        end if        
        if left(wst_ucase, 13) = "COPYRIGHT (C)" then
            fGoodCompile = true
            wszOutputMsg = wszOutputMsg & wst & vbCrLf: continue For
        end if        
        
        ' Check to see if an error occurred in compiling a resource script.
        ' if there was a bad source name passed to the compiler (for 
        ' example, missing .rc file), then the output at the end of the
        ' log file is like the following:
        '
        ' Error!
        ' Could Not Open source file (p.RC)
        ' OBJ file Not made
        ' compiling resource FAILED: Error Code 1
        '
        ' Very sorry, but GoRC had a problem.
                                            
        ' Check to see if linking failed
        if (left(wst_ucase, 6) = "ERROR!") or _
            (left(wst_ucase, 34) = "VERY SORRY, BUT GORC HAD A PROBLEM") then
            wszText = "" & chr(9) & "0" & chr(9) & "" & chr(9) & "compiling resource FAILED: Error Code 1 (refer to log file)"
            frmListView_AddString( hLV, wszText )
            NumErrors = NumErrors + 1
        elseif (left(wst_ucase, 5) = "ERROR") then
            wszText = "" & chr(9) & "0" & chr(9) & "" & chr(9) & "compiling FAILED: Error Code 1 (refer to log file)"
            frmListView_AddString( hLV, wszText )
            NumErrors = NumErrors + 1
        elseif (left(wst_ucase, 19) = "COMPILING C FAILED:") then
            wszText = "" & chr(9) & "0" & chr(9) & "" & chr(9) & "compiling C FAILED: Error Code 1 (refer to log file)"
            frmListView_AddString( hLV, wszText )
            NumErrors = NumErrors + 1
        end if
        
        if instr(wst_ucase, "LINKING FAILED:") then 
            wszText = "" & chr(9) & "0" & chr(9) & "" & chr(9) & wst & " (refer to log file)"
            frmListView_AddString( hLV, wszText )
            NumErrors = NumErrors + 1
        end if
    
    
        ' Check for the "linking: " line because that line identifies the actual output filename being created
        if left(wst_ucase, 9) = "LINKING: " then 
            i = instr(wst, " -o ")
            if i then
            wszTemp = mid(wst, i+4)
            i = instr(wszTemp, wDQ & " ")
            if i then gCompile.OutputFilename = AfxStrRemove(left(wszTemp, i), wDQ)
            end if      
        end if
        
        ' Determine if we are reading any lines in the log file that appear after the "compiling: " line
        ' but before the "assembling: ". Anything there is data output by #print preprocessor statements.
        if left(wst_ucase, 11) = "COMPILING: " then 
            bReadingCompileOutput = true
            continue for
        elseif left(wst_ucase, 13) = "COMPILING C: " then 
            bReadingCompileOutput = true
            continue for
        elseif left(wst_ucase, 12) = "ASSEMBLING: " then 
            bReadingCompileOutput = false
        elseif left(wst_ucase, 14) = "COMPILING RC: " then 
            bReadingCompileOutput = false
        elseif left(wst_ucase, 9) = "LINKING: " then 
            bReadingCompileOutput = false
        end if

        if bReadingCompileOutput then

            if len(wst) = 0 then continue for

            ' Check for any compiler warnings
            Error_Start = 0
            IsWarning = instr(wst_ucase, ") WARNING ")
            if IsWarning then Error_Start = IsWarning
            IsError   = instr(wst_ucase, ") ERROR ") 
            if IsError then Error_Start = IsError
            
            if (Error_Start > 0) then 
                'sample warning message
                'c:\freebasic\test.bas(1394) warning 1(1): Passing scalar as pointer, at parameter 2 (hwndOldFocus) of ONSETFOCUS()
                'sample error message
                'c:\freebasic\test.bas(17) error 41: Variable not declared, kjljjada in 'kjljjada Error'

                ' Determine the line number. Error_Start variable holds the position of the closing
                ' parenthesis of the line number. We simply need to reverse search from there for the
                ' opening parenthesis.
                ' 2018-08-29: Code updated to handle case of embedded parenthesis in file name
                Parenthesis_end   = Error_Start
                Parenthesis_Start = instrrev(wst, "(", Parenthesis_End)
                
                if (Parenthesis_Start < Parenthesis_End) andalso _
                    (Parenthesis_end <= Error_Start) then
            
                    wst1 = left(wst, Parenthesis_Start-1)   ' filename
                    wst2 = mid( wst, Parenthesis_Start + 1, Parenthesis_end - Parenthesis_Start - 1)  ' line# 
                    wst3 = mid( wst, Error_Start + 1)  ' error message

                    wszText = "" & chr(9) & wst2 & chr(9) & wst1 & chr(9) & wst3
                    frmListView_AddString( hLV, wszText )
                    
                    if IsWarning then 
                        NumWarnings = NumWarnings + 1
                    elseif IsError then
                        if nFirstErrorLine = -1 then
                            nFirstErrorLine = NumWarnings + NumErrors
                        end if
                        NumErrors = NumErrors + 1
                    end if            
                end if

            else
                wszText = "" & chr(9) & "" & chr(9) & "" & chr(9) & wst
                frmListView_AddString( hLV, wszText )
                NumDirectives = NumDirectives + 1
            end if

        end if
    
        nListViewLine = NumWarnings + NumErrors + NumDirectives
    next
    
    ' if there were no errors but the fGoodCompile flag was not set to true then the log file
    ' did not contain the required FB copyright notice. Something must have went wrong, like trying
    ' to call the 64 bit compiler using a 32 bit operating system. Show the message to the user via
    ' the Output window (log file).
    if fGoodCompile = false then NumErrors = NumErrors + 1

    dim as CWSTR wszIconCompileMsg

    ' if the EXE output file was never created then throw an error
    if fCompilingObjFiles = false then
        if (NumWarnings = 0) andalso (NumErrors = 0) then
            if Filelen(gCompile.OutputFilename) = 0 then 
                NumErrors = NumErrors + 1
            end if
        end if
    end if
    
    ' In all cases where warnings and/or errors exist, we will show the Compiler Results listview
    if (NumWarnings > 0) orelse (NumErrors > 0) orelse (NumDirectives > 0) then
    
        wszIconCompileMsg = L(193, "Errors")   & " " & NumErrors   & "  " & _
                        L(192, "Warnings") & " " & NumWarnings & _
                        "  [" & _
                        AfxLocalDateStr( "yyyy-MM-dd" ) & "  " & _
                        AfxLocalTimeStr( "hh:mm:ss" ) & "]"
        gCompile.wszOutputMsg = L(229,"Failed Compile")  & " (" & wszIconCompileMsg & ")" & vbcrlf
        SetCompileStatusBarMessage( wszIconCompileMsg, ghIconBad )
       
        ' only beep on errors
        if NumErrors > 0 then MessageBeep(MB_ICONWARNING)
        
        ' Position the Compiler Log to the first error/warning
        frmListView_DeleteBlankFirstLine( HWND_FRMOUTPUT_LVRESULTS )
        frmListView_SelectItem( hLV, 0 )
        
        ' if fGoodCompile is false then something unusual occurred so better show the log file by default
        if fGoodCompile = false then
            frmOutput_PositionWindows
        end if
      
        ' if the Search Results, TODO, Notes tab is active then reposition to 
        ' the first tab for error listview
        select case gOutputTabsCurSel 
            case 1, 2, 3, 4
            gOutputTabsCurSel = 0
            frmOutput_PositionWindows
        end select
        
        ' Only retore the Output window if Errors exist. Warnings only will not trigger
        ' the Output window to open but the user can see how many warnings exist via the
        ' statusbar results message and then they can manually open the Output window
        ' to view the warning message (simply clicking on the statusbar message should
        ' do that).
        if NumErrors > 0 then frmOutput_RestorePanel()
        
        ' Set to error line position only after all windows have been shown and resized
        SetDocumentErrorPosition(hLV, wID)
    end if
    
    if (NumErrors = 0) andalso (bAllowSuccessMessage = true) then 
        ' we are not compiling modules
        dim as long nFileSize = AfxGetFileSize(gCompile.OutputFilename)
        wszIconCompileMsg = L(193, "Errors") & " " & NumErrors & "  " & _
                        L(192, "Warnings") & " " & NumWarnings & _
                        "  [ " & AfxStrPathname("NAMEX", gCompile.OutputFilename) & "  " & _
                        rtrim(AfxStrFormatKBSize(nFileSize)) & " (" & _
                        nFileSize & " " & L(199,"bytes") & ") ]"
        SetCompileStatusBarMessage( wszIconCompileMsg, ghIconGood )
        
        if gConfig.DisableCompileBeep = false then MessageBeep(MB_OK)
       
        gCompile.wszOutputMsg = _   ' this gets output to the Output window
            L(228,"Successful Compile")  & " (" & _
            L(193,"Errors")              & " " & NumErrors & " " & _
            L(192,"Warnings")            & " " & NumWarnings & ")" & vbcrlf & vbcrlf & _
            L(194,"Primary Source:")     & " " & gCompile.MainFilename & vbCrLf & _
            L(195,"Target Compilation:") & " " & gCompile.OutputFilename & " (" & _
                                    rtrim(AfxStrFormatKBSize(nFileSize)) & ", " & _
                                    nFileSize & " " & L(199,"bytes") & ")" & vbcrlf & _
            L(196,"Compile Time:")       & " " & format(gCompile.EndTime-gCompile.StartTime, "###0.0") & _
                                    " " & L(198,"seconds") & " (" & _
                                    AfxSystemTimeToDateStr( gCompile.SystemTime, "yyyy-MM-dd" ) & " " & _
                                    AfxSystemTimeToTimeStr( gCompile.SystemTime, "hh:mm:ss" ) & ")" & vbcrlf
    end if


    ' Update the log file text box in the frmOutput window
    SetLogFileTextbox

    ' if Errors have occurred then return true. We will allow processing
    ' to continue if only Warnings occurred.
    ' There were errors then do not allow running the EXE (warnings are okay)
    if NumErrors > 0 then 
        gCompile.RunAfterCompile = false 
        return true
    end if

    
    function = false
end function


