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

#define IDC_MENUBAR_FILE      1000
#define IDC_MENUBAR_EDIT      1001
#define IDC_MENUBAR_SEARCH    1002
#define IDC_MENUBAR_VIEW      1003
#define IDC_MENUBAR_PROJECT   1004
#define IDC_MENUBAR_COMPILE   1005
#define IDC_MENUBAR_HELP      1006

''  Menu message identifiers
enum
    '' USER MESSAGES
    MSG_USER_SETFOCUS = WM_USER + 1     ' 1024 + 1
    MSG_USER_PROCESS_COMMANDLINE 
    MSG_USER_SHOWAUTOCOMPLETE
    MSG_USER_APPENDEQUALSSIGN
    MSG_USER_PROCESS_STARTUPUSERTOOLS
    MSG_USER_TOPTABS_CHANGING
    MSG_USER_TOPTABS_CHANGED
    MSG_USER_LOAD_EXPLORERFILES
    MSG_USER_LOAD_FUNCTIONLISTFILES
    MSG_USER_LOAD_BOOKMARKSFILES
    MSG_USER_LOAD_FUNCTIONSFILES
    MSG_USER_SHOW_KEYBOARDEDIT
    
    '' FILE
    IDM_FILE_START
    IDM_FILE, IDM_FILENEW, IDM_FILEOPEN, IDM_FILEOPENASTEMPLATE
    IDM_FILEOPEN_EXPLORERLISTBOX
    IDM_FILECLOSE, IDM_FILECLOSE_EXPLORERLISTBOX
    IDM_FILECLOSEALL, IDM_FILECLOSEALLOTHERS, IDM_CLOSEALLFORWARD, IDM_CLOSEALLBACKWARD
    IDM_FILESAVE, IDM_FILESAVE_EXPLORERLISTBOX
    IDM_FILESAVEAS, IDM_FILESAVEAS_EXPLORERLISTBOX 
    IDM_FILERENAME, IDM_FILERENAME_EXPLORERLISTBOX
    IDM_FILESAVEALL
    IDM_LOADSESSION, IDM_SAVESESSION, IDM_CLOSESESSION
    IDM_MRU, IDM_MRUFILES, IDM_MRUSESSION, IDM_MRUSESSIONFILES
    IDM_OPENINCLUDE, IDM_KEYBOARDSHORTCUTS 
    IDM_OPTIONS, IDM_OPTIONSDIALOG, IDM_BUILDCONFIG, IDM_BUILDCONFIG_POPUP, IDM_THEMES
    IDM_USERTOOLS, IDM_USERTOOLSDIALOG
    IDM_EXIT
    IDM_FILE_END
    
    '' EDIT 
    IDM_EDIT_START
    IDM_UNDO, IDM_REDO
    IDM_CUT, IDM_COPY, IDM_PASTE, IDM_INSERTFILE
    IDM_FILEENCODING, IDM_ANSI, IDM_UTF8, IDM_UTF8BOM, IDM_UTF16BOM
    IDM_DELETELINE, IDM_DELETE, 
    IDM_FIND, IDM_FINDNEXT, IDM_FINDPREV
    IDM_REPLACENEXT, IDM_REPLACEPREV, IDM_REPLACEALL
    IDM_FINDNEXTACCEL, IDM_FINDPREVACCEL 
    IDM_FINDINFILES, IDM_REPLACE
    IDM_INDENTBLOCK, IDM_UNINDENTBLOCK, IDM_COMMENTBLOCK, IDM_UNCOMMENTBLOCK
    IDM_DUPLICATELINE, IDM_MOVELINEUP, IDM_MOVELINEDOWN, IDM_NEWLINEBELOWCURRENT
    IDM_TOUPPERCASE, IDM_TOLOWERCASE, IDM_TOMIXEDCASE
    IDM_LINEENDINGS, IDM_EOLTOCRLF, IDM_EOLTOLF
    IDM_SELECTLINE, IDM_TABSTOSPACES
    IDM_SPACES, IDM_SELECTALL
    IDM_EDIT_END
    
    '' SEARCH
    IDM_SEARCH_START
    IDM_SEARCH
    IDM_DEFINITION, IDM_LASTPOSITION
    IDM_GOTONEXTTAB, IDM_GOTOPREVTAB, IDM_CLOSETAB, IDM_GOTONEXTFUNCTION, IDM_GOTOPREVFUNCTION
    IDM_GOTOHEADERFILE, IDM_GOTOSOURCEFILE, IDM_GOTOMAINFILE, IDM_GOTORESOURCEFILE
    IDM_BOOKMARKTOGGLE, IDM_BOOKMARKNEXT, IDM_BOOKMARKPREV, IDM_BOOKMARKCLEARALL
    IDM_BOOKMARKCLEARALLDOCS, IDM_CLEARALLBOOKMARKNODE, IDM_REMOVEBOOKMARKNODE
    IDM_GOTONEXTCOMPILEERROR, IDM_GOTOPREVCOMPILEERROR
    IDM_SETFOCUSEDITOR, IDM_GOTO
    IDM_SEARCH_END
    
    '' VIEW
    IDM_VIEW_START
    IDM_VIEW, IDM_VIEWSIDEPANEL, IDM_VIEWEXPLORER, IDM_VIEWOUTPUT, IDM_FUNCTIONLIST
    IDM_BOOKMARKSLIST, IDM_SPLITLEFTRIGHT, IDM_SPLITTOPBOTTOM
    IDM_ZOOMIN, IDM_ZOOMOUT, IDM_FOLDTOGGLE, IDM_FOLDBELOW, IDM_FOLDALL, IDM_UNFOLDALL
    IDM_VIEWTODO, IDM_VIEWNOTES, IDM_RESTOREMAIN, IDM_EXPLORERPOSITION
    IDM_VIEW_END
    
    '' PROJECT
    IDM_PROJECT_START
    IDM_PROJECTNEW, IDM_PROJECTMANAGER, IDM_PROJECTOPEN, IDM_MRUPROJECT, IDM_MRUPROJECTFILES
    IDM_PROJECTCLOSE, IDM_PROJECTSAVE, IDM_PROJECTSAVEAS, IDM_PROJECTFILESADD, IDM_PROJECTOPTIONS  
    IDM_PROJECTFILETYPE, IDM_REMOVEFILEFROMPROJECT, IDM_REMOVEFILEFROMPROJECT_EXPLORERLISTBOX
    IDM_PROJECT_END
        
    '' COMPILE
    IDM_COMPILE_START
    IDM_BUILDEXECUTE, IDM_COMPILE, IDM_REBUILDALL, IDM_RUNEXE, IDM_QUICKRUN, IDM_COMMANDLINE
    IDM_COMPILE_END
    
    '' HELP
    IDM_HELP_START
    IDM_HELP_FB, IDM_HELP_TIKO, IDM_ABOUT
    IDM_HELP_END
    
    '' OTHER
    IDM_SETFILEMAIN
    IDM_SETFILERESOURCE
    IDM_SETFILEHEADER
    IDM_SETFILEMODULE
    IDM_SETFILENORMAL
    IDM_SETFILEMAIN_EXPLORERTREEVIEW
    IDM_SETFILERESOURCE_EXPLORERTREEVIEW
    IDM_SETFILEHEADER_EXPLORERTREEVIEW
    IDM_SETFILEMODULE_EXPLORERTREEVIEW
    IDM_SETFILENORMAL_EXPLORERTREEVIEW
    IDM_EXPLORER_EXPANDALL 
    IDM_EXPLORER_COLLAPSEALL 
    IDM_FUNCTIONS_EXPANDALL 
    IDM_FUNCTIONS_COLLAPSEALL 
    IDM_BOOKMARKS_EXPANDALL 
    IDM_BOOKMARKS_COLLAPSEALL 
    IDM_FUNCTIONS_VIEWASTREE
    IDM_FUNCTIONS_VIEWASLIST
    IDM_SETCATEGORY
    IDM_CLOSEPANEL
    IDM_COPYDATA_COMMANDLINE     ' IPC message sending commandline between instances of the editor
        
    IDM_MRUCLEAR, IDM_MRUSESSIONCLEAR, IDM_MRUPROJECTCLEAR
    IDM_CONSOLE, IDM_GUI, IDM_RESOURCE, IDM_LINKMODULES   ' used for compiler directives in code
    IDM_32BIT, IDM_64BIT   ' mainly used for identifying compiler associated with a project
end enum

#define IDM_USERTOOLSLIST    4000
#define IDM_USERTOOLSBASE    4001
#define IDM_MRUBASE          5000  ' Windows id of MRU items 1 to 10 (located under File menu)
#define IDM_MRUPROJECTBASE   6000  ' Windows id of MRUPROJECT items 1 to 10 (located under Project menu)
#define IDM_MRUSESSIONBASE   7000  ' Windows id of MRUSESSION items 1 to 10 (located under File menu)
#define IDM_BUILDCONFIGBASE  8000


'  Global window handles
dim shared as HWND HWND_FRMMAIN, HWND_FRMRECENT, HWND_FRMOUTPUT, HWND_FRMMAIN_STATUSBAR
dim shared as HWND HWND_FRMMAIN_MENUBAR
dim shared as HWND HWND_FRMHELPVIEWER, HWND_FRMHELPVIEWER_LEFTPANEL, HWND_FRMHELPVIEWER_RIGHTPANEL
dim shared as HWND HWND_FRMOPTIONS, HWND_FRMOPTIONSGENERAL, HWND_FRMOPTIONSEDITOR, HWND_FRMOPTIONSEDITOR2
dim shared as HWND HWND_FRMOPTIONSCOLORS, HWND_FRMOPTIONSCOMPILER, HWND_FRMOPTIONSLOCAL
dim shared as HWND HWND_FRMOPTIONSKEYWORDS, HWND_FRMOPTIONSKEYWORDSWINAPI
dim shared as HWND HWND_FRMFINDREPLACE, HWND_FRMFINDINFILES, HWND_FRMFINDREPLACE_SHADOW
dim shared as HWND HWND_FRMBUILDCONFIG, HWND_FRMUSERTOOLS, HWND_FRMABOUT
dim shared as HWND HWND_FRMKEYBOARD, HWND_FRMKEYBOARD_LISTVIEW, HWND_FRMKEYBOARDEDIT

dim shared as HWND HWND_FRMMAIN_TOPTABS, HWND_FRMMAIN_TOPTABS_SHADOW
dim shared as HWND HWND_FRMEXPLORER, HWND_FRMEXPLORER_LISTBOX
dim shared as HWND HWND_FRMFUNCTIONS, HWND_FRMFUNCTIONS_LISTBOX
dim shared as HWND HWND_FRMBOOKMARKS, HWND_FRMBOOKMARKS_LISTBOX
dim shared as HWND HWND_FRMPANEL, HWND_FRMPANEL_MENU, HWND_FRMPANEL_VSCROLLBAR
dim shared as HWND HWND_FRMEDITOR_HSCROLLBAR(1)
dim shared as HWND HWND_FRMEDITOR_VSCROLLBAR(1)

dim shared as long ghIconGood, ghIconBad
dim shared as HCURSOR ghCursorSizeNS
dim shared as HCURSOR ghCursorSizeWE

' Create a dynamic array that will hold all localization words/phrases while
' a language is being edited in frmOptionsLocal. Also create a global array
' that holds the english phrases. When a localization is loaded, any missing
' translations are replaced with the english version.
redim shared gLangEnglish(any) as wstring * MAX_PATH
redim shared gLocalPhrases(any) as wstring * MAX_PATH
common shared gLocalPhrasesEdit as boolean   ' a localization language is being edited. 

' Create a dynamic array that will hold all localization words/phrases. This
' array is resized and loaded using the LoadLocalizationFile function.
redim shared LL(any) as wstring * MAX_PATH

' Define a macro that allows the user to specify the LL array subscript and
' also a descriptive label (that is ignored), and return the LL array value.
#Define L(e,s) LL(e)

#Define SetFocusScintilla  PostMessage( HWND_FRMMAIN, MSG_USER_SETFOCUS, 0, 0 )
#Define SciExec(h, m, w, l) SendMessage(h, m, w, CAST(LPARAM, l))


''
''  Save information related to Find/Replace and Find in Files operations
''
type FINDREPLACE_TYPE
    bFirstTimeInvoked   as boolean = true
    hCueBannerFont      as HFONT
    foundCount          as long 
    txtFind             as CWSTR
    txtReplace          as CWSTR
    txtFindCombo(10)    as CWSTR
    txtReplaceCombo(10) as CWSTR
    txtFilesCombo(10)   as CWSTR
    txtFolderCombo(10)  as CWSTR
    txtLastFind         as CWSTR
    txtFiles            as CWSTR         ' *.*, *.bas, etc (FindInFolder)
    txtFolder           as CWSTR         ' start search from this folder (FindInFolder)
    nSearchSubFolders   as long          ' search sub folders as well (FindInFolder)
    nWholeWord          as long          ' find/replace whole word search
    nMatchCase          as long          ' match case when searching
    nSelection          as long          ' search only selected text
    nPreserve           as long          ' search only selected text
    nSearchCurrentDoc   as long
    nSearchAllOpenDocs  as long
    nSearchProject      as long
    wszResults          as CWSTR
    bExpanded           as boolean
    rcExpand            as RECT
    rcMatchCase         as RECT
    rcWholeWord         as RECT
    rcResults           as RECT
    rcUpArrow           as RECT  
    rcDownArrow         as RECT  
    rcSelection         as RECT
    rcPreserve          as RECT 
    rcReplace           as RECT 
    rcReplaceAll        as RECT 
    rcClose             as RECT 
end type
dim shared gFind as FINDREPLACE_TYPE
dim shared gFindInFiles as FINDREPLACE_TYPE


TYPE MENUBAR_ITEM
    wszText as CWSTR
    rcItem  as RECT
    id      as long
end type

' shared variables that control the state of what menubar button is active.
dim shared gMenuBar(any) as MENUBAR_ITEM
dim shared gActiveMenuBarIndex as long = -1
dim shared as long gMenuLastCurSel = -1
dim shared as boolean gPrevent_WM_NCACTIVATE = false

' array that holds the names of all fonts on the target system
dim shared gFontNames( any ) as CWSTR


const MENUITEM_HEIGHT = 24
const EXPLORERITEM_HEIGHT = 22
const MENUBAR_HEIGHT = 30
const TOPTABS_HEIGHT = 36
const OUTPUT_TABS_HEIGHT = 40

const MENUITEM_HEIGHT_COMPACT = 20
const EXPLORERITEM_HEIGHT_COMPACT = 19 
const MENUBAR_HEIGHT_COMPACT = 28 

const STATUSBAR_HEIGHT = 22
const SCROLLBAR_WIDTH_PANEL = 10
const SCROLLBAR_WIDTH_EDITOR = 12
const SCROLLBAR_HEIGHT = 12
const SCROLLBAR_MINTHUMBSIZE = 30
const SPLITSIZE = 4

enum SPLIT_MODE
    SplitNone       = 0
    SplitLeftRight  = 1
    SplitTopBottom  = 2
end enum


type TOPMENU_TYPE
    nParentID   as long
    nID         as long
    nChildID    as long
    isDisabled  as boolean
    isSeparator as boolean
    isChecked   as boolean
end type
redim shared gTopMenu(any) as TOPMENU_TYPE

dim shared as wstring * 10 _
    wszIconChevronLeft, wszIconChevronRight, wszIconChevronUp, wszIconChevronDown, _
    wszIconDocument, wszIconUpArrow, wszIconDownArrow, wszIconSelection, wszIconCheckmark, _
    wszIconClose, wszIconDirty, wszIconCompileResult, wszIconMatchCase, wszIconWholeWord, _
    wszIconPreserveCase, wszIconReplace, wszIconReplaceAll, wszIconMoreActions, wszIconAddFileButton, _
    wszIconExplorer, wszIconFunctions, wszIconBookmarks, wszIconCompile, wszIconBuildExecute, _
    wszIconSplitEditor, wszIconSplitLeftRight, wszIconSplitTopBottom, wszIconThemes, _
    wszIconSettings, wszIconCheckBoxEmpty, wszIconCheckBoxMarked

' Symbol characters display in top menus, frmExplorer, and tab control

'"Segoe Fluent Icons"
    wszIconClose             = !"\uE10A"      ' light X  
    wszIconChevronLeft       = !"\uE012"
    wszIconChevronRight      = !"\uE013" 
    wszIconChevronUp         = !"\uE014"
    wszIconChevronDown       = !"\uE015"
    wszIconDocument          = !"\u00B7"     ' small dot (use the regular Segue UI font for this one)
    wszIconUpArrow           = !"\uF0AD"     ' up arrow
    wszIconDownArrow         = !"\uF0AE"     ' down arrow
    wszIconSelection         = !"\uE14C"     ' selection icon
    wszIconCheckmark         = !"\uE001"     ' checkmark
    wszIconDirty             = !"\u2981"     ' larger dot
    wszIconCompileResult     = !"\uECCC"     ' larger circle  
    wszIconMatchCase         = "Aa"          ' match case
    wszIconWholeWord         = "W"           ' whole word
    wszIconPreserveCase      = "AB"          ' preserve case
    wszIconReplace           = !"\uE14B"     ' replace
    wszIconReplaceAll        = !"\uE299"     ' replace all
    wszIconMoreActions       = !"\uE10C"     ' ...
    wszIconAddFileButton     = !"\uE109"     ' plus sign (thicker)
    wszIconExplorer          = !"\uE8A9"
    wszIconFunctions         = !"\uE8BC"
    wszIconBookmarks         = !"\uE723"
    wszIconCompile           = !"\uE74C"
    wszIconBuildExecute      = !"\uE768"  
    wszIconSplitLeftRight    = !"\uF57C"   
    wszIconSplitTopBottom    = !"\uF16E"   
    wszIconSplitEditor       = wszIconSplitLeftRight
    wszIconSettings          = !"\uE713"   
    wszIconThemes            = !"\uE771"   
    wszIconCheckBoxEmpty     = !"\uE739"
    wszIconCheckBoxMarked    = !"\uE73A"

