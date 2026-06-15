# Windows Procedures

Assorted Windows procedures.

**Include File**: AfxNova/AfxWin.inc.

---

## Windows

| Name       | Description |
| ---------- | ----------- |
| [AfxCommand](#afxcommand) | Returns command line parameters used to call the program. |
| [AfxCommandLineCount](#afxcommandlinecount) | Returns the number of command line arguments used to call the program |
| [AfxComputerName](#afxgetcomputername) | Retrieves the NetBIOS name of the local computer. |
| [AfxComputerNameDnsFullyQualified](#afxgetcomputernamednsfullyqualified) | Retrieves the fully qualified DNS name that uniquely identifies the local computer. |
| [AfxComputerNameDnsHostname](#afxgetcomputernamednshostname) | Retrieves the DNS host name of the local computer. |
| [AfxGetComputerNameDnsHostname](#afxgetcomputernamednshostname) | Retrieves the The DNS host name of the local computer. |
| [AfxComputerNameNetBios](#afxgetcomputernamenetbios) | Retrieves the NetBIOS name of the local computer. |
| [AfxExtractResource](#afxextractresource) | Extracts resource data and returns it as a string. |
| [AfxExtractResourceToFile](#afxextractresourcetofile) | Extracts resource data and saves it to a file. |
| [AfxGetAllMACAddresses](#afxgetallmacaddresses) | Populates a dynamic array of STRINGs with all the real MAC addresses of the system. |
| [AfxGetAllPhysicalMACAddresses](#afxgetallphysicalmacaddresses) | Populates a dynamic array of STRINGs with all *real* MAC addresses (Ethernet/Wi-Fi). |
| [AfxGetComputerName](#afxgetcomputername) | Retrieves the NetBIOS name of the local computer. |
| [AfxComputerNameDnsFullyQualified](#afxgetcomputernamednsfullyqualified) | Retrieves the fully qualified DNS name that uniquely identifies the local computer. |
| [AfxGetComputerNameDnsHostname](#afxgetcomputernamednshostname) | Retrieves the The DNS host name of the local computer. |
| [AfxComputerNameNetBios](#afxgetcomputernamenetbios) | Retrieves the NetBIOS name of the local computer. |
| [AfxGetMACAddress](#afxgetmacaddress) | Retrieves the MAC address of a machine's Ethernet card. |
| [AfxGetMACAddressEx](#afxgetmacaddressex) | Retrieves the MAC address of a machine's Ethernet card. |
| [AfxGetTempPath](#afxtemppath) | Retrieves the path of the directory designated for temporary files. |
| [AfxGetUserName](#afxgetusername) | Retrieves the name of the user associated with the current thread. |
| [AfxGetSystemWow64Directory](#afxgetsystemwow64directory) | Retrieves the path of the system directory used by WOW64. |
| [AfxGetWinDir](#afxgetwindir) | Retrieves the path of the Windows directory. |
| [AfxGetWinErrMsg](#afxgetwinerrmsg) | Retrieves the localized description of the specified Windows error code. |
| [AfxGetWindowsDirectory](#afxgetwindir) | Retrieves the path of the Windows directory. |
| [AfxMsg](#afxmsg) | Displays an application modal message box. |
| [AfxSystemWow64Directory](#afxgetsystemwow64directory) | Retrieves the path of the system directory used by WOW64. |
| [AfxTempPath](#afxtemppath) | Retrieves the path of the directory designated for temporary files. |
| [AfxUserName](#afxgetusername) | Retrieves the name of the user associated with the current thread. |
| [AfxWinDir](#afxgetwindir) | Retrieves the path of the Windows directory. |

---

## File and Folder Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxChDir](#afxchdir) | Changes the current directory for the current process. |
| [AfxCopyFile](#afxcopyfile) | Copies an existing file to a new file. |
| [AfxCreateDirectory](#afxmakedir) | Creates a new directory. |
| [AfxCurDir](#afxcurdir) | Retrieves the current directory for the current process. |
| [AfxDeleteFile](#Afxdeletefile) | Deletes the specified file. |
| [AfxExeFileExt](#afxgetexefileext) | Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it. |
| [AfxExeFileName](#afxgetexefilename) | Returns the file name of the program which is currently executing. |
| [AfxExeFileNameX](#afxgetexefilenameX) | Returns the file name and extension of the program which is currently executing. |
| [AfxGetExeFullPath](#afxgetexefullpath) | Returns the complete drive, path, file name, and extension of the program which is currently executing. |
| [AfxExePath](#afxexepath) | Returns the path of the program which is currently executing. The path has not a trailing backslash except if it is a drive, e.g. C:\. |
| [AfxExePathName](#afxgetexpathname) | Returns the path of the program which is currently executing. The path has a trailing backslash. |
| [AfxFileCopy](#Afxcopyfile) | Copies an existing file to a new file. |
| [AfxFileDateTime](#afxfiledatetime) | Returns the file's last modified date and time as Date Serial. |
| [AfxFileExists](#afxfileexists) | Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). |
| [AfxFileExt](#Afxgetfileext) | Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it. |
| [AfxFileName](#afxgetfilename) | Parses a path/filename and returns the file name portion. That is the text to the right of the last backslash (\) or colon (:), ending just before the last period (.). |
| [AfxFileNameX](#afxgetfilenamex) | Parses a path/filename and returns the file name and extension portion. That is the text to the right of the last backslash (\) or colon (:). |
| [AfxFileReadAllLines](#afxfilereadalllines) | Reads all the lines of the specified file into a safe array. |
| [AfxFileScan](#afxfilescan) | Scans a text file and returns the number of occurrences of the specified delimiter. |
| [AfxFolderExists](#afxfolderexists) | Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). |
| [AfxFolderName](#afxgetfoldername) | Returns a string containing the name of the folder for a specified path, i.e. the path minus the file name. |
| [AfxGetCurDir](#afxcurdir) | Retrieves the current directory for the current process. |
| [AfxGetCurrentDirectory](#afxcurdir) | Retrieves the current directory for the current process. |
| [AfxGetDriveType](#afxgetdrivetype) | Determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive. |
| [AfxGetExeFileExt](#afxgetexefileext) | Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it. |
| [AfxGetExeFileName](#afxgetexefilename) | Returns the file name of the program which is currently executing. |
| [AfxGetExeFileNameX](#afxgetexefilenameX) | Returns the file name and extension of the program which is currently executing. |
| [AfxGetExeFullPath](#afxgetexefullpath) | Returns the complete drive, path, file name, and extension of the program which is currently executing. |
| [AfxGetExePath](#Afxexepath) | Returns the path of the program which is currently executing. The path has not a trailing backslash except if it is a drive, e.g. C:\. |
| [AfxGetExePathName](#afxgetexpathname) | Returns the path of the program which is currently executing. The path has a trailing backslash. |
| [AfxGetFileCreationTime](#afxgetfilecreationtime) | Returns the time the file was created, in FILETIME format. |
| [AfxGetFileExt](#Afxgetfileext) | Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it. |
| [AfxGetFileLastAccessTime](#afxgetfilelastaccesstime) | Returns the time the file was last accessed, in FILETIME format. |
| [AfxGetFileLastWriteTime](#Afxgetfilelastwritetime) | Returns the time the file was last written to, truncated, or overwritten, in FILETIME format. |
| [AfxFileLen](#afxgetfilesize) | Returns the size in bytes of the specified file. |
| [AfxGetFileName](#afxgetfilename) | Parses a path/filename and returns the file name portion. That is the text to the right of the last backslash (\) or colon (:), ending just before the last period (.). |
| [AfxGetFileNameX](#afxgetfilenamex) | Parses a path/filename and returns the file name and extension portion. That is the text to the right of the last backslash (\) or colon (:). |
| [AfxGetFileSize](#afxgetfilesize) | Returns the size in bytes of the specified file. |
| [AfxGetFileVersion](#afxgetfileversion) | Retrieves the version of the specified file multiplied by 100, e.g. 601 for version 6.01. |
| [AfxGetFolderName](#afxgetfoldername) | Returns a string containing the name of the folder for a specified path, i.e. the path minus the file name. |
| [AfxGetKnowFolderPath](#afxgetknowfolderpath) | Retrieves the path of an special folder. Requires Windows Vista/Windows 7 or superior. |
| [AfxGetLongPathName](#afxgetlongpathname) | Retrieves the short path form of the specified path. |
| [AfxGetPathFromProcessId](#afxgetpathfromprocessid) | Retrieves the path of the executable file given its process identifier. |
| [AfxGetPathName](#afxgetpathname) | Parses a path/filename and returns the path portion. That is the text up to and including the last backslash (\) or colon (:). |
| [AfxGetShortPathName](#afxgetshortpathname) | Retrieves the short path form of the specified path. |
| [AfxGetSpecialFolderLocation](#afxgetspecialfolderlocation) | Retrieves the path of an special folder. |
| [AfxGetSystemDllPath](#afxgetsystemdllpath) | Retrieves the fully qualified path for the file that contains the specified module. |
| [AfxGetSystemDrive](#afxsystemdrive) | Retrieves the fully qualified path for the file that contains the specified module. |
| [AfxGetSystemDirectory](#afxsystemdirectory) | Retrieves the path of the system directory. |
| [AfxGetWinDir](#afxgetwindir) | Retrieves the path of the Windows directory. |
| [AfxIsCompressedFile](#afxiscompressedfile) | Returns True if the specified file or directory is compressed; False if it is not. |
| [AfxIsEncryptedFile](#afxisencryptedfile) | Returns True if the specified file or directory is encrypted; False if it is not. |
| [AfxIsFolder](#afxisfolder) | Returns True if the specified path is a folder; False if it is not. |
| [AfxIsHiddenFile](#afxishiddenFile) | Returns True if the specified path is a hidden file or directory; False if it is not. |
| [AfxIsNormalFile](#afxisnormalfile) | Returns True if the specified path is a normal file (a file that does not have other attributes set); False if it is not. |
| [AfxIsNotContentIndexedFile](#afxisnotcontentindexedfile) | Returns TRUE if the specified file or directory is not to be indexed by the content indexing service; FALSE, otherwise. |
| [AfxIsOfflineFile](#afxisofflinefile) | Returns TRUE if the specified file file is not available immediately; FALSE, otherwise. |
| [AfxIsReadOnlyFile](#afxisreadonlyfile) | Returns True if the specified path is a read only file; False if it is not. |
| [AfxIsReparsePointFile](#afxisreparsepointfile) | Returns TRUE if the specified path is a file or directory that has an associated reparse point, or a file that is a symbolic link.; FALSE, otherwise. |
| [AfxIsSparseFile](#afxissparsefile) | Returns TRUE if the specified path is a sparse file; FALSE, otherwise. |
| [AfxIsSystemFile](#afxissystemfile) | Returns True if the specified path is a system file; False if it is not. |
| [AfxIsTemporaryFile](#afxistemporaryfile) | Returns True if the specified path is a temporary file; False if it is not. |
| [AfxKill](#afxdeletefile) | Deletes the specified file. |
| [AfxLongPathName](#afxgetlongpathname) | Retrieves the short path form of the specified path. |
| [AfxMakeDir](#afxmakedir) | Creates a new directory. |
| [AfxMkDir](#afxmakedir) | Creates a new directory. |
| [AfxMoveFile](#afxmovefile) | Moves an existing file or a directory, including its children. |
| [AfxName](#afxmovefile) | Moves an existing file or a directory, including its children. |
| [AfxPathFromProcessId](#afxgetpathfromprocessid) | Retrieves the path of the executable file given its process identifier. |
| [AfxPathName](#afxgetpathname) | Parses a path/filename and returns the path portion. That is the text up to and including the last backslash (\) or colon (:). |
| [AfxRemoveDirectory](#afxremovedir) | Deletes an existing empty directory. |
| [AfxRemoveDir](#afxremovedir) | Deletes an existing empty directory. |
| [AfxRenameFile](#afxmovefile) | Moves an existing file or a directory, including its children. |
| [AfxRmDir](#afxremovedir) | Deletes an existing empty directory. |
| [AfxSaveIconToFile](#afxsaveicontofile) | Saves an icon to a file. |
| [AfxSaveTempFile](#afxsavetempfile) | Saves the contents of a string buffer in a temporary file. |
| [AfxSetCurDir](#afxchdir) | Changes the current directory for the current process. |
| [AfxSetCurrentDirectory](#afxchdir) | Changes the current directory for the current process. |
| [AfxShortPathName](#afxgetshortpathname) | Retrieves the short path form of the specified path. |
| [AfxSystemDllPath](#afxgetsystemdllpath) | Retrieves the fully qualified path for the file that contains the specified module. |
| [AfxSystemDirectory](#afxsystemdirectory) | Retrieves the path of the system directory. |
| [AfxSystemDrive](#afxsystemdrive) | Retrieves the fully qualified path for the file that contains the specified module. |

---

## Window

| Name       | Description |
| ---------- | ----------- |
| [AfxCenterWindow](#afxcenterwindow) | Centers a window on the screen or over another window. |
| [AfxForceSetForegroundWindow](#afxforcesetforegroundwindow) | Brings the thread that created the specified window into the foreground and activates the window. |
| [AfxGetSystemInfo](#afxgetsysteminfo) | Retrieves information about the current system. |
| [AfxGetTopEnabledWindow](#afxgettopenabledwindow) | Retrieves the handle of the enabled and visible window at the top of the z-order in an application. |
| [AfxGetTopLevelParent](#afxgettoplevelparent) | Retrieves the window's top-level parent window. |
| [AfxGetTopLevelWindow](#afxgettoplevelwindow) | Retrieves the window's top-level parent or owner window. |
| [AfxGetWindowBounds](#afxgetwindowbounds) | Retrieves the bounds of a window without the drop shadows. |
| [AfxGetWindowClassName](#afxgetwindowclassname) | Retrieves the name of the class to which the specified window belongs. |
| [AfxGetWindowClientHeight](#afxgetwindowclientheight) | Returns the height of the client area of window, in pixels. |
| [AfxGetWindowClientRect](#afxgetwindowclientrect) | Retrieves the coordinates of a window's client area. |
| [AfxGetWindowClientWidth](#afxgetwindowclientwidth) | Returns the width of the client area of a window, in pixels. |
| [AfxGetWindowHeight](#afxgetwindowHhight) | Returns the height of a window, in pixels. |
| [AfxGetWindowLocation](#afxgetwindowlocation) | Returns the location of the top left corner of the window, in pixels. |
| [AfxGetWindowRect](#afxgetwindowrect) | Retrieves the dimensions of the bounding rectangle of the specified window. |
| [AfxGetWindowSize](#afxgetwindowsize) | Gets the width and height of a window, in pixels. |
| [AfxGetWindowText](#afxgetwindowtext) | Gets the text of a window. |
| [AfxGetWindowTextLength](#afxgetwindowtextlength) | Gets the length of the text of a window. |
| [AfxGetWindowWidth](#afxgetwindowwidth) | Returns the width of a window, in pixels. |
| [AfxGetWorkAreaHeight](#afxgetworkareaheight) | Retrieves the height of the work area on the primary display monitor expressed in virtual screen coordinates. |
| [AfxGetWorkAreaRect](#afxgetworkarearect) | Retrieves the coordinates of the work area on the primary display monitor expressed in virtual screen coordinates |
| [AfxGetWorkAreaWidth](#afxgetworkareawidth) | Retrieves the width of the work area on the primary display monitor expressed in virtual screen coordinates. |
| [AfxMoveWindowForDpi](#afxmovewindowfordpi) | Changes the position and dimensions of the specified window. |
| [AfxRedrawNonClientArea](#afxredrawnonclientarea) | Redraws the non-client area of the specified window. |
| [AfxRedrawWindow](#afxredrawwindow) | Redraws the specified window. |
| [AfxSetWindowClientSize](#afxsetwindowclientsize) | Adjusts the bounding rectangle of a window based on the desired size of the client area. |
| [AfxSetWindowClientSizeForDpi](#afxsetwindowclientsize) | Adjusts the bounding rectangle of a window based on the desired size of the client area. DPI aware. |
| [AfxSetWindowIcon](#afxsetwindowicon) | Associates a new large icon with a window. |
| [AfxSetWindowLocation](#afxsetwindowlocation) | Sets the location of the top left corner of the window, in pixels. |
| [AfxSetWindowLocationForDpi](#afxsetwindowlocation) | Sets the location of the top left corner of the window, in pixels. DPI aware |
| [AfxSetWindowPosForDpi](#afxsetwindowposfordpi) | Sets the size of the specified window, in pixels. |
| [AfxSetWindowSize](#afxsetwindowsize) | Sets the size of the specified window, in pixels. |
| [AfxSetWindowSizeForDpi](#afxsetwindowsizefordpi) | Sets the size of the specified window, in pixels. DPI aware. |
| [AfxSetWindowText](#afxsetwindowtext) | Sets the text of a window. |
| [AfxShowWindowState](#afxshowwindowstate) | Sets the specified window's show state. |

---

## Window styles

| Name       | Description |
| ---------- | ----------- |
| [AfxAddWindowExStyle](#afxaddwindowexstyle) | Adds a new extended style to the specified window. |
| [AfxAddWindowStyle](#afxaddwindowstyle) | Adds a new style to the specified window. |
| [AfxGetWindowExStyle](#afxgetwindowexstyle) | Retrieves the extended window styles of the specified window. |
| [AfxGetWindowStyle](#afxgetwindowstyle) | Retrieves the window styles of the specified window. |
| [AfxRemoveWindowExStyle](#afxremovewindowexstyle) | Removes an extended style from the specified window. |
| [AfxRemoveWindowStyle](#afxremovewindowstyle) | Removes a style from the specified window. |
| [AfxSetWindowExStyle](#afxsetwindowexstyle) | Sets the extended style(s) of the specified window. |
| [AfxSetWindowStyle](#afxsetwindowstyle) | Sets the style(s) of the specified window. |

---

## Display

| Name       | Description |
| ---------- | ----------- |
| [AfxForceVisibleDisplay](#afxforcevisibledisplay) | Force visibility of an off-screen window. |
| [AfxGetDisplayBitsPerPixel](#afxgetdisplaybitsperpixel) | Returns the color resolution, in bits per pixel, of the display device. |
| [AfxGetDisplayFrequency](#afxgetdisplayfrequency) | Returns the frequency, in hertz (cycles per second), of the display device in a particular mode. |
| [AfxGetDisplayPixelsHeight](#afxgetdisplaypixelsheight) | Returns the height, in pixels, of the current display device on the computer on which the calling thread is running. |
| [AfxGetDisplayPixelsWidth](#afxgetdisplaypixelswidth) | Returns the width, in pixels, of the current display device on the computer on which the calling thread is running. |
| [AfxGetScreenColors](#afxgetdisplaybitsperpixel) | Returns the color resolution, in bits per pixel, of the display device. |
| [AfxGetScreenHeight](#afxgetscreenheight) | Retrieves the height of the screen, in pixels. This function is virtualized for DPI. |
| [AfxGetScreenRefreshDate](#afxgetdisplayfrequency) | Returns the frequency, in hertz (cycles per second), of the display device in a particular mode. |
| [AfxScreenWidth](#afxgetscreenwidth) | Retrieves the width of the screen, in pixels. This function is virtualized for DPI. |
| [AfxScreenColors](#afxgetdisplaybitsperpixel) | Returns the color resolution, in bits per pixel, of the display device. |
| [AfxGetScreenRefreshDate](#afxgetdisplayfrequency) | Returns the frequency, in hertz (cycles per second), of the display device in a particular mode. |
| [AfxGetWorkArea](#afxgetworkarea) | Retrieves the coordinates of the work area on the primary display monitor expressed in virtual screen coordinates. |
| [AfxScreenHeight](#afxgetscreenheight) | Retrieves the height of the screen, in pixels. This function is virtualized for DPI. |
| [AfxScreenWidth](#afxgetscreenwidth) | Retrieves the width of the screen, in pixels. This function is virtualized for DPI. |
| [AfxWorkArea](#afxgetworkarea) | Retrieves the coordinates of the work area on the primary display monitor expressed in virtual screen coordinates. |

---

## Messages

| Name       | Description |
| ---------- | ----------- |
| [AfxDoEvents](#afxdoevents) | Processes pending Windows messages. |
| [AfxForwardSizeMessage](#afxforwardsizemMessage) | Sends a WM_SIZE message to the specified window. |
| [AfxPumpMessages](#afxpumpmessages) | Processes pending Windows messages. |

---

## Handles

| Name       | Description |
| ---------- | ----------- |
| [AfxGetControlHandle](#afxgetcontrolhandle) | Returns the handle of the control with the specified identifier. |
| [AfxGetFormHandle](#afxgetformhandle) | Finds the handle of the top-level window or MDI child window that is the ancestor of the specified window handle. |
| [AfxGetHwndFromPID](#afxgethwndfrompid) | Retrieves a window handle given it's process identifier. |
| [AfxPathFromWindowHandle](#afxgetpathfromwindowhandle) | Retrieves the path of the executable file that created the specified window. |
| [AfxGetPathFromWindowHandle](#afxgetpathfromwindowhandle) | Retrieves the path of the executable file that created the specified window. |

---

## Common dialogs

| Name       | Description |
| ---------- | ----------- |
| [AfxBrowseForFolder](#afxbrowseforfolder) | Displays a dialog box that enables the user to select a folder. |
| [AfxChooseColorDialog](#afxchoosecolordialog) | Displays the Windows choose color dialog. |
| [AfxControlRunDLL](#afxcontrolrundll) | Launches control panel applications. |
| [AfxOpenFileDialog](#afxopenfiledialog) | Creates an Open dialog box that lets the user specify the drive, directory, and the name of a file or set of files to be opened. |
| [AfxSaveFileDialog](#afxsavefiledialog) | Creates a Save dialog box that lets the user specify the drive, directory, and name of a file to save. |
| [AfxShowSysInfo](#afxshowsysinfo) | Displays the Windows Information System dialog. |

---

## High DPI

| Name       | Description |
| ---------- | ----------- |
| [AfxGetDpi](#afxlogpixelsx) | Retrieves the number of pixels per logical inch. |
| [AfxGetDpiX](#afxlogpixelsx) | Retrieves the number of pixels per logical inch along the screen width. |
| [AfxGetDpiY](#afxlogpixelsy) | Retrieves the number of pixels per logical inch along the screen height. |
| [AfxGetMonitorHorizontalScaling](#afxgetmonitorhorizontalscaling) | Returns the horizontal scaling of the monitor that the window is currently displayed on. |
| [AfxGetMonitorVerticalScaling](#afxgetmonitorverticalscaling) | Returns the vertical scaling of the monitor that the window is currently displayed on. |
| [AfxGetMonitorLogicalHeight](#afxgetmonitorlogicalheight) | Returns the logical height of the monitor that the window is currently displayed on. |
| [AfxGetMonitorLogicalWidth](#afxgetmonitorlogicalwidth) | Returns the logical width of the monitor that the window is currently displayed on. |
| [AfxIsDPIResolutionAtLeast](#afxisdpiresolutionatleast) | Determines if screen resolution meets minimum requirements in relative pixels. |
| [AfxIsProcessDPIAware](#afxisprocessdpiaware) | Determines whether the current process is dots per inch (dpi) aware. |
| [AfxIsResolutionAtLeast](#afxisresolutionatleast) | Determines if screen resolution meets minimum requirements. |
| [AfxLoadIconMetric](#afxloadiconmetric) | Loads a specified icon resource with a client-specified system metric. |
| [AfxLogPixelsX](#afxlogpixelsx) | Retrieves the number of pixels per logical inch along the screen width. |
| [AfxLogPixelsY](#afxlogpixelsy) | Retrieves the number of pixels per logical inch along the screen height. |
| [AfxScaleRatioX](#afxscaleratiox) | Retrieves the desktop horizontal scaling ratio. |
| [AfxScaleRatioY](#afxscaleratioy) | Retrieves the desktop vertical scaling ratio. |
| [AfxScaleX](#afxscalex) | Scales an horizontal coordinate according the DPI (dots per pixel) being used by the operating system. |
| [AfxScaleY](#afxscaley) | Scales an vertical coordinate according the DPI (dots per pixel) being used by the operating system. |
| [AfxSetProcessDPIAware](#afxsetprocessdpiaware) | Sets the current process as dots per inch (dpi) aware. |
| [AfxUnscaleX](#afxunscalex) | Unscales an horizontal coordinate according the DPI (dots per pixel) being used by the operating system. |
| [AfxUnscaleY](#afxunscaley) | Unscales a vertical coordinate according the DPI (dots per pixel) being used by the operating system. |
| [AfxUseDpiScaling](#afxusedpiscaling) | Returns TRUE if the OS uses DPI scaling; FALSE otherwise. |

---

## Fonts

| Name       | Description |
| ---------- | ----------- |
| [AfxCreateFont](#afxcreatefont) | Creates a logical font. |
| [AfxGetFontHeight](#afxgetfontheight) | Returns the logical height of a font given its point size. |
| [AfxGetFontPointSize](#afxgetfontpointsize) | Returns the point size of a font given its logical height. |
| [AfxGetWindowFont](#afxgetwindowfont) | Retrieves the font with which the window or control is currently drawing its text. |
| [AfxGetWindowFontInfo](#afxgetwindowfontinfo) | Retrieves information about the font being used by a window or control. |
| [AfxGetWindowsFontInfo](#afxgetwindowsfontinfo) | Retrieves information about the fonts used by Windows. |
| [AfxGetWindowsFontPointSize](#afxgetwindowsfontpointsize) | Retrieves the point size of the fonts used by Windows. |
| [AfxModifyFontFaceName](#afxmodifyfontfacename) | Modifies the face name of the font of a window or control. |
| [AfxModifyFontHeight](#afxmodifyfontheight) | Modifies the height of the font used by a window of control. |
| [AfxModifyFontSettings](#afxmodifyfontsettings) | Modifies settings of the font used by a window of control. |
| [AfxSetWindowFont](#afxsetwindowfont) | Sets the font that a control is to use when drawing text. |

---

## Clipboard

| Name       | Description |
| ---------- | ----------- |
| [AfxClearClipboard](#afxclearclipboard) | Clears the contents of the clipboard. |
| [AfxGetClipboardData](#afxgetclipboarddata) | Retrieves data from the clipboard in the specified format. |
| [AfxGetClipboardText](#afxgetclipboardtext) | Returns a text string from the clipboard. |
| [AfxSetClipboardData](#afxsetclipboarddata) | Places data on the clipboard in a specified clipboard format. |
| [AfxSetClipboardText](#afxsetclipboardtext) | Places a text string into the clipboard. |

---

## Bitmap

| Name       | Description |
| ---------- | ----------- |
| [AfxCaptureDisplay](#afxcapturedisplay) | Captures the display and returns an handle to a bitmap. |
| [AfxGetBitmapHeight](#afxgetbitmapheight) | Retrieves the height of the specified bitmap. |
| [AfxGetBitmapWidth](#afxgetbitmapwidth) | Retrieves the width of the specified bitmap. |

---

## Device Independent Bitmap (DIB)

| Name       | Description |
| ---------- | ----------- |
| [AfxCreateDIBSection](#afxcreatedibsection) | Creates a DIB section. |
| [AfxDibLoadImage](#AfxDibLoadImage) | Loads a DIB in memory and returns a pointer to it. |
| [AfxDibSaveImage](#AfxDibSaveImage) | Saves a DIB to a file. |

---

## Metric conversions

| Name       | Description |
| ---------- | ----------- |
| [AfxHiMetricToPixelsX](#AfxHiMetricToPixelsX) | Converts from HiMetric to Pixels (horizontal resolution). |
| [AfxHiMetricToPixelsY](#AfxHiMetricToPixelsY) | Converts from HiMetric to Pixels (vertical resolution). |
| [AfxPixelsToHiMetricX](#AfxPixelsToHiMetricX) | Converts from Pixels to HiMetric (horizontal resolution). |
| [AfxPixelsToHiMetricY](#AfxPixelsToHiMetricY) | Converts from Pixels to HiMetric (vertical resolution). |
| [AfxPixelsToPointsX](#AfxPixelsToPointsX) | Converts pixels to points size (1/72 of an inch) (horizontal resolution). |
| [AfxPixelsToPointsY](#AfxPixelsToPointsY) | Converts pixels to points size (1/72 of an inch) (vertical resolution). |
| [AfxPixelsToTwipsX](#AfxPixelsToTwipsX) | Converts pixels to twips (horizontal resolution). |
| [AfxPixelsToTwipsY](#AfxPixelsToTwipsY) | Converts pixels to twips (vertical resolution). |
| [AfxPointSizeToDip](#AfxPointSizeToDip) | Converts point size to DIP (device independent pixel). |
| [AfxPointsToPixelsX](#AfxPointsToPixelsX) | Converts a point size (1/72 of an inch) to pixels (horizontal resolution). |
| [AfxPointsToPixelsY](#AfxPointsToPixelsY) | Converts a point size (1/72 of an inch) to pixels (vertical resolution). |
| [AfxTwipsPerPixelX](#AfxTwipsPerPixelX) | Returns the width of a pixel in twips (horizontal resolution). |
| [AfxTwipsPerPixelY](#AfxTwipsPerPixelY) | Returns the width of a pixel in twips (vertical resolution). |
| [AfxTwipsToPixelsX](#AfxTwipsToPixelsX) | Converts twips to pixels (horizontal resolution). |
| [AfxTwipsToPixelsY](#AfxTwipsToPixelsY) | Converts twips to pixels (vertical resolution). |

---

## Mail and Internet

| Name       | Description |
| ---------- | ----------- |
| [AfxGetDefaultBrowserName](#AfxGetDefaultBrowserName) | Retrieves the name of the default browser. |
| [AfxGetDefaultBrowserPath](#AfxGetDefaultBrowserPath) | Retrieves the path of the default browser. |
| [AfxGetDefaultMailClientName](#AfxGetDefaultMailClientName) | Retrieves the name of the default client mail application. |
| [AfxGetDefaultMailClientPath](#AfxGetDefaultMailClientPath) | Retrieves the path of the default mail client application. |
| [AfxGetInternetExplorerVersion](#AfxGetInternetExplorerVersion) | Returns the Internet Explorer version installed. |
| [AfxInternetAttemptConnect](#afxinternetattemptconnect) | Attempts to make a connection to the Internet. |
| [AfxInternetCheckConnection](#afxinternetcheckconnection) | Checks if a connection to the Internet can be established. |
| [AfxInternetCanonicalizeUrl](#afxinternetcanonicalizeurl) | Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences. |
| [AfxInternetCombineUrl](#afxinternetcombineurl) | Combines a base and relative URL into a single URL. The resultant URL is canonicalized. |
| [AfxInternetGetConnectedState](#afxinternetgetconnectedstate) | Retrieves the connected state of the local system. |
| [AfxInternetGetConnectionDescription](#afxinternetgetconnectiondescription) | Retrieves the connection description. |
| [AfxInternetGetConnectionName](#afxinternetgetconnectionname) | Retrieves the connection name. |

---

## System information

| Name       | Description |
| ---------- | ----------- |
| [AfxAppsUseDarkMode](#afxappsusedarkmode) | Returns TRUE if Windows applications are using dark mode, or FALSE otherwise. |
| [AfxAvailablePageFile](#afxavailablepagefile) | Returns maximum amount of memory the current process can commit, in bytes. |
| [AfxAvailablePhysicalMemory](#afxavailablephysicalmemory) | Returns the amount of physical memory currently available, in bytes. |
| [AfxAvailableVirtualMemory](#afxavailablevirtualmemory) | Returns size of the user-mode portion of the virtual address space of the calling process, in bytes. |
| [AfxComCtlVersion](#afxcomctlversion) | Returns the version of CommCtl32.dll. |
| [AfxGetPhysicallyInstalledSystemMemory](#afxgetphysicallyinstalledsystemmemory) | Retrieves the amount of RAM that is physically installed on the computer, in kilobytes. |
| [AfxGetProductInfo](#afxgetproductinfo) | Retrieves the product type for the operating system on the local computer, and maps the type to the product types supported by the specified operating system. |
| [AfxGetUserDomain](#afxgetuserdomain) | Retrieves the name of the user associated with the current thread. |
| [AfxGetWindowsBuild](#afxwindowsbuild) | Returns the Windows build number. |
| [AfxGetWindowsInstallDate](#afxwindowsinstalldate) | Returns the date in which Windows was installed, in Unix time. |
| [AfxGetWindowsMajorVersion](#afxwindowsmajorversion) | Returns the Windows major version. |
| [AfxGetWindowsMinorVersion](#afxwindowsminorversion) | Returns the Windows minor version. |
| [AfxGetWindowsPlatform](#afxwindowsplatform) | Returns the Windows platform. |
| [AfxGetWindowsVersion](#afxwindowsversion) | Returns the Windows version. |
| [AfxGetWindowsVersionStr](#afxgetwindowsversionstr) | Returns the full Windows version as a string. |
| [AfxIsPlatformNT](#afxisplatformnt) | Returns TRUE if the Windows Platform is NT; FALSE, otherwise. |
| [AfxIsProcessElevated](#afxisprocesselevated) | Checks if the process is running with real administrative privileges. |
| [AfxMemoryLoad](#afxmemoryload) | Returns the amount of actual physical memory, in bytes. |
| [AfxPhysicallyInstalledSystemMemory](#afxgetphysicallyinstalledsystemmemory) | Retrieves the amount of RAM that is physically installed on the computer, in kilobytes. |
| [AfxProcessorArchitecture](#afxprocessorarchitecture) | Returns the processor architecture of the operating system. |
| [AfxProcessorsCount](#afxprocessorscount) | Returns the number of processors. |
| [AfxSystemUsesDarkMode](#afxsystemusesdarkmode) | Returns TRUE if Windows is using dark mode, or FALSE otherwise. |
| [AfxTotalPageFile](#afxtotalpagefile) | Returns the current committed memory limit for the system or the current process, whichever is smaller, in bytes. |
| [AfxTotalPhysicalMemory](#afxtotalphysicalmemory) | Returns the amount of actual physical memory, in bytes. |
| [AfxTotalVirtualMemory](#afxtotalvirtualmemory) | Returns size of the user-mode portion of the virtual address space of the calling process, in bytes. |
| [AfxWindowsBitness](#afxwindowsbitness) | Returns the bitness of the operating system (32 or 64 bit). |
| [AfxWindowsBuild](#afxwindowsbuild) | Returns the Windows build number. |
| [AfxWindowsFeatureUpdate](#afxwindowsfeatureupdate) | Returns the Windows feature update versión, e.g. 22H2. |
| [AfxWindowsInstallDate](#afxwindowsinstalldate) | Returns the date in which Windows was installed, in Unix time. |
| [AfxWindowsPlatform](#afxwindowsplatform) | Returns the Windows platform. |
| [AfxWindowsMajorVersion](#afxwindowsmajorversion) | Returns the Windows major version. |
| [AfxWindowsMinorVersion](#afxwindowsminorversion) | Returns the Windows minor version. |
| [AfxWindowsVersion](#afxwindowsversion) | Returns the Windows version. |
| [AfxWindowsVersionStr](#afxgetwindowsversionstr) | Returns the full Windows version as a string. |

## Power status

| Name       | Description |
| ---------- | ----------- |
| [ACLineStatus](#aclinestatus) | Retrieves the AC power status. |
| [AfxBatteryChargeStatus](#afxbatterychargestatus) | Retrieves the battery charge status. |
| [AfxBatteryLifePercent](#afxbatterylifepercent) | Retrieves the percentage of full battery charge remaining. |
| [AfxBatteryLifeTime](#afxbatterylifetime) | Retrieves the number of seconds of battery life remaining. |
| [AfxBatteryFullLifeTime](#afxbatteryfulllifetime) | Retrieves the number of seconds of battery life when at full charge |

---

### AfxCommand

Returns command line parameters used to call the program. Unicode replacement for FreeBasic's **Command** keyword. **WCOmmand** is an alias or **AfxCommand**.

```
FUNCTION AfxCommand (BYVAL nIndex AS LONG = -1) AS DWSTRING
#define WCommand AfxCommand
```

| Parameter  | Description |
| ---------- | ----------- |
| *nIndex* | Zero-based index for a particular command-line argument. |

#### Return value

Returns the command-line arguments(s).

#### Remarks

**AfxCommand** returns command-line arguments passed to the program upon execution.

If index is less than zero (< 0), a space-separated list of all command-line arguments is returned, otherwise, a single argument is returned. A value of zero (0) returns the name of the executable; and values of one (1) and greater return each command-line argument.

If index is greater than the number of arguments passed to the program, a null string ("") is returned.

---

### AfxCommandLineCount

Returns the number of command line arguments used to call the program. **WCommandArgsc** is an alias for **AfxCommandLineCount**.

```
FUNCTION AfxCommandLineCount (BYVAL nIndex AS LONG = -1) AS DWSTRING
#define WCommandArgsc AfxCommandLineCount
```
#### Return value

The number of command line arguments used to call the program.

---

### AfxExtractResource

Extracts resource data and returns it as a string.

```
FUNCTION AfxExtractResource (BYVAL hInstance AS HINSTANCE, _
   BYREF wszResourceName AS WSTRING, BYVAL pResourceType AS LPWSTR = MAKEINTRESOURCEW(10)) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInstance* | A handle to the module whose portable executable file or an accompanying MUI file contains the resource. If this parameter is NULL, the function searches the module used to create the current process. |
| *wszResourceName* | Name of the resource. If the resource is an image that uses an integral identifier, *wszResourceName* should begin with a number symbol (#) followed by the identifier in an ASCII format, e.g., "#998". Otherwise, use the text identifier name for the image. Only images embedded as raw data (type RCDATA) are valid. These must be in format .png, .jpg, .gif, .tiff. |
| *pResourceType* | Type of the resource, e.g. RT_RCDATA. For a list of predefined resource types see: [Resource Types](https://docs.microsoft.com/en-us/windows/desktop/menurc/resource-types) |

#### Return value

A string containing the resource data.

#### Example

```
DIM strResData AS STRING = AfxExtractResource(NULL, "IDI_ARROW_RIGHT")
where IDI_ARROW_RIGHT is the identifier in the resource file for
IDI_ARROW_RIGHT RCDATA ".\Resources\arrow_right_64.png"
--or--
DIM strResData AS STRING = AfxExtractResource(NULL, "#111")
' where "#111" is the identifier in the resource file for
' 111 RCDATA ".\Resources\VEGA_PAZ_01.jpg"
-----
' // Write the resource data to a file
DIM hFile AS HANDLE = CreateFileW("PazVega.jpg", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
IF hFile THEN
   DIM dwBytesWritten AS DWORD
   DIM bSuccess AS BOOLEAN = WriteFile(hFile, STRPTR(strResData), LEN(strResData), @dwBytesWritten, NULL)
   CloseHandle(hFile)
   print bSuccess
END IF
```
---

### AfxExtractResourceToFile

Extracts resource data and saves it to a file.

```
FUNCTION AfxExtractResourceToFile (BYVAL hInstance AS HINSTANCE, BYREF wszResourceName AS WSTRING, _
   BYREF wszFileName AS WSTRING, BYVAL pResourceType AS LPWSTR = MAKEINTRESOURCEW(10)) AS STRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInstance* | A handle to the module whose portable executable file or an accompanying MUI file contains the resource. If this parameter is NULL, the function searches the module used to create the current process. |
| *wszResourceName* | Name of the resource. If the resource is an image that uses an integral identifier, *wszResourceName* should begin with a number symbol (#) followed by the identifier in an ASCII format, e.g., "#998". Otherwise, use the text identifier name for the image. Only images embedded as raw data (type RCDATA) are valid. These must be in format .png, .jpg, .gif, .tiff. |
| *wszFileName* | Path of the file where to save the extracted resource. |
| *pResourceType* | Type of the resource, e.g. RT_RCDATA. For a list of predefined resource types see: [Resource Types](https://docs.microsoft.com/en-us/windows/desktop/menurc/resource-types) |

#### Return value

TRUE on success of FALSE on failure.

#### Example

```
AfxExtractResourceToFile(NULL, "IDI_ARROW_RIGHT", "IDI_ARROW_RIGHT.png")
where IDI_ARROW_RIGHT is the identifier in the resource file for
IDI_ARROW_RIGHT RCDATA ".\Resources\arrow_right_64.png"
```
#### Example

```
AfxExtractResourceToFile(NULL, "#111", "VEGA_PAZ_01.jpg")
where "#111" is the identifier in the resource file for
111 RCDATA ".\Resources\VEGA_PAZ_01.jpg"
```
---

### AfxChDir

Changes the current directory for the current process. Aliases: **AfxSetCurDir**, **AfxSetCurrentDirectory**.

```
FUNCTION AfxChDir (BYVAL pwszPathName AS LPCWSTR) AS LONG
FUNCTION AfxSetCurDir (BYVAL pwszPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxSetCurrentDirectory (BYVAL pwszPathName AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpPathName* | The path to the new current directory. This parameter may specify a relative path or a full path. In either case, the full path of the specified directory is calculated and stored as the current directory. |

#### Return value for AfxChDir:

If the function succeeds, the return value is 0.<br>
If the function fails, the return value is -1.<br>
To get extended error information, call **GetLastError**.

**AfxMkDir** is an unicode replacement for Free Basic's **MkDir**.

#### Return value for AfxSetCurDir and AfxSetCurrentDirectory:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

---

### AfxCopyFile

Copies an existing file to a new file. Alias: **AfxFileCopy**.

```
FUNCTION AfxCopyFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR, _
   BYVAL bFailIfExists AS BOOLEAN = FALSE) AS BOOLEAN
FUNCTION AfxFileCopy (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR, _
   BYVAL bFailIfExists AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpExistingFileName* | The name of an existing file. To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\\\\?\\" to the path. If *lpExistingFileName* does not exist, **CopyFile** fails, and **GetLastError** returns ERROR_FILE_NOT_FOUND. |
| *lpNewFileName* | The name of the new file. To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\\\\?\\" to the path. |
| *bFailIfExists* | If this parameter is TRUE and the new file specified by *lpNewFileName* already exists, the function fails. If this parameter is FALSE and the new file already exists, the function overwrites the existing file and succeeds. |

#### Return value

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE. To get extended error information, call **GetLastError**.

#### Rermarks

**AfxFileCopy** is an unicode replacement for Free Basic's **FileCopy** and returns 0 on success, or 1 if an error occurred.

---

### AfxMkDir

Creates a new directory. Aliases: **AfxMakeDir**, **AfxCreateDirectory**.

```
FUNCTION AfxMkDir (BYVAL lpPathName AS LPCWSTR) AS LONG
FUNCTION AfxCreateDirectory (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxMakeDir (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpPathName* | The path of the directory to be created. To extend the limit to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value for AfxMkDir:

If the function succeeds, the return value is 0.<br>
If the function fails, the return value is -1.<br>
To get extended error information, call **GetLastError**.

**AfxMkDir** is an unicode replacement for Free Basic's **MkDir**.

#### Return value for AfxCreateDirectory and AfxMakeDir:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

Possible errors include the following.

| Error      | Description |
| ---------- | ----------- |
| ERROR_ALREADY_EXISTS | The specified directory already exists. |
| ERROR_PATH_NOT_FOUND | One or more intermediate directories do not exist; this function will only create the final directory in the path. |

---

### AfxDeleteFile

Deletes the specified file. Alias: **AfxKill**.

```
FUNCTION AfxDeleteFile (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
FUNCTION AfxKill (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFileSpec* | The full path and name of the file to delete. To extend the limit to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

#### Remarks

If an application attempts to delete a file that does not exist, this function fails with ERROR_FILE_NOT_FOUND. If the file is a read-only file, the function fails with ERROR_ACCESS_DENIED.

**AfxKill** is an unicode replacement for Free Basic's **Kill** and returns 0 on success, or -1 on failure.

---

### AfxFileDateTime

Returns the file's last modified date and time as Date Serial. Unicode replacement for Free Basic's **FileDateTime**.

```
FUNCTION AfxFileDateTime (BYREF wszFileName AS WSTRING) AS DOUBLE
```

#### Return value

The date and time as a Date Serial. If it fails, it returns 0.

#### Example

```
#include "windows.bi"
#include "vbcompat.bi"
#include "Afx/AfxWin.bi"
DIM wszFileName AS WSTRING * MAX_PATH = ExePath & "\c2.bas"
DIM dt AS DOUBLE = AfxFileDateTime(wszFileName)
PRINT Format(dt, "yyyy-mm-dd hh:mm AM/PM")
```

### AfxCurdir

Retrieves the current directory for the current process. Aliases: **AfxGetCurDir**, **AfxGetCurrentDirectory**- Unicode replacement for Free Basic's **CurDir**.

```
FUNCTION AfxCurDir () AS DWSTRING
FUNCTION AfxGetCurDir () AS DWSTRING
FUNCTION AfxGetCurrentDirectory () AS DWSTRING
```

#### Return value

The name of the current directory for the current process.

---

### AfxMoveFile

Moves an existing file or a directory, including its children. Aliases: **AfxRenameFile**, **AfxMoveFile**. **AfxName** is an unicode replacement for Free Basic's **Name**.

```
FUNCTION AfxName (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS LONG
FUNCTION AfxRenameFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxMoveFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpExistingFileName* | The name of an existing file. To extend the limit to 32,767 wide characters, prepend "\\\\?\\" to the path. If *lpExistingFileName* does not exist, **AfxRenameFile** fails, and **GetLastError** returns ERROR_FILE_NOT_FOUND. |
| *lpNewFileName* | The name of the new file. To extend the limit to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value for AfxName:

If the function succeeds, the return value is 0.<br>
If the function fails, the return value is -1.<br>
To get extended error information, call **GetLastError**.

**AfxName** is an unicode replacement for Free Basic's **Name**.

#### Return value for AfxRenameFile and AfxMoveFile:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

---

### AfxRemoveDir 

Deletes an existing empty directory. Aliases: **AfxRemoveDirectory**. **AfxRmDir** is an unicode replacement for Free Basic's **RmDir**.

```
FUNCTION AfxRmDir (BYVAL lpPathName AS LPCWSTR) AS LONG
FUNCTION AfxRemoveDir (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxRemoveDirectory (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpPathName* | The path of the directory to be removed. This path must specify an empty directory, and the calling process must have delete access to the directory. To extend the limit to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value for AfxRmDir:

If the function succeeds, the return value is 0.<br>
If the function fails, the return value is -1.<br>
To get extended error information, call **GetLastError**.

**AfxRmDir** is an unicode replacement for Free Basic's **RmDir**.

#### Return value for AfxRemoveDir and AfxRemoveDirectory:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

#### Remaks

These functions mark a directory for deletion on close. Therefore, the directory is not removed until the last handle to the directory is closed. To recursively delete the files in a directory, use the **SHFileOperation** function.

---

### AfxFileExists

Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used).

```
FUNCTION AfxFileExists (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFileSpec* | The directory or path, and the file name, which can include wildcard characters, for example, an asterisk (\*) or a question mark (?). This parameter should not be NULL, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\). If the string ends with a wildcard, period (.), or directory name, the user must have access permissions to the root and all subdirectories on the path. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value

Boolean. TRUE if the specified file exist or FALSE otherwise.

#### Remarks

Prepending the string "\\\\?\\" does not allow access to the root directory.

On network shares, you can use an pwszFileSpec in the form of the following: "\\\\server\service\\\*". However, you cannot use an pwszFileSpec that points to the share itself; for example, "\\\\server\service" is not valid.

To examine a directory that is not a root directory, use the path to that directory, without a trailing backslash. For example, an argument of "C:\Windows" returns information about the directory "C:\Windows", not about a directory or file in "C:\Windows". To examine the files and directories in "C:\Windows", use an *pwszFileSpec* of "C:\Windows\*".

Be aware that some other thread or process could create or delete a file with this name between the time you query for the result and the time you act on the information. If this is a potential concern for your application, one possible solution is to use the **CreateFile** function with CREATE_NEW (which fails if the file exists) or OPEN_EXISTING (which fails if the file does not exist).

---

### AfxFolderExists

Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used).

```
FUNCTION AfxFolderExists (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFileSpec* | The directory or path, and the file name, which can include wildcard characters, for example, an asterisk (\*) or a question mark (?). This parameter should not be NULL, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\). If the string ends with a wildcard, period (.), or directory name, the user must have access permissions to the root and all subdirectories on the path. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value

Boolean. TRUE if the specified file exist or FALSE otherwise.

#### Remarks

Prepending the string "\\\\?\\" does not allow access to the root directory.

On network shares, you can use an *pwszFileSpec* in the form of the following: "\\\\server\service\\\*". However, you cannot use an pwszFileSpec that points to the share itself; for example, "\\\\server\service" is not valid.

To examine a directory that is not a root directory, use the path to that directory, without a trailing backslash. For example, an argument of "C:\Windows" returns information about the directory "C:\Windows", not about a directory or file in "C:\Windows". To examine the files and directories in "C:\Windows", use an pwszFileSpec of "C:\Windows\\\*".

Be aware that some other thread or process could create or delete a file with this name between the time you query for the result and the time you act on the information. If this is a potential concern for your application, one possible solution is to use the **CreateFile** function with CREATE_NEW (which fails if the file exists) or OPEN_EXISTING (which fails if the file does not exist).

---

### AfxGetFileSize

Returns the size in bytes of the specified file. Alias: **AfxFileLen**.

```
FUNCTION AfxGetFileSize (BYREF wszFileSpec AS WSTRING) AS ULONGLONG
FUNCTION AfxFileLen (BYREF wszFileSpec AS WSTRING) AS ULONGLONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Return value

The size in bytes of the file on success, or 0 on failure.

---

### AfxExePath

Returns the path of the program which is currently executing.

```
FUNCTION AfxExePath () AS DWSTRING
FUNCTION AfxGetExePath () AS DWSTRING
```

#### Remarks

Unicode replacement for Free Basic's **ExePath** function. The path name has not a trailing backslash, except if it is a drive, e.g. "C:\".

#### Alias

 **AfxGetExePath**.
 
---

### AfxGetExePathName

Returns the path of the program which is currently executing.

```
FUNCTION AfxGetExePathName () AS DWSTRING
```

#### Remarks

The path name has a trailing backslash.

#### Alias

**AfxExePathName**

---

### AfxGetDriveType

Determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive.

```
FUNCTION AfxGetDriveType (BYVAL lpRootPathName AS LPCWSTR) as UINT
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpRootPathName* | The root directory for the drive. A trailing backslash is required. If this parameter is NULL, the function uses the root of the current directory. |

#### Return value

DRIVE_UNKNOWN (0), DRIVE_NO_ROOT_DIR (1), DRIVE_REMOVABLE (2), DRIVE_FIXED(3), DRIVE_REMOTE (4), DRIVE_CDROM (5), DRIVE_RAMDISK (6).

---

### AfxGetExeFileExt

Parses a path/filename and returns the extension portion of the path/file name.

```
FUNCTION AfxGetExeFileExt () AS DWSTRING
```

#### Return value

The extension portion of the file name. That is the last period (.) in the string plus the text to the right of it.

#### Alias

**AfxExeFileExt**

---

### AfxGetExeFileName

Returns the file name of the program which is currently executing.

```
FUNCTION AfxGetExeFileName () AS DWSTRING
```

#### Alias

** AfxExeFilename**

---

### AfxGetExeFileNameX

Returns the file name and extension of the program which is currently executing.

```
FUNCTION AfxGetExeFileNameX () AS DWSTRING
```

#### Alias

** AfxExeFilenameX**

---

### AfxGetExeFullPath

Returns the complete drive, path, file name, and extension of the program which is currently executing.

```
FUNCTION AfxGetExeFullPath () AS DWSTRING
```

#### Alias

**AfxExeFullPath**

---

### AfxGetFileExt

Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it.

```
FUNCTION AfxGetFileExt (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. |

#### Alias

**AfxFileExt**

---

### AfxGetFileCreationTime

Returns the time the file was created, in FILETIME format.

```
FUNCTION AfxGetFileCreationTime (BYREF wszFileSpec AS WSTRING, BYVAL bUTC AS BOOLEAN = TRUE) AS FILETIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The directory or path, and the file name, which can include wildcard characters, for example, an asterisk (\*) or a question mark (?). This parameter should not be NULL, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\). If the string ends with a wildcard, period (.), or directory name, the user must have access permissions to the root and all subdirectories on the path. To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\\\?\\" to the path. |
| *bUTC* | Optional. Pass FALSE if you want to get the time in local time (the NTFS file system stores time values in UTC format, so they are not affected by changes in time zone or daylight saving time). **FileTimeToLocalFileTime** uses the current settings for the time zone and daylight saving time. Therefore, if it is daylight saving time, it takes daylight saving time into account, even if the file time you are converting is in standard time. |

---

### AfxGetFileLastAccessTime

Returns the time the file was accessed, in FILETIME format.

```
FUNCTION AfxGetFileLastAccessTime (BYREF wszFileSpec AS WSTRING, BYVAL bUTC AS BOOLEAN = TRUE) AS FILETIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The directory or path, and the file name, which can include wildcard characters, for example, an asterisk (\*) or a question mark (?). This parameter should not be NULL, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\). If the string ends with a wildcard, period (.), or directory name, the user must have access permissions to the root and all subdirectories on the path. To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\\\?\\" to the path. |
| *bUTC* | Optional. Pass FALSE if you want to get the time in local time (the NTFS file system stores time values in UTC format, so they are not affected by changes in time zone or daylight saving time). **FileTimeToLocalFileTime** uses the current settings for the time zone and daylight saving time. Therefore, if it is daylight saving time, it takes daylight saving time into account, even if the file time you are converting is in standard time. |

---

### AfxGetFileLastWriteTime

Returns the time the file was last written to, truncated, or overwritten, in FILETIME format.

```
FUNCTION AfxGetFileLastWriteTime (BYREF wszFileSpec AS WSTRING, BYVAL bUTC AS BOOLEAN = TRUE) AS FILETIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The directory or path, and the file name, which can include wildcard characters, for example, an asterisk (\*) or a question mark (?). This parameter should not be NULL, an invalid string (for example, an empty string or a string that is missing the terminating null character), or end in a trailing backslash (\\). If the string ends with a wildcard, period (.), or directory name, the user must have access permissions to the root and all subdirectories on the path. To extend the limit from MAX_PATH to 32,767 wide characters, prepend "\\\\?\\" to the path. |
| *bUTC* | Optional. Pass FALSE if you want to get the time in local time (the NTFS file system stores time values in UTC format, so they are not affected by changes in time zone or daylight saving time). **FileTimeToLocalFileTime** uses the current settings for the time zone and daylight saving time. Therefore, if it is daylight saving time, it takes daylight saving time into account, even if the file time you are converting is in standard time. |

---

### AfxGetFileName

Parses a path/filename and returns the file name portion. That is the text to the right of the last backslash (\) or colon (:), ending just before the last period (.).

```
FUNCTION AfxGetFileName (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. |

#### Alias

**AfxFileName**

---

### AfxGetFileNameX

Parses a path/filename and returns the file name and extension portion. That is the text to the right of the last backslash (\\) or colon (:).

```
FUNCTION AfxGetFileNameX (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. |

#### Alias

**AfxFileNameX**

---

### AfxGetFileVersion

Retrieves the version of the specified file multiplied by 100, e.g. 601 for version 6.01.

```
FUNCTION AfxGetFileVersion (BYVAL pwszFileName AS WSTRING PTR) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. |

---

### AfxGetFolderName

Returns a string containing the name of the folder for a specified path, i.e. the path minus the file name.

```
FUNCTION AfxGetFolderName (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. |

#### Alias

**AfxGetFolderName**

---

### AfxGetKnowFolderPath

Retrieves the path of an special folder.

```
FUNCTION AfxGetKnowFolderPath (BYVAL rfid AS CONST KNOWNFOLDERID CONST PTR, _
   BYVAL dwFlags AS DWORD = 0, BYVAL hToken AS HANDLE = NULL) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *rfid* | A reference to the KNOWNFOLDERID that identifies the folder. The folders associated with the known folder IDs might not exist on a particular system. |
| *dwFlags* | Flags that specify special retrieval options. This value can be 0; otherwise, it is one or more of the KNOWN_FOLDER_FLAG values. |
| *hToken* | An access token used to represent a particular user. This parameter is usually set to NULL, in which case the function tries to access the current user's instance of the folder. However, you may need to assign a value to *hToken* for those folders that can have multiple users but are treated as belonging to a single user. The most commonly used folder of this type is Documents. The calling application is responsible for correct impersonation when *hToken* is non-null. It must have appropriate security privileges for the particular user, including TOKEN_QUERY and TOKEN_IMPERSONATE, and the user's registry hive must be currently mounted. See [Access Control](https://msdn.microsoft.com/en-us/library/windows/desktop/aa374860(v=vs.85).aspx) for further discussion of access control issues.<br>Assigning the *hToken* parameter a value of -1 indicates the Default User. This allows clients of **SHGetKnownFolderIDList** to find folder locations (such as the Desktop folder) for the Default User. The Default User user profile is duplicated when any new user account is created, and includes special folders such as Documents and Desktop. Any items added to the Default User folder also appear in any new user account. Note that access to the Default User folders requires administrator privileges. |

#### Return value

The path of the requested folder on success, or an empty string on failure.

#### Remarks

Requires Windows Vista/Windows 7 or superior.

For a list of KNOWNFOLDERID constants see: [KNOWNFOLDERID](https://msdn.microsoft.com/en-us/library/windows/desktop/dd378457(v=vs.85).aspx)

#### Usage example

```
AfxGetKnowFolderPath(@FOLDERID_CommonPrograms)
```
---

### AfxGetLongPathName

Retrieves the short path form of the specified path.
```
FUNCTION AfxGetLongPathName (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. To extend the limit of MAX_PATH wode characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Alias

**AfxLongPathName**

---

### AfxGetPathFromProcessId

Retrieves the path of the executable file given its process identifier.

```
FUNCTION AfxGetPathFromProcessId (BYVAL dwProcessId AS DWORD) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwProcessId* | The process identifier. |

#### Alias

**AfxPathFromProcessId**

---

### AfxGetPathName

Parses a path/filename and returns the path portion. That is the text up to and including the last backslash (\) or colon (:).

```
FUNCTION AfxGetPathName (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. |

#### Alias

**AfxPathName**

---

### AfxGetShortPathName

Retrieves the short path form of the specified path.

```
FUNCTION AfxGetShortPathName (BYREF wszPath AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | The path/filename string. To extend the limit of MAX_PATH wode characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

#### Alias

**AfxShortPathName**

---

### AfxGetSpecialFolderLocation

Retrieves the path of a special folder.

```
FUNCTION AfxGetSpecialFolderLocation (BYVAL nFolder AS LONG) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *nFolder* | A CSIDL value that identifies the folder of interest. |

#### Remarks

For a list of CSIDL values see: [CSIDL](https://msdn.microsoft.com/en-us/library/windows/desktop/bb762494(v=vs.85).aspx)

---

### AfxGetSystemDllPath

Retrieves the fully qualified path for the file that contains the specified module.

```
FUNCTION AfxGetSystemDllPath (BYREF wszDllName AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszDllName* | The name of the system DLL to find. |

#### Remarks

To locate the file for a module that was loaded by another process, use the **GetModuleFileNameEx** function.

#### Alias

**AfxSystemDllPath**

---

### AfxSystemDrive

Returns the system drive name, e.g. "C:".

```
FUNCTION AfxSystemDrive () AS DWSTRING
```

#### Alias

**AfxGetSystemDrive**

---

### AfxSystemDirectory

Retrieves the path of the system directory.

```
FUNCTION AfxSystemDirectory () AS DWSTRING
```

#### Alias

**AfxGetSystemDirectory**

---

### AfxGetWinDir

Retrieves the path of the Windows directory. This path does not end with a backslash unless the Windows directory is the root directory. For example, if the Windows directory is named Windows on drive C, the path of the Windows directory retrieved by this function is C:\Windows. If the system was installed in the root directory of drive C, the path retrieved is C:\\.

```
FUNCTION AfxGetWinDir () AS DWSTRING
```

#### Aliases

**AfxWindir**, **"AfxWindowsDirectory**

---

### GetTempPath

Retrieves the path of the directory designated for temporary files.

```
FUNCTION AfxGetTempPath () AS DWSTRING
```

#### Alias

**AfxTempPath**

---

### AfxGetSystemWow64Directory

Retrieves the path of the system directory used by WOW64. This directory is not present on 32-bit Windows.

```
FUNCTION AfxGetSystemWow64Directory () AS DWSTRING
```

#### Alias

**AfxSystemWow64Directory**

---

### AfxIsCompressedFile

Returns True if the specified file or directory is compressed; False if it is not.

```
FUNCTION AfxIsCompressedFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsEncryptedFile

Returns True if the specified file or directory is encrypted; False if it is not.

```
FUNCTION AfxIsEncryptedFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsFolder

Returns True if the specified path is a folder; False if it is not.

```
FUNCTION AfxIsFolder (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsHiddenFile

Returns True if the specified path is a hidden file or directory; False if it is not.

```
FUNCTION AfxIsHiddenFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsNormalFile

Returns True if the specified path is a normal file (a file that does not have other attributes set); False if it is not.

```
FUNCTION AfxIsNormalFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsNotContentIndexedFile

Returns TRUE if the specified file or directory is not to be indexed by the content indexing service; FALSE, otherwise.

```
FUNCTION AfxIsNotContentIndexedFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsOfflineFile

Returns TRUE if the specified file file is not available immediately; FALSE, otherwise.

```
FUNCTION AfxIsOfflineFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsReadOnlyFile

Returns True if the specified path is a read only file; False if it is not.

```
FUNCTION AfxIsReadOnlyFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### <a name="AfxIsReparsePointFile"></a>AfxIsReparsePointFile

Returns TRUE if the specified path is a file or directory that has an associated reparse point, or a file that is a symbolic link.; FALSE, otherwise.

```
FUNCTION AfxIsReparsePointFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsSparseFile

Returns TRUE if the specified path is a sparse file; FALSE, otherwise.

```
FUNCTION AfxIsSparseFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsSystemFile

Returns True if the specified path is a system file; False if it is not.

```
FUNCTION AfxIsSystemFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxIsTemporaryFile

Returns True if the specified path is a temporary file; False if it is not.

```
FUNCTION AfxIsTemporaryFile (BYREF wszFileSpec AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileSpec* | The path to a file. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |

---

### AfxFileScan

Scans a text file ans returns the number of occurrences of the specified delimiter.

```
FUNCTION AfxFileScanA (BYREF wszFileName AS WSTRING, BYREF Delimiter AS ZSTRING = CHR(13, 10)) AS DWORD
FUNCTION AfxFileScanW (BYREF wszFileName AS WSTRING, BYREF Delimiter AS WSTRING = CHR(13, 10)) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | Path of the file to scan. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |
| *Delimiter* | Optional. Delimiter to find. Default value is CHR(13, 10), which returns the number of lines. You can use CHR(10) for Linux files, "," for comma delimited cvs files, CHR(9) for spreadshets in tab delimited format, etc. |

#### Remarks

Use **AfxFileScanA** for ansi text files and **AfxFileScanW** for unicode text files.

---

### AfxFileReadAllLines

Reads all the lines of the specified file into a safe array.

```
FUNCTION AfxFileReadAllLinesA (BYREF wszFileName AS WSTRING, BYREF Delimiter AS ZSTRING = CHR(13, 10)) AS DSafeArray
FUNCTION AfxFileReadAllLinesW (BYREF wszFileName AS WSTRING, BYREF Delimiter AS WSTRING = CHR(13, 10)) AS DSafeArray
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | Path of the file to scan. To extend the limit of MAX_PATH wide characters to 32,767 wide characters, prepend "\\\\?\\" to the path. |
| *Delimiter* | Optional. Delimiter to find. Default value is CHR(13, 10), which returns the number of lines. You can use CHR(10) for Linux files, "," for comma delimited cvs files, CHR(9) for spreadshets in tab delimited format, etc. |

#### Remarks

Use **AfxFileReadAllLinesA** for ansi text files and **AfxFileReadAllLinesW** for unicode text files.

Because it returns a safe array, this function is located in the DSafeArray.inc include file.

---

### AfxSaveIconToFile

Saves an icon to a file.

```
FUNCTION AfxSaveIconToFile (BYVAL hIcon AS HICON, BYREF fileName AS WSTRING) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *hIcon* | The icon handle. |
| *fileName* | The name of the file to save. |

#### Return value

Returns **S_OK** on success or and  HRESULT code on failure.

#### Usage examples

```
DIM hIcon as HICON = LoadIcon(NULL, IDI_INFORMATION)
DIM hr AS HRESULT = AfxSaveIconToFile(hIcon, "test.ico")
```
```
DIM hIcon AS HICON = cast(HICON, LoadImage(NULL, ExePath & "\" & "MyIco.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE))
DIM hr AS HRESULT = AfxSaveIconToFile(hIcon, "test2.ico")
```
---

### AfxSaveTempFile

Saves the contents of a string buffer in a temporary file.

```
FUNCTION AfxSaveTempFile (BYVAL pwszBuffer AS WSTRING PTR, BYREF wszExtension AS WSTRING) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszBuffer* | The string buffer to save. |
| *wszExtension* | Optional. The extension of the file name without a colon (e.g. "bas"). If an empty string is passed, the function will use "tmp" as the extension. |

#### Remarks

Temporary files whose names have been created by this function are not automatically deleted. To delete these files call **AfxDeleteFile**.

---

### AfxAddWindowExStyle

Adds a new extended style to the specified window.

```
FUNCTION AfxAddWindowExStyle (BYVAL hwnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
```
| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *dwExStyle* | Extended style to add. |

#### Return value

The previous window extended styles.

#### Usage example

```
AfxAddWindowExStyle(hwnd, WS_EX_COMPOSITED)
```

#### Remarks

If the window has a class style of CS_CLASSDC or CS_OWNDC, do not set the extended window styles WS_EX_COMPOSITED or WS_EX_LAYERED.

---

### AfxAddWindowStyle

Adds a new style to the specified window.

```
FUNCTION AfxAddWindowStyle (BYVAL hwnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
```
| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *dwStyle* | Style to add. |

#### Return value

The previous window styles.

#### Usage example

```
AfxAddWindowStyle(hwnd, WS_HSCROLL)
```

### AfxGetWindowExStyle

Retrieves the extended window styles of the specified window.

```
FUNCTION AfxGetWindowExStyle (BYVAL hwnd AS HWND) AS LONG_PTR

```
| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxGetWindowStyle

Retrieves the window styles of the specified window.

```
FUNCTION AfxGetWindowStyle (BYVAL hwnd AS HWND) AS LONG_PTR
```
| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxRemoveWindowExStyle

Removes an extended style from the specified window.

```
FUNCTION AfxRemoveWindowExStyle (BYVAL hwnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *dwExStyle* | The extended style to remove. |

#### Return value

The previous extended window styles.

### AfxRemoveWindowStyle

Removes a style from the specified window.

```
FUNCTION AfxRemoveWindowStyle (BYVAL hwnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *dwStyle* | The style to remove. |

#### Return value

The previous window styles.

---

### AfxSetWindowExStyle

Sets the extended style(s) of the specified window.

```
FUNCTION AfxSetWindowExStyle (BYVAL hwnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *dwExStyle* | The extended style(s) to set. |

#### Return value

The previous extended window styles.

---

### AfxSetWindowStyle

Sets the style(s) of the specified window.

```
FUNCTION AfxSetWindowStyle (BYVAL hwnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *dwStyle* | The style(s) to set. |

#### Return value

The previous window styles.

---

### AfxForceVisibleDisplay

If you use dual (or even triple/quad) displays then you have undoubtedly encountered the following situation: You change the physical order of your displays, or otherwise reconfigure the logical ordering using your display software. This sometimes has the side-effect of changing your desktop coordinates from zero-based to negative starting coordinates (i.e. the top-left coordinate of your desktop changes from 0,0 to -1024,-768).

This effects many Windows programs which restore their last on-screen position whenever they are started. Should the user reorder their display configuration this can sometimes result in a Windows program subsequently starting in an off-screen position (i.e. at a location that used to be visible) - and is now effectively invisible, preventing the user from closing it down or otherwise moving it back on-screen.

The **AfxForceVisibleDisplay** function can be called at program start-time right after the main window has been created and positioned 'on-screen'. Should the window be positioned in an off-screen position, it is forced back onto the nearest display to its last position. The user will be unaware this is happening and won't even realize to thank you for keeping their user-interface visible, even though they changed their display settings.

Source: Catch-22 web site.

```
SUB AfxForceVisibleDisplay (BYVAL hwnd AS HWND)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxGetDisplayBitsPerPixel

Returns the color resolution, in bits per pixel, of the display device.

```
FUNCTION AfxGetDisplayBitsPerPixel () AS DWORD
```

#### Aliases

**AfxScreenColors**, **AfxGetScreenColors**

---

### AfxGetDisplayFrequency

Returns the frequency, in hertz (cycles per second), of the display device in a particular mode. This value is also known as the display device's vertical refresh rate.

```
FUNCTION AfxGetDisplayBitsPerPixel () AS DWORD
```

#### Aliases

**AfxGetScreenRefreshDate**, **AfxScreenRefreshDate**

---

### AfxGetDisplayPixelsHeight

Returns the height, in pixels, of the current display device on the computer on which the calling thread is running.

```
FUNCTION AfxGetDisplayPixelsHeight () AS DWORD
```
---

### AfxGetDisplayPixelsWidth

Returns the width, in pixels, of the current display device on the computer on which the calling thread is running.

```
FUNCTION AfxGetDisplayPixelsWidth () AS DWORD
```

#### Remarks

Contrarily to **GetSystemMetrics** or **GetDeviceCaps**, it returns the real width even when it is called from an application that is not DPI aware, e.g. an application running virtualized in a monitor 1920 pixels width and a DPI of 192, will return 960 pixels if it calls **GetSystemMetrics** or **GetDeviceCaps**, but will return 1920 pixels calling **AfxGetDisplayPixelsWidth**.

---

### AfxScreenHeight

Retrieves the height of the screen, in pixels. This function is virtualized for DPI.

```
FUNCTION AfxGetScreenHeight () AS LONG
```

#### Alias

**AfxGetScreenHeight**

---

### AfxScreenWidth

Retrieves the width of the screen, in pixels. This function is virtualized for DPI.

```
FUNCTION AfxScreenWidth () AS LONG
```

#### Alias

**AfxGetScreenWidth**

---

### AfxGetWorkArea

Retrieves the coordinates of the work area on the primary display monitor expressed in virtual screen coordinates. The work area is the portion of the screen not obscured by the system taskbar or by application desktop toolbars. To get the work area of a monitor other than the primary display monitor, call the GetMonitorInfo function.

```
FUNCTION AfxGetWorkArea () AS RECT
```

#### Alias

**AfxWorkArea**

---

### AfxDoEvents

Processes pending Windows messages. Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow your application to be responsive to user input.

```
SUB AfxDoEvents (BYVAL hWin AS HWND = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Optional. Handle of the window or dialog. If NULL, the window handle to the active window attached to the calling thread's message queue is used. |

---

# <a name="AfxForwardSizeMessage"></a>AfxForwardSizeMessage

Sends a WM_SIZE message to the specified window.

```
FUNCTION AfxForwardSizeMessage (BYVAL hwnd AS HWND, BYVAL nResizeType AS DWORD, _
   BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to a window. |
| *nResizeType* | Type of resizing requested. |
| *nWidth* | The new width of the client area. |
| *nHeight* | The new height of the client ara. |

| Resizing type  | Description |
| -------------- | ----------- |
| SIZE_MAXHIDE | Message is sent to all pop-up windows when some other window is maximized. |
| SIZE_MAXIMIZED | Maximize the window. |
| SIZE_MAXSHOW | Message is sent to all pop-up windows when some other window has been restored to its former size. |
| SIZE_MINIMIZED | Minimize the window. |
| SIZE_RESTORED | The window has been resized, but neither the SIZE_MINIMIZED nor SIZE_MAXIMIZED value applies. |

#### Remark

If an application processes this message, it should return zero.

---

### AfxPumpMessages

Processes pending Windows messages. Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow your application to be responsive to user input.

```
SUB AfxPumpMessages
```
---

### AfxGetControlHandle

Returns the handle of the control with the specified identifier. The reference handle can be the handle of the form or the handle of any other control on the form.

```
FUNCTION AfxGetControlHandle (BYVAL hwnd AS HWND, BYVAL wCtrlID AS WORD) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *wCtrlID* | Control identifier. |

#### Return value

Returns the handle of the control or NULL.

---

### AfxGetFormHandle

Finds the handle of the top-level window or MDI child window that is the ancestor of the specified window handle. The reference handle is the handle of any control on the form.

```
FUNCTION AfxGetFormHandle (BYVAL hwnd AS HWND) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to the control. |

#### Return value

Handle of the ancestor window.

---

### AfxGetHwndFromPID

Retrieves a window handle given it's process identifier.

```
FUNCTION AfxGetHwndFromPID (BYVAL PID AS DWORD) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *PID* | The process identifier. |

#### Return value

The window handle or NULL.

---

### AfxGetPathFromWindowHandle

Retrieves the path of the executable file that created the specified window.

```
FUNCTION AfxGetPathFromWindowHandle (BYVAL hwnd AS HWND) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The window handle. |

#### Return value

The path of the executable file.

#### Alias

**AfxPathFromWindowHandle**

---

### AfxBrowseForFolder

Displays a dialog box that enables the user to select a folder.

```
FUNCTION AfxBrowseForFolder (BYVAL hwnd AS HWND, BYVAL pwszTitle AS WSTRING PTR = NULL, _
   BYVAL pwszStartFolder AS WSTRING PTR = NULL, BYVAL nFlags AS LONG = 0) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle to the parent window of the dialog box. This value can be zero. |
| *pwszTitle* | Optional. A string value that represents the title displayed inside the Browse dialog box. |
| *pwszStartFolder* | Optional.  The initial folder that the dialog will show. |
| *nFlags* | Optional. A LONG value that contains the options for the method. This can be zero or a combination of the values listed under the *ulFlags* member of the **BROWSEINFO** structure. |

| Flag       | Description |
| ---------- | ----------- |
| BIF_RETURNONLYFSDIRS | Only return file system directories. If the user selects folders that are not part of the file system, the OK button is grayed. |
| BIF_DONTGOBELOWDOMAIN | Do not include network folders below the domain level in the dialog box's tree view control. |
| BIF_STATUSTEXT | Include a status area in the dialog box. The callback function can set the status text by sending messages to the dialog box. This flag is not supported when BIF_NEWDIALOGSTYLE is specified. |
| BIF_RETURNFSANCESTORS | Only return file system ancestors. An ancestor is a subfolder that is beneath the root folder in the namespace hierarchy. If the user selects an ancestor of the root folder that is not part of the file system, the **OK** button is grayed. |
| BIF_EDITBOX | Version 4.71. Include an edit control in the browse dialog box that allows the user to type the name of an item. |
| BIF_NEWDIALOGSTYLE | Version 5.0. Use the new user interface. Setting this flag provides the user with a larger dialog box that can be resized. The dialog box has several new capabilities, including: drag-and-drop capability within the dialog box, reordering, shortcut menus, new folders, delete, and other shortcut menu commands. |
| BIF_USENEWUI | Version 5.0. Use the new user interface, including an edit box. This flag is equivalent to BIF_EDITBOX OR BIF_NEWDIALOGSTYLE. |
| BIF_UAHINT | Version 6.0. When combined with BIF_NEWDIALOGSTYLE, adds a usage hint to the dialog box, in place of the edit box. BIF_EDITBOX overrides this flag. |
| BIF_NONEWFOLDERBUTTON | Version 6.0. Do not include the **New Folder** button in the browse dialog box. |
| BIF_NOTRANSLATETARGETS | Version 6.0. When the selected item is a shortcut, return the PIDL of the shortcut itself rather than its target. |
| BIF_BROWSEFORCOMPUTER | Only return computers. If the user selects anything other than a computer, the **OK** button is grayed. |
| BIF_BROWSEFORPRINTER | Only allow the selection of printers. If the user selects anything other than a printer, the **OK** button is grayed. In Windows XP and later systems, the best practice is to use a Windows XP-style dialog, setting the root of the dialog to the Printers and Faxes folder (CSIDL_PRINTERS). |
| BIF_BROWSEINCLUDEFILES | Version 4.71. The browse dialog box displays files as well as folders. |
| BIF_SHAREABLE | Version 5.0. The browse dialog box can display shareable resources on remote systems. This is intended for applications that want to expose remote shares on a local system. The BIF_NEWDIALOGSTYLE flag must also be set. |
| BIF_BROWSEFILEJUNCTIONS | Windows 7 and later. Allow folder junctions such as a library or a compressed file with a .zip file name extension to be browsed. |

#### Notes

If COM is initialized through CoInitializeEx with the COINIT_MULTITHREADED flag set, **AfxShellBrowserForFolder** fails if BIF_NEWDIALOGSTYLE or BIF_USENEWUI are passed.

#### Return value

The path of the selected folder.

#### Remarks

If you don't pass any flags, the function will use BIF_RETURNONLYFSDIRS OR BIF_DONTGOBELOWDOMAIN OR BIF_USENEWUI OR BIF_RETURNFSANCESTORS.

#### Usage example

```
DIM dws AS DWSTRING = AfxBrowseForFolder(hwnd, "C:")
```
---

### AfxChooseColorDialog

Displays the Windows choose color dialog.

```
FUNCTION AfxChooseColorDialog (BYVAL hwnd AS HWND, BYVAL rgbDefaultColor AS COLORREF = 0, _
   BYVAL lpCustColors AS COLORREF PTR = NULL) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to the parent window or NULL. |
| *rgbDefaultColor* | The color initially selected when the dialog box is created. If the specified color value is not among the available colors, the system selects the nearest solid color available. If *rgbDefaultColor* is zero, the initially selected color is black. |
| *lpCustColors* | Out. A pointer to an array of 16 values that contain red, green, blue (RGB) values for the custom color boxes in the dialog box. If the user modifies these colors, the system updates the array with the new RGB values. To preserve new custom colors between calls to the **AfxChooseColorDialog** function, you should allocate static memory for the array. To create a COLORREF color value, use the BGR macro. |

#### Return value

The selected color, or -1 if the user has canceled the dialog.

---

### AfxControlRunDLL

Control_RunDLL is an undocumented procedure in the Shell32.dll which can be used to launch control panel applications. You’ve to pass the name of the control panel file (.cpl) and the tool represented by it will be launched. For launching some control panel applications, you’ve to provide a valid windows handle (hwnd parameter) and program instance (*hInst*) parameter).

```
FUNCTION AfxControlRunDLL (BYVAL hwnd AS HWND, BYVAL hInst AS HINSTANCE, _
   BYVAL cmd AS WSTRING PTR, BYVAL nCmdShow AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to a window. This parameter can be NULL. |
| *hInst* | Instance handle. This parameter can be NULL. |
| *cmd* | The command and parameters. |
| *nCmdShow* | Controls how the window is to be shown, e.g. SW_SHOWNORMAL. |

| nCmdShow value  | Description |
| --------------- | ----------- |
| SW_FORCEMINIMIZE | Minimizes a window, even if the thread that owns the window is not responding. This flag should only be used when minimizing windows from a different thread. |
| SW_HIDE | Hides the window and activates another window. |
| SW_MAXIMIZE | Maximizes the specified window. |
| SW_MINIMIZE | Minimizes the specified window and activates the next top-level window in the Z order. |
| SW_RESTORE | Activates and displays the window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window. |
| SW_SHOW | Activates the window and displays it in its current size and position. |
| SW_SHOWDEFAULT | Sets the show state based on the SW_ value specified in the STARTUPINFO structure passed to the **CreateProcess** function by the program that started the application. |
| SW_SHOWMAXIMIZED | Activates the window and displays it as a maximized window. |
| SW_SHOWMINIMIZED | Activates the window and displays it as a minimized window. |
| SW_SHOWMINNOACTIVE | Displays the window as a minimized window. This value is similar to SW_SHOWMINIMIZED, except the window is not activated. |
| SW_SHOWNA | Displays the window in its current size and position. This value is similar to SW_SHOW, except that the window is not activated. |
| SW_SHOWNOACTIVATE | Displays a window in its most recent size and position. This value is similar to SW_SHOWNORMAL, except that the window is not activated. |
| SW_SHOWNORMAL | Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time. |

#### Usage examples

```
AfxControlRunDLL(0, 0, "", SW_SHOWNORMAL)   ' Opens the control panel
AfxControlRunDLL(0, 0, "appwiz.cpl", SW_SHOWNORMAL)   ' Opens the applications wizard
```
---

### AfxOpenFileDialog

Creates an **Open** dialog box that lets the user specify the drive, directory, and the name of a file or set of files to be opened. The dialog box uses the Explorer-style user interface.

```
FUNCTION AfxOpenFileDialog (BYVAL hwndOwner AS HWND, BYREF wszTitle AS WSTRING, BYREF wszFile AS WSTRING, _
   BYREF wszInitialDir AS WSTRING, BYREF wszFilter AS WSTRING, BYREF wszDefExt AS WSTRING, _
   BYVAL pdwFlags AS DWORD PTR = NULL, BYVAL pdwBufLen AS DWORD PTR = NULL) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndOwner* | A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be NULL if the dialog box has no owner. |
| *wszTitle* | A string to be placed in the title bar of the dialog box. If this member is NULL, the system uses the default title (that is, **Open**). |
| *wszFile* | The file name used to initialize the **File Name** edit control. |
| *wszInitialDir* | The initial directory.  If no initial directory is specified, the dialog will use the current directory. |
| *wszFilter* | A buffer containing pairs of "\|" separated strings. The first string in each pair is a display string that describes the filter (for example, "Text Files"), and the second string specifies the filter pattern (for example, "\*.TXT"). To specify multiple filter patterns for a single display string, use a semicolon to separate the patterns (for example, "\*.TXT;\*.DOC;\*.BAK"). A pattern string can be a combination of valid file name characters and the asterisk (\*) wildcard character. Do not include spaces in the pattern string. The system does not change the order of the filters. It displays them in the **File Types** combo box in the order specified in *wszFilter*. |
| *wszDefExt* | The default extension. This extension is appended to the file name if the user fails to type an extension. This string can be any length, but only the first three characters are appended. The string should not contain a period (.). If this member is NULL and the user fails to type an extension, no extension is appended. |
| *pdwFlags* | \[in, out, optional] A set of bit flags you can use to initialize the dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be a combination of the following flags. |
| *pdwBufLen* | \[in, out, optional] Maximum length of the returned string containing the selected file or files. |

| Flag       | Description |
| ---------- | ----------- |
| OFN_ALLOWMULTISELECT | The **File Name** list box allows multiple selections. |
| OFN_DONTADDTORECENT | Prevents the system from adding a link to the selected file in the file system directory that contains the user's most recently used documents. To retrieve the location of this directory, call the **SHGetSpecialFolderLocation** function with the CSIDL_RECENT flag. |
| OFN_EXTENSIONDIFFERENT | The user typed a file name extension that differs from the extension specified by *wszDefExt*. The function does not use this flag if *wszDefExt* is NULL. |
| OFN_FILEMUSTEXIST | The user can type only names of existing files in the **File Name** entry field. If this flag is specified and the user enters an invalid name, the dialog box procedure displays a warning in a message box. If this flag is specified, the OFN_PATHMUSTEXIST flag is also used. |
| OFN_FORCESHOWHIDDEN | Forces the showing of system and hidden files, thus overriding the user setting to show or not show hidden files. However, a file that is marked both system and hidden is not shown. |
| OFN_HIDEREADONLY | Hides the **Read Only** check box. |
| OFN_NODEREFERENCELINKS | Directs the dialog box to return the path and file name of the selected shortcut (.LNK) file. If this value is not specified, the dialog box returns the path and file name of the file referenced by the shortcut. |
| OFN_NONETWORKBUTTON | Hides and disables the **Network** button. |
| OFN_NOREADONLYRETURN | The returned file does not have the **Read Only** check box selected and is not in a write-protected directory. |
| OFN_PATHMUSTEXIST | The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the **File Name** entry field, the dialog box function displays a warning in a message box. |
| OFN_READONLY | Causes the **Read Only** check box to be selected initially when the dialog box is created. This flag indicates the state of the **Read Only** check box when the dialog box is closed. |
| OFN_SHOWHELP | Causes the dialog box to display the **Help** button. The *hwndOwner* member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the **Help** button. |

#### Return value

If the OFN_ALLOWMULTISELECT flag is set and the user selects multiple files, the returned string contains the current directory followed by the file names of the selected files. For Explorer-style dialog boxes, the directory and file name strings are separated by semicolons. If the user selects only one file, the returned string does not have a separator between the path and file name.

Parse the number of ",". If only one, then the user has selected only a file and the string contains the full path. If more, The first substring contains the path and the others the files. If the user has not selected any file, an empty string is returned. On failure, an empty string is returned and, if not null, the pdwBufLen parameter will be filled by the size of the required buffer in characters.

#### Usage example:

```
DIM wszFile AS WSTRING * 260 = "*.*"
DIM wszInitialDir AS STRING * 260 = CURDIR
DIM wszFilter AS WSTRING * 260 = "BAS files (*.BAS)|*.BAS|" & "All Files (*.*)|*.*|"
DIM dwFlags AS DWORD = OFN_EXPLORER OR OFN_FILEMUSTEXIST OR OFN_HIDEREADONLY OR OFN_ALLOWMULTISELECT
DIM dws AS DWSTRING = AfxOpenFileDialog(hwnd, "", wszFile, wszInitialDir, wszFilter, "BAS", @dwFlags, NULL)
```
---

### AfxSaveFileDialog

Creates a **Save** dialog box that lets the user specify the drive, directory, and name of a file to save. The dialog box uses the Explorer-style user interface.

```
FUNCTION AfxSaveFileDialog (BYVAL hwndOwner AS HWND, BYREF wszTitle AS WSTRING, BYREF wszFile AS WSTRING, _
   BYREF wszInitialDir AS WSTRING, BYREF wszFilter AS WSTRING, BYREF wszDefExt AS WSTRING, _
   BYVAL pdwFlags AS DWORD PTR = NULL) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndOwner* | A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be NULL if the dialog box has no owner. |
| *wszTitle* | A string to be placed in the title bar of the dialog box. If this member is NULL, the system uses the default title (that is, **Save As**). |
| *wszFile* | The file name used to initialize the **File Name** edit control. |
| *wszInitialDir* | The initial directory.  If no initial directory is specified, the dialog will use the current directory. |
| *wszFilter* | A buffer containing pairs of "\|" separated strings. The first string in each pair is a display string that describes the filter (for example, "Text Files"), and the second string specifies the filter pattern (for example, "\*.TXT"). To specify multiple filter patterns for a single display string, use a semicolon to separate the patterns (for example, "\*.TXT;\*.DOC;\*.BAK"). A pattern string can be a combination of valid file name characters and the asterisk (\*) wildcard character. Do not include spaces in the pattern string. The system does not change the order of the filters. It displays them in the **File Types** combo box in the order specified in *wszFilter*. |
| *wszDefExt* | The default extension. This extension is appended to the file name if the user fails to type an extension. This string can be any length, but only the first three characters are appended. The string should not contain a period (.). If this member is NULL and the user fails to type an extension, no extension is appended. |
| *pdwFlags* | \[in, out, optional] A set of bit flags you can use to initialize the dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be a combination of the following flags. |

| Flag       | Description |
| ---------- | ----------- |
| OFN_CREATEPROMPT | If the user specifies a file that does not exist, this flag causes the dialog box to prompt the user for permission to create the file. If the user chooses to create the file, the dialog box closes and the function returns the specified name; otherwise, the dialog box remains open. |
| OFN_DONTADDTORECENT | Prevents the system from adding a link to the selected file in the file system directory that contains the user's most recently used documents. To retrieve the location of this directory, call the **SHGetSpecialFolderLocation** function with the CSIDL_RECENT flag. |
| OFN_EXTENSIONDIFFERENT | The user typed a file name extension that differs from the extension specified by *wszDefExt*. The function does not use this flag if *wszDefExt* is NULL. |
| OFN_FORCESHOWHIDDEN | Forces the showing of system and hidden files, thus overriding the user setting to show or not show hidden files. However, a file that is marked both system and hidden is not shown. |
| OFN_HIDEREADONLY | Hides the **Read Only** check box |
| OFN_NOCHANGEDIR | Restores the current directory to its original value if the user changed the directory while searching for files. |
| OFN_NODEREFERENCELINKS | Directs the dialog box to return the path and file name of the selected shortcut (.LNK) file. If this value is not specified, the dialog box returns the path and file name of the file referenced by the shortcut. |
| OFN_NOTESTFILECREATE | The file is not created before the dialog box is closed. This flag should be specified if the application saves the file on a create-nonmodify network share. When an application specifies this flag, the library does not check for write protection, a full disk, an open drive door, or network protection. Applications using this flag must perform file operations carefully, because a file cannot be reopened once it is closed. |
| OFN_NONETWORKBUTTON | Hides and disables the **Network** button. |
| OFN_NOREADONLYRETURN | The returned file does not have the **Read Only** check box selected and is not in a write-protected directory. |
| OFN_OVERWRITEPROMPT | The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the **File Name** entry field, the dialog box function displays a warning in a message box. |
| OFN_PATHMUSTEXIST | The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the **File Name** entry field, the dialog box function displays a warning in a message box. |
| OFN_SHOWHELP | Causes the dialog box to display the **Help** button. The hwndOwner member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the **Help** button. |

#### Return value

The path of the file to be saved.

#### Usage example:

```
DIM wszFile AS WSTRING * 260 = "*.*"
DIM wszInitialDir AS STRING * 260 = CURDIR
DIM wszFilter AS WSTRING * 260 = "BAS files (*.BAS)|*.BAS|" & "All Files (*.*)|*.*|"
DIM dwFlags AS DWORD = OFN_EXPLORER OR OFN_FILEMUSTEXIST OR OFN_HIDEREADONLY OR OFN_OVERWRITEPROMPT
DIM dws AS DWSTRING = AfxSaveFileDialog(hwnd, "", wszFile, wszInitialDir, wszFilter, "BAS", @dwFlags)
```
---

### AfxShowSysInfo

Displays the Windows Information System dialog.

```
FUNCTION AfxShowSysInfo (BYVAL hwnd AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to the parent window or NULL. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE.

---

### AfxGetMonitorHorizontalScaling

Returns the horizontal scaling of the monitor that the window is currently displayed on.

```
FUNCTION AfxGetMonitorHorizontalScaling (BYVAL hwnd AS HWND = NULL) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. A handle to the window. If NULL, the desktop window handle will be used. |

#### Remarks

If the application to which the window belongs is not DPI aware, a computer using 192 DPI, will return an scaling ratio of 2.

---

### AfxGetMonitorVerticalScaling

Returns the vertical scaling of the monitor that the window is currently displayed on.

```
FUNCTION AfxGetMonitorVerticalScaling (BYVAL hwnd AS HWND = NULL) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. A handle to the window. If NULL, the desktop window handle will be used. |

#### Remarks

If the application to which the window belongs is not DPI aware, a computer using 192 DPI, will return an scaling ratio of 2.

---

### AfxGetMonitorLogicalHeight

Returns the logical height of the monitor that the window is currently displayed on.

```
FUNCTION AfxGetMonitorLogicalHeight (BYVAL hwnd AS HWND = NULL) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. A handle to the window. If NULL, the desktop window handle will be used. |

#### Remarks

If the application to which the window belongs is not DPI aware, a monitor with an height resolution of 1080 pixels in a computer using 192 DPI, will return 540 pixels.

---

### AfxGetMonitorLogicalWidth

Returns the logical width of the monitor that the window is currently displayed on.

```
FUNCTION AfxGetMonitorLogicalWidth (BYVAL hwnd AS HWND = NULL) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. A handle to the window. If NULL, the desktop window handle will be used. |

#### Remarks

If the application to which the window belongs is not DPI aware, a monitor with a width resolution of 1920 pixels in a computer using 192 DPI, will return 960 pixels.

---

### AfxIsDPIResolutionAtLeast

Determines if screen resolution meets minimum requirements in relative pixels, e.g. for a screen resolution of 1920x1080 pixels and a DPI of 192 (scaling ratio = 2), the maximum relative pixels for a DPI aware application is 960x540.

```
FUNCTION AfxIsDPIResolutionAtLeast (BYVAL cxMin AS LONG, BYVAL cyMin AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *cxMin* | Minimum screen resolution width in relative pixels. |
| *cyMin* | Minimum screen resolution height in relative pixels. |

#### Return value

TRUE or FALSE.

### AfxIsProcessDPIAware

Determines whether the current process is dots per inch (dpi) aware such that it adjusts the sizes of UI elements to compensate for the dpi setting.

```
FUNCTION AfxIsProcessDPIAware () AS BOOLEAN
```

#### Return value

TRUE if the process is dpi aware; otherwise, FALSE.

---

### AfxIsResolutionAtLeast

Determines if screen resolution meets minimum requirements.

```
FUNCTION AfxIsResolutionAtLeast (BYVAL cxMin AS LONG, BYVAL cyMin AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *cxMin* | Minimum screen resolution width in relative pixels. |
| *cyMin* | Minimum screen resolution height in relative pixels. |

#### Return value

TRUE or FALSE.

---

### AfxLoadIconMetric

Loads a specified icon resource with a client-specified system metric.

```
FUNCTION AfxLoadIconMetric (BYVAL hinst AS HINSTANCE, BYVAL pwszName AS WSTRING PTR, _
   BYVAL lims AS LONG, BYVAL phico AS HICON PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hinst* | A handle to the module of either a DLL or executable (.exe) file that contains the icon to be loaded. For more information, see **GetModuleHandle**. To load a predefined icon or a standalone icon file, set this parameter to NULL. |
| *pwszName* | A pointer to a null-terminated, Unicode buffer that contains location information about the icon to load. It is interpreted as follows: If *hinst* is NULL, *pwszName* can specify one of two things.<br>1) The identifier of a predefined icon to load. These identifiers are recognized: IDI_APPLICATION, IDI_INFORMATION, IDI_ERROR, IDI_WARNING, IDI_SHIELD, IDI_QUESTION.<br>To pass these constants to the **AfxLoadIconMetric** function, use the MAKEINTRESOURCE macro. For example, to load the IDI_ERROR icon, pass MAKEINTRESOURCE(IDI_ERROR) as the *pwszName* parameter and NULL as the *hinst* parameter.<br>2) The name of a standalone icon (.ico) file.<br>If hinst is non-null, *pwszName* can specify one of two things.<br>1) The name of the icon resource, if the icon resource is to be loaded by name from the module.<br>2) The icon ordinal, if the icon resource is to be loaded by ordinal from the module. This ordinal must be packaged by using the MAKEINTRESOURCE macro. |
| *lims* | The desired metric. One of the following values:<br>**LIM_SMALL** : Corresponds to SM_CXSMICON, the recommended pixel width of a small icon.<br>**LIM_LARGE** : Corresponds to SM_CXICON, the default pixel width of an icon. |
| *phico* | When this function returns, contains a pointer to the handle of the loaded icon. |

#### Return value

Returns S_OK if successful, otherwise an error, including the following value: *E_INVALIDARG* : The contents of the buffer pointed to by pszName do not fit any of the expected interpretations.

#### Remarks

**LoadIconMetric** is similar to **LoadIcon**, but with the capability to specify the icon metric. It is used in place of **LoadIcon** when the calling application wants to ensure a high quality icon. This is particularly useful in high dots per inch (dpi) situations.

Icons are extracted or created as follows.

1) If an exact size match is found in the resource, that icon is used.<br>
2) If an exact size match cannot be found and a larger icon is available, a new icon is created by scaling the larger version down to the desired size.<br>
3) If an exact size match cannot be found and no larger icon is available, a new icon is created by scaling a smaller icon up to the desired size.

---

### AfxLogPixelsX

Retrieves the number of pixels per logical inch along the screen width. In a system with multiple display monitors, this value is the same for all monitors. Aliases: **AfxGetDpi**, **AfxGetDpiX**.

```
FUNCTION AfxLogPixelsX () AS LONG
FUNCTION AfxGetDpi () AS LONG
FUNCTION AfxGetDpiX () AS LONG
```
---

### AfxLogPixelsY

Retrieves the number of pixels per logical inch along the screen height. In a system with multiple display monitors, this value is the same for all monitors. Alias: **AfxGetDpiY**.

```
FUNCTION AfxLogPixelsY () AS LONG
FUNCTION AfxGetDpiY () AS LONG
```
---

### AfxScaleRatioX

Retrieves the desktop horizontal scaling ratio.

```
FUNCTION AfxScaleRatioX () AS LONG
```
---

### AfxScaleRatioY

Retrieves the desktop vertical scaling ratio.

```
FUNCTION AfxScaleRatioY () AS LONG
```
---

### AfxScaleX

Scales an horizontal coordinate according the DPI (dots per pixel) being used by the operating system.

```
FUNCTION AfxScaleX (BYVAL cx AS SINGLE) AS SINGLE
```

#### Return value

The scaled coordinate.

---

### AfxScaleY

Scales a vertical coordinate according the DPI (dots per pixel) being used by the operating system.

```
FUNCTION AfxScaleY (BYVAL cx AS SINGLE) AS SINGLE
```

#### Return value

The scaled coordinate.

---

### AfxSetProcessDPIAware

Sets the current process as dots per inch (dpi) aware.

Note: **AfxSetProcessDPIAware** is subject to a possible race condition if a DLL caches dpi settings during initialization. For this reason, it is recommended that dpi-aware be set through the application (.exe) manifest rather than by calling **AfxSetProcessDPIAware**.

```
FUNCTION AfxSetProcessDPIAware () AS BOOLEAN
```

#### Return value

If the function succeeds, the return value is TRUE. Otherwise, the return value is FALSE.

#### Remarks

DLLs should accept the dpi setting of the host process rather than call **AfxSetProcessDPIAware** themselves. To be set properly, *dpiAware* should be specified as part of the application (.exe) manifest. (*dpiAware* defined in an embedded DLL manifest has no affect.) The following markup shows how to set *dpiAware* as part of an application (.exe) manifest.

```
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0" xmlns:asmv3="urn:schemas-microsoft-com:asm.v3" >
 ...
  <asmv3:application>
    <asmv3:windowsSettings xmlns="http://schemas.microsoft.com/SMI/2005/WindowsSettings">
      <dpiAware>true</dpiAware>
    </asmv3:windowsSettings>
  </asmv3:application>
 ...
</assembly>
```

### AfxUnscaleX

Unscales an horizontal coordinate according the DPI (dots per pixel) being used by the operating system.

```
FUNCTION AfxUnscaleX (BYVAL cx AS SINGLE) AS SINGLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cx* | The value of the horizontal coordinate, in pixels. |

#### Return value

The unscaled coordinate.

---

### AfxUnscaleY

Unscales a vertical coordinate according the DPI (dots per pixel) being used by the operating system.

```
FUNCTION AfxUnscaleY (BYVAL cx AS SINGLE) AS SINGLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cy* | The value of the vertical coordinate, in pixels. |

#### Return value

The unscaled coordinate.

---

### AfxUseDpiScaling

Returns TRUE if the OS uses DPI scaling; FALSE otherwise.

```
FUNCTION AfxUseDpiScaling () AS BOOLEAN
```
---

### AfxCreateFont

Creates a logical font.

```
FUNCTION AfxCreateFont (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, BYVAL DPI AS LONG = 96, _
   BYVAL lWeight AS LONG = 0, BYVAL bItalic AS UBYTE = FALSE, BYVAL bUnderline AS UBYTE = FALSE, _
   BYVAL bStrikeOut AS UBYTE = FALSE, BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS HFONT
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFaceName* | The typeface name. |
| *lPointSize* | The point size. |
| *DPI* | Dots per inch to calculate scaling. Default value = 96 (no scaling). If you pass -1 and the application is DPI aware, the DPI value used by the operating system will be used. |
| *lWeight* | Initial weight of the font. If the weight is below 550 (the average of FW_NORMAL, 400, and FW_BOLD, 700), then the Bold property is also initialized to FALSE. If the weight is above 550, the Bold property is set to TRUE.<br>The following values are defined for convenience: FW_DONTCARE (0), FW_THIN (100), FW_EXTRALIGHT (200), FW_ULTRALIGHT (200), FW_LIGHT (300), FW_NORMAL (400), FW_REGULAR (400), FW_MEDIUM (500), FW_SEMIBOLD (600), FW_DEMIBOLD (600), FW_BOLD (700), FW_EXTRABOLD (800), FW_ULTRABOLD (800), FW_HEAVY (900), FW_BLACK (900) |
| *bItalic* | Italic flag. CTRUE or FALSE. |
| *bUnderline* | Underline flag. CTRUE or FALSE. |
| *bStrikeOut* | StrikeOut flag. CTRUE or FALSE |
| *bCharSet* | Specifies the character set. The following values are predefined:<br>ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET, DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET, MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET.<br>Korean Windows: JOHAB_CHARSET.<br>Middle-Eastern Windows: HEBREW_CHARSET, ARABIC_CHARSET.<br>Thai Windows: THAI_CHARSET.<br>The OEM_CHARSET value specifies a character set that is operating-system dependent. DEFAULT_CHARSET is set to a value based on the current system locale. For example, when the system locale is English (United States), it is set as ANSI_CHARSET. Fonts with other character sets may exist in the operating system. If an application uses a font with an unknown character set, it should not attempt to translate or interpret strings that are rendered with that font. This parameter is important in the font mapping process. To ensure consistent results, specify a specific character set. If you specify a typeface name in the *wszFaceName* parameter, make sure that the *bCharSet* value matches the character set of the typeface specified in *wszFaceName*. |

#### Return value

The handle of the font or NULL on failure.

#### Remarks

The returned font must be destroyed with **DeleteObject** or the macro **DeleteFont** when no longer needed to prevent memory leaks.

#### Usage examples

```
hFont = AfxCreateFont("MS Sans Serif", 8, , FW_NORMAL, , , , DEFAULT_CHARSET)
hFont = AfxCreateFont("Courier New", 10, 96 , FW_BOLD, , , , DEFAULT_CHARSET)
hFont = AfxCreateFont("Marlett", 8, -1, FW_NORMAL, , , , SYMBOL_CHARSET)
```
---

### AfxGetFontHeight

Returns the logical height of a font given its point size.

```
FUNCTION AfxGetFontHeight (BYVAL nPointSize AS LONG) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *nPointSize* | The point size of the font. |

---

### AfxGetFontPointSize

Returns the point size of a font given its logical height.

```
FUNCTION AfxGetFontPointSize (BYVAL nHeight AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nHeight* | The logical height of the font. |

---

### AfxGetWindowFont

Retrieves the font with which the window or control is currently drawing its text.

```
FUNCTION AfxGetWindowFont (BYVAL hwnd AS HWND) AS HFONT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to a window or control. |

#### Return value

The handle of the font.

---

### AfxGetWindowFontInfo

Retrieves information about the font being used by a window or control.

```
FUNCTION AfxGetWindowFontInfo (BYVAL hwnd AS HWND) AS LOGFONTW
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to a window or control. |

#### Return value

A LOGFONTW structure.

---

### AfxGetWindowsFontInfo

Retrieves information about the fonts used by Windows.

```
FUNCTION AfxGetWindowsFontInfo (BYVAL nType AS LONG, BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *nType* | The type of the font: AFX_FONT_CAPTION, AFX_FONT_SMALLCAPTION, AFX_FONT_MENU, AFX_FONT_STATUS, AFX_FONT_MESSAGE. |
| *plfw* | Pointer to a LOGFONTW structure that receives the font information. |

#### Return value

TRUE on succes or FALSE on failure. To get extended error information, call **GetLastError**.

---

### AfxGetWindowsFontPointSize

Retrieves the point size of the fonts used by Windows.

```
FUNCTION AfxGetWindowsFontPointSize (BYVAL nType AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nType* | The type of the font: AFX_FONT_CAPTION, AFX_FONT_SMALLCAPTION, AFX_FONT_MENU, AFX_FONT_STATUS, AFX_FONT_MESSAGE. |

---

### AfxModifyFontFaceName

Modifies the face name of the font of a window or control.

```
FUNCTION AfxModifyFontFaceName (BYVAL hwnd AS HWND, BYREF wszNewFaceName AS WSTRING) AS HFONT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *wszNewFaceName* | The new face name of the font. |

#### Return value

The handle of the new font on success, or NULL on failure.

To get extended error information call **GetLastError**.

#### Remarks

The returned font must be destroyed with **DeleteObject** or the macro **DeleteFont** when no longer needed to prevent memory leaks.

---

### AfxModifyFontHeight

Modifies the height of the font used by a window of control.

```
FUNCTION AfxModifyFontHeight (BYVAL hwnd AS HWND, BYVAL nValue AS LONG) AS HFONT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *nValue* | The base is 100. To increase the font a 20% pass 120; to reduce it a 20% pass 80%. |

#### Return value

The handle of the new font on success, or NULL on failure.

To get extended error information call **GetLastError**.

#### Remarks

The returned font must be destroyed with **DeleteObject** or the macro **DeleteFont** when no longer needed to prevent memory leaks.

---

### AfxModifyFontSettings

Modifies settings of the font used by a window of control.

```
FUNCTION AfxModifyFontSettings (BYVAL hwnd AS HWND, BYVAL nSetting AS LONG, BYVAL nValue AS LONG) AS HFONT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *nSetting* | One of the AFX_FONT_xxx constants (see below). |
| *nValue* | Depends of the nSetting value. **AFX_FONT_HEIGHT** : The base is 100. To increase the font a 20% pass 120; to reduce it a 20% pass 80%.<br>**AFX_FONT_WEIGHT** : The weight of the font in the range 0 through 1000. For example, 400 is normal and  700 is bold. If this value is zero, a default weight is used. The following values are defined for convenience. FW_DONTCARE (0), FW_THIN (100), FW_EXTRALIGHT (200), FW_ULTRALIGHT (200), FW_LIGHT (300), FW_NORMAL (400), FW_REGULAR (400), FW_MEDIUM (500), FW_SEMIBOLD (600), FW_DEMIBOLD (600), FW_BOLD (700), FW_EXTRABOLD (800), FW_ULTRABOLD (800), FW_HEAVY (900), FW_BLACK (900)<br>**AFX_FONT_ITALIC** : TRUE or FALSE.<br>**AFX_FONT_UNDERLINE** : TRUE or FALSE.<br>**AFX_FONT_STRIKEOUT** : TRUE or FALSE.<br>**AFX_FONT_CHARSET**: The following values are predefined: ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET, DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET, MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET, VIETNAMESE_CHARSET, JOHAB_CHARSET (Korean language edition of Windows), ARABIC_CHARSET and HEBREW_CHARSET (Middle East language edition of Windows), THAI_CHARSET (Thai language edition of Windows). The OEM_CHARSET value specifies a character set that is operating-system dependent. DEFAULT_CHARSET is set to a value based on the current system locale. For example, when the system locale is English (United States), it is set as ANSI_CHARSET. |

#### Return value

The handle of the new font on success, or NULL on failure.

To get extended error information call **GetLastError**.

#### Remarks

The returned font must be destroyed with **DeleteObject** or the macro **DeleteFont** when no longer needed to prevent memory leaks.

### AfxSetWindowFont

Sets the font that a control is to use when drawing text.

```
SUB AfxSetWindowFont (BYVAL hwnd AS HWND, BYVAL hFont AS HFONT, BYVAL fRedraw AS LONG = CTRUE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *hFont* | A handle to the font. If this parameter is NULL, the control uses the default system font to draw text. |
| *fRedraw* | Optional. Specifies whether the control should be redrawn immediately upon setting the font. If this parameter is CTRUE, the control redraws itself. |

#### Return value

The handle of the new font on success, or NULL on failure.

To get extended error information call **GetLastError**.

#### Remarks

The application should call the **DeleteObject** function to delete the font when it is no longer needed; for example, after it destroys the control.

The size of the control does not change as a result of receiving this message. To avoid clipping text that does not fit within the boundaries of the control, the application should correct the size of the control window before it sets the font.

---

### AfxClearClipboard

Clears the contents of the clipboard.

```
FUNCTION AfxClearClipboard () AS LONG
```

#### Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.

---

### AfxGetClipboardData

Retrieves data from the clipboard in the specified format.

```
FUNCTION AfxGetClipboardData (BYVAL cfFormat AS DWORD) AS HGLOBAL
```

| Parameter  | Description |
| ---------- | ----------- |
| *cfFormat* | The clipboard format. This parameter can be a registered format or any of the standard clipboard formats. |

Standard clipboard formats:

| Constant/Value  | Description |
| --------------- | ----------- |
| CF_BITMAP | A handle to a bitmap. |
| CF_DIB | A memory object containing a BITMAPINFO structure followed by the bitmap bits. |
| CF_DIBV5 | A memory object containing a BITMAPV5HEADER structure followed by the bitmap color space information and the bitmap bits. |
| CF_DIF | Software Arts' Data Interchange Format. |
| CF_DSPBITMAP | Bitmap display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in bitmap format in lieu of the privately formatted data. |
| CF_DSPENHMETAFILE | Enhanced metafile display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in enhanced metafile format in lieu of the privately formatted data. |
| CF_DSPMETAFILEPICT | Metafile-picture display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in metafile-picture format in lieu of the privately formatted data. |
| CF_DSPTEXT | Text display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in text format in lieu of the privately formatted data. |
| CF_ENHMETAFILE | A handle to an enhanced metafile. |
| CF_GDIOBJFIRST | Start of a range of integer values for application-defined GDI object clipboard formats. The end of the range is CF_GDIOBJLAST. Handles associated with clipboard formats in this range are not automatically deleted using the **GlobalFree** function when the clipboard is emptied. Also, when using values in this range, the hMem parameter is not a handle to a GDI object, but is a handle allocated by the **GlobalAlloc** function with the GMEM_MOVEABLE flag. |
| CF_GDIOBJLAST | See CF_GDIOBJFIRST. |
| CF_HDROP | A handle that identifies a list of files. An application can retrieve information about the files by passing the handle to the **DragQueryFile** function. |
| CF_LOCALE | The data is a handle to the locale identifier associated with text in the clipboard. When you close the clipboard, if it contains CF_TEXT data but no CF_LOCALE data, the system automatically sets the CF_LOCALE format to the current input language. You can use the CF_LOCALE format to associate a different locale with the clipboard text.<br>An application that pastes text from the clipboard can retrieve this format to determine which character set was used to generate the text.<br>Note that the clipboard does not support plain text in multiple character sets. To achieve this, use a formatted text data type such as RTF instead.<br>The system uses the code page associated with CF_LOCALE to implicitly convert from CF_TEXT to CF_UNICODETEXT. Therefore, the correct code page table is used for the conversion. |
| CF_METAFILEPICT | Handle to a metafile picture format as defined by the **METAFILEPICT** structure. When passing a CF_METAFILEPICT handle by means of DDE, the application responsible for deleting hMem should also free the metafile referred to by the CF_METAFILEPICT handle. |
| CF_OEMTEXT | Text format containing characters in the OEM character set. Each line ends with a carriage return/linefeed (CR-LF) combination. A null character signals the end of the data. |
| CF_OWNERDISPLAY | Owner-display format. The clipboard owner must display and update the clipboard viewer window, and receive the WM_ASKCBFORMATNAME, WM_HSCROLLCLIPBOARD, WM_PAINTCLIPBOARD, WM_SIZECLIPBOARD, and WM_VSCROLLCLIPBOARD messages. The *hMem* parameter must be NULL. |
| CF_PALETTE | Handle to a color palette. Whenever an application places data in the clipboard that depends on or assumes a color palette, it should place the palette on the clipboard as well.<br>If the clipboard contains data in the CF_PALETTE (logical color palette) format, the application should use the** SelectPalette** and **RealizePalette** functions to realize (compare) any other data in the clipboard against that logical palette.<br>When displaying clipboard data, the clipboard always uses as its current palette any object on the clipboard that is in the CF_PALETTE format. |
| CF_PENDATA | Data for the pen extensions to the Microsoft Windows for Pen Computing. |
| CF_PRIVATEFIRST | Start of a range of integer values for private clipboard formats. The range ends with CF_PRIVATELAST. Handles associated with private clipboard formats are not freed automatically; the clipboard owner must free such handles, typically in response to the WM_DESTROYCLIPBOARD message. |
| CF_PRIVATELAST | See CF_PRIVATEFIRST. |
| CF_RIFF | Represents audio data more complex than can be represented in a CF_WAVE standard wave format. |
| CF_SYLK | Microsoft Symbolic Link (SYLK) format. |
| CF_TEXT | Text format. Each line ends with a carriage return/linefeed (CR-LF) combination. A null character signals the end of the data. Use this format for ANSI text. |
| CF_TIFF | Tagged-image file format. |
| CF_UNICODETEXT | Unicode text format. Each line ends with a carriage return/linefeed (CR-LF) combination. A null character signals the end of the data. |
| CF_WAVE | Represents audio data in one of the standard wave formats, such as 11 kHz or 22 kHz PCM. |

#### Return value

If the function succeeds, the return value is the handle to the data. If the function fails, the return value is NULL.

### AfxGetClipboardText

Returns a text string from the clipboard.

```
FUNCTION AfxGetClipboardText () AS DWSTRING
```

#### Return value

The retrieved text string.

---

### AfxSetClipboardData

Places data on the clipboard in a specified clipboard format.

```
FUNCTION AfxSetClipboardData (BYVAL cfFormat AS DWORD, BYVAL hData AS HANDLE) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cfFormat* | The clipboard format. This parameter can be a registered format or any of the standard clipboard formats. |
| *hData* | Handle to the data in the specified format. |

Standard clipboard formats:

| Constant/Value  | Description |
| --------------- | ----------- |
| CF_BITMAP | A handle to a bitmap. |
| CF_DIB | A memory object containing a BITMAPINFO structure followed by the bitmap bits. |
| CF_DIBV5 | A memory object containing a BITMAPV5HEADER structure followed by the bitmap color space information and the bitmap bits. |
| CF_DIF | Software Arts' Data Interchange Format. |
| CF_DSPBITMAP | Bitmap display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in bitmap format in lieu of the privately formatted data. |
| CF_DSPENHMETAFILE | Enhanced metafile display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in enhanced metafile format in lieu of the privately formatted data. |
| CF_DSPMETAFILEPICT | Metafile-picture display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in metafile-picture format in lieu of the privately formatted data. |
| CF_DSPTEXT | Text display format associated with a private format. The *hMem* parameter must be a handle to data that can be displayed in text format in lieu of the privately formatted data. |
| CF_ENHMETAFILE | A handle to an enhanced metafile. |
| CF_GDIOBJFIRST | Start of a range of integer values for application-defined GDI object clipboard formats. The end of the range is CF_GDIOBJLAST. Handles associated with clipboard formats in this range are not automatically deleted using the **GlobalFree** function when the clipboard is emptied. Also, when using values in this range, the hMem parameter is not a handle to a GDI object, but is a handle allocated by the **GlobalAlloc** function with the GMEM_MOVEABLE flag. |
| CF_GDIOBJLAST | See CF_GDIOBJFIRST. |
| CF_HDROP | A handle that identifies a list of files. An application can retrieve information about the files by passing the handle to the **DragQueryFile** function. |
| CF_LOCALE | The data is a handle to the locale identifier associated with text in the clipboard. When you close the clipboard, if it contains CF_TEXT data but no CF_LOCALE data, the system automatically sets the CF_LOCALE format to the current input language. You can use the CF_LOCALE format to associate a different locale with the clipboard text.<br>An application that pastes text from the clipboard can retrieve this format to determine which character set was used to generate the text.<br>Note that the clipboard does not support plain text in multiple character sets. To achieve this, use a formatted text data type such as RTF instead.<br>The system uses the code page associated with CF_LOCALE to implicitly convert from CF_TEXT to CF_UNICODETEXT. Therefore, the correct code page table is used for the conversion. |
| CF_METAFILEPICT | Handle to a metafile picture format as defined by the **METAFILEPICT** structure. When passing a CF_METAFILEPICT handle by means of DDE, the application responsible for deleting hMem should also free the metafile referred to by the CF_METAFILEPICT handle. |
| CF_OEMTEXT | Text format containing characters in the OEM character set. Each line ends with a carriage return/linefeed (CR-LF) combination. A null character signals the end of the data. |
| CF_OWNERDISPLAY | Owner-display format. The clipboard owner must display and update the clipboard viewer window, and receive the WM_ASKCBFORMATNAME, WM_HSCROLLCLIPBOARD, WM_PAINTCLIPBOARD, WM_SIZECLIPBOARD, and WM_VSCROLLCLIPBOARD messages. The *hMem* parameter must be NULL. |
| CF_PALETTE | Handle to a color palette. Whenever an application places data in the clipboard that depends on or assumes a color palette, it should place the palette on the clipboard as well.<br>If the clipboard contains data in the CF_PALETTE (logical color palette) format, the application should use the** SelectPalette** and **RealizePalette** functions to realize (compare) any other data in the clipboard against that logical palette.<br>When displaying clipboard data, the clipboard always uses as its current palette any object on the clipboard that is in the CF_PALETTE format. |
| CF_PENDATA | Data for the pen extensions to the Microsoft Windows for Pen Computing. |
| CF_PRIVATEFIRST | Start of a range of integer values for private clipboard formats. The range ends with CF_PRIVATELAST. Handles associated with private clipboard formats are not freed automatically; the clipboard owner must free such handles, typically in response to the WM_DESTROYCLIPBOARD message. |
| CF_PRIVATELAST | See CF_PRIVATEFIRST. |
| CF_RIFF | Represents audio data more complex than can be represented in a CF_WAVE standard wave format. |
| CF_SYLK | Microsoft Symbolic Link (SYLK) format. |
| CF_TEXT | Text format. Each line ends with a carriage return/linefeed (CR-LF) combination. A null character signals the end of the data. Use this format for ANSI text. |
| CF_TIFF | Tagged-image file format. |
| CF_UNICODETEXT | Unicode text format. Each line ends with a carriage return/linefeed (CR-LF) combination. A null character signals the end of the data. |
| CF_WAVE | Represents audio data in one of the standard wave formats, such as 11 kHz or 22 kHz PCM. |

#### Return value

If the function succeeds, the return value is the handle to the data. If the function fails, the return value is NULL.

#### Remarks

If **AfxSetClipboardData** succeeds, the system owns the object identified by the *hData* parameter. The application may not write to or free the data once ownership has been transferred to the system.

---

### AfxSetClipboardText

Places a text string into the clipboard.

```
FUNCTION AfxSetClipboardText (BYREF wszText AS WSTRING) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszText* | The text to be placed in the clipboard. |

#### Return value

If the function succeeds, the return value is the handle to the data. If the function fails, the return value is NULL.

---

### AfxCaptureDisplay

Captures the display and returns an handle to a bitmap.

```
FUNCTION AfxCaptureDisplay () AS HBITMAP
```

#### Return value

The handle of a bitmap.

#### Usage example

```
DIM hBitmap AS HBITMAP = AfxCaptureDisplay
```
---

### AfxGetBitmapHeight

Retrieves the height of the specified bitmap.

```
FUNCTION AfxGetBitmapHeight (BYVAL hBitmap AS HBITMAP) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hBitmap* | Handle to the bitmap. |

#### Return value

The height of the bitmap on success or 0 on failure.

---

### AfxGetBitmapWidth

Retrieves the width of the specified bitmap.

```
FUNCTION AfxGetBitmapWidth (BYVAL hBitmap AS HBITMAP) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hBitmap* | Handle to the bitmap. |

#### Return value

The width of the bitmap on success or 0 on failure.

---

### AfxCreateDIBSection

Creates a DIB section.

```
FUNCTION AfxCreateDIBSection (BYVAL hdc AS HDC, BYVAL nWidth AS DWORD, BYVAL nHeight AS DWORD, _
   BYVAL bpp AS LONG = 0, BYVAL ppvBits AS ANY PTR PTR = NULL) AS HBITMAP
```

| Parameter  | Description |
| ---------- | ----------- |
| *hdc* | A handle to the device context. |
| *nWidth* | The width of the bitmap, in pixels. |
| *nHeight* | The height of the bitmap, in pixels. |
| *bpp* | The number of bits-per-pixel. If this parameter is 0, the function will use the value returned by GetDeviceCaps(hDC, BITSPIXEL_). |
| *ppvBits* | Out, optional. A pointer to a variable that receives a pointer to the location of the DIB bit values. Can be NULL. |

#### Return value

If the function succeeds, the return value is a handle to the newly created DIB, and *ppvBits* points to the bitmap bit values.

If the function fails, the return value is NULL, and *ppvBits* is NULL. The function can fail if one or more of the input parameters is invalid.

This function can return the following value: ERROR_INVALID_PARAMETER (One or more of the input parameters is invalid).

#### Remarks

You must delete the returned bitmap handle with **DeleteObject** when no longer needed to avoid memory leaks.

You cannot paste a DIB section from one application into another application.

**AfxCreateDIBSection** does not use the **BITMAPINFOHEADER** parameters *biXPelsPerMeter* or *biYPelsPerMeter* and will not provide resolution information in the **BITMAPINFO** structure.

#### Usage example

```
DIM hdcWindow AS HDC, hbmp AS HBITMAP, pvBits AS ANY PTR
hdcWindow = GetWindowDC(hwnd)   ' where hwnd is the handle of the wanted window or control
hbmp = AfxCreateDIBSection(hdcWindow, 10, 10, @pvBits)
ReleaseDC(hwnd, hdcWindow)
```

### AfxCenterWindow

Centers a window on the screen or over another window. It also ensures that the placement is done within the work area.

```
SUB AfxCenterWindow (BYVAL hwnd AS HWND = NULL, BYVAL hwndParent AS HWND = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. Handle to the window. |
| *hwndParent* | Optional. Handle to the parent window. |

---

### AfxForceSetForegroundWindow

Brings the thread that created the specified window into the foreground and activates the window. Keyboard input is directed to the window, and various visual cues are changed for the user. The system assigns a slightly higher priority to the thread that created the foreground window than it does to other threads.

```
SUB AfxForceSetForegroundWindow (BYVAL hwnd AS HWND)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Remarks

Replacement for the **SetForegroundWindow** API function, that sometimes fails.

---

### AfxGetSystemInfo

Retrieves information about the current system.

```
FUNCTION AfxGetSystemInfo (BYREF metricName AS STRING) AS LONG_PTR
```
| MetricName | Description |
| ---------- | ----------- |
| *CpuCount* | The number of logical processors in the current group. |
| *CpuMask* | A mask representing the set of processors configured into the system. Bit 0 is processor 0; bit 31 is processor 31. |
| *Granularity* | The granularity for the starting address at which virtual memory can be allocated. |
| *MaxAppAddr* | The highest memory address accessible to applications and DLLs. |
| *MaxAppAddr* | The lowest memory address accessible to applications and DLLs. |
| *PageSize* | The page size and the granularity of page protection and commitment. This is the page size used by the **VirtualAlloc** function. |

---

### AfxGetTopEnabledWindow

Retrieves the handle of the enabled and visible window at the top of the z-order in an application.

```
FUNCTION AfxGetTopEnabledWindow () AS HWND
```

#### Return value

Handle of the window at top of z-order or NULL.

---

### AfxGetTopLevelParent

Retrieves the window's top-level parent window.

```
FUNCTION AfxGetTopEnabledWindow () AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Return value

Handle of the top-level parent window.

---

### AfxGetTopLevelWindow

Retrieves the window's top-level parent or owner window.

```
FUNCTION AfxGetTopLevelWindow (BYVAL hwnd AS HWND) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Return value

Handle of the top-level parent or owner window.

---

### AfxGetWindowBounds

Retrieves the bounds of a window without the drop shadows.
```
FUNCTION AfxGetWindowBounds (BYVAL hWin AS HWND) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Remarks

In Windows Vista and later, the Window Rect includes the area occupied by the drop shadow. Calling **GetWindowRect** will have different behavior depending on whether the window has ever been shown or not. If the window has not been shown before, **GetWindowRect** will not include the area of the drop shadow. To get the window bounds excluding the drop shadow, use DwmGetWindowAttribute, specifying DWMWA_EXTENDED_FRAME_BOUNDS. Note that unlike the Window Rect, the DWM Extended Frame Bounds are not adjusted for DPI. Getting the extended frame bounds can only be done after the window has been shown at least once.

---

### AfxGetWindowClassName

Retrieves the name of the class to which the specified window belongs. 

```
FUNCTION AfxGetWindowClassName (BYVAL hwnd AS HWND) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Return value

The name of the class.

---

### AfxGetWindowClientHeight

Returns the height of the client area of window, in pixels.

```
FUNCTION AfxGetWindowClientHeight (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxGetWindowClientRect

Retrieves the coordinates of a window's client area. The client coordinates specify the upper-left and lower-right corners of the client area. Because client coordinates are relative to the upper-left corner of a window's client area, the coordinates of the upper-left corner are (0,0).

```
FUNCTION AfxGetWindowClientRect (BYVAL hwnd AS HWND) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Return value

A RECT structure with the retrieved coordinates of the window's client area.

---

### AfxGetWindowClientWidth

Returns the width of the client area of a window, in pixels.

```
FUNCTION AfxGetWindowClientWidth (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxGetWindowHeight

Returns the height of a window, in pixels.

```
FUNCTION AfxGetWindowHeight (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxGetWindowLocation

Returns the location of the top left corner of the window, in pixels. The location is relative to the upper-left corner of the client area in the parent window.

```
SUB AfxGetWindowLocation (BYVAL hwnd AS HWND, BYREF nLeft AS LONG, BYREF nTop AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nLeft* | Out. The horizontal location. |
| *nTop* | Out. The vertical location. |

---

### AfxGetWindowRect

Retrieves the dimensions of the bounding rectangle of the specified window. The dimensions are given in screen coordinates that are relative to the upper-left corner of the screen.

```
FUNCTION AfxGetWindowRect (BYVAL hwnd AS HWND) AS RECT
```

#### Return value

A RECT structure with the retrieved dimensions.

---

### AfxGetWindowSize

Gets the width and height of the specified window, in pixels.

```
FUNCTION AfxGetWindowSize (BYVAL hwnd AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nWidth* | The width of the window. |
| *nHeight* | The height of the window. |

---

### AfxGetWindowText

Gets the text of a window. This function can also be used to retrieve the text of buttons, edit and static controls.

```
FUNCTION AfxGetWindowText (BYVAL hwnd AS HWND) AS DWSTRING
```

#### Return value

The text of the window.

For an edit control, the text returned is the content of the edit control. For a combo box, the text is the content of the edit control (or static-text) portion of the combo box. For a button, the text is the button name. For other windows, the text is the window title. To retrieve the text of an item in a list box, an application can use the **ListBox_GetText** function. 

Rich Edit: If the text to be copied exceeds 64K, use either the EM_STREAMOUT or EM_GETSELTEXT message.

#### Remarks

This function uses the WM_GETTEXT message because **GetWindowText** cannot retrieve the text of a window in another application.

#### Usage examples

DIM dwsText AS DWSTRING = AfxGetWindowText(hwnd)
MessageBoxW 0, dwsText, "", MB_OK

### AfxGetWindowTextLength

Retrieves the length of the text of a window. This function can also be used to retrieve the length of the text of buttons, edit and static controls.

```
FUNCTION AfxGetWindowTextLength (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Return value

If the function succeeds, the return value is the length of the text in characters, not including the terminating null character.

If the function fails, the return value is zero.

For an edit control, the text returned is the content of the edit control. For a combo box, the text is the content of the edit control (or static-text) portion of the combo box. For a button, the text is the button name. For other windows, the text is the window title. To retrieve the text of an item in a list box, an application can use the **ListBox_GetTextLength** function. 

**AfxGetWindowTextLength** sends a WM_GETTEXTLENGTH message. When the WM_GETTEXTLENGTH message is sent, the **DefWindowProc** function returns the length, in characters, of the text. Under certain conditions, the **DefWindowProc** function returns a value that is larger than the actual length of the text. This occurs with certain mixtures of ANSI and Unicode, and is due to the system allowing for the possible existence of double-byte character set (DBCS) characters within the text. The return value, however, will always be at least as large as the actual length of the text; you can thus always use it to guide buffer allocation. This behavior can occur when an application uses both ANSI functions and common dialogs, which use Unicode.

To obtain the exact length of the text, use the WM_GETTEXT, LB_GETTEXT, or CB_GETLBTEXT messages, or the **GetWindowText** function.

Sending a WM_GETTEXTLENGTH message to a non-text static control, such as a static bitmap or static icon control, does not return a string value. Instead, it returns zero.

---

### AfxGetWindowWidth

Returns the width of a window, in pixels.

```
FUNCTION AfxGetWindowWidth (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

---

### AfxGetWorkAreaHeight

Retrieves the height of the work area on the primary display monitor expressed in virtual screen coordinates. The work area is the portion of the screen not obscured by the system taskbar or by application desktop toolbars. To get the work area of a monitor other than the primary display monitor, call the **GetMonitorInfo** function.

```
FUNCTION AfxGetWorkAreaHeight () AS LONG
```

### AfxGetWorkAreaRect

Retrieves the coordinates of the work area on the primary display monitor expressed in virtual screen coordinates. The work area is the portion of the screen not obscured by the system taskbar or by application desktop toolbars. To get the work area of a monitor other than the primary display monitor, call the **GetMonitorInfo** function.

```
FUNCTION AfxGetWorkAreaRect () AS RECT
```

#### Return value

A RECT structure with the retrieved coordinates.

---

### AfxGetWorkAreaWidth

Retrieves the width of the work area on the primary display monitor expressed in virtual screen coordinates. The work area is the portion of the screen not obscured by the system taskbar or by application desktop toolbars. To get the work area of a monitor other than the primary display monitor, call the **GetMonitorInfo** function.

```
FUNCTION AfxGetWorkAreaWidth () AS LONG
```

### AfxRedrawNonClientArea

Redraws the non-client area of the specified window.

```
FUNCTION AfxRedrawNonClientArea (BYVAL hwnd AS HWND) AS BOOLEAN
```

#### Return value

If the function succeeds, the return value is TRUE.

If the function fails, the return value is FALSE. To get extended error information, call **GetLastError**.

---

### AfxMoveWindowForDpi

Changes the position and dimensions of the specified window. For a top-level window, the position and dimensions are relative to the upper-left corner of the screen. For a child window, they are relative to the upper-left corner of the parent window's client area. DPI aware versiomn of the API function **MoveWindow**.

```
PRIVATE FUNCTION AfxMoveWindowForDPI (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, _
   BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS BOOLEAN = TRUE) AS BOOLEAN

```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *x* | The new position of the left side of the window. |
| *y* | The new position of the top side of the window. |
| *nWidth* | The new width of the window. |
| *nHeight* | The new height of the window. |
| *bRepaint* | Indicates whether the window is to be repainted. If this parameter is TRUE, the window receives a message. If the parameter is FALSE, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of moving a child window. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE. To get extended error information, call **GetLastError**.

#### Remarks

If the *bRepaint* parameter is TRUE, the system sends the WM_PAINT message to the window procedure immediately after moving the window (that is, the **MoveWindow** function calls the **UpdateWindow** function). If *bRepaint* is FALSE, the application must explicitly invalidate or redraw any parts of the window and parent window that need redrawing.

**MoveWindow** sends the WM_WINDOWPOSCHANGING, WM_WINDOWPOSCHANGED, WM_MOVE, WM_SIZE, and WM_NCCALCSIZE messages to the window.

---

### AfxRedrawWindow

Redraws the specified window.

```
SUB AfxRedrawWindow (BYVAL hwnd AS HWND)
```
---

### AfxSetWindowClientSize

Adjusts the bounding rectangle of a window based on the desired size of the client area.

```
SUB AfxSetWindowClientSize (BYVAL hwnd AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
   BYVAL rxRatio AS SINGLE = 1, BYVAL ryRatio AS SINGLE = 1)
SUB AfxSetWindowClientSizeForDpi (BYVAL hwnd AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nWidth* | The new width of the client area of the window. |
| *nHeight* | The new height of the client area of the window. |
| *rxRatio* | Horizontal scaling ratio. |
| *ryRatio* | Vertical scaling ratio. |

#### Remarks

**AfxSetWindowClientSizeForDpi** if DPI aware version of **AfxSetWindowClientSizeFor**.

---

### AfxSetWindowIcon

Associates a new large icon with a window. The system displays the large icon in the ALT+TAB dialog box, and the small icon in the window caption.

```
FUNCTION AfxSetWindowIcon (BYVAL hwnd AS HWND, BYVAL nIconType AS LONG, BYVAL hIcon AS HICON) AS HICON
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nIconType* | The type of icon to be set. This parameter can be one of the following values.<br>**ICON_BIG** : Set the large icon for the window.<br>**ICON_SMALL** : Set the small icon for the window. |
| *hIcon* | A handle to the new large icon. If this parameter is NULL, the icon is removed. |

#### Return value

The return value is a handle to the previous large or small icon, depending on the value of *nIconType*. It is NULL if the window previously had no icon of the type indicated by *nIconType*.

---

### AfxSetWindowLocation

Sets the location of the top left corner of the window, in pixels.The location is relative to the upper-left corner of the client area in the parent window.

```
FUNCTION AfxSetWindowLocation (BYVAL hwnd AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
FUNCTION AfxSetWindowLocationForDpi (BYVAL hwnd AS HWND, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nLeft* | The new position of the left side of the window, in client coordinates. |
| *nTop* | The new position of the top side of the window, in client coordinates. |

#### Return value

If the function succeeds, the return value is TRUE.

If the function fails, the return value is FALSE. To get extended error information, call **GetLastError**.

**AfxSetWindowLocationForDpi** is a DPI awre version of **AfxSetWindowLocation**.

---

### AfxSetWindowPosForDpi

Changes the size, position, and Z order of a child, pop-up, or top-level window. DPI aware version of the API function **SetWindowPos**.

```
PRIVATE FUNCTION AfxSetWindowPosForDPI (BYVAL hwnd AS HWND, BYVAL hWndInsertAfter AS HWND, _
   BYVAL x AS LONG, BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, _
   BYVAL uFlags AS UINT = SWP_NOZORDER) AS BOOLEAN

```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *hWndInsertAfter* | A handle to the window to precede the positioned window in the Z order. |
| *x* | The new position of the left side of the window, in client coordinates. |
| *y* | The new position of the top side of the window, in client coordinates. |
| *cx* | The new width of the window, in pixels. |
| *cy* | The new height of the window, in pixels. |
| *uFlags* | The window sizing and positioning flags. This parameter can be a combination of the following values. See: [SetWindowPos](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowpos). |

---

### AfxSetWindowSize

Sets the size of the specified window, in pixels.

```
FUNCTION AfxSetWindowSize (BYVAL hwnd AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
FUNCTION AfxSetWindowSizeForDpi (BYVAL hwnd AS HWND, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nWidth* | The new width of the window. |
| *nHeight* | The new height of the window. |

#### Remarks

**AfxSetWindowSizeForDpi** is a DPI aware version of **AfxSetWindowSize**.

---

### AfxSetWindowText

Sets the text of a window. This function can also be used to set the text of buttons, edit and static controls.

```
FUNCTION AfxSetWindowText (BYVAL hwnd AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *pwszText* | The text to set. |

#### Return value

If the function succeeds, the return value is TRUE.

If the function fails, the return value is FALSE.

---

### AfxShowWindowState

Sets the specified window's show state.

```
FUNCTION AfxShowWindowState (BYVAL hwnd AS HWND, BYVAL nShowState AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *nShowState* | Controls how the window is to be shown. This parameter is ignored the first time an application calls **AfxShowWindowState**, if the program that launched the application provides a **STARTUPINFO** structure. Otherwise, the first time **AfxShowWindowState** is called, the value should be the value obtained by the **WinMain** function in its *nCmdShow* parameter. In subsequent calls, this parameter can be one of the values listed below. |

| Value      | Maning |
| ---------- | ----------- |
| SW_FORCEMINIMIZE | Minimizes a window, even if the thread that owns the window is not responding. This flag should only be used when minimizing windows from a different thread. |
| SW_HIDE | Hides the window and activates another window. |
| SW_MAXIMIZE | Maximizes the specified window. |
| SW_MINIMIZE | Minimizes the specified window and activates the next top-level window in the Z order. |
| SW_RESTORE | Activates and displays the window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window. |
| SW_SHOW | Activates the window and displays it in its current size and position. |
| SW_SHOWDEFAULT | Sets the show state based on the SW_ value specified in the **STARTUPINFO** structure passed to the **CreateProcess** function by the program that started the application. |
| SW_SHOWMAXIMIZED | Activates the window and displays it as a maximized window. |
| SW_SHOWMINIMIZED | Activates the window and displays it as a minimized window. |
| SW_SHOWMINNOACTIVE | Displays the window as a minimized window. This value is similar to SW_SHOWMINIMIZED, except the window is not activated. |
| SW_SHOWNA | Displays the window in its current size and position. This value is similar to SW_SHOW, except that the window is not activated. |
| SW_SHOWNOACTIVATE | Displays a window in its most recent size and position. This value is similar to SW_SHOWNORMAL, except that the window is not activated. |
| SW_SHOWNORMAL | Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time. |

#### Return value

If the window was previously visible, the return value is TRUE.

If the window was previously hidden, the return value is FALSE.

#### Remarks

To perform certain special effects when showing or hiding a window, use **AnimateWindow**.

The first time an application calls **AfxShowWindowState**, it should use the **WinMain** function's *nCmdShow* parameter as its *nCmdShow* parameter. Subsequent calls to **AfxShowWindowState** must use one of the values in the given list, instead of the one specified by the **WinMain** function's *nCmdShow* parameter.

As noted in the discussion of the *nCmdShow* parameter, the *nCmdShow* value is ignored in the first call to **AfxShowWindowState** if the program that launched the application specifies startup information in the structure. In this case, **AfxShowWindowState** uses the information specified in the **STARTUPINFO** structure to show the window. On subsequent calls, the application must call **AfxShowWindowState** with *nCmdShow* set to SW_SHOWDEFAULT to use the startup information provided by the program that launched the application. This behavior is designed for the following situations:

* Applications create their main window by calling **CreateWindow** with the WS_VISIBLE flag set.
* Applications create their main window by calling **CreateWindow** with the WS_VISIBLE flag cleared, and later call **AfxShowWindowState** with the SW_SHOW flag set to make it visible.

---

### AfxWindowsVersion

Returns the Windows version.

```
FUNCTION AfxWindowsVersion () AS LONG
```

#### Return value

Platform 1:
```
  400 Windows 95
  410 Windows 98
  490 Windows ME
```

Platform 2:

```
  400 Windows NT
  500 Windows 2000
  501 Windows XP
  502 Windows Server 2003
  600 Windows Vista and Windows Server 2008
  601 Windows 7
  602 Windows 8
  603 Windows 8.1
 1000 Windows 10
```

**Note 1**: As Windows 95 and Windows NT return the same version number, we also need to call **AfxGetWindowsPlatform** to differentiate them.

**Note 2**: As Windows 10 and Windows 11 return the same version number, we also need to call **AfxWindowsBuild** to differentiate them. Windows 11 is Windows 10 build 21996 and higher.

#### Alias

**AfxGetWindowsVersion**

---

### AfxWindowsMajorVersion

Returns the Windows major version.

```
FUNCTION AfxWindowsMajorVersion () AS LONG
```

#### Alias

**AfxGetWindowsMajorVersion**

---

### AfxWindowsMinorVersion

Returns the Windows minor version.

```
FUNCTION AfxWindowsMinorVersion () AS LONG
```

#### Alias

**AfxGetWindowsMinorVersion**

---

### AfxWindowsVersionStr

Returns the full Windows version, including the build number, as a string.

```
FUNCTION AfxWindowsVersionStr () AS DWSTRING
```

#### Alias

**AfxGetWindowsVersionStr**

---

### AfxProcessorArchitecture

Returns the processor architecture of the operating system, e.g. "AMD64".

```
FUNCTION AfxProcessorArchitecture () AS DWSTRING
```
---

### AfxProcessorsCount

Returns the number of processors.

```
FUNCTION AfxProcessorsCount () AS LONG
```
---

### AfxTotalPageFile

Returns the current committed memory limit for the system or the current process, whichever is smaller, in bytes.

```
FUNCTION AfxTotalPageFile () AS DWORDLONG
```
---

### AfxAvailablePageFile

Returns maximum amount of memory the current process can commit, in bytes. This value is equal to or smaller than the system-wide available commit value.

```
FUNCTION AfxAvailablePageFile () AS DWORDLONG
```
---

### AfxWindowsBuild

Returns the Windows build number.

```
FUNCTION AfxWindowsBuild () AS LONG
```

#### Alias

**AfxGetWindowsBuild**

---

### AfxWindowsInstallDate

Returns the date in which Windows was installed, in Unix time.

```
FUNCTION AfxWindowsInstallDate () AS DWORD
```

#### Alias

**AfxGetWindowsInstallDate**

#### Usage examples:
```
PRINT AfxUnixDateStr(AfxWindowsInstallDate, "dd-MM-yyyy")
PRINT AfxUnixTimeStr(AfxWindowsInstallDate, "hh':'mm':'ss")
```
---

### AfxAppsUseDarkMode

Returns TRUE if Windows applications are using dark mode, or FALSE otherwise.

```
FUNCTION AfxAppsUseDarkMode () AS BOOLEAN
```
---

### AfxSystemUsesDarkMode

Returns TRUE if Windows is using dark mode, or FALSE otherwise.

```
FUNCTION AfxSystemUseDarkMode () AS BOOLEAN
```
---

### AfxWindowsPlatform

Returns the Windows platform.

```
FUNCTION AfxWindowsPlatform () AS LONG
```

#### Return value

| Value      | Description |
| ---------- | ----------- |
| 1 | Windows 95/98/ME |
| 2 | Windows NT/2000/XP/Server/Vista/Windows 7 |

#### Alias

**AfxGetWindowsPlatform**

---

### AfxWindowsBitness

Returns the Windows bitness (32 or 64 bit).

```
FUNCTION AfxWindowsBitness () AS LONG
```
---

### AfxIsPlatformNT

Returns TRUE if the Windows Platform is NT; FALSE, otherwise.

```
FUNCTION AfxIsPlatformNT () AS BOOLEAN
```
---

### AfxWindowsFeatureUpdate

Returns the Windows feature update versión, e.g. 22H2.

```
FUNCTION AfxWindowsFeatureUpdate () AS DWSTRING
```
---

### AfxComCtlVersion

Returns the version of CommCtl32.dll

```
#define AfxComCtlVersion AfxGetFileVersion("COMCTL32.DLL")
```

#### Return value

The version of CommCtl32.dll multiplied by 100, e.g. 582 for version 5.82.

---

### AfxMsg

Displays an application modal message box. Can be used with any string data type or literal.It is a quick shortcur for the **MessageBoxW** API function.

```
FUNCTION AfxMsg (BYREF wszText AS WSTRING, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYVAL pwszText AS WSTRING PTR, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYVAL hWin AS HWND, BYREF wszText AS WSTRING, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYVAL hWin AS HWND, BYVAL pwszText AS WSTRING PTR, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszText* | Any string data type or a literal. |
| *pwszText* | Pointer to a WSTRING. |
| *wszCaption* | Optional. The message box caption. Default title is "Message". |
| *uType* | Optional. For a list of available types, see the Microsoft documentation for the MessageBoxW function. The MB_APPLMODAL type is always added. |

---

### AfxGetWinDir

Retrieves the path of the Windows directory. This path does not end with a backslash unless the Windows directory is the root directory. For example, if the Windows directory is named Windows on drive C, the path of the Windows directory retrieved by this function is C:\Windows. If the system was installed in the root directory of drive C, the path retrieved is C:\\.

```
FUNCTION AfxGetWinDir () AS DWSTRING
```
---

### AfxGetWinErrMsg

Retrieves the localized description of the specified Windows error code.

```
FUNCTION AfxGetWinErrMsg (BYVAL dwError AS DWORD) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwError* | The Windows error code. |

#### Return value

The localized description of the error code.

---

### AfxGetComputerName

Retrieves the NetBIOS name of the local computer. This name is established at system startup, when the system reads it from the registry.

```
FUNCTION AfxGetComputerName () AS DWSTRING
```

#### Return value

The NetBIOS name of the local computer.

#### Alias

**AfxComputerName**

#### Remarks

The behavior of this function can be affected if the local computer is a node in a cluster. For more information, see **ResUtilGetEnvironmentWithNetName** and **UseNetworkName**.

---

### AfxGetComputerNameDnsFullyQualified

Retrieves the fully qualified DNS name that uniquely identifies the local computer. This name is a combination of the DNS host name and the DNS domain name, using the form HostName.DomainName. If the local computer is a node in a cluster, dwsBuffer receives the fully qualified DNS name of the cluster virtual server.

```
FUNCTION AfxGetComputerNameDnsFullyQualified () AS DWSTRING
```

#### Alias

AfxComputerNameDnsHostname

---

### AfxGetComputerNameDnsHostname

Retrieves the DNS host name of the local computer. If the local computer is a node in a cluster, dwsBuffer receives the DNS host name of the cluster virtual server.

```
FUNCTION AfxGetComputerNameDnsHostname () AS DWSTRING
```

#### Alias

AfxComputerNameDnsHostname

---

### AfxGetComputerNameNetBIOS

Retrieves the NetBIOS name of the local computer. If the local computer is a node in a cluster, dwsBuffer receives the NetBIOS name of the cluster virtual server.

```
FUNCTION AfxGetComputerNameNetBIOS () AS DWSTRING
```

#### Alias

AfxComputerNameNetBIOS

---

### AfxGetUserName

Retrieves the name of the user associated with the current thread.

```
FUNCTION AfxGetUserName () AS DWSTRING
```

#### Alias

**AfxUserName**

#### Return value

The name of the current user associated with the current thread.

#### Remarks

If the current thread is impersonating another client, the **AfxGetUserName** function returns the user name of the client that the thread is impersonating.

---

### AfxGetUserDomain

Retrieves the name of the user associated with the current thread.

```
FUNCTION AfxGetUserDomain () AS DWSTRING
```
---

### AfxGetPhysicallyInstalledSystemMemory

Retrieves the amount of RAM that is physically installed on the computer, in kilobytes.

```
FUNCTION AfxGetPhysicallyInstalledSystemMemory () AS ULONGLONG
```

#### Alias

**AfxPhysicallyInstalledSystemMemory**

---

### AfxIsProcessElevated

Checks if the process is running with real administrative privileges.

```
FUNCTION AfxIsProcessElevated () AS BOOLEAN
```
---

### AfxMemoryLoad

Returns the amount of actual physical memory, in bytes.

```
FUNCTION AfxMemoryLoad () AS DWORD
```
---

### AfxTotalPhysicalMemory

Returns the amount of actual physical memory, in bytes.

```
FUNCTION AfxTotalPhysicalMemory () AS DWORDLONG
```
---

### AfxAvailablePhysicalMemory

Returns the amount of physical memory currently available, in bytes. This is the amount of physical memory that can be immediately reused without having to write its contents to disk first. It is the sum of the size of the standby, free, and zero lists.

```
FUNCTION AfxTotalPhysicalMemory () AS DWORDLONG
```
---

### AfxTotalVirtualMemory

Returns size of the user-mode portion of the virtual address space of the calling process, in bytes. This value depends on the type of process, the type of processor, and the configuration of the operating system. For example, this value is approximately 2 GB for most 32-bit processes on an x86 processor and approximately 3 GB for 32-bit processes that are large address aware running on a system with 4-gigabyte tuning enabled.

```
FUNCTION AfxTotalVirtualMemory () AS DWORDLONG
```
---

### AfxAvailableVirtualMemory

Returns amount of unreserved and uncommitted memory currently in the user-mode portion of the virtual address space of the calling process, in bytes.

```
FUNCTION AfxAvailableVirtualMemory () AS DWORDLONG
```
---

### AfxGetProductInfo

Retrieves the product type for the operating system on the local computer, and maps the type to the product types supported by the specified operating system.

```
FUNCTION AfxGetProductInfo () AS DWORD
```

#### Return value

Can be one of the following values (some products below may be out of support).

| Name | Value | Meaning |
|----- | ------| ------- |
| **PRODUCT_BUSINESS** | &h00000006 | Business |
| **PRODUCT_BUSINESS_N** | &h00000010 | Business N |
| **PRODUCT_CLUSTER_SERVER** | &h00000012 | HPC Edition |
| **PRODUCT_CLUSTER_SERVER_V** | &h00000040 | Server Hyper Core V |
| **PRODUCT_CORE** | &h00000065 | Windows 10 Home |
| **PRODUCT_CORE_COUNTRYSPECIFIC** | &h00000063 | Windows 10 Home China |
| **PRODUCT_CORE_N** | &h00000062 | Windows 10 Home N |
| **PRODUCT_CORE_SINGLELANGUAGE** | &h00000064 | Windows 10 Home Single Language |
| **PRODUCT_DATACENTER_EVALUATION_SERVER** | &h00000050 | Server Datacenter (evaluation installation) |
| **PRODUCT_DATACENTER_A_SERVER_CORE** | &h00000091 | Server Datacenter, Semi-Annual Channel (core installation) |
| **PRODUCT_STANDARD_A_SERVER_CORE** | &h00000092 | Server Standard, Semi-Annual Channel (core installation) |
| **PRODUCT_DATACENTER_SERVER** | &h00000008 | Server Datacenter (full installation. For Server Core installations of Windows Server 2012 and later, use the method, Determining whether Server Core is running.) |
| **PRODUCT_DATACENTER_SERVER_CORE** | &h0000000C | Server Datacenter (core installation, Windows Server 2008 R2 and earlier) |
| **PRODUCT_DATACENTER_SERVER_CORE_V** | &h00000027 | Server Datacenter without Hyper-V (core installation) |
| **PRODUCT_DATACENTER_SERVER_V** | &h00000025 | Server Datacenter without Hyper-V (full installation) |
| **PRODUCT_EDUCATION** | &h00000079 | Windows 10 Education |
| **PRODUCT_EDUCATION_N** | &h0000007A | Windows 10 Education N |
| **PRODUCT_ENTERPRISE** | &h00000004 | Windows 10 Enterprise |
| **PRODUCT_ENTERPRISE_E** | &h00000046 | Windows 10 Enterprise E |
| **PRODUCT_ENTERPRISE_EVALUATION** | &h00000048 | Windows 10 Enterprise Evaluation |
| **PRODUCT_ENTERPRISE_N** | &h00000018 | Windows 10 Enterprise N |
| **PRODUCT_ENTERPRISE_N_EVALUATION** | &h00000054 | Windows 10 Enterprise N Evaluation |
| **PRODUCT_ENTERPRISE_S** | &h0000007D | Windows 10 Enterprise 2015 LTSB |
| **PRODUCT_ENTERPRISE_S_EVALUATION** | &h00000081 | Windows 10 Enterprise 2015 LTSB Evaluation |
| **PRODUCT_ENTERPRISE_S_N** | &h0000007E | Windows 10 Enterprise 2015 LTSB N |
| **PRODUCT_ENTERPRISE_S_N_EVALUATION** | &h00000082 | Windows 10 Enterprise 2015 LTSB N Evaluation |
| **PRODUCT_ENTERPRISE_SERVER** | &h0000000A | Server Enterprise (full installation) |
| **PRODUCT_ENTERPRISE_SERVER_CORE** | &h0000000E | Server Enterprise (core installation) |
| **PRODUCT_ENTERPRISE_SERVER_CORE_V** | &h00000029 | Server Enterprise without Hyper-V (core installation) |
| **PRODUCT_ENTERPRISE_SERVER_IA64** | &h0000000F | Server Enterprise for Itanium-based Systems |
| **PRODUCT_ENTERPRISE_SERVER_V** | &h00000026 | Server Enterprise without Hyper-V (full installation) |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL** | &h0000003C | Windows Essential Server Solution Additional |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC** | &h0000003E | Windows Essential Server Solution Additional SVC |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT** | &h0000003B | Windows Essential Server Solution Management |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC** | &h0000003D | Windows Essential Server Solution Management SVC |
| **PRODUCT_HOME_BASIC** | &h00000002 | Home Basic |
| **PRODUCT_HOME_BASIC_E** | &h00000043 | Not supported |
| **PRODUCT_HOME_BASIC_N** | &h00000005 | Home Basic N |
| **PRODUCT_HOME_PREMIUM** | &h00000003 | Home Premium |
| **PRODUCT_HOME_PREMIUM_E** | &h00000044 | Not supported |
| **PRODUCT_HOME_PREMIUM_N** | &h0000001A | Home Premium N |
| **PRODUCT_HOME_PREMIUM_SERVER** | &h00000022 | Windows Home Server 2011 |
| **PRODUCT_HOME_SERVER** | &h00000013 | Windows Storage Server 2008 R2 Essentials |
| **PRODUCT_HYPERV** | &h0000002A | Microsoft Hyper-V Server |
| **PRODUCT_IOTENTERPRISE** | &h000000BC | Windows IoT Enterprise |
| **PRODUCT_IOTENTERPRISE_S** | &h000000BF | Windows IoT Enterprise LTSC |
| **PRODUCT_IOTUAP** | &h0000007B | Windows 10 IoT Core |
| **PRODUCT_IOTUAPCOMMERCIAL** | &h00000083 | Windows 10 IoT Core Commercial |
| **PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT** | &h0000001E | Windows Essential Business Server Management Server |
| **PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING** | &h00000020 | Windows Essential Business Server Messaging Server |
| **PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY** | &h0000001F | Windows Essential Business Server Security Server |
| **PRODUCT_MOBILE_CORE** | &h00000068 | Windows 10 Mobile |
| **PRODUCT_MOBILE_ENTERPRISE** | &h00000085 | Windows 10 Mobile Enterprise |
| **PRODUCT_MULTIPOINT_PREMIUM_SERVER** | &h0000004D | Windows MultiPoint Server Premium (full installation) |
| **PRODUCT_MULTIPOINT_STANDARD_SERVER** | &h0000004C | Windows MultiPoint Server Standard (full installation) |
| **PRODUCT_PPI_PRO** | &h00000077 | Windows 10 Team |
| **PRODUCT_PRO_FOR_EDUCATION** | &h000000A4 | Windows 10 Pro Education |
| **PRODUCT_PRO_WORKSTATION** | &h000000A1 | Windows 10 Pro for Workstations |
| **PRODUCT_PRO_WORKSTATION_N** | &h000000A2 | Windows 10 Pro for Workstations N |
| **PRODUCT_PROFESSIONAL** | &h00000030 | Windows 10 Pro |
| **PRODUCT_PROFESSIONAL_E** | &h00000045 | Not supported |
| **PRODUCT_PROFESSIONAL_N** | &h00000031 | Windows 10 Pro N |
| **PRODUCT_PROFESSIONAL_WMC** | &h00000067 | Professional with Media Center |
| **PRODUCT_SB_SOLUTION_SERVER** | &h00000032 | Windows Small Business Server 2011 Essentials |
| **PRODUCT_SB_SOLUTION_SERVER_EM** | &h00000036 | Server For SB Solutions EM |
| **PRODUCT_SERVER_FOR_SB_SOLUTIONS** | &h00000033 | Server For SB Solutions |
| **PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM** | &h00000037 | Server For SB Solutions EM |
| **PRODUCT_SERVER_FOR_SMALLBUSINESS** | &h00000018 | Windows Server 2008 for Windows Essential Server Solutions |
| **PRODUCT_SERVER_FOR_SMALLBUSINESS_V** | &h00000023 | Windows Server 2008 without Hyper-V for Windows Essential Server Solutions |
| **PRODUCT_SERVER_FOUNDATION** | &h00000021 | Server Foundation |
| **PRODUCT_SERVERRDSH** | &h000000AF | Windows 10 Enterprise for Virtual Desktops |
| **PRODUCT_SMALLBUSINESS_SERVER** | &h00000009 | Windows Small Business Server |
| **PRODUCT_SMALLBUSINESS_SERVER_PREMIUM** | &h00000019 | Small Business Server Premium |
| **PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE** | &h0000003F | Small Business Server Premium (core installation) |
| **PRODUCT_SOLUTION_EMBEDDEDSERVER** | &h00000038 | Windows MultiPoint Server |
| **PRODUCT_STANDARD_EVALUATION_SERVER** | &h0000004F | Server Standard (evaluation installation) |
| **PRODUCT_STANDARD_SERVER** | &h00000007 | Server Standard (full installation. For Server Core installations of Windows Server 2012 and later, use the method, Determining whether Server Core is running.) |
| **PRODUCT_STANDARD_SERVER_CORE** | &h0000000D | Server Standard (core installation, Windows Server 2008 R2 and earlier) |
| **PRODUCT_STANDARD_SERVER_CORE_V** | &h00000028 | Server Standard without Hyper-V (core installation) |
| **PRODUCT_STANDARD_SERVER_V** | &h00000024 | Server Standard without Hyper-V |
| **PRODUCT_STANDARD_SERVER_SOLUTIONS** | &h00000034 | Server Solutions Premium |
| **PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE** | &h00000035 | Server Solutions Premium (core installation) |
| **PRODUCT_STARTER** | &h0000000B | Starter |
| **PRODUCT_STARTER_E** | &h00000042 | Not supported |
| **PRODUCT_STARTER_N** | &h0000002F | Starter N |
| **PRODUCT_STORAGE_ENTERPRISE_SERVER** | &h00000017 | Storage Server Enterprise |
| **PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE** | &h0000002E | Storage Server Enterprise (core installation) |
| **PRODUCT_STORAGE_EXPRESS_SERVER** | &h00000014 | Storage Server Express |
| **PRODUCT_STORAGE_EXPRESS_SERVER_CORE** | &h0000002B | Storage Server Express (core installation) |
| **PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER** | &h00000060 | Storage Server Standard (evaluation installation) |
| **PRODUCT_STORAGE_STANDARD_SERVER** | &h00000015 | Storage Server Standard |
| **PRODUCT_STORAGE_STANDARD_SERVER_CORE** | &h0000002C | Storage Server Standard (core installation) |
| **PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER** | &h0000005F | Storage Server Workgroup (evaluation installation) |
| **PRODUCT_STORAGE_WORKGROUP_SERVER** | &h00000016 | Storage Server Workgroup |
| **PRODUCT_STORAGE_WORKGROUP_SERVER_CORE** | &h0000002D | Storage Server Workgroup (core installation) |
| **PRODUCT_ULTIMATE** | &h00000001 | Ultimate |
| **PRODUCT_ULTIMATE_E** | &h00000047 | Not supported |
| **PRODUCT_ULTIMATE_N** | &h0000001C | Ultimate N |
| **PRODUCT_UNDEFINED** | &h00000000 | An unknown product |
| **PRODUCT_WEB_SERVER** | &h00000011 | Web Server (full installation) |
| **PRODUCT_WEB_SERVER_CORE** | &h0000001D | Web Server (core installation) |

---

### AfxGetMACAddress

Retrieves the MAC address of a machine's Ethernet card.

```
FUNCTION AfxGetMACAddress () AS STRING
```

#### Return value

The MAC address in the following format: MM-MM-MM-SS-SS-SS. The leftmost 6 digits, called a "prefix", is associated with the adapter manufacturer. The rightmost digits of a MAC address represent an identification number for the specific device.

#### Remarks

This function only supports one NIC card on your PC.

---

### AfxGetMACAddressEx

Get the MAC address of the first valid physical adapter using **GetAdaptersAddresses**.

```
FUNCTION AfxGetMACAddress () AS STRING
```

#### Return value

The MAC address in the following format: MM-MM-MM-SS-SS-SS. The leftmost 6 digits, called a "prefix", is associated with the adapter manufacturer. The rightmost digits of a MAC address represent an identification number for the specific device.

#### Remarks

This is the Microsoft-recommended method.

---

### AfxGetAllMACAddresses

Populates a dynamic array of STRINGs with all the real MAC addresses of the system.

```
FUNCTION AfxGetAllMACAddresses (macs() AS STRING) AS LONG
```

#### Return value

The number of elements in the array or -1 on failure.

#### Usage example
```
DIM macs(ANY) AS STRING
DIM count AS LONG = AfxGetAllMACAddresses(macs())
FOR i AS LONG = LBOUND(macs) TO UBOUND(macs)
   PRINT macs(i)
NEXT
```
---

### AfxGetAllPhysicalMACAddresses

Populates a dynamic array of STRINGs with all *real* MAC addresses (Ethernet/Wi-Fi).

```
FUNCTION AfxGetAllPhysicalMACAddresses (macs() AS STRING) AS LONG
```

#### Return value

The number of elements in the array or -1 on failure.

#### Usage example
```
DIM macs(ANY) AS STRING
DIM count AS LONG = AfxGetAllMACAddresses(macs())
FOR i AS LONG = LBOUND(macs) TO UBOUND(macs)
   PRINT macs(i)
NEXT
```
---

### AfxGetDefaultBrowserPath

Retrieves the path of the default browser.

```
FUNCTION AfxGetDefaultBrowserPath () AS DWSTRING
```

#### Return value

The retrieved path or an empty string.

---

### AfxGetDefaultMailClientName

Retrieves the name of the default client mail application.

```
FUNCTION AfxGetDefaultMailClientName () AS DWSTRING
```

#### Return value

The retrieved name or an empty string.

---

### AfxGetDefaultMailClientPath

Retrieves the path of the default client mail application.

```
FUNCTION AfxGetDefaultMailClientPath () AS DWSTRING
```

#### Return value

The retrieved path or an empty string.

---

### AfxGetInternetExplorerVersion

Returns the Internet Explorer version installed.

```
FUNCTION AfxGetInternetExplorerVersion () AS SINGLE
```

#### Return value

The Internet Explorer version (major.minor).

---

### AfxInternetAttemptConnect

Attempts to make a connection to the Internet.

```
FUNCTION AfxInternetAttemptConnect () AS DWORD
```

#### Return value

Returns ERROR_SUCCESS if successful, or a system error code otherwise.

#### Remarks

This function allows an application to first attempt to connect before issuing any requests. A client program can use this to evoke the dial-up dialog box. If the attempt fails, the application should enter offline mode.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

#### Usage example

```
IF AfxInternetAttemptConnect = ERROR_SUCCESS THEN ? "You can connect to the Internet"
```
---

### AfxInternetCheckConnection

Checks if a connection to the Internet can be established.

```
FUNCTION AfxInternetCheckConnection (BYVAL pwszUrl AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszUrl* | Pointer to a null-terminated string that specifies the URL to use to check the connection. |

#### Return value

Returns TRUE if a connection is made successfully, or FALSE otherwise. Use GetLastError to retrieve the error code. ERROR_NOT_CONNECTED is returned by GetLastError if a connection cannot be made or if the sockets database is unconditionally offline.

#### Remarks

**InternetCheckConnection** is deprecated. **InternetCheckConnection** does not work in environments that use a web proxy server to access the Internet. Depending on the environment, use **NetworkInformation.GetInternetConnectionProfile** or the NLM Interfaces to check for Internet access instead.

#### Usage example

```
IF AfxInternetCheckConnection("https://www.freebasic.net/forum/viewforum.php?f=1") THEN ? "Connection succeeded!"
```
---

### AfxInternetCanonicalizeUrl

Canonicalizes a URL, which includes converting unsafe characters and spaces into escape sequences.

```
FUNCTION AfxInternetCanonicalizeUrl (BYVAL pwszUrl AS WSTRING PTR, BYVAL dwFlags AS DWORD = 0) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszUrl* | A pointer to the string that contains the URL to canonicalize. |
| *dwFlags* | Controls canonicalization. If no flags are specified, the function converts all unsafe characters and meta sequences (such as .,\\ .., and ...) to escape sequences. This parameter can be one of the following values. |

| Value  | Meaning |
| ------ | ------- |
| **ICU_BROWSER_MODE** | Does not encode or decode characters after "#" or "?", and does not remove trailing white space after "?". If this value is not specified, the entire URL is encoded and trailing white space is removed. |
| **ICU_DECODE** | Converts all %XX sequences to characters, including escape sequences, before the URL is parsed. |
| **ICU_ENCODE_PERCENT** | Encodes any percent signs encountered. By default, percent signs are not encoded. This value is available in Microsoft Internet Explorer 5 and later. |
| **ICU_ENCODE_SPACES_ONLY** | Encodes spaces only. |
| **ICU_NO_ENCODE** | Does not convert unsafe characters to escape sequences. |
| **ICU_NO_META** | Does not remove meta sequences (such as "." and "..") from the URL. |

#### Return value

The canonicalized url on success or an empty string on failure.

#### Usage example
```
PRINT AfxInternetCanonicalizeUrl("http://msdn2.microsoft.com/en-us/ library/")
```
---

### AfxInternetCombineUrl

Combines a base and relative URL into a single URL. The resultant URL is canonicalized.

```
FUNCTION AfxInternetCombineUrl (BYVAL pwszBaseUrl AS WSTRING PTR, BYVAL pwszRelativeUrl AS WSTRING PTR, _
   BYVAL dwFlags AS DWORD = 0) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszBaseUrl* | Pointer to a null-terminated string that contains the base URL. |
| *pwszRelativeUrl* | Pointer to a null-terminated string that contains the relative URL. |
| *dwFlags* | Controls canonicalization. If no flags are specified, the function converts all unsafe characters and meta sequences (such as .,\\ .., and ...) to escape sequences. This parameter can be one of the following values. |

| Value  | Meaning |
| ------ | ------- |
| **ICU_BROWSER_MODE** | Does not encode or decode characters after "#" or "?", and does not remove trailing white space after "?". If this value is not specified, the entire URL is encoded and trailing white space is removed. |
| **ICU_DECODE** | Converts all %XX sequences to characters, including escape sequences, before the URL is parsed. |
| **ICU_ENCODE_PERCENT** | Encodes any percent signs encountered. By default, percent signs are not encoded. This value is available in Microsoft Internet Explorer 5 and later. |
| **ICU_ENCODE_SPACES_ONLY** | Encodes spaces only. |
| **ICU_NO_ENCODE** | Does not convert unsafe characters to escape sequences. |
| **ICU_NO_META** | Does not remove meta sequences (such as "." and "..") from the URL. |

#### Return value

The canonicalized url on success or an empty string on failure.

#### Usage example
```
PRINT AfxInternetCombineUrl (BYVAL pwszBaseUrl AS WSTRING PTR, BYVAL pwszRelativeUrl AS WSTRING PTR, _
   BYVAL dwFlags AS DWORD = 0) AS DWSTRING
```
---

### AfxInternetGetConnectedState

Retrieves the connected state of the local system.

```
FUNCTION AfxInternetGetConnectedState () AS BOOLEAN
```

#### Return value

Returns TRUE or FALSE.

---

### AfxInternetGetConnectionDescription

Retrieves the connection description.

```
FUNCTION AfxInternetGetConnectionDescription () AS DWORD
```

#### Return value

Can be a combination of the following values.

| Name | Value  | Meaning |
| ---- | ------ | ------- |
| **INTERNET_CONNECTION_CONFIGURED** | &h40 | Local system has a valid connection to the Internet, but it might or might not be currently connected. |
| **INTERNET_CONNECTION_LAN** | &h02 | Local system uses a local area network to connect to the Internet. |
| **INTERNET_CONNECTION_MODEM** | &h01 | Local system uses a modem to connect to the Internet. |
| **INTERNET_CONNECTION_MODEM_BUSY** | &h08 | No longer used. |
| **INTERNET_CONNECTION_OFFLINE** | &h20 | Local system is in offline mode. |
| **INTERNET_CONNECTION_PROXY** | &h04 | Local system uses a proxy server to connect to the Internet. |

---

### AfxInternetGetConnectionName

Retrieves the connection name.

```
FUNCTION AfxInternetGetConnectionDescription () AS DWORD
```

#### Return value

Returns the connection name on success or an empty string on failure.

---

### AfxHiMetricToPixelsX

Converts from HiMetric to Pixels (horizontal resolution). Himetric is a scaling unit similar to twips used in computing. It is one thousandth of a centimeter and is independent of the screen resolution. HiMetric per inch = 2540; 1 inch = 2.54 mm.

```
SUB AfxHiMetricToPixelsX (BYVAL hm AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hm* | The size in HiMetric units. |

#### Return value

The size in pixels.

### AfxHiMetricToPixelsY

Converts from HiMetric to Pixels (vertical resolution). Himetric is a scaling unit similar to twips used in computing. It is one thousandth of a centimeter and is independent of the screen resolution. HiMetric per inch = 2540; 1 inch = 2.54 mm.

```
SUB AfxHiMetricToPixelsY (BYVAL hm AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hm* | The size in HiMetric units. |

#### Return value

The size in pixels.

---

### AfxPixelsToHiMetricX

Converts from Pixels to HiMetric (horizontal resolution). Himetric is a scaling unit similar to twips used in computing. It is one thousandth of a centimeter and is independent of the screen resolution. HiMetric per inch = 2540; 1 inch = 2.54 mm.

```
SUB AfxPixelsToHiMetricX (BYVAL cx AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *cx* | The size in pixels. |

#### Return value

The size in HiMetric units.

---

### AfxPixelsToHiMetricY

Converts from Pixels to HiMetric (vertical resolution). Himetric is a scaling unit similar to twips used in computing. It is one thousandth of a centimeter and is independent of the screen resolution. HiMetric per inch = 2540; 1 inch = 2.54 mm.

```
SUB AfxPixelsToHiMetricY (BYVAL cx AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *cy* | The size in pixels. |

#### Return value

The size in HiMetric units.

---

### AfxPixelsToPointsX

Converts pixels to points size (1/72 of an inch). Horizontal resolution.

```
SUB AfxPixelsToPointsX (BYVAL pix AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pix* | The number of pixels. |

#### Return value

The number of points.

---

### AfxPixelsToPointsY

Converts pixels to points size (1/72 of an inch). Vertical resolution.

```
SUB AfxPixelsToPointsY (BYVAL pix AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pix* | The number of pixels. |

#### Return value

The number of points.

---

### AfxPixelsToTwipsX

Converts pixels to twips. Horizontal resolution.

```
FUNCTION AfxPixelsToTwipsX (BYVAL nPixels AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nPixels* | The number of pixels. |

#### Return value

The number of twips.

---

### AfxPixelsToTwipsY

Converts pixels to twips. Vertical resolution.

```
FUNCTION AfxPixelsToTwipsY (BYVAL nPixels AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nPixels* | The number of pixels. |

#### Return value

The number of twips.

---

### AfxPointSizeToDip

Converts point size to DIP (device independent pixel). DIP is defined as 1/96 of an inch and a point is 1/72 of an inch.

```
FUNCTION AfxPointSizeToDip (BYVAL ptsize AS SINGLE) AS SINGLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *ptsize* | The point size to convert. |

#### Return value

The number of DIP pixels.

---

### AfxPointsToPixelsX

Converts a point size (1/72 of an inch) to pixels. Horizontal resolution.

```
FUNCTION AfxPointsToPixelsX (BYVAL pts AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pts* | The number of points. |

#### Return value

The number of pixels.

---

### AfxPointsToPixelsY

Converts a point size (1/72 of an inch) to pixels. Vertical resolution.

```
FUNCTION AfxPointsToPixelsY (BYVAL pts AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pts* | The number of points. |

#### Return value

The number of pixels.

---

### AfxTwipsPerPixelX

Returns the width of a pixel in twips (horizontal resolution). Pixel dimensions can vary between systems and may not always be square, so separate functions for pixel width and height are required.

```
FUNCTION AfxTwipsPerPixelX () AS LONG
```

#### Return value

The number of twips per pixel.

---

### AfxTwipsPerPixelY

Returns the width of a pixel in twips (vertical resolution). Pixel dimensions can vary between systems and may not always be square, so separate functions for pixel width and height are required.

```
FUNCTION AfxTwipsPerPixelY () AS LONG
```

#### Return value

The number of twips per pixel.

---

### AfxTwipsToPixelsX

Converts twips to pixels. Horizontal resolution.

```
FUNCTION AfxTwipsToPixelsX (BYVAL nTwips AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nTwips* | The number of twips. |

#### Return value

The number of pixels.

---

### AfxTwipsToPixelsY

Converts twips to pixels. Vertical resolution.

```
FUNCTION AfxTwipsToPixelsY (BYVAL nTwips AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nTwips* | The number of twips. |

#### Return value

The number of pixels.

---

### AfxDibLoadImage

Loads a DIB in memory and returns a pointer to it.

```
FUNCTION AfxDibLoadImage (BYVAL pwszFileName AS WSTRING PTR) AS BITMAPFILEHEADER PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFileName* | Path of the bitmap file. |

#### Return value

A pointer to the bitmap file header. You must release it with **CoTaskMemFree** when no longer needed.

---

### AfxDibSaveImage

Saves a DIB to a file.

```
FUNCTION AfxDibSaveImage (BYVAL pwszFileName AS WSTRING PTR, BYVAL pbmfh AS BITMAPFILEHEADER PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFileName* | Path of the bitmap file. |
| *pbmfh* | Pointer to the bitmap file header. |

#### Return value

TRUE if the DIB has been saved successfully; FALSE otherwise.

---

### AfxACLineStatus

Retrieves the AC power status.

```
FUNCTION AfxACLineStatus () AS UBYTE
```

#### Return value

This member can be one of the following values:

| Value  | Description |
| ------ | ----------- |
| 0 | Offline |
| 1 | Online |
| 255 | Unknown status |

---

### AfxBatteryChargeStatus

Retrieves the battery charge status.

```
FUNCTION AfxBatteryChargeStatus () AS UBYTE
```

#### Return value

| Value  | Description |
| ------ | ----------- |
| 1 | High. The battery capacity is at more than 66 percent. |
| 2 | Low. The battery capacity is at less than 33 percent. |
| 4 | Critical. The battery capacity is at less than five percent. |
| 8 | Charging. |
| 128 | No system battery. |
| 255 | Unknown status. Unable to read the battery flag information. |

#### Remarks

The value is zero if the battery is not being charged and the battery capacity is between low and high.

---

### AfxBatteryLifePercent

The percentage of full battery charge remaining.

```
FUNCTION AfxBatteryLifePercent () AS UBYTE
```
#### Return value

This member can be a value in the range 0 to 100, or 255 if status is unknown.

---

### AfxBatteryLifeTime

Retrieves the number of seconds of battery life remaining, or –1 if remaining seconds are unknown or if the device is connected to AC power.

```
FUNCTION AfxBatteryLifeTime () AS LONG
```

### AfxBatteryFullLifeTime

Retrieves the number of seconds of battery life when at full charge, or –1 if full battery lifetime is unknown or if the device is connected to AC power.

```
FUNCTION AfxBatteryFullLifeTime () AS LONG
```

#### Remarks

The system is only capable of estimating BatteryFullLifeTime based on calculations on BatteryLifeTime and BatteryLifePercent. Without smart battery subsystems, this value may not be accurate enough to be useful.

---
