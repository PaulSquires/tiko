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


type TYPE_BUILDS
    id               as string    ' GUID
    wszDescription   as CWSTR
    IsDefault        as long      ' 0:False, 1:True
    Is32bit          as long      ' 0:False, 1:True
    Is64bit          as long      ' 0:False, 1:True
    ExcludeInPopup   as long      ' 0:False, 1:True  (do not show in statusbar popup menu)
    wszOptions       as CWSTR     ' Compiler options (manual and selected from listbox)
    idMenu           as long      ' Used to match selected build from statusbar popup menu 
                                ' because some items can be excluded from the popup.
    IsCtrl           as long
    IsAlt            as long
    IsShift          as long
    wszKey           as CWSTR
end type

type TYPE_TOOLS
    wszDescription   as CWSTR
    wszCommand       as CWSTR
    wszParameters    as CWSTR
    wszKey           as CWSTR
    wszWorkingFolder as CWSTR
    IsCtrl           as long
    IsAlt            as long
    IsShift          as long
    IsPromptRun      as long
    IsMinimized      as long
    IsWaitFinish     as long
    IsDisplayMenu    as long
    Action           as long 
end type

type TYPE_CATEGORIES
    idFileType       as string    ' GUID or special node value (FILETYPE_*)
    wszDescription   as CWSTR
    bShow            as boolean = true
end type

' NOTE: These node types are different values than the FileType defines from
' the clsDocument.bi file so we could not reuse those equates. These nodetype
' equates defined the order in which the files will be displayed in the 
' explorer listbox.
    #define CATINDEX_FILES             0
    #define CATINDEX_MAIN              1
    #define CATINDEX_RESOURCE          2
    #define CATINDEX_HEADER            3
    #define CATINDEX_MODULE            4
    #define CATINDEX_NORMAL            5

type clsConfig
    public:
        ConfigFilename            as CWSTR 
        FBKeywordsFilename        as CWSTR 
        WinApiKeywordsFilename    as CWSTR 
        FBKeywordsDefaultFilename as CWSTR 
        FBCodetipsFilename        as CWSTR
        WinAPICodetipsFilename    as CWSTR 
        WinFBXCodetipsFilename    as CWSTR
        DefaultSessionFilename    as CWSTR 
        HelpTableOfContents       as CWSTR
         
        DateFileTime              as FILETIME
        
        SettingsVersion           as CWSTR
        Tools(any)                as TYPE_TOOLS
        ToolsTemp(any)            as TYPE_TOOLS  
        Builds(any)               as TYPE_BUILDS  
        BuildsTemp(any)           as TYPE_BUILDS  
        Cat(any)                  as TYPE_CATEGORIES
        CatTemp(any)              as TYPE_CATEGORIES
        ExplorerPositionRight     as long = false
        FBKeywords                as string
        WinApiKeywords            as string
        bKeywordsDirty            as boolean = true       ' not saved to file
        AskExit                   as long = false         ' use long so true/False string not written to file
        AutoSaveFiles             as long = false
        AutoSaveInterval          as long = 10            ' seconds between autosave checks
        idAutoSaveTimer           as long = 999           ' id of Autosave timer
        RestoreSession            as long = true
        wszLastActiveSession      as CWSTR
        CompactMenus              as long = false
        ShowPanel                 as long = true
        ShowPanelWidth            as long = 250
        ShowOutputPanel           as long = true
        ShowOutputPanelHeight     as long = OUTPUT_TABS_HEIGHT * 5 ' user set height 
        ShowOutputPanelMinimized  as long = true          ' if window is at minimum height (toggled "minimized")
        ShowOutputPanelIndex      as long = 0             ' gOutputTabsCurSel (default: Compiler Results)
        SyntaxHighlighting        as long = true
        Codetips                  as long = true
        AutoComplete              as long = true
        CharacterAutoComplete     as long = false
        RightEdge                 as long = false
        RightEdgePosition         as CWSTR = "80"
        LeftMargin                as long = true
        FoldMargin                as long = false
        AutoIndentation           as long = true
        ForNextVariable           as long = false
        ConfineCaret              as long = true
        LineNumbering             as long = true
        HighlightCurrentLine      as long = true
        IndentGuides              as long = false
        PositionMiddle            as long = false         ' position found text to middle of screen
        BraceHighlight            as long = false
        OccurrenceHighlight       as long = false
        TabIndentSpaces           as long = true
        MultipleInstances         as long = true
        CompileAutosave           as long = true
        UnicodeEncoding           as long = false
        TabSize                   as CWSTR = "4"
        LocalizationFile          as CWSTR = "english.lang"
        EditorFontname            as CWSTR = "Consolas"
        EditorFontCharSet         as CWSTR = "Default"
        EditorFontsize            as CWSTR = "11"
        FontExtraSpace            as CWSTR = "2"
        ThemeShortFilename        as CWSTR = "default_dark.theme"
        KeywordCase               as long = 3  ' "Original Case"
        StartupLeft               as long = 0
        StartupTop                as long = 0
        StartupRight              as long = 0
        StartupBottom             as long = 0
        StartupMaximized          as long = false
        HelpStartupLeft           as long = 0
        HelpStartupTop            as long = 0
        HelpStartupRight          as long = 0
        HelpStartupBottom         as long = 0
        HelpStartupMaximized      as long = false
        HelpLeftPanelWidth        as long = 0
        FBWINCompiler32           as CWSTR
        FBWINCompiler64           as CWSTR
        CompilerBuild             as CWSTR     ' Build GUID
        CompilerSwitches          as CWSTR
        CompilerIncludes          as CWSTR
        CompilerHelpfile          as CWSTR
        RunViaCommandWindow       as long = false
        DisableCompileBeep        as long = false
        MRU(9)                    as CWSTR
        MRUProject(9)             as CWSTR
        MRUSession(9)             as CWSTR
                                
        declare constructor()
        declare function SetCategoryDefaults() as long
        declare function LoadKeywords() as long
        declare function SaveKeywords() as long
        declare function WriteMRU() as long
        declare function WriteMRUProjects() as long
        declare function WriteMRUSessions() as long
        declare function SaveConfigFile() as long
        declare function LoadConfigFile( byval isHotReload as boolean = false ) as long
        declare function CloseSessionFile( byref wszSessionFile as wstring ) as boolean    
        declare function SaveSessionFile( byref wszSessionFile as wstring ) as boolean    
        declare function LoadSessionFile( byref wszSessionFile as wstring ) as boolean   
        declare function SaveDefaultSessionFile() as boolean    
        declare function LoadDefaultSessionFile() as boolean    
        declare function ProjectSaveToFile() as boolean    
        declare function ProjectLoadFromFile( byval wszFile as CWSTR ) as boolean    
        declare function LoadCodetipsFB() as boolean
        declare function LoadCodetipsWinAPI() as boolean
        declare function LoadCodetipsWinFBX() as boolean
        declare function LoadCodetipsGeneric( byval wszFilename as CWSTR, byval nFiletype as long) as boolean
        declare function LoadCodetips() as long
        declare function ReloadConfigFileTest() as boolean    
end type
