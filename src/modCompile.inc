''    tiko editor - Programmer's Code Editor for the FreeBASIC Compiler
''    Copyright (C) 2016-2026 Paul Squires, PlanetSquires Software
''
''    This program is free software: you can redistribute it and/or modify
''    it under the terms of the GNU General Public License as published by
''    the Free Software Foundation, either version 3 of the License, or
''    (at your option) any later version.
''
''    This program is distributed in the hope that it will be useful,
''    but WITHOUT any WARRANTY; without even the implied warranty of
''    MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See the
''    GNU General Public License for more details.

''
''
''   modCompile.inc
''
''   Code here handles the entire compiling process. It prepares the necessary
''   command line data to pass to the applicable 32 or 64 version of the FBC
''   compiler. Compile time errors are parsed through analyis of the log file
''   and presented to the user via the Compiler Results listview and the Compiler
''   Log File text box.
''
''

#include once "modCompile.bi"
#include once "modCompileErrors.bi"
#include once "frmUserTools.bi"
#include once "frmDebug.bi"
#include once "frmOutput.bi"

dim shared gCompile as COMPILE_TYPE

''
'' Main module that handles the entire compile process
''
function code_Compile( byval wID as long ) as boolean

    dim pDoc as clsDocument ptr
    
    dim wszTemp        as wstring * MAX_PATH 
    dim wszFileExe     as wstring * MAX_PATH
    dim wszIconCompile as DWSTRING
    dim wszCommand     as DWSTRING 
    dim wszParams      as DWSTRING
    dim sConsoleText   as string 
    
    dim as DWSTRING wExeCmd, wDQ, wsLogSt, wst
            
    dim as boolean fCompile32, fCompile64
    
    dim as long idxBuild, f, i, n, nCount
    
    wDQ = wchr(34) ' unicode double quotes
                                
    gCompile.wszFullCommandLine = ""
    gCompile.wszFullLogFile = ""
    gCompile.wszOutputMsg = ""
    gCompile.ResourceFile = ""
    gCompile.LinkModules = ""
    
    
    ' Indicate in the StatusBar that we have started to compile
    SetCompileStatusBarMessage( L(449, "Generating compiler files") & "...", 0 )
    

    ' Can only continue to compile if the primary source code file
    ' is not dirty and needs to be saved.
    if wID <> IDM_QUICKRUN then
        if gConfig.CompileAutosave then
            if OnCommand_FileSaveAll(HWND_FRMMAIN) then 
                SetCompileStatusBarMessage( "", 0 )
                return true  ' user cancelled save
            end if   
        end if
    end if
    
    ' Get the array index for the current selected build (project or document)
    idxBuild = frmBuildConfig_getActiveBuildIndex()
    if idxBuild = -1 then idxBuild = 0
    
    ' Perform some pre-compile checks to see if we should continue.
    gConfig.FBWINCompiler32 = ProcessFromCurdriveApp(gConfig.FBWINCompiler32)
    gConfig.FBWINCompiler64 = ProcessFromCurdriveApp(gConfig.FBWINCompiler64)
    if gConfig.Builds(idxBuild).Is32bit then
        fCompile32 = true: fCompile64 = false
        gCompile.CompilerPath = gConfig.FBWINcompiler32
    end if
    if gConfig.Builds(idxBuild).Is64bit then
        gCompile.CompilerPath = gConfig.FBWINcompiler64
        fCompile32 = false: fCompile64 = true
    end if

    ' Convert relative path to absolute path if needed.
    if AfxPathIsRelative(gCompile.CompilerPath) then
        gCompile.CompilerPath = AfxPathCombine(AfxGetExePathName, gCompile.CompilerPath)
    end if


    ' Check to see if the compiler exists
    if AfxFileExists(gCompile.CompilerPath) = 0 then 
        wszTemp = L(202,"Invalid defined compiler path.")
        wszTemp = wszTemp & vbcrlf & "Path: " & gCompile.CompilerPath
        SetCompileStatusBarMessage( "", 0 )
        MessageBox( HWND_FRMMAIN, wszTemp, L(201,"Error"), _
                        MB_OK Or MB_ICONINFORMATION Or MB_DEFBUTTON1 )
        function = false: exit function
    end if
    

    ' Set some compile flags depending on the type of compile requested.
    gCompile.CompileID = wID
    select case gCompile.CompileID
        case IDM_BUILDEXECUTE: gCompile.RunAfterCompile = true
        case IDM_QUICKRUN:     gCompile.RunAfterCompile = true
        case IDM_COMPILE:      gCompile.RunAfterCompile = false
    End select
    
    
    dim pDocMain as clsDocument ptr 
    if gApp.IsProjectActive then
        pDocMain = gApp.GetMainDocumentPtr()
        if pDocMain = 0 then
            SetCompileStatusBarMessage( "", 0 )
            MessageBox( HWND_FRMMAIN, L(208,"No Main file specified for the project."), L(201,"Error"), _
                            MB_OK Or MB_ICONINFORMATION Or MB_DEFBUTTON1 )
            function = false: exit function
        end if
    else
        pDocMain = gTTabCtl.GetActiveDocumentPtr()
    end if
    if pDocMain = 0 then 
        SetCompileStatusBarMessage( "", 0 )
        return 0
    end if
    
    ' Run any precompile tools
    for y as long = lbound(gConfig.Tools) to ubound(gConfig.Tools)
        if gConfig.Tools(y).Action = USERTOOL_ACTION_PRECOMPILE then
            frmUserTools_ExecuteUserTool(y)
        end if   
    next

    ' if this is a QuickRun then we need to copy the current source code to a temporary bas file
    ' and compile that bas file instead. 
    if gCompile.CompileID = IDM_QUICKRUN then  
        if AfxFileExists(pDocMain->DiskFilename) then
            gCompile.MainFolder = AfxStrPathname("PATH", pDocMain->DiskFilename)
        else    
            gCompile.MainFolder = AfxGetExePathName
        end if

        gCompile.MainFilename = gCompile.MainFolder & QUICKRUNBAS
        gCompile.MainName     = AfxStrPathname("NAME", gCompile.MainFilename)
        
        pDocMain->SaveTempFile( gCompile.MainFilename )

    else
        gCompile.MainFilename = pDocMain->DiskFilename
        gCompile.MainName     = AfxStrPathname("NAME", pDocMain->DiskFilename)
        gCompile.MainFolder   = AfxStrPathname("PATH", pDocMain->DiskFilename)
    end if
    
    gCompile.ResourceFile = ""    ' default that there is no resource
    gCompile.CompileFlags = gConfig.Builds(idxBuild).wszOptions
    
    ' If debugging, then ensure that we use the GCC compiler rather than GAS and
    ' also include the -g compile flag.
    if gCompile.CompileID = IDM_DEBUG_STARTDEBUGGING then
        ' Remove any -O optimization flags and add no inline flag.
        gCompile.CompileFlags = AfxStrRemove( gCompile.CompileFlags, " -Wc" )
        gCompile.CompileFlags = AfxStrRemove( gCompile.CompileFlags, " -O1" )
        gCompile.CompileFlags = AfxStrRemove( gCompile.CompileFlags, " -O2" )
        gCompile.CompileFlags = AfxStrRemove( gCompile.CompileFlags, " -O3" )
        gCompile.CompileFlags = AfxStrRemove( gCompile.CompileFlags, " -Os" )
        gCompile.CompileFlags = AfxStrRemove( gCompile.CompileFlags, " -Ofast" )
        ' If gcc already exists then no need to replace chosen backend. Only do
        ' the replacements if gcc is not found.
        if instr( gCompile.CompileFlags, " -gen gcc" ) = 0 then
            ' Replace llvm, gas, gas64 with gcc (ensure replacement string is same size as search string)
            ' Search for gas64 before gas because gas will match before gas64.
            gCompile.CompileFlags = AfxStrReplace( gCompile.CompileFlags, " -gen gas64", " -gen gcc  " )
            gCompile.CompileFlags = AfxStrReplace( gCompile.CompileFlags, " -gen gas", " -gen gcc" )
            gCompile.CompileFlags = AfxStrReplace( gCompile.CompileFlags, " -gen llvm", " -gen gcc " )
        end if
        gCompile.CompileFlags = gCompile.CompileFlags & " -g -exx -nostrip "
    end if

    ' Iterate the optional semi colon separated list of compiler include paths
    gCompile.CompileIncludes = ""
    dim as DWSTRING includePath
    dim as long numpaths = AfxStrParseCount(gConfig.CompilerIncludes, ";")
    for i as long = 1 to numpaths
        includePath = rtrim(AfxStrParse(gConfig.CompilerIncludes, i, ";"))
        if len(includePath) then 
            gCompile.CompileIncludes = gCompile.CompileIncludes + " -i " + chr(34) + includePath + chr(34)
        end if
    next

    if gApp.IsProjectActive then
        dim pDocResource as clsDocument ptr = gApp.GetResourceDocumentPtr()
        if pDocResource then gCompile.ResourceFile = pDocResource->DiskFilename

        gCompile.ObjFolder = gCompile.MainFolder & APPEXTENSION & "\"
        gCompile.ObjFolderShort = ".\" & APPEXTENSION & "\"

        if fCompile32 then 
            gCompile.ObjID = "32.o"
            gCompile.CompileFlags = gCompile.CompileFlags + " " + gApp.ProjectOther32 +" " + gCompile.CompileIncludes          
        end if
        if fCompile64 then 
            gCompile.ObjID = "64.o"
            gCompile.CompileFlags = gCompile.CompileFlags + " " + gApp.ProjectOther64 + " " + gCompile.CompileIncludes          
        end if   
        
        ' Make sure the folders exist
        SHCreateDirectory( 0, gCompile.ObjFolder )

    else
        ' No active project
        gCompile.CompileFlags = gCompile.CompileFlags + " " + gConfig.CompilerSwitches + " " + gCompile.CompileIncludes  
    end if


    ' Search main source code for any user embedded compile directives. These will override
    ' anything that was set at the default or project level.
    redim directives(any) as COMPILE_DIRECTIVES
    pDocMain->CompileDirectives(directives())
    
    for i as long = lbound(directives) to ubound(directives)
        select case directives(i).DirectiveFlag 
            case IDM_CONSOLE
                n = instr(gCompile.CompileFlags, " -S GUI ")
                if n then gCompile.CompileFlags = AfxStrDelete(gCompile.CompileFlags, n, 8)
                gCompile.CompileFlags = gCompile.CompileFlags + " -s console "
            case IDM_GUI
                n = instr(gCompile.CompileFlags, " -S CONSOLE ")
                if n then gCompile.CompileFlags = AfxStrDelete(gCompile.CompileFlags, n, 12)
                gCompile.CompileFlags = gCompile.CompileFlags + " -s gui "
            case IDM_RESOURCE
                gCompile.ResourceFile = directives(i).DirectiveText
                case IDM_LINKMODULES
                gCompile.LinkModules = gCompile.LinkModules & " " & directives(i).DirectiveText
        end select
    next
    gCompile.LinkModules = AddPathsToLinkModules(gCompile.LinkModules)


    ' Need to determine the output filename in order to search for any existing
    ' running process.
    gCompile.OutputFilename = gCompile.MainFolder & gCompile.MainName & ".exe"
    if instr(" " & ucase(gCompile.CompileFlags), " -DLL") then
        gCompile.OutputFilename = gCompile.MainFolder & gCompile.MainName & ".dll"
    end if
    if instr(" " & ucase(gCompile.CompileFlags), " -DYLIB") then
        gCompile.OutputFilename = gCompile.MainFolder & gCompile.MainName & ".dll"
    end if
    if instr(" " & ucase(gCompile.CompileFlags), " -LIB") then
        gCompile.OutputFilename = gCompile.MainFolder & "lib" & gCompile.MainName & ".a"
    end if

    if gCompile.CompileID = IDM_QUICKRUN then
        ' Delete the quick run exe when Application ends.
        gApp.wszQuickRunFilename = gCompile.OutputFilename
    end if    
        
    ' Need to test if the resulting application to be compiled is actually running
    ' in memory. This would cause the compile to fail.
    if IsProcessRunning(@gCompile.OutputFilename) then
        AfxDeleteFile( gCompile.OutputFilename )
        SetCompileStatusBarMessage( "", 0 )
        MessageBox( HWND_FRMMAIN, L(200,"Program running") & "...", L(201,"Error"), _
                        MB_OK Or MB_ICONINFORMATION Or MB_DEFBUTTON1 )
        function = false: exit function
    end if
        

    gApp.IsCompiling = true    

    dim as HCURSOR hCurSave = GetCursor()
    SetCursor( LoadCursor(0, IDC_WAIT) )
    pDoc = gTTabCtl.GetActiveDocumentPtr()
    if pDoc then SciExec( pDoc->hWindow(0), SCI_SETCURSOR, SC_CURSORWAIT, 0 )


    ' Change to the output code directory
    chdir gCompile.MainFolder
    
    gCompile.StartTime = timer
    

    ' if this is a project then we need to compile all of the modules first
    ' in order to create the necessary *.o object files
    if gApp.IsProjectActive then
        ' Determine if we are switching from Release builds to Debug builds. This means
        ' that any existing obj's would be invalid and will be forced to rebuild.
        ' Look for the "_debug_active.txt" filename.
        dim as DWSTRING wszDebugFilename = gCompile.ObjFolder & "_debug_active.txt"
        dim as boolean bForceRebuild = false
        dim as boolean bDebugFileExists = AfxFileExists( wszDebugFilename )
        if gCompile.CompileID = IDM_DEBUG_STARTDEBUGGING then
            ' Debug build
            bForceRebuild = iif( bDebugFileExists, false, true )
            ' Create the debug active file for later checks
            dim pStream as CTextStream   '(utf16)
            if pStream.Create( wszDebugFilename, true, true ) = S_OK then 
                pStream.WriteLine "-- DEBUG OBJECT FILES --"
            end if
            pStream.Close
        else
            ' Release builds
            if bDebugFileExists then bForceRebuild = true
            ' Remove the existing debug check filename
            AfxDeleteFile( wszDebugFilename )
        end if

        gCompile.CompileFlags = " " & gCompile.CompileFlags & " "
        dim as string g_flag = iif(instr(gCompile.CompileFlags, " -g "), " -g -nostrip ", "")
        dim as string e_flag = iif(instr(gCompile.CompileFlags, " -e "), " -e ", "")
        dim as string ex_flag = iif(instr(gCompile.CompileFlags, " -ex "), " -ex ", "")
        dim as string exx_flag = iif(instr(gCompile.CompileFlags, " -exx "), " -exx ", "")
        
        dim as long nFileCount   ' used to calculate when to fire an AfxDoEvents
        pDoc = gApp.pDocList
        do until pDoc = 0
            if pDoc->ProjectFileType = FILETYPE_MODULE then
                ' Get the base name of the file for constructing the object filename
                wszTemp = AfxStrPathname("NAME", pDoc->DiskFilename)
                wszTemp = gCompile.ObjFolderShort & wszTemp & gCompile.ObjID
                
                ' Compare the source code file datetime to the object. if the source code
                ' date time is greater then we need to recompile it, otherwise we will simply
                ' link to the existing object file.
                dim as boolean bRebuildModule = false
               
                dim as FILETIME ft1 = AfxGetFileLastWriteTime(pDoc->DiskFilename) ' source file
                dim as FILETIME ft2 = AfxGetFileLastWriteTime(wszTemp)  ' object file

                if (AfxFileTimeToVariantTime(ft1) > AfxFileTimeToVariantTime(ft2)) then bRebuildModule = true
                
                ' If rebuild is false then we still need to check any embedded #include files that
                ' may have changed since the document was parsed.
                dim pDocInclude as clsDocument ptr 
                pDocInclude = pDoc->pDocIncludeList
                do until pDocInclude = 0
                    ft1 = AfxGetFileLastWriteTime(pDocInclude->DiskFilename) ' current include file datetime
                    if AfxFileTimeToVariantTime(ft1) > AfxFileTimeToVariantTime(pDocInclude->DateFileTime) then 
                        bRebuildModule = true
                    end if    
                    pDocInclude->DateFileTime = ft1
                    pDocInclude = pDocInclude->pDocNext
                loop
                
                if (bRebuildModule = true) orelse (bForceRebuild = true) orelse (gCompile.CompileID = IDM_REBUILDALL)  then
                    nFileCount = nFileCount + 1
                    if (nFileCount mod 5) = 0 then AfxDoEvents
                    
                    ' Prepend with # so that spinner shows
                    wst = L(203, "Compiling") + "... " + AfxStrPathname("NAMEX", pDoc->DiskFilename) 
                    SetCompileStatusBarMessage( wst, 0 )
        
                    wszCommand = gCompile.CompilerPath
                    wszParams = g_flag & e_flag & ex_flag & exx_flag &  _
                                gCompile.CompileIncludes + " " + _
                                " -c -b " + wDQ + pDoc->DiskFilename + wDQ + _
                                " -v -o " + wDQ + wszTemp + wDQ 
                    RedirConsoleToFile( wszCommand, wszParams, sConsoleText )
                    gCompile.wszFullCommandLine = wszCommand & " " & wszParams
                    gCompile.wszFullLogFile = sConsoleText

                    ' Need to check to see if any errors occurred while compiling this
                    ' object file. if yes, then stop processing object files and display
                    ' the error.
                    if ParseLogForError(sConsoleText, false, gCompile.CompileID, fCompile64, true) then   ' error detected
                        gApp.IsCompiling = false
                        SetCursor( hCurSave )
                        ResetScintillaCursors()
                        return true
                    end if
                    sConsoleText = ""
                end if
            
            end if
            pDoc = pDoc->pDocNext
        loop
    end if

    
    ' Compile the Main file. if this is a project then we also need to link
    ' in all of the *.o object files.
    ' Per fxm post https://www.freebasic.net/forum/viewtopic.php?f=8&p=266126#p266126
    ' and https://www.freebasic.net/forum/viewtopic.php?f=3&t=28723&p=274431#p274431
    ' Do not specify file extension with -m parameter.
    ' So the main module file must be called twice in the command line:
    ' - after compile option '-m', but without specified extension,
    ' - and also like any module to compile, but there with its specified extension.
    'dim as DWSTRING wszMfile = wDQ + AfxStrPathName("PATH", gCompile.MainFilename) + AfxStrPathName("NAME", gCompile.MainFilename) + wDQ
    'dim as DWSTRING wszMfile = AfxStrPathName("NAME", gCompile.MainFilename) 
    'wszParams = "-m " + wszMfile + " " + wDQ + gCompile.MainFilename + wDQ 
    wszParams = "-m " + wDQ + gCompile.MainFilename + wDQ 


    if len(gCompile.LinkModules) then
        wszParams = wszParams + " " + gCompile.LinkModules
    end if

    if len(gCompile.ResourceFile) then  
        wszParams = wszParams + " " + wDQ + gCompile.ResourceFile + wDQ
    end if  
    
    
    ' Ensure verbose compiler message output
    wszParams = wszParams + " -v " + gCompile.CompileFlags 
    
    f = instr(wszParams, " -x ") 
    if f = 0 then
        wszParams = wszParams + " -x " + wDQ + gCompile.OutputFilename + wDQ
    else
        ' The ParseLogForError() function below will identify the correct
        ' filename for gCompile.OutputFilename based on the man file being linked.
    end if
    
    if gApp.IsProjectActive then
        pDoc = gApp.pDocList
        do until pDoc = 0
            if pDoc->ProjectFileType = FILETYPE_MODULE then
                ' Get the base name of the file for constructing the object filename
                wszTemp = AfxStrPathname("NAME", pDoc->DiskFilename)
                wszParams = wszParams + " " + gCompile.ObjFolderShort + wszTemp + gCompile.ObjID
            end if
            pDoc = pDoc->pDocNext
        loop
    end if

    ' Attempt to delete any existing output file so it will not exist should the compile fail.
    if AfxFileExists( gCompile.OutputFilename ) then
        AfxDeleteFile( gCompile.OutputFilename )
    end if

    ' Prepend with # so that spinner shows
    wst = "#" + L(203, "Compiling") + "... " + AfxStrPathname("NAMEX", gCompile.MainFilename) 
    SetCompileStatusBarMessage( wst, 0 )
    SetCursor( LoadCursor(0, IDC_WAIT) )

    sConsoleText = ""
    wszCommand = gCompile.CompilerPath
    
    dim as CompileThreadParams ctp
    ctp.wszExe = wszCommand
    ctp.wszCmdLine = wszParams
    ctp.sConsoleText = ""

    ' Do the compile in a separate thread so that the main thread GUI can display
    ' the spinner in the statusbar.
    gCompile.bCompileThreadComplete = false
    dim as any ptr pThread = ThreadCreate( @compile_thread, @ctp )
    
    do until gCompile.bCompileThreadComplete = true
        AfxDoEvents()
    loop    
    
    gCompile.wszFullCommandLine = wszCommand & " " & wszParams
    gCompile.wszFullLogFile = ctp.sConsoleText
    sConsoleText = ctp.sConsoleText
                

    ' Attempt to fix the random problem whereby the spinning mouse wait cursor is not reset
    ' to an arrow. It seems to happen in random cases whereby an error is thrown and a new 
    ' document is loaded to position to the error line. Very hard to reproduce. We will manually
    ' reset all Scintilla cursors here for all open documents. Maybe this will help.
    SetCursor( hCurSave )
    ResetScintillaCursors()
    
    gCompile.EndTime = timer
    gCompile.SystemTime = AfxSystemSystemTime 

    ' if this was a QuickRun then delete the temporary code file that was created.
    if gCompile.CompileID = IDM_QUICKRUN then 
        AfxDeleteFile( gCompile.MainFilename )
    end if    
    
    gApp.IsCompiling = false

    if ParseLogForError(sConsoleText, true, gCompile.CompileID, fCompile64, false) = true then 
        ' Error was found. Editor has now been set to the error position. Nothing
        ' more we can do now but exit out. 
        ' Make sure gApp.IsCompiling = false before returning
    else
        ' Run any postcompile tools
        for y as long = lbound(gConfig.Tools) to ubound(gConfig.Tools)
            if gConfig.Tools(y).Action = USERTOOL_ACTION_POSTCOMPILE then
            frmUserTools_ExecuteUserTool(y)
            end if   
        next
        
        ' if gCompile.OutputFilename is a relative filename then convert it to full filename.
        gCompile.OutputFilename = AfxStrReplace( gCompile.OutputFilename, "/", "\" )
        if AfxPathIsRelative( gCompile.OutputFilename ) then 
            gCompile.OutputFilename = AfxPathCombine( gCompile.MainFolder, gCompile.OutputFilename )
        end if

        if gCompile.CompileID = IDM_DEBUG_STARTDEBUGGING then
           frmDebug_Show( _
                HWND_FRMMAIN, _
                gCompile.OutputFilename, _
                iif( gApp.IsProjectActive, gApp.ProjectCommandLine, gApp.wszCommandLine ) _
                )
        end if
        
        if gCompile.RunAfterCompile then 
            RunEXE( _
                pDocMain, _
                gCompile.OutputFilename,    _
                iif( gApp.IsProjectActive, gApp.ProjectCommandLine, gApp.wszCommandLine ) _
                )
        end if
    
    end if

    function = true   ' successful
End function


''
''
''
function AddPathsToLinkModules( byval modules as DWSTRING ) as DWSTRING
    ' SEARCH ORDER
    ' (1) Current folder
    ' (2) User defined Include paths
    ' (3) \inc folder for the selected compiler toolchain

    dim as DWSTRING wszResult  ' the final fully path qualified list of space separated module filenames
    dim as DWSTRING wszTemp
    
    dim as DWSTRING wszCurrentFolder = AfxStrPathname("PATH", gCompile.MainFilename)
    dim as DWSTRING wszIconCompilerIncFolder = AfxStrPathname("PATH", gCompile.CompilerPath) & "inc\"
    
    dim as DWSTRING wszLinkModules = AfxStrShrink(gCompile.LinkModules)  
    
    dim as long nummodules = AfxStrParseCount(wszLinkModules, " ")
    for i as long = 1 to nummodules
        dim as DWSTRING modulename = trim(AfxStrParse(wszLinkModules, i, " "))
        ' Remove any enclosing double quotes from the filename
        modulename = AfxStrRemove(modulename, chr(34))

        if len(modulename) = 0 then continue for

        ' (1) Current folder
        wszTemp = wszCurrentFolder & modulename
        if AfxFileExists(wszTemp) then
            wszResult = wszResult & chr(34) & wszTemp & chr(34) & " "
            continue for
        end if
    
        ' (2) User defined Include paths
        ' Iterate the optional semi colon separated list of compiler include paths
        gCompile.CompileIncludes = ""
        dim as DWSTRING includePath
        dim as long numpaths = AfxStrParseCount(gConfig.CompilerIncludes, ";")
        for i as long = 1 to numpaths
            includePath = rtrim(AfxStrParse(gConfig.CompilerIncludes, i, ";"))
            ' Remove any enclosing double quotes from the includepath
            includePath = AfxStrRemove(includePath, chr(34)) & "\"   ' ensure trailing backslash
            if len(includePath) then 
            wszTemp = includePath & modulename
            if AfxFileExists(wszTemp) then
                wszResult = wszResult & chr(34) & wszTemp & chr(34) & " "
                continue for: continue for
            end if
            end if
        next
    
        ' (3) \inc folder for the selected compiler toolchain
        wszTemp = wszIconCompilerIncFolder & modulename
        if AfxFileExists(wszTemp) then
            wszResult = wszResult & chr(34) & wszTemp & chr(34) & " "
            continue for
        end if
    next
    
    function = trim(wszResult)
end function

