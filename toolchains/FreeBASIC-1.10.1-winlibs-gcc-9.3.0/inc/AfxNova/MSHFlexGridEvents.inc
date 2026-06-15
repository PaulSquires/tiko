' ########################################################################################
' CMSHFlexGridEvents class
' Implementation of the MSHFlexGrid events sink class
' ########################################################################################
TYPE CMSHFlexGridEvents EXTENDS OBJECT

   DECLARE VIRTUAL FUNCTION QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObject AS LPVOID PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION AddRef () AS ULONG
   DECLARE VIRTUAL FUNCTION Release () AS ULONG
   DECLARE VIRTUAL FUNCTION GetTypeInfoCount (BYVAL pctinfo AS UINT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION GetTypeInfo (BYVAL iTInfo AS UINT, BYVAL lcid AS LCID, BYVAL ppTInfo AS ITypeInfo PTR PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION GetIDsOfNames (BYVAL riid AS CONST IID CONST PTR, BYVAL rgszNames AS LPOLESTR PTR, BYVAL cNames AS UINT, BYVAL lcid AS LCID, BYVAL rgDispId AS DISPID PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION Invoke (BYVAL dispIdMember AS DISPID, BYVAL riid AS CONST IID CONST PTR, BYVAL lcid AS LCID, BYVAL wFlags AS WORD, BYVAL pDispParams AS DISPPARAMS PTR, BYVAL pVarResult AS VARIANT PTR, BYVAL pExcepInfo AS EXCEPINFO PTR, BYVAL puArgErr AS UINT PTR) AS HRESULT

   DECLARE CONSTRUCTOR
   DECLARE VIRTUAL DESTRUCTOR

   DECLARE VIRTUAL FUNCTION Click () AS HRESULT
   DECLARE VIRTUAL FUNCTION DblClick () AS HRESULT
   DECLARE VIRTUAL FUNCTION KeyDown (BYVAL keyCode AS SHORT PTR, BYVAL iShift AS SHORT) AS HRESULT
   DECLARE VIRTUAL FUNCTION KeyPress (BYVAL keyAnsi AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION KeyUp (BYVAL keyCode AS SHORT PTR, BYVAL iShift AS SHORT) AS HRESULT
   DECLARE VIRTUAL FUNCTION MouseDown (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   DECLARE VIRTUAL FUNCTION MouseMove (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   DECLARE VIRTUAL FUNCTION MouseUp (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   DECLARE VIRTUAL FUNCTION SelChange () AS HRESULT
   DECLARE VIRTUAL FUNCTION RowSelChange () AS HRESULT
   DECLARE VIRTUAL FUNCTION EnterCell () AS HRESULT
   DECLARE VIRTUAL FUNCTION LeaveCell () AS HRESULT
   DECLARE VIRTUAL FUNCTION Scroll () AS HRESULT
   DECLARE VIRTUAL FUNCTION Compare (BYVAL row1 AS LONG, BYVAL row2 AS LONG, BYVAL iCmp AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION Collapse (BYVAL iCancel AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION Expand (BYVAL iCancel AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION OLEStartDrag (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL AllowedEffects AS LONG PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION OLEGiveFeedBack (BYVAL Effect AS LONG PTR, BYVAL DefaultCursors AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION OLESetData (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL DataFormat AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION OLECompleteDrag (BYVAL Effect AS LONG PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION OLEDragOver (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, _
           BYVAL iButton AS SHORT PTR, BYVAL iShift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR, BYVAL iState AS SHORT PTR) AS HRESULT
   DECLARE VIRTUAL FUNCTION OLEDragDrop (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, _
           BYVAL iButton AS SHORT PTR, BYVAL iShift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR) AS HRESULT

Private:
   cRef AS ULONG   ' // Reference count

END TYPE

' ========================================================================================
PRIVATE CONSTRUCTOR CMSHFlexGridEvents
   CMSHGRIDEVT_DP("")
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE DESTRUCTOR CMSHFlexGridEvents
   CMSHGRIDEVT_DP("")
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns a pointer to our implementation of the CMSHFlexGridEvents events class.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.QueryInterface (BYVAL riid AS REFIID, BYVAL ppvObj AS LPVOID PTR) AS HRESULT
   CMSHGRIDEVT_DP("iid: " & AfxGuidText(riid))
   IF ppvObj = NULL THEN RETURN E_INVALIDARG
   IF IsEqualIID(riid, @AFX_IID_IMSHFlexGrid) OR _
      IsEqualIID(riid, @IID_IUnknown) OR _
      IsEqualIID(riid, @IID_IDispatch) THEN
      *ppvObj = @this
      ' // Increment the reference count
      this.addRef
      RETURN S_OK
   END IF
   RETURN E_NOINTERFACE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Increments the reference count
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.AddRef () AS ULONG
   this.cRef += 1
   CMSHGRIDEVT_DP(WSTR(this.cRef))
   RETURN this.cRef
END FUNCTION
' ========================================================================================

' ========================================================================================
' Decrement the reference count
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Release () AS ULONG
   this.cRef -= 1
   CMSHGRIDEVT_DP(WSTR(this.cRef))
   FUNCTION = this.cRef
   IF this.cRef = 0 THEN DELETE @this
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.GetTypeInfoCount (BYVAL pctinfo AS UINT PTR) AS HRESULT
   CMSHGRIDEVT_DP("")
   *pctInfo = 0
   RETURN E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.GetTypeInfo (BYVAL iTInfo AS UINT, BYVAL lcid AS LCID, BYVAL ppTInfo AS ITypeInfo PTR PTR) AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.GetIDsOfNames (BYVAL riid AS CONST IID CONST PTR, BYVAL rgszNames AS LPOLESTR PTR, BYVAL cNames AS UINT, BYVAL lcid AS LCID, BYVAL rgDispId AS DISPID PTR) AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN E_NOTIMPL
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Occurs when a user presses and then releases a mouse button over the grid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Click () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the user double-clicks the grid with the mouse button.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.DblClick () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when a user presses a key while the grid has the focus.
' e.g. VK_DOWN = &h28; VK_UP = &h26: VK_SHIFT = &h10; VK_CONTROL = &H11
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.KeyDown (BYVAL keyCode AS SHORT PTR, BYVAL iShift AS SHORT) AS HRESULT
   CMSHGRIDEVT_DP("keyCode = " & HEX(*keyCode) & "; iShift = " & WSTR(iShift))
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the user presses and releases an ansi key.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.KeyPress (BYVAL keyAnsi AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("keyansi = " & HEX(*keyAnsi))
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the user presses and releases an ascii key.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.KeyUp (BYVAL keyCode AS SHORT PTR, BYVAL iShift AS SHORT) AS HRESULT
   CMSHGRIDEVT_DP("keyCode = " & HEX(*keyCode) & "; iShift = " & WSTR(iShift))
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the user presses a mouse button.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.MouseDown (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   CMSHGRIDEVT_DP("MouseDown = " & WSTR(iButton) & "; iShift = " & WSTR(iShift) & "; x = " & x & "; y = " & y)
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the user moves the mouse.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.MouseMove (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   CMSHGRIDEVT_DP("MouseMove = " & WSTR(iButton) & "; iShift = " & WSTR(iShift) & "; x = " & x & "; y = " & y)
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the user releases a mouse button.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.MouseUp (BYVAL iButton AS SHORT, BYVAL iShift AS SHORT, BYVAL x AS OLE_XPOS_PIXELS, BYVAL y AS OLE_YPOS_PIXELS) AS HRESULT
   CMSHGRIDEVT_DP("MouseUp = " & WSTR(iButton) & "; iShift = " & WSTR(iShift) & "; x = " & x & "; y = " & y)
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Fired when the selected range changes.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.SelChange () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Fired when the current cell changes to a new cell.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.RowSelChange () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Fired when a cell becomes active.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.EnterCell () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Fired before the current cell changes to a different cell.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.LeaveCell () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Occurs when the contents of the grid are scrolled.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Scroll () AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' Fired when the Sort property is set to flexSortCustom to allow custom comparison of rows.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Compare (BYVAL row1 AS LONG, BYVAL row2 AS LONG, BYVAL iCmp AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("row1: " & WSTR(row1) & "; row2: " & WSTR(row2))
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' Occurs when the user collapses a row within the grid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Collapse (BYVAL iCancel AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' Occurs whe the user expands a row within the grid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Expand (BYVAL iCancel AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("")
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' Occurs whe the user expands a row within the grid.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.OLEStartDrag (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL AllowedEffects AS LONG PTR) AS HRESULT
   CMSHGRIDEVT_DP("pData: " & WSTR(pData) & "; " & WSTR(*AllowedEffects))
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' * Fired after every OLEDragOver event to allow the source component to provide visual feedback to the user.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.OLEGiveFeedBack (BYVAL Effect AS LONG PTR, BYVAL DefaultCursors AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("Effect: " & WSTR(*Effect) & "; " & "DefaultCursors: " & WSTR(*DefaultCursors))
   RETURN S_OK
END FUNCTION
' ========================================================================================
' ========================================================================================
' Fired on the source component when a target component performs the GetData method on the
' source's DataObject component.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.OLESetData (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL DataFormat AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("pData: " & WSTR(pData) & "; DataFormat: " & WSTR(*DataFormat))
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Fired after a drop to inform the source component that a drag action was either perdormed or cancelled.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.OLECompleteDrag (BYVAL Effect AS LONG PTR) AS HRESULT
   CMSHGRIDEVT_DP("Effect: " & WSTR(*Effect))
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Occurs when an object is dragged into the bounds of an element that is acting as the drop target,
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.OLEDragOver (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, _
BYVAL iButton AS SHORT PTR, BYVAL iShift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR, BYVAL iState AS SHORT PTR) AS HRESULT
   CMSHGRIDEVT_DP("pData: " & WSTR(pData) & "; Effect: " & WSTR(*Effect) & "; " & WSTR(*iButton) & "; iShift: " & WSTR(*iShift) & "; x: " & WSTR(*x) & "; y: " & WSTR(*y) & "; iState: " & WSTR(*iState))
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' * Fired when a source component is dropped onto a target component.
' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.OLEDragDrop (BYVAL pData AS Afx_IVBDataObject PTR PTR, BYVAL Effect AS LONG PTR, _
BYVAL iButton AS SHORT PTR, BYVAL iShift AS SHORT PTR, BYVAL x AS SINGLE PTR, BYVAL y AS SINGLE PTR) AS HRESULT
   CMSHGRIDEVT_DP("pData: " & WSTR(pData) & "; Effect: " & WSTR(*Effect) & "; " & WSTR(*iButton) & "; iShift: " & WSTR(*iShift) & "; x: " & WSTR(*x) & "; y: " & WSTR(*y))
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
PRIVATE FUNCTION CMSHFlexGridEvents.Invoke (BYVAL dispIdMember AS DISPID, BYVAL riid AS CONST IID CONST PTR, BYVAL lcid AS LCID, BYVAL wFlags AS WORD, BYVAL pDispParams AS DISPPARAMS PTR, BYVAL pVarResult AS VARIANT PTR, BYVAL pExcepInfo AS EXCEPINFO PTR, BYVAL puArgErr AS UINT PTR) AS HRESULT
   
   DIM hr AS HRESULT
   
   SELECT CASE dispIdMember

      CASE -600   ' // Click
         RETURN this.Click

      CASE -601   ' // DblClick
         RETURN this.DblClick

      CASE -602   ' // KeyDown
         DIM keyCode AS SHORT = *pDispParams->rgvarg[1].piVal
         DIM iShift AS SHORT = pDispParams->rgvarg[0].iVal
         hr = this.KeyDown(@keyCode, iShift)
         *pDispParams->rgvarg[1].piVal = keyCode
         RETURN hr

      CASE -603   ' // KeyPress
         DIM keyAnsi AS SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.KeyPress(@keyAnsi)
         *pDispParams->rgvarg[0].piVal = keyAnsi
         RETURN hr

      CASE -604   ' // KeyUp
         DIM keyCode AS SHORT = *pDispParams->rgvarg[1].piVal
         DIM iShift AS SHORT = pDispParams->rgvarg[0].iVal
         hr = this.KeyUp(@keyCode, iShift)
         *pDispParams->rgvarg[1].piVal = keyCode
         RETURN hr

      CASE -605   ' // MouseDown
         DIM iButton AS SHORT = pDispParams->rgvarg[3].iVal
         DIM iShift AS SHORT = pDispParams->rgvarg[2].iVal
         DIM x AS LONG = pDispParams->rgvarg[1].lVal
         DIM y AS LONG = pDispParams->rgvarg[0].lVal
         hr = this.MouseDown(iButton, iShift, x, y)
         RETURN hr

      CASE -606   ' // MouseMove
         DIM iButton AS SHORT = pDispParams->rgvarg[3].iVal
         DIM iShift AS SHORT = pDispParams->rgvarg[2].iVal
         DIM x AS LONG = pDispParams->rgvarg[1].lVal
         DIM y AS LONG = pDispParams->rgvarg[0].lVal
         hr = this.MouseMove(iButton, iShift, x, y)
         RETURN hr

      CASE -607   ' // MouseUp
         DIM iButton AS SHORT = pDispParams->rgvarg[3].iVal
         DIM iShift AS SHORT = pDispParams->rgvarg[2].iVal
         DIM x AS LONG = pDispParams->rgvarg[1].lVal
         DIM y AS LONG = pDispParams->rgvarg[0].lVal
         hr = this.MouseUp(iButton, iShift, x, y)
         RETURN hr

      CASE 69   ' // SelChange
         RETURN this.SelChange

      CASE 70   ' // RowSelChange
         RETURN this.RowSelChange

      CASE 71   ' // EnterCell
         RETURN this.EnterCell

      CASE 72   ' // LeaveCell
         RETURN this.LeaveCell

      CASE 73   ' // Scroll
         RETURN this.Scroll

      CASE 74   ' // Compare
         DIM row1 AS LONG = pDispParams->rgvarg[2].lVal
         DIM row2 AS LONG = pDispParams->rgvarg[1].lVal
         DIM iCmp AS  SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.Compare(row1, row2, @iCmp)
         *pDispParams->rgvarg[0].piVal = iCmp
         RETURN hr

      CASE 140   ' // Collapse
         DIM iCancel AS SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.Collapse(@iCancel)
         *pDispParams->rgvarg[0].piVal = iCancel
         RETURN hr

      CASE 141  ' // Expand
         DIM iCancel AS SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.Expand(@iCancel)
         *pDispParams->rgvarg[0].piVal = iCancel
         RETURN hr

      CASE 1550   ' // OLEStartDrag
         DIM pData AS Afx_IVBDataObject PTR PTR = cast(ANY PTR, pDispParams->rgvarg[1].ppDispVal)
         DIM AllowedEffects AS LONG = *pDispParams->rgvarg[0].plVal
         hr = this.OLEStartDrag(pData, @AllowedEffects)
         *pDispParams->rgvarg[0].plVal = AllowedEffects
         RETURN hr

      CASE 1551   ' // OLEGiveFeedBack
         DIM Effect AS LONG = *pDispParams->rgvarg[1].plVal
         DIM DefaultCursors AS SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.OLEGiveFeedBack(@Effect, @DefaultCursors)
         *pDispParams->rgvarg[1].plVal = Effect
         *pDispParams->rgvarg[0].piVal = DefaultCursors
         RETURN hr

      CASE 1552   ' // OLESetData
         DIM pData AS Afx_IVBDataObject PTR PTR = cast(ANY PTR, pDispParams->rgvarg[1].ppDispVal)
         DIM DataFormat AS SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.OLESetData(pData, @dataFormat)
         *pDispParams->rgvarg[0].piVal = DataFormat
         RETURN hr

      CASE 1553   ' // OLECompleteDrag
         DIM Effect AS LONG = *pDispParams->rgvarg[0].plVal
         hr = this.OLECompleteDrag(@Effect)
         *pDispParams->rgvarg[0].plVal^= EFfect
         RETURN hr

      CASE 1554   ' // OLEDragOver
         DIM pData AS Afx_IVBDataObject PTR PTR = cast(ANY PTR, pDispParams->rgvarg[6].ppDispVal)
         DIM Effect AS LONG = *pDispParams->rgvarg[5].plVal
         DIM iButton AS SHORT = *pDispParams->rgvarg[4].piVal
         DIM iShift AS SHORT = *pDispParams->rgvarg[3].piVal
         DIM x AS SINGLE = *pDispParams->rgvarg[2].pfltVal
         DIM y AS SINGLE = *pDispParams->rgvarg[1].pfltVal
         DIM iState AS SHORT = *pDispParams->rgvarg[0].piVal
         hr = this.OLEDragOver(pData, @Effect, @iButton, @iShift, @x, @y, @iState)
         *pDispParams->rgvarg[5].plVal = EFfect
         *pDispParams->rgvarg[4].piVal = iButton
         *pDispParams->rgvarg[3].piVal = iShift
         *pDispParams->rgvarg[2].pfltVal = x
         *pDispParams->rgvarg[1].pfltVal = y
         *pDispParams->rgvarg[0].piVal = iState
         RETURN hr

      CASE 1555   ' // OLEDragDrop
         DIM pData AS Afx_IVBDataObject PTR PTR = cast(ANY PTR, pDispParams->rgvarg[5].ppDispVal)
         DIM Effect AS LONG = *pDispParams->rgvarg[4].plVal
         DIM iButton AS SHORT = *pDispParams->rgvarg[3].piVal
         DIM iShift AS SHORT = *pDispParams->rgvarg[2].piVal
         DIM x AS SINGLE = *pDispParams->rgvarg[1].pfltVal
         DIM y AS SINGLE = *pDispParams->rgvarg[0].pfltVal
         hr = this.OLEDragDrop(pData, @Effect, @iButton, @iShift, @x, @y)
         *pDispParams->rgvarg[4].plVal = EFfect
         *pDispParams->rgvarg[3].piVal = iButton
         *pDispParams->rgvarg[2].piVal = iShift
         *pDispParams->rgvarg[1].pfltVal = x
         *pDispParams->rgvarg[0].pfltVal = y
         RETURN hr

   END SELECT

   RETURN S_OK
END FUNCTION
' ========================================================================================
