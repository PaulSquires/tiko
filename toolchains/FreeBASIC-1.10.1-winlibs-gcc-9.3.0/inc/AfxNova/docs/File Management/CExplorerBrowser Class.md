# CExplorerBrowser Class

Wraps the **IExplorerBrowser** interface.

**IExplorerBrowser** is a browser object that can be either navigated or that can host a view of a data object. As a full-featured browser object, it also supports an automatic travel log.

The Shell provides a default implementation of **IExplorerBrowser** as CLSID_ExplorerBrowser. Typically, a developer does not need to provide a custom implementation of this interface.

---

### Constructor

Creates an instance of the **IExplorerBrowser** interface.

#### Example

```
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CExplorerBrowser.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "Explorer Browser", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(620, 400)
   ' // Centers the window
   pWindow.Center

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC peb AS CExplorerBrowser PTR

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         ' // Creates an instance of the Explorer Browser
         peb = NEW CExplorerBrowser
         IF peb = NULL THEN RETURN 0
         peb->SetOptions(EBO_SHOWFRAMES)
         DIM fs AS FOLDERSETTINGS
         fs.ViewMode = FVM_DETAILS
         DIM rc AS RECT
         GetClientRect hwnd, @rc
         peb->Initialize(hwnd, @rc, @fs)
         ' // Navigate to the Profile folder
         DIM pidlBrowse AS ITEMIDLIST PTR
         IF SUCCEEDED(SHGetFolderLocation(NULL, CSIDL_PROGRAM_FILES, NULL, 0, @pidlBrowse)) THEN
             peb->BrowseToIDList(pidlBrowse, SBSP_ABSOLUTE)
             ILFree(pidlBrowse)
         END IF
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_SIZE
         ' // Resize the explorer browser
         DIM rc AS REct
         GetClientRect hwnd, @rc
         IF peb THEN peb->SetRect(NULL, rc)
         RETURN 0

      CASE WM_DESTROY
         ' // Destroy the CExplorerBrowser class
         IF peb THEN Delete peb
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

---

### Methods
| Name       | Description |
| ---------- | ----------- |
| [Advise](#advise) | Initiates a connection with IExplorerBrowser for event callbacks. |
| [BroseToIDList](#browsetoidlist) | Browses to a pointer to an item identifier list (PIDL) |
| [BroseToObject](#browsetoobject) | Browses to an object. |
| [Destroy](#destroy) | Destroys the browser. |
| [FillFromObject](#fillfromobject) | Creates a results folder and fills it with items. |
| [GetCurrentView](#getcurrentview) | Gets an interface for the current view of the browser. |
| [GetOptions](#getoptions) | Gets the current browser options. |
| [Initialize](#initialize) | Prepares the browser to be navigated. |
| [NavigateBack](#navigateback) | Navigate back programatically.  |
| [NavigateForward](#navigateforward) | Navigate forward programatically. |
| [NavigateTo](#navigateto) | Navigate to the specified folder. |
| [NavigateToParent](#navigatetoparent) | Navigate to the parent folder. |
| [RemoveAll](#removeall) | Removes all items from the results folder. |
| [SetEmptyText](#setemptytext) | Sets the default empty text. |
| [SetEvents](#setevents) | Sets a connection with **IExplorerBrowserEvents** for event callbacks. |
| [SetFolderSettings](#setfoldersettings) | Sets the folder settings for the current view. |
| [SetOptions](#setoptions) | Sets the current browser options. |
| [SetPropertyBag](#setpropertybag) | Sets the name of the property bag. |
| [SetRect](#setrect) | Sets the size and position of the view windows created by the browser. |
| [Unadvise](#unadvise) | Terminates an advisory connection. |

---

### Auxiliary methods

| Name       | Description |
| ---------- | ----------- |
| [GetLastResult](#getlastresult) | Returns the last result code. |
| [SetResult](#setresult) | Sets the last result code. |
| [GetErrorInfo](#geterrorinfo) | Returns a localized description of the last result code. |
| [GetPtr](#getptr) | Returns a raw pointer to the underlying **IExplorerBrowser** interface. |
| [ObjPtr](#objptr) | Returns an AddRef'ed pointer to the underlying **IExplorerBrowser** interface. |

---

### Events

The **IExplorerBrowserEvents** interface exposes methods for notification of Explorer browser navigation and view creation events.

| Name       | Description |
| ---------- | ----------- |
| [OnNavigationComplete](#onnavigationcomplete) | Notifies clients that the Explorer browser has successfully navigated to a Shell folder. |
| [OnNavigationEnding](#onnavigationpending) | Notifies clients of a pending Explorer browser navigation to a Shell folder. |
| [OnNavigationFailed](#onnavigationfailed) | Notifies clients that the Explorer browser has failed to navigate to a Shell folder. |
| [OnViewCreated](#onviewcreated) | Notifies clients that the view of the Explorer browser has been created and can be modified. |

---

## GetLastResult

Returns the last result code
```
FUNCTION GetLastResult () AS HRESULT
   RETURN m_Result
END FUNCTION
```
---

## SetResult

Sets the last result code.
```
FUNCTION SetResult (BYVAL Result AS HRESULT) AS HRESULT
   m_Result = Result
   RETURN m_Result
END FUNCTION
```
| Parameter | Description |
| --------- | ----------- |
| *Result* | The **HRESULT** error code returned by the methods. |

---

## GetErrorInfo

Returns a description of the last result code.
```
FUNCTION GetErrorInfo (BYVAL nError AS LONG = -1) AS DWSTRING
```
---

## GetPtr

Returns a raw pointer to the underlying **IExplorerBrowser** interface. Don't release this pointer.
```
FUNCTION ObjPtr () AS IExplorerBrowser PTR
```
---

## ObjPtr

Returns an AddRef'ed pointer to the underlying **IExplorerBrowser** interface. You musr release this pointer calling the **Release** method.
```
FUNCTION ObjPtr () AS IExplorerBrowser PTR
```
---

## Initialize

Prepares the browser to be navigated.

```
FUNCTION Initialize (BYVAL hwndParent AS HWND, BYVAL prc AS RECT PTR, _
   BYVAL pfs AS FOLDERSETTINGS PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *hwndParent* | A handle to the owner window or control. |
| *prc* | A pointer to a **RECT** that contains the coordinates of the bounding rectangle that the browser will occupy. The coordinates are relative to *hwndParent*. |
| *pfs* | A pointer to a **FOLDERSETTINGS** structure that determines how the folder will be displayed in the view. If this parameter is **NULL**, then you must call **SetFolderSettings**; otherwise, the default view settings for the folder are used. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

After calling the **Initialize** method, it is the responsibility of the caller to call the **Destroy** method to destroy the browser and free any memory and windowed resources associated with the browser.

The **CExplorerBrowser** class calls the **Destroy** method when the class ends.

---

## Destroy

Destroys the browser.

```
FUNCTION Destroy () AS HRESULT
```

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

If method **Initialize** was called, then method **Destroy** must be called to free resources. Failure to call **Destroy** may cause a memory leak.

The **CExplorerBrowser** class calls the **Destroy** method when the class ends.

---

## Advise

Initiates a connection with **IExplorerBrowser** for event callbacks.

```
FUNCTION Advise (BYVAL psbe AS IExplorerBrowserEvents PTR, BYVAL pdwCookie AS DWORD) AS HRESULT
FUNCTION Advise (BYVAL psbe AS IExplorerBrowserEvents PTR) AS DWORD
```

| Parameter | Description |
| --------- | ----------- |
| *psbe* | A pointer to the **IExplorerBrowserEvents** interface of the object to be advised of **IExplorerBrowser** events. |
| *pdwCookie* | A token that uniquely identifies the event listener. |

#### Return value

First overloaded function: If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

Second overloaded function: Returns token that uniquely identifies the event listener. To get the result code, call the **GetLastResult** method.

#### Remarks

This method is called by an implementer of **IExplorerBrowserEvents**. The implementer (listener) is advised of **ExplorerBrowser** view and navigation events by callback of the methods of **IExplorerBrowserEvents**.

Call **Advise** to initiate an advisory connection prior to the first **IExplorerBrowser** navigation. Callbacks to event listeners are made as the browser is browsing.

The first browse happens synchronously to a call on **BrowseToObject**, or a similar method. Future callbacks happen asynchronously, as the browser browses.

When the connection is no longer needed, call method **Unadvise** to terminate the connection.

The **CExplorerBrowser** class provides the method **SetEvents** that calls the **Advise** methods, stores the cookie and calls **Unadvise** when the class ends.

---

## Unadvise

Terminates an advisory connection.

```
FUNCTION Unadvise (BYVAL dwCookie AS DWORD) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *dwCookie* | A connection token previously returned from **Advise**. Identifies the connection to be terminated. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

Terminates an advisory connection previously established through method **Advise**. The *dwCookie* parameter identifies the connection to terminate. Failure to call **Unadvise**, may result in a memory leak.

The **CExplorerBrowser** class provides the method **SetEvents** that calls the **Advise** methods, stores the cookie and calls **Unadvise** when the class ends.

---

## BrowseToIDList

Browses to a pointer to an item identifier list (PIDL)

```
FUNCTION BrowseToIDList (BYVAL pidl AS LPCITEMIDLIST, BYVAL uFlags AS UINT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pidl* | Type: **PCUIDLIST_RELATIVE**. A pointer to a const **ITEMIDLIST** (item identifier list) that specifies an object's location as the destination to navigate to. This parameter can be **NULL**. |
| *uFlags* | A flag that specifies the category of the *pidl*. This affects how navigation is accomplished. Must be the value zero, or a bitwise combination of the following values. |

| Flag | Description |
| ---- | ----------- |
| **SBSP_ABSOLUTE** | An absolute PIDL, relative to the desktop. |
| **SBSP_RELATIVE** | A relative PIDL, relative to the current folder. |
| **SBSP_PARENT** | Browse to the parent folder, ignore the PIDL. |
| **SBSP_NAVIGATEBACK** | Navigate back, ignore the PIDL. |
| **SBSP_NAVIGATEFORWARD** | Navigate forward, ignore the PIDL. |
| **SBSP_KEEPWORDWHEELTEXT** | Windows Vista and later. This flag indicates that any search text entered by a WordWheel (the Search box in Windows Explorer) should be preserved during this navigation, so that items at the new location are filtered in the same way they were filtered at the previous location. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The parameter *pidl* may be **NULL** if the flags specified in *uFlags* indicate navigation through the built-in TravelLog, that is, SBSP_NAVIGATEBACK or SBSP_NAVIGATEFORWARD.

This method supports only a subset of the SBSP flags listed in the shobjidl.bi file. Consequently, this method returns E_INVALIDARG if SBSP_NEWBROWSER or SBSP_EXPLOREMODE are specified in *uFlags*.

---

## BrowseToObject

Browses to an object.

```
FUNCTION BrowseToObject (BYVAL punk AS IUnknown PTR, BYVAL uFlags AS UINT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *punk* | A pointer to an object to browse to. If the object cannot be browsed, an error value is returned. |
| *uFlags* | A flag that specifies the category of the *pidl*. This affects how navigation is accomplished. Must be the value zero, or a bitwise combination of the following values. |

| Flag | Description |
| ---- | ----------- |
| **SBSP_ABSOLUTE** | An absolute PIDL, relative to the desktop. |
| **SBSP_RELATIVE** | A relative PIDL, relative to the current folder. |
| **SBSP_PARENT** | Browse to the parent folder, ignore the PIDL. |
| **SBSP_NAVIGATEBACK** | Navigate back, ignore the PIDL. |
| **SBSP_NAVIGATEFORWARD** | Navigate forward, ignore the PIDL. |
| **SBSP_KEEPWORDWHEELTEXT** | Windows Vista and later. This flag indicates that any search text entered by a WordWheel (the Search box in Windows Explorer) should be preserved during this navigation, so that items at the new location are filtered in the same way they were filtered at the previous location. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

*uFlags* may be any of the **EXPLORER_BROWSER_FILL_FLAGS** or any of the flags defined in **BrowseObject**'s *wFlags* parameter, except for flags that indicate navigation.

This method calls **GetIDList** and browses to the pidl returned. It operates in the same way as **BrowseToIDList**, except that *punk* cannot be **NULL**. Standard usage is to browse to an **IShellFolder** or an **IShellItem**. An error will be returned if the object passed in cannot be browsed through. An object that can be browsed through implements either **IPersistFolder2** or **IPersistIDList**.

The first navigation of **IExplorerBrowser** is synchronous. After that, all navigations are asynchronous. As a result, calls to **BrowseToObject** will succeed if you properly set up the pending navigation, but that does not guarantee the navigation will succeed. To be informed of success and failure, clients should implement **IExplorerBrowserEvents** and respond appropriately in **OnNavigationComplete** and **OnNavigationFailed**.

---

## FillFromObject

Creates a results folder and fills it with items.

```
FUNCTION FillFromObject (BYVAL punk AS IUnknown PTR, _
   BYVAL dwFlags AS EXPLORER_BROWSER_FILL_FLAGS) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *punk* | An interface pointer on the source object that will fill the **IResultsFolder**. This can be an **IDataObject** or any object that can be used with **INamespaceWalk**. |
| *dwFlags* | One of the **EXPLORER_BROWSER_FILL_FLAGS** values. |

**EXPLORER_BROWSER_FILL_FLAGS**

| Flag | Description |
| ---- | ----------- |
| **EBF_NONE** | No flags. |
| **EBF_SELECTFROMDATAOBJECT** | Causes **FillFromObject** to first populate the results folder with the contents of the parent folders of the items in the data object, and then select only the items that are in the data object. |
| **EBF_NODROPTARGET** | Do not allow dropping on the folder. In other words, do not register a drop target for the view. Applications can then register their own drop targets. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The object passed via interface pointer *punk* fills **IResultsFolder**.

The parameter *dwFlags* can be any of the **EXPLORER_BROWSER_FILL_FLAGS** or any of the flags defined in **BrowseObject**'s *wFlags* parameter, except for flags that indicate navigation.

The parameter punk can be any object that **INamespaceWalk** can consume. If called with **EBF_SELECTFROMDATAOBJECT**, *punk* must be an **IDataObject** and the namespace will be walked at the parent level of the data object, including all peer items, but selecting only those contained in the data object. This flag is most commonly used when **FOLDERSETTINGS** have *FWF_CHECKSELECT* enabled, allowing check-selection of a set of items that have been compiled in the data object.

**Note**. If a pointer to an item identifier list (PIDL) in the data object is fully qualified, the parent folder cannot be successfully walked, because desktop folder items would be added to the list.
 
This method may be called more than once, with each successive call adding additional items to the view. **RemoveAll** may be called to clear the contents of the results folder. This function should be called with **EBF_NODROPTARGET** to prevent users from drag dropping new items into the view, unless this is desired. Setting **EBO_NAVIGATEONCE** is also recommended so that the browser will stay in the **ResultsFolder**, preventing the user from navigating to a folder that may be represented in the data object.

To manipulate items in the results folder directly, call **GetCurrentView** to get the view from **ExplorerBrowser** and then ask the view for results folder using **GetFolder**. Using the obtained results folder enables manipulation of the data in the folder with more flexibility than with the methods that **IExplorerBrowser** provides.

---

## GetCurrentView

Gets an interface for the current view of the browser.

```
FUNCTION GetCurrentView (BYVAL riid AS IID PTR, BYVAL ppv AS ANY PTR PTR) AS HRESULT
FUNCTION GetCurrentView (BYVAL riid AS IID PTR) AS ANY PTR
```

| Parameter | Description |
| --------- | ----------- |
| *riid* | A reference to the desired interface ID. |
| *ppv* | When this method returns, contains the interface pointer requested in *riid*. This will typically be **IShellView**, **IShellView2**, **IFolderView**, or a related interface. |

#### Return value

First overloaded method: If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

Second overloaded method: The interface pointer requested in *riid*.

---

## SetRect

Sets the size and position of the view windows created by the browser.

```
FUNCTION SetRect (BYVAL phdwp AS HDWP PTR, BYVAL rcBrowser AS RECT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *phdwp* | A pointer to a **DeferWindowPos** handle. This parameter can be **NULL**. |
| *rcBrowser* | The coordinates that the browser will occupy. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

Coordinates are relative to the *hwndParent* passed in **Initialize**.

---

## SetPropertyBag

Sets the name of the property bag.

```
FUNCTION SetPropertyBag (BYREF wszPropertyBag AS WSTRING) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *wszPropertyBag* | A null-terminated, Unicode string that contains the name of the property bag. View state information that is specific to the application of the client is stored (persisted) using this name. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

ExplorerBrowser can retrieve the properties stored in the property bag by calling function **SHGetViewStatePropertyBag**. ExplorerBrowser writes to this property bag which is also stored (persisted) in the registry. Persistence occurs automatically when ExplorerBrowser destroys the current view, begins a navigation, or is destroyed. After any of these events, it writes information about the view state in case it has been modified by the user.

If no properties have been stored, the default view state of the ExplorerBrowser is used. The default view state is the view state that the user has set for a particular location, or if the view state for a location has not been set (never modified by the user), then the default view state is based on the template for the file type (for example, documents, music and pictures) at the location. All Explorer windows use the same sequence to determine the default view state.

---

## SetEmptyText

Sets the default empty text.

```
FUNCTION SetEmptyText (BYREF wszEmptyText AS WSTRING) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *wszEmptyText* | A null-terminated, Unicode string that contains the empty text. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

The text set is displayed when the Explorer browser view is empty.

This method applies the empty text string to the current view and sets the default empty text string that is used when navigating to another location.

If this method is not called, the empty text will default to the text provided by the folder that has been navigated to.

---

## SetFolderSettings

Sets the folder settings for the current view.

```
FUNCTION SetFolderSettings (BYVAL pfs AS FOLDERSETTINGS PTR) AS HRESULT
FUNCTION SetFolderSettings (BYVAL ViewMode AS UINT, BYVAL fFlags AS UINT) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pfs* | A pointer to a [FOLDERSETTINGS](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure that contains the folder settings to be applied. |

| Parameter | Description |
| --------- | ----------- |
| *ViewMode* | Folder view mode. One of the [FOLDERVIEWMODE](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/ne-shobjidl_core-folderviewmode) values. |
| *fFlags* | A set of flags that indicate the options for the folder. This can be zero or a combination of the [FOLDERFLAGS](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/ne-shobjidl_core-folderflags) values. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

This method also changes the default that will be applied when navigating to another location.

To ensure the view state is preserved across sessions, specify the persistence name using **SetPropertyBag**.

---

## SetOptions

Sets the current browser options.

```
FUNCTION SetOptions (BYVAL dwFlag AS EXPLORER_BROWSER_OPTIONS) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *dwFlag* | One or more [EXPLORER_BROWSER_OPTIONS](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/ne-shobjidl_core-explorer_browser_options) flags to be set. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

This action overrides any previous options.

Frames are disabled by default. To enable frames and get the default set of panes, set the **EBO_SHOWFRAMES** flag using the **SetOptions** method. The default panes, listed as **IExplorerPaneVisibility** constants, are these:

* EP_NavPane
* EP_Commands
* EP_Commands_Organize
* EP_Commands_View
* EP_DetailsPane
* EP_PreviewPane
* EP_QueryPane
* EP_AdvQueryPane
* EP_StatusBar
* EP_Ribbon

See [IExplorerPaneVisibility.GetPaneState](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nf-shobjidl_core-iexplorerpanevisibility-getpanestate) for more information.

---

## GetOptions

Gets the current browser options.

```
FUNCTION GetOptions (BYVAL pdwFlag AS EXPLORER_BROWSER_OPTIONS PTR) AS HRESULT
FUNCTION GetOptions () AS EXPLORER_BROWSER_OPTIONS
```

| Parameter | Description |
| --------- | ----------- |
| *pdwFlag* | When this method returns, contains the current [EXPLORER_BROWSER_OPTIONS](https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/ne-shobjidl_core-explorer_browser_options) for the browser. |

#### Return value

First overloaded function: If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

Second overloaded function: Returns the current browser options.

---

## RemoveAll

Removes all items from the results folder.

```
FUNCTION RemoveAll () AS HRESULT
```

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

## NavigateBack

Navigate back programatically.

```
FUNCTION NavigateBack () AS HRESULT
```

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

## NavigateForward

Navigate forward programatically.

```
FUNCTION NavigateForward () AS HRESULT
```

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

## NavigateToParent

Navigate to the parent folder programatically.

```
FUNCTION NavigateToParent () AS HRESULT
```

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

## NavigateTo

Navigate to the specified folder.

```
FUNCTION NavigateTo (BYREF wszPath AS WSTRING) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *wszPath* | The path to the folder. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

---

## SetEvents

Sets a connection with **IExplorerBrowserEvents** for event callbacks.

```
FUNCTION SetEvents (BYVAL pebe AS IExplorerBrowserEvents PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pebe* | A pointer to the **IExplorerBrowserEvents** interface of the object to be advised of **IExplorerBrowser** events. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Example
```
#define _WIN32_WINNT &h0602
#define _CEXPBROW_DEBUG_ 1
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CExplorerBrowser.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "Explorer Browser", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(620, 400)
   ' // Centers the window
   pWindow.Center

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ########################################################################################
' CExplorerBrowserEventsImpl class
' Implementation of the IExplorerBrowserEvents callback interface
' ########################################################################################
TYPE CExplorerBrowserEventsImpl EXTENDS CExplorerBrowserEvents

   DECLARE FUNCTION OnNavigationPending (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE ) AS HRESULT
   DECLARE FUNCTION OnViewCreated (BYVAL psv AS IShellView PTR) AS HRESULT
   DECLARE FUNCTION OnNavigationComplete (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE ) AS HRESULT
   DECLARE FUNCTION OnNavigationFailed (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE ) AS HRESULT

END TYPE

' ========================================================================================
' Notifies clients of a pending Explorer browser navigation to a Shell folder.
' ========================================================================================
FUNCTION CExplorerBrowserEventsImpl.OnNavigationPending (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE ) AS HRESULT
   CEXPBROW_DP("- pidlFolder: " & WSTR(pidlFolder))
   DIM wszName AS WSTRING * MAX_PATH
   SHGetPathFromIDListW(pidlFolder, @wszName)
   CEXPBROW_DP("- " & wszName)
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Notifica a los clientes que se ha creado la vista del explorador Explorador y que se pueden modificar.
' ========================================================================================
FUNCTION CExplorerBrowserEventsImpl.OnViewCreated (BYVAL psv AS IShellView PTR) AS HRESULT
   CEXPBROW_DP("- pShellView: " & WSTR(psv))
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Notifies clients that the Explorer browser has successfully navigated to a Shell folder.
' ========================================================================================
FUNCTION CExplorerBrowserEventsImpl.OnNavigationComplete (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE ) AS HRESULT
   CEXPBROW_DP("- pidlFolder: " & WSTR(pidlFolder))
   DIM wszName AS WSTRING * MAX_PATH
   SHGetPathFromIDListW(pidlFolder, @wszName)
   CEXPBROW_DP("- " & wszName)
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Notifies clients that the Explorer browser has failed to navigate to a Shell folder.
' ========================================================================================
FUNCTION CExplorerBrowserEventsImpl.OnNavigationFailed (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE ) AS HRESULT
   CEXPBROW_DP("- pidlFolder: " & WSTR(pidlFolder))
   DIM wszName AS WSTRING * MAX_PATH
   SHGetPathFromIDListW(pidlFolder, @wszName)
   CEXPBROW_DP("- " & wszName)
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ########################################################################################
' Main window procedure
' ########################################################################################

FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC peb AS CExplorerBrowser PTR

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         ' // Creates an instance of the Explorer Browser
         peb = NEW CExplorerBrowser
         IF peb = NULL THEN RETURN 0
         peb->SetOptions(EBO_SHOWFRAMES)
         DIM fs AS FOLDERSETTINGS
         fs.ViewMode = FVM_DETAILS
         DIM rc AS RECT
         GetClientRect hwnd, @rc
         peb->Initialize(hwnd, @rc, @fs)
         ' // Set events
         DIM pebe AS ANY PTR = NEW CExplorerBrowserEventsImpl
         peb->SetEvents(pebe)
         ' // Navigate to the Profile folder
         DIM pidlBrowse AS ITEMIDLIST PTR
         IF SUCCEEDED(SHGetFolderLocation(NULL, CSIDL_PROGRAM_FILES, NULL, 0, @pidlBrowse)) THEN
             peb->BrowseToIDList(pidlBrowse, SBSP_ABSOLUTE)
             ILFree(pidlBrowse)
         END IF
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
         END SELECT
         RETURN 0

      CASE WM_SIZE
         ' // Resize the explorer browser
         DIM rc AS REct
         GetClientRect hwnd, @rc
         IF peb THEN peb->SetRect(NULL, rc)
         RETURN 0

      CASE WM_DESTROY
         ' // Destroy the CExplorerBrowser class
         IF peb THEN Delete peb
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```
---

## OnNavigationComplete

Notifies clients that the Explorer browser has successfully navigated to a Shell folder.

```
FUNCTION OnNavigationComplete (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pidlFolder* | A PIDL that specifies the folder. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

This method is called after method **OnViewCreated**, assuming a successful view creation.

After a navigation and view creation, either **OnNavigationComplete** or **OnNavigationFailed** is called depending on whether the destination could be navigated to. For example, a failure to navigate includes a destination that is not reached either because there is no route to the path or the user has canceled.

---

## OnNavigationFailed

Notifies clients that the Explorer browser has failed to navigate to a Shell folder.

```
FUNCTION OnNavigationFailed (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pidlFolder* | A PIDL that specifies the folder. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

This method is called after method **OnViewCreated**, assuming a successful view creation.

After a navigation and view creation, either **OnNavigationComplete** or **OnNavigationFailed** is called, depending on whether the destination could be navigated to. For example, a failure to navigate includes a destination that is not reached either because there is no route to the path or the user has canceled.

---

## OnNavigationPending

Notifies clients of a pending Explorer browser navigation to a Shell folder.

```
FUNCTION OnNavigationPending (BYVAL pidlFolder AS PCIDLIST_ABSOLUTE) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *pidlFolder* | A PIDL that specifies the folder. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

Explorer browser calls this method before it navigates to a folder, that is, before calling **OnNavigationFailed** or **OnNavigationComplete**.

Returning any failure code from this method, including **E_NOTIMPL**, will cancel the navigation.

---

## OnViewCreated

Notifies clients that the view of the Explorer browser has been created and can be modified.

```
FUNCTION OnViewCreated (BYVAL psv AS IShellView PTR) AS HRESULT
```

| Parameter | Description |
| --------- | ----------- |
| *psv* | A pointer to an **IShellView** interface. |

#### Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

#### Remarks

An Explorer browser calls this method to enable the client to perform any modifications to the Explorer browser view before it is shown; for example, to set view modes or folder flags.

---
