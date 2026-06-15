# CWindow Class

`CWindow` is a powerful class to easily create Graphical User Interfaces (GUI) for Windows applications.

#### Main features

* Easy creation of Graphical User Interfaces (GUI).
* 100% compatible with the Windows API.
* Optional default values for window styles and extended styles.
* High DPI and Unicode support for windows and controls.
* Support for alpha blended icons and images.

#### Remarks

The default message pump (**CWindow.DoEvents**), should be enough for most applications, but you can replace it with your own.

**Include file**: AfxNova/CWindow.inc.

### Constructor

Registers the class name and initializes the common controls library.

```
CONSTRUCTOR CWindow (BYREF wszClassName AS CONST WSTRING = "")
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszClassName* | Optional. The name of the class name to register. If omitted, the class will use "FBWindowClass:" and a number as the class name. |

#### Usage examples

```
DIM pWindow AS CWindow
```
```
DIM pWindow AS CWindow = "MyClassName"
```

### Tutorial

| Topic      |
| ---------- |
| [Creating the main window](#topic1) |
| [Getting a pointer to the CWindow class](#topic2) |
| [Adding controls](#topic3) |
| [Popup windows](#topic4) |
| [Using PNG icons in toolbars](#topic5) |
| [Visual style menus](#topic6) |
| [Keyboard accelerators](#topic7) |

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [AccelHandle](#accelhandle) | Gets/sets the accelerator table handle. |
| [AddAccelerator](#addaccelerator) | Adds an accelerator key to the table. |
| [AddControl](#addcontrol) | Adds a control to the window. |
| [AnchorControl](#anchorcontrol) | Anchors a window or control to its parent window. |
| [BigIcon](#bigicon) | Associates a new large icon with the main window. |
| [Brush](#brush) | Gets/sets the background brush. |
| [Center](#center) | Centers a window on the screen or over another window. |
| [ClassStyle](#classstyle) | Gets/sets the style of the class. |
| [ClientHeight](#clientheight) | Returns the unscaled client height of the main window. |
| [ClientWidth](#clientwidth) | Returns the unscaled client width of the window. |
| [ControlAddExStyle](#controladdexstyle) | Adds a new extended style to the specified control..|
| [ControlAddStyle](#controladdstyle) | Adds a new style to the specified control.|
| [ControlClientHeight](#controlclientheight) | Returns the unscaled client height of the specified window. |
| [ControlClientWidth](#controlclientwidth) | Returns the unscaled client width of the specified window. |
| [ControlGetExStyle](#controlgetexstyle) | Retrieves the extended window styles of the specified control. |
| [ControlGetStyle](#controlgetstyle) | Retrieves the window styles of the specified control. |
| [ControlGetUser](#controlgetuser) | Gets the control's user data. |
| [ControlHandle](#controlhandle) | Retrieves a handle to the child control specified by its identifier. |
| [ControlHeight](#controlheight) | Returns the unscaled height of the specified window. |
| [ControlRemoveExStyle](#controlremoveexstyle) | Removes an extended style from the specified control. |
| [ControlRemoveStyle](#controlremovestyle) | Removes an style from the specified control. |
| [ControlSetExStyle](#controlsetexstyle) | Sets the window extended styles of the specified control. |
| [ControlSetStyle](#controlsetstyle) | Sets the window styles of the specified control. |
| [ControlSetUser](#controlsetuser) | Sets the control's user data. |
| [ControlWidth](#controlwidth) | Returns the unscaled width of the specified window. |
| [Create](#create) | Creates a new window. |
| [CreateAcceleratorTable](#createacceleratortable) | Creates the accelerator table. |
| [CreateFont](#createfont) | Creates a DPI aware logical font. |
| [DefaultFontSize](#defaultfontsize) | Gets/sets the point size of the default font. |
| [DestroyAcceleratorTable](#destroyacceleratortable) | Destroys the accelerator table. |
| [DoEvents](#doevents) | Processes windows messages. |
| [DPI](#dpi) | Gets/sets the DPI (dots per inch) to be used by the application. |
| [Font](#font) | Gets/sets the font used as default. |
| [GetBackColor](#getbackcolor) | Gets the background color of a control. |
| [GetClientRect](#getclientrect) | Retrieves the unscaled coordinates of the main window client area. |
| [GetControlClientRect](#getcontrolclientrect) | Retrieves the unscaled coordinates of a window's client area. |
| [GetControlWindowRect](#getcontrolwindowrect) | Retrieves the unscaled dimensions of the bounding rectangle of the specified window. |
| [GetForeColor](#getforecolor) | Gets the foreground color of `CWindow`or control. |
| [GetWindowRect](#getwindowrect) | Retrieves the unscaled dimensions of the bounding rectangle of the main window. |
| [GetWorkArea](#getworkarea) | Retrieves the unscaled size of the work area on the primary display monitor. |
| [Height](#height) | Returns the unscaled height of the main window. |
| [hWindow](#hwindow) | Gets/sets the main window handle. |
| [InstanceHandle](#instancehandle) | Gets/sets the instance handle. |
| [IsNonStable](#isnonstable) | Returns true if the `CWindow` is stabilized; otherwise, false. |
| [IsStabilized](#isstabilized) | Returns true if the `CWindow` is stabilized; otherwise, false. |
| [IsWindowScrollable](#iswindowscrollable) | Returns true if the `CWindow` is scrollable; otherwise, false. |
| [MoveWindow](#movewindow) | Changes the position and dimensions of the specified window. |
| [NonStable](#nonstable) | Makes a `CWindow` non stable (closeable). |
| [Resize](#resize) | Resizes the window sending a WM_SIZE message with the  SIZE_RESTORED value. |
| [rxRatio](#rxratio) | Returns the horizontal scaling ratio. |
| [ryRatio](#ryratio) | Returns the vertical scaling ratio. |
| [ScaleX](#scalex) | Scales an horizontal coordinate according the DPI setting. |
| [ScaleY](#scaley) | Scales a vertical coordinate according the DPI setting. |
| [ScreenX](#screenx) | Returns the x-coordinate of the window relative to the screen. |
| [ScreenY](#screeny) | Returns the y-coordinate of the window relative to the screen. |
| [SetBackColor](#setbackcolor) | Sets the background color of a `CWindow`. |
| [SetClientSize](#setclientsize) | Adjusts the bounding rectangle of the window based on the desired size of the client area. |
| [SetControlCallback](#setcontrolcallback) | Optional address of a callback function that receives all WM_COMMAND and WM_NOTIFY messages for the control. |
| [SetControlSubclass](#setcontrolsubclass) | Installs or updates a control subclass callback. |
| [SetCtlColors](#setctlcolors) | Sets the colors of a control |
| [SetFont](#setfont) | Creates a DPI aware logical font and sets it as the default font. |
| [SetWindowPos](#setwindowpos) | Changes the size, position, and Z order of a child, pop-up, or top-level window. |
| [SmallIcon](#smallicon) | Associates a new small icon with the main window. |
| [Stabilize](#stabilize) | Makes the `CWindow` window stabilized (non-closeable). |
| [UnScaleX](#unscalex) | Unscales an horizontal coordinate according the DPI setting. |
| [UnScaleY](#unscaley) | Unscales a vertical coordinate according the DPI setting. |
| [UserData](#userdata) | Gets/sets a value in the user data area of the window. |
| [Width](#width) | Returns the unscaled width of the main window. |
| [WindowExStyle](#windowexstyle) | Gets/sets the window extended styles. |
| [WindowStyle](#windowstyle) | Gets/sets the window styles. |
| [WindowStyleEx](#windowexstyle) | Gets/sets the window extended styles. |

### Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxCWindowPtr](#afxcwindowptr) | Returns a pointer to the **CWindow** class given the handle of the main window or the CREATESTRUCT structure associated with it. |
| [AfxCWindowOwnerPtr](#afxcwindowownerptr) | Returns a pointer to the **CWindow** class given the handle of the window created with it or the handle of any of it's children windows or controls. |

### Dialog

| Name       | Description |
| ---------- | ----------- |
| [AfxInputBox](#afxinputbox) | Input box dialog. |

# Tutorial

### <a name="topic1"></a>Creating the main window

To use `CWindow` you must first include "CWindow.inc" and allow all symbols of its namespace to be accessed adding **USING AfxNova**.

```
#INCLUDE ONCE "AfxNova/CWindow.inc"
USING AfxNova
```

The first step is to create an instance of the class:

```
DIM pWindow AS CWindow
```

The `CWindow` constructor registers a class for the window with the name "FBWindowClass:xxx", where xxx is a counter number. Alternatively, you can force the use of your own class name by specifying it, e.g.

```
DIM pWindow AS CWindow = "MyClassName"
```

The constructor also checks if the application is DPI aware and calculates the scaling ratios and the default font name ("Segoe UI", 9 pt, for Windows 10 and above").

You can override it by setting your own DPI and/or font before creating the window, e.g.

```
DIM pWindow AS CWindow
pWindow. DPI = 96
pWindow.SetFont("Times New Roman", 10, FW_NORMAL, , , , DEFAULT_CHARSET)
```

By default, `CWindow` uses a standard COLOR_3DFACE + 1 brush. You can override it calling the **Brush** property:

```
DIM pWindow AS CWindow
pWindow.Brush = GetStockObject(WHITE_BRUSH)
```

This makes the background of the window white.

The window class uses CS_HREDRAW OR CS_VREDRAW as default window styles. Without them, the background is not repainted and the controls leave garbage in it when resized. With them, windows with many controls can cause flicker. To avoid flicker, you can change the windows style using e.g. pWindow.ClassStyle = CS_DBLCLKS and take care yourself of repainting.

The next step is to create the window.

The **Create** method has many parameters, all of which are optional:

```
hParent     = Parent window handle
wszTitle    = Window caption
lpfnWndProc = Address of the callback function
x           = Horizontal position
y           = Vertical position
nWidth      = Window width
nHeight     = Window height
dwStyle     = Window style
dwExStyle   = Extended style
```

The most verbose way to call it is:

```
DIM hwndMain AS HWND = pWindow.Create(NULL, "CWindow Test", @WndProc, 0, 0, 525, 395, _
   WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS, WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE)
```

But just using

```
pWindow.Create
```

a working window is created and sized using CW_USEDEFAULT.

Unless the window has to use all the available desktop space, it may be preferible to use the **SetClientSize** method to size the window because Windows UI elements such the caption and borders have different sizes depending of the Windows version and/or the styles used. Therefore, to make sure that you have enough room for your controls, sizing the window according the client size seems more adequate.

We may need to process Windows messages, so we need to provide a callback function, e.g.

```
' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

and we have to pass the address of that callback function:

```
pWindow.Create(NULL, "CWindow Test", @WndProc)
pWindow.SetClientSize(500, 320)   ' The size may vary
```

Optionally, we can automatically center the window in the destop calling the **Center** method, e.g.

```
pWindow.Create(NULL, "CWindow Test", @WndProc)
pWindow.SetClientSize(500, 320)   ' The size may vary
pWindow.Center
```

To process Windows messages we need a message pump. **CWindow** provides a default one calling the **DoEvents** method:

```
FUNCTION = pWindow.DoEvents(nCmdShow)
```

This default message pump displays the window and processes the messages. It can be used with most applications, but, in case of need, you can replace it with your own, e.g.

```
' // Displays the window
DIM hwndMain AS HWND = pWindow.hWindow
ShowWindow(hwndMain, nCmdShow)
UpdateWindow(hwndMain)

' // Processes Windows messages
DIM uMsg AS MSG
WHILE (GetMessageW(@uMsg, NULL, 0, 0) <> FALSE)
   IF IsDialogMessageW(hWndMain, @uMsg) = 0 THEN
      TranslateMessage(@uMsg)
      DispatchMessageW(@uMsg)
   END IF
WEND
FUNCTION = uMsg.wParam
```
Each instance of the `CWindow` class has an user data area consisting in an array of 99 LONG_PTR values that you can use to store information that you find useful.

These values are set and retrieved using the **UserData** property and an index from 0 to 99.

---

### <a name="topic2"></a>Getting a pointer to the CWindow class

At any time, you can get a pointer to the **CWindow** class by using:

```
DIM pWindow AS CWindow PTR = CAST(CWindow PTR, GetWindowLongPtrW(hwnd, 0))
- or -
DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
```
where *hwnd* is the handle of its associated window handle.

If the handle of the main window its not available, the function **AfxCWindowOwnerPtr** allows the use of the handle of any of it's child controls.

An special case is the WM_CREATE message.

At the time in which this message is processed in the window callback, **CWindow** has not yet been able to store the pointer in the extra bytes of the window class.

To solve this problem, the **Create** method passes the pointer to the class in the *lParam* parameter when calling the API function **CreateWindowEx** to create the window.

This pointer can be retrieved in WM_CREATE using:

```
CASE WM_CREATE
   DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
   DIM pWindow AS CWindow PTR = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
- or -
CASE WM_CREATE
   DIM pWindow AS CWindow PTR = AfxCWindowPtr(lParam)
```
---

### <a name="topic3"></a>Adding controls

To add controls to the window you can use the **AddControl** method. Alternatively, you can use the API function **CreateWindowEx**, but then you will have to do scaling by yourself.

Besides the registered class names for the controls, in many cases you can use easier to remember aliases. For example. you can use "STATUSBAR" instead of "MSCTLS_STATUSBAR32".

The **AddControl** method also provides default styles for all the Windows controls. Therefore, you can save typing unless you need to use different styles.

For example, to add a button you can use

```
pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 350, 250, 75, 23)
```

instead of

```
pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 350, 250, 75, 23, _
   WS_CHILD OR WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER)
```

For a list of predefined class names and styles, see the **AddControl** method.

If the application is DPI aware, controls created with the **AddControl** method are scaled according to the DPI setting.

---

### <a name="topic4"></a>Popup windows

To create a popup window you simply create a new instance of the `CWindow` class and, in the **Create** method, you make it child of the main window and use the **WS_POPUPWINDOW** style.

```
DIM pWindow AS CWindow
pWindow.Create(hParent, "Popup window", @PopupWndProc, , , , , _
   WS_VISIBLE OR WS_CAPTION OR WS_POPUPWINDOW OR WS_THICKFRAME, WS_EX_WINDOWEDGE)
```

The window created this way is modeless. To make it modal, we need to disable the parent window:

```
CASE WM_CREATE
   EnableWindow GetParent(hwnd), FALSE
```

When the popup dialog is closed, we need to enable the parent window:

```
CASE WM_CLOSE
   ' // Enables parent window keeping parent's zorder
   EnableWindow GetParent(hwnd), CTRUE
```

#### Example

```
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
USING AfxNova

CONST IDC_POPUP = 1001

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG

   END wWinMain(GetModuleHandleW(NULL), NULL, WCOMMAND(), SW_NORMAL)

DECLARE FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
DECLARE FUNCTION PopupWindow (BYVAL hParent AS HWND) AS LONG
DECLARE FUNCTION PopupWndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a popup window", @WndProc)
   pWindow.SetClientSize(500, 320)
   pWindow.Center

   ' // Add a button
   pWindow.AddControl("Button", pWindow.hWindow, IDC_POPUP, "&Popup", 350, 250, 75, 23)

   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         ' // If ESC key pressed, close the application sending an WM_CLOSE message
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDC_POPUP
               IF HIWORD(wParam) = BN_CLICKED THEN
                  PopupWindow(hwnd)
                  EXIT FUNCTION
               END IF
         END SELECT

    	CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Popup window procedure
' ========================================================================================
FUNCTION PopupWindow (BYVAL hParent AS HWND) AS LONG

   DIM pWindow AS CWindow
   pWindow.Create(hParent, "Popup window", @PopupWndProc, , , , , _
      WS_VISIBLE OR WS_CAPTION OR WS_POPUPWINDOW OR WS_THICKFRAME, WS_EX_WINDOWEDGE)
   pWindow.Brush = GetStockObject(WHITE_BRUSH)
   pWindow.SetClientSize(300, 200)
   pWindow.Center(pWindow.hWindow, hParent)
   ' / Process Windows messages
   FUNCTION = pWindow.DoEvents

END FUNCTION
' ========================================================================================

' ========================================================================================
' Popup window procedure
' ========================================================================================
FUNCTION PopupWndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   DIM hOldFont AS HFONT
   STATIC hNewFont AS HFONT

   SELECT CASE uMsg

      CASE WM_CREATE
         ' // Get a pointer to the CWindow class from the CREATESTRUCT structure
         DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
         DIM pWindow AS CWindow PTR = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
         ' // Create a new font scaled according the DPI ratio
         IF pWindow->DPI <> 96 THEN hNewFont = pWindow->CreateFont("Tahoma", 9)
         ' Disable parent window to make popup window modal
         EnableWindow GetParent(hwnd), FALSE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_PAINT
    		DIM rc AS RECT, ps AS PAINTSTRUCT, hDC AS HANDLE
         hDC = BeginPaint(hWnd, @ps)
         IF hNewFont THEN hOldFont = CAST(HFONT, SelectObject(hDC, CAST(HGDIOBJ, hNewFont)))
         GetClientRect(hWnd, @rc)
         DrawTextW(hDC, "Hello, World!", -1, @rc, DT_SINGLELINE or DT_CENTER or DT_VCENTER)
         IF hNewFont THEN SelectObject(hDC, CAST(HGDIOBJ, CAST(HFONT, hOldFont)))
         EndPaint(hWnd, @ps)
         EXIT FUNCTION

      CASE WM_CLOSE
         ' // Enables parent window keeping parent's zorder
         EnableWindow GetParent(hwnd), CTRUE
         ' // Don't exit; let DefWindowProcW perform the default action

    	CASE WM_DESTROY
         ' // Destroy the new font
         IF hNewFont THEN DeleteObject(CAST(HGDIOBJ, hNewFont))
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

#### Modeless Popup Windows and Custom Message Pump

In the above example, if you remove **EnableWindow** to keep the popup window modeless, you must replace the default message pump (**CWindow.DoEvents**) with a custom loop. Otherwise, the popup may not exit cleanly when the main window closes.

**Problem**: When the main window is destroyed, it sends **WM_DESTROY** to its children—including the modeless popup. The popup may call **PostQuitMessage**, but if it doesn't have focus, it won't receive **WM_QUIT**, and its message loop will continue running.

**Solution**: Use a custom message pump that checks if the popup window still exists. Once `IsWindow(hWnd)` returns FALSE, the loop exits cleanly.

Therefore, replace

```
' / Process Windows messages
FUNCTION = pWindow.DoEvents
```

with a custom message pump like this:

```
DIM hWndPopUp AS HWND = pWindow.hWindow
DIM uMsg AS tagMsg
DO
   IF PeekMessageW(@uMsg, NULL, 0, 0, PM_REMOVE) THEN
      IF IsDialogMessageW(hWndPopUp, @uMsg) = 0 THEN
         TranslateMessage @uMsg
         DispatchMessage @uMsg
      END IF
   END IF
LOOP WHILE IsWindow(hWndPopUp)
FUNCTION = uMsg.wParam
```

and remove `PostQuitMessage(0)` in **WM_DESTROY**.

---

### <a name="topic5"></a>Using PNG icons in toolbars

**AfxGdiplus.inc** provides functions that allow to use alpha-blended PNG icons in toolbars.

**AfxGdipAddIconFromFile** loads the images from disk and **AfxGdipAddIconFromRes** from a resource file embedded in the application.

We need to create an image list for the toolbar of the appropriate size. To calculate the size, I'm using the following formula: 16 * pWindow.DPI \ 96. Where 16 is the size of a normal icon (for toolbars it may be preferible to use 20 to make them a bit bigger), pWindow.DPI the DPI being used by the computer and 96 the DPI used by applications that are not DPI aware.

```
' // Create an image list for the toolbar
DIM hImageList AS HIMAGELIST
DIM cx AS LONG = 16 * pWindow.DPI \ 96
hImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
IF hImageList THEN
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_ARROW_LEFT_48")
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_ARROW_RIGHT_48")
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_HOME_48")
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_SAVE_48")
END IF
SendMessageW hToolBar, TB_SETIMAGELIST, 0, CAST(LPARAM, hImageList)
```

We are using 48 bit icons in this example, that usually resize well to adapt to different DPI settings. This way, we can use only a set of icons instead of several sets of icons of different sizes. However, for best quality, it is advisable to use the appropriate icon size.

**AfxGdipAddIconFromFile** and **AfxGdipAddIconFromRes** also provide two optional parameters, *dimPercent* and *bGrayScale*. With *dimPercent* you can indicate a percentage of dimming, and *bGrayScale* is a boolean value (TRUE or FALSE) that tells these functions to convert the icon colors to shades of gray. This allows to create an image list for disabled items with the same icon set. The following code creates a disabled image using the same color PNG icons, but dimming them a 60% and converting them to gray:

```
' // Create a disabled image list for the toolbar
DIM hDisabledImageList AS HIMAGELIST
DIM cx AS LONG = 16 * pWindow.DPI \ 96
hDisabledImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
IF hDisabledImageList THEN
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_ARROW_LEFT_48", 60, TRUE))
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_ARROW_RIGHT_48", 60, TRUE))
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_HOME_48", 60, TRUE))
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_SAVE_48", 60, TRUE))
END IF
SendMessageW hToolBar, TB_SETDISABLEDIMAGELIST, 0, CAST(LPARAM, hDisabledImageList)
```

**Resource file**:

```
//=============================================================================
// Manifest
//=============================================================================

1 24 ".\Resources\Manifest.xml"

//=============================================================================
// Toolbar icons
//=============================================================================

// Toolbar, normal
IDI_ARROW_LEFT       RCDATA ".\Resources\arrow_left_48.png"
IDI_ARROW_RIGHT      RCDATA ".\Resources\arrow_right_48.png"
IDI_HOME             RCDATA ".\Resources\home_48.png"
IDI_SAVE             RCDATA ".\Resources\save_48.png"

```

**Manifest**:

```
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
   <assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0" xmlns:asmv3="urn:schemas-microsoft-com:asm.v3">

      <assemblyIdentity version="1.0.0.0"
         processorArchitecture="*"
         name="ApplicationName"
         type="win32"/>
      <description>Optional description of your application</description>

      <asmv3:application>
         <asmv3:windowsSettings xmlns="http://schemas.microsoft.com/SMI/2005/WindowsSettings">
            <dpiAware>true</dpiAware>
         </asmv3:windowsSettings>
      </asmv3:application>

      <!-- Compatibility section -->
      <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
         <application>
            <!--The ID below indicates application support for Windows Vista -->
            <supportedOS Id="{e2011457-1546-43c5-a5fe-008deee3d3f0}"/>
            <!--The ID below indicates application support for Windows 7 -->
            <supportedOS Id="{35138b9a-5d96-4fbd-8e2d-a2440225f93a}"/>
            <!--This Id value indicates the application supports Windows 8 functionality-->
            <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}"/>
            <!--This Id value indicates the application supports Windows 8.1 functionality-->
            <supportedOS Id="{1f676c76-80e1-4239-95bb-83d0f6d0da78}"/>
            <!--This Id value indicates the application supports Windows 10 functionality-->
            <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}"/>
         </application>
       </compatibility>

      <!-- Trustinfo section -->
      <trustInfo xmlns="urn:schemas-microsoft-com:asm.v2">
         <security>
            <requestedPrivileges>
               <requestedExecutionLevel
                  level="asInvoker"
                  uiAccess="false"/>
               </requestedPrivileges>
         </security>
      </trustInfo>

      <dependency>
         <dependentAssembly>
            <assemblyIdentity
               type="win32"
               name="Microsoft.Windows.Common-Controls"
               version="6.0.0.0"
               processorArchitecture="*"
               publicKeyToken="6595b64144ccf1df"
               language="*" />
         </dependentAssembly>
      </dependency>

   </assembly>
```

#### Example

```
#define unicode
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxCtl.inc"
#INCLUDE ONCE "AfxNova/AfxGdiplus.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS wSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG

   END wWinMain(GetModuleHandleW(NULL), NULL, WCOMMAND(), SW_NORMAL)

CONST IDC_TOOLBAR = 1001
enum
   IDM_LEFTARROW = 28000
   IDM_RIGHTARROW
   IDM_HOME
   IDM_SAVEFILE
end enum

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   DIM pWindow AS CWindow PTR

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
'            CASE IDM_CUT   ' etc.
'               MessageBoxW hwnd, "You have clicked the Cut button", "Toolbar", MB_OK
'               EXIT FUNCTION
         END SELECT

      CASE WM_DESTROY
         ' // Destroy the image list
         ImageList_Destroy CAST(HIMAGELIST, SendMessageW(GetDlgItem(hwnd, IDC_TOOLBAR), TB_SETIMAGELIST, 0, 0))
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a toolbar", @WndProc)
   ' // Set the client size
   pWindow.SetClientSize(600, 300)
   ' // Center the window
   pWindow.Center

   ' // Add a button
   pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close")

   ' // Add a tooolbar
   DIM hToolBar AS HWND = pWindow.AddControl("Toolbar", pWindow.hWindow, IDC_TOOLBAR)
   ' // Module instance handle
   DIM hInst AS HINSTANCE = GetModuleHandle(NULL)
   ' // Create an image list for the toolbar
   DIM hImageList AS HIMAGELIST
   DIM cx AS LONG = 16 * pWindow.DPI \ 96
   hImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
   IF hImageList THEN
      AfxGdipAddIconFromRes(hImageList, hInst, "IDI_ARROW_LEFT_48")
      AfxGdipAddIconFromRes(hImageList, hInst, "IDI_ARROW_RIGHT_48")
      AfxGdipAddIconFromRes(hImageList, hInst, "IDI_HOME_48")
      AfxGdipAddIconFromRes(hImageList, hInst, "IDI_SAVE_48")
   END IF
   SendMessageW hToolBar, TB_SETIMAGELIST, 0, CAST(LPARAM, hImageList)

   ' // Add buttons to the toolbar
   Toolbar_AddButton hToolBar, 0, IDM_LEFTARROW
   Toolbar_AddButton hToolBar, 1, IDM_RIGHTARROW
   Toolbar_AddButton hToolBar, 2, IDM_HOME
   Toolbar_AddButton hToolBar, 3, IDM_SAVEFILE

   ' // Size the toolbar
   SendMessageW hToolBar, TB_AUTOSIZE, 0, 0

   ' // Process event messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================
```
---

### <a name="topic6"></a>Visual style menus

Windows Vista and posterior Windows versions provide menus that are part of the visual schema. These menus are rendered using visual styles, which can be added to existing applications. Adding code for new features to existing code must be done carefully to avoid breaking existing application behavior. Certain situations can cause visual styling to be disabled in an application. These situations include:

* Customizing menus using owner-draw menu items (MFT_OWNERDRAW)
* Using menu breaks (MFT_MENUBREAK or MFT_MENUBARBREAK)
* Using HBMMENU_CALLBACK to defer bitmap rendering
* Using a destroyed menu handle

These situations prevent visual style menus from being rendered. Owner-draw menus can be used in Windows Vista and posterior Windows versions, but the menus will not be visually styled. Windows Vista and posterior Windows versions provide alpha-blended bitmaps, which enables menu items to be shown without using owner-draw menu items.

**Requirements**:

* The bitmap is a 32bpp DIB section.
* The DIB section has BI_RGB compression.
* The bitmap contains pre-multiplied alpha pixels.
* The bitmap is stored in hbmpChecked, hbmpUnchecked, or hbmpItem fields.

**Note**: MFT_BITMAP items do not support PARGB32 bitmaps.

The **AfxAddIconToMenuItem** function included in **AfxMenu.inc** allows to use alpha-blended icons in visually styled menus.

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
DIM hIcon AS HICON
hIcon = LoadImageW(NULL, "MyIcon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE)
IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
```

PNG icons can be used by converting them first to an icon with **AfxGdipImageFromFile**:

```
hIcon = AfxGdipImageFromFile("MyIcon.png")
IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
```

But, in general, we are more interested in loading the icons from a resource file embedded in the application. We can achieve it using the **AfxGdipIconFromRes** function.

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 0)
AfxAddIconToMenuItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInst, "IDI_ARROW_LEFT_48"))
```

#### Remarks

Unlike toolbars, which use image lists, menus do not copy the icons but store their handles directly. Therefore, the icons must remain valid for as long as the menu exists.

The difference between **AfxGdipIconFromFile** / **AfxGdipIconFromRes** (used with menus) and **AfxAddGdipIconFromFile** / **AfxAddGdipIconFromRes** (used with image lists) is that the latter functions destroy the original icon after copying it into the image list.

Since menu icons are not copied, they must be destroyed manually when the menu is no longer needed. To do this, call the **AfxDestroyMenuBitmaps** function before destroying the menu.

#### Example

The following code uses the same resource file that the one for the "Using PNG icons in toolbars example" to demonstrate that we can use just one set of icons for both toolbars and menus.

```
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "win/uxtheme.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxGdiplus.inc"
#INCLUDE ONCE "AfxNova/AfxMenu.inc"
USING AfxNova

' // Menu identifiers
#define IDM_UNDO     1001   ' Undo
#define IDM_REDO     1002   ' Redo
#define IDM_HOME     1003   ' Home
#define IDM_SAVE     1004   ' Save file
#define IDM_EXIT     1005   ' Exit

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL pwszCmdLine AS WSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END wWinMain(GetModuleHandleW(NULL), NULL, WCOMMAND(), SW_NORMAL)

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CreateMenu
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+U"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_REDO, "&Redo" & CHR(9) & "Ctrl+R"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_HOME, "&Home" & CHR(9) & "Ctrl+H"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDM_UNDO
               MessageBox hwnd, "Undo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_REDO
               MessageBox hwnd, "Redo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_HOME
               MessageBox hwnd, "Home option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_SAVE
               MessageBox hwnd, "Save option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT

      CASE WM_DESTROY
         ' // Destroy the menu and the bitmaps
         DIM hMenu AS HMENU = GetMenu(hwnd)
         AfxDestroyMenuBitmaps(hMenu)
         DestroyMenu(hMenu)              
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         RETURN 0

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a menu", @WndProc)
   pWindow.SetClientSize(400, 250)
   pWindow.Center

   ' // Add a button
   pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 280, 180, 75, 23)

   ' // Module instance handle
   DIM hInst AS HINSTANCE = GetModuleHandle(NULL)

   ' // Create the menu
   DIM hMenu AS HMENU = BuildMenu
   SetMenu pWindow.hWindow, hMenu

   ' // Add icons to the items of the File menu
   DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 0)
   AfxAddIconToMenuItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInst, "IDI_ARROW_LEFT_48"))
   AfxAddIconToMenuItem(hSubMenu, 1, TRUE, AfxGdipIconFromRes(hInst, "IDI_ARROW_RIGHT_48"))
   AfxAddIconToMenuItem(hSubMenu, 2, TRUE, AfxGdipIconFromRes(hInst, "IDI_HOME_48"))
   AfxAddIconToMenuItem(hSubMenu, 3, TRUE, AfxGdipIconFromRes(hInst, "IDI_SAVE_48"))

   ' // Process Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================
```
---

### <a name="topic7"></a>Keyboard Accelerators

Accelerators are closely related to menus — both provide the user with access to an application's command set. Typically, users rely on an application's menus to learn the command set and then switch over to using accelerators as they become more proficient with the application. Accelerators provide faster, more direct access to commands than menus do. At a minimum, an application should provide accelerators for the more commonly used commands. Although accelerators typically generate commands that exist as menu items, they can also generate commands that have no equivalent menu items. 

Creating an accelerator table with **CWindow** is very simple. You only need to build the table with calls to the **AddAccelerator** method and then call the **CreateAcceleratorTable** method. The accelerator table will be destroyed automatically when the window is destroyed or the applications ends. If you need to change the accelerator table, you can first destroy it calling the **DestroyAcceleratorTable** method, build a new table with **AddAccelerator** and then call **CreateAcceleratorTable**.

```
' // Create a keyboard accelerator table
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "U", IDM_UNDO ' // Ctrl+U - Undo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "R", IDM_REDO ' // Ctrl+R - Redo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "H", IDM_HOME ' // Ctrl+H - Home
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "S", IDM_SAVE ' // Ctrl+S - Save
pWindow.CreateAcceleratorTable
```

#### Example

The following example creates a menu and an accelerator table.

```
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxMenu.inc"
USING AfxNova

' // Menu identifiers
#define IDM_UNDO     1001   ' Undo
#define IDM_REDO     1002   ' Redo
#define IDM_HOME     1003   ' Home
#define IDM_SAVE     1004   ' Save file
#define IDM_EXIT     1005   ' Exit

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG

   END wWinMain(GetModuleHandleW(NULL), NULL, WCOMMAND(), SW_NORMAL)

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CreateMenu
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+U"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_REDO, "&Redo" & CHR(9) & "Ctrl+R"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_HOME, "&Home" & CHR(9) & "Ctrl+H"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDM_UNDO
               MessageBox hwnd, "Undo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_REDO
               MessageBox hwnd, "Redo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_HOME
               MessageBox hwnd, "Home option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_SAVE
               MessageBox hwnd, "Save option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT

      CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a menu", @WndProc)
   pWindow.SetClientSize(400, 250)
   pWindow.Center

   ' // Add a button
   DIM hButton AS HWND = pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 280, 180, 75, 23)
   SetFocus hButton

   ' // Module instance handle
   DIM hInst AS HINSTANCE = GetModuleHandle(NULL)

   ' // Create the menu
   DIM hMenu AS HMENU = BuildMenu
   SetMenu pWindow.hWindow, hMenu

   ' // Create a keyboard accelerator table
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "U", IDM_UNDO ' // Ctrl+U - Undo
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "R", IDM_REDO ' // Ctrl+R - Redo
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "H", IDM_HOME ' // Ctrl+H - Home
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "S", IDM_SAVE ' // Ctrl+S - Save
   pWindow.CreateAcceleratorTable

   ' // Process Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================
```
---

## AccelHandle

Gets/sets the accelerator table handle.

```
PROPERTY AccelHandle () AS HACCEL
PROPERTY AccelHandle (BYVAL hAccel AS HACCEL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hAccel* | The new accelerator table handle. |

#### Return value

The current accelerator table handle.

#### Remarks

If a previous table was attached to the target dialog, the table is automatically destroyed when the new table is attached in its place. The accelerator table is also destroyed automatically when the class is destroyed.

You can destroy the current accelerator table by setting the property with a null handle.

#### Usage example

DIM hAccel AS HACCEL = pWindow.AccelHandle

---

## AddAccelerator

Adds an accelerator key to the table.

```
SUB AddAccelerator (BYVAL fvirt AS UBYTE, BYVAL wKey AS WORD, BYVAL cmd AS WORD)
```

| Parameter  | Description |
| ---------- | ----------- |
| *fvirt* | The accelerator behavior. This member can be one or more of the following values:<br>**FALT (&H10)** : The ALT key must be held down when the accelerator key is pressed.<br>**FCONTROL (&H08)** : The CTRL key must be held down when the accelerator key is pressed.<br>**FNOINVERT (&H02)** : No top-level menu item is highlighted when the accelerator is used. If this flag is not specified, a top-level menu item will be highlighted, if possible, when the accelerator is used. This attribute is obsolete and retained only for backward compatibility with resource files designed for 16-bit Windows.<br>**FSHIFT (&H04)** : The SHIFT key must be held down when the accelerator key is pressed.<br>**FVIRTKEY (TRUE)**: The key member specifies a virtual-key code. If this flag is not specified, key is assumed to specify a character code. |
| *vKey* | The accelerator key. This member can be either a virtual-key code or a character code. |
| *cmd* | The accelerator identifier. This value is placed in the low-order word of the wParam parameter of the WM_COMMAND or WM_SYSCOMMAND message when the accelerator is pressed. |

#### Remarks

To create an accelerator table, first add all the keys using this method and then call the **CreateAcceleratorTable** method.

#### Example

```
' // Create a keyboard accelerator table
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "U", IDM_UNDO ' // Ctrl+U - Undo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "R", IDM_REDO ' // Ctrl+R - Redo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "H", IDM_HOME ' // Ctrl+H - Home
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "S", IDM_SAVE ' // Ctrl+S - Save
pWindow.CreateAcceleratorTable
```
---

## AddControl

Adds a control to the window.

```
FUNCTION AddControl (BYREF wszClassName AS WSTRING, BYVAL hParent AS HWND = NULL, _
   BYVAL cID AS LONG_PTR = 0, BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = 0, _
   BYVAL y AS LONG = 0, BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, _
   BYVAL dwStyle AS LONG = -1, BYVAL dwExStyle AS LONG = -1, _
   BYVAL lpParam AS LONG_PTR = 0) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszClassName* | The window class name. The class name can be any name registered with **RegisterClass** or **RegisterClassEx**, provided that the module that registers the class is also the module that creates the window. The class name can also be any of the predefined system class names. |
| *hParent* | A handle to the parent or owner window of the control being created. If this parameter is omitted, the handle of the main window beloging to the **CWindow** class is used. |
| *cID* | The control identifier, an integer value used to notify its parent about events. The application determines the control identifier; it must be unique for all controls with the same parent window. |
| *wszTitle* | The window name. If the window style specifies a title bar, the window title is displayed in the title bar. When creating controls, such as buttons, check boxes, and static controls, use wszTitle to specify the text of the control. When creating a static control with the SS_ICON style, use wszTitle to specify the icon name or identifier. To specify an identifier, use the syntax *"#num"*. |
| *x* | The x-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *y* | The initial y-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the control. |
| *nHeight* | The height of the control. |
| *dwStyle* | The window styles of the control being created. |
| *dwExStyle* | The extended window styles of the control being created. |
| *lpParam* | Optional. Pointer to a value to be passed to the window through the CREATESTRUCT structure (lpCreateParams member) pointed to by the lParam param of the WM_CREATE message. This message is sent to the created window by this function before it returns. |

#### Return value

If the method succeeds, the return value is a handle to the new control.

If the method fails, the return value is NULL. To get extended error information, call **GetLastError**.

This method typically fails for one of the following reasons:

* An invalid parameter value
* The system class was registered by a different module
* The WH_CBT hook is installed and returns a failure code
* If the control is not registered or its window window procedure fails WM_CREATE or WM_NCCREATE.

#### Predefined class names and styles

| Class name | Styles      |
| ---------- | ----------- |
| **"BUTTON"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER.<br>**BS_FLAT**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER OR BS_FLAT.<br>**BS_DEFPUSHBUTTON**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_DEFPUSHBUTTON.<br>**BS_ICON**: WS_CHILD OR WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_ICON.<br>**BS_BITMAP**: WS_CHILD OR WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_BITMAP.<br>**BS_OWNERDRAW**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_OWNERDRAW.<br>**BS_SPLITBUTTON**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_SPLITBUTTON>.<br>**BS_DEFSPLITBUTTON**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_CENTER OR BS_VCENTER OR BS_DEFSPLITBUTTON.<br>**BS_COMMANDLINK**: WS_CHILD OR WS_VISIBLE OR WS_TABSTOP OR BS_COMMANDLINK.<br>**BS_DEFCOMMANDLINK**: WS_CHILD OR WS_VISIBLE OR WS_TABSTOP OR BS_DEFCOMMANDLINK. |
| **"CUSTOMBUTTON"**, **"OWNERDRAWBUTTON"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_OWNERDRAW. |
| **"RADIOBUTTON"**, **"OPTION"** | **Default**: Default: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_AUTORADIOBUTTON OR BS_LEFT OR BS_VCENTER-<br>**WS_GROUP**: WS_VISIBLE OR WS_TABSTOP OR BS_AUTORADIOBUTTON OR BS_LEFT OR BS_VCENTER OR WS_GROUP. |
| **"CHECKBOX"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_AUTOCHECKBOX OR BS_LEFT OR BS_VCENTER. |
| **"CHECK3STATE"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_AUTO3STATE OR BS_LEFT OR BS_VCENTER. |
| **"LABEL"** | **Default**: WS_CHILD, WS_VISIBLE OR SS_LEFT OR WS_GROUP OR SS_NOTIFY. |
| **"BITMAPLABEL"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_GROUP OR SS_BITMAP.<br>**Default extended style**: WS_EX_TRANSPARENT. |
| **"ICONLABEL"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_GROUP OR SS_ICON.<br>**Default extended style**: WS_EX_TRANSPARENT. |
| **"BITMAPBUTTON"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_BITMAP. |
| **"ICONBUTTON"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_ICON. |
| **"CUSTOMLABEL"** | **Default**: WS_VISIBLE OR WS_GROUP OR SS_OWNERDRAW. |
| **"FRAME"**. **"FRAMEWINDOW** | **Default**: WS_CHILD, WS_VISIBLE OR WS_CLIPSIBLINGS OR WS_GROUP OR SS_BLACKFRAME.<br>**Default extended style**: WS_EX_TRANSPARENT. |
| **"GROUPBOX"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_CLIPSIBLINGS OR WS_GROUP OR BS_GROUPBOX.<br>**Default extended style**: WS_EX_TRANSPARENT. |
| **"LINE"** | **Default**: WS_CHILD, WS_VISIBLE OR SS_ETCHEDFRAME.<br>**Default extended style**: WS_EX_TRANSPARENT. |
| **"EDIT"**, **"TEXTBOX"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR ES_AUTOHSCROLL.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"EDITMULTILINE"**, **"MULTILINETEXTBOX"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR ES_AUTOHSCROLL OR ES_MULTILINE OR ES_NOHIDESEL OR ES_WANTRETURN.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"COMBOBOX"** | **Default**: WS_CHILD OR WS_VISIBLE OR WS_VSCROLL OR WS_BORDER OR WS_TABSTOP OR CBS_DROPDOWN OR CBS_HASSTRINGS OR CBS_SORT.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"COMBOBOXEX"**, **"COMBOBOXEX32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_BORDER OR WS_TABSTOP OR CBS_DROPDOWNLIST. |
| **"LISTBOX"** | **Default**: WS_VISIBLE OR WS_HSCROLL OR WS_VSCROLL OR WS_BORDER OR WS_TABSTOP OR LBS_STANDARD OR LBS_HASSTRINGS OR LBS_SORT OR LBS_NOTIFY.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"PROGRESSBAR"**, **"MSCTLS_PROGRESS32"** | **Default**: WS_CHILD, WS_VISIBLE. |
| **"HEADER"**, **"SYSHEADER32"** | **Default**: WS_CHILD, WS_VISIBLE OR CCS_TOP OR HDS_HORZ OR HDS_BUTTONS. |
| **"TREEVIEW"**, **"SYSTREEVIEW32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_BORDER OR WS_TABSTOP OR TVS_HASBUTTONS OR TVS_HASLINES OR TVS_LINESATROOT OR TVS_SHOWSELALWAYS.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"LISTVIEW"**, **"SYSLISTVIEW32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_CLIPCHILDREN OR WS_TABSTOP OR LVS_REPORT OR LVS_SHOWSELALWAYS OR LVS_SHAREIMAGELISTS OR LVS_AUTOARRANGE OR LVS_EDITLABELS OR LVS_ALIGNTOP.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"TOOLBAR"**, **"TOOLBARWINDOW32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR CCS_TOP OR WS_BORDER OR TBSTYLE_FLAT OR TBSTYLE_TOOLTIPS. |
| **"REBAR"**, **"REBARWINDOW32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_BORDER OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR CCS_NODIVIDER OR RBS_VARHEIGHT OR RBS_BANDBORDERS. |
| **"DATETIMEPICKER"**, **"SYSDATETIMEPICK32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR DTS_SHORTDATEFORMAT. |
| **"MONTHCALENDAR"**, **"MONTHCAL"**, **"SYSMONTHCAL32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"IPADDRESS"**, **"SYSIPADDRESS32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"HOTKEY"**, **"MSCTLS_HOTKEY32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP.<br>**Default extended style**: WS_EX_CLIENTEDGE. |
| **"ANIMATE"**, **"ANIMATION"**, **"SYSANIMATE32"** | **Default**: WS_CHILD, WS_VISIBLE OR ACS_TRANSPARENT. |
| **"SYSLINK"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP. |
| **"PAGER"**, **"SYSPAGER"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP  OR PGS_HORZ. |
| **"TAB"**, **"TABCONTROL"**, **"SYSTABCONTROL32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_GROUP OR WS_TABSTOP OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR TCS_TABS OR TCS_SINGLELINE OR TCS_RAGGEDRIGHT.<br>**Default extended style**: WS_EX_CONTROLPARENT. |
| **"STATUSBAR"**, **"MSCTLS_STATUSBAR32"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS OR CCS_BOTTOM OR SBARS_SIZEGRIP. |
| **"SIZEBAR"**, **"SIZEBOX"**, **"SIZEGRIP"** | **Default**: WS_CHILD, WS_VISIBLE OR SBS_SIZEGRIP OR SBS_SIZEBOXBOTTOMRIGHTALIGN. |
| **"HSCROLLBAR"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR SBS_HORZ. |
| **"VSCROLLBAR"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR SBS_VERT. |
| **"TRACKBAR"**, **"MSCTLS_TRACKBAR32"**, **"SLIDER"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR TBS_AUTOTICKS OR TBS_HORZ OR TBS_BOTTOM. |
| **"UPDOWN"**, **"MSCTLS_UPDOWN32"** | **Default**: WS_VISIBLE OR UDS_WRAP OR UDS_ARROWKEYS OR UDS_ALIGNRIGHT OR UDS_SETBUDDYINT. |
| **"RICHEDIT"**, **"RichEdit50W"** | **Default**: WS_CHILD, WS_VISIBLE OR WS_TABSTOP OR ES_LEFT OR WS_HSCROLL OR WS_VSCROLL OR ES_AUTOHSCROLL OR ES_AUTOVSCROLL OR ES_MULTILINE OR ES_WANTRETURN OR ES_NOHIDESEL OR ES_SAVESEL.<br>**Default extended style**: WS_EX_CLIENTEDGE. |

#### Remarks

For the "BITMAPBUTTON", "BITMAPLABEL", "ICONBUTTON" and "ICONLABEL" controls you must pass in the *wszTitle* parameter the name of the bitmap in the resource file (.RES). If the image resource uses an integral identifier, the name should begin with a number symbol (#) followed by the identifier in an ASCII format, e.g., "#998". Otherwise, use the text identifier name for the image.

---

## AnchorControl

Anchors a window or control to its parent window.

```
FUNCTION AnchorControl (BYVAL hwndCtl AS HWND, BYVAL nAnchorMode AS LONG) AS BOOLEAN
```
```
FUNCTION AnchorControl (BYVAL cID AS LONG, BYVAL nAnchorMode AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndCtl* | Handle to the child window or control. |
| *cID* | Identifier of the child window or control. |
| *nAnchorMode* | One of the following constants. |

#### Constants

```
ENUM AFX_ANCHORPOINT
   AFX_ANCHOR_NONE =  0
   AFX_ANCHOR_WIDTH
   AFX_ANCHOR_RIGHT
   AFX_ANCHOR_CENTER_HORZ
   AFX_ANCHOR_HEIGHT
   AFX_ANCHOR_HEIGHT_WIDTH
   AFX_ANCHOR_HEIGHT_RIGHT
   AFX_ANCHOR_BOTTOM
   AFX_ANCHOR_BOTTOM_WIDTH
   AFX_ANCHOR_BOTTOM_RIGHT
   AFX_ANCHOR_CENTER_HORZ_BOTTOM
   AFX_ANCHOR_CENTER_VERT
   AFX_ANCHOR_CENTER_VERT_RIGHT
   AFX_ANCHOR_CENTER
END ENUM
```

#### Example

```
pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)
pWindow.AnchorControl(IDC_GROUPBOX, AFX_ANCHOR_HEIGHT_RIGHT)
pWindow.AnchorControl(IDC_COMBOBOX, AFX_ANCHOR_RIGHT)
```
---

## BigIcon

Associates a new large icon with the main window. The system displays the large icon in the ALT+TAB dialog box.

```
PROPERTY BigIcon (BYVAL hIcon AS HICON)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hIcon* | The icon handle. If this parameter is NULL, the icon is removed. |

#### Example

```
pWindow.BigIcon = LoadImage(hInstance, MAKEINTRESOURCE(101), IMAGE_ICON, 48, 48, LR_SHARED)
```
---

## SmallIcon

Associates a new small icon with the main window. The system displays the small icon in the in the window caption.

```
PROPERTY SmallIcon (BYVAL hIcon AS HICON)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hIcon* | The icon handle. If this parameter is NULL, the icon is removed. |

#### Example

```
pWindow.SmallIcon = LoadImage(hInstance, MAKEINTRESOURCE(100), IMAGE_ICON, 32, 32, LR_SHARED)
```
---

## Brush

Gets/sets the background brush.

```
PROPERTY Brush () AS HBRUSH
PROPERTY Brush (BYVAL hbrBackground AS HBRUSH)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hbrBackground* | A handle to the class background brush. This member can be a handle to the physical brush to be used for painting the background, or it can be a color value. A color value must be one of the following standard system colors (the value 1 must be added to the chosen color), e.g. COLOR_WINDOW + 1. |

#### Usage examples

```
pWindow.Brush = CAST(HBRUSH, COLOR_WINDOW + 1)
```
```
' // Make the background of the window white
pWindow.Brush = GetStockObject(WHITE_BRUSH)
```
```
' // Make the background of the window blue
pWindow.Brush = CreateSolidBrush(BGR(0, 0, 255))
```
---

## Center

Centers a window on the screen or over another window. It also ensures that the placement is done within the work area.

```
SUB Center (BYVAL hwnd AS HWND = NULL, BYVAL hwndParent AS HWND = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. Handle to the window. If NULL, the handle of the main window is used. |
| *hwndParent* | Optional. Handle to the parent window. If NULL, the coordinates of the work area of the desktop window are used for the calculations. |

#### Example

```
' // Creates the main window
DIM pWindow AS CWindow
pWindow.Create(NULL, "CWindow test", @WndProc)
' // Sizes it by setting the wanted width and height of its client area
pWindow.SetClientSize(500, 320)
' // Centers the window
pWindow.Center
```
---

## ClassStyle

Gets/sets the style of the class.

```
PROPERTY ClassStyle () AS ULONG_PTR
PROPERTY ClassStyle (BYVAL dwStyle AS ULONG_PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwStyle* | The class style. Can be a combination of the following constants: |

| Constant   | Description |
| ---------- | ----------- |
| **CS_BYTEALIGNCLIENT** | Aligns the window's client area on a byte boundary (in the x direction). This style affects the width of the window and its horizontal placement on the display. |
| **CS_BYTEALIGNWINDOW** | Aligns the window on a byte boundary (in the x direction). This style affects the width of the window and its horizontal placement on the display. |
| **CS_CLASSDC** | Allocates one device context to be shared by all windows in the class. Because window classes are process specific, it is possible for multiple threads of an application to create a window of the same class. It is also possible for the threads to attempt to use the device context simultaneously. When this happens, the system allows only one thread to successfully finish its drawing operation. |
| **CS_DBLCLKS** | Sends a double-click message to the window procedure when the user double-clicks the mouse while the cursor is within a window belonging to the class. |
| **CS_DROPSHADOW** | Enables the drop shadow effect on a window. The effect is turned on and off through **SPI_SETDROPSHADOW**. Typically, this is enabled for small, short-lived windows such as menus to emphasize their Z order relationship to other windows. |
| **CS_GLOBALCLASS** | Indicates that the window class is an application global class. |
| **CS_HREDRAW** | Redraws the entire window if a movement or size adjustment changes the width of the client area. |
| **CS_NOCLOSE** | Disables **Close** on the window menu. |
| **CS_OWNDC** | Allocates a unique device context for each window in the class. |
| **CS_PARENTDC** | Sets the clipping rectangle of the child window to that of the parent window so that the child can draw on the parent. A window with the **CS_PARENTDC** style bit receives a regular device context from the system's cache of device contexts. It does not give the child the parent's device context or device context settings. Specifying **CS_PARENTDC** enhances an application's performance. |
| **CS_SAVEBITS** | Saves, as a bitmap, the portion of the screen image obscured by a window of this class. When the window is removed, the system uses the saved bitmap to restore the screen image, including other windows that were obscured. Therefore, the system does not send **WM_PAINT** messages to windows that were obscured if the memory used by the bitmap has not been discarded and if other screen actions have not invalidated the stored image.<br>This style is useful for small windows (for example, menus or dialog boxes) that are displayed briefly and then removed before other screen activity takes place. This style increases the time required to display the window, because the system must first allocate memory to store the bitmap. |
| **CS_VREDRAW** | Redraws the entire window if a movement or size adjustment changes the height of the client area. |

#### Example

```
' // Creates the main window
DIM pWindow AS CWindow
pWindow.Create(NULL, "CWindow test", @WndProc)
' // Change the class style
pWindow.ClassStyle = CS_DBLCLKS
```
---

## ClientHeight

Returns the unscaled client height of the main window.

```
PROPERTY ClientHeight () AS LONG
```

#### Usage example

```
DIM nHeight AS LONG = pWindow.ClientHeight
```
---

## ClientWidth

Returns the unscaled client width of the main window.

```
PROPERTY ClientWidth () AS LONG
```

#### Usage example

```
DIM nWidth AS LONG = pWindow.ClientWidth
```
---

## ControlClientHeight

Returns the unscaled client height of the specified window or control.

```
PROPERTY ControlClientHeight (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |

#### Usage example

```
DIM nHeight AS LONG = pWindow.ControlClientHeight(hwnd)
```
---

## ControlClientWidth

Returns the unscaled client width of the specified window or control.

```
PROPERTY ControlClientWidth (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |

#### Usage example

```
DIM nHeight AS LONG = pWindow.ControlClientWidth(hwnd)
```
---

## ControlGetUser

Gets the control's user data.

```
FUNCTION ControlGetUser (BYVAL hCtl AS LONG, BYVAL index AS LONG) AS LONG_PTR
FUNCTION ControlGetUser (BYVAL cID AS LONG, BYVAL index AS LONG) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the control. |
| *cID* | The control identifier. |
| *index* | The index number of the user data value to retrieve, in the range 0 to 9 inclusive. |

#### Remarks

Each control has a user data area consisting of ten LONG_PTR values which may be used at the programmer's discretion to save relevant data. **ControlGetUser** allows one of the values to be retrieved, based upon the index parameter value (0 through 9).

#### Return value

Returns the LONG_PTR data value stored in the nominated user data index.

---

## ControlSetUser

Sets the control's user data.

```
FUNCTION ControlSetUser (BYVAL hCtl AS LONG, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
FUNCTION ControlSetUser (BYVAL cID AS LONG, BYVAL index AS LONG, BYVAL userValue AS LONG_PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the control. |
| *cID* | The control identifier. |
| *index* | The index number of the user data value to set, in the range 0 to 9 inclusive. |
| *userValue* | The LONG_PTR data value to store in the user data area. |

#### Remarks

Each control has a user data area consisting of ten LONG_PTR values which may be used at the programmer's discretion to save relevant data. **ControlSetUser** allows one of the values to be set, based upon the index parameter value (0 through 9).

---

## ControlHandle

Retrieves a handle to the child control specified by its identifier.

```
FUNCTION ControlHandle (BYVAL cID AS LONG) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *cID* | The child control identifier. |

#### Usage example

```
DIM hCtl AS HWND = pWindow.ControlHandle(cID)
```
---

## ControlAddExStyle

Adds a new extended style to the specified control.

```
FUNCTION ControlAddExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlAddStyle

Adds a new style to the specified control.

```
FUNCTION ControlAddStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlGetExStyle

Retrieves the extended window styles of the specified control

```
FUNCTION ControlGetExStyle (BYVAL hWnd AS HWND) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlGetStyle

Retrieves the window styles of the specified control

```
FUNCTION ControlGetStyle (BYVAL hWnd AS HWND) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlSetExStyle

Sets the window extended styles of the specified control

```
FUNCTION ControlSetExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlRemoveExStyle

Removes an extended style from the specified control.

```
FUNCTION ControlRemoveExStyle (BYVAL hWnd AS HWND, BYVAL dwExStyle AS DWORD) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlRemoveStyle

Removes an style from the specified control.

```
FUNCTION ControlRemoveStyle (BYVAL hWnd AS HWND, BYVAL dwStyle AS LONG_PTR) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlSetStyle

Sets the window styles of the specified control

```
FUNCTION ControlSetEtyle (BYVAL hWnd AS HWND) AS LONG_PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle of the control. |

---

## ControlHeight

Returns the unscaled height of the specified window.

```
FUNCTION ControlHeight (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |

#### Usage example

```
DIM nHeight AS LONG = pWindow.ControlHeight(hwnd)
```
---

## ControlWidth

Returns the unscaled width of the specified window.

```
FUNCTION ControlWidth (BYVAL hwnd AS HWND) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |

#### Usage example

```
DIM nWidth AS LONG = pWindow.ControlWidth(hwnd)
```
---

## Create

**Create** creates a new window. If you don't specify the window styles, it creates an overlaped window with the styles WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS and the extended styles WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE.

**CreateOverlapped** creates an overlapped window. An overlapped window has a title bar and a border and uses these styles: WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU.

```
FUNCTION Create (BYVAL hParent AS HWND = NULL, BYREF wszTitle AS WSTRING = "", _
   BYVAL lpfnWndProc AS WNDPROC = NULL, BYVAL x AS LONG = CW_USEDEFAULT, _
   BYVAL y AS LONG = CW_USEDEFAULT, BYVAL nWidth AS LONG = CW_USEDEFAULT, _
   BYVAL nHeight AS LONG = CW_USEDEFAULT, 
   BYVAL dwStyle AS UINT = WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS, _
   BYVAL dwExStyle AS UINT = WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE) AS HWND
```
```
FUNCTION CreateOverlapped (BYVAL hParent AS HWND = NULL, BYREF wszTitle AS WSTRING = "", _
   BYVAL lpfnWndProc AS WNDPROC = NULL, BYVAL x AS LONG = CW_USEDEFAULT, _
   BYVAL y AS LONG = CW_USEDEFAULT, BYVAL nWidth AS LONG = CW_USEDEFAULT, _
   BYVAL nHeight AS LONG = CW_USEDEFAULT, _
   BYVAL dwExStyle AS UINT = WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE) AS HWND
```


| Parameter  | Description |
| ---------- | ----------- |
| *hParent* | A handle to the parent or owner window of the control being created. |
| *wszTitle* | The window caption. |
| *lpfnWndProc* | Address of the window callback procedure. |
| *x* | The x-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *y* | The initial y-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the window. |
| *nHeight* | The height of the window. |
| *dwStyle* | The style of the window being created. |
| *dwExStyle* | The extended window style of the control being created. |

#### Return value

If the function succeeds, the return value is a handle to the new window.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Window Styles

The following are the window styles. After the window has been created, these styles cannot be modified, except as noted.

| Constant   | Description |
| ---------- | ----------- |
| WS_BORDER | The window has a thin-line border. |
| WS_CAPTION | The window has a title bar (includes the WS_BORDER style). |
| WS_CHILD | The window is a child window. A window with this style cannot have a menu bar. This style cannot be used with the WS_POPUP style. |
| WS_CHILDWINDOW | Same as the WS_CHILD style. |
| WS_CLIPCHILDREN | Excludes the area occupied by child windows when drawing occurs within the parent window. This style is used when creating the parent window. |
| WS_CLIPSIBLINGS | Clips child windows relative to each other; that is, when a particular child window receives a WM_PAINT message, the WS_CLIPSIBLINGS style clips all other overlapping child windows out of the region of the child window to be updated. If WS_CLIPSIBLINGS is not specified and child windows overlap, it is possible, when drawing within the client area of a child window, to draw within the client area of a neighboring child window. |
| WS_DISABLED | The window is initially disabled. A disabled window cannot receive input from the user. To change this after a window has been created, use the **EnableWindow** function. |
| WS_DLGFRAME | The window has a border of a style typically used with dialog boxes. A window with this style cannot have a title bar. |
| WS_GROUP | The window is the first control of a group of controls. The group consists of this first control and all controls defined after it, up to the next control with the WS_GROUP style. The first control in each group usually has the WS_TABSTOP style so that the user can move from group to group. The user can subsequently change the keyboard focus from one control in the group to the next control in the group by using the direction keys. |
| WS_GROUP | The window is the first control of a group of controls. The group consists of this first control and all controls defined after it, up to the next control with the WS_GROUP style. The first control in each group usually has the WS_TABSTOP style so that the user can move from group to group. The user can subsequently change the keyboard focus from one control in the group to the next control in the group by using the direction keys.<br>You can turn this style on and off to change dialog box navigation. To change this style after a window has been created, use the **SetWindowLongPtrW** function. |
| WS_HSCROLL | The window has a horizontal scroll bar. |
| WS_ICONIC | The window is initially minimized. Same as the WS_MINIMIZE style. |
| WS_MAXIMIZE | The window is initially maximized. |
| WS_MAXIMIZEBOX | The window has a maximize button. Cannot be combined with the WS_EX_CONTEXTHELP style. The WS_SYSMENU style must also be specified. |
| WS_MINIMIZE | The window is initially minimized. Same as the WS_ICONIC style. |
| WS_MINIMIZEBOX | The window has a minimize button. Cannot be combined with the WS_EX_CONTEXTHELP style. The WS_SYSMENU style must also be specified. |
| WS_OVERLAPPED | The window is an overlapped window. An overlapped window has a title bar and a border. Same as the WS_TILED style. |
| WS_OVERLAPPEDWINDOW | (WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX). The window is an overlapped window. Same as the WS_TILEDWINDOW style. |
| WS_POPUP | The windows is a pop-up window. This style cannot be used with the WS_CHILD style. |
| WS_POPUPWINDOW | (WS_POPUP OR WS_BORDER OR WS_SYSMENU). The window is a pop-up window. The WS_CAPTION and WS_POPUPWINDOW styles must be combined to make the window menu visible. |
| WS_SIZEBOX | The window has a sizing border. Same as the WS_THICKFRAME style. |
| WS_SYSMENU | The window has a window menu on its title bar. The WS_CAPTION style must also be specified. |
| WS_TABSTOP | The window is a control that can receive the keyboard focus when the user presses the TAB key. Pressing the TAB key changes the keyboard focus to the next control with the WS_TABSTOP style.<br>You can turn this style on and off to change dialog box navigation. To change this style after a window has been created, use the **SetWindowLongPtrW** function. For user-created windows and modeless dialogs to work with tab stops, alter the message loop to call the **IsDialogMessage** function. |
| WS_THICKFRAME | The window has a sizing border. Same as the WS_SIZEBOX style. |
| WS_TILED | The window is an overlapped window. An overlapped window has a title bar and a border. Same as the WS_OVERLAPPED style. |
| WS_TILEDWINDOW | (WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX). The window is an overlapped window. Same as the WS_OVERLAPPEDWINDOW style.  |
| WS_VISIBLE | The window is initially visible. This style can be turned on and off by using the **ShowWindow** or **SetWindowPos** function. |
| WS_VSCROLL | The window has a vertical scroll bar. |

#### Extended Window Styles

| Constant   | Description |
| ---------- | ----------- |
| WS_EX_ACCEPTFILES | The window accepts drag-drop files. |
| WS_EX_APPWINDOW | Forces a top-level window onto the taskbar when the window is visible. |
| WS_EX_CLIENTEDGE | The window has a border with a sunken edge. |
| WS_EX_COMPOSITED | Paints all descendants of a window in bottom-to-top painting order using double-buffering. This cannot be used if the window has a class style of either CS_OWNDC or CS_CLASSDC. |
| WS_EX_CONTEXTHELP | The title bar of the window includes a question mark. When the user clicks the question mark, the cursor changes to a question mark with a pointer. If the user then clicks a child window, the child receives a WM_HELP message. The child window should pass the message to the parent window procedure, which should call the WinHelp function using the HELP_WM_HELP command. The Help application displays a pop-up window that typically contains help for the child window. WS_EX_CONTEXTHELP cannot be used with the WS_MAXIMIZEBOX or WS_MINIMIZEBOX styles. |
| WS_EX_CONTROLPARENT | The window itself contains child windows that should take part in dialog box navigation. If this style is specified, the dialog manager recurses into children of this window when performing navigation operations such as handling the TAB key, an arrow key, or a keyboard mnemonic. |
| WS_EX_DLGMODALFRAME | The window has a double border; the window can, optionally, be created with a title bar by specifying the WS_CAPTION style in the *dwStyle* parameter. |
| WS_EX_LAYERED | The window is a layered window. Note that this cannot be used for child windows. Also, this cannot be used if the window has a class style of either CS_OWNDC or CS_CLASSDC. |
| WS_EX_LAYOUTRTL | If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the horizontal origin of the window is on the right edge. Increasing horizontal values advance to the left. |
| WS_EX_LEFT | The window has generic left-aligned properties. This is the default. |
| WS_EX_LEFTSCROLLBAR | If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the vertical scroll bar (if present) is to the left of the client area. For other languages, the style is ignored. |
| WS_EX_LTRREADING | The window text is displayed using left-to-right reading-order properties. This is the default. |
| WS_EX_MDICHILD | The window is a MDI child window. |
| WS_EX_NOACTIVATE | A top-level window created with this style does not become the foreground window when the user clicks it. The system does not bring this window to the foreground when the user minimizes or closes the foreground window. To activate the window, use the **SetActiveWindow** or **SetForegroundWindow** function. The window does not appear on the taskbar by default. To force the window to appear on the taskbar, use the WS_EX_APPWINDOW style. |
| WS_EX_NOINHERITLAYOUT | The window does not pass its window layout to its child windows. |
| WS_EX_NOPARENTNOTIFY | The child window created with this style does not send the WM_PARENTNOTIFY message to its parent window when it is created or destroyed. |
| WS_EX_OVERLAPPEDWINDOW | (WS_EX_WINDOWEDGE OR WS_EX_CLIENTEDGE). The window is an overlapped window. |
| WS_EX_PALETTEWINDOW | (WS_EX_WINDOWEDGE OR WS_EX_TOOLWINDOW OR WS_EX_TOPMOST). The window is palette window, which is a modeless dialog box that presents an array of commands. |
| WS_EX_RIGHT | The window has generic "right-aligned" properties. This depends on the window class. This style has an effect only if the shell language is Hebrew, Arabic, or another language that supports reading-order alignment; otherwise, the style is ignored. Using the WS_EX_RIGHT style for static or edit controls has the same effect as using the SS_RIGHT or ES_RIGHT style, respectively. Using this style with button controls has the same effect as using BS_RIGHT and BS_RIGHTBUTTON styles. |
| WS_EX_RIGHTSCROLLBAR | The vertical scroll bar (if present) is to the right of the client area. This is the default. |
| WS_EX_RTLREADING | If the shell language is Hebrew, Arabic, or another language that supports reading-order alignment, the window text is displayed using right-to-left reading-order properties. For other languages, the style is ignored. |
| WS_EX_STATICEDGE | The window has a three-dimensional border style intended to be used for items that do not accept user input. |
| WS_EX_TOOLWINDOW | The window is intended to be used as a floating toolbar. A tool window has a title bar that is shorter than a normal title bar, and the window title is drawn using a smaller font. A tool window does not appear in the taskbar or in the dialog that appears when the user presses ALT+TAB. If a tool window has a system menu, its icon is not displayed on the title bar. However, you can display the system menu by right-clicking or by typing ALT+SPACE. |
| WS_EX_TOPMOST | The window should be placed above all non-topmost windows and should stay above them, even when the window is deactivated. To add or remove this style, use the **SetWindowPos** function. |
| WS_EX_TRANSPARENT | The window should not be painted until siblings beneath the window (that were created by the same thread) have been painted. The window appears transparent because the bits of underlying sibling windows have already been painted. To achieve transparency without these restrictions, use the **SetWindowRgn** function. |
| WS_EX_WINDOWEDGE | The window has a border with a raised edge. |

#### Usage examples

```
DIM hwndMain AS HWND = pWindow.Create
```
```
DIM hwndMain AS HWND = pWindow.Create(NULL, "CWindow Test", @WndProc)
```
```
DIM hwndMain AS HWND = pWindow.Create(NULL, "CWindow Test", @WndProc), 0, 0, 525, 395)
```
```
DIM hwndMain AS HWND = pWindow.Create(NULL, "CWindow Test", @WndProc, 0, 0, 525, 395, _
   WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS, WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE)
```
---

## CreateAcceleratorTable

Creates the accelerator table.

```
FUNCTION CreateAcceleratorTable () AS HACCEL
```

#### Return value

The handle of the new accelerator table.

#### Example

```
' // Create a keyboard accelerator table
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "U", IDM_UNDO ' // Ctrl+U - Undo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "R", IDM_REDO ' // Ctrl+R - Redo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "H", IDM_HOME ' // Ctrl+H - Home
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "S", IDM_SAVE ' // Ctrl+S - Save
DIM hAccel AS HACCEL = pWindow.CreateAcceleratorTable
```
---

## CreateFont

Creates a DPI aware logical font.

```
FUNCTION CreateFont (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, _
   BYVAL lWeight AS LONG = FW_NORMAL, BYVAL bItalic AS UBYTE = FALSE, _
   BYVAL bUnderline AS UBYTE = FALSE, BYVAL bStrikeOut AS UBYTE = FALSE, _
   BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS HFONT
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFaceName* | A string that specifies the typeface name of the font. The length of this string must not exceed 31 characters. The **EnumFontFamilies** function can be used to enumerate the typeface names of all currently available fonts. If *wszFaceName* is an empty string, GDI uses the first font that matches the other specified attributes. |
| *lPointSize* | Specifies the height, in logical units, of the font's character cell or character. |
| *lWeight* | Specifies the weight of the font in the range 0 through 1000. If this value is zero, a default weight is used. |
| *bItalic* | Specifies an italic font if set to CTRUE. |
| *bUnderline* | Specifies an underlined font if set to CTRUE. |
| *bStrikeOut* | Specifies a strikeout font if set to CTRUE. |
| *bCharSet* | Specifies the character set. The following values are predefined:<br>ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET, DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET, MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET.<br>Korean Windows: JOHAB_CHARSET.<br>Middle-Eastern Windows: HEBREW_CHARSET, ARABIC_CHARSET.<br>Thai Windows: THAI_CHARSET.<br>The OEM_CHARSET value specifies a character set that is operating-system dependent. DEFAULT_CHARSET is set to a value based on the current system locale. For example, when the system locale is English (United States), it is set as ANSI_CHARSET. Fonts with other character sets may exist in the operating system. If an application uses a font with an unknown character set, it should not attempt to translate or interpret strings that are rendered with that font. This parameter is important in the font mapping process. To ensure consistent results, specify a specific character set. If you specify a typeface name in the *wszFaceName* parameter, make sure that the *bCharSet* value matches the character set of the typeface specified in *wszFaceName*. |

#### Return value

A handle to a logical font indicates success. NULL indicates failure. To get extended error information, call **GetLastError**.

#### Examples

```
hFont = CWindow.CreateFont("MS Sans Serif", 8, FW_NORMAL, , , , DEFAULT_CHARSET)
hFont = CWindow.CreateFont("Courier New", 10, FW_BOLD, , , , DEFAULT_CHARSET)
hFont = CWindow.CreateFont("Marlett", 8, FW_NORMAL, , , , SYMBOL_CHARSET)
```
---

## DefaultFontSize

Gets/sets the point size of the default font.

```
PROPERTY DefaultFontSize () AS LONG
PROPERTY DefaultFontSize (BYVAL nPointSize AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nPointSize* | The point size of the font |

#### Return value

The point size of the font.

#### Usage examples

```
DIM nSize AS LONG = pWindow.DefaultFontSize
```
```
pWindow.DefaultFontSize = 12
```
---

## DoEvents

Processes windows messages.

```
FUNCTION DoEvents (BYVAL nCmdShow AS LONG = 0) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nCmdShow* | Optional. Specifies how the window is to be shown. If **DoEvents** is called in the main window, the value should be the value obtained by the wWinMain function in its *nCmdShow* parameter. |

#### Return value

The application exit code. This is the value sent when calling the **PostQuitMessage** API function.

#### Remarks

This is the default message pump and should be enough for most applications, but you can replace it with your own.

#### Usage example

```
FUNCTION = pWindow.DoEvents(nCmdShow)
```
---

## DPI

Gets/sets the **DPI** (dots per inch) to be used by the application. The main window, controls and fonts will be scaled according this value. Don't change the DPI value once the main window has been created.

By default, **CWindow** retrieves the **DPI** setting used by the computer and calculates the scaling ratios, but you can use this property to alter this behavior. For example, passing a DPI of 96 disables scaling; any other value, changes the scaling ratios.

```
PROPERTY DPI () AS SINGLE
PROPERTY DPI (BYVAL nDPI AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDPI* | The number of dots per inch. Pass -1 to use the value returned by the **GetDeviceCaps** API function. |

#### Remarks

To make the application DPI aware with Windows 10 or superior it's needed a call to the API function **SetProcessDpiAwareness** or set it through the application manifest.

DLLs should accept the dpi setting of the host process rather than call **SetProcessDpiAwareness** themselves. To be set properly, *dpiAware* should be specified as part of the application (.exe) manifest. (*dpiAware* defined in an embedded DLL manifest has no affect.) The following markup shows how to set *dpiAware* as part of an application (.exe) manifest.

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

#### Usage examples

```
DIM dpi AS LONG = pWindow.DPI
```
```
pWindow.DPI = 96
```
---

## Font

Gets/sets the font used as default.

```
PROPERTY Font () AS HFONT
PROPERTY Font (BYVAL hFont AS HFONT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hFont* | A handle to the font. |

#### Usage examples

```
DIM hFont AS HFONT = pWindow.Font
```
```
pWindow.Font = hFont
```
The Set property can only be used before calling the **Create** method. If the windows has already been created, calling this property is ignored.

---

## GetClientRect

Retrieves the unscaled coordinates of the main window client area. The client coordinates specify the upper-left and lower-right corners of the client area. Because client coordinates are relative to the upper-left corner of a window's client area, the coordinates of the upper-left corner are (0,0). 

```
SUB GetClientRect (BYVAL lpRect AS LPRECT)
FUNCTION GetClientRect () AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpRect* | Pointer to a **RECT** structure that receives the client coordinates. The left and top members are zero. The right and bottom members contain the width and height of the window. |

#### Remarks

In conformance with conventions for the **RECT** structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (right, bottom) lies immediately outside the rectangle.

#### Usage examples

```
DIM rc AS RECT
pWindow.GetClientRect(@rc)
```
```
DIM rc AS RECT = pWindow.GetClientRect
```
---

## GetControlClientRect

Retrieves the unscaled coordinates of a window's client area. The client coordinates specify the upper-left and lower-right corners of the client area. Because client coordinates are relative to the upper-left corner of a window's client area, the coordinates of the upper-left corner are (0,0). 

```
SUB GetControlClientRect (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
```
```
FUNCTION GetControlClientRect (BYVAL hwnd AS HWND) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *lpRect* | Pointer to a **RECT** structure that receives the client coordinates. The left and top members are zero. The right and bottom members contain the width and height of the window.  |

#### Remarks

In conformance with conventions for the **RECT** structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (right, bottom) lies immediately outside the rectangle.

#### Usage examples

```
DIM rc AS RECT
pWindow.GetControlClientRect(hCtl, @rc)
```
```
DIM rc AS RECT = pWindow.GetControlClientRect(hCtl)
```
---

## GetControlWindowRect

Retrieves the unscaled dimensions of the bounding rectangle of the specified window. The dimensions are given in screen coordinates that are relative to the upper-left corner of the screen.

```
SUB GetControlWindowRect (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
```
```
FUNCTION GetControlWindowRect (BYVAL hwnd AS HWND) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *lpRect* | Pointer to a **RECT** structure that receives the client coordinates. The left and top members are zero. The right and bottom members contain the width and height of the window.  |

#### Remarks

In conformance with conventions for the **RECT** structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (right, bottom) lies immediately outside the rectangle.

#### Usage examples

```
DIM rc AS RECT
pWindow.GetControlWindowRect(hCtl, @rc)
```
```
DIM rc AS RECT = pWindow.GetControlWindowRect(hCtl)
```
---

## GetWindowRect

Retrieves the unscaled dimensions of the bounding rectangle of the main window. The dimensions are given in screen coordinates that are relative to the upper-left corner of the screen.

```
SUB GetWindowRect (BYVAL hwnd AS HWND, BYVAL lpRect AS LPRECT)
```
```
FUNCTION GetWindowRect (BYVAL hwnd AS HWND) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *lpRect* | Pointer to a **RECT** structure that receives the client coordinates. The left and top members are zero. The right and bottom members contain the width and height of the window.  |

#### Remarks

In conformance with conventions for the **RECT** structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (right, bottom) lies immediately outside the rectangle.

#### Usage examples

```
DIM rc AS RECT
pWindow.GetWindowRect(@rc)
```
```
DIM rc AS RECT = pWindow.GetWindowRect
```
---

## GetWorkArea

Retrieves the unscaled size of the work area on the primary display monitor. The work area is the portion of the screen not obscured by the system taskbar or by application desktop toolbars.

```
SUB GetWorkArea (BYVAL lpRect AS LPRECT)
```
```
FUNCTION GetWorkArea () AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or control. |
| *lpRect* | Pointer to a **RECT** structure that receives the client coordinates. The left and top members are zero. The right and bottom members contain the width and height of the window.  |

#### Remarks

In conformance with conventions for the **RECT** structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (right, bottom) lies immediately outside the rectangle.

#### Usage examples

```
DIM rc AS RECT
pWindow.GetWorkArea(@rc)
```
```
DIM rc AS RECT = pWindow.GetWorkArea
```
---

## Height

Returns the unscaled height of the main window.

```
PROPERTY Height () AS LONG
```

#### Usage example

```
DIM nHeight AS LONG = pWindow.Height
```
---

## Width

Returns the unscaled width of the main window.

```
PROPERTY Width () AS LONG
```

#### Usage example

```
DIM nWidth AS LONG = pWindow.Width
```
---

## ScreenX

Returns the unscaled x-coordinate of the window relative to the screen.

```
PROPERTY ScreenX () AS LONG
```

#### Usage example

```
DIM nLeft AS LONG = pWindow.ScreenX
```
---

## ScreenY

Returns the unscaled y-coordinate of the window relative to the screen.

```
PROPERTY ScreenY () AS LONG
```

#### Usage example

```
DIM nTop AS LONG = pWindow.ScreenY
```
---

## hWindow

Gets/sets the main window handle.

```
PROPERTY hWindow () AS HWND
PROPERTY hWindow (BYVAL hwnd AS HWND)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |

#### Return value

The window handle.

#### Usage examples

```
DIM hwnd AS HWND = pWindow.hWindow
```
```
pWindow.hWindow = hwnd
```
---

## InstanceHandle

Gets/sets the instance handle.

```
PROPERTY InstanceHandle () AS HINSTANCE
PROPERTY InstanceHandle (BYVAL hInst AS HINSTANCE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInst* | The instance handle. |

#### Return value

The instance handle.

#### Usage example

```
DIM hInstance = pWindow.InstanceHandle
```
```
pWindow.InstanceHandle = pInstance
```
---

## IsNonStable

Returns true if the `CWindow` is non stable; otherwise, false.

```
FUNCTION IsNonStable () AS BOOLEAN
```
---

## IsStabilized

Returns true if the `CWindow` is stabilized; otherwise, false.

```
FUNCTION IsStabilized () AS BOOLEAN
```
---

## IsWindowScrollable

Returns true if the `CWindow` is scrollable; otherwise, false.

```
FUNCTION IsWindowScrollable () AS BOOLEAN
```
---

## MoveWindow

Changes the position and dimensions of the specified window. For a top-level window, the position and dimensions are relative to the upper-left corner of the screen. For a child window, they are relative to the upper-left corner of the parent window's client area. This method scales the window by multiplying the size and coordinates according the DPI setting; therefore, you must pass unscaled values to it.

```
FUNCTION MoveWindow (BYVAL hwnd AS HWND, BYVAL x AS LONG, BYVAL y AS LONG, _
   BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS WINBOOL) AS WINBOOL
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *x* | The new position of the left side of the window. |
| *y* | The new position of the top of the window. |
| *nWidth* | The new width of the window. |
| *nHeight* | The new height of the window. |
| *bRepaint* | Indicates whether the window is to be repainted. If this parameter is CTRUE, the window receives a message. If the parameter is FALSE, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of moving a child window. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

#### Remarks

If the *bRepaint* parameter is CTRUE, the system sends the WM_PAINT message to the window procedure immediately after moving the window (that is, the **MoveWindow** method calls the UpdateWindow function). If *bRepaint* is FALSE, the application must explicitly invalidate or redraw any parts of the window and parent window that need redrawing.

**MoveWindow** sends the WM_WINDOWPOSCHANGING, WM_WINDOWPOSCHANGED, WM_MOVE, WM_SIZE, and WM_NCCALCSIZE messages to the window.

#### Usage example

```
pWindow.MoveWindow GetDlgItem(hwnd, IDCANCEL), pWindow.ClientWidth, _
   pWindow-ClientHeight, 75, 23, CTRUE
```
---

## NonStable

Makes a `CWindow` non stable (closeable).

```
FUNCTION NonStable () AS BOOLEAN
```
#### Return value

If the function succeeds, the function returns true; otherwise, false.

#### Remarks

The window is made non-stable, meaning that it can be closed by the user. If there is a system menu, the close option and the close box are enabled. The ALT-F4 close key is also enabled. This is the default mode of operation.

---

## Resize

Resizes the window sending a WM_SIZE message with the  SIZE_RESTORED value.

```
SUB Resize
```

#### Usage example

```
pWindow.Resize
```
---

## rxRatio

Returns the horizontal scaling ratio.

```
PROPERTY rxRatio () AS SINGLE
```

#### Usage example

```
DIM rx AS LONG = pWindow.rxRatio
```
---

## ryRatio

Returns the vertical scaling ratio.

```
PROPERTY ryRatio () AS SINGLE
```

#### Usage example

```
DIM ry AS LONG = pWindow.ryRatio
```
---

## ScaleX

Scales an horizontal coordinate according the DPI setting.

```
PROPERTY ScaleX (BYVAL cx AS SINGLE) AS SINGLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cx* | The value of the horizontal coordinate, in pixels. |

#### Usage example

```
pWindow.ScaleX(cx)
```
#### Remarks

A SINGLE datatype is used instead of a long to avoid rounding errors in the calculation.

---

## ScaleY

Scales an vertical coordinate according the DPI setting.

```
PROPERTY ScaleY (BYVAL cy AS SINGLE) AS SINGLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cy* | The value of the vertical coordinate, in pixels. |

#### Usage example

```
pWindow.ScaleY(cy)
```

#### Remarks

A SINGLE datatype is used instead of a long to avoid rounding errors in the calculation.

---

## SetBackColor

Sets the background color of a `CWindow`.

```
FUNCTION SetBackColor (BYVAL backColor AS COLORREF) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *backColor* | An RGB color value. |

---

## SetClientSize

Adjusts the bounding rectangle of the window based on the desired size of the client area. The sizes are scaled according the DPI seeting.

```
SUB SetClientSize (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | The new width of the client area of the window. |
| *nHeight* | The new height of the client area of the window. |

#### Usage example

```
pWindow.SetClientSize(400, 250)
```
---

## SetControlSubclass

Installs or updates a control subclass callback.

```
FUNCTION SetControlSubclass (BYVAL hCtl AS HWND, BYVAL pfnSubclass AS ANY PTR, _
   BYVAL uIdSubclass AS UINT_PTR, BYVAL dwRefData AS ANY PTR) AS BOOLEAN
FUNCTION SetControlSubclass (BYVAL hCtl AS HWND, BYVAL pfnSubclass AS ANY PTR, _
   BYVAL uIdSubclass AS UINT_PTR, BYVAL dwRefData AS DWORD_PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the control being subclassed. |
| *pfnSubclass* | A pointer to a window procedure. This pointer and the subclass ID uniquely identify this subclass callback. |
| *uIdSubclass* | The subclass ID. This ID together with the subclass procedure uniquely identify a subclass. To remove a subclass, pass the subclass procedure and this value to the **RemoveWindowSubclass** function. This value is passed to the subclass procedure in the *uIdSubclass* parameter. |
| *dwRefData* | DWORD_PTR to reference data. The meaning of this value is determined by the calling application. This value is passed to the subclass procedure in the *dwRefData* parameter. A different *dwRefData* is associated with each combination of window handle, subclass procedure and *uIdSubclass*. |

#### Return value

TRUE if the subclass callback was successfully installed; otherwise, FALSE.

#### Remarks

Subclass callbacks are identified by the combination of the callback address and the caller-defined subclass ID. If the callback address and ID pair have not yet been installed, then this function installs the subclass. If the pair has already been installed, then this function just updates the reference data.

Each callback can store a single DWORD_PTR of reference data, which is passed to the callback function when it is called to filter messages. No reference counting is performed for the callback; it may repeatedly call **SetControlSubclass** to alter the value of its reference data element.

**Warning**: You cannot use the subclassing helper functions to subclass a window across threads.

---

## SetControlCallback

Optional address of a callback function that receives all **WM_COMMAND** and **WM_NOTIFY** messages for the control.

```
FUNCTION SetControlCallback (BYVAL hCtl AS HWND, BYVAL pCallback AS ANY PTR) AS BOOLEAN
FUNCTION SetControlCallback (BYVAL cID AS LONG, BYVAL pCallback AS ANY PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the control. |
| *pCallback* | A pointer to a window procedure. You can use **PROCPTR** to get the pointer, e.g. PROCPTR (MyCallbackProc). |

#### Return value

TRUE if the subclass callback was successfully installed; otherwise, FALSE.

---

## SetCtlColors

Sets the colors of a and edit, listbox or static control.

```
FUNCTION SetCtlColors (BYVAL hCtl AS HWND, BYVAL foreColor AS COLORREF, _
   BYVAL backColor AS COLORREF) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the control. |
| *foreColor* | The foreground color of the control. |
| *backColor* | The background color of the control. |

---

## GetBackColor

Gets the background color of a `CWindow`or control.

```
FUNCTION GetBackColor (BYVAL hCtl AS HWND) AS COLORREF
```
| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the `CWindow`or control. |

---

## GetForeColor

Gets the foreground color of a control.

```
FUNCTION GetForeColor (BYVAL hCtl AS HWND) AS COLORREF
```
| Parameter  | Description |
| ---------- | ----------- |
| *hCtl* | The handle of the control. |

---

## SetFont

Creates a DPI aware logical font and sets it as the default font.

```
FUNCTION SetFont (BYREF wszFaceName AS WSTRING, BYVAL lPointSize AS LONG, _
   BYVAL lWeight AS LONG = FW_NORMAL, BYVAL bItalic AS UBYTE = FALSE, _
   BYVAL bUnderline AS UBYTE = FALSE, BYVAL bStrikeOut AS UBYTE = FALSE, _
   BYVAL bCharSet AS UBYTE = DEFAULT_CHARSET) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFaceName* | A string that specifies the typeface name of the font. The length of this string must not exceed 31 characters. The **EnumFontFamilies** function can be used to enumerate the typeface names of all currently available fonts. If *wszFaceName* is an empty string, GDI uses the first font that matches the other specified attributes. |
| *lPointSize* | Specifies the height, in logical units, of the font's character cell or character. |
| *lWeight* | Specifies the weight of the font in the range 0 through 1000. If this value is zero, a default weight is used. |
| *bItalic* | Specifies an italic font if set to CTRUE. |
| *bUnderline* | Specifies an underlined font if set to CTRUE. |
| *bStrikeOut* | Specifies a strikeout font if set to CTRUE. |
| *bCharSet* | Specifies the character set. The following values are predefined:<br>ANSI_CHARSET, BALTIC_CHARSET, CHINESEBIG5_CHARSET, DEFAULT_CHARSET, EASTEUROPE_CHARSET, GB2312_CHARSET, GREEK_CHARSET, HANGUL_CHARSET, MAC_CHARSET, OEM_CHARSET, RUSSIAN_CHARSET, SHIFTJIS_CHARSET, SYMBOL_CHARSET, TURKISH_CHARSET.<br>Korean Windows: JOHAB_CHARSET.<br>Middle-Eastern Windows: HEBREW_CHARSET, ARABIC_CHARSET.<br>Thai Windows: THAI_CHARSET.<br>The OEM_CHARSET value specifies a character set that is operating-system dependent. DEFAULT_CHARSET is set to a value based on the current system locale. For example, when the system locale is English (United States), it is set as ANSI_CHARSET. Fonts with other character sets may exist in the operating system. If an application uses a font with an unknown character set, it should not attempt to translate or interpret strings that are rendered with that font. This parameter is important in the font mapping process. To ensure consistent results, specify a specific character set. If you specify a typeface name in the *wszFaceName* parameter, make sure that the *bCharSet* value matches the character set of the typeface specified in *wszFaceName*. |

#### Return value

CTRUE or FALSE.

#### Usage examples

```
pWindow.SetFont("MS Sans Serif", 8, FW_NORMAL, , , , DEFAULT_CHARSET)
pWindow.SetFont("Courier New", 10, FW_BOLD, , , , DEFAULT_CHARSET)
pWindow.SetFont("Marlett", 8, FW_NORMAL, , , , SYMBOL_CHARSET)
```
---

## SetViewPort

Makes a `CWindow` scrollable by shrinking its client area size.

```
FUNCTION SetViewPort (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | The new width of the client area of the control. |
| *nHeight* | The new height of the client area of the control. |

---

## SetWindowPos

Changes the size, position, and Z order of a child, pop-up, or top-level window. These windows are ordered according to their appearance on the screen. The topmost window receives the highest rank and is the first window in the Z order. The sizes and coordinates are scaled according the DPI setting.

```
FUNCTION SetWindowPos (BYVAL hwnd AS HWND, BYVAL hwndInsertAfter AS HWND, _
   BYVAL x AS LONG, BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, _
   BYVAL uFlags AS UINT) AS WINBOOL
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window. |
| *hwndInsertAfter* | A handle to the window to precede the positioned window in the Z order. This parameter must be a window handle or one of the following values.<br>**HWND_BOTTOM**: Places the window at the bottom of the Z order. If the *hWnd* parameter identifies a topmost window, the window loses its topmost status and is placed at the bottom of all other windows.<br>**HWND_NOTOPMOST**: Places the window above all non-topmost windows (that is, behind all topmost windows). This flag has no effect if the window is already a non-topmost window.<br>**HWND_TOP**: Places the window at the top of the Z order.<br>**HWND_TOPMOST**: Places the window above all non-topmost windows. The window maintains its topmost position even when it is deactivated.<br>For more information about how this parameter is used, see the **Remarks** section. |
| *x* | The new position of the left side of the window, in client coordinates. |
| *y* | The new position of the top of the window, in client coordinates. |
| *cx* | The new width of the window, in pixels. |
| *cy* | The new height of the window, in pixels. |
| *uFlags* | The window sizing and positioning flags. This parameter can be a combination of the following values. |

| Value      | Meaning     |
| ---------- | ----------- |
| SWP_ASYNCWINDOWPOS | If the calling thread and the thread that owns the window are attached to different input queues, the system posts the request to the thread that owns the window. This prevents the calling thread from blocking its execution while other threads process the request.  |
| SWP_DEFERERASE | Prevents generation of the **WM_SYNCPAINT** message. |
| SWP_DRAWFRAME | Draws a frame (defined in the window's class description) around the window. |
| SWP_FRAMECHANGED | Applies new frame styles set using the **SetWindowLongPtrW** function. Sends a **WM_NCCALCSIZE** message to the window, even if the window's size is not being changed. If this flag is not specified, **WM_NCCALCSIZE** is sent only when the window's size is being changed. |
| SWP_HIDEWINDOW | Hides the window. |
| SWP_NOACTIVATE | Does not activate the window. If this flag is not set, the window is activated and moved to the top of either the topmost or non-topmost group (depending on the setting of the *hWndInsertAfter* parameter). |
| SWP_NOCOPYBITS | Discards the entire contents of the client area. If this flag is not specified, the valid contents of the client area are saved and copied back into the client area after the window is sized or repositioned. |
| SWP_NOMOVE | Retains the current position (ignores X and Y parameters). |
| SWP_NOOWNERZORDER | Does not change the owner window's position in the Z order. |
| SWP_NOREDRAW | Does not redraw changes. If this flag is set, no repainting of any kind occurs. This applies to the client area, the nonclient area (including the title bar and scroll bars), and any part of the parent window uncovered as a result of the window being moved. When this flag is set, the application must explicitly invalidate or redraw any parts of the window and parent window that need redrawing. |
| SWP_NOREPOSITION | Same as the SWP_NOOWNERZORDER flag. |
| SWP_NOSENDCHANGING | Prevents the window from receiving the **WM_WINDOWPOSCHANGING** message. |
| SWP_NOSIZE | Retains the current size (ignores the *cx* and *cy* parameters). |
| SWP_NOZORDER | Retains the current Z order (ignores the *hWndInsertAfter* parameter). |
| SWP_SHOWWINDOW | Displays the window. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

#### Remarks

As part of the Vista re-architecture, all services were moved off the interactive desktop into Session 0. *hwnd* and window manager operations are only effective inside a session and cross-session attempts to manipulate the hwnd will fail.

If you have changed certain window data using **SetWindowLongPtrW**, you must call **SetWindowPos** for the changes to take effect. Use the following combination for uFlags: SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER OR SWP_FRAMECHANGED.

A window can be made a topmost window either by setting the *hwndInsertAfter* parameter to HWND_TOPMOST and ensuring that the SWP_NOZORDER flag is not set, or by setting a window's position in the Z order so that it is above any existing topmost windows. When a non-topmost window is made topmost, its owned windows are also made topmost. Its owners, however, are not changed.

If neither the SWP_NOACTIVATE nor SWP_NOZORDER flag is specified (that is, when the application requests that a window be simultaneously activated and its position in the Z order changed), the value specified in *hwndInsertAfter* is used only in the following circumstances.

* Neither the HWND_TOPMOST nor HWND_NOTOPMOST flag is specified in *hwndInsertAfter*.
* The window identified by *hwnd* is not the active window.

An application cannot activate an inactive window without also bringing it to the top of the Z order. Applications can change an activated window's position in the Z order without restrictions, or it can activate a window and then move it to the top of the topmost or non-topmost windows.

If a topmost window is repositioned to the bottom (HWND_BOTTOM) of the Z order or after any non-topmost window, it is no longer topmost. When a topmost window is made non-topmost, its owners and its owned windows are also made non-topmost windows.

A non-topmost window can own a topmost window, but the reverse cannot occur. Any window (for example, a dialog box) owned by a topmost window is itself made a topmost window, to ensure that all owned windows stay above their owner.

If an application is not in the foreground, and should be in the foreground, it must call the **SetForegroundWindow** function.

To use **SetWindowPos** to bring a window to the top, the process that owns the window must have **SetForegroundWindow** permission.

#### Usage example

```
SetWindowPos(hwnd, NULL, 0, 0, cx, cy, _
   SWP_NOZORDER OR SWP_NOMOVE OR SWP_NOACTIVATE)
```
---

## Stabilize

Makes the`CWindow` stabilized (non-closeable by the user).

```
FUNCTION Stabilize () AS BOOLEAN
```
#### Return value

If the function succeeds, the function returns true; otherwise, false.

#### Remarks

If there is a system menu, the close option and the close box are grayed. The ALT-F4 close key is disabled.  This allows you to be certain that your operations on can be completed. When a `CWindow` is stabilized, only program termination will close it.

---

## UnScaleX

Unscales an horizontal coordinate according the DPI setting.

```
PROPERTY UnScaleX (BYVAL cx AS SINGLE) AS SINGLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *cx* | The value of the horizontal coordinate, in pixels. |

#### Remarks

A SINGLE datatype is used instead of a long to avoid rounding errors in the calculation.

#### Usage example

DIM cx AS SINGLE = pWindow.UnScaleX(250)

---

## UnScaleY

Unscales a vertical coordinate according the DPI setting.

```
PROPERTY UnScaleY (BYVAL cy AS SINGLE) AS SINGLE
```

| Parameter   | Description |
| ---------- | ----------- |
| *cy* | The value of the vertical coordinate, in pixels. |

#### Remarks

A SINGLE datatype is used instead of a long to avoid rounding errors in the calculation.

#### Usage example

DIM cy AS SINGLE = pWindow.UnScaleY(250)

---

## UserData

Gets/sets a value in the user data area of the window.

```
PROPERTY UserData (BYVAL idx AS LONG) AS LONG_PTR
PROPERTY UserData (BYVAL idx AS LONG, BYVAL newValue AS LONG_PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The index number of the user data value to retrieve, in the range 0 to 99 inclusive. |
| *newValue* | The value to set. |

#### Usage examples

```
pWindow.UserData(1) = value
```
```
DIM value AS LONG_PTR = pWindow.UserData(1)
```
---

## WindowExStyle

Gets/sets the window extended styles. Alias: **WindowStyleEx**.

```
PROPERTY WindowExStyle () AS LONG_PTR
PROPERTY WindowExStyle (BYVAL dwExStyle AS LONG_PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwExStyle* | The extended style(s) to set. |

#### Return value

The extended style(s) used by the window.

#### Usage examples

```
DIM dwExStyle AS ULONG_PTR = pWindow.WindowExStyle
```
```
pWindow.WindowExStyle = WS_EX_CLIENTEDGE
```
---

## WindowStyle

Gets/sets the window styles.

```
PROPERTY WindowStyle () AS LONG_PTR
PROPERTY WindowStyle (BYVAL dwStyle AS LONG_PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwStyle* | The style(s) to set. |

#### Return value

The style(s) used by the window.

#### Usage examples

```
DIM dwStyle AS LONG_PTR = pWindow.WindowStyle
```
```
pWindow.WindowStyle = WS_POPUPWINDOW OR WS_CAPTION   ' // Creates a popup window
```
---

## AfxCWindowPtr

Returns a pointer to the **CWindow** class given the handle of the main window or the **CREATESTRUCT** structure associated with it. To retrieve it from the handle of any of its child windows or controls, use **AfxCWindowOwnerPtr**.

```
FUNCTION AfxCWindowPtr (BYVAL hwnd AS HWND) AS CWindow PTR
FUNCTION AfxCWindowPtr (BYVAL lParam AS LPARAM) AS CWindow PTR
FUNCTION AfxCWindowPtr (BYVAL pCreateStruct AS CREATESTRUCT PTR) AS CWindow PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle of the main window created with the **Create** method of the **CWindow** class. |
| *lParam* | Value passed by Windows to the **WM_CREATE** message. |
| *pCreateStruct* | Pointer to the **CREATESTRUCT** structure used by Windows during the window creation and passed to the window procedure as the *lParam* parameter of the **WM_CREATE** message. |

#### Return value

A pointer to the **CWindow** class or NULL.

#### Usage examples

```
DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
```
```
DIM pWindow AS CWindow PTR = AfxCWindowPtr(lParam)
```
---

## AfxCWindowOwnerPtr

Returns a pointer to the **CWindow** class given the handle of the window created with it or the handle of any of it's children windows or controls.

```
FUNCTION AfxCWindowOwnerPtr (BYVAL hwnd AS HWND) AS CWindow PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle of the window created with it or the handle of any of it's children windows or controls. |

#### Return value

A pointer to the **CWindow** class or NULL.

#### Usage example

```
DIM pWindow AS CWindow PTR = AfxCWindowOwnerPtr(hwnd)
```
---

## AfxInputBox

Input box dialog.

```
FUNCTION AfxInputBox (BYVAL hParent AS HWND = NULL, BYVAL x AS LONG = 0, _
   BYVAL y AS LONG = 0, BYREF dwsCaption AS DWSTRING = "", BYREF dwsPrompt AS DWSTRING = "", _
   BYREF dwsText AS DWSTRING = "", BYVAL nLen AS LONG = 260, _
   BYVAL bPassword AS BOOLEAN = FALSE) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hParent* | Optional. The handle of the parent main window. |
| *x, y* | Optional. The location of the dialog. If both are 0, the dialog is centered. |
| *dwsCaption* | Optional. The caption of the dialog. |
| *dwsPrompt* | Optional. The prompt displayed in the dialog. |
| *dwsText* | Optional. The text to edit. |
| *nLen* | Optional. Maximum length of the string to edit.<br>The default length is 260 characters.<br>The maximum length is 2048 characters. |
| *bPassword* | Optional. TRUE or FALSE. Displays all characters as an asterisk (\*) as they are typed into the edit control. |

#### Return value

The edited string.

#### Usage example

```
DIM dws AS DWSTRING = AfxInputBox(hwnd, 0, 0, "InputBox test", "What's your name?", "My name is José")
```
---
