' ========================================================================================
' tiko editor 
' Windows FreeBASIC Editor (Windows 64 bit)
' Paul Squires (2016-2025)
' ========================================================================================

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


#define UNICODE
#define _WIN32_WINNT &h0602  

#include once "windows.bi"
#include once "vbcompat.bi"
#include once "win\shobjidl.bi"
#include once "win\TlHelp32.bi"
#include once "Afx\CWindow.inc"
#include once "Afx\AfxFile.inc"
#include once "Afx\AfxRichEdit.inc"
#include once "Afx\AfxGdiplus.inc"
#include once "Afx\AfxCom.inc" 
#include once "Afx\CImageCtx.inc"

using Afx


#define APPNAME        wstr("Tiko Editor")
#define APPNAMESHORT   wstr("Tiko")
#define APPCLASSNAME   wstr("tiko_editor_class")
#define APPVERSION     wstr("1.0.4") 
#define APPEXTENSION   wstr(".tiko") 
#define APPBITS wstr(" (64-bit)")

#define APPCOPYRIGHT   wstr("Paul Squires, PlanetSquires Software, Copyright (C) 2016-2025") 
dim shared as CWSTR gwszDefaultToolchain = "FreeBASIC-1.10.1-winlibs-gcc-9.3.0"

#include once "modScintilla.bi"
#include once "modDeclares.bi"         

#include once "clsDocument.bi"
#include once "clsTopTabCtl.bi"
#include once "clsDB2.bi"
#include once "clsConfig.bi"
#include once "clsApp.bi"

'  Global classes
dim shared gApp     as clsApp
dim shared gConfig  as clsConfig
dim shared gTTabCtl as clsTopTabCtl


#include once "clsDB2.inc"
#include once "clsConfig.inc"
#include once "modThemes.inc"
#include once "modRoutines.inc"
#include once "modParser.inc"
#include once "clsDocument.inc"
#include once "clsApp.inc"
#include once "clsTopTabCtl.inc"
#include once "modAutoInsert.inc"
#include once "modCompile.inc"
#include once "modCompileErrors.inc"
#include once "modMenus.inc"
#include once "modCodetips.inc"
#include once "modMenuDefinitions.inc"
#include once "modMRU.inc"

#include once "frmAbout.inc" 
#include once "frmPopupMenu.inc"
#include once "frmTopTabs.inc"
#include once "frmMenuBar.inc"
#include once "frmStatusBar.inc"
#include once "frmPanelVScroll.inc" 
#include once "frmEditorHScroll.inc" 
#include once "frmEditorVScroll.inc" 
#include once "frmPanel.inc" 
#include once "frmPanelMenu.inc" 
#include once "frmExplorer.inc" 
#include once "frmBookmarks.inc" 
#include once "frmFunctions.inc" 
#include once "frmKeyboardEdit.inc" 
#include once "frmKeyboard.inc" 
#include once "frmBuildConfig.inc" 
#include once "frmOutput.inc" 
#include once "frmOptionsGeneral.inc"
#include once "frmOptionsEditor.inc"
#include once "frmOptionsEditor2.inc"
#include once "frmOptionsColors.inc"
#include once "frmOptionsCompiler.inc"
#include once "frmOptionsLocal.inc"
#include once "frmOptionsKeywords.inc"
#include once "frmOptionsKeywordsWinApi.inc"
#include once "frmOptions.inc"
#include once "frmGoto.inc"
#include once "frmCommandLine.inc"
#include once "frmFindInFiles.inc"
#include once "frmFindReplace.inc"
#include once "frmProjectOptions.inc"
#include once "frmMainOnCommand.inc"
#include once "frmMainOnNotify.inc"
#include once "frmUserTools.inc"
#include once "modMsgPump.inc"
#include once "frmMainFile.inc"
#include once "frmMainEdit.inc"
#include once "frmMainSearch.inc"
#include once "frmMainView.inc"
#include once "frmMainProject.inc"
#include once "frmMainCompile.inc"
#include once "frmMain.inc"


' ========================================================================================
' WinMain
' ========================================================================================
function WinMain( _
            byval hInstance     as HINSTANCE, _
            byval hPrevInstance as HINSTANCE, _
            byval szCmdLine     as zstring ptr, _
            byval nCmdShow      as long _
            ) as long


    ' Load configuration files 
    gConfig.LoadConfigFile()
    gConfig.LoadKeywords()

    
    ' Attempt to load the english localization file. This is necessary because
    ' any non-english localization file will have missing entries filled by the
    ' english version.
    dim as CWSTR wszLocalizationFile
    wszLocalizationFile = AfxGetExePathName + wstr("settings\languages\english.lang")
    if LoadLocalizationFile(wszLocalizationFile, true) = false Then
        MessageBox( 0, _
                    "English Localization file could not be loaded. Aborting application." + vbcrlf + _
                    wszLocalizationFile, _
                    "Error", _
                    MB_OK or MB_ICONWARNING or MB_DEFBUTTON1 or MB_APPLMODAL )
        return 1
    end if
    
    
    ' Load the selected localization file
    wszLocalizationFile = AfxGetExePathName + "settings\languages\" + gConfig.LocalizationFile
    if LoadLocalizationFile(wszLocalizationFile, false) = false then
        MessageBox( 0, _
                    "Localization file could not be loaded." + vbcrlf + _
                    wszLocalizationFile, _
                    "Error", _
                    MB_OK or MB_ICONWARNING or MB_DEFBUTTON1 or MB_APPLMODAL )
        return 1
    end if
    
    
    ' Load the Segoe Fluent Icons ttf file that is used for displaying the various
    ' icons used within the editor.
    dim as CWSTR wszFontFile 
    wszFontFile = AfxGetExePathName + "SegoeFluentIcons.ttf"
    if AddFontResourceEx(wszFontFile.vptr, FR_PRIVATE, NULL) = 0 then
        MessageBox( 0, _
                    "Unable to load application font 'SegoeFluentIcons.ttf'. Aborting application." , _
                    "Error", _
                    MB_OK or MB_ICONWARNING or MB_DEFBUTTON1 or MB_APPLMODAL )
        return 1
    end if


    ' Load default Explorer Categories should none exist. Need to do it here
    ' rather than from within Config because the localization file must be 
    ' loaded first.
    gConfig.SetCategoryDefaults()


    ' Check for previous instance 
    if gConfig.MultipleInstances = false Then
        dim as HWND hWindow = FindWindow(APPCLASSNAME, 0)
        if hWindow then
            SetForegroundWindow(hWindow)
            ' Send the command line to the original editor to be processed
            dim as CWSTR wszPath 
            dim as CWSTR wszArg  
            dim as CWSTR wszSendString  

            dim as long i = 1
            do
                wszArg = AfxCommand(i)
                if len(wszArg) = 0 then exit do
                
                ' Remove any double quotes from the argument.
                wszPath = AfxStrRemove( wszArg, wchr(34) )
                
                ' if no path exists for the file then add the current folder
                wszPath = AfxStrPathname( "PATH", wszArg )
                if len(wszPath) = 0 then wszArg = AfxGetExePathName & wszArg 
                
                wszSendString = wszSendString & _
                                iif(len(wszSendString), ";", "") & _
                                wszArg
                i += 1
            loop

            dim as COPYDATASTRUCT cds
            cds.dwData = IDM_COPYDATA_COMMANDLINE
            cds.cbData = len(wszSendString) * 2  ' unicode
            cds.lpData = wszSendString.vptr
            SendMessage(hWindow, WM_COPYDATA, 0, cast(LPARAM, @cds))
            return true
        end if
    end if
    

    ' Initialize the COM library
    CoInitialize(null)


    ' Load the Scintilla code editing dll
    dim as any ptr pLibLexilla = dylibload("Lexilla64.dll")
    dim as any ptr pLibScintilla = dylibload("Scintilla64.dll")
    gApp.pfnCreateLexerfn = cast(CreateLexerFn , GetProcAddress(pLibLexilla, "CreateLexer"))

    if (pLibLexilla = 0) orelse (pLibScintilla = 0) then
        MessageBox( 0, _
                    "Error loading Scintilla DLL's. Ensure C++ redistributable is installed:" + vbcrlf + _
                    "https://aka.ms/vs/17/release/vc_redist.x64.exe", _
                    "Error", _
                    MB_OK or MB_ICONWARNING or MB_DEFBUTTON1 or MB_APPLMODAL )
        return 1
    end if

    ' Load the HTML help library for displaying FreeBASIC help *.chm file
    gpHelpLib = dylibload( "hhctrl.ocx" )

    ' Load codetip files 
    if gConfig.Codetips then gConfig.LoadCodetips


    ' Show the main form
    function = frmMain_Show( 0 )


    ' Free the Scintilla, CaptureConsole and HTML help libraries
    dylibfree(pLibLexilla)
    dylibfree(pLibScintilla)
    dylibfree(gpHelpLib)
    
    ' Unload the font file
    if len(wszFontFile) then RemoveFontResource(wszFontFile)
    
    ' Uninitialize the COM library
    CoUninitialize

end function


' ========================================================================================
' Main program entry point
' ========================================================================================
end WinMain( GetModuleHandle(null), null, command(), SW_NORMAL )

