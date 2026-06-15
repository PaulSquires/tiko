# CWebView2 Class

The Microsoft Edge WebView2 control enables you to host web content in your application using Chromium-based Microsoft Edge as the rendering engine. [WebView2 API Reference](https://learn.microsoft.com/en-us/microsoft-edge/webview2/webview2-api-reference?tabs=dotnetcsharp).

The `CWebView2` class provides a FreeBasic-friendly wrapper around the Microsoft Edge WebView2 control, enabling developers to embed modern web content (HTML, CSS, JavaScript) directly into native Windows applications. It abstracts the complexity of COM interop by exposing a simplified interface that integrates seamlessly with FreeBasic code, while still giving access to the full power of the underlying WebView2 API.

This class is designed to:

* Create and manage WebView2 environments using the installed Edge runtime or a specified browser executable.
* Expose core functionality such as navigation, script execution, DOM interaction, and event handling.
* Provide error handling and diagnostics through methods like **GetErrorInfo** and **GetLastResult**, making it easier to debug and maintain applications.
* Support customization via environment options, settings, and event callbacks, allowing developers to tailor the embedded browser to their application’s needs.

By encapsulating the WebView2 COM interfaces into a structured FreeBasic class, `CWebView2` bridges the gap between modern web technologies and native desktop development. It empowers FreeBasic programmers to build hybrid applications that combine the performance and flexibility of native code with the rich UI capabilities of the web.

**Constructor Overview**

Unlike traditional APIs where a function call immediately returns a usable object, WebView2 works asynchronously. When you request the creation of a WebView environment, the operation is dispatched, and the actual result is delivered later through a callback interface. This design allows WebView2 to perform initialization tasks (loading the Edge runtime, preparing the user data folder, etc.) without blocking your application.

The `CWebView2` class hides this complexity by implementing internally:

**CWebView2EnvironmentCompletedHandlerInternal**: Wraps **ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler**

**CWebView2ControllerCompletedHandlerInternal**: Wraps **ICoreWebView2CreateCoreWebView2ControllerCompletedHandler**

These handlers receive the completion notifications from WebView2 and finalize the setup of the control. As a result, the constructor doesn’t return a fully initialized WebView immediately. Instead, you use the **IsReady** method to check when the control is available for navigation and interaction.

**Usage Patterns**

Usage 1: Default runtime and user data folder
```
DIM pWebView2 AS CWebView2 = hWin
```
Usage 2: Custom user data folder
```
DIM pWebView2 AS CWebView2 = CWebView2(hWin, UserFolder)
```
Default runtime: Relies on the installed Edge runtime and default profile storage.

Custom folder: Calls **CreateCoreWebView2EnvironmentWithOptions**, allowing you to isolate cookies, cache, and storage in a separate profile. This is ideal for multi-tab or multi-user scenarios, though startup may be slightly slower.

We can also use a subfolder in te Windows temporary folder for this purpose:

```
' // Use always the same folder for the WebView2 files
' // Here we are using a subfolder in the temporary folder
DIM wszTemp AS WSTRING * 260
GetTempPathW(260, @wszTemp)
DIM wszUserData AS WSTRING * 260
wszUserData = wszTemp & "AfxNovaWebView2"

' // Create an instance of WebView
DIM pWebView2 AS CWebView2 = CWebView2(hWin, @wszUserData)
```

Usando DWSTRING:

DIM dwsUserDataFolder AS DWSTRING = AfxGetTempPath & "AfxNovaWebView2"
DIM pWebView2 AS CWebView2 = CWebView2(hWin, dwsUserDataFolder)
```
```

**Key Takeaway**

WebView2 creation is not immediate. You send a request, and the control becomes ready only after the asynchronous callbacks complete. The `CWebView2` class encapsulates this pattern, so developers simply construct the object and then call **IsReady** before using it — no need to manually wire up completion handlers.

---

| Name       | Description |
| ---------- | ----------- |
| [Constructor](#constructor) | Creates an instance of the `CWebView2`class. |
| [GetControllerPtr](#getcontrollerptr) | Returns a raw pointer to the **Afx_ICoreWebView2Controller** interface. |
| [GetEnvironmentPtr](#getenvironmentptr) | Returns a raw pointer to the **Afx_ICoreWebView2Environment** interface. |
| [GetWebViewPtr](#getwebviewptr) | Returns a raw pointer to the **Afx_ICoreWebView2** interface. |
| [GetCoreWebView](#getcorewebview) | Returns an addref'ed pointer to the **Afx_ICoreWebView2** interface. |
| [IsReady](#isready) | Chekcs if `WebView2` is ready to be used.. |

---

### Functions

| Name       | Description |
| ---------- | ----------- |
| [CompareBrowserVersions](#comparebrowserversions) | Get the browser version info including channel name if it is not the WebView2 Runtime. |
| [CreateCoreWebView2Environment](#createcorewebview2environment) | Creates an evergreen WebView2 Environment using the installed Edge version. |
| [CreateCoreWebView2EnvironmentWithDetails](#createcorewebview2environmentwithdetails) | Creates an environment with a custom version of Edge, user data directory and/or additional browser switches. |
| [CreateCoreWebView2EnvironmentWithOptions](#createcorewebview2environmentwithoptions) | Creates a WebView2 environment with a custom version of WebView2 Runtime, user data folder, and with or without additional options. |
| [GetAvailableCoreWebView2BrowserVersionString](#getavailablecorewebview2browserversionstring) | Get the browser version info including channel name if it is not the WebView2 Runtime. |

---

### Helper functions

| Name       | Description |
| ---------- | ----------- |
| [AfxCWebView2Ptr](#afxcwebview2ptr) | Returns a raw pointer to the **CWebView** class. |
| [AfxSaveTempHtmlFile](#afxsavetemphtmlfile) | Saves the contents of an html script to a temporary file. |

---

### Error and result codes

| Name       | Description |
| ---------- | ----------- |
| [GetErrorInfo](#geterrorinfo) | Returns a localized description of the specified error code. |
| [GetLastResult](#getlastresult) | Returns the last result code. |
| [SetResult](#setresult) | Sets the last result code. |

---

### Creation Callbacks

Two objects are essential to the lifecycle of a `WebView2` control: the environment and the controller. Unlike normal events that use add_ and remove_ methods, these objects are created asynchronously by the `WebView2` runtime and delivered through completion handlers.

**Environment** (ICoreWebView2Environment)

Represents the browser engine instance used by `WebView2`.

Created by calling **CreateCoreWebView2Environment**.

The runtime does not return the environment immediately; instead, it invokes the **CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal** once creation is finished.

`CWebView2` receives the environment pointer through this callback, allowing initialization to continue.

**Controller** (ICoreWebView2Controller)

Manages the WebView control and its interaction with the host window.

Created by calling **CreateCoreWebView2Controller** on the environment.

Again, the runtime delivers the controller asynchronously via the **CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal**.

Once the controller is available, the associated **ICoreWebView2** object can be retrieved and used for navigation, scripting, and event subscription.

| Name       | Description |
| ---------- | ----------- |
| [CWebView2CreateCoreWebView2EnvironmentCompletedHandler](#cwebview2createcorewebview2environmentcompletedhandler) | Implementation of the ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler callback interface. |
| [CWebView2CreateCoreWebView2ControllerCompletedHandler](#cwebview2createcorewebview2controllercompletedhandler) | Implementation of the ICoreWebView2CreateCoreWebView2ControllerCompletedHandler callback interface. |

---

### CWebView2 methods

| Name       | Description |
| ---------- | ----------- |
| [AddHostObjectToScript](#hostobjecttoscript) | Add the provided host object to script running in the WebView with the specified name. |
| [AddScriptToExecuteOnDocumentCreated](#scripttoexecuteondocumentcreated) | Add the provided JavaScript to a list of scripts that should be run after the global object has been created, but before the HTML document has been parsed and before any other script included by the HTML document is run. |
| [AddWebResourceRequestedFilter](#webresourcerequestedfilter) | This method is deprecated and does not behave as expected for iframes. |
| [CallDevToolsProtocolMethod](#callDevToolsProtocolMethod) | Runs an asynchronous **DevToolsProtocol** method. |
| [CanGoBack](#cangoback) | TRUE if the WebView is able to navigate to the previous page in the navigation history. |
| [CanGoForward](#cangoforward) | TRUE if the WebView is able to navigate to a next page in the navigation history. |
| [CapturePreview](#capturepreview) | Capture an image of what WebView is displaying. |
| [Close](#close) | Closes the WebView and cleans up the underlying browser instance. |
| [ExecuteScript](#executescript) | Run JavaScript code from the javascript parameter in the current top-level document rendered in the WebView. |
| [GetBounds](#getbounds) | Gets the WebView bounds. |
| [GetBrowserProcessId](#getbrowserprocessid) | The process ID of the browser process that hosts the WebView. |
| [GetContainsFullScreenElement](#getcontainsfullscreenelement) | TRUE if the WebView is able to navigate to a next page in the navigation history. |
| [GetDevToolsProtocolEventReceiver](#getdevtoolsprotocoleventreceiver) | Get a DevTools Protocol event receiver that allows you to subscribe to a DevTools Protocol event. |
| [GetIsVisible](#getisvisible) | The **IsVisible** property determines whether to show or hide the WebView2. |
| [GetParentWindow](#getparentwindow) | The parent window provided by the app that this WebView is using to render content. |
| [GetSource](#getsource) | The URI of the current top level document. |
| [GetZoomFactor](#getzoomfactor) | The zoom factor for the WebView. |
| [GoBack](#goback) | Navigates the WebView to the previous page in the navigation history. |
| [GoForward](#goforward) | Navigates the WebView to the next page in the navigation history. |
| [MoveFocus](#movefocus) | Moves focus into WebView. |
| [Navigate](#navigate) | Cause a navigation of the top-level document to run to the specified URI. |
| [NavigateToString](#navigatetostring) | Initiates a navigation to htmlContent as source HTML of a new document. |
| [NotifyParentWindowPositionChanged](#notifyparentwindowpositionchanged) | This is a notification separate from Bounds that tells WebView that the main WebView parent (or any ancestor) HWND moved. |
| [OpenDevToolsWindow](#opendevtoolswindow) | Opens the DevTools window for the current document in the WebView. |
| [PostWebMessageAsJson](#postwebmessageasjson) | Post the specified webMessage to the top level document in this WebView. |
| [PostWebMessageAsString](#postwebmessageasstring) | Posts a message that is a simple string rather than a JSON string representation of a JavaScript object. |
| [Reload](#reload) | Reload the current page. |
| [RemoveHostObjectToScript](#hostobjecttoscript) | Remove the host object specified by the name so that it is no longer accessible from JavaScript code in the WebView. |
| [RemoveScriptToExecuteOnDocumentCreated](#scripttoexecuteondocumentcreated) | Remove the corresponding JavaScript added using AddScriptToExecuteOnDocumentCreated with the specified script ID. |
| [RemoveWebResourceRequestedFilter](#webresourcerequestedfilter) | Remove an event handler previously added with AddWebResourceRequestedFilter. |
| [SetBounds](#setbounds) | Sets the **Bounds** property. |
| [SetIsVisible](#setisvisible) | Sets the IsVisible property. |
| [SetParentWindow](#setparentwindow) | Sets the parent window for the WebView. |
| [SetZoomFactor](#setzoomfactor) | Sets the **ZoomFactor** property. |
| [Stop](#stop) | Stop all navigations and pending resource fetches. Does not stop scripts. |

---

### Settings properties

| Name       | Description |
| ---------- | ----------- |
| [GetSettings](#getsettings) | Gets a pointer to the **ICoreWebView2Settings** interface. |
| [AreDefaultContextMenusEnabled](#aredefaultcontextmenusenabled) | Determines whether the default context menus are shown to the user in WebView. |
| [AreDefaultScriptDialogsEnabled](#aredefaultscriptdialogsenabled) | Determines whether WebView renders the default JavaScript dialog box. |
| [AreDevToolsEnabled](#aredevtoolsenabled) | Determines whether the user is able to use the context menu or keyboard shortcuts to open the DevTools window. |
| [AreHostObjectsAllowed](#arehostobjectsallowed) | Determines whether host objects are accessible from the page in WebView. |
| [IsBuiltInErrorPageEnabled](#isbuiltinerrorpageenabled) | Determines whether to disable built in error page for navigation failure and render process failure. |
| [IsScriptEnabled](#isscriptenabled) | Determines whether running JavaScript is enabled in all future navigations in the WebView. |
| [IsStatusBarEnabled](#isstatusbarenabled) | Determines whether the status bar is displayed. |
| [IsWebMessageEnabled](#iswebmessageenabled) | Determines whether communication from the host to the top-level HTML document of the WebView is allowed. |
| [IsZoomControlEnabled](#iszoomcontrolenabled) | Determines whether the user is able to impact the zoom of the WebView. |

---

### Events

| Name       | Description |
| ---------- | ----------- |
| [AddAcceleratorKeyPressed](#acceleratorkeypressed) | Adds an event handler for the AcceleratorKeyPressed event. |
| [RemoveAcceleratorKeyPressed](#acceleratorkeypressed) | Removes an event handler previously added with AddAcceleratorKeyPressed. |
| [AddContainsFullScreenElementChanged](#containsfullscreenelementchanged) | Adds an event handler for the AcceleratorKeyPressed event. |
| [RemoveContainsFullScreenElementChanged](#containsfullscreenelementchanged) | Remove an event handler previously added with AddContainsFullScreenElementChanged. |
| [AddContentLoading](#contentloading) | Add an event handler for the ContentLoading event. |
| [RemoveContentLoading](#contentloading) | Remove an event handler previously added with AddContentLoading. |
| [AddDocumentTitleChanged](#documenttitlechanged) | Add an event handler for the DocumentTitleChanged event. |
| [RemoveDocumentTitleChanged](#documenttitlechanged) | Remove an event handler previously added with AddDocumentTitleChanged. |
| [AddFrameNavigationCompleted](#framenavigationcompleted) | Add an event handler for the FrameNavigationCompleted event. |
| [RemoveFrameNavigationCompleted](#framenavigationcompleted) | Remove an event handler previously added with AddFrameNavigationCompleted. |
| [AddFrameNavigationStarting](#framenavigationstarting) | Add an event handler for the FrameNavigationStarting event. |
| [RemoveFrameNavigationStarting](#framenavigationstarting) | Remove an event handler previously added with AddFrameNavigationStarting. |
| [AddGotFocus](#gotfocus) | Adds an event handler for the GotFocus event. |
| [RemoveGotFocus](#gotfocus) | Removes an event handler previously added with AddGotFocus. |
| [AddLostFocus](#lostfocus) | Adds an event handler for the LostFocus event. |
| [RemoveLostFocus](#lostfocus) | Removes an event handler previously added with AddLostFocus. |
| [AddHistoryChanged](#historychanged) | Add an event handler for the HistoryChanged event. |
| [RemoveHistoryChanged](#historychanged) | Remove an event handler previously added with AddHistoryChanged. |
| [AddMoveFocusRequested](#movefocusrequested) | Adds an event handler for the MoveFocusRequested event. |
| [RemoveMoveFocusRequested](#focusrequested) | Removes an event handler previously added with AddMoveFocusRequested. |
| [AddNavigationCompleted](#navigationcompleted) | Add an event handler for the NavigationCompleted event. |
| [RemoveNavigationCompleted](#navigationcompleted) | Remove an event handler previously added with AddNavigationCompleted. |
| [AddNavigationStarting](#navigationstarting) | Add an event handler for the NavigationStarting event. |
| [RemoveNavigationStarting](#navigationstarting) | Remove an event handler previously added with AddNavigationStarting. |
| [AddNewWindowRequested](#newwindowrequested) | Add an event handler for the NewWindowRequested event. |
| [RemoveNewWindowRequested](#newwindowrequested) | Remove an event handler previously added with AddNewWindowRequested. |
| [AddPermissionRequested](#permissionrequested) | Add an event handler for the PermissionRequested event. |
| [RemovePermissionRequested](#permissionrequested) | Remove an event handler previously added with AddPermissionRequested. |
| [AddProcessFailed](#processfailed) | Add an event handler for the ProcessFailed event. |
| [RemoveProcessFailed](#processfailed) | Remove an event handler previously added with AddProcessFailed. |
| [AddScriptDialogOpening](#scriptdialogopening) | Add an event handler for the ScriptDialogOpening event. |
| [RemoveScriptDialogOpening](#scriptdialogopening) | Remove an event handler previously added with AddScriptDialogOpening. |
| [AddSourceChanged](#sourcechanged) | Add an event handler for the SourceChanged event. |
| [RemoveSourceChanged](#sourcechanged) | Remove an event handler previously added with AddSourceChanged. |
| [AddWebMessageReceived](#webmessagereceived) | Add an event handler for the WebMessageReceived event. |
| [RemoveWebMessageReceived](#webmessagereceived) | Remove an event handler previously added with AddWebMessageReceived. |
| [AddWebResourceRequested](#webresourcerequested) | Add an event handler for the WebResourceRequested event. |
| [RemoveWebResourceRequested](#webresourcerequested) | Remove an event handler previously added with AddWebResourceRequested. |
| [AddWindowCloseRequested](#windowcloserequested) | Add an event handler for the WindowCloseRequested event. |
| [RemoveWindowCloseRequested](#windowcloserequested) | Remove an event handler previously added with AddWindowCloseRequested. |
| [AddZoomFactorChanged](#zoomfactorchanged) | Adds an event handler for the ZoomFactorChanged event. |
| [RemoveZoomFactorChanged](#zoomfactorchanged) | Remove an event handler previously added with AddZoomFactorChanged. |

---

### Constructor

Creates an instance of the `CWebView2`class.

```
CONSTRUCTOR CWebView2 (BYVAL hWin AS HWND, BYVAL pUserDataFolder AS WSTRING PTR = NULL)
CONSTRUCTOR CWebView2 (BYVAL hWin AS HWND, BYREF wszUserDataFolder AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | [in] Handle of the window that will host the WebView control. |
| *pUserDataFolder* | [in] Path of the folder where WebView2 will create the profile files. If You don't specify a folder, WebView2 will create one with the name of the application and the WebView2 suffix, e.g. MyApp.exe.WebView2. |
| *wszUserDataFolder* | [in] Path of the folder where WebView2 will create the profile files.|

#### Flow diagram

```
[Application] 
     |
     |  Calls CWebView2(hWnd, userDataFolder)
     v
[CWebView2 Constructor]
     |
     |  -> Calls CreateCoreWebView2EnvironmentWithOptions(...)
     |       with a pointer to the CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal completion handler
     v
[CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal .Invoke]
     |
     |  Receives pointer to ICoreWebView2Environment
     |  -> Stores it in m_pEnv
     |  -> Calls CreateCoreWebView2Controller(...)
     |       with apointer to the CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal completion handler
     v
[CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal.Invoke]
     |
     |  Receives pointer to ICoreWebView2Controller
     |  -> Stores it in m_pController
     |  -> Obtains a pointer to the ICoreWebView2 interface and stores it in m_pWebView
     v
[CWebView2 Ready]
     |
     |  Programmer can now call:
     |     .Navigate("https://...")
     |     .MoveFocus(...)
     |     .ExecuteScript(...)
     v
[Normal WebView Usage]
```

#### Example

```
#include once "AfxNova/CWindow.inc"
#include once "AfxNova/CWebView2.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ########################################################################################
' CWebView2NavigationCompletedEventHandlerImpl class
' Implementation of the ICoreWebView2NavigationCompletedEventHandler callback interface.
' ########################################################################################
TYPE CWebView2NavigationCompletedEventHandlerImpl EXTENDS CWebView2NavigationCompletedEventHandler

   DECLARE FUNCTION Invoke (BYVAL sender AS Afx_ICoreWebView2 PTR, BYVAL args AS Afx_ICoreWebView2NavigationCompletedEventArgs PTR) AS HRESULT
   DECLARE CONSTRUCTOR (BYVAL pWebView2 AS CWebView2 PTR)
   DECLARE DESTRUCTOR

   m_pWebView2 AS CWebView2 PTR
   m_token AS EventRegistrationToken

END TYPE
' ########################################################################################

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

   ' // Create the main window
   DIM pWindow AS CWindow
   DIM hWin AS HWND = pWindow.Create(NULL, "WebView2", @WndProc)
   ' // Set its client size
   pWindow.SetClientSize(1050, 500)
   ' // Center the window
   pWindow.Center

   ' // Create an instance of WebView
   DIM pWebView2 AS CWebView2 = CWebView2(hWin, ExePath)
   ' // Wait until is ready
   IF pWebView2.IsReady THEN
      ' // Set a navigation handler
      DIM pEnv AS CWebView2NavigationCompletedEventHandlerImpl PTR
      pEnv = NEW CWebView2NavigationCompletedEventHandlerImpl(@pWebView2)
      ' // Set an event handler for NewWindow
      DIM pNewWindowHandler AS CWebView2NewWindowRequestedEventHandlerImpl PTR
      pNewWindowHandler = NEW CWebView2NewWindowRequestedEventHandlerImpl(@pWebView2, TRUE)
      ' // Navigate to a web page
      pWebView2.Navigate("https://www.planetsquires.com/protect/forum/index.php")
      ' // Set the focus in the web page
      pWebView2.MoveFocus(COREWEBVIEW2_MOVE_FOCUS_REASON_PROGRAMMATIC)
   END IF

   ' // Dispatch Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window callback procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC hFocus AS HWND

   SELECT CASE uMsg

      CASE WM_COMMAND
         
         SELECT CASE GET_WM_COMMAND_ID(wParam, lParam)

            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE WM_SIZE
         ' // Resize the WebView
         DIM pWebView2 AS CWebView2 PTR = AfxCWebView2Ptr(hWnd)
         IF pWebView2 THEN
            DIM rc AS RECT
            IF GetClientRect(hWnd, @rc) THEN
               pWebView2->SetBounds(rc)
            ENDIF
         END IF

    	CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================


' ########################################################################################
' Implementation of the CWebView2NavigationCompletedEventHandlerInternal class
' ########################################################################################

' ========================================================================================
CONSTRUCTOR CWebView2NavigationCompletedEventHandlerInternal (BYVAL pWebView2 AS CWebView2 PTR)
   IF pWebView2 THEN
      m_pWebView2 = pWebView2
      pWebView2->AddNavigationCompleted(cast(ANY PTR, @this), @m_token)
   END IF
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
DESTRUCTOR CWebView2NavigationCompletedEventHandlerInternal
   IF m_pWebView2 THEN m_pWebView2->RemoveNavigationCompleted(m_token)
END DESTRUCTOR
' ========================================================================================
' ========================================================================================
FUNCTION CWebView2NavigationCompletedEventHandlerInternal.Invoke (BYVAL sender AS Afx_ICoreWebView2 PTR, BYVAL args AS Afx_ICoreWebView2NavigationCompletedEventArgs PTR) AS HRESULT
   DIM IsSuccess AS WINBOOL   
   IF args THEN args->get_IsSuccess(@IsSuccess)
   DIM WebErrorStatus AS COREWEBVIEW2_WEB_ERROR_STATUS
   IF args THEN args->get_WebErrorStatus(@WebErrorStatus)
   DIM NavigationId AS UINT64
   IF args THEN args->get_NavigationId(@NavigationId)
   RETURN S_OK
END FUNCTION
' ========================================================================================
```
---

### CWebView2CreateCoreWebView2EnvironmentCompletedHandler

Implementation of the **ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler** interface.

Used when the `WebView2` runtime finishes creating a **ICoreWebView2Environment** object. The creation is initiated by calling the **CreateCoreWebView2Environment** or **CreateCoreWebView2EnvironmentWithOptions**.

```
' ########################################################################################
' CWebView2CreateCoreWebView2EnvironmentCompletedHandler class
' Implementation of the ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler callback interface.
' ########################################################################################
TYPE CWebView2CreateCoreWebView2EnvironmentCompletedHandler EXTENDS OBJECT

   DECLARE VIRTUAL FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION AddRef () AS ULONG
   DECLARE VIRTUAL FUNCTION Release () AS ULONG
   DECLARE VIRTUAL FUNCTION Invoke (BYVAL errorCode AS HRESULT, BYVAL createdEnvironment AS Afx_ICoreWebView2Environment PTR) AS HRESULT

   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

   ' Reference count for COM
   refCount AS ULONG = 0

END TYPE
' ########################################################################################

' =====================================================================================
' Constructor
' =====================================================================================
PRIVATE CONSTRUCTOR CWebView2CreateCoreWebView2EnvironmentCompletedHandler
   CWV2_DP("")
END CONSTRUCTOR
' =====================================================================================
' =====================================================================================
' Destructor
' =====================================================================================
PRIVATE DESTRUCTOR CWebView2CreateCoreWebView2EnvironmentCompletedHandler
   CWV2_DP("")
END DESTRUCTOR
' =====================================================================================

' ========================================================================================
' Returns pointers to the implemented classes and supported interfaces.
' It is never called by WebView, so we simply return S_OK.
' ========================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandler.QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObj AS LPVOID PTR) AS HRESULT
   CWV2_DP("")
   RETURN S_OK
END FUNCTION
' =====================================================================================

' ========================================================================================
' Increments the reference count for an interface on an object. This method should be called
' for every new copy of a pointer to an interface on an object.
' ========================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandler.AddRef () AS ULONG
   refCount += 1
   CWV2_DP(WSTR(refCount))
   RETURN refCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Decrements the reference count for an interface on an object.
' If the count reaches 0, it deletes itself.
' ========================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandler.Release () AS ULONG
   refCount -= 1
   CWV2_DP(WSTR(refCount))
   IF refCount = 0 THEN
      CWV2_DP("Delete class")
      Delete @this
   END IF
   RETURN refCount
END FUNCTION
' =====================================================================================

' =====================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandler.Invoke (BYVAL errorCode AS HRESULT, BYVAL createdEnvironment AS Afx_ICoreWebView2Environment PTR) AS HRESULT
   CWV2_DP("")
   RETURN S_OK
END FUNCTION
' =====================================================================================
```

This is the code of the callback class used internally by `CWebView2`. It is included here for documentation purposes. You will never have to call it by yourself.

#### Remarks

The `CWebView2`class implements an intenal implementation of this class. It is called in your appliacation as follows:

```
' // Create an instance of WebView
DIM pWebView2 AS CWebView2 = CWebView2(hWin, pUserDataFolder)
```

```
' ========================================================================================
' Constructor
' Usage 1: DIM pWebView2 AS CWebView2 = hWin
' CreateCoreWebView2Environment, so it relies on the default runtime and default user data folder.
' Usage 2: DIM pWebView2 AS CWebView2 = CWebView2(hWin, pUserDataFolder)
' Calls CreateCoreWebView2EnvironmentWithOptions, pointing to any folder you choose.
' This gives you a separate profile: cookies, cache, storage isolated from the default.
' Slightly slower startup, but perfect for multi-tab or multi-user contexts.
' ========================================================================================
PRIVATE CONSTRUCTOR CWebView2 (BYVAL hWin AS HWND, BYVAL pUserDataFolder AS WSTRING PTR = NULL)
   CWV2_DP("hWin: " & WSTR(hWin) & " - this: " & WSTR(@this))
   ' // Initialize the COM library
   CoInitialize NULL
   ' // Store the window handle
   IF hWin = NULL THEN SetResult(E_POINTER): EXIT CONSTRUCTOR
   SetWindowLongPtrW(hWin, GWLP_USERDATA, cast(LONG_PTR, @this))
   m_hwnd = hWin
   ' // Create the environment
   DIM pEnv AS CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal PTR
   pEnv = NEW CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal(@this)
   DIM hr AS HRESULT
   IF pUserDataFolder = NULL THEN
      hr = CreateCoreWebView2Environment(cast(ANY PTR, pEnv))
   ELSE
      hr = CreateCoreWebView2EnvironmentWithOptions(NULL, pUserDataFolder, NULL, cast(ANY PTR, pEnv))
   END IF
   SetResult(hr)
   CWV2_DP("pEnv: " & WSTR(pEnv) & " - hr: " & HEX(hr))
END CONSTRUCTOR
' ========================================================================================
```

```
' ########################################################################################
' CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal class
' Implementation of the ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler callback interface.
' ########################################################################################
TYPE CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal EXTENDS OBJECT

   DECLARE VIRTUAL FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION AddRef () AS ULONG
   DECLARE VIRTUAL FUNCTION Release () AS ULONG
   DECLARE VIRTUAL FUNCTION Invoke (BYVAL errorCode AS HRESULT, BYVAL createdEnvironment AS Afx_ICoreWebView2Environment PTR) AS HRESULT

   DECLARE CONSTRUCTOR (BYVAL pWebView2 AS CWebView2 PTR)
   DECLARE DESTRUCTOR

   ' Reference count for COM
   refCount AS ULONG = 0
   m_pWebView2 AS CWebView2 PTR

END TYPE
' ########################################################################################

' ########################################################################################
' CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal class
' Implementation of the ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler callback interface.
' ########################################################################################

' =====================================================================================
' Constructor
' =====================================================================================
CONSTRUCTOR CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal (BYVAL pWebView2 AS CWebView2 PTR)
   CWV2_DP("pWebView2: " & WSTR(pWebView2)  & " - this: " & WSTR(@this))
   m_pWebView2 = pWebView2
END CONSTRUCTOR
' =====================================================================================
' =====================================================================================
' Destructor
' =====================================================================================
DESTRUCTOR CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal
   CWV2_DP(WSTR(@this))
END DESTRUCTOR
' =====================================================================================

' ========================================================================================
' Returns pointers to the implemented classes and supported interfaces.
' It is never called by WebView, so we simply return S_OK.
' ========================================================================================
FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal.QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObj AS LPVOID PTR) AS HRESULT
   CWV2_DP("")
   RETURN S_OK
END FUNCTION
' =====================================================================================

' ========================================================================================
' Increments the reference count for an interface on an object. This method should be called
' for every new copy of a pointer to an interface on an object.
' ========================================================================================
FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal.AddRef () AS ULONG
   refCount += 1
   CWV2_DP(WSTR(refCount))
   RETURN refCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Decrements the reference count for an interface on an object.
' If the count reaches 0, it deletes itself.
' ========================================================================================
FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal.Release () AS ULONG
   refCount -= 1
   CWV2_DP(WSTR(refCount))
   IF refCount = 0 THEN
      CWV2_DP("Delete class")
      Delete @this
   END IF
   RETURN refCount
END FUNCTION
' =====================================================================================

' =====================================================================================
FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal.Invoke (BYVAL errorCode AS HRESULT, BYVAL createdEnvironment AS Afx_ICoreWebView2Environment PTR) AS HRESULT
   CWV2_DP("")
   IF errorCode = S_OK AND m_pWebView2 <> NULL THEN
      m_pWebView2->m_pEnv = createdEnvironment
      m_pWebView2->m_pEnv->AddRef
      ' // Create controller
      DIM pController AS CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal PTR
      pController = NEW CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal(m_pWebView2)
      m_pWebView2->m_pEnv->CreateCoreWebView2Controller(m_pWebView2->m_hWnd, cast(ANY PTR, pController))
      ' // Get the runtime versión
      DIM wszVersion AS LPWSTR
      IF m_pWebView2->m_pEnv->get_BrowserVersionString(@wszVersion) = S_OK THEN
         m_pWebView2->m_BrowserVersion = *wszVersion
         CoTaskMemFree(wszVersion)
      END IF
   END IF
   RETURN S_OK
END FUNCTION
' =====================================================================================
```
---

### CWebView2CreateCoreWebView2ControllerCompletedHandler

Implementation of the **ICoreWebView2CreateCoreWebView2ControllerCompletedHandler** callback interface.

The controller is created during the processing of the **Invoke** method of the **CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal** class by calloing the **CreateCoreWebView2Controller** of the **ICoreWebView2Environment** interface. A pointer to the **ICoreWebView2Controller** interface is provided by `WebView`in the **Invoke** method of the **CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal** class.

```
FUNCTION CWebView2CreateCoreWebView2EnvironmentCompletedHandlerInternal.Invoke (BYVAL errorCode AS HRESULT, BYVAL createdEnvironment AS Afx_ICoreWebView2Environment PTR) AS HRESULT
   CWV2_DP("")
   IF errorCode = S_OK AND m_pWebView2 <> NULL THEN
      m_pWebView2->m_pEnv = createdEnvironment
      m_pWebView2->m_pEnv->AddRef
      ' // Create controller
      DIM pController AS CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal PTR
      pController = NEW CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal(m_pWebView2)
      m_pWebView2->m_pEnv->CreateCoreWebView2Controller(m_pWebView2->m_hWnd, cast(ANY PTR, pController))
      ' // Get the runtime versión
      DIM wszVersion AS LPWSTR
      IF m_pWebView2->m_pEnv->get_BrowserVersionString(@wszVersion) = S_OK THEN
         m_pWebView2->m_BrowserVersion = *wszVersion
         CoTaskMemFree(wszVersion)
      END IF
   END IF
   RETURN S_OK
END FUNCTION
```

#### Method

| Name       | Description |
| ---------- | ----------- |
| [Invoke](#invoke) | Provides the result of the corresponding asynchronous method. |

```
FUNCTION Invoke (BYVAL errorCode AS HRESULT, _
   BYVAL createdController AS Afx_ICoreWebView2Controller PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *errorCode* | [in] An HRESULT code to check for errors. |
| *createdController* | [in] A pointer to the **ICoreWebView2Controller** interface. |

#### Implementation

```

' ########################################################################################
' CWebView2CreateCoreWebView2ControllerCompletedHandler class
' Implementation of the ICoreWebView2CreateCoreWebView2ControllerCompletedHandler callback interface.
' ########################################################################################
TYPE CWebView2CreateCoreWebView2ControllerCompletedHandler EXTENDS OBJECT

   DECLARE VIRTUAL FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION AddRef () AS ULONG
   DECLARE VIRTUAL FUNCTION Release () AS ULONG
   DECLARE VIRTUAL FUNCTION Invoke (BYVAL errorCode AS HRESULT, BYVAL createdController AS Afx_ICoreWebView2Controller PTR) AS HRESULT

   DECLARE CONSTRUCTOR
   DECLARE DESTRUCTOR

   ' Reference count for COM
   refCount AS ULONG = 0

END TYPE
' ########################################################################################

' =====================================================================================
' Constructor
' =====================================================================================
PRIVATE CONSTRUCTOR CWebView2CreateCoreWebView2ControllerCompletedHandler
   CWV2_DP("")
END CONSTRUCTOR
' =====================================================================================
' =====================================================================================
' Destructor
' =====================================================================================
PRIVATE DESTRUCTOR CWebView2CreateCoreWebView2ControllerCompletedHandler
   CWV2_DP("")
END DESTRUCTOR
' =====================================================================================

' ========================================================================================
' Returns pointers to the implemented classes and supported interfaces.
' It is never called by WebView, so we simply return S_OK.
' ========================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandler.QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObj AS LPVOID PTR) AS HRESULT
   CWV2_DP("")
   RETURN S_OK
END FUNCTION
' =====================================================================================

' ========================================================================================
' Increments the reference count for an interface on an object. This method should be called
' for every new copy of a pointer to an interface on an object.
' ========================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandler.AddRef () AS ULONG
   refCount += 1
   CWV2_DP(WSTR(refCount))
   RETURN refCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Decrements the reference count for an interface on an object.
' If the count reaches 0, it deletes itself.
' ========================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandler.Release () AS ULONG
   refCount -= 1
   CWV2_DP(WSTR(refCount))
   IF refCount = 0 THEN
      CWV2_DP("Delete class")
      Delete @this
   END IF
   RETURN refCount
END FUNCTION
' =====================================================================================

' =====================================================================================
PRIVATE FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandler.Invoke (BYVAL errorCode AS HRESULT, BYVAL createdController AS Afx_ICoreWebView2Controller PTR) AS HRESULT
   CWV2_DP("")
   RETURN S_OK
END FUNCTION
' =====================================================================================
```

This is the code of the callback class used internally by `CWebView2`. It is included here for documentation purposes. You will never have to call it by yourself.

```

' ########################################################################################
' CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal class
' Implementation of the ICoreWebView2CreateCoreWebView2ControllerCompletedHandler callback interface.
' ########################################################################################

' =====================================================================================
' Constructor
' =====================================================================================
CONSTRUCTOR CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal (BYVAL pWebView2 AS CWebView2 PTR)
   CWV2_DP("pWebView2: " & WSTR(pWebView2)  & " - this: " & WSTR(@this))
   m_pWebView2 = pWebView2
END CONSTRUCTOR
' =====================================================================================
' =====================================================================================
' Destructor
' =====================================================================================
DESTRUCTOR CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal
   CWV2_DP(WSTR(@this))
END DESTRUCTOR
' =====================================================================================

' ========================================================================================
' Returns pointers to the implemented classes and supported interfaces.
' It is never called by WebView, so we simply return S_OK.
' ========================================================================================
FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal.QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObj AS LPVOID PTR) AS HRESULT
   CWV2_DP("")
   RETURN S_OK
END FUNCTION
' =====================================================================================

' ========================================================================================
' Increments the reference count for an interface on an object. This method should be called
' for every new copy of a pointer to an interface on an object.
' ========================================================================================
FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal.AddRef () AS ULONG
   refCount += 1
   CWV2_DP(WSTR(refCount))
   RETURN refCount
END FUNCTION
' ========================================================================================

' ========================================================================================
' Decrements the reference count for an interface on an object.
' If the count reaches 0, it deletes itself.
' ========================================================================================
FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal.Release () AS ULONG
   refCount -= 1
   CWV2_DP(WSTR(refCount))
   IF refCount = 0 THEN
      CWV2_DP("Delete class")
      Delete @this
   END IF
   RETURN refCount
END FUNCTION
' =====================================================================================

' =====================================================================================
FUNCTION CWebView2CreateCoreWebView2ControllerCompletedHandlerInternal.Invoke (BYVAL errorCode AS HRESULT, BYVAL createdController AS Afx_ICoreWebView2Controller PTR) AS HRESULT
   CWV2_DP(WSTR(errorCode))
   IF errorCode = S_OK AND m_pWebView2 <> NULL THEN
      m_pWebView2->m_pController = createdController
      m_pWebView2->m_pController->AddRef
      CWV2_DP("createdController: " & WSTR(createdController))
      ' // Get a pointer to the ICoreWebView2 inerface
      DIM pCoreWebView2 AS Afx_ICoreWebView2 PTR
      IF createdController->get_CoreWebView2(@pCoreWebView2) = S_OK THEN
         m_pWebView2->m_pCoreWebView2 = pCoreWebView2
         ' Don't call AddRef here; it is already AddRef'ed
         ' // Make the WebView2 control visible
         createdController->put_IsVisible(TRUE)
         ' // adjust the control to the client area of the window
         DIM rc AS RECT
         GetClientRect(m_pWebView2->m_hwnd, @rc)
         createdController->put_Bounds(rc)
      END IF
   END IF
   RETURN S_OK
END FUNCTION
' =====================================================================================
```
---

### GetControllerPtr

Returns a raw pointer to the **Afx_ICoreWebView2Controller** interface.

```
FUNCTION GetControllerPtr () AS Afx_ICoreWebView2Controller PTR
```
---

### GetEnvironmentPtr

Returns a raw pointer to the **Afx_ICoreWebView2Environment** interface.

```
FUNCTION GetEnvironmentPtr () AS Afx_ICoreWebView2Environment PTR
```
---

### GetWebViewPtr

Returns a raw pointer to the **Afx_ICoreWebView2** interface.

```
FUNCTION GetWebViewPtr () AS Afx_ICoreWebView2 PTR
```
---

### GetCoreWebView

Gets an AddRef'ed pointer of the **Afx_ICoreWebView2** interface

```
FUNCTION GetCoreWebView2 () AS Afx_ICoreWebView2 PTR
```
---

### IsReady

Checks if WebView2 is ready to be used.

```
FUNCTION IsReady (BYVAL dwMaxWaitMilliseconds AS LONG = -1) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwMaxWaitMilliseconds* | [in] Number of milliseconds to wait for the response, or -1 for an infinite wait. |

#### Return value

Returns TRUE or FALSE.

---

### AfxCWebView2Ptr

Returns a raw pointer to the **CWebView** class given the handle of the window that hosts it.

```
FUNCTION AfxCWebView2Ptr (BYVAL hWin AS HWND) AS CWebView2 PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | [in] Handle of the window that hosts the WebView control. |

#### Remarks

The returned pointer is a raw pointer. Therefore you don't have to release it.

---

### AfxSaveTempHtmlFile

Saves the contents of an html script to a temporary file and returns the name of the file. The file is saved with a .html extension and using UTF-8 encoding.

```
FUNCTION AfxSaveTempHtmlFile (BYVAL pwszBuffer AS WSTRING PTR) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszBuffer* | [in] A pointer to the string containing the hrml script to save. |

#### Remarks

Used to save and html script to be used with the **Navigate** method.

---

### GetLastResult

Returns the last result code.

```
FUNCTION GetLastResult () AS HRESULT
```
---

### SetResult

Sets the result code.
```
FUNCTION SetResult (BYVAL Result AS HRESULT) AS HRESULT
```
| Parameter | Description |
| --------- | ----------- |
| *Result* | The error code returned by the methods. |

---

### GetErrorInfo

Returns a description of the last result code.

```
FUNCTION GetErrorInfo () AS DWSTRING
```

#### Return value

DWSTRING. A description of the last result code.

---

### CallDevToolsProtocolMethod

Runs an asynchronous DevToolsProtocol method.

```
FUNCTION CallDevToolsProtocolMethod (BYVAL methodName AS LPCWSTR, _
   BYVAL parametersAsJson AS LPCWSTR, _
   BYVAL handler AS Afx_ICoreWebView2CallDevToolsProtocolMethodCompletedHandler PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *methodName* | [in] Full name of the method in the **{domain}.{method} format**. |
| *parametersAsJson* | [in] A JSON formatted string containing the parameters for the corresponding method. |
| *handler* | [in] A pointer to the implemented **Afx_ICoreWebView2CallDevToolsProtocolMethodCompletedHandler** callback interface. |

For more information about available methods, navigate to [DevTools Protocol Viewer](https://chromedevtools.github.io/devtools-protocol/tot/). The *methodName* parameter is the full name of the method in the **{domain}.{method}** format. The *arametersAsJson* parameter is a JSON formatted string containing the parameters for the corresponding method. The Invoke method of the handler is run when the method asynchronously completes. Invoke is run with the return object of the method as a JSON string. This function returns **E_INVALIDARG** if the *methodName* is unknown or the *parametersAsJson* has an error. In the case of such an error, the *returnObjectAsJson* parameter of the handler will include information about the error. Note even though WebView2 dispatches the CDP messages in the order called, CDP method calls may be processed out of order. If you require CDP methods to run in a particular order, you should wait for the previous method's completed handler to run before calling the next method. If the method is to run in **AddNewWindowRequested** handler it should be called before the new window is set if the cdp message should affect the initial navigation. If called after setting the **NewWindow** property, the cdp messages may or may not apply to the initial navigation and may only apply to the subsequent navigation. For more details see **ICoreWebView2NewWindowRequestedEventArgs.put_NewWindow**.

---

### CanGoBack

TRUE if the WebView is able to navigate to a previous page in the navigation history.

```
FUNCTION CanGoBack () AS BOOLEAN
```
---

### CanGoForward

TRUE if the WebView is able to navigate to a previous page in the navigation history.

```
FUNCTION CanGoForward () AS BOOLEAN
```
---

### CapturePreview

Capture an image of what WebView is displaying.
```
FUNCTION CapturePreview (BYVAL imageFormat AS COREWEBVIEW2_CAPTURE_PREVIEW_IMAGE_FORMAT, _
   BYVAL imageStream AS IStream PTR, _
   BYVAL handler AS Afx_ICoreWebView2CapturePreviewCompletedHandler PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *imageFormat* | [in] The format of the image: COREWEBVIEW2_CAPTURE_PREVIEW_IMAGE_FORMAT_PNG or COREWEBVIEW2_CAPTURE_PREVIEW_IMAGE_FORMAT_JPEG. |
| *imageStream* | [in] Pointer to an **IStream** interface. |
| *handler* | [in] Pointer to an **Afx_ICoreWebView2CapturePreviewCompletedHandler** callback interface. |

Specify the format of the image with the *imageFormat* parameter. The resulting image binary data is written to the provided *imageStream* parameter. When **CapturePreview** finishes writing to the stream, the **Invoke** method on the provided handler parameter is run. This method fails if called before the first **ContentLoading** event. For example if this is called in the **NavigationStarting** event for the first navigation it will fail. For subsequent navigations, the method may not fail, but will not capture an image of a given webpage until the **ContentLoading** event has been fired for it. Any call to this method prior to that will result in a capture of the page being navigated away from.

---

### Close

Closes the WebView and cleans up the underlying browser instance.

```
FUNCTION Close () AS HRESULT
```

Cleaning up the browser instance releases the resources powering the WebView. The browser instance is shut down if no other WebViews are using it.

After running **Close**, most methods will fail and event handlers stop running. Specifically, the WebView releases the associated references to any associated event handlers when **Close** is run.

**Close** is implicitly run when the **CoreWebView2Controller** loses the final reference and is destructed. But it is best practice to explicitly run **Close** to avoid any accidental cycle of references between the WebView and the app code. Specifically, if you capture a reference to the WebView in an event handler you create a reference cycle between the WebView and the event handler. Run **Close** to break the cycle by releasing all event handlers. But to avoid the situation, it is best to both explicitly run **Close** on the WebView and to not capture a reference to the WebView to ensure the WebView is cleaned up correctly. **Close** is synchronous and won't trigger the beforeunload event.

---

### ExecuteScript

Run JavaScript code from the javascript parameter in the current top-level document rendered in the WebView.

```
FUNCTION ExecuteScript (BYVAL javaScript AS LPCWSTR, _
   BYVAL handler AS Afx_ICoreWebView2ExecuteScriptCompletedHandler PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *javaScript* | [in] The Java script. |
| *handler* | [in] Pointer to an implemented **Afx_ICoreWebView2ExecuteScriptCompletedHandler** callback interface. |

The result of evaluating the provided JavaScript is used in this parameter. The result value is a JSON encoded string. If the result is undefined, contains a reference cycle, or otherwise is not able to be encoded into JSON, then the result is considered to be null, which is encoded in JSON as the string "null".

### GetBounds

Gets the WebView bounds.

```
FUNCTION GetBounds () AS RECT
```

Bounds are relative to the parent HWND. The app has two ways to position a WebView.

* Create a child HWND that is the WebView parent HWND. Position the window where the WebView should be. Use (0, 0) for the top-left corner (the offset) of the **Bounds** of the WebView.

* Use the top-most window of the app as the WebView parent HWND. For example, to position WebView correctly in the app, set the top-left corner of the **Bound** of the WebView.

The values of **Bounds** are limited by the coordinate space of the host.

---

### GetBrowserProcessId

Gets process ID of the browser process that hosts the WebView.

```
FUNCTION GetBrowserProcessId () AS UINT32
```
---

### GetContainsFullScreenElement

Indicates if the WebView contains a fullscreen HTML element.

```
FUNCTION GetContainsFullScreenElement () AS LONG
```
---

### GetIsVisible

TRUE if the WebView is visible; FALSE otherwise.

```
FUNCTION GetIsVisible () AS BOOLEAN
```
---

### GetParentWindow

Gets the handle of the parent window provided by the app that this WebView is using to render content.

```
FUNCTION GetParentWindow () AS HWND
```
---

### GetSource

Gets the URI of the current top level document.

```
FUNCTION GetSource () AS DWSTRING
```

This value potentially changes as a part of the **SourceChanged** event that runs for some cases such as navigating to a different site or fragment navigations. It remains the same for other types of navigations such as page refreshes or **history.pushState** with the same URL as the current page.

---

### GetZoomFactor

Gets the zoom factor for the WebView.

```
FUNCTION GetZoomFactor () AS DOUBLE
```

#### Note

Changing zoom factor may cause **window.innerWidth**, **window.innerHeight**, both, and page layout to change. A zoom factor that is applied by the host by running **ZoomFactor** becomes the new default zoom for the WebView. The zoom factor applies across navigations and is the zoom factor WebView is returned to when the user chooses Ctrl+0. When the zoom factor is changed by the user (resulting in the app receiving **ZoomFactorChanged**), that zoom applies only for the current page. Any user applied zoom is only for the current page and is reset on a navigation. Specifying a zoomFactor less than or equal to 0 is not allowed. WebView also has an internal supported zoom factor range. When a specified zoom factor is out of that range, it is normalized to be within the range, and a **ZoomFactorChanged** event is triggered for the real applied zoom factor. When the range normalization happens, the **ZoomFactor** property reports the zoom factor specified during the previous modification of the **ZoomFactor** property until the **ZoomFactorChanged** event is received after WebView applies the normalized zoom factor.

---

### GoBack

Navigates the WebView to the previous page in the navigation history.

```
FUNCTION GoBack () AS HRESULT
```
---

### GoForward

Navigates the WebView to the next page in the navigation history.

```
FUNCTION GoForward () AS HRESULT
```
---

### MoveFocus

Moves focus into WebView.

```
FUNCTION MoveFocus (BYVAL reason AS COREWEBVIEW2_MOVE_FOCUS_REASON) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *reason* | [in] One of the following constants: COREWEBVIEW2_MOVE_FOCUS_REASON_PROGRAMMATIC, COREWEBVIEW2_MOVE_FOCUS_REASON_NEXT or COREWEBVIEW2_MOVE_FOCUS_REASON_PREVIOUS. |

WebView gets focus and focus is set to correspondent element in the page hosted in the WebView. For **Programmatic** reason, focus is set to previously focused element or the default element if no previously focused element exists. For **Next** reason, focus is set to the first element. For **Previous** reason, focus is set to the last element. WebView changes focus through user interaction including selecting into a WebView or Tab into it. For tabbing, the app runs **MoveFocus** with **Next** or **Previous** to align with Tab and Shift+Tab respectively when it decides the WebView is the next element that may exist in a tab. Or, the app runs **IsDialogMessage** as part of the associated message loop to allow the platform to auto handle tabbing. The platform rotates through all windows with **WS_TABSTOP**. When the WebView gets focus from **IsDialogMessage**, it is internally put the focus on the first or last element for tab and Shift+Tab respectively.

---

### Navigate

Cause a navigation of the top-level document to run to the specified URI.

```
FUNCTION Navigate (BYVAL uri AS LPCWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *uri* | [in] The URI where to navigate. |

---

### NavigateToString

Initiates a navigation to htmlContent as source HTML of a new document.

```
FUNCTION NavigateToString (BYVAL htmlContent AS LPCWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *htmlContent* | [in] The HTML content. |

#### Remarks

The *htmlContent* parameter may not be larger than 2 MB (2 * 1024 * 1024 bytes) in total size. The origin of the new page is **about:blank**.

---

### NotifyParentWindowPositionChangd

This is a notification separate from **SetBounds** that tells WebView its parent (or any ancestor) HWND moved.

```
FUNCTION NotifyParentWindowPositionChanged () AS HRESULT
```

#### Remarks

This is needed for accessibility and certain dialogs in WebView to work correctly.

---

### OpenDevToolsWindow

Opens the DevTools window for the current document in the WebView.

```
FUNCTION OpenDevToolsWindow () AS HRESULT
```

#### Remarks

Does nothing if run when the DevTools window is already open.

---

# ## PostWebMessageAsJson

Post the specified webMessage to the top level document in this WebView.

```
FUNCTION PostWebMessageAsJson (BYVAL webMessageAsJson AS LPCWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *webMessageAsJson* | [in] The message in JSON format. |

---

### PostWebMessageAsString

Posts a message that is a simple string rather than a JSON string representation of a JavaScript object.

```
FUNCTION PostWebMessageAsString (BYVAL webMessageAsString AS LPCWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *webMessageAsString* | [in] The message as a string. |

---

### Reload

Reload the current page.

```
FUNCTION Reload () AS HRESULT
```

This is similar to navigating to the URI of current top level document including all navigation events firing and respecting any entries in the HTTP cache. But, the back or forward history are not modified.

---

### SetBounds

Sets the **Bounds** propety.

```
FUNCTION SetBounds (BYVAL bounds AS RECT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *bounds* | [in] A **RECT** structure with the bound values. |

---

### SetIsVisible

Set the **IsVisible** property.

```
FUNCTION SetIsVisible (BYVAL IsVisible AS BOOLEAN) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *IsVisible* | [in] TRUE or FALSE. |

---

### SetParentWindow

Set the parent window for the WebView.

```
FUNCTION SetParentWindow (BYVAL parentWindow AS HWND) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *parentWindow* | [in] The handle of the parent window. |

#### Remarks

This will cause the WebView to reparent its window to the newly provided window.

---

### SetZoomFactor

Set the **ZoomFactor** property.

```
FUNCTION SetZoomFactor (BYVAL zoomFactor AS DOUBLE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *zoomFactor* | [in] The zoom factor value. |

---

### Stop

Stop all navigations and pending resource fetches. Does not stop scripts.

```
FUNCTION Stop () AS HRESULT
```
---

### CompareBrowserVersions

Compares two instances of browser versions correctly and returns an integer that indicates whether the first instance is older, the same as, or newer than the second instance.
  
```
FUNCTION CompareBrowserVersions (BYVAL version1 AS PCWSTR, BYVAL version2 AS PCWSTR, _
   BYVAL result AS INT_ PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *version1* | [in] One of the version strings to compare. |
| *version2* | [in] The other version string to compare. |
| *result* | [out] Pointer to an INT variable that receives the result. |

| Value type | Condition |
| ---------- | --------- |
| Less than zero | *version1* is older than *version2*. |
| Zero | *version1* is the same than *version2*. |
| Greater than zero | *version1* is newer than *version2*. |

It can be used to determine whether to use webview2 or certain feature base on version. Sets the value of result to -1, 0 or 1 if version1 is less than, equal or greater than version2 respectively. Returns **E_INVALIDARG** if it fails to parse any of the version strings or any input parameter is null. Input can directly use the versionInfo obtained from **GetAvailableCoreWebView2BrowserVersionString**, channel info will be ignored.

---

### CreateCoreWebView2Environment

Creates an evergreen WebView2 Environment using the installed Edge version. This is equivalent to calling CreateCoreWebView2EnvironmentWithOptions with nullptr for browserExecutableFolder, userDataFolder, additionalBrowserArguments.

```
FUNCTION CreateCoreWebView2Environment (BYVAL environment_created_handler AS _
   Afx_ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *environment_created_handler* | [in] Pointer to an implemented Afx_ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler callback interface. |

---

### CreateCoreWebView2EnvironmentWithOptions

Creates a  WebView2 environment with a custom version of Edge, user data directory and/or additional options.

```
FUNCTION CreateCoreWebView2EnvironmentWithOptions (BYVAL browserExecutableFolder AS PCWSTR, _
   BYVAL userDataFolder AS PCWSTR, BYVAL environmentOptions AS Afx_ICoreWebView2EnvironmentOptions PTR, _
   BYVAL environment_created_handler AS Afx_ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *browserExecutableFolder* | [in] Relative path to the folder that contains the embedded Edge. |
| *userDataFolder* | [in] Specifies the default user data folder location for WebView2. |
| *environmentOptions* | [in] Pointer to an Afx_ICoreWebView2EnvironmentOptions interface. |
| *environment_created_handler* | [in] Pointer to an implemented Afx_ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler callback interface. |

*browserExecutableFolder* is the relative path to the folder that contains the embedded Edge. The embedded Edge can be obtained by copying the version named folder of an installed Edge, like 73.0.52.0 sub folder of an installed 73.0.52.0 Edge. The folder should have msedge.exe, msedge.dll, and so on. Use null or empty string for *browserExecutableFolder* to create WebView using Edge installed on the machine, in which case the API will try to find a compatible version of Edge installed on the machine according to the channel preference trying to find first per user install and then per machine install.

The default channel search order is stable, beta, dev, and canary. When there is an override WEBVIEW2_RELEASE_CHANNEL_PREFERENCE environment variable or applicable releaseChannelPreference registry value with the value of 1, the channel search order is reversed.

userDataFolder can be specified to change the default user data folder location for WebView2. The path can be an absolute file path or a relative file path that is interpreted as relative to the current process's executable. Otherwise, for UWP apps, the default user data folder will be the app data folder for the package; for non-UWP apps, the default user data folder {Executable File Name}.WebView2 will be created in the same directory next to the app executable. WebView2 creation can fail if the executable is running in a directory that the process doesn't have permission to create a new folder in. The app is responsible to clean up its user data folder when it is done.

Note that as a browser process might be shared among WebViews, WebView creation will fail with HRESULT_FROM_WIN32(ERROR_INVALID_STATE) if the specified options does not match the options of the WebViews that are currently running in the shared browser process.

environment_created_handler is the handler result to the async operation which will contain the WebView2Environment that got created.

The browserExecutableFolder, userDataFolder and additionalBrowserArguments of the environmentOptions may be overridden by values either specified in environment variables or in the registry.

When creating a WebView2Environment the following environment variables are checked:

WEBVIEW2_BROWSER_EXECUTABLE_FOLDER
WEBVIEW2_USER_DATA_FOLDER
WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS
WEBVIEW2_RELEASE_CHANNEL_PREFERENCE

If an override environment variable is found then we use the browserExecutableFolder, userDataFolder and additionalBrowserArguments values as replacements for the corresponding values in CreateCoreWebView2EnvironmentWithOptions parameters.

While not strictly overrides, there exists additional environment variables that can be set:

WEBVIEW2_WAIT_FOR_SCRIPT_DEBUGGER

When found with a non-empty value, this indicates that the WebView is being launched under a script debugger. In this case, the WebView will issue a Page.waitForDebugger CDP command that will cause script execution inside the WebView to pause on launch, until a debugger issues a corresponding Runtime.runIfWaitingForDebugger CDP command to resume execution. Note: There is no registry key equivalent of this environment variable.

WEBVIEW2_PIPE_FOR_SCRIPT_DEBUGGER

When found with a non-empty value, this indicates that the WebView is being launched under a script debugger that also supports host applications that use multiple WebViews. The value is used as the identifier for a named pipe that will be opened and written to when a new WebView is created by the host application. The payload will match that of the remote-debugging-port JSON target and can be used by the external debugger to attach to a specific WebView instance. The format of the pipe created by the debugger should be: \\.\pipe\WebView2\Debugger\{app_name}\{pipe_name} where:

* {app_name} is the host application exe filename, e.g. WebView2Example.exe

* {pipe_name} is the value set for WEBVIEW2_PIPE_FOR_SCRIPT_DEBUGGER.

To enable debugging of the targets identified by the JSON you will also need to set the WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS environment variable to send --remote-debugging-port={port_num} where:

* {port_num} is the port on which the CDP server will bind.

Be aware that setting both the WEBVIEW2_PIPE_FOR_SCRIPT_DEBUGGER and WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS environment variables will cause the WebViews hosted in your application and their contents to be exposed to 3rd party applications such as debuggers.

Note: There is no registry key equivalent of this environment variable.

If none of those environment variables exist, then the registry is examined next. The following registry keys are checked:

[{Root}\Software\Policies\Microsoft\EmbeddedBrowserWebView\LoaderOverride\{AppId}]
"releaseChannelPreference"=dword:00000000
"browserExecutableFolder"=""
"userDataFolder"=""
"additionalBrowserArguments"=""

In the unlikely scenario where some instances of WebView are open during a browser update we could end up blocking the deletion of old Edge browsers. To avoid running out of disk space a new WebView creation will fail with the next error if it detects that there are many old versions present.

ERROR_DISK_FULL

The default maximum number of Edge versions allowed is 20.

The maximum number of old Edge versions allowed can be overwritten with the value of the following environment variable.

COREWEBVIEW2_MAX_INSTANCES

If the Webview depends on an installed Edge and it is uninstalled any subsequent creation will fail with the next error

ERROR_PRODUCT_UNINSTALLED

First we check with Root as HKLM and then HKCU. AppId is first set to the Application User Model ID of the caller's process, then if there's no corresponding registry key the AppId is set to the executable name of the caller's process, or if that isn't a registry key then '*'. If an override registry key is found then we use the browserExecutableFolder, userDataFolder and additionalBrowserArguments registry values as replacements for the corresponding values in CreateCoreWebView2EnvironmentWithOptions parameters.

---

### GetAvailableCoreWebView2BrowserVersionString

Get the browser version info including channel name if it is not the stable channel or the Embedded Edge.

```
FUNCTION GetAvailableCoreWebView2BrowserVersionString (BYVAL browserExecutableFolder AS PCWSTR, _
   BYVAL versionInfo AS LPWSTR PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *browserExecutableFolder* | [in] Relative path to the folder that contains the embedded Edge. |
| *versionInfo* | [out] Pointer to an unicode string that will receive version information. |

#### Remarks

Channel names are beta, dev, and canary. If an override exists for the *browserExecutableFolder* or the channel preference, the override will be used. If there isn't an override, then the parameter passed to **GetAvailableCoreWebView2BrowserVersionString** is used.

---

### GetAvailableCoreWebView2BrowserVersionString

Get the browser version info including channel name if it is not the stable channel or the Embedded Edge.

```
FUNCTION GetAvailableCoreWebView2BrowserVersionString (BYVAL browserExecutableFolder AS PCWSTR, _
   BYVAL versionInfo AS LPWSTR PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *browserExecutableFolder* | [in] Relative path to the folder that contains the embedded Edge. |
| *versionInfo* | [out] Pointer to an unicode string that will receive version information. |

---

### GetSettings

Gets a pointer to the **Afx_ICoreWebView2Settings** interface, that allows to modify various modifiable settings for the running WebView.

```
FUNCTION GetSettings () AS Afx_ICoreWebView2Settings PTR
```
---

### AreDefaultContextMenusEnabled

Determines whether the default context menus are shown to the user in WebView.

```
PROPERTY AreDefaultContextMenusEnabled () AS BOOLEAN
PROPERTY AreDefaultContextMenusEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```
---

### AreDefaultScriptDialogsEnabled

Used when loading a new HTML document.

```
PROPERTY AreDefaultScriptDialogsEnabled () AS BOOLEAN
PROPERTY AreDefaultScriptDialogsEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```

#### Remarks

If set to FALSE, WebView2 does not render the default JavaScript dialog box (specifically those displayed by the JavaScript alert, confirm, prompt functions and beforeunload event). Instead, if an event handler is set using **AddScriptDialogOpening**, WebView sends an event that contains all of the information for the dialog and allow the host app to show a custom UI. The default value is TRUE.

---

### AreDevToolsEnabled

Determines whether the user is able to use the context menu or keyboard shortcuts to open the DevTools window.

```
PROPERTY AreDevToolsEnabled () AS BOOLEAN
PROPERTY AreDevToolsEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```
---

### AreHostObjectsAllowed

Determines whether host objects are accessible from the page in WebView.

```
PROPERTY AreHostObjectsAllowed () AS BOOLEAN
PROPERTY AreHostObjectsAllowed (BYVAL enabled AS BOOLEAN) AS HRESULT
```
---

### IsBuiltInErrorPageEnabled

Determines whether to disable built in error page for navigation failure and render process failure.

```
PROPERTY IsBuiltInErrorPageEnabled () AS BOOLEAN
PROPERTY IsBuiltInErrorPageEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```
---

### IsScriptEnabled

Controls if running JavaScript is enabled in all future navigations in the WebView. This only affects scripts in the document. Scripts injected with ExecuteScript runs even if script is disabled. The default value is TRUE.

```
PROPERTY IsScriptEnabled () AS BOOLEAN
PROPERTY IsScriptEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```

#### Remarks

Changes to settings will apply at the next navigation, which includes the navigation after a **NavigationStarting** event.  We can use this to change settings according to what site we're visiting.

---

### IsStatusBarEnabled

Controls whether the status bar is displayed.

```
PROPERTY IsStatusBarEnabled () AS BOOLEAN
PROPERTY IsStatusBarEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```

#### Remarks

The status bar is usually displayed in the lower left of the WebView and shows things such as the URI of a link when the user hovers over it and other information. The default value is TRUE. The status bar UI can be altered by web content and should not be considered secure.

---

### IsWebMessageEnabled

Used when loading a new HTML document.

```
PROPERTY IsWebMessageEnabled () AS BOOLEAN
PROPERTY IsWebMessageEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```

#### Remarks

 If set to TRUE, communication from the host to the top-level HTML document of the WebView is allowed using **PostWebMessageAsJson**, **PostWebMessageAsString**, and message event of **window.chrome.webview**. For more information, see **PostWebMessageAsJson**. Communication from the top-level HTML document of the WebView to the host is allowed using the **postMessage** function of **window.chrome.webview** and **AddWebMessageReceived** method. For more information, see **AddWebMessageReceived**. If set to false, then communication is disallowed. **PostWebMessageAsJson** and **PostWebMessageAsString** fails with **E_ACCESSDENIED** and **window.chrome.webview.postMessage** fails by throwing an instance of an **Error** object. The default value is TRUE.

---

### IsZoomControlEnabled

Determines whether the user is able to impact the zoom of the WebView.

```
PROPERTY IsZoomControlEnabled () AS BOOLEAN
PROPERTY IsZoomControlEnabled (BYVAL enabled AS BOOLEAN) AS HRESULT
```

#### Remarks

When disabled, the user is not able to zoom using Ctrl++, Ctrl+-, or Ctrl+mouse wheel, but the zoom is set using **ZoomFactor** API. The default value is TRUE.

---

### AcceleratorKeyPressed

Adds/removes an event handler for the **AcceleratorKeyPressed** event.

```
FUNCTION AddAcceleratorKeyPressed ( _
   BYVAL eventHandler AS Afx_ICoreWebView2NavigationStartingEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveAcceleratorKeyPressed (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2NavigationStartingEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### ContainsFullScreenElementChanged

Adds/removes an event handler for the **ContainsFullScreenElementChanged** event.

```
FUNCTION AddContainsFullScreenElementChanged ( _
   BYVAL eventHandler AS Afx_ICoreWebView2ContainsFullScreenElementChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveContainsFullScreenElementChanged (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2ContainsFullScreenElementChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### ContentLoading

Adds/removes an event handler for the **ContentLoading** event.

```
FUNCTION AddContentLoading ( _
   BYVAL eventHandler AS Afx_ICoreWebView2ContentLoadingEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveContentLoading (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2ContentLoadingEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### DocumentTitleChanged

Adds/removes an event handler for the **DocumentTitleChanged** event.

```
FUNCTION AddDocumentTitleChanged ( _
   BYVAL eventHandler AS Afx_ICoreWebView2DocumentTitleChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveDocumentTitleChanged (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2DocumentTitleChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### FrameNavigationStarting

Adds/removes an event handler for the **FrameNavigationStarting** event.

```
FUNCTION AddFrameNavigationStarting ( _
   BYVAL eventHandler AS Afx_ICoreWebView2NavigationStartingEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveFrameNavigationStarting (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2NavigationStartingEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### GotFocus

Adds/removes an event handler for the **GotFocus** event.

```
FUNCTION AddGotFocus ( _
   BYVAL eventHandler AS Afx_ICoreWebView2FocusChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveGotFocus (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2FocusChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### LostFocus

Adds/removes an event handler for the **LostFocus** event.

```
FUNCTION AddLostFocus ( _
   BYVAL eventHandler AS Afx_ICoreWebView2FocusChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveLostFocus (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2FocusChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### HistoryChanged

Adds/removes an event handler for the **HistoryChanged** event.

```
FUNCTION AddHistoryChanged ( _
   BYVAL eventHandler AS Afx_ICoreWebView2SourceChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveHistoryChanged (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2SourceChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### MoveFocusRequested

Adds/removes an event handler for the **MoveFocusRequested** event.

```
FUNCTION AddMoveFocusRequested ( _
   BYVAL eventHandler AS Afx_ICoreWebView2MoveFocusRequestedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveMoveFocusRequested (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2MoveFocusRequestedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### NavigationCompleted

Adds/removes an event handler for the **NavigationCompleted** event.

```
FUNCTION AddNavigationCompleted ( _
   BYVAL eventHandler AS Afx_ICoreWebView2NavigationCompletedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveNavigationCompleted (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2MoveFocusRequestedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### NavigationStarting

Adds/removes an event handler for the **NavigationStarting** event.

```
FUNCTION AddNavigationStarting ( _
   BYVAL eventHandler AS Afx_ICoreWebView2NavigationStartingEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveNavigationStarting (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2NavigationStartingEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### NewWindowRequested

Adds/removes an event handler for the **NewWindowRequested** event.

```
FUNCTION AddNavigationStarting ( _
   BYVAL eventHandler AS Afx_ICoreWebView2NewWindowRequestedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveNewWindowRequested (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2NewWindowRequestedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### PermissionRequested

Adds/removes an event handler for the **PermissionRequested** event.

```
FUNCTION AddPermissionRequested ( _
   BYVAL eventHandler AS Afx_ICoreWebView2PermissionRequestedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemovePermissionRequested (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2PermissionRequestedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### ProcessFailed

Adds/removes an event handler for the **ProcessFailed** event.

```
FUNCTION AddProcessFailed ( _
   BYVAL eventHandler AS Afx_ICoreWebView2ProcessFailedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveProcessFailed (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2ProcessFailedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### ScriptDialogOpening

Adds/removes an event handler for the **ScriptDialogOpening** event.

```
FUNCTION AddScriptDialogOpening ( _
   BYVAL eventHandler AS Afx_ICoreWebView2ScriptDialogOpeningEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveProcessFailed (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2ScriptDialogOpeningEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### ScriptDialogOpening

Adds/removes an event handler for the **ScriptDialogOpening** event.

```
FUNCTION AddScriptDialogOpening ( _
   BYVAL eventHandler AS Afx_ICoreWebView2ScriptDialogOpeningEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveProcessFailed (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2ScriptDialogOpeningEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### SourceChanged

Adds/removes an event handler for the **SourceChanged** event.

```
FUNCTION AddSourceChanged ( _
   BYVAL eventHandler AS Afx_ICoreWebView2SourceChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveSourceChanged (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2SourceChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### WebMessageReceived

Adds/removes an event handler for the **WebMessageReceived** event.

```
FUNCTION AddWebMessageReceived ( _
   BYVAL eventHandler AS Afx_ICoreWebView2WebMessageReceivedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveWebMessageReceived (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2WebMessageReceivedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### WebResourceRequested

Adds/removes an event handler for the **WebResourceRequested** event.

```
FUNCTION AddWebResourceRequested ( _
   BYVAL eventHandler AS Afx_ICoreWebView2WebResourceRequestedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveWebResourceRequested (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2WebResourceRequestedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### WindowCloseRequested

Adds/removes an event handler for the **WindowCloseRequested** event.

```
FUNCTION AddWindowCloseRequested ( _
   BYVAL eventHandler AS Afx_ICoreWebView2WindowCloseRequestedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveWindowCloseRequested (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2WindowCloseRequestedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### ZoomFactorChanged

Adds/removes an event handler for the **ZoomFactorChanged** event.

```
FUNCTION AddZoomFactorChanged ( _
   BYVAL eventHandler AS Afx_ICoreWebView2ZoomFactorChangedEventHandler PTR, _
   BYVAL token AS EventRegistrationToken PTR) AS HRESULT
FUNCTION RemoveZoomFactorChanged (BYVAL token AS EventRegistrationToken) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventHandler* | Pointer to an ICoreWebView2ZoomFactorChangedEventHandler. |
| *token* | Token that uniquely identifies the subscription. |

---

### HostObjectToScript

Adds/removes the provided host object to script running in the WebView with the specified name.

```
FUNCTION AddHostObjectToScript (BYVAL _name AS LPCWSTR, BYVAL _object AS VARIANT PTR) AS HRESULT
FUNCTION RemoveHostObjectFromScript (BYVAL _name AS LPCWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *_name* | The name of the host object. |
| *_object* | The host object to be added to script. |

#### Remarks

Host objects are exposed as host object proxies using window.chrome.webview.hostObjects.{name}. Host object proxies are promises and resolves to an object representing the host object. The promise is rejected if the app has not added an object with the name. When JavaScript code access a property or method of the object, a promise is return, which resolves to the value returned from the host for the property or method, or rejected in case of error, for example, no property or method on the object or parameters are not valid.

**Note**: While simple types, IDispatch and array are supported, and IUnknown objects that also implement IDispatch are treated as IDispatch, generic IUnknown, VT_DECIMAL, or VT_RECORD variant is not supported. Remote JavaScript objects like callback functions are represented as an VT_DISPATCH``VARIANT with the object implementing IDispatch. The JavaScript callback method may be invoked using DISPID_VALUE for the DISPID. Such callback method invocations will return immediately and will not wait for the JavaScript function to run and so will not provide the return value of the JavaScript function. Nested arrays are supported up to a depth of 3. Arrays of by reference types are not supported. VT_EMPTY and VT_NULL are mapped into JavaScript as null. In JavaScript, null and undefined are mapped to VT_EMPTY.

---

### ScriptToExecuteOnDocumentCreated

Adds/removes the provided JavaScript to a list of scripts that should be run after the global object has been created, but before the HTML document has been parsed and before any other script included by the HTML document is run.

```
FUNCTION AddScriptToExecuteOnDocumentCreated (BYVAL javaScript AS LPCWSTR, _
   BYVAL handler AS Afx_ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler PTR) AS HRESULT
FUNCTION RemoveScriptToExecuteOnDocumentCreated (BYVAL id AS LPCWSTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *javaScript* | A javascript script. |
| *handler* | Pointer to an ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler. |

#### Remarks

This method injects a script that runs on all top-level document and child frame page navigations. This method runs asynchronously, and you must wait for the completion handler to finish before the injected script is ready to run. When this method completes, the Invoke method of the handler is run with the id of the injected script. id is a string. To remove the injected script, use ^^RemoveScriptToExecuteOnDocumentCreated**.

If the method is run in **AddNewWindowRequested** handler it should be called before the new window is set. If called after setting the **NewWindow** property, the initial script may or may not apply to the initial navigation and may only apply to the subsequent navigation.

**Note**: If an HTML document is running in a sandbox of some kind using sandbox properties or the Content-Security-Policy HTTP header affects the script that runs. For example, if the allow-modals keyword is not set then requests to run the alert function are ignored.

---

### WebResourceRequestedFilter

**Warning**: This method is deprecated and does not behave as expected for iframes.

It will cause the **WebResourceRequested** event to fire only for the main frame and its same-origin iframes. Please use **AddWebResourceRequestedFilterWithRequestSourceKinds** instead, which will let the event to fire for all iframes on the document.

Adds a URI and resource context filter for the **WebResourceRequested** event. A web resource request with a resource context that matches this filter's resource context and a URI that matches this filter's URI wildcard string will be raised via the **WebResourceRequested** event.

```
FUNCTION AddWebResourceRequestedFilter (BYVAL uri AS LPCWSTR, BYVAL _
   ResourceContext AS COREWEBVIEW2_WEB_RESOURCE_CONTEXT) AS HRESULT
FUNCTION RemoveWebResourceRequestedFilter (BYVAL uri AS LPCWSTR, _
   BYVAL ResourceContext AS COREWEBVIEW2_WEB_RESOURCE_CONTEXT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *uri* | The URI to add. |
| *ResourceContext* | The resource context filter. |

#### Remarks


The uri parameter value is a wildcard string matched against the URI of the web resource request. This is a glob style wildcard string in which a * matches zero or more characters and a ? matches exactly one character. These wildcard characters can be escaped using a backslash just before the wildcard character in order to represent the literal * or ?.

The matching occurs over the URI as a whole string and not limiting wildcard matches to particular parts of the URI. The wildcard filter is compared to the URI after the URI has been normalized, any URI fragment has been removed, and non-ASCII hostnames have been converted to punycode.

Specifying a NULL for the uri is equivalent to an empty string which matches no URIs.

---

### GetDevToolsProtocolEventReceiver

Get a DevTools Protocol event receiver that allows you to subscribe to a DevTools Protocol event.

```
FUNCTION GetDevToolsProtocolEventReceiver (BYVAL eventName AS LPCWSTR, _
   BYVAL receiver AS Afx_ICoreWebView2DevToolsProtocolEventReceiver PTR PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *eventName* | The full name of the event. |
| *receiver* | A pointer that receives a pointer to ICoreWebView2DevToolsProtocolEventReceiver. |

The eventName parameter is the full name of the event in the format {domain}.{event}. For more information about DevTools Protocol events description and event args, navigate to [DevTools Protocol Viewer](https://chromedevtools.github.io/devtools-protocol/tot/).

---

