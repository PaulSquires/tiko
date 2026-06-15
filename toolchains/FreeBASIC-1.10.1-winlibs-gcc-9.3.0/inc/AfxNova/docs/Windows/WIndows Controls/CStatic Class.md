# CStatic Class

Applications often use static controls to label other controls or to separate a group of controls. Although static controls are child windows, they cannot be selected. Therefore, they cannot receive the keyboard focus and cannot have a keyboard interface. A static control that has the SS_NOTIFY style receives mouse input, notifying the parent window when the user clicks or double clicks the control. Static controls belong to the STATIC window class.

Although static controls can be used in overlapped, pop-up, and child windows, they are designed for use in dialog boxes, where the system standardizes their behavior. By using static controls outside dialog boxes, a developer increases the risk that the application might behave in a nonstandard fashion. Typically, a developer either uses static controls in dialog boxes or uses the SS_OWNERDRAW style to create customized static controls.

See: [About Static Controls](https://learn.microsoft.com/en-us/windows/win32/controls/about-static-controls)

**Include file**: CStatic.inc.

| Name | Description |
| ---- | ----------- |
| [DeleteBitmap](#deletebitmap) | Deletes a bitmap associated with a static control. |
| [DeleteCursor](#deletecursor) | Deletes a cursor associated with a static control. |
| [DeleteEnhancedMetafile](#deleteenhancedmetafile) | Deletes an enhanced metafile associated with a static control. |
| [DeleteIcon](#deleteicon) | Deletes an icon associated with a static control. |
| [DeleteImage](#deleteimage) | Deletes an image associated with a static control. |
| [Disable](#disable) | Disables the control. |
| [Enable](#enable) | Enables the control. |
| [GetIcon](#geticon) | Retrieves a handle to the icon associated with a static control that has the SS_ICON style. |
| [GetImage](#getimage) | Retrieves a handle to the image (icon or bitmap) associated with a static control. |
| [GetText](#getext) | Gets the text of a static control. |
| [GetTextLength](#getextlength) | Gets the length of the text of a static control. |
| [SetBitmap](#setbitmap) | Associates a bitmap with a static control. |
| [SetCursor](#setcursor) | Associates a cursor with a static control. |
| [SetEnhancedMetafile](#setenhancedmetafile) | Associates an enhanced metafile with a static control. |
| [SetIcon](#seticon) | Associates an icon with an static control. |
| [SetImage](#setimage) | Associates a new image with a static control. |
| [SetText](#settext) | Sets the text of a static control. |

---

### DeleteBitmap

Deletes a bitmap associated with a static control. Returns TRUE o FALSE.

```
FUNCTION DeleteBitmap (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.DeleteBitmap(hStatic)
```
---

### DeleteCursor

Deletes a cursor associated with a static control. Returns TRUE or FALSE.

```
FUNCTION DeleteCursor (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.DeleteCursor(hStatic)
```
---

### DeleteEnhancedMetafile

Deletes an enhanced metafile associated with a static control. Returns TRUE or FALSE.

```
FUNCTION DeleteEnhancedMetafile (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.DeleteEnhancedMetafile(hStatic)
```
---

### DeleteIcon

Deletes an icon associated with a static control. Returns TRUE o FALSE.

```
FUNCTION DeleteIcon (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.DeleteIcon(hStatic)
```
---

### DeleteImage

Deletes an image associated with a static control. Returns TRUE or FALSE.

```
FUNCTION DeleteImage (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.DeleteImage(hStatic)
```
---

### Disable

Disables the control. Returns False if the control was previous disabled; otherwise TRUE

```
FUNCTION Disable (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.Disable(hStatic)
```
---

### Enable

Enables the control. Returns False if the control was previous enabled; otherwise TRUE

```
FUNCTION Enable (BYVAL hStatic AS HWND) AS BOOLEAN
```

#### Usage example

```
CStatic.Enable(hStatic)
```
---

### GetIcon

Retrieves a handle to the icon associated with a static control that has the SS_ICON style.

```
FUNCTION GetIcon (BYVAL hStatic AS HWND) AS HICON
```

#### Usage example

```
DIM hIcon AS HICON = CStatic.GetIcon(hStatic)
```
---

### GetImage

Retrieves a handle to the image (icon or bitmap) associated with a static control. The return value is a handle to the image, if any; otherwise, it is NULL.

```
FUNCTION GetImage (BYVAL hStatic AS HWND) AS HICON
```

#### Usage example

```
DIM hImage AS HANDLE = CStatic.GetIcon(hStatic)
```
---

### GetText

Gets the text of a static control.

```
FUNCTION GetText (BYVAL hStatic AS HWND) AS DWSTRING
```

#### Usage example

```
DIM dwsText AS DWSTRING = CStatic.GetText(hStatic)
```
---

### GetTextLength

Gets the length of the text of a static control.

```
FUNCTION GetTextLength (BYVAL hStatic AS HWND) AS LONG
```

#### Usage example

```
DIM nLen AS LONG = CStatic.GetTextLength(hStatic)
```
---

### SetBitmap

Associates a bitmap with a static control. The return value is a handle to the image previously associated with the static control, if any; otherwise, it is NULL.

```
FUNCTION SetBitmap (BYVAL hStatic AS HWND, BYVAL hBmp AS HBITMAP) AS HBITMAP
```

| Parameter | Description |
| ------- | -------------- |
| *hBmp* | Handle of the bitmap to set. |

#### Usage example

```
DIM hOldBmp AS HBITMAP = CStatic.SetBitmap(hStatic, hBmp)
```
---

### SetCursor

Associates a cursor with a static control. The return value is a handle to the cursor previously associated with the static control.

```
FUNCTION SetCursor (BYVAL hStatic AS HWND, BYVAL hCur AS HCURSOR) AS HCURSOR
```

| Parameter | Description |
| ------- | -------------- |
| *hCur* | Handle of the cursor to set. |

#### Usage example

```
DIM hOldCur AS HCURSOR = CStatic.SetCursor(hStatic, hCur)
```
---

### SetEnhancedMetafile

Associates an enhanced metafile with a static control. The return value is a handle to the image previously associated with the static control, if any; otherwise, it is NULL.

```
FUNCTION SetEnhancedMetafile (BYVAL hStatic AS HWND, BYVAL hEMF AS HENHMETAFILE) AS HCURSOR
```

| Parameter | Description |
| ------- | -------------- |
| *hEMF* | Handle of the enhanced metafile to set. |

#### Usage example

```
DIM hOldEMF AS HENHMETAFILE = CStatic.SetCursor(hStatic, hEMF)
```
---

### SetIcon

Associates an icon with an static control. The return value is a handle to the icon previously associated with the static control, if any; otherwise, it is NULL.

```
FUNCTION SetIcon (BYVAL hStatic AS HWND, BYVAL hIcon AS HICON) AS HICON
```

| Parameter | Description |
| ------- | -------------- |
| *hIcon* | Handle of the icon to set. |

#### Usage example

```
DIM hOldIcon AS HICON = CStatic.SetIcon(hStatic, hIcon)
```
---

### SetImage

Associates a new image with a static control. The return value is a handle to the image previously associated with the static control, if any; otherwise, it is NULL.

```
FUNCTION SetIcon (BYVAL hStatic AS HWND, BYVAL nType AS LONG, BYVAL hImage AS HANDLE) AS HANDLE
```

| Parameter | Description |
| ------- | -------------- |
| *hStatic* | Handle of the static control. |
| *nType* | Type of the image to set. |
| *hImage* | Handle of the image to set. |

To associate an image with a static control, the control must have the proper style. The following table shows the style needed for each image type.

| Image type | Static control type |
| ---------- | ------------------- |
| **IMAGE_BITMAP** | SS_BITMAP |
| **IMAGE_CURSOR** | SS_ICON |
| **IMAGE_ENHMETAFILE** | SS_ENHMETAFILE |
| **IMAGE_ICON** | SS_ICON |

#### Usage example

```
DIM hOldBmp AS HICON = CStatic.SetImage(hStatic, IMAGE_BITMAP, hBmp)
DIM hOldIcon AS HICON = CStatic.SetImage(hStatic, IMAGE_ICON, hIcon)
DIM hOldCur AS HCURSOR = CStatic.SetImage(hStatic, IMAGE_CURSOR, hCur)
DIM hOldEMF AS HCURSOR = CStatic.SetImage(hStatic, IMAGE_ENHMETAFILE, hEMF)
```
---

### SetText

Sets the text of a static control.

```
FUNCTION SetText (BYVAL hStatic AS HWND, BYVAL pwszText AS WSTRING PTR) AS BOOLEAN
```

| Parameter | Description |
| ------- | -------------- |
| *hStatic* | Handle of the static control. |
| *pwszText* | The text to set. |

#### Usage example

```
CStatic.SetText(hStatic, "New text")
```
---
