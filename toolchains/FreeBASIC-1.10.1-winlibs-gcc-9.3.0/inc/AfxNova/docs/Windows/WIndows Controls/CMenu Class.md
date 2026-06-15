# About Menus

A menu is a list of items that specify options or groups of options (a submenu) for an application. Clicking a menu item opens a submenu or causes the application to carry out a command. 

#### Menu Bars and Menus

A menu is arranged in a hierarchy. At the top level of the hierarchy is the *menu bar*; which contains a list of *menus*, which in turn can contain submenus. A menu bar is sometimes called a *top-level menu*, and the menus and submenus are also known as *pop-up menus*.

A menu item can either carry out a command or open a submenu. An item that carries out a command is called a *command item* or a *command*.

An item on the menu bar almost always opens a menu. Menu bars rarely contain command items. A menu opened from the menu bar drops down from the menu bar and is sometimes called a *drop-down menu*. When a drop-down menu is displayed, it is attached to the menu bar. A menu item on the menu bar that opens a drop-down menu is also called a menu name.

The menu names on a menu bar represent the main categories of commands that an application provides. Selecting a menu name from the menu bar typically opens a menu whose menu items correspond to the commands in a category. For example, a menu bar might contain a File menu name that, when clicked by the user, activates a menu with menu items such as New, Open, and Save. To get information about a menu bar, call **CMenu.GetBarInfo**.

Only an overlapped or pop-up window can contain a menu bar; a child window cannot contain one. If the window has a title bar, the system positions the menu bar just below it. A menu bar is always visible. A submenu is not visible, however, until the user selects a menu item that activates it. For more information about overlapped and pop-up windows, see [Window Types](https://learn.microsoft.com/en-us/windows/win32/winmsg/window-features).

Each menu must have an owner window. The system sends messages to a menu's owner window when the user selects the menu or chooses an item from the menu.

#### Shortcut Menus

The system also provides shortcut menus. A shortcut menu is not attached to the menu bar; it can appear anywhere on the screen. An application typically associates a shortcut menu with a portion of a window, such as the client area, or with a specific object, such as an icon. For this reason, these menus are also called *context menus*.

A shortcut menu remains hidden until the user activates it, typically by right-clicking a selection, a toolbar, or a taskbar button. The menu is usually displayed at the position of the caret or mouse cursor.

#### The Window Menu

The **Window** menu (also known as the **System** menu or **Control** menu) is a pop-up menu defined and managed almost exclusively by the operating system. The user can open the window menu by clicking the application icon on the title bar or by right-clicking anywhere on the title bar.

The **Window** menu provides a standard set of menu items that the user can choose to change a window's size or position, or close the application. Items on the window menu can be added, deleted, and modified, but most applications just use the standard set of menu items. An overlapped, pop-up, or child window can have a window menu. It is uncommon for an overlapped or pop-up window not to include a window menu.

When the user chooses a command from the **Window menu**, the system sends a **WM_SYSCOMMAND** message to the menu's owner window. In most applications, the window procedure does not process messages from the window menu. Instead, it simply passes the messages to the **DefWindowProc** function for system-default processing of the message. If an application adds a command to the window menu, the window procedure must process the command.

An application can use the **CMenu.GetSystemMenuHandle** function to create a copy of the default window menu to modify. Any window that does not use the **CMenu.GetSystemMenuHandle** function to make its own copy of the window menu receives the standard window menu.

See more MSDN documentation at [About Menus](https://learn.microsoft.com/en-us/windows/win32/menurc/about-menus) and [Using Menus](https://learn.microsoft.com/en-us/windows/win32/menurc/using-menus)

---

## Methods

| Name       | Description |
| ---------- | ----------- |
| [AddBitmapToItem](#addbitmaptoitem) | Adds a bitmap to the menu item. |
| [AddIconToItem](#addicontoitem) | Adds a bitmap to the menu item. |
| [AddPopup](#addpopup) | Adds a popup child menu to an existing menu. |
| [Append](#append) | Appends a new item to the end of the specified menu bar, drop-down menu, submenu, or shortcut menu. |
| [Attach](#attach) | Attaches a menu to a window or dialog. |
| [BoldItem](#olditem) | Changes the text of a menu item to bold. |
| [CheckItem](#checkitem) | Checks a menu item. |
| [CheckRadioButton](#checkradiobutton) | Checks a specified menu item and makes it a radio item. |
| [ContextMenu](#contextmenu) | Creates a floating context menu. |
| [Create](#create) | Creates a new menu bar. |
| [CreatePopup](#createpopup) | Creates a drop-down menu, submenu, or shortcut menu. |
| [DeleteItem](#deleteitem) | Deletes a menu item or detaches a submenu from the specified menu. |
| [DeleteMenu](#deletemenu) | Deletes a menu or detaches a submenu from the specified menu. |
| [Destroy](#destroy) | Destroys the specified menu and frees any memory that the menu occupies. |
| [DestroyBitmaps](#destroybitmaps) | Destroys the bitmaps used by the menu. |
| [DisableItem](#disableitem) | Disables the specified menu item. |
| [DrawBar](#frawbar) |Redraws the menu bar of the specified window. |
| [EnableItem](#enableitem) | Enables the specified menu item. |
| [FindItemPos](#finditempos) | Finds the submenu and position of the specified menu item. |
| [GetBarInfo](#getarinfo) | Retrieves information about the specified menu bar. |
| [GetCheckMarkHeight](#getcheckmarkheight) | Retrieves the height of the default check-mark bitmap. |
| [GetCheckMarkWidth](#getcheckmarkwidth) | Retrieves the width of the default check-mark bitmap. |
| [GetContextHelpId](#getcontexthelpid) | Retrieves the Help context identifier associated with the specified menu. |
| [GetDefaultItem](#getdefaultitem) | Determines the default menu item on the specified menu. |
| [GetFont](#getfont) | Retrieves information about the font used in menu bars. |
| [GetFontPointSize](#getfontpointsize) | Retrieves the point size of the font used in menu bars. |
| [GetHandle](#gethandle) | Retrieves a handle to the menu assigned to the specified window or dialog.  |
| [GetInfo](#getinfo) | Gets information for a specified menu. |
| [GetItemCount](#getitemcount) | Determines the number of items in the specified menu. |
| [GetItemFromPoint](#getitemfrompoint) | Determines which menu item, if any, is at the specified location. |
| [GetItemID](#getitemid) | Retrieves the menu item ID of a menu item located at the specified position in a menu. |
| [GetItemInfo](#getiteminfo) | Retrieves information about a menu item. |
| [GetItemRect](#getitemrect) | Retrieves the bounding rectangle for the specified menu item. |
| [GetItemState](#getitemstate) | Retrieves the state of the specified menu item. |
| [GetItemText](#getitemtext) | Retrieves the text of the specified menu item. |
| [GetItemTextLen](#getitemtextlen) | Returns the length of the specified menu item. |
| [GetRect](#getrect) | Calculates the size of a menu bar or a drop-down menu. |
| [GetState](#getstate) | Retrieves the state of the specified menu item. |
| [GetSubMenu](#getsubmenu) | Retrieves a handle to the drop-down menu or submenu activated by the specified menu item. |
| [GetSubmenusCount](#getsubmenuscount) | Retrieves the number of submenus of a menu. |
| [GetSystemMenuHandle](#getsystemmenuhandle) | Retrieves the system menu handle. |
| [GetWindowOwner](#ghetwindowowner) | Retrieves the window owner of the specified menu |
| [GrayItem](#grayitem) | Grays the specified menu item. |
| [HiliteItem](#hiliteitem) | Highlights the specified menu item. |
| [IsItemChecked](#isitemchecked) | Returns TRUE if the specified menu item is checked; FALSE otherwise. |
| [IsItemDisabled](#isitemdisabled) | Returns TRUE if the specified menu item is enabled; FALSE otherwise. |
| [IsItemEnabled](#isitemenabled) | Returns TRUE if the specified menu item is disabled; FALSE otherwise. |
| [IsItemGrayed](#isitemgrayed) | Returns TRUE if the specified menu item is grayed; FALSE otherwise. |
| [IsItemHighlighted](#isitemhighlighted) | Returns TRUE if the specified menu item is highlighted; FALSE otherwise. |
| [IsItemOwnerdraw](#isitemownerdraw) | Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise. |
| [IsItemPopup](#isitempopup) | Returns TRUE if the specified menu item is a submenu; FALSE otherwise. |
| [IsItemSeparator](#isitemseparator) | Returns TRUE if the specified menu item is a separator; FALSE otherwise. |
| [IsMenu](#ismenu) | Determines whether a handle is a menu handle. |
| [IsMenuHandle](#ismenu) | Determines whether a handle is a menu handle. |
| [Load](#load) | Loads the specified menu resource from the executable (.exe) file associated with an application instance. |
| [LoadIndirect](#loadindirect) | Loads the specified menu template in memory. |
| [Modify](#modify) | Changes an existing menu item. |
| [NewPopup](#createpopup) | Creates a drop-down menu, submenu, or shortcut menu. |
| [RemoveCloseOption](#removecloseoption) | Removes the system menu close option and disables the X button. |
| [RemoveItem](#deleteitem) | Deletes a menu item or detaches a submenu from the specified menu. |
| [RemoveMenu](#deletemenu) | Deletes a menu or detaches a submenu from the specified menu. |
| [RestoreCloseOption](#restorecloseoption) | Restores the system menu close option and enables Alt+F4 and the X button. |
| [RightJustifyItem](#rightjustifyitem) |  Right justifies a top level menu item. This is usually used to have the Help menu item right-justified on the menu bar. |
| [SetContextHelpId](#setcontexthelpid) | Associates a Help context identifier with a menu. |
| [SetDefaultItem](#setdefaultitem) | Sets the default menu item for the specified menu. |
| [SetInfo](#setifo) | Sets information for a specified menu. |
| [SetItemBitmaps](#setitembitmaps) | Associates the specified bitmap with a menu item. |
| [SetItemBold](#bolditem) | Changes the text of a menu item to bold. |
| [SetItemInfo](#setiteminfo) | Changes information about a menu item. |
| [SetItemText](#setitemtext) | Sets the text of the specified menu item. |
| [SetItemState](#setitemstate) | Sets the state of the specified menu item. |
| [SetState](#setstate) | Sets the state of the specified menu item. |
| [ToggleCheckState](#togglecheckstate) | Toggles the checked state of a menu item. |
| [ToggleItem](#toggleitem) | Toggles the checked state of a menu item. |
| [TrackPopupMenu](#trackpopupmenu) | Displays a shortcut menu at the specified location and tracks the selection of items on the menu. |
| [TrackPopupMenuEx](#trackpopupmenuex) | Displays a shortcut menu at the specified location and tracks the selection of items on the menu. |
| [UncheckItem](#uncheckitem) | Unchecks a menu item. |

---

### AddBitmapToItem

Adds a bitmap to the menu item.

```
FUNCTION AddBitmapToItem (BYVAL hMenu AS HMENU, BYVAL nMenuItem AS LONG, _
   BYVAL fByPosition AS BOOLEAN, BYVAL hbmp AS HBITMAP) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *nMenuItem* | The identifier or position of the menu item to change. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |
| *hbmp* | The bitmap handle. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### AddIconToItem

Converts an icon handle to a bitmap and adds it to the specified *hbmpItem field* of **HMENU** item.

```
FUNCTION AddIconToItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, _
   BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |
| *hIcon* | Handle of the icon to add to the menu. |
| *fAutoDestroy* | TRUE (the default) or FALSE. If TRUE, **AddIconToItem** destroys the icon before returning. |
| *phbmp* | Out. Location where the bitmap representation of the icon is stored. Can be NULL. |

#### Return value

TRUE or FALSE.

#### Remarks

The caller is responsible for destroying the bitmap generated. The icon will be destroyed if *fAutoDestroy* is set to true. The *hbmpItem* field of the menu item can be used to keep track of the bitmap by passing NULL to *phbmp*.

Using **AfxGdipAddIconFromFile** or **AfxGdipIconFromRes** to load the image from a file or resource and convert it to a icon you can use alphablended .png icons.

#### Usage example

Loading the icon from disk:

```
DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 1)
DIM hIcon AS HICON = LoadImageW(NULL, ExePath & "\undo_32.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE)
IF hIcon THEN CMenu.AddIconToItem(hSubMenu, 0, TRUE, hIcon)
```

Loading the icon from a resource file:

```
DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 1)
CMenu.AddIconToItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInstance, "IDI_UNDO_32"))
```
---

### Append

Appends a new item to the end of the specified menu bar, drop-down menu, submenu, or shortcut menu. You can use this function to specify the content, appearance, and behavior of the menu item.

```
FUNCTION Append (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL uIDNewItem AS UINT_PTR, _
   BYVAL pwszNewItem AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle of the parent menu to which the item should be added. |
| *uFlags* | Controls the appearance and behavior of the new menu item. This parameter can be a combination of the following values (see below). |
| *uIDNewItem* | The identifier of the new menu item or, if the *uFlags* parameter is set to **MF_POPUP**, a handle to the drop-down menu or submenu. |
| *pwszNewItem* | The content of the new menu item. The interpretation of *pwszNewItem* depends on whether the *uFlags* parameter includes the following values (see below). |

| Flag  | Meaning |
| ----- | ------- |
| **MF_BITMAP** | Contains a bitmap handle. |
| **MF_OWNERDRAW** | Contains an application-supplied value that can be used to maintain additional data related to the menu item. The value is in the **itemData** member of the structure pointed to by the *lParam* parameter of the **WM_MEASUREITEM** or **WM_DRAWITEM** message sent when the menu is created or its appearance is updated. |
| **MF_STRING** | Contains a pointer to a null-terminated string. |

#### Values for the *uFlags* parameter

| Flag  | Meaning |
| ----- | ------- |
| **MF_BITMAP** | Uses a bitmap as the menu item. The lpNewItem parameter contains a handle to the bitmap. |
| **MF_CHECKED** | Places a check mark next to the menu item. If the application provides check-mark bitmaps (see SetMenuItemBitmaps, this flag displays the check-mark bitmap next to the menu item. |
| **MF_DISABLED** | Disables the menu item so that it cannot be selected, but the flag does not gray it. |
| **MF_ENABLED** | Enables the menu item so that it can be selected, and restores it from its grayed state. |
| **MF_GRAYED** | Disables the menu item and grays it so that it cannot be selected. |
| **MF_MENUBARBREAK** | Functions the same as the **MF_MENUBREAK** flag for a menu bar. For a drop-down menu, submenu, or shortcut menu, the new column is separated from the old column by a vertical line. |
| **MF_MENUBREAK** | Places the item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or shortcut menu) without separating columns. |
| **MF_OWNERDRAW** | Specifies that the item is an owner-drawn item. Before the menu is displayed for the first time, the window that owns the menu receives a **WM_MEASUREITEM** message to retrieve the width and height of the menu item. The **WM_DRAWITEM** message is then sent to the window procedure of the owner window whenever the appearance of the menu item must be updated. |
| **MF_POPUP** | Specifies that the menu item opens a drop-down menu or submenu. The *uIDNewItem* parameter specifies a handle to the drop-down menu or submenu. This flag is used to add a menu name to a menu bar, or a menu item that opens a submenu to a drop-down menu, submenu, or shortcut menu. |
| **MF_SEPARATOR** | Draws a horizontal dividing line. This flag is used only in a drop-down menu, submenu, or shortcut menu. The line cannot be grayed, disabled, or highlighted. The *pwszNewItem* and *uIDNewItem* parameters are ignored. |
| **MF_STRING** | Specifies that the menu item is a text string; the lpNewItem parameter is a pointer to the string. |
| **MF_UNCHECKED** | Does not place a check mark next to the item (default). If the application supplies check-mark bitmaps (see **SetMenuItemBitmaps**), this flag displays the clear bitmap next to the menu item. |

#### Usage examples

```
CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
```
---

### AddPopup

Adds a popup child menu to an existing menu. A popup menu is a small window that "pops up" when a menu item is highlighted. This allows nesting, and gives the user an opportunity to choose from "sub-menu" items.

```
FUNCTION AddPopup (BYVAL hMenu AS HMENU, BYVAL hPopup AS HMENU, BYVAL fState AS UINT, _
   BYVAL item AS LONG, BYREF wszText AS WSTRING, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle of the parent menu which holds the popup. |
| *hPopup* | Handle of the child popup menu to be added. |
| *fState* | The initial state of the menu item. It can be one of the following:<br>MFS_DISABLED: Disable the item so that it cannot be selected.<br>MFS_ENABLED:  Enable the item so that it can be selected. |
| *item* | If the option is included, *item* is a unique numeric identifier for this popup menu. *item* may be used later with a *fByPosition* option to reference this popup. *item* is an integral numeric value in the range of -32768 to +32767. |
| *wszText* | Text displayed in the parent menu. An ampersand (&) may be used in the  to make the following letter into a control accelerator (hot-key). The letter appears underscored to signify that it is an accelerator. |
| *fByPosition* | Indicates the position in the parent menu where the popup child menu is to be inserted. If the *fByPosition* option is used, the popup menu is inserted prior to the menu item specified by *item*. Otherwise, the popup menu is inserted at the physical position within the parent menu, where position = 1 for the first position, position = 2 for the second, and so on. If position is not specified then the popup menu is appended to the end of the menu. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Usage example

```
DIM hSubPopUpMenu AS HMENU = CMenu.CreatePopUp
    CMenu.AddPopup hPopUpMenu, hSubPopUpMenu, MF_ENABLED, 4001, "Nested submenu 1"
    CMenu.Append hSubPopUpMenu, MF_ENABLED, 4002, "Nested submenu 1 item 1"
    CMenu.Append hSubPopUpMenu, MF_ENABLED, 4003, "Nested submenu 1 item 2"
    CMenu.Append hSubPopUpMenu, MF_SEPARATOR, 0, ""
DIM hSubPopUpMenu2 AS HMENU = CMenu.CreatePopUp
    CMenu.AddPopup hSubPopUpMenu, hSubPopUpMenu2, MF_ENABLED, 5001, "Nested submenu 2"
    CMenu.Append hSubPopUpMenu2, MF_ENABLED, 5002, "Nested submenu 2 item 1"
    CMenu.Append hSubPopUpMenu2, MF_ENABLED, 5003, "Nested submenu 2 item 2"
```
---

### Attach

Attaches a menu to a window or dialog.

```
FUNCTION Attach (BYVAL hwnd AS HWND, BYVAL hMenu AS HMENU) AS BOOLEAN
```

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Remarks

The Windows API function **SetMenu** performs the same action.

---

### BoldItem

Changes the text of a menu item to bold.

```
FUNCTION BoldItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG) AS BOOLEAN
FUNCTION SetItemBold (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Remarks

The application must call the **CMenu.DrawBar** method whenever a menu changes, whether or not the menu is in a displayed window. **BoldItem** and **SetItemBold** do this call internally.

---

### CheckItem

Checks a menu item.

```
FUNCTION CheckItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

The return value specifies the previous state of the menu item (either **MF_CHECKED** or **MF_UNCHECKED**). If the menu item does not exist, the return value is -1.

#### Usage examples

By command:
```
CMenu.CheckItem(hMenu, IDM_OPEN)
```
By position:
```
DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 0)
CMenu.CheckItem(hSubMenu, 1, TRUE)
```
---

### CheckRadioButton

Checks a specified menu item and makes it a radio item. At the same time, the function clears all other menu items in the associated group and clears the radio-item type flag for those items.

```
FUNCTION CheckRadioButton (BYVAL hMenu AS HMENU, BYVAL first AS LONG, BYVAL last AS LONG, _
   BYVAL check AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *first* | The identifier or position of the first menu item in the group. |
| *last* | The identifier or position of the last menu item in the group. |
| *check* | The identifier or position of the menu item to check. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Usage example
```
CMenu.CheckRadioButton(hMenu, ID_OPEN, ID_EXIT, ID_EXIT)      ' By item identifier
CMenu.CheckRadioButton(GetSubMenu(hMenu, 0), 1, 2, 2, TRUE)   ' By position
```
---

### ContextMenu

Creates a floating context menu.

```
FUNCTION ContextMenu (BYVAL hWin AS HWND, BYVAL hPopupMenu AS HMENU, BYVAL x AS LONG, _
   BYVAL y AS LONG, BYVAL flags AS UINT) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the window or dialog that owns the shortcut menu. |
| *hPopupMenu* | A handle to the shortcut menu to be displayed. The handle can be obtained by calling **MenuAddPopup** to create a new shortcut menu, or by calling **MenuGetSubMenu** to retrieve a handle to a submenu associated with an existing menu item. |
| *x* | The horizontal location of the shortcut menu, in screen coordinates. |
| *y* | The vertical location of the shortcut menu, in screen coordinates. |
| *flags* | May be combined, as appropriate, to specify the characteristics of the context menu.<br>TPM_LEFTBUTTON: Tracks the left button.<br>TPM_RIGHTBUTTON: Tracks the right button.<br>TPM_LEFTALIGN: Left side of the menu is aligned with *x*.<br>TPM_CENTERALIGN: Centers horizontally with *x*.<br>TPM_RIGHTALIGN: Right side of the menu is aligned with *x*.<br>TPM_TOPALIGN: Top of the menu is aligned with *y*.<br>TPM_VCENTERALIGN: Centers vertically with *y*.<br>TPM_BOTTOMALIGN: Bottom of the menu is aligned with *y*. |

#### Return value

If you specify **TPM_RETURNCMD** in the *flags* parameter, the return value is the menu-item identifier of the item that the user selected. If the user cancels the menu without making a selection, or if an error occurs, the return value is zero.

#### Example

```
#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_LABEL = 1001

' // Menu identifiers
ENUM
   IDM_NEW = 1001   ' New file
   IDM_OPEN         ' Open file...
   IDM_SAVE         ' Save file
   IDM_SAVEAS       ' Save file as...
   IDM_EXIT         ' Exit
END ENUM

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
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Context menu", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Adds a label
   pWindow.AddControl("Label", hWin, IDC_LABEL, "Click the mouse right button", 110, 20, 175, 23)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDC_LABEL, AFX_ANCHOR_WIDTH)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 290, 160, 75, 30)
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
'            CASE IDM_NEW   ' IDM_OPEN, IDM_SAVE, etc.
'               MessageBox hwnd, "New option clicked", "Menu", MB_OK
            CASE IDM_NEW TO IDM_EXIT  ' IDM_OPEN, IDM_SAVE, etc.
               MessageBox hwnd, "Option clicked", "Menu", MB_OK
         END SELECT
         RETURN 0

      CASE WM_CONTEXTMENU
         ' // Build the context menu
         DIM hPopUpMenu AS HMENU = CMenu.CreatePopUp
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_OPEN, "&Open..." & CHR(9) & "Ctrl+O"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVEAS, "Save &As..."
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
         DIM pt AS POINT
         GetCursorPos @pt
         CMenu.ContextMenu hwnd, hPopupMenu, pt.x, pt.y

         CMenu.Destroy hPopupMenu
         EXIT FUNCTION

      CASE WM_DESTROY
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

### Create

Creates a new menu bar.

```
FUNCTION Create () AS HMENU
```

#### Return value

If the function succeeds, the return value is a handle to the newly created menu.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Usage example

```
DIM hMenu AS HMENU = CMenu.Create
```
---

### CreatePopup

Creates a drop-down menu, submenu, or shortcut menu. The menu is initially empty. You can insert or append menu items by using the **CMenu.AddString** function. You can also use the **CMenu.Append** method to append menu items.

```
FUNCTION CreatePopup () AS HMENU
```

#### Return value

If the function succeeds, the return value is a handle to the newly created menu.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Remarks

The application can add the new menu to an existing menu, or it can display a shortcut menu by calling the **TrackPopupMenuEx** or **TrackPopupMenu** functions.

Resources associated with a menu that is assigned to a window are freed automatically. If the menu is not assigned to a window, an application must free system resources associated with the menu before closing. An application frees menu resources by calling the **CMenu.Destroy** method.

---

### DeleteItem

Deletes a menu item or detaches a submenu from the specified menu.

```
FUNCTION DeleteItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
FUNCTION RemoveItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get delete. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *item*. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 0 for the first position, position = 1 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Remarks

To remove menus use always the position and to remove drop-down menus use the identifier.

#### Usage examples

```
' ----------------------------------------------------------------------------------------
' Remove by identifier:
' ----------------------------------------------------------------------------------------
CMenu.DeleteItem(hMenu, IDM_OPEN)    ' Removes the menu item with the IDM_OPEN identifier
CMenu.DeleteItem(hMenu, IDM_POPUP)   ' Removes the popup menu with the IDM_POPUP identifier
' ----------------------------------------------------------------------------------------
' Remove a menu by position
' ----------------------------------------------------------------------------------------
CMenu.DeleteItem(hMenu, 1, TRUE)     ' Removes the second menu (zero-based position)
' ----------------------------------------------------------------------------------------
' Remove an item by position
' ----------------------------------------------------------------------------------------
DIM hFoundMenu AS HMENU, itemPos AS LONG
DIM bRes AS BOOLEAN = CMenu.FindItemPos(hMenu, IDM_EXIT, hFoundMenu, itemPos)
IF bRes THEN CMenu.DeleteItem(hFoundMenu, itemPos, TRUE)
' ----------------------------------------------------------------------------------------
```
---

### DeleteMenu

Deletes a menu or detaches a submenu from the specified menu. **DeleteItem** can also be used to delete menus.

```
FUNCTION DeleteMenu (BYVAL hMenu AS HMENU, BYVAL uPosition AS DWORD, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
FUNCTION RemoveMenu (BYVAL hMenu AS HMENU, BYVAL uPosition AS DWORD, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uPosition* | The identifier or position of the menu to delete. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uPosition*. If this parameter is FALSE, *uPosition* is a menu item identifier. Otherwise, it is a menu item position, where position = 0 for the first position, position = 1 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Remarks

To remove menus use always the position and to remove drop-down menus use the identifier.

#### Usage examples

```
CMenu.DeleteMenu(hMenu, 1, TRUE)     ' Removes the second menu (zero-based position)
CMenu.DeleteMenu(hMenu, IDM_POPUP)   ' Removes the popup menu with the IDM_POPUP identifier
```
---

### Destroy

Destroys the main menu from the window or dialog. The second overloaded method destroys the menu attached to a window or dialog.

```
FUNCTION Destroy (BYVAL hMenu AS HMENU) AS BOOLEAN
FUNCTION Destroy (BYVAL hWin AS HWND) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle of the menu. |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Usage examples

```
CMenu.Destroy(hMenu)
CMenu.Destroy(hwnd)
```
---

### DestroyBitmaps

Destroys the bitmaps used by the menu, if any.

```
SUB DestroyBitmaps (BYVAL hMenu AS HMENU)
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle of the menu. |

#### Usage example

```
CASE WM_DESTROY
    ' // Destroy the menu and the bitmaps
    DIM hMenu AS HMENU = CMenu.GetHandle(hwnd)
    CMenu.DestroyBitmaps(hMenu)
    CMenu.Destroy(hMenu)              
```
---

### DisableItem

Disables the specified menu item.

```
FUNCTION DisableItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Usage example

```
CMenu.DisableItem(hMenu, IDM_OPEN)
```

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** method whenever a menu changes, whether or not the menu is in a displayed window. **DisableItem** does this call internally.

---

### DrawBar

Redraws the menu bar of the specified window or dialog. If the menu bar changes after the system has created the window or dialog, this function must be called to draw the changed menu bar.

```
FUNCTION DrawBar (BYVAL hWin AS HWND) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

#### Remarks

This operation should be performed when a menu is altered dynamically after the dialog has been initially created, without regard to the visible state of the dialog.

---

### EnableItem

Enables the specified menu item.

```
FUNCTION EnableItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

#### Remaarks

The application must call the **CMenu.DrawBar** method whenever a menu changes, whether or not the menu is in a displayed window. **EnableItem** does this call internally.

#### Usage example

```
CMenu.EnableItem(hMenu, IDM_OPEN)
```
---

### FindItemPos

Recursively finds the submenu and position of the specified menu item.

```
FUNCTION FindItemPos (BYVAL hMenu AS HMENU, BYVAL itemID AS UINT, _
   BYREF hMenuFound AS HMENU, BYREF itemPos AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *itemID* | The identifier of the menu item. |
| *hMenuFound* | Handle of the submenu where the item was found |
| *itemPos* | A variable of type LONG that receives the zero-based position of the item in the submenu. |

#### Return value

Returns TRUE if the function succeeds or FALSE otherwise.

#### Example
```
DIM hFoundMenu AS HMENU, itemPos AS LONG
DIM bRes AS BOOLEAN = CMenu.FindItemPos(hMenu, IDM_CASCADE, hFoundMenu, itemPos)
IF bRes THEN
   PRINT "hFoundMenu", hFoundMenu
   PRINT "itemPos", itemPos
   PRINT CMenu.GetItemID(hMenu, hFoundMenu, itemPos)
END IF
```
---

### GetBarInfo

Retrieves information about the specified menu bar.

```
FUNCTION GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG, BYVAL pmbi AS MENUBARINFO PTR) AS BOOLEAN
FUNCTION GetBarInfo (BYVAL hwnd AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG, BYREF mbi AS MENUBARINFO) AS BOOLEAN
FUNCTION GetBarInfo (BYVAL hWin AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG) AS MENUBARINFO
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window or dialog that owns the menu bar. |
| *idObject* | The menu object. This parameter can be one of the following values:<br>OBJID_CLIENT: &hFFFFFFFC - The popup menu associated with the window.<br>OBJID_MENU: &hFFFFFFFD - The menu bar associated with the window<br>OBJID_SYSMENU: &hFFFFFFFF - The system menu associated with the window |
| *idItem* | The item for which to retrieve information. If this parameter is zero, the function retrieves information about the menu itself. If this parameter is 1, the function retrieves information about the first item on the menu, and so on. |

#### Return value

A **MENUBARINFO** structure.

---

### GetCheckMarkHeight

Retrieves the height of the default check-mark bitmap. The system displays this bitmap next to selected menu items. Before calling the **SetItemBitmaps** function to replace the default check-mark bitmap for a menu item, an application must determine the correct bitmap size by calling **GetCheckMarkWidth** and **GetCheckMarkHeight**.

```
FUNCTION GetCheckMarkHeight () AS LONG
```

#### Return value

Returns the height of the default check-mark bitmap.

---

### GetCheckMarkWidth

Retrieves the width of the default check-mark bitmap. The system displays this bitmap next to selected menu items. Before calling the **SetItemBitmaps** function to replace the default check-mark bitmap for a menu item, an application must determine the correct bitmap size by calling **GetCheckMarkWidth** and **GetCheckMarkHeight**.

```
FUNCTION GetCheckMarkWidth () AS LONG
```

#### Return value

Returns the width of the default check-mark bitmap.

---

### GetContextHelpId

Retrieves the Help context identifier associated with the specified menu.

```
FUNCTION GetContextHelpId (BYVAL hMenu AS HMENU) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu for which the Help context identifier is to be retrieved. |

#### Return value

Returns the Help context identifier if the menu has one, or zero otherwise.

---

### GetDefaultItem

Determines the default menu item on the specified menu.

```
FUNCTION GetDefaultItem (BYVAL hMenu AS HMENU, BYVAL gmdiFlags AS UINT = 0, BYVAL fByPosition AS BOOLEAN = TRUE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu for which to retrieve the default menu item. |
| *gmdiFlags* | Indicates how the function should search for menu items. This parameter can be zero or more of the following values.<br>GMDI_GOINTOPOPUPS &H0002 : If the default item is one that opens a submenu, the function is to search recursively in the corresponding submenu. If the submenu has no default item, the return value identifies the item that opens the submenu. By default, the function returns the first default item on the specified menu, regardless of whether it is an item that opens a submenu.<br>GMDI_USEDISABLED &h0001: The function is to return a default item, even if it is disabled. By default, the function skips disabled or grayed items. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

If the function succeeds, the return value is the identifier or position of the menu item. If the function fails, the return value is 0. To get extended error information, call **GetLastError**.

---

### GetFont

Retrieves information about the font used in menu bars.

```
FUNCTION GetFont (BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
FUNCTION GetFont () AS LOGFONTW
```

| Parameter  | Description |
| ---------- | ----------- |
| *plfw* | Pointer to a **LOGFONTW** structure that contains information about the font used in menu bars. |

#### Return value

A **LOGFONTW** structure that contains information about the font used in menu bars.

---

### GetFontPointSize

Retrieves the point size of the font used in menu bars.

```
FUNCTION GetFontPointSize () AS LONG
```

#### Return value

The point size of the font used in menu bars. If the function fails, the return value is 0.

---

### GetHandle

Retrieves a handle to the menu assigned to the specified window or dialog. 

```
FUNCTION GetHandle (BYVAL hWin AS HWND) AS HMENU
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window or dialog whose menu handle is to be retrieved. |

#### Return value

The return value is a handle to the menu. If the specified window has no menu, the return value is NULL. If the window is a child window, the return value is undefined.

#### Remarks

**GetHandle** does not work on floating menu bars. Floating menu bars are custom controls that mimic standard menus; they are not menus. To get the handle on a floating menu bar, use the Active Accessibility APIs. The Windows API **GetMenu** function can be used instead of **CMenu.GetHandle**.

---

### GetInfo

Gets information for a specified menu.

```
FUNCTION GetInfo (BYVAL hMenu AS HMENU, BYVAL pmi AS MENUINFO PTR) AS BOOLEAN
FUNCTION GetInfo (BYVAL hMenu AS HMENU, BYREF mi AS MENUINFO) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window or dialog whose menu handle is to be retrieved. |
| *pmi* | A pointer to a **MENUINFO** structure containing information for the menu. |
| *mi* | A pointer to a **MENUINFO** structure containing information for the menu. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

The third overloaded function returns a **MENUINFO** directly.

---

### GetItemCount

Determines the number of items in the specified menu.

```
FUNCTION GetItemCount (BYVAL hMenu AS HMENU) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu to be examined. |

#### Return value

If the function succeeds, the return value specifies the number of items in the menu.

If the function fails, the return value is -1. To get extended error information, call **GetLastError**.

---

### GetItemFromPoint

Determines which menu item, if any, is at the specified location.

```
FUNCTION GetItemFromPoint (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU, BYVAL ptScreen AS POINT) AS LONG
FUNCTION GetItemFromPoint (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window containing the menu. If this value is NULL and the hMenu parameter represents a popup menu, the function will find the menu window. |
| *hMenu* | A handle to the menu containing the menu items to hit test. |
| *ptScreen* | A structure that specifies the location to test. If *hMenu* specifies a menu bar, this parameter is in window coordinates. Otherwise, it is in client coordinates. |

#### Return value

Returns the zero-based position of the menu item at the specified location or -1 if no menu item is at the specified location.

---

### GetItemID

Retrieves the menu item ID of a menu item located at the specified position in a menu.

```
FUNCTION GetItemID (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS UINT
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the item whose identifier is to be retrieved. |
| *nPos* | The zero-based relative position of the menu item whose identifier is to be retrieved. |

#### Return value

The return value is the identifier of the menu item located at the specified position in a menu.

#### Remarks

When working with Win32 menus, it is easy to assume that menu item positions are global and that GetItemID(hMenu, nPos) will return the identifier of the item located at that absolute index. Unfortunately, this assumption is incorrect and leads to the function consistently returning -1.

The key detail — which is not clearly stated in Microsoft’s documentation — is the following: The Windows API function **GetMenuItemID**, used by **GetItemID**, does not accept absolute positions, it only accepts positions relative to the specific submenu you pass as *hMenu*.

In other words:

* Each submenu (HMENU) has its own independent list of items.
* Positions are 0‑based within that submenu only.
* Passing the main menu handle (hMenu) and a global index will always fail.
* Passing the wrong submenu handle will also fail.

This explains why calling GetItemID(hMenu, absolutePos) returns -1, even when the item clearly exists.

To retrieve the ID of a menu item, you must:

* Determine which submenu contains the item.
* Determine the relative position of the item within that submenu.
* Pass the correct submenu handle and the relative position to **GetItemID**.

For example: CMenu.GetItemID(CMenu.GetSubMenu(hMenu, 0), 1)

This works because:

* GetSubMenu(hMenu, 0) returns the correct submenu handle.
* 1 is the position relative to that submenu.

Finding the correct submenu and position:

To make this easier, the framework provides: FindItemPos(hMenu, itemID, hMenuFound, itemPos)

This function returns:

* hMenuFound → the handle of the submenu
* itemPos → the zero‑based position inside that submenu

Once you have these values, you can safely call: GetItemID(hMenuFound, itemPos)

This is the only combination that Win32 accepts.

#### Summary

* Win32 menu positions are not global.
* Each submenu has its own independent index space.
* GetItemID requires: the correct submenu handle, and the relative position within that submenu.

Passing the main menu handle and an absolute index will always fail.

This behavior is unintuitive at first, but once understood, menu handling becomes predictable and reliable.

---

### GetItemInfo

Retrieves information about a menu item.

```
FUNCTION GetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPosition AS BOOLEAN, _
   BYVAL pmii AS MENUITEMINFOW PTR) AS BOOLEAN
FUNCTION GetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPosition AS BOOLEAN, _
   BYREF mii AS MENUITEMINFOW) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPositon* | The meaning of *item*. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position |
| *pmii* | A pointer to a **MENUITEMINFO** structure that specifies the information to retrieve and receives information about the menu item. Note that you must set the **cbSize** member to sizeof(MENUITEMINFO) before calling this function. |
| *mii* | A **MENUITEMINFO** structure that specifies the information to retrieve and receives information about the menu item. Note that you must set the **cbSize** member to sizeof(MENUITEMINFO) before calling this function. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the **GetLastError** function.

#### Remarks

To retrieve a menu item of type **MFT_STRING**, first find the size of the string by setting the **dwTypeData** member of **MENUITEMINFO** to NULL and then calling **CMenu.GetItemInfo**. The value of **cch**+1 is the size needed. Then allocate a buffer of this size, place the pointer to the buffer in **dwTypeData**, increment cch by one, and then call **CMenu.GetItemInfo** once again to fill the buffer with the string.

If the retrieved menu item is of some other type, then **CMenu.GetItemInfo** sets the **dwTypeData** member to a value whose type is specified by the **fTypefType** member and sets **cch** to 0.

---

### GetItemRect

Retrieves the bounding rectangle for the specified menu item.

```
FUNCTION GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT, BYVAL prcItem AS RECT PTR) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYVAL uItem AS UINT, BYREF rcItem AS RECT) AS BOOLEAN
FUNCTION GetItemRect (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog  that owns the menu. If this value is NULL and the *hMenu* parameter represents a popup menu, the function will find the menu window. |
| *hmenu* | The handle of the menu. |
| *uItem* | The zero-based relative position of the menu item. |
| *prcItem* | A pointer to a **RECT** structure that receives the bounding rectangle of the specified menu item expressed in screen coordinates. |
| *rcItem* | A **RECT** structure that receives the bounding rectangle of the specified menu item expressed in screen coordinates. |

#### Return value

If the function succeeds, the return value is 0. If the function fails, the return value is a system error code.

The third overloaded method returns a **RECT** structure directly.

---

### GetItemState

Retrieves the state of the specified menu item.

```
FUNCTION GetItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

0 on failure or one or more of the following values:
```
MFS_CHECKED   The item is checked
MFS_DEFAULT   The menu item is the default.
MFS_DISABLED  The item is disabled.
MFS_ENABLED   The item is enabled.
MFS_GRAYED    The item is grayed.
MFS_HILITE    The item is highlighted
MFS_UNCHECKED The item is unchecked.
MFS_UNHILITE  The item is not highlighted.
```

#### Usage example
```
DIM dwState AS DWORD = CMenu.GetItemState(hMenu, IDM_OPEN)
```
---

### GetItemText

Retrieves the text of the specified menu item.

```
FUNCTION GetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG, _
   BYVAL pwszText AS WSTRING PTR, BYVAL cchTextMax AS LONG) AS BOOLEAN
FUNCTION GetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |
| *pwszText* | Pointer to a unicode buffer that receives the text of the menu item. |
| *cchTextMax* | Size in characters of the *pwszText* buffer. |

#### Usage example

```
DIM dwsText AS DWSTRING = CMenu.GetItemText(hMenu, 1, TRUE)
```
---

### GetItemTextLen

Returns the lengnth of the specified menu item.

```
FUNCTION GetItemTextLen (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### GetRect

Calculates the size of a menu bar or a drop-down menu.

```
FUNCTION GetRect (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU, BYVAL prcmenu AS RECT PTR) AS LONG
FUNCTION GetRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU, BYREF rcmenu AS RECT) AS LONG
FUNCTION GetRect (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU) AS RECT
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the windowor dialog  that owns the menu. If this value is NULL and the *hMenu* parameter represents a popup menu, the function will find the menu window. |
| *hmenu* | The handle of the menu. |
| *prcmenu* | A pointer to a **RECT** structure that receives the bounding rectangle of the specified menu expressed in screen coordinates. |
| *rcmenu* | A **RECT** structure that receives the bounding rectangle of the specified menu expressed in screen coordinates. |

#### Return value

If the function succeeds, the return value is 0. If the function fails, the return value is a system error code.

The third overloaded method returns a **RECT** structure directly.

---

### GetState

Retrieves the state of the specified menu item.

```
FUNCTION GetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS UINT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

0 on failure or one or more of the following values:

| Value  | Description |
| ------ | ----------- |
| **MFS_CHECKED** | The item is checked. |
| **MFS_DEFAULT** | The menu item is the default. |
| **MFS_DISABLED** | The item is disabled. |
| **MFS_ENABLED** | The item is enabled. |
| **MFS_GRAYED** | The item is grayed. |
| **MFS_HILITE** | The item is highlighted. |
| **MFS_UNCHECKED** | The item is unchecked. |
| **MFS_UNHILITE** | The item is not highlighted. |

---

### GetSubMenu

Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.

```
FUNCTION GetSubMenu (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS HMENU
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |
| *nPos* | The zero-based relative position of the menu item whose identifier is to be retrieved. |

#### Return value

If the function succeeds, the return value is a handle to the drop-down menu or submenu activated by the menu item. If the menu item does not activate a drop-down menu or submenu, the return value is NULL.

---

### GetSubmenusCount

Retrieves the number of submenus of a menu.

```
FUNCTION GetSubmenusCount(BYVAL hMenu AS HMENU) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |

#### Return value

The number of submenus.

---

### GetSystemMenuHandle

Retrieves the system menu handle.

```
FUNCTION GetSystemMenuHandle (BYVAL hwnd AS HWND, BYVAL bRevert AS BOOLEAN = FALSE) AS HMENU
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |
| *bRevert* | The action to be taken. If this parameter is FALSE, **MenuGetSystemMenuHandle** returns a handle to the copy of the window menu currently in use. The copy is initially identical to the window menu, but it can be modified. If this parameter is TRUE, **MenuGetSystemMenuHandle** resets the window menu back to the default state. The previous window menu, if any, is destroyed. |

#### Return value

If the *bRevert* parameter is FALSE, the return value is a handle to a copy of the window menu. If the *bRevert* parameter is TRUE, the return value is NULL.

---

### GetWindowOwner

Retrieves the window owner of the specified menu

```
FUNCTION GetWindowOwner (BYVAL hMenu AS HMENU) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |

#### Return value

The handle of the window that owns the menu.

---

### GrayItem

Grays the specified menu item.

```
FUNCTION GrayItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** function whenever a menu changes, whether or not the menu is in a displayed window. **GrayItem** does this call internally.

---

### HiliteItem

Highlights the specified menu item.

```
FUNCTION HiliteItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** function whenever a menu changes, whether or not the menu is in a displayed window. **HiliteItem** does this call internally.

---

### IsItemChecked

Returns TRUE if the specified menu item is checked; FALSE otherwise.

```
FUNCTION IsItemChecked (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.IsItemChecked(hMenu, IDM_OPEN)
```
---

### IsItemDisabled

Returns TRUE if the specified menu item is disabled; FALSE otherwise.

```
FUNCTION IsItemDisabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example
```
DIM bRes AS BOOLEAN = IsItemDisabled(hMenu, IDM_OPEN)
```
---

### IsItemEnabled

Returns TRUE if the specified menu item is enabled; FALSE otherwise.

```
FUNCTION IsItemEnabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.IsItemEnabled(hMenu, IDM_OPEN)
```
---

### IsItemGrayed

Returns TRUE if the specified menu item is grayed; FALSE otherwise.

```
FUNCTION IsItemGrayed (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.IsItemGrayed(hMenu, IDM_OPEN)
```
---

### IsItemHighlighted

Returns TRUE if the specified menu item is highlighted; FALSE otherwise.

```
FUNCTION IsItemHighlighted (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.IsItemHighlighted(hMenu, IDM_OPEN)
```
---

### IsItemOwnerdraw

Returns TRUE if the specified menu item is a ownerdraw; FALSE otherwise.

```
FUNCTION IsItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example

```
DIM bRes AS BOOLEAN = CMenu.IsItemOwnerdraw(hMenu, IDM_OPEN)
```
---

### IsItemPopup

Returns TRUE if the specified menu item is a submenu; FALSE otherwise.

```
FUNCTION IsItemPopup (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example

```
DIM bRes AS BOOLEAN = CMenu.IsItemPopup(hMenu, IDM_OPEN)
```
---

### IsItemSeparator

Returns TRUE if the specified menu item is a separator; FALSE otherwise.

```
FUNCTION IsItemSeparator (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example:
```
DIM hSubMenu AS HMENU = CMenu.GetSubMenu(hMenu, 0)
DIM bRes AS BOOLEAN = CMenu.IsItemSeparator(hSubMenu, 2, TRUE)
```
---

### IsMenu

Determines whether a handle is a menu handle.

```
FUNCTION IsMenu (BYVAL hMenu AS HMENU) AS BOOLEAN
FUNCTION IsMenuHandle (BYVAL hMenu AS HMENU) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified handle is a menu handle; FALSE otherwise.

#### Usage example

```
DIM bRes AS BOOLEAN = CMenu.IsMenu(hMenu)
DIM bRes AS BOOLEAN = CMenu.IsMenuHandle(hMenu)
```
---

### Load

Loads the specified menu resource from the executable (.exe) file associated with an application instance.

```
FUNCTION Load (BYVAL hInst AS HINSTANCE, BYVAL pMenuName AS WSTRING PTR) AS HMENU
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInst* | A handle to the module containing the menu resource to be loaded. |
| *pMenuName* | The name of the menu resource. Alternatively, this parameter can consist of the resource identifier in the low-order word and zero in the high-order word. To create this value, use the **MAKEINTRESOURCE** macro. |

#### Return value

If the function succeeds, the return value is a handle to the menu resource.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Remarks

The **CMenu.Destroy** method is used, before an application closes, to destroy the menu and free memory that the loaded menu occupied.

---

### LoadIndirect

Loads the specified menu template in memory.

```
FUNCTION LoadIndirect (BYVAL pMenuTemplate AS MENUTEMPLATEW PTR) AS HMENU
```

| Parameter  | Description |
| ---------- | ----------- |
| *pMenuTemplate* | A pointer to a menu template or an extended menu template. A menu template consists of a MENUITEMTEMPLATEHEADER structure followed by one or more contiguous MENUITEMTEMPLATE structures. An extended menu template consists of a MENUEX_TEMPLATE_HEADER structure followed by one or more contiguous MENUEX_TEMPLATE_ITEM structures. |

#### Return value

If the function succeeds, the return value is a handle to the menu.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Remarks

For both the ANSI and the Unicode version of this function, the strings in the **MENUITEMTEMPLATE** structure must be Unicode strings.

---

### Modify

Changes an existing menu item. This function is used to specify the content, appearance, and behavior of the menu item.

```
FUNCTION Modify (BYVAL hMenu AS HMENU, BYVAL uPosition AS UINT, BYVAL uFlags AS UINT, _
   BYVAL uIDNewItem AS UINT_PTR, BYVAL pNewItem AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu to be changed. |
| *uPosition* | The menu item to be changed, as determined by the *uFlags* parameter. |
| *uFlags* | Controls the interpretation of the uPosition parameter and the content, appearance, and behavior of the menu item. This parameter must include one of the following required values:<br>**MF_BYCOMMAND**: Indicates that the *uPosition* parameter gives the identifier of the menu item. The **MF_BYCOMMAND** flag is the default if neither the **MF_BYCOMMAND** nor **MF_BYPOSITION** flag is specified.<br>**MF_BYPOSITION**: 	Indicates that the *uPosition* parameter gives the zero-based relative position of the menu item. The parameter must also include at least one of the following values (see below). |
| *uIDNewItem* | The identifier of the modified menu item or, if the uFlags parameter has the **MF_POPUP** flag set, a handle to the drop-down menu or submenu. |
| *pNewItem* | The contents of the changed menu item. The interpretation of this parameter depends on whether the uFlags parameter includes the **MF_BITMAP**, **MF_OWNERDRAW**, or **MF_STRING** flag. |

| Flag  | Meaning |
| ----- | ------- |
| **MF_BITMAP** | A bitmap handle. |
| **MF_OWNERDRAW** | Contains an application-supplied value that can be used to maintain additional data related to the menu item. The value is in the **itemData** member of the structure pointed to by the *lParam* parameter of the **WM_MEASUREITEM** or **WM_DRAWITEM** message sent when the menu is created or its appearance is updated. |
| **MF_STRING** | A pointer to a null-terminated string (the default). |

#### Values for the *uFlags* parameter

| Flag  | Meaning |
| ----- | ------- |
| **MF_BITMAP** | Uses a bitmap as the menu item. The lpNewItem parameter contains a handle to the bitmap. |
| **MF_CHECKED** | Places a check mark next to the menu item. If the application provides check-mark bitmaps (see SetMenuItemBitmaps, this flag displays the check-mark bitmap next to the menu item. |
| **MF_DISABLED** | Disables the menu item so that it cannot be selected, but the flag does not gray it. |
| **MF_ENABLED** | Enables the menu item so that it can be selected, and restores it from its grayed state. |
| **MF_GRAYED** | Disables the menu item and grays it so that it cannot be selected. |
| **MF_MENUBARBREAK** | Functions the same as the **MF_MENUBREAK** flag for a menu bar. For a drop-down menu, submenu, or shortcut menu, the new column is separated from the old column by a vertical line. |
| **MF_MENUBREAK** | Places the item on a new line (for a menu bar) or in a new column (for a drop-down menu, submenu, or shortcut menu) without separating columns. |
| **MF_OWNERDRAW** | Specifies that the item is an owner-drawn item. Before the menu is displayed for the first time, the window that owns the menu receives a **WM_MEASUREITEM** message to retrieve the width and height of the menu item. The **WM_DRAWITEM** message is then sent to the window procedure of the owner window whenever the appearance of the menu item must be updated. |
| **MF_POPUP** | Specifies that the menu item opens a drop-down menu or submenu. The *uIDNewItem* parameter specifies a handle to the drop-down menu or submenu. This flag is used to add a menu name to a menu bar, or a menu item that opens a submenu to a drop-down menu, submenu, or shortcut menu. |
| **MF_SEPARATOR** | Draws a horizontal dividing line. This flag is used only in a drop-down menu, submenu, or shortcut menu. The line cannot be grayed, disabled, or highlighted. The *pwszNewItem* and *uIDNewItem* parameters are ignored. |
| **MF_STRING** | Specifies that the menu item is a text string; the lpNewItem parameter is a pointer to the string. |
| **MF_UNCHECKED** | Does not place a check mark next to the item (default). If the application supplies check-mark bitmaps (see **SetMenuItemBitmaps**), this flag displays the clear bitmap next to the menu item. |

---

### RemoveCloseOption

Removes the system menu close option and disables the X button.

```
FUNCTION RemoveCloseOption (BYVAL hWin AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Usage eample
```
DIM bRes AS BOOLEAN = CMenu.RemoveCloseOption
```
---

### RestoreCloseOption

Restores the system menu close option and enables Alt+F4 and the X button.

```
FUNCTION RestoreCloseOption (BYVAL hWin AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Usage eample
```
DIM bRes AS BOOLEAN = CMenu.RestoreCloseOption
```
---

### RightJustifyItem

Right justifies a top level menu item. This is usually used to have the Help menu item right-justified on the menu bar.

```
FUNCTION RightJustifyItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** method whenever a menu changes, whether or not the menu is in a displayed window. **RightJustifyItem** does this call internally.

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.RightJustifyItem(hMenu, ID_EXIT)
```
---

### SetContextHelpId

Associates a Help context identifier with a menu.

```
FUNCTION SetContextHelpId (BYVAL hMenu AS HMENU, BYVAL helpID AS DWORD) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu with which to associate the Help context identifier. |
| *helpID* | The help context identifier. |

#### Return value

Returns nonzero if successful, or zero otherwise.

To retrieve extended error information, call **GetLastError**.

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.SetContextHelpId(hMenu, 123)
```
---

### SetDefaultItem

Sets the default menu item for the specified menu.

```
FUNCTION SetDefaultItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu to set the default item for. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the **GetLastError** function.

#### Usage example
```
DIM bRes AS BOOLEAN = CMenu.SetDefaultItem(hMenu, IDM_NEW)
```
---

### SetInfo

Sets information for a specified menu.

```
FUNCTION SetInfo (BYVAL hMenu AS HMENU, BYVAL pmi AS MENUINFO PTR) AS BOOLEAN
FUNCTION SetInfo (BYVAL hMenu AS HMENU, BYREF mi AS MENUINFO) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to a menu. |
| *pmi* | A pointer to a **MENUINFO** structure for the menu.. |
| *mi* | A **MENUINFO** structure for the menu.. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

---

### SetItemBitmaps

Associates the specified bitmap with a menu item. Whether the menu item is selected or clear, the system displays the appropriate bitmap next to the menu item.

```
FUNCTION SetItemBitmaps (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL hBitmapUnchecked AS HBITMAP, BYVAL hBitmapChecked AS HBITMAP, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu containing the item to receive new check-mark bitmaps. |
| *item* | The identifier or position of the menu item to be changed. The meaning of this parameter depends on the value of *fByPosition*. |
| *hBitmapUnchecked* | A handle to the bitmap displayed when the menu item is not selected. |
| *hBitmapChecked* | A handle to the bitmap displayed when the menu item is selected. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call **GetLastError**.

#### Remarks

If either the *hBitmapUnchecked* or *hBitmapChecked* parameter is NULL, the system displays nothing next to the menu item for the corresponding check state. If both parameters are NULL, the system displays the default check-mark bitmap when the item is selected, and removes the bitmap when the item is not selected.

When the menu is destroyed, these bitmaps are not destroyed; it is up to the application to destroy them.

The selected and clear bitmaps should be monochrome. The system uses the Boolean AND operator to combine bitmaps with the menu so that the white part becomes transparent and the black part becomes the menu-item color. If you use color bitmaps, the results may be undesirable.

Use the **GetSystemMetrics** function with the **SM_CXMENUCHECK** and **SM_CYMENUCHECK** values to retrieve the bitmap dimensions.

#### Usage example
```
CMenu.CheckItem(hMenu, IDM_OPEN)
CMenu.SetItemBitmaps(hMenu, IDM_OPEN, NULL, NULL)
```
---

### SetItemInfo

Changes information about a menu item.

```
FUNCTION SetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, _
   BYVAL pmii AS MENUITEMINFOW PTR) AS BOOLEAN
FUNCTION SetItemInfo (BYVAL hMenu AS HMENU, BYVAL item AS UINT, BYVAL fByPositon AS BOOLEAN, _
   BYREF mii AS MENUITEMINFOW) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to a menu. |
| *item* | The identifier or position of the menu item to change. The meaning of this parameter depends on the value of *fByPositon*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |
| *pmii* | A pointer to a **MENUITEMINFOW** structure that contains information about the menu item and specifies which menu item attributes to change. |
| *mii* | A **MENUITEMINFOW** structure that contains information about the menu item and specifies which menu item attributes to change. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** function whenever a menu changes, whether the menu is in a displayed window. **SetItemInfo** does this call internally.

In order for keyboard accelerators to work with bitmap or owner-drawn menu items, the owner of the menu must process the **WM_MENUCHAR** message.

---

### SetItemText

Sets the text of the specified menu item.

```
FUNCTION SetItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYREF wszText AS WSTRING, _
    BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *wszText* | Text to set. |
| *fByPosition* | The meaning of uItem. If this parameter is FALSE, uItem is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** method whenever a menu changes, whether or not the menu is in a displayed window. **SetItemText** does this call internally.

#### Usage example

```
DIM bRes AS BOOLEAN = CMenu.SetItemText(hMenu, IDM_NEW, "New file")
```
---

### SetItemState

Sets the state of the specified menu item.

```
FUNCTION SetMenuItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fState AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fState* | The menu item state. It can be one or more of these values:<br>MFS_CHECKED: Checks the menu item.<br>MFS_DEFAULT: Specifies that the menu item is the default.<br>MFS_DISABLED: Disables the menu item and grays it so that it cannot be selected.<br>MFS_ENABLED: Enables the menu item so that it can be selected. This is the default state.<br>MFS_GRAYED: Disables the menu item and grays it so that it cannot be selected.<br>MFS_HILITE: Highlights the menu item.<br>MFS_UNCHECKED: Unchecks the menu item.<br>MFS_UNHILITE: Removes the highlight from the menu item. This is the default state. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** function whenever a menu changes, whether or not the menu is in a displayed window. **SetItemState** does this call internlly.

#### Usage example
```
CMenu.SetItemState(hMenu, IDM_OPEN, MFS_CHECKED)
```
---

### SetState

Sets the state of the specified menu item.

```
FUNCTION SetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fState AS UINT, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | | *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fState* | The menu item state. It can be one or more of these values:<br>MFS_CHECKED: Checks the menu item.<br>MFS_DEFAULT: Specifies that the menu item is the default.<br>MFS_DISABLED: Disables the menu item and grays it so that it cannot be selected.<br>MFS_ENABLED: Enables the menu item so that it can be selected. This is the default state.<br>MFS_GRAYED: Disables the menu item and grays it so that it cannot be selected.<br> MFS_HILITE: Highlights the menu item.<br>MFS_UNCHECKED Unchecks the menu item.<br>MFS_UNHILITE: Removes the highlight from the menu item. This is the default state. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** function whenever a menu changes, whether or not the menu is in a displayed window. **SetState** does this call internally.

#### Usage example
```
CMenu.SetState(hMenu, IDM_OPEN, MFS_CHECKED)
```
---

### ToggleCheckState

Toggles the checked state of a menu item.

```
FUNCTION ToggleCheckState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **CMenu.DrawBar** method whenever a menu changes, whether or not the menu is in a displayed window. **ToggleCheckState** does this call internally.

#### Usage example
```
CMenu.ToggleCheckState(hMenu, IDM_OPEN)
```
---

### ToggleItem

Toggles the checked state of a menu item.

```
FUNCTION ToggleItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *uItem* | The menu item whose check-mark attribute is to be set or unset. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

The return value specifies the previous state of the menu item (either **MF_CHECKED** or **MF_UNCHECKED**). If the menu item does not exist, the return value is –1.

#### Usage example
```
CMenu.ToggleItem(hMenu, IDM_OPEN)
```
---

### TrackPopupMenu

Displays a shortcut menu at the specified location and tracks the selection of items on the menu. The shortcut menu can appear anywhere on the screen.

```
FUNCTION TrackPopupMenu (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL x AS LONG, BYVAL y AS LONG, _
   BYVAL hwnd AS HWND, BYVAL prc AS RECT PTR = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the shortcut menu to be displayed. The handle can be obtained by calling **CMenu.CreatePopup** to create a new shortcut menu, or by calling **CMenu.GetSubMenu** to retrieve a handle to a submenu associated with an existing menu item. |
| *uFlags* | Use zero of more of these flags to specify function options (see below). |
| *x* | The horizontal location of the shortcut menu, in screen coordinates. |
| *y* | The vertical location of the shortcut menu, in screen coordinates. |
| *hWnd* | A handle to the window that owns the shortcut menu. This window receives all messages from the menu. The window does not receive a **WM_COMMAND** message from the menu until the function returns. If you specify **TPM_NONOTIFY** in the uFlags parameter, the function does not send messages to the window identified by *hWnd*. However, you must still pass a window handle in *hWnd*. It can be any window handle from your application. |
| *prc* | Ignored. |

Use one of the following flags to specify how the function positions the shortcut menu horizontally.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_CENTERALIGN** | Centers the shortcut menu horizontally relative to the coordinate specified by the x parameter. |
| **TPM_LEFTALIGN** | Positions the shortcut menu so that its left side is aligned with the coordinate specified by the x parameter. |
| **TPM_RIGHTALIGN** | Positions the shortcut menu so that its right side is aligned with the coordinate specified by the x parameter. |

Use one of the following flags to specify how the function positions the shortcut menu vertically.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_BOTTOMALIGN** | Positions the shortcut menu so that its bottom side is aligned with the coordinate specified by the y parameter. |
| **TPM_TOPALIGN** | Positions the shortcut menu so that its top side is aligned with the coordinate specified by the y parameter. |
| **TPM_VCENTERALIGN** | Centers the shortcut menu vertically relative to the coordinate specified by the y parameter. |

Use the following flags to control discovery of the user selection without having to set up a parent window for the menu.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_NONOTIFY** | The function does not send notification messages when the user clicks a menu item. |
| **TPM_RETURNCMD** | The function returns the menu item identifier of the user's selection in the return value. |

Use one of the following flags to specify which mouse button the shortcut menu tracks.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_LEFTBUTTON** | The user can select menu items with only the left mouse button. |
| **TPM_RIGHTBUTTON** | The user can select menu items with both the left and right mouse buttons. |

Use any reasonable combination of the following flags to modify the animation of a menu. For example, by selecting a horizontal and a vertical flag, you can achieve diagonal animation.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_HORNEGANIMATION** | Animates the menu from right to left. |
| **TPM_HORPOSANIMATION** | Animates the menu from left to right. |
| **TPM_NOANIMATION** | Displays menu without animation. |
| **TPM_VERNEGANIMATION** | Animates the menu from bottom to top. |
| **TPM_VERPOSANIMATION** | Animates the menu from top to bottom. |

For any animation to occur, the **SystemParametersInfo** function must set **SPI_SETMENUANIMATION**. Also, all the TPM_*ANIMATION flags, except **TPM_NOANIMATION**, are ignored if menu fade animation is on. For more information, see the **SPI_GETMENUFADE** flag in **SystemParametersInfo**.

Use the **TPM_RECURSE** flag to display a menu when another menu is already displayed. This is intended to support context menus within a menu.

For right-to-left text layout, use **TPM_LAYOUTRTL**. By default, the text layout is left-to-right.

#### Return value

If you specify **TPM_RETURNCMD** in the *uFlags* parameter, the return value is the menu-item identifier of the item that the user selected. If the user cancels the menu without making a selection, or if an error occurs, the return value is zero.

If you do not specify **TPM_RETURNCMD** in the *uFlags* parameter, the return value is nonzero if the function succeeds and zero if it fails. To get extended error information, call **GetLastError**.

---

### TrackPopupMenuEx

Displays a shortcut menu at the specified location and tracks the selection of items on the shortcut menu. The shortcut menu can appear anywhere on the screen.

```
FUNCTION TrackPopupMenuEx (BYVAL hMenu AS HMENU, BYVAL uFlags AS UINT, BYVAL x AS LONG, BYVAL y AS LONG, _
   BYVAL hwnd AS HWND, BYVAL ptpm AS TPMPARAMS PTR = NULL) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the shortcut menu to be displayed. The handle can be obtained by calling **CMenu.CreatePopup** to create a new shortcut menu, or by calling **CMenu.GetSubMenu** to retrieve a handle to a submenu associated with an existing menu item. |
| *uFlags* | Use zero of more of these flags to specify function options (see below). |
| *x* | The horizontal location of the shortcut menu, in screen coordinates. |
| *y* | The vertical location of the shortcut menu, in screen coordinates. |
| *hWnd* | A handle to the window that owns the shortcut menu. This window receives all messages from the menu. The window does not receive a **WM_COMMAND** message from the menu until the function returns. If you specify **TPM_NONOTIFY** in the uFlags parameter, the function does not send messages to the window identified by *hWnd*. However, you must still pass a window handle in *hWnd*. It can be any window handle from your application. |
| *ptpm* | A pointer to a **TPMPARAMS** structure that specifies an area of the screen the menu should not overlap. This parameter can be NULL. |

Use one of the following flags to specify how the function positions the shortcut menu horizontally.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_CENTERALIGN** | Centers the shortcut menu horizontally relative to the coordinate specified by the x parameter. |
| **TPM_LEFTALIGN** | Positions the shortcut menu so that its left side is aligned with the coordinate specified by the x parameter. |
| **TPM_RIGHTALIGN** | Positions the shortcut menu so that its right side is aligned with the coordinate specified by the x parameter. |

Use one of the following flags to specify how the function positions the shortcut menu vertically.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_BOTTOMALIGN** | Positions the shortcut menu so that its bottom side is aligned with the coordinate specified by the y parameter. |
| **TPM_TOPALIGN** | Positions the shortcut menu so that its top side is aligned with the coordinate specified by the y parameter. |
| **TPM_VCENTERALIGN** | Centers the shortcut menu vertically relative to the coordinate specified by the y parameter. |

Use the following flags to control discovery of the user selection without having to set up a parent window for the menu.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_NONOTIFY** | The function does not send notification messages when the user clicks a menu item. |
| **TPM_RETURNCMD** | The function returns the menu item identifier of the user's selection in the return value. |

Use one of the following flags to specify which mouse button the shortcut menu tracks.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_LEFTBUTTON** | The user can select menu items with only the left mouse button. |
| **TPM_RIGHTBUTTON** | The user can select menu items with both the left and right mouse buttons. |

Use any reasonable combination of the following flags to modify the animation of a menu. For example, by selecting a horizontal and a vertical flag, you can achieve diagonal animation.

| Value  | Meaaning |
| ------ | -------- |
| **TPM_HORNEGANIMATION** | Animates the menu from right to left. |
| **TPM_HORPOSANIMATION** | Animates the menu from left to right. |
| **TPM_NOANIMATION** | Displays menu without animation. |
| **TPM_VERNEGANIMATION** | Animates the menu from bottom to top. |
| **TPM_VERPOSANIMATION** | Animates the menu from top to bottom. |

For any animation to occur, the **SystemParametersInfo** function must set **SPI_SETMENUANIMATION**. Also, all the TPM_*ANIMATION flags, except **TPM_NOANIMATION**, are ignored if menu fade animation is on. For more information, see the **SPI_GETMENUFADE** flag in **SystemParametersInfo**.

Use the **TPM_RECURSE** flag to display a menu when another menu is already displayed. This is intended to support context menus within a menu.

For right-to-left text layout, use **TPM_LAYOUTRTL**. By default, the text layout is left-to-right.

#### Return value

If you specify **TPM_RETURNCMD** in the *uFlags* parameter, the return value is the menu-item identifier of the item that the user selected. If the user cancels the menu without making a selection, or if an error occurs, the return value is zero.

If you do not specify **TPM_RETURNCMD** in the *uFlags* parameter, the return value is nonzero if the function succeeds and zero if it fails. To get extended error information, call **GetLastError**.

---

### UncheckItem

Unchecks a menu item.

```
FUNCTION UncheckItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, BYVAL fByPosition AS LONG = FALSE) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

The return value specifies the previous state of the menu item (either **MF_CHECKED** or **MF_UNCHECKED**). If the menu item does not exist, the return value is -1.

#### Usage example

```
CMenu.UncheckItem(hMenu, IDM_OPEN)
```
---

## Examples

Builds a menu using `CWindow` and `CMenu`.

```
#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' // Menu identifiers
ENUM
   IDM_NEW = 1001     ' New file
   IDM_OPEN           ' Open file...
   IDM_SAVE           ' Save file
   IDM_SAVEAS         ' Save file as...
   IDM_EXIT           ' Exit

   IDM_UNDO = 2001    ' Undo
   IDM_CUT            ' Cut
   IDM_COPY           ' Copy
   IDM_PASTE          ' Paste

   IDM_TILEH = 3001   ' Tile hosizontal
   IDM_TILEV          ' Tile vertical
   IDM_CASCADE        ' Cascade
   IDM_ARRANGE        ' Arrange icons
   IDM_CLOSE          ' Close
   IDM_CLOSEALL       ' Close all
END ENUM

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CMenu.Create
   hPopUpMenu = CMenu.CreatePopup
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_OPEN, "&Open..." & CHR(9) & "Ctrl+O"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVEAS, "Save &As..."
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   hPopUpMenu = CMenu.CreatePopup
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Edit"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+Z"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CUT, "Cu&t" & CHR(9) & "Ctrl+X"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_COPY, "&Copy" & CHR(9) & "Ctrl+C"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_PASTE, "&Paste" & CHR(9) & "Ctrl+V"
   hPopUpMenu = CMenu.CreatePopup
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Window"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_TILEH, "&Tile Horizontal"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_TILEV, "Tile &Vertical"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CASCADE, "Ca&scade"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_ARRANGE, "&Arrange &Icons"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CLOSE, "&Close" & CHR(9) & "Ctrl+F4"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CLOSEALL, "Close &All"
   FUNCTION = hMenu

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
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Menu", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Creates the menu
   DIM hMenu AS HMENU = BuildMenu
   CMenu.SetMenu pWindow.hWindow, hMenu

   ' // Set the main window background color
   pWindow.SetBackColor(RGB_GOLD)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
            CASE IDM_NEW   ' IDM_OPEN, IDM_SAVE, etc.
               MessageBox hwnd, "New option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT
         RETURN 0

      CASE WM_DESTROY
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

### Menu with accelerators

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
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

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CMenu.Create
   hPopUpMenu = CMenu.CreatePopup
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+U"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_REDO, "&Redo" & CHR(9) & "Ctrl+R"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_HOME, "&Home" & CHR(9) & "Ctrl+H"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   FUNCTION = hMenu

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
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

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
   CMenu.SetMenu pWindow.hWindow, hMenu

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

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

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
```
---

### Menu with icons

```
'#RESOURCE "CW_Menu_Icons_01.rc"
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/AfxGdiPlus.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' // Menu identifiers
ENUM
   IDM_UNDO = 1001   ' Undo
   IDM_REDO          ' Redo
   IDM_HOME          ' Home
   IDM_SAVE          ' Save
   IDM_EXIT          ' Exit
END ENUM

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CMenu.Create
   hPopUpMenu = CMenu.CreatePopUp
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+U"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_REDO, "&Redo" & CHR(9) & "Ctrl+R"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_HOME, "&Home" & CHR(9) & "Ctrl+H"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   FUNCTION = hMenu

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
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Menu with icons", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Creates the menu
   DIM hMenu AS HMENU = BuildMenu
   CMenu.SetMenu pWindow.hWindow, hMenu

   ' // Add icons to the items of the File menu
   DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 0)
   CMenu.AddIconToItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInstance, "IDI_ARROW_LEFT_32"))
   CMenu.AddIconToItem(hSubMenu, 1, TRUE, AfxGdipIconFromRes(hInstance, "IDI_ARROW_RIGHT_32"))
   CMenu.AddIconToItem(hSubMenu, 2, TRUE, AfxGdipIconFromRes(hInstance, "IDI_HOME_32"))
   CMenu.AddIconToItem(hSubMenu, 3, TRUE, AfxGdipIconFromRes(hInstance, "IDI_SAVE_32"))

   ' // Set the main window background color
   pWindow.SetBackColor(RGB_OLDLACE)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
            CASE IDM_UNDO   ' IDM_UNDO, IDM_Redo, etc.
               MessageBox hwnd, "Undo option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT
         RETURN 0

      CASE WM_DESTROY
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

### Nested submenus

```
' ########################################################################################
' Microsoft Windows
' File: CW_Menu_NestedSubmenus_01.bas
' Contents: CWindow - Nested submenus
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#INCLUDE ONCE "AfxNova/CWindow.inc"
#INCLUDE ONCE "AfxNova/CMenu.inc"
#INCLUDE ONCE "AfxNova/AfxMenu.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

 
' // Menu identifiers
ENUM
   IDM_NEW = 1001     ' New file
   IDM_OPEN           ' Open file...
   IDM_SAVE           ' Save file
   IDM_SAVEAS         ' Save file as...
   IDM_EXIT           ' Exit

   IDM_UNDO = 2001    ' Undo
   IDM_CUT            ' Cut
   IDM_COPY           ' Copy
   IDM_PASTE          ' Paste

   IDM_TILEH = 3001   ' Tile hosizontal
   IDM_TILEV          ' Tile vertical
   IDM_CASCADE        ' Cascade
   IDM_ARRANGE        ' Arrange icons
   IDM_CLOSE          ' Close
   IDM_CLOSEALL       ' Close all
END ENUM

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CMenu.Create
   hPopUpMenu = CMenu.NewPopup
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_OPEN, "&Open..." & CHR(9) & "Ctrl+O"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_SAVEAS, "Save &As..."
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   hPopUpMenu = CMenu.CreatePopUp
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Edit"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+Z"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CUT, "Cu&t" & CHR(9) & "Ctrl+X"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_COPY, "&Copy" & CHR(9) & "Ctrl+C"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_PASTE, "&Paste" & CHR(9) & "Ctrl+V"
   hPopUpMenu = CMenu.CreatePopUp
      CMenu.Append hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Window"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_TILEH, "&Tile Horizontal"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_TILEV, "Tile &Vertical"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CASCADE, "Ca&scade"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_ARRANGE, "&Arrange &Icons"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CLOSE, "&Close" & CHR(9) & "Ctrl+F4"
         CMenu.Append hPopUpMenu, MF_ENABLED, IDM_CLOSEALL, "Close &All"
         CMenu.Append hPopUpMenu, MF_SEPARATOR, 0, ""

   ' // Nested menus
   DIM hSubPopUpMenu AS HMENU = CMenu.CreatePopUp
         CMenu.AddPopup hPopUpMenu, hSubPopUpMenu, MF_ENABLED, 4001, "Nested submenu 1"
         CMenu.Append hSubPopUpMenu, MF_ENABLED, 4002, "Nested submenu 1 item 1"
         CMenu.Append hSubPopUpMenu, MF_ENABLED, 4003, "Nested submenu 1 item 2"
         CMenu.Append hSubPopUpMenu, MF_SEPARATOR, 0, ""
   DIM hSubPopUpMenu2 AS HMENU = CMenu.CreatePopUp
         CMenu.AddPopup hSubPopUpMenu, hSubPopUpMenu2, MF_ENABLED, 5001, "Nested submenu 2"
         CMenu.Append hSubPopUpMenu2, MF_ENABLED, 5002, "Nested submenu 2 item 1"
         CMenu.Append hSubPopUpMenu2, MF_ENABLED, 5003, "Nested submenu 2 item 2"

   FUNCTION = hMenu

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
   ' // Enable visual styles without including a manifest file
   AfxEnableVisualStyles

   ' // Creates the main window
   DIM pWindow AS CWindow = "MyClassName"   ' Use the name you wish
   DIM hWin AS HWND = pWindow.Create(NULL, "CWindow - Menu", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 220)
   ' // Centers the window
   pWindow.Center

   ' // Creates the menu
   DIM hMenu AS HMENU = BuildMenu
   CMenu.SetMenu pWindow.hWindow, hMenu

   ' // Set the main window background color
   pWindow.SetBackColor(RGB_GOLD)

   ' // Adds a button
   pWindow.AddControl("Button", hWin, IDCANCEL, "&Close", 270, 155, 75, 30)
   ' // Anchors the button to the bottom and the right side of the main window
   pWindow.AnchorControl(IDCANCEL, AFX_ANCHOR_BOTTOM_RIGHT)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns –1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Sent when the user selects a command item from a menu, when a control sends a
      ' // notification message to its parent window, or when an accelerator keystroke is translated.
      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN SendMessageW(hwnd, WM_CLOSE, 0, 0)
            CASE IDM_NEW   ' IDM_OPEN, IDM_SAVE, etc.
               MessageBox hwnd, "New option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT
         RETURN 0

      CASE WM_DESTROY
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
