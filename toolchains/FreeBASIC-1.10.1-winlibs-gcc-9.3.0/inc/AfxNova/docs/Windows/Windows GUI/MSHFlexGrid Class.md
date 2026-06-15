# Microsoft Hierarchical Grid

The Microsoft Hierarchical FlexGrid (`MSHFlexGrid`) control displays and operates on tabular data. It allows complete flexibility to sort, merge, and format tables containing strings and pictures. When bound to a data control, `MSHFlexGrid` displays read-only data.

#### Remarks

You can place text, a picture, or both in any cell of an `MSHFlexGrid`. The **Row** and **Col** properties specify the current cell in an `MSHFlexGrid`. You can specify the current cell using code, or the user can change it atrun time using the mouse or the arrow keys. The **Text** property references the contents of the current cell.

If the text in a cell is too long to display in the cell, and the **WordWrap** property is set to **True**, the text wraps to the next line within the same cell. To display the wrapped text, you may need to increase the cell’s column width (**ColWidth** property) or row height (**RowHeight** property).

Use the **Col** and **Row** properties to determine the number of columns and rows in an `MSHFlexGrid`. Use the **Band** properties to determine the band styles in an `MSHFlexGrid`.

#### Displaying Hierarchical Recordsets

A major feature of the `MSHFlexGrid` control is its ability to display hierarchical recordsets—relational tables displayed in a hierarchical fashion. The easiest way to create a hierarchical recordset is to create an ADO recordset and assign its **DataSource** property to the **DataSource** property of the MSHFlexGrid control. You can also create a hierarchical recordset in code using the **MSDataShape** provider and the SQL' **SHAPE** command to generate the recordset:

```
' Create a ConnectionString.
Dim dwsConStr As DWString
dwsConStr = "Provider=MSDataShape.1;Data Source=Nwind;" & _
"Connect Timeout=15;Data Provider=MSDASQL"

' Create a Shape command.
Dim dwsShape As DWString
dwShape = "SHAPE {SELECT * FROM `Customers`}  AS Customers " & _
"APPEND ({SELECT * FROM `Orders`}  AS Orders RELATE " & _
"CustomerID TO CustomerID) AS Orders"

' Assign the ConnectionString to an ADO Data Control's
' ConnectionString property, and the Shape command to the 
' control's RecordSource property.
 adodc.ConnectionString = dwsConStr
 adodc.RecordSource = dwsShape

' Set the HflexGrid control's DataSource property to the 
' ADO Data control.
grid.DataSource = adodc
```

### Constructor of the class

| Name       | Description |
| ---------- | ----------- |
| [Constructor](#constructor) | Attaches an instance of the MSHFlexGrid control. |

---

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [AboutBox](#aboutbox) | Displays an about box. |
| [AddItem](#additem) | Adds a row to an MSHFlexGrid. This property doesn’t support named arguments. |
| [Clear](#clear) | Clears the contents of the MSHFlexGrid. This includes all text, pictures, and cell formatting. This method does not affect the number of rows and columns within the MSHFlexGrid. |
| [ClearStucture](#clearstructure) | Clears any mapping information from the MSHFlexGrid that regards the order and name of the displayed columns. |
| [CollapseAll](#collapseall) | Collapses all rows of the specified band within the MSHFlexGrid. |
| [RemoveItem](#removeitem) | Removes a row from an MSHFlexGrid atrun time. |

---

### Properties

| Name       | Description |
| ---------- | ----------- |
| [AllowBigSelection](#allowbigselection) | Returns or sets a value that determines whether clicking on a column or row header should cause the entire column or row to be selected. |
| [AllowUserResizing](#allowuserresizing) | Returns or sets a value that determines whether the user can use the mouse to resize rows and columns in the MSHFlexGrid. |
| [Appearance](#appearance) | Returns or sets the paint style of the control on an MDIForm or Form object. |
| [ApplyBandFieldNameInfoChanges](#applybandfieldnameinfochanges) |  |
| [BackColor](#backcolor) | Returns or sets the background color of various elements of the MSHFlexGrid. |
| [BackColorBand](#backcolorband) |  Returns or sets the background color of the band area of the MSHFlexGrid. |
| [BackColorBkg](#backcolorbkg) | Returns or sets the background color of various elements of the MSHFlexGrid. |
| [BackColorFixed](#backcolorfixed) | Returns or sets the background color of various elements of the MSHFlexGrid. |
| [BackColorHeader](#backcolorheader) | Returns or sets the background color of the header area of the MSHFlexGrid. |
| [BackColorIndent](#backcolorindent) | Returns or sets the background color of the indented area of the MSHFlexGrid. |
| [BackColorSel](#backcolorsel) | Returns or sets the background color of the selected cells of the MSHFlexGrid. |
| [BackColorUnpopulated](#backcolorunpopulated) |  Returns or sets the background color of the unpopulated area of the MSHFlexGrid. |
| [BandColIndex](#bandcolindex) | Returns the column number of the current cell relative to the band that contains the cell. |
| [BandData](#banddata) | Returns or sets an arbitrary long value associated with each band. |
| [BandDisplay](#banddisplay) | Specifies how the bands display within the MSHFlexGrid. |
| [BandExpandable](#bandexpandable) | Returns and sets a value that determines whether the row in the current band can be expanded and collapsed. The current band is defined by the Col and Row properties.  |
| [BandIndent](#bandindent) | Specifies the number of columns by which to indent a band. |
| [BandLevel](#bandlevel) | Returns the band number that contains the current cell. The band numbers begin at 0. The current cell is defined by the Col and Row properties. |
| [Bands](#bands) | Returns the total number of bands in an MSHFlexGrid. The MSHFlexGrid always has a minimum of one band. When the MSHFlexGrid is bound to a standard Recordset, the entire MSHFlexGrid is treated as one band. |
| [BorderStyle](#brderstyle) | Returns or sets the border style for the control. |
| [CellAlignment](#cellalignment) | Returns or sets a value that determines the horizontal and vertical alignment of data within the current cell. |
| [CellBackColor](#cellbackcolor) | Returns or sets the background colors of individual cells or cell ranges. |
| [CellFontBold](#cellfontbold) | Returns or sets the bold style for the current cell text. |
| [CellFontItalic](#cellfontitalic) | Returns or sets the italic style for the current cell text. |
| [CellFontName](#cellfontname) | Returns or sets the name of the font for the current cell text. |
| [CellFontSize](#cellfontsize) | Returns or sets the size, in points, for the current cell text. |
| [CellFontStrikeThrough](#cellfontstrikethrough) | Returns or sets a value that determines if the Strikethrough style is applied to the current cell text. |
| [CellFontUnderline](#cellfontunderline) | Returns or sets a value that specifies if the underline style is applied to the current cell text. |
| [CellFontWidth](#cellfontwidth) | Returns or sets the width, in points, for the current cell text. |
| [CellForeColor](#cellforecolor) | Returns or sets the foreground colors of individual cells or cell ranges. |
| [CellHeight](#cellheight) | Returns the position and size of the current cell, intwips.  |
| [CellLeft](#cellleft) | Returns the position and size of the current cell, intwips. |
| [CellPicture](#cellpicture) | Returns or sets an image to be displayed in the current cell or range of cells.  |
| [CellPictureAlignment](#cellpicturealignment) | Returns or sets the alignment of pictures in a cell or range of selected cells. |
| [CellTextStyle](#celltextstyle) | Returns or sets the three-dimensional style for text in a specific cell or range of cells. |
| [CellTop](#celltop) | Returns the position and size of the current cell, intwips. |
| [CellType](#celltype) | Returns the type of the current, active, cell of the MSHFlexGrid. |
| [CellWidth](#cellwidth) | Returns the position and size of the current cell, intwips. |
| [Clip](#clip) | Returns or sets the contents of the cells in the MSHFlexGrid's selected region.  |
| [Col](#col) | Returns or sets the coordinates of the active cell in an MSHFlexGrid. |
| [ColAlignment](#colalignment) | Returns or sets the alignment of data in a column. This can be a standard column, a column within a band, or a column within a header. |
| [ColAlignmentBand](#colalignmentband) | Returns or sets the alignment of data in a column within a band. |
| [ColAlignmentFixed](#colalignmentfixed) | Returns or sets the alignment of data in the fixed cells of a column in an MSHFlexGrid. |
| [ColAlignmentHeader](#colalignmentheader) | Returns or sets the alignment of data in a column within a header. |
| [ColData](#coldata) | Returns or sets an arbitrary long value associated with each column. |
| [ColHeader](#colheader) | Specifies whether headers should display for the specified band. |
| [ColHeaderCaption](#colheadercaption) | Specifies the caption to display in the header of the specified column and band. |
| [ColIsVisible](#colisvisible) | Returns whether a given column is currently within view. |
| [CollectBandFieldNameInfo](#collectbandfieldnameinfo) | Manages column bands. |
| [ColWordWrapOption](#colwordwrapoption) | Controls how text wraps and behaves when it exceeds a cell's width. |
| [ColWordWrapOptionBand](#colwordwrapoptionband) | Controls how text wrapping is applied to specific column bands. |
| [ColWordWrapOptionHeader](#colwordwrapoptionheader) | Controls text wrapping specifically for column header cells. |
| [ColWordWrapOptionFixed](#colwordwrapoptionfixed) | Controls text wrapping specifically within the fixed columns (row headers) or fixed rows (column headers) of the grid. |
| [ColPos](#colpos) | Returns the distance, intwips, between the upper-left corner of the control and the upper-left corner of a specified column. |
| [ColPosition](#colposition) | Sets the position of an MSHFlexGrid column, allowing you to move columns to specific positions. |
| [Cols](#cols) | Returns or sets the total number of columns in an MSHFlexGrid. |
| [ColSel](#colsel) |  Returns or sets the start or end column for a range of cells. |
| [ColWidth](#colwidth) | Returns or sets the width of the column in the specified band, intwips. |
| [CountColumnsInBand](#countcolumnsinband) | Returns the number of columns within a specific logical group or band. |
| [DataField](#datafield) | Returns the name of the field bound to the specified column in the specified band. |
| [DataMember](#datamember) | Returns or sets the data member. |
| [DataSource](#datasource) | Returns or sets the data source. |
| [Enabled](#enabled) | Returns or sets a value that determines whether a form or control can respond to user-generated events. Visual Basic only? |
| [ExpandAll](#expandall) | Expands all rows of the specified band within the MSHFlexGrid. |
| [FillStyle](#fillstyle) | Returns or sets a value that determines whether setting the Text property, or one of the cell formatting properties, applies the change to all selected cells within the MSHFlexGrid. |
| [FixedAlignment](#fixedalignment) | Returns or sets the alignment of data in the fixed cells of a column in an MSHFlexGrid. |
| [FixedCols](#fixedcols) | Returns or sets the total number of fixed columns within an MSHFlexGrid. |
| [FixedRows](#fixedrows) | Returns or sets the total number of fixed rows within an MSHFlexGrid.  |
| [FocusRect](#focusrect) | Returns or sets a value that determines whether the MSHFlexGrid should draw a focus rectangle around the current cell. |
| [Font](#font) | Returns or sets the default font, or the font for individual cells. |
| [FontBand](#fontband) | Returns or sets the font of the text in the band. |
| [FontBold](#fontbold) | Determines whether the font is bold. |
| [FontFixed](#fontfixed) | Returns or sets the font of the text in the fixed cells. |
| [FontHeader](#fontheader) | Returns or sets the font of the text in the header. |
| [FontItalic](#fontitalic) | Determines whether the font is italicized. |
| [FontName](#fontname) | Returns or sets the name of the font. |
| [FontSize](#fontsize) | Determines the size of the font. |
| [FontStrikeThrough](#fontstrikethrough) | Determines the strikethru of the font. |
| [FontStrikethru](#fontstrikethru) | Determines the strikethru of the font. |
| [FontUnderline](#fontunderline) | Determines the font is underlined. |
| [FontWidth](#fontwidth) | Returns or sets the width, in points, of the font to be used for text displayed within an MSHFlexGrid |
| [FontWidthBand](#fontwidthband) | Returns or sets the width, in points, of the font to be used for text displayed withinthe grid's band area. |
| [FontWidthFixed](#fontwidthfixed) | Returns or sets the width, in points, of the font to be used for text displayed withinthe grid's fixed area. |
| [FontWidthHeader](#fontwidthheader) | Returns or sets the width, in points, of the font to be used for text displayed withinthe grid's header area. |
| [ForeColor](#forecolor) | Returns or sets the colors used to draw text on the MSHFlexGrid. |
| [ForeColorBand](#forecolorband) | Returns or sets the colors used to draw text on the band part of the MSHFlexGrid. |
| [ForeColorFixed](#forecolorfixed) | Returns or sets the foreground color of the fixed rows and columns. |
| [ForeColorHeader](#forecolorheader) | Returns or sets the colors used to draw text on the header of the MSHFlexGrid. |
| [ForeColorSel](#forecolorsel) | Returns or sets the foreground color of the selected cells. |
| [FormatString](#formatstring) | Sets the column widths, alignments, fixed row text, and fixed column text of the MSHFlexGrid. |
| [GetBandName](#getbandname) | Returns the name of the band. |
| [GetColumnInBandInfo](#getcolumninbandinfo) | Retrieves information regarding columns within a band. |
| [GridColor](#gridcolor) | Returns or sets the line color used between the cells of the MSHFlexGrid. |
| [GridColorBand](#gridcolorband) | Returns or sets the line color used between the bands of the MSHFlexGrid. |
| [GridColorFixed](#gridcolorfixed) | Returns or sets the color used to draw the grid lines between the fixed cells. |
| [GridColorHeader](#gridcolorheader) | Returns or sets the line color used between the header of the MSHFlexGrid. |
| [GridColorIndent](#gridcolorindent) | Returns or sets the line color used between the indents of the MSHFlexGrid. |
| [GridColorUnpopulated](#gridcolorunpopulated) | Returns or sets the line color used between the unpopulated areas of the MSHFlexGrid. | |
| [GridLines](#gridlines) | Returns or sets a value that determines whether lines are drawn between cells of the grid |
| [GridLinesBand](#gridlinesband) | Returns or sets a value that determines the type of lines that are drawn between bands. |
| [GridLinesFixed](#gridlinesfixed) | Returns or sets a value that determines the type of lines that are drawn between fixed cells. |
| [GridLinesHeader](#gridlinesheader) | Returns or sets a value that determines the type of lines that are drawn between the header. |
| [GridLinesIndent](#gridlinesindent) | Returns or sets a value that determines the type of lines that are drawn between the indents. |
| [GridLinesUnpopulated](#gridlinesunpopulated) | Returns or sets a value that determines the type of lines that are drawn between the unpopulated areas of the grid. |
| [GridLineWidth](#gridlinewidth) | Returns or sets the width, in pixels, of the lines displayed between cells. |
| [GridLineWidthBand](#gridlinewidthband) | Returns or sets the width, in pixels, of the lines displayed between bands of the grid. |
| [GridLineWidthFixed](#gridlinewidthfixed) | Returns or sets the width, in pixels, of the lines displayed between the fixed cells of the grid. |
| [GridLineWidthHeader](#gridlinewidthheader) | Returns or sets the width, in pixels, of the lines displayed between the headers of the grid. |
| [GridLineWidthIndent](#gridlinewidthindent) | Returns or sets the width, in pixels, of the lines displayed between the indents of the grid. |
| [GridLineWidthUnpopulated](#gridlinewidthunpopulated) | Returns or sets the width, in pixels, of the lines displayed between the unpopulated areas of the grid. |
| [HighLight](#highLight) | Determines whether selected cells appear highlighted within the MSHFlexGrid. |
| [hWnd](#hwnd) | Returns the handle of the control. |
| [LeftCol](#leftcol) | Returns or sets the left-most visible non fixed column in the MSHFlexGrid. |
| [MergeCells](#mergecells) | Returns or sets a value that determines whether cells with the same contents should be grouped in a single cell spanning multiple rows or columns. |
| [MergeCol](#mergecol) | Returns or sets a value that determines which columns can have their contents merged. This property must be True to use the MergeCells property. |
| [MergeRow](#mergerow) | Returns or sets a value that determines which rows can have their contents merged. This property must be True to use the MergeCells property. |
| [MouseCol](#mousecol) | Returns the current mouse position, in column coordinate. |
| [MouseIcon](#mouseicon) | Returns or sets a custom mouse icon. |
| [MousePointer](#mousepointer) | Returns or sets a value indicating the type of mouse pointer displayed when the mouse is over a particular part of an object at run time. |
| [MouseRow](#mouserow) | Returns the current mouse position, in row coordinate. |
| [OLEDrag](#oledrag) | Returns or sets whether the control can act as an OLE drag source, either automatically or under program control. |
| [OLEDropMode](#oledropmode) | Returns or sets whether the control can act as an OLE drop target, either automatically or under program control. |
| [Picture](#picture) | Returns a picture of your MSHFlexGrid. This picture is suitable for printing, saving to disk, copying to the clipboard, or assigning to a different control. |
| [PictureType](#picturetype) | Returns or sets the type of picture to be generated by the Picture property.**** |
| [Recordset](#recordset) | Used to bind hierarchical or flat ADO data to the grid. |
| [Redraw](#redraw) | Returns or sets a value that determines whether the MSHFlexGrid should be automatically redrawn after each change. |
| [Refresh](#refresh) | Synchronizes the grid's visual state with its data source. |
| [RightToLeft](#righttoleft) | Used to support languages that read from right to left, such as Arabic or Hebrew. |
| [Row](#row) | Returns or sets the coordinates of the active cell in an MSHFlexGrid. |
| [RowData](#rowdata) | Returns or sets an arbitrary long value associated with each row. |
| [RowExpandable](#rowexpandable) | Specify whether the current row is expandable. The current row is defined by the Col and Row properties. |
| [RowExpanded](#rowexpanded) | Specify whether the current row is expanded or collapsed. The current row is defined by the Col and Row properties. |
| [RowHeight](#rowheight) | Returns or sets the height of the specified row, intwips. |
| [RowHeightMin](rowheightmin) | Returns or sets the minimum row height for the entire control, intwips. |
| [RowIsVisible](rowisvisible) | Returns or sets a value that determines whether a specified row is visible. |
| [RowPos](#rowpos) | Returns the distance, intwips, between the upper-left corner of the MSHFlexGrid and the upper-left corner of a specified row. |
| [RowPosition](#rowposition) | Sets the position of an MSHFlexGrid row, allowing you to move rows to specific positions. |
| [Rows](#rows) | Returns or sets the total number of rows in an MSHFlexGrid. |
| [RowSel](#rowsel) | Returns or sets the start or end row for a range of cells.  |
| [RowSet](#rowset) | Used to bind hierarchical or flat ADO data to the grid. |
| [RowSizingMode](#rowsizingmode) | Returns or sets a value that describes the sizing mode of the rows in the MSHFlexGrid. |
| [ScrollBars](#scrollbars) | Returns or sets a value that determines whether an MSHFlexGrid has horizontal and/or vertical scroll bars. |
| [ScrollTrack](#scrolltrack) | Returns or sets a value that determines whether the MSHFlexGrid should scroll its contents while the user moves the scroll box along the scroll bars. |
| [SelectionMode](#selectionmode) | Returns or sets a value that determines whether an MSHFlexGrid should allow regular cell selection, selection by rows, or selection by columns. |
| [SetColumnInBandInfo](#setcolumninbandinfo) |  |
| [Sort](#sort) | Sets a value that sorts selected rows according to selected criteria. |
| [Text](#text) | Returns or sets the text content of a cell or range of cells. |
| [TextArray](#textarray) | Returns or sets the text content of an arbitrary cell. |
| [TextMatrix](#textmatrix) | Returns or sets the text contents of an arbitrary cell. |
| [TextStyle](#textstyle) | Determines the style of regular MSHFlexGrid cells. |
| [TextStyleBand](#textstyleband) | Determines the style of bands. |
| [TextStyleFixed](#textstylefixed) | Determines the style of fixed rows and columns. |
| [TextStyleHeader](#textstyleheader) | Determines the style of headers. |
| [TopRow](#toprow) | Returns or sets the uppermost visible row (other than a fixed row) in the MSHFlexGrid. |
| [Version](#version) | Returns the version of the MSHFlexGrid that is currently loaded in memory. |
| [WordWrap](#wordwrap) | Returns or sets a value that determines whether a cell displays multiple lines of text or one long line of text. |

---

### Events

| Name       | Description |
| ---------- | ----------- |
| [Click](#click) | Occurs when the user presses and then releases a mouse button over the grid. |
| [DblClick](#dblclick) | Occurs when the user double-clicks the grid with the mouse button. |
| [Collapse](#collapse) | Occurs when the user collapses a row within the grid. The Col and Row properties of the MSHFlexGrid contain the cell used to collapse the band. |
| [Compare](#compare) | Occurs when the Sort property for the MSHFlexGrid is set to Custom Sort (9), so the user can customize the sort process. |
| [EnterCell](#entercell) | Occurs when the currently active cell changes to a different cell. |
| [Expand](#expand) | Occurs when the user expands a row within the MSHFlexGrid. The Col and Row properties of the MSHFlexGrid contain the cell used to expand the band. |
| [KeyDown](#keydown) | Occurs when the user presses a key while the grid has the focus. |
| [KeyPress](#keypress) | Occurs when the user presses and releases an ascii key. |
| [KeyUp](#keyup) | Occurs when the user releases a key. |
| [LeaveCell](#leavecell) | Occurs when the currently active cell changes to a different cell. |
| [MouseDpwn](#mousedown) | Occurs when the user presses a mouse button. |
| [MouseMove](#mousemove) | Occurs when the user moves the mouse. |
| [MouseUp](#mouseup) | Occurs when the user releases a mouse button. |
| [OLECompleteDrag](#olecompletedrag) | Fired after an OLE drag operation is started. |
| [OLEDragDrop](#oledragdrop) | Fired when a source component is dropped onto a target component. |
| [OLEDragOver](#oledragover) | Fired when an object is dragged in to the bounds of an element that is acting as the drop target. || [OLEGiveFeedback](#olegivefeedack) | Fired after a drop to inform the source component that a drag action was either performed or cancelled |
| [OLESetData](#olesedata) | Fired on the source component when a target component performs the GetData method in the source's DataObject component. |
| [OLEStartDrag](#olestartdrag) | Fired after an OLE drag operation is started. |
| [RowSelChange](#rowcolchange) | Fired when the current cell changes to a new cell. |
| [Scroll](#scroll) | Occurs when the contents of the MSHFlexGrid are scrolled. This can be done using the scroll bars, keyboard, or programmatically by changing the TopRow or LeftCol properties. |
| [SelChange](#selchange) | Occurs when the selected range changes to a different cell or range of cells. |

---

### MSHFlexGrid Control Constants

This section contains information on the control constants of the `MSHFlexGrid`. Note that these constants also apply to the `MSFlexGrid` unless otherwise noted.

#### AddModeSettings Property (MSHFlexGrid)

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexNoAddNew** | 0 | The current cell is not in the last row, and no **AddNew** operation is pending. |
| **flexAddNewCurrent** | 1 | The current cell is in the last row, but no **AddNew** operation is pending. |
| **flexAddNewPending** | 2 | The current cell is in the next to last row. This is a result of either a pending **AddNew** operation initiated by the user through the user interface of the `MSHFlexGrid`, or setting a column’s **Value** or **Text** property programmatically.  |

#### AllowUserResizing Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexResizeNone** | 0 | The user cannot resize with the mouse. This is the default. |
| **flexResizeColumns** | 1 | The user can resize columns using the mouse. |
| **flexResizeRows** | 2 | The user can resize rows using the mouse. |
| **flexResizeBoth** | 3 | The user can resize columns and rows using the mouse. |

#### Appearance Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexFlat** | 0 | The overall look of `MSHFlexGrid` is flat, or normal. |
| **flex3D** | 1 | The overall look of `MSHFlexGrid` is three-dimensional.  |

#### BorderStyle Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexBorderNone** | 0 | There is no border. |
| **flexBorderSingle** | 1 | There is a single border. |

#### CellAlignment Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexAlignLeftTop** | 0 | The cell content is aligned left, top. |
| **flexAlignLeftCenter** | 1 | The cell content is aligned left, center. This is the default for strings. |
| **flexAlignLeftBottom** | 2 | The cell content is aligned left, bottom. |
| **flexAlignCenterTop** | 3 | The cell content is aligned center, top. |
| **flexAlignCenterCenter** | 4 | The cell content is aligned center, center. |
| **flexAlignCenterBottom** | 5 | The cell content is aligned center, bottom. |
| **flexAlignRightTop** | 6 | The cell content is aligned right, top. |
| **flexAlignRightCenter** | 7 | The cell content is aligned right, center. This is the default for numbers. |
| **flexAlignRightBottom** | 8 | The cell content is aligned right, bottom. |
| **flexAlignGeneral** | 9 | The cell content is of general alignment. This is "left, center" for strings and "right, center" for numbers. |

#### CellPictureAlignment Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexAlignLeftTop** | 0 | The picture is aligned left, top. |
| **flexAlignLeftCenter** | 1 | The picture is aligned left, center. |
| **flexAlignLeftBottom** | 2 | The picture is aligned left, bottom. |
| **flexAlignCenterTop** | 3 | The picture is aligned center, top. |
| **flexAlignCenterCenter** | 4 | The picture is aligned center, center. |
| **flexAlignCenterBottom** | 5 | The picture is aligned center, bottom. |
| **flexAlignRightTop** | 6 | The picture is aligned right, top. |
| **flexAlignRightCenter** | 7 | The picture is aligned right, center. |
| **flexAlignRightBottom** | 8 | The picture is aligned right, bottom. |

#### CellTextStyle, TextStyle, TextStyleFixed Properties

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexTextFlat** | 0 | The text is normal, flat text. |
| **flexTextRaised** | 1 | The text appears raised. |
| **flexTextInset** | 2 | The text appears inset. |
| **flexTextRaisedLight** | 3 | The text appears slightly raised. |
| **flexTextInsetLight** | 4 | The text appears slightly inset. |

#### CellType Properties (MSHFlexGrid)

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexCellTypeStandard** | 0 | The cell is a standard cell. |
| **flexCellTypeFixed** | 1 | The cell is contained in a fixed row or column. |
| **flexCellTypeHeader** | 2 | The cell is a header cell for a band of data. |
| **flexCellTypeIndent** | 3 | The cell is used in a column that indents a band of data. |
| **flexCellTypeUnpopulated** | 4 | The cell is an unpopulated cell. |

#### ColAlignment Properties

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexAlignLeftTop** | 0 | The column content is aligned left, top. |
| **flexAlignLeftCenter** | 1 | The column content is aligned left, center. This is the default for strings. |
| **flexAlignLeftBottom** | 2 | The column content is aligned left, bottom. |
| **flexAlignCenterTop** | 3 | The column content is aligned center, top. |
| **flexAlignCenterCenter** | 4 | The column content is aligned center, center. |
| **flexAlignCenterBottom** | 5 | The column content is aligned center, bottom. |
| **flexAlignRightTop** | 6 | The column content is aligned right, top. |
| **flexAlignRightCenter** | 7 | The column content is aligned right, center. This is the default for numbers. |
| **flexAlignRightBottom** | 8 | The column content is aligned right, bottom. |
| **flexAlignGeneral** | 9 | The column content is of general alignment. This is left center for strings and right center for numbers. |

#### ColHeader Property (MSHFlexGrid)

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexColHeaderOn** | 0 | The headers display for each band. |
| **flexColHeaderOff** | 1 | No headers display for the band. |
| **flexColHeaderOnce** | 2 | The headers display for the band. If the band is collapsed, only one header displays. Duplicate headers don’t display. |

#### DisplayBandSettings Property (MSHFlexGrid)

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexBandDisplayHorizontal** | 0 | The bands within the MSHFlexGrid display horizontally (across). This is the default. |
| **flexBandDisplayVertical** | 1 | The bands within the MSHFlexGrid display vertically (up and down). |

#### DisplayCellSettings Property (MSHFlexGrid)

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **FlexCellDisplayHorizontal** | 0 | The bands within the MSHFlexGrid display horizontally (across). |
| **flexCellDisplayVertical** | 1 | The bands within the MSHFlexGrid display vertically (up and down). |

#### FillStyle Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexFillSingle** | 0 | Changing Text or any of the cell properties only affects the active cell. This is the default. |
| **flexFillRepeat** | 1 | Repeat. Changing the Text or any of the cell properties affects all selected cells. |

#### FocusRect Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexFocusNone** | 0 | There is no focus rectangle around the current cell. |
| **flexFocusLight** | 1 | There is a light focus rectangle around the current cell. This is the default. |
| **flexFocusHeavy** | 2 | There is a heavy focus rectangle around the current cell. |

#### GridLines, GridLinesFixed Properties

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexGridNone** | 0 | No Lines. There are no lines between cells. In the MSFlexGrid, this is the default for GridLines. |
| **flexGridFlat** | 1 | Lines. The line style between cells is set to normal, flat lines. In the MSHFlexGrid, this is the default for GridLines. |
| **flexGridInset** | 2 | Inset Lines. The line style between cells is set to inset lines. In the MSFlexGrid, this is the default for GridLinesFixed. |
| **flexGridRaised** | 3 | Raised Lines. The line style between cells is set to raised lines. In the MSHFlexGrid, this is the default for GridLinesFixed. |

#### HighLight Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexHighlightNever** | 0 | There is no highlight on the selected cells. |
| **flexHighlightAlways** | 1 | The selected cells are always highlighted. This is the default. |
| **flexHighlightWithFocus** | 2 | The highlight appears only when the control has focus. |

#### MergeCells Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexMergeNever** | 0 | Never. The cells containing identical content are not grouped. This is the default. |
| **flexMergeFree** | 1 | Free. Cells with identical content always merge. |
| **flexMergeRestrictRows** | 2 | Restrict Rows. Only adjacent cells (to the left) within the row containing identical content merge. |
| **flexMergeRestrict-Columns** | 3 | Restrict Columns. Only adjacent cells (to the top) within the column containing identical content merge. |
| **flexMergeRestrictBoth** | 4 | Restrict Both. Only adjacent cells within the row (to the left) or column (to the top) containing identical content merge. |

#### MousePointer Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexDefault** | 0 | The outline of MSHFlexGrid. |
| **flexArrow** | 1 | An arrow pointer. |
| **flexCross** | 2 | A set of crosshairs. |
| **flexIBeam** | 3 | An "I"-shaped beam to allow for text entry. |
| **flexIcon** | 4 | A square within a square. |
| **flexSize** | 5 | A resizing pointer with arrows facing up, down, left, and right. |
| **flexSizeNESW** | 6 | A resizing pointer with arrows pointing to the upper right and lower left. |
| **flexSizeNS** | 7 | A resizing pointer with arrows pointing up and down. |
| **flexSizeNWSE** | 8 | A resizing pointer with arrows pointing to the upper left and lower right. |
| **flexSizeEW** | 9 | A resizing pointer with arrows pointing left and right. |
| **flexUpArrow** | 10 | An arrow pointing up. |
| **flexHourGlass** | 11 | An hourglass symbol. |
| **flexNoDrop** | 12 | A no drop pointer. |
| **flexCustom** | 13 | A custom style pointer. |

#### PictureType Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexPictureColor** | 0 | This produces a high-quality full-color image.  |
| **flexPictureMonochrome** | 1 | This produces a lower-quality, monochrome, image that consumes less memory. |

#### RowSizingSettings Property (MSHFlexGrid)

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexRowSizeIndividual** | 0 | Resizing a row changes only the height of the row sized. This is the default. |
| **flexRowSizeAll** | 1 | Resizing a row changes the height of all rows in the MSHFlexGrid. |

#### SelectionMode Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexSelectionFree** | 0 | Free. This allows individual cells in the MSHFlexGrid to be selected, spreadsheet-style. (Default) |
| **flexSelectionByRow** | 1 | By Row. This forces selections to span entire rows, as in a multi-column list box or record-based display. |
| **flexSelectionByColumn** | 2 | By Column. This forces selections to span entire columns, as if selecting ranges for a chart or fields for sorting. |

#### ScrollBars Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexScrollNone** | 0 | Free. The MSHFlexGrid has no scroll bars. |
| **flexScrollHorizontal** | 1 | The MSHFlexGrid has a horizontal scroll bar. |
| **flexScrollVertical** | 2 | The MSHFlexGrid has a vertical scroll bar. |
| **flexScrollBoth** | 3 | The MSHFlexGrid has horizontal and vertical scroll bars. This is the default. |

#### Sort Property

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexSortNone** | 0 | None. No sorting is performed. |
| **flexSortGenericAscending** | 1 | Generic Ascending. An ascending sort, which estimates whether text is string or number, is performed. |
| **lexSortGenericDescending** | 2 | Generic Descending. A descending sort, which estimates whether text is string or number, is performed. |
| **flexSortNumericAscending** | 3 | Numeric Ascending. An ascending sort, which converts strings to numbers, is performed. |
| **flexSortNumericDescending** | 4 | Numeric Descending. A descending sort, which converts strings to numbers, is performed. |
| **flexSortStringNoCaseAsending** | 5 | String Ascending. An ascending sort using case-insensitive string comparison is performed. |
| **flexSortNoCaseDescending** | 6 | String Descending. A descending sort using case-insensitive string comparison is performed. |
| **flexSortStringAscending** | 7 | String Ascending. An ascending sort using case-sensitive string comparison is performed. |
| **flexSortStringDescending** | 8 | String Descending. A descending sort using case-sensitive string comparison is performed. |
| **flexSortCustom** | 9 | Custom. This uses the Compare event to compare rows. |

---

### Constructor

Attaches an instance of the MSHFlexGrid control.

```
CONSTRUCTOR CMSHFlexGrid (BYVAL pDisp AS IDispatch PTR, BYVAL fAddRef AS BOOLEAN = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pDisp* | Pointer to the **IDispatch** interface of the control returned by the **OcxDispObj** or **OcxDispPtr** methods of the `CAxHost` class (OLE container) |
| *fAddRef* | If TRUE, the control increments its reference count. This is only needed if the pointer attached is the one returned by the **OcxDispPtr** method. |

#### Example

```
#define UNICODE
'#define _CAXH_DEBUG_ 1
#INCLUDE ONCE "AfxNova/AfxCOM.inc"
#INCLUDE ONCE "AfxNova/CAxHost.inc"
#INCLUDE ONCE "AfxNova/MSHFlexGrid.inc"
#INCLUDE ONCE "AfxNova/CADODB.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_GRID = 1001

' ========================================================================================
' Main
' ========================================================================================
FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                   BYVAL hPrevInstance AS HINSTANCE, _
                   BYVAL pwszCmdLine AS WSTRING PTR, _
                   BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   ' // The recommended way is to use a manifest file
   AfxSetProcessDPIAware

   ' // Creates the main window
   DIM pWindow AS CWindow
   ' -or- DIM pWindow AS CWindow = "MyClassName" (use the name that you wish)
   DIM hwndMain AS HWND = pWindow.Create(NULL, "Microsoft Hierarchical Flex Grid", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(800, 450)
   ' // Centers the window
   pWindow.Center

   DIM wszLibName AS WSTRING * 260 = ExePath & "\MSHFLXGD.OCX"
   DIM pHost AS CAxHost = CAxHost(@pWindow, IDC_GRID, wszLibName, AFX_CLSID_MSHFlexGrid, _
       AFX_IID_IMSHFlexGrid, RTLKEY_MSHFlexGrid, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   pWindow.AnchorControl(IDC_GRID, AFX_ANCHOR_HEIGHT_WIDTH)
   SetFocus pHost.hWindow

   DIM pGrid AS CMSHFlexGrid = pHost.OcxDispObj
   ' // Set the width of the columns (in twips)
   pGrid.ColWidth(0) = 300
   pGrid.ColWidth(1) = 1100
   pGrid.ColWidth(2) = 3000
   pGrid.ColWidth(3) = 2000
   pGrid.ColWidth(4) = 2000
   pGrid.ColWidth(5) = 3000
   pGrid.ColWidth(6) = 1500
   pGrid.ColWidth(7) = 700
   pGrid.ColWidth(8) = 1200
   pGrid.ColWidth(9) = 1200
   pGrid.ColWidth(10) = 1500
   pGrid.ColWidth(11) = 1500
   ' Change the foreground and background colors
   pGrid.ForeColor = BGR(0, 0, 0)
   pGrid.BackColor = BGR(255,255,235)

   ' Open an ADO connection
   DIM pConnection AS CAdoConnection PTR = NEW CAdoConnection
   pConnection->ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" & ExePath & $"\nwind.mdb"
   pConnection->Open
   ' Open a recordset
   DIM pRecordset AS CAdoRecordset PTR = NEW CAdoRecordset
   DIM dvSource AS DVARIANT = "SELECT * FROM Customers"
   pRecordset->Open(dvSource, pConnection, adOpenKeyset, adLockOptimistic, adCmdText)
   ' Set the Datasource property of the recordset
   pGrid.DataSource = cast(ANY PTR, pRecordset->DataSource)
   ' Close the recordset
   pRecordset->Close
   ' Close the connection
   pConnection->Close
   ' // Delete the recordset
   Delete pRecordset
   ' // Delete the connection
   Delete pConnection

   ' // Display the window
   ShowWindow(hwndMain, nCmdShow)
   UpdateWindow(hwndMain)

   ' // Dispatch Windows messages
   DIM uMsg AS MSG
   WHILE (GetMessageW(@uMsg, NULL, 0, 0) <> FALSE)
      IF AfxCAxHostForwardMessage(GetFocus, @uMsg) = FALSE THEN
         IF IsDialogMessageW(hwndMain, @uMsg) = 0 THEN
            TranslateMessage(@uMsg)
            DispatchMessageW(@uMsg)
         END IF
      END IF
   WEND
   FUNCTION = uMsg.wParam

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

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```
---

### hWnd

Return the Windows handle of the grid control. The hWnd (Handle to a Window) is a unique value used to identify the `MSHFlexGrid` as a standard Windows window object. It is primarily used when you need to perform advanced operations that the standard control properties do not support. 

```
FUNCTION hWnd () AS .HWND
```

#### Common Use Cases

**API Calls**: Many Windows API functions require a window handle to target a specific control.

**Subclassing**: Developers use the **hWnd** to "hook" into the control's message stream, often to add features like mouse-wheel scrolling support, which is not natively robust in the legacy control.

**External interaction**: It allows external applications or routines to identify and interact with the grid window directly within the Windows environment.

---

### AddItem

Adds a row to an `MSHFlexGrid`.

```
FUNCTION AddItem (BYREF Item AS WSTRING, BYVAL Index AS LONG = -1) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Item* | Required. A string expression displayed in the newly added row. To add multiple strings (for multiple columns in the row), use the tab character to separate each string. |
| *Index* | Optional. A Long value indicating the position within the control. This position is where the new row is placed. For the first row, index=0. If index is omitted, the new row becomes the last row in the band. |

#### Remarks

You can quickly fill a row with multiple values using a single line of code:
```
' Adds a row with "ID" in Col 0, "Name" in Col 1, and "Date" in Col 2
grid.AddItem "101" & CHR(9) & "John Doe" & CHR(9) & "2026-01-02"
```

**Performance optimization**: When adding a large number of rows (e.g., thousands), it is critical to set `Redraw = False` before starting the loop and `Redraw = True` after to prevent flickering and improve speed.

**Unbound requirement**: **AddItem** is typically used when the grid is not bound to a data source. If the grid is bound to a hierarchical **Recordset**, attempting to use **AddItem** may result in a runtime error, as the structure is managed by the data source. 

#### Related methods and properties

**RemoveItem**: Used to delete a specific row by its index.

**Rows Property**: Alternatively, you can add empty rows by manually incrementing the Rows property (e.g., `grid.Rows = MSHFlexGrid1.Rows + 1)`.

**TextMatrix**: While **AddItem** creates a new row, `TextMatrix(row, col)` is used to update the contents of an existing cell. 

---

### RemoveItem

Removes the row at the specified index and automatically shifts all subsequent rows up to fill the gap. 

```
FUNCTION RemoveItem (BYVAL Index AS LONG) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | A Long value indicating representing the zero-based position of the row to be deleted. |

#### Example

Deleting the currently selected row
```
' Removes the row where the user has currently clicked
grid.RemoveItem grid.Row
```

#### Remarks

**The "Last Row" error**: You cannot use **RemoveItem** to delete the very last remaining non-fixed row in the grid. Attempting to do so triggers Runtime Error 30015: "Can not remove last non-fixed row."

**Workaround**: If you need to clear the last row, either set the **Rows** property to equal the **FixedRows** or use the **Clear** method.

**Data binding**: You cannot use **RemoveItem** if the grid is bound to a data source (like an ADO Recordset). In a bound grid, you must delete the record from the underlying data source and then refresh the grid.

**Fixed rows**: You cannot remove a row that is defined as "fixed" (header rows). 

**Best practice: Deleting multiple rows**

When deleting multiple rows (for example, a selected range), you must always loop backward. If you loop forward, the indices shift as you delete, causing the code to skip rows or crash. 
```
' Correct way to delete a range of selected rows
grid.Redraw = False ' Prevent flickering
For i As Long = grid.RowSel To grid.Row Step -1
   ' Check to ensure we aren't trying to delete the last data row
   If grid.Rows > grid.FixedRows + 1 Then
      grid.RemoveItem i
   Else
      grid.Clear ' Wipe the last remaining row instead of removing it
   End If
Next
grid.Redraw = True
```

#### Technical tips

For large grids, always set `grid.Redraw = False` before starting a deletion loop to prevent the grid from attempting to repaint after every single row removal.

If your goal is to wipe all data but keep the column headers, it is much faster to set `grid.Rows = grid.FixedRows + 1` than to call **RemoveItem** in a loop.

---

### AllowBigSelection

Returns or sets a value that determines whether clicking on a column or row header should cause the entire column or row to be selected.

```
PROPERTY AllowBigSelection () AS BOOLEAN
PROPERTY AllowBigSelection (BYVAL bAllowBigSelection AS BOOLEAN = TRUE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bAllowBigSelection* | **True**: Default. When the user clicks the header, the entire column or row is selected. **False**: When the user clicks the header, only the header is selected. |

#### Key characteristics

**Fixed area interaction**: When set to **True**, clicking on a fixed row (column header) selects the entire column, and clicking on a fixed column (row header) selects the entire row.

**Global selection**: If set to **True**, clicking on the top-left fixed cell (the intersection of fixed rows and columns) selects the entire grid.

**Selection boundaries**: If set to **False**, clicking on a fixed cell simply selects the first non-fixed cell adjacent to that header, rather than highlighting the entire row or column. 

#### Relationship to SelectionMode

While **AllowBigSelection** enables selection via the fixed areas, the **SelectionMode** property defines the selection behavior within the data area. 

*flexSelectionFree* (0): Allows individual cell or range selection.
*flexSelectionByRow* (1): Forces any selection to span the entire width of the rows.
*flexSelectionByColumn* (2): Forces any selection to span the entire height of the columns. 

#### Example implementation

To configure a grid where users can select individual cells but cannot select entire columns by clicking the headers: 
```
' Disable the ability to select entire rows/columns via headers
grid.AllowBigSelection = False

' Allow users to select free-form ranges in the data area
grid.SelectionMode = flexSelectionFree
```

#### Technical tip

**Restricting to single selection**: If you want to prevent users from selecting more than one cell at a time, you must typically set `AllowBigSelection = False` and also manage the selection range manually in the **SelChange** or **MouseUp** events.

---

### AllowUserResizing

Returns or sets whether the user is allowed to resize rows and columns with the mouse.

```
PROPERTY AllowUserResizing () AS AllowUserResizeSettings
PROPERTY AllowUserResizing (BYVAL bAllowUserResizing AS AllowUserResizeSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bAllowUserResizing* | Returns or sets a value that determines whether the user can use the mouse to resize rows and columns in the MSHFlexGrid. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| flexResizeNone | 0 | None. Default. The user cannot resize with the mouse. |
| flexResizeColumns | 1 | Columns. The user can resize columns using the mouse. |
| flexResizeRows | 2 | Rows. The user can resize rows using the mouse. |
| flexResizeBoth | 3 | Both. The user can resize columns and rows using the mouse. |

#### Operational mechanics

**Interaction area**: To resize, the user must position the mouse pointer over the fixed area (headers) near a border. The mouse pointer will change to a sizing pointer (double-headed arrow), indicating the user can click and drag.

**Group resizing**: If a group of rows or columns is selected (using `AllowBigSelection = True`), resizing one of them will automatically apply the new size to all selected items in that group.

**Locked cells**: Cells with a height or width of zero (hidden rows/columns) cannot be resized by the user. To make them resizable while appearing hidden, set their width to 1 pixel instead of 0. 

#### Technical tips

**Double-click to fit**: While not a native property of the base `MSHFlexGrid`, many developers implement "AutoFit" functionality by writing code in the **DblClick** event to set the **ColWidth** based on the longest text entry in that column.

**Merged cells restriction**: Resizing may be disabled or difficult for users if you have merged cells in the header area, as the grid may not recognize the border between merged columns as a valid sizing handle. 

---

### BackColor

Returns or sets the background color of the non-fixed cells. To set the background color of individual cells, use the **CellBackColor** property.

```
PROPERTY BackColor () AS OLE_COLOR
PROPERTY BackColor (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | A numeric expression that specifies the color. This is typically a 32-bit RGB color value. |

#### Remarks

It affects all non-fixed cells simultaneously unless an individual cell's background is specifically overridden. 

#### Key characteristics

**Default behavior**: Cells with their own background property set to 0 (default) will automatically inherit the color defined by **BackColor**.

**Overriding individual cells**: To change the background of a specific cell or range, use the **CellBackColor** property after selecting the targeted row and column.

**Handling black**: Setting **BackColor** to 0 may cause the grid to use the standard system background color. To explicitly set the background to black, use the constant *vbBlack* or the literal value 1. 

#### Related global background properties

For a complete visual configuration, **BackColor** is often used alongside these related properties: 

**BackColorFixed**: Sets the background color for all fixed header rows and columns.
**BackColorSel**: Sets the background color for cells that are currently selected or highlighted.
**BackColorBkg**: Sets the color of the empty area (the "background of the background") not covered by any cells.
**BackColorBand**: Sets the background color for a specific hierarchical level or band. 

#### Example implementation

To set the entire grid's data area to a light blue at runtime:
```
' Sets the global default background for all scrollable cells
grid.BackColor = BGR(230, 240, 255) 

' Contrast with CellBackColor for a specific cell highlight
grid.Row = 1
grid.Col = 1
grid.CellBackColor = vbYellow
```
#### Technical tips

**Performance**: When performing bulk updates to multiple color properties, set `Redraw = False` before changes and `Redraw = True` afterward to prevent screen flickering.

**Theme integration**: Developers often set **BackColor** to system constants like *vbWindowBackground* to ensure the application matches the user's modern OS theme. 

---

### BackColorBand

Returns or sets the background color of the band. Bands are hierarchical levels in the grid (for example, when the grid is grouped). Band indices start at 0 for the first level.

```
PROPERTY BackColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR
PROPERTY BackColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY BackColorBand () AS OLE_COLOR
PROPERTY BackColorBand (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Key characteristics

**Hierarchical distinction**: It is primarily used to color-code different data levels to improve readability in complex one-to-many relationship displays.

**Global vs. Band**: While the standard **BackColor** sets the default for the entire data area, **BackColorBand** overrides that default for all cells within the specified hierarchical level.

**Individual cell overrides**: If you use the **CellBackColor** property on a specific cell within a band, that individual setting will take precedence over the **BackColorBand** color.

#### Example implementation
To set the parent band to a button-face gray and the first child band to a light blue:
```
' Color the primary parent band
grid.BackColorBand(0) = vbButtonFace

' Color the first level of child data
grid.BackColorBand(1) = BGR(220, 240, 255)
```

#### Technical Tips

**Black vs. system default**: Setting this property to 0 may cause it to revert to the standard system background color. To explicitly set a band to black, use the constant *vbBlack* or the literal value 1.

**Theming**: To create a modern "zebra-stripe" or banded look across a hierarchy, ensure you also configure the **BackColorHeader** and **BackColorIndent** for the corresponding bands to maintain visual consistency.

---

### BackColorHeader

Returns or sets the background color of the header area of the grid.

```
PROPERTY BackColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR
PROPERTY BackColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY BackColorHeader () AS OLE_COLOR
PROPERTY BackColorHeader (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a system color constant (such vbHighlight or vbWindowBackground) or an RGB value. |

#### Key characteristics

**Hierarchical specificity**: While the global BackColorFixed property sets the background color for the general fixed rows and columns of the entire grid, BackColorHeader provides granular control over the headers of nested data levels.

**Visual distinction**: This is typically used to color-code the headers of different data levels, helping users distinguish between parent records and child details at a glance.

**3D style interaction**: If the **GridLinesHeader** property is set to a 3D style (like *flexGridRaised*), the **BackColorHeader** will fill the surface of the "button-like" header cell. 

#### Example implementation

To set the primary band header to dark blue and the secondary band header to a lighter gray:
```
' Setting the primary parent band header
grid.BackColorHeader(0) = BGR(0, 0, 128)

' Setting the child band header to a light gray (system button face)
grid.BackColorHeader(1) = &H8000000F 
```

#### Technical tips

**Black vs. system default**: Setting this property to 0 may cause it to revert to the system default background. To force a true black background for a header, use the constant *vbBlack* or the value 1.

**Performance**: When updating multiple band-specific visual settings, set `Redraw = False` before starting and `Redraw = True` afterward to ensure a smooth, flicker-free update on modern displays. 

---

### BackColorIndent

Returns or sets the background color of the indented area of the grid that separates a child band from its parent band in a hierarchical display.

```
PROPERTY BackColorIndent (BYVAL BandNumber AS LONG) AS OLE_COLOR
PROPERTY BackColorIndent (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY BackColorIndent () AS OLE_COLOR
PROPERTY BackColorIndent (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value. This can be a standard VB constant (e.g., vbRed), a hex color code, or an RGB value. |

#### Key characteristics

**Hierarchical navigation**: The "indent" area is the horizontal gap created when nested child data is offset to show a parent-child relationship.

**Visual structure**: Developers use this property to color-code these gaps, helping users visually track the depth of the hierarchy.

**Default behavior**: If not set, the indent area typically inherits the color of the band's background or the global background color.

#### Example implementation

To apply a light gray indent to the first child band for better structural clarity:
```
' Target the first child band (Band 1)
' Set the indentation color to a light gray
grid.BackColorIndent(1) = &HE0E0E0 
```
#### Technical tips

**Seamless look**: To make the indent area appear as part of the parent row, set **BackColorIndent** to match the **BackColorBand** of the parent level (Band 0).

**Redraw performance**: When updating multiple band-specific visual settings, set `Redraw = False` before changes and True afterward to prevent screen flickering.

---

### BackColorFixed

Returns or sets the background color of the fixed cells of the grid. Fixed cells are the non-scrolling rows and columns typically used for headers or labels

```
PROPERTY BackColorFixed () AS OLE_COLOR
PROPERTY BackColorFixed (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value. This can be a standard VB constant (e.g., vbGrayText), a hex color code, or an RGB value. |

#### Remarks

Affects all cells in the rows defined by the **FixedRows** property and columns defined by the **FixedCols** property.

It is commonly used to differentiate header labels from the scrollable data area (controlled by the **BackColor** property).

While `BackColorHeader(BandNumber)` sets the color for headers of a specific hierarchical level, **BackColorFixed** is the general property for the grid's overall fixed boundaries. 

#### Key characteristics

**Visual distinction**: It is primarily used to separate header labels from the scrollable data area (which is controlled by the standard **BackColor** property).

**Interaction with headers**: In a hierarchical display, while **BackColorFixed** sets the general background for all frozen cells, you can use `BackColorHeader(BandNumber)` for more granular control over specific nested data levels.

**3D Effect**: If **GridLinesFixed** is set to *flexGridRaised* (the default), this color fills the face of the 3D "buttons" that make up the headers.

#### Example implementation

To set the fixed headers to a modern light gray and ensure they stand out:
```
' Sets the background color of all fixed rows and columns to light gray
grid.BackColorFixed = &HC0C0C0 ' vbSilver

' Alternatively, using a specific system color for theme consistency
grid.BackColorFixed = vbButtonFace
```
#### Technical tips

**Contrast**: To ensure readability, always pair this with the **ForeColorFixed** property to maintain high contrast between the header background and the text.

**Handling black**: Setting this property to 0 may cause it to revert to the default system color. To explicitly force a black header background, use the constant *vbBlack* or the literal value 1.

**Optimization**: When updating multiple color properties at once, set `Redraw = False` before the changes and `Redraw = True` afterward to prevent screen flickering.

---

### BackColorSel

Returns or sets the background color of the selected cells of the grid. This property applies to the entire control and determines the highlight color whenever a cell or range of cells is selected.

```
PROPERTY BackColorSel () AS OLE_COLOR
PROPERTY BackColorSel (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbHighlight, vbBlue), a hex code, or an RGB value. |

#### Remarks

**Highlight Behavior**: The color specified by **BackColorSel** is only visible when a cell is part of the current selection. If the control loses focus, the visibility of this highlight depends on the **Highlight** property setting: flexHighlightNever = 0, flexHighlightAlways = 1, flexHighlightWithFocus = 2.

While **BackColorSel** sets the color for the temporary selection highlight, **CellBackColor** is used to permanently change the background color of specific individual cells regardless of whether they are selected.

Unlike band-specific properties (e.g., **BackColorBand**), **BackColorSel** is a global property that affects all selected cells across all hierarchical levels. 

It is critical to pair this with the **ForeColorSel** property to ensure that the text remains readable against the selection background. 

#### Example implementation

To change the selection highlight to a custom soft blue for a more modern 2026 interface:
```
' Set the background of selected cells to a custom light blue
grid.BackColorSel = BGR(173, 216, 230)

' Set the text of selected cells to black for contrast
grid.ForeColorSel = vbBlack
```
## Technical tips

**Individual cell highlights**: If you need to "highlight" a cell permanently without it being the active selection, use **CellBackColor** instead. **BackColorSel** only applies while the cell is within the active selection range.

**System theme integration**: For modern application design, developers frequently use the constant *vbHighlight* to ensure the grid matches the user's current Windows theme.

**Flicker management**: When programmatically changing selection colors during a loop or complex data update, set `Redraw = False` to prevent visual stuttering.

---

### BackColorBkg

Returns or sets the background color of the grid. This property affects the overall appearance of the grid, especially when the control is larger than the total number of rows and columns displayed.

```
PROPERTY BackColorBkg () AS OLE_COLOR
PROPERTY BackColorBkg (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbDarkGray), a hex code, or an RGB value. |

#### Remarks

While **BackColor** sets the background for individual non-fixed data cells, **BackColorBkg** fills the "unused" space at the bottom and right of the grid. By default, this is often set to a dark gray color.

In hierarchical views, **BackColorUnpopulated** specifically targets the space within bands that does not contain data, whereas **BackColorBkg** is for the global control background.

A common practice is to set **BackColorBkg** to match the background color of the parent form to create a "borderless" or seamless appearance. 

#### Example implementation

To make the empty area of the grid match a standard white workspace:
```
' Sets the unused area background to white
grid.BackColorBkg = vbWhite

' To make it seamless with the form background
grid.BackColorBkg = this.BackColor
```

#### Technical tips

**Explicit black**: To ensure the background is true black, use the constant *vbBlack* or the literal value 1. Setting it to 0 may sometimes result in a default system gray.

**Visual padding**: If you want to simulate padding around your data, set the control size slightly larger than your columns/rows and use **BackColorBkg** to provide a surrounding border color.

**Redraw performance**: Changing this property triggers a full repaint of the control. When performing multiple visual updates, wrap your code in `Redraw = False` and `Redraw = True`.

---

### BackColorUnpopulated

Returns or sets the background color of the unpopulated area of the grid, i.e. areas within the grid that do not contain data.

```
PROPERTY BackColorUnpopulated () AS OLE_COLOR
PROPERTY BackColorUnpopulated (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbGrayText), a hex code, or an RGB value. |

#### Remarks

Unlike the global **BackColorBkg** (which covers the entirely empty area of the control), **BackColorUnpopulated** targets regions reserved for bands where no data exists. It is typically used to visually separate populated areas from unpopulated ones in complex, multi-level hierarchical displays.

It is commonly used to visually differentiate between bands that have data and those that are currently empty placeholders in a complex tree-like data view.

#### Example implementation

To make unpopulated areas appear as a subtle gray to indicate they are "empty" placeholders:
```
' Sets the background color for unpopulated cells in a hierarchical view
grid.BackColorUnpopulated = BGR(245, 245, 245) ' Very light gray
```

#### Technical tips

**Handling black**: Setting this property to 0 may cause it to revert to the default system background. To explicitly force a black background for unpopulated cells, use the constant vbBlack or the value 1.

**Theming**: For a clean, modern look, developers often match this property to the **BackColorBkg** to make empty structural areas blend seamlessly with the control's general background.

**Performance**: Changing this property triggers a repaint. If you are updating multiple visual properties at once, set `Redraw = False` before starting and **True** afterward to ensure a smooth transition.

---

### ForeColor

Returns or sets the foreground colors of individual cells or cell ranges. This property acts as the global default for all text within the scrollable area of the grid.

```
PROPERTY ForeColor () AS OLE_COLOR
PROPERTY ForeColor (BYVAL clr AS OLE_COLOR)
```
| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbBlue), a hex code, or an RGB value. |

#### Remarks

It affects all data cells simultaneously. It does not affect the text in fixed rows or columns; for those, you must use **ForeColorFixed**.

While **ForeColor** is the general default, in hierarchical views you can override text colors for specific data levels using the `ForeColorBand(BandNumber)` property.

To change the text color of a single specific cell, use the **CellForeColor** property after setting the **Row** and **Col** properties to target that cell. 

#### Example implementation

To set the default text color of the data area to a dark navy blue:
```
' Sets the global text color for all data cells
grid.ForeColor = BGR(0, 0, 102)

' Contrast with the header text color
grid.ForeColorFixed = vbWhite
```

#### Technical tips

Setting **ForeColor** to 0 may cause the grid to use the system's default text color rather than a true black. For an explicit black, use the constant *vbBlack* or the literal value 1.

Ensure the **ForeColor** provides high contrast against the **BackColor**. Accessibility standards generally recommend a contrast ratio of at least 4.5:1 for standard text.

If you are dynamically changing text colors in a loop, set `Redraw = False` before the operation and **True** afterward to ensure a flicker-free update. 

---

### ForeColorBand

Returns or sets the text color for for the data cells within a specific band (level) of a hierarchical display. 

```
PROPERTY ForeColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR
PROPERTY ForeColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY ForeColorBand () AS OLE_COLOR
PROPERTY ForeColorBand (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbBlue), a hex code, or an RGB value. |

#### Remarks

Like other band-specific properties, **ForeColorBand** is an array property that allows you to apply different text colors to different levels of nested data.

The primary use of **ForeColorBand** is to create visual distinction between data levels in a hierarchical grid. For example: Top-level data (Band 0): Can be set to a bold black for high visibility. Nested data (Band 1 or higher): Can be set to a softer color, like dark gray or blue, to indicate it is secondary or sub-detail information.

**ForeColorBand** overrides the global **ForeColor** setting for all cells within that specific band. However, the **CellForeColor** property can still be used to override an individual cell's color within that band.

This property specifically targets data cells. To change the text color of the headers for a specific band, use the **ForeColorHeader** property instead.

#### Example implementation

To set the primary band (Band 0) to black and the first child band (Band 1) to a dark red:
```
' Setting text color for the parent level
grid.ForeColorBand(0) = vbBlack

' Setting text color for the child level
grid.ForeColorBand(1) = RGB(150, 0, 0)
```

#### Technical tips

Setting the property to 0 may revert to the system default color. To ensure text is explicitly black, use the constant *vbBlack* or the literal value 1.

When updating multiple band colors at runtime, wrap the code in `Redraw = False` and Redraw = **True** to prevent screen flickering.

---

### ForeColorFixed

Returns or sets the text color for all fixed cells in the control. Fixed cells are non-scrolling areas typically used for data labels or column headers.

```
PROPERTY ForeColorFixed () AS OLE_COLOR
PROPERTY ForeColorFixed (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbBlue), a system constant (e.g. vbHighlight), a hex code, or an RGB value. |

#### Remarks

It is important to distinguish ForeColorFixed from band-specific properties in the MSHFlexGrid:

**ForeColorFixed**: A global property that sets the text color for the entire fixed area (defined by **FixedRows** and **FixedCols**).

**ForeColorHeader(BandNumber)**: A targeted property that sets the text color specifically for the headers of a nested hierarchical level (band).

#### Technical tips

**Consistency**: For a professional look, **ForeColorFixed** is typically paired with **BackColorFixed** to ensure readability.

**Black text**: Setting the property to 0 may result in the default system color. To explicitly force black text, use the constant *vbBlack* or the literal value 1.

**Optimization**: When updating multiple visual properties (like text and background colors), set `Redraw = False` before changes and `Redraw = True` afterward to prevent screen flickering.

**Interaction with bands**: While **ForeColorFixed** provides a global setting for all headers, the `MSHFlexGrid` also supports `ForeColorHeader(BandNumber)` for granular control over the text colors of specific nested hierarchical levels. 

#### Example implementation

To set the header text of the entire grid to a high-contrast white:
```
' Sets the text color for all fixed headers to white
grid.ForeColorFixed = vbWhite

' Alternatively, setting it to a custom theme blue
grid.ForeColorFixed = BGR(0, 51, 153)
```
---

### ForeColorHeader

Returns or sets the text color for for the header cells within a specific hierarchical band.

```
PROPERTY ForeColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR
PROPERTY ForeColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY ForeColorHeader () AS OLE_COLOR
PROPERTY ForeColorHeader (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbBlue), a hex code, or an RGB value. |

#### Remarks

This is an array-based property, meaning you must specify which band index (level of data) you are targeting.

While **ForeColorFixed** sets the text color for all fixed headers globally, **ForeColorHeader** allows you to apply unique colors to the headers of different nested data levels.

Because `MSHFlexGrid` is often used for read-only hierarchical data displays, this property is primarily used to enhance the readability of different data levels. Developers typically match **ForeColorHeader** with a contrasting **BackColorHeader** for that same band index to ensure header labels remain legible.

Setting the property to 0 may result in the default system text color. To force an explicit black color, use the constant *vbBlack* or the literal value 1.

When updating multiple band-specific visual settings, it is best practice to set `Redraw = False` before starting and **True** afterward to ensure a smooth, flicker-free update on modern displays.

#### Example implementation

To apply specific colors to the headers of a multi-level grid:
```
' Set the parent band (Band 0) header text to white
grid.ForeColorHeader(0) = vbWhite

' Set the first child band (Band 1) header text to a custom blue
grid.ForeColorHeader(1) = BGR(0, 0, 255)
```
---

### ForeColorSel

Returns or sets the text color for all fixed cells in the control. Fixed cells are non-scrolling areas typically used for data labels or column headers.

```
PROPERTY ForeColorSel () AS OLE_COLOR
PROPERTY ForeColorSel (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a Visual Basic constant (e.g. vbWhite), a system constant (e.g. vbHighlightText), a hex code, or an RGB value. |

#### Remarks

**ForeColorSel** works in tandem with **BackColorSel** to ensure that selected text remains readable against the highlight background. To maintain readability, ensure there is high contrast between the selection background and the text color (e.g., white text on a dark blue background).

Unlike band-specific properties, this applies to all selected cells regardless of which hierarchical level (band) they belong to.

The selected color is only visible if the selection is active. To ensure selection colors are always visible even when the control loses focus, set the **Highlight** property to *flexHighlightAlways*.

#### Technical tips

**Individual cell overrides**: Note that setting **CellForeColor** for a specific cell will typically be overridden by **ForeColorSel** the moment that cell becomes part of an active selection.

**System theme integration**: In modern application design, developers often use the constant *vbHighlightText* to ensure the grid follows the user's current Windows desktop theme.

**Handling black**: Setting the property to 0 may result in the default system text color. To explicitly force black text for selected items, use the constant **vbBlack** or the literal value 1.

#### Example implementation

To set a high-contrast white text for any selected cells against a custom dark blue highlight:
```
' Set the background of selected cells to dark blue
grid.BackColorSel = BGR(0, 0, 128)

' Set the text of selected cells to white for clarity
grid.ForeColorSel = vbWhite
```
---

### Rows

Returns or sets the total number of rows in the grid. It is used both to set the capacity of the grid and to retrieve the current row count.

```
PROPERTY Rows () AS LONG
PROPERTY Rows (BYVAL nRows AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nRows* | Specifies the total number of rows, including both data rows and fixed (header) rows. The value of *nRows* must be at least one greater than the value of **FixedRows**, unless they are both set to zero. |

#### Remarks

**Dynamic resizing**: You can increase or decrease the number of rows at runtime by simply assigning a new value to the property.

**Automatic management**: When bound to a data source, the `MSHFlexGrid` typically sets the **Rows** property automatically based on the number of records in the recordset plus the number of fixed rows.

**Zero-based indexing**: Row indexing starts at 0. If you have 1 fixed row, it is Row 0; the first data row will be Row 1.

**Memory limit**: The minimum number of rows and columns is 0. The maximum number is limited by the memory available on your computer.

#### Example implementation
To programmatically add a new row to the end of the grid:
```
' Increment the row count by one
grid.Rows = MSHFlexGrid1.Rows + 1
```
To clear all data while preserving a single header row:
```
' Resets the grid to only display the fixed header
grid.Rows = 1
```

#### Technical constraints

Visual Truncation: On modern high-resolution displays, ensure that the **RowHeight** is set appropriately; if **Rows** is set to a very high number, the vertical scrollbar will handle navigation, but the control's internal 16-bit coordinate system (inherited from its legacy architecture) can occasionally cause rendering issues if a single row's height is excessively large. 

---

### Cols

Returns or sets the total number of columns in the grid.

```
PROPERTY Cols (BYVAL BandNumber AS LONG) AS LONG
PROPERTY Cols (BYVAL BandNumber AS LONG, BYVAL nCols AS LONG)
PROPERTY Cols () AS LONG
PROPERTY Cols (BYVAL nCols AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background column count is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *nCols* | Specifies the number of columns. The value of *nCols* must be at least one greater than the value of **FixedCols**, unless they are both set to zero.|

#### Remarks

**Dynamic resizing**: You can add or remove columns at runtime by changing this value. For example, grid.Cols = 10 immediately sets the grid to have 10 columns.

**Zero-based indexing**: Columns are indexed starting at 0. If **Cols** is set to 5, the valid column indices are 0 through 4.

**Fixed columns**: The **FixedCols** property (which defines non-scrolling label columns) must always be less than the total **Cols** value.

#### Capacity and memory limits

**Cell limit**: The `MSHFlexGrid`'s total capacity is governed by a cell limit (Rows × Cols). The minimum number of rows and columns is 0. The maximum number is limited by the memory available on your computer.

**Column max**: Theoretically, you can have thousands of columns, but in practice, performance and memory usually restrict this to a few hundred for stable application behavior.

#### Example implementation

To define a grid with one frozen header column and five scrollable data columns:
```
' Total columns must be greater than FixedCols
grid.Cols = 6      ' 1 fixed + 5 data
grid.FixedCols = 1  ' Freeze the first column
```
#### Technical tips

**Inserting columns**: There is no native **InsertColumn** method. To insert a column at a specific position, you must increase the **Cols** property and then manually move data using the **TextMatrix** property.

**Performance**: When resizing a large number of columns, set `Redraw = False` before making changes to prevent screen flickering. 

---

### FixedRows

Returns or sets the total number of fixed rows in the grid. This property specifies how many rows are "frozen" as headers that do not move when the user scrolls through the data.

```
PROPERTY FixedRows () AS LONG
PROPERTY FixedRows (BYVAL nRows AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nRows* | Specifies the total number of fixed rows. The value of **FixedRows** must be at least 1 less than the total number of **Rows** (unless **Rows** is 0). |

#### Key characteristics

**Non-selectable**: Fixed rows cannot be selected or edited by the user through standard mouse or keyboard actions, though they can be modified via code.

**Visual distinction**: These rows typically use the colors defined by **BackColorFixed** and **ForeColorFixed** to differentiate them from the scrollable data area.

**Automatic headers**: When bound to a database, the `MSHFlexGrid` often uses the first fixed row to display field names automatically.

#### Remarks

In an `MSHFlexGrid`, **FixedRows** generally accounts for the primary headers. If the grid is displaying hierarchical bands, those bands may have their own internal headers, but **FixedRows** specifically defines the global frozen area at the top.

Cells within fixed rows cannot be selected or edited by the user via standard mouse or keyboard actions, although they can be modified programmatically using the **TextMatrix** property.

The value of **FixedRows** must always be less than the total number of rows (**Rows**). Attempting to set **FixedRows** equal to or greater than **Rows** will result in a runtime error. 

Fixed columns and rows are constant when you scroll other columns or rows in the `MSHFlexGrid`. You can specify zero or multiple fixed columns rows. In addition, you can select the colors, font, gridline, and text style of the fixed columns and rows.

If the **SelectionMode** property is a numerical value, when you select a fixed row at run time, all cells within that row are selected.

If the **AllowUserResizing** property is a numerical value, you can resize the fixed rows or fixed columns at run time.

Fixed columns and fixed rows are used in spreadsheet applications to display row numbers and column names or letters.

#### Example implementation

To set up a grid with two frozen header rows (useful for multi-line labels):
```
' Ensure total rows are set before defining fixed rows
grid.Rows = 20
grid.FixedRows = 2
```
#### Technical tips

**Order of operations**: Always set the **Rows** property before the **FixedRows** property to avoid "Invalid Property Value" errors.

**Styling**: The background and text colors of these rows are globally controlled by the **BackColorFixed** and **ForeColorFixed** properties.

**Dynamic adjustment**: You can set `FixedRows = 0` at runtime if you want to remove all headers and allow the entire grid to scroll.

**Resizing**: If **AllowUserResizing** is enabled, users can still resize the height of fixed rows even though the content is frozen.

---

### FixedCols

Returns or sets the total number of fixed columns in the grid. This property specifies how many columns are "frozen" as headers that do not move when the user scrolls through the data.

```
PROPERTY FixedCols () AS LONG
PROPERTY FixedCols (BYVAL nCols AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nCols* | Specifies the total number of fixed columns. The value must be at least 1 less than the total number of columns **(**Cols**), or a runtime error will occur. |

#### Key characteristics

**Frozen position**: Fixed columns are always positioned at the far left edge of the grid and do not move during horizontal scrolling.

**Interaction restrictions**: By default, cells in fixed columns are not selectable or editable by the user via mouse or keyboard, although they can be modified through code using the **TextMatrix** property.

**Visual style**: These columns use the global settings defined by **BackColorFixed** and **ForeColorFixed** to distinguish them from standard data cells.

**Automatic sizing**: If **AllowUserResizing** is enabled, users can still resize the width of fixed columns at runtime.

**Hierarchical views**: When using hierarchical data, **FixedCols** applies to the entire grid structure, providing a consistent reference point for all bands.

#### Remarks

Fixed columns and rows are constant when you scroll other columns or rows in the `MSHFlexGrid`. You can specify zero or multiple fixed columns rows. In addition, you can select the colors, font, gridline, and text style of the fixed columns and rows.

If the **SelectionMode** property is a numerical value, when you select a fixed column at run time, all cells within that column are selected.

If the **AllowUserResizing** property is a numerical value, you can resize the fixed rows or fixed columns at run time.

Fixed columns and fixed rows are used in spreadsheet applications to display row numbers and column names or letters.

#### Example implementation
To set up a grid with one frozen column (Index 0) and four scrollable data columns:
```
' Always set total Cols before FixedCols
grid.Cols = 5
grid.FixedCols = 1

' Populate the fixed column with a label
grid.TextMatrix(0, 0) = "Record ID"
```

#### Technical tips

**Setting sequence**: If you attempt to set **FixedCols** to a value equal to or greater than the current **Cols** property, the control will throw an "Invalid property value" error.

**Data access**: You can still read or write data to fixed columns programmatically using the `TextMatrix(row, col)` property.

**Disabling headers**: To make the entire grid scrollable horizontally with no frozen columns, set `FixedCols = 0`.

### FixedAlignment

Returns or sets the alignment of data in the fixed cells of a column in an `MSHFlexGrid`. Allows you to align column headers independently of the data in the scrollable cells.

```
PROPERTY FixedAlignment (BYVAL Index AS LONG) AS SHORT
PROPERTY FixedAlignment (BYVAL Index AS LONG, BYVAL alignment AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the column to be formatted. |
| *alignment* | An integer or constant that specifies both the horizontal and vertical alignment. |

The settings for **FixedAlignment** are the same as those used for **ColAlignment**:

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | Left, Top |
| *flexAlignLeftCenter* | 1 | (Default for strings) Left, Center |
| *flexAlignLeftBottom* | 2 | Left, Bottom |
| *flexAlignCenterTop* | 3 | Center, Top |
| *flexAlignCenterCenter* | 4 | Center, Center |
| *flexAlignCenterBottom* | 5 | Center, Bottom |
| *flexAlignRightTop* | 6 | Right, Top |
| *flexAlignRightCenter* | 7 | (Default for numbers) Right, Center |
| *flexAlignRightBottom* | 8 | Right, Bottom |
| *flexAlignGeneral* | 9 | Left for strings, Right for numbers |

#### Remarks

While the global **ColAlignment** property typically affects an entire column—including its headers—**FixedAlignment** explicitly overrides that setting for the cells in the fixed rows (headers) of that column.

It is commonly used when you want a column's data to be right-aligned (for numbers) but its header to be centered or left-aligned. 

#### Example implementation

To center a header while keeping the numeric data in that column right-aligned:
```
' Set the data area of the second column (Index 1) to right-center
grid.ColAlignment(1) = flexAlignRightCenter

' Override only the header (Fixed Row) of the same column to center-center
grid.FixedAlignment(1) = flexAlignCenterCenter
```

#### Technical considerations

Fixed cells are generally read-only for the user, but you can still programmatically update their text using `TextMatrix(0, ColIndex)` and then apply **FixedAlignment** to style that text.

In some legacy versions of `MSHFlexGrid`, the justification defined within a **FormatString** (e.g., using ^ or >) may be ignored for fixed rows. Using the **FixedAlignment** property programmatically is the standard workaround to ensure headers are correctly positioned.

---

### Row

Returns or sets the row position of the active cell or the start of a selection.

```
PROPERTY Row () AS LONG
PROPERTY Row (BYVAL nRow AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nRow* | The row position of the active cell. The first row in the grid is index 0. If you have one fixed header row, the first data row is typically index 1. |

#### Remarks

This property identifies the vertical position of the active cell or the start of a selection.

To modify a cell’s value without changing the selected **Row** and **Col** properties, use the **TextMatrix** property.

#### Key functions

**Targeting cells**: The **Row** and **Col** properties together specify the active cell. Properties like **Text**, **CellBackColor**, and **CellForeColor** all apply specifically to the cell located at the intersection of **Row** and **Col**.

**Managing selections**: Setting the **Row** property resets the **RowSel** property to the same value. To select a range of rows, you must set **Row** (the starting point) first, followed by **RowSel** (the ending point).

**Runtime navigation**: You can programmatically move the user's focus or the active selection by changing the **Row** value.

**Detecting user interaction**: You can use the **Row** property inside a **Click** or **EnterCell** event to determine which row the user has just selected.

#### Example implementation

To select the fifth row (Index 4) and retrieve its text:
```
' Move the active focus to the fifth row
grid.Row = 4
grid.Col = 1 ' Specify the column too

' Retrieve the text from that active cell
Dim cellData As DWString
cellData = grid.Text
```

#### Technical tips

**Subscript out of range**: Attempting to set **Row** to a value greater than or equal to the total **Rows** count will result in a runtime error.

**Event handling**: Use the **Row** property inside a **Click** or **EnterCell** event to determine which row the user has just clicked.

**Data access alternative**: If you need to read or write data to a cell without moving the user's focus (the highlight), use the **TextMatrix** property instead of changing the **Row** and **Col** properties. 

---

### Col

Returns or sets the column position of the active cell or the start of a selection.

```
PROPERTY Col () AS LONG
PROPERTY Col (BYVAL nCol AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nCol* | The column position of the active cell. Column indices start at 0. If the grid has one fixed column, the first scrollable data column is typically index 1. |

#### Remarks

This property identifies the horizontal position of the active cell or the start of a selection.

To modify a cell’s value without changing the selected **Row** and **Col** properties, use the **TextMatrix** property.

#### Key functions

**Defining the active cell**: Together with the **Row** property, **Col** specifies the coordinates of the active cell. Subsequent properties such as **Text**, **CellBackColor**, and **CellForeColor** apply specifically to this targeted cell.

**Selection management**: Setting the **Col** property automatically resets the **ColSel** property to the same value. To select a block of columns, you must set **Col** (the starting edge) first, then set **ColSel** (the ending edge).

**Runtime navigation**: You can programmatically move the user's focus across the grid by changing the **Col** value.

#### Example implementation

To select the second column (Index 1) and change its text color:
```
' Move the active focus to the second column
grid.Col = 1

' The following property now applies to the cell at current Row/Col
grid.CellForeColor = vbRed
```

#### Technical tips

**Subscript out of range**: Setting **Col** to a value equal to or greater than the total column count (**Cols**) will trigger a runtime error.

**Alternative data access**: If you need to read or write data to a cell without moving the user's focus (avoiding visual flickering), use the `TextMatrix(row, col)` property instead of changing **Col** and **Row**.

**User interaction**: You can use the **Col** property within events like **Click** or **EnterCell** to determine which column the user has just interacted with. 

---

### RowSel

Returns or sets the start or end row for a range of cells.

```
PROPERTY RowSel () AS LONG
PROPERTY RowSel (BYVAL nRow AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nRow* | A Long value that specifies the start or end row for a range of cells. |

#### Remarks

**RowSel** works in conjunction with the **Row** property to define a vertical selection block. The selection spans from the row index specified by **Row** to the row index specified by **RowSel**.

Whenever you set the **Row** and **Col** properties, **RowSel** and **ColSel** are automatically reset, so the cursor becomes the current selection. To select a block of cells from code, you must first set the **Row** and **Col** properties, and then set **RowSel** and **ColSel**. Note that **RowSel** may be above or below **Row**, and **ColSel** may be to the left or to the right of **Col**.

#### Key behaviors

**Automatic reset**: Whenever you set the **Row** property, **RowSel** is automatically reset to the same value. To select multiple rows, you must set **Row** first and then set **RowSel**.

**Directional selection**: **RowSel** can be less than, equal to, or greater than **Row**. The grid handles the highlight regardless of which index is higher.

**Selection mode**: The visual effect of **RowSel** is influenced by the **SelectionMode** property. If **SelectionMode** is set to 1 - *flexSelectionByRow*, the grid will highlight the entire span of rows between **Row** and **RowSel**, regardless of column settings.

#### Example implementation

To programmatically select a block of rows from index 1 to index 10:
```
grid.Row = 1     ' Set the starting row of the selection
grid.RowSel = 10 ' Extend the selection to the ending row
```
#### Technical tips

**Normalization for loops**: Because **RowSel** can be smaller than **Row**, use the **Min** and **Max** values (or `Abs(RowSel - Row)`) when looping through selected rows to avoid errors.

**Identifying user selection**: Use **RowSel** in events like **MouseUp** or **SelChange** to determine exactly which rows the user has highlighted.

**Clearing selection**: To remove a multi-row highlight and focus on a single cell, simply set **RowSel** = **Row**. 

---

### ColSel

Returns or sets the start or end column for a range of cells.

```
PROPERTY ColSel () AS LONG
PROPERTY ColSel (BYVAL nCol AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nCol* | A Long value that specifies the start or end column for a range of cells. |

#### Remarks

**ColSel** works in conjunction with the **Col** property to define a horizontal selection block. The selection spans from the column index specified by **Col** to the column index specified by **ColSel**.

Whenever you set the **Row** and **Col** properties, **RowSel** and **ColSel** are automatically reset, so the cursor becomes the current selection. To select a block of cells from code, you must first set the **Row** and **Col** properties, and then set **RowSel** and **ColSel**. Note that **RowSel** may be above or below **Row**, and **ColSel** may be to the left or to the right of **Col**.

#### Key characteristics

**Automatic reset**: Whenever the **Col** property is set, **ColSel** is automatically reset to match it. To select a range, you must assign **Col** first, followed by **ColSel**.

**Selection direction**: **ColSel** can be a higher or lower index than **Col**. The grid will correctly highlight the range regardless of the numerical order.

**Block selection**: When used alongside **Row** and **RowSel**, these four properties define a rectangular block of selected cells.

#### Example implementation

To programmatically highlight a range of columns from index 1 through index 3:
```
' Move the active focus to the start of the range
grid.Col = 1 

' Extend the selection highlight to the end of the range
grid.ColSel = 3 
```

#### Technical tips

**SelectionMode interaction**: If the **SelectionMode** property is set to *flexSelectionByRow*, changing **ColSel** will still define the internal selection range, but the visual highlight will always occupy the full width of the row.

**Identifying user input**: Use **ColSel** in the **MouseUp** or **SelChange** events to detect which columns the user has highlighted.

**Boundary check**: Attempting to set **ColSel** to a value equal to or greater than the total column count (**Cols**) will trigger a "Subscript out of range" runtime error.

---

### TopRow

Returns or sets the uppermost visible row (other than a fixed row) in the grid. It sets or returns the index of the first visible scrollable row at the top of the grid. 

```
PROPERTY TopRow () AS LONG
PROPERTY TopRow (BYVAL nRow AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nRow* |  A Long value that specifies the uppermost row in the grid. |

#### Remarks

Assigning a value to **TopRow** causes the grid to scroll so that the specified row index is the topmost row displayed immediately below the fixed header rows. 

#### Key characteristics

**Scrolling limitation**: You cannot set **TopRow** to a value that would cause empty space to appear below the last row. The maximum valid value is the total number of rows minus the number of rows currently visible in the grid's display area.

**Automatic adjustment**: If you attempt to set **TopRow** to a value greater than the maximum possible, the grid will automatically reset it to the largest valid value to keep the last record visible.

**Read/Write**: It can be used to capture the current scroll position (e.g., currentPos = grid.TopRow) to return the user to the same view later.

#### Example implementation

To programmatically scroll to the 50th row (Index 49):
```
' Ensure row 49 is at the top of the visible data area
grid.TopRow = 49
```
To ensure the very last row is visible (common after adding new data):
```
' Scroll to the bottom as far as possible
grid.TopRow = grid.Rows - 1
```
#### Technical tips

**Scrollbar dependency**: Some versions of the control may require scrollbars to be enabled for **TopRow** to function correctly programmatically.

**Synchronization**: This property is ideal for synchronizing two grids; setting the **TopRow** of a second grid to match the first ensures their vertical views stay aligned.

**Horizontal equivalent**: To programmatically scroll the grid horizontally, use the **LeftCol** property. 

---

### LeftCol

Returns or sets the left-most visible non fixed column in the grid.

```
PROPERTY LeftCol () AS LONG
PROPERTY LeftCol (BYVAL nCol AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nCol* |  A Long value that specifies the left-most column. |

#### Remarks

When you assign a value to **LeftCol**, the grid scrolls horizontally so that the specified column index is displayed immediately to the right of any fixed columns.

#### Key characteristics

**Horizontal navigation**: This property is the horizontal equivalent of the **TopRow** property.

**Scrolling boundaries**: You cannot set **LeftCol** to a value that would cause empty space to be displayed at the right edge of the grid. The property automatically adjusts to the maximum possible value based on the total number of columns and the width of the control.

**Read/Write**: It can be used to save a user's horizontal scroll position before a grid refresh so that the view can be restored afterward.

#### Example implementation

To programmatically scroll the grid so that the 10th column (Index 9) is the first visible column:
```
' Scroll horizontally to show column 9
grid.LeftCol = 9
```
To reset the view back to the start of the data:
```
' Reset horizontal scroll to the first scrollable column
grid.LeftCol = grid.FixedCols
```
#### Technical tips

**View vs. focus**: Changing **LeftCol** only moves the visible viewport. It does not change the active cell (**Col** property). To move the selection focus to that column, you must set `grid.Col = 9` separately.

**Grid synchronization**: This property is frequently used to synchronize the horizontal scrolling of two separate grid controls (e.g., a header grid and a data grid) so they always display the same columns.

**Performance**: If changing **LeftCol** as part of a larger visual update, set `Redraw = False` before and `Redraw = True` after to ensure a smooth transition without flickering.

---

### GridLines

Returns or sets a value that determines whether lines are drawn between cells.

```
PROPERTY GridLines () AS GridLineSettings
PROPERTY GridLines (BYVAL value AS GridLineSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *value* |  A Long value or constant that specifies the type of lines drawn, as described in *Settings*. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexGridNone* | 0 | There are no lines between cells. In the `MSFlexGrid`, this is the default for **GridLines**. |
| *flexGridFlat* | 1 | The line style between cells is set to normal, flat, lines. In the `MSHFlexGrid`, this is the default for **GridLines**. |
| *flexGridInset* | 2 | The line style between cells is set to inset lines (lines appear sunken into the grid surface.). In the `MSFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridRaised* | 3 | The line style between cells is set to raised lines (lines appear to pop out from the grid surface.). In the `MSHFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridDashes* | 4 | The line style between cells is set to dashed lines. |
| *flexGridDots* | 5 | The line style between cells is set to dotted lines. |

#### Remarks

When the **GridLines** property is set to 1 (flat lines), the color of the lines is determined by the **GridColor** property. However, if using *flexGridInset* or *flexGridRaised*, the colors are typically managed by the system to maintain the 3D effect. Raised and inset gridlines are always black and white.

**Visual grouping**: If you want to group rows visually without lines, set `GridLines = flexGridNone` and use alternating **CellBackColor** values to create a "zebra stripe" effect.

**Hierarchical bands**: In hierarchical mode, gridlines apply consistently across all bands. If you need distinct line styles for specific data levels, you typically have to manage this through background color contrast rather than the **GridLines** property itself.

#### Example implementation

To remove all lines between data cells for a cleaner "list" appearance:
```
' Removes all internal data gridlines
grid.GridLines = flexGridNone
```
#### Technical tips

**Modern UI design**: For applications running on Windows 10/11, many developers prefer *flexGridFlat* (1) with a very light GridColor (like BGR(230, 230, 230)) to match modern flat-design aesthetics.

**Performance**: Changing the line style triggers a complete repaint of the control. For large grids, set `Redraw = False` before changing this property. 

**Individual cells**: You cannot change the gridline style for a single specific cell; it is a global setting for the data area. To "remove" lines for one cell, you would typically match the **GridColor** to that cell's **CellBackColor**. 

---

### GridLinesFixed

Returns or sets a value that determines whether lines are drawn between cells. This property specifically targets the lines within the fixed areas defined by **FixedRows** and **FixedCols**. 

```
PROPERTY GridLinesFixed () AS GridLineSettings
PROPERTY GridLinesFixed (BYVAL value AS GridLineSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *value* |  A Long value or constant that specifies the type of lines drawn, as described in *Settings*. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexGridNone* | 0 | There are no lines between cells. In the `MSFlexGrid`, this is the default for **GridLines**. |
| *flexGridFlat* | 1 | The line style between cells is set to normal, flat, lines. In the `MSHFlexGrid`, this is the default for **GridLines**. |
| *flexGridInset* | 2 | The line style between cells is set to inset lines (lines appear sunken into the grid surface.). In the `MSFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridRaised* | 3 | The line style between cells is set to raised lines (lines appear to pop out from the grid surface.). In the `MSHFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridDashes* | 4 | The line style between cells is set to dashed lines. |
| *flexGridDots* | 5 | The line style between cells is set to dotted lines. |

#### Remarks

This setting applies to all fixed headers, including those generated by hierarchical bands. 

When the **GridLinesFixed** property is set to 1 (flat lines), the color of the lines is determined by the **GridColorFixed** property.

Raised and inset gridlines are always black and white.

Changing the line style triggers a complete repaint of the control. For large grids, set `Redraw = False` before changing this property. 

#### Example implementation

To create a modern, flat-design header for an application running in 2026:
```
' Remove the 3D effect for a cleaner, modern look
grid.GridLinesFixed = flexGridFlat

' Set the header line color to a dark gray
grid.GridColorFixed = BGR(128, 128, 128)
```
#### Technical tips

**Visual consistency**: To avoid a jarring interface, ensure **GridLinesFixed** matches the style of the global **GridLines** (used for the data area) unless a distinct visual separation is intended.

**Accessibility**: On modern high-DPI displays, *flexGridFlat* (1) often provides better visual clarity than the legacy 3D styles, which can appear blurry or too thin at high resolutions.

---

### GridLinesBand

Returns or sets the gridline style for a specific band within the hierarchical display.

```
PROPERTY GridLinesBand (BYVAL BandNumber AS LONG) AS GridLineSettings
PROPERTY GridLinesBand (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
PROPERTY GridLinesBand () AS GridLineSettings
PROPERTY GridLinesBand (BYVAL value AS GridLineSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *value* |  A Long value or constant that specifies the type of lines drawn, as described in *Settings*. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexGridNone* | 0 | There are no lines between cells. In the `MSFlexGrid`, this is the default for **GridLines**. |
| *flexGridFlat* | 1 | The line style between cells is set to normal, flat, lines. In the `MSHFlexGrid`, this is the default for **GridLines**. |
| *flexGridInset* | 2 | The line style between cells is set to inset lines (lines appear sunken into the grid surface.). In the `MSFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridRaised* | 3 | The line style between cells is set to raised lines (lines appear to pop out from the grid surface.). In the `MSHFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridDashes* | 4 | The line style between cells is set to dashed lines. |
| *flexGridDots* | 5 | The line style between cells is set to dotted lines. |

#### Remarks

When the **GridLinesBand** property is set to 1 (flat lines), the color of the lines is determined by the **GridColorBand** property.

Raised and inset gridlines are always black and white.

Changing the line style triggers a complete repaint of the control. For large grids, set `Redraw = False` before changing this property. 

Unlike the global **GridLines** property, **GridLinesBand** is an array property indexed by the band number, allowing you to define different line styles for each level of the data hierarchy.

**Hierarchical distinction**: It allows for unique visual styling of different nested levels. For example, you might want a parent band to have clear 3D dividers while child bands appear flat and minimalist.

**Color control**: The color of these lines is determined globally by the **GridColor** property. You cannot set a unique line color for a single band using this property.

#### Example implementation

To give the primary band a 3D look while making the first child band flat:
```
' Sets parent band (Band 0) to raised lines
grid.GridLinesBand(0) = flexGridRaised

' Sets first child band (Band 1) to standard flat lines
grid.GridLinesBand(1) = flexGridFlat
```
#### Technical tips

**Hiding Lines for Specific Levels**: To make a specific level of detail look like a plain list without dividers, set `GridLinesBand(BandNumber) = flexGridNone`.

**Visual synchronization**: For a professional look, developers often match the **GridLinesBand** style with the **GridLinesHeader** style for that same band index.

**Performance**: When updating multiple band-specific settings at runtime, wrap your code in `Redraw = False` and `Redraw = True` to prevent visual flickering.

---

### GridLinesHeader

Returns or sets a value that determines whether lines are drawn within the header area of a specified band.

```
PROPERTY GridLinesHeader (BYVAL BandNumber AS LONG) AS GridLineSettings
PROPERTY GridLinesHeader (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
PROPERTY GridLinesHeader () AS GridLineSettings
PROPERTY GridLinesHeader (BYVAL value AS GridLineSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *value* |  A Long value or constant that specifies the type of lines drawn, as described in *Settings*. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexGridNone* | 0 | There are no lines between cells. In the `MSFlexGrid`, this is the default for **GridLines**. |
| *flexGridFlat* | 1 | The line style between cells is set to normal, flat, lines. In the `MSHFlexGrid`, this is the default for **GridLines**. |
| *flexGridInset* | 2 | The line style between cells is set to inset lines (lines appear sunken into the grid surface.). In the `MSFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridRaised* | 3 | The line style between cells is set to raised lines (lines appear to pop out from the grid surface.). In the `MSHFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridDashes* | 4 | The line style between cells is set to dashed lines. |
| *flexGridDots* | 5 | The line style between cells is set to dotted lines. |

#### Remarks

While the global **GridLinesFixed** property sets the style for the overall fixed areas of the grid, **GridLinesHeader** provides granular control over the internal headers of each hierarchical level.

The color of these lines is determined globally by the **GridColorFixed** property. However, this color only applies if the style is set to *flexGridFlat*. For 3D styles (Inset/Raised), the system uses standard highlight and shadow colors. Raised and inset gridlines are always black and white.

Unlike the global **GridLines** property, **GridLinesHeader** is an array property indexed by the band number, allowing you to apply different visual styles to the header gridlines for each level of nested data.

#### Example implementation

To give a parent band's header a flat look while maintaining the traditional 3D look for child bands:
```
' Sets the header of the primary band (Band 0) to flat lines
grid.GridLinesHeader(0) = flexGridFlat

' Sets the header of the child band (Band 1) to a raised 3D look
grid.GridLinesHeader(1) = flexGridRaised
```
#### Technical tips

**Hiding headers**: To make headers appear as a single solid block without internal dividers, set `GridLinesHeader(BandNumber) = flexGridNone`.

**Visual synchronization**: For professional interfaces, developers often match the **GridLinesHeader** style with the **GridLinesBand** style of the corresponding data area to maintain a consistent visual theme for that level of the hierarchy.

**Performance**: If updating multiple bands at once, set `Redraw = False` before changes and `Redraw = True` afterward to ensure a smooth, flicker-free update.

---

### GridLinesIndent

Returns or sets a value that determines whether lines are drawn within the indented area of a specified band.

```
PROPERTY GridLinesIndent (BYVAL BandNumber AS LONG) AS GridLineSettings
PROPERTY GridLinesIndent (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
PROPERTY GridLinesIndent () AS GridLineSettings
PROPERTY GridLinesIndent (BYVAL value AS GridLineSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *value* |  A Long value or constant that specifies the type of lines drawn, as described in *Settings*. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexGridNone* | 0 | There are no lines between cells. In the `MSFlexGrid`, this is the default for **GridLines**. |
| *flexGridFlat* | 1 | The line style between cells is set to normal, flat, lines. In the `MSHFlexGrid`, this is the default for **GridLines**. |
| *flexGridInset* | 2 | The line style between cells is set to inset lines (lines appear sunken into the grid surface.). In the `MSFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridRaised* | 3 | The line style between cells is set to raised lines (lines appear to pop out from the grid surface.). In the `MSHFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridDashes* | 4 | The line style between cells is set to dashed lines. |
| *flexGridDots* | 5 | The line style between cells is set to dotted lines. |

#### Remarks

When the **GridLinesIndent** property is set to 1 (flat lines), the color of the lines is determined by the **GridColorIndent** property. Raised and inset gridlines are always black and white.

Changing the line style triggers a complete repaint of the control. For large grids, set `Redraw = False` before changing this property. 

Unlike the global **GridLines** property, **GridLinesIndent** is an array property indexed by the band number, allowing you to apply different visual styles to the indent gridlines for each level of nested data.

The indent area is unique to the `MSHFlexGrid`'s hierarchical view. This property allows you to maintain visual consistency across the gaps between parent and child data.

#### Example implementation

To remove gridlines from the indentation of the first child level for a cleaner appearance:
```
' Target the first child band (Band 1)
' Remove lines from its indentation area
grid.GridLinesIndent(1) = flexGridNone
```
#### Technical tips

**Seamless interface**: Many modern developers set **GridLinesIndent** to *flexGridNone* to make the hierarchy appear as a continuous block rather than separate boxes.

---

### GridLinesUnpopulated

Returns or sets a value that determines whether lines are drawn within the unpopulated areas of the grid.

```
PROPERTY GridLinesUnpopulated (BYVAL BandNumber AS LONG) AS GridLineSettings
PROPERTY GridLinesUnpopulated (BYVAL BandNumber AS LONG, BYVAL value AS GridLineSettings)
PROPERTY GridLinesUnpopulated () AS GridLineSettings
PROPERTY GridLinesUnpopulated (BYVAL value AS GridLineSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *value* |  A Long value or constant that specifies the type of lines drawn, as described in *Settings*. |

#### Settings

The settings for value are:

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexGridNone* | 0 | There are no lines between cells. In the `MSFlexGrid`, this is the default for **GridLines**. |
| *flexGridFlat* | 1 | The line style between cells is set to normal, flat, lines. In the `MSHFlexGrid`, this is the default for **GridLines**. |
| *flexGridInset* | 2 | The line style between cells is set to inset lines (lines appear sunken into the grid surface.). In the `MSFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridRaised* | 3 | The line style between cells is set to raised lines (lines appear to pop out from the grid surface.). In the `MSHFlexGrid`, this is the default for **GridLinesFixed**. |
| *flexGridDashes* | 4 | The line style between cells is set to dashed lines. |
| *flexGridDots* | 5 | The line style between cells is set to dotted lines. |

#### Remarks

When the **GridLinesUnpopulated** property is set to 1 (flat lines), the color of the lines is determined by the **GridColorUnpopulated** property. Raised and inset gridlines are always black and white.

Changing the line style triggers a complete repaint of the control. For large grids, set `Redraw = False` before changing this property. 

Unlike the global **GridLines** property, **GridLinesUnpopulated** is an array property indexed by the band number, allowing you to apply different visual styles to the unpopulated gridlines for each level of nested data.

#### Example implementation

To ensure unpopulated areas remain clean and visually distinct from the active data area:
```
' Removes gridlines from unpopulated areas for a cleaner look
grid.GridLinesUnpopulated = flexGridNone

' Set a specific background for these empty areas to distinguish them
grid.BackColorUnpopulated = vbButtonFace
```
#### Technical tips

**Black vs. system color**: If setting the gridline color via **GridColor**, remember that setting it to 0 may result in the default system color. For true black lines in unpopulated areas (if using *flexGridFlat*), use the constant *vbBlack* or value 1.

---

### GridColor

Returns or sets the line color used between the cells of the grid.

```
PROPERTY GridColor () AS OLE_COLOR 
PROPERTY GridColor (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Remarks

The **GridColor** property can only be used when the **GridLines** property is set to 1 (*flexGridFlat*). Raised and inset gridlines are always black and white.

#### Key characteristics

**Visibility requirement**: For gridlines to appear, the **GridLines** property must be set to a value other than *flexGridNone* (0).

**Visual hiding**: A common technique to "hide" gridlines without changing the **GridLines** style is to set **GridColor** to the same color as the **BackColor** of the cells (e.g., setting it to white to make lines disappear on a white background).

**Hierarchical application**: In hierarchical views, **GridColor** applies to all data bands unless specific unpopulated areas are colored differently using **GridColorUnpopulated**.

#### Setting the color

You can assign colors using several methods:

**VB constants**: grid.GridColor = vbButtonShadow.
**RGB function**: grid.GridColor = BGR(200, 200, 200) (for a light gray effect).
**Hexadecimal**: grid.GridColor = &H808080. 

#### Technical tips

**Explicit black**: To ensure true black gridlines, use the constant *vbBlack* or the literal value 1. Setting the property to 0 may be interpreted by the system as a default "automatic" color.

**Performance**: When updating multiple visual properties (such as background and grid colors), it is best practice to set `Redraw = False` before making changes and **True** afterward to prevent screen flickering.

---

### GridColorFixed

Returns or sets the line color used between fixed cells of the grid.

```
PROPERTY GridColorFixed () AS OLE_COLOR 
PROPERTY GridColorFixed (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Remarks

The **GridColorFixed** property can only be used when the **GridLinesFixed** property is set to 1 (*flexGridFlat*).

Raised and inset gridlines are always black and white.

#### Key Characteristics

**Dependence on style**: **GridColorFixed** is only functional when the **GridLinesFixed** property is set to *flexGridFlat* (1).

**3D style override**: If **GridLinesFixed** is set to 3D styles such as *flexGridInset* (2) or *flexGridRaised* (3), the *GridColorFixed* property is ignored. In these cases, the grid automatically uses system-defined highlight and shadow colors (typically black and white) to draw the 3D effect.

**Visual consistency**: To create a modern, flat interface, developers often set **GridLinesFixed** to *flexGridFlat* and use **GridColorFixed** to match the gridlines to a specific theme color.
```
' Ensure the grid style allows custom colors (Flat style)
grid.GridLinesFixed = flexGridFlat 
' Set the fixed area gridline color
grid.GridColorFixed = BGR(128, 128, 128)
```
#### Technical tips

**Redraw performance**: When changing multiple gridline colors, it is best practice to set `Redraw = False` before making changes and True afterward to avoid screen flickering.

**Black vs. system default**: Setting this property to 0 may result in the default system color. For an explicit black, use the constant *vbBlack* or the literal value 1.

---

### GridColorUnpopulated

Returns or sets the line color used for the "unpopulated" region—space within a hierarchical band structure that is reserved but currently empty. 

```
PROPERTY GridColorUnpopulated () AS OLE_COLOR 
PROPERTY GridColorUnpopulated (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Remarks

Raised and inset gridlines are always black and white.

This property only affects the color of gridlines in empty structural areas—not populated cells, fixed headers, or indent regions.

#### Key characteristics

**Visual scope**: While **GridColor** handles active data cells and **GridColorFixed** handles headers, **GridColorUnpopulated** is used to maintain a consistent grid appearance in the empty portions of a hierarchical structure.

**Dependence on style**: Similar to other gridline color properties, this is only effective if the **GridLinesUnpopulated** property is set to a visible style, such as *flexGridFlat* (1). If the style is set to *flexGridNone* (0), the color setting will not be visible.

**Hierarchical purpose*: It is most commonly used in complex data views where a parent record has multiple child records, and you want to control the line color of the unused space within those nested levels.

#### Example implementation

To set a light blue gridline for the unpopulated areas of your grid:
```
' Ensure unpopulated areas show flat gridlines
grid.GridLinesUnpopulated = flexGridFlat

' Set the specific color for those lines
grid.GridColorUnpopulated = BGR(128, 192, 255)
```
---

### GridColorBand

Returns or sets the color of the gridlines specifically for a targeted hierarchical band.

```
PROPERTY GridColorBand (BYVAL BandNumber AS LONG) AS OLE_COLOR 
PROPERTY GridColorBand (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY GridColorBand () AS OLE_COLOR 
PROPERTY GridColorBand (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Remarks

Raised and inset gridlines are always black and white.

Because the `MSHFlexGrid` can display nested levels of data, this is an array-based property.

#### Key characteristics

**Visual distinction**: It allows developers to color-code the grid structure of different data levels, making complex parent-child relationships easier for the user to navigate visually.

**Style dependency**: For the color to be visible, the `GridLinesBand(BandNumber)` property must be set to *flexGridFlat* (1). If the band is using 3D styles like *flexGridRaised* (3) or *flexGridInset* (2), the custom color is ignored in favor of system-defined highlight/shadow colors.

**Scope**: This property specifically targets the lines between data cells within the specified band. It does not affect the band's header lines (controlled by **GridColorFixed**) or the lines in the indent area.

#### Example implementation

To set a dark gray gridline for the parent band and a lighter gray for the child band:
```
' Ensure both bands are using a flat line style
grid.GridLinesBand(0) = flexGridFlat
gris.GridLinesBand(1) = flexGridFlat

' Apply different colors to the lines of each band
grid.GridColorBand(0) = &H404040 ' Dark Gray
grid.GridColorBand(1) = &HC0C0C0 ' Light Gray
```
#### Technical tips

**Handling black**: Setting this property to 0 may cause the grid to use the default system color. To explicitly force black lines, use the constant *vbBlack* or the literal value 1.

**Performance**: When updating visual properties for multiple bands, wrap the code in `Redraw = False` and `Redraw = True` to prevent screen flickering.

---

### GridColorHeader

Returns or sets the color of the gridlines specifically for the header area of a designated hierarchical band.

```
PROPERTY GridColorHeader (BYVAL BandNumber AS LONG) AS OLE_COLOR 
PROPERTY GridColorHeader (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY GridColorHeader () AS OLE_COLOR 
PROPERTY GridColorHeader (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Remarks

Raised and inset gridlines are always black and white.

Because the `MSHFlexGrid` can display nested levels of data, this is an array-based property.

#### Key characteristics

**Style dependency**: This property is only effective if the `GridLinesHeader(BandNumber)` property for that specific band is set to *flexGridFlat* (1).

**3D style override**: If the header lines are set to 3D styles like *flexGridRaised* (3) or *flexGridInset* (2), the custom color is ignored. In these cases, the grid automatically uses system-defined highlight and shadow colors (typically black and white) to render the 3D effect.

**Granular control**: While **GridColorFixed** provides a global setting for all headers, **GridColorHeader** allows you to color-code different levels of data uniquely to enhance hierarchical navigation. 

#### Example implementation

To set a specific color for the header gridlines of the first child level (Band 1):
```
' Ensure the header lines for Band 1 are using the flat style
grid.GridLinesHeader(1) = flexGridFlat

' Set the gridline color for that band's header to a specific light gray
grid.GridColorHeader(1) = &HC0C0C0  ' vbSilver
```
#### Technical tips

**Handling system colors**: Setting the property to 0 may result in the default system text color. To force an explicit black color for lines, use the constant *vbBlack* or the literal value 1.

**Visual synchronization**: To maintain a professional look, developers often match **GridColorHeader** with the **GridColorBand** of the same band index so the header and data area lines look uniform.

**Flicker reduction**: When updating multiple band-specific color properties, wrap the code in `Redraw = False` and `Redraw = True` to ensure a smooth repaint on modern displays.

---

### GridColorIndent

Returns or sets the color within the indented area of a specific hierarchical band.

```
PROPERTY GridColorIndent (BYVAL BandNumber AS LONG) AS OLE_COLOR 
PROPERTY GridColorIndent (BYVAL BandNumber AS LONG, BYVAL clr AS OLE_COLOR)
PROPERTY GridColorIndent () AS OLE_COLOR 
PROPERTY GridColorIndent (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose background color is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *clr* | An OLE_COLOR value, such as a system color constant or an RGB value. |

#### Remarks

This property targets the lines in the "indent" space—the empty area used to offset a child band from its parent.

Raised and inset gridlines are always black and white.

Because the `MSHFlexGrid` can display nested levels of data, this is an array-based property.

#### Key characteristics

**Style dependency**: This property is only visible if the `GridLinesIndent(BandNumber)` property for that band is set to *flexGridFlat* (1). If the style is set to *flexGridNone* (0), the color setting has no effect.

**Hierarchical navigation**: It is used to maintain visual structure across the gaps between parent and child records.

**Global override**: While this property sets the color for the indent lines of a specific band, the overall default for the grid is typically inherited from the global **GridColor** unless explicitly defined here.

#### Example implementation

To set a specific light gray color for the indent lines of the first child level:
```
' Ensure the indent area for Band 1 uses flat gridlines
grid.GridLinesIndent(1) = flexGridFlat

' Set the color for those specific lines
grid.GridColorIndent(1) = BGR(200, 200, 200)
```

#### Technical tips

**Seamless design**: To make the indent area look like a single solid block, set **GridColorIndent** to the same color as **BackColorIndent**.

**Black vs. default**: Setting the color to 0 may revert to the system default. For true black lines, use the constant *vbBlack* or the value 1.

**Flicker reduction**: When updating multiple band-specific color properties, wrap the code in `Redraw = False` and `Redraw = True` to ensure a smooth repaint on modern displays.

---

### RowHeight

Returns or sets the height of the specified row, in twips.

```
PROPERTY RowHeight (BYVAL Index AS LONG) AS LONG
PROPERTY RowHeight (BYVAL Index AS LONG, BYVAL rHeight AS LONG)
```
| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the row to size, or -1 to set all rows at once. |
| *rHeight* | The height of the row, measured in twips (1/1440th of an inch). |

#### Remarks

Setting the height to 0 effectively hides the row from the user's view.

Setting the height to -1 for a specific row index resets that row to the default height based on the control's current font.

If the **AllowUserResizing** property is enabled, users can manually change the **RowHeight** at runtime by dragging row headers.

The `MSHFlexGrid` does not automatically expand **RowHeight** to fit wrapped text. If you enable **WordWrap**, you must manually calculate and set a larger **RowHeight** to see the multiple lines of text.

In hierarchical displays, you can use the **RowHeightMin** property to set a minimum height across all rows in a specific band. 

When resizing a large number of rows in a loop, always set `Redraw = False` before the loop and `Redraw = True` after to prevent visual stuttering.

#### Example Implementation
```
' Set the header row (index 0) to be taller
grid.RowHeight(0) = 450

' Set all data rows to a standard height
grid.RowHeight(-1) = 300

' Hide the second row (index 1)
grid.RowHeight(1) = 0
```
---

### RowHeightMin

Returns or sets the height of the specified row, in twips.

```
PROPERTY RowHeightMin () AS LONG
PROPERTY RowHeightMin (BYVAL rHeightMin AS LONG)
```
| Parameter  | Description |
| ---------- | ----------- |
| *rHeightMin* | The height of the row, measured in twips (1/1440th of an inch). |

#### Remarks

When set to a non-zero value, it prevents any individual row from becoming shorter than this limit, even if the content or user resizing would otherwise reduce it further. 

Unlike the **RowHeight** property, which can target individual rows, **RowHeightMin** applies a consistent minimum threshold across the entire grid.

It is particularly useful when using small fonts or when the **AllowUserResizing** property is enabled, ensuring that users do not accidentally hide row content by resizing it too small.

If a conflict exists between an individual row's **RowHeight** and the global **RowHeightMin**, the **RowHeightMin** value takes precedence to ensure the minimum height is maintained. 

#### Example implementation

To ensure all rows in a grid are at least 300 twips high, which is a standard minimum for readability:
```
' Prevents any row from being shorter than 300 twips
grid.RowHeightMin = 300
```

#### Technical tips

**Bug mitigation**: A known legacy bug in the `MSHFlexGrid` sometimes causes newly added rows (via **AddItem** or data binding) to default to a height of 0 if a previous row was removed. Setting **RowHeightMin** to a standard height (e.g., 240 or 300 twips) is a common workaround to ensure new data remains visible automatically.

---

### ColWidth

Returns or sets the width of the column in the specified band, in twips.

```
PROPERTY ColWidth (BYVAL Index AS LONG) AS LONG
PROPERTY ColWidth (BYVAL Index AS LONG, BYVAL nWidth AS LONG)
```
```
FUNCTION ColWidth2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0) AS LONG
FUNCTION ColWidth2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL nWidth AS LONG) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | A Long value that specifies which column's width to change. To set the same width for all columns at once, use an index of -1. |
| *nWidth* | A numeric expression that specifies the width of the specified column, in twips. Setting the width to 0 hides the column from the user. |
| *BandNumber* | Optional. A Long value that specifies the band that contains the column. |

#### Remaks

Setting the width to -1 for a specific index resets that column to the default width, which is determined by the control's current font size. 

**Manual auto-fit**: The `MSHFlexGrid` does not have a native "AutoFit" property. Developers implement this by iterating through rows, measuring text using the **TextWidth** method of a form or picture box with matching font settings, and then updating **ColWidth**.

If the **AllowUserResizing** property is enabled, users can manually override these values by dragging the column borders in the fixed header area.

When bound to a database, the grid usually initializes with default widths. You typically need to call **ColWidth** after the data is loaded to ensure a proper layout. 

If resizing multiple columns in a loop, set `Redraw = False` before starting and `Redraw = True` afterward to prevent screen flickering. 

#### Example Implementation
```
' Set a specific width for the first column (Index 0)
grid.ColWidth(0) = 2000

' Hide the third column (Index 2)
grid.ColWidth(2) = 0

' Set all columns to a standard uniform width
grid.ColWidth(-1) = 1200
```
---

### RowIsVisible

Returns a Boolean value indicating if any part of the row is visible to the user. 

```
PROPERTY RowIsVisible (BYVAL Index AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the row being checked.  |

The property returns **True** even if the row is only partially visible at the bottom of the grid.

If a row has its height set to 0 but is within the scrollable area currently on screen, the property typically returns **True**.

The value changes as the user scrolls or as the **TopRow** property is adjusted programmatically. 

It is frequently used in search routines. If a searched row is not visible, developers use it to trigger a scroll:

```
' Example: If Row 50 is not visible, scroll to it
If Not grid.RowIsVisible(50) Then
    grid.TopRow = 50
End If
```
**Counting visible rows**: Developers often calculate the number of rows currently shown by looping from the **TopRow** until **RowIsVisible** returns **False**:

```
Dim i As Long, count As Long
For i = grid.TopRow To grid.Rows - 1
   If grid.RowIsVisible(i) Then
      count = count + 1
   Else
      Exit For
   End If
Next
```
---

### ColIsVisible

Returns a Boolean value indicating if any part of the column is visible to the user. 

```
PROPERTY ColIsVisible (BYVAL Index AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the column being checked.  |

#### Remarks

The property returns **True** even if the column is only partially visible at the left or right edge of the scrollable area.

The value of this property changes automatically as the user interacts with the horizontal scrollbar or when the LeftCol property is changed programmatically.

Note that if a column's width is set to 0 `(ColWidth(index) = 0)`, the property may still return **True** if that "hidden" index is within the current scroll range, though it occupies no visual space.

#### Example implementation

It is commonly used to ensure a specific column is displayed to the user after a search or automated data entry:
```
' Check if the 10th column (Index 9) is visible
If Not grid.ColIsVisible(9) Then
    ' If not visible, scroll the grid horizontally to show it
    grid.LeftCol = 9
End If
```
#### Technical tips

Fixed columns (defined by **FixedCols**) usually always return True for **ColIsVisible** unless the entire grid is hidden or the columns are shrunk to 0 width, as they do not scroll out of the viewport.

This property is highly useful when calculating how many columns can fit on a user's screen at once, especially on modern high-resolution displays where horizontal real estate varies greatly.

---

### RowPos

Returns the distance, in twips, between the upper-left corner of the grid and the upper-left corner of a specified row.

```
PROPERTY RowPos (BYVAL Index AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the row. |

#### Remarks

The value is relative to the upper-left corner of the grid control itself.

If a row is currently scrolled out of view or has a **RowHeight** of 0, **RowPos** still returns its calculated logical position within the grid structure.

While **RowPos** returns a coordinate, the related **RowPosition** property is used to move a row to a new index in the grid. 

Developers often use **RowPos** (combined with **ColPos**) to accurately position another control, such as a **TextBox** or **ComboBox**, directly over a specific cell to simulate in-cell editing.

In advanced UI scenarios, it helps determine exactly which row is located at a specific mouse Y-coordinate during **MouseDown** or **MouseMove** events. 

**RowPos** for fixed header rows (e.g., RowPos(0)) will usually return 0 (or the thickness of the grid's border) because they are locked at the top of the viewport.

#### Technical implementation example

To find the Y-coordinate of the 5th row (index 4):
```
' Get the top coordinate of the 5th row in twips
Dim rowTop As Long
rowTop = grid.RowPos(4)
```
---

### ColPos

Returns the distance, intwips, between the upper-left corner of the control and the upper-left corner of a specified column.

```
PROPERTY ColPos (BYVAL Index AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the column. |

#### Remarks

The value returned is relative to the upper-left corner of the grid control.

**ColPos** returns the position based on the current scroll state. If a column is scrolled off to the left, its **ColPos** will be a negative value.

While **ColPos** returns a coordinate, the related **ColPosition** property is used to move a column to a different index location in the grid.

Developers use **ColPos** and **RowPos** to calculate the exact coordinates needed to place a standard **TextBox** or **ComboBox** over a cell, creating the illusion of a native editable grid.

It is used to determine where to display a popup or tooltip relative to a specific data column when a user hovers their mouse.

It helps position external icons, progress bars, or validation markers precisely over a column.

#### Technical tips

For fixed columns (e.g., ColPos(0)), the value will generally remain static as they do not move during horizontal scrolling.

If a column's width is set to 0, **ColPos** will return the coordinate where that column would have started, which is identical to the **ColPos** of the next visible column.

---

### RowPosition

Sets the position of an `MSHFlexGrid` row, allowing you to move rows to specific positions

```
PROPERTY RowPosition (BYVAL Index AS LONG, BYVAL newPos AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The current zero-based index of the row you wish to move. |
| *newPos* | The target zero-based index where the row should be placed. |

#### Remarks

Unlike the **RowPos** property (which returns a coordinate), **RowPosition** is a write-only property used to reorder rows.

When a row is moved, the other rows automatically shift to accommodate the change. For example, moving Row 5 to Position 1 will push the original Row 1 down to Position 2.

Moving a row via **RowPosition** preserves all cell contents, individual cell formatting (**CellBackColor**, etc.), and row-specific metadata.

In a hierarchical display, **RowPosition** typically operates within the context of the current band or the top-level structure.

#### Example implementation

To move the last row of a 10-row grid to the very top (immediately following the fixed headers):
```
' Moves the row currently at index 9 to index 1
grid.RowPosition(9) = 1
```
To swap the positions of two rows (e.g., Row 2 and Row 3):
```
' Moving Row 2 to Position 3 effectively swaps them
grid.RowPosition(2) = 3
```

#### Technical tips

You cannot move a row into the fixed area using this property, nor can you move a fixed row into the scrollable data area. Attempting to do so will result in an "Invalid property value" error.

This property is intended for use in unbound mode. If the grid is bound to a data source (like an ADO Recordset), you should reorder the underlying data source (e.g., via an ORDER BY clause) rather than using **RowPosition**, as the grid will reset its layout upon the next data refresh.

If reordering many rows at once, set `Redraw = False` before the operations and `Redraw = True` afterward to avoid visual flickering. 

---

### ColPosition

Sets the position of an MSHFlexGrid column, allowing you to move columns to specific positions.

```
PROPERTY ColPosition (BYVAL Index AS LONG, BYVAL newPos AS LONG)
FUNCTION ColPosition2 (BYVAL Index AS LONG, BYVAL BandNumber AS LONG = 0, BYVAL newPos AS LONG) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The current zero-based index of the column you want to move. |
| *newPos* | The target zero-based index where the column should be placed. |
| *BandNumber* | Optional. A Long value that specifies the band that contains the column. |

#### Remarks

Unlike **ColPos** (which returns a pixel/twip coordinate), **ColPosition** is used to move a column from its current index to a new index location.

When a column is moved, all other columns between the old and new positions automatically shift to fill the gap.

This property moves the entire column including its data, **ColWidth**, and individual cell formatting.

This property is primarily intended for grids in unbound mode. If the grid is bound to a data source, the order is typically governed by the fields in the underlying recordset; manually moving columns may be overwritten upon a data refresh.

#### Example implementation

To move the third column (Index 2) to the first position (Index 0):
```
' Moves column 2 to the far left
grid.ColPosition(2) = 0
```
To swap the first and second columns:
```
' Moving column 0 to position 1 effectively swaps the two
grid.ColPosition(0) = 1
```

#### Technical tips

You generally cannot move a scrollable column into the fixed area (defined by **FixedCols**) or move a fixed column into the scrollable area using this property. Attempting to do so will trigger an "Invalid property value" error.

This property is often used to implement "Drag and Drop" column reordering. By capturing the **MouseDown** and **MouseUp** events on column headers, you can use **ColPosition** to update the grid layout based on user preference.

If moving multiple columns at once, set `Redraw = False` before the operations and **True** afterward to prevent screen flickering.

---

### MergeRow

Returns or sets a value that determines which rows can have their contents merged. This property must be **True** to use the **MergeCells** property.

```
PROPERTY MergeRow (BYVAL Index AS LONG) AS BOOLEAN
FUNCTION MergeRow (BYVAL Index AS LONG, BYVAL merge AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the row you want to configure. |
| *merge* | True enables merging for that row; False (default) disables it. |

#### Remarks

For **MergeRow** to take effect, the following conditions must be met:

* The **MergeCells** property must be set to a value other than *flexMergeNever* (0).
* Adjacent cells in the specified row must contain the exact same text.
* If you are trying to merge a block of cells both horizontally and vertically, the corresponding **MergeCol** property for those columns must also be considered. 

#### Example implementation

To merge the cells in the first row of a grid if they contain duplicate values:
```
' 1. Enable merging globally (Restricted to cells with identical text)
grid.MergeCells = flexMergeRestrictBoth

' 2. Specify that Row 0 is eligible for merging
grie.MergeRow(0) = True

' 3. Assign duplicate text to see the effect
grid.TextMatrix(0, 0) = "Region"
grid.TextMatrix(0, 1) = "Region" ' These two cells will now appear as one
```

#### Technical tips

When cells are merged, the text is typically aligned based on the **CellAlignment** property of the first cell in the merged group.

In hierarchical displays, **MergeRow** is often used to "clean up" repeating parent data so it spans across child columns, making the data structure easier to read.

Extensive merging in very large grids (~100,000+ cells) can slow down the control's repaint speed. Always use `Redraw = False` when populating data that will be merged.

---

### MergeCol

Returns or sets a value that determines which columns can have their contents merged. This property must be **True** to use the **MergeCells** property.

```
PROPERTY MergeCol (BYVAL Index AS LONG) AS BOOLEAN
FUNCTION MergeCol (BYVAL Index AS LONG, BYVAL merge AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the column you want to configure. |
| *merge* | True enables merging for that column; False (default) disables it. |

#### Remarks

Setting **MergeCol** to **True** will only result in a visible merge if the following global conditions are met:

* The **MergeCells** property must be set to a value other than *flexMergeNever* (0).
* Vertical cells must contain the exact same string.
* Merged cells typically inherit the alignment of the top-most cell in the merged group. 

#### Example implementation

This is commonly used for "Category" columns where the same label repeats for many rows:
```
' 1. Enable merging globally
grid.MergeCells = flexMergeRestrictColumns

' 2. Enable merging for the first column (Column 0)
grid.MergeCol(0) = True

' 3. Populate data (Cells with "North" will merge vertically)
grid.TextMatrix(1, 0) = "North"
grid.TextMatrix(2, 0) = "North" 
```

#### Technical tips

In the `MSHFlexGrid`, **MergeCol** is frequently used to eliminate the repetitive display of parent-level data when expanding child bands, creating a cleaner "tree" look.

To merge cells horizontally across a row, use the corresponding **MergeRow** property.

For very large datasets, set `Redraw = False` before populating the grid and enabling merging. Calculating merged boundaries can be resource-intensive for the legacy rendering engine if done cell-by-cell.

Cells will not merge if they contain different formatting (e.g., different **CellBackColor**), even if the text content is identical. 

---

### MergeCells

Returns or sets a value that determines whether cells with the same contents should be grouped in a single cell spanning multiple rows or columns.

```
PROPERTY MergeCells () AS MergeCellsSettings
FUNCTION MergeCells (BYVAL merge AS MergeCellsSettings)
```
| Parameter  | Description |
| ---------- | ----------- |
| *merge* | An integer or constant that specifies the grouping (merging) of cells. |

#### MergeCellsSettings constants

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexMergeNever** | 0 | Never. The cells containing identical content are not grouped. This is the default. |
| **flexMergeFree** | 1 | Free. Cells with identical content always merge. |
| **flexMergeRestrictRows** | 2 | Restrict rows. Only adjacent cells (to the left of the current cell) within the row containing identical content merge. |
| **flexMergeRestrictColumns** | 3 | Restrict columns. Only adjacent cells (to the top of the current cell) within the column containing identical content merge. |
| **flexMergeRestrictAll** | 4 | Restrict both. Only adjacent cells within the row (to the left) or column (to the top) containing identical content merge. |

#### Remarks

To enable cell merging, you must follow this specific sequence: 

* Set the **MergeCells** property to a value other than 0 (never).
* Set the `MergeRow(index)` or `MergeCol(index)` array properties to **True** for the specific rows or columns allowed to merge.
* Ensure that adjacent cells contain the exact same text. The grid merges automatically based on content and updates immediately when cell text changes. 

#### Example implementation

To merge all cells in the first column that contain identical text:
```
' Enable global column-based merging
grid.MergeCells = flexMergeRestrictColumns 

' Allow merging specifically for the first column
grid.MergeCol(0) = True 

' Populate identical data to trigger the merge
grid.TextMatrix(1, 0) = "Region A"
grid.TextMatrix(2, 0) = "Region A"
```

#### Technical considerations

When **MergeCells** is active, the standard selection highlight is automatically turned off to improve repainting performance and avoid unexpected selection behavior in merged ranges.

Merged cells typically inherit the alignment properties of the top-left cell in the group. 

---

### Clear

Clears the contents of the `MSHFlexGrid`. This includes all text, pictures, and cell formatting. This method does not affect the number of rows and columns within the `MSHFlexGrid`.

```
FUNCTION Clear () AS HRESULT
```

#### Remarks

This method affects every cell in the grid, including both fixed (header) and non-fixed (data) cells.

If you need to clear the grid but keep the headers, **Clear** is often too broad because it empties the header labels. Instead, developers use one of the following alternatives:

1. Resetting just the data area (keeping headers):

To clear data while leaving headers intact, it is more efficient to adjust the **Rows** property:
```
' Reset the grid to only show the header row (assuming 1 fixed row)
grid.Rows = MSHFlexGrid1.FixedRows
```
2. Clearing only non-fixed cells via **Clip**:

If you want to keep the structure but only wipe the data cells:
```
' Select all non-fixed cells
grid.Row = grid.FixedRows
grid.Col = grid.FixedCols
grid.RowSel = grid.Rows - 1
grid.ColSel = grid.Cols - 1
' Wipe the selection text
grid.Clip = "" 
```

#### Technical tips

If you are clearing a very large grid (e.g., 50,000+ cells), set `Redraw = False` before calling **Clear** and `Redraw = True` immediately after to avoid screen flickering.

This method is primarily used in unbound mode. If the grid is bound to a data source, calling **Clear** may result in an error or the data will simply reappear once the data source refreshes.

---

### ClearStructure

Reset the control's internal column mapping and band information when it is bound to a data source.

```
FUNCTION ClearStructure () AS HRESULT
```

#### Remarks

Unlike the standard **Clear** method, which only empties cell content and formatting, **ClearStructure** removes the grid's underlying organizational metadata. 

This method is primarily used in data-bound scenarios involving ADO or Shaped Recordsets. 

When you change the **RecordSource** of a bound data control to a new query with a different number of columns or a different hierarchy (bands), the `MSHFlexGrid` often retains the column arrangement of the previous recordset.

Calling **ClearStructure** before assigning a new recordset forces the grid to "forget" its old layout and rebuild its columns and bands to match the new data structure automatically. 

It is typically called immediately before setting a new **DataSource** or **Recordset**.

#### Technical Tips

If you are binding to an empty recordset (EOF), using **ClearStructure** followed by a set to an empty recordset can sometimes cause unexpected behavior in legacy systems. It is best practice to verify the recordset has data before rebinding if possible.

Because this method resets everything, any custom column headers or **ColWidth** settings you applied manually will be lost. You must re-apply your custom formatting after the grid has bound to the new data.

Like other visual updates, use the `Redraw = False` property before calling **ClearStructure** and rebinding to prevent the user from seeing the grid "flicker" as it rebuilds. 

---

### Refresh

It ensures that any pending visual changes—such as property updates, cell coloring, or text changes—are rendered on the screen without waiting for the operating system's standard paint cycle.

```
FUNCTION Refresh () AS HRESULT
```

#### Remarks

#### Key scenarios for use

**Ensuring updates during long loops**: If you are updating many cells in a loop, the grid may appear "frozen." Calling **Refresh** inside the loop forces it to show progress (though this can significantly slow down the execution).

**Repainting after overlays**: If another window or a floating control (like a **TextBox** used for editing) was recently moved from the top of the grid, **Refresh** clears any residual "ghost" images.

**Data source updates**: While the grid usually updates automatically when its bound **Recordset** changes, a manual **Refresh** can be used to ensure the UI is in sync with the underlying data provider after a complex transaction.

#### Refresh vs. Redraw

Developers frequently confuse **Refresh** with the **Redraw** property.

**Redraw**: A property used to turn the grid's drawing engine on or off. You set `Redraw = False` before a bulk operation to speed it up, and `Redraw = True` to resume drawing.

**Refresh**: A method that triggers a single, immediate redraw event.

#### Example implementation
```
' Stop the grid from flickering during a bulk update
grid.Redraw = False

' ... Perform hundreds of cell updates ...

' Re-enable drawing
grid.Redraw = True

' Force the control to update its visual appearance right now
grid.Refresh
```

#### Technical tips

Do not call **Refresh** excessively inside a large loop. On modern high-resolution displays, forcing a full repaint too frequently can cause the application to lag.

`MSHFlexGrid` controls running on modern Windows versions might occasionally experience "stuck" pixels or artifacts. Calling **Refresh** during resizing is a common workaround to ensure the grid renders correctly.

---

### Redraw

Returns or sets a boolean toggle that determines whether the `MSHFlexGrid` should be automatically redrawn after each change.

```
PROPERTTY Redraw () AS BOOLEAN
PROPERTY Redraw (BYVAL bRedraw AS BOOLEAN)
```
| Parameter  | Description |
| ---------- | ----------- |
| *bRedraw* | **True** (Default): The grid repaints immediately every time a cell value, color, or property changes.<br>**False**: The grid stores changes in memory but does not update the screen until the property is set back to **True**. |

#### Remarks

When **Redraw** is set to **True** during a large loop, the grid attempts to repaint for every single cell update. On modern high-resolution displays, this causes significant visual flickering and drastically slows down execution. By setting `Redraw = False`, you can increase data processing speed by 10x to 100x.

#### Example implementation

This is the standard best-practice pattern for updating an MSHFlexGrid:
```
' 1. Turn off repainting to boost speed and prevent flicker
grid.Redraw = False

' 2. Perform bulk data operations (e.g., loading 5,000 rows)
For i = 1 To 5000
   grid.AddItem "Row " & STR(i) & CHR(9) & "Data " & STR(i)
Next i

' 3. Turn repainting back on to show all changes at once
grid.Redraw = True

' 4. (Optional) Force an immediate refresh
grid.Refresh
```

#### Technical tips

Always place `grid.Redraw = True` in your error-handling routine. If the code crashes while **Redraw** is **False**, the grid will appear frozen or white, and it will not respond to user input until the application is restarted or the property is toggled.

The grid does not automatically reset this property. It remains **False** until your code explicitly changes it back to **True**.

Failing to set `Redraw = True` before a form is minimized or hidden can cause the grid to lose its graphical buffer. Microsoft's legacy documentation recommends keeping **Redraw** active unless a specific batch process is running. 

---

### Text

Returns or sets the text content of a cell or range of cells.

```
PROPERTY Text () AS DWSTRING
PROPERTY Text (BYREF wszText AS WSTRING) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszText* | The text to set. |

#### Remarks

When retrieving, the **Text** property always retrieves the contents of the current cell as defined by the **Row** and **Col** properties.

When setting, the **Text** property sets the contents of the current cell or selection depending on the setting of the **FillStyle** property.

Unlike **TextMatrix**, which uses row/column indices directly, the **Text** property always refers to whichever cell is "active" or has the current focus highlight.

If the **FillStyle** property is set to *flexFillRepeat*, assigning a value to the **Text** property will fill every cell within the currently selected range. By default (*flexFillSingle*), it only affects the active cell.

If the **WordWrap** property is True, long text strings assigned to this property will automatically wrap to multiple lines within the cell. 

#### Example implementation

To change the text of the cell the user has currently clicked:
```
' Sets the content of the currently active cell
grid.Text = "Revised Entry"
```

To read the text from the third row and second column:
```
' Must move focus to the specific cell first to use .Text
grid.Row = 2
grid.Col = 1
Dim cellValue As DWString
cellValue = grid.Text
```
#### Technical tips

For background updates where you don't want the user's cursor to move, the **TextMatrix** property is the superior choice because it doesn't change the active **Row** and **Col** indices.

The Text property always returns a string. If the cell contains numbers for a calculation, you must convert it using functions like **Val**.

By default, the `MSHFlexGrid` is read-only. Users cannot type directly into cells. To allow "editing," developers typically overlay a standard **TextBox** on top of the grid and then transfer the textbox's content back to the grid's **Text** property. 

---

### TextArray

Returns or sets the text contents of an arbitrary cell.

```
PROPERTY TextArray (BYVAL Index AS LONG) AS DWSTRING
PROPERTY TextArray (BYVAL Index AS LONG, BYREF wszText AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | An integer value that specifies which cell to read or write. |
| *wszText* | The text to set. |

This property allows you to set or retrieve the contents of a cell without changing the **Row** and **Col** properties.

The *Index* argument determines which cell to use. It is calculated by multiplying the preferred row by the **Cols** property and adding the preferred column.

#### Remarks

While most developers use `TextMatrix(Row, Col)` for two-dimensional access, **TextArray** maps the entire grid (across all bands) into a single linear sequence.

**Formula**: To find the **TextArray** index for a specific cell, use:
```
Index = (Row * Cols) + Col.
```
**Constraint**: You cannot change the active cell's position using this property; it only modifies the content.

#### Comparison with other properties

| Property  | Input type | Best use case |
| --------  | ---------- | ------------- |
| **Text**  | None | Accessing or modifying the currently selected/active cell. |
| **TextMatrix** | (Row, Col) | Standard programmatic access to any cell without moving focus. |
| **TextArray** | (Index) | Backward compatibility or iterating through a grid as a single flat list. |

#### Example usage

To place text in a grid with 5 columns at the second row and second column (which would be index 6):
```
' Using TextMatrix (Preferred)
grid.TextMatrix(1, 1) = "Data"

' Using TextArray (One-dimensional index)
' Index = (1 * 5) + 1 = 6
grid.TextArray(6) = "Data" 
```

#### Behavior with fixed rows and columns

Although **TextArray** accesses cells using a one‑dimensional index, fixed rows and fixed columns are included in the linear sequence exactly the same as normal cells. In other words:

* TextArray does not skip fixed rows
* TextArray does not skip fixed columns
* Every cell in the grid participates in the linear index

The index always starts at the top‑left cell (0,0) — even if that cell is part of a fixed header — and continues row by row across the entire grid.

This means:

* Cell (0,0) (usually a fixed header cell) is TextArray(0)
* Cell (0,1) is TextArray(1)
* Cell (1,0) is TextArray(Cols)
* And so on

#### Example

In a grid with:
```
FixedRows = 1
FixedCols = 1
Cols = 5
```
The mapping is:
```
Cell (0,0) → Index = (0 * 5) + 0 = 0
Cell (0,3) → Index = (0 * 5) + 3 = 3
Cell (1,0) → Index = (1 * 5) + 0 = 5
```

While **TextMatrix** and **Text** treat fixed cells specially (e.g., they don’t move the active cell), **TextArray** treats fixed cells exactly like any other cell in the linear sequence.

This is useful when:

* iterating through the entire grid as a flat list
* exporting data
* performing bulk operations without changing the active cell
* implementing custom copy/paste logic

But it also means that developers must account for fixed rows and columns when calculating indices manually.

---

### TextMatrix

Returns or sets the text contents of an arbitrary cell.

```
FUNCTION TextMatrix (BYVAL nRow AS LONG, BYVAL nCol AS LONG) AS DWSTRING
FUNCTION TextMatrix (BYVAL nRow AS LONG, BYVAL nCol AS LONG, BYREF wszText AS WSTRING) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *nRow* | The zero-based index of the row. |
| *nCol* | The zero-based index of the column. |
| *wszText* | The text to set. |

#### Syntax
```
' To set a cell value:
grid.TextMatrix(row, col, string)

' To retrieve a cell value:
variable = grid.TextMatrix(row, col)
```

#### Remarks

Unlike the **Text** property, which only interacts with the active cell (defined by the **Row** and **Col** properties), **TextMatrix** allows you to target any cell directly using coordinates. 

It is significantly faster than using **Row**, **Col**, and then **Text** because it avoids the overhead of moving the user's focus and redrawing the selection highlight.

You can update data in the background without affecting what the user has currently highlighted.

It works for all cells, including fixed (header) rows and columns, making it the standard tool for setting column headers at runtime. 

#### Example implementation

To populate a grid with data and set a custom header: 
```
' Setting a header label in the first fixed row
grid.TextMatrix(0, 1) = "Customer Name"

' Setting data in a specific data row
grid.TextMatrix(1, 1) = "John Smith"

' Retrieving data for a calculation
Dim price As Double
price = Val(grid.TextMatrix(5, 2))
```

#### Technical tips

You must ensure the **Rows** and **Cols** properties are set large enough to accommodate the indices you pass to **TextMatrix**, or a runtime error will occur.

When using **TextMatrix** in a large loop (e.g., loading 10,000+ items), always wrap the code in `Redraw = False` and `Redraw = True` to prevent the grid from attempting to repaint after every single cell update.

**TextMatrix** always returns and accepts a string. To perform math, you must convert the result using functions like **Val**.

---

### FormatString

Returns or sets the column widths, alignments, fixed row text, and fixed column text of the grid.

```
PROPERTY FormatString () AS DWSTRING
PROPERTY FormatString (BYREF wszStr AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszStr* | The string to set. |

#### Syntax and special characters

The string is parsed using specific symbols to determine the grid structure: 

Pipe (|): Separates column information.

Semicolon (;): Separates row information (used to set row headers).

Greater Than (>): Right-aligns the text in that column.

Less Than (<): Left-aligns the text in that column.

Caret (^): Centers the text in that column. 

#### Remarks

The **FormatString** property contains segments separated by pipe characters (|). The text between pipes defines a column and may also contain special alignment characters. These characters align the entire column to the left (<), center (^), or right (>). In addition, the text is assigned to row zero by default, and the text width defines the width of each column.

The **FormatString** property may contain a semicolon (;). This causes the remainder of the string to be interpreted as row heading and row width information. In addition, the text is assigned to column zero by default, and the longest string defines the width of column zero.

The `MSHFlexGrid` creates additional rows and columns to accommodate all fields defined by the **FormatString**. Additional rows and columns are not deleted if only a few fields are specified. To remove additional rows and columns, set the **Rows** and **Cols** properties.

#### Basic example

To set up a grid with three columns (ID, Name, and Date) with specific alignments:
```
' < = Left Align, ^ = Center, > = Right Align
grid.FormatString = "<ID |^Name |>Date "
```
Result: The first fixed row will contain those three labels. The grid automatically adjusts the number of columns (**Cols**) to match the pipe count.

#### Advanced Example (Rows and Columns)

You can define both column headers and row headers simultaneously:
```
' Sets 3 column headers and 2 row headers
grid.FormatString = "Product | Price | Stock ; Item 1 | Item 2"
```

#### Remarks

The `MSHFlexGrid` automatically sizes columns based on the length of the strings provided in the **FormatString**. If you add extra spaces (e.g., " Name "), the column will be wider.

The labels defined in this property are automatically placed in the Fixed areas (Row 0 and Column 0).

Assigning a value to FormatString resets any previous column count and header text, making it a quick way to "re-skin" a grid for a different data view. 

#### Technical tips

While **FormatString** sets the initial alignment, you can still override individual cell or column alignment later using the **ColAlignment** or **CellAlignment** properties.

On high-resolution displays, the automatic width calculation based on string length is still twips-based. If your headers look cramped, you may need to manually adjust **ColWidth** after setting the **FormatString**.

Setting the **FormatString** does not necessarily clear the data in the scrollable cells (if the column count stays compatible), but it is best practice to set the structure before populating data. Microsoft's legacy documentation remains the reference for this string-parsing logic. 

---

### DataField

Returns the name of the field bound to the specified column in the specified band. 

```
FUNCTION DataField (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The zero‑based index of the band that contains the column. |
| *BandColIdx* | The zero‑based index of the column within that band. |

#### Remarks

When the `MSHFlexGrid` is bound to a data source (such as an ADODC or a shaped Recordset), each column automatically receives a **DataField** value corresponding to the underlying field name in the Recordset.

In hierarchical datasets created with `SQL SHAPE`, each band corresponds to a different Recordset level. In this case, the “data field” for a band column may come from:

* a field in the parent Recordset
* a field in a child Recordset
* an alias defined in the SHAPE command (e.g., AS Orders)

This makes **DataField** useful for inspecting how the grid mapped fields to bands.

Although you can retrieve the bound field name, the `MSHFlexGrid` is fundamentally a read‑only display control. To edit data, developers typically overlay a TextBox, ComboBox, or other input control on top of the active cell and manually write changes back to the underlying Recordset.

By default, the grid uses the **DataField** names as column headers. If you want a more user-friendly name (e.g., "Customer ID" instead of "cust_id"), it is best practice to use SQL Aliases in your connection string (e.g., `SELECT cust_id AS [Customer ID]...`) rather than changing captions at runtime, as re-binding the grid will reset headers to the raw field names. 

Changing captions at runtime is possible, but any re‑binding of the grid will restore the original field names unless they were aliased in the query.

---

### DataSource

Returns or sets the data source.

```
PROPERTY DataSource () AS Afx_IDataSource PTR
PROPERTY DataSource (BYVAL Data_Source AS Afx_IDataSource PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Data_Source* | The data source, such an ADODC (Microsoft ADO Data Control) or a live ADODB.Recordset. |

#### Remarks

The **DataSource** property is used at runtime to bind the grid to a data source object, such as an **ADODC** (Microsoft ADO Data Control) or a live **ADODB Recordset**. 

A key distinction of the `MSHFlexGrid` (versus the standard `MSFlexGrid`) is its full compatibility with ADO and its ability to handle hierarchical recordsets. 

When bound to a recordset created with the `MSDataShape` provider (using the `SHAPE` command), the grid automatically creates "bands" to represent nested parent-child relationships.

If the data source contains multiple members or tables, the **DataMember** property is often used in conjunction with **DataSource** to specify which particular set of data to display. 

Even when bound via **DataSource**, the `MSHFlexGrid` remains a display-only control. It does not natively support direct in-cell editing; updates must be handled by overlaying controls or manually updating the underlying recordset.

Upon setting a new **DataSource**, the grid typically rebuilds its structure (columns and bands) to match the new data source.

A long-standing legacy behavior remains where the grid may only display up to 2,048 rows when bound, even if the data source contains more records. For larger datasets, developers often use the **Clip** property or manual population methods.

To ensure the grid reflects changes made to the data source at runtime, it may be necessary to call the **Refresh** method or re-set the **DataSource** property.

---

### DataMember

Returns or sets the data member.

```
PROPERTY DataMember () AS DWSTRING
PROPERTY DataMember (BYREF wszDataMember AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszDataMember* | Specefies the table or child recordset to display. |

#### Remarks

`MSHFlexGrid`'s **DataMember** property specifies which table to display when the **DataSource** is a complex object like a hierarchical Recordset, allowing the grid to bind to a specific part of that data, like "Customers" from a Recordset containing "Customers" and "Orders" tables. It tells the grid which specific table name within the larger data source to use for populating rows and columns, essential for displaying related data sets. 

A known bug exists where rebinding to a different **DataMember** may cause an error if the **DataSource** isn't reset first. To resolve this, set the **DataSource** = NULL before rebinding to a new data member or environment.

Simply changing the **DataMember** or calling **Refresh** often does not update the data if the underlying recordset has changed. Developers frequently need to manually reassign the **DataSource** to force a UI update. 

To avoid errors and ensure a clean refresh, follow this binding sequence:

**Set DataMember first**: It is often recommended to set the **DataMember** string before assigning the **DataSource**. This ensures that when the binding is initialized, the grid already knows which specific data list to load.

**Assign DataSource**: Set the **DataSource** last to trigger the actual data retrieval and UI population.

**Clear Structure (Optional)**: If you are rebinding a grid to a different data member, use the **ClearStructure** method first to remove old column mappings and bands.

---

### Recordset

Returns or sets the recordset. Used to bind hierarchical or flat ADO data to the grid.

```
PROPERTY Recordset () AS Afx_ADORecordsetPTR
PROPERTY Recordset (BYVAL rs AS Afx_ADORecordset PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *rs* | A reference to an ADO Recordset. |

#### Remarks

You can bind it to a live recordset at runtime using the following syntax: 
```
' Assuming "rs" is an open ADODB Recordset
grid.Recordset = rs
```
```
' Assuming "rs" is an open ADODB Recordset
grid.DataSource = rs.DataSource
```

While the grid usually references the data through the **DataSource** property, it maintains an internal reference to the underlying **Recordset** for hierarchical navigation and data retrieval.

The `MSHFlexGrid` is uniquely designed to display "shaped" recordsets. If your recordset has a parent-child relationship (created via the `MSDataShape` provider), the grid automatically creates collapsible bands.

Even when bound to a recordset, the `MSHFlexGrid` is read-only by default. Users cannot type into cells to update the recordset; you must use an overlay (like a **TextBox**) to capture changes and manually update the recordset fields.

A long-standing legacy limitation is that the `MSHFlexGrid` may only display the first 2,048 rows when bound to a recordset, even if more records exist. To display more than this, developers use the **GetString** method of the recordset combined with the grid's **Clip** property for a manual, high-speed population. 

When binding a recordset, ensure proper cursor and lock settings to prevent runtime errors:

**Cursor type**: Use *adOpenStatic* or *adOpenKeyset* to ensure the recordset supports counting and navigation.

**Lock type**: Use *adLockReadOnly* for simple displays, or *adLockOptimistic* if you intend to perform manual updates to the data through code.

**Refreshing data**: To reflect changes made to the recordset (such as a deleted row), you can re-set the **DataSource** property to force the grid to rebuild its view. 

Note that in some specific environments or versions, attempting to set `grid.Recordset = rs` directly may result in a "Type Mismatch" error. It is generally safer and more reliable to use `grid.DataSource = rs.DataSource` for runtime binding. 

Many developers prefer using the grid in unbound mode to avoid binding limitations. You can manually manipulate the data rows using: 

**AddItem**: Appends a new row to the grid.

**TextMatrix(row, col)**: Directly sets or retrieves the text of any specific cell without changing the selection focus. 

---

### RowSet

Returns or sets the recordset. Used to bind hierarchical or flat ADO data to the grid.

```
PROPERTY Rowset () AS VARIANT
PROPERTY Rowset (BYVAL v AS VARIANT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *v* | A VARIANT containing reference to an ADO Recordset. |

**RowSet** is equivalent to **Recordset**, but returns the pointer wrapped into a VARIANT for compatibility with VB6.

---

### FillStyle

Returns or sets a value that determines whether setting the Text property, or one of the cell formatting properties, applies the change to all selected cells within the `MSHFlexGrid`.

```
PROPERTY FillStyle () AS FillStyleSettings
PROPERTY FillStyle (BYVAL style AS FillStyleSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *style* | One of the constants listed below. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexFillSingle** | 0 | Single. Changing **Text** or any of the cell properties only affects the active cell. This is the default. |
| **flexFillRepeat** | 1 | Repeat. Changing **Text** or any of the cell properties affects all selected cells. |

#### Remarks

The primary use of *flexFillRepeat* is to avoid slow loops when applying identical formatting to a large group of cells. Instead of iterating through every cell in a row or column, you can select the range and apply the property once. 

#### Usage Example

To quickly color an entire row green without a loop:
```
grid.Redraw = False           ' Boost performance
grid.FillStyle = flexFillRepeat 
grid.Row = 1                  ' Start of selection
grid.Col = 0
grid.RowSel = 1               ' End of selection
grid.ColSel = .Cols - 1
grid.CellBackColor = vbGreen  ' Applies to the whole selection
grid.FillStyle = flexFillSingle ' Reset to default
grid.Redraw = True
```
**Important limitations**

**Discontinuous selection**: The property does not work across discontinuous selections (like those made with *flexSelectionListBox*). Only the selection block containing the current active cell will be modified.

**Active cell focus**: When using *flexFillRepeat*, you must always ensure the **Row**, **Col**, **RowSel**, and **ColSel** properties are correctly defined to cover the intended range before applying the formatting change. 

---

### Clip

Returns or sets the contents of the cells in the `MSHFlexGrid`'s selected region.

```
PROPERTY Clip () AS DWSTRING
PROPERTY Clip (BYREF wszClip AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszClip* | One of the constants listed below. |

#### Remarks

It allows you to get or set the contents of a selected range of cells using a single string.

The **Clip** property operates exclusively on the current selection, defined by the **Row**, **Col**, **RowSel**, and **ColSel** properties. 

By default, tab characters (CHR(9)) indicate column breaks, and carriage returns (CHR(13)) indicate row breaks. 

**Clip** is significantly faster than using **TextMatrix** in a loop because it minimizes the number of individual property calls.

A critical use case for legacy maintenance is overcoming a bug where bound `MSHFlexGrids` only display the first 2,048 rows. By using the **GetString** method of an ADO Recordset, you can transfer thousands of rows into the grid instantly:
```
' Example: Populating a grid with 5,000 rows
grid.Rows = 5000
grid.Col = 0: grid.Row = 1
grid.ColSel = 5: grid.RowSel = 4999
grid.Clip = rs.GetString(adClipString)
```

**Clipboard interaction**: It is the standard property for implementing Copy and Paste functionality. You can move data to the system clipboard by simply assigning **Clip** to Clipboard.SetText. 

#### Technical limitations

**Selection mapping**: If the provided string contains more rows or columns than are currently selected in the grid, the extra data is ignored. If the string contains fewer rows/columns, the remaining selected cells are unaffected.

**Formatting**: The **Clip** property only transfers plain text. It does not preserve or transfer cell formatting such as colors, fonts, or images.

**Selection state**: Because **Clip** depends on the selection, you must ensure your code correctly sets the **RowSel** and **ColSel** boundaries before assignment to avoid "cutting off" data. 

---

### SelectionMode

Returns or sets a value that determines whether an MSHFlexGrid should allow regular cell selection, selection by rows, or selection by columns.

```
PROPERTY SelectionMode () AS SelectionModeSettings
PROPERTY SelectionMode (BYVAL selMode AS SelectionModeSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *selMode* | One of the constants listed below. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexSelectionFree** | 0 | Free. This allows individual cells in the `MSHFlexGrid` to be selected, spreadsheet style. This is the default. |
| **flexSelectionByRow** | 1 | By Row. This forces selections to span entire rows, as in a multi-column list box or record-based display. |
| **flexSelectionByColumn** | 2 | By Column. This forces selections to span entire columns, as if selecting ranges for a chart or fields for sorting. |

#### Remarks

The color of the selection is determined by the **BackColorSel** and **ForeColorSel** properties.

Even if **ByRow** is enabled, the grid still tracks a specific "active" cell using the **Row** and **Col** properties, though the entire row appears highlighted to the user.

#### Property interactions:

**AllowBigSelection**: If set to **True**, clicking on fixed header rows/columns will override **SelectionMode** to select the entire column or row.

**Highlight**: To ensure the selection remains visible even when the grid loses focus, set the **Highlight** property to 1 - *flexHighlightAlways*.

#### Example implementation

To configure a grid for a standard record-based display where clicking any data highlights the full record:
```
' Enable full-row selection for record-based views
grid.SelectionMode = flexSelectionByRow

' Ensure the selection is always visible
grid.Highlight = flexHighlightAlways
```

#### Technical tips

**Handling fixed rows**: By default, fixed rows (headers) cannot be selected. Clicking a fixed row usually selects the data column below it if **AllowBigSelection** is enabled.

**Programmatic selection**: You can still programmatically select ranges by setting **Row**, **Col**, **RowSel**, and **ColSel** regardless of the **SelectionMode** setting.

---

### Sort

Sets a value that sorts selected rows according to selected criteria.

```
PROPERTY Sort (BYVAL settings AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *settings* | One of the constants listed below. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexSortNone** | 0 | Free. None. No sorting is performed. |
| **flexSortGenericAscending** | 1 | Generic Ascending. An ascending sort, which estimates whether text is string or number, is performed. |
| **flexSortGenericDescending** | 2 | Generic Descending. A descending sort, which estimates whether text is string or number, is performed. |
| **flexSortNumericAscending** | 3 | Numeric Ascending. An ascending sort, which converts strings to numbers, is performed. |
| **flexSortNumericDescending** | 4 | Numeric Descending. A descending sort, which converts strings to numbers, is performed. |
| **flexSortStringNoCaseAsending** | 5 | String Ascending. An ascending sort using case-insensitive string comparison is performed. |
| **flexSortNoCaseDescending** | 6 | String Descending. A descending sort using case-insensitive string comparison is performed. |
| **flexSortStringAscending** | 7 | String Ascending. An ascending sort using case-sensitive string comparison is performed. |
| **flexSortStringDescending** | 8 | String Descending. A descending sort using case-sensitive string comparison is performed. |
| **flexSortCustom** | 9 | Custom. This uses the **Compare** event to compare rows. |

#### Remarks

The **Sort** property reorders rows based on values in specified columns. The rows to be sorted are determined by the **Row** and **RowSel** properties; if they are equal, all non-fixed rows are sorted. The columns used for sorting are defined by **Col** and **ColSel**. Sorting proceeds left-to-right across the selected columns

#### Example implementation

To sort all data rows by the second column (Index 1) in descending order:
```
grid.Redraw = False           ' Boost performance
grid.Row = 1                  ' Set range (Row 1 to last row)
grid.RowSel = .Rows - 1
grid.Col = 1                  ' Set sort key to Column 1
grid.ColSel = 1
grid.Sort = flexSortGenericDescending
grid.Redraw = True
```

#### Technical tips

**Custom sort speed**: The *flexSortCustom* setting is notably slower than standard methods.

**Date sorting**: A common technique for date sorting is to use a hidden column formatted as yyyy-mm-dd or using numeric date representations, then performing a numeric sort on that column.

**Multi-column limitation**: The grid only supports sorting on contiguous columns. For non-contiguous columns, you must adjust their positions using **ColPosition** before sorting. 

---

### BorderStyle

Specifies whether the grid is surrounded by a single-line border or no border at all.

```
PROPERTY BorderStyle () AS BorderStyleSettings
PROPERTY BorderStyle (BYVAL style AS BorderStyleSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *style* | One of the constants listed below. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexBorderNone** | 0 | No border. |
| **flexBorderSingle** | 1 | A flat border. |

#### Remarks

This property affects only the outer edge of the entire grid control. It does not control the lines between individual cells (gridlines).

While **BorderStyle** sets the outer frame, the **Appearance** property determines if that frame has a flat or 3D look.

The legacy `MSHFlexGrid` does not support complex outer borders like "Fixed3D" or "Inset" directly through the **BorderStyle** property alone; these effects are typically achieved by combining **BorderStyle** with the **Appearance** property. 

#### Technical tips

**Removing all borders**: To make the grid appear as a seamless part of a form, set **BorderStyle** = 0 (None) and set the **GridLines** property to 0 (None).

**Modern theme integration**: In modern Windows developers often set **BorderStyle** to 0 and place the `MSHFlexGrid` inside a container (like a **Frame**) to simulate custom modern border effects that match current OS aesthetics.

**Cell borders**: If you need to change the lines between cells, do not use **BorderStyle**. Instead, use **GridLines**, **GridLinesFixed**, or cell-specific properties like **CellAlignment**.

---

### Appearance

Returns or sets the paint style of the control.

```
PROPERTY Appearance () AS AppearanceSettings
PROPERTY Appearance (BYVAL app AS AppearanceSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *app* | One of the constants listed below. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexFlat** | 0 | The grid has a flat, two-dimensional appearance. |
| **flex3D** | 1 | The grid has a three-dimensional effect, typically with inset borders for a "sunken" look. |

#### Remarks

The **Appearance** property works in conjunction with the **BorderStyle** property. For a truly flat look, **Appearance** is often set to 0 and **BorderStyle** to 0 (None).

**Visual scope**: It primarily influences the outer frame and the lines separating fixed headers. It does not directly change the background color or font, which are handled by properties like **BackColor** and **Font**.

#### Technical tips

On modern high-DPI displays, many developers prefer the *flexFlat* (0) setting to match modern "flat design" OS aesthetics, as the legacy 3D effect can appear dated or blurry at high resolutions.

Changing the **Appearance** at runtime triggers an immediate repaint of the entire control. To avoid flickering during bulk property changes, set `Redraw = False` before making adjustments.

---

### Enabled

Determines whether the grid can respond to user-generated events such as mouse clicks, keyboard navigation, or scrolling.

```
PROPERTY Enabled () AS BOOLEAN
PROPERTY Enabled (BYVAL bEnabled AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bEnabled* | **True** (Default): The user can interact with the grid, select cells, and trigger events.<br>**False**: The grid is "locked." It will not respond to mouse or keyboard input. |

#### Remaerks

Unlike many other controls, the legacy `MSHFlexGrid` does not automatically "gray out" its text or background when **Enabled** is set to False. The data remains clearly visible, but the control becomes unresponsive.

When `Enabled = False`, events like **Click**, **DblClick**, **KeyDown**, and **SelChange** will not fire.

Setting `Enabled = False` does not prevent you from changing cell values or properties via code. You can still use **TextMatrix**, **CellBackColor**, and other properties to update the grid programmatically. 

#### Common use cases

**Read-only mode**: It is often used to temporarily lock the grid while a background data process or calculation is running to prevent the user from changing the selection.

**Input validation**: Developers disable the grid until a specific condition (like a login or a selection in another control) is met.

**Simulating grayed-out state**: Since the grid doesn't gray out automatically, developers often use a helper function to manually change the colors when disabling the control:
```
' To disable and show a visual change:
grif.Enabled = False
grid.ForeColor = vbGrayText
grid.BackColor = vbButtonFace
```
#### Technical tips

**Scrolling**: When `Enabled = False`, the user cannot move the scrollbars. If you want the user to be able to scroll but not select/edit data, you should leave `Enabled = True` and instead write code in the **BeforeSelChange** or **EnterCell** events to cancel interactions.

**Focus**: A disabled `MSHFlexGrid` cannot receive the input focus. If the grid has focus when you set `Enabled = False`, the focus will automatically move to the next available control in the tab order. 

---

### WordWrap

Returns or sets a value that determines whether a cell displays multiple lines of text or one long line of text.

```
PROPERTY WordWrap () AS BOOLEAN
PROPERTY WordWrap (BYVAL bWrap AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bWrap* | **True**The cell text displays with multiple, wrapping lines of text.<br>**False**: The cell text displays as one long line of text. This is the default. |

#### Remarks

This property determines whether the grid automatically breaks long strings containing spaces into multiple lines within a cell. 

The `MSHFlexGrid` displays text slightly faster when WordWrap is set to False.

A critical legacy behavior is that setting `WordWrap = True` does not automatically increase the row height to fit the wrapped text.

To actually see the wrapped text, you must manually increase the **RowHeight** property for the affected rows.

Strings containing manual line breaks (like CHR(13, 10)) will always wrap to multiple lines regardless of the **WordWrap** setting, provided the row is tall enough. 

#### Example implementation

To enable wrapping for a specific cell and ensure it is visible:
```
grid.WordWrap = True
grid.TextMatrix(1, 1) = "This is a long string that will wrap."
' Manually set a taller row height to display the wrapped content
grid.RowHeight(1) = 600 
```

#### Technical tips

**Alignment**: For best results with wrapped text, use the **ColAlignment** or **CellAlignment** properties to set vertical alignment to the top (e.g., *flexAlignLeftTop*) so the first line of text remains visible even if the row is too short.

On modern High-DPI displays, ensure your manual **RowHeight** adjustments account for current system scaling to prevent text from being truncated. 

---

### FocusRect

Returns or sets a value that determines whether the MSHFlexGrid should draw a focus rectangle around the current cell.

```
PROPERTY FocusRect () AS FocusRectSettings
PROPERTY FocusRect (BYVAL bFocusRect AS FocusRectSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bFocusRect* | *flexFocusNone*: No focus rectangle is displayed. The active cell is indistinguishable from others unless background/selection colors are used.<br>*flexFocusLight*: A light, dotted line rectangle appears around the active cell.<br>*flexFocusHeavy*:A thick, solid black rectangle appears around the active cell. |

#### Remarks

The **FocusRect** is distinct from the **BackColorSel** (selection highlight). The focus rectangle identifies the single "anchor" cell within a larger selected block of cells.

Developers often set `FocusRect = flexFocusNone` when building modern dashboard-style interfaces where a dotted line appears "dated." Instead, they rely on the `**BackColorSel** to show focus.

The **flexFocusHeavy** (2) setting is particularly useful for accessibility on modern high-resolution displays, where the light dotted line can be difficult for users to see.

#### Example implementation

To remove the dotted focus box for a cleaner, modern look:
```
' Removes the focus rectangle from the active cell
hrid.FocusRect = flexFocusNone
```

#### Technical tips

**Zebra-striping**: If you use alternating row colors, the **FocusRect** is the only way for the user to know exactly which cell has focus if you haven't enabled full-row selection (`SelectionMode = flexSelectionByRow`).

**Interaction with selection**: If you set **SelectionMode** to *ByRow* (1), the focus rectangle will still typically only appear around the specific cell the user clicked, even though the whole row is highlighted.

**Performance**: Changing this property does not require a full grid reload, but like all visual properties, wrapping changes in `Redraw = False/True` is best practice during bulk updates. 

---

### Highlight

Determines whether selected cells appear highlighted within the `MSHFlexGrid`.

```
PROPERTY Highlight () AS HighLightSettings
PROPERTY Highlight (BYVAL bHighlight AS HighLightSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bHighlight* | *flexHighlightNever*: There is no highlight on the selected cells.<br>*flexHighlightAlways*: The selected cells are always highlighted. (Default).<br>*flexHighlightWithFocus*: The highlight appears only when the control has focus. |

#### Remarks

This property controls the visibility of the highlight block (defined by **BackColorSel** and **ForeColorSel**).

When this property is set to zero and a range of cells is selected, there is no visual cue or emphasis indicating the selected cells.

Setting `Highlight = flexHighlightAlways (1)` is a common requirement for dashboard-style applications where the user needs to keep track of a selected record while typing data into a separate sidebar or detail view.

If a cell is merged, the built-in selection highlight may sometimes fail to appear correctly. In these specialized cases, developers often manually use **CellBackColor** as a fallback for custom highlighting.

While **Highlight** controls the broad selection colors, the **FocusRect** property manages the specific dotted or solid box around the single "anchor" cell within that selection.

#### Example implementation

To ensure the user's current selection remains visible even when they are interacting with other parts of the form:
```
' Keep the blue selection bar visible at all times
grid.Highlight = flexHighlightAlways

' Use with SelectionMode to highlight a whole record
grid.SelectionMode = flexSelectionByRow 
```

#### Technical tips

To change the actual color of the highlight, use the **BackColorSel** (background) and **ForeColorSel** (text) properties.

You can toggle **Highlight** programmatically during events like **GotFocus** and **LostFocus** to simulate custom UI behaviors that standard modes do not provide. 

---

### RowData

Returns or sets an arbitrary long value associated with each row. This property is an array that stores a Long for every row in the grid. It is purely for developer use and is never visible to the end-user.

```
PROPERTY RowData (BYVAL Index AS LONG) AS LONG
PROPERTY RowData (BYVAL Index AS LONG, BYVAL nData AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the row. |

#### Remarks

It allows you to link a visual grid row to a specific record ID in a database without needing to display that ID in a visible column.

One of the most important features of **RowData** is that the value stays with the row. If you sort the grid or move rows using **RowPosition**, the **RowData** value moves automatically with its associated row content.

Since **RowData** only accepts Longs, if you need to store a hidden string (like a GUID), you must instead use a hidden column (setting ColWidth(index) = 0).

#### Example implementation

Storing a database ID when populating the grid and retrieving it when the user clicks a row:

```
' 1. Storing the ID (Unbound mode)
grid.AddItem "John Smith"
grid.RowData(grid.Rows - 1) = 1042 ' Hidden Primary Key

' 2. Retrieving the ID during a Click event
Dim selectedID As Long
selectedID = grid.RowData(grid.Row)
PRINT "You selected Record ID: " & STR(selectedID)
```

#### Technical tips

Using **RowData** is more memory-efficient than creating an extra hidden column, as it doesn't involve the overhead of the grid's cell-rendering engine.

There is a corresponding **ColData** property that performs the same function for columns, though it is used much less frequently than **RowData**.

When the grid is bound to a data source, **RowData** is not automatically populated with the Primary Key. You must still populate it manually if you need quick access to a specific numeric identifier outside of the bound recordset.

---

### ColData

Returns or sets an arbitrary long value associated with each column. This property is an array that stores a Long for every column in the grid. It is purely for developer use and is never visible to the end-user.

```
PROPERTY ColData (BYVAL Index AS LONG) AS LONG
PROPERTY ColData (BYVAL Index AS LONG, BYVAL nData AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based index of the column. |

#### Remarks

It is most commonly used to store internal identifiers, such as database field types, original source indices, or bit-flags that determine how the column should behave (e.g., "Sortable" vs. "Non-sortable").

If you move a column using the **ColPosition** property, the **ColData** value moves with it, ensuring the metadata stays attached to the correct data column.

The value is never rendered on the screen. It is accessible only through code. 

#### Example implementation

A common use case is tagging columns with a "Data Type" flag to determine how to format them during a dynamic population:
```
' Define constants for custom data types
Const TYPE_STRING = 0
Const TYPE_CURRENCY = 1

' Tag Column 2 as a currency column
grid.ColData(2) = TYPE_CURRENCY

' Later, check the tag to apply formatting
If grid.ColData(grid.Col) = TYPE_CURRENCY Then
    Print "This column contains financial data."
End If
```

#### Technical tips

**ColData** only accepts Long integers. If you need to store hidden strings (like field names), you should instead use a hidden row (RowHeight(0) = 0) or maintain a separate internal string array.

For modern systems, using **ColData** is highly efficient as it avoids the overhead of creating additional hidden columns or complex dictionaries to track column attributes.

---

### BandData

Returns or sets an arbitrary long value associated with each band. This property is an array that stores a Long for every band in the grid. It is purely for developer use and is never visible to the end-user.

```
PROPERTY BandData (BYVAL band AS LONG) AS LONG
PROPERTY BandData (BYVAL band AS LONG, BYVAL nData AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *band* | The zero-based index of the band (e.g., 0 for the parent level, 1 for the first child level). |

#### Remarks

It is an "arbitrary" value, meaning it has no inherent effect on the grid's display. It is used programmatically to "tag" bands with information such as a database table ID, a bit-mask for permissions, or a custom state flag.

In complex hierarchical views (Master-Detail-Subdetail), **BandData** is often used to quickly identify which database entity a specific band represents without having to check the grid's data source or binding string. 

#### Example implementation

To tag Band 0 as "Main Records" and Band 1 as "Sub-Items" for later logic:
```
' Tag the parent band with a custom code (e.g., 100)
grid.BandData(0) = 100

' Tag the first child band with a custom code (e.g., 200)
grid.BandData(1) = 200

' Later, check which band the user is currently interacting with
If grid.BandData(grid.BandDisplay) = 100 Then
    Print "You are in the primary data level."
End If
```

#### Technical tips

Using **BandData** is highly efficient as it stores simple integers directly in the control's internal array, avoiding the overhead of external dictionaries or hidden labels.

**BandData** only supports Long values. If you need to associate a string with a band, you must instead use a hidden row/column or store the string in a separate array using the value in **BandData** as the index.

While **BandData** stores your custom values, the **BandDisplay** property is used to determine which band contains the currently active cell. 

---

### BandDisplay

Specifies how the bands display within the MSHFlexGrid.

```
PROPERTY BandDisplay () AS BandDisplaySettings
PROPERTY BandDisplay (BYVAL settings AS BandDisplaySettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *settings* | A value that specifies how the bands display within the grid:<br>*flexBandDisplayHorizontal*: Default. The bands within the grid display horizontally (across).<br>*flexBandDisplayVertical*: The bands within the grid display vertically (up and down). |

#### Remarks

This property is only effective when the `MSHFlexGrid` is bound to a hierarchical data source, such as an ADO Shaped Recordset. It has no effect on a standard flat (non-hierarchical) grid.

Switching to vertical display is often used for "pivoted" data views where relationships are easier to read from left-to-right rather than top-to-bottom.

Regardless of the display orientation, you can still control the appearance of headers for each level using properties like **BackColorHeader** or **GridLinesHeader**.

#### Example implementation

To change a grid from its default horizontal list view to a vertical hierarchical view:
```
' Changes the bands to display vertically (columns)
grid.BandDisplay = flexBandDisplayVertical
```

#### Technical tips

The "hierarchical" features of the `MSHFlexGrid`, including band display settings, generally only work when the control is data-bound. In unbound mode, the grid functions like a standard `MSFlexGrid` with limited band support.

Changing the **BandDisplay** property at runtime triggers a full rebuild of the grid's visual structure. It is best practice to set `Redraw = False` before the change to prevent screen flickering.

You can further refine the display using **BandExpandable**, which determines if users can collapse or expand these bands at runtime.

---

### BandExpandable

Returns and sets a value that determines whether the row in the current band can be expanded and collapsed. The current band is defined by the **Col** and **Row** properties. 

```
PROPERTY BandExpandable (BYVAL BandNumber AS LONG) AS BOOLEAN
PROPERTY BandExpandable (BYVAL BandNumber AS LONG, BYVAL bExpandable AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A Long representing the zero-based index of the specific hierarchical band (0 for the parent level, 1 for the first child level, etc.). |
| *bExpandable* | **True** (Default) enables the expansion/collapse feature for the band; **False** prevents the user from changing its visibility state. |

#### Remarks

This property is an array-based setting indexed by the band number. It allows you to control the "drill-down" capability for each level of nested data independently. 

When set to **True**, the grid displays "+" and "-" icons next to parent records, allowing users to drill down into one-to-many relationships.

This property is only functional when the grid is bound to a hierarchical data source, such as a Shaped Recordset created via the `MSDataShape` provider.

If set to **False**, the specified band remains in its current state (either fully expanded or fully collapsed) and the user cannot toggle it. 

#### Example implementation

To lock the primary parent band so users cannot collapse it while allowing child bands to be toggled:
```
' Prevents the parent band (Band 0) from being collapsed
grid.BandExpandable(0) = False

' Allows the first child level (Band 1) to be expanded/collapsed
grid.BandExpandable(1) = True
```

#### Technical tips

This property has no effect if the grid is used as an unbound control, as the "hierarchical" logic is managed by the underlying data provider.

For modern applications running legacy environments, ensuring **BandExpandable** is only enabled for necessary levels can reduce visual clutter and simplify navigation in deep data trees.

---

### RowExpandable

Determines whether the current row can be expanded to display child rows. The current row is defined by the **Col** and **Row** properties.

```
PROPERTY RowExpandable () AS BOOLEAN
```

#### Return value

**True**: The current row has child rows and can be expanded.

**False**: The current row has no child rows and cannot be expanded.

---

### RowExpanded

Indicates or sets whether the current row is expanded. The current row is defined by the **Col** and **Row** properties.

```
PROPERTY RowExpanded () AS BOOLEAN
PROPERTY RowExpanded (BYVAL bRowExpanded AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bRowExpanded* | Assigning **True** expands the current row. Assigning **False** collapses the current row. |

#### Return value

**True**: The current row is expanded and its child rows are visible.

**False**: The current row is collapsed and its child rows are hidden.

#### Example implementations
```
' Expand the current row
grid.RowExpanded = TRUE

' Collapse the current row
grid.RowExpanded = FALSE

' Check expansion state
If grid.RowExpanded Then
    Print "Row is expanded"
End If
```
To programmatically expand all rows in a grid after a data refresh:
```
' Loop through all rows to expand them
grid.Redraw = False ' Prevent flickering
For i As Long = 0 To grid.Rows - 1
   ' Attempt to expand the row; non-expandable rows will simply be ignored
   grid.RowExpanded(i) = True
Next
grid.Redraw = True
```

#### Remarks

This property only has an effect when the `MSHFlexGrid` is displaying hierarchical data, typically from a `SHAPE` recordset created with the `MSDataShape` provider.

When a row is expandable, the grid automatically displays "+" or "-" icons. Setting **RowExpanded** to **True** or **False** programmatically is the equivalent of a user clicking these icons.

For a row to be expandable, the **BandExpandable** property for its specific level must be set to True

#### Technical tips

You can read the property to check if a user has currently expanded a specific record: `If grid.RowExpanded(10) Then ...`

This property has no effect on MSHFlexGrid if it is used in an unbound mode (manually populated via **AddItem**).

Large hierarchical grids can be resource-intensive. When toggling expansion states for many rows, always use the `Redraw = False` property to improve performance on modern high-resolution displays. 

---

### CollapseAll

Collapses all rows in the grid according to the specified band. If no band is specified, all rows in all bands are collapsed.

```
FUNCTION CollapseAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The band to collapse. If omitted or set to –1, all bands are collapsed. |

#### Example implementations
```
' Collapse all rows in all bands
grid.CollapseAll

' Collapse only band 1
grid.CollapseAll 1
```
---

### ExpandAll

Expands all rows in the grid according to the specified band. If no band is specified, all rows in all bands are expanded.

```
FUNCTION ExpandAll (BYVAL BandNumber AS LONG = -1) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The band to expand. If omitted or set to –1, all bands are expanded. |

#### Example implementations
```
' Expand all rows in all bands
grid.ExpandAll

' Expand only band 1
grid.ExpandAll 1
```
---

### GridLineWidth

Returns or sets the preferred width, in pixels, for the current line. Its purpose is to visually control the spacing and clarity of cell borders, complementing other styling choices. 

```
PROPERTY GridLineWidth () AS SHORT
PROPERTY GridLineWidth (BYVAL nWidth AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | An integer representing the width in pixels (e.g., 2 for a thicker line). |

#### Example
```
' Set grid lines to be raised and 2 pixels thick
grid.GridLines = flexGridRaised
grid.GridLineWidth = 2
grid.GridColor = &HFF0000 ' Example: Red grid lines
```
#### Remarks

Sets the thickness of the grid lines in pixels, allowing you to adjust how thick or thin the separating lines between cells appear, controlling the visual density of the grid. It's a property that works with other styling options like **GridLines** (e.g., *flexGridInset*, *flexGridRaised**) and **GridColor** to customize the grid's look and feel. 

#### Key related properties

**GridLines**: Defines the 3D style (e.g., *flexGridInset*, *flexGridRaised*, *flexGridFlat*).

**GridColor**: Sets the color of the grid lines.

**GridColorFixed**: Sets the color for fixed (header) cells. 

---

### GridLineWidthFixed

Returns or sets the preferred width, in pixels, of the fixed areas of the grid.

```
PROPERTY GridLineWidthFixed () AS SHORT
PROPERTY GridLineWidthFixed (BYVAL nWidth AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | An integer representing the width in pixels (e.g., 2 for a thicker line). |

#### Example
```
grid.GridLineWidthFixed = 2  ' Sets fixed grid lines to be 2 pixels wide
grid.GridLineWidth = 1       ' Sets scrollable grid lines to be 1 pixel wide
```
#### Remarks

This property determines the thickness (width) of the lines separating cells in the fixed rows (top-most rows that don't scroll) and fixed columns (left-most columns that don't scroll).

Using a thicker width for fixed areas can help visually separate headers from the scrollable region, but very large differences may create uneven borders.

#### Key related properties

**GridLineWidth**: Width of lines in the scrollable (non-fixed) area.

**GridLineWidthHeader**: Width of lines in the header area.

**GridLineWidthBand**: Width of lines for a specific band. 

---

### GridLineWidthUnpopulated

Returns or sets the preferred width, in pixels, of the unpopulated areas of the grid — regions where no data, fixed rows, fixed columns, or banded structure is present.

```
PROPERTY GridLineWidthUnpopulated () AS SHORT
PROPERTY GridLineWidthUnpopulated (BYVAL nWidth AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | An integer representing the width in pixels (e.g., 2 for a thicker line). |

#### Example
```
grid.GridLineWidthUnpopulated = 2  ' Sets unpopulated grid lines to be 2 pixels wide
grid.GridLineWidth = 1             ' Sets scrollable grid lines to be 1 pixel wide
```
#### Remarks

In hierarchical layouts, the `MSHFlexGrid` may contain areas that do not correspond to any data row, fixed row, or band. These “unpopulated” regions appear when:

* the grid is larger than the data it displays
* bands have uneven row counts
* indentation or outline levels leave visual gaps

**GridLineWidthUnpopulated** controls the thickness of the grid lines drawn in these empty regions, allowing you to visually distinguish them from populated cells.

This property is one of several width‑specific settings that let you fine‑tune the appearance of different grid areas:

* **GridLineWidth** – scrollable populated cells
* **GridLineWidthFixed** – fixed rows and fixed columns
* **GridLineWidthBand** – specific band
* **GridLineWidthHeader** – band header area
* **GridLineWidthIndent** – indentation area
* **GridLineWidthUnpopulated** – empty/unpopulated regions

---

### GridLineWidthBand

Returns or sets the preferred width, in pixels, of the specified band of the grid.

```
PROPERTY GridLineWidthBand (BYVAL BandNumber AS LONG) AS SHORT
PROPERTY GridLineWidthBand (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
PROPERTY GridLineWidthBand () AS SHORT
PROPERTY GridLineWidthBand (BYVAL nWidth AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose line width is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *nWidth* | An integer representing the width in pixels (e.g., 2 for a thicker line). |

#### Example
```
grid.GridLineWidthBand(0) = 2  ' Sets the first band to be 2 pixels wide
grid.GridLineWidthBand(1) = 1  ' Sets the second band to be 1 pixel wide
```

#### Remarks

The `MSHFlexGrid` control (Microsoft Hierarchical FlexGrid) is an ActiveX control that displays data in a grid format, particularly supporting hierarchical recordsets (data organized into bands). 

The **GridLineWidthBand** property specifically controls the width (thickness) of the grid lines that separate these hierarchical data bands. 

This property is one of several width‑specific settings that let you fine‑tune the appearance of different grid areas:

* **GridLineWidth** – scrollable populated cells
* **GridLineWidthFixed** – fixed rows and fixed columns
* **GridLineWidthBand** – specific band
* **GridLineWidthHeader** – band header area
* **GridLineWidthIndent** – indentation area
* **GridLineWidthUnpopulated** – empty/unpopulated regions

---

### GridLineWidthHeader

Returns or sets the preferred width, in pixels, of the grid lines drawn in the header area of a specific band.

```
PROPERTY GridLineWidthHeader (BYVAL BandNumber AS LONG) AS SHORT
PROPERTY GridLineWidthHeader (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
PROPERTY GridLineWidthHeader () AS SHORT
PROPERTY GridLineWidthHeader (BYVAL nWidth AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose header line width is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *nWidth* | An integer representing the width in pixels (e.g., 2 for a thicker line). |

#### Example
```
grid.GridLineWidthHeader(0) = 2  ' Sets the headers of first band to be 2 pixels wide
grid.GridLineWidthHeader(1) = 1  ' Sets the headers of the second band to be 1 pixels wide
```

#### Remarks

The `MSHFlexGrid` control supports hierarchical data, where each level of the hierarchy is represented as a band. The **GridLineWidthHeader** property controls the thickness of the grid lines drawn in the header area of a specific band, allowing each level of the hierarchy to have its own visual style.

This property is one of several width‑specific settings that let you fine‑tune the appearance of different grid areas:

* **GridLineWidth** – scrollable populated cells
* **GridLineWidthFixed** – fixed rows and fixed columns
* **GridLineWidthBand** – specific band
* **GridLineWidthHeader** – band header area
* **GridLineWidthIndent** – indentation area
* **GridLineWidthUnpopulated** – empty/unpopulated regions

---

### GridLineWidthIndent

Returns or sets the preferred width, in pixels, of the grid lines drawn within the indentation area of the hierarchical display. 

```
PROPERTY GridLineWidthIndent (BYVAL BandNumber AS LONG) AS SHORT
PROPERTY GridLineWidthIndent (BYVAL BandNumber AS LONG, BYVAL nWidth AS SHORT)
PROPERTY GridLineWidthIndent () AS SHORT
PROPERTY GridLineWidthIndent (BYVAL nWidth AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose indent line width is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *nWidth* | An integer representing the width in pixels (e.g., 2 for a thicker line). |

#### Example
```
grid.GridLineWidthIndent(0) = 2  ' Sets the indents of first band to be 2 pixels wide
grid.GridLineWidthIndent(1) = 1  ' Sets the indents of the second band to be 1 pixels wide
```

#### Remarks

In hierarchical layouts, child rows are visually indented to reflect their level within the structure. The **GridLineWidthIndent** property controls the thickness of the grid lines drawn in these indentation regions, allowing you to visually distinguish different hierarchy levels or emphasize structural depth.
 
This property is one of several width‑specific settings that let you fine‑tune the appearance of different grid areas:

* **GridLineWidth** – scrollable populated cells
* **GridLineWidthFixed** – fixed rows and fixed columns
* **GridLineWidthBand** – specific band
* **GridLineWidthHeader** – band header area
* **GridLineWidthIndent** – indentation area
* **GridLineWidthUnpopulated** – empty/unpopulated regions

---

### Bands

Returns the total number of bands in an `MSHFlexGrid`. The `MSHFlexGrid` always has a minimum of one band. When the `MSHFlexGrid` is bound to a standard Recordset, the entire `MSHFlexGrid` is treated as one band.

```
FUNCTION Bands () AS LONG
```

#### Example
```
grid.Bands  ' Gets the number of bands
```

#### Remarks

Bands are the structural components used to display hierarchical or "parent-child" data relationships. `MSHFlexGrid` uses bands to organize multi-level data sets. 

Each band represents one level of a hierarchical Recordset. For instance, "Band 0" typically displays parent records (e.g., Customers), while "Band 1" displays associated child records (e.g., Orders).

Bands are primarily a feature of bound mode. They are most commonly populated using ADO Data Shaping (the `MSDataShape` provider). In unbound mode, the hierarchical functionality of bands is largely unavailable.

The number of bands depends entirely on the structure of the bound Recordset (or Data Shape). Band 0 is always the top‑level (root) band.
Subsequent bands follow the order in the shaped Recordset. Unbound grids always return 1.

* **Bands Property**: Returns the total number of bands in the control.
* **BandLevel / BandColIndex**: Used to identify the specific band or column index within a band for formatting.
* **BandDisplay**: Determines if bands are displayed horizontally (stacked) or vertically. 

You can customize the appearance of each band independently to distinguish between data levels: 

**Coloring**: Properties such as **BackColorBand**, **BackColorHeader**, and **BackColorIndent** can be set specifically for a BandNumber.

**Interaction**: Users can often expand or collapse bands to manage complex data views.

**Header customization**: You can set unique captions for columns within each band via the control's property pages at design time or through specific runtime properties. 

---

### BandLevel

Returns the zero-based band number that contains the current cell. The band numbers begin at 0. The current cell is determined by the **Col** and **Row** properties. 

```
FUNCTION BandLevel () AS LONG
```

#### Example
```
grid.BandLevel  ' band number that contains the current cell
```

#### Remarks

It returns the band index (starting at 0) for the cell that currently has focus. For example, if you click a cell in the parent row, **BandLevel** might return 0; clicking a child record would return 1.

It is frequently used in conjunction with the **BandColIndex** property to format columns within a specific hierarchical level.

A common implementation is using **BandLevel** with the **ColWidth** property to adjust the width of columns belonging to a particular band rather than the entire grid. 

To set the width of the first column in the second band (Band 1):
```
' Syntax: MSHFlexGrid.ColWidth(index, [bandlevel])
grid.ColWidth(0, 1) = 1500 
```

#### Related band properties

* **Bands**: Returns the total number of bands currently in the grid.
* **BandColIndex**: Returns the column index relative to its specific band, rather than the absolute column index of the entire grid.
* **ColHeaderCaption**: Allows you to set or return the header text for a column at a specific band level. 

---

### BandColIndex

Returns the index of a column relative to its specific band (hierarchical level), rather than its absolute position in the entire grid. 

```
FUNCTION BandColIndex () AS LONG
```

#### Remarks

In a hierarchical grid, a column might be the 10th column overall but the 0th column within "Band 1" (the first child level). **BandColIndex** provides this local index.

This property is primarily used to identify which logical data field a user has clicked or selected within a specific level of the hierarchy.

It is almost always used in conjunction with the **BandLevel** property to uniquely identify a cell's location in a multi-band data structure. 

#### Common use cases

**Dynamic formatting**: Developers use **BandColIndex** to apply formatting (like **ColWidth** or **ColAlignment**) to all columns of a specific type across multiple parent records.

**Data retrieval**: When a user clicks a cell, **BandColIndex** helps determine which field in the underlying Recordset is being accessed, regardless of how many columns are displayed in parent bands above it.

**Auto-sizing**: It is a critical property for loops that auto-size columns, as it allows the code to reference the correct band and column pair when using the **ColWidth** method. 

#### Example
```
Dim localCol As Long
Dim currentBand As Long

localCol = grid.BandColIndex
currentBand = grid.BandLevel

Print "You clicked column " & STR(localCol) & " in Band " & STR(currentBand)
```
---

### BandIndent

Specifies the number of columns by which a particular band is indented relative to the left edge of the control.

```
PROPERTY BandIndent (BYVAL BandNumber AS LONG) AS LONG
PROPERTY BandIndent (BYVAL BandNumber AS LONG, BYVAL nCols AS LONG)
PROPERTY BandIndent () AS LONG
PROPERTY BandIndent (BYVAL nCols AS LONG)
```
| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The zero-based index of the band you wish to indent. If the band number is omited, band 0 is assumed. |
| *nCols* | The number of columns to use for the indentation. |

#### Remarks

By indenting child bands (e.g., Band 1, Band 2), developers can create a "drill-down" effect that makes it easier for users to distinguish between parent and child records in a `SHAPE` command-based dataset.

When using **BandIndent**, developers often use these related properties to further customize the indented areas:

**BackColorIndent**: Sets the background color of the indented area for a specific band.

**ColWidth**: Often used with a band parameter (*ColWidth(column, band)*) to ensure the columns within an indented band are sized appropriately without affecting the parent band.

**BandDisplay**: Determines if the bands are displayed horizontally (default) or vertically, which affects how the indentation appears visually. 

---

### GetBandName

Returns the name of the specified band.

```
FUNCTION GetBandName (BYVAL BandNumber AS LONG) AS DWSTRING
```
| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The zero‑based index of the band whose name you want to retrieve. |

#### Remarks

**GetBandName** returns the display name associated with a band in a hierarchical Recordset. These names originate from the shaped Recordset structure (typically created using the `MSDataShape` provider). For example, a `SHAPE` command such as:
```
SHAPE {SELECT * FROM Customers} APPEND ({SELECT * FROM Orders} AS Orders) RELATE CustomerID TO CustomerID
```
creates two bands:

* Band 0 → "Customers"
* Band 1 → "Orders"

**GetBandName** allows you to retrieve these names at runtime, which is especially useful for:

* displaying band names in custom UI elements
* debugging hierarchical structures
* applying formatting rules based on band identity
* dynamically generating captions or tooltips

If the Recordset does not define explicit band names, the control may return an empty string.

#### Example
```
Dim bandName As `DWString
bandName = grid.GetBandName(1)
Print "Band 1 name: "; bandName
```
---

### CountColumnsInBand

Returns the number of columns of the specified band.

```
FUNCTION CountColumnsInBand (BYVAL BandNumber AS LONG) AS LONG
```
| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The zero‑based index of the band whose column count you want to retrieve. |

#### Remarks

**CountColumnsInBand** returns the number of columns defined within a specific band of a hierarchical grid. This is especially useful when working with shaped Recordsets, where each band may have a different number of fields.

Typical uses include:

* iterating through all columns of a specific band
* applying formatting (e.g., **ColWidth**, **ColAlignment**) only to columns belonging to that band
* dynamically generating headers or layouts based on the band structure
* debugging shaped Recordsets to verify the expected number of fields per band

#### Example
```
Dim cols As Long = grid.CountColumnsInBand(1)
Print "Band 1 has "; cols; " columns."
```
---

### CollectBandFieldNameInfo

Forces the grid to collect or refresh internal band and field name information from the bound hierarchical Recordset.

```
FUNCTION CollectBandFieldNameInfo (BYVAL force_collection AS LONG) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *force_collection* | Non‑zero forces a full rebuild of band/field metadata; zero collects only if not already initialized. |

#### Remarks

This method is undocumented in the official `MSHFlexGrid` reference. It is used internally by the control to populate band names, field names, and column mappings when working with hierarchical (shaped) Recordsets. Application code typically does not need to call this method directly.

---

### GetColumnInBandInfo

Undocumented. Retrieves all metadata for a specific column within a specific band (hierarchical level).

```
FUNCTION CMSHFlexGrid.GetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, _
   BYVAL ColName AS BSTR PTR, BYVAL Caption AS BSTR PTR, BYVAL Hidden AS VARIANT_BOOL PTR, _
   BYVAL RowsetColIndex AS LONG PTR, BYVAL Alignment AS SHORT PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | Zero‑based band index of the band. |
| *UIIndex* | Zero‑based column index within that band. |
| *ColName* | Receives the underlying Recordset field name. |
| *Caption* | Receives the display caption for this column. |
| *Hidden* | Receives whether the column is hidden (VARIANT_TRUE / VARIANT_FALSE). |
| *RowsetColIndex* | Receives the absolute Recordset column index for this band column. |
| *Alignment* | Receives the alignment constant used for this column. |

This is the internal metadata accessor for hierarchical columns.
It returns everything the grid knows about a column in a specific band:

* the logical field name
* the display caption
* whether the column is hidden
* the Recordset field index this column maps to
* the alignment used for rendering

This is the low‑level API behind:

* ColHeaderCaption
* ColAlignment
* ColHidden
* BandColIndex
* CountColumnsInBand

The grid calls this internally when building the UI for shaped Recordsets.

#### When to use it

You would call this if you need to:

* inspect the structure of a shaped Recordset
* debug band/column mappings
* build custom UI elements
* understand how the grid mapped fields to bands
* enumerate columns within a band

**Note**: **GetColumnInBandInfo** and **SetColumnInBandInfo** are undocumented internal methods of the `MSHFlexGrid`. They are used by the control to manage hierarchical column metadata. They are fully functional but should be used with care, as invalid values may cause inconsistent grid behavior.

---

### SetColumnInBandInfo

Undocumented. Sets or updates the metadata for a specific column within a specific band.

```
FUNCTION SetColumnInBandInfo (BYVAL BandNumber AS LONG, BYVAL UIIndex AS LONG, _
   BYVAL ColName AS BSTR, BYVAL Caption AS BSTR, BYVAL Hidden AS VARIANT_BOOL, _
   BYVAL RowsetColIndex AS LONG, BYVAL Alignment AS SHORT) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | Zero‑based band index of the band. |
| *UIIndex* | Zero‑based column index within that band. |
| *ColName* | New underlying field name. |
| *Caption* | New display caption. |
| *Hidden* | Whether the column should be hidden (VARIANT_TRUE / VARIANT_FALSE). |
| *RowsetColIndex* | New Recordset field index to map to. |
| *Alignment* | New alignment constant. |

This is the internal setter for hierarchical column metadata.

It allows the grid to modify:

* captions
* hidden state
* alignment
* field mapping
* column names

This is the mechanism behind the following public properties:

* ColHeaderCaption
* ColAlignment
* ColHidden
* ColData
* ColWidth (indirectly)

The grid calls this internally when

* applying formatting
* responding to property changes
* rebuilding the UI after binding
* refreshing shaped Recordsets

#### Should developers call this?

Normally no, because:

* invalid metadata can break the grid
* the control assumes these values match the Recordset
* Microsoft never intended this to be public

**Note**: **GetColumnInBandInfo** and **SetColumnInBandInfo** are undocumented internal methods of the `MSHFlexGrid`. They are used by the control to manage hierarchical column metadata. They are fully functional but should be used with care, as invalid values may cause inconsistent grid behavior.

---

### ApplyBandFieldNameInfoChanges

Undocumented. Applies any pending changes to the internal band/field metadata previously modified through internal methods such as **SetColumnInBandInfo**.

```
FUNCTION ApplyBandFieldNameInfoChanges () AS HRESULT
```

**ApplyBandFieldNameInfoChanges** is an undocumented internal method of the `MSHFlexGrid`. It finalizes and commits updates made to the grid’s internal representation of:

* band names
* field names
* column captions
* hidden states
* alignment
* Recordset field mappings

This method works in conjunction with the following internal functions:

* **CollectBandFieldNameInfo**: Gathers the initial metadata from the shaped Recordset.
* **GetColumnInBandInfo**: Retrieves metadata for a specific column in a band.
* **SetColumnInBandInfo**: Modifies metadata for a specific column in a band.

After one or more calls to **SetColumnInBandInfo**, the grid does not immediately rebuild its internal structures. Instead, it queues the changes.

**ApplyBandFieldNameInfoChanges** forces the grid to:

* validate the updated metadata
* rebuild its internal band/column tables
* refresh the UI to reflect the changes

#### When to use it

You would only call this method if you are:

* programmatically modifying band/column metadata
* dynamically altering captions, hidden states, or field mappings
* building advanced wrappers (like yours)
* debugging shaped Recordset structures

For normal usage, this method is never needed and was never intended to be exposed.

#### Example (Conceptual)
```
' Modify metadata for a column in Band 1
grid.SetColumnInBandInfo 1, 0, "OrderID", "Order ID", False, 3, 1

' Commit the changes
grid.ApplyBandFieldNameInfoChanges
```
---

### RowSizingMode

Returns or sets a value that describes the sizing mode of the rows in the `MSHFlexGrid`.

```
PROPERTY RowSizingMode () AS RowSizingSettings
PROPERTY RowSizingMode (BYVAL sizingMode AS RowSizingSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *sizingMode* | An integer or constant that specifies the settings of the row size.<br>*flexRowSizeIndividual*: Resizing a row changes only the height of that row. This is the default.<br>*flexRowSizeAll*: Resizing a row changes the height of all rows in the `MSHFlexGrid`. |

#### Remarks

This property only takes effect when **AllowUserResizing** is set to to *flexResizeRows* or *flexResizeBoth*.

Users typically initiate resizing by dragging the boundary of a row in the fixed column (the gray header area on the left).

In hierarchical (multi‑band) layouts, **RowSizingMode** applies to the actual rendered rows, not to logical bands. When set to *flexRowSizeAll*, resizing any row causes every visible row—parent rows, child rows, and grandchildren—to adopt the same height.

This behavior is purely visual; it does not affect the underlying Recordset or band structure.

#### Example

To ensure that all rows stay uniform in height whenever a user adjusts one:
```
grid.AllowUserResizing = flexResizeRows
grid.RowSizingMode = flexRowSizeAll
```
---

### ColWordWrapOption

Returns or set how text wraps or is truncated within a specific column. Unlike the global WordWrap property, this provides per‑column control over wrapping behavior.

```
PROPERTY ColWordWrapOption (BYVAL Index AS LONG) AS WordWrapSettings
PROPERTY ColWordWrapOption (BYVAL Index AS LONG, BYVAL opt AS WordWrapSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero-based column index. |
| *opt* | An integer value or constant that defines how text is displayed:<br>*flexWordBreak*: Normal word-breaking/wrapping.<br>*flexWordBreakEllipsis*: Wraps text but appends an ellipsis ("...") if the text is still too long for the available space. |

#### Remarks

Setting this property to enable wrapping does not automatically adjust the row height. You must manually set the **RowHeight** property for the wrapped text to be visible.

For standard word wrapping to occur, the text must contain spaces; otherwise, the control may simply truncate the string or require manual row height adjustments. 

#### Example

To enable wrapping with an ellipsis for the first column:
```
' Enable global word wrap first
grid.WordWrap = True

' Set specific option for Column 0
grid.ColWordWrapOption(0) = flexWordBreakEllipsis

' Manually increase row height to see the wrapped content
grid.RowHeight(1) = 1000 
```
---

### ColWordWrapOptionBand

Returns or sets how text wraps or is truncated within a specific band. Unlike the global **WordWrap** property, which targets a single column index, this property applies the specified wrapping rule to every column in the designated band.

```
PROPERTY ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS WordWrapSettings
PROPERTY ColWordWrapOptionBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYVAL opt AS WordWrapSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The zero-based index of the hierarchical band. |
| *BandColIdx* | The zero‑based index of the column within that band. A value of –1 applies the setting to all the bands. |
| *opt* | An integer value or constant that defines how text is displayed:<br>*flexWordBreak*: Normal word-breaking/wrapping.<br>*flexWordBreakEllipsis*: Wraps text but appends an ellipsis ("...") if the text is still too long for the available space. |

#### Remarks

To see any effect, the global **WordWrap** property must be set to **True**.

Enabling this property does not automatically resize rows. You must programmatically adjust the **RowHeight** to accommodate multiple lines of text.

The setting applies only to the specified band column, not to the corresponding absolute column index in the flattened grid.

In hierarchical layouts, each band maintains its own formatting table.
This means two different bands can have different wrapping rules for columns that share the same absolute column index.

#### Behavior notes

Fixed rows belonging to a band (e.g., band headers) also obey this setting.

Wrapping only occurs at whitespace; long unbroken strings may still be truncated.

When using *flexWordBreakEllipsis*, the ellipsis always appears at the end of the visible text, regardless of horizontal alignment.

#### Related properties

* **ColWordWrapOptionFixed**: Specifically controls wrapping for fixed (header/sidebar) columns.
* **ColWordWrapOptionHeader**: Controls wrapping behavior specifically for column headers.
* **ColAlignmentBand**: Often used alongside wrapping to ensure text is aligned correctly (e.g., top-left) within the expanded row space. 

---

### ColWordWrapOptionHeader

Returns or sets how text wraps or is truncated within a specific column header.

```
PROPERTY ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS WordWrapSettings
PROPERTY ColWordWrapOptionHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYVAL opt AS WordWrapSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The zero-based index of the hierarchical band. |
| *BandColIdx* | The zero‑based index of the column within that header. A value of –1 applies the setting to all header columns in the band. |
| *opt* | An integer value or constant that defines how text is displayed:<br>*flexWordBreak*: Normal word-breaking/wrapping.<br>*flexWordBreakEllipsis*: Wraps text but appends an ellipsis ("...") if the text is still too long for the available space. |

#### Remarks

While other properties like **ColWordWrapOption** target standard data cells, this property ensures header text remains legible in constrained spaces. 

It defines whether and how text in the header cells of a specific column should wrap.

It typically requires a column index to specify which header's wrapping behavior to modify.

Like most `MSHFlexGrid` properties, it is designed to work with hierarchical data structures, ensuring headers at different levels (bands) can have independent wrapping rules. 

To see the effects of this property, the grid's global **WordWrap** property must be set to **True**.

Setting this property does not automatically resize the header row. You must programmatically increase the **RowHeight** of the header row (usually Row 0) to reveal the wrapped lines of text.

It is often paired with alignment properties (like **ColAlignmentHeader**) to ensure the wrapped text is positioned correctly (e.g., centered or top-left) within the expanded header area. 

#### Summary of wrapping properties in MSHFlexGrid

* **ColWordWrapOption**: Standard data cells in a specific column.
* **ColWordWrapOptionBand**: All columns within a specific hierarchical band.
* **ColWordWrapOptionFixed**: Fixed (non-scrolling) columns.
* **ColWordWrapOptionHeader**: Header cells for a specific column.

---

### ColWordWrapOptionFixed

Returns or sets how text wraps or is truncated within the fixed columns (the non-scrolling columns usually located on the far left of the grid).

```
PROPERTY ColWordWrapOptionFixed (BYVAL Index AS LONG) AS WordWrapSettings
PROPERTY ColWordWrapOptionFixed (BYVAL Index AS LONG, BYVAL opt AS WordWrapSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The zero‑based index of the fixed column. A value of –1 applies the setting to all the fixed columns. |
| *opt* | An integer value or constant that defines how text is displayed:<br>*flexWordBreak*: Normal word-breaking/wrapping.<br>*flexWordBreakEllipsis*: Wraps text but appends an ellipsis ("...") if the text is still too long for the available space. |

#### Remarks

The grid's global **WordWrap** property must be set to **True** for this specific property to function.

Enabling wrapping does not automatically grow the row. You must manually set the **RowHeight** for the row containing the text to see the wrapped lines.

This property only has a visible effect on columns whose index is less than the value of the **FixedCols** property. 

Because fixed columns often contain labels, row numbers, or hierarchical indicators, this property is useful when those labels are longer than the available width and would otherwise be clipped.

#### Summary of wrapping properties in MSHFlexGrid

* **ColWordWrapOption**: Standard data cells in a specific column.
* **ColWordWrapOptionBand**: All columns within a specific hierarchical band.
* **ColWordWrapOptionFixed**: Fixed (non-scrolling) columns.
* **ColWordWrapOptionHeader**: Header cells for a specific column.

---

### MouseRow

Returns the zero-based index of the row under the mouse pointer.

```
FUNCTION MouseRow () AS LONG
```

#### Remarks

Unlike the **Row** property (which indicates the selected or active row), **MouseRo** updates as the user moves the mouse, regardless of whether they click.

It translates the mouse's vertical pixel position into a grid row index.

If the mouse is over a fixed header row, **MouseRow** will return the index of that header (e.g., 0 for the first header row).

If the mouse is over a data row, the returned value corresponds to that row’s index.

If the mouse is within the control but below the last populated row, it typically returns -1.

Internally, the control converts the mouse’s vertical pixel coordinate into a row index using its row‑height table. This means the result is always based on the visual layout, not on the underlying Recordset.

#### Common use cases

**Context menus**: Identifying which row to act upon when a user right-clicks.

**Tooltips**: Displaying specific data info or "hints" as a user hovers over different rows.

**Hot-tracking**: Changing the background color or cursor style as the mouse moves over specific data rows.

#### Example: Displaying a value on hover
```
Dim hoverRow As Long = grid.MouseRow
' Ensure the mouse is over a valid data row (not header or empty space)
If hoverRow >= grid.FixedRows Then
   Print "Hovering over: " & grid.TextMatrix(hoverRow, 0)
End If
```
---

### MouseCol

Returns the zero-based index of the column under the mouse pointer.

```
FUNCTION MouseCol () AS LONG
```

#### Remarks

Unlike the **Col** property (which indicates the selected or active column), **MouseCol** tracks the mouse cursor's horizontal position dynamically as it moves across the grid.

It automatically translates the mouse's X-coordinate (horizontal) into the corresponding column index, accounting for current scroll positions and column widths.

If the mouse is over a fixed column (the gray area on the left), **MouseCol** returns the index of that fixed column (e.g., 0).

If the mouse is over a scrollable data column, the returned value corresponds to that column’s index.

If the mouse is within the control's boundaries but to the right of the last column, the property returns -1.

Internally, the control converts the mouse’s horizontal pixel coordinate into a column index, taking into account:

* current horizontal scroll position
* individual column widths
* fixed vs. scrollable column regions

#### Common use cases

**Context-sensitive menus**: Determining which specific data field the user is right-clicking to show relevant options.

**Custom tooltips**: Showing a tooltip with the full text of a cell if the content is too long to be displayed in the current column width.

**Interactive sorting**: Detecting when a user is hovering over a header to highlight it before a click triggers a sort.

#### Example: Example: Identifying a column on right-click
```
Dim targetCol As Long = grid.MouseCol
DIM targetRow As Long = grid.MouseRow
If targetCol <> -1 And targetRow <> -1 Then
   Print "You right-clicked Column: " & STR(targetCol) & " in Row: " & STR(targetRow)
End If
```
---

### MousePointer

Returns or sets the default arrow cursor to different standard system shapes or a custom image. 

```
FUNCTION MousePointer () AS MousePointerSettings
PROPERTY MousePointer (BYVAL settings AS MousePointerSettings)
```

#### Remarks

It provides immediate visual feedback to the user about what kind of interaction is possible (e.g., resizing columns, selecting text, or indicating a wait state).

It allows you to use standard Windows cursors or load a custom icon file (.ico or .cur). 

The cursor may be temporarily overridden by the control during certain operations:

* hovering over column borders (column resizing)
* hovering over row borders (row resizing)
* dragging column headers
*scrolling

After these temporary overrides, the cursor returns to the value specified by MousePointer.

You typically set **MousePointer** using predefined constants:

| Value  | Constant | Description |
| ------ | -------- | ----------- |
| **0** | flexDefault | Uses the standard default cursor (usually an arrow). |
| **1** | flexArrow | An arrow cursor. |
| **2** | flexCross | A crosshair cursor (often used for selection). |
| **3** | flexIBeam | An I-beam cursor (for text input indication). |
| **4** | flexIcon | An icon/thumbnail representation. |
| **5** | flexSize | Double-headed arrow (general resizing). |
| **6** | flexSizeNESW | Double-headed arrow pointing NorthEast/SouthWest. |
| **7** | flexSizeNS | Double-headed arrow pointing North/South (row resizing). |
| **8** | flexSizeNWSE | Double-headed arrow pointing NorthWest/SouthEast. |
| **9** | flexSizeWE | Double-headed arrow pointing West/East (column resizing). |
| **10** | flexUpArrow | A simple upward-pointing arrow. |
| **11** | flexHourglass | A waiting/busy hourglass or spinning circle cursor. |
| **99** | flexCustom | Uses a custom icon specified in the MouseIcon property. |

#### Example usage

To change the cursor to an hourglass when performing a long operation:
```
' Change cursor to hourglass while processing
grid.MousePointer = flexHourglass 
    
' ... run a long database query or data load ...
    
' Reset cursor to default when done
grid.MousePointer = flexDefault 
```

#### Using a custom icon

When using **flexCustom** (Value 99), you must also load an icon file into the **MouseIcon** property at design time or runtime:
```
' Load a custom icon from a file
grid.MouseIcon = LoadPicture("C:\path\to\mycursor.ico")
grid.MousePointer = flexCustom
```

Custom cursors must be .ico or .cur files; animated .ani cursors are not supported.

If the file cannot be loaded, the control silently falls back to *flexDefault*.

The cursor may be overridden temporarily during built‑in interactions (resizing, dragging), but the control restores your chosen cursor afterward.

---

### MouseIcon

Returns or sets a custom image (typically an .ico or .cur file) to the mouse cursor when it is positioned over the grid.

```
FUNCTION MouseIcon () AS IPicture PTR
PROPERTY MouseIcon (BYVAL pic AS IPicture PTR)
```

#### Remarks

To use a custom icon, you must set two properties in tandem: 

* **MousePointer**: Must be set to 99 - *flexCustom*.
* **MouseIcon**: Must be assigned a valid picture object. 

If the file cannot be loaded or is invalid, the control silently falls back to the default cursor.

#### Setting MouseIcon at runtime
```
' Step 1: Set the pointer to custom mode
grid.MousePointer = 99 

' Step 2: Load the specific icon or cursor file
grid.MouseIcon = LoadPicture("C:\Icons\MyCustomCursor.cur")
```
---

### ColHeader

Determines whether column headers are displayed for a specific band in the grid. 

```
PROPERTY ColHeader (BYVAL BandNumber AS LONG) AS ColHeaderSettings
PROPERTY ColHeader (BYVAL BandNumber AS LONG, BYVAL settings AS ColHeaderSettings)
PROPERTY ColHeader () AS ColHeaderSettings
PROPERTY ColHeader (BYVAL settings AS ColHeaderSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band specifies that contains the headers that will show or be hidden. If the band number is omited, band 0 is assumed. |
| *settings* | *flexColHeaderOn*: The headers display for each band.<br>*flexColHeaderOff*: No headers display for the band. |

#### Remarks

If you are not using data-bound bands, headers are created by setting **FixedRows** and assigning text to the first row (Row 0). 

```
' Define Header Row: Set FixedRows = 1 to create a non-scrolling top row.
' Set Header Text: Use the TextMatrix property to assign titles:
grid.FixedRows = 1
grid.TextMatrix(0, 0) = "ID"
grif.TextMatrix(0, 1) = "Name"
```
**Alignment**: Use `ColAlignment(index)` to align data, but note that header text (row 0) sometimes requires separate formatting or manual alignment characters.

#### Data-bound haders

When bound to a Recordset, the `MSHFlexGrid` automatically uses the database field names as headers in Row 0. To change the text of these automatic headers, use SQL Aliases in your query (e.g., `SELECT emp_name AS [Employee Name] FROM...`).

**Redundancy fix**: If setting **ColHeader** to * flexColHeaderOn * creates duplicate headers, you can hide the field-name row by setting `FixedRows = 0` if you only want your custom captions to show. 

**Multiple lines**: To create a multi-line header, increase **FixedRows** (e.g., to 2) and manually populate both rows.

```
grid.FixedRows = 2
grid.TextMatrix(0, 0) = "Employee"
grid.TextMatrix(1, 0) = "ID"
```

**Interactivity**: By default, clicking a header (Fixed Row) does not change the grid's **Row** property (it often defaults to 1); you must use **MouseRow** and **MouseCol** to detect clicks for sorting or selection. 

```
If grid.MouseRow = 0 Then
    ' Header clicked → perform sorting
End If
```
---

### ColHeaderCaption

Specifies the caption to display in the header of the specified column and band.

```
FUNCTION ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS DWSTRING
FUNCTION ColHeaderCaption (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG, BYREF wszCaption AS WSTRING) AS HRESULT
FUNCTION ColHeaderCaption (BYVAL BandColIdx AS LONG) AS DWSTRING
FUNCTION ColHeaderCaption (BYVAL BandColIdx AS LONG, BYREF wszCaption AS WSTRING) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band that contains the specified column to set the caption. If the band number is omited, band 0 is assumed. |
| *BandColIdx* | The index of the column within that band. |
| *wszCaption* | The caption to set. |

#### Remarks

**Overwriting field names**: When bound to a database, the grid defaults to using database field names as headers. **ColHeaderCaption** overwrites these field names with your custom text.

**Redundancy issues**: Sometimes setting **ColHeader** to *flexColHeaderOn* while using **ColHeaderCaption** can result in two headers (the custom one and the original database field name). You may need to adjust **FixedRows** or the **ColHeader** property to hide the unwanted row.

**Read-only situations**: In some specific configurations or older versions, these properties may appear as read-only if the data source is not properly initialized or if certain `Access` database drivers are used.

**Alternative**: For unbound grids, developers often simply use the **TextMatrix** property to set header text at Row 0: `grid.TextMatrix(0, 1, "Caption")`. 

#### Example

To set the header for the first four columns of the first band (Band 0):
```
grid.ColHeaderCaption(0, 0, "Part Code")
grid.ColHeaderCaption(0, 1, "Job Number")
grid.ColHeaderCaption(0, 2, "Scrap")
grid.ColHeaderCaption(0, 3, "Reason")
```
---

### ScrollBars

Returns or sets a value that determines whether an `MSHFlexGrid` has horizontal and/or vertical scroll bars.

```
PROPERTY ScrollBars () AS ScrollBarsSetting
PROPERTY ScrollBars (BYVAL settings AS ScrollBarsSettings)
```
| Parameter  | Description |
| ---------- | ----------- |
| *settings* | An integer or constant that specifies the type of scroll bars. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexResizeNone* | 0 | None. Default. The user cannot resize with the mouse. |
| *flexScrollBarHorizontal* | 1 | Only a horizontal scroll bar is displayed. |
| *flexScrollBarVertical* | 2 | Only a vertical scroll bar is displayed. |
| *flexScrollBarBoth* | 3 | Both horizontal and vertical scroll bars are displayed (Default). |

#### Remarks

Even if set to *flexScrollBarBoth*, a scroll bar only physically appears if the content (total rows or columns) actually exceeds the grid's width or height.

If a scroll bar is set to "None" for a specific direction, the user cannot use the keyboard (arrow keys) to scroll to cells outside the visible area in that direction. 

You can force the grid to scroll to a specific location via code regardless of the **ScrollBars** setting using these properties: 

* **TopRow**: Sets or returns the index of the row displayed at the very top of the grid.
* **LeftCol**: Sets or returns the index of the column displayed at the leftmost side of the grid. 

**Important events**

**Scroll event**: This event fires whenever the grid is scrolled, whether by the user interacting with the scroll bars or by code changing **TopRow** or **LeftCol**.

**Detection workaround**: There is no native "ScrollbarVisible" property. To detect if a scroll bar is currently visible, you can compare the sum of all **RowHeight** values against the control's height.

---

### ScrollTrack

Returns or sets a value that determines whether the `MSHFlexGrid` should scroll its contents while the user moves the scroll box along the scroll bars.

```
PROPERTY ScrollTrack () AS BOOLEAN
PROPERTY ScrollTrack (BYVAL bTrack AS BOOLEAN)
```
| Parameter  | Description |
| ---------- | ----------- |
| *bTrack* | **True** (Default): The grid content scrolls instantaneously as the user drags the scroll box. This provides immediate visual feedback.<br>**False**: The grid content only updates/redraws after the user releases the mouse button. While dragging, the contents remain static even though the scroll box moves. |

#### Interaction with events

The **ScrollTrack** setting directly affects the firing of the **Scroll** event:

If set to **True**, the **Scroll** event fires continuously while the user is dragging the scroll box.

If set to **False**, the **Scroll** event fires only once when the user stops dragging and releases the thumb. 

#### Usage recommendations

**Performance**: If your grid contains a massive amount of data or complex custom drawing logic, setting **ScrollTrack** to False can improve performance by preventing constant redraws during scrolling.

**Real-time feedback**: Use **True** for a modern, responsive feel that matches how applications like Excel typically behave. 

#### Comparison to programmatic scrolling

The **ScrollTrack** property only affects manual scrolling via the scroll bars. Programmatic changes to the view using the **TopRow** or **LeftCol** properties will always redraw the grid immediately, regardless of the **ScrollTrack** setting. 

---

### OLEDropMode

Determines how the grid acts as a "drop target" for OLE drag-and-drop operations, such as dragging files from Windows Explorer or text from another application into the grid. 

```
PROPERTY OLEDropMode () AS OLEDropConstants
PROPERTY OLEDropMode (BYVAL dropMode AS OLEDropConstants)
```
| Parameter  | Description |
| ---------- | ----------- |
| *dropMode* | The property can be set to the following values: |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexOLEDropNone* | 0 | (Default) The control does not accept OLE drops and displays the "No Drop" cursor. |
| *flexOLEDropManual* | 1 | The programmer must handle the drop manually in code using the **OLEDragOver** and **OLEDragDrop** events. |

#### Manual mode (flexOLEDropManual)

This is the most common setting for custom behavior. When set to 1, you must use specific events to process the data:

* **OLEDragOver**: Fires when an object is dragged over the grid. You can use this to change the mouse cursor or highlight the cell under the mouse.
* **OLEDragDrop**: Fires when the user releases the object over the grid. Use the **Data** object (specifically **Data.Files** or **Data.GetData**) to extract the dropped information. 

The grid does not restrict formats; it simply passes the OLE data object to your event handlers.

Common formats include:

* vbCFText — plain text
* vbCFRTF — rich text
* vbCFFiles — file drops
* Custom clipboard formats

#### Hit‑testing

Inside **OLEDragOver** or **OLEDragDrop**, you can use:

* grid.MouseRow
* grid.MouseCol

to determine the target cell.

#### Visual feedback

To give the user a better experience, you can:

* highlight the target row/column
* show a custom cursor
* reject drops by setting Effect = vbDropEffectNone

#### Implementation example

To allow a user to drop a file path into a cell manually:
```
' Check if files were dropped
If Data.GetFormat(vbCFFiles) Then
   ' Drop the first file path into the current cell
   grid.Text = Data.Files(1)
End If
```
---

### OLEDrag

The **OLEDrag** method and **OLEDragMode** property enable the grid to act as a source for OLE drag-and-drop operations, allowing data to be dragged from the grid to other controls or applications

```
FUNCTION OLEDrag () AS HRESULT
```

When using manual mode, you must explicitly call **OLEDrag** to start the process. This triggers the **OLEStartDrag** event, where you define what data is being dragged. 

#### Key Events for Dragging

To fully manage a drag operation from the grid, use these events:

* **OLEStartDrag**: Use this to set the allowed effects (copy, move) and provide the initial data using **Data.SetData**.

* **OLEGiveFeedback**: Occurs after every **OLEDragOver** event in a target; use this to change the mouse cursor or provide visual cues based on the target's response.

* **OLESetData**: If data wasn't provided at the start, this event fires when the target actually requests it.

* **OLECompleteDrag**: Fires when the operation is finished; used to perform cleanup, such as deleting the source text if a "move" was performed.

---

### TextStyle

Returns or sets the three-dimensional style for text within a specific cell or range of cells. 

```
PROPERTY TextStyle () AS TextStyleSettings
PROPERTY TextStyle (BYVAL style AS TextStyleSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *style* | An integer or constant that specifies the text style. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexTextFlat* | 0 | The text is normal, flat text. This is the default. |
| *flexTextRaised* | 1 | The text appears raised. |
| *flexTextInset* | 2 | The text appears inset. |
| *flexTextRaisedLight* | 3 | The text appears slightly raised. |
| *flexTextInsetLight* | 4 | The text appears slightly inset. |

Settings 1 and 2 work best for large and bold fonts. Settings 3 and 4 work best for small, regular fonts.

#### TextStyle vs. TextStyleFixed

The `MSHFlexGrid` provides two separate properties to distinguish between standard data cells and header cells: 

* **TextStyle**: Applies to all non-fixed (regular) cells.
* **TextStyleFixed**: Specifically applies to text in fixed rows and columns (headers). This is often used to make column headers stand out with a raised 3D effect. 

While these 3D effects were common in classic Windows UI, modern design often favors **flexTextFlat** for better readability on high-resolution displays.

Unlike properties like CellFontBold, which can be applied to individual cells, the **TextStyle** property typically affects all cells in the grid or the entire "Fixed" section at once.

#### Example
```
' Make headers appear raised
grid.TextStyleFixed = flexTextRaised 
' Keep regular data flat
grid.TextStyle = flexTextFlat
```
---

### TextStyleFixed

Returns or sets the three-dimensional style for text within fixed rows and columns.

```
PROPERTY TextStyleFixed () AS TextStyleSettings
PROPERTY TextStyleFixed (BYVAL style AS TextStyleSettings)
```

| Parameter  | Description |
| ---------- | ----------- |
| *style* | An integer or constant that specifies the text style. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexTextFlat* | 0 | The text is normal, flat text. This is the default. |
| *flexTextRaised* | 1 | The text appears raised. |
| *flexTextInset* | 2 | The text appears inset. |
| *flexTextRaisedLight* | 3 | The text appears slightly raised. |
| *flexTextInsetLight* | 4 | The text appears slightly inset. |

Settings 1 and 2 work best for large and bold fonts. Settings 3 and 4 work best for small, regular fonts.

#### Distinction from TextStyle

* **TextStyleFixed**: Only affects text in rows and columns defined by the **FixedRows** and **FixedCols** properties.
* **TextStyle**: Affects the text in all standard, scrollable data cells. 

#### Implementation example

To make your column headers appear distinct from the data with a raised effect in VB6:
```
grid.FixedRows = 1
' Apply a 3D raised effect to the header text
grid.TextStyleFixed = flexTextRaised 
' Keep the data cells flat for better readability
grid.TextStyle = flexTextFlat 
```
#### Key limitations

This property applies to all fixed cells in the grid simultaneously. You cannot use it to give different 3D styles to individual header cells.

Interaction with **GridLines**: For a complete 3D look, developers often pair **TextStyleFixed** with the **GridLinesFixed** property (e.g., setting it to *flexGridRaised*). 

---

### TextStyleBand

Returns or sets the three-dimensional style for text within a specific band.

```
PROPERTY TextStyleBand (BYVAL BandNumber AS LONG) AS TextStyleSettings
PROPERTY TextStyleBand (BYVAL BandNumber AS LONG, BYVAL style AS TextStyleSettings) AS HRESULT
PROPERTY TextStyleBand () AS TextStyleSettings
PROPERTY TextStyleBand (BYVAL style AS TextStyleSettings) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose text Style is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *style* | An integer or constant that specifies the text style. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexTextFlat* | 0 | The text is normal, flat text. This is the default. |
| *flexTextRaised* | 1 | The text appears raised. |
| *flexTextInset* | 2 | The text appears inset. |
| *flexTextRaisedLight* | 3 | The text appears slightly raised. |
| *flexTextInsetLight* | 4 | The text appears slightly inset. |

Settings 1 and 2 work best for large and bold fonts. Settings 3 and 4 work best for small, regular fonts.

#### Remarks

The property is applied per band, allowing you to visually distinguish different levels of your data hierarchy (e.g., Parent vs. Child records).

#### Example: To make the text in the first child band (Band 1) appear inset:
```
grid.TextStyleBand(1) = flexTextInset
```
This property is most useful when the grid is bound to an ADO Hierarchical Recordset created using the `SHAPE` command. In such a grid, you can use **TextStyleBand** to make nested levels of data visually stand out, which is often difficult to achieve with standard flat grids. Note that if the grid is not bound to a hierarchical data source, only Band 0 exists.

#### Key distinctions

* **TextStyleBand**: Applies 3D effects to the data cells belonging to a specific band.
* **TextStyleHeader**: Applies 3D effects to the headers of a specific band.
* **TextStyleFixed**: Applies to the main fixed rows/columns of the grid overall, regardless of bands.
* **TextStyle**: Applies to all standard cells in the grid if not specifically overridden by band-specific settings.

---

### TextStyleHeader

Returns or sets the three-dimensional style for text withinthe column headers of a specific band.

```
PROPERTY TextStyleHeader (BYVAL BandNumber AS LONG) AS TextStyleSettings
PROPERTY TextStyleHeader (BYVAL BandNumber AS LONG, BYVAL style AS TextStyleSettings) AS HRESULT
PROPERTY TextStyleHeader () AS TextStyleSettings
PROPERTY TextStyleHeader (BYVAL style AS TextStyleSettings) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose text Style is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *style* | An integer or constant that specifies the text style. |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexTextFlat* | 0 | The text is normal, flat text. This is the default. |
| *flexTextRaised* | 1 | The text appears raised. |
| *flexTextInset* | 2 | The text appears inset. |
| *flexTextRaisedLight* | 3 | The text appears slightly raised. |
| *flexTextInsetLight* | 4 | The text appears slightly inset. |

Settings 1 and 2 work best for large and bold fonts. Settings 3 and 4 work best for small, regular fonts.

#### Example

To make the headers for the primary data level (Band 0) appear raised:
```
grid.TextStyleHeader(0) = flexTextRaised
```

#### Key differences from other style properties

* **TextStyleHeader**: Specifically targets the headers for a chosen band.
* **TextStyleBand**: Applies 3D effects to the data cells within that specific band.
* **TextStyleFixed**: Applies globally to all fixed rows and columns (general grid headers), regardless of the band structure.
* **TextStyle**: Applies to all standard, non-fixed data cells throughout the grid. 

This property is most effective when working with Hierarchical Recordsets (using the `SHAPE` command). In these setups, each band has its own set of column headers.

---
 
### CellType

Returns the type of the current, active, cell of the `MSHFlexGrid`.

```
PROPERTY CellType () AS CellTypeSettings
```
#### CellTypeSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexCellTypeStandard* | 0 | Default. The cell is a standard cell. |
| *flexCellTypeFixed* | 1 | The cell is contained in a fixed row or column. |
| *flexCellTypeHeader* | 2 | The cell is a header cell for a band of data. |
| *flexCellTypeIndent* | 3 | The cell is used in a column that indents a band of data. |
| *flexCellTypeUnpopulated* | 4 | The cell is an unpopulated cell. |

#### Practical usage

* **Conditional formatting**: You can use **CellType** to apply specific styles (like background colors or fonts) only to header cells or indentation cells, ensuring they remain distinct from standard data cells.
* **Identifying data levels**: When using hierarchical data (e.g., parent and child records), **CellType** helps you determine if the user has clicked on a data row or a band header, which is essential for custom sorting or expanding/collapsing logic.
* **Selection logic**: By checking **CellType**, you can prevent users from attempting to "edit" or perform actions on indentation or header cells that should remain read-only.

---

### CellHeight

Returns the height of the currently selected cell in twips. 

```
PROPERTY CellHeight () AS LONG
```

#### Key characteristics

* **Read-only**: Unlike the **RowHeight** property, **CellHeight** is read-only. You use it to retrieve the current height rather than setting it.
* **Selection-based**: It always refers to the cell located at the current **Row** and **Col** position.
* **Automatic view**: Accessing this property ensures the cell is scrolled into the visible area of the grid if it isn't already. 

#### Common use cases

* **Positioning controls**: It is frequently used to overlay other controls, such as a **TextBox** or **ComboBox**, exactly over a specific cell to make it appear editable.
* **Calculating grid dimensions**: It helps in calculating the total height of the grid based on the number of rows to avoid unnecessary scrollbars.

#### Adjusting height for wordWrap

If you need a cell to grow to fit multi-line text, you cannot use **CellHeight**. Instead, you must set the **WordWrap** property to **True** and manually increase the corresponding **RowHeight** using a loop or API calls. 

---

### CellWidth

Returns the width of the currently selected cell in twips.

```
PROPERTY CellWidth () AS LONG
```

#### Key characteristics

* **Read-only**: You cannot set the width using this property. To change the width of a column, you must use the **ColWidth** property (e.g., `grid.ColWidth(1) = 1500`).
* **Selection-based**: It always refers to the cell located at the current **Row** and **Col** position.
* **Visibility**: Accessing **CellWidth** will automatically scroll the grid to ensure the current cell is visible within the control's viewport.

#### Overlaying controls

The primary use for **CellWidth** is for floating editors. Since the `MSHFlexGrid` does not have a native "edit mode," developers overlay a **TextBox** or **ComboBox** on top of the cell.

If a column is hidden (set to `ColWidth = 0`), the **CellWidth** property will return 0 when that column is selected. To ensure a professional UI, always check if `CellWidth > 0` before attempting to position floating UI elements over a cell.

---

### CellLeft

Returns the distance between the left edge of the grid control and the left edge of the currently selected cell, measured in twips. 

```
PROPERTY CellLeft () AS LONG
```

#### Key functionality

* **Read-only**: You cannot set the position of a cell using this property; it only reports the current location.
* **Selection-based**: It always refers to the cell determined by the current **Row** and **Col** properties.
* **Auto-scroll**: Accessing **CellLeft** automatically scrolls the grid to bring the selected cell into the visible viewport if it is not already there.
* **Coordinate system**: The value is relative to the top-left corner of the `MSHFlexGrid` control, not the form. 

#### Primary use case: In-cell editing

Because `MSHFlexGrid` is primarily a display control, developers use **CellLeft** (along with **CellTop**, **CellWidth**, and **CellHeight**) to position a "floating" **TextBox** or **ComboBox** over a cell to simulate an editable environment. 

---

### CellTop

Returns the distance from the top edge of the control to the top edge of the currently selected cell, measured in twips. 

```
PROPERTY CellTop () AS LONG
```

#### Key characteristics

* **Read-only**: You cannot manually set this property. It is used to retrieve the vertical position of the active cell (defined by the **Row** and **Col** properties).
* **Auto-scrolling**: Simply accessing the **CellTop** property in your code automatically scrolls the grid to bring the selected cell into the visible viewport if it is currently hidden.
* **Coordinate context**: The value is relative to the top of the `MSHFlexGrid` control itself, not the entire form. 

#### Primary use: Floating editors

The most common application for **CellTop** is positioning a "floating" input control—like a **TextBox** or **ComboBox**—directly over a grid cell to simulate an editable cell.

---

### CellBackColor

Returns or sets the background color of the currently active cell or a selected range of cells. 

```
PROPERTY CellBackColor () AS OLE_COLOR
PROPERTY CellBackColor (BYVAL bkColor AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bkColor* | A numeric expression that specifies the color for the current cell selection. Setting this property to zero paints the cell using the standard background color. |


The property affects the cell(s) determined by the current **Row** and **Col** properties. 

Set for Single Cell:
```
grid.Row = 2 ' Target row
grid.Col = 1 ' Target column
grid.CellBackColor = vbRed ' Set color to red
```

Set for a Range: To color multiple cells at once, set the **FillStyle** property to **flexFillRepeat**.
```
grid.FillStyle = flexFillRepeat
grid.Row = 1: grid.Col = 1
grid.RowSel = 3: grid.ColSel = 3
grid.CellBackColor = vbBlue
grid.FillStyle = flexFillSingle ' Reset to single-cell mode
```

#### Key Behaviors

* **Difference from BackColor**: The **BackColor** property sets the default background for all non-fixed cells. **CellBackColor** overrides this global setting for individual cells.
* **Black color workaround**: Setting **CellBackColor** to 0 (the value for *vbBlack*) tells the grid to use its "standard" background color. To explicitly color a cell black, use a near-black value such as 1 or BGR(1, 1, 1).
* **Read-only defaults**: If you check **CellBackColor** for a cell that has not been specifically colored, it may return 0, meaning it is using the default **BackColor** of the grid.

#### Hierarchical grid colors

Since the `MSHFlexGrid` supports bands, it also provides specialized properties for larger areas of the grid: 

* **BackColorBand**: Background for specific data bands.
* **BackColorHeader**: Background for band headers.
* **BackColorIndent**: Background for indented column areas.
* **BackColorUnpopulated**: Background for empty areas of the grid.

---

### CellForeColor

Returns or sets the the text color (foreground color) of the currently active cell or a selected range of cells. 

```
PROPERTY CellForeColor () AS OLE_COLOR
PROPERTY CellForeColor (BYVAL clr AS OLE_COLOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | A numeric expression that specifies the color for the current cell selection. Setting this property to zero paints the cell using the standard foreground color. |

Set for a single cell:
```
grid.Row = 1
grid.Col = 2
grid.CellForeColor = vbBlue ' Changes text in cell (1, 2) to blue
```

Set for a range: To change the text color for multiple cells at once, use the **FillStyle** property to avoid looping through every individual cell.
```
grid.FillStyle = flexFillRepeat ' Apply changes to all cells in selection
grid.Row = 1: grid.Col = 1
grid.RowSel = 5: grid.ColSel = 5
grid.CellForeColor = vbRed
grid.FillStyle = flexFillSingle ' Reset to default single-cell behavior
```

#### Key Behaviors

* **Override global settings:: The **ForeColor** property sets the default text color for all non-fixed cells in the grid. **CellForeColor** overrides this global setting for specific cells.
* **The black color issue**: Setting **CellForeColor** to 0 (the value for *vbBlack*) often causes the grid to revert to its standard default color instead of forcing black. To explicitly set a cell's text to black, use the value 1 or BGR(1, 1, 1).
* **Hierarchical specifics**: Because the `MSHFlexGrid` supports bands, you can also use global properties like **ForeColorBand** or **ForeColorHeader** to set text colors for entire data levels or band headers respectively. 

#### Implementation tips

* **Performance**: When changing colors in a large loop, set the grid's **Redraw** property to **False** before the loop and True after it to prevent flickering and improve speed.
* **Visibility**: Ensure high contrast between **CellForeColor** and **CellBackColor**. For example, avoid black text on a dark red background to maintain readability on modern high-resolution displays. 

---

### CellAlignment

Returns or sets the horizontal and vertical alignment of text within the currently selected cell or range of cells.

```
PROPERTY CellAlignment () AS SHORT
PROPERTY CellAlignment (BYVAL nAlignment AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nALignment* | An integer or constant that specifies how text should be aligned within the current cell. |

#### AlignmentSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | The cell content is aligned left, top. |
| *flexAlignLeftCenter* | 1 | Default for strings. The cell content is aligned left, center. |
| *flexAlignLeftBottom* | 2 | The cell content is aligned left, bottom. |
| *flexAlignCenterTop* | 3 | The cell content is aligned center, top. |
| *flexAlignCenterCenter* | 4 | The cell content is aligned center, center. |
| *flexAlignCenterBottom* | 5 | The cell content is aligned center, bottom. |
| *flexAlignRightTop* | 6 | The cell content is aligned right, top. |
| *flexAlignRightCenter* | 7 | Default for numbers. The cell content is aligned right, center. |
| *flexAlignRightBottom* | 8 | The cell content is aligned right, bottom. |
| *flexAlignGeneral* | 9 | The cell content is of general alignment. This is "left, center" for strings and "right, center" for numbers. |

#### Individual cell vs. range

**Single cell**: By default, setting **CellAlignment** only affects the cell at the current **Row** and **Col**.

**Range of cells**: To align multiple cells simultaneously, set the *FillStyle* property to *flexFillRepeat* before applying the alignment.
```
grid.FillStyle = flexFillRepeat
grid.Row = 1: grid.Col = 1     ' Start of range
grid.RowSel = 5: grid.ColSel = 5 ' End of range
grid.CellAlignment = flexAlignCenterCenter
grid.FillStyle = flexFillSingle ' Reset to default
```
#### Related alignment properties

While **CellAlignment** is for specific cells, other properties handle broader areas: 

* **ColAlignment(index)**: Sets the alignment for an entire column, including headers. Use an index of -1 to align all columns at once.
* **FixedAlignment(index)**: Specifically sets the alignment for fixed rows (headers) in a given column.
* **ColAlignmentBand / ColAlignmentHeader**: Used for specific bands in hierarchical data structures. 

---

### CellTextStyle

Returns or sets the three-dimensional style for text in a specific cell or range of cells.

```
PROPERTY CellTextStyle () AS TextStyleSettings
PROPERTY CellTextStyle (BYVAL style AS TextStyleSettings)
```
| Parameter  | Description |
| ---------- | ----------- |
| *style* | An integer or constant that specifies the text style of the current cell. |

#### TextStyleSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexTextFlat* | 0 | Default. The text is normal, flat text. |
| *flexTextRaised* | 1 | The text appears raised. |
| *flexTextInset* | 2 | The text appears inset. |
| *flexTextRaisedLight* | 3 | The text appears slightly raised. |
| *flexTextInsetLight* | 4 | The text appears slightly inset. |

#### Syntax and scope

The property applies to the current active cell defined by the **Row** and **Col** properties. 

* **Single cell**: By default, changing this property only affects the active cell.
* **Range of cells**: If the **FillStyle** property is set to *flexFillRepeat*, changing **CellTextStyle** will apply the style to all cells in the current selection. 

#### Usage recommendations

* **Font pairing**: The *flexTextRaised* and *flexTextInset* styles typically look best when applied to large or bold fonts.
* **Subtle styles**: For smaller, regular fonts, the "Light" versions (*flexTextRaisedLight* or *flexTextInsetLight*) are generally preferred for better readability. 

#### Comparison with other style properties

While **CellTextStyle** is used for individual data cells, other properties handle broader areas:

* **TextStyle**: Sets the default style for all non-fixed cells in the grid.
* **TextStyleFixed**: Specifically targets the text style for all fixed (header) rows and columns.
* **TextStyleBand**: Defines the style for all cells within a specific hierarchical band.
* **TextStyleHeader**: Defines the style for headers of a specific hierarchical band.

---

### CellPictureAlignment

Returns or sets the alignment of pictures in a cell or range of selected cells.

```
PROPERTY CellPictureAlignment () AS SHORT
PROPERTY CellPictureAlignment (BYVAL nAlignment AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nAlignment* | An integer or constant that specifies how pictures should be aligned within cells. |

#### AlignmentSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | The picture is aligned left, top. |
| *flexAlignLeftCenter* | 1 | The picture is aligned left, center. |
| *flexAlignLeftBottom* | 2 | The picture is aligned left, bottom. |
| *flexAlignCenterTop* | 3 | The picture is aligned center, top. |
| *flexAlignCenterCenter* | 4 | The picture is aligned center, center. |
| *flexAlignCenterBottom* | 5 | The picture is aligned center, bottom. |
| *flexAlignRightTop* | 6 | The picture is aligned right, top. |
| *flexAlignRightCenter* | 7 | The picture is aligned right, center. |
| *flexAlignRightBottom* | 8 | The picture is aligned right, bottom. |

#### Basic implementation

To align a picture in a single cell, set the Row and Col properties first:
```
grid.Row = 1
grid.Col = 1
grid.CellPicture = LoadPicture("C:\path\to\image.bmp")
' Center the picture in the cell
grid.CellPictureAlignment = flexAlignCenterCenter 
```
 
#### Range alignment (multiple cells)

To apply the same picture alignment to a block of cells simultaneously, use the **FillStyle** property:

* Set FillStyle = flexFillRepeat.
* Define the range using Row, Col, RowSel, and ColSel.
* Set the CellPictureAlignment property.
* Reset FillStyle = flexFillSingle to prevent accidental global changes. 

```
grid.FillStyle = flexFillRepeat
grid.Row = 1 : grid.Col = 1
grid.RowSel = 5 : grid.ColSel = 5
grid.CellPictureAlignment = flexAlignCenterCenter
grid.FillStyle = flexFillSingle
```

**Checkbox alignment**: This property is often used to center custom checkbox images within a cell to simulate a boolean field.

**Text Interaction**: This property only affects the picture. To align text within the same cell, you must use the separate **CellAlignment** property.

**Automatic scrolling**: Accessing cell positioning properties often forces the grid to scroll the targeted cell into view. 

---

### ColAlignment

Returns or sets the alignment of data in a column.

```
PROPERTY ColAlignment (BYVAL Index AS LONG) AS SHORT
PROPERTY ColAlignment (BYVAL Index AS LONG, BYVAL nAlignment AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The number of the column. |
| *nAlignment* | An integer or constant that specifies the alignment of data in a column. |

#### AlignmentSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | The cell content is aligned left, top. |
| *flexAlignLeftCenter* | 1 | Default for strings. The cell content is aligned left, center. |
| *flexAlignLeftBottom* | 2 | The cell content is aligned left, bottom. |
| *flexAlignCenterTop* | 3 | The cell content is aligned center, top. |
| *flexAlignCenterCenter* | 4 | The cell content is aligned center, center. |
| *flexAlignCenterBottom* | 5 | The cell content is aligned center, bottom. |
| *flexAlignRightTop* | 6 | The cell content is aligned right, top. |
| *flexAlignRightCenter* | 7 | Default for numbers. The cell content is aligned right, center. |
| *flexAlignRightBottom* | 8 | The cell content is aligned right, bottom. |
| *flexAlignGeneral* | 9 | The cell content is of general alignment. This is "left, center" for strings and "right, center" for numbers. |

#### Remarks

Any column can have an alignment that is different from other columns. The **ColAlignment** property affects all cells in the specified column, including those in fixed rows.

---

### ColAlignmentFixed

Returns or sets the alignment of data within the fixed columns of the grid.

```
PROPERTY ColAlignmentFixed (BYVAL Index AS LONG) AS SHORT
PROPERTY ColAlignmentFixed (BYVAL Index AS LONG, BYVAL nAlignment AS SHORT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *Index* | The number of the column. |
| *nAlignment* | An integer or constant that specifies the alignment of data in a column. |

#### AlignmentSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | The cell content is aligned left, top. |
| *flexAlignLeftCenter* | 1 | Default for strings. The cell content is aligned left, center. |
| *flexAlignLeftBottom* | 2 | The cell content is aligned left, bottom. |
| *flexAlignCenterTop* | 3 | The cell content is aligned center, top. |
| *flexAlignCenterCenter* | 4 | The cell content is aligned center, center. |
| *flexAlignCenterBottom* | 5 | The cell content is aligned center, bottom. |
| *flexAlignRightTop* | 6 | The cell content is aligned right, top. |
| *flexAlignRightCenter* | 7 | Default for numbers. The cell content is aligned right, center. |
| *flexAlignRightBottom* | 8 | The cell content is aligned right, bottom. |


#### Remarks

Any column can have an alignment that is different from other columns. The **ColAlignment** property affects all cells in the specified column, including those in fixed rows.

---

### ColAlignmentBand

Returns or sets the alignment of data within a specific column of a hierarchical band.

```
FUNCTION ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS SHORT
FUNCTION ColAlignmentBand (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
FUNCTION ColAlignmentBand (BYVAL BandColIdx AS LONG) AS SHORT
FUNCTION ColAlignmentBand (BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose data alignment is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *Index* | The number of the column. |
| *nAlignment* | An integer or constant that specifies the alignment of data in a column. |

#### AlignmentSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | The cell content is aligned left, top. |
| *flexAlignLeftCenter* | 1 | Default for strings. The cell content is aligned left, center. |
| *flexAlignLeftBottom* | 2 | The cell content is aligned left, bottom. |
| *flexAlignCenterTop* | 3 | The cell content is aligned center, top. |
| *flexAlignCenterCenter* | 4 | The cell content is aligned center, center. |
| *flexAlignCenterBottom* | 5 | The cell content is aligned center, bottom. |
| *flexAlignRightTop* | 6 | The cell content is aligned right, top. |
| *flexAlignRightCenter* | 7 | Default for numbers. The cell content is aligned right, center. |
| *flexAlignRightBottom* | 8 | The cell content is aligned right, bottom. |
| *flexAlignGeneral* | 9 | The cell content is of general alignment. This is "left, center" for strings and "right, center" for numbers. |

#### Remarks

While the standard **ColAlignment** property affects an entire column across the whole grid, **ColAlignmentBand** allows for granular control over how data is positioned in nested data levels (bands) created from hierarchical ADO recordsets. 

This property is used in applications that use complex, multi-level data displays. It specifically targets the data cells within a band. To align the headers for that same band, you must use the companion property: ColAlignmentHeader. Settings made with **ColAlignmentBand** will generally take precedence over the more global **ColAlignment** property for those specific band members.

#### Example
```
' Center-align the 2nd column of the first child band (Band 1)
grid.ColAlignmentBand(1, 1) = flexAlignCenterCenter
```
---

### ColAlignmentHeader

Returns or sets the alignment of data within the column headers of a specific band.

```
FUNCTION ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG) AS SHORT
FUNCTION ColAlignmentHeader (BYVAL BandNumber AS LONG, BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
FUNCTION ColAlignmentHeader (BYVAL BandColIdx AS LONG) AS SHORT
FUNCTION ColAlignmentHeader (BYVAL BandColIdx AS LONG = -1, BYVAL nAlignment AS SHORT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | A zero‑based index identifying the band whose data alignment is being retrieved or modified. If the band number is omited, band 0 is assumed. |
| *Index* | The number of the column. |
| *nAlignment* | An integer or constant that specifies the alignment of data in a column. |

#### AlignmentSettings enumeration

| Constant | Value | Description |
| -------- | ----- | ----------- |
| *flexAlignLeftTop* | 0 | The cell content is aligned left, top. |
| *flexAlignLeftCenter* | 1 | Default for strings. The cell content is aligned left, center. |
| *flexAlignLeftBottom* | 2 | The cell content is aligned left, bottom. |
| *flexAlignCenterTop* | 3 | The cell content is aligned center, top. |
| *flexAlignCenterCenter* | 4 | The cell content is aligned center, center. |
| *flexAlignCenterBottom* | 5 | The cell content is aligned center, bottom. |
| *flexAlignRightTop* | 6 | The cell content is aligned right, top. |
| *flexAlignRightCenter* | 7 | Default for numbers. The cell content is aligned right, center. |
| *flexAlignRightBottom* | 8 | The cell content is aligned right, bottom. |
| *flexAlignGeneral* | 9 | The cell content is of general alignment. This is "left, center" for strings and "right, center" for numbers. |

#### Remarks

Setting **ColAlignmentHeader** overrides more global settings like **ColAlignment** specifically for that header cell.

Use **ColAlignmentBand** to set the alignment for the data cells within the same band, as **ColAlignmentHeader** only affects the header labels.

#### Example
```
' Center-align the header for the 4th column of the primary band (Band 0)
grid.ColAlignmentHeader(0, 3) = flexAlignCenterCenter
```
---

### Font

Returns or sets the default font, or the font for individual cells.

```
PROPERTY Font () AS IFont PTR
PROPERTY Font (BYVAL pFont AS IFont PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pFont* | Pointer to an **IFont** inerface. |

#### Remarks

Changing font size does not always automatically resize the row. You may need to manually adjust the **RowHeight** property if the text becomes clipped.

Use **FontBand** or **FontHeader** to set fonts for specific bands in hierarchical data structures.

In modern Windows environments, ensure your selected font is a standard TrueType font to maintain consistent scaling on high-resolution displays.

---

### FontName

Returns or sets the name of the default font.

```
PROPERTY FontName () AS DWSTRING
PROPERTY FontName (BYREF wszFont AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFont* | The font name. |

---

### FontSize

Returns or sets the size of the default font.

```
PROPERTY FontSize () AS SINGLE
PROPERTY FontSize (BYVAL nSize AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nSize* | The font size. |

---

### FontBold

Returns or sets the bold attribute of the default font.

```
PROPERTY FontBold () AS BOOLEAN
PROPERTY FontBold (BYVAL bBold AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bBold* | True to set the attribute; False, othewise |

---

### FontItalic

Returns or sets the italic attribute of the default font.

```
PROPERTY FontItalic () AS BOOLEAN
PROPERTY FontItalic (BYVAL bItalic AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bItalic* | True to set the attribue; False, othewise |

---

### FontStrikethru

Returns or sets the strike through attribute of the default font.

```
PROPERTY FontStrikethru () AS BOOLEAN
PROPERTY FontStrikethru (BYVAL bStrikeThrough AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bStrikeThrough* | True to set the attribute; False, othewise |

---

### FontStrikeThrough

Returns or sets the strike through attribute of the default font.

```
PROPERTY FontStrikeThrough () AS BOOLEAN
PROPERTY FontStrikeThrough (BYVAL bStrikeThrough AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bStrikeThrough* | True to set the attribute; False, othewise |

---

### FontUnderline

Returns or sets the underline attribute of the default font.

```
PROPERTY FontUnderline () AS BOOLEAN
PROPERTY FontUnderline (BYVAL bUnderline AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bUnderline* | True to set the attribute; False, othewise |

---

### RightToLeft

Returns or sets the rigth to left attribute of the default font.

```
PROPERTY RightToLeft () AS BOOLEAN
PROPERTY RightToLeft (BYVAL bRightToLeft AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bRightToLeft* | True to set the attribute; False, othewise |

#### Remarks

This property is used to support bidirectional (BiDi) systems, such as those used for Arabic or Hebrew languages. It primarily adjusts the visual layout and text flow of the control to match these languages. 

 Setting this property to **True** modifies the control's behavior. Typical changes include:

* Placing vertical scroll bars on the left side of the grid.
* Aligning text and headers to begin from the right.

For simply right-justifying text in a standard English layout, developers should use the **ColAlignment** or **CellAlignment** properties (e.g., *flexAlignRightCenter*) rather than the **RightToLeft** property.
 
---

### FontWidth

Returns or sets the width, in points, of the font to be used for text displayed within the grid.

```
PROPERTY FontWidth () AS SINGLE
PROPERTY FontWidth (BYVAL nWidth AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | The font width, in points. |

#### Remarks

This property is relatively rare in standard UI development as it forces a specific horizontal stretch or compression on characters, separate from their vertical height. 

#### Difference from FontSize

While both affect character dimensions, they serve different purposes:
* **FontSize**: Controls the overall scale of the character, primarily its vertical height.
* **FontWidth**: Specifically controls the horizontal "fatness" or "narrowness" of characters. Increasing this value makes text appear wider without increasing its height. 

#### Practical usage tips

* **Grid fitting**: **FontWidth** is occasionally used to squeeze longer strings into a fixed **ColWidth** without resorting to a smaller, less readable **FontSize**.
* **Visual distinction**: It can be used to distinguish different levels of a hierarchical display (e.g., child bands having slightly narrower text than parent bands).
* **Clipping risks**: Increasing the **FontWidth** without manually increasing the **ColWidth** will cause text to be clipped, as the grid does not automatically expand columns to accommodate wider fonts. 

#### Implementation example

To make the first child band (Band 1) appear slightly more condensed than the rest of the grid:
```
' Standard font width for the grid
grid.FontWidth = 0 ' 0 usually defaults to the standard width for the current point size

' Narrower font width for child records in Band 1
grid.FontWidthBand(1) = 6 
```
---

### FontFixed

Returns or sets a Font object used to display text in all fixed rows and fixed columns (the non-scrolling headers).

```
PROPERTY FontFixed () AS IFont PTR
PROPERTY FontFixed (BYVAL pFont AS IFont PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pFont* | A pointer to an **IFont** object. |

#### Remarks

While the standard **Font** property controls the appearance of data in the scrollable area, **FontFixed** allows you to apply a distinct visual style to the headers. This is a "global" property for the fixed section; it applies to all fixed cells simultaneously.

#### Available properties

Since **FontFixed** is a standard **Font** object, you can modify any of its attributes:

* **FontFixed->Name**: Sets the typeface (e.g., "Arial").
* **FontFixed->Size**: Sets the text size in points.
* **FontFixed->Bold**: A Boolean to make headers bold.
* **FontFixed->Italic / Underline / Strikethrough**: Standard style toggles.

#### Usage example

To make your grid headers stand out from the data:
```
' Ensure there is at least one fixed row
grid.FixedRows = 1

' Set header font properties
grid.FontFixed->Name = "Segoe UI"
grid.FontFixed->Size = 10
grid.FontFixed->Bold = True
    
' Set standard data font for contrast
grid.Font->Name = "Tahoma"
grid.Font->Size = 9
grid.Font->Bold = False
```

When maintaining legacy apps on modern Windows versions, using `FontFixed.Bold = True` is the most common way to ensure headers remain distinguishable on high-DPI displays. However, remember that bolding text often makes it wider; you may need to manually increase the **ColWidth** or **RowHeight** of the fixed cells to prevent the text from being cut off.

---

### FontWidthFixed

Returns or sets the width, in points, of the font to be used for all fixed rows and fixed columns (the non-scrolling headers).

```
PROPERTY FontWidthFixed () AS SINGLE
PROPERTY FontWidthFixed (BYVAL nWidth AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | The width of the font, in points. A value of 0 typically resets the font to its standard natural width for the current point size. |

#### Remarks

Unlike **FontSize**, which scales the whole character, **FontWidthFixed** specifically controls the horizontal stretch or compression of characters. Increasing this value makes header text appear wider without making it taller. 

If you increase the **FontWidthFixed** value significantly, you must manually adjust the **ColWidth** of your fixed columns. The `MSHFlexGrid` does not automatically expand the column width to prevent wider characters from being clipped. 

#### Example
```
grid.FixedRows = 1
' Compress the header font slightly to fit more text
grid.FontWidthFixed = 6 
' For contrast, keep data cells at standard width
grid.FontWidth = 0 
```
---

### FontBand

Returns or sets a Font object used for data cells within a specific hierarchical band.

```
PROPERTY FontBand (BYVAL BandNumber AS LONG) AS IFont PTR
PROPERTY FontBand (BYVAL BandNumber AS LONG, BYVAL pFont AS IFont PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pFont* | A pointer to an **IFont** object. |

#### Remarks

Since the `MSHFlexGrid` is designed to display parent-child relationships (hierarchies), this property allows you to visually distinguish different levels of data by applying unique fonts to each level.

This property is index-based, where the index corresponds to the band level (Band 0 is the top-level or primary data).

Because it returns a **Font** object, you can modify specific attributes:
```
grid.FontBand(1)->Name = "Verdana"
grid.FontBand(1)->Bold = True
grid.FontBand(1)->Size = 9
```

#### Difference from FontHeader

It is important to distinguish where the font is being applied:

* **FontBand(index)**: Affects the data cells (rows) belonging to that specific hierarchical level.
* **FontHeader(index)**: Affects the column headers for that specific hierarchical level.

This property is primarily used when the grid is bound to an ADO Hierarchical Recordset (created via the SQL SHAPE command).
V
You can make child records (Band 1) appear in a smaller or italicized font to clearly show they are "sub-items" of the parent record (Band 0).

If a specific font is not set for a band, it typically inherits the grid's global **Font** property.

#### Implementation example

To make child records in the second level of the hierarchy appear distinct:
```
' Set the primary data (Band 0) to standard font
grid.FontBand(0).Name = "Arial"
grid.FontBand(0).Size = 10
    
' Set the child data (Band 1) to be smaller and italicized
grid.FontBand(1).Name = "Arial"
grid.FontBand(1).Size = 8
grid.FontBand(1).Italic = True
```

#### Important note on resizing

As with most `MSHFlexGrid` font properties, changing the font via **FontBand** does not automatically trigger a recalculation of **RowHeight**. If you increase the font size for a specific band, you must manually adjust the **RowHeight** for the rows in that band to prevent the text from being cut off.

---

### FontWidthBand

Returns or sets the width of the font for the data cells within a specific hierarchical band. 

```
PROPERTY FontWidthBand (BYVAL BandNumber AS LONG) AS SINGLE
PROPERTY FontWidthBand (BYVAL BandNumber AS LONG, BYVAL nWidth AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The index of the hierarchical band (e.g., 0 for the parent, 1 for the first child). |
| *nWidth* | The width of the font, in points. A value of 0 typically resets the font to its standard natural width for the current point size. |

#### Remarks

While standard font properties apply to the entire grid, **FontWidthBand** provides granular control over the horizontal scale of characters for specific nested levels in hierarchical data displays. 

It is most commonly used in legacy to make nested child records appear more condensed or visually distinct from their parent records.

Like other font properties, changing the **FontWidthBand** does not automatically resize columns. If the font width is increased, you must manually adjust the **ColWidth** for that band to avoid text clipping.

This property is only effective when the grid is bound to a hierarchical data source (e.g., an ADO recordset created via the `SHAPE` command). If the grid is used in unbound mode, typically only Band 0 exists. 

---


### FontHeader

Returns or sets a Font object used specifically for the column headers of a particular hierarchical band.

```
PROPERTY FontHeader (BYVAL BandNumber AS LONG) AS IFont PTR
PROPERTY FontHeader (BYVAL BandNumber AS LONG, BYVAL pFont AS IFont PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pFont* | A pointer to an **IFont** object. |

#### Remarks

This property allows for level-specific font customization in hierarchical data displays (e.g., distinguishing parent headers from child headers).

It affects only the header cells for the specified band index (starting at 0 for the top-level band). 

Because **FontHeader** returns a standard **Font** object, you can modify its specific attributes directly in code: 
```
grid.FontHeader(0)->Name = "Arial"
grid.FontHeader(0)->Size = 10
grid.FontHeader(0)->Bold = True
```
This property is only relevant when the grid is bound to a Hierarchical Recordset (using the `SHAPE` command). If the grid is used in a standard "flat" mode, only Band 0 exists.

In modern maintenance of legacy apps, **FontHeader** is often used to make nested child headers appear in a smaller or italicized font to improve visual clarity of the data hierarchy.

Note that changing font attributes via FontHeader does not automatically resize the row or column; you may need to manually update **RowHeight** or **ColWidth** to prevent text clipping. 

---

### FontWidthHeader

Returns or sets the width of the font used in the column headers for a specific hierarchical band. 

```
PROPERTY FontWidthHeader (BYVAL BandNumber AS LONG) AS SINGLE
PROPERTY FontWidthHeader (BYVAL BandNumber AS LONG, BYVAL nWidth AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *BandNumber* | The index of the hierarchical band (starting at 0 for the top level). |
| *nWidth* | The width of the font, in points. A value of 0 typically resets the font to its standard natural width for the current point size. |

#### Remarks

This property is only functional when the grid is bound to a Hierarchical Recordset (using the ADO `SHAPE` command). In unbound mode, only Band 0 is typically available.

In modern maintenance of legacy apps, this property is often used to horizontally compress long header text into narrow columns without reducing the font's vertical height.

Changing the **FontWidthHeader** does not automatically resize the column. If you increase the font width, you must manually adjust the **ColWidth** for that band to prevent text clipping. 

#### Example
```
' Standard header font for the main band
grid.FontWidthHeader(0) = 0 

' Squeeze child headers in Band 1 to fit smaller columns
grid.FontWidthHeader(1) = 6
```
---

### CellFontName

Returns or sets the typeface (font name) for the currently active cell or a selected range of cells.

```
PROPERTY CellFontName () AS DWSTRING
PROPERTY CellFontName (BYREF wszFontName AS WSTRING)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFontName* | The font name. |

#### Remarks

This property affects the cell(s) specified by the current **Row** and **Col** properties.

* **Set single cell**: grid.CellFontName = "Arial"
* **Read value**: strFont = grid.CellFontName

To change the font name for multiple cells simultaneously without a loop, you must utilize the **FillStyle** property:

Set grid.FillStyle = flexFillRepeat (Value 1).
Select the range using the Row, Col, RowSel, and ColSel properties.
Assign the new font: grid.CellFontName = "Verdana".
Reset grid.FillStyle = flexFillSingle (Value 0) to avoid accidental global changes later.

It is common to use **CellFontName** to display symbols or distinct data types in specific columns:
```
grid.Row = 2: grid.Col = 1
' Change typeface for a specific cell
grid.CellFontName = "Courier New" 
grid.CellFontSize = 10
grid.Text = "Fixed-Width Data"
```
Changing the font name can change the width of the text. You may need to manually update the **ColWidth** to ensure the text remains fully visible and is not clipped.

---

### CellFontSize

Returns or sets the size, in points, for the current cell text.

```
PROPERTY CellFontSize () AS SINGLE
PROPERTY CellFontSize (BYREF nSize AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nSize* | the size of the current cell text. |

#### Examples

For specific cells:
```
grid.Row = 2 ' Selects the 3rd row (index 2)
grid.Col = 3 ' Selects the 4th column (index 3)
grid.CellFontSize = 14 ' Sets font size to 14pt
grid.CellFontName = "Arial" ' Optionally change font name
grid.CellFontBold = True  ' Optionally make it bold
```
For an entire column:
```
grid.Col = 1 ' Selects the 2nd column
For intCounter As Long = 0 To grid.Rows - 1
   grid.Row = intCounter
   grid.CellFontSize = 10 ' Set font size for all cells in this column
Next
```
---

### CellFontBold

Returns or sets the bold style for the current cell text.

```
PROPERTY CellFontBold () AS BOOLEAN
PROPERTY CellFontBold (BYREF bBold AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bBold* | True to set the attribute; False, othewise |

#### Examples

For a single cell

```
grid.Row = 3 ' Set to your row index (0-based)
grid.Col = 4 ' Set to your column index (0-based)
grid.CellFontBold = True
```
For a range of cells or an entire row
```
grid.Row = 3 ' Starting row
grid.RowSel = 3 ' Ending row (same as start for one row)
grid.Col = 0 ' Starting column
grid.ColSel = .Cols - 1 ' Ending column (all columns)
grid.FillStyle = flexFillRepeat ' Apply to selection
grid.CellFontBold = True
```
---

### CellFontItalic

Returns or sets the bold style for the current cell text.

```
PROPERTY CellFontItalic () AS BOOLEAN
PROPERTY CellFontItalic (BYVAL bItalic AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bItalic* | True to set the attribue; False, othewise |

#### Example
```
' Select the cell at Row 1, Column 2
grid.Row = 1
grid.Col = 2

' Set the font of the selected cell to italic
rid.CellFontItalic = True
```
You can apply the style to multiple cells simultaneously by using the **FillStyle** property and setting the selection range with **RowSel**, **ColSel**.
```
' Select a range of cells (e.g., from Row 1, Col 1 to Row 5, Col 3)
grid.Row = 1
grid.Col = 1
grid.RowSel = 5
grid.ColSel = 3
    
' Enable the FillStyle to apply changes to all selected cells
grid.FillStyle = flexFillRepeat
    
' Set the font of all selected cells to italic
grid.CellFontItalic = True
    
' Reset FillStyle to default for single-cell changes afterward
grid.FillStyle = flexFillSingle
```

Using `Redraw = False` before making many updates in a loop and setting it back to **True** after is recommended to prevent flickering and improve performance.

---

### CellFontUnderline

Returns or sets a value that specifies if the underline style is applied to the current cell text.

```
PROPERTY CellFontUnderline () AS BOOLEAN
PROPERTY CellFontUnderline (BYVAL bUnderline AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bUnderline* | True to set the attribute; False, othewise |

```
' 1. Set the desired cell as the target for the next font modifications
grid.Row = 1 ' Example: target row 1
grid.Col = 2 ' Example: target column 2

' 2. Access the CellFont property and set its Underline attribute to True
grid.CellFont->Underline = True

' Optional: You can also change other font properties in the same way
grd.CellFont->Bold = True
grid.CellFont->Italic = True
grid.CellFont->Size = 12
grid.CellFont->Name = "Arial"

This method modifies the font properties of the cell specified by the current Row and Col properties.
```
---

### CellFontStrikeThrough

Returns or sets a value that determines if the Strikethrough style is applied to the current cell text.

```
PROPERTY CellFontStrikeThrough () AS BOOLEAN
PROPERTY CellFontStrikeThrough (BYVAL bStrikeThrough AS VARIANT_BOOL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bStrikeThrough* | True to set the attribute; False, othewise |

```
' Set the current cell to Row 3, Column 1
grid.Row = 3
grid.Col = 1

' Enable strikethrough for this specific cell
grid.CellFontStrikethru = True
```
---

### CellFontWidth

Returns or sets the width, in points, for the current cell text. 

```
PROPERTY FontWidth () AS SINGLE
PROPERTY FontWidth (BYVAL nWidth AS SINGLE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nWidth* | The font width, in points. |

#### Remarks

The following code sets the width of the text of the current cell when the `MSHFlexGrid` is in focus.
```
grid.CellFontWidth = 5
```
---

### PictureType

Returns or sets the type of picture to be generated by the **Picture** property.

```
PROPERTY PictureType () AS PictureTypeSettings
PROPERTY PictureType (BYVAL picType AS PictureTypeSettings)
```

| Parameter | Description |
| --------- | ----------- |
| *picType* | The type of picture that should be generated |

| Constant | Value | Description |
| -------- | ----- | ----------- |
| **flexPictureColor** | 0 | This produces a high-quality full-color image. |
| **flexPictureMonochrome** | 1 | This produces a lower-quality, monochrome, image that consumes less memory. |

---

### Picture

Returns a snapshot of the entire grid control as a picture object. 

```
PROPERTY Picture () AS IPicture PTR
```

This is typically used for printing the grid, saving it to disk, or copying it to the clipboard.

---

### Click

Occurs when the user presses and then releases a mouse button over the grid. |

```
FUNCTION Click () AS HRESULT
```
---

### DblClick

Occurs when the user double-clicks the grid with the mouse button.

```
FUNCTION DblClick () AS HRESULT
```
---

### Collapse

Occurs when the user collapses a row within the grid. The **Col** and **Row** properties of the `MSHFlexGrid` contain the cell used to collapse the band.

```
FUNCTION Collapse (BYVAL iCancel AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *iCancel* | Return TRUE to cancel the action. |

---

### Compare

Occurs when the Sort property for the MSHFlexGrid is set to Custom Sort (9), so the user can customize the sort process.

```
FUNCTION Compare (BYVAL row1 AS LONG, BYVAL row2 AS LONG, BYVAL iCmp AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *row1* | The first row in a pair of rows being compared. |
| *row2* | The second row in a pair of rows being compared. |
| *iCmp* | An integer that represents the sort order of each pair, as descibed below. |

| Setting  | Description |
| -------- | ----------- |
| -1 | If *row1* should appear before *row2*. |
| 0 | If both rows are equal or either row can appear before the other. |
| 1 | If *row1* should appear after *row2*. |

---

### EnterCell

Occurs when the currently active cell changes to a different cell.

```
FUNCTION EnterCell () AS HRESULT
```
---

### Expand

Occurs when the user expands a row within the MSHFlexGrid. The Col and Row properties of the MSHFlexGrid contain the cell used to expand the band.

```
FUNCTION Expand (BYVAL iCancel AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *iCancel* | Return TRUE to cancel the action. |

---

### KeyDown

Occurs when the user presses a key while the grid has the focus. It is primarily used to detect special key presses, such as function keys (F1-F12), navigation keys (HOME, END, PAGEUP), or key combinations with CTRL/ALT/SHIFT.

```
FUNCTION KeyDown (BYVAL keyCode AS SHORT PTR, BYVAL iShift AS SHORT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *keyCode* | An integer that represents the key code of the key that was pressed. |
| *iShift* | The state of SHIFT, CTRL, and ALT. |

---

### KeyPress

Occurs when the user presses and releases an ascii key.

```
FUNCTION KeyPress (BYVAL keyAnsi AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *keyAnsi* | An integer value that represents a standard numeric ANSI key code. |

---

### KeyUp

Occurs when the user releases a key.

```
FUNCTION KeyUp (BYVAL keyCode AS SHORT PTR, BYVAL iShift AS SHORT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *keyCode* | An integer that represents the key code of the key that was released. |
| *iShift* | An integer which acts as a bit field corresponding to the state of the SHIFT, CTRL, and ALT keys when they are depressed. The SHIFT key is bit 0, the CTRL key is bit 1, and the ALT key is bit 2. These bits correspond to the values 1 (Shift Mask), 2 (Ctrl Mask), and 4 (Alt Mask), respectively. The*i* Shift parameter indicates the state of these keys; some, all, or none of the bits can be set, indicating that some, all, or none of the keys are depressed. For example, if both the CTRL and ALT keys were depressed, the value of *iShift* would be 6. |

---

### LeaveCell

Occurs when the currently active cell changes to a different cell.

```
FUNCTION LeaveCell () AS HRESULT
```
---

### MouseDown

Occurs when the user presses a mouse button.

```
FUNCTION MouseDown MouseMove (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, _
   BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *iButton* | An integer value that identifies which mouse button caused the event. 1 = left button (1), 2 = right button, or 4 = middle button. |
| *iShift* | An integer which acts as a bit field corresponding to the state of the SHIFT, CTRL, and ALT keys when they are depressed. The SHIFT key is bit 0, the CTRL key is bit 1, and the ALT key is bit 2. These bits correspond to the values 1 (Shift Mask), 2 (Ctrl Mask), and 4 (Alt Mask), respectively. The*i* Shift parameter indicates the state of these keys; some, all, or none of the bits can be set, indicating that some, all, or none of the keys are depressed. For example, if both the CTRL and ALT keys were depressed, the value of *iShift* would be 6. |
| *x* | The horizontal position, in pixels, from the left edge of the grid. |
| *y* | The vertical position, in pixels, from the top edge of the grid. |

---

### MouseMove

Occurs when the user moves the mouse.

```
FUNCTION MouseMove (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, _
   BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *iButton* | An integer value that identifies which mouse button caused the event. 1 = left button (1), 2 = right button, or 4 = middle button. |
| *iShift* | An integer which acts as a bit field corresponding to the state of the SHIFT, CTRL, and ALT keys when they are depressed. The SHIFT key is bit 0, the CTRL key is bit 1, and the ALT key is bit 2. These bits correspond to the values 1 (Shift Mask), 2 (Ctrl Mask), and 4 (Alt Mask), respectively. The*i* Shift parameter indicates the state of these keys; some, all, or none of the bits can be set, indicating that some, all, or none of the keys are depressed. For example, if both the CTRL and ALT keys were depressed, the value of *iShift* would be 6. |
| *x* | The horizontal position, in pixels, from the left edge of the grid. |
| *y* | The vertical position, in pixels, from the top edge of the grid. |

---

### MouseUp

Occurs when the user releases a mouse button.

```
FUNCTION MouseUp (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, _
   BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *iButton* | An integer value that identifies which mouse button caused the event. 1 = left button (1), 2 = right button, or 4 = middle button. |
| *iShift* | An integer which acts as a bit field corresponding to the state of the SHIFT, CTRL, and ALT keys when they are depressed. The SHIFT key is bit 0, the CTRL key is bit 1, and the ALT key is bit 2. These bits correspond to the values 1 (Shift Mask), 2 (Ctrl Mask), and 4 (Alt Mask), respectively. The*i* Shift parameter indicates the state of these keys; some, all, or none of the bits can be set, indicating that some, all, or none of the keys are depressed. For example, if both the CTRL and ALT keys were depressed, the value of *iShift* would be 6. |
| *x* | The horizontal position, in pixels, from the left edge of the grid. |
| *y* | The vertical position, in pixels, from the top edge of the grid. |

---

### OLECompleteDrag

Fired after an OLE drag operation is started.

```
FUNCTION OLECompleteDrag (BYVAL Effect AS LONG PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Effect* | The action to be performed |

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **vbDropEffectNone** | 0 | Drop target cannot accept the data. |
| **vbDropEffectCopy** | 1 | Drop results in a copy of data from the source to the target. The original data is unaltered by the drag operation. |
| **vbDropEffectMove** | 2 | Drop results in data being moved from drag source to drop source. The drag source should remove the data from itself after the move. |

---

### OLEDragDrop

Fired when a source component is dropped onto a target component.

```
FUNCTION OLEDragDrop (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, _
   BYVAL iButton AS SHORT PTR, BYVAL iShift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pData* | An object containing formats that the source will provide and (possibly) the data for those formats. If no data is contained in the object, it is provided when the control calls the **GetData** method. The **SetData** and **Clear** methods cannot be used here. |
| *Effect* | The action that has been performed (if any), thus allowing the source to take appropriate action if the component was moved (such as the source deleting the data). See the table below. |
| *iButton* | An integer value that identifies which mouse button caused the event. 1 = left button (1), 2 = right button, or 4 = middle button. |
| *iShift* | An integer which acts as a bit field corresponding to the state of the SHIFT, CTRL, and ALT keys when they are depressed. The SHIFT key is bit 0, the CTRL key is bit 1, and the ALT key is bit 2. These bits correspond to the values 1 (Shift Mask), 2 (Ctrl Mask), and 4 (Alt Mask), respectively. The*i* Shift parameter indicates the state of these keys; some, all, or none of the bits can be set, indicating that some, all, or none of the keys are depressed. For example, if both the CTRL and ALT keys were depressed, the value of *iShift* would be 6. |
| *x* | The horizontal position, in pixels, from the left edge of the grid. |
| *y* | The vertical position, in pixels, from the top edge of the grid. |

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **vbDropEffectNone** | 0 | Drop target cannot accept the data. |
| **vbDropEffectCopy** | 1 | Drop results in a copy of data from the source to the target. The original data is unaltered by the drag operation. |
| **vbDropEffectMove** | 2 | Drop results in data being moved from drag source to drop source. The drag source should remove the data from itself after the move. |

---

### OLEDragOver

Occurs when an object is dragged into the bounds of an element that is acting as the drop target,

```
FUNCTION OLEDragOver (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, _
   BYVAL iButton AS SHORT PTR, BYVAL iShift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR, _
   BYVAL iState AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pData* | An object containing formats that the source will provide and (possibly) the data for those formats. If no data is contained in the object, it is provided when the control calls the **GetData** method. The **SetData** and **Clear** methods cannot be used here. |
| *Effect* | The action that has been performed (if any), thus allowing the source to take appropriate action if the component was moved (such as the source deleting the data). See the table below. |
| *iButton* | An integer value that identifies which mouse button caused the event. 1 = left button (1), 2 = right button, or 4 = middle button. |
| *iShift* | An integer which acts as a bit field corresponding to the state of the SHIFT, CTRL, and ALT keys when they are depressed. The SHIFT key is bit 0, the CTRL key is bit 1, and the ALT key is bit 2. These bits correspond to the values 1 (Shift Mask), 2 (Ctrl Mask), and 4 (Alt Mask), respectively. The*i* Shift parameter indicates the state of these keys; some, all, or none of the bits can be set, indicating that some, all, or none of the keys are depressed. For example, if both the CTRL and ALT keys were depressed, the value of *iShift* would be 6. |
| *x* | The horizontal position, in pixels, from the left edge of the grid. |
| *y* | The vertical position, in pixels, from the top edge of the grid. |
| *state* | An integer that corresponds to the transition state of the control being dragged in relation to a target form or control. The possible values are:<br>*flexEnter(0)*: Source component is being dragged within the range of a target.<br>*flexLeave(1)*Source component is being dragged out of the range of a target.*flexOver(2)Source component has moved from one position in the target to another.:

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **vbDropEffectNone** | 0 | Drop target cannot accept the data. |
| **vbDropEffectCopy** | 1 | Drop results in a copy of data from the source to the target. The original data is unaltered by the drag operation. |
| **vbDropEffectMove** | 2 | Drop results in data being moved from drag source to drop source. The drag source should remove the data from itself after the move. |

---

### OLEGiveFeedback

Fired after a drop to inform the source component that a drag action was either performed or cancelled.

```
FUNCTION OLEGiveFeedBack (BYVAL Effect AS LONG PTR, BYVAL DefaultCursors AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Effect* | The action that has been performed (if any), thus allowing the source to take appropriate action if the component was moved (such as the source deleting the data). See the table below. |
| *DefaultCursors* | A boolean value which determines whether the default or a user-defined mouse cursor is used. |

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **vbDropEffectNone** | 0 | Drop target cannot accept the data. |
| **vbDropEffectCopy** | 1 | Drop results in a copy of data from the source to the target. The original data is unaltered by the drag operation. |
| **vbDropEffectMove** | 2 | Drop results in data being moved from drag source to drop source. The drag source should remove the data from itself after the move. |

---

### OLESetData

Fired on the source component when a target component performs the GetData method in the source's DataObject component.

```
FUNCTION OLESetData (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL DataFormat AS SHORT PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pData* | An object in which to place the requested data. The component calls the SetData method to load the requested format. |
| *DataFormat* | An integer specifying the format of the data that the target component is requesting. The source component uses this value to determine what to load into the **DataObject** object. |

#### Remarks

In certain cases, you may wish to defer loading data into the DataObject object of a source component to save time, especially if the source component supports many formats. This event allows the source to respond to only one request for a given format of data. When this event is called, the source should check the format parameter to determine what needs to be loaded and then perform the SetData method on the DataObject object to load the data which is then passed back to the target component.

---

### OLEStartDrag

Fired after an OLE drag operation is started.

```
FUNCTION OLEStartDrag (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL AllowedEffects AS LONG PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pData* | An object containing formats that the source will provide. You may provide the values for this parameter in this event. |
| *AllowedEffects* | An  integer containing the effects that the source component supports. The possible values are: |

| Constant  | Value | Description |
| --------- | ----- | ----------- |
| **vbDropEffectNone** | 0 | Drop target cannot accept the data. |
| **vbDropEffectCopy** | 1 | Drop results in a copy of data from the source to the target. The original data is unaltered by the drag operation. |
| **vbDropEffectMove** | 2 | Drop results in data being moved from drag source to drop source. The drag source should remove the data from itself after the move. |

---

### RowSelChange

Fired when the current cell changes to a new cell.

```
FUNCTION RowSelChange () AS HRESULT
```
---

### Scroll

Occurs when the contents of the MSHFlexGrid are scrolled. This can be done using the scroll bars, keyboard, or programmatically by changing the TopRow or LeftCol properties.

```
FUNCTION Scroll () AS HRESULT
```
---

### SelChange

Occurs when the selected range changes to a different cell or range of cells.

```
FUNCTION SelChange () AS HRESULT
```
---
