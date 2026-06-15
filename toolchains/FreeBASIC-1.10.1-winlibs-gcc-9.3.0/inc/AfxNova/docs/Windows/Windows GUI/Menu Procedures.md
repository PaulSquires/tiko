# About Menus

A menu is a list of items that specify options or groups of options (a submenu) for an application. Clicking a menu item opens a submenu or causes the application to carry out a command. 

#### Menu Bars and Menus

A menu is arranged in a hierarchy. At the top level of the hierarchy is the *menu bar*; which contains a list of *menus*, which in turn can contain submenus. A menu bar is sometimaes called a *top-level menu*, and the menus and submenus are also known as *pop-up menus*.

A menu item can either carry out a command or open a submenu. An item that carries out a command is called a *command item* or a *command*.

An item on the menu bar almost always opens a menu. Menu bars rarely contain command items. A menu opened from the menu bar drops down from the menu bar and is sometimes called a *drop-down menu*. When a drop-down menu is displayed, it is attached to the menu bar. A menu item on the menu bar that opens a drop-down menu is also called a menu name.

The menu names on a menu bar represent the main categories of commands that an application provides. Selecting a menu name from the menu bar typically opens a menu whose menu items correspond to the commands in a category. For example, a menu bar might contain a File menu name that, when clicked by the user, activates a menu with menu items such as New, Open, and Save. To get information about a menu bar, call **GetMenuBarInfo**.

Only an overlapped or pop-up window can contain a menu bar; a child window cannot contain one. If the window has a title bar, the system positions the menu bar just below it. A menu bar is always visible. A submenu is not visible, however, until the user selects a menu item that activates it. For more information about overlapped and pop-up windows, see [Window Types](https://learn.microsoft.com/en-us/windows/win32/winmsg/window-features).

Each menu must have an owner window. The system sends messages to a menu's owner window when the user selects the menu or chooses an item from the menu.

#### Shortcut Menus

The system also provides shortcut menus. A shortcut menu is not attached to the menu bar; it can appear anywhere on the screen. An application typically associates a shortcut menu with a portion of a window, such as the client area, or with a specific object, such as an icon. For this reason, these menus are also called *context menus*.

A shortcut menu remains hidden until the user activates it, typically by right-clicking a selection, a toolbar, or a taskbar button. The menu is usually displayed at the position of the caret or mouse cursor.

#### The Window Menu

The **Window** menu (also known as the **System** menu or **Control** menu) is a pop-up menu defined and managed almost exclusively by the operating system. The user can open the window menu by clicking the application icon on the title bar or by right-clicking anywhere on the title bar.

The **Window** menu provides a standard set of menu items that the user can choose to change a window's size or position, or close the application. Items on the window menu can be added, deleted, and modified, but most applications just use the standard set of menu items. An overlapped, pop-up, or child window can have a window menu. It is uncommon for an overlapped or pop-up window not to include a window menu.

When the user chooses a command from the **Window menu**, the system sends a **WM_SYSCOMMAND** message to the menu's owner window. In most applications, the window procedure does not process messages from the window menu. Instead, it simply passes the messages to the **DefWindowProc** function for system-default processing of the message. If an application adds a command to the window menu, the window procedure must process the command.

An application can use the **GetSystemMenu** function to create a copy of the default window menu to modify. Any window that does not use the **GetSystemMenu** function to make its own copy of the window menu receives the standard window menu.

See more MSDN documentation at [About Menus](https://learn.microsoft.com/en-us/windows/win32/menurc/about-menus) and [Using Menus](https://learn.microsoft.com/en-us/windows/win32/menurc/using-menus)

---

## Examples

| Name       | Description |
| ---------- | ----------- |
| [CWindow Menu](#cwindowmenu) | Builds a menu using CWindow. |
| [CDialog Menu](#cdialogmenu) | Builds a menu using CDialog. |

---

## Windows API Menu Procedures

Menu functions provided by Windows.

See [Menu Functions](https://learn.microsoft.com/en-us/windows/win32/menurc/menu-functions)

| Name       | Description |
| ---------- | ----------- |
| **AppendMenu** | Appends a new item to the end of the specified menu bar, drop-down menu, submenu, or shortcut menu. |
| **CheckMenuItem** | Sets the state of the specified menu item's check-mark attribute to either selected or clear. |
| **CheckMenuRadioItem** | Checks a specified menu item and makes it a radio item. |
| **CreateMenu** | Creates a menu. |
| **CreatePopupMenu** | Creates a drop-down menu, submenu, or shortcut menu. |
| **DeleteMenu** | Deletes an item from the specified menu. |
| **DestroyMenu** | Destroys the specified menu and frees any memory that the menu occupies. |
| **DrawMenuBar** | Redraws the menu bar of the specified window. |
| **EnableMenuItem** | Enables, disables, or grays the specified menu item. |
| **EndMenu** | Ends the calling thread's active menu. |
| **GetMenu** | Retrieves a handle to the menu assigned to the specified window. |
| **GetMenuCheckMarkDimensions** | Retrieves the dimensions of the default check-mark bitmap. |
| **GetMenuDefaultItem** | Determines the default menu item on the specified menu. |
| **GetMenuInfo** | Retrieves information about a specified menu. |
| **GetMenuItemCount** | Determines the number of items in the specified menu. |
| **GetMenuItemID** | Retrieves the menu item identifier of a menu item located at the specified position in a menu. |
| **GetMenuItemInfo** | Retrieves information about a menu item. |
| **GetMenuItemRect** | Retrieves the bounding rectangle for the specified menu item. |
| **GetMenuState** | Retrieves the menu flags associated with the specified menu item. |
| **GetMenuString** | Copies the text string of the specified menu item into the specified buffer. |
| **GetSubMenu** | Retrieves a handle to the drop-down menu or submenu activated by the specified menu item. |
| **GetSystemMenu** |Enables the application to access the window menu (also known as the system menu or the control menu) for copying and modifying. |
| **HiliteMenuItem** | Adds or removes highlighting from an item in a menu bar. |
| **InsertMenu** | Inserts a new menu item into a menu, moving other items down the menu. |
| **InsertMenuItem** | Inserts a new menu item at the specified position in a menu. |
| **IsMenu** | Determines whether a handle is a menu handle. |
| **LoadMenu** | Loads the specified menu resource from the executable (.exe) file associated with an application instance. |
| **LoadMenuIndirect** | Loads the specified menu template in memory. |
| **MenuItemFromPoint** | Determines which menu item, if any, is at the specified location. |
| **ModifyMenu** | Changes an existing menu item. |
| **RemoveMenu** | Deletes a menu item or detaches a submenu from the specified menu. |
| **SetMenu** | Assigns a new menu to the specified window. |
| **SetMenuDefaultItem** | Sets the default menu item for the specified menu. |
| **SetMenuInfo** | Sets information for a specified menu. |
| **SetMenuItemBitmaps** | Associates the specified bitmap with a menu item. |
| **SetMenuItemInfo** | Changes information about a menu item. |
| **TrackPopupMenu** | Displays a shortcut menu at the specified location and tracks the selection of items on the menu. |
| **TrackPopupMenuEx** | Displays a shortcut menu at the specified location and tracks the selection of items on the shortcut menu. |

---

## SDK Style Menu Wrappers

Wwappers to add functionality or convenience of use to the above listed SDK functions.

| Name       | Description |
| ---------- | ----------- |
| [AfxAddIconToMenuItem](#afxaddicontomenuitem) | Converts an icon handle to a bitmap and adds it to the specified *hbmpItem* field of HMENU item. |
| [AfxCheckMenuItem](#afxcheckmenuitem) | Checks a menu item. |
| [AfxDestroyMenu](#afxdestroymenu) | Destroys a menu. |
| [AfxDestroyMenuBitmaps](#afxdestroymenubitmaps) | Destroys the bitmaps used by the menu, if any. |
| [AfxDisableMenuItem](#afxdisablemenuitem) | Disables the specified menu item. |
| [AfxEnableMenuItem](#afxenablemenuitem) | Enables the specified menu item. |
| [AfxGetMenuFont](#afxgetmenufont) | Retrieves information about the font used in menu bars. |
| [AfxGetMenuFontPointSize](#afxgetmenufontpointsize) | Retrieves the point size of the font used in menu bars. |
| [AfxGetMenuItemState](#afxgetmenuitemstate) | Retrieves the state of the specified menu item. |
| [AfxGetMenuItemText](#afxgetmenuitemtext) | Retrieves the text of the specified menu item. |
| [AfxGetMenuItemTextLen](#afxgetmenuitemtextlen) | Retrieves length of the of the specified menu item. |
| [AfxGetMenuRect](#afxgetmenurect) | Calculates the size of a menu bar or a drop-down menu. |
| [AfxGrayMenuItem](#afxgraymenuitem) | Grays the specified menu item. |
| [AfxHiliteMenuItem](#afxhilitemenuitem) | Highlights the specified menu item. |
| [AfxIsMenuItemChecked](#afxismenuitemchecked) | Returns TRUE if the specified menu item is checked; FALSE otherwise. |
| [AfxIsMenuItemDisabled](#afxismenuitemdisabled) | Returns TRUE if the specified menu item is disabled; FALSE otherwise. |
| [AfxIsMenuItemEnabled](#afxismenuitemenabled) | Returns TRUE if the specified menu item is enabled; FALSE otherwise. |
| [AfxIsMenuItemGrayed](#afxismenuitemgrayed) | Returns TRUE if the specified menu item is grayed; FALSE otherwise. |
| [AfxIsMenuItemHighlighted](#afxismenuitemhighlighted) | Returns TRUE if the specified menu item is highlighted; FALSE otherwise. |
| [AfxIsMenuItemOwnerdraw](#afxismenuitemownerdraw) | Returns TRUE if the specified menu item is a ownerdraw; FALSE otherwise. |
| [AfxIsMenuItemPopup](#afxismenuitempopup) | Returns TRUE if the specified menu item is a submenu; FALSE otherwise. |
| [AfxIsMenuItemSeparator](#afxismenuitemseparator) | Returns TRUE if the specified menu item is a separator; FALSE otherwise. |
| [AfxRemoveCloseMenu](#Afxremoveclosemenu) | Removes the system menu close option and disables the X button. |
| [AfxRightJustifyMenuItem](#afxrightjustifymenuitem) | Right justifies a top level menu item. |
| [AfxSetMenuItemBold](#afxsetmenuitembold) | Changes the text of a menu item to bold. |
| [AfxSetMenuItemState](#afxsetmenuitemstate) | Sets the state of the specified menu item. |
| [AfxSetMenuItemText](#afxsetmenuitemtext) | Sets the text of the specified menu item. |
| [AfxToggleMenuItem](#afxtogglemenuitem) | Toggles the checked state of a menu item. |
| [AfxUnCheckMenuItem](#afxuncheckmenuitem) | Unchecks a menu item. |

---

## DDT Style Menu Wrappers

These procedures replicate the PowerBASIC's menu procedures and add many more functionality using the same syntax. Contrarily to the *Afx menu* procedures, that use zero-based items, these ones are one-based.

| Name       | Description |
| ---------- | ----------- |
| [IsMenuHandle](#IsMenuHandle) | Determines whether a handle is a menu handle. |
| [IsMenuItemChecked](#ismenuitemchecked) | Returns TRUE if the specified menu item is checked; FALSE otherwise. |
| [IsMenuItemEnabled](#ismenuitemenabled) | Returns TRUE if the specified menu item is enabled; FALSE otherwise. |
| [IsMenuItemDisabled](#ismenuitemdisabled) | Returns TRUE if the specified menu item is disabled; FALSE otherwise. |
| [IsMenuItemGrayed](#ismenuitemgrayed) | Returns TRUE if the specified menu item is grayed; FALSE otherwise. |
| [IsMenuItemHighlighted](#ismenuitemghighlighted) | Returns TRUE if the specified menu item is grayed; FALSE otherwise. |
| [IsMenuItemSeparator](#ismenuitemseparator) | Returns TRUE if the specified menu item is a separator; FALSE otherwise. |
| [IsMenuItemOwnerdraw](#ismenuitemownerdraw) | Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise. |
| [IsMenuItemPopup](#ismenuitempopup) |Returns TRUE if the specified menu item is a submenu; FALSE otherwise. |
| [MenuAddBitmapToItem](#menuaddbitmaptoitem) | Adds a bitmap to the menu item. |
| [MenuAddIconToItem](#menuaddicontoitem) | Adds an icon to the menu item. |
| [MenuAddPopup](#menuaddpopup) | Adds a popup child menu to an existing menu. |
| [MenuAddString](#menuaddstring) | Adds a string or separator to an existing menu. |
| [MenuAttach](#menuattach) | Attaches a menu to a window or dialog. |
| [MenuBoldItem](#menubolditem) | Changes the text of a menu item to bold. |
| [MenuCheckItem](#menucheckitem) | Checks a menu item. |
| [MenuCheckRadioButton](#menucheckradiobutton) | ' Checks a specified menu item and makes it a radio item. At the same time, the function clears all other menu items in the associated group and clears the radio-item type flag for those items. |
| [MenuContext](#MenuContext) | Creates a floating context menu. |
| [MenuDelete](#menudelete) | Deletes a menu item from an existing menu. |
| [MenuDestroy](#menudestroy) | Destroys the main menu from the window or dialog. |
| [MenuDestroyBitmaps](#menudestroybitmaps) | Destroys the bitmaps used by menu. |
| [MenuDisableItem](#menudisableitem) | Disables the specified menu item. |
| [MenuDrawBar](#menudrawbar) | Redraws the menu bar of the specified window or dialog. |
| [MenuEnableItem](#menuenableitem) | Enables the specified menu item. |
| [MenuFindItemPosition](#menufinditemposition) | Finds the position of the specified menu item. |
| [MenuGetBarInfo](#menugetbarinfo) | Retrieves information about the specified menu bar. |
| [MenuGetCheckMarkHeight](#menugetcheckmarkheight) | Retrieves the height of the default check-mark bitmap. |
| [MenuGetContextHelpId](#menugetcontexthelpid) | Retrieves the Help context identifier associated with the specified menu. |
| [MenuGetCheckMarkWidth](#menugetcheckmarkwidth) | Retrieves the dimensions of the default check-mark bitmap. |
| [MenuGetDefaultItem](#menugetdefaultitem) | Determines the default menu item on the specified menu. |
| [MenuGetFont](#menugetfont) | Retrieves information about the font used in menu bars. |
| [MenuGetFontPointSize](#menugetfontpointsize) | Retrieves the point size of the font used in menu bars. |
| [MenuGetHandle](#menugethandle) | Retrieves a handle to the menu assigned to the specified window or dialog.  |
| [MenuGetItemCount](#menugetitemcount) | Determines the number of items in the specified menu. |
| [MenuGetItemFromPoint](#menugetitemfrompoint) | Determines which menu item, if any, is at the specified location. |
| [MenuGetItemID](#menugetitemid) | Retrieves the menu item ID of a menu item located at the specified position in a menu. |
| [MenuGetRect](#menugetrect) | Calculates the size of a menu bar or a drop-down menu. |
| [MenuGetState](#menugetstate) | Retrieves the state of the specified menu item. |
| [MenuGetSubMenu](#menugetsubmenu) | Retrieves a handle to the drop-down menu or submenu activated by the specified menu item. |
| [MenuGetSubmenusCount](#menugetsubmenuscount) | Get the number of submenus of a menu. |
| [MenuGetText](#menugettext) | Retrieves the text of the specified menu item. |
| [MenuGetTextLen](#menugettexlLen) | Returns the lengnth of the text of the specified menu item. |
| [MenuGetWindowOwner](#menugetwindowowner) | Retrieve the window owner of the specified menu. |
| [MenuGetSytemMenuHandle](#menugetsytemmenuhandle) | Enables the application to access the window menu (also known as the system menu or the control menu) for copying and modifying.  |
| [MenuGrayItem](#menugrayitem) | Disables the specified menu item. |
| [MenuHiliteItem](#menuhiliteitem) | Highlights the specified menu item. |
| [MenuItemToggleCheckState](#menuitemtogglecheckstate) | Retrieves the state of the specified menu item. |
| [MenuNewBar](#menunewbar) | Creates a new menu bar. |
| [MenuNewPopup](#menunewpopup) | Creates a new popup menu. |
| [MenuRemoveCloseOptiom](#menuremovecloseoptiom) | Removes the system menu close option and disables the X button. |
| [MenuRestoreCloseOption](#menurestorecloseoption) | Restores the system menu close option and enables Alt+F4 and the X button. |
| [MenuRightJustifyItem](#menurightjustifyitem) | Right justifies a top level menu item. This is usually used to have the Help menu item. |
| [MenuSetContextHelpId](#menusetcontexthelpid) | Associates a Help context identifier with a menu. |
| [MenuSetDefaultItem](#menusetdefaultitem) | Sets the default menu item for the specified menu. |
| [MenuSetItemBitmaps](#MenuSetItemBitmaps) | Associates the specified bitmap with a menu item. Whether the menu item is selected or clear, the system displays the appropriate bitmap next to the menu item. |
| [MenuSetState](#menusetstate) | Sets the state of the specified menu item. |
| [MenuSetText](#menusettext) | Retrieves the text of the specified menu item. |
| [MenuUnCheckItem](#menuuncheckitem) | Unchecks a menu item. |

---

### AfxAddIconToMenuItem

Converts an icon handle to a bitmap and adds it to the specified *hbmpItem field* of **HMENU** item.

```
FUNCTION AfxAddIconToMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS BOOLEAN, BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, _
   BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |
| *hIcon* | Handle of the icon to add to the menu. |
| *fAutoDestroy* | TRUE (the default) or FALSE. If TRUE, **AfxAddIconToMenuItem** destroys the icon before returning. |
| *phbmp* | Out. Location where the bitmap representation of the icon is stored. Can be NULL. |

#### Return value

TRUE or FALSE.

#### Remarks

The caller is responsible for destroying the bitmap generated. The icon will be destroyed if *fAutoDestroy* is set to true. The *hbmpItem* field of the menu item can be used to keep track of the bitmap by passing NULL to *phbmp*.

Using **AfxGdipAddIconFromFile** or **AfxGdipIconFromRes** to load the image from a file or resource and convert it to a icon you can use alphablended .png icons.

#### Usage example

Loading the icon from disc:

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
DIM hIcon AS HICON = LoadImageW(NULL, ExePath & "\undo_32.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE)
IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
```

Loading the icon from a resource file:

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
AfxAddIconToMenuItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInstance, "IDI_UNDO_32"))
```
---

### AfxCheckMenuItem

Checks a menu item.

```
FUNCTION AfxCheckMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

The return value specifies the previous state of the menu item (either MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.

---

### AfxDestroyMenu

Destroys the specified menu and frees any memory that the menu occupies.
The second overloaded function destroys the menu attached to a window or dialog.

```
FUNCTION AfxDestroyMenu (BYVAL hMenu AS HMENU) AS BOOLEAN
FUNCTION AfxDestroyMenu (BYVAL hwnd AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu to be destroyed. |

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window or dialog that owns the menu. |

#### Return value

A boolean true (-1) pr false (0).

---

### AfxDestroyMenuBitmaps

Destroys the bitmaps used by the menu.

```
SUB AfxDestroyMenuBitmaps (BYVAL hMenu AS HMENU)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu to be destroyed. |

#### Example

```
CASE WM_DESTROY
   ' // Destroy the menu and the bitmaps
   DIM hMenu AS HMENU = GetMenu(hwnd)
   AfxDestroyMenuBitmaps(hMenu)
   DestroyMenu(hMenu)              
```
---

### AfxDisableMenuItem

Disables the specified menu item.

```
FUNCTION AfxDisableMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS DWORD
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### AfxEnableMenuItem

Enables the specified menu item.

```
FUNCTION AfxEnableMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### AfxGetMenuFont

Retrieves information about the font used in menu bars.

```
FUNCTION AfxGetMenuFont (BYVAL plfw AS LOGFONTW PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *plfw* | Pointer to a LOGFONTW structure.

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

---

### AfxGetMenuFontPointSize

Retrieves the point size of the font used in menu bars.

```
FUNCTION AfxGetMenuFontPointSize () AS LONG
```

#### Return value

The point size of the font. If the function fails, the return value is 0.

---

### AfxGetMenuItemState

Retrieves the state of the specified menu item.

```
FUNCTION AfxGetMenuItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS DWORD
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
---

### AfxGetMenuItemText

Retrieves the text of the specified menu item.

```
FUNCTION AfxGetMenuItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Usage example

```
DIM dwsText AS DWSTRING = AfxGetMenuItemText(hMenu, 1, TRUE)
```
---

### AfxGetMenuItemTextLen

Returns the lengnth of the specified menu item.

```
FUNCTION AfxGetMenuItemTextLen (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxGetMenuRect

Returns the dimensions of a menu bar or a drop-down menu.

```
FUNCTION AfxGetMenuRect (BYVAL hwnd AS HWND, BYVAL hmenu AS HMENU) AS RECT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle of the window that owns the menu. |
| *hMenu* | Handle to the menu. |

---

### AfxGrayMenuItem

Grays the specified menu item.

```
FUNCTION AfxGrayMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### AfxHiliteMenuItem

Highlights the specified menu item.

```
FUNCTION AfxHiliteMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### AfxIsMenuItemChecked

Returns TRUE if the specified menu item is checked; FALSE otherwise.

```
FUNCTION AfxIsMenuItemChecked (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemDisabled

Returns TRUE if the specified menu item is disabled; FALSE otherwise.

```
FUNCTION AfxIsMenuItemDisabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemEnabled

Returns TRUE if the specified menu item is enabled; FALSE otherwise.

```
FUNCTION AfxIsMenuItemEnabled (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemGrayed

Returns TRUE if the specified menu item is grayed; FALSE otherwise.

```
FUNCTION AfxIsMenuItemGrayed (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemHighlighted

Returns TRUE if the specified menu item is highlighted; FALSE otherwise.

```
FUNCTION AfxIsMenuItemHighlighted (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemOwnerdraw

Returns TRUE if the specified menu item is a ownerdraw; FALSE otherwise.

```
FUNCTION AfxIsMenuItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemPopup

Returns TRUE if the specified menu item is a submenu; FALSE otherwise.

```
FUNCTION AfxIsMenuItemPopup (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxIsMenuItemSeparator

Returns TRUE if the specified menu item is a separator; FALSE otherwise.

```
FUNCTION AfxIsMenuItemSeparator (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

---

### AfxRemoveCloseMenu

Removes the system menu close option and disables the X button.

```
SUB AfxRemoveCloseMenu (BYVAL hwnd AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window that owns the menu. |

#### Return value

TRUE or FALSE.

---

### AfxRightJustifyMenuItem

Right justifies a top level menu item.

```
FUNCTION AfxRightJustifyMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window that owns the menu. |
| *uItem* | The zero-based position of the top level menu item to justify. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE.

#### Remarks

This is usually used to have the Help menu item right-justified on the menu bar.

---

### AfxSetMenuItemBold

Changes the text of a menu item to bold.

```
FUNCTION AfxSetMenuItemBold (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to the window that owns the menu. |
| *uItem* | The zero-based position of the top level menu item to bold. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE.

---

### AfxSetMenuItemState

Sets the state of the specified menu item.

```
FUNCTION AfxSetMenuItemState (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
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

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### AfxSetMenuItemText

Sets the text of the specified menu item.

```
FUNCTION AfxSetMenuItemText (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYREF wszText AS WSTRING, BYVAL fByPosition AS LONG = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *wszText* | The text to set. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **DrawMenuBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### AfxToggleMenuItem

Toggles the checked state of a menu item.

```
FUNCTION AfxToggleMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

The return value specifies the previous state of the menu item (either MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.

---

### AfxUnCheckMenuItem

Unchecks a menu item.

```
FUNCTION AfxUnCheckMenuItem (BYVAL hMenu AS HMENU, BYVAL uItem AS DWORD, _
   BYVAL fByPosition AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *uItem* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of *uItem*. If this parameter is FALSE, *uItem* is a menu item identifier. Otherwise, it is a menu item position. |

#### Return value

The return value specifies the previous state of the menu item (either MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.

---

### IsMenuHandle

Determines whether a handle is a menu handle.

```
FUNCTION IsMenuHandle (BYVAL hMenu AS HMENU) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified handle is a menu handle; FALSE otherwise.

---

### IsMenuItemChecked

Determines whether the specified menu item is checked.

```
FUNCTION IsMenuItemChecked (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is checked; FALSE otherwise.

---

### IsMenuItemEnabled

Determines whether the specified menu item is enabled.

```
FUNCTION IsMenuItemEnabled (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is enabled; FALSE otherwise.

---

### IsMenuItemDisabled

Determines whether the specified menu item is disabled.

```
FUNCTION IsMenuItemDisabled (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is disabled; FALSE otherwise.

---

### IsMenuItemGrayed

Determines whether the specified menu item is grayed.

```
FUNCTION IsMenuItemGrayed (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is grayed; FALSE otherwise.

---

### IsMenuItemHighlighted

Determines whether the specified menu item is highlighted.

```
FUNCTION IsMenuItemHighlighted (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is highlighted; FALSE otherwise.

---

### IsMenuItemSeparator

Determines whether the specified menu item is a separator.

```
FUNCTION IsMenuItemSeparator (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is a separator; FALSE otherwise.

---

### IsMenuItemOwnerdraw

Determines whether the specified menu item is ownerdraw.

```
FUNCTION IsMenuItemOwnerdraw (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise.

---

### IsMenuItemPopup

Determines whether the specified menu item is a popup item.

```
FUNCTION IsMenuItemPopup (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

#### Return value

Returns TRUE if the specified menu item is a popup item; FALSE otherwise.

---

### MenuAddIconToItem

Converts an icon to a bitmap and adds it to the specified hbmpItem field of HMENU item. The caller is responsible for destroying the bitmap generated. The icon will be destroyed if *fAutoDestroy* is set to true. The *hbmpItem* field of the menu item can be used to keep track of the bitmap by passing NULL to *phbmp*.

```
FUNCTION MenuAddIconToItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN, _
   BYVAL hIcon AS HICON, BYVAL fAutoDestroy AS BOOLEAN = TRUE, BYVAL phbmp AS HBITMAP PTR = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to change. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |
| *hicon* | Handle of the icon to add to the menu. |
| *fAutoDestroy* | TRUE (the default) or FALSE. If TRUE, **MenuAddIconToItem** destroys the icon before returning. |
| *phbmp* | Location where the bitmap representation of the icon is stored. Can be NULL. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

---

### MenuAddBitmapToItem

Adds a bitmap to the menu item.

```
FUNCTION MenuAddBitmapToItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN, BYVAL hbmp AS HBITMAP) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to change. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |
| *hbmp* | The bitmap handle. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### MenuAddPopup

Adds a popup child menu to an existing menu. A popup menu is a small window that "pops up" when a menu item is highlighted. This allows nesting, and gives the user an opportunity to choose from "sub-menu" items.

```
FUNCTION MenuAddPopup (BYVAL hMenu AS HMENU, BYREF wszText AS WSTRING, BYVAL hPopup AS HMENU, _
   BYVAL fState AS UINT, BYVAL item AS LONG = 0, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle of the parent menu which holds the popup. |
| *wszText* | Text displayed in the parent menu. An ampersand (&) may be used in the  to make the following letter into a control accelerator (hot-key). The letter appears underscored to signify that it is an accelerator. |
| *hPopup* | Handle of the child popup menu to be added. |
| *fState* | The initial state of the menu item. It can be one of the following:<br>MFS_DISABLED: Disable the item so that it cannot be selected.<br>%MFS_ENABLED:  Enable the item so that it can be selected. |
| *item* | If the option is included, *item* is a unique numeric identifier for this popup menu. *item* may be used later with a *fByPosition* option to reference this popup. *item* is an integral numeric value in the range of -32768 to +32767. |
| *fByPosition* | Indicates the position in the parent menu where the popup child menu is to be inserted. If the *fByPosition* option is used, the popup menu is inserted prior to the menu item specified by *item*. Otherwise, the popup menu is inserted at the physical position within the parent menu, where position = 1 for the first position, position = 2 for the second, and so on. If position is not specified then the popup menu is appended to the end of the menu. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### MenuAddString

Adds a string or separator to an existing menu. A string may contain an optional command accelerator key, and also describe an equivalent keyboard accelerator combination.

```
FUNCTION MenuAddString (BYVAL hMenu AS HMENU, BYREF wszText AS WSTRING, BYVAL id AS LONG, _
   BYVAL fState AS UINT, BYVAL item AS LONG = 0, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle of the parent menu to which the string should be added. |
| *wszText* | Text to display in the parent menu. An ampersand (&) may be used in the string to make the following letter into a command accelerator (hot-key). The letter is underscored to signify that it is an accelerator. To create a horizontal separator instead of a text string, set wszText = "-", id = 0, fState = 0. Keyboard accelerators can be indicated in the text of a menu item, for the reference of the user. To include a keyboard accelerator description in a menu string, separate it from the menu item text with a CHR(9) character. For example: MenuAddString hMenu, "Cu&t" & CHR(9) & "CTRL+X", id, fState. |
| *id* | The unique  identifier for the menu item. When a menu item is selected, *id* is sent to the parent dialog callback function to notify the dialog which option was selected. |
| *fState* | The initial state of the menu item. It can be one or more of the following, combined together with the OR operator to form a bitmask: <br>MFS_CHECKED: Place a checkmark next to the item.<br>MFS_DEFAULT: The default menu item, displayed in bold.  Only one item may be the default.<br>MFS_DISABLED: Disable the menu item so that it cannot be selected.<br>MFS_ENABLED: Enable the menu item so that it can be selected.<br>MFS_GRAYED: Disable the menu item so that it cannot be selected, and draw it in a "grayed" state to indicate this.<br>MFS_HILITE: Highlight the menu item.<br>MFS_UNCHECKED: Do not place a checkmark next to the item.<br>MFS_UNHILITE: Item is not highlighted.<br>A state value of zero (0) provides MFS_ENABLED, MFS_UNCHECKED, and MFS_UNHILITE. |
| *item* | Optional position in the parent menu, where the menu item should be inserted. If the *fByPosition* option is used, the menu item is inserted prior to the menu item identifier specified by *item*. Otherwise, the menu item is inserted at the physical position within the parent menu, where position = 1 for the first position, position = 2 for the second, and so on. If position is not specified then the popup menu is appended to the end of the menu. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Remarks

The application must call the **MenuDrawBar** statement whenever a menu changes, whether or not the menu is in a displayed dialog.

#### Usage examples
```
MenuAddString hPopup1, "&Open", ID_OPEN, MF_ENABLED
```
Insert the item before the ID_OPEN item
```
MenuAddString hPopup1, "&Exit", ID_EXIT, MF_ENABLED, 1, TRUE          ' insert by position
MenuAddString hPopup1, "&Exit", ID_EXIT, MF_ENABLED, ID_OPEN, FALSE   ' insert by identifier
```
---

### MenuAttach

Attaches a menu to a window or dialog.

```
FUNCTION MenuAttach (BYVAL hMenu AS HMENU, BYVAL hwnd AS HWND) AS BOOLEAN
```

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

#### Remarks

The Windows API function **SetMenu** performs the same action.

---

### MenuBoldItem

Changes the text of a menu item to bold.

```
FUNCTION MenuBoldItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### MenuCheckItem

Checks a menu item.

```
FUNCTION MenuCheckItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### MenuCheckRadioButton

Checks a specified menu item and makes it a radio item. At the same time, the function clears all other menu items in the associated group and clears the radio-item type flag for those items.

```
FUNCTION MenuCheckRadioButton (BYVAL hMenu AS HMENU, BYVAL first AS LONG, BYVAL last AS LONG, _
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
MenuCheckRadioButton(hMenu, ID_OPEN, ID_EXIT, ID_EXIT)      ' By item identifier
MenuCheckRadioButton(GetSubMenu(hMenu, 0), 1, 2, 2, TRUE)   ' By position
```
---

### MenuContext

Creates a floating context menu.

```
FUNCTION MenuContext (BYVAL hWin AS HWND, BYVAL hPopupMenu AS HMENU, BYVAL x AS LONG, _
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

### MenuDelete

Deletes a menu item from an existing menu.

```
FUNCTION MenuDelete (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### MenuDestroy

Destroys the main menu from the window or dialog.

```
FUNCTION MenuDestroy (BYVAL hWin AS HWND) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### MenuDestroyBitmaps

Destroys the bitmaps used by the menu.

```
SUB MenuDestroyBitmaps (BYVAL hMenu AS HMENU)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu to be destroyed. |

#### Example

```
CASE WM_DESTROY
   ' // Destroy the menu and the bitmaps
   DIM hMenu AS HMENU = GetMenu(hwnd)
   MenuDestroyBitmaps(hMenu)
   DestroyMenu(hMenu)              
```
---

### MenuDisableItem

Disables the specified menu item.

```
FUNCTION MenuDisableItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

#### Remaarks

The application must call the **MenuDrawBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### MenuDrawBar

Redraws the menu bar of the specified window or dialog. If the menu bar changes after the system has created the window or dialog, this function must be called to draw the changed menu bar.

```
FUNCTION MenuDrawBar (BYVAL hWin AS HWND) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

#### Remarks

This operation should be performed when a menu is altered dynamically after the dialog has been initially created, without regard to the visible state of the dialog.

---

### MenuEnableItem

Enables the specified menu item.

```
FUNCTION MenuEnableItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise. To get extended error information, use the **GetLastError** function.

#### Remaarks

The application must call the **MenuDrawBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### MenuFindItemPosition

Finds the position of the specified menu item.

```
FUNCTION MenuFindItemPosition (BYVAL hMenu AS HMENU, BYVAL itemID AS UINT, BYREF itemPos AS LONG) AS BOOLEAN
FUNCTION MenuFindItemPosition (BYVAL hMenu AS HMENU, BYVAL itemID AS UINT) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *itemID* | The identifier of the menu item. |
| *itemPos* | A variable of type LONG that received the item position. |

#### Return value

The first overloaded function returns TRUE if the function succeeds; FALSE otherwise.

The second overloaded function returns the item position, or zero if it is not found.

To get extended error information, use the **GetLastError** function.

---

### MenuGetBarInfo

Retrieves information about the specified menu bar.

```
FUNCTION MenuGetBarInfo (BYVAL hWin AS HWND, BYVAL idObject AS LONG, BYVAL idItem AS LONG) AS MENUBARINFO
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window or dialog that owns the menu bar. |
| *idObject* | The menu object. This parameter can be one of the following values:<br>OBJID_CLIENT: &hFFFFFFFC - The popup menu associated with the window.<br>OBJID_MENU: &hFFFFFFFD - The menu bar associated with the window<br>OBJID_SYSMENU: &hFFFFFFFF - The system menu associated with the window |
| *idItem* | The item for which to retrieve information. If this parameter is zero, the function retrieves information about the menu itself. If this parameter is 1, the function retrieves information about the first item on the menu, and so on. |

#### Return value

A **MENUBARINFO** structure.

---

### MenuGetCheckMarkHeight

Retrieves the height of the default check-mark bitmap. The system displays this bitmap next to selected menu items. Before calling the **MenuSetItemBitmaps** function to replace the default check-mark bitmap for a menu item, an application must determine the correct bitmap size by calling **MenuGetCheckMarkWidth** and **MenuGetCheckMarkHeight**.

```
FUNCTION MenuGetCheckMarkHeight () AS LONG
```

#### Return value

Returns the height of the default check-mark bitmap.

---

### MenuGetCheckMarkWidth

Retrieves the width of the default check-mark bitmap. The system displays this bitmap next to selected menu items. Before calling the **MenuSetItemBitmaps** function to replace the default check-mark bitmap for a menu item, an application must determine the correct bitmap size by calling **MenuGetCheckMarkWidth** and **MenuGetCheckMarkHeight**.

```
FUNCTION MenuGetCheckMarkWidth () AS LONG
```

#### Return value

Returns the width of the default check-mark bitmap.

---

### MenuGetContextHelpId

Retrieves the Help context identifier associated with the specified menu.

```
FUNCTION MenuGetCheckMarkHeight () AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu for which the Help context identifier is to be retrieved. |

#### Return value

Returns the Help context identifier if the menu has one, or zero otherwise.

---

### MenuGetDefaultItem

Determines the default menu item on the specified menu.

```
FUNCTION MenuGetDefaultItem (BYVAL hMenu AS HMENU, BYVAL gmdiFlags AS UINT = 0, BYVAL fByPosition AS BOOLEAN = TRUE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu for which to retrieve the default menu item. |
| *gmdiFlags* | Indicates how the function should search for menu items. This parameter can be zero or more of the following values.<br>GMDI_GOINTOPOPUPS &H0002 : If the default item is one that opens a submenu, the function is to search recursively in the corresponding submenu. If the submenu has no default item, the return value identifies the item that opens the submenu. By default, the function returns the first default item on the specified menu, regardless of whether it is an item that opens a submenu.<br>GMDI_USEDISABLED &h0001: The function is to return a default item, even if it is disabled. By default, the function skips disabled or grayed items. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

If the function succeeds, the return value is the identifier or position of the menu item. If the function fails, the return value is 0. To get extended error information, call **GetLastError**.

---

### MenuGetFont

Retrieves information about the font used in menu bars.

```
FUNCTION MenuGetFont () AS LOGFONTW
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu for which to retrieve the default menu item. |

#### Return value

A **LOGFONTW** structure that contains information about the font used in menu bars.

---

### MenuGetFontPointSize

Retrieves the point size of the font used in menu bars.

```
FUNCTION MenuGetFontPointSize () AS LONG
```

#### Return value

The point size of the font used in menu bars. If the function fails, the return value is 0.

---

### MenuGetHandle

Retrieves a handle to the menu assigned to the specified window or dialog. 

```
FUNCTION MenuGetHandle (BYVAL hWin AS HWND) AS HMENU
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window or dialog whose menu handle is to be retrieved. |

#### Return value

The return value is a handle to the menu. If the specified window has no menu, the return value is NULL. If the window is a child window, the return value is undefined.

#### Remarks

**MenuGetHandle** does not work on floating menu bars. Floating menu bars are custom controls that mimic standard menus; they are not menus. To get the handle on a floating menu bar, use the Active Accessibility APIs. The Windows API **GetMenu** function can be used instead of **MenuGetHandle**.

---

### MenuGetItemCount

Determines the number of items in the specified menu.

```
FUNCTION MenuGetItemCount (BYVAL hMenu AS HMENU) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu to be examined. |

#### Return value

If the function succeeds, the return value specifies the number of items in the menu.

If the function fails, the return value is -1. To get extended error information, call **GetLastError**.

---

### MenuGetItemFromPoint

Determines which menu item, if any, is at the specified location.

```
FUNCTION MenuGetItemFromPoint (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU, BYVAL ptScreen AS POINT) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | A handle to the window containing the menu. If this value is NULL and the hMenu parameter represents a popup menu, the function will find the menu window. |
| *hMenu* | A handle to the menu containing the menu items to hit test. |
| *ptScreen* | A structure that specifies the location to test. If *hMenu* specifies a menu bar, this parameter is in window coordinates. Otherwise, it is in client coordinates. |

#### Return value

Returns the zero-based position of the menu item at the specified location or -1 if no menu item is at the specified location.

---

### MenuGetItemID

Retrieves the menu item ID of a menu item located at the specified position in a menu.

```
FUNCTION MenuGetItemID (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS UINT
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the item whose identifier is to be retrieved. |
| *nPos* | The one-based relative position of the menu item whose identifier is to be retrieved. |

#### Return value

The return value is the identifier of the specified menu item. If the menu item identifier is NULL or if the specified item opens a submenu, the return value is -1.

---

### MenuGetRect

Calculates the size of a menu bar or a drop-down menu.

```
FUNCTION FUNCTION MenuGetRect (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU, BYVAL prcmenu AS RECT PTR) AS LONG
FUNCTION MenuGetRect (BYVAL hWin AS HWND, BYVAL hmenu AS HMENU) AS RECT
```
| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the windowor dialog  that owns the menu. If this value is NULL and the *hMenu* parameter represents a popup menu, the function will find the menu window. |
| *hmenu* | The one-based relative position of the menu item whose identifier is to be retrieved. |
| *prcmenu* | A pointer to a **RECT** structure that receives the bounding rectangle of the specified menu item expressed in screen coordinates. |

#### Return value

If the function succeeds, the return value is 0. If the function fails, the return value is a system error code.

The second overloaded function returns a **RECT** structure directly.

---

### MenuGetState

Retrieves the state of the specified menu item.

```
FUNCTION MenuGetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS UINT
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

### MenuGetSubMenu

Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.

```
FUNCTION MenuGetSubMenu (BYVAL hMenu AS HMENU, BYVAL nPos AS LONG) AS HMENU
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |
| *nPos* | The one-based relative position of the menu item whose identifier is to be retrieved. |

#### Return value

If the function succeeds, the return value is a handle to the drop-down menu or submenu activated by the menu item. If the menu item does not activate a drop-down menu or submenu, the return value is NULL.

---

### MenuGetSubmenusCount

Retrieves the number of submenus of a menu.

```
FUNCTION MenuGetSubmenusCount(BYVAL hMenu AS HMENU) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |

#### Return value

The number of submenus.

---

### MenuGetText

Retrieves the text of the specified menu item.

```
FUNCTION MenuGetText (BYVAL hMenu AS HMENU, BYVAL item AS LONG, B_
   YVAL fByPosition AS BOOLEAN = FALSE) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

The retrieved text.

---

### MenuGetTextLen

Returns the lengnth of the text of the specified menu item.

```
FUNCTION MenuGetTextLen (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

The length of the text.

---

### MenuGetWindowOwner

Retrieves the window owner of the specified menu

```
FUNCTION MenuGetWindowOwner (BYVAL hMenu AS HMENU) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |

#### Return value

The handle of the window that owns the menu.

---

### MenuGetWindowOwner

Retrieves the window owner of the specified menu.

```
FUNCTION MenuGetWindowOwner (BYVAL hMenu AS HMENU) AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |

#### Return value

The handle of the window that owns the menu.

---

### MenuGetSystemMenuHandle

Retrieves the system menu handle.

```
FUNCTION MenuGetSystemMenuHandle (BYVAL hwnd AS HWND, BYVAL bRevert AS BOOLEAN = FALSE) AS HMENU
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu. |
| *bRevert* | The action to be taken. If this parameter is FALSE, **MenuGetSystemMenuHandle** returns a handle to the copy of the window menu currently in use. The copy is initially identical to the window menu, but it can be modified. If this parameter is TRUE, **MenuGetSystemMenuHandle** resets the window menu back to the default state. The previous window menu, if any, is destroyed. |

#### Return value

If the *bRevert* parameter is FALSE, the return value is a handle to a copy of the window menu. If the *bRevert* parameter is TRUE, the return value is NULL.

---

### MenuGrayItem

Grays the specified menu item.

```
FUNCTION MenuGrayItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
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

The application must call the **MenuDrawBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### MenuHiliteItem

Highlights the specified menu item.

```
FUNCTION MenuHiliteItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
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

The application must call the **MenuDrawBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### MenuItemToggleCheckState

Toggles the checked state of a menu item.

```
PRIVATE FUNCTION MenuItemToggleCheckState (BYVAL hMenu AS HMENU, _
   BYVAL item AS LONG, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Remarks

The application must call the **MenuDrawBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### MenuNewBar

Creates a menu.

```
FUNCTION MenuNewBar () AS HMENU
```

#### Return value

If the function succeeds, the return value is a handle to the newly created menu.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Remarks

Instead of **MenuNewBar** you can call the Windows API function **CreateMenu**.

---

### MenuNewPopup

Creates a drop-down menu, submenu, or shortcut menu.

```
FUNCTION MenuNewPopup () AS HMENU
```

#### Return value

If the function succeeds, the return value is a handle to the newly created menu.

If the function fails, the return value is NULL. To get extended error information, call **GetLastError**.

#### Remarks

Instead of **MenuNewPopup** you can call the Windows API function **CreatePopupMenu**.

---

### MenuRemoveCloseOptiom

Removes the system menu close option and disables the X button.

```
FUNCTION MenuRemoveCloseOptiom (BYVAL hWin AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

---

### MenuRestoreCloseOptiom

Restores the system menu close option and enables Alt+F4 and the X button.

```
FUNCTION MenuRestoreCloseOption (BYVAL hWin AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

---

### MenuRightJustifyItem

Right justifies a top level menu item. This is usually used to have the Help menu item right-justified on the menu bar.

```
FUNCTION MenuRightJustifyItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hWin* | Handle of the window or dialog that owns the menu. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

#### Usage example
```
MenuRightJustifyItem(hMenu, ID_EXIT)
```
---

### MenuSetContextHelpId

Associates a Help context identifier with a menu.

```
FUNCTION MenuSetContextHelpId (BYVAL hMenu AS HMENU, BYVAL helpID AS DWORD) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu with which to associate the Help context identifier. |
| *helpID* | The help context identifier. |

#### Return value

Returns nonzero if successful, or zero otherwise.

To retrieve extended error information, call **GetLastError**.

---

### MenuSetDefaultItem

Sets the default menu item for the specified menu.

```
FUNCTION MenuSetDefaultItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = TRUE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu to set the default item for. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the **GetLastError** function.

---

### MenuSetItemBitmaps

Associates the specified bitmap with a menu item. Whether the menu item is selected or clear, the system displays the appropriate bitmap next to the menu item.

```
FUNCTION MenuSetItemBitmaps (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
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

---

### MenuSetState

Sets the state of the specified menu item.

```
FUNCTION MenuSetState (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
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

The application must call the **MenuDrawBar** function whenever a menu changes, whether or not the menu is in a displayed window.

---

### MenuSetText

Sets the text of the specified menu item.

```
FUNCTION MenuSetText (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYREF wszText AS WSTRING, BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | A handle to the menu that contains the menu item. |
| *item* | | *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *wszText* | The text to set. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

TRUE or FALSE. To get extended error information, use the **GetLastError** function.

---

### MenuUnCheckItem

Unchecks a menu item.

```
FUNCTION MenuUnCheckItem (BYVAL hMenu AS HMENU, BYVAL item AS LONG, _
   BYVAL fByPosition AS BOOLEAN = FALSE) AS BOOLEAN
```
| Parameter  | Description |
| ---------- | ----------- |
| *hMenu* | Handle to the menu that contains the menu item. |
| *item* | The identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of *fByPosition*. |
| *fByPosition* | The meaning of item. If this parameter is FALSE, *item* is a menu item identifier. Otherwise, it is a menu item position, where position = 1 for the first position, position = 2 for the second, and so on. |

#### Return value

Returns TRUE if the function succeeds; FALSE otherwise.

---

### <a name="cwindowmenu"></a>CWindow Menu

Builds a menu using `CWindow`and the Windows API.

```
#define UNICODE
#define _WIN32_WINNT &h0602
#INCLUDE ONCE "AfxNova/CWindow.inc"
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

   hMenu = CreateMenu
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_NEW, "&New" & CHR(9) & "Ctrl+N"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_OPEN, "&Open..." & CHR(9) & "Ctrl+O"
         AppendMenuW hPopUpMenu, MF_SEPARATOR, 0, ""
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_SAVEAS, "Save &As..."
         AppendMenuW hPopUpMenu, MF_SEPARATOR, 0, ""
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Edit"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+Z"
         AppendMenuW hPopUpMenu, MF_SEPARATOR, 0, ""
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_CUT, "Cu&t" & CHR(9) & "Ctrl+X"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_COPY, "&Copy" & CHR(9) & "Ctrl+C"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_PASTE, "&Paste" & CHR(9) & "Ctrl+V"
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&Window"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_TILEH, "&Tile Horizontal"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_TILEV, "Tile &Vertical"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_CASCADE, "Ca&scade"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_ARRANGE, "&Arrange &Icons"
         AppendMenuW hPopUpMenu, MF_SEPARATOR, 0, ""
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_CLOSE, "&Close" & CHR(9) & "Ctrl+F4"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_CLOSEALL, "Close &All"
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
   SetMenu pWindow.hWindow, hMenu

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

Builds a menu and a keyboard accelerator table using `CWindow`.

```
#define UNICODE
#define _WIN32_WINNT &h0602
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

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

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
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   AfxSetProcessDPIAware

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
```
---

### <a name="cdialogmenu"></a>CDialog Menu

Builds a menu using `CDialog`and the DDT wrappers.

```
#define UNICODE
#define _WIN32_WINNT &h0602
#include once "AfxNova/DDT.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

DECLARE FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR

CONST ID_OPEN = 401
CONST ID_EXIT = 402
CONST ID_OPTION1 = 403
CONST ID_OPTION2 = 404
CONST ID_HELP = 405
CONST ID_ABOUT = 406

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu (BYVAL hDlg AS HWND) AS HMENU
   DIM lResult AS LONG

   ' ** First create a top-level menu:
   DIM hMenu AS HMENU = MenuNewBar

   ' ** Add a top-level menu item with a popup menu:
   DIM hPopup1 AS HMENU = MenuNewPopup
   MenuAddPopup hMenu, "&File", hPopup1, MF_ENABLED
   MenuAddString hPopup1, "&Open", ID_OPEN, MF_ENABLED
   MenuAddString hPopup1, "&Exit", ID_EXIT, MF_ENABLED
   MenuAddString hPopup1, "-", 0, 0

   ' ** Now we can add another item to the menu that will bring up a sub-menu. 
   ' First we obtain a new popup menu handle to distinguish it from the first 
   ' popup menu:
   DIM hPopup2 AS HMENU = MenuNewPopup

   ' ** Now add a new menu item to the first menu. 
   ' This item will bring up the sub-menu when selected:
   MenuAddPopup hPopup1, "&More Options", hPopup2, MF_ENABLED

   ' ** Now we will define the sub menu:
   MenuAddString hPopup2, "Option &1", ID_OPTION1, MF_ENABLED
   MenuAddString hPopup2, "Option &2", ID_OPTION2, MF_ENABLED

   ' ** Finally, we'll add a second top-level menu and popup.
   ' For this popup, we can reuse the first popup variable:
   hPopup1 = MenuNewPopup
   MenuAddPopup hMenu, "&Help", hPopup1, MF_ENABLED
   MenuAddString hPopup1, "&Help", ID_HELP, MF_ENABLED
   MenuAddString hPopup1, "-", 0, 0
   MenuAddString hPopup1, "&About", ID_ABOUT, MF_ENABLED
   
   ' Attach the menu to the dialog
   MenuAttach hMenu, hDlg

   ' // Bold the Exit menu item
   MenuBoldItem(hMenu, ID_EXIT)
   ' // Right justify the Help menu
'   MenuRightJustifyItem(hMenu, 1)

   RETURN hMenu
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

   ' // Create a new dialog using dialog units
   DIM hDlg AS HWND = DialogNew(0, "DDT with FreeBasic - Menu Demo",50, 50, 175, 75, WS_OVERLAPPEDWINDOW OR DS_CENTER)

   ' // Add controls to the dialog
   ControlAdd "GroupBox", hDlg, 101, "Just a simple question", 5, 5, 160, 55
   ControlAdd "Label", hDlg, 102, "What's your name ?", 10, 20, 80, 10
   ControlAdd "Edit", hDlg, 103, "", 90, 19, 70, 12
   ControlAdd("Button", hDlg, 104, "&Ok", 80, 40, 50, 12, BS_DEFPUSHBUTTON)

   ' // Build and attach a menu
   DIM hMenu AS HMENU = BuildMenu(hDlg)

   ' // Create a keyboard accelerator table
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "O", ID_OPEN  ' // Ctrl+O - Open
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "H", ID_HELP  ' // Ctrl+H - Help
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "E", ID_EXIT  ' // Ctrl+E - Exit
   AddAccelerator hDlg, FVIRTKEY OR FCONTROL, "A", ID_ABOUT ' // Ctrl+A - About
   CreateAccelTable(hDlg)

   ' // Display and activate the dialog as modal
   DialogShowModal(hDlg, @DlgProc)

'   ' // Display and activate the dialog as modeless
'   DialogShowModeless(@DlgProc)

'   ' // Message handler loop
'   DO
'      pDlg.DialogDoEvents
'   LOOP WHILE IsWindow(hDlg)

   RETURN DialogEndResult(hDlg)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Dialog callback procedure
' ========================================================================================
FUNCTION DlgProc (BYVAL hDlg AS HWND, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LPARAM) AS INT_PTR
   
   SELECT CASE uMsg

      CASE WM_INITDIALOG
         RETURN TRUE

      CASE WM_COMMAND
         SELECT CASE CBCTL(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hDlg, WM_CLOSE, 0, 0
               END IF
            CASE 104 'IDOK
               DIM dws AS DWSTRING = AfxGetWindowText(GetDlgItem(hDlg, 103))
               IF LEN(dws) THEN MsgBox("Your name is " & dws, MB_ICONINFORMATION OR MB_TASKMODAL, "Answer")
               IF LEN(dws) = 0 THEN MsgBox("Hmm ...", MB_ICONEXCLAMATION OR MB_TASKMODAL, "No answer")
           CASE ID_OPEN TO ID_ABOUT
               MsgBox("WM_COMMAND received from a menu item!", MB_TASKMODAL, "Test menu")
         END SELECT

      CASE WM_CLOSE
         ' // End the application
         DialogEnd(hDlg)

   END SELECT

   RETURN FALSE

END FUNCTION
```
---
